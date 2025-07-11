/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Type_create_darray */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Type_create_darray = PMPI_Type_create_darray
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Type_create_darray  MPI_Type_create_darray
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Type_create_darray as PMPI_Type_create_darray
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Type_create_darray(int size, int rank, int ndims, const int array_of_gsizes[],
                           const int array_of_distribs[], const int array_of_dargs[],
                           const int array_of_psizes[], int order, MPI_Datatype oldtype,
                           MPI_Datatype *newtype)
                            __attribute__ ((weak, alias("PMPI_Type_create_darray")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Type_create_darray
#define MPI_Type_create_darray PMPI_Type_create_darray
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Type_create_darray(int size, int rank, int ndims, const int array_of_gsizes[],
                                       const int array_of_distribs[], const int array_of_dargs[],
                                       const int array_of_psizes[], int order, MPI_Datatype oldtype,
                                       MPI_Datatype *newtype)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNEG(size, "size", mpi_errno);
            MPIR_ERRTEST_ARGNEG(ndims, "ndims", mpi_errno);
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
            MPIR_ERR_CHKANDJUMP3((rank < 0 || rank >= size), mpi_errno, MPI_ERR_RANK,
                                  "**argrange", "**argrange %s %d %d", "rank", rank, (size - 1));
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    *newtype = MPI_DATATYPE_NULL;
    mpi_errno = MPIR_Type_create_darray_impl(size, rank, ndims, array_of_gsizes, array_of_distribs,
                                             array_of_dargs, array_of_psizes, order, oldtype, newtype);
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
                                     "**mpi_type_create_darray",
                                     "**mpi_type_create_darray %d %d %d %p %p %p %p %d %D %p", size,
                                     rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs,
                                     array_of_psizes, order, oldtype, newtype);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Type_create_darray(QMPI_Context context, int tool_id, int size, int rank, int ndims,
                            const int array_of_gsizes[], const int array_of_distribs[],
                            const int array_of_dargs[], const int array_of_psizes[], int order,
                            MPI_Datatype oldtype, MPI_Datatype *newtype)
{
    return internal_Type_create_darray(size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs, array_of_psizes, order, oldtype, newtype);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Type_create_darray(int size, int rank, int ndims, const int array_of_gsizes[],
                           const int array_of_distribs[], const int array_of_dargs[],
                           const int array_of_psizes[], int order, MPI_Datatype oldtype,
                           MPI_Datatype *newtype)
{
    QMPI_Context context;
    QMPI_Type_create_darray_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Type_create_darray(context, 0, size, rank, ndims, array_of_gsizes,
                                       array_of_distribs, array_of_dargs, array_of_psizes, order,
                                       oldtype, newtype);

    fn_ptr = (QMPI_Type_create_darray_t *) MPIR_QMPI_first_fn_ptrs[MPI_TYPE_CREATE_DARRAY_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_TYPE_CREATE_DARRAY_T], size, rank,
            ndims, array_of_gsizes, array_of_distribs, array_of_dargs, array_of_psizes, order,
            oldtype, newtype);
}
#else /* ENABLE_QMPI */
int MPI_Type_create_darray(int size, int rank, int ndims, const int array_of_gsizes[],
                           const int array_of_distribs[], const int array_of_dargs[],
                           const int array_of_psizes[], int order, MPI_Datatype oldtype,
                           MPI_Datatype *newtype)
{
    return internal_Type_create_darray(size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs, array_of_psizes, order, oldtype, newtype);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Type_create_darray_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Type_create_darray_c = PMPI_Type_create_darray_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Type_create_darray_c  MPI_Type_create_darray_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Type_create_darray_c as PMPI_Type_create_darray_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Type_create_darray_c(int size, int rank, int ndims, const MPI_Count array_of_gsizes[],
                             const int array_of_distribs[], const int array_of_dargs[],
                             const int array_of_psizes[], int order, MPI_Datatype oldtype,
                             MPI_Datatype *newtype)
                              __attribute__ ((weak, alias("PMPI_Type_create_darray_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Type_create_darray_c
#define MPI_Type_create_darray_c PMPI_Type_create_darray_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Type_create_darray_c(int size, int rank, int ndims,
                                         const MPI_Count array_of_gsizes[],
                                         const int array_of_distribs[], const int array_of_dargs[],
                                         const int array_of_psizes[], int order,
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
            MPIR_ERRTEST_ARGNEG(size, "size", mpi_errno);
            MPIR_ERRTEST_ARGNEG(ndims, "ndims", mpi_errno);
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
            MPIR_ERR_CHKANDJUMP3((rank < 0 || rank >= size), mpi_errno, MPI_ERR_RANK,
                                  "**argrange", "**argrange %s %d %d", "rank", rank, (size - 1));
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        *newtype = MPI_DATATYPE_NULL;
        mpi_errno = MPIR_Type_create_darray_large_impl(size, rank, ndims, (MPI_Aint *) array_of_gsizes,
                                                       array_of_distribs, array_of_dargs, array_of_psizes,
                                                       order, oldtype, newtype);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        MPI_Aint *array_of_gsizes_c = MPL_malloc(ndims * sizeof(MPI_Aint), MPL_MEM_OTHER);
        for (int i = 0; i < ndims; i++) {
            if (array_of_gsizes[i] > MPIR_AINT_MAX) {
                mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                                 __func__, __LINE__, MPI_ERR_OTHER,
                                                 "**too_big_for_input",
                                                 "**too_big_for_input %s", "array_of_gsizes[i]");
                goto fn_fail;
            }
            array_of_gsizes_c[i] = array_of_gsizes[i];
        }
        *newtype = MPI_DATATYPE_NULL;
        mpi_errno = MPIR_Type_create_darray_large_impl(size, rank, ndims, array_of_gsizes_c,
                                                       array_of_distribs, array_of_dargs, array_of_psizes,
                                                       order, oldtype, newtype);
        if (mpi_errno) {
            goto fn_fail;
        }
        MPL_free(array_of_gsizes_c);
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
                                     "**mpi_type_create_darray_c",
                                     "**mpi_type_create_darray_c %d %d %d %p %p %p %p %d %D %p", size,
                                     rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs,
                                     array_of_psizes, order, oldtype, newtype);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Type_create_darray_c(QMPI_Context context, int tool_id, int size, int rank, int ndims,
                              const MPI_Count array_of_gsizes[], const int array_of_distribs[],
                              const int array_of_dargs[], const int array_of_psizes[], int order,
                              MPI_Datatype oldtype, MPI_Datatype *newtype)
{
    return internal_Type_create_darray_c(size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs, array_of_psizes, order, oldtype, newtype);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Type_create_darray_c(int size, int rank, int ndims, const MPI_Count array_of_gsizes[],
                             const int array_of_distribs[], const int array_of_dargs[],
                             const int array_of_psizes[], int order, MPI_Datatype oldtype,
                             MPI_Datatype *newtype)
{
    QMPI_Context context;
    QMPI_Type_create_darray_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Type_create_darray_c(context, 0, size, rank, ndims, array_of_gsizes,
                                         array_of_distribs, array_of_dargs, array_of_psizes, order,
                                         oldtype, newtype);

    fn_ptr = (QMPI_Type_create_darray_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_TYPE_CREATE_DARRAY_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_TYPE_CREATE_DARRAY_C_T], size, rank,
            ndims, array_of_gsizes, array_of_distribs, array_of_dargs, array_of_psizes, order,
            oldtype, newtype);
}
#else /* ENABLE_QMPI */
int MPI_Type_create_darray_c(int size, int rank, int ndims, const MPI_Count array_of_gsizes[],
                             const int array_of_distribs[], const int array_of_dargs[],
                             const int array_of_psizes[], int order, MPI_Datatype oldtype,
                             MPI_Datatype *newtype)
{
    return internal_Type_create_darray_c(size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs, array_of_psizes, order, oldtype, newtype);
}

#endif /* ENABLE_QMPI */
