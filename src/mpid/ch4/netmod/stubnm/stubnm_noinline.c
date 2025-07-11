/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* ** This file is auto-generated, do not edit ** */

#include <mpidimpl.h>

int MPIDI_STUBNM_init_local(int *tag_bits)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_init_world(void)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_mpi_finalize_hook(void)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_init_vcis(int num_vcis, int *num_vcis_actual)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_post_init(void)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_comm_set_hints(MPIR_Comm * comm_ptr, MPIR_Info * info)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_get_local_upids(MPIR_Comm * comm, int **local_upid_size, char **local_upids)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_upids_to_gpids(int size, int *remote_upid_size, char *remote_upids,
                                uint64_t * remote_gpids)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_dynamic_send(uint64_t remote_gpid, int tag, const void *buf, int size, int timeout)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_dynamic_recv(int tag, void *buf, int size, int timeout)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_mpi_comm_commit_pre_hook(MPIR_Comm * comm)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_mpi_comm_commit_post_hook(MPIR_Comm * comm)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_mpi_comm_free_hook(MPIR_Comm * comm)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_mpi_win_create_hook(MPIR_Win * win)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_mpi_win_allocate_hook(MPIR_Win * win)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_mpi_win_allocate_shared_hook(MPIR_Win * win)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_mpi_win_create_dynamic_hook(MPIR_Win * win)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_mpi_win_attach_hook(MPIR_Win * win, void *base, MPI_Aint size)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_mpi_win_detach_hook(MPIR_Win * win, const void *base)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_mpi_win_free_hook(MPIR_Win * win)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_mpi_psend_init(const void *buf, int partitions, MPI_Aint count,
                                MPI_Datatype datatype, int rank, int tag, MPIR_Comm * comm,
                                MPIR_Info * info, MPIDI_av_entry_t * av, MPIR_Request ** req_p)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_mpi_precv_init(void *buf, int partitions, MPI_Aint count, MPI_Datatype datatype,
                                int rank, int tag, MPIR_Comm * comm, MPIR_Info * info,
                                MPIDI_av_entry_t * av, MPIR_Request ** req_p)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

void *MPIDI_STUBNM_mpi_alloc_mem(MPI_Aint size, MPIR_Info * info)
{
    MPIR_Assert(0);
    return 0;
}

int MPIDI_STUBNM_mpi_free_mem(void *ptr)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_mpi_win_set_info(MPIR_Win * win, MPIR_Info * info)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_mpi_win_get_info(MPIR_Win * win, MPIR_Info ** info_p)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_mpi_win_free(MPIR_Win ** win_p)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_mpi_win_create(void *base, MPI_Aint length, int disp_unit, MPIR_Info * info,
                                MPIR_Comm * comm_ptr, MPIR_Win ** win_p)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_mpi_win_attach(MPIR_Win * win, void *base, MPI_Aint size)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_mpi_win_allocate_shared(MPI_Aint size, int disp_unit, MPIR_Info * info,
                                         MPIR_Comm * comm_ptr, void **baseptr_p, MPIR_Win ** win_p)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_mpi_win_detach(MPIR_Win * win, const void *base)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_mpi_win_allocate(MPI_Aint size, int disp_unit, MPIR_Info * info, MPIR_Comm * comm,
                                  void *baseptr, MPIR_Win ** win_p)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_mpi_win_create_dynamic(MPIR_Info * info, MPIR_Comm * comm, MPIR_Win ** win_p)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_mpi_type_commit_hook(MPIR_Datatype * datatype_p)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_mpi_type_free_hook(MPIR_Datatype * datatype_p)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_mpi_op_commit_hook(MPIR_Op * op_p)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}

int MPIDI_STUBNM_mpi_op_free_hook(MPIR_Op * op_p)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Assert(0);
    return mpi_errno;
}
