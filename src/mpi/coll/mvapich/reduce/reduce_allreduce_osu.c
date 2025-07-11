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

int MPIR_Reduce_intra_osu_allreduce(const void *sendbuf, void *recvbuf,
                                    MPI_Aint count, MPI_Datatype datatype,
                                    MPI_Op op, int root, MPIR_Comm *comm_ptr,
                                    MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    int mpi_errno_ret = MPI_SUCCESS;
    int rank;
    MPI_Aint true_lb, true_extent, extent;
    void *tmp_buf = NULL;
    size_t recvbuf_size = 0;
    int using_comm_buf = 0;

    MPIC_MVP_RECURSION_GUARD_ENTER(MPIR_Reduce_intra_binomial, sendbuf, recvbuf,
                                   count, datatype, op, root, comm_ptr, errflag)

    MPIR_T_PVAR_COUNTER_INC(MVP, mvp_coll_reduce_allreduce, 1);
    MPIR_TIMER_START(coll, reduce, allreduce);

    if (count == 0) {
        goto fn_exit;
    }

    rank = comm_ptr->rank;

    MPIR_Type_get_true_extent_impl(datatype, &true_lb, &true_extent);
    MPIR_Datatype_get_extent_macro(datatype, extent);

    recvbuf_size = count * MPL_MAX(extent, true_extent);

    /* Call allreduce and discard the result on all non-root processes */
    if (rank != root) {
        tmp_buf = MPL_malloc(recvbuf_size, MPL_MEM_BUFFER);
    }

    if (rank != root) {
        mpi_errno = MPIR_Allreduce(sendbuf, tmp_buf, count, datatype, op,
                                   comm_ptr, errflag);
    } else {
        mpi_errno = MPIR_Allreduce(sendbuf, recvbuf, count, datatype, op,
                                   comm_ptr, errflag);
    }

    MPIR_ERR_CHECK(mpi_errno);

    if (!using_comm_buf && rank != root) {
        MPL_free(tmp_buf);
    }

fn_exit:
    MPIR_TIMER_END(coll, reduce, allreduce);
    MPIC_MVP_RECURSION_GUARD_EXIT
    if (mpi_errno_ret) {
        mpi_errno = mpi_errno_ret;
    } else if (errflag) {
        MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**coll_fail");
    }

    return mpi_errno;
fn_fail:
    goto fn_exit;
}
