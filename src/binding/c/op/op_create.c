/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Op_create */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Op_create = PMPI_Op_create
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Op_create  MPI_Op_create
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Op_create as PMPI_Op_create
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Op_create(MPI_User_function *user_fn, int commute, MPI_Op *op)
     __attribute__ ((weak, alias("PMPI_Op_create")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Op_create
#define MPI_Op_create PMPI_Op_create
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Op_create(MPI_User_function *user_fn, int commute, MPI_Op *op)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(user_fn, "user_fn", mpi_errno);
            MPIR_ERRTEST_ARGNULL(op, "op", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPIR_Op *op_ptr ATTRIBUTE((unused)) = NULL;
    *op = MPI_OP_NULL;
    mpi_errno = MPIR_Op_create_impl(user_fn, commute, &op_ptr);
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
                                     "**mpi_op_create", "**mpi_op_create %p %d %p", user_fn, commute,
                                     op);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Op_create(QMPI_Context context, int tool_id, MPI_User_function *user_fn, int commute,
                   MPI_Op *op)
{
    return internal_Op_create(user_fn, commute, op);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Op_create(MPI_User_function *user_fn, int commute, MPI_Op *op)
{
    QMPI_Context context;
    QMPI_Op_create_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Op_create(context, 0, user_fn, commute, op);

    fn_ptr = (QMPI_Op_create_t *) MPIR_QMPI_first_fn_ptrs[MPI_OP_CREATE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_OP_CREATE_T], user_fn, commute, op);
}
#else /* ENABLE_QMPI */
int MPI_Op_create(MPI_User_function *user_fn, int commute, MPI_Op *op)
{
    return internal_Op_create(user_fn, commute, op);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Op_create_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Op_create_c = PMPI_Op_create_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Op_create_c  MPI_Op_create_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Op_create_c as PMPI_Op_create_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Op_create_c(MPI_User_function_c *user_fn, int commute, MPI_Op *op)
     __attribute__ ((weak, alias("PMPI_Op_create_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Op_create_c
#define MPI_Op_create_c PMPI_Op_create_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Op_create_c(MPI_User_function_c *user_fn, int commute, MPI_Op *op)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(user_fn, "user_fn", mpi_errno);
            MPIR_ERRTEST_ARGNULL(op, "op", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        MPIR_Op *op_ptr ATTRIBUTE((unused)) = NULL;
        *op = MPI_OP_NULL;
        mpi_errno = MPIR_Op_create_large_impl(user_fn, commute, &op_ptr);
        if (mpi_errno) {
            goto fn_fail;
        }
        if (op_ptr) {
            MPIR_OBJ_PUBLISH_HANDLE(*op, op_ptr->handle);
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        MPIR_Op *op_ptr ATTRIBUTE((unused)) = NULL;
        *op = MPI_OP_NULL;
        mpi_errno = MPIR_Op_create_large_impl(user_fn, commute, &op_ptr);
        if (mpi_errno) {
            goto fn_fail;
        }
        if (op_ptr) {
            MPIR_OBJ_PUBLISH_HANDLE(*op, op_ptr->handle);
        }
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
                                     "**mpi_op_create_c", "**mpi_op_create_c %p %d %p", user_fn,
                                     commute, op);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Op_create_c(QMPI_Context context, int tool_id, MPI_User_function_c *user_fn, int commute,
                     MPI_Op *op)
{
    return internal_Op_create_c(user_fn, commute, op);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Op_create_c(MPI_User_function_c *user_fn, int commute, MPI_Op *op)
{
    QMPI_Context context;
    QMPI_Op_create_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Op_create_c(context, 0, user_fn, commute, op);

    fn_ptr = (QMPI_Op_create_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_OP_CREATE_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_OP_CREATE_C_T], user_fn, commute, op);
}
#else /* ENABLE_QMPI */
int MPI_Op_create_c(MPI_User_function_c *user_fn, int commute, MPI_Op *op)
{
    return internal_Op_create_c(user_fn, commute, op);
}

#endif /* ENABLE_QMPI */
