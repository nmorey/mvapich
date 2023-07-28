/* -*- Mode: C; c-basic-offset:4 ; -*- */
/* Copyright (c) 2001-2023, The Ohio State University. All rights
 * reserved.
 *
 * This file is part of the MVAPICH software package developed by the
 * team members of The Ohio State University's Network-Based Computing
 * Laboratory (NBCL), headed by Professor Dhabaleswar K. (DK) Panda.
 *
 * For detailed copyright and licensing information, please refer to the
 * copyright file COPYRIGHT in the top level MVAPICH directory.
 */

/*
 *
 *  (C) 2001 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

#include "mpiimpl.h"
#include <math.h>
#include <unistd.h>
#include "mvp_coll_shmem.h"
#include "mvp_common_tuning.h"
#include "alltoall_tuning.h"

/*
=== BEGIN_MPI_T_MVP_CVAR_INFO_BLOCK ===

categories:
    - name : COLLECTIVE
      description: INHERITED

cvars:
   - name        : MVP_ALLTOALL_MEDIUM_MSG
     category    : COLLECTIVE
     type        : int
     default     : 16384
     class       : none
     verbosity   : MPI_T_VERBOSITY_USER_BASIC
     scope       : MPI_T_SCOPE_ALL_EQ
     description : >-
       TODO-DESC

   - name        : MVP_ALLTOALL_SMALL_MSG
     category    : COLLECTIVE
     type        : int
     default     : 2048
     class       : none
     verbosity   : MPI_T_VERBOSITY_USER_BASIC
     scope       : MPI_T_SCOPE_ALL_EQ
     description : >-
       TODO-DESC

   - name        : MVP_ALLTOALL_THROTTLE_FACTOR
     category    : COLLECTIVE
     type        : int
     default     : 32
     class       : none
     verbosity   : MPI_T_VERBOSITY_USER_BASIC
     scope       : MPI_T_SCOPE_ALL_EQ
     description : >-
       TODO-DESC

   - name        : MVP_ALLTOALL_INTRA_THROTTLE_FACTOR
     category    : COLLECTIVE
     type        : int
     default     : 32
     class       : none
     verbosity   : MPI_T_VERBOSITY_USER_BASIC
     scope       : MPI_T_SCOPE_ALL_EQ
     description : >-
       TODO-DESC

   - name        : MVP_ALLTOALL_LARGE_MSG_THROTTLE_FACTOR
     category    : COLLECTIVE
     type        : int
     default     : 4
     class       : none
     verbosity   : MPI_T_VERBOSITY_USER_BASIC
     scope       : MPI_T_SCOPE_ALL_EQ
     description : >-
       TODO-DESC

   - name        : MVP_USE_XOR_ALLTOALL
     category    : COLLECTIVE
     type        : int
     default     : 1
     class       : none
     verbosity   : MPI_T_VERBOSITY_USER_BASIC
     scope       : MPI_T_SCOPE_ALL_EQ
     description : >-
       TODO-DESC

=== END_MPI_T_MVP_CVAR_INFO_BLOCK ===
*/

/* This is the default implementation of alltoall. The algorithm is:

   Algorithm: MPI_Alltoall

   We use four algorithms for alltoall. For short messages and
   (comm_size >= 8), we use the algorithm by Jehoshua Bruck et al,
   IEEE TPDS, Nov. 1997. It is a store-and-forward algorithm that
   takes lgp steps. Because of the extra communication, the bandwidth
   requirement is (n/2).lgp.beta.

   Cost = lgp.alpha + (n/2).lgp.beta

   where n is the total amount of data a process needs to send to all
   other processes.

   For medium size messages and (short messages for comm_size < 8), we
   use an algorithm that posts all irecvs and isends and then does a
   waitall. We scatter the order of sources and destinations among the
   processes, so that all processes don't try to send/recv to/from the
   same process at the same time.

   For long messages and power-of-two number of processes, we use a
   pairwise exchange algorithm, which takes p-1 steps. We
   calculate the pairs by using an exclusive-or algorithm:
           for (i=1; i<comm_size; i++)
               dest = rank ^ i;
   This algorithm doesn't work if the number of processes is not a power of
   two. For a non-power-of-two number of processes, we use an
   algorithm in which, in step i, each process  receives from (rank-i)
   and sends to (rank+i).

   Cost = (p-1).alpha + n.beta

   where n is the total amount of data a process needs to send to all
   other processes.

   Possible improvements:

   End Algorithm: MPI_Alltoall
*/

int (*MVP_Alltoall_function)(const void *sendbuf, int sendcount,
                             MPI_Datatype sendtype, void *recvbuf,
                             int recvcount, MPI_Datatype recvtype,
                             MPIR_Comm *comm_ptr,
                             MPIR_Errflag_t *errflag) = NULL;

int MPIR_Alltoall_RD_MVP(const void *sendbuf, int sendcount,
                         MPI_Datatype sendtype, void *recvbuf, int recvcount,
                         MPI_Datatype recvtype, MPIR_Comm *comm_ptr,
                         MPIR_Errflag_t *errflag)
{
    if ((HANDLE_GET_KIND(sendtype) == HANDLE_KIND_BUILTIN) &&
        (HANDLE_GET_KIND(recvtype) == HANDLE_KIND_BUILTIN)) {
        return MPIR_Alltoall_ALG_MVP(sendbuf, sendcount, sendtype, recvbuf,
                                     recvcount, recvtype, comm_ptr, errflag);
    } else {
        return MPIR_Alltoall_pairwise_MVP(sendbuf, sendcount, sendtype, recvbuf,
                                          recvcount, recvtype, comm_ptr,
                                          errflag);
    }
}

