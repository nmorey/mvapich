/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Status_get_tag */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Status_get_tag = PMPI_Status_get_tag
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Status_get_tag  MPI_Status_get_tag
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Status_get_tag as PMPI_Status_get_tag
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Status_get_tag(MPI_Status *status, int *tag)
     __attribute__ ((weak, alias("PMPI_Status_get_tag")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Status_get_tag
#define MPI_Status_get_tag PMPI_Status_get_tag
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Status_get_tag(MPI_Status *status, int *tag)
{
    *tag = status->MPI_TAG;
    return MPI_SUCCESS;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Status_get_tag(QMPI_Context context, int tool_id, MPI_Status *status, int *tag)
{
    return internal_Status_get_tag(status, tag);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Status_get_tag(MPI_Status *status, int *tag)
{
    QMPI_Context context;
    QMPI_Status_get_tag_t *fn_ptr;

    context.storage_stack = NULL;

    int mpi_errno = MPI_SUCCESS;
    mpi_errno = MPII_qmpi_init();
    if (mpi_errno != MPI_SUCCESS) {
        return mpi_errno;
    }

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Status_get_tag(context, 0, status, tag);

    fn_ptr = (QMPI_Status_get_tag_t *) MPIR_QMPI_first_fn_ptrs[MPI_STATUS_GET_TAG_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_STATUS_GET_TAG_T], status, tag);
}
#else /* ENABLE_QMPI */
int MPI_Status_get_tag(MPI_Status *status, int *tag)
{
    return internal_Status_get_tag(status, tag);
}

#endif /* ENABLE_QMPI */
