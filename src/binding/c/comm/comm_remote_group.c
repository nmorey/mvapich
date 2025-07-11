/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Comm_remote_group */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Comm_remote_group = PMPI_Comm_remote_group
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Comm_remote_group  MPI_Comm_remote_group
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Comm_remote_group as PMPI_Comm_remote_group
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Comm_remote_group(MPI_Comm comm, MPI_Group *group)
     __attribute__ ((weak, alias("PMPI_Comm_remote_group")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Comm_remote_group
#define MPI_Comm_remote_group PMPI_Comm_remote_group
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Comm_remote_group(MPI_Comm comm, MPI_Group *group)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Comm *comm_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COMM(comm, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_Comm_get_ptr(comm, comm_ptr);

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_Comm_valid_ptr(comm_ptr, mpi_errno, TRUE);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_ERRTEST_ARGNULL(group, "group", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPIR_Group *group_ptr ATTRIBUTE((unused)) = NULL;
    *group = MPI_GROUP_NULL;
    mpi_errno = MPIR_Comm_remote_group_impl(comm_ptr, &group_ptr);
    if (mpi_errno) {
        goto fn_fail;
    }
    if (group_ptr) {
        MPIR_OBJ_PUBLISH_HANDLE(*group, group_ptr->handle);
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
                                     "**mpi_comm_remote_group", "**mpi_comm_remote_group %C %p", comm,
                                     group);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Comm_remote_group(QMPI_Context context, int tool_id, MPI_Comm comm, MPI_Group *group)
{
    return internal_Comm_remote_group(comm, group);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Comm_remote_group(MPI_Comm comm, MPI_Group *group)
{
    QMPI_Context context;
    QMPI_Comm_remote_group_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Comm_remote_group(context, 0, comm, group);

    fn_ptr = (QMPI_Comm_remote_group_t *) MPIR_QMPI_first_fn_ptrs[MPI_COMM_REMOTE_GROUP_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_COMM_REMOTE_GROUP_T], comm, group);
}
#else /* ENABLE_QMPI */
int MPI_Comm_remote_group(MPI_Comm comm, MPI_Group *group)
{
    return internal_Comm_remote_group(comm, group);
}

#endif /* ENABLE_QMPI */
