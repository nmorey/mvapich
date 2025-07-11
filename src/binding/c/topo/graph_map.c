/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Graph_map */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Graph_map = PMPI_Graph_map
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Graph_map  MPI_Graph_map
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Graph_map as PMPI_Graph_map
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Graph_map(MPI_Comm comm, int nnodes, const int indx[], const int edges[], int *newrank)
     __attribute__ ((weak, alias("PMPI_Graph_map")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Graph_map
#define MPI_Graph_map PMPI_Graph_map
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Graph_map(MPI_Comm comm, int nnodes, const int indx[], const int edges[],
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
            MPIR_Comm_valid_ptr(comm_ptr, mpi_errno, FALSE);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_ERRTEST_ARGNULL(newrank, "newrank", mpi_errno);
            MPIR_ERR_CHKANDJUMP(comm_ptr->local_size < nnodes, mpi_errno, MPI_ERR_ARG, "**graphnnodes");
            MPIR_ERRTEST_ARGNULL(indx, "indx", mpi_errno);
            MPIR_ERRTEST_ARGNULL(edges, "edges", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    if (comm_ptr->topo_fns && comm_ptr->topo_fns->graphMap) {
        mpi_errno = comm_ptr->topo_fns->graphMap(comm_ptr, nnodes, indx, edges, newrank);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        mpi_errno = MPIR_Graph_map_impl(comm_ptr, nnodes, indx, edges, newrank);
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
                                     "**mpi_graph_map", "**mpi_graph_map %C %d %p %p %p", comm, nnodes,
                                     indx, edges, newrank);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Graph_map(QMPI_Context context, int tool_id, MPI_Comm comm, int nnodes, const int indx[],
                   const int edges[], int *newrank)
{
    return internal_Graph_map(comm, nnodes, indx, edges, newrank);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Graph_map(MPI_Comm comm, int nnodes, const int indx[], const int edges[], int *newrank)
{
    QMPI_Context context;
    QMPI_Graph_map_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Graph_map(context, 0, comm, nnodes, indx, edges, newrank);

    fn_ptr = (QMPI_Graph_map_t *) MPIR_QMPI_first_fn_ptrs[MPI_GRAPH_MAP_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_GRAPH_MAP_T], comm, nnodes, indx, edges,
            newrank);
}
#else /* ENABLE_QMPI */
int MPI_Graph_map(MPI_Comm comm, int nnodes, const int indx[], const int edges[], int *newrank)
{
    return internal_Graph_map(comm, nnodes, indx, edges, newrank);
}

#endif /* ENABLE_QMPI */
