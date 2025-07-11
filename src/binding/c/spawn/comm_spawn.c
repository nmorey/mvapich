/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Comm_spawn */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Comm_spawn = PMPI_Comm_spawn
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Comm_spawn  MPI_Comm_spawn
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Comm_spawn as PMPI_Comm_spawn
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Comm_spawn(const char *command, char *argv[], int maxprocs, MPI_Info info, int root,
                   MPI_Comm comm, MPI_Comm *intercomm, int array_of_errcodes[])
                    __attribute__ ((weak, alias("PMPI_Comm_spawn")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Comm_spawn
#define MPI_Comm_spawn PMPI_Comm_spawn
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Comm_spawn(const char *command, char *argv[], int maxprocs, MPI_Info info,
                               int root, MPI_Comm comm, MPI_Comm *intercomm,
                               int array_of_errcodes[])
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Comm *comm_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
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
    MPIR_Info *info_ptr = NULL;
    if (comm_ptr->rank == root) {
        MPIR_Info_get_ptr(info, info_ptr);
    }

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_Comm_valid_ptr(comm_ptr, mpi_errno, FALSE);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_ERRTEST_COMM_INTRA(comm_ptr, mpi_errno);
            MPIR_ERRTEST_INTRA_ROOT(comm_ptr, root, mpi_errno);
            MPIR_ERRTEST_ARGNULL(intercomm, "intercomm", mpi_errno);
            if (comm_ptr->rank == root) {
                MPIR_ERRTEST_INFO_OR_NULL(info, mpi_errno);
                MPIR_ERRTEST_ARGNULL(command, "command", mpi_errno);
                MPIR_ERRTEST_ARGNEG(maxprocs, "maxprocs", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPIR_Comm *intercomm_ptr ATTRIBUTE((unused)) = NULL;
    *intercomm = MPI_COMM_NULL;
    mpi_errno = MPIR_Comm_spawn_impl(command, argv, maxprocs, info_ptr, root, comm_ptr, &intercomm_ptr,
                                     array_of_errcodes);
    if (mpi_errno) {
        goto fn_fail;
    }
    if (intercomm_ptr) {
        MPIR_OBJ_PUBLISH_HANDLE(*intercomm, intercomm_ptr->handle);
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
                                     "**mpi_comm_spawn", "**mpi_comm_spawn %s %p %d %I %i %C %p %p",
                                     command, argv, maxprocs, info, root, comm, intercomm,
                                     array_of_errcodes);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Comm_spawn(QMPI_Context context, int tool_id, const char *command, char *argv[],
                    int maxprocs, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *intercomm,
                    int array_of_errcodes[])
{
    return internal_Comm_spawn(command, argv, maxprocs, info, root, comm, intercomm, array_of_errcodes);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Comm_spawn(const char *command, char *argv[], int maxprocs, MPI_Info info, int root,
                   MPI_Comm comm, MPI_Comm *intercomm, int array_of_errcodes[])
{
    QMPI_Context context;
    QMPI_Comm_spawn_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Comm_spawn(context, 0, command, argv, maxprocs, info, root, comm, intercomm,
                               array_of_errcodes);

    fn_ptr = (QMPI_Comm_spawn_t *) MPIR_QMPI_first_fn_ptrs[MPI_COMM_SPAWN_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_COMM_SPAWN_T], command, argv, maxprocs,
            info, root, comm, intercomm, array_of_errcodes);
}
#else /* ENABLE_QMPI */
int MPI_Comm_spawn(const char *command, char *argv[], int maxprocs, MPI_Info info, int root,
                   MPI_Comm comm, MPI_Comm *intercomm, int array_of_errcodes[])
{
    return internal_Comm_spawn(command, argv, maxprocs, info, root, comm, intercomm, array_of_errcodes);
}

#endif /* ENABLE_QMPI */
