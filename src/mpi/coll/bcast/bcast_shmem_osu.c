#include "bcast_tuning.h"

/* Intranode bcast using shmem */
int MPIR_Shmem_Bcast_MV2(void *buffer,
                         int count,
                         MPI_Datatype datatype,
                         int root, MPIR_Comm * shmem_comm_ptr, 
                         MPIR_Errflag_t *errflag)
{
    MPIR_TIMER_START(coll, bcast, shmem);
    int mpi_errno = MPI_SUCCESS;
    int shmem_comm_rank;
    MPI_Aint type_size;
    intptr_t nbytes;
    int local_rank, local_size;

    MPIR_T_PVAR_COUNTER_INC(MV2, mv2_coll_bcast_shmem, 1);
    MPIR_Datatype_get_size_macro(datatype, type_size);
    nbytes = (intptr_t) (count) * (type_size);
    shmem_comm_rank = shmem_comm_ptr->dev.ch.shmem_comm_rank;
    void *shmem_buf = NULL;

    local_rank = shmem_comm_ptr->rank;
    local_size = shmem_comm_ptr->local_size;

    if (count == 0) {
        goto fn_exit;
    }

    MPIR_T_PVAR_COUNTER_INC(MV2, mv2_num_shmem_coll_calls, 1);

    if (mv2_use_slot_shmem_coll && mv2_use_slot_shmem_bcast) {
        char *buf;
        int len;
        intptr_t pos;
        MPI_Aint extent;
        MPI_Aint true_lb, true_extent;
        MPIR_Datatype_get_extent_macro(datatype, extent);
        MPIR_Type_get_true_extent_impl(datatype, &true_lb, &true_extent);
        nbytes = (intptr_t) (count) * extent;
        for (pos = 0; pos < nbytes; pos += mv2_shm_slot_len) {
            buf = (char *) buffer + true_lb + pos;
            len = MIN(nbytes - pos, mv2_shm_slot_len);
            mv2_shm_bcast(shmem_comm_ptr->dev.ch.shmem_info, buf, len, 0);
        }
        goto fn_exit;
    }

    if (local_rank == 0) {
        MPIR_MV2_SHMEM_Bcast_GetBuf(local_size, local_rank,
                                      shmem_comm_rank, (void *) &shmem_buf);
        mpi_errno = MPIR_Localcopy(buffer, count, datatype, 
                                   shmem_buf, nbytes, MPI_BYTE);
        MPIR_MV2_SHMEM_Bcast_Complete(local_size, local_rank, 
                                        shmem_comm_rank);
    } else {
        MPIR_MV2_SHMEM_Bcast_GetBuf(local_size, local_rank,
                                      shmem_comm_rank, (void *) &shmem_buf);
        mpi_errno = MPIR_Localcopy(shmem_buf, nbytes, MPI_BYTE, 
                                   buffer, count, datatype);
        MPIR_MV2_SHMEM_Bcast_Complete(local_size, local_rank, 
                                        shmem_comm_rank);
    }
    if (mpi_errno) {
        *errflag = MPIR_ERR_GET_CLASS(mpi_errno);
        MPIR_ERR_POP(mpi_errno);
    }

  fn_exit:
    MPIR_TIMER_END(coll, bcast, shmem);
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

