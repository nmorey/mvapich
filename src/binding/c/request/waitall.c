/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Waitall */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Waitall = PMPI_Waitall
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Waitall  MPI_Waitall
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Waitall as PMPI_Waitall
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Waitall(int count, MPI_Request array_of_requests[], MPI_Status *array_of_statuses)
     __attribute__ ((weak, alias("PMPI_Waitall")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Waitall
#define MPI_Waitall PMPI_Waitall
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Waitall(int count, MPI_Request array_of_requests[],
                            MPI_Status *array_of_statuses)
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
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (array_of_statuses != MPI_STATUSES_IGNORE && count > 0) {
                MPIR_ERRTEST_ARGNULL(array_of_statuses, "array_of_statuses", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Waitall(count, request_ptrs, array_of_statuses);
    for (int i = 0; i < count; i++) {
        if (mpi_errno && array_of_statuses != MPI_STATUSES_IGNORE
            && array_of_statuses[i].MPI_ERROR == MPI_ERR_PENDING) {
            continue;
        }
        if (request_ptrs[i] && !MPIR_Request_is_persistent(request_ptrs[i])) {
            int rc = MPIR_Request_free_return(request_ptrs[i]);
            array_of_requests[i] = MPI_REQUEST_NULL;
            if (rc) {
                if (array_of_statuses == MPI_STATUSES_IGNORE) {
                    mpi_errno = MPI_ERR_IN_STATUS;
                } else if (mpi_errno == MPI_ERR_IN_STATUS) {
                    array_of_statuses[i].MPI_ERROR = rc;
                } else {
                    MPIR_Assert(mpi_errno == MPI_SUCCESS);
                    /* init all statuses' MPI_ERROR fields first */
                    for (int j = 0; j < count; j++) {
                        array_of_statuses[j].MPI_ERROR = MPI_SUCCESS;
                    }
                    mpi_errno = MPI_ERR_IN_STATUS;
                    array_of_statuses[i].MPI_ERROR = rc;
                }
            }
        }
    }
    if (mpi_errno)
        goto fn_fail;
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
                                     "**mpi_waitall", "**mpi_waitall %d %p %p", count,
                                     array_of_requests, array_of_statuses);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Waitall(QMPI_Context context, int tool_id, int count, MPI_Request array_of_requests[],
                 MPI_Status *array_of_statuses)
{
    return internal_Waitall(count, array_of_requests, array_of_statuses);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Waitall(int count, MPI_Request array_of_requests[], MPI_Status *array_of_statuses)
{
    QMPI_Context context;
    QMPI_Waitall_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Waitall(context, 0, count, array_of_requests, array_of_statuses);

    fn_ptr = (QMPI_Waitall_t *) MPIR_QMPI_first_fn_ptrs[MPI_WAITALL_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_WAITALL_T], count, array_of_requests,
            array_of_statuses);
}
#else /* ENABLE_QMPI */
int MPI_Waitall(int count, MPI_Request array_of_requests[], MPI_Status *array_of_statuses)
{
    return internal_Waitall(count, array_of_requests, array_of_statuses);
}

#endif /* ENABLE_QMPI */
