/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Dist_graph_neighbors */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Dist_graph_neighbors = PMPI_Dist_graph_neighbors
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Dist_graph_neighbors  MPI_Dist_graph_neighbors
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Dist_graph_neighbors as PMPI_Dist_graph_neighbors
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Dist_graph_neighbors(MPI_Comm comm, int maxindegree, int sources[], int sourceweights[],
                             int maxoutdegree, int destinations[], int destweights[])
                              __attribute__ ((weak, alias("PMPI_Dist_graph_neighbors")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Dist_graph_neighbors
#define MPI_Dist_graph_neighbors PMPI_Dist_graph_neighbors
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Dist_graph_neighbors(MPI_Comm comm, int maxindegree, int sources[],
                                         int sourceweights[], int maxoutdegree, int destinations[],
                                         int destweights[])
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
            if (maxindegree > 0) {
                MPIR_ERRTEST_ARGNULL(sources, "sources", mpi_errno);
            }
            if (maxoutdegree > 0) {
                MPIR_ERRTEST_ARGNULL(destinations, "destinations", mpi_errno);
            }
            MPIR_Topology *topo_ptr = NULL;
            topo_ptr = MPIR_Topology_get(comm_ptr);
            MPIR_ERR_CHKANDJUMP(!topo_ptr || topo_ptr->kind != MPI_DIST_GRAPH, mpi_errno, MPI_ERR_TOPOLOGY, "**notdistgraphtopo");
            MPIR_ERRTEST_ARGNEG(maxindegree, "maxindegree", mpi_errno);
            MPIR_ERRTEST_ARGNEG(maxoutdegree, "maxoutdegree", mpi_errno);
            MPIR_ERR_CHKANDJUMP3((maxindegree < topo_ptr->topo.dist_graph.indegree), mpi_errno,
                                 MPI_ERR_ARG, "**argtoosmall", "**argtoosmall %s %d %d",
                                 "maxindegree", maxindegree, topo_ptr->topo.dist_graph.indegree);
            MPIR_ERR_CHKANDJUMP3((maxoutdegree < topo_ptr->topo.dist_graph.outdegree), mpi_errno,
                                 MPI_ERR_ARG, "**argtoosmall", "**argtoosmall %s %d %d",
                                 "maxoutdegree", maxoutdegree, topo_ptr->topo.dist_graph.outdegree);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Dist_graph_neighbors_impl(comm_ptr, maxindegree, sources, sourceweights,
                                               maxoutdegree, destinations, destweights);
    if (mpi_errno) {
        goto fn_fail;
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
                                     "**mpi_dist_graph_neighbors",
                                     "**mpi_dist_graph_neighbors %C %d %p %p %d %p %p", comm,
                                     maxindegree, sources, sourceweights, maxoutdegree, destinations,
                                     destweights);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Dist_graph_neighbors(QMPI_Context context, int tool_id, MPI_Comm comm, int maxindegree,
                              int sources[], int sourceweights[], int maxoutdegree,
                              int destinations[], int destweights[])
{
    return internal_Dist_graph_neighbors(comm, maxindegree, sources, sourceweights, maxoutdegree, destinations, destweights);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Dist_graph_neighbors(MPI_Comm comm, int maxindegree, int sources[], int sourceweights[],
                             int maxoutdegree, int destinations[], int destweights[])
{
    QMPI_Context context;
    QMPI_Dist_graph_neighbors_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Dist_graph_neighbors(context, 0, comm, maxindegree, sources, sourceweights,
                                         maxoutdegree, destinations, destweights);

    fn_ptr = (QMPI_Dist_graph_neighbors_t *) MPIR_QMPI_first_fn_ptrs[MPI_DIST_GRAPH_NEIGHBORS_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_DIST_GRAPH_NEIGHBORS_T], comm,
            maxindegree, sources, sourceweights, maxoutdegree, destinations, destweights);
}
#else /* ENABLE_QMPI */
int MPI_Dist_graph_neighbors(MPI_Comm comm, int maxindegree, int sources[], int sourceweights[],
                             int maxoutdegree, int destinations[], int destweights[])
{
    return internal_Dist_graph_neighbors(comm, maxindegree, sources, sourceweights, maxoutdegree, destinations, destweights);
}

#endif /* ENABLE_QMPI */
