!
! Copyright (C) by Argonne National Laboratory
!     See COPYRIGHT in top-level directory
!

! -- THIS FILE IS AUTO-GENERATED -- 

module mpi_c_interface_nobuf

IMPLICIT NONE

INTERFACE

FUNCTION MPIR_Comm_create_keyval_c(comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, &
                                   extra_state) &
    bind(C, name="PMPI_Comm_create_keyval") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_funptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    IMPLICIT NONE
    TYPE(c_funptr), VALUE :: comm_copy_attr_fn
    TYPE(c_funptr), VALUE :: comm_delete_attr_fn
    INTEGER(c_int), INTENT(out) :: comm_keyval
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: extra_state
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_create_keyval_c

FUNCTION MPIR_Comm_delete_attr_c(comm, comm_keyval) &
    bind(C, name="PMPI_Comm_delete_attr") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), VALUE, INTENT(in) :: comm_keyval
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_delete_attr_c

FUNCTION MPIR_Comm_free_keyval_c(comm_keyval) &
    bind(C, name="PMPI_Comm_free_keyval") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    IMPLICIT NONE
    INTEGER(c_int), INTENT(inout) :: comm_keyval
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_free_keyval_c

FUNCTION MPIR_Comm_get_attr_c(comm, comm_keyval, attribute_val, flag, attr_type) &
    bind(C, name="MPII_Comm_get_attr") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface_glue, ONLY : MPIR_ATTR_AINT
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), VALUE, INTENT(in) :: comm_keyval
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: attribute_val
    INTEGER(c_int), INTENT(out) :: flag
    INTEGER(kind(MPIR_ATTR_AINT)), VALUE, INTENT(in) :: attr_type
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_get_attr_c

FUNCTION MPIR_Comm_set_attr_c(comm, comm_keyval, attribute_val, attr_type) &
    bind(C, name="MPII_Comm_set_attr") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface_glue, ONLY : MPIR_ATTR_AINT
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), VALUE, INTENT(in) :: comm_keyval
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: attribute_val
    INTEGER(kind(MPIR_ATTR_AINT)), VALUE, INTENT(in) :: attr_type
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_set_attr_c

FUNCTION MPIR_Type_create_keyval_c(type_copy_attr_fn, type_delete_attr_fn, type_keyval, &
                                   extra_state) &
    bind(C, name="PMPI_Type_create_keyval") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_funptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    IMPLICIT NONE
    TYPE(c_funptr), VALUE :: type_copy_attr_fn
    TYPE(c_funptr), VALUE :: type_delete_attr_fn
    INTEGER(c_int), INTENT(out) :: type_keyval
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: extra_state
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_create_keyval_c

FUNCTION MPIR_Type_delete_attr_c(datatype, type_keyval) &
    bind(C, name="PMPI_Type_delete_attr") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: type_keyval
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_delete_attr_c

FUNCTION MPIR_Type_free_keyval_c(type_keyval) &
    bind(C, name="PMPI_Type_free_keyval") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    IMPLICIT NONE
    INTEGER(c_int), INTENT(inout) :: type_keyval
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_free_keyval_c

FUNCTION MPIR_Type_get_attr_c(datatype, type_keyval, attribute_val, flag, attr_type) &
    bind(C, name="MPII_Type_get_attr") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface_glue, ONLY : MPIR_ATTR_AINT
    IMPLICIT NONE
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: type_keyval
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: attribute_val
    INTEGER(c_int), INTENT(out) :: flag
    INTEGER(kind(MPIR_ATTR_AINT)), VALUE, INTENT(in) :: attr_type
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_get_attr_c

FUNCTION MPIR_Type_set_attr_c(datatype, type_keyval, attribute_val, attr_type) &
    bind(C, name="MPII_Type_set_attr") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface_glue, ONLY : MPIR_ATTR_AINT
    IMPLICIT NONE
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: type_keyval
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: attribute_val
    INTEGER(kind(MPIR_ATTR_AINT)), VALUE, INTENT(in) :: attr_type
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_set_attr_c

FUNCTION MPIR_Win_create_keyval_c(win_copy_attr_fn, win_delete_attr_fn, win_keyval, extra_state) &
    bind(C, name="PMPI_Win_create_keyval") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_funptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    IMPLICIT NONE
    TYPE(c_funptr), VALUE :: win_copy_attr_fn
    TYPE(c_funptr), VALUE :: win_delete_attr_fn
    INTEGER(c_int), INTENT(out) :: win_keyval
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: extra_state
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_create_keyval_c

FUNCTION MPIR_Win_delete_attr_c(win, win_keyval) &
    bind(C, name="PMPI_Win_delete_attr") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Win
    IMPLICIT NONE
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_int), VALUE, INTENT(in) :: win_keyval
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_delete_attr_c

FUNCTION MPIR_Win_free_keyval_c(win_keyval) &
    bind(C, name="PMPI_Win_free_keyval") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    IMPLICIT NONE
    INTEGER(c_int), INTENT(inout) :: win_keyval
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_free_keyval_c

FUNCTION MPIR_Win_get_attr_c(win, win_keyval, attribute_val, flag, attr_type) &
    bind(C, name="MPII_Win_get_attr") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Win
    USE :: mpi_c_interface_glue, ONLY : MPIR_ATTR_AINT
    IMPLICIT NONE
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_int), VALUE, INTENT(in) :: win_keyval
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: attribute_val
    INTEGER(c_int), INTENT(out) :: flag
    INTEGER(kind(MPIR_ATTR_AINT)), VALUE, INTENT(in) :: attr_type
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_get_attr_c

FUNCTION MPIR_Win_set_attr_c(win, win_keyval, attribute_val, attr_type) &
    bind(C, name="MPII_Win_set_attr") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Win
    USE :: mpi_c_interface_glue, ONLY : MPIR_ATTR_AINT
    IMPLICIT NONE
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_int), VALUE, INTENT(in) :: win_keyval
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: attribute_val
    INTEGER(kind(MPIR_ATTR_AINT)), VALUE, INTENT(in) :: attr_type
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_set_attr_c

FUNCTION MPIR_Barrier_c(comm) &
    bind(C, name="PMPI_Barrier") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Barrier_c

FUNCTION MPIR_Barrier_init_c(comm, info, request) &
    bind(C, name="PMPI_Barrier_init") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Info, c_Request
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Barrier_init_c

FUNCTION MPIR_Ibarrier_c(comm, request) &
    bind(C, name="PMPI_Ibarrier") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Request
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Ibarrier_c

FUNCTION MPIR_Comm_compare_c(comm1, comm2, result) &
    bind(C, name="PMPI_Comm_compare") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm1
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm2
    INTEGER(c_int), INTENT(out) :: result
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_compare_c

FUNCTION MPIR_Comm_create_c(comm, group, newcomm) &
    bind(C, name="PMPI_Comm_create") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Group
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Group), VALUE, INTENT(in) :: group
    INTEGER(c_Comm), INTENT(out) :: newcomm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_create_c

FUNCTION MPIR_Comm_create_group_c(comm, group, tag, newcomm) &
    bind(C, name="PMPI_Comm_create_group") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Group
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Group), VALUE, INTENT(in) :: group
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), INTENT(out) :: newcomm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_create_group_c

FUNCTION MPIR_Comm_dup_c(comm, newcomm) &
    bind(C, name="PMPI_Comm_dup") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Comm), INTENT(out) :: newcomm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_dup_c

FUNCTION MPIR_Comm_dup_with_info_c(comm, info, newcomm) &
    bind(C, name="PMPI_Comm_dup_with_info") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Info
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Comm), INTENT(out) :: newcomm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_dup_with_info_c

FUNCTION MPIR_Comm_free_c(comm) &
    bind(C, name="PMPI_Comm_free") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), INTENT(inout) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_free_c

FUNCTION MPIR_Comm_get_info_c(comm, info_used) &
    bind(C, name="PMPI_Comm_get_info") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Info
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), INTENT(out) :: info_used
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_get_info_c

FUNCTION MPIR_Comm_get_name_c(comm, comm_name, resultlen) &
    bind(C, name="PMPI_Comm_get_name") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    character(kind=c_char), INTENT(out) :: comm_name(*)
    INTEGER(c_int), INTENT(out) :: resultlen
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_get_name_c

FUNCTION MPIR_Comm_group_c(comm, group) &
    bind(C, name="PMPI_Comm_group") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Group
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Group), INTENT(out) :: group
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_group_c

FUNCTION MPIR_Comm_idup_c(comm, newcomm, request) &
    bind(C, name="PMPI_Comm_idup") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Request
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Comm), INTENT(out) :: newcomm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_idup_c

FUNCTION MPIR_Comm_idup_with_info_c(comm, info, newcomm, request) &
    bind(C, name="PMPI_Comm_idup_with_info") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Info, c_Request
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Comm), INTENT(out) :: newcomm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_idup_with_info_c

FUNCTION MPIR_Comm_rank_c(comm, rank) &
    bind(C, name="PMPI_Comm_rank") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), INTENT(out) :: rank
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_rank_c

FUNCTION MPIR_Comm_remote_group_c(comm, group) &
    bind(C, name="PMPI_Comm_remote_group") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Group
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Group), INTENT(out) :: group
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_remote_group_c

FUNCTION MPIR_Comm_remote_size_c(comm, size) &
    bind(C, name="PMPI_Comm_remote_size") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), INTENT(out) :: size
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_remote_size_c

FUNCTION MPIR_Comm_set_info_c(comm, info) &
    bind(C, name="PMPI_Comm_set_info") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Info
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_set_info_c

FUNCTION MPIR_Comm_set_name_c(comm, comm_name) &
    bind(C, name="PMPI_Comm_set_name") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    character(kind=c_char), INTENT(in) :: comm_name(*)
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_set_name_c

FUNCTION MPIR_Comm_size_c(comm, size) &
    bind(C, name="PMPI_Comm_size") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), INTENT(out) :: size
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_size_c

FUNCTION MPIR_Comm_split_c(comm, color, key, newcomm) &
    bind(C, name="PMPI_Comm_split") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), VALUE, INTENT(in) :: color
    INTEGER(c_int), VALUE, INTENT(in) :: key
    INTEGER(c_Comm), INTENT(out) :: newcomm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_split_c

FUNCTION MPIR_Comm_split_type_c(comm, split_type, key, info, newcomm) &
    bind(C, name="PMPI_Comm_split_type") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Info
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), VALUE, INTENT(in) :: split_type
    INTEGER(c_int), VALUE, INTENT(in) :: key
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Comm), INTENT(out) :: newcomm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_split_type_c

FUNCTION MPIR_Comm_test_inter_c(comm, flag) &
    bind(C, name="PMPI_Comm_test_inter") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), INTENT(out) :: flag
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_test_inter_c

FUNCTION MPIR_Intercomm_create_c(local_comm, local_leader, peer_comm, remote_leader, tag, &
                                 newintercomm) &
    bind(C, name="PMPI_Intercomm_create") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: local_comm
    INTEGER(c_int), VALUE, INTENT(in) :: local_leader
    INTEGER(c_Comm), VALUE, INTENT(in) :: peer_comm
    INTEGER(c_int), VALUE, INTENT(in) :: remote_leader
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), INTENT(out) :: newintercomm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Intercomm_create_c

FUNCTION MPIR_Intercomm_create_from_groups_c(local_group, local_leader, remote_group, remote_leader, &
                                             stringtag, info, errhandler, newintercomm) &
    bind(C, name="PMPI_Intercomm_create_from_groups") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_c_interface_types, ONLY : c_Group, c_Info, c_Errhandler, c_Comm
    IMPLICIT NONE
    INTEGER(c_Group), VALUE, INTENT(in) :: local_group
    INTEGER(c_int), VALUE, INTENT(in) :: local_leader
    INTEGER(c_Group), VALUE, INTENT(in) :: remote_group
    INTEGER(c_int), VALUE, INTENT(in) :: remote_leader
    character(kind=c_char), INTENT(in) :: stringtag(*)
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Errhandler), VALUE, INTENT(in) :: errhandler
    INTEGER(c_Comm), INTENT(out) :: newintercomm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Intercomm_create_from_groups_c

FUNCTION MPIR_Intercomm_merge_c(intercomm, high, newintracomm) &
    bind(C, name="PMPI_Intercomm_merge") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: intercomm
    INTEGER(c_int), VALUE, INTENT(in) :: high
    INTEGER(c_Comm), INTENT(out) :: newintracomm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Intercomm_merge_c

