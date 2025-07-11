/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Error_string */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Error_string = PMPI_Error_string
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Error_string  MPI_Error_string
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Error_string as PMPI_Error_string
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Error_string(int errorcode, char *string, int *resultlen)
     __attribute__ ((weak, alias("PMPI_Error_string")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Error_string
#define MPI_Error_string PMPI_Error_string
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Error_string(int errorcode, char *string, int *resultlen)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            if (MPI_MAX_ERROR_STRING > 0) {
                MPIR_ERRTEST_ARGNULL(string, "string", mpi_errno);
            }
            MPIR_ERRTEST_ARGNULL(resultlen, "resultlen", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Error_string_impl(errorcode, string, resultlen);
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
                                     "**mpi_error_string", "**mpi_error_string %d %p %p", errorcode,
                                     string, resultlen);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Error_string(QMPI_Context context, int tool_id, int errorcode, char *string,
                      int *resultlen)
{
    return internal_Error_string(errorcode, string, resultlen);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Error_string(int errorcode, char *string, int *resultlen)
{
    QMPI_Context context;
    QMPI_Error_string_t *fn_ptr;

    context.storage_stack = NULL;

    int mpi_errno = MPI_SUCCESS;
    mpi_errno = MPII_qmpi_init();
    if (mpi_errno != MPI_SUCCESS) {
        return mpi_errno;
    }

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Error_string(context, 0, errorcode, string, resultlen);

    fn_ptr = (QMPI_Error_string_t *) MPIR_QMPI_first_fn_ptrs[MPI_ERROR_STRING_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_ERROR_STRING_T], errorcode, string,
            resultlen);
}
#else /* ENABLE_QMPI */
int MPI_Error_string(int errorcode, char *string, int *resultlen)
{
    return internal_Error_string(errorcode, string, resultlen);
}

#endif /* ENABLE_QMPI */
