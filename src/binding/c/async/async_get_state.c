/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPIX_Async_get_state */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPIX_Async_get_state = PMPIX_Async_get_state
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPIX_Async_get_state  MPIX_Async_get_state
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPIX_Async_get_state as PMPIX_Async_get_state
#elif defined(HAVE_WEAK_ATTRIBUTE)
void * MPIX_Async_get_state(MPIX_Async_thing async_thing)
     __attribute__ ((weak, alias("PMPIX_Async_get_state")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPIX_Async_get_state
#define MPIX_Async_get_state PMPIX_Async_get_state
#endif /* MPICH_MPI_FROM_PMPI */

static void * internalX_Async_get_state(MPIX_Async_thing async_thing)
{
    return MPIR_Async_thing_get_state(async_thing);
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
void * QMPIX_Async_get_state(QMPI_Context context, int tool_id, MPIX_Async_thing async_thing)
{
    return internalX_Async_get_state(async_thing);
}
#endif /* MPICH_MPI_FROM_PMPI */
void * MPIX_Async_get_state(MPIX_Async_thing async_thing)
{
    QMPI_Context context;
    QMPIX_Async_get_state_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPIX_Async_get_state(context, 0, async_thing);

    fn_ptr = (QMPIX_Async_get_state_t *) MPIR_QMPI_first_fn_ptrs[MPIX_ASYNC_GET_STATE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPIX_ASYNC_GET_STATE_T], async_thing);
}
#else /* ENABLE_QMPI */
void * MPIX_Async_get_state(MPIX_Async_thing async_thing)
{
    return internalX_Async_get_state(async_thing);
}

#endif /* ENABLE_QMPI */
