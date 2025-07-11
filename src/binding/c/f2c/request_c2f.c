/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Request_c2f */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Request_c2f = PMPI_Request_c2f
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Request_c2f  MPI_Request_c2f
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Request_c2f as PMPI_Request_c2f
#elif defined(HAVE_WEAK_ATTRIBUTE)
MPI_Fint MPI_Request_c2f(MPI_Request request)  __attribute__ ((weak, alias("PMPI_Request_c2f")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Request_c2f
#define MPI_Request_c2f PMPI_Request_c2f
#endif /* MPICH_MPI_FROM_PMPI */

static MPI_Fint internal_Request_c2f(MPI_Request request)
{
    return (MPI_Fint) request;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
MPI_Fint QMPI_Request_c2f(QMPI_Context context, int tool_id, MPI_Request request)
{
    return internal_Request_c2f(request);
}
#endif /* MPICH_MPI_FROM_PMPI */
MPI_Fint MPI_Request_c2f(MPI_Request request)
{
    QMPI_Context context;
    QMPI_Request_c2f_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Request_c2f(context, 0, request);

    fn_ptr = (QMPI_Request_c2f_t *) MPIR_QMPI_first_fn_ptrs[MPI_REQUEST_C2F_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_REQUEST_C2F_T], request);
}
#else /* ENABLE_QMPI */
MPI_Fint MPI_Request_c2f(MPI_Request request)
{
    return internal_Request_c2f(request);
}

#endif /* ENABLE_QMPI */
