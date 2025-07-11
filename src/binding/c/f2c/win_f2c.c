/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Win_f2c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Win_f2c = PMPI_Win_f2c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Win_f2c  MPI_Win_f2c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Win_f2c as PMPI_Win_f2c
#elif defined(HAVE_WEAK_ATTRIBUTE)
MPI_Win MPI_Win_f2c(MPI_Fint win)  __attribute__ ((weak, alias("PMPI_Win_f2c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Win_f2c
#define MPI_Win_f2c PMPI_Win_f2c
#endif /* MPICH_MPI_FROM_PMPI */

static MPI_Win internal_Win_f2c(MPI_Fint win)
{
    return (MPI_Win) win;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
MPI_Win QMPI_Win_f2c(QMPI_Context context, int tool_id, MPI_Fint win)
{
    return internal_Win_f2c(win);
}
#endif /* MPICH_MPI_FROM_PMPI */
MPI_Win MPI_Win_f2c(MPI_Fint win)
{
    QMPI_Context context;
    QMPI_Win_f2c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Win_f2c(context, 0, win);

    fn_ptr = (QMPI_Win_f2c_t *) MPIR_QMPI_first_fn_ptrs[MPI_WIN_F2C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_WIN_F2C_T], win);
}
#else /* ENABLE_QMPI */
MPI_Win MPI_Win_f2c(MPI_Fint win)
{
    return internal_Win_f2c(win);
}

#endif /* ENABLE_QMPI */
