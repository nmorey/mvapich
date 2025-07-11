/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Reduce_scatter_init */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Reduce_scatter_init = PMPI_Reduce_scatter_init
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Reduce_scatter_init  MPI_Reduce_scatter_init
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Reduce_scatter_init as PMPI_Reduce_scatter_init
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Reduce_scatter_init(const void *sendbuf, void *recvbuf, const int recvcounts[],
                            MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Info info,
                            MPI_Request *request)
                             __attribute__ ((weak, alias("PMPI_Reduce_scatter_init")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Reduce_scatter_init
#define MPI_Reduce_scatter_init PMPI_Reduce_scatter_init
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Reduce_scatter_init(const void *sendbuf, void *recvbuf, const int recvcounts[],
                                        MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
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
            MPIR_ERRTEST_OP(op, mpi_errno);
            if (!HANDLE_IS_BUILTIN(op)) {
                MPIR_Op *op_ptr = NULL;
                MPIR_Op_get_ptr(op, op_ptr);
                MPIR_Op_valid_ptr(op_ptr, mpi_errno);
            } else {
                mpi_errno = (*MPIR_OP_HDL_TO_DTYPE_FN(op)) (datatype);
                if (mpi_errno != MPI_SUCCESS) {
                    MPI_Datatype alt_dt = MPIR_Op_get_alt_datatype(op, datatype);
                    if (alt_dt != MPI_DATATYPE_NULL) {
                        datatype = alt_dt;
                        mpi_errno = MPI_SUCCESS;
                    }
                }
            }
            if (mpi_errno) {
                goto fn_fail;
            }
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
            int comm_size = comm_ptr->local_size;
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
            int sum = 0;
            for (int i = 0; i < comm_size; i++) {
                MPIR_ERRTEST_COUNT(recvcounts[i], mpi_errno);
                sum += recvcounts[i];
            }
            MPIR_ERRTEST_RECVBUF_INPLACE(recvbuf, recvcounts[comm_rank], mpi_errno);
            if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTERCOMM) {
                MPIR_ERRTEST_SENDBUF_INPLACE(sendbuf, sum, mpi_errno);
            } else if (sendbuf != MPI_IN_PLACE && sum != 0) {
                MPIR_ERRTEST_ALIAS_COLL(sendbuf, recvbuf, mpi_errno);
            }
            MPIR_ERRTEST_USERBUFFER(recvbuf, recvcounts[comm_rank], datatype, mpi_errno);
            MPIR_ERRTEST_USERBUFFER(sendbuf, sum, datatype, mpi_errno);
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    int n;
    n = comm_ptr->local_size;
#ifdef ENABLE_THREADCOMM
    if (comm_ptr->threadcomm) {
        int intracomm_size = comm_ptr->local_size;
        n = comm_ptr->threadcomm->rank_offset_table[intracomm_size - 1];
    }
#endif
    MPI_Aint *tmp_array = MPL_malloc(n * sizeof(MPI_Aint), MPL_MEM_OTHER);
    for (int i = 0; i < n; i++) {
        tmp_array[i] = recvcounts[i];
    }
    MPIR_Request *request_ptr = NULL;
    mpi_errno = MPIR_Reduce_scatter_init(sendbuf, recvbuf, tmp_array, datatype, op, comm_ptr, info_ptr,
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
                                     "**mpi_reduce_scatter_init",
                                     "**mpi_reduce_scatter_init %p %p %p %D %O %C %I %p", sendbuf,
                                     recvbuf, recvcounts, datatype, op, comm, info, request);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Reduce_scatter_init(QMPI_Context context, int tool_id, const void *sendbuf, void *recvbuf,
                             const int recvcounts[], MPI_Datatype datatype, MPI_Op op,
                             MPI_Comm comm, MPI_Info info, MPI_Request *request)
{
    return internal_Reduce_scatter_init(sendbuf, recvbuf, recvcounts, datatype, op, comm, info, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Reduce_scatter_init(const void *sendbuf, void *recvbuf, const int recvcounts[],
                            MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Info info,
                            MPI_Request *request)
{
    QMPI_Context context;
    QMPI_Reduce_scatter_init_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Reduce_scatter_init(context, 0, sendbuf, recvbuf, recvcounts, datatype, op,
                                        comm, info, request);

    fn_ptr = (QMPI_Reduce_scatter_init_t *) MPIR_QMPI_first_fn_ptrs[MPI_REDUCE_SCATTER_INIT_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_REDUCE_SCATTER_INIT_T], sendbuf,
            recvbuf, recvcounts, datatype, op, comm, info, request);
}
#else /* ENABLE_QMPI */
int MPI_Reduce_scatter_init(const void *sendbuf, void *recvbuf, const int recvcounts[],
                            MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Info info,
                            MPI_Request *request)
{
    return internal_Reduce_scatter_init(sendbuf, recvbuf, recvcounts, datatype, op, comm, info, request);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Reduce_scatter_init_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Reduce_scatter_init_c = PMPI_Reduce_scatter_init_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Reduce_scatter_init_c  MPI_Reduce_scatter_init_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Reduce_scatter_init_c as PMPI_Reduce_scatter_init_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Reduce_scatter_init_c(const void *sendbuf, void *recvbuf, const MPI_Count recvcounts[],
                              MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Info info,
                              MPI_Request *request)
                               __attribute__ ((weak, alias("PMPI_Reduce_scatter_init_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Reduce_scatter_init_c
#define MPI_Reduce_scatter_init_c PMPI_Reduce_scatter_init_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Reduce_scatter_init_c(const void *sendbuf, void *recvbuf,
                                          const MPI_Count recvcounts[], MPI_Datatype datatype,
                                          MPI_Op op, MPI_Comm comm, MPI_Info info,
                                          MPI_Request *request)
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
            MPIR_ERRTEST_OP(op, mpi_errno);
            if (!HANDLE_IS_BUILTIN(op)) {
                MPIR_Op *op_ptr = NULL;
                MPIR_Op_get_ptr(op, op_ptr);
                MPIR_Op_valid_ptr(op_ptr, mpi_errno);
            } else {
                mpi_errno = (*MPIR_OP_HDL_TO_DTYPE_FN(op)) (datatype);
                if (mpi_errno != MPI_SUCCESS) {
                    MPI_Datatype alt_dt = MPIR_Op_get_alt_datatype(op, datatype);
                    if (alt_dt != MPI_DATATYPE_NULL) {
                        datatype = alt_dt;
                        mpi_errno = MPI_SUCCESS;
                    }
                }
            }
            if (mpi_errno) {
                goto fn_fail;
            }
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
            int comm_size = comm_ptr->local_size;
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
            int sum = 0;
            for (int i = 0; i < comm_size; i++) {
                MPIR_ERRTEST_COUNT(recvcounts[i], mpi_errno);
                sum += recvcounts[i];
            }
            MPIR_ERRTEST_RECVBUF_INPLACE(recvbuf, recvcounts[comm_rank], mpi_errno);
            if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTERCOMM) {
                MPIR_ERRTEST_SENDBUF_INPLACE(sendbuf, sum, mpi_errno);
            } else if (sendbuf != MPI_IN_PLACE && sum != 0) {
                MPIR_ERRTEST_ALIAS_COLL(sendbuf, recvbuf, mpi_errno);
            }
            MPIR_ERRTEST_USERBUFFER(recvbuf, recvcounts[comm_rank], datatype, mpi_errno);
            MPIR_ERRTEST_USERBUFFER(sendbuf, sum, datatype, mpi_errno);
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        MPIR_Request *request_ptr = NULL;
        mpi_errno = MPIR_Reduce_scatter_init(sendbuf, recvbuf, (MPI_Aint *) recvcounts, datatype, op,
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
        int n;
        n = comm_ptr->local_size;
#ifdef ENABLE_THREADCOMM
        if (comm_ptr->threadcomm) {
            int intracomm_size = comm_ptr->local_size;
            n = comm_ptr->threadcomm->rank_offset_table[intracomm_size - 1];
        }
#endif
        MPI_Aint *tmp_array = MPL_malloc(n * sizeof(MPI_Aint), MPL_MEM_OTHER);
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
        MPIR_Request *request_ptr = NULL;
        mpi_errno = MPIR_Reduce_scatter_init(sendbuf, recvbuf, tmp_array, datatype, op, comm_ptr, info_ptr,
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
                                     "**mpi_reduce_scatter_init_c",
                                     "**mpi_reduce_scatter_init_c %p %p %p %D %O %C %I %p", sendbuf,
                                     recvbuf, recvcounts, datatype, op, comm, info, request);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Reduce_scatter_init_c(QMPI_Context context, int tool_id, const void *sendbuf,
                               void *recvbuf, const MPI_Count recvcounts[], MPI_Datatype datatype,
                               MPI_Op op, MPI_Comm comm, MPI_Info info, MPI_Request *request)
{
    return internal_Reduce_scatter_init_c(sendbuf, recvbuf, recvcounts, datatype, op, comm, info, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Reduce_scatter_init_c(const void *sendbuf, void *recvbuf, const MPI_Count recvcounts[],
                              MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Info info,
                              MPI_Request *request)
{
    QMPI_Context context;
    QMPI_Reduce_scatter_init_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Reduce_scatter_init_c(context, 0, sendbuf, recvbuf, recvcounts, datatype, op,
                                          comm, info, request);

    fn_ptr = (QMPI_Reduce_scatter_init_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_REDUCE_SCATTER_INIT_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_REDUCE_SCATTER_INIT_C_T], sendbuf,
            recvbuf, recvcounts, datatype, op, comm, info, request);
}
#else /* ENABLE_QMPI */
int MPI_Reduce_scatter_init_c(const void *sendbuf, void *recvbuf, const MPI_Count recvcounts[],
                              MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Info info,
                              MPI_Request *request)
{
    return internal_Reduce_scatter_init_c(sendbuf, recvbuf, recvcounts, datatype, op, comm, info, request);
}

#endif /* ENABLE_QMPI */