int MPIR_Alltoall_index_tuned_intra_MVP(const void *sendbuf, int sendcount,
                                        MPI_Datatype sendtype, void *recvbuf,
                                        int recvcount, MPI_Datatype recvtype,
                                        MPIR_Comm *comm_ptr,
                                        MPIR_Errflag_t *errflag)
{
    int sendtype_size, recvtype_size, comm_size;
    MPI_Aint nbytes;
    char *tmp_buf = NULL;
    int mpi_errno = MPI_SUCCESS;
    int partial_sub_ok = 0;
    int conf_index = 0;
    int local_size = -1;
    int comm_size_index = 0;
    int inter_node_algo_index = 0;
    int table_min_comm_size = 0;
    int table_max_comm_size = 0;
    int table_min_inter_size = 0;
    int table_max_inter_size = 0;
    int last_inter;
    int lp2ltn; // largest power of 2 less than n
    int lp2ltn_min;
    MPI_Comm shmem_comm;
    MPIR_Comm *shmem_commptr = NULL;
    comm_size = comm_ptr->local_size;

    MPIR_Datatype_get_size_macro(sendtype, sendtype_size);
    MPIR_Datatype_get_size_macro(recvtype, recvtype_size);
    nbytes = (MPI_Aint)sendtype_size * sendcount;

#ifdef CHANNEL_PSM
    /* To avoid picking up algorithms like recursive doubling alltoall
     * if psm is used */
    if (nbytes >= ipath_max_transfer_size) {
        MVP_Alltoall_function = MPIR_Alltoall_pairwise_MVP;
        goto psm_a2a_bypass;
    }
#endif

    /* check if safe to use partial subscription mode */
    if (comm_ptr->dev.ch.shmem_coll_ok == 1 && comm_ptr->dev.ch.is_uniform) {
        shmem_comm = comm_ptr->dev.ch.shmem_comm;
        MPIR_Comm_get_ptr(shmem_comm, shmem_commptr);
        local_size = shmem_commptr->local_size;
        if (mvp_alltoall_indexed_table_ppn_conf[0] == -1) {
            /* Indicating user defined tuning */
            conf_index = 0;
            goto conf_check_end;
        }
        if (likely(MVP_ENABLE_SKIP_TUNING_TABLE_SEARCH &&
                   (nbytes <= MVP_COLL_SKIP_TABLE_THRESHOLD))) {
            /* for small messages, force Bruck or RD */
            if (comm_size * nbytes < MVP_ALLTOALL_RD_MAX_MSG_SIZE &&
                local_size < 16 && nbytes < 32) {
                MVP_Alltoall_function = MPIR_Alltoall_RD_MVP;
            } else {
                MVP_Alltoall_function = MPIR_Alltoall_bruck_MVP;
            }
            goto skip_tuning_tables;
        }

        FIND_PPN_INDEX(alltoall, local_size, conf_index, partial_sub_ok)
    }

    if (partial_sub_ok != 1) {
        conf_index = mvp_alltoall_indexed_num_ppn_conf / 2;
    }

conf_check_end:

    /* Search for the corresponding system size inside the tuning table */
    /*
     * Comm sizes progress in powers of 2.
     * Therefore comm_size can just be indexed instead
     */
    table_min_comm_size =
        mvp_alltoall_indexed_thresholds_table[conf_index][0].numproc;
    table_max_comm_size =
        mvp_alltoall_indexed_thresholds_table
            [conf_index][mvp_size_alltoall_indexed_tuning_table[conf_index] - 1]
                .numproc;

    if (comm_size < table_min_comm_size) {
        /* Comm size smaller than smallest configuration in table: use smallest
         * available */
        comm_size_index = 0;
    } else if (comm_size > table_max_comm_size) {
        /* Comm size larger than largest configuration in table: use largest
         * available */
        comm_size_index =
            mvp_size_alltoall_indexed_tuning_table[conf_index] - 1;
    } else {
        /* Comm size in between smallest and largest configuration: find closest
         * match */
        lp2ltn_min = pow(2, (int)log2(table_min_comm_size));
        if (comm_ptr->dev.ch.is_pof2) {
            comm_size_index = log2(comm_size / lp2ltn_min);
        } else {
            lp2ltn = pow(2, (int)log2(comm_size));
            comm_size_index =
                (lp2ltn < lp2ltn_min) ? 0 : log2(lp2ltn / lp2ltn_min);
        }
    }

    last_inter =
        mvp_alltoall_indexed_thresholds_table[conf_index][comm_size_index]
            .size_table -
        1;
    table_min_inter_size =
        mvp_alltoall_indexed_thresholds_table[conf_index][comm_size_index]
            .algo_table[0]
            .msg_sz;
    table_max_inter_size =
        mvp_alltoall_indexed_thresholds_table[conf_index][comm_size_index]
            .algo_table[last_inter]
            .msg_sz;

    if (nbytes < table_min_inter_size) {
        /* Msg size smaller than smallest configuration in table: use smallest
         * available */
        inter_node_algo_index = 0;
    } else if (nbytes > table_max_inter_size) {
        /* Msg size larger than largest configuration in table: use largest
         * available */
        inter_node_algo_index = last_inter;
    } else {
        /* Msg size in between smallest and largest configuration: find closest
         * match */
        if (pow(2, (int)log2(nbytes)) == nbytes) {
            inter_node_algo_index = log2(nbytes / table_min_inter_size);
        } else {
            lp2ltn = pow(2, (int)log2(nbytes));
            inter_node_algo_index = (lp2ltn < table_min_inter_size) ?
                                        0 :
                                        log2(lp2ltn / table_min_inter_size);
        }
    }

    MVP_Alltoall_function =
        mvp_alltoall_indexed_thresholds_table[conf_index][comm_size_index]
            .algo_table[inter_node_algo_index]
            .MVP_pt_Alltoall_function;

#ifdef _MVP_CH4_OVERRIDE_
psm_a2a_bypass:
#endif
skip_tuning_tables:

    if (sendbuf != MPI_IN_PLACE) {
        mpi_errno =
            MVP_Alltoall_function(sendbuf, sendcount, sendtype, recvbuf,
                                  recvcount, recvtype, comm_ptr, errflag);
    } else {
        if (mvp_alltoall_indexed_thresholds_table[conf_index][comm_size_index]
                .in_place_algo_table[inter_node_algo_index] == 0) {
            tmp_buf = (char *)MPL_malloc(comm_size * recvcount * recvtype_size,
                                         MPL_MEM_COLL);
            mpi_errno = MPIR_Localcopy((char *)recvbuf, comm_size * recvcount,
                                       recvtype, (char *)tmp_buf,
                                       comm_size * recvcount, recvtype);

            mpi_errno =
                MVP_Alltoall_function(tmp_buf, recvcount, recvtype, recvbuf,
                                      recvcount, recvtype, comm_ptr, errflag);
            MPL_free(tmp_buf);
        } else {
            mpi_errno = MPIR_Alltoall_inplace_MVP(sendbuf, sendcount, sendtype,
                                                  recvbuf, recvcount, recvtype,
                                                  comm_ptr, errflag);
        }
    }
    return (mpi_errno);
}
/* begin:nested */
/* not declared static because a machine-specific function may call this one in
 * some cases */
