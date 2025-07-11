#include "mpiimpl.h"
#include "mvp_coll_impl.h"

int MPIR_Barrier_intra_osu_pairwise(MPIR_Comm *comm_ptr, MPIR_Errflag_t errflag)
{
    int size, rank;
    int d, dst, src;
    int mpi_errno = MPI_SUCCESS;
    int surfeit;
    /* pof2 = greatest power of two < size of Comm (see MPIR_Comm decl) */
    int pof2 = comm_ptr->coll.pof2;

    MPIR_T_PVAR_COUNTER_INC(MVP, mvp_coll_barrier_pairwise, 1);
    MPIR_TIMER_START(coll, barrier, pairwise);

    size = comm_ptr->local_size;
    surfeit = size - pof2;
    /* Trivial barriers return immediately */
    if (size == 1) {
        goto fn_exit;
    }

    rank = comm_ptr->rank;

    /* Perform a combine-like operation */
    if (rank < pof2) {
        if (rank < surfeit) {
            /* get the fanin letter from the upper "half" process: */
            dst = pof2 + rank;
            MPIR_T_MVP_PVAR_COLL_SET_INC(barrier, pairwise, recv, 0, MPI_BYTE);
            mpi_errno = MPIC_Recv(NULL, 0, MPI_BYTE, dst, MPIR_BARRIER_TAG,
                                  comm_ptr, MPI_STATUS_IGNORE);
        }

        /* combine on embedded pof2 power-of-two processes */
        for (d = 1; d < pof2; d <<= 1) {
            dst = (rank ^ d);
            MPIR_T_MVP_PVAR_COLL_SET_INC(barrier, pairwise, send, 0, MPI_BYTE);
            MPIR_T_MVP_PVAR_COLL_SET_INC(barrier, pairwise, recv, 0, MPI_BYTE);
            mpi_errno = MPIC_Sendrecv(NULL, 0, MPI_BYTE, dst, MPIR_BARRIER_TAG,
                                      NULL, 0, MPI_BYTE, dst, MPIR_BARRIER_TAG,
                                      comm_ptr, MPI_STATUS_IGNORE, errflag);
        }

        /* fanout data to nodes above pof2... */
        if (rank < surfeit) {
            dst = pof2 + rank;
            MPIR_T_MVP_PVAR_COLL_SET_INC(barrier, pairwise, send, 0, MPI_BYTE);
            mpi_errno = MPIC_Send(NULL, 0, MPI_BYTE, dst, MPIR_BARRIER_TAG,
                                  comm_ptr, errflag);
        }
    } else {
        /* fanin data to power of 2 subset */
        src = rank - pof2;
        MPIR_T_MVP_PVAR_COLL_SET_INC(barrier, pairwise, send, 0, MPI_BYTE);
        MPIR_T_MVP_PVAR_COLL_SET_INC(barrier, pairwise, recv, 0, MPI_BYTE);
        mpi_errno = MPIC_Sendrecv(NULL, 0, MPI_BYTE, src, MPIR_BARRIER_TAG,
                                  NULL, 0, MPI_BYTE, src, MPIR_BARRIER_TAG,
                                  comm_ptr, MPI_STATUS_IGNORE, errflag);
    }

fn_exit:
    MPIR_TIMER_END(coll, barrier, pairwise);
    return mpi_errno;
fn_fail:
    goto fn_exit;
}
