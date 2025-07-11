/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Win_lock_all */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Win_lock_all = PMPI_Win_lock_all
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Win_lock_all  MPI_Win_lock_all
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Win_lock_all as PMPI_Win_lock_all
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Win_lock_all(int assert, MPI_Win win)  __attribute__ ((weak, alias("PMPI_Win_lock_all")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Win_lock_all
#define MPI_Win_lock_all PMPI_Win_lock_all
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Win_lock_all(int assert, MPI_Win win)
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
            if (assert != (assert & (MPI_MODE_NOCHECK))) {
                MPIR_ERR_SET1(mpi_errno, MPI_ERR_ARG, "**assert", "**assert %d", assert);
                goto fn_fail;
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPID_Win_lock_all(assert, win_ptr);
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
                                     "**mpi_win_lock_all", "**mpi_win_lock_all %A %W", assert, win);
#endif
    mpi_errno = MPIR_Err_return_win(win_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Win_lock_all(QMPI_Context context, int tool_id, int assert, MPI_Win win)
{
    return internal_Win_lock_all(assert, win);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Win_lock_all(int assert, MPI_Win win)
{
    QMPI_Context context;
    QMPI_Win_lock_all_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Win_lock_all(context, 0, assert, win);

    fn_ptr = (QMPI_Win_lock_all_t *) MPIR_QMPI_first_fn_ptrs[MPI_WIN_LOCK_ALL_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_WIN_LOCK_ALL_T], assert, win);
}
#else /* ENABLE_QMPI */
int MPI_Win_lock_all(int assert, MPI_Win win)
{
    return internal_Win_lock_all(assert, win);
}

#endif /* ENABLE_QMPI */
