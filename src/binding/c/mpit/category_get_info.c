/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_T_category_get_info */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_T_category_get_info = PMPI_T_category_get_info
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_T_category_get_info  MPI_T_category_get_info
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_T_category_get_info as PMPI_T_category_get_info
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_T_category_get_info(int cat_index, char *name, int *name_len, char *desc, int *desc_len,
                            int *num_cvars, int *num_pvars, int *num_categories)
                             __attribute__ ((weak, alias("PMPI_T_category_get_info")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_T_category_get_info
#define MPI_T_category_get_info PMPI_T_category_get_info
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_T_category_get_info(int cat_index, char *name, int *name_len, char *desc,
                                        int *desc_len, int *num_cvars, int *num_pvars,
                                        int *num_categories)
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
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    cat_table_entry_t *cat;
    cat = (cat_table_entry_t *) utarray_eltptr(cat_table, cat_index);
    MPIR_T_strncpy(name, cat->name, name_len);
    MPIR_T_strncpy(desc, cat->desc, desc_len);

    if (num_cvars != NULL)
        *num_cvars = utarray_len(cat->cvar_indices);

    if (num_pvars != NULL)
        *num_pvars = utarray_len(cat->pvar_indices);

    if (num_categories != NULL)
        *num_categories = utarray_len(cat->subcat_indices);
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
int QMPI_T_category_get_info(QMPI_Context context, int tool_id, int cat_index, char *name,
                             int *name_len, char *desc, int *desc_len, int *num_cvars,
                             int *num_pvars, int *num_categories)
{
    return internal_T_category_get_info(cat_index, name, name_len, desc, desc_len, num_cvars, num_pvars, num_categories);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_T_category_get_info(int cat_index, char *name, int *name_len, char *desc, int *desc_len,
                            int *num_cvars, int *num_pvars, int *num_categories)
{
    QMPI_Context context;
    QMPI_T_category_get_info_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_T_category_get_info(context, 0, cat_index, name, name_len, desc, desc_len,
                                        num_cvars, num_pvars, num_categories);

    fn_ptr = (QMPI_T_category_get_info_t *) MPIR_QMPI_first_fn_ptrs[MPI_T_CATEGORY_GET_INFO_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_T_CATEGORY_GET_INFO_T], cat_index, name,
            name_len, desc, desc_len, num_cvars, num_pvars, num_categories);
}
#else /* ENABLE_QMPI */
int MPI_T_category_get_info(int cat_index, char *name, int *name_len, char *desc, int *desc_len,
                            int *num_cvars, int *num_pvars, int *num_categories)
{
    return internal_T_category_get_info(cat_index, name, name_len, desc, desc_len, num_cvars, num_pvars, num_categories);
}

#endif /* ENABLE_QMPI */
