#include "barrier_tuning.h"

#if defined (_SHARP_SUPPORT_)
#include "api/sharp_coll.h"
#include "ibv_sharp.h"
#endif

#if defined (_SHARP_SUPPORT_)
int MPIR_Sharp_Barrier_MV2 (MPIR_Comm * comm_ptr, 
                                   MPIR_Errflag_t *errflag)
{
    MPIR_TIMER_START(coll, barrier, sharp);
    MPIR_T_PVAR_COUNTER_INC(MV2, mv2_coll_barrier_sharp, 1);
    int mpi_errno = MPI_SUCCESS;

    struct sharp_coll_comm * sharp_comm =
        ((sharp_info_t *)comm_ptr->dev.ch.sharp_coll_info)
            ->sharp_comm_module->sharp_coll_comm;

    /* Ensure that all messages in non-sharp channels are progressed first
     * to prevent deadlocks in subsequent blocking sharp API calls */
    while (rdma_global_ext_sendq_size) {
        MPIDI_CH3_Progress_test();
    }

    mpi_errno = sharp_ops.coll_do_barrier(sharp_comm);

    if (mpi_errno != SHARP_COLL_SUCCESS) {
        goto fn_fail;
    }

    mpi_errno = MPI_SUCCESS;

fn_exit:
    MPIR_TIMER_END(coll,barrier,sharp);
    return (mpi_errno);

fn_fail:
    PRINT_DEBUG(DEBUG_Sharp_verbose, "Continue without SHArP: %s \n", sharp_ops.coll_strerror(mpi_errno));
    mpi_errno = MPI_ERR_INTERN;
    goto fn_exit;

}
#endif /* end of defined (_SHARP_SUPPORT_) */
