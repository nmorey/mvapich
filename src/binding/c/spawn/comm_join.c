/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Comm_join */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Comm_join = PMPI_Comm_join
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Comm_join  MPI_Comm_join
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Comm_join as PMPI_Comm_join
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Comm_join(int fd, MPI_Comm *intercomm)  __attribute__ ((weak, alias("PMPI_Comm_join")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Comm_join
#define MPI_Comm_join PMPI_Comm_join
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Comm_join(int fd, MPI_Comm *intercomm)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(intercomm, "intercomm", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPIR_Comm *intercomm_ptr ATTRIBUTE((unused)) = NULL;
    *intercomm = MPI_COMM_NULL;
    mpi_errno = MPIR_Comm_join_impl(fd, &intercomm_ptr);
    if (mpi_errno) {
        goto fn_fail;
    }
    if (intercomm_ptr) {
        MPIR_OBJ_PUBLISH_HANDLE(*intercomm, intercomm_ptr->handle);
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
                                     "**mpi_comm_join", "**mpi_comm_join %d %p", fd, intercomm);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Comm_join(QMPI_Context context, int tool_id, int fd, MPI_Comm *intercomm)
{
    return internal_Comm_join(fd, intercomm);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Comm_join(int fd, MPI_Comm *intercomm)
{
    QMPI_Context context;
    QMPI_Comm_join_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Comm_join(context, 0, fd, intercomm);

    fn_ptr = (QMPI_Comm_join_t *) MPIR_QMPI_first_fn_ptrs[MPI_COMM_JOIN_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_COMM_JOIN_T], fd, intercomm);
}
#else /* ENABLE_QMPI */
int MPI_Comm_join(int fd, MPI_Comm *intercomm)
{
    return internal_Comm_join(fd, intercomm);
}

#endif /* ENABLE_QMPI */
