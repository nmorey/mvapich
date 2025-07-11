/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Mrecv */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Mrecv = PMPI_Mrecv
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Mrecv  MPI_Mrecv
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Mrecv as PMPI_Mrecv
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Mrecv(void *buf, int count, MPI_Datatype datatype, MPI_Message *message,
              MPI_Status *status)  __attribute__ ((weak, alias("PMPI_Mrecv")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Mrecv
#define MPI_Mrecv PMPI_Mrecv
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Mrecv(void *buf, int count, MPI_Datatype datatype, MPI_Message *message,
                          MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Request *message_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(message, "message", mpi_errno);
            MPIR_ERRTEST_REQUEST(*message, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_Request_get_ptr(*message, message_ptr);

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            if (*message != MPI_MESSAGE_NO_PROC) {
                MPIR_Request_valid_ptr(message_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
                MPIR_ERR_CHKANDJUMP((message_ptr->kind != MPIR_REQUEST_KIND__MPROBE),
                                    mpi_errno, MPI_ERR_ARG, "**reqnotmsg");
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
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    if (message_ptr == NULL || message_ptr->handle == MPIR_REQUEST_NULL_RECV) {
        /* treat as though MPI_MESSAGE_NO_PROC was passed */
        MPIR_Status_set_procnull(status);
        *message = MPI_MESSAGE_NULL;
        goto fn_exit;
    }

    /* ... body of routine ... */
    MPIR_Request *rreq = NULL;
    mpi_errno = MPID_Mrecv(buf, count, datatype, message_ptr, status, &rreq);
    MPIR_ERR_CHECK(mpi_errno);
    /* rreq == NULL implies message = MPI_MESSAGE_NO_PROC.
     * I.e, status was set and no need to wait on rreq */
    if (rreq != NULL) {
        mpi_errno = MPIR_Wait(rreq, status);
        MPIR_Request_free(rreq);
        MPIR_ERR_CHECK(mpi_errno);
    }

    *message = MPI_MESSAGE_NULL;
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    MPID_THREAD_CS_EXIT(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_mrecv", "**mpi_mrecv %p %d %D %p %p", buf, count, datatype,
                                     message, status);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Mrecv(QMPI_Context context, int tool_id, void *buf, int count, MPI_Datatype datatype,
               MPI_Message *message, MPI_Status *status)
{
    return internal_Mrecv(buf, count, datatype, message, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Mrecv(void *buf, int count, MPI_Datatype datatype, MPI_Message *message,
              MPI_Status *status)
{
    QMPI_Context context;
    QMPI_Mrecv_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Mrecv(context, 0, buf, count, datatype, message, status);

    fn_ptr = (QMPI_Mrecv_t *) MPIR_QMPI_first_fn_ptrs[MPI_MRECV_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_MRECV_T], buf, count, datatype, message,
            status);
}
#else /* ENABLE_QMPI */
int MPI_Mrecv(void *buf, int count, MPI_Datatype datatype, MPI_Message *message,
              MPI_Status *status)
{
    return internal_Mrecv(buf, count, datatype, message, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Mrecv_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Mrecv_c = PMPI_Mrecv_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Mrecv_c  MPI_Mrecv_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Mrecv_c as PMPI_Mrecv_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Mrecv_c(void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Message *message,
                MPI_Status *status)  __attribute__ ((weak, alias("PMPI_Mrecv_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Mrecv_c
#define MPI_Mrecv_c PMPI_Mrecv_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Mrecv_c(void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Message *message,
                            MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Request *message_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(message, "message", mpi_errno);
            MPIR_ERRTEST_REQUEST(*message, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_Request_get_ptr(*message, message_ptr);

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            if (*message != MPI_MESSAGE_NO_PROC) {
                MPIR_Request_valid_ptr(message_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
                MPIR_ERR_CHKANDJUMP((message_ptr->kind != MPIR_REQUEST_KIND__MPROBE),
                                    mpi_errno, MPI_ERR_ARG, "**reqnotmsg");
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
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    if (message_ptr == NULL || message_ptr->handle == MPIR_REQUEST_NULL_RECV) {
        /* treat as though MPI_MESSAGE_NO_PROC was passed */
        MPIR_Status_set_procnull(status);
        *message = MPI_MESSAGE_NULL;
        goto fn_exit;
    }

    /* ... body of routine ... */
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        MPIR_Request *rreq = NULL;
        mpi_errno = MPID_Mrecv(buf, count, datatype, message_ptr, status, &rreq);
        MPIR_ERR_CHECK(mpi_errno);
        /* rreq == NULL implies message = MPI_MESSAGE_NO_PROC.
         * I.e, status was set and no need to wait on rreq */
        if (rreq != NULL) {
            mpi_errno = MPIR_Wait(rreq, status);
            MPIR_Request_free(rreq);
            MPIR_ERR_CHECK(mpi_errno);
        }

        *message = MPI_MESSAGE_NULL;
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        MPIR_Request *rreq = NULL;
        mpi_errno = MPID_Mrecv(buf, count, datatype, message_ptr, status, &rreq);
        MPIR_ERR_CHECK(mpi_errno);
        /* rreq == NULL implies message = MPI_MESSAGE_NO_PROC.
         * I.e, status was set and no need to wait on rreq */
        if (rreq != NULL) {
            mpi_errno = MPIR_Wait(rreq, status);
            MPIR_Request_free(rreq);
            MPIR_ERR_CHECK(mpi_errno);
        }

        *message = MPI_MESSAGE_NULL;
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
                                     "**mpi_mrecv_c", "**mpi_mrecv_c %p %c %D %p %p", buf, count,
                                     datatype, message, status);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Mrecv_c(QMPI_Context context, int tool_id, void *buf, MPI_Count count,
                 MPI_Datatype datatype, MPI_Message *message, MPI_Status *status)
{
    return internal_Mrecv_c(buf, count, datatype, message, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Mrecv_c(void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Message *message,
                MPI_Status *status)
{
    QMPI_Context context;
    QMPI_Mrecv_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Mrecv_c(context, 0, buf, count, datatype, message, status);

    fn_ptr = (QMPI_Mrecv_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_MRECV_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_MRECV_C_T], buf, count, datatype,
            message, status);
}
#else /* ENABLE_QMPI */
int MPI_Mrecv_c(void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Message *message,
                MPI_Status *status)
{
    return internal_Mrecv_c(buf, count, datatype, message, status);
}

#endif /* ENABLE_QMPI */
