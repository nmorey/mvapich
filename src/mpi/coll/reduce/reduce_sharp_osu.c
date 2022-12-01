#include "reduce_tuning.h"
#if defined (_SHARP_SUPPORT_)
#include "api/sharp_coll.h"
#include "ibv_sharp.h"
extern int mv2_sharp_tuned_msg_size;
#endif

#if defined (_SHARP_SUPPORT_)
/* Currently implemented on top of allreduce. 
 * Ideally should use lower level Sharp
 * calls to achieve the same once avaliable*/
int MPIR_Sharp_Reduce_MV2(const void *sendbuf, void *recvbuf, int count,
                          MPI_Datatype datatype, MPI_Op op, int root,
                          MPIR_Comm * comm_ptr, MPIR_Errflag_t *errflag)
{
    MPIR_TIMER_START(coll,reduce,sharp);
    MPIR_T_PVAR_COUNTER_INC(MV2, mv2_coll_reduce_sharp, 1);
    int mpi_errno = MPI_SUCCESS;
    void *new_recvbuf = NULL;
    int rank = comm_ptr->rank;

    if (rank != root) {
        new_recvbuf = (void *) comm_ptr->dev.ch.coll_tmp_buf;
    } else {
        new_recvbuf = (void *) recvbuf;
    }

    mpi_errno = MPIR_Sharp_Allreduce_MV2(sendbuf, new_recvbuf, count,
                                         datatype, op, comm_ptr, errflag);
    MPIR_ERR_CHECK(mpi_errno);

fn_exit:
    MPIR_TIMER_END(coll,reduce,sharp);
    return (mpi_errno);
fn_fail:
    goto fn_exit;
}
#endif
