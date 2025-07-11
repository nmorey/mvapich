/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Session_c2f */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Session_c2f = PMPI_Session_c2f
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Session_c2f  MPI_Session_c2f
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Session_c2f as PMPI_Session_c2f
#elif defined(HAVE_WEAK_ATTRIBUTE)
MPI_Fint MPI_Session_c2f(MPI_Session session)  __attribute__ ((weak, alias("PMPI_Session_c2f")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Session_c2f
#define MPI_Session_c2f PMPI_Session_c2f
#endif /* MPICH_MPI_FROM_PMPI */

static MPI_Fint internal_Session_c2f(MPI_Session session)
{
    return (MPI_Fint) session;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
MPI_Fint QMPI_Session_c2f(QMPI_Context context, int tool_id, MPI_Session session)
{
    return internal_Session_c2f(session);
}
#endif /* MPICH_MPI_FROM_PMPI */
MPI_Fint MPI_Session_c2f(MPI_Session session)
{
    QMPI_Context context;
    QMPI_Session_c2f_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Session_c2f(context, 0, session);

    fn_ptr = (QMPI_Session_c2f_t *) MPIR_QMPI_first_fn_ptrs[MPI_SESSION_C2F_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_SESSION_C2F_T], session);
}
#else /* ENABLE_QMPI */
MPI_Fint MPI_Session_c2f(MPI_Session session)
{
    return internal_Session_c2f(session);
}

#endif /* ENABLE_QMPI */
