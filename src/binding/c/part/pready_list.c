/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Pready_list */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Pready_list = PMPI_Pready_list
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Pready_list  MPI_Pready_list
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Pready_list as PMPI_Pready_list
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Pready_list(int length, const int array_of_partitions[], MPI_Request request)
     __attribute__ ((weak, alias("PMPI_Pready_list")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Pready_list
#define MPI_Pready_list PMPI_Pready_list
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Pready_list(int length, const int array_of_partitions[], MPI_Request request)
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
            MPIR_ERRTEST_REQUEST(request, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_Request_get_ptr(request, request_ptr);

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_Request_valid_ptr(request_ptr, mpi_errno);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_ERRTEST_PREADYREQ(request_ptr, mpi_errno);
            MPIR_ERRTEST_ARGNEG(length, "length", mpi_errno);
            if (length > 0) {
                MPIR_ERRTEST_ARGNULL(array_of_partitions, "array_of_partitions", mpi_errno);
                for (int i = 0; i < length; i++) {
                    MPIR_ERRTEST_PARTITION(array_of_partitions[i], request_ptr, mpi_errno);
                }
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPID_Pready_list(length, array_of_partitions, request_ptr);
    if (mpi_errno != MPI_SUCCESS)
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
                                     "**mpi_pready_list", "**mpi_pready_list %d %p %R", length,
                                     array_of_partitions, request);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Pready_list(QMPI_Context context, int tool_id, int length, const int array_of_partitions[],
                     MPI_Request request)
{
    return internal_Pready_list(length, array_of_partitions, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Pready_list(int length, const int array_of_partitions[], MPI_Request request)
{
    QMPI_Context context;
    QMPI_Pready_list_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Pready_list(context, 0, length, array_of_partitions, request);

    fn_ptr = (QMPI_Pready_list_t *) MPIR_QMPI_first_fn_ptrs[MPI_PREADY_LIST_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_PREADY_LIST_T], length,
            array_of_partitions, request);
}
#else /* ENABLE_QMPI */
int MPI_Pready_list(int length, const int array_of_partitions[], MPI_Request request)
{
    return internal_Pready_list(length, array_of_partitions, request);
}

#endif /* ENABLE_QMPI */
