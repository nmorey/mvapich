/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Win_get_name */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Win_get_name = PMPI_Win_get_name
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Win_get_name  MPI_Win_get_name
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Win_get_name as PMPI_Win_get_name
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Win_get_name(MPI_Win win, char *win_name, int *resultlen)
     __attribute__ ((weak, alias("PMPI_Win_get_name")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Win_get_name
#define MPI_Win_get_name PMPI_Win_get_name
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Win_get_name(MPI_Win win, char *win_name, int *resultlen)
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
            if (win != MPI_WIN_NULL) {
                MPIR_ERRTEST_WIN(win, mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    if (win != MPI_WIN_NULL) {
        MPIR_Win_get_ptr(win, win_ptr);
    }

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            if (win != MPI_WIN_NULL) {
                MPIR_Win_valid_ptr(win_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            if (MPI_MAX_OBJECT_NAME > 0) {
                MPIR_ERRTEST_ARGNULL(win_name, "win_name", mpi_errno);
            }
            MPIR_ERRTEST_ARGNULL(resultlen, "resultlen", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Win_get_name_impl(win_ptr, win_name, resultlen);
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
                                     "**mpi_win_get_name", "**mpi_win_get_name %W %p %p", win, win_name,
                                     resultlen);
#endif
    mpi_errno = MPIR_Err_return_win(win_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Win_get_name(QMPI_Context context, int tool_id, MPI_Win win, char *win_name,
                      int *resultlen)
{
    return internal_Win_get_name(win, win_name, resultlen);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Win_get_name(MPI_Win win, char *win_name, int *resultlen)
{
    QMPI_Context context;
    QMPI_Win_get_name_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Win_get_name(context, 0, win, win_name, resultlen);

    fn_ptr = (QMPI_Win_get_name_t *) MPIR_QMPI_first_fn_ptrs[MPI_WIN_GET_NAME_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_WIN_GET_NAME_T], win, win_name,
            resultlen);
}
#else /* ENABLE_QMPI */
int MPI_Win_get_name(MPI_Win win, char *win_name, int *resultlen)
{
    return internal_Win_get_name(win, win_name, resultlen);
}

#endif /* ENABLE_QMPI */
