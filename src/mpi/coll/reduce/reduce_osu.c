/* -*- Mode: C; c-basic-offset:4 ; -*- */
/*
 *
 *  (C) 2001 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

/* Copyright (c) 2001-2022, The Ohio State University. All rights
 * reserved.
 *
 * This file is part of the MVAPICH2 software package developed by the
 * team members of The Ohio State University's Network-Based Computing
 * Laboratory (NBCL), headed by Professor Dhabaleswar K. (DK) Panda.
 *
 * For detailed copyright and licensing information, please refer to the
 * copyright file COPYRIGHT in the top level MVAPICH2 directory.
 *
 */

#include "mpiimpl.h"
#include "mv2_coll_shmem.h"
#include "mv2_common_tuning.h"
#include "reduce_tuning.h"

/*
=== BEGIN_MPI_T_MV2_CVAR_INFO_BLOCK ===

cvars:
    - name        : MV2_INTRA_SHMEM_REDUCE_MSG
      category    : COLLECTIVE
      type        : int
      default     : (1<<11)
      class       : none
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : >-
        TODO-DESC

    - name        : MV2_REDUCE_2LEVEL_MSG
      category    : COLLECTIVE
      type        : int
      default     : (1<<18)
      class       : none
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : >-
        This parameter can be used to determine the threshold for the
        2-level reduce algorithm. We now use the shared-memory-based
        algorithm for messages smaller than the MV2_SHMEM_REDUCE_MSG,
        the 2-level algorithm for medium sized messages up to the
        threshold defined by this parameter. We use the default
        point-to-point algorithms messages larger than this threshold.

    - name        : MV2_REDUCE_SHORT_MSG
      category    : COLLECTIVE
      type        : int
      default     : 2048
      class       : none
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : >-
        TODO-DESC

    - name        : MV2_SHMEM_REDUCE_MSG
      category    : COLLECTIVE
      type        : int
      default     : (1<<12)
      class       : none
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : >-
        The SHMEM reduce is used for messages less than this threshold.

    - name        : MV2_USE_SHMEM_REDUCE
      category    : COLLECTIVE
      type        : boolean
      default     : 1
      class       : none
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : >-
        This parameter can be used to turn off shared memory based
        MPI_Reduce for OFA-IB-CH3 over IBA by setting this to 0.

=== END_MPI_T_MV2_CVAR_INFO_BLOCK ===
*/

int (*reduce_fn)(const void *sendbuf, void *recvbuf, int count,
                 MPI_Datatype datatype, MPI_Op op, int root,
                 MPIR_Comm * comm_ptr, MPIR_Errflag_t *errflag);

int (*MV2_Reduce_function)(const void *sendbuf, void *recvbuf, int count,
                           MPI_Datatype datatype, MPI_Op op, int root,
                           MPIR_Comm * comm_ptr, MPIR_Errflag_t *errflag) = NULL;

int (*MV2_Reduce_intra_function)(const void *sendbuf, void *recvbuf, int count,
                                 MPI_Datatype datatype, MPI_Op op, int root,
                                 MPIR_Comm * comm_ptr,
                                 MPIR_Errflag_t *errflag) = NULL;

int (*MPIR_Rank_list_mapper)(MPIR_Comm *, int) = NULL;