int MPIR_Alltoall_tune_intra_MVP(const void *sendbuf, int sendcount,
                                 MPI_Datatype sendtype, void *recvbuf,
                                 int recvcount, MPI_Datatype recvtype,
                                 MPIR_Comm *comm_ptr, MPIR_Errflag_t *errflag)
{
    int sendtype_size, recvtype_size, nbytes, comm_size;
    char *tmp_buf = NULL;
    int mpi_errno = MPI_SUCCESS;
    int range = 0;
    int range_threshold = 0;
    int partial_sub_ok = 0;
    int conf_index = 0;
    int local_size = -1;
    MPI_Comm shmem_comm;
    MPIR_Comm *shmem_commptr = NULL;
    comm_size = comm_ptr->local_size;

    MPIR_Datatype_get_size_macro(sendtype, sendtype_size);
    MPIR_Datatype_get_size_macro(recvtype, recvtype_size);
    nbytes = sendtype_size * sendcount;

    /* check if safe to use partial subscription mode */
    if (comm_ptr->dev.ch.shmem_coll_ok == 1 && comm_ptr->dev.ch.is_uniform) {
        shmem_comm = comm_ptr->dev.ch.shmem_comm;
        MPIR_Comm_get_ptr(shmem_comm, shmem_commptr);
        local_size = shmem_commptr->local_size;
        if (mvp_alltoall_table_ppn_conf[0] == -1) {
            /* Indicating user defined tuning */
            conf_index = 0;
            goto conf_check_end;
        }
        FIND_PPN_INDEX(alltoall, local_size, conf_index, partial_sub_ok)
    }

    if (partial_sub_ok != 1) {
        conf_index = mvp_alltoall_num_ppn_conf / 2;
    }

conf_check_end:

    /* Search for the corresponding system size inside the tuning table */
    while ((range < (mvp_size_alltoall_tuning_table[conf_index] - 1)) &&
           (comm_size >
            mvp_alltoall_thresholds_table[conf_index][range].numproc)) {
        range++;
    }
    /* Search for corresponding inter-leader function */
    while (
        (range_threshold <
         (mvp_alltoall_thresholds_table[conf_index][range].size_table - 1)) &&
        (nbytes > mvp_alltoall_thresholds_table[conf_index][range]
                      .algo_table[range_threshold]
                      .max) &&
        (mvp_alltoall_thresholds_table[conf_index][range]
             .algo_table[range_threshold]
             .max != -1)) {
        range_threshold++;
    }
    MVP_Alltoall_function = mvp_alltoall_thresholds_table[conf_index][range]
                                .algo_table[range_threshold]
                                .MVP_pt_Alltoall_function;

    if (sendbuf != MPI_IN_PLACE) {
        mpi_errno =
            MVP_Alltoall_function(sendbuf, sendcount, sendtype, recvbuf,
                                  recvcount, recvtype, comm_ptr, errflag);
    } else {
        range_threshold = 0;
        if (nbytes < mvp_alltoall_thresholds_table[conf_index][range]
                         .in_place_algo_table[range_threshold]
                         .min ||
            nbytes > mvp_alltoall_thresholds_table[conf_index][range]
                         .in_place_algo_table[range_threshold]
                         .max) {
            tmp_buf = (char *)MPL_malloc(comm_size * recvcount * recvtype_size,
                                         MPL_MEM_COLL);
            mpi_errno = MPIR_Localcopy((char *)recvbuf, comm_size * recvcount,
                                       recvtype, (char *)tmp_buf,
                                       comm_size * recvcount, recvtype);

            mpi_errno =
                MVP_Alltoall_function(tmp_buf, recvcount, recvtype, recvbuf,
                                      recvcount, recvtype, comm_ptr, errflag);
            MPL_free(tmp_buf);
        } else {
            mpi_errno = MPIR_Alltoall_inplace_MVP(sendbuf, sendcount, sendtype,
                                                  recvbuf, recvcount, recvtype,
                                                  comm_ptr, errflag);
        }
    }
    return (mpi_errno);
}

