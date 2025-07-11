/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Dims_create */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Dims_create = PMPI_Dims_create
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Dims_create  MPI_Dims_create
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Dims_create as PMPI_Dims_create
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Dims_create(int nnodes, int ndims, int dims[])
     __attribute__ ((weak, alias("PMPI_Dims_create")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Dims_create
#define MPI_Dims_create PMPI_Dims_create
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Dims_create(int nnodes, int ndims, int dims[])
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNEG(nnodes, "nnodes", mpi_errno);
            MPIR_ERRTEST_ARGNEG(ndims, "ndims", mpi_errno);
            if (!(nnodes == 1 && ndims == 0)) {
                /* nnodes == 1 && ndims == 0 is allowed.
                 * When ndims is 0, dims can be NULL. */
                MPIR_ERRTEST_ARGNULL(dims, "dims", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Dims_create_impl(nnodes, ndims, dims);
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
                                     "**mpi_dims_create", "**mpi_dims_create %d %d %p", nnodes, ndims,
                                     dims);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Dims_create(QMPI_Context context, int tool_id, int nnodes, int ndims, int dims[])
{
    return internal_Dims_create(nnodes, ndims, dims);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Dims_create(int nnodes, int ndims, int dims[])
{
    QMPI_Context context;
    QMPI_Dims_create_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Dims_create(context, 0, nnodes, ndims, dims);

    fn_ptr = (QMPI_Dims_create_t *) MPIR_QMPI_first_fn_ptrs[MPI_DIMS_CREATE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_DIMS_CREATE_T], nnodes, ndims, dims);
}
#else /* ENABLE_QMPI */
int MPI_Dims_create(int nnodes, int ndims, int dims[])
{
    return internal_Dims_create(nnodes, ndims, dims);
}

#endif /* ENABLE_QMPI */
