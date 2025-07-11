/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPIX_Threadcomm_finish */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPIX_Threadcomm_finish = PMPIX_Threadcomm_finish
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPIX_Threadcomm_finish  MPIX_Threadcomm_finish
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPIX_Threadcomm_finish as PMPIX_Threadcomm_finish
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPIX_Threadcomm_finish(MPI_Comm threadcomm)
     __attribute__ ((weak, alias("PMPIX_Threadcomm_finish")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPIX_Threadcomm_finish
#define MPIX_Threadcomm_finish PMPIX_Threadcomm_finish
#endif /* MPICH_MPI_FROM_PMPI */

static int internalX_Threadcomm_finish(MPI_Comm threadcomm)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Comm *threadcomm_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COMM(threadcomm, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_Comm_get_ptr(threadcomm, threadcomm_ptr);

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_Comm_valid_ptr(threadcomm_ptr, mpi_errno, FALSE);
            if (mpi_errno) {
                goto fn_fail;
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Threadcomm_finish_impl(threadcomm_ptr);
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
                                     "**mpix_threadcomm_finish", "**mpix_threadcomm_finish %C",
                                     threadcomm);
#endif
    mpi_errno = MPIR_Err_return_comm(threadcomm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPIX_Threadcomm_finish(QMPI_Context context, int tool_id, MPI_Comm threadcomm)
{
    return internalX_Threadcomm_finish(threadcomm);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPIX_Threadcomm_finish(MPI_Comm threadcomm)
{
    QMPI_Context context;
    QMPIX_Threadcomm_finish_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPIX_Threadcomm_finish(context, 0, threadcomm);

    fn_ptr = (QMPIX_Threadcomm_finish_t *) MPIR_QMPI_first_fn_ptrs[MPIX_THREADCOMM_FINISH_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPIX_THREADCOMM_FINISH_T], threadcomm);
}
#else /* ENABLE_QMPI */
int MPIX_Threadcomm_finish(MPI_Comm threadcomm)
{
    return internalX_Threadcomm_finish(threadcomm);
}

#endif /* ENABLE_QMPI */
