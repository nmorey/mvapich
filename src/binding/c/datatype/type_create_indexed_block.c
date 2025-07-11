/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Type_create_indexed_block */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Type_create_indexed_block = PMPI_Type_create_indexed_block
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Type_create_indexed_block  MPI_Type_create_indexed_block
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Type_create_indexed_block as PMPI_Type_create_indexed_block
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Type_create_indexed_block(int count, int blocklength, const int array_of_displacements[],
                                  MPI_Datatype oldtype, MPI_Datatype *newtype)
                                   __attribute__ ((weak, alias("PMPI_Type_create_indexed_block")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Type_create_indexed_block
#define MPI_Type_create_indexed_block PMPI_Type_create_indexed_block
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Type_create_indexed_block(int count, int blocklength,
                                              const int array_of_displacements[],
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
            if (count > 0) {
                MPIR_ERRTEST_ARGNULL(array_of_displacements, "array_of_displacements", mpi_errno);
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
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    *newtype = MPI_DATATYPE_NULL;
    mpi_errno = MPIR_Type_create_indexed_block_impl(count, blocklength, array_of_displacements, oldtype,
                                                    newtype);
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
                                     "**mpi_type_create_indexed_block",
                                     "**mpi_type_create_indexed_block %d %d %p %D %p", count,
                                     blocklength, array_of_displacements, oldtype, newtype);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Type_create_indexed_block(QMPI_Context context, int tool_id, int count, int blocklength,
                                   const int array_of_displacements[], MPI_Datatype oldtype,
                                   MPI_Datatype *newtype)
{
    return internal_Type_create_indexed_block(count, blocklength, array_of_displacements, oldtype, newtype);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Type_create_indexed_block(int count, int blocklength, const int array_of_displacements[],
                                  MPI_Datatype oldtype, MPI_Datatype *newtype)
{
    QMPI_Context context;
    QMPI_Type_create_indexed_block_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Type_create_indexed_block(context, 0, count, blocklength,
                                              array_of_displacements, oldtype, newtype);

    fn_ptr = (QMPI_Type_create_indexed_block_t *) MPIR_QMPI_first_fn_ptrs[MPI_TYPE_CREATE_INDEXED_BLOCK_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_TYPE_CREATE_INDEXED_BLOCK_T], count,
            blocklength, array_of_displacements, oldtype, newtype);
}
#else /* ENABLE_QMPI */
int MPI_Type_create_indexed_block(int count, int blocklength, const int array_of_displacements[],
                                  MPI_Datatype oldtype, MPI_Datatype *newtype)
{
    return internal_Type_create_indexed_block(count, blocklength, array_of_displacements, oldtype, newtype);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Type_create_indexed_block_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Type_create_indexed_block_c = PMPI_Type_create_indexed_block_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Type_create_indexed_block_c  MPI_Type_create_indexed_block_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Type_create_indexed_block_c as PMPI_Type_create_indexed_block_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Type_create_indexed_block_c(MPI_Count count, MPI_Count blocklength,
                                    const MPI_Count array_of_displacements[], MPI_Datatype oldtype,
                                    MPI_Datatype *newtype)
                                     __attribute__ ((weak, alias("PMPI_Type_create_indexed_block_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Type_create_indexed_block_c
#define MPI_Type_create_indexed_block_c PMPI_Type_create_indexed_block_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Type_create_indexed_block_c(MPI_Count count, MPI_Count blocklength,
                                                const MPI_Count array_of_displacements[],
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
            if (count > 0) {
                MPIR_ERRTEST_ARGNULL(array_of_displacements, "array_of_displacements", mpi_errno);
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
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        *newtype = MPI_DATATYPE_NULL;
        mpi_errno = MPIR_Type_create_indexed_block_large_impl((MPI_Aint) count, (MPI_Aint) blocklength,
                                                              (MPI_Aint *) array_of_displacements, oldtype,
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
        if (blocklength > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "blocklength");
            goto fn_fail;
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
        mpi_errno = MPIR_Type_create_indexed_block_large_impl(count, blocklength, array_of_displacements_c,
                                                              oldtype, newtype);
        if (mpi_errno) {
            goto fn_fail;
        }
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
                                     "**mpi_type_create_indexed_block_c",
                                     "**mpi_type_create_indexed_block_c %c %c %p %D %p", count,
                                     blocklength, array_of_displacements, oldtype, newtype);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Type_create_indexed_block_c(QMPI_Context context, int tool_id, MPI_Count count,
                                     MPI_Count blocklength,
                                     const MPI_Count array_of_displacements[], MPI_Datatype oldtype,
                                     MPI_Datatype *newtype)
{
    return internal_Type_create_indexed_block_c(count, blocklength, array_of_displacements, oldtype, newtype);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Type_create_indexed_block_c(MPI_Count count, MPI_Count blocklength,
                                    const MPI_Count array_of_displacements[], MPI_Datatype oldtype,
                                    MPI_Datatype *newtype)
{
    QMPI_Context context;
    QMPI_Type_create_indexed_block_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Type_create_indexed_block_c(context, 0, count, blocklength,
                                                array_of_displacements, oldtype, newtype);

    fn_ptr = (QMPI_Type_create_indexed_block_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_TYPE_CREATE_INDEXED_BLOCK_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_TYPE_CREATE_INDEXED_BLOCK_C_T], count,
            blocklength, array_of_displacements, oldtype, newtype);
}
#else /* ENABLE_QMPI */
int MPI_Type_create_indexed_block_c(MPI_Count count, MPI_Count blocklength,
                                    const MPI_Count array_of_displacements[], MPI_Datatype oldtype,
                                    MPI_Datatype *newtype)
{
    return internal_Type_create_indexed_block_c(count, blocklength, array_of_displacements, oldtype, newtype);
}

#endif /* ENABLE_QMPI */
