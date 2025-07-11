/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

#if defined(HAVE_ROMIO) && defined(MPICH_MPI_FROM_PMPI)
void MPIR_Comm_split_filesystem(void);
void MPIR_ROMIO_Get_file_errhand(void);
void MPIR_ROMIO_Set_file_errhand(void);
void *dummy_refs_MPI_Get_library_version[] = {
    (void *) MPIR_Comm_split_filesystem,
    (void *) MPIR_ROMIO_Get_file_errhand,
    (void *) MPIR_ROMIO_Set_file_errhand,
};
#endif

/* -- Begin Profiling Symbol Block for routine MPI_Get_library_version */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Get_library_version = PMPI_Get_library_version
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Get_library_version  MPI_Get_library_version
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Get_library_version as PMPI_Get_library_version
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Get_library_version(char *version, int *resultlen)
     __attribute__ ((weak, alias("PMPI_Get_library_version")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Get_library_version
#define MPI_Get_library_version PMPI_Get_library_version
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Get_library_version(char *version, int *resultlen)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            if (MPI_MAX_LIBRARY_VERSION_STRING > 0) {
                MPIR_ERRTEST_ARGNULL(version, "version", mpi_errno);
            }
            MPIR_ERRTEST_ARGNULL(resultlen, "resultlen", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Get_library_version_impl(version, resultlen);
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
                                     "**mpi_get_library_version", "**mpi_get_library_version %p %p",
                                     version, resultlen);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Get_library_version(QMPI_Context context, int tool_id, char *version, int *resultlen)
{
    return internal_Get_library_version(version, resultlen);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Get_library_version(char *version, int *resultlen)
{
    QMPI_Context context;
    QMPI_Get_library_version_t *fn_ptr;

    context.storage_stack = NULL;

    int mpi_errno = MPI_SUCCESS;
    mpi_errno = MPII_qmpi_init();
    if (mpi_errno != MPI_SUCCESS) {
        return mpi_errno;
    }

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Get_library_version(context, 0, version, resultlen);

    fn_ptr = (QMPI_Get_library_version_t *) MPIR_QMPI_first_fn_ptrs[MPI_GET_LIBRARY_VERSION_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_GET_LIBRARY_VERSION_T], version,
            resultlen);
}
#else /* ENABLE_QMPI */
int MPI_Get_library_version(char *version, int *resultlen)
{
    return internal_Get_library_version(version, resultlen);
}

#endif /* ENABLE_QMPI */
