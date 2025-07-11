/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Unpack_external */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Unpack_external = PMPI_Unpack_external
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Unpack_external  MPI_Unpack_external
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Unpack_external as PMPI_Unpack_external
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Unpack_external(const char datarep[], const void *inbuf, MPI_Aint insize,
                        MPI_Aint *position, void *outbuf, int outcount, MPI_Datatype datatype)
                         __attribute__ ((weak, alias("PMPI_Unpack_external")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Unpack_external
#define MPI_Unpack_external PMPI_Unpack_external
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Unpack_external(const char datarep[], const void *inbuf, MPI_Aint insize,
                                    MPI_Aint *position, void *outbuf, int outcount,
                                    MPI_Datatype datatype)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(inbuf, "inbuf", mpi_errno);
            MPIR_ERRTEST_COUNT(insize, mpi_errno);
            MPIR_ERRTEST_ARGNULL(position, "position", mpi_errno);
            MPIR_ERRTEST_ARGNULL(outbuf, "outbuf", mpi_errno);
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
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    if (insize == 0) {
        goto fn_exit;
    }

    /* ... body of routine ... */
    mpi_errno = MPIR_Unpack_external_impl(datarep, inbuf, insize, position, outbuf, outcount,
                                          datatype);
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
                                     "**mpi_unpack_external",
                                     "**mpi_unpack_external %s %p %L %p %p %d %D", datarep, inbuf,
                                     (long long) insize, position, outbuf, outcount, datatype);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Unpack_external(QMPI_Context context, int tool_id, const char datarep[], const void *inbuf,
                         MPI_Aint insize, MPI_Aint *position, void *outbuf, int outcount,
                         MPI_Datatype datatype)
{
    return internal_Unpack_external(datarep, inbuf, insize, position, outbuf, outcount, datatype);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Unpack_external(const char datarep[], const void *inbuf, MPI_Aint insize,
                        MPI_Aint *position, void *outbuf, int outcount, MPI_Datatype datatype)
{
    QMPI_Context context;
    QMPI_Unpack_external_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Unpack_external(context, 0, datarep, inbuf, insize, position, outbuf, outcount,
                                    datatype);

    fn_ptr = (QMPI_Unpack_external_t *) MPIR_QMPI_first_fn_ptrs[MPI_UNPACK_EXTERNAL_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_UNPACK_EXTERNAL_T], datarep, inbuf,
            insize, position, outbuf, outcount, datatype);
}
#else /* ENABLE_QMPI */
int MPI_Unpack_external(const char datarep[], const void *inbuf, MPI_Aint insize,
                        MPI_Aint *position, void *outbuf, int outcount, MPI_Datatype datatype)
{
    return internal_Unpack_external(datarep, inbuf, insize, position, outbuf, outcount, datatype);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Unpack_external_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Unpack_external_c = PMPI_Unpack_external_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Unpack_external_c  MPI_Unpack_external_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Unpack_external_c as PMPI_Unpack_external_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Unpack_external_c(const char datarep[], const void *inbuf, MPI_Count insize,
                          MPI_Count *position, void *outbuf, MPI_Count outcount,
                          MPI_Datatype datatype)
                           __attribute__ ((weak, alias("PMPI_Unpack_external_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Unpack_external_c
#define MPI_Unpack_external_c PMPI_Unpack_external_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Unpack_external_c(const char datarep[], const void *inbuf, MPI_Count insize,
                                      MPI_Count *position, void *outbuf, MPI_Count outcount,
                                      MPI_Datatype datatype)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(inbuf, "inbuf", mpi_errno);
            MPIR_ERRTEST_COUNT(insize, mpi_errno);
            MPIR_ERRTEST_ARGNULL(position, "position", mpi_errno);
            MPIR_ERRTEST_ARGNULL(outbuf, "outbuf", mpi_errno);
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
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    if (insize == 0) {
        goto fn_exit;
    }

    /* ... body of routine ... */
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_Unpack_external_impl(datarep, inbuf, (MPI_Aint) insize, (MPI_Aint *) position,
                                              outbuf, (MPI_Aint) outcount, datatype);
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
        mpi_errno = MPIR_Unpack_external_impl(datarep, inbuf, insize, &position_c, outbuf, outcount,
                                              datatype);
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
                                     "**mpi_unpack_external_c",
                                     "**mpi_unpack_external_c %s %p %c %p %p %c %D", datarep, inbuf,
                                     insize, position, outbuf, outcount, datatype);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Unpack_external_c(QMPI_Context context, int tool_id, const char datarep[],
                           const void *inbuf, MPI_Count insize, MPI_Count *position, void *outbuf,
                           MPI_Count outcount, MPI_Datatype datatype)
{
    return internal_Unpack_external_c(datarep, inbuf, insize, position, outbuf, outcount, datatype);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Unpack_external_c(const char datarep[], const void *inbuf, MPI_Count insize,
                          MPI_Count *position, void *outbuf, MPI_Count outcount,
                          MPI_Datatype datatype)
{
    QMPI_Context context;
    QMPI_Unpack_external_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Unpack_external_c(context, 0, datarep, inbuf, insize, position, outbuf,
                                      outcount, datatype);

    fn_ptr = (QMPI_Unpack_external_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_UNPACK_EXTERNAL_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_UNPACK_EXTERNAL_C_T], datarep, inbuf,
            insize, position, outbuf, outcount, datatype);
}
#else /* ENABLE_QMPI */
int MPI_Unpack_external_c(const char datarep[], const void *inbuf, MPI_Count insize,
                          MPI_Count *position, void *outbuf, MPI_Count outcount,
                          MPI_Datatype datatype)
{
    return internal_Unpack_external_c(datarep, inbuf, insize, position, outbuf, outcount, datatype);
}

#endif /* ENABLE_QMPI */
