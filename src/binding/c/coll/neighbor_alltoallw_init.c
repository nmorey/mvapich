/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Neighbor_alltoallw_init */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Neighbor_alltoallw_init = PMPI_Neighbor_alltoallw_init
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Neighbor_alltoallw_init  MPI_Neighbor_alltoallw_init
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Neighbor_alltoallw_init as PMPI_Neighbor_alltoallw_init
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Neighbor_alltoallw_init(const void *sendbuf, const int sendcounts[],
                                const MPI_Aint sdispls[], const MPI_Datatype sendtypes[],
                                void *recvbuf, const int recvcounts[], const MPI_Aint rdispls[],
                                const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Info info,
                                MPI_Request *request)
                                 __attribute__ ((weak, alias("PMPI_Neighbor_alltoallw_init")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Neighbor_alltoallw_init
#define MPI_Neighbor_alltoallw_init PMPI_Neighbor_alltoallw_init
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Neighbor_alltoallw_init(const void *sendbuf, const int sendcounts[],
                                            const MPI_Aint sdispls[],
                                            const MPI_Datatype sendtypes[], void *recvbuf,
                                            const int recvcounts[], const MPI_Aint rdispls[],
                                            const MPI_Datatype recvtypes[], MPI_Comm comm,
                                            MPI_Info info, MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Comm *comm_ptr ATTRIBUTE((unused)) = NULL;
    MPIR_Info *info_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COMM(comm, mpi_errno);
            MPIR_ERRTEST_INFO_OR_NULL(info, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_Comm_get_ptr(comm, comm_ptr);
    if (info != MPI_INFO_NULL) {
        MPIR_Info_get_ptr(info, info_ptr);
    }

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_Comm_valid_ptr(comm_ptr, mpi_errno, FALSE);
            if (mpi_errno) {
                goto fn_fail;
            }
            if (info != MPI_INFO_NULL) {
                MPIR_Info_valid_ptr(info_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            int indegree, outdegree, weighted;
            mpi_errno = MPIR_Topo_canon_nhb_count(comm_ptr, &indegree, &outdegree, &weighted);
            for (int i = 0; i < outdegree; i++) {
                if (sendcounts[i] > 0) {
                    MPIR_ERRTEST_DATATYPE(sendtypes[i], "datatype", mpi_errno);
                    if (!HANDLE_IS_BUILTIN(sendtypes[i])) {
                        MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                        MPIR_Datatype_get_ptr(sendtypes[i], datatype_ptr);
                        MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                        if (mpi_errno) {
                            goto fn_fail;
                        }
                        MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                        if (mpi_errno) {
                            goto fn_fail;
                        }
                    }
                }
                MPIR_ERRTEST_COUNT(sendcounts[i], mpi_errno);
                if (sdispls[i] == 0) {
                    MPIR_ERRTEST_USERBUFFER(sendbuf, sendcounts[i], sendtypes[i], mpi_errno);
                }
            }
            for (int i = 0; i < indegree; i++) {
                if (recvcounts[i] > 0) {
                    MPIR_ERRTEST_DATATYPE(recvtypes[i], "datatype", mpi_errno);
                    if (!HANDLE_IS_BUILTIN(recvtypes[i])) {
                        MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                        MPIR_Datatype_get_ptr(recvtypes[i], datatype_ptr);
                        MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                        if (mpi_errno) {
                            goto fn_fail;
                        }
                        MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                        if (mpi_errno) {
                            goto fn_fail;
                        }
                    }
                }
                MPIR_ERRTEST_COUNT(recvcounts[i], mpi_errno);
                if (rdispls[i] == 0) {
                    MPIR_ERRTEST_USERBUFFER(recvbuf, recvcounts[i], recvtypes[i], mpi_errno);
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
    MPI_Aint *tmp_array = MPL_malloc((outdegree + indegree) * sizeof(MPI_Aint), MPL_MEM_OTHER);
    for (int i = 0; i < outdegree; i++) {
        tmp_array[i] = sendcounts[i];
    }
    for (int i = 0; i < indegree; i++) {
        tmp_array[outdegree + i] = recvcounts[i];
    }
    MPIR_Request *request_ptr = NULL;
    mpi_errno = MPIR_Neighbor_alltoallw_init(sendbuf, tmp_array, sdispls, sendtypes, recvbuf,
                                             tmp_array + outdegree, rdispls, recvtypes, comm_ptr,
                                             info_ptr, &request_ptr);
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
                                     "**mpi_neighbor_alltoallw_init",
                                     "**mpi_neighbor_alltoallw_init %p %p %p %p %p %p %p %p %C %I %p",
                                     sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts,
                                     rdispls, recvtypes, comm, info, request);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Neighbor_alltoallw_init(QMPI_Context context, int tool_id, const void *sendbuf,
                                 const int sendcounts[], const MPI_Aint sdispls[],
                                 const MPI_Datatype sendtypes[], void *recvbuf,
                                 const int recvcounts[], const MPI_Aint rdispls[],
                                 const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Info info,
                                 MPI_Request *request)
{
    return internal_Neighbor_alltoallw_init(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, info, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Neighbor_alltoallw_init(const void *sendbuf, const int sendcounts[],
                                const MPI_Aint sdispls[], const MPI_Datatype sendtypes[],
                                void *recvbuf, const int recvcounts[], const MPI_Aint rdispls[],
                                const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Info info,
                                MPI_Request *request)
{
    QMPI_Context context;
    QMPI_Neighbor_alltoallw_init_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Neighbor_alltoallw_init(context, 0, sendbuf, sendcounts, sdispls, sendtypes,
                                            recvbuf, recvcounts, rdispls, recvtypes, comm, info,
                                            request);

    fn_ptr = (QMPI_Neighbor_alltoallw_init_t *) MPIR_QMPI_first_fn_ptrs[MPI_NEIGHBOR_ALLTOALLW_INIT_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_NEIGHBOR_ALLTOALLW_INIT_T], sendbuf,
            sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, info,
            request);
}
#else /* ENABLE_QMPI */
int MPI_Neighbor_alltoallw_init(const void *sendbuf, const int sendcounts[],
                                const MPI_Aint sdispls[], const MPI_Datatype sendtypes[],
                                void *recvbuf, const int recvcounts[], const MPI_Aint rdispls[],
                                const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Info info,
                                MPI_Request *request)
{
    return internal_Neighbor_alltoallw_init(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, info, request);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Neighbor_alltoallw_init_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Neighbor_alltoallw_init_c = PMPI_Neighbor_alltoallw_init_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Neighbor_alltoallw_init_c  MPI_Neighbor_alltoallw_init_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Neighbor_alltoallw_init_c as PMPI_Neighbor_alltoallw_init_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Neighbor_alltoallw_init_c(const void *sendbuf, const MPI_Count sendcounts[],
                                  const MPI_Aint sdispls[], const MPI_Datatype sendtypes[],
                                  void *recvbuf, const MPI_Count recvcounts[],
                                  const MPI_Aint rdispls[], const MPI_Datatype recvtypes[],
                                  MPI_Comm comm, MPI_Info info, MPI_Request *request)
                                   __attribute__ ((weak, alias("PMPI_Neighbor_alltoallw_init_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Neighbor_alltoallw_init_c
#define MPI_Neighbor_alltoallw_init_c PMPI_Neighbor_alltoallw_init_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Neighbor_alltoallw_init_c(const void *sendbuf, const MPI_Count sendcounts[],
                                              const MPI_Aint sdispls[],
                                              const MPI_Datatype sendtypes[], void *recvbuf,
                                              const MPI_Count recvcounts[],
                                              const MPI_Aint rdispls[],
                                              const MPI_Datatype recvtypes[], MPI_Comm comm,
                                              MPI_Info info, MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Comm *comm_ptr ATTRIBUTE((unused)) = NULL;
    MPIR_Info *info_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COMM(comm, mpi_errno);
            MPIR_ERRTEST_INFO_OR_NULL(info, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_Comm_get_ptr(comm, comm_ptr);
    if (info != MPI_INFO_NULL) {
        MPIR_Info_get_ptr(info, info_ptr);
    }

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_Comm_valid_ptr(comm_ptr, mpi_errno, FALSE);
            if (mpi_errno) {
                goto fn_fail;
            }
            if (info != MPI_INFO_NULL) {
                MPIR_Info_valid_ptr(info_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            int indegree, outdegree, weighted;
            mpi_errno = MPIR_Topo_canon_nhb_count(comm_ptr, &indegree, &outdegree, &weighted);
            for (int i = 0; i < outdegree; i++) {
                if (sendcounts[i] > 0) {
                    MPIR_ERRTEST_DATATYPE(sendtypes[i], "datatype", mpi_errno);
                    if (!HANDLE_IS_BUILTIN(sendtypes[i])) {
                        MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                        MPIR_Datatype_get_ptr(sendtypes[i], datatype_ptr);
                        MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                        if (mpi_errno) {
                            goto fn_fail;
                        }
                        MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                        if (mpi_errno) {
                            goto fn_fail;
                        }
                    }
                }
                MPIR_ERRTEST_COUNT(sendcounts[i], mpi_errno);
                if (sdispls[i] == 0) {
                    MPIR_ERRTEST_USERBUFFER(sendbuf, sendcounts[i], sendtypes[i], mpi_errno);
                }
            }
            for (int i = 0; i < indegree; i++) {
                if (recvcounts[i] > 0) {
                    MPIR_ERRTEST_DATATYPE(recvtypes[i], "datatype", mpi_errno);
                    if (!HANDLE_IS_BUILTIN(recvtypes[i])) {
                        MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                        MPIR_Datatype_get_ptr(recvtypes[i], datatype_ptr);
                        MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                        if (mpi_errno) {
                            goto fn_fail;
                        }
                        MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                        if (mpi_errno) {
                            goto fn_fail;
                        }
                    }
                }
                MPIR_ERRTEST_COUNT(recvcounts[i], mpi_errno);
                if (rdispls[i] == 0) {
                    MPIR_ERRTEST_USERBUFFER(recvbuf, recvcounts[i], recvtypes[i], mpi_errno);
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
        mpi_errno = MPIR_Neighbor_alltoallw_init(sendbuf, (MPI_Aint *) sendcounts, sdispls, sendtypes,
                                                 recvbuf, (MPI_Aint *) recvcounts, rdispls, recvtypes,
                                                 comm_ptr, info_ptr, &request_ptr);
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
        MPI_Aint *tmp_array = MPL_malloc((outdegree + indegree) * sizeof(MPI_Aint), MPL_MEM_OTHER);
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
        for (int i = 0; i < indegree; i++) {
            if (recvcounts[i] > MPIR_AINT_MAX) {
                mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                                 __func__, __LINE__, MPI_ERR_OTHER,
                                                 "**too_big_for_input",
                                                 "**too_big_for_input %s", "recvcounts[i]");
                goto fn_fail;
            }
            tmp_array[outdegree + i] = recvcounts[i];
        }
        MPIR_Request *request_ptr = NULL;
        mpi_errno = MPIR_Neighbor_alltoallw_init(sendbuf, tmp_array, sdispls, sendtypes, recvbuf,
                                                 tmp_array + outdegree, rdispls, recvtypes, comm_ptr,
                                                 info_ptr, &request_ptr);
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
                                     "**mpi_neighbor_alltoallw_init_c",
                                     "**mpi_neighbor_alltoallw_init_c %p %p %p %p %p %p %p %p %C %I %p",
                                     sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts,
                                     rdispls, recvtypes, comm, info, request);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Neighbor_alltoallw_init_c(QMPI_Context context, int tool_id, const void *sendbuf,
                                   const MPI_Count sendcounts[], const MPI_Aint sdispls[],
                                   const MPI_Datatype sendtypes[], void *recvbuf,
                                   const MPI_Count recvcounts[], const MPI_Aint rdispls[],
                                   const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Info info,
                                   MPI_Request *request)
{
    return internal_Neighbor_alltoallw_init_c(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, info, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Neighbor_alltoallw_init_c(const void *sendbuf, const MPI_Count sendcounts[],
                                  const MPI_Aint sdispls[], const MPI_Datatype sendtypes[],
                                  void *recvbuf, const MPI_Count recvcounts[],
                                  const MPI_Aint rdispls[], const MPI_Datatype recvtypes[],
                                  MPI_Comm comm, MPI_Info info, MPI_Request *request)
{
    QMPI_Context context;
    QMPI_Neighbor_alltoallw_init_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Neighbor_alltoallw_init_c(context, 0, sendbuf, sendcounts, sdispls, sendtypes,
                                              recvbuf, recvcounts, rdispls, recvtypes, comm, info,
                                              request);

    fn_ptr = (QMPI_Neighbor_alltoallw_init_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_NEIGHBOR_ALLTOALLW_INIT_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_NEIGHBOR_ALLTOALLW_INIT_C_T], sendbuf,
            sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, info,
            request);
}
#else /* ENABLE_QMPI */
int MPI_Neighbor_alltoallw_init_c(const void *sendbuf, const MPI_Count sendcounts[],
                                  const MPI_Aint sdispls[], const MPI_Datatype sendtypes[],
                                  void *recvbuf, const MPI_Count recvcounts[],
                                  const MPI_Aint rdispls[], const MPI_Datatype recvtypes[],
                                  MPI_Comm comm, MPI_Info info, MPI_Request *request)
{
    return internal_Neighbor_alltoallw_init_c(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, info, request);
}

#endif /* ENABLE_QMPI */