FUNCTION MPIR_Comm_test_threadcomm_c(comm, flag) &
    bind(C, name="PMPIX_Comm_test_threadcomm") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), INTENT(out) :: flag
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_test_threadcomm_c

FUNCTION MPIR_Comm_revoke_c(comm) &
    bind(C, name="PMPIX_Comm_revoke") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_revoke_c

FUNCTION MPIR_Comm_shrink_c(comm, newcomm) &
    bind(C, name="PMPIX_Comm_shrink") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Comm), INTENT(out) :: newcomm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_shrink_c

FUNCTION MPIR_Comm_failure_ack_c(comm) &
    bind(C, name="PMPIX_Comm_failure_ack") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_failure_ack_c

FUNCTION MPIR_Comm_failure_get_acked_c(comm, failedgrp) &
    bind(C, name="PMPIX_Comm_failure_get_acked") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Group
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Group), INTENT(out) :: failedgrp
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_failure_get_acked_c

FUNCTION MPIR_Comm_agree_c(comm, flag) &
    bind(C, name="PMPIX_Comm_agree") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), INTENT(out) :: flag
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_agree_c

FUNCTION MPIR_Comm_get_failed_c(comm, failedgrp) &
    bind(C, name="PMPIX_Comm_get_failed") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Group
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Group), INTENT(out) :: failedgrp
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_get_failed_c

FUNCTION MPIR_Get_count_c(status, datatype, count) &
    bind(C, name="PMPI_Get_count") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), INTENT(out) :: count
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Get_count_c

FUNCTION MPIR_Get_count_c_large(status, datatype, count) &
    bind(C, name="PMPI_Get_count_c") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: count
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Get_count_c_large

FUNCTION MPIR_Get_elements_c(status, datatype, count) &
    bind(C, name="PMPI_Get_elements") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), INTENT(out) :: count
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Get_elements_c

FUNCTION MPIR_Get_elements_c_large(status, datatype, count) &
    bind(C, name="PMPI_Get_elements_c") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: count
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Get_elements_c_large

FUNCTION MPIR_Get_elements_x_c(status, datatype, count) &
    bind(C, name="PMPI_Get_elements_x") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: count
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Get_elements_x_c

FUNCTION MPIR_Pack_external_size_c(datarep, incount, datatype, size) &
    bind(C, name="PMPI_Pack_external_size") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    character(kind=c_char), INTENT(in) :: datarep(*)
    INTEGER(c_int), VALUE, INTENT(in) :: incount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: size
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Pack_external_size_c

FUNCTION MPIR_Pack_external_size_c_large(datarep, incount, datatype, size) &
    bind(C, name="PMPI_Pack_external_size_c") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    character(kind=c_char), INTENT(in) :: datarep(*)
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: incount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: size
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Pack_external_size_c_large

FUNCTION MPIR_Pack_size_c(incount, datatype, comm, size) &
    bind(C, name="PMPI_Pack_size") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: incount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), INTENT(out) :: size
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Pack_size_c

FUNCTION MPIR_Pack_size_c_large(incount, datatype, comm, size) &
    bind(C, name="PMPI_Pack_size_c") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: incount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: size
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Pack_size_c_large

FUNCTION MPIR_Status_set_elements_c(status, datatype, count) &
    bind(C, name="PMPI_Status_set_elements") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Status_set_elements_c

FUNCTION MPIR_Status_set_elements_c_large(status, datatype, count) &
    bind(C, name="PMPI_Status_set_elements_c") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Status_set_elements_c_large

FUNCTION MPIR_Status_set_elements_x_c(status, datatype, count) &
    bind(C, name="PMPI_Status_set_elements_x") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Status_set_elements_x_c

FUNCTION MPIR_Type_commit_c(datatype) &
    bind(C, name="PMPI_Type_commit") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_Datatype), INTENT(inout) :: datatype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_commit_c

FUNCTION MPIR_Type_contiguous_c(count, oldtype, newtype) &
    bind(C, name="PMPI_Type_contiguous") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: oldtype
    INTEGER(c_Datatype), INTENT(out) :: newtype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_contiguous_c

FUNCTION MPIR_Type_contiguous_c_large(count, oldtype, newtype) &
    bind(C, name="PMPI_Type_contiguous_c") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: oldtype
    INTEGER(c_Datatype), INTENT(out) :: newtype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_contiguous_c_large

FUNCTION MPIR_Type_create_darray_c(size, rank, ndims, array_of_gsizes, array_of_distribs, &
                                   array_of_dargs, array_of_psizes, order, oldtype, newtype) &
    bind(C, name="PMPI_Type_create_darray") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: size
    INTEGER(c_int), VALUE, INTENT(in) :: rank
    INTEGER(c_int), VALUE, INTENT(in) :: ndims
    INTEGER(c_int), INTENT(in) :: array_of_gsizes(ndims)
    INTEGER(c_int), INTENT(in) :: array_of_distribs(ndims)
    INTEGER(c_int), INTENT(in) :: array_of_dargs(ndims)
    INTEGER(c_int), INTENT(in) :: array_of_psizes(ndims)
    INTEGER(c_int), VALUE, INTENT(in) :: order
    INTEGER(c_Datatype), VALUE, INTENT(in) :: oldtype
    INTEGER(c_Datatype), INTENT(out) :: newtype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_create_darray_c

FUNCTION MPIR_Type_create_darray_c_large(size, rank, ndims, array_of_gsizes, array_of_distribs, &
                                         array_of_dargs, array_of_psizes, order, oldtype, &
                                         newtype) &
    bind(C, name="PMPI_Type_create_darray_c") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: size
    INTEGER(c_int), VALUE, INTENT(in) :: rank
    INTEGER(c_int), VALUE, INTENT(in) :: ndims
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_gsizes(ndims)
    INTEGER(c_int), INTENT(in) :: array_of_distribs(ndims)
    INTEGER(c_int), INTENT(in) :: array_of_dargs(ndims)
    INTEGER(c_int), INTENT(in) :: array_of_psizes(ndims)
    INTEGER(c_int), VALUE, INTENT(in) :: order
    INTEGER(c_Datatype), VALUE, INTENT(in) :: oldtype
    INTEGER(c_Datatype), INTENT(out) :: newtype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_create_darray_c_large

FUNCTION MPIR_Type_create_f90_complex_c(p, r, newtype) &
    bind(C, name="PMPI_Type_create_f90_complex") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: p
    INTEGER(c_int), VALUE, INTENT(in) :: r
    INTEGER(c_Datatype), INTENT(out) :: newtype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_create_f90_complex_c

FUNCTION MPIR_Type_create_f90_integer_c(r, newtype) &
    bind(C, name="PMPI_Type_create_f90_integer") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: r
    INTEGER(c_Datatype), INTENT(out) :: newtype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_create_f90_integer_c

FUNCTION MPIR_Type_create_f90_real_c(p, r, newtype) &
    bind(C, name="PMPI_Type_create_f90_real") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: p
    INTEGER(c_int), VALUE, INTENT(in) :: r
    INTEGER(c_Datatype), INTENT(out) :: newtype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_create_f90_real_c

FUNCTION MPIR_Type_create_hindexed_c(count, array_of_blocklengths, array_of_displacements, oldtype, &
                                     newtype) &
    bind(C, name="PMPI_Type_create_hindexed") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_int), INTENT(in) :: array_of_blocklengths(count)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: array_of_displacements(count)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: oldtype
    INTEGER(c_Datatype), INTENT(out) :: newtype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_create_hindexed_c

FUNCTION MPIR_Type_create_hindexed_c_large(count, array_of_blocklengths, array_of_displacements, &
                                           oldtype, newtype) &
    bind(C, name="PMPI_Type_create_hindexed_c") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_blocklengths(count)
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_displacements(count)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: oldtype
    INTEGER(c_Datatype), INTENT(out) :: newtype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_create_hindexed_c_large

FUNCTION MPIR_Type_create_hindexed_block_c(count, blocklength, array_of_displacements, oldtype, &
                                           newtype) &
    bind(C, name="PMPI_Type_create_hindexed_block") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_int), VALUE, INTENT(in) :: blocklength
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: array_of_displacements(count)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: oldtype
    INTEGER(c_Datatype), INTENT(out) :: newtype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_create_hindexed_block_c

FUNCTION MPIR_Type_create_hindexed_block_c_large(count, blocklength, array_of_displacements, &
                                                 oldtype, newtype) &
    bind(C, name="PMPI_Type_create_hindexed_block_c") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: blocklength
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_displacements(count)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: oldtype
    INTEGER(c_Datatype), INTENT(out) :: newtype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_create_hindexed_block_c_large

FUNCTION MPIR_Type_create_hvector_c(count, blocklength, stride, oldtype, newtype) &
    bind(C, name="PMPI_Type_create_hvector") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_int), VALUE, INTENT(in) :: blocklength
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: stride
    INTEGER(c_Datatype), VALUE, INTENT(in) :: oldtype
    INTEGER(c_Datatype), INTENT(out) :: newtype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_create_hvector_c

FUNCTION MPIR_Type_create_hvector_c_large(count, blocklength, stride, oldtype, newtype) &
    bind(C, name="PMPI_Type_create_hvector_c") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: blocklength
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: stride
    INTEGER(c_Datatype), VALUE, INTENT(in) :: oldtype
    INTEGER(c_Datatype), INTENT(out) :: newtype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_create_hvector_c_large

FUNCTION MPIR_Type_create_indexed_block_c(count, blocklength, array_of_displacements, oldtype, &
                                          newtype) &
    bind(C, name="PMPI_Type_create_indexed_block") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_int), VALUE, INTENT(in) :: blocklength
    INTEGER(c_int), INTENT(in) :: array_of_displacements(count)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: oldtype
    INTEGER(c_Datatype), INTENT(out) :: newtype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_create_indexed_block_c

FUNCTION MPIR_Type_create_indexed_block_c_large(count, blocklength, array_of_displacements, oldtype, &
                                                newtype) &
    bind(C, name="PMPI_Type_create_indexed_block_c") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: blocklength
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_displacements(count)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: oldtype
    INTEGER(c_Datatype), INTENT(out) :: newtype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_create_indexed_block_c_large

FUNCTION MPIR_Type_create_resized_c(oldtype, lb, extent, newtype) &
    bind(C, name="PMPI_Type_create_resized") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_Datatype), VALUE, INTENT(in) :: oldtype
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: lb
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: extent
    INTEGER(c_Datatype), INTENT(out) :: newtype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_create_resized_c

FUNCTION MPIR_Type_create_struct_c(count, array_of_blocklengths, array_of_displacements, &
                                   array_of_types, newtype) &
    bind(C, name="PMPI_Type_create_struct") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_int), INTENT(in) :: array_of_blocklengths(count)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: array_of_displacements(count)
    INTEGER(c_Datatype), INTENT(in) :: array_of_types(count)
    INTEGER(c_Datatype), INTENT(out) :: newtype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_create_struct_c

FUNCTION MPIR_Type_create_struct_c_large(count, array_of_blocklengths, array_of_displacements, &
                                         array_of_types, newtype) &
    bind(C, name="PMPI_Type_create_struct_c") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_blocklengths(count)
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_displacements(count)
    INTEGER(c_Datatype), INTENT(in) :: array_of_types(count)
    INTEGER(c_Datatype), INTENT(out) :: newtype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_create_struct_c_large

FUNCTION MPIR_Type_create_subarray_c(ndims, array_of_sizes, array_of_subsizes, array_of_starts, &
                                     order, oldtype, newtype) &
    bind(C, name="PMPI_Type_create_subarray") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: ndims
    INTEGER(c_int), INTENT(in) :: array_of_sizes(ndims)
    INTEGER(c_int), INTENT(in) :: array_of_subsizes(ndims)
    INTEGER(c_int), INTENT(in) :: array_of_starts(ndims)
    INTEGER(c_int), VALUE, INTENT(in) :: order
    INTEGER(c_Datatype), VALUE, INTENT(in) :: oldtype
    INTEGER(c_Datatype), INTENT(out) :: newtype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_create_subarray_c

FUNCTION MPIR_Type_create_subarray_c_large(ndims, array_of_sizes, array_of_subsizes, &
                                           array_of_starts, order, oldtype, newtype) &
    bind(C, name="PMPI_Type_create_subarray_c") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: ndims
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_sizes(ndims)
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_subsizes(ndims)
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_starts(ndims)
    INTEGER(c_int), VALUE, INTENT(in) :: order
    INTEGER(c_Datatype), VALUE, INTENT(in) :: oldtype
    INTEGER(c_Datatype), INTENT(out) :: newtype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_create_subarray_c_large

