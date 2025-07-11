/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPIX_Grequest_class_create */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPIX_Grequest_class_create = PMPIX_Grequest_class_create
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPIX_Grequest_class_create  MPIX_Grequest_class_create
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPIX_Grequest_class_create as PMPIX_Grequest_class_create
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPIX_Grequest_class_create(MPI_Grequest_query_function *query_fn,
                               MPI_Grequest_free_function *free_fn,
                               MPI_Grequest_cancel_function *cancel_fn,
                               MPIX_Grequest_poll_function *poll_fn,
                               MPIX_Grequest_wait_function *wait_fn,
                               MPIX_Grequest_class *greq_class)
                                __attribute__ ((weak, alias("PMPIX_Grequest_class_create")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPIX_Grequest_class_create
#define MPIX_Grequest_class_create PMPIX_Grequest_class_create
#endif /* MPICH_MPI_FROM_PMPI */

static int internalX_Grequest_class_create(MPI_Grequest_query_function *query_fn,
                                           MPI_Grequest_free_function *free_fn,
                                           MPI_Grequest_cancel_function *cancel_fn,
                                           MPIX_Grequest_poll_function *poll_fn,
                                           MPIX_Grequest_wait_function *wait_fn,
                                           MPIX_Grequest_class *greq_class)
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
            MPIR_ERRTEST_ARGNULL(greq_class, "greq_class", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Grequest_class_create_impl(query_fn, free_fn, cancel_fn, poll_fn, wait_fn,
                                                greq_class);
    if (mpi_errno) {
        goto fn_fail;
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
                                     "**mpix_grequest_class_create",
                                     "**mpix_grequest_class_create %p %p %p %p %p %p", query_fn,
                                     free_fn, cancel_fn, poll_fn, wait_fn, greq_class);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPIX_Grequest_class_create(QMPI_Context context, int tool_id,
                                MPI_Grequest_query_function *query_fn,
                                MPI_Grequest_free_function *free_fn,
                                MPI_Grequest_cancel_function *cancel_fn,
                                MPIX_Grequest_poll_function *poll_fn,
                                MPIX_Grequest_wait_function *wait_fn,
                                MPIX_Grequest_class *greq_class)
{
    return internalX_Grequest_class_create(query_fn, free_fn, cancel_fn, poll_fn, wait_fn, greq_class);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPIX_Grequest_class_create(MPI_Grequest_query_function *query_fn,
                               MPI_Grequest_free_function *free_fn,
                               MPI_Grequest_cancel_function *cancel_fn,
                               MPIX_Grequest_poll_function *poll_fn,
                               MPIX_Grequest_wait_function *wait_fn,
                               MPIX_Grequest_class *greq_class)
{
    QMPI_Context context;
    QMPIX_Grequest_class_create_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPIX_Grequest_class_create(context, 0, query_fn, free_fn, cancel_fn, poll_fn,
                                           wait_fn, greq_class);

    fn_ptr = (QMPIX_Grequest_class_create_t *) MPIR_QMPI_first_fn_ptrs[MPIX_GREQUEST_CLASS_CREATE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPIX_GREQUEST_CLASS_CREATE_T], query_fn,
            free_fn, cancel_fn, poll_fn, wait_fn, greq_class);
}
#else /* ENABLE_QMPI */
int MPIX_Grequest_class_create(MPI_Grequest_query_function *query_fn,
                               MPI_Grequest_free_function *free_fn,
                               MPI_Grequest_cancel_function *cancel_fn,
                               MPIX_Grequest_poll_function *poll_fn,
                               MPIX_Grequest_wait_function *wait_fn,
                               MPIX_Grequest_class *greq_class)
{
    return internalX_Grequest_class_create(query_fn, free_fn, cancel_fn, poll_fn, wait_fn, greq_class);
}

#endif /* ENABLE_QMPI */
