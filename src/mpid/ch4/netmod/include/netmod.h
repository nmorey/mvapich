/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* ** This file is auto-generated, do not edit ** */

#ifndef NETMOD_H_INCLUDED
#define NETMOD_H_INCLUDED

#include <mpidimpl.h>

#define MPIDI_MAX_NETMOD_STRING_LEN 64

typedef union {
#ifdef HAVE_CH4_NETMOD_OFI
    MPIDI_OFI_Global_t ofi;
#endif
#ifdef HAVE_CH4_NETMOD_UCX
    MPIDI_UCX_Global_t ucx;
#endif
} MPIDI_NM_Global_t;

typedef int (*MPIDI_NM_init_local_t) (int *tag_bits);
typedef int (*MPIDI_NM_init_world_t) (void);
typedef int (*MPIDI_NM_mpi_finalize_hook_t) (void);
typedef int (*MPIDI_NM_init_vcis_t) (int num_vcis, int *num_vcis_actual);
typedef int (*MPIDI_NM_post_init_t) (void);
typedef int (*MPIDI_NM_progress_t) (int vci, int *made_progress);
typedef int (*MPIDI_NM_comm_set_hints_t) (MPIR_Comm * comm_ptr, MPIR_Info * info);
typedef int (*MPIDI_NM_am_send_hdr_t) (int rank, MPIR_Comm * comm, int handler_id,
                                       const void *am_hdr, MPI_Aint am_hdr_sz, int src_vci,
                                       int dst_vci);
typedef int (*MPIDI_NM_am_isend_t) (int rank, MPIR_Comm * comm, int handler_id, const void *am_hdr,
                                    MPI_Aint am_hdr_sz, const void *data, MPI_Aint count,
                                    MPI_Datatype datatype, int src_vci, int dst_vci,
                                    MPIR_Request * sreq);
typedef int (*MPIDI_NM_am_send_hdr_reply_t) (MPIR_Comm * comm, int src_rank, int handler_id,
                                             const void *am_hdr, MPI_Aint am_hdr_sz, int src_vci,
                                             int dst_vci);
typedef int (*MPIDI_NM_am_isend_reply_t) (MPIR_Comm * comm, int src_rank, int handler_id,
                                          const void *am_hdr, MPI_Aint am_hdr_sz, const void *data,
                                          MPI_Aint count, MPI_Datatype datatype, int src_vci,
                                          int dst_vci, MPIR_Request * sreq);
typedef MPIDIG_recv_data_copy_cb (*MPIDI_NM_am_get_data_copy_cb_t) (uint32_t attr);
typedef MPI_Aint (*MPIDI_NM_am_hdr_max_sz_t) (void);
typedef MPI_Aint (*MPIDI_NM_am_eager_limit_t) (void);
typedef MPI_Aint (*MPIDI_NM_am_eager_buf_limit_t) (void);
typedef bool (*MPIDI_NM_am_check_eager_t) (MPI_Aint am_hdr_sz, MPI_Aint data_sz, const void *data,
                                           MPI_Aint count, MPI_Datatype datatype,
                                           MPIR_Request * sreq);
typedef bool (*MPIDI_NM_am_can_do_tag_t) (void);
typedef int (*MPIDI_NM_am_tag_send_t) (int rank, MPIR_Comm * comm, int handler_id, int tag,
                                       const void *buf, MPI_Aint count, MPI_Datatype datatype,
                                       int src_vci, int dst_vci, MPIR_Request * sreq);
typedef int (*MPIDI_NM_am_tag_recv_t) (int rank, MPIR_Comm * comm, int handler_id, int tag,
                                       void *buf, MPI_Aint count, MPI_Datatype datatype,
                                       int src_vci, int dst_vci, MPIR_Request * rreq);
typedef int (*MPIDI_NM_comm_get_gpid_t) (MPIR_Comm * comm_ptr, int idx, uint64_t * gpid_ptr,
                                         bool is_remote);
typedef int (*MPIDI_NM_get_local_upids_t) (MPIR_Comm * comm, int **local_upid_size,
                                           char **local_upids);
typedef int (*MPIDI_NM_upids_to_gpids_t) (int size, int *remote_upid_size, char *remote_upids,
                                          uint64_t * remote_gpids);
typedef int (*MPIDI_NM_dynamic_send_t) (uint64_t remote_gpid, int tag, const void *buf, int size,
                                        int timeout);
typedef int (*MPIDI_NM_dynamic_recv_t) (int tag, void *buf, int size, int timeout);
typedef int (*MPIDI_NM_mpi_comm_commit_pre_hook_t) (MPIR_Comm * comm);
typedef int (*MPIDI_NM_mpi_comm_commit_post_hook_t) (MPIR_Comm * comm);
typedef int (*MPIDI_NM_mpi_comm_free_hook_t) (MPIR_Comm * comm);
typedef int (*MPIDI_NM_mpi_win_create_hook_t) (MPIR_Win * win);
typedef int (*MPIDI_NM_mpi_win_allocate_hook_t) (MPIR_Win * win);
typedef int (*MPIDI_NM_mpi_win_allocate_shared_hook_t) (MPIR_Win * win);
typedef int (*MPIDI_NM_mpi_win_create_dynamic_hook_t) (MPIR_Win * win);
typedef int (*MPIDI_NM_mpi_win_attach_hook_t) (MPIR_Win * win, void *base, MPI_Aint size);
typedef int (*MPIDI_NM_mpi_win_detach_hook_t) (MPIR_Win * win, const void *base);
typedef int (*MPIDI_NM_mpi_win_free_hook_t) (MPIR_Win * win);
typedef int (*MPIDI_NM_rma_win_cmpl_hook_t) (MPIR_Win * win);
typedef int (*MPIDI_NM_rma_win_local_cmpl_hook_t) (MPIR_Win * win);
typedef int (*MPIDI_NM_rma_target_cmpl_hook_t) (int rank, MPIR_Win * win);
typedef int (*MPIDI_NM_rma_target_local_cmpl_hook_t) (int rank, MPIR_Win * win);
typedef void (*MPIDI_NM_am_request_init_t) (MPIR_Request * req);
typedef void (*MPIDI_NM_am_request_finalize_t) (MPIR_Request * req);
typedef int (*MPIDI_NM_mpi_isend_t) (const void *buf, MPI_Aint count, MPI_Datatype datatype,
                                     int rank, int tag, MPIR_Comm * comm, int attr,
                                     MPIDI_av_entry_t * addr, MPIR_Request ** req_p);
typedef int (*MPIDI_NM_mpi_cancel_send_t) (MPIR_Request * sreq);
typedef int (*MPIDI_NM_mpi_irecv_t) (void *buf, MPI_Aint count, MPI_Datatype datatype, int rank,
                                     int tag, MPIR_Comm * comm, int attr, MPIDI_av_entry_t * addr,
                                     MPIR_Request ** req_p, MPIR_Request * partner);
typedef int (*MPIDI_NM_mpi_imrecv_t) (void *buf, MPI_Aint count, MPI_Datatype datatype,
                                      MPIR_Request * message);
typedef int (*MPIDI_NM_mpi_cancel_recv_t) (MPIR_Request * rreq, bool is_blocking);
typedef int (*MPIDI_NM_mpi_psend_init_t) (const void *buf, int partitions, MPI_Aint count,
                                          MPI_Datatype datatype, int rank, int tag,
                                          MPIR_Comm * comm, MPIR_Info * info, MPIDI_av_entry_t * av,
                                          MPIR_Request ** req_p);
typedef int (*MPIDI_NM_mpi_precv_init_t) (void *buf, int partitions, MPI_Aint count,
                                          MPI_Datatype datatype, int rank, int tag,
                                          MPIR_Comm * comm, MPIR_Info * info, MPIDI_av_entry_t * av,
                                          MPIR_Request ** req_p);
typedef int (*MPIDI_NM_part_start_t) (MPIR_Request * req);
typedef int (*MPIDI_NM_mpi_pready_range_t) (int partition_low, int partition_high,
                                            MPIR_Request * sreq);
typedef int (*MPIDI_NM_mpi_pready_list_t) (int length, const int array_of_partitions[],
                                           MPIR_Request * sreq);
typedef int (*MPIDI_NM_mpi_parrived_t) (MPIR_Request * rreq, int partition, int *flag);
typedef void *(*MPIDI_NM_mpi_alloc_mem_t) (MPI_Aint size, MPIR_Info * info);
typedef int (*MPIDI_NM_mpi_free_mem_t) (void *ptr);
typedef int (*MPIDI_NM_mpi_improbe_t) (int source, int tag, MPIR_Comm * comm, int attr,
                                       MPIDI_av_entry_t * addr, int *flag,
                                       MPIR_Request ** message_p, MPI_Status * status);
