/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* ** This file is auto-generated, do not edit ** */

#ifndef NETMOD_IMPL_H_INCLUDED
#define NETMOD_IMPL_H_INCLUDED

#ifndef NETMOD_INLINE
#ifndef NETMOD_DISABLE_INLINES
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_progress(int vci, int *made_progress)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->progress(vci, made_progress);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_am_send_hdr(int rank, MPIR_Comm * comm, int handler_id,
                                                  const void *am_hdr, MPI_Aint am_hdr_sz,
                                                  int src_vci, int dst_vci)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->am_send_hdr(rank, comm, handler_id, am_hdr, am_hdr_sz, src_vci, dst_vci);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_am_isend(int rank, MPIR_Comm * comm, int handler_id,
                                               const void *am_hdr, MPI_Aint am_hdr_sz,
                                               const void *data, MPI_Aint count,
                                               MPI_Datatype datatype, int src_vci, int dst_vci,
                                               MPIR_Request * sreq)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->am_isend(rank, comm, handler_id, am_hdr, am_hdr_sz, data, count, datatype,
                                  src_vci, dst_vci, sreq);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_am_send_hdr_reply(MPIR_Comm * comm, int src_rank,
                                                        int handler_id, const void *am_hdr,
                                                        MPI_Aint am_hdr_sz, int src_vci,
                                                        int dst_vci)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->am_send_hdr_reply(comm, src_rank, handler_id, am_hdr, am_hdr_sz, src_vci,
                                           dst_vci);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_am_isend_reply(MPIR_Comm * comm, int src_rank, int handler_id,
                                                     const void *am_hdr, MPI_Aint am_hdr_sz,
                                                     const void *data, MPI_Aint count,
                                                     MPI_Datatype datatype, int src_vci,
                                                     int dst_vci, MPIR_Request * sreq)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->am_isend_reply(comm, src_rank, handler_id, am_hdr, am_hdr_sz, data, count,
                                        datatype, src_vci, dst_vci, sreq);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX MPIDIG_recv_data_copy_cb MPIDI_NM_am_get_data_copy_cb(uint32_t attr)
{
    MPIDIG_recv_data_copy_cb ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->am_get_data_copy_cb(attr);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX MPI_Aint MPIDI_NM_am_hdr_max_sz(void)
{
    MPI_Aint ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->am_hdr_max_sz();

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX MPI_Aint MPIDI_NM_am_eager_limit(void)
{
    MPI_Aint ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->am_eager_limit();

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX MPI_Aint MPIDI_NM_am_eager_buf_limit(void)
{
    MPI_Aint ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->am_eager_buf_limit();

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX bool MPIDI_NM_am_check_eager(MPI_Aint am_hdr_sz, MPI_Aint data_sz,
                                                      const void *data, MPI_Aint count,
                                                      MPI_Datatype datatype, MPIR_Request * sreq)
{
    bool ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->am_check_eager(am_hdr_sz, data_sz, data, count, datatype, sreq);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX bool MPIDI_NM_am_can_do_tag(void)
{
    bool ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->am_can_do_tag();

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_am_tag_send(int rank, MPIR_Comm * comm, int handler_id,
                                                  int tag, const void *buf, MPI_Aint count,
                                                  MPI_Datatype datatype, int src_vci, int dst_vci,
                                                  MPIR_Request * sreq)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->am_tag_send(rank, comm, handler_id, tag, buf, count, datatype, src_vci,
                                     dst_vci, sreq);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_am_tag_recv(int rank, MPIR_Comm * comm, int handler_id,
                                                  int tag, void *buf, MPI_Aint count,
                                                  MPI_Datatype datatype, int src_vci, int dst_vci,
                                                  MPIR_Request * rreq)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->am_tag_recv(rank, comm, handler_id, tag, buf, count, datatype, src_vci,
                                     dst_vci, rreq);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_comm_get_gpid(MPIR_Comm * comm_ptr, int idx,
                                                    uint64_t * gpid_ptr, bool is_remote)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->comm_get_gpid(comm_ptr, idx, gpid_ptr, is_remote);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_rma_win_cmpl_hook(MPIR_Win * win)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->rma_win_cmpl_hook(win);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_rma_win_local_cmpl_hook(MPIR_Win * win)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->rma_win_local_cmpl_hook(win);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_rma_target_cmpl_hook(int rank, MPIR_Win * win)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->rma_target_cmpl_hook(rank, win);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_rma_target_local_cmpl_hook(int rank, MPIR_Win * win)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_func->rma_target_local_cmpl_hook(rank, win);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX void MPIDI_NM_am_request_init(MPIR_Request * req)
{
    MPIR_FUNC_ENTER;

    MPIDI_NM_func->am_request_init(req);

    MPIR_FUNC_EXIT;
}

MPL_STATIC_INLINE_PREFIX void MPIDI_NM_am_request_finalize(MPIR_Request * req)
{
    MPIR_FUNC_ENTER;

    MPIDI_NM_func->am_request_finalize(req);

    MPIR_FUNC_EXIT;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_isend(const void *buf, MPI_Aint count,
                                                MPI_Datatype datatype, int rank, int tag,
                                                MPIR_Comm * comm, int attr, MPIDI_av_entry_t * addr,
                                                MPIR_Request ** req_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_isend(buf, count, datatype, rank, tag, comm, attr, addr, req_p);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_cancel_send(MPIR_Request * sreq)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_cancel_send(sreq);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_irecv(void *buf, MPI_Aint count, MPI_Datatype datatype,
                                                int rank, int tag, MPIR_Comm * comm, int attr,
                                                MPIDI_av_entry_t * addr, MPIR_Request ** req_p,
                                                MPIR_Request * partner)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_irecv(buf, count, datatype, rank, tag, comm, attr, addr, req_p,
                                          partner);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_imrecv(void *buf, MPI_Aint count, MPI_Datatype datatype,
                                                 MPIR_Request * message)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_imrecv(buf, count, datatype, message);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_cancel_recv(MPIR_Request * rreq, bool is_blocking)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_cancel_recv(rreq, is_blocking);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_part_start(MPIR_Request * req)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->part_start(req);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_pready_range(int partition_low, int partition_high,
                                                       MPIR_Request * sreq)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_pready_range(partition_low, partition_high, sreq);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_pready_list(int length, const int array_of_partitions[],
                                                      MPIR_Request * sreq)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_pready_list(length, array_of_partitions, sreq);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_parrived(MPIR_Request * rreq, int partition, int *flag)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_parrived(rreq, partition, flag);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_improbe(int source, int tag, MPIR_Comm * comm, int attr,
                                                  MPIDI_av_entry_t * addr, int *flag,
                                                  MPIR_Request ** message_p, MPI_Status * status)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_improbe(source, tag, comm, attr, addr, flag, message_p, status);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_iprobe(int source, int tag, MPIR_Comm * comm, int attr,
                                                 MPIDI_av_entry_t * addr, int *flag,
                                                 MPI_Status * status)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_iprobe(source, tag, comm, attr, addr, flag, status);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_win_shared_query(MPIR_Win * win, int rank,
                                                           MPI_Aint * size_p, int *disp_unit_p,
                                                           void *baseptr)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_win_shared_query(win, rank, size_p, disp_unit_p, baseptr);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_put(const void *origin_addr, MPI_Aint origin_count,
                                              MPI_Datatype origin_datatype, int target_rank,
                                              MPI_Aint target_disp, MPI_Aint target_count,
                                              MPI_Datatype target_datatype, MPIR_Win * win,
                                              MPIDI_av_entry_t * addr, MPIDI_winattr_t winattr)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_put(origin_addr, origin_count, origin_datatype, target_rank,
                                        target_disp, target_count, target_datatype, win, addr,
                                        winattr);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_win_start(MPIR_Group * group, int assert, MPIR_Win * win)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_win_start(group, assert, win);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_win_complete(MPIR_Win * win)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_win_complete(win);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_win_post(MPIR_Group * group, int assert, MPIR_Win * win)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_win_post(group, assert, win);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_win_wait(MPIR_Win * win)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_win_wait(win);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_win_test(MPIR_Win * win, int *flag)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_win_test(win, flag);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_win_lock(int lock_type, int rank, int assert,
                                                   MPIR_Win * win, MPIDI_av_entry_t * addr)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_win_lock(lock_type, rank, assert, win, addr);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_win_unlock(int rank, MPIR_Win * win,
                                                     MPIDI_av_entry_t * addr)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_win_unlock(rank, win, addr);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_get(void *origin_addr, MPI_Aint origin_count,
                                              MPI_Datatype origin_datatype, int target_rank,
                                              MPI_Aint target_disp, MPI_Aint target_count,
                                              MPI_Datatype target_datatype, MPIR_Win * win,
                                              MPIDI_av_entry_t * addr, MPIDI_winattr_t winattr)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_get(origin_addr, origin_count, origin_datatype, target_rank,
                                        target_disp, target_count, target_datatype, win, addr,
                                        winattr);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_win_fence(int assert, MPIR_Win * win)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_win_fence(assert, win);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_accumulate(const void *origin_addr, MPI_Aint origin_count,
                                                     MPI_Datatype origin_datatype, int target_rank,
                                                     MPI_Aint target_disp, MPI_Aint target_count,
                                                     MPI_Datatype target_datatype, MPI_Op op,
                                                     MPIR_Win * win, MPIDI_av_entry_t * addr,
                                                     MPIDI_winattr_t winattr)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_accumulate(origin_addr, origin_count, origin_datatype,
                                               target_rank, target_disp, target_count,
                                               target_datatype, op, win, addr, winattr);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_rput(const void *origin_addr, MPI_Aint origin_count,
                                               MPI_Datatype origin_datatype, int target_rank,
                                               MPI_Aint target_disp, MPI_Aint target_count,
                                               MPI_Datatype target_datatype, MPIR_Win * win,
                                               MPIDI_av_entry_t * addr, MPIDI_winattr_t winattr,
                                               MPIR_Request ** req_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_rput(origin_addr, origin_count, origin_datatype, target_rank,
                                         target_disp, target_count, target_datatype, win, addr,
                                         winattr, req_p);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_win_flush_local(int rank, MPIR_Win * win,
                                                          MPIDI_av_entry_t * addr)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_win_flush_local(rank, win, addr);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_compare_and_swap(const void *origin_addr,
                                                           const void *compare_addr,
                                                           void *result_addr, MPI_Datatype datatype,
                                                           int target_rank, MPI_Aint target_disp,
                                                           MPIR_Win * win, MPIDI_av_entry_t * addr,
                                                           MPIDI_winattr_t winattr)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_compare_and_swap(origin_addr, compare_addr, result_addr,
                                                     datatype, target_rank, target_disp, win, addr,
                                                     winattr);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_raccumulate(const void *origin_addr,
                                                      MPI_Aint origin_count,
                                                      MPI_Datatype origin_datatype, int target_rank,
                                                      MPI_Aint target_disp, MPI_Aint target_count,
                                                      MPI_Datatype target_datatype, MPI_Op op,
                                                      MPIR_Win * win, MPIDI_av_entry_t * addr,
                                                      MPIDI_winattr_t winattr,
                                                      MPIR_Request ** req_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_raccumulate(origin_addr, origin_count, origin_datatype,
                                                target_rank, target_disp, target_count,
                                                target_datatype, op, win, addr, winattr, req_p);

    MPIR_FUNC_EXIT;
    return ret;
}

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
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_rget_accumulate(origin_addr, origin_count, origin_datatype,
                                                    result_addr, result_count, result_datatype,
                                                    target_rank, target_disp, target_count,
                                                    target_datatype, op, win, addr, winattr, req_p);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_fetch_and_op(const void *origin_addr, void *result_addr,
                                                       MPI_Datatype datatype, int target_rank,
                                                       MPI_Aint target_disp, MPI_Op op,
                                                       MPIR_Win * win, MPIDI_av_entry_t * addr,
                                                       MPIDI_winattr_t winattr)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_fetch_and_op(origin_addr, result_addr, datatype, target_rank,
                                                 target_disp, op, win, addr, winattr);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_win_flush(int rank, MPIR_Win * win,
                                                    MPIDI_av_entry_t * addr)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_win_flush(rank, win, addr);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_win_flush_local_all(MPIR_Win * win)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_win_flush_local_all(win);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_win_unlock_all(MPIR_Win * win)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_win_unlock_all(win);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_rget(void *origin_addr, MPI_Aint origin_count,
                                               MPI_Datatype origin_datatype, int target_rank,
                                               MPI_Aint target_disp, MPI_Aint target_count,
                                               MPI_Datatype target_datatype, MPIR_Win * win,
                                               MPIDI_av_entry_t * addr, MPIDI_winattr_t winattr,
                                               MPIR_Request ** req_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_rget(origin_addr, origin_count, origin_datatype, target_rank,
                                         target_disp, target_count, target_datatype, win, addr,
                                         winattr, req_p);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_win_sync(MPIR_Win * win)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_win_sync(win);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_win_flush_all(MPIR_Win * win)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_win_flush_all(win);

    MPIR_FUNC_EXIT;
    return ret;
}

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
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_get_accumulate(origin_addr, origin_count, origin_datatype,
                                                   result_addr, result_count, result_datatype,
                                                   target_rank, target_disp, target_count,
                                                   target_datatype, op, win, addr, winattr);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_win_lock_all(int assert, MPIR_Win * win)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_win_lock_all(assert, win);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_rank_is_local(int target, MPIR_Comm * comm)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->rank_is_local(target, comm);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_barrier(MPIR_Comm * comm, MPIR_Errflag_t errflag)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_barrier(comm, errflag);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_bcast(void *buffer, MPI_Aint count, MPI_Datatype datatype,
                                                int root, MPIR_Comm * comm, MPIR_Errflag_t errflag)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_bcast(buffer, count, datatype, root, comm, errflag);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_allreduce(const void *sendbuf, void *recvbuf,
                                                    MPI_Aint count, MPI_Datatype datatype,
                                                    MPI_Op op, MPIR_Comm * comm,
                                                    MPIR_Errflag_t errflag)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_allreduce(sendbuf, recvbuf, count, datatype, op, comm, errflag);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_allgather(const void *sendbuf, MPI_Aint sendcount,
                                                    MPI_Datatype sendtype, void *recvbuf,
                                                    MPI_Aint recvcount, MPI_Datatype recvtype,
                                                    MPIR_Comm * comm, MPIR_Errflag_t errflag)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                              recvtype, comm, errflag);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_allgatherv(const void *sendbuf, MPI_Aint sendcount,
                                                     MPI_Datatype sendtype, void *recvbuf,
                                                     const MPI_Aint * recvcounts,
                                                     const MPI_Aint * displs, MPI_Datatype recvtype,
                                                     MPIR_Comm * comm, MPIR_Errflag_t errflag)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts,
                                               displs, recvtype, comm, errflag);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_scatter(const void *sendbuf, MPI_Aint sendcount,
                                                  MPI_Datatype sendtype, void *recvbuf,
                                                  MPI_Aint recvcount, MPI_Datatype recvtype,
                                                  int root, MPIR_Comm * comm,
                                                  MPIR_Errflag_t errflag)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_scatter(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                            recvtype, root, comm, errflag);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_scatterv(const void *sendbuf, const MPI_Aint * sendcounts,
                                                   const MPI_Aint * displs, MPI_Datatype sendtype,
                                                   void *recvbuf, MPI_Aint recvcount,
                                                   MPI_Datatype recvtype, int root,
                                                   MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_scatterv(sendbuf, sendcounts, displs, sendtype, recvbuf,
                                             recvcount, recvtype, root, comm_ptr, errflag);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_gather(const void *sendbuf, MPI_Aint sendcount,
                                                 MPI_Datatype sendtype, void *recvbuf,
                                                 MPI_Aint recvcount, MPI_Datatype recvtype,
                                                 int root, MPIR_Comm * comm, MPIR_Errflag_t errflag)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_gather(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                           recvtype, root, comm, errflag);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_gatherv(const void *sendbuf, MPI_Aint sendcount,
                                                  MPI_Datatype sendtype, void *recvbuf,
                                                  const MPI_Aint * recvcounts,
                                                  const MPI_Aint * displs, MPI_Datatype recvtype,
                                                  int root, MPIR_Comm * comm,
                                                  MPIR_Errflag_t errflag)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_gatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts,
                                            displs, recvtype, root, comm, errflag);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_alltoall(const void *sendbuf, MPI_Aint sendcount,
                                                   MPI_Datatype sendtype, void *recvbuf,
                                                   MPI_Aint recvcount, MPI_Datatype recvtype,
                                                   MPIR_Comm * comm, MPIR_Errflag_t errflag)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                             recvtype, comm, errflag);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_alltoallv(const void *sendbuf,
                                                    const MPI_Aint * sendcounts,
                                                    const MPI_Aint * sdispls, MPI_Datatype sendtype,
                                                    void *recvbuf, const MPI_Aint * recvcounts,
                                                    const MPI_Aint * rdispls, MPI_Datatype recvtype,
                                                    MPIR_Comm * comm, MPIR_Errflag_t errflag)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf,
                                              recvcounts, rdispls, recvtype, comm, errflag);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_alltoallw(const void *sendbuf,
                                                    const MPI_Aint * sendcounts,
                                                    const MPI_Aint * sdispls,
                                                    const MPI_Datatype sendtypes[], void *recvbuf,
                                                    const MPI_Aint * recvcounts,
                                                    const MPI_Aint * rdispls,
                                                    const MPI_Datatype recvtypes[],
                                                    MPIR_Comm * comm, MPIR_Errflag_t errflag)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf,
                                              recvcounts, rdispls, recvtypes, comm, errflag);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_reduce(const void *sendbuf, void *recvbuf, MPI_Aint count,
                                                 MPI_Datatype datatype, MPI_Op op, int root,
                                                 MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_reduce(sendbuf, recvbuf, count, datatype, op, root, comm_ptr,
                                           errflag);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_reduce_scatter(const void *sendbuf, void *recvbuf,
                                                         const MPI_Aint * recvcounts,
                                                         MPI_Datatype datatype, MPI_Op op,
                                                         MPIR_Comm * comm_ptr,
                                                         MPIR_Errflag_t errflag)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_reduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op,
                                                   comm_ptr, errflag);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_reduce_scatter_block(const void *sendbuf, void *recvbuf,
                                                               MPI_Aint recvcount,
                                                               MPI_Datatype datatype, MPI_Op op,
                                                               MPIR_Comm * comm_ptr,
                                                               MPIR_Errflag_t errflag)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_reduce_scatter_block(sendbuf, recvbuf, recvcount, datatype, op,
                                                         comm_ptr, errflag);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_scan(const void *sendbuf, void *recvbuf, MPI_Aint count,
                                               MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm,
                                               MPIR_Errflag_t errflag)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_scan(sendbuf, recvbuf, count, datatype, op, comm, errflag);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_exscan(const void *sendbuf, void *recvbuf, MPI_Aint count,
                                                 MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm,
                                                 MPIR_Errflag_t errflag)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_exscan(sendbuf, recvbuf, count, datatype, op, comm, errflag);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_neighbor_allgather(const void *sendbuf,
                                                             MPI_Aint sendcount,
                                                             MPI_Datatype sendtype, void *recvbuf,
                                                             MPI_Aint recvcount,
                                                             MPI_Datatype recvtype,
                                                             MPIR_Comm * comm)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_neighbor_allgather(sendbuf, sendcount, sendtype, recvbuf,
                                                       recvcount, recvtype, comm);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_neighbor_allgatherv(const void *sendbuf,
                                                              MPI_Aint sendcount,
                                                              MPI_Datatype sendtype, void *recvbuf,
                                                              const MPI_Aint * recvcounts,
                                                              const MPI_Aint * displs,
                                                              MPI_Datatype recvtype,
                                                              MPIR_Comm * comm)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_neighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf,
                                                        recvcounts, displs, recvtype, comm);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_neighbor_alltoallv(const void *sendbuf,
                                                             const MPI_Aint * sendcounts,
                                                             const MPI_Aint * sdispls,
                                                             MPI_Datatype sendtype, void *recvbuf,
                                                             const MPI_Aint * recvcounts,
                                                             const MPI_Aint * rdispls,
                                                             MPI_Datatype recvtype,
                                                             MPIR_Comm * comm)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_neighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype,
                                                       recvbuf, recvcounts, rdispls, recvtype,
                                                       comm);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_neighbor_alltoallw(const void *sendbuf,
                                                             const MPI_Aint * sendcounts,
                                                             const MPI_Aint * sdispls,
                                                             const MPI_Datatype sendtypes[],
                                                             void *recvbuf,
                                                             const MPI_Aint * recvcounts,
                                                             const MPI_Aint * rdispls,
                                                             const MPI_Datatype recvtypes[],
                                                             MPIR_Comm * comm)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_neighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes,
                                                       recvbuf, recvcounts, rdispls, recvtypes,
                                                       comm);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_neighbor_alltoall(const void *sendbuf, MPI_Aint sendcount,
                                                            MPI_Datatype sendtype, void *recvbuf,
                                                            MPI_Aint recvcount,
                                                            MPI_Datatype recvtype, MPIR_Comm * comm)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_neighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf,
                                                      recvcount, recvtype, comm);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_ineighbor_allgather(const void *sendbuf,
                                                              MPI_Aint sendcount,
                                                              MPI_Datatype sendtype, void *recvbuf,
                                                              MPI_Aint recvcount,
                                                              MPI_Datatype recvtype,
                                                              MPIR_Comm * comm,
                                                              MPIR_Request ** req_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_ineighbor_allgather(sendbuf, sendcount, sendtype, recvbuf,
                                                        recvcount, recvtype, comm, req_p);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_ineighbor_allgatherv(const void *sendbuf,
                                                               MPI_Aint sendcount,
                                                               MPI_Datatype sendtype, void *recvbuf,
                                                               const MPI_Aint * recvcounts,
                                                               const MPI_Aint * displs,
                                                               MPI_Datatype recvtype,
                                                               MPIR_Comm * comm,
                                                               MPIR_Request ** req_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_ineighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf,
                                                         recvcounts, displs, recvtype, comm, req_p);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_ineighbor_alltoall(const void *sendbuf,
                                                             MPI_Aint sendcount,
                                                             MPI_Datatype sendtype, void *recvbuf,
                                                             MPI_Aint recvcount,
                                                             MPI_Datatype recvtype,
                                                             MPIR_Comm * comm,
                                                             MPIR_Request ** req_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_ineighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf,
                                                       recvcount, recvtype, comm, req_p);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_ineighbor_alltoallv(const void *sendbuf,
                                                              const MPI_Aint * sendcounts,
                                                              const MPI_Aint * sdispls,
                                                              MPI_Datatype sendtype, void *recvbuf,
                                                              const MPI_Aint * recvcounts,
                                                              const MPI_Aint * rdispls,
                                                              MPI_Datatype recvtype,
                                                              MPIR_Comm * comm,
                                                              MPIR_Request ** req_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_ineighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype,
                                                        recvbuf, recvcounts, rdispls, recvtype,
                                                        comm, req_p);

    MPIR_FUNC_EXIT;
    return ret;
}

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
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_ineighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes,
                                                        recvbuf, recvcounts, rdispls, recvtypes,
                                                        comm, req_p);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_ibarrier(MPIR_Comm * comm, MPIR_Request ** req_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_ibarrier(comm, req_p);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_ibcast(void *buffer, MPI_Aint count,
                                                 MPI_Datatype datatype, int root, MPIR_Comm * comm,
                                                 MPIR_Request ** req_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_ibcast(buffer, count, datatype, root, comm, req_p);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_iallgather(const void *sendbuf, MPI_Aint sendcount,
                                                     MPI_Datatype sendtype, void *recvbuf,
                                                     MPI_Aint recvcount, MPI_Datatype recvtype,
                                                     MPIR_Comm * comm, MPIR_Request ** req_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_iallgather(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                               recvtype, comm, req_p);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_iallgatherv(const void *sendbuf, MPI_Aint sendcount,
                                                      MPI_Datatype sendtype, void *recvbuf,
                                                      const MPI_Aint * recvcounts,
                                                      const MPI_Aint * displs,
                                                      MPI_Datatype recvtype, MPIR_Comm * comm,
                                                      MPIR_Request ** req_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_iallgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts,
                                                displs, recvtype, comm, req_p);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_iallreduce(const void *sendbuf, void *recvbuf,
                                                     MPI_Aint count, MPI_Datatype datatype,
                                                     MPI_Op op, MPIR_Comm * comm,
                                                     MPIR_Request ** req_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_iallreduce(sendbuf, recvbuf, count, datatype, op, comm, req_p);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_ialltoall(const void *sendbuf, MPI_Aint sendcount,
                                                    MPI_Datatype sendtype, void *recvbuf,
                                                    MPI_Aint recvcount, MPI_Datatype recvtype,
                                                    MPIR_Comm * comm, MPIR_Request ** req_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_ialltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                              recvtype, comm, req_p);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_ialltoallv(const void *sendbuf,
                                                     const MPI_Aint * sendcounts,
                                                     const MPI_Aint * sdispls,
                                                     MPI_Datatype sendtype, void *recvbuf,
                                                     const MPI_Aint * recvcounts,
                                                     const MPI_Aint * rdispls,
                                                     MPI_Datatype recvtype, MPIR_Comm * comm,
                                                     MPIR_Request ** req_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_ialltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf,
                                               recvcounts, rdispls, recvtype, comm, req_p);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_ialltoallw(const void *sendbuf,
                                                     const MPI_Aint * sendcounts,
                                                     const MPI_Aint * sdispls,
                                                     const MPI_Datatype sendtypes[], void *recvbuf,
                                                     const MPI_Aint * recvcounts,
                                                     const MPI_Aint * rdispls,
                                                     const MPI_Datatype recvtypes[],
                                                     MPIR_Comm * comm, MPIR_Request ** req_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_ialltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf,
                                               recvcounts, rdispls, recvtypes, comm, req_p);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_iexscan(const void *sendbuf, void *recvbuf,
                                                  MPI_Aint count, MPI_Datatype datatype, MPI_Op op,
                                                  MPIR_Comm * comm, MPIR_Request ** req_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_iexscan(sendbuf, recvbuf, count, datatype, op, comm, req_p);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_igather(const void *sendbuf, MPI_Aint sendcount,
                                                  MPI_Datatype sendtype, void *recvbuf,
                                                  MPI_Aint recvcount, MPI_Datatype recvtype,
                                                  int root, MPIR_Comm * comm, MPIR_Request ** req_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_igather(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                            recvtype, root, comm, req_p);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_igatherv(const void *sendbuf, MPI_Aint sendcount,
                                                   MPI_Datatype sendtype, void *recvbuf,
                                                   const MPI_Aint * recvcounts,
                                                   const MPI_Aint * displs, MPI_Datatype recvtype,
                                                   int root, MPIR_Comm * comm,
                                                   MPIR_Request ** req_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_igatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts,
                                             displs, recvtype, root, comm, req_p);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_ireduce_scatter_block(const void *sendbuf, void *recvbuf,
                                                                MPI_Aint recvcount,
                                                                MPI_Datatype datatype, MPI_Op op,
                                                                MPIR_Comm * comm,
                                                                MPIR_Request ** req_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_ireduce_scatter_block(sendbuf, recvbuf, recvcount, datatype, op,
                                                          comm, req_p);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_ireduce_scatter(const void *sendbuf, void *recvbuf,
                                                          const MPI_Aint * recvcounts,
                                                          MPI_Datatype datatype, MPI_Op op,
                                                          MPIR_Comm * comm, MPIR_Request ** req_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_ireduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op,
                                                    comm, req_p);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_ireduce(const void *sendbuf, void *recvbuf,
                                                  MPI_Aint count, MPI_Datatype datatype, MPI_Op op,
                                                  int root, MPIR_Comm * comm_ptr,
                                                  MPIR_Request ** req_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_ireduce(sendbuf, recvbuf, count, datatype, op, root, comm_ptr,
                                            req_p);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_iscan(const void *sendbuf, void *recvbuf, MPI_Aint count,
                                                MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm,
                                                MPIR_Request ** req_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_iscan(sendbuf, recvbuf, count, datatype, op, comm, req_p);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_iscatter(const void *sendbuf, MPI_Aint sendcount,
                                                   MPI_Datatype sendtype, void *recvbuf,
                                                   MPI_Aint recvcount, MPI_Datatype recvtype,
                                                   int root, MPIR_Comm * comm,
                                                   MPIR_Request ** req_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_iscatter(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                             recvtype, root, comm, req_p);

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_mpi_iscatterv(const void *sendbuf,
                                                    const MPI_Aint * sendcounts,
                                                    const MPI_Aint * displs, MPI_Datatype sendtype,
                                                    void *recvbuf, MPI_Aint recvcount,
                                                    MPI_Datatype recvtype, int root,
                                                    MPIR_Comm * comm_ptr, MPIR_Request ** req_p)
{
    int ret;

    MPIR_FUNC_ENTER;

    ret = MPIDI_NM_native_func->mpi_iscatterv(sendbuf, sendcounts, displs, sendtype, recvbuf,
                                              recvcount, recvtype, root, comm_ptr, req_p);

    MPIR_FUNC_EXIT;
    return ret;
}

#endif /* NETMOD_DISABLE_INLINES */

#else
#define __netmod_inline_stubnm__   0
#define __netmod_inline_ofi__   1
#define __netmod_inline_ucx__   2

#if NETMOD_INLINE==__netmod_inline_stubnm__
#include "../stubnm/netmod_inline.h"
#elif NETMOD_INLINE==__netmod_inline_ofi__
#include "../ofi/netmod_inline.h"
#elif NETMOD_INLINE==__netmod_inline_ucx__
#include "../ucx/netmod_inline.h"
#else
#error "No direct netmod included"
#endif
#endif /* NETMOD_INLINE */

#endif /* NETMOD_IMPL_H_INCLUDED */
