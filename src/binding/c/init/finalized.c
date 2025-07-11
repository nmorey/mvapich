/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

#include "mpi_init.h"

/* -- Begin Profiling Symbol Block for routine MPI_Finalized */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Finalized = PMPI_Finalized
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Finalized  MPI_Finalized
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Finalized as PMPI_Finalized
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Finalized(int *flag)  __attribute__ ((weak, alias("PMPI_Finalized")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Finalized
#define MPI_Finalized PMPI_Finalized
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Finalized(int *flag)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(flag, "flag", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Finalized_impl(flag);
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
    if (MPIR_Errutil_is_initialized()) {
        mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**mpi_finalized", "**mpi_finalized %p", flag);
        mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    }
#endif
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Finalized(QMPI_Context context, int tool_id, int *flag)
{
    return internal_Finalized(flag);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Finalized(int *flag)
{
    QMPI_Context context;
    QMPI_Finalized_t *fn_ptr;

    context.storage_stack = NULL;

    int mpi_errno = MPI_SUCCESS;
    mpi_errno = MPII_qmpi_init();
    if (mpi_errno != MPI_SUCCESS) {
        return mpi_errno;
    }

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Finalized(context, 0, flag);

    fn_ptr = (QMPI_Finalized_t *) MPIR_QMPI_first_fn_ptrs[MPI_FINALIZED_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FINALIZED_T], flag);
}
#else /* ENABLE_QMPI */
int MPI_Finalized(int *flag)
{
    return internal_Finalized(flag);
}

#endif /* ENABLE_QMPI */
