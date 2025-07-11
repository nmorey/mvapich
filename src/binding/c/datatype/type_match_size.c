/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Type_match_size */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Type_match_size = PMPI_Type_match_size
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Type_match_size  MPI_Type_match_size
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Type_match_size as PMPI_Type_match_size
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Type_match_size(int typeclass, int size, MPI_Datatype *datatype)
     __attribute__ ((weak, alias("PMPI_Type_match_size")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Type_match_size
#define MPI_Type_match_size PMPI_Type_match_size
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Type_match_size(int typeclass, int size, MPI_Datatype *datatype)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(datatype, "datatype", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    *datatype = MPI_DATATYPE_NULL;
    mpi_errno = MPIR_Type_match_size_impl(typeclass, size, datatype);
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
                                     "**mpi_type_match_size", "**mpi_type_match_size %d %d %p",
                                     typeclass, size, datatype);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Type_match_size(QMPI_Context context, int tool_id, int typeclass, int size,
                         MPI_Datatype *datatype)
{
    return internal_Type_match_size(typeclass, size, datatype);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Type_match_size(int typeclass, int size, MPI_Datatype *datatype)
{
    QMPI_Context context;
    QMPI_Type_match_size_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Type_match_size(context, 0, typeclass, size, datatype);

    fn_ptr = (QMPI_Type_match_size_t *) MPIR_QMPI_first_fn_ptrs[MPI_TYPE_MATCH_SIZE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_TYPE_MATCH_SIZE_T], typeclass, size,
            datatype);
}
#else /* ENABLE_QMPI */
int MPI_Type_match_size(int typeclass, int size, MPI_Datatype *datatype)
{
    return internal_Type_match_size(typeclass, size, datatype);
}

#endif /* ENABLE_QMPI */
