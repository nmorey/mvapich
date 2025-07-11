/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Session_finalize */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Session_finalize = PMPI_Session_finalize
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Session_finalize  MPI_Session_finalize
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Session_finalize as PMPI_Session_finalize
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Session_finalize(MPI_Session *session)
     __attribute__ ((weak, alias("PMPI_Session_finalize")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Session_finalize
#define MPI_Session_finalize PMPI_Session_finalize
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Session_finalize(MPI_Session *session)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Session *session_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(session, "session", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_Session_get_ptr(*session, session_ptr);

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_Session_valid_ptr(session_ptr, mpi_errno);
            if (mpi_errno) {
                goto fn_fail;
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Session_finalize_impl(session_ptr);
    if (mpi_errno) {
        goto fn_fail;
    }
    *session = MPI_SESSION_NULL;
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_session_finalize", "**mpi_session_finalize %p", session);
#endif
    mpi_errno = MPIR_Err_return_session(session_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Session_finalize(QMPI_Context context, int tool_id, MPI_Session *session)
{
    return internal_Session_finalize(session);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Session_finalize(MPI_Session *session)
{
    QMPI_Context context;
    QMPI_Session_finalize_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Session_finalize(context, 0, session);

    fn_ptr = (QMPI_Session_finalize_t *) MPIR_QMPI_first_fn_ptrs[MPI_SESSION_FINALIZE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_SESSION_FINALIZE_T], session);
}
#else /* ENABLE_QMPI */
int MPI_Session_finalize(MPI_Session *session)
{
    return internal_Session_finalize(session);
}

#endif /* ENABLE_QMPI */
