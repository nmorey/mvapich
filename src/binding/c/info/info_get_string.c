/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Info_get_string */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Info_get_string = PMPI_Info_get_string
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Info_get_string  MPI_Info_get_string
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Info_get_string as PMPI_Info_get_string
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Info_get_string(MPI_Info info, const char *key, int *buflen, char *value, int *flag)
     __attribute__ ((weak, alias("PMPI_Info_get_string")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Info_get_string
#define MPI_Info_get_string PMPI_Info_get_string
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Info_get_string(MPI_Info info, const char *key, int *buflen, char *value,
                                    int *flag)
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
            MPIR_ERRTEST_ARGNULL(buflen, "buflen", mpi_errno);
            MPIR_ERRTEST_ARGNEG(*buflen, "*buflen", mpi_errno);
            MPIR_ERRTEST_ARGNULL(flag, "flag", mpi_errno);
            if (*buflen > 0) {
                MPIR_ERRTEST_ARGNULL(value, "value", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Info_get_string_impl(info_ptr, key, buflen, value, flag);
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
                                     "**mpi_info_get_string", "**mpi_info_get_string %I %s %p %p %p",
                                     info, key, buflen, value, flag);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Info_get_string(QMPI_Context context, int tool_id, MPI_Info info, const char *key,
                         int *buflen, char *value, int *flag)
{
    return internal_Info_get_string(info, key, buflen, value, flag);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Info_get_string(MPI_Info info, const char *key, int *buflen, char *value, int *flag)
{
    QMPI_Context context;
    QMPI_Info_get_string_t *fn_ptr;

    context.storage_stack = NULL;

    int mpi_errno = MPI_SUCCESS;
    mpi_errno = MPII_qmpi_init();
    if (mpi_errno != MPI_SUCCESS) {
        return mpi_errno;
    }

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Info_get_string(context, 0, info, key, buflen, value, flag);

    fn_ptr = (QMPI_Info_get_string_t *) MPIR_QMPI_first_fn_ptrs[MPI_INFO_GET_STRING_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_INFO_GET_STRING_T], info, key, buflen,
            value, flag);
}
#else /* ENABLE_QMPI */
int MPI_Info_get_string(MPI_Info info, const char *key, int *buflen, char *value, int *flag)
{
    return internal_Info_get_string(info, key, buflen, value, flag);
}

#endif /* ENABLE_QMPI */
