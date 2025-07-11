/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Request_get_status */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Request_get_status = PMPI_Request_get_status
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Request_get_status  MPI_Request_get_status
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Request_get_status as PMPI_Request_get_status
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Request_get_status(MPI_Request request, int *flag, MPI_Status *status)
     __attribute__ ((weak, alias("PMPI_Request_get_status")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Request_get_status
#define MPI_Request_get_status PMPI_Request_get_status
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Request_get_status(MPI_Request request, int *flag, MPI_Status *status)
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
            MPIR_ERRTEST_REQUEST_OR_NULL(request, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    if (request != MPI_REQUEST_NULL) {
        MPIR_Request_get_ptr(request, request_ptr);
    }

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            if (request != MPI_REQUEST_NULL) {
                MPIR_Request_valid_ptr(request_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            MPIR_ERRTEST_ARGNULL(flag, "flag", mpi_errno);
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    if (request == MPI_REQUEST_NULL || !MPIR_Request_is_active(request_ptr)) {
        *flag = 1;
        MPIR_Status_set_empty(status);
        goto fn_exit;
    }

    /* ... body of routine ... */
    mpi_errno = MPIR_Test(request_ptr, flag, status);
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
                                     "**mpi_request_get_status", "**mpi_request_get_status %R %p %p",
                                     request, flag, status);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Request_get_status(QMPI_Context context, int tool_id, MPI_Request request, int *flag,
                            MPI_Status *status)
{
    return internal_Request_get_status(request, flag, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Request_get_status(MPI_Request request, int *flag, MPI_Status *status)
{
    QMPI_Context context;
    QMPI_Request_get_status_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Request_get_status(context, 0, request, flag, status);

    fn_ptr = (QMPI_Request_get_status_t *) MPIR_QMPI_first_fn_ptrs[MPI_REQUEST_GET_STATUS_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_REQUEST_GET_STATUS_T], request, flag,
            status);
}
#else /* ENABLE_QMPI */
int MPI_Request_get_status(MPI_Request request, int *flag, MPI_Status *status)
{
    return internal_Request_get_status(request, flag, status);
}

#endif /* ENABLE_QMPI */
