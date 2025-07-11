/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Close_port */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Close_port = PMPI_Close_port
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Close_port  MPI_Close_port
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Close_port as PMPI_Close_port
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Close_port(const char *port_name)  __attribute__ ((weak, alias("PMPI_Close_port")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Close_port
#define MPI_Close_port PMPI_Close_port
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Close_port(const char *port_name)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(port_name, "port_name", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Close_port_impl(port_name);
    if (mpi_errno) {
        goto fn_fail;
    }
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    MPID_THREAD_CS_EXIT(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_close_port", "**mpi_close_port %s", port_name);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Close_port(QMPI_Context context, int tool_id, const char *port_name)
{
    return internal_Close_port(port_name);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Close_port(const char *port_name)
{
    QMPI_Context context;
    QMPI_Close_port_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Close_port(context, 0, port_name);

    fn_ptr = (QMPI_Close_port_t *) MPIR_QMPI_first_fn_ptrs[MPI_CLOSE_PORT_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_CLOSE_PORT_T], port_name);
}
#else /* ENABLE_QMPI */
int MPI_Close_port(const char *port_name)
{
    return internal_Close_port(port_name);
}

#endif /* ENABLE_QMPI */
