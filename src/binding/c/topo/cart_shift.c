/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Cart_shift */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Cart_shift = PMPI_Cart_shift
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Cart_shift  MPI_Cart_shift
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Cart_shift as PMPI_Cart_shift
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Cart_shift(MPI_Comm comm, int direction, int disp, int *rank_source, int *rank_dest)
     __attribute__ ((weak, alias("PMPI_Cart_shift")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Cart_shift
#define MPI_Cart_shift PMPI_Cart_shift
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Cart_shift(MPI_Comm comm, int direction, int disp, int *rank_source,
                               int *rank_dest)
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
            MPIR_ERRTEST_ARGNEG(direction, "direction", mpi_errno);
            MPIR_ERRTEST_ARGNULL(rank_source, "rank_source", mpi_errno);
            MPIR_ERRTEST_ARGNULL(rank_dest, "rank_dest", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Cart_shift_impl(comm_ptr, direction, disp, rank_source, rank_dest);
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
                                     "**mpi_cart_shift", "**mpi_cart_shift %C %d %d %p %p", comm,
                                     direction, disp, rank_source, rank_dest);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Cart_shift(QMPI_Context context, int tool_id, MPI_Comm comm, int direction, int disp,
                    int *rank_source, int *rank_dest)
{
    return internal_Cart_shift(comm, direction, disp, rank_source, rank_dest);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Cart_shift(MPI_Comm comm, int direction, int disp, int *rank_source, int *rank_dest)
{
    QMPI_Context context;
    QMPI_Cart_shift_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Cart_shift(context, 0, comm, direction, disp, rank_source, rank_dest);

    fn_ptr = (QMPI_Cart_shift_t *) MPIR_QMPI_first_fn_ptrs[MPI_CART_SHIFT_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_CART_SHIFT_T], comm, direction, disp,
            rank_source, rank_dest);
}
#else /* ENABLE_QMPI */
int MPI_Cart_shift(MPI_Comm comm, int direction, int disp, int *rank_source, int *rank_dest)
{
    return internal_Cart_shift(comm, direction, disp, rank_source, rank_dest);
}

#endif /* ENABLE_QMPI */
