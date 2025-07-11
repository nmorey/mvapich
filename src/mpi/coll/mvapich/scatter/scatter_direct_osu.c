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

#include "mpiimpl.h"
#include "mvp_coll_impl.h"

int MPIR_Scatter_intra_osu_direct(const void *sendbuf, MPI_Aint sendcnt,
                                  MPI_Datatype sendtype, void *recvbuf,
                                  MPI_Aint recvcnt, MPI_Datatype recvtype,
                                  int root, MPIR_Comm *comm_ptr,
                                  MPIR_Errflag_t errflag)
{
    int rank, comm_size;
    int mpi_errno = MPI_SUCCESS;
    int mpi_errno_ret = MPI_SUCCESS;
    MPI_Aint sendtype_extent;
    int i, reqs;
    MPIR_Request **reqarray;
    MPI_Status *starray;
    MPIR_CHKLMEM_DECL(2);

    MPIR_T_PVAR_COUNTER_INC(MVP, mvp_coll_scatter_direct, 1);
    MPIR_TIMER_START(coll, scatter, direct);

    rank = comm_ptr->rank;

    /* If I'm the root, then scatter */
    if (((comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) &&
         (root == rank)) ||
        ((comm_ptr->comm_kind == MPIR_COMM_KIND__INTERCOMM) &&
         (root == MPI_ROOT))) {
        if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM)
            comm_size = comm_ptr->local_size;
        else
            comm_size = comm_ptr->remote_size;

        MPIR_Datatype_get_extent_macro(sendtype, sendtype_extent);

        MPIR_CHKLMEM_MALLOC(reqarray, MPIR_Request **,
                            comm_size * sizeof(MPIR_Request *), mpi_errno,
                            "reqarray", MPL_MEM_COLL);
        MPIR_CHKLMEM_MALLOC(starray, MPI_Status *,
                            comm_size * sizeof(MPI_Status), mpi_errno,
                            "starray", MPL_MEM_COLL);

        reqs = 0;
        for (i = 0; i < comm_size; i++) {
            if (sendcnt) {
                if ((comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) &&
                    (i == rank)) {
                    if (recvbuf != MPI_IN_PLACE) {
                        mpi_errno = MPIR_Localcopy(
                            ((char *)sendbuf +
                             rank * sendcnt * sendtype_extent),
                            sendcnt, sendtype, recvbuf, recvcnt, recvtype);
                    }
                } else {
                    MPIR_T_MVP_PVAR_COLL_SET_INC(scatter, direct, send, sendcnt,
                                                 sendtype);
                    mpi_errno = MPIC_Isend(
                        ((char *)sendbuf + i * sendcnt * sendtype_extent),
                        sendcnt, sendtype, i, MPIR_SCATTER_TAG, comm_ptr,
                        &reqarray[reqs++], errflag);
                }
                if (mpi_errno) {
                    /* for communication errors,
                     * just record the error but continue */
                    errflag = MPIR_ERR_GET_CLASS(mpi_errno);
                    MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
                    MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
                }
            }
        }
        /* ... then wait for *all* of them to finish: */
        mpi_errno = MPIC_Waitall(reqs, reqarray, starray);
        /* --BEGIN ERROR HANDLING-- */
        if (mpi_errno == MPI_ERR_IN_STATUS) {
            for (i = 0; i < reqs; i++) {
                if (starray[i].MPI_ERROR != MPI_SUCCESS)
                    mpi_errno = starray[i].MPI_ERROR;
                if (mpi_errno) {
                    /* for communication errors,
                     * just record the error but continue */
                    errflag = MPIR_ERR_GET_CLASS(mpi_errno);
                    MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
                    MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
                }
            }
        }
        /* --END ERROR HANDLING-- */
    } else if (root != MPI_PROC_NULL) {
        /* non-root nodes, and in the intercomm. case,
         * non-root nodes on remote side */
        if (recvcnt) {
            MPIR_T_MVP_PVAR_COLL_SET_INC(scatter, direct, recv, recvcnt,
                                         recvtype);
            mpi_errno =
                MPIC_Recv(recvbuf, recvcnt, recvtype, root, MPIR_SCATTER_TAG,
                          comm_ptr, MPI_STATUS_IGNORE);
            if (mpi_errno) {
                /* for communication errors,
                 * just record the error but continue */
                errflag = MPIR_ERR_GET_CLASS(mpi_errno);
                MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
                MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
            }
        }
    }

