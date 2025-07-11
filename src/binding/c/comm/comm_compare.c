/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Comm_compare */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Comm_compare = PMPI_Comm_compare
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Comm_compare  MPI_Comm_compare
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Comm_compare as PMPI_Comm_compare
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Comm_compare(MPI_Comm comm1, MPI_Comm comm2, int *result)
     __attribute__ ((weak, alias("PMPI_Comm_compare")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Comm_compare
#define MPI_Comm_compare PMPI_Comm_compare
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Comm_compare(MPI_Comm comm1, MPI_Comm comm2, int *result)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Comm *comm1_ptr ATTRIBUTE((unused)) = NULL;
    MPIR_Comm *comm2_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COMM(comm1, mpi_errno);
            MPIR_ERRTEST_COMM(comm2, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_Comm_get_ptr(comm1, comm1_ptr);
    MPIR_Comm_get_ptr(comm2, comm2_ptr);

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_Comm_valid_ptr(comm1_ptr, mpi_errno, TRUE);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_Comm_valid_ptr(comm2_ptr, mpi_errno, TRUE);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_ERRTEST_ARGNULL(result, "result", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Comm_compare_impl(comm1_ptr, comm2_ptr, result);
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
                                     "**mpi_comm_compare", "**mpi_comm_compare %C %C %p", comm1, comm2,
                                     result);
#endif
    mpi_errno = MPIR_Err_return_comm(comm1_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Comm_compare(QMPI_Context context, int tool_id, MPI_Comm comm1, MPI_Comm comm2,
                      int *result)
{
    return internal_Comm_compare(comm1, comm2, result);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Comm_compare(MPI_Comm comm1, MPI_Comm comm2, int *result)
{
    QMPI_Context context;
    QMPI_Comm_compare_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Comm_compare(context, 0, comm1, comm2, result);

    fn_ptr = (QMPI_Comm_compare_t *) MPIR_QMPI_first_fn_ptrs[MPI_COMM_COMPARE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_COMM_COMPARE_T], comm1, comm2, result);
}
#else /* ENABLE_QMPI */
int MPI_Comm_compare(MPI_Comm comm1, MPI_Comm comm2, int *result)
{
    return internal_Comm_compare(comm1, comm2, result);
}

#endif /* ENABLE_QMPI */
