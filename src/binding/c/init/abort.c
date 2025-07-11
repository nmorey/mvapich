/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Abort */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Abort = PMPI_Abort
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Abort  MPI_Abort
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Abort as PMPI_Abort
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Abort(MPI_Comm comm, int errorcode)  __attribute__ ((weak, alias("PMPI_Abort")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Abort
#define MPI_Abort PMPI_Abort
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Abort(MPI_Comm comm, int errorcode)
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
    mpi_errno = MPIR_Abort_impl(comm_ptr, errorcode);
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
                                     "**mpi_abort", "**mpi_abort %C %d", comm, errorcode);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Abort(QMPI_Context context, int tool_id, MPI_Comm comm, int errorcode)
{
    return internal_Abort(comm, errorcode);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Abort(MPI_Comm comm, int errorcode)
{
    QMPI_Context context;
    QMPI_Abort_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Abort(context, 0, comm, errorcode);

    fn_ptr = (QMPI_Abort_t *) MPIR_QMPI_first_fn_ptrs[MPI_ABORT_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_ABORT_T], comm, errorcode);
}
#else /* ENABLE_QMPI */
int MPI_Abort(MPI_Comm comm, int errorcode)
{
    return internal_Abort(comm, errorcode);
}

#endif /* ENABLE_QMPI */
