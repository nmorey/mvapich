/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPIX_Threadcomm_init */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPIX_Threadcomm_init = PMPIX_Threadcomm_init
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPIX_Threadcomm_init  MPIX_Threadcomm_init
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPIX_Threadcomm_init as PMPIX_Threadcomm_init
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPIX_Threadcomm_init(MPI_Comm comm, int num_threads, MPI_Comm *newthreadcomm)
     __attribute__ ((weak, alias("PMPIX_Threadcomm_init")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPIX_Threadcomm_init
#define MPIX_Threadcomm_init PMPIX_Threadcomm_init
#endif /* MPICH_MPI_FROM_PMPI */

static int internalX_Threadcomm_init(MPI_Comm comm, int num_threads, MPI_Comm *newthreadcomm)
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
            MPIR_Comm_valid_ptr(comm_ptr, mpi_errno, FALSE);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_ERRTEST_ARGNEG(num_threads, "num_threads", mpi_errno);
            MPIR_ERRTEST_ARGNULL(newthreadcomm, "newthreadcomm", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPIR_Comm *newthreadcomm_ptr ATTRIBUTE((unused)) = NULL;
    *newthreadcomm = MPI_COMM_NULL;
    mpi_errno = MPIR_Threadcomm_init_impl(comm_ptr, num_threads, &newthreadcomm_ptr);
    if (mpi_errno) {
        goto fn_fail;
    }
    if (newthreadcomm_ptr) {
        MPIR_OBJ_PUBLISH_HANDLE(*newthreadcomm, newthreadcomm_ptr->handle);
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
                                     "**mpix_threadcomm_init", "**mpix_threadcomm_init %C %d %p", comm,
                                     num_threads, newthreadcomm);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPIX_Threadcomm_init(QMPI_Context context, int tool_id, MPI_Comm comm, int num_threads,
                          MPI_Comm *newthreadcomm)
{
    return internalX_Threadcomm_init(comm, num_threads, newthreadcomm);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPIX_Threadcomm_init(MPI_Comm comm, int num_threads, MPI_Comm *newthreadcomm)
{
    QMPI_Context context;
    QMPIX_Threadcomm_init_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPIX_Threadcomm_init(context, 0, comm, num_threads, newthreadcomm);

    fn_ptr = (QMPIX_Threadcomm_init_t *) MPIR_QMPI_first_fn_ptrs[MPIX_THREADCOMM_INIT_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPIX_THREADCOMM_INIT_T], comm, num_threads,
            newthreadcomm);
}
#else /* ENABLE_QMPI */
int MPIX_Threadcomm_init(MPI_Comm comm, int num_threads, MPI_Comm *newthreadcomm)
{
    return internalX_Threadcomm_init(comm, num_threads, newthreadcomm);
}

#endif /* ENABLE_QMPI */
