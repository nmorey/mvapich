/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Comm_get_parent */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Comm_get_parent = PMPI_Comm_get_parent
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Comm_get_parent  MPI_Comm_get_parent
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Comm_get_parent as PMPI_Comm_get_parent
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Comm_get_parent(MPI_Comm *parent)  __attribute__ ((weak, alias("PMPI_Comm_get_parent")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Comm_get_parent
#define MPI_Comm_get_parent PMPI_Comm_get_parent
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Comm_get_parent(MPI_Comm *parent)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(parent, "parent", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Comm_get_parent_impl(parent);
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
                                     "**mpi_comm_get_parent", "**mpi_comm_get_parent %p", parent);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Comm_get_parent(QMPI_Context context, int tool_id, MPI_Comm *parent)
{
    return internal_Comm_get_parent(parent);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Comm_get_parent(MPI_Comm *parent)
{
    QMPI_Context context;
    QMPI_Comm_get_parent_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Comm_get_parent(context, 0, parent);

    fn_ptr = (QMPI_Comm_get_parent_t *) MPIR_QMPI_first_fn_ptrs[MPI_COMM_GET_PARENT_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_COMM_GET_PARENT_T], parent);
}
#else /* ENABLE_QMPI */
int MPI_Comm_get_parent(MPI_Comm *parent)
{
    return internal_Comm_get_parent(parent);
}

#endif /* ENABLE_QMPI */
