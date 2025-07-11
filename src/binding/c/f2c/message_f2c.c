/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Message_f2c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Message_f2c = PMPI_Message_f2c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Message_f2c  MPI_Message_f2c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Message_f2c as PMPI_Message_f2c
#elif defined(HAVE_WEAK_ATTRIBUTE)
MPI_Message MPI_Message_f2c(MPI_Fint message)  __attribute__ ((weak, alias("PMPI_Message_f2c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Message_f2c
#define MPI_Message_f2c PMPI_Message_f2c
#endif /* MPICH_MPI_FROM_PMPI */

static MPI_Message internal_Message_f2c(MPI_Fint message)
{
    return (MPI_Message) message;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
MPI_Message QMPI_Message_f2c(QMPI_Context context, int tool_id, MPI_Fint message)
{
    return internal_Message_f2c(message);
}
#endif /* MPICH_MPI_FROM_PMPI */
MPI_Message MPI_Message_f2c(MPI_Fint message)
{
    QMPI_Context context;
    QMPI_Message_f2c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Message_f2c(context, 0, message);

    fn_ptr = (QMPI_Message_f2c_t *) MPIR_QMPI_first_fn_ptrs[MPI_MESSAGE_F2C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_MESSAGE_F2C_T], message);
}
#else /* ENABLE_QMPI */
MPI_Message MPI_Message_f2c(MPI_Fint message)
{
    return internal_Message_f2c(message);
}

#endif /* ENABLE_QMPI */
