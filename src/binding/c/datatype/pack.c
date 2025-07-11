/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Pack */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Pack = PMPI_Pack
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Pack  MPI_Pack
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Pack as PMPI_Pack
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Pack(const void *inbuf, int incount, MPI_Datatype datatype, void *outbuf, int outsize,
             int *position, MPI_Comm comm)  __attribute__ ((weak, alias("PMPI_Pack")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Pack
#define MPI_Pack PMPI_Pack
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Pack(const void *inbuf, int incount, MPI_Datatype datatype, void *outbuf,
                         int outsize, int *position, MPI_Comm comm)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Comm *comm_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COMM(comm, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_Comm_get_ptr(comm, comm_ptr);

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_Comm_valid_ptr(comm_ptr, mpi_errno, FALSE);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_ERRTEST_COUNT(incount, mpi_errno);
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
            MPIR_ERRTEST_ARGNEG(outsize, "outsize", mpi_errno);
            MPIR_ERRTEST_ARGNULL(position, "position", mpi_errno);
            /* MPI_BOTTOM cannot be used when count > 1 */
            if (incount > 1) {
                MPIR_ERRTEST_ARGNULL(inbuf, "inbuf", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPI_Aint dt_size;
    MPIR_Datatype_get_size_macro(datatype, dt_size);
    if (dt_size == 0) {
        goto fn_exit;
    }

    /* ... body of routine ... */
    MPI_Aint position_c = *position;
    mpi_errno = MPIR_Pack_impl(inbuf, incount, datatype, outbuf, outsize, &position_c, comm_ptr);
    if (mpi_errno) {
        goto fn_fail;
    }
    if (position_c > INT_MAX) {
        *position = MPI_UNDEFINED;
    } else {
        *position = position_c;
    }
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_pack", "**mpi_pack %p %d %D %p %d %p %C", inbuf, incount,
                                     datatype, outbuf, outsize, position, comm);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Pack(QMPI_Context context, int tool_id, const void *inbuf, int incount,
              MPI_Datatype datatype, void *outbuf, int outsize, int *position, MPI_Comm comm)
{
    return internal_Pack(inbuf, incount, datatype, outbuf, outsize, position, comm);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Pack(const void *inbuf, int incount, MPI_Datatype datatype, void *outbuf, int outsize,
             int *position, MPI_Comm comm)
{
    QMPI_Context context;
    QMPI_Pack_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Pack(context, 0, inbuf, incount, datatype, outbuf, outsize, position, comm);

    fn_ptr = (QMPI_Pack_t *) MPIR_QMPI_first_fn_ptrs[MPI_PACK_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_PACK_T], inbuf, incount, datatype,
            outbuf, outsize, position, comm);
}
#else /* ENABLE_QMPI */
int MPI_Pack(const void *inbuf, int incount, MPI_Datatype datatype, void *outbuf, int outsize,
             int *position, MPI_Comm comm)
{
    return internal_Pack(inbuf, incount, datatype, outbuf, outsize, position, comm);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Pack_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Pack_c = PMPI_Pack_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Pack_c  MPI_Pack_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Pack_c as PMPI_Pack_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Pack_c(const void *inbuf, MPI_Count incount, MPI_Datatype datatype, void *outbuf,
               MPI_Count outsize, MPI_Count *position, MPI_Comm comm)
                __attribute__ ((weak, alias("PMPI_Pack_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Pack_c
#define MPI_Pack_c PMPI_Pack_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Pack_c(const void *inbuf, MPI_Count incount, MPI_Datatype datatype,
                           void *outbuf, MPI_Count outsize, MPI_Count *position, MPI_Comm comm)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Comm *comm_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COMM(comm, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_Comm_get_ptr(comm, comm_ptr);

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_Comm_valid_ptr(comm_ptr, mpi_errno, FALSE);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_ERRTEST_COUNT(incount, mpi_errno);
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
            MPIR_ERRTEST_ARGNEG(outsize, "outsize", mpi_errno);
            MPIR_ERRTEST_ARGNULL(position, "position", mpi_errno);
            /* MPI_BOTTOM cannot be used when count > 1 */
            if (incount > 1) {
                MPIR_ERRTEST_ARGNULL(inbuf, "inbuf", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPI_Aint dt_size;
    MPIR_Datatype_get_size_macro(datatype, dt_size);
    if (dt_size == 0) {
        goto fn_exit;
    }

    /* ... body of routine ... */
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_Pack_impl(inbuf, (MPI_Aint) incount, datatype, outbuf, (MPI_Aint) outsize,
                                   (MPI_Aint *) position, comm_ptr);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (incount > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "incount");
            goto fn_fail;
        }
        if (outsize > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "outsize");
            goto fn_fail;
        }
        if (*position > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "*position");
            goto fn_fail;
        }
        MPI_Aint position_c = *position;
        mpi_errno = MPIR_Pack_impl(inbuf, incount, datatype, outbuf, outsize, &position_c, comm_ptr);
        if (mpi_errno) {
            goto fn_fail;
        }
        *position = position_c;
    }
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_pack_c", "**mpi_pack_c %p %c %D %p %c %p %C", inbuf,
                                     incount, datatype, outbuf, outsize, position, comm);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Pack_c(QMPI_Context context, int tool_id, const void *inbuf, MPI_Count incount,
                MPI_Datatype datatype, void *outbuf, MPI_Count outsize, MPI_Count *position,
                MPI_Comm comm)
{
    return internal_Pack_c(inbuf, incount, datatype, outbuf, outsize, position, comm);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Pack_c(const void *inbuf, MPI_Count incount, MPI_Datatype datatype, void *outbuf,
               MPI_Count outsize, MPI_Count *position, MPI_Comm comm)
{
    QMPI_Context context;
    QMPI_Pack_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Pack_c(context, 0, inbuf, incount, datatype, outbuf, outsize, position, comm);

    fn_ptr = (QMPI_Pack_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_PACK_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_PACK_C_T], inbuf, incount, datatype,
            outbuf, outsize, position, comm);
}
#else /* ENABLE_QMPI */
int MPI_Pack_c(const void *inbuf, MPI_Count incount, MPI_Datatype datatype, void *outbuf,
               MPI_Count outsize, MPI_Count *position, MPI_Comm comm)
{
    return internal_Pack_c(inbuf, incount, datatype, outbuf, outsize, position, comm);
}

#endif /* ENABLE_QMPI */
