/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Iscan */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Iscan = PMPI_Iscan
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Iscan  MPI_Iscan
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Iscan as PMPI_Iscan
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Iscan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op,
              MPI_Comm comm, MPI_Request *request)  __attribute__ ((weak, alias("PMPI_Iscan")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Iscan
#define MPI_Iscan PMPI_Iscan
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Iscan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype,
                          MPI_Op op, MPI_Comm comm, MPI_Request *request)
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
            MPIR_ERRTEST_COMM_INTRA(comm_ptr, mpi_errno);
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
            MPIR_ERRTEST_RECVBUF_INPLACE(recvbuf, count, mpi_errno);
            if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTERCOMM) {
                MPIR_ERRTEST_SENDBUF_INPLACE(sendbuf, count, mpi_errno);
            } else if (sendbuf != MPI_IN_PLACE && count != 0) {
                MPIR_ERRTEST_ALIAS_COLL(sendbuf, recvbuf, mpi_errno);
            }
            MPIR_ERRTEST_USERBUFFER(recvbuf, count, datatype, mpi_errno);
            MPIR_ERRTEST_USERBUFFER(sendbuf, count, datatype, mpi_errno);
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM && count == 0) {
        MPIR_Request *request_ptr = MPIR_Request_create_complete(MPIR_REQUEST_KIND__COLL);
        *request = request_ptr->handle;
        goto fn_exit;
    }

    /* ... body of routine ... */
    MPIR_Request *request_ptr = NULL;
    mpi_errno = MPIR_Iscan(sendbuf, recvbuf, count, datatype, op, comm_ptr, &request_ptr);
    if (mpi_errno) {
        goto fn_fail;
    }
    if (!request_ptr) {
        request_ptr = MPIR_Request_create_complete(MPIR_REQUEST_KIND__COLL);
    }
    *request = request_ptr->handle;
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    MPID_THREAD_CS_EXIT(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_iscan", "**mpi_iscan %p %p %d %D %O %C %p", sendbuf,
                                     recvbuf, count, datatype, op, comm, request);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Iscan(QMPI_Context context, int tool_id, const void *sendbuf, void *recvbuf, int count,
               MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request)
{
    return internal_Iscan(sendbuf, recvbuf, count, datatype, op, comm, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Iscan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op,
              MPI_Comm comm, MPI_Request *request)
{
    QMPI_Context context;
    QMPI_Iscan_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Iscan(context, 0, sendbuf, recvbuf, count, datatype, op, comm, request);

    fn_ptr = (QMPI_Iscan_t *) MPIR_QMPI_first_fn_ptrs[MPI_ISCAN_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_ISCAN_T], sendbuf, recvbuf, count,
            datatype, op, comm, request);
}
#else /* ENABLE_QMPI */
int MPI_Iscan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op,
              MPI_Comm comm, MPI_Request *request)
{
    return internal_Iscan(sendbuf, recvbuf, count, datatype, op, comm, request);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Iscan_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Iscan_c = PMPI_Iscan_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Iscan_c  MPI_Iscan_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Iscan_c as PMPI_Iscan_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Iscan_c(const void *sendbuf, void *recvbuf, MPI_Count count, MPI_Datatype datatype,
                MPI_Op op, MPI_Comm comm, MPI_Request *request)
                 __attribute__ ((weak, alias("PMPI_Iscan_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Iscan_c
#define MPI_Iscan_c PMPI_Iscan_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Iscan_c(const void *sendbuf, void *recvbuf, MPI_Count count,
                            MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request)
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
            MPIR_ERRTEST_COMM_INTRA(comm_ptr, mpi_errno);
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
            MPIR_ERRTEST_RECVBUF_INPLACE(recvbuf, count, mpi_errno);
            if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTERCOMM) {
                MPIR_ERRTEST_SENDBUF_INPLACE(sendbuf, count, mpi_errno);
            } else if (sendbuf != MPI_IN_PLACE && count != 0) {
                MPIR_ERRTEST_ALIAS_COLL(sendbuf, recvbuf, mpi_errno);
            }
            MPIR_ERRTEST_USERBUFFER(recvbuf, count, datatype, mpi_errno);
            MPIR_ERRTEST_USERBUFFER(sendbuf, count, datatype, mpi_errno);
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM && count == 0) {
        MPIR_Request *request_ptr = MPIR_Request_create_complete(MPIR_REQUEST_KIND__COLL);
        *request = request_ptr->handle;
        goto fn_exit;
    }

    /* ... body of routine ... */
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        MPIR_Request *request_ptr = NULL;
        mpi_errno = MPIR_Iscan(sendbuf, recvbuf, (MPI_Aint) count, datatype, op, comm_ptr, &request_ptr);
        if (mpi_errno) {
            goto fn_fail;
        }
        if (!request_ptr) {
            request_ptr = MPIR_Request_create_complete(MPIR_REQUEST_KIND__COLL);
        }
        *request = request_ptr->handle;
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        MPIR_Request *request_ptr = NULL;
        mpi_errno = MPIR_Iscan(sendbuf, recvbuf, count, datatype, op, comm_ptr, &request_ptr);
        if (mpi_errno) {
            goto fn_fail;
        }
        if (!request_ptr) {
            request_ptr = MPIR_Request_create_complete(MPIR_REQUEST_KIND__COLL);
        }
        *request = request_ptr->handle;
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
                                     "**mpi_iscan_c", "**mpi_iscan_c %p %p %c %D %O %C %p", sendbuf,
                                     recvbuf, count, datatype, op, comm, request);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Iscan_c(QMPI_Context context, int tool_id, const void *sendbuf, void *recvbuf,
                 MPI_Count count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                 MPI_Request *request)
{
    return internal_Iscan_c(sendbuf, recvbuf, count, datatype, op, comm, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Iscan_c(const void *sendbuf, void *recvbuf, MPI_Count count, MPI_Datatype datatype,
                MPI_Op op, MPI_Comm comm, MPI_Request *request)
{
    QMPI_Context context;
    QMPI_Iscan_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Iscan_c(context, 0, sendbuf, recvbuf, count, datatype, op, comm, request);

    fn_ptr = (QMPI_Iscan_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_ISCAN_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_ISCAN_C_T], sendbuf, recvbuf, count,
            datatype, op, comm, request);
}
#else /* ENABLE_QMPI */
int MPI_Iscan_c(const void *sendbuf, void *recvbuf, MPI_Count count, MPI_Datatype datatype,
                MPI_Op op, MPI_Comm comm, MPI_Request *request)
{
    return internal_Iscan_c(sendbuf, recvbuf, count, datatype, op, comm, request);
}

#endif /* ENABLE_QMPI */
