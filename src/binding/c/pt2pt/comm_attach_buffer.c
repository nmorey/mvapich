/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Comm_attach_buffer */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Comm_attach_buffer = PMPI_Comm_attach_buffer
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Comm_attach_buffer  MPI_Comm_attach_buffer
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Comm_attach_buffer as PMPI_Comm_attach_buffer
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Comm_attach_buffer(MPI_Comm comm, void *buffer, int size)
     __attribute__ ((weak, alias("PMPI_Comm_attach_buffer")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Comm_attach_buffer
#define MPI_Comm_attach_buffer PMPI_Comm_attach_buffer
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Comm_attach_buffer(MPI_Comm comm, void *buffer, int size)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Comm *comm_ptr ATTRIBUTE((unused)) = NULL;

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

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_Comm_valid_ptr(comm_ptr, mpi_errno, FALSE);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_ERRTEST_ARGNULL(buffer, "buffer", mpi_errno);
            MPIR_ERRTEST_ARGNEG(size, "size", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Comm_attach_buffer_impl(comm_ptr, buffer, size);
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
                                     "**mpi_comm_attach_buffer", "**mpi_comm_attach_buffer %C %p %d",
                                     comm, buffer, size);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Comm_attach_buffer(QMPI_Context context, int tool_id, MPI_Comm comm, void *buffer,
                            int size)
{
    return internal_Comm_attach_buffer(comm, buffer, size);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Comm_attach_buffer(MPI_Comm comm, void *buffer, int size)
{
    QMPI_Context context;
    QMPI_Comm_attach_buffer_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Comm_attach_buffer(context, 0, comm, buffer, size);

    fn_ptr = (QMPI_Comm_attach_buffer_t *) MPIR_QMPI_first_fn_ptrs[MPI_COMM_ATTACH_BUFFER_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_COMM_ATTACH_BUFFER_T], comm, buffer,
            size);
}
#else /* ENABLE_QMPI */
int MPI_Comm_attach_buffer(MPI_Comm comm, void *buffer, int size)
{
    return internal_Comm_attach_buffer(comm, buffer, size);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Comm_attach_buffer_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Comm_attach_buffer_c = PMPI_Comm_attach_buffer_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Comm_attach_buffer_c  MPI_Comm_attach_buffer_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Comm_attach_buffer_c as PMPI_Comm_attach_buffer_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Comm_attach_buffer_c(MPI_Comm comm, void *buffer, MPI_Count size)
     __attribute__ ((weak, alias("PMPI_Comm_attach_buffer_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Comm_attach_buffer_c
#define MPI_Comm_attach_buffer_c PMPI_Comm_attach_buffer_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Comm_attach_buffer_c(MPI_Comm comm, void *buffer, MPI_Count size)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Comm *comm_ptr ATTRIBUTE((unused)) = NULL;

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

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_Comm_valid_ptr(comm_ptr, mpi_errno, FALSE);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_ERRTEST_ARGNULL(buffer, "buffer", mpi_errno);
            MPIR_ERRTEST_ARGNEG(size, "size", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_Comm_attach_buffer_impl(comm_ptr, buffer, (MPI_Aint) size);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (size > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "size");
            goto fn_fail;
        }
        mpi_errno = MPIR_Comm_attach_buffer_impl(comm_ptr, buffer, size);
        if (mpi_errno) {
            goto fn_fail;
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
                                     "**mpi_comm_attach_buffer_c",
                                     "**mpi_comm_attach_buffer_c %C %p %c", comm, buffer, size);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Comm_attach_buffer_c(QMPI_Context context, int tool_id, MPI_Comm comm, void *buffer,
                              MPI_Count size)
{
    return internal_Comm_attach_buffer_c(comm, buffer, size);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Comm_attach_buffer_c(MPI_Comm comm, void *buffer, MPI_Count size)
{
    QMPI_Context context;
    QMPI_Comm_attach_buffer_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Comm_attach_buffer_c(context, 0, comm, buffer, size);

    fn_ptr = (QMPI_Comm_attach_buffer_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_COMM_ATTACH_BUFFER_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_COMM_ATTACH_BUFFER_C_T], comm, buffer,
            size);
}
#else /* ENABLE_QMPI */
int MPI_Comm_attach_buffer_c(MPI_Comm comm, void *buffer, MPI_Count size)
{
    return internal_Comm_attach_buffer_c(comm, buffer, size);
}

#endif /* ENABLE_QMPI */
