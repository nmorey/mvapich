/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPIX_Grequest_start */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPIX_Grequest_start = PMPIX_Grequest_start
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPIX_Grequest_start  MPIX_Grequest_start
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPIX_Grequest_start as PMPIX_Grequest_start
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPIX_Grequest_start(MPI_Grequest_query_function *query_fn, MPI_Grequest_free_function *free_fn,
                        MPI_Grequest_cancel_function *cancel_fn,
                        MPIX_Grequest_poll_function *poll_fn, MPIX_Grequest_wait_function *wait_fn,
                        void *extra_state, MPI_Request *request)
                         __attribute__ ((weak, alias("PMPIX_Grequest_start")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPIX_Grequest_start
#define MPIX_Grequest_start PMPIX_Grequest_start
#endif /* MPICH_MPI_FROM_PMPI */

static int internalX_Grequest_start(MPI_Grequest_query_function *query_fn,
                                    MPI_Grequest_free_function *free_fn,
                                    MPI_Grequest_cancel_function *cancel_fn,
                                    MPIX_Grequest_poll_function *poll_fn,
                                    MPIX_Grequest_wait_function *wait_fn, void *extra_state,
                                    MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(query_fn, "query_fn", mpi_errno);
            MPIR_ERRTEST_ARGNULL(free_fn, "free_fn", mpi_errno);
            MPIR_ERRTEST_ARGNULL(cancel_fn, "cancel_fn", mpi_errno);
            MPIR_ERRTEST_ARGNULL(poll_fn, "poll_fn", mpi_errno);
            MPIR_ERRTEST_ARGNULL(wait_fn, "wait_fn", mpi_errno);
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPIR_Request *request_ptr = NULL;
    mpi_errno = MPIR_Grequest_start_impl(query_fn, free_fn, cancel_fn, extra_state, &request_ptr);
    if (mpi_errno) {
        goto fn_fail;
    }
    request_ptr->u.ureq.greq_fns->poll_fn = poll_fn;
    request_ptr->u.ureq.greq_fns->wait_fn = wait_fn;
    *request = request_ptr->handle;
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    MPID_THREAD_CS_EXIT(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpix_grequest_start",
                                     "**mpix_grequest_start %p %p %p %p %p %p %p", query_fn, free_fn,
                                     cancel_fn, poll_fn, wait_fn, extra_state, request);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPIX_Grequest_start(QMPI_Context context, int tool_id, MPI_Grequest_query_function *query_fn,
                         MPI_Grequest_free_function *free_fn,
                         MPI_Grequest_cancel_function *cancel_fn,
                         MPIX_Grequest_poll_function *poll_fn, MPIX_Grequest_wait_function *wait_fn,
                         void *extra_state, MPI_Request *request)
{
    return internalX_Grequest_start(query_fn, free_fn, cancel_fn, poll_fn, wait_fn, extra_state, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPIX_Grequest_start(MPI_Grequest_query_function *query_fn, MPI_Grequest_free_function *free_fn,
                        MPI_Grequest_cancel_function *cancel_fn,
                        MPIX_Grequest_poll_function *poll_fn, MPIX_Grequest_wait_function *wait_fn,
                        void *extra_state, MPI_Request *request)
{
    QMPI_Context context;
    QMPIX_Grequest_start_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPIX_Grequest_start(context, 0, query_fn, free_fn, cancel_fn, poll_fn, wait_fn,
                                    extra_state, request);

    fn_ptr = (QMPIX_Grequest_start_t *) MPIR_QMPI_first_fn_ptrs[MPIX_GREQUEST_START_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPIX_GREQUEST_START_T], query_fn, free_fn,
            cancel_fn, poll_fn, wait_fn, extra_state, request);
}
#else /* ENABLE_QMPI */
int MPIX_Grequest_start(MPI_Grequest_query_function *query_fn, MPI_Grequest_free_function *free_fn,
                        MPI_Grequest_cancel_function *cancel_fn,
                        MPIX_Grequest_poll_function *poll_fn, MPIX_Grequest_wait_function *wait_fn,
                        void *extra_state, MPI_Request *request)
{
    return internalX_Grequest_start(query_fn, free_fn, cancel_fn, poll_fn, wait_fn, extra_state, request);
}

#endif /* ENABLE_QMPI */
