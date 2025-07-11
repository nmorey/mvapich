/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Win_detach */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Win_detach = PMPI_Win_detach
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Win_detach  MPI_Win_detach
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Win_detach as PMPI_Win_detach
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Win_detach(MPI_Win win, const void *base)
     __attribute__ ((weak, alias("PMPI_Win_detach")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Win_detach
#define MPI_Win_detach PMPI_Win_detach
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Win_detach(MPI_Win win, const void *base)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Win *win_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_WIN(win, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_Win_get_ptr(win, win_ptr);

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_Win_valid_ptr(win_ptr, mpi_errno);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_ERRTEST_ARGNULL(base, "base", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    if (base == NULL)
        goto fn_exit;

    /* ... body of routine ... */
    mpi_errno = MPID_Win_detach(win_ptr, base);
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
                                     "**mpi_win_detach", "**mpi_win_detach %W %p", win, base);
#endif
    mpi_errno = MPIR_Err_return_win(win_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Win_detach(QMPI_Context context, int tool_id, MPI_Win win, const void *base)
{
    return internal_Win_detach(win, base);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Win_detach(MPI_Win win, const void *base)
{
    QMPI_Context context;
    QMPI_Win_detach_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Win_detach(context, 0, win, base);

    fn_ptr = (QMPI_Win_detach_t *) MPIR_QMPI_first_fn_ptrs[MPI_WIN_DETACH_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_WIN_DETACH_T], win, base);
}
#else /* ENABLE_QMPI */
int MPI_Win_detach(MPI_Win win, const void *base)
{
    return internal_Win_detach(win, base);
}

#endif /* ENABLE_QMPI */
