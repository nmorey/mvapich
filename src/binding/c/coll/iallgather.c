/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Iallgather */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Iallgather = PMPI_Iallgather
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Iallgather  MPI_Iallgather
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Iallgather as PMPI_Iallgather
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Iallgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf,
                   int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
                    __attribute__ ((weak, alias("PMPI_Iallgather")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Iallgather
#define MPI_Iallgather PMPI_Iallgather
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Iallgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                               void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm,
                               MPI_Request *request)
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
            if ( sendbuf != MPI_IN_PLACE) {
                MPIR_ERRTEST_DATATYPE(sendtype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(sendtype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(sendtype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTERCOMM) {
                    MPIR_ERRTEST_SENDBUF_INPLACE(sendbuf, sendcount, mpi_errno);
                }
                MPIR_ERRTEST_COUNT(sendcount, mpi_errno);
                MPIR_ERRTEST_USERBUFFER(sendbuf, sendcount, sendtype, mpi_errno);
                if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
                    int comm_rank;
                    comm_rank = comm_ptr->rank;
#ifdef ENABLE_THREADCOMM
                    if (comm_ptr->threadcomm) {
                        comm_rank = MPIR_THREADCOMM_TID_TO_RANK(comm_ptr->threadcomm, MPIR_threadcomm_get_tid(comm_ptr->threadcomm));
                    }
#endif
                    if (sendtype == recvtype && sendcount == recvcount && sendcount != 0) {
                        MPI_Aint recvtype_size;
                        MPIR_Datatype_get_size_macro(recvtype, recvtype_size);
                        MPIR_ERRTEST_ALIAS_COLL(sendbuf, (char *) recvbuf + comm_rank * recvcount * recvtype_size, mpi_errno);
                    }
                }
            }
            MPIR_ERRTEST_DATATYPE(recvtype, "datatype", mpi_errno);
            if (!HANDLE_IS_BUILTIN(recvtype)) {
                MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                MPIR_Datatype_get_ptr(recvtype, datatype_ptr);
                MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
                MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            MPIR_ERRTEST_RECVBUF_INPLACE(recvbuf, recvcount, mpi_errno);
            MPIR_ERRTEST_COUNT(recvcount, mpi_errno);
            MPIR_ERRTEST_USERBUFFER(recvbuf, recvcount, recvtype, mpi_errno);
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        if ((sendcount == 0 && sendbuf != MPI_IN_PLACE) || recvcount == 0) {
            MPIR_Request *request_ptr = MPIR_Request_create_complete(MPIR_REQUEST_KIND__COLL);
            *request = request_ptr->handle;
            goto fn_exit;
        }
    }

    /* ... body of routine ... */
    MPIR_Request *request_ptr = NULL;
    mpi_errno = MPIR_Iallgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm_ptr,
                                &request_ptr);
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
                                     "**mpi_iallgather", "**mpi_iallgather %p %d %D %p %d %D %C %p",
                                     sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm,
                                     request);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Iallgather(QMPI_Context context, int tool_id, const void *sendbuf, int sendcount,
                    MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype,
                    MPI_Comm comm, MPI_Request *request)
{
    return internal_Iallgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Iallgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf,
                   int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
    QMPI_Context context;
    QMPI_Iallgather_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Iallgather(context, 0, sendbuf, sendcount, sendtype, recvbuf, recvcount,
                               recvtype, comm, request);

    fn_ptr = (QMPI_Iallgather_t *) MPIR_QMPI_first_fn_ptrs[MPI_IALLGATHER_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_IALLGATHER_T], sendbuf, sendcount,
            sendtype, recvbuf, recvcount, recvtype, comm, request);
}
#else /* ENABLE_QMPI */
int MPI_Iallgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf,
                   int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
    return internal_Iallgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Iallgather_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Iallgather_c = PMPI_Iallgather_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Iallgather_c  MPI_Iallgather_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Iallgather_c as PMPI_Iallgather_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Iallgather_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf,
                     MPI_Count recvcount, MPI_Datatype recvtype, MPI_Comm comm,
                     MPI_Request *request)  __attribute__ ((weak, alias("PMPI_Iallgather_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Iallgather_c
#define MPI_Iallgather_c PMPI_Iallgather_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Iallgather_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype,
                                 void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype,
                                 MPI_Comm comm, MPI_Request *request)
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
            if ( sendbuf != MPI_IN_PLACE) {
                MPIR_ERRTEST_DATATYPE(sendtype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(sendtype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(sendtype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTERCOMM) {
                    MPIR_ERRTEST_SENDBUF_INPLACE(sendbuf, sendcount, mpi_errno);
                }
                MPIR_ERRTEST_COUNT(sendcount, mpi_errno);
                MPIR_ERRTEST_USERBUFFER(sendbuf, sendcount, sendtype, mpi_errno);
                if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
                    int comm_rank;
                    comm_rank = comm_ptr->rank;
#ifdef ENABLE_THREADCOMM
                    if (comm_ptr->threadcomm) {
                        comm_rank = MPIR_THREADCOMM_TID_TO_RANK(comm_ptr->threadcomm, MPIR_threadcomm_get_tid(comm_ptr->threadcomm));
                    }
#endif
                    if (sendtype == recvtype && sendcount == recvcount && sendcount != 0) {
                        MPI_Aint recvtype_size;
                        MPIR_Datatype_get_size_macro(recvtype, recvtype_size);
                        MPIR_ERRTEST_ALIAS_COLL(sendbuf, (char *) recvbuf + comm_rank * recvcount * recvtype_size, mpi_errno);
                    }
                }
            }
            MPIR_ERRTEST_DATATYPE(recvtype, "datatype", mpi_errno);
            if (!HANDLE_IS_BUILTIN(recvtype)) {
                MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                MPIR_Datatype_get_ptr(recvtype, datatype_ptr);
                MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
                MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            MPIR_ERRTEST_RECVBUF_INPLACE(recvbuf, recvcount, mpi_errno);
            MPIR_ERRTEST_COUNT(recvcount, mpi_errno);
            MPIR_ERRTEST_USERBUFFER(recvbuf, recvcount, recvtype, mpi_errno);
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        if ((sendcount == 0 && sendbuf != MPI_IN_PLACE) || recvcount == 0) {
            MPIR_Request *request_ptr = MPIR_Request_create_complete(MPIR_REQUEST_KIND__COLL);
            *request = request_ptr->handle;
            goto fn_exit;
        }
    }

    /* ... body of routine ... */
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        MPIR_Request *request_ptr = NULL;
        mpi_errno = MPIR_Iallgather(sendbuf, (MPI_Aint) sendcount, sendtype, recvbuf, (MPI_Aint) recvcount,
                                    recvtype, comm_ptr, &request_ptr);
        if (mpi_errno) {
            goto fn_fail;
        }
        if (!request_ptr) {
            request_ptr = MPIR_Request_create_complete(MPIR_REQUEST_KIND__COLL);
        }
        *request = request_ptr->handle;
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (sendcount > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "sendcount");
            goto fn_fail;
        }
        if (recvcount > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "recvcount");
            goto fn_fail;
        }
        MPIR_Request *request_ptr = NULL;
        mpi_errno = MPIR_Iallgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm_ptr,
                                    &request_ptr);
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
                                     "**mpi_iallgather_c", "**mpi_iallgather_c %p %c %D %p %c %D %C %p",
                                     sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm,
                                     request);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Iallgather_c(QMPI_Context context, int tool_id, const void *sendbuf, MPI_Count sendcount,
                      MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount,
                      MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
    return internal_Iallgather_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Iallgather_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf,
                     MPI_Count recvcount, MPI_Datatype recvtype, MPI_Comm comm,
                     MPI_Request *request)
{
    QMPI_Context context;
    QMPI_Iallgather_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Iallgather_c(context, 0, sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                 recvtype, comm, request);

    fn_ptr = (QMPI_Iallgather_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_IALLGATHER_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_IALLGATHER_C_T], sendbuf, sendcount,
            sendtype, recvbuf, recvcount, recvtype, comm, request);
}
#else /* ENABLE_QMPI */
int MPI_Iallgather_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf,
                     MPI_Count recvcount, MPI_Datatype recvtype, MPI_Comm comm,
                     MPI_Request *request)
{
    return internal_Iallgather_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request);
}

#endif /* ENABLE_QMPI */
