/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_T_event_set_dropped_handler */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_T_event_set_dropped_handler = PMPI_T_event_set_dropped_handler
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_T_event_set_dropped_handler  MPI_T_event_set_dropped_handler
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_T_event_set_dropped_handler as PMPI_T_event_set_dropped_handler
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_T_event_set_dropped_handler(MPI_T_event_registration event_registration,
                                    MPI_T_event_dropped_cb_function dropped_cb_function)
                                     __attribute__ ((weak, alias("PMPI_T_event_set_dropped_handler")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_T_event_set_dropped_handler
#define MPI_T_event_set_dropped_handler PMPI_T_event_set_dropped_handler
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_T_event_set_dropped_handler(MPI_T_event_registration event_registration,
                                                MPI_T_event_dropped_cb_function dropped_cb_function)
{
    int mpi_errno = MPI_SUCCESS;

    MPIT_ERRTEST_MPIT_INITIALIZED();

    MPIR_T_THREAD_CS_ENTER();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIT_ERRTEST_EVENT_REG_HANDLE(event_registration);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_T_event_set_dropped_handler_impl(event_registration, dropped_cb_function);
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
int QMPI_T_event_set_dropped_handler(QMPI_Context context, int tool_id,
                                     MPI_T_event_registration event_registration,
                                     MPI_T_event_dropped_cb_function dropped_cb_function)
{
    return internal_T_event_set_dropped_handler(event_registration, dropped_cb_function);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_T_event_set_dropped_handler(MPI_T_event_registration event_registration,
                                    MPI_T_event_dropped_cb_function dropped_cb_function)
{
    QMPI_Context context;
    QMPI_T_event_set_dropped_handler_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_T_event_set_dropped_handler(context, 0, event_registration,
                                                dropped_cb_function);

    fn_ptr = (QMPI_T_event_set_dropped_handler_t *) MPIR_QMPI_first_fn_ptrs[MPI_T_EVENT_SET_DROPPED_HANDLER_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_T_EVENT_SET_DROPPED_HANDLER_T],
            event_registration, dropped_cb_function);
}
#else /* ENABLE_QMPI */
int MPI_T_event_set_dropped_handler(MPI_T_event_registration event_registration,
                                    MPI_T_event_dropped_cb_function dropped_cb_function)
{
    return internal_T_event_set_dropped_handler(event_registration, dropped_cb_function);
}

#endif /* ENABLE_QMPI */
