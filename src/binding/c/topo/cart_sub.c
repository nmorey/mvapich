/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Cart_sub */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Cart_sub = PMPI_Cart_sub
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Cart_sub  MPI_Cart_sub
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Cart_sub as PMPI_Cart_sub
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Cart_sub(MPI_Comm comm, const int remain_dims[], MPI_Comm *newcomm)
     __attribute__ ((weak, alias("PMPI_Cart_sub")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Cart_sub
#define MPI_Cart_sub PMPI_Cart_sub
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Cart_sub(MPI_Comm comm, const int remain_dims[], MPI_Comm *newcomm)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Comm *comm_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
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
            MPIR_Comm_valid_ptr(comm_ptr, mpi_errno, FALSE);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_ERRTEST_ARGNULL(newcomm, "newcomm", mpi_errno);
            MPIR_Topology *cart_ptr = MPIR_Topology_get(comm_ptr);
            MPIR_ERR_CHKANDJUMP((!cart_ptr || cart_ptr->kind != MPI_CART),
                                mpi_errno, MPI_ERR_TOPOLOGY, "**notcarttopo");
            int ndims = cart_ptr->topo.cart.ndims;
            if (ndims != 0) {
                MPIR_ERRTEST_ARGNULL(remain_dims, "remain_dims", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPIR_Comm *newcomm_ptr ATTRIBUTE((unused)) = NULL;
    *newcomm = MPI_COMM_NULL;
    mpi_errno = MPIR_Cart_sub_impl(comm_ptr, remain_dims, &newcomm_ptr);
    if (mpi_errno) {
        goto fn_fail;
    }
    if (newcomm_ptr) {
        MPIR_OBJ_PUBLISH_HANDLE(*newcomm, newcomm_ptr->handle);
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
                                     "**mpi_cart_sub", "**mpi_cart_sub %C %p %p", comm, remain_dims,
                                     newcomm);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Cart_sub(QMPI_Context context, int tool_id, MPI_Comm comm, const int remain_dims[],
                  MPI_Comm *newcomm)
{
    return internal_Cart_sub(comm, remain_dims, newcomm);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Cart_sub(MPI_Comm comm, const int remain_dims[], MPI_Comm *newcomm)
{
    QMPI_Context context;
    QMPI_Cart_sub_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Cart_sub(context, 0, comm, remain_dims, newcomm);

    fn_ptr = (QMPI_Cart_sub_t *) MPIR_QMPI_first_fn_ptrs[MPI_CART_SUB_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_CART_SUB_T], comm, remain_dims,
            newcomm);
}
#else /* ENABLE_QMPI */
int MPI_Cart_sub(MPI_Comm comm, const int remain_dims[], MPI_Comm *newcomm)
{
    return internal_Cart_sub(comm, remain_dims, newcomm);
}

#endif /* ENABLE_QMPI */
