/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Type_get_value_index */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Type_get_value_index = PMPI_Type_get_value_index
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Type_get_value_index  MPI_Type_get_value_index
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Type_get_value_index as PMPI_Type_get_value_index
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Type_get_value_index(MPI_Datatype value_type, MPI_Datatype index_type,
                             MPI_Datatype *pair_type)
                              __attribute__ ((weak, alias("PMPI_Type_get_value_index")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Type_get_value_index
#define MPI_Type_get_value_index PMPI_Type_get_value_index
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Type_get_value_index(MPI_Datatype value_type, MPI_Datatype index_type,
                                         MPI_Datatype *pair_type)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_DATATYPE(value_type, "datatype", mpi_errno);
            if (!HANDLE_IS_BUILTIN(value_type)) {
                MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                MPIR_Datatype_get_ptr(value_type, datatype_ptr);
                MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            MPIR_ERRTEST_DATATYPE(index_type, "datatype", mpi_errno);
            if (!HANDLE_IS_BUILTIN(index_type)) {
                MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                MPIR_Datatype_get_ptr(index_type, datatype_ptr);
                MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            MPIR_ERRTEST_ARGNULL(pair_type, "pair_type", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    *pair_type = MPI_DATATYPE_NULL;
    mpi_errno = MPIR_Type_get_value_index_impl(value_type, index_type, pair_type);
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
                                     "**mpi_type_get_value_index",
                                     "**mpi_type_get_value_index %D %D %p", value_type, index_type,
                                     pair_type);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Type_get_value_index(QMPI_Context context, int tool_id, MPI_Datatype value_type,
                              MPI_Datatype index_type, MPI_Datatype *pair_type)
{
    return internal_Type_get_value_index(value_type, index_type, pair_type);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Type_get_value_index(MPI_Datatype value_type, MPI_Datatype index_type,
                             MPI_Datatype *pair_type)
{
    QMPI_Context context;
    QMPI_Type_get_value_index_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Type_get_value_index(context, 0, value_type, index_type, pair_type);

    fn_ptr = (QMPI_Type_get_value_index_t *) MPIR_QMPI_first_fn_ptrs[MPI_TYPE_GET_VALUE_INDEX_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_TYPE_GET_VALUE_INDEX_T], value_type,
            index_type, pair_type);
}
#else /* ENABLE_QMPI */
int MPI_Type_get_value_index(MPI_Datatype value_type, MPI_Datatype index_type,
                             MPI_Datatype *pair_type)
{
    return internal_Type_get_value_index(value_type, index_type, pair_type);
}

#endif /* ENABLE_QMPI */
