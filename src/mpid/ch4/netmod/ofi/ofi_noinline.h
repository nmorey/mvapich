/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* ** This file is auto-generated, do not edit ** */

#ifndef OFI_NOINLINE_H_INCLUDED
#define OFI_NOINLINE_H_INCLUDED

#include "ofi_impl.h"

int MPIDI_OFI_init_local(int *tag_bits);
int MPIDI_OFI_init_world(void);
int MPIDI_OFI_mpi_finalize_hook(void);
int MPIDI_OFI_init_vcis(int num_vcis, int *num_vcis_actual);
int MPIDI_OFI_post_init(void);
int MPIDI_OFI_comm_set_hints(MPIR_Comm * comm_ptr, MPIR_Info * info);
int MPIDI_OFI_get_local_upids(MPIR_Comm * comm, int **local_upid_size, char **local_upids);
int MPIDI_OFI_upids_to_gpids(int size, int *remote_upid_size, char *remote_upids,
                             uint64_t * remote_gpids);
int MPIDI_OFI_dynamic_send(uint64_t remote_gpid, int tag, const void *buf, int size, int timeout);
int MPIDI_OFI_dynamic_recv(int tag, void *buf, int size, int timeout);
int MPIDI_OFI_mpi_comm_commit_pre_hook(MPIR_Comm * comm);
int MPIDI_OFI_mpi_comm_commit_post_hook(MPIR_Comm * comm);
int MPIDI_OFI_mpi_comm_free_hook(MPIR_Comm * comm);
int MPIDI_OFI_mpi_win_create_hook(MPIR_Win * win);
int MPIDI_OFI_mpi_win_allocate_hook(MPIR_Win * win);
int MPIDI_OFI_mpi_win_allocate_shared_hook(MPIR_Win * win);
int MPIDI_OFI_mpi_win_create_dynamic_hook(MPIR_Win * win);
int MPIDI_OFI_mpi_win_attach_hook(MPIR_Win * win, void *base, MPI_Aint size);
int MPIDI_OFI_mpi_win_detach_hook(MPIR_Win * win, const void *base);
int MPIDI_OFI_mpi_win_free_hook(MPIR_Win * win);
int MPIDI_OFI_mpi_psend_init(const void *buf, int partitions, MPI_Aint count, MPI_Datatype datatype,
                             int rank, int tag, MPIR_Comm * comm, MPIR_Info * info,
                             MPIDI_av_entry_t * av, MPIR_Request ** req_p);
int MPIDI_OFI_mpi_precv_init(void *buf, int partitions, MPI_Aint count, MPI_Datatype datatype,
                             int rank, int tag, MPIR_Comm * comm, MPIR_Info * info,
                             MPIDI_av_entry_t * av, MPIR_Request ** req_p);
void *MPIDI_OFI_mpi_alloc_mem(MPI_Aint size, MPIR_Info * info);
int MPIDI_OFI_mpi_free_mem(void *ptr);
int MPIDI_OFI_mpi_win_set_info(MPIR_Win * win, MPIR_Info * info);
int MPIDI_OFI_mpi_win_get_info(MPIR_Win * win, MPIR_Info ** info_p);
int MPIDI_OFI_mpi_win_free(MPIR_Win ** win_p);
int MPIDI_OFI_mpi_win_create(void *base, MPI_Aint length, int disp_unit, MPIR_Info * info,
                             MPIR_Comm * comm_ptr, MPIR_Win ** win_p);
int MPIDI_OFI_mpi_win_attach(MPIR_Win * win, void *base, MPI_Aint size);
int MPIDI_OFI_mpi_win_allocate_shared(MPI_Aint size, int disp_unit, MPIR_Info * info,
                                      MPIR_Comm * comm_ptr, void **baseptr_p, MPIR_Win ** win_p);
int MPIDI_OFI_mpi_win_detach(MPIR_Win * win, const void *base);
int MPIDI_OFI_mpi_win_allocate(MPI_Aint size, int disp_unit, MPIR_Info * info, MPIR_Comm * comm,
                               void *baseptr, MPIR_Win ** win_p);