FUNCTION MPIR_Type_dup_c(oldtype, newtype) &
    bind(C, name="PMPI_Type_dup") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_Datatype), VALUE, INTENT(in) :: oldtype
    INTEGER(c_Datatype), INTENT(out) :: newtype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_dup_c

FUNCTION MPIR_Type_free_c(datatype) &
    bind(C, name="PMPI_Type_free") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_Datatype), INTENT(inout) :: datatype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_free_c

FUNCTION MPIR_Type_get_contents_c(datatype, max_integers, max_addresses, max_datatypes, &
                                  array_of_integers, array_of_addresses, array_of_datatypes) &
    bind(C, name="PMPI_Type_get_contents") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: max_integers
    INTEGER(c_int), VALUE, INTENT(in) :: max_addresses
    INTEGER(c_int), VALUE, INTENT(in) :: max_datatypes
    INTEGER(c_int), INTENT(out) :: array_of_integers(max_integers)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: array_of_addresses(max_addresses)
    INTEGER(c_Datatype), INTENT(out) :: array_of_datatypes(max_datatypes)
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_get_contents_c

FUNCTION MPIR_Type_get_contents_c_large(datatype, max_integers, max_addresses, max_large_counts, &
                                        max_datatypes, array_of_integers, array_of_addresses, &
                                        array_of_large_counts, array_of_datatypes) &
    bind(C, name="PMPI_Type_get_contents_c") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: max_integers
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: max_addresses
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: max_large_counts
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: max_datatypes
    INTEGER(c_int), INTENT(out) :: array_of_integers(max_integers)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: array_of_addresses(max_addresses)
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: array_of_large_counts(max_large_counts)
    INTEGER(c_Datatype), INTENT(out) :: array_of_datatypes(max_datatypes)
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_get_contents_c_large

FUNCTION MPIR_Type_get_envelope_c(datatype, num_integers, num_addresses, num_datatypes, combiner) &
    bind(C, name="PMPI_Type_get_envelope") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), INTENT(out) :: num_integers
    INTEGER(c_int), INTENT(out) :: num_addresses
    INTEGER(c_int), INTENT(out) :: num_datatypes
    INTEGER(c_int), INTENT(out) :: combiner
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_get_envelope_c

FUNCTION MPIR_Type_get_envelope_c_large(datatype, num_integers, num_addresses, num_large_counts, &
                                        num_datatypes, combiner) &
    bind(C, name="PMPI_Type_get_envelope_c") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: num_integers
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: num_addresses
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: num_large_counts
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: num_datatypes
    INTEGER(c_int), INTENT(out) :: combiner
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_get_envelope_c_large

FUNCTION MPIR_Type_get_extent_c(datatype, lb, extent) &
    bind(C, name="PMPI_Type_get_extent") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: lb
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: extent
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_get_extent_c

FUNCTION MPIR_Type_get_extent_x_c(datatype, lb, extent) &
    bind(C, name="PMPI_Type_get_extent_x") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: lb
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: extent
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_get_extent_x_c

FUNCTION MPIR_Type_get_name_c(datatype, type_name, resultlen) &
    bind(C, name="PMPI_Type_get_name") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    character(kind=c_char), INTENT(out) :: type_name(*)
    INTEGER(c_int), INTENT(out) :: resultlen
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_get_name_c

FUNCTION MPIR_Type_get_true_extent_c(datatype, true_lb, true_extent) &
    bind(C, name="PMPI_Type_get_true_extent") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: true_lb
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: true_extent
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_get_true_extent_c

FUNCTION MPIR_Type_get_true_extent_x_c(datatype, true_lb, true_extent) &
    bind(C, name="PMPI_Type_get_true_extent_x") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: true_lb
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: true_extent
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_get_true_extent_x_c

FUNCTION MPIR_Type_get_value_index_c(value_type, index_type, pair_type) &
    bind(C, name="PMPI_Type_get_value_index") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_Datatype), VALUE, INTENT(in) :: value_type
    INTEGER(c_Datatype), VALUE, INTENT(in) :: index_type
    INTEGER(c_Datatype), INTENT(out) :: pair_type
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_get_value_index_c

FUNCTION MPIR_Type_indexed_c(count, array_of_blocklengths, array_of_displacements, oldtype, &
                             newtype) &
    bind(C, name="PMPI_Type_indexed") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_int), INTENT(in) :: array_of_blocklengths(count)
    INTEGER(c_int), INTENT(in) :: array_of_displacements(count)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: oldtype
    INTEGER(c_Datatype), INTENT(out) :: newtype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_indexed_c

FUNCTION MPIR_Type_indexed_c_large(count, array_of_blocklengths, array_of_displacements, oldtype, &
                                   newtype) &
    bind(C, name="PMPI_Type_indexed_c") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_blocklengths(count)
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_displacements(count)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: oldtype
    INTEGER(c_Datatype), INTENT(out) :: newtype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_indexed_c_large

FUNCTION MPIR_Type_match_size_c(typeclass, size, datatype) &
    bind(C, name="PMPI_Type_match_size") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: typeclass
    INTEGER(c_int), VALUE, INTENT(in) :: size
    INTEGER(c_Datatype), INTENT(out) :: datatype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_match_size_c

FUNCTION MPIR_Type_set_name_c(datatype, type_name) &
    bind(C, name="PMPI_Type_set_name") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    character(kind=c_char), INTENT(in) :: type_name(*)
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_set_name_c

FUNCTION MPIR_Type_size_c(datatype, size) &
    bind(C, name="PMPI_Type_size") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), INTENT(out) :: size
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_size_c

FUNCTION MPIR_Type_size_c_large(datatype, size) &
    bind(C, name="PMPI_Type_size_c") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: size
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_size_c_large

FUNCTION MPIR_Type_size_x_c(datatype, size) &
    bind(C, name="PMPI_Type_size_x") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: size
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_size_x_c

FUNCTION MPIR_Type_vector_c(count, blocklength, stride, oldtype, newtype) &
    bind(C, name="PMPI_Type_vector") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_int), VALUE, INTENT(in) :: blocklength
    INTEGER(c_int), VALUE, INTENT(in) :: stride
    INTEGER(c_Datatype), VALUE, INTENT(in) :: oldtype
    INTEGER(c_Datatype), INTENT(out) :: newtype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_vector_c

FUNCTION MPIR_Type_vector_c_large(count, blocklength, stride, oldtype, newtype) &
    bind(C, name="PMPI_Type_vector_c") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: blocklength
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: stride
    INTEGER(c_Datatype), VALUE, INTENT(in) :: oldtype
    INTEGER(c_Datatype), INTENT(out) :: newtype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Type_vector_c_large

FUNCTION MPIR_Add_error_class_c(errorclass) &
    bind(C, name="PMPI_Add_error_class") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    IMPLICIT NONE
    INTEGER(c_int), INTENT(out) :: errorclass
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Add_error_class_c

FUNCTION MPIR_Add_error_code_c(errorclass, errorcode) &
    bind(C, name="PMPI_Add_error_code") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: errorclass
    INTEGER(c_int), INTENT(out) :: errorcode
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Add_error_code_c

FUNCTION MPIR_Add_error_string_c(errorcode, string) &
    bind(C, name="PMPI_Add_error_string") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: errorcode
    character(kind=c_char), INTENT(in) :: string(*)
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Add_error_string_c

FUNCTION MPIR_Comm_call_errhandler_c(comm, errorcode) &
    bind(C, name="PMPI_Comm_call_errhandler") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), VALUE, INTENT(in) :: errorcode
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_call_errhandler_c

FUNCTION MPII_Comm_create_errhandler_c(comm_errhandler_fn, errhandler) &
    bind(C, name="MPII_Comm_create_errhandler") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_funptr
    USE :: mpi_c_interface_types, ONLY : c_Errhandler
    IMPLICIT NONE
    TYPE(c_funptr), VALUE :: comm_errhandler_fn
    INTEGER(c_Errhandler), INTENT(out) :: errhandler
    INTEGER(c_int) :: ierror
END FUNCTION MPII_Comm_create_errhandler_c

FUNCTION MPIR_Comm_get_errhandler_c(comm, errhandler) &
    bind(C, name="PMPI_Comm_get_errhandler") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Errhandler
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Errhandler), INTENT(out) :: errhandler
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_get_errhandler_c

FUNCTION MPIR_Comm_set_errhandler_c(comm, errhandler) &
    bind(C, name="PMPI_Comm_set_errhandler") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Errhandler
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Errhandler), VALUE, INTENT(in) :: errhandler
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_set_errhandler_c

FUNCTION MPIR_Errhandler_free_c(errhandler) &
    bind(C, name="PMPI_Errhandler_free") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Errhandler
    IMPLICIT NONE
    INTEGER(c_Errhandler), INTENT(inout) :: errhandler
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Errhandler_free_c

FUNCTION MPIR_Error_class_c(errorcode, errorclass) &
    bind(C, name="PMPI_Error_class") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: errorcode
    INTEGER(c_int), INTENT(out) :: errorclass
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Error_class_c

FUNCTION MPIR_Error_string_c(errorcode, string, resultlen) &
    bind(C, name="PMPI_Error_string") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: errorcode
    character(kind=c_char), INTENT(out) :: string(*)
    INTEGER(c_int), INTENT(out) :: resultlen
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Error_string_c

FUNCTION MPIR_File_call_errhandler_c(fh, errorcode) &
    bind(C, name="PMPI_File_call_errhandler") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_File
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(c_int), VALUE, INTENT(in) :: errorcode
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_call_errhandler_c

FUNCTION MPII_File_create_errhandler_c(file_errhandler_fn, errhandler) &
    bind(C, name="MPII_File_create_errhandler") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_funptr
    USE :: mpi_c_interface_types, ONLY : c_Errhandler
    IMPLICIT NONE
    TYPE(c_funptr), VALUE :: file_errhandler_fn
    INTEGER(c_Errhandler), INTENT(out) :: errhandler
    INTEGER(c_int) :: ierror
END FUNCTION MPII_File_create_errhandler_c

FUNCTION MPIR_File_get_errhandler_c(file, errhandler) &
    bind(C, name="PMPI_File_get_errhandler") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_File, c_Errhandler
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: file
    INTEGER(c_Errhandler), INTENT(out) :: errhandler
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_get_errhandler_c

FUNCTION MPIR_File_set_errhandler_c(file, errhandler) &
    bind(C, name="PMPI_File_set_errhandler") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_File, c_Errhandler
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: file
    INTEGER(c_Errhandler), VALUE, INTENT(in) :: errhandler
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_set_errhandler_c

FUNCTION MPIR_Remove_error_class_c(errorclass) &
    bind(C, name="PMPI_Remove_error_class") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: errorclass
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Remove_error_class_c

FUNCTION MPIR_Remove_error_code_c(errorcode) &
    bind(C, name="PMPI_Remove_error_code") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: errorcode
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Remove_error_code_c

FUNCTION MPIR_Remove_error_string_c(errorcode) &
    bind(C, name="PMPI_Remove_error_string") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: errorcode
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Remove_error_string_c

FUNCTION MPIR_Session_call_errhandler_c(session, errorcode) &
    bind(C, name="PMPI_Session_call_errhandler") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Session
    IMPLICIT NONE
    INTEGER(c_Session), VALUE, INTENT(in) :: session
    INTEGER(c_int), VALUE, INTENT(in) :: errorcode
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Session_call_errhandler_c

FUNCTION MPIR_Session_create_errhandler_c(session_errhandler_fn, errhandler) &
    bind(C, name="PMPI_Session_create_errhandler") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_funptr
    USE :: mpi_c_interface_types, ONLY : c_Errhandler
    IMPLICIT NONE
    TYPE(c_funptr), VALUE :: session_errhandler_fn
    INTEGER(c_Errhandler), INTENT(out) :: errhandler
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Session_create_errhandler_c

FUNCTION MPIR_Session_get_errhandler_c(session, errhandler) &
    bind(C, name="PMPI_Session_get_errhandler") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Session, c_Errhandler
    IMPLICIT NONE
    INTEGER(c_Session), VALUE, INTENT(in) :: session
    INTEGER(c_Errhandler), INTENT(out) :: errhandler
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Session_get_errhandler_c

FUNCTION MPIR_Session_set_errhandler_c(session, errhandler) &
    bind(C, name="PMPI_Session_set_errhandler") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Session, c_Errhandler
    IMPLICIT NONE
    INTEGER(c_Session), VALUE, INTENT(in) :: session
    INTEGER(c_Errhandler), VALUE, INTENT(in) :: errhandler
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Session_set_errhandler_c

