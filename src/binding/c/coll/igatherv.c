/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Igatherv */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Igatherv = PMPI_Igatherv
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Igatherv  MPI_Igatherv
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Igatherv as PMPI_Igatherv
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Igatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf,
                 const int recvcounts[], const int displs[], MPI_Datatype recvtype, int root,
                 MPI_Comm comm, MPI_Request *request)
                  __attribute__ ((weak, alias("PMPI_Igatherv")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Igatherv
#define MPI_Igatherv PMPI_Igatherv
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Igatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                             void *recvbuf, const int recvcounts[], const int displs[],
                             MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request)
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
            if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
                MPIR_ERRTEST_INTRA_ROOT(comm_ptr, root, mpi_errno);
            } else {
                MPIR_ERRTEST_INTER_ROOT(comm_ptr, root, mpi_errno);
            }
            int comm_rank;
            comm_rank = comm_ptr->rank;
#ifdef ENABLE_THREADCOMM
            if (comm_ptr->threadcomm) {
                comm_rank = MPIR_THREADCOMM_TID_TO_RANK(comm_ptr->threadcomm, MPIR_threadcomm_get_tid(comm_ptr->threadcomm));
            }
#endif
            if ((comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM && sendbuf != MPI_IN_PLACE) || (comm_ptr->comm_kind == MPIR_COMM_KIND__INTERCOMM && root != MPI_ROOT && root != MPI_PROC_NULL)) {
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
                if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM && comm_rank == root) {
                    if (sendtype == recvtype && sendcount != 0 && recvcounts[comm_rank] !=0) {
                        MPI_Aint recvtype_size;
                        MPIR_Datatype_get_size_macro(recvtype, recvtype_size);
                        MPIR_ERRTEST_ALIAS_COLL(sendbuf, (char *) recvbuf + displs[comm_rank] * recvtype_size, mpi_errno);
                    }
                }
            }
            int comm_size;
            if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTERCOMM) {
                comm_size = comm_ptr->remote_size;
            } else {
                comm_size = comm_ptr->local_size;
            }
#ifdef ENABLE_THREADCOMM
            if (comm_ptr->threadcomm) {
                comm_size = comm_ptr->threadcomm->rank_offset_table[comm_ptr->local_size - 1];
            }
#endif
            if ((comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM && comm_rank == root) || (comm_ptr->comm_kind == MPIR_COMM_KIND__INTERCOMM && root == MPI_ROOT)) {
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
                for (int i = 0; i < comm_size; i++) {
                    MPIR_ERRTEST_RECVBUF_INPLACE(recvbuf, recvcounts[i], mpi_errno);
                    MPIR_ERRTEST_COUNT(recvcounts[i], mpi_errno);
                    if (displs[i] == 0) {
                        MPIR_ERRTEST_USERBUFFER(recvbuf, recvcounts[i], recvtype, mpi_errno);
                    }
                }
            }
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    int n;
    n = (comm_ptr->comm_kind == MPIR_COMM_KIND__INTERCOMM) ? comm_ptr->remote_size : comm_ptr->local_size;
#ifdef ENABLE_THREADCOMM
    if (comm_ptr->threadcomm) {
        int intracomm_size = comm_ptr->local_size;
        n = comm_ptr->threadcomm->rank_offset_table[intracomm_size - 1];
    }
#endif
    MPI_Aint *tmp_array = MPL_malloc(n * 2 * sizeof(MPI_Aint), MPL_MEM_OTHER);
    int r;
    r = comm_ptr->rank;
#ifdef ENABLE_THREADCOMM
    if (comm_ptr->threadcomm) {
        r = MPIR_THREADCOMM_TID_TO_RANK(comm_ptr->threadcomm, MPIR_threadcomm_get_tid(comm_ptr->threadcomm));
    }
