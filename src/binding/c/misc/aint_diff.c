/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Aint_diff */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Aint_diff = PMPI_Aint_diff
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Aint_diff  MPI_Aint_diff
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Aint_diff as PMPI_Aint_diff
#elif defined(HAVE_WEAK_ATTRIBUTE)
MPI_Aint MPI_Aint_diff(MPI_Aint addr1, MPI_Aint addr2)
     __attribute__ ((weak, alias("PMPI_Aint_diff")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Aint_diff
#define MPI_Aint_diff PMPI_Aint_diff
#endif /* MPICH_MPI_FROM_PMPI */

static MPI_Aint internal_Aint_diff(MPI_Aint addr1, MPI_Aint addr2)
{
    MPI_Aint result;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_FUNC_TERSE_ENTER;
    result = MPID_Aint_diff(addr1, addr2);
    MPIR_FUNC_TERSE_EXIT;

    return result;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
MPI_Aint QMPI_Aint_diff(QMPI_Context context, int tool_id, MPI_Aint addr1, MPI_Aint addr2)
{
    return internal_Aint_diff(addr1, addr2);
}
#endif /* MPICH_MPI_FROM_PMPI */
MPI_Aint MPI_Aint_diff(MPI_Aint addr1, MPI_Aint addr2)
{
    QMPI_Context context;
    QMPI_Aint_diff_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Aint_diff(context, 0, addr1, addr2);

    fn_ptr = (QMPI_Aint_diff_t *) MPIR_QMPI_first_fn_ptrs[MPI_AINT_DIFF_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_AINT_DIFF_T], addr1, addr2);
}
#else /* ENABLE_QMPI */
MPI_Aint MPI_Aint_diff(MPI_Aint addr1, MPI_Aint addr2)
{
    return internal_Aint_diff(addr1, addr2);
}

#endif /* ENABLE_QMPI */
