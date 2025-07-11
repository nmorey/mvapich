/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Intercomm_create_from_groups */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Intercomm_create_from_groups = PMPI_Intercomm_create_from_groups
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Intercomm_create_from_groups  MPI_Intercomm_create_from_groups
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Intercomm_create_from_groups as PMPI_Intercomm_create_from_groups
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Intercomm_create_from_groups(MPI_Group local_group, int local_leader,
                                     MPI_Group remote_group, int remote_leader,
                                     const char *stringtag, MPI_Info info,
                                     MPI_Errhandler errhandler, MPI_Comm *newintercomm)
                                      __attribute__ ((weak, alias("PMPI_Intercomm_create_from_groups")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Intercomm_create_from_groups
#define MPI_Intercomm_create_from_groups PMPI_Intercomm_create_from_groups
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Intercomm_create_from_groups(MPI_Group local_group, int local_leader,
                                                 MPI_Group remote_group, int remote_leader,
                                                 const char *stringtag, MPI_Info info,
                                                 MPI_Errhandler errhandler, MPI_Comm *newintercomm)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Group *local_group_ptr ATTRIBUTE((unused)) = NULL;
    MPIR_Group *remote_group_ptr ATTRIBUTE((unused)) = NULL;
    MPIR_Info *info_ptr ATTRIBUTE((unused)) = NULL;
    MPIR_Errhandler *errhandler_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_GROUP(local_group, mpi_errno);
            MPIR_ERRTEST_GROUP(remote_group, mpi_errno);
            MPIR_ERRTEST_INFO_OR_NULL(info, mpi_errno);
            MPIR_ERRTEST_ERRHANDLER(errhandler, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_Group_get_ptr(local_group, local_group_ptr);
    MPIR_Group_get_ptr(remote_group, remote_group_ptr);
    if (info != MPI_INFO_NULL) {
        MPIR_Info_get_ptr(info, info_ptr);
    }
    MPIR_Errhandler_get_ptr(errhandler, errhandler_ptr);

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_Group_valid_ptr(local_group_ptr, mpi_errno);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_Group_valid_ptr(remote_group_ptr, mpi_errno);
            if (mpi_errno) {
                goto fn_fail;
            }
            if (info != MPI_INFO_NULL) {
                MPIR_Info_valid_ptr(info_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            MPIR_Errhandler_valid_ptr(errhandler_ptr, mpi_errno);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_ERRTEST_ARGNULL(stringtag, "stringtag", mpi_errno);
            MPIR_ERRTEST_ARGNULL(newintercomm, "newintercomm", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    if (local_group == MPI_GROUP_EMPTY || remote_group == MPI_GROUP_EMPTY) {
        *newintercomm = MPI_COMM_NULL;
        goto fn_exit;
    }

    /* ... body of routine ... */
    MPIR_Comm *newintercomm_ptr ATTRIBUTE((unused)) = NULL;
    *newintercomm = MPI_COMM_NULL;
    mpi_errno = MPIR_Intercomm_create_from_groups_impl(local_group_ptr, local_leader, remote_group_ptr,
                                                       remote_leader, stringtag, info_ptr,
                                                       errhandler_ptr, &newintercomm_ptr);
    if (mpi_errno) {
        goto fn_fail;
    }
    if (newintercomm_ptr) {
        MPIR_OBJ_PUBLISH_HANDLE(*newintercomm, newintercomm_ptr->handle);
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
                                     "**mpi_intercomm_create_from_groups",
                                     "**mpi_intercomm_create_from_groups %G %i %G %i %s %I %E %p",
                                     local_group, local_leader, remote_group, remote_leader, stringtag,
                                     info, errhandler, newintercomm);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Intercomm_create_from_groups(QMPI_Context context, int tool_id, MPI_Group local_group,
                                      int local_leader, MPI_Group remote_group, int remote_leader,
                                      const char *stringtag, MPI_Info info,
                                      MPI_Errhandler errhandler, MPI_Comm *newintercomm)
{
    return internal_Intercomm_create_from_groups(local_group, local_leader, remote_group, remote_leader, stringtag, info, errhandler, newintercomm);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Intercomm_create_from_groups(MPI_Group local_group, int local_leader,
                                     MPI_Group remote_group, int remote_leader,
                                     const char *stringtag, MPI_Info info,
                                     MPI_Errhandler errhandler, MPI_Comm *newintercomm)
{
    QMPI_Context context;
    QMPI_Intercomm_create_from_groups_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Intercomm_create_from_groups(context, 0, local_group, local_leader,
                                                 remote_group, remote_leader, stringtag, info,
                                                 errhandler, newintercomm);

    fn_ptr = (QMPI_Intercomm_create_from_groups_t *) MPIR_QMPI_first_fn_ptrs[MPI_INTERCOMM_CREATE_FROM_GROUPS_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_INTERCOMM_CREATE_FROM_GROUPS_T],
            local_group, local_leader, remote_group, remote_leader, stringtag, info, errhandler,
            newintercomm);
}
#else /* ENABLE_QMPI */
int MPI_Intercomm_create_from_groups(MPI_Group local_group, int local_leader,
                                     MPI_Group remote_group, int remote_leader,
                                     const char *stringtag, MPI_Info info,
                                     MPI_Errhandler errhandler, MPI_Comm *newintercomm)
{
    return internal_Intercomm_create_from_groups(local_group, local_leader, remote_group, remote_leader, stringtag, info, errhandler, newintercomm);
}

#endif /* ENABLE_QMPI */
