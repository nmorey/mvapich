/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPIX_Query_cuda_support */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPIX_Query_cuda_support = PMPIX_Query_cuda_support
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPIX_Query_cuda_support  MPIX_Query_cuda_support
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPIX_Query_cuda_support as PMPIX_Query_cuda_support
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPIX_Query_cuda_support(void)  __attribute__ ((weak, alias("PMPIX_Query_cuda_support")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPIX_Query_cuda_support
#define MPIX_Query_cuda_support PMPIX_Query_cuda_support
#endif /* MPICH_MPI_FROM_PMPI */

static int internalX_Query_cuda_support(void)
{
    int is_supported = 0;
    int mpi_errno ATTRIBUTE((unused));

    mpi_errno = PMPIX_GPU_query_support(MPIX_GPU_SUPPORT_CUDA, &is_supported);
    assert(mpi_errno == MPI_SUCCESS);

    return is_supported;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPIX_Query_cuda_support(QMPI_Context context, int tool_id)
{
    return internalX_Query_cuda_support();
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPIX_Query_cuda_support(void)
{
    QMPI_Context context;
    QMPIX_Query_cuda_support_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPIX_Query_cuda_support(context, 0);

    fn_ptr = (QMPIX_Query_cuda_support_t *) MPIR_QMPI_first_fn_ptrs[MPIX_QUERY_CUDA_SUPPORT_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPIX_QUERY_CUDA_SUPPORT_T]);
}
#else /* ENABLE_QMPI */
int MPIX_Query_cuda_support(void)
{
    return internalX_Query_cuda_support();
}

#endif /* ENABLE_QMPI */
