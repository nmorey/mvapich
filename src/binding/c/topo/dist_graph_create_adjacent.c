/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Dist_graph_create_adjacent */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Dist_graph_create_adjacent = PMPI_Dist_graph_create_adjacent
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Dist_graph_create_adjacent  MPI_Dist_graph_create_adjacent
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Dist_graph_create_adjacent as PMPI_Dist_graph_create_adjacent
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Dist_graph_create_adjacent(MPI_Comm comm_old, int indegree, const int sources[],
                                   const int sourceweights[], int outdegree,
                                   const int destinations[], const int destweights[], MPI_Info info,
                                   int reorder, MPI_Comm *comm_dist_graph)
                                    __attribute__ ((weak, alias("PMPI_Dist_graph_create_adjacent")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Dist_graph_create_adjacent
#define MPI_Dist_graph_create_adjacent PMPI_Dist_graph_create_adjacent
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Dist_graph_create_adjacent(MPI_Comm comm_old, int indegree, const int sources[],
                                               const int sourceweights[], int outdegree,
                                               const int destinations[], const int destweights[],
                                               MPI_Info info, int reorder,
                                               MPI_Comm *comm_dist_graph)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Comm *comm_old_ptr ATTRIBUTE((unused)) = NULL;
    MPIR_Info *info_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COMM(comm_old, mpi_errno);
            MPIR_ERRTEST_INFO_OR_NULL(info, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_Comm_get_ptr(comm_old, comm_old_ptr);
    if (info != MPI_INFO_NULL) {
        MPIR_Info_get_ptr(info, info_ptr);
    }

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_Comm_valid_ptr(comm_old_ptr, mpi_errno, FALSE);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_ERRTEST_COMM_INTRA(comm_old_ptr, mpi_errno);
            if (info != MPI_INFO_NULL) {
                MPIR_Info_valid_ptr(info_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            MPIR_ERRTEST_ARGNULL(comm_dist_graph, "comm_dist_graph", mpi_errno);
            MPIR_ERRTEST_ARGNEG(indegree, "indegree", mpi_errno);
            MPIR_ERRTEST_ARGNEG(outdegree, "outdegree", mpi_errno);

            if (indegree > 0) {
                MPIR_ERRTEST_ARGNULL(sources, "sources", mpi_errno);
                if (sourceweights == MPI_UNWEIGHTED && destweights != MPI_UNWEIGHTED) {
                    MPIR_ERR_SET(mpi_errno, MPI_ERR_TOPOLOGY, "**unweightedboth");
                    goto fn_fail;
                }
                /* TODO check ranges for array elements too (**argarrayneg / **rankarray) */
            }
            if (outdegree > 0) {
                MPIR_ERRTEST_ARGNULL(destinations, "destinations", mpi_errno);
                if (destweights == MPI_UNWEIGHTED && sourceweights != MPI_UNWEIGHTED) {
                    MPIR_ERR_SET(mpi_errno, MPI_ERR_TOPOLOGY, "**unweightedboth");
                    goto fn_fail;
                }
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPIR_Comm *comm_dist_graph_ptr ATTRIBUTE((unused)) = NULL;
    *comm_dist_graph = MPI_COMM_NULL;
    mpi_errno = MPIR_Dist_graph_create_adjacent_impl(comm_old_ptr, indegree, sources, sourceweights,
                                                     outdegree, destinations, destweights, info_ptr,
                                                     reorder, &comm_dist_graph_ptr);
    if (mpi_errno) {
        goto fn_fail;
    }
    if (comm_dist_graph_ptr) {
        MPIR_OBJ_PUBLISH_HANDLE(*comm_dist_graph, comm_dist_graph_ptr->handle);
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
                                     "**mpi_dist_graph_create_adjacent",
                                     "**mpi_dist_graph_create_adjacent %C %d %p %p %d %p %p %I %d %p",
                                     comm_old, indegree, sources, sourceweights, outdegree,
                                     destinations, destweights, info, reorder, comm_dist_graph);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_old_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Dist_graph_create_adjacent(QMPI_Context context, int tool_id, MPI_Comm comm_old,
                                    int indegree, const int sources[], const int sourceweights[],
                                    int outdegree, const int destinations[],
                                    const int destweights[], MPI_Info info, int reorder,
                                    MPI_Comm *comm_dist_graph)
{
    return internal_Dist_graph_create_adjacent(comm_old, indegree, sources, sourceweights, outdegree, destinations, destweights, info, reorder, comm_dist_graph);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Dist_graph_create_adjacent(MPI_Comm comm_old, int indegree, const int sources[],
                                   const int sourceweights[], int outdegree,
                                   const int destinations[], const int destweights[], MPI_Info info,
                                   int reorder, MPI_Comm *comm_dist_graph)
{
    QMPI_Context context;
    QMPI_Dist_graph_create_adjacent_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Dist_graph_create_adjacent(context, 0, comm_old, indegree, sources,
                                               sourceweights, outdegree, destinations, destweights,
                                               info, reorder, comm_dist_graph);

    fn_ptr = (QMPI_Dist_graph_create_adjacent_t *) MPIR_QMPI_first_fn_ptrs[MPI_DIST_GRAPH_CREATE_ADJACENT_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_DIST_GRAPH_CREATE_ADJACENT_T], comm_old,
            indegree, sources, sourceweights, outdegree, destinations, destweights, info, reorder,
            comm_dist_graph);
}
#else /* ENABLE_QMPI */
int MPI_Dist_graph_create_adjacent(MPI_Comm comm_old, int indegree, const int sources[],
                                   const int sourceweights[], int outdegree,
                                   const int destinations[], const int destweights[], MPI_Info info,
                                   int reorder, MPI_Comm *comm_dist_graph)
{
    return internal_Dist_graph_create_adjacent(comm_old, indegree, sources, sourceweights, outdegree, destinations, destweights, info, reorder, comm_dist_graph);
}

#endif /* ENABLE_QMPI */
