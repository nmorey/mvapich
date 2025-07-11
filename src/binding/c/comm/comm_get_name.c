/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Comm_get_name */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Comm_get_name = PMPI_Comm_get_name
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Comm_get_name  MPI_Comm_get_name
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Comm_get_name as PMPI_Comm_get_name
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Comm_get_name(MPI_Comm comm, char *comm_name, int *resultlen)
     __attribute__ ((weak, alias("PMPI_Comm_get_name")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Comm_get_name
#define MPI_Comm_get_name PMPI_Comm_get_name
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Comm_get_name(MPI_Comm comm, char *comm_name, int *resultlen)
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
            if (comm != MPI_COMM_NULL) {
                MPIR_ERRTEST_COMM(comm, mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    if (comm != MPI_COMM_NULL) {
        MPIR_Comm_get_ptr(comm, comm_ptr);
    }

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            if (comm != MPI_COMM_NULL) {
                MPIR_Comm_valid_ptr(comm_ptr, mpi_errno, TRUE);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            if (MPI_MAX_OBJECT_NAME > 0) {
                MPIR_ERRTEST_ARGNULL(comm_name, "comm_name", mpi_errno);
            }
            MPIR_ERRTEST_ARGNULL(resultlen, "resultlen", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Comm_get_name_impl(comm_ptr, comm_name, resultlen);
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
                                     "**mpi_comm_get_name", "**mpi_comm_get_name %C %p %p", comm,
                                     comm_name, resultlen);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Comm_get_name(QMPI_Context context, int tool_id, MPI_Comm comm, char *comm_name,
                       int *resultlen)
{
    return internal_Comm_get_name(comm, comm_name, resultlen);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Comm_get_name(MPI_Comm comm, char *comm_name, int *resultlen)
{
    QMPI_Context context;
    QMPI_Comm_get_name_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Comm_get_name(context, 0, comm, comm_name, resultlen);

    fn_ptr = (QMPI_Comm_get_name_t *) MPIR_QMPI_first_fn_ptrs[MPI_COMM_GET_NAME_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_COMM_GET_NAME_T], comm, comm_name,
            resultlen);
}
#else /* ENABLE_QMPI */
int MPI_Comm_get_name(MPI_Comm comm, char *comm_name, int *resultlen)
{
    return internal_Comm_get_name(comm, comm_name, resultlen);
}

#endif /* ENABLE_QMPI */
