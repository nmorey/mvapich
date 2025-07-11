/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_T_event_register_callback */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_T_event_register_callback = PMPI_T_event_register_callback
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_T_event_register_callback  MPI_T_event_register_callback
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_T_event_register_callback as PMPI_T_event_register_callback
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_T_event_register_callback(MPI_T_event_registration event_registration,
                                  MPI_T_cb_safety cb_safety, MPI_Info info, void *user_data,
                                  MPI_T_event_cb_function event_cb_function)
                                   __attribute__ ((weak, alias("PMPI_T_event_register_callback")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_T_event_register_callback
#define MPI_T_event_register_callback PMPI_T_event_register_callback
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_T_event_register_callback(MPI_T_event_registration event_registration,
                                              MPI_T_cb_safety cb_safety, MPI_Info info,
                                              void *user_data,
                                              MPI_T_event_cb_function event_cb_function)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Info *info_ptr ATTRIBUTE((unused)) = NULL;

    MPIT_ERRTEST_MPIT_INITIALIZED();

    MPIR_T_THREAD_CS_ENTER();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_INFO_OR_NULL(info, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    if (info != MPI_INFO_NULL) {
        MPIR_Info_get_ptr(info, info_ptr);
    }

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            if (info != MPI_INFO_NULL) {
                MPIR_Info_valid_ptr(info_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            MPIT_ERRTEST_EVENT_REG_HANDLE(event_registration);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_T_event_register_callback_impl(event_registration, cb_safety, info_ptr, user_data,
                                                    event_cb_function);
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
int QMPI_T_event_register_callback(QMPI_Context context, int tool_id,
                                   MPI_T_event_registration event_registration,
                                   MPI_T_cb_safety cb_safety, MPI_Info info, void *user_data,
                                   MPI_T_event_cb_function event_cb_function)
{
    return internal_T_event_register_callback(event_registration, cb_safety, info, user_data, event_cb_function);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_T_event_register_callback(MPI_T_event_registration event_registration,
                                  MPI_T_cb_safety cb_safety, MPI_Info info, void *user_data,
                                  MPI_T_event_cb_function event_cb_function)
{
    QMPI_Context context;
    QMPI_T_event_register_callback_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_T_event_register_callback(context, 0, event_registration, cb_safety, info,
                                              user_data, event_cb_function);

    fn_ptr = (QMPI_T_event_register_callback_t *) MPIR_QMPI_first_fn_ptrs[MPI_T_EVENT_REGISTER_CALLBACK_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_T_EVENT_REGISTER_CALLBACK_T],
            event_registration, cb_safety, info, user_data, event_cb_function);
}
#else /* ENABLE_QMPI */
int MPI_T_event_register_callback(MPI_T_event_registration event_registration,
                                  MPI_T_cb_safety cb_safety, MPI_Info info, void *user_data,
                                  MPI_T_event_cb_function event_cb_function)
{
    return internal_T_event_register_callback(event_registration, cb_safety, info, user_data, event_cb_function);
}

#endif /* ENABLE_QMPI */
