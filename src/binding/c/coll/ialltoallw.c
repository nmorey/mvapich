/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Ialltoallw */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Ialltoallw = PMPI_Ialltoallw
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Ialltoallw  MPI_Ialltoallw
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Ialltoallw as PMPI_Ialltoallw
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Ialltoallw(const void *sendbuf, const int sendcounts[], const int sdispls[],
                   const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[],
                   const int rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm,
                   MPI_Request *request)  __attribute__ ((weak, alias("PMPI_Ialltoallw")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Ialltoallw
#define MPI_Ialltoallw PMPI_Ialltoallw
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Ialltoallw(const void *sendbuf, const int sendcounts[], const int sdispls[],
                               const MPI_Datatype sendtypes[], void *recvbuf,
                               const int recvcounts[], const int rdispls[],
                               const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Request *request)
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
            if ( sendbuf != MPI_IN_PLACE) {
                for (int i = 0; i < comm_size; i++) {
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
                    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTERCOMM) {
                        MPIR_ERRTEST_SENDBUF_INPLACE(sendbuf, sendcounts[i], mpi_errno);
                    }
                    MPIR_ERRTEST_COUNT(sendcounts[i], mpi_errno);
                    if (sdispls[i] == 0) {
                        MPIR_ERRTEST_USERBUFFER(sendbuf, sendcounts[i], sendtypes[i], mpi_errno);
                    }
                }
                if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
                    if (sendtypes == recvtypes && sendcounts == recvcounts) {
                        MPIR_ERRTEST_ALIAS_COLL(sendbuf, recvbuf, mpi_errno);
                    }
                }
            }
            for (int i = 0; i < comm_size; i++) {
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
                MPIR_ERRTEST_RECVBUF_INPLACE(recvbuf, recvcounts[i], mpi_errno);
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
    int n;
    n = (comm_ptr->comm_kind == MPIR_COMM_KIND__INTERCOMM) ? comm_ptr->remote_size : comm_ptr->local_size;
#ifdef ENABLE_THREADCOMM
    if (comm_ptr->threadcomm) {
        int intracomm_size = comm_ptr->local_size;
        n = comm_ptr->threadcomm->rank_offset_table[intracomm_size - 1];
    }
#endif
    MPI_Aint *tmp_array = MPL_malloc(n * 4 * sizeof(MPI_Aint), MPL_MEM_OTHER);
    if (sendbuf != MPI_IN_PLACE) {
        for (int i = 0; i < n; i++) {
            tmp_array[i] = sendcounts[i];
        }
        for (int i = 0; i < n; i++) {
            tmp_array[n + i] = sdispls[i];
        }
    }
    for (int i = 0; i < n; i++) {
        tmp_array[n * 2 + i] = recvcounts[i];
    }
    for (int i = 0; i < n; i++) {
        tmp_array[n * 3 + i] = rdispls[i];
    }
    MPIR_Request *request_ptr = NULL;
    mpi_errno = MPIR_Ialltoallw(sendbuf, tmp_array, tmp_array + n, sendtypes, recvbuf,
                                tmp_array + n * 2, tmp_array + n * 3, recvtypes, comm_ptr,
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
                                     "**mpi_ialltoallw",
                                     "**mpi_ialltoallw %p %p %p %p %p %p %p %p %C %p", sendbuf,
                                     sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls,
                                     recvtypes, comm, request);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Ialltoallw(QMPI_Context context, int tool_id, const void *sendbuf, const int sendcounts[],
                    const int sdispls[], const MPI_Datatype sendtypes[], void *recvbuf,
                    const int recvcounts[], const int rdispls[], const MPI_Datatype recvtypes[],
                    MPI_Comm comm, MPI_Request *request)
{
    return internal_Ialltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Ialltoallw(const void *sendbuf, const int sendcounts[], const int sdispls[],
                   const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[],
                   const int rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm,
                   MPI_Request *request)
{
    QMPI_Context context;
    QMPI_Ialltoallw_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Ialltoallw(context, 0, sendbuf, sendcounts, sdispls, sendtypes, recvbuf,
                               recvcounts, rdispls, recvtypes, comm, request);

    fn_ptr = (QMPI_Ialltoallw_t *) MPIR_QMPI_first_fn_ptrs[MPI_IALLTOALLW_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_IALLTOALLW_T], sendbuf, sendcounts,
            sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request);
}
#else /* ENABLE_QMPI */
int MPI_Ialltoallw(const void *sendbuf, const int sendcounts[], const int sdispls[],
                   const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[],
                   const int rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm,
                   MPI_Request *request)
{
    return internal_Ialltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Ialltoallw_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Ialltoallw_c = PMPI_Ialltoallw_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Ialltoallw_c  MPI_Ialltoallw_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Ialltoallw_c as PMPI_Ialltoallw_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Ialltoallw_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[],
                     const MPI_Datatype sendtypes[], void *recvbuf, const MPI_Count recvcounts[],
                     const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm,
                     MPI_Request *request)  __attribute__ ((weak, alias("PMPI_Ialltoallw_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Ialltoallw_c
#define MPI_Ialltoallw_c PMPI_Ialltoallw_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Ialltoallw_c(const void *sendbuf, const MPI_Count sendcounts[],
                                 const MPI_Aint sdispls[], const MPI_Datatype sendtypes[],
                                 void *recvbuf, const MPI_Count recvcounts[],
                                 const MPI_Aint rdispls[], const MPI_Datatype recvtypes[],
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
            if ( sendbuf != MPI_IN_PLACE) {
                for (int i = 0; i < comm_size; i++) {
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
                    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTERCOMM) {
                        MPIR_ERRTEST_SENDBUF_INPLACE(sendbuf, sendcounts[i], mpi_errno);
                    }
                    MPIR_ERRTEST_COUNT(sendcounts[i], mpi_errno);
                    if (sdispls[i] == 0) {
                        MPIR_ERRTEST_USERBUFFER(sendbuf, sendcounts[i], sendtypes[i], mpi_errno);
                    }
                }
                if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
                    if (sendtypes == recvtypes && sendcounts == recvcounts) {
                        MPIR_ERRTEST_ALIAS_COLL(sendbuf, recvbuf, mpi_errno);
                    }
                }
            }
            for (int i = 0; i < comm_size; i++) {
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
                MPIR_ERRTEST_RECVBUF_INPLACE(recvbuf, recvcounts[i], mpi_errno);
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
        mpi_errno = MPIR_Ialltoallw(sendbuf, (MPI_Aint *) sendcounts, (MPI_Aint *) sdispls, sendtypes,
                                    recvbuf, (MPI_Aint *) recvcounts, (MPI_Aint *) rdispls, recvtypes,
                                    comm_ptr, &request_ptr);
        if (mpi_errno) {
            goto fn_fail;
        }
        if (!request_ptr) {
            request_ptr = MPIR_Request_create_complete(MPIR_REQUEST_KIND__COLL);
        }
        *request = request_ptr->handle;
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        int n;
        n = (comm_ptr->comm_kind == MPIR_COMM_KIND__INTERCOMM) ? comm_ptr->remote_size : comm_ptr->local_size;
#ifdef ENABLE_THREADCOMM
        if (comm_ptr->threadcomm) {
            int intracomm_size = comm_ptr->local_size;
            n = comm_ptr->threadcomm->rank_offset_table[intracomm_size - 1];
        }
#endif
        MPI_Aint *tmp_array = MPL_malloc(n * 4 * sizeof(MPI_Aint), MPL_MEM_OTHER);
        if (sendbuf != MPI_IN_PLACE) {
            for (int i = 0; i < n; i++) {
                if (sendcounts[i] > MPIR_AINT_MAX) {
                    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                                     __func__, __LINE__, MPI_ERR_OTHER,
                                                     "**too_big_for_input",
                                                     "**too_big_for_input %s", "sendcounts[i]");
                    goto fn_fail;
                }
                tmp_array[i] = sendcounts[i];
            }
            for (int i = 0; i < n; i++) {
                if (sdispls[i] > MPIR_AINT_MAX) {
                    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                                     __func__, __LINE__, MPI_ERR_OTHER,
                                                     "**too_big_for_input",
                                                     "**too_big_for_input %s", "sdispls[i]");
                    goto fn_fail;
                }
                tmp_array[n + i] = sdispls[i];
            }
        }
        for (int i = 0; i < n; i++) {
            if (recvcounts[i] > MPIR_AINT_MAX) {
                mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                                 __func__, __LINE__, MPI_ERR_OTHER,
                                                 "**too_big_for_input",
                                                 "**too_big_for_input %s", "recvcounts[i]");
                goto fn_fail;
            }
            tmp_array[n * 2 + i] = recvcounts[i];
        }
        for (int i = 0; i < n; i++) {
            if (rdispls[i] > MPIR_AINT_MAX) {
                mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                                 __func__, __LINE__, MPI_ERR_OTHER,
                                                 "**too_big_for_input",
                                                 "**too_big_for_input %s", "rdispls[i]");
                goto fn_fail;
            }
            tmp_array[n * 3 + i] = rdispls[i];
        }
        MPIR_Request *request_ptr = NULL;
        mpi_errno = MPIR_Ialltoallw(sendbuf, tmp_array, tmp_array + n, sendtypes, recvbuf,
                                    tmp_array + n * 2, tmp_array + n * 3, recvtypes, comm_ptr,
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
                                     "**mpi_ialltoallw_c",
                                     "**mpi_ialltoallw_c %p %p %p %p %p %p %p %p %C %p", sendbuf,
                                     sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls,
                                     recvtypes, comm, request);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Ialltoallw_c(QMPI_Context context, int tool_id, const void *sendbuf,
                      const MPI_Count sendcounts[], const MPI_Aint sdispls[],
                      const MPI_Datatype sendtypes[], void *recvbuf, const MPI_Count recvcounts[],
                      const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm,
                      MPI_Request *request)
{
    return internal_Ialltoallw_c(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Ialltoallw_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[],
                     const MPI_Datatype sendtypes[], void *recvbuf, const MPI_Count recvcounts[],
                     const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm,
                     MPI_Request *request)
{
    QMPI_Context context;
    QMPI_Ialltoallw_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Ialltoallw_c(context, 0, sendbuf, sendcounts, sdispls, sendtypes, recvbuf,
                                 recvcounts, rdispls, recvtypes, comm, request);

    fn_ptr = (QMPI_Ialltoallw_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_IALLTOALLW_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_IALLTOALLW_C_T], sendbuf, sendcounts,
            sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request);
}
#else /* ENABLE_QMPI */
int MPI_Ialltoallw_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[],
                     const MPI_Datatype sendtypes[], void *recvbuf, const MPI_Count recvcounts[],
                     const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm,
                     MPI_Request *request)
{
    return internal_Ialltoallw_c(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request);
}

#endif /* ENABLE_QMPI */
