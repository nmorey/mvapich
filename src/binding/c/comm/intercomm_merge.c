/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Intercomm_merge */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Intercomm_merge = PMPI_Intercomm_merge
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Intercomm_merge  MPI_Intercomm_merge
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Intercomm_merge as PMPI_Intercomm_merge
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Intercomm_merge(MPI_Comm intercomm, int high, MPI_Comm *newintracomm)
     __attribute__ ((weak, alias("PMPI_Intercomm_merge")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Intercomm_merge
#define MPI_Intercomm_merge PMPI_Intercomm_merge
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Intercomm_merge(MPI_Comm intercomm, int high, MPI_Comm *newintracomm)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Comm *intercomm_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COMM(intercomm, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_Comm_get_ptr(intercomm, intercomm_ptr);
    /* Make sure that we have a local intercommunicator */
    if (!intercomm_ptr->local_comm) {
        /* Manufacture the local communicator */
        MPII_Setup_intercomm_localcomm(intercomm_ptr);
    }

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_Comm_valid_ptr(intercomm_ptr, mpi_errno, FALSE);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_ERRTEST_ARGNULL(newintracomm, "newintracomm", mpi_errno);
            int acthigh;
            /* Check for consistent values of high in each local group.
             * The Intel test suite checks for this; it is also an easy
             * error to make */
            acthigh = high ? 1 : 0;     /* Clamp high into 1 or 0 */
            mpi_errno = MPIR_Allreduce(MPI_IN_PLACE, &acthigh, 1, MPI_INT,
                                        MPI_SUM, intercomm_ptr->local_comm, MPIR_ERR_NONE);
            MPIR_ERR_CHECK(mpi_errno);
            /* acthigh must either == 0 or the size of the local comm */
            if (acthigh != 0 && acthigh != intercomm_ptr->local_size) {
                mpi_errno = MPIR_Err_create_code(MPI_SUCCESS,
                                                 MPIR_ERR_RECOVERABLE, __func__, __LINE__,
                                                 MPI_ERR_ARG, "**notsame", "**notsame %s %s",
                                                 "high", "MPI_Intercomm_merge");
                goto fn_fail;
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPIR_Comm *newintracomm_ptr ATTRIBUTE((unused)) = NULL;
    *newintracomm = MPI_COMM_NULL;
    mpi_errno = MPIR_Intercomm_merge_impl(intercomm_ptr, high, &newintracomm_ptr);
    if (mpi_errno) {
        goto fn_fail;
    }
    if (newintracomm_ptr) {
        MPIR_OBJ_PUBLISH_HANDLE(*newintracomm, newintracomm_ptr->handle);
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
                                     "**mpi_intercomm_merge", "**mpi_intercomm_merge %C %d %p",
                                     intercomm, high, newintracomm);
#endif
    mpi_errno = MPIR_Err_return_comm(intercomm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Intercomm_merge(QMPI_Context context, int tool_id, MPI_Comm intercomm, int high,
                         MPI_Comm *newintracomm)
{
    return internal_Intercomm_merge(intercomm, high, newintracomm);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Intercomm_merge(MPI_Comm intercomm, int high, MPI_Comm *newintracomm)
{
    QMPI_Context context;
    QMPI_Intercomm_merge_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Intercomm_merge(context, 0, intercomm, high, newintracomm);

    fn_ptr = (QMPI_Intercomm_merge_t *) MPIR_QMPI_first_fn_ptrs[MPI_INTERCOMM_MERGE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_INTERCOMM_MERGE_T], intercomm, high,
            newintracomm);
}
#else /* ENABLE_QMPI */
int MPI_Intercomm_merge(MPI_Comm intercomm, int high, MPI_Comm *newintracomm)
{
    return internal_Intercomm_merge(intercomm, high, newintracomm);
}

#endif /* ENABLE_QMPI */
