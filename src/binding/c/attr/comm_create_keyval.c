/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Comm_create_keyval */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Comm_create_keyval = PMPI_Comm_create_keyval
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Comm_create_keyval  MPI_Comm_create_keyval
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Comm_create_keyval as PMPI_Comm_create_keyval
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Comm_create_keyval(MPI_Comm_copy_attr_function *comm_copy_attr_fn,
                           MPI_Comm_delete_attr_function *comm_delete_attr_fn, int *comm_keyval,
                           void *extra_state)
                            __attribute__ ((weak, alias("PMPI_Comm_create_keyval")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Comm_create_keyval
#define MPI_Comm_create_keyval PMPI_Comm_create_keyval
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Comm_create_keyval(MPI_Comm_copy_attr_function *comm_copy_attr_fn,
                                       MPI_Comm_delete_attr_function *comm_delete_attr_fn,
                                       int *comm_keyval, void *extra_state)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(comm_keyval, "comm_keyval", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Comm_create_keyval_impl(comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval,
                                             extra_state);
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
                                     "**mpi_comm_create_keyval", "**mpi_comm_create_keyval %p %p %p %p",
                                     comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, extra_state);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Comm_create_keyval(QMPI_Context context, int tool_id,
                            MPI_Comm_copy_attr_function *comm_copy_attr_fn,
                            MPI_Comm_delete_attr_function *comm_delete_attr_fn, int *comm_keyval,
                            void *extra_state)
{
    return internal_Comm_create_keyval(comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, extra_state);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Comm_create_keyval(MPI_Comm_copy_attr_function *comm_copy_attr_fn,
                           MPI_Comm_delete_attr_function *comm_delete_attr_fn, int *comm_keyval,
                           void *extra_state)
{
    QMPI_Context context;
    QMPI_Comm_create_keyval_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Comm_create_keyval(context, 0, comm_copy_attr_fn, comm_delete_attr_fn,
                                       comm_keyval, extra_state);

    fn_ptr = (QMPI_Comm_create_keyval_t *) MPIR_QMPI_first_fn_ptrs[MPI_COMM_CREATE_KEYVAL_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_COMM_CREATE_KEYVAL_T],
            comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, extra_state);
}
#else /* ENABLE_QMPI */
int MPI_Comm_create_keyval(MPI_Comm_copy_attr_function *comm_copy_attr_fn,
                           MPI_Comm_delete_attr_function *comm_delete_attr_fn, int *comm_keyval,
                           void *extra_state)
{
    return internal_Comm_create_keyval(comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, extra_state);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Keyval_create */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Keyval_create = PMPI_Keyval_create
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Keyval_create  MPI_Keyval_create
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Keyval_create as PMPI_Keyval_create
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Keyval_create(MPI_Copy_function *copy_fn, MPI_Delete_function *delete_fn, int *keyval,
                      void *extra_state)  __attribute__ ((weak, alias("PMPI_Keyval_create")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Keyval_create
#define MPI_Keyval_create PMPI_Keyval_create
#endif /* MPICH_MPI_FROM_PMPI */

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Keyval_create(QMPI_Context context, int tool_id, MPI_Copy_function *copy_fn,
                       MPI_Delete_function *delete_fn, int *keyval, void *extra_state)
{
    return internal_Comm_create_keyval(copy_fn, delete_fn, keyval, extra_state);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Keyval_create(MPI_Copy_function *copy_fn, MPI_Delete_function *delete_fn, int *keyval,
                      void *extra_state)
{
    QMPI_Context context;
    QMPI_Keyval_create_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Keyval_create(context, 0, copy_fn, delete_fn, keyval, extra_state);

    fn_ptr = (QMPI_Keyval_create_t *) MPIR_QMPI_first_fn_ptrs[MPI_KEYVAL_CREATE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_KEYVAL_CREATE_T], copy_fn, delete_fn,
            keyval, extra_state);
}
#else /* ENABLE_QMPI */
int MPI_Keyval_create(MPI_Copy_function *copy_fn, MPI_Delete_function *delete_fn, int *keyval,
                      void *extra_state)
{
    return internal_Comm_create_keyval(copy_fn, delete_fn, keyval, extra_state);
}

#endif /* ENABLE_QMPI */
