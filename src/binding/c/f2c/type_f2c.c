/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Type_f2c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Type_f2c = PMPI_Type_f2c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Type_f2c  MPI_Type_f2c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Type_f2c as PMPI_Type_f2c
#elif defined(HAVE_WEAK_ATTRIBUTE)
MPI_Datatype MPI_Type_f2c(MPI_Fint datatype)  __attribute__ ((weak, alias("PMPI_Type_f2c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Type_f2c
#define MPI_Type_f2c PMPI_Type_f2c
#endif /* MPICH_MPI_FROM_PMPI */

static MPI_Datatype internal_Type_f2c(MPI_Fint datatype)
{
    return (MPI_Datatype) datatype;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
MPI_Datatype QMPI_Type_f2c(QMPI_Context context, int tool_id, MPI_Fint datatype)
{
    return internal_Type_f2c(datatype);
}
#endif /* MPICH_MPI_FROM_PMPI */
MPI_Datatype MPI_Type_f2c(MPI_Fint datatype)
{
    QMPI_Context context;
    QMPI_Type_f2c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Type_f2c(context, 0, datatype);

    fn_ptr = (QMPI_Type_f2c_t *) MPIR_QMPI_first_fn_ptrs[MPI_TYPE_F2C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_TYPE_F2C_T], datatype);
}
#else /* ENABLE_QMPI */
MPI_Datatype MPI_Type_f2c(MPI_Fint datatype)
{
    return internal_Type_f2c(datatype);
}

#endif /* ENABLE_QMPI */