typedef int (*MPIDI_NM_mpi_iprobe_t) (int source, int tag, MPIR_Comm * comm, int attr,
                                      MPIDI_av_entry_t * addr, int *flag, MPI_Status * status);
typedef int (*MPIDI_NM_mpi_win_set_info_t) (MPIR_Win * win, MPIR_Info * info);
typedef int (*MPIDI_NM_mpi_win_shared_query_t) (MPIR_Win * win, int rank, MPI_Aint * size_p,
                                                int *disp_unit_p, void *baseptr);
typedef int (*MPIDI_NM_mpi_put_t) (const void *origin_addr, MPI_Aint origin_count,
                                   MPI_Datatype origin_datatype, int target_rank,
                                   MPI_Aint target_disp, MPI_Aint target_count,
                                   MPI_Datatype target_datatype, MPIR_Win * win,
                                   MPIDI_av_entry_t * addr, MPIDI_winattr_t winattr);
typedef int (*MPIDI_NM_mpi_win_start_t) (MPIR_Group * group, int assert, MPIR_Win * win);
typedef int (*MPIDI_NM_mpi_win_complete_t) (MPIR_Win * win);
typedef int (*MPIDI_NM_mpi_win_post_t) (MPIR_Group * group, int assert, MPIR_Win * win);
typedef int (*MPIDI_NM_mpi_win_wait_t) (MPIR_Win * win);
typedef int (*MPIDI_NM_mpi_win_test_t) (MPIR_Win * win, int *flag);
typedef int (*MPIDI_NM_mpi_win_lock_t) (int lock_type, int rank, int assert, MPIR_Win * win,
                                        MPIDI_av_entry_t * addr);
typedef int (*MPIDI_NM_mpi_win_unlock_t) (int rank, MPIR_Win * win, MPIDI_av_entry_t * addr);
typedef int (*MPIDI_NM_mpi_win_get_info_t) (MPIR_Win * win, MPIR_Info ** info_p);
typedef int (*MPIDI_NM_mpi_get_t) (void *origin_addr, MPI_Aint origin_count,
                                   MPI_Datatype origin_datatype, int target_rank,
                                   MPI_Aint target_disp, MPI_Aint target_count,
                                   MPI_Datatype target_datatype, MPIR_Win * win,
                                   MPIDI_av_entry_t * addr, MPIDI_winattr_t winattr);
typedef int (*MPIDI_NM_mpi_win_free_t) (MPIR_Win ** win_p);
typedef int (*MPIDI_NM_mpi_win_fence_t) (int assert, MPIR_Win * win);
typedef int (*MPIDI_NM_mpi_win_create_t) (void *base, MPI_Aint length, int disp_unit,
                                          MPIR_Info * info, MPIR_Comm * comm_ptr,
                                          MPIR_Win ** win_p);
typedef int (*MPIDI_NM_mpi_accumulate_t) (const void *origin_addr, MPI_Aint origin_count,
                                          MPI_Datatype origin_datatype, int target_rank,
                                          MPI_Aint target_disp, MPI_Aint target_count,
                                          MPI_Datatype target_datatype, MPI_Op op, MPIR_Win * win,
                                          MPIDI_av_entry_t * addr, MPIDI_winattr_t winattr);
typedef int (*MPIDI_NM_mpi_win_attach_t) (MPIR_Win * win, void *base, MPI_Aint size);
typedef int (*MPIDI_NM_mpi_win_allocate_shared_t) (MPI_Aint size, int disp_unit, MPIR_Info * info,
                                                   MPIR_Comm * comm_ptr, void **baseptr_p,
                                                   MPIR_Win ** win_p);
typedef int (*MPIDI_NM_mpi_rput_t) (const void *origin_addr, MPI_Aint origin_count,
                                    MPI_Datatype origin_datatype, int target_rank,
                                    MPI_Aint target_disp, MPI_Aint target_count,
                                    MPI_Datatype target_datatype, MPIR_Win * win,
                                    MPIDI_av_entry_t * addr, MPIDI_winattr_t winattr,
                                    MPIR_Request ** req_p);
typedef int (*MPIDI_NM_mpi_win_flush_local_t) (int rank, MPIR_Win * win, MPIDI_av_entry_t * addr);
typedef int (*MPIDI_NM_mpi_win_detach_t) (MPIR_Win * win, const void *base);
typedef int (*MPIDI_NM_mpi_compare_and_swap_t) (const void *origin_addr, const void *compare_addr,
                                                void *result_addr, MPI_Datatype datatype,
                                                int target_rank, MPI_Aint target_disp,
                                                MPIR_Win * win, MPIDI_av_entry_t * addr,
                                                MPIDI_winattr_t winattr);
typedef int (*MPIDI_NM_mpi_raccumulate_t) (const void *origin_addr, MPI_Aint origin_count,
                                           MPI_Datatype origin_datatype, int target_rank,
                                           MPI_Aint target_disp, MPI_Aint target_count,
                                           MPI_Datatype target_datatype, MPI_Op op, MPIR_Win * win,
                                           MPIDI_av_entry_t * addr, MPIDI_winattr_t winattr,
                                           MPIR_Request ** req_p);
typedef int (*MPIDI_NM_mpi_rget_accumulate_t) (const void *origin_addr, MPI_Aint origin_count,
                                               MPI_Datatype origin_datatype, void *result_addr,
                                               MPI_Aint result_count, MPI_Datatype result_datatype,
                                               int target_rank, MPI_Aint target_disp,
                                               MPI_Aint target_count, MPI_Datatype target_datatype,
                                               MPI_Op op, MPIR_Win * win, MPIDI_av_entry_t * addr,
                                               MPIDI_winattr_t winattr, MPIR_Request ** req_p);
typedef int (*MPIDI_NM_mpi_fetch_and_op_t) (const void *origin_addr, void *result_addr,
                                            MPI_Datatype datatype, int target_rank,
                                            MPI_Aint target_disp, MPI_Op op, MPIR_Win * win,
                                            MPIDI_av_entry_t * addr, MPIDI_winattr_t winattr);
typedef int (*MPIDI_NM_mpi_win_allocate_t) (MPI_Aint size, int disp_unit, MPIR_Info * info,
                                            MPIR_Comm * comm, void *baseptr, MPIR_Win ** win_p);
typedef int (*MPIDI_NM_mpi_win_flush_t) (int rank, MPIR_Win * win, MPIDI_av_entry_t * addr);
typedef int (*MPIDI_NM_mpi_win_flush_local_all_t) (MPIR_Win * win);
typedef int (*MPIDI_NM_mpi_win_unlock_all_t) (MPIR_Win * win);
typedef int (*MPIDI_NM_mpi_win_create_dynamic_t) (MPIR_Info * info, MPIR_Comm * comm,
                                                  MPIR_Win ** win_p);
typedef int (*MPIDI_NM_mpi_rget_t) (void *origin_addr, MPI_Aint origin_count,
                                    MPI_Datatype origin_datatype, int target_rank,
                                    MPI_Aint target_disp, MPI_Aint target_count,
                                    MPI_Datatype target_datatype, MPIR_Win * win,
                                    MPIDI_av_entry_t * addr, MPIDI_winattr_t winattr,
                                    MPIR_Request ** req_p);
typedef int (*MPIDI_NM_mpi_win_sync_t) (MPIR_Win * win);
typedef int (*MPIDI_NM_mpi_win_flush_all_t) (MPIR_Win * win);
typedef int (*MPIDI_NM_mpi_get_accumulate_t) (const void *origin_addr, MPI_Aint origin_count,
                                              MPI_Datatype origin_datatype, void *result_addr,
                                              MPI_Aint result_count, MPI_Datatype result_datatype,
                                              int target_rank, MPI_Aint target_disp,
                                              MPI_Aint target_count, MPI_Datatype target_datatype,
                                              MPI_Op op, MPIR_Win * win, MPIDI_av_entry_t * addr,
                                              MPIDI_winattr_t winattr);
typedef int (*MPIDI_NM_mpi_win_lock_all_t) (int assert, MPIR_Win * win);
typedef int (*MPIDI_NM_rank_is_local_t) (int target, MPIR_Comm * comm);
typedef int (*MPIDI_NM_mpi_barrier_t) (MPIR_Comm * comm, MPIR_Errflag_t errflag);
typedef int (*MPIDI_NM_mpi_bcast_t) (void *buffer, MPI_Aint count, MPI_Datatype datatype, int root,
                                     MPIR_Comm * comm, MPIR_Errflag_t errflag);
typedef int (*MPIDI_NM_mpi_allreduce_t) (const void *sendbuf, void *recvbuf, MPI_Aint count,
                                         MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm,
                                         MPIR_Errflag_t errflag);
typedef int (*MPIDI_NM_mpi_allgather_t) (const void *sendbuf, MPI_Aint sendcount,
                                         MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount,
                                         MPI_Datatype recvtype, MPIR_Comm * comm,
                                         MPIR_Errflag_t errflag);
