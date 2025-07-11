/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Info_dup */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Info_dup = PMPI_Info_dup
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Info_dup  MPI_Info_dup
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Info_dup as PMPI_Info_dup
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Info_dup(MPI_Info info, MPI_Info *newinfo)  __attribute__ ((weak, alias("PMPI_Info_dup")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Info_dup
#define MPI_Info_dup PMPI_Info_dup
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Info_dup(MPI_Info info, MPI_Info *newinfo)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Info *info_ptr ATTRIBUTE((unused)) = NULL;
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_INFO(info, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_Info_get_ptr(info, info_ptr);

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_Info_valid_ptr(info_ptr, mpi_errno);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_ERRTEST_ARGNULL(newinfo, "newinfo", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPIR_Info *newinfo_ptr ATTRIBUTE((unused)) = NULL;
    *newinfo = MPI_INFO_NULL;
    mpi_errno = MPIR_Info_dup_impl(info_ptr, &newinfo_ptr);
    if (mpi_errno) {
        goto fn_fail;
    }
    if (newinfo_ptr) {
        MPIR_OBJ_PUBLISH_HANDLE(*newinfo, newinfo_ptr->handle);
    }
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_info_dup", "**mpi_info_dup %I %p", info, newinfo);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Info_dup(QMPI_Context context, int tool_id, MPI_Info info, MPI_Info *newinfo)
{
    return internal_Info_dup(info, newinfo);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Info_dup(MPI_Info info, MPI_Info *newinfo)
{
    QMPI_Context context;
    QMPI_Info_dup_t *fn_ptr;

    context.storage_stack = NULL;

    int mpi_errno = MPI_SUCCESS;
    mpi_errno = MPII_qmpi_init();
    if (mpi_errno != MPI_SUCCESS) {
        return mpi_errno;
    }

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Info_dup(context, 0, info, newinfo);

    fn_ptr = (QMPI_Info_dup_t *) MPIR_QMPI_first_fn_ptrs[MPI_INFO_DUP_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_INFO_DUP_T], info, newinfo);
}
#else /* ENABLE_QMPI */
int MPI_Info_dup(MPI_Info info, MPI_Info *newinfo)
{
    return internal_Info_dup(info, newinfo);
}

#endif /* ENABLE_QMPI */
