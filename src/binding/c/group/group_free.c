/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Group_free */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Group_free = PMPI_Group_free
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Group_free  MPI_Group_free
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Group_free as PMPI_Group_free
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Group_free(MPI_Group *group)  __attribute__ ((weak, alias("PMPI_Group_free")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Group_free
#define MPI_Group_free PMPI_Group_free
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Group_free(MPI_Group *group)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Group *group_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(group, "group", mpi_errno);
            MPIR_ERRTEST_GROUP(*group, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_Group_get_ptr(*group, group_ptr);

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_Group_valid_ptr(group_ptr, mpi_errno);
            if (mpi_errno) {
                goto fn_fail;
            }
            /* Cannot free the predefined groups, but allow GROUP_EMPTY
             * because otherwise many tests fail */
            if ((HANDLE_IS_BUILTIN(*group)) && *group != MPI_GROUP_EMPTY) {
                mpi_errno = MPIR_Err_create_code(MPI_SUCCESS,
                                                 MPIR_ERR_RECOVERABLE, __func__, __LINE__,
                                                 MPI_ERR_GROUP, "**groupperm", 0);
            }
            if (mpi_errno) {
            	goto fn_fail;
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Group_free_impl(group_ptr);
    if (mpi_errno) {
        goto fn_fail;
    }
    *group = MPI_GROUP_NULL;
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    MPID_THREAD_CS_EXIT(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_group_free", "**mpi_group_free %p", group);
#endif
    mpi_errno = MPIR_Err_return_group(group_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Group_free(QMPI_Context context, int tool_id, MPI_Group *group)
{
    return internal_Group_free(group);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Group_free(MPI_Group *group)
{
    QMPI_Context context;
    QMPI_Group_free_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Group_free(context, 0, group);

    fn_ptr = (QMPI_Group_free_t *) MPIR_QMPI_first_fn_ptrs[MPI_GROUP_FREE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_GROUP_FREE_T], group);
}
#else /* ENABLE_QMPI */
int MPI_Group_free(MPI_Group *group)
{
    return internal_Group_free(group);
}

#endif /* ENABLE_QMPI */
