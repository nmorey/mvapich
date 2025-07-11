/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_T_category_changed */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_T_category_changed = PMPI_T_category_changed
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_T_category_changed  MPI_T_category_changed
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_T_category_changed as PMPI_T_category_changed
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_T_category_changed(int *update_number)
     __attribute__ ((weak, alias("PMPI_T_category_changed")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_T_category_changed
#define MPI_T_category_changed PMPI_T_category_changed
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_T_category_changed(int *update_number)
{
    int mpi_errno = MPI_SUCCESS;

    MPIT_ERRTEST_MPIT_INITIALIZED();

    MPIR_T_THREAD_CS_ENTER();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIT_ERRTEST_ARGNULL(update_number);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    *update_number = cat_stamp;
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
int QMPI_T_category_changed(QMPI_Context context, int tool_id, int *update_number)
{
    return internal_T_category_changed(update_number);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_T_category_changed(int *update_number)
{
    QMPI_Context context;
    QMPI_T_category_changed_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_T_category_changed(context, 0, update_number);

    fn_ptr = (QMPI_T_category_changed_t *) MPIR_QMPI_first_fn_ptrs[MPI_T_CATEGORY_CHANGED_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_T_CATEGORY_CHANGED_T], update_number);
}
#else /* ENABLE_QMPI */
int MPI_T_category_changed(int *update_number)
{
    return internal_T_category_changed(update_number);
}

#endif /* ENABLE_QMPI */
