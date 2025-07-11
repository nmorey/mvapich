/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Dist_graph_create */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Dist_graph_create = PMPI_Dist_graph_create
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Dist_graph_create  MPI_Dist_graph_create
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Dist_graph_create as PMPI_Dist_graph_create
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Dist_graph_create(MPI_Comm comm_old, int n, const int sources[], const int degrees[],
                          const int destinations[], const int weights[], MPI_Info info, int reorder,
                          MPI_Comm *comm_dist_graph)
                           __attribute__ ((weak, alias("PMPI_Dist_graph_create")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Dist_graph_create
#define MPI_Dist_graph_create PMPI_Dist_graph_create
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Dist_graph_create(MPI_Comm comm_old, int n, const int sources[],
                                      const int degrees[], const int destinations[],
                                      const int weights[], MPI_Info info, int reorder,
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
            MPIR_ERRTEST_ARGNEG(n, "n", mpi_errno);
            MPIR_ERRTEST_ARGNULL(comm_dist_graph, "comm_dist_graph", mpi_errno);
            if (n > 0) {
                int have_degrees = 0;
                MPIR_ERRTEST_ARGNULL(sources, "sources", mpi_errno);
                MPIR_ERRTEST_ARGNULL(degrees, "degrees", mpi_errno);
                for (int i = 0; i < n; ++i) {
                    if (degrees[i]) {
                        have_degrees = 1;
                        break;
                    }
                }
                if (have_degrees) {
                    MPIR_ERRTEST_ARGNULL(destinations, "destinations", mpi_errno);
                    if (weights != MPI_UNWEIGHTED)
                        MPIR_ERRTEST_ARGNULL(weights, "weights", mpi_errno);
                }
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPIR_Comm *comm_dist_graph_ptr ATTRIBUTE((unused)) = NULL;
    *comm_dist_graph = MPI_COMM_NULL;
    mpi_errno = MPIR_Dist_graph_create_impl(comm_old_ptr, n, sources, degrees, destinations, weights,
                                            info_ptr, reorder, &comm_dist_graph_ptr);
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
                                     "**mpi_dist_graph_create",
                                     "**mpi_dist_graph_create %C %d %p %p %p %p %I %d %p", comm_old, n,
                                     sources, degrees, destinations, weights, info, reorder,
                                     comm_dist_graph);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_old_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Dist_graph_create(QMPI_Context context, int tool_id, MPI_Comm comm_old, int n,
                           const int sources[], const int degrees[], const int destinations[],
                           const int weights[], MPI_Info info, int reorder,
                           MPI_Comm *comm_dist_graph)
{
    return internal_Dist_graph_create(comm_old, n, sources, degrees, destinations, weights, info, reorder, comm_dist_graph);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Dist_graph_create(MPI_Comm comm_old, int n, const int sources[], const int degrees[],
                          const int destinations[], const int weights[], MPI_Info info, int reorder,
                          MPI_Comm *comm_dist_graph)
{
    QMPI_Context context;
    QMPI_Dist_graph_create_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Dist_graph_create(context, 0, comm_old, n, sources, degrees, destinations,
                                      weights, info, reorder, comm_dist_graph);

    fn_ptr = (QMPI_Dist_graph_create_t *) MPIR_QMPI_first_fn_ptrs[MPI_DIST_GRAPH_CREATE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_DIST_GRAPH_CREATE_T], comm_old, n,
            sources, degrees, destinations, weights, info, reorder, comm_dist_graph);
}
#else /* ENABLE_QMPI */
int MPI_Dist_graph_create(MPI_Comm comm_old, int n, const int sources[], const int degrees[],
                          const int destinations[], const int weights[], MPI_Info info, int reorder,
                          MPI_Comm *comm_dist_graph)
{
    return internal_Dist_graph_create(comm_old, n, sources, degrees, destinations, weights, info, reorder, comm_dist_graph);
}

#endif /* ENABLE_QMPI */
