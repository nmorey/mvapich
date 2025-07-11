/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Buffer_flush */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Buffer_flush = PMPI_Buffer_flush
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Buffer_flush  MPI_Buffer_flush
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Buffer_flush as PMPI_Buffer_flush
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Buffer_flush(void)  __attribute__ ((weak, alias("PMPI_Buffer_flush")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Buffer_flush
#define MPI_Buffer_flush PMPI_Buffer_flush
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Buffer_flush(void)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

    /* ... body of routine ... */
    mpi_errno = MPIR_Buffer_flush_impl();
    if (mpi_errno) {
        goto fn_fail;
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
                                     "**mpi_buffer_flush", 0);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Buffer_flush(QMPI_Context context, int tool_id)
{
    return internal_Buffer_flush();
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Buffer_flush(void)
{
    QMPI_Context context;
    QMPI_Buffer_flush_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Buffer_flush(context, 0);

    fn_ptr = (QMPI_Buffer_flush_t *) MPIR_QMPI_first_fn_ptrs[MPI_BUFFER_FLUSH_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_BUFFER_FLUSH_T]);
}
#else /* ENABLE_QMPI */
int MPI_Buffer_flush(void)
{
    return internal_Buffer_flush();
}

#endif /* ENABLE_QMPI */
