/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_T_enum_get_item */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_T_enum_get_item = PMPI_T_enum_get_item
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_T_enum_get_item  MPI_T_enum_get_item
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_T_enum_get_item as PMPI_T_enum_get_item
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_T_enum_get_item(MPI_T_enum enumtype, int indx, int *value, char *name, int *name_len)
     __attribute__ ((weak, alias("PMPI_T_enum_get_item")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_T_enum_get_item
#define MPI_T_enum_get_item PMPI_T_enum_get_item
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_T_enum_get_item(MPI_T_enum enumtype, int indx, int *value, char *name,
                                    int *name_len)
{
    int mpi_errno = MPI_SUCCESS;

    MPIT_ERRTEST_MPIT_INITIALIZED();

    MPIR_T_THREAD_CS_ENTER();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIT_ERRTEST_ENUM_HANDLE(enumtype);
            MPIT_ERRTEST_ENUM_ITEM(enumtype, indx);
            MPIT_ERRTEST_ARGNULL(value);
            MPIT_ERRTEST_ARGNULL(name);
            MPIT_ERRTEST_ARGNULL(name_len);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    enum_item_t *item;
    item = (enum_item_t *) utarray_eltptr(enumtype->items, indx);
    *value = item->value;
    MPIR_T_strncpy(name, item->name, name_len);
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
int QMPI_T_enum_get_item(QMPI_Context context, int tool_id, MPI_T_enum enumtype, int indx,
                         int *value, char *name, int *name_len)
{
    return internal_T_enum_get_item(enumtype, indx, value, name, name_len);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_T_enum_get_item(MPI_T_enum enumtype, int indx, int *value, char *name, int *name_len)
{
    QMPI_Context context;
    QMPI_T_enum_get_item_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_T_enum_get_item(context, 0, enumtype, indx, value, name, name_len);

    fn_ptr = (QMPI_T_enum_get_item_t *) MPIR_QMPI_first_fn_ptrs[MPI_T_ENUM_GET_ITEM_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_T_ENUM_GET_ITEM_T], enumtype, indx,
            value, name, name_len);
}
#else /* ENABLE_QMPI */
int MPI_T_enum_get_item(MPI_T_enum enumtype, int indx, int *value, char *name, int *name_len)
{
    return internal_T_enum_get_item(enumtype, indx, value, name, name_len);
}

#endif /* ENABLE_QMPI */
