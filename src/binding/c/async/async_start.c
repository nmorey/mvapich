/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPIX_Async_start */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPIX_Async_start = PMPIX_Async_start
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPIX_Async_start  MPIX_Async_start
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPIX_Async_start as PMPIX_Async_start
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPIX_Async_start(MPIX_Async_poll_function *poll_fn, void *extra_state, MPIX_Stream stream)
     __attribute__ ((weak, alias("PMPIX_Async_start")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPIX_Async_start
#define MPIX_Async_start PMPIX_Async_start
#endif /* MPICH_MPI_FROM_PMPI */

static int internalX_Async_start(MPIX_Async_poll_function *poll_fn, void *extra_state,
                                 MPIX_Stream stream)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Stream *stream_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    if (stream != MPIX_STREAM_NULL) {
        MPIR_Stream_get_ptr(stream, stream_ptr);
    }

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            if (stream != MPIX_STREAM_NULL) {
                MPIR_Stream_valid_ptr(stream_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            MPIR_ERRTEST_ARGNULL(poll_fn, "poll_fn", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Async_things_add(poll_fn, extra_state, stream_ptr);
    if (mpi_errno) goto fn_fail;
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    MPID_THREAD_CS_EXIT(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpix_async_start", "**mpix_async_start %p %p %x", poll_fn,
                                     extra_state, stream);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPIX_Async_start(QMPI_Context context, int tool_id, MPIX_Async_poll_function *poll_fn,
                      void *extra_state, MPIX_Stream stream)
{
    return internalX_Async_start(poll_fn, extra_state, stream);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPIX_Async_start(MPIX_Async_poll_function *poll_fn, void *extra_state, MPIX_Stream stream)
{
    QMPI_Context context;
    QMPIX_Async_start_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPIX_Async_start(context, 0, poll_fn, extra_state, stream);

    fn_ptr = (QMPIX_Async_start_t *) MPIR_QMPI_first_fn_ptrs[MPIX_ASYNC_START_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPIX_ASYNC_START_T], poll_fn, extra_state,
            stream);
}
#else /* ENABLE_QMPI */
int MPIX_Async_start(MPIX_Async_poll_function *poll_fn, void *extra_state, MPIX_Stream stream)
{
    return internalX_Async_start(poll_fn, extra_state, stream);
}

#endif /* ENABLE_QMPI */
