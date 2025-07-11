/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Alloc_mem */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Alloc_mem = PMPI_Alloc_mem
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Alloc_mem  MPI_Alloc_mem
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Alloc_mem as PMPI_Alloc_mem
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Alloc_mem(MPI_Aint size, MPI_Info info, void *baseptr)
     __attribute__ ((weak, alias("PMPI_Alloc_mem")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Alloc_mem
#define MPI_Alloc_mem PMPI_Alloc_mem
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Alloc_mem(MPI_Aint size, MPI_Info info, void *baseptr)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Info *info_ptr ATTRIBUTE((unused)) = NULL;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_INFO_OR_NULL(info, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    if (info != MPI_INFO_NULL) {
        MPIR_Info_get_ptr(info, info_ptr);
    }

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            if (info != MPI_INFO_NULL) {
                MPIR_Info_valid_ptr(info_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            MPIR_ERRTEST_ARGNEG(size, "size", mpi_errno);
            MPIR_ERRTEST_ARGNULL(baseptr, "baseptr", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    void *ap = MPID_Alloc_mem(size, info_ptr);

    /* --BEGIN ERROR HANDLING-- */
    if (!ap) {
        mpi_errno =
            MPIR_Err_create_code(MPI_SUCCESS, MPIR_ERR_RECOVERABLE, __func__, __LINE__,
                                 MPI_ERR_NO_MEM, "**allocmem", 0);
        goto fn_fail;
    }
    /* --END ERROR HANDLING-- */

    MPL_VG_MEM_INIT(ap, size);
    *(void **) baseptr = ap;
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    MPID_THREAD_CS_EXIT(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_alloc_mem", "**mpi_alloc_mem %L %I %p", (long long) size,
                                     info, baseptr);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Alloc_mem(QMPI_Context context, int tool_id, MPI_Aint size, MPI_Info info, void *baseptr)
{
    return internal_Alloc_mem(size, info, baseptr);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Alloc_mem(MPI_Aint size, MPI_Info info, void *baseptr)
{
    QMPI_Context context;
    QMPI_Alloc_mem_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Alloc_mem(context, 0, size, info, baseptr);

    fn_ptr = (QMPI_Alloc_mem_t *) MPIR_QMPI_first_fn_ptrs[MPI_ALLOC_MEM_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_ALLOC_MEM_T], size, info, baseptr);
}
#else /* ENABLE_QMPI */
int MPI_Alloc_mem(MPI_Aint size, MPI_Info info, void *baseptr)
{
    return internal_Alloc_mem(size, info, baseptr);
}

#endif /* ENABLE_QMPI */
