/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPIX_Recv_enqueue */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPIX_Recv_enqueue = PMPIX_Recv_enqueue
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPIX_Recv_enqueue  MPIX_Recv_enqueue
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPIX_Recv_enqueue as PMPIX_Recv_enqueue
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPIX_Recv_enqueue(void *buf, int count, MPI_Datatype datatype, int source, int tag,
                      MPI_Comm comm, MPI_Status *status)
                       __attribute__ ((weak, alias("PMPIX_Recv_enqueue")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPIX_Recv_enqueue
#define MPIX_Recv_enqueue PMPIX_Recv_enqueue
#endif /* MPICH_MPI_FROM_PMPI */

static int internalX_Recv_enqueue(void *buf, int count, MPI_Datatype datatype, int source, int tag,
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
            MPIR_ERRTEST_RANK(comm_ptr, source, mpi_errno);
            MPIR_ERRTEST_SEND_TAG(tag, mpi_errno);
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPID_Recv_enqueue(buf, count, datatype, source, tag, comm_ptr, status);
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
                                     "**mpix_recv_enqueue", "**mpix_recv_enqueue %p %d %D %i %t %C %p",
                                     buf, count, datatype, source, tag, comm, status);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPIX_Recv_enqueue(QMPI_Context context, int tool_id, void *buf, int count,
                       MPI_Datatype datatype, int source, int tag, MPI_Comm comm,
                       MPI_Status *status)
{
    return internalX_Recv_enqueue(buf, count, datatype, source, tag, comm, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPIX_Recv_enqueue(void *buf, int count, MPI_Datatype datatype, int source, int tag,
                      MPI_Comm comm, MPI_Status *status)
{
    QMPI_Context context;
    QMPIX_Recv_enqueue_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPIX_Recv_enqueue(context, 0, buf, count, datatype, source, tag, comm, status);

    fn_ptr = (QMPIX_Recv_enqueue_t *) MPIR_QMPI_first_fn_ptrs[MPIX_RECV_ENQUEUE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPIX_RECV_ENQUEUE_T], buf, count, datatype,
            source, tag, comm, status);
}
#else /* ENABLE_QMPI */
int MPIX_Recv_enqueue(void *buf, int count, MPI_Datatype datatype, int source, int tag,
                      MPI_Comm comm, MPI_Status *status)
{
    return internalX_Recv_enqueue(buf, count, datatype, source, tag, comm, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPIX_Recv_enqueue_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPIX_Recv_enqueue_c = PMPIX_Recv_enqueue_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPIX_Recv_enqueue_c  MPIX_Recv_enqueue_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPIX_Recv_enqueue_c as PMPIX_Recv_enqueue_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPIX_Recv_enqueue_c(void *buf, MPI_Count count, MPI_Datatype datatype, int source, int tag,
                        MPI_Comm comm, MPI_Status *status)
                         __attribute__ ((weak, alias("PMPIX_Recv_enqueue_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPIX_Recv_enqueue_c
#define MPIX_Recv_enqueue_c PMPIX_Recv_enqueue_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internalX_Recv_enqueue_c(void *buf, MPI_Count count, MPI_Datatype datatype, int source,
                                    int tag, MPI_Comm comm, MPI_Status *status)
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
            MPIR_ERRTEST_RANK(comm_ptr, source, mpi_errno);
            MPIR_ERRTEST_SEND_TAG(tag, mpi_errno);
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPID_Recv_enqueue(buf, (MPI_Aint) count, datatype, source, tag, comm_ptr, status);
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
        mpi_errno = MPID_Recv_enqueue(buf, count, datatype, source, tag, comm_ptr, status);
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
                                     "**mpix_recv_enqueue_c",
                                     "**mpix_recv_enqueue_c %p %c %D %i %t %C %p", buf, count, datatype,
                                     source, tag, comm, status);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPIX_Recv_enqueue_c(QMPI_Context context, int tool_id, void *buf, MPI_Count count,
                         MPI_Datatype datatype, int source, int tag, MPI_Comm comm,
                         MPI_Status *status)
{
    return internalX_Recv_enqueue_c(buf, count, datatype, source, tag, comm, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPIX_Recv_enqueue_c(void *buf, MPI_Count count, MPI_Datatype datatype, int source, int tag,
                        MPI_Comm comm, MPI_Status *status)
{
    QMPI_Context context;
    QMPIX_Recv_enqueue_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPIX_Recv_enqueue_c(context, 0, buf, count, datatype, source, tag, comm, status);

    fn_ptr = (QMPIX_Recv_enqueue_c_t *) MPIR_QMPI_first_fn_ptrs[MPIX_RECV_ENQUEUE_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPIX_RECV_ENQUEUE_C_T], buf, count,
            datatype, source, tag, comm, status);
}
#else /* ENABLE_QMPI */
int MPIX_Recv_enqueue_c(void *buf, MPI_Count count, MPI_Datatype datatype, int source, int tag,
                        MPI_Comm comm, MPI_Status *status)
{
    return internalX_Recv_enqueue_c(buf, count, datatype, source, tag, comm, status);
}

#endif /* ENABLE_QMPI */
