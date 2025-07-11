/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Add_error_code */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Add_error_code = PMPI_Add_error_code
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Add_error_code  MPI_Add_error_code
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Add_error_code as PMPI_Add_error_code
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Add_error_code(int errorclass, int *errorcode)
     __attribute__ ((weak, alias("PMPI_Add_error_code")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Add_error_code
#define MPI_Add_error_code PMPI_Add_error_code
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Add_error_code(int errorclass, int *errorcode)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(errorcode, "errorcode", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Add_error_code_impl(errorclass, errorcode);
    if (mpi_errno) {
        goto fn_fail;
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
                                     "**mpi_add_error_code", "**mpi_add_error_code %d %p", errorclass,
                                     errorcode);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Add_error_code(QMPI_Context context, int tool_id, int errorclass, int *errorcode)
{
    return internal_Add_error_code(errorclass, errorcode);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Add_error_code(int errorclass, int *errorcode)
{
    QMPI_Context context;
    QMPI_Add_error_code_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Add_error_code(context, 0, errorclass, errorcode);

    fn_ptr = (QMPI_Add_error_code_t *) MPIR_QMPI_first_fn_ptrs[MPI_ADD_ERROR_CODE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_ADD_ERROR_CODE_T], errorclass,
            errorcode);
}
#else /* ENABLE_QMPI */
int MPI_Add_error_code(int errorclass, int *errorcode)
{
    return internal_Add_error_code(errorclass, errorcode);
}

#endif /* ENABLE_QMPI */
