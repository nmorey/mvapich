/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Comm_spawn_multiple */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Comm_spawn_multiple = PMPI_Comm_spawn_multiple
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Comm_spawn_multiple  MPI_Comm_spawn_multiple
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Comm_spawn_multiple as PMPI_Comm_spawn_multiple
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Comm_spawn_multiple(int count, char *array_of_commands[], char **array_of_argv[],
                            const int array_of_maxprocs[], const MPI_Info array_of_info[], int root,
                            MPI_Comm comm, MPI_Comm *intercomm, int array_of_errcodes[])
                             __attribute__ ((weak, alias("PMPI_Comm_spawn_multiple")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Comm_spawn_multiple
#define MPI_Comm_spawn_multiple PMPI_Comm_spawn_multiple
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Comm_spawn_multiple(int count, char *array_of_commands[],
                                        char **array_of_argv[], const int array_of_maxprocs[],
                                        const MPI_Info array_of_info[], int root, MPI_Comm comm,
                                        MPI_Comm *intercomm, int array_of_errcodes[])
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Comm *comm_ptr ATTRIBUTE((unused)) = NULL;
    MPIR_Info **array_of_info_ptrs = NULL;

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
    if (comm_ptr->rank == root) {
        array_of_info_ptrs = MPL_malloc(count * sizeof(MPIR_Info *), MPL_MEM_OTHER);
        for (int i = 0; i < count; i++) {
            MPIR_Info_get_ptr(array_of_info[i], array_of_info_ptrs[i]);
        }
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
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            MPIR_ERRTEST_ARGNULL(intercomm, "intercomm", mpi_errno);
            if (comm_ptr->rank == root) {
                MPIR_ERRTEST_ARGNULL(array_of_info, "array_of_info", mpi_errno);
                MPIR_ERRTEST_ARGNULL(array_of_commands, "array_of_commands", mpi_errno);
                MPIR_ERRTEST_ARGNULL(array_of_maxprocs, "array_of_maxprocs", mpi_errno);
                MPIR_ERRTEST_ARGNONPOS(count, "count", mpi_errno, MPI_ERR_ARG);
                for (int i = 0; i < count; i++) {
                    MPIR_ERRTEST_INFO_OR_NULL(array_of_info[i], mpi_errno);
                    MPIR_ERRTEST_ARGNULL(array_of_commands[i], "array_of_commands[i]", mpi_errno);
                    MPIR_ERRTEST_ARGNEG(array_of_maxprocs[i], "array_of_maxprocs[i]", mpi_errno);
                }
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    MPIR_Comm *intercomm_ptr ATTRIBUTE((unused)) = NULL;
    *intercomm = MPI_COMM_NULL;
    mpi_errno = MPIR_Comm_spawn_multiple_impl(count, array_of_commands, array_of_argv,
                                              array_of_maxprocs, array_of_info_ptrs, root, comm_ptr,
                                              &intercomm_ptr, array_of_errcodes);
    if (mpi_errno) {
        goto fn_fail;
    }
    if (intercomm_ptr) {
        MPIR_OBJ_PUBLISH_HANDLE(*intercomm, intercomm_ptr->handle);
    }
    /* ... end of body of routine ... */

  fn_exit:
    if (array_of_info_ptrs) {
        MPL_free(array_of_info_ptrs);
    }
    MPIR_FUNC_TERSE_EXIT;
    MPID_THREAD_CS_EXIT(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_comm_spawn_multiple",
                                     "**mpi_comm_spawn_multiple %d %p %p %p %p %i %C %p %p", count,
                                     array_of_commands, array_of_argv, array_of_maxprocs, array_of_info,
                                     root, comm, intercomm, array_of_errcodes);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Comm_spawn_multiple(QMPI_Context context, int tool_id, int count,
                             char *array_of_commands[], char **array_of_argv[],
                             const int array_of_maxprocs[], const MPI_Info array_of_info[],
                             int root, MPI_Comm comm, MPI_Comm *intercomm, int array_of_errcodes[])
{
    return internal_Comm_spawn_multiple(count, array_of_commands, array_of_argv, array_of_maxprocs, array_of_info, root, comm, intercomm, array_of_errcodes);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Comm_spawn_multiple(int count, char *array_of_commands[], char **array_of_argv[],
                            const int array_of_maxprocs[], const MPI_Info array_of_info[], int root,
                            MPI_Comm comm, MPI_Comm *intercomm, int array_of_errcodes[])
{
    QMPI_Context context;
    QMPI_Comm_spawn_multiple_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Comm_spawn_multiple(context, 0, count, array_of_commands, array_of_argv,
                                        array_of_maxprocs, array_of_info, root, comm, intercomm,
                                        array_of_errcodes);

    fn_ptr = (QMPI_Comm_spawn_multiple_t *) MPIR_QMPI_first_fn_ptrs[MPI_COMM_SPAWN_MULTIPLE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_COMM_SPAWN_MULTIPLE_T], count,
            array_of_commands, array_of_argv, array_of_maxprocs, array_of_info, root, comm,
            intercomm, array_of_errcodes);
}
#else /* ENABLE_QMPI */
int MPI_Comm_spawn_multiple(int count, char *array_of_commands[], char **array_of_argv[],
                            const int array_of_maxprocs[], const MPI_Info array_of_info[], int root,
                            MPI_Comm comm, MPI_Comm *intercomm, int array_of_errcodes[])
{
    return internal_Comm_spawn_multiple(count, array_of_commands, array_of_argv, array_of_maxprocs, array_of_info, root, comm, intercomm, array_of_errcodes);
}

#endif /* ENABLE_QMPI */
