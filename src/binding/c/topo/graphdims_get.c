/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Graphdims_get */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Graphdims_get = PMPI_Graphdims_get
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Graphdims_get  MPI_Graphdims_get
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Graphdims_get as PMPI_Graphdims_get
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Graphdims_get(MPI_Comm comm, int *nnodes, int *nedges)
     __attribute__ ((weak, alias("PMPI_Graphdims_get")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Graphdims_get
#define MPI_Graphdims_get PMPI_Graphdims_get
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Graphdims_get(MPI_Comm comm, int *nnodes, int *nedges)
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
            MPIR_ERRTEST_ARGNULL(nnodes, "nnodes", mpi_errno);
            MPIR_ERRTEST_ARGNULL(nedges, "nedges", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Graphdims_get_impl(comm_ptr, nnodes, nedges);
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
                                     "**mpi_graphdims_get", "**mpi_graphdims_get %C %p %p", comm,
                                     nnodes, nedges);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Graphdims_get(QMPI_Context context, int tool_id, MPI_Comm comm, int *nnodes, int *nedges)
{
    return internal_Graphdims_get(comm, nnodes, nedges);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Graphdims_get(MPI_Comm comm, int *nnodes, int *nedges)
{
    QMPI_Context context;
    QMPI_Graphdims_get_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Graphdims_get(context, 0, comm, nnodes, nedges);

    fn_ptr = (QMPI_Graphdims_get_t *) MPIR_QMPI_first_fn_ptrs[MPI_GRAPHDIMS_GET_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_GRAPHDIMS_GET_T], comm, nnodes,
            nedges);
}
#else /* ENABLE_QMPI */
int MPI_Graphdims_get(MPI_Comm comm, int *nnodes, int *nedges)
{
    return internal_Graphdims_get(comm, nnodes, nedges);
}

#endif /* ENABLE_QMPI */
