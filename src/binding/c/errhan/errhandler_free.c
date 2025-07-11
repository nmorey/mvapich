/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Errhandler_free */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Errhandler_free = PMPI_Errhandler_free
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Errhandler_free  MPI_Errhandler_free
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Errhandler_free as PMPI_Errhandler_free
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Errhandler_free(MPI_Errhandler *errhandler)
     __attribute__ ((weak, alias("PMPI_Errhandler_free")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Errhandler_free
#define MPI_Errhandler_free PMPI_Errhandler_free
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Errhandler_free(MPI_Errhandler *errhandler)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Errhandler *errhandler_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(errhandler, "errhandler", mpi_errno);
            MPIR_ERRTEST_ERRHANDLER(*errhandler, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_Errhandler_get_ptr(*errhandler, errhandler_ptr);

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_Errhandler_valid_ptr(errhandler_ptr, mpi_errno);
            if (mpi_errno) {
                goto fn_fail;
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Errhandler_free_impl(errhandler_ptr);
    if (mpi_errno) {
        goto fn_fail;
    }
    *errhandler = MPI_ERRHANDLER_NULL;
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    MPID_THREAD_CS_EXIT(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_errhandler_free", "**mpi_errhandler_free %p", errhandler);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Errhandler_free(QMPI_Context context, int tool_id, MPI_Errhandler *errhandler)
{
    return internal_Errhandler_free(errhandler);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Errhandler_free(MPI_Errhandler *errhandler)
{
    QMPI_Context context;
    QMPI_Errhandler_free_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Errhandler_free(context, 0, errhandler);

    fn_ptr = (QMPI_Errhandler_free_t *) MPIR_QMPI_first_fn_ptrs[MPI_ERRHANDLER_FREE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_ERRHANDLER_FREE_T], errhandler);
}
#else /* ENABLE_QMPI */
int MPI_Errhandler_free(MPI_Errhandler *errhandler)
{
    return internal_Errhandler_free(errhandler);
}

#endif /* ENABLE_QMPI */
