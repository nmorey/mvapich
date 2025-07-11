/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Op_commutative */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Op_commutative = PMPI_Op_commutative
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Op_commutative  MPI_Op_commutative
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Op_commutative as PMPI_Op_commutative
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Op_commutative(MPI_Op op, int *commute)
     __attribute__ ((weak, alias("PMPI_Op_commutative")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Op_commutative
#define MPI_Op_commutative PMPI_Op_commutative
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Op_commutative(MPI_Op op, int *commute)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            if (!HANDLE_IS_BUILTIN(op)) {
                MPIR_Op *op_ptr = NULL;
                MPIR_Op_get_ptr(op, op_ptr);
                MPIR_Op_valid_ptr(op_ptr, mpi_errno);
            }
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_ERRTEST_ARGNULL(commute, "commute", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Op_commutative_impl(op, commute);
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
                                     "**mpi_op_commutative", "**mpi_op_commutative %O %p", op,
                                     commute);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Op_commutative(QMPI_Context context, int tool_id, MPI_Op op, int *commute)
{
    return internal_Op_commutative(op, commute);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Op_commutative(MPI_Op op, int *commute)
{
    QMPI_Context context;
    QMPI_Op_commutative_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Op_commutative(context, 0, op, commute);

    fn_ptr = (QMPI_Op_commutative_t *) MPIR_QMPI_first_fn_ptrs[MPI_OP_COMMUTATIVE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_OP_COMMUTATIVE_T], op, commute);
}
#else /* ENABLE_QMPI */
int MPI_Op_commutative(MPI_Op op, int *commute)
{
    return internal_Op_commutative(op, commute);
}

#endif /* ENABLE_QMPI */
