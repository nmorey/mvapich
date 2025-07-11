/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Group_rank */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Group_rank = PMPI_Group_rank
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Group_rank  MPI_Group_rank
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Group_rank as PMPI_Group_rank
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Group_rank(MPI_Group group, int *rank)  __attribute__ ((weak, alias("PMPI_Group_rank")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Group_rank
#define MPI_Group_rank PMPI_Group_rank
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Group_rank(MPI_Group group, int *rank)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Group *group_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_GROUP(group, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_Group_get_ptr(group, group_ptr);

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_Group_valid_ptr(group_ptr, mpi_errno);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_ERRTEST_ARGNULL(rank, "rank", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Group_rank_impl(group_ptr, rank);
    if (mpi_errno) {
        goto fn_fail;
    }
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_group_rank", "**mpi_group_rank %G %p", group, rank);
#endif
    mpi_errno = MPIR_Err_return_group(group_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Group_rank(QMPI_Context context, int tool_id, MPI_Group group, int *rank)
{
    return internal_Group_rank(group, rank);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Group_rank(MPI_Group group, int *rank)
{
    QMPI_Context context;
    QMPI_Group_rank_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Group_rank(context, 0, group, rank);

    fn_ptr = (QMPI_Group_rank_t *) MPIR_QMPI_first_fn_ptrs[MPI_GROUP_RANK_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_GROUP_RANK_T], group, rank);
}
#else /* ENABLE_QMPI */
int MPI_Group_rank(MPI_Group group, int *rank)
{
    return internal_Group_rank(group, rank);
}

#endif /* ENABLE_QMPI */
