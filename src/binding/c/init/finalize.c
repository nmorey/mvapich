/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Finalize */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Finalize = PMPI_Finalize
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Finalize  MPI_Finalize
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Finalize as PMPI_Finalize
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Finalize(void)  __attribute__ ((weak, alias("PMPI_Finalize")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Finalize
#define MPI_Finalize PMPI_Finalize
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Finalize(void)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();
    MPIR_FUNC_TERSE_ENTER;

    /* ... body of routine ... */
    mpi_errno = MPIR_Finalize_impl();
    if (mpi_errno) {
        goto fn_fail;
    }
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_finalize", 0);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Finalize(QMPI_Context context, int tool_id)
{
    return internal_Finalize();
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Finalize(void)
{
    QMPI_Context context;
    QMPI_Finalize_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Finalize(context, 0);

    fn_ptr = (QMPI_Finalize_t *) MPIR_QMPI_first_fn_ptrs[MPI_FINALIZE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FINALIZE_T]);
}
#else /* ENABLE_QMPI */
int MPI_Finalize(void)
{
    return internal_Finalize();
}

#endif /* ENABLE_QMPI */
