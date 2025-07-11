/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Group_range_incl */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Group_range_incl = PMPI_Group_range_incl
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Group_range_incl  MPI_Group_range_incl
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Group_range_incl as PMPI_Group_range_incl
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Group_range_incl(MPI_Group group, int n, int ranges[][3], MPI_Group *newgroup)
     __attribute__ ((weak, alias("PMPI_Group_range_incl")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Group_range_incl
#define MPI_Group_range_incl PMPI_Group_range_incl
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Group_range_incl(MPI_Group group, int n, int ranges[][3], MPI_Group *newgroup)
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
            MPIR_ERRTEST_ARGNEG(n, "n", mpi_errno);
            MPIR_ERRTEST_ARGNULL(newgroup, "newgroup", mpi_errno);
            if (group_ptr) {
            	mpi_errno = MPIR_Group_check_valid_ranges(group_ptr, ranges, n);
            }
            if (mpi_errno) {
            	goto fn_fail;
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPIR_Group *newgroup_ptr ATTRIBUTE((unused)) = NULL;
    *newgroup = MPI_GROUP_NULL;
    mpi_errno = MPIR_Group_range_incl_impl(group_ptr, n, ranges, &newgroup_ptr);
    if (mpi_errno) {
        goto fn_fail;
    }
    if (newgroup_ptr) {
        MPIR_OBJ_PUBLISH_HANDLE(*newgroup, newgroup_ptr->handle);
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
                                     "**mpi_group_range_incl", "**mpi_group_range_incl %G %d %p %p",
                                     group, n, ranges, newgroup);
#endif
    mpi_errno = MPIR_Err_return_group(group_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Group_range_incl(QMPI_Context context, int tool_id, MPI_Group group, int n,
                          int ranges[][3], MPI_Group *newgroup)
{
    return internal_Group_range_incl(group, n, ranges, newgroup);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Group_range_incl(MPI_Group group, int n, int ranges[][3], MPI_Group *newgroup)
{
    QMPI_Context context;
    QMPI_Group_range_incl_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Group_range_incl(context, 0, group, n, ranges, newgroup);

    fn_ptr = (QMPI_Group_range_incl_t *) MPIR_QMPI_first_fn_ptrs[MPI_GROUP_RANGE_INCL_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_GROUP_RANGE_INCL_T], group, n, ranges,
            newgroup);
}
#else /* ENABLE_QMPI */
int MPI_Group_range_incl(MPI_Group group, int n, int ranges[][3], MPI_Group *newgroup)
{
    return internal_Group_range_incl(group, n, ranges, newgroup);
}

#endif /* ENABLE_QMPI */
