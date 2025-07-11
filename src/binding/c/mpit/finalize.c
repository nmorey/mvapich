/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_T_finalize */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_T_finalize = PMPI_T_finalize
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_T_finalize  MPI_T_finalize
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_T_finalize as PMPI_T_finalize
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_T_finalize(void)  __attribute__ ((weak, alias("PMPI_T_finalize")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_T_finalize
#define MPI_T_finalize PMPI_T_finalize
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_T_finalize(void)
{
    int mpi_errno = MPI_SUCCESS;

    MPIT_ERRTEST_MPIT_INITIALIZED();
    MPIR_FUNC_TERSE_ENTER;

    /* ... body of routine ... */
    --MPIR_T_init_balance;
    if (MPIR_T_init_balance < 0) {
        mpi_errno = MPI_T_ERR_NOT_INITIALIZED;
        goto fn_fail;
    }

    if (MPIR_T_init_balance == 0) {
        MPIR_T_THREAD_CS_FINALIZE();
        MPIR_T_env_finalize();
    }
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    return mpi_errno;

  fn_fail:
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_T_finalize(QMPI_Context context, int tool_id)
{
    return internal_T_finalize();
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_T_finalize(void)
{
    QMPI_Context context;
    QMPI_T_finalize_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_T_finalize(context, 0);

    fn_ptr = (QMPI_T_finalize_t *) MPIR_QMPI_first_fn_ptrs[MPI_T_FINALIZE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_T_FINALIZE_T]);
}
#else /* ENABLE_QMPI */
int MPI_T_finalize(void)
{
    return internal_T_finalize();
}

#endif /* ENABLE_QMPI */
