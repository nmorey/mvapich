/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Win_get_group */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Win_get_group = PMPI_Win_get_group
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Win_get_group  MPI_Win_get_group
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Win_get_group as PMPI_Win_get_group
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Win_get_group(MPI_Win win, MPI_Group *group)
     __attribute__ ((weak, alias("PMPI_Win_get_group")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Win_get_group
#define MPI_Win_get_group PMPI_Win_get_group
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Win_get_group(MPI_Win win, MPI_Group *group)
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
            MPIR_ERRTEST_ARGNULL(group, "group", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPIR_Group *group_ptr = NULL;
    MPIR_Comm *win_comm_ptr = win_ptr->comm_ptr;
    mpi_errno = MPIR_Comm_group_impl(win_comm_ptr, &group_ptr);
    if (mpi_errno != MPI_SUCCESS)
        goto fn_fail;
    *group = group_ptr->handle;
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    MPID_THREAD_CS_EXIT(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_win_get_group", "**mpi_win_get_group %W %p", win, group);
#endif
    mpi_errno = MPIR_Err_return_win(win_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Win_get_group(QMPI_Context context, int tool_id, MPI_Win win, MPI_Group *group)
{
    return internal_Win_get_group(win, group);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Win_get_group(MPI_Win win, MPI_Group *group)
{
    QMPI_Context context;
    QMPI_Win_get_group_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Win_get_group(context, 0, win, group);

    fn_ptr = (QMPI_Win_get_group_t *) MPIR_QMPI_first_fn_ptrs[MPI_WIN_GET_GROUP_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_WIN_GET_GROUP_T], win, group);
}
#else /* ENABLE_QMPI */
int MPI_Win_get_group(MPI_Win win, MPI_Group *group)
{
    return internal_Win_get_group(win, group);
}

#endif /* ENABLE_QMPI */
