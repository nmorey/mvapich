/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Unpack */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Unpack = PMPI_Unpack
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Unpack  MPI_Unpack
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Unpack as PMPI_Unpack
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Unpack(const void *inbuf, int insize, int *position, void *outbuf, int outcount,
               MPI_Datatype datatype, MPI_Comm comm)  __attribute__ ((weak, alias("PMPI_Unpack")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Unpack
#define MPI_Unpack PMPI_Unpack
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Unpack(const void *inbuf, int insize, int *position, void *outbuf, int outcount,
                           MPI_Datatype datatype, MPI_Comm comm)
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
            MPIR_ERRTEST_ARGNEG(insize, "insize", mpi_errno);
            MPIR_ERRTEST_ARGNULL(position, "position", mpi_errno);
            MPIR_ERRTEST_COUNT(outcount, mpi_errno);
            MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
            if (!HANDLE_IS_BUILTIN(datatype)) {
                MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
                MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            /* MPI_BOTTOM cannot be used when count > 1 */
            if (outcount > 1) {
                MPIR_ERRTEST_ARGNULL(outbuf, "outbuf", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPI_Aint dt_size;
    MPIR_Datatype_get_size_macro(datatype, dt_size);
    if (dt_size == 0) {
        goto fn_exit;
    }

    /* ... body of routine ... */
    MPI_Aint position_c = *position;
    mpi_errno = MPIR_Unpack_impl(inbuf, insize, &position_c, outbuf, outcount, datatype, comm_ptr);
    if (mpi_errno) {
        goto fn_fail;
    }
    if (position_c > INT_MAX) {
        *position = MPI_UNDEFINED;
    } else {
        *position = position_c;
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
                                     "**mpi_unpack", "**mpi_unpack %p %d %p %p %d %D %C", inbuf, insize,
                                     position, outbuf, outcount, datatype, comm);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Unpack(QMPI_Context context, int tool_id, const void *inbuf, int insize, int *position,
                void *outbuf, int outcount, MPI_Datatype datatype, MPI_Comm comm)
{
    return internal_Unpack(inbuf, insize, position, outbuf, outcount, datatype, comm);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Unpack(const void *inbuf, int insize, int *position, void *outbuf, int outcount,
               MPI_Datatype datatype, MPI_Comm comm)
{
    QMPI_Context context;
    QMPI_Unpack_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Unpack(context, 0, inbuf, insize, position, outbuf, outcount, datatype, comm);

    fn_ptr = (QMPI_Unpack_t *) MPIR_QMPI_first_fn_ptrs[MPI_UNPACK_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_UNPACK_T], inbuf, insize, position,
            outbuf, outcount, datatype, comm);
}
#else /* ENABLE_QMPI */
int MPI_Unpack(const void *inbuf, int insize, int *position, void *outbuf, int outcount,
               MPI_Datatype datatype, MPI_Comm comm)
{
    return internal_Unpack(inbuf, insize, position, outbuf, outcount, datatype, comm);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Unpack_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Unpack_c = PMPI_Unpack_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Unpack_c  MPI_Unpack_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Unpack_c as PMPI_Unpack_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Unpack_c(const void *inbuf, MPI_Count insize, MPI_Count *position, void *outbuf,
                 MPI_Count outcount, MPI_Datatype datatype, MPI_Comm comm)
                  __attribute__ ((weak, alias("PMPI_Unpack_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Unpack_c
#define MPI_Unpack_c PMPI_Unpack_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Unpack_c(const void *inbuf, MPI_Count insize, MPI_Count *position, void *outbuf,
                             MPI_Count outcount, MPI_Datatype datatype, MPI_Comm comm)
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
            MPIR_ERRTEST_ARGNEG(insize, "insize", mpi_errno);
            MPIR_ERRTEST_ARGNULL(position, "position", mpi_errno);
            MPIR_ERRTEST_COUNT(outcount, mpi_errno);
            MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
            if (!HANDLE_IS_BUILTIN(datatype)) {
                MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
                MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            /* MPI_BOTTOM cannot be used when count > 1 */
            if (outcount > 1) {
                MPIR_ERRTEST_ARGNULL(outbuf, "outbuf", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPI_Aint dt_size;
    MPIR_Datatype_get_size_macro(datatype, dt_size);
    if (dt_size == 0) {
        goto fn_exit;
    }

    /* ... body of routine ... */
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_Unpack_impl(inbuf, (MPI_Aint) insize, (MPI_Aint *) position, outbuf,
                                     (MPI_Aint) outcount, datatype, comm_ptr);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (insize > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "insize");
            goto fn_fail;
        }
        if (outcount > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "outcount");
            goto fn_fail;
        }
        if (*position > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "*position");
            goto fn_fail;
        }
        MPI_Aint position_c = *position;
        mpi_errno = MPIR_Unpack_impl(inbuf, insize, &position_c, outbuf, outcount, datatype, comm_ptr);
        if (mpi_errno) {
            goto fn_fail;
        }
        *position = position_c;
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
                                     "**mpi_unpack_c", "**mpi_unpack_c %p %c %p %p %c %D %C", inbuf,
                                     insize, position, outbuf, outcount, datatype, comm);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Unpack_c(QMPI_Context context, int tool_id, const void *inbuf, MPI_Count insize,
                  MPI_Count *position, void *outbuf, MPI_Count outcount, MPI_Datatype datatype,
                  MPI_Comm comm)
{
    return internal_Unpack_c(inbuf, insize, position, outbuf, outcount, datatype, comm);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Unpack_c(const void *inbuf, MPI_Count insize, MPI_Count *position, void *outbuf,
                 MPI_Count outcount, MPI_Datatype datatype, MPI_Comm comm)
{
    QMPI_Context context;
    QMPI_Unpack_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Unpack_c(context, 0, inbuf, insize, position, outbuf, outcount, datatype,
                             comm);

    fn_ptr = (QMPI_Unpack_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_UNPACK_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_UNPACK_C_T], inbuf, insize, position,
            outbuf, outcount, datatype, comm);
}
#else /* ENABLE_QMPI */
int MPI_Unpack_c(const void *inbuf, MPI_Count insize, MPI_Count *position, void *outbuf,
                 MPI_Count outcount, MPI_Datatype datatype, MPI_Comm comm)
{
    return internal_Unpack_c(inbuf, insize, position, outbuf, outcount, datatype, comm);
}

#endif /* ENABLE_QMPI */
