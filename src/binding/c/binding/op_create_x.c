/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPIX_Op_create_x */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPIX_Op_create_x = PMPIX_Op_create_x
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPIX_Op_create_x  MPIX_Op_create_x
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPIX_Op_create_x as PMPIX_Op_create_x
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPIX_Op_create_x(MPIX_User_function_x *user_fn_x, MPIX_Destructor_function *destructor_fn,
                     int commute, void *extra_state, MPI_Op *op)
                      __attribute__ ((weak, alias("PMPIX_Op_create_x")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPIX_Op_create_x
#define MPIX_Op_create_x PMPIX_Op_create_x
#endif /* MPICH_MPI_FROM_PMPI */

static int internalX_Op_create_x(MPIX_User_function_x *user_fn_x,
                                 MPIX_Destructor_function *destructor_fn, int commute,
                                 void *extra_state, MPI_Op *op)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(user_fn_x, "user_fn_x", mpi_errno);
            MPIR_ERRTEST_ARGNULL(destructor_fn, "destructor_fn", mpi_errno);
            MPIR_ERRTEST_ARGNULL(op, "op", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPIR_Op *op_ptr ATTRIBUTE((unused)) = NULL;
    *op = MPI_OP_NULL;
    mpi_errno = MPIR_Op_create_x_impl(user_fn_x, destructor_fn, commute, extra_state, &op_ptr);
    if (mpi_errno) {
        goto fn_fail;
    }
    if (op_ptr) {
        MPIR_OBJ_PUBLISH_HANDLE(*op, op_ptr->handle);
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
                                     "**mpix_op_create_x", "**mpix_op_create_x %p %p %d %p %p",
                                     user_fn_x, destructor_fn, commute, extra_state, op);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPIX_Op_create_x(QMPI_Context context, int tool_id, MPIX_User_function_x *user_fn_x,
                      MPIX_Destructor_function *destructor_fn, int commute, void *extra_state,
                      MPI_Op *op)
{
    return internalX_Op_create_x(user_fn_x, destructor_fn, commute, extra_state, op);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPIX_Op_create_x(MPIX_User_function_x *user_fn_x, MPIX_Destructor_function *destructor_fn,
                     int commute, void *extra_state, MPI_Op *op)
{
    QMPI_Context context;
    QMPIX_Op_create_x_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPIX_Op_create_x(context, 0, user_fn_x, destructor_fn, commute, extra_state, op);

    fn_ptr = (QMPIX_Op_create_x_t *) MPIR_QMPI_first_fn_ptrs[MPIX_OP_CREATE_X_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPIX_OP_CREATE_X_T], user_fn_x,
            destructor_fn, commute, extra_state, op);
}
#else /* ENABLE_QMPI */
int MPIX_Op_create_x(MPIX_User_function_x *user_fn_x, MPIX_Destructor_function *destructor_fn,
                     int commute, void *extra_state, MPI_Op *op)
{
    return internalX_Op_create_x(user_fn_x, destructor_fn, commute, extra_state, op);
}

#endif /* ENABLE_QMPI */
