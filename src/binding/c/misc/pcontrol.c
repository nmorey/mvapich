/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Pcontrol */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Pcontrol = PMPI_Pcontrol
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Pcontrol  MPI_Pcontrol
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Pcontrol as PMPI_Pcontrol
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Pcontrol(const int level, ...)  __attribute__ ((weak, alias("PMPI_Pcontrol")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Pcontrol
#define MPI_Pcontrol PMPI_Pcontrol
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Pcontrol(const int level, ...)
{
    int mpi_errno = MPI_SUCCESS;
    va_list list;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_FUNC_TERSE_ENTER;

    /* ... body of routine ...  */

    /* This is a dummy routine that does nothing.  It is intended for
     * use by the user (or a tool) with the profiling interface */
    /* We include a reference to va_start and va_end to (a) quiet some
     * compilers that warn when they are not present and (b) show how to
     * access any optional arguments */
    va_start(list, level);
    va_end(list);

    /* ... end of body of routine ... */
    MPIR_FUNC_TERSE_EXIT;
    return mpi_errno;
    /* There should never be any fn_fail case; this suppresses warnings from
     * compilers that object to unused labels */
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Pcontrol(QMPI_Context context, int tool_id, const int level, ...)
{
    va_list varargs;
    va_start(varargs, level);

    return internal_Pcontrol(level, varargs);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Pcontrol(const int level, ...)
{
    QMPI_Context context;
    QMPI_Pcontrol_t *fn_ptr;

    context.storage_stack = NULL;

    va_list varargs;
    va_start(varargs, level);

    int mpi_errno = MPI_SUCCESS;
    mpi_errno = MPII_qmpi_init();
    if (mpi_errno != MPI_SUCCESS) {
        return mpi_errno;
    }

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Pcontrol(context, 0, level, varargs);

    fn_ptr = (QMPI_Pcontrol_t *) MPIR_QMPI_first_fn_ptrs[MPI_PCONTROL_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_PCONTROL_T], level, varargs);
}
#else /* ENABLE_QMPI */
int MPI_Pcontrol(const int level, ...)
{
    va_list varargs;
    va_start(varargs, level);

    return internal_Pcontrol(level, varargs);
}

#endif /* ENABLE_QMPI */
