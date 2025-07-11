/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Type_create_hvector */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Type_create_hvector = PMPI_Type_create_hvector
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Type_create_hvector  MPI_Type_create_hvector
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Type_create_hvector as PMPI_Type_create_hvector
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Type_create_hvector(int count, int blocklength, MPI_Aint stride, MPI_Datatype oldtype,
                            MPI_Datatype *newtype)
                             __attribute__ ((weak, alias("PMPI_Type_create_hvector")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Type_create_hvector
#define MPI_Type_create_hvector PMPI_Type_create_hvector
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Type_create_hvector(int count, int blocklength, MPI_Aint stride,
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
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            MPIR_ERRTEST_COUNT(blocklength, mpi_errno);
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
    mpi_errno = MPIR_Type_create_hvector_impl(count, blocklength, stride, oldtype, newtype);
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
                                     "**mpi_type_create_hvector",
                                     "**mpi_type_create_hvector %d %d %L %D %p", count, blocklength,
                                     (long long) stride, oldtype, newtype);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Type_create_hvector(QMPI_Context context, int tool_id, int count, int blocklength,
                             MPI_Aint stride, MPI_Datatype oldtype, MPI_Datatype *newtype)
{
    return internal_Type_create_hvector(count, blocklength, stride, oldtype, newtype);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Type_create_hvector(int count, int blocklength, MPI_Aint stride, MPI_Datatype oldtype,
                            MPI_Datatype *newtype)
{
    QMPI_Context context;
    QMPI_Type_create_hvector_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Type_create_hvector(context, 0, count, blocklength, stride, oldtype, newtype);

    fn_ptr = (QMPI_Type_create_hvector_t *) MPIR_QMPI_first_fn_ptrs[MPI_TYPE_CREATE_HVECTOR_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_TYPE_CREATE_HVECTOR_T], count,
            blocklength, stride, oldtype, newtype);
}
#else /* ENABLE_QMPI */
int MPI_Type_create_hvector(int count, int blocklength, MPI_Aint stride, MPI_Datatype oldtype,
                            MPI_Datatype *newtype)
{
    return internal_Type_create_hvector(count, blocklength, stride, oldtype, newtype);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Type_create_hvector_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Type_create_hvector_c = PMPI_Type_create_hvector_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Type_create_hvector_c  MPI_Type_create_hvector_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Type_create_hvector_c as PMPI_Type_create_hvector_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Type_create_hvector_c(MPI_Count count, MPI_Count blocklength, MPI_Count stride,
                              MPI_Datatype oldtype, MPI_Datatype *newtype)
                               __attribute__ ((weak, alias("PMPI_Type_create_hvector_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Type_create_hvector_c
#define MPI_Type_create_hvector_c PMPI_Type_create_hvector_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Type_create_hvector_c(MPI_Count count, MPI_Count blocklength, MPI_Count stride,
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
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            MPIR_ERRTEST_COUNT(blocklength, mpi_errno);
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
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        *newtype = MPI_DATATYPE_NULL;
        mpi_errno = MPIR_Type_create_hvector_large_impl((MPI_Aint) count, (MPI_Aint) blocklength,
                                                        (MPI_Aint) stride, oldtype, newtype);
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
        if (blocklength > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "blocklength");
            goto fn_fail;
        }
        if (stride > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "stride");
            goto fn_fail;
        }
        *newtype = MPI_DATATYPE_NULL;
        mpi_errno = MPIR_Type_create_hvector_large_impl(count, blocklength, stride, oldtype, newtype);
        if (mpi_errno) {
            goto fn_fail;
        }
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
                                     "**mpi_type_create_hvector_c",
                                     "**mpi_type_create_hvector_c %c %c %c %D %p", count, blocklength,
                                     stride, oldtype, newtype);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Type_create_hvector_c(QMPI_Context context, int tool_id, MPI_Count count,
                               MPI_Count blocklength, MPI_Count stride, MPI_Datatype oldtype,
                               MPI_Datatype *newtype)
{
    return internal_Type_create_hvector_c(count, blocklength, stride, oldtype, newtype);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Type_create_hvector_c(MPI_Count count, MPI_Count blocklength, MPI_Count stride,
                              MPI_Datatype oldtype, MPI_Datatype *newtype)
{
    QMPI_Context context;
    QMPI_Type_create_hvector_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Type_create_hvector_c(context, 0, count, blocklength, stride, oldtype,
                                          newtype);

    fn_ptr = (QMPI_Type_create_hvector_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_TYPE_CREATE_HVECTOR_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_TYPE_CREATE_HVECTOR_C_T], count,
            blocklength, stride, oldtype, newtype);
}
#else /* ENABLE_QMPI */
int MPI_Type_create_hvector_c(MPI_Count count, MPI_Count blocklength, MPI_Count stride,
                              MPI_Datatype oldtype, MPI_Datatype *newtype)
{
    return internal_Type_create_hvector_c(count, blocklength, stride, oldtype, newtype);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Type_hvector */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Type_hvector = PMPI_Type_hvector
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Type_hvector  MPI_Type_hvector
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Type_hvector as PMPI_Type_hvector
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Type_hvector(int count, int blocklength, MPI_Aint stride, MPI_Datatype oldtype,
                     MPI_Datatype *newtype)  __attribute__ ((weak, alias("PMPI_Type_hvector")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Type_hvector
#define MPI_Type_hvector PMPI_Type_hvector
#endif /* MPICH_MPI_FROM_PMPI */

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Type_hvector(QMPI_Context context, int tool_id, int count, int blocklength,
                      MPI_Aint stride, MPI_Datatype oldtype, MPI_Datatype *newtype)
{
    return internal_Type_create_hvector(count, blocklength, stride, oldtype, newtype);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Type_hvector(int count, int blocklength, MPI_Aint stride, MPI_Datatype oldtype,
                     MPI_Datatype *newtype)
{
    QMPI_Context context;
    QMPI_Type_hvector_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Type_hvector(context, 0, count, blocklength, stride, oldtype, newtype);

    fn_ptr = (QMPI_Type_hvector_t *) MPIR_QMPI_first_fn_ptrs[MPI_TYPE_HVECTOR_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_TYPE_HVECTOR_T], count, blocklength,
            stride, oldtype, newtype);
}
#else /* ENABLE_QMPI */
int MPI_Type_hvector(int count, int blocklength, MPI_Aint stride, MPI_Datatype oldtype,
                     MPI_Datatype *newtype)
{
    return internal_Type_create_hvector(count, blocklength, stride, oldtype, newtype);
}

#endif /* ENABLE_QMPI */
