/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

#if defined(HAVE_ROMIO) && defined(MPICH_MPI_FROM_PMPI)
void MPIR_Comm_split_filesystem(void);
void MPIR_ROMIO_Get_file_errhand(void);
void MPIR_ROMIO_Set_file_errhand(void);
void *dummy_refs_MPI_Session_init[] = {
    (void *) MPIR_Comm_split_filesystem,
    (void *) MPIR_ROMIO_Get_file_errhand,
    (void *) MPIR_ROMIO_Set_file_errhand,
};
#endif

/* -- Begin Profiling Symbol Block for routine MPI_Session_init */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Session_init = PMPI_Session_init
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Session_init  MPI_Session_init
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Session_init as PMPI_Session_init
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Session_init(MPI_Info info, MPI_Errhandler errhandler, MPI_Session *session)
     __attribute__ ((weak, alias("PMPI_Session_init")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Session_init
#define MPI_Session_init PMPI_Session_init
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Session_init(MPI_Info info, MPI_Errhandler errhandler, MPI_Session *session)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Info *info_ptr ATTRIBUTE((unused)) = NULL;
    MPIR_Errhandler *errhandler_ptr ATTRIBUTE((unused)) = NULL;
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_INFO_OR_NULL(info, mpi_errno);
            MPIR_ERRTEST_ERRHANDLER(errhandler, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    if (info != MPI_INFO_NULL) {
        MPIR_Info_get_ptr(info, info_ptr);
    }
    MPIR_Errhandler_get_ptr(errhandler, errhandler_ptr);

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
            MPIR_Errhandler_valid_ptr(errhandler_ptr, mpi_errno);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_ERRTEST_ARGNULL(session, "session", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPIR_Session *session_ptr ATTRIBUTE((unused)) = NULL;
    *session = MPI_SESSION_NULL;
    mpi_errno = MPIR_Session_init_impl(info_ptr, errhandler_ptr, &session_ptr);
    if (mpi_errno) {
        goto fn_fail;
    }
    if (session_ptr) {
        MPIR_OBJ_PUBLISH_HANDLE(*session, session_ptr->handle);
    }
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_session_init", "**mpi_session_init %I %E %p", info,
                                     errhandler, session);
#endif
    mpi_errno = MPIR_Err_return_session_init(errhandler_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Session_init(QMPI_Context context, int tool_id, MPI_Info info, MPI_Errhandler errhandler,
                      MPI_Session *session)
{
    return internal_Session_init(info, errhandler, session);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Session_init(MPI_Info info, MPI_Errhandler errhandler, MPI_Session *session)
{
    QMPI_Context context;
    QMPI_Session_init_t *fn_ptr;

    context.storage_stack = NULL;

    int mpi_errno = MPI_SUCCESS;
    mpi_errno = MPII_qmpi_init();
    if (mpi_errno != MPI_SUCCESS) {
        return mpi_errno;
    }

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Session_init(context, 0, info, errhandler, session);

    fn_ptr = (QMPI_Session_init_t *) MPIR_QMPI_first_fn_ptrs[MPI_SESSION_INIT_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_SESSION_INIT_T], info, errhandler,
            session);
}
#else /* ENABLE_QMPI */
int MPI_Session_init(MPI_Info info, MPI_Errhandler errhandler, MPI_Session *session)
{
    return internal_Session_init(info, errhandler, session);
}

#endif /* ENABLE_QMPI */