/* old version of MPIR_Alltoall_intra_MVP */
int MPIR_Alltoall_intra_MVP(const void *sendbuf, int sendcount,
                            MPI_Datatype sendtype, void *recvbuf, int recvcount,
                            MPI_Datatype recvtype, MPIR_Comm *comm_ptr,
                            MPIR_Errflag_t *errflag)
{
    int comm_size, i, j, pof2;
    MPI_Aint sendtype_extent, recvtype_extent;
    MPI_Aint recvtype_true_extent, recvbuf_extent, recvtype_true_lb;
    int mpi_errno = MPI_SUCCESS;
    int mpi_errno_ret = MPI_SUCCESS;
    int src, dst, rank, nbytes;
    MPI_Status status;
    int sendtype_size, block, *displs, count;
    MPI_Aint pack_size, position;
    MPI_Datatype newtype;
    void *tmp_buf;
    void *tmp;
    MPIR_Request **reqarray;
    MPI_Status *starray;
#ifdef MPIR_OLD_SHORT_ALLTOALL_ALG
    MPI_Aint sendtype_true_extent, sendbuf_extent, sendtype_true_lb;
    int k, p, curr_cnt, dst_tree_root, my_tree_root;
    int last_recv_cnt, mask, tmp_mask, tree_root, nprocs_completed;
#endif

    if (recvcount == 0)
        return MPI_SUCCESS;

    comm_size = comm_ptr->local_size;
    rank = comm_ptr->rank;

    /* Get extent of send and recv types */
    MPIR_Datatype_get_extent_macro(recvtype, recvtype_extent);
    MPIR_Datatype_get_extent_macro(sendtype, sendtype_extent);

    MPIR_Datatype_get_size_macro(sendtype, sendtype_size);
    nbytes = sendtype_size * sendcount;

    if (sendbuf == MPI_IN_PLACE) {
        /* We use pair-wise sendrecv_replace in order to conserve memory usage,
         * which is keeping with the spirit of the MPI-2.2 Standard.  But
         * because of this approach all processes must agree on the global
         * schedule of sendrecv_replace operations to avoid deadlock.
         *
         * Note that this is not an especially efficient algorithm in terms of
         * time and there will be multiple repeated malloc/free's rather than
         * maintaining a single buffer across the whole loop.  Something like
         * MADRE is probably the best solution for the MPI_IN_PLACE scenario. */
        for (i = 0; i < comm_size; ++i) {
            /* start inner loop at i to avoid re-exchanging data */
            for (j = i; j < comm_size; ++j) {
                if (rank == i) {
                    /* also covers the (rank == i && rank == j) case */
                    MPIR_PVAR_INC(alltoall, intra, send, recvcount, recvtype);
                    MPIR_PVAR_INC(alltoall, intra, recv, recvcount, recvtype);
                    mpi_errno = MPIC_Sendrecv_replace(
                        ((char *)recvbuf + j * recvcount * recvtype_extent),
                        recvcount, recvtype, j, MPIR_ALLTOALL_TAG, j,
                        MPIR_ALLTOALL_TAG, comm_ptr, &status, errflag);
                    if (mpi_errno) {
                        /* for communication errors, just record the error but
                         * continue */
                        *errflag = MPIR_ERR_GET_CLASS(mpi_errno);
                        MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
                        MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
                    }
                } else if (rank == j) {
                    /* same as above with i/j args reversed */
                    MPIR_PVAR_INC(alltoall, intra, send, recvcount, recvtype);
                    MPIR_PVAR_INC(alltoall, intra, recv, recvcount, recvtype);
                    mpi_errno = MPIC_Sendrecv_replace(
                        ((char *)recvbuf + i * recvcount * recvtype_extent),
                        recvcount, recvtype, i, MPIR_ALLTOALL_TAG, i,
                        MPIR_ALLTOALL_TAG, comm_ptr, &status, errflag);
                    if (mpi_errno) {
                        /* for communication errors, just record the error but
                         * continue */
                        *errflag = MPIR_ERR_GET_CLASS(mpi_errno);
                        MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
                        MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
                    }
                }
            }
        }
    }

    else if ((nbytes <= MVP_ALLTOALL_SMALL_MSG) &&
             (comm_size >= 8)
#if defined(_ENABLE_CUDA_)
             /* use Isend/Irecv and pairwise in cuda configuration*/
             && !mvp_enable_device
#endif
    ) {

        /* use the indexing algorithm by Jehoshua Bruck et al,
         * IEEE TPDS, Nov. 97 */

        /* allocate temporary buffer */
        MPIR_Pack_size_impl(recvcount * comm_size, recvtype, &pack_size);
        tmp_buf = MPL_malloc(pack_size, MPL_MEM_COLL);
        /* --BEGIN ERROR HANDLING-- */
        if (!tmp_buf) {
            mpi_errno = MPIR_Err_create_code(MPI_SUCCESS, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**nomem", 0);
            return mpi_errno;
        }
        /* --END ERROR HANDLING-- */

        /* Do Phase 1 of the algorithim. Shift the data blocks on process i
         * upwards by a distance of i blocks. Store the result in recvbuf. */
        mpi_errno =
            MPIR_Localcopy((char *)sendbuf + rank * sendcount * sendtype_extent,
                           (comm_size - rank) * sendcount, sendtype, recvbuf,
                           (comm_size - rank) * recvcount, recvtype);
        MPIR_ERR_CHECK(mpi_errno);
        mpi_errno = MPIR_Localcopy(
            sendbuf, rank * sendcount, sendtype,
            (char *)recvbuf + (comm_size - rank) * recvcount * recvtype_extent,
            rank * recvcount, recvtype);
        MPIR_ERR_CHECK(mpi_errno);
        /* Input data is now stored in recvbuf with datatype recvtype */

        /* Now do Phase 2, the communication phase. It takes
           ceiling(lg p) steps. In each step i, each process sends to rank+2^i
           and receives from rank-2^i, and exchanges all data blocks
           whose ith bit is 1. */

        /* allocate displacements array for indexed datatype used in
           communication */

        displs = MPL_malloc(comm_size * sizeof(int), MPL_MEM_COLL);
        /* --BEGIN ERROR HANDLING-- */
        if (!displs) {
            mpi_errno = MPIR_Err_create_code(MPI_SUCCESS, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**nomem", 0);
            return mpi_errno;
        }
        /* --END ERROR HANDLING-- */

        pof2 = 1;
        while (pof2 < comm_size) {
            dst = (rank + pof2) % comm_size;
            src = (rank - pof2 + comm_size) % comm_size;

            /* Exchange all data blocks whose ith bit is 1 */
            /* Create an indexed datatype for the purpose */

            count = 0;
            for (block = 1; block < comm_size; block++) {
                if (block & pof2) {
                    displs[count] = block * recvcount;
                    count++;
                }
            }

            mpi_errno = MPIR_Type_create_indexed_block_impl(
                count, recvcount, displs, recvtype, &newtype);
            MPIR_ERR_CHECK(mpi_errno);

            mpi_errno = MPIR_Type_commit_impl(&newtype);
            MPIR_ERR_CHECK(mpi_errno);

            position = 0;
            mpi_errno = MPIR_Typerep_pack(recvbuf, 1, newtype, position,
                                          tmp_buf, pack_size, &position);
            MPIR_ERR_CHECK(mpi_errno);

            MPIR_PVAR_INC(alltoall, intra, send, position, MPI_PACKED);
            MPIR_PVAR_INC(alltoall, intra, recv, 1, newtype);
            mpi_errno = MPIC_Sendrecv(tmp_buf, position, MPI_PACKED, dst,
                                      MPIR_ALLTOALL_TAG, recvbuf, 1, newtype,
                                      src, MPIR_ALLTOALL_TAG, comm_ptr,
                                      MPI_STATUS_IGNORE, errflag);
            if (mpi_errno) {
                /* for communication errors, just record the error but continue
                 */
                *errflag = MPIR_ERR_GET_CLASS(mpi_errno);
                MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
                MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
            }

            MPIR_Type_free_impl(&newtype);

            pof2 *= 2;
        }

        MPL_free(displs);
        MPL_free(tmp_buf);

        /* Rotate blocks in recvbuf upwards by (rank + 1) blocks. Need
         * a temporary buffer of the same size as recvbuf. */

        /* get true extent of recvtype */
        MPIR_Type_get_true_extent_impl(recvtype, &recvtype_true_lb,
                                       &recvtype_true_extent);
        recvbuf_extent = recvcount * comm_size *
                         (MPL_MAX(recvtype_true_extent, recvtype_extent));
        tmp_buf = MPL_malloc(recvbuf_extent, MPL_MEM_COLL);
        /* --BEGIN ERROR HANDLING-- */
        if (!tmp_buf) {
            mpi_errno = MPIR_Err_create_code(MPI_SUCCESS, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**nomem", 0);
            return mpi_errno;
        }
        /* --END ERROR HANDLING-- */
        /* adjust for potential negative lower bound in datatype */
        tmp_buf = (void *)((char *)tmp_buf - recvtype_true_lb);

        mpi_errno = MPIR_Localcopy(
            (char *)recvbuf + (rank + 1) * recvcount * recvtype_extent,
            (comm_size - rank - 1) * recvcount, recvtype, tmp_buf,
            (comm_size - rank - 1) * recvcount, recvtype);
        MPIR_ERR_CHECK(mpi_errno);
        mpi_errno =
            MPIR_Localcopy(recvbuf, (rank + 1) * recvcount, recvtype,
                           (char *)tmp_buf + (comm_size - rank - 1) *
                                                 recvcount * recvtype_extent,
                           (rank + 1) * recvcount, recvtype);
        MPIR_ERR_CHECK(mpi_errno);

        /* Blocks are in the reverse order now (comm_size-1 to 0).
         * Reorder them to (0 to comm_size-1) and store them in recvbuf. */

        for (i = 0; i < comm_size; i++)
            MPIR_Localcopy((char *)tmp_buf + i * recvcount * recvtype_extent,
                           recvcount, recvtype,
                           (char *)recvbuf + (comm_size - i - 1) * recvcount *
                                                 recvtype_extent,
                           recvcount, recvtype);

        tmp = (void *)(tmp_buf + recvtype_true_lb);
        MPL_free(tmp);

#ifdef MPIR_OLD_SHORT_ALLTOALL_ALG
        /* Short message. Use recursive doubling. Each process sends all
           its data at each step along with all data it received in
           previous steps. */

        /* need to allocate temporary buffer of size
           sendbuf_extent*comm_size */

        /* get true extent of sendtype */
        MPIR_Type_get_true_extent_impl(sendtype, &sendtype_true_lb,
                                       &sendtype_true_extent);
        sendbuf_extent = sendcount * comm_size *
                         (MPL_MAX(sendtype_true_extent, sendtype_extent));
        tmp_buf = MPL_malloc(sendbuf_extent * comm_size, MPL_MEM_COLL);
        /* --BEGIN ERROR HANDLING-- */
        if (!tmp_buf) {
            mpi_errno = MPIR_Err_create_code(MPI_SUCCESS, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**nomem", 0);
            return mpi_errno;
        }
        /* --END ERROR HANDLING-- */

        /* adjust for potential negative lower bound in datatype */
        tmp_buf = (void *)((char *)tmp_buf - sendtype_true_lb);

        /* copy local sendbuf into tmp_buf at location indexed by rank */
        curr_cnt = sendcount * comm_size;
        mpi_errno = MPIR_Localcopy(sendbuf, curr_cnt, sendtype,
                                   ((char *)tmp_buf + rank * sendbuf_extent),
                                   curr_cnt, sendtype);
        MPIR_ERR_CHECK(mpi_errno);

        mask = 0x1;
        i = 0;
        while (mask < comm_size) {
            dst = rank ^ mask;

            dst_tree_root = dst >> i;
            dst_tree_root <<= i;

            my_tree_root = rank >> i;
            my_tree_root <<= i;

            if (dst < comm_size) {
                MPIR_PVAR_INC(alltoall, intra, send, curr_cnt, sendtype);
                MPIR_PVAR_INC(alltoall, intra, recv,
                              sendbuf_extent * (comm_size - dst_tree_root),
                              sendtype);
                mpi_errno = MPIC_Sendrecv(
                    ((char *)tmp_buf + my_tree_root * sendbuf_extent), curr_cnt,
                    sendtype, dst, MPIR_ALLTOALL_TAG,
                    ((char *)tmp_buf + dst_tree_root * sendbuf_extent),
                    sendbuf_extent * (comm_size - dst_tree_root), sendtype, dst,
                    MPIR_ALLTOALL_TAG, comm_ptr, &status, errflag);
                if (mpi_errno) {
                    /* for communication errors, just record the error but
                     * continue */
                    *errflag = MPIR_ERR_GET_CLASS(mpi_errno);
                    MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
                    MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
                }

                /* in case of non-power-of-two nodes, less data may be
                   received than specified */
                MPIR_Get_count_impl(&status, sendtype, &last_recv_cnt);
                curr_cnt += last_recv_cnt;
            }

            /* if some processes in this process's subtree in this step
               did not have any destination process to communicate with
               because of non-power-of-two, we need to send them the
               result. We use a logarithmic recursive-halfing algorithm
               for this. */

            if (dst_tree_root + mask > comm_size) {
                nprocs_completed = comm_size - my_tree_root - mask;
                /* nprocs_completed is the number of processes in this
                   subtree that have all the data. Send data to others
                   in a tree fashion. First find root of current tree
                   that is being divided into two. k is the number of
                   least-significant bits in this process's rank that
                   must be zeroed out to find the rank of the root */
                j = mask;
                k = 0;
                while (j) {
                    j >>= 1;
                    k++;
                }
                k--;

                tmp_mask = mask >> 1;
                while (tmp_mask) {
                    dst = rank ^ tmp_mask;

                    tree_root = rank >> k;
                    tree_root <<= k;

                    /* send only if this proc has data and destination
                       doesn't have data. at any step, multiple processes
                       can send if they have the data */
                    if ((dst > rank) && (rank < tree_root + nprocs_completed) &&
                        (dst >= tree_root + nprocs_completed)) {
                        /* send the data received in this step above */
                        MPIR_PVAR_INC(alltoall, intra, send, last_recv_cnt,
                                      sendtype);
                        mpi_errno = MPIC_Send(
                            ((char *)tmp_buf + dst_tree_root * sendbuf_extent),
                            last_recv_cnt, sendtype, dst, MPIR_ALLTOALL_TAG,
                            comm_ptr, errflag);
                        if (mpi_errno) {
                            /* for communication errors, just record the error
                             * but continue */
                            *errflag = MPIR_ERR_GET_CLASS(mpi_errno);
                            MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
                            MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
                        }

                        /* recv only if this proc. doesn't have data and sender
                           has data */
                        else if ((dst < rank) &&
                                 (dst < tree_root + nprocs_completed) &&
                                 (rank >= tree_root + nprocs_completed)) {
                            MPIR_PVAR_INC(alltoall, intra, recv,
                                          sendbuf_extent *
                                              (comm_size - dst_tree_root),
                                          sendtype);
                            mpi_errno = MPIC_Recv(
                                ((char *)tmp_buf +
                                 dst_tree_root * sendbuf_extent),
                                sendbuf_extent * (comm_size - dst_tree_root),
                                sendtype, dst, MPIR_ALLTOALL_TAG, comm_ptr,
                                &status, errflag);
                            if (mpi_errno) {
                                /* for communication errors, just record the
                                 * error but continue */
                                *errflag = MPIR_ERR_GET_CLASS(mpi_errno);
                                MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER,
                                             "**fail");
                                MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
                            }

                            MPIR_ERR_CHECK(mpi_errno);
                            MPIR_Get_count_impl(&status, sendtype,
                                                &last_recv_cnt);
                            curr_cnt += last_recv_cnt;
                        }
                        tmp_mask >>= 1;
                        k--;
                    }
                }

                mask <<= 1;
                i++;
            }

            /* now copy everyone's contribution from tmp_buf to recvbuf */
            for (p = 0; p < comm_size; p++) {
                mpi_errno = MPIR_Localcopy(
                    ((char *)tmp_buf + p * sendbuf_extent +
                     rank * sendcount * sendtype_extent),
                    sendcount, sendtype,
                    ((char *)recvbuf + p * recvcount * recvtype_extent),
                    recvcount, recvtype);
                MPIR_ERR_CHECK(mpi_errno);
            }

            tmp = (void *)(tmp_buf + sendtype_true_lb);
            MPL_free(tmp);
#endif
        }
        else if (nbytes <= MVP_ALLTOALL_MEDIUM_MSG)
        {
            /* Medium-size message. Use isend/irecv with scattered
               destinations. Use Tony Ladd's modification to post only
               a small number of isends/irecvs at a time. */
            /* FIXME: This converts the Alltoall to a set of blocking phases.
               Two alternatives should be considered:
               1) the choice of communication pattern could try to avoid
                  contending routes in each phase
               2) rather than wait for all communication to finish (waitall),
                  we could maintain constant queue size by using waitsome
                  and posting new isend/irecv as others complete.  This avoids
                  synchronization delays at the end of each block (when
                  there are only a few isend/irecvs left)
             */
            int ii, ss, bblock;

            MPIR_CHKLMEM_DECL(2);

            bblock = MVP_ALLTOALL_THROTTLE_FACTOR;

            if (bblock >= comm_size)
                bblock = comm_size;
            /* If throttle_factor is n, each process posts n pairs of
               isend/irecv in each iteration. */

            /* FIXME: This should use the memory macros (there are storage
               leaks here if there is an error, for example) */
            MPIR_CHKLMEM_MALLOC(reqarray, MPIR_Request **,
                                2 * bblock * sizeof(MPIR_Request *), mpi_errno,
                                "reqarray", MPL_MEM_COLL);

            MPIR_CHKLMEM_MALLOC(starray, MPI_Status *,
                                2 * bblock * sizeof(MPI_Status), mpi_errno,
                                "starray", MPL_MEM_COLL);

            for (ii = 0; ii < comm_size; ii += bblock) {
                ss = comm_size - ii < bblock ? comm_size - ii : bblock;
                /* do the communication -- post ss sends and receives: */
                for (i = 0; i < ss; i++) {
                    dst = (rank + i + ii) % comm_size;
                    MPIR_PVAR_INC(alltoall, intra, recv, recvcount, recvtype);
                    mpi_errno = MPIC_Irecv(
                        (char *)recvbuf + dst * recvcount * recvtype_extent,
                        recvcount, recvtype, dst, MPIR_ALLTOALL_TAG, comm_ptr,
                        &reqarray[i]);
                    MPIR_ERR_CHECK(mpi_errno);
                }

                for (i = 0; i < ss; i++) {
                    dst = (rank - i - ii + comm_size) % comm_size;
                    MPIR_PVAR_INC(alltoall, intra, send, sendcount, sendtype);
                    mpi_errno = MPIC_Isend(
                        (char *)sendbuf + dst * sendcount * sendtype_extent,
                        sendcount, sendtype, dst, MPIR_ALLTOALL_TAG, comm_ptr,
                        &reqarray[i + ss], errflag);
                    MPIR_ERR_CHECK(mpi_errno);
                }

                /* ... then wait for them to finish: */
                mpi_errno = MPIC_Waitall(2 * ss, reqarray, starray, errflag);
                MPIR_ERR_CHECK(mpi_errno);

                /* --BEGIN ERROR HANDLING-- */
                if (mpi_errno == MPI_ERR_IN_STATUS) {
                    for (j = 0; j < 2 * ss; j++) {
                        if (starray[j].MPI_ERROR != MPI_SUCCESS) {
                            mpi_errno = starray[j].MPI_ERROR;
                        }
                    }
                }
            }
            /* --END ERROR HANDLING-- */
            MPIR_CHKLMEM_FREEALL();
        }
        else
        {
            /* Long message. If comm_size is a power-of-two, do a pairwise
               exchange using exclusive-or to create pairs. Else send to
               rank+i, receive from rank-i. */

            /* Make local copy first */
            mpi_errno = MPIR_Localcopy(
                ((char *)sendbuf + rank * sendcount * sendtype_extent),
                sendcount, sendtype,
                ((char *)recvbuf + rank * recvcount * recvtype_extent),
                recvcount, recvtype);
            MPIR_ERR_CHECK(mpi_errno);

            /* Is comm_size a power-of-two? */
            i = 1;
            while (i < comm_size)
                i *= 2;

            if (i == comm_size && MVP_USE_XOR_ALLTOALL) {
                pof2 = 1;
            } else {
                pof2 = 0;
            }

            /* Do the pairwise exchanges */
            for (i = 1; i < comm_size; i++) {
                if (pof2 == 1) {
                    /* use exclusive-or algorithm */
                    src = dst = rank ^ i;
                } else {
                    src = (rank - i + comm_size) % comm_size;
                    dst = (rank + i) % comm_size;
                }

                MPIR_PVAR_INC(alltoall, intra, send, sendcount, sendtype);
                MPIR_PVAR_INC(alltoall, intra, recv, recvcount, recvtype);
                mpi_errno = MPIC_Sendrecv(
                    ((char *)sendbuf + dst * sendcount * sendtype_extent),
                    sendcount, sendtype, dst, MPIR_ALLTOALL_TAG,
                    ((char *)recvbuf + src * recvcount * recvtype_extent),
                    recvcount, recvtype, src, MPIR_ALLTOALL_TAG, comm_ptr,
                    &status, errflag);
                if (mpi_errno) {
                    /* for communication errors, just record the error but
                     * continue */
                    *errflag = MPIR_ERR_GET_CLASS(mpi_errno);
                    MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
                    MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
                }
            }
        }

    fn_fail:
        return (mpi_errno);
    }

    /* end:nested */

    int MPIR_Alltoall_MVP(const void *sendbuf, int sendcount,
                          MPI_Datatype sendtype, void *recvbuf, int recvcount,
                          MPI_Datatype recvtype, MPIR_Comm *comm_ptr,
                          MPIR_Errflag_t *errflag)
    {
        int mpi_errno = MPI_SUCCESS;

#ifdef _ENABLE_CUDA_
        MPI_Aint sendtype_extent, recvtype_extent;
        int comm_size, nbytes = 0, snbytes = 0;
        int send_mem_type = 0, recv_mem_type = 0;

        if (mvp_enable_device) {
            if (sendbuf != MPI_IN_PLACE) {
                send_mem_type = is_device_buffer(sendbuf);
            }
            recv_mem_type = is_device_buffer(recvbuf);
        }

        comm_size = comm_ptr->local_size;

        MPIR_Datatype_get_extent_macro(recvtype, recvtype_extent);
        MPIR_Datatype_get_extent_macro(sendtype, sendtype_extent);
        if (sendbuf != MPI_IN_PLACE) {
            snbytes = sendtype_extent * sendcount;
        }
        nbytes = recvtype_extent * recvcount;

        /*Handling Non-contig datatypes*/
        if (mvp_enable_device && (send_mem_type || recv_mem_type) &&
            (nbytes < mvp_device_stage_block_size &&
             snbytes < mvp_device_stage_block_size)) {
            device_coll_pack((void **)&sendbuf, &sendcount, &sendtype, &recvbuf,
                             &recvcount, &recvtype, 0, comm_size, comm_size);

            MPIR_Datatype_get_extent_macro(recvtype, recvtype_extent);
            MPIR_Datatype_get_extent_macro(sendtype, sendtype_extent);
            if (sendbuf != MPI_IN_PLACE) {
                snbytes = sendtype_extent * sendcount;
            }
            nbytes = recvtype_extent * recvcount;
        }

        if (mvp_enable_device && mvp_device_alltoall_dynamic && send_mem_type &&
            recv_mem_type && nbytes <= mvp_device_stage_block_size &&
            snbytes <= mvp_device_stage_block_size &&
            nbytes * comm_size > mvp_device_stage_block_size) {
            mpi_errno = MPIR_Alltoall_CUDA_intra_MVP(
                sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                comm_ptr, errflag);
            MPIR_ERR_CHECK(mpi_errno);
            goto fn_exit;
        } else if (mvp_enable_device && mvp_device_coll_use_stage &&
                   (send_mem_type || recv_mem_type) &&
                   nbytes <= mvp_device_alltoall_stage_limit) {
            if (sendbuf != MPI_IN_PLACE) {
                mpi_errno = device_stage_alloc(
                    (void **)&sendbuf, sendcount * sendtype_extent * comm_size,
                    &recvbuf, recvcount * recvtype_extent * comm_size,
                    send_mem_type, recv_mem_type, 0);
            } else {
                mpi_errno = device_stage_alloc(
                    (void **)&sendbuf, recvcount * recvtype_extent * comm_size,
                    &recvbuf, recvcount * recvtype_extent * comm_size,
                    send_mem_type, recv_mem_type, 0);
            }
            MPIR_ERR_CHECK(mpi_errno);
        }
#endif /*#ifdef _ENABLE_CUDA_*/
        if (!MVP_USE_OLD_ALLTOALL) {
                mpi_errno = MPIR_Alltoall_index_tuned_intra_MVP(
                    sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                    comm_ptr, errflag);
        } else {
            mpi_errno =
                MPIR_Alltoall_intra_MVP(sendbuf, sendcount, sendtype, recvbuf,
                                        recvcount, recvtype, comm_ptr, errflag);
        }

        MPIR_ERR_CHECK(mpi_errno);

#ifdef _ENABLE_CUDA_
        if (mvp_enable_device && mvp_device_coll_use_stage &&
            (send_mem_type || recv_mem_type) &&
            nbytes <= mvp_device_alltoall_stage_limit) {
            device_stage_free((void **)&sendbuf, &recvbuf,
                              recvcount * recvtype_extent * comm_size,
                              send_mem_type, recv_mem_type);
        }

#endif /*#ifdef _ENABLE_CUDA_*/

    fn_exit:
#ifdef _ENABLE_CUDA_
        if (mvp_enable_device && (send_mem_type || recv_mem_type)) {
            device_coll_unpack(&recvcount, comm_size);
        }
#endif
        return mpi_errno;
    fn_fail:
        goto fn_exit;
    }
