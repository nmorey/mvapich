/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Comm_free_keyval */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Comm_free_keyval = PMPI_Comm_free_keyval
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Comm_free_keyval  MPI_Comm_free_keyval
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Comm_free_keyval as PMPI_Comm_free_keyval
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Comm_free_keyval(int *comm_keyval)  __attribute__ ((weak, alias("PMPI_Comm_free_keyval")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Comm_free_keyval
#define MPI_Comm_free_keyval PMPI_Comm_free_keyval
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Comm_free_keyval(int *comm_keyval)
{
    int mpi_errno = MPI_SUCCESS;
    MPII_Keyval *comm_keyval_ptr ATTRIBUTE((unused)) = NULL;

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

    MPII_Keyval_get_ptr(*comm_keyval, comm_keyval_ptr);

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPII_Keyval_valid_ptr(comm_keyval_ptr, mpi_errno);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_ERRTEST_KEYVAL(*comm_keyval, MPIR_COMM, "*comm_keyval", mpi_errno);
            MPIR_ERRTEST_KEYVAL_PERM(*comm_keyval, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Comm_free_keyval_impl(comm_keyval_ptr);
    if (mpi_errno) {
        goto fn_fail;
    }
    *comm_keyval = MPI_KEYVAL_INVALID;
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    MPID_THREAD_CS_EXIT(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_comm_free_keyval", "**mpi_comm_free_keyval %p",
                                     comm_keyval);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Comm_free_keyval(QMPI_Context context, int tool_id, int *comm_keyval)
{
    return internal_Comm_free_keyval(comm_keyval);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Comm_free_keyval(int *comm_keyval)
{
    QMPI_Context context;
    QMPI_Comm_free_keyval_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Comm_free_keyval(context, 0, comm_keyval);

    fn_ptr = (QMPI_Comm_free_keyval_t *) MPIR_QMPI_first_fn_ptrs[MPI_COMM_FREE_KEYVAL_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_COMM_FREE_KEYVAL_T], comm_keyval);
}
#else /* ENABLE_QMPI */
int MPI_Comm_free_keyval(int *comm_keyval)
{
    return internal_Comm_free_keyval(comm_keyval);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Keyval_free */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Keyval_free = PMPI_Keyval_free
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Keyval_free  MPI_Keyval_free
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Keyval_free as PMPI_Keyval_free
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Keyval_free(int *keyval)  __attribute__ ((weak, alias("PMPI_Keyval_free")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Keyval_free
#define MPI_Keyval_free PMPI_Keyval_free
#endif /* MPICH_MPI_FROM_PMPI */

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Keyval_free(QMPI_Context context, int tool_id, int *keyval)
{
    return internal_Comm_free_keyval(keyval);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Keyval_free(int *keyval)
{
    QMPI_Context context;
    QMPI_Keyval_free_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Keyval_free(context, 0, keyval);

    fn_ptr = (QMPI_Keyval_free_t *) MPIR_QMPI_first_fn_ptrs[MPI_KEYVAL_FREE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_KEYVAL_FREE_T], keyval);
}
#else /* ENABLE_QMPI */
int MPI_Keyval_free(int *keyval)
{
    return internal_Comm_free_keyval(keyval);
}

#endif /* ENABLE_QMPI */
