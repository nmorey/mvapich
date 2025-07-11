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

#ifndef POSIX_EAGER_MVP_SHM_PRE_H_INCLUDED
#define POSIX_EAGER_MVP_SHM_PRE_H_INCLUDED

typedef struct MPIDI_MVP_eager_mvp_shm_recv_transaction {
    void *pointer_to_cell;
} MPIDI_POSIX_eager_mvp_shm_recv_transaction_t;

#endif /* POSIX_EAGER_MVP_SHM_PRE_H_INCLUDED */
