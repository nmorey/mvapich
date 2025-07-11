/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Group_f2c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Group_f2c = PMPI_Group_f2c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Group_f2c  MPI_Group_f2c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Group_f2c as PMPI_Group_f2c
#elif defined(HAVE_WEAK_ATTRIBUTE)
MPI_Group MPI_Group_f2c(MPI_Fint group)  __attribute__ ((weak, alias("PMPI_Group_f2c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Group_f2c
#define MPI_Group_f2c PMPI_Group_f2c
#endif /* MPICH_MPI_FROM_PMPI */

static MPI_Group internal_Group_f2c(MPI_Fint group)
{
    return (MPI_Group) group;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
MPI_Group QMPI_Group_f2c(QMPI_Context context, int tool_id, MPI_Fint group)
{
    return internal_Group_f2c(group);
}
#endif /* MPICH_MPI_FROM_PMPI */
MPI_Group MPI_Group_f2c(MPI_Fint group)
{
    QMPI_Context context;
    QMPI_Group_f2c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Group_f2c(context, 0, group);

    fn_ptr = (QMPI_Group_f2c_t *) MPIR_QMPI_first_fn_ptrs[MPI_GROUP_F2C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_GROUP_F2C_T], group);
}
#else /* ENABLE_QMPI */
MPI_Group MPI_Group_f2c(MPI_Fint group)
{
    return internal_Group_f2c(group);
}

#endif /* ENABLE_QMPI */