FUNCTION MPIR_Win_call_errhandler_c(win, errorcode) &
    bind(C, name="PMPI_Win_call_errhandler") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Win
    IMPLICIT NONE
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_int), VALUE, INTENT(in) :: errorcode
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_call_errhandler_c

FUNCTION MPII_Win_create_errhandler_c(win_errhandler_fn, errhandler) &
    bind(C, name="MPII_Win_create_errhandler") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_funptr
    USE :: mpi_c_interface_types, ONLY : c_Errhandler
    IMPLICIT NONE
    TYPE(c_funptr), VALUE :: win_errhandler_fn
    INTEGER(c_Errhandler), INTENT(out) :: errhandler
    INTEGER(c_int) :: ierror
END FUNCTION MPII_Win_create_errhandler_c

FUNCTION MPIR_Win_get_errhandler_c(win, errhandler) &
    bind(C, name="PMPI_Win_get_errhandler") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Win, c_Errhandler
    IMPLICIT NONE
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_Errhandler), INTENT(out) :: errhandler
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_get_errhandler_c

FUNCTION MPIR_Win_set_errhandler_c(win, errhandler) &
    bind(C, name="PMPI_Win_set_errhandler") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Win, c_Errhandler
    IMPLICIT NONE
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_Errhandler), VALUE, INTENT(in) :: errhandler
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_set_errhandler_c

FUNCTION MPIR_Group_compare_c(group1, group2, result) &
    bind(C, name="PMPI_Group_compare") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Group
    IMPLICIT NONE
    INTEGER(c_Group), VALUE, INTENT(in) :: group1
    INTEGER(c_Group), VALUE, INTENT(in) :: group2
    INTEGER(c_int), INTENT(out) :: result
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Group_compare_c

FUNCTION MPIR_Group_difference_c(group1, group2, newgroup) &
    bind(C, name="PMPI_Group_difference") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Group
    IMPLICIT NONE
    INTEGER(c_Group), VALUE, INTENT(in) :: group1
    INTEGER(c_Group), VALUE, INTENT(in) :: group2
    INTEGER(c_Group), INTENT(out) :: newgroup
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Group_difference_c

FUNCTION MPIR_Group_excl_c(group, n, ranks, newgroup) &
    bind(C, name="PMPI_Group_excl") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Group
    IMPLICIT NONE
    INTEGER(c_Group), VALUE, INTENT(in) :: group
    INTEGER(c_int), VALUE, INTENT(in) :: n
    INTEGER(c_int), INTENT(in) :: ranks(n)
    INTEGER(c_Group), INTENT(out) :: newgroup
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Group_excl_c

FUNCTION MPIR_Group_free_c(group) &
    bind(C, name="PMPI_Group_free") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Group
    IMPLICIT NONE
    INTEGER(c_Group), INTENT(inout) :: group
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Group_free_c

FUNCTION MPIR_Group_incl_c(group, n, ranks, newgroup) &
    bind(C, name="PMPI_Group_incl") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Group
    IMPLICIT NONE
    INTEGER(c_Group), VALUE, INTENT(in) :: group
    INTEGER(c_int), VALUE, INTENT(in) :: n
    INTEGER(c_int), INTENT(in) :: ranks(n)
    INTEGER(c_Group), INTENT(out) :: newgroup
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Group_incl_c

FUNCTION MPIR_Group_intersection_c(group1, group2, newgroup) &
    bind(C, name="PMPI_Group_intersection") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Group
    IMPLICIT NONE
    INTEGER(c_Group), VALUE, INTENT(in) :: group1
    INTEGER(c_Group), VALUE, INTENT(in) :: group2
    INTEGER(c_Group), INTENT(out) :: newgroup
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Group_intersection_c

FUNCTION MPIR_Group_range_excl_c(group, n, ranges, newgroup) &
    bind(C, name="PMPI_Group_range_excl") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Group
    IMPLICIT NONE
    INTEGER(c_Group), VALUE, INTENT(in) :: group
    INTEGER(c_int), VALUE, INTENT(in) :: n
    INTEGER(c_int), INTENT(in) :: ranges(n, 3)
    INTEGER(c_Group), INTENT(out) :: newgroup
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Group_range_excl_c

FUNCTION MPIR_Group_range_incl_c(group, n, ranges, newgroup) &
    bind(C, name="PMPI_Group_range_incl") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Group
    IMPLICIT NONE
    INTEGER(c_Group), VALUE, INTENT(in) :: group
    INTEGER(c_int), VALUE, INTENT(in) :: n
    INTEGER(c_int), INTENT(in) :: ranges(n, 3)
    INTEGER(c_Group), INTENT(out) :: newgroup
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Group_range_incl_c

FUNCTION MPIR_Group_rank_c(group, rank) &
    bind(C, name="PMPI_Group_rank") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Group
    IMPLICIT NONE
    INTEGER(c_Group), VALUE, INTENT(in) :: group
    INTEGER(c_int), INTENT(out) :: rank
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Group_rank_c

FUNCTION MPIR_Group_size_c(group, size) &
    bind(C, name="PMPI_Group_size") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Group
    IMPLICIT NONE
    INTEGER(c_Group), VALUE, INTENT(in) :: group
    INTEGER(c_int), INTENT(out) :: size
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Group_size_c

FUNCTION MPIR_Group_translate_ranks_c(group1, n, ranks1, group2, ranks2) &
    bind(C, name="PMPI_Group_translate_ranks") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Group
    IMPLICIT NONE
    INTEGER(c_Group), VALUE, INTENT(in) :: group1
    INTEGER(c_int), VALUE, INTENT(in) :: n
    INTEGER(c_int), INTENT(in) :: ranks1(n)
    INTEGER(c_Group), VALUE, INTENT(in) :: group2
    INTEGER(c_int), INTENT(out) :: ranks2(n)
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Group_translate_ranks_c

FUNCTION MPIR_Group_union_c(group1, group2, newgroup) &
    bind(C, name="PMPI_Group_union") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Group
    IMPLICIT NONE
    INTEGER(c_Group), VALUE, INTENT(in) :: group1
    INTEGER(c_Group), VALUE, INTENT(in) :: group2
    INTEGER(c_Group), INTENT(out) :: newgroup
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Group_union_c

FUNCTION MPIR_Info_create_c(info) &
    bind(C, name="PMPI_Info_create") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Info
    IMPLICIT NONE
    INTEGER(c_Info), INTENT(out) :: info
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Info_create_c

FUNCTION MPIR_Info_create_env_c(info) &
    bind(C, name="PMPI_Info_create_env") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Info
    IMPLICIT NONE
    INTEGER(c_Info), INTENT(out) :: info
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Info_create_env_c

FUNCTION MPIR_Info_delete_c(info, key) &
    bind(C, name="PMPI_Info_delete") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_c_interface_types, ONLY : c_Info
    IMPLICIT NONE
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    character(kind=c_char), INTENT(in) :: key(*)
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Info_delete_c

FUNCTION MPIR_Info_dup_c(info, newinfo) &
    bind(C, name="PMPI_Info_dup") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Info
    IMPLICIT NONE
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Info), INTENT(out) :: newinfo
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Info_dup_c

FUNCTION MPIR_Info_free_c(info) &
    bind(C, name="PMPI_Info_free") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Info
    IMPLICIT NONE
    INTEGER(c_Info), INTENT(inout) :: info
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Info_free_c

FUNCTION MPIR_Info_get_c(info, key, valuelen, value, flag) &
    bind(C, name="PMPI_Info_get") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_c_interface_types, ONLY : c_Info
    IMPLICIT NONE
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    character(kind=c_char), INTENT(in) :: key(*)
    INTEGER(c_int), VALUE, INTENT(in) :: valuelen
    character(kind=c_char), INTENT(out) :: value(*)
    INTEGER(c_int), INTENT(out) :: flag
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Info_get_c

FUNCTION MPIR_Info_get_nkeys_c(info, nkeys) &
    bind(C, name="PMPI_Info_get_nkeys") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Info
    IMPLICIT NONE
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_int), INTENT(out) :: nkeys
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Info_get_nkeys_c

FUNCTION MPIR_Info_get_nthkey_c(info, n, key) &
    bind(C, name="PMPI_Info_get_nthkey") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_c_interface_types, ONLY : c_Info
    IMPLICIT NONE
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_int), VALUE, INTENT(in) :: n
    character(kind=c_char), INTENT(out) :: key(*)
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Info_get_nthkey_c

FUNCTION MPIR_Info_get_string_c(info, key, buflen, value, flag) &
    bind(C, name="PMPI_Info_get_string") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_c_interface_types, ONLY : c_Info
    IMPLICIT NONE
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    character(kind=c_char), INTENT(in) :: key(*)
    INTEGER(c_int), INTENT(inout) :: buflen
    character(kind=c_char), INTENT(out) :: value(*)
    INTEGER(c_int), INTENT(out) :: flag
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Info_get_string_c

FUNCTION MPIR_Info_get_valuelen_c(info, key, valuelen, flag) &
    bind(C, name="PMPI_Info_get_valuelen") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_c_interface_types, ONLY : c_Info
    IMPLICIT NONE
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    character(kind=c_char), INTENT(in) :: key(*)
    INTEGER(c_int), INTENT(out) :: valuelen
    INTEGER(c_int), INTENT(out) :: flag
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Info_get_valuelen_c

FUNCTION MPIR_Info_set_c(info, key, value) &
    bind(C, name="PMPI_Info_set") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_c_interface_types, ONLY : c_Info
    IMPLICIT NONE
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    character(kind=c_char), INTENT(in) :: key(*)
    character(kind=c_char), INTENT(in) :: value(*)
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Info_set_c

FUNCTION MPIR_Abort_c(comm, errorcode) &
    bind(C, name="PMPI_Abort") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), VALUE, INTENT(in) :: errorcode
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Abort_c

FUNCTION MPIR_Comm_create_from_group_c(group, stringtag, info, errhandler, newcomm) &
    bind(C, name="PMPI_Comm_create_from_group") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_c_interface_types, ONLY : c_Group, c_Info, c_Errhandler, c_Comm
    IMPLICIT NONE
    INTEGER(c_Group), VALUE, INTENT(in) :: group
    character(kind=c_char), INTENT(in) :: stringtag(*)
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Errhandler), VALUE, INTENT(in) :: errhandler
    INTEGER(c_Comm), INTENT(out) :: newcomm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_create_from_group_c

FUNCTION MPIR_Finalize_c() &
    bind(C, name="PMPI_Finalize") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    IMPLICIT NONE
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Finalize_c

FUNCTION MPIR_Finalized_c(flag) &
    bind(C, name="PMPI_Finalized") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    IMPLICIT NONE
    INTEGER(c_int), INTENT(out) :: flag
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Finalized_c

FUNCTION MPIR_Group_from_session_pset_c(session, pset_name, newgroup) &
    bind(C, name="PMPI_Group_from_session_pset") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_c_interface_types, ONLY : c_Session, c_Group
    IMPLICIT NONE
    INTEGER(c_Session), VALUE, INTENT(in) :: session
    character(kind=c_char), INTENT(in) :: pset_name(*)
    INTEGER(c_Group), INTENT(out) :: newgroup
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Group_from_session_pset_c

FUNCTION MPIR_Init_c(argc, argv) &
    bind(C, name="PMPI_Init") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    IMPLICIT NONE
    TYPE(c_ptr), VALUE, INTENT(in) :: argc
    TYPE(c_ptr), VALUE, INTENT(in) :: argv
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Init_c

FUNCTION MPIR_Init_thread_c(argc, argv, required, provided) &
    bind(C, name="PMPI_Init_thread") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    IMPLICIT NONE
    TYPE(c_ptr), VALUE, INTENT(in) :: argc
    TYPE(c_ptr), VALUE, INTENT(in) :: argv
    INTEGER(c_int), VALUE, INTENT(in) :: required
    INTEGER(c_int), INTENT(out) :: provided
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Init_thread_c

FUNCTION MPIR_Initialized_c(flag) &
    bind(C, name="PMPI_Initialized") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    IMPLICIT NONE
    INTEGER(c_int), INTENT(out) :: flag
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Initialized_c

FUNCTION MPIR_Is_thread_main_c(flag) &
    bind(C, name="PMPI_Is_thread_main") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    IMPLICIT NONE
    INTEGER(c_int), INTENT(out) :: flag
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Is_thread_main_c

FUNCTION MPIR_Query_thread_c(provided) &
    bind(C, name="PMPI_Query_thread") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    IMPLICIT NONE
    INTEGER(c_int), INTENT(out) :: provided
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Query_thread_c

