/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPIX_Win_create_errhandler_x */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPIX_Win_create_errhandler_x = PMPIX_Win_create_errhandler_x
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPIX_Win_create_errhandler_x  MPIX_Win_create_errhandler_x
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPIX_Win_create_errhandler_x as PMPIX_Win_create_errhandler_x
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPIX_Win_create_errhandler_x(MPIX_Win_errhandler_function_x *comm_errhandler_fn_x,
                                 MPIX_Destructor_function *destructor_fn, void *extra_state,
                                 MPI_Errhandler *errhandler)
                                  __attribute__ ((weak, alias("PMPIX_Win_create_errhandler_x")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPIX_Win_create_errhandler_x
#define MPIX_Win_create_errhandler_x PMPIX_Win_create_errhandler_x
#endif /* MPICH_MPI_FROM_PMPI */

static int internalX_Win_create_errhandler_x(MPIX_Win_errhandler_function_x *comm_errhandler_fn_x,
                                             MPIX_Destructor_function *destructor_fn,
                                             void *extra_state, MPI_Errhandler *errhandler)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(comm_errhandler_fn_x, "comm_errhandler_fn_x", mpi_errno);
            MPIR_ERRTEST_ARGNULL(destructor_fn, "destructor_fn", mpi_errno);
            MPIR_ERRTEST_ARGNULL(errhandler, "errhandler", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPIR_Errhandler *errhandler_ptr ATTRIBUTE((unused)) = NULL;
    *errhandler = MPI_ERRHANDLER_NULL;
    mpi_errno = MPIR_Win_create_errhandler_x_impl(comm_errhandler_fn_x, destructor_fn, extra_state,
                                                  &errhandler_ptr);
    if (mpi_errno) {
        goto fn_fail;
    }
    if (errhandler_ptr) {
        MPIR_OBJ_PUBLISH_HANDLE(*errhandler, errhandler_ptr->handle);
    }
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    MPID_THREAD_CS_EXIT(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpix_win_create_errhandler_x",
                                     "**mpix_win_create_errhandler_x %p %p %p %p", comm_errhandler_fn_x,
                                     destructor_fn, extra_state, errhandler);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPIX_Win_create_errhandler_x(QMPI_Context context, int tool_id,
                                  MPIX_Win_errhandler_function_x *comm_errhandler_fn_x,
                                  MPIX_Destructor_function *destructor_fn, void *extra_state,
                                  MPI_Errhandler *errhandler)
{
    return internalX_Win_create_errhandler_x(comm_errhandler_fn_x, destructor_fn, extra_state, errhandler);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPIX_Win_create_errhandler_x(MPIX_Win_errhandler_function_x *comm_errhandler_fn_x,
                                 MPIX_Destructor_function *destructor_fn, void *extra_state,
                                 MPI_Errhandler *errhandler)
{
    QMPI_Context context;
    QMPIX_Win_create_errhandler_x_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPIX_Win_create_errhandler_x(context, 0, comm_errhandler_fn_x, destructor_fn,
                                             extra_state, errhandler);

    fn_ptr = (QMPIX_Win_create_errhandler_x_t *) MPIR_QMPI_first_fn_ptrs[MPIX_WIN_CREATE_ERRHANDLER_X_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPIX_WIN_CREATE_ERRHANDLER_X_T],
            comm_errhandler_fn_x, destructor_fn, extra_state, errhandler);
}
#else /* ENABLE_QMPI */
int MPIX_Win_create_errhandler_x(MPIX_Win_errhandler_function_x *comm_errhandler_fn_x,
                                 MPIX_Destructor_function *destructor_fn, void *extra_state,
                                 MPI_Errhandler *errhandler)
{
    return internalX_Win_create_errhandler_x(comm_errhandler_fn_x, destructor_fn, extra_state, errhandler);
}

#endif /* ENABLE_QMPI */
