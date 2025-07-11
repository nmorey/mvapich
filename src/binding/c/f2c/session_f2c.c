/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Session_f2c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Session_f2c = PMPI_Session_f2c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Session_f2c  MPI_Session_f2c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Session_f2c as PMPI_Session_f2c
#elif defined(HAVE_WEAK_ATTRIBUTE)
MPI_Session MPI_Session_f2c(MPI_Fint session)  __attribute__ ((weak, alias("PMPI_Session_f2c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Session_f2c
#define MPI_Session_f2c PMPI_Session_f2c
#endif /* MPICH_MPI_FROM_PMPI */

static MPI_Session internal_Session_f2c(MPI_Fint session)
{
    return (MPI_Session) session;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
MPI_Session QMPI_Session_f2c(QMPI_Context context, int tool_id, MPI_Fint session)
{
    return internal_Session_f2c(session);
}
#endif /* MPICH_MPI_FROM_PMPI */
MPI_Session MPI_Session_f2c(MPI_Fint session)
{
    QMPI_Context context;
    QMPI_Session_f2c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Session_f2c(context, 0, session);

    fn_ptr = (QMPI_Session_f2c_t *) MPIR_QMPI_first_fn_ptrs[MPI_SESSION_F2C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_SESSION_F2C_T], session);
}
#else /* ENABLE_QMPI */
MPI_Session MPI_Session_f2c(MPI_Fint session)
{
    return internal_Session_f2c(session);
}

#endif /* ENABLE_QMPI */
