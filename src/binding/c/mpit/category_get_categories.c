/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_T_category_get_categories */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_T_category_get_categories = PMPI_T_category_get_categories
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_T_category_get_categories  MPI_T_category_get_categories
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_T_category_get_categories as PMPI_T_category_get_categories
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_T_category_get_categories(int cat_index, int len, int indices[])
     __attribute__ ((weak, alias("PMPI_T_category_get_categories")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_T_category_get_categories
#define MPI_T_category_get_categories PMPI_T_category_get_categories
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_T_category_get_categories(int cat_index, int len, int indices[])
{
    int mpi_errno = MPI_SUCCESS;

    MPIT_ERRTEST_MPIT_INITIALIZED();

    MPIR_T_THREAD_CS_ENTER();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIT_ERRTEST_CAT_INDEX(cat_index);
            MPIT_ERRTEST_ARGNEG(len);
            if (len != 0) {
                MPIT_ERRTEST_ARGNULL(indices);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    if (len == 0) {
        goto fn_exit;
    }

    /* ... body of routine ... */
    mpi_errno = MPIR_T_category_get_categories_impl(cat_index, len, indices);
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
int QMPI_T_category_get_categories(QMPI_Context context, int tool_id, int cat_index, int len,
                                   int indices[])
{
    return internal_T_category_get_categories(cat_index, len, indices);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_T_category_get_categories(int cat_index, int len, int indices[])
{
    QMPI_Context context;
    QMPI_T_category_get_categories_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_T_category_get_categories(context, 0, cat_index, len, indices);

    fn_ptr = (QMPI_T_category_get_categories_t *) MPIR_QMPI_first_fn_ptrs[MPI_T_CATEGORY_GET_CATEGORIES_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_T_CATEGORY_GET_CATEGORIES_T], cat_index,
            len, indices);
}
#else /* ENABLE_QMPI */
int MPI_T_category_get_categories(int cat_index, int len, int indices[])
{
    return internal_T_category_get_categories(cat_index, len, indices);
}

#endif /* ENABLE_QMPI */