#endif
    if ((comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM && r == root) || (comm_ptr->comm_kind == MPIR_COMM_KIND__INTERCOMM && root == MPI_ROOT)) {
        for (int i = 0; i < n; i++) {
            tmp_array[i] = recvcounts[i];
        }
        for (int i = 0; i < n; i++) {
            tmp_array[n + i] = displs[i];
        }
    }
    MPIR_Request *request_ptr = NULL;
    mpi_errno = MPIR_Igatherv(sendbuf, sendcount, sendtype, recvbuf, tmp_array, tmp_array + n, recvtype,
                              root, comm_ptr, &request_ptr);
    if (mpi_errno) {
        goto fn_fail;
    }
    if (!request_ptr) {
        request_ptr = MPIR_Request_create_complete(MPIR_REQUEST_KIND__COLL);
    }
    *request = request_ptr->handle;
    MPL_free(tmp_array);
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    MPID_THREAD_CS_EXIT(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_igatherv", "**mpi_igatherv %p %d %D %p %p %p %D %i %C %p",
                                     sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs,
                                     recvtype, root, comm, request);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Igatherv(QMPI_Context context, int tool_id, const void *sendbuf, int sendcount,
                  MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[],
                  MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request)
{
    return internal_Igatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Igatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf,
                 const int recvcounts[], const int displs[], MPI_Datatype recvtype, int root,
                 MPI_Comm comm, MPI_Request *request)
{
    QMPI_Context context;
    QMPI_Igatherv_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Igatherv(context, 0, sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs,
                             recvtype, root, comm, request);

    fn_ptr = (QMPI_Igatherv_t *) MPIR_QMPI_first_fn_ptrs[MPI_IGATHERV_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_IGATHERV_T], sendbuf, sendcount,
            sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, request);
}
#else /* ENABLE_QMPI */
int MPI_Igatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf,
                 const int recvcounts[], const int displs[], MPI_Datatype recvtype, int root,
                 MPI_Comm comm, MPI_Request *request)
{
    return internal_Igatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, request);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Igatherv_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Igatherv_c = PMPI_Igatherv_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Igatherv_c  MPI_Igatherv_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Igatherv_c as PMPI_Igatherv_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Igatherv_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf,
                   const MPI_Count recvcounts[], const MPI_Aint displs[], MPI_Datatype recvtype,
                   int root, MPI_Comm comm, MPI_Request *request)
                    __attribute__ ((weak, alias("PMPI_Igatherv_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Igatherv_c
#define MPI_Igatherv_c PMPI_Igatherv_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Igatherv_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype,
                               void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint displs[],
                               MPI_Datatype recvtype, int root, MPI_Comm comm,
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
            if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
                MPIR_ERRTEST_INTRA_ROOT(comm_ptr, root, mpi_errno);
            } else {
                MPIR_ERRTEST_INTER_ROOT(comm_ptr, root, mpi_errno);
            }
            int comm_rank;
            comm_rank = comm_ptr->rank;
#ifdef ENABLE_THREADCOMM
            if (comm_ptr->threadcomm) {
                comm_rank = MPIR_THREADCOMM_TID_TO_RANK(comm_ptr->threadcomm, MPIR_threadcomm_get_tid(comm_ptr->threadcomm));
            }
#endif
            if ((comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM && sendbuf != MPI_IN_PLACE) || (comm_ptr->comm_kind == MPIR_COMM_KIND__INTERCOMM && root != MPI_ROOT && root != MPI_PROC_NULL)) {
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
                if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM && comm_rank == root) {
                    if (sendtype == recvtype && sendcount != 0 && recvcounts[comm_rank] !=0) {
                        MPI_Aint recvtype_size;
                        MPIR_Datatype_get_size_macro(recvtype, recvtype_size);
                        MPIR_ERRTEST_ALIAS_COLL(sendbuf, (char *) recvbuf + displs[comm_rank] * recvtype_size, mpi_errno);
                    }
                }
            }
            int comm_size;
            if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTERCOMM) {
                comm_size = comm_ptr->remote_size;
            } else {
                comm_size = comm_ptr->local_size;
            }
#ifdef ENABLE_THREADCOMM
            if (comm_ptr->threadcomm) {
                comm_size = comm_ptr->threadcomm->rank_offset_table[comm_ptr->local_size - 1];
            }
