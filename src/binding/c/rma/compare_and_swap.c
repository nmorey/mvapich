/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Compare_and_swap */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Compare_and_swap = PMPI_Compare_and_swap
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Compare_and_swap  MPI_Compare_and_swap
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Compare_and_swap as PMPI_Compare_and_swap
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Compare_and_swap(const void *origin_addr, const void *compare_addr, void *result_addr,
                         MPI_Datatype datatype, int target_rank, MPI_Aint target_disp, MPI_Win win)
                          __attribute__ ((weak, alias("PMPI_Compare_and_swap")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Compare_and_swap
#define MPI_Compare_and_swap PMPI_Compare_and_swap
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Compare_and_swap(const void *origin_addr, const void *compare_addr,
                                     void *result_addr, MPI_Datatype datatype, int target_rank,
                                     MPI_Aint target_disp, MPI_Win win)
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
            MPIR_ERRTEST_ARGNULL(origin_addr, "origin_addr", mpi_errno);
            MPIR_ERRTEST_ARGNULL(compare_addr, "compare_addr", mpi_errno);
            MPIR_ERRTEST_ARGNULL(result_addr, "result_addr", mpi_errno);
            MPIR_ERRTEST_SEND_RANK(win_ptr->comm_ptr, target_rank, mpi_errno);
            if (win_ptr->create_flavor != MPI_WIN_FLAVOR_DYNAMIC) {
                MPIR_ERRTEST_DISP(target_disp, mpi_errno);
            }
            MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
            /* Check if datatype is a C integer, Fortran Integer,
             * logical, or byte, per the classes given on page 165. */
            MPIR_ERRTEST_TYPE_RMA_ATOMIC(datatype, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* Return immediately for dummy process */
    if (unlikely(target_rank == MPI_PROC_NULL)) {
        goto fn_exit;
    }

    /* ... body of routine ... */
    mpi_errno = MPID_Compare_and_swap(origin_addr, compare_addr, result_addr, datatype, target_rank,
                                      target_disp, win_ptr);
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
                                     "**mpi_compare_and_swap",
                                     "**mpi_compare_and_swap %p %p %p %D %d %L %W", origin_addr,
                                     compare_addr, result_addr, datatype, target_rank,
                                     (long long) target_disp, win);
#endif
    mpi_errno = MPIR_Err_return_win(win_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Compare_and_swap(QMPI_Context context, int tool_id, const void *origin_addr,
                          const void *compare_addr, void *result_addr, MPI_Datatype datatype,
                          int target_rank, MPI_Aint target_disp, MPI_Win win)
{
    return internal_Compare_and_swap(origin_addr, compare_addr, result_addr, datatype, target_rank, target_disp, win);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Compare_and_swap(const void *origin_addr, const void *compare_addr, void *result_addr,
                         MPI_Datatype datatype, int target_rank, MPI_Aint target_disp, MPI_Win win)
{
    QMPI_Context context;
    QMPI_Compare_and_swap_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Compare_and_swap(context, 0, origin_addr, compare_addr, result_addr, datatype,
                                     target_rank, target_disp, win);

    fn_ptr = (QMPI_Compare_and_swap_t *) MPIR_QMPI_first_fn_ptrs[MPI_COMPARE_AND_SWAP_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_COMPARE_AND_SWAP_T], origin_addr,
            compare_addr, result_addr, datatype, target_rank, target_disp, win);
}
#else /* ENABLE_QMPI */
int MPI_Compare_and_swap(const void *origin_addr, const void *compare_addr, void *result_addr,
                         MPI_Datatype datatype, int target_rank, MPI_Aint target_disp, MPI_Win win)
{
    return internal_Compare_and_swap(origin_addr, compare_addr, result_addr, datatype, target_rank, target_disp, win);
}

#endif /* ENABLE_QMPI */
