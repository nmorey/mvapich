/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_T_event_read */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_T_event_read = PMPI_T_event_read
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_T_event_read  MPI_T_event_read
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_T_event_read as PMPI_T_event_read
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_T_event_read(MPI_T_event_instance event_instance, int element_index, void *buffer)
     __attribute__ ((weak, alias("PMPI_T_event_read")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_T_event_read
#define MPI_T_event_read PMPI_T_event_read
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_T_event_read(MPI_T_event_instance event_instance, int element_index,
                                 void *buffer)
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
            MPIT_ERRTEST_ARGNEG(element_index);
            MPIT_ERRTEST_ARGNULL(buffer);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_T_event_read_impl(event_instance, element_index, buffer);
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
int QMPI_T_event_read(QMPI_Context context, int tool_id, MPI_T_event_instance event_instance,
                      int element_index, void *buffer)
{
    return internal_T_event_read(event_instance, element_index, buffer);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_T_event_read(MPI_T_event_instance event_instance, int element_index, void *buffer)
{
    QMPI_Context context;
    QMPI_T_event_read_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_T_event_read(context, 0, event_instance, element_index, buffer);

    fn_ptr = (QMPI_T_event_read_t *) MPIR_QMPI_first_fn_ptrs[MPI_T_EVENT_READ_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_T_EVENT_READ_T], event_instance,
            element_index, buffer);
}
#else /* ENABLE_QMPI */
int MPI_T_event_read(MPI_T_event_instance event_instance, int element_index, void *buffer)
{
    return internal_T_event_read(event_instance, element_index, buffer);
}

#endif /* ENABLE_QMPI */
