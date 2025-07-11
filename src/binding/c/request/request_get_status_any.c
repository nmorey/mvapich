/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Request_get_status_any */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Request_get_status_any = PMPI_Request_get_status_any
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Request_get_status_any  MPI_Request_get_status_any
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Request_get_status_any as PMPI_Request_get_status_any
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Request_get_status_any(int count, MPI_Request array_of_requests[], int *indx, int *flag,
                               MPI_Status *status)
                                __attribute__ ((weak, alias("PMPI_Request_get_status_any")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Request_get_status_any
#define MPI_Request_get_status_any PMPI_Request_get_status_any
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Request_get_status_any(int count, MPI_Request array_of_requests[], int *indx,
                                           int *flag, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Request *request_ptr_array[MPIR_REQUEST_PTR_ARRAY_SIZE];
    MPIR_Request **request_ptrs = request_ptr_array;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            if (count > 0) {
                MPIR_ERRTEST_ARGNULL(array_of_requests, "array_of_requests", mpi_errno);
                for (int i = 0; i < count; i++) {
                    MPIR_ERRTEST_ARRAYREQUEST_OR_NULL(array_of_requests[i], i, mpi_errno);
                }
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    if (count > MPIR_REQUEST_PTR_ARRAY_SIZE) {
        int nbytes = count * sizeof(MPIR_Request *);
        request_ptrs = (MPIR_Request **) MPL_malloc(nbytes, MPL_MEM_OBJECT);
        if (request_ptrs == NULL) {
            MPIR_CHKMEM_SETERR(mpi_errno, nbytes, "request pointers");
            goto fn_fail;
        }
    }

    for (int i = 0; i < count; i++) {
        MPIR_Request_get_ptr(array_of_requests[i], request_ptrs[i]);
    }

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            for (int i = 0; i < count; i++) {
                if (array_of_requests[i] != MPI_REQUEST_NULL) {
                    MPIR_Request_valid_ptr(request_ptrs[i], mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
            }
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            MPIR_ERRTEST_ARGNULL(indx, "indx", mpi_errno);
            MPIR_ERRTEST_ARGNULL(flag, "flag", mpi_errno);
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Testany(count, request_ptrs, indx, flag, status);
    if (mpi_errno) {
        goto fn_fail;
    }
    /* ... end of body of routine ... */

  fn_exit:
    if (count > MPIR_REQUEST_PTR_ARRAY_SIZE) {
        MPL_free(request_ptrs);
    }
    MPIR_FUNC_TERSE_EXIT;
    MPID_THREAD_CS_EXIT(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_request_get_status_any",
                                     "**mpi_request_get_status_any %d %p %p %p %p", count,
                                     array_of_requests, indx, flag, status);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Request_get_status_any(QMPI_Context context, int tool_id, int count,
                                MPI_Request array_of_requests[], int *indx, int *flag,
                                MPI_Status *status)
{
    return internal_Request_get_status_any(count, array_of_requests, indx, flag, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Request_get_status_any(int count, MPI_Request array_of_requests[], int *indx, int *flag,
                               MPI_Status *status)
{
    QMPI_Context context;
    QMPI_Request_get_status_any_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Request_get_status_any(context, 0, count, array_of_requests, indx, flag,
                                           status);

    fn_ptr = (QMPI_Request_get_status_any_t *) MPIR_QMPI_first_fn_ptrs[MPI_REQUEST_GET_STATUS_ANY_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_REQUEST_GET_STATUS_ANY_T], count,
            array_of_requests, indx, flag, status);
}
#else /* ENABLE_QMPI */
int MPI_Request_get_status_any(int count, MPI_Request array_of_requests[], int *indx, int *flag,
                               MPI_Status *status)
{
    return internal_Request_get_status_any(count, array_of_requests, indx, flag, status);
}

#endif /* ENABLE_QMPI */
