/*
 * Copyright (c) 2001-2023, The Ohio State University. All rights reserved.
 *
 * This file is part of the MVAPICH software package developed by the team
 * members of The Ohio State University's Network-Based Computing Laboratory
 * (NBCL), headed by Professor Dhabaleswar K. (DK) Panda.
 *
 * For detailed copyright and licensing information, please refer to the
 * copyright file COPYRIGHT in the top level MVAPICH directory.
 */

/*
=== BEGIN_MPI_T_CVAR_INFO_BLOCK ===

cvars:
    - name        : MPIR_CVAR_BCAST_INTER_KNOMIAL_FACTOR
      category    : COLLECTIVE
      type        : int
      default     : 4
      class       : none
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : >-
        This defines the degree of the knomial operation during the
        inter-node knomial broadcast phase.

    - name        : MPIR_CVAR_BCAST_INTRA_KNOMIAL_FACTOR
      category    : COLLECTIVE
      type        : int
      default     : 4
      class       : none
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : >-
        This defines the degree of the knomial operation during the
        intra-node knomial broadcast phase.

=== END_MPI_T_CVAR_INFO_BLOCK ===
*/

#include "mpiimpl.h"
#include "mvp_coll_impl.h"

int MPIR_Bcast_intra_osu_knomial_inter_node(void *buffer, int count,
                                            MPI_Datatype datatype, int root,
                                            MPIR_Comm *comm_ptr, int inter_kf,
                                            MPIR_Errflag_t errflag)
{
    MPIR_Comm *shmem_commptr = NULL, *leader_commptr = NULL;
    int local_rank = 0;
    int comm_size = 0, rank = 0;
    int mpi_errno = MPI_SUCCESS;
    int mpi_errno_ret = MPI_SUCCESS;
    MPIR_Request **reqarray = NULL;
    MPI_Status *starray = NULL;
    int src, dst, mask, relative_rank;
    int k;

    MPIR_T_PVAR_COUNTER_INC(MVP, mvp_coll_bcast_knomial_internode, 1);
    MPIR_TIMER_START(coll, bcast, knomial_internode);
    /*
if (count > 262144) {
 static volatile int zz = 0;
 char hostname[256];
 gethostname(hostname, sizeof(hostname));
 fprintf(stderr, "PID %d on %s ready for attach\n", getpid(), hostname);
 fflush(stderr);
 while (0 == zz) { sleep(5); }
}
*/
    if (comm_ptr->hierarchy_kind == MPIR_COMM_HIERARCHY_KIND__PARENT) {
        /* parent comm has the subcomms */
        shmem_commptr = comm_ptr->node_comm;
        leader_commptr = comm_ptr->node_roots_comm;
        local_rank = shmem_commptr->rank;
    } else {
        /* non hierarchical setup, we just the full comm */
        leader_commptr = comm_ptr;
    }

    MPIR_CHKLMEM_DECL(2);

    MPIR_CHKLMEM_MALLOC(reqarray, MPIR_Request **,
                        2 * inter_kf * sizeof(MPIR_Request *), mpi_errno,
                        "reqarray", MPL_MEM_COLL);

    MPIR_CHKLMEM_MALLOC(starray, MPI_Status *,
                        2 * inter_kf * sizeof(MPI_Status), mpi_errno, "starray",
                        MPL_MEM_COLL);
    if (local_rank == 0) {
        comm_size = leader_commptr->local_size;
        rank = leader_commptr->rank;
        /* inter-node k-nomial bcast  */
        if (comm_size > 1) {
            relative_rank =
                (rank >= root) ? rank - root : rank - root + comm_size;
            mask = 0x1;

            while (mask < comm_size) {
                if (relative_rank % (inter_kf * mask)) {
                    src =
                        relative_rank / (inter_kf * mask) * (inter_kf * mask) +
                        root;
                    if (src >= comm_size) {
                        src -= comm_size;
                    }

                    MPIR_T_MVP_PVAR_COLL_SET_INC(bcast, knomial_internode, recv,
                                                 count, datatype);
                    mpi_errno =
                        MPIC_Recv(buffer, count, datatype, src, MPIR_BCAST_TAG,
                                  leader_commptr, MPI_STATUS_IGNORE);
                    if (mpi_errno) {
                        /* for communication errors,
                         * just record the error but continue */
                        errflag = MPIR_ERR_GET_CLASS(mpi_errno);
                        MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
                        MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
                    }
                    break;
                }
                mask *= inter_kf;
            }

            mask /= inter_kf;

            while (mask > 0) {
                int reqs = 0;
                for (k = 1; k < inter_kf; k++) {
                    if (relative_rank + mask * k < comm_size) {
                        dst = rank + mask * k;
                        if (dst >= comm_size) {
                            dst -= comm_size;
                        }
                        MPIR_T_MVP_PVAR_COLL_SET_INC(bcast, knomial_internode,
                                                     send, count, datatype);
                        mpi_errno = MPIC_Isend(buffer, count, datatype, dst,
                                               MPIR_BCAST_TAG, leader_commptr,
                                               &reqarray[reqs++], errflag);
                        if (mpi_errno) {
                            /* for communication errors,
                             * just record the error but continue */
                            errflag = MPIR_ERR_GET_CLASS(mpi_errno);
                            MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
                            MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
                        }
                    }
                }
                mpi_errno = MPIC_Waitall(reqs, reqarray, starray);
                MPIR_ERR_CHECK(mpi_errno);

                /* --BEGIN ERROR HANDLING-- */
                if (mpi_errno == MPI_ERR_IN_STATUS) {
                    int j;
                    for (j = 0; j < reqs; j++) {
                        if (starray[j].MPI_ERROR != MPI_SUCCESS) {
                            mpi_errno = starray[j].MPI_ERROR;
                            if (mpi_errno) {
                                /* for communication errors,
                                 * just record the error but continue */
                                errflag = MPIR_ERR_GET_CLASS(mpi_errno);
                                MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER,
                                             "**fail");
                                MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
                            }
                        }
                    }
                }
                mask /= inter_kf;
            }
        }
    }
    /* Start the shmem-bcast before
     * we send the data across the network */
    /* TODO: consider skipping tuning here for overhead */
    if (shmem_commptr) {
        mpi_errno =
            MPIR_Bcast_impl(buffer, count, datatype, 0, shmem_commptr, errflag);
    }
