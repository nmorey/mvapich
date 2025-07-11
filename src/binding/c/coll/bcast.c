/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Bcast */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Bcast = PMPI_Bcast
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Bcast  MPI_Bcast
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Bcast as PMPI_Bcast
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Bcast(void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm)
     __attribute__ ((weak, alias("PMPI_Bcast")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Bcast
#define MPI_Bcast PMPI_Bcast
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Bcast(void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm)
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
                MPIR_ERRTEST_USERBUFFER(buffer, count, datatype, mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    if (count == 0 || MPIR_is_self_comm(comm_ptr)) {
        goto fn_exit;
    }

    /* ... body of routine ... */
#ifdef ENABLE_THREADCOMM
    if (comm_ptr->threadcomm) {
        mpi_errno = MPIR_Threadcomm_bcast_impl(buffer, count, datatype, root, comm_ptr);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else
#endif
    {
        mpi_errno = MPIR_Bcast(buffer, count, datatype, root, comm_ptr, MPIR_ERR_NONE);
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
                                     "**mpi_bcast", "**mpi_bcast %p %d %D %i %C", buffer, count,
                                     datatype, root, comm);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Bcast(QMPI_Context context, int tool_id, void *buffer, int count, MPI_Datatype datatype,
               int root, MPI_Comm comm)
{
    return internal_Bcast(buffer, count, datatype, root, comm);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Bcast(void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm)
{
    QMPI_Context context;
    QMPI_Bcast_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Bcast(context, 0, buffer, count, datatype, root, comm);

    fn_ptr = (QMPI_Bcast_t *) MPIR_QMPI_first_fn_ptrs[MPI_BCAST_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_BCAST_T], buffer, count, datatype, root,
            comm);
}
#else /* ENABLE_QMPI */
int MPI_Bcast(void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm)
{
    return internal_Bcast(buffer, count, datatype, root, comm);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Bcast_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Bcast_c = PMPI_Bcast_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Bcast_c  MPI_Bcast_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Bcast_c as PMPI_Bcast_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Bcast_c(void *buffer, MPI_Count count, MPI_Datatype datatype, int root, MPI_Comm comm)
     __attribute__ ((weak, alias("PMPI_Bcast_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Bcast_c
#define MPI_Bcast_c PMPI_Bcast_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Bcast_c(void *buffer, MPI_Count count, MPI_Datatype datatype, int root,
                            MPI_Comm comm)
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
                MPIR_ERRTEST_USERBUFFER(buffer, count, datatype, mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    if (count == 0 || MPIR_is_self_comm(comm_ptr)) {
        goto fn_exit;
    }

    /* ... body of routine ... */
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
#ifdef ENABLE_THREADCOMM
        if (comm_ptr->threadcomm) {
            mpi_errno = MPIR_Threadcomm_bcast_impl(buffer, (MPI_Aint) count, datatype, root, comm_ptr);
            if (mpi_errno) {
                goto fn_fail;
            }
        } else
#endif
        {
            mpi_errno = MPIR_Bcast(buffer, (MPI_Aint) count, datatype, root, comm_ptr, MPIR_ERR_NONE);
            if (mpi_errno) {
                goto fn_fail;
            }
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
#ifdef ENABLE_THREADCOMM
        if (comm_ptr->threadcomm) {
            mpi_errno = MPIR_Threadcomm_bcast_impl(buffer, count, datatype, root, comm_ptr);
            if (mpi_errno) {
                goto fn_fail;
            }
        } else
#endif
        {
            mpi_errno = MPIR_Bcast(buffer, count, datatype, root, comm_ptr, MPIR_ERR_NONE);
            if (mpi_errno) {
                goto fn_fail;
            }
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
                                     "**mpi_bcast_c", "**mpi_bcast_c %p %c %D %i %C", buffer, count,
                                     datatype, root, comm);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Bcast_c(QMPI_Context context, int tool_id, void *buffer, MPI_Count count,
                 MPI_Datatype datatype, int root, MPI_Comm comm)
{
    return internal_Bcast_c(buffer, count, datatype, root, comm);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Bcast_c(void *buffer, MPI_Count count, MPI_Datatype datatype, int root, MPI_Comm comm)
{
    QMPI_Context context;
    QMPI_Bcast_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Bcast_c(context, 0, buffer, count, datatype, root, comm);

    fn_ptr = (QMPI_Bcast_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_BCAST_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_BCAST_C_T], buffer, count, datatype,
            root, comm);
}
#else /* ENABLE_QMPI */
int MPI_Bcast_c(void *buffer, MPI_Count count, MPI_Datatype datatype, int root, MPI_Comm comm)
{
    return internal_Bcast_c(buffer, count, datatype, root, comm);
}

#endif /* ENABLE_QMPI */
