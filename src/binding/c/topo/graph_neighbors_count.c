/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Graph_neighbors_count */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Graph_neighbors_count = PMPI_Graph_neighbors_count
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Graph_neighbors_count  MPI_Graph_neighbors_count
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Graph_neighbors_count as PMPI_Graph_neighbors_count
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Graph_neighbors_count(MPI_Comm comm, int rank, int *nneighbors)
     __attribute__ ((weak, alias("PMPI_Graph_neighbors_count")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Graph_neighbors_count
#define MPI_Graph_neighbors_count PMPI_Graph_neighbors_count
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Graph_neighbors_count(MPI_Comm comm, int rank, int *nneighbors)
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
            MPIR_ERRTEST_ARGNULL(nneighbors, "nneighbors", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Graph_neighbors_count_impl(comm_ptr, rank, nneighbors);
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
                                     "**mpi_graph_neighbors_count",
                                     "**mpi_graph_neighbors_count %C %i %p", comm, rank, nneighbors);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Graph_neighbors_count(QMPI_Context context, int tool_id, MPI_Comm comm, int rank,
                               int *nneighbors)
{
    return internal_Graph_neighbors_count(comm, rank, nneighbors);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Graph_neighbors_count(MPI_Comm comm, int rank, int *nneighbors)
{
    QMPI_Context context;
    QMPI_Graph_neighbors_count_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Graph_neighbors_count(context, 0, comm, rank, nneighbors);

    fn_ptr = (QMPI_Graph_neighbors_count_t *) MPIR_QMPI_first_fn_ptrs[MPI_GRAPH_NEIGHBORS_COUNT_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_GRAPH_NEIGHBORS_COUNT_T], comm, rank,
            nneighbors);
}
#else /* ENABLE_QMPI */
int MPI_Graph_neighbors_count(MPI_Comm comm, int rank, int *nneighbors)
{
    return internal_Graph_neighbors_count(comm, rank, nneighbors);
}

#endif /* ENABLE_QMPI */
