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

#ifndef POSIX_EAGER_MVP_SHM_SEND_H_INCLUDED
#define POSIX_EAGER_MVP_SHM_SEND_H_INCLUDED

#include "mvp_shm_impl.h"
#include "mpidu_genq.h"

MPL_STATIC_INLINE_PREFIX size_t MPIDI_POSIX_eager_payload_limit(void)
{
    return MPIR_CVAR_CH4_MVP_SHM_POSIX_CELL_SIZE -
           sizeof(mvp_shm_spsc_queue_cell_t);
}

MPL_STATIC_INLINE_PREFIX size_t MPIDI_POSIX_eager_buf_limit(void)
{
    return MPIR_CVAR_CH4_MVP_SHM_POSIX_CELL_SIZE;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_POSIX_eager_send(
    int grank, MPIDI_POSIX_am_header_t *msg_hdr, const void *am_hdr,
    MPI_Aint am_hdr_sz, const void *buf, MPI_Aint count, MPI_Datatype datatype,
    MPI_Aint offset, int src_vci, int dst_vci, MPI_Aint *bytes_sent)
{
    int ret = MPIDI_POSIX_OK;
    MPIR_FUNC_ENTER;
    int local_size = MPIR_Process.local_size;
    int local_rank = MPIR_Process.local_rank;
    MPI_Aint packed_size = 0;

    int dst_local_rank = MPIDI_POSIX_global.local_ranks[grank];
    mvp_shm_spsc_queue_t *receiver_queue = MPIDI_POSIX_eager_mvp_shm_get_recvq(
        local_rank, dst_local_rank, local_size);
    uint64_t tail = MPL_atomic_relaxed_load_uint64(receiver_queue->atomic_tail);
    int num_cells = MPIR_CVAR_CH4_MVP_SHM_POSIX_NUM_CELLS;
    if (receiver_queue->cached_head + num_cells - tail < 1) {
        receiver_queue->cached_head =
            MPL_atomic_acquire_load_uint64(receiver_queue->atomic_head);
        if (receiver_queue->cached_head + num_cells - tail < 1) {
            ret = MPIDI_POSIX_NOK;
            goto fn_exit;
        }
    }
    size_t available = MPIDI_POSIX_EAGER_MVP_SHM_CELL_CAPACITY();
    char *cell_addr = (char *)receiver_queue->base_addr +
                      (tail & MVP_SHM_QUEUE_SIZE_MASK) *
                          MPIR_CVAR_CH4_MVP_SHM_POSIX_CELL_SIZE;
    char *payload = cell_addr + sizeof(mvp_shm_spsc_queue_cell_t);

    mvp_shm_spsc_queue_cell_t cell;
    cell.from = MPIR_Process.local_rank;
    cell.payload_size = 0;
    if (am_hdr) {
        MPI_Aint resized_am_hdr_sz =
            MPL_ROUND_UP_ALIGN(am_hdr_sz, MAX_ALIGNMENT);
        cell.am_header = *msg_hdr;
        cell.type = MPIDI_POSIX_EAGER_MVP_SHM_CELL_TYPE_HDR;
        payload = payload + resized_am_hdr_sz;
        cell.payload_size += resized_am_hdr_sz;
        cell.am_header.am_hdr_sz = resized_am_hdr_sz;
        available -= cell.am_header.am_hdr_sz;
    } else {
        cell.type = MPIDI_POSIX_EAGER_MVP_SHM_CELL_TYPE_DATA;
    }

    if (am_hdr) {
        MPIR_Typerep_copy((char *)cell_addr + sizeof(mvp_shm_spsc_queue_cell_t),
                          am_hdr, am_hdr_sz, MPIR_TYPEREP_FLAG_NONE);
    }
    if (bytes_sent) {
        MPIR_Typerep_pack(buf, count, datatype, offset, payload, available,
                          &packed_size, MPIR_TYPEREP_FLAG_NONE);
        cell.payload_size += packed_size;
        *bytes_sent = packed_size;
    }

    MPIR_Typerep_copy(cell_addr, &cell, sizeof(mvp_shm_spsc_queue_cell_t),
                      MPIR_TYPEREP_FLAG_NONE);

    MPL_atomic_release_store_uint64(receiver_queue->atomic_tail, tail + 1);

fn_exit:
    MPIR_FUNC_EXIT;
    return ret;
}

#endif /* POSIX_EAGER_MVP_SHM_SEND_H_INCLUDED */
