/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_T_source_get_timestamp */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_T_source_get_timestamp = PMPI_T_source_get_timestamp
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_T_source_get_timestamp  MPI_T_source_get_timestamp
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_T_source_get_timestamp as PMPI_T_source_get_timestamp
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_T_source_get_timestamp(int source_index, MPI_Count *timestamp)
     __attribute__ ((weak, alias("PMPI_T_source_get_timestamp")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_T_source_get_timestamp
#define MPI_T_source_get_timestamp PMPI_T_source_get_timestamp
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_T_source_get_timestamp(int source_index, MPI_Count *timestamp)
{
    int mpi_errno = MPI_SUCCESS;

    MPIT_ERRTEST_MPIT_INITIALIZED();

    MPIR_T_THREAD_CS_ENTER();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIT_ERRTEST_ARGNULL(timestamp);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_T_source_get_timestamp_impl(source_index, timestamp);
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
int QMPI_T_source_get_timestamp(QMPI_Context context, int tool_id, int source_index,
                                MPI_Count *timestamp)
{
    return internal_T_source_get_timestamp(source_index, timestamp);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_T_source_get_timestamp(int source_index, MPI_Count *timestamp)
{
    QMPI_Context context;
    QMPI_T_source_get_timestamp_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_T_source_get_timestamp(context, 0, source_index, timestamp);

    fn_ptr = (QMPI_T_source_get_timestamp_t *) MPIR_QMPI_first_fn_ptrs[MPI_T_SOURCE_GET_TIMESTAMP_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_T_SOURCE_GET_TIMESTAMP_T], source_index,
            timestamp);
}
#else /* ENABLE_QMPI */
int MPI_T_source_get_timestamp(int source_index, MPI_Count *timestamp)
{
    return internal_T_source_get_timestamp(source_index, timestamp);
}

#endif /* ENABLE_QMPI */
