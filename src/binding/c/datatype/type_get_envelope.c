/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Type_get_envelope */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Type_get_envelope = PMPI_Type_get_envelope
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Type_get_envelope  MPI_Type_get_envelope
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Type_get_envelope as PMPI_Type_get_envelope
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Type_get_envelope(MPI_Datatype datatype, int *num_integers, int *num_addresses,
                          int *num_datatypes, int *combiner)
                           __attribute__ ((weak, alias("PMPI_Type_get_envelope")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Type_get_envelope
#define MPI_Type_get_envelope PMPI_Type_get_envelope
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Type_get_envelope(MPI_Datatype datatype, int *num_integers, int *num_addresses,
                                      int *num_datatypes, int *combiner)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();
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
            MPIR_ERRTEST_ARGNULL(num_integers, "num_integers", mpi_errno);
            MPIR_ERRTEST_ARGNULL(num_addresses, "num_addresses", mpi_errno);
            MPIR_ERRTEST_ARGNULL(num_datatypes, "num_datatypes", mpi_errno);
            MPIR_ERRTEST_ARGNULL(combiner, "combiner", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Type_get_envelope_impl(datatype, num_integers, num_addresses, num_datatypes,
                                            combiner);
    if (mpi_errno) {
        goto fn_fail;
    }
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_type_get_envelope",
                                     "**mpi_type_get_envelope %D %p %p %p %p", datatype, num_integers,
                                     num_addresses, num_datatypes, combiner);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Type_get_envelope(QMPI_Context context, int tool_id, MPI_Datatype datatype,
                           int *num_integers, int *num_addresses, int *num_datatypes,
                           int *combiner)
{
    return internal_Type_get_envelope(datatype, num_integers, num_addresses, num_datatypes, combiner);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Type_get_envelope(MPI_Datatype datatype, int *num_integers, int *num_addresses,
                          int *num_datatypes, int *combiner)
{
    QMPI_Context context;
    QMPI_Type_get_envelope_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Type_get_envelope(context, 0, datatype, num_integers, num_addresses,
                                      num_datatypes, combiner);

    fn_ptr = (QMPI_Type_get_envelope_t *) MPIR_QMPI_first_fn_ptrs[MPI_TYPE_GET_ENVELOPE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_TYPE_GET_ENVELOPE_T], datatype,
            num_integers, num_addresses, num_datatypes, combiner);
}
#else /* ENABLE_QMPI */
int MPI_Type_get_envelope(MPI_Datatype datatype, int *num_integers, int *num_addresses,
                          int *num_datatypes, int *combiner)
{
    return internal_Type_get_envelope(datatype, num_integers, num_addresses, num_datatypes, combiner);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Type_get_envelope_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Type_get_envelope_c = PMPI_Type_get_envelope_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Type_get_envelope_c  MPI_Type_get_envelope_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Type_get_envelope_c as PMPI_Type_get_envelope_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Type_get_envelope_c(MPI_Datatype datatype, MPI_Count *num_integers,
                            MPI_Count *num_addresses, MPI_Count *num_large_counts,
                            MPI_Count *num_datatypes, int *combiner)
                             __attribute__ ((weak, alias("PMPI_Type_get_envelope_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Type_get_envelope_c
#define MPI_Type_get_envelope_c PMPI_Type_get_envelope_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Type_get_envelope_c(MPI_Datatype datatype, MPI_Count *num_integers,
                                        MPI_Count *num_addresses, MPI_Count *num_large_counts,
                                        MPI_Count *num_datatypes, int *combiner)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();
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
            MPIR_ERRTEST_ARGNULL(num_integers, "num_integers", mpi_errno);
            MPIR_ERRTEST_ARGNULL(num_addresses, "num_addresses", mpi_errno);
            MPIR_ERRTEST_ARGNULL(num_large_counts, "num_large_counts", mpi_errno);
            MPIR_ERRTEST_ARGNULL(num_datatypes, "num_datatypes", mpi_errno);
            MPIR_ERRTEST_ARGNULL(combiner, "combiner", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_Type_get_envelope_large_impl(datatype, (MPI_Aint *) num_integers,
                                                      (MPI_Aint *) num_addresses,
                                                      (MPI_Aint *) num_large_counts,
                                                      (MPI_Aint *) num_datatypes, combiner);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        MPI_Aint num_integers_c;
        MPI_Aint num_addresses_c;
        MPI_Aint num_large_counts_c;
        MPI_Aint num_datatypes_c;
        mpi_errno = MPIR_Type_get_envelope_large_impl(datatype, &num_integers_c, &num_addresses_c,
                                                      &num_large_counts_c, &num_datatypes_c, combiner);
        if (mpi_errno) {
            goto fn_fail;
        }
        *num_integers = num_integers_c;
        *num_addresses = num_addresses_c;
        *num_large_counts = num_large_counts_c;
        *num_datatypes = num_datatypes_c;
    }
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_type_get_envelope_c",
                                     "**mpi_type_get_envelope_c %D %p %p %p %p %p", datatype,
                                     num_integers, num_addresses, num_large_counts, num_datatypes,
                                     combiner);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Type_get_envelope_c(QMPI_Context context, int tool_id, MPI_Datatype datatype,
                             MPI_Count *num_integers, MPI_Count *num_addresses,
                             MPI_Count *num_large_counts, MPI_Count *num_datatypes, int *combiner)
{
    return internal_Type_get_envelope_c(datatype, num_integers, num_addresses, num_large_counts, num_datatypes, combiner);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Type_get_envelope_c(MPI_Datatype datatype, MPI_Count *num_integers,
                            MPI_Count *num_addresses, MPI_Count *num_large_counts,
                            MPI_Count *num_datatypes, int *combiner)
{
    QMPI_Context context;
    QMPI_Type_get_envelope_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Type_get_envelope_c(context, 0, datatype, num_integers, num_addresses,
                                        num_large_counts, num_datatypes, combiner);

    fn_ptr = (QMPI_Type_get_envelope_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_TYPE_GET_ENVELOPE_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_TYPE_GET_ENVELOPE_C_T], datatype,
            num_integers, num_addresses, num_large_counts, num_datatypes, combiner);
}
#else /* ENABLE_QMPI */
int MPI_Type_get_envelope_c(MPI_Datatype datatype, MPI_Count *num_integers,
                            MPI_Count *num_addresses, MPI_Count *num_large_counts,
                            MPI_Count *num_datatypes, int *combiner)
{
    return internal_Type_get_envelope_c(datatype, num_integers, num_addresses, num_large_counts, num_datatypes, combiner);
}

#endif /* ENABLE_QMPI */
