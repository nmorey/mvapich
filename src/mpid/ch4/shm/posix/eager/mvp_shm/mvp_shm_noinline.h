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

#ifndef POSIX_EAGER_MVP_SHM_NOINLINE_H_INCLUDED
#define POSIX_EAGER_MVP_SHM_NOINLINE_H_INCLUDED

#include "mvp_shm_types.h"
#include "mvp_shm_impl.h"

int MPIDI_MVP_POSIX_init(int rank, int size);
int MPIDI_MVP_POSIX_post_init(void);
int MPIDI_MVP_POSIX_finalize(void);

#ifdef POSIX_EAGER_INLINE
#define MPIDI_POSIX_eager_init      MPIDI_MVP_POSIX_init
#define MPIDI_POSIX_eager_post_init MPIDI_MVP_POSIX_post_init
#define MPIDI_POSIX_eager_finalize  MPIDI_MVP_POSIX_finalize
#endif

#endif /* POSIX_EAGER_MVP_SHM_NOINLINE_H_INCLUDED */