fn_fail:

    MPIR_CHKLMEM_FREEALL();
    MPIR_TIMER_END(coll, bcast, knomial_internode);
    return mpi_errno;
}

int MPIR_Bcast_intra_osu_knomial_intra_node(void *buffer, int count,
                                            MPI_Datatype datatype, int root,
                                            MPIR_Comm *comm_ptr, int intra_kf,
                                            MPIR_Errflag_t errflag)
{
    int local_size = 0, rank;
    int mpi_errno = MPI_SUCCESS;
    int mpi_errno_ret = MPI_SUCCESS;
    MPIR_Request **reqarray = NULL;
    MPI_Status *starray = NULL;
    int src, dst, mask, relative_rank;
    int k;

    MPIR_T_PVAR_COUNTER_INC(MVP, mvp_coll_bcast_knomial_intranode, 1);
    MPIR_TIMER_START(coll, bcast, knomial_intranode);
    local_size = comm_ptr->local_size;
    rank = comm_ptr->rank;
    MPIR_CHKLMEM_DECL(2);

    MPIR_CHKLMEM_MALLOC(reqarray, MPIR_Request **,
                        2 * intra_kf * sizeof(MPIR_Request *), mpi_errno,
                        "reqarray", MPL_MEM_COLL);

    MPIR_CHKLMEM_MALLOC(starray, MPI_Status *,
                        2 * intra_kf * sizeof(MPI_Status), mpi_errno, "starray",
                        MPL_MEM_COLL);

    /* intra-node k-nomial bcast  */
    if (local_size > 1) {
        relative_rank = (rank >= root) ? rank - root : rank - root + local_size;
        mask = 0x1;

        while (mask < local_size) {
            if (relative_rank % (intra_kf * mask)) {
                src = relative_rank / (intra_kf * mask) * (intra_kf * mask) +
                      root;
                if (src >= local_size) {
                    src -= local_size;
                }

                MPIR_T_MVP_PVAR_COLL_SET_INC(bcast, knomial_intranode, recv,
                                             count, datatype);
                mpi_errno =
                    MPIC_Recv(buffer, count, datatype, src, MPIR_BCAST_TAG,
                              comm_ptr, MPI_STATUS_IGNORE);
                if (mpi_errno) {
                    /* for communication errors,
                     * just record the error but continue */
                    errflag = MPIR_ERR_GET_CLASS(mpi_errno);
                    MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
                    MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
                }
                break;
            }
            mask *= intra_kf;
        }
        mask /= intra_kf;

        while (mask > 0) {
            int reqs = 0;
            for (k = 1; k < intra_kf; k++) {
                if (relative_rank + mask * k < local_size) {
                    dst = rank + mask * k;
                    if (dst >= local_size) {
                        dst -= local_size;
                    }
                    MPIR_T_MVP_PVAR_COLL_SET_INC(bcast, knomial_intranode, send,
                                                 count, datatype);
                    mpi_errno =
                        MPIC_Isend(buffer, count, datatype, dst, MPIR_BCAST_TAG,
                                   comm_ptr, &reqarray[reqs++], errflag);
                    if (mpi_errno) {
                        /* for communication errors,
                         * just record the error but continue */
                        errflag = MPIR_ERR_GET_CLASS(mpi_errno);
                        MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
                        MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
                    }
                }
            }
            mpi_errno = MPIC_Waitall(reqs, reqarray, starray);
            MPIR_ERR_CHECK(mpi_errno);

            /* --BEGIN ERROR HANDLING-- */
            if (mpi_errno == MPI_ERR_IN_STATUS) {
                int j;
                for (j = 0; j < reqs; j++) {
                    if (starray[j].MPI_ERROR != MPI_SUCCESS) {
                        mpi_errno = starray[j].MPI_ERROR;
                        if (mpi_errno) {
                            /* for communication errors,
                             * just record the error but continue */
                            errflag = MPIR_ERR_GET_CLASS(mpi_errno);
                            MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
                            MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
                        }
                    }
                }
            }
            mask /= intra_kf;
        }
    }

fn_fail:
    MPIR_CHKLMEM_FREEALL();
    MPIR_TIMER_END(coll, bcast, knomial_intranode);
    return mpi_errno;
}

int MPIR_Bcast_intra_osu_knomial(void *buffer, MPI_Aint count,
                                 MPI_Datatype datatype, int root,
                                 MPIR_Comm *comm_ptr, int inter_kf,
                                 int intra_kf, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    if (comm_ptr->node_count > 1) {
        mpi_errno = MPIR_Bcast_intra_osu_knomial_inter_node(
            buffer, count, datatype, root, comm_ptr, inter_kf, errflag);
    } else {
        mpi_errno = MPIR_Bcast_intra_osu_knomial_intra_node(
            buffer, count, datatype, root, comm_ptr, intra_kf, errflag);
    }
fn_exit:
    return mpi_errno;
fn_fail:
    goto fn_exit;
}
