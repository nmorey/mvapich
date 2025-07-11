/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPIX_Stream_create */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPIX_Stream_create = PMPIX_Stream_create
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPIX_Stream_create  MPIX_Stream_create
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPIX_Stream_create as PMPIX_Stream_create
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPIX_Stream_create(MPI_Info info, MPIX_Stream *stream)
     __attribute__ ((weak, alias("PMPIX_Stream_create")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPIX_Stream_create
#define MPIX_Stream_create PMPIX_Stream_create
#endif /* MPICH_MPI_FROM_PMPI */

static int internalX_Stream_create(MPI_Info info, MPIX_Stream *stream)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Info *info_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_INFO_OR_NULL(info, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    if (info != MPI_INFO_NULL) {
        MPIR_Info_get_ptr(info, info_ptr);
    }

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            if (info != MPI_INFO_NULL) {
                MPIR_Info_valid_ptr(info_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            MPIR_ERRTEST_ARGNULL(stream, "stream", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPIR_Stream *stream_ptr ATTRIBUTE((unused)) = NULL;
    *stream = MPIX_STREAM_NULL;
    mpi_errno = MPIR_Stream_create_impl(info_ptr, &stream_ptr);
    if (mpi_errno) {
        goto fn_fail;
    }
    if (stream_ptr) {
        MPIR_OBJ_PUBLISH_HANDLE(*stream, stream_ptr->handle);
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
                                     "**mpix_stream_create", "**mpix_stream_create %I %p", info,
                                     stream);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPIX_Stream_create(QMPI_Context context, int tool_id, MPI_Info info, MPIX_Stream *stream)
{
    return internalX_Stream_create(info, stream);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPIX_Stream_create(MPI_Info info, MPIX_Stream *stream)
{
    QMPI_Context context;
    QMPIX_Stream_create_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPIX_Stream_create(context, 0, info, stream);

    fn_ptr = (QMPIX_Stream_create_t *) MPIR_QMPI_first_fn_ptrs[MPIX_STREAM_CREATE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPIX_STREAM_CREATE_T], info, stream);
}
#else /* ENABLE_QMPI */
int MPIX_Stream_create(MPI_Info info, MPIX_Stream *stream)
{
    return internalX_Stream_create(info, stream);
}

#endif /* ENABLE_QMPI */
