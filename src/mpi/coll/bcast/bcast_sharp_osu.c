#include "bcast_tuning.h"

#if defined (_SHARP_SUPPORT_)
#include "api/sharp_coll.h"
#include "ibv_sharp.h"
extern int mv2_sharp_tuned_msg_size;
#endif


#if defined (_SHARP_SUPPORT_)
/* Currently implemented on top of allreduce. Ideally should use lower level Sharp
 * calls to achieve the same once avaliable*/
int MPIR_Sharp_Bcast_MV2(void *buffer,
                         int count,
                         MPI_Datatype datatype,
                         int root, MPIR_Comm * comm_ptr, 
                         MPIR_Errflag_t *errflag)
{
    MPIR_TIMER_START(coll, bcast, sharp);
    MPIR_T_PVAR_COUNTER_INC(MV2, mv2_coll_bcast_sharp, 1);
    int mpi_errno = MPI_SUCCESS;
    void *sendbuf = NULL, *recvbuf = NULL;
    MPI_Aint type_size = 0;
    /* Get size of data */
    MPIR_Datatype_get_size_macro(datatype, type_size);
    intptr_t nbytes = (intptr_t) (count) * (type_size);
    int rank = comm_ptr->rank;

    if (rank == root) {
        sendbuf = (void *) buffer;
        recvbuf = (void *) comm_ptr->dev.ch.coll_tmp_buf;
    } else {
        memset(comm_ptr->dev.ch.coll_tmp_buf, 0, nbytes);
        sendbuf = (void *) comm_ptr->dev.ch.coll_tmp_buf;
        recvbuf = (void *) buffer;
    }

    mpi_errno = MPIR_Sharp_Allreduce_MV2(sendbuf, recvbuf, count,
                                         datatype, MPI_SUM, comm_ptr, 
                                         errflag);
    MPIR_ERR_CHECK(mpi_errno);

fn_exit:
    MPIR_TIMER_END(coll, bcast, sharp);
    return (mpi_errno);
fn_fail:
    goto fn_exit;
}
#endif

