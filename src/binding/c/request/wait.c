/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Wait */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Wait = PMPI_Wait
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Wait  MPI_Wait
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Wait as PMPI_Wait
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Wait(MPI_Request *request, MPI_Status *status)  __attribute__ ((weak, alias("PMPI_Wait")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Wait
#define MPI_Wait PMPI_Wait
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Wait(MPI_Request *request, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Request *request_ptr ATTRIBUTE((unused)) = NULL;
    MPIR_Comm *comm_ptr = NULL;

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
    if (request_ptr) {
        /* Because %s may be freed, save a copy of comm_ptr for use at fn_fail */
        comm_ptr = request_ptr->comm;
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

    if (*request == MPI_REQUEST_NULL || !MPIR_Request_is_active(request_ptr)) {
        MPIR_Status_set_empty(status);
        goto fn_exit;
    }

    /* ... body of routine ... */
    mpi_errno = MPIR_Wait(request_ptr, status);
    if (!MPIR_Request_is_persistent(request_ptr)) {
        int rc = MPIR_Request_free_return(request_ptr);
        *request = MPI_REQUEST_NULL;
        if (rc) {
            mpi_errno = rc;
        }
    }
    if (mpi_errno)
        goto fn_fail;

    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    MPID_THREAD_CS_EXIT(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_wait", "**mpi_wait %p %p", request, status);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Wait(QMPI_Context context, int tool_id, MPI_Request *request, MPI_Status *status)
{
    return internal_Wait(request, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Wait(MPI_Request *request, MPI_Status *status)
{
    QMPI_Context context;
    QMPI_Wait_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Wait(context, 0, request, status);

    fn_ptr = (QMPI_Wait_t *) MPIR_QMPI_first_fn_ptrs[MPI_WAIT_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_WAIT_T], request, status);
}
#else /* ENABLE_QMPI */
int MPI_Wait(MPI_Request *request, MPI_Status *status)
{
    return internal_Wait(request, status);
}

#endif /* ENABLE_QMPI */
