/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Ineighbor_alltoallv */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Ineighbor_alltoallv = PMPI_Ineighbor_alltoallv
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Ineighbor_alltoallv  MPI_Ineighbor_alltoallv
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Ineighbor_alltoallv as PMPI_Ineighbor_alltoallv
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Ineighbor_alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[],
                            MPI_Datatype sendtype, void *recvbuf, const int recvcounts[],
                            const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm,
                            MPI_Request *request)
                             __attribute__ ((weak, alias("PMPI_Ineighbor_alltoallv")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Ineighbor_alltoallv
#define MPI_Ineighbor_alltoallv PMPI_Ineighbor_alltoallv
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Ineighbor_alltoallv(const void *sendbuf, const int sendcounts[],
                                        const int sdispls[], MPI_Datatype sendtype, void *recvbuf,
                                        const int recvcounts[], const int rdispls[],
                                        MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
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
            int indegree, outdegree, weighted;
            mpi_errno = MPIR_Topo_canon_nhb_count(comm_ptr, &indegree, &outdegree, &weighted);
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
            for (int i = 0; i < outdegree; i++) {
                MPIR_ERRTEST_COUNT(sendcounts[i], mpi_errno);
                if (sdispls[i] == 0) {
                    MPIR_ERRTEST_USERBUFFER(sendbuf, sendcounts[i], sendtype, mpi_errno);
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
            for (int i = 0; i < indegree; i++) {
                MPIR_ERRTEST_COUNT(recvcounts[i], mpi_errno);
                if (rdispls[i] == 0) {
                    MPIR_ERRTEST_USERBUFFER(recvbuf, recvcounts[i], recvtype, mpi_errno);
                }
            }
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    int indegree, outdegree, weighted;
    mpi_errno = MPIR_Topo_canon_nhb_count(comm_ptr, &indegree, &outdegree, &weighted);
    MPI_Aint *tmp_array = MPL_malloc((outdegree + indegree) * 2 * sizeof(MPI_Aint), MPL_MEM_OTHER);
    for (int i = 0; i < outdegree; i++) {
        tmp_array[i] = sendcounts[i];
    }
    for (int i = 0; i < outdegree; i++) {
        tmp_array[outdegree + i] = sdispls[i];
    }
    for (int i = 0; i < indegree; i++) {
        tmp_array[outdegree * 2 + i] = recvcounts[i];
    }
    for (int i = 0; i < indegree; i++) {
        tmp_array[outdegree * 2 + indegree + i] = rdispls[i];
    }
    MPIR_Request *request_ptr = NULL;
    mpi_errno = MPIR_Ineighbor_alltoallv(sendbuf, tmp_array, tmp_array + outdegree, sendtype, recvbuf,
                                         tmp_array + outdegree * 2,
                                         tmp_array + outdegree * 2 + indegree, recvtype, comm_ptr,
                                         &request_ptr);
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
                                     "**mpi_ineighbor_alltoallv",
                                     "**mpi_ineighbor_alltoallv %p %p %p %D %p %p %p %D %C %p", sendbuf,
                                     sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls,
                                     recvtype, comm, request);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Ineighbor_alltoallv(QMPI_Context context, int tool_id, const void *sendbuf,
                             const int sendcounts[], const int sdispls[], MPI_Datatype sendtype,
                             void *recvbuf, const int recvcounts[], const int rdispls[],
                             MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
    return internal_Ineighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Ineighbor_alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[],
                            MPI_Datatype sendtype, void *recvbuf, const int recvcounts[],
                            const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm,
                            MPI_Request *request)
{
    QMPI_Context context;
    QMPI_Ineighbor_alltoallv_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Ineighbor_alltoallv(context, 0, sendbuf, sendcounts, sdispls, sendtype, recvbuf,
                                        recvcounts, rdispls, recvtype, comm, request);

    fn_ptr = (QMPI_Ineighbor_alltoallv_t *) MPIR_QMPI_first_fn_ptrs[MPI_INEIGHBOR_ALLTOALLV_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_INEIGHBOR_ALLTOALLV_T], sendbuf,
            sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request);
}
#else /* ENABLE_QMPI */
int MPI_Ineighbor_alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[],
                            MPI_Datatype sendtype, void *recvbuf, const int recvcounts[],
                            const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm,
                            MPI_Request *request)
{
    return internal_Ineighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Ineighbor_alltoallv_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Ineighbor_alltoallv_c = PMPI_Ineighbor_alltoallv_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Ineighbor_alltoallv_c  MPI_Ineighbor_alltoallv_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Ineighbor_alltoallv_c as PMPI_Ineighbor_alltoallv_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Ineighbor_alltoallv_c(const void *sendbuf, const MPI_Count sendcounts[],
                              const MPI_Aint sdispls[], MPI_Datatype sendtype, void *recvbuf,
                              const MPI_Count recvcounts[], const MPI_Aint rdispls[],
                              MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
                               __attribute__ ((weak, alias("PMPI_Ineighbor_alltoallv_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Ineighbor_alltoallv_c
#define MPI_Ineighbor_alltoallv_c PMPI_Ineighbor_alltoallv_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Ineighbor_alltoallv_c(const void *sendbuf, const MPI_Count sendcounts[],
                                          const MPI_Aint sdispls[], MPI_Datatype sendtype,
                                          void *recvbuf, const MPI_Count recvcounts[],
                                          const MPI_Aint rdispls[], MPI_Datatype recvtype,
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
            int indegree, outdegree, weighted;
            mpi_errno = MPIR_Topo_canon_nhb_count(comm_ptr, &indegree, &outdegree, &weighted);
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
            for (int i = 0; i < outdegree; i++) {
                MPIR_ERRTEST_COUNT(sendcounts[i], mpi_errno);
                if (sdispls[i] == 0) {
                    MPIR_ERRTEST_USERBUFFER(sendbuf, sendcounts[i], sendtype, mpi_errno);
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
            for (int i = 0; i < indegree; i++) {
                MPIR_ERRTEST_COUNT(recvcounts[i], mpi_errno);
                if (rdispls[i] == 0) {
                    MPIR_ERRTEST_USERBUFFER(recvbuf, recvcounts[i], recvtype, mpi_errno);
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
        mpi_errno = MPIR_Ineighbor_alltoallv(sendbuf, (MPI_Aint *) sendcounts, (MPI_Aint *) sdispls,
                                             sendtype, recvbuf, (MPI_Aint *) recvcounts,
                                             (MPI_Aint *) rdispls, recvtype, comm_ptr, &request_ptr);
        if (mpi_errno) {
            goto fn_fail;
        }
        if (!request_ptr) {
            request_ptr = MPIR_Request_create_complete(MPIR_REQUEST_KIND__COLL);
        }
        *request = request_ptr->handle;
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        int indegree, outdegree, weighted;
        mpi_errno = MPIR_Topo_canon_nhb_count(comm_ptr, &indegree, &outdegree, &weighted);
        MPI_Aint *tmp_array = MPL_malloc((outdegree + indegree) * 2 * sizeof(MPI_Aint), MPL_MEM_OTHER);
        for (int i = 0; i < outdegree; i++) {
            if (sendcounts[i] > MPIR_AINT_MAX) {
                mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                                 __func__, __LINE__, MPI_ERR_OTHER,
                                                 "**too_big_for_input",
                                                 "**too_big_for_input %s", "sendcounts[i]");
                goto fn_fail;
            }
            tmp_array[i] = sendcounts[i];
        }
        for (int i = 0; i < outdegree; i++) {
            if (sdispls[i] > MPIR_AINT_MAX) {
                mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                                 __func__, __LINE__, MPI_ERR_OTHER,
                                                 "**too_big_for_input",
                                                 "**too_big_for_input %s", "sdispls[i]");
                goto fn_fail;
            }
            tmp_array[outdegree + i] = sdispls[i];
        }
        for (int i = 0; i < indegree; i++) {
            if (recvcounts[i] > MPIR_AINT_MAX) {
                mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                                 __func__, __LINE__, MPI_ERR_OTHER,
                                                 "**too_big_for_input",
                                                 "**too_big_for_input %s", "recvcounts[i]");
                goto fn_fail;
            }
            tmp_array[outdegree * 2 + i] = recvcounts[i];
        }
        for (int i = 0; i < indegree; i++) {
            if (rdispls[i] > MPIR_AINT_MAX) {
                mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                                 __func__, __LINE__, MPI_ERR_OTHER,
                                                 "**too_big_for_input",
                                                 "**too_big_for_input %s", "rdispls[i]");
                goto fn_fail;
            }
            tmp_array[outdegree * 2 + indegree + i] = rdispls[i];
        }
        MPIR_Request *request_ptr = NULL;
        mpi_errno = MPIR_Ineighbor_alltoallv(sendbuf, tmp_array, tmp_array + outdegree, sendtype, recvbuf,
                                             tmp_array + outdegree * 2,
                                             tmp_array + outdegree * 2 + indegree, recvtype, comm_ptr,
                                             &request_ptr);
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
                                     "**mpi_ineighbor_alltoallv_c",
                                     "**mpi_ineighbor_alltoallv_c %p %p %p %D %p %p %p %D %C %p",
                                     sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts,
                                     rdispls, recvtype, comm, request);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Ineighbor_alltoallv_c(QMPI_Context context, int tool_id, const void *sendbuf,
                               const MPI_Count sendcounts[], const MPI_Aint sdispls[],
                               MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[],
                               const MPI_Aint rdispls[], MPI_Datatype recvtype, MPI_Comm comm,
                               MPI_Request *request)
{
    return internal_Ineighbor_alltoallv_c(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Ineighbor_alltoallv_c(const void *sendbuf, const MPI_Count sendcounts[],
                              const MPI_Aint sdispls[], MPI_Datatype sendtype, void *recvbuf,
                              const MPI_Count recvcounts[], const MPI_Aint rdispls[],
                              MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
    QMPI_Context context;
    QMPI_Ineighbor_alltoallv_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Ineighbor_alltoallv_c(context, 0, sendbuf, sendcounts, sdispls, sendtype,
                                          recvbuf, recvcounts, rdispls, recvtype, comm, request);

    fn_ptr = (QMPI_Ineighbor_alltoallv_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_INEIGHBOR_ALLTOALLV_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_INEIGHBOR_ALLTOALLV_C_T], sendbuf,
            sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request);
}
#else /* ENABLE_QMPI */
int MPI_Ineighbor_alltoallv_c(const void *sendbuf, const MPI_Count sendcounts[],
                              const MPI_Aint sdispls[], MPI_Datatype sendtype, void *recvbuf,
                              const MPI_Count recvcounts[], const MPI_Aint rdispls[],
                              MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
    return internal_Ineighbor_alltoallv_c(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request);
}

#endif /* ENABLE_QMPI */
