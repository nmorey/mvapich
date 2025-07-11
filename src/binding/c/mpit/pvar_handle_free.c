/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_T_pvar_handle_free */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_T_pvar_handle_free = PMPI_T_pvar_handle_free
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_T_pvar_handle_free  MPI_T_pvar_handle_free
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_T_pvar_handle_free as PMPI_T_pvar_handle_free
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_T_pvar_handle_free(MPI_T_pvar_session session, MPI_T_pvar_handle *handle)
     __attribute__ ((weak, alias("PMPI_T_pvar_handle_free")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_T_pvar_handle_free
#define MPI_T_pvar_handle_free PMPI_T_pvar_handle_free
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_T_pvar_handle_free(MPI_T_pvar_session session, MPI_T_pvar_handle *handle)
{
    int mpi_errno = MPI_SUCCESS;

    MPIT_ERRTEST_MPIT_INITIALIZED();

    MPIR_T_THREAD_CS_ENTER();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIT_ERRTEST_PVAR_SESSION(session);
            MPIT_ERRTEST_PVAR_HANDLE(*handle);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_T_pvar_handle_free_impl(session, handle);
    if (mpi_errno) {
        goto fn_fail;
    }
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    MPIR_T_THREAD_CS_EXIT();
    return mpi_errno;

  fn_fail:
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_T_pvar_handle_free(QMPI_Context context, int tool_id, MPI_T_pvar_session session,
                            MPI_T_pvar_handle *handle)
{
    return internal_T_pvar_handle_free(session, handle);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_T_pvar_handle_free(MPI_T_pvar_session session, MPI_T_pvar_handle *handle)
{
    QMPI_Context context;
    QMPI_T_pvar_handle_free_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_T_pvar_handle_free(context, 0, session, handle);

    fn_ptr = (QMPI_T_pvar_handle_free_t *) MPIR_QMPI_first_fn_ptrs[MPI_T_PVAR_HANDLE_FREE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_T_PVAR_HANDLE_FREE_T], session,
            handle);
}
#else /* ENABLE_QMPI */
int MPI_T_pvar_handle_free(MPI_T_pvar_session session, MPI_T_pvar_handle *handle)
{
    return internal_T_pvar_handle_free(session, handle);
}

#endif /* ENABLE_QMPI */
