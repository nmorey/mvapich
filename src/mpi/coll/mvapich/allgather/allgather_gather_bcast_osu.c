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

extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_coll_timer_allgather_gather_bcast;
extern unsigned long long PVAR_COUNTER_mvp_coll_allgather_gather_bcast;

/* executes an allgather as a gather followed by a broadcast */
int MPIR_Allgather_intra_osu_gather_bcast(
    const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
    void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
    MPIR_Comm *comm_ptr, MPIR_Errflag_t errflag)
{
    int comm_size;
    int mpi_errno = MPI_SUCCESS;
    int gather_bcast_root = -1;

    MPIR_T_PVAR_COUNTER_INC(MVP, mvp_coll_allgather_gather_bcast, 1);
    MPIR_TIMER_START(coll, allgather, gather_bcast);

    comm_size = comm_ptr->local_size;

    gather_bcast_root = 0;
    /* non root processes actually can't handle in place in a gather call */
    if (MPI_IN_PLACE == sendbuf && comm_ptr->rank) {
        sendbuf = recvbuf;
    }
    mpi_errno = MPIR_Gather(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                            recvtype, gather_bcast_root, comm_ptr, errflag);
    MPIR_ERR_CHECK(mpi_errno);

    /* gather_bcast_root has all data at this point */

    /* call bcast on the receive buffer */
    mpi_errno = MPIR_Bcast(recvbuf, recvcount * comm_size, recvtype,
                           gather_bcast_root, comm_ptr, errflag);
    MPIR_ERR_CHECK(mpi_errno);

fn_fail:
    MPIR_TIMER_END(coll, allgather, gather_bcast);
    return (mpi_errno);
}
