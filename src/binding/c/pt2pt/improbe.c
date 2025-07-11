/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Improbe */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Improbe = PMPI_Improbe
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Improbe  MPI_Improbe
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Improbe as PMPI_Improbe
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Improbe(int source, int tag, MPI_Comm comm, int *flag, MPI_Message *message,
                MPI_Status *status)  __attribute__ ((weak, alias("PMPI_Improbe")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Improbe
#define MPI_Improbe PMPI_Improbe
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Improbe(int source, int tag, MPI_Comm comm, int *flag, MPI_Message *message,
                            MPI_Status *status)
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
            MPIR_ERRTEST_ARGNULL(flag, "flag", mpi_errno);
            MPIR_ERRTEST_ARGNULL(message, "message", mpi_errno);
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* Return immediately for dummy process */
    if (unlikely(source == MPI_PROC_NULL)) {
        *message = MPI_MESSAGE_NO_PROC;
        MPIR_Status_set_procnull(status);
        *flag = TRUE;
        goto fn_exit;
    }

    /* ... body of routine ... */
    MPIR_Request *msgp = NULL;

    *message = MPI_MESSAGE_NULL;
    mpi_errno = MPID_Improbe(source, tag, comm_ptr, 0, flag, &msgp, status);
    MPIR_ERR_CHECK(mpi_errno);

    if (*flag) {
        MPIR_Assert(msgp != NULL);
        *message = msgp->handle;
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
                                     "**mpi_improbe", "**mpi_improbe %i %t %C %p %p %p", source, tag,
                                     comm, flag, message, status);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Improbe(QMPI_Context context, int tool_id, int source, int tag, MPI_Comm comm, int *flag,
                 MPI_Message *message, MPI_Status *status)
{
    return internal_Improbe(source, tag, comm, flag, message, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Improbe(int source, int tag, MPI_Comm comm, int *flag, MPI_Message *message,
                MPI_Status *status)
{
    QMPI_Context context;
    QMPI_Improbe_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Improbe(context, 0, source, tag, comm, flag, message, status);

    fn_ptr = (QMPI_Improbe_t *) MPIR_QMPI_first_fn_ptrs[MPI_IMPROBE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_IMPROBE_T], source, tag, comm, flag,
            message, status);
}
#else /* ENABLE_QMPI */
int MPI_Improbe(int source, int tag, MPI_Comm comm, int *flag, MPI_Message *message,
                MPI_Status *status)
{
    return internal_Improbe(source, tag, comm, flag, message, status);
}

#endif /* ENABLE_QMPI */
