/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Cartdim_get */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Cartdim_get = PMPI_Cartdim_get
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Cartdim_get  MPI_Cartdim_get
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Cartdim_get as PMPI_Cartdim_get
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Cartdim_get(MPI_Comm comm, int *ndims)  __attribute__ ((weak, alias("PMPI_Cartdim_get")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Cartdim_get
#define MPI_Cartdim_get PMPI_Cartdim_get
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Cartdim_get(MPI_Comm comm, int *ndims)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Comm *comm_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();
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
            MPIR_Comm_valid_ptr(comm_ptr, mpi_errno, TRUE);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_ERRTEST_ARGNULL(ndims, "ndims", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Cartdim_get_impl(comm_ptr, ndims);
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
                                     "**mpi_cartdim_get", "**mpi_cartdim_get %C %p", comm, ndims);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Cartdim_get(QMPI_Context context, int tool_id, MPI_Comm comm, int *ndims)
{
    return internal_Cartdim_get(comm, ndims);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Cartdim_get(MPI_Comm comm, int *ndims)
{
    QMPI_Context context;
    QMPI_Cartdim_get_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Cartdim_get(context, 0, comm, ndims);

    fn_ptr = (QMPI_Cartdim_get_t *) MPIR_QMPI_first_fn_ptrs[MPI_CARTDIM_GET_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_CARTDIM_GET_T], comm, ndims);
}
#else /* ENABLE_QMPI */
int MPI_Cartdim_get(MPI_Comm comm, int *ndims)
{
    return internal_Cartdim_get(comm, ndims);
}

#endif /* ENABLE_QMPI */
