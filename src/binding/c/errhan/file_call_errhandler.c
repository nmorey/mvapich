/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_File_call_errhandler */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_call_errhandler = PMPI_File_call_errhandler
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_call_errhandler  MPI_File_call_errhandler
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_call_errhandler as PMPI_File_call_errhandler
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_call_errhandler(MPI_File fh, int errorcode)
     __attribute__ ((weak, alias("PMPI_File_call_errhandler")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_call_errhandler
#define MPI_File_call_errhandler PMPI_File_call_errhandler
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_call_errhandler(MPI_File fh, int errorcode)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();
    MPIR_FUNC_TERSE_ENTER;

    /* ... body of routine ... */
    mpi_errno = MPIR_File_call_errhandler_impl(fh, errorcode);
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
                                     "**mpi_file_call_errhandler", "**mpi_file_call_errhandler %F %d",
                                     fh, errorcode);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_call_errhandler(QMPI_Context context, int tool_id, MPI_File fh, int errorcode)
{
    return internal_File_call_errhandler(fh, errorcode);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_call_errhandler(MPI_File fh, int errorcode)
{
    QMPI_Context context;
    QMPI_File_call_errhandler_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_call_errhandler(context, 0, fh, errorcode);

    fn_ptr = (QMPI_File_call_errhandler_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_CALL_ERRHANDLER_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_CALL_ERRHANDLER_T], fh,
            errorcode);
}
#else /* ENABLE_QMPI */
int MPI_File_call_errhandler(MPI_File fh, int errorcode)
{
    return internal_File_call_errhandler(fh, errorcode);
}

#endif /* ENABLE_QMPI */
