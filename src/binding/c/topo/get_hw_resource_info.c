/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Get_hw_resource_info */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Get_hw_resource_info = PMPI_Get_hw_resource_info
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Get_hw_resource_info  MPI_Get_hw_resource_info
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Get_hw_resource_info as PMPI_Get_hw_resource_info
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Get_hw_resource_info(MPI_Info *hw_info)
     __attribute__ ((weak, alias("PMPI_Get_hw_resource_info")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Get_hw_resource_info
#define MPI_Get_hw_resource_info PMPI_Get_hw_resource_info
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Get_hw_resource_info(MPI_Info *hw_info)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(hw_info, "hw_info", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPIR_Info *hw_info_ptr ATTRIBUTE((unused)) = NULL;
    *hw_info = MPI_INFO_NULL;
    mpi_errno = MPIR_Get_hw_resource_info_impl(&hw_info_ptr);
    if (mpi_errno) {
        goto fn_fail;
    }
    if (hw_info_ptr) {
        MPIR_OBJ_PUBLISH_HANDLE(*hw_info, hw_info_ptr->handle);
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
                                     "**mpi_get_hw_resource_info", "**mpi_get_hw_resource_info %p",
                                     hw_info);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Get_hw_resource_info(QMPI_Context context, int tool_id, MPI_Info *hw_info)
{
    return internal_Get_hw_resource_info(hw_info);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Get_hw_resource_info(MPI_Info *hw_info)
{
    QMPI_Context context;
    QMPI_Get_hw_resource_info_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Get_hw_resource_info(context, 0, hw_info);

    fn_ptr = (QMPI_Get_hw_resource_info_t *) MPIR_QMPI_first_fn_ptrs[MPI_GET_HW_RESOURCE_INFO_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_GET_HW_RESOURCE_INFO_T], hw_info);
}
#else /* ENABLE_QMPI */
int MPI_Get_hw_resource_info(MPI_Info *hw_info)
{
    return internal_Get_hw_resource_info(hw_info);
}

#endif /* ENABLE_QMPI */