fn_exit:
    MPIR_TIMER_END(coll, scatter, direct);
    MPIR_CHKLMEM_FREEALL();
    return mpi_errno;
fn_fail:
    goto fn_exit;
}

int MPIR_Scatter_intra_osu_direct_block(const void *sendbuf, MPI_Aint sendcnt,
                                        MPI_Datatype sendtype, void *recvbuf,
                                        MPI_Aint recvcnt, MPI_Datatype recvtype,
                                        int root, MPIR_Comm *comm_ptr,
                                        MPIR_Errflag_t errflag)
{
    MPIR_TIMER_START(coll, scatter, direct_blk);
    int rank, comm_size;
    int mpi_errno = MPI_SUCCESS;
    int mpi_errno_ret = MPI_SUCCESS;
    MPI_Aint sendtype_extent;
    int i;

    MPIR_T_PVAR_COUNTER_INC(MVP, mvp_coll_scatter_direct_blk, 1);

    rank = comm_ptr->rank;

    /* If I'm the root, then scatter */
    if (((comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) &&
         (root == rank)) ||
        ((comm_ptr->comm_kind == MPIR_COMM_KIND__INTERCOMM) &&
         (root == MPI_ROOT))) {
        if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM)
            comm_size = comm_ptr->local_size;
        else
            comm_size = comm_ptr->remote_size;

        MPIR_Datatype_get_extent_macro(sendtype, sendtype_extent);

        for (i = 0; i < comm_size; i++) {
            if (sendcnt) {
                if ((comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) &&
                    (i == rank)) {
                    if (recvbuf != MPI_IN_PLACE) {
                        mpi_errno = MPIR_Localcopy(
                            ((char *)sendbuf +
                             rank * sendcnt * sendtype_extent),
                            sendcnt, sendtype, recvbuf, recvcnt, recvtype);
                        MPIR_ERR_CHECK(mpi_errno);
                    }
                } else {
                    MPIR_T_MVP_PVAR_COLL_SET_INC(scatter, direct_blk, send,
                                                 sendcnt, sendtype);
                    mpi_errno = MPIC_Send(
                        ((char *)sendbuf + i * sendcnt * sendtype_extent),
                        sendcnt, sendtype, i, MPIR_SCATTER_TAG, comm_ptr,
                        errflag);
                }
                if (mpi_errno) {
                    /* for communication errors,
                     * just record the error but continue */
                    errflag = MPIR_ERR_GET_CLASS(mpi_errno);
                    MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
                    MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
                }
            }
        }
    } else if (root != MPI_PROC_NULL) {
        /* non-root nodes, and in the intercomm. case,
         * non-root nodes on remote side */
        if (recvcnt) {
            MPIR_T_MVP_PVAR_COLL_SET_INC(scatter, direct_blk, recv, recvcnt,
                                         recvtype);
            mpi_errno =
                MPIC_Recv(recvbuf, recvcnt, recvtype, root, MPIR_SCATTER_TAG,
                          comm_ptr, MPI_STATUS_IGNORE);
            if (mpi_errno) {
                /* for communication errors,
                 * just record the error but continue */
                errflag = MPIR_ERR_GET_CLASS(mpi_errno);
                MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
                MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
            }
        }
    }

fn_exit:
    MPIR_TIMER_END(coll, scatter, direct_blk);
    return mpi_errno;
fn_fail:
    goto fn_exit;
}
