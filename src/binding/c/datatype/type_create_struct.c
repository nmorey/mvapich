/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Type_create_struct */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Type_create_struct = PMPI_Type_create_struct
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Type_create_struct  MPI_Type_create_struct
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Type_create_struct as PMPI_Type_create_struct
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Type_create_struct(int count, const int array_of_blocklengths[],
                           const MPI_Aint array_of_displacements[],
                           const MPI_Datatype array_of_types[], MPI_Datatype *newtype)
                            __attribute__ ((weak, alias("PMPI_Type_create_struct")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Type_create_struct
#define MPI_Type_create_struct PMPI_Type_create_struct
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Type_create_struct(int count, const int array_of_blocklengths[],
                                       const MPI_Aint array_of_displacements[],
                                       const MPI_Datatype array_of_types[], MPI_Datatype *newtype)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_ARGNULL(array_of_blocklengths, "array_of_blocklengths", mpi_errno);
                for (int i = 0; i < count; i++) {
                    MPIR_ERRTEST_COUNT(array_of_blocklengths[i], mpi_errno);
                }
            }
            if (count > 0) {
                MPIR_ERRTEST_ARGNULL(array_of_displacements, "array_of_displacements", mpi_errno);
            }
            if (count > 0) {
                MPIR_ERRTEST_ARGNULL(array_of_types, "array_of_types", mpi_errno);
                for (int i = 0; i < count; i++) {
                    if (!HANDLE_IS_BUILTIN(array_of_types[i])) {
                        MPIR_Datatype *datatype_ptr;
                        MPIR_Datatype_get_ptr(array_of_types[i], datatype_ptr);
                        MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                        if (mpi_errno) {
                            goto fn_fail;
                        }
                    }
                }
            }
            MPIR_ERRTEST_ARGNULL(newtype, "newtype", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    *newtype = MPI_DATATYPE_NULL;
    mpi_errno = MPIR_Type_create_struct_impl(count, array_of_blocklengths, array_of_displacements,
                                             array_of_types, newtype);
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
                                     "**mpi_type_create_struct",
                                     "**mpi_type_create_struct %d %p %p %p %p", count,
                                     array_of_blocklengths, array_of_displacements, array_of_types,
                                     newtype);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Type_create_struct(QMPI_Context context, int tool_id, int count,
                            const int array_of_blocklengths[],
                            const MPI_Aint array_of_displacements[],
                            const MPI_Datatype array_of_types[], MPI_Datatype *newtype)
{
    return internal_Type_create_struct(count, array_of_blocklengths, array_of_displacements, array_of_types, newtype);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Type_create_struct(int count, const int array_of_blocklengths[],
                           const MPI_Aint array_of_displacements[],
                           const MPI_Datatype array_of_types[], MPI_Datatype *newtype)
{
    QMPI_Context context;
    QMPI_Type_create_struct_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Type_create_struct(context, 0, count, array_of_blocklengths,
                                       array_of_displacements, array_of_types, newtype);

    fn_ptr = (QMPI_Type_create_struct_t *) MPIR_QMPI_first_fn_ptrs[MPI_TYPE_CREATE_STRUCT_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_TYPE_CREATE_STRUCT_T], count,
            array_of_blocklengths, array_of_displacements, array_of_types, newtype);
}
#else /* ENABLE_QMPI */
int MPI_Type_create_struct(int count, const int array_of_blocklengths[],
                           const MPI_Aint array_of_displacements[],
                           const MPI_Datatype array_of_types[], MPI_Datatype *newtype)
{
    return internal_Type_create_struct(count, array_of_blocklengths, array_of_displacements, array_of_types, newtype);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Type_create_struct_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Type_create_struct_c = PMPI_Type_create_struct_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Type_create_struct_c  MPI_Type_create_struct_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Type_create_struct_c as PMPI_Type_create_struct_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Type_create_struct_c(MPI_Count count, const MPI_Count array_of_blocklengths[],
                             const MPI_Count array_of_displacements[],
                             const MPI_Datatype array_of_types[], MPI_Datatype *newtype)
                              __attribute__ ((weak, alias("PMPI_Type_create_struct_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Type_create_struct_c
#define MPI_Type_create_struct_c PMPI_Type_create_struct_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Type_create_struct_c(MPI_Count count, const MPI_Count array_of_blocklengths[],
                                         const MPI_Count array_of_displacements[],
                                         const MPI_Datatype array_of_types[],
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
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_ARGNULL(array_of_blocklengths, "array_of_blocklengths", mpi_errno);
                for (int i = 0; i < count; i++) {
                    MPIR_ERRTEST_COUNT(array_of_blocklengths[i], mpi_errno);
                }
            }
            if (count > 0) {
                MPIR_ERRTEST_ARGNULL(array_of_displacements, "array_of_displacements", mpi_errno);
            }
            if (count > 0) {
                MPIR_ERRTEST_ARGNULL(array_of_types, "array_of_types", mpi_errno);
                for (int i = 0; i < count; i++) {
                    if (!HANDLE_IS_BUILTIN(array_of_types[i])) {
                        MPIR_Datatype *datatype_ptr;
                        MPIR_Datatype_get_ptr(array_of_types[i], datatype_ptr);
                        MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                        if (mpi_errno) {
                            goto fn_fail;
                        }
                    }
                }
            }
            MPIR_ERRTEST_ARGNULL(newtype, "newtype", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        *newtype = MPI_DATATYPE_NULL;
        mpi_errno = MPIR_Type_create_struct_large_impl((MPI_Aint) count, (MPI_Aint *) array_of_blocklengths,
                                                       (MPI_Aint *) array_of_displacements, array_of_types,
                                                       newtype);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        MPI_Aint *array_of_blocklengths_c = MPL_malloc(count * sizeof(MPI_Aint), MPL_MEM_OTHER);
        for (int i = 0; i < count; i++) {
            if (array_of_blocklengths[i] > MPIR_AINT_MAX) {
                mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                                 __func__, __LINE__, MPI_ERR_OTHER,
                                                 "**too_big_for_input",
                                                 "**too_big_for_input %s", "array_of_blocklengths[i]");
                goto fn_fail;
            }
            array_of_blocklengths_c[i] = array_of_blocklengths[i];
        }
        MPI_Aint *array_of_displacements_c = MPL_malloc(count * sizeof(MPI_Aint), MPL_MEM_OTHER);
        for (int i = 0; i < count; i++) {
            if (array_of_displacements[i] > MPIR_AINT_MAX) {
                mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                                 __func__, __LINE__, MPI_ERR_OTHER,
                                                 "**too_big_for_input",
                                                 "**too_big_for_input %s", "array_of_displacements[i]");
                goto fn_fail;
            }
            array_of_displacements_c[i] = array_of_displacements[i];
        }
        *newtype = MPI_DATATYPE_NULL;
        mpi_errno = MPIR_Type_create_struct_large_impl(count, array_of_blocklengths_c,
                                                       array_of_displacements_c, array_of_types, newtype);
        if (mpi_errno) {
            goto fn_fail;
        }
        MPL_free(array_of_blocklengths_c);
        MPL_free(array_of_displacements_c);
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
                                     "**mpi_type_create_struct_c",
                                     "**mpi_type_create_struct_c %c %p %p %p %p", count,
                                     array_of_blocklengths, array_of_displacements, array_of_types,
                                     newtype);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Type_create_struct_c(QMPI_Context context, int tool_id, MPI_Count count,
                              const MPI_Count array_of_blocklengths[],
                              const MPI_Count array_of_displacements[],
                              const MPI_Datatype array_of_types[], MPI_Datatype *newtype)
{
    return internal_Type_create_struct_c(count, array_of_blocklengths, array_of_displacements, array_of_types, newtype);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Type_create_struct_c(MPI_Count count, const MPI_Count array_of_blocklengths[],
                             const MPI_Count array_of_displacements[],
                             const MPI_Datatype array_of_types[], MPI_Datatype *newtype)
{
    QMPI_Context context;
    QMPI_Type_create_struct_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Type_create_struct_c(context, 0, count, array_of_blocklengths,
                                         array_of_displacements, array_of_types, newtype);

    fn_ptr = (QMPI_Type_create_struct_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_TYPE_CREATE_STRUCT_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_TYPE_CREATE_STRUCT_C_T], count,
            array_of_blocklengths, array_of_displacements, array_of_types, newtype);
}
#else /* ENABLE_QMPI */
int MPI_Type_create_struct_c(MPI_Count count, const MPI_Count array_of_blocklengths[],
                             const MPI_Count array_of_displacements[],
                             const MPI_Datatype array_of_types[], MPI_Datatype *newtype)
{
    return internal_Type_create_struct_c(count, array_of_blocklengths, array_of_displacements, array_of_types, newtype);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Type_struct */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Type_struct = PMPI_Type_struct
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Type_struct  MPI_Type_struct
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Type_struct as PMPI_Type_struct
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Type_struct(int count, int array_of_blocklengths[], MPI_Aint array_of_displacements[],
                    MPI_Datatype array_of_types[], MPI_Datatype *newtype)
                     __attribute__ ((weak, alias("PMPI_Type_struct")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Type_struct
#define MPI_Type_struct PMPI_Type_struct
#endif /* MPICH_MPI_FROM_PMPI */

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Type_struct(QMPI_Context context, int tool_id, int count, int array_of_blocklengths[],
                     MPI_Aint array_of_displacements[], MPI_Datatype array_of_types[],
                     MPI_Datatype *newtype)
{
    return internal_Type_create_struct(count, array_of_blocklengths, array_of_displacements, array_of_types, newtype);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Type_struct(int count, int array_of_blocklengths[], MPI_Aint array_of_displacements[],
                    MPI_Datatype array_of_types[], MPI_Datatype *newtype)
{
    QMPI_Context context;
    QMPI_Type_struct_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Type_struct(context, 0, count, array_of_blocklengths, array_of_displacements,
                                array_of_types, newtype);

    fn_ptr = (QMPI_Type_struct_t *) MPIR_QMPI_first_fn_ptrs[MPI_TYPE_STRUCT_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_TYPE_STRUCT_T], count,
            array_of_blocklengths, array_of_displacements, array_of_types, newtype);
}
#else /* ENABLE_QMPI */
int MPI_Type_struct(int count, int array_of_blocklengths[], MPI_Aint array_of_displacements[],
                    MPI_Datatype array_of_types[], MPI_Datatype *newtype)
{
    return internal_Type_create_struct(count, array_of_blocklengths, array_of_displacements, array_of_types, newtype);
}

#endif /* ENABLE_QMPI */
