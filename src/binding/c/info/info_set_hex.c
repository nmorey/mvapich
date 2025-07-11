/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPIX_Info_set_hex */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPIX_Info_set_hex = PMPIX_Info_set_hex
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPIX_Info_set_hex  MPIX_Info_set_hex
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPIX_Info_set_hex as PMPIX_Info_set_hex
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPIX_Info_set_hex(MPI_Info info, const char *key, const void *value, int value_size)
     __attribute__ ((weak, alias("PMPIX_Info_set_hex")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPIX_Info_set_hex
#define MPIX_Info_set_hex PMPIX_Info_set_hex
#endif /* MPICH_MPI_FROM_PMPI */

static int internalX_Info_set_hex(MPI_Info info, const char *key, const void *value,
                                  int value_size)
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
            MPIR_ERR_CHKANDJUMP((!key), mpi_errno, MPI_ERR_INFO_KEY, "**infokeynull");
            int keylen = (int) strlen(key);
            MPIR_ERR_CHKANDJUMP((keylen > MPI_MAX_INFO_KEY), mpi_errno, MPI_ERR_INFO_KEY, "**infokeylong");
            MPIR_ERR_CHKANDJUMP((keylen == 0), mpi_errno, MPI_ERR_INFO_KEY, "**infokeyempty");
            MPIR_ERRTEST_ARGNULL(value, "value", mpi_errno);
            MPIR_ERRTEST_ARGNEG(value_size, "value_size", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Info_set_hex_impl(info_ptr, key, value, value_size);
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
                                     "**mpix_info_set_hex", "**mpix_info_set_hex %I %s %p %d", info,
                                     key, value, value_size);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPIX_Info_set_hex(QMPI_Context context, int tool_id, MPI_Info info, const char *key,
                       const void *value, int value_size)
{
    return internalX_Info_set_hex(info, key, value, value_size);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPIX_Info_set_hex(MPI_Info info, const char *key, const void *value, int value_size)
{
    QMPI_Context context;
    QMPIX_Info_set_hex_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPIX_Info_set_hex(context, 0, info, key, value, value_size);

    fn_ptr = (QMPIX_Info_set_hex_t *) MPIR_QMPI_first_fn_ptrs[MPIX_INFO_SET_HEX_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPIX_INFO_SET_HEX_T], info, key, value,
            value_size);
}
#else /* ENABLE_QMPI */
int MPIX_Info_set_hex(MPI_Info info, const char *key, const void *value, int value_size)
{
    return internalX_Info_set_hex(info, key, value, value_size);
}

#endif /* ENABLE_QMPI */
