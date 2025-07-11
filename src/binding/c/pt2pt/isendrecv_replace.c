/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Isendrecv_replace */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Isendrecv_replace = PMPI_Isendrecv_replace
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Isendrecv_replace  MPI_Isendrecv_replace
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Isendrecv_replace as PMPI_Isendrecv_replace
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Isendrecv_replace(void *buf, int count, MPI_Datatype datatype, int dest, int sendtag,
                          int source, int recvtag, MPI_Comm comm, MPI_Request *request)
                           __attribute__ ((weak, alias("PMPI_Isendrecv_replace")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Isendrecv_replace
#define MPI_Isendrecv_replace PMPI_Isendrecv_replace
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Isendrecv_replace(void *buf, int count, MPI_Datatype datatype, int dest,
                                      int sendtag, int source, int recvtag, MPI_Comm comm,
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
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
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
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            MPIR_ERRTEST_SEND_RANK(comm_ptr, dest, mpi_errno);
            MPIR_ERRTEST_SEND_TAG(sendtag, mpi_errno);
            MPIR_ERRTEST_RECV_RANK(comm_ptr, source, mpi_errno);
            MPIR_ERRTEST_RECV_TAG(recvtag, mpi_errno);
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPIR_Request *request_ptr ATTRIBUTE((unused)) = NULL;
    *request = MPI_REQUEST_NULL;
    mpi_errno = MPIR_Isendrecv_replace_impl(buf, count, datatype, dest, sendtag, source, recvtag,
                                            comm_ptr, &request_ptr);
    if (mpi_errno) {
        goto fn_fail;
    }
    if (request_ptr) {
        MPIR_OBJ_PUBLISH_HANDLE(*request, request_ptr->handle);
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
                                     "**mpi_isendrecv_replace",
                                     "**mpi_isendrecv_replace %p %d %D %i %t %i %t %C %p", buf, count,
                                     datatype, dest, sendtag, source, recvtag, comm, request);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Isendrecv_replace(QMPI_Context context, int tool_id, void *buf, int count,
                           MPI_Datatype datatype, int dest, int sendtag, int source, int recvtag,
                           MPI_Comm comm, MPI_Request *request)
{
    return internal_Isendrecv_replace(buf, count, datatype, dest, sendtag, source, recvtag, comm, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Isendrecv_replace(void *buf, int count, MPI_Datatype datatype, int dest, int sendtag,
                          int source, int recvtag, MPI_Comm comm, MPI_Request *request)
{
    QMPI_Context context;
    QMPI_Isendrecv_replace_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Isendrecv_replace(context, 0, buf, count, datatype, dest, sendtag, source,
                                      recvtag, comm, request);

    fn_ptr = (QMPI_Isendrecv_replace_t *) MPIR_QMPI_first_fn_ptrs[MPI_ISENDRECV_REPLACE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_ISENDRECV_REPLACE_T], buf, count,
            datatype, dest, sendtag, source, recvtag, comm, request);
}
#else /* ENABLE_QMPI */
int MPI_Isendrecv_replace(void *buf, int count, MPI_Datatype datatype, int dest, int sendtag,
                          int source, int recvtag, MPI_Comm comm, MPI_Request *request)
{
    return internal_Isendrecv_replace(buf, count, datatype, dest, sendtag, source, recvtag, comm, request);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Isendrecv_replace_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Isendrecv_replace_c = PMPI_Isendrecv_replace_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Isendrecv_replace_c  MPI_Isendrecv_replace_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Isendrecv_replace_c as PMPI_Isendrecv_replace_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Isendrecv_replace_c(void *buf, MPI_Count count, MPI_Datatype datatype, int dest,
                            int sendtag, int source, int recvtag, MPI_Comm comm,
                            MPI_Request *request)
                             __attribute__ ((weak, alias("PMPI_Isendrecv_replace_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Isendrecv_replace_c
#define MPI_Isendrecv_replace_c PMPI_Isendrecv_replace_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Isendrecv_replace_c(void *buf, MPI_Count count, MPI_Datatype datatype, int dest,
                                        int sendtag, int source, int recvtag, MPI_Comm comm,
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
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
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
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            MPIR_ERRTEST_SEND_RANK(comm_ptr, dest, mpi_errno);
            MPIR_ERRTEST_SEND_TAG(sendtag, mpi_errno);
            MPIR_ERRTEST_RECV_RANK(comm_ptr, source, mpi_errno);
            MPIR_ERRTEST_RECV_TAG(recvtag, mpi_errno);
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        MPIR_Request *request_ptr ATTRIBUTE((unused)) = NULL;
        *request = MPI_REQUEST_NULL;
        mpi_errno = MPIR_Isendrecv_replace_impl(buf, (MPI_Aint) count, datatype, dest, sendtag, source,
                                                recvtag, comm_ptr, &request_ptr);
        if (mpi_errno) {
            goto fn_fail;
        }
        if (request_ptr) {
            MPIR_OBJ_PUBLISH_HANDLE(*request, request_ptr->handle);
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
        MPIR_Request *request_ptr ATTRIBUTE((unused)) = NULL;
        *request = MPI_REQUEST_NULL;
        mpi_errno = MPIR_Isendrecv_replace_impl(buf, count, datatype, dest, sendtag, source, recvtag,
                                                comm_ptr, &request_ptr);
        if (mpi_errno) {
            goto fn_fail;
        }
        if (request_ptr) {
            MPIR_OBJ_PUBLISH_HANDLE(*request, request_ptr->handle);
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
                                     "**mpi_isendrecv_replace_c",
                                     "**mpi_isendrecv_replace_c %p %c %D %i %t %i %t %C %p", buf, count,
                                     datatype, dest, sendtag, source, recvtag, comm, request);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Isendrecv_replace_c(QMPI_Context context, int tool_id, void *buf, MPI_Count count,
                             MPI_Datatype datatype, int dest, int sendtag, int source, int recvtag,
                             MPI_Comm comm, MPI_Request *request)
{
    return internal_Isendrecv_replace_c(buf, count, datatype, dest, sendtag, source, recvtag, comm, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Isendrecv_replace_c(void *buf, MPI_Count count, MPI_Datatype datatype, int dest,
                            int sendtag, int source, int recvtag, MPI_Comm comm,
                            MPI_Request *request)
{
    QMPI_Context context;
    QMPI_Isendrecv_replace_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Isendrecv_replace_c(context, 0, buf, count, datatype, dest, sendtag, source,
                                        recvtag, comm, request);

    fn_ptr = (QMPI_Isendrecv_replace_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_ISENDRECV_REPLACE_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_ISENDRECV_REPLACE_C_T], buf, count,
            datatype, dest, sendtag, source, recvtag, comm, request);
}
#else /* ENABLE_QMPI */
int MPI_Isendrecv_replace_c(void *buf, MPI_Count count, MPI_Datatype datatype, int dest,
                            int sendtag, int source, int recvtag, MPI_Comm comm,
                            MPI_Request *request)
{
    return internal_Isendrecv_replace_c(buf, count, datatype, dest, sendtag, source, recvtag, comm, request);
}

#endif /* ENABLE_QMPI */
