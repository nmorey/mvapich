/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Get_version */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Get_version = PMPI_Get_version
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Get_version  MPI_Get_version
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Get_version as PMPI_Get_version
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Get_version(int *version, int *subversion)
     __attribute__ ((weak, alias("PMPI_Get_version")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Get_version
#define MPI_Get_version PMPI_Get_version
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Get_version(int *version, int *subversion)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(version, "version", mpi_errno);
            MPIR_ERRTEST_ARGNULL(subversion, "subversion", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Get_version_impl(version, subversion);
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
                                     "**mpi_get_version", "**mpi_get_version %p %p", version,
                                     subversion);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Get_version(QMPI_Context context, int tool_id, int *version, int *subversion)
{
    return internal_Get_version(version, subversion);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Get_version(int *version, int *subversion)
{
    QMPI_Context context;
    QMPI_Get_version_t *fn_ptr;

    context.storage_stack = NULL;

    int mpi_errno = MPI_SUCCESS;
    mpi_errno = MPII_qmpi_init();
    if (mpi_errno != MPI_SUCCESS) {
        return mpi_errno;
    }

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Get_version(context, 0, version, subversion);

    fn_ptr = (QMPI_Get_version_t *) MPIR_QMPI_first_fn_ptrs[MPI_GET_VERSION_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_GET_VERSION_T], version, subversion);
}
#else /* ENABLE_QMPI */
int MPI_Get_version(int *version, int *subversion)
{
    return internal_Get_version(version, subversion);
}

#endif /* ENABLE_QMPI */
