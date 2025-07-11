/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Session_get_nth_pset */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Session_get_nth_pset = PMPI_Session_get_nth_pset
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Session_get_nth_pset  MPI_Session_get_nth_pset
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Session_get_nth_pset as PMPI_Session_get_nth_pset
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Session_get_nth_pset(MPI_Session session, MPI_Info info, int n, int *pset_len,
                             char *pset_name)
                              __attribute__ ((weak, alias("PMPI_Session_get_nth_pset")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Session_get_nth_pset
#define MPI_Session_get_nth_pset PMPI_Session_get_nth_pset
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Session_get_nth_pset(MPI_Session session, MPI_Info info, int n, int *pset_len,
                                         char *pset_name)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Session *session_ptr ATTRIBUTE((unused)) = NULL;
    MPIR_Info *info_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
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

    MPIR_Session_get_ptr(session, session_ptr);
    if (info != MPI_INFO_NULL) {
        MPIR_Info_get_ptr(info, info_ptr);
    }

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_Session_valid_ptr(session_ptr, mpi_errno);
            if (mpi_errno) {
                goto fn_fail;
            }
            if (info != MPI_INFO_NULL) {
                MPIR_Info_valid_ptr(info_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            MPIR_ERRTEST_ARGNEG(n, "n", mpi_errno);
            MPIR_ERRTEST_ARGNULL(pset_len, "pset_len", mpi_errno);
            if (*pset_len) {
                MPIR_ERRTEST_ARGNULL(pset_name, "pset_name", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Session_get_nth_pset_impl(session_ptr, info_ptr, n, pset_len, pset_name);
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
                                     "**mpi_session_get_nth_pset",
                                     "**mpi_session_get_nth_pset %S %I %d %p %p", session, info, n,
                                     pset_len, pset_name);
#endif
    mpi_errno = MPIR_Err_return_session(session_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Session_get_nth_pset(QMPI_Context context, int tool_id, MPI_Session session, MPI_Info info,
                              int n, int *pset_len, char *pset_name)
{
    return internal_Session_get_nth_pset(session, info, n, pset_len, pset_name);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Session_get_nth_pset(MPI_Session session, MPI_Info info, int n, int *pset_len,
                             char *pset_name)
{
    QMPI_Context context;
    QMPI_Session_get_nth_pset_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Session_get_nth_pset(context, 0, session, info, n, pset_len, pset_name);

    fn_ptr = (QMPI_Session_get_nth_pset_t *) MPIR_QMPI_first_fn_ptrs[MPI_SESSION_GET_NTH_PSET_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_SESSION_GET_NTH_PSET_T], session, info,
            n, pset_len, pset_name);
}
#else /* ENABLE_QMPI */
int MPI_Session_get_nth_pset(MPI_Session session, MPI_Info info, int n, int *pset_len,
                             char *pset_name)
{
    return internal_Session_get_nth_pset(session, info, n, pset_len, pset_name);
}

#endif /* ENABLE_QMPI */
