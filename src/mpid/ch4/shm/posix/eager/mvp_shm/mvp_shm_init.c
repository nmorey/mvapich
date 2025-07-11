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

#include "mpidimpl.h"
#include "mvp_shm_noinline.h"

/*
=== BEGIN_MPI_T_CVAR_INFO_BLOCK ===

cvars:
    - name        : MPIR_CVAR_CH4_MVP_SHM_POSIX_NUM_CELLS
      category    : CH4
      type        : int
      default     : 128
      class       : none
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : >-
        The number of cells used per sender

    - name        : MPIR_CVAR_CH4_MVP_SHM_POSIX_CELL_SIZE
      category    : CH4
      type        : int
      default     : 16384
      class       : none
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : >-
        Size of each cell.

=== END_MPI_T_CVAR_INFO_BLOCK ===
*/

MPIDI_POSIX_eager_mvp_shm_global_t MPIDI_POSIX_eager_mvp_shm_global;

static int mvp_shm_init_queues(void *mmap_ptr, int rank, int local_size)
{
    int mpi_errno = MPI_SUCCESS;
    char *base_addr = (char *)mmap_ptr;
    int sender_rank = 0;
    for (sender_rank = 0; sender_rank < local_size; sender_rank++) {
        mvp_shm_spsc_queue_t *receiver_queue =
            &MPIDI_POSIX_eager_mvp_shm_global.shm_region
                 .shared_queues[rank * local_size + sender_rank];
        receiver_queue->atomic_head = (MPL_atomic_uint64_t *)base_addr;
        base_addr =
            base_addr + MPIDI_POSIX_eager_mvp_shm_global.cache_line_size;
        receiver_queue->atomic_tail = (MPL_atomic_uint64_t *)base_addr;
        base_addr += MPIDI_POSIX_eager_mvp_shm_global.cache_line_size;
        receiver_queue->base_addr = base_addr;
        MPL_atomic_store_uint64(receiver_queue->atomic_head, 0);
        MPL_atomic_store_uint64(receiver_queue->atomic_tail, 0);
        receiver_queue->cached_head = 0;
        receiver_queue->cached_tail = 0;
        base_addr += MPIR_CVAR_CH4_MVP_SHM_POSIX_CELL_SIZE *
                     MPIR_CVAR_CH4_MVP_SHM_POSIX_NUM_CELLS;
    }

fn_exit:
    return mpi_errno;
fn_fail:
    goto fn_exit;
}

static int mvp_shm_init_region(int local_size)
{
    int mpi_errno = MPI_SUCCESS;

    void *mmap_ptr = MPIDI_POSIX_eager_mvp_shm_global.mmap_ptr;
    MPIDI_POSIX_eager_mvp_shm_global.shm_region.shared_queues = MPL_malloc(
        sizeof(mvp_shm_spsc_queue_t) * local_size * local_size, MPL_MEM_OTHER);
    int receiver_rank = 0;
    for (receiver_rank = 0; receiver_rank < local_size; receiver_rank++) {
        mvp_shm_init_queues((void *)mmap_ptr, receiver_rank, local_size);
        mmap_ptr += (MPIR_CVAR_CH4_MVP_SHM_POSIX_CELL_SIZE *
                         MPIR_CVAR_CH4_MVP_SHM_POSIX_NUM_CELLS +
                     2 * MPIDI_POSIX_eager_mvp_shm_global.cache_line_size) *
                    local_size;
    }

    MPIR_ERR_CHECK(mpi_errno);

fn_exit:
    return mpi_errno;
fn_fail:
    goto fn_exit;
}

int MPIDI_MVP_POSIX_init(int rank, int size)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_FUNC_ENTER;

    int local_size = MPIR_Process.local_size;
    long cache_line_size = sysconf(_SC_LEVEL1_DCACHE_LINESIZE);
    MPIDI_POSIX_eager_mvp_shm_global.cache_line_size = cache_line_size;
    size_t spsc_queue_size =
        (2 * cache_line_size + MPIR_CVAR_CH4_MVP_SHM_POSIX_CELL_SIZE *
                                   MPIR_CVAR_CH4_MVP_SHM_POSIX_NUM_CELLS) *
        local_size;
    size_t shm_allocation_size = local_size * spsc_queue_size;
    mpi_errno = MPIDU_Init_shm_alloc(
        shm_allocation_size, &MPIDI_POSIX_eager_mvp_shm_global.mmap_ptr);
    MPIR_ERR_CHECK(mpi_errno);

    memset(MPIDI_POSIX_eager_mvp_shm_global.mmap_ptr, 0, shm_allocation_size);

    MPIDI_POSIX_eager_mvp_shm_global.cell_size =
        MPIR_CVAR_CH4_MVP_SHM_POSIX_CELL_SIZE;

    mpi_errno = mvp_shm_init_region(local_size);
    MPIR_ERR_CHECK(mpi_errno);

    mpi_errno = MPIDU_Init_shm_barrier();
    MPIR_ERR_CHECK(mpi_errno);
fn_exit:
    MPIR_FUNC_EXIT;
    return mpi_errno;
fn_fail:
    goto fn_exit;
}

int MPIDI_MVP_POSIX_post_init(void)
{
    int mpi_errno = MPI_SUCCESS;
fn_exit:
    return mpi_errno;
fn_fail:
    goto fn_exit;
}

int MPIDI_MVP_POSIX_finalize(void)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_FUNC_ENTER;

    mpi_errno = MPIDU_Init_shm_free(MPIDI_POSIX_eager_mvp_shm_global.mmap_ptr);
    MPIR_ERR_CHECK(mpi_errno);

    if (MPIDI_POSIX_eager_mvp_shm_global.shm_region.shared_queues) {
        MPL_free(MPIDI_POSIX_eager_mvp_shm_global.shm_region.shared_queues);
    }

fn_exit:
    MPIR_FUNC_EXIT;
    return mpi_errno;
fn_fail:
    goto fn_exit;
}
