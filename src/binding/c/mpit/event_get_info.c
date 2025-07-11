/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_T_event_get_info */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_T_event_get_info = PMPI_T_event_get_info
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_T_event_get_info  MPI_T_event_get_info
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_T_event_get_info as PMPI_T_event_get_info
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_T_event_get_info(int event_index, char *name, int *name_len, int *verbosity,
                         MPI_Datatype array_of_datatypes[], MPI_Aint array_of_displacements[],
                         int *num_elements, MPI_T_enum *enumtype, MPI_Info *info, char *desc,
                         int *desc_len, int *bind)
                          __attribute__ ((weak, alias("PMPI_T_event_get_info")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_T_event_get_info
#define MPI_T_event_get_info PMPI_T_event_get_info
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_T_event_get_info(int event_index, char *name, int *name_len, int *verbosity,
                                     MPI_Datatype array_of_datatypes[],
                                     MPI_Aint array_of_displacements[], int *num_elements,
                                     MPI_T_enum *enumtype, MPI_Info *info, char *desc,
                                     int *desc_len, int *bind)
{
    int mpi_errno = MPI_SUCCESS;

    MPIT_ERRTEST_MPIT_INITIALIZED();

    MPIR_T_THREAD_CS_ENTER();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIT_ERRTEST_ARGNULL(name_len);
            MPIT_ERRTEST_ARGNULL(verbosity);
            MPIT_ERRTEST_ARGNULL(enumtype);
            MPIT_ERRTEST_ARGNULL(desc_len);
            MPIT_ERRTEST_ARGNULL(bind);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_T_event_get_info_impl(event_index, name, name_len, verbosity, array_of_datatypes,
                                           array_of_displacements, num_elements, enumtype, info, desc,
                                           desc_len, bind);
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
int QMPI_T_event_get_info(QMPI_Context context, int tool_id, int event_index, char *name,
                          int *name_len, int *verbosity, MPI_Datatype array_of_datatypes[],
                          MPI_Aint array_of_displacements[], int *num_elements,
                          MPI_T_enum *enumtype, MPI_Info *info, char *desc, int *desc_len,
                          int *bind)
{
    return internal_T_event_get_info(event_index, name, name_len, verbosity, array_of_datatypes, array_of_displacements, num_elements, enumtype, info, desc, desc_len, bind);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_T_event_get_info(int event_index, char *name, int *name_len, int *verbosity,
                         MPI_Datatype array_of_datatypes[], MPI_Aint array_of_displacements[],
                         int *num_elements, MPI_T_enum *enumtype, MPI_Info *info, char *desc,
                         int *desc_len, int *bind)
{
    QMPI_Context context;
    QMPI_T_event_get_info_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_T_event_get_info(context, 0, event_index, name, name_len, verbosity,
                                     array_of_datatypes, array_of_displacements, num_elements,
                                     enumtype, info, desc, desc_len, bind);

    fn_ptr = (QMPI_T_event_get_info_t *) MPIR_QMPI_first_fn_ptrs[MPI_T_EVENT_GET_INFO_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_T_EVENT_GET_INFO_T], event_index, name,
            name_len, verbosity, array_of_datatypes, array_of_displacements, num_elements, enumtype,
            info, desc, desc_len, bind);
}
#else /* ENABLE_QMPI */
int MPI_T_event_get_info(int event_index, char *name, int *name_len, int *verbosity,
                         MPI_Datatype array_of_datatypes[], MPI_Aint array_of_displacements[],
                         int *num_elements, MPI_T_enum *enumtype, MPI_Info *info, char *desc,
                         int *desc_len, int *bind)
{
    return internal_T_event_get_info(event_index, name, name_len, verbosity, array_of_datatypes, array_of_displacements, num_elements, enumtype, info, desc, desc_len, bind);
}

#endif /* ENABLE_QMPI */