#endif
            if ((comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM && comm_rank == root) || (comm_ptr->comm_kind == MPIR_COMM_KIND__INTERCOMM && root == MPI_ROOT)) {
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
                for (int i = 0; i < comm_size; i++) {
                    MPIR_ERRTEST_RECVBUF_INPLACE(recvbuf, recvcounts[i], mpi_errno);
                    MPIR_ERRTEST_COUNT(recvcounts[i], mpi_errno);
                    if (displs[i] == 0) {
                        MPIR_ERRTEST_USERBUFFER(recvbuf, recvcounts[i], recvtype, mpi_errno);
                    }
                }
            }
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        MPIR_Request *request_ptr = NULL;
        mpi_errno = MPIR_Igatherv(sendbuf, (MPI_Aint) sendcount, sendtype, recvbuf, (MPI_Aint *) recvcounts,
                                  (MPI_Aint *) displs, recvtype, root, comm_ptr, &request_ptr);
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
        int n;
        n = (comm_ptr->comm_kind == MPIR_COMM_KIND__INTERCOMM) ? comm_ptr->remote_size : comm_ptr->local_size;
#ifdef ENABLE_THREADCOMM
        if (comm_ptr->threadcomm) {
            int intracomm_size = comm_ptr->local_size;
            n = comm_ptr->threadcomm->rank_offset_table[intracomm_size - 1];
        }
#endif
        MPI_Aint *tmp_array = MPL_malloc(n * 2 * sizeof(MPI_Aint), MPL_MEM_OTHER);
        int r;
        r = comm_ptr->rank;
#ifdef ENABLE_THREADCOMM
        if (comm_ptr->threadcomm) {
            r = MPIR_THREADCOMM_TID_TO_RANK(comm_ptr->threadcomm, MPIR_threadcomm_get_tid(comm_ptr->threadcomm));
        }
#endif
        if ((comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM && r == root) || (comm_ptr->comm_kind == MPIR_COMM_KIND__INTERCOMM && root == MPI_ROOT)) {
            for (int i = 0; i < n; i++) {
                if (recvcounts[i] > MPIR_AINT_MAX) {
                    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                                     __func__, __LINE__, MPI_ERR_OTHER,
                                                     "**too_big_for_input",
                                                     "**too_big_for_input %s", "recvcounts[i]");
                    goto fn_fail;
                }
                tmp_array[i] = recvcounts[i];
            }
            for (int i = 0; i < n; i++) {
                if (displs[i] > MPIR_AINT_MAX) {
                    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                                     __func__, __LINE__, MPI_ERR_OTHER,
                                                     "**too_big_for_input",
                                                     "**too_big_for_input %s", "displs[i]");
                    goto fn_fail;
                }
                tmp_array[n + i] = displs[i];
            }
        }
        MPIR_Request *request_ptr = NULL;
        mpi_errno = MPIR_Igatherv(sendbuf, sendcount, sendtype, recvbuf, tmp_array, tmp_array + n, recvtype,
                                  root, comm_ptr, &request_ptr);
        if (mpi_errno) {
            goto fn_fail;
        }
        if (!request_ptr) {
            request_ptr = MPIR_Request_create_complete(MPIR_REQUEST_KIND__COLL);
        }
        *request = request_ptr->handle;
        MPL_free(tmp_array);
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
                                     "**mpi_igatherv_c",
                                     "**mpi_igatherv_c %p %c %D %p %p %p %D %i %C %p", sendbuf,
                                     sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root,
                                     comm, request);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Igatherv_c(QMPI_Context context, int tool_id, const void *sendbuf, MPI_Count sendcount,
                    MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[],
                    const MPI_Aint displs[], MPI_Datatype recvtype, int root, MPI_Comm comm,
                    MPI_Request *request)
{
    return internal_Igatherv_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Igatherv_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf,
                   const MPI_Count recvcounts[], const MPI_Aint displs[], MPI_Datatype recvtype,
                   int root, MPI_Comm comm, MPI_Request *request)
{
    QMPI_Context context;
    QMPI_Igatherv_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Igatherv_c(context, 0, sendbuf, sendcount, sendtype, recvbuf, recvcounts,
                               displs, recvtype, root, comm, request);

    fn_ptr = (QMPI_Igatherv_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_IGATHERV_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_IGATHERV_C_T], sendbuf, sendcount,
            sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, request);
}
#else /* ENABLE_QMPI */
int MPI_Igatherv_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf,
                   const MPI_Count recvcounts[], const MPI_Aint displs[], MPI_Datatype recvtype,
                   int root, MPI_Comm comm, MPI_Request *request)
{
    return internal_Igatherv_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, request);
}

#endif /* ENABLE_QMPI */
