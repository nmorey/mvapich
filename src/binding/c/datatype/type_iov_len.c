/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPIX_Type_iov_len */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPIX_Type_iov_len = PMPIX_Type_iov_len
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPIX_Type_iov_len  MPIX_Type_iov_len
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPIX_Type_iov_len as PMPIX_Type_iov_len
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPIX_Type_iov_len(MPI_Datatype datatype, MPI_Count max_iov_bytes, MPI_Count *iov_len,
                      MPI_Count *actual_iov_bytes)
                       __attribute__ ((weak, alias("PMPIX_Type_iov_len")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPIX_Type_iov_len
#define MPIX_Type_iov_len PMPIX_Type_iov_len
#endif /* MPICH_MPI_FROM_PMPI */

static int internalX_Type_iov_len(MPI_Datatype datatype, MPI_Count max_iov_bytes,
                                  MPI_Count *iov_len, MPI_Count *actual_iov_bytes)
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
                MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            MPIR_ERRTEST_ARGNEG(max_iov_bytes, "max_iov_bytes", mpi_errno);
            MPIR_ERRTEST_ARGNULL(iov_len, "iov_len", mpi_errno);
            MPIR_ERRTEST_ARGNULL(actual_iov_bytes, "actual_iov_bytes", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPI_Aint max_iov_bytes_i, iov_len_i, actual_iov_bytes_i;

    max_iov_bytes_i = (MPI_Aint) max_iov_bytes;
    MPIR_Assert(max_iov_bytes_i == max_iov_bytes);

    mpi_errno = MPIR_Typerep_iov_len(1, datatype, max_iov_bytes_i, &iov_len_i, &actual_iov_bytes_i);
    if (mpi_errno) {
        goto fn_fail;
    }

    *iov_len = iov_len_i;
    MPIR_Assert(*iov_len == iov_len_i);
    *actual_iov_bytes = actual_iov_bytes_i;
    MPIR_Assert(*actual_iov_bytes == actual_iov_bytes_i);
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    MPID_THREAD_CS_EXIT(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpix_type_iov_len", "**mpix_type_iov_len %D %c %p %p", datatype,
                                     max_iov_bytes, iov_len, actual_iov_bytes);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPIX_Type_iov_len(QMPI_Context context, int tool_id, MPI_Datatype datatype,
                       MPI_Count max_iov_bytes, MPI_Count *iov_len, MPI_Count *actual_iov_bytes)
{
    return internalX_Type_iov_len(datatype, max_iov_bytes, iov_len, actual_iov_bytes);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPIX_Type_iov_len(MPI_Datatype datatype, MPI_Count max_iov_bytes, MPI_Count *iov_len,
                      MPI_Count *actual_iov_bytes)
{
    QMPI_Context context;
    QMPIX_Type_iov_len_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPIX_Type_iov_len(context, 0, datatype, max_iov_bytes, iov_len, actual_iov_bytes);

    fn_ptr = (QMPIX_Type_iov_len_t *) MPIR_QMPI_first_fn_ptrs[MPIX_TYPE_IOV_LEN_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPIX_TYPE_IOV_LEN_T], datatype,
            max_iov_bytes, iov_len, actual_iov_bytes);
}
#else /* ENABLE_QMPI */
int MPIX_Type_iov_len(MPI_Datatype datatype, MPI_Count max_iov_bytes, MPI_Count *iov_len,
                      MPI_Count *actual_iov_bytes)
{
    return internalX_Type_iov_len(datatype, max_iov_bytes, iov_len, actual_iov_bytes);
}

#endif /* ENABLE_QMPI */
