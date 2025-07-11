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

#ifndef MPIR_MVP_LMEM_H_INCLUDED
#define MPIR_MVP_LMEM_H_INCLUDED

#include "mpichconf.h"

/*
=== BEGIN_MPI_T_CVAR_INFO_BLOCK ===

cvars:
    - name        : MPIR_CVAR_LMEM_POOL_SIZE
      category    : MEMORY
      type        : int
      default     : 32 * 1024 * 1024
      class       : none
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : >-
        Sets the amount of space allocated at init time to be used by internal
        functions for local temp buffers.

=== END_MPI_T_CVAR_INFO_BLOCK ===
*/

/* use of alloca */
#if defined(HAVE_ALLOCA) && defined(HAVE_ALLOCA_H)
#include <alloca.h>
#endif
#include <sys/resource.h>

#define ALIGN 64
#define ALIGNDIFF(_n) (_n & (ALIGN - 1))

/* declared in src/util/mpir_handlemem.c as it is the closest functionality */
extern void *mvp_lmem_pool;
extern uintptr_t mvp_lmem_free_head;
extern uintptr_t mvp_lmem_size;
extern uint64_t mvp_stack_size;

#define MPIR_MVP_LMEM_SIZE (mvp_lmem_free_head - (uintptr_t)mvp_lmem_pool)
#define MPIR_MVP_LMEM_MAX                                                      \
    ((uintptr_t)(mvp_lmem_pool + MPIR_CVAR_LMEM_POOL_SIZE))

/* check if memory is in the local pool */
#define MPIR_MVP_MEM_IS_LOCAL(_chk_ptr)                                        \
    (((uintptr_t)(_chk_ptr) >= (uintptr_t)mvp_lmem_pool) &&                    \
     ((uintptr_t)(_chk_ptr) < (uintptr_t)MPIR_MVP_LMEM_MAX))

#define MVP_NULL_POOL (void *)0xecececec
#define MVP_VALID_MEM_POOL (mvp_lmem_pool && (MVP_NULL_POOL != mvp_lmem_pool))

#define MPIR_MVP_INIT_LMEMPOOL()                                               \
    do {                                                                       \
        if (!mvp_lmem_pool && !MPIR_IS_THREADED) {                             \
            mvp_lmem_pool =                                                    \
                MPL_aligned_alloc(ALIGN, MPIR_CVAR_LMEM_POOL_SIZE,             \
                                  MPL_MEM_OTHER);                              \
            mvp_lmem_free_head = (uintptr_t)mvp_lmem_pool;                     \
        } else if (!mvp_lmem_pool) {                                           \
            MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);    \
            struct rlimit _rlim;                                               \
            mvp_lmem_pool = MVP_NULL_POOL;                                     \
            mvp_lmem_free_head = (uintptr_t)mvp_lmem_pool;                     \
            getrlimit(RLIMIT_STACK, &_rlim);                                   \
            mvp_stack_size = _rlim.rlim_cur;                                   \
            MPID_THREAD_CS_EXIT(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);     \
        }                                                                      \
    } while(0)

#define MPIR_MVP_FREE_LMEMPOOL()                                               \
    do {                                                                       \
        if (MVP_VALID_MEM_POOL && !MPIR_IS_THREADED) {                         \
            MPIR_Assert(!MPIR_MVP_LMEM_SIZE);                                  \
            MPL_free(mvp_lmem_pool);                                           \
            mvp_lmem_pool = NULL;                                              \
        }                                                                      \
    } while(0)

#if defined(MVP_HAVE_ALLOCA) && defined(MPICH_IS_THREADED)
/* allocate memory on the local pool - opperates like a stack frame */
#define MPIR_MVP_LALLOC(_ptr, _type, _nbytes, _class)                          \
    {                                                                          \
        size_t _alloc_bytes = (size_t)_nbytes;                                 \
        if (ALIGNDIFF(_alloc_bytes)) {                                         \
            _alloc_bytes += (ALIGN - ALIGNDIFF(_alloc_bytes));                 \
        }                                                                      \
        if (MPIR_IS_THREADED || !MVP_VALID_MEM_POOL &&                         \
            _alloc_bytes < mvp_stack_size) {                                   \
            _ptr = (_type)alloca(_alloc_bytes);                                \
        } else if (mvp_lmem_free_head + _alloc_bytes > MPIR_MVP_LMEM_MAX ||    \
                   MPIR_ThreadInfo.thread_provided == MPI_THREAD_MULTIPLE ||   \
                   !MVP_VALID_MEM_POOL) {                                      \
            _ptr = (_type)MPL_aligned_alloc(ALIGN, _alloc_bytes, _class);      \
        } else {                                                               \
            MPIR_Assert(mvp_lmem_pool);                                        \
            _ptr = (_type)mvp_lmem_free_head;                                  \
            mvp_lmem_free_head += _alloc_bytes;                                \
            mvp_my_lmem_size += _alloc_bytes;                                  \
        }                                                                      \
    }
#else
#define MPIR_MVP_LALLOC(_ptr, _type, _nbytes, _class)                          \
    {                                                                          \
        size_t _alloc_bytes = (size_t)_nbytes;                                 \
        if (ALIGNDIFF(_alloc_bytes)) {                                         \
            _alloc_bytes += (ALIGN - ALIGNDIFF(_alloc_bytes));                 \
        }                                                                      \
        if (MPIR_IS_THREADED || !MVP_VALID_MEM_POOL ||                         \
            mvp_lmem_free_head + _alloc_bytes > MPIR_MVP_LMEM_MAX) {           \
            _ptr = (_type)MPL_aligned_alloc(ALIGN, _alloc_bytes, _class);      \
        } else {                                                               \
            MPIR_Assert(mvp_lmem_pool);                                        \
            _ptr = (_type)mvp_lmem_free_head;                                  \
            mvp_lmem_free_head += _alloc_bytes;                                \
            mvp_my_lmem_size += _alloc_bytes;                                  \
        }                                                                      \
    }
#endif

/* free memory if it was not on the local pool */
#define MPIR_MVP_LFREE(_ptr)                                                   \
    {                                                                          \
        void *_free_ptr = (_ptr);                                              \
        if (!MPIR_MVP_MEM_IS_LOCAL(_free_ptr)) {                               \
            MPL_free(_free_ptr);                                               \
        }                                                                      \
    }

#endif /* MPIR_MVP_LMEM_H_INCLUDED */
