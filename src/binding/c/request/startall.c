/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Startall */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Startall = PMPI_Startall
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Startall  MPI_Startall
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Startall as PMPI_Startall
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Startall(int count, MPI_Request array_of_requests[])
     __attribute__ ((weak, alias("PMPI_Startall")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Startall
#define MPI_Startall PMPI_Startall
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Startall(int count, MPI_Request array_of_requests[])
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
                    MPIR_ERRTEST_REQUEST(array_of_requests[i], mpi_errno);
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
                MPIR_Request_valid_ptr(request_ptrs[i], mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
                MPIR_ERRTEST_STARTREQ(request_ptrs[i], mpi_errno);
                MPIR_ERRTEST_STARTREQ_ACTIVE(request_ptrs[i], mpi_errno);
            }
            MPIR_ERRTEST_COUNT(count, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPID_Startall(count, request_ptrs);
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
                                     "**mpi_startall", "**mpi_startall %d %p", count,
                                     array_of_requests);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Startall(QMPI_Context context, int tool_id, int count, MPI_Request array_of_requests[])
{
    return internal_Startall(count, array_of_requests);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Startall(int count, MPI_Request array_of_requests[])
{
    QMPI_Context context;
    QMPI_Startall_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Startall(context, 0, count, array_of_requests);

    fn_ptr = (QMPI_Startall_t *) MPIR_QMPI_first_fn_ptrs[MPI_STARTALL_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_STARTALL_T], count, array_of_requests);
}
#else /* ENABLE_QMPI */
int MPI_Startall(int count, MPI_Request array_of_requests[])
{
    return internal_Startall(count, array_of_requests);
}

#endif /* ENABLE_QMPI */
