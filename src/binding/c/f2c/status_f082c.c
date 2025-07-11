/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Status_f082c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Status_f082c = PMPI_Status_f082c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Status_f082c  MPI_Status_f082c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Status_f082c as PMPI_Status_f082c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Status_f082c(const MPI_F08_status *f08_status, MPI_Status *c_status)
     __attribute__ ((weak, alias("PMPI_Status_f082c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Status_f082c
#define MPI_Status_f082c PMPI_Status_f082c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Status_f082c(const MPI_F08_status *f08_status, MPI_Status *c_status)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(f08_status, "f08_status", mpi_errno);
            if (c_status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(c_status, "c_status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Status_f082c_impl(f08_status, c_status);
    if (mpi_errno) {
        goto fn_fail;
    }
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_status_f082c", "**mpi_status_f082c %p %p", f08_status,
                                     c_status);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Status_f082c(QMPI_Context context, int tool_id, const MPI_F08_status *f08_status,
                      MPI_Status *c_status)
{
    return internal_Status_f082c(f08_status, c_status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Status_f082c(const MPI_F08_status *f08_status, MPI_Status *c_status)
{
    QMPI_Context context;
    QMPI_Status_f082c_t *fn_ptr;

    context.storage_stack = NULL;

    int mpi_errno = MPI_SUCCESS;
    mpi_errno = MPII_qmpi_init();
    if (mpi_errno != MPI_SUCCESS) {
        return mpi_errno;
    }

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Status_f082c(context, 0, f08_status, c_status);

    fn_ptr = (QMPI_Status_f082c_t *) MPIR_QMPI_first_fn_ptrs[MPI_STATUS_F082C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_STATUS_F082C_T], f08_status, c_status);
}
#else /* ENABLE_QMPI */
int MPI_Status_f082c(const MPI_F08_status *f08_status, MPI_Status *c_status)
{
    return internal_Status_f082c(f08_status, c_status);
}

#endif /* ENABLE_QMPI */
