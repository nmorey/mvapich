/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Win_shared_query */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Win_shared_query = PMPI_Win_shared_query
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Win_shared_query  MPI_Win_shared_query
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Win_shared_query as PMPI_Win_shared_query
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Win_shared_query(MPI_Win win, int rank, MPI_Aint *size, int *disp_unit, void *baseptr)
     __attribute__ ((weak, alias("PMPI_Win_shared_query")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Win_shared_query
#define MPI_Win_shared_query PMPI_Win_shared_query
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Win_shared_query(MPI_Win win, int rank, MPI_Aint *size, int *disp_unit,
                                     void *baseptr)
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
            MPIR_ERRTEST_WIN_NOT_DYNAMIC(win_ptr, mpi_errno);
            MPIR_ERRTEST_SEND_RANK(win_ptr->comm_ptr, rank, mpi_errno);
            MPIR_ERRTEST_ARGNULL(size, "size", mpi_errno);
            MPIR_ERRTEST_ARGNULL(disp_unit, "disp_unit", mpi_errno);
            MPIR_ERRTEST_ARGNULL(baseptr, "baseptr", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPI_Aint disp_unit_c;
    mpi_errno = MPIR_Win_shared_query_impl(win_ptr, rank, size, &disp_unit_c, baseptr);
    if (mpi_errno) {
        goto fn_fail;
    }
    if (disp_unit_c > INT_MAX) {
        *disp_unit = MPI_UNDEFINED;
    } else {
        *disp_unit = disp_unit_c;
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
                                     "**mpi_win_shared_query", "**mpi_win_shared_query %W %d %p %p %p",
                                     win, rank, size, disp_unit, baseptr);
#endif
    mpi_errno = MPIR_Err_return_win(win_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Win_shared_query(QMPI_Context context, int tool_id, MPI_Win win, int rank, MPI_Aint *size,
                          int *disp_unit, void *baseptr)
{
    return internal_Win_shared_query(win, rank, size, disp_unit, baseptr);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Win_shared_query(MPI_Win win, int rank, MPI_Aint *size, int *disp_unit, void *baseptr)
{
    QMPI_Context context;
    QMPI_Win_shared_query_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Win_shared_query(context, 0, win, rank, size, disp_unit, baseptr);

    fn_ptr = (QMPI_Win_shared_query_t *) MPIR_QMPI_first_fn_ptrs[MPI_WIN_SHARED_QUERY_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_WIN_SHARED_QUERY_T], win, rank, size,
            disp_unit, baseptr);
}
#else /* ENABLE_QMPI */
int MPI_Win_shared_query(MPI_Win win, int rank, MPI_Aint *size, int *disp_unit, void *baseptr)
{
    return internal_Win_shared_query(win, rank, size, disp_unit, baseptr);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Win_shared_query_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Win_shared_query_c = PMPI_Win_shared_query_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Win_shared_query_c  MPI_Win_shared_query_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Win_shared_query_c as PMPI_Win_shared_query_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Win_shared_query_c(MPI_Win win, int rank, MPI_Aint *size, MPI_Aint *disp_unit,
                           void *baseptr)
                            __attribute__ ((weak, alias("PMPI_Win_shared_query_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Win_shared_query_c
#define MPI_Win_shared_query_c PMPI_Win_shared_query_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Win_shared_query_c(MPI_Win win, int rank, MPI_Aint *size, MPI_Aint *disp_unit,
                                       void *baseptr)
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
            MPIR_ERRTEST_WIN_NOT_DYNAMIC(win_ptr, mpi_errno);
            MPIR_ERRTEST_SEND_RANK(win_ptr->comm_ptr, rank, mpi_errno);
            MPIR_ERRTEST_ARGNULL(size, "size", mpi_errno);
            MPIR_ERRTEST_ARGNULL(disp_unit, "disp_unit", mpi_errno);
            MPIR_ERRTEST_ARGNULL(baseptr, "baseptr", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_Win_shared_query_impl(win_ptr, rank, size, (MPI_Aint *) disp_unit, baseptr);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        mpi_errno = MPIR_Win_shared_query_impl(win_ptr, rank, size, disp_unit, baseptr);
        if (mpi_errno) {
            goto fn_fail;
        }
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
                                     "**mpi_win_shared_query_c",
                                     "**mpi_win_shared_query_c %W %d %p %p %p", win, rank, size,
                                     disp_unit, baseptr);
#endif
    mpi_errno = MPIR_Err_return_win(win_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Win_shared_query_c(QMPI_Context context, int tool_id, MPI_Win win, int rank,
                            MPI_Aint *size, MPI_Aint *disp_unit, void *baseptr)
{
    return internal_Win_shared_query_c(win, rank, size, disp_unit, baseptr);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Win_shared_query_c(MPI_Win win, int rank, MPI_Aint *size, MPI_Aint *disp_unit,
                           void *baseptr)
{
    QMPI_Context context;
    QMPI_Win_shared_query_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Win_shared_query_c(context, 0, win, rank, size, disp_unit, baseptr);

    fn_ptr = (QMPI_Win_shared_query_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_WIN_SHARED_QUERY_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_WIN_SHARED_QUERY_C_T], win, rank, size,
            disp_unit, baseptr);
}
#else /* ENABLE_QMPI */
int MPI_Win_shared_query_c(MPI_Win win, int rank, MPI_Aint *size, MPI_Aint *disp_unit,
                           void *baseptr)
{
    return internal_Win_shared_query_c(win, rank, size, disp_unit, baseptr);
}

#endif /* ENABLE_QMPI */
