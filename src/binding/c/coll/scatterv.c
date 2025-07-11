/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Scatterv */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Scatterv = PMPI_Scatterv
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Scatterv  MPI_Scatterv
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Scatterv as PMPI_Scatterv
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Scatterv(const void *sendbuf, const int sendcounts[], const int displs[],
                 MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype,
                 int root, MPI_Comm comm)  __attribute__ ((weak, alias("PMPI_Scatterv")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Scatterv
#define MPI_Scatterv PMPI_Scatterv
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Scatterv(const void *sendbuf, const int sendcounts[], const int displs[],
                             MPI_Datatype sendtype, void *recvbuf, int recvcount,
                             MPI_Datatype recvtype, int root, MPI_Comm comm)
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
            int comm_rank;
            comm_rank = comm_ptr->rank;
#ifdef ENABLE_THREADCOMM
            if (comm_ptr->threadcomm) {
                comm_rank = MPIR_THREADCOMM_TID_TO_RANK(comm_ptr->threadcomm, MPIR_threadcomm_get_tid(comm_ptr->threadcomm));
            }
#endif
            if ((comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM && comm_rank == root) || (comm_ptr->comm_kind == MPIR_COMM_KIND__INTERCOMM && root == MPI_ROOT)) {
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
                    MPIR_ERRTEST_SENDBUF_INPLACE(sendbuf, sendcounts[i], mpi_errno);
                    MPIR_ERRTEST_COUNT(sendcounts[i], mpi_errno);
                    if (displs[i] == 0) {
                        MPIR_ERRTEST_USERBUFFER(sendbuf, sendcounts[i], sendtype, mpi_errno);
                    }
                }
            }
            if ((comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM && recvbuf != MPI_IN_PLACE) || (comm_ptr->comm_kind == MPIR_COMM_KIND__INTERCOMM && root != MPI_ROOT && root != MPI_PROC_NULL)) {
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
                if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTERCOMM) {
                    MPIR_ERRTEST_RECVBUF_INPLACE(recvbuf, recvcount, mpi_errno);
                }
                MPIR_ERRTEST_COUNT(recvcount, mpi_errno);
                MPIR_ERRTEST_USERBUFFER(recvbuf, recvcount, recvtype, mpi_errno);
                if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM && comm_rank == root) {
                    if (sendtype == recvtype && recvcount != 0 && sendcounts[comm_rank] !=0) {
                        MPI_Aint sendtype_size;
                        MPIR_Datatype_get_size_macro(sendtype, sendtype_size);
                        MPIR_ERRTEST_ALIAS_COLL(recvbuf, (char *) sendbuf + displs[comm_rank] * sendtype_size, mpi_errno);
                    }
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
            tmp_array[i] = sendcounts[i];
        }
        for (int i = 0; i < n; i++) {
            tmp_array[n + i] = displs[i];
        }
    }
