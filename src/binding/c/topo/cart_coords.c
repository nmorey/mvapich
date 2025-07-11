/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Cart_coords */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Cart_coords = PMPI_Cart_coords
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Cart_coords  MPI_Cart_coords
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Cart_coords as PMPI_Cart_coords
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Cart_coords(MPI_Comm comm, int rank, int maxdims, int coords[])
     __attribute__ ((weak, alias("PMPI_Cart_coords")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Cart_coords
#define MPI_Cart_coords PMPI_Cart_coords
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Cart_coords(MPI_Comm comm, int rank, int maxdims, int coords[])
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
            MPIR_ERRTEST_RANK(comm_ptr, rank, mpi_errno);
            MPIR_ERRTEST_ARGNEG(maxdims, "maxdims", mpi_errno);
            MPIR_Topology *cart_ptr;
            cart_ptr = MPIR_Topology_get(comm_ptr);
            MPIR_ERR_CHKANDJUMP((!cart_ptr || cart_ptr->kind != MPI_CART), mpi_errno, MPI_ERR_TOPOLOGY, "**notcarttopo");
            MPIR_ERR_CHKANDJUMP2((cart_ptr->topo.cart.ndims > maxdims), mpi_errno, MPI_ERR_ARG,
                                 "**dimsmany", "**dimsmany %d %d", cart_ptr->topo.cart.ndims, maxdims);
            if (cart_ptr->topo.cart.ndims > 0) {
                MPIR_ERRTEST_ARGNULL(coords, "coords", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Cart_coords_impl(comm_ptr, rank, maxdims, coords);
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
                                     "**mpi_cart_coords", "**mpi_cart_coords %C %i %d %p", comm, rank,
                                     maxdims, coords);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Cart_coords(QMPI_Context context, int tool_id, MPI_Comm comm, int rank, int maxdims,
                     int coords[])
{
    return internal_Cart_coords(comm, rank, maxdims, coords);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Cart_coords(MPI_Comm comm, int rank, int maxdims, int coords[])
{
    QMPI_Context context;
    QMPI_Cart_coords_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Cart_coords(context, 0, comm, rank, maxdims, coords);

    fn_ptr = (QMPI_Cart_coords_t *) MPIR_QMPI_first_fn_ptrs[MPI_CART_COORDS_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_CART_COORDS_T], comm, rank, maxdims,
            coords);
}
#else /* ENABLE_QMPI */
int MPI_Cart_coords(MPI_Comm comm, int rank, int maxdims, int coords[])
{
    return internal_Cart_coords(comm, rank, maxdims, coords);
}

#endif /* ENABLE_QMPI */
