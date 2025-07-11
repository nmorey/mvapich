/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Type_dup */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Type_dup = PMPI_Type_dup
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Type_dup  MPI_Type_dup
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Type_dup as PMPI_Type_dup
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Type_dup(MPI_Datatype oldtype, MPI_Datatype *newtype)
     __attribute__ ((weak, alias("PMPI_Type_dup")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Type_dup
#define MPI_Type_dup PMPI_Type_dup
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Type_dup(MPI_Datatype oldtype, MPI_Datatype *newtype)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_DATATYPE(oldtype, "datatype", mpi_errno);
            if (!HANDLE_IS_BUILTIN(oldtype)) {
                MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                MPIR_Datatype_get_ptr(oldtype, datatype_ptr);
                MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            MPIR_ERRTEST_ARGNULL(newtype, "newtype", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    *newtype = MPI_DATATYPE_NULL;
    mpi_errno = MPIR_Type_dup_impl(oldtype, newtype);
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
                                     "**mpi_type_dup", "**mpi_type_dup %D %p", oldtype, newtype);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Type_dup(QMPI_Context context, int tool_id, MPI_Datatype oldtype, MPI_Datatype *newtype)
{
    return internal_Type_dup(oldtype, newtype);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Type_dup(MPI_Datatype oldtype, MPI_Datatype *newtype)
{
    QMPI_Context context;
    QMPI_Type_dup_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Type_dup(context, 0, oldtype, newtype);

    fn_ptr = (QMPI_Type_dup_t *) MPIR_QMPI_first_fn_ptrs[MPI_TYPE_DUP_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_TYPE_DUP_T], oldtype, newtype);
}
#else /* ENABLE_QMPI */
int MPI_Type_dup(MPI_Datatype oldtype, MPI_Datatype *newtype)
{
    return internal_Type_dup(oldtype, newtype);
}

#endif /* ENABLE_QMPI */
