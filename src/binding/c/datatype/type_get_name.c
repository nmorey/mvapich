/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Type_get_name */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Type_get_name = PMPI_Type_get_name
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Type_get_name  MPI_Type_get_name
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Type_get_name as PMPI_Type_get_name
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Type_get_name(MPI_Datatype datatype, char *type_name, int *resultlen)
     __attribute__ ((weak, alias("PMPI_Type_get_name")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Type_get_name
#define MPI_Type_get_name PMPI_Type_get_name
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Type_get_name(MPI_Datatype datatype, char *type_name, int *resultlen)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            if (datatype != MPI_DATATYPE_NULL) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    if (datatype != MPI_DATATYPE_NULL) {
        MPIR_Datatype_get_ptr(datatype, datatype_ptr);
    }

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            if (datatype != MPI_DATATYPE_NULL) {
                MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            if (MPI_MAX_OBJECT_NAME > 0) {
                MPIR_ERRTEST_ARGNULL(type_name, "type_name", mpi_errno);
            }
            MPIR_ERRTEST_ARGNULL(resultlen, "resultlen", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Type_get_name_impl(datatype_ptr, type_name, resultlen);
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
                                     "**mpi_type_get_name", "**mpi_type_get_name %D %p %p", datatype,
                                     type_name, resultlen);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Type_get_name(QMPI_Context context, int tool_id, MPI_Datatype datatype, char *type_name,
                       int *resultlen)
{
    return internal_Type_get_name(datatype, type_name, resultlen);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Type_get_name(MPI_Datatype datatype, char *type_name, int *resultlen)
{
    QMPI_Context context;
    QMPI_Type_get_name_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Type_get_name(context, 0, datatype, type_name, resultlen);

    fn_ptr = (QMPI_Type_get_name_t *) MPIR_QMPI_first_fn_ptrs[MPI_TYPE_GET_NAME_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_TYPE_GET_NAME_T], datatype, type_name,
            resultlen);
}
#else /* ENABLE_QMPI */
int MPI_Type_get_name(MPI_Datatype datatype, char *type_name, int *resultlen)
{
    return internal_Type_get_name(datatype, type_name, resultlen);
}

#endif /* ENABLE_QMPI */
