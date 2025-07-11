/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Graph_create */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Graph_create = PMPI_Graph_create
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Graph_create  MPI_Graph_create
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Graph_create as PMPI_Graph_create
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Graph_create(MPI_Comm comm_old, int nnodes, const int indx[], const int edges[],
                     int reorder, MPI_Comm *comm_graph)
                      __attribute__ ((weak, alias("PMPI_Graph_create")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Graph_create
#define MPI_Graph_create PMPI_Graph_create
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Graph_create(MPI_Comm comm_old, int nnodes, const int indx[], const int edges[],
                                 int reorder, MPI_Comm *comm_graph)
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
            MPIR_ERRTEST_ARGNULL(comm_graph, "comm_graph", mpi_errno);
            int comm_size = comm_old_ptr->remote_size;

            /* Check that the communicator is large enough */
            if (nnodes > comm_size) {
                mpi_errno = MPIR_Err_create_code(MPI_SUCCESS, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_ARG,
                                                 "**topotoolarge", "**topotoolarge %d %d", nnodes, comm_size);
                if (mpi_errno)
                    goto fn_fail;
            }

            if (nnodes > 0) {
                MPIR_ERRTEST_ARGNULL(indx, "indx", mpi_errno);
                MPIR_ERRTEST_ARGNULL(edges, "edges", mpi_errno);
                /* Check that index is monotone nondecreasing */
                /* Use ERR_ARG instead of ERR_TOPOLOGY because there is no
                 * topology yet */
                for (int i = 0; i < nnodes; i++) {
                    if (indx[i] < 0) {
                        mpi_errno = MPIR_Err_create_code(MPI_SUCCESS, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_ARG,
                                                        "**indexneg", "**indexneg %d %d", i, indx[i]);
                        if (mpi_errno)
                            goto fn_fail;
                    }
                    if (i + 1 < nnodes && indx[i] > indx[i + 1]) {
                        mpi_errno = MPIR_Err_create_code(MPI_SUCCESS, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_ARG,
                                                        "**indexnonmonotone", "**indexnonmonotone %d %d %d", i, indx[i], indx[i + 1]);
                        if (mpi_errno)
                            goto fn_fail;
                    }
                }
                /* Check that edge number is in range. Note that the
                 * edges refer to a rank in the communicator, and can
                 * be greater than nnodes */
                for (int i = 0; i < indx[nnodes - 1]; i++) {
                    if (edges[i] > comm_size || edges[i] < 0) {
                        mpi_errno = MPIR_Err_create_code(MPI_SUCCESS, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_ARG,
                                                         "**edgeoutrange", "**edgeoutrange %d %d %d", i, edges[i], comm_size);
                        if (mpi_errno)
                            goto fn_fail;
                    }
                }
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* Test for empty communicator */
    if (nnodes == 0) {
        *comm_graph = MPI_COMM_NULL;
        goto fn_exit;
    }

    /* ... body of routine ... */
    if (comm_old_ptr->topo_fns && comm_old_ptr->topo_fns->graphCreate) {
        mpi_errno = comm_old_ptr->topo_fns->graphCreate(comm_old_ptr, nnodes, indx, edges, reorder,
                                                        comm_graph);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        MPIR_Comm *comm_graph_ptr ATTRIBUTE((unused)) = NULL;
        *comm_graph = MPI_COMM_NULL;
        mpi_errno = MPIR_Graph_create_impl(comm_old_ptr, nnodes, indx, edges, reorder, &comm_graph_ptr);
        if (mpi_errno) {
            goto fn_fail;
        }
        if (comm_graph_ptr) {
            MPIR_OBJ_PUBLISH_HANDLE(*comm_graph, comm_graph_ptr->handle);
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
                                     "**mpi_graph_create", "**mpi_graph_create %C %d %p %p %d %p",
                                     comm_old, nnodes, indx, edges, reorder, comm_graph);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_old_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Graph_create(QMPI_Context context, int tool_id, MPI_Comm comm_old, int nnodes,
                      const int indx[], const int edges[], int reorder, MPI_Comm *comm_graph)
{
    return internal_Graph_create(comm_old, nnodes, indx, edges, reorder, comm_graph);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Graph_create(MPI_Comm comm_old, int nnodes, const int indx[], const int edges[],
                     int reorder, MPI_Comm *comm_graph)
{
    QMPI_Context context;
    QMPI_Graph_create_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Graph_create(context, 0, comm_old, nnodes, indx, edges, reorder, comm_graph);

    fn_ptr = (QMPI_Graph_create_t *) MPIR_QMPI_first_fn_ptrs[MPI_GRAPH_CREATE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_GRAPH_CREATE_T], comm_old, nnodes, indx,
            edges, reorder, comm_graph);
}
#else /* ENABLE_QMPI */
int MPI_Graph_create(MPI_Comm comm_old, int nnodes, const int indx[], const int edges[],
                     int reorder, MPI_Comm *comm_graph)
{
    return internal_Graph_create(comm_old, nnodes, indx, edges, reorder, comm_graph);
}

#endif /* ENABLE_QMPI */
