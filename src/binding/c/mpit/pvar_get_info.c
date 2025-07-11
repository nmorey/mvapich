/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_T_pvar_get_info */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_T_pvar_get_info = PMPI_T_pvar_get_info
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_T_pvar_get_info  MPI_T_pvar_get_info
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_T_pvar_get_info as PMPI_T_pvar_get_info
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_T_pvar_get_info(int pvar_index, char *name, int *name_len, int *verbosity, int *var_class,
                        MPI_Datatype *datatype, MPI_T_enum *enumtype, char *desc, int *desc_len,
                        int *bind, int *readonly, int *continuous, int *atomic)
                         __attribute__ ((weak, alias("PMPI_T_pvar_get_info")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_T_pvar_get_info
#define MPI_T_pvar_get_info PMPI_T_pvar_get_info
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_T_pvar_get_info(int pvar_index, char *name, int *name_len, int *verbosity,
                                    int *var_class, MPI_Datatype *datatype, MPI_T_enum *enumtype,
                                    char *desc, int *desc_len, int *bind, int *readonly,
                                    int *continuous, int *atomic)
{
    int mpi_errno = MPI_SUCCESS;

    MPIT_ERRTEST_MPIT_INITIALIZED();

    MPIR_T_THREAD_CS_ENTER();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIT_ERRTEST_CVAR_INDEX(pvar_index);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    pvar_table_entry_t *entry;
    entry = (pvar_table_entry_t *) utarray_eltptr(pvar_table, pvar_index);
    if (!entry->active) {
        mpi_errno = MPI_T_ERR_INVALID_INDEX;
        goto fn_fail;
    }

    pvar_table_entry_t *info;
    info = (pvar_table_entry_t *) utarray_eltptr(pvar_table, pvar_index);

    MPIR_T_strncpy(name, info->name, name_len);
    MPIR_T_strncpy(desc, info->desc, desc_len);

    if (verbosity != NULL)
        *verbosity = info->verbosity;

    if (var_class != NULL)
        *var_class = info->varclass;

    if (datatype != NULL)
        *datatype = info->datatype;

    if (enumtype != NULL)
        *enumtype = info->enumtype;

    if (bind != NULL)
        *bind = info->bind;

    if (readonly != NULL)
        *readonly = info->flags & MPIR_T_PVAR_FLAG_READONLY;

    if (continuous != NULL)
        *continuous = info->flags & MPIR_T_PVAR_FLAG_CONTINUOUS;

    if (atomic != NULL)
        *atomic = info->flags & MPIR_T_PVAR_FLAG_ATOMIC;
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
int QMPI_T_pvar_get_info(QMPI_Context context, int tool_id, int pvar_index, char *name,
                         int *name_len, int *verbosity, int *var_class, MPI_Datatype *datatype,
                         MPI_T_enum *enumtype, char *desc, int *desc_len, int *bind, int *readonly,
                         int *continuous, int *atomic)
{
    return internal_T_pvar_get_info(pvar_index, name, name_len, verbosity, var_class, datatype, enumtype, desc, desc_len, bind, readonly, continuous, atomic);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_T_pvar_get_info(int pvar_index, char *name, int *name_len, int *verbosity, int *var_class,
                        MPI_Datatype *datatype, MPI_T_enum *enumtype, char *desc, int *desc_len,
                        int *bind, int *readonly, int *continuous, int *atomic)
{
    QMPI_Context context;
    QMPI_T_pvar_get_info_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_T_pvar_get_info(context, 0, pvar_index, name, name_len, verbosity, var_class,
                                    datatype, enumtype, desc, desc_len, bind, readonly, continuous,
                                    atomic);

    fn_ptr = (QMPI_T_pvar_get_info_t *) MPIR_QMPI_first_fn_ptrs[MPI_T_PVAR_GET_INFO_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_T_PVAR_GET_INFO_T], pvar_index, name,
            name_len, verbosity, var_class, datatype, enumtype, desc, desc_len, bind, readonly,
            continuous, atomic);
}
#else /* ENABLE_QMPI */
int MPI_T_pvar_get_info(int pvar_index, char *name, int *name_len, int *verbosity, int *var_class,
                        MPI_Datatype *datatype, MPI_T_enum *enumtype, char *desc, int *desc_len,
                        int *bind, int *readonly, int *continuous, int *atomic)
{
    return internal_T_pvar_get_info(pvar_index, name, name_len, verbosity, var_class, datatype, enumtype, desc, desc_len, bind, readonly, continuous, atomic);
}

#endif /* ENABLE_QMPI */
