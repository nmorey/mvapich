/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Parrived */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Parrived = PMPI_Parrived
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Parrived  MPI_Parrived
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Parrived as PMPI_Parrived
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Parrived(MPI_Request request, int partition, int *flag)
     __attribute__ ((weak, alias("PMPI_Parrived")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Parrived
#define MPI_Parrived PMPI_Parrived
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Parrived(MPI_Request request, int partition, int *flag)
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
            MPIR_ERRTEST_PARRIVEDREQ(request_ptr, mpi_errno);
            MPIR_ERRTEST_ARGNULL(flag, "flag", mpi_errno);
            MPIR_ERRTEST_PARTITION(partition, request_ptr, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    if (request == MPI_REQUEST_NULL || !MPIR_Part_request_is_active(request_ptr)) {
        *flag = TRUE;
        goto fn_exit;
    }

    /* ... body of routine ... */
    mpi_errno = MPIR_Parrived(request_ptr, partition, flag);
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
                                     "**mpi_parrived", "**mpi_parrived %R %d %p", request, partition,
                                     flag);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Parrived(QMPI_Context context, int tool_id, MPI_Request request, int partition, int *flag)
{
    return internal_Parrived(request, partition, flag);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Parrived(MPI_Request request, int partition, int *flag)
{
    QMPI_Context context;
    QMPI_Parrived_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Parrived(context, 0, request, partition, flag);

    fn_ptr = (QMPI_Parrived_t *) MPIR_QMPI_first_fn_ptrs[MPI_PARRIVED_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_PARRIVED_T], request, partition, flag);
}
#else /* ENABLE_QMPI */
int MPI_Parrived(MPI_Request request, int partition, int *flag)
{
    return internal_Parrived(request, partition, flag);
}

#endif /* ENABLE_QMPI */
