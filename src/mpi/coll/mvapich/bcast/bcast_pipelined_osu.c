/*
 * Copyright (c) 2001-2023, The Ohio State University. All rights reserved.
 *
 * This file is part of the MVAPICH software package developed by the team
 * members of The Ohio State University's Network-Based Computing Laboratory
 * (NBCL), headed by Professor Dhabaleswar K. (DK) Panda.
 *
 * For detailed copyright and licensing information, please refer to the
 * copyright file COPYRIGHT in the top level MVAPICH directory.
 */

/*
=== BEGIN_MPI_T_CVAR_INFO_BLOCK ===

cvars:
    - name        : MPIR_CVAR_BCAST_SEGMENT_SIZE
      category    : COLLECTIVE
      type        : int
      default     : 8192
      class       : none
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : >-
        Size of the segments used for PIPELINED bcast

=== END_MPI_T_CVAR_INFO_BLOCK ===
*/

#include "mpiimpl.h"
#include "mvp_coll_impl.h"

int MPIR_Bcast_intra_osu_pipelined(void *buffer, MPI_Aint count,
                                   MPI_Datatype datatype, int root,
                                   MPIR_Comm *comm_ptr, int seg_size,
                                   MPIR_Errflag_t errflag)
{
    MPIR_Comm *shmem_commptr = NULL;
    int local_rank = 0;
    int mpi_errno = MPI_SUCCESS;
    MPI_Aint type_size = 0;
    intptr_t nbytes = 0, rem_count = 0, bcast_segment_count = 0,
             bcast_curr_count = 0;
    MPI_Aint extent;
    MPI_Aint true_extent, true_lb;
    void *tmp_buf = NULL;

    MPIR_T_PVAR_COUNTER_INC(MVP, mvp_coll_bcast_pipelined, 1);
    MPIR_TIMER_START(coll, bcast, pipelined);

    shmem_commptr = comm_ptr->node_comm;
    MPIR_Datatype_get_extent_macro(datatype, extent);

    if (shmem_commptr) {
        local_rank = shmem_commptr->rank;
    }
    MPIR_Datatype_get_size_macro(datatype, type_size);
    nbytes = (intptr_t)(count)*extent;

    MPIR_Type_get_true_extent_impl(datatype, &true_lb, &true_extent);
    /* even though we always call this algorithm with contiguous buffer, still,
     * the datatype might have some holes in the beginning. Therefore, true_lb
     * might be non zero */
    tmp_buf = buffer + true_lb;

    rem_count = nbytes;
    bcast_segment_count = MIN(rem_count, seg_size);

    while (bcast_curr_count < nbytes) {
        mpi_errno = MPIR_Bcast_intra_osu_knomial(
            (char *)tmp_buf + bcast_curr_count, bcast_segment_count, MPI_BYTE,
            0, comm_ptr, MPIR_CVAR_BCAST_INTER_KNOMIAL_FACTOR,
            MPIR_CVAR_BCAST_INTRA_KNOMIAL_FACTOR, errflag);
        bcast_curr_count += bcast_segment_count;
        rem_count -= bcast_segment_count;
        bcast_segment_count = MIN(rem_count, bcast_segment_count);
    }

fn_fail:
    MPIR_TIMER_END(coll, bcast, pipelined);
    return mpi_errno;
}
