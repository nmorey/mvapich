/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Type_create_subarray */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Type_create_subarray = PMPI_Type_create_subarray
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Type_create_subarray  MPI_Type_create_subarray
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Type_create_subarray as PMPI_Type_create_subarray
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Type_create_subarray(int ndims, const int array_of_sizes[], const int array_of_subsizes[],
                             const int array_of_starts[], int order, MPI_Datatype oldtype,
                             MPI_Datatype *newtype)
                              __attribute__ ((weak, alias("PMPI_Type_create_subarray")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Type_create_subarray
#define MPI_Type_create_subarray PMPI_Type_create_subarray
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Type_create_subarray(int ndims, const int array_of_sizes[],
                                         const int array_of_subsizes[], const int array_of_starts[],
                                         int order, MPI_Datatype oldtype, MPI_Datatype *newtype)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNEG(ndims, "ndims", mpi_errno);
            if (ndims > 0) {
                MPIR_ERRTEST_ARGNULL(array_of_starts, "array_of_starts", mpi_errno);
                for (int i = 0; i < ndims; i++) {
                    MPIR_ERRTEST_COUNT(array_of_starts[i], mpi_errno);
                }
            }
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
            if (order != MPI_ORDER_C && order != MPI_ORDER_FORTRAN) {
                MPIR_ERR_SET1(mpi_errno, MPI_ERR_ARG, "**storageorder", "**storageorder %d", order);
                goto fn_fail;
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    *newtype = MPI_DATATYPE_NULL;
    mpi_errno = MPIR_Type_create_subarray_impl(ndims, array_of_sizes, array_of_subsizes,
                                               array_of_starts, order, oldtype, newtype);
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
                                     "**mpi_type_create_subarray",
                                     "**mpi_type_create_subarray %d %p %p %p %d %D %p", ndims,
                                     array_of_sizes, array_of_subsizes, array_of_starts, order, oldtype,
                                     newtype);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Type_create_subarray(QMPI_Context context, int tool_id, int ndims,
                              const int array_of_sizes[], const int array_of_subsizes[],
                              const int array_of_starts[], int order, MPI_Datatype oldtype,
                              MPI_Datatype *newtype)
{
    return internal_Type_create_subarray(ndims, array_of_sizes, array_of_subsizes, array_of_starts, order, oldtype, newtype);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Type_create_subarray(int ndims, const int array_of_sizes[], const int array_of_subsizes[],
                             const int array_of_starts[], int order, MPI_Datatype oldtype,
                             MPI_Datatype *newtype)
{
    QMPI_Context context;
    QMPI_Type_create_subarray_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Type_create_subarray(context, 0, ndims, array_of_sizes, array_of_subsizes,
                                         array_of_starts, order, oldtype, newtype);

    fn_ptr = (QMPI_Type_create_subarray_t *) MPIR_QMPI_first_fn_ptrs[MPI_TYPE_CREATE_SUBARRAY_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_TYPE_CREATE_SUBARRAY_T], ndims,
            array_of_sizes, array_of_subsizes, array_of_starts, order, oldtype, newtype);
}
#else /* ENABLE_QMPI */
int MPI_Type_create_subarray(int ndims, const int array_of_sizes[], const int array_of_subsizes[],
                             const int array_of_starts[], int order, MPI_Datatype oldtype,
                             MPI_Datatype *newtype)
{
    return internal_Type_create_subarray(ndims, array_of_sizes, array_of_subsizes, array_of_starts, order, oldtype, newtype);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Type_create_subarray_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Type_create_subarray_c = PMPI_Type_create_subarray_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Type_create_subarray_c  MPI_Type_create_subarray_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Type_create_subarray_c as PMPI_Type_create_subarray_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Type_create_subarray_c(int ndims, const MPI_Count array_of_sizes[],
                               const MPI_Count array_of_subsizes[],
                               const MPI_Count array_of_starts[], int order, MPI_Datatype oldtype,
                               MPI_Datatype *newtype)
                                __attribute__ ((weak, alias("PMPI_Type_create_subarray_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Type_create_subarray_c
#define MPI_Type_create_subarray_c PMPI_Type_create_subarray_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Type_create_subarray_c(int ndims, const MPI_Count array_of_sizes[],
                                           const MPI_Count array_of_subsizes[],
                                           const MPI_Count array_of_starts[], int order,
                                           MPI_Datatype oldtype, MPI_Datatype *newtype)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNEG(ndims, "ndims", mpi_errno);
            if (ndims > 0) {
                MPIR_ERRTEST_ARGNULL(array_of_starts, "array_of_starts", mpi_errno);
                for (int i = 0; i < ndims; i++) {
                    MPIR_ERRTEST_COUNT(array_of_starts[i], mpi_errno);
                }
            }
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
            if (order != MPI_ORDER_C && order != MPI_ORDER_FORTRAN) {
                MPIR_ERR_SET1(mpi_errno, MPI_ERR_ARG, "**storageorder", "**storageorder %d", order);
                goto fn_fail;
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        *newtype = MPI_DATATYPE_NULL;
        mpi_errno = MPIR_Type_create_subarray_large_impl(ndims, (MPI_Aint *) array_of_sizes,
                                                         (MPI_Aint *) array_of_subsizes,
                                                         (MPI_Aint *) array_of_starts, order, oldtype,
                                                         newtype);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        MPI_Aint *array_of_sizes_c = MPL_malloc(ndims * sizeof(MPI_Aint), MPL_MEM_OTHER);
        for (int i = 0; i < ndims; i++) {
            if (array_of_sizes[i] > MPIR_AINT_MAX) {
                mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                                 __func__, __LINE__, MPI_ERR_OTHER,
                                                 "**too_big_for_input",
                                                 "**too_big_for_input %s", "array_of_sizes[i]");
                goto fn_fail;
            }
            array_of_sizes_c[i] = array_of_sizes[i];
        }
        MPI_Aint *array_of_subsizes_c = MPL_malloc(ndims * sizeof(MPI_Aint), MPL_MEM_OTHER);
        for (int i = 0; i < ndims; i++) {
            if (array_of_subsizes[i] > MPIR_AINT_MAX) {
                mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                                 __func__, __LINE__, MPI_ERR_OTHER,
                                                 "**too_big_for_input",
                                                 "**too_big_for_input %s", "array_of_subsizes[i]");
                goto fn_fail;
            }
            array_of_subsizes_c[i] = array_of_subsizes[i];
        }
        MPI_Aint *array_of_starts_c = MPL_malloc(ndims * sizeof(MPI_Aint), MPL_MEM_OTHER);
        for (int i = 0; i < ndims; i++) {
            if (array_of_starts[i] > MPIR_AINT_MAX) {
                mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                                 __func__, __LINE__, MPI_ERR_OTHER,
                                                 "**too_big_for_input",
                                                 "**too_big_for_input %s", "array_of_starts[i]");
                goto fn_fail;
            }
            array_of_starts_c[i] = array_of_starts[i];
        }
        *newtype = MPI_DATATYPE_NULL;
        mpi_errno = MPIR_Type_create_subarray_large_impl(ndims, array_of_sizes_c, array_of_subsizes_c,
                                                         array_of_starts_c, order, oldtype, newtype);
        if (mpi_errno) {
            goto fn_fail;
        }
        MPL_free(array_of_sizes_c);
        MPL_free(array_of_subsizes_c);
        MPL_free(array_of_starts_c);
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
                                     "**mpi_type_create_subarray_c",
                                     "**mpi_type_create_subarray_c %d %p %p %p %d %D %p", ndims,
                                     array_of_sizes, array_of_subsizes, array_of_starts, order, oldtype,
                                     newtype);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Type_create_subarray_c(QMPI_Context context, int tool_id, int ndims,
                                const MPI_Count array_of_sizes[],
                                const MPI_Count array_of_subsizes[],
                                const MPI_Count array_of_starts[], int order, MPI_Datatype oldtype,
                                MPI_Datatype *newtype)
{
    return internal_Type_create_subarray_c(ndims, array_of_sizes, array_of_subsizes, array_of_starts, order, oldtype, newtype);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Type_create_subarray_c(int ndims, const MPI_Count array_of_sizes[],
                               const MPI_Count array_of_subsizes[],
                               const MPI_Count array_of_starts[], int order, MPI_Datatype oldtype,
                               MPI_Datatype *newtype)
{
    QMPI_Context context;
    QMPI_Type_create_subarray_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Type_create_subarray_c(context, 0, ndims, array_of_sizes, array_of_subsizes,
                                           array_of_starts, order, oldtype, newtype);

    fn_ptr = (QMPI_Type_create_subarray_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_TYPE_CREATE_SUBARRAY_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_TYPE_CREATE_SUBARRAY_C_T], ndims,
            array_of_sizes, array_of_subsizes, array_of_starts, order, oldtype, newtype);
}
#else /* ENABLE_QMPI */
int MPI_Type_create_subarray_c(int ndims, const MPI_Count array_of_sizes[],
                               const MPI_Count array_of_subsizes[],
                               const MPI_Count array_of_starts[], int order, MPI_Datatype oldtype,
                               MPI_Datatype *newtype)
{
    return internal_Type_create_subarray_c(ndims, array_of_sizes, array_of_subsizes, array_of_starts, order, oldtype, newtype);
}

#endif /* ENABLE_QMPI */
