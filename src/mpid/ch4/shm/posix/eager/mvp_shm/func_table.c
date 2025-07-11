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

#ifdef POSIX_EAGER_INLINE
/* this file is empty */
#else

#define POSIX_EAGER_DISABLE_INLINES

#include <mpidimpl.h>
#include "posix_eager_inline.h"

MPIDI_POSIX_eager_funcs_t MPIDI_POSIX_eager_mvp_shm_funcs = {
    MPIDI_MVP_POSIX_init,
    MPIDI_MVP_POSIX_post_init,
    MPIDI_MVP_POSIX_finalize,

    MPIDI_POSIX_eager_send,

    MPIDI_POSIX_eager_recv_begin,
    MPIDI_POSIX_eager_recv_memcpy,
    MPIDI_POSIX_eager_recv_commit,

    MPIDI_POSIX_eager_recv_posted_hook,
    MPIDI_POSIX_eager_recv_completed_hook,

    MPIDI_POSIX_eager_payload_limit,
    MPIDI_POSIX_eager_buf_limit};

#endif /* POSIX_EAGER_INLINE */