/* This is the default implementation of reduce. The algorithm is:

   Algorithm: MPI_Reduce

   For long messages and for builtin ops and if count >= pof2 (where
   pof2 is the nearest power-of-two less than or equal to the number
   of processes), we use Rabenseifner's algorithm (see
   http://www.hlrs.de/organization/par/services/models/mpi/myreduce.html ).
   This algorithm implements the reduce in two steps: first a
   reduce-scatter, followed by a gather to the root. A
   recursive-halving algorithm (beginning with processes that are
   distance 1 apart) is used for the reduce-scatter, and a binomial tree
   algorithm is used for the gather. The non-power-of-two case is
   handled by dropping to the nearest lower power-of-two: the first
   few odd-numbered processes send their data to their left neighbors
   (rank-1), and the reduce-scatter happens among the remaining
   power-of-two processes. If the root is one of the excluded
   processes, then after the reduce-scatter, rank 0 sends its result to
   the root and exits; the root now acts as rank 0 in the binomial tree
   algorithm for gather.

   For the power-of-two case, the cost for the reduce-scatter is
   lgp.alpha + n.((p-1)/p).beta + n.((p-1)/p).gamma. The cost for the
   gather to root is lgp.alpha + n.((p-1)/p).beta. Therefore, the
   total cost is:
   Cost = 2.lgp.alpha + 2.n.((p-1)/p).beta + n.((p-1)/p).gamma

   For the non-power-of-two case, assuming the root is not one of the
   odd-numbered processes that get excluded in the reduce-scatter,
   Cost = (2.floor(lgp)+1).alpha + (2.((p-1)/p) + 1).n.beta +
           n.(1+(p-1)/p).gamma

   For short messages, user-defined ops, and count < pof2, we use a
   binomial tree algorithm for both short and long messages.

   Cost = lgp.alpha + n.lgp.beta + n.lgp.gamma

   We use the binomial tree algorithm in the case of user-defined ops
   because in this case derived datatypes are allowed, and the user
   could pass basic datatypes on one process and derived on another as
   long as the type maps are the same. Breaking up derived datatypes
   to do the reduce-scatter is tricky.

   FIXME: Per the MPI-2.1 standard this case is not possible.  We
   should be able to use the reduce-scatter/gather approach as long as
   count >= pof2.  [goodell@ 2009-01-21]

   Possible improvements:

   End Algorithm: MPI_Reduce
*/

/* not declared static because a machine-specific function may call this one
   in some cases */
