/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Error_class */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Error_class = PMPI_Error_class
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Error_class  MPI_Error_class
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Error_class as PMPI_Error_class
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Error_class(int errorcode, int *errorclass)
     __attribute__ ((weak, alias("PMPI_Error_class")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Error_class
#define MPI_Error_class PMPI_Error_class
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Error_class(int errorcode, int *errorclass)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(errorclass, "errorclass", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Error_class_impl(errorcode, errorclass);
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
                                     "**mpi_error_class", "**mpi_error_class %d %p", errorcode,
                                     errorclass);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Error_class(QMPI_Context context, int tool_id, int errorcode, int *errorclass)
{
    return internal_Error_class(errorcode, errorclass);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Error_class(int errorcode, int *errorclass)
{
    QMPI_Context context;
    QMPI_Error_class_t *fn_ptr;

    context.storage_stack = NULL;

    int mpi_errno = MPI_SUCCESS;
    mpi_errno = MPII_qmpi_init();
    if (mpi_errno != MPI_SUCCESS) {
        return mpi_errno;
    }

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Error_class(context, 0, errorcode, errorclass);

    fn_ptr = (QMPI_Error_class_t *) MPIR_QMPI_first_fn_ptrs[MPI_ERROR_CLASS_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_ERROR_CLASS_T], errorcode, errorclass);
}
#else /* ENABLE_QMPI */
int MPI_Error_class(int errorcode, int *errorclass)
{
    return internal_Error_class(errorcode, errorclass);
}

#endif /* ENABLE_QMPI */