FUNCTION MPIR_Session_finalize_c(session) &
    bind(C, name="PMPI_Session_finalize") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Session
    IMPLICIT NONE
    INTEGER(c_Session), INTENT(inout) :: session
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Session_finalize_c

FUNCTION MPIR_Session_get_info_c(session, info_used) &
    bind(C, name="PMPI_Session_get_info") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Session, c_Info
    IMPLICIT NONE
    INTEGER(c_Session), VALUE, INTENT(in) :: session
    INTEGER(c_Info), INTENT(out) :: info_used
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Session_get_info_c

FUNCTION MPIR_Session_get_nth_pset_c(session, info, n, pset_len, pset_name) &
    bind(C, name="PMPI_Session_get_nth_pset") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_c_interface_types, ONLY : c_Session, c_Info
    IMPLICIT NONE
    INTEGER(c_Session), VALUE, INTENT(in) :: session
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_int), VALUE, INTENT(in) :: n
    INTEGER(c_int), INTENT(inout) :: pset_len
    character(kind=c_char), INTENT(out) :: pset_name(*)
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Session_get_nth_pset_c

FUNCTION MPIR_Session_get_num_psets_c(session, info, npset_names) &
    bind(C, name="PMPI_Session_get_num_psets") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Session, c_Info
    IMPLICIT NONE
    INTEGER(c_Session), VALUE, INTENT(in) :: session
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_int), INTENT(out) :: npset_names
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Session_get_num_psets_c

FUNCTION MPIR_Session_get_pset_info_c(session, pset_name, info) &
    bind(C, name="PMPI_Session_get_pset_info") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_c_interface_types, ONLY : c_Session, c_Info
    IMPLICIT NONE
    INTEGER(c_Session), VALUE, INTENT(in) :: session
    character(kind=c_char), INTENT(in) :: pset_name(*)
    INTEGER(c_Info), INTENT(out) :: info
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Session_get_pset_info_c

FUNCTION MPIR_Session_init_c(info, errhandler, session) &
    bind(C, name="PMPI_Session_init") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Info, c_Errhandler, c_Session
    IMPLICIT NONE
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Errhandler), VALUE, INTENT(in) :: errhandler
    INTEGER(c_Session), INTENT(out) :: session
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Session_init_c

FUNCTION MPIR_Aint_add_c(base, disp) &
    bind(C, name="PMPI_Aint_add") result(res)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    IMPLICIT NONE
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: base
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: disp
    INTEGER(KIND=MPI_ADDRESS_KIND) :: res
END FUNCTION MPIR_Aint_add_c

FUNCTION MPIR_Aint_diff_c(addr1, addr2) &
    bind(C, name="PMPI_Aint_diff") result(res)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    IMPLICIT NONE
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: addr1
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: addr2
    INTEGER(KIND=MPI_ADDRESS_KIND) :: res
END FUNCTION MPIR_Aint_diff_c

FUNCTION MPIR_Get_library_version_c(version, resultlen) &
    bind(C, name="PMPI_Get_library_version") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    IMPLICIT NONE
    character(kind=c_char), INTENT(out) :: version(*)
    INTEGER(c_int), INTENT(out) :: resultlen
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Get_library_version_c

FUNCTION MPIR_Get_processor_name_c(name, resultlen) &
    bind(C, name="PMPI_Get_processor_name") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    IMPLICIT NONE
    character(kind=c_char), INTENT(out) :: name(*)
    INTEGER(c_int), INTENT(out) :: resultlen
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Get_processor_name_c

FUNCTION MPIR_Get_version_c(version, subversion) &
    bind(C, name="PMPI_Get_version") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    IMPLICIT NONE
    INTEGER(c_int), INTENT(out) :: version
    INTEGER(c_int), INTENT(out) :: subversion
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Get_version_c

FUNCTION MPIR_Pcontrol_c(level) &
    bind(C, name="PMPI_Pcontrol") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: level
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Pcontrol_c

FUNCTION MPIR_GPU_query_support_c(gpu_type, is_supported) &
    bind(C, name="PMPIX_GPU_query_support") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: gpu_type
    INTEGER(c_int), INTENT(out) :: is_supported
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_GPU_query_support_c

FUNCTION MPIR_Query_cuda_support_c() &
    bind(C, name="PMPIX_Query_cuda_support") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    IMPLICIT NONE
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Query_cuda_support_c

FUNCTION MPIR_Query_ze_support_c() &
    bind(C, name="PMPIX_Query_ze_support") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    IMPLICIT NONE
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Query_ze_support_c

FUNCTION MPIR_Query_hip_support_c() &
    bind(C, name="PMPIX_Query_hip_support") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    IMPLICIT NONE
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Query_hip_support_c

FUNCTION MPIR_Op_commutative_c(op, commute) &
    bind(C, name="PMPI_Op_commutative") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Op
    IMPLICIT NONE
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_int), INTENT(out) :: commute
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Op_commutative_c

FUNCTION MPIR_Op_create_c(user_fn, commute, op) &
    bind(C, name="MPII_op_create") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_funptr
    USE :: mpi_c_interface_types, ONLY : c_Op
    IMPLICIT NONE
    TYPE(c_funptr), VALUE :: user_fn
    INTEGER(c_int), VALUE, INTENT(in) :: commute
    INTEGER(c_Op), INTENT(out) :: op
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Op_create_c

FUNCTION MPIR_Op_create_c_large(user_fn, commute, op) &
    bind(C, name="PMPI_Op_create_c") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_funptr
    USE :: mpi_c_interface_types, ONLY : c_Op
    IMPLICIT NONE
    TYPE(c_funptr), VALUE :: user_fn
    INTEGER(c_int), VALUE, INTENT(in) :: commute
    INTEGER(c_Op), INTENT(out) :: op
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Op_create_c_large

FUNCTION MPIR_Op_free_c(op) &
    bind(C, name="PMPI_Op_free") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Op
    IMPLICIT NONE
    INTEGER(c_Op), INTENT(inout) :: op
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Op_free_c

FUNCTION MPIR_Parrived_c(request, partition, flag) &
    bind(C, name="PMPI_Parrived") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Request
    IMPLICIT NONE
    INTEGER(c_Request), VALUE, INTENT(in) :: request
    INTEGER(c_int), VALUE, INTENT(in) :: partition
    INTEGER(c_int), INTENT(out) :: flag
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Parrived_c

FUNCTION MPIR_Pready_c(partition, request) &
    bind(C, name="PMPI_Pready") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Request
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: partition
    INTEGER(c_Request), VALUE, INTENT(in) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Pready_c

FUNCTION MPIR_Pready_list_c(length, array_of_partitions, request) &
    bind(C, name="PMPI_Pready_list") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Request
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: length
    INTEGER(c_int), INTENT(in) :: array_of_partitions(length)
    INTEGER(c_Request), VALUE, INTENT(in) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Pready_list_c

FUNCTION MPIR_Pready_range_c(partition_low, partition_high, request) &
    bind(C, name="PMPI_Pready_range") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Request
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: partition_low
    INTEGER(c_int), VALUE, INTENT(in) :: partition_high
    INTEGER(c_Request), VALUE, INTENT(in) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Pready_range_c

FUNCTION MPIR_Buffer_detach_c(buffer_addr, size) &
    bind(C, name="PMPI_Buffer_detach") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, C_PTR
    IMPLICIT NONE
    TYPE(C_PTR), INTENT(out) :: buffer_addr
    INTEGER(c_int), INTENT(out) :: size
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Buffer_detach_c

FUNCTION MPIR_Buffer_detach_c_large(buffer_addr, size) &
    bind(C, name="PMPI_Buffer_detach_c") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, C_PTR
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    IMPLICIT NONE
    TYPE(C_PTR), INTENT(out) :: buffer_addr
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: size
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Buffer_detach_c_large

FUNCTION MPIR_Buffer_flush_c() &
    bind(C, name="PMPI_Buffer_flush") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    IMPLICIT NONE
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Buffer_flush_c

FUNCTION MPIR_Buffer_iflush_c(request) &
    bind(C, name="PMPI_Buffer_iflush") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Request
    IMPLICIT NONE
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Buffer_iflush_c

FUNCTION MPIR_Comm_detach_buffer_c(comm, buffer_addr, size) &
    bind(C, name="PMPI_Comm_detach_buffer") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, C_PTR
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    TYPE(C_PTR), INTENT(out) :: buffer_addr
    INTEGER(c_int), INTENT(out) :: size
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_detach_buffer_c

FUNCTION MPIR_Comm_detach_buffer_c_large(comm, buffer_addr, size) &
    bind(C, name="PMPI_Comm_detach_buffer_c") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, C_PTR
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    TYPE(C_PTR), INTENT(out) :: buffer_addr
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: size
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_detach_buffer_c_large

FUNCTION MPIR_Comm_flush_buffer_c(comm) &
    bind(C, name="PMPI_Comm_flush_buffer") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_flush_buffer_c

FUNCTION MPIR_Comm_iflush_buffer_c(comm, request) &
    bind(C, name="PMPI_Comm_iflush_buffer") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Request
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_iflush_buffer_c

FUNCTION MPIR_Improbe_c(source, tag, comm, flag, message, status) &
    bind(C, name="PMPI_Improbe") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Message
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: source
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), INTENT(out) :: flag
    INTEGER(c_Message), INTENT(out) :: message
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Improbe_c

FUNCTION MPIR_Iprobe_c(source, tag, comm, flag, status) &
    bind(C, name="PMPI_Iprobe") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: source
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), INTENT(out) :: flag
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Iprobe_c

FUNCTION MPIR_Mprobe_c(source, tag, comm, message, status) &
    bind(C, name="PMPI_Mprobe") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Message
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: source
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Message), INTENT(out) :: message
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Mprobe_c

FUNCTION MPIR_Probe_c(source, tag, comm, status) &
    bind(C, name="PMPI_Probe") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: source
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Probe_c

FUNCTION MPIR_Session_detach_buffer_c(session, buffer_addr, size) &
    bind(C, name="PMPI_Session_detach_buffer") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, C_PTR
    USE :: mpi_c_interface_types, ONLY : c_Session
    IMPLICIT NONE
    INTEGER(c_Session), VALUE, INTENT(in) :: session
    TYPE(C_PTR), INTENT(out) :: buffer_addr
    INTEGER(c_int), INTENT(out) :: size
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Session_detach_buffer_c

FUNCTION MPIR_Session_detach_buffer_c_large(session, buffer_addr, size) &
    bind(C, name="PMPI_Session_detach_buffer_c") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, C_PTR
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Session
    IMPLICIT NONE
    INTEGER(c_Session), VALUE, INTENT(in) :: session
    TYPE(C_PTR), INTENT(out) :: buffer_addr
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: size
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Session_detach_buffer_c_large

FUNCTION MPIR_Session_flush_buffer_c(session) &
    bind(C, name="PMPI_Session_flush_buffer") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Session
    IMPLICIT NONE
    INTEGER(c_Session), VALUE, INTENT(in) :: session
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Session_flush_buffer_c

FUNCTION MPIR_Session_iflush_buffer_c(session, request) &
    bind(C, name="PMPI_Session_iflush_buffer") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Session, c_Request
    IMPLICIT NONE
    INTEGER(c_Session), VALUE, INTENT(in) :: session
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Session_iflush_buffer_c

FUNCTION MPIR_Cancel_c(request) &
    bind(C, name="PMPI_Cancel") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Request
    IMPLICIT NONE
    INTEGER(c_Request), INTENT(in) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Cancel_c

FUNCTION MPIR_Grequest_complete_c(request) &
    bind(C, name="PMPI_Grequest_complete") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Request
    IMPLICIT NONE
    INTEGER(c_Request), VALUE, INTENT(in) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Grequest_complete_c

FUNCTION MPIR_Grequest_start_c(query_fn, free_fn, cancel_fn, extra_state, request) &
    bind(C, name="PMPI_Grequest_start") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_funptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Request
    IMPLICIT NONE
    TYPE(c_funptr), VALUE :: query_fn
    TYPE(c_funptr), VALUE :: free_fn
    TYPE(c_funptr), VALUE :: cancel_fn
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: extra_state
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Grequest_start_c

FUNCTION MPIR_Request_free_c(request) &
    bind(C, name="PMPI_Request_free") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Request
    IMPLICIT NONE
    INTEGER(c_Request), INTENT(inout) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Request_free_c

FUNCTION MPIR_Request_get_status_c(request, flag, status) &
    bind(C, name="PMPI_Request_get_status") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_Request
    IMPLICIT NONE
    INTEGER(c_Request), VALUE, INTENT(in) :: request
    INTEGER(c_int), INTENT(out) :: flag
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Request_get_status_c

