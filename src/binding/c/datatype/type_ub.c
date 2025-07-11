/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Type_ub */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Type_ub = PMPI_Type_ub
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Type_ub  MPI_Type_ub
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Type_ub as PMPI_Type_ub
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Type_ub(MPI_Datatype datatype, MPI_Aint *displacement)
     __attribute__ ((weak, alias("PMPI_Type_ub")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Type_ub
#define MPI_Type_ub PMPI_Type_ub
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Type_ub(MPI_Datatype datatype, MPI_Aint *displacement)
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
            MPIR_ERRTEST_ARGNULL(displacement, "displacement", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPI_Aint lb, extent;
    mpi_errno = MPIR_Type_get_extent_impl(datatype, &lb, &extent);
    if (mpi_errno) {
        goto fn_fail;
    }
    *displacement = lb + extent;
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_type_ub", "**mpi_type_ub %D %p", datatype, displacement);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Type_ub(QMPI_Context context, int tool_id, MPI_Datatype datatype, MPI_Aint *displacement)
{
    return internal_Type_ub(datatype, displacement);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Type_ub(MPI_Datatype datatype, MPI_Aint *displacement)
{
    QMPI_Context context;
    QMPI_Type_ub_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Type_ub(context, 0, datatype, displacement);

    fn_ptr = (QMPI_Type_ub_t *) MPIR_QMPI_first_fn_ptrs[MPI_TYPE_UB_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_TYPE_UB_T], datatype, displacement);
}
#else /* ENABLE_QMPI */
int MPI_Type_ub(MPI_Datatype datatype, MPI_Aint *displacement)
{
    return internal_Type_ub(datatype, displacement);
}

#endif /* ENABLE_QMPI */
