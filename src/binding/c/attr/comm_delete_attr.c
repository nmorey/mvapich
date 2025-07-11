/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Comm_delete_attr */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Comm_delete_attr = PMPI_Comm_delete_attr
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Comm_delete_attr  MPI_Comm_delete_attr
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Comm_delete_attr as PMPI_Comm_delete_attr
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Comm_delete_attr(MPI_Comm comm, int comm_keyval)
     __attribute__ ((weak, alias("PMPI_Comm_delete_attr")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Comm_delete_attr
#define MPI_Comm_delete_attr PMPI_Comm_delete_attr
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Comm_delete_attr(MPI_Comm comm, int comm_keyval)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Comm *comm_ptr ATTRIBUTE((unused)) = NULL;
    MPII_Keyval *comm_keyval_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COMM(comm, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_Comm_get_ptr(comm, comm_ptr);
    MPII_Keyval_get_ptr(comm_keyval, comm_keyval_ptr);

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_Comm_valid_ptr(comm_ptr, mpi_errno, TRUE);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPII_Keyval_valid_ptr(comm_keyval_ptr, mpi_errno);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_ERRTEST_KEYVAL(comm_keyval, MPIR_COMM, "comm_keyval", mpi_errno);
            MPIR_ERRTEST_KEYVAL_PERM(comm_keyval, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Comm_delete_attr_impl(comm_ptr, comm_keyval_ptr);
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
                                     "**mpi_comm_delete_attr", "**mpi_comm_delete_attr %C %K", comm,
                                     comm_keyval);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Comm_delete_attr(QMPI_Context context, int tool_id, MPI_Comm comm, int comm_keyval)
{
    return internal_Comm_delete_attr(comm, comm_keyval);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Comm_delete_attr(MPI_Comm comm, int comm_keyval)
{
    QMPI_Context context;
    QMPI_Comm_delete_attr_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Comm_delete_attr(context, 0, comm, comm_keyval);

    fn_ptr = (QMPI_Comm_delete_attr_t *) MPIR_QMPI_first_fn_ptrs[MPI_COMM_DELETE_ATTR_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_COMM_DELETE_ATTR_T], comm,
            comm_keyval);
}
#else /* ENABLE_QMPI */
int MPI_Comm_delete_attr(MPI_Comm comm, int comm_keyval)
{
    return internal_Comm_delete_attr(comm, comm_keyval);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Attr_delete */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Attr_delete = PMPI_Attr_delete
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Attr_delete  MPI_Attr_delete
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Attr_delete as PMPI_Attr_delete
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Attr_delete(MPI_Comm comm, int keyval)  __attribute__ ((weak, alias("PMPI_Attr_delete")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Attr_delete
#define MPI_Attr_delete PMPI_Attr_delete
#endif /* MPICH_MPI_FROM_PMPI */

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Attr_delete(QMPI_Context context, int tool_id, MPI_Comm comm, int keyval)
{
    return internal_Comm_delete_attr(comm, keyval);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Attr_delete(MPI_Comm comm, int keyval)
{
    QMPI_Context context;
    QMPI_Attr_delete_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Attr_delete(context, 0, comm, keyval);

    fn_ptr = (QMPI_Attr_delete_t *) MPIR_QMPI_first_fn_ptrs[MPI_ATTR_DELETE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_ATTR_DELETE_T], comm, keyval);
}
#else /* ENABLE_QMPI */
int MPI_Attr_delete(MPI_Comm comm, int keyval)
{
    return internal_Comm_delete_attr(comm, keyval);
}

#endif /* ENABLE_QMPI */
