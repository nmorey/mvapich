/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Test_cancelled */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Test_cancelled = PMPI_Test_cancelled
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Test_cancelled  MPI_Test_cancelled
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Test_cancelled as PMPI_Test_cancelled
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Test_cancelled(const MPI_Status *status, int *flag)
     __attribute__ ((weak, alias("PMPI_Test_cancelled")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Test_cancelled
#define MPI_Test_cancelled PMPI_Test_cancelled
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Test_cancelled(const MPI_Status *status, int *flag)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            MPIR_ERRTEST_ARGNULL(flag, "flag", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Test_cancelled_impl(status, flag);
    if (mpi_errno) {
        goto fn_fail;
    }
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_test_cancelled", "**mpi_test_cancelled %p %p", status,
                                     flag);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Test_cancelled(QMPI_Context context, int tool_id, const MPI_Status *status, int *flag)
{
    return internal_Test_cancelled(status, flag);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Test_cancelled(const MPI_Status *status, int *flag)
{
    QMPI_Context context;
    QMPI_Test_cancelled_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Test_cancelled(context, 0, status, flag);

    fn_ptr = (QMPI_Test_cancelled_t *) MPIR_QMPI_first_fn_ptrs[MPI_TEST_CANCELLED_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_TEST_CANCELLED_T], status, flag);
}
#else /* ENABLE_QMPI */
int MPI_Test_cancelled(const MPI_Status *status, int *flag)
{
    return internal_Test_cancelled(status, flag);
}

#endif /* ENABLE_QMPI */
