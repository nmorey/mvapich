!
! Copyright (C) by Argonne National Laboratory
!     See COPYRIGHT in top-level directory
!

! -- THIS FILE IS AUTO-GENERATED -- 

MODULE pmpi_f08
    USE,intrinsic :: iso_c_binding, ONLY: c_ptr
    USE :: mpi_f08_types
    USE :: mpi_f08_compile_constants
    USE :: mpi_f08_link_constants
    USE :: mpi_f08_callbacks
    
    IMPLICIT NONE
    
    INTERFACE PMPI_Comm_create_keyval
        SUBROUTINE PMPIR_Comm_create_keyval_f08(comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, &
                                              extra_state, ierror)
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            USE :: mpi_f08_callbacks, ONLY : MPI_Comm_copy_attr_function, MPI_Comm_delete_attr_function
            IMPLICIT NONE
            PROCEDURE(MPI_Comm_copy_attr_function) :: comm_copy_attr_fn
            PROCEDURE(MPI_Comm_delete_attr_function) :: comm_delete_attr_fn
            INTEGER, INTENT(out) :: comm_keyval
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: extra_state
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_create_keyval_f08
    END INTERFACE PMPI_Comm_create_keyval
    
    INTERFACE PMPI_Comm_delete_attr
        SUBROUTINE PMPIR_Comm_delete_attr_f08(comm, comm_keyval, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: comm_keyval
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_delete_attr_f08
    END INTERFACE PMPI_Comm_delete_attr
    
    INTERFACE PMPI_Comm_free_keyval
        SUBROUTINE PMPIR_Comm_free_keyval_f08(comm_keyval, ierror)
            IMPLICIT NONE
            INTEGER, INTENT(inout) :: comm_keyval
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_free_keyval_f08
    END INTERFACE PMPI_Comm_free_keyval
    
    INTERFACE PMPI_Comm_get_attr
        SUBROUTINE PMPIR_Comm_get_attr_f08(comm, comm_keyval, attribute_val, flag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: comm_keyval
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: attribute_val
            LOGICAL, INTENT(out) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_get_attr_f08
    END INTERFACE PMPI_Comm_get_attr
    
    INTERFACE PMPI_Comm_set_attr
        SUBROUTINE PMPIR_Comm_set_attr_f08(comm, comm_keyval, attribute_val, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: comm_keyval
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: attribute_val
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_set_attr_f08
    END INTERFACE PMPI_Comm_set_attr
    
    INTERFACE PMPI_Type_create_keyval
        SUBROUTINE PMPIR_Type_create_keyval_f08(type_copy_attr_fn, type_delete_attr_fn, type_keyval, &
                                              extra_state, ierror)
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            USE :: mpi_f08_callbacks, ONLY : MPI_Type_copy_attr_function, MPI_Type_delete_attr_function
            IMPLICIT NONE
            PROCEDURE(MPI_Type_copy_attr_function) :: type_copy_attr_fn
            PROCEDURE(MPI_Type_delete_attr_function) :: type_delete_attr_fn
            INTEGER, INTENT(out) :: type_keyval
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: extra_state
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Type_create_keyval_f08
    END INTERFACE PMPI_Type_create_keyval
    
    INTERFACE PMPI_Type_delete_attr
        SUBROUTINE PMPIR_Type_delete_attr_f08(datatype, type_keyval, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: type_keyval
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Type_delete_attr_f08
    END INTERFACE PMPI_Type_delete_attr
    
    INTERFACE PMPI_Type_free_keyval
        SUBROUTINE PMPIR_Type_free_keyval_f08(type_keyval, ierror)
            IMPLICIT NONE
            INTEGER, INTENT(inout) :: type_keyval
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Type_free_keyval_f08
    END INTERFACE PMPI_Type_free_keyval
    
    INTERFACE PMPI_Type_get_attr
        SUBROUTINE PMPIR_Type_get_attr_f08(datatype, type_keyval, attribute_val, flag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: type_keyval
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: attribute_val
            LOGICAL, INTENT(out) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Type_get_attr_f08
    END INTERFACE PMPI_Type_get_attr
    
    INTERFACE PMPI_Type_set_attr
        SUBROUTINE PMPIR_Type_set_attr_f08(datatype, type_keyval, attribute_val, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: type_keyval
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: attribute_val
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Type_set_attr_f08
    END INTERFACE PMPI_Type_set_attr
    
    INTERFACE PMPI_Win_create_keyval
        SUBROUTINE PMPIR_Win_create_keyval_f08(win_copy_attr_fn, win_delete_attr_fn, win_keyval, extra_state, &
                                             ierror)
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            USE :: mpi_f08_callbacks, ONLY : MPI_Win_copy_attr_function, MPI_Win_delete_attr_function
            IMPLICIT NONE
            PROCEDURE(MPI_Win_copy_attr_function) :: win_copy_attr_fn
            PROCEDURE(MPI_Win_delete_attr_function) :: win_delete_attr_fn
            INTEGER, INTENT(out) :: win_keyval
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: extra_state
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_create_keyval_f08
    END INTERFACE PMPI_Win_create_keyval
    
    INTERFACE PMPI_Win_delete_attr
        SUBROUTINE PMPIR_Win_delete_attr_f08(win, win_keyval, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, INTENT(in) :: win_keyval
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_delete_attr_f08
    END INTERFACE PMPI_Win_delete_attr
    
    INTERFACE PMPI_Win_free_keyval
        SUBROUTINE PMPIR_Win_free_keyval_f08(win_keyval, ierror)
            IMPLICIT NONE
            INTEGER, INTENT(inout) :: win_keyval
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_free_keyval_f08
    END INTERFACE PMPI_Win_free_keyval
    
    INTERFACE PMPI_Win_get_attr
        SUBROUTINE PMPIR_Win_get_attr_f08(win, win_keyval, attribute_val, flag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, INTENT(in) :: win_keyval
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: attribute_val
            LOGICAL, INTENT(out) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_get_attr_f08
    END INTERFACE PMPI_Win_get_attr
    
    INTERFACE PMPI_Win_set_attr
        SUBROUTINE PMPIR_Win_set_attr_f08(win, win_keyval, attribute_val, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, INTENT(in) :: win_keyval
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: attribute_val
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_set_attr_f08
    END INTERFACE PMPI_Win_set_attr
    
    INTERFACE PMPI_Allgather
        SUBROUTINE PMPIR_Allgather_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, &
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
        END SUBROUTINE PMPIR_Allgather_f08ts
        
        SUBROUTINE PMPIR_Allgather_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, &
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
        END SUBROUTINE PMPIR_Allgather_c_f08ts
    END INTERFACE PMPI_Allgather
    
    INTERFACE PMPI_Allgather_init
        SUBROUTINE PMPIR_Allgather_init_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
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
        END SUBROUTINE PMPIR_Allgather_init_f08ts
        
        SUBROUTINE PMPIR_Allgather_init_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
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
        END SUBROUTINE PMPIR_Allgather_init_c_f08ts
    END INTERFACE PMPI_Allgather_init
    
    INTERFACE PMPI_Allgatherv
        SUBROUTINE PMPIR_Allgatherv_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, &
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
        END SUBROUTINE PMPIR_Allgatherv_f08ts
        
        SUBROUTINE PMPIR_Allgatherv_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
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
        END SUBROUTINE PMPIR_Allgatherv_c_f08ts
    END INTERFACE PMPI_Allgatherv
    
    INTERFACE PMPI_Allgatherv_init
        SUBROUTINE PMPIR_Allgatherv_init_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
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
        END SUBROUTINE PMPIR_Allgatherv_init_f08ts
        
        SUBROUTINE PMPIR_Allgatherv_init_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
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
        END SUBROUTINE PMPIR_Allgatherv_init_c_f08ts
    END INTERFACE PMPI_Allgatherv_init
    
    INTERFACE PMPI_Allreduce
        SUBROUTINE PMPIR_Allreduce_f08ts(sendbuf, recvbuf, count, datatype, op, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
            TYPE(*), DIMENSION(..) :: recvbuf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Allreduce_f08ts
        
        SUBROUTINE PMPIR_Allreduce_c_f08ts(sendbuf, recvbuf, count, datatype, op, comm, ierror)
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
        END SUBROUTINE PMPIR_Allreduce_c_f08ts
    END INTERFACE PMPI_Allreduce
    
    INTERFACE PMPI_Allreduce_init
        SUBROUTINE PMPIR_Allreduce_init_f08ts(sendbuf, recvbuf, count, datatype, op, comm, info, request, &
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
        END SUBROUTINE PMPIR_Allreduce_init_f08ts
        
        SUBROUTINE PMPIR_Allreduce_init_c_f08ts(sendbuf, recvbuf, count, datatype, op, comm, info, request, &
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
        END SUBROUTINE PMPIR_Allreduce_init_c_f08ts
    END INTERFACE PMPI_Allreduce_init
    
    INTERFACE PMPI_Alltoall
        SUBROUTINE PMPIR_Alltoall_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, &
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
        END SUBROUTINE PMPIR_Alltoall_f08ts
        
        SUBROUTINE PMPIR_Alltoall_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, &
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
        END SUBROUTINE PMPIR_Alltoall_c_f08ts
    END INTERFACE PMPI_Alltoall
    
    INTERFACE PMPI_Alltoall_init
        SUBROUTINE PMPIR_Alltoall_init_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, &
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
        END SUBROUTINE PMPIR_Alltoall_init_f08ts
        
        SUBROUTINE PMPIR_Alltoall_init_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
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
        END SUBROUTINE PMPIR_Alltoall_init_c_f08ts
    END INTERFACE PMPI_Alltoall_init
    
    INTERFACE PMPI_Alltoallv
        SUBROUTINE PMPIR_Alltoallv_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, &
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
        END SUBROUTINE PMPIR_Alltoallv_f08ts
        
        SUBROUTINE PMPIR_Alltoallv_c_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, &
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
        END SUBROUTINE PMPIR_Alltoallv_c_f08ts
    END INTERFACE PMPI_Alltoallv
    
    INTERFACE PMPI_Alltoallv_init
        SUBROUTINE PMPIR_Alltoallv_init_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, &
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
        END SUBROUTINE PMPIR_Alltoallv_init_f08ts
        
        SUBROUTINE PMPIR_Alltoallv_init_c_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, &
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
        END SUBROUTINE PMPIR_Alltoallv_init_c_f08ts
    END INTERFACE PMPI_Alltoallv_init
    
    INTERFACE PMPI_Alltoallw
        SUBROUTINE PMPIR_Alltoallw_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, &
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
        END SUBROUTINE PMPIR_Alltoallw_f08ts
        
        SUBROUTINE PMPIR_Alltoallw_c_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, &
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
        END SUBROUTINE PMPIR_Alltoallw_c_f08ts
    END INTERFACE PMPI_Alltoallw
    
    INTERFACE PMPI_Alltoallw_init
        SUBROUTINE PMPIR_Alltoallw_init_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, &
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
        END SUBROUTINE PMPIR_Alltoallw_init_f08ts
        
        SUBROUTINE PMPIR_Alltoallw_init_c_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, &
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
        END SUBROUTINE PMPIR_Alltoallw_init_c_f08ts
    END INTERFACE PMPI_Alltoallw_init
    
    INTERFACE PMPI_Barrier
        SUBROUTINE PMPIR_Barrier_f08(comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Barrier_f08
    END INTERFACE PMPI_Barrier
    
    INTERFACE PMPI_Barrier_init
        SUBROUTINE PMPIR_Barrier_init_f08(comm, info, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Info, MPI_Request
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Info), INTENT(in) :: info
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Barrier_init_f08
    END INTERFACE PMPI_Barrier_init
    
    INTERFACE PMPI_Bcast
        SUBROUTINE PMPIR_Bcast_f08ts(buffer, count, datatype, root, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(inout) :: buffer
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: root
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Bcast_f08ts
        
        SUBROUTINE PMPIR_Bcast_c_f08ts(buffer, count, datatype, root, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(inout) :: buffer
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: root
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Bcast_c_f08ts
    END INTERFACE PMPI_Bcast
    
    INTERFACE PMPI_Bcast_init
        SUBROUTINE PMPIR_Bcast_init_f08ts(buffer, count, datatype, root, comm, info, request, ierror)
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
        END SUBROUTINE PMPIR_Bcast_init_f08ts
        
        SUBROUTINE PMPIR_Bcast_init_c_f08ts(buffer, count, datatype, root, comm, info, request, ierror)
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
        END SUBROUTINE PMPIR_Bcast_init_c_f08ts
    END INTERFACE PMPI_Bcast_init
    
    INTERFACE PMPI_Exscan
        SUBROUTINE PMPIR_Exscan_f08ts(sendbuf, recvbuf, count, datatype, op, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
            TYPE(*), DIMENSION(..) :: recvbuf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Exscan_f08ts
        
        SUBROUTINE PMPIR_Exscan_c_f08ts(sendbuf, recvbuf, count, datatype, op, comm, ierror)
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
        END SUBROUTINE PMPIR_Exscan_c_f08ts
    END INTERFACE PMPI_Exscan
    
    INTERFACE PMPI_Exscan_init
        SUBROUTINE PMPIR_Exscan_init_f08ts(sendbuf, recvbuf, count, datatype, op, comm, info, request, &
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
        END SUBROUTINE PMPIR_Exscan_init_f08ts
        
        SUBROUTINE PMPIR_Exscan_init_c_f08ts(sendbuf, recvbuf, count, datatype, op, comm, info, request, &
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
        END SUBROUTINE PMPIR_Exscan_init_c_f08ts
    END INTERFACE PMPI_Exscan_init
    
    INTERFACE PMPI_Gather
        SUBROUTINE PMPIR_Gather_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, &
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
        END SUBROUTINE PMPIR_Gather_f08ts
        
        SUBROUTINE PMPIR_Gather_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, &
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
        END SUBROUTINE PMPIR_Gather_c_f08ts
    END INTERFACE PMPI_Gather
    
    INTERFACE PMPI_Gather_init
        SUBROUTINE PMPIR_Gather_init_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, &
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
        END SUBROUTINE PMPIR_Gather_init_f08ts
        
        SUBROUTINE PMPIR_Gather_init_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, &
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
        END SUBROUTINE PMPIR_Gather_init_c_f08ts
    END INTERFACE PMPI_Gather_init
    
    INTERFACE PMPI_Gatherv
        SUBROUTINE PMPIR_Gatherv_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, &
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
        END SUBROUTINE PMPIR_Gatherv_f08ts
        
        SUBROUTINE PMPIR_Gatherv_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, &
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
        END SUBROUTINE PMPIR_Gatherv_c_f08ts
    END INTERFACE PMPI_Gatherv
    
    INTERFACE PMPI_Gatherv_init
        SUBROUTINE PMPIR_Gatherv_init_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
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
        END SUBROUTINE PMPIR_Gatherv_init_f08ts
        
        SUBROUTINE PMPIR_Gatherv_init_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
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
        END SUBROUTINE PMPIR_Gatherv_init_c_f08ts
    END INTERFACE PMPI_Gatherv_init
    
    INTERFACE PMPI_Iallgather
        SUBROUTINE PMPIR_Iallgather_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, &
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
        END SUBROUTINE PMPIR_Iallgather_f08ts
        
        SUBROUTINE PMPIR_Iallgather_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, &
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
        END SUBROUTINE PMPIR_Iallgather_c_f08ts
    END INTERFACE PMPI_Iallgather
    
    INTERFACE PMPI_Iallgatherv
        SUBROUTINE PMPIR_Iallgatherv_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
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
        END SUBROUTINE PMPIR_Iallgatherv_f08ts
        
        SUBROUTINE PMPIR_Iallgatherv_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
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
        END SUBROUTINE PMPIR_Iallgatherv_c_f08ts
    END INTERFACE PMPI_Iallgatherv
    
    INTERFACE PMPI_Iallreduce
        SUBROUTINE PMPIR_Iallreduce_f08ts(sendbuf, recvbuf, count, datatype, op, comm, request, ierror)
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
        END SUBROUTINE PMPIR_Iallreduce_f08ts
        
        SUBROUTINE PMPIR_Iallreduce_c_f08ts(sendbuf, recvbuf, count, datatype, op, comm, request, ierror)
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
        END SUBROUTINE PMPIR_Iallreduce_c_f08ts
    END INTERFACE PMPI_Iallreduce
    
    INTERFACE PMPI_Ialltoall
        SUBROUTINE PMPIR_Ialltoall_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, &
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
        END SUBROUTINE PMPIR_Ialltoall_f08ts
        
        SUBROUTINE PMPIR_Ialltoall_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, &
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
        END SUBROUTINE PMPIR_Ialltoall_c_f08ts
    END INTERFACE PMPI_Ialltoall
    
    INTERFACE PMPI_Ialltoallv
        SUBROUTINE PMPIR_Ialltoallv_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, &
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
        END SUBROUTINE PMPIR_Ialltoallv_f08ts
        
        SUBROUTINE PMPIR_Ialltoallv_c_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, &
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
        END SUBROUTINE PMPIR_Ialltoallv_c_f08ts
    END INTERFACE PMPI_Ialltoallv
    
    INTERFACE PMPI_Ialltoallw
        SUBROUTINE PMPIR_Ialltoallw_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, &
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
        END SUBROUTINE PMPIR_Ialltoallw_f08ts
        
        SUBROUTINE PMPIR_Ialltoallw_c_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, &
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
        END SUBROUTINE PMPIR_Ialltoallw_c_f08ts
    END INTERFACE PMPI_Ialltoallw
    
    INTERFACE PMPI_Ibarrier
        SUBROUTINE PMPIR_Ibarrier_f08(comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Request
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Ibarrier_f08
    END INTERFACE PMPI_Ibarrier
    
    INTERFACE PMPI_Ibcast
        SUBROUTINE PMPIR_Ibcast_f08ts(buffer, count, datatype, root, comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm, MPI_Request
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(inout), ASYNCHRONOUS :: buffer
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: root
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Ibcast_f08ts
        
        SUBROUTINE PMPIR_Ibcast_c_f08ts(buffer, count, datatype, root, comm, request, ierror)
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
        END SUBROUTINE PMPIR_Ibcast_c_f08ts
    END INTERFACE PMPI_Ibcast
    
    INTERFACE PMPI_Iexscan
        SUBROUTINE PMPIR_Iexscan_f08ts(sendbuf, recvbuf, count, datatype, op, comm, request, ierror)
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
        END SUBROUTINE PMPIR_Iexscan_f08ts
        
        SUBROUTINE PMPIR_Iexscan_c_f08ts(sendbuf, recvbuf, count, datatype, op, comm, request, ierror)
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
        END SUBROUTINE PMPIR_Iexscan_c_f08ts
    END INTERFACE PMPI_Iexscan
    
    INTERFACE PMPI_Igather
        SUBROUTINE PMPIR_Igather_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, &
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
        END SUBROUTINE PMPIR_Igather_f08ts
        
        SUBROUTINE PMPIR_Igather_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, &
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
        END SUBROUTINE PMPIR_Igather_c_f08ts
    END INTERFACE PMPI_Igather
    
    INTERFACE PMPI_Igatherv
        SUBROUTINE PMPIR_Igatherv_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, &
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
        END SUBROUTINE PMPIR_Igatherv_f08ts
        
        SUBROUTINE PMPIR_Igatherv_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, &
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
        END SUBROUTINE PMPIR_Igatherv_c_f08ts
    END INTERFACE PMPI_Igatherv
    
    INTERFACE PMPI_Ineighbor_allgather
        SUBROUTINE PMPIR_Ineighbor_allgather_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
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
        END SUBROUTINE PMPIR_Ineighbor_allgather_f08ts
        
        SUBROUTINE PMPIR_Ineighbor_allgather_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, &
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
        END SUBROUTINE PMPIR_Ineighbor_allgather_c_f08ts
    END INTERFACE PMPI_Ineighbor_allgather
    
    INTERFACE PMPI_Ineighbor_allgatherv
        SUBROUTINE PMPIR_Ineighbor_allgatherv_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
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
        END SUBROUTINE PMPIR_Ineighbor_allgatherv_f08ts
        
        SUBROUTINE PMPIR_Ineighbor_allgatherv_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, &
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
        END SUBROUTINE PMPIR_Ineighbor_allgatherv_c_f08ts
    END INTERFACE PMPI_Ineighbor_allgatherv
    
    INTERFACE PMPI_Ineighbor_alltoall
        SUBROUTINE PMPIR_Ineighbor_alltoall_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
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
        END SUBROUTINE PMPIR_Ineighbor_alltoall_f08ts
        
        SUBROUTINE PMPIR_Ineighbor_alltoall_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, &
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
        END SUBROUTINE PMPIR_Ineighbor_alltoall_c_f08ts
    END INTERFACE PMPI_Ineighbor_alltoall
    
    INTERFACE PMPI_Ineighbor_alltoallv
        SUBROUTINE PMPIR_Ineighbor_alltoallv_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, &
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
        END SUBROUTINE PMPIR_Ineighbor_alltoallv_f08ts
        
        SUBROUTINE PMPIR_Ineighbor_alltoallv_c_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, &
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
        END SUBROUTINE PMPIR_Ineighbor_alltoallv_c_f08ts
    END INTERFACE PMPI_Ineighbor_alltoallv
    
    INTERFACE PMPI_Ineighbor_alltoallw
        SUBROUTINE PMPIR_Ineighbor_alltoallw_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, &
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
        END SUBROUTINE PMPIR_Ineighbor_alltoallw_f08ts
        
        SUBROUTINE PMPIR_Ineighbor_alltoallw_c_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, &
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
        END SUBROUTINE PMPIR_Ineighbor_alltoallw_c_f08ts
    END INTERFACE PMPI_Ineighbor_alltoallw
    
    INTERFACE PMPI_Ireduce
        SUBROUTINE PMPIR_Ireduce_f08ts(sendbuf, recvbuf, count, datatype, op, root, comm, request, ierror)
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
        END SUBROUTINE PMPIR_Ireduce_f08ts
        
        SUBROUTINE PMPIR_Ireduce_c_f08ts(sendbuf, recvbuf, count, datatype, op, root, comm, request, ierror)
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
        END SUBROUTINE PMPIR_Ireduce_c_f08ts
    END INTERFACE PMPI_Ireduce
    
    INTERFACE PMPI_Ireduce_scatter
        SUBROUTINE PMPIR_Ireduce_scatter_f08ts(sendbuf, recvbuf, recvcounts, datatype, op, comm, request, &
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
        END SUBROUTINE PMPIR_Ireduce_scatter_f08ts
        
        SUBROUTINE PMPIR_Ireduce_scatter_c_f08ts(sendbuf, recvbuf, recvcounts, datatype, op, comm, request, &
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
        END SUBROUTINE PMPIR_Ireduce_scatter_c_f08ts
    END INTERFACE PMPI_Ireduce_scatter
    
    INTERFACE PMPI_Ireduce_scatter_block
        SUBROUTINE PMPIR_Ireduce_scatter_block_f08ts(sendbuf, recvbuf, recvcount, datatype, op, comm, request, &
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
        END SUBROUTINE PMPIR_Ireduce_scatter_block_f08ts
        
        SUBROUTINE PMPIR_Ireduce_scatter_block_c_f08ts(sendbuf, recvbuf, recvcount, datatype, op, comm, &
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
        END SUBROUTINE PMPIR_Ireduce_scatter_block_c_f08ts
    END INTERFACE PMPI_Ireduce_scatter_block
    
    INTERFACE PMPI_Iscan
        SUBROUTINE PMPIR_Iscan_f08ts(sendbuf, recvbuf, count, datatype, op, comm, request, ierror)
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
        END SUBROUTINE PMPIR_Iscan_f08ts
        
        SUBROUTINE PMPIR_Iscan_c_f08ts(sendbuf, recvbuf, count, datatype, op, comm, request, ierror)
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
        END SUBROUTINE PMPIR_Iscan_c_f08ts
    END INTERFACE PMPI_Iscan
    
    INTERFACE PMPI_Iscatter
        SUBROUTINE PMPIR_Iscatter_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, &
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
        END SUBROUTINE PMPIR_Iscatter_f08ts
        
        SUBROUTINE PMPIR_Iscatter_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, &
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
        END SUBROUTINE PMPIR_Iscatter_c_f08ts
    END INTERFACE PMPI_Iscatter
    
    INTERFACE PMPI_Iscatterv
        SUBROUTINE PMPIR_Iscatterv_f08ts(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, &
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
        END SUBROUTINE PMPIR_Iscatterv_f08ts
        
        SUBROUTINE PMPIR_Iscatterv_c_f08ts(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, &
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
        END SUBROUTINE PMPIR_Iscatterv_c_f08ts
    END INTERFACE PMPI_Iscatterv
    
    INTERFACE PMPI_Neighbor_allgather
        SUBROUTINE PMPIR_Neighbor_allgather_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
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
        END SUBROUTINE PMPIR_Neighbor_allgather_f08ts
        
        SUBROUTINE PMPIR_Neighbor_allgather_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, &
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
        END SUBROUTINE PMPIR_Neighbor_allgather_c_f08ts
    END INTERFACE PMPI_Neighbor_allgather
    
    INTERFACE PMPI_Neighbor_allgather_init
        SUBROUTINE PMPIR_Neighbor_allgather_init_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, &
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
        END SUBROUTINE PMPIR_Neighbor_allgather_init_f08ts
        
        SUBROUTINE PMPIR_Neighbor_allgather_init_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, &
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
        END SUBROUTINE PMPIR_Neighbor_allgather_init_c_f08ts
    END INTERFACE PMPI_Neighbor_allgather_init
    
    INTERFACE PMPI_Neighbor_allgatherv
        SUBROUTINE PMPIR_Neighbor_allgatherv_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
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
        END SUBROUTINE PMPIR_Neighbor_allgatherv_f08ts
        
        SUBROUTINE PMPIR_Neighbor_allgatherv_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, &
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
        END SUBROUTINE PMPIR_Neighbor_allgatherv_c_f08ts
    END INTERFACE PMPI_Neighbor_allgatherv
    
    INTERFACE PMPI_Neighbor_allgatherv_init
        SUBROUTINE PMPIR_Neighbor_allgatherv_init_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, &
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
        END SUBROUTINE PMPIR_Neighbor_allgatherv_init_f08ts
        
        SUBROUTINE PMPIR_Neighbor_allgatherv_init_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcounts, &
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
        END SUBROUTINE PMPIR_Neighbor_allgatherv_init_c_f08ts
    END INTERFACE PMPI_Neighbor_allgatherv_init
    
    INTERFACE PMPI_Neighbor_alltoall
        SUBROUTINE PMPIR_Neighbor_alltoall_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
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
        END SUBROUTINE PMPIR_Neighbor_alltoall_f08ts
        
        SUBROUTINE PMPIR_Neighbor_alltoall_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
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
        END SUBROUTINE PMPIR_Neighbor_alltoall_c_f08ts
    END INTERFACE PMPI_Neighbor_alltoall
    
    INTERFACE PMPI_Neighbor_alltoall_init
        SUBROUTINE PMPIR_Neighbor_alltoall_init_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, &
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
        END SUBROUTINE PMPIR_Neighbor_alltoall_init_f08ts
        
        SUBROUTINE PMPIR_Neighbor_alltoall_init_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, &
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
        END SUBROUTINE PMPIR_Neighbor_alltoall_init_c_f08ts
    END INTERFACE PMPI_Neighbor_alltoall_init
    
    INTERFACE PMPI_Neighbor_alltoallv
        SUBROUTINE PMPIR_Neighbor_alltoallv_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, &
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
        END SUBROUTINE PMPIR_Neighbor_alltoallv_f08ts
        
        SUBROUTINE PMPIR_Neighbor_alltoallv_c_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, &
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
        END SUBROUTINE PMPIR_Neighbor_alltoallv_c_f08ts
    END INTERFACE PMPI_Neighbor_alltoallv
    
    INTERFACE PMPI_Neighbor_alltoallv_init
        SUBROUTINE PMPIR_Neighbor_alltoallv_init_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, &
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
        END SUBROUTINE PMPIR_Neighbor_alltoallv_init_f08ts
        
        SUBROUTINE PMPIR_Neighbor_alltoallv_init_c_f08ts(sendbuf, sendcounts, sdispls, sendtype, recvbuf, &
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
        END SUBROUTINE PMPIR_Neighbor_alltoallv_init_c_f08ts
    END INTERFACE PMPI_Neighbor_alltoallv_init
    
    INTERFACE PMPI_Neighbor_alltoallw
        SUBROUTINE PMPIR_Neighbor_alltoallw_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, &
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
        END SUBROUTINE PMPIR_Neighbor_alltoallw_f08ts
        
        SUBROUTINE PMPIR_Neighbor_alltoallw_c_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, &
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
        END SUBROUTINE PMPIR_Neighbor_alltoallw_c_f08ts
    END INTERFACE PMPI_Neighbor_alltoallw
    
    INTERFACE PMPI_Neighbor_alltoallw_init
        SUBROUTINE PMPIR_Neighbor_alltoallw_init_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, &
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
        END SUBROUTINE PMPIR_Neighbor_alltoallw_init_f08ts
        
        SUBROUTINE PMPIR_Neighbor_alltoallw_init_c_f08ts(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, &
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
        END SUBROUTINE PMPIR_Neighbor_alltoallw_init_c_f08ts
    END INTERFACE PMPI_Neighbor_alltoallw_init
    
    INTERFACE PMPI_Reduce
        SUBROUTINE PMPIR_Reduce_f08ts(sendbuf, recvbuf, count, datatype, op, root, comm, ierror)
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
        END SUBROUTINE PMPIR_Reduce_f08ts
        
        SUBROUTINE PMPIR_Reduce_c_f08ts(sendbuf, recvbuf, count, datatype, op, root, comm, ierror)
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
        END SUBROUTINE PMPIR_Reduce_c_f08ts
    END INTERFACE PMPI_Reduce
    
    INTERFACE PMPI_Reduce_init
        SUBROUTINE PMPIR_Reduce_init_f08ts(sendbuf, recvbuf, count, datatype, op, root, comm, info, request, &
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
        END SUBROUTINE PMPIR_Reduce_init_f08ts
        
        SUBROUTINE PMPIR_Reduce_init_c_f08ts(sendbuf, recvbuf, count, datatype, op, root, comm, info, request, &
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
        END SUBROUTINE PMPIR_Reduce_init_c_f08ts
    END INTERFACE PMPI_Reduce_init
    
    INTERFACE PMPI_Reduce_local
        SUBROUTINE PMPIR_Reduce_local_f08ts(inbuf, inoutbuf, count, datatype, op, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: inbuf
            TYPE(*), DIMENSION(..), INTENT(inout) :: inoutbuf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Reduce_local_f08ts
        
        SUBROUTINE PMPIR_Reduce_local_c_f08ts(inbuf, inoutbuf, count, datatype, op, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: inbuf
            TYPE(*), DIMENSION(..), INTENT(inout) :: inoutbuf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Reduce_local_c_f08ts
    END INTERFACE PMPI_Reduce_local
    
    INTERFACE PMPI_Reduce_scatter
        SUBROUTINE PMPIR_Reduce_scatter_f08ts(sendbuf, recvbuf, recvcounts, datatype, op, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
            TYPE(*), DIMENSION(..) :: recvbuf
            INTEGER, INTENT(in) :: recvcounts(*)
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Reduce_scatter_f08ts
        
        SUBROUTINE PMPIR_Reduce_scatter_c_f08ts(sendbuf, recvbuf, recvcounts, datatype, op, comm, ierror)
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
        END SUBROUTINE PMPIR_Reduce_scatter_c_f08ts
    END INTERFACE PMPI_Reduce_scatter
    
    INTERFACE PMPI_Reduce_scatter_block
        SUBROUTINE PMPIR_Reduce_scatter_block_f08ts(sendbuf, recvbuf, recvcount, datatype, op, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
            TYPE(*), DIMENSION(..) :: recvbuf
            INTEGER, INTENT(in) :: recvcount
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Reduce_scatter_block_f08ts
        
        SUBROUTINE PMPIR_Reduce_scatter_block_c_f08ts(sendbuf, recvbuf, recvcount, datatype, op, comm, &
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
        END SUBROUTINE PMPIR_Reduce_scatter_block_c_f08ts
    END INTERFACE PMPI_Reduce_scatter_block
    
    INTERFACE PMPI_Reduce_scatter_block_init
        SUBROUTINE PMPIR_Reduce_scatter_block_init_f08ts(sendbuf, recvbuf, recvcount, datatype, op, comm, &
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
        END SUBROUTINE PMPIR_Reduce_scatter_block_init_f08ts
        
        SUBROUTINE PMPIR_Reduce_scatter_block_init_c_f08ts(sendbuf, recvbuf, recvcount, datatype, op, comm, &
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
        END SUBROUTINE PMPIR_Reduce_scatter_block_init_c_f08ts
    END INTERFACE PMPI_Reduce_scatter_block_init
    
    INTERFACE PMPI_Reduce_scatter_init
        SUBROUTINE PMPIR_Reduce_scatter_init_f08ts(sendbuf, recvbuf, recvcounts, datatype, op, comm, info, &
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
        END SUBROUTINE PMPIR_Reduce_scatter_init_f08ts
        
        SUBROUTINE PMPIR_Reduce_scatter_init_c_f08ts(sendbuf, recvbuf, recvcounts, datatype, op, comm, info, &
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
        END SUBROUTINE PMPIR_Reduce_scatter_init_c_f08ts
    END INTERFACE PMPI_Reduce_scatter_init
    
    INTERFACE PMPI_Scan
        SUBROUTINE PMPIR_Scan_f08ts(sendbuf, recvbuf, count, datatype, op, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
            TYPE(*), DIMENSION(..) :: recvbuf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Scan_f08ts
        
        SUBROUTINE PMPIR_Scan_c_f08ts(sendbuf, recvbuf, count, datatype, op, comm, ierror)
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
        END SUBROUTINE PMPIR_Scan_c_f08ts
    END INTERFACE PMPI_Scan
    
    INTERFACE PMPI_Scan_init
        SUBROUTINE PMPIR_Scan_init_f08ts(sendbuf, recvbuf, count, datatype, op, comm, info, request, ierror)
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
        END SUBROUTINE PMPIR_Scan_init_f08ts
        
        SUBROUTINE PMPIR_Scan_init_c_f08ts(sendbuf, recvbuf, count, datatype, op, comm, info, request, &
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
        END SUBROUTINE PMPIR_Scan_init_c_f08ts
    END INTERFACE PMPI_Scan_init
    
    INTERFACE PMPI_Scatter
        SUBROUTINE PMPIR_Scatter_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, &
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
        END SUBROUTINE PMPIR_Scatter_f08ts
        
        SUBROUTINE PMPIR_Scatter_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, &
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
        END SUBROUTINE PMPIR_Scatter_c_f08ts
    END INTERFACE PMPI_Scatter
    
    INTERFACE PMPI_Scatter_init
        SUBROUTINE PMPIR_Scatter_init_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, &
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
        END SUBROUTINE PMPIR_Scatter_init_f08ts
        
        SUBROUTINE PMPIR_Scatter_init_c_f08ts(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
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
        END SUBROUTINE PMPIR_Scatter_init_c_f08ts
    END INTERFACE PMPI_Scatter_init
    
    INTERFACE PMPI_Scatterv
        SUBROUTINE PMPIR_Scatterv_f08ts(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, &
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
        END SUBROUTINE PMPIR_Scatterv_f08ts
        
        SUBROUTINE PMPIR_Scatterv_c_f08ts(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, &
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
        END SUBROUTINE PMPIR_Scatterv_c_f08ts
    END INTERFACE PMPI_Scatterv
    
    INTERFACE PMPI_Scatterv_init
        SUBROUTINE PMPIR_Scatterv_init_f08ts(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, &
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
        END SUBROUTINE PMPIR_Scatterv_init_f08ts
        
        SUBROUTINE PMPIR_Scatterv_init_c_f08ts(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, &
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
        END SUBROUTINE PMPIR_Scatterv_init_c_f08ts
    END INTERFACE PMPI_Scatterv_init
    
    INTERFACE PMPI_Comm_compare
        SUBROUTINE PMPIR_Comm_compare_f08(comm1, comm2, result, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm1
            TYPE(MPI_Comm), INTENT(in) :: comm2
            INTEGER, INTENT(out) :: result
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_compare_f08
    END INTERFACE PMPI_Comm_compare
    
    INTERFACE PMPI_Comm_create
        SUBROUTINE PMPIR_Comm_create_f08(comm, group, newcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Group), INTENT(in) :: group
            TYPE(MPI_Comm), INTENT(out) :: newcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_create_f08
    END INTERFACE PMPI_Comm_create
    
    INTERFACE PMPI_Comm_create_group
        SUBROUTINE PMPIR_Comm_create_group_f08(comm, group, tag, newcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Group), INTENT(in) :: group
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(out) :: newcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_create_group_f08
    END INTERFACE PMPI_Comm_create_group
    
    INTERFACE PMPI_Comm_dup
        SUBROUTINE PMPIR_Comm_dup_f08(comm, newcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Comm), INTENT(out) :: newcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_dup_f08
    END INTERFACE PMPI_Comm_dup
    
    INTERFACE PMPI_Comm_dup_with_info
        SUBROUTINE PMPIR_Comm_dup_with_info_f08(comm, info, newcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Info), INTENT(in) :: info
            TYPE(MPI_Comm), INTENT(out) :: newcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_dup_with_info_f08
    END INTERFACE PMPI_Comm_dup_with_info
    
    INTERFACE PMPI_Comm_free
        SUBROUTINE PMPIR_Comm_free_f08(comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(inout) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_free_f08
    END INTERFACE PMPI_Comm_free
    
    INTERFACE PMPI_Comm_get_info
        SUBROUTINE PMPIR_Comm_get_info_f08(comm, info_used, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Info), INTENT(out) :: info_used
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_get_info_f08
    END INTERFACE PMPI_Comm_get_info
    
    INTERFACE PMPI_Comm_get_name
        SUBROUTINE PMPIR_Comm_get_name_f08(comm, comm_name, resultlen, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_MAX_OBJECT_NAME
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            CHARACTER(len=MPI_MAX_OBJECT_NAME), INTENT(out) :: comm_name
            INTEGER, INTENT(out) :: resultlen
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_get_name_f08
    END INTERFACE PMPI_Comm_get_name
    
    INTERFACE PMPI_Comm_group
        SUBROUTINE PMPIR_Comm_group_f08(comm, group, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Group), INTENT(out) :: group
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_group_f08
    END INTERFACE PMPI_Comm_group
    
    INTERFACE PMPI_Comm_idup
        SUBROUTINE PMPIR_Comm_idup_f08(comm, newcomm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Request
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Comm), INTENT(out), ASYNCHRONOUS :: newcomm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_idup_f08
    END INTERFACE PMPI_Comm_idup
    
    INTERFACE PMPI_Comm_idup_with_info
        SUBROUTINE PMPIR_Comm_idup_with_info_f08(comm, info, newcomm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Info, MPI_Request
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Info), INTENT(in) :: info
            TYPE(MPI_Comm), INTENT(out), ASYNCHRONOUS :: newcomm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_idup_with_info_f08
    END INTERFACE PMPI_Comm_idup_with_info
    
    INTERFACE PMPI_Comm_rank
        SUBROUTINE PMPIR_Comm_rank_f08(comm, rank, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(out) :: rank
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_rank_f08
    END INTERFACE PMPI_Comm_rank
    
    INTERFACE PMPI_Comm_remote_group
        SUBROUTINE PMPIR_Comm_remote_group_f08(comm, group, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Group), INTENT(out) :: group
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_remote_group_f08
    END INTERFACE PMPI_Comm_remote_group
    
    INTERFACE PMPI_Comm_remote_size
        SUBROUTINE PMPIR_Comm_remote_size_f08(comm, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_remote_size_f08
    END INTERFACE PMPI_Comm_remote_size
    
    INTERFACE PMPI_Comm_set_info
        SUBROUTINE PMPIR_Comm_set_info_f08(comm, info, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Info), INTENT(in) :: info
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_set_info_f08
    END INTERFACE PMPI_Comm_set_info
    
    INTERFACE PMPI_Comm_set_name
        SUBROUTINE PMPIR_Comm_set_name_f08(comm, comm_name, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            CHARACTER(len=*), INTENT(in) :: comm_name
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_set_name_f08
    END INTERFACE PMPI_Comm_set_name
    
    INTERFACE PMPI_Comm_size
        SUBROUTINE PMPIR_Comm_size_f08(comm, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_size_f08
    END INTERFACE PMPI_Comm_size
    
    INTERFACE PMPI_Comm_split
        SUBROUTINE PMPIR_Comm_split_f08(comm, color, key, newcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: color
            INTEGER, INTENT(in) :: key
            TYPE(MPI_Comm), INTENT(out) :: newcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_split_f08
    END INTERFACE PMPI_Comm_split
    
    INTERFACE PMPI_Comm_split_type
        SUBROUTINE PMPIR_Comm_split_type_f08(comm, split_type, key, info, newcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: split_type
            INTEGER, INTENT(in) :: key
            TYPE(MPI_Info), INTENT(in) :: info
            TYPE(MPI_Comm), INTENT(out) :: newcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_split_type_f08
    END INTERFACE PMPI_Comm_split_type
    
    INTERFACE PMPI_Comm_test_inter
        SUBROUTINE PMPIR_Comm_test_inter_f08(comm, flag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            LOGICAL, INTENT(out) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_test_inter_f08
    END INTERFACE PMPI_Comm_test_inter
    
    INTERFACE PMPI_Intercomm_create
        SUBROUTINE PMPIR_Intercomm_create_f08(local_comm, local_leader, peer_comm, remote_leader, tag, &
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
        END SUBROUTINE PMPIR_Intercomm_create_f08
    END INTERFACE PMPI_Intercomm_create
    
    INTERFACE PMPI_Intercomm_create_from_groups
        SUBROUTINE PMPIR_Intercomm_create_from_groups_f08(local_group, local_leader, remote_group, &
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
        END SUBROUTINE PMPIR_Intercomm_create_from_groups_f08
    END INTERFACE PMPI_Intercomm_create_from_groups
    
    INTERFACE PMPI_Intercomm_merge
        SUBROUTINE PMPIR_Intercomm_merge_f08(intercomm, high, newintracomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: intercomm
            LOGICAL, INTENT(in) :: high
            TYPE(MPI_Comm), INTENT(out) :: newintracomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Intercomm_merge_f08
    END INTERFACE PMPI_Intercomm_merge
    
    INTERFACE PMPIX_Comm_test_threadcomm
        SUBROUTINE PMPIXR_Comm_test_threadcomm_f08(comm, flag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            LOGICAL, INTENT(out) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIXR_Comm_test_threadcomm_f08
    END INTERFACE PMPIX_Comm_test_threadcomm
    
    INTERFACE PMPIX_Comm_revoke
        SUBROUTINE PMPIXR_Comm_revoke_f08(comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIXR_Comm_revoke_f08
    END INTERFACE PMPIX_Comm_revoke
    
    INTERFACE PMPIX_Comm_shrink
        SUBROUTINE PMPIXR_Comm_shrink_f08(comm, newcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Comm), INTENT(out) :: newcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIXR_Comm_shrink_f08
    END INTERFACE PMPIX_Comm_shrink
    
    INTERFACE PMPIX_Comm_failure_ack
        SUBROUTINE PMPIXR_Comm_failure_ack_f08(comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIXR_Comm_failure_ack_f08
    END INTERFACE PMPIX_Comm_failure_ack
    
    INTERFACE PMPIX_Comm_failure_get_acked
        SUBROUTINE PMPIXR_Comm_failure_get_acked_f08(comm, failedgrp, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Group), INTENT(out) :: failedgrp
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIXR_Comm_failure_get_acked_f08
    END INTERFACE PMPIX_Comm_failure_get_acked
    
    INTERFACE PMPIX_Comm_agree
        SUBROUTINE PMPIXR_Comm_agree_f08(comm, flag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            LOGICAL, INTENT(out) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIXR_Comm_agree_f08
    END INTERFACE PMPIX_Comm_agree
    
    INTERFACE PMPIX_Comm_get_failed
        SUBROUTINE PMPIXR_Comm_get_failed_f08(comm, failedgrp, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Group), INTENT(out) :: failedgrp
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIXR_Comm_get_failed_f08
    END INTERFACE PMPIX_Comm_get_failed
    
    INTERFACE PMPI_Get_address
        SUBROUTINE PMPIR_Get_address_f08ts(location, address, ierror)
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: location
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: address
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Get_address_f08ts
    END INTERFACE PMPI_Get_address
    
    INTERFACE PMPI_Get_count
        SUBROUTINE PMPIR_Get_count_f08(status, datatype, count, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Status, MPI_Datatype
            IMPLICIT NONE
            TYPE(MPI_Status), INTENT(in), TARGET :: status
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(out) :: count
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Get_count_f08
        
        SUBROUTINE PMPIR_Get_count_c_f08(status, datatype, count, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Status, MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_Status), INTENT(in), TARGET :: status
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: count
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Get_count_c_f08
    END INTERFACE PMPI_Get_count
    
    INTERFACE PMPI_Get_elements
        SUBROUTINE PMPIR_Get_elements_f08(status, datatype, count, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Status, MPI_Datatype
            IMPLICIT NONE
            TYPE(MPI_Status), INTENT(in), TARGET :: status
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(out) :: count
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Get_elements_f08
        
        SUBROUTINE PMPIR_Get_elements_c_f08(status, datatype, count, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Status, MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_Status), INTENT(in), TARGET :: status
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: count
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Get_elements_c_f08
    END INTERFACE PMPI_Get_elements
    
    INTERFACE PMPI_Get_elements_x
        SUBROUTINE PMPIR_Get_elements_x_f08(status, datatype, count, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Status, MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_Status), INTENT(in), TARGET :: status
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: count
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Get_elements_x_f08
    END INTERFACE PMPI_Get_elements_x
    
    INTERFACE PMPI_Pack
        SUBROUTINE PMPIR_Pack_f08ts(inbuf, incount, datatype, outbuf, outsize, position, comm, ierror)
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
        END SUBROUTINE PMPIR_Pack_f08ts
        
        SUBROUTINE PMPIR_Pack_c_f08ts(inbuf, incount, datatype, outbuf, outsize, position, comm, ierror)
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
        END SUBROUTINE PMPIR_Pack_c_f08ts
    END INTERFACE PMPI_Pack
    
    INTERFACE PMPI_Pack_external
        SUBROUTINE PMPIR_Pack_external_f08ts(datarep, inbuf, incount, datatype, outbuf, outsize, position, &
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
        END SUBROUTINE PMPIR_Pack_external_f08ts
        
        SUBROUTINE PMPIR_Pack_external_c_f08ts(datarep, inbuf, incount, datatype, outbuf, outsize, position, &
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
        END SUBROUTINE PMPIR_Pack_external_c_f08ts
    END INTERFACE PMPI_Pack_external
    
    INTERFACE PMPI_Pack_external_size
        SUBROUTINE PMPIR_Pack_external_size_f08(datarep, incount, datatype, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            CHARACTER(len=*), INTENT(in) :: datarep
            INTEGER, INTENT(in) :: incount
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Pack_external_size_f08
        
        SUBROUTINE PMPIR_Pack_external_size_c_f08(datarep, incount, datatype, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            CHARACTER(len=*), INTENT(in) :: datarep
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: incount
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Pack_external_size_c_f08
    END INTERFACE PMPI_Pack_external_size
    
    INTERFACE PMPI_Pack_size
        SUBROUTINE PMPIR_Pack_size_f08(incount, datatype, comm, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            IMPLICIT NONE
            INTEGER, INTENT(in) :: incount
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Pack_size_f08
        
        SUBROUTINE PMPIR_Pack_size_c_f08(incount, datatype, comm, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: incount
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Pack_size_c_f08
    END INTERFACE PMPI_Pack_size
    
    INTERFACE PMPI_Status_set_elements
        SUBROUTINE PMPIR_Status_set_elements_f08(status, datatype, count, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Status, MPI_Datatype
            IMPLICIT NONE
            TYPE(MPI_Status), INTENT(inout), TARGET :: status
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: count
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Status_set_elements_f08
        
        SUBROUTINE PMPIR_Status_set_elements_c_f08(status, datatype, count, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Status, MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_Status), INTENT(inout), TARGET :: status
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Status_set_elements_c_f08
    END INTERFACE PMPI_Status_set_elements
    
    INTERFACE PMPI_Status_set_elements_x
        SUBROUTINE PMPIR_Status_set_elements_x_f08(status, datatype, count, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Status, MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_Status), INTENT(inout), TARGET :: status
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Status_set_elements_x_f08
    END INTERFACE PMPI_Status_set_elements_x
    
    INTERFACE PMPI_Type_commit
        SUBROUTINE PMPIR_Type_commit_f08(datatype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(inout) :: datatype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Type_commit_f08
    END INTERFACE PMPI_Type_commit
    
    INTERFACE PMPI_Type_contiguous
        SUBROUTINE PMPIR_Type_contiguous_f08(count, oldtype, newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: oldtype
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Type_contiguous_f08
        
        SUBROUTINE PMPIR_Type_contiguous_c_f08(count, oldtype, newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: oldtype
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Type_contiguous_c_f08
    END INTERFACE PMPI_Type_contiguous
    
    INTERFACE PMPI_Type_create_darray
        SUBROUTINE PMPIR_Type_create_darray_f08(size, rank, ndims, array_of_gsizes, array_of_distribs, &
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
        END SUBROUTINE PMPIR_Type_create_darray_f08
        
        SUBROUTINE PMPIR_Type_create_darray_c_f08(size, rank, ndims, array_of_gsizes, array_of_distribs, &
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
        END SUBROUTINE PMPIR_Type_create_darray_c_f08
    END INTERFACE PMPI_Type_create_darray
    
    INTERFACE PMPI_Type_create_f90_complex
        SUBROUTINE PMPIR_Type_create_f90_complex_f08(p, r, newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            INTEGER, INTENT(in) :: p
            INTEGER, INTENT(in) :: r
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Type_create_f90_complex_f08
    END INTERFACE PMPI_Type_create_f90_complex
    
    INTERFACE PMPI_Type_create_f90_integer
        SUBROUTINE PMPIR_Type_create_f90_integer_f08(r, newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            INTEGER, INTENT(in) :: r
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Type_create_f90_integer_f08
    END INTERFACE PMPI_Type_create_f90_integer
    
    INTERFACE PMPI_Type_create_f90_real
        SUBROUTINE PMPIR_Type_create_f90_real_f08(p, r, newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            INTEGER, INTENT(in) :: p
            INTEGER, INTENT(in) :: r
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Type_create_f90_real_f08
    END INTERFACE PMPI_Type_create_f90_real
    
    INTERFACE PMPI_Type_create_hindexed
        SUBROUTINE PMPIR_Type_create_hindexed_f08(count, array_of_blocklengths, array_of_displacements, &
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
        END SUBROUTINE PMPIR_Type_create_hindexed_f08
        
        SUBROUTINE PMPIR_Type_create_hindexed_c_f08(count, array_of_blocklengths, array_of_displacements, &
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
        END SUBROUTINE PMPIR_Type_create_hindexed_c_f08
    END INTERFACE PMPI_Type_create_hindexed
    
    INTERFACE PMPI_Type_create_hindexed_block
        SUBROUTINE PMPIR_Type_create_hindexed_block_f08(count, blocklength, array_of_displacements, oldtype, &
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
        END SUBROUTINE PMPIR_Type_create_hindexed_block_f08
        
        SUBROUTINE PMPIR_Type_create_hindexed_block_c_f08(count, blocklength, array_of_displacements, oldtype, &
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
        END SUBROUTINE PMPIR_Type_create_hindexed_block_c_f08
    END INTERFACE PMPI_Type_create_hindexed_block
    
    INTERFACE PMPI_Type_create_hvector
        SUBROUTINE PMPIR_Type_create_hvector_f08(count, blocklength, stride, oldtype, newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            INTEGER, INTENT(in) :: count
            INTEGER, INTENT(in) :: blocklength
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: stride
            TYPE(MPI_Datatype), INTENT(in) :: oldtype
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Type_create_hvector_f08
        
        SUBROUTINE PMPIR_Type_create_hvector_c_f08(count, blocklength, stride, oldtype, newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: blocklength
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: stride
            TYPE(MPI_Datatype), INTENT(in) :: oldtype
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Type_create_hvector_c_f08
    END INTERFACE PMPI_Type_create_hvector
    
    INTERFACE PMPI_Type_create_indexed_block
        SUBROUTINE PMPIR_Type_create_indexed_block_f08(count, blocklength, array_of_displacements, oldtype, &
                                                     newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            INTEGER, INTENT(in) :: count
            INTEGER, INTENT(in) :: blocklength
            INTEGER, INTENT(in) :: array_of_displacements(count)
            TYPE(MPI_Datatype), INTENT(in) :: oldtype
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Type_create_indexed_block_f08
        
        SUBROUTINE PMPIR_Type_create_indexed_block_c_f08(count, blocklength, array_of_displacements, oldtype, &
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
        END SUBROUTINE PMPIR_Type_create_indexed_block_c_f08
    END INTERFACE PMPI_Type_create_indexed_block
    
    INTERFACE PMPI_Type_create_resized
        SUBROUTINE PMPIR_Type_create_resized_f08(oldtype, lb, extent, newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: oldtype
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: lb
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: extent
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Type_create_resized_f08
    END INTERFACE PMPI_Type_create_resized
    
    INTERFACE PMPI_Type_create_struct
        SUBROUTINE PMPIR_Type_create_struct_f08(count, array_of_blocklengths, array_of_displacements, &
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
        END SUBROUTINE PMPIR_Type_create_struct_f08
        
        SUBROUTINE PMPIR_Type_create_struct_c_f08(count, array_of_blocklengths, array_of_displacements, &
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
        END SUBROUTINE PMPIR_Type_create_struct_c_f08
    END INTERFACE PMPI_Type_create_struct
    
    INTERFACE PMPI_Type_create_subarray
        SUBROUTINE PMPIR_Type_create_subarray_f08(ndims, array_of_sizes, array_of_subsizes, array_of_starts, &
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
        END SUBROUTINE PMPIR_Type_create_subarray_f08
        
        SUBROUTINE PMPIR_Type_create_subarray_c_f08(ndims, array_of_sizes, array_of_subsizes, array_of_starts, &
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
        END SUBROUTINE PMPIR_Type_create_subarray_c_f08
    END INTERFACE PMPI_Type_create_subarray
    
    INTERFACE PMPI_Type_dup
        SUBROUTINE PMPIR_Type_dup_f08(oldtype, newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: oldtype
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Type_dup_f08
    END INTERFACE PMPI_Type_dup
    
    INTERFACE PMPI_Type_free
        SUBROUTINE PMPIR_Type_free_f08(datatype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(inout) :: datatype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Type_free_f08
    END INTERFACE PMPI_Type_free
    
    INTERFACE PMPI_Type_get_contents
        SUBROUTINE PMPIR_Type_get_contents_f08(datatype, max_integers, max_addresses, max_datatypes, &
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
        END SUBROUTINE PMPIR_Type_get_contents_f08
        
        SUBROUTINE PMPIR_Type_get_contents_c_f08(datatype, max_integers, max_addresses, max_large_counts, &
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
        END SUBROUTINE PMPIR_Type_get_contents_c_f08
    END INTERFACE PMPI_Type_get_contents
    
    INTERFACE PMPI_Type_get_envelope
        SUBROUTINE PMPIR_Type_get_envelope_f08(datatype, num_integers, num_addresses, num_datatypes, combiner, &
                                             ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(out) :: num_integers
            INTEGER, INTENT(out) :: num_addresses
            INTEGER, INTENT(out) :: num_datatypes
            INTEGER, INTENT(out) :: combiner
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Type_get_envelope_f08
        
        SUBROUTINE PMPIR_Type_get_envelope_c_f08(datatype, num_integers, num_addresses, num_large_counts, &
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
        END SUBROUTINE PMPIR_Type_get_envelope_c_f08
    END INTERFACE PMPI_Type_get_envelope
    
    INTERFACE PMPI_Type_get_extent
        SUBROUTINE PMPIR_Type_get_extent_f08(datatype, lb, extent, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: lb
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: extent
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Type_get_extent_f08
    END INTERFACE PMPI_Type_get_extent
    
    INTERFACE PMPI_Type_get_extent_x
        SUBROUTINE PMPIR_Type_get_extent_x_f08(datatype, lb, extent, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: lb
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: extent
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Type_get_extent_x_f08
    END INTERFACE PMPI_Type_get_extent_x
    
    INTERFACE PMPI_Type_get_name
        SUBROUTINE PMPIR_Type_get_name_f08(datatype, type_name, resultlen, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_MAX_OBJECT_NAME
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            CHARACTER(len=MPI_MAX_OBJECT_NAME), INTENT(out) :: type_name
            INTEGER, INTENT(out) :: resultlen
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Type_get_name_f08
    END INTERFACE PMPI_Type_get_name
    
    INTERFACE PMPI_Type_get_true_extent
        SUBROUTINE PMPIR_Type_get_true_extent_f08(datatype, true_lb, true_extent, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: true_lb
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: true_extent
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Type_get_true_extent_f08
    END INTERFACE PMPI_Type_get_true_extent
    
    INTERFACE PMPI_Type_get_true_extent_x
        SUBROUTINE PMPIR_Type_get_true_extent_x_f08(datatype, true_lb, true_extent, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: true_lb
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: true_extent
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Type_get_true_extent_x_f08
    END INTERFACE PMPI_Type_get_true_extent_x
    
    INTERFACE PMPI_Type_get_value_index
        SUBROUTINE PMPIR_Type_get_value_index_f08(value_type, index_type, pair_type, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: value_type
            TYPE(MPI_Datatype), INTENT(in) :: index_type
            TYPE(MPI_Datatype), INTENT(out) :: pair_type
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Type_get_value_index_f08
    END INTERFACE PMPI_Type_get_value_index
    
    INTERFACE PMPI_Type_indexed
        SUBROUTINE PMPIR_Type_indexed_f08(count, array_of_blocklengths, array_of_displacements, oldtype, &
                                        newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            INTEGER, INTENT(in) :: count
            INTEGER, INTENT(in) :: array_of_blocklengths(count)
            INTEGER, INTENT(in) :: array_of_displacements(count)
            TYPE(MPI_Datatype), INTENT(in) :: oldtype
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Type_indexed_f08
        
        SUBROUTINE PMPIR_Type_indexed_c_f08(count, array_of_blocklengths, array_of_displacements, oldtype, &
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
        END SUBROUTINE PMPIR_Type_indexed_c_f08
    END INTERFACE PMPI_Type_indexed
    
    INTERFACE PMPI_Type_match_size
        SUBROUTINE PMPIR_Type_match_size_f08(typeclass, size, datatype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            INTEGER, INTENT(in) :: typeclass
            INTEGER, INTENT(in) :: size
            TYPE(MPI_Datatype), INTENT(out) :: datatype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Type_match_size_f08
    END INTERFACE PMPI_Type_match_size
    
    INTERFACE PMPI_Type_set_name
        SUBROUTINE PMPIR_Type_set_name_f08(datatype, type_name, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            CHARACTER(len=*), INTENT(in) :: type_name
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Type_set_name_f08
    END INTERFACE PMPI_Type_set_name
    
    INTERFACE PMPI_Type_size
        SUBROUTINE PMPIR_Type_size_f08(datatype, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Type_size_f08
        
        SUBROUTINE PMPIR_Type_size_c_f08(datatype, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Type_size_c_f08
    END INTERFACE PMPI_Type_size
    
    INTERFACE PMPI_Type_size_x
        SUBROUTINE PMPIR_Type_size_x_f08(datatype, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Type_size_x_f08
    END INTERFACE PMPI_Type_size_x
    
    INTERFACE PMPI_Type_vector
        SUBROUTINE PMPIR_Type_vector_f08(count, blocklength, stride, oldtype, newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            IMPLICIT NONE
            INTEGER, INTENT(in) :: count
            INTEGER, INTENT(in) :: blocklength
            INTEGER, INTENT(in) :: stride
            TYPE(MPI_Datatype), INTENT(in) :: oldtype
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Type_vector_f08
        
        SUBROUTINE PMPIR_Type_vector_c_f08(count, blocklength, stride, oldtype, newtype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: blocklength
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: stride
            TYPE(MPI_Datatype), INTENT(in) :: oldtype
            TYPE(MPI_Datatype), INTENT(out) :: newtype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Type_vector_c_f08
    END INTERFACE PMPI_Type_vector
    
    INTERFACE PMPI_Unpack
        SUBROUTINE PMPIR_Unpack_f08ts(inbuf, insize, position, outbuf, outcount, datatype, comm, ierror)
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
        END SUBROUTINE PMPIR_Unpack_f08ts
        
        SUBROUTINE PMPIR_Unpack_c_f08ts(inbuf, insize, position, outbuf, outcount, datatype, comm, ierror)
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
        END SUBROUTINE PMPIR_Unpack_c_f08ts
    END INTERFACE PMPI_Unpack
    
    INTERFACE PMPI_Unpack_external
        SUBROUTINE PMPIR_Unpack_external_f08ts(datarep, inbuf, insize, position, outbuf, outcount, datatype, &
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
        END SUBROUTINE PMPIR_Unpack_external_f08ts
        
        SUBROUTINE PMPIR_Unpack_external_c_f08ts(datarep, inbuf, insize, position, outbuf, outcount, datatype, &
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
        END SUBROUTINE PMPIR_Unpack_external_c_f08ts
    END INTERFACE PMPI_Unpack_external
    
    INTERFACE PMPI_Add_error_class
        SUBROUTINE PMPIR_Add_error_class_f08(errorclass, ierror)
            IMPLICIT NONE
            INTEGER, INTENT(out) :: errorclass
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Add_error_class_f08
    END INTERFACE PMPI_Add_error_class
    
    INTERFACE PMPI_Add_error_code
        SUBROUTINE PMPIR_Add_error_code_f08(errorclass, errorcode, ierror)
            IMPLICIT NONE
            INTEGER, INTENT(in) :: errorclass
            INTEGER, INTENT(out) :: errorcode
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Add_error_code_f08
    END INTERFACE PMPI_Add_error_code
    
    INTERFACE PMPI_Add_error_string
        SUBROUTINE PMPIR_Add_error_string_f08(errorcode, string, ierror)
            IMPLICIT NONE
            INTEGER, INTENT(in) :: errorcode
            CHARACTER(len=*), INTENT(in) :: string
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Add_error_string_f08
    END INTERFACE PMPI_Add_error_string
    
    INTERFACE PMPI_Comm_call_errhandler
        SUBROUTINE PMPIR_Comm_call_errhandler_f08(comm, errorcode, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: errorcode
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_call_errhandler_f08
    END INTERFACE PMPI_Comm_call_errhandler
    
    INTERFACE PMPI_Comm_create_errhandler
        SUBROUTINE PMPIR_Comm_create_errhandler_f08(comm_errhandler_fn, errhandler, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Errhandler
            USE :: mpi_f08_callbacks, ONLY : MPI_Comm_errhandler_function
            IMPLICIT NONE
            PROCEDURE(MPI_Comm_errhandler_function) :: comm_errhandler_fn
            TYPE(MPI_Errhandler), INTENT(out) :: errhandler
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_create_errhandler_f08
    END INTERFACE PMPI_Comm_create_errhandler
    
    INTERFACE PMPI_Comm_get_errhandler
        SUBROUTINE PMPIR_Comm_get_errhandler_f08(comm, errhandler, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Errhandler
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Errhandler), INTENT(out) :: errhandler
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_get_errhandler_f08
    END INTERFACE PMPI_Comm_get_errhandler
    
    INTERFACE PMPI_Comm_set_errhandler
        SUBROUTINE PMPIR_Comm_set_errhandler_f08(comm, errhandler, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Errhandler
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Errhandler), INTENT(in) :: errhandler
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_set_errhandler_f08
    END INTERFACE PMPI_Comm_set_errhandler
    
    INTERFACE PMPI_Errhandler_free
        SUBROUTINE PMPIR_Errhandler_free_f08(errhandler, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Errhandler
            IMPLICIT NONE
            TYPE(MPI_Errhandler), INTENT(inout) :: errhandler
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Errhandler_free_f08
    END INTERFACE PMPI_Errhandler_free
    
    INTERFACE PMPI_Error_class
        SUBROUTINE PMPIR_Error_class_f08(errorcode, errorclass, ierror)
            IMPLICIT NONE
            INTEGER, INTENT(in) :: errorcode
            INTEGER, INTENT(out) :: errorclass
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Error_class_f08
    END INTERFACE PMPI_Error_class
    
    INTERFACE PMPI_Error_string
        SUBROUTINE PMPIR_Error_string_f08(errorcode, string, resultlen, ierror)
            USE :: mpi_f08_compile_constants, ONLY : MPI_MAX_ERROR_STRING
            IMPLICIT NONE
            INTEGER, INTENT(in) :: errorcode
            CHARACTER(len=MPI_MAX_ERROR_STRING), INTENT(out) :: string
            INTEGER, INTENT(out) :: resultlen
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Error_string_f08
    END INTERFACE PMPI_Error_string
    
    INTERFACE PMPI_File_call_errhandler
        SUBROUTINE PMPIR_File_call_errhandler_f08(fh, errorcode, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER, INTENT(in) :: errorcode
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_call_errhandler_f08
    END INTERFACE PMPI_File_call_errhandler
    
    INTERFACE PMPI_File_create_errhandler
        SUBROUTINE PMPIR_File_create_errhandler_f08(file_errhandler_fn, errhandler, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Errhandler
            USE :: mpi_f08_callbacks, ONLY : MPI_File_errhandler_function
            IMPLICIT NONE
            PROCEDURE(MPI_File_errhandler_function) :: file_errhandler_fn
            TYPE(MPI_Errhandler), INTENT(out) :: errhandler
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_create_errhandler_f08
    END INTERFACE PMPI_File_create_errhandler
    
    INTERFACE PMPI_File_get_errhandler
        SUBROUTINE PMPIR_File_get_errhandler_f08(file, errhandler, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Errhandler
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: file
            TYPE(MPI_Errhandler), INTENT(out) :: errhandler
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_get_errhandler_f08
    END INTERFACE PMPI_File_get_errhandler
    
    INTERFACE PMPI_File_set_errhandler
        SUBROUTINE PMPIR_File_set_errhandler_f08(file, errhandler, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Errhandler
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: file
            TYPE(MPI_Errhandler), INTENT(in) :: errhandler
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_set_errhandler_f08
    END INTERFACE PMPI_File_set_errhandler
    
    INTERFACE PMPI_Remove_error_class
        SUBROUTINE PMPIR_Remove_error_class_f08(errorclass, ierror)
            IMPLICIT NONE
            INTEGER, INTENT(in) :: errorclass
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Remove_error_class_f08
    END INTERFACE PMPI_Remove_error_class
    
    INTERFACE PMPI_Remove_error_code
        SUBROUTINE PMPIR_Remove_error_code_f08(errorcode, ierror)
            IMPLICIT NONE
            INTEGER, INTENT(in) :: errorcode
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Remove_error_code_f08
    END INTERFACE PMPI_Remove_error_code
    
    INTERFACE PMPI_Remove_error_string
        SUBROUTINE PMPIR_Remove_error_string_f08(errorcode, ierror)
            IMPLICIT NONE
            INTEGER, INTENT(in) :: errorcode
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Remove_error_string_f08
    END INTERFACE PMPI_Remove_error_string
    
    INTERFACE PMPI_Session_call_errhandler
        SUBROUTINE PMPIR_Session_call_errhandler_f08(session, errorcode, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Session
            IMPLICIT NONE
            TYPE(MPI_Session), INTENT(in) :: session
            INTEGER, INTENT(in) :: errorcode
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Session_call_errhandler_f08
    END INTERFACE PMPI_Session_call_errhandler
    
    INTERFACE PMPI_Session_create_errhandler
        SUBROUTINE PMPIR_Session_create_errhandler_f08(session_errhandler_fn, errhandler, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Errhandler
            USE :: mpi_f08_callbacks, ONLY : MPI_Session_errhandler_function
            IMPLICIT NONE
            PROCEDURE(MPI_Session_errhandler_function) :: session_errhandler_fn
            TYPE(MPI_Errhandler), INTENT(out) :: errhandler
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Session_create_errhandler_f08
    END INTERFACE PMPI_Session_create_errhandler
    
    INTERFACE PMPI_Session_get_errhandler
        SUBROUTINE PMPIR_Session_get_errhandler_f08(session, errhandler, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Session, MPI_Errhandler
            IMPLICIT NONE
            TYPE(MPI_Session), INTENT(in) :: session
            TYPE(MPI_Errhandler), INTENT(out) :: errhandler
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Session_get_errhandler_f08
    END INTERFACE PMPI_Session_get_errhandler
    
    INTERFACE PMPI_Session_set_errhandler
        SUBROUTINE PMPIR_Session_set_errhandler_f08(session, errhandler, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Session, MPI_Errhandler
            IMPLICIT NONE
            TYPE(MPI_Session), INTENT(in) :: session
            TYPE(MPI_Errhandler), INTENT(in) :: errhandler
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Session_set_errhandler_f08
    END INTERFACE PMPI_Session_set_errhandler
    
    INTERFACE PMPI_Win_call_errhandler
        SUBROUTINE PMPIR_Win_call_errhandler_f08(win, errorcode, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, INTENT(in) :: errorcode
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_call_errhandler_f08
    END INTERFACE PMPI_Win_call_errhandler
    
    INTERFACE PMPI_Win_create_errhandler
        SUBROUTINE PMPIR_Win_create_errhandler_f08(win_errhandler_fn, errhandler, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Errhandler
            USE :: mpi_f08_callbacks, ONLY : MPI_Win_errhandler_function
            IMPLICIT NONE
            PROCEDURE(MPI_Win_errhandler_function) :: win_errhandler_fn
            TYPE(MPI_Errhandler), INTENT(out) :: errhandler
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_create_errhandler_f08
    END INTERFACE PMPI_Win_create_errhandler
    
    INTERFACE PMPI_Win_get_errhandler
        SUBROUTINE PMPIR_Win_get_errhandler_f08(win, errhandler, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win, MPI_Errhandler
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            TYPE(MPI_Errhandler), INTENT(out) :: errhandler
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_get_errhandler_f08
    END INTERFACE PMPI_Win_get_errhandler
    
    INTERFACE PMPI_Win_set_errhandler
        SUBROUTINE PMPIR_Win_set_errhandler_f08(win, errhandler, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win, MPI_Errhandler
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            TYPE(MPI_Errhandler), INTENT(in) :: errhandler
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_set_errhandler_f08
    END INTERFACE PMPI_Win_set_errhandler
    
    INTERFACE PMPI_Group_compare
        SUBROUTINE PMPIR_Group_compare_f08(group1, group2, result, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Group), INTENT(in) :: group1
            TYPE(MPI_Group), INTENT(in) :: group2
            INTEGER, INTENT(out) :: result
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Group_compare_f08
    END INTERFACE PMPI_Group_compare
    
    INTERFACE PMPI_Group_difference
        SUBROUTINE PMPIR_Group_difference_f08(group1, group2, newgroup, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Group), INTENT(in) :: group1
            TYPE(MPI_Group), INTENT(in) :: group2
            TYPE(MPI_Group), INTENT(out) :: newgroup
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Group_difference_f08
    END INTERFACE PMPI_Group_difference
    
    INTERFACE PMPI_Group_excl
        SUBROUTINE PMPIR_Group_excl_f08(group, n, ranks, newgroup, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Group), INTENT(in) :: group
            INTEGER, INTENT(in) :: n
            INTEGER, INTENT(in) :: ranks(n)
            TYPE(MPI_Group), INTENT(out) :: newgroup
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Group_excl_f08
    END INTERFACE PMPI_Group_excl
    
    INTERFACE PMPI_Group_free
        SUBROUTINE PMPIR_Group_free_f08(group, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Group), INTENT(inout) :: group
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Group_free_f08
    END INTERFACE PMPI_Group_free
    
    INTERFACE PMPI_Group_incl
        SUBROUTINE PMPIR_Group_incl_f08(group, n, ranks, newgroup, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Group), INTENT(in) :: group
            INTEGER, INTENT(in) :: n
            INTEGER, INTENT(in) :: ranks(n)
            TYPE(MPI_Group), INTENT(out) :: newgroup
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Group_incl_f08
    END INTERFACE PMPI_Group_incl
    
    INTERFACE PMPI_Group_intersection
        SUBROUTINE PMPIR_Group_intersection_f08(group1, group2, newgroup, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Group), INTENT(in) :: group1
            TYPE(MPI_Group), INTENT(in) :: group2
            TYPE(MPI_Group), INTENT(out) :: newgroup
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Group_intersection_f08
    END INTERFACE PMPI_Group_intersection
    
    INTERFACE PMPI_Group_range_excl
        SUBROUTINE PMPIR_Group_range_excl_f08(group, n, ranges, newgroup, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Group), INTENT(in) :: group
            INTEGER, INTENT(in) :: n
            INTEGER, INTENT(in) :: ranges(n, 3)
            TYPE(MPI_Group), INTENT(out) :: newgroup
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Group_range_excl_f08
    END INTERFACE PMPI_Group_range_excl
    
    INTERFACE PMPI_Group_range_incl
        SUBROUTINE PMPIR_Group_range_incl_f08(group, n, ranges, newgroup, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Group), INTENT(in) :: group
            INTEGER, INTENT(in) :: n
            INTEGER, INTENT(in) :: ranges(n, 3)
            TYPE(MPI_Group), INTENT(out) :: newgroup
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Group_range_incl_f08
    END INTERFACE PMPI_Group_range_incl
    
    INTERFACE PMPI_Group_rank
        SUBROUTINE PMPIR_Group_rank_f08(group, rank, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Group), INTENT(in) :: group
            INTEGER, INTENT(out) :: rank
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Group_rank_f08
    END INTERFACE PMPI_Group_rank
    
    INTERFACE PMPI_Group_size
        SUBROUTINE PMPIR_Group_size_f08(group, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Group), INTENT(in) :: group
            INTEGER, INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Group_size_f08
    END INTERFACE PMPI_Group_size
    
    INTERFACE PMPI_Group_translate_ranks
        SUBROUTINE PMPIR_Group_translate_ranks_f08(group1, n, ranks1, group2, ranks2, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Group), INTENT(in) :: group1
            INTEGER, INTENT(in) :: n
            INTEGER, INTENT(in) :: ranks1(n)
            TYPE(MPI_Group), INTENT(in) :: group2
            INTEGER, INTENT(out) :: ranks2(n)
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Group_translate_ranks_f08
    END INTERFACE PMPI_Group_translate_ranks
    
    INTERFACE PMPI_Group_union
        SUBROUTINE PMPIR_Group_union_f08(group1, group2, newgroup, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Group), INTENT(in) :: group1
            TYPE(MPI_Group), INTENT(in) :: group2
            TYPE(MPI_Group), INTENT(out) :: newgroup
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Group_union_f08
    END INTERFACE PMPI_Group_union
    
    INTERFACE PMPI_Info_create
        SUBROUTINE PMPIR_Info_create_f08(info, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(out) :: info
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Info_create_f08
    END INTERFACE PMPI_Info_create
    
    INTERFACE PMPI_Info_create_env
        SUBROUTINE PMPIR_Info_create_env_f08(info, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(out) :: info
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Info_create_env_f08
    END INTERFACE PMPI_Info_create_env
    
    INTERFACE PMPI_Info_delete
        SUBROUTINE PMPIR_Info_delete_f08(info, key, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(in) :: info
            CHARACTER(len=*), INTENT(in) :: key
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Info_delete_f08
    END INTERFACE PMPI_Info_delete
    
    INTERFACE PMPI_Info_dup
        SUBROUTINE PMPIR_Info_dup_f08(info, newinfo, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(in) :: info
            TYPE(MPI_Info), INTENT(out) :: newinfo
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Info_dup_f08
    END INTERFACE PMPI_Info_dup
    
    INTERFACE PMPI_Info_free
        SUBROUTINE PMPIR_Info_free_f08(info, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(inout) :: info
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Info_free_f08
    END INTERFACE PMPI_Info_free
    
    INTERFACE PMPI_Info_get
        SUBROUTINE PMPIR_Info_get_f08(info, key, valuelen, value, flag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(in) :: info
            CHARACTER(len=*), INTENT(in) :: key
            INTEGER, INTENT(in) :: valuelen
            CHARACTER(len=valuelen), INTENT(out) :: value
            LOGICAL, INTENT(out) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Info_get_f08
    END INTERFACE PMPI_Info_get
    
    INTERFACE PMPI_Info_get_nkeys
        SUBROUTINE PMPIR_Info_get_nkeys_f08(info, nkeys, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(in) :: info
            INTEGER, INTENT(out) :: nkeys
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Info_get_nkeys_f08
    END INTERFACE PMPI_Info_get_nkeys
    
    INTERFACE PMPI_Info_get_nthkey
        SUBROUTINE PMPIR_Info_get_nthkey_f08(info, n, key, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(in) :: info
            INTEGER, INTENT(in) :: n
            CHARACTER(len=*), INTENT(out) :: key
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Info_get_nthkey_f08
    END INTERFACE PMPI_Info_get_nthkey
    
    INTERFACE PMPI_Info_get_string
        SUBROUTINE PMPIR_Info_get_string_f08(info, key, buflen, value, flag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(in) :: info
            CHARACTER(len=*), INTENT(in) :: key
            INTEGER, INTENT(inout) :: buflen
            CHARACTER(len=*), INTENT(out) :: value
            LOGICAL, INTENT(out) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Info_get_string_f08
    END INTERFACE PMPI_Info_get_string
    
    INTERFACE PMPI_Info_get_valuelen
        SUBROUTINE PMPIR_Info_get_valuelen_f08(info, key, valuelen, flag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(in) :: info
            CHARACTER(len=*), INTENT(in) :: key
            INTEGER, INTENT(out) :: valuelen
            LOGICAL, INTENT(out) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Info_get_valuelen_f08
    END INTERFACE PMPI_Info_get_valuelen
    
    INTERFACE PMPI_Info_set
        SUBROUTINE PMPIR_Info_set_f08(info, key, value, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(in) :: info
            CHARACTER(len=*), INTENT(in) :: key
            CHARACTER(len=*), INTENT(in) :: value
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Info_set_f08
    END INTERFACE PMPI_Info_set
    
    INTERFACE PMPIX_Info_set_hex
        SUBROUTINE PMPIXR_Info_set_hex_f08ts(info, key, value, value_size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(in) :: info
            CHARACTER(len=*), INTENT(in) :: key
            TYPE(*), DIMENSION(..), INTENT(in) :: value
            INTEGER, INTENT(in) :: value_size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIXR_Info_set_hex_f08ts
    END INTERFACE PMPIX_Info_set_hex
    
    INTERFACE PMPI_Abort
        SUBROUTINE PMPIR_Abort_f08(comm, errorcode, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: errorcode
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Abort_f08
    END INTERFACE PMPI_Abort
    
    INTERFACE PMPI_Comm_create_from_group
        SUBROUTINE PMPIR_Comm_create_from_group_f08(group, stringtag, info, errhandler, newcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Group, MPI_Info, MPI_Errhandler, MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Group), INTENT(in) :: group
            CHARACTER(len=*), INTENT(in) :: stringtag
            TYPE(MPI_Info), INTENT(in) :: info
            TYPE(MPI_Errhandler), INTENT(in) :: errhandler
            TYPE(MPI_Comm), INTENT(out) :: newcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_create_from_group_f08
    END INTERFACE PMPI_Comm_create_from_group
    
    INTERFACE PMPI_Finalize
        SUBROUTINE PMPIR_Finalize_f08(ierror)
            IMPLICIT NONE
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Finalize_f08
    END INTERFACE PMPI_Finalize
    
    INTERFACE PMPI_Finalized
        SUBROUTINE PMPIR_Finalized_f08(flag, ierror)
            IMPLICIT NONE
            LOGICAL, INTENT(out) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Finalized_f08
    END INTERFACE PMPI_Finalized
    
    INTERFACE PMPI_Group_from_session_pset
        SUBROUTINE PMPIR_Group_from_session_pset_f08(session, pset_name, newgroup, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Session, MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Session), INTENT(in) :: session
            CHARACTER(len=*), INTENT(in) :: pset_name
            TYPE(MPI_Group), INTENT(out) :: newgroup
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Group_from_session_pset_f08
    END INTERFACE PMPI_Group_from_session_pset
    
    INTERFACE PMPI_Init
        SUBROUTINE PMPIR_Init_f08(ierror)
            IMPLICIT NONE
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Init_f08
    END INTERFACE PMPI_Init
    
    INTERFACE PMPI_Init_thread
        SUBROUTINE PMPIR_Init_thread_f08(required, provided, ierror)
            IMPLICIT NONE
            INTEGER, INTENT(in) :: required
            INTEGER, INTENT(out) :: provided
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Init_thread_f08
    END INTERFACE PMPI_Init_thread
    
    INTERFACE PMPI_Initialized
        SUBROUTINE PMPIR_Initialized_f08(flag, ierror)
            IMPLICIT NONE
            LOGICAL, INTENT(out) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Initialized_f08
    END INTERFACE PMPI_Initialized
    
    INTERFACE PMPI_Is_thread_main
        SUBROUTINE PMPIR_Is_thread_main_f08(flag, ierror)
            IMPLICIT NONE
            LOGICAL, INTENT(out) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Is_thread_main_f08
    END INTERFACE PMPI_Is_thread_main
    
    INTERFACE PMPI_Query_thread
        SUBROUTINE PMPIR_Query_thread_f08(provided, ierror)
            IMPLICIT NONE
            INTEGER, INTENT(out) :: provided
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Query_thread_f08
    END INTERFACE PMPI_Query_thread
    
    INTERFACE PMPI_Session_finalize
        SUBROUTINE PMPIR_Session_finalize_f08(session, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Session
            IMPLICIT NONE
            TYPE(MPI_Session), INTENT(inout) :: session
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Session_finalize_f08
    END INTERFACE PMPI_Session_finalize
    
    INTERFACE PMPI_Session_get_info
        SUBROUTINE PMPIR_Session_get_info_f08(session, info_used, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Session, MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Session), INTENT(in) :: session
            TYPE(MPI_Info), INTENT(out) :: info_used
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Session_get_info_f08
    END INTERFACE PMPI_Session_get_info
    
    INTERFACE PMPI_Session_get_nth_pset
        SUBROUTINE PMPIR_Session_get_nth_pset_f08(session, info, n, pset_len, pset_name, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Session, MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Session), INTENT(in) :: session
            TYPE(MPI_Info), INTENT(in) :: info
            INTEGER, INTENT(in) :: n
            INTEGER, INTENT(inout) :: pset_len
            CHARACTER(len=*), INTENT(out) :: pset_name
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Session_get_nth_pset_f08
    END INTERFACE PMPI_Session_get_nth_pset
    
    INTERFACE PMPI_Session_get_num_psets
        SUBROUTINE PMPIR_Session_get_num_psets_f08(session, info, npset_names, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Session, MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Session), INTENT(in) :: session
            TYPE(MPI_Info), INTENT(in) :: info
            INTEGER, INTENT(out) :: npset_names
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Session_get_num_psets_f08
    END INTERFACE PMPI_Session_get_num_psets
    
    INTERFACE PMPI_Session_get_pset_info
        SUBROUTINE PMPIR_Session_get_pset_info_f08(session, pset_name, info, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Session, MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Session), INTENT(in) :: session
            CHARACTER(len=*), INTENT(in) :: pset_name
            TYPE(MPI_Info), INTENT(out) :: info
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Session_get_pset_info_f08
    END INTERFACE PMPI_Session_get_pset_info
    
    INTERFACE PMPI_Session_init
        SUBROUTINE PMPIR_Session_init_f08(info, errhandler, session, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info, MPI_Errhandler, MPI_Session
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(in) :: info
            TYPE(MPI_Errhandler), INTENT(in) :: errhandler
            TYPE(MPI_Session), INTENT(out) :: session
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Session_init_f08
    END INTERFACE PMPI_Session_init
    
    INTERFACE PMPI_Aint_add
        FUNCTION PMPIR_Aint_add_f08(base, disp) result(res)
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: base
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: disp
            INTEGER(KIND=MPI_ADDRESS_KIND) :: res
        END FUNCTION PMPIR_Aint_add_f08
    END INTERFACE PMPI_Aint_add
    
    INTERFACE PMPI_Aint_diff
        FUNCTION PMPIR_Aint_diff_f08(addr1, addr2) result(res)
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: addr1
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: addr2
            INTEGER(KIND=MPI_ADDRESS_KIND) :: res
        END FUNCTION PMPIR_Aint_diff_f08
    END INTERFACE PMPI_Aint_diff
    
    INTERFACE PMPI_Get_library_version
        SUBROUTINE PMPIR_Get_library_version_f08(version, resultlen, ierror)
            USE :: mpi_f08_compile_constants, ONLY : MPI_MAX_LIBRARY_VERSION_STRING
            IMPLICIT NONE
            CHARACTER(len=MPI_MAX_LIBRARY_VERSION_STRING), INTENT(out) :: version
            INTEGER, INTENT(out) :: resultlen
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Get_library_version_f08
    END INTERFACE PMPI_Get_library_version
    
    INTERFACE PMPI_Get_processor_name
        SUBROUTINE PMPIR_Get_processor_name_f08(name, resultlen, ierror)
            USE :: mpi_f08_compile_constants, ONLY : MPI_MAX_PROCESSOR_NAME
            IMPLICIT NONE
            CHARACTER(len=MPI_MAX_PROCESSOR_NAME), INTENT(out) :: name
            INTEGER, INTENT(out) :: resultlen
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Get_processor_name_f08
    END INTERFACE PMPI_Get_processor_name
    
    INTERFACE PMPI_Get_version
        SUBROUTINE PMPIR_Get_version_f08(version, subversion, ierror)
            IMPLICIT NONE
            INTEGER, INTENT(out) :: version
            INTEGER, INTENT(out) :: subversion
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Get_version_f08
    END INTERFACE PMPI_Get_version
    
    INTERFACE PMPI_Pcontrol
        SUBROUTINE PMPIR_Pcontrol_f08(level, ierror)
            IMPLICIT NONE
            INTEGER, INTENT(in) :: level
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Pcontrol_f08
    END INTERFACE PMPI_Pcontrol
    
    INTERFACE PMPIX_GPU_query_support
        SUBROUTINE PMPIXR_GPU_query_support_f08(gpu_type, is_supported, ierror)
            IMPLICIT NONE
            INTEGER, INTENT(in) :: gpu_type
            LOGICAL, INTENT(out) :: is_supported
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIXR_GPU_query_support_f08
    END INTERFACE PMPIX_GPU_query_support
    
    INTERFACE PMPIX_Query_cuda_support
        SUBROUTINE PMPIXR_Query_cuda_support_f08(ierror)
            IMPLICIT NONE
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIXR_Query_cuda_support_f08
    END INTERFACE PMPIX_Query_cuda_support
    
    INTERFACE PMPIX_Query_ze_support
        SUBROUTINE PMPIXR_Query_ze_support_f08(ierror)
            IMPLICIT NONE
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIXR_Query_ze_support_f08
    END INTERFACE PMPIX_Query_ze_support
    
    INTERFACE PMPIX_Query_hip_support
        SUBROUTINE PMPIXR_Query_hip_support_f08(ierror)
            IMPLICIT NONE
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIXR_Query_hip_support_f08
    END INTERFACE PMPIX_Query_hip_support
    
    INTERFACE PMPI_Op_commutative
        SUBROUTINE PMPIR_Op_commutative_f08(op, commute, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Op
            IMPLICIT NONE
            TYPE(MPI_Op), INTENT(in) :: op
            LOGICAL, INTENT(out) :: commute
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Op_commutative_f08
    END INTERFACE PMPI_Op_commutative
    
    INTERFACE PMPI_Op_create
        SUBROUTINE PMPIR_Op_create_f08(user_fn, commute, op, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Op
            USE :: mpi_f08_callbacks, ONLY : MPI_User_function
            IMPLICIT NONE
            PROCEDURE(MPI_User_function) :: user_fn
            LOGICAL, INTENT(in) :: commute
            TYPE(MPI_Op), INTENT(out) :: op
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Op_create_f08
    END INTERFACE PMPI_Op_create
    
    INTERFACE PMPI_Op_create_c
        SUBROUTINE PMPIR_Op_create_c_f08(user_fn, commute, op, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Op
            USE :: mpi_f08_callbacks, ONLY : MPI_User_function_c
            IMPLICIT NONE
            PROCEDURE(MPI_User_function_c) :: user_fn
            LOGICAL, INTENT(in) :: commute
            TYPE(MPI_Op), INTENT(out) :: op
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Op_create_c_f08
    END INTERFACE PMPI_Op_create_c
    
    INTERFACE PMPI_Op_free
        SUBROUTINE PMPIR_Op_free_f08(op, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Op
            IMPLICIT NONE
            TYPE(MPI_Op), INTENT(inout) :: op
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Op_free_f08
    END INTERFACE PMPI_Op_free
    
    INTERFACE PMPI_Parrived
        SUBROUTINE PMPIR_Parrived_f08(request, partition, flag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request
            IMPLICIT NONE
            TYPE(MPI_Request), INTENT(in) :: request
            INTEGER, INTENT(in) :: partition
            LOGICAL, INTENT(out) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Parrived_f08
    END INTERFACE PMPI_Parrived
    
    INTERFACE PMPI_Pready
        SUBROUTINE PMPIR_Pready_f08(partition, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request
            IMPLICIT NONE
            INTEGER, INTENT(in) :: partition
            TYPE(MPI_Request), INTENT(in) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Pready_f08
    END INTERFACE PMPI_Pready
    
    INTERFACE PMPI_Pready_list
        SUBROUTINE PMPIR_Pready_list_f08(length, array_of_partitions, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request
            IMPLICIT NONE
            INTEGER, INTENT(in) :: length
            INTEGER, INTENT(in) :: array_of_partitions(length)
            TYPE(MPI_Request), INTENT(in) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Pready_list_f08
    END INTERFACE PMPI_Pready_list
    
    INTERFACE PMPI_Pready_range
        SUBROUTINE PMPIR_Pready_range_f08(partition_low, partition_high, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request
            IMPLICIT NONE
            INTEGER, INTENT(in) :: partition_low
            INTEGER, INTENT(in) :: partition_high
            TYPE(MPI_Request), INTENT(in) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Pready_range_f08
    END INTERFACE PMPI_Pready_range
    
    INTERFACE PMPI_Precv_init
        SUBROUTINE PMPIR_Precv_init_f08ts(buf, partitions, count, datatype, dest, tag, comm, info, request, &
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
        END SUBROUTINE PMPIR_Precv_init_f08ts
    END INTERFACE PMPI_Precv_init
    
    INTERFACE PMPI_Psend_init
        SUBROUTINE PMPIR_Psend_init_f08ts(buf, partitions, count, datatype, dest, tag, comm, info, request, &
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
        END SUBROUTINE PMPIR_Psend_init_f08ts
    END INTERFACE PMPI_Psend_init
    
    INTERFACE PMPI_Bsend
        SUBROUTINE PMPIR_Bsend_f08ts(buf, count, datatype, dest, tag, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Bsend_f08ts
        
        SUBROUTINE PMPIR_Bsend_c_f08ts(buf, count, datatype, dest, tag, comm, ierror)
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
        END SUBROUTINE PMPIR_Bsend_c_f08ts
    END INTERFACE PMPI_Bsend
    
    INTERFACE PMPI_Bsend_init
        SUBROUTINE PMPIR_Bsend_init_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
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
        END SUBROUTINE PMPIR_Bsend_init_f08ts
        
        SUBROUTINE PMPIR_Bsend_init_c_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
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
        END SUBROUTINE PMPIR_Bsend_init_c_f08ts
    END INTERFACE PMPI_Bsend_init
    
    INTERFACE PMPI_Buffer_attach
        SUBROUTINE PMPIR_Buffer_attach_f08ts(buffer, size, ierror)
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buffer
            INTEGER, INTENT(in) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Buffer_attach_f08ts
        
        SUBROUTINE PMPIR_Buffer_attach_c_f08ts(buffer, size, ierror)
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buffer
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Buffer_attach_c_f08ts
    END INTERFACE PMPI_Buffer_attach
    
    INTERFACE PMPI_Buffer_detach
        SUBROUTINE PMPIR_Buffer_detach_f08(buffer_addr, size, ierror)
            USE, intrinsic :: iso_c_binding, ONLY : C_PTR
            IMPLICIT NONE
            TYPE(C_PTR), INTENT(out) :: buffer_addr
            INTEGER, INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Buffer_detach_f08
        
        SUBROUTINE PMPIR_Buffer_detach_c_f08(buffer_addr, size, ierror)
            USE, intrinsic :: iso_c_binding, ONLY : C_PTR
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(C_PTR), INTENT(out) :: buffer_addr
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Buffer_detach_c_f08
    END INTERFACE PMPI_Buffer_detach
    
    INTERFACE PMPI_Buffer_flush
        SUBROUTINE PMPIR_Buffer_flush_f08(ierror)
            IMPLICIT NONE
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Buffer_flush_f08
    END INTERFACE PMPI_Buffer_flush
    
    INTERFACE PMPI_Buffer_iflush
        SUBROUTINE PMPIR_Buffer_iflush_f08(request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request
            IMPLICIT NONE
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Buffer_iflush_f08
    END INTERFACE PMPI_Buffer_iflush
    
    INTERFACE PMPI_Comm_attach_buffer
        SUBROUTINE PMPIR_Comm_attach_buffer_f08ts(comm, buffer, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buffer
            INTEGER, INTENT(in) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_attach_buffer_f08ts
        
        SUBROUTINE PMPIR_Comm_attach_buffer_c_f08ts(comm, buffer, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buffer
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_attach_buffer_c_f08ts
    END INTERFACE PMPI_Comm_attach_buffer
    
    INTERFACE PMPI_Comm_detach_buffer
        SUBROUTINE PMPIR_Comm_detach_buffer_f08(comm, buffer_addr, size, ierror)
            USE, intrinsic :: iso_c_binding, ONLY : C_PTR
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(C_PTR), INTENT(out) :: buffer_addr
            INTEGER, INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_detach_buffer_f08
        
        SUBROUTINE PMPIR_Comm_detach_buffer_c_f08(comm, buffer_addr, size, ierror)
            USE, intrinsic :: iso_c_binding, ONLY : C_PTR
            USE :: mpi_f08_types, ONLY : MPI_Comm
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(C_PTR), INTENT(out) :: buffer_addr
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_detach_buffer_c_f08
    END INTERFACE PMPI_Comm_detach_buffer
    
    INTERFACE PMPI_Comm_flush_buffer
        SUBROUTINE PMPIR_Comm_flush_buffer_f08(comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_flush_buffer_f08
    END INTERFACE PMPI_Comm_flush_buffer
    
    INTERFACE PMPI_Comm_iflush_buffer
        SUBROUTINE PMPIR_Comm_iflush_buffer_f08(comm, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Request
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_iflush_buffer_f08
    END INTERFACE PMPI_Comm_iflush_buffer
    
    INTERFACE PMPI_Ibsend
        SUBROUTINE PMPIR_Ibsend_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
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
        END SUBROUTINE PMPIR_Ibsend_f08ts
        
        SUBROUTINE PMPIR_Ibsend_c_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
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
        END SUBROUTINE PMPIR_Ibsend_c_f08ts
    END INTERFACE PMPI_Ibsend
    
    INTERFACE PMPI_Improbe
        SUBROUTINE PMPIR_Improbe_f08(source, tag, comm, flag, message, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Message, MPI_Status
            IMPLICIT NONE
            INTEGER, INTENT(in) :: source
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            LOGICAL, INTENT(out) :: flag
            TYPE(MPI_Message), INTENT(out) :: message
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Improbe_f08
    END INTERFACE PMPI_Improbe
    
    INTERFACE PMPI_Imrecv
        SUBROUTINE PMPIR_Imrecv_f08ts(buf, count, datatype, message, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Message, MPI_Request
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Message), INTENT(inout) :: message
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Imrecv_f08ts
        
        SUBROUTINE PMPIR_Imrecv_c_f08ts(buf, count, datatype, message, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Message, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Message), INTENT(inout) :: message
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Imrecv_c_f08ts
    END INTERFACE PMPI_Imrecv
    
    INTERFACE PMPI_Iprobe
        SUBROUTINE PMPIR_Iprobe_f08(source, tag, comm, flag, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Status
            IMPLICIT NONE
            INTEGER, INTENT(in) :: source
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            LOGICAL, INTENT(out) :: flag
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Iprobe_f08
    END INTERFACE PMPI_Iprobe
    
    INTERFACE PMPI_Irecv
        SUBROUTINE PMPIR_Irecv_f08ts(buf, count, datatype, source, tag, comm, request, ierror)
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
        END SUBROUTINE PMPIR_Irecv_f08ts
        
        SUBROUTINE PMPIR_Irecv_c_f08ts(buf, count, datatype, source, tag, comm, request, ierror)
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
        END SUBROUTINE PMPIR_Irecv_c_f08ts
    END INTERFACE PMPI_Irecv
    
    INTERFACE PMPI_Irsend
        SUBROUTINE PMPIR_Irsend_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
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
        END SUBROUTINE PMPIR_Irsend_f08ts
        
        SUBROUTINE PMPIR_Irsend_c_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
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
        END SUBROUTINE PMPIR_Irsend_c_f08ts
    END INTERFACE PMPI_Irsend
    
    INTERFACE PMPI_Isend
        SUBROUTINE PMPIR_Isend_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
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
        END SUBROUTINE PMPIR_Isend_f08ts
        
        SUBROUTINE PMPIR_Isend_c_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
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
        END SUBROUTINE PMPIR_Isend_c_f08ts
    END INTERFACE PMPI_Isend
    
    INTERFACE PMPI_Isendrecv
        SUBROUTINE PMPIR_Isendrecv_f08ts(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, &
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
        END SUBROUTINE PMPIR_Isendrecv_f08ts
        
        SUBROUTINE PMPIR_Isendrecv_c_f08ts(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, &
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
        END SUBROUTINE PMPIR_Isendrecv_c_f08ts
    END INTERFACE PMPI_Isendrecv
    
    INTERFACE PMPI_Isendrecv_replace
        SUBROUTINE PMPIR_Isendrecv_replace_f08ts(buf, count, datatype, dest, sendtag, source, recvtag, comm, &
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
        END SUBROUTINE PMPIR_Isendrecv_replace_f08ts
        
        SUBROUTINE PMPIR_Isendrecv_replace_c_f08ts(buf, count, datatype, dest, sendtag, source, recvtag, comm, &
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
        END SUBROUTINE PMPIR_Isendrecv_replace_c_f08ts
    END INTERFACE PMPI_Isendrecv_replace
    
    INTERFACE PMPI_Issend
        SUBROUTINE PMPIR_Issend_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
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
        END SUBROUTINE PMPIR_Issend_f08ts
        
        SUBROUTINE PMPIR_Issend_c_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
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
        END SUBROUTINE PMPIR_Issend_c_f08ts
    END INTERFACE PMPI_Issend
    
    INTERFACE PMPI_Mprobe
        SUBROUTINE PMPIR_Mprobe_f08(source, tag, comm, message, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Message, MPI_Status
            IMPLICIT NONE
            INTEGER, INTENT(in) :: source
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Message), INTENT(out) :: message
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Mprobe_f08
    END INTERFACE PMPI_Mprobe
    
    INTERFACE PMPI_Mrecv
        SUBROUTINE PMPIR_Mrecv_f08ts(buf, count, datatype, message, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Message, MPI_Status
            IMPLICIT NONE
            TYPE(*), DIMENSION(..) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Message), INTENT(inout) :: message
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Mrecv_f08ts
        
        SUBROUTINE PMPIR_Mrecv_c_f08ts(buf, count, datatype, message, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Message, MPI_Status
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(*), DIMENSION(..) :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Message), INTENT(inout) :: message
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Mrecv_c_f08ts
    END INTERFACE PMPI_Mrecv
    
    INTERFACE PMPI_Probe
        SUBROUTINE PMPIR_Probe_f08(source, tag, comm, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Status
            IMPLICIT NONE
            INTEGER, INTENT(in) :: source
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Probe_f08
    END INTERFACE PMPI_Probe
    
    INTERFACE PMPI_Recv
        SUBROUTINE PMPIR_Recv_f08ts(buf, count, datatype, source, tag, comm, status, ierror)
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
        END SUBROUTINE PMPIR_Recv_f08ts
        
        SUBROUTINE PMPIR_Recv_c_f08ts(buf, count, datatype, source, tag, comm, status, ierror)
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
        END SUBROUTINE PMPIR_Recv_c_f08ts
    END INTERFACE PMPI_Recv
    
    INTERFACE PMPI_Recv_init
        SUBROUTINE PMPIR_Recv_init_f08ts(buf, count, datatype, source, tag, comm, request, ierror)
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
        END SUBROUTINE PMPIR_Recv_init_f08ts
        
        SUBROUTINE PMPIR_Recv_init_c_f08ts(buf, count, datatype, source, tag, comm, request, ierror)
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
        END SUBROUTINE PMPIR_Recv_init_c_f08ts
    END INTERFACE PMPI_Recv_init
    
    INTERFACE PMPI_Rsend
        SUBROUTINE PMPIR_Rsend_f08ts(buf, count, datatype, dest, tag, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Rsend_f08ts
        
        SUBROUTINE PMPIR_Rsend_c_f08ts(buf, count, datatype, dest, tag, comm, ierror)
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
        END SUBROUTINE PMPIR_Rsend_c_f08ts
    END INTERFACE PMPI_Rsend
    
    INTERFACE PMPI_Rsend_init
        SUBROUTINE PMPIR_Rsend_init_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
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
        END SUBROUTINE PMPIR_Rsend_init_f08ts
        
        SUBROUTINE PMPIR_Rsend_init_c_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
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
        END SUBROUTINE PMPIR_Rsend_init_c_f08ts
    END INTERFACE PMPI_Rsend_init
    
    INTERFACE PMPI_Send
        SUBROUTINE PMPIR_Send_f08ts(buf, count, datatype, dest, tag, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Send_f08ts
        
        SUBROUTINE PMPIR_Send_c_f08ts(buf, count, datatype, dest, tag, comm, ierror)
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
        END SUBROUTINE PMPIR_Send_c_f08ts
    END INTERFACE PMPI_Send
    
    INTERFACE PMPI_Send_init
        SUBROUTINE PMPIR_Send_init_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
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
        END SUBROUTINE PMPIR_Send_init_f08ts
        
        SUBROUTINE PMPIR_Send_init_c_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
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
        END SUBROUTINE PMPIR_Send_init_c_f08ts
    END INTERFACE PMPI_Send_init
    
    INTERFACE PMPI_Sendrecv
        SUBROUTINE PMPIR_Sendrecv_f08ts(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, &
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
        END SUBROUTINE PMPIR_Sendrecv_f08ts
        
        SUBROUTINE PMPIR_Sendrecv_c_f08ts(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, &
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
        END SUBROUTINE PMPIR_Sendrecv_c_f08ts
    END INTERFACE PMPI_Sendrecv
    
    INTERFACE PMPI_Sendrecv_replace
        SUBROUTINE PMPIR_Sendrecv_replace_f08ts(buf, count, datatype, dest, sendtag, source, recvtag, comm, &
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
        END SUBROUTINE PMPIR_Sendrecv_replace_f08ts
        
        SUBROUTINE PMPIR_Sendrecv_replace_c_f08ts(buf, count, datatype, dest, sendtag, source, recvtag, comm, &
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
        END SUBROUTINE PMPIR_Sendrecv_replace_c_f08ts
    END INTERFACE PMPI_Sendrecv_replace
    
    INTERFACE PMPI_Session_attach_buffer
        SUBROUTINE PMPIR_Session_attach_buffer_f08ts(session, buffer, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Session
            IMPLICIT NONE
            TYPE(MPI_Session), INTENT(in) :: session
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buffer
            INTEGER, INTENT(in) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Session_attach_buffer_f08ts
        
        SUBROUTINE PMPIR_Session_attach_buffer_c_f08ts(session, buffer, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Session
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_Session), INTENT(in) :: session
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buffer
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Session_attach_buffer_c_f08ts
    END INTERFACE PMPI_Session_attach_buffer
    
    INTERFACE PMPI_Session_detach_buffer
        SUBROUTINE PMPIR_Session_detach_buffer_f08(session, buffer_addr, size, ierror)
            USE, intrinsic :: iso_c_binding, ONLY : C_PTR
            USE :: mpi_f08_types, ONLY : MPI_Session
            IMPLICIT NONE
            TYPE(MPI_Session), INTENT(in) :: session
            TYPE(C_PTR), INTENT(out) :: buffer_addr
            INTEGER, INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Session_detach_buffer_f08
        
        SUBROUTINE PMPIR_Session_detach_buffer_c_f08(session, buffer_addr, size, ierror)
            USE, intrinsic :: iso_c_binding, ONLY : C_PTR
            USE :: mpi_f08_types, ONLY : MPI_Session
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_Session), INTENT(in) :: session
            TYPE(C_PTR), INTENT(out) :: buffer_addr
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Session_detach_buffer_c_f08
    END INTERFACE PMPI_Session_detach_buffer
    
    INTERFACE PMPI_Session_flush_buffer
        SUBROUTINE PMPIR_Session_flush_buffer_f08(session, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Session
            IMPLICIT NONE
            TYPE(MPI_Session), INTENT(in) :: session
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Session_flush_buffer_f08
    END INTERFACE PMPI_Session_flush_buffer
    
    INTERFACE PMPI_Session_iflush_buffer
        SUBROUTINE PMPIR_Session_iflush_buffer_f08(session, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Session, MPI_Request
            IMPLICIT NONE
            TYPE(MPI_Session), INTENT(in) :: session
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Session_iflush_buffer_f08
    END INTERFACE PMPI_Session_iflush_buffer
    
    INTERFACE PMPI_Ssend
        SUBROUTINE PMPIR_Ssend_f08ts(buf, count, datatype, dest, tag, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Ssend_f08ts
        
        SUBROUTINE PMPIR_Ssend_c_f08ts(buf, count, datatype, dest, tag, comm, ierror)
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
        END SUBROUTINE PMPIR_Ssend_c_f08ts
    END INTERFACE PMPI_Ssend
    
    INTERFACE PMPI_Ssend_init
        SUBROUTINE PMPIR_Ssend_init_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
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
        END SUBROUTINE PMPIR_Ssend_init_f08ts
        
        SUBROUTINE PMPIR_Ssend_init_c_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
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
        END SUBROUTINE PMPIR_Ssend_init_c_f08ts
    END INTERFACE PMPI_Ssend_init
    
    INTERFACE PMPI_Cancel
        SUBROUTINE PMPIR_Cancel_f08(request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request
            IMPLICIT NONE
            TYPE(MPI_Request), INTENT(in) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Cancel_f08
    END INTERFACE PMPI_Cancel
    
    INTERFACE PMPI_Grequest_complete
        SUBROUTINE PMPIR_Grequest_complete_f08(request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request
            IMPLICIT NONE
            TYPE(MPI_Request), INTENT(in) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Grequest_complete_f08
    END INTERFACE PMPI_Grequest_complete
    
    INTERFACE PMPI_Grequest_start
        SUBROUTINE PMPIR_Grequest_start_f08(query_fn, free_fn, cancel_fn, extra_state, request, ierror)
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
        END SUBROUTINE PMPIR_Grequest_start_f08
    END INTERFACE PMPI_Grequest_start
    
    INTERFACE PMPI_Request_free
        SUBROUTINE PMPIR_Request_free_f08(request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request
            IMPLICIT NONE
            TYPE(MPI_Request), INTENT(inout) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Request_free_f08
    END INTERFACE PMPI_Request_free
    
    INTERFACE PMPI_Request_get_status
        SUBROUTINE PMPIR_Request_get_status_f08(request, flag, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_Request), INTENT(in) :: request
            LOGICAL, INTENT(out) :: flag
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Request_get_status_f08
    END INTERFACE PMPI_Request_get_status
    
    INTERFACE PMPI_Request_get_status_all
        SUBROUTINE PMPIR_Request_get_status_all_f08(count, array_of_requests, flag, array_of_statuses, &
                                                  ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status
            IMPLICIT NONE
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Request), INTENT(in) :: array_of_requests(count)
            LOGICAL, INTENT(out) :: flag
            TYPE(MPI_Status), INTENT(out), TARGET :: array_of_statuses(*)
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Request_get_status_all_f08
    END INTERFACE PMPI_Request_get_status_all
    
    INTERFACE PMPI_Request_get_status_any
        SUBROUTINE PMPIR_Request_get_status_any_f08(count, array_of_requests, indx, flag, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status
            IMPLICIT NONE
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Request), INTENT(in) :: array_of_requests(count)
            INTEGER, INTENT(out) :: indx
            LOGICAL, INTENT(out) :: flag
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Request_get_status_any_f08
    END INTERFACE PMPI_Request_get_status_any
    
    INTERFACE PMPI_Request_get_status_some
        SUBROUTINE PMPIR_Request_get_status_some_f08(incount, array_of_requests, outcount, array_of_indices, &
                                                   array_of_statuses, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status
            IMPLICIT NONE
            INTEGER, INTENT(in) :: incount
            TYPE(MPI_Request), INTENT(in) :: array_of_requests(incount)
            INTEGER, INTENT(out) :: outcount
            INTEGER, INTENT(out) :: array_of_indices(*)
            TYPE(MPI_Status), INTENT(out), TARGET :: array_of_statuses(*)
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Request_get_status_some_f08
    END INTERFACE PMPI_Request_get_status_some
    
    INTERFACE PMPI_Start
        SUBROUTINE PMPIR_Start_f08(request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request
            IMPLICIT NONE
            TYPE(MPI_Request), INTENT(inout) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Start_f08
    END INTERFACE PMPI_Start
    
    INTERFACE PMPI_Startall
        SUBROUTINE PMPIR_Startall_f08(count, array_of_requests, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request
            IMPLICIT NONE
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Request), INTENT(inout) :: array_of_requests(count)
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Startall_f08
    END INTERFACE PMPI_Startall
    
    INTERFACE PMPI_Status_get_error
        SUBROUTINE PMPIR_Status_get_error_f08(status, error, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Status
            IMPLICIT NONE
            TYPE(MPI_Status), INTENT(in), TARGET :: status
            INTEGER, INTENT(out) :: error
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Status_get_error_f08
    END INTERFACE PMPI_Status_get_error
    
    INTERFACE PMPI_Status_get_source
        SUBROUTINE PMPIR_Status_get_source_f08(status, source, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Status
            IMPLICIT NONE
            TYPE(MPI_Status), INTENT(in), TARGET :: status
            INTEGER, INTENT(out) :: source
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Status_get_source_f08
    END INTERFACE PMPI_Status_get_source
    
    INTERFACE PMPI_Status_get_tag
        SUBROUTINE PMPIR_Status_get_tag_f08(status, tag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Status
            IMPLICIT NONE
            TYPE(MPI_Status), INTENT(in), TARGET :: status
            INTEGER, INTENT(out) :: tag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Status_get_tag_f08
    END INTERFACE PMPI_Status_get_tag
    
    INTERFACE PMPI_Status_set_error
        SUBROUTINE PMPIR_Status_set_error_f08(status, error, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Status
            IMPLICIT NONE
            TYPE(MPI_Status), INTENT(inout), TARGET :: status
            INTEGER, INTENT(in) :: error
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Status_set_error_f08
    END INTERFACE PMPI_Status_set_error
    
    INTERFACE PMPI_Status_set_source
        SUBROUTINE PMPIR_Status_set_source_f08(status, source, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Status
            IMPLICIT NONE
            TYPE(MPI_Status), INTENT(inout), TARGET :: status
            INTEGER, INTENT(in) :: source
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Status_set_source_f08
    END INTERFACE PMPI_Status_set_source
    
    INTERFACE PMPI_Status_set_tag
        SUBROUTINE PMPIR_Status_set_tag_f08(status, tag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Status
            IMPLICIT NONE
            TYPE(MPI_Status), INTENT(inout), TARGET :: status
            INTEGER, INTENT(in) :: tag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Status_set_tag_f08
    END INTERFACE PMPI_Status_set_tag
    
    INTERFACE PMPI_Status_set_cancelled
        SUBROUTINE PMPIR_Status_set_cancelled_f08(status, flag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Status
            IMPLICIT NONE
            TYPE(MPI_Status), INTENT(inout), TARGET :: status
            LOGICAL, INTENT(in) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Status_set_cancelled_f08
    END INTERFACE PMPI_Status_set_cancelled
    
    INTERFACE PMPI_Test
        SUBROUTINE PMPIR_Test_f08(request, flag, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_Request), INTENT(inout) :: request
            LOGICAL, INTENT(out) :: flag
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Test_f08
    END INTERFACE PMPI_Test
    
    INTERFACE PMPI_Test_cancelled
        SUBROUTINE PMPIR_Test_cancelled_f08(status, flag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Status
            IMPLICIT NONE
            TYPE(MPI_Status), INTENT(in), TARGET :: status
            LOGICAL, INTENT(out) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Test_cancelled_f08
    END INTERFACE PMPI_Test_cancelled
    
    INTERFACE PMPI_Testall
        SUBROUTINE PMPIR_Testall_f08(count, array_of_requests, flag, array_of_statuses, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status
            IMPLICIT NONE
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Request), INTENT(inout) :: array_of_requests(count)
            LOGICAL, INTENT(out) :: flag
            TYPE(MPI_Status), INTENT(out), TARGET :: array_of_statuses(*)
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Testall_f08
    END INTERFACE PMPI_Testall
    
    INTERFACE PMPI_Testany
        SUBROUTINE PMPIR_Testany_f08(count, array_of_requests, indx, flag, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status
            IMPLICIT NONE
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Request), INTENT(inout) :: array_of_requests(count)
            INTEGER, INTENT(out) :: indx
            LOGICAL, INTENT(out) :: flag
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Testany_f08
    END INTERFACE PMPI_Testany
    
    INTERFACE PMPI_Testsome
        SUBROUTINE PMPIR_Testsome_f08(incount, array_of_requests, outcount, array_of_indices, &
                                    array_of_statuses, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status
            IMPLICIT NONE
            INTEGER, INTENT(in) :: incount
            TYPE(MPI_Request), INTENT(inout) :: array_of_requests(incount)
            INTEGER, INTENT(out) :: outcount
            INTEGER, INTENT(out) :: array_of_indices(*)
            TYPE(MPI_Status), INTENT(out), TARGET :: array_of_statuses(*)
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Testsome_f08
    END INTERFACE PMPI_Testsome
    
    INTERFACE PMPI_Wait
        SUBROUTINE PMPIR_Wait_f08(request, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_Request), INTENT(inout) :: request
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Wait_f08
    END INTERFACE PMPI_Wait
    
    INTERFACE PMPI_Waitall
        SUBROUTINE PMPIR_Waitall_f08(count, array_of_requests, array_of_statuses, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status
            IMPLICIT NONE
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Request), INTENT(inout) :: array_of_requests(count)
            TYPE(MPI_Status), INTENT(out), TARGET :: array_of_statuses(*)
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Waitall_f08
    END INTERFACE PMPI_Waitall
    
    INTERFACE PMPI_Waitany
        SUBROUTINE PMPIR_Waitany_f08(count, array_of_requests, indx, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status
            IMPLICIT NONE
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Request), INTENT(inout) :: array_of_requests(count)
            INTEGER, INTENT(out) :: indx
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Waitany_f08
    END INTERFACE PMPI_Waitany
    
    INTERFACE PMPI_Waitsome
        SUBROUTINE PMPIR_Waitsome_f08(incount, array_of_requests, outcount, array_of_indices, &
                                    array_of_statuses, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status
            IMPLICIT NONE
            INTEGER, INTENT(in) :: incount
            TYPE(MPI_Request), INTENT(inout) :: array_of_requests(incount)
            INTEGER, INTENT(out) :: outcount
            INTEGER, INTENT(out) :: array_of_indices(*)
            TYPE(MPI_Status), INTENT(out), TARGET :: array_of_statuses(*)
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Waitsome_f08
    END INTERFACE PMPI_Waitsome
    
    INTERFACE PMPIX_Request_is_complete
        FUNCTION PMPIXR_Request_is_complete_f08(request) result(res)
            USE :: mpi_f08_types, ONLY : MPI_Request
            IMPLICIT NONE
            TYPE(MPI_Request), INTENT(in) :: request
            LOGICAL :: res
        END FUNCTION PMPIXR_Request_is_complete_f08
    END INTERFACE PMPIX_Request_is_complete
    
    INTERFACE PMPI_Accumulate
        SUBROUTINE PMPIR_Accumulate_f08ts(origin_addr, origin_count, origin_datatype, target_rank, &
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
        END SUBROUTINE PMPIR_Accumulate_f08ts
        
        SUBROUTINE PMPIR_Accumulate_c_f08ts(origin_addr, origin_count, origin_datatype, target_rank, &
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
        END SUBROUTINE PMPIR_Accumulate_c_f08ts
    END INTERFACE PMPI_Accumulate
    
    INTERFACE PMPI_Alloc_mem
        SUBROUTINE PMPIR_Alloc_mem_f08(size, info, baseptr, ierror)
            USE, intrinsic :: iso_c_binding, ONLY : C_PTR
            USE :: mpi_f08_types, ONLY : MPI_Info
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: size
            TYPE(MPI_Info), INTENT(in) :: info
            TYPE(C_PTR), INTENT(out) :: baseptr
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Alloc_mem_f08
    END INTERFACE PMPI_Alloc_mem
    
    INTERFACE PMPI_Compare_and_swap
        SUBROUTINE PMPIR_Compare_and_swap_f08ts(origin_addr, compare_addr, result_addr, datatype, target_rank, &
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
        END SUBROUTINE PMPIR_Compare_and_swap_f08ts
    END INTERFACE PMPI_Compare_and_swap
    
    INTERFACE PMPI_Fetch_and_op
        SUBROUTINE PMPIR_Fetch_and_op_f08ts(origin_addr, result_addr, datatype, target_rank, target_disp, op, &
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
        END SUBROUTINE PMPIR_Fetch_and_op_f08ts
    END INTERFACE PMPI_Fetch_and_op
    
    INTERFACE PMPI_Free_mem
        SUBROUTINE PMPIR_Free_mem_f08ts(base, ierror)
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: base
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Free_mem_f08ts
    END INTERFACE PMPI_Free_mem
    
    INTERFACE PMPI_Get
        SUBROUTINE PMPIR_Get_f08ts(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
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
        END SUBROUTINE PMPIR_Get_f08ts
        
        SUBROUTINE PMPIR_Get_c_f08ts(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
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
        END SUBROUTINE PMPIR_Get_c_f08ts
    END INTERFACE PMPI_Get
    
    INTERFACE PMPI_Get_accumulate
        SUBROUTINE PMPIR_Get_accumulate_f08ts(origin_addr, origin_count, origin_datatype, result_addr, &
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
        END SUBROUTINE PMPIR_Get_accumulate_f08ts
        
        SUBROUTINE PMPIR_Get_accumulate_c_f08ts(origin_addr, origin_count, origin_datatype, result_addr, &
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
        END SUBROUTINE PMPIR_Get_accumulate_c_f08ts
    END INTERFACE PMPI_Get_accumulate
    
    INTERFACE PMPI_Put
        SUBROUTINE PMPIR_Put_f08ts(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
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
        END SUBROUTINE PMPIR_Put_f08ts
        
        SUBROUTINE PMPIR_Put_c_f08ts(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
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
        END SUBROUTINE PMPIR_Put_c_f08ts
    END INTERFACE PMPI_Put
    
    INTERFACE PMPI_Raccumulate
        SUBROUTINE PMPIR_Raccumulate_f08ts(origin_addr, origin_count, origin_datatype, target_rank, &
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
        END SUBROUTINE PMPIR_Raccumulate_f08ts
        
        SUBROUTINE PMPIR_Raccumulate_c_f08ts(origin_addr, origin_count, origin_datatype, target_rank, &
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
        END SUBROUTINE PMPIR_Raccumulate_c_f08ts
    END INTERFACE PMPI_Raccumulate
    
    INTERFACE PMPI_Rget
        SUBROUTINE PMPIR_Rget_f08ts(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
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
        END SUBROUTINE PMPIR_Rget_f08ts
        
        SUBROUTINE PMPIR_Rget_c_f08ts(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
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
        END SUBROUTINE PMPIR_Rget_c_f08ts
    END INTERFACE PMPI_Rget
    
    INTERFACE PMPI_Rget_accumulate
        SUBROUTINE PMPIR_Rget_accumulate_f08ts(origin_addr, origin_count, origin_datatype, result_addr, &
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
        END SUBROUTINE PMPIR_Rget_accumulate_f08ts
        
        SUBROUTINE PMPIR_Rget_accumulate_c_f08ts(origin_addr, origin_count, origin_datatype, result_addr, &
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
        END SUBROUTINE PMPIR_Rget_accumulate_c_f08ts
    END INTERFACE PMPI_Rget_accumulate
    
    INTERFACE PMPI_Rput
        SUBROUTINE PMPIR_Rput_f08ts(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
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
        END SUBROUTINE PMPIR_Rput_f08ts
        
        SUBROUTINE PMPIR_Rput_c_f08ts(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
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
        END SUBROUTINE PMPIR_Rput_c_f08ts
    END INTERFACE PMPI_Rput
    
    INTERFACE PMPI_Win_allocate
        SUBROUTINE PMPIR_Win_allocate_f08(size, disp_unit, info, comm, baseptr, win, ierror)
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
        END SUBROUTINE PMPIR_Win_allocate_f08
        
        SUBROUTINE PMPIR_Win_allocate_c_f08(size, disp_unit, info, comm, baseptr, win, ierror)
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
        END SUBROUTINE PMPIR_Win_allocate_c_f08
    END INTERFACE PMPI_Win_allocate
    
    INTERFACE PMPI_Win_allocate_shared
        SUBROUTINE PMPIR_Win_allocate_shared_f08(size, disp_unit, info, comm, baseptr, win, ierror)
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
        END SUBROUTINE PMPIR_Win_allocate_shared_f08
        
        SUBROUTINE PMPIR_Win_allocate_shared_c_f08(size, disp_unit, info, comm, baseptr, win, ierror)
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
        END SUBROUTINE PMPIR_Win_allocate_shared_c_f08
    END INTERFACE PMPI_Win_allocate_shared
    
    INTERFACE PMPI_Win_attach
        SUBROUTINE PMPIR_Win_attach_f08ts(win, base, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: base
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_attach_f08ts
    END INTERFACE PMPI_Win_attach
    
    INTERFACE PMPI_Win_complete
        SUBROUTINE PMPIR_Win_complete_f08(win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_complete_f08
    END INTERFACE PMPI_Win_complete
    
    INTERFACE PMPI_Win_create
        SUBROUTINE PMPIR_Win_create_f08ts(base, size, disp_unit, info, comm, win, ierror)
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
        END SUBROUTINE PMPIR_Win_create_f08ts
        
        SUBROUTINE PMPIR_Win_create_c_f08ts(base, size, disp_unit, info, comm, win, ierror)
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
        END SUBROUTINE PMPIR_Win_create_c_f08ts
    END INTERFACE PMPI_Win_create
    
    INTERFACE PMPI_Win_create_dynamic
        SUBROUTINE PMPIR_Win_create_dynamic_f08(info, comm, win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info, MPI_Comm, MPI_Win
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(in) :: info
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Win), INTENT(out) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_create_dynamic_f08
    END INTERFACE PMPI_Win_create_dynamic
    
    INTERFACE PMPI_Win_detach
        SUBROUTINE PMPIR_Win_detach_f08ts(win, base, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: base
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_detach_f08ts
    END INTERFACE PMPI_Win_detach
    
    INTERFACE PMPI_Win_fence
        SUBROUTINE PMPIR_Win_fence_f08(assert, win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            INTEGER, INTENT(in) :: assert
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_fence_f08
    END INTERFACE PMPI_Win_fence
    
    INTERFACE PMPI_Win_flush
        SUBROUTINE PMPIR_Win_flush_f08(rank, win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            INTEGER, INTENT(in) :: rank
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_flush_f08
    END INTERFACE PMPI_Win_flush
    
    INTERFACE PMPI_Win_flush_all
        SUBROUTINE PMPIR_Win_flush_all_f08(win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_flush_all_f08
    END INTERFACE PMPI_Win_flush_all
    
    INTERFACE PMPI_Win_flush_local
        SUBROUTINE PMPIR_Win_flush_local_f08(rank, win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            INTEGER, INTENT(in) :: rank
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_flush_local_f08
    END INTERFACE PMPI_Win_flush_local
    
    INTERFACE PMPI_Win_flush_local_all
        SUBROUTINE PMPIR_Win_flush_local_all_f08(win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_flush_local_all_f08
    END INTERFACE PMPI_Win_flush_local_all
    
    INTERFACE PMPI_Win_free
        SUBROUTINE PMPIR_Win_free_f08(win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(inout) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_free_f08
    END INTERFACE PMPI_Win_free
    
    INTERFACE PMPI_Win_get_group
        SUBROUTINE PMPIR_Win_get_group_f08(win, group, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win, MPI_Group
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            TYPE(MPI_Group), INTENT(out) :: group
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_get_group_f08
    END INTERFACE PMPI_Win_get_group
    
    INTERFACE PMPI_Win_get_info
        SUBROUTINE PMPIR_Win_get_info_f08(win, info_used, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win, MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            TYPE(MPI_Info), INTENT(out) :: info_used
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_get_info_f08
    END INTERFACE PMPI_Win_get_info
    
    INTERFACE PMPI_Win_get_name
        SUBROUTINE PMPIR_Win_get_name_f08(win, win_name, resultlen, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            USE :: mpi_f08_compile_constants, ONLY : MPI_MAX_OBJECT_NAME
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            CHARACTER(len=MPI_MAX_OBJECT_NAME), INTENT(out) :: win_name
            INTEGER, INTENT(out) :: resultlen
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_get_name_f08
    END INTERFACE PMPI_Win_get_name
    
    INTERFACE PMPI_Win_lock
        SUBROUTINE PMPIR_Win_lock_f08(lock_type, rank, assert, win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            INTEGER, INTENT(in) :: lock_type
            INTEGER, INTENT(in) :: rank
            INTEGER, INTENT(in) :: assert
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_lock_f08
    END INTERFACE PMPI_Win_lock
    
    INTERFACE PMPI_Win_lock_all
        SUBROUTINE PMPIR_Win_lock_all_f08(assert, win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            INTEGER, INTENT(in) :: assert
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_lock_all_f08
    END INTERFACE PMPI_Win_lock_all
    
    INTERFACE PMPI_Win_post
        SUBROUTINE PMPIR_Win_post_f08(group, assert, win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Group, MPI_Win
            IMPLICIT NONE
            TYPE(MPI_Group), INTENT(in) :: group
            INTEGER, INTENT(in) :: assert
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_post_f08
    END INTERFACE PMPI_Win_post
    
    INTERFACE PMPI_Win_set_info
        SUBROUTINE PMPIR_Win_set_info_f08(win, info, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win, MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            TYPE(MPI_Info), INTENT(in) :: info
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_set_info_f08
    END INTERFACE PMPI_Win_set_info
    
    INTERFACE PMPI_Win_set_name
        SUBROUTINE PMPIR_Win_set_name_f08(win, win_name, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            CHARACTER(len=*), INTENT(in) :: win_name
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_set_name_f08
    END INTERFACE PMPI_Win_set_name
    
    INTERFACE PMPI_Win_shared_query
        SUBROUTINE PMPIR_Win_shared_query_f08(win, rank, size, disp_unit, baseptr, ierror)
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
        END SUBROUTINE PMPIR_Win_shared_query_f08
        
        SUBROUTINE PMPIR_Win_shared_query_c_f08(win, rank, size, disp_unit, baseptr, ierror)
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
        END SUBROUTINE PMPIR_Win_shared_query_c_f08
    END INTERFACE PMPI_Win_shared_query
    
    INTERFACE PMPI_Win_start
        SUBROUTINE PMPIR_Win_start_f08(group, assert, win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Group, MPI_Win
            IMPLICIT NONE
            TYPE(MPI_Group), INTENT(in) :: group
            INTEGER, INTENT(in) :: assert
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_start_f08
    END INTERFACE PMPI_Win_start
    
    INTERFACE PMPI_Win_sync
        SUBROUTINE PMPIR_Win_sync_f08(win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_sync_f08
    END INTERFACE PMPI_Win_sync
    
    INTERFACE PMPI_Win_test
        SUBROUTINE PMPIR_Win_test_f08(win, flag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            LOGICAL, INTENT(out) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_test_f08
    END INTERFACE PMPI_Win_test
    
    INTERFACE PMPI_Win_unlock
        SUBROUTINE PMPIR_Win_unlock_f08(rank, win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            INTEGER, INTENT(in) :: rank
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_unlock_f08
    END INTERFACE PMPI_Win_unlock
    
    INTERFACE PMPI_Win_unlock_all
        SUBROUTINE PMPIR_Win_unlock_all_f08(win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_unlock_all_f08
    END INTERFACE PMPI_Win_unlock_all
    
    INTERFACE PMPI_Win_wait
        SUBROUTINE PMPIR_Win_wait_f08(win, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Win
            IMPLICIT NONE
            TYPE(MPI_Win), INTENT(in) :: win
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Win_wait_f08
    END INTERFACE PMPI_Win_wait
    
    INTERFACE PMPI_Close_port
        SUBROUTINE PMPIR_Close_port_f08(port_name, ierror)
            IMPLICIT NONE
            CHARACTER(len=*), INTENT(in) :: port_name
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Close_port_f08
    END INTERFACE PMPI_Close_port
    
    INTERFACE PMPI_Comm_accept
        SUBROUTINE PMPIR_Comm_accept_f08(port_name, info, root, comm, newcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info, MPI_Comm
            IMPLICIT NONE
            CHARACTER(len=*), INTENT(in) :: port_name
            TYPE(MPI_Info), INTENT(in) :: info
            INTEGER, INTENT(in) :: root
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Comm), INTENT(out) :: newcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_accept_f08
    END INTERFACE PMPI_Comm_accept
    
    INTERFACE PMPI_Comm_connect
        SUBROUTINE PMPIR_Comm_connect_f08(port_name, info, root, comm, newcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info, MPI_Comm
            IMPLICIT NONE
            CHARACTER(len=*), INTENT(in) :: port_name
            TYPE(MPI_Info), INTENT(in) :: info
            INTEGER, INTENT(in) :: root
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPI_Comm), INTENT(out) :: newcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_connect_f08
    END INTERFACE PMPI_Comm_connect
    
    INTERFACE PMPI_Comm_disconnect
        SUBROUTINE PMPIR_Comm_disconnect_f08(comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(inout) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_disconnect_f08
    END INTERFACE PMPI_Comm_disconnect
    
    INTERFACE PMPI_Comm_get_parent
        SUBROUTINE PMPIR_Comm_get_parent_f08(parent, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(out) :: parent
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_get_parent_f08
    END INTERFACE PMPI_Comm_get_parent
    
    INTERFACE PMPI_Comm_join
        SUBROUTINE PMPIR_Comm_join_f08(fd, intercomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            INTEGER, INTENT(in) :: fd
            TYPE(MPI_Comm), INTENT(out) :: intercomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Comm_join_f08
    END INTERFACE PMPI_Comm_join
    
    INTERFACE PMPI_Comm_spawn
        SUBROUTINE PMPIR_Comm_spawn_f08(command, argv, maxprocs, info, root, comm, intercomm, &
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
        END SUBROUTINE PMPIR_Comm_spawn_f08
    END INTERFACE PMPI_Comm_spawn
    
    INTERFACE PMPI_Comm_spawn_multiple
        SUBROUTINE PMPIR_Comm_spawn_multiple_f08(count, array_of_commands, array_of_argv, array_of_maxprocs, &
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
        END SUBROUTINE PMPIR_Comm_spawn_multiple_f08
    END INTERFACE PMPI_Comm_spawn_multiple
    
    INTERFACE PMPI_Lookup_name
        SUBROUTINE PMPIR_Lookup_name_f08(service_name, info, port_name, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            USE :: mpi_f08_compile_constants, ONLY : MPI_MAX_PORT_NAME
            IMPLICIT NONE
            CHARACTER(len=*), INTENT(in) :: service_name
            TYPE(MPI_Info), INTENT(in) :: info
            CHARACTER(len=MPI_MAX_PORT_NAME), INTENT(out) :: port_name
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Lookup_name_f08
    END INTERFACE PMPI_Lookup_name
    
    INTERFACE PMPI_Open_port
        SUBROUTINE PMPIR_Open_port_f08(info, port_name, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            USE :: mpi_f08_compile_constants, ONLY : MPI_MAX_PORT_NAME
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(in) :: info
            CHARACTER(len=MPI_MAX_PORT_NAME), INTENT(out) :: port_name
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Open_port_f08
    END INTERFACE PMPI_Open_port
    
    INTERFACE PMPI_Publish_name
        SUBROUTINE PMPIR_Publish_name_f08(service_name, info, port_name, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            IMPLICIT NONE
            CHARACTER(len=*), INTENT(in) :: service_name
            TYPE(MPI_Info), INTENT(in) :: info
            CHARACTER(len=*), INTENT(in) :: port_name
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Publish_name_f08
    END INTERFACE PMPI_Publish_name
    
    INTERFACE PMPI_Unpublish_name
        SUBROUTINE PMPIR_Unpublish_name_f08(service_name, info, port_name, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            IMPLICIT NONE
            CHARACTER(len=*), INTENT(in) :: service_name
            TYPE(MPI_Info), INTENT(in) :: info
            CHARACTER(len=*), INTENT(in) :: port_name
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Unpublish_name_f08
    END INTERFACE PMPI_Unpublish_name
    
    INTERFACE PMPIX_Stream_create
        SUBROUTINE PMPIXR_Stream_create_f08(info, stream, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info, MPIX_Stream
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(in) :: info
            TYPE(MPIX_Stream), INTENT(out) :: stream
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIXR_Stream_create_f08
    END INTERFACE PMPIX_Stream_create
    
    INTERFACE PMPIX_Stream_free
        SUBROUTINE PMPIXR_Stream_free_f08(stream, ierror)
            USE :: mpi_f08_types, ONLY : MPIX_Stream
            IMPLICIT NONE
            TYPE(MPIX_Stream), INTENT(inout) :: stream
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIXR_Stream_free_f08
    END INTERFACE PMPIX_Stream_free
    
    INTERFACE PMPIX_Stream_comm_create
        SUBROUTINE PMPIXR_Stream_comm_create_f08(comm, stream, newcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPIX_Stream
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            TYPE(MPIX_Stream), INTENT(in) :: stream
            TYPE(MPI_Comm), INTENT(out) :: newcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIXR_Stream_comm_create_f08
    END INTERFACE PMPIX_Stream_comm_create
    
    INTERFACE PMPIX_Stream_comm_create_multiplex
        SUBROUTINE PMPIXR_Stream_comm_create_multiplex_f08(comm, count, array_of_streams, newcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPIX_Stream
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: count
            TYPE(MPIX_Stream), INTENT(in) :: array_of_streams(count)
            TYPE(MPI_Comm), INTENT(out) :: newcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIXR_Stream_comm_create_multiplex_f08
    END INTERFACE PMPIX_Stream_comm_create_multiplex
    
    INTERFACE PMPIX_Comm_get_stream
        SUBROUTINE PMPIXR_Comm_get_stream_f08(comm, idx, stream, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPIX_Stream
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: idx
            TYPE(MPIX_Stream), INTENT(out) :: stream
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIXR_Comm_get_stream_f08
    END INTERFACE PMPIX_Comm_get_stream
    
    INTERFACE PMPIX_Stream_progress
        SUBROUTINE PMPIXR_Stream_progress_f08(stream, ierror)
            USE :: mpi_f08_types, ONLY : MPIX_Stream
            IMPLICIT NONE
            TYPE(MPIX_Stream), INTENT(in) :: stream
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIXR_Stream_progress_f08
    END INTERFACE PMPIX_Stream_progress
    
    INTERFACE PMPIX_Start_progress_thread
        SUBROUTINE PMPIXR_Start_progress_thread_f08(stream, ierror)
            USE :: mpi_f08_types, ONLY : MPIX_Stream
            IMPLICIT NONE
            TYPE(MPIX_Stream), INTENT(in) :: stream
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIXR_Start_progress_thread_f08
    END INTERFACE PMPIX_Start_progress_thread
    
    INTERFACE PMPIX_Stop_progress_thread
        SUBROUTINE PMPIXR_Stop_progress_thread_f08(stream, ierror)
            USE :: mpi_f08_types, ONLY : MPIX_Stream
            IMPLICIT NONE
            TYPE(MPIX_Stream), INTENT(in) :: stream
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIXR_Stop_progress_thread_f08
    END INTERFACE PMPIX_Stop_progress_thread
    
    INTERFACE PMPIX_Stream_send
        SUBROUTINE PMPIXR_Stream_send_f08ts(buf, count, datatype, dest, tag, comm, source_stream_index, &
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
        END SUBROUTINE PMPIXR_Stream_send_f08ts
        
        SUBROUTINE PMPIXR_Stream_send_c_f08ts(buf, count, datatype, dest, tag, comm, source_stream_index, &
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
        END SUBROUTINE PMPIXR_Stream_send_c_f08ts
    END INTERFACE PMPIX_Stream_send
    
    INTERFACE PMPIX_Stream_isend
        SUBROUTINE PMPIXR_Stream_isend_f08ts(buf, count, datatype, dest, tag, comm, source_stream_index, &
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
        END SUBROUTINE PMPIXR_Stream_isend_f08ts
        
        SUBROUTINE PMPIXR_Stream_isend_c_f08ts(buf, count, datatype, dest, tag, comm, source_stream_index, &
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
        END SUBROUTINE PMPIXR_Stream_isend_c_f08ts
    END INTERFACE PMPIX_Stream_isend
    
    INTERFACE PMPIX_Stream_recv
        SUBROUTINE PMPIXR_Stream_recv_f08ts(buf, count, datatype, source, tag, comm, source_stream_index, &
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
        END SUBROUTINE PMPIXR_Stream_recv_f08ts
        
        SUBROUTINE PMPIXR_Stream_recv_c_f08ts(buf, count, datatype, source, tag, comm, source_stream_index, &
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
        END SUBROUTINE PMPIXR_Stream_recv_c_f08ts
    END INTERFACE PMPIX_Stream_recv
    
    INTERFACE PMPIX_Stream_irecv
        SUBROUTINE PMPIXR_Stream_irecv_f08ts(buf, count, datatype, source, tag, comm, source_stream_index, &
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
        END SUBROUTINE PMPIXR_Stream_irecv_f08ts
        
        SUBROUTINE PMPIXR_Stream_irecv_c_f08ts(buf, count, datatype, source, tag, comm, source_stream_index, &
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
        END SUBROUTINE PMPIXR_Stream_irecv_c_f08ts
    END INTERFACE PMPIX_Stream_irecv
    
    INTERFACE PMPIX_Send_enqueue
        SUBROUTINE PMPIXR_Send_enqueue_f08ts(buf, count, datatype, dest, tag, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Comm
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, INTENT(in) :: dest
            INTEGER, INTENT(in) :: tag
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIXR_Send_enqueue_f08ts
        
        SUBROUTINE PMPIXR_Send_enqueue_c_f08ts(buf, count, datatype, dest, tag, comm, ierror)
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
        END SUBROUTINE PMPIXR_Send_enqueue_c_f08ts
    END INTERFACE PMPIX_Send_enqueue
    
    INTERFACE PMPIX_Recv_enqueue
        SUBROUTINE PMPIXR_Recv_enqueue_f08ts(buf, count, datatype, source, tag, comm, status, ierror)
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
        END SUBROUTINE PMPIXR_Recv_enqueue_f08ts
        
        SUBROUTINE PMPIXR_Recv_enqueue_c_f08ts(buf, count, datatype, source, tag, comm, status, ierror)
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
        END SUBROUTINE PMPIXR_Recv_enqueue_c_f08ts
    END INTERFACE PMPIX_Recv_enqueue
    
    INTERFACE PMPIX_Isend_enqueue
        SUBROUTINE PMPIXR_Isend_enqueue_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
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
        END SUBROUTINE PMPIXR_Isend_enqueue_f08ts
        
        SUBROUTINE PMPIXR_Isend_enqueue_c_f08ts(buf, count, datatype, dest, tag, comm, request, ierror)
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
        END SUBROUTINE PMPIXR_Isend_enqueue_c_f08ts
    END INTERFACE PMPIX_Isend_enqueue
    
    INTERFACE PMPIX_Irecv_enqueue
        SUBROUTINE PMPIXR_Irecv_enqueue_f08ts(buf, count, datatype, source, tag, comm, request, ierror)
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
        END SUBROUTINE PMPIXR_Irecv_enqueue_f08ts
        
        SUBROUTINE PMPIXR_Irecv_enqueue_c_f08ts(buf, count, datatype, source, tag, comm, request, ierror)
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
        END SUBROUTINE PMPIXR_Irecv_enqueue_c_f08ts
    END INTERFACE PMPIX_Irecv_enqueue
    
    INTERFACE PMPIX_Wait_enqueue
        SUBROUTINE PMPIXR_Wait_enqueue_f08(request, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_Request), INTENT(inout) :: request
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIXR_Wait_enqueue_f08
    END INTERFACE PMPIX_Wait_enqueue
    
    INTERFACE PMPIX_Waitall_enqueue
        SUBROUTINE PMPIXR_Waitall_enqueue_f08(count, array_of_requests, array_of_statuses, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Request, MPI_Status
            IMPLICIT NONE
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Request), INTENT(inout) :: array_of_requests(count)
            TYPE(MPI_Status), INTENT(out), TARGET :: array_of_statuses(*)
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIXR_Waitall_enqueue_f08
    END INTERFACE PMPIX_Waitall_enqueue
    
    INTERFACE PMPIX_Allreduce_enqueue
        SUBROUTINE PMPIXR_Allreduce_enqueue_f08ts(sendbuf, recvbuf, count, datatype, op, comm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Datatype, MPI_Op, MPI_Comm
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
            TYPE(*), DIMENSION(..) :: recvbuf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Op), INTENT(in) :: op
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIXR_Allreduce_enqueue_f08ts
        
        SUBROUTINE PMPIXR_Allreduce_enqueue_c_f08ts(sendbuf, recvbuf, count, datatype, op, comm, ierror)
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
        END SUBROUTINE PMPIXR_Allreduce_enqueue_c_f08ts
    END INTERFACE PMPIX_Allreduce_enqueue
    
    INTERFACE PMPIX_Threadcomm_init
        SUBROUTINE PMPIXR_Threadcomm_init_f08(comm, num_threads, newthreadcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: num_threads
            TYPE(MPI_Comm), INTENT(out) :: newthreadcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIXR_Threadcomm_init_f08
    END INTERFACE PMPIX_Threadcomm_init
    
    INTERFACE PMPIX_Threadcomm_free
        SUBROUTINE PMPIXR_Threadcomm_free_f08(threadcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(inout) :: threadcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIXR_Threadcomm_free_f08
    END INTERFACE PMPIX_Threadcomm_free
    
    INTERFACE PMPIX_Threadcomm_start
        SUBROUTINE PMPIXR_Threadcomm_start_f08(threadcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: threadcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIXR_Threadcomm_start_f08
    END INTERFACE PMPIX_Threadcomm_start
    
    INTERFACE PMPIX_Threadcomm_finish
        SUBROUTINE PMPIXR_Threadcomm_finish_f08(threadcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: threadcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIXR_Threadcomm_finish_f08
    END INTERFACE PMPIX_Threadcomm_finish
    
    INTERFACE PMPI_Wtick
        FUNCTION PMPIR_Wtick_f08() result(res)
            IMPLICIT NONE
            DOUBLE PRECISION :: res
        END FUNCTION PMPIR_Wtick_f08
    END INTERFACE PMPI_Wtick
    
    INTERFACE PMPI_Wtime
        FUNCTION PMPIR_Wtime_f08() result(res)
            IMPLICIT NONE
            DOUBLE PRECISION :: res
        END FUNCTION PMPIR_Wtime_f08
    END INTERFACE PMPI_Wtime
    
    INTERFACE PMPI_Cart_coords
        SUBROUTINE PMPIR_Cart_coords_f08(comm, rank, maxdims, coords, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: rank
            INTEGER, INTENT(in) :: maxdims
            INTEGER, INTENT(out) :: coords(maxdims)
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Cart_coords_f08
    END INTERFACE PMPI_Cart_coords
    
    INTERFACE PMPI_Cart_create
        SUBROUTINE PMPIR_Cart_create_f08(comm_old, ndims, dims, periods, reorder, comm_cart, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm_old
            INTEGER, INTENT(in) :: ndims
            INTEGER, INTENT(in) :: dims(ndims)
            LOGICAL, INTENT(in) :: periods(ndims)
            LOGICAL, INTENT(in) :: reorder
            TYPE(MPI_Comm), INTENT(out) :: comm_cart
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Cart_create_f08
    END INTERFACE PMPI_Cart_create
    
    INTERFACE PMPI_Cart_get
        SUBROUTINE PMPIR_Cart_get_f08(comm, maxdims, dims, periods, coords, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: maxdims
            INTEGER, INTENT(out) :: dims(maxdims)
            LOGICAL, INTENT(out) :: periods(maxdims)
            INTEGER, INTENT(out) :: coords(maxdims)
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Cart_get_f08
    END INTERFACE PMPI_Cart_get
    
    INTERFACE PMPI_Cart_map
        SUBROUTINE PMPIR_Cart_map_f08(comm, ndims, dims, periods, newrank, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: ndims
            INTEGER, INTENT(in) :: dims(ndims)
            LOGICAL, INTENT(in) :: periods(ndims)
            INTEGER, INTENT(out) :: newrank
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Cart_map_f08
    END INTERFACE PMPI_Cart_map
    
    INTERFACE PMPI_Cart_rank
        SUBROUTINE PMPIR_Cart_rank_f08(comm, coords, rank, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: coords(*)
            INTEGER, INTENT(out) :: rank
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Cart_rank_f08
    END INTERFACE PMPI_Cart_rank
    
    INTERFACE PMPI_Cart_shift
        SUBROUTINE PMPIR_Cart_shift_f08(comm, direction, disp, rank_source, rank_dest, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: direction
            INTEGER, INTENT(in) :: disp
            INTEGER, INTENT(out) :: rank_source
            INTEGER, INTENT(out) :: rank_dest
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Cart_shift_f08
    END INTERFACE PMPI_Cart_shift
    
    INTERFACE PMPI_Cart_sub
        SUBROUTINE PMPIR_Cart_sub_f08(comm, remain_dims, newcomm, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            LOGICAL, INTENT(in) :: remain_dims(*)
            TYPE(MPI_Comm), INTENT(out) :: newcomm
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Cart_sub_f08
    END INTERFACE PMPI_Cart_sub
    
    INTERFACE PMPI_Cartdim_get
        SUBROUTINE PMPIR_Cartdim_get_f08(comm, ndims, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(out) :: ndims
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Cartdim_get_f08
    END INTERFACE PMPI_Cartdim_get
    
    INTERFACE PMPI_Dims_create
        SUBROUTINE PMPIR_Dims_create_f08(nnodes, ndims, dims, ierror)
            IMPLICIT NONE
            INTEGER, INTENT(in) :: nnodes
            INTEGER, INTENT(in) :: ndims
            INTEGER, INTENT(inout) :: dims(ndims)
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Dims_create_f08
    END INTERFACE PMPI_Dims_create
    
    INTERFACE PMPI_Dist_graph_create
        SUBROUTINE PMPIR_Dist_graph_create_f08(comm_old, n, sources, degrees, destinations, weights, info, &
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
        END SUBROUTINE PMPIR_Dist_graph_create_f08
    END INTERFACE PMPI_Dist_graph_create
    
    INTERFACE PMPI_Dist_graph_create_adjacent
        SUBROUTINE PMPIR_Dist_graph_create_adjacent_f08(comm_old, indegree, sources, sourceweights, outdegree, &
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
        END SUBROUTINE PMPIR_Dist_graph_create_adjacent_f08
    END INTERFACE PMPI_Dist_graph_create_adjacent
    
    INTERFACE PMPI_Dist_graph_neighbors
        SUBROUTINE PMPIR_Dist_graph_neighbors_f08(comm, maxindegree, sources, sourceweights, maxoutdegree, &
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
        END SUBROUTINE PMPIR_Dist_graph_neighbors_f08
    END INTERFACE PMPI_Dist_graph_neighbors
    
    INTERFACE PMPI_Dist_graph_neighbors_count
        SUBROUTINE PMPIR_Dist_graph_neighbors_count_f08(comm, indegree, outdegree, weighted, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(out) :: indegree
            INTEGER, INTENT(out) :: outdegree
            LOGICAL, INTENT(out) :: weighted
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Dist_graph_neighbors_count_f08
    END INTERFACE PMPI_Dist_graph_neighbors_count
    
    INTERFACE PMPI_Get_hw_resource_info
        SUBROUTINE PMPIR_Get_hw_resource_info_f08(hw_info, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            IMPLICIT NONE
            TYPE(MPI_Info), INTENT(out) :: hw_info
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Get_hw_resource_info_f08
    END INTERFACE PMPI_Get_hw_resource_info
    
    INTERFACE PMPI_Graph_create
        SUBROUTINE PMPIR_Graph_create_f08(comm_old, nnodes, indx, edges, reorder, comm_graph, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm_old
            INTEGER, INTENT(in) :: nnodes
            INTEGER, INTENT(in) :: indx(nnodes)
            INTEGER, INTENT(in) :: edges(*)
            LOGICAL, INTENT(in) :: reorder
            TYPE(MPI_Comm), INTENT(out) :: comm_graph
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Graph_create_f08
    END INTERFACE PMPI_Graph_create
    
    INTERFACE PMPI_Graph_get
        SUBROUTINE PMPIR_Graph_get_f08(comm, maxindex, maxedges, indx, edges, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: maxindex
            INTEGER, INTENT(in) :: maxedges
            INTEGER, INTENT(out) :: indx(maxindex)
            INTEGER, INTENT(out) :: edges(maxedges)
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Graph_get_f08
    END INTERFACE PMPI_Graph_get
    
    INTERFACE PMPI_Graph_map
        SUBROUTINE PMPIR_Graph_map_f08(comm, nnodes, indx, edges, newrank, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: nnodes
            INTEGER, INTENT(in) :: indx(nnodes)
            INTEGER, INTENT(in) :: edges(*)
            INTEGER, INTENT(out) :: newrank
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Graph_map_f08
    END INTERFACE PMPI_Graph_map
    
    INTERFACE PMPI_Graph_neighbors
        SUBROUTINE PMPIR_Graph_neighbors_f08(comm, rank, maxneighbors, neighbors, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: rank
            INTEGER, INTENT(in) :: maxneighbors
            INTEGER, INTENT(out) :: neighbors(maxneighbors)
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Graph_neighbors_f08
    END INTERFACE PMPI_Graph_neighbors
    
    INTERFACE PMPI_Graph_neighbors_count
        SUBROUTINE PMPIR_Graph_neighbors_count_f08(comm, rank, nneighbors, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(in) :: rank
            INTEGER, INTENT(out) :: nneighbors
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Graph_neighbors_count_f08
    END INTERFACE PMPI_Graph_neighbors_count
    
    INTERFACE PMPI_Graphdims_get
        SUBROUTINE PMPIR_Graphdims_get_f08(comm, nnodes, nedges, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(out) :: nnodes
            INTEGER, INTENT(out) :: nedges
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Graphdims_get_f08
    END INTERFACE PMPI_Graphdims_get
    
    INTERFACE PMPI_Topo_test
        SUBROUTINE PMPIR_Topo_test_f08(comm, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            INTEGER, INTENT(out) :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_Topo_test_f08
    END INTERFACE PMPI_Topo_test
    
    INTERFACE PMPI_File_close
        SUBROUTINE PMPIR_File_close_f08(fh, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(inout) :: fh
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_close_f08
    END INTERFACE PMPI_File_close
    
    INTERFACE PMPI_File_delete
        SUBROUTINE PMPIR_File_delete_f08(filename, info, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Info
            IMPLICIT NONE
            CHARACTER(len=*), INTENT(in) :: filename
            TYPE(MPI_Info), INTENT(in) :: info
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_delete_f08
    END INTERFACE PMPI_File_delete
    
    INTERFACE PMPI_File_get_amode
        SUBROUTINE PMPIR_File_get_amode_f08(fh, amode, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER, INTENT(out) :: amode
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_get_amode_f08
    END INTERFACE PMPI_File_get_amode
    
    INTERFACE PMPI_File_get_atomicity
        SUBROUTINE PMPIR_File_get_atomicity_f08(fh, flag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            LOGICAL, INTENT(out) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_get_atomicity_f08
    END INTERFACE PMPI_File_get_atomicity
    
    INTERFACE PMPI_File_get_byte_offset
        SUBROUTINE PMPIR_File_get_byte_offset_f08(fh, offset, disp, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(out) :: disp
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_get_byte_offset_f08
    END INTERFACE PMPI_File_get_byte_offset
    
    INTERFACE PMPI_File_get_group
        SUBROUTINE PMPIR_File_get_group_f08(fh, group, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Group
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(MPI_Group), INTENT(out) :: group
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_get_group_f08
    END INTERFACE PMPI_File_get_group
    
    INTERFACE PMPI_File_get_info
        SUBROUTINE PMPIR_File_get_info_f08(fh, info_used, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Info
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(MPI_Info), INTENT(out) :: info_used
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_get_info_f08
    END INTERFACE PMPI_File_get_info
    
    INTERFACE PMPI_File_get_position
        SUBROUTINE PMPIR_File_get_position_f08(fh, offset, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(out) :: offset
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_get_position_f08
    END INTERFACE PMPI_File_get_position
    
    INTERFACE PMPI_File_get_position_shared
        SUBROUTINE PMPIR_File_get_position_shared_f08(fh, offset, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(out) :: offset
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_get_position_shared_f08
    END INTERFACE PMPI_File_get_position_shared
    
    INTERFACE PMPI_File_get_size
        SUBROUTINE PMPIR_File_get_size_f08(fh, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(out) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_get_size_f08
    END INTERFACE PMPI_File_get_size
    
    INTERFACE PMPI_File_get_type_extent
        SUBROUTINE PMPIR_File_get_type_extent_f08(fh, datatype, extent, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: extent
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_get_type_extent_f08
    END INTERFACE PMPI_File_get_type_extent
    
    INTERFACE PMPI_File_get_view
        SUBROUTINE PMPIR_File_get_view_f08(fh, disp, etype, filetype, datarep, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(out) :: disp
            TYPE(MPI_Datatype), INTENT(out) :: etype
            TYPE(MPI_Datatype), INTENT(out) :: filetype
            CHARACTER(len=*), INTENT(out) :: datarep
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_get_view_f08
    END INTERFACE PMPI_File_get_view
    
    INTERFACE PMPI_File_iread
        SUBROUTINE PMPIR_File_iread_f08ts(fh, buf, count, datatype, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Request
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_iread_f08ts
        
        SUBROUTINE PMPIR_File_iread_c_f08ts(fh, buf, count, datatype, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_iread_c_f08ts
    END INTERFACE PMPI_File_iread
    
    INTERFACE PMPI_File_iread_all
        SUBROUTINE PMPIR_File_iread_all_f08ts(fh, buf, count, datatype, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Request
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_iread_all_f08ts
        
        SUBROUTINE PMPIR_File_iread_all_c_f08ts(fh, buf, count, datatype, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_iread_all_c_f08ts
    END INTERFACE PMPI_File_iread_all
    
    INTERFACE PMPI_File_iread_at
        SUBROUTINE PMPIR_File_iread_at_f08ts(fh, offset, buf, count, datatype, request, ierror)
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
        END SUBROUTINE PMPIR_File_iread_at_f08ts
        
        SUBROUTINE PMPIR_File_iread_at_c_f08ts(fh, offset, buf, count, datatype, request, ierror)
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
        END SUBROUTINE PMPIR_File_iread_at_c_f08ts
    END INTERFACE PMPI_File_iread_at
    
    INTERFACE PMPI_File_iread_at_all
        SUBROUTINE PMPIR_File_iread_at_all_f08ts(fh, offset, buf, count, datatype, request, ierror)
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
        END SUBROUTINE PMPIR_File_iread_at_all_f08ts
        
        SUBROUTINE PMPIR_File_iread_at_all_c_f08ts(fh, offset, buf, count, datatype, request, ierror)
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
        END SUBROUTINE PMPIR_File_iread_at_all_c_f08ts
    END INTERFACE PMPI_File_iread_at_all
    
    INTERFACE PMPI_File_iread_shared
        SUBROUTINE PMPIR_File_iread_shared_f08ts(fh, buf, count, datatype, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Request
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_iread_shared_f08ts
        
        SUBROUTINE PMPIR_File_iread_shared_c_f08ts(fh, buf, count, datatype, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_iread_shared_c_f08ts
    END INTERFACE PMPI_File_iread_shared
    
    INTERFACE PMPI_File_iwrite
        SUBROUTINE PMPIR_File_iwrite_f08ts(fh, buf, count, datatype, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Request
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_iwrite_f08ts
        
        SUBROUTINE PMPIR_File_iwrite_c_f08ts(fh, buf, count, datatype, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_iwrite_c_f08ts
    END INTERFACE PMPI_File_iwrite
    
    INTERFACE PMPI_File_iwrite_all
        SUBROUTINE PMPIR_File_iwrite_all_f08ts(fh, buf, count, datatype, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Request
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_iwrite_all_f08ts
        
        SUBROUTINE PMPIR_File_iwrite_all_c_f08ts(fh, buf, count, datatype, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_iwrite_all_c_f08ts
    END INTERFACE PMPI_File_iwrite_all
    
    INTERFACE PMPI_File_iwrite_at
        SUBROUTINE PMPIR_File_iwrite_at_f08ts(fh, offset, buf, count, datatype, request, ierror)
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
        END SUBROUTINE PMPIR_File_iwrite_at_f08ts
        
        SUBROUTINE PMPIR_File_iwrite_at_c_f08ts(fh, offset, buf, count, datatype, request, ierror)
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
        END SUBROUTINE PMPIR_File_iwrite_at_c_f08ts
    END INTERFACE PMPI_File_iwrite_at
    
    INTERFACE PMPI_File_iwrite_at_all
        SUBROUTINE PMPIR_File_iwrite_at_all_f08ts(fh, offset, buf, count, datatype, request, ierror)
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
        END SUBROUTINE PMPIR_File_iwrite_at_all_f08ts
        
        SUBROUTINE PMPIR_File_iwrite_at_all_c_f08ts(fh, offset, buf, count, datatype, request, ierror)
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
        END SUBROUTINE PMPIR_File_iwrite_at_all_c_f08ts
    END INTERFACE PMPI_File_iwrite_at_all
    
    INTERFACE PMPI_File_iwrite_shared
        SUBROUTINE PMPIR_File_iwrite_shared_f08ts(fh, buf, count, datatype, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Request
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_iwrite_shared_f08ts
        
        SUBROUTINE PMPIR_File_iwrite_shared_c_f08ts(fh, buf, count, datatype, request, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Request
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Request), INTENT(out) :: request
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_iwrite_shared_c_f08ts
    END INTERFACE PMPI_File_iwrite_shared
    
    INTERFACE PMPI_File_open
        SUBROUTINE PMPIR_File_open_f08(comm, filename, amode, info, fh, ierror)
            USE :: mpi_f08_types, ONLY : MPI_Comm, MPI_Info, MPI_File
            IMPLICIT NONE
            TYPE(MPI_Comm), INTENT(in) :: comm
            CHARACTER(len=*), INTENT(in) :: filename
            INTEGER, INTENT(in) :: amode
            TYPE(MPI_Info), INTENT(in) :: info
            TYPE(MPI_File), INTENT(out) :: fh
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_open_f08
    END INTERFACE PMPI_File_open
    
    INTERFACE PMPI_File_preallocate
        SUBROUTINE PMPIR_File_preallocate_f08(fh, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_preallocate_f08
    END INTERFACE PMPI_File_preallocate
    
    INTERFACE PMPI_File_read
        SUBROUTINE PMPIR_File_read_f08ts(fh, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_read_f08ts
        
        SUBROUTINE PMPIR_File_read_c_f08ts(fh, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..) :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_read_c_f08ts
    END INTERFACE PMPI_File_read
    
    INTERFACE PMPI_File_read_all
        SUBROUTINE PMPIR_File_read_all_f08ts(fh, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_read_all_f08ts
        
        SUBROUTINE PMPIR_File_read_all_c_f08ts(fh, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..) :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_read_all_c_f08ts
    END INTERFACE PMPI_File_read_all
    
    INTERFACE PMPI_File_read_all_begin
        SUBROUTINE PMPIR_File_read_all_begin_f08ts(fh, buf, count, datatype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_read_all_begin_f08ts
        
        SUBROUTINE PMPIR_File_read_all_begin_c_f08ts(fh, buf, count, datatype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_read_all_begin_c_f08ts
    END INTERFACE PMPI_File_read_all_begin
    
    INTERFACE PMPI_File_read_all_end
        SUBROUTINE PMPIR_File_read_all_end_f08ts(fh, buf, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_read_all_end_f08ts
    END INTERFACE PMPI_File_read_all_end
    
    INTERFACE PMPI_File_read_at
        SUBROUTINE PMPIR_File_read_at_f08ts(fh, offset, buf, count, datatype, status, ierror)
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
        END SUBROUTINE PMPIR_File_read_at_f08ts
        
        SUBROUTINE PMPIR_File_read_at_c_f08ts(fh, offset, buf, count, datatype, status, ierror)
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
        END SUBROUTINE PMPIR_File_read_at_c_f08ts
    END INTERFACE PMPI_File_read_at
    
    INTERFACE PMPI_File_read_at_all
        SUBROUTINE PMPIR_File_read_at_all_f08ts(fh, offset, buf, count, datatype, status, ierror)
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
        END SUBROUTINE PMPIR_File_read_at_all_f08ts
        
        SUBROUTINE PMPIR_File_read_at_all_c_f08ts(fh, offset, buf, count, datatype, status, ierror)
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
        END SUBROUTINE PMPIR_File_read_at_all_c_f08ts
    END INTERFACE PMPI_File_read_at_all
    
    INTERFACE PMPI_File_read_at_all_begin
        SUBROUTINE PMPIR_File_read_at_all_begin_f08ts(fh, offset, buf, count, datatype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_read_at_all_begin_f08ts
        
        SUBROUTINE PMPIR_File_read_at_all_begin_c_f08ts(fh, offset, buf, count, datatype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND, MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_read_at_all_begin_c_f08ts
    END INTERFACE PMPI_File_read_at_all_begin
    
    INTERFACE PMPI_File_read_at_all_end
        SUBROUTINE PMPIR_File_read_at_all_end_f08ts(fh, buf, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_read_at_all_end_f08ts
    END INTERFACE PMPI_File_read_at_all_end
    
    INTERFACE PMPI_File_read_ordered
        SUBROUTINE PMPIR_File_read_ordered_f08ts(fh, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_read_ordered_f08ts
        
        SUBROUTINE PMPIR_File_read_ordered_c_f08ts(fh, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..) :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_read_ordered_c_f08ts
    END INTERFACE PMPI_File_read_ordered
    
    INTERFACE PMPI_File_read_ordered_begin
        SUBROUTINE PMPIR_File_read_ordered_begin_f08ts(fh, buf, count, datatype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_read_ordered_begin_f08ts
        
        SUBROUTINE PMPIR_File_read_ordered_begin_c_f08ts(fh, buf, count, datatype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_read_ordered_begin_c_f08ts
    END INTERFACE PMPI_File_read_ordered_begin
    
    INTERFACE PMPI_File_read_ordered_end
        SUBROUTINE PMPIR_File_read_ordered_end_f08ts(fh, buf, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), ASYNCHRONOUS :: buf
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_read_ordered_end_f08ts
    END INTERFACE PMPI_File_read_ordered_end
    
    INTERFACE PMPI_File_read_shared
        SUBROUTINE PMPIR_File_read_shared_f08ts(fh, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_read_shared_f08ts
        
        SUBROUTINE PMPIR_File_read_shared_c_f08ts(fh, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..) :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_read_shared_c_f08ts
    END INTERFACE PMPI_File_read_shared
    
    INTERFACE PMPI_File_seek
        SUBROUTINE PMPIR_File_seek_f08(fh, offset, whence, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
            INTEGER, INTENT(in) :: whence
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_seek_f08
    END INTERFACE PMPI_File_seek
    
    INTERFACE PMPI_File_seek_shared
        SUBROUTINE PMPIR_File_seek_shared_f08(fh, offset, whence, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
            INTEGER, INTENT(in) :: whence
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_seek_shared_f08
    END INTERFACE PMPI_File_seek_shared
    
    INTERFACE PMPI_File_set_atomicity
        SUBROUTINE PMPIR_File_set_atomicity_f08(fh, flag, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            LOGICAL, INTENT(in) :: flag
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_set_atomicity_f08
    END INTERFACE PMPI_File_set_atomicity
    
    INTERFACE PMPI_File_set_info
        SUBROUTINE PMPIR_File_set_info_f08(fh, info, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Info
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(MPI_Info), INTENT(in) :: info
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_set_info_f08
    END INTERFACE PMPI_File_set_info
    
    INTERFACE PMPI_File_set_size
        SUBROUTINE PMPIR_File_set_size_f08(fh, size, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: size
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_set_size_f08
    END INTERFACE PMPI_File_set_size
    
    INTERFACE PMPI_File_set_view
        SUBROUTINE PMPIR_File_set_view_f08(fh, disp, etype, filetype, datarep, info, ierror)
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
        END SUBROUTINE PMPIR_File_set_view_f08
    END INTERFACE PMPI_File_set_view
    
    INTERFACE PMPI_File_sync
        SUBROUTINE PMPIR_File_sync_f08(fh, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_sync_f08
    END INTERFACE PMPI_File_sync
    
    INTERFACE PMPI_File_write
        SUBROUTINE PMPIR_File_write_f08ts(fh, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_write_f08ts
        
        SUBROUTINE PMPIR_File_write_c_f08ts(fh, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_write_c_f08ts
    END INTERFACE PMPI_File_write
    
    INTERFACE PMPI_File_write_all
        SUBROUTINE PMPIR_File_write_all_f08ts(fh, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_write_all_f08ts
        
        SUBROUTINE PMPIR_File_write_all_c_f08ts(fh, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_write_all_c_f08ts
    END INTERFACE PMPI_File_write_all
    
    INTERFACE PMPI_File_write_all_begin
        SUBROUTINE PMPIR_File_write_all_begin_f08ts(fh, buf, count, datatype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_write_all_begin_f08ts
        
        SUBROUTINE PMPIR_File_write_all_begin_c_f08ts(fh, buf, count, datatype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_write_all_begin_c_f08ts
    END INTERFACE PMPI_File_write_all_begin
    
    INTERFACE PMPI_File_write_all_end
        SUBROUTINE PMPIR_File_write_all_end_f08ts(fh, buf, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_write_all_end_f08ts
    END INTERFACE PMPI_File_write_all_end
    
    INTERFACE PMPI_File_write_at
        SUBROUTINE PMPIR_File_write_at_f08ts(fh, offset, buf, count, datatype, status, ierror)
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
        END SUBROUTINE PMPIR_File_write_at_f08ts
        
        SUBROUTINE PMPIR_File_write_at_c_f08ts(fh, offset, buf, count, datatype, status, ierror)
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
        END SUBROUTINE PMPIR_File_write_at_c_f08ts
    END INTERFACE PMPI_File_write_at
    
    INTERFACE PMPI_File_write_at_all
        SUBROUTINE PMPIR_File_write_at_all_f08ts(fh, offset, buf, count, datatype, status, ierror)
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
        END SUBROUTINE PMPIR_File_write_at_all_f08ts
        
        SUBROUTINE PMPIR_File_write_at_all_c_f08ts(fh, offset, buf, count, datatype, status, ierror)
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
        END SUBROUTINE PMPIR_File_write_at_all_c_f08ts
    END INTERFACE PMPI_File_write_at_all
    
    INTERFACE PMPI_File_write_at_all_begin
        SUBROUTINE PMPIR_File_write_at_all_begin_f08ts(fh, offset, buf, count, datatype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_write_at_all_begin_f08ts
        
        SUBROUTINE PMPIR_File_write_at_all_begin_c_f08ts(fh, offset, buf, count, datatype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND, MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            INTEGER(KIND=MPI_OFFSET_KIND), INTENT(in) :: offset
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_write_at_all_begin_c_f08ts
    END INTERFACE PMPI_File_write_at_all_begin
    
    INTERFACE PMPI_File_write_at_all_end
        SUBROUTINE PMPIR_File_write_at_all_end_f08ts(fh, buf, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_write_at_all_end_f08ts
    END INTERFACE PMPI_File_write_at_all_end
    
    INTERFACE PMPI_File_write_ordered
        SUBROUTINE PMPIR_File_write_ordered_f08ts(fh, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_write_ordered_f08ts
        
        SUBROUTINE PMPIR_File_write_ordered_c_f08ts(fh, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_write_ordered_c_f08ts
    END INTERFACE PMPI_File_write_ordered
    
    INTERFACE PMPI_File_write_ordered_begin
        SUBROUTINE PMPIR_File_write_ordered_begin_f08ts(fh, buf, count, datatype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_write_ordered_begin_f08ts
        
        SUBROUTINE PMPIR_File_write_ordered_begin_c_f08ts(fh, buf, count, datatype, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_write_ordered_begin_c_f08ts
    END INTERFACE PMPI_File_write_ordered_begin
    
    INTERFACE PMPI_File_write_ordered_end
        SUBROUTINE PMPIR_File_write_ordered_end_f08ts(fh, buf, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in), ASYNCHRONOUS :: buf
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_write_ordered_end_f08ts
    END INTERFACE PMPI_File_write_ordered_end
    
    INTERFACE PMPI_File_write_shared
        SUBROUTINE PMPIR_File_write_shared_f08ts(fh, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER, INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_write_shared_f08ts
        
        SUBROUTINE PMPIR_File_write_shared_c_f08ts(fh, buf, count, datatype, status, ierror)
            USE :: mpi_f08_types, ONLY : MPI_File, MPI_Datatype, MPI_Status
            USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
            IMPLICIT NONE
            TYPE(MPI_File), INTENT(in) :: fh
            TYPE(*), DIMENSION(..), INTENT(in) :: buf
            INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: count
            TYPE(MPI_Datatype), INTENT(in) :: datatype
            TYPE(MPI_Status), INTENT(out), TARGET :: status
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_File_write_shared_c_f08ts
    END INTERFACE PMPI_File_write_shared
    
    INTERFACE PMPI_Register_datarep
        SUBROUTINE PMPIR_Register_datarep_f08(datarep, read_conversion_fn, write_conversion_fn, &
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
        END SUBROUTINE PMPIR_Register_datarep_f08
    END INTERFACE PMPI_Register_datarep
    
    INTERFACE PMPI_Register_datarep_c
        SUBROUTINE PMPIR_Register_datarep_c_f08(datarep, read_conversion_fn, write_conversion_fn, &
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
        END SUBROUTINE PMPIR_Register_datarep_c_f08
    END INTERFACE PMPI_Register_datarep_c
    
    INTERFACE PMPI_F_sync_reg
        SUBROUTINE PMPIR_F_sync_reg_f08ts(buf, ierror)
            IMPLICIT NONE
            TYPE(*), DIMENSION(..), INTENT(inout), ASYNCHRONOUS :: buf
            INTEGER, OPTIONAL, INTENT(out) :: ierror
        END SUBROUTINE PMPIR_F_sync_reg_f08ts
    END INTERFACE PMPI_F_sync_reg
    
END MODULE pmpi_f08
