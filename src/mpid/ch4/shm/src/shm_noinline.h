/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* ** This file is auto-generated, do not edit ** */

#ifndef SHM_NOINLINE_H_INCLUDED
#define SHM_NOINLINE_H_INCLUDED

#include "shm_impl.h"

int MPIDI_SHM_init_local(int *tag_bits);
int MPIDI_SHM_init_world(void);
int MPIDI_SHM_mpi_finalize_hook(void);
int MPIDI_SHM_post_init(void);
int MPIDI_SHM_comm_set_hints(MPIR_Comm * comm_ptr, MPIR_Info * info);
int MPIDI_SHM_mpi_comm_commit_pre_hook(MPIR_Comm * comm);
int MPIDI_SHM_mpi_comm_commit_post_hook(MPIR_Comm * comm);
int MPIDI_SHM_mpi_comm_free_hook(MPIR_Comm * comm);
int MPIDI_SHM_mpi_win_create_hook(MPIR_Win * win);
int MPIDI_SHM_mpi_win_allocate_hook(MPIR_Win * win);
int MPIDI_SHM_mpi_win_allocate_shared_hook(MPIR_Win * win);
int MPIDI_SHM_mpi_win_create_dynamic_hook(MPIR_Win * win);
int MPIDI_SHM_mpi_win_attach_hook(MPIR_Win * win, void *base, MPI_Aint size);
int MPIDI_SHM_mpi_win_detach_hook(MPIR_Win * win, const void *base);
int MPIDI_SHM_mpi_win_free_hook(MPIR_Win * win);
int MPIDI_SHM_mpi_psend_init(const void *buf, int partitions, MPI_Aint count, MPI_Datatype datatype,
                             int rank, int tag, MPIR_Comm * comm, MPIR_Info * info,
                             MPIDI_av_entry_t * av, MPIR_Request ** req_p);
int MPIDI_SHM_mpi_precv_init(void *buf, int partitions, MPI_Aint count, MPI_Datatype datatype,
                             int rank, int tag, MPIR_Comm * comm, MPIR_Info * info,
                             MPIDI_av_entry_t * av, MPIR_Request ** req_p);
void *MPIDI_SHM_mpi_alloc_mem(MPI_Aint size, MPIR_Info * info);
int MPIDI_SHM_mpi_free_mem(void *ptr);
int MPIDI_SHM_mpi_win_set_info(MPIR_Win * win, MPIR_Info * info);
int MPIDI_SHM_mpi_win_get_info(MPIR_Win * win, MPIR_Info ** info_p);
int MPIDI_SHM_mpi_win_free(MPIR_Win ** win_p);
int MPIDI_SHM_mpi_win_create(void *base, MPI_Aint length, int disp_unit, MPIR_Info * info,
                             MPIR_Comm * comm_ptr, MPIR_Win ** win_p);
int MPIDI_SHM_mpi_win_attach(MPIR_Win * win, void *base, MPI_Aint size);
int MPIDI_SHM_mpi_win_allocate_shared(MPI_Aint size, int disp_unit, MPIR_Info * info,
                                      MPIR_Comm * comm_ptr, void **baseptr_p, MPIR_Win ** win_p);
int MPIDI_SHM_mpi_win_detach(MPIR_Win * win, const void *base);
int MPIDI_SHM_mpi_win_allocate(MPI_Aint size, int disp_unit, MPIR_Info * info, MPIR_Comm * comm,
                               void *baseptr, MPIR_Win ** win_p);
int MPIDI_SHM_mpi_win_create_dynamic(MPIR_Info * info, MPIR_Comm * comm, MPIR_Win ** win_p);
int MPIDI_SHM_mpi_type_commit_hook(MPIR_Datatype * type);
int MPIDI_SHM_mpi_type_free_hook(MPIR_Datatype * type);
int MPIDI_SHM_mpi_op_commit_hook(MPIR_Op * op_p);
int MPIDI_SHM_mpi_op_free_hook(MPIR_Op * op_p);

#endif /* SHM_NOINLINE_H_INCLUDED */