typedef int (*MPIDI_NM_mpi_allgatherv_t) (const void *sendbuf, MPI_Aint sendcount,
                                          MPI_Datatype sendtype, void *recvbuf,
                                          const MPI_Aint * recvcounts, const MPI_Aint * displs,
                                          MPI_Datatype recvtype, MPIR_Comm * comm,
                                          MPIR_Errflag_t errflag);
typedef int (*MPIDI_NM_mpi_scatter_t) (const void *sendbuf, MPI_Aint sendcount,
                                       MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount,
                                       MPI_Datatype recvtype, int root, MPIR_Comm * comm,
                                       MPIR_Errflag_t errflag);
typedef int (*MPIDI_NM_mpi_scatterv_t) (const void *sendbuf, const MPI_Aint * sendcounts,
                                        const MPI_Aint * displs, MPI_Datatype sendtype,
                                        void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                                        int root, MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
typedef int (*MPIDI_NM_mpi_gather_t) (const void *sendbuf, MPI_Aint sendcount,
                                      MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount,
                                      MPI_Datatype recvtype, int root, MPIR_Comm * comm,
                                      MPIR_Errflag_t errflag);
typedef int (*MPIDI_NM_mpi_gatherv_t) (const void *sendbuf, MPI_Aint sendcount,
                                       MPI_Datatype sendtype, void *recvbuf,
                                       const MPI_Aint * recvcounts, const MPI_Aint * displs,
                                       MPI_Datatype recvtype, int root, MPIR_Comm * comm,
                                       MPIR_Errflag_t errflag);
typedef int (*MPIDI_NM_mpi_alltoall_t) (const void *sendbuf, MPI_Aint sendcount,
                                        MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount,
                                        MPI_Datatype recvtype, MPIR_Comm * comm,
                                        MPIR_Errflag_t errflag);
typedef int (*MPIDI_NM_mpi_alltoallv_t) (const void *sendbuf, const MPI_Aint * sendcounts,
                                         const MPI_Aint * sdispls, MPI_Datatype sendtype,
                                         void *recvbuf, const MPI_Aint * recvcounts,
                                         const MPI_Aint * rdispls, MPI_Datatype recvtype,
                                         MPIR_Comm * comm, MPIR_Errflag_t errflag);
typedef int (*MPIDI_NM_mpi_alltoallw_t) (const void *sendbuf, const MPI_Aint * sendcounts,
                                         const MPI_Aint * sdispls, const MPI_Datatype sendtypes[],
                                         void *recvbuf, const MPI_Aint * recvcounts,
                                         const MPI_Aint * rdispls, const MPI_Datatype recvtypes[],
                                         MPIR_Comm * comm, MPIR_Errflag_t errflag);
typedef int (*MPIDI_NM_mpi_reduce_t) (const void *sendbuf, void *recvbuf, MPI_Aint count,
                                      MPI_Datatype datatype, MPI_Op op, int root,
                                      MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
typedef int (*MPIDI_NM_mpi_reduce_scatter_t) (const void *sendbuf, void *recvbuf,
                                              const MPI_Aint * recvcounts, MPI_Datatype datatype,
                                              MPI_Op op, MPIR_Comm * comm_ptr,
                                              MPIR_Errflag_t errflag);
typedef int (*MPIDI_NM_mpi_reduce_scatter_block_t) (const void *sendbuf, void *recvbuf,
                                                    MPI_Aint recvcount, MPI_Datatype datatype,
                                                    MPI_Op op, MPIR_Comm * comm_ptr,
                                                    MPIR_Errflag_t errflag);
typedef int (*MPIDI_NM_mpi_scan_t) (const void *sendbuf, void *recvbuf, MPI_Aint count,
                                    MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm,
                                    MPIR_Errflag_t errflag);
typedef int (*MPIDI_NM_mpi_exscan_t) (const void *sendbuf, void *recvbuf, MPI_Aint count,
                                      MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm,
                                      MPIR_Errflag_t errflag);
typedef int (*MPIDI_NM_mpi_neighbor_allgather_t) (const void *sendbuf, MPI_Aint sendcount,
                                                  MPI_Datatype sendtype, void *recvbuf,
                                                  MPI_Aint recvcount, MPI_Datatype recvtype,
                                                  MPIR_Comm * comm);
typedef int (*MPIDI_NM_mpi_neighbor_allgatherv_t) (const void *sendbuf, MPI_Aint sendcount,
                                                   MPI_Datatype sendtype, void *recvbuf,
                                                   const MPI_Aint * recvcounts,
                                                   const MPI_Aint * displs, MPI_Datatype recvtype,
                                                   MPIR_Comm * comm);
typedef int (*MPIDI_NM_mpi_neighbor_alltoallv_t) (const void *sendbuf, const MPI_Aint * sendcounts,
                                                  const MPI_Aint * sdispls, MPI_Datatype sendtype,
                                                  void *recvbuf, const MPI_Aint * recvcounts,
                                                  const MPI_Aint * rdispls, MPI_Datatype recvtype,
                                                  MPIR_Comm * comm);
typedef int (*MPIDI_NM_mpi_neighbor_alltoallw_t) (const void *sendbuf, const MPI_Aint * sendcounts,
                                                  const MPI_Aint * sdispls,
                                                  const MPI_Datatype sendtypes[], void *recvbuf,
                                                  const MPI_Aint * recvcounts,
                                                  const MPI_Aint * rdispls,
                                                  const MPI_Datatype recvtypes[], MPIR_Comm * comm);
typedef int (*MPIDI_NM_mpi_neighbor_alltoall_t) (const void *sendbuf, MPI_Aint sendcount,
                                                 MPI_Datatype sendtype, void *recvbuf,
                                                 MPI_Aint recvcount, MPI_Datatype recvtype,
                                                 MPIR_Comm * comm);
typedef int (*MPIDI_NM_mpi_ineighbor_allgather_t) (const void *sendbuf, MPI_Aint sendcount,
                                                   MPI_Datatype sendtype, void *recvbuf,
                                                   MPI_Aint recvcount, MPI_Datatype recvtype,
                                                   MPIR_Comm * comm, MPIR_Request ** req_p);
typedef int (*MPIDI_NM_mpi_ineighbor_allgatherv_t) (const void *sendbuf, MPI_Aint sendcount,
                                                    MPI_Datatype sendtype, void *recvbuf,
                                                    const MPI_Aint * recvcounts,
                                                    const MPI_Aint * displs, MPI_Datatype recvtype,
                                                    MPIR_Comm * comm, MPIR_Request ** req_p);
typedef int (*MPIDI_NM_mpi_ineighbor_alltoall_t) (const void *sendbuf, MPI_Aint sendcount,
                                                  MPI_Datatype sendtype, void *recvbuf,
                                                  MPI_Aint recvcount, MPI_Datatype recvtype,
                                                  MPIR_Comm * comm, MPIR_Request ** req_p);
typedef int (*MPIDI_NM_mpi_ineighbor_alltoallv_t) (const void *sendbuf, const MPI_Aint * sendcounts,
                                                   const MPI_Aint * sdispls, MPI_Datatype sendtype,
                                                   void *recvbuf, const MPI_Aint * recvcounts,
                                                   const MPI_Aint * rdispls, MPI_Datatype recvtype,
                                                   MPIR_Comm * comm, MPIR_Request ** req_p);
typedef int (*MPIDI_NM_mpi_ineighbor_alltoallw_t) (const void *sendbuf, const MPI_Aint * sendcounts,
                                                   const MPI_Aint * sdispls,
                                                   const MPI_Datatype sendtypes[], void *recvbuf,
                                                   const MPI_Aint * recvcounts,
                                                   const MPI_Aint * rdispls,
                                                   const MPI_Datatype recvtypes[], MPIR_Comm * comm,
                                                   MPIR_Request ** req_p);
typedef int (*MPIDI_NM_mpi_ibarrier_t) (MPIR_Comm * comm, MPIR_Request ** req_p);
typedef int (*MPIDI_NM_mpi_ibcast_t) (void *buffer, MPI_Aint count, MPI_Datatype datatype, int root,
                                      MPIR_Comm * comm, MPIR_Request ** req_p);
typedef int (*MPIDI_NM_mpi_iallgather_t) (const void *sendbuf, MPI_Aint sendcount,
                                          MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount,
                                          MPI_Datatype recvtype, MPIR_Comm * comm,
                                          MPIR_Request ** req_p);
typedef int (*MPIDI_NM_mpi_iallgatherv_t) (const void *sendbuf, MPI_Aint sendcount,
                                           MPI_Datatype sendtype, void *recvbuf,
                                           const MPI_Aint * recvcounts, const MPI_Aint * displs,
                                           MPI_Datatype recvtype, MPIR_Comm * comm,
                                           MPIR_Request ** req_p);
typedef int (*MPIDI_NM_mpi_iallreduce_t) (const void *sendbuf, void *recvbuf, MPI_Aint count,
                                          MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm,
                                          MPIR_Request ** req_p);
typedef int (*MPIDI_NM_mpi_ialltoall_t) (const void *sendbuf, MPI_Aint sendcount,
                                         MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount,
                                         MPI_Datatype recvtype, MPIR_Comm * comm,
                                         MPIR_Request ** req_p);
typedef int (*MPIDI_NM_mpi_ialltoallv_t) (const void *sendbuf, const MPI_Aint * sendcounts,
                                          const MPI_Aint * sdispls, MPI_Datatype sendtype,
                                          void *recvbuf, const MPI_Aint * recvcounts,
                                          const MPI_Aint * rdispls, MPI_Datatype recvtype,
                                          MPIR_Comm * comm, MPIR_Request ** req_p);
typedef int (*MPIDI_NM_mpi_ialltoallw_t) (const void *sendbuf, const MPI_Aint * sendcounts,
                                          const MPI_Aint * sdispls, const MPI_Datatype sendtypes[],
                                          void *recvbuf, const MPI_Aint * recvcounts,
                                          const MPI_Aint * rdispls, const MPI_Datatype recvtypes[],
                                          MPIR_Comm * comm, MPIR_Request ** req_p);
typedef int (*MPIDI_NM_mpi_iexscan_t) (const void *sendbuf, void *recvbuf, MPI_Aint count,
                                       MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm,
                                       MPIR_Request ** req_p);
typedef int (*MPIDI_NM_mpi_igather_t) (const void *sendbuf, MPI_Aint sendcount,
                                       MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount,
                                       MPI_Datatype recvtype, int root, MPIR_Comm * comm,
                                       MPIR_Request ** req_p);
typedef int (*MPIDI_NM_mpi_igatherv_t) (const void *sendbuf, MPI_Aint sendcount,
                                        MPI_Datatype sendtype, void *recvbuf,
                                        const MPI_Aint * recvcounts, const MPI_Aint * displs,
                                        MPI_Datatype recvtype, int root, MPIR_Comm * comm,
                                        MPIR_Request ** req_p);
typedef int (*MPIDI_NM_mpi_ireduce_scatter_block_t) (const void *sendbuf, void *recvbuf,
                                                     MPI_Aint recvcount, MPI_Datatype datatype,
                                                     MPI_Op op, MPIR_Comm * comm,
                                                     MPIR_Request ** req_p);
typedef int (*MPIDI_NM_mpi_ireduce_scatter_t) (const void *sendbuf, void *recvbuf,
                                               const MPI_Aint * recvcounts, MPI_Datatype datatype,
                                               MPI_Op op, MPIR_Comm * comm, MPIR_Request ** req_p);
typedef int (*MPIDI_NM_mpi_ireduce_t) (const void *sendbuf, void *recvbuf, MPI_Aint count,
                                       MPI_Datatype datatype, MPI_Op op, int root,
                                       MPIR_Comm * comm_ptr, MPIR_Request ** req_p);
typedef int (*MPIDI_NM_mpi_iscan_t) (const void *sendbuf, void *recvbuf, MPI_Aint count,
                                     MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm,
                                     MPIR_Request ** req_p);
typedef int (*MPIDI_NM_mpi_iscatter_t) (const void *sendbuf, MPI_Aint sendcount,
                                        MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount,
                                        MPI_Datatype recvtype, int root, MPIR_Comm * comm,
                                        MPIR_Request ** req_p);
typedef int (*MPIDI_NM_mpi_iscatterv_t) (const void *sendbuf, const MPI_Aint * sendcounts,
                                         const MPI_Aint * displs, MPI_Datatype sendtype,
                                         void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                                         int root, MPIR_Comm * comm_ptr, MPIR_Request ** req_p);
typedef int (*MPIDI_NM_mpi_type_commit_hook_t) (MPIR_Datatype * datatype_p);
typedef int (*MPIDI_NM_mpi_type_free_hook_t) (MPIR_Datatype * datatype_p);
typedef int (*MPIDI_NM_mpi_op_commit_hook_t) (MPIR_Op * op_p);
typedef int (*MPIDI_NM_mpi_op_free_hook_t) (MPIR_Op * op_p);

typedef struct MPIDI_NM_funcs {
    MPIDI_NM_init_local_t init_local;
    MPIDI_NM_init_world_t init_world;
    MPIDI_NM_mpi_finalize_hook_t mpi_finalize_hook;
    MPIDI_NM_init_vcis_t init_vcis;
    MPIDI_NM_post_init_t post_init;
    MPIDI_NM_progress_t progress;
    MPIDI_NM_comm_set_hints_t comm_set_hints;
    MPIDI_NM_am_send_hdr_t am_send_hdr;
    MPIDI_NM_am_isend_t am_isend;
    MPIDI_NM_am_send_hdr_reply_t am_send_hdr_reply;
    MPIDI_NM_am_isend_reply_t am_isend_reply;
    MPIDI_NM_am_get_data_copy_cb_t am_get_data_copy_cb;
    MPIDI_NM_am_hdr_max_sz_t am_hdr_max_sz;
    MPIDI_NM_am_eager_limit_t am_eager_limit;
    MPIDI_NM_am_eager_buf_limit_t am_eager_buf_limit;
    MPIDI_NM_am_check_eager_t am_check_eager;
    MPIDI_NM_am_can_do_tag_t am_can_do_tag;
    MPIDI_NM_am_tag_send_t am_tag_send;
    MPIDI_NM_am_tag_recv_t am_tag_recv;
    MPIDI_NM_comm_get_gpid_t comm_get_gpid;
    MPIDI_NM_get_local_upids_t get_local_upids;
    MPIDI_NM_upids_to_gpids_t upids_to_gpids;
    MPIDI_NM_dynamic_send_t dynamic_send;
    MPIDI_NM_dynamic_recv_t dynamic_recv;
    MPIDI_NM_mpi_comm_commit_pre_hook_t mpi_comm_commit_pre_hook;
    MPIDI_NM_mpi_comm_commit_post_hook_t mpi_comm_commit_post_hook;
    MPIDI_NM_mpi_comm_free_hook_t mpi_comm_free_hook;
    MPIDI_NM_mpi_win_create_hook_t mpi_win_create_hook;
    MPIDI_NM_mpi_win_allocate_hook_t mpi_win_allocate_hook;
    MPIDI_NM_mpi_win_allocate_shared_hook_t mpi_win_allocate_shared_hook;
    MPIDI_NM_mpi_win_create_dynamic_hook_t mpi_win_create_dynamic_hook;
    MPIDI_NM_mpi_win_attach_hook_t mpi_win_attach_hook;
    MPIDI_NM_mpi_win_detach_hook_t mpi_win_detach_hook;
    MPIDI_NM_mpi_win_free_hook_t mpi_win_free_hook;
    MPIDI_NM_rma_win_cmpl_hook_t rma_win_cmpl_hook;
    MPIDI_NM_rma_win_local_cmpl_hook_t rma_win_local_cmpl_hook;
    MPIDI_NM_rma_target_cmpl_hook_t rma_target_cmpl_hook;
    MPIDI_NM_rma_target_local_cmpl_hook_t rma_target_local_cmpl_hook;
    MPIDI_NM_am_request_init_t am_request_init;
    MPIDI_NM_am_request_finalize_t am_request_finalize;
} MPIDI_NM_funcs_t;

typedef struct MPIDI_NM_native_funcs {
    MPIDI_NM_mpi_isend_t mpi_isend;
    MPIDI_NM_mpi_cancel_send_t mpi_cancel_send;
    MPIDI_NM_mpi_irecv_t mpi_irecv;
    MPIDI_NM_mpi_imrecv_t mpi_imrecv;
    MPIDI_NM_mpi_cancel_recv_t mpi_cancel_recv;
    MPIDI_NM_mpi_psend_init_t mpi_psend_init;
    MPIDI_NM_mpi_precv_init_t mpi_precv_init;
    MPIDI_NM_part_start_t part_start;
    MPIDI_NM_mpi_pready_range_t mpi_pready_range;
    MPIDI_NM_mpi_pready_list_t mpi_pready_list;
    MPIDI_NM_mpi_parrived_t mpi_parrived;
    MPIDI_NM_mpi_alloc_mem_t mpi_alloc_mem;
    MPIDI_NM_mpi_free_mem_t mpi_free_mem;
    MPIDI_NM_mpi_improbe_t mpi_improbe;
    MPIDI_NM_mpi_iprobe_t mpi_iprobe;
    MPIDI_NM_mpi_win_set_info_t mpi_win_set_info;
    MPIDI_NM_mpi_win_shared_query_t mpi_win_shared_query;
    MPIDI_NM_mpi_put_t mpi_put;
    MPIDI_NM_mpi_win_start_t mpi_win_start;
    MPIDI_NM_mpi_win_complete_t mpi_win_complete;
    MPIDI_NM_mpi_win_post_t mpi_win_post;
    MPIDI_NM_mpi_win_wait_t mpi_win_wait;
    MPIDI_NM_mpi_win_test_t mpi_win_test;
    MPIDI_NM_mpi_win_lock_t mpi_win_lock;
    MPIDI_NM_mpi_win_unlock_t mpi_win_unlock;
    MPIDI_NM_mpi_win_get_info_t mpi_win_get_info;
    MPIDI_NM_mpi_get_t mpi_get;
    MPIDI_NM_mpi_win_free_t mpi_win_free;
    MPIDI_NM_mpi_win_fence_t mpi_win_fence;
    MPIDI_NM_mpi_win_create_t mpi_win_create;
    MPIDI_NM_mpi_accumulate_t mpi_accumulate;
    MPIDI_NM_mpi_win_attach_t mpi_win_attach;
    MPIDI_NM_mpi_win_allocate_shared_t mpi_win_allocate_shared;
    MPIDI_NM_mpi_rput_t mpi_rput;
    MPIDI_NM_mpi_win_flush_local_t mpi_win_flush_local;
    MPIDI_NM_mpi_win_detach_t mpi_win_detach;
    MPIDI_NM_mpi_compare_and_swap_t mpi_compare_and_swap;
    MPIDI_NM_mpi_raccumulate_t mpi_raccumulate;
    MPIDI_NM_mpi_rget_accumulate_t mpi_rget_accumulate;
    MPIDI_NM_mpi_fetch_and_op_t mpi_fetch_and_op;
    MPIDI_NM_mpi_win_allocate_t mpi_win_allocate;
    MPIDI_NM_mpi_win_flush_t mpi_win_flush;
    MPIDI_NM_mpi_win_flush_local_all_t mpi_win_flush_local_all;
    MPIDI_NM_mpi_win_unlock_all_t mpi_win_unlock_all;
    MPIDI_NM_mpi_win_create_dynamic_t mpi_win_create_dynamic;
    MPIDI_NM_mpi_rget_t mpi_rget;
    MPIDI_NM_mpi_win_sync_t mpi_win_sync;
    MPIDI_NM_mpi_win_flush_all_t mpi_win_flush_all;
    MPIDI_NM_mpi_get_accumulate_t mpi_get_accumulate;
    MPIDI_NM_mpi_win_lock_all_t mpi_win_lock_all;
    MPIDI_NM_rank_is_local_t rank_is_local;
    MPIDI_NM_mpi_barrier_t mpi_barrier;
    MPIDI_NM_mpi_bcast_t mpi_bcast;
    MPIDI_NM_mpi_allreduce_t mpi_allreduce;
    MPIDI_NM_mpi_allgather_t mpi_allgather;
    MPIDI_NM_mpi_allgatherv_t mpi_allgatherv;
    MPIDI_NM_mpi_scatter_t mpi_scatter;
    MPIDI_NM_mpi_scatterv_t mpi_scatterv;
    MPIDI_NM_mpi_gather_t mpi_gather;
    MPIDI_NM_mpi_gatherv_t mpi_gatherv;
    MPIDI_NM_mpi_alltoall_t mpi_alltoall;
    MPIDI_NM_mpi_alltoallv_t mpi_alltoallv;
    MPIDI_NM_mpi_alltoallw_t mpi_alltoallw;
    MPIDI_NM_mpi_reduce_t mpi_reduce;
    MPIDI_NM_mpi_reduce_scatter_t mpi_reduce_scatter;
    MPIDI_NM_mpi_reduce_scatter_block_t mpi_reduce_scatter_block;
    MPIDI_NM_mpi_scan_t mpi_scan;
    MPIDI_NM_mpi_exscan_t mpi_exscan;
    MPIDI_NM_mpi_neighbor_allgather_t mpi_neighbor_allgather;
    MPIDI_NM_mpi_neighbor_allgatherv_t mpi_neighbor_allgatherv;
    MPIDI_NM_mpi_neighbor_alltoallv_t mpi_neighbor_alltoallv;
    MPIDI_NM_mpi_neighbor_alltoallw_t mpi_neighbor_alltoallw;
    MPIDI_NM_mpi_neighbor_alltoall_t mpi_neighbor_alltoall;
    MPIDI_NM_mpi_ineighbor_allgather_t mpi_ineighbor_allgather;
    MPIDI_NM_mpi_ineighbor_allgatherv_t mpi_ineighbor_allgatherv;
    MPIDI_NM_mpi_ineighbor_alltoall_t mpi_ineighbor_alltoall;
    MPIDI_NM_mpi_ineighbor_alltoallv_t mpi_ineighbor_alltoallv;
    MPIDI_NM_mpi_ineighbor_alltoallw_t mpi_ineighbor_alltoallw;
    MPIDI_NM_mpi_ibarrier_t mpi_ibarrier;
    MPIDI_NM_mpi_ibcast_t mpi_ibcast;
    MPIDI_NM_mpi_iallgather_t mpi_iallgather;
    MPIDI_NM_mpi_iallgatherv_t mpi_iallgatherv;
    MPIDI_NM_mpi_iallreduce_t mpi_iallreduce;
    MPIDI_NM_mpi_ialltoall_t mpi_ialltoall;
    MPIDI_NM_mpi_ialltoallv_t mpi_ialltoallv;
    MPIDI_NM_mpi_ialltoallw_t mpi_ialltoallw;
    MPIDI_NM_mpi_iexscan_t mpi_iexscan;
    MPIDI_NM_mpi_igather_t mpi_igather;
    MPIDI_NM_mpi_igatherv_t mpi_igatherv;
    MPIDI_NM_mpi_ireduce_scatter_block_t mpi_ireduce_scatter_block;
    MPIDI_NM_mpi_ireduce_scatter_t mpi_ireduce_scatter;
    MPIDI_NM_mpi_ireduce_t mpi_ireduce;
    MPIDI_NM_mpi_iscan_t mpi_iscan;
    MPIDI_NM_mpi_iscatter_t mpi_iscatter;
    MPIDI_NM_mpi_iscatterv_t mpi_iscatterv;
    MPIDI_NM_mpi_type_commit_hook_t mpi_type_commit_hook;
    MPIDI_NM_mpi_type_free_hook_t mpi_type_free_hook;
    MPIDI_NM_mpi_op_commit_hook_t mpi_op_commit_hook;
    MPIDI_NM_mpi_op_free_hook_t mpi_op_free_hook;
} MPIDI_NM_native_funcs_t;

extern MPIDI_NM_funcs_t *MPIDI_NM_funcs[];
extern MPIDI_NM_funcs_t *MPIDI_NM_func;
extern MPIDI_NM_native_funcs_t *MPIDI_NM_native_funcs[];
extern MPIDI_NM_native_funcs_t *MPIDI_NM_native_func;
extern int MPIDI_num_netmods;
extern char MPIDI_NM_strings[][MPIDI_MAX_NETMOD_STRING_LEN];

int MPIDI_NM_init_local(int *tag_bits);
int MPIDI_NM_init_world(void);
int MPIDI_NM_mpi_finalize_hook(void);
int MPIDI_NM_init_vcis(int num_vcis, int *num_vcis_actual);
int MPIDI_NM_post_init(void);
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_progress(int vci,
                                               int *made_progress) MPL_STATIC_INLINE_SUFFIX;
int MPIDI_NM_comm_set_hints(MPIR_Comm * comm_ptr, MPIR_Info * info);
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_am_send_hdr(int rank, MPIR_Comm * comm, int handler_id,
                                                  const void *am_hdr, MPI_Aint am_hdr_sz,
                                                  int src_vci,
                                                  int dst_vci) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_am_isend(int rank, MPIR_Comm * comm, int handler_id,
                                               const void *am_hdr, MPI_Aint am_hdr_sz,
                                               const void *data, MPI_Aint count,
                                               MPI_Datatype datatype, int src_vci, int dst_vci,
                                               MPIR_Request * sreq) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_am_send_hdr_reply(MPIR_Comm * comm, int src_rank,
                                                        int handler_id, const void *am_hdr,
                                                        MPI_Aint am_hdr_sz, int src_vci,
                                                        int dst_vci) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_am_isend_reply(MPIR_Comm * comm, int src_rank, int handler_id,
                                                     const void *am_hdr, MPI_Aint am_hdr_sz,
                                                     const void *data, MPI_Aint count,
                                                     MPI_Datatype datatype, int src_vci,
                                                     int dst_vci,
                                                     MPIR_Request * sreq) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX MPIDIG_recv_data_copy_cb MPIDI_NM_am_get_data_copy_cb(uint32_t attr)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX MPI_Aint MPIDI_NM_am_hdr_max_sz(void) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX MPI_Aint MPIDI_NM_am_eager_limit(void) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX MPI_Aint MPIDI_NM_am_eager_buf_limit(void) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX bool MPIDI_NM_am_check_eager(MPI_Aint am_hdr_sz, MPI_Aint data_sz,
                                                      const void *data, MPI_Aint count,
                                                      MPI_Datatype datatype,
                                                      MPIR_Request * sreq) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX bool MPIDI_NM_am_can_do_tag(void) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_am_tag_send(int rank, MPIR_Comm * comm, int handler_id,
                                                  int tag, const void *buf, MPI_Aint count,
                                                  MPI_Datatype datatype, int src_vci, int dst_vci,
                                                  MPIR_Request * sreq) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_am_tag_recv(int rank, MPIR_Comm * comm, int handler_id,
                                                  int tag, void *buf, MPI_Aint count,
                                                  MPI_Datatype datatype, int src_vci, int dst_vci,
                                                  MPIR_Request * rreq) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_comm_get_gpid(MPIR_Comm * comm_ptr, int idx,
                                                    uint64_t * gpid_ptr,
                                                    bool is_remote) MPL_STATIC_INLINE_SUFFIX;
int MPIDI_NM_get_local_upids(MPIR_Comm * comm, int **local_upid_size, char **local_upids);
int MPIDI_NM_upids_to_gpids(int size, int *remote_upid_size, char *remote_upids,
                            uint64_t * remote_gpids);
int MPIDI_NM_dynamic_send(uint64_t remote_gpid, int tag, const void *buf, int size, int timeout);
int MPIDI_NM_dynamic_recv(int tag, void *buf, int size, int timeout);
int MPIDI_NM_mpi_comm_commit_pre_hook(MPIR_Comm * comm);
int MPIDI_NM_mpi_comm_commit_post_hook(MPIR_Comm * comm);
int MPIDI_NM_mpi_comm_free_hook(MPIR_Comm * comm);
int MPIDI_NM_mpi_win_create_hook(MPIR_Win * win);
int MPIDI_NM_mpi_win_allocate_hook(MPIR_Win * win);
int MPIDI_NM_mpi_win_allocate_shared_hook(MPIR_Win * win);
int MPIDI_NM_mpi_win_create_dynamic_hook(MPIR_Win * win);
int MPIDI_NM_mpi_win_attach_hook(MPIR_Win * win, void *base, MPI_Aint size);
int MPIDI_NM_mpi_win_detach_hook(MPIR_Win * win, const void *base);
int MPIDI_NM_mpi_win_free_hook(MPIR_Win * win);
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_rma_win_cmpl_hook(MPIR_Win * win) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_rma_win_local_cmpl_hook(MPIR_Win * win)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_rma_target_cmpl_hook(int rank,
                                                           MPIR_Win * win) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_rma_target_local_cmpl_hook(int rank,
                                                                 MPIR_Win * win)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX void MPIDI_NM_am_request_init(MPIR_Request * req) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX void MPIDI_NM_am_request_finalize(MPIR_Request * req)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_isend(const void *buf, MPI_Aint count,
                                                MPI_Datatype datatype, int rank, int tag,
                                                MPIR_Comm * comm, int attr, MPIDI_av_entry_t * addr,
                                                MPIR_Request ** req_p) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_cancel_send(MPIR_Request * sreq) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_irecv(void *buf, MPI_Aint count, MPI_Datatype datatype,
                                                int rank, int tag, MPIR_Comm * comm, int attr,
                                                MPIDI_av_entry_t * addr, MPIR_Request ** req_p,
                                                MPIR_Request * partner) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_imrecv(void *buf, MPI_Aint count, MPI_Datatype datatype,
                                                 MPIR_Request * message) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_cancel_recv(MPIR_Request * rreq,
                                                      bool is_blocking) MPL_STATIC_INLINE_SUFFIX;
int MPIDI_NM_mpi_psend_init(const void *buf, int partitions, MPI_Aint count, MPI_Datatype datatype,
                            int rank, int tag, MPIR_Comm * comm, MPIR_Info * info,
                            MPIDI_av_entry_t * av, MPIR_Request ** req_p);
int MPIDI_NM_mpi_precv_init(void *buf, int partitions, MPI_Aint count, MPI_Datatype datatype,
                            int rank, int tag, MPIR_Comm * comm, MPIR_Info * info,
                            MPIDI_av_entry_t * av, MPIR_Request ** req_p);
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_part_start(MPIR_Request * req) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_pready_range(int partition_low, int partition_high,
                                                       MPIR_Request * sreq)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_pready_list(int length, const int array_of_partitions[],
                                                      MPIR_Request * sreq) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_parrived(MPIR_Request * rreq, int partition,
                                                   int *flag) MPL_STATIC_INLINE_SUFFIX;
void *MPIDI_NM_mpi_alloc_mem(MPI_Aint size, MPIR_Info * info);
int MPIDI_NM_mpi_free_mem(void *ptr);
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_improbe(int source, int tag, MPIR_Comm * comm, int attr,
                                                  MPIDI_av_entry_t * addr, int *flag,
                                                  MPIR_Request ** message_p,
                                                  MPI_Status * status) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_iprobe(int source, int tag, MPIR_Comm * comm, int attr,
                                                 MPIDI_av_entry_t * addr, int *flag,
                                                 MPI_Status * status) MPL_STATIC_INLINE_SUFFIX;
int MPIDI_NM_mpi_win_set_info(MPIR_Win * win, MPIR_Info * info);
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_win_shared_query(MPIR_Win * win, int rank,
                                                           MPI_Aint * size_p, int *disp_unit_p,
                                                           void *baseptr) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_put(const void *origin_addr, MPI_Aint origin_count,
                                              MPI_Datatype origin_datatype, int target_rank,
                                              MPI_Aint target_disp, MPI_Aint target_count,
                                              MPI_Datatype target_datatype, MPIR_Win * win,
                                              MPIDI_av_entry_t * addr,
                                              MPIDI_winattr_t winattr) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_win_start(MPIR_Group * group, int assert,
                                                    MPIR_Win * win) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_win_complete(MPIR_Win * win) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_win_post(MPIR_Group * group, int assert,
                                                   MPIR_Win * win) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_win_wait(MPIR_Win * win) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_win_test(MPIR_Win * win,
                                                   int *flag) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_win_lock(int lock_type, int rank, int assert,
                                                   MPIR_Win * win,
                                                   MPIDI_av_entry_t * addr)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_win_unlock(int rank, MPIR_Win * win,
                                                     MPIDI_av_entry_t * addr)
    MPL_STATIC_INLINE_SUFFIX;
int MPIDI_NM_mpi_win_get_info(MPIR_Win * win, MPIR_Info ** info_p);
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_get(void *origin_addr, MPI_Aint origin_count,
                                              MPI_Datatype origin_datatype, int target_rank,
                                              MPI_Aint target_disp, MPI_Aint target_count,
                                              MPI_Datatype target_datatype, MPIR_Win * win,
                                              MPIDI_av_entry_t * addr,
                                              MPIDI_winattr_t winattr) MPL_STATIC_INLINE_SUFFIX;
int MPIDI_NM_mpi_win_free(MPIR_Win ** win_p);
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_win_fence(int assert,
                                                    MPIR_Win * win) MPL_STATIC_INLINE_SUFFIX;
int MPIDI_NM_mpi_win_create(void *base, MPI_Aint length, int disp_unit, MPIR_Info * info,
                            MPIR_Comm * comm_ptr, MPIR_Win ** win_p);
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_accumulate(const void *origin_addr, MPI_Aint origin_count,
                                                     MPI_Datatype origin_datatype, int target_rank,
                                                     MPI_Aint target_disp, MPI_Aint target_count,
                                                     MPI_Datatype target_datatype, MPI_Op op,
                                                     MPIR_Win * win, MPIDI_av_entry_t * addr,
                                                     MPIDI_winattr_t winattr)
    MPL_STATIC_INLINE_SUFFIX;
int MPIDI_NM_mpi_win_attach(MPIR_Win * win, void *base, MPI_Aint size);
int MPIDI_NM_mpi_win_allocate_shared(MPI_Aint size, int disp_unit, MPIR_Info * info,
                                     MPIR_Comm * comm_ptr, void **baseptr_p, MPIR_Win ** win_p);
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_rput(const void *origin_addr, MPI_Aint origin_count,
                                               MPI_Datatype origin_datatype, int target_rank,
                                               MPI_Aint target_disp, MPI_Aint target_count,
                                               MPI_Datatype target_datatype, MPIR_Win * win,
                                               MPIDI_av_entry_t * addr, MPIDI_winattr_t winattr,
                                               MPIR_Request ** req_p) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_win_flush_local(int rank, MPIR_Win * win,
                                                          MPIDI_av_entry_t * addr)
    MPL_STATIC_INLINE_SUFFIX;
int MPIDI_NM_mpi_win_detach(MPIR_Win * win, const void *base);
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_compare_and_swap(const void *origin_addr,
                                                           const void *compare_addr,
                                                           void *result_addr, MPI_Datatype datatype,
                                                           int target_rank, MPI_Aint target_disp,
                                                           MPIR_Win * win, MPIDI_av_entry_t * addr,
                                                           MPIDI_winattr_t winattr)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_raccumulate(const void *origin_addr,
                                                      MPI_Aint origin_count,
                                                      MPI_Datatype origin_datatype, int target_rank,
                                                      MPI_Aint target_disp, MPI_Aint target_count,
                                                      MPI_Datatype target_datatype, MPI_Op op,
                                                      MPIR_Win * win, MPIDI_av_entry_t * addr,
                                                      MPIDI_winattr_t winattr,
                                                      MPIR_Request ** req_p)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_rget_accumulate(const void *origin_addr,
                                                          MPI_Aint origin_count,
                                                          MPI_Datatype origin_datatype,
                                                          void *result_addr, MPI_Aint result_count,
                                                          MPI_Datatype result_datatype,
                                                          int target_rank, MPI_Aint target_disp,
                                                          MPI_Aint target_count,
                                                          MPI_Datatype target_datatype, MPI_Op op,
                                                          MPIR_Win * win, MPIDI_av_entry_t * addr,
                                                          MPIDI_winattr_t winattr,
                                                          MPIR_Request ** req_p)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_fetch_and_op(const void *origin_addr, void *result_addr,
                                                       MPI_Datatype datatype, int target_rank,
                                                       MPI_Aint target_disp, MPI_Op op,
                                                       MPIR_Win * win, MPIDI_av_entry_t * addr,
                                                       MPIDI_winattr_t winattr)
    MPL_STATIC_INLINE_SUFFIX;
int MPIDI_NM_mpi_win_allocate(MPI_Aint size, int disp_unit, MPIR_Info * info, MPIR_Comm * comm,
                              void *baseptr, MPIR_Win ** win_p);
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_win_flush(int rank, MPIR_Win * win,
                                                    MPIDI_av_entry_t * addr)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_win_flush_local_all(MPIR_Win * win)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_win_unlock_all(MPIR_Win * win) MPL_STATIC_INLINE_SUFFIX;
int MPIDI_NM_mpi_win_create_dynamic(MPIR_Info * info, MPIR_Comm * comm, MPIR_Win ** win_p);
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_rget(void *origin_addr, MPI_Aint origin_count,
                                               MPI_Datatype origin_datatype, int target_rank,
                                               MPI_Aint target_disp, MPI_Aint target_count,
                                               MPI_Datatype target_datatype, MPIR_Win * win,
                                               MPIDI_av_entry_t * addr, MPIDI_winattr_t winattr,
                                               MPIR_Request ** req_p) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_win_sync(MPIR_Win * win) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_win_flush_all(MPIR_Win * win) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_get_accumulate(const void *origin_addr,
                                                         MPI_Aint origin_count,
                                                         MPI_Datatype origin_datatype,
                                                         void *result_addr, MPI_Aint result_count,
                                                         MPI_Datatype result_datatype,
                                                         int target_rank, MPI_Aint target_disp,
                                                         MPI_Aint target_count,
                                                         MPI_Datatype target_datatype, MPI_Op op,
                                                         MPIR_Win * win, MPIDI_av_entry_t * addr,
                                                         MPIDI_winattr_t winattr)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_win_lock_all(int assert,
                                                       MPIR_Win * win) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_rank_is_local(int target,
                                                    MPIR_Comm * comm) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_barrier(MPIR_Comm * comm,
                                                  MPIR_Errflag_t errflag) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_bcast(void *buffer, MPI_Aint count, MPI_Datatype datatype,
                                                int root, MPIR_Comm * comm,
                                                MPIR_Errflag_t errflag) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_allreduce(const void *sendbuf, void *recvbuf,
                                                    MPI_Aint count, MPI_Datatype datatype,
                                                    MPI_Op op, MPIR_Comm * comm,
                                                    MPIR_Errflag_t errflag)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_allgather(const void *sendbuf, MPI_Aint sendcount,
                                                    MPI_Datatype sendtype, void *recvbuf,
                                                    MPI_Aint recvcount, MPI_Datatype recvtype,
                                                    MPIR_Comm * comm,
                                                    MPIR_Errflag_t errflag)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_allgatherv(const void *sendbuf, MPI_Aint sendcount,
                                                     MPI_Datatype sendtype, void *recvbuf,
                                                     const MPI_Aint * recvcounts,
                                                     const MPI_Aint * displs, MPI_Datatype recvtype,
                                                     MPIR_Comm * comm,
                                                     MPIR_Errflag_t errflag)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_scatter(const void *sendbuf, MPI_Aint sendcount,
                                                  MPI_Datatype sendtype, void *recvbuf,
                                                  MPI_Aint recvcount, MPI_Datatype recvtype,
                                                  int root, MPIR_Comm * comm,
                                                  MPIR_Errflag_t errflag) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_scatterv(const void *sendbuf, const MPI_Aint * sendcounts,
                                                   const MPI_Aint * displs, MPI_Datatype sendtype,
                                                   void *recvbuf, MPI_Aint recvcount,
                                                   MPI_Datatype recvtype, int root,
                                                   MPIR_Comm * comm_ptr,
                                                   MPIR_Errflag_t errflag) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_gather(const void *sendbuf, MPI_Aint sendcount,
                                                 MPI_Datatype sendtype, void *recvbuf,
                                                 MPI_Aint recvcount, MPI_Datatype recvtype,
                                                 int root, MPIR_Comm * comm,
                                                 MPIR_Errflag_t errflag) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_gatherv(const void *sendbuf, MPI_Aint sendcount,
                                                  MPI_Datatype sendtype, void *recvbuf,
                                                  const MPI_Aint * recvcounts,
                                                  const MPI_Aint * displs, MPI_Datatype recvtype,
                                                  int root, MPIR_Comm * comm,
                                                  MPIR_Errflag_t errflag) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_alltoall(const void *sendbuf, MPI_Aint sendcount,
                                                   MPI_Datatype sendtype, void *recvbuf,
                                                   MPI_Aint recvcount, MPI_Datatype recvtype,
                                                   MPIR_Comm * comm,
                                                   MPIR_Errflag_t errflag) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_alltoallv(const void *sendbuf,
                                                    const MPI_Aint * sendcounts,
                                                    const MPI_Aint * sdispls, MPI_Datatype sendtype,
                                                    void *recvbuf, const MPI_Aint * recvcounts,
                                                    const MPI_Aint * rdispls, MPI_Datatype recvtype,
                                                    MPIR_Comm * comm,
                                                    MPIR_Errflag_t errflag)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_alltoallw(const void *sendbuf,
                                                    const MPI_Aint * sendcounts,
                                                    const MPI_Aint * sdispls,
                                                    const MPI_Datatype sendtypes[], void *recvbuf,
                                                    const MPI_Aint * recvcounts,
                                                    const MPI_Aint * rdispls,
                                                    const MPI_Datatype recvtypes[],
                                                    MPIR_Comm * comm,
                                                    MPIR_Errflag_t errflag)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_reduce(const void *sendbuf, void *recvbuf, MPI_Aint count,
                                                 MPI_Datatype datatype, MPI_Op op, int root,
                                                 MPIR_Comm * comm_ptr,
                                                 MPIR_Errflag_t errflag) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_reduce_scatter(const void *sendbuf, void *recvbuf,
                                                         const MPI_Aint * recvcounts,
                                                         MPI_Datatype datatype, MPI_Op op,
                                                         MPIR_Comm * comm_ptr,
                                                         MPIR_Errflag_t errflag)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_reduce_scatter_block(const void *sendbuf, void *recvbuf,
                                                               MPI_Aint recvcount,
                                                               MPI_Datatype datatype, MPI_Op op,
                                                               MPIR_Comm * comm_ptr,
                                                               MPIR_Errflag_t errflag)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_scan(const void *sendbuf, void *recvbuf, MPI_Aint count,
                                               MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm,
                                               MPIR_Errflag_t errflag) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_exscan(const void *sendbuf, void *recvbuf, MPI_Aint count,
                                                 MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm,
                                                 MPIR_Errflag_t errflag) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_neighbor_allgather(const void *sendbuf,
                                                             MPI_Aint sendcount,
                                                             MPI_Datatype sendtype, void *recvbuf,
                                                             MPI_Aint recvcount,
                                                             MPI_Datatype recvtype,
                                                             MPIR_Comm * comm)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_neighbor_allgatherv(const void *sendbuf,
                                                              MPI_Aint sendcount,
                                                              MPI_Datatype sendtype, void *recvbuf,
                                                              const MPI_Aint * recvcounts,
                                                              const MPI_Aint * displs,
                                                              MPI_Datatype recvtype,
                                                              MPIR_Comm * comm)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_neighbor_alltoallv(const void *sendbuf,
                                                             const MPI_Aint * sendcounts,
                                                             const MPI_Aint * sdispls,
                                                             MPI_Datatype sendtype, void *recvbuf,
                                                             const MPI_Aint * recvcounts,
                                                             const MPI_Aint * rdispls,
                                                             MPI_Datatype recvtype,
                                                             MPIR_Comm * comm)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_neighbor_alltoallw(const void *sendbuf,
                                                             const MPI_Aint * sendcounts,
                                                             const MPI_Aint * sdispls,
                                                             const MPI_Datatype sendtypes[],
                                                             void *recvbuf,
                                                             const MPI_Aint * recvcounts,
                                                             const MPI_Aint * rdispls,
                                                             const MPI_Datatype recvtypes[],
                                                             MPIR_Comm * comm)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_neighbor_alltoall(const void *sendbuf, MPI_Aint sendcount,
                                                            MPI_Datatype sendtype, void *recvbuf,
                                                            MPI_Aint recvcount,
                                                            MPI_Datatype recvtype,
                                                            MPIR_Comm * comm)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_ineighbor_allgather(const void *sendbuf,
                                                              MPI_Aint sendcount,
                                                              MPI_Datatype sendtype, void *recvbuf,
                                                              MPI_Aint recvcount,
                                                              MPI_Datatype recvtype,
                                                              MPIR_Comm * comm,
                                                              MPIR_Request ** req_p)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_ineighbor_allgatherv(const void *sendbuf,
                                                               MPI_Aint sendcount,
                                                               MPI_Datatype sendtype, void *recvbuf,
                                                               const MPI_Aint * recvcounts,
                                                               const MPI_Aint * displs,
                                                               MPI_Datatype recvtype,
                                                               MPIR_Comm * comm,
                                                               MPIR_Request ** req_p)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_ineighbor_alltoall(const void *sendbuf,
                                                             MPI_Aint sendcount,
                                                             MPI_Datatype sendtype, void *recvbuf,
                                                             MPI_Aint recvcount,
                                                             MPI_Datatype recvtype,
                                                             MPIR_Comm * comm,
                                                             MPIR_Request ** req_p)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_ineighbor_alltoallv(const void *sendbuf,
                                                              const MPI_Aint * sendcounts,
                                                              const MPI_Aint * sdispls,
                                                              MPI_Datatype sendtype, void *recvbuf,
                                                              const MPI_Aint * recvcounts,
                                                              const MPI_Aint * rdispls,
                                                              MPI_Datatype recvtype,
                                                              MPIR_Comm * comm,
                                                              MPIR_Request ** req_p)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_ineighbor_alltoallw(const void *sendbuf,
                                                              const MPI_Aint * sendcounts,
                                                              const MPI_Aint * sdispls,
                                                              const MPI_Datatype sendtypes[],
                                                              void *recvbuf,
                                                              const MPI_Aint * recvcounts,
                                                              const MPI_Aint * rdispls,
                                                              const MPI_Datatype recvtypes[],
                                                              MPIR_Comm * comm,
                                                              MPIR_Request ** req_p)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_ibarrier(MPIR_Comm * comm,
                                                   MPIR_Request ** req_p) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_ibcast(void *buffer, MPI_Aint count,
                                                 MPI_Datatype datatype, int root, MPIR_Comm * comm,
                                                 MPIR_Request ** req_p) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_iallgather(const void *sendbuf, MPI_Aint sendcount,
                                                     MPI_Datatype sendtype, void *recvbuf,
                                                     MPI_Aint recvcount, MPI_Datatype recvtype,
                                                     MPIR_Comm * comm,
                                                     MPIR_Request ** req_p)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_iallgatherv(const void *sendbuf, MPI_Aint sendcount,
                                                      MPI_Datatype sendtype, void *recvbuf,
                                                      const MPI_Aint * recvcounts,
                                                      const MPI_Aint * displs,
                                                      MPI_Datatype recvtype, MPIR_Comm * comm,
                                                      MPIR_Request ** req_p)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_iallreduce(const void *sendbuf, void *recvbuf,
                                                     MPI_Aint count, MPI_Datatype datatype,
                                                     MPI_Op op, MPIR_Comm * comm,
                                                     MPIR_Request ** req_p)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_ialltoall(const void *sendbuf, MPI_Aint sendcount,
                                                    MPI_Datatype sendtype, void *recvbuf,
                                                    MPI_Aint recvcount, MPI_Datatype recvtype,
                                                    MPIR_Comm * comm,
                                                    MPIR_Request ** req_p) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_ialltoallv(const void *sendbuf,
                                                     const MPI_Aint * sendcounts,
                                                     const MPI_Aint * sdispls,
                                                     MPI_Datatype sendtype, void *recvbuf,
                                                     const MPI_Aint * recvcounts,
                                                     const MPI_Aint * rdispls,
                                                     MPI_Datatype recvtype, MPIR_Comm * comm,
                                                     MPIR_Request ** req_p)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_ialltoallw(const void *sendbuf,
                                                     const MPI_Aint * sendcounts,
                                                     const MPI_Aint * sdispls,
                                                     const MPI_Datatype sendtypes[], void *recvbuf,
                                                     const MPI_Aint * recvcounts,
                                                     const MPI_Aint * rdispls,
                                                     const MPI_Datatype recvtypes[],
                                                     MPIR_Comm * comm,
                                                     MPIR_Request ** req_p)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_iexscan(const void *sendbuf, void *recvbuf,
                                                  MPI_Aint count, MPI_Datatype datatype, MPI_Op op,
                                                  MPIR_Comm * comm,
                                                  MPIR_Request ** req_p) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_igather(const void *sendbuf, MPI_Aint sendcount,
                                                  MPI_Datatype sendtype, void *recvbuf,
                                                  MPI_Aint recvcount, MPI_Datatype recvtype,
                                                  int root, MPIR_Comm * comm,
                                                  MPIR_Request ** req_p) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_igatherv(const void *sendbuf, MPI_Aint sendcount,
                                                   MPI_Datatype sendtype, void *recvbuf,
                                                   const MPI_Aint * recvcounts,
                                                   const MPI_Aint * displs, MPI_Datatype recvtype,
                                                   int root, MPIR_Comm * comm,
                                                   MPIR_Request ** req_p) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_ireduce_scatter_block(const void *sendbuf, void *recvbuf,
                                                                MPI_Aint recvcount,
                                                                MPI_Datatype datatype, MPI_Op op,
                                                                MPIR_Comm * comm,
                                                                MPIR_Request ** req_p)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_ireduce_scatter(const void *sendbuf, void *recvbuf,
                                                          const MPI_Aint * recvcounts,
                                                          MPI_Datatype datatype, MPI_Op op,
                                                          MPIR_Comm * comm,
                                                          MPIR_Request ** req_p)
    MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_ireduce(const void *sendbuf, void *recvbuf,
                                                  MPI_Aint count, MPI_Datatype datatype, MPI_Op op,
                                                  int root, MPIR_Comm * comm_ptr,
                                                  MPIR_Request ** req_p) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_iscan(const void *sendbuf, void *recvbuf, MPI_Aint count,
                                                MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm,
                                                MPIR_Request ** req_p) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_iscatter(const void *sendbuf, MPI_Aint sendcount,
                                                   MPI_Datatype sendtype, void *recvbuf,
                                                   MPI_Aint recvcount, MPI_Datatype recvtype,
                                                   int root, MPIR_Comm * comm,
                                                   MPIR_Request ** req_p) MPL_STATIC_INLINE_SUFFIX;
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_iscatterv(const void *sendbuf,
                                                    const MPI_Aint * sendcounts,
                                                    const MPI_Aint * displs, MPI_Datatype sendtype,
                                                    void *recvbuf, MPI_Aint recvcount,
                                                    MPI_Datatype recvtype, int root,
                                                    MPIR_Comm * comm_ptr,
                                                    MPIR_Request ** req_p) MPL_STATIC_INLINE_SUFFIX;
int MPIDI_NM_mpi_type_commit_hook(MPIR_Datatype * datatype_p);
int MPIDI_NM_mpi_type_free_hook(MPIR_Datatype * datatype_p);
int MPIDI_NM_mpi_op_commit_hook(MPIR_Op * op_p);
int MPIDI_NM_mpi_op_free_hook(MPIR_Op * op_p);

#endif /* NETMOD_H_INCLUDED */
