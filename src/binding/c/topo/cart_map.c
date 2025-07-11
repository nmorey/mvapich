/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Cart_map */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Cart_map = PMPI_Cart_map
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Cart_map  MPI_Cart_map
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Cart_map as PMPI_Cart_map
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Cart_map(MPI_Comm comm, int ndims, const int dims[], const int periods[], int *newrank)
     __attribute__ ((weak, alias("PMPI_Cart_map")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Cart_map
#define MPI_Cart_map PMPI_Cart_map
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Cart_map(MPI_Comm comm, int ndims, const int dims[], const int periods[],
                             int *newrank)
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
            MPIR_ERRTEST_ARGNEG(ndims, "ndims", mpi_errno);
            MPIR_ERRTEST_ARGNULL(newrank, "newrank", mpi_errno);
            if (ndims > 0) {
                MPIR_ERRTEST_ARGNULL(dims, "dims", mpi_errno);
                MPIR_ERRTEST_ARGNULL(periods, "periods", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    if (comm_ptr->topo_fns && comm_ptr->topo_fns->cartMap) {
        mpi_errno = comm_ptr->topo_fns->cartMap(comm_ptr, ndims, dims, periods, newrank);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        mpi_errno = MPIR_Cart_map_impl(comm_ptr, ndims, dims, periods, newrank);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_cart_map", "**mpi_cart_map %C %d %p %p %p", comm, ndims,
                                     dims, periods, newrank);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Cart_map(QMPI_Context context, int tool_id, MPI_Comm comm, int ndims, const int dims[],
                  const int periods[], int *newrank)
{
    return internal_Cart_map(comm, ndims, dims, periods, newrank);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Cart_map(MPI_Comm comm, int ndims, const int dims[], const int periods[], int *newrank)
{
    QMPI_Context context;
    QMPI_Cart_map_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Cart_map(context, 0, comm, ndims, dims, periods, newrank);

    fn_ptr = (QMPI_Cart_map_t *) MPIR_QMPI_first_fn_ptrs[MPI_CART_MAP_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_CART_MAP_T], comm, ndims, dims, periods,
            newrank);
}
#else /* ENABLE_QMPI */
int MPI_Cart_map(MPI_Comm comm, int ndims, const int dims[], const int periods[], int *newrank)
{
    return internal_Cart_map(comm, ndims, dims, periods, newrank);
}

#endif /* ENABLE_QMPI */