FUNCTION MPIR_Request_get_status_all_c(count, array_of_requests, flag, array_of_statuses) &
    bind(C, name="PMPI_Request_get_status_all") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_Request
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Request), INTENT(in) :: array_of_requests(count)
    INTEGER(c_int), INTENT(out) :: flag
    TYPE(c_ptr), VALUE, INTENT(in) :: array_of_statuses
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Request_get_status_all_c

FUNCTION MPIR_Request_get_status_any_c(count, array_of_requests, indx, flag, status) &
    bind(C, name="PMPI_Request_get_status_any") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_Request
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Request), INTENT(in) :: array_of_requests(count)
    INTEGER(c_int), INTENT(out) :: indx
    INTEGER(c_int), INTENT(out) :: flag
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Request_get_status_any_c

FUNCTION MPIR_Request_get_status_some_c(incount, array_of_requests, outcount, array_of_indices, &
                                        array_of_statuses) &
    bind(C, name="PMPI_Request_get_status_some") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_Request
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: incount
    INTEGER(c_Request), INTENT(in) :: array_of_requests(incount)
    INTEGER(c_int), INTENT(out) :: outcount
    INTEGER(c_int), INTENT(out) :: array_of_indices(*)
    TYPE(c_ptr), VALUE, INTENT(in) :: array_of_statuses
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Request_get_status_some_c

FUNCTION MPIR_Start_c(request) &
    bind(C, name="PMPI_Start") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Request
    IMPLICIT NONE
    INTEGER(c_Request), INTENT(inout) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Start_c

FUNCTION MPIR_Startall_c(count, array_of_requests) &
    bind(C, name="PMPI_Startall") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Request
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Request), INTENT(inout) :: array_of_requests(count)
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Startall_c

FUNCTION MPIR_Status_get_error_c(status, error) &
    bind(C, name="PMPI_Status_get_error") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    IMPLICIT NONE
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int), INTENT(out) :: error
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Status_get_error_c

FUNCTION MPIR_Status_get_source_c(status, source) &
    bind(C, name="PMPI_Status_get_source") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    IMPLICIT NONE
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int), INTENT(out) :: source
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Status_get_source_c

FUNCTION MPIR_Status_get_tag_c(status, tag) &
    bind(C, name="PMPI_Status_get_tag") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    IMPLICIT NONE
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int), INTENT(out) :: tag
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Status_get_tag_c

FUNCTION MPIR_Status_set_error_c(status, error) &
    bind(C, name="PMPI_Status_set_error") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    IMPLICIT NONE
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int), VALUE, INTENT(in) :: error
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Status_set_error_c

FUNCTION MPIR_Status_set_source_c(status, source) &
    bind(C, name="PMPI_Status_set_source") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    IMPLICIT NONE
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int), VALUE, INTENT(in) :: source
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Status_set_source_c

FUNCTION MPIR_Status_set_tag_c(status, tag) &
    bind(C, name="PMPI_Status_set_tag") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    IMPLICIT NONE
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Status_set_tag_c

FUNCTION MPIR_Status_set_cancelled_c(status, flag) &
    bind(C, name="PMPI_Status_set_cancelled") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    IMPLICIT NONE
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int), VALUE, INTENT(in) :: flag
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Status_set_cancelled_c

FUNCTION MPIR_Test_c(request, flag, status) &
    bind(C, name="PMPI_Test") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_Request
    IMPLICIT NONE
    INTEGER(c_Request), INTENT(inout) :: request
    INTEGER(c_int), INTENT(out) :: flag
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Test_c

FUNCTION MPIR_Test_cancelled_c(status, flag) &
    bind(C, name="PMPI_Test_cancelled") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    IMPLICIT NONE
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int), INTENT(out) :: flag
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Test_cancelled_c

FUNCTION MPIR_Testall_c(count, array_of_requests, flag, array_of_statuses) &
    bind(C, name="PMPI_Testall") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_Request
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Request), INTENT(inout) :: array_of_requests(count)
    INTEGER(c_int), INTENT(out) :: flag
    TYPE(c_ptr), VALUE, INTENT(in) :: array_of_statuses
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Testall_c

FUNCTION MPIR_Testany_c(count, array_of_requests, indx, flag, status) &
    bind(C, name="PMPI_Testany") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_Request
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Request), INTENT(inout) :: array_of_requests(count)
    INTEGER(c_int), INTENT(out) :: indx
    INTEGER(c_int), INTENT(out) :: flag
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Testany_c

FUNCTION MPIR_Testsome_c(incount, array_of_requests, outcount, array_of_indices, &
                         array_of_statuses) &
    bind(C, name="PMPI_Testsome") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_Request
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: incount
    INTEGER(c_Request), INTENT(inout) :: array_of_requests(incount)
    INTEGER(c_int), INTENT(out) :: outcount
    INTEGER(c_int), INTENT(out) :: array_of_indices(*)
    TYPE(c_ptr), VALUE, INTENT(in) :: array_of_statuses
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Testsome_c

FUNCTION MPIR_Wait_c(request, status) &
    bind(C, name="PMPI_Wait") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_Request
    IMPLICIT NONE
    INTEGER(c_Request), INTENT(inout) :: request
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Wait_c

FUNCTION MPIR_Waitall_c(count, array_of_requests, array_of_statuses) &
    bind(C, name="PMPI_Waitall") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_Request
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Request), INTENT(inout) :: array_of_requests(count)
    TYPE(c_ptr), VALUE, INTENT(in) :: array_of_statuses
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Waitall_c

FUNCTION MPIR_Waitany_c(count, array_of_requests, indx, status) &
    bind(C, name="PMPI_Waitany") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_Request
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Request), INTENT(inout) :: array_of_requests(count)
    INTEGER(c_int), INTENT(out) :: indx
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Waitany_c

FUNCTION MPIR_Waitsome_c(incount, array_of_requests, outcount, array_of_indices, &
                         array_of_statuses) &
    bind(C, name="PMPI_Waitsome") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_Request
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: incount
    INTEGER(c_Request), INTENT(inout) :: array_of_requests(incount)
    INTEGER(c_int), INTENT(out) :: outcount
    INTEGER(c_int), INTENT(out) :: array_of_indices(*)
    TYPE(c_ptr), VALUE, INTENT(in) :: array_of_statuses
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Waitsome_c

FUNCTION MPIR_Request_is_complete_c(request) &
    bind(C, name="PMPIX_Request_is_complete") result(res)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Request
    IMPLICIT NONE
    INTEGER(c_Request), VALUE, INTENT(in) :: request
    LOGICAL :: res
END FUNCTION MPIR_Request_is_complete_c

FUNCTION MPIR_Alloc_mem_c(size, info, baseptr) &
    bind(C, name="PMPI_Alloc_mem") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, C_PTR
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Info
    IMPLICIT NONE
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: size
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    TYPE(C_PTR), INTENT(out) :: baseptr
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Alloc_mem_c

FUNCTION MPIR_Win_allocate_c(size, disp_unit, info, comm, baseptr, win) &
    bind(C, name="PMPI_Win_allocate") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, C_PTR
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Info, c_Comm, c_Win
    IMPLICIT NONE
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: size
    INTEGER(c_int), VALUE, INTENT(in) :: disp_unit
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    TYPE(C_PTR), INTENT(out) :: baseptr
    INTEGER(c_Win), INTENT(out) :: win
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_allocate_c

FUNCTION MPIR_Win_allocate_c_large(size, disp_unit, info, comm, baseptr, win) &
    bind(C, name="PMPI_Win_allocate_c") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, C_PTR
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Info, c_Comm, c_Win
    IMPLICIT NONE
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: size
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: disp_unit
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    TYPE(C_PTR), INTENT(out) :: baseptr
    INTEGER(c_Win), INTENT(out) :: win
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_allocate_c_large

FUNCTION MPIR_Win_allocate_shared_c(size, disp_unit, info, comm, baseptr, win) &
    bind(C, name="PMPI_Win_allocate_shared") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, C_PTR
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Info, c_Comm, c_Win
    IMPLICIT NONE
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: size
    INTEGER(c_int), VALUE, INTENT(in) :: disp_unit
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    TYPE(C_PTR), INTENT(out) :: baseptr
    INTEGER(c_Win), INTENT(out) :: win
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_allocate_shared_c

FUNCTION MPIR_Win_allocate_shared_c_large(size, disp_unit, info, comm, baseptr, win) &
    bind(C, name="PMPI_Win_allocate_shared_c") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, C_PTR
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Info, c_Comm, c_Win
    IMPLICIT NONE
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: size
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: disp_unit
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    TYPE(C_PTR), INTENT(out) :: baseptr
    INTEGER(c_Win), INTENT(out) :: win
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_allocate_shared_c_large

FUNCTION MPIR_Win_complete_c(win) &
    bind(C, name="PMPI_Win_complete") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Win
    IMPLICIT NONE
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_complete_c

FUNCTION MPIR_Win_create_dynamic_c(info, comm, win) &
    bind(C, name="PMPI_Win_create_dynamic") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Info, c_Comm, c_Win
    IMPLICIT NONE
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Win), INTENT(out) :: win
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_create_dynamic_c

FUNCTION MPIR_Win_fence_c(assert, win) &
    bind(C, name="PMPI_Win_fence") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Win
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: assert
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_fence_c

FUNCTION MPIR_Win_flush_c(rank, win) &
    bind(C, name="PMPI_Win_flush") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Win
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: rank
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_flush_c

FUNCTION MPIR_Win_flush_all_c(win) &
    bind(C, name="PMPI_Win_flush_all") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Win
    IMPLICIT NONE
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_flush_all_c

FUNCTION MPIR_Win_flush_local_c(rank, win) &
    bind(C, name="PMPI_Win_flush_local") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Win
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: rank
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_flush_local_c

FUNCTION MPIR_Win_flush_local_all_c(win) &
    bind(C, name="PMPI_Win_flush_local_all") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Win
    IMPLICIT NONE
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_flush_local_all_c

FUNCTION MPIR_Win_free_c(win) &
    bind(C, name="PMPI_Win_free") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Win
    IMPLICIT NONE
    INTEGER(c_Win), INTENT(inout) :: win
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_free_c

FUNCTION MPIR_Win_get_group_c(win, group) &
    bind(C, name="PMPI_Win_get_group") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Win, c_Group
    IMPLICIT NONE
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_Group), INTENT(out) :: group
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_get_group_c

FUNCTION MPIR_Win_get_info_c(win, info_used) &
    bind(C, name="PMPI_Win_get_info") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Win, c_Info
    IMPLICIT NONE
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_Info), INTENT(out) :: info_used
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_get_info_c

FUNCTION MPIR_Win_get_name_c(win, win_name, resultlen) &
    bind(C, name="PMPI_Win_get_name") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_c_interface_types, ONLY : c_Win
    IMPLICIT NONE
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    character(kind=c_char), INTENT(out) :: win_name(*)
    INTEGER(c_int), INTENT(out) :: resultlen
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_get_name_c

FUNCTION MPIR_Win_lock_c(lock_type, rank, assert, win) &
    bind(C, name="PMPI_Win_lock") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Win
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: lock_type
    INTEGER(c_int), VALUE, INTENT(in) :: rank
    INTEGER(c_int), VALUE, INTENT(in) :: assert
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_lock_c

FUNCTION MPIR_Win_lock_all_c(assert, win) &
    bind(C, name="PMPI_Win_lock_all") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Win
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: assert
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_lock_all_c

FUNCTION MPIR_Win_post_c(group, assert, win) &
    bind(C, name="PMPI_Win_post") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Group, c_Win
    IMPLICIT NONE
    INTEGER(c_Group), VALUE, INTENT(in) :: group
    INTEGER(c_int), VALUE, INTENT(in) :: assert
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_post_c

FUNCTION MPIR_Win_set_info_c(win, info) &
    bind(C, name="PMPI_Win_set_info") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Win, c_Info
    IMPLICIT NONE
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_set_info_c

FUNCTION MPIR_Win_set_name_c(win, win_name) &
    bind(C, name="PMPI_Win_set_name") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_c_interface_types, ONLY : c_Win
    IMPLICIT NONE
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    character(kind=c_char), INTENT(in) :: win_name(*)
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_set_name_c

FUNCTION MPIR_Win_shared_query_c(win, rank, size, disp_unit, baseptr) &
    bind(C, name="PMPI_Win_shared_query") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, C_PTR
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Win
    IMPLICIT NONE
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_int), VALUE, INTENT(in) :: rank
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: size
    INTEGER(c_int), INTENT(out) :: disp_unit
    TYPE(C_PTR), INTENT(out) :: baseptr
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_shared_query_c

