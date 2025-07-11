/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Session_create_errhandler */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Session_create_errhandler = PMPI_Session_create_errhandler
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Session_create_errhandler  MPI_Session_create_errhandler
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Session_create_errhandler as PMPI_Session_create_errhandler
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Session_create_errhandler(MPI_Session_errhandler_function *session_errhandler_fn,
                                  MPI_Errhandler *errhandler)
                                   __attribute__ ((weak, alias("PMPI_Session_create_errhandler")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Session_create_errhandler
#define MPI_Session_create_errhandler PMPI_Session_create_errhandler
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Session_create_errhandler(MPI_Session_errhandler_function *session_errhandler_fn,
                                              MPI_Errhandler *errhandler)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(session_errhandler_fn, "session_errhandler_fn", mpi_errno);
            MPIR_ERRTEST_ARGNULL(errhandler, "errhandler", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPIR_Errhandler *errhandler_ptr ATTRIBUTE((unused)) = NULL;
    *errhandler = MPI_ERRHANDLER_NULL;
    mpi_errno = MPIR_Session_create_errhandler_impl(session_errhandler_fn, &errhandler_ptr);
    if (mpi_errno) {
        goto fn_fail;
    }
    if (errhandler_ptr) {
        MPIR_OBJ_PUBLISH_HANDLE(*errhandler, errhandler_ptr->handle);
    }
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_session_create_errhandler",
                                     "**mpi_session_create_errhandler %p %p", session_errhandler_fn,
                                     errhandler);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Session_create_errhandler(QMPI_Context context, int tool_id,
                                   MPI_Session_errhandler_function *session_errhandler_fn,
                                   MPI_Errhandler *errhandler)
{
    return internal_Session_create_errhandler(session_errhandler_fn, errhandler);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Session_create_errhandler(MPI_Session_errhandler_function *session_errhandler_fn,
                                  MPI_Errhandler *errhandler)
{
    QMPI_Context context;
    QMPI_Session_create_errhandler_t *fn_ptr;

    context.storage_stack = NULL;

    int mpi_errno = MPI_SUCCESS;
    mpi_errno = MPII_qmpi_init();
    if (mpi_errno != MPI_SUCCESS) {
        return mpi_errno;
    }

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Session_create_errhandler(context, 0, session_errhandler_fn, errhandler);

    fn_ptr = (QMPI_Session_create_errhandler_t *) MPIR_QMPI_first_fn_ptrs[MPI_SESSION_CREATE_ERRHANDLER_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_SESSION_CREATE_ERRHANDLER_T],
            session_errhandler_fn, errhandler);
}
#else /* ENABLE_QMPI */
int MPI_Session_create_errhandler(MPI_Session_errhandler_function *session_errhandler_fn,
                                  MPI_Errhandler *errhandler)
{
    return internal_Session_create_errhandler(session_errhandler_fn, errhandler);
}

#endif /* ENABLE_QMPI */
