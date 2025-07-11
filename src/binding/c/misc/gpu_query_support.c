/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPIX_GPU_query_support */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPIX_GPU_query_support = PMPIX_GPU_query_support
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPIX_GPU_query_support  MPIX_GPU_query_support
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPIX_GPU_query_support as PMPIX_GPU_query_support
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPIX_GPU_query_support(int gpu_type, int *is_supported)
     __attribute__ ((weak, alias("PMPIX_GPU_query_support")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPIX_GPU_query_support
#define MPIX_GPU_query_support PMPIX_GPU_query_support
#endif /* MPICH_MPI_FROM_PMPI */

static int internalX_GPU_query_support(int gpu_type, int *is_supported)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(is_supported, "is_supported", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_GPU_query_support_impl(gpu_type, is_supported);
    if (mpi_errno) {
        goto fn_fail;
    }
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpix_gpu_query_support", "**mpix_gpu_query_support %d %p",
                                     gpu_type, is_supported);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPIX_GPU_query_support(QMPI_Context context, int tool_id, int gpu_type, int *is_supported)
{
    return internalX_GPU_query_support(gpu_type, is_supported);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPIX_GPU_query_support(int gpu_type, int *is_supported)
{
    QMPI_Context context;
    QMPIX_GPU_query_support_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPIX_GPU_query_support(context, 0, gpu_type, is_supported);

    fn_ptr = (QMPIX_GPU_query_support_t *) MPIR_QMPI_first_fn_ptrs[MPIX_GPU_QUERY_SUPPORT_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPIX_GPU_QUERY_SUPPORT_T], gpu_type,
            is_supported);
}
#else /* ENABLE_QMPI */
int MPIX_GPU_query_support(int gpu_type, int *is_supported)
{
    return internalX_GPU_query_support(gpu_type, is_supported);
}

#endif /* ENABLE_QMPI */
