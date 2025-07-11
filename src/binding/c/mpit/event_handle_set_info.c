/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_T_event_handle_set_info */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_T_event_handle_set_info = PMPI_T_event_handle_set_info
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_T_event_handle_set_info  MPI_T_event_handle_set_info
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_T_event_handle_set_info as PMPI_T_event_handle_set_info
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_T_event_handle_set_info(MPI_T_event_registration event_registration, MPI_Info info)
     __attribute__ ((weak, alias("PMPI_T_event_handle_set_info")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_T_event_handle_set_info
#define MPI_T_event_handle_set_info PMPI_T_event_handle_set_info
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_T_event_handle_set_info(MPI_T_event_registration event_registration,
                                            MPI_Info info)
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
            MPIR_ERRTEST_INFO(info, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_Info_get_ptr(info, info_ptr);

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_Info_valid_ptr(info_ptr, mpi_errno);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIT_ERRTEST_EVENT_REG_HANDLE(event_registration);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_T_event_handle_set_info_impl(event_registration, info_ptr);
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
int QMPI_T_event_handle_set_info(QMPI_Context context, int tool_id,
                                 MPI_T_event_registration event_registration, MPI_Info info)
{
    return internal_T_event_handle_set_info(event_registration, info);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_T_event_handle_set_info(MPI_T_event_registration event_registration, MPI_Info info)
{
    QMPI_Context context;
    QMPI_T_event_handle_set_info_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_T_event_handle_set_info(context, 0, event_registration, info);

    fn_ptr = (QMPI_T_event_handle_set_info_t *) MPIR_QMPI_first_fn_ptrs[MPI_T_EVENT_HANDLE_SET_INFO_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_T_EVENT_HANDLE_SET_INFO_T],
            event_registration, info);
}
#else /* ENABLE_QMPI */
int MPI_T_event_handle_set_info(MPI_T_event_registration event_registration, MPI_Info info)
{
    return internal_T_event_handle_set_info(event_registration, info);
}

#endif /* ENABLE_QMPI */
