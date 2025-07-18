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

int MPIR_Reduce_scatter_intra_osu_basic(const void *sendbuf, void *recvbuf,
                                        const MPI_Aint *recvcnts,
                                        MPI_Datatype datatype, MPI_Op op,
                                        MPIR_Comm *comm_ptr,
                                        MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS, i;
    int rank, size;
    int total_count;
    MPI_Aint *displs = NULL;
    char *tmprbuf = NULL;
    char *tmprbuf_free = NULL;
    int root = 0, use_scatterv = 0;
    MPIR_CHKLMEM_DECL(1);

    MPIR_T_PVAR_COUNTER_INC(MVP, mvp_coll_reduce_scatter_basic, 1);
    MPIR_TIMER_START(coll, reduce_scatter, basic);

    rank = comm_ptr->rank;
    size = comm_ptr->local_size;

    for (i = 0, total_count = 0; i < size; i++) {
        total_count += recvcnts[i];
    }

    /* Reduce to rank 0 (root) and scatterv */
    tmprbuf = (char *)recvbuf;
    if (MPI_IN_PLACE == sendbuf) {
        /* recvbuf on root (0) is big enough to hold whole data */
        if (root == rank) {
            mpi_errno = MPIR_Reduce(MPI_IN_PLACE, tmprbuf, total_count,
                                    datatype, op, root, comm_ptr, errflag);
        } else {
            mpi_errno = MPIR_Reduce(tmprbuf, NULL, total_count, datatype, op,
                                    root, comm_ptr, errflag);
        }
    } else {
        /* Allocate temporary receive buffer on root to ensure that
         *                rbuf is big enough */
        MPI_Aint true_lb, true_extent, extent;
        MPIR_Type_get_true_extent_impl(datatype, &true_lb, &true_extent);
        MPIR_Datatype_get_extent_macro(datatype, extent);

        MPIR_CHKLMEM_MALLOC(tmprbuf_free, void *,
                            total_count *(MPL_MAX(extent, true_extent)),
                            mpi_errno, "receive buffer", MPL_MEM_COLL);
        tmprbuf = (void *)((char *)tmprbuf_free - true_lb);

        mpi_errno = MPIR_Reduce(sendbuf, tmprbuf, total_count, datatype, op,
                                root, comm_ptr, errflag);
    }
    if (MPI_SUCCESS != mpi_errno) {
        MPIR_TIMER_END(coll, reduce_scatter, basic);
        return mpi_errno;
    }

    for (i = 1; i < size; i++) {
        if (recvcnts[i] != recvcnts[i - 1]) {
            use_scatterv = 1;
            break;
        }
    }

    if (use_scatterv == 0) {
        /* Use regular Scatter when possible */
        if (sendbuf != MPI_IN_PLACE) {
            mpi_errno =
                MPIR_Scatter(tmprbuf, recvcnts[0], datatype, recvbuf,
                             recvcnts[0], datatype, root, comm_ptr, errflag);
        } else {
            if (root == rank) {
                mpi_errno = MPIR_Scatter(tmprbuf, recvcnts[0], datatype,
                                         MPI_IN_PLACE, recvcnts[0], datatype,
                                         root, comm_ptr, errflag);
            } else {
                mpi_errno = MPIR_Scatter(NULL, recvcnts[0], datatype, recvbuf,
                                         recvcnts[0], datatype, root, comm_ptr,
                                         errflag);
            }
        }
        if (MPI_SUCCESS != mpi_errno) {
            MPIR_TIMER_END(coll, reduce_scatter, basic);
            return mpi_errno;
        }
    } else {
        displs = MPL_malloc(size * sizeof(MPI_Aint), MPL_MEM_COLL);
        displs[0] = 0;
        for (i = 1; i < size; i++) {
            displs[i] = displs[i - 1] + recvcnts[i - 1];
        }
        if (sendbuf != MPI_IN_PLACE) {
            mpi_errno = MPIR_Scatterv(tmprbuf, recvcnts, displs, datatype,
                                      recvbuf, recvcnts[rank], datatype, root,
                                      comm_ptr, errflag);
        } else {
            if (root == rank) {
                mpi_errno = MPIR_Scatterv(tmprbuf, recvcnts, displs, datatype,
                                          MPI_IN_PLACE, recvcnts[rank],
                                          datatype, root, comm_ptr, errflag);
            } else {
                mpi_errno = MPIR_Scatterv(NULL, recvcnts, displs, datatype,
                                          recvbuf, recvcnts[rank], datatype,
                                          root, comm_ptr, errflag);
            }
        }
        if (MPI_SUCCESS != mpi_errno) {
            MPIR_TIMER_END(coll, reduce_scatter, basic);
            return mpi_errno;
        }
        MPL_free(displs);
    }

fn_exit:
    MPIR_CHKLMEM_FREEALL();
    MPIR_TIMER_END(coll, reduce_scatter, basic);
    return mpi_errno;
fn_fail:
    goto fn_exit;
}
