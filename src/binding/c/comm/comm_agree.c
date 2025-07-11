/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPIX_Comm_agree */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPIX_Comm_agree = PMPIX_Comm_agree
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPIX_Comm_agree  MPIX_Comm_agree
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPIX_Comm_agree as PMPIX_Comm_agree
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPIX_Comm_agree(MPI_Comm comm, int *flag)  __attribute__ ((weak, alias("PMPIX_Comm_agree")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPIX_Comm_agree
#define MPIX_Comm_agree PMPIX_Comm_agree
#endif /* MPICH_MPI_FROM_PMPI */

static int internalX_Comm_agree(MPI_Comm comm, int *flag)
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
            MPIR_ERRTEST_ARGNULL(flag, "flag", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Comm_agree_impl(comm_ptr, flag);
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
                                     "**mpix_comm_agree", "**mpix_comm_agree %C %p", comm, flag);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPIX_Comm_agree(QMPI_Context context, int tool_id, MPI_Comm comm, int *flag)
{
    return internalX_Comm_agree(comm, flag);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPIX_Comm_agree(MPI_Comm comm, int *flag)
{
    QMPI_Context context;
    QMPIX_Comm_agree_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPIX_Comm_agree(context, 0, comm, flag);

    fn_ptr = (QMPIX_Comm_agree_t *) MPIR_QMPI_first_fn_ptrs[MPIX_COMM_AGREE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPIX_COMM_AGREE_T], comm, flag);
}
#else /* ENABLE_QMPI */
int MPIX_Comm_agree(MPI_Comm comm, int *flag)
{
    return internalX_Comm_agree(comm, flag);
}

#endif /* ENABLE_QMPI */
