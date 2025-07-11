/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPIX_Comm_failure_ack */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPIX_Comm_failure_ack = PMPIX_Comm_failure_ack
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPIX_Comm_failure_ack  MPIX_Comm_failure_ack
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPIX_Comm_failure_ack as PMPIX_Comm_failure_ack
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPIX_Comm_failure_ack(MPI_Comm comm)  __attribute__ ((weak, alias("PMPIX_Comm_failure_ack")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPIX_Comm_failure_ack
#define MPIX_Comm_failure_ack PMPIX_Comm_failure_ack
#endif /* MPICH_MPI_FROM_PMPI */

static int internalX_Comm_failure_ack(MPI_Comm comm)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Comm *comm_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COMM(comm, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_Comm_get_ptr(comm, comm_ptr);

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_Comm_valid_ptr(comm_ptr, mpi_errno, TRUE);
            if (mpi_errno) {
                goto fn_fail;
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPID_Comm_failure_ack(comm_ptr);
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
                                     "**mpix_comm_failure_ack", "**mpix_comm_failure_ack %C", comm);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPIX_Comm_failure_ack(QMPI_Context context, int tool_id, MPI_Comm comm)
{
    return internalX_Comm_failure_ack(comm);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPIX_Comm_failure_ack(MPI_Comm comm)
{
    QMPI_Context context;
    QMPIX_Comm_failure_ack_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPIX_Comm_failure_ack(context, 0, comm);

    fn_ptr = (QMPIX_Comm_failure_ack_t *) MPIR_QMPI_first_fn_ptrs[MPIX_COMM_FAILURE_ACK_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPIX_COMM_FAILURE_ACK_T], comm);
}
#else /* ENABLE_QMPI */
int MPIX_Comm_failure_ack(MPI_Comm comm)
{
    return internalX_Comm_failure_ack(comm);
}

#endif /* ENABLE_QMPI */
