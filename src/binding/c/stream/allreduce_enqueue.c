/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPIX_Allreduce_enqueue */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPIX_Allreduce_enqueue = PMPIX_Allreduce_enqueue
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPIX_Allreduce_enqueue  MPIX_Allreduce_enqueue
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPIX_Allreduce_enqueue as PMPIX_Allreduce_enqueue
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPIX_Allreduce_enqueue(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype,
                           MPI_Op op, MPI_Comm comm)
                            __attribute__ ((weak, alias("PMPIX_Allreduce_enqueue")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPIX_Allreduce_enqueue
#define MPIX_Allreduce_enqueue PMPIX_Allreduce_enqueue
#endif /* MPICH_MPI_FROM_PMPI */

static int internalX_Allreduce_enqueue(const void *sendbuf, void *recvbuf, int count,
                                       MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
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
            MPIR_ERRTEST_ARGNULL(sendbuf, "sendbuf", mpi_errno);
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
                MPIR_ERRTEST_USERBUFFER(recvbuf, count, datatype, mpi_errno);
            }
            MPIR_ERRTEST_OP(op, mpi_errno);
            if (!HANDLE_IS_BUILTIN(op)) {
                MPIR_Op *op_ptr = NULL;
                MPIR_Op_get_ptr(op, op_ptr);
                MPIR_Op_valid_ptr(op_ptr, mpi_errno);
            }
            if (mpi_errno) {
                goto fn_fail;
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Allreduce_enqueue_impl(sendbuf, recvbuf, count, datatype, op, comm_ptr);
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
                                     "**mpix_allreduce_enqueue",
                                     "**mpix_allreduce_enqueue %p %p %d %D %O %C", sendbuf, recvbuf,
                                     count, datatype, op, comm);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPIX_Allreduce_enqueue(QMPI_Context context, int tool_id, const void *sendbuf, void *recvbuf,
                            int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
    return internalX_Allreduce_enqueue(sendbuf, recvbuf, count, datatype, op, comm);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPIX_Allreduce_enqueue(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype,
                           MPI_Op op, MPI_Comm comm)
{
    QMPI_Context context;
    QMPIX_Allreduce_enqueue_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPIX_Allreduce_enqueue(context, 0, sendbuf, recvbuf, count, datatype, op, comm);

    fn_ptr = (QMPIX_Allreduce_enqueue_t *) MPIR_QMPI_first_fn_ptrs[MPIX_ALLREDUCE_ENQUEUE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPIX_ALLREDUCE_ENQUEUE_T], sendbuf, recvbuf,
            count, datatype, op, comm);
}
#else /* ENABLE_QMPI */
int MPIX_Allreduce_enqueue(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype,
                           MPI_Op op, MPI_Comm comm)
{
    return internalX_Allreduce_enqueue(sendbuf, recvbuf, count, datatype, op, comm);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPIX_Allreduce_enqueue_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPIX_Allreduce_enqueue_c = PMPIX_Allreduce_enqueue_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPIX_Allreduce_enqueue_c  MPIX_Allreduce_enqueue_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPIX_Allreduce_enqueue_c as PMPIX_Allreduce_enqueue_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPIX_Allreduce_enqueue_c(const void *sendbuf, void *recvbuf, MPI_Count count,
                             MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
                              __attribute__ ((weak, alias("PMPIX_Allreduce_enqueue_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPIX_Allreduce_enqueue_c
#define MPIX_Allreduce_enqueue_c PMPIX_Allreduce_enqueue_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internalX_Allreduce_enqueue_c(const void *sendbuf, void *recvbuf, MPI_Count count,
                                         MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
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
            MPIR_ERRTEST_ARGNULL(sendbuf, "sendbuf", mpi_errno);
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
                MPIR_ERRTEST_USERBUFFER(recvbuf, count, datatype, mpi_errno);
            }
            MPIR_ERRTEST_OP(op, mpi_errno);
            if (!HANDLE_IS_BUILTIN(op)) {
                MPIR_Op *op_ptr = NULL;
                MPIR_Op_get_ptr(op, op_ptr);
                MPIR_Op_valid_ptr(op_ptr, mpi_errno);
            }
            if (mpi_errno) {
                goto fn_fail;
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_Allreduce_enqueue_impl(sendbuf, recvbuf, (MPI_Aint) count, datatype, op,
                                                comm_ptr);
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
        mpi_errno = MPIR_Allreduce_enqueue_impl(sendbuf, recvbuf, count, datatype, op, comm_ptr);
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
                                     "**mpix_allreduce_enqueue_c",
                                     "**mpix_allreduce_enqueue_c %p %p %c %D %O %C", sendbuf, recvbuf,
                                     count, datatype, op, comm);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPIX_Allreduce_enqueue_c(QMPI_Context context, int tool_id, const void *sendbuf, void *recvbuf,
                              MPI_Count count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
    return internalX_Allreduce_enqueue_c(sendbuf, recvbuf, count, datatype, op, comm);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPIX_Allreduce_enqueue_c(const void *sendbuf, void *recvbuf, MPI_Count count,
                             MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
    QMPI_Context context;
    QMPIX_Allreduce_enqueue_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPIX_Allreduce_enqueue_c(context, 0, sendbuf, recvbuf, count, datatype, op, comm);

    fn_ptr = (QMPIX_Allreduce_enqueue_c_t *) MPIR_QMPI_first_fn_ptrs[MPIX_ALLREDUCE_ENQUEUE_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPIX_ALLREDUCE_ENQUEUE_C_T], sendbuf,
            recvbuf, count, datatype, op, comm);
}
#else /* ENABLE_QMPI */
int MPIX_Allreduce_enqueue_c(const void *sendbuf, void *recvbuf, MPI_Count count,
                             MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
    return internalX_Allreduce_enqueue_c(sendbuf, recvbuf, count, datatype, op, comm);
}

#endif /* ENABLE_QMPI */
