/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Reduce_local */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Reduce_local = PMPI_Reduce_local
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Reduce_local  MPI_Reduce_local
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Reduce_local as PMPI_Reduce_local
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Reduce_local(const void *inbuf, void *inoutbuf, int count, MPI_Datatype datatype,
                     MPI_Op op)  __attribute__ ((weak, alias("PMPI_Reduce_local")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Reduce_local
#define MPI_Reduce_local PMPI_Reduce_local
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Reduce_local(const void *inbuf, void *inoutbuf, int count,
                                 MPI_Datatype datatype, MPI_Op op)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_OP(op, mpi_errno);
            if (!HANDLE_IS_BUILTIN(op)) {
                MPIR_Op *op_ptr = NULL;
                MPIR_Op_get_ptr(op, op_ptr);
                MPIR_Op_valid_ptr(op_ptr, mpi_errno);
            } else {
                mpi_errno = (*MPIR_OP_HDL_TO_DTYPE_FN(op)) (datatype);
                if (mpi_errno != MPI_SUCCESS) {
                    MPI_Datatype alt_dt = MPIR_Op_get_alt_datatype(op, datatype);
                    if (alt_dt != MPI_DATATYPE_NULL) {
                        datatype = alt_dt;
                        mpi_errno = MPI_SUCCESS;
                    }
                }
            }
            if (mpi_errno) {
                goto fn_fail;
            }
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
            if (count > 0) {
                MPIR_ERRTEST_ALIAS_COLL(inbuf, inoutbuf, mpi_errno);
            }
            MPIR_ERRTEST_NAMED_BUF_INPLACE(inbuf, "inbuf", count, mpi_errno);
            MPIR_ERRTEST_NAMED_BUF_INPLACE(inoutbuf, "inoutbuf", count, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Reduce_local(inbuf, inoutbuf, count, datatype, op);
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
                                     "**mpi_reduce_local", "**mpi_reduce_local %p %p %d %D %O", inbuf,
                                     inoutbuf, count, datatype, op);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Reduce_local(QMPI_Context context, int tool_id, const void *inbuf, void *inoutbuf,
                      int count, MPI_Datatype datatype, MPI_Op op)
{
    return internal_Reduce_local(inbuf, inoutbuf, count, datatype, op);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Reduce_local(const void *inbuf, void *inoutbuf, int count, MPI_Datatype datatype,
                     MPI_Op op)
{
    QMPI_Context context;
    QMPI_Reduce_local_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Reduce_local(context, 0, inbuf, inoutbuf, count, datatype, op);

    fn_ptr = (QMPI_Reduce_local_t *) MPIR_QMPI_first_fn_ptrs[MPI_REDUCE_LOCAL_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_REDUCE_LOCAL_T], inbuf, inoutbuf, count,
            datatype, op);
}
#else /* ENABLE_QMPI */
int MPI_Reduce_local(const void *inbuf, void *inoutbuf, int count, MPI_Datatype datatype,
                     MPI_Op op)
{
    return internal_Reduce_local(inbuf, inoutbuf, count, datatype, op);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Reduce_local_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Reduce_local_c = PMPI_Reduce_local_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Reduce_local_c  MPI_Reduce_local_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Reduce_local_c as PMPI_Reduce_local_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Reduce_local_c(const void *inbuf, void *inoutbuf, MPI_Count count, MPI_Datatype datatype,
                       MPI_Op op)  __attribute__ ((weak, alias("PMPI_Reduce_local_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Reduce_local_c
#define MPI_Reduce_local_c PMPI_Reduce_local_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Reduce_local_c(const void *inbuf, void *inoutbuf, MPI_Count count,
                                   MPI_Datatype datatype, MPI_Op op)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_OP(op, mpi_errno);
            if (!HANDLE_IS_BUILTIN(op)) {
                MPIR_Op *op_ptr = NULL;
                MPIR_Op_get_ptr(op, op_ptr);
                MPIR_Op_valid_ptr(op_ptr, mpi_errno);
            } else {
                mpi_errno = (*MPIR_OP_HDL_TO_DTYPE_FN(op)) (datatype);
                if (mpi_errno != MPI_SUCCESS) {
                    MPI_Datatype alt_dt = MPIR_Op_get_alt_datatype(op, datatype);
                    if (alt_dt != MPI_DATATYPE_NULL) {
                        datatype = alt_dt;
                        mpi_errno = MPI_SUCCESS;
                    }
                }
            }
            if (mpi_errno) {
                goto fn_fail;
            }
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
            if (count > 0) {
                MPIR_ERRTEST_ALIAS_COLL(inbuf, inoutbuf, mpi_errno);
            }
            MPIR_ERRTEST_NAMED_BUF_INPLACE(inbuf, "inbuf", count, mpi_errno);
            MPIR_ERRTEST_NAMED_BUF_INPLACE(inoutbuf, "inoutbuf", count, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_Reduce_local(inbuf, inoutbuf, count, datatype, op);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_Reduce_local(inbuf, inoutbuf, count, datatype, op);
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
                                     "**mpi_reduce_local_c", "**mpi_reduce_local_c %p %p %c %D %O",
                                     inbuf, inoutbuf, count, datatype, op);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Reduce_local_c(QMPI_Context context, int tool_id, const void *inbuf, void *inoutbuf,
                        MPI_Count count, MPI_Datatype datatype, MPI_Op op)
{
    return internal_Reduce_local_c(inbuf, inoutbuf, count, datatype, op);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Reduce_local_c(const void *inbuf, void *inoutbuf, MPI_Count count, MPI_Datatype datatype,
                       MPI_Op op)
{
    QMPI_Context context;
    QMPI_Reduce_local_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Reduce_local_c(context, 0, inbuf, inoutbuf, count, datatype, op);

    fn_ptr = (QMPI_Reduce_local_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_REDUCE_LOCAL_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_REDUCE_LOCAL_C_T], inbuf, inoutbuf,
            count, datatype, op);
}
#else /* ENABLE_QMPI */
int MPI_Reduce_local_c(const void *inbuf, void *inoutbuf, MPI_Count count, MPI_Datatype datatype,
                       MPI_Op op)
{
    return internal_Reduce_local_c(inbuf, inoutbuf, count, datatype, op);
}

#endif /* ENABLE_QMPI */
