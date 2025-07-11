/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Alltoallv */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Alltoallv = PMPI_Alltoallv
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Alltoallv  MPI_Alltoallv
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Alltoallv as PMPI_Alltoallv
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[],
                  MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int rdispls[],
                  MPI_Datatype recvtype, MPI_Comm comm)
                   __attribute__ ((weak, alias("PMPI_Alltoallv")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Alltoallv
#define MPI_Alltoallv PMPI_Alltoallv
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[],
                              MPI_Datatype sendtype, void *recvbuf, const int recvcounts[],
                              const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm)
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
                for (int i = 0; i < comm_size; i++) {
                    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTERCOMM) {
                        MPIR_ERRTEST_SENDBUF_INPLACE(sendbuf, sendcounts[i], mpi_errno);
                    }
                    MPIR_ERRTEST_COUNT(sendcounts[i], mpi_errno);
                    if (sdispls[i] == 0) {
                        MPIR_ERRTEST_USERBUFFER(sendbuf, sendcounts[i], sendtype, mpi_errno);
                    }
                }
                if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
                    if (sendtype == recvtype && sendcounts == recvcounts) {
                        MPIR_ERRTEST_ALIAS_COLL(sendbuf, recvbuf, mpi_errno);
                    }
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
            for (int i = 0; i < comm_size; i++) {
                MPIR_ERRTEST_RECVBUF_INPLACE(recvbuf, recvcounts[i], mpi_errno);
                MPIR_ERRTEST_COUNT(recvcounts[i], mpi_errno);
                if (rdispls[i] == 0) {
                    MPIR_ERRTEST_USERBUFFER(recvbuf, recvcounts[i], recvtype, mpi_errno);
                }
            }
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
#ifdef ENABLE_THREADCOMM
    if (comm_ptr->threadcomm) {
        mpi_errno = MPIR_Threadcomm_alltoallv_impl(sendbuf, tmp_array, tmp_array + n, sendtype, recvbuf,
                                                   tmp_array + n * 2, tmp_array + n * 3, recvtype,
                                                   comm_ptr);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else
#endif
    {
        mpi_errno = MPIR_Alltoallv(sendbuf, tmp_array, tmp_array + n, sendtype, recvbuf, tmp_array + n * 2,
                                   tmp_array + n * 3, recvtype, comm_ptr, MPIR_ERR_NONE);
        if (mpi_errno) {
            goto fn_fail;
        }
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
                                     "**mpi_alltoallv", "**mpi_alltoallv %p %p %p %D %p %p %p %D %C",
                                     sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts,
                                     rdispls, recvtype, comm);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Alltoallv(QMPI_Context context, int tool_id, const void *sendbuf, const int sendcounts[],
                   const int sdispls[], MPI_Datatype sendtype, void *recvbuf,
                   const int recvcounts[], const int rdispls[], MPI_Datatype recvtype,
                   MPI_Comm comm)
{
    return internal_Alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[],
                  MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int rdispls[],
                  MPI_Datatype recvtype, MPI_Comm comm)
{
    QMPI_Context context;
    QMPI_Alltoallv_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Alltoallv(context, 0, sendbuf, sendcounts, sdispls, sendtype, recvbuf,
                              recvcounts, rdispls, recvtype, comm);

    fn_ptr = (QMPI_Alltoallv_t *) MPIR_QMPI_first_fn_ptrs[MPI_ALLTOALLV_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_ALLTOALLV_T], sendbuf, sendcounts,
            sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm);
}
#else /* ENABLE_QMPI */
int MPI_Alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[],
                  MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int rdispls[],
                  MPI_Datatype recvtype, MPI_Comm comm)
{
    return internal_Alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Alltoallv_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Alltoallv_c = PMPI_Alltoallv_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Alltoallv_c  MPI_Alltoallv_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Alltoallv_c as PMPI_Alltoallv_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Alltoallv_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[],
                    MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[],
                    const MPI_Aint rdispls[], MPI_Datatype recvtype, MPI_Comm comm)
                     __attribute__ ((weak, alias("PMPI_Alltoallv_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Alltoallv_c
#define MPI_Alltoallv_c PMPI_Alltoallv_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Alltoallv_c(const void *sendbuf, const MPI_Count sendcounts[],
                                const MPI_Aint sdispls[], MPI_Datatype sendtype, void *recvbuf,
                                const MPI_Count recvcounts[], const MPI_Aint rdispls[],
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
                for (int i = 0; i < comm_size; i++) {
                    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTERCOMM) {
                        MPIR_ERRTEST_SENDBUF_INPLACE(sendbuf, sendcounts[i], mpi_errno);
                    }
                    MPIR_ERRTEST_COUNT(sendcounts[i], mpi_errno);
                    if (sdispls[i] == 0) {
                        MPIR_ERRTEST_USERBUFFER(sendbuf, sendcounts[i], sendtype, mpi_errno);
                    }
                }
                if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
                    if (sendtype == recvtype && sendcounts == recvcounts) {
                        MPIR_ERRTEST_ALIAS_COLL(sendbuf, recvbuf, mpi_errno);
                    }
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
            for (int i = 0; i < comm_size; i++) {
                MPIR_ERRTEST_RECVBUF_INPLACE(recvbuf, recvcounts[i], mpi_errno);
                MPIR_ERRTEST_COUNT(recvcounts[i], mpi_errno);
                if (rdispls[i] == 0) {
                    MPIR_ERRTEST_USERBUFFER(recvbuf, recvcounts[i], recvtype, mpi_errno);
                }
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
#ifdef ENABLE_THREADCOMM
        if (comm_ptr->threadcomm) {
            mpi_errno = MPIR_Threadcomm_alltoallv_impl(sendbuf, (MPI_Aint *) sendcounts, (MPI_Aint *) sdispls,
                                                       sendtype, recvbuf, (MPI_Aint *) recvcounts,
                                                       (MPI_Aint *) rdispls, recvtype, comm_ptr);
            if (mpi_errno) {
                goto fn_fail;
            }
        } else
#endif
        {
            mpi_errno = MPIR_Alltoallv(sendbuf, (MPI_Aint *) sendcounts, (MPI_Aint *) sdispls, sendtype,
                                       recvbuf, (MPI_Aint *) recvcounts, (MPI_Aint *) rdispls, recvtype,
                                       comm_ptr, MPIR_ERR_NONE);
            if (mpi_errno) {
                goto fn_fail;
            }
        }
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
#ifdef ENABLE_THREADCOMM
        if (comm_ptr->threadcomm) {
            mpi_errno = MPIR_Threadcomm_alltoallv_impl(sendbuf, tmp_array, tmp_array + n, sendtype, recvbuf,
                                                       tmp_array + n * 2, tmp_array + n * 3, recvtype,
                                                       comm_ptr);
            if (mpi_errno) {
                goto fn_fail;
            }
        } else
#endif
        {
            mpi_errno = MPIR_Alltoallv(sendbuf, tmp_array, tmp_array + n, sendtype, recvbuf, tmp_array + n * 2,
                                       tmp_array + n * 3, recvtype, comm_ptr, MPIR_ERR_NONE);
            if (mpi_errno) {
                goto fn_fail;
            }
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
                                     "**mpi_alltoallv_c",
                                     "**mpi_alltoallv_c %p %p %p %D %p %p %p %D %C", sendbuf,
                                     sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls,
                                     recvtype, comm);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Alltoallv_c(QMPI_Context context, int tool_id, const void *sendbuf,
                     const MPI_Count sendcounts[], const MPI_Aint sdispls[], MPI_Datatype sendtype,
                     void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint rdispls[],
                     MPI_Datatype recvtype, MPI_Comm comm)
{
    return internal_Alltoallv_c(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Alltoallv_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[],
                    MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[],
                    const MPI_Aint rdispls[], MPI_Datatype recvtype, MPI_Comm comm)
{
    QMPI_Context context;
    QMPI_Alltoallv_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Alltoallv_c(context, 0, sendbuf, sendcounts, sdispls, sendtype, recvbuf,
                                recvcounts, rdispls, recvtype, comm);

    fn_ptr = (QMPI_Alltoallv_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_ALLTOALLV_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_ALLTOALLV_C_T], sendbuf, sendcounts,
            sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm);
}
#else /* ENABLE_QMPI */
int MPI_Alltoallv_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[],
                    MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[],
                    const MPI_Aint rdispls[], MPI_Datatype recvtype, MPI_Comm comm)
{
    return internal_Alltoallv_c(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm);
}

#endif /* ENABLE_QMPI */
