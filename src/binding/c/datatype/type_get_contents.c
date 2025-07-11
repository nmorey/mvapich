/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Type_get_contents */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Type_get_contents = PMPI_Type_get_contents
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Type_get_contents  MPI_Type_get_contents
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Type_get_contents as PMPI_Type_get_contents
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Type_get_contents(MPI_Datatype datatype, int max_integers, int max_addresses,
                          int max_datatypes, int array_of_integers[], MPI_Aint array_of_addresses[],
                          MPI_Datatype array_of_datatypes[])
                           __attribute__ ((weak, alias("PMPI_Type_get_contents")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Type_get_contents
#define MPI_Type_get_contents PMPI_Type_get_contents
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Type_get_contents(MPI_Datatype datatype, int max_integers, int max_addresses,
                                      int max_datatypes, int array_of_integers[],
                                      MPI_Aint array_of_addresses[],
                                      MPI_Datatype array_of_datatypes[])
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
            if (!HANDLE_IS_BUILTIN(datatype)) {
                MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            MPIR_ERRTEST_ARGNEG(max_integers, "max_integers", mpi_errno);
            MPIR_ERRTEST_ARGNEG(max_addresses, "max_addresses", mpi_errno);
            MPIR_ERRTEST_ARGNEG(max_datatypes, "max_datatypes", mpi_errno);
            if (max_integers > 0) {
                MPIR_ERRTEST_ARGNULL(array_of_integers, "array_of_integers", mpi_errno);
            }
            if (max_addresses > 0) {
                MPIR_ERRTEST_ARGNULL(array_of_addresses, "array_of_addresses", mpi_errno);
            }
            if (max_datatypes > 0) {
                MPIR_ERRTEST_ARGNULL(array_of_datatypes, "array_of_datatypes", mpi_errno);
            }
            if (MPIR_DATATYPE_IS_PREDEFINED(datatype)) {
                mpi_errno = MPIR_Err_create_code(MPI_SUCCESS, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_TYPE, "**contentspredef", 0);
                goto fn_fail;
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Type_get_contents_impl(datatype, max_integers, max_addresses, max_datatypes,
                                            array_of_integers, array_of_addresses, array_of_datatypes);
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
                                     "**mpi_type_get_contents",
                                     "**mpi_type_get_contents %D %d %d %d %p %p %p", datatype,
                                     max_integers, max_addresses, max_datatypes, array_of_integers,
                                     array_of_addresses, array_of_datatypes);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Type_get_contents(QMPI_Context context, int tool_id, MPI_Datatype datatype,
                           int max_integers, int max_addresses, int max_datatypes,
                           int array_of_integers[], MPI_Aint array_of_addresses[],
                           MPI_Datatype array_of_datatypes[])
{
    return internal_Type_get_contents(datatype, max_integers, max_addresses, max_datatypes, array_of_integers, array_of_addresses, array_of_datatypes);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Type_get_contents(MPI_Datatype datatype, int max_integers, int max_addresses,
                          int max_datatypes, int array_of_integers[], MPI_Aint array_of_addresses[],
                          MPI_Datatype array_of_datatypes[])
{
    QMPI_Context context;
    QMPI_Type_get_contents_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Type_get_contents(context, 0, datatype, max_integers, max_addresses,
                                      max_datatypes, array_of_integers, array_of_addresses,
                                      array_of_datatypes);

    fn_ptr = (QMPI_Type_get_contents_t *) MPIR_QMPI_first_fn_ptrs[MPI_TYPE_GET_CONTENTS_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_TYPE_GET_CONTENTS_T], datatype,
            max_integers, max_addresses, max_datatypes, array_of_integers, array_of_addresses,
            array_of_datatypes);
}
#else /* ENABLE_QMPI */
int MPI_Type_get_contents(MPI_Datatype datatype, int max_integers, int max_addresses,
                          int max_datatypes, int array_of_integers[], MPI_Aint array_of_addresses[],
                          MPI_Datatype array_of_datatypes[])
{
    return internal_Type_get_contents(datatype, max_integers, max_addresses, max_datatypes, array_of_integers, array_of_addresses, array_of_datatypes);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Type_get_contents_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Type_get_contents_c = PMPI_Type_get_contents_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Type_get_contents_c  MPI_Type_get_contents_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Type_get_contents_c as PMPI_Type_get_contents_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Type_get_contents_c(MPI_Datatype datatype, MPI_Count max_integers, MPI_Count max_addresses,
                            MPI_Count max_large_counts, MPI_Count max_datatypes,
                            int array_of_integers[], MPI_Aint array_of_addresses[],
                            MPI_Count array_of_large_counts[], MPI_Datatype array_of_datatypes[])
                             __attribute__ ((weak, alias("PMPI_Type_get_contents_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Type_get_contents_c
#define MPI_Type_get_contents_c PMPI_Type_get_contents_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Type_get_contents_c(MPI_Datatype datatype, MPI_Count max_integers,
                                        MPI_Count max_addresses, MPI_Count max_large_counts,
                                        MPI_Count max_datatypes, int array_of_integers[],
                                        MPI_Aint array_of_addresses[],
                                        MPI_Count array_of_large_counts[],
                                        MPI_Datatype array_of_datatypes[])
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
            if (!HANDLE_IS_BUILTIN(datatype)) {
                MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            MPIR_ERRTEST_ARGNEG(max_integers, "max_integers", mpi_errno);
            MPIR_ERRTEST_ARGNEG(max_addresses, "max_addresses", mpi_errno);
            MPIR_ERRTEST_ARGNEG(max_large_counts, "max_large_counts", mpi_errno);
            MPIR_ERRTEST_ARGNEG(max_datatypes, "max_datatypes", mpi_errno);
            if (max_integers > 0) {
                MPIR_ERRTEST_ARGNULL(array_of_integers, "array_of_integers", mpi_errno);
            }
            if (max_addresses > 0) {
                MPIR_ERRTEST_ARGNULL(array_of_addresses, "array_of_addresses", mpi_errno);
            }
            if (max_large_counts > 0) {
                MPIR_ERRTEST_ARGNULL(array_of_large_counts, "array_of_large_counts", mpi_errno);
            }
            if (max_datatypes > 0) {
                MPIR_ERRTEST_ARGNULL(array_of_datatypes, "array_of_datatypes", mpi_errno);
            }
            if (MPIR_DATATYPE_IS_PREDEFINED(datatype)) {
                mpi_errno = MPIR_Err_create_code(MPI_SUCCESS, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_TYPE, "**contentspredef", 0);
                goto fn_fail;
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_Type_get_contents_large_impl(datatype, (MPI_Aint) max_integers,
                                                      (MPI_Aint) max_addresses, (MPI_Aint) max_large_counts,
                                                      (MPI_Aint) max_datatypes, array_of_integers,
                                                      array_of_addresses, array_of_large_counts,
                                                      array_of_datatypes);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (max_integers > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "max_integers");
            goto fn_fail;
        }
        if (max_addresses > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "max_addresses");
            goto fn_fail;
        }
        if (max_large_counts > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "max_large_counts");
            goto fn_fail;
        }
        if (max_datatypes > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "max_datatypes");
            goto fn_fail;
        }
        mpi_errno = MPIR_Type_get_contents_large_impl(datatype, max_integers, max_addresses,
                                                      max_large_counts, max_datatypes, array_of_integers,
                                                      array_of_addresses, array_of_large_counts,
                                                      array_of_datatypes);
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
                                     "**mpi_type_get_contents_c",
                                     "**mpi_type_get_contents_c %D %c %c %c %c %p %p %p %p", datatype,
                                     max_integers, max_addresses, max_large_counts, max_datatypes,
                                     array_of_integers, array_of_addresses, array_of_large_counts,
                                     array_of_datatypes);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Type_get_contents_c(QMPI_Context context, int tool_id, MPI_Datatype datatype,
                             MPI_Count max_integers, MPI_Count max_addresses,
                             MPI_Count max_large_counts, MPI_Count max_datatypes,
                             int array_of_integers[], MPI_Aint array_of_addresses[],
                             MPI_Count array_of_large_counts[], MPI_Datatype array_of_datatypes[])
{
    return internal_Type_get_contents_c(datatype, max_integers, max_addresses, max_large_counts, max_datatypes, array_of_integers, array_of_addresses, array_of_large_counts, array_of_datatypes);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Type_get_contents_c(MPI_Datatype datatype, MPI_Count max_integers, MPI_Count max_addresses,
                            MPI_Count max_large_counts, MPI_Count max_datatypes,
                            int array_of_integers[], MPI_Aint array_of_addresses[],
                            MPI_Count array_of_large_counts[], MPI_Datatype array_of_datatypes[])
{
    QMPI_Context context;
    QMPI_Type_get_contents_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Type_get_contents_c(context, 0, datatype, max_integers, max_addresses,
                                        max_large_counts, max_datatypes, array_of_integers,
                                        array_of_addresses, array_of_large_counts,
                                        array_of_datatypes);

    fn_ptr = (QMPI_Type_get_contents_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_TYPE_GET_CONTENTS_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_TYPE_GET_CONTENTS_C_T], datatype,
            max_integers, max_addresses, max_large_counts, max_datatypes, array_of_integers,
            array_of_addresses, array_of_large_counts, array_of_datatypes);
}
#else /* ENABLE_QMPI */
int MPI_Type_get_contents_c(MPI_Datatype datatype, MPI_Count max_integers, MPI_Count max_addresses,
                            MPI_Count max_large_counts, MPI_Count max_datatypes,
                            int array_of_integers[], MPI_Aint array_of_addresses[],
                            MPI_Count array_of_large_counts[], MPI_Datatype array_of_datatypes[])
{
    return internal_Type_get_contents_c(datatype, max_integers, max_addresses, max_large_counts, max_datatypes, array_of_integers, array_of_addresses, array_of_large_counts, array_of_datatypes);
}

#endif /* ENABLE_QMPI */
