/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Ssend */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Ssend = PMPI_Ssend
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Ssend  MPI_Ssend
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Ssend as PMPI_Ssend
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Ssend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
     __attribute__ ((weak, alias("PMPI_Ssend")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Ssend
#define MPI_Ssend PMPI_Ssend
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Ssend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag,
                          MPI_Comm comm)
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
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* Return immediately for dummy process */
    if (unlikely(dest == MPI_PROC_NULL)) {
        goto fn_exit;
    }

    /* ... body of routine ... */
    MPIR_Request *request_ptr = NULL;

    mpi_errno = MPID_Ssend(buf, count, datatype, dest, tag, comm_ptr, 0, &request_ptr);
    if (mpi_errno != MPI_SUCCESS)
        goto fn_fail;

    if (request_ptr == NULL) {
        goto fn_exit;
    }

    /* If a request was returned, then we need to block until the request
     * is complete */
    mpi_errno = MPIR_Wait(request_ptr, MPI_STATUS_IGNORE);
    MPIR_Request_free(request_ptr);
    MPIR_ERR_CHECK(mpi_errno);
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    MPID_THREAD_CS_EXIT(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_ssend", "**mpi_ssend %p %d %D %i %t %C", buf, count,
                                     datatype, dest, tag, comm);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Ssend(QMPI_Context context, int tool_id, const void *buf, int count, MPI_Datatype datatype,
               int dest, int tag, MPI_Comm comm)
{
    return internal_Ssend(buf, count, datatype, dest, tag, comm);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Ssend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
    QMPI_Context context;
    QMPI_Ssend_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Ssend(context, 0, buf, count, datatype, dest, tag, comm);

    fn_ptr = (QMPI_Ssend_t *) MPIR_QMPI_first_fn_ptrs[MPI_SSEND_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_SSEND_T], buf, count, datatype, dest,
            tag, comm);
}
#else /* ENABLE_QMPI */
int MPI_Ssend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
    return internal_Ssend(buf, count, datatype, dest, tag, comm);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Ssend_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Ssend_c = PMPI_Ssend_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Ssend_c  MPI_Ssend_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Ssend_c as PMPI_Ssend_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Ssend_c(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag,
                MPI_Comm comm)  __attribute__ ((weak, alias("PMPI_Ssend_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Ssend_c
#define MPI_Ssend_c PMPI_Ssend_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Ssend_c(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest,
                            int tag, MPI_Comm comm)
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
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* Return immediately for dummy process */
    if (unlikely(dest == MPI_PROC_NULL)) {
        goto fn_exit;
    }

    /* ... body of routine ... */
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        MPIR_Request *request_ptr = NULL;

        mpi_errno = MPID_Ssend(buf, count, datatype, dest, tag, comm_ptr, 0, &request_ptr);
        if (mpi_errno != MPI_SUCCESS)
            goto fn_fail;

        if (request_ptr == NULL) {
            goto fn_exit;
        }

        /* If a request was returned, then we need to block until the request
         * is complete */
        mpi_errno = MPIR_Wait(request_ptr, MPI_STATUS_IGNORE);
        MPIR_Request_free(request_ptr);
        MPIR_ERR_CHECK(mpi_errno);
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

        mpi_errno = MPID_Ssend(buf, count, datatype, dest, tag, comm_ptr, 0, &request_ptr);
        if (mpi_errno != MPI_SUCCESS)
            goto fn_fail;

        if (request_ptr == NULL) {
            goto fn_exit;
        }

        /* If a request was returned, then we need to block until the request
         * is complete */
        mpi_errno = MPIR_Wait(request_ptr, MPI_STATUS_IGNORE);
        MPIR_Request_free(request_ptr);
        MPIR_ERR_CHECK(mpi_errno);
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
                                     "**mpi_ssend_c", "**mpi_ssend_c %p %c %D %i %t %C", buf, count,
                                     datatype, dest, tag, comm);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Ssend_c(QMPI_Context context, int tool_id, const void *buf, MPI_Count count,
                 MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
    return internal_Ssend_c(buf, count, datatype, dest, tag, comm);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Ssend_c(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag,
                MPI_Comm comm)
{
    QMPI_Context context;
    QMPI_Ssend_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Ssend_c(context, 0, buf, count, datatype, dest, tag, comm);

    fn_ptr = (QMPI_Ssend_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_SSEND_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_SSEND_C_T], buf, count, datatype, dest,
            tag, comm);
}
#else /* ENABLE_QMPI */
int MPI_Ssend_c(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag,
                MPI_Comm comm)
{
    return internal_Ssend_c(buf, count, datatype, dest, tag, comm);
}

#endif /* ENABLE_QMPI */
