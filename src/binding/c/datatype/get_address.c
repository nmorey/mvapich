/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Get_address */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Get_address = PMPI_Get_address
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Get_address  MPI_Get_address
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Get_address as PMPI_Get_address
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Get_address(const void *location, MPI_Aint *address)
     __attribute__ ((weak, alias("PMPI_Get_address")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Get_address
#define MPI_Get_address PMPI_Get_address
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Get_address(const void *location, MPI_Aint *address)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(address, "address", mpi_errno);
            /* location can be NULL (MPI_BOTTOM) */
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
    mpi_errno = MPIR_Get_address_impl(location, address);
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
                                     "**mpi_get_address", "**mpi_get_address %p %p", location,
                                     address);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Get_address(QMPI_Context context, int tool_id, const void *location, MPI_Aint *address)
{
    return internal_Get_address(location, address);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Get_address(const void *location, MPI_Aint *address)
{
    QMPI_Context context;
    QMPI_Get_address_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Get_address(context, 0, location, address);

    fn_ptr = (QMPI_Get_address_t *) MPIR_QMPI_first_fn_ptrs[MPI_GET_ADDRESS_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_GET_ADDRESS_T], location, address);
}
#else /* ENABLE_QMPI */
int MPI_Get_address(const void *location, MPI_Aint *address)
{
    return internal_Get_address(location, address);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Address */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Address = PMPI_Address
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Address  MPI_Address
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Address as PMPI_Address
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Address(void *location, MPI_Aint *address)  __attribute__ ((weak, alias("PMPI_Address")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Address
#define MPI_Address PMPI_Address
#endif /* MPICH_MPI_FROM_PMPI */

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Address(QMPI_Context context, int tool_id, void *location, MPI_Aint *address)
{
    return internal_Get_address(location, address);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Address(void *location, MPI_Aint *address)
{
    QMPI_Context context;
    QMPI_Address_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Address(context, 0, location, address);

    fn_ptr = (QMPI_Address_t *) MPIR_QMPI_first_fn_ptrs[MPI_ADDRESS_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_ADDRESS_T], location, address);
}
#else /* ENABLE_QMPI */
int MPI_Address(void *location, MPI_Aint *address)
{
    return internal_Get_address(location, address);
}

#endif /* ENABLE_QMPI */
