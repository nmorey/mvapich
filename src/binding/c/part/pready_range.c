/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Pready_range */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Pready_range = PMPI_Pready_range
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Pready_range  MPI_Pready_range
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Pready_range as PMPI_Pready_range
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Pready_range(int partition_low, int partition_high, MPI_Request request)
     __attribute__ ((weak, alias("PMPI_Pready_range")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Pready_range
#define MPI_Pready_range PMPI_Pready_range
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Pready_range(int partition_low, int partition_high, MPI_Request request)
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
            MPIR_ERRTEST_PARTITION(partition_low, request_ptr, mpi_errno);
            MPIR_ERRTEST_PARTITION(partition_high, request_ptr, mpi_errno);
            if (partition_low > partition_high) {
                mpi_errno = MPIR_Err_create_code(MPI_SUCCESS,
                                           MPIR_ERR_RECOVERABLE,
                                           __func__, __LINE__,
                                           MPI_ERR_OTHER,
                                           "**partitioninvalid", "**partitioninvalid %d %d",
                                           partition_low, partition_high);
                goto fn_fail;
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPID_Pready_range(partition_low, partition_high, request_ptr);
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
                                     "**mpi_pready_range", "**mpi_pready_range %d %d %R", partition_low,
                                     partition_high, request);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Pready_range(QMPI_Context context, int tool_id, int partition_low, int partition_high,
                      MPI_Request request)
{
    return internal_Pready_range(partition_low, partition_high, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Pready_range(int partition_low, int partition_high, MPI_Request request)
{
    QMPI_Context context;
    QMPI_Pready_range_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Pready_range(context, 0, partition_low, partition_high, request);

    fn_ptr = (QMPI_Pready_range_t *) MPIR_QMPI_first_fn_ptrs[MPI_PREADY_RANGE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_PREADY_RANGE_T], partition_low,
            partition_high, request);
}
#else /* ENABLE_QMPI */
int MPI_Pready_range(int partition_low, int partition_high, MPI_Request request)
{
    return internal_Pready_range(partition_low, partition_high, request);
}

#endif /* ENABLE_QMPI */
