/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Recv */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Recv = PMPI_Recv
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Recv  MPI_Recv
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Recv as PMPI_Recv
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Recv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm,
             MPI_Status *status)  __attribute__ ((weak, alias("PMPI_Recv")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Recv
#define MPI_Recv PMPI_Recv
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Recv(void *buf, int count, MPI_Datatype datatype, int source, int tag,
                         MPI_Comm comm, MPI_Status *status)
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
            MPIR_ERRTEST_RECV_RANK(comm_ptr, source, mpi_errno);
            MPIR_ERRTEST_RECV_TAG(tag, mpi_errno);
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* Return immediately for dummy process */
    if (unlikely(source == MPI_PROC_NULL)) {
        MPIR_Status_set_procnull(status);
        goto fn_exit;
    }

    /* ... body of routine ... */
#ifdef ENABLE_THREADCOMM
    if (comm_ptr->threadcomm) {
        mpi_errno = MPIR_Threadcomm_recv_impl(buf, count, datatype, source, tag, comm_ptr, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else
#endif
    {
        MPIR_Request *request_ptr = NULL;

        /* MT: Note that MPID_Recv may release the SINGLE_CS if it
         * decides to block internally.  MPID_Recv in that case will
         * re-aquire the SINGLE_CS before returning */
        mpi_errno = MPID_Recv(buf, count, datatype, source, tag, comm_ptr, 0, status, &request_ptr);
        if (mpi_errno != MPI_SUCCESS)
            goto fn_fail;

        if (request_ptr == NULL) {
            goto fn_exit;
        }

        mpi_errno = MPIR_Wait(request_ptr, status);
        MPIR_Request_free(request_ptr);
        if (mpi_errno != MPI_SUCCESS)
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
                                     "**mpi_recv", "**mpi_recv %p %d %D %i %t %C %p", buf, count,
                                     datatype, source, tag, comm, status);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Recv(QMPI_Context context, int tool_id, void *buf, int count, MPI_Datatype datatype,
              int source, int tag, MPI_Comm comm, MPI_Status *status)
{
    return internal_Recv(buf, count, datatype, source, tag, comm, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Recv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm,
             MPI_Status *status)
{
    QMPI_Context context;
    QMPI_Recv_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Recv(context, 0, buf, count, datatype, source, tag, comm, status);

    fn_ptr = (QMPI_Recv_t *) MPIR_QMPI_first_fn_ptrs[MPI_RECV_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_RECV_T], buf, count, datatype, source,
            tag, comm, status);
}
#else /* ENABLE_QMPI */
int MPI_Recv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm,
             MPI_Status *status)
{
    return internal_Recv(buf, count, datatype, source, tag, comm, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Recv_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Recv_c = PMPI_Recv_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Recv_c  MPI_Recv_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Recv_c as PMPI_Recv_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Recv_c(void *buf, MPI_Count count, MPI_Datatype datatype, int source, int tag,
               MPI_Comm comm, MPI_Status *status)  __attribute__ ((weak, alias("PMPI_Recv_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Recv_c
#define MPI_Recv_c PMPI_Recv_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Recv_c(void *buf, MPI_Count count, MPI_Datatype datatype, int source, int tag,
                           MPI_Comm comm, MPI_Status *status)
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
            MPIR_ERRTEST_RECV_RANK(comm_ptr, source, mpi_errno);
            MPIR_ERRTEST_RECV_TAG(tag, mpi_errno);
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* Return immediately for dummy process */
    if (unlikely(source == MPI_PROC_NULL)) {
        MPIR_Status_set_procnull(status);
        goto fn_exit;
    }

    /* ... body of routine ... */
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
#ifdef ENABLE_THREADCOMM
        if (comm_ptr->threadcomm) {
            mpi_errno = MPIR_Threadcomm_recv_impl(buf, (MPI_Aint) count, datatype, source, tag, comm_ptr,
                                                  status);
            if (mpi_errno) {
                goto fn_fail;
            }
        } else
#endif
        {
            MPIR_Request *request_ptr = NULL;

            /* MT: Note that MPID_Recv may release the SINGLE_CS if it
             * decides to block internally.  MPID_Recv in that case will
             * re-aquire the SINGLE_CS before returning */
            mpi_errno = MPID_Recv(buf, count, datatype, source, tag, comm_ptr, 0, status, &request_ptr);
            if (mpi_errno != MPI_SUCCESS)
                goto fn_fail;

            if (request_ptr == NULL) {
                goto fn_exit;
            }

            mpi_errno = MPIR_Wait(request_ptr, status);
            MPIR_Request_free(request_ptr);
            if (mpi_errno != MPI_SUCCESS)
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
#ifdef ENABLE_THREADCOMM
        if (comm_ptr->threadcomm) {
            mpi_errno = MPIR_Threadcomm_recv_impl(buf, count, datatype, source, tag, comm_ptr, status);
            if (mpi_errno) {
                goto fn_fail;
            }
        } else
#endif
        {
            MPIR_Request *request_ptr = NULL;

            /* MT: Note that MPID_Recv may release the SINGLE_CS if it
             * decides to block internally.  MPID_Recv in that case will
             * re-aquire the SINGLE_CS before returning */
            mpi_errno = MPID_Recv(buf, count, datatype, source, tag, comm_ptr, 0, status, &request_ptr);
            if (mpi_errno != MPI_SUCCESS)
                goto fn_fail;

            if (request_ptr == NULL) {
                goto fn_exit;
            }

            mpi_errno = MPIR_Wait(request_ptr, status);
            MPIR_Request_free(request_ptr);
            if (mpi_errno != MPI_SUCCESS)
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
                                     "**mpi_recv_c", "**mpi_recv_c %p %c %D %i %t %C %p", buf, count,
                                     datatype, source, tag, comm, status);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Recv_c(QMPI_Context context, int tool_id, void *buf, MPI_Count count,
                MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status)
{
    return internal_Recv_c(buf, count, datatype, source, tag, comm, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Recv_c(void *buf, MPI_Count count, MPI_Datatype datatype, int source, int tag,
               MPI_Comm comm, MPI_Status *status)
{
    QMPI_Context context;
    QMPI_Recv_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Recv_c(context, 0, buf, count, datatype, source, tag, comm, status);

    fn_ptr = (QMPI_Recv_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_RECV_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_RECV_C_T], buf, count, datatype, source,
            tag, comm, status);
}
#else /* ENABLE_QMPI */
int MPI_Recv_c(void *buf, MPI_Count count, MPI_Datatype datatype, int source, int tag,
               MPI_Comm comm, MPI_Status *status)
{
    return internal_Recv_c(buf, count, datatype, source, tag, comm, status);
}

#endif /* ENABLE_QMPI */
