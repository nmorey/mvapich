/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Get_count */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Get_count = PMPI_Get_count
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Get_count  MPI_Get_count
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Get_count as PMPI_Get_count
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Get_count(const MPI_Status *status, MPI_Datatype datatype, int *count)
     __attribute__ ((weak, alias("PMPI_Get_count")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Get_count
#define MPI_Get_count PMPI_Get_count
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Get_count(const MPI_Status *status, MPI_Datatype datatype, int *count)
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
            }
            MPIR_ERRTEST_ARGNULL(count, "count", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPI_Aint count_c;
    mpi_errno = MPIR_Get_count_impl(status, datatype, &count_c);
    if (mpi_errno) {
        goto fn_fail;
    }
    if (count_c > INT_MAX) {
        *count = MPI_UNDEFINED;
    } else {
        *count = count_c;
    }
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_get_count", "**mpi_get_count %p %D %p", status, datatype,
                                     count);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Get_count(QMPI_Context context, int tool_id, const MPI_Status *status,
                   MPI_Datatype datatype, int *count)
{
    return internal_Get_count(status, datatype, count);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Get_count(const MPI_Status *status, MPI_Datatype datatype, int *count)
{
    QMPI_Context context;
    QMPI_Get_count_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Get_count(context, 0, status, datatype, count);

    fn_ptr = (QMPI_Get_count_t *) MPIR_QMPI_first_fn_ptrs[MPI_GET_COUNT_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_GET_COUNT_T], status, datatype, count);
}
#else /* ENABLE_QMPI */
int MPI_Get_count(const MPI_Status *status, MPI_Datatype datatype, int *count)
{
    return internal_Get_count(status, datatype, count);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Get_count_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Get_count_c = PMPI_Get_count_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Get_count_c  MPI_Get_count_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Get_count_c as PMPI_Get_count_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Get_count_c(const MPI_Status *status, MPI_Datatype datatype, MPI_Count *count)
     __attribute__ ((weak, alias("PMPI_Get_count_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Get_count_c
#define MPI_Get_count_c PMPI_Get_count_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Get_count_c(const MPI_Status *status, MPI_Datatype datatype, MPI_Count *count)
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
            }
            MPIR_ERRTEST_ARGNULL(count, "count", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_Get_count_impl(status, datatype, (MPI_Aint *) count);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        MPI_Aint count_c;
        mpi_errno = MPIR_Get_count_impl(status, datatype, &count_c);
        if (mpi_errno) {
            goto fn_fail;
        }
        *count = count_c;
    }
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_get_count_c", "**mpi_get_count_c %p %D %p", status,
                                     datatype, count);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Get_count_c(QMPI_Context context, int tool_id, const MPI_Status *status,
                     MPI_Datatype datatype, MPI_Count *count)
{
    return internal_Get_count_c(status, datatype, count);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Get_count_c(const MPI_Status *status, MPI_Datatype datatype, MPI_Count *count)
{
    QMPI_Context context;
    QMPI_Get_count_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Get_count_c(context, 0, status, datatype, count);

    fn_ptr = (QMPI_Get_count_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_GET_COUNT_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_GET_COUNT_C_T], status, datatype,
            count);
}
#else /* ENABLE_QMPI */
int MPI_Get_count_c(const MPI_Status *status, MPI_Datatype datatype, MPI_Count *count)
{
    return internal_Get_count_c(status, datatype, count);
}

#endif /* ENABLE_QMPI */
