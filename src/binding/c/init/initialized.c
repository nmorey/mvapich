/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

#include "mpi_init.h"
#if defined(HAVE_ROMIO) && defined(MPICH_MPI_FROM_PMPI)
void MPIR_Comm_split_filesystem(void);
void MPIR_ROMIO_Get_file_errhand(void);
void MPIR_ROMIO_Set_file_errhand(void);
void *dummy_refs_MPI_Initialized[] = {
    (void *) MPIR_Comm_split_filesystem,
    (void *) MPIR_ROMIO_Get_file_errhand,
    (void *) MPIR_ROMIO_Set_file_errhand,
};
#endif

/* -- Begin Profiling Symbol Block for routine MPI_Initialized */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Initialized = PMPI_Initialized
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Initialized  MPI_Initialized
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Initialized as PMPI_Initialized
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Initialized(int *flag)  __attribute__ ((weak, alias("PMPI_Initialized")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Initialized
#define MPI_Initialized PMPI_Initialized
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Initialized(int *flag)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(flag, "flag", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Initialized_impl(flag);
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
    if (MPIR_Errutil_is_initialized()) {
        mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**mpi_initialized", "**mpi_initialized %p", flag);
        mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    }
#endif
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Initialized(QMPI_Context context, int tool_id, int *flag)
{
    return internal_Initialized(flag);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Initialized(int *flag)
{
    QMPI_Context context;
    QMPI_Initialized_t *fn_ptr;

    context.storage_stack = NULL;

    int mpi_errno = MPI_SUCCESS;
    mpi_errno = MPII_qmpi_init();
    if (mpi_errno != MPI_SUCCESS) {
        return mpi_errno;
    }

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Initialized(context, 0, flag);

    fn_ptr = (QMPI_Initialized_t *) MPIR_QMPI_first_fn_ptrs[MPI_INITIALIZED_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_INITIALIZED_T], flag);
}
#else /* ENABLE_QMPI */
int MPI_Initialized(int *flag)
{
    return internal_Initialized(flag);
}

#endif /* ENABLE_QMPI */
