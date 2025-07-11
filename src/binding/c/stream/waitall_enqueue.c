/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPIX_Waitall_enqueue */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPIX_Waitall_enqueue = PMPIX_Waitall_enqueue
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPIX_Waitall_enqueue  MPIX_Waitall_enqueue
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPIX_Waitall_enqueue as PMPIX_Waitall_enqueue
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPIX_Waitall_enqueue(int count, MPI_Request array_of_requests[], MPI_Status *array_of_statuses)
     __attribute__ ((weak, alias("PMPIX_Waitall_enqueue")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPIX_Waitall_enqueue
#define MPIX_Waitall_enqueue PMPIX_Waitall_enqueue
#endif /* MPICH_MPI_FROM_PMPI */

static int internalX_Waitall_enqueue(int count, MPI_Request array_of_requests[],
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
            if (count > 0) {
                MPIR_ERRTEST_ARGNULL(array_of_statuses, "array_of_statuses", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPID_Waitall_enqueue(count, array_of_requests, array_of_statuses);
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
                                     "**mpix_waitall_enqueue", "**mpix_waitall_enqueue %d %p %p", count,
                                     array_of_requests, array_of_statuses);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPIX_Waitall_enqueue(QMPI_Context context, int tool_id, int count,
                          MPI_Request array_of_requests[], MPI_Status *array_of_statuses)
{
    return internalX_Waitall_enqueue(count, array_of_requests, array_of_statuses);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPIX_Waitall_enqueue(int count, MPI_Request array_of_requests[], MPI_Status *array_of_statuses)
{
    QMPI_Context context;
    QMPIX_Waitall_enqueue_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPIX_Waitall_enqueue(context, 0, count, array_of_requests, array_of_statuses);

    fn_ptr = (QMPIX_Waitall_enqueue_t *) MPIR_QMPI_first_fn_ptrs[MPIX_WAITALL_ENQUEUE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPIX_WAITALL_ENQUEUE_T], count,
            array_of_requests, array_of_statuses);
}
#else /* ENABLE_QMPI */
int MPIX_Waitall_enqueue(int count, MPI_Request array_of_requests[], MPI_Status *array_of_statuses)
{
    return internalX_Waitall_enqueue(count, array_of_requests, array_of_statuses);
}

#endif /* ENABLE_QMPI */
