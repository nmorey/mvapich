/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_T_event_get_source */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_T_event_get_source = PMPI_T_event_get_source
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_T_event_get_source  MPI_T_event_get_source
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_T_event_get_source as PMPI_T_event_get_source
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_T_event_get_source(MPI_T_event_instance event_instance, int *source_index)
     __attribute__ ((weak, alias("PMPI_T_event_get_source")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_T_event_get_source
#define MPI_T_event_get_source PMPI_T_event_get_source
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_T_event_get_source(MPI_T_event_instance event_instance, int *source_index)
{
    int mpi_errno = MPI_SUCCESS;

    MPIT_ERRTEST_MPIT_INITIALIZED();

    MPIR_T_THREAD_CS_ENTER();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIT_ERRTEST_EVENT_INSTANCE_HANDLE(event_instance);
            MPIT_ERRTEST_ARGNULL(source_index);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_T_event_get_source_impl(event_instance, source_index);
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
int QMPI_T_event_get_source(QMPI_Context context, int tool_id, MPI_T_event_instance event_instance,
                            int *source_index)
{
    return internal_T_event_get_source(event_instance, source_index);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_T_event_get_source(MPI_T_event_instance event_instance, int *source_index)
{
    QMPI_Context context;
    QMPI_T_event_get_source_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_T_event_get_source(context, 0, event_instance, source_index);

    fn_ptr = (QMPI_T_event_get_source_t *) MPIR_QMPI_first_fn_ptrs[MPI_T_EVENT_GET_SOURCE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_T_EVENT_GET_SOURCE_T], event_instance,
            source_index);
}
#else /* ENABLE_QMPI */
int MPI_T_event_get_source(MPI_T_event_instance event_instance, int *source_index)
{
    return internal_T_event_get_source(event_instance, source_index);
}

#endif /* ENABLE_QMPI */
