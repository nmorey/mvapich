!
! Copyright (C) by Argonne National Laboratory
!     See COPYRIGHT in top-level directory
!

! -- THIS FILE IS AUTO-GENERATED -- 


SUBROUTINE MPI_Comm_create_keyval_f08(comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, &
                                      extra_state, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_funptr, c_funloc, c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_SUCCESS, MPI_ADDRESS_KIND
    USE :: mpi_f08_callbacks, ONLY : MPI_Comm_copy_attr_function, MPI_Comm_delete_attr_function
    USE :: mpi_c_interface, ONLY : MPIR_Comm_create_keyval_c
    USE :: mpi_c_interface_glue, ONLY : MPII_Keyval_set_f90_proxy
    
    IMPLICIT NONE
    
    PROCEDURE(MPI_Comm_copy_attr_function) :: comm_copy_attr_fn
    PROCEDURE(MPI_Comm_delete_attr_function) :: comm_delete_attr_fn
    INTEGER, INTENT(out) :: comm_keyval
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: extra_state
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    TYPE(c_funptr) :: comm_copy_attr_fn_c
    TYPE(c_funptr) :: comm_delete_attr_fn_c
    INTEGER(c_int) :: comm_keyval_c
    INTEGER(c_int) :: ierror_c
    
    comm_copy_attr_fn_c = c_funloc(comm_copy_attr_fn)
    comm_delete_attr_fn_c = c_funloc(comm_delete_attr_fn)
    
    ierror_c = MPIR_Comm_create_keyval_c(comm_copy_attr_fn_c, comm_delete_attr_fn_c, comm_keyval_c, &
                                         extra_state)
    IF (ierror_c == MPI_SUCCESS) THEN
        call MPII_Keyval_set_f90_proxy(comm_keyval_c)
    END IF
    comm_keyval = comm_keyval_c
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_create_keyval_f08

SUBROUTINE MPI_Comm_delete_attr_f08(comm, comm_keyval, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Comm_delete_attr_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(in) :: comm_keyval
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: comm_keyval_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_delete_attr_c(comm%MPI_VAL, comm_keyval)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_delete_attr_f08

SUBROUTINE MPI_Comm_free_keyval_f08(comm_keyval, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface, ONLY : MPIR_Comm_free_keyval_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(inout) :: comm_keyval
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: comm_keyval_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_free_keyval_c(comm_keyval)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_free_keyval_f08

SUBROUTINE MPI_Comm_get_attr_f08(comm, comm_keyval, attribute_val, flag, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Comm_get_attr_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_ATTR_AINT
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(in) :: comm_keyval
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: attribute_val
    LOGICAL, INTENT(out) :: flag
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: comm_keyval_c
    INTEGER(c_int) :: flag_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_get_attr_c(comm%MPI_VAL, comm_keyval, attribute_val, flag_c, MPIR_ATTR_AINT)
    
    flag = (flag_c /= 0)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_get_attr_f08

SUBROUTINE MPI_Comm_set_attr_f08(comm, comm_keyval, attribute_val, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Comm_set_attr_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_ATTR_AINT
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(in) :: comm_keyval
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: attribute_val
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: comm_keyval_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_set_attr_c(comm%MPI_VAL, comm_keyval, attribute_val, MPIR_ATTR_AINT)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_set_attr_f08

SUBROUTINE MPI_Type_create_keyval_f08(type_copy_attr_fn, type_delete_attr_fn, type_keyval, &
                                      extra_state, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_funptr, c_funloc, c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_SUCCESS, MPI_ADDRESS_KIND
    USE :: mpi_f08_callbacks, ONLY : MPI_Type_copy_attr_function, MPI_Type_delete_attr_function
    USE :: mpi_c_interface, ONLY : MPIR_Type_create_keyval_c
    USE :: mpi_c_interface_glue, ONLY : MPII_Keyval_set_f90_proxy
    
    IMPLICIT NONE
    
    PROCEDURE(MPI_Type_copy_attr_function) :: type_copy_attr_fn
    PROCEDURE(MPI_Type_delete_attr_function) :: type_delete_attr_fn
    INTEGER, INTENT(out) :: type_keyval
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: extra_state
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    TYPE(c_funptr) :: type_copy_attr_fn_c
    TYPE(c_funptr) :: type_delete_attr_fn_c
    INTEGER(c_int) :: type_keyval_c
    INTEGER(c_int) :: ierror_c
    
    type_copy_attr_fn_c = c_funloc(type_copy_attr_fn)
    type_delete_attr_fn_c = c_funloc(type_delete_attr_fn)
    
    ierror_c = MPIR_Type_create_keyval_c(type_copy_attr_fn_c, type_delete_attr_fn_c, type_keyval_c, &
                                         extra_state)
    IF (ierror_c == MPI_SUCCESS) THEN
        call MPII_Keyval_set_f90_proxy(type_keyval_c)
    END IF
    type_keyval = type_keyval_c
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_create_keyval_f08

SUBROUTINE MPI_Type_delete_attr_f08(datatype, type_keyval, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_delete_attr_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: type_keyval
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: type_keyval_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_delete_attr_c(datatype%MPI_VAL, type_keyval)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_delete_attr_f08

SUBROUTINE MPI_Type_free_keyval_f08(type_keyval, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface, ONLY : MPIR_Type_free_keyval_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(inout) :: type_keyval
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: type_keyval_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_free_keyval_c(type_keyval)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_free_keyval_f08

SUBROUTINE MPI_Type_get_attr_f08(datatype, type_keyval, attribute_val, flag, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_get_attr_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_ATTR_AINT
    
    IMPLICIT NONE
    
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: type_keyval
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: attribute_val
    LOGICAL, INTENT(out) :: flag
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: type_keyval_c
    INTEGER(c_int) :: flag_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_get_attr_c(datatype%MPI_VAL, type_keyval, attribute_val, flag_c, &
                                    MPIR_ATTR_AINT)
    
    flag = (flag_c /= 0)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_get_attr_f08

SUBROUTINE MPI_Type_set_attr_f08(datatype, type_keyval, attribute_val, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_set_attr_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_ATTR_AINT
    
    IMPLICIT NONE
    
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: type_keyval
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: attribute_val
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: type_keyval_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_set_attr_c(datatype%MPI_VAL, type_keyval, attribute_val, MPIR_ATTR_AINT)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_set_attr_f08

SUBROUTINE MPI_Win_create_keyval_f08(win_copy_attr_fn, win_delete_attr_fn, win_keyval, extra_state, &
                                     ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_funptr, c_funloc, c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_SUCCESS, MPI_ADDRESS_KIND
    USE :: mpi_f08_callbacks, ONLY : MPI_Win_copy_attr_function, MPI_Win_delete_attr_function
    USE :: mpi_c_interface, ONLY : MPIR_Win_create_keyval_c
    USE :: mpi_c_interface_glue, ONLY : MPII_Keyval_set_f90_proxy
    
    IMPLICIT NONE
    
    PROCEDURE(MPI_Win_copy_attr_function) :: win_copy_attr_fn
    PROCEDURE(MPI_Win_delete_attr_function) :: win_delete_attr_fn
    INTEGER, INTENT(out) :: win_keyval
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: extra_state
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    TYPE(c_funptr) :: win_copy_attr_fn_c
    TYPE(c_funptr) :: win_delete_attr_fn_c
    INTEGER(c_int) :: win_keyval_c
    INTEGER(c_int) :: ierror_c
    
    win_copy_attr_fn_c = c_funloc(win_copy_attr_fn)
    win_delete_attr_fn_c = c_funloc(win_delete_attr_fn)
    
    ierror_c = MPIR_Win_create_keyval_c(win_copy_attr_fn_c, win_delete_attr_fn_c, win_keyval_c, &
                                        extra_state)
    IF (ierror_c == MPI_SUCCESS) THEN
        call MPII_Keyval_set_f90_proxy(win_keyval_c)
    END IF
    win_keyval = win_keyval_c
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_create_keyval_f08

SUBROUTINE MPI_Win_delete_attr_f08(win, win_keyval, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Win
    USE :: mpi_c_interface_types, ONLY : c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_delete_attr_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Win), INTENT(in) :: win
    INTEGER, INTENT(in) :: win_keyval
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: win_keyval_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_delete_attr_c(win%MPI_VAL, win_keyval)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_delete_attr_f08

SUBROUTINE MPI_Win_free_keyval_f08(win_keyval, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface, ONLY : MPIR_Win_free_keyval_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(inout) :: win_keyval
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: win_keyval_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_free_keyval_c(win_keyval)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_free_keyval_f08

SUBROUTINE MPI_Win_get_attr_f08(win, win_keyval, attribute_val, flag, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Win
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_get_attr_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_ATTR_AINT
    
    IMPLICIT NONE
    
    TYPE(MPI_Win), INTENT(in) :: win
    INTEGER, INTENT(in) :: win_keyval
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: attribute_val
    LOGICAL, INTENT(out) :: flag
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: win_keyval_c
    INTEGER(c_int) :: flag_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_get_attr_c(win%MPI_VAL, win_keyval, attribute_val, flag_c, MPIR_ATTR_AINT)
    
    flag = (flag_c /= 0)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_get_attr_f08

SUBROUTINE MPI_Win_set_attr_f08(win, win_keyval, attribute_val, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Win
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_set_attr_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_ATTR_AINT
    
    IMPLICIT NONE
    
    TYPE(MPI_Win), INTENT(in) :: win
    INTEGER, INTENT(in) :: win_keyval
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: attribute_val
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: win_keyval_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_set_attr_c(win%MPI_VAL, win_keyval, attribute_val, MPIR_ATTR_AINT)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_set_attr_f08

SUBROUTINE MPI_Allgather_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, &
                               ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Allgather_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER, INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER, INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: sendcount_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int) :: recvcount_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Allgather_cdesc(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcount, &
                                    recvtype%MPI_VAL, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Allgather_f08ts

SUBROUTINE MPI_Allgather_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, &
                                 ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Allgather_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Allgather_cdesc_large(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcount, &
                                          recvtype%MPI_VAL, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Allgather_c_f08ts

SUBROUTINE MPI_Allgather_init_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
                                    comm, info, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Allgather_init_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER, INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: sendcount_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int) :: recvcount_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Allgather_init_cdesc(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcount, &
                                         recvtype%MPI_VAL, comm%MPI_VAL, info%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Allgather_init_f08ts

SUBROUTINE MPI_Allgather_init_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
                                      comm, info, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Allgather_init_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Allgather_init_cdesc_large(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcount, &
                                               recvtype%MPI_VAL, comm%MPI_VAL, info%MPI_VAL, &
                                               request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Allgather_init_c_f08ts

SUBROUTINE MPI_Allgatherv_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, &
                                comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Allgatherv_cdesc, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER, INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER, INTENT(in) :: recvcounts(*)
    INTEGER, INTENT(in) :: displs(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: sendcount_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(c_int), allocatable, dimension(:) :: displs_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Allgatherv_cdesc(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcounts, displs, &
                                     recvtype%MPI_VAL, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Allgatherv_f08ts

SUBROUTINE MPI_Allgatherv_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
                                  recvtype, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Allgatherv_cdesc_large, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: displs(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: displs_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Allgatherv_cdesc_large(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcounts, &
                                           displs, recvtype%MPI_VAL, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Allgatherv_c_f08ts

SUBROUTINE MPI_Allgatherv_init_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
                                     recvtype, comm, info, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Allgatherv_init_cdesc, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER, INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in), ASYNCHRONOUS :: recvcounts(*)
    INTEGER, INTENT(in), ASYNCHRONOUS :: displs(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: sendcount_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(c_int), allocatable, dimension(:) :: displs_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Allgatherv_init_cdesc(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcounts, &
                                          displs, recvtype%MPI_VAL, comm%MPI_VAL, info%MPI_VAL, &
                                          request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Allgatherv_init_f08ts

SUBROUTINE MPI_Allgatherv_init_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
                                       recvtype, comm, info, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Allgatherv_init_cdesc_large, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in), ASYNCHRONOUS :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in), ASYNCHRONOUS :: displs(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: displs_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Allgatherv_init_cdesc_large(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, &
                                                recvcounts, displs, recvtype%MPI_VAL, comm%MPI_VAL, &
                                                info%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Allgatherv_init_c_f08ts

SUBROUTINE MPI_Allreduce_f08ts(sendbuf, recvbuf, count, datatype, op, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Allreduce_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Allreduce_cdesc(sendbuf, recvbuf, count, datatype%MPI_VAL, op%MPI_VAL, &
                                    comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Allreduce_f08ts

SUBROUTINE MPI_Allreduce_c_f08ts(sendbuf, recvbuf, count, datatype, op, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Allreduce_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Allreduce_cdesc_large(sendbuf, recvbuf, count, datatype%MPI_VAL, op%MPI_VAL, &
                                          comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Allreduce_c_f08ts

SUBROUTINE MPI_Allreduce_init_f08ts(sendbuf, recvbuf, count, datatype, op, comm, info, request, &
                                    ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Allreduce_init_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Allreduce_init_cdesc(sendbuf, recvbuf, count, datatype%MPI_VAL, op%MPI_VAL, &
                                         comm%MPI_VAL, info%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Allreduce_init_f08ts

SUBROUTINE MPI_Allreduce_init_c_f08ts(sendbuf, recvbuf, count, datatype, op, comm, info, request, &
                                      ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Allreduce_init_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Allreduce_init_cdesc_large(sendbuf, recvbuf, count, datatype%MPI_VAL, op%MPI_VAL, &
                                               comm%MPI_VAL, info%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Allreduce_init_c_f08ts

SUBROUTINE MPI_Alltoall_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, &
                              ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Alltoall_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER, INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER, INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: sendcount_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int) :: recvcount_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Alltoall_cdesc(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcount, &
                                   recvtype%MPI_VAL, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Alltoall_f08ts

SUBROUTINE MPI_Alltoall_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, &
                                ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Alltoall_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Alltoall_cdesc_large(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcount, &
                                         recvtype%MPI_VAL, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Alltoall_c_f08ts

SUBROUTINE MPI_Alltoall_init_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, &
                                   info, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Alltoall_init_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER, INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: sendcount_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int) :: recvcount_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Alltoall_init_cdesc(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcount, &
                                        recvtype%MPI_VAL, comm%MPI_VAL, info%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Alltoall_init_f08ts

SUBROUTINE MPI_Alltoall_init_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
                                     comm, info, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Alltoall_init_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Alltoall_init_cdesc_large(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcount, &
                                              recvtype%MPI_VAL, comm%MPI_VAL, info%MPI_VAL, &
                                              request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Alltoall_init_c_f08ts

SUBROUTINE MPI_Alltoallv_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, &
                               recvtype, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_f08_link_constants, ONLY : MPI_IN_PLACE
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Alltoallv_cdesc, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), TARGET :: sendbuf
    INTEGER, INTENT(in) :: sendcounts(*)
    INTEGER, INTENT(in) :: sdispls(*)
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER, INTENT(in) :: recvcounts(*)
    INTEGER, INTENT(in) :: rdispls(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int), allocatable, dimension(:) :: sendcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(c_int), allocatable, dimension(:) :: sdispls_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int), allocatable, dimension(:) :: rdispls_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    comm_c = comm%MPI_VAL
    err = MPIR_Comm_size_c(comm_c, length)
    
    IF (c_associated(c_loc(sendbuf), c_loc(MPI_IN_PLACE))) THEN
        ierror_c = MPIR_Alltoallv_cdesc(sendbuf, sendcounts, sdispls, sendtype%MPI_VAL, recvbuf, recvcounts, &
                                        rdispls, recvtype%MPI_VAL, comm%MPI_VAL)
    ELSE
        ierror_c = MPIR_Alltoallv_cdesc(sendbuf, sendcounts, sdispls, sendtype%MPI_VAL, recvbuf, recvcounts, &
                                        rdispls, recvtype%MPI_VAL, comm%MPI_VAL)
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Alltoallv_f08ts

SUBROUTINE MPI_Alltoallv_c_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, &
                                 rdispls, recvtype, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_f08_link_constants, ONLY : MPI_IN_PLACE
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Alltoallv_cdesc_large, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), TARGET :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: sdispls(*)
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: rdispls(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: sendcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: sdispls_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: recvcounts_c
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: rdispls_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    comm_c = comm%MPI_VAL
    err = MPIR_Comm_size_c(comm_c, length)
    
    IF (c_associated(c_loc(sendbuf), c_loc(MPI_IN_PLACE))) THEN
        ierror_c = MPIR_Alltoallv_cdesc_large(sendbuf, sendcounts, sdispls, sendtype%MPI_VAL, recvbuf, &
                                              recvcounts, rdispls, recvtype%MPI_VAL, comm%MPI_VAL)
    ELSE
        ierror_c = MPIR_Alltoallv_cdesc_large(sendbuf, sendcounts, sdispls, sendtype%MPI_VAL, recvbuf, &
                                              recvcounts, rdispls, recvtype%MPI_VAL, comm%MPI_VAL)
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Alltoallv_c_f08ts

SUBROUTINE MPI_Alltoallv_init_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, &
                                    rdispls, recvtype, comm, info, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_f08_link_constants, ONLY : MPI_IN_PLACE
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Alltoallv_init_cdesc, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS, TARGET :: sendbuf
    INTEGER, INTENT(in), ASYNCHRONOUS :: sendcounts(*)
    INTEGER, INTENT(in), ASYNCHRONOUS :: sdispls(*)
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in), ASYNCHRONOUS :: recvcounts(*)
    INTEGER, INTENT(in), ASYNCHRONOUS :: rdispls(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int), allocatable, dimension(:) :: sendcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(c_int), allocatable, dimension(:) :: sdispls_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int), allocatable, dimension(:) :: rdispls_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    comm_c = comm%MPI_VAL
    err = MPIR_Comm_size_c(comm_c, length)
    
    IF (c_associated(c_loc(sendbuf), c_loc(MPI_IN_PLACE))) THEN
        ierror_c = MPIR_Alltoallv_init_cdesc(sendbuf, sendcounts, sdispls, sendtype%MPI_VAL, recvbuf, &
                                             recvcounts, rdispls, recvtype%MPI_VAL, comm%MPI_VAL, &
                                             info%MPI_VAL, request%MPI_VAL)
    ELSE
        ierror_c = MPIR_Alltoallv_init_cdesc(sendbuf, sendcounts, sdispls, sendtype%MPI_VAL, recvbuf, &
                                             recvcounts, rdispls, recvtype%MPI_VAL, comm%MPI_VAL, &
                                             info%MPI_VAL, request%MPI_VAL)
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Alltoallv_init_f08ts

SUBROUTINE MPI_Alltoallv_init_c_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, &
                                      rdispls, recvtype, comm, info, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_f08_link_constants, ONLY : MPI_IN_PLACE
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Alltoallv_init_cdesc_large, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS, TARGET :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in), ASYNCHRONOUS :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in), ASYNCHRONOUS :: sdispls(*)
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in), ASYNCHRONOUS :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in), ASYNCHRONOUS :: rdispls(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: sendcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: sdispls_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: recvcounts_c
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: rdispls_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    comm_c = comm%MPI_VAL
    err = MPIR_Comm_size_c(comm_c, length)
    
    IF (c_associated(c_loc(sendbuf), c_loc(MPI_IN_PLACE))) THEN
        ierror_c = MPIR_Alltoallv_init_cdesc_large(sendbuf, sendcounts, sdispls, sendtype%MPI_VAL, recvbuf, &
                                                   recvcounts, rdispls, recvtype%MPI_VAL, comm%MPI_VAL, &
                                                   info%MPI_VAL, request%MPI_VAL)
    ELSE
        ierror_c = MPIR_Alltoallv_init_cdesc_large(sendbuf, sendcounts, sdispls, sendtype%MPI_VAL, recvbuf, &
                                                   recvcounts, rdispls, recvtype%MPI_VAL, comm%MPI_VAL, &
                                                   info%MPI_VAL, request%MPI_VAL)
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Alltoallv_init_c_f08ts

SUBROUTINE MPI_Alltoallw_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, &
                               rdispls, recvtypes, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_f08_link_constants, ONLY : MPI_IN_PLACE
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Alltoallw_cdesc, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), TARGET :: sendbuf
    INTEGER, INTENT(in) :: sendcounts(*)
    INTEGER, INTENT(in) :: sdispls(*)
    TYPE(MPI_Datatype), INTENT(in) :: sendtypes(*)
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER, INTENT(in) :: recvcounts(*)
    INTEGER, INTENT(in) :: rdispls(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtypes(*)
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int), allocatable, dimension(:) :: sendcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(c_int), allocatable, dimension(:) :: sdispls_c
    INTEGER(c_Datatype), allocatable, dimension(:) :: sendtypes_c
    INTEGER(c_int), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int), allocatable, dimension(:) :: rdispls_c
    INTEGER(c_Datatype), allocatable, dimension(:) :: recvtypes_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    comm_c = comm%MPI_VAL
    err = MPIR_Comm_size_c(comm_c, length)
    
    IF (c_associated(c_loc(sendbuf), c_loc(MPI_IN_PLACE))) THEN
        ierror_c = MPIR_Alltoallw_cdesc(sendbuf, sendcounts, sdispls, sendtypes(1:1)%MPI_VAL, recvbuf, &
                                        recvcounts, rdispls, recvtypes(1:length)%MPI_VAL, comm%MPI_VAL)
    ELSE
        ierror_c = MPIR_Alltoallw_cdesc(sendbuf, sendcounts, sdispls, sendtypes(1:length)%MPI_VAL, recvbuf, &
                                        recvcounts, rdispls, recvtypes(1:length)%MPI_VAL, comm%MPI_VAL)
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Alltoallw_f08ts

SUBROUTINE MPI_Alltoallw_c_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, &
                                 rdispls, recvtypes, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_f08_link_constants, ONLY : MPI_IN_PLACE
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Alltoallw_cdesc_large, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), TARGET :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: sdispls(*)
    TYPE(MPI_Datatype), INTENT(in) :: sendtypes(*)
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: rdispls(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtypes(*)
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: sendcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: sdispls_c
    INTEGER(c_Datatype), allocatable, dimension(:) :: sendtypes_c
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: recvcounts_c
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: rdispls_c
    INTEGER(c_Datatype), allocatable, dimension(:) :: recvtypes_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    comm_c = comm%MPI_VAL
    err = MPIR_Comm_size_c(comm_c, length)
    
    IF (c_associated(c_loc(sendbuf), c_loc(MPI_IN_PLACE))) THEN
        ierror_c = MPIR_Alltoallw_cdesc_large(sendbuf, sendcounts, sdispls, sendtypes(1:1)%MPI_VAL, recvbuf, &
                                              recvcounts, rdispls, recvtypes(1:length)%MPI_VAL, &
                                              comm%MPI_VAL)
    ELSE
        ierror_c = MPIR_Alltoallw_cdesc_large(sendbuf, sendcounts, sdispls, sendtypes(1:length)%MPI_VAL, &
                                              recvbuf, recvcounts, rdispls, recvtypes(1:length)%MPI_VAL, &
                                              comm%MPI_VAL)
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Alltoallw_c_f08ts

SUBROUTINE MPI_Alltoallw_init_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, &
                                    rdispls, recvtypes, comm, info, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_f08_link_constants, ONLY : MPI_IN_PLACE
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Alltoallw_init_cdesc, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS, TARGET :: sendbuf
    INTEGER, INTENT(in), ASYNCHRONOUS :: sendcounts(*)
    INTEGER, INTENT(in), ASYNCHRONOUS :: sdispls(*)
    TYPE(MPI_Datatype), INTENT(in), ASYNCHRONOUS :: sendtypes(*)
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in), ASYNCHRONOUS :: recvcounts(*)
    INTEGER, INTENT(in), ASYNCHRONOUS :: rdispls(*)
    TYPE(MPI_Datatype), INTENT(in), ASYNCHRONOUS :: recvtypes(*)
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int), allocatable, dimension(:) :: sendcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(c_int), allocatable, dimension(:) :: sdispls_c
    INTEGER(c_Datatype), allocatable, dimension(:) :: sendtypes_c
    INTEGER(c_int), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int), allocatable, dimension(:) :: rdispls_c
    INTEGER(c_Datatype), allocatable, dimension(:) :: recvtypes_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    comm_c = comm%MPI_VAL
    err = MPIR_Comm_size_c(comm_c, length)
    
    IF (c_associated(c_loc(sendbuf), c_loc(MPI_IN_PLACE))) THEN
        ierror_c = MPIR_Alltoallw_init_cdesc(sendbuf, sendcounts, sdispls, sendtypes(1:1)%MPI_VAL, recvbuf, &
                                             recvcounts, rdispls, recvtypes(1:length)%MPI_VAL, comm%MPI_VAL, &
                                             info%MPI_VAL, request%MPI_VAL)
    ELSE
        ierror_c = MPIR_Alltoallw_init_cdesc(sendbuf, sendcounts, sdispls, sendtypes(1:length)%MPI_VAL, &
                                             recvbuf, recvcounts, rdispls, recvtypes(1:length)%MPI_VAL, &
                                             comm%MPI_VAL, info%MPI_VAL, request%MPI_VAL)
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Alltoallw_init_f08ts

SUBROUTINE MPI_Alltoallw_init_c_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, &
                                      rdispls, recvtypes, comm, info, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_f08_link_constants, ONLY : MPI_IN_PLACE
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Alltoallw_init_cdesc_large, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS, TARGET :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in), ASYNCHRONOUS :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in), ASYNCHRONOUS :: sdispls(*)
    TYPE(MPI_Datatype), INTENT(in), ASYNCHRONOUS :: sendtypes(*)
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in), ASYNCHRONOUS :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in), ASYNCHRONOUS :: rdispls(*)
    TYPE(MPI_Datatype), INTENT(in), ASYNCHRONOUS :: recvtypes(*)
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: sendcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: sdispls_c
    INTEGER(c_Datatype), allocatable, dimension(:) :: sendtypes_c
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: recvcounts_c
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: rdispls_c
    INTEGER(c_Datatype), allocatable, dimension(:) :: recvtypes_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    comm_c = comm%MPI_VAL
    err = MPIR_Comm_size_c(comm_c, length)
    
    IF (c_associated(c_loc(sendbuf), c_loc(MPI_IN_PLACE))) THEN
        ierror_c = MPIR_Alltoallw_init_cdesc_large(sendbuf, sendcounts, sdispls, sendtypes(1:1)%MPI_VAL, &
                                                   recvbuf, recvcounts, rdispls, &
                                                   recvtypes(1:length)%MPI_VAL, comm%MPI_VAL, info%MPI_VAL, &
                                                   request%MPI_VAL)
    ELSE
        ierror_c = MPIR_Alltoallw_init_cdesc_large(sendbuf, sendcounts, sdispls, &
                                                   sendtypes(1:length)%MPI_VAL, recvbuf, recvcounts, &
                                                   rdispls, recvtypes(1:length)%MPI_VAL, comm%MPI_VAL, &
                                                   info%MPI_VAL, request%MPI_VAL)
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Alltoallw_init_c_f08ts

SUBROUTINE MPI_Barrier_f08(comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Barrier_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Barrier_c(comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Barrier_f08

SUBROUTINE MPI_Barrier_init_f08(comm, info, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Barrier_init_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Barrier_init_c(comm%MPI_VAL, info%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Barrier_init_f08

SUBROUTINE MPI_Bcast_f08ts(buffer, count, datatype, root, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Bcast_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(inout) :: buffer
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Bcast_cdesc(buffer, count, datatype%MPI_VAL, root, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Bcast_f08ts

SUBROUTINE MPI_Bcast_c_f08ts(buffer, count, datatype, root, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Bcast_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(inout) :: buffer
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Bcast_cdesc_large(buffer, count, datatype%MPI_VAL, root, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Bcast_c_f08ts

SUBROUTINE MPI_Bcast_init_f08ts(buffer, count, datatype, root, comm, info, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Bcast_init_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buffer
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Bcast_init_cdesc(buffer, count, datatype%MPI_VAL, root, comm%MPI_VAL, info%MPI_VAL, &
                                     request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Bcast_init_f08ts

SUBROUTINE MPI_Bcast_init_c_f08ts(buffer, count, datatype, root, comm, info, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Bcast_init_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buffer
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Bcast_init_cdesc_large(buffer, count, datatype%MPI_VAL, root, comm%MPI_VAL, &
                                           info%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Bcast_init_c_f08ts

SUBROUTINE MPI_Exscan_f08ts(sendbuf, recvbuf, count, datatype, op, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Exscan_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Exscan_cdesc(sendbuf, recvbuf, count, datatype%MPI_VAL, op%MPI_VAL, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Exscan_f08ts

SUBROUTINE MPI_Exscan_c_f08ts(sendbuf, recvbuf, count, datatype, op, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Exscan_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Exscan_cdesc_large(sendbuf, recvbuf, count, datatype%MPI_VAL, op%MPI_VAL, &
                                       comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Exscan_c_f08ts

SUBROUTINE MPI_Exscan_init_f08ts(sendbuf, recvbuf, count, datatype, op, comm, info, request, &
                                 ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Exscan_init_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Exscan_init_cdesc(sendbuf, recvbuf, count, datatype%MPI_VAL, op%MPI_VAL, &
                                      comm%MPI_VAL, info%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Exscan_init_f08ts

SUBROUTINE MPI_Exscan_init_c_f08ts(sendbuf, recvbuf, count, datatype, op, comm, info, request, &
                                   ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Exscan_init_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Exscan_init_cdesc_large(sendbuf, recvbuf, count, datatype%MPI_VAL, op%MPI_VAL, &
                                            comm%MPI_VAL, info%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Exscan_init_c_f08ts

SUBROUTINE MPI_Gather_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, &
                            ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Gather_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER, INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER, INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: sendcount_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int) :: recvcount_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Gather_cdesc(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcount, &
                                 recvtype%MPI_VAL, root, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Gather_f08ts

SUBROUTINE MPI_Gather_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, &
                              comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Gather_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Gather_cdesc_large(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcount, &
                                       recvtype%MPI_VAL, root, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Gather_c_f08ts

SUBROUTINE MPI_Gather_init_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, &
                                 comm, info, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Gather_init_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER, INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: sendcount_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int) :: recvcount_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Gather_init_cdesc(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcount, &
                                      recvtype%MPI_VAL, root, comm%MPI_VAL, info%MPI_VAL, &
                                      request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Gather_init_f08ts

SUBROUTINE MPI_Gather_init_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, &
                                   comm, info, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Gather_init_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Gather_init_cdesc_large(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcount, &
                                            recvtype%MPI_VAL, root, comm%MPI_VAL, info%MPI_VAL, &
                                            request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Gather_init_c_f08ts

SUBROUTINE MPI_Gatherv_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, &
                             root, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Gatherv_cdesc, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER, INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER, INTENT(in) :: recvcounts(*)
    INTEGER, INTENT(in) :: displs(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: sendcount_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(c_int), allocatable, dimension(:) :: displs_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Gatherv_cdesc(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcounts, displs, &
                                  recvtype%MPI_VAL, root, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Gatherv_f08ts

SUBROUTINE MPI_Gatherv_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, &
                               root, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Gatherv_cdesc_large, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: displs(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: displs_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Gatherv_cdesc_large(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcounts, &
                                        displs, recvtype%MPI_VAL, root, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Gatherv_c_f08ts

SUBROUTINE MPI_Gatherv_init_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
                                  recvtype, root, comm, info, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Gatherv_init_cdesc, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER, INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in), ASYNCHRONOUS :: recvcounts(*)
    INTEGER, INTENT(in), ASYNCHRONOUS :: displs(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: sendcount_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(c_int), allocatable, dimension(:) :: displs_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Gatherv_init_cdesc(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcounts, &
                                       displs, recvtype%MPI_VAL, root, comm%MPI_VAL, info%MPI_VAL, &
                                       request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Gatherv_init_f08ts

SUBROUTINE MPI_Gatherv_init_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
                                    recvtype, root, comm, info, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Gatherv_init_cdesc_large, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in), ASYNCHRONOUS :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in), ASYNCHRONOUS :: displs(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: displs_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Gatherv_init_cdesc_large(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcounts, &
                                             displs, recvtype%MPI_VAL, root, comm%MPI_VAL, info%MPI_VAL, &
                                             request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Gatherv_init_c_f08ts

SUBROUTINE MPI_Iallgather_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, &
                                request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Iallgather_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER, INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: sendcount_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int) :: recvcount_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Iallgather_cdesc(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcount, &
                                     recvtype%MPI_VAL, comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Iallgather_f08ts

SUBROUTINE MPI_Iallgather_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, &
                                  request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Iallgather_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Iallgather_cdesc_large(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcount, &
                                           recvtype%MPI_VAL, comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Iallgather_c_f08ts

SUBROUTINE MPI_Iallgatherv_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
                                 recvtype, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Iallgatherv_cdesc, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER, INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in), ASYNCHRONOUS :: recvcounts(*)
    INTEGER, INTENT(in), ASYNCHRONOUS :: displs(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: sendcount_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(c_int), allocatable, dimension(:) :: displs_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Iallgatherv_cdesc(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcounts, displs, &
                                      recvtype%MPI_VAL, comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Iallgatherv_f08ts

SUBROUTINE MPI_Iallgatherv_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
                                   recvtype, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Iallgatherv_cdesc_large, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in), ASYNCHRONOUS :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in), ASYNCHRONOUS :: displs(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: displs_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Iallgatherv_cdesc_large(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcounts, &
                                            displs, recvtype%MPI_VAL, comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Iallgatherv_c_f08ts

SUBROUTINE MPI_Iallreduce_f08ts(sendbuf, recvbuf, count, datatype, op, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Iallreduce_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Iallreduce_cdesc(sendbuf, recvbuf, count, datatype%MPI_VAL, op%MPI_VAL, &
                                     comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Iallreduce_f08ts

SUBROUTINE MPI_Iallreduce_c_f08ts(sendbuf, recvbuf, count, datatype, op, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Iallreduce_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Iallreduce_cdesc_large(sendbuf, recvbuf, count, datatype%MPI_VAL, op%MPI_VAL, &
                                           comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Iallreduce_c_f08ts

SUBROUTINE MPI_Ialltoall_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, &
                               request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Ialltoall_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER, INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: sendcount_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int) :: recvcount_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Ialltoall_cdesc(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcount, &
                                    recvtype%MPI_VAL, comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Ialltoall_f08ts

SUBROUTINE MPI_Ialltoall_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, &
                                 request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Ialltoall_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Ialltoall_cdesc_large(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcount, &
                                          recvtype%MPI_VAL, comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Ialltoall_c_f08ts

SUBROUTINE MPI_Ialltoallv_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, &
                                rdispls, recvtype, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_link_constants, ONLY : MPI_IN_PLACE
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Ialltoallv_cdesc, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS, TARGET :: sendbuf
    INTEGER, INTENT(in), ASYNCHRONOUS :: sendcounts(*)
    INTEGER, INTENT(in), ASYNCHRONOUS :: sdispls(*)
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in), ASYNCHRONOUS :: recvcounts(*)
    INTEGER, INTENT(in), ASYNCHRONOUS :: rdispls(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int), allocatable, dimension(:) :: sendcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(c_int), allocatable, dimension(:) :: sdispls_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int), allocatable, dimension(:) :: rdispls_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    comm_c = comm%MPI_VAL
    err = MPIR_Comm_size_c(comm_c, length)
    
    IF (c_associated(c_loc(sendbuf), c_loc(MPI_IN_PLACE))) THEN
        ierror_c = MPIR_Ialltoallv_cdesc(sendbuf, sendcounts, sdispls, sendtype%MPI_VAL, recvbuf, &
                                         recvcounts, rdispls, recvtype%MPI_VAL, comm%MPI_VAL, &
                                         request%MPI_VAL)
    ELSE
        ierror_c = MPIR_Ialltoallv_cdesc(sendbuf, sendcounts, sdispls, sendtype%MPI_VAL, recvbuf, &
                                         recvcounts, rdispls, recvtype%MPI_VAL, comm%MPI_VAL, &
                                         request%MPI_VAL)
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Ialltoallv_f08ts

SUBROUTINE MPI_Ialltoallv_c_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, &
                                  rdispls, recvtype, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_f08_link_constants, ONLY : MPI_IN_PLACE
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Ialltoallv_cdesc_large, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS, TARGET :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in), ASYNCHRONOUS :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in), ASYNCHRONOUS :: sdispls(*)
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in), ASYNCHRONOUS :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in), ASYNCHRONOUS :: rdispls(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: sendcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: sdispls_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: recvcounts_c
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: rdispls_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    comm_c = comm%MPI_VAL
    err = MPIR_Comm_size_c(comm_c, length)
    
    IF (c_associated(c_loc(sendbuf), c_loc(MPI_IN_PLACE))) THEN
        ierror_c = MPIR_Ialltoallv_cdesc_large(sendbuf, sendcounts, sdispls, sendtype%MPI_VAL, recvbuf, &
                                               recvcounts, rdispls, recvtype%MPI_VAL, comm%MPI_VAL, &
                                               request%MPI_VAL)
    ELSE
        ierror_c = MPIR_Ialltoallv_cdesc_large(sendbuf, sendcounts, sdispls, sendtype%MPI_VAL, recvbuf, &
                                               recvcounts, rdispls, recvtype%MPI_VAL, comm%MPI_VAL, &
                                               request%MPI_VAL)
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Ialltoallv_c_f08ts

SUBROUTINE MPI_Ialltoallw_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, &
                                rdispls, recvtypes, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_link_constants, ONLY : MPI_IN_PLACE
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Ialltoallw_cdesc, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS, TARGET :: sendbuf
    INTEGER, INTENT(in), ASYNCHRONOUS :: sendcounts(*)
    INTEGER, INTENT(in), ASYNCHRONOUS :: sdispls(*)
    TYPE(MPI_Datatype), INTENT(in), ASYNCHRONOUS :: sendtypes(*)
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in), ASYNCHRONOUS :: recvcounts(*)
    INTEGER, INTENT(in), ASYNCHRONOUS :: rdispls(*)
    TYPE(MPI_Datatype), INTENT(in), ASYNCHRONOUS :: recvtypes(*)
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int), allocatable, dimension(:) :: sendcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(c_int), allocatable, dimension(:) :: sdispls_c
    INTEGER(c_Datatype), allocatable, dimension(:) :: sendtypes_c
    INTEGER(c_int), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int), allocatable, dimension(:) :: rdispls_c
    INTEGER(c_Datatype), allocatable, dimension(:) :: recvtypes_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    comm_c = comm%MPI_VAL
    err = MPIR_Comm_size_c(comm_c, length)
    
    IF (c_associated(c_loc(sendbuf), c_loc(MPI_IN_PLACE))) THEN
        ierror_c = MPIR_Ialltoallw_cdesc(sendbuf, sendcounts, sdispls, sendtypes(1:1)%MPI_VAL, recvbuf, &
                                         recvcounts, rdispls, recvtypes(1:length)%MPI_VAL, comm%MPI_VAL, &
                                         request%MPI_VAL)
    ELSE
        ierror_c = MPIR_Ialltoallw_cdesc(sendbuf, sendcounts, sdispls, sendtypes(1:length)%MPI_VAL, recvbuf, &
                                         recvcounts, rdispls, recvtypes(1:length)%MPI_VAL, comm%MPI_VAL, &
                                         request%MPI_VAL)
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Ialltoallw_f08ts

SUBROUTINE MPI_Ialltoallw_c_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, &
                                  rdispls, recvtypes, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_f08_link_constants, ONLY : MPI_IN_PLACE
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Ialltoallw_cdesc_large, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS, TARGET :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in), ASYNCHRONOUS :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in), ASYNCHRONOUS :: sdispls(*)
    TYPE(MPI_Datatype), INTENT(in), ASYNCHRONOUS :: sendtypes(*)
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in), ASYNCHRONOUS :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in), ASYNCHRONOUS :: rdispls(*)
    TYPE(MPI_Datatype), INTENT(in), ASYNCHRONOUS :: recvtypes(*)
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: sendcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: sdispls_c
    INTEGER(c_Datatype), allocatable, dimension(:) :: sendtypes_c
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: recvcounts_c
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: rdispls_c
    INTEGER(c_Datatype), allocatable, dimension(:) :: recvtypes_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    comm_c = comm%MPI_VAL
    err = MPIR_Comm_size_c(comm_c, length)
    
    IF (c_associated(c_loc(sendbuf), c_loc(MPI_IN_PLACE))) THEN
        ierror_c = MPIR_Ialltoallw_cdesc_large(sendbuf, sendcounts, sdispls, sendtypes(1:1)%MPI_VAL, &
                                               recvbuf, recvcounts, rdispls, recvtypes(1:length)%MPI_VAL, &
                                               comm%MPI_VAL, request%MPI_VAL)
    ELSE
        ierror_c = MPIR_Ialltoallw_cdesc_large(sendbuf, sendcounts, sdispls, sendtypes(1:length)%MPI_VAL, &
                                               recvbuf, recvcounts, rdispls, recvtypes(1:length)%MPI_VAL, &
                                               comm%MPI_VAL, request%MPI_VAL)
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Ialltoallw_c_f08ts

SUBROUTINE MPI_Ibarrier_f08(comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Ibarrier_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Ibarrier_c(comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Ibarrier_f08

SUBROUTINE MPI_Ibcast_f08ts(buffer, count, datatype, root, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Ibcast_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(inout), ASYNCHRONOUS :: buffer
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Ibcast_cdesc(buffer, count, datatype%MPI_VAL, root, comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Ibcast_f08ts

SUBROUTINE MPI_Ibcast_c_f08ts(buffer, count, datatype, root, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Ibcast_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(inout), ASYNCHRONOUS :: buffer
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Ibcast_cdesc_large(buffer, count, datatype%MPI_VAL, root, comm%MPI_VAL, &
                                       request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Ibcast_c_f08ts

SUBROUTINE MPI_Iexscan_f08ts(sendbuf, recvbuf, count, datatype, op, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Iexscan_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Iexscan_cdesc(sendbuf, recvbuf, count, datatype%MPI_VAL, op%MPI_VAL, comm%MPI_VAL, &
                                  request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Iexscan_f08ts

SUBROUTINE MPI_Iexscan_c_f08ts(sendbuf, recvbuf, count, datatype, op, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Iexscan_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Iexscan_cdesc_large(sendbuf, recvbuf, count, datatype%MPI_VAL, op%MPI_VAL, &
                                        comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Iexscan_c_f08ts

SUBROUTINE MPI_Igather_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, &
                             request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Igather_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER, INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: sendcount_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int) :: recvcount_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Igather_cdesc(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcount, &
                                  recvtype%MPI_VAL, root, comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Igather_f08ts

SUBROUTINE MPI_Igather_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, &
                               comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Igather_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Igather_cdesc_large(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcount, &
                                        recvtype%MPI_VAL, root, comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Igather_c_f08ts

SUBROUTINE MPI_Igatherv_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, &
                              root, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Igatherv_cdesc, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER, INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in), ASYNCHRONOUS :: recvcounts(*)
    INTEGER, INTENT(in), ASYNCHRONOUS :: displs(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: sendcount_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(c_int), allocatable, dimension(:) :: displs_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Igatherv_cdesc(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcounts, displs, &
                                   recvtype%MPI_VAL, root, comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Igatherv_f08ts

SUBROUTINE MPI_Igatherv_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, &
                                root, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Igatherv_cdesc_large, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in), ASYNCHRONOUS :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in), ASYNCHRONOUS :: displs(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: displs_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Igatherv_cdesc_large(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcounts, &
                                         displs, recvtype%MPI_VAL, root, comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Igatherv_c_f08ts

SUBROUTINE MPI_Ineighbor_allgather_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
                                         comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Ineighbor_allgather_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER, INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: sendcount_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int) :: recvcount_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Ineighbor_allgather_cdesc(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcount, &
                                              recvtype%MPI_VAL, comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Ineighbor_allgather_f08ts

SUBROUTINE MPI_Ineighbor_allgather_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, &
                                           recvtype, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Ineighbor_allgather_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Ineighbor_allgather_cdesc_large(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, &
                                                    recvcount, recvtype%MPI_VAL, comm%MPI_VAL, &
                                                    request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Ineighbor_allgather_c_f08ts

SUBROUTINE MPI_Ineighbor_allgatherv_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
                                          recvtype, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Ineighbor_allgatherv_cdesc, MPIR_Dist_graph_neighbors_count_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER, INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in), ASYNCHRONOUS :: recvcounts(*)
    INTEGER, INTENT(in), ASYNCHRONOUS :: displs(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: sendcount_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int) :: err, indegree, outdegree, weighted
    INTEGER(c_int), allocatable, dimension(:) :: displs_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Ineighbor_allgatherv_cdesc(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, &
                                               recvcounts, displs, recvtype%MPI_VAL, comm%MPI_VAL, &
                                               request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Ineighbor_allgatherv_f08ts

SUBROUTINE MPI_Ineighbor_allgatherv_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, &
                                            displs, recvtype, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Ineighbor_allgatherv_cdesc_large, &
        MPIR_Dist_graph_neighbors_count_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in), ASYNCHRONOUS :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in), ASYNCHRONOUS :: displs(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int) :: err, indegree, outdegree, weighted
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: displs_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Ineighbor_allgatherv_cdesc_large(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, &
                                                     recvcounts, displs, recvtype%MPI_VAL, comm%MPI_VAL, &
                                                     request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Ineighbor_allgatherv_c_f08ts

SUBROUTINE MPI_Ineighbor_alltoall_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
                                        comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Ineighbor_alltoall_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER, INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: sendcount_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int) :: recvcount_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Ineighbor_alltoall_cdesc(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcount, &
                                             recvtype%MPI_VAL, comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Ineighbor_alltoall_f08ts

SUBROUTINE MPI_Ineighbor_alltoall_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, &
                                          recvtype, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Ineighbor_alltoall_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Ineighbor_alltoall_cdesc_large(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, &
                                                   recvcount, recvtype%MPI_VAL, comm%MPI_VAL, &
                                                   request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Ineighbor_alltoall_c_f08ts

SUBROUTINE MPI_Ineighbor_alltoallv_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, &
                                         recvcounts, rdispls, recvtype, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Ineighbor_alltoallv_cdesc, MPIR_Dist_graph_neighbors_count_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER, INTENT(in), ASYNCHRONOUS :: sendcounts(*)
    INTEGER, INTENT(in), ASYNCHRONOUS :: sdispls(*)
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in), ASYNCHRONOUS :: recvcounts(*)
    INTEGER, INTENT(in), ASYNCHRONOUS :: rdispls(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int), allocatable, dimension(:) :: sendcounts_c
    INTEGER(c_int) :: err, indegree, outdegree, weighted
    INTEGER(c_int), allocatable, dimension(:) :: sdispls_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int), allocatable, dimension(:) :: rdispls_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    comm_c = comm%MPI_VAL
    err = MPIR_Dist_graph_neighbors_count_c(comm_c, indegree, outdegree, weighted)
    
    ierror_c = MPIR_Ineighbor_alltoallv_cdesc(sendbuf, sendcounts, sdispls, sendtype%MPI_VAL, recvbuf, &
                                              recvcounts, rdispls, recvtype%MPI_VAL, comm%MPI_VAL, &
                                              request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Ineighbor_alltoallv_f08ts

SUBROUTINE MPI_Ineighbor_alltoallv_c_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, &
                                           recvcounts, rdispls, recvtype, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Ineighbor_alltoallv_cdesc_large, &
        MPIR_Dist_graph_neighbors_count_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in), ASYNCHRONOUS :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in), ASYNCHRONOUS :: sdispls(*)
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in), ASYNCHRONOUS :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in), ASYNCHRONOUS :: rdispls(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: sendcounts_c
    INTEGER(c_int) :: err, indegree, outdegree, weighted
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: sdispls_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: recvcounts_c
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: rdispls_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    comm_c = comm%MPI_VAL
    err = MPIR_Dist_graph_neighbors_count_c(comm_c, indegree, outdegree, weighted)
    
    ierror_c = MPIR_Ineighbor_alltoallv_cdesc_large(sendbuf, sendcounts, sdispls, sendtype%MPI_VAL, &
                                                    recvbuf, recvcounts, rdispls, recvtype%MPI_VAL, &
                                                    comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Ineighbor_alltoallv_c_f08ts

SUBROUTINE MPI_Ineighbor_alltoallw_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, &
                                         recvcounts, rdispls, recvtypes, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Ineighbor_alltoallw_cdesc, MPIR_Dist_graph_neighbors_count_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER, INTENT(in), ASYNCHRONOUS :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in), ASYNCHRONOUS :: sdispls(*)
    TYPE(MPI_Datatype), INTENT(in), ASYNCHRONOUS :: sendtypes(*)
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in), ASYNCHRONOUS :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in), ASYNCHRONOUS :: rdispls(*)
    TYPE(MPI_Datatype), INTENT(in), ASYNCHRONOUS :: recvtypes(*)
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int), allocatable, dimension(:) :: sendcounts_c
    INTEGER(c_int) :: err, indegree, outdegree, weighted
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: sdispls_c
    INTEGER(c_Datatype), allocatable, dimension(:) :: sendtypes_c
    INTEGER(c_int), allocatable, dimension(:) :: recvcounts_c
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: rdispls_c
    INTEGER(c_Datatype), allocatable, dimension(:) :: recvtypes_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    comm_c = comm%MPI_VAL
    err = MPIR_Dist_graph_neighbors_count_c(comm_c, indegree, outdegree, weighted)
    
    ierror_c = MPIR_Ineighbor_alltoallw_cdesc(sendbuf, sendcounts, sdispls, &
                                              sendtypes(1:outdegree)%MPI_VAL, recvbuf, recvcounts, &
                                              rdispls, recvtypes(1:indegree)%MPI_VAL, comm%MPI_VAL, &
                                              request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Ineighbor_alltoallw_f08ts

SUBROUTINE MPI_Ineighbor_alltoallw_c_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, &
                                           recvcounts, rdispls, recvtypes, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Ineighbor_alltoallw_cdesc_large, &
        MPIR_Dist_graph_neighbors_count_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in), ASYNCHRONOUS :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in), ASYNCHRONOUS :: sdispls(*)
    TYPE(MPI_Datatype), INTENT(in), ASYNCHRONOUS :: sendtypes(*)
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in), ASYNCHRONOUS :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in), ASYNCHRONOUS :: rdispls(*)
    TYPE(MPI_Datatype), INTENT(in), ASYNCHRONOUS :: recvtypes(*)
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: sendcounts_c
    INTEGER(c_int) :: err, indegree, outdegree, weighted
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: sdispls_c
    INTEGER(c_Datatype), allocatable, dimension(:) :: sendtypes_c
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: recvcounts_c
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: rdispls_c
    INTEGER(c_Datatype), allocatable, dimension(:) :: recvtypes_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    comm_c = comm%MPI_VAL
    err = MPIR_Dist_graph_neighbors_count_c(comm_c, indegree, outdegree, weighted)
    
    ierror_c = MPIR_Ineighbor_alltoallw_cdesc_large(sendbuf, sendcounts, sdispls, &
                                                    sendtypes(1:outdegree)%MPI_VAL, recvbuf, recvcounts, &
                                                    rdispls, recvtypes(1:indegree)%MPI_VAL, &
                                                    comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Ineighbor_alltoallw_c_f08ts

SUBROUTINE MPI_Ireduce_f08ts(sendbuf, recvbuf, count, datatype, op, root, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Ireduce_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Ireduce_cdesc(sendbuf, recvbuf, count, datatype%MPI_VAL, op%MPI_VAL, root, &
                                  comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Ireduce_f08ts

SUBROUTINE MPI_Ireduce_c_f08ts(sendbuf, recvbuf, count, datatype, op, root, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Ireduce_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Ireduce_cdesc_large(sendbuf, recvbuf, count, datatype%MPI_VAL, op%MPI_VAL, root, &
                                        comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Ireduce_c_f08ts

SUBROUTINE MPI_Ireduce_scatter_f08ts(sendbuf, recvbuf, recvcounts, datatype, op, comm, request, &
                                     ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Ireduce_scatter_cdesc, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in), ASYNCHRONOUS :: recvcounts(*)
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Ireduce_scatter_cdesc(sendbuf, recvbuf, recvcounts, datatype%MPI_VAL, op%MPI_VAL, &
                                          comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Ireduce_scatter_f08ts

SUBROUTINE MPI_Ireduce_scatter_c_f08ts(sendbuf, recvbuf, recvcounts, datatype, op, comm, request, &
                                       ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Ireduce_scatter_cdesc_large, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in), ASYNCHRONOUS :: recvcounts(*)
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Ireduce_scatter_cdesc_large(sendbuf, recvbuf, recvcounts, datatype%MPI_VAL, &
                                                op%MPI_VAL, comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Ireduce_scatter_c_f08ts

SUBROUTINE MPI_Ireduce_scatter_block_f08ts(sendbuf, recvbuf, recvcount, datatype, op, comm, request, &
                                           ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Ireduce_scatter_block_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: recvcount_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Ireduce_scatter_block_cdesc(sendbuf, recvbuf, recvcount, datatype%MPI_VAL, &
                                                op%MPI_VAL, comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Ireduce_scatter_block_f08ts

SUBROUTINE MPI_Ireduce_scatter_block_c_f08ts(sendbuf, recvbuf, recvcount, datatype, op, comm, &
                                             request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Ireduce_scatter_block_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Ireduce_scatter_block_cdesc_large(sendbuf, recvbuf, recvcount, datatype%MPI_VAL, &
                                                      op%MPI_VAL, comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Ireduce_scatter_block_c_f08ts

SUBROUTINE MPI_Iscan_f08ts(sendbuf, recvbuf, count, datatype, op, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Iscan_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Iscan_cdesc(sendbuf, recvbuf, count, datatype%MPI_VAL, op%MPI_VAL, comm%MPI_VAL, &
                                request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Iscan_f08ts

SUBROUTINE MPI_Iscan_c_f08ts(sendbuf, recvbuf, count, datatype, op, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Iscan_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Iscan_cdesc_large(sendbuf, recvbuf, count, datatype%MPI_VAL, op%MPI_VAL, &
                                      comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Iscan_c_f08ts

SUBROUTINE MPI_Iscatter_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, &
                              comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Iscatter_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER, INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: sendcount_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int) :: recvcount_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Iscatter_cdesc(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcount, &
                                   recvtype%MPI_VAL, root, comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Iscatter_f08ts

SUBROUTINE MPI_Iscatter_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, &
                                comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Iscatter_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Iscatter_cdesc_large(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcount, &
                                         recvtype%MPI_VAL, root, comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Iscatter_c_f08ts

SUBROUTINE MPI_Iscatterv_f08ts(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, &
                               root, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Iscatterv_cdesc, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER, INTENT(in), ASYNCHRONOUS :: sendcounts(*)
    INTEGER, INTENT(in), ASYNCHRONOUS :: displs(*)
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int), allocatable, dimension(:) :: sendcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(c_int), allocatable, dimension(:) :: displs_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int) :: recvcount_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Iscatterv_cdesc(sendbuf, sendcounts, displs, sendtype%MPI_VAL, recvbuf, recvcount, &
                                    recvtype%MPI_VAL, root, comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Iscatterv_f08ts

SUBROUTINE MPI_Iscatterv_c_f08ts(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, &
                                 recvtype, root, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Iscatterv_cdesc_large, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in), ASYNCHRONOUS :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in), ASYNCHRONOUS :: displs(*)
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: sendcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: displs_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Iscatterv_cdesc_large(sendbuf, sendcounts, displs, sendtype%MPI_VAL, recvbuf, &
                                          recvcount, recvtype%MPI_VAL, root, comm%MPI_VAL, &
                                          request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Iscatterv_c_f08ts

SUBROUTINE MPI_Neighbor_allgather_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
                                        comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Neighbor_allgather_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER, INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER, INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: sendcount_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int) :: recvcount_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Neighbor_allgather_cdesc(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcount, &
                                             recvtype%MPI_VAL, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Neighbor_allgather_f08ts

SUBROUTINE MPI_Neighbor_allgather_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, &
                                          recvtype, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Neighbor_allgather_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Neighbor_allgather_cdesc_large(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, &
                                                   recvcount, recvtype%MPI_VAL, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Neighbor_allgather_c_f08ts

SUBROUTINE MPI_Neighbor_allgather_init_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, &
                                             recvtype, comm, info, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Neighbor_allgather_init_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER, INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: sendcount_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int) :: recvcount_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Neighbor_allgather_init_cdesc(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, &
                                                  recvcount, recvtype%MPI_VAL, comm%MPI_VAL, &
                                                  info%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Neighbor_allgather_init_f08ts

SUBROUTINE MPI_Neighbor_allgather_init_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, &
                                               recvtype, comm, info, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Neighbor_allgather_init_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Neighbor_allgather_init_cdesc_large(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, &
                                                        recvcount, recvtype%MPI_VAL, comm%MPI_VAL, &
                                                        info%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Neighbor_allgather_init_c_f08ts

SUBROUTINE MPI_Neighbor_allgatherv_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
                                         recvtype, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Neighbor_allgatherv_cdesc, MPIR_Dist_graph_neighbors_count_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER, INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER, INTENT(in) :: recvcounts(*)
    INTEGER, INTENT(in) :: displs(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: sendcount_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int) :: err, indegree, outdegree, weighted
    INTEGER(c_int), allocatable, dimension(:) :: displs_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Neighbor_allgatherv_cdesc(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcounts, &
                                              displs, recvtype%MPI_VAL, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Neighbor_allgatherv_f08ts

SUBROUTINE MPI_Neighbor_allgatherv_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, &
                                           displs, recvtype, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Neighbor_allgatherv_cdesc_large, &
        MPIR_Dist_graph_neighbors_count_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: displs(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int) :: err, indegree, outdegree, weighted
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: displs_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Neighbor_allgatherv_cdesc_large(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, &
                                                    recvcounts, displs, recvtype%MPI_VAL, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Neighbor_allgatherv_c_f08ts

SUBROUTINE MPI_Neighbor_allgatherv_init_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, &
                                              displs, recvtype, comm, info, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Neighbor_allgatherv_init_cdesc, &
        MPIR_Dist_graph_neighbors_count_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER, INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in), ASYNCHRONOUS :: recvcounts(*)
    INTEGER, INTENT(in) :: displs(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: sendcount_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int) :: err, indegree, outdegree, weighted
    INTEGER(c_int), allocatable, dimension(:) :: displs_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Neighbor_allgatherv_init_cdesc(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, &
                                                   recvcounts, displs, recvtype%MPI_VAL, comm%MPI_VAL, &
                                                   info%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Neighbor_allgatherv_init_f08ts

SUBROUTINE MPI_Neighbor_allgatherv_init_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, &
                                                displs, recvtype, comm, info, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Neighbor_allgatherv_init_cdesc_large, &
        MPIR_Dist_graph_neighbors_count_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in), ASYNCHRONOUS :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: displs(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int) :: err, indegree, outdegree, weighted
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: displs_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Neighbor_allgatherv_init_cdesc_large(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, &
                                                         recvcounts, displs, recvtype%MPI_VAL, &
                                                         comm%MPI_VAL, info%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Neighbor_allgatherv_init_c_f08ts

SUBROUTINE MPI_Neighbor_alltoall_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
                                       comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Neighbor_alltoall_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER, INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER, INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: sendcount_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int) :: recvcount_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Neighbor_alltoall_cdesc(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcount, &
                                            recvtype%MPI_VAL, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Neighbor_alltoall_f08ts

SUBROUTINE MPI_Neighbor_alltoall_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
                                         comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Neighbor_alltoall_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Neighbor_alltoall_cdesc_large(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, &
                                                  recvcount, recvtype%MPI_VAL, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Neighbor_alltoall_c_f08ts

SUBROUTINE MPI_Neighbor_alltoall_init_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, &
                                            recvtype, comm, info, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Neighbor_alltoall_init_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER, INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: sendcount_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int) :: recvcount_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Neighbor_alltoall_init_cdesc(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, &
                                                 recvcount, recvtype%MPI_VAL, comm%MPI_VAL, &
                                                 info%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Neighbor_alltoall_init_f08ts

SUBROUTINE MPI_Neighbor_alltoall_init_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, &
                                              recvtype, comm, info, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Neighbor_alltoall_init_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Neighbor_alltoall_init_cdesc_large(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, &
                                                       recvcount, recvtype%MPI_VAL, comm%MPI_VAL, &
                                                       info%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Neighbor_alltoall_init_c_f08ts

SUBROUTINE MPI_Neighbor_alltoallv_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, &
                                        rdispls, recvtype, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Neighbor_alltoallv_cdesc, MPIR_Dist_graph_neighbors_count_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER, INTENT(in) :: sendcounts(*)
    INTEGER, INTENT(in) :: sdispls(*)
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER, INTENT(in) :: recvcounts(*)
    INTEGER, INTENT(in) :: rdispls(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int), allocatable, dimension(:) :: sendcounts_c
    INTEGER(c_int) :: err, indegree, outdegree, weighted
    INTEGER(c_int), allocatable, dimension(:) :: sdispls_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int), allocatable, dimension(:) :: rdispls_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    comm_c = comm%MPI_VAL
    err = MPIR_Dist_graph_neighbors_count_c(comm_c, indegree, outdegree, weighted)
    
    ierror_c = MPIR_Neighbor_alltoallv_cdesc(sendbuf, sendcounts, sdispls, sendtype%MPI_VAL, recvbuf, &
                                             recvcounts, rdispls, recvtype%MPI_VAL, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Neighbor_alltoallv_f08ts

SUBROUTINE MPI_Neighbor_alltoallv_c_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, &
                                          recvcounts, rdispls, recvtype, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Neighbor_alltoallv_cdesc_large, &
        MPIR_Dist_graph_neighbors_count_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: sdispls(*)
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: rdispls(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: sendcounts_c
    INTEGER(c_int) :: err, indegree, outdegree, weighted
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: sdispls_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: recvcounts_c
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: rdispls_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    comm_c = comm%MPI_VAL
    err = MPIR_Dist_graph_neighbors_count_c(comm_c, indegree, outdegree, weighted)
    
    ierror_c = MPIR_Neighbor_alltoallv_cdesc_large(sendbuf, sendcounts, sdispls, sendtype%MPI_VAL, &
                                                   recvbuf, recvcounts, rdispls, recvtype%MPI_VAL, &
                                                   comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Neighbor_alltoallv_c_f08ts

SUBROUTINE MPI_Neighbor_alltoallv_init_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, &
                                             recvcounts, rdispls, recvtype, comm, info, request, &
                                             ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Neighbor_alltoallv_init_cdesc, &
        MPIR_Dist_graph_neighbors_count_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER, INTENT(in), ASYNCHRONOUS :: sendcounts(*)
    INTEGER, INTENT(in), ASYNCHRONOUS :: sdispls(*)
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in), ASYNCHRONOUS :: recvcounts(*)
    INTEGER, INTENT(in), ASYNCHRONOUS :: rdispls(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int), allocatable, dimension(:) :: sendcounts_c
    INTEGER(c_int) :: err, indegree, outdegree, weighted
    INTEGER(c_int), allocatable, dimension(:) :: sdispls_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int), allocatable, dimension(:) :: rdispls_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    comm_c = comm%MPI_VAL
    err = MPIR_Dist_graph_neighbors_count_c(comm_c, indegree, outdegree, weighted)
    
    ierror_c = MPIR_Neighbor_alltoallv_init_cdesc(sendbuf, sendcounts, sdispls, sendtype%MPI_VAL, &
                                                  recvbuf, recvcounts, rdispls, recvtype%MPI_VAL, &
                                                  comm%MPI_VAL, info%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Neighbor_alltoallv_init_f08ts

SUBROUTINE MPI_Neighbor_alltoallv_init_c_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, &
                                               recvcounts, rdispls, recvtype, comm, info, request, &
                                               ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Neighbor_alltoallv_init_cdesc_large, &
        MPIR_Dist_graph_neighbors_count_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in), ASYNCHRONOUS :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in), ASYNCHRONOUS :: sdispls(*)
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in), ASYNCHRONOUS :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in), ASYNCHRONOUS :: rdispls(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: sendcounts_c
    INTEGER(c_int) :: err, indegree, outdegree, weighted
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: sdispls_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: recvcounts_c
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: rdispls_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    comm_c = comm%MPI_VAL
    err = MPIR_Dist_graph_neighbors_count_c(comm_c, indegree, outdegree, weighted)
    
    ierror_c = MPIR_Neighbor_alltoallv_init_cdesc_large(sendbuf, sendcounts, sdispls, sendtype%MPI_VAL, &
                                                        recvbuf, recvcounts, rdispls, recvtype%MPI_VAL, &
                                                        comm%MPI_VAL, info%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Neighbor_alltoallv_init_c_f08ts

SUBROUTINE MPI_Neighbor_alltoallw_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, &
                                        recvcounts, rdispls, recvtypes, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Neighbor_alltoallw_cdesc, MPIR_Dist_graph_neighbors_count_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER, INTENT(in) :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: sdispls(*)
    TYPE(MPI_Datatype), INTENT(in) :: sendtypes(*)
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER, INTENT(in) :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: rdispls(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtypes(*)
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int), allocatable, dimension(:) :: sendcounts_c
    INTEGER(c_int) :: err, indegree, outdegree, weighted
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: sdispls_c
    INTEGER(c_Datatype), allocatable, dimension(:) :: sendtypes_c
    INTEGER(c_int), allocatable, dimension(:) :: recvcounts_c
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: rdispls_c
    INTEGER(c_Datatype), allocatable, dimension(:) :: recvtypes_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    comm_c = comm%MPI_VAL
    err = MPIR_Dist_graph_neighbors_count_c(comm_c, indegree, outdegree, weighted)
    
    ierror_c = MPIR_Neighbor_alltoallw_cdesc(sendbuf, sendcounts, sdispls, &
                                             sendtypes(1:outdegree)%MPI_VAL, recvbuf, recvcounts, &
                                             rdispls, recvtypes(1:indegree)%MPI_VAL, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Neighbor_alltoallw_f08ts

SUBROUTINE MPI_Neighbor_alltoallw_c_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, &
                                          recvcounts, rdispls, recvtypes, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Neighbor_alltoallw_cdesc_large, &
        MPIR_Dist_graph_neighbors_count_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: sdispls(*)
    TYPE(MPI_Datatype), INTENT(in) :: sendtypes(*)
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: rdispls(*)
    TYPE(MPI_Datatype), INTENT(in) :: recvtypes(*)
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: sendcounts_c
    INTEGER(c_int) :: err, indegree, outdegree, weighted
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: sdispls_c
    INTEGER(c_Datatype), allocatable, dimension(:) :: sendtypes_c
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: recvcounts_c
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: rdispls_c
    INTEGER(c_Datatype), allocatable, dimension(:) :: recvtypes_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    comm_c = comm%MPI_VAL
    err = MPIR_Dist_graph_neighbors_count_c(comm_c, indegree, outdegree, weighted)
    
    ierror_c = MPIR_Neighbor_alltoallw_cdesc_large(sendbuf, sendcounts, sdispls, &
                                                   sendtypes(1:outdegree)%MPI_VAL, recvbuf, recvcounts, &
                                                   rdispls, recvtypes(1:indegree)%MPI_VAL, &
                                                   comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Neighbor_alltoallw_c_f08ts

SUBROUTINE MPI_Neighbor_alltoallw_init_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, &
                                             recvcounts, rdispls, recvtypes, comm, info, request, &
                                             ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Neighbor_alltoallw_init_cdesc, &
        MPIR_Dist_graph_neighbors_count_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER, INTENT(in), ASYNCHRONOUS :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in), ASYNCHRONOUS :: sdispls(*)
    TYPE(MPI_Datatype), INTENT(in), ASYNCHRONOUS :: sendtypes(*)
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in), ASYNCHRONOUS :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in), ASYNCHRONOUS :: rdispls(*)
    TYPE(MPI_Datatype), INTENT(in), ASYNCHRONOUS :: recvtypes(*)
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int), allocatable, dimension(:) :: sendcounts_c
    INTEGER(c_int) :: err, indegree, outdegree, weighted
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: sdispls_c
    INTEGER(c_Datatype), allocatable, dimension(:) :: sendtypes_c
    INTEGER(c_int), allocatable, dimension(:) :: recvcounts_c
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: rdispls_c
    INTEGER(c_Datatype), allocatable, dimension(:) :: recvtypes_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    comm_c = comm%MPI_VAL
    err = MPIR_Dist_graph_neighbors_count_c(comm_c, indegree, outdegree, weighted)
    
    ierror_c = MPIR_Neighbor_alltoallw_init_cdesc(sendbuf, sendcounts, sdispls, &
                                                  sendtypes(1:outdegree)%MPI_VAL, recvbuf, recvcounts, &
                                                  rdispls, recvtypes(1:indegree)%MPI_VAL, comm%MPI_VAL, &
                                                  info%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Neighbor_alltoallw_init_f08ts

SUBROUTINE MPI_Neighbor_alltoallw_init_c_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, &
                                               recvcounts, rdispls, recvtypes, comm, info, request, &
                                               ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Neighbor_alltoallw_init_cdesc_large, &
        MPIR_Dist_graph_neighbors_count_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in), ASYNCHRONOUS :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in), ASYNCHRONOUS :: sdispls(*)
    TYPE(MPI_Datatype), INTENT(in), ASYNCHRONOUS :: sendtypes(*)
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in), ASYNCHRONOUS :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in), ASYNCHRONOUS :: rdispls(*)
    TYPE(MPI_Datatype), INTENT(in), ASYNCHRONOUS :: recvtypes(*)
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: sendcounts_c
    INTEGER(c_int) :: err, indegree, outdegree, weighted
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: sdispls_c
    INTEGER(c_Datatype), allocatable, dimension(:) :: sendtypes_c
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: recvcounts_c
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: rdispls_c
    INTEGER(c_Datatype), allocatable, dimension(:) :: recvtypes_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    comm_c = comm%MPI_VAL
    err = MPIR_Dist_graph_neighbors_count_c(comm_c, indegree, outdegree, weighted)
    
    ierror_c = MPIR_Neighbor_alltoallw_init_cdesc_large(sendbuf, sendcounts, sdispls, &
                                                        sendtypes(1:outdegree)%MPI_VAL, recvbuf, &
                                                        recvcounts, rdispls, &
                                                        recvtypes(1:indegree)%MPI_VAL, comm%MPI_VAL, &
                                                        info%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Neighbor_alltoallw_init_c_f08ts

SUBROUTINE MPI_Reduce_f08ts(sendbuf, recvbuf, count, datatype, op, root, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Reduce_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Reduce_cdesc(sendbuf, recvbuf, count, datatype%MPI_VAL, op%MPI_VAL, root, &
                                 comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Reduce_f08ts

SUBROUTINE MPI_Reduce_c_f08ts(sendbuf, recvbuf, count, datatype, op, root, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Reduce_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Reduce_cdesc_large(sendbuf, recvbuf, count, datatype%MPI_VAL, op%MPI_VAL, root, &
                                       comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Reduce_c_f08ts

SUBROUTINE MPI_Reduce_init_f08ts(sendbuf, recvbuf, count, datatype, op, root, comm, info, request, &
                                 ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Reduce_init_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Reduce_init_cdesc(sendbuf, recvbuf, count, datatype%MPI_VAL, op%MPI_VAL, root, &
                                      comm%MPI_VAL, info%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Reduce_init_f08ts

SUBROUTINE MPI_Reduce_init_c_f08ts(sendbuf, recvbuf, count, datatype, op, root, comm, info, request, &
                                   ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Reduce_init_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Reduce_init_cdesc_large(sendbuf, recvbuf, count, datatype%MPI_VAL, op%MPI_VAL, root, &
                                            comm%MPI_VAL, info%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Reduce_init_c_f08ts

SUBROUTINE MPI_Reduce_local_f08ts(inbuf, inoutbuf, count, datatype, op, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op
    USE :: mpi_c_interface, ONLY : MPIR_Reduce_local_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: inbuf
    TYPE(*), DIMENSION(..), INTENT(inout) :: inoutbuf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Reduce_local_cdesc(inbuf, inoutbuf, count, datatype%MPI_VAL, op%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Reduce_local_f08ts

SUBROUTINE MPI_Reduce_local_c_f08ts(inbuf, inoutbuf, count, datatype, op, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op
    USE :: mpi_c_interface, ONLY : MPIR_Reduce_local_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: inbuf
    TYPE(*), DIMENSION(..), INTENT(inout) :: inoutbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Reduce_local_cdesc_large(inbuf, inoutbuf, count, datatype%MPI_VAL, op%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Reduce_local_c_f08ts

SUBROUTINE MPI_Reduce_scatter_f08ts(sendbuf, recvbuf, recvcounts, datatype, op, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Reduce_scatter_cdesc, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER, INTENT(in) :: recvcounts(*)
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Reduce_scatter_cdesc(sendbuf, recvbuf, recvcounts, datatype%MPI_VAL, op%MPI_VAL, &
                                         comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Reduce_scatter_f08ts

SUBROUTINE MPI_Reduce_scatter_c_f08ts(sendbuf, recvbuf, recvcounts, datatype, op, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Reduce_scatter_cdesc_large, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Reduce_scatter_cdesc_large(sendbuf, recvbuf, recvcounts, datatype%MPI_VAL, &
                                               op%MPI_VAL, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Reduce_scatter_c_f08ts

SUBROUTINE MPI_Reduce_scatter_block_f08ts(sendbuf, recvbuf, recvcount, datatype, op, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Reduce_scatter_block_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER, INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: recvcount_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Reduce_scatter_block_cdesc(sendbuf, recvbuf, recvcount, datatype%MPI_VAL, &
                                               op%MPI_VAL, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Reduce_scatter_block_f08ts

SUBROUTINE MPI_Reduce_scatter_block_c_f08ts(sendbuf, recvbuf, recvcount, datatype, op, comm, &
                                            ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Reduce_scatter_block_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Reduce_scatter_block_cdesc_large(sendbuf, recvbuf, recvcount, datatype%MPI_VAL, &
                                                     op%MPI_VAL, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Reduce_scatter_block_c_f08ts

SUBROUTINE MPI_Reduce_scatter_block_init_f08ts(sendbuf, recvbuf, recvcount, datatype, op, comm, &
                                               info, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Reduce_scatter_block_init_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: recvcount_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Reduce_scatter_block_init_cdesc(sendbuf, recvbuf, recvcount, datatype%MPI_VAL, &
                                                    op%MPI_VAL, comm%MPI_VAL, info%MPI_VAL, &
                                                    request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Reduce_scatter_block_init_f08ts

SUBROUTINE MPI_Reduce_scatter_block_init_c_f08ts(sendbuf, recvbuf, recvcount, datatype, op, comm, &
                                                 info, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Reduce_scatter_block_init_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Reduce_scatter_block_init_cdesc_large(sendbuf, recvbuf, recvcount, datatype%MPI_VAL, &
                                                          op%MPI_VAL, comm%MPI_VAL, info%MPI_VAL, &
                                                          request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Reduce_scatter_block_init_c_f08ts

SUBROUTINE MPI_Reduce_scatter_init_f08ts(sendbuf, recvbuf, recvcounts, datatype, op, comm, info, &
                                         request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Reduce_scatter_init_cdesc, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in), ASYNCHRONOUS :: recvcounts(*)
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Reduce_scatter_init_cdesc(sendbuf, recvbuf, recvcounts, datatype%MPI_VAL, &
                                              op%MPI_VAL, comm%MPI_VAL, info%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Reduce_scatter_init_f08ts

SUBROUTINE MPI_Reduce_scatter_init_c_f08ts(sendbuf, recvbuf, recvcounts, datatype, op, comm, info, &
                                           request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Reduce_scatter_init_cdesc_large, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in), ASYNCHRONOUS :: recvcounts(*)
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: recvcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Reduce_scatter_init_cdesc_large(sendbuf, recvbuf, recvcounts, datatype%MPI_VAL, &
                                                    op%MPI_VAL, comm%MPI_VAL, info%MPI_VAL, &
                                                    request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Reduce_scatter_init_c_f08ts

SUBROUTINE MPI_Scan_f08ts(sendbuf, recvbuf, count, datatype, op, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Scan_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Scan_cdesc(sendbuf, recvbuf, count, datatype%MPI_VAL, op%MPI_VAL, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Scan_f08ts

SUBROUTINE MPI_Scan_c_f08ts(sendbuf, recvbuf, count, datatype, op, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Scan_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Scan_cdesc_large(sendbuf, recvbuf, count, datatype%MPI_VAL, op%MPI_VAL, &
                                     comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Scan_c_f08ts

SUBROUTINE MPI_Scan_init_f08ts(sendbuf, recvbuf, count, datatype, op, comm, info, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Scan_init_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Scan_init_cdesc(sendbuf, recvbuf, count, datatype%MPI_VAL, op%MPI_VAL, comm%MPI_VAL, &
                                    info%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Scan_init_f08ts

SUBROUTINE MPI_Scan_init_c_f08ts(sendbuf, recvbuf, count, datatype, op, comm, info, request, &
                                 ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Scan_init_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Scan_init_cdesc_large(sendbuf, recvbuf, count, datatype%MPI_VAL, op%MPI_VAL, &
                                          comm%MPI_VAL, info%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Scan_init_c_f08ts

SUBROUTINE MPI_Scatter_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, &
                             ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Scatter_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER, INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER, INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: sendcount_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int) :: recvcount_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Scatter_cdesc(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcount, &
                                  recvtype%MPI_VAL, root, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Scatter_f08ts

SUBROUTINE MPI_Scatter_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, &
                               comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Scatter_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Scatter_cdesc_large(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcount, &
                                        recvtype%MPI_VAL, root, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Scatter_c_f08ts

SUBROUTINE MPI_Scatter_init_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, &
                                  comm, info, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Scatter_init_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER, INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: sendcount_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int) :: recvcount_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Scatter_init_cdesc(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcount, &
                                       recvtype%MPI_VAL, root, comm%MPI_VAL, info%MPI_VAL, &
                                       request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Scatter_init_f08ts

SUBROUTINE MPI_Scatter_init_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
                                    root, comm, info, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Scatter_init_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Scatter_init_cdesc_large(sendbuf, sendcount, sendtype%MPI_VAL, recvbuf, recvcount, &
                                             recvtype%MPI_VAL, root, comm%MPI_VAL, info%MPI_VAL, &
                                             request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Scatter_init_c_f08ts

SUBROUTINE MPI_Scatterv_f08ts(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, &
                              root, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Scatterv_cdesc, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER, INTENT(in) :: sendcounts(*)
    INTEGER, INTENT(in) :: displs(*)
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER, INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int), allocatable, dimension(:) :: sendcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(c_int), allocatable, dimension(:) :: displs_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int) :: recvcount_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Scatterv_cdesc(sendbuf, sendcounts, displs, sendtype%MPI_VAL, recvbuf, recvcount, &
                                   recvtype%MPI_VAL, root, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Scatterv_f08ts

SUBROUTINE MPI_Scatterv_c_f08ts(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, &
                                root, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Scatterv_cdesc_large, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: displs(*)
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: sendcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: displs_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Scatterv_cdesc_large(sendbuf, sendcounts, displs, sendtype%MPI_VAL, recvbuf, &
                                         recvcount, recvtype%MPI_VAL, root, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Scatterv_c_f08ts

SUBROUTINE MPI_Scatterv_init_f08ts(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, &
                                   recvtype, root, comm, info, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Scatterv_init_cdesc, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER, INTENT(in), ASYNCHRONOUS :: sendcounts(*)
    INTEGER, INTENT(in), ASYNCHRONOUS :: displs(*)
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int), allocatable, dimension(:) :: sendcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(c_int), allocatable, dimension(:) :: displs_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int) :: recvcount_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Scatterv_init_cdesc(sendbuf, sendcounts, displs, sendtype%MPI_VAL, recvbuf, &
                                        recvcount, recvtype%MPI_VAL, root, comm%MPI_VAL, info%MPI_VAL, &
                                        request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Scatterv_init_f08ts

SUBROUTINE MPI_Scatterv_init_c_f08ts(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, &
                                     recvtype, root, comm, info, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Scatterv_init_cdesc_large, MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in), ASYNCHRONOUS :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in), ASYNCHRONOUS :: displs(*)
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(KIND=MPI_COUNT_KIND), allocatable, dimension(:) :: sendcounts_c
    INTEGER(c_int) :: err, length
    INTEGER(KIND=MPI_ADDRESS_KIND), allocatable, dimension(:) :: displs_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Scatterv_init_cdesc_large(sendbuf, sendcounts, displs, sendtype%MPI_VAL, recvbuf, &
                                              recvcount, recvtype%MPI_VAL, root, comm%MPI_VAL, &
                                              info%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Scatterv_init_c_f08ts

SUBROUTINE MPI_Comm_compare_f08(comm1, comm2, result, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Comm_compare_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm1
    TYPE(MPI_Comm), INTENT(in) :: comm2
    INTEGER, INTENT(out) :: result
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm1_c
    INTEGER(c_Comm) :: comm2_c
    INTEGER(c_int) :: result_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_compare_c(comm1%MPI_VAL, comm2%MPI_VAL, result)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_compare_f08

SUBROUTINE MPI_Comm_create_f08(comm, group, newcomm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Group
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Group
    USE :: mpi_c_interface, ONLY : MPIR_Comm_create_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Group), INTENT(in) :: group
    TYPE(MPI_Comm), INTENT(out) :: newcomm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Group) :: group_c
    INTEGER(c_Comm) :: newcomm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_create_c(comm%MPI_VAL, group%MPI_VAL, newcomm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_create_f08

SUBROUTINE MPI_Comm_create_group_f08(comm, group, tag, newcomm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Group
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Group
    USE :: mpi_c_interface, ONLY : MPIR_Comm_create_group_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Group), INTENT(in) :: group
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(out) :: newcomm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Group) :: group_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: newcomm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_create_group_c(comm%MPI_VAL, group%MPI_VAL, tag, newcomm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_create_group_f08

SUBROUTINE MPI_Comm_dup_f08(comm, newcomm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Comm_dup_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Comm), INTENT(out) :: newcomm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Comm) :: newcomm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_dup_c(comm%MPI_VAL, newcomm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_dup_f08

SUBROUTINE MPI_Comm_dup_with_info_f08(comm, info, newcomm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Info
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Info
    USE :: mpi_c_interface, ONLY : MPIR_Comm_dup_with_info_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Comm), INTENT(out) :: newcomm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Comm) :: newcomm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_dup_with_info_c(comm%MPI_VAL, info%MPI_VAL, newcomm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_dup_with_info_f08

SUBROUTINE MPI_Comm_free_f08(comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Comm_free_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(inout) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_free_c(comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_free_f08

SUBROUTINE MPI_Comm_get_info_f08(comm, info_used, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Info
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Info
    USE :: mpi_c_interface, ONLY : MPIR_Comm_get_info_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(out) :: info_used
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_used_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_get_info_c(comm%MPI_VAL, info_used%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_get_info_f08

SUBROUTINE MPI_Comm_get_name_f08(comm, comm_name, resultlen, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_MAX_OBJECT_NAME
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Comm_get_name_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_c2f
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    CHARACTER(len=MPI_MAX_OBJECT_NAME), INTENT(out) :: comm_name
    INTEGER, INTENT(out) :: resultlen
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    character(kind=c_char) :: comm_name_c(MPI_MAX_OBJECT_NAME + 1)
    INTEGER(c_int) :: resultlen_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_get_name_c(comm%MPI_VAL, comm_name_c, resultlen)
    
    call MPIR_Fortran_string_c2f(comm_name_c, comm_name)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_get_name_f08

SUBROUTINE MPI_Comm_group_f08(comm, group, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Group
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Group
    USE :: mpi_c_interface, ONLY : MPIR_Comm_group_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Group), INTENT(out) :: group
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Group) :: group_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_group_c(comm%MPI_VAL, group%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_group_f08

SUBROUTINE MPI_Comm_idup_f08(comm, newcomm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Comm_idup_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Comm), INTENT(out), ASYNCHRONOUS :: newcomm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Comm) :: newcomm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_idup_c(comm%MPI_VAL, newcomm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_idup_f08

SUBROUTINE MPI_Comm_idup_with_info_f08(comm, info, newcomm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Comm_idup_with_info_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Comm), INTENT(out), ASYNCHRONOUS :: newcomm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Comm) :: newcomm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_idup_with_info_c(comm%MPI_VAL, info%MPI_VAL, newcomm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_idup_with_info_f08

SUBROUTINE MPI_Comm_rank_f08(comm, rank, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Comm_rank_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(out) :: rank
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: rank_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_rank_c(comm%MPI_VAL, rank)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_rank_f08

SUBROUTINE MPI_Comm_remote_group_f08(comm, group, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Group
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Group
    USE :: mpi_c_interface, ONLY : MPIR_Comm_remote_group_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Group), INTENT(out) :: group
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Group) :: group_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_remote_group_c(comm%MPI_VAL, group%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_remote_group_f08

SUBROUTINE MPI_Comm_remote_size_f08(comm, size, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Comm_remote_size_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(out) :: size
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: size_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_remote_size_c(comm%MPI_VAL, size)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_remote_size_f08

SUBROUTINE MPI_Comm_set_info_f08(comm, info, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Info
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Info
    USE :: mpi_c_interface, ONLY : MPIR_Comm_set_info_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_set_info_c(comm%MPI_VAL, info%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_set_info_f08

SUBROUTINE MPI_Comm_set_name_f08(comm, comm_name, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Comm_set_name_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_f2c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    CHARACTER(len=*), INTENT(in) :: comm_name
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    character(kind=c_char) :: comm_name_c(len_trim(comm_name) + 1)
    INTEGER(c_int) :: ierror_c
    
    call MPIR_Fortran_string_f2c(comm_name, comm_name_c)
    
    ierror_c = MPIR_Comm_set_name_c(comm%MPI_VAL, comm_name_c)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_set_name_f08

SUBROUTINE MPI_Comm_size_f08(comm, size, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Comm_size_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(out) :: size
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: size_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_size_c(comm%MPI_VAL, size)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_size_f08

SUBROUTINE MPI_Comm_split_f08(comm, color, key, newcomm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Comm_split_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(in) :: color
    INTEGER, INTENT(in) :: key
    TYPE(MPI_Comm), INTENT(out) :: newcomm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: color_c
    INTEGER(c_int) :: key_c
    INTEGER(c_Comm) :: newcomm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_split_c(comm%MPI_VAL, color, key, newcomm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_split_f08

SUBROUTINE MPI_Comm_split_type_f08(comm, split_type, key, info, newcomm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Info
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Info
    USE :: mpi_c_interface, ONLY : MPIR_Comm_split_type_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(in) :: split_type
    INTEGER, INTENT(in) :: key
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Comm), INTENT(out) :: newcomm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: split_type_c
    INTEGER(c_int) :: key_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Comm) :: newcomm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_split_type_c(comm%MPI_VAL, split_type, key, info%MPI_VAL, newcomm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_split_type_f08

SUBROUTINE MPI_Comm_test_inter_f08(comm, flag, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Comm_test_inter_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    LOGICAL, INTENT(out) :: flag
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: flag_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_test_inter_c(comm%MPI_VAL, flag_c)
    
    flag = (flag_c /= 0)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_test_inter_f08

SUBROUTINE MPI_Intercomm_create_f08(local_comm, local_leader, peer_comm, remote_leader, tag, &
                                    newintercomm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Intercomm_create_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: local_comm
    INTEGER, INTENT(in) :: local_leader
    TYPE(MPI_Comm), INTENT(in) :: peer_comm
    INTEGER, INTENT(in) :: remote_leader
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(out) :: newintercomm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: local_comm_c
    INTEGER(c_int) :: local_leader_c
    INTEGER(c_Comm) :: peer_comm_c
    INTEGER(c_int) :: remote_leader_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: newintercomm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Intercomm_create_c(local_comm%MPI_VAL, local_leader, peer_comm%MPI_VAL, &
                                       remote_leader, tag, newintercomm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Intercomm_create_f08

SUBROUTINE MPI_Intercomm_create_from_groups_f08(local_group, local_leader, remote_group, &
                                                remote_leader, stringtag, info, errhandler, &
                                                newintercomm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_f08_types, ONLY : MPI_Group, MPI_Info, MPI_Errhandler, MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Group, c_Info, c_Errhandler, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Intercomm_create_from_groups_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_f2c
    
    IMPLICIT NONE
    
    TYPE(MPI_Group), INTENT(in) :: local_group
    INTEGER, INTENT(in) :: local_leader
    TYPE(MPI_Group), INTENT(in) :: remote_group
    INTEGER, INTENT(in) :: remote_leader
    CHARACTER(len=*), INTENT(in) :: stringtag
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Errhandler), INTENT(in) :: errhandler
    TYPE(MPI_Comm), INTENT(out) :: newintercomm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Group) :: local_group_c
    INTEGER(c_int) :: local_leader_c
    INTEGER(c_Group) :: remote_group_c
    INTEGER(c_int) :: remote_leader_c
    character(kind=c_char) :: stringtag_c(len_trim(stringtag) + 1)
    INTEGER(c_Info) :: info_c
    INTEGER(c_Errhandler) :: errhandler_c
    INTEGER(c_Comm) :: newintercomm_c
    INTEGER(c_int) :: ierror_c
    
    call MPIR_Fortran_string_f2c(stringtag, stringtag_c)
    
    ierror_c = MPIR_Intercomm_create_from_groups_c(local_group%MPI_VAL, local_leader, &
                                                   remote_group%MPI_VAL, remote_leader, stringtag_c, &
                                                   info%MPI_VAL, errhandler%MPI_VAL, &
                                                   newintercomm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Intercomm_create_from_groups_f08

SUBROUTINE MPI_Intercomm_merge_f08(intercomm, high, newintracomm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Intercomm_merge_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: intercomm
    LOGICAL, INTENT(in) :: high
    TYPE(MPI_Comm), INTENT(out) :: newintracomm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: intercomm_c
    INTEGER(c_int) :: high_c
    INTEGER(c_Comm) :: newintracomm_c
    INTEGER(c_int) :: ierror_c
    
    IF (high) THEN
        high_c = 1
    ELSE
        high_c = 0
    END IF
    
    ierror_c = MPIR_Intercomm_merge_c(intercomm%MPI_VAL, high_c, newintracomm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Intercomm_merge_f08

SUBROUTINE MPIX_Comm_test_threadcomm_f08(comm, flag, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Comm_test_threadcomm_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    LOGICAL, INTENT(out) :: flag
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: flag_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_test_threadcomm_c(comm%MPI_VAL, flag_c)
    
    flag = (flag_c /= 0)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Comm_test_threadcomm_f08

SUBROUTINE MPIX_Comm_revoke_f08(comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Comm_revoke_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_revoke_c(comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Comm_revoke_f08

SUBROUTINE MPIX_Comm_shrink_f08(comm, newcomm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Comm_shrink_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Comm), INTENT(out) :: newcomm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Comm) :: newcomm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_shrink_c(comm%MPI_VAL, newcomm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Comm_shrink_f08

SUBROUTINE MPIX_Comm_failure_ack_f08(comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Comm_failure_ack_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_failure_ack_c(comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Comm_failure_ack_f08

SUBROUTINE MPIX_Comm_failure_get_acked_f08(comm, failedgrp, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Group
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Group
    USE :: mpi_c_interface, ONLY : MPIR_Comm_failure_get_acked_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Group), INTENT(out) :: failedgrp
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Group) :: failedgrp_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_failure_get_acked_c(comm%MPI_VAL, failedgrp%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Comm_failure_get_acked_f08

SUBROUTINE MPIX_Comm_agree_f08(comm, flag, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Comm_agree_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    LOGICAL, INTENT(out) :: flag
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: flag_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_agree_c(comm%MPI_VAL, flag_c)
    
    flag = (flag_c /= 0)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Comm_agree_f08

SUBROUTINE MPIX_Comm_get_failed_f08(comm, failedgrp, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Group
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Group
    USE :: mpi_c_interface, ONLY : MPIR_Comm_get_failed_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Group), INTENT(out) :: failedgrp
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Group) :: failedgrp_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_get_failed_c(comm%MPI_VAL, failedgrp%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Comm_get_failed_f08

SUBROUTINE MPI_Get_address_f08ts(location, address, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface, ONLY : MPIR_Get_address_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: location
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: address
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Get_address_cdesc(location, address)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Get_address_f08ts

SUBROUTINE MPI_Get_count_f08(status, datatype, count, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_Status, assignment(=), MPI_Datatype
    USE :: mpi_c_interface_types, ONLY : c_Status, c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Get_count_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Status), INTENT(in), TARGET :: status
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(out) :: count
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: count_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Get_count_c(c_loc(status), datatype%MPI_VAL, count)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Get_count_f08

SUBROUTINE MPI_Get_count_c_f08(status, datatype, count, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_Status, assignment(=), MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Status, c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Get_count_c_large
    
    IMPLICIT NONE
    
    TYPE(MPI_Status), INTENT(in), TARGET :: status
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: count
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Get_count_c_large(c_loc(status), datatype%MPI_VAL, count)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Get_count_c_f08

SUBROUTINE MPI_Get_elements_f08(status, datatype, count, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_Status, assignment(=), MPI_Datatype
    USE :: mpi_c_interface_types, ONLY : c_Status, c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Get_elements_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Status), INTENT(in), TARGET :: status
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(out) :: count
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: count_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Get_elements_c(c_loc(status), datatype%MPI_VAL, count)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Get_elements_f08

SUBROUTINE MPI_Get_elements_c_f08(status, datatype, count, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_Status, assignment(=), MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Status, c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Get_elements_c_large
    
    IMPLICIT NONE
    
    TYPE(MPI_Status), INTENT(in), TARGET :: status
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: count
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Get_elements_c_large(c_loc(status), datatype%MPI_VAL, count)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Get_elements_c_f08

SUBROUTINE MPI_Get_elements_x_f08(status, datatype, count, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_Status, assignment(=), MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Status, c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Get_elements_x_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Status), INTENT(in), TARGET :: status
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: count
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Get_elements_x_c(c_loc(status), datatype%MPI_VAL, count)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Get_elements_x_f08

SUBROUTINE MPI_Pack_f08ts(inbuf, incount, datatype, outbuf, outsize, position, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Pack_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: inbuf
    INTEGER, INTENT(in) :: incount
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(*), DIMENSION(..) :: outbuf
    INTEGER, INTENT(in) :: outsize
    INTEGER, INTENT(inout) :: position
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: incount_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: outsize_c
    INTEGER(c_int) :: position_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Pack_cdesc(inbuf, incount, datatype%MPI_VAL, outbuf, outsize, position, &
                               comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Pack_f08ts

SUBROUTINE MPI_Pack_c_f08ts(inbuf, incount, datatype, outbuf, outsize, position, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Pack_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: inbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: incount
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(*), DIMENSION(..) :: outbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: outsize
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(inout) :: position
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Pack_cdesc_large(inbuf, incount, datatype%MPI_VAL, outbuf, outsize, position, &
                                     comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Pack_c_f08ts

SUBROUTINE MPI_Pack_external_f08ts(datarep, inbuf, incount, datatype, outbuf, outsize, position, &
                                   ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Pack_external_cdesc
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_f2c
    
    IMPLICIT NONE
    
    CHARACTER(len=*), INTENT(in) :: datarep
    TYPE(*), DIMENSION(..), INTENT(in) :: inbuf
    INTEGER, INTENT(in) :: incount
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(*), DIMENSION(..) :: outbuf
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: outsize
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(inout) :: position
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    character(kind=c_char) :: datarep_c(len_trim(datarep) + 1)
    INTEGER(c_int) :: incount_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    call MPIR_Fortran_string_f2c(datarep, datarep_c)
    
    ierror_c = MPIR_Pack_external_cdesc(datarep_c, inbuf, incount, datatype%MPI_VAL, outbuf, outsize, &
                                        position)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Pack_external_f08ts

SUBROUTINE MPI_Pack_external_c_f08ts(datarep, inbuf, incount, datatype, outbuf, outsize, position, &
                                     ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Pack_external_cdesc_large
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_f2c
    
    IMPLICIT NONE
    
    CHARACTER(len=*), INTENT(in) :: datarep
    TYPE(*), DIMENSION(..), INTENT(in) :: inbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: incount
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(*), DIMENSION(..) :: outbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: outsize
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(inout) :: position
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    character(kind=c_char) :: datarep_c(len_trim(datarep) + 1)
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    call MPIR_Fortran_string_f2c(datarep, datarep_c)
    
    ierror_c = MPIR_Pack_external_cdesc_large(datarep_c, inbuf, incount, datatype%MPI_VAL, outbuf, &
                                              outsize, position)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Pack_external_c_f08ts

SUBROUTINE MPI_Pack_external_size_f08(datarep, incount, datatype, size, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Pack_external_size_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_f2c
    
    IMPLICIT NONE
    
    CHARACTER(len=*), INTENT(in) :: datarep
    INTEGER, INTENT(in) :: incount
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: size
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    character(kind=c_char) :: datarep_c(len_trim(datarep) + 1)
    INTEGER(c_int) :: incount_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    call MPIR_Fortran_string_f2c(datarep, datarep_c)
    
    ierror_c = MPIR_Pack_external_size_c(datarep_c, incount, datatype%MPI_VAL, size)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Pack_external_size_f08

SUBROUTINE MPI_Pack_external_size_c_f08(datarep, incount, datatype, size, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Pack_external_size_c_large
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_f2c
    
    IMPLICIT NONE
    
    CHARACTER(len=*), INTENT(in) :: datarep
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: incount
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: size
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    character(kind=c_char) :: datarep_c(len_trim(datarep) + 1)
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    call MPIR_Fortran_string_f2c(datarep, datarep_c)
    
    ierror_c = MPIR_Pack_external_size_c_large(datarep_c, incount, datatype%MPI_VAL, size)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Pack_external_size_c_f08

SUBROUTINE MPI_Pack_size_f08(incount, datatype, comm, size, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Pack_size_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: incount
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(out) :: size
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: incount_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: size_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Pack_size_c(incount, datatype%MPI_VAL, comm%MPI_VAL, size)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Pack_size_f08

SUBROUTINE MPI_Pack_size_c_f08(incount, datatype, comm, size, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Pack_size_c_large
    
    IMPLICIT NONE
    
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: incount
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: size
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Pack_size_c_large(incount, datatype%MPI_VAL, comm%MPI_VAL, size)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Pack_size_c_f08

SUBROUTINE MPI_Status_set_elements_f08(status, datatype, count, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_Status, assignment(=), MPI_Datatype
    USE :: mpi_c_interface_types, ONLY : c_Status, c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Status_set_elements_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Status), INTENT(inout), TARGET :: status
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: count
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: count_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Status_set_elements_c(c_loc(status), datatype%MPI_VAL, count)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Status_set_elements_f08

SUBROUTINE MPI_Status_set_elements_c_f08(status, datatype, count, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_Status, assignment(=), MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Status, c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Status_set_elements_c_large
    
    IMPLICIT NONE
    
    TYPE(MPI_Status), INTENT(inout), TARGET :: status
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Status_set_elements_c_large(c_loc(status), datatype%MPI_VAL, count)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Status_set_elements_c_f08

SUBROUTINE MPI_Status_set_elements_x_f08(status, datatype, count, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_Status, assignment(=), MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Status, c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Status_set_elements_x_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Status), INTENT(inout), TARGET :: status
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Status_set_elements_x_c(c_loc(status), datatype%MPI_VAL, count)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Status_set_elements_x_f08

SUBROUTINE MPI_Type_commit_f08(datatype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_commit_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Datatype), INTENT(inout) :: datatype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_commit_c(datatype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_commit_f08

SUBROUTINE MPI_Type_contiguous_f08(count, oldtype, newtype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_contiguous_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: oldtype
    TYPE(MPI_Datatype), INTENT(out) :: newtype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: oldtype_c
    INTEGER(c_Datatype) :: newtype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_contiguous_c(count, oldtype%MPI_VAL, newtype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_contiguous_f08

SUBROUTINE MPI_Type_contiguous_c_f08(count, oldtype, newtype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_contiguous_c_large
    
    IMPLICIT NONE
    
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: oldtype
    TYPE(MPI_Datatype), INTENT(out) :: newtype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: oldtype_c
    INTEGER(c_Datatype) :: newtype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_contiguous_c_large(count, oldtype%MPI_VAL, newtype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_contiguous_c_f08

SUBROUTINE MPI_Type_create_darray_f08(size, rank, ndims, array_of_gsizes, array_of_distribs, &
                                      array_of_dargs, array_of_psizes, order, oldtype, newtype, &
                                      ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_create_darray_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: size
    INTEGER, INTENT(in) :: rank
    INTEGER, INTENT(in) :: ndims
    INTEGER, INTENT(in) :: array_of_gsizes(ndims)
    INTEGER, INTENT(in) :: array_of_distribs(ndims)
    INTEGER, INTENT(in) :: array_of_dargs(ndims)
    INTEGER, INTENT(in) :: array_of_psizes(ndims)
    INTEGER, INTENT(in) :: order
    TYPE(MPI_Datatype), INTENT(in) :: oldtype
    TYPE(MPI_Datatype), INTENT(out) :: newtype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: size_c
    INTEGER(c_int) :: rank_c
    INTEGER(c_int) :: ndims_c
    INTEGER(c_int) :: array_of_gsizes_c(ndims)
    INTEGER(c_int) :: array_of_distribs_c(ndims)
    INTEGER(c_int) :: array_of_dargs_c(ndims)
    INTEGER(c_int) :: array_of_psizes_c(ndims)
    INTEGER(c_int) :: order_c
    INTEGER(c_Datatype) :: oldtype_c
    INTEGER(c_Datatype) :: newtype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_create_darray_c(size, rank, ndims, array_of_gsizes, array_of_distribs, &
                                         array_of_dargs, array_of_psizes, order, oldtype%MPI_VAL, &
                                         newtype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_create_darray_f08

SUBROUTINE MPI_Type_create_darray_c_f08(size, rank, ndims, array_of_gsizes, array_of_distribs, &
                                        array_of_dargs, array_of_psizes, order, oldtype, newtype, &
                                        ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_create_darray_c_large
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: size
    INTEGER, INTENT(in) :: rank
    INTEGER, INTENT(in) :: ndims
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_gsizes(ndims)
    INTEGER, INTENT(in) :: array_of_distribs(ndims)
    INTEGER, INTENT(in) :: array_of_dargs(ndims)
    INTEGER, INTENT(in) :: array_of_psizes(ndims)
    INTEGER, INTENT(in) :: order
    TYPE(MPI_Datatype), INTENT(in) :: oldtype
    TYPE(MPI_Datatype), INTENT(out) :: newtype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: size_c
    INTEGER(c_int) :: rank_c
    INTEGER(c_int) :: ndims_c
    INTEGER(c_int) :: array_of_distribs_c(ndims)
    INTEGER(c_int) :: array_of_dargs_c(ndims)
    INTEGER(c_int) :: array_of_psizes_c(ndims)
    INTEGER(c_int) :: order_c
    INTEGER(c_Datatype) :: oldtype_c
    INTEGER(c_Datatype) :: newtype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_create_darray_c_large(size, rank, ndims, array_of_gsizes, array_of_distribs, &
                                               array_of_dargs, array_of_psizes, order, oldtype%MPI_VAL, &
                                               newtype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_create_darray_c_f08

SUBROUTINE MPI_Type_create_f90_complex_f08(p, r, newtype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_create_f90_complex_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: p
    INTEGER, INTENT(in) :: r
    TYPE(MPI_Datatype), INTENT(out) :: newtype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: p_c
    INTEGER(c_int) :: r_c
    INTEGER(c_Datatype) :: newtype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_create_f90_complex_c(p, r, newtype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_create_f90_complex_f08

SUBROUTINE MPI_Type_create_f90_integer_f08(r, newtype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_create_f90_integer_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: r
    TYPE(MPI_Datatype), INTENT(out) :: newtype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: r_c
    INTEGER(c_Datatype) :: newtype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_create_f90_integer_c(r, newtype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_create_f90_integer_f08

SUBROUTINE MPI_Type_create_f90_real_f08(p, r, newtype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_create_f90_real_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: p
    INTEGER, INTENT(in) :: r
    TYPE(MPI_Datatype), INTENT(out) :: newtype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: p_c
    INTEGER(c_int) :: r_c
    INTEGER(c_Datatype) :: newtype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_create_f90_real_c(p, r, newtype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_create_f90_real_f08

SUBROUTINE MPI_Type_create_hindexed_f08(count, array_of_blocklengths, array_of_displacements, &
                                        oldtype, newtype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_create_hindexed_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: count
    INTEGER, INTENT(in) :: array_of_blocklengths(count)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: array_of_displacements(count)
    TYPE(MPI_Datatype), INTENT(in) :: oldtype
    TYPE(MPI_Datatype), INTENT(out) :: newtype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_int) :: array_of_blocklengths_c(count)
    INTEGER(c_Datatype) :: oldtype_c
    INTEGER(c_Datatype) :: newtype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_create_hindexed_c(count, array_of_blocklengths, array_of_displacements, &
                                           oldtype%MPI_VAL, newtype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_create_hindexed_f08

SUBROUTINE MPI_Type_create_hindexed_c_f08(count, array_of_blocklengths, array_of_displacements, &
                                          oldtype, newtype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_create_hindexed_c_large
    
    IMPLICIT NONE
    
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_blocklengths(count)
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_displacements(count)
    TYPE(MPI_Datatype), INTENT(in) :: oldtype
    TYPE(MPI_Datatype), INTENT(out) :: newtype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: oldtype_c
    INTEGER(c_Datatype) :: newtype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_create_hindexed_c_large(count, array_of_blocklengths, array_of_displacements, &
                                                 oldtype%MPI_VAL, newtype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_create_hindexed_c_f08

SUBROUTINE MPI_Type_create_hindexed_block_f08(count, blocklength, array_of_displacements, oldtype, &
                                              newtype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_create_hindexed_block_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: count
    INTEGER, INTENT(in) :: blocklength
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: array_of_displacements(count)
    TYPE(MPI_Datatype), INTENT(in) :: oldtype
    TYPE(MPI_Datatype), INTENT(out) :: newtype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_int) :: blocklength_c
    INTEGER(c_Datatype) :: oldtype_c
    INTEGER(c_Datatype) :: newtype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_create_hindexed_block_c(count, blocklength, array_of_displacements, &
                                                 oldtype%MPI_VAL, newtype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_create_hindexed_block_f08

SUBROUTINE MPI_Type_create_hindexed_block_c_f08(count, blocklength, array_of_displacements, oldtype, &
                                                newtype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_create_hindexed_block_c_large
    
    IMPLICIT NONE
    
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: blocklength
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_displacements(count)
    TYPE(MPI_Datatype), INTENT(in) :: oldtype
    TYPE(MPI_Datatype), INTENT(out) :: newtype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: oldtype_c
    INTEGER(c_Datatype) :: newtype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_create_hindexed_block_c_large(count, blocklength, array_of_displacements, &
                                                       oldtype%MPI_VAL, newtype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_create_hindexed_block_c_f08

SUBROUTINE MPI_Type_create_hvector_f08(count, blocklength, stride, oldtype, newtype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_create_hvector_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: count
    INTEGER, INTENT(in) :: blocklength
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: stride
    TYPE(MPI_Datatype), INTENT(in) :: oldtype
    TYPE(MPI_Datatype), INTENT(out) :: newtype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_int) :: blocklength_c
    INTEGER(c_Datatype) :: oldtype_c
    INTEGER(c_Datatype) :: newtype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_create_hvector_c(count, blocklength, stride, oldtype%MPI_VAL, newtype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_create_hvector_f08

SUBROUTINE MPI_Type_create_hvector_c_f08(count, blocklength, stride, oldtype, newtype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_create_hvector_c_large
    
    IMPLICIT NONE
    
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: blocklength
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: stride
    TYPE(MPI_Datatype), INTENT(in) :: oldtype
    TYPE(MPI_Datatype), INTENT(out) :: newtype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: oldtype_c
    INTEGER(c_Datatype) :: newtype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_create_hvector_c_large(count, blocklength, stride, oldtype%MPI_VAL, &
                                                newtype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_create_hvector_c_f08

SUBROUTINE MPI_Type_create_indexed_block_f08(count, blocklength, array_of_displacements, oldtype, &
                                             newtype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_create_indexed_block_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: count
    INTEGER, INTENT(in) :: blocklength
    INTEGER, INTENT(in) :: array_of_displacements(count)
    TYPE(MPI_Datatype), INTENT(in) :: oldtype
    TYPE(MPI_Datatype), INTENT(out) :: newtype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_int) :: blocklength_c
    INTEGER(c_int) :: array_of_displacements_c(count)
    INTEGER(c_Datatype) :: oldtype_c
    INTEGER(c_Datatype) :: newtype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_create_indexed_block_c(count, blocklength, array_of_displacements, &
                                                oldtype%MPI_VAL, newtype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_create_indexed_block_f08

SUBROUTINE MPI_Type_create_indexed_block_c_f08(count, blocklength, array_of_displacements, oldtype, &
                                               newtype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_create_indexed_block_c_large
    
    IMPLICIT NONE
    
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: blocklength
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_displacements(count)
    TYPE(MPI_Datatype), INTENT(in) :: oldtype
    TYPE(MPI_Datatype), INTENT(out) :: newtype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: oldtype_c
    INTEGER(c_Datatype) :: newtype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_create_indexed_block_c_large(count, blocklength, array_of_displacements, &
                                                      oldtype%MPI_VAL, newtype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_create_indexed_block_c_f08

SUBROUTINE MPI_Type_create_resized_f08(oldtype, lb, extent, newtype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_create_resized_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Datatype), INTENT(in) :: oldtype
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: lb
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: extent
    TYPE(MPI_Datatype), INTENT(out) :: newtype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: oldtype_c
    INTEGER(c_Datatype) :: newtype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_create_resized_c(oldtype%MPI_VAL, lb, extent, newtype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_create_resized_f08

SUBROUTINE MPI_Type_create_struct_f08(count, array_of_blocklengths, array_of_displacements, &
                                      array_of_types, newtype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_create_struct_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: count
    INTEGER, INTENT(in) :: array_of_blocklengths(count)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: array_of_displacements(count)
    TYPE(MPI_Datatype), INTENT(in) :: array_of_types(count)
    TYPE(MPI_Datatype), INTENT(out) :: newtype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_int) :: array_of_blocklengths_c(count)
    INTEGER(c_Datatype) :: array_of_types_c(count)
    INTEGER(c_Datatype) :: newtype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_create_struct_c(count, array_of_blocklengths, array_of_displacements, &
                                         array_of_types%MPI_VAL, newtype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_create_struct_f08

SUBROUTINE MPI_Type_create_struct_c_f08(count, array_of_blocklengths, array_of_displacements, &
                                        array_of_types, newtype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_create_struct_c_large
    
    IMPLICIT NONE
    
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_blocklengths(count)
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_displacements(count)
    TYPE(MPI_Datatype), INTENT(in) :: array_of_types(count)
    TYPE(MPI_Datatype), INTENT(out) :: newtype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: array_of_types_c(count)
    INTEGER(c_Datatype) :: newtype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_create_struct_c_large(count, array_of_blocklengths, array_of_displacements, &
                                               array_of_types%MPI_VAL, newtype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_create_struct_c_f08

SUBROUTINE MPI_Type_create_subarray_f08(ndims, array_of_sizes, array_of_subsizes, array_of_starts, &
                                        order, oldtype, newtype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_create_subarray_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: ndims
    INTEGER, INTENT(in) :: array_of_sizes(ndims)
    INTEGER, INTENT(in) :: array_of_subsizes(ndims)
    INTEGER, INTENT(in) :: array_of_starts(ndims)
    INTEGER, INTENT(in) :: order
    TYPE(MPI_Datatype), INTENT(in) :: oldtype
    TYPE(MPI_Datatype), INTENT(out) :: newtype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: ndims_c
    INTEGER(c_int) :: array_of_sizes_c(ndims)
    INTEGER(c_int) :: array_of_subsizes_c(ndims)
    INTEGER(c_int) :: array_of_starts_c(ndims)
    INTEGER(c_int) :: order_c
    INTEGER(c_Datatype) :: oldtype_c
    INTEGER(c_Datatype) :: newtype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_create_subarray_c(ndims, array_of_sizes, array_of_subsizes, array_of_starts, &
                                           order, oldtype%MPI_VAL, newtype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_create_subarray_f08

SUBROUTINE MPI_Type_create_subarray_c_f08(ndims, array_of_sizes, array_of_subsizes, array_of_starts, &
                                          order, oldtype, newtype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_create_subarray_c_large
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: ndims
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_sizes(ndims)
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_subsizes(ndims)
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_starts(ndims)
    INTEGER, INTENT(in) :: order
    TYPE(MPI_Datatype), INTENT(in) :: oldtype
    TYPE(MPI_Datatype), INTENT(out) :: newtype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: ndims_c
    INTEGER(c_int) :: order_c
    INTEGER(c_Datatype) :: oldtype_c
    INTEGER(c_Datatype) :: newtype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_create_subarray_c_large(ndims, array_of_sizes, array_of_subsizes, &
                                                 array_of_starts, order, oldtype%MPI_VAL, &
                                                 newtype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_create_subarray_c_f08

SUBROUTINE MPI_Type_dup_f08(oldtype, newtype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_dup_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Datatype), INTENT(in) :: oldtype
    TYPE(MPI_Datatype), INTENT(out) :: newtype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: oldtype_c
    INTEGER(c_Datatype) :: newtype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_dup_c(oldtype%MPI_VAL, newtype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_dup_f08

SUBROUTINE MPI_Type_free_f08(datatype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_free_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Datatype), INTENT(inout) :: datatype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_free_c(datatype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_free_f08

SUBROUTINE MPI_Type_get_contents_f08(datatype, max_integers, max_addresses, max_datatypes, &
                                     array_of_integers, array_of_addresses, array_of_datatypes, &
                                     ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_get_contents_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: max_integers
    INTEGER, INTENT(in) :: max_addresses
    INTEGER, INTENT(in) :: max_datatypes
    INTEGER, INTENT(out) :: array_of_integers(max_integers)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: array_of_addresses(max_addresses)
    TYPE(MPI_Datatype), INTENT(out) :: array_of_datatypes(max_datatypes)
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: max_integers_c
    INTEGER(c_int) :: max_addresses_c
    INTEGER(c_int) :: max_datatypes_c
    INTEGER(c_int) :: array_of_integers_c(max_integers)
    INTEGER(c_Datatype) :: array_of_datatypes_c(max_datatypes)
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_get_contents_c(datatype%MPI_VAL, max_integers, max_addresses, max_datatypes, &
                                        array_of_integers, array_of_addresses, &
                                        array_of_datatypes%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_get_contents_f08

SUBROUTINE MPI_Type_get_contents_c_f08(datatype, max_integers, max_addresses, max_large_counts, &
                                       max_datatypes, array_of_integers, array_of_addresses, &
                                       array_of_large_counts, array_of_datatypes, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_get_contents_c_large
    
    IMPLICIT NONE
    
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: max_integers
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: max_addresses
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: max_large_counts
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: max_datatypes
    INTEGER, INTENT(out) :: array_of_integers(max_integers)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: array_of_addresses(max_addresses)
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: array_of_large_counts(max_large_counts)
    TYPE(MPI_Datatype), INTENT(out) :: array_of_datatypes(max_datatypes)
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: array_of_integers_c(max_integers)
    INTEGER(c_Datatype) :: array_of_datatypes_c(max_datatypes)
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_get_contents_c_large(datatype%MPI_VAL, max_integers, max_addresses, &
                                              max_large_counts, max_datatypes, array_of_integers, &
                                              array_of_addresses, array_of_large_counts, &
                                              array_of_datatypes%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_get_contents_c_f08

SUBROUTINE MPI_Type_get_envelope_f08(datatype, num_integers, num_addresses, num_datatypes, combiner, &
                                     ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_get_envelope_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(out) :: num_integers
    INTEGER, INTENT(out) :: num_addresses
    INTEGER, INTENT(out) :: num_datatypes
    INTEGER, INTENT(out) :: combiner
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: num_integers_c
    INTEGER(c_int) :: num_addresses_c
    INTEGER(c_int) :: num_datatypes_c
    INTEGER(c_int) :: combiner_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_get_envelope_c(datatype%MPI_VAL, num_integers, num_addresses, num_datatypes, &
                                        combiner)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_get_envelope_f08

SUBROUTINE MPI_Type_get_envelope_c_f08(datatype, num_integers, num_addresses, num_large_counts, &
                                       num_datatypes, combiner, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_get_envelope_c_large
    
    IMPLICIT NONE
    
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: num_integers
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: num_addresses
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: num_large_counts
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: num_datatypes
    INTEGER, INTENT(out) :: combiner
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: combiner_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_get_envelope_c_large(datatype%MPI_VAL, num_integers, num_addresses, &
                                              num_large_counts, num_datatypes, combiner)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_get_envelope_c_f08

SUBROUTINE MPI_Type_get_extent_f08(datatype, lb, extent, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_get_extent_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: lb
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: extent
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_get_extent_c(datatype%MPI_VAL, lb, extent)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_get_extent_f08

SUBROUTINE MPI_Type_get_extent_x_f08(datatype, lb, extent, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_get_extent_x_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: lb
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: extent
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_get_extent_x_c(datatype%MPI_VAL, lb, extent)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_get_extent_x_f08

SUBROUTINE MPI_Type_get_name_f08(datatype, type_name, resultlen, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_MAX_OBJECT_NAME
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_get_name_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_c2f
    
    IMPLICIT NONE
    
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    CHARACTER(len=MPI_MAX_OBJECT_NAME), INTENT(out) :: type_name
    INTEGER, INTENT(out) :: resultlen
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    character(kind=c_char) :: type_name_c(MPI_MAX_OBJECT_NAME + 1)
    INTEGER(c_int) :: resultlen_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_get_name_c(datatype%MPI_VAL, type_name_c, resultlen)
    
    call MPIR_Fortran_string_c2f(type_name_c, type_name)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_get_name_f08

SUBROUTINE MPI_Type_get_true_extent_f08(datatype, true_lb, true_extent, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_get_true_extent_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: true_lb
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: true_extent
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_get_true_extent_c(datatype%MPI_VAL, true_lb, true_extent)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_get_true_extent_f08

SUBROUTINE MPI_Type_get_true_extent_x_f08(datatype, true_lb, true_extent, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_get_true_extent_x_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: true_lb
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: true_extent
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_get_true_extent_x_c(datatype%MPI_VAL, true_lb, true_extent)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_get_true_extent_x_f08

SUBROUTINE MPI_Type_get_value_index_f08(value_type, index_type, pair_type, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_get_value_index_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Datatype), INTENT(in) :: value_type
    TYPE(MPI_Datatype), INTENT(in) :: index_type
    TYPE(MPI_Datatype), INTENT(out) :: pair_type
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: value_type_c
    INTEGER(c_Datatype) :: index_type_c
    INTEGER(c_Datatype) :: pair_type_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_get_value_index_c(value_type%MPI_VAL, index_type%MPI_VAL, pair_type%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_get_value_index_f08

SUBROUTINE MPI_Type_indexed_f08(count, array_of_blocklengths, array_of_displacements, oldtype, &
                                newtype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_indexed_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: count
    INTEGER, INTENT(in) :: array_of_blocklengths(count)
    INTEGER, INTENT(in) :: array_of_displacements(count)
    TYPE(MPI_Datatype), INTENT(in) :: oldtype
    TYPE(MPI_Datatype), INTENT(out) :: newtype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_int) :: array_of_blocklengths_c(count)
    INTEGER(c_int) :: array_of_displacements_c(count)
    INTEGER(c_Datatype) :: oldtype_c
    INTEGER(c_Datatype) :: newtype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_indexed_c(count, array_of_blocklengths, array_of_displacements, &
                                   oldtype%MPI_VAL, newtype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_indexed_f08

SUBROUTINE MPI_Type_indexed_c_f08(count, array_of_blocklengths, array_of_displacements, oldtype, &
                                  newtype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_indexed_c_large
    
    IMPLICIT NONE
    
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_blocklengths(count)
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_displacements(count)
    TYPE(MPI_Datatype), INTENT(in) :: oldtype
    TYPE(MPI_Datatype), INTENT(out) :: newtype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: oldtype_c
    INTEGER(c_Datatype) :: newtype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_indexed_c_large(count, array_of_blocklengths, array_of_displacements, &
                                         oldtype%MPI_VAL, newtype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_indexed_c_f08

SUBROUTINE MPI_Type_match_size_f08(typeclass, size, datatype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_match_size_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: typeclass
    INTEGER, INTENT(in) :: size
    TYPE(MPI_Datatype), INTENT(out) :: datatype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: typeclass_c
    INTEGER(c_int) :: size_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_match_size_c(typeclass, size, datatype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_match_size_f08

SUBROUTINE MPI_Type_set_name_f08(datatype, type_name, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_set_name_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_f2c
    
    IMPLICIT NONE
    
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    CHARACTER(len=*), INTENT(in) :: type_name
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    character(kind=c_char) :: type_name_c(len_trim(type_name) + 1)
    INTEGER(c_int) :: ierror_c
    
    call MPIR_Fortran_string_f2c(type_name, type_name_c)
    
    ierror_c = MPIR_Type_set_name_c(datatype%MPI_VAL, type_name_c)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_set_name_f08

SUBROUTINE MPI_Type_size_f08(datatype, size, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_size_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(out) :: size
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: size_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_size_c(datatype%MPI_VAL, size)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_size_f08

SUBROUTINE MPI_Type_size_c_f08(datatype, size, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_size_c_large
    
    IMPLICIT NONE
    
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: size
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_size_c_large(datatype%MPI_VAL, size)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_size_c_f08

SUBROUTINE MPI_Type_size_x_f08(datatype, size, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_size_x_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: size
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_size_x_c(datatype%MPI_VAL, size)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_size_x_f08

SUBROUTINE MPI_Type_vector_f08(count, blocklength, stride, oldtype, newtype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_vector_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: count
    INTEGER, INTENT(in) :: blocklength
    INTEGER, INTENT(in) :: stride
    TYPE(MPI_Datatype), INTENT(in) :: oldtype
    TYPE(MPI_Datatype), INTENT(out) :: newtype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_int) :: blocklength_c
    INTEGER(c_int) :: stride_c
    INTEGER(c_Datatype) :: oldtype_c
    INTEGER(c_Datatype) :: newtype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_vector_c(count, blocklength, stride, oldtype%MPI_VAL, newtype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_vector_f08

SUBROUTINE MPI_Type_vector_c_f08(count, blocklength, stride, oldtype, newtype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Type_vector_c_large
    
    IMPLICIT NONE
    
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: blocklength
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: stride
    TYPE(MPI_Datatype), INTENT(in) :: oldtype
    TYPE(MPI_Datatype), INTENT(out) :: newtype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: oldtype_c
    INTEGER(c_Datatype) :: newtype_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Type_vector_c_large(count, blocklength, stride, oldtype%MPI_VAL, newtype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Type_vector_c_f08

SUBROUTINE MPI_Unpack_f08ts(inbuf, insize, position, outbuf, outcount, datatype, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Unpack_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: inbuf
    INTEGER, INTENT(in) :: insize
    INTEGER, INTENT(inout) :: position
    TYPE(*), DIMENSION(..) :: outbuf
    INTEGER, INTENT(in) :: outcount
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: insize_c
    INTEGER(c_int) :: position_c
    INTEGER(c_int) :: outcount_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Unpack_cdesc(inbuf, insize, position, outbuf, outcount, datatype%MPI_VAL, &
                                 comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Unpack_f08ts

SUBROUTINE MPI_Unpack_c_f08ts(inbuf, insize, position, outbuf, outcount, datatype, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Unpack_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: inbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: insize
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(inout) :: position
    TYPE(*), DIMENSION(..) :: outbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: outcount
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Unpack_cdesc_large(inbuf, insize, position, outbuf, outcount, datatype%MPI_VAL, &
                                       comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Unpack_c_f08ts

SUBROUTINE MPI_Unpack_external_f08ts(datarep, inbuf, insize, position, outbuf, outcount, datatype, &
                                     ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Unpack_external_cdesc
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_f2c
    
    IMPLICIT NONE
    
    CHARACTER(len=*), INTENT(in) :: datarep
    TYPE(*), DIMENSION(..), INTENT(in) :: inbuf
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: insize
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(inout) :: position
    TYPE(*), DIMENSION(..) :: outbuf
    INTEGER, INTENT(in) :: outcount
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    character(kind=c_char) :: datarep_c(len_trim(datarep) + 1)
    INTEGER(c_int) :: outcount_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    call MPIR_Fortran_string_f2c(datarep, datarep_c)
    
    ierror_c = MPIR_Unpack_external_cdesc(datarep_c, inbuf, insize, position, outbuf, outcount, &
                                          datatype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Unpack_external_f08ts

SUBROUTINE MPI_Unpack_external_c_f08ts(datarep, inbuf, insize, position, outbuf, outcount, datatype, &
                                       ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_Unpack_external_cdesc_large
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_f2c
    
    IMPLICIT NONE
    
    CHARACTER(len=*), INTENT(in) :: datarep
    TYPE(*), DIMENSION(..), INTENT(in) :: inbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: insize
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(inout) :: position
    TYPE(*), DIMENSION(..) :: outbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: outcount
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    character(kind=c_char) :: datarep_c(len_trim(datarep) + 1)
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    call MPIR_Fortran_string_f2c(datarep, datarep_c)
    
    ierror_c = MPIR_Unpack_external_cdesc_large(datarep_c, inbuf, insize, position, outbuf, outcount, &
                                                datatype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Unpack_external_c_f08ts

SUBROUTINE MPI_Add_error_class_f08(errorclass, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface, ONLY : MPIR_Add_error_class_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(out) :: errorclass
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: errorclass_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Add_error_class_c(errorclass)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Add_error_class_f08

SUBROUTINE MPI_Add_error_code_f08(errorclass, errorcode, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface, ONLY : MPIR_Add_error_code_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: errorclass
    INTEGER, INTENT(out) :: errorcode
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: errorclass_c
    INTEGER(c_int) :: errorcode_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Add_error_code_c(errorclass, errorcode)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Add_error_code_f08

SUBROUTINE MPI_Add_error_string_f08(errorcode, string, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_c_interface, ONLY : MPIR_Add_error_string_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_f2c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: errorcode
    CHARACTER(len=*), INTENT(in) :: string
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: errorcode_c
    character(kind=c_char) :: string_c(len_trim(string) + 1)
    INTEGER(c_int) :: ierror_c
    
    call MPIR_Fortran_string_f2c(string, string_c)
    
    ierror_c = MPIR_Add_error_string_c(errorcode, string_c)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Add_error_string_f08

SUBROUTINE MPI_Comm_call_errhandler_f08(comm, errorcode, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Comm_call_errhandler_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(in) :: errorcode
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: errorcode_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_call_errhandler_c(comm%MPI_VAL, errorcode)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_call_errhandler_f08

SUBROUTINE MPI_Comm_create_errhandler_f08(comm_errhandler_fn, errhandler, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_funptr, c_funloc, c_int
    USE :: mpi_f08_types, ONLY : MPI_Errhandler
    USE :: mpi_f08_callbacks, ONLY : MPI_Comm_errhandler_function
    USE :: mpi_c_interface_types, ONLY : c_Errhandler
    USE :: mpi_c_interface, ONLY : MPII_Comm_create_errhandler_c
    
    IMPLICIT NONE
    
    PROCEDURE(MPI_Comm_errhandler_function) :: comm_errhandler_fn
    TYPE(MPI_Errhandler), INTENT(out) :: errhandler
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    TYPE(c_funptr) :: comm_errhandler_fn_c
    INTEGER(c_Errhandler) :: errhandler_c
    INTEGER(c_int) :: ierror_c
    
    comm_errhandler_fn_c = c_funloc(comm_errhandler_fn)
    
    ierror_c = MPII_Comm_create_errhandler_c(comm_errhandler_fn_c, errhandler%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_create_errhandler_f08

SUBROUTINE MPI_Comm_get_errhandler_f08(comm, errhandler, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Errhandler
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Errhandler
    USE :: mpi_c_interface, ONLY : MPIR_Comm_get_errhandler_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Errhandler), INTENT(out) :: errhandler
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Errhandler) :: errhandler_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_get_errhandler_c(comm%MPI_VAL, errhandler%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_get_errhandler_f08

SUBROUTINE MPI_Comm_set_errhandler_f08(comm, errhandler, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Errhandler
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Errhandler
    USE :: mpi_c_interface, ONLY : MPIR_Comm_set_errhandler_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Errhandler), INTENT(in) :: errhandler
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Errhandler) :: errhandler_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_set_errhandler_c(comm%MPI_VAL, errhandler%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_set_errhandler_f08

SUBROUTINE MPI_Errhandler_free_f08(errhandler, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Errhandler
    USE :: mpi_c_interface_types, ONLY : c_Errhandler
    USE :: mpi_c_interface, ONLY : MPIR_Errhandler_free_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Errhandler), INTENT(inout) :: errhandler
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Errhandler) :: errhandler_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Errhandler_free_c(errhandler%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Errhandler_free_f08

SUBROUTINE MPI_Error_class_f08(errorcode, errorclass, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface, ONLY : MPIR_Error_class_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: errorcode
    INTEGER, INTENT(out) :: errorclass
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: errorcode_c
    INTEGER(c_int) :: errorclass_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Error_class_c(errorcode, errorclass)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Error_class_f08

SUBROUTINE MPI_Error_string_f08(errorcode, string, resultlen, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_f08_compile_constants, ONLY : MPI_MAX_ERROR_STRING
    USE :: mpi_c_interface, ONLY : MPIR_Error_string_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_c2f
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: errorcode
    CHARACTER(len=MPI_MAX_ERROR_STRING), INTENT(out) :: string
    INTEGER, INTENT(out) :: resultlen
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: errorcode_c
    character(kind=c_char) :: string_c(MPI_MAX_ERROR_STRING + 1)
    INTEGER(c_int) :: resultlen_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Error_string_c(errorcode, string_c, resultlen)
    
    call MPIR_Fortran_string_c2f(string_c, string)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Error_string_f08

SUBROUTINE MPI_File_call_errhandler_f08(fh, errorcode, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c
    USE :: mpi_c_interface_types, ONLY : c_File
    USE :: mpi_c_interface, ONLY : MPIR_File_call_errhandler_c
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER, INTENT(in) :: errorcode
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: errorcode_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_call_errhandler_c(fh_c, errorcode)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_call_errhandler_f08

SUBROUTINE MPI_File_create_errhandler_f08(file_errhandler_fn, errhandler, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_funptr, c_funloc, c_int
    USE :: mpi_f08_types, ONLY : MPI_Errhandler
    USE :: mpi_f08_callbacks, ONLY : MPI_File_errhandler_function
    USE :: mpi_c_interface_types, ONLY : c_Errhandler
    USE :: mpi_c_interface, ONLY : MPII_File_create_errhandler_c
    
    IMPLICIT NONE
    
    PROCEDURE(MPI_File_errhandler_function) :: file_errhandler_fn
    TYPE(MPI_Errhandler), INTENT(out) :: errhandler
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    TYPE(c_funptr) :: file_errhandler_fn_c
    INTEGER(c_Errhandler) :: errhandler_c
    INTEGER(c_int) :: ierror_c
    
    file_errhandler_fn_c = c_funloc(file_errhandler_fn)
    
    ierror_c = MPII_File_create_errhandler_c(file_errhandler_fn_c, errhandler%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_create_errhandler_f08

SUBROUTINE MPI_File_get_errhandler_f08(file, errhandler, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Errhandler
    USE :: mpi_c_interface_types, ONLY : c_File, c_Errhandler
    USE :: mpi_c_interface, ONLY : MPIR_File_get_errhandler_c
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: file
    TYPE(MPI_Errhandler), INTENT(out) :: errhandler
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: file_c
    INTEGER(c_Errhandler) :: errhandler_c
    INTEGER(c_int) :: ierror_c
    
    file_c = MPI_File_f2c(file%MPI_VAL)
    
    ierror_c = MPIR_File_get_errhandler_c(file_c, errhandler%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_get_errhandler_f08

SUBROUTINE MPI_File_set_errhandler_f08(file, errhandler, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Errhandler
    USE :: mpi_c_interface_types, ONLY : c_File, c_Errhandler
    USE :: mpi_c_interface, ONLY : MPIR_File_set_errhandler_c
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: file
    TYPE(MPI_Errhandler), INTENT(in) :: errhandler
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: file_c
    INTEGER(c_Errhandler) :: errhandler_c
    INTEGER(c_int) :: ierror_c
    
    file_c = MPI_File_f2c(file%MPI_VAL)
    
    ierror_c = MPIR_File_set_errhandler_c(file_c, errhandler%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_set_errhandler_f08

SUBROUTINE MPI_Remove_error_class_f08(errorclass, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface, ONLY : MPIR_Remove_error_class_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: errorclass
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: errorclass_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Remove_error_class_c(errorclass)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Remove_error_class_f08

SUBROUTINE MPI_Remove_error_code_f08(errorcode, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface, ONLY : MPIR_Remove_error_code_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: errorcode
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: errorcode_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Remove_error_code_c(errorcode)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Remove_error_code_f08

SUBROUTINE MPI_Remove_error_string_f08(errorcode, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface, ONLY : MPIR_Remove_error_string_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: errorcode
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: errorcode_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Remove_error_string_c(errorcode)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Remove_error_string_f08

SUBROUTINE MPI_Session_call_errhandler_f08(session, errorcode, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Session
    USE :: mpi_c_interface_types, ONLY : c_Session
    USE :: mpi_c_interface, ONLY : MPIR_Session_call_errhandler_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Session), INTENT(in) :: session
    INTEGER, INTENT(in) :: errorcode
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Session) :: session_c
    INTEGER(c_int) :: errorcode_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Session_call_errhandler_c(session%MPI_VAL, errorcode)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Session_call_errhandler_f08

SUBROUTINE MPI_Session_create_errhandler_f08(session_errhandler_fn, errhandler, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_funptr, c_funloc, c_int
    USE :: mpi_f08_types, ONLY : MPI_Errhandler
    USE :: mpi_f08_callbacks, ONLY : MPI_Session_errhandler_function
    USE :: mpi_c_interface_types, ONLY : c_Errhandler
    USE :: mpi_c_interface, ONLY : MPIR_Session_create_errhandler_c
    
    IMPLICIT NONE
    
    PROCEDURE(MPI_Session_errhandler_function) :: session_errhandler_fn
    TYPE(MPI_Errhandler), INTENT(out) :: errhandler
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    TYPE(c_funptr) :: session_errhandler_fn_c
    INTEGER(c_Errhandler) :: errhandler_c
    INTEGER(c_int) :: ierror_c
    
    session_errhandler_fn_c = c_funloc(session_errhandler_fn)
    
    ierror_c = MPIR_Session_create_errhandler_c(session_errhandler_fn_c, errhandler%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Session_create_errhandler_f08

SUBROUTINE MPI_Session_get_errhandler_f08(session, errhandler, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Session, MPI_Errhandler
    USE :: mpi_c_interface_types, ONLY : c_Session, c_Errhandler
    USE :: mpi_c_interface, ONLY : MPIR_Session_get_errhandler_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Session), INTENT(in) :: session
    TYPE(MPI_Errhandler), INTENT(out) :: errhandler
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Session) :: session_c
    INTEGER(c_Errhandler) :: errhandler_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Session_get_errhandler_c(session%MPI_VAL, errhandler%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Session_get_errhandler_f08

SUBROUTINE MPI_Session_set_errhandler_f08(session, errhandler, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Session, MPI_Errhandler
    USE :: mpi_c_interface_types, ONLY : c_Session, c_Errhandler
    USE :: mpi_c_interface, ONLY : MPIR_Session_set_errhandler_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Session), INTENT(in) :: session
    TYPE(MPI_Errhandler), INTENT(in) :: errhandler
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Session) :: session_c
    INTEGER(c_Errhandler) :: errhandler_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Session_set_errhandler_c(session%MPI_VAL, errhandler%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Session_set_errhandler_f08

SUBROUTINE MPI_Win_call_errhandler_f08(win, errorcode, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Win
    USE :: mpi_c_interface_types, ONLY : c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_call_errhandler_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Win), INTENT(in) :: win
    INTEGER, INTENT(in) :: errorcode
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: errorcode_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_call_errhandler_c(win%MPI_VAL, errorcode)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_call_errhandler_f08

SUBROUTINE MPI_Win_create_errhandler_f08(win_errhandler_fn, errhandler, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_funptr, c_funloc, c_int
    USE :: mpi_f08_types, ONLY : MPI_Errhandler
    USE :: mpi_f08_callbacks, ONLY : MPI_Win_errhandler_function
    USE :: mpi_c_interface_types, ONLY : c_Errhandler
    USE :: mpi_c_interface, ONLY : MPII_Win_create_errhandler_c
    
    IMPLICIT NONE
    
    PROCEDURE(MPI_Win_errhandler_function) :: win_errhandler_fn
    TYPE(MPI_Errhandler), INTENT(out) :: errhandler
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    TYPE(c_funptr) :: win_errhandler_fn_c
    INTEGER(c_Errhandler) :: errhandler_c
    INTEGER(c_int) :: ierror_c
    
    win_errhandler_fn_c = c_funloc(win_errhandler_fn)
    
    ierror_c = MPII_Win_create_errhandler_c(win_errhandler_fn_c, errhandler%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_create_errhandler_f08

SUBROUTINE MPI_Win_get_errhandler_f08(win, errhandler, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Win, MPI_Errhandler
    USE :: mpi_c_interface_types, ONLY : c_Win, c_Errhandler
    USE :: mpi_c_interface, ONLY : MPIR_Win_get_errhandler_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Win), INTENT(in) :: win
    TYPE(MPI_Errhandler), INTENT(out) :: errhandler
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Win) :: win_c
    INTEGER(c_Errhandler) :: errhandler_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_get_errhandler_c(win%MPI_VAL, errhandler%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_get_errhandler_f08

SUBROUTINE MPI_Win_set_errhandler_f08(win, errhandler, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Win, MPI_Errhandler
    USE :: mpi_c_interface_types, ONLY : c_Win, c_Errhandler
    USE :: mpi_c_interface, ONLY : MPIR_Win_set_errhandler_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Win), INTENT(in) :: win
    TYPE(MPI_Errhandler), INTENT(in) :: errhandler
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Win) :: win_c
    INTEGER(c_Errhandler) :: errhandler_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_set_errhandler_c(win%MPI_VAL, errhandler%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_set_errhandler_f08

SUBROUTINE MPI_Group_compare_f08(group1, group2, result, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Group
    USE :: mpi_c_interface_types, ONLY : c_Group
    USE :: mpi_c_interface, ONLY : MPIR_Group_compare_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Group), INTENT(in) :: group1
    TYPE(MPI_Group), INTENT(in) :: group2
    INTEGER, INTENT(out) :: result
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Group) :: group1_c
    INTEGER(c_Group) :: group2_c
    INTEGER(c_int) :: result_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Group_compare_c(group1%MPI_VAL, group2%MPI_VAL, result)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Group_compare_f08

SUBROUTINE MPI_Group_difference_f08(group1, group2, newgroup, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Group
    USE :: mpi_c_interface_types, ONLY : c_Group
    USE :: mpi_c_interface, ONLY : MPIR_Group_difference_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Group), INTENT(in) :: group1
    TYPE(MPI_Group), INTENT(in) :: group2
    TYPE(MPI_Group), INTENT(out) :: newgroup
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Group) :: group1_c
    INTEGER(c_Group) :: group2_c
    INTEGER(c_Group) :: newgroup_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Group_difference_c(group1%MPI_VAL, group2%MPI_VAL, newgroup%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Group_difference_f08

SUBROUTINE MPI_Group_excl_f08(group, n, ranks, newgroup, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Group
    USE :: mpi_c_interface_types, ONLY : c_Group
    USE :: mpi_c_interface, ONLY : MPIR_Group_excl_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Group), INTENT(in) :: group
    INTEGER, INTENT(in) :: n
    INTEGER, INTENT(in) :: ranks(n)
    TYPE(MPI_Group), INTENT(out) :: newgroup
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Group) :: group_c
    INTEGER(c_int) :: n_c
    INTEGER(c_int) :: ranks_c(n)
    INTEGER(c_Group) :: newgroup_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Group_excl_c(group%MPI_VAL, n, ranks, newgroup%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Group_excl_f08

SUBROUTINE MPI_Group_free_f08(group, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Group
    USE :: mpi_c_interface_types, ONLY : c_Group
    USE :: mpi_c_interface, ONLY : MPIR_Group_free_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Group), INTENT(inout) :: group
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Group) :: group_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Group_free_c(group%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Group_free_f08

SUBROUTINE MPI_Group_incl_f08(group, n, ranks, newgroup, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Group
    USE :: mpi_c_interface_types, ONLY : c_Group
    USE :: mpi_c_interface, ONLY : MPIR_Group_incl_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Group), INTENT(in) :: group
    INTEGER, INTENT(in) :: n
    INTEGER, INTENT(in) :: ranks(n)
    TYPE(MPI_Group), INTENT(out) :: newgroup
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Group) :: group_c
    INTEGER(c_int) :: n_c
    INTEGER(c_int) :: ranks_c(n)
    INTEGER(c_Group) :: newgroup_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Group_incl_c(group%MPI_VAL, n, ranks, newgroup%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Group_incl_f08

SUBROUTINE MPI_Group_intersection_f08(group1, group2, newgroup, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Group
    USE :: mpi_c_interface_types, ONLY : c_Group
    USE :: mpi_c_interface, ONLY : MPIR_Group_intersection_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Group), INTENT(in) :: group1
    TYPE(MPI_Group), INTENT(in) :: group2
    TYPE(MPI_Group), INTENT(out) :: newgroup
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Group) :: group1_c
    INTEGER(c_Group) :: group2_c
    INTEGER(c_Group) :: newgroup_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Group_intersection_c(group1%MPI_VAL, group2%MPI_VAL, newgroup%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Group_intersection_f08

SUBROUTINE MPI_Group_range_excl_f08(group, n, ranges, newgroup, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Group
    USE :: mpi_c_interface_types, ONLY : c_Group
    USE :: mpi_c_interface, ONLY : MPIR_Group_range_excl_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Group), INTENT(in) :: group
    INTEGER, INTENT(in) :: n
    INTEGER, INTENT(in) :: ranges(n, 3)
    TYPE(MPI_Group), INTENT(out) :: newgroup
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Group) :: group_c
    INTEGER(c_int) :: n_c
    INTEGER(c_int) :: ranges_c(n, 3)
    INTEGER(c_Group) :: newgroup_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Group_range_excl_c(group%MPI_VAL, n, ranges, newgroup%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Group_range_excl_f08

SUBROUTINE MPI_Group_range_incl_f08(group, n, ranges, newgroup, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Group
    USE :: mpi_c_interface_types, ONLY : c_Group
    USE :: mpi_c_interface, ONLY : MPIR_Group_range_incl_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Group), INTENT(in) :: group
    INTEGER, INTENT(in) :: n
    INTEGER, INTENT(in) :: ranges(n, 3)
    TYPE(MPI_Group), INTENT(out) :: newgroup
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Group) :: group_c
    INTEGER(c_int) :: n_c
    INTEGER(c_int) :: ranges_c(n, 3)
    INTEGER(c_Group) :: newgroup_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Group_range_incl_c(group%MPI_VAL, n, ranges, newgroup%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Group_range_incl_f08

SUBROUTINE MPI_Group_rank_f08(group, rank, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Group
    USE :: mpi_c_interface_types, ONLY : c_Group
    USE :: mpi_c_interface, ONLY : MPIR_Group_rank_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Group), INTENT(in) :: group
    INTEGER, INTENT(out) :: rank
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Group) :: group_c
    INTEGER(c_int) :: rank_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Group_rank_c(group%MPI_VAL, rank)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Group_rank_f08

SUBROUTINE MPI_Group_size_f08(group, size, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Group
    USE :: mpi_c_interface_types, ONLY : c_Group
    USE :: mpi_c_interface, ONLY : MPIR_Group_size_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Group), INTENT(in) :: group
    INTEGER, INTENT(out) :: size
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Group) :: group_c
    INTEGER(c_int) :: size_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Group_size_c(group%MPI_VAL, size)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Group_size_f08

SUBROUTINE MPI_Group_translate_ranks_f08(group1, n, ranks1, group2, ranks2, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Group
    USE :: mpi_c_interface_types, ONLY : c_Group
    USE :: mpi_c_interface, ONLY : MPIR_Group_translate_ranks_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Group), INTENT(in) :: group1
    INTEGER, INTENT(in) :: n
    INTEGER, INTENT(in) :: ranks1(n)
    TYPE(MPI_Group), INTENT(in) :: group2
    INTEGER, INTENT(out) :: ranks2(n)
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Group) :: group1_c
    INTEGER(c_int) :: n_c
    INTEGER(c_int) :: ranks1_c(n)
    INTEGER(c_Group) :: group2_c
    INTEGER(c_int) :: ranks2_c(n)
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Group_translate_ranks_c(group1%MPI_VAL, n, ranks1, group2%MPI_VAL, ranks2)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Group_translate_ranks_f08

SUBROUTINE MPI_Group_union_f08(group1, group2, newgroup, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Group
    USE :: mpi_c_interface_types, ONLY : c_Group
    USE :: mpi_c_interface, ONLY : MPIR_Group_union_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Group), INTENT(in) :: group1
    TYPE(MPI_Group), INTENT(in) :: group2
    TYPE(MPI_Group), INTENT(out) :: newgroup
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Group) :: group1_c
    INTEGER(c_Group) :: group2_c
    INTEGER(c_Group) :: newgroup_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Group_union_c(group1%MPI_VAL, group2%MPI_VAL, newgroup%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Group_union_f08

SUBROUTINE MPI_Info_create_f08(info, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Info
    USE :: mpi_c_interface_types, ONLY : c_Info
    USE :: mpi_c_interface, ONLY : MPIR_Info_create_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Info), INTENT(out) :: info
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Info) :: info_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Info_create_c(info%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Info_create_f08

SUBROUTINE MPI_Info_create_env_f08(info, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Info
    USE :: mpi_c_interface_types, ONLY : c_Info
    USE :: mpi_c_interface, ONLY : MPIR_Info_create_env_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Info), INTENT(out) :: info
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Info) :: info_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Info_create_env_c(info%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Info_create_env_f08

SUBROUTINE MPI_Info_delete_f08(info, key, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_types, ONLY : MPI_Info
    USE :: mpi_c_interface_types, ONLY : c_Info
    USE :: mpi_c_interface, ONLY : MPIR_Info_delete_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_f2c
    
    IMPLICIT NONE
    
    TYPE(MPI_Info), INTENT(in) :: info
    CHARACTER(len=*), INTENT(in) :: key
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Info) :: info_c
    character(kind=c_char) :: key_c(len_trim(key) + 1)
    INTEGER(c_int) :: ierror_c
    
    call MPIR_Fortran_string_f2c(key, key_c)
    
    ierror_c = MPIR_Info_delete_c(info%MPI_VAL, key_c)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Info_delete_f08

SUBROUTINE MPI_Info_dup_f08(info, newinfo, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Info
    USE :: mpi_c_interface_types, ONLY : c_Info
    USE :: mpi_c_interface, ONLY : MPIR_Info_dup_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Info), INTENT(out) :: newinfo
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Info) :: info_c
    INTEGER(c_Info) :: newinfo_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Info_dup_c(info%MPI_VAL, newinfo%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Info_dup_f08

SUBROUTINE MPI_Info_free_f08(info, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Info
    USE :: mpi_c_interface_types, ONLY : c_Info
    USE :: mpi_c_interface, ONLY : MPIR_Info_free_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Info), INTENT(inout) :: info
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Info) :: info_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Info_free_c(info%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Info_free_f08

SUBROUTINE MPI_Info_get_f08(info, key, valuelen, value, flag, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_types, ONLY : MPI_Info
    USE :: mpi_c_interface_types, ONLY : c_Info
    USE :: mpi_c_interface, ONLY : MPIR_Info_get_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_f2c, MPIR_Fortran_string_c2f
    
    IMPLICIT NONE
    
    TYPE(MPI_Info), INTENT(in) :: info
    CHARACTER(len=*), INTENT(in) :: key
    INTEGER, INTENT(in) :: valuelen
    CHARACTER(len=valuelen), INTENT(out) :: value
    LOGICAL, INTENT(out) :: flag
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Info) :: info_c
    character(kind=c_char) :: key_c(len_trim(key) + 1)
    INTEGER(c_int) :: valuelen_c
    character(kind=c_char) :: value_c(valuelen + 1)
    INTEGER(c_int) :: flag_c
    INTEGER(c_int) :: ierror_c
    
    call MPIR_Fortran_string_f2c(key, key_c)
    
    ierror_c = MPIR_Info_get_c(info%MPI_VAL, key_c, valuelen, value_c, flag_c)
    
    IF (flag_c /= 0) THEN
        call MPIR_Fortran_string_c2f(value_c, value)
    END IF
    flag = (flag_c /= 0)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Info_get_f08

SUBROUTINE MPI_Info_get_nkeys_f08(info, nkeys, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Info
    USE :: mpi_c_interface_types, ONLY : c_Info
    USE :: mpi_c_interface, ONLY : MPIR_Info_get_nkeys_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Info), INTENT(in) :: info
    INTEGER, INTENT(out) :: nkeys
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Info) :: info_c
    INTEGER(c_int) :: nkeys_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Info_get_nkeys_c(info%MPI_VAL, nkeys)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Info_get_nkeys_f08

SUBROUTINE MPI_Info_get_nthkey_f08(info, n, key, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_f08_types, ONLY : MPI_Info
    USE :: mpi_c_interface_types, ONLY : c_Info
    USE :: mpi_c_interface, ONLY : MPIR_Info_get_nthkey_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_c2f
    
    IMPLICIT NONE
    
    TYPE(MPI_Info), INTENT(in) :: info
    INTEGER, INTENT(in) :: n
    CHARACTER(len=*), INTENT(out) :: key
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Info) :: info_c
    INTEGER(c_int) :: n_c
    character(kind=c_char) :: key_c(len(key) + 1)
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Info_get_nthkey_c(info%MPI_VAL, n, key_c)
    
    call MPIR_Fortran_string_c2f(key_c, key)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Info_get_nthkey_f08

SUBROUTINE MPI_Info_get_string_f08(info, key, buflen, value, flag, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_types, ONLY : MPI_Info
    USE :: mpi_c_interface_types, ONLY : c_Info
    USE :: mpi_c_interface, ONLY : MPIR_Info_get_string_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_f2c, MPIR_Fortran_string_c2f
    
    IMPLICIT NONE
    
    TYPE(MPI_Info), INTENT(in) :: info
    CHARACTER(len=*), INTENT(in) :: key
    INTEGER, INTENT(inout) :: buflen
    CHARACTER(len=*), INTENT(out) :: value
    LOGICAL, INTENT(out) :: flag
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Info) :: info_c
    character(kind=c_char) :: key_c(len_trim(key) + 1)
    INTEGER(c_int) :: buflen_c
    character(kind=c_char) :: value_c(buflen + 1)
    INTEGER(c_int) :: flag_c
    INTEGER(c_int) :: ierror_c
    
    call MPIR_Fortran_string_f2c(key, key_c)
    IF (buflen > 0) THEN
        buflen_c = buflen + 1
    ELSE
        buflen_c = 0
    END IF
    
    ierror_c = MPIR_Info_get_string_c(info%MPI_VAL, key_c, buflen_c, value_c, flag_c)
    
    IF (flag_c /= 0) THEN
        IF (buflen /= 0) THEN
            call MPIR_Fortran_string_c2f(value_c, value)
        END IF
        buflen = buflen_c - 1
    END IF
    flag = (flag_c /= 0)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Info_get_string_f08

SUBROUTINE MPI_Info_get_valuelen_f08(info, key, valuelen, flag, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_types, ONLY : MPI_Info
    USE :: mpi_c_interface_types, ONLY : c_Info
    USE :: mpi_c_interface, ONLY : MPIR_Info_get_valuelen_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_f2c
    
    IMPLICIT NONE
    
    TYPE(MPI_Info), INTENT(in) :: info
    CHARACTER(len=*), INTENT(in) :: key
    INTEGER, INTENT(out) :: valuelen
    LOGICAL, INTENT(out) :: flag
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Info) :: info_c
    character(kind=c_char) :: key_c(len_trim(key) + 1)
    INTEGER(c_int) :: valuelen_c
    INTEGER(c_int) :: flag_c
    INTEGER(c_int) :: ierror_c
    
    call MPIR_Fortran_string_f2c(key, key_c)
    
    ierror_c = MPIR_Info_get_valuelen_c(info%MPI_VAL, key_c, valuelen, flag_c)
    
    flag = (flag_c /= 0)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Info_get_valuelen_f08

SUBROUTINE MPI_Info_set_f08(info, key, value, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_types, ONLY : MPI_Info
    USE :: mpi_c_interface_types, ONLY : c_Info
    USE :: mpi_c_interface, ONLY : MPIR_Info_set_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_f2c
    
    IMPLICIT NONE
    
    TYPE(MPI_Info), INTENT(in) :: info
    CHARACTER(len=*), INTENT(in) :: key
    CHARACTER(len=*), INTENT(in) :: value
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Info) :: info_c
    character(kind=c_char) :: key_c(len_trim(key) + 1)
    character(kind=c_char) :: value_c(len_trim(value) + 1)
    INTEGER(c_int) :: ierror_c
    
    call MPIR_Fortran_string_f2c(key, key_c)
    call MPIR_Fortran_string_f2c(value, value_c)
    
    ierror_c = MPIR_Info_set_c(info%MPI_VAL, key_c, value_c)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Info_set_f08

SUBROUTINE MPIX_Info_set_hex_f08ts(info, key, value, value_size, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_types, ONLY : MPI_Info
    USE :: mpi_c_interface_types, ONLY : c_Info
    USE :: mpi_c_interface, ONLY : MPIR_Info_set_hex_cdesc
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_f2c
    
    IMPLICIT NONE
    
    TYPE(MPI_Info), INTENT(in) :: info
    CHARACTER(len=*), INTENT(in) :: key
    TYPE(*), DIMENSION(..), INTENT(in) :: value
    INTEGER, INTENT(in) :: value_size
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Info) :: info_c
    character(kind=c_char) :: key_c(len_trim(key) + 1)
    INTEGER(c_int) :: value_size_c
    INTEGER(c_int) :: ierror_c
    
    call MPIR_Fortran_string_f2c(key, key_c)
    
    ierror_c = MPIR_Info_set_hex_cdesc(info%MPI_VAL, key_c, value, value_size)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Info_set_hex_f08ts

SUBROUTINE MPI_Abort_f08(comm, errorcode, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Abort_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(in) :: errorcode
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: errorcode_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Abort_c(comm%MPI_VAL, errorcode)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Abort_f08

SUBROUTINE MPI_Comm_create_from_group_f08(group, stringtag, info, errhandler, newcomm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_types, ONLY : MPI_Group, MPI_Info, MPI_Errhandler, MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Group, c_Info, c_Errhandler, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Comm_create_from_group_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_f2c
    
    IMPLICIT NONE
    
    TYPE(MPI_Group), INTENT(in) :: group
    CHARACTER(len=*), INTENT(in) :: stringtag
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Errhandler), INTENT(in) :: errhandler
    TYPE(MPI_Comm), INTENT(out) :: newcomm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Group) :: group_c
    character(kind=c_char) :: stringtag_c(len_trim(stringtag) + 1)
    INTEGER(c_Info) :: info_c
    INTEGER(c_Errhandler) :: errhandler_c
    INTEGER(c_Comm) :: newcomm_c
    INTEGER(c_int) :: ierror_c
    
    call MPIR_Fortran_string_f2c(stringtag, stringtag_c)
    
    ierror_c = MPIR_Comm_create_from_group_c(group%MPI_VAL, stringtag_c, info%MPI_VAL, &
                                             errhandler%MPI_VAL, newcomm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_create_from_group_f08

SUBROUTINE MPI_Finalize_f08(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface, ONLY : MPIR_Finalize_c
    
    IMPLICIT NONE
    
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Finalize_c()
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Finalize_f08

SUBROUTINE MPI_Finalized_f08(flag, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface, ONLY : MPIR_Finalized_c
    
    IMPLICIT NONE
    
    LOGICAL, INTENT(out) :: flag
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: flag_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Finalized_c(flag_c)
    
    flag = (flag_c /= 0)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Finalized_f08

SUBROUTINE MPI_Group_from_session_pset_f08(session, pset_name, newgroup, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_types, ONLY : MPI_Session, MPI_Group
    USE :: mpi_c_interface_types, ONLY : c_Session, c_Group
    USE :: mpi_c_interface, ONLY : MPIR_Group_from_session_pset_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_f2c
    
    IMPLICIT NONE
    
    TYPE(MPI_Session), INTENT(in) :: session
    CHARACTER(len=*), INTENT(in) :: pset_name
    TYPE(MPI_Group), INTENT(out) :: newgroup
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Session) :: session_c
    character(kind=c_char) :: pset_name_c(len_trim(pset_name) + 1)
    INTEGER(c_Group) :: newgroup_c
    INTEGER(c_int) :: ierror_c
    
    call MPIR_Fortran_string_f2c(pset_name, pset_name_c)
    
    ierror_c = MPIR_Group_from_session_pset_c(session%MPI_VAL, pset_name_c, newgroup%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Group_from_session_pset_f08

SUBROUTINE MPI_Init_f08(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_null_ptr, c_int
    USE :: mpi_c_interface, ONLY : MPIR_Init_c
    
    IMPLICIT NONE
    
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Init_c(c_null_ptr, c_null_ptr)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Init_f08

SUBROUTINE MPI_Init_thread_f08(required, provided, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_null_ptr, c_int
    USE :: mpi_c_interface, ONLY : MPIR_Init_thread_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: required
    INTEGER, INTENT(out) :: provided
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: required_c
    INTEGER(c_int) :: provided_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Init_thread_c(c_null_ptr, c_null_ptr, required, provided)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Init_thread_f08

SUBROUTINE MPI_Initialized_f08(flag, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface, ONLY : MPIR_Initialized_c
    
    IMPLICIT NONE
    
    LOGICAL, INTENT(out) :: flag
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: flag_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Initialized_c(flag_c)
    
    flag = (flag_c /= 0)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Initialized_f08

SUBROUTINE MPI_Is_thread_main_f08(flag, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface, ONLY : MPIR_Is_thread_main_c
    
    IMPLICIT NONE
    
    LOGICAL, INTENT(out) :: flag
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: flag_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Is_thread_main_c(flag_c)
    
    flag = (flag_c /= 0)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Is_thread_main_f08

SUBROUTINE MPI_Query_thread_f08(provided, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface, ONLY : MPIR_Query_thread_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(out) :: provided
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: provided_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Query_thread_c(provided)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Query_thread_f08

SUBROUTINE MPI_Session_finalize_f08(session, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Session
    USE :: mpi_c_interface_types, ONLY : c_Session
    USE :: mpi_c_interface, ONLY : MPIR_Session_finalize_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Session), INTENT(inout) :: session
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Session) :: session_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Session_finalize_c(session%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Session_finalize_f08

SUBROUTINE MPI_Session_get_info_f08(session, info_used, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Session, MPI_Info
    USE :: mpi_c_interface_types, ONLY : c_Session, c_Info
    USE :: mpi_c_interface, ONLY : MPIR_Session_get_info_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Session), INTENT(in) :: session
    TYPE(MPI_Info), INTENT(out) :: info_used
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Session) :: session_c
    INTEGER(c_Info) :: info_used_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Session_get_info_c(session%MPI_VAL, info_used%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Session_get_info_f08

SUBROUTINE MPI_Session_get_nth_pset_f08(session, info, n, pset_len, pset_name, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_f08_types, ONLY : MPI_Session, MPI_Info
    USE :: mpi_c_interface_types, ONLY : c_Session, c_Info
    USE :: mpi_c_interface, ONLY : MPIR_Session_get_nth_pset_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_c2f
    
    IMPLICIT NONE
    
    TYPE(MPI_Session), INTENT(in) :: session
    TYPE(MPI_Info), INTENT(in) :: info
    INTEGER, INTENT(in) :: n
    INTEGER, INTENT(inout) :: pset_len
    CHARACTER(len=*), INTENT(out) :: pset_name
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Session) :: session_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_int) :: n_c
    INTEGER(c_int) :: pset_len_c
    character(kind=c_char) :: pset_name_c(len(pset_name) + 1)
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Session_get_nth_pset_c(session%MPI_VAL, info%MPI_VAL, n, pset_len, pset_name_c)
    
    call MPIR_Fortran_string_c2f(pset_name_c, pset_name)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Session_get_nth_pset_f08

SUBROUTINE MPI_Session_get_num_psets_f08(session, info, npset_names, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Session, MPI_Info
    USE :: mpi_c_interface_types, ONLY : c_Session, c_Info
    USE :: mpi_c_interface, ONLY : MPIR_Session_get_num_psets_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Session), INTENT(in) :: session
    TYPE(MPI_Info), INTENT(in) :: info
    INTEGER, INTENT(out) :: npset_names
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Session) :: session_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_int) :: npset_names_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Session_get_num_psets_c(session%MPI_VAL, info%MPI_VAL, npset_names)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Session_get_num_psets_f08

SUBROUTINE MPI_Session_get_pset_info_f08(session, pset_name, info, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_types, ONLY : MPI_Session, MPI_Info
    USE :: mpi_c_interface_types, ONLY : c_Session, c_Info
    USE :: mpi_c_interface, ONLY : MPIR_Session_get_pset_info_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_f2c
    
    IMPLICIT NONE
    
    TYPE(MPI_Session), INTENT(in) :: session
    CHARACTER(len=*), INTENT(in) :: pset_name
    TYPE(MPI_Info), INTENT(out) :: info
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Session) :: session_c
    character(kind=c_char) :: pset_name_c(len_trim(pset_name) + 1)
    INTEGER(c_Info) :: info_c
    INTEGER(c_int) :: ierror_c
    
    call MPIR_Fortran_string_f2c(pset_name, pset_name_c)
    
    ierror_c = MPIR_Session_get_pset_info_c(session%MPI_VAL, pset_name_c, info%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Session_get_pset_info_f08

SUBROUTINE MPI_Session_init_f08(info, errhandler, session, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Info, MPI_Errhandler, MPI_Session
    USE :: mpi_c_interface_types, ONLY : c_Info, c_Errhandler, c_Session
    USE :: mpi_c_interface, ONLY : MPIR_Session_init_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Errhandler), INTENT(in) :: errhandler
    TYPE(MPI_Session), INTENT(out) :: session
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Info) :: info_c
    INTEGER(c_Errhandler) :: errhandler_c
    INTEGER(c_Session) :: session_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Session_init_c(info%MPI_VAL, errhandler%MPI_VAL, session%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Session_init_f08

FUNCTION MPI_Aint_add_f08(base, disp) result(res)
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface, ONLY : MPIR_Aint_add_c
    
    IMPLICIT NONE
    
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: base
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: disp
    INTEGER(KIND=MPI_ADDRESS_KIND) :: res
    
    
    res = MPIR_Aint_add_c(base, disp)
    
END FUNCTION MPI_Aint_add_f08

FUNCTION MPI_Aint_diff_f08(addr1, addr2) result(res)
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface, ONLY : MPIR_Aint_diff_c
    
    IMPLICIT NONE
    
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: addr1
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: addr2
    INTEGER(KIND=MPI_ADDRESS_KIND) :: res
    
    
    res = MPIR_Aint_diff_c(addr1, addr2)
    
END FUNCTION MPI_Aint_diff_f08

SUBROUTINE MPI_Get_library_version_f08(version, resultlen, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_MAX_LIBRARY_VERSION_STRING
    USE :: mpi_c_interface, ONLY : MPIR_Get_library_version_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_c2f
    
    IMPLICIT NONE
    
    CHARACTER(len=MPI_MAX_LIBRARY_VERSION_STRING), INTENT(out) :: version
    INTEGER, INTENT(out) :: resultlen
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    character(kind=c_char) :: version_c(MPI_MAX_LIBRARY_VERSION_STRING + 1)
    INTEGER(c_int) :: resultlen_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Get_library_version_c(version_c, resultlen)
    
    call MPIR_Fortran_string_c2f(version_c, version)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Get_library_version_f08

SUBROUTINE MPI_Get_processor_name_f08(name, resultlen, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_MAX_PROCESSOR_NAME
    USE :: mpi_c_interface, ONLY : MPIR_Get_processor_name_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_c2f
    
    IMPLICIT NONE
    
    CHARACTER(len=MPI_MAX_PROCESSOR_NAME), INTENT(out) :: name
    INTEGER, INTENT(out) :: resultlen
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    character(kind=c_char) :: name_c(MPI_MAX_PROCESSOR_NAME + 1)
    INTEGER(c_int) :: resultlen_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Get_processor_name_c(name_c, resultlen)
    
    call MPIR_Fortran_string_c2f(name_c, name)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Get_processor_name_f08

SUBROUTINE MPI_Get_version_f08(version, subversion, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface, ONLY : MPIR_Get_version_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(out) :: version
    INTEGER, INTENT(out) :: subversion
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: version_c
    INTEGER(c_int) :: subversion_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Get_version_c(version, subversion)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Get_version_f08

SUBROUTINE MPI_Pcontrol_f08(level, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface, ONLY : MPIR_Pcontrol_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: level
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: level_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Pcontrol_c(level)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Pcontrol_f08

SUBROUTINE MPIX_GPU_query_support_f08(gpu_type, is_supported, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface, ONLY : MPIR_GPU_query_support_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: gpu_type
    LOGICAL, INTENT(out) :: is_supported
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: gpu_type_c
    INTEGER(c_int) :: is_supported_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_GPU_query_support_c(gpu_type, is_supported_c)
    
    is_supported = (is_supported_c /= 0)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_GPU_query_support_f08

SUBROUTINE MPIX_Query_cuda_support_f08(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface, ONLY : MPIR_Query_cuda_support_c
    
    IMPLICIT NONE
    
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Query_cuda_support_c()
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Query_cuda_support_f08

SUBROUTINE MPIX_Query_ze_support_f08(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface, ONLY : MPIR_Query_ze_support_c
    
    IMPLICIT NONE
    
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Query_ze_support_c()
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Query_ze_support_f08

SUBROUTINE MPIX_Query_hip_support_f08(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface, ONLY : MPIR_Query_hip_support_c
    
    IMPLICIT NONE
    
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Query_hip_support_c()
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Query_hip_support_f08

SUBROUTINE MPI_Op_commutative_f08(op, commute, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Op
    USE :: mpi_c_interface_types, ONLY : c_Op
    USE :: mpi_c_interface, ONLY : MPIR_Op_commutative_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Op), INTENT(in) :: op
    LOGICAL, INTENT(out) :: commute
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Op) :: op_c
    INTEGER(c_int) :: commute_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Op_commutative_c(op%MPI_VAL, commute_c)
    
    commute = (commute_c /= 0)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Op_commutative_f08

SUBROUTINE MPI_Op_create_f08(user_fn, commute, op, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_funptr, c_funloc, c_int
    USE :: mpi_f08_types, ONLY : MPI_Op
    USE :: mpi_f08_callbacks, ONLY : MPI_User_function
    USE :: mpi_c_interface_types, ONLY : c_Op
    USE :: mpi_c_interface, ONLY : MPIR_Op_create_c
    
    IMPLICIT NONE
    
    PROCEDURE(MPI_User_function) :: user_fn
    LOGICAL, INTENT(in) :: commute
    TYPE(MPI_Op), INTENT(out) :: op
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    TYPE(c_funptr) :: user_fn_c
    INTEGER(c_int) :: commute_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_int) :: ierror_c
    
    user_fn_c = c_funloc(user_fn)
    IF (commute) THEN
        commute_c = 1
    ELSE
        commute_c = 0
    END IF
    
    ierror_c = MPIR_Op_create_c(user_fn_c, commute_c, op%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Op_create_f08

SUBROUTINE MPI_Op_create_c_f08(user_fn, commute, op, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_funptr, c_funloc, c_int
    USE :: mpi_f08_types, ONLY : MPI_Op
    USE :: mpi_f08_callbacks, ONLY : MPI_User_function_c
    USE :: mpi_c_interface_types, ONLY : c_Op
    USE :: mpi_c_interface, ONLY : MPIR_Op_create_c_large
    
    IMPLICIT NONE
    
    PROCEDURE(MPI_User_function_c) :: user_fn
    LOGICAL, INTENT(in) :: commute
    TYPE(MPI_Op), INTENT(out) :: op
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    TYPE(c_funptr) :: user_fn_c
    INTEGER(c_int) :: commute_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_int) :: ierror_c
    
    user_fn_c = c_funloc(user_fn)
    IF (commute) THEN
        commute_c = 1
    ELSE
        commute_c = 0
    END IF
    
    ierror_c = MPIR_Op_create_c_large(user_fn_c, commute_c, op%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Op_create_c_f08

SUBROUTINE MPI_Op_free_f08(op, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Op
    USE :: mpi_c_interface_types, ONLY : c_Op
    USE :: mpi_c_interface, ONLY : MPIR_Op_free_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Op), INTENT(inout) :: op
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Op) :: op_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Op_free_c(op%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Op_free_f08

SUBROUTINE MPI_Parrived_f08(request, partition, flag, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Parrived_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Request), INTENT(in) :: request
    INTEGER, INTENT(in) :: partition
    LOGICAL, INTENT(out) :: flag
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: partition_c
    INTEGER(c_int) :: flag_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Parrived_c(request%MPI_VAL, partition, flag_c)
    
    flag = (flag_c /= 0)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Parrived_f08

SUBROUTINE MPI_Pready_f08(partition, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Pready_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: partition
    TYPE(MPI_Request), INTENT(in) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: partition_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Pready_c(partition, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Pready_f08

SUBROUTINE MPI_Pready_list_f08(length, array_of_partitions, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Pready_list_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: length
    INTEGER, INTENT(in) :: array_of_partitions(length)
    TYPE(MPI_Request), INTENT(in) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: length_c
    INTEGER(c_int) :: array_of_partitions_c(length)
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Pready_list_c(length, array_of_partitions, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Pready_list_f08

SUBROUTINE MPI_Pready_range_f08(partition_low, partition_high, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Pready_range_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: partition_low
    INTEGER, INTENT(in) :: partition_high
    TYPE(MPI_Request), INTENT(in) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: partition_low_c
    INTEGER(c_int) :: partition_high_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Pready_range_c(partition_low, partition_high, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Pready_range_f08

SUBROUTINE MPI_Precv_init_f08ts(buf, partitions, count, datatype, dest, tag, comm, info, request, &
                                ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Precv_init_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER, INTENT(in) :: partitions
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: partitions_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Precv_init_cdesc(buf, partitions, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL, &
                                     info%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Precv_init_f08ts

SUBROUTINE MPI_Psend_init_f08ts(buf, partitions, count, datatype, dest, tag, comm, info, request, &
                                ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Psend_init_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER, INTENT(in) :: partitions
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: partitions_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Psend_init_cdesc(buf, partitions, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL, &
                                     info%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Psend_init_f08ts

SUBROUTINE MPI_Bsend_f08ts(buf, count, datatype, dest, tag, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Bsend_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Bsend_cdesc(buf, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Bsend_f08ts

SUBROUTINE MPI_Bsend_c_f08ts(buf, count, datatype, dest, tag, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Bsend_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Bsend_cdesc_large(buf, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Bsend_c_f08ts

SUBROUTINE MPI_Bsend_init_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Bsend_init_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Bsend_init_cdesc(buf, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL, &
                                     request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Bsend_init_f08ts

SUBROUTINE MPI_Bsend_init_c_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Bsend_init_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Bsend_init_cdesc_large(buf, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL, &
                                           request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Bsend_init_c_f08ts

SUBROUTINE MPI_Buffer_attach_f08ts(buffer, size, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface, ONLY : MPIR_Buffer_attach_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buffer
    INTEGER, INTENT(in) :: size
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: size_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Buffer_attach_cdesc(buffer, size)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Buffer_attach_f08ts

SUBROUTINE MPI_Buffer_attach_c_f08ts(buffer, size, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface, ONLY : MPIR_Buffer_attach_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buffer
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: size
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Buffer_attach_cdesc_large(buffer, size)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Buffer_attach_c_f08ts

SUBROUTINE MPI_Buffer_detach_f08(buffer_addr, size, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : C_PTR, c_int
    USE :: mpi_c_interface, ONLY : MPIR_Buffer_detach_c
    
    IMPLICIT NONE
    
    TYPE(C_PTR), INTENT(out) :: buffer_addr
    INTEGER, INTENT(out) :: size
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: size_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Buffer_detach_c(buffer_addr, size)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Buffer_detach_f08

SUBROUTINE MPI_Buffer_detach_c_f08(buffer_addr, size, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : C_PTR, c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface, ONLY : MPIR_Buffer_detach_c_large
    
    IMPLICIT NONE
    
    TYPE(C_PTR), INTENT(out) :: buffer_addr
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: size
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Buffer_detach_c_large(buffer_addr, size)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Buffer_detach_c_f08

SUBROUTINE MPI_Buffer_flush_f08(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface, ONLY : MPIR_Buffer_flush_c
    
    IMPLICIT NONE
    
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Buffer_flush_c()
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Buffer_flush_f08

SUBROUTINE MPI_Buffer_iflush_f08(request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Buffer_iflush_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Buffer_iflush_c(request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Buffer_iflush_f08

SUBROUTINE MPI_Comm_attach_buffer_f08ts(comm, buffer, size, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Comm_attach_buffer_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buffer
    INTEGER, INTENT(in) :: size
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: size_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_attach_buffer_cdesc(comm%MPI_VAL, buffer, size)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_attach_buffer_f08ts

SUBROUTINE MPI_Comm_attach_buffer_c_f08ts(comm, buffer, size, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Comm_attach_buffer_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buffer
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: size
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_attach_buffer_cdesc_large(comm%MPI_VAL, buffer, size)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_attach_buffer_c_f08ts

SUBROUTINE MPI_Comm_detach_buffer_f08(comm, buffer_addr, size, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : C_PTR, c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Comm_detach_buffer_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(C_PTR), INTENT(out) :: buffer_addr
    INTEGER, INTENT(out) :: size
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: size_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_detach_buffer_c(comm%MPI_VAL, buffer_addr, size)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_detach_buffer_f08

SUBROUTINE MPI_Comm_detach_buffer_c_f08(comm, buffer_addr, size, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : C_PTR, c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Comm_detach_buffer_c_large
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(C_PTR), INTENT(out) :: buffer_addr
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: size
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_detach_buffer_c_large(comm%MPI_VAL, buffer_addr, size)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_detach_buffer_c_f08

SUBROUTINE MPI_Comm_flush_buffer_f08(comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Comm_flush_buffer_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_flush_buffer_c(comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_flush_buffer_f08

SUBROUTINE MPI_Comm_iflush_buffer_f08(comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Comm_iflush_buffer_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_iflush_buffer_c(comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_iflush_buffer_f08

SUBROUTINE MPI_Ibsend_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Ibsend_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Ibsend_cdesc(buf, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL, &
                                 request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Ibsend_f08ts

SUBROUTINE MPI_Ibsend_c_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Ibsend_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Ibsend_cdesc_large(buf, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL, &
                                       request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Ibsend_c_f08ts

SUBROUTINE MPI_Improbe_f08(source, tag, comm, flag, message, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Message, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Message, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Improbe_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: source
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    LOGICAL, INTENT(out) :: flag
    TYPE(MPI_Message), INTENT(out) :: message
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: source_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: flag_c
    INTEGER(c_Message) :: message_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_Improbe_c(source, tag, comm%MPI_VAL, flag_c, message%MPI_VAL, &
                                  MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_Improbe_c(source, tag, comm%MPI_VAL, flag_c, message%MPI_VAL, c_loc(status))
    END IF
    
    flag = (flag_c /= 0)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Improbe_f08

SUBROUTINE MPI_Imrecv_f08ts(buf, count, datatype, message, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Message, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Message, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Imrecv_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Message), INTENT(inout) :: message
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Message) :: message_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Imrecv_cdesc(buf, count, datatype%MPI_VAL, message%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Imrecv_f08ts

SUBROUTINE MPI_Imrecv_c_f08ts(buf, count, datatype, message, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Message, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Message, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Imrecv_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Message), INTENT(inout) :: message
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Message) :: message_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Imrecv_cdesc_large(buf, count, datatype%MPI_VAL, message%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Imrecv_c_f08ts

SUBROUTINE MPI_Iprobe_f08(source, tag, comm, flag, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Iprobe_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: source
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    LOGICAL, INTENT(out) :: flag
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: source_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: flag_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_Iprobe_c(source, tag, comm%MPI_VAL, flag_c, MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_Iprobe_c(source, tag, comm%MPI_VAL, flag_c, c_loc(status))
    END IF
    
    flag = (flag_c /= 0)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Iprobe_f08

SUBROUTINE MPI_Irecv_f08ts(buf, count, datatype, source, tag, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Irecv_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: source
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: source_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Irecv_cdesc(buf, count, datatype%MPI_VAL, source, tag, comm%MPI_VAL, &
                                request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Irecv_f08ts

SUBROUTINE MPI_Irecv_c_f08ts(buf, count, datatype, source, tag, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Irecv_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: source
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: source_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Irecv_cdesc_large(buf, count, datatype%MPI_VAL, source, tag, comm%MPI_VAL, &
                                      request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Irecv_c_f08ts

SUBROUTINE MPI_Irsend_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Irsend_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Irsend_cdesc(buf, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL, &
                                 request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Irsend_f08ts

SUBROUTINE MPI_Irsend_c_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Irsend_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Irsend_cdesc_large(buf, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL, &
                                       request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Irsend_c_f08ts

SUBROUTINE MPI_Isend_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Isend_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Isend_cdesc(buf, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Isend_f08ts

SUBROUTINE MPI_Isend_c_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Isend_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Isend_cdesc_large(buf, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL, &
                                      request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Isend_c_f08ts

SUBROUTINE MPI_Isendrecv_f08ts(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, &
                               recvtype, source, recvtag, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Isendrecv_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER, INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: sendtag
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER, INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    INTEGER, INTENT(in) :: source
    INTEGER, INTENT(in) :: recvtag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: sendcount_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: sendtag_c
    INTEGER(c_int) :: recvcount_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_int) :: source_c
    INTEGER(c_int) :: recvtag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Isendrecv_cdesc(sendbuf, sendcount, sendtype%MPI_VAL, dest, sendtag, recvbuf, &
                                    recvcount, recvtype%MPI_VAL, source, recvtag, comm%MPI_VAL, &
                                    request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Isendrecv_f08ts

SUBROUTINE MPI_Isendrecv_c_f08ts(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, &
                                 recvtype, source, recvtag, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Isendrecv_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: sendtag
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    INTEGER, INTENT(in) :: source
    INTEGER, INTENT(in) :: recvtag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: sendtag_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_int) :: source_c
    INTEGER(c_int) :: recvtag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Isendrecv_cdesc_large(sendbuf, sendcount, sendtype%MPI_VAL, dest, sendtag, recvbuf, &
                                          recvcount, recvtype%MPI_VAL, source, recvtag, comm%MPI_VAL, &
                                          request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Isendrecv_c_f08ts

SUBROUTINE MPI_Isendrecv_replace_f08ts(buf, count, datatype, dest, sendtag, source, recvtag, comm, &
                                       request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Isendrecv_replace_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(inout), ASYNCHRONOUS :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: sendtag
    INTEGER, INTENT(in) :: source
    INTEGER, INTENT(in) :: recvtag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: sendtag_c
    INTEGER(c_int) :: source_c
    INTEGER(c_int) :: recvtag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Isendrecv_replace_cdesc(buf, count, datatype%MPI_VAL, dest, sendtag, source, &
                                            recvtag, comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Isendrecv_replace_f08ts

SUBROUTINE MPI_Isendrecv_replace_c_f08ts(buf, count, datatype, dest, sendtag, source, recvtag, comm, &
                                         request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Isendrecv_replace_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(inout), ASYNCHRONOUS :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: sendtag
    INTEGER, INTENT(in) :: source
    INTEGER, INTENT(in) :: recvtag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: sendtag_c
    INTEGER(c_int) :: source_c
    INTEGER(c_int) :: recvtag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Isendrecv_replace_cdesc_large(buf, count, datatype%MPI_VAL, dest, sendtag, source, &
                                                  recvtag, comm%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Isendrecv_replace_c_f08ts

SUBROUTINE MPI_Issend_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Issend_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Issend_cdesc(buf, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL, &
                                 request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Issend_f08ts

SUBROUTINE MPI_Issend_c_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Issend_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Issend_cdesc_large(buf, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL, &
                                       request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Issend_c_f08ts

SUBROUTINE MPI_Mprobe_f08(source, tag, comm, message, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Message, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Message, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Mprobe_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: source
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Message), INTENT(out) :: message
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: source_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Message) :: message_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_Mprobe_c(source, tag, comm%MPI_VAL, message%MPI_VAL, &
                                 MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_Mprobe_c(source, tag, comm%MPI_VAL, message%MPI_VAL, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Mprobe_f08

SUBROUTINE MPI_Mrecv_f08ts(buf, count, datatype, message, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Message, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Message, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Mrecv_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..) :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Message), INTENT(inout) :: message
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Message) :: message_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_Mrecv_cdesc(buf, count, datatype%MPI_VAL, message%MPI_VAL, &
                                    MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_Mrecv_cdesc(buf, count, datatype%MPI_VAL, message%MPI_VAL, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Mrecv_f08ts

SUBROUTINE MPI_Mrecv_c_f08ts(buf, count, datatype, message, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Message, MPI_Status, assignment(=)
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Message, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Mrecv_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Message), INTENT(inout) :: message
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Message) :: message_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_Mrecv_cdesc_large(buf, count, datatype%MPI_VAL, message%MPI_VAL, &
                                          MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_Mrecv_cdesc_large(buf, count, datatype%MPI_VAL, message%MPI_VAL, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Mrecv_c_f08ts

SUBROUTINE MPI_Probe_f08(source, tag, comm, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Probe_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: source
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: source_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_Probe_c(source, tag, comm%MPI_VAL, MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_Probe_c(source, tag, comm%MPI_VAL, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Probe_f08

SUBROUTINE MPI_Recv_f08ts(buf, count, datatype, source, tag, comm, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Recv_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..) :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: source
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: source_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_Recv_cdesc(buf, count, datatype%MPI_VAL, source, tag, comm%MPI_VAL, &
                                   MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_Recv_cdesc(buf, count, datatype%MPI_VAL, source, tag, comm%MPI_VAL, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Recv_f08ts

SUBROUTINE MPI_Recv_c_f08ts(buf, count, datatype, source, tag, comm, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Status, assignment(=)
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Recv_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: source
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: source_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_Recv_cdesc_large(buf, count, datatype%MPI_VAL, source, tag, comm%MPI_VAL, &
                                         MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_Recv_cdesc_large(buf, count, datatype%MPI_VAL, source, tag, comm%MPI_VAL, &
                                         c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Recv_c_f08ts

SUBROUTINE MPI_Recv_init_f08ts(buf, count, datatype, source, tag, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Recv_init_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: source
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: source_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Recv_init_cdesc(buf, count, datatype%MPI_VAL, source, tag, comm%MPI_VAL, &
                                    request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Recv_init_f08ts

SUBROUTINE MPI_Recv_init_c_f08ts(buf, count, datatype, source, tag, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Recv_init_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: source
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: source_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Recv_init_cdesc_large(buf, count, datatype%MPI_VAL, source, tag, comm%MPI_VAL, &
                                          request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Recv_init_c_f08ts

SUBROUTINE MPI_Rsend_f08ts(buf, count, datatype, dest, tag, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Rsend_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Rsend_cdesc(buf, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Rsend_f08ts

SUBROUTINE MPI_Rsend_c_f08ts(buf, count, datatype, dest, tag, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Rsend_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Rsend_cdesc_large(buf, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Rsend_c_f08ts

SUBROUTINE MPI_Rsend_init_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Rsend_init_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Rsend_init_cdesc(buf, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL, &
                                     request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Rsend_init_f08ts

SUBROUTINE MPI_Rsend_init_c_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Rsend_init_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Rsend_init_cdesc_large(buf, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL, &
                                           request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Rsend_init_c_f08ts

SUBROUTINE MPI_Send_f08ts(buf, count, datatype, dest, tag, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Send_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Send_cdesc(buf, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Send_f08ts

SUBROUTINE MPI_Send_c_f08ts(buf, count, datatype, dest, tag, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Send_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Send_cdesc_large(buf, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Send_c_f08ts

SUBROUTINE MPI_Send_init_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Send_init_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Send_init_cdesc(buf, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL, &
                                    request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Send_init_f08ts

SUBROUTINE MPI_Send_init_c_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Send_init_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Send_init_cdesc_large(buf, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL, &
                                          request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Send_init_c_f08ts

SUBROUTINE MPI_Sendrecv_f08ts(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, &
                              recvtype, source, recvtag, comm, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Sendrecv_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER, INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: sendtag
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER, INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    INTEGER, INTENT(in) :: source
    INTEGER, INTENT(in) :: recvtag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: sendcount_c
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: sendtag_c
    INTEGER(c_int) :: recvcount_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_int) :: source_c
    INTEGER(c_int) :: recvtag_c
    INTEGER(c_Comm) :: comm_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_Sendrecv_cdesc(sendbuf, sendcount, sendtype%MPI_VAL, dest, sendtag, recvbuf, &
                                       recvcount, recvtype%MPI_VAL, source, recvtag, comm%MPI_VAL, &
                                       MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_Sendrecv_cdesc(sendbuf, sendcount, sendtype%MPI_VAL, dest, sendtag, recvbuf, &
                                       recvcount, recvtype%MPI_VAL, source, recvtag, comm%MPI_VAL, &
                                       c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Sendrecv_f08ts

SUBROUTINE MPI_Sendrecv_c_f08ts(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, &
                                recvtype, source, recvtag, comm, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Status, assignment(=)
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Sendrecv_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
    TYPE(MPI_Datatype), INTENT(in) :: sendtype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: sendtag
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcount
    TYPE(MPI_Datatype), INTENT(in) :: recvtype
    INTEGER, INTENT(in) :: source
    INTEGER, INTENT(in) :: recvtag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: sendtype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: sendtag_c
    INTEGER(c_Datatype) :: recvtype_c
    INTEGER(c_int) :: source_c
    INTEGER(c_int) :: recvtag_c
    INTEGER(c_Comm) :: comm_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_Sendrecv_cdesc_large(sendbuf, sendcount, sendtype%MPI_VAL, dest, sendtag, recvbuf, &
                                             recvcount, recvtype%MPI_VAL, source, recvtag, comm%MPI_VAL, &
                                             MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_Sendrecv_cdesc_large(sendbuf, sendcount, sendtype%MPI_VAL, dest, sendtag, recvbuf, &
                                             recvcount, recvtype%MPI_VAL, source, recvtag, comm%MPI_VAL, &
                                             c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Sendrecv_c_f08ts

SUBROUTINE MPI_Sendrecv_replace_f08ts(buf, count, datatype, dest, sendtag, source, recvtag, comm, &
                                      status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Sendrecv_replace_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(inout) :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: sendtag
    INTEGER, INTENT(in) :: source
    INTEGER, INTENT(in) :: recvtag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: sendtag_c
    INTEGER(c_int) :: source_c
    INTEGER(c_int) :: recvtag_c
    INTEGER(c_Comm) :: comm_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_Sendrecv_replace_cdesc(buf, count, datatype%MPI_VAL, dest, sendtag, source, recvtag, &
                                               comm%MPI_VAL, MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_Sendrecv_replace_cdesc(buf, count, datatype%MPI_VAL, dest, sendtag, source, recvtag, &
                                               comm%MPI_VAL, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Sendrecv_replace_f08ts

SUBROUTINE MPI_Sendrecv_replace_c_f08ts(buf, count, datatype, dest, sendtag, source, recvtag, comm, &
                                        status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Status, assignment(=)
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Sendrecv_replace_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(inout) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: sendtag
    INTEGER, INTENT(in) :: source
    INTEGER, INTENT(in) :: recvtag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: sendtag_c
    INTEGER(c_int) :: source_c
    INTEGER(c_int) :: recvtag_c
    INTEGER(c_Comm) :: comm_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_Sendrecv_replace_cdesc_large(buf, count, datatype%MPI_VAL, dest, sendtag, source, &
                                                     recvtag, comm%MPI_VAL, &
                                                     MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_Sendrecv_replace_cdesc_large(buf, count, datatype%MPI_VAL, dest, sendtag, source, &
                                                     recvtag, comm%MPI_VAL, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Sendrecv_replace_c_f08ts

SUBROUTINE MPI_Session_attach_buffer_f08ts(session, buffer, size, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Session
    USE :: mpi_c_interface_types, ONLY : c_Session
    USE :: mpi_c_interface, ONLY : MPIR_Session_attach_buffer_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_Session), INTENT(in) :: session
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buffer
    INTEGER, INTENT(in) :: size
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Session) :: session_c
    INTEGER(c_int) :: size_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Session_attach_buffer_cdesc(session%MPI_VAL, buffer, size)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Session_attach_buffer_f08ts

SUBROUTINE MPI_Session_attach_buffer_c_f08ts(session, buffer, size, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Session
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Session
    USE :: mpi_c_interface, ONLY : MPIR_Session_attach_buffer_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(MPI_Session), INTENT(in) :: session
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buffer
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: size
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Session) :: session_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Session_attach_buffer_cdesc_large(session%MPI_VAL, buffer, size)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Session_attach_buffer_c_f08ts

SUBROUTINE MPI_Session_detach_buffer_f08(session, buffer_addr, size, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : C_PTR, c_int
    USE :: mpi_f08_types, ONLY : MPI_Session
    USE :: mpi_c_interface_types, ONLY : c_Session
    USE :: mpi_c_interface, ONLY : MPIR_Session_detach_buffer_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Session), INTENT(in) :: session
    TYPE(C_PTR), INTENT(out) :: buffer_addr
    INTEGER, INTENT(out) :: size
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Session) :: session_c
    INTEGER(c_int) :: size_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Session_detach_buffer_c(session%MPI_VAL, buffer_addr, size)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Session_detach_buffer_f08

SUBROUTINE MPI_Session_detach_buffer_c_f08(session, buffer_addr, size, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : C_PTR, c_int
    USE :: mpi_f08_types, ONLY : MPI_Session
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Session
    USE :: mpi_c_interface, ONLY : MPIR_Session_detach_buffer_c_large
    
    IMPLICIT NONE
    
    TYPE(MPI_Session), INTENT(in) :: session
    TYPE(C_PTR), INTENT(out) :: buffer_addr
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: size
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Session) :: session_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Session_detach_buffer_c_large(session%MPI_VAL, buffer_addr, size)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Session_detach_buffer_c_f08

SUBROUTINE MPI_Session_flush_buffer_f08(session, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Session
    USE :: mpi_c_interface_types, ONLY : c_Session
    USE :: mpi_c_interface, ONLY : MPIR_Session_flush_buffer_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Session), INTENT(in) :: session
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Session) :: session_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Session_flush_buffer_c(session%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Session_flush_buffer_f08

SUBROUTINE MPI_Session_iflush_buffer_f08(session, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Session, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Session, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Session_iflush_buffer_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Session), INTENT(in) :: session
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Session) :: session_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Session_iflush_buffer_c(session%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Session_iflush_buffer_f08

SUBROUTINE MPI_Ssend_f08ts(buf, count, datatype, dest, tag, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Ssend_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Ssend_cdesc(buf, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Ssend_f08ts

SUBROUTINE MPI_Ssend_c_f08ts(buf, count, datatype, dest, tag, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Ssend_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Ssend_cdesc_large(buf, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Ssend_c_f08ts

SUBROUTINE MPI_Ssend_init_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Ssend_init_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Ssend_init_cdesc(buf, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL, &
                                     request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Ssend_init_f08ts

SUBROUTINE MPI_Ssend_init_c_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Ssend_init_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Ssend_init_cdesc_large(buf, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL, &
                                           request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Ssend_init_c_f08ts

SUBROUTINE MPI_Cancel_f08(request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Cancel_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Request), INTENT(in) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Cancel_c(request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Cancel_f08

SUBROUTINE MPI_Grequest_complete_f08(request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Grequest_complete_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Request), INTENT(in) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Grequest_complete_c(request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Grequest_complete_f08

SUBROUTINE MPI_Grequest_start_f08(query_fn, free_fn, cancel_fn, extra_state, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_funptr, c_funloc, c_int
    USE :: mpi_f08_types, ONLY : MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND, MPI_SUCCESS
    USE :: mpi_f08_callbacks, ONLY : MPI_Grequest_query_function, MPI_Grequest_free_function, &
        MPI_Grequest_cancel_function
    USE :: mpi_c_interface_types, ONLY : c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Grequest_start_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Grequest_set_lang_fortran
    
    IMPLICIT NONE
    
    PROCEDURE(MPI_Grequest_query_function) :: query_fn
    PROCEDURE(MPI_Grequest_free_function) :: free_fn
    PROCEDURE(MPI_Grequest_cancel_function) :: cancel_fn
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: extra_state
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    TYPE(c_funptr) :: query_fn_c
    TYPE(c_funptr) :: free_fn_c
    TYPE(c_funptr) :: cancel_fn_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    query_fn_c = c_funloc(query_fn)
    free_fn_c = c_funloc(free_fn)
    cancel_fn_c = c_funloc(cancel_fn)
    
    ierror_c = MPIR_Grequest_start_c(query_fn_c, free_fn_c, cancel_fn_c, extra_state, request_c)
    IF (ierror_c == MPI_SUCCESS) THEN
        call MPIR_Grequest_set_lang_fortran(request_c)
    END IF
    request%MPI_VAL = request_c
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Grequest_start_f08

SUBROUTINE MPI_Request_free_f08(request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Request_free_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Request), INTENT(inout) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Request_free_c(request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Request_free_f08

SUBROUTINE MPI_Request_get_status_f08(request, flag, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_Request, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Request_get_status_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Request), INTENT(in) :: request
    LOGICAL, INTENT(out) :: flag
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: flag_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_Request_get_status_c(request%MPI_VAL, flag_c, MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_Request_get_status_c(request%MPI_VAL, flag_c, c_loc(status))
    END IF
    
    flag = (flag_c /= 0)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Request_get_status_f08

SUBROUTINE MPI_Request_get_status_all_f08(count, array_of_requests, flag, array_of_statuses, &
                                          ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUSES_IGNORE, MPIR_F08_get_MPI_STATUSES_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_Request, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Request_get_status_all_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Request), INTENT(in) :: array_of_requests(count)
    LOGICAL, INTENT(out) :: flag
    TYPE(MPI_Status), INTENT(out), TARGET :: array_of_statuses(*)
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Request) :: array_of_requests_c(count)
    INTEGER(c_int) :: flag_c
    TYPE(c_Status), TARGET :: array_of_statuses_c(count)
    INTEGER(c_int) :: ierror_c
    
    IF (c_associated(c_loc(array_of_statuses), c_loc(MPI_STATUSES_IGNORE))) THEN
        ierror_c = MPIR_Request_get_status_all_c(count, array_of_requests%MPI_VAL, flag_c, &
                                                 MPIR_F08_get_MPI_STATUSES_IGNORE_c())
    ELSE
        ierror_c = MPIR_Request_get_status_all_c(count, array_of_requests%MPI_VAL, flag_c, &
                                                 c_loc(array_of_statuses))
    END IF
    
    flag = (flag_c /= 0)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Request_get_status_all_f08

SUBROUTINE MPI_Request_get_status_any_f08(count, array_of_requests, indx, flag, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status, assignment(=)
    USE :: mpi_f08_compile_constants, ONLY : MPI_UNDEFINED
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_Request, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Request_get_status_any_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Request), INTENT(in) :: array_of_requests(count)
    INTEGER, INTENT(out) :: indx
    LOGICAL, INTENT(out) :: flag
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Request) :: array_of_requests_c(count)
    INTEGER(c_int) :: indx_c
    INTEGER(c_int) :: flag_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_Request_get_status_any_c(count, array_of_requests%MPI_VAL, indx_c, flag_c, &
                                                 MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_Request_get_status_any_c(count, array_of_requests%MPI_VAL, indx_c, flag_c, &
                                                 c_loc(status))
    END IF
    
    IF (indx_c == MPI_UNDEFINED) THEN
        indx = indx_c
    ELSE
        indx = indx_c + 1
    END IF
    flag = (flag_c /= 0)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Request_get_status_any_f08

SUBROUTINE MPI_Request_get_status_some_f08(incount, array_of_requests, outcount, array_of_indices, &
                                           array_of_statuses, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUSES_IGNORE, MPIR_F08_get_MPI_STATUSES_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_Request, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Request_get_status_some_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: incount
    TYPE(MPI_Request), INTENT(in) :: array_of_requests(incount)
    INTEGER, INTENT(out) :: outcount
    INTEGER, INTENT(out) :: array_of_indices(*)
    TYPE(MPI_Status), INTENT(out), TARGET :: array_of_statuses(*)
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: incount_c
    INTEGER(c_Request) :: array_of_requests_c(incount)
    INTEGER(c_int) :: outcount_c
    INTEGER(c_int) :: array_of_indices_c(incount)
    TYPE(c_Status), TARGET :: array_of_statuses_c(incount)
    INTEGER(c_int) :: ierror_c
    
    IF (c_associated(c_loc(array_of_statuses), c_loc(MPI_STATUSES_IGNORE))) THEN
        ierror_c = MPIR_Request_get_status_some_c(incount, array_of_requests%MPI_VAL, outcount, &
                                                  array_of_indices_c, MPIR_F08_get_MPI_STATUSES_IGNORE_c())
    ELSE
        ierror_c = MPIR_Request_get_status_some_c(incount, array_of_requests%MPI_VAL, outcount, &
                                                  array_of_indices_c, c_loc(array_of_statuses))
    END IF
    
    array_of_indices(1:outcount) = array_of_indices_c(1:outcount) + 1
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Request_get_status_some_f08

SUBROUTINE MPI_Start_f08(request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Start_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Request), INTENT(inout) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Start_c(request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Start_f08

SUBROUTINE MPI_Startall_f08(count, array_of_requests, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Startall_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Request), INTENT(inout) :: array_of_requests(count)
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Request) :: array_of_requests_c(count)
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Startall_c(count, array_of_requests%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Startall_f08

SUBROUTINE MPI_Status_get_error_f08(status, error, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_Status, assignment(=)
    USE :: mpi_c_interface_types, ONLY : c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Status_get_error_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Status), INTENT(in), TARGET :: status
    INTEGER, INTENT(out) :: error
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: error_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Status_get_error_c(c_loc(status), error)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Status_get_error_f08

SUBROUTINE MPI_Status_get_source_f08(status, source, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_Status, assignment(=)
    USE :: mpi_c_interface_types, ONLY : c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Status_get_source_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Status), INTENT(in), TARGET :: status
    INTEGER, INTENT(out) :: source
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: source_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Status_get_source_c(c_loc(status), source)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Status_get_source_f08

SUBROUTINE MPI_Status_get_tag_f08(status, tag, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_Status, assignment(=)
    USE :: mpi_c_interface_types, ONLY : c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Status_get_tag_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Status), INTENT(in), TARGET :: status
    INTEGER, INTENT(out) :: tag
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Status_get_tag_c(c_loc(status), tag)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Status_get_tag_f08

SUBROUTINE MPI_Status_set_error_f08(status, error, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_Status, assignment(=)
    USE :: mpi_c_interface_types, ONLY : c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Status_set_error_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Status), INTENT(inout), TARGET :: status
    INTEGER, INTENT(in) :: error
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: error_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Status_set_error_c(c_loc(status), error)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Status_set_error_f08

SUBROUTINE MPI_Status_set_source_f08(status, source, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_Status, assignment(=)
    USE :: mpi_c_interface_types, ONLY : c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Status_set_source_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Status), INTENT(inout), TARGET :: status
    INTEGER, INTENT(in) :: source
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: source_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Status_set_source_c(c_loc(status), source)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Status_set_source_f08

SUBROUTINE MPI_Status_set_tag_f08(status, tag, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_Status, assignment(=)
    USE :: mpi_c_interface_types, ONLY : c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Status_set_tag_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Status), INTENT(inout), TARGET :: status
    INTEGER, INTENT(in) :: tag
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Status_set_tag_c(c_loc(status), tag)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Status_set_tag_f08

SUBROUTINE MPI_Status_set_cancelled_f08(status, flag, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_Status, assignment(=)
    USE :: mpi_c_interface_types, ONLY : c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Status_set_cancelled_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Status), INTENT(inout), TARGET :: status
    LOGICAL, INTENT(in) :: flag
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: flag_c
    INTEGER(c_int) :: ierror_c
    
    IF (flag) THEN
        flag_c = 1
    ELSE
        flag_c = 0
    END IF
    
    ierror_c = MPIR_Status_set_cancelled_c(c_loc(status), flag_c)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Status_set_cancelled_f08

SUBROUTINE MPI_Test_f08(request, flag, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_Request, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Test_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Request), INTENT(inout) :: request
    LOGICAL, INTENT(out) :: flag
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: flag_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_Test_c(request%MPI_VAL, flag_c, MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_Test_c(request%MPI_VAL, flag_c, c_loc(status))
    END IF
    
    flag = (flag_c /= 0)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Test_f08

SUBROUTINE MPI_Test_cancelled_f08(status, flag, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_Status, assignment(=)
    USE :: mpi_c_interface_types, ONLY : c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Test_cancelled_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Status), INTENT(in), TARGET :: status
    LOGICAL, INTENT(out) :: flag
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: flag_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Test_cancelled_c(c_loc(status), flag_c)
    
    flag = (flag_c /= 0)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Test_cancelled_f08

SUBROUTINE MPI_Testall_f08(count, array_of_requests, flag, array_of_statuses, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUSES_IGNORE, MPIR_F08_get_MPI_STATUSES_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_Request, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Testall_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Request), INTENT(inout) :: array_of_requests(count)
    LOGICAL, INTENT(out) :: flag
    TYPE(MPI_Status), INTENT(out), TARGET :: array_of_statuses(*)
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Request) :: array_of_requests_c(count)
    INTEGER(c_int) :: flag_c
    TYPE(c_Status), TARGET :: array_of_statuses_c(count)
    INTEGER(c_int) :: ierror_c
    
    IF (c_associated(c_loc(array_of_statuses), c_loc(MPI_STATUSES_IGNORE))) THEN
        ierror_c = MPIR_Testall_c(count, array_of_requests%MPI_VAL, flag_c, &
                                  MPIR_F08_get_MPI_STATUSES_IGNORE_c())
    ELSE
        ierror_c = MPIR_Testall_c(count, array_of_requests%MPI_VAL, flag_c, c_loc(array_of_statuses))
    END IF
    
    flag = (flag_c /= 0)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Testall_f08

SUBROUTINE MPI_Testany_f08(count, array_of_requests, indx, flag, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status, assignment(=)
    USE :: mpi_f08_compile_constants, ONLY : MPI_UNDEFINED
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_Request, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Testany_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Request), INTENT(inout) :: array_of_requests(count)
    INTEGER, INTENT(out) :: indx
    LOGICAL, INTENT(out) :: flag
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Request) :: array_of_requests_c(count)
    INTEGER(c_int) :: indx_c
    INTEGER(c_int) :: flag_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_Testany_c(count, array_of_requests%MPI_VAL, indx_c, flag_c, &
                                  MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_Testany_c(count, array_of_requests%MPI_VAL, indx_c, flag_c, c_loc(status))
    END IF
    
    IF (indx_c == MPI_UNDEFINED) THEN
        indx = indx_c
    ELSE
        indx = indx_c + 1
    END IF
    flag = (flag_c /= 0)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Testany_f08

SUBROUTINE MPI_Testsome_f08(incount, array_of_requests, outcount, array_of_indices, &
                            array_of_statuses, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUSES_IGNORE, MPIR_F08_get_MPI_STATUSES_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_Request, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Testsome_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: incount
    TYPE(MPI_Request), INTENT(inout) :: array_of_requests(incount)
    INTEGER, INTENT(out) :: outcount
    INTEGER, INTENT(out) :: array_of_indices(*)
    TYPE(MPI_Status), INTENT(out), TARGET :: array_of_statuses(*)
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: incount_c
    INTEGER(c_Request) :: array_of_requests_c(incount)
    INTEGER(c_int) :: outcount_c
    INTEGER(c_int) :: array_of_indices_c(incount)
    TYPE(c_Status), TARGET :: array_of_statuses_c(incount)
    INTEGER(c_int) :: ierror_c
    
    IF (c_associated(c_loc(array_of_statuses), c_loc(MPI_STATUSES_IGNORE))) THEN
        ierror_c = MPIR_Testsome_c(incount, array_of_requests%MPI_VAL, outcount, array_of_indices_c, &
                                   MPIR_F08_get_MPI_STATUSES_IGNORE_c())
    ELSE
        ierror_c = MPIR_Testsome_c(incount, array_of_requests%MPI_VAL, outcount, array_of_indices_c, &
                                   c_loc(array_of_statuses))
    END IF
    
    array_of_indices(1:outcount) = array_of_indices_c(1:outcount) + 1
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Testsome_f08

SUBROUTINE MPI_Wait_f08(request, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_Request, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Wait_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Request), INTENT(inout) :: request
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Request) :: request_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_Wait_c(request%MPI_VAL, MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_Wait_c(request%MPI_VAL, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Wait_f08

SUBROUTINE MPI_Waitall_f08(count, array_of_requests, array_of_statuses, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUSES_IGNORE, MPIR_F08_get_MPI_STATUSES_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_Request, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Waitall_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Request), INTENT(inout) :: array_of_requests(count)
    TYPE(MPI_Status), INTENT(out), TARGET :: array_of_statuses(*)
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Request) :: array_of_requests_c(count)
    TYPE(c_Status), TARGET :: array_of_statuses_c(count)
    INTEGER(c_int) :: ierror_c
    
    IF (c_associated(c_loc(array_of_statuses), c_loc(MPI_STATUSES_IGNORE))) THEN
        ierror_c = MPIR_Waitall_c(count, array_of_requests%MPI_VAL, MPIR_F08_get_MPI_STATUSES_IGNORE_c())
    ELSE
        ierror_c = MPIR_Waitall_c(count, array_of_requests%MPI_VAL, c_loc(array_of_statuses))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Waitall_f08

SUBROUTINE MPI_Waitany_f08(count, array_of_requests, indx, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status, assignment(=)
    USE :: mpi_f08_compile_constants, ONLY : MPI_UNDEFINED
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_Request, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Waitany_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Request), INTENT(inout) :: array_of_requests(count)
    INTEGER, INTENT(out) :: indx
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Request) :: array_of_requests_c(count)
    INTEGER(c_int) :: indx_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_Waitany_c(count, array_of_requests%MPI_VAL, indx_c, &
                                  MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_Waitany_c(count, array_of_requests%MPI_VAL, indx_c, c_loc(status))
    END IF
    
    IF (indx_c == MPI_UNDEFINED) THEN
        indx = indx_c
    ELSE
        indx = indx_c + 1
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Waitany_f08

SUBROUTINE MPI_Waitsome_f08(incount, array_of_requests, outcount, array_of_indices, &
                            array_of_statuses, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUSES_IGNORE, MPIR_F08_get_MPI_STATUSES_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_Request, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Waitsome_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: incount
    TYPE(MPI_Request), INTENT(inout) :: array_of_requests(incount)
    INTEGER, INTENT(out) :: outcount
    INTEGER, INTENT(out) :: array_of_indices(*)
    TYPE(MPI_Status), INTENT(out), TARGET :: array_of_statuses(*)
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: incount_c
    INTEGER(c_Request) :: array_of_requests_c(incount)
    INTEGER(c_int) :: outcount_c
    INTEGER(c_int) :: array_of_indices_c(incount)
    TYPE(c_Status), TARGET :: array_of_statuses_c(incount)
    INTEGER(c_int) :: ierror_c
    
    IF (c_associated(c_loc(array_of_statuses), c_loc(MPI_STATUSES_IGNORE))) THEN
        ierror_c = MPIR_Waitsome_c(incount, array_of_requests%MPI_VAL, outcount, array_of_indices_c, &
                                   MPIR_F08_get_MPI_STATUSES_IGNORE_c())
    ELSE
        ierror_c = MPIR_Waitsome_c(incount, array_of_requests%MPI_VAL, outcount, array_of_indices_c, &
                                   c_loc(array_of_statuses))
    END IF
    
    array_of_indices(1:outcount) = array_of_indices_c(1:outcount) + 1
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Waitsome_f08

FUNCTION MPIX_Request_is_complete_f08(request) result(res)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Request_is_complete_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Request), INTENT(in) :: request
    LOGICAL :: res
    
    INTEGER(c_Request) :: request_c
    
    res = MPIR_Request_is_complete_c(request%MPI_VAL)
    
END FUNCTION MPIX_Request_is_complete_f08

SUBROUTINE MPI_Accumulate_f08ts(origin_addr, origin_count, origin_datatype, target_rank, &
                                target_disp, target_count, target_datatype, op, win, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Win
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Accumulate_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: origin_addr
    INTEGER, INTENT(in) :: origin_count
    TYPE(MPI_Datatype), INTENT(in) :: origin_datatype
    INTEGER, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: target_disp
    INTEGER, INTENT(in) :: target_count
    TYPE(MPI_Datatype), INTENT(in) :: target_datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Win), INTENT(in) :: win
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: origin_count_c
    INTEGER(c_Datatype) :: origin_datatype_c
    INTEGER(c_int) :: target_rank_c
    INTEGER(c_int) :: target_count_c
    INTEGER(c_Datatype) :: target_datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Accumulate_cdesc(origin_addr, origin_count, origin_datatype%MPI_VAL, target_rank, &
                                     target_disp, target_count, target_datatype%MPI_VAL, op%MPI_VAL, &
                                     win%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Accumulate_f08ts

SUBROUTINE MPI_Accumulate_c_f08ts(origin_addr, origin_count, origin_datatype, target_rank, &
                                  target_disp, target_count, target_datatype, op, win, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Win
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Accumulate_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: origin_addr
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: origin_count
    TYPE(MPI_Datatype), INTENT(in) :: origin_datatype
    INTEGER, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: target_disp
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: target_count
    TYPE(MPI_Datatype), INTENT(in) :: target_datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Win), INTENT(in) :: win
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: origin_datatype_c
    INTEGER(c_int) :: target_rank_c
    INTEGER(c_Datatype) :: target_datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Accumulate_cdesc_large(origin_addr, origin_count, origin_datatype%MPI_VAL, &
                                           target_rank, target_disp, target_count, &
                                           target_datatype%MPI_VAL, op%MPI_VAL, win%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Accumulate_c_f08ts

SUBROUTINE MPI_Alloc_mem_f08(size, info, baseptr, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : C_PTR, c_int
    USE :: mpi_f08_types, ONLY : MPI_Info
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Info
    USE :: mpi_c_interface, ONLY : MPIR_Alloc_mem_c
    
    IMPLICIT NONE
    
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: size
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(C_PTR), INTENT(out) :: baseptr
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Info) :: info_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Alloc_mem_c(size, info%MPI_VAL, baseptr)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Alloc_mem_f08

SUBROUTINE MPI_Compare_and_swap_f08ts(origin_addr, compare_addr, result_addr, datatype, target_rank, &
                                      target_disp, win, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Win
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Compare_and_swap_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: origin_addr
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: compare_addr
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: result_addr
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: target_disp
    TYPE(MPI_Win), INTENT(in) :: win
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: target_rank_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Compare_and_swap_cdesc(origin_addr, compare_addr, result_addr, datatype%MPI_VAL, &
                                           target_rank, target_disp, win%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Compare_and_swap_f08ts

SUBROUTINE MPI_Fetch_and_op_f08ts(origin_addr, result_addr, datatype, target_rank, target_disp, op, &
                                  win, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Win
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Fetch_and_op_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: origin_addr
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: result_addr
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: target_disp
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Win), INTENT(in) :: win
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: target_rank_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Fetch_and_op_cdesc(origin_addr, result_addr, datatype%MPI_VAL, target_rank, &
                                       target_disp, op%MPI_VAL, win%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Fetch_and_op_f08ts

SUBROUTINE MPI_Free_mem_f08ts(base, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface, ONLY : MPIR_Free_mem_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: base
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Free_mem_cdesc(base)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Free_mem_f08ts

SUBROUTINE MPI_Get_f08ts(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
                         target_count, target_datatype, win, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Win
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Get_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: origin_addr
    INTEGER, INTENT(in) :: origin_count
    TYPE(MPI_Datatype), INTENT(in) :: origin_datatype
    INTEGER, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: target_disp
    INTEGER, INTENT(in) :: target_count
    TYPE(MPI_Datatype), INTENT(in) :: target_datatype
    TYPE(MPI_Win), INTENT(in) :: win
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: origin_count_c
    INTEGER(c_Datatype) :: origin_datatype_c
    INTEGER(c_int) :: target_rank_c
    INTEGER(c_int) :: target_count_c
    INTEGER(c_Datatype) :: target_datatype_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Get_cdesc(origin_addr, origin_count, origin_datatype%MPI_VAL, target_rank, &
                              target_disp, target_count, target_datatype%MPI_VAL, win%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Get_f08ts

SUBROUTINE MPI_Get_c_f08ts(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
                           target_count, target_datatype, win, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Win
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Get_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: origin_addr
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: origin_count
    TYPE(MPI_Datatype), INTENT(in) :: origin_datatype
    INTEGER, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: target_disp
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: target_count
    TYPE(MPI_Datatype), INTENT(in) :: target_datatype
    TYPE(MPI_Win), INTENT(in) :: win
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: origin_datatype_c
    INTEGER(c_int) :: target_rank_c
    INTEGER(c_Datatype) :: target_datatype_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Get_cdesc_large(origin_addr, origin_count, origin_datatype%MPI_VAL, target_rank, &
                                    target_disp, target_count, target_datatype%MPI_VAL, win%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Get_c_f08ts

SUBROUTINE MPI_Get_accumulate_f08ts(origin_addr, origin_count, origin_datatype, result_addr, &
                                    result_count, result_datatype, target_rank, target_disp, &
                                    target_count, target_datatype, op, win, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Win
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Get_accumulate_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: origin_addr
    INTEGER, INTENT(in) :: origin_count
    TYPE(MPI_Datatype), INTENT(in) :: origin_datatype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: result_addr
    INTEGER, INTENT(in) :: result_count
    TYPE(MPI_Datatype), INTENT(in) :: result_datatype
    INTEGER, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: target_disp
    INTEGER, INTENT(in) :: target_count
    TYPE(MPI_Datatype), INTENT(in) :: target_datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Win), INTENT(in) :: win
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: origin_count_c
    INTEGER(c_Datatype) :: origin_datatype_c
    INTEGER(c_int) :: result_count_c
    INTEGER(c_Datatype) :: result_datatype_c
    INTEGER(c_int) :: target_rank_c
    INTEGER(c_int) :: target_count_c
    INTEGER(c_Datatype) :: target_datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Get_accumulate_cdesc(origin_addr, origin_count, origin_datatype%MPI_VAL, &
                                         result_addr, result_count, result_datatype%MPI_VAL, &
                                         target_rank, target_disp, target_count, &
                                         target_datatype%MPI_VAL, op%MPI_VAL, win%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Get_accumulate_f08ts

SUBROUTINE MPI_Get_accumulate_c_f08ts(origin_addr, origin_count, origin_datatype, result_addr, &
                                      result_count, result_datatype, target_rank, target_disp, &
                                      target_count, target_datatype, op, win, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Win
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Get_accumulate_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: origin_addr
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: origin_count
    TYPE(MPI_Datatype), INTENT(in) :: origin_datatype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: result_addr
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: result_count
    TYPE(MPI_Datatype), INTENT(in) :: result_datatype
    INTEGER, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: target_disp
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: target_count
    TYPE(MPI_Datatype), INTENT(in) :: target_datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Win), INTENT(in) :: win
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: origin_datatype_c
    INTEGER(c_Datatype) :: result_datatype_c
    INTEGER(c_int) :: target_rank_c
    INTEGER(c_Datatype) :: target_datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Get_accumulate_cdesc_large(origin_addr, origin_count, origin_datatype%MPI_VAL, &
                                               result_addr, result_count, result_datatype%MPI_VAL, &
                                               target_rank, target_disp, target_count, &
                                               target_datatype%MPI_VAL, op%MPI_VAL, win%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Get_accumulate_c_f08ts

SUBROUTINE MPI_Put_f08ts(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
                         target_count, target_datatype, win, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Win
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Put_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: origin_addr
    INTEGER, INTENT(in) :: origin_count
    TYPE(MPI_Datatype), INTENT(in) :: origin_datatype
    INTEGER, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: target_disp
    INTEGER, INTENT(in) :: target_count
    TYPE(MPI_Datatype), INTENT(in) :: target_datatype
    TYPE(MPI_Win), INTENT(in) :: win
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: origin_count_c
    INTEGER(c_Datatype) :: origin_datatype_c
    INTEGER(c_int) :: target_rank_c
    INTEGER(c_int) :: target_count_c
    INTEGER(c_Datatype) :: target_datatype_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Put_cdesc(origin_addr, origin_count, origin_datatype%MPI_VAL, target_rank, &
                              target_disp, target_count, target_datatype%MPI_VAL, win%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Put_f08ts

SUBROUTINE MPI_Put_c_f08ts(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
                           target_count, target_datatype, win, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Win
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Put_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: origin_addr
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: origin_count
    TYPE(MPI_Datatype), INTENT(in) :: origin_datatype
    INTEGER, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: target_disp
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: target_count
    TYPE(MPI_Datatype), INTENT(in) :: target_datatype
    TYPE(MPI_Win), INTENT(in) :: win
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: origin_datatype_c
    INTEGER(c_int) :: target_rank_c
    INTEGER(c_Datatype) :: target_datatype_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Put_cdesc_large(origin_addr, origin_count, origin_datatype%MPI_VAL, target_rank, &
                                    target_disp, target_count, target_datatype%MPI_VAL, win%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Put_c_f08ts

SUBROUTINE MPI_Raccumulate_f08ts(origin_addr, origin_count, origin_datatype, target_rank, &
                                 target_disp, target_count, target_datatype, op, win, request, &
                                 ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Win, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Win, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Raccumulate_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: origin_addr
    INTEGER, INTENT(in) :: origin_count
    TYPE(MPI_Datatype), INTENT(in) :: origin_datatype
    INTEGER, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: target_disp
    INTEGER, INTENT(in) :: target_count
    TYPE(MPI_Datatype), INTENT(in) :: target_datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Win), INTENT(in) :: win
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: origin_count_c
    INTEGER(c_Datatype) :: origin_datatype_c
    INTEGER(c_int) :: target_rank_c
    INTEGER(c_int) :: target_count_c
    INTEGER(c_Datatype) :: target_datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Raccumulate_cdesc(origin_addr, origin_count, origin_datatype%MPI_VAL, target_rank, &
                                      target_disp, target_count, target_datatype%MPI_VAL, op%MPI_VAL, &
                                      win%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Raccumulate_f08ts

SUBROUTINE MPI_Raccumulate_c_f08ts(origin_addr, origin_count, origin_datatype, target_rank, &
                                   target_disp, target_count, target_datatype, op, win, request, &
                                   ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Win, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Win, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Raccumulate_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: origin_addr
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: origin_count
    TYPE(MPI_Datatype), INTENT(in) :: origin_datatype
    INTEGER, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: target_disp
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: target_count
    TYPE(MPI_Datatype), INTENT(in) :: target_datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Win), INTENT(in) :: win
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: origin_datatype_c
    INTEGER(c_int) :: target_rank_c
    INTEGER(c_Datatype) :: target_datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Raccumulate_cdesc_large(origin_addr, origin_count, origin_datatype%MPI_VAL, &
                                            target_rank, target_disp, target_count, &
                                            target_datatype%MPI_VAL, op%MPI_VAL, win%MPI_VAL, &
                                            request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Raccumulate_c_f08ts

SUBROUTINE MPI_Rget_f08ts(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
                          target_count, target_datatype, win, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Win, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Win, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Rget_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: origin_addr
    INTEGER, INTENT(in) :: origin_count
    TYPE(MPI_Datatype), INTENT(in) :: origin_datatype
    INTEGER, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: target_disp
    INTEGER, INTENT(in) :: target_count
    TYPE(MPI_Datatype), INTENT(in) :: target_datatype
    TYPE(MPI_Win), INTENT(in) :: win
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: origin_count_c
    INTEGER(c_Datatype) :: origin_datatype_c
    INTEGER(c_int) :: target_rank_c
    INTEGER(c_int) :: target_count_c
    INTEGER(c_Datatype) :: target_datatype_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Rget_cdesc(origin_addr, origin_count, origin_datatype%MPI_VAL, target_rank, &
                               target_disp, target_count, target_datatype%MPI_VAL, win%MPI_VAL, &
                               request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Rget_f08ts

SUBROUTINE MPI_Rget_c_f08ts(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
                            target_count, target_datatype, win, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Win, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Win, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Rget_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: origin_addr
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: origin_count
    TYPE(MPI_Datatype), INTENT(in) :: origin_datatype
    INTEGER, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: target_disp
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: target_count
    TYPE(MPI_Datatype), INTENT(in) :: target_datatype
    TYPE(MPI_Win), INTENT(in) :: win
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: origin_datatype_c
    INTEGER(c_int) :: target_rank_c
    INTEGER(c_Datatype) :: target_datatype_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Rget_cdesc_large(origin_addr, origin_count, origin_datatype%MPI_VAL, target_rank, &
                                     target_disp, target_count, target_datatype%MPI_VAL, win%MPI_VAL, &
                                     request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Rget_c_f08ts

SUBROUTINE MPI_Rget_accumulate_f08ts(origin_addr, origin_count, origin_datatype, result_addr, &
                                     result_count, result_datatype, target_rank, target_disp, &
                                     target_count, target_datatype, op, win, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Win, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Win, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Rget_accumulate_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: origin_addr
    INTEGER, INTENT(in) :: origin_count
    TYPE(MPI_Datatype), INTENT(in) :: origin_datatype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: result_addr
    INTEGER, INTENT(in) :: result_count
    TYPE(MPI_Datatype), INTENT(in) :: result_datatype
    INTEGER, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: target_disp
    INTEGER, INTENT(in) :: target_count
    TYPE(MPI_Datatype), INTENT(in) :: target_datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Win), INTENT(in) :: win
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: origin_count_c
    INTEGER(c_Datatype) :: origin_datatype_c
    INTEGER(c_int) :: result_count_c
    INTEGER(c_Datatype) :: result_datatype_c
    INTEGER(c_int) :: target_rank_c
    INTEGER(c_int) :: target_count_c
    INTEGER(c_Datatype) :: target_datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Rget_accumulate_cdesc(origin_addr, origin_count, origin_datatype%MPI_VAL, &
                                          result_addr, result_count, result_datatype%MPI_VAL, &
                                          target_rank, target_disp, target_count, &
                                          target_datatype%MPI_VAL, op%MPI_VAL, win%MPI_VAL, &
                                          request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Rget_accumulate_f08ts

SUBROUTINE MPI_Rget_accumulate_c_f08ts(origin_addr, origin_count, origin_datatype, result_addr, &
                                       result_count, result_datatype, target_rank, target_disp, &
                                       target_count, target_datatype, op, win, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Win, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Win, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Rget_accumulate_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: origin_addr
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: origin_count
    TYPE(MPI_Datatype), INTENT(in) :: origin_datatype
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: result_addr
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: result_count
    TYPE(MPI_Datatype), INTENT(in) :: result_datatype
    INTEGER, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: target_disp
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: target_count
    TYPE(MPI_Datatype), INTENT(in) :: target_datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Win), INTENT(in) :: win
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: origin_datatype_c
    INTEGER(c_Datatype) :: result_datatype_c
    INTEGER(c_int) :: target_rank_c
    INTEGER(c_Datatype) :: target_datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Rget_accumulate_cdesc_large(origin_addr, origin_count, origin_datatype%MPI_VAL, &
                                                result_addr, result_count, result_datatype%MPI_VAL, &
                                                target_rank, target_disp, target_count, &
                                                target_datatype%MPI_VAL, op%MPI_VAL, win%MPI_VAL, &
                                                request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Rget_accumulate_c_f08ts

SUBROUTINE MPI_Rput_f08ts(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
                          target_count, target_datatype, win, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Win, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Win, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Rput_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: origin_addr
    INTEGER, INTENT(in) :: origin_count
    TYPE(MPI_Datatype), INTENT(in) :: origin_datatype
    INTEGER, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: target_disp
    INTEGER, INTENT(in) :: target_count
    TYPE(MPI_Datatype), INTENT(in) :: target_datatype
    TYPE(MPI_Win), INTENT(in) :: win
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: origin_count_c
    INTEGER(c_Datatype) :: origin_datatype_c
    INTEGER(c_int) :: target_rank_c
    INTEGER(c_int) :: target_count_c
    INTEGER(c_Datatype) :: target_datatype_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Rput_cdesc(origin_addr, origin_count, origin_datatype%MPI_VAL, target_rank, &
                               target_disp, target_count, target_datatype%MPI_VAL, win%MPI_VAL, &
                               request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Rput_f08ts

SUBROUTINE MPI_Rput_c_f08ts(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
                            target_count, target_datatype, win, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Win, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Win, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Rput_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: origin_addr
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: origin_count
    TYPE(MPI_Datatype), INTENT(in) :: origin_datatype
    INTEGER, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: target_disp
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: target_count
    TYPE(MPI_Datatype), INTENT(in) :: target_datatype
    TYPE(MPI_Win), INTENT(in) :: win
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: origin_datatype_c
    INTEGER(c_int) :: target_rank_c
    INTEGER(c_Datatype) :: target_datatype_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Rput_cdesc_large(origin_addr, origin_count, origin_datatype%MPI_VAL, target_rank, &
                                     target_disp, target_count, target_datatype%MPI_VAL, win%MPI_VAL, &
                                     request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Rput_c_f08ts

SUBROUTINE MPI_Win_allocate_f08(size, disp_unit, info, comm, baseptr, win, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, C_PTR
    USE :: mpi_f08_types, ONLY : MPI_Info, MPI_Comm, MPI_Win
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Info, c_Comm, c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_allocate_c
    
    IMPLICIT NONE
    
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: size
    INTEGER, INTENT(in) :: disp_unit
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(C_PTR), INTENT(out) :: baseptr
    TYPE(MPI_Win), INTENT(out) :: win
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: disp_unit_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_allocate_c(size, disp_unit, info%MPI_VAL, comm%MPI_VAL, baseptr, win%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_allocate_f08

SUBROUTINE MPI_Win_allocate_c_f08(size, disp_unit, info, comm, baseptr, win, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : C_PTR, c_int
    USE :: mpi_f08_types, ONLY : MPI_Info, MPI_Comm, MPI_Win
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Info, c_Comm, c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_allocate_c_large
    
    IMPLICIT NONE
    
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: size
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: disp_unit
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(C_PTR), INTENT(out) :: baseptr
    TYPE(MPI_Win), INTENT(out) :: win
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Info) :: info_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_allocate_c_large(size, disp_unit, info%MPI_VAL, comm%MPI_VAL, baseptr, &
                                         win%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_allocate_c_f08

SUBROUTINE MPI_Win_allocate_shared_f08(size, disp_unit, info, comm, baseptr, win, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, C_PTR
    USE :: mpi_f08_types, ONLY : MPI_Info, MPI_Comm, MPI_Win
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Info, c_Comm, c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_allocate_shared_c
    
    IMPLICIT NONE
    
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: size
    INTEGER, INTENT(in) :: disp_unit
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(C_PTR), INTENT(out) :: baseptr
    TYPE(MPI_Win), INTENT(out) :: win
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: disp_unit_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_allocate_shared_c(size, disp_unit, info%MPI_VAL, comm%MPI_VAL, baseptr, &
                                          win%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_allocate_shared_f08

SUBROUTINE MPI_Win_allocate_shared_c_f08(size, disp_unit, info, comm, baseptr, win, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : C_PTR, c_int
    USE :: mpi_f08_types, ONLY : MPI_Info, MPI_Comm, MPI_Win
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Info, c_Comm, c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_allocate_shared_c_large
    
    IMPLICIT NONE
    
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: size
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: disp_unit
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(C_PTR), INTENT(out) :: baseptr
    TYPE(MPI_Win), INTENT(out) :: win
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Info) :: info_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_allocate_shared_c_large(size, disp_unit, info%MPI_VAL, comm%MPI_VAL, baseptr, &
                                                win%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_allocate_shared_c_f08

SUBROUTINE MPI_Win_attach_f08ts(win, base, size, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Win
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_attach_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_Win), INTENT(in) :: win
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: base
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: size
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_attach_cdesc(win%MPI_VAL, base, size)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_attach_f08ts

SUBROUTINE MPI_Win_complete_f08(win, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Win
    USE :: mpi_c_interface_types, ONLY : c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_complete_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Win), INTENT(in) :: win
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_complete_c(win%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_complete_f08

SUBROUTINE MPI_Win_create_f08ts(base, size, disp_unit, info, comm, win, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Info, MPI_Comm, MPI_Win
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Info, c_Comm, c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_create_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: base
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: size
    INTEGER, INTENT(in) :: disp_unit
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Win), INTENT(out) :: win
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: disp_unit_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_create_cdesc(base, size, disp_unit, info%MPI_VAL, comm%MPI_VAL, win%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_create_f08ts

SUBROUTINE MPI_Win_create_c_f08ts(base, size, disp_unit, info, comm, win, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Info, MPI_Comm, MPI_Win
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Info, c_Comm, c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_create_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: base
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: size
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: disp_unit
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Win), INTENT(out) :: win
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Info) :: info_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_create_cdesc_large(base, size, disp_unit, info%MPI_VAL, comm%MPI_VAL, &
                                           win%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_create_c_f08ts

SUBROUTINE MPI_Win_create_dynamic_f08(info, comm, win, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Info, MPI_Comm, MPI_Win
    USE :: mpi_c_interface_types, ONLY : c_Info, c_Comm, c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_create_dynamic_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Win), INTENT(out) :: win
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Info) :: info_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_create_dynamic_c(info%MPI_VAL, comm%MPI_VAL, win%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_create_dynamic_f08

SUBROUTINE MPI_Win_detach_f08ts(win, base, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Win
    USE :: mpi_c_interface_types, ONLY : c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_detach_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_Win), INTENT(in) :: win
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: base
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_detach_cdesc(win%MPI_VAL, base)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_detach_f08ts

SUBROUTINE MPI_Win_fence_f08(assert, win, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Win
    USE :: mpi_c_interface_types, ONLY : c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_fence_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: assert
    TYPE(MPI_Win), INTENT(in) :: win
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: assert_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_fence_c(assert, win%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_fence_f08

SUBROUTINE MPI_Win_flush_f08(rank, win, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Win
    USE :: mpi_c_interface_types, ONLY : c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_flush_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: rank
    TYPE(MPI_Win), INTENT(in) :: win
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: rank_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_flush_c(rank, win%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_flush_f08

SUBROUTINE MPI_Win_flush_all_f08(win, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Win
    USE :: mpi_c_interface_types, ONLY : c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_flush_all_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Win), INTENT(in) :: win
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_flush_all_c(win%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_flush_all_f08

SUBROUTINE MPI_Win_flush_local_f08(rank, win, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Win
    USE :: mpi_c_interface_types, ONLY : c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_flush_local_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: rank
    TYPE(MPI_Win), INTENT(in) :: win
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: rank_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_flush_local_c(rank, win%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_flush_local_f08

SUBROUTINE MPI_Win_flush_local_all_f08(win, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Win
    USE :: mpi_c_interface_types, ONLY : c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_flush_local_all_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Win), INTENT(in) :: win
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_flush_local_all_c(win%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_flush_local_all_f08

SUBROUTINE MPI_Win_free_f08(win, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Win
    USE :: mpi_c_interface_types, ONLY : c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_free_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Win), INTENT(inout) :: win
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_free_c(win%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_free_f08

SUBROUTINE MPI_Win_get_group_f08(win, group, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Win, MPI_Group
    USE :: mpi_c_interface_types, ONLY : c_Win, c_Group
    USE :: mpi_c_interface, ONLY : MPIR_Win_get_group_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Win), INTENT(in) :: win
    TYPE(MPI_Group), INTENT(out) :: group
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Win) :: win_c
    INTEGER(c_Group) :: group_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_get_group_c(win%MPI_VAL, group%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_get_group_f08

SUBROUTINE MPI_Win_get_info_f08(win, info_used, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Win, MPI_Info
    USE :: mpi_c_interface_types, ONLY : c_Win, c_Info
    USE :: mpi_c_interface, ONLY : MPIR_Win_get_info_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Win), INTENT(in) :: win
    TYPE(MPI_Info), INTENT(out) :: info_used
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Win) :: win_c
    INTEGER(c_Info) :: info_used_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_get_info_c(win%MPI_VAL, info_used%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_get_info_f08

SUBROUTINE MPI_Win_get_name_f08(win, win_name, resultlen, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_types, ONLY : MPI_Win
    USE :: mpi_f08_compile_constants, ONLY : MPI_MAX_OBJECT_NAME
    USE :: mpi_c_interface_types, ONLY : c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_get_name_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_c2f
    
    IMPLICIT NONE
    
    TYPE(MPI_Win), INTENT(in) :: win
    CHARACTER(len=MPI_MAX_OBJECT_NAME), INTENT(out) :: win_name
    INTEGER, INTENT(out) :: resultlen
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Win) :: win_c
    character(kind=c_char) :: win_name_c(MPI_MAX_OBJECT_NAME + 1)
    INTEGER(c_int) :: resultlen_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_get_name_c(win%MPI_VAL, win_name_c, resultlen)
    
    call MPIR_Fortran_string_c2f(win_name_c, win_name)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_get_name_f08

SUBROUTINE MPI_Win_lock_f08(lock_type, rank, assert, win, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Win
    USE :: mpi_c_interface_types, ONLY : c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_lock_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: lock_type
    INTEGER, INTENT(in) :: rank
    INTEGER, INTENT(in) :: assert
    TYPE(MPI_Win), INTENT(in) :: win
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: lock_type_c
    INTEGER(c_int) :: rank_c
    INTEGER(c_int) :: assert_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_lock_c(lock_type, rank, assert, win%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_lock_f08

SUBROUTINE MPI_Win_lock_all_f08(assert, win, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Win
    USE :: mpi_c_interface_types, ONLY : c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_lock_all_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: assert
    TYPE(MPI_Win), INTENT(in) :: win
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: assert_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_lock_all_c(assert, win%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_lock_all_f08

SUBROUTINE MPI_Win_post_f08(group, assert, win, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Group, MPI_Win
    USE :: mpi_c_interface_types, ONLY : c_Group, c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_post_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Group), INTENT(in) :: group
    INTEGER, INTENT(in) :: assert
    TYPE(MPI_Win), INTENT(in) :: win
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Group) :: group_c
    INTEGER(c_int) :: assert_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_post_c(group%MPI_VAL, assert, win%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_post_f08

SUBROUTINE MPI_Win_set_info_f08(win, info, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Win, MPI_Info
    USE :: mpi_c_interface_types, ONLY : c_Win, c_Info
    USE :: mpi_c_interface, ONLY : MPIR_Win_set_info_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Win), INTENT(in) :: win
    TYPE(MPI_Info), INTENT(in) :: info
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Win) :: win_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_set_info_c(win%MPI_VAL, info%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_set_info_f08

SUBROUTINE MPI_Win_set_name_f08(win, win_name, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_types, ONLY : MPI_Win
    USE :: mpi_c_interface_types, ONLY : c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_set_name_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_f2c
    
    IMPLICIT NONE
    
    TYPE(MPI_Win), INTENT(in) :: win
    CHARACTER(len=*), INTENT(in) :: win_name
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Win) :: win_c
    character(kind=c_char) :: win_name_c(len_trim(win_name) + 1)
    INTEGER(c_int) :: ierror_c
    
    call MPIR_Fortran_string_f2c(win_name, win_name_c)
    
    ierror_c = MPIR_Win_set_name_c(win%MPI_VAL, win_name_c)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_set_name_f08

SUBROUTINE MPI_Win_shared_query_f08(win, rank, size, disp_unit, baseptr, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, C_PTR
    USE :: mpi_f08_types, ONLY : MPI_Win
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_shared_query_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Win), INTENT(in) :: win
    INTEGER, INTENT(in) :: rank
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: size
    INTEGER, INTENT(out) :: disp_unit
    TYPE(C_PTR), INTENT(out) :: baseptr
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: rank_c
    INTEGER(c_int) :: disp_unit_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_shared_query_c(win%MPI_VAL, rank, size, disp_unit, baseptr)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_shared_query_f08

SUBROUTINE MPI_Win_shared_query_c_f08(win, rank, size, disp_unit, baseptr, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, C_PTR
    USE :: mpi_f08_types, ONLY : MPI_Win
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_shared_query_c_large
    
    IMPLICIT NONE
    
    TYPE(MPI_Win), INTENT(in) :: win
    INTEGER, INTENT(in) :: rank
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: size
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: disp_unit
    TYPE(C_PTR), INTENT(out) :: baseptr
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: rank_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_shared_query_c_large(win%MPI_VAL, rank, size, disp_unit, baseptr)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_shared_query_c_f08

SUBROUTINE MPI_Win_start_f08(group, assert, win, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Group, MPI_Win
    USE :: mpi_c_interface_types, ONLY : c_Group, c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_start_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Group), INTENT(in) :: group
    INTEGER, INTENT(in) :: assert
    TYPE(MPI_Win), INTENT(in) :: win
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Group) :: group_c
    INTEGER(c_int) :: assert_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_start_c(group%MPI_VAL, assert, win%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_start_f08

SUBROUTINE MPI_Win_sync_f08(win, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Win
    USE :: mpi_c_interface_types, ONLY : c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_sync_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Win), INTENT(in) :: win
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_sync_c(win%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_sync_f08

SUBROUTINE MPI_Win_test_f08(win, flag, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Win
    USE :: mpi_c_interface_types, ONLY : c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_test_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Win), INTENT(in) :: win
    LOGICAL, INTENT(out) :: flag
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: flag_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_test_c(win%MPI_VAL, flag_c)
    
    flag = (flag_c /= 0)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_test_f08

SUBROUTINE MPI_Win_unlock_f08(rank, win, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Win
    USE :: mpi_c_interface_types, ONLY : c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_unlock_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: rank
    TYPE(MPI_Win), INTENT(in) :: win
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: rank_c
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_unlock_c(rank, win%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_unlock_f08

SUBROUTINE MPI_Win_unlock_all_f08(win, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Win
    USE :: mpi_c_interface_types, ONLY : c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_unlock_all_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Win), INTENT(in) :: win
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_unlock_all_c(win%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_unlock_all_f08

SUBROUTINE MPI_Win_wait_f08(win, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Win
    USE :: mpi_c_interface_types, ONLY : c_Win
    USE :: mpi_c_interface, ONLY : MPIR_Win_wait_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Win), INTENT(in) :: win
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Win) :: win_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Win_wait_c(win%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Win_wait_f08

SUBROUTINE MPI_Close_port_f08(port_name, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_c_interface, ONLY : MPIR_Close_port_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_f2c
    
    IMPLICIT NONE
    
    CHARACTER(len=*), INTENT(in) :: port_name
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    character(kind=c_char) :: port_name_c(len_trim(port_name) + 1)
    INTEGER(c_int) :: ierror_c
    
    call MPIR_Fortran_string_f2c(port_name, port_name_c)
    
    ierror_c = MPIR_Close_port_c(port_name_c)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Close_port_f08

SUBROUTINE MPI_Comm_accept_f08(port_name, info, root, comm, newcomm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_types, ONLY : MPI_Info, MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Info, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Comm_accept_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_f2c
    
    IMPLICIT NONE
    
    CHARACTER(len=*), INTENT(in) :: port_name
    TYPE(MPI_Info), INTENT(in) :: info
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Comm), INTENT(out) :: newcomm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    character(kind=c_char) :: port_name_c(len_trim(port_name) + 1)
    INTEGER(c_Info) :: info_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Comm) :: newcomm_c
    INTEGER(c_int) :: ierror_c
    
    call MPIR_Fortran_string_f2c(port_name, port_name_c)
    
    ierror_c = MPIR_Comm_accept_c(port_name_c, info%MPI_VAL, root, comm%MPI_VAL, newcomm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_accept_f08

SUBROUTINE MPI_Comm_connect_f08(port_name, info, root, comm, newcomm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_types, ONLY : MPI_Info, MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Info, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Comm_connect_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_f2c
    
    IMPLICIT NONE
    
    CHARACTER(len=*), INTENT(in) :: port_name
    TYPE(MPI_Info), INTENT(in) :: info
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Comm), INTENT(out) :: newcomm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    character(kind=c_char) :: port_name_c(len_trim(port_name) + 1)
    INTEGER(c_Info) :: info_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Comm) :: newcomm_c
    INTEGER(c_int) :: ierror_c
    
    call MPIR_Fortran_string_f2c(port_name, port_name_c)
    
    ierror_c = MPIR_Comm_connect_c(port_name_c, info%MPI_VAL, root, comm%MPI_VAL, newcomm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_connect_f08

SUBROUTINE MPI_Comm_disconnect_f08(comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Comm_disconnect_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(inout) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_disconnect_c(comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_disconnect_f08

SUBROUTINE MPI_Comm_get_parent_f08(parent, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Comm_get_parent_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(out) :: parent
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: parent_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_get_parent_c(parent%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_get_parent_f08

SUBROUTINE MPI_Comm_join_f08(fd, intercomm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Comm_join_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: fd
    TYPE(MPI_Comm), INTENT(out) :: intercomm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: fd_c
    INTEGER(c_Comm) :: intercomm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_join_c(fd, intercomm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_join_f08

SUBROUTINE MPI_Comm_spawn_f08(command, argv, maxprocs, info, root, comm, intercomm, &
                              array_of_errcodes, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_ptr, c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_Info, MPI_Comm
    USE :: mpi_f08_link_constants, ONLY : MPI_ARGV_NULL, MPIR_F08_get_MPI_ARGV_NULL_c, &
        MPI_ERRCODES_IGNORE, MPIR_F08_get_MPI_ERRCODES_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_Info, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Comm_spawn_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_f2c
    
    IMPLICIT NONE
    
    CHARACTER(len=*), INTENT(in) :: command
    CHARACTER(len=*), INTENT(in), TARGET :: argv(*)
    INTEGER, INTENT(in) :: maxprocs
    TYPE(MPI_Info), INTENT(in) :: info
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Comm), INTENT(out) :: intercomm
    INTEGER, TARGET :: array_of_errcodes(*)
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    character(kind=c_char) :: command_c(len_trim(command) + 1)
    TYPE(c_ptr) :: argv_cptr
    INTEGER(c_int) :: maxprocs_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Comm) :: intercomm_c
    TYPE(c_ptr) :: array_of_errcodes_cptr
    LOGICAL :: has_errcodes_ignore = .false.
    INTEGER(c_int), TARGET :: array_of_errcodes_c(maxprocs)
    INTEGER(c_int) :: argv_len
    INTEGER(c_int) :: ierror_c
    
    call MPIR_Fortran_string_f2c(command, command_c)
    argv_cptr = c_loc(argv)
    IF (c_associated(argv_cptr, c_loc(MPI_ARGV_NULL))) THEN
        argv_cptr = MPIR_F08_get_MPI_ARGV_NULL_c()
    END IF
    array_of_errcodes_cptr = c_loc(array_of_errcodes)
    IF (c_associated(array_of_errcodes_cptr, c_loc(MPI_ERRCODES_IGNORE))) THEN
        array_of_errcodes_cptr = MPIR_F08_get_MPI_ERRCODES_IGNORE_c()
        has_errcodes_ignore = .true.
    END IF
    argv_len = len(argv)
    
    ierror_c = MPIR_Comm_spawn_c(command_c, argv_cptr, maxprocs, info%MPI_VAL, root, comm%MPI_VAL, &
                                 intercomm%MPI_VAL, array_of_errcodes_cptr, argv_len)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_spawn_f08

SUBROUTINE MPI_Comm_spawn_multiple_f08(count, array_of_commands, array_of_argv, array_of_maxprocs, &
                                       array_of_info, root, comm, intercomm, array_of_errcodes, &
                                       ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_ptr, c_associated
    USE :: mpi_f08_types, ONLY : MPI_Info, MPI_Comm
    USE :: mpi_f08_link_constants, ONLY : MPI_ARGVS_NULL, MPIR_F08_get_MPI_ARGVS_NULL_c, &
        MPI_ERRCODES_IGNORE, MPIR_F08_get_MPI_ERRCODES_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_Info, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Comm_spawn_multiple_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: count
    CHARACTER(len=*), INTENT(in), TARGET :: array_of_commands(*)
    CHARACTER(len=*), INTENT(in), TARGET :: array_of_argv(count, *)
    INTEGER, INTENT(in) :: array_of_maxprocs(count)
    TYPE(MPI_Info), INTENT(in) :: array_of_info(count)
    INTEGER, INTENT(in) :: root
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Comm), INTENT(out) :: intercomm
    INTEGER, TARGET :: array_of_errcodes(*)
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    TYPE(c_ptr) :: array_of_argv_cptr
    INTEGER(c_int) :: array_of_maxprocs_c(count)
    INTEGER(c_Info) :: array_of_info_c(count)
    INTEGER(c_int) :: root_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Comm) :: intercomm_c
    TYPE(c_ptr) :: array_of_errcodes_cptr
    LOGICAL :: has_errcodes_ignore = .false.
    INTEGER(c_int), TARGET :: array_of_errcodes_c(sum(array_of_maxprocs(1:count)))
    INTEGER(c_int) :: array_of_commands_len
    INTEGER(c_int) :: array_of_argv_len
    INTEGER(c_int) :: ierror_c
    
    array_of_argv_cptr = c_loc(array_of_argv)
    IF (c_associated(array_of_argv_cptr, c_loc(MPI_ARGVS_NULL))) THEN
        array_of_argv_cptr = MPIR_F08_get_MPI_ARGVS_NULL_c()
    END IF
    array_of_errcodes_cptr = c_loc(array_of_errcodes)
    IF (c_associated(array_of_errcodes_cptr, c_loc(MPI_ERRCODES_IGNORE))) THEN
        array_of_errcodes_cptr = MPIR_F08_get_MPI_ERRCODES_IGNORE_c()
        has_errcodes_ignore = .true.
    END IF
    array_of_commands_len = len(array_of_commands)
    array_of_argv_len = len(array_of_argv)
    
    ierror_c = MPIR_Comm_spawn_multiple_c(count, c_loc(array_of_commands), array_of_argv_cptr, &
                                          array_of_maxprocs, array_of_info%MPI_VAL, root, comm%MPI_VAL, &
                                          intercomm%MPI_VAL, array_of_errcodes_cptr, &
                                          array_of_commands_len, array_of_argv_len)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Comm_spawn_multiple_f08

SUBROUTINE MPI_Lookup_name_f08(service_name, info, port_name, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_types, ONLY : MPI_Info
    USE :: mpi_f08_compile_constants, ONLY : MPI_MAX_PORT_NAME
    USE :: mpi_c_interface_types, ONLY : c_Info
    USE :: mpi_c_interface, ONLY : MPIR_Lookup_name_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_f2c, MPIR_Fortran_string_c2f
    
    IMPLICIT NONE
    
    CHARACTER(len=*), INTENT(in) :: service_name
    TYPE(MPI_Info), INTENT(in) :: info
    CHARACTER(len=MPI_MAX_PORT_NAME), INTENT(out) :: port_name
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    character(kind=c_char) :: service_name_c(len_trim(service_name) + 1)
    INTEGER(c_Info) :: info_c
    character(kind=c_char) :: port_name_c(MPI_MAX_PORT_NAME + 1)
    INTEGER(c_int) :: ierror_c
    
    call MPIR_Fortran_string_f2c(service_name, service_name_c)
    
    ierror_c = MPIR_Lookup_name_c(service_name_c, info%MPI_VAL, port_name_c)
    
    call MPIR_Fortran_string_c2f(port_name_c, port_name)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Lookup_name_f08

SUBROUTINE MPI_Open_port_f08(info, port_name, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_types, ONLY : MPI_Info
    USE :: mpi_f08_compile_constants, ONLY : MPI_MAX_PORT_NAME
    USE :: mpi_c_interface_types, ONLY : c_Info
    USE :: mpi_c_interface, ONLY : MPIR_Open_port_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_c2f
    
    IMPLICIT NONE
    
    TYPE(MPI_Info), INTENT(in) :: info
    CHARACTER(len=MPI_MAX_PORT_NAME), INTENT(out) :: port_name
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Info) :: info_c
    character(kind=c_char) :: port_name_c(MPI_MAX_PORT_NAME + 1)
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Open_port_c(info%MPI_VAL, port_name_c)
    
    call MPIR_Fortran_string_c2f(port_name_c, port_name)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Open_port_f08

SUBROUTINE MPI_Publish_name_f08(service_name, info, port_name, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_types, ONLY : MPI_Info
    USE :: mpi_c_interface_types, ONLY : c_Info
    USE :: mpi_c_interface, ONLY : MPIR_Publish_name_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_f2c
    
    IMPLICIT NONE
    
    CHARACTER(len=*), INTENT(in) :: service_name
    TYPE(MPI_Info), INTENT(in) :: info
    CHARACTER(len=*), INTENT(in) :: port_name
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    character(kind=c_char) :: service_name_c(len_trim(service_name) + 1)
    INTEGER(c_Info) :: info_c
    character(kind=c_char) :: port_name_c(len_trim(port_name) + 1)
    INTEGER(c_int) :: ierror_c
    
    call MPIR_Fortran_string_f2c(service_name, service_name_c)
    call MPIR_Fortran_string_f2c(port_name, port_name_c)
    
    ierror_c = MPIR_Publish_name_c(service_name_c, info%MPI_VAL, port_name_c)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Publish_name_f08

SUBROUTINE MPI_Unpublish_name_f08(service_name, info, port_name, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_types, ONLY : MPI_Info
    USE :: mpi_c_interface_types, ONLY : c_Info
    USE :: mpi_c_interface, ONLY : MPIR_Unpublish_name_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_f2c
    
    IMPLICIT NONE
    
    CHARACTER(len=*), INTENT(in) :: service_name
    TYPE(MPI_Info), INTENT(in) :: info
    CHARACTER(len=*), INTENT(in) :: port_name
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    character(kind=c_char) :: service_name_c(len_trim(service_name) + 1)
    INTEGER(c_Info) :: info_c
    character(kind=c_char) :: port_name_c(len_trim(port_name) + 1)
    INTEGER(c_int) :: ierror_c
    
    call MPIR_Fortran_string_f2c(service_name, service_name_c)
    call MPIR_Fortran_string_f2c(port_name, port_name_c)
    
    ierror_c = MPIR_Unpublish_name_c(service_name_c, info%MPI_VAL, port_name_c)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Unpublish_name_f08

SUBROUTINE MPIX_Stream_create_f08(info, stream, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Info, MPIX_Stream
    USE :: mpi_c_interface_types, ONLY : c_Info, c_Stream
    USE :: mpi_c_interface, ONLY : MPIR_Stream_create_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPIX_Stream), INTENT(out) :: stream
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Info) :: info_c
    INTEGER(c_Stream) :: stream_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Stream_create_c(info%MPI_VAL, stream%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Stream_create_f08

SUBROUTINE MPIX_Stream_free_f08(stream, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPIX_Stream
    USE :: mpi_c_interface_types, ONLY : c_Stream
    USE :: mpi_c_interface, ONLY : MPIR_Stream_free_c
    
    IMPLICIT NONE
    
    TYPE(MPIX_Stream), INTENT(inout) :: stream
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Stream) :: stream_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Stream_free_c(stream%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Stream_free_f08

SUBROUTINE MPIX_Stream_comm_create_f08(comm, stream, newcomm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm, MPIX_Stream
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Stream
    USE :: mpi_c_interface, ONLY : MPIR_Stream_comm_create_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPIX_Stream), INTENT(in) :: stream
    TYPE(MPI_Comm), INTENT(out) :: newcomm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Stream) :: stream_c
    INTEGER(c_Comm) :: newcomm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Stream_comm_create_c(comm%MPI_VAL, stream%MPI_VAL, newcomm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Stream_comm_create_f08

SUBROUTINE MPIX_Stream_comm_create_multiplex_f08(comm, count, array_of_streams, newcomm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm, MPIX_Stream
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Stream
    USE :: mpi_c_interface, ONLY : MPIR_Stream_comm_create_multiplex_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(in) :: count
    TYPE(MPIX_Stream), INTENT(in) :: array_of_streams(count)
    TYPE(MPI_Comm), INTENT(out) :: newcomm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: count_c
    INTEGER(c_Stream) :: array_of_streams_c(count)
    INTEGER(c_Comm) :: newcomm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Stream_comm_create_multiplex_c(comm%MPI_VAL, count, array_of_streams%MPI_VAL, &
                                                   newcomm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Stream_comm_create_multiplex_f08

SUBROUTINE MPIX_Comm_get_stream_f08(comm, idx, stream, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm, MPIX_Stream
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Stream
    USE :: mpi_c_interface, ONLY : MPIR_Comm_get_stream_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(in) :: idx
    TYPE(MPIX_Stream), INTENT(out) :: stream
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: idx_c
    INTEGER(c_Stream) :: stream_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Comm_get_stream_c(comm%MPI_VAL, idx, stream%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Comm_get_stream_f08

SUBROUTINE MPIX_Stream_progress_f08(stream, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPIX_Stream
    USE :: mpi_c_interface_types, ONLY : c_Stream
    USE :: mpi_c_interface, ONLY : MPIR_Stream_progress_c
    
    IMPLICIT NONE
    
    TYPE(MPIX_Stream), INTENT(in) :: stream
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Stream) :: stream_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Stream_progress_c(stream%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Stream_progress_f08

SUBROUTINE MPIX_Start_progress_thread_f08(stream, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPIX_Stream
    USE :: mpi_c_interface_types, ONLY : c_Stream
    USE :: mpi_c_interface, ONLY : MPIR_Start_progress_thread_c
    
    IMPLICIT NONE
    
    TYPE(MPIX_Stream), INTENT(in) :: stream
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Stream) :: stream_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Start_progress_thread_c(stream%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Start_progress_thread_f08

SUBROUTINE MPIX_Stop_progress_thread_f08(stream, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPIX_Stream
    USE :: mpi_c_interface_types, ONLY : c_Stream
    USE :: mpi_c_interface, ONLY : MPIR_Stop_progress_thread_c
    
    IMPLICIT NONE
    
    TYPE(MPIX_Stream), INTENT(in) :: stream
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Stream) :: stream_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Stop_progress_thread_c(stream%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Stop_progress_thread_f08

SUBROUTINE MPIX_Stream_send_f08ts(buf, count, datatype, dest, tag, comm, source_stream_index, &
                                  dest_stream_index, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Stream_send_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(in) :: source_stream_index
    INTEGER, INTENT(in) :: dest_stream_index
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: source_stream_index_c
    INTEGER(c_int) :: dest_stream_index_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Stream_send_cdesc(buf, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL, &
                                      source_stream_index, dest_stream_index)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Stream_send_f08ts

SUBROUTINE MPIX_Stream_send_c_f08ts(buf, count, datatype, dest, tag, comm, source_stream_index, &
                                    dest_stream_index, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Stream_send_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(in) :: source_stream_index
    INTEGER, INTENT(in) :: dest_stream_index
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: source_stream_index_c
    INTEGER(c_int) :: dest_stream_index_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Stream_send_cdesc_large(buf, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL, &
                                            source_stream_index, dest_stream_index)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Stream_send_c_f08ts

SUBROUTINE MPIX_Stream_isend_f08ts(buf, count, datatype, dest, tag, comm, source_stream_index, &
                                   dest_stream_index, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Stream_isend_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(in) :: source_stream_index
    INTEGER, INTENT(in) :: dest_stream_index
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: source_stream_index_c
    INTEGER(c_int) :: dest_stream_index_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Stream_isend_cdesc(buf, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL, &
                                       source_stream_index, dest_stream_index, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Stream_isend_f08ts

SUBROUTINE MPIX_Stream_isend_c_f08ts(buf, count, datatype, dest, tag, comm, source_stream_index, &
                                     dest_stream_index, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Stream_isend_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(in) :: source_stream_index
    INTEGER, INTENT(in) :: dest_stream_index
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: source_stream_index_c
    INTEGER(c_int) :: dest_stream_index_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Stream_isend_cdesc_large(buf, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL, &
                                             source_stream_index, dest_stream_index, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Stream_isend_c_f08ts

SUBROUTINE MPIX_Stream_recv_f08ts(buf, count, datatype, source, tag, comm, source_stream_index, &
                                  dest_stream_index, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Stream_recv_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..) :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: source
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(in) :: source_stream_index
    INTEGER, INTENT(in) :: dest_stream_index
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: source_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: source_stream_index_c
    INTEGER(c_int) :: dest_stream_index_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_Stream_recv_cdesc(buf, count, datatype%MPI_VAL, source, tag, comm%MPI_VAL, &
                                          source_stream_index, dest_stream_index, &
                                          MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_Stream_recv_cdesc(buf, count, datatype%MPI_VAL, source, tag, comm%MPI_VAL, &
                                          source_stream_index, dest_stream_index, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Stream_recv_f08ts

SUBROUTINE MPIX_Stream_recv_c_f08ts(buf, count, datatype, source, tag, comm, source_stream_index, &
                                    dest_stream_index, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Status, assignment(=)
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Stream_recv_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: source
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(in) :: source_stream_index
    INTEGER, INTENT(in) :: dest_stream_index
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: source_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: source_stream_index_c
    INTEGER(c_int) :: dest_stream_index_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_Stream_recv_cdesc_large(buf, count, datatype%MPI_VAL, source, tag, comm%MPI_VAL, &
                                                source_stream_index, dest_stream_index, &
                                                MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_Stream_recv_cdesc_large(buf, count, datatype%MPI_VAL, source, tag, comm%MPI_VAL, &
                                                source_stream_index, dest_stream_index, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Stream_recv_c_f08ts

SUBROUTINE MPIX_Stream_irecv_f08ts(buf, count, datatype, source, tag, comm, source_stream_index, &
                                   dest_stream_index, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Stream_irecv_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: source
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(in) :: source_stream_index
    INTEGER, INTENT(in) :: dest_stream_index
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: source_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: source_stream_index_c
    INTEGER(c_int) :: dest_stream_index_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Stream_irecv_cdesc(buf, count, datatype%MPI_VAL, source, tag, comm%MPI_VAL, &
                                       source_stream_index, dest_stream_index, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Stream_irecv_f08ts

SUBROUTINE MPIX_Stream_irecv_c_f08ts(buf, count, datatype, source, tag, comm, source_stream_index, &
                                     dest_stream_index, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Stream_irecv_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: source
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(in) :: source_stream_index
    INTEGER, INTENT(in) :: dest_stream_index
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: source_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: source_stream_index_c
    INTEGER(c_int) :: dest_stream_index_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Stream_irecv_cdesc_large(buf, count, datatype%MPI_VAL, source, tag, comm%MPI_VAL, &
                                             source_stream_index, dest_stream_index, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Stream_irecv_c_f08ts

SUBROUTINE MPIX_Send_enqueue_f08ts(buf, count, datatype, dest, tag, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Send_enqueue_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Send_enqueue_cdesc(buf, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Send_enqueue_f08ts

SUBROUTINE MPIX_Send_enqueue_c_f08ts(buf, count, datatype, dest, tag, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Send_enqueue_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Send_enqueue_cdesc_large(buf, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Send_enqueue_c_f08ts

SUBROUTINE MPIX_Recv_enqueue_f08ts(buf, count, datatype, source, tag, comm, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Recv_enqueue_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..) :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: source
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: source_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_Recv_enqueue_cdesc(buf, count, datatype%MPI_VAL, source, tag, comm%MPI_VAL, &
                                           MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_Recv_enqueue_cdesc(buf, count, datatype%MPI_VAL, source, tag, comm%MPI_VAL, &
                                           c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Recv_enqueue_f08ts

SUBROUTINE MPIX_Recv_enqueue_c_f08ts(buf, count, datatype, source, tag, comm, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Status, assignment(=)
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Recv_enqueue_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: source
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: source_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_Recv_enqueue_cdesc_large(buf, count, datatype%MPI_VAL, source, tag, comm%MPI_VAL, &
                                                 MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_Recv_enqueue_cdesc_large(buf, count, datatype%MPI_VAL, source, tag, comm%MPI_VAL, &
                                                 c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Recv_enqueue_c_f08ts

SUBROUTINE MPIX_Isend_enqueue_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Isend_enqueue_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Isend_enqueue_cdesc(buf, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL, &
                                        request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Isend_enqueue_f08ts

SUBROUTINE MPIX_Isend_enqueue_c_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Isend_enqueue_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: dest
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: dest_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Isend_enqueue_cdesc_large(buf, count, datatype%MPI_VAL, dest, tag, comm%MPI_VAL, &
                                              request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Isend_enqueue_c_f08ts

SUBROUTINE MPIX_Irecv_enqueue_f08ts(buf, count, datatype, source, tag, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Irecv_enqueue_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..) :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: source
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: source_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Irecv_enqueue_cdesc(buf, count, datatype%MPI_VAL, source, tag, comm%MPI_VAL, &
                                        request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Irecv_enqueue_f08ts

SUBROUTINE MPIX_Irecv_enqueue_c_f08ts(buf, count, datatype, source, tag, comm, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_Irecv_enqueue_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, INTENT(in) :: source
    INTEGER, INTENT(in) :: tag
    TYPE(MPI_Comm), INTENT(in) :: comm
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: source_c
    INTEGER(c_int) :: tag_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Irecv_enqueue_cdesc_large(buf, count, datatype%MPI_VAL, source, tag, comm%MPI_VAL, &
                                              request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Irecv_enqueue_c_f08ts

SUBROUTINE MPIX_Wait_enqueue_f08(request, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_Request, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Wait_enqueue_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Request), INTENT(inout) :: request
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Request) :: request_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_Wait_enqueue_c(request%MPI_VAL, MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_Wait_enqueue_c(request%MPI_VAL, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Wait_enqueue_f08

SUBROUTINE MPIX_Waitall_enqueue_f08(count, array_of_requests, array_of_statuses, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUSES_IGNORE, MPIR_F08_get_MPI_STATUSES_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_Request, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_Waitall_enqueue_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Request), INTENT(inout) :: array_of_requests(count)
    TYPE(MPI_Status), INTENT(out), TARGET :: array_of_statuses(*)
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Request) :: array_of_requests_c(count)
    TYPE(c_Status), TARGET :: array_of_statuses_c(count)
    INTEGER(c_int) :: ierror_c
    
    IF (c_associated(c_loc(array_of_statuses), c_loc(MPI_STATUSES_IGNORE))) THEN
        ierror_c = MPIR_Waitall_enqueue_c(count, array_of_requests%MPI_VAL, &
                                          MPIR_F08_get_MPI_STATUSES_IGNORE_c())
    ELSE
        ierror_c = MPIR_Waitall_enqueue_c(count, array_of_requests%MPI_VAL, c_loc(array_of_statuses))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Waitall_enqueue_f08

SUBROUTINE MPIX_Allreduce_enqueue_f08ts(sendbuf, recvbuf, count, datatype, op, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Allreduce_enqueue_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Allreduce_enqueue_cdesc(sendbuf, recvbuf, count, datatype%MPI_VAL, op%MPI_VAL, &
                                            comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Allreduce_enqueue_f08ts

SUBROUTINE MPIX_Allreduce_enqueue_c_f08ts(sendbuf, recvbuf, count, datatype, op, comm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Allreduce_enqueue_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Op), INTENT(in) :: op
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Op) :: op_c
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Allreduce_enqueue_cdesc_large(sendbuf, recvbuf, count, datatype%MPI_VAL, op%MPI_VAL, &
                                                  comm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Allreduce_enqueue_c_f08ts

SUBROUTINE MPIX_Threadcomm_init_f08(comm, num_threads, newthreadcomm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Threadcomm_init_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(in) :: num_threads
    TYPE(MPI_Comm), INTENT(out) :: newthreadcomm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: num_threads_c
    INTEGER(c_Comm) :: newthreadcomm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Threadcomm_init_c(comm%MPI_VAL, num_threads, newthreadcomm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Threadcomm_init_f08

SUBROUTINE MPIX_Threadcomm_free_f08(threadcomm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Threadcomm_free_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(inout) :: threadcomm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: threadcomm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Threadcomm_free_c(threadcomm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Threadcomm_free_f08

SUBROUTINE MPIX_Threadcomm_start_f08(threadcomm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Threadcomm_start_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: threadcomm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: threadcomm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Threadcomm_start_c(threadcomm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Threadcomm_start_f08

SUBROUTINE MPIX_Threadcomm_finish_f08(threadcomm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Threadcomm_finish_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: threadcomm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: threadcomm_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Threadcomm_finish_c(threadcomm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPIX_Threadcomm_finish_f08

FUNCTION MPI_Wtick_f08() result(res)
    USE :: mpi_c_interface, ONLY : MPIR_Wtick_c
    
    IMPLICIT NONE
    
    DOUBLE PRECISION :: res
    
    
    res = MPIR_Wtick_c()
    
END FUNCTION MPI_Wtick_f08

FUNCTION MPI_Wtime_f08() result(res)
    USE :: mpi_c_interface, ONLY : MPIR_Wtime_c
    
    IMPLICIT NONE
    
    DOUBLE PRECISION :: res
    
    
    res = MPIR_Wtime_c()
    
END FUNCTION MPI_Wtime_f08

SUBROUTINE MPI_Cart_coords_f08(comm, rank, maxdims, coords, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Cart_coords_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(in) :: rank
    INTEGER, INTENT(in) :: maxdims
    INTEGER, INTENT(out) :: coords(maxdims)
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: rank_c
    INTEGER(c_int) :: maxdims_c
    INTEGER(c_int) :: coords_c(maxdims)
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Cart_coords_c(comm%MPI_VAL, rank, maxdims, coords)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Cart_coords_f08

SUBROUTINE MPI_Cart_create_f08(comm_old, ndims, dims, periods, reorder, comm_cart, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Cart_create_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm_old
    INTEGER, INTENT(in) :: ndims
    INTEGER, INTENT(in) :: dims(ndims)
    LOGICAL, INTENT(in) :: periods(ndims)
    LOGICAL, INTENT(in) :: reorder
    TYPE(MPI_Comm), INTENT(out) :: comm_cart
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_old_c
    INTEGER(c_int) :: ndims_c
    INTEGER(c_int) :: dims_c(ndims)
    INTEGER(c_int) :: periods_c(ndims)
    INTEGER(c_int) :: reorder_c
    INTEGER(c_Comm) :: comm_cart_c
    INTEGER(c_int) :: ierror_c
    
    periods_c = merge(1, 0, periods)
    IF (reorder) THEN
        reorder_c = 1
    ELSE
        reorder_c = 0
    END IF
    
    ierror_c = MPIR_Cart_create_c(comm_old%MPI_VAL, ndims, dims, periods_c, reorder_c, &
                                  comm_cart%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Cart_create_f08

SUBROUTINE MPI_Cart_get_f08(comm, maxdims, dims, periods, coords, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Cart_get_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(in) :: maxdims
    INTEGER, INTENT(out) :: dims(maxdims)
    LOGICAL, INTENT(out) :: periods(maxdims)
    INTEGER, INTENT(out) :: coords(maxdims)
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: maxdims_c
    INTEGER(c_int) :: dims_c(maxdims)
    INTEGER(c_int) :: periods_c(maxdims)
    INTEGER(c_int) :: coords_c(maxdims)
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Cart_get_c(comm%MPI_VAL, maxdims, dims, periods_c, coords)
    
    periods = (periods_c /= 0)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Cart_get_f08

SUBROUTINE MPI_Cart_map_f08(comm, ndims, dims, periods, newrank, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Cart_map_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(in) :: ndims
    INTEGER, INTENT(in) :: dims(ndims)
    LOGICAL, INTENT(in) :: periods(ndims)
    INTEGER, INTENT(out) :: newrank
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ndims_c
    INTEGER(c_int) :: dims_c(ndims)
    INTEGER(c_int) :: periods_c(ndims)
    INTEGER(c_int) :: newrank_c
    INTEGER(c_int) :: ierror_c
    
    periods_c = merge(1, 0, periods)
    
    ierror_c = MPIR_Cart_map_c(comm%MPI_VAL, ndims, dims, periods_c, newrank)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Cart_map_f08

SUBROUTINE MPI_Cart_rank_f08(comm, coords, rank, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Cart_rank_c, MPIR_Cartdim_get_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(in) :: coords(*)
    INTEGER, INTENT(out) :: rank
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int), allocatable, dimension(:) :: coords_c
    INTEGER(c_int) :: err, length
    INTEGER(c_int) :: rank_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Cart_rank_c(comm%MPI_VAL, coords, rank)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Cart_rank_f08

SUBROUTINE MPI_Cart_shift_f08(comm, direction, disp, rank_source, rank_dest, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Cart_shift_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(in) :: direction
    INTEGER, INTENT(in) :: disp
    INTEGER, INTENT(out) :: rank_source
    INTEGER, INTENT(out) :: rank_dest
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: direction_c
    INTEGER(c_int) :: disp_c
    INTEGER(c_int) :: rank_source_c
    INTEGER(c_int) :: rank_dest_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Cart_shift_c(comm%MPI_VAL, direction, disp, rank_source, rank_dest)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Cart_shift_f08

SUBROUTINE MPI_Cart_sub_f08(comm, remain_dims, newcomm, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Cart_sub_c, MPIR_Cartdim_get_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    LOGICAL, INTENT(in) :: remain_dims(*)
    TYPE(MPI_Comm), INTENT(out) :: newcomm
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int), allocatable, dimension(:) :: remain_dims_c
    INTEGER(c_int) :: err, length
    INTEGER(c_Comm) :: newcomm_c
    INTEGER(c_int) :: ierror_c
    
    comm_c = comm%MPI_VAL
    err = MPIR_Cartdim_get_c(comm_c, length)
    remain_dims_c = merge(1, 0, remain_dims(1:length))
    
    ierror_c = MPIR_Cart_sub_c(comm%MPI_VAL, remain_dims_c, newcomm%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Cart_sub_f08

SUBROUTINE MPI_Cartdim_get_f08(comm, ndims, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Cartdim_get_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(out) :: ndims
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: ndims_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Cartdim_get_c(comm%MPI_VAL, ndims)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Cartdim_get_f08

SUBROUTINE MPI_Dims_create_f08(nnodes, ndims, dims, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface, ONLY : MPIR_Dims_create_c
    
    IMPLICIT NONE
    
    INTEGER, INTENT(in) :: nnodes
    INTEGER, INTENT(in) :: ndims
    INTEGER, INTENT(inout) :: dims(ndims)
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: nnodes_c
    INTEGER(c_int) :: ndims_c
    INTEGER(c_int) :: dims_c(ndims)
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Dims_create_c(nnodes, ndims, dims)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Dims_create_f08

SUBROUTINE MPI_Dist_graph_create_f08(comm_old, n, sources, degrees, destinations, weights, info, &
                                     reorder, comm_dist_graph, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Info
    USE :: mpi_f08_link_constants, ONLY : MPI_UNWEIGHTED, MPIR_F08_get_MPI_UNWEIGHTED_c, &
        MPI_WEIGHTS_EMPTY, MPIR_F08_get_MPI_WEIGHTS_EMPTY_c
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Info
    USE :: mpi_c_interface, ONLY : MPIR_Dist_graph_create_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm_old
    INTEGER, INTENT(in) :: n
    INTEGER, INTENT(in) :: sources(n)
    INTEGER, INTENT(in) :: degrees(n)
    INTEGER, INTENT(in) :: destinations(*)
    INTEGER, INTENT(in), TARGET :: weights(*)
    TYPE(MPI_Info), INTENT(in) :: info
    LOGICAL, INTENT(in) :: reorder
    TYPE(MPI_Comm), INTENT(out) :: comm_dist_graph
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_old_c
    INTEGER(c_int) :: n_c
    INTEGER(c_int) :: sources_c(n)
    INTEGER(c_int) :: degrees_c(n)
    INTEGER(c_int) :: destinations_c(sum(degrees))
    TYPE(c_ptr) :: weights_cptr
    LOGICAL :: has_weights = .false.
    INTEGER(c_int), TARGET :: weights_c(sum(degrees))
    INTEGER(c_Info) :: info_c
    INTEGER(c_int) :: reorder_c
    INTEGER(c_Comm) :: comm_dist_graph_c
    INTEGER(c_int) :: ierror_c
    
    weights_cptr = c_loc(weights)
    IF (c_associated(weights_cptr, c_loc(MPI_UNWEIGHTED))) THEN
        weights_cptr = MPIR_F08_get_MPI_UNWEIGHTED_c()
    ELSE IF (c_associated(weights_cptr, c_loc(MPI_WEIGHTS_EMPTY))) THEN
        weights_cptr = MPIR_F08_get_MPI_WEIGHTS_EMPTY_c()
    ELSE
        weights_cptr = c_loc(weights)
        has_weights = .true.
    END IF
    IF (reorder) THEN
        reorder_c = 1
    ELSE
        reorder_c = 0
    END IF
    
    ierror_c = MPIR_Dist_graph_create_c(comm_old%MPI_VAL, n, sources, degrees, destinations, &
                                        weights_cptr, info%MPI_VAL, reorder_c, comm_dist_graph%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Dist_graph_create_f08

SUBROUTINE MPI_Dist_graph_create_adjacent_f08(comm_old, indegree, sources, sourceweights, outdegree, &
                                              destinations, destweights, info, reorder, &
                                              comm_dist_graph, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Info
    USE :: mpi_f08_link_constants, ONLY : MPI_UNWEIGHTED, MPIR_F08_get_MPI_UNWEIGHTED_c, &
        MPI_WEIGHTS_EMPTY, MPIR_F08_get_MPI_WEIGHTS_EMPTY_c
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Info
    USE :: mpi_c_interface, ONLY : MPIR_Dist_graph_create_adjacent_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm_old
    INTEGER, INTENT(in) :: indegree
    INTEGER, INTENT(in) :: sources(indegree)
    INTEGER, INTENT(in), TARGET :: sourceweights(*)
    INTEGER, INTENT(in) :: outdegree
    INTEGER, INTENT(in) :: destinations(outdegree)
    INTEGER, INTENT(in), TARGET :: destweights(*)
    TYPE(MPI_Info), INTENT(in) :: info
    LOGICAL, INTENT(in) :: reorder
    TYPE(MPI_Comm), INTENT(out) :: comm_dist_graph
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_old_c
    INTEGER(c_int) :: indegree_c
    INTEGER(c_int) :: sources_c(indegree)
    TYPE(c_ptr) :: sourceweights_cptr
    LOGICAL :: has_sourceweights = .false.
    INTEGER(c_int), TARGET :: sourceweights_c(indegree)
    INTEGER(c_int) :: outdegree_c
    INTEGER(c_int) :: destinations_c(outdegree)
    TYPE(c_ptr) :: destweights_cptr
    LOGICAL :: has_destweights = .false.
    INTEGER(c_int), TARGET :: destweights_c(outdegree)
    INTEGER(c_Info) :: info_c
    INTEGER(c_int) :: reorder_c
    INTEGER(c_Comm) :: comm_dist_graph_c
    INTEGER(c_int) :: ierror_c
    
    sourceweights_cptr = c_loc(sourceweights)
    IF (c_associated(sourceweights_cptr, c_loc(MPI_UNWEIGHTED))) THEN
        sourceweights_cptr = MPIR_F08_get_MPI_UNWEIGHTED_c()
    ELSE IF (c_associated(sourceweights_cptr, c_loc(MPI_WEIGHTS_EMPTY))) THEN
        sourceweights_cptr = MPIR_F08_get_MPI_WEIGHTS_EMPTY_c()
    ELSE
        sourceweights_cptr = c_loc(sourceweights)
        has_sourceweights = .true.
    END IF
    destweights_cptr = c_loc(destweights)
    IF (c_associated(destweights_cptr, c_loc(MPI_UNWEIGHTED))) THEN
        destweights_cptr = MPIR_F08_get_MPI_UNWEIGHTED_c()
    ELSE IF (c_associated(destweights_cptr, c_loc(MPI_WEIGHTS_EMPTY))) THEN
        destweights_cptr = MPIR_F08_get_MPI_WEIGHTS_EMPTY_c()
    ELSE
        destweights_cptr = c_loc(destweights)
        has_destweights = .true.
    END IF
    IF (reorder) THEN
        reorder_c = 1
    ELSE
        reorder_c = 0
    END IF
    
    ierror_c = MPIR_Dist_graph_create_adjacent_c(comm_old%MPI_VAL, indegree, sources, &
                                                 sourceweights_cptr, outdegree, destinations, &
                                                 destweights_cptr, info%MPI_VAL, reorder_c, &
                                                 comm_dist_graph%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Dist_graph_create_adjacent_f08

SUBROUTINE MPI_Dist_graph_neighbors_f08(comm, maxindegree, sources, sourceweights, maxoutdegree, &
                                        destinations, destweights, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_f08_link_constants, ONLY : MPI_UNWEIGHTED, MPIR_F08_get_MPI_UNWEIGHTED_c, &
        MPI_WEIGHTS_EMPTY, MPIR_F08_get_MPI_WEIGHTS_EMPTY_c
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Dist_graph_neighbors_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(in) :: maxindegree
    INTEGER, INTENT(out) :: sources(maxindegree)
    INTEGER, TARGET :: sourceweights(*)
    INTEGER, INTENT(in) :: maxoutdegree
    INTEGER, INTENT(out) :: destinations(maxoutdegree)
    INTEGER, TARGET :: destweights(*)
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: maxindegree_c
    INTEGER(c_int) :: sources_c(maxindegree)
    TYPE(c_ptr) :: sourceweights_cptr
    LOGICAL :: has_sourceweights = .false.
    INTEGER(c_int), TARGET :: sourceweights_c(maxindegree)
    INTEGER(c_int) :: maxoutdegree_c
    INTEGER(c_int) :: destinations_c(maxoutdegree)
    TYPE(c_ptr) :: destweights_cptr
    LOGICAL :: has_destweights = .false.
    INTEGER(c_int), TARGET :: destweights_c(maxoutdegree)
    INTEGER(c_int) :: ierror_c
    
    sourceweights_cptr = c_loc(sourceweights)
    IF (c_associated(sourceweights_cptr, c_loc(MPI_UNWEIGHTED))) THEN
        sourceweights_cptr = MPIR_F08_get_MPI_UNWEIGHTED_c()
    ELSE IF (c_associated(sourceweights_cptr, c_loc(MPI_WEIGHTS_EMPTY))) THEN
        sourceweights_cptr = MPIR_F08_get_MPI_WEIGHTS_EMPTY_c()
    ELSE
        sourceweights_cptr = c_loc(sourceweights)
        has_sourceweights = .true.
    END IF
    destweights_cptr = c_loc(destweights)
    IF (c_associated(destweights_cptr, c_loc(MPI_UNWEIGHTED))) THEN
        destweights_cptr = MPIR_F08_get_MPI_UNWEIGHTED_c()
    ELSE IF (c_associated(destweights_cptr, c_loc(MPI_WEIGHTS_EMPTY))) THEN
        destweights_cptr = MPIR_F08_get_MPI_WEIGHTS_EMPTY_c()
    ELSE
        destweights_cptr = c_loc(destweights)
        has_destweights = .true.
    END IF
    
    ierror_c = MPIR_Dist_graph_neighbors_c(comm%MPI_VAL, maxindegree, sources, sourceweights_cptr, &
                                           maxoutdegree, destinations, destweights_cptr)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Dist_graph_neighbors_f08

SUBROUTINE MPI_Dist_graph_neighbors_count_f08(comm, indegree, outdegree, weighted, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Dist_graph_neighbors_count_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(out) :: indegree
    INTEGER, INTENT(out) :: outdegree
    LOGICAL, INTENT(out) :: weighted
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: indegree_c
    INTEGER(c_int) :: outdegree_c
    INTEGER(c_int) :: weighted_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Dist_graph_neighbors_count_c(comm%MPI_VAL, indegree, outdegree, weighted_c)
    
    weighted = (weighted_c /= 0)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Dist_graph_neighbors_count_f08

SUBROUTINE MPI_Get_hw_resource_info_f08(hw_info, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Info
    USE :: mpi_c_interface_types, ONLY : c_Info
    USE :: mpi_c_interface, ONLY : MPIR_Get_hw_resource_info_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Info), INTENT(out) :: hw_info
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Info) :: hw_info_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Get_hw_resource_info_c(hw_info%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Get_hw_resource_info_f08

SUBROUTINE MPI_Graph_create_f08(comm_old, nnodes, indx, edges, reorder, comm_graph, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Graph_create_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm_old
    INTEGER, INTENT(in) :: nnodes
    INTEGER, INTENT(in) :: indx(nnodes)
    INTEGER, INTENT(in) :: edges(*)
    LOGICAL, INTENT(in) :: reorder
    TYPE(MPI_Comm), INTENT(out) :: comm_graph
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_old_c
    INTEGER(c_int) :: nnodes_c
    INTEGER(c_int) :: indx_c(nnodes)
    INTEGER(c_int) :: edges_c(indx(nnodes))
    INTEGER(c_int) :: reorder_c
    INTEGER(c_Comm) :: comm_graph_c
    INTEGER(c_int) :: ierror_c
    
    IF (reorder) THEN
        reorder_c = 1
    ELSE
        reorder_c = 0
    END IF
    
    ierror_c = MPIR_Graph_create_c(comm_old%MPI_VAL, nnodes, indx, edges, reorder_c, &
                                   comm_graph%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Graph_create_f08

SUBROUTINE MPI_Graph_get_f08(comm, maxindex, maxedges, indx, edges, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Graph_get_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(in) :: maxindex
    INTEGER, INTENT(in) :: maxedges
    INTEGER, INTENT(out) :: indx(maxindex)
    INTEGER, INTENT(out) :: edges(maxedges)
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: maxindex_c
    INTEGER(c_int) :: maxedges_c
    INTEGER(c_int) :: indx_c(maxindex)
    INTEGER(c_int) :: edges_c(maxedges)
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Graph_get_c(comm%MPI_VAL, maxindex, maxedges, indx, edges)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Graph_get_f08

SUBROUTINE MPI_Graph_map_f08(comm, nnodes, indx, edges, newrank, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Graph_map_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(in) :: nnodes
    INTEGER, INTENT(in) :: indx(nnodes)
    INTEGER, INTENT(in) :: edges(*)
    INTEGER, INTENT(out) :: newrank
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: nnodes_c
    INTEGER(c_int) :: indx_c(nnodes)
    INTEGER(c_int) :: edges_c(indx(nnodes))
    INTEGER(c_int) :: newrank_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Graph_map_c(comm%MPI_VAL, nnodes, indx, edges, newrank)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Graph_map_f08

SUBROUTINE MPI_Graph_neighbors_f08(comm, rank, maxneighbors, neighbors, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Graph_neighbors_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(in) :: rank
    INTEGER, INTENT(in) :: maxneighbors
    INTEGER, INTENT(out) :: neighbors(maxneighbors)
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: rank_c
    INTEGER(c_int) :: maxneighbors_c
    INTEGER(c_int) :: neighbors_c(maxneighbors)
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Graph_neighbors_c(comm%MPI_VAL, rank, maxneighbors, neighbors)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Graph_neighbors_f08

SUBROUTINE MPI_Graph_neighbors_count_f08(comm, rank, nneighbors, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Graph_neighbors_count_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(in) :: rank
    INTEGER, INTENT(out) :: nneighbors
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: rank_c
    INTEGER(c_int) :: nneighbors_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Graph_neighbors_count_c(comm%MPI_VAL, rank, nneighbors)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Graph_neighbors_count_f08

SUBROUTINE MPI_Graphdims_get_f08(comm, nnodes, nedges, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Graphdims_get_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(out) :: nnodes
    INTEGER, INTENT(out) :: nedges
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: nnodes_c
    INTEGER(c_int) :: nedges_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Graphdims_get_c(comm%MPI_VAL, nnodes, nedges)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Graphdims_get_f08

SUBROUTINE MPI_Topo_test_f08(comm, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm
    USE :: mpi_c_interface_types, ONLY : c_Comm
    USE :: mpi_c_interface, ONLY : MPIR_Topo_test_c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    INTEGER, INTENT(out) :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    INTEGER(c_int) :: status_c
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_Topo_test_c(comm%MPI_VAL, status)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Topo_test_f08

SUBROUTINE MPI_File_close_f08(fh, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_File_c2f
    USE :: mpi_c_interface_types, ONLY : c_File
    USE :: mpi_c_interface, ONLY : MPIR_File_close_c
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(inout) :: fh
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_close_c(fh_c)
    
    fh%MPI_VAL = MPI_File_c2f(fh_c)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_close_f08

SUBROUTINE MPI_File_delete_f08(filename, info, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_types, ONLY : MPI_Info
    USE :: mpi_c_interface_types, ONLY : c_Info
    USE :: mpi_c_interface, ONLY : MPIR_File_delete_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_f2c
    
    IMPLICIT NONE
    
    CHARACTER(len=*), INTENT(in) :: filename
    TYPE(MPI_Info), INTENT(in) :: info
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    character(kind=c_char) :: filename_c(len_trim(filename) + 1)
    INTEGER(c_Info) :: info_c
    INTEGER(c_int) :: ierror_c
    
    call MPIR_Fortran_string_f2c(filename, filename_c)
    
    ierror_c = MPIR_File_delete_c(filename_c, info%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_delete_f08

SUBROUTINE MPI_File_get_amode_f08(fh, amode, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c
    USE :: mpi_c_interface_types, ONLY : c_File
    USE :: mpi_c_interface, ONLY : MPIR_File_get_amode_c
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER, INTENT(out) :: amode
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: amode_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_get_amode_c(fh_c, amode)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_get_amode_f08

SUBROUTINE MPI_File_get_atomicity_f08(fh, flag, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c
    USE :: mpi_c_interface_types, ONLY : c_File
    USE :: mpi_c_interface, ONLY : MPIR_File_get_atomicity_c
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    LOGICAL, INTENT(out) :: flag
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: flag_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_get_atomicity_c(fh_c, flag_c)
    
    flag = (flag_c /= 0)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_get_atomicity_f08

SUBROUTINE MPI_File_get_byte_offset_f08(fh, offset, disp, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File
    USE :: mpi_c_interface, ONLY : MPIR_File_get_byte_offset_c
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(out) :: disp
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_get_byte_offset_c(fh_c, offset, disp)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_get_byte_offset_f08

SUBROUTINE MPI_File_get_group_f08(fh, group, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Group
    USE :: mpi_c_interface_types, ONLY : c_File, c_Group
    USE :: mpi_c_interface, ONLY : MPIR_File_get_group_c
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(MPI_Group), INTENT(out) :: group
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Group) :: group_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_get_group_c(fh_c, group%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_get_group_f08

SUBROUTINE MPI_File_get_info_f08(fh, info_used, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Info
    USE :: mpi_c_interface_types, ONLY : c_File, c_Info
    USE :: mpi_c_interface, ONLY : MPIR_File_get_info_c
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(MPI_Info), INTENT(out) :: info_used
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Info) :: info_used_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_get_info_c(fh_c, info_used%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_get_info_f08

SUBROUTINE MPI_File_get_position_f08(fh, offset, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File
    USE :: mpi_c_interface, ONLY : MPIR_File_get_position_c
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(out) :: offset
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_get_position_c(fh_c, offset)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_get_position_f08

SUBROUTINE MPI_File_get_position_shared_f08(fh, offset, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File
    USE :: mpi_c_interface, ONLY : MPIR_File_get_position_shared_c
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(out) :: offset
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_get_position_shared_c(fh_c, offset)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_get_position_shared_f08

SUBROUTINE MPI_File_get_size_f08(fh, size, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File
    USE :: mpi_c_interface, ONLY : MPIR_File_get_size_c
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(out) :: size
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_get_size_c(fh_c, size)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_get_size_f08

SUBROUTINE MPI_File_get_type_extent_f08(fh, datatype, extent, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_File_get_type_extent_c
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: extent
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_get_type_extent_c(fh_c, datatype%MPI_VAL, extent)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_get_type_extent_f08

SUBROUTINE MPI_File_get_view_f08(fh, disp, etype, filetype, datarep, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_File_get_view_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_c2f
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(out) :: disp
    TYPE(MPI_Datatype), INTENT(out) :: etype
    TYPE(MPI_Datatype), INTENT(out) :: filetype
    CHARACTER(len=*), INTENT(out) :: datarep
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Datatype) :: etype_c
    INTEGER(c_Datatype) :: filetype_c
    character(kind=c_char) :: datarep_c(len(datarep) + 1)
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_get_view_c(fh_c, disp, etype%MPI_VAL, filetype%MPI_VAL, datarep_c)
    
    call MPIR_Fortran_string_c2f(datarep_c, datarep)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_get_view_f08

SUBROUTINE MPI_File_iread_f08ts(fh, buf, count, datatype, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_File_iread_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_iread_cdesc(fh_c, buf, count, datatype%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_iread_f08ts

SUBROUTINE MPI_File_iread_c_f08ts(fh, buf, count, datatype, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_File_iread_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_iread_cdesc_large(fh_c, buf, count, datatype%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_iread_c_f08ts

SUBROUTINE MPI_File_iread_all_f08ts(fh, buf, count, datatype, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_File_iread_all_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_iread_all_cdesc(fh_c, buf, count, datatype%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_iread_all_f08ts

SUBROUTINE MPI_File_iread_all_c_f08ts(fh, buf, count, datatype, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_File_iread_all_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_iread_all_cdesc_large(fh_c, buf, count, datatype%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_iread_all_c_f08ts

SUBROUTINE MPI_File_iread_at_f08ts(fh, offset, buf, count, datatype, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_File_iread_at_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_iread_at_cdesc(fh_c, offset, buf, count, datatype%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_iread_at_f08ts

SUBROUTINE MPI_File_iread_at_c_f08ts(fh, offset, buf, count, datatype, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND, MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_File_iread_at_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_iread_at_cdesc_large(fh_c, offset, buf, count, datatype%MPI_VAL, &
                                              request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_iread_at_c_f08ts

SUBROUTINE MPI_File_iread_at_all_f08ts(fh, offset, buf, count, datatype, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_File_iread_at_all_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_iread_at_all_cdesc(fh_c, offset, buf, count, datatype%MPI_VAL, &
                                            request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_iread_at_all_f08ts

SUBROUTINE MPI_File_iread_at_all_c_f08ts(fh, offset, buf, count, datatype, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND, MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_File_iread_at_all_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_iread_at_all_cdesc_large(fh_c, offset, buf, count, datatype%MPI_VAL, &
                                                  request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_iread_at_all_c_f08ts

SUBROUTINE MPI_File_iread_shared_f08ts(fh, buf, count, datatype, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_File_iread_shared_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_iread_shared_cdesc(fh_c, buf, count, datatype%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_iread_shared_f08ts

SUBROUTINE MPI_File_iread_shared_c_f08ts(fh, buf, count, datatype, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_File_iread_shared_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_iread_shared_cdesc_large(fh_c, buf, count, datatype%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_iread_shared_c_f08ts

SUBROUTINE MPI_File_iwrite_f08ts(fh, buf, count, datatype, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_File_iwrite_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_iwrite_cdesc(fh_c, buf, count, datatype%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_iwrite_f08ts

SUBROUTINE MPI_File_iwrite_c_f08ts(fh, buf, count, datatype, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_File_iwrite_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_iwrite_cdesc_large(fh_c, buf, count, datatype%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_iwrite_c_f08ts

SUBROUTINE MPI_File_iwrite_all_f08ts(fh, buf, count, datatype, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_File_iwrite_all_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_iwrite_all_cdesc(fh_c, buf, count, datatype%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_iwrite_all_f08ts

SUBROUTINE MPI_File_iwrite_all_c_f08ts(fh, buf, count, datatype, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_File_iwrite_all_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_iwrite_all_cdesc_large(fh_c, buf, count, datatype%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_iwrite_all_c_f08ts

SUBROUTINE MPI_File_iwrite_at_f08ts(fh, offset, buf, count, datatype, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_File_iwrite_at_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_iwrite_at_cdesc(fh_c, offset, buf, count, datatype%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_iwrite_at_f08ts

SUBROUTINE MPI_File_iwrite_at_c_f08ts(fh, offset, buf, count, datatype, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND, MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_File_iwrite_at_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_iwrite_at_cdesc_large(fh_c, offset, buf, count, datatype%MPI_VAL, &
                                               request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_iwrite_at_c_f08ts

SUBROUTINE MPI_File_iwrite_at_all_f08ts(fh, offset, buf, count, datatype, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_File_iwrite_at_all_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_iwrite_at_all_cdesc(fh_c, offset, buf, count, datatype%MPI_VAL, &
                                             request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_iwrite_at_all_f08ts

SUBROUTINE MPI_File_iwrite_at_all_c_f08ts(fh, offset, buf, count, datatype, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND, MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_File_iwrite_at_all_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_iwrite_at_all_cdesc_large(fh_c, offset, buf, count, datatype%MPI_VAL, &
                                                   request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_iwrite_at_all_c_f08ts

SUBROUTINE MPI_File_iwrite_shared_f08ts(fh, buf, count, datatype, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Request
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_File_iwrite_shared_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_iwrite_shared_cdesc(fh_c, buf, count, datatype%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_iwrite_shared_f08ts

SUBROUTINE MPI_File_iwrite_shared_c_f08ts(fh, buf, count, datatype, request, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Request
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    USE :: mpi_c_interface, ONLY : MPIR_File_iwrite_shared_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Request), INTENT(out) :: request
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_Request) :: request_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_iwrite_shared_cdesc_large(fh_c, buf, count, datatype%MPI_VAL, request%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_iwrite_shared_c_f08ts

SUBROUTINE MPI_File_open_f08(comm, filename, amode, info, fh, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Info, MPI_File, MPI_File_c2f
    USE :: mpi_c_interface_types, ONLY : c_Comm, c_Info, c_File
    USE :: mpi_c_interface, ONLY : MPIR_File_open_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_f2c
    
    IMPLICIT NONE
    
    TYPE(MPI_Comm), INTENT(in) :: comm
    CHARACTER(len=*), INTENT(in) :: filename
    INTEGER, INTENT(in) :: amode
    TYPE(MPI_Info), INTENT(in) :: info
    TYPE(MPI_File), INTENT(out) :: fh
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_Comm) :: comm_c
    character(kind=c_char) :: filename_c(len_trim(filename) + 1)
    INTEGER(c_int) :: amode_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: ierror_c
    
    call MPIR_Fortran_string_f2c(filename, filename_c)
    
    ierror_c = MPIR_File_open_c(comm%MPI_VAL, filename_c, amode, info%MPI_VAL, fh_c)
    
    fh%MPI_VAL = MPI_File_c2f(fh_c)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_open_f08

SUBROUTINE MPI_File_preallocate_f08(fh, size, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File
    USE :: mpi_c_interface, ONLY : MPIR_File_preallocate_c
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: size
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_preallocate_c(fh_c, size)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_preallocate_f08

SUBROUTINE MPI_File_read_f08ts(fh, buf, count, datatype, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_File_read_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..) :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_File_read_cdesc(fh_c, buf, count, datatype%MPI_VAL, &
                                        MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_File_read_cdesc(fh_c, buf, count, datatype%MPI_VAL, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_read_f08ts

SUBROUTINE MPI_File_read_c_f08ts(fh, buf, count, datatype, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Status, assignment(=)
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_File_read_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Datatype) :: datatype_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_File_read_cdesc_large(fh_c, buf, count, datatype%MPI_VAL, &
                                              MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_File_read_cdesc_large(fh_c, buf, count, datatype%MPI_VAL, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_read_c_f08ts

SUBROUTINE MPI_File_read_all_f08ts(fh, buf, count, datatype, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_File_read_all_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..) :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_File_read_all_cdesc(fh_c, buf, count, datatype%MPI_VAL, &
                                            MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_File_read_all_cdesc(fh_c, buf, count, datatype%MPI_VAL, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_read_all_f08ts

SUBROUTINE MPI_File_read_all_c_f08ts(fh, buf, count, datatype, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Status, assignment(=)
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_File_read_all_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Datatype) :: datatype_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_File_read_all_cdesc_large(fh_c, buf, count, datatype%MPI_VAL, &
                                                  MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_File_read_all_cdesc_large(fh_c, buf, count, datatype%MPI_VAL, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_read_all_c_f08ts

SUBROUTINE MPI_File_read_all_begin_f08ts(fh, buf, count, datatype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_File_read_all_begin_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_read_all_begin_cdesc(fh_c, buf, count, datatype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_read_all_begin_f08ts

SUBROUTINE MPI_File_read_all_begin_c_f08ts(fh, buf, count, datatype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_File_read_all_begin_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_read_all_begin_cdesc_large(fh_c, buf, count, datatype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_read_all_begin_c_f08ts

SUBROUTINE MPI_File_read_all_end_f08ts(fh, buf, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_File, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_File_read_all_end_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_File_read_all_end_cdesc(fh_c, buf, MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_File_read_all_end_cdesc(fh_c, buf, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_read_all_end_f08ts

SUBROUTINE MPI_File_read_at_f08ts(fh, offset, buf, count, datatype, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Status, assignment(=)
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_File_read_at_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
    TYPE(*), DIMENSION(..) :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_File_read_at_cdesc(fh_c, offset, buf, count, datatype%MPI_VAL, &
                                           MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_File_read_at_cdesc(fh_c, offset, buf, count, datatype%MPI_VAL, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_read_at_f08ts

SUBROUTINE MPI_File_read_at_c_f08ts(fh, offset, buf, count, datatype, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Status, assignment(=)
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND, MPI_COUNT_KIND
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_File_read_at_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Datatype) :: datatype_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_File_read_at_cdesc_large(fh_c, offset, buf, count, datatype%MPI_VAL, &
                                                 MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_File_read_at_cdesc_large(fh_c, offset, buf, count, datatype%MPI_VAL, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_read_at_c_f08ts

SUBROUTINE MPI_File_read_at_all_f08ts(fh, offset, buf, count, datatype, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Status, assignment(=)
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_File_read_at_all_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
    TYPE(*), DIMENSION(..) :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_File_read_at_all_cdesc(fh_c, offset, buf, count, datatype%MPI_VAL, &
                                               MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_File_read_at_all_cdesc(fh_c, offset, buf, count, datatype%MPI_VAL, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_read_at_all_f08ts

SUBROUTINE MPI_File_read_at_all_c_f08ts(fh, offset, buf, count, datatype, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Status, assignment(=)
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND, MPI_COUNT_KIND
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_File_read_at_all_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Datatype) :: datatype_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_File_read_at_all_cdesc_large(fh_c, offset, buf, count, datatype%MPI_VAL, &
                                                     MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_File_read_at_all_cdesc_large(fh_c, offset, buf, count, datatype%MPI_VAL, &
                                                     c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_read_at_all_c_f08ts

SUBROUTINE MPI_File_read_at_all_begin_f08ts(fh, offset, buf, count, datatype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_File_read_at_all_begin_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_read_at_all_begin_cdesc(fh_c, offset, buf, count, datatype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_read_at_all_begin_f08ts

SUBROUTINE MPI_File_read_at_all_begin_c_f08ts(fh, offset, buf, count, datatype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND, MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_File_read_at_all_begin_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_read_at_all_begin_cdesc_large(fh_c, offset, buf, count, datatype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_read_at_all_begin_c_f08ts

SUBROUTINE MPI_File_read_at_all_end_f08ts(fh, buf, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_File, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_File_read_at_all_end_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_File_read_at_all_end_cdesc(fh_c, buf, MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_File_read_at_all_end_cdesc(fh_c, buf, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_read_at_all_end_f08ts

SUBROUTINE MPI_File_read_ordered_f08ts(fh, buf, count, datatype, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_File_read_ordered_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..) :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_File_read_ordered_cdesc(fh_c, buf, count, datatype%MPI_VAL, &
                                                MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_File_read_ordered_cdesc(fh_c, buf, count, datatype%MPI_VAL, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_read_ordered_f08ts

SUBROUTINE MPI_File_read_ordered_c_f08ts(fh, buf, count, datatype, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Status, assignment(=)
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_File_read_ordered_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Datatype) :: datatype_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_File_read_ordered_cdesc_large(fh_c, buf, count, datatype%MPI_VAL, &
                                                      MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_File_read_ordered_cdesc_large(fh_c, buf, count, datatype%MPI_VAL, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_read_ordered_c_f08ts

SUBROUTINE MPI_File_read_ordered_begin_f08ts(fh, buf, count, datatype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_File_read_ordered_begin_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_read_ordered_begin_cdesc(fh_c, buf, count, datatype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_read_ordered_begin_f08ts

SUBROUTINE MPI_File_read_ordered_begin_c_f08ts(fh, buf, count, datatype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_File_read_ordered_begin_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_read_ordered_begin_cdesc_large(fh_c, buf, count, datatype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_read_ordered_begin_c_f08ts

SUBROUTINE MPI_File_read_ordered_end_f08ts(fh, buf, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_File, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_File_read_ordered_end_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_File_read_ordered_end_cdesc(fh_c, buf, MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_File_read_ordered_end_cdesc(fh_c, buf, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_read_ordered_end_f08ts

SUBROUTINE MPI_File_read_shared_f08ts(fh, buf, count, datatype, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_File_read_shared_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..) :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_File_read_shared_cdesc(fh_c, buf, count, datatype%MPI_VAL, &
                                               MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_File_read_shared_cdesc(fh_c, buf, count, datatype%MPI_VAL, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_read_shared_f08ts

SUBROUTINE MPI_File_read_shared_c_f08ts(fh, buf, count, datatype, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Status, assignment(=)
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_File_read_shared_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Datatype) :: datatype_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_File_read_shared_cdesc_large(fh_c, buf, count, datatype%MPI_VAL, &
                                                     MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_File_read_shared_cdesc_large(fh_c, buf, count, datatype%MPI_VAL, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_read_shared_c_f08ts

SUBROUTINE MPI_File_seek_f08(fh, offset, whence, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File
    USE :: mpi_c_interface, ONLY : MPIR_File_seek_c
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
    INTEGER, INTENT(in) :: whence
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: whence_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_seek_c(fh_c, offset, whence)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_seek_f08

SUBROUTINE MPI_File_seek_shared_f08(fh, offset, whence, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File
    USE :: mpi_c_interface, ONLY : MPIR_File_seek_shared_c
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
    INTEGER, INTENT(in) :: whence
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: whence_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_seek_shared_c(fh_c, offset, whence)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_seek_shared_f08

SUBROUTINE MPI_File_set_atomicity_f08(fh, flag, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c
    USE :: mpi_c_interface_types, ONLY : c_File
    USE :: mpi_c_interface, ONLY : MPIR_File_set_atomicity_c
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    LOGICAL, INTENT(in) :: flag
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: flag_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    IF (flag) THEN
        flag_c = 1
    ELSE
        flag_c = 0
    END IF
    
    ierror_c = MPIR_File_set_atomicity_c(fh_c, flag_c)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_set_atomicity_f08

SUBROUTINE MPI_File_set_info_f08(fh, info, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Info
    USE :: mpi_c_interface_types, ONLY : c_File, c_Info
    USE :: mpi_c_interface, ONLY : MPIR_File_set_info_c
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(MPI_Info), INTENT(in) :: info
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Info) :: info_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_set_info_c(fh_c, info%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_set_info_f08

SUBROUTINE MPI_File_set_size_f08(fh, size, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File
    USE :: mpi_c_interface, ONLY : MPIR_File_set_size_c
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: size
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_set_size_c(fh_c, size)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_set_size_f08

SUBROUTINE MPI_File_set_view_f08(fh, disp, etype, filetype, datarep, info, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Info
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Info
    USE :: mpi_c_interface, ONLY : MPIR_File_set_view_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_f2c
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: disp
    TYPE(MPI_Datatype), INTENT(in) :: etype
    TYPE(MPI_Datatype), INTENT(in) :: filetype
    CHARACTER(len=*), INTENT(in) :: datarep
    TYPE(MPI_Info), INTENT(in) :: info
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Datatype) :: etype_c
    INTEGER(c_Datatype) :: filetype_c
    character(kind=c_char) :: datarep_c(len_trim(datarep) + 1)
    INTEGER(c_Info) :: info_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    call MPIR_Fortran_string_f2c(datarep, datarep_c)
    
    ierror_c = MPIR_File_set_view_c(fh_c, disp, etype%MPI_VAL, filetype%MPI_VAL, datarep_c, &
                                    info%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_set_view_f08

SUBROUTINE MPI_File_sync_f08(fh, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c
    USE :: mpi_c_interface_types, ONLY : c_File
    USE :: mpi_c_interface, ONLY : MPIR_File_sync_c
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_sync_c(fh_c)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_sync_f08

SUBROUTINE MPI_File_write_f08ts(fh, buf, count, datatype, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_File_write_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_File_write_cdesc(fh_c, buf, count, datatype%MPI_VAL, &
                                         MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_File_write_cdesc(fh_c, buf, count, datatype%MPI_VAL, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_write_f08ts

SUBROUTINE MPI_File_write_c_f08ts(fh, buf, count, datatype, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Status, assignment(=)
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_File_write_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Datatype) :: datatype_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_File_write_cdesc_large(fh_c, buf, count, datatype%MPI_VAL, &
                                               MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_File_write_cdesc_large(fh_c, buf, count, datatype%MPI_VAL, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_write_c_f08ts

SUBROUTINE MPI_File_write_all_f08ts(fh, buf, count, datatype, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_File_write_all_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_File_write_all_cdesc(fh_c, buf, count, datatype%MPI_VAL, &
                                             MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_File_write_all_cdesc(fh_c, buf, count, datatype%MPI_VAL, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_write_all_f08ts

SUBROUTINE MPI_File_write_all_c_f08ts(fh, buf, count, datatype, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Status, assignment(=)
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_File_write_all_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Datatype) :: datatype_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_File_write_all_cdesc_large(fh_c, buf, count, datatype%MPI_VAL, &
                                                   MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_File_write_all_cdesc_large(fh_c, buf, count, datatype%MPI_VAL, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_write_all_c_f08ts

SUBROUTINE MPI_File_write_all_begin_f08ts(fh, buf, count, datatype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_File_write_all_begin_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_write_all_begin_cdesc(fh_c, buf, count, datatype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_write_all_begin_f08ts

SUBROUTINE MPI_File_write_all_begin_c_f08ts(fh, buf, count, datatype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_File_write_all_begin_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_write_all_begin_cdesc_large(fh_c, buf, count, datatype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_write_all_begin_c_f08ts

SUBROUTINE MPI_File_write_all_end_f08ts(fh, buf, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_File, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_File_write_all_end_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_File_write_all_end_cdesc(fh_c, buf, MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_File_write_all_end_cdesc(fh_c, buf, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_write_all_end_f08ts

SUBROUTINE MPI_File_write_at_f08ts(fh, offset, buf, count, datatype, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Status, assignment(=)
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_File_write_at_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_File_write_at_cdesc(fh_c, offset, buf, count, datatype%MPI_VAL, &
                                            MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_File_write_at_cdesc(fh_c, offset, buf, count, datatype%MPI_VAL, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_write_at_f08ts

SUBROUTINE MPI_File_write_at_c_f08ts(fh, offset, buf, count, datatype, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Status, assignment(=)
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND, MPI_COUNT_KIND
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_File_write_at_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Datatype) :: datatype_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_File_write_at_cdesc_large(fh_c, offset, buf, count, datatype%MPI_VAL, &
                                                  MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_File_write_at_cdesc_large(fh_c, offset, buf, count, datatype%MPI_VAL, &
                                                  c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_write_at_c_f08ts

SUBROUTINE MPI_File_write_at_all_f08ts(fh, offset, buf, count, datatype, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Status, assignment(=)
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_File_write_at_all_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_File_write_at_all_cdesc(fh_c, offset, buf, count, datatype%MPI_VAL, &
                                                MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_File_write_at_all_cdesc(fh_c, offset, buf, count, datatype%MPI_VAL, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_write_at_all_f08ts

SUBROUTINE MPI_File_write_at_all_c_f08ts(fh, offset, buf, count, datatype, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Status, assignment(=)
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND, MPI_COUNT_KIND
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_File_write_at_all_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Datatype) :: datatype_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_File_write_at_all_cdesc_large(fh_c, offset, buf, count, datatype%MPI_VAL, &
                                                      MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_File_write_at_all_cdesc_large(fh_c, offset, buf, count, datatype%MPI_VAL, &
                                                      c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_write_at_all_c_f08ts

SUBROUTINE MPI_File_write_at_all_begin_f08ts(fh, offset, buf, count, datatype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_File_write_at_all_begin_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_write_at_all_begin_cdesc(fh_c, offset, buf, count, datatype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_write_at_all_begin_f08ts

SUBROUTINE MPI_File_write_at_all_begin_c_f08ts(fh, offset, buf, count, datatype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND, MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_File_write_at_all_begin_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_write_at_all_begin_cdesc_large(fh_c, offset, buf, count, datatype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_write_at_all_begin_c_f08ts

SUBROUTINE MPI_File_write_at_all_end_f08ts(fh, buf, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_File, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_File_write_at_all_end_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_File_write_at_all_end_cdesc(fh_c, buf, MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_File_write_at_all_end_cdesc(fh_c, buf, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_write_at_all_end_f08ts

SUBROUTINE MPI_File_write_ordered_f08ts(fh, buf, count, datatype, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_File_write_ordered_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_File_write_ordered_cdesc(fh_c, buf, count, datatype%MPI_VAL, &
                                                 MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_File_write_ordered_cdesc(fh_c, buf, count, datatype%MPI_VAL, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_write_ordered_f08ts

SUBROUTINE MPI_File_write_ordered_c_f08ts(fh, buf, count, datatype, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Status, assignment(=)
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_File_write_ordered_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Datatype) :: datatype_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_File_write_ordered_cdesc_large(fh_c, buf, count, datatype%MPI_VAL, &
                                                       MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_File_write_ordered_cdesc_large(fh_c, buf, count, datatype%MPI_VAL, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_write_ordered_c_f08ts

SUBROUTINE MPI_File_write_ordered_begin_f08ts(fh, buf, count, datatype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_File_write_ordered_begin_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_write_ordered_begin_cdesc(fh_c, buf, count, datatype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_write_ordered_begin_f08ts

SUBROUTINE MPI_File_write_ordered_begin_c_f08ts(fh, buf, count, datatype, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    USE :: mpi_c_interface, ONLY : MPIR_File_write_ordered_begin_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Datatype) :: datatype_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    ierror_c = MPIR_File_write_ordered_begin_cdesc_large(fh_c, buf, count, datatype%MPI_VAL)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_write_ordered_begin_c_f08ts

SUBROUTINE MPI_File_write_ordered_end_f08ts(fh, buf, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_File, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_File_write_ordered_end_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_File_write_ordered_end_cdesc(fh_c, buf, MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_File_write_ordered_end_cdesc(fh_c, buf, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_write_ordered_end_f08ts

SUBROUTINE MPI_File_write_shared_f08ts(fh, buf, count, datatype, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_loc, c_associated
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Status, assignment(=)
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_File_write_shared_cdesc
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER, INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_int) :: count_c
    INTEGER(c_Datatype) :: datatype_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_File_write_shared_cdesc(fh_c, buf, count, datatype%MPI_VAL, &
                                                MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_File_write_shared_cdesc(fh_c, buf, count, datatype%MPI_VAL, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_write_shared_f08ts

SUBROUTINE MPI_File_write_shared_c_f08ts(fh, buf, count, datatype, status, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_loc, c_associated, c_int
    USE :: mpi_f08_types, ONLY : MPI_File, MPI_File_f2c, MPI_Datatype, MPI_Status, assignment(=)
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_f08_link_constants, ONLY : MPI_STATUS_IGNORE, MPIR_F08_get_MPI_STATUS_IGNORE_c
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Status
    USE :: mpi_c_interface, ONLY : MPIR_File_write_shared_cdesc_large
    
    IMPLICIT NONE
    
    TYPE(MPI_File), INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
    TYPE(MPI_Datatype), INTENT(in) :: datatype
    TYPE(MPI_Status), INTENT(out), TARGET :: status
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_File) :: fh_c
    INTEGER(c_Datatype) :: datatype_c
    TYPE(c_Status), TARGET :: status_c
    INTEGER(c_int) :: ierror_c
    
    fh_c = MPI_File_f2c(fh%MPI_VAL)
    
    IF (c_associated(c_loc(status), c_loc(MPI_STATUS_IGNORE))) THEN
        ierror_c = MPIR_File_write_shared_cdesc_large(fh_c, buf, count, datatype%MPI_VAL, &
                                                      MPIR_F08_get_MPI_STATUS_IGNORE_c())
    ELSE
        ierror_c = MPIR_File_write_shared_cdesc_large(fh_c, buf, count, datatype%MPI_VAL, c_loc(status))
    END IF
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_File_write_shared_c_f08ts

SUBROUTINE MPI_Register_datarep_f08(datarep, read_conversion_fn, write_conversion_fn, &
                                    dtype_file_extent_fn, extra_state, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_funptr, c_funloc, c_associated, c_null_funptr, &
        c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_f08_callbacks, ONLY : MPI_Datarep_conversion_function, MPI_CONVERSION_FN_NULL, &
        MPI_Datarep_extent_function
    USE :: mpi_c_interface, ONLY : MPIR_Register_datarep_c
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_f2c
    
    IMPLICIT NONE
    
    CHARACTER(len=*), INTENT(in) :: datarep
    PROCEDURE(MPI_Datarep_conversion_function) :: read_conversion_fn
    PROCEDURE(MPI_Datarep_conversion_function) :: write_conversion_fn
    PROCEDURE(MPI_Datarep_extent_function) :: dtype_file_extent_fn
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: extra_state
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    character(kind=c_char) :: datarep_c(len_trim(datarep) + 1)
    TYPE(c_funptr) :: read_conversion_fn_c
    TYPE(c_funptr) :: write_conversion_fn_c
    TYPE(c_funptr) :: dtype_file_extent_fn_c
    INTEGER(c_int) :: ierror_c
    
    call MPIR_Fortran_string_f2c(datarep, datarep_c)
    read_conversion_fn_c = c_funloc(read_conversion_fn)
    IF (c_associated(read_conversion_fn_c, c_funloc(MPI_CONVERSION_FN_NULL))) then
        read_conversion_fn_c = c_null_funptr
    END IF
    write_conversion_fn_c = c_funloc(write_conversion_fn)
    IF (c_associated(write_conversion_fn_c, c_funloc(MPI_CONVERSION_FN_NULL))) then
        write_conversion_fn_c = c_null_funptr
    END IF
    dtype_file_extent_fn_c = c_funloc(dtype_file_extent_fn)
    
    ierror_c = MPIR_Register_datarep_c(datarep_c, read_conversion_fn_c, write_conversion_fn_c, &
                                       dtype_file_extent_fn_c, extra_state)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Register_datarep_f08

SUBROUTINE MPI_Register_datarep_c_f08(datarep, read_conversion_fn, write_conversion_fn, &
                                      dtype_file_extent_fn, extra_state, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_char, c_funptr, c_funloc, c_associated, c_null_funptr, &
        c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_f08_callbacks, ONLY : MPI_Datarep_conversion_function_c, MPI_CONVERSION_FN_NULL_C, &
        MPI_Datarep_extent_function
    USE :: mpi_c_interface, ONLY : MPIR_Register_datarep_c_large
    USE :: mpi_c_interface_glue, ONLY : MPIR_Fortran_string_f2c
    
    IMPLICIT NONE
    
    CHARACTER(len=*), INTENT(in) :: datarep
    PROCEDURE(MPI_Datarep_conversion_function_c) :: read_conversion_fn
    PROCEDURE(MPI_Datarep_conversion_function_c) :: write_conversion_fn
    PROCEDURE(MPI_Datarep_extent_function) :: dtype_file_extent_fn
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: extra_state
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    character(kind=c_char) :: datarep_c(len_trim(datarep) + 1)
    TYPE(c_funptr) :: read_conversion_fn_c
    TYPE(c_funptr) :: write_conversion_fn_c
    TYPE(c_funptr) :: dtype_file_extent_fn_c
    INTEGER(c_int) :: ierror_c
    
    call MPIR_Fortran_string_f2c(datarep, datarep_c)
    read_conversion_fn_c = c_funloc(read_conversion_fn)
    IF (c_associated(read_conversion_fn_c, c_funloc(MPI_CONVERSION_FN_NULL_C))) then
        read_conversion_fn_c = c_null_funptr
    END IF
    write_conversion_fn_c = c_funloc(write_conversion_fn)
    IF (c_associated(write_conversion_fn_c, c_funloc(MPI_CONVERSION_FN_NULL_C))) then
        write_conversion_fn_c = c_null_funptr
    END IF
    dtype_file_extent_fn_c = c_funloc(dtype_file_extent_fn)
    
    ierror_c = MPIR_Register_datarep_c_large(datarep_c, read_conversion_fn_c, write_conversion_fn_c, &
                                             dtype_file_extent_fn_c, extra_state)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_Register_datarep_c_f08

SUBROUTINE MPI_F_sync_reg_f08ts(buf, ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface, ONLY : MPIR_F_sync_reg_cdesc
    
    IMPLICIT NONE
    
    TYPE(*), DIMENSION(..), INTENT(inout), ASYNCHRONOUS :: buf
    INTEGER, OPTIONAL, INTENT(out) :: ierror
    
    INTEGER(c_int) :: ierror_c
    
    ierror_c = MPIR_F_sync_reg_cdesc(buf)
    
    IF (present(ierror)) ierror = ierror_c
END SUBROUTINE MPI_F_sync_reg_f08ts
