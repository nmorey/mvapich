/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Comm_accept */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Comm_accept = PMPI_Comm_accept
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Comm_accept  MPI_Comm_accept
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Comm_accept as PMPI_Comm_accept
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Comm_accept(const char *port_name, MPI_Info info, int root, MPI_Comm comm,
                    MPI_Comm *newcomm)  __attribute__ ((weak, alias("PMPI_Comm_accept")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Comm_accept
#define MPI_Comm_accept PMPI_Comm_accept
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Comm_accept(const char *port_name, MPI_Info info, int root, MPI_Comm comm,
                                MPI_Comm *newcomm)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Info *info_ptr ATTRIBUTE((unused)) = NULL;
    MPIR_Comm *comm_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_INFO_OR_NULL(info, mpi_errno);
            MPIR_ERRTEST_COMM(comm, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    if (info != MPI_INFO_NULL) {
        MPIR_Info_get_ptr(info, info_ptr);
    }
    MPIR_Comm_get_ptr(comm, comm_ptr);

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
            MPIR_Comm_valid_ptr(comm_ptr, mpi_errno, FALSE);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_ERRTEST_INTRA_ROOT(comm_ptr, root, mpi_errno);
            MPIR_ERRTEST_ARGNULL(newcomm, "newcomm", mpi_errno);
            if (comm_ptr->rank == root) {
                MPIR_ERRTEST_ARGNULL(port_name, "port_name", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPIR_Comm *newcomm_ptr ATTRIBUTE((unused)) = NULL;
    *newcomm = MPI_COMM_NULL;
    mpi_errno = MPIR_Comm_accept_impl(port_name, info_ptr, root, comm_ptr, &newcomm_ptr);
    if (mpi_errno) {
        goto fn_fail;
    }
    if (newcomm_ptr) {
        MPIR_OBJ_PUBLISH_HANDLE(*newcomm, newcomm_ptr->handle);
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
                                     "**mpi_comm_accept", "**mpi_comm_accept %s %I %i %C %p", port_name,
                                     info, root, comm, newcomm);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Comm_accept(QMPI_Context context, int tool_id, const char *port_name, MPI_Info info,
                     int root, MPI_Comm comm, MPI_Comm *newcomm)
{
    return internal_Comm_accept(port_name, info, root, comm, newcomm);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Comm_accept(const char *port_name, MPI_Info info, int root, MPI_Comm comm,
                    MPI_Comm *newcomm)
{
    QMPI_Context context;
    QMPI_Comm_accept_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Comm_accept(context, 0, port_name, info, root, comm, newcomm);

    fn_ptr = (QMPI_Comm_accept_t *) MPIR_QMPI_first_fn_ptrs[MPI_COMM_ACCEPT_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_COMM_ACCEPT_T], port_name, info, root,
            comm, newcomm);
}
#else /* ENABLE_QMPI */
int MPI_Comm_accept(const char *port_name, MPI_Info info, int root, MPI_Comm comm,
                    MPI_Comm *newcomm)
{
    return internal_Comm_accept(port_name, info, root, comm, newcomm);
}

#endif /* ENABLE_QMPI */
