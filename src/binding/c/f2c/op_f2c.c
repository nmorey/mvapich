/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Op_f2c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Op_f2c = PMPI_Op_f2c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Op_f2c  MPI_Op_f2c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Op_f2c as PMPI_Op_f2c
#elif defined(HAVE_WEAK_ATTRIBUTE)
MPI_Op MPI_Op_f2c(MPI_Fint op)  __attribute__ ((weak, alias("PMPI_Op_f2c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Op_f2c
#define MPI_Op_f2c PMPI_Op_f2c
#endif /* MPICH_MPI_FROM_PMPI */

static MPI_Op internal_Op_f2c(MPI_Fint op)
{
    return (MPI_Op) op;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
MPI_Op QMPI_Op_f2c(QMPI_Context context, int tool_id, MPI_Fint op)
{
    return internal_Op_f2c(op);
}
#endif /* MPICH_MPI_FROM_PMPI */
MPI_Op MPI_Op_f2c(MPI_Fint op)
{
    QMPI_Context context;
    QMPI_Op_f2c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Op_f2c(context, 0, op);

    fn_ptr = (QMPI_Op_f2c_t *) MPIR_QMPI_first_fn_ptrs[MPI_OP_F2C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_OP_F2C_T], op);
}
#else /* ENABLE_QMPI */
MPI_Op MPI_Op_f2c(MPI_Fint op)
{
    return internal_Op_f2c(op);
}

#endif /* ENABLE_QMPI */