#ifdef ENABLE_THREADCOMM
    if (comm_ptr->threadcomm) {
        mpi_errno = MPIR_Threadcomm_scatterv_impl(sendbuf, tmp_array, tmp_array + n, sendtype, recvbuf,
                                                  recvcount, recvtype, root, comm_ptr);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else
#endif
    {
        mpi_errno = MPIR_Scatterv(sendbuf, tmp_array, tmp_array + n, sendtype, recvbuf, recvcount, recvtype,
                                  root, comm_ptr, MPIR_ERR_NONE);
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
                                     "**mpi_scatterv", "**mpi_scatterv %p %p %p %D %p %d %D %i %C",
                                     sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount,
                                     recvtype, root, comm);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Scatterv(QMPI_Context context, int tool_id, const void *sendbuf, const int sendcounts[],
                  const int displs[], MPI_Datatype sendtype, void *recvbuf, int recvcount,
                  MPI_Datatype recvtype, int root, MPI_Comm comm)
{
    return internal_Scatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Scatterv(const void *sendbuf, const int sendcounts[], const int displs[],
                 MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype,
                 int root, MPI_Comm comm)
{
    QMPI_Context context;
    QMPI_Scatterv_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Scatterv(context, 0, sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount,
                             recvtype, root, comm);

    fn_ptr = (QMPI_Scatterv_t *) MPIR_QMPI_first_fn_ptrs[MPI_SCATTERV_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_SCATTERV_T], sendbuf, sendcounts,
            displs, sendtype, recvbuf, recvcount, recvtype, root, comm);
}
#else /* ENABLE_QMPI */
int MPI_Scatterv(const void *sendbuf, const int sendcounts[], const int displs[],
                 MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype,
                 int root, MPI_Comm comm)
{
    return internal_Scatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Scatterv_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Scatterv_c = PMPI_Scatterv_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Scatterv_c  MPI_Scatterv_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Scatterv_c as PMPI_Scatterv_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Scatterv_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint displs[],
                   MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype,
                   int root, MPI_Comm comm)  __attribute__ ((weak, alias("PMPI_Scatterv_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Scatterv_c
#define MPI_Scatterv_c PMPI_Scatterv_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Scatterv_c(const void *sendbuf, const MPI_Count sendcounts[],
                               const MPI_Aint displs[], MPI_Datatype sendtype, void *recvbuf,
                               MPI_Count recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm)
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
            int comm_rank;
            comm_rank = comm_ptr->rank;
#ifdef ENABLE_THREADCOMM
            if (comm_ptr->threadcomm) {
                comm_rank = MPIR_THREADCOMM_TID_TO_RANK(comm_ptr->threadcomm, MPIR_threadcomm_get_tid(comm_ptr->threadcomm));
            }
#endif
            if ((comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM && comm_rank == root) || (comm_ptr->comm_kind == MPIR_COMM_KIND__INTERCOMM && root == MPI_ROOT)) {
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
                    MPIR_ERRTEST_SENDBUF_INPLACE(sendbuf, sendcounts[i], mpi_errno);
                    MPIR_ERRTEST_COUNT(sendcounts[i], mpi_errno);
                    if (displs[i] == 0) {
                        MPIR_ERRTEST_USERBUFFER(sendbuf, sendcounts[i], sendtype, mpi_errno);
                    }
                }
            }
            if ((comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM && recvbuf != MPI_IN_PLACE) || (comm_ptr->comm_kind == MPIR_COMM_KIND__INTERCOMM && root != MPI_ROOT && root != MPI_PROC_NULL)) {
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
                if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTERCOMM) {
                    MPIR_ERRTEST_RECVBUF_INPLACE(recvbuf, recvcount, mpi_errno);
                }
                MPIR_ERRTEST_COUNT(recvcount, mpi_errno);
                MPIR_ERRTEST_USERBUFFER(recvbuf, recvcount, recvtype, mpi_errno);
                if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM && comm_rank == root) {
                    if (sendtype == recvtype && recvcount != 0 && sendcounts[comm_rank] !=0) {
                        MPI_Aint sendtype_size;
                        MPIR_Datatype_get_size_macro(sendtype, sendtype_size);
                        MPIR_ERRTEST_ALIAS_COLL(recvbuf, (char *) sendbuf + displs[comm_rank] * sendtype_size, mpi_errno);
                    }
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
            mpi_errno = MPIR_Threadcomm_scatterv_impl(sendbuf, (MPI_Aint *) sendcounts, (MPI_Aint *) displs,
                                                      sendtype, recvbuf, (MPI_Aint) recvcount, recvtype, root,
                                                      comm_ptr);
            if (mpi_errno) {
                goto fn_fail;
            }
        } else
#endif
        {
            mpi_errno = MPIR_Scatterv(sendbuf, (MPI_Aint *) sendcounts, (MPI_Aint *) displs, sendtype, recvbuf,
                                      (MPI_Aint) recvcount, recvtype, root, comm_ptr, MPIR_ERR_NONE);
            if (mpi_errno) {
                goto fn_fail;
            }
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (recvcount > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "recvcount");
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
#ifdef ENABLE_THREADCOMM
        if (comm_ptr->threadcomm) {
            mpi_errno = MPIR_Threadcomm_scatterv_impl(sendbuf, tmp_array, tmp_array + n, sendtype, recvbuf,
                                                      recvcount, recvtype, root, comm_ptr);
            if (mpi_errno) {
                goto fn_fail;
            }
        } else
#endif
        {
            mpi_errno = MPIR_Scatterv(sendbuf, tmp_array, tmp_array + n, sendtype, recvbuf, recvcount, recvtype,
                                      root, comm_ptr, MPIR_ERR_NONE);
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
                                     "**mpi_scatterv_c", "**mpi_scatterv_c %p %p %p %D %p %c %D %i %C",
                                     sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount,
                                     recvtype, root, comm);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Scatterv_c(QMPI_Context context, int tool_id, const void *sendbuf,
                    const MPI_Count sendcounts[], const MPI_Aint displs[], MPI_Datatype sendtype,
                    void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, int root,
                    MPI_Comm comm)
{
    return internal_Scatterv_c(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Scatterv_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint displs[],
                   MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype,
                   int root, MPI_Comm comm)
{
    QMPI_Context context;
    QMPI_Scatterv_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Scatterv_c(context, 0, sendbuf, sendcounts, displs, sendtype, recvbuf,
                               recvcount, recvtype, root, comm);

    fn_ptr = (QMPI_Scatterv_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_SCATTERV_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_SCATTERV_C_T], sendbuf, sendcounts,
            displs, sendtype, recvbuf, recvcount, recvtype, root, comm);
}
#else /* ENABLE_QMPI */
int MPI_Scatterv_c(const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint displs[],
                   MPI_Datatype sendtype, void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype,
                   int root, MPI_Comm comm)
{
    return internal_Scatterv_c(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm);
}

#endif /* ENABLE_QMPI */
