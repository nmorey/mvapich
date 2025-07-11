/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* ** This file is auto-generated, do not edit ** */


#include "mpidimpl.h"

#ifndef NETMOD_INLINE
int MPIDI_NM_init_local(int *tag_bits)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->init_local(tag_bits);

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_init_world(void)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->init_world();

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_mpi_finalize_hook(void)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->mpi_finalize_hook();

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_init_vcis(int num_vcis, int *num_vcis_actual)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->init_vcis(num_vcis, num_vcis_actual);

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_post_init(void)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->post_init();

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_comm_set_hints(MPIR_Comm * comm_ptr, MPIR_Info * info)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->comm_set_hints(comm_ptr, info);

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_get_local_upids(MPIR_Comm * comm, int **local_upid_size, char **local_upids)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->get_local_upids(comm, local_upid_size, local_upids);

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_upids_to_gpids(int size, int *remote_upid_size, char *remote_upids,
                            uint64_t * remote_gpids)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->upids_to_gpids(size, remote_upid_size, remote_upids, remote_gpids);

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_dynamic_send(uint64_t remote_gpid, int tag, const void *buf, int size, int timeout)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->dynamic_send(remote_gpid, tag, buf, size, timeout);

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_dynamic_recv(int tag, void *buf, int size, int timeout)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->dynamic_recv(tag, buf, size, timeout);

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_mpi_comm_commit_pre_hook(MPIR_Comm * comm)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->mpi_comm_commit_pre_hook(comm);

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_mpi_comm_commit_post_hook(MPIR_Comm * comm)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->mpi_comm_commit_post_hook(comm);

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_mpi_comm_free_hook(MPIR_Comm * comm)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->mpi_comm_free_hook(comm);

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_mpi_win_create_hook(MPIR_Win * win)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->mpi_win_create_hook(win);

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_mpi_win_allocate_hook(MPIR_Win * win)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->mpi_win_allocate_hook(win);

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_mpi_win_allocate_shared_hook(MPIR_Win * win)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->mpi_win_allocate_shared_hook(win);

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_mpi_win_create_dynamic_hook(MPIR_Win * win)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->mpi_win_create_dynamic_hook(win);

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_mpi_win_attach_hook(MPIR_Win * win, void *base, MPI_Aint size)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->mpi_win_attach_hook(win, base, size);

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_mpi_win_detach_hook(MPIR_Win * win, const void *base)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->mpi_win_detach_hook(win, base);

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_mpi_win_free_hook(MPIR_Win * win)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->mpi_win_free_hook(win);

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_mpi_psend_init(const void *buf, int partitions, MPI_Aint count, MPI_Datatype datatype,
                            int rank, int tag, MPIR_Comm * comm, MPIR_Info * info,
                            MPIDI_av_entry_t * av, MPIR_Request ** req_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_psend_init(buf, partitions, count, datatype, rank, tag, comm,
                                               info, av, req_p);

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_mpi_precv_init(void *buf, int partitions, MPI_Aint count, MPI_Datatype datatype,
                            int rank, int tag, MPIR_Comm * comm, MPIR_Info * info,
                            MPIDI_av_entry_t * av, MPIR_Request ** req_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_precv_init(buf, partitions, count, datatype, rank, tag, comm,
                                               info, av, req_p);

    MPIR_FUNC_EXIT;
    return ret;
}

void *MPIDI_NM_mpi_alloc_mem(MPI_Aint size, MPIR_Info * info)
{
    void * ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_alloc_mem(size, info);

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_mpi_free_mem(void *ptr)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_free_mem(ptr);

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_mpi_win_set_info(MPIR_Win * win, MPIR_Info * info)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_win_set_info(win, info);

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_mpi_win_get_info(MPIR_Win * win, MPIR_Info ** info_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_win_get_info(win, info_p);

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_mpi_win_free(MPIR_Win ** win_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_win_free(win_p);

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_mpi_win_create(void *base, MPI_Aint length, int disp_unit, MPIR_Info * info,
                            MPIR_Comm * comm_ptr, MPIR_Win ** win_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_win_create(base, length, disp_unit, info, comm_ptr, win_p);

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_mpi_win_attach(MPIR_Win * win, void *base, MPI_Aint size)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_win_attach(win, base, size);

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_mpi_win_allocate_shared(MPI_Aint size, int disp_unit, MPIR_Info * info,
                                     MPIR_Comm * comm_ptr, void **baseptr_p, MPIR_Win ** win_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_win_allocate_shared(size, disp_unit, info, comm_ptr, baseptr_p,
                                                        win_p);

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_mpi_win_detach(MPIR_Win * win, const void *base)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_win_detach(win, base);

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_mpi_win_allocate(MPI_Aint size, int disp_unit, MPIR_Info * info, MPIR_Comm * comm,
                              void *baseptr, MPIR_Win ** win_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_win_allocate(size, disp_unit, info, comm, baseptr, win_p);

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_mpi_win_create_dynamic(MPIR_Info * info, MPIR_Comm * comm, MPIR_Win ** win_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_win_create_dynamic(info, comm, win_p);

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_mpi_type_commit_hook(MPIR_Datatype * datatype_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_type_commit_hook(datatype_p);

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_mpi_type_free_hook(MPIR_Datatype * datatype_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_type_free_hook(datatype_p);

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_mpi_op_commit_hook(MPIR_Op * op_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_op_commit_hook(op_p);

    MPIR_FUNC_EXIT;
    return ret;
}

int MPIDI_NM_mpi_op_free_hook(MPIR_Op * op_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_op_free_hook(op_p);

    MPIR_FUNC_EXIT;
    return ret;
}

#endif /* NETMOD_INLINE */