FUNCTION MPIR_Win_shared_query_c_large(win, rank, size, disp_unit, baseptr) &
    bind(C, name="PMPI_Win_shared_query_c") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, C_PTR
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Win
    IMPLICIT NONE
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_int), VALUE, INTENT(in) :: rank
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: size
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: disp_unit
    TYPE(C_PTR), INTENT(out) :: baseptr
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_shared_query_c_large

FUNCTION MPIR_Win_start_c(group, assert, win) &
    bind(C, name="PMPI_Win_start") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Group, c_Win
    IMPLICIT NONE
    INTEGER(c_Group), VALUE, INTENT(in) :: group
    INTEGER(c_int), VALUE, INTENT(in) :: assert
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_start_c

FUNCTION MPIR_Win_sync_c(win) &
    bind(C, name="PMPI_Win_sync") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Win
    IMPLICIT NONE
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_sync_c

FUNCTION MPIR_Win_test_c(win, flag) &
    bind(C, name="PMPI_Win_test") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Win
    IMPLICIT NONE
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_int), INTENT(out) :: flag
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_test_c

FUNCTION MPIR_Win_unlock_c(rank, win) &
    bind(C, name="PMPI_Win_unlock") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Win
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: rank
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_unlock_c

FUNCTION MPIR_Win_unlock_all_c(win) &
    bind(C, name="PMPI_Win_unlock_all") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Win
    IMPLICIT NONE
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_unlock_all_c

FUNCTION MPIR_Win_wait_c(win) &
    bind(C, name="PMPI_Win_wait") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Win
    IMPLICIT NONE
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_wait_c

FUNCTION MPIR_Close_port_c(port_name) &
    bind(C, name="PMPI_Close_port") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    IMPLICIT NONE
    character(kind=c_char), INTENT(in) :: port_name(*)
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Close_port_c

FUNCTION MPIR_Comm_accept_c(port_name, info, root, comm, newcomm) &
    bind(C, name="PMPI_Comm_accept") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_c_interface_types, ONLY : c_Info, c_Comm
    IMPLICIT NONE
    character(kind=c_char), INTENT(in) :: port_name(*)
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Comm), INTENT(out) :: newcomm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_accept_c

FUNCTION MPIR_Comm_connect_c(port_name, info, root, comm, newcomm) &
    bind(C, name="PMPI_Comm_connect") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_c_interface_types, ONLY : c_Info, c_Comm
    IMPLICIT NONE
    character(kind=c_char), INTENT(in) :: port_name(*)
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Comm), INTENT(out) :: newcomm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_connect_c

FUNCTION MPIR_Comm_disconnect_c(comm) &
    bind(C, name="PMPI_Comm_disconnect") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), INTENT(inout) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_disconnect_c

FUNCTION MPIR_Comm_get_parent_c(parent) &
    bind(C, name="PMPI_Comm_get_parent") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), INTENT(out) :: parent
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_get_parent_c

FUNCTION MPIR_Comm_join_c(fd, intercomm) &
    bind(C, name="PMPI_Comm_join") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: fd
    INTEGER(c_Comm), INTENT(out) :: intercomm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_join_c

FUNCTION MPIR_Comm_spawn_c(command, argv, maxprocs, info, root, comm, intercomm, array_of_errcodes, &
                           argv_elem_len) &
    bind(C, name="MPIR_Comm_spawn_c") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_Info, c_Comm
    IMPLICIT NONE
    character(kind=c_char), INTENT(in) :: command(*)
    TYPE(c_ptr), VALUE, INTENT(in) :: argv
    INTEGER(c_int), VALUE, INTENT(in) :: maxprocs
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Comm), INTENT(out) :: intercomm
    TYPE(c_ptr), VALUE, INTENT(in) :: array_of_errcodes
    INTEGER(c_int), VALUE, INTENT(in) :: argv_elem_len
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_spawn_c

FUNCTION MPIR_Comm_spawn_multiple_c(count, array_of_commands, array_of_argv, array_of_maxprocs, &
                                    array_of_info, root, comm, intercomm, array_of_errcodes, &
                                    commands_elem_len, argv_elem_len) &
    bind(C, name="MPIR_Comm_spawn_multiple_c") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_Info, c_Comm
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: count
    TYPE(c_ptr), VALUE, INTENT(in) :: array_of_commands
    TYPE(c_ptr), VALUE, INTENT(in) :: array_of_argv
    INTEGER(c_int), INTENT(in) :: array_of_maxprocs(count)
    INTEGER(c_Info), INTENT(in) :: array_of_info(count)
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Comm), INTENT(out) :: intercomm
    TYPE(c_ptr), VALUE, INTENT(in) :: array_of_errcodes
    INTEGER(c_int), VALUE, INTENT(in) :: commands_elem_len
    INTEGER(c_int), VALUE, INTENT(in) :: argv_elem_len
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_spawn_multiple_c

FUNCTION MPIR_Lookup_name_c(service_name, info, port_name) &
    bind(C, name="PMPI_Lookup_name") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_c_interface_types, ONLY : c_Info
    IMPLICIT NONE
    character(kind=c_char), INTENT(in) :: service_name(*)
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    character(kind=c_char), INTENT(out) :: port_name(*)
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Lookup_name_c

FUNCTION MPIR_Open_port_c(info, port_name) &
    bind(C, name="PMPI_Open_port") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_c_interface_types, ONLY : c_Info
    IMPLICIT NONE
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    character(kind=c_char), INTENT(out) :: port_name(*)
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Open_port_c

FUNCTION MPIR_Publish_name_c(service_name, info, port_name) &
    bind(C, name="PMPI_Publish_name") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_c_interface_types, ONLY : c_Info
    IMPLICIT NONE
    character(kind=c_char), INTENT(in) :: service_name(*)
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    character(kind=c_char), INTENT(in) :: port_name(*)
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Publish_name_c

FUNCTION MPIR_Unpublish_name_c(service_name, info, port_name) &
    bind(C, name="PMPI_Unpublish_name") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_c_interface_types, ONLY : c_Info
    IMPLICIT NONE
    character(kind=c_char), INTENT(in) :: service_name(*)
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    character(kind=c_char), INTENT(in) :: port_name(*)
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Unpublish_name_c

FUNCTION MPIR_Stream_create_c(info, stream) &
    bind(C, name="PMPIX_Stream_create") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Info, c_Stream
    IMPLICIT NONE
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Stream), INTENT(out) :: stream
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Stream_create_c

FUNCTION MPIR_Stream_free_c(stream) &
    bind(C, name="PMPIX_Stream_free") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Stream
    IMPLICIT NONE
    INTEGER(c_Stream), INTENT(inout) :: stream
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Stream_free_c

FUNCTION MPIR_Stream_comm_create_c(comm, stream, newcomm) &
    bind(C, name="PMPIX_Stream_comm_create") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Stream
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Stream), VALUE, INTENT(in) :: stream
    INTEGER(c_Comm), INTENT(out) :: newcomm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Stream_comm_create_c

FUNCTION MPIR_Stream_comm_create_multiplex_c(comm, count, array_of_streams, newcomm) &
    bind(C, name="PMPIX_Stream_comm_create_multiplex") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Stream
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Stream), INTENT(in) :: array_of_streams(count)
    INTEGER(c_Comm), INTENT(out) :: newcomm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Stream_comm_create_multiplex_c

FUNCTION MPIR_Comm_get_stream_c(comm, idx, stream) &
    bind(C, name="PMPIX_Comm_get_stream") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Stream
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), VALUE, INTENT(in) :: idx
    INTEGER(c_Stream), INTENT(out) :: stream
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_get_stream_c

FUNCTION MPIR_Stream_progress_c(stream) &
    bind(C, name="PMPIX_Stream_progress") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Stream
    IMPLICIT NONE
    INTEGER(c_Stream), VALUE, INTENT(in) :: stream
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Stream_progress_c

FUNCTION MPIR_Start_progress_thread_c(stream) &
    bind(C, name="PMPIX_Start_progress_thread") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Stream
    IMPLICIT NONE
    INTEGER(c_Stream), VALUE, INTENT(in) :: stream
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Start_progress_thread_c

FUNCTION MPIR_Stop_progress_thread_c(stream) &
    bind(C, name="PMPIX_Stop_progress_thread") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Stream
    IMPLICIT NONE
    INTEGER(c_Stream), VALUE, INTENT(in) :: stream
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Stop_progress_thread_c

FUNCTION MPIR_Wait_enqueue_c(request, status) &
    bind(C, name="PMPIX_Wait_enqueue") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_Request
    IMPLICIT NONE
    INTEGER(c_Request), INTENT(inout) :: request
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Wait_enqueue_c

FUNCTION MPIR_Waitall_enqueue_c(count, array_of_requests, array_of_statuses) &
    bind(C, name="PMPIX_Waitall_enqueue") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_Request
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Request), INTENT(inout) :: array_of_requests(count)
    TYPE(c_ptr), VALUE, INTENT(in) :: array_of_statuses
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Waitall_enqueue_c

FUNCTION MPIR_Threadcomm_init_c(comm, num_threads, newthreadcomm) &
    bind(C, name="PMPIX_Threadcomm_init") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), VALUE, INTENT(in) :: num_threads
    INTEGER(c_Comm), INTENT(out) :: newthreadcomm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Threadcomm_init_c

FUNCTION MPIR_Threadcomm_free_c(threadcomm) &
    bind(C, name="PMPIX_Threadcomm_free") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), INTENT(inout) :: threadcomm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Threadcomm_free_c

FUNCTION MPIR_Threadcomm_start_c(threadcomm) &
    bind(C, name="PMPIX_Threadcomm_start") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: threadcomm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Threadcomm_start_c

FUNCTION MPIR_Threadcomm_finish_c(threadcomm) &
    bind(C, name="PMPIX_Threadcomm_finish") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: threadcomm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Threadcomm_finish_c

FUNCTION MPIR_Wtick_c() &
    bind(C, name="PMPI_Wtick") result(res)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    IMPLICIT NONE
    DOUBLE PRECISION :: res
END FUNCTION MPIR_Wtick_c

FUNCTION MPIR_Wtime_c() &
    bind(C, name="PMPI_Wtime") result(res)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    IMPLICIT NONE
    DOUBLE PRECISION :: res
END FUNCTION MPIR_Wtime_c

FUNCTION MPIR_Cart_coords_c(comm, rank, maxdims, coords) &
    bind(C, name="PMPI_Cart_coords") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), VALUE, INTENT(in) :: rank
    INTEGER(c_int), VALUE, INTENT(in) :: maxdims
    INTEGER(c_int), INTENT(out) :: coords(maxdims)
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Cart_coords_c

FUNCTION MPIR_Cart_create_c(comm_old, ndims, dims, periods, reorder, comm_cart) &
    bind(C, name="PMPI_Cart_create") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm_old
    INTEGER(c_int), VALUE, INTENT(in) :: ndims
    INTEGER(c_int), INTENT(in) :: dims(ndims)
    INTEGER(c_int), INTENT(in) :: periods(ndims)
    INTEGER(c_int), VALUE, INTENT(in) :: reorder
    INTEGER(c_Comm), INTENT(out) :: comm_cart
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Cart_create_c

FUNCTION MPIR_Cart_get_c(comm, maxdims, dims, periods, coords) &
    bind(C, name="PMPI_Cart_get") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), VALUE, INTENT(in) :: maxdims
    INTEGER(c_int), INTENT(out) :: dims(maxdims)
    INTEGER(c_int), INTENT(out) :: periods(maxdims)
    INTEGER(c_int), INTENT(out) :: coords(maxdims)
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Cart_get_c

FUNCTION MPIR_Cart_map_c(comm, ndims, dims, periods, newrank) &
    bind(C, name="PMPI_Cart_map") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), VALUE, INTENT(in) :: ndims
    INTEGER(c_int), INTENT(in) :: dims(ndims)
    INTEGER(c_int), INTENT(in) :: periods(ndims)
    INTEGER(c_int), INTENT(out) :: newrank
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Cart_map_c

FUNCTION MPIR_Cart_rank_c(comm, coords, rank) &
    bind(C, name="PMPI_Cart_rank") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), INTENT(in) :: coords(*)
    INTEGER(c_int), INTENT(out) :: rank
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Cart_rank_c