int MPIR_Reduce_index_tuned_intra_MV2(const void *sendbuf, void *recvbuf,
                                      int count, MPI_Datatype datatype,
                                      MPI_Op op, int root, MPIR_Comm * comm_ptr,
                                      MPIR_Errflag_t *errflag)
{
    int mpi_errno = MPI_SUCCESS;
    int mpi_errno_ret = MPI_SUCCESS;
    int comm_size_index = 0;
    int inter_node_algo_index = 0;
    int intra_node_algo_index = 0;
    int local_size = 0;
    int partial_sub_ok = 0;
    int conf_index = 0;
    int table_min_comm_size = 0;
    int table_max_comm_size = 0;
    int table_min_inter_size = 0;
    int table_max_inter_size = 0;
    int table_min_intra_size = 0;
    int table_max_intra_size = 0;
    int last_inter;
    int last_intra;
    int lp2ltn; // largest power of 2 less than n
    int lp2ltn_min;
    int is_commutative, pof2;
    MPIR_Op *op_ptr;
    int comm_size = 0;
    int nbytes = 0;
    int sendtype_size;
    int is_two_level = 0;
    MPIR_Comm *shmem_commptr = NULL;
    MPI_Comm shmem_comm;
    comm_size = comm_ptr->local_size;
    MPIR_Datatype_get_size_macro(datatype, sendtype_size);
    nbytes = count * sendtype_size;

    if (count == 0)
        return MPI_SUCCESS;

    if (HANDLE_GET_KIND(op) == HANDLE_KIND_BUILTIN) {
        is_commutative = 1;
        /* get the function by indexing into the op table */
    } else {
        MPIR_Op_get_ptr(op, op_ptr)
        if (op_ptr->kind == MPIR_OP_KIND__USER_NONCOMMUTE) {
            is_commutative = 0;
        } else {
            is_commutative = 1;
        }
    }

    /* find nearest power-of-two less than or equal to comm_size */
    pof2 = comm_ptr->dev.ch.gpof2;

#ifdef _ENABLE_CUDA_
    int rank = 0, stride = 0;
    MPI_Aint true_lb, true_extent, extent;
    MPIR_Type_get_true_extent_impl(datatype, &true_lb, &true_extent);
    MPIR_Datatype_get_extent_macro(datatype, extent);
    stride = count * MPL_MAX(extent, true_extent);
    int recv_mem_type = 0;
    int send_mem_type = 0;
    char *recv_host_buf = NULL;
    char *send_host_buf = NULL;
    char *temp_recvbuf = recvbuf;

    rank = comm_ptr->rank;

    if (mv2_enable_device) {
        recv_mem_type = is_device_buffer(recvbuf);
        if (sendbuf != MPI_IN_PLACE) {
            send_mem_type = is_device_buffer(sendbuf);
        }
    }
    if (mv2_enable_device && send_mem_type) {
        send_host_buf = (char*)MPL_malloc(stride, MPL_MEM_COLL);
        MV2_MPID_Memcpy_Device((void *)send_host_buf, (void *)sendbuf, 
                               stride, deviceMemcpyDeviceToHost);
        sendbuf = send_host_buf;
    }

    if (mv2_enable_device && recv_mem_type) {
        recv_host_buf = (char*)MPL_malloc(stride, MPL_MEM_COLL);
        MV2_MPID_Memcpy_Device((void *)recv_host_buf, (void *)recvbuf, 
                               stride, deviceMemcpyDeviceToHost);
        recvbuf = recv_host_buf;
    }
#endif

    /* check if safe to use partial subscription mode */
    if (comm_ptr->dev.ch.shmem_coll_ok == 1 && comm_ptr->dev.ch.is_uniform) {
        shmem_comm = comm_ptr->dev.ch.shmem_comm;
        MPIR_Comm_get_ptr(shmem_comm, shmem_commptr);
        local_size = shmem_commptr->local_size;
        if (mv2_reduce_indexed_table_ppn_conf[0] == -1) {
            /* Indicating user defined tuning */
            conf_index = 0;
            goto conf_check_end;
        }

        if (nbytes <= mv2_topo_aware_reduce_max_msg &&
              nbytes >= mv2_topo_aware_reduce_min_msg &&
              mv2_enable_skip_tuning_table_search &&
              nbytes <= mv2_coll_skip_table_threshold &&
              mv2_enable_topo_aware_collectives &&
              mv2_use_topo_aware_reduce && comm_ptr->dev.ch.topo_coll_ok == 1 &&
              is_commutative &&
              local_size >= mv2_topo_aware_reduce_ppn_threshold &&
              mv2_topo_aware_reduce_node_threshold <= 
                                        comm_ptr->dev.ch.leader_group_size) {
            MV2_Reduce_function = MPIR_Reduce_topo_aware_hierarchical_MV2;
            goto skip_tuning_tables;
        }

        if (likely(mv2_enable_shmem_reduce && 
              mv2_enable_skip_tuning_table_search &&
              (nbytes <= mv2_coll_skip_table_threshold))) {
            /* for small messages, force shmem + binomial */
            MV2_Reduce_intra_function = MPIR_Reduce_shmem_MV2;
            MV2_Reduce_function = MPIR_Reduce_binomial_MV2;
            is_two_level = 1;
            goto skip_tuning_tables;
        }
        FIND_PPN_INDEX(reduce, local_size,conf_index, partial_sub_ok)
    }

    if (partial_sub_ok != 1) {
        conf_index = mv2_reduce_indexed_num_ppn_conf / 2;
    }

conf_check_end:
    /* Search for the corresponding system size inside the tuning table */
    /*
     * Comm sizes progress in powers of 2. Therefore comm_size can just be indexed instead
     */
    table_min_comm_size = 
        mv2_reduce_indexed_thresholds_table[conf_index][0].numproc;
    table_max_comm_size =
        mv2_reduce_indexed_thresholds_table[conf_index]
                [mv2_size_reduce_indexed_tuning_table[conf_index] - 1].numproc;

    if (comm_size < table_min_comm_size) {
        /* Comm size smaller than smallest configuration in table: use smallest available */
        comm_size_index = 0;
    } else if (comm_size > table_max_comm_size) {
        /* Comm size larger than largest configuration in table: use largest available */
        comm_size_index = mv2_size_reduce_indexed_tuning_table[conf_index] - 1;
    } else {
        /* Comm size in between smallest and largest configuration: find closest match */
        lp2ltn_min = pow(2, (int)log2(table_min_comm_size));
        if (comm_ptr->dev.ch.is_pof2) {
            comm_size_index = log2( comm_size / lp2ltn_min );
        } else {
            lp2ltn = pow(2, (int)log2(comm_size));
            comm_size_index = (lp2ltn < lp2ltn_min) ? 0 : log2(lp2ltn / lp2ltn_min);
        }
    }

    last_inter = 
        mv2_reduce_indexed_thresholds_table[conf_index]
                            [comm_size_index].size_inter_table - 1;
    table_min_inter_size =
        mv2_reduce_indexed_thresholds_table[conf_index]
                            [comm_size_index].inter_leader[0].msg_sz;
    table_max_inter_size = 
        mv2_reduce_indexed_thresholds_table[conf_index]
                            [comm_size_index].inter_leader[last_inter].msg_sz;
    last_intra = 
        mv2_reduce_indexed_thresholds_table[conf_index]
                            [comm_size_index].size_intra_table - 1;
    table_min_intra_size =
        mv2_reduce_indexed_thresholds_table[conf_index]
                            [comm_size_index].intra_node[0].msg_sz;
    table_max_intra_size = 
        mv2_reduce_indexed_thresholds_table[conf_index]
                            [comm_size_index].intra_node[last_intra].msg_sz;

    if (nbytes < table_min_inter_size) {
        /* Msg size smaller than smallest configuration in table:
         * use smallest available */
        inter_node_algo_index = 0;
    } else if (nbytes > table_max_inter_size) {
        /* Msg size larger than largest configuration in table:
         * use largest available */
        inter_node_algo_index = last_inter;
    } else {
        /* Msg size in between smallest and largest configuration:
         * find closest match */
        if (pow(2, (int)log2(nbytes)) == nbytes) {
            inter_node_algo_index = log2( nbytes / table_min_inter_size );
        } else {
            lp2ltn = pow(2, (int)log2(nbytes));
            inter_node_algo_index = (lp2ltn < table_min_inter_size) ? 0 :
                                            log2(lp2ltn / table_min_inter_size);
        }
    }

    if (nbytes < table_min_intra_size) {
        /* Msg size smaller than smallest configuration in table:
         * use smallest available */
        intra_node_algo_index = 0;
    } else if (nbytes > table_max_intra_size) {
        /* Msg size larger than largest configuration in table:
         * use largest available */
        intra_node_algo_index = last_intra;
    } else {
        /* Msg size in between smallest and largest configuration:
         * find closest match */
        if (pow(2, (int)log2(nbytes)) == nbytes) {
            intra_node_algo_index = log2(nbytes / table_min_intra_size);
        } else {
            lp2ltn = pow(2, (int)log2(nbytes));
            intra_node_algo_index = (lp2ltn < table_min_intra_size) ? 0 :
                                            log2(lp2ltn / table_min_intra_size);
        }
    }

    /* Set intra-node function pt for reduce_two_level */
    MV2_Reduce_intra_function =
        mv2_reduce_indexed_thresholds_table[conf_index][comm_size_index].
                    intra_node[intra_node_algo_index].MV2_pt_Reduce_function;
    /* Set inter-leader pt */
    MV2_Reduce_function =
        mv2_reduce_indexed_thresholds_table[conf_index][comm_size_index].
                    inter_leader[inter_node_algo_index].MV2_pt_Reduce_function;

    if(mv2_reduce_intra_knomial_factor < 0) {
        mv2_reduce_intra_knomial_factor = 
            mv2_reduce_indexed_thresholds_table[conf_index]
                                        [comm_size_index].intra_k_degree;
    }
    if(mv2_reduce_inter_knomial_factor < 0) {
        mv2_reduce_inter_knomial_factor =
            mv2_reduce_indexed_thresholds_table[conf_index]
                                        [comm_size_index].inter_k_degree;
    }
    if(mv2_reduce_indexed_thresholds_table[conf_index][comm_size_index].
                            is_two_level_reduce[inter_node_algo_index] == 1) {
        is_two_level = 1;
    }

skip_tuning_tables:
#ifdef CHANNEL_MRAIL_GEN2
    if (MPIR_Reduce_Zcpy_MV2 == MV2_Reduce_function) {

        if(mv2_use_slot_shmem_coll &&
                mv2_enable_zcpy_reduce == 1 &&
                nbytes <= mv2_shm_slot_len &&
                comm_ptr->dev.ch.shmem_coll_ok == 1 &&
                mv2_enable_shmem_reduce && is_commutative == 1) {
            /* do nothing and continue to use zcpy */
        } else {
            /*fall back to trusty algorithm because it's invalid to
             * use zcpy without the initializations. */
            MV2_Reduce_function = MPIR_Reduce_binomial_MV2;
        }
    }
#endif /* CHANNEL_MRAIL_GEN2 */


    /* We call Reduce function */
    if(is_two_level == 1) {
        if (comm_ptr->dev.ch.shmem_coll_ok == 1 &&
                is_commutative == 1) {
            mpi_errno = MPIR_Reduce_two_level_helper_MV2(sendbuf, recvbuf,
                                                         count, datatype, op,
                                                         root, comm_ptr,
                                                         errflag);
        } else {
            mpi_errno = MPIR_Reduce_binomial_MV2(sendbuf, recvbuf, count,
                                                 datatype, op, root,
                                                 comm_ptr, errflag);
        }
    } else if(MV2_Reduce_function == &MPIR_Reduce_inter_knomial_wrapper_MV2 ) {
        if(is_commutative ==1) {
            mpi_errno = MV2_Reduce_function(sendbuf, recvbuf, count, datatype,
                                            op, root, comm_ptr, errflag);
        } else {
            mpi_errno = MPIR_Reduce_binomial_MV2(sendbuf, recvbuf, count,
                                                 datatype, op, root,
                                                 comm_ptr, errflag);
        }
    } else if(MV2_Reduce_function == &MPIR_Reduce_redscat_gather_MV2) {
        if ((HANDLE_GET_KIND(op) == HANDLE_KIND_BUILTIN) && (count >= pof2)) {
            mpi_errno = MV2_Reduce_function(sendbuf, recvbuf, count, datatype,
                                            op, root, comm_ptr, errflag);
        } else {
            mpi_errno = MPIR_Reduce_binomial_MV2(sendbuf, recvbuf, count,
                                                 datatype, op, root, comm_ptr, errflag);
        }
    } else {
        mpi_errno = MV2_Reduce_function(sendbuf, recvbuf, count, datatype,
                                        op, root, comm_ptr, errflag);
    }

    if (mpi_errno) {
        /* for communication errors, just record the error but continue */
        *errflag = MPIR_ERR_GET_CLASS(mpi_errno);
        MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
        MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
    }
    MPIR_ERR_CHECK(mpi_errno);
#ifdef _ENABLE_CUDA_
    if (mv2_enable_device && recv_mem_type && (rank == root)) {
        recvbuf = temp_recvbuf;
        MV2_MPID_Memcpy_Device((void *)recvbuf, (void *)recv_host_buf, stride,
                               deviceMemcpyHostToDevice);
    }
    if (mv2_enable_device && recv_mem_type) {
        if (recv_host_buf) {
            MPL_free(recv_host_buf);
            recv_host_buf = NULL;
        }
    }
    if (mv2_enable_device && send_mem_type) {
        if (send_host_buf) {
            MPL_free(send_host_buf);
            send_host_buf = NULL;
        }
    }
#endif
    if (mpi_errno_ret) {
        mpi_errno = mpi_errno_ret;
    } else if (*errflag) {
        MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**coll_fail");
    }

fn_exit:
    return mpi_errno;
fn_fail:
    goto fn_exit;
}

