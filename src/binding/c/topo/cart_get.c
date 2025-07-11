/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Cart_get */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Cart_get = PMPI_Cart_get
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Cart_get  MPI_Cart_get
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Cart_get as PMPI_Cart_get
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Cart_get(MPI_Comm comm, int maxdims, int dims[], int periods[], int coords[])
     __attribute__ ((weak, alias("PMPI_Cart_get")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Cart_get
#define MPI_Cart_get PMPI_Cart_get
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Cart_get(MPI_Comm comm, int maxdims, int dims[], int periods[], int coords[])
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
            MPIR_ERRTEST_ARGNEG(maxdims, "maxdims", mpi_errno);
            if (maxdims > 0) {
                MPIR_ERRTEST_ARGNULL(dims, "dims", mpi_errno);
                MPIR_ERRTEST_ARGNULL(periods, "periods", mpi_errno);
                MPIR_ERRTEST_ARGNULL(coords, "coords", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Cart_get_impl(comm_ptr, maxdims, dims, periods, coords);
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
                                     "**mpi_cart_get", "**mpi_cart_get %C %d %p %p %p", comm, maxdims,
                                     dims, periods, coords);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Cart_get(QMPI_Context context, int tool_id, MPI_Comm comm, int maxdims, int dims[],
                  int periods[], int coords[])
{
    return internal_Cart_get(comm, maxdims, dims, periods, coords);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Cart_get(MPI_Comm comm, int maxdims, int dims[], int periods[], int coords[])
{
    QMPI_Context context;
    QMPI_Cart_get_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Cart_get(context, 0, comm, maxdims, dims, periods, coords);

    fn_ptr = (QMPI_Cart_get_t *) MPIR_QMPI_first_fn_ptrs[MPI_CART_GET_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_CART_GET_T], comm, maxdims, dims,
            periods, coords);
}
#else /* ENABLE_QMPI */
int MPI_Cart_get(MPI_Comm comm, int maxdims, int dims[], int periods[], int coords[])
{
    return internal_Cart_get(comm, maxdims, dims, periods, coords);
}

#endif /* ENABLE_QMPI */
