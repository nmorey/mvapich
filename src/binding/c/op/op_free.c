/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Op_free */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Op_free = PMPI_Op_free
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Op_free  MPI_Op_free
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Op_free as PMPI_Op_free
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Op_free(MPI_Op *op)  __attribute__ ((weak, alias("PMPI_Op_free")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Op_free
#define MPI_Op_free PMPI_Op_free
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Op_free(MPI_Op *op)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Op *op_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(op, "op", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_Op_get_ptr(*op, op_ptr);

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_Op_valid_ptr(op_ptr, mpi_errno);
            if (mpi_errno) {
                goto fn_fail;
            }
            if (HANDLE_IS_BUILTIN(*op)) {
                mpi_errno = MPIR_Err_create_code(MPI_SUCCESS, MPIR_ERR_RECOVERABLE, __func__, __LINE__,
                                                 MPI_ERR_OP, "**permop", 0);
                goto fn_fail;
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Op_free_impl(op_ptr);
    if (mpi_errno) {
        goto fn_fail;
    }
    *op = MPI_OP_NULL;
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    MPID_THREAD_CS_EXIT(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_op_free", "**mpi_op_free %p", op);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Op_free(QMPI_Context context, int tool_id, MPI_Op *op)
{
    return internal_Op_free(op);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Op_free(MPI_Op *op)
{
    QMPI_Context context;
    QMPI_Op_free_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Op_free(context, 0, op);

    fn_ptr = (QMPI_Op_free_t *) MPIR_QMPI_first_fn_ptrs[MPI_OP_FREE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_OP_FREE_T], op);
}
#else /* ENABLE_QMPI */
int MPI_Op_free(MPI_Op *op)
{
    return internal_Op_free(op);
}

#endif /* ENABLE_QMPI */