int MPIDI_OFI_mpi_win_create_dynamic(MPIR_Info * info, MPIR_Comm * comm, MPIR_Win ** win_p);
int MPIDI_OFI_mpi_type_commit_hook(MPIR_Datatype * datatype_p);
int MPIDI_OFI_mpi_type_free_hook(MPIR_Datatype * datatype_p);
int MPIDI_OFI_mpi_op_commit_hook(MPIR_Op * op_p);
int MPIDI_OFI_mpi_op_free_hook(MPIR_Op * op_p);

#ifdef NETMOD_INLINE
#define MPIDI_NM_init_local MPIDI_OFI_init_local
#define MPIDI_NM_init_world MPIDI_OFI_init_world
#define MPIDI_NM_mpi_finalize_hook MPIDI_OFI_mpi_finalize_hook
#define MPIDI_NM_init_vcis MPIDI_OFI_init_vcis
#define MPIDI_NM_post_init MPIDI_OFI_post_init
#define MPIDI_NM_comm_set_hints MPIDI_OFI_comm_set_hints
#define MPIDI_NM_get_local_upids MPIDI_OFI_get_local_upids
#define MPIDI_NM_upids_to_gpids MPIDI_OFI_upids_to_gpids
#define MPIDI_NM_dynamic_send MPIDI_OFI_dynamic_send
#define MPIDI_NM_dynamic_recv MPIDI_OFI_dynamic_recv
#define MPIDI_NM_mpi_comm_commit_pre_hook MPIDI_OFI_mpi_comm_commit_pre_hook
#define MPIDI_NM_mpi_comm_commit_post_hook MPIDI_OFI_mpi_comm_commit_post_hook
#define MPIDI_NM_mpi_comm_free_hook MPIDI_OFI_mpi_comm_free_hook
#define MPIDI_NM_mpi_win_create_hook MPIDI_OFI_mpi_win_create_hook
#define MPIDI_NM_mpi_win_allocate_hook MPIDI_OFI_mpi_win_allocate_hook
#define MPIDI_NM_mpi_win_allocate_shared_hook MPIDI_OFI_mpi_win_allocate_shared_hook
#define MPIDI_NM_mpi_win_create_dynamic_hook MPIDI_OFI_mpi_win_create_dynamic_hook
#define MPIDI_NM_mpi_win_attach_hook MPIDI_OFI_mpi_win_attach_hook
#define MPIDI_NM_mpi_win_detach_hook MPIDI_OFI_mpi_win_detach_hook
#define MPIDI_NM_mpi_win_free_hook MPIDI_OFI_mpi_win_free_hook
#define MPIDI_NM_mpi_psend_init MPIDI_OFI_mpi_psend_init
#define MPIDI_NM_mpi_precv_init MPIDI_OFI_mpi_precv_init
#define MPIDI_NM_mpi_alloc_mem MPIDI_OFI_mpi_alloc_mem
#define MPIDI_NM_mpi_free_mem MPIDI_OFI_mpi_free_mem
#define MPIDI_NM_mpi_win_set_info MPIDI_OFI_mpi_win_set_info
#define MPIDI_NM_mpi_win_get_info MPIDI_OFI_mpi_win_get_info
#define MPIDI_NM_mpi_win_free MPIDI_OFI_mpi_win_free
#define MPIDI_NM_mpi_win_create MPIDI_OFI_mpi_win_create
#define MPIDI_NM_mpi_win_attach MPIDI_OFI_mpi_win_attach
#define MPIDI_NM_mpi_win_allocate_shared MPIDI_OFI_mpi_win_allocate_shared
#define MPIDI_NM_mpi_win_detach MPIDI_OFI_mpi_win_detach
#define MPIDI_NM_mpi_win_allocate MPIDI_OFI_mpi_win_allocate
#define MPIDI_NM_mpi_win_create_dynamic MPIDI_OFI_mpi_win_create_dynamic
#define MPIDI_NM_mpi_type_commit_hook MPIDI_OFI_mpi_type_commit_hook
#define MPIDI_NM_mpi_type_free_hook MPIDI_OFI_mpi_type_free_hook
#define MPIDI_NM_mpi_op_commit_hook MPIDI_OFI_mpi_op_commit_hook
#define MPIDI_NM_mpi_op_free_hook MPIDI_OFI_mpi_op_free_hook
#endif /* NETMOD_INLINE */

#endif /* OFI_NOINLINE_H_INCLUDED */
