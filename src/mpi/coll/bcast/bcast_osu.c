/* -*- Mode: C; c-basic-offset:4 ; -*- */
/* Copyright (c) 2001-2022, The Ohio State University. All rights
 * reserved.
 *
 * This file is part of the MVAPICH2 software package developed by the
 * team members of The Ohio State University's Network-Based Computing
 * Laboratory (NBCL), headed by Professor Dhabaleswar K. (DK) Panda.
 *
 * For detailed copyright and licensing information, please refer to the
 * copyright file COPYRIGHT in the top level MVAPICH2 directory.
 */
/*
 *
 *  (C) 2001 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

#include "mpiimpl.h"
#include <unistd.h>
#include "mv2_coll_shmem.h"
#include <unistd.h>
#include "mv2_common_tuning.h"
#include "bcast_tuning.h"
#if defined(_MCST_SUPPORT_)
#include "ibv_mcast.h"
#endif

/*
=== BEGIN_MPI_T_MV2_CVAR_INFO_BLOCK ===

cvars:
    - name        : MV2_BCAST_TWO_LEVEL_SYSTEM_SIZE
      category    : COLLECTIVE
      type        : int
      default     : 64
      class       : none
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : >-
        TODO-DESC

    - name        : MV2_KNOMIAL_2LEVEL_BCAST_MESSAGE_SIZE_THRESHOLD
      category    : COLLECTIVE
      type        : int
      default     : 2048
      class       : none
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : >-
        TODO-DESC

    - name        : MV2_KNOMIAL_2LEVEL_BCAST_SYSTEM_SIZE_THRESHOLD
      category    : COLLECTIVE
      type        : int
      default     : 64
      class       : none
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : >-
        TODO-DESC

    - name        : MV2_USE_BCAST_SHORT_MSG
      category    : COLLECTIVE
      type        : int
      default     : -1
      class       : none
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : >-
        TODO-DESC

    - name        : MV2_USE_KNOMIAL_2LEVEL_BCAST
      category    : COLLECTIVE
      type        : boolean
      default     : 1
      class       : none
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : >-
        TODO-DESC

    - name        : MV2_USE_KNOMIAL_INTER_LEADER_BCAST
      category    : COLLECTIVE
      type        : boolean
      default     : 1
      class       : none
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : >-
        TODO-DESC

    - name        : MV2_USE_SHMEM_BCAST
      category    : COLLECTIVE
      type        : boolean
      default     : 1
      class       : none
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : >-
        This parameter can be used to turn off shared memory based
        MPI_Bcast for OFA-IB-CH3 over IBA by setting this to 0.

=== END_MPI_T_MV2_CVAR_INFO_BLOCK ===
*/

/* A binomial tree broadcast algorithm.  Good for short messages, 
   Cost = lgp.alpha + n.lgp.beta */

int (*MV2_Bcast_function) (void *buffer, int count, MPI_Datatype datatype,
                           int root, MPIR_Comm * comm_ptr, MPIR_Errflag_t *errflag) = NULL;

int (*MV2_Bcast_intra_node_function) (void *buffer, int count, MPI_Datatype datatype,
                                      int root, MPIR_Comm * comm_ptr,
                                      MPIR_Errflag_t *errflag) = NULL;

