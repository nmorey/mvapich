/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_T_cvar_write */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_T_cvar_write = PMPI_T_cvar_write
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_T_cvar_write  MPI_T_cvar_write
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_T_cvar_write as PMPI_T_cvar_write
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_T_cvar_write(MPI_T_cvar_handle handle, const void *buf)
     __attribute__ ((weak, alias("PMPI_T_cvar_write")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_T_cvar_write
#define MPI_T_cvar_write PMPI_T_cvar_write
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_T_cvar_write(MPI_T_cvar_handle handle, const void *buf)
{
    int mpi_errno = MPI_SUCCESS;

    MPIT_ERRTEST_MPIT_INITIALIZED();

    MPIR_T_THREAD_CS_ENTER();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIT_ERRTEST_CVAR_HANDLE(handle);
            MPIT_ERRTEST_ARGNULL(buf);
            MPIR_T_cvar_handle_t *hnd = handle;

            if (hnd->scope == MPI_T_SCOPE_CONSTANT) {
                mpi_errno = MPI_T_ERR_CVAR_SET_NEVER;
                goto fn_fail;
            } else if (hnd->scope == MPI_T_SCOPE_READONLY) {
                mpi_errno = MPI_T_ERR_CVAR_SET_NOT_NOW;
                goto fn_fail;
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_T_cvar_write_impl(handle, buf);
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
int QMPI_T_cvar_write(QMPI_Context context, int tool_id, MPI_T_cvar_handle handle, const void *buf)
{
    return internal_T_cvar_write(handle, buf);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_T_cvar_write(MPI_T_cvar_handle handle, const void *buf)
{
    QMPI_Context context;
    QMPI_T_cvar_write_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_T_cvar_write(context, 0, handle, buf);

    fn_ptr = (QMPI_T_cvar_write_t *) MPIR_QMPI_first_fn_ptrs[MPI_T_CVAR_WRITE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_T_CVAR_WRITE_T], handle, buf);
}
#else /* ENABLE_QMPI */
int MPI_T_cvar_write(MPI_T_cvar_handle handle, const void *buf)
{
    return internal_T_cvar_write(handle, buf);
}

#endif /* ENABLE_QMPI */
