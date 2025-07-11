/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Probe */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Probe = PMPI_Probe
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Probe  MPI_Probe
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Probe as PMPI_Probe
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Probe(int source, int tag, MPI_Comm comm, MPI_Status *status)
     __attribute__ ((weak, alias("PMPI_Probe")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Probe
#define MPI_Probe PMPI_Probe
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Probe(int source, int tag, MPI_Comm comm, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Comm *comm_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COMM(comm, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_Comm_get_ptr(comm, comm_ptr);

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_Comm_valid_ptr(comm_ptr, mpi_errno, FALSE);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_ERRTEST_RECV_RANK(comm_ptr, source, mpi_errno);
            MPIR_ERRTEST_RECV_TAG(tag, mpi_errno);
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* Return immediately for dummy process */
    if (unlikely(source == MPI_PROC_NULL)) {
        MPIR_Status_set_procnull(status);
        goto fn_exit;
    }

    /* ... body of routine ... */
    mpi_errno = MPID_Probe(source, tag, comm_ptr, 0, status);
    if (mpi_errno != MPI_SUCCESS)
        goto fn_fail;
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    MPID_THREAD_CS_EXIT(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_probe", "**mpi_probe %i %t %C %p", source, tag, comm,
                                     status);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Probe(QMPI_Context context, int tool_id, int source, int tag, MPI_Comm comm,
               MPI_Status *status)
{
    return internal_Probe(source, tag, comm, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Probe(int source, int tag, MPI_Comm comm, MPI_Status *status)
{
    QMPI_Context context;
    QMPI_Probe_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Probe(context, 0, source, tag, comm, status);

    fn_ptr = (QMPI_Probe_t *) MPIR_QMPI_first_fn_ptrs[MPI_PROBE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_PROBE_T], source, tag, comm, status);
}
#else /* ENABLE_QMPI */
int MPI_Probe(int source, int tag, MPI_Comm comm, MPI_Status *status)
{
    return internal_Probe(source, tag, comm, status);
}

#endif /* ENABLE_QMPI */
