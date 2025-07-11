/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Get_elements */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Get_elements = PMPI_Get_elements
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Get_elements  MPI_Get_elements
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Get_elements as PMPI_Get_elements
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Get_elements(const MPI_Status *status, MPI_Datatype datatype, int *count)
     __attribute__ ((weak, alias("PMPI_Get_elements")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Get_elements
#define MPI_Get_elements PMPI_Get_elements
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Get_elements(const MPI_Status *status, MPI_Datatype datatype, int *count)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
            if (!HANDLE_IS_BUILTIN(datatype)) {
                MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
                MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            MPIR_ERRTEST_ARGNULL(count, "count", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPI_Count count_x;
    MPI_Count byte_count = MPIR_STATUS_GET_COUNT(*status);
    mpi_errno = MPIR_Get_elements_x_impl(&byte_count, datatype, &count_x);
    if (mpi_errno) {
        goto fn_fail;
    }

    /* clip the value if it cannot be correctly returned to the user */
    *count = (count_x > INT_MAX) ? MPI_UNDEFINED : (int) count_x;

    if (byte_count != 0) {
        *count = MPI_UNDEFINED;
    }
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_get_elements", "**mpi_get_elements %p %D %p", status,
                                     datatype, count);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Get_elements(QMPI_Context context, int tool_id, const MPI_Status *status,
                      MPI_Datatype datatype, int *count)
{
    return internal_Get_elements(status, datatype, count);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Get_elements(const MPI_Status *status, MPI_Datatype datatype, int *count)
{
    QMPI_Context context;
    QMPI_Get_elements_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Get_elements(context, 0, status, datatype, count);

    fn_ptr = (QMPI_Get_elements_t *) MPIR_QMPI_first_fn_ptrs[MPI_GET_ELEMENTS_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_GET_ELEMENTS_T], status, datatype,
            count);
}
#else /* ENABLE_QMPI */
int MPI_Get_elements(const MPI_Status *status, MPI_Datatype datatype, int *count)
{
    return internal_Get_elements(status, datatype, count);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Get_elements_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Get_elements_c = PMPI_Get_elements_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Get_elements_c  MPI_Get_elements_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Get_elements_c as PMPI_Get_elements_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Get_elements_c(const MPI_Status *status, MPI_Datatype datatype, MPI_Count *count)
     __attribute__ ((weak, alias("PMPI_Get_elements_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Get_elements_c
#define MPI_Get_elements_c PMPI_Get_elements_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Get_elements_c(const MPI_Status *status, MPI_Datatype datatype,
                                   MPI_Count *count)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
            if (!HANDLE_IS_BUILTIN(datatype)) {
                MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
                MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            MPIR_ERRTEST_ARGNULL(count, "count", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPI_Count byte_count = MPIR_STATUS_GET_COUNT(*status);
    mpi_errno = MPIR_Get_elements_x_impl(&byte_count, datatype, count);
    if (mpi_errno) {
        goto fn_fail;
    }

    if (byte_count != 0) {
        *count = MPI_UNDEFINED;
    }
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_get_elements_c", "**mpi_get_elements_c %p %D %p", status,
                                     datatype, count);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Get_elements_c(QMPI_Context context, int tool_id, const MPI_Status *status,
                        MPI_Datatype datatype, MPI_Count *count)
{
    return internal_Get_elements_c(status, datatype, count);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Get_elements_c(const MPI_Status *status, MPI_Datatype datatype, MPI_Count *count)
{
    QMPI_Context context;
    QMPI_Get_elements_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Get_elements_c(context, 0, status, datatype, count);

    fn_ptr = (QMPI_Get_elements_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_GET_ELEMENTS_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_GET_ELEMENTS_C_T], status, datatype,
            count);
}
#else /* ENABLE_QMPI */
int MPI_Get_elements_c(const MPI_Status *status, MPI_Datatype datatype, MPI_Count *count)
{
    return internal_Get_elements_c(status, datatype, count);
}

#endif /* ENABLE_QMPI */
