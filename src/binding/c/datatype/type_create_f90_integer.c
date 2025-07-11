/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Type_create_f90_integer */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Type_create_f90_integer = PMPI_Type_create_f90_integer
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Type_create_f90_integer  MPI_Type_create_f90_integer
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Type_create_f90_integer as PMPI_Type_create_f90_integer
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Type_create_f90_integer(int r, MPI_Datatype *newtype)
     __attribute__ ((weak, alias("PMPI_Type_create_f90_integer")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Type_create_f90_integer
#define MPI_Type_create_f90_integer PMPI_Type_create_f90_integer
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Type_create_f90_integer(int r, MPI_Datatype *newtype)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(newtype, "newtype", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    *newtype = MPI_DATATYPE_NULL;
    mpi_errno = MPIR_Type_create_f90_integer_impl(r, newtype);
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
                                     "**mpi_type_create_f90_integer",
                                     "**mpi_type_create_f90_integer %d %p", r, newtype);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Type_create_f90_integer(QMPI_Context context, int tool_id, int r, MPI_Datatype *newtype)
{
    return internal_Type_create_f90_integer(r, newtype);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Type_create_f90_integer(int r, MPI_Datatype *newtype)
{
    QMPI_Context context;
    QMPI_Type_create_f90_integer_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Type_create_f90_integer(context, 0, r, newtype);

    fn_ptr = (QMPI_Type_create_f90_integer_t *) MPIR_QMPI_first_fn_ptrs[MPI_TYPE_CREATE_F90_INTEGER_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_TYPE_CREATE_F90_INTEGER_T], r,
            newtype);
}
#else /* ENABLE_QMPI */
int MPI_Type_create_f90_integer(int r, MPI_Datatype *newtype)
{
    return internal_Type_create_f90_integer(r, newtype);
}

#endif /* ENABLE_QMPI */
