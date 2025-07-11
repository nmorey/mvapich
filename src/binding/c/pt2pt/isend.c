/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Isend */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Isend = PMPI_Isend
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Isend  MPI_Isend
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Isend as PMPI_Isend
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Isend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm,
              MPI_Request *request)  __attribute__ ((weak, alias("PMPI_Isend")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Isend
#define MPI_Isend PMPI_Isend
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Isend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag,
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
            MPIR_ERRTEST_SEND_TAG(tag, mpi_errno);
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* Return immediately for dummy process */
    if (unlikely(dest == MPI_PROC_NULL)) {
        MPIR_Request *lw_req = MPIR_Request_create_complete(MPIR_REQUEST_KIND__SEND);
        MPIR_ERR_CHKANDSTMT(lw_req == NULL, mpi_errno, MPIX_ERR_NOREQ, goto fn_fail,
                            "**nomemreq");
        *request = lw_req->handle;
        goto fn_exit;
    }

    /* ... body of routine ... */
#ifdef ENABLE_THREADCOMM
    if (comm_ptr->threadcomm) {
        MPIR_Request *request_ptr = NULL;
        mpi_errno = MPIR_Threadcomm_isend_impl(buf, count, datatype, dest, tag, comm_ptr, &request_ptr);
        if (mpi_errno) {
            goto fn_fail;
        }
        *request = request_ptr->handle;
    } else
#endif
    {
        MPIR_Request *request_ptr = NULL;

        mpi_errno = MPID_Isend(buf, count, datatype, dest, tag, comm_ptr, 0, &request_ptr);
        if (mpi_errno != MPI_SUCCESS)
            goto fn_fail;

        /* return the handle of the request to the user */
        /* MPIU_OBJ_HANDLE_PUBLISH is unnecessary for isend, lower-level access is
         * responsible for its own consistency, while upper-level field access is
         * controlled by the completion counter */
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
                                     "**mpi_isend", "**mpi_isend %p %d %D %i %t %C %p", buf, count,
                                     datatype, dest, tag, comm, request);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Isend(QMPI_Context context, int tool_id, const void *buf, int count, MPI_Datatype datatype,
               int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
    return internal_Isend(buf, count, datatype, dest, tag, comm, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Isend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm,
              MPI_Request *request)
{
    QMPI_Context context;
    QMPI_Isend_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Isend(context, 0, buf, count, datatype, dest, tag, comm, request);

    fn_ptr = (QMPI_Isend_t *) MPIR_QMPI_first_fn_ptrs[MPI_ISEND_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_ISEND_T], buf, count, datatype, dest,
            tag, comm, request);
}
#else /* ENABLE_QMPI */
int MPI_Isend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm,
              MPI_Request *request)
{
    return internal_Isend(buf, count, datatype, dest, tag, comm, request);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Isend_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Isend_c = PMPI_Isend_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Isend_c  MPI_Isend_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Isend_c as PMPI_Isend_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Isend_c(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag,
                MPI_Comm comm, MPI_Request *request)
                 __attribute__ ((weak, alias("PMPI_Isend_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Isend_c
#define MPI_Isend_c PMPI_Isend_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Isend_c(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest,
                            int tag, MPI_Comm comm, MPI_Request *request)
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
            MPIR_ERRTEST_SEND_TAG(tag, mpi_errno);
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* Return immediately for dummy process */
    if (unlikely(dest == MPI_PROC_NULL)) {
        MPIR_Request *lw_req = MPIR_Request_create_complete(MPIR_REQUEST_KIND__SEND);
        MPIR_ERR_CHKANDSTMT(lw_req == NULL, mpi_errno, MPIX_ERR_NOREQ, goto fn_fail,
                            "**nomemreq");
        *request = lw_req->handle;
        goto fn_exit;
    }

    /* ... body of routine ... */
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
#ifdef ENABLE_THREADCOMM
        if (comm_ptr->threadcomm) {
            MPIR_Request *request_ptr = NULL;
            mpi_errno = MPIR_Threadcomm_isend_impl(buf, (MPI_Aint) count, datatype, dest, tag, comm_ptr,
                                                   &request_ptr);
            if (mpi_errno) {
                goto fn_fail;
            }
            *request = request_ptr->handle;
        } else
#endif
        {
            MPIR_Request *request_ptr = NULL;

            mpi_errno = MPID_Isend(buf, count, datatype, dest, tag, comm_ptr, 0, &request_ptr);
            if (mpi_errno != MPI_SUCCESS)
                goto fn_fail;

            /* return the handle of the request to the user */
            /* MPIU_OBJ_HANDLE_PUBLISH is unnecessary for isend, lower-level access is
             * responsible for its own consistency, while upper-level field access is
             * controlled by the completion counter */
            *request = request_ptr->handle;
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
#ifdef ENABLE_THREADCOMM
        if (comm_ptr->threadcomm) {
            MPIR_Request *request_ptr = NULL;
            mpi_errno = MPIR_Threadcomm_isend_impl(buf, count, datatype, dest, tag, comm_ptr, &request_ptr);
            if (mpi_errno) {
                goto fn_fail;
            }
            *request = request_ptr->handle;
        } else
#endif
        {
            MPIR_Request *request_ptr = NULL;

            mpi_errno = MPID_Isend(buf, count, datatype, dest, tag, comm_ptr, 0, &request_ptr);
            if (mpi_errno != MPI_SUCCESS)
                goto fn_fail;

            /* return the handle of the request to the user */
            /* MPIU_OBJ_HANDLE_PUBLISH is unnecessary for isend, lower-level access is
             * responsible for its own consistency, while upper-level field access is
             * controlled by the completion counter */
            *request = request_ptr->handle;
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
                                     "**mpi_isend_c", "**mpi_isend_c %p %c %D %i %t %C %p", buf, count,
                                     datatype, dest, tag, comm, request);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Isend_c(QMPI_Context context, int tool_id, const void *buf, MPI_Count count,
                 MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
    return internal_Isend_c(buf, count, datatype, dest, tag, comm, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Isend_c(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag,
                MPI_Comm comm, MPI_Request *request)
{
    QMPI_Context context;
    QMPI_Isend_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Isend_c(context, 0, buf, count, datatype, dest, tag, comm, request);

    fn_ptr = (QMPI_Isend_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_ISEND_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_ISEND_C_T], buf, count, datatype, dest,
            tag, comm, request);
}
#else /* ENABLE_QMPI */
int MPI_Isend_c(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag,
                MPI_Comm comm, MPI_Request *request)
{
    return internal_Isend_c(buf, count, datatype, dest, tag, comm, request);
}

#endif /* ENABLE_QMPI */
