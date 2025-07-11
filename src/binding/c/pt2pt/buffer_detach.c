/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Buffer_detach */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Buffer_detach = PMPI_Buffer_detach
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Buffer_detach  MPI_Buffer_detach
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Buffer_detach as PMPI_Buffer_detach
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Buffer_detach(void *buffer_addr, int *size)
     __attribute__ ((weak, alias("PMPI_Buffer_detach")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Buffer_detach
#define MPI_Buffer_detach PMPI_Buffer_detach
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Buffer_detach(void *buffer_addr, int *size)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(buffer_addr, "buffer_addr", mpi_errno);
            MPIR_ERRTEST_ARGNULL(size, "size", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPI_Aint size_c;
    mpi_errno = MPIR_Buffer_detach_impl(buffer_addr, &size_c);
    if (mpi_errno) {
        goto fn_fail;
    }
    if (size_c > INT_MAX) {
        *size = MPI_UNDEFINED;
    } else {
        *size = size_c;
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
                                     "**mpi_buffer_detach", "**mpi_buffer_detach %p %p", buffer_addr,
                                     size);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Buffer_detach(QMPI_Context context, int tool_id, void *buffer_addr, int *size)
{
    return internal_Buffer_detach(buffer_addr, size);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Buffer_detach(void *buffer_addr, int *size)
{
    QMPI_Context context;
    QMPI_Buffer_detach_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Buffer_detach(context, 0, buffer_addr, size);

    fn_ptr = (QMPI_Buffer_detach_t *) MPIR_QMPI_first_fn_ptrs[MPI_BUFFER_DETACH_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_BUFFER_DETACH_T], buffer_addr, size);
}
#else /* ENABLE_QMPI */
int MPI_Buffer_detach(void *buffer_addr, int *size)
{
    return internal_Buffer_detach(buffer_addr, size);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Buffer_detach_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Buffer_detach_c = PMPI_Buffer_detach_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Buffer_detach_c  MPI_Buffer_detach_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Buffer_detach_c as PMPI_Buffer_detach_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Buffer_detach_c(void *buffer_addr, MPI_Count *size)
     __attribute__ ((weak, alias("PMPI_Buffer_detach_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Buffer_detach_c
#define MPI_Buffer_detach_c PMPI_Buffer_detach_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Buffer_detach_c(void *buffer_addr, MPI_Count *size)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(buffer_addr, "buffer_addr", mpi_errno);
            MPIR_ERRTEST_ARGNULL(size, "size", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_Buffer_detach_impl(buffer_addr, (MPI_Aint *) size);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        MPI_Aint size_c;
        mpi_errno = MPIR_Buffer_detach_impl(buffer_addr, &size_c);
        if (mpi_errno) {
            goto fn_fail;
        }
        *size = size_c;
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
                                     "**mpi_buffer_detach_c", "**mpi_buffer_detach_c %p %p",
                                     buffer_addr, size);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Buffer_detach_c(QMPI_Context context, int tool_id, void *buffer_addr, MPI_Count *size)
{
    return internal_Buffer_detach_c(buffer_addr, size);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Buffer_detach_c(void *buffer_addr, MPI_Count *size)
{
    QMPI_Context context;
    QMPI_Buffer_detach_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Buffer_detach_c(context, 0, buffer_addr, size);

    fn_ptr = (QMPI_Buffer_detach_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_BUFFER_DETACH_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_BUFFER_DETACH_C_T], buffer_addr, size);
}
#else /* ENABLE_QMPI */
int MPI_Buffer_detach_c(void *buffer_addr, MPI_Count *size)
{
    return internal_Buffer_detach_c(buffer_addr, size);
}

#endif /* ENABLE_QMPI */
