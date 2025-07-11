/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Win_allocate_shared */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Win_allocate_shared = PMPI_Win_allocate_shared
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Win_allocate_shared  MPI_Win_allocate_shared
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Win_allocate_shared as PMPI_Win_allocate_shared
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Win_allocate_shared(MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm,
                            void *baseptr, MPI_Win *win)
                             __attribute__ ((weak, alias("PMPI_Win_allocate_shared")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Win_allocate_shared
#define MPI_Win_allocate_shared PMPI_Win_allocate_shared
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Win_allocate_shared(MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm,
                                        void *baseptr, MPI_Win *win)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Info *info_ptr ATTRIBUTE((unused)) = NULL;
    MPIR_Comm *comm_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_INFO_OR_NULL(info, mpi_errno);
            MPIR_ERRTEST_COMM(comm, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    if (info != MPI_INFO_NULL) {
        MPIR_Info_get_ptr(info, info_ptr);
    }
    MPIR_Comm_get_ptr(comm, comm_ptr);

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            if (info != MPI_INFO_NULL) {
                MPIR_Info_valid_ptr(info_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            MPIR_Comm_valid_ptr(comm_ptr, mpi_errno, FALSE);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_ERRTEST_WIN_SIZE(size, mpi_errno);
            MPIR_ERRTEST_WIN_DISPUNIT(disp_unit, mpi_errno);
            MPIR_ERRTEST_ARGNULL(baseptr, "baseptr", mpi_errno);
            MPIR_ERRTEST_ARGNULL(win, "win", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPIR_Win *win_ptr ATTRIBUTE((unused)) = NULL;
    *win = MPI_WIN_NULL;
    mpi_errno = MPID_Win_allocate_shared(size, disp_unit, info_ptr, comm_ptr, baseptr, &win_ptr);
    if (mpi_errno) {
        goto fn_fail;
    }
    if (win_ptr) {
        /* Initialize a few fields that have specific defaults */
        win_ptr->name[0] = 0;
        win_ptr->errhandler = 0;
        MPIR_OBJ_PUBLISH_HANDLE(*win, win_ptr->handle);
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
                                     "**mpi_win_allocate_shared",
                                     "**mpi_win_allocate_shared %L %d %I %C %p %p", (long long) size,
                                     disp_unit, info, comm, baseptr, win);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Win_allocate_shared(QMPI_Context context, int tool_id, MPI_Aint size, int disp_unit,
                             MPI_Info info, MPI_Comm comm, void *baseptr, MPI_Win *win)
{
    return internal_Win_allocate_shared(size, disp_unit, info, comm, baseptr, win);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Win_allocate_shared(MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm,
                            void *baseptr, MPI_Win *win)
{
    QMPI_Context context;
    QMPI_Win_allocate_shared_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Win_allocate_shared(context, 0, size, disp_unit, info, comm, baseptr, win);

    fn_ptr = (QMPI_Win_allocate_shared_t *) MPIR_QMPI_first_fn_ptrs[MPI_WIN_ALLOCATE_SHARED_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_WIN_ALLOCATE_SHARED_T], size, disp_unit,
            info, comm, baseptr, win);
}
#else /* ENABLE_QMPI */
int MPI_Win_allocate_shared(MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm,
                            void *baseptr, MPI_Win *win)
{
    return internal_Win_allocate_shared(size, disp_unit, info, comm, baseptr, win);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Win_allocate_shared_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Win_allocate_shared_c = PMPI_Win_allocate_shared_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Win_allocate_shared_c  MPI_Win_allocate_shared_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Win_allocate_shared_c as PMPI_Win_allocate_shared_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Win_allocate_shared_c(MPI_Aint size, MPI_Aint disp_unit, MPI_Info info, MPI_Comm comm,
                              void *baseptr, MPI_Win *win)
                               __attribute__ ((weak, alias("PMPI_Win_allocate_shared_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Win_allocate_shared_c
#define MPI_Win_allocate_shared_c PMPI_Win_allocate_shared_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Win_allocate_shared_c(MPI_Aint size, MPI_Aint disp_unit, MPI_Info info,
                                          MPI_Comm comm, void *baseptr, MPI_Win *win)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Info *info_ptr ATTRIBUTE((unused)) = NULL;
    MPIR_Comm *comm_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_INFO_OR_NULL(info, mpi_errno);
            MPIR_ERRTEST_COMM(comm, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    if (info != MPI_INFO_NULL) {
        MPIR_Info_get_ptr(info, info_ptr);
    }
    MPIR_Comm_get_ptr(comm, comm_ptr);

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            if (info != MPI_INFO_NULL) {
                MPIR_Info_valid_ptr(info_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            MPIR_Comm_valid_ptr(comm_ptr, mpi_errno, FALSE);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_ERRTEST_WIN_SIZE(size, mpi_errno);
            MPIR_ERRTEST_WIN_DISPUNIT(disp_unit, mpi_errno);
            MPIR_ERRTEST_ARGNULL(baseptr, "baseptr", mpi_errno);
            MPIR_ERRTEST_ARGNULL(win, "win", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        MPIR_Win *win_ptr ATTRIBUTE((unused)) = NULL;
        *win = MPI_WIN_NULL;
        mpi_errno = MPID_Win_allocate_shared(size, (MPI_Aint) disp_unit, info_ptr, comm_ptr, baseptr,
                                             &win_ptr);
        if (mpi_errno) {
            goto fn_fail;
        }
        if (win_ptr) {
            /* Initialize a few fields that have specific defaults */
            win_ptr->name[0] = 0;
            win_ptr->errhandler = 0;
            MPIR_OBJ_PUBLISH_HANDLE(*win, win_ptr->handle);
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        MPIR_Win *win_ptr ATTRIBUTE((unused)) = NULL;
        *win = MPI_WIN_NULL;
        mpi_errno = MPID_Win_allocate_shared(size, disp_unit, info_ptr, comm_ptr, baseptr, &win_ptr);
        if (mpi_errno) {
            goto fn_fail;
        }
        if (win_ptr) {
            /* Initialize a few fields that have specific defaults */
            win_ptr->name[0] = 0;
            win_ptr->errhandler = 0;
            MPIR_OBJ_PUBLISH_HANDLE(*win, win_ptr->handle);
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
                                     "**mpi_win_allocate_shared_c",
                                     "**mpi_win_allocate_shared_c %L %L %I %C %p %p", (long long) size,
                                     (long long) disp_unit, info, comm, baseptr, win);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Win_allocate_shared_c(QMPI_Context context, int tool_id, MPI_Aint size, MPI_Aint disp_unit,
                               MPI_Info info, MPI_Comm comm, void *baseptr, MPI_Win *win)
{
    return internal_Win_allocate_shared_c(size, disp_unit, info, comm, baseptr, win);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Win_allocate_shared_c(MPI_Aint size, MPI_Aint disp_unit, MPI_Info info, MPI_Comm comm,
                              void *baseptr, MPI_Win *win)
{
    QMPI_Context context;
    QMPI_Win_allocate_shared_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Win_allocate_shared_c(context, 0, size, disp_unit, info, comm, baseptr, win);

    fn_ptr = (QMPI_Win_allocate_shared_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_WIN_ALLOCATE_SHARED_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_WIN_ALLOCATE_SHARED_C_T], size,
            disp_unit, info, comm, baseptr, win);
}
#else /* ENABLE_QMPI */
int MPI_Win_allocate_shared_c(MPI_Aint size, MPI_Aint disp_unit, MPI_Info info, MPI_Comm comm,
                              void *baseptr, MPI_Win *win)
{
    return internal_Win_allocate_shared_c(size, disp_unit, info, comm, baseptr, win);
}

#endif /* ENABLE_QMPI */
