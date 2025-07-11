/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Info_create_env */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Info_create_env = PMPI_Info_create_env
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Info_create_env  MPI_Info_create_env
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Info_create_env as PMPI_Info_create_env
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Info_create_env(int argc, char *argv[], MPI_Info *info)
     __attribute__ ((weak, alias("PMPI_Info_create_env")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Info_create_env
#define MPI_Info_create_env PMPI_Info_create_env
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Info_create_env(int argc, char *argv[], MPI_Info *info)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(info, "info", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPIR_Info *info_ptr ATTRIBUTE((unused)) = NULL;
    *info = MPI_INFO_NULL;
    mpi_errno = MPIR_Info_create_env_impl(argc, argv, &info_ptr);
    if (mpi_errno) {
        goto fn_fail;
    }
    if (info_ptr) {
        MPIR_OBJ_PUBLISH_HANDLE(*info, info_ptr->handle);
    }
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_info_create_env", "**mpi_info_create_env %p %p %p", argc,
                                     argv, info);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Info_create_env(QMPI_Context context, int tool_id, int argc, char *argv[], MPI_Info *info)
{
    return internal_Info_create_env(argc, argv, info);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Info_create_env(int argc, char *argv[], MPI_Info *info)
{
    QMPI_Context context;
    QMPI_Info_create_env_t *fn_ptr;

    context.storage_stack = NULL;

    int mpi_errno = MPI_SUCCESS;
    mpi_errno = MPII_qmpi_init();
    if (mpi_errno != MPI_SUCCESS) {
        return mpi_errno;
    }

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Info_create_env(context, 0, argc, argv, info);

    fn_ptr = (QMPI_Info_create_env_t *) MPIR_QMPI_first_fn_ptrs[MPI_INFO_CREATE_ENV_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_INFO_CREATE_ENV_T], argc, argv, info);
}
#else /* ENABLE_QMPI */
int MPI_Info_create_env(int argc, char *argv[], MPI_Info *info)
{
    return internal_Info_create_env(argc, argv, info);
}

#endif /* ENABLE_QMPI */
