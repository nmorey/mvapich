/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Message_c2f */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Message_c2f = PMPI_Message_c2f
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Message_c2f  MPI_Message_c2f
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Message_c2f as PMPI_Message_c2f
#elif defined(HAVE_WEAK_ATTRIBUTE)
MPI_Fint MPI_Message_c2f(MPI_Message message)  __attribute__ ((weak, alias("PMPI_Message_c2f")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Message_c2f
#define MPI_Message_c2f PMPI_Message_c2f
#endif /* MPICH_MPI_FROM_PMPI */

static MPI_Fint internal_Message_c2f(MPI_Message message)
{
    return (MPI_Fint) message;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
MPI_Fint QMPI_Message_c2f(QMPI_Context context, int tool_id, MPI_Message message)
{
    return internal_Message_c2f(message);
}
#endif /* MPICH_MPI_FROM_PMPI */
MPI_Fint MPI_Message_c2f(MPI_Message message)
{
    QMPI_Context context;
    QMPI_Message_c2f_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Message_c2f(context, 0, message);

    fn_ptr = (QMPI_Message_c2f_t *) MPIR_QMPI_first_fn_ptrs[MPI_MESSAGE_C2F_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_MESSAGE_C2F_T], message);
}
#else /* ENABLE_QMPI */
MPI_Fint MPI_Message_c2f(MPI_Message message)
{
    return internal_Message_c2f(message);
}

#endif /* ENABLE_QMPI */
