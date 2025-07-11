/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_T_event_handle_alloc */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_T_event_handle_alloc = PMPI_T_event_handle_alloc
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_T_event_handle_alloc  MPI_T_event_handle_alloc
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_T_event_handle_alloc as PMPI_T_event_handle_alloc
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_T_event_handle_alloc(int event_index, void *obj_handle, MPI_Info info,
                             MPI_T_event_registration *event_registration)
                              __attribute__ ((weak, alias("PMPI_T_event_handle_alloc")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_T_event_handle_alloc
#define MPI_T_event_handle_alloc PMPI_T_event_handle_alloc
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_T_event_handle_alloc(int event_index, void *obj_handle, MPI_Info info,
                                         MPI_T_event_registration *event_registration)
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
            MPIT_ERRTEST_ARGNULL(event_registration);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_T_event_handle_alloc_impl(event_index, obj_handle, info_ptr, event_registration);
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
int QMPI_T_event_handle_alloc(QMPI_Context context, int tool_id, int event_index, void *obj_handle,
                              MPI_Info info, MPI_T_event_registration *event_registration)
{
    return internal_T_event_handle_alloc(event_index, obj_handle, info, event_registration);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_T_event_handle_alloc(int event_index, void *obj_handle, MPI_Info info,
                             MPI_T_event_registration *event_registration)
{
    QMPI_Context context;
    QMPI_T_event_handle_alloc_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_T_event_handle_alloc(context, 0, event_index, obj_handle, info,
                                         event_registration);

    fn_ptr = (QMPI_T_event_handle_alloc_t *) MPIR_QMPI_first_fn_ptrs[MPI_T_EVENT_HANDLE_ALLOC_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_T_EVENT_HANDLE_ALLOC_T], event_index,
            obj_handle, info, event_registration);
}
#else /* ENABLE_QMPI */
int MPI_T_event_handle_alloc(int event_index, void *obj_handle, MPI_Info info,
                             MPI_T_event_registration *event_registration)
{
    return internal_T_event_handle_alloc(event_index, obj_handle, info, event_registration);
}

#endif /* ENABLE_QMPI */
