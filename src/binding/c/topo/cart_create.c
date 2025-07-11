/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Cart_create */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Cart_create = PMPI_Cart_create
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Cart_create  MPI_Cart_create
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Cart_create as PMPI_Cart_create
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Cart_create(MPI_Comm comm_old, int ndims, const int dims[], const int periods[],
                    int reorder, MPI_Comm *comm_cart)
                     __attribute__ ((weak, alias("PMPI_Cart_create")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Cart_create
#define MPI_Cart_create PMPI_Cart_create
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Cart_create(MPI_Comm comm_old, int ndims, const int dims[], const int periods[],
                                int reorder, MPI_Comm *comm_cart)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Comm *comm_old_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COMM(comm_old, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_Comm_get_ptr(comm_old, comm_old_ptr);

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_Comm_valid_ptr(comm_old_ptr, mpi_errno, FALSE);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_ERRTEST_COMM_INTRA(comm_old_ptr, mpi_errno);
            MPIR_ERRTEST_ARGNEG(ndims, "ndims", mpi_errno);
            MPIR_ERRTEST_ARGNULL(comm_cart, "comm_cart", mpi_errno);
            if (ndims > 0) {
                MPIR_ERRTEST_ARGNULL(dims, "dims", mpi_errno);
                MPIR_ERRTEST_ARGNULL(periods, "periods", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    if (comm_old_ptr->topo_fns && comm_old_ptr->topo_fns->cartCreate) {
        mpi_errno = comm_old_ptr->topo_fns->cartCreate(comm_old_ptr, ndims, dims, periods, reorder,
                                                       comm_cart);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        MPIR_Comm *comm_cart_ptr ATTRIBUTE((unused)) = NULL;
        *comm_cart = MPI_COMM_NULL;
        mpi_errno = MPIR_Cart_create_impl(comm_old_ptr, ndims, dims, periods, reorder, &comm_cart_ptr);
        if (mpi_errno) {
            goto fn_fail;
        }
        if (comm_cart_ptr) {
            MPIR_OBJ_PUBLISH_HANDLE(*comm_cart, comm_cart_ptr->handle);
        }
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
                                     "**mpi_cart_create", "**mpi_cart_create %C %d %p %p %d %p",
                                     comm_old, ndims, dims, periods, reorder, comm_cart);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_old_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Cart_create(QMPI_Context context, int tool_id, MPI_Comm comm_old, int ndims,
                     const int dims[], const int periods[], int reorder, MPI_Comm *comm_cart)
{
    return internal_Cart_create(comm_old, ndims, dims, periods, reorder, comm_cart);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Cart_create(MPI_Comm comm_old, int ndims, const int dims[], const int periods[],
                    int reorder, MPI_Comm *comm_cart)
{
    QMPI_Context context;
    QMPI_Cart_create_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Cart_create(context, 0, comm_old, ndims, dims, periods, reorder, comm_cart);

    fn_ptr = (QMPI_Cart_create_t *) MPIR_QMPI_first_fn_ptrs[MPI_CART_CREATE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_CART_CREATE_T], comm_old, ndims, dims,
            periods, reorder, comm_cart);
}
#else /* ENABLE_QMPI */
int MPI_Cart_create(MPI_Comm comm_old, int ndims, const int dims[], const int periods[],
                    int reorder, MPI_Comm *comm_cart)
{
    return internal_Cart_create(comm_old, ndims, dims, periods, reorder, comm_cart);
}

#endif /* ENABLE_QMPI */
