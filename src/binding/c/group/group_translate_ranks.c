/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Group_translate_ranks */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Group_translate_ranks = PMPI_Group_translate_ranks
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Group_translate_ranks  MPI_Group_translate_ranks
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Group_translate_ranks as PMPI_Group_translate_ranks
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Group_translate_ranks(MPI_Group group1, int n, const int ranks1[], MPI_Group group2,
                              int ranks2[])
                               __attribute__ ((weak, alias("PMPI_Group_translate_ranks")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Group_translate_ranks
#define MPI_Group_translate_ranks PMPI_Group_translate_ranks
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Group_translate_ranks(MPI_Group group1, int n, const int ranks1[],
                                          MPI_Group group2, int ranks2[])
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Group *group1_ptr ATTRIBUTE((unused)) = NULL;
    MPIR_Group *group2_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_GROUP(group1, mpi_errno);
            MPIR_ERRTEST_GROUP(group2, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_Group_get_ptr(group1, group1_ptr);
    MPIR_Group_get_ptr(group2, group2_ptr);

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_Group_valid_ptr(group1_ptr, mpi_errno);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_Group_valid_ptr(group2_ptr, mpi_errno);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_ERRTEST_ARGNEG(n, "n", mpi_errno);
            if (n > 0) {
                MPIR_ERRTEST_ARGNULL(ranks2, "ranks2", mpi_errno);
            }
            if (group1_ptr) {
            	/* Check that the rank entries are valid */
            	int size1 = group1_ptr->size;
            	for (int i = 0; i < n; i++) {
            	    if ((ranks1[i] < 0 && ranks1[i] != MPI_PROC_NULL) || ranks1[i] >= size1) {
            		mpi_errno = MPIR_Err_create_code(MPI_SUCCESS,
            						 MPIR_ERR_RECOVERABLE, __func__, __LINE__,
            						 MPI_ERR_RANK,
            						 "**rank", "**rank %d %d",
            						 ranks1[i], size1);
            		goto fn_fail;
            	    }
            	}
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Group_translate_ranks_impl(group1_ptr, n, ranks1, group2_ptr, ranks2);
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
                                     "**mpi_group_translate_ranks",
                                     "**mpi_group_translate_ranks %G %d %p %G %p", group1, n, ranks1,
                                     group2, ranks2);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Group_translate_ranks(QMPI_Context context, int tool_id, MPI_Group group1, int n,
                               const int ranks1[], MPI_Group group2, int ranks2[])
{
    return internal_Group_translate_ranks(group1, n, ranks1, group2, ranks2);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Group_translate_ranks(MPI_Group group1, int n, const int ranks1[], MPI_Group group2,
                              int ranks2[])
{
    QMPI_Context context;
    QMPI_Group_translate_ranks_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Group_translate_ranks(context, 0, group1, n, ranks1, group2, ranks2);

    fn_ptr = (QMPI_Group_translate_ranks_t *) MPIR_QMPI_first_fn_ptrs[MPI_GROUP_TRANSLATE_RANKS_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_GROUP_TRANSLATE_RANKS_T], group1, n,
            ranks1, group2, ranks2);
}
#else /* ENABLE_QMPI */
int MPI_Group_translate_ranks(MPI_Group group1, int n, const int ranks1[], MPI_Group group2,
                              int ranks2[])
{
    return internal_Group_translate_ranks(group1, n, ranks1, group2, ranks2);
}

#endif /* ENABLE_QMPI */
