/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPIX_Stream_comm_create */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPIX_Stream_comm_create = PMPIX_Stream_comm_create
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPIX_Stream_comm_create  MPIX_Stream_comm_create
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPIX_Stream_comm_create as PMPIX_Stream_comm_create
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPIX_Stream_comm_create(MPI_Comm comm, MPIX_Stream stream, MPI_Comm *newcomm)
     __attribute__ ((weak, alias("PMPIX_Stream_comm_create")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPIX_Stream_comm_create
#define MPIX_Stream_comm_create PMPIX_Stream_comm_create
#endif /* MPICH_MPI_FROM_PMPI */

static int internalX_Stream_comm_create(MPI_Comm comm, MPIX_Stream stream, MPI_Comm *newcomm)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Comm *comm_ptr ATTRIBUTE((unused)) = NULL;
    MPIR_Stream *stream_ptr ATTRIBUTE((unused)) = NULL;

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
    if (stream != MPIX_STREAM_NULL) {
        MPIR_Stream_get_ptr(stream, stream_ptr);
    }

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_Comm_valid_ptr(comm_ptr, mpi_errno, FALSE);
            if (mpi_errno) {
                goto fn_fail;
            }
            if (stream != MPIX_STREAM_NULL) {
                MPIR_Stream_valid_ptr(stream_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            MPIR_ERRTEST_ARGNULL(newcomm, "newcomm", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPIR_Comm *newcomm_ptr ATTRIBUTE((unused)) = NULL;
    *newcomm = MPI_COMM_NULL;
    mpi_errno = MPIR_Stream_comm_create_impl(comm_ptr, stream_ptr, &newcomm_ptr);
    if (mpi_errno) {
        goto fn_fail;
    }
    if (newcomm_ptr) {
        MPIR_OBJ_PUBLISH_HANDLE(*newcomm, newcomm_ptr->handle);
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
                                     "**mpix_stream_comm_create", "**mpix_stream_comm_create %C %x %p",
                                     comm, stream, newcomm);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPIX_Stream_comm_create(QMPI_Context context, int tool_id, MPI_Comm comm, MPIX_Stream stream,
                             MPI_Comm *newcomm)
{
    return internalX_Stream_comm_create(comm, stream, newcomm);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPIX_Stream_comm_create(MPI_Comm comm, MPIX_Stream stream, MPI_Comm *newcomm)
{
    QMPI_Context context;
    QMPIX_Stream_comm_create_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPIX_Stream_comm_create(context, 0, comm, stream, newcomm);

    fn_ptr = (QMPIX_Stream_comm_create_t *) MPIR_QMPI_first_fn_ptrs[MPIX_STREAM_COMM_CREATE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPIX_STREAM_COMM_CREATE_T], comm, stream,
            newcomm);
}
#else /* ENABLE_QMPI */
int MPIX_Stream_comm_create(MPI_Comm comm, MPIX_Stream stream, MPI_Comm *newcomm)
{
    return internalX_Stream_comm_create(comm, stream, newcomm);
}

#endif /* ENABLE_QMPI */