FUNCTION MPIR_Cart_shift_c(comm, direction, disp, rank_source, rank_dest) &
    bind(C, name="PMPI_Cart_shift") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), VALUE, INTENT(in) :: direction
    INTEGER(c_int), VALUE, INTENT(in) :: disp
    INTEGER(c_int), INTENT(out) :: rank_source
    INTEGER(c_int), INTENT(out) :: rank_dest
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Cart_shift_c

FUNCTION MPIR_Cart_sub_c(comm, remain_dims, newcomm) &
    bind(C, name="PMPI_Cart_sub") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), INTENT(in) :: remain_dims(*)
    INTEGER(c_Comm), INTENT(out) :: newcomm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Cart_sub_c

FUNCTION MPIR_Cartdim_get_c(comm, ndims) &
    bind(C, name="PMPI_Cartdim_get") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), INTENT(out) :: ndims
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Cartdim_get_c

FUNCTION MPIR_Dims_create_c(nnodes, ndims, dims) &
    bind(C, name="PMPI_Dims_create") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    IMPLICIT NONE
    INTEGER(c_int), VALUE, INTENT(in) :: nnodes
    INTEGER(c_int), VALUE, INTENT(in) :: ndims
    INTEGER(c_int), INTENT(inout) :: dims(ndims)
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Dims_create_c

FUNCTION MPIR_Dist_graph_create_c(comm_old, n, sources, degrees, destinations, weights, info, &
                                  reorder, comm_dist_graph) &
    bind(C, name="PMPI_Dist_graph_create") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Info
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm_old
    INTEGER(c_int), VALUE, INTENT(in) :: n
    INTEGER(c_int), INTENT(in) :: sources(n)
    INTEGER(c_int), INTENT(in) :: degrees(n)
    INTEGER(c_int), INTENT(in) :: destinations(*)
    TYPE(c_ptr), VALUE, INTENT(in) :: weights
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_int), VALUE, INTENT(in) :: reorder
    INTEGER(c_Comm), INTENT(out) :: comm_dist_graph
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Dist_graph_create_c

FUNCTION MPIR_Dist_graph_create_adjacent_c(comm_old, indegree, sources, sourceweights, outdegree, &
                                           destinations, destweights, info, reorder, &
                                           comm_dist_graph) &
    bind(C, name="PMPI_Dist_graph_create_adjacent") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Info
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm_old
    INTEGER(c_int), VALUE, INTENT(in) :: indegree
    INTEGER(c_int), INTENT(in) :: sources(indegree)
    TYPE(c_ptr), VALUE, INTENT(in) :: sourceweights
    INTEGER(c_int), VALUE, INTENT(in) :: outdegree
    INTEGER(c_int), INTENT(in) :: destinations(outdegree)
    TYPE(c_ptr), VALUE, INTENT(in) :: destweights
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_int), VALUE, INTENT(in) :: reorder
    INTEGER(c_Comm), INTENT(out) :: comm_dist_graph
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Dist_graph_create_adjacent_c

FUNCTION MPIR_Dist_graph_neighbors_c(comm, maxindegree, sources, sourceweights, maxoutdegree, &
                                     destinations, destweights) &
    bind(C, name="PMPI_Dist_graph_neighbors") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), VALUE, INTENT(in) :: maxindegree
    INTEGER(c_int), INTENT(out) :: sources(maxindegree)
    TYPE(c_ptr), VALUE, INTENT(in) :: sourceweights
    INTEGER(c_int), VALUE, INTENT(in) :: maxoutdegree
    INTEGER(c_int), INTENT(out) :: destinations(maxoutdegree)
    TYPE(c_ptr), VALUE, INTENT(in) :: destweights
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Dist_graph_neighbors_c

FUNCTION MPIR_Dist_graph_neighbors_count_c(comm, indegree, outdegree, weighted) &
    bind(C, name="PMPI_Dist_graph_neighbors_count") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), INTENT(out) :: indegree
    INTEGER(c_int), INTENT(out) :: outdegree
    INTEGER(c_int), INTENT(out) :: weighted
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Dist_graph_neighbors_count_c

FUNCTION MPIR_Get_hw_resource_info_c(hw_info) &
    bind(C, name="PMPI_Get_hw_resource_info") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Info
    IMPLICIT NONE
    INTEGER(c_Info), INTENT(out) :: hw_info
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Get_hw_resource_info_c

FUNCTION MPIR_Graph_create_c(comm_old, nnodes, indx, edges, reorder, comm_graph) &
    bind(C, name="PMPI_Graph_create") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm_old
    INTEGER(c_int), VALUE, INTENT(in) :: nnodes
    INTEGER(c_int), INTENT(in) :: indx(nnodes)
    INTEGER(c_int), INTENT(in) :: edges(*)
    INTEGER(c_int), VALUE, INTENT(in) :: reorder
    INTEGER(c_Comm), INTENT(out) :: comm_graph
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Graph_create_c

FUNCTION MPIR_Graph_get_c(comm, maxindex, maxedges, indx, edges) &
    bind(C, name="PMPI_Graph_get") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), VALUE, INTENT(in) :: maxindex
    INTEGER(c_int), VALUE, INTENT(in) :: maxedges
    INTEGER(c_int), INTENT(out) :: indx(maxindex)
    INTEGER(c_int), INTENT(out) :: edges(maxedges)
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Graph_get_c

FUNCTION MPIR_Graph_map_c(comm, nnodes, indx, edges, newrank) &
    bind(C, name="PMPI_Graph_map") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), VALUE, INTENT(in) :: nnodes
    INTEGER(c_int), INTENT(in) :: indx(nnodes)
    INTEGER(c_int), INTENT(in) :: edges(*)
    INTEGER(c_int), INTENT(out) :: newrank
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Graph_map_c

FUNCTION MPIR_Graph_neighbors_c(comm, rank, maxneighbors, neighbors) &
    bind(C, name="PMPI_Graph_neighbors") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), VALUE, INTENT(in) :: rank
    INTEGER(c_int), VALUE, INTENT(in) :: maxneighbors
    INTEGER(c_int), INTENT(out) :: neighbors(maxneighbors)
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Graph_neighbors_c

FUNCTION MPIR_Graph_neighbors_count_c(comm, rank, nneighbors) &
    bind(C, name="PMPI_Graph_neighbors_count") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), VALUE, INTENT(in) :: rank
    INTEGER(c_int), INTENT(out) :: nneighbors
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Graph_neighbors_count_c

FUNCTION MPIR_Graphdims_get_c(comm, nnodes, nedges) &
    bind(C, name="PMPI_Graphdims_get") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), INTENT(out) :: nnodes
    INTEGER(c_int), INTENT(out) :: nedges
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Graphdims_get_c

FUNCTION MPIR_Topo_test_c(comm, status) &
    bind(C, name="PMPI_Topo_test") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), INTENT(out) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Topo_test_c

FUNCTION MPIR_File_close_c(fh) &
    bind(C, name="PMPI_File_close") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_File
    IMPLICIT NONE
    INTEGER(c_File), INTENT(inout) :: fh
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_close_c

FUNCTION MPIR_File_delete_c(filename, info) &
    bind(C, name="PMPI_File_delete") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_c_interface_types, ONLY : c_Info
    IMPLICIT NONE
    character(kind=c_char), INTENT(in) :: filename(*)
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_delete_c

FUNCTION MPIR_File_get_amode_c(fh, amode) &
    bind(C, name="PMPI_File_get_amode") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_File
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(c_int), INTENT(out) :: amode
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_get_amode_c

FUNCTION MPIR_File_get_atomicity_c(fh, flag) &
    bind(C, name="PMPI_File_get_atomicity") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_File
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(c_int), INTENT(out) :: flag
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_get_atomicity_c

FUNCTION MPIR_File_get_byte_offset_c(fh, offset, disp) &
    bind(C, name="PMPI_File_get_byte_offset") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), VALUE, INTENT(in) :: offset
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(out) :: disp
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_get_byte_offset_c

FUNCTION MPIR_File_get_group_c(fh, group) &
    bind(C, name="PMPI_File_get_group") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_File, c_Group
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(c_Group), INTENT(out) :: group
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_get_group_c

FUNCTION MPIR_File_get_info_c(fh, info_used) &
    bind(C, name="PMPI_File_get_info") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_File, c_Info
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(c_Info), INTENT(out) :: info_used
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_get_info_c

FUNCTION MPIR_File_get_position_c(fh, offset) &
    bind(C, name="PMPI_File_get_position") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(out) :: offset
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_get_position_c

FUNCTION MPIR_File_get_position_shared_c(fh, offset) &
    bind(C, name="PMPI_File_get_position_shared") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(out) :: offset
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_get_position_shared_c

FUNCTION MPIR_File_get_size_c(fh, size) &
    bind(C, name="PMPI_File_get_size") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(out) :: size
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_get_size_c

FUNCTION MPIR_File_get_type_extent_c(fh, datatype, extent) &
    bind(C, name="PMPI_File_get_type_extent") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: extent
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_get_type_extent_c

FUNCTION MPIR_File_get_view_c(fh, disp, etype, filetype, datarep) &
    bind(C, name="PMPI_File_get_view") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(out) :: disp
    INTEGER(c_Datatype), INTENT(out) :: etype
    INTEGER(c_Datatype), INTENT(out) :: filetype
    character(kind=c_char), INTENT(out) :: datarep(*)
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_get_view_c

FUNCTION MPIR_File_open_c(comm, filename, amode, info, fh) &
    bind(C, name="PMPI_File_open") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Info, c_File
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    character(kind=c_char), INTENT(in) :: filename(*)
    INTEGER(c_int), VALUE, INTENT(in) :: amode
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_File), INTENT(out) :: fh
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_open_c

FUNCTION MPIR_File_preallocate_c(fh, size) &
    bind(C, name="PMPI_File_preallocate") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), VALUE, INTENT(in) :: size
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_preallocate_c

FUNCTION MPIR_File_seek_c(fh, offset, whence) &
    bind(C, name="PMPI_File_seek") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), VALUE, INTENT(in) :: offset
    INTEGER(c_int), VALUE, INTENT(in) :: whence
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_seek_c

FUNCTION MPIR_File_seek_shared_c(fh, offset, whence) &
    bind(C, name="PMPI_File_seek_shared") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), VALUE, INTENT(in) :: offset
    INTEGER(c_int), VALUE, INTENT(in) :: whence
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_seek_shared_c

FUNCTION MPIR_File_set_atomicity_c(fh, flag) &
    bind(C, name="PMPI_File_set_atomicity") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_File
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(c_int), VALUE, INTENT(in) :: flag
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_set_atomicity_c

FUNCTION MPIR_File_set_info_c(fh, info) &
    bind(C, name="PMPI_File_set_info") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_File, c_Info
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_set_info_c

FUNCTION MPIR_File_set_size_c(fh, size) &
    bind(C, name="PMPI_File_set_size") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), VALUE, INTENT(in) :: size
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_set_size_c

FUNCTION MPIR_File_set_view_c(fh, disp, etype, filetype, datarep, info) &
    bind(C, name="PMPI_File_set_view") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Info
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), VALUE, INTENT(in) :: disp
    INTEGER(c_Datatype), VALUE, INTENT(in) :: etype
    INTEGER(c_Datatype), VALUE, INTENT(in) :: filetype
    character(kind=c_char), INTENT(in) :: datarep(*)
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_set_view_c

FUNCTION MPIR_File_sync_c(fh) &
    bind(C, name="PMPI_File_sync") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_File
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_sync_c

FUNCTION MPIR_Register_datarep_c(datarep, read_conversion_fn, write_conversion_fn, &
                                 dtype_file_extent_fn, extra_state) &
    bind(C, name="PMPI_Register_datarep") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char, c_funptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    IMPLICIT NONE
    character(kind=c_char), INTENT(in) :: datarep(*)
    TYPE(c_funptr), VALUE :: read_conversion_fn
    TYPE(c_funptr), VALUE :: write_conversion_fn
    TYPE(c_funptr), VALUE :: dtype_file_extent_fn
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: extra_state
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Register_datarep_c

FUNCTION MPIR_Register_datarep_c_large(datarep, read_conversion_fn, write_conversion_fn, &
                                       dtype_file_extent_fn, extra_state) &
    bind(C, name="PMPI_Register_datarep_c") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char, c_funptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    IMPLICIT NONE
    character(kind=c_char), INTENT(in) :: datarep(*)
    TYPE(c_funptr), VALUE :: read_conversion_fn
    TYPE(c_funptr), VALUE :: write_conversion_fn
    TYPE(c_funptr), VALUE :: dtype_file_extent_fn
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: extra_state
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Register_datarep_c_large

END INTERFACE
END module mpi_c_interface_nobuf
