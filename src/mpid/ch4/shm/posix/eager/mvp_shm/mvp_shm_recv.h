/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */
/*
 * Copyright (c) 2001-2025, The Ohio State University. All rights reserved.
 *
 * This file is part of the MVAPICH software package developed by the team
 * members of The Ohio State University's Network-Based Computing Laboratory
 * (NBCL), headed by Professor Dhabaleswar K. (DK) Panda.
 *
 * For detailed copyright and licensing information, please refer to the
 * copyright file COPYRIGHT in the top level MVAPICH directory.
 */

#ifndef POSIX_EAGER_MVP_SHM_RECV_H_INCLUDED
#define POSIX_EAGER_MVP_SHM_RECV_H_INCLUDED

#include "mvp_shm_impl.h"
#include "mpidu_genq.h"

MPL_STATIC_INLINE_PREFIX int MPIDI_POSIX_eager_recv_begin(
    int vci, MPIDI_POSIX_eager_recv_transaction_t *transaction)
{
    int ret = MPIDI_POSIX_NOK;

    MPIR_FUNC_ENTER;

    int local_size = MPIR_Process.local_size;
    int local_rank = MPIR_Process.local_rank;

    for (int rank = 0; rank < local_size; rank++) {
        mvp_shm_spsc_queue_t *receiver_queue =
            MPIDI_POSIX_eager_mvp_shm_get_recvq(rank, local_rank, local_size);
        uint64_t head =
            MPL_atomic_relaxed_load_uint64(receiver_queue->atomic_head);
        int num_cells = MPIR_CVAR_CH4_MVP_SHM_POSIX_NUM_CELLS;
        if (receiver_queue->cached_tail - head < 1) {
            receiver_queue->cached_tail =
                MPL_atomic_acquire_load_uint64(receiver_queue->atomic_tail);
            if (receiver_queue->cached_tail - head < 1) {
                continue;
            }
        }
        volatile char *cell_addr = (volatile char *)receiver_queue->base_addr +
                                   (head & MVP_SHM_QUEUE_SIZE_MASK) *
                                       MPIR_CVAR_CH4_MVP_SHM_POSIX_CELL_SIZE;
        volatile mvp_shm_spsc_queue_cell_t *cell =
            (volatile mvp_shm_spsc_queue_cell_t *)cell_addr;
        transaction->src_local_rank = cell->from;
        /* TODO: support multiple VCIs */
        transaction->src_vci = 0;
        transaction->dst_vci = vci;
        transaction->payload =
            (char *)cell_addr + sizeof(mvp_shm_spsc_queue_cell_t);
        transaction->payload_sz = cell->payload_size;

        if (likely(cell->type == MPIDI_POSIX_EAGER_MVP_SHM_CELL_TYPE_HDR)) {
            transaction->msg_hdr =
                &((mvp_shm_spsc_queue_cell_t *)cell)->am_header;
        } else {
            MPIR_Assert(cell->type == MPIDI_POSIX_EAGER_MVP_SHM_CELL_TYPE_DATA);
            transaction->msg_hdr = NULL;
        }
        ret = MPIDI_POSIX_OK;
        break;
    }

    MPIR_FUNC_EXIT;
    return ret;
}

MPL_STATIC_INLINE_PREFIX void MPIDI_POSIX_eager_recv_memcpy(
    MPIDI_POSIX_eager_recv_transaction_t *transaction, void *dst,
    const void *src, size_t size)
{
    MPIR_Typerep_copy(dst, src, size, MPIR_TYPEREP_FLAG_NONE);
}

MPL_STATIC_INLINE_PREFIX void MPIDI_POSIX_eager_recv_commit(
    MPIDI_POSIX_eager_recv_transaction_t *transaction)
{
    MPIR_FUNC_ENTER;
    int local_size = MPIR_Process.local_size;
    int local_rank = MPIR_Process.local_rank;
    mvp_shm_spsc_queue_t *receiver_queue = MPIDI_POSIX_eager_mvp_shm_get_recvq(
        transaction->src_local_rank, local_rank, local_size);
    uint64_t head = MPL_atomic_relaxed_load_uint64(receiver_queue->atomic_head);
    MPL_atomic_release_store_uint64(receiver_queue->atomic_head, head + 1);
    MPIR_FUNC_EXIT;
}

MPL_STATIC_INLINE_PREFIX void MPIDI_POSIX_eager_recv_posted_hook(int grank) {}

MPL_STATIC_INLINE_PREFIX void MPIDI_POSIX_eager_recv_completed_hook(int grank)
{
}

#endif /* POSIX_EAGER_MVP_SHM_RECV_H_INCLUDED */
