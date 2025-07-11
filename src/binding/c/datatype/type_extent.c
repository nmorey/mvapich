/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Type_extent */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Type_extent = PMPI_Type_extent
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Type_extent  MPI_Type_extent
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Type_extent as PMPI_Type_extent
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Type_extent(MPI_Datatype datatype, MPI_Aint *extent)
     __attribute__ ((weak, alias("PMPI_Type_extent")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Type_extent
#define MPI_Type_extent PMPI_Type_extent
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Type_extent(MPI_Datatype datatype, MPI_Aint *extent)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_Datatype_get_ptr(datatype, datatype_ptr);

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_ERRTEST_ARGNULL(extent, "extent", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPI_Aint lb;
    mpi_errno = MPIR_Type_get_extent_impl(datatype, &lb, extent);
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
                                     "**mpi_type_extent", "**mpi_type_extent %D %p", datatype, extent);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Type_extent(QMPI_Context context, int tool_id, MPI_Datatype datatype, MPI_Aint *extent)
{
    return internal_Type_extent(datatype, extent);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Type_extent(MPI_Datatype datatype, MPI_Aint *extent)
{
    QMPI_Context context;
    QMPI_Type_extent_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Type_extent(context, 0, datatype, extent);

    fn_ptr = (QMPI_Type_extent_t *) MPIR_QMPI_first_fn_ptrs[MPI_TYPE_EXTENT_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_TYPE_EXTENT_T], datatype, extent);
}
#else /* ENABLE_QMPI */
int MPI_Type_extent(MPI_Datatype datatype, MPI_Aint *extent)
{
    return internal_Type_extent(datatype, extent);
}

#endif /* ENABLE_QMPI */
