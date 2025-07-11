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

#ifndef POSIX_EAGER_MVP_SHM_TYPES_H_INCLUDED
#define POSIX_EAGER_MVP_SHM_TYPES_H_INCLUDED

#include <mpidimpl.h>
#include "mpidu_init_shm.h"

#define MPIDI_POSIX_EAGER_MVP_SHM_CELL_TYPE_HDR  0
#define MPIDI_POSIX_EAGER_MVP_SHM_CELL_TYPE_DATA 1

typedef struct spsc_queue_cell {
    uint16_t type;
    uint16_t from;
    uint32_t payload_size;
    MPIDI_POSIX_am_header_t am_header;
} mvp_shm_spsc_queue_cell_t;

typedef struct spsc_queue {
    MPL_atomic_uint64_t *atomic_head;
    MPL_atomic_uint64_t *atomic_tail;
    uint64_t cached_head;
    uint64_t cached_tail;
    void *base_addr;
    mvp_shm_spsc_queue_cell_t *cells;
} mvp_shm_spsc_queue_t;

typedef struct shm_region {
    mvp_shm_spsc_queue_t *shared_queues;
} shm_region_t;

typedef struct MPIDI_POSIX_eager_mvp_shm_global {
    void *mmap_ptr;
    long cache_line_size;
    int cell_size;
    size_t shmem_allocation_size;
    shm_region_t shm_region;
} MPIDI_POSIX_eager_mvp_shm_global_t;

extern MPIDI_POSIX_eager_mvp_shm_global_t MPIDI_POSIX_eager_mvp_shm_global;

MPL_STATIC_INLINE_PREFIX mvp_shm_spsc_queue_t *
MPIDI_POSIX_eager_mvp_shm_get_recvq(int sender, int receiver, int local_size)
{
    return &MPIDI_POSIX_eager_mvp_shm_global.shm_region
                .shared_queues[receiver * local_size + sender];
}

#define MVP_SHM_QUEUE_SIZE_MASK (MPIR_CVAR_CH4_MVP_SHM_POSIX_NUM_CELLS - 1)

#define MPIDI_POSIX_EAGER_MVP_SHM_CELL_PAYLOAD(base_addr)                      \
    ((char *)(base_addr) + sizeof(mvp_shm_spsc_queue_cell_t))

#define MPIDI_POSIX_EAGER_MVP_SHM_CELL_CAPACITY()                              \
    MPIDI_POSIX_eager_mvp_shm_global.cell_size -                               \
        sizeof(mvp_shm_spsc_queue_cell_t)
#endif /* POSIX_EAGER_MVP_SHM_TYPES_H_INCLUDED */
