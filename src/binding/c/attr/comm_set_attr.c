/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Comm_set_attr */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Comm_set_attr = PMPI_Comm_set_attr
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Comm_set_attr  MPI_Comm_set_attr
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Comm_set_attr as PMPI_Comm_set_attr
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Comm_set_attr(MPI_Comm comm, int comm_keyval, void *attribute_val)
     __attribute__ ((weak, alias("PMPI_Comm_set_attr")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Comm_set_attr
#define MPI_Comm_set_attr PMPI_Comm_set_attr
#endif /* MPICH_MPI_FROM_PMPI */

#ifndef MPICH_MPI_FROM_PMPI
int MPII_Comm_set_attr(MPI_Comm comm, int comm_keyval, void *attribute_val,
                       MPIR_Attr_type attr_type)
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
    mpi_errno = MPIR_Comm_set_attr_impl(comm_ptr, comm_keyval_ptr, attribute_val, attr_type);
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
                                     "**mpi_comm_set_attr", "**mpi_comm_set_attr %C %K %p", comm,
                                     comm_keyval, attribute_val);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Comm_set_attr(MPI_Comm comm, int comm_keyval, void *attribute_val)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_FUNC_TERSE_ENTER;

    mpi_errno = MPII_Comm_set_attr(comm, comm_keyval, attribute_val, MPIR_ATTR_PTR);

    MPIR_FUNC_TERSE_EXIT;
    return mpi_errno;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Comm_set_attr(QMPI_Context context, int tool_id, MPI_Comm comm, int comm_keyval,
                       void *attribute_val)
{
    return internal_Comm_set_attr(comm, comm_keyval, attribute_val);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Comm_set_attr(MPI_Comm comm, int comm_keyval, void *attribute_val)
{
    QMPI_Context context;
    QMPI_Comm_set_attr_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Comm_set_attr(context, 0, comm, comm_keyval, attribute_val);

    fn_ptr = (QMPI_Comm_set_attr_t *) MPIR_QMPI_first_fn_ptrs[MPI_COMM_SET_ATTR_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_COMM_SET_ATTR_T], comm, comm_keyval,
            attribute_val);
}
#else /* ENABLE_QMPI */
int MPI_Comm_set_attr(MPI_Comm comm, int comm_keyval, void *attribute_val)
{
    return internal_Comm_set_attr(comm, comm_keyval, attribute_val);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Attr_put */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Attr_put = PMPI_Attr_put
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Attr_put  MPI_Attr_put
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Attr_put as PMPI_Attr_put
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Attr_put(MPI_Comm comm, int keyval, void *attribute_val)
     __attribute__ ((weak, alias("PMPI_Attr_put")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Attr_put
#define MPI_Attr_put PMPI_Attr_put
#endif /* MPICH_MPI_FROM_PMPI */

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Attr_put(QMPI_Context context, int tool_id, MPI_Comm comm, int keyval,
                  void *attribute_val)
{
    return internal_Comm_set_attr(comm, keyval, attribute_val);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Attr_put(MPI_Comm comm, int keyval, void *attribute_val)
{
    QMPI_Context context;
    QMPI_Attr_put_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Attr_put(context, 0, comm, keyval, attribute_val);

    fn_ptr = (QMPI_Attr_put_t *) MPIR_QMPI_first_fn_ptrs[MPI_ATTR_PUT_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_ATTR_PUT_T], comm, keyval,
            attribute_val);
}
#else /* ENABLE_QMPI */
int MPI_Attr_put(MPI_Comm comm, int keyval, void *attribute_val)
{
    return internal_Comm_set_attr(comm, keyval, attribute_val);
}

#endif /* ENABLE_QMPI */
