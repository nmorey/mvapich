/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Op_c2f */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Op_c2f = PMPI_Op_c2f
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Op_c2f  MPI_Op_c2f
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Op_c2f as PMPI_Op_c2f
#elif defined(HAVE_WEAK_ATTRIBUTE)
MPI_Fint MPI_Op_c2f(MPI_Op op)  __attribute__ ((weak, alias("PMPI_Op_c2f")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Op_c2f
#define MPI_Op_c2f PMPI_Op_c2f
#endif /* MPICH_MPI_FROM_PMPI */

static MPI_Fint internal_Op_c2f(MPI_Op op)
{
    return (MPI_Fint) op;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
MPI_Fint QMPI_Op_c2f(QMPI_Context context, int tool_id, MPI_Op op)
{
    return internal_Op_c2f(op);
}
#endif /* MPICH_MPI_FROM_PMPI */
MPI_Fint MPI_Op_c2f(MPI_Op op)
{
    QMPI_Context context;
    QMPI_Op_c2f_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Op_c2f(context, 0, op);

    fn_ptr = (QMPI_Op_c2f_t *) MPIR_QMPI_first_fn_ptrs[MPI_OP_C2F_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_OP_C2F_T], op);
}
#else /* ENABLE_QMPI */
MPI_Fint MPI_Op_c2f(MPI_Op op)
{
    return internal_Op_c2f(op);
}

#endif /* ENABLE_QMPI */
