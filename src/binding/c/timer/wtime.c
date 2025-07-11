/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Wtime */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Wtime = PMPI_Wtime
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Wtime  MPI_Wtime
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Wtime as PMPI_Wtime
#elif defined(HAVE_WEAK_ATTRIBUTE)
double MPI_Wtime(void)  __attribute__ ((weak, alias("PMPI_Wtime")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Wtime
#define MPI_Wtime PMPI_Wtime
#endif /* MPICH_MPI_FROM_PMPI */

static double internal_Wtime(void)
{
    double d;
    MPL_time_t t;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_FUNC_TERSE_ENTER;
    MPL_wtime(&t);
    MPL_wtime_todouble(&t, &d);
    MPIR_FUNC_TERSE_EXIT;

    return d;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
double QMPI_Wtime(QMPI_Context context, int tool_id)
{
    return internal_Wtime();
}
#endif /* MPICH_MPI_FROM_PMPI */
double MPI_Wtime(void)
{
    QMPI_Context context;
    QMPI_Wtime_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Wtime(context, 0);

    fn_ptr = (QMPI_Wtime_t *) MPIR_QMPI_first_fn_ptrs[MPI_WTIME_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_WTIME_T]);
}
#else /* ENABLE_QMPI */
double MPI_Wtime(void)
{
    return internal_Wtime();
}

#endif /* ENABLE_QMPI */
