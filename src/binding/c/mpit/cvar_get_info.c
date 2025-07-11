/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_T_cvar_get_info */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_T_cvar_get_info = PMPI_T_cvar_get_info
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_T_cvar_get_info  MPI_T_cvar_get_info
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_T_cvar_get_info as PMPI_T_cvar_get_info
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_T_cvar_get_info(int cvar_index, char *name, int *name_len, int *verbosity,
                        MPI_Datatype *datatype, MPI_T_enum *enumtype, char *desc, int *desc_len,
                        int *bind, int *scope)
                         __attribute__ ((weak, alias("PMPI_T_cvar_get_info")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_T_cvar_get_info
#define MPI_T_cvar_get_info PMPI_T_cvar_get_info
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_T_cvar_get_info(int cvar_index, char *name, int *name_len, int *verbosity,
                                    MPI_Datatype *datatype, MPI_T_enum *enumtype, char *desc,
                                    int *desc_len, int *bind, int *scope)
{
    int mpi_errno = MPI_SUCCESS;

    MPIT_ERRTEST_MPIT_INITIALIZED();

    MPIR_T_THREAD_CS_ENTER();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIT_ERRTEST_CVAR_INDEX(cvar_index);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    cvar_table_entry_t *cvar;
    cvar = (cvar_table_entry_t *) utarray_eltptr(cvar_table, cvar_index);

    MPIR_T_strncpy(name, cvar->name, name_len);
    MPIR_T_strncpy(desc, cvar->desc, desc_len);

    if (verbosity != NULL)
        *verbosity = cvar->verbosity;

    if (datatype != NULL)
        *datatype = cvar->datatype;

    if (enumtype != NULL)
        *enumtype = cvar->enumtype;

    if (bind!= NULL)
        *bind= cvar->bind;

    if (scope != NULL)
        *scope = cvar->scope;
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
int QMPI_T_cvar_get_info(QMPI_Context context, int tool_id, int cvar_index, char *name,
                         int *name_len, int *verbosity, MPI_Datatype *datatype,
                         MPI_T_enum *enumtype, char *desc, int *desc_len, int *bind, int *scope)
{
    return internal_T_cvar_get_info(cvar_index, name, name_len, verbosity, datatype, enumtype, desc, desc_len, bind, scope);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_T_cvar_get_info(int cvar_index, char *name, int *name_len, int *verbosity,
                        MPI_Datatype *datatype, MPI_T_enum *enumtype, char *desc, int *desc_len,
                        int *bind, int *scope)
{
    QMPI_Context context;
    QMPI_T_cvar_get_info_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_T_cvar_get_info(context, 0, cvar_index, name, name_len, verbosity, datatype,
                                    enumtype, desc, desc_len, bind, scope);

    fn_ptr = (QMPI_T_cvar_get_info_t *) MPIR_QMPI_first_fn_ptrs[MPI_T_CVAR_GET_INFO_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_T_CVAR_GET_INFO_T], cvar_index, name,
            name_len, verbosity, datatype, enumtype, desc, desc_len, bind, scope);
}
#else /* ENABLE_QMPI */
int MPI_T_cvar_get_info(int cvar_index, char *name, int *name_len, int *verbosity,
                        MPI_Datatype *datatype, MPI_T_enum *enumtype, char *desc, int *desc_len,
                        int *bind, int *scope)
{
    return internal_T_cvar_get_info(cvar_index, name, name_len, verbosity, datatype, enumtype, desc, desc_len, bind, scope);
}

#endif /* ENABLE_QMPI */
