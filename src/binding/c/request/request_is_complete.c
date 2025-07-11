/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPIX_Request_is_complete */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPIX_Request_is_complete = PMPIX_Request_is_complete
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPIX_Request_is_complete  MPIX_Request_is_complete
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPIX_Request_is_complete as PMPIX_Request_is_complete
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPIX_Request_is_complete(MPI_Request request)
     __attribute__ ((weak, alias("PMPIX_Request_is_complete")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPIX_Request_is_complete
#define MPIX_Request_is_complete PMPIX_Request_is_complete
#endif /* MPICH_MPI_FROM_PMPI */

static int internalX_Request_is_complete(MPI_Request request)
{
    MPIR_Request *request_ptr;
    MPIR_Request_get_ptr(request, request_ptr);
    if (request_ptr) {
        return MPIR_Request_is_complete(request_ptr);
    } else {
        return 1;
    }
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPIX_Request_is_complete(QMPI_Context context, int tool_id, MPI_Request request)
{
    return internalX_Request_is_complete(request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPIX_Request_is_complete(MPI_Request request)
{
    QMPI_Context context;
    QMPIX_Request_is_complete_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPIX_Request_is_complete(context, 0, request);

    fn_ptr = (QMPIX_Request_is_complete_t *) MPIR_QMPI_first_fn_ptrs[MPIX_REQUEST_IS_COMPLETE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPIX_REQUEST_IS_COMPLETE_T], request);
}
#else /* ENABLE_QMPI */
int MPIX_Request_is_complete(MPI_Request request)
{
    return internalX_Request_is_complete(request);
}

#endif /* ENABLE_QMPI */
