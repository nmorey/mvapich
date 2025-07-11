/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Fetch_and_op */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Fetch_and_op = PMPI_Fetch_and_op
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Fetch_and_op  MPI_Fetch_and_op
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Fetch_and_op as PMPI_Fetch_and_op
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Fetch_and_op(const void *origin_addr, void *result_addr, MPI_Datatype datatype,
                     int target_rank, MPI_Aint target_disp, MPI_Op op, MPI_Win win)
                      __attribute__ ((weak, alias("PMPI_Fetch_and_op")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Fetch_and_op
#define MPI_Fetch_and_op PMPI_Fetch_and_op
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Fetch_and_op(const void *origin_addr, void *result_addr, MPI_Datatype datatype,
                                 int target_rank, MPI_Aint target_disp, MPI_Op op, MPI_Win win)
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
            MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
            if (!HANDLE_IS_BUILTIN(datatype)) {
                MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
                MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            MPIR_ERRTEST_SEND_RANK(win_ptr->comm_ptr, target_rank, mpi_errno);
            if (win_ptr->create_flavor != MPI_WIN_FLAVOR_DYNAMIC) {
                MPIR_ERRTEST_DISP(target_disp, mpi_errno);
            }
            MPIR_ERRTEST_OP_GACC(op, mpi_errno);
            if (op != MPI_NO_OP) {
                /* NOTE: when op is MPI_NO_OP, origin_addr is allowed to be NULL.
                 * In such case, MPI_Fetch_and_op equals to an atomic GET. */
                 MPIR_ERRTEST_ARGNULL(origin_addr, "origin_addr", mpi_errno);
            }
            MPIR_ERRTEST_ARGNULL(result_addr, "result_addr", mpi_errno);
            if (!MPIR_DATATYPE_IS_PREDEFINED(datatype)) {
                MPIR_ERR_SETANDJUMP(mpi_errno, MPI_ERR_TYPE, "**typenotpredefined");
            }
            if (!HANDLE_IS_BUILTIN(op)) {
                MPIR_ERR_SETANDJUMP(mpi_errno, MPI_ERR_OP, "**opnotpredefined");
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* Return immediately for dummy process */
    if (unlikely(target_rank == MPI_PROC_NULL)) {
        goto fn_exit;
    }

    /* ... body of routine ... */
    mpi_errno = MPID_Fetch_and_op(origin_addr, result_addr, datatype, target_rank, target_disp, op,
                                  win_ptr);
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
                                     "**mpi_fetch_and_op", "**mpi_fetch_and_op %p %p %D %d %L %O %W",
                                     origin_addr, result_addr, datatype, target_rank,
                                     (long long) target_disp, op, win);
#endif
    mpi_errno = MPIR_Err_return_win(win_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Fetch_and_op(QMPI_Context context, int tool_id, const void *origin_addr, void *result_addr,
                      MPI_Datatype datatype, int target_rank, MPI_Aint target_disp, MPI_Op op,
                      MPI_Win win)
{
    return internal_Fetch_and_op(origin_addr, result_addr, datatype, target_rank, target_disp, op, win);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Fetch_and_op(const void *origin_addr, void *result_addr, MPI_Datatype datatype,
                     int target_rank, MPI_Aint target_disp, MPI_Op op, MPI_Win win)
{
    QMPI_Context context;
    QMPI_Fetch_and_op_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Fetch_and_op(context, 0, origin_addr, result_addr, datatype, target_rank,
                                 target_disp, op, win);

    fn_ptr = (QMPI_Fetch_and_op_t *) MPIR_QMPI_first_fn_ptrs[MPI_FETCH_AND_OP_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FETCH_AND_OP_T], origin_addr,
            result_addr, datatype, target_rank, target_disp, op, win);
}
#else /* ENABLE_QMPI */
int MPI_Fetch_and_op(const void *origin_addr, void *result_addr, MPI_Datatype datatype,
                     int target_rank, MPI_Aint target_disp, MPI_Op op, MPI_Win win)
{
    return internal_Fetch_and_op(origin_addr, result_addr, datatype, target_rank, target_disp, op, win);
}

#endif /* ENABLE_QMPI */
