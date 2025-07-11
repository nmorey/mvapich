/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Get_processor_name */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Get_processor_name = PMPI_Get_processor_name
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Get_processor_name  MPI_Get_processor_name
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Get_processor_name as PMPI_Get_processor_name
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Get_processor_name(char *name, int *resultlen)
     __attribute__ ((weak, alias("PMPI_Get_processor_name")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Get_processor_name
#define MPI_Get_processor_name PMPI_Get_processor_name
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Get_processor_name(char *name, int *resultlen)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            if (MPI_MAX_PROCESSOR_NAME > 0) {
                MPIR_ERRTEST_ARGNULL(name, "name", mpi_errno);
            }
            MPIR_ERRTEST_ARGNULL(resultlen, "resultlen", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPID_Get_processor_name(name, MPI_MAX_PROCESSOR_NAME, resultlen);
    if (mpi_errno != MPI_SUCCESS)
        goto fn_fail;
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    MPID_THREAD_CS_EXIT(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_get_processor_name", "**mpi_get_processor_name %p %p", name,
                                     resultlen);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Get_processor_name(QMPI_Context context, int tool_id, char *name, int *resultlen)
{
    return internal_Get_processor_name(name, resultlen);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Get_processor_name(char *name, int *resultlen)
{
    QMPI_Context context;
    QMPI_Get_processor_name_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Get_processor_name(context, 0, name, resultlen);

    fn_ptr = (QMPI_Get_processor_name_t *) MPIR_QMPI_first_fn_ptrs[MPI_GET_PROCESSOR_NAME_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_GET_PROCESSOR_NAME_T], name,
            resultlen);
}
#else /* ENABLE_QMPI */
int MPI_Get_processor_name(char *name, int *resultlen)
{
    return internal_Get_processor_name(name, resultlen);
}

#endif /* ENABLE_QMPI */
