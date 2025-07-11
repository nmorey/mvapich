/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Query_thread */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Query_thread = PMPI_Query_thread
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Query_thread  MPI_Query_thread
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Query_thread as PMPI_Query_thread
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Query_thread(int *provided)  __attribute__ ((weak, alias("PMPI_Query_thread")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Query_thread
#define MPI_Query_thread PMPI_Query_thread
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Query_thread(int *provided)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(provided, "provided", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Query_thread_impl(provided);
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
                                     "**mpi_query_thread", "**mpi_query_thread %p", provided);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Query_thread(QMPI_Context context, int tool_id, int *provided)
{
    return internal_Query_thread(provided);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Query_thread(int *provided)
{
    QMPI_Context context;
    QMPI_Query_thread_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Query_thread(context, 0, provided);

    fn_ptr = (QMPI_Query_thread_t *) MPIR_QMPI_first_fn_ptrs[MPI_QUERY_THREAD_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_QUERY_THREAD_T], provided);
}
#else /* ENABLE_QMPI */
int MPI_Query_thread(int *provided)
{
    return internal_Query_thread(provided);
}

#endif /* ENABLE_QMPI */
