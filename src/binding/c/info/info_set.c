/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Info_set */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Info_set = PMPI_Info_set
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Info_set  MPI_Info_set
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Info_set as PMPI_Info_set
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Info_set(MPI_Info info, const char *key, const char *value)
     __attribute__ ((weak, alias("PMPI_Info_set")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Info_set
#define MPI_Info_set PMPI_Info_set
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Info_set(MPI_Info info, const char *key, const char *value)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Info *info_ptr ATTRIBUTE((unused)) = NULL;
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_INFO(info, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_Info_get_ptr(info, info_ptr);

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_Info_valid_ptr(info_ptr, mpi_errno);
            if (mpi_errno) {
                goto fn_fail;
            }
            MPIR_ERR_CHKANDJUMP((!key), mpi_errno, MPI_ERR_INFO_KEY, "**infokeynull");
            int keylen = (int) strlen(key);
            MPIR_ERR_CHKANDJUMP((keylen > MPI_MAX_INFO_KEY), mpi_errno, MPI_ERR_INFO_KEY, "**infokeylong");
            MPIR_ERR_CHKANDJUMP((keylen == 0), mpi_errno, MPI_ERR_INFO_KEY, "**infokeyempty");
            MPIR_ERRTEST_ARGNULL(value, "value", mpi_errno);
            MPIR_ERR_CHKANDJUMP((info == MPI_INFO_ENV), mpi_errno, MPI_ERR_INFO,
                                "**infoenv");
            MPIR_ERR_CHKANDJUMP((strlen(value) > MPI_MAX_INFO_VAL), mpi_errno, MPI_ERR_INFO_VALUE,
                                "**infovallong");
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Info_set_impl(info_ptr, key, value);
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
                                     "**mpi_info_set", "**mpi_info_set %I %s %s", info, key, value);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Info_set(QMPI_Context context, int tool_id, MPI_Info info, const char *key,
                  const char *value)
{
    return internal_Info_set(info, key, value);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Info_set(MPI_Info info, const char *key, const char *value)
{
    QMPI_Context context;
    QMPI_Info_set_t *fn_ptr;

    context.storage_stack = NULL;

    int mpi_errno = MPI_SUCCESS;
    mpi_errno = MPII_qmpi_init();
    if (mpi_errno != MPI_SUCCESS) {
        return mpi_errno;
    }

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Info_set(context, 0, info, key, value);

    fn_ptr = (QMPI_Info_set_t *) MPIR_QMPI_first_fn_ptrs[MPI_INFO_SET_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_INFO_SET_T], info, key, value);
}
#else /* ENABLE_QMPI */
int MPI_Info_set(MPI_Info info, const char *key, const char *value)
{
    return internal_Info_set(info, key, value);
}

#endif /* ENABLE_QMPI */
