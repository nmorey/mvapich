/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Type_create_resized */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Type_create_resized = PMPI_Type_create_resized
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Type_create_resized  MPI_Type_create_resized
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Type_create_resized as PMPI_Type_create_resized
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Type_create_resized(MPI_Datatype oldtype, MPI_Aint lb, MPI_Aint extent,
                            MPI_Datatype *newtype)
                             __attribute__ ((weak, alias("PMPI_Type_create_resized")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Type_create_resized
#define MPI_Type_create_resized PMPI_Type_create_resized
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Type_create_resized(MPI_Datatype oldtype, MPI_Aint lb, MPI_Aint extent,
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
    mpi_errno = MPIR_Type_create_resized_impl(oldtype, lb, extent, newtype);
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
                                     "**mpi_type_create_resized",
                                     "**mpi_type_create_resized %D %L %L %p", oldtype, (long long) lb,
                                     (long long) extent, newtype);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Type_create_resized(QMPI_Context context, int tool_id, MPI_Datatype oldtype, MPI_Aint lb,
                             MPI_Aint extent, MPI_Datatype *newtype)
{
    return internal_Type_create_resized(oldtype, lb, extent, newtype);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Type_create_resized(MPI_Datatype oldtype, MPI_Aint lb, MPI_Aint extent,
                            MPI_Datatype *newtype)
{
    QMPI_Context context;
    QMPI_Type_create_resized_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Type_create_resized(context, 0, oldtype, lb, extent, newtype);

    fn_ptr = (QMPI_Type_create_resized_t *) MPIR_QMPI_first_fn_ptrs[MPI_TYPE_CREATE_RESIZED_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_TYPE_CREATE_RESIZED_T], oldtype, lb,
            extent, newtype);
}
#else /* ENABLE_QMPI */
int MPI_Type_create_resized(MPI_Datatype oldtype, MPI_Aint lb, MPI_Aint extent,
                            MPI_Datatype *newtype)
{
    return internal_Type_create_resized(oldtype, lb, extent, newtype);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Type_create_resized_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Type_create_resized_c = PMPI_Type_create_resized_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Type_create_resized_c  MPI_Type_create_resized_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Type_create_resized_c as PMPI_Type_create_resized_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Type_create_resized_c(MPI_Datatype oldtype, MPI_Count lb, MPI_Count extent,
                              MPI_Datatype *newtype)
                               __attribute__ ((weak, alias("PMPI_Type_create_resized_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Type_create_resized_c
#define MPI_Type_create_resized_c PMPI_Type_create_resized_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Type_create_resized_c(MPI_Datatype oldtype, MPI_Count lb, MPI_Count extent,
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
        mpi_errno = MPIR_Type_create_resized_large_impl(oldtype, (MPI_Aint) lb, (MPI_Aint) extent,
                                                        newtype);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (lb > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "lb");
            goto fn_fail;
        }
        if (extent > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "extent");
            goto fn_fail;
        }
        *newtype = MPI_DATATYPE_NULL;
        mpi_errno = MPIR_Type_create_resized_large_impl(oldtype, lb, extent, newtype);
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
                                     "**mpi_type_create_resized_c",
                                     "**mpi_type_create_resized_c %D %c %c %p", oldtype, lb, extent,
                                     newtype);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Type_create_resized_c(QMPI_Context context, int tool_id, MPI_Datatype oldtype,
                               MPI_Count lb, MPI_Count extent, MPI_Datatype *newtype)
{
    return internal_Type_create_resized_c(oldtype, lb, extent, newtype);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Type_create_resized_c(MPI_Datatype oldtype, MPI_Count lb, MPI_Count extent,
                              MPI_Datatype *newtype)
{
    QMPI_Context context;
    QMPI_Type_create_resized_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Type_create_resized_c(context, 0, oldtype, lb, extent, newtype);

    fn_ptr = (QMPI_Type_create_resized_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_TYPE_CREATE_RESIZED_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_TYPE_CREATE_RESIZED_C_T], oldtype, lb,
            extent, newtype);
}
#else /* ENABLE_QMPI */
int MPI_Type_create_resized_c(MPI_Datatype oldtype, MPI_Count lb, MPI_Count extent,
                              MPI_Datatype *newtype)
{
    return internal_Type_create_resized_c(oldtype, lb, extent, newtype);
}

#endif /* ENABLE_QMPI */
