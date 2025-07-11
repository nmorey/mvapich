/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPIX_Wait_enqueue */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPIX_Wait_enqueue = PMPIX_Wait_enqueue
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPIX_Wait_enqueue  MPIX_Wait_enqueue
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPIX_Wait_enqueue as PMPIX_Wait_enqueue
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPIX_Wait_enqueue(MPI_Request *request, MPI_Status *status)
     __attribute__ ((weak, alias("PMPIX_Wait_enqueue")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPIX_Wait_enqueue
#define MPIX_Wait_enqueue PMPIX_Wait_enqueue
#endif /* MPICH_MPI_FROM_PMPI */

static int internalX_Wait_enqueue(MPI_Request *request, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Request *request_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
            MPIR_ERRTEST_REQUEST_OR_NULL(*request, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    if (*request != MPI_REQUEST_NULL) {
        MPIR_Request_get_ptr(*request, request_ptr);
    }

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            if (*request != MPI_REQUEST_NULL) {
                MPIR_Request_valid_ptr(request_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPID_Wait_enqueue(request_ptr, status);
    if (mpi_errno) {
        goto fn_fail;
    }
    *request = MPI_REQUEST_NULL;
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    MPID_THREAD_CS_EXIT(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpix_wait_enqueue", "**mpix_wait_enqueue %p %p", request,
                                     status);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPIX_Wait_enqueue(QMPI_Context context, int tool_id, MPI_Request *request, MPI_Status *status)
{
    return internalX_Wait_enqueue(request, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPIX_Wait_enqueue(MPI_Request *request, MPI_Status *status)
{
    QMPI_Context context;
    QMPIX_Wait_enqueue_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPIX_Wait_enqueue(context, 0, request, status);

    fn_ptr = (QMPIX_Wait_enqueue_t *) MPIR_QMPI_first_fn_ptrs[MPIX_WAIT_ENQUEUE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPIX_WAIT_ENQUEUE_T], request, status);
}
#else /* ENABLE_QMPI */
int MPIX_Wait_enqueue(MPI_Request *request, MPI_Status *status)
{
    return internalX_Wait_enqueue(request, status);
}

#endif /* ENABLE_QMPI */
