/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Is_thread_main */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Is_thread_main = PMPI_Is_thread_main
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Is_thread_main  MPI_Is_thread_main
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Is_thread_main as PMPI_Is_thread_main
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Is_thread_main(int *flag)  __attribute__ ((weak, alias("PMPI_Is_thread_main")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Is_thread_main
#define MPI_Is_thread_main PMPI_Is_thread_main
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Is_thread_main(int *flag)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(flag, "flag", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Is_thread_main_impl(flag);
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
                                     "**mpi_is_thread_main", "**mpi_is_thread_main %p", flag);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Is_thread_main(QMPI_Context context, int tool_id, int *flag)
{
    return internal_Is_thread_main(flag);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Is_thread_main(int *flag)
{
    QMPI_Context context;
    QMPI_Is_thread_main_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Is_thread_main(context, 0, flag);

    fn_ptr = (QMPI_Is_thread_main_t *) MPIR_QMPI_first_fn_ptrs[MPI_IS_THREAD_MAIN_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_IS_THREAD_MAIN_T], flag);
}
#else /* ENABLE_QMPI */
int MPI_Is_thread_main(int *flag)
{
    return internal_Is_thread_main(flag);
}

#endif /* ENABLE_QMPI */
