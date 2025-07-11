!
! Copyright (C) by Argonne National Laboratory
!     See COPYRIGHT in top-level directory
!

! -- THIS FILE IS AUTO-GENERATED -- 

MODULE mpi_f08
    USE,intrinsic :: iso_c_binding, ONLY: c_ptr
    USE :: pmpi_f08
    USE :: mpi_f08_types
    USE :: mpi_f08_compile_constants
    USE :: mpi_f08_link_constants
    USE :: mpi_f08_callbacks
    
    IMPLICIT NONE
    
    INTERFACE MPI_Comm_create_keyval
        SUBROUTINE MPI_Comm_create_keyval_f08(comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, &
                                              extra_state, ierror)
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            USE :: mpi_f08_callbacks, ONLY : MPI_Comm_copy_attr_function, MPI_Comm_delete_attr_function
            IMPLICIT NONE
            PROCEDURE(MPI_Comm_copy_attr_function) :: comm_copy_attr_fn
            PROCEDURE(MPI_Comm_delete_attr_function) :: comm_delete_attr_fn
            INTEGER, INTENT(out) :: comm_keyval
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: extra_state
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_create_keyval_f08
    END INTERFACE MPI_Comm_create_keyval
    
    INTERFACE MPI_Comm_delete_attr
        SUBROUTINE MPI_Comm_delete_attr_f08(comm, comm_keyval, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: comm_keyval
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_delete_attr_f08
    END INTERFACE MPI_Comm_delete_attr
    
    INTERFACE MPI_Comm_free_keyval
        SUBROUTINE MPI_Comm_free_keyval_f08(comm_keyval, ierror)
            IMPLICIT NONE
            INTEGER, INTENT(inout) :: comm_keyval
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_free_keyval_f08
    END INTERFACE MPI_Comm_free_keyval
    
    INTERFACE MPI_Comm_get_attr
        SUBROUTINE MPI_Comm_get_attr_f08(comm, comm_keyval, attribute_val, flag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: comm_keyval
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: attribute_val
            LOGICAL, INTENT(out) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_get_attr_f08
    END INTERFACE MPI_Comm_get_attr
    
    INTERFACE MPI_Comm_set_attr
        SUBROUTINE MPI_Comm_set_attr_f08(comm, comm_keyval, attribute_val, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: comm_keyval
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: attribute_val
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_set_attr_f08
    END INTERFACE MPI_Comm_set_attr
    
    INTERFACE MPI_Type_create_keyval
        SUBROUTINE MPI_Type_create_keyval_f08(type_copy_attr_fn, type_delete_attr_fn, type_keyval, &
                                              extra_state, ierror)
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            USE :: mpi_f08_callbacks, ONLY : MPI_Type_copy_attr_function, MPI_Type_delete_attr_function
            IMPLICIT NONE
            PROCEDURE(MPI_Type_copy_attr_function) :: type_copy_attr_fn
            PROCEDURE(MPI_Type_delete_attr_function) :: type_delete_attr_fn
            INTEGER, INTENT(out) :: type_keyval
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: extra_state
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_create_keyval_f08
    END INTERFACE MPI_Type_create_keyval
    
    INTERFACE MPI_Type_delete_attr
        SUBROUTINE MPI_Type_delete_attr_f08(datatype, type_keyval, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: type_keyval
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_delete_attr_f08
    END INTERFACE MPI_Type_delete_attr
    
    INTERFACE MPI_Type_free_keyval
        SUBROUTINE MPI_Type_free_keyval_f08(type_keyval, ierror)
            IMPLICIT NONE
            INTEGER, INTENT(inout) :: type_keyval
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_free_keyval_f08
    END INTERFACE MPI_Type_free_keyval
    
    INTERFACE MPI_Type_get_attr
        SUBROUTINE MPI_Type_get_attr_f08(datatype, type_keyval, attribute_val, flag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: type_keyval
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: attribute_val
            LOGICAL, INTENT(out) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_get_attr_f08
    END INTERFACE MPI_Type_get_attr
    
    INTERFACE MPI_Type_set_attr
        SUBROUTINE MPI_Type_set_attr_f08(datatype, type_keyval, attribute_val, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: type_keyval
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: attribute_val
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_set_attr_f08
    END INTERFACE MPI_Type_set_attr
    
    INTERFACE MPI_Win_create_keyval
        SUBROUTINE MPI_Win_create_keyval_f08(win_copy_attr_fn, win_delete_attr_fn, win_keyval, extra_state, &
                                             ierror)
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            USE :: mpi_f08_callbacks, ONLY : MPI_Win_copy_attr_function, MPI_Win_delete_attr_function
            IMPLICIT NONE
            PROCEDURE(MPI_Win_copy_attr_function) :: win_copy_attr_fn
            PROCEDURE(MPI_Win_delete_attr_function) :: win_delete_attr_fn
            INTEGER, INTENT(out) :: win_keyval
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: extra_state
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_create_keyval_f08
    END INTERFACE MPI_Win_create_keyval
    
    INTERFACE MPI_Win_delete_attr
        SUBROUTINE MPI_Win_delete_attr_f08(win, win_keyval, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, INTENT(in) :: win_keyval
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_delete_attr_f08
    END INTERFACE MPI_Win_delete_attr
    
    INTERFACE MPI_Win_free_keyval
        SUBROUTINE MPI_Win_free_keyval_f08(win_keyval, ierror)
            IMPLICIT NONE
            INTEGER, INTENT(inout) :: win_keyval
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_free_keyval_f08
    END INTERFACE MPI_Win_free_keyval
    
    INTERFACE MPI_Win_get_attr
        SUBROUTINE MPI_Win_get_attr_f08(win, win_keyval, attribute_val, flag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, INTENT(in) :: win_keyval
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: attribute_val
            LOGICAL, INTENT(out) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_get_attr_f08
    END INTERFACE MPI_Win_get_attr
    
    INTERFACE MPI_Win_set_attr
        SUBROUTINE MPI_Win_set_attr_f08(win, win_keyval, attribute_val, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, INTENT(in) :: win_keyval
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: attribute_val
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_set_attr_f08
    END INTERFACE MPI_Win_set_attr
    
    INTERFACE MPI_Allgather
        SUBROUTINE MPI_Allgather_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, &
                                       ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
            INTEGER, INTENT(in) :: sendcount
            TYPE(MPI_Datatype), INTENT(in) :: sendtype
            TYPE(*), DIMENSION(..) :: recvbuf
            INTEGER, INTENT(in) :: recvcount
            TYPE(MPI_Datatype), INTENT(in) :: recvtype
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Allgather_f08ts
        
        SUBROUTINE MPI_Allgather_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, &
                                         ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
            TYPE(MPI_Datatype), INTENT(in) :: sendtype
            TYPE(*), DIMENSION(..) :: recvbuf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcount
            TYPE(MPI_Datatype), INTENT(in) :: recvtype
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Allgather_c_f08ts
    END INTERFACE MPI_Allgather
    
    INTERFACE MPI_Allgather_init
        SUBROUTINE MPI_Allgather_init_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
                                            comm, info, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
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
        END SUBROUTINE MPI_Allgather_init_f08ts
        
        SUBROUTINE MPI_Allgather_init_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
                                              comm, info, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
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
        END SUBROUTINE MPI_Allgather_init_c_f08ts
    END INTERFACE MPI_Allgather_init
    
    INTERFACE MPI_Allgatherv
        SUBROUTINE MPI_Allgatherv_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, &
                                        comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
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
        END SUBROUTINE MPI_Allgatherv_f08ts
        
        SUBROUTINE MPI_Allgatherv_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
                                          recvtype, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Allgatherv_c_f08ts
    END INTERFACE MPI_Allgatherv
    
    INTERFACE MPI_Allgatherv_init
        SUBROUTINE MPI_Allgatherv_init_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
                                             recvtype, comm, info, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
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
        END SUBROUTINE MPI_Allgatherv_init_f08ts
        
        SUBROUTINE MPI_Allgatherv_init_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
                                               recvtype, comm, info, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Allgatherv_init_c_f08ts
    END INTERFACE MPI_Allgatherv_init
    
    INTERFACE MPI_Allreduce
        SUBROUTINE MPI_Allreduce_f08ts(sendbuf, recvbuf, count, datatype, op, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
            TYPE(*), DIMENSION(..) :: recvbuf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Allreduce_f08ts
        
        SUBROUTINE MPI_Allreduce_c_f08ts(sendbuf, recvbuf, count, datatype, op, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
            TYPE(*), DIMENSION(..) :: recvbuf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Allreduce_c_f08ts
    END INTERFACE MPI_Allreduce
    
    INTERFACE MPI_Allreduce_init
        SUBROUTINE MPI_Allreduce_init_f08ts(sendbuf, recvbuf, count, datatype, op, comm, info, request, &
                                            ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request
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
        END SUBROUTINE MPI_Allreduce_init_f08ts
        
        SUBROUTINE MPI_Allreduce_init_c_f08ts(sendbuf, recvbuf, count, datatype, op, comm, info, request, &
                                              ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
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
        END SUBROUTINE MPI_Allreduce_init_c_f08ts
    END INTERFACE MPI_Allreduce_init
    
    INTERFACE MPI_Alltoall
        SUBROUTINE MPI_Alltoall_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, &
                                      ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
            INTEGER, INTENT(in) :: sendcount
            TYPE(MPI_Datatype), INTENT(in) :: sendtype
            TYPE(*), DIMENSION(..) :: recvbuf
            INTEGER, INTENT(in) :: recvcount
            TYPE(MPI_Datatype), INTENT(in) :: recvtype
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Alltoall_f08ts
        
        SUBROUTINE MPI_Alltoall_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, &
                                        ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
            TYPE(MPI_Datatype), INTENT(in) :: sendtype
            TYPE(*), DIMENSION(..) :: recvbuf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcount
            TYPE(MPI_Datatype), INTENT(in) :: recvtype
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Alltoall_c_f08ts
    END INTERFACE MPI_Alltoall
    
    INTERFACE MPI_Alltoall_init
        SUBROUTINE MPI_Alltoall_init_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, &
                                           info, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
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
        END SUBROUTINE MPI_Alltoall_init_f08ts
        
        SUBROUTINE MPI_Alltoall_init_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
                                             comm, info, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
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
        END SUBROUTINE MPI_Alltoall_init_c_f08ts
    END INTERFACE MPI_Alltoall_init
    
    INTERFACE MPI_Alltoallv
        SUBROUTINE MPI_Alltoallv_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, &
                                       recvtype, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
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
        END SUBROUTINE MPI_Alltoallv_f08ts
        
        SUBROUTINE MPI_Alltoallv_c_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, &
                                         rdispls, recvtype, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Alltoallv_c_f08ts
    END INTERFACE MPI_Alltoallv
    
    INTERFACE MPI_Alltoallv_init
        SUBROUTINE MPI_Alltoallv_init_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, &
                                            rdispls, recvtype, comm, info, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
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
        END SUBROUTINE MPI_Alltoallv_init_f08ts
        
        SUBROUTINE MPI_Alltoallv_init_c_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, &
                                              rdispls, recvtype, comm, info, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Alltoallv_init_c_f08ts
    END INTERFACE MPI_Alltoallv_init
    
    INTERFACE MPI_Alltoallw
        SUBROUTINE MPI_Alltoallw_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, &
                                       rdispls, recvtypes, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
            INTEGER, INTENT(in) :: sendcounts(*)
            INTEGER, INTENT(in) :: sdispls(*)
            TYPE(MPI_Datatype), INTENT(in) :: sendtypes(*)
            TYPE(*), DIMENSION(..) :: recvbuf
            INTEGER, INTENT(in) :: recvcounts(*)
            INTEGER, INTENT(in) :: rdispls(*)
            TYPE(MPI_Datatype), INTENT(in) :: recvtypes(*)
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Alltoallw_f08ts
        
        SUBROUTINE MPI_Alltoallw_c_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, &
                                         rdispls, recvtypes, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Alltoallw_c_f08ts
    END INTERFACE MPI_Alltoallw
    
    INTERFACE MPI_Alltoallw_init
        SUBROUTINE MPI_Alltoallw_init_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, &
                                            rdispls, recvtypes, comm, info, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
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
        END SUBROUTINE MPI_Alltoallw_init_f08ts
        
        SUBROUTINE MPI_Alltoallw_init_c_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, &
                                              rdispls, recvtypes, comm, info, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Alltoallw_init_c_f08ts
    END INTERFACE MPI_Alltoallw_init
    
    INTERFACE MPI_Barrier
        SUBROUTINE MPI_Barrier_f08(comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Barrier_f08
    END INTERFACE MPI_Barrier
    
    INTERFACE MPI_Barrier_init
        SUBROUTINE MPI_Barrier_init_f08(comm, info, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Info, MPI_Request
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Info), INTENT(in) :: info
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Barrier_init_f08
    END INTERFACE MPI_Barrier_init
    
    INTERFACE MPI_Bcast
        SUBROUTINE MPI_Bcast_f08ts(buffer, count, datatype, root, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(inout) :: buffer
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: root
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Bcast_f08ts
        
        SUBROUTINE MPI_Bcast_c_f08ts(buffer, count, datatype, root, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(inout) :: buffer
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: root
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Bcast_c_f08ts
    END INTERFACE MPI_Bcast
    
    INTERFACE MPI_Bcast_init
        SUBROUTINE MPI_Bcast_init_f08ts(buffer, count, datatype, root, comm, info, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buffer
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: root
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Info), INTENT(in) :: info
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Bcast_init_f08ts
        
        SUBROUTINE MPI_Bcast_init_c_f08ts(buffer, count, datatype, root, comm, info, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buffer
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: root
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Info), INTENT(in) :: info
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Bcast_init_c_f08ts
    END INTERFACE MPI_Bcast_init
    
    INTERFACE MPI_Exscan
        SUBROUTINE MPI_Exscan_f08ts(sendbuf, recvbuf, count, datatype, op, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
            TYPE(*), DIMENSION(..) :: recvbuf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Exscan_f08ts
        
        SUBROUTINE MPI_Exscan_c_f08ts(sendbuf, recvbuf, count, datatype, op, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
            TYPE(*), DIMENSION(..) :: recvbuf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Exscan_c_f08ts
    END INTERFACE MPI_Exscan
    
    INTERFACE MPI_Exscan_init
        SUBROUTINE MPI_Exscan_init_f08ts(sendbuf, recvbuf, count, datatype, op, comm, info, request, &
                                         ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request
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
        END SUBROUTINE MPI_Exscan_init_f08ts
        
        SUBROUTINE MPI_Exscan_init_c_f08ts(sendbuf, recvbuf, count, datatype, op, comm, info, request, &
                                           ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
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
        END SUBROUTINE MPI_Exscan_init_c_f08ts
    END INTERFACE MPI_Exscan_init
    
    INTERFACE MPI_Gather
        SUBROUTINE MPI_Gather_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, &
                                    ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
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
        END SUBROUTINE MPI_Gather_f08ts
        
        SUBROUTINE MPI_Gather_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, &
                                      comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
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
        END SUBROUTINE MPI_Gather_c_f08ts
    END INTERFACE MPI_Gather
    
    INTERFACE MPI_Gather_init
        SUBROUTINE MPI_Gather_init_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, &
                                         comm, info, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
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
        END SUBROUTINE MPI_Gather_init_f08ts
        
        SUBROUTINE MPI_Gather_init_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, &
                                           comm, info, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
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
        END SUBROUTINE MPI_Gather_init_c_f08ts
    END INTERFACE MPI_Gather_init
    
    INTERFACE MPI_Gatherv
        SUBROUTINE MPI_Gatherv_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, &
                                     root, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
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
        END SUBROUTINE MPI_Gatherv_f08ts
        
        SUBROUTINE MPI_Gatherv_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, &
                                       root, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Gatherv_c_f08ts
    END INTERFACE MPI_Gatherv
    
    INTERFACE MPI_Gatherv_init
        SUBROUTINE MPI_Gatherv_init_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
                                          recvtype, root, comm, info, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
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
        END SUBROUTINE MPI_Gatherv_init_f08ts
        
        SUBROUTINE MPI_Gatherv_init_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
                                            recvtype, root, comm, info, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Gatherv_init_c_f08ts
    END INTERFACE MPI_Gatherv_init
    
    INTERFACE MPI_Iallgather
        SUBROUTINE MPI_Iallgather_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, &
                                        request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
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
        END SUBROUTINE MPI_Iallgather_f08ts
        
        SUBROUTINE MPI_Iallgather_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, &
                                          request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
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
        END SUBROUTINE MPI_Iallgather_c_f08ts
    END INTERFACE MPI_Iallgather
    
    INTERFACE MPI_Iallgatherv
        SUBROUTINE MPI_Iallgatherv_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
                                         recvtype, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
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
        END SUBROUTINE MPI_Iallgatherv_f08ts
        
        SUBROUTINE MPI_Iallgatherv_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
                                           recvtype, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Iallgatherv_c_f08ts
    END INTERFACE MPI_Iallgatherv
    
    INTERFACE MPI_Iallreduce
        SUBROUTINE MPI_Iallreduce_f08ts(sendbuf, recvbuf, count, datatype, op, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Iallreduce_f08ts
        
        SUBROUTINE MPI_Iallreduce_c_f08ts(sendbuf, recvbuf, count, datatype, op, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Iallreduce_c_f08ts
    END INTERFACE MPI_Iallreduce
    
    INTERFACE MPI_Ialltoall
        SUBROUTINE MPI_Ialltoall_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, &
                                       request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
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
        END SUBROUTINE MPI_Ialltoall_f08ts
        
        SUBROUTINE MPI_Ialltoall_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, &
                                         request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
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
        END SUBROUTINE MPI_Ialltoall_c_f08ts
    END INTERFACE MPI_Ialltoall
    
    INTERFACE MPI_Ialltoallv
        SUBROUTINE MPI_Ialltoallv_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, &
                                        rdispls, recvtype, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
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
        END SUBROUTINE MPI_Ialltoallv_f08ts
        
        SUBROUTINE MPI_Ialltoallv_c_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, &
                                          rdispls, recvtype, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Ialltoallv_c_f08ts
    END INTERFACE MPI_Ialltoallv
    
    INTERFACE MPI_Ialltoallw
        SUBROUTINE MPI_Ialltoallw_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, &
                                        rdispls, recvtypes, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
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
        END SUBROUTINE MPI_Ialltoallw_f08ts
        
        SUBROUTINE MPI_Ialltoallw_c_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, &
                                          rdispls, recvtypes, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Ialltoallw_c_f08ts
    END INTERFACE MPI_Ialltoallw
    
    INTERFACE MPI_Ibarrier
        SUBROUTINE MPI_Ibarrier_f08(comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Request
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Ibarrier_f08
    END INTERFACE MPI_Ibarrier
    
    INTERFACE MPI_Ibcast
        SUBROUTINE MPI_Ibcast_f08ts(buffer, count, datatype, root, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(inout), ASYNCHRONOUS :: buffer
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: root
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Ibcast_f08ts
        
        SUBROUTINE MPI_Ibcast_c_f08ts(buffer, count, datatype, root, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(inout), ASYNCHRONOUS :: buffer
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: root
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Ibcast_c_f08ts
    END INTERFACE MPI_Ibcast
    
    INTERFACE MPI_Iexscan
        SUBROUTINE MPI_Iexscan_f08ts(sendbuf, recvbuf, count, datatype, op, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Iexscan_f08ts
        
        SUBROUTINE MPI_Iexscan_c_f08ts(sendbuf, recvbuf, count, datatype, op, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Iexscan_c_f08ts
    END INTERFACE MPI_Iexscan
    
    INTERFACE MPI_Igather
        SUBROUTINE MPI_Igather_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, &
                                     request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
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
        END SUBROUTINE MPI_Igather_f08ts
        
        SUBROUTINE MPI_Igather_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, &
                                       comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
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
        END SUBROUTINE MPI_Igather_c_f08ts
    END INTERFACE MPI_Igather
    
    INTERFACE MPI_Igatherv
        SUBROUTINE MPI_Igatherv_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, &
                                      root, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
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
        END SUBROUTINE MPI_Igatherv_f08ts
        
        SUBROUTINE MPI_Igatherv_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, &
                                        root, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Igatherv_c_f08ts
    END INTERFACE MPI_Igatherv
    
    INTERFACE MPI_Ineighbor_allgather
        SUBROUTINE MPI_Ineighbor_allgather_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
                                                 comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
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
        END SUBROUTINE MPI_Ineighbor_allgather_f08ts
        
        SUBROUTINE MPI_Ineighbor_allgather_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, &
                                                   recvtype, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
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
        END SUBROUTINE MPI_Ineighbor_allgather_c_f08ts
    END INTERFACE MPI_Ineighbor_allgather
    
    INTERFACE MPI_Ineighbor_allgatherv
        SUBROUTINE MPI_Ineighbor_allgatherv_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
                                                  recvtype, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
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
        END SUBROUTINE MPI_Ineighbor_allgatherv_f08ts
        
        SUBROUTINE MPI_Ineighbor_allgatherv_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, &
                                                    displs, recvtype, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Ineighbor_allgatherv_c_f08ts
    END INTERFACE MPI_Ineighbor_allgatherv
    
    INTERFACE MPI_Ineighbor_alltoall
        SUBROUTINE MPI_Ineighbor_alltoall_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
                                                comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
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
        END SUBROUTINE MPI_Ineighbor_alltoall_f08ts
        
        SUBROUTINE MPI_Ineighbor_alltoall_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, &
                                                  recvtype, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
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
        END SUBROUTINE MPI_Ineighbor_alltoall_c_f08ts
    END INTERFACE MPI_Ineighbor_alltoall
    
    INTERFACE MPI_Ineighbor_alltoallv
        SUBROUTINE MPI_Ineighbor_alltoallv_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, &
                                                 recvcounts, rdispls, recvtype, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
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
        END SUBROUTINE MPI_Ineighbor_alltoallv_f08ts
        
        SUBROUTINE MPI_Ineighbor_alltoallv_c_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, &
                                                   recvcounts, rdispls, recvtype, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Ineighbor_alltoallv_c_f08ts
    END INTERFACE MPI_Ineighbor_alltoallv
    
    INTERFACE MPI_Ineighbor_alltoallw
        SUBROUTINE MPI_Ineighbor_alltoallw_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, &
                                                 recvcounts, rdispls, recvtypes, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Ineighbor_alltoallw_f08ts
        
        SUBROUTINE MPI_Ineighbor_alltoallw_c_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, &
                                                   recvcounts, rdispls, recvtypes, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Ineighbor_alltoallw_c_f08ts
    END INTERFACE MPI_Ineighbor_alltoallw
    
    INTERFACE MPI_Ireduce
        SUBROUTINE MPI_Ireduce_f08ts(sendbuf, recvbuf, count, datatype, op, root, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request
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
        END SUBROUTINE MPI_Ireduce_f08ts
        
        SUBROUTINE MPI_Ireduce_c_f08ts(sendbuf, recvbuf, count, datatype, op, root, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
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
        END SUBROUTINE MPI_Ireduce_c_f08ts
    END INTERFACE MPI_Ireduce
    
    INTERFACE MPI_Ireduce_scatter
        SUBROUTINE MPI_Ireduce_scatter_f08ts(sendbuf, recvbuf, recvcounts, datatype, op, comm, request, &
                                             ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
            INTEGER, INTENT(in), ASYNCHRONOUS :: recvcounts(*)
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Ireduce_scatter_f08ts
        
        SUBROUTINE MPI_Ireduce_scatter_c_f08ts(sendbuf, recvbuf, recvcounts, datatype, op, comm, request, &
                                               ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in), ASYNCHRONOUS :: recvcounts(*)
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Ireduce_scatter_c_f08ts
    END INTERFACE MPI_Ireduce_scatter
    
    INTERFACE MPI_Ireduce_scatter_block
        SUBROUTINE MPI_Ireduce_scatter_block_f08ts(sendbuf, recvbuf, recvcount, datatype, op, comm, request, &
                                                   ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
            INTEGER, INTENT(in) :: recvcount
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Ireduce_scatter_block_f08ts
        
        SUBROUTINE MPI_Ireduce_scatter_block_c_f08ts(sendbuf, recvbuf, recvcount, datatype, op, comm, &
                                                     request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcount
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Ireduce_scatter_block_c_f08ts
    END INTERFACE MPI_Ireduce_scatter_block
    
    INTERFACE MPI_Iscan
        SUBROUTINE MPI_Iscan_f08ts(sendbuf, recvbuf, count, datatype, op, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Iscan_f08ts
        
        SUBROUTINE MPI_Iscan_c_f08ts(sendbuf, recvbuf, count, datatype, op, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: sendbuf
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: recvbuf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Iscan_c_f08ts
    END INTERFACE MPI_Iscan
    
    INTERFACE MPI_Iscatter
        SUBROUTINE MPI_Iscatter_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, &
                                      comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
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
        END SUBROUTINE MPI_Iscatter_f08ts
        
        SUBROUTINE MPI_Iscatter_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, &
                                        comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
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
        END SUBROUTINE MPI_Iscatter_c_f08ts
    END INTERFACE MPI_Iscatter
    
    INTERFACE MPI_Iscatterv
        SUBROUTINE MPI_Iscatterv_f08ts(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, &
                                       root, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
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
        END SUBROUTINE MPI_Iscatterv_f08ts
        
        SUBROUTINE MPI_Iscatterv_c_f08ts(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, &
                                         recvtype, root, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Iscatterv_c_f08ts
    END INTERFACE MPI_Iscatterv
    
    INTERFACE MPI_Neighbor_allgather
        SUBROUTINE MPI_Neighbor_allgather_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
                                                comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
            INTEGER, INTENT(in) :: sendcount
            TYPE(MPI_Datatype), INTENT(in) :: sendtype
            TYPE(*), DIMENSION(..) :: recvbuf
            INTEGER, INTENT(in) :: recvcount
            TYPE(MPI_Datatype), INTENT(in) :: recvtype
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Neighbor_allgather_f08ts
        
        SUBROUTINE MPI_Neighbor_allgather_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, &
                                                  recvtype, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
            TYPE(MPI_Datatype), INTENT(in) :: sendtype
            TYPE(*), DIMENSION(..) :: recvbuf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcount
            TYPE(MPI_Datatype), INTENT(in) :: recvtype
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Neighbor_allgather_c_f08ts
    END INTERFACE MPI_Neighbor_allgather
    
    INTERFACE MPI_Neighbor_allgather_init
        SUBROUTINE MPI_Neighbor_allgather_init_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, &
                                                     recvtype, comm, info, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
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
        END SUBROUTINE MPI_Neighbor_allgather_init_f08ts
        
        SUBROUTINE MPI_Neighbor_allgather_init_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, &
                                                       recvtype, comm, info, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
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
        END SUBROUTINE MPI_Neighbor_allgather_init_c_f08ts
    END INTERFACE MPI_Neighbor_allgather_init
    
    INTERFACE MPI_Neighbor_allgatherv
        SUBROUTINE MPI_Neighbor_allgatherv_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
                                                 recvtype, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
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
        END SUBROUTINE MPI_Neighbor_allgatherv_f08ts
        
        SUBROUTINE MPI_Neighbor_allgatherv_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, &
                                                   displs, recvtype, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Neighbor_allgatherv_c_f08ts
    END INTERFACE MPI_Neighbor_allgatherv
    
    INTERFACE MPI_Neighbor_allgatherv_init
        SUBROUTINE MPI_Neighbor_allgatherv_init_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, &
                                                      displs, recvtype, comm, info, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
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
        END SUBROUTINE MPI_Neighbor_allgatherv_init_f08ts
        
        SUBROUTINE MPI_Neighbor_allgatherv_init_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, &
                                                        displs, recvtype, comm, info, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Neighbor_allgatherv_init_c_f08ts
    END INTERFACE MPI_Neighbor_allgatherv_init
    
    INTERFACE MPI_Neighbor_alltoall
        SUBROUTINE MPI_Neighbor_alltoall_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
                                               comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
            INTEGER, INTENT(in) :: sendcount
            TYPE(MPI_Datatype), INTENT(in) :: sendtype
            TYPE(*), DIMENSION(..) :: recvbuf
            INTEGER, INTENT(in) :: recvcount
            TYPE(MPI_Datatype), INTENT(in) :: recvtype
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Neighbor_alltoall_f08ts
        
        SUBROUTINE MPI_Neighbor_alltoall_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
                                                 comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcount
            TYPE(MPI_Datatype), INTENT(in) :: sendtype
            TYPE(*), DIMENSION(..) :: recvbuf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcount
            TYPE(MPI_Datatype), INTENT(in) :: recvtype
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Neighbor_alltoall_c_f08ts
    END INTERFACE MPI_Neighbor_alltoall
    
    INTERFACE MPI_Neighbor_alltoall_init
        SUBROUTINE MPI_Neighbor_alltoall_init_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, &
                                                    recvtype, comm, info, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
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
        END SUBROUTINE MPI_Neighbor_alltoall_init_f08ts
        
        SUBROUTINE MPI_Neighbor_alltoall_init_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, &
                                                      recvtype, comm, info, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
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
        END SUBROUTINE MPI_Neighbor_alltoall_init_c_f08ts
    END INTERFACE MPI_Neighbor_alltoall_init
    
    INTERFACE MPI_Neighbor_alltoallv
        SUBROUTINE MPI_Neighbor_alltoallv_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, &
                                                rdispls, recvtype, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
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
        END SUBROUTINE MPI_Neighbor_alltoallv_f08ts
        
        SUBROUTINE MPI_Neighbor_alltoallv_c_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, &
                                                  recvcounts, rdispls, recvtype, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Neighbor_alltoallv_c_f08ts
    END INTERFACE MPI_Neighbor_alltoallv
    
    INTERFACE MPI_Neighbor_alltoallv_init
        SUBROUTINE MPI_Neighbor_alltoallv_init_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, &
                                                     recvcounts, rdispls, recvtype, comm, info, request, &
                                                     ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
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
        END SUBROUTINE MPI_Neighbor_alltoallv_init_f08ts
        
        SUBROUTINE MPI_Neighbor_alltoallv_init_c_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, &
                                                       recvcounts, rdispls, recvtype, comm, info, request, &
                                                       ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Neighbor_alltoallv_init_c_f08ts
    END INTERFACE MPI_Neighbor_alltoallv_init
    
    INTERFACE MPI_Neighbor_alltoallw
        SUBROUTINE MPI_Neighbor_alltoallw_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, &
                                                recvcounts, rdispls, recvtypes, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Neighbor_alltoallw_f08ts
        
        SUBROUTINE MPI_Neighbor_alltoallw_c_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, &
                                                  recvcounts, rdispls, recvtypes, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Neighbor_alltoallw_c_f08ts
    END INTERFACE MPI_Neighbor_alltoallw
    
    INTERFACE MPI_Neighbor_alltoallw_init
        SUBROUTINE MPI_Neighbor_alltoallw_init_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, &
                                                     recvcounts, rdispls, recvtypes, comm, info, request, &
                                                     ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Neighbor_alltoallw_init_f08ts
        
        SUBROUTINE MPI_Neighbor_alltoallw_init_c_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, &
                                                       recvcounts, rdispls, recvtypes, comm, info, request, &
                                                       ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Neighbor_alltoallw_init_c_f08ts
    END INTERFACE MPI_Neighbor_alltoallw_init
    
    INTERFACE MPI_Reduce
        SUBROUTINE MPI_Reduce_f08ts(sendbuf, recvbuf, count, datatype, op, root, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
            TYPE(*), DIMENSION(..) :: recvbuf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            INTEGER, INTENT(in) :: root
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Reduce_f08ts
        
        SUBROUTINE MPI_Reduce_c_f08ts(sendbuf, recvbuf, count, datatype, op, root, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
            TYPE(*), DIMENSION(..) :: recvbuf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            INTEGER, INTENT(in) :: root
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Reduce_c_f08ts
    END INTERFACE MPI_Reduce
    
    INTERFACE MPI_Reduce_init
        SUBROUTINE MPI_Reduce_init_f08ts(sendbuf, recvbuf, count, datatype, op, root, comm, info, request, &
                                         ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request
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
        END SUBROUTINE MPI_Reduce_init_f08ts
        
        SUBROUTINE MPI_Reduce_init_c_f08ts(sendbuf, recvbuf, count, datatype, op, root, comm, info, request, &
                                           ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
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
        END SUBROUTINE MPI_Reduce_init_c_f08ts
    END INTERFACE MPI_Reduce_init
    
    INTERFACE MPI_Reduce_local
        SUBROUTINE MPI_Reduce_local_f08ts(inbuf, inoutbuf, count, datatype, op, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: inbuf
            TYPE(*), DIMENSION(..), INTENT(inout) :: inoutbuf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Reduce_local_f08ts
        
        SUBROUTINE MPI_Reduce_local_c_f08ts(inbuf, inoutbuf, count, datatype, op, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: inbuf
            TYPE(*), DIMENSION(..), INTENT(inout) :: inoutbuf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Reduce_local_c_f08ts
    END INTERFACE MPI_Reduce_local
    
    INTERFACE MPI_Reduce_scatter
        SUBROUTINE MPI_Reduce_scatter_f08ts(sendbuf, recvbuf, recvcounts, datatype, op, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
            TYPE(*), DIMENSION(..) :: recvbuf
            INTEGER, INTENT(in) :: recvcounts(*)
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Reduce_scatter_f08ts
        
        SUBROUTINE MPI_Reduce_scatter_c_f08ts(sendbuf, recvbuf, recvcounts, datatype, op, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
            TYPE(*), DIMENSION(..) :: recvbuf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Reduce_scatter_c_f08ts
    END INTERFACE MPI_Reduce_scatter
    
    INTERFACE MPI_Reduce_scatter_block
        SUBROUTINE MPI_Reduce_scatter_block_f08ts(sendbuf, recvbuf, recvcount, datatype, op, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
            TYPE(*), DIMENSION(..) :: recvbuf
            INTEGER, INTENT(in) :: recvcount
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Reduce_scatter_block_f08ts
        
        SUBROUTINE MPI_Reduce_scatter_block_c_f08ts(sendbuf, recvbuf, recvcount, datatype, op, comm, &
                                                    ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
            TYPE(*), DIMENSION(..) :: recvbuf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcount
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Reduce_scatter_block_c_f08ts
    END INTERFACE MPI_Reduce_scatter_block
    
    INTERFACE MPI_Reduce_scatter_block_init
        SUBROUTINE MPI_Reduce_scatter_block_init_f08ts(sendbuf, recvbuf, recvcount, datatype, op, comm, &
                                                       info, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request
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
        END SUBROUTINE MPI_Reduce_scatter_block_init_f08ts
        
        SUBROUTINE MPI_Reduce_scatter_block_init_c_f08ts(sendbuf, recvbuf, recvcount, datatype, op, comm, &
                                                         info, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
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
        END SUBROUTINE MPI_Reduce_scatter_block_init_c_f08ts
    END INTERFACE MPI_Reduce_scatter_block_init
    
    INTERFACE MPI_Reduce_scatter_init
        SUBROUTINE MPI_Reduce_scatter_init_f08ts(sendbuf, recvbuf, recvcounts, datatype, op, comm, info, &
                                                 request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request
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
        END SUBROUTINE MPI_Reduce_scatter_init_f08ts
        
        SUBROUTINE MPI_Reduce_scatter_init_c_f08ts(sendbuf, recvbuf, recvcounts, datatype, op, comm, info, &
                                                   request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
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
        END SUBROUTINE MPI_Reduce_scatter_init_c_f08ts
    END INTERFACE MPI_Reduce_scatter_init
    
    INTERFACE MPI_Scan
        SUBROUTINE MPI_Scan_f08ts(sendbuf, recvbuf, count, datatype, op, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
            TYPE(*), DIMENSION(..) :: recvbuf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Scan_f08ts
        
        SUBROUTINE MPI_Scan_c_f08ts(sendbuf, recvbuf, count, datatype, op, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
            TYPE(*), DIMENSION(..) :: recvbuf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Scan_c_f08ts
    END INTERFACE MPI_Scan
    
    INTERFACE MPI_Scan_init
        SUBROUTINE MPI_Scan_init_f08ts(sendbuf, recvbuf, count, datatype, op, comm, info, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request
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
        END SUBROUTINE MPI_Scan_init_f08ts
        
        SUBROUTINE MPI_Scan_init_c_f08ts(sendbuf, recvbuf, count, datatype, op, comm, info, request, &
                                         ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
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
        END SUBROUTINE MPI_Scan_init_c_f08ts
    END INTERFACE MPI_Scan_init
    
    INTERFACE MPI_Scatter
        SUBROUTINE MPI_Scatter_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, &
                                     ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
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
        END SUBROUTINE MPI_Scatter_f08ts
        
        SUBROUTINE MPI_Scatter_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, &
                                       comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
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
        END SUBROUTINE MPI_Scatter_c_f08ts
    END INTERFACE MPI_Scatter
    
    INTERFACE MPI_Scatter_init
        SUBROUTINE MPI_Scatter_init_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, &
                                          comm, info, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
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
        END SUBROUTINE MPI_Scatter_init_f08ts
        
        SUBROUTINE MPI_Scatter_init_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
                                            root, comm, info, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
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
        END SUBROUTINE MPI_Scatter_init_c_f08ts
    END INTERFACE MPI_Scatter_init
    
    INTERFACE MPI_Scatterv
        SUBROUTINE MPI_Scatterv_f08ts(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, &
                                      root, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
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
        END SUBROUTINE MPI_Scatterv_f08ts
        
        SUBROUTINE MPI_Scatterv_c_f08ts(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, &
                                        root, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Scatterv_c_f08ts
    END INTERFACE MPI_Scatterv
    
    INTERFACE MPI_Scatterv_init
        SUBROUTINE MPI_Scatterv_init_f08ts(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, &
                                           recvtype, root, comm, info, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
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
        END SUBROUTINE MPI_Scatterv_init_f08ts
        
        SUBROUTINE MPI_Scatterv_init_c_f08ts(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, &
                                             recvtype, root, comm, info, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Scatterv_init_c_f08ts
    END INTERFACE MPI_Scatterv_init
    
    INTERFACE MPI_Comm_compare
        SUBROUTINE MPI_Comm_compare_f08(comm1, comm2, result, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm1
            TYPE(MPI_Comm), INTENT(in) :: comm2
            INTEGER, INTENT(out) :: result
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_compare_f08
    END INTERFACE MPI_Comm_compare
    
    INTERFACE MPI_Comm_create
        SUBROUTINE MPI_Comm_create_f08(comm, group, newcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Group), INTENT(in) :: group
            TYPE(MPI_Comm), INTENT(out) :: newcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_create_f08
    END INTERFACE MPI_Comm_create
    
    INTERFACE MPI_Comm_create_group
        SUBROUTINE MPI_Comm_create_group_f08(comm, group, tag, newcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Group), INTENT(in) :: group
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(out) :: newcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_create_group_f08
    END INTERFACE MPI_Comm_create_group
    
    INTERFACE MPI_Comm_dup
        SUBROUTINE MPI_Comm_dup_f08(comm, newcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Comm), INTENT(out) :: newcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_dup_f08
    END INTERFACE MPI_Comm_dup
    
    INTERFACE MPI_Comm_dup_with_info
        SUBROUTINE MPI_Comm_dup_with_info_f08(comm, info, newcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Info), INTENT(in) :: info
            TYPE(MPI_Comm), INTENT(out) :: newcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_dup_with_info_f08
    END INTERFACE MPI_Comm_dup_with_info
    
    INTERFACE MPI_Comm_free
        SUBROUTINE MPI_Comm_free_f08(comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(inout) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_free_f08
    END INTERFACE MPI_Comm_free
    
    INTERFACE MPI_Comm_get_info
        SUBROUTINE MPI_Comm_get_info_f08(comm, info_used, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Info), INTENT(out) :: info_used
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_get_info_f08
    END INTERFACE MPI_Comm_get_info
    
    INTERFACE MPI_Comm_get_name
        SUBROUTINE MPI_Comm_get_name_f08(comm, comm_name, resultlen, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_MAX_OBJECT_NAME
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            CHARACTER(len=MPI_MAX_OBJECT_NAME), INTENT(out) :: comm_name
            INTEGER, INTENT(out) :: resultlen
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_get_name_f08
    END INTERFACE MPI_Comm_get_name
    
    INTERFACE MPI_Comm_group
        SUBROUTINE MPI_Comm_group_f08(comm, group, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Group), INTENT(out) :: group
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_group_f08
    END INTERFACE MPI_Comm_group
    
    INTERFACE MPI_Comm_idup
        SUBROUTINE MPI_Comm_idup_f08(comm, newcomm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Request
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Comm), INTENT(out), ASYNCHRONOUS :: newcomm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_idup_f08
    END INTERFACE MPI_Comm_idup
    
    INTERFACE MPI_Comm_idup_with_info
        SUBROUTINE MPI_Comm_idup_with_info_f08(comm, info, newcomm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Info, MPI_Request
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Info), INTENT(in) :: info
            TYPE(MPI_Comm), INTENT(out), ASYNCHRONOUS :: newcomm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_idup_with_info_f08
    END INTERFACE MPI_Comm_idup_with_info
    
    INTERFACE MPI_Comm_rank
        SUBROUTINE MPI_Comm_rank_f08(comm, rank, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(out) :: rank
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_rank_f08
    END INTERFACE MPI_Comm_rank
    
    INTERFACE MPI_Comm_remote_group
        SUBROUTINE MPI_Comm_remote_group_f08(comm, group, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Group), INTENT(out) :: group
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_remote_group_f08
    END INTERFACE MPI_Comm_remote_group
    
    INTERFACE MPI_Comm_remote_size
        SUBROUTINE MPI_Comm_remote_size_f08(comm, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_remote_size_f08
    END INTERFACE MPI_Comm_remote_size
    
    INTERFACE MPI_Comm_set_info
        SUBROUTINE MPI_Comm_set_info_f08(comm, info, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Info), INTENT(in) :: info
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_set_info_f08
    END INTERFACE MPI_Comm_set_info
    
    INTERFACE MPI_Comm_set_name
        SUBROUTINE MPI_Comm_set_name_f08(comm, comm_name, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            CHARACTER(len=*), INTENT(in) :: comm_name
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_set_name_f08
    END INTERFACE MPI_Comm_set_name
    
    INTERFACE MPI_Comm_size
        SUBROUTINE MPI_Comm_size_f08(comm, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_size_f08
    END INTERFACE MPI_Comm_size
    
    INTERFACE MPI_Comm_split
        SUBROUTINE MPI_Comm_split_f08(comm, color, key, newcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: color
            INTEGER, INTENT(in) :: key
            TYPE(MPI_Comm), INTENT(out) :: newcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_split_f08
    END INTERFACE MPI_Comm_split
    
    INTERFACE MPI_Comm_split_type
        SUBROUTINE MPI_Comm_split_type_f08(comm, split_type, key, info, newcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: split_type
            INTEGER, INTENT(in) :: key
            TYPE(MPI_Info), INTENT(in) :: info
            TYPE(MPI_Comm), INTENT(out) :: newcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_split_type_f08
    END INTERFACE MPI_Comm_split_type
    
    INTERFACE MPI_Comm_test_inter
        SUBROUTINE MPI_Comm_test_inter_f08(comm, flag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            LOGICAL, INTENT(out) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_test_inter_f08
    END INTERFACE MPI_Comm_test_inter
    
    INTERFACE MPI_Intercomm_create
        SUBROUTINE MPI_Intercomm_create_f08(local_comm, local_leader, peer_comm, remote_leader, tag, &
                                            newintercomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: local_comm
            INTEGER, INTENT(in) :: local_leader
            TYPE(MPI_Comm), INTENT(in) :: peer_comm
            INTEGER, INTENT(in) :: remote_leader
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(out) :: newintercomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Intercomm_create_f08
    END INTERFACE MPI_Intercomm_create
    
    INTERFACE MPI_Intercomm_create_from_groups
        SUBROUTINE MPI_Intercomm_create_from_groups_f08(local_group, local_leader, remote_group, &
                                                        remote_leader, stringtag, info, errhandler, &
                                                        newintercomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Group, MPI_Info, MPI_Errhandler, MPI_Comm
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
        END SUBROUTINE MPI_Intercomm_create_from_groups_f08
    END INTERFACE MPI_Intercomm_create_from_groups
    
    INTERFACE MPI_Intercomm_merge
        SUBROUTINE MPI_Intercomm_merge_f08(intercomm, high, newintracomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: intercomm
            LOGICAL, INTENT(in) :: high
            TYPE(MPI_Comm), INTENT(out) :: newintracomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Intercomm_merge_f08
    END INTERFACE MPI_Intercomm_merge
    
    INTERFACE MPIX_Comm_test_threadcomm
        SUBROUTINE MPIX_Comm_test_threadcomm_f08(comm, flag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            LOGICAL, INTENT(out) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Comm_test_threadcomm_f08
    END INTERFACE MPIX_Comm_test_threadcomm
    
    INTERFACE MPIX_Comm_revoke
        SUBROUTINE MPIX_Comm_revoke_f08(comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Comm_revoke_f08
    END INTERFACE MPIX_Comm_revoke
    
    INTERFACE MPIX_Comm_shrink
        SUBROUTINE MPIX_Comm_shrink_f08(comm, newcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Comm), INTENT(out) :: newcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Comm_shrink_f08
    END INTERFACE MPIX_Comm_shrink
    
    INTERFACE MPIX_Comm_failure_ack
        SUBROUTINE MPIX_Comm_failure_ack_f08(comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Comm_failure_ack_f08
    END INTERFACE MPIX_Comm_failure_ack
    
    INTERFACE MPIX_Comm_failure_get_acked
        SUBROUTINE MPIX_Comm_failure_get_acked_f08(comm, failedgrp, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Group), INTENT(out) :: failedgrp
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Comm_failure_get_acked_f08
    END INTERFACE MPIX_Comm_failure_get_acked
    
    INTERFACE MPIX_Comm_agree
        SUBROUTINE MPIX_Comm_agree_f08(comm, flag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            LOGICAL, INTENT(out) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Comm_agree_f08
    END INTERFACE MPIX_Comm_agree
    
    INTERFACE MPIX_Comm_get_failed
        SUBROUTINE MPIX_Comm_get_failed_f08(comm, failedgrp, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Group), INTENT(out) :: failedgrp
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Comm_get_failed_f08
    END INTERFACE MPIX_Comm_get_failed
    
    INTERFACE MPI_Get_address
        SUBROUTINE MPI_Get_address_f08ts(location, address, ierror)
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: location
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: address
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Get_address_f08ts
    END INTERFACE MPI_Get_address
    
    INTERFACE MPI_Get_count
        SUBROUTINE MPI_Get_count_f08(status, datatype, count, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Status, MPI_Datatype
            IMPLICIT NONE
            TYPE(MPI_Status), INTENT(in), TARGET :: status
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(out) :: count
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Get_count_f08
        
        SUBROUTINE MPI_Get_count_c_f08(status, datatype, count, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Status, MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_Status), INTENT(in), TARGET :: status
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: count
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Get_count_c_f08
    END INTERFACE MPI_Get_count
    
    INTERFACE MPI_Get_elements
        SUBROUTINE MPI_Get_elements_f08(status, datatype, count, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Status, MPI_Datatype
            IMPLICIT NONE
            TYPE(MPI_Status), INTENT(in), TARGET :: status
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(out) :: count
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Get_elements_f08
        
        SUBROUTINE MPI_Get_elements_c_f08(status, datatype, count, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Status, MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_Status), INTENT(in), TARGET :: status
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: count
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Get_elements_c_f08
    END INTERFACE MPI_Get_elements
    
    INTERFACE MPI_Get_elements_x
        SUBROUTINE MPI_Get_elements_x_f08(status, datatype, count, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Status, MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_Status), INTENT(in), TARGET :: status
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: count
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Get_elements_x_f08
    END INTERFACE MPI_Get_elements_x
    
    INTERFACE MPI_Pack
        SUBROUTINE MPI_Pack_f08ts(inbuf, incount, datatype, outbuf, outsize, position, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: inbuf
            INTEGER, INTENT(in) :: incount
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(*), DIMENSION(..) :: outbuf
            INTEGER, INTENT(in) :: outsize
            INTEGER, INTENT(inout) :: position
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Pack_f08ts
        
        SUBROUTINE MPI_Pack_c_f08ts(inbuf, incount, datatype, outbuf, outsize, position, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: inbuf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: incount
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(*), DIMENSION(..) :: outbuf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: outsize
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(inout) :: position
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Pack_c_f08ts
    END INTERFACE MPI_Pack
    
    INTERFACE MPI_Pack_external
        SUBROUTINE MPI_Pack_external_f08ts(datarep, inbuf, incount, datatype, outbuf, outsize, position, &
                                           ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            CHARACTER(len=*), INTENT(in) :: datarep
            TYPE(*), DIMENSION(..), INTENT(in) :: inbuf
            INTEGER, INTENT(in) :: incount
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(*), DIMENSION(..) :: outbuf
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: outsize
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(inout) :: position
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Pack_external_f08ts
        
        SUBROUTINE MPI_Pack_external_c_f08ts(datarep, inbuf, incount, datatype, outbuf, outsize, position, &
                                             ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            CHARACTER(len=*), INTENT(in) :: datarep
            TYPE(*), DIMENSION(..), INTENT(in) :: inbuf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: incount
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(*), DIMENSION(..) :: outbuf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: outsize
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(inout) :: position
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Pack_external_c_f08ts
    END INTERFACE MPI_Pack_external
    
    INTERFACE MPI_Pack_external_size
        SUBROUTINE MPI_Pack_external_size_f08(datarep, incount, datatype, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            CHARACTER(len=*), INTENT(in) :: datarep
            INTEGER, INTENT(in) :: incount
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Pack_external_size_f08
        
        SUBROUTINE MPI_Pack_external_size_c_f08(datarep, incount, datatype, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            CHARACTER(len=*), INTENT(in) :: datarep
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: incount
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Pack_external_size_c_f08
    END INTERFACE MPI_Pack_external_size
    
    INTERFACE MPI_Pack_size
        SUBROUTINE MPI_Pack_size_f08(incount, datatype, comm, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            IMPLICIT NONE
            INTEGER, INTENT(in) :: incount
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Pack_size_f08
        
        SUBROUTINE MPI_Pack_size_c_f08(incount, datatype, comm, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: incount
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Pack_size_c_f08
    END INTERFACE MPI_Pack_size
    
    INTERFACE MPI_Status_set_elements
        SUBROUTINE MPI_Status_set_elements_f08(status, datatype, count, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Status, MPI_Datatype
            IMPLICIT NONE
            TYPE(MPI_Status), INTENT(inout), TARGET :: status
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: count
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Status_set_elements_f08
        
        SUBROUTINE MPI_Status_set_elements_c_f08(status, datatype, count, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Status, MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_Status), INTENT(inout), TARGET :: status
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Status_set_elements_c_f08
    END INTERFACE MPI_Status_set_elements
    
    INTERFACE MPI_Status_set_elements_x
        SUBROUTINE MPI_Status_set_elements_x_f08(status, datatype, count, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Status, MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_Status), INTENT(inout), TARGET :: status
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Status_set_elements_x_f08
    END INTERFACE MPI_Status_set_elements_x
    
    INTERFACE MPI_Type_commit
        SUBROUTINE MPI_Type_commit_f08(datatype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(inout) :: datatype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_commit_f08
    END INTERFACE MPI_Type_commit
    
    INTERFACE MPI_Type_contiguous
        SUBROUTINE MPI_Type_contiguous_f08(count, oldtype, newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: oldtype
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_contiguous_f08
        
        SUBROUTINE MPI_Type_contiguous_c_f08(count, oldtype, newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: oldtype
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_contiguous_c_f08
    END INTERFACE MPI_Type_contiguous
    
    INTERFACE MPI_Type_create_darray
        SUBROUTINE MPI_Type_create_darray_f08(size, rank, ndims, array_of_gsizes, array_of_distribs, &
                                              array_of_dargs, array_of_psizes, order, oldtype, newtype, &
                                              ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
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
        END SUBROUTINE MPI_Type_create_darray_f08
        
        SUBROUTINE MPI_Type_create_darray_c_f08(size, rank, ndims, array_of_gsizes, array_of_distribs, &
                                                array_of_dargs, array_of_psizes, order, oldtype, newtype, &
                                                ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
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
        END SUBROUTINE MPI_Type_create_darray_c_f08
    END INTERFACE MPI_Type_create_darray
    
    INTERFACE MPI_Type_create_f90_complex
        SUBROUTINE MPI_Type_create_f90_complex_f08(p, r, newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            INTEGER, INTENT(in) :: p
            INTEGER, INTENT(in) :: r
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_create_f90_complex_f08
    END INTERFACE MPI_Type_create_f90_complex
    
    INTERFACE MPI_Type_create_f90_integer
        SUBROUTINE MPI_Type_create_f90_integer_f08(r, newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            INTEGER, INTENT(in) :: r
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_create_f90_integer_f08
    END INTERFACE MPI_Type_create_f90_integer
    
    INTERFACE MPI_Type_create_f90_real
        SUBROUTINE MPI_Type_create_f90_real_f08(p, r, newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            INTEGER, INTENT(in) :: p
            INTEGER, INTENT(in) :: r
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_create_f90_real_f08
    END INTERFACE MPI_Type_create_f90_real
    
    INTERFACE MPI_Type_create_hindexed
        SUBROUTINE MPI_Type_create_hindexed_f08(count, array_of_blocklengths, array_of_displacements, &
                                                oldtype, newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            INTEGER, INTENT(in) :: count
            INTEGER, INTENT(in) :: array_of_blocklengths(count)
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: array_of_displacements(count)
            TYPE(MPI_Datatype), INTENT(in) :: oldtype
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_create_hindexed_f08
        
        SUBROUTINE MPI_Type_create_hindexed_c_f08(count, array_of_blocklengths, array_of_displacements, &
                                                  oldtype, newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_blocklengths(count)
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_displacements(count)
            TYPE(MPI_Datatype), INTENT(in) :: oldtype
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_create_hindexed_c_f08
    END INTERFACE MPI_Type_create_hindexed
    
    INTERFACE MPI_Type_create_hindexed_block
        SUBROUTINE MPI_Type_create_hindexed_block_f08(count, blocklength, array_of_displacements, oldtype, &
                                                      newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            INTEGER, INTENT(in) :: count
            INTEGER, INTENT(in) :: blocklength
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: array_of_displacements(count)
            TYPE(MPI_Datatype), INTENT(in) :: oldtype
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_create_hindexed_block_f08
        
        SUBROUTINE MPI_Type_create_hindexed_block_c_f08(count, blocklength, array_of_displacements, oldtype, &
                                                        newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: blocklength
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_displacements(count)
            TYPE(MPI_Datatype), INTENT(in) :: oldtype
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_create_hindexed_block_c_f08
    END INTERFACE MPI_Type_create_hindexed_block
    
    INTERFACE MPI_Type_create_hvector
        SUBROUTINE MPI_Type_create_hvector_f08(count, blocklength, stride, oldtype, newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            INTEGER, INTENT(in) :: count
            INTEGER, INTENT(in) :: blocklength
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: stride
            TYPE(MPI_Datatype), INTENT(in) :: oldtype
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_create_hvector_f08
        
        SUBROUTINE MPI_Type_create_hvector_c_f08(count, blocklength, stride, oldtype, newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: blocklength
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: stride
            TYPE(MPI_Datatype), INTENT(in) :: oldtype
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_create_hvector_c_f08
    END INTERFACE MPI_Type_create_hvector
    
    INTERFACE MPI_Type_create_indexed_block
        SUBROUTINE MPI_Type_create_indexed_block_f08(count, blocklength, array_of_displacements, oldtype, &
                                                     newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            INTEGER, INTENT(in) :: count
            INTEGER, INTENT(in) :: blocklength
            INTEGER, INTENT(in) :: array_of_displacements(count)
            TYPE(MPI_Datatype), INTENT(in) :: oldtype
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_create_indexed_block_f08
        
        SUBROUTINE MPI_Type_create_indexed_block_c_f08(count, blocklength, array_of_displacements, oldtype, &
                                                       newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: blocklength
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_displacements(count)
            TYPE(MPI_Datatype), INTENT(in) :: oldtype
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_create_indexed_block_c_f08
    END INTERFACE MPI_Type_create_indexed_block
    
    INTERFACE MPI_Type_create_resized
        SUBROUTINE MPI_Type_create_resized_f08(oldtype, lb, extent, newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: oldtype
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: lb
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: extent
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_create_resized_f08
    END INTERFACE MPI_Type_create_resized
    
    INTERFACE MPI_Type_create_struct
        SUBROUTINE MPI_Type_create_struct_f08(count, array_of_blocklengths, array_of_displacements, &
                                              array_of_types, newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            INTEGER, INTENT(in) :: count
            INTEGER, INTENT(in) :: array_of_blocklengths(count)
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: array_of_displacements(count)
            TYPE(MPI_Datatype), INTENT(in) :: array_of_types(count)
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_create_struct_f08
        
        SUBROUTINE MPI_Type_create_struct_c_f08(count, array_of_blocklengths, array_of_displacements, &
                                                array_of_types, newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_blocklengths(count)
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_displacements(count)
            TYPE(MPI_Datatype), INTENT(in) :: array_of_types(count)
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_create_struct_c_f08
    END INTERFACE MPI_Type_create_struct
    
    INTERFACE MPI_Type_create_subarray
        SUBROUTINE MPI_Type_create_subarray_f08(ndims, array_of_sizes, array_of_subsizes, array_of_starts, &
                                                order, oldtype, newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            INTEGER, INTENT(in) :: ndims
            INTEGER, INTENT(in) :: array_of_sizes(ndims)
            INTEGER, INTENT(in) :: array_of_subsizes(ndims)
            INTEGER, INTENT(in) :: array_of_starts(ndims)
            INTEGER, INTENT(in) :: order
            TYPE(MPI_Datatype), INTENT(in) :: oldtype
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_create_subarray_f08
        
        SUBROUTINE MPI_Type_create_subarray_c_f08(ndims, array_of_sizes, array_of_subsizes, array_of_starts, &
                                                  order, oldtype, newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            INTEGER, INTENT(in) :: ndims
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_sizes(ndims)
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_subsizes(ndims)
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_starts(ndims)
            INTEGER, INTENT(in) :: order
            TYPE(MPI_Datatype), INTENT(in) :: oldtype
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_create_subarray_c_f08
    END INTERFACE MPI_Type_create_subarray
    
    INTERFACE MPI_Type_dup
        SUBROUTINE MPI_Type_dup_f08(oldtype, newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: oldtype
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_dup_f08
    END INTERFACE MPI_Type_dup
    
    INTERFACE MPI_Type_free
        SUBROUTINE MPI_Type_free_f08(datatype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(inout) :: datatype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_free_f08
    END INTERFACE MPI_Type_free
    
    INTERFACE MPI_Type_get_contents
        SUBROUTINE MPI_Type_get_contents_f08(datatype, max_integers, max_addresses, max_datatypes, &
                                             array_of_integers, array_of_addresses, array_of_datatypes, &
                                             ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: max_integers
            INTEGER, INTENT(in) :: max_addresses
            INTEGER, INTENT(in) :: max_datatypes
            INTEGER, INTENT(out) :: array_of_integers(max_integers)
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: array_of_addresses(max_addresses)
            TYPE(MPI_Datatype), INTENT(out) :: array_of_datatypes(max_datatypes)
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_get_contents_f08
        
        SUBROUTINE MPI_Type_get_contents_c_f08(datatype, max_integers, max_addresses, max_large_counts, &
                                               max_datatypes, array_of_integers, array_of_addresses, &
                                               array_of_large_counts, array_of_datatypes, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Type_get_contents_c_f08
    END INTERFACE MPI_Type_get_contents
    
    INTERFACE MPI_Type_get_envelope
        SUBROUTINE MPI_Type_get_envelope_f08(datatype, num_integers, num_addresses, num_datatypes, combiner, &
                                             ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(out) :: num_integers
            INTEGER, INTENT(out) :: num_addresses
            INTEGER, INTENT(out) :: num_datatypes
            INTEGER, INTENT(out) :: combiner
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_get_envelope_f08
        
        SUBROUTINE MPI_Type_get_envelope_c_f08(datatype, num_integers, num_addresses, num_large_counts, &
                                               num_datatypes, combiner, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: num_integers
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: num_addresses
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: num_large_counts
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: num_datatypes
            INTEGER, INTENT(out) :: combiner
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_get_envelope_c_f08
    END INTERFACE MPI_Type_get_envelope
    
    INTERFACE MPI_Type_get_extent
        SUBROUTINE MPI_Type_get_extent_f08(datatype, lb, extent, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: lb
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: extent
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_get_extent_f08
    END INTERFACE MPI_Type_get_extent
    
    INTERFACE MPI_Type_get_extent_x
        SUBROUTINE MPI_Type_get_extent_x_f08(datatype, lb, extent, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: lb
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: extent
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_get_extent_x_f08
    END INTERFACE MPI_Type_get_extent_x
    
    INTERFACE MPI_Type_get_name
        SUBROUTINE MPI_Type_get_name_f08(datatype, type_name, resultlen, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_MAX_OBJECT_NAME
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            CHARACTER(len=MPI_MAX_OBJECT_NAME), INTENT(out) :: type_name
            INTEGER, INTENT(out) :: resultlen
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_get_name_f08
    END INTERFACE MPI_Type_get_name
    
    INTERFACE MPI_Type_get_true_extent
        SUBROUTINE MPI_Type_get_true_extent_f08(datatype, true_lb, true_extent, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: true_lb
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: true_extent
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_get_true_extent_f08
    END INTERFACE MPI_Type_get_true_extent
    
    INTERFACE MPI_Type_get_true_extent_x
        SUBROUTINE MPI_Type_get_true_extent_x_f08(datatype, true_lb, true_extent, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: true_lb
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: true_extent
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_get_true_extent_x_f08
    END INTERFACE MPI_Type_get_true_extent_x
    
    INTERFACE MPI_Type_get_value_index
        SUBROUTINE MPI_Type_get_value_index_f08(value_type, index_type, pair_type, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: value_type
            TYPE(MPI_Datatype), INTENT(in) :: index_type
            TYPE(MPI_Datatype), INTENT(out) :: pair_type
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_get_value_index_f08
    END INTERFACE MPI_Type_get_value_index
    
    INTERFACE MPI_Type_indexed
        SUBROUTINE MPI_Type_indexed_f08(count, array_of_blocklengths, array_of_displacements, oldtype, &
                                        newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            INTEGER, INTENT(in) :: count
            INTEGER, INTENT(in) :: array_of_blocklengths(count)
            INTEGER, INTENT(in) :: array_of_displacements(count)
            TYPE(MPI_Datatype), INTENT(in) :: oldtype
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_indexed_f08
        
        SUBROUTINE MPI_Type_indexed_c_f08(count, array_of_blocklengths, array_of_displacements, oldtype, &
                                          newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_blocklengths(count)
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: array_of_displacements(count)
            TYPE(MPI_Datatype), INTENT(in) :: oldtype
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_indexed_c_f08
    END INTERFACE MPI_Type_indexed
    
    INTERFACE MPI_Type_match_size
        SUBROUTINE MPI_Type_match_size_f08(typeclass, size, datatype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            INTEGER, INTENT(in) :: typeclass
            INTEGER, INTENT(in) :: size
            TYPE(MPI_Datatype), INTENT(out) :: datatype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_match_size_f08
    END INTERFACE MPI_Type_match_size
    
    INTERFACE MPI_Type_set_name
        SUBROUTINE MPI_Type_set_name_f08(datatype, type_name, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            CHARACTER(len=*), INTENT(in) :: type_name
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_set_name_f08
    END INTERFACE MPI_Type_set_name
    
    INTERFACE MPI_Type_size
        SUBROUTINE MPI_Type_size_f08(datatype, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_size_f08
        
        SUBROUTINE MPI_Type_size_c_f08(datatype, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_size_c_f08
    END INTERFACE MPI_Type_size
    
    INTERFACE MPI_Type_size_x
        SUBROUTINE MPI_Type_size_x_f08(datatype, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_size_x_f08
    END INTERFACE MPI_Type_size_x
    
    INTERFACE MPI_Type_vector
        SUBROUTINE MPI_Type_vector_f08(count, blocklength, stride, oldtype, newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            INTEGER, INTENT(in) :: count
            INTEGER, INTENT(in) :: blocklength
            INTEGER, INTENT(in) :: stride
            TYPE(MPI_Datatype), INTENT(in) :: oldtype
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_vector_f08
        
        SUBROUTINE MPI_Type_vector_c_f08(count, blocklength, stride, oldtype, newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: blocklength
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: stride
            TYPE(MPI_Datatype), INTENT(in) :: oldtype
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Type_vector_c_f08
    END INTERFACE MPI_Type_vector
    
    INTERFACE MPI_Unpack
        SUBROUTINE MPI_Unpack_f08ts(inbuf, insize, position, outbuf, outcount, datatype, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: inbuf
            INTEGER, INTENT(in) :: insize
            INTEGER, INTENT(inout) :: position
            TYPE(*), DIMENSION(..) :: outbuf
            INTEGER, INTENT(in) :: outcount
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Unpack_f08ts
        
        SUBROUTINE MPI_Unpack_c_f08ts(inbuf, insize, position, outbuf, outcount, datatype, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: inbuf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: insize
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(inout) :: position
            TYPE(*), DIMENSION(..) :: outbuf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: outcount
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Unpack_c_f08ts
    END INTERFACE MPI_Unpack
    
    INTERFACE MPI_Unpack_external
        SUBROUTINE MPI_Unpack_external_f08ts(datarep, inbuf, insize, position, outbuf, outcount, datatype, &
                                             ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            CHARACTER(len=*), INTENT(in) :: datarep
            TYPE(*), DIMENSION(..), INTENT(in) :: inbuf
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: insize
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(inout) :: position
            TYPE(*), DIMENSION(..) :: outbuf
            INTEGER, INTENT(in) :: outcount
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Unpack_external_f08ts
        
        SUBROUTINE MPI_Unpack_external_c_f08ts(datarep, inbuf, insize, position, outbuf, outcount, datatype, &
                                               ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            CHARACTER(len=*), INTENT(in) :: datarep
            TYPE(*), DIMENSION(..), INTENT(in) :: inbuf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: insize
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(inout) :: position
            TYPE(*), DIMENSION(..) :: outbuf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: outcount
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Unpack_external_c_f08ts
    END INTERFACE MPI_Unpack_external
    
    INTERFACE MPI_Add_error_class
        SUBROUTINE MPI_Add_error_class_f08(errorclass, ierror)
            IMPLICIT NONE
            INTEGER, INTENT(out) :: errorclass
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Add_error_class_f08
    END INTERFACE MPI_Add_error_class
    
    INTERFACE MPI_Add_error_code
        SUBROUTINE MPI_Add_error_code_f08(errorclass, errorcode, ierror)
            IMPLICIT NONE
            INTEGER, INTENT(in) :: errorclass
            INTEGER, INTENT(out) :: errorcode
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Add_error_code_f08
    END INTERFACE MPI_Add_error_code
    
    INTERFACE MPI_Add_error_string
        SUBROUTINE MPI_Add_error_string_f08(errorcode, string, ierror)
            IMPLICIT NONE
            INTEGER, INTENT(in) :: errorcode
            CHARACTER(len=*), INTENT(in) :: string
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Add_error_string_f08
    END INTERFACE MPI_Add_error_string
    
    INTERFACE MPI_Comm_call_errhandler
        SUBROUTINE MPI_Comm_call_errhandler_f08(comm, errorcode, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: errorcode
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_call_errhandler_f08
    END INTERFACE MPI_Comm_call_errhandler
    
    INTERFACE MPI_Comm_create_errhandler
        SUBROUTINE MPI_Comm_create_errhandler_f08(comm_errhandler_fn, errhandler, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Errhandler
            USE :: mpi_f08_callbacks, ONLY : MPI_Comm_errhandler_function
            IMPLICIT NONE
            PROCEDURE(MPI_Comm_errhandler_function) :: comm_errhandler_fn
            TYPE(MPI_Errhandler), INTENT(out) :: errhandler
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_create_errhandler_f08
    END INTERFACE MPI_Comm_create_errhandler
    
    INTERFACE MPI_Comm_get_errhandler
        SUBROUTINE MPI_Comm_get_errhandler_f08(comm, errhandler, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Errhandler
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Errhandler), INTENT(out) :: errhandler
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_get_errhandler_f08
    END INTERFACE MPI_Comm_get_errhandler
    
    INTERFACE MPI_Comm_set_errhandler
        SUBROUTINE MPI_Comm_set_errhandler_f08(comm, errhandler, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Errhandler
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Errhandler), INTENT(in) :: errhandler
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_set_errhandler_f08
    END INTERFACE MPI_Comm_set_errhandler
    
    INTERFACE MPI_Errhandler_free
        SUBROUTINE MPI_Errhandler_free_f08(errhandler, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Errhandler
            IMPLICIT NONE
            TYPE(MPI_Errhandler), INTENT(inout) :: errhandler
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Errhandler_free_f08
    END INTERFACE MPI_Errhandler_free
    
    INTERFACE MPI_Error_class
        SUBROUTINE MPI_Error_class_f08(errorcode, errorclass, ierror)
            IMPLICIT NONE
            INTEGER, INTENT(in) :: errorcode
            INTEGER, INTENT(out) :: errorclass
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Error_class_f08
    END INTERFACE MPI_Error_class
    
    INTERFACE MPI_Error_string
        SUBROUTINE MPI_Error_string_f08(errorcode, string, resultlen, ierror)
            USE :: mpi_f08_compile_constants, ONLY : MPI_MAX_ERROR_STRING
            IMPLICIT NONE
            INTEGER, INTENT(in) :: errorcode
            CHARACTER(len=MPI_MAX_ERROR_STRING), INTENT(out) :: string
            INTEGER, INTENT(out) :: resultlen
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Error_string_f08
    END INTERFACE MPI_Error_string
    
    INTERFACE MPI_File_call_errhandler
        SUBROUTINE MPI_File_call_errhandler_f08(fh, errorcode, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER, INTENT(in) :: errorcode
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_call_errhandler_f08
    END INTERFACE MPI_File_call_errhandler
    
    INTERFACE MPI_File_create_errhandler
        SUBROUTINE MPI_File_create_errhandler_f08(file_errhandler_fn, errhandler, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Errhandler
            USE :: mpi_f08_callbacks, ONLY : MPI_File_errhandler_function
            IMPLICIT NONE
            PROCEDURE(MPI_File_errhandler_function) :: file_errhandler_fn
            TYPE(MPI_Errhandler), INTENT(out) :: errhandler
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_create_errhandler_f08
    END INTERFACE MPI_File_create_errhandler
    
    INTERFACE MPI_File_get_errhandler
        SUBROUTINE MPI_File_get_errhandler_f08(file, errhandler, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Errhandler
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: file
            TYPE(MPI_Errhandler), INTENT(out) :: errhandler
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_get_errhandler_f08
    END INTERFACE MPI_File_get_errhandler
    
    INTERFACE MPI_File_set_errhandler
        SUBROUTINE MPI_File_set_errhandler_f08(file, errhandler, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Errhandler
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: file
            TYPE(MPI_Errhandler), INTENT(in) :: errhandler
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_set_errhandler_f08
    END INTERFACE MPI_File_set_errhandler
    
    INTERFACE MPI_Remove_error_class
        SUBROUTINE MPI_Remove_error_class_f08(errorclass, ierror)
            IMPLICIT NONE
            INTEGER, INTENT(in) :: errorclass
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Remove_error_class_f08
    END INTERFACE MPI_Remove_error_class
    
    INTERFACE MPI_Remove_error_code
        SUBROUTINE MPI_Remove_error_code_f08(errorcode, ierror)
            IMPLICIT NONE
            INTEGER, INTENT(in) :: errorcode
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Remove_error_code_f08
    END INTERFACE MPI_Remove_error_code
    
    INTERFACE MPI_Remove_error_string
        SUBROUTINE MPI_Remove_error_string_f08(errorcode, ierror)
            IMPLICIT NONE
            INTEGER, INTENT(in) :: errorcode
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Remove_error_string_f08
    END INTERFACE MPI_Remove_error_string
    
    INTERFACE MPI_Session_call_errhandler
        SUBROUTINE MPI_Session_call_errhandler_f08(session, errorcode, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Session
            IMPLICIT NONE
            TYPE(MPI_Session), INTENT(in) :: session
            INTEGER, INTENT(in) :: errorcode
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Session_call_errhandler_f08
    END INTERFACE MPI_Session_call_errhandler
    
    INTERFACE MPI_Session_create_errhandler
        SUBROUTINE MPI_Session_create_errhandler_f08(session_errhandler_fn, errhandler, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Errhandler
            USE :: mpi_f08_callbacks, ONLY : MPI_Session_errhandler_function
            IMPLICIT NONE
            PROCEDURE(MPI_Session_errhandler_function) :: session_errhandler_fn
            TYPE(MPI_Errhandler), INTENT(out) :: errhandler
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Session_create_errhandler_f08
    END INTERFACE MPI_Session_create_errhandler
    
    INTERFACE MPI_Session_get_errhandler
        SUBROUTINE MPI_Session_get_errhandler_f08(session, errhandler, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Session, MPI_Errhandler
            IMPLICIT NONE
            TYPE(MPI_Session), INTENT(in) :: session
            TYPE(MPI_Errhandler), INTENT(out) :: errhandler
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Session_get_errhandler_f08
    END INTERFACE MPI_Session_get_errhandler
    
    INTERFACE MPI_Session_set_errhandler
        SUBROUTINE MPI_Session_set_errhandler_f08(session, errhandler, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Session, MPI_Errhandler
            IMPLICIT NONE
            TYPE(MPI_Session), INTENT(in) :: session
            TYPE(MPI_Errhandler), INTENT(in) :: errhandler
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Session_set_errhandler_f08
    END INTERFACE MPI_Session_set_errhandler
    
    INTERFACE MPI_Win_call_errhandler
        SUBROUTINE MPI_Win_call_errhandler_f08(win, errorcode, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, INTENT(in) :: errorcode
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_call_errhandler_f08
    END INTERFACE MPI_Win_call_errhandler
    
    INTERFACE MPI_Win_create_errhandler
        SUBROUTINE MPI_Win_create_errhandler_f08(win_errhandler_fn, errhandler, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Errhandler
            USE :: mpi_f08_callbacks, ONLY : MPI_Win_errhandler_function
            IMPLICIT NONE
            PROCEDURE(MPI_Win_errhandler_function) :: win_errhandler_fn
            TYPE(MPI_Errhandler), INTENT(out) :: errhandler
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_create_errhandler_f08
    END INTERFACE MPI_Win_create_errhandler
    
    INTERFACE MPI_Win_get_errhandler
        SUBROUTINE MPI_Win_get_errhandler_f08(win, errhandler, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win, MPI_Errhandler
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            TYPE(MPI_Errhandler), INTENT(out) :: errhandler
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_get_errhandler_f08
    END INTERFACE MPI_Win_get_errhandler
    
    INTERFACE MPI_Win_set_errhandler
        SUBROUTINE MPI_Win_set_errhandler_f08(win, errhandler, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win, MPI_Errhandler
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            TYPE(MPI_Errhandler), INTENT(in) :: errhandler
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_set_errhandler_f08
    END INTERFACE MPI_Win_set_errhandler
    
    INTERFACE MPI_Group_compare
        SUBROUTINE MPI_Group_compare_f08(group1, group2, result, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Group), INTENT(in) :: group1
            TYPE(MPI_Group), INTENT(in) :: group2
            INTEGER, INTENT(out) :: result
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Group_compare_f08
    END INTERFACE MPI_Group_compare
    
    INTERFACE MPI_Group_difference
        SUBROUTINE MPI_Group_difference_f08(group1, group2, newgroup, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Group), INTENT(in) :: group1
            TYPE(MPI_Group), INTENT(in) :: group2
            TYPE(MPI_Group), INTENT(out) :: newgroup
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Group_difference_f08
    END INTERFACE MPI_Group_difference
    
    INTERFACE MPI_Group_excl
        SUBROUTINE MPI_Group_excl_f08(group, n, ranks, newgroup, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Group), INTENT(in) :: group
            INTEGER, INTENT(in) :: n
            INTEGER, INTENT(in) :: ranks(n)
            TYPE(MPI_Group), INTENT(out) :: newgroup
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Group_excl_f08
    END INTERFACE MPI_Group_excl
    
    INTERFACE MPI_Group_free
        SUBROUTINE MPI_Group_free_f08(group, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Group), INTENT(inout) :: group
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Group_free_f08
    END INTERFACE MPI_Group_free
    
    INTERFACE MPI_Group_incl
        SUBROUTINE MPI_Group_incl_f08(group, n, ranks, newgroup, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Group), INTENT(in) :: group
            INTEGER, INTENT(in) :: n
            INTEGER, INTENT(in) :: ranks(n)
            TYPE(MPI_Group), INTENT(out) :: newgroup
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Group_incl_f08
    END INTERFACE MPI_Group_incl
    
    INTERFACE MPI_Group_intersection
        SUBROUTINE MPI_Group_intersection_f08(group1, group2, newgroup, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Group), INTENT(in) :: group1
            TYPE(MPI_Group), INTENT(in) :: group2
            TYPE(MPI_Group), INTENT(out) :: newgroup
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Group_intersection_f08
    END INTERFACE MPI_Group_intersection
    
    INTERFACE MPI_Group_range_excl
        SUBROUTINE MPI_Group_range_excl_f08(group, n, ranges, newgroup, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Group), INTENT(in) :: group
            INTEGER, INTENT(in) :: n
            INTEGER, INTENT(in) :: ranges(n, 3)
            TYPE(MPI_Group), INTENT(out) :: newgroup
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Group_range_excl_f08
    END INTERFACE MPI_Group_range_excl
    
    INTERFACE MPI_Group_range_incl
        SUBROUTINE MPI_Group_range_incl_f08(group, n, ranges, newgroup, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Group), INTENT(in) :: group
            INTEGER, INTENT(in) :: n
            INTEGER, INTENT(in) :: ranges(n, 3)
            TYPE(MPI_Group), INTENT(out) :: newgroup
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Group_range_incl_f08
    END INTERFACE MPI_Group_range_incl
    
    INTERFACE MPI_Group_rank
        SUBROUTINE MPI_Group_rank_f08(group, rank, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Group), INTENT(in) :: group
            INTEGER, INTENT(out) :: rank
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Group_rank_f08
    END INTERFACE MPI_Group_rank
    
    INTERFACE MPI_Group_size
        SUBROUTINE MPI_Group_size_f08(group, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Group), INTENT(in) :: group
            INTEGER, INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Group_size_f08
    END INTERFACE MPI_Group_size
    
    INTERFACE MPI_Group_translate_ranks
        SUBROUTINE MPI_Group_translate_ranks_f08(group1, n, ranks1, group2, ranks2, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Group), INTENT(in) :: group1
            INTEGER, INTENT(in) :: n
            INTEGER, INTENT(in) :: ranks1(n)
            TYPE(MPI_Group), INTENT(in) :: group2
            INTEGER, INTENT(out) :: ranks2(n)
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Group_translate_ranks_f08
    END INTERFACE MPI_Group_translate_ranks
    
    INTERFACE MPI_Group_union
        SUBROUTINE MPI_Group_union_f08(group1, group2, newgroup, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Group), INTENT(in) :: group1
            TYPE(MPI_Group), INTENT(in) :: group2
            TYPE(MPI_Group), INTENT(out) :: newgroup
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Group_union_f08
    END INTERFACE MPI_Group_union
    
    INTERFACE MPI_Info_create
        SUBROUTINE MPI_Info_create_f08(info, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(out) :: info
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Info_create_f08
    END INTERFACE MPI_Info_create
    
    INTERFACE MPI_Info_create_env
        SUBROUTINE MPI_Info_create_env_f08(info, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(out) :: info
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Info_create_env_f08
    END INTERFACE MPI_Info_create_env
    
    INTERFACE MPI_Info_delete
        SUBROUTINE MPI_Info_delete_f08(info, key, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(in) :: info
            CHARACTER(len=*), INTENT(in) :: key
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Info_delete_f08
    END INTERFACE MPI_Info_delete
    
    INTERFACE MPI_Info_dup
        SUBROUTINE MPI_Info_dup_f08(info, newinfo, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(in) :: info
            TYPE(MPI_Info), INTENT(out) :: newinfo
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Info_dup_f08
    END INTERFACE MPI_Info_dup
    
    INTERFACE MPI_Info_free
        SUBROUTINE MPI_Info_free_f08(info, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(inout) :: info
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Info_free_f08
    END INTERFACE MPI_Info_free
    
    INTERFACE MPI_Info_get
        SUBROUTINE MPI_Info_get_f08(info, key, valuelen, value, flag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(in) :: info
            CHARACTER(len=*), INTENT(in) :: key
            INTEGER, INTENT(in) :: valuelen
            CHARACTER(len=valuelen), INTENT(out) :: value
            LOGICAL, INTENT(out) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Info_get_f08
    END INTERFACE MPI_Info_get
    
    INTERFACE MPI_Info_get_nkeys
        SUBROUTINE MPI_Info_get_nkeys_f08(info, nkeys, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(in) :: info
            INTEGER, INTENT(out) :: nkeys
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Info_get_nkeys_f08
    END INTERFACE MPI_Info_get_nkeys
    
    INTERFACE MPI_Info_get_nthkey
        SUBROUTINE MPI_Info_get_nthkey_f08(info, n, key, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(in) :: info
            INTEGER, INTENT(in) :: n
            CHARACTER(len=*), INTENT(out) :: key
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Info_get_nthkey_f08
    END INTERFACE MPI_Info_get_nthkey
    
    INTERFACE MPI_Info_get_string
        SUBROUTINE MPI_Info_get_string_f08(info, key, buflen, value, flag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(in) :: info
            CHARACTER(len=*), INTENT(in) :: key
            INTEGER, INTENT(inout) :: buflen
            CHARACTER(len=*), INTENT(out) :: value
            LOGICAL, INTENT(out) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Info_get_string_f08
    END INTERFACE MPI_Info_get_string
    
    INTERFACE MPI_Info_get_valuelen
        SUBROUTINE MPI_Info_get_valuelen_f08(info, key, valuelen, flag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(in) :: info
            CHARACTER(len=*), INTENT(in) :: key
            INTEGER, INTENT(out) :: valuelen
            LOGICAL, INTENT(out) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Info_get_valuelen_f08
    END INTERFACE MPI_Info_get_valuelen
    
    INTERFACE MPI_Info_set
        SUBROUTINE MPI_Info_set_f08(info, key, value, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(in) :: info
            CHARACTER(len=*), INTENT(in) :: key
            CHARACTER(len=*), INTENT(in) :: value
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Info_set_f08
    END INTERFACE MPI_Info_set
    
    INTERFACE MPIX_Info_set_hex
        SUBROUTINE MPIX_Info_set_hex_f08ts(info, key, value, value_size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(in) :: info
            CHARACTER(len=*), INTENT(in) :: key
            TYPE(*), DIMENSION(..), INTENT(in) :: value
            INTEGER, INTENT(in) :: value_size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Info_set_hex_f08ts
    END INTERFACE MPIX_Info_set_hex
    
    INTERFACE MPI_Abort
        SUBROUTINE MPI_Abort_f08(comm, errorcode, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: errorcode
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Abort_f08
    END INTERFACE MPI_Abort
    
    INTERFACE MPI_Comm_create_from_group
        SUBROUTINE MPI_Comm_create_from_group_f08(group, stringtag, info, errhandler, newcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Group, MPI_Info, MPI_Errhandler, MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Group), INTENT(in) :: group
            CHARACTER(len=*), INTENT(in) :: stringtag
            TYPE(MPI_Info), INTENT(in) :: info
            TYPE(MPI_Errhandler), INTENT(in) :: errhandler
            TYPE(MPI_Comm), INTENT(out) :: newcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_create_from_group_f08
    END INTERFACE MPI_Comm_create_from_group
    
    INTERFACE MPI_Finalize
        SUBROUTINE MPI_Finalize_f08(ierror)
            IMPLICIT NONE
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Finalize_f08
    END INTERFACE MPI_Finalize
    
    INTERFACE MPI_Finalized
        SUBROUTINE MPI_Finalized_f08(flag, ierror)
            IMPLICIT NONE
            LOGICAL, INTENT(out) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Finalized_f08
    END INTERFACE MPI_Finalized
    
    INTERFACE MPI_Group_from_session_pset
        SUBROUTINE MPI_Group_from_session_pset_f08(session, pset_name, newgroup, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Session, MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Session), INTENT(in) :: session
            CHARACTER(len=*), INTENT(in) :: pset_name
            TYPE(MPI_Group), INTENT(out) :: newgroup
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Group_from_session_pset_f08
    END INTERFACE MPI_Group_from_session_pset
    
    INTERFACE MPI_Init
        SUBROUTINE MPI_Init_f08(ierror)
            IMPLICIT NONE
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Init_f08
    END INTERFACE MPI_Init
    
    INTERFACE MPI_Init_thread
        SUBROUTINE MPI_Init_thread_f08(required, provided, ierror)
            IMPLICIT NONE
            INTEGER, INTENT(in) :: required
            INTEGER, INTENT(out) :: provided
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Init_thread_f08
    END INTERFACE MPI_Init_thread
    
    INTERFACE MPI_Initialized
        SUBROUTINE MPI_Initialized_f08(flag, ierror)
            IMPLICIT NONE
            LOGICAL, INTENT(out) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Initialized_f08
    END INTERFACE MPI_Initialized
    
    INTERFACE MPI_Is_thread_main
        SUBROUTINE MPI_Is_thread_main_f08(flag, ierror)
            IMPLICIT NONE
            LOGICAL, INTENT(out) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Is_thread_main_f08
    END INTERFACE MPI_Is_thread_main
    
    INTERFACE MPI_Query_thread
        SUBROUTINE MPI_Query_thread_f08(provided, ierror)
            IMPLICIT NONE
            INTEGER, INTENT(out) :: provided
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Query_thread_f08
    END INTERFACE MPI_Query_thread
    
    INTERFACE MPI_Session_finalize
        SUBROUTINE MPI_Session_finalize_f08(session, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Session
            IMPLICIT NONE
            TYPE(MPI_Session), INTENT(inout) :: session
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Session_finalize_f08
    END INTERFACE MPI_Session_finalize
    
    INTERFACE MPI_Session_get_info
        SUBROUTINE MPI_Session_get_info_f08(session, info_used, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Session, MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Session), INTENT(in) :: session
            TYPE(MPI_Info), INTENT(out) :: info_used
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Session_get_info_f08
    END INTERFACE MPI_Session_get_info
    
    INTERFACE MPI_Session_get_nth_pset
        SUBROUTINE MPI_Session_get_nth_pset_f08(session, info, n, pset_len, pset_name, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Session, MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Session), INTENT(in) :: session
            TYPE(MPI_Info), INTENT(in) :: info
            INTEGER, INTENT(in) :: n
            INTEGER, INTENT(inout) :: pset_len
            CHARACTER(len=*), INTENT(out) :: pset_name
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Session_get_nth_pset_f08
    END INTERFACE MPI_Session_get_nth_pset
    
    INTERFACE MPI_Session_get_num_psets
        SUBROUTINE MPI_Session_get_num_psets_f08(session, info, npset_names, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Session, MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Session), INTENT(in) :: session
            TYPE(MPI_Info), INTENT(in) :: info
            INTEGER, INTENT(out) :: npset_names
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Session_get_num_psets_f08
    END INTERFACE MPI_Session_get_num_psets
    
    INTERFACE MPI_Session_get_pset_info
        SUBROUTINE MPI_Session_get_pset_info_f08(session, pset_name, info, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Session, MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Session), INTENT(in) :: session
            CHARACTER(len=*), INTENT(in) :: pset_name
            TYPE(MPI_Info), INTENT(out) :: info
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Session_get_pset_info_f08
    END INTERFACE MPI_Session_get_pset_info
    
    INTERFACE MPI_Session_init
        SUBROUTINE MPI_Session_init_f08(info, errhandler, session, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info, MPI_Errhandler, MPI_Session
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(in) :: info
            TYPE(MPI_Errhandler), INTENT(in) :: errhandler
            TYPE(MPI_Session), INTENT(out) :: session
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Session_init_f08
    END INTERFACE MPI_Session_init
    
    INTERFACE MPI_Aint_add
        FUNCTION MPI_Aint_add_f08(base, disp) result(res)
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: base
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: disp
            INTEGER(KIND=MPI_ADDRESS_KIND) :: res
        END FUNCTION MPI_Aint_add_f08
    END INTERFACE MPI_Aint_add
    
    INTERFACE MPI_Aint_diff
        FUNCTION MPI_Aint_diff_f08(addr1, addr2) result(res)
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: addr1
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: addr2
            INTEGER(KIND=MPI_ADDRESS_KIND) :: res
        END FUNCTION MPI_Aint_diff_f08
    END INTERFACE MPI_Aint_diff
    
    INTERFACE MPI_Get_library_version
        SUBROUTINE MPI_Get_library_version_f08(version, resultlen, ierror)
            USE :: mpi_f08_compile_constants, ONLY : MPI_MAX_LIBRARY_VERSION_STRING
            IMPLICIT NONE
            CHARACTER(len=MPI_MAX_LIBRARY_VERSION_STRING), INTENT(out) :: version
            INTEGER, INTENT(out) :: resultlen
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Get_library_version_f08
    END INTERFACE MPI_Get_library_version
    
    INTERFACE MPI_Get_processor_name
        SUBROUTINE MPI_Get_processor_name_f08(name, resultlen, ierror)
            USE :: mpi_f08_compile_constants, ONLY : MPI_MAX_PROCESSOR_NAME
            IMPLICIT NONE
            CHARACTER(len=MPI_MAX_PROCESSOR_NAME), INTENT(out) :: name
            INTEGER, INTENT(out) :: resultlen
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Get_processor_name_f08
    END INTERFACE MPI_Get_processor_name
    
    INTERFACE MPI_Get_version
        SUBROUTINE MPI_Get_version_f08(version, subversion, ierror)
            IMPLICIT NONE
            INTEGER, INTENT(out) :: version
            INTEGER, INTENT(out) :: subversion
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Get_version_f08
    END INTERFACE MPI_Get_version
    
    INTERFACE MPI_Pcontrol
        SUBROUTINE MPI_Pcontrol_f08(level, ierror)
            IMPLICIT NONE
            INTEGER, INTENT(in) :: level
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Pcontrol_f08
    END INTERFACE MPI_Pcontrol
    
    INTERFACE MPIX_GPU_query_support
        SUBROUTINE MPIX_GPU_query_support_f08(gpu_type, is_supported, ierror)
            IMPLICIT NONE
            INTEGER, INTENT(in) :: gpu_type
            LOGICAL, INTENT(out) :: is_supported
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_GPU_query_support_f08
    END INTERFACE MPIX_GPU_query_support
    
    INTERFACE MPIX_Query_cuda_support
        SUBROUTINE MPIX_Query_cuda_support_f08(ierror)
            IMPLICIT NONE
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Query_cuda_support_f08
    END INTERFACE MPIX_Query_cuda_support
    
    INTERFACE MPIX_Query_ze_support
        SUBROUTINE MPIX_Query_ze_support_f08(ierror)
            IMPLICIT NONE
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Query_ze_support_f08
    END INTERFACE MPIX_Query_ze_support
    
    INTERFACE MPIX_Query_hip_support
        SUBROUTINE MPIX_Query_hip_support_f08(ierror)
            IMPLICIT NONE
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Query_hip_support_f08
    END INTERFACE MPIX_Query_hip_support
    
    INTERFACE MPI_Op_commutative
        SUBROUTINE MPI_Op_commutative_f08(op, commute, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Op
            IMPLICIT NONE
            TYPE(MPI_Op), INTENT(in) :: op
            LOGICAL, INTENT(out) :: commute
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Op_commutative_f08
    END INTERFACE MPI_Op_commutative
    
    INTERFACE MPI_Op_create
        SUBROUTINE MPI_Op_create_f08(user_fn, commute, op, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Op
            USE :: mpi_f08_callbacks, ONLY : MPI_User_function
            IMPLICIT NONE
            PROCEDURE(MPI_User_function) :: user_fn
            LOGICAL, INTENT(in) :: commute
            TYPE(MPI_Op), INTENT(out) :: op
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Op_create_f08
    END INTERFACE MPI_Op_create
    
    INTERFACE MPI_Op_create_c
        SUBROUTINE MPI_Op_create_c_f08(user_fn, commute, op, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Op
            USE :: mpi_f08_callbacks, ONLY : MPI_User_function_c
            IMPLICIT NONE
            PROCEDURE(MPI_User_function_c) :: user_fn
            LOGICAL, INTENT(in) :: commute
            TYPE(MPI_Op), INTENT(out) :: op
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Op_create_c_f08
    END INTERFACE MPI_Op_create_c
    
    INTERFACE MPI_Op_free
        SUBROUTINE MPI_Op_free_f08(op, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Op
            IMPLICIT NONE
            TYPE(MPI_Op), INTENT(inout) :: op
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Op_free_f08
    END INTERFACE MPI_Op_free
    
    INTERFACE MPI_Parrived
        SUBROUTINE MPI_Parrived_f08(request, partition, flag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request
            IMPLICIT NONE
            TYPE(MPI_Request), INTENT(in) :: request
            INTEGER, INTENT(in) :: partition
            LOGICAL, INTENT(out) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Parrived_f08
    END INTERFACE MPI_Parrived
    
    INTERFACE MPI_Pready
        SUBROUTINE MPI_Pready_f08(partition, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request
            IMPLICIT NONE
            INTEGER, INTENT(in) :: partition
            TYPE(MPI_Request), INTENT(in) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Pready_f08
    END INTERFACE MPI_Pready
    
    INTERFACE MPI_Pready_list
        SUBROUTINE MPI_Pready_list_f08(length, array_of_partitions, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request
            IMPLICIT NONE
            INTEGER, INTENT(in) :: length
            INTEGER, INTENT(in) :: array_of_partitions(length)
            TYPE(MPI_Request), INTENT(in) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Pready_list_f08
    END INTERFACE MPI_Pready_list
    
    INTERFACE MPI_Pready_range
        SUBROUTINE MPI_Pready_range_f08(partition_low, partition_high, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request
            IMPLICIT NONE
            INTEGER, INTENT(in) :: partition_low
            INTEGER, INTENT(in) :: partition_high
            TYPE(MPI_Request), INTENT(in) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Pready_range_f08
    END INTERFACE MPI_Pready_range
    
    INTERFACE MPI_Precv_init
        SUBROUTINE MPI_Precv_init_f08ts(buf, partitions, count, datatype, dest, tag, comm, info, request, &
                                        ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
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
        END SUBROUTINE MPI_Precv_init_f08ts
    END INTERFACE MPI_Precv_init
    
    INTERFACE MPI_Psend_init
        SUBROUTINE MPI_Psend_init_f08ts(buf, partitions, count, datatype, dest, tag, comm, info, request, &
                                        ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
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
        END SUBROUTINE MPI_Psend_init_f08ts
    END INTERFACE MPI_Psend_init
    
    INTERFACE MPI_Bsend
        SUBROUTINE MPI_Bsend_f08ts(buf, count, datatype, dest, tag, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Bsend_f08ts
        
        SUBROUTINE MPI_Bsend_c_f08ts(buf, count, datatype, dest, tag, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Bsend_c_f08ts
    END INTERFACE MPI_Bsend
    
    INTERFACE MPI_Bsend_init
        SUBROUTINE MPI_Bsend_init_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Bsend_init_f08ts
        
        SUBROUTINE MPI_Bsend_init_c_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Bsend_init_c_f08ts
    END INTERFACE MPI_Bsend_init
    
    INTERFACE MPI_Buffer_attach
        SUBROUTINE MPI_Buffer_attach_f08ts(buffer, size, ierror)
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buffer
            INTEGER, INTENT(in) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Buffer_attach_f08ts
        
        SUBROUTINE MPI_Buffer_attach_c_f08ts(buffer, size, ierror)
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buffer
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Buffer_attach_c_f08ts
    END INTERFACE MPI_Buffer_attach
    
    INTERFACE MPI_Buffer_detach
        SUBROUTINE MPI_Buffer_detach_f08(buffer_addr, size, ierror)
            USE, intrinsic :: iso_c_binding, ONLY : C_PTR
            IMPLICIT NONE
            TYPE(C_PTR), INTENT(out) :: buffer_addr
            INTEGER, INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Buffer_detach_f08
        
        SUBROUTINE MPI_Buffer_detach_c_f08(buffer_addr, size, ierror)
            USE, intrinsic :: iso_c_binding, ONLY : C_PTR
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(C_PTR), INTENT(out) :: buffer_addr
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Buffer_detach_c_f08
    END INTERFACE MPI_Buffer_detach
    
    INTERFACE MPI_Buffer_flush
        SUBROUTINE MPI_Buffer_flush_f08(ierror)
            IMPLICIT NONE
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Buffer_flush_f08
    END INTERFACE MPI_Buffer_flush
    
    INTERFACE MPI_Buffer_iflush
        SUBROUTINE MPI_Buffer_iflush_f08(request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request
            IMPLICIT NONE
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Buffer_iflush_f08
    END INTERFACE MPI_Buffer_iflush
    
    INTERFACE MPI_Comm_attach_buffer
        SUBROUTINE MPI_Comm_attach_buffer_f08ts(comm, buffer, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buffer
            INTEGER, INTENT(in) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_attach_buffer_f08ts
        
        SUBROUTINE MPI_Comm_attach_buffer_c_f08ts(comm, buffer, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buffer
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_attach_buffer_c_f08ts
    END INTERFACE MPI_Comm_attach_buffer
    
    INTERFACE MPI_Comm_detach_buffer
        SUBROUTINE MPI_Comm_detach_buffer_f08(comm, buffer_addr, size, ierror)
            USE, intrinsic :: iso_c_binding, ONLY : C_PTR
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(C_PTR), INTENT(out) :: buffer_addr
            INTEGER, INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_detach_buffer_f08
        
        SUBROUTINE MPI_Comm_detach_buffer_c_f08(comm, buffer_addr, size, ierror)
            USE, intrinsic :: iso_c_binding, ONLY : C_PTR
            USE :: mpi_f08_types, ONLY : MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(C_PTR), INTENT(out) :: buffer_addr
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_detach_buffer_c_f08
    END INTERFACE MPI_Comm_detach_buffer
    
    INTERFACE MPI_Comm_flush_buffer
        SUBROUTINE MPI_Comm_flush_buffer_f08(comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_flush_buffer_f08
    END INTERFACE MPI_Comm_flush_buffer
    
    INTERFACE MPI_Comm_iflush_buffer
        SUBROUTINE MPI_Comm_iflush_buffer_f08(comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Request
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_iflush_buffer_f08
    END INTERFACE MPI_Comm_iflush_buffer
    
    INTERFACE MPI_Ibsend
        SUBROUTINE MPI_Ibsend_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Ibsend_f08ts
        
        SUBROUTINE MPI_Ibsend_c_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Ibsend_c_f08ts
    END INTERFACE MPI_Ibsend
    
    INTERFACE MPI_Improbe
        SUBROUTINE MPI_Improbe_f08(source, tag, comm, flag, message, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Message, MPI_Status
            IMPLICIT NONE
            INTEGER, INTENT(in) :: source
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            LOGICAL, INTENT(out) :: flag
            TYPE(MPI_Message), INTENT(out) :: message
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Improbe_f08
    END INTERFACE MPI_Improbe
    
    INTERFACE MPI_Imrecv
        SUBROUTINE MPI_Imrecv_f08ts(buf, count, datatype, message, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Message, MPI_Request
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Message), INTENT(inout) :: message
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Imrecv_f08ts
        
        SUBROUTINE MPI_Imrecv_c_f08ts(buf, count, datatype, message, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Message, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Message), INTENT(inout) :: message
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Imrecv_c_f08ts
    END INTERFACE MPI_Imrecv
    
    INTERFACE MPI_Iprobe
        SUBROUTINE MPI_Iprobe_f08(source, tag, comm, flag, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Status
            IMPLICIT NONE
            INTEGER, INTENT(in) :: source
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            LOGICAL, INTENT(out) :: flag
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Iprobe_f08
    END INTERFACE MPI_Iprobe
    
    INTERFACE MPI_Irecv
        SUBROUTINE MPI_Irecv_f08ts(buf, count, datatype, source, tag, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: source
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Irecv_f08ts
        
        SUBROUTINE MPI_Irecv_c_f08ts(buf, count, datatype, source, tag, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: source
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Irecv_c_f08ts
    END INTERFACE MPI_Irecv
    
    INTERFACE MPI_Irsend
        SUBROUTINE MPI_Irsend_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Irsend_f08ts
        
        SUBROUTINE MPI_Irsend_c_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Irsend_c_f08ts
    END INTERFACE MPI_Irsend
    
    INTERFACE MPI_Isend
        SUBROUTINE MPI_Isend_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Isend_f08ts
        
        SUBROUTINE MPI_Isend_c_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Isend_c_f08ts
    END INTERFACE MPI_Isend
    
    INTERFACE MPI_Isendrecv
        SUBROUTINE MPI_Isendrecv_f08ts(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, &
                                       recvtype, source, recvtag, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
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
        END SUBROUTINE MPI_Isendrecv_f08ts
        
        SUBROUTINE MPI_Isendrecv_c_f08ts(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, &
                                         recvtype, source, recvtag, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
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
        END SUBROUTINE MPI_Isendrecv_c_f08ts
    END INTERFACE MPI_Isendrecv
    
    INTERFACE MPI_Isendrecv_replace
        SUBROUTINE MPI_Isendrecv_replace_f08ts(buf, count, datatype, dest, sendtag, source, recvtag, comm, &
                                               request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
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
        END SUBROUTINE MPI_Isendrecv_replace_f08ts
        
        SUBROUTINE MPI_Isendrecv_replace_c_f08ts(buf, count, datatype, dest, sendtag, source, recvtag, comm, &
                                                 request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
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
        END SUBROUTINE MPI_Isendrecv_replace_c_f08ts
    END INTERFACE MPI_Isendrecv_replace
    
    INTERFACE MPI_Issend
        SUBROUTINE MPI_Issend_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Issend_f08ts
        
        SUBROUTINE MPI_Issend_c_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Issend_c_f08ts
    END INTERFACE MPI_Issend
    
    INTERFACE MPI_Mprobe
        SUBROUTINE MPI_Mprobe_f08(source, tag, comm, message, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Message, MPI_Status
            IMPLICIT NONE
            INTEGER, INTENT(in) :: source
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Message), INTENT(out) :: message
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Mprobe_f08
    END INTERFACE MPI_Mprobe
    
    INTERFACE MPI_Mrecv
        SUBROUTINE MPI_Mrecv_f08ts(buf, count, datatype, message, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Message, MPI_Status
            IMPLICIT NONE
            TYPE(*), DIMENSION(..) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Message), INTENT(inout) :: message
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Mrecv_f08ts
        
        SUBROUTINE MPI_Mrecv_c_f08ts(buf, count, datatype, message, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Message, MPI_Status
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..) :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Message), INTENT(inout) :: message
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Mrecv_c_f08ts
    END INTERFACE MPI_Mrecv
    
    INTERFACE MPI_Probe
        SUBROUTINE MPI_Probe_f08(source, tag, comm, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Status
            IMPLICIT NONE
            INTEGER, INTENT(in) :: source
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Probe_f08
    END INTERFACE MPI_Probe
    
    INTERFACE MPI_Recv
        SUBROUTINE MPI_Recv_f08ts(buf, count, datatype, source, tag, comm, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Status
            IMPLICIT NONE
            TYPE(*), DIMENSION(..) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: source
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Recv_f08ts
        
        SUBROUTINE MPI_Recv_c_f08ts(buf, count, datatype, source, tag, comm, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Status
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..) :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: source
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Recv_c_f08ts
    END INTERFACE MPI_Recv
    
    INTERFACE MPI_Recv_init
        SUBROUTINE MPI_Recv_init_f08ts(buf, count, datatype, source, tag, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: source
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Recv_init_f08ts
        
        SUBROUTINE MPI_Recv_init_c_f08ts(buf, count, datatype, source, tag, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: source
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Recv_init_c_f08ts
    END INTERFACE MPI_Recv_init
    
    INTERFACE MPI_Rsend
        SUBROUTINE MPI_Rsend_f08ts(buf, count, datatype, dest, tag, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Rsend_f08ts
        
        SUBROUTINE MPI_Rsend_c_f08ts(buf, count, datatype, dest, tag, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Rsend_c_f08ts
    END INTERFACE MPI_Rsend
    
    INTERFACE MPI_Rsend_init
        SUBROUTINE MPI_Rsend_init_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Rsend_init_f08ts
        
        SUBROUTINE MPI_Rsend_init_c_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Rsend_init_c_f08ts
    END INTERFACE MPI_Rsend_init
    
    INTERFACE MPI_Send
        SUBROUTINE MPI_Send_f08ts(buf, count, datatype, dest, tag, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Send_f08ts
        
        SUBROUTINE MPI_Send_c_f08ts(buf, count, datatype, dest, tag, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Send_c_f08ts
    END INTERFACE MPI_Send
    
    INTERFACE MPI_Send_init
        SUBROUTINE MPI_Send_init_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Send_init_f08ts
        
        SUBROUTINE MPI_Send_init_c_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Send_init_c_f08ts
    END INTERFACE MPI_Send_init
    
    INTERFACE MPI_Sendrecv
        SUBROUTINE MPI_Sendrecv_f08ts(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, &
                                      recvtype, source, recvtag, comm, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Status
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
        END SUBROUTINE MPI_Sendrecv_f08ts
        
        SUBROUTINE MPI_Sendrecv_c_f08ts(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, &
                                        recvtype, source, recvtag, comm, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Status
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
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
        END SUBROUTINE MPI_Sendrecv_c_f08ts
    END INTERFACE MPI_Sendrecv
    
    INTERFACE MPI_Sendrecv_replace
        SUBROUTINE MPI_Sendrecv_replace_f08ts(buf, count, datatype, dest, sendtag, source, recvtag, comm, &
                                              status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Status
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
        END SUBROUTINE MPI_Sendrecv_replace_f08ts
        
        SUBROUTINE MPI_Sendrecv_replace_c_f08ts(buf, count, datatype, dest, sendtag, source, recvtag, comm, &
                                                status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Status
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
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
        END SUBROUTINE MPI_Sendrecv_replace_c_f08ts
    END INTERFACE MPI_Sendrecv_replace
    
    INTERFACE MPI_Session_attach_buffer
        SUBROUTINE MPI_Session_attach_buffer_f08ts(session, buffer, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Session
            IMPLICIT NONE
            TYPE(MPI_Session), INTENT(in) :: session
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buffer
            INTEGER, INTENT(in) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Session_attach_buffer_f08ts
        
        SUBROUTINE MPI_Session_attach_buffer_c_f08ts(session, buffer, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Session
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_Session), INTENT(in) :: session
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buffer
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Session_attach_buffer_c_f08ts
    END INTERFACE MPI_Session_attach_buffer
    
    INTERFACE MPI_Session_detach_buffer
        SUBROUTINE MPI_Session_detach_buffer_f08(session, buffer_addr, size, ierror)
            USE, intrinsic :: iso_c_binding, ONLY : C_PTR
            USE :: mpi_f08_types, ONLY : MPI_Session
            IMPLICIT NONE
            TYPE(MPI_Session), INTENT(in) :: session
            TYPE(C_PTR), INTENT(out) :: buffer_addr
            INTEGER, INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Session_detach_buffer_f08
        
        SUBROUTINE MPI_Session_detach_buffer_c_f08(session, buffer_addr, size, ierror)
            USE, intrinsic :: iso_c_binding, ONLY : C_PTR
            USE :: mpi_f08_types, ONLY : MPI_Session
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_Session), INTENT(in) :: session
            TYPE(C_PTR), INTENT(out) :: buffer_addr
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Session_detach_buffer_c_f08
    END INTERFACE MPI_Session_detach_buffer
    
    INTERFACE MPI_Session_flush_buffer
        SUBROUTINE MPI_Session_flush_buffer_f08(session, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Session
            IMPLICIT NONE
            TYPE(MPI_Session), INTENT(in) :: session
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Session_flush_buffer_f08
    END INTERFACE MPI_Session_flush_buffer
    
    INTERFACE MPI_Session_iflush_buffer
        SUBROUTINE MPI_Session_iflush_buffer_f08(session, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Session, MPI_Request
            IMPLICIT NONE
            TYPE(MPI_Session), INTENT(in) :: session
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Session_iflush_buffer_f08
    END INTERFACE MPI_Session_iflush_buffer
    
    INTERFACE MPI_Ssend
        SUBROUTINE MPI_Ssend_f08ts(buf, count, datatype, dest, tag, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Ssend_f08ts
        
        SUBROUTINE MPI_Ssend_c_f08ts(buf, count, datatype, dest, tag, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Ssend_c_f08ts
    END INTERFACE MPI_Ssend
    
    INTERFACE MPI_Ssend_init
        SUBROUTINE MPI_Ssend_init_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Ssend_init_f08ts
        
        SUBROUTINE MPI_Ssend_init_c_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Ssend_init_c_f08ts
    END INTERFACE MPI_Ssend_init
    
    INTERFACE MPI_Cancel
        SUBROUTINE MPI_Cancel_f08(request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request
            IMPLICIT NONE
            TYPE(MPI_Request), INTENT(in) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Cancel_f08
    END INTERFACE MPI_Cancel
    
    INTERFACE MPI_Grequest_complete
        SUBROUTINE MPI_Grequest_complete_f08(request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request
            IMPLICIT NONE
            TYPE(MPI_Request), INTENT(in) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Grequest_complete_f08
    END INTERFACE MPI_Grequest_complete
    
    INTERFACE MPI_Grequest_start
        SUBROUTINE MPI_Grequest_start_f08(query_fn, free_fn, cancel_fn, extra_state, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            USE :: mpi_f08_callbacks, ONLY : MPI_Grequest_query_function, MPI_Grequest_free_function, &
                MPI_Grequest_cancel_function
            IMPLICIT NONE
            PROCEDURE(MPI_Grequest_query_function) :: query_fn
            PROCEDURE(MPI_Grequest_free_function) :: free_fn
            PROCEDURE(MPI_Grequest_cancel_function) :: cancel_fn
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: extra_state
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Grequest_start_f08
    END INTERFACE MPI_Grequest_start
    
    INTERFACE MPI_Request_free
        SUBROUTINE MPI_Request_free_f08(request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request
            IMPLICIT NONE
            TYPE(MPI_Request), INTENT(inout) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Request_free_f08
    END INTERFACE MPI_Request_free
    
    INTERFACE MPI_Request_get_status
        SUBROUTINE MPI_Request_get_status_f08(request, flag, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_Request), INTENT(in) :: request
            LOGICAL, INTENT(out) :: flag
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Request_get_status_f08
    END INTERFACE MPI_Request_get_status
    
    INTERFACE MPI_Request_get_status_all
        SUBROUTINE MPI_Request_get_status_all_f08(count, array_of_requests, flag, array_of_statuses, &
                                                  ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status
            IMPLICIT NONE
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Request), INTENT(in) :: array_of_requests(count)
            LOGICAL, INTENT(out) :: flag
            TYPE(MPI_Status), INTENT(out), TARGET :: array_of_statuses(*)
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Request_get_status_all_f08
    END INTERFACE MPI_Request_get_status_all
    
    INTERFACE MPI_Request_get_status_any
        SUBROUTINE MPI_Request_get_status_any_f08(count, array_of_requests, indx, flag, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status
            IMPLICIT NONE
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Request), INTENT(in) :: array_of_requests(count)
            INTEGER, INTENT(out) :: indx
            LOGICAL, INTENT(out) :: flag
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Request_get_status_any_f08
    END INTERFACE MPI_Request_get_status_any
    
    INTERFACE MPI_Request_get_status_some
        SUBROUTINE MPI_Request_get_status_some_f08(incount, array_of_requests, outcount, array_of_indices, &
                                                   array_of_statuses, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status
            IMPLICIT NONE
            INTEGER, INTENT(in) :: incount
            TYPE(MPI_Request), INTENT(in) :: array_of_requests(incount)
            INTEGER, INTENT(out) :: outcount
            INTEGER, INTENT(out) :: array_of_indices(*)
            TYPE(MPI_Status), INTENT(out), TARGET :: array_of_statuses(*)
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Request_get_status_some_f08
    END INTERFACE MPI_Request_get_status_some
    
    INTERFACE MPI_Start
        SUBROUTINE MPI_Start_f08(request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request
            IMPLICIT NONE
            TYPE(MPI_Request), INTENT(inout) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Start_f08
    END INTERFACE MPI_Start
    
    INTERFACE MPI_Startall
        SUBROUTINE MPI_Startall_f08(count, array_of_requests, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request
            IMPLICIT NONE
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Request), INTENT(inout) :: array_of_requests(count)
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Startall_f08
    END INTERFACE MPI_Startall
    
    INTERFACE MPI_Status_get_error
        SUBROUTINE MPI_Status_get_error_f08(status, error, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Status
            IMPLICIT NONE
            TYPE(MPI_Status), INTENT(in), TARGET :: status
            INTEGER, INTENT(out) :: error
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Status_get_error_f08
    END INTERFACE MPI_Status_get_error
    
    INTERFACE MPI_Status_get_source
        SUBROUTINE MPI_Status_get_source_f08(status, source, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Status
            IMPLICIT NONE
            TYPE(MPI_Status), INTENT(in), TARGET :: status
            INTEGER, INTENT(out) :: source
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Status_get_source_f08
    END INTERFACE MPI_Status_get_source
    
    INTERFACE MPI_Status_get_tag
        SUBROUTINE MPI_Status_get_tag_f08(status, tag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Status
            IMPLICIT NONE
            TYPE(MPI_Status), INTENT(in), TARGET :: status
            INTEGER, INTENT(out) :: tag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Status_get_tag_f08
    END INTERFACE MPI_Status_get_tag
    
    INTERFACE MPI_Status_set_error
        SUBROUTINE MPI_Status_set_error_f08(status, error, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Status
            IMPLICIT NONE
            TYPE(MPI_Status), INTENT(inout), TARGET :: status
            INTEGER, INTENT(in) :: error
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Status_set_error_f08
    END INTERFACE MPI_Status_set_error
    
    INTERFACE MPI_Status_set_source
        SUBROUTINE MPI_Status_set_source_f08(status, source, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Status
            IMPLICIT NONE
            TYPE(MPI_Status), INTENT(inout), TARGET :: status
            INTEGER, INTENT(in) :: source
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Status_set_source_f08
    END INTERFACE MPI_Status_set_source
    
    INTERFACE MPI_Status_set_tag
        SUBROUTINE MPI_Status_set_tag_f08(status, tag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Status
            IMPLICIT NONE
            TYPE(MPI_Status), INTENT(inout), TARGET :: status
            INTEGER, INTENT(in) :: tag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Status_set_tag_f08
    END INTERFACE MPI_Status_set_tag
    
    INTERFACE MPI_Status_set_cancelled
        SUBROUTINE MPI_Status_set_cancelled_f08(status, flag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Status
            IMPLICIT NONE
            TYPE(MPI_Status), INTENT(inout), TARGET :: status
            LOGICAL, INTENT(in) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Status_set_cancelled_f08
    END INTERFACE MPI_Status_set_cancelled
    
    INTERFACE MPI_Test
        SUBROUTINE MPI_Test_f08(request, flag, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_Request), INTENT(inout) :: request
            LOGICAL, INTENT(out) :: flag
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Test_f08
    END INTERFACE MPI_Test
    
    INTERFACE MPI_Test_cancelled
        SUBROUTINE MPI_Test_cancelled_f08(status, flag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Status
            IMPLICIT NONE
            TYPE(MPI_Status), INTENT(in), TARGET :: status
            LOGICAL, INTENT(out) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Test_cancelled_f08
    END INTERFACE MPI_Test_cancelled
    
    INTERFACE MPI_Testall
        SUBROUTINE MPI_Testall_f08(count, array_of_requests, flag, array_of_statuses, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status
            IMPLICIT NONE
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Request), INTENT(inout) :: array_of_requests(count)
            LOGICAL, INTENT(out) :: flag
            TYPE(MPI_Status), INTENT(out), TARGET :: array_of_statuses(*)
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Testall_f08
    END INTERFACE MPI_Testall
    
    INTERFACE MPI_Testany
        SUBROUTINE MPI_Testany_f08(count, array_of_requests, indx, flag, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status
            IMPLICIT NONE
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Request), INTENT(inout) :: array_of_requests(count)
            INTEGER, INTENT(out) :: indx
            LOGICAL, INTENT(out) :: flag
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Testany_f08
    END INTERFACE MPI_Testany
    
    INTERFACE MPI_Testsome
        SUBROUTINE MPI_Testsome_f08(incount, array_of_requests, outcount, array_of_indices, &
                                    array_of_statuses, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status
            IMPLICIT NONE
            INTEGER, INTENT(in) :: incount
            TYPE(MPI_Request), INTENT(inout) :: array_of_requests(incount)
            INTEGER, INTENT(out) :: outcount
            INTEGER, INTENT(out) :: array_of_indices(*)
            TYPE(MPI_Status), INTENT(out), TARGET :: array_of_statuses(*)
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Testsome_f08
    END INTERFACE MPI_Testsome
    
    INTERFACE MPI_Wait
        SUBROUTINE MPI_Wait_f08(request, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_Request), INTENT(inout) :: request
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Wait_f08
    END INTERFACE MPI_Wait
    
    INTERFACE MPI_Waitall
        SUBROUTINE MPI_Waitall_f08(count, array_of_requests, array_of_statuses, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status
            IMPLICIT NONE
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Request), INTENT(inout) :: array_of_requests(count)
            TYPE(MPI_Status), INTENT(out), TARGET :: array_of_statuses(*)
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Waitall_f08
    END INTERFACE MPI_Waitall
    
    INTERFACE MPI_Waitany
        SUBROUTINE MPI_Waitany_f08(count, array_of_requests, indx, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status
            IMPLICIT NONE
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Request), INTENT(inout) :: array_of_requests(count)
            INTEGER, INTENT(out) :: indx
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Waitany_f08
    END INTERFACE MPI_Waitany
    
    INTERFACE MPI_Waitsome
        SUBROUTINE MPI_Waitsome_f08(incount, array_of_requests, outcount, array_of_indices, &
                                    array_of_statuses, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status
            IMPLICIT NONE
            INTEGER, INTENT(in) :: incount
            TYPE(MPI_Request), INTENT(inout) :: array_of_requests(incount)
            INTEGER, INTENT(out) :: outcount
            INTEGER, INTENT(out) :: array_of_indices(*)
            TYPE(MPI_Status), INTENT(out), TARGET :: array_of_statuses(*)
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Waitsome_f08
    END INTERFACE MPI_Waitsome
    
    INTERFACE MPIX_Request_is_complete
        FUNCTION MPIX_Request_is_complete_f08(request) result(res)
            USE :: mpi_f08_types, ONLY : MPI_Request
            IMPLICIT NONE
            TYPE(MPI_Request), INTENT(in) :: request
            LOGICAL :: res
        END FUNCTION MPIX_Request_is_complete_f08
    END INTERFACE MPIX_Request_is_complete
    
    INTERFACE MPI_Accumulate
        SUBROUTINE MPI_Accumulate_f08ts(origin_addr, origin_count, origin_datatype, target_rank, &
                                        target_disp, target_count, target_datatype, op, win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Win
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Accumulate_f08ts
        
        SUBROUTINE MPI_Accumulate_c_f08ts(origin_addr, origin_count, origin_datatype, target_rank, &
                                          target_disp, target_count, target_datatype, op, win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Win
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Accumulate_c_f08ts
    END INTERFACE MPI_Accumulate
    
    INTERFACE MPI_Alloc_mem
        SUBROUTINE MPI_Alloc_mem_f08(size, info, baseptr, ierror)
            USE, intrinsic :: iso_c_binding, ONLY : C_PTR
            USE :: mpi_f08_types, ONLY : MPI_Info
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: size
            TYPE(MPI_Info), INTENT(in) :: info
            TYPE(C_PTR), INTENT(out) :: baseptr
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Alloc_mem_f08
    END INTERFACE MPI_Alloc_mem
    
    INTERFACE MPI_Compare_and_swap
        SUBROUTINE MPI_Compare_and_swap_f08ts(origin_addr, compare_addr, result_addr, datatype, target_rank, &
                                              target_disp, win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Win
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: origin_addr
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: compare_addr
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: result_addr
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: target_rank
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: target_disp
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Compare_and_swap_f08ts
    END INTERFACE MPI_Compare_and_swap
    
    INTERFACE MPI_Fetch_and_op
        SUBROUTINE MPI_Fetch_and_op_f08ts(origin_addr, result_addr, datatype, target_rank, target_disp, op, &
                                          win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Win
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: origin_addr
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: result_addr
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: target_rank
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: target_disp
            TYPE(MPI_Op), INTENT(in) :: op
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Fetch_and_op_f08ts
    END INTERFACE MPI_Fetch_and_op
    
    INTERFACE MPI_Free_mem
        SUBROUTINE MPI_Free_mem_f08ts(base, ierror)
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: base
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Free_mem_f08ts
    END INTERFACE MPI_Free_mem
    
    INTERFACE MPI_Get
        SUBROUTINE MPI_Get_f08ts(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
                                 target_count, target_datatype, win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Win
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Get_f08ts
        
        SUBROUTINE MPI_Get_c_f08ts(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
                                   target_count, target_datatype, win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Win
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Get_c_f08ts
    END INTERFACE MPI_Get
    
    INTERFACE MPI_Get_accumulate
        SUBROUTINE MPI_Get_accumulate_f08ts(origin_addr, origin_count, origin_datatype, result_addr, &
                                            result_count, result_datatype, target_rank, target_disp, &
                                            target_count, target_datatype, op, win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Win
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Get_accumulate_f08ts
        
        SUBROUTINE MPI_Get_accumulate_c_f08ts(origin_addr, origin_count, origin_datatype, result_addr, &
                                              result_count, result_datatype, target_rank, target_disp, &
                                              target_count, target_datatype, op, win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Win
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Get_accumulate_c_f08ts
    END INTERFACE MPI_Get_accumulate
    
    INTERFACE MPI_Put
        SUBROUTINE MPI_Put_f08ts(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
                                 target_count, target_datatype, win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Win
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Put_f08ts
        
        SUBROUTINE MPI_Put_c_f08ts(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
                                   target_count, target_datatype, win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Win
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Put_c_f08ts
    END INTERFACE MPI_Put
    
    INTERFACE MPI_Raccumulate
        SUBROUTINE MPI_Raccumulate_f08ts(origin_addr, origin_count, origin_datatype, target_rank, &
                                         target_disp, target_count, target_datatype, op, win, request, &
                                         ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Win, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Raccumulate_f08ts
        
        SUBROUTINE MPI_Raccumulate_c_f08ts(origin_addr, origin_count, origin_datatype, target_rank, &
                                           target_disp, target_count, target_datatype, op, win, request, &
                                           ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Win, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Raccumulate_c_f08ts
    END INTERFACE MPI_Raccumulate
    
    INTERFACE MPI_Rget
        SUBROUTINE MPI_Rget_f08ts(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
                                  target_count, target_datatype, win, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Win, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Rget_f08ts
        
        SUBROUTINE MPI_Rget_c_f08ts(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
                                    target_count, target_datatype, win, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Win, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Rget_c_f08ts
    END INTERFACE MPI_Rget
    
    INTERFACE MPI_Rget_accumulate
        SUBROUTINE MPI_Rget_accumulate_f08ts(origin_addr, origin_count, origin_datatype, result_addr, &
                                             result_count, result_datatype, target_rank, target_disp, &
                                             target_count, target_datatype, op, win, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Win, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Rget_accumulate_f08ts
        
        SUBROUTINE MPI_Rget_accumulate_c_f08ts(origin_addr, origin_count, origin_datatype, result_addr, &
                                               result_count, result_datatype, target_rank, target_disp, &
                                               target_count, target_datatype, op, win, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Win, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Rget_accumulate_c_f08ts
    END INTERFACE MPI_Rget_accumulate
    
    INTERFACE MPI_Rput
        SUBROUTINE MPI_Rput_f08ts(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
                                  target_count, target_datatype, win, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Win, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Rput_f08ts
        
        SUBROUTINE MPI_Rput_c_f08ts(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
                                    target_count, target_datatype, win, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Win, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
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
        END SUBROUTINE MPI_Rput_c_f08ts
    END INTERFACE MPI_Rput
    
    INTERFACE MPI_Win_allocate
        SUBROUTINE MPI_Win_allocate_f08(size, disp_unit, info, comm, baseptr, win, ierror)
            USE, intrinsic :: iso_c_binding, ONLY : C_PTR
            USE :: mpi_f08_types, ONLY : MPI_Info, MPI_Comm, MPI_Win
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: size
            INTEGER, INTENT(in) :: disp_unit
            TYPE(MPI_Info), INTENT(in) :: info
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(C_PTR), INTENT(out) :: baseptr
            TYPE(MPI_Win), INTENT(out) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_allocate_f08
        
        SUBROUTINE MPI_Win_allocate_c_f08(size, disp_unit, info, comm, baseptr, win, ierror)
            USE, intrinsic :: iso_c_binding, ONLY : C_PTR
            USE :: mpi_f08_types, ONLY : MPI_Info, MPI_Comm, MPI_Win
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: size
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: disp_unit
            TYPE(MPI_Info), INTENT(in) :: info
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(C_PTR), INTENT(out) :: baseptr
            TYPE(MPI_Win), INTENT(out) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_allocate_c_f08
    END INTERFACE MPI_Win_allocate
    
    INTERFACE MPI_Win_allocate_shared
        SUBROUTINE MPI_Win_allocate_shared_f08(size, disp_unit, info, comm, baseptr, win, ierror)
            USE, intrinsic :: iso_c_binding, ONLY : C_PTR
            USE :: mpi_f08_types, ONLY : MPI_Info, MPI_Comm, MPI_Win
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: size
            INTEGER, INTENT(in) :: disp_unit
            TYPE(MPI_Info), INTENT(in) :: info
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(C_PTR), INTENT(out) :: baseptr
            TYPE(MPI_Win), INTENT(out) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_allocate_shared_f08
        
        SUBROUTINE MPI_Win_allocate_shared_c_f08(size, disp_unit, info, comm, baseptr, win, ierror)
            USE, intrinsic :: iso_c_binding, ONLY : C_PTR
            USE :: mpi_f08_types, ONLY : MPI_Info, MPI_Comm, MPI_Win
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: size
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: disp_unit
            TYPE(MPI_Info), INTENT(in) :: info
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(C_PTR), INTENT(out) :: baseptr
            TYPE(MPI_Win), INTENT(out) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_allocate_shared_c_f08
    END INTERFACE MPI_Win_allocate_shared
    
    INTERFACE MPI_Win_attach
        SUBROUTINE MPI_Win_attach_f08ts(win, base, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: base
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_attach_f08ts
    END INTERFACE MPI_Win_attach
    
    INTERFACE MPI_Win_complete
        SUBROUTINE MPI_Win_complete_f08(win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_complete_f08
    END INTERFACE MPI_Win_complete
    
    INTERFACE MPI_Win_create
        SUBROUTINE MPI_Win_create_f08ts(base, size, disp_unit, info, comm, win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info, MPI_Comm, MPI_Win
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: base
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: size
            INTEGER, INTENT(in) :: disp_unit
            TYPE(MPI_Info), INTENT(in) :: info
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Win), INTENT(out) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_create_f08ts
        
        SUBROUTINE MPI_Win_create_c_f08ts(base, size, disp_unit, info, comm, win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info, MPI_Comm, MPI_Win
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: base
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: size
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: disp_unit
            TYPE(MPI_Info), INTENT(in) :: info
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Win), INTENT(out) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_create_c_f08ts
    END INTERFACE MPI_Win_create
    
    INTERFACE MPI_Win_create_dynamic
        SUBROUTINE MPI_Win_create_dynamic_f08(info, comm, win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info, MPI_Comm, MPI_Win
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(in) :: info
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Win), INTENT(out) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_create_dynamic_f08
    END INTERFACE MPI_Win_create_dynamic
    
    INTERFACE MPI_Win_detach
        SUBROUTINE MPI_Win_detach_f08ts(win, base, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: base
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_detach_f08ts
    END INTERFACE MPI_Win_detach
    
    INTERFACE MPI_Win_fence
        SUBROUTINE MPI_Win_fence_f08(assert, win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            INTEGER, INTENT(in) :: assert
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_fence_f08
    END INTERFACE MPI_Win_fence
    
    INTERFACE MPI_Win_flush
        SUBROUTINE MPI_Win_flush_f08(rank, win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            INTEGER, INTENT(in) :: rank
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_flush_f08
    END INTERFACE MPI_Win_flush
    
    INTERFACE MPI_Win_flush_all
        SUBROUTINE MPI_Win_flush_all_f08(win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_flush_all_f08
    END INTERFACE MPI_Win_flush_all
    
    INTERFACE MPI_Win_flush_local
        SUBROUTINE MPI_Win_flush_local_f08(rank, win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            INTEGER, INTENT(in) :: rank
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_flush_local_f08
    END INTERFACE MPI_Win_flush_local
    
    INTERFACE MPI_Win_flush_local_all
        SUBROUTINE MPI_Win_flush_local_all_f08(win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_flush_local_all_f08
    END INTERFACE MPI_Win_flush_local_all
    
    INTERFACE MPI_Win_free
        SUBROUTINE MPI_Win_free_f08(win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(inout) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_free_f08
    END INTERFACE MPI_Win_free
    
    INTERFACE MPI_Win_get_group
        SUBROUTINE MPI_Win_get_group_f08(win, group, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win, MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            TYPE(MPI_Group), INTENT(out) :: group
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_get_group_f08
    END INTERFACE MPI_Win_get_group
    
    INTERFACE MPI_Win_get_info
        SUBROUTINE MPI_Win_get_info_f08(win, info_used, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win, MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            TYPE(MPI_Info), INTENT(out) :: info_used
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_get_info_f08
    END INTERFACE MPI_Win_get_info
    
    INTERFACE MPI_Win_get_name
        SUBROUTINE MPI_Win_get_name_f08(win, win_name, resultlen, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            USE :: mpi_f08_compile_constants, ONLY : MPI_MAX_OBJECT_NAME
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            CHARACTER(len=MPI_MAX_OBJECT_NAME), INTENT(out) :: win_name
            INTEGER, INTENT(out) :: resultlen
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_get_name_f08
    END INTERFACE MPI_Win_get_name
    
    INTERFACE MPI_Win_lock
        SUBROUTINE MPI_Win_lock_f08(lock_type, rank, assert, win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            INTEGER, INTENT(in) :: lock_type
            INTEGER, INTENT(in) :: rank
            INTEGER, INTENT(in) :: assert
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_lock_f08
    END INTERFACE MPI_Win_lock
    
    INTERFACE MPI_Win_lock_all
        SUBROUTINE MPI_Win_lock_all_f08(assert, win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            INTEGER, INTENT(in) :: assert
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_lock_all_f08
    END INTERFACE MPI_Win_lock_all
    
    INTERFACE MPI_Win_post
        SUBROUTINE MPI_Win_post_f08(group, assert, win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Group, MPI_Win
            IMPLICIT NONE
            TYPE(MPI_Group), INTENT(in) :: group
            INTEGER, INTENT(in) :: assert
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_post_f08
    END INTERFACE MPI_Win_post
    
    INTERFACE MPI_Win_set_info
        SUBROUTINE MPI_Win_set_info_f08(win, info, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win, MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            TYPE(MPI_Info), INTENT(in) :: info
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_set_info_f08
    END INTERFACE MPI_Win_set_info
    
    INTERFACE MPI_Win_set_name
        SUBROUTINE MPI_Win_set_name_f08(win, win_name, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            CHARACTER(len=*), INTENT(in) :: win_name
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_set_name_f08
    END INTERFACE MPI_Win_set_name
    
    INTERFACE MPI_Win_shared_query
        SUBROUTINE MPI_Win_shared_query_f08(win, rank, size, disp_unit, baseptr, ierror)
            USE, intrinsic :: iso_c_binding, ONLY : C_PTR
            USE :: mpi_f08_types, ONLY : MPI_Win
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, INTENT(in) :: rank
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: size
            INTEGER, INTENT(out) :: disp_unit
            TYPE(C_PTR), INTENT(out) :: baseptr
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_shared_query_f08
        
        SUBROUTINE MPI_Win_shared_query_c_f08(win, rank, size, disp_unit, baseptr, ierror)
            USE, intrinsic :: iso_c_binding, ONLY : C_PTR
            USE :: mpi_f08_types, ONLY : MPI_Win
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, INTENT(in) :: rank
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: size
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: disp_unit
            TYPE(C_PTR), INTENT(out) :: baseptr
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_shared_query_c_f08
    END INTERFACE MPI_Win_shared_query
    
    INTERFACE MPI_Win_start
        SUBROUTINE MPI_Win_start_f08(group, assert, win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Group, MPI_Win
            IMPLICIT NONE
            TYPE(MPI_Group), INTENT(in) :: group
            INTEGER, INTENT(in) :: assert
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_start_f08
    END INTERFACE MPI_Win_start
    
    INTERFACE MPI_Win_sync
        SUBROUTINE MPI_Win_sync_f08(win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_sync_f08
    END INTERFACE MPI_Win_sync
    
    INTERFACE MPI_Win_test
        SUBROUTINE MPI_Win_test_f08(win, flag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            LOGICAL, INTENT(out) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_test_f08
    END INTERFACE MPI_Win_test
    
    INTERFACE MPI_Win_unlock
        SUBROUTINE MPI_Win_unlock_f08(rank, win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            INTEGER, INTENT(in) :: rank
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_unlock_f08
    END INTERFACE MPI_Win_unlock
    
    INTERFACE MPI_Win_unlock_all
        SUBROUTINE MPI_Win_unlock_all_f08(win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_unlock_all_f08
    END INTERFACE MPI_Win_unlock_all
    
    INTERFACE MPI_Win_wait
        SUBROUTINE MPI_Win_wait_f08(win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Win_wait_f08
    END INTERFACE MPI_Win_wait
    
    INTERFACE MPI_Close_port
        SUBROUTINE MPI_Close_port_f08(port_name, ierror)
            IMPLICIT NONE
            CHARACTER(len=*), INTENT(in) :: port_name
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Close_port_f08
    END INTERFACE MPI_Close_port
    
    INTERFACE MPI_Comm_accept
        SUBROUTINE MPI_Comm_accept_f08(port_name, info, root, comm, newcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info, MPI_Comm
            IMPLICIT NONE
            CHARACTER(len=*), INTENT(in) :: port_name
            TYPE(MPI_Info), INTENT(in) :: info
            INTEGER, INTENT(in) :: root
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Comm), INTENT(out) :: newcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_accept_f08
    END INTERFACE MPI_Comm_accept
    
    INTERFACE MPI_Comm_connect
        SUBROUTINE MPI_Comm_connect_f08(port_name, info, root, comm, newcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info, MPI_Comm
            IMPLICIT NONE
            CHARACTER(len=*), INTENT(in) :: port_name
            TYPE(MPI_Info), INTENT(in) :: info
            INTEGER, INTENT(in) :: root
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Comm), INTENT(out) :: newcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_connect_f08
    END INTERFACE MPI_Comm_connect
    
    INTERFACE MPI_Comm_disconnect
        SUBROUTINE MPI_Comm_disconnect_f08(comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(inout) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_disconnect_f08
    END INTERFACE MPI_Comm_disconnect
    
    INTERFACE MPI_Comm_get_parent
        SUBROUTINE MPI_Comm_get_parent_f08(parent, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(out) :: parent
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_get_parent_f08
    END INTERFACE MPI_Comm_get_parent
    
    INTERFACE MPI_Comm_join
        SUBROUTINE MPI_Comm_join_f08(fd, intercomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            INTEGER, INTENT(in) :: fd
            TYPE(MPI_Comm), INTENT(out) :: intercomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Comm_join_f08
    END INTERFACE MPI_Comm_join
    
    INTERFACE MPI_Comm_spawn
        SUBROUTINE MPI_Comm_spawn_f08(command, argv, maxprocs, info, root, comm, intercomm, &
                                      array_of_errcodes, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info, MPI_Comm
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
        END SUBROUTINE MPI_Comm_spawn_f08
    END INTERFACE MPI_Comm_spawn
    
    INTERFACE MPI_Comm_spawn_multiple
        SUBROUTINE MPI_Comm_spawn_multiple_f08(count, array_of_commands, array_of_argv, array_of_maxprocs, &
                                               array_of_info, root, comm, intercomm, array_of_errcodes, &
                                               ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info, MPI_Comm
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
        END SUBROUTINE MPI_Comm_spawn_multiple_f08
    END INTERFACE MPI_Comm_spawn_multiple
    
    INTERFACE MPI_Lookup_name
        SUBROUTINE MPI_Lookup_name_f08(service_name, info, port_name, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            USE :: mpi_f08_compile_constants, ONLY : MPI_MAX_PORT_NAME
            IMPLICIT NONE
            CHARACTER(len=*), INTENT(in) :: service_name
            TYPE(MPI_Info), INTENT(in) :: info
            CHARACTER(len=MPI_MAX_PORT_NAME), INTENT(out) :: port_name
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Lookup_name_f08
    END INTERFACE MPI_Lookup_name
    
    INTERFACE MPI_Open_port
        SUBROUTINE MPI_Open_port_f08(info, port_name, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            USE :: mpi_f08_compile_constants, ONLY : MPI_MAX_PORT_NAME
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(in) :: info
            CHARACTER(len=MPI_MAX_PORT_NAME), INTENT(out) :: port_name
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Open_port_f08
    END INTERFACE MPI_Open_port
    
    INTERFACE MPI_Publish_name
        SUBROUTINE MPI_Publish_name_f08(service_name, info, port_name, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            IMPLICIT NONE
            CHARACTER(len=*), INTENT(in) :: service_name
            TYPE(MPI_Info), INTENT(in) :: info
            CHARACTER(len=*), INTENT(in) :: port_name
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Publish_name_f08
    END INTERFACE MPI_Publish_name
    
    INTERFACE MPI_Unpublish_name
        SUBROUTINE MPI_Unpublish_name_f08(service_name, info, port_name, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            IMPLICIT NONE
            CHARACTER(len=*), INTENT(in) :: service_name
            TYPE(MPI_Info), INTENT(in) :: info
            CHARACTER(len=*), INTENT(in) :: port_name
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Unpublish_name_f08
    END INTERFACE MPI_Unpublish_name
    
    INTERFACE MPIX_Stream_create
        SUBROUTINE MPIX_Stream_create_f08(info, stream, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info, MPIX_Stream
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(in) :: info
            TYPE(MPIX_Stream), INTENT(out) :: stream
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Stream_create_f08
    END INTERFACE MPIX_Stream_create
    
    INTERFACE MPIX_Stream_free
        SUBROUTINE MPIX_Stream_free_f08(stream, ierror)
            USE :: mpi_f08_types, ONLY : MPIX_Stream
            IMPLICIT NONE
            TYPE(MPIX_Stream), INTENT(inout) :: stream
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Stream_free_f08
    END INTERFACE MPIX_Stream_free
    
    INTERFACE MPIX_Stream_comm_create
        SUBROUTINE MPIX_Stream_comm_create_f08(comm, stream, newcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPIX_Stream
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPIX_Stream), INTENT(in) :: stream
            TYPE(MPI_Comm), INTENT(out) :: newcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Stream_comm_create_f08
    END INTERFACE MPIX_Stream_comm_create
    
    INTERFACE MPIX_Stream_comm_create_multiplex
        SUBROUTINE MPIX_Stream_comm_create_multiplex_f08(comm, count, array_of_streams, newcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPIX_Stream
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: count
            TYPE(MPIX_Stream), INTENT(in) :: array_of_streams(count)
            TYPE(MPI_Comm), INTENT(out) :: newcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Stream_comm_create_multiplex_f08
    END INTERFACE MPIX_Stream_comm_create_multiplex
    
    INTERFACE MPIX_Comm_get_stream
        SUBROUTINE MPIX_Comm_get_stream_f08(comm, idx, stream, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPIX_Stream
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: idx
            TYPE(MPIX_Stream), INTENT(out) :: stream
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Comm_get_stream_f08
    END INTERFACE MPIX_Comm_get_stream
    
    INTERFACE MPIX_Stream_progress
        SUBROUTINE MPIX_Stream_progress_f08(stream, ierror)
            USE :: mpi_f08_types, ONLY : MPIX_Stream
            IMPLICIT NONE
            TYPE(MPIX_Stream), INTENT(in) :: stream
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Stream_progress_f08
    END INTERFACE MPIX_Stream_progress
    
    INTERFACE MPIX_Start_progress_thread
        SUBROUTINE MPIX_Start_progress_thread_f08(stream, ierror)
            USE :: mpi_f08_types, ONLY : MPIX_Stream
            IMPLICIT NONE
            TYPE(MPIX_Stream), INTENT(in) :: stream
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Start_progress_thread_f08
    END INTERFACE MPIX_Start_progress_thread
    
    INTERFACE MPIX_Stop_progress_thread
        SUBROUTINE MPIX_Stop_progress_thread_f08(stream, ierror)
            USE :: mpi_f08_types, ONLY : MPIX_Stream
            IMPLICIT NONE
            TYPE(MPIX_Stream), INTENT(in) :: stream
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Stop_progress_thread_f08
    END INTERFACE MPIX_Stop_progress_thread
    
    INTERFACE MPIX_Stream_send
        SUBROUTINE MPIX_Stream_send_f08ts(buf, count, datatype, dest, tag, comm, source_stream_index, &
                                          dest_stream_index, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
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
        END SUBROUTINE MPIX_Stream_send_f08ts
        
        SUBROUTINE MPIX_Stream_send_c_f08ts(buf, count, datatype, dest, tag, comm, source_stream_index, &
                                            dest_stream_index, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
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
        END SUBROUTINE MPIX_Stream_send_c_f08ts
    END INTERFACE MPIX_Stream_send
    
    INTERFACE MPIX_Stream_isend
        SUBROUTINE MPIX_Stream_isend_f08ts(buf, count, datatype, dest, tag, comm, source_stream_index, &
                                           dest_stream_index, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
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
        END SUBROUTINE MPIX_Stream_isend_f08ts
        
        SUBROUTINE MPIX_Stream_isend_c_f08ts(buf, count, datatype, dest, tag, comm, source_stream_index, &
                                             dest_stream_index, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
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
        END SUBROUTINE MPIX_Stream_isend_c_f08ts
    END INTERFACE MPIX_Stream_isend
    
    INTERFACE MPIX_Stream_recv
        SUBROUTINE MPIX_Stream_recv_f08ts(buf, count, datatype, source, tag, comm, source_stream_index, &
                                          dest_stream_index, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Status
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
        END SUBROUTINE MPIX_Stream_recv_f08ts
        
        SUBROUTINE MPIX_Stream_recv_c_f08ts(buf, count, datatype, source, tag, comm, source_stream_index, &
                                            dest_stream_index, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Status
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
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
        END SUBROUTINE MPIX_Stream_recv_c_f08ts
    END INTERFACE MPIX_Stream_recv
    
    INTERFACE MPIX_Stream_irecv
        SUBROUTINE MPIX_Stream_irecv_f08ts(buf, count, datatype, source, tag, comm, source_stream_index, &
                                           dest_stream_index, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
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
        END SUBROUTINE MPIX_Stream_irecv_f08ts
        
        SUBROUTINE MPIX_Stream_irecv_c_f08ts(buf, count, datatype, source, tag, comm, source_stream_index, &
                                             dest_stream_index, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
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
        END SUBROUTINE MPIX_Stream_irecv_c_f08ts
    END INTERFACE MPIX_Stream_irecv
    
    INTERFACE MPIX_Send_enqueue
        SUBROUTINE MPIX_Send_enqueue_f08ts(buf, count, datatype, dest, tag, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Send_enqueue_f08ts
        
        SUBROUTINE MPIX_Send_enqueue_c_f08ts(buf, count, datatype, dest, tag, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Send_enqueue_c_f08ts
    END INTERFACE MPIX_Send_enqueue
    
    INTERFACE MPIX_Recv_enqueue
        SUBROUTINE MPIX_Recv_enqueue_f08ts(buf, count, datatype, source, tag, comm, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Status
            IMPLICIT NONE
            TYPE(*), DIMENSION(..) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: source
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Recv_enqueue_f08ts
        
        SUBROUTINE MPIX_Recv_enqueue_c_f08ts(buf, count, datatype, source, tag, comm, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Status
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..) :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: source
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Recv_enqueue_c_f08ts
    END INTERFACE MPIX_Recv_enqueue
    
    INTERFACE MPIX_Isend_enqueue
        SUBROUTINE MPIX_Isend_enqueue_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Isend_enqueue_f08ts
        
        SUBROUTINE MPIX_Isend_enqueue_c_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Isend_enqueue_c_f08ts
    END INTERFACE MPIX_Isend_enqueue
    
    INTERFACE MPIX_Irecv_enqueue
        SUBROUTINE MPIX_Irecv_enqueue_f08ts(buf, count, datatype, source, tag, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            IMPLICIT NONE
            TYPE(*), DIMENSION(..) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: source
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Irecv_enqueue_f08ts
        
        SUBROUTINE MPIX_Irecv_enqueue_c_f08ts(buf, count, datatype, source, tag, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..) :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: source
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Irecv_enqueue_c_f08ts
    END INTERFACE MPIX_Irecv_enqueue
    
    INTERFACE MPIX_Wait_enqueue
        SUBROUTINE MPIX_Wait_enqueue_f08(request, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_Request), INTENT(inout) :: request
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Wait_enqueue_f08
    END INTERFACE MPIX_Wait_enqueue
    
    INTERFACE MPIX_Waitall_enqueue
        SUBROUTINE MPIX_Waitall_enqueue_f08(count, array_of_requests, array_of_statuses, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status
            IMPLICIT NONE
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Request), INTENT(inout) :: array_of_requests(count)
            TYPE(MPI_Status), INTENT(out), TARGET :: array_of_statuses(*)
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Waitall_enqueue_f08
    END INTERFACE MPIX_Waitall_enqueue
    
    INTERFACE MPIX_Allreduce_enqueue
        SUBROUTINE MPIX_Allreduce_enqueue_f08ts(sendbuf, recvbuf, count, datatype, op, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
            TYPE(*), DIMENSION(..) :: recvbuf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Allreduce_enqueue_f08ts
        
        SUBROUTINE MPIX_Allreduce_enqueue_c_f08ts(sendbuf, recvbuf, count, datatype, op, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
            TYPE(*), DIMENSION(..) :: recvbuf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Allreduce_enqueue_c_f08ts
    END INTERFACE MPIX_Allreduce_enqueue
    
    INTERFACE MPIX_Threadcomm_init
        SUBROUTINE MPIX_Threadcomm_init_f08(comm, num_threads, newthreadcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: num_threads
            TYPE(MPI_Comm), INTENT(out) :: newthreadcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Threadcomm_init_f08
    END INTERFACE MPIX_Threadcomm_init
    
    INTERFACE MPIX_Threadcomm_free
        SUBROUTINE MPIX_Threadcomm_free_f08(threadcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(inout) :: threadcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Threadcomm_free_f08
    END INTERFACE MPIX_Threadcomm_free
    
    INTERFACE MPIX_Threadcomm_start
        SUBROUTINE MPIX_Threadcomm_start_f08(threadcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: threadcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Threadcomm_start_f08
    END INTERFACE MPIX_Threadcomm_start
    
    INTERFACE MPIX_Threadcomm_finish
        SUBROUTINE MPIX_Threadcomm_finish_f08(threadcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: threadcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPIX_Threadcomm_finish_f08
    END INTERFACE MPIX_Threadcomm_finish
    
    INTERFACE MPI_Wtick
        FUNCTION MPI_Wtick_f08() result(res)
            IMPLICIT NONE
            DOUBLE PRECISION :: res
        END FUNCTION MPI_Wtick_f08
    END INTERFACE MPI_Wtick
    
    INTERFACE MPI_Wtime
        FUNCTION MPI_Wtime_f08() result(res)
            IMPLICIT NONE
            DOUBLE PRECISION :: res
        END FUNCTION MPI_Wtime_f08
    END INTERFACE MPI_Wtime
    
    INTERFACE MPI_Cart_coords
        SUBROUTINE MPI_Cart_coords_f08(comm, rank, maxdims, coords, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: rank
            INTEGER, INTENT(in) :: maxdims
            INTEGER, INTENT(out) :: coords(maxdims)
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Cart_coords_f08
    END INTERFACE MPI_Cart_coords
    
    INTERFACE MPI_Cart_create
        SUBROUTINE MPI_Cart_create_f08(comm_old, ndims, dims, periods, reorder, comm_cart, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm_old
            INTEGER, INTENT(in) :: ndims
            INTEGER, INTENT(in) :: dims(ndims)
            LOGICAL, INTENT(in) :: periods(ndims)
            LOGICAL, INTENT(in) :: reorder
            TYPE(MPI_Comm), INTENT(out) :: comm_cart
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Cart_create_f08
    END INTERFACE MPI_Cart_create
    
    INTERFACE MPI_Cart_get
        SUBROUTINE MPI_Cart_get_f08(comm, maxdims, dims, periods, coords, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: maxdims
            INTEGER, INTENT(out) :: dims(maxdims)
            LOGICAL, INTENT(out) :: periods(maxdims)
            INTEGER, INTENT(out) :: coords(maxdims)
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Cart_get_f08
    END INTERFACE MPI_Cart_get
    
    INTERFACE MPI_Cart_map
        SUBROUTINE MPI_Cart_map_f08(comm, ndims, dims, periods, newrank, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: ndims
            INTEGER, INTENT(in) :: dims(ndims)
            LOGICAL, INTENT(in) :: periods(ndims)
            INTEGER, INTENT(out) :: newrank
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Cart_map_f08
    END INTERFACE MPI_Cart_map
    
    INTERFACE MPI_Cart_rank
        SUBROUTINE MPI_Cart_rank_f08(comm, coords, rank, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: coords(*)
            INTEGER, INTENT(out) :: rank
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Cart_rank_f08
    END INTERFACE MPI_Cart_rank
    
    INTERFACE MPI_Cart_shift
        SUBROUTINE MPI_Cart_shift_f08(comm, direction, disp, rank_source, rank_dest, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: direction
            INTEGER, INTENT(in) :: disp
            INTEGER, INTENT(out) :: rank_source
            INTEGER, INTENT(out) :: rank_dest
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Cart_shift_f08
    END INTERFACE MPI_Cart_shift
    
    INTERFACE MPI_Cart_sub
        SUBROUTINE MPI_Cart_sub_f08(comm, remain_dims, newcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            LOGICAL, INTENT(in) :: remain_dims(*)
            TYPE(MPI_Comm), INTENT(out) :: newcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Cart_sub_f08
    END INTERFACE MPI_Cart_sub
    
    INTERFACE MPI_Cartdim_get
        SUBROUTINE MPI_Cartdim_get_f08(comm, ndims, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(out) :: ndims
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Cartdim_get_f08
    END INTERFACE MPI_Cartdim_get
    
    INTERFACE MPI_Dims_create
        SUBROUTINE MPI_Dims_create_f08(nnodes, ndims, dims, ierror)
            IMPLICIT NONE
            INTEGER, INTENT(in) :: nnodes
            INTEGER, INTENT(in) :: ndims
            INTEGER, INTENT(inout) :: dims(ndims)
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Dims_create_f08
    END INTERFACE MPI_Dims_create
    
    INTERFACE MPI_Dist_graph_create
        SUBROUTINE MPI_Dist_graph_create_f08(comm_old, n, sources, degrees, destinations, weights, info, &
                                             reorder, comm_dist_graph, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Info
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
        END SUBROUTINE MPI_Dist_graph_create_f08
    END INTERFACE MPI_Dist_graph_create
    
    INTERFACE MPI_Dist_graph_create_adjacent
        SUBROUTINE MPI_Dist_graph_create_adjacent_f08(comm_old, indegree, sources, sourceweights, outdegree, &
                                                      destinations, destweights, info, reorder, &
                                                      comm_dist_graph, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Info
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
        END SUBROUTINE MPI_Dist_graph_create_adjacent_f08
    END INTERFACE MPI_Dist_graph_create_adjacent
    
    INTERFACE MPI_Dist_graph_neighbors
        SUBROUTINE MPI_Dist_graph_neighbors_f08(comm, maxindegree, sources, sourceweights, maxoutdegree, &
                                                destinations, destweights, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: maxindegree
            INTEGER, INTENT(out) :: sources(maxindegree)
            INTEGER, TARGET :: sourceweights(*)
            INTEGER, INTENT(in) :: maxoutdegree
            INTEGER, INTENT(out) :: destinations(maxoutdegree)
            INTEGER, TARGET :: destweights(*)
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Dist_graph_neighbors_f08
    END INTERFACE MPI_Dist_graph_neighbors
    
    INTERFACE MPI_Dist_graph_neighbors_count
        SUBROUTINE MPI_Dist_graph_neighbors_count_f08(comm, indegree, outdegree, weighted, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(out) :: indegree
            INTEGER, INTENT(out) :: outdegree
            LOGICAL, INTENT(out) :: weighted
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Dist_graph_neighbors_count_f08
    END INTERFACE MPI_Dist_graph_neighbors_count
    
    INTERFACE MPI_Get_hw_resource_info
        SUBROUTINE MPI_Get_hw_resource_info_f08(hw_info, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(out) :: hw_info
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Get_hw_resource_info_f08
    END INTERFACE MPI_Get_hw_resource_info
    
    INTERFACE MPI_Graph_create
        SUBROUTINE MPI_Graph_create_f08(comm_old, nnodes, indx, edges, reorder, comm_graph, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm_old
            INTEGER, INTENT(in) :: nnodes
            INTEGER, INTENT(in) :: indx(nnodes)
            INTEGER, INTENT(in) :: edges(*)
            LOGICAL, INTENT(in) :: reorder
            TYPE(MPI_Comm), INTENT(out) :: comm_graph
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Graph_create_f08
    END INTERFACE MPI_Graph_create
    
    INTERFACE MPI_Graph_get
        SUBROUTINE MPI_Graph_get_f08(comm, maxindex, maxedges, indx, edges, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: maxindex
            INTEGER, INTENT(in) :: maxedges
            INTEGER, INTENT(out) :: indx(maxindex)
            INTEGER, INTENT(out) :: edges(maxedges)
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Graph_get_f08
    END INTERFACE MPI_Graph_get
    
    INTERFACE MPI_Graph_map
        SUBROUTINE MPI_Graph_map_f08(comm, nnodes, indx, edges, newrank, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: nnodes
            INTEGER, INTENT(in) :: indx(nnodes)
            INTEGER, INTENT(in) :: edges(*)
            INTEGER, INTENT(out) :: newrank
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Graph_map_f08
    END INTERFACE MPI_Graph_map
    
    INTERFACE MPI_Graph_neighbors
        SUBROUTINE MPI_Graph_neighbors_f08(comm, rank, maxneighbors, neighbors, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: rank
            INTEGER, INTENT(in) :: maxneighbors
            INTEGER, INTENT(out) :: neighbors(maxneighbors)
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Graph_neighbors_f08
    END INTERFACE MPI_Graph_neighbors
    
    INTERFACE MPI_Graph_neighbors_count
        SUBROUTINE MPI_Graph_neighbors_count_f08(comm, rank, nneighbors, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: rank
            INTEGER, INTENT(out) :: nneighbors
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Graph_neighbors_count_f08
    END INTERFACE MPI_Graph_neighbors_count
    
    INTERFACE MPI_Graphdims_get
        SUBROUTINE MPI_Graphdims_get_f08(comm, nnodes, nedges, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(out) :: nnodes
            INTEGER, INTENT(out) :: nedges
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Graphdims_get_f08
    END INTERFACE MPI_Graphdims_get
    
    INTERFACE MPI_Topo_test
        SUBROUTINE MPI_Topo_test_f08(comm, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(out) :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Topo_test_f08
    END INTERFACE MPI_Topo_test
    
    INTERFACE MPI_File_close
        SUBROUTINE MPI_File_close_f08(fh, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(inout) :: fh
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_close_f08
    END INTERFACE MPI_File_close
    
    INTERFACE MPI_File_delete
        SUBROUTINE MPI_File_delete_f08(filename, info, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            IMPLICIT NONE
            CHARACTER(len=*), INTENT(in) :: filename
            TYPE(MPI_Info), INTENT(in) :: info
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_delete_f08
    END INTERFACE MPI_File_delete
    
    INTERFACE MPI_File_get_amode
        SUBROUTINE MPI_File_get_amode_f08(fh, amode, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER, INTENT(out) :: amode
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_get_amode_f08
    END INTERFACE MPI_File_get_amode
    
    INTERFACE MPI_File_get_atomicity
        SUBROUTINE MPI_File_get_atomicity_f08(fh, flag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            LOGICAL, INTENT(out) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_get_atomicity_f08
    END INTERFACE MPI_File_get_atomicity
    
    INTERFACE MPI_File_get_byte_offset
        SUBROUTINE MPI_File_get_byte_offset_f08(fh, offset, disp, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(out) :: disp
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_get_byte_offset_f08
    END INTERFACE MPI_File_get_byte_offset
    
    INTERFACE MPI_File_get_group
        SUBROUTINE MPI_File_get_group_f08(fh, group, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Group
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(MPI_Group), INTENT(out) :: group
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_get_group_f08
    END INTERFACE MPI_File_get_group
    
    INTERFACE MPI_File_get_info
        SUBROUTINE MPI_File_get_info_f08(fh, info_used, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Info
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(MPI_Info), INTENT(out) :: info_used
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_get_info_f08
    END INTERFACE MPI_File_get_info
    
    INTERFACE MPI_File_get_position
        SUBROUTINE MPI_File_get_position_f08(fh, offset, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(out) :: offset
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_get_position_f08
    END INTERFACE MPI_File_get_position
    
    INTERFACE MPI_File_get_position_shared
        SUBROUTINE MPI_File_get_position_shared_f08(fh, offset, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(out) :: offset
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_get_position_shared_f08
    END INTERFACE MPI_File_get_position_shared
    
    INTERFACE MPI_File_get_size
        SUBROUTINE MPI_File_get_size_f08(fh, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_get_size_f08
    END INTERFACE MPI_File_get_size
    
    INTERFACE MPI_File_get_type_extent
        SUBROUTINE MPI_File_get_type_extent_f08(fh, datatype, extent, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: extent
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_get_type_extent_f08
    END INTERFACE MPI_File_get_type_extent
    
    INTERFACE MPI_File_get_view
        SUBROUTINE MPI_File_get_view_f08(fh, disp, etype, filetype, datarep, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(out) :: disp
            TYPE(MPI_Datatype), INTENT(out) :: etype
            TYPE(MPI_Datatype), INTENT(out) :: filetype
            CHARACTER(len=*), INTENT(out) :: datarep
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_get_view_f08
    END INTERFACE MPI_File_get_view
    
    INTERFACE MPI_File_iread
        SUBROUTINE MPI_File_iread_f08ts(fh, buf, count, datatype, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Request
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_iread_f08ts
        
        SUBROUTINE MPI_File_iread_c_f08ts(fh, buf, count, datatype, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_iread_c_f08ts
    END INTERFACE MPI_File_iread
    
    INTERFACE MPI_File_iread_all
        SUBROUTINE MPI_File_iread_all_f08ts(fh, buf, count, datatype, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Request
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_iread_all_f08ts
        
        SUBROUTINE MPI_File_iread_all_c_f08ts(fh, buf, count, datatype, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_iread_all_c_f08ts
    END INTERFACE MPI_File_iread_all
    
    INTERFACE MPI_File_iread_at
        SUBROUTINE MPI_File_iread_at_f08ts(fh, offset, buf, count, datatype, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_iread_at_f08ts
        
        SUBROUTINE MPI_File_iread_at_c_f08ts(fh, offset, buf, count, datatype, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND, MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_iread_at_c_f08ts
    END INTERFACE MPI_File_iread_at
    
    INTERFACE MPI_File_iread_at_all
        SUBROUTINE MPI_File_iread_at_all_f08ts(fh, offset, buf, count, datatype, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_iread_at_all_f08ts
        
        SUBROUTINE MPI_File_iread_at_all_c_f08ts(fh, offset, buf, count, datatype, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND, MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_iread_at_all_c_f08ts
    END INTERFACE MPI_File_iread_at_all
    
    INTERFACE MPI_File_iread_shared
        SUBROUTINE MPI_File_iread_shared_f08ts(fh, buf, count, datatype, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Request
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_iread_shared_f08ts
        
        SUBROUTINE MPI_File_iread_shared_c_f08ts(fh, buf, count, datatype, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_iread_shared_c_f08ts
    END INTERFACE MPI_File_iread_shared
    
    INTERFACE MPI_File_iwrite
        SUBROUTINE MPI_File_iwrite_f08ts(fh, buf, count, datatype, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Request
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_iwrite_f08ts
        
        SUBROUTINE MPI_File_iwrite_c_f08ts(fh, buf, count, datatype, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_iwrite_c_f08ts
    END INTERFACE MPI_File_iwrite
    
    INTERFACE MPI_File_iwrite_all
        SUBROUTINE MPI_File_iwrite_all_f08ts(fh, buf, count, datatype, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Request
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_iwrite_all_f08ts
        
        SUBROUTINE MPI_File_iwrite_all_c_f08ts(fh, buf, count, datatype, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_iwrite_all_c_f08ts
    END INTERFACE MPI_File_iwrite_all
    
    INTERFACE MPI_File_iwrite_at
        SUBROUTINE MPI_File_iwrite_at_f08ts(fh, offset, buf, count, datatype, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_iwrite_at_f08ts
        
        SUBROUTINE MPI_File_iwrite_at_c_f08ts(fh, offset, buf, count, datatype, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND, MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_iwrite_at_c_f08ts
    END INTERFACE MPI_File_iwrite_at
    
    INTERFACE MPI_File_iwrite_at_all
        SUBROUTINE MPI_File_iwrite_at_all_f08ts(fh, offset, buf, count, datatype, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_iwrite_at_all_f08ts
        
        SUBROUTINE MPI_File_iwrite_at_all_c_f08ts(fh, offset, buf, count, datatype, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND, MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_iwrite_at_all_c_f08ts
    END INTERFACE MPI_File_iwrite_at_all
    
    INTERFACE MPI_File_iwrite_shared
        SUBROUTINE MPI_File_iwrite_shared_f08ts(fh, buf, count, datatype, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Request
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_iwrite_shared_f08ts
        
        SUBROUTINE MPI_File_iwrite_shared_c_f08ts(fh, buf, count, datatype, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_iwrite_shared_c_f08ts
    END INTERFACE MPI_File_iwrite_shared
    
    INTERFACE MPI_File_open
        SUBROUTINE MPI_File_open_f08(comm, filename, amode, info, fh, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Info, MPI_File
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            CHARACTER(len=*), INTENT(in) :: filename
            INTEGER, INTENT(in) :: amode
            TYPE(MPI_Info), INTENT(in) :: info
            TYPE(MPI_File), INTENT(out) :: fh
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_open_f08
    END INTERFACE MPI_File_open
    
    INTERFACE MPI_File_preallocate
        SUBROUTINE MPI_File_preallocate_f08(fh, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_preallocate_f08
    END INTERFACE MPI_File_preallocate
    
    INTERFACE MPI_File_read
        SUBROUTINE MPI_File_read_f08ts(fh, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_read_f08ts
        
        SUBROUTINE MPI_File_read_c_f08ts(fh, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..) :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_read_c_f08ts
    END INTERFACE MPI_File_read
    
    INTERFACE MPI_File_read_all
        SUBROUTINE MPI_File_read_all_f08ts(fh, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_read_all_f08ts
        
        SUBROUTINE MPI_File_read_all_c_f08ts(fh, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..) :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_read_all_c_f08ts
    END INTERFACE MPI_File_read_all
    
    INTERFACE MPI_File_read_all_begin
        SUBROUTINE MPI_File_read_all_begin_f08ts(fh, buf, count, datatype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_read_all_begin_f08ts
        
        SUBROUTINE MPI_File_read_all_begin_c_f08ts(fh, buf, count, datatype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_read_all_begin_c_f08ts
    END INTERFACE MPI_File_read_all_begin
    
    INTERFACE MPI_File_read_all_end
        SUBROUTINE MPI_File_read_all_end_f08ts(fh, buf, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_read_all_end_f08ts
    END INTERFACE MPI_File_read_all_end
    
    INTERFACE MPI_File_read_at
        SUBROUTINE MPI_File_read_at_f08ts(fh, offset, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
            TYPE(*), DIMENSION(..) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_read_at_f08ts
        
        SUBROUTINE MPI_File_read_at_c_f08ts(fh, offset, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND, MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
            TYPE(*), DIMENSION(..) :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_read_at_c_f08ts
    END INTERFACE MPI_File_read_at
    
    INTERFACE MPI_File_read_at_all
        SUBROUTINE MPI_File_read_at_all_f08ts(fh, offset, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
            TYPE(*), DIMENSION(..) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_read_at_all_f08ts
        
        SUBROUTINE MPI_File_read_at_all_c_f08ts(fh, offset, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND, MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
            TYPE(*), DIMENSION(..) :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_read_at_all_c_f08ts
    END INTERFACE MPI_File_read_at_all
    
    INTERFACE MPI_File_read_at_all_begin
        SUBROUTINE MPI_File_read_at_all_begin_f08ts(fh, offset, buf, count, datatype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_read_at_all_begin_f08ts
        
        SUBROUTINE MPI_File_read_at_all_begin_c_f08ts(fh, offset, buf, count, datatype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND, MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_read_at_all_begin_c_f08ts
    END INTERFACE MPI_File_read_at_all_begin
    
    INTERFACE MPI_File_read_at_all_end
        SUBROUTINE MPI_File_read_at_all_end_f08ts(fh, buf, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_read_at_all_end_f08ts
    END INTERFACE MPI_File_read_at_all_end
    
    INTERFACE MPI_File_read_ordered
        SUBROUTINE MPI_File_read_ordered_f08ts(fh, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_read_ordered_f08ts
        
        SUBROUTINE MPI_File_read_ordered_c_f08ts(fh, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..) :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_read_ordered_c_f08ts
    END INTERFACE MPI_File_read_ordered
    
    INTERFACE MPI_File_read_ordered_begin
        SUBROUTINE MPI_File_read_ordered_begin_f08ts(fh, buf, count, datatype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_read_ordered_begin_f08ts
        
        SUBROUTINE MPI_File_read_ordered_begin_c_f08ts(fh, buf, count, datatype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_read_ordered_begin_c_f08ts
    END INTERFACE MPI_File_read_ordered_begin
    
    INTERFACE MPI_File_read_ordered_end
        SUBROUTINE MPI_File_read_ordered_end_f08ts(fh, buf, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_read_ordered_end_f08ts
    END INTERFACE MPI_File_read_ordered_end
    
    INTERFACE MPI_File_read_shared
        SUBROUTINE MPI_File_read_shared_f08ts(fh, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_read_shared_f08ts
        
        SUBROUTINE MPI_File_read_shared_c_f08ts(fh, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..) :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_read_shared_c_f08ts
    END INTERFACE MPI_File_read_shared
    
    INTERFACE MPI_File_seek
        SUBROUTINE MPI_File_seek_f08(fh, offset, whence, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
            INTEGER, INTENT(in) :: whence
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_seek_f08
    END INTERFACE MPI_File_seek
    
    INTERFACE MPI_File_seek_shared
        SUBROUTINE MPI_File_seek_shared_f08(fh, offset, whence, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
            INTEGER, INTENT(in) :: whence
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_seek_shared_f08
    END INTERFACE MPI_File_seek_shared
    
    INTERFACE MPI_File_set_atomicity
        SUBROUTINE MPI_File_set_atomicity_f08(fh, flag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            LOGICAL, INTENT(in) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_set_atomicity_f08
    END INTERFACE MPI_File_set_atomicity
    
    INTERFACE MPI_File_set_info
        SUBROUTINE MPI_File_set_info_f08(fh, info, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Info
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(MPI_Info), INTENT(in) :: info
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_set_info_f08
    END INTERFACE MPI_File_set_info
    
    INTERFACE MPI_File_set_size
        SUBROUTINE MPI_File_set_size_f08(fh, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_set_size_f08
    END INTERFACE MPI_File_set_size
    
    INTERFACE MPI_File_set_view
        SUBROUTINE MPI_File_set_view_f08(fh, disp, etype, filetype, datarep, info, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Info
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: disp
            TYPE(MPI_Datatype), INTENT(in) :: etype
            TYPE(MPI_Datatype), INTENT(in) :: filetype
            CHARACTER(len=*), INTENT(in) :: datarep
            TYPE(MPI_Info), INTENT(in) :: info
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_set_view_f08
    END INTERFACE MPI_File_set_view
    
    INTERFACE MPI_File_sync
        SUBROUTINE MPI_File_sync_f08(fh, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_sync_f08
    END INTERFACE MPI_File_sync
    
    INTERFACE MPI_File_write
        SUBROUTINE MPI_File_write_f08ts(fh, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_write_f08ts
        
        SUBROUTINE MPI_File_write_c_f08ts(fh, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_write_c_f08ts
    END INTERFACE MPI_File_write
    
    INTERFACE MPI_File_write_all
        SUBROUTINE MPI_File_write_all_f08ts(fh, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_write_all_f08ts
        
        SUBROUTINE MPI_File_write_all_c_f08ts(fh, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_write_all_c_f08ts
    END INTERFACE MPI_File_write_all
    
    INTERFACE MPI_File_write_all_begin
        SUBROUTINE MPI_File_write_all_begin_f08ts(fh, buf, count, datatype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_write_all_begin_f08ts
        
        SUBROUTINE MPI_File_write_all_begin_c_f08ts(fh, buf, count, datatype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_write_all_begin_c_f08ts
    END INTERFACE MPI_File_write_all_begin
    
    INTERFACE MPI_File_write_all_end
        SUBROUTINE MPI_File_write_all_end_f08ts(fh, buf, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_write_all_end_f08ts
    END INTERFACE MPI_File_write_all_end
    
    INTERFACE MPI_File_write_at
        SUBROUTINE MPI_File_write_at_f08ts(fh, offset, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_write_at_f08ts
        
        SUBROUTINE MPI_File_write_at_c_f08ts(fh, offset, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND, MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_write_at_c_f08ts
    END INTERFACE MPI_File_write_at
    
    INTERFACE MPI_File_write_at_all
        SUBROUTINE MPI_File_write_at_all_f08ts(fh, offset, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_write_at_all_f08ts
        
        SUBROUTINE MPI_File_write_at_all_c_f08ts(fh, offset, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND, MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_write_at_all_c_f08ts
    END INTERFACE MPI_File_write_at_all
    
    INTERFACE MPI_File_write_at_all_begin
        SUBROUTINE MPI_File_write_at_all_begin_f08ts(fh, offset, buf, count, datatype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_write_at_all_begin_f08ts
        
        SUBROUTINE MPI_File_write_at_all_begin_c_f08ts(fh, offset, buf, count, datatype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND, MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_write_at_all_begin_c_f08ts
    END INTERFACE MPI_File_write_at_all_begin
    
    INTERFACE MPI_File_write_at_all_end
        SUBROUTINE MPI_File_write_at_all_end_f08ts(fh, buf, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_write_at_all_end_f08ts
    END INTERFACE MPI_File_write_at_all_end
    
    INTERFACE MPI_File_write_ordered
        SUBROUTINE MPI_File_write_ordered_f08ts(fh, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_write_ordered_f08ts
        
        SUBROUTINE MPI_File_write_ordered_c_f08ts(fh, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_write_ordered_c_f08ts
    END INTERFACE MPI_File_write_ordered
    
    INTERFACE MPI_File_write_ordered_begin
        SUBROUTINE MPI_File_write_ordered_begin_f08ts(fh, buf, count, datatype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_write_ordered_begin_f08ts
        
        SUBROUTINE MPI_File_write_ordered_begin_c_f08ts(fh, buf, count, datatype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_write_ordered_begin_c_f08ts
    END INTERFACE MPI_File_write_ordered_begin
    
    INTERFACE MPI_File_write_ordered_end
        SUBROUTINE MPI_File_write_ordered_end_f08ts(fh, buf, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_write_ordered_end_f08ts
    END INTERFACE MPI_File_write_ordered_end
    
    INTERFACE MPI_File_write_shared
        SUBROUTINE MPI_File_write_shared_f08ts(fh, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_write_shared_f08ts
        
        SUBROUTINE MPI_File_write_shared_c_f08ts(fh, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_File_write_shared_c_f08ts
    END INTERFACE MPI_File_write_shared
    
    INTERFACE MPI_Register_datarep
        SUBROUTINE MPI_Register_datarep_f08(datarep, read_conversion_fn, write_conversion_fn, &
                                            dtype_file_extent_fn, extra_state, ierror)
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            USE :: mpi_f08_callbacks, ONLY : MPI_Datarep_conversion_function, MPI_Datarep_extent_function
            IMPLICIT NONE
            CHARACTER(len=*), INTENT(in) :: datarep
            PROCEDURE(MPI_Datarep_conversion_function) :: read_conversion_fn
            PROCEDURE(MPI_Datarep_conversion_function) :: write_conversion_fn
            PROCEDURE(MPI_Datarep_extent_function) :: dtype_file_extent_fn
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: extra_state
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Register_datarep_f08
    END INTERFACE MPI_Register_datarep
    
    INTERFACE MPI_Register_datarep_c
        SUBROUTINE MPI_Register_datarep_c_f08(datarep, read_conversion_fn, write_conversion_fn, &
                                              dtype_file_extent_fn, extra_state, ierror)
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            USE :: mpi_f08_callbacks, ONLY : MPI_Datarep_conversion_function_c, MPI_Datarep_extent_function
            IMPLICIT NONE
            CHARACTER(len=*), INTENT(in) :: datarep
            PROCEDURE(MPI_Datarep_conversion_function_c) :: read_conversion_fn
            PROCEDURE(MPI_Datarep_conversion_function_c) :: write_conversion_fn
            PROCEDURE(MPI_Datarep_extent_function) :: dtype_file_extent_fn
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: extra_state
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_Register_datarep_c_f08
    END INTERFACE MPI_Register_datarep_c
    
    INTERFACE MPI_F_sync_reg
        SUBROUTINE MPI_F_sync_reg_f08ts(buf, ierror)
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(inout), ASYNCHRONOUS :: buf
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE MPI_F_sync_reg_f08ts
    END INTERFACE MPI_F_sync_reg
    
END MODULE mpi_f08