static int MPIR_Bcast_tune_inter_node_helper_MV2(void *buffer,
                                                 int count,
                                                 MPI_Datatype datatype,
                                                 int root,
                                                 MPIR_Comm * comm_ptr, MPIR_Errflag_t *errflag)
{
    int rank;
    int mpi_errno = MPI_SUCCESS;
    int mpi_errno_ret = MPI_SUCCESS;
    MPI_Aint type_size; 
    intptr_t nbytes=0;
    MPI_Comm shmem_comm, leader_comm;
    MPIR_Comm *shmem_commptr = NULL, *leader_commptr = NULL;
    int local_rank, local_size, global_rank = -1;
    int leader_root, leader_of_root;

    rank = comm_ptr->rank;

    shmem_comm = comm_ptr->dev.ch.shmem_comm;
    MPIR_Comm_get_ptr(shmem_comm, shmem_commptr);
    local_rank = shmem_commptr->rank;
    local_size = shmem_commptr->local_size;

    leader_comm = comm_ptr->dev.ch.leader_comm;
    MPIR_Comm_get_ptr(leader_comm, leader_commptr);

    if ((local_rank == 0) && (local_size > 1)) {
        global_rank = leader_commptr->rank;
    }

    leader_of_root = comm_ptr->dev.ch.leader_map[root];
    leader_root = comm_ptr->dev.ch.leader_rank[leader_of_root];
    MPIR_Datatype_get_size_macro(datatype, type_size);
    nbytes = (intptr_t) (count) * (type_size);

#ifdef CHANNEL_MRAIL_GEN2
    if(&MPIR_Pipelined_Bcast_Zcpy_MV2 == MV2_Bcast_function) { 
       /* We should not be reaching here, with bcast_fn set to the 
        * zcpy function. The bcast-zcpy runtime variable has been disabled. 
        * Just set MV2_Bcast_function to something else to handle this corner
        * case */
        MV2_Bcast_function = &MPIR_Pipelined_Bcast_MV2; 
    } 
#endif

    if (local_size > 1) {
        if ((local_rank == 0) && (root != rank) && (leader_root == global_rank)) {
            MPIR_PVAR_INC(bcast, tune_inter_node_helper, recv, count, datatype);
            mpi_errno = MPIC_Recv(buffer, count, datatype, root,
                                     MPIR_BCAST_TAG, comm_ptr, MPI_STATUS_IGNORE, errflag);
            if (mpi_errno) {
                /* for communication errors, just record the error but continue */
                *errflag = MPIR_ERR_GET_CLASS(mpi_errno);
                MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
                MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
            }
        }
        if ((local_rank != 0) && (root == rank)) {
            MPIR_PVAR_INC(bcast, tune_inter_node_helper, send, count, datatype);
            mpi_errno = MPIC_Send(buffer, count, datatype,
                                     leader_of_root, MPIR_BCAST_TAG, comm_ptr, errflag);
            if (mpi_errno) {
                /* for communication errors, just record the error but continue */
                *errflag = MPIR_ERR_GET_CLASS(mpi_errno);
                MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
                MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
            }
        }
    }
#if defined(_MCST_SUPPORT_)
    if (MV2_SELECT_MCAST_BASED_BCAST(comm_ptr, nbytes)) {
        mpi_errno = MPIR_Mcast_inter_node_MV2(buffer, count, datatype, root, comm_ptr,
                                              errflag);
        if (mpi_errno == MPI_SUCCESS) {
            goto fn_exit;
        } else {
            goto fn_fail;
        }
    }
#endif

    if (local_rank == 0) {
        leader_comm = comm_ptr->dev.ch.leader_comm;
        root = leader_root;
        MPIR_Comm_get_ptr(leader_comm, leader_commptr);
        rank = leader_commptr->rank;
    }

    if (MV2_Bcast_function == &MPIR_Pipelined_Bcast_MV2) {
        mpi_errno = MPIR_Pipelined_Bcast_MV2(buffer, count, datatype,
                                             root, comm_ptr, errflag);
        MPIR_ERR_CHECK(mpi_errno);
    } else if (MV2_Bcast_function == &MPIR_Bcast_scatter_ring_allgather_shm_MV2) {
        mpi_errno = MPIR_Bcast_scatter_ring_allgather_shm_MV2(buffer, count,
                                                              datatype, leader_root,
                                                              comm_ptr,
                                                              errflag);
        MPIR_ERR_CHECK(mpi_errno);
    } else {
        if (local_rank == 0) {
            if (MV2_Bcast_function == &MPIR_Knomial_Bcast_inter_node_wrapper_MV2) {
                mpi_errno = MPIR_Knomial_Bcast_inter_node_wrapper_MV2(buffer, count,
                                                              datatype, root,
                                                              comm_ptr, errflag);
            } else {
                mpi_errno = MV2_Bcast_function(buffer, count, datatype,
                                               root, leader_commptr, errflag);
            }
            MPIR_ERR_CHECK(mpi_errno);
        }
    }

  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

static int MPIR_Bcast_inter_node_helper_MV2(void *buffer,
                                            int count,
                                            MPI_Datatype datatype,
                                            int root,
                                            MPIR_Comm * comm_ptr, MPIR_Errflag_t *errflag)
{
    int rank;
    int mpi_errno = MPI_SUCCESS;
    int mpi_errno_ret = MPI_SUCCESS;
    MPI_Aint type_size; 
    intptr_t nbytes=0;
    MPI_Comm shmem_comm, leader_comm;
    MPIR_Comm *shmem_commptr = NULL, *leader_commptr = NULL;
    int local_rank, local_size, global_rank = -1;
    int leader_root, leader_of_root;

    rank = comm_ptr->rank;

    shmem_comm = comm_ptr->dev.ch.shmem_comm;
    MPIR_Comm_get_ptr(shmem_comm, shmem_commptr);
    local_rank = shmem_commptr->rank;
    local_size = shmem_commptr->local_size;

    leader_comm = comm_ptr->dev.ch.leader_comm;
    MPIR_Comm_get_ptr(leader_comm, leader_commptr);

    if ((local_rank == 0) && (local_size > 1)) {
        global_rank = leader_commptr->rank;
    }

    leader_of_root = comm_ptr->dev.ch.leader_map[root];
    leader_root = comm_ptr->dev.ch.leader_rank[leader_of_root];
    MPIR_Datatype_get_size_macro(datatype, type_size);
    nbytes = (intptr_t) (count) * (type_size);

    if (local_size > 1) {
        if ((local_rank == 0) && (root != rank) && (leader_root == global_rank)) {
            MPIR_PVAR_INC(bcast, inter_node_helper, recv, count, datatype);
            mpi_errno = MPIC_Recv(buffer, count, datatype, root,
                                     MPIR_BCAST_TAG, comm_ptr, MPI_STATUS_IGNORE, errflag);
            if (mpi_errno) {
                /* for communication errors, just record the error but continue */
                *errflag = MPIR_ERR_GET_CLASS(mpi_errno);
                MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
                MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
            }
        }
        if ((local_rank != 0) && (root == rank)) {
            MPIR_PVAR_INC(bcast, inter_node_helper, send, count, datatype);
            mpi_errno = MPIC_Send(buffer, count, datatype,
                                     leader_of_root, MPIR_BCAST_TAG, comm_ptr, errflag);
            if (mpi_errno) {
                /* for communication errors, just record the error but continue */
                *errflag = MPIR_ERR_GET_CLASS(mpi_errno);
                MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
                MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
            }
        }
    }
#if defined(_MCST_SUPPORT_)
    if (MV2_SELECT_MCAST_BASED_BCAST(comm_ptr, nbytes)) {
        mpi_errno = MPIR_Mcast_inter_node_MV2(buffer, count, datatype,
                                              root, comm_ptr, errflag);
        if (mpi_errno == MPI_SUCCESS) {
            goto fn_exit;
        }
    }
#endif

    if (mv2_use_pipelined_bcast == 1 && nbytes > bcast_segment_size) {
        mpi_errno = MPIR_Pipelined_Bcast_MV2(buffer, count, datatype,
                                             leader_root, comm_ptr, errflag);
        MPIR_ERR_CHECK(mpi_errno);
    } else {
        if (local_rank == 0) {
            leader_comm = comm_ptr->dev.ch.leader_comm;
            root = leader_root;
            MPIR_Comm_get_ptr(leader_comm, leader_commptr);
            rank = leader_commptr->rank;
        }

        if (mv2_knomial_inter_leader_bcast == 1
            && nbytes <= mv2_knomial_inter_leader_threshold) {
            if (local_rank == 0) {
                mpi_errno = MPIR_Knomial_Bcast_inter_node_wrapper_MV2(buffer, count,
                                                              datatype, root,
                                                              comm_ptr, errflag);
            }
        } else {
            if (mv2_scatter_ring_inter_leader_bcast) {
                if (mv2_bcast_scatter_ring_overlap == 1) {
                    if (nbytes <= mv2_bcast_scatter_ring_overlap_msg_upperbound &&
                        comm_ptr->local_size >=
                        mv2_bcast_scatter_ring_overlap_cores_lowerbound) {

                        mpi_errno = MPIR_Bcast_scatter_ring_allgather_shm_MV2(buffer,
                                                                              count,
                                                                              datatype,
                                                                              leader_root,
                                                                              comm_ptr,
                                                                              errflag);
                    } else if (local_rank == 0) {

                        mpi_errno = MPIR_Bcast_scatter_ring_allgather_MV2(buffer, count,
                                                                          datatype,
                                                                          root,
                                                                          leader_commptr,
                                                                          errflag);
                    }
                } else if (local_rank == 0) {
                    mpi_errno = MPIR_Bcast_scatter_ring_allgather_MV2(buffer, count,
                                                                      datatype,
                                                                      root,
                                                                      leader_commptr,
                                                                      errflag);
                }

            } else if (local_rank == 0) {

                if (mv2_scatter_rd_inter_leader_bcast) {
                    mpi_errno =
                        MPIR_Bcast_scatter_doubling_allgather_MV2(buffer, count,
                                                                  datatype, root,
                                                                  leader_commptr,
                                                                  errflag);
                } else if (mv2_knomial_inter_leader_bcast) {
                    mpi_errno = MPIR_Knomial_Bcast_inter_node_wrapper_MV2(buffer, count,
                                                                  datatype, root,
                                                                  comm_ptr, errflag);
                } else {
                    mpi_errno = MPIR_Bcast_binomial_MV2(buffer, count,
                                                        datatype, root,
                                                        leader_commptr, errflag);
                }
                MPIR_ERR_CHECK(mpi_errno);
            }
        }
    }

  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}


int MPIR_Bcast_intra_MV2(void *buffer,
                         int count,
                         MPI_Datatype datatype,
                         int root, MPIR_Comm * comm_ptr, MPIR_Errflag_t *errflag)
{
    int mpi_errno = MPI_SUCCESS;
    int mpi_errno_ret = MPI_SUCCESS;
    int comm_size, rank;
    int two_level_bcast = 1;
    intptr_t nbytes = 0; 
    int is_homogeneous, is_contig;
    MPI_Aint type_size, position;
    void *tmp_buf = NULL;
    MPIR_Comm *shmem_commptr = NULL;
    MPI_Comm shmem_comm;
    MPIR_Datatype *dtp;

    MPIR_CHKLMEM_DECL(1);

    if (count == 0)
        goto fn_exit;

    comm_size = comm_ptr->local_size;
    rank = comm_ptr->rank;

    if (HANDLE_GET_KIND(datatype) == HANDLE_KIND_BUILTIN)
        is_contig = 1;
    else {
        MPIR_Datatype_get_ptr(datatype, dtp);
        is_contig = dtp->is_contig;
    }

    is_homogeneous = 1;
#ifdef MPID_HAS_HETERO
    if (comm_ptr->is_hetero)
        is_homogeneous = 0;
#endif

    /* MPI_Type_size() might not give the accurate size of the packed
     * datatype for heterogeneous systems (because of padding, encoding,
     * etc). On the other hand, MPI_Pack_size() can become very
     * expensive, depending on the implementation, especially for
     * heterogeneous systems. We want to use MPI_Type_size() wherever
     * possible, and MPI_Pack_size() in other places.
     */
    if (is_homogeneous) {
        MPIR_Datatype_get_size_macro(datatype, type_size);
    } else {
        MPIR_Pack_size_impl(1, datatype, &type_size);
    }
    nbytes = (intptr_t) (count) * (type_size);
    if (comm_size <= mv2_bcast_two_level_system_size) {
        if (nbytes > mv2_bcast_short_msg && nbytes < mv2_bcast_large_msg) {
            two_level_bcast = 1;
        } else {
            two_level_bcast = 0;
        }
    }

    if (comm_ptr->dev.ch.shmem_coll_ok == 1
        && mv2_enable_shmem_bcast == 1
        && (two_level_bcast == 1
#if defined(_MCST_SUPPORT_)
            || MV2_SELECT_MCAST_BASED_BCAST(comm_ptr, nbytes)
#endif
        )) {

        if (!is_contig || !is_homogeneous) {
            MPIR_CHKLMEM_MALLOC(tmp_buf, void *, nbytes, mpi_errno, "tmp_buf", 
                                MPL_MEM_COLL);

            /* TODO: Pipeline the packing and communication */
            position = 0;
            if (rank == root) {
                mpi_errno =
                    MPIR_Typerep_pack(buffer, count, datatype, position, 
                                        tmp_buf, nbytes, &position);
                MPIR_ERR_CHECK(mpi_errno);
            }
        }

        shmem_comm = comm_ptr->dev.ch.shmem_comm;
        MPIR_Comm_get_ptr(shmem_comm, shmem_commptr);
        if (!is_contig || !is_homogeneous) {
            mpi_errno =
                MPIR_Bcast_inter_node_helper_MV2(tmp_buf, nbytes, MPI_BYTE,
                                                 root, comm_ptr, errflag);
        } else {
            mpi_errno =
                MPIR_Bcast_inter_node_helper_MV2(buffer, count, datatype, root,
                                                 comm_ptr, errflag);
        }
        if (mpi_errno) {
            /* for communication errors, just record the error but continue */
            *errflag = MPIR_ERR_GET_CLASS(mpi_errno);
            MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
            MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
        }

        /* We are now done with the inter-node phase */
        if (comm_ptr->dev.ch.intra_node_done == 0) {
            if (nbytes <= mv2_knomial_intra_node_threshold) {
                if (!is_contig || !is_homogeneous) {
                    mpi_errno = MPIR_Shmem_Bcast_MV2(tmp_buf, nbytes, MPI_BYTE,
                                                     root, shmem_commptr, errflag);
                } else {
                    mpi_errno = MPIR_Shmem_Bcast_MV2(buffer, count, datatype,
                                                     root, shmem_commptr, errflag);
                }
            } else {
                if (!is_contig || !is_homogeneous) {
                    mpi_errno =
                        MPIR_Knomial_Bcast_intra_node_MV2(tmp_buf, nbytes,
                                                          MPI_BYTE,
                                                          INTRA_NODE_ROOT,
                                                          shmem_commptr, errflag);
                } else {
                    mpi_errno =
                        MPIR_Knomial_Bcast_intra_node_MV2(buffer, count,
                                                          datatype,
                                                          INTRA_NODE_ROOT,
                                                          shmem_commptr, errflag);
                }
            }
        }
        if (mpi_errno) {
            /* for communication errors, just record the error but continue */
            *errflag = MPIR_ERR_GET_CLASS(mpi_errno);
            MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
            MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
        }
        if (!is_contig || !is_homogeneous) {
            /* Finishing up... */
            if (rank != root) {
                position = 0;
                mpi_errno = MPIR_Typerep_unpack(tmp_buf, nbytes, buffer, count,
                                                datatype, position, &position);
            }
        }
    } else {
        if (nbytes <= mv2_bcast_short_msg) {
            mpi_errno = MPIR_Bcast_binomial_MV2(buffer, count, datatype, root,
                                                comm_ptr, errflag);
        } else {
            if (mv2_scatter_rd_inter_leader_bcast) {
                mpi_errno = MPIR_Bcast_scatter_ring_allgather_MV2(buffer, count,
                                                                  datatype,
                                                                  root,
                                                                  comm_ptr, errflag);
            } else {
                mpi_errno =
                    MPIR_Bcast_scatter_doubling_allgather_MV2(buffer, count,
                                                              datatype, root,
                                                              comm_ptr, errflag);
            }
        }
        if (mpi_errno) {
            /* for communication errors, just record the error but continue */
            *errflag = MPIR_ERR_GET_CLASS(mpi_errno);
            MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
            MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
        }
    }

  fn_exit:
    MPIR_CHKLMEM_FREEALL();
    if (mpi_errno_ret)
        mpi_errno = mpi_errno_ret;
    else if (*errflag)
        MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**coll_fail");
    return mpi_errno;

  fn_fail:
    goto fn_exit;

}


int MPIR_Bcast_index_tuned_intra_MV2(void *buffer,
                              int count,
                              MPI_Datatype datatype,
                              int root, MPIR_Comm * comm_ptr, MPIR_Errflag_t *errflag)
{
    int mpi_errno = MPI_SUCCESS;
    int mpi_errno_ret = MPI_SUCCESS;
    int comm_size, rank;
    int two_level_bcast = 1;
    intptr_t nbytes = 0;
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
    int is_homogeneous, is_contig;
    MPI_Aint type_size, position;
    void *tmp_buf = NULL;
    MPIR_Comm *shmem_commptr = NULL;
    MPI_Comm shmem_comm;
    MPIR_Datatype *dtp;

    MPIR_CHKLMEM_DECL(1);

    if (count == 0)
        goto fn_exit;

    comm_size = comm_ptr->local_size;
    rank = comm_ptr->rank;

    if (HANDLE_GET_KIND(datatype) == HANDLE_KIND_BUILTIN)
        is_contig = 1;
    else {
        MPIR_Datatype_get_ptr(datatype, dtp);
        is_contig = dtp->is_contig;
    } 

    is_homogeneous = 1;
#ifdef MPID_HAS_HETERO
    if (comm_ptr->is_hetero)
        is_homogeneous = 0;
#endif

    /* MPI_Type_size() might not give the accurate size of the packed
     * datatype for heterogeneous systems (because of padding, encoding,
     * etc). On the other hand, MPI_Pack_size() can become very
     * expensive, depending on the implementation, especially for
     * heterogeneous systems. We want to use MPI_Type_size() wherever
     * possible, and MPI_Pack_size() in other places.
     */
    if (is_homogeneous) {
        MPIR_Datatype_get_size_macro(datatype, type_size);
    } else {
        MPIR_Pack_size_impl(1, datatype, &type_size);
    }
    nbytes = (intptr_t) (count) * (type_size);
    
    /* check if safe to use partial subscription mode */
    if (comm_ptr->dev.ch.shmem_coll_ok == 1 && comm_ptr->dev.ch.is_uniform) {
    
        shmem_comm = comm_ptr->dev.ch.shmem_comm;
        MPIR_Comm_get_ptr(shmem_comm, shmem_commptr);
        local_size = shmem_commptr->local_size;
        if (mv2_bcast_indexed_table_ppn_conf[0] == -1) {
            // Indicating user defined tuning
            conf_index = 0;
            goto conf_check_end;
        }
        if (nbytes <= mv2_topo_aware_bcast_max_msg && nbytes >=
                mv2_topo_aware_bcast_min_msg && mv2_enable_skip_tuning_table_search
                && nbytes <= mv2_coll_skip_table_threshold && mv2_enable_topo_aware_collectives
                && mv2_use_topo_aware_bcast && comm_ptr->dev.ch.topo_coll_ok == 1
                && local_size >= mv2_topo_aware_bcast_ppn_threshold
                && mv2_topo_aware_bcast_node_threshold <= comm_ptr->dev.ch.leader_group_size) {
            MV2_Bcast_function = &MPIR_Bcast_topo_aware_hierarchical_MV2;
            goto skip_tuning_tables;
        }
        if (likely(mv2_enable_shmem_bcast &&
                   mv2_enable_skip_tuning_table_search &&
                   (nbytes <= mv2_coll_skip_table_threshold))) {
            /* for small messages, force shmem + zcpy pipeline */
#if defined CHANNEL_MRAIL_GEN2
            if (mv2_enable_zcpy_bcast == 1) {
                MV2_Bcast_function = &MPIR_Pipelined_Bcast_Zcpy_MV2;
            } else {
                MV2_Bcast_function = &MPIR_Pipelined_Bcast_MV2; 
            }
            MV2_Bcast_intra_node_function = &MPIR_Knomial_Bcast_intra_node_MV2;
#elif defined _MV2_CH4_OVERRIDE_ 
            MV2_Bcast_function = &MPIR_Bcast_binomial_MV2; 
            MV2_Bcast_intra_node_function = &MPIR_Shmem_Bcast_MV2;
#endif
            two_level_bcast = 1;
            zcpy_knomial_factor = 8;
            mv2_inter_node_knomial_factor = 8;
            bcast_segment_size = 8192;
            goto skip_tuning_tables;
        }

        FIND_PPN_INDEX  (bcast, local_size,conf_index, partial_sub_ok)
    }
 
    if (partial_sub_ok != 1) {
        conf_index = mv2_bcast_indexed_num_ppn_conf/2;
    }
        
conf_check_end:

    /* Search for the corresponding system size inside the tuning table */
    /*
     * Comm sizes progress in powers of 2. Therefore comm_size can just be indexed instead
     */
    table_min_comm_size = mv2_bcast_indexed_thresholds_table[conf_index][0].numproc;
    table_max_comm_size =
	mv2_bcast_indexed_thresholds_table[conf_index][mv2_size_bcast_indexed_tuning_table[conf_index] - 1].numproc;
    
    if (comm_size < table_min_comm_size) {
	/* Comm size smaller than smallest configuration in table: use smallest available */
	comm_size_index = 0;
    }
    else if (comm_size > table_max_comm_size) {
	/* Comm size larger than largest configuration in table: use largest available */
	comm_size_index = mv2_size_bcast_indexed_tuning_table[conf_index] - 1;
    }
    else {
	/* Comm size in between smallest and largest configuration: find closest match */
    lp2ltn_min = pow(2, (int)log2(table_min_comm_size));
	if (comm_ptr->dev.ch.is_pof2) {
	    comm_size_index = log2( comm_size / lp2ltn_min );
	}
	else {
	    lp2ltn = pow(2, (int)log2(comm_size));
        comm_size_index = (lp2ltn < lp2ltn_min) ? 0 : log2( lp2ltn / lp2ltn_min );
	}
    }

    last_inter = mv2_bcast_indexed_thresholds_table[conf_index][comm_size_index].size_inter_table - 1;
    table_min_inter_size = mv2_bcast_indexed_thresholds_table[conf_index][comm_size_index].inter_leader[0].msg_sz;
    table_max_inter_size = mv2_bcast_indexed_thresholds_table[conf_index][comm_size_index].inter_leader[last_inter].msg_sz;
    last_intra = mv2_bcast_indexed_thresholds_table[conf_index][comm_size_index].size_intra_table - 1;
    table_min_intra_size = mv2_bcast_indexed_thresholds_table[conf_index][comm_size_index].intra_node[0].msg_sz;
    table_max_intra_size = mv2_bcast_indexed_thresholds_table[conf_index][comm_size_index].intra_node[last_intra].msg_sz;
    
    if (nbytes < table_min_inter_size) {
	/* Msg size smaller than smallest configuration in table: use smallest available */
	inter_node_algo_index = 0;
    }
    else if (nbytes > table_max_inter_size) {
	/* Msg size larger than largest configuration in table: use largest available */
	inter_node_algo_index = last_inter;
    }
    else {
	/* Msg size in between smallest and largest configuration: find closest match */
	if (pow(2, (int)log2(nbytes)) == nbytes) {
	    inter_node_algo_index = log2( nbytes / table_min_inter_size );
	}
	else {
	    lp2ltn = pow(2, (int)log2(nbytes));
	    inter_node_algo_index = (lp2ltn < table_min_inter_size) ? 0 : log2( lp2ltn / table_min_inter_size );
	}
    }
    
    if (nbytes < table_min_intra_size) {
	/* Msg size smaller than smallest configuration in table: use smallest available */
	intra_node_algo_index = 0;
    }
    else if (nbytes > table_max_intra_size) {
	/* Msg size larger than largest configuration in table: use largest available */
	intra_node_algo_index = last_intra;
    }
    else {
	/* Msg size in between smallest and largest configuration: find closest match */
	if (pow(2, (int)log2(nbytes)) == nbytes) {
	    intra_node_algo_index = log2(nbytes / table_min_intra_size );
	}
	else {
	    lp2ltn = pow(2, (int)log2(nbytes));
	    intra_node_algo_index = (lp2ltn < table_min_intra_size) ? 0 : log2(lp2ltn / table_min_intra_size );
	}
    }
        
    MV2_Bcast_function =
        mv2_bcast_indexed_thresholds_table[conf_index][comm_size_index].inter_leader[inter_node_algo_index].
        MV2_pt_Bcast_function;

    MV2_Bcast_intra_node_function =
        mv2_bcast_indexed_thresholds_table[conf_index][comm_size_index].
        intra_node[intra_node_algo_index].MV2_pt_Bcast_function;

    if (mv2_user_bcast_intra == NULL && MV2_Bcast_intra_node_function == &MPIR_Knomial_Bcast_intra_node_MV2
        && nbytes < mv2_knomial_intra_node_threshold && comm_ptr->dev.ch.shmem_coll_ok == 1) {
            MV2_Bcast_intra_node_function = &MPIR_Shmem_Bcast_MV2;
    }

    if (mv2_bcast_indexed_thresholds_table[conf_index][comm_size_index].inter_leader[inter_node_algo_index].
        zcpy_pipelined_knomial_factor > 0) {
        zcpy_knomial_factor = 
            mv2_bcast_indexed_thresholds_table[conf_index][comm_size_index].inter_leader[inter_node_algo_index].
            zcpy_pipelined_knomial_factor;
    } else {
	zcpy_knomial_factor = MV2_DEFAULT_ZCPY_KNOMIAL_FACTOR;
    }

    if (mv2_pipelined_zcpy_knomial_factor != -1) {
        zcpy_knomial_factor = mv2_pipelined_zcpy_knomial_factor;
    }

    /* If we use previous shmem scheme, fall back to previous threshold for intra-node*/
    if (!mv2_use_slot_shmem_coll || !mv2_use_slot_shmem_bcast){
        /* not depending on intra node tuning table with old shmem design */
        if (nbytes <= mv2_knomial_intra_node_threshold){
            MV2_Bcast_intra_node_function = &MPIR_Shmem_Bcast_MV2;
        } else {
            MV2_Bcast_intra_node_function = &MPIR_Knomial_Bcast_intra_node_MV2;
        }
    } else if(MV2_Bcast_intra_node_function == NULL) {
        /* if tuning table do not have any intra selection, set func pointer to
        ** default one for mcast intra node */
        MV2_Bcast_intra_node_function = &MPIR_Shmem_Bcast_MV2;
    }

    /* Set value of pipeline segment size */
    bcast_segment_size = mv2_bcast_indexed_thresholds_table[conf_index][comm_size_index].bcast_segment_size;
    
    /* Set value of inter node knomial factor */
    if(mv2_bcast_indexed_thresholds_table[conf_index][comm_size_index].inter_node_knomial_factor > 0) {
        mv2_inter_node_knomial_factor = mv2_bcast_indexed_thresholds_table[conf_index][comm_size_index].inter_node_knomial_factor;
    } else {
	mv2_inter_node_knomial_factor = MV2_DEFAULT_INTER_NODE_KNOMIAL_FACTOR;
    }

    /* Set value of intra node knomial factor */
    if(mv2_bcast_indexed_thresholds_table[conf_index][comm_size_index].intra_node_knomial_factor > 0) {
        mv2_intra_node_knomial_factor = mv2_bcast_indexed_thresholds_table[conf_index][comm_size_index].intra_node_knomial_factor;
    } else {
	mv2_intra_node_knomial_factor = MV2_DEFAULT_INTRA_NODE_KNOMIAL_FACTOR;
    }

    /* Check if we will use a two level algorithm or not */
    two_level_bcast =
        mv2_bcast_indexed_thresholds_table[conf_index][comm_size_index].is_two_level_bcast[inter_node_algo_index];

    if (MV2_Bcast_function == &MPIR_Knomial_Bcast_inter_node_wrapper_MV2 &&  
            two_level_bcast != 1) {
        /* knomial inter node wrapper algorithm relies on leader_comm, therefore, it
         * most be called only on leader_comm */
        MV2_Bcast_function = &MPIR_Bcast_binomial_MV2;
    }

skip_tuning_tables:
#if defined CHANNEL_MRAIL_GEN2
    if (mv2_bcast_indexed_table_ppn_conf[0] != -1 && (mv2_enable_zcpy_bcast == 0 
#if defined(_MCST_SUPPORT_)
        || MV2_SELECT_MCAST_BASED_BCAST(comm_ptr, nbytes) 
#endif
        )) {
        MV2_Bcast_intra_node_function = &MPIR_Shmem_Bcast_MV2;
        MV2_Bcast_function = &MPIR_Knomial_Bcast_inter_node_wrapper_MV2;
        two_level_bcast = 1;
    }
#endif
                
    if (comm_ptr->dev.ch.shmem_coll_ok != 1) {
        if(nbytes < MPICH_LARGE_MSG_COLLECTIVE_SIZE) { 
            mpi_errno = MPIR_Bcast_allcomm_auto(buffer, count, datatype, root, 
                        comm_ptr, errflag);
        } else { 
            mpi_errno = MPIR_Bcast_scatter_ring_allgather_MV2(buffer, count, 
                            datatype, root, 
                            comm_ptr, errflag);
        } 
    } else if (mv2_enable_shmem_bcast == 1 && two_level_bcast) {
        if (!is_contig || !is_homogeneous) {
            MPIR_CHKLMEM_MALLOC(tmp_buf, void *, nbytes, mpi_errno, "tmp_buf", 
                                MPL_MEM_COLL);

            /* TODO: Pipeline the packing and communication */
            position = 0;
            if (rank == root) {
                mpi_errno =
                    MPIR_Typerep_pack(buffer, count, datatype, position, 
                                        tmp_buf, nbytes, &position);
                MPIR_ERR_CHECK(mpi_errno);
            }
        }
#ifdef _OSU_MVAPICH_
#ifdef CHANNEL_MRAIL_GEN2
        if ((mv2_enable_zcpy_bcast == 1) &&
              (&MPIR_Pipelined_Bcast_Zcpy_MV2 == MV2_Bcast_function)) {  
            if (!is_contig || !is_homogeneous) {
                mpi_errno = MPIR_Pipelined_Bcast_Zcpy_MV2(tmp_buf, nbytes, MPI_BYTE,
                                                 root, comm_ptr, errflag);
            } else { 
                mpi_errno = MPIR_Pipelined_Bcast_Zcpy_MV2(buffer, count, datatype,
                                                 root, comm_ptr, errflag);
            } 
        } else if (&MPIR_Bcast_topo_aware_hierarchical_MV2 == MV2_Bcast_function) {
            if (!is_contig || !is_homogeneous) {
                mpi_errno = MPIR_Bcast_topo_aware_hierarchical_MV2(tmp_buf, nbytes, MPI_BYTE,
                                                 root, comm_ptr, errflag);
            } else {
                mpi_errno = MPIR_Bcast_topo_aware_hierarchical_MV2(buffer, count, datatype,
                                                 root, comm_ptr, errflag);
            }
        } else 
#endif
#endif /* _OSU_MVAPICH_ */
        { 
            shmem_comm = comm_ptr->dev.ch.shmem_comm;
            MPIR_Comm_get_ptr(shmem_comm, shmem_commptr);
            if (!is_contig || !is_homogeneous) {
                mpi_errno =
                    MPIR_Bcast_tune_inter_node_helper_MV2(tmp_buf, nbytes, MPI_BYTE,
                                                          root, comm_ptr, errflag);
            } else {
                mpi_errno =
                    MPIR_Bcast_tune_inter_node_helper_MV2(buffer, count, datatype, root,
                                                          comm_ptr, errflag);
            }
            if (mpi_errno) {
                /* for communication errors, just record the error but continue */
                *errflag = MPIR_ERR_GET_CLASS(mpi_errno);
                MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
                MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
            }

            /* We are now done with the inter-node phase */
            if (comm_ptr->dev.ch.intra_node_done == 0) {

                if (!is_contig || !is_homogeneous) {
                    mpi_errno = MV2_Bcast_intra_node_function(tmp_buf, nbytes,
                                                              MPI_BYTE, INTRA_NODE_ROOT, shmem_commptr,
                                                              errflag);
                } else {
                    mpi_errno = MV2_Bcast_intra_node_function(buffer, count,
                                                              datatype, INTRA_NODE_ROOT, shmem_commptr,
                                                              errflag);

                }
            }
        } 
        if (mpi_errno) {
            /* for communication errors, just record the error but continue */
            *errflag = MPIR_ERR_GET_CLASS(mpi_errno);
            MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
            MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
        }
        if (!is_contig || !is_homogeneous) {
            /* Finishing up... */
            if (rank != root) {
                position = 0;
                mpi_errno = MPIR_Typerep_unpack(tmp_buf, nbytes, buffer, count,
                                                datatype, position, &position);
            }
        }
    } else {
        /* We use Knomial for intra node */
        MV2_Bcast_intra_node_function = &MPIR_Knomial_Bcast_intra_node_MV2;
        if (mv2_enable_shmem_bcast == 0) {
            /* Fall back to non-tuned version */
            MPIR_Bcast_intra_MV2(buffer, count, datatype, root, comm_ptr, errflag);
        } else {
#ifdef CHANNEL_MRAIL_GEN2
            if ((&MPIR_Pipelined_Bcast_Zcpy_MV2 == MV2_Bcast_function) &&
                (mv2_enable_zcpy_bcast == 0 || !is_contig || !is_homogeneous)) {
                /* We should not be reaching here, with bcast_fn set to the 
                 * zcpy function. The bcast-zcpy runtime variable has been disabled. 
                 * Just set MV2_Bcast_function to something else to handle this corner
                 * case */
                MV2_Bcast_function = &MPIR_Bcast_binomial_MV2; 
            } 
#endif
            mpi_errno = MV2_Bcast_function(buffer, count, datatype, root,
                                           comm_ptr, errflag);

        }
    }

    if (mpi_errno) {
        /* for communication errors, just record the error but continue */
        *errflag = MPIR_ERR_GET_CLASS(mpi_errno);
        MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
        MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
    }

  fn_exit:
    MPIR_CHKLMEM_FREEALL();
    if (mpi_errno_ret)
        mpi_errno = mpi_errno_ret;
    else if (*errflag)
        MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**coll_fail");
    return mpi_errno;

  fn_fail:
    goto fn_exit;

}


int MPIR_Bcast_tune_intra_MV2(void *buffer,
                              int count,
                              MPI_Datatype datatype,
                              int root, MPIR_Comm * comm_ptr, MPIR_Errflag_t *errflag)
{
    int mpi_errno = MPI_SUCCESS;
    int mpi_errno_ret = MPI_SUCCESS;
    int comm_size, rank;
    int two_level_bcast = 1;
    intptr_t nbytes = 0; 
    int range = 0;
    int range_threshold = 0;
    int range_threshold_intra = 0;
    int is_homogeneous, is_contig;
    MPI_Aint type_size, position;
    void *tmp_buf = NULL;
    MPIR_Comm *shmem_commptr = NULL;
    MPI_Comm shmem_comm;
    MPIR_Datatype *dtp;

    MPIR_CHKLMEM_DECL(1);

    if (count == 0)
        goto fn_exit;

    comm_size = comm_ptr->local_size;
    rank = comm_ptr->rank;

    if (HANDLE_GET_KIND(datatype) == HANDLE_KIND_BUILTIN)
        is_contig = 1;
    else {
        MPIR_Datatype_get_ptr(datatype, dtp);
        is_contig = dtp->is_contig;
    }

    is_homogeneous = 1;
#ifdef MPID_HAS_HETERO
    if (comm_ptr->is_hetero)
        is_homogeneous = 0;
#endif

    /* MPI_Type_size() might not give the accurate size of the packed
     * datatype for heterogeneous systems (because of padding, encoding,
     * etc). On the other hand, MPI_Pack_size() can become very
     * expensive, depending on the implementation, especially for
     * heterogeneous systems. We want to use MPI_Type_size() wherever
     * possible, and MPI_Pack_size() in other places.
     */
    if (is_homogeneous) {
        MPIR_Datatype_get_size_macro(datatype, type_size);
    } else {
        MPIR_Pack_size_impl(1, datatype, &type_size);
    }
    nbytes = (intptr_t) (count) * (type_size);

    /* Search for the corresponding system size inside the tuning table */
    while ((range < (mv2_size_bcast_tuning_table - 1)) &&
           (comm_size > mv2_bcast_thresholds_table[range].numproc)) {
        range++;
    }
    /* Search for corresponding inter-leader function */
    while ((range_threshold < (mv2_bcast_thresholds_table[range].size_inter_table - 1))
           && (nbytes >
               mv2_bcast_thresholds_table[range].inter_leader[range_threshold].max)
           && (mv2_bcast_thresholds_table[range].inter_leader[range_threshold].max != -1)) {
        range_threshold++;
    }

    /* Search for corresponding intra-node function */
    while ((range_threshold_intra <
            (mv2_bcast_thresholds_table[range].size_intra_table - 1))
           && (nbytes >
               mv2_bcast_thresholds_table[range].intra_node[range_threshold_intra].max)
           && (mv2_bcast_thresholds_table[range].intra_node[range_threshold_intra].max !=
               -1)) {
        range_threshold_intra++;
    }

    MV2_Bcast_function =
        mv2_bcast_thresholds_table[range].inter_leader[range_threshold].
        MV2_pt_Bcast_function;

    MV2_Bcast_intra_node_function =
        mv2_bcast_thresholds_table[range].
        intra_node[range_threshold_intra].MV2_pt_Bcast_function;

    if (mv2_user_bcast_intra == NULL && 
            MV2_Bcast_intra_node_function == &MPIR_Knomial_Bcast_intra_node_MV2) {
            MV2_Bcast_intra_node_function = &MPIR_Shmem_Bcast_MV2;
    }

    if (mv2_bcast_thresholds_table[range].inter_leader[range_threshold].
        zcpy_pipelined_knomial_factor != -1) {
        zcpy_knomial_factor = 
            mv2_bcast_thresholds_table[range].inter_leader[range_threshold].
            zcpy_pipelined_knomial_factor;
    }

    if (mv2_pipelined_zcpy_knomial_factor != -1) {
        zcpy_knomial_factor = mv2_pipelined_zcpy_knomial_factor;
    }

    /* If we use previous shmem scheme, fall back to previous threshold for intra-node*/
    if (!mv2_use_slot_shmem_coll || !mv2_use_slot_shmem_bcast){
        /* not depending on intra node tuning table with old shmem design */
        if (nbytes <= mv2_knomial_intra_node_threshold){
            MV2_Bcast_intra_node_function = &MPIR_Shmem_Bcast_MV2;
        } else {
            MV2_Bcast_intra_node_function = &MPIR_Knomial_Bcast_intra_node_MV2;
        }
    } else if(MV2_Bcast_intra_node_function == NULL) {
        /* if tuning table do not have any intra selection, set func pointer to
        ** default one for mcast intra node */
        MV2_Bcast_intra_node_function = &MPIR_Shmem_Bcast_MV2;
    }

    /* Set value of pipeline segment size */
    bcast_segment_size = mv2_bcast_thresholds_table[range].bcast_segment_size;
    
    /* Set value of inter node knomial factor */
    mv2_inter_node_knomial_factor = mv2_bcast_thresholds_table[range].inter_node_knomial_factor;

    /* Set value of intra node knomial factor */
    mv2_intra_node_knomial_factor = mv2_bcast_thresholds_table[range].intra_node_knomial_factor;

    /* Check if we will use a two level algorithm or not */
    two_level_bcast =
        mv2_bcast_thresholds_table[range].is_two_level_bcast[range_threshold];
    if (comm_ptr->dev.ch.shmem_coll_ok != 1) {
        if(nbytes < MPICH_LARGE_MSG_COLLECTIVE_SIZE) { 
            mpi_errno = MPIR_Bcast_allcomm_auto(buffer, count, datatype, root, 
                        comm_ptr, errflag);
        } else { 
            mpi_errno = MPIR_Bcast_scatter_ring_allgather_MV2(buffer, count, 
                            datatype, root, 
                            comm_ptr, errflag);
        } 
    } else if (mv2_enable_shmem_bcast == 1 && two_level_bcast == 1) {
        if (!is_contig || !is_homogeneous) {
            MPIR_CHKLMEM_MALLOC(tmp_buf, void *, nbytes, mpi_errno, "tmp_buf", 
                                MPL_MEM_COLL);

            /* TODO: Pipeline the packing and communication */
            position = 0;
            if (rank == root) {
                mpi_errno =
                    MPIR_Typerep_pack(buffer, count, datatype, position, 
                                        tmp_buf, nbytes, &position);
                MPIR_ERR_CHECK(mpi_errno);
            }
        }
#ifdef CHANNEL_MRAIL_GEN2
        if ((mv2_enable_zcpy_bcast == 1) &&
              (&MPIR_Pipelined_Bcast_Zcpy_MV2 == MV2_Bcast_function)) {  
            if (!is_contig || !is_homogeneous) {
                mpi_errno = MPIR_Pipelined_Bcast_Zcpy_MV2(tmp_buf, nbytes, MPI_BYTE,
                                                 root, comm_ptr, errflag);
            } else { 
                mpi_errno = MPIR_Pipelined_Bcast_Zcpy_MV2(buffer, count, datatype,
                                                 root, comm_ptr, errflag);
            } 
        } else 
#endif /* defined(CHANNEL_MRAIL_GEN2) */
        { 
            shmem_comm = comm_ptr->dev.ch.shmem_comm;
            MPIR_Comm_get_ptr(shmem_comm, shmem_commptr);
            if (!is_contig || !is_homogeneous) {
                mpi_errno =
                    MPIR_Bcast_tune_inter_node_helper_MV2(tmp_buf, nbytes, MPI_BYTE,
                                                          root, comm_ptr, errflag);
            } else {
                mpi_errno =
                    MPIR_Bcast_tune_inter_node_helper_MV2(buffer, count, datatype, root,
                                                          comm_ptr, errflag);
            }
            if (mpi_errno) {
                /* for communication errors, just record the error but continue */
                *errflag = MPIR_ERR_GET_CLASS(mpi_errno);
                MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
                MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
            }

            /* We are now done with the inter-node phase */
            if (comm_ptr->dev.ch.intra_node_done == 0) {

                if (!is_contig || !is_homogeneous) {
                    mpi_errno = MV2_Bcast_intra_node_function(tmp_buf, nbytes,
                                                              MPI_BYTE, INTRA_NODE_ROOT, shmem_commptr,
                                                              errflag);
                } else {
                    mpi_errno = MV2_Bcast_intra_node_function(buffer, count,
                                                              datatype, INTRA_NODE_ROOT, shmem_commptr,
                                                              errflag);

                }
            }
        } 
        if (mpi_errno) {
            /* for communication errors, just record the error but continue */
            *errflag = MPIR_ERR_GET_CLASS(mpi_errno);
            MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
            MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
        }
        if (!is_contig || !is_homogeneous) {
            /* Finishing up... */
            if (rank != root) {
                position = 0;
                mpi_errno = MPIR_Typerep_unpack(tmp_buf, nbytes, buffer, count,
                                                datatype, position, &position);
            }
        }
    } else {
        /* We use Knomial for intra node */
        MV2_Bcast_intra_node_function = &MPIR_Knomial_Bcast_intra_node_MV2;
        if (mv2_enable_shmem_bcast == 0) {
            /* Fall back to non-tuned version */
            MPIR_Bcast_intra_MV2(buffer, count, datatype, root, comm_ptr, errflag);
        } else {
            mpi_errno = MV2_Bcast_function(buffer, count, datatype, root,
                                           comm_ptr, errflag);

        }
    }

    if (mpi_errno) {
        /* for communication errors, just record the error but continue */
        *errflag = MPIR_ERR_GET_CLASS(mpi_errno);
        MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
        MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
    }

  fn_exit:
    MPIR_CHKLMEM_FREEALL();
    if (mpi_errno_ret)
        mpi_errno = mpi_errno_ret;
    else if (*errflag)
        MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**coll_fail");
    return mpi_errno;

  fn_fail:
    goto fn_exit;

}

int MPIR_Bcast_MV2(void *buf, int count, MPI_Datatype datatype,
                   int root, MPIR_Comm * comm_ptr, MPIR_Errflag_t *errflag)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_T_PVAR_COMM_COUNTER_INC(MV2,mv2_coll_bcast_subcomm,1,comm_ptr);
#ifdef _ENABLE_CUDA_
    MPI_Aint datatype_extent;
    MPIR_Datatype_get_extent_macro(datatype, datatype_extent);
    intptr_t nbytes = 0; 
    nbytes = (intptr_t) (count) * (datatype_extent);
    int mem_type = 0;
    int rank = comm_ptr->rank;
    if (mv2_enable_device) {
        mem_type = is_device_buffer(buf);
    }

    if (mv2_enable_device && mem_type &&
        mv2_device_coll_use_stage && (nbytes <= mv2_device_bcast_stage_limit)) {
        if (rank == root) {
            mpi_errno = device_stage_alloc(&buf, count * datatype_extent,
                                         NULL, 0, mem_type, 0, 0);
        } else {
            mpi_errno = device_stage_alloc(NULL, 0, &buf, count * datatype_extent, 0, 1, 0);
        }
        MPIR_ERR_CHECK(mpi_errno);
    }
#endif                          /*#ifdef _ENABLE_CUDA_ */
    if (mv2_use_old_bcast == 0) {
        /* Use the new tuned bcast */
	if (mv2_use_indexed_tuning || mv2_use_indexed_bcast_tuning) {
	    mpi_errno = MPIR_Bcast_index_tuned_intra_MV2(buf, count, datatype,
						  root, comm_ptr, errflag);
	}
	else {
	    mpi_errno = MPIR_Bcast_tune_intra_MV2(buf, count, datatype,
						  root, comm_ptr, errflag);
	}
    } else {
        /* Use the previous tuned bcast */
        mpi_errno = MPIR_Bcast_intra_MV2(buf, count, datatype, root, comm_ptr, errflag);
    }
    comm_ptr->dev.ch.intra_node_done = 0;
#ifdef _ENABLE_CUDA_
    if (mv2_enable_device && mem_type &&
        mv2_device_coll_use_stage && (nbytes <= mv2_device_bcast_stage_limit)) {
        if (rank == root) {
            device_stage_free(&buf, NULL, 0, mem_type, 0);
        } else {
            device_stage_free(NULL, &buf, count * datatype_extent, 0, mem_type);
        }
    }
#endif                          /*#ifdef _ENABLE_CUDA_ */
    MPIR_ERR_CHECK(mpi_errno);

  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}