/* not declared static because a machine-specific function may call this one
   in some cases */
int MPIR_Reduce_MV2(const void *sendbuf, void *recvbuf, int count,
                    MPI_Datatype datatype, MPI_Op op, int root,
                    MPIR_Comm * comm_ptr, MPIR_Errflag_t *errflag)
{
    int mpi_errno = MPI_SUCCESS;
    int mpi_errno_ret = MPI_SUCCESS;
    int range = 0;
    int range_threshold = 0;
    int range_intra_threshold = 0;
    int is_commutative, pof2;
    MPIR_Op *op_ptr;
    int comm_size = 0;
    int nbytes = 0;
    int sendtype_size;
    int is_two_level = 0;

    MPIR_T_PVAR_COMM_COUNTER_INC(MV2, mv2_coll_reduce_subcomm, 1, comm_ptr);

    if (mv2_use_indexed_tuning || mv2_use_indexed_reduce_tuning) {
        MPIR_Reduce_index_tuned_intra_MV2(sendbuf, recvbuf, count,
                                          datatype, op, root, comm_ptr,
                                          errflag);
        goto fn_exit;
    }
    comm_size = comm_ptr->local_size;
    MPIR_Datatype_get_size_macro(datatype, sendtype_size);
    nbytes = count * sendtype_size;

    if (count == 0) {
        return MPI_SUCCESS;
    }

    if (HANDLE_GET_KIND(op) == HANDLE_KIND_BUILTIN) {
        is_commutative = 1;
        /* get the function by indexing into the op table */
    } else {
        MPIR_Op_get_ptr(op, op_ptr)
        if (op_ptr->kind == MPIR_OP_KIND__USER_NONCOMMUTE) {
            is_commutative = 0;
        } else {
            is_commutative = 1;
        }
    }

    /* find nearest power-of-two less than or equal to comm_size */
    pof2 = comm_ptr->dev.ch.gpof2;

#ifdef _ENABLE_CUDA_
    int rank = 0, stride = 0;
    MPI_Aint true_lb, true_extent, extent;
    MPIR_Type_get_true_extent_impl(datatype, &true_lb, &true_extent);
    MPIR_Datatype_get_extent_macro(datatype, extent);
    stride = count * MPL_MAX(extent, true_extent);
    int recv_mem_type = 0;
    int send_mem_type = 0;
    char *recv_host_buf = NULL;
    char *send_host_buf = NULL;
    char *temp_recvbuf = recvbuf;
    const char *temp_sendbuf = sendbuf;

    rank = comm_ptr->rank;

    if (mv2_enable_device) {
        recv_mem_type = is_device_buffer(recvbuf);
        if ( sendbuf != MPI_IN_PLACE ) {
            send_mem_type = is_device_buffer(sendbuf);
        }
    }
    if (mv2_enable_device && send_mem_type) {
        send_host_buf = (char*)MPL_malloc(stride, MPL_MEM_COLL);
        MV2_MPID_Memcpy_Device((void *)send_host_buf, (void *)sendbuf, stride,
                               deviceMemcpyDeviceToHost);
        sendbuf = send_host_buf;
    }

    if (mv2_enable_device && recv_mem_type) {
        recv_host_buf = (char*)MPL_malloc(stride, MPL_MEM_COLL);
        MV2_MPID_Memcpy_Device((void *)recv_host_buf, (void *)recvbuf, stride,
                               deviceMemcpyDeviceToHost);
        recvbuf = recv_host_buf;
    }
#endif

    /* Search for the corresponding system size inside the tuning table */
    while ((range < (mv2_size_reduce_tuning_table - 1)) &&
            (comm_size > mv2_reduce_thresholds_table[range].numproc)) {
        range++;
    }
    /* Search for corresponding inter-leader function */
    while ((range_threshold <
                (mv2_reduce_thresholds_table[range].size_inter_table - 1)) &&
           (nbytes > mv2_reduce_thresholds_table[range].
                                        inter_leader[range_threshold].max) &&
           (mv2_reduce_thresholds_table[range].
                                    inter_leader[range_threshold].max != -1)) {
        range_threshold++;
    }

    /* Search for corresponding intra node function */
    while ((range_intra_threshold <
            (mv2_reduce_thresholds_table[range].size_intra_table - 1)) &&
            (nbytes > mv2_reduce_thresholds_table[range].
                                intra_node[range_intra_threshold].max) &&
            (mv2_reduce_thresholds_table[range].
                                intra_node[range_intra_threshold].max != -1)) {
        range_intra_threshold++;
    }

    /* Set intra-node function pt for reduce_two_level */
    MV2_Reduce_intra_function =
        mv2_reduce_thresholds_table[range].intra_node[range_intra_threshold].
        MV2_pt_Reduce_function;
    /* Set inter-leader pt */
    MV2_Reduce_function =
        mv2_reduce_thresholds_table[range].inter_leader[range_threshold].
        MV2_pt_Reduce_function;

    if (mv2_reduce_intra_knomial_factor < 0) {
        mv2_reduce_intra_knomial_factor = 
                mv2_reduce_thresholds_table[range].intra_k_degree;
    }
    if (mv2_reduce_inter_knomial_factor < 0) {
        mv2_reduce_inter_knomial_factor = 
                mv2_reduce_thresholds_table[range].inter_k_degree;
    }
    if (mv2_reduce_thresholds_table[range].
                    is_two_level_reduce[range_threshold] == 1) {
        is_two_level = 1;
    }
    /* We call Reduce function */
    if (is_two_level == 1) {
        if (comm_ptr->dev.ch.shmem_coll_ok == 1 &&
                                    is_commutative == 1) {
            mpi_errno = MPIR_Reduce_two_level_helper_MV2(sendbuf, recvbuf,
                                                         count, datatype, op,
                                                         root, comm_ptr,
                                                         errflag);
        } else {
            mpi_errno = MPIR_Reduce_binomial_MV2(sendbuf, recvbuf, count,
                                                 datatype, op, root, comm_ptr,
                                                 errflag);
        }
    } else if(MV2_Reduce_function == &MPIR_Reduce_inter_knomial_wrapper_MV2 ) {
        if(is_commutative ==1) {
            mpi_errno = MV2_Reduce_function(sendbuf, recvbuf, count,
                                            datatype, op, root, comm_ptr,
                                            errflag);
        } else {
            mpi_errno = MPIR_Reduce_binomial_MV2(sendbuf, recvbuf, count,
                                                 datatype, op, root, comm_ptr,
                                                 errflag);
        }
    } else if(MV2_Reduce_function == &MPIR_Reduce_redscat_gather_MV2) {
        if ((HANDLE_GET_KIND(op) == HANDLE_KIND_BUILTIN) && (count >= pof2)) {
            mpi_errno = MV2_Reduce_function(sendbuf, recvbuf, count,
                                            datatype, op, root, comm_ptr,
                                            errflag);
        } else {
            mpi_errno = MPIR_Reduce_binomial_MV2(sendbuf, recvbuf, count,
                                                 datatype, op, root, comm_ptr,
                                                 errflag);
        }
    } else {
        mpi_errno = MV2_Reduce_function(sendbuf, recvbuf, count,
                                        datatype, op, root, comm_ptr,
                                        errflag);
    }

    if (mpi_errno) {
        /* for communication errors, just record the error but continue */
        *errflag = MPIR_ERR_GET_CLASS(mpi_errno);
        MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
        MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
    }
    MPIR_ERR_CHECK(mpi_errno);
#ifdef _ENABLE_CUDA_
    if (mv2_enable_device && recv_mem_type && (rank == root)) {
        recvbuf = temp_recvbuf;
        MV2_MPID_Memcpy_Device((void *)recvbuf, (void *)recv_host_buf, stride, 
                               deviceMemcpyHostToDevice);
    }
    if (mv2_enable_device && recv_mem_type) {
        if (recv_host_buf) {
            MPL_free(recv_host_buf);
            recv_host_buf = NULL;
        }
    }
    if (mv2_enable_device && send_mem_type) {
        sendbuf = temp_sendbuf;
        if (send_host_buf) {
            MPL_free(send_host_buf);
            send_host_buf = NULL;
        }
    }
#endif
    if (mpi_errno_ret) {
        mpi_errno = mpi_errno_ret;
    } else if (*errflag) {
        MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**coll_fail");
    }

fn_exit:
    return mpi_errno;
fn_fail:
    goto fn_exit;
}
