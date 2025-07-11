/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Neighbor_allgatherv */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Neighbor_allgatherv = PMPI_Neighbor_allgatherv
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Neighbor_allgatherv  MPI_Neighbor_allgatherv
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Neighbor_allgatherv as PMPI_Neighbor_allgatherv
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Neighbor_allgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                            void *recvbuf, const int recvcounts[], const int displs[],
                            MPI_Datatype recvtype, MPI_Comm comm)
                             __attribute__ ((weak, alias("PMPI_Neighbor_allgatherv")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Neighbor_allgatherv
#define MPI_Neighbor_allgatherv PMPI_Neighbor_allgatherv
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Neighbor_allgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                                        void *recvbuf, const int recvcounts[], const int displs[],
                                        MPI_Datatype recvtype, MPI_Comm comm)
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
            MPIR_ERRTEST_COUNT(sendcount, mpi_errno);
            if (sendcount > 0) {
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
                MPIR_ERRTEST_USERBUFFER(sendbuf, sendcount, sendtype, mpi_errno);
            }
            int indegree, outdegree, weighted;
            mpi_errno = MPIR_Topo_canon_nhb_count(comm_ptr, &indegree, &outdegree, &weighted);
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
                if (displs[i] == 0) {
                    MPIR_ERRTEST_USERBUFFER(recvbuf, recvcounts[i], recvtype, mpi_errno);
                }
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    int indegree, outdegree, weighted;
    mpi_errno = MPIR_Topo_canon_nhb_count(comm_ptr, &indegree, &outdegree, &weighted);
    MPI_Aint *tmp_array = MPL_malloc(indegree * 2 * sizeof(MPI_Aint), MPL_MEM_OTHER);
    for (int i = 0; i < indegree; i++) {
        tmp_array[i] = recvcounts[i];
    }
    for (int i = 0; i < indegree; i++) {
        tmp_array[indegree + i] = displs[i];
    }
    mpi_errno = MPIR_Neighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf, tmp_array,
                                         tmp_array + indegree, recvtype, comm_ptr);
    if (mpi_errno) {
        goto fn_fail;
    }
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
                                     "**mpi_neighbor_allgatherv",
                                     "**mpi_neighbor_allgatherv %p %d %D %p %p %p %D %C", sendbuf,
                                     sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Neighbor_allgatherv(QMPI_Context context, int tool_id, const void *sendbuf, int sendcount,
                             MPI_Datatype sendtype, void *recvbuf, const int recvcounts[],
                             const int displs[], MPI_Datatype recvtype, MPI_Comm comm)
{
    return internal_Neighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Neighbor_allgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                            void *recvbuf, const int recvcounts[], const int displs[],
                            MPI_Datatype recvtype, MPI_Comm comm)
{
    QMPI_Context context;
    QMPI_Neighbor_allgatherv_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Neighbor_allgatherv(context, 0, sendbuf, sendcount, sendtype, recvbuf,
                                        recvcounts, displs, recvtype, comm);

    fn_ptr = (QMPI_Neighbor_allgatherv_t *) MPIR_QMPI_first_fn_ptrs[MPI_NEIGHBOR_ALLGATHERV_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_NEIGHBOR_ALLGATHERV_T], sendbuf,
            sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm);
}
#else /* ENABLE_QMPI */
int MPI_Neighbor_allgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                            void *recvbuf, const int recvcounts[], const int displs[],
                            MPI_Datatype recvtype, MPI_Comm comm)
{
    return internal_Neighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Neighbor_allgatherv_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Neighbor_allgatherv_c = PMPI_Neighbor_allgatherv_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Neighbor_allgatherv_c  MPI_Neighbor_allgatherv_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Neighbor_allgatherv_c as PMPI_Neighbor_allgatherv_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Neighbor_allgatherv_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype,
                              void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint displs[],
                              MPI_Datatype recvtype, MPI_Comm comm)
                               __attribute__ ((weak, alias("PMPI_Neighbor_allgatherv_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Neighbor_allgatherv_c
#define MPI_Neighbor_allgatherv_c PMPI_Neighbor_allgatherv_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Neighbor_allgatherv_c(const void *sendbuf, MPI_Count sendcount,
                                          MPI_Datatype sendtype, void *recvbuf,
                                          const MPI_Count recvcounts[], const MPI_Aint displs[],
                                          MPI_Datatype recvtype, MPI_Comm comm)
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
            MPIR_ERRTEST_COUNT(sendcount, mpi_errno);
            if (sendcount > 0) {
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
                MPIR_ERRTEST_USERBUFFER(sendbuf, sendcount, sendtype, mpi_errno);
            }
            int indegree, outdegree, weighted;
            mpi_errno = MPIR_Topo_canon_nhb_count(comm_ptr, &indegree, &outdegree, &weighted);
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
                if (displs[i] == 0) {
                    MPIR_ERRTEST_USERBUFFER(recvbuf, recvcounts[i], recvtype, mpi_errno);
                }
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_Neighbor_allgatherv(sendbuf, (MPI_Aint) sendcount, sendtype, recvbuf,
                                             (MPI_Aint *) recvcounts, (MPI_Aint *) displs, recvtype,
                                             comm_ptr);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (sendcount > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "sendcount");
            goto fn_fail;
        }
        int indegree, outdegree, weighted;
        mpi_errno = MPIR_Topo_canon_nhb_count(comm_ptr, &indegree, &outdegree, &weighted);
        MPI_Aint *tmp_array = MPL_malloc(indegree * 2 * sizeof(MPI_Aint), MPL_MEM_OTHER);
        for (int i = 0; i < indegree; i++) {
            if (recvcounts[i] > MPIR_AINT_MAX) {
                mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                                 __func__, __LINE__, MPI_ERR_OTHER,
                                                 "**too_big_for_input",
                                                 "**too_big_for_input %s", "recvcounts[i]");
                goto fn_fail;
            }
            tmp_array[i] = recvcounts[i];
        }
        for (int i = 0; i < indegree; i++) {
            if (displs[i] > MPIR_AINT_MAX) {
                mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                                 __func__, __LINE__, MPI_ERR_OTHER,
                                                 "**too_big_for_input",
                                                 "**too_big_for_input %s", "displs[i]");
                goto fn_fail;
            }
            tmp_array[indegree + i] = displs[i];
        }
        mpi_errno = MPIR_Neighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf, tmp_array,
                                             tmp_array + indegree, recvtype, comm_ptr);
        if (mpi_errno) {
            goto fn_fail;
        }
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
                                     "**mpi_neighbor_allgatherv_c",
                                     "**mpi_neighbor_allgatherv_c %p %c %D %p %p %p %D %C", sendbuf,
                                     sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Neighbor_allgatherv_c(QMPI_Context context, int tool_id, const void *sendbuf,
                               MPI_Count sendcount, MPI_Datatype sendtype, void *recvbuf,
                               const MPI_Count recvcounts[], const MPI_Aint displs[],
                               MPI_Datatype recvtype, MPI_Comm comm)
{
    return internal_Neighbor_allgatherv_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Neighbor_allgatherv_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype,
                              void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint displs[],
                              MPI_Datatype recvtype, MPI_Comm comm)
{
    QMPI_Context context;
    QMPI_Neighbor_allgatherv_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Neighbor_allgatherv_c(context, 0, sendbuf, sendcount, sendtype, recvbuf,
                                          recvcounts, displs, recvtype, comm);

    fn_ptr = (QMPI_Neighbor_allgatherv_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_NEIGHBOR_ALLGATHERV_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_NEIGHBOR_ALLGATHERV_C_T], sendbuf,
            sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm);
}
#else /* ENABLE_QMPI */
int MPI_Neighbor_allgatherv_c(const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype,
                              void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint displs[],
                              MPI_Datatype recvtype, MPI_Comm comm)
{
    return internal_Neighbor_allgatherv_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm);
}

#endif /* ENABLE_QMPI */
