/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Pack_external */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Pack_external = PMPI_Pack_external
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Pack_external  MPI_Pack_external
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Pack_external as PMPI_Pack_external
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Pack_external(const char *datarep, const void *inbuf, int incount, MPI_Datatype datatype,
                      void *outbuf, MPI_Aint outsize, MPI_Aint *position)
                       __attribute__ ((weak, alias("PMPI_Pack_external")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Pack_external
#define MPI_Pack_external PMPI_Pack_external
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Pack_external(const char *datarep, const void *inbuf, int incount,
                                  MPI_Datatype datatype, void *outbuf, MPI_Aint outsize,
                                  MPI_Aint *position)
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
            MPIR_ERRTEST_COUNT(incount, mpi_errno);
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
            MPIR_ERRTEST_ARGNULL(outbuf, "outbuf", mpi_errno);
            MPIR_ERRTEST_COUNT(outsize, mpi_errno);
            MPIR_ERRTEST_ARGNULL(position, "position", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    if (incount == 0) {
        goto fn_exit;
    }

    /* ... body of routine ... */
    mpi_errno = MPIR_Pack_external_impl(datarep, inbuf, incount, datatype, outbuf, outsize, position);
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
                                     "**mpi_pack_external", "**mpi_pack_external %s %p %d %D %p %L %p",
                                     datarep, inbuf, incount, datatype, outbuf, (long long) outsize,
                                     position);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Pack_external(QMPI_Context context, int tool_id, const char *datarep, const void *inbuf,
                       int incount, MPI_Datatype datatype, void *outbuf, MPI_Aint outsize,
                       MPI_Aint *position)
{
    return internal_Pack_external(datarep, inbuf, incount, datatype, outbuf, outsize, position);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Pack_external(const char *datarep, const void *inbuf, int incount, MPI_Datatype datatype,
                      void *outbuf, MPI_Aint outsize, MPI_Aint *position)
{
    QMPI_Context context;
    QMPI_Pack_external_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Pack_external(context, 0, datarep, inbuf, incount, datatype, outbuf, outsize,
                                  position);

    fn_ptr = (QMPI_Pack_external_t *) MPIR_QMPI_first_fn_ptrs[MPI_PACK_EXTERNAL_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_PACK_EXTERNAL_T], datarep, inbuf,
            incount, datatype, outbuf, outsize, position);
}
#else /* ENABLE_QMPI */
int MPI_Pack_external(const char *datarep, const void *inbuf, int incount, MPI_Datatype datatype,
                      void *outbuf, MPI_Aint outsize, MPI_Aint *position)
{
    return internal_Pack_external(datarep, inbuf, incount, datatype, outbuf, outsize, position);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Pack_external_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Pack_external_c = PMPI_Pack_external_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Pack_external_c  MPI_Pack_external_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Pack_external_c as PMPI_Pack_external_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Pack_external_c(const char *datarep, const void *inbuf, MPI_Count incount,
                        MPI_Datatype datatype, void *outbuf, MPI_Count outsize,
                        MPI_Count *position)
                         __attribute__ ((weak, alias("PMPI_Pack_external_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Pack_external_c
#define MPI_Pack_external_c PMPI_Pack_external_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Pack_external_c(const char *datarep, const void *inbuf, MPI_Count incount,
                                    MPI_Datatype datatype, void *outbuf, MPI_Count outsize,
                                    MPI_Count *position)
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
            MPIR_ERRTEST_COUNT(incount, mpi_errno);
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
            MPIR_ERRTEST_ARGNULL(outbuf, "outbuf", mpi_errno);
            MPIR_ERRTEST_COUNT(outsize, mpi_errno);
            MPIR_ERRTEST_ARGNULL(position, "position", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    if (incount == 0) {
        goto fn_exit;
    }

    /* ... body of routine ... */
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_Pack_external_impl(datarep, inbuf, (MPI_Aint) incount, datatype, outbuf,
                                            (MPI_Aint) outsize, (MPI_Aint *) position);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (incount > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "incount");
            goto fn_fail;
        }
        if (outsize > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "outsize");
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
        mpi_errno = MPIR_Pack_external_impl(datarep, inbuf, incount, datatype, outbuf, outsize,
                                            &position_c);
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
                                     "**mpi_pack_external_c",
                                     "**mpi_pack_external_c %s %p %c %D %p %c %p", datarep, inbuf,
                                     incount, datatype, outbuf, outsize, position);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Pack_external_c(QMPI_Context context, int tool_id, const char *datarep, const void *inbuf,
                         MPI_Count incount, MPI_Datatype datatype, void *outbuf, MPI_Count outsize,
                         MPI_Count *position)
{
    return internal_Pack_external_c(datarep, inbuf, incount, datatype, outbuf, outsize, position);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Pack_external_c(const char *datarep, const void *inbuf, MPI_Count incount,
                        MPI_Datatype datatype, void *outbuf, MPI_Count outsize,
                        MPI_Count *position)
{
    QMPI_Context context;
    QMPI_Pack_external_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Pack_external_c(context, 0, datarep, inbuf, incount, datatype, outbuf, outsize,
                                    position);

    fn_ptr = (QMPI_Pack_external_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_PACK_EXTERNAL_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_PACK_EXTERNAL_C_T], datarep, inbuf,
            incount, datatype, outbuf, outsize, position);
}
#else /* ENABLE_QMPI */
int MPI_Pack_external_c(const char *datarep, const void *inbuf, MPI_Count incount,
                        MPI_Datatype datatype, void *outbuf, MPI_Count outsize,
                        MPI_Count *position)
{
    return internal_Pack_external_c(datarep, inbuf, incount, datatype, outbuf, outsize, position);
}

#endif /* ENABLE_QMPI */
