!
! Copyright (C) by Argonne National Laboratory
!     See COPYRIGHT in top-level directory
!

! -- THIS FILE IS AUTO-GENERATED -- 

module mpi_c_interface_cdesc

IMPLICIT NONE

INTERFACE

FUNCTION MPIR_Allgather_cdesc(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm) &
    bind(C, name="MPIR_Allgather_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Allgather_cdesc

FUNCTION MPIR_Allgather_cdesc_large(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
                                    comm) &
    bind(C, name="MPIR_Allgather_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Allgather_cdesc_large

FUNCTION MPIR_Allgather_init_cdesc(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, &
                                   info, request) &
    bind(C, name="MPIR_Allgather_init_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Allgather_init_cdesc

FUNCTION MPIR_Allgather_init_cdesc_large(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
                                         comm, info, request) &
    bind(C, name="MPIR_Allgather_init_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Allgather_init_cdesc_large

FUNCTION MPIR_Allgatherv_cdesc(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, &
                               comm) &
    bind(C, name="MPIR_Allgatherv_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), INTENT(in) :: recvcounts(*)
    INTEGER(c_int), INTENT(in) :: displs(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Allgatherv_cdesc

FUNCTION MPIR_Allgatherv_cdesc_large(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
                                     recvtype, comm) &
    bind(C, name="MPIR_Allgatherv_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: displs(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Allgatherv_cdesc_large

FUNCTION MPIR_Allgatherv_init_cdesc(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
                                    recvtype, comm, info, request) &
    bind(C, name="MPIR_Allgatherv_init_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), INTENT(in) :: recvcounts(*)
    INTEGER(c_int), INTENT(in) :: displs(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Allgatherv_init_cdesc

FUNCTION MPIR_Allgatherv_init_cdesc_large(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
                                          recvtype, comm, info, request) &
    bind(C, name="MPIR_Allgatherv_init_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: displs(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Allgatherv_init_cdesc_large

FUNCTION MPIR_Allreduce_cdesc(sendbuf, recvbuf, count, datatype, op, comm) &
    bind(C, name="MPIR_Allreduce_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Allreduce_cdesc

FUNCTION MPIR_Allreduce_cdesc_large(sendbuf, recvbuf, count, datatype, op, comm) &
    bind(C, name="MPIR_Allreduce_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Allreduce_cdesc_large

FUNCTION MPIR_Allreduce_init_cdesc(sendbuf, recvbuf, count, datatype, op, comm, info, request) &
    bind(C, name="MPIR_Allreduce_init_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Allreduce_init_cdesc

FUNCTION MPIR_Allreduce_init_cdesc_large(sendbuf, recvbuf, count, datatype, op, comm, info, &
                                         request) &
    bind(C, name="MPIR_Allreduce_init_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Allreduce_init_cdesc_large

FUNCTION MPIR_Alltoall_cdesc(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm) &
    bind(C, name="MPIR_Alltoall_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Alltoall_cdesc

FUNCTION MPIR_Alltoall_cdesc_large(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
                                   comm) &
    bind(C, name="MPIR_Alltoall_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Alltoall_cdesc_large

FUNCTION MPIR_Alltoall_init_cdesc(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, &
                                  info, request) &
    bind(C, name="MPIR_Alltoall_init_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Alltoall_init_cdesc

FUNCTION MPIR_Alltoall_init_cdesc_large(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
                                        comm, info, request) &
    bind(C, name="MPIR_Alltoall_init_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Alltoall_init_cdesc_large

FUNCTION MPIR_Alltoallv_cdesc(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, &
                              recvtype, comm) &
    bind(C, name="MPIR_Alltoallv_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), INTENT(in) :: sendcounts(*)
    INTEGER(c_int), INTENT(in) :: sdispls(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), INTENT(in) :: recvcounts(*)
    INTEGER(c_int), INTENT(in) :: rdispls(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Alltoallv_cdesc

FUNCTION MPIR_Alltoallv_cdesc_large(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, &
                                    rdispls, recvtype, comm) &
    bind(C, name="MPIR_Alltoallv_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: sdispls(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: rdispls(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Alltoallv_cdesc_large

FUNCTION MPIR_Alltoallv_init_cdesc(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, &
                                   rdispls, recvtype, comm, info, request) &
    bind(C, name="MPIR_Alltoallv_init_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), INTENT(in) :: sendcounts(*)
    INTEGER(c_int), INTENT(in) :: sdispls(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), INTENT(in) :: recvcounts(*)
    INTEGER(c_int), INTENT(in) :: rdispls(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Alltoallv_init_cdesc

FUNCTION MPIR_Alltoallv_init_cdesc_large(sendbuf, sendcounts, sdispls, sendtype, recvbuf, &
                                         recvcounts, rdispls, recvtype, comm, info, request) &
    bind(C, name="MPIR_Alltoallv_init_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: sdispls(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: rdispls(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Alltoallv_init_cdesc_large

FUNCTION MPIR_Alltoallw_cdesc(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, &
                              recvtypes, comm) &
    bind(C, name="MPIR_Alltoallw_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), INTENT(in) :: sendcounts(*)
    INTEGER(c_int), INTENT(in) :: sdispls(*)
    INTEGER(c_Datatype), INTENT(in) :: sendtypes(*)
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), INTENT(in) :: recvcounts(*)
    INTEGER(c_int), INTENT(in) :: rdispls(*)
    INTEGER(c_Datatype), INTENT(in) :: recvtypes(*)
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Alltoallw_cdesc

FUNCTION MPIR_Alltoallw_cdesc_large(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, &
                                    rdispls, recvtypes, comm) &
    bind(C, name="MPIR_Alltoallw_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: sdispls(*)
    INTEGER(c_Datatype), INTENT(in) :: sendtypes(*)
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: rdispls(*)
    INTEGER(c_Datatype), INTENT(in) :: recvtypes(*)
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Alltoallw_cdesc_large

FUNCTION MPIR_Alltoallw_init_cdesc(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, &
                                   rdispls, recvtypes, comm, info, request) &
    bind(C, name="MPIR_Alltoallw_init_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), INTENT(in) :: sendcounts(*)
    INTEGER(c_int), INTENT(in) :: sdispls(*)
    INTEGER(c_Datatype), INTENT(in) :: sendtypes(*)
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), INTENT(in) :: recvcounts(*)
    INTEGER(c_int), INTENT(in) :: rdispls(*)
    INTEGER(c_Datatype), INTENT(in) :: recvtypes(*)
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Alltoallw_init_cdesc

FUNCTION MPIR_Alltoallw_init_cdesc_large(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, &
                                         recvcounts, rdispls, recvtypes, comm, info, request) &
    bind(C, name="MPIR_Alltoallw_init_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: sdispls(*)
    INTEGER(c_Datatype), INTENT(in) :: sendtypes(*)
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: rdispls(*)
    INTEGER(c_Datatype), INTENT(in) :: recvtypes(*)
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Alltoallw_init_cdesc_large

FUNCTION MPIR_Bcast_cdesc(buffer, count, datatype, root, comm) &
    bind(C, name="MPIR_Bcast_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: buffer
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Bcast_cdesc

FUNCTION MPIR_Bcast_cdesc_large(buffer, count, datatype, root, comm) &
    bind(C, name="MPIR_Bcast_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: buffer
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Bcast_cdesc_large

FUNCTION MPIR_Bcast_init_cdesc(buffer, count, datatype, root, comm, info, request) &
    bind(C, name="MPIR_Bcast_init_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: buffer
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Bcast_init_cdesc

FUNCTION MPIR_Bcast_init_cdesc_large(buffer, count, datatype, root, comm, info, request) &
    bind(C, name="MPIR_Bcast_init_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: buffer
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Bcast_init_cdesc_large

FUNCTION MPIR_Exscan_cdesc(sendbuf, recvbuf, count, datatype, op, comm) &
    bind(C, name="MPIR_Exscan_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Exscan_cdesc

FUNCTION MPIR_Exscan_cdesc_large(sendbuf, recvbuf, count, datatype, op, comm) &
    bind(C, name="MPIR_Exscan_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Exscan_cdesc_large

FUNCTION MPIR_Exscan_init_cdesc(sendbuf, recvbuf, count, datatype, op, comm, info, request) &
    bind(C, name="MPIR_Exscan_init_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Exscan_init_cdesc

FUNCTION MPIR_Exscan_init_cdesc_large(sendbuf, recvbuf, count, datatype, op, comm, info, request) &
    bind(C, name="MPIR_Exscan_init_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Exscan_init_cdesc_large

FUNCTION MPIR_Gather_cdesc(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, &
                           comm) &
    bind(C, name="MPIR_Gather_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Gather_cdesc

FUNCTION MPIR_Gather_cdesc_large(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, &
                                 comm) &
    bind(C, name="MPIR_Gather_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Gather_cdesc_large

FUNCTION MPIR_Gather_init_cdesc(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, &
                                comm, info, request) &
    bind(C, name="MPIR_Gather_init_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Gather_init_cdesc

FUNCTION MPIR_Gather_init_cdesc_large(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
                                      root, comm, info, request) &
    bind(C, name="MPIR_Gather_init_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Gather_init_cdesc_large

FUNCTION MPIR_Gatherv_cdesc(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, &
                            root, comm) &
    bind(C, name="MPIR_Gatherv_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), INTENT(in) :: recvcounts(*)
    INTEGER(c_int), INTENT(in) :: displs(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Gatherv_cdesc

FUNCTION MPIR_Gatherv_cdesc_large(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
                                  recvtype, root, comm) &
    bind(C, name="MPIR_Gatherv_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: displs(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Gatherv_cdesc_large

FUNCTION MPIR_Gatherv_init_cdesc(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
                                 recvtype, root, comm, info, request) &
    bind(C, name="MPIR_Gatherv_init_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), INTENT(in) :: recvcounts(*)
    INTEGER(c_int), INTENT(in) :: displs(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Gatherv_init_cdesc

FUNCTION MPIR_Gatherv_init_cdesc_large(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
                                       recvtype, root, comm, info, request) &
    bind(C, name="MPIR_Gatherv_init_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: displs(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Gatherv_init_cdesc_large

FUNCTION MPIR_Iallgather_cdesc(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, &
                               request) &
    bind(C, name="MPIR_Iallgather_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Iallgather_cdesc

FUNCTION MPIR_Iallgather_cdesc_large(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
                                     comm, request) &
    bind(C, name="MPIR_Iallgather_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Iallgather_cdesc_large

FUNCTION MPIR_Iallgatherv_cdesc(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, &
                                comm, request) &
    bind(C, name="MPIR_Iallgatherv_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), INTENT(in) :: recvcounts(*)
    INTEGER(c_int), INTENT(in) :: displs(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Iallgatherv_cdesc

FUNCTION MPIR_Iallgatherv_cdesc_large(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
                                      recvtype, comm, request) &
    bind(C, name="MPIR_Iallgatherv_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: displs(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Iallgatherv_cdesc_large

FUNCTION MPIR_Iallreduce_cdesc(sendbuf, recvbuf, count, datatype, op, comm, request) &
    bind(C, name="MPIR_Iallreduce_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Iallreduce_cdesc

FUNCTION MPIR_Iallreduce_cdesc_large(sendbuf, recvbuf, count, datatype, op, comm, request) &
    bind(C, name="MPIR_Iallreduce_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Iallreduce_cdesc_large

FUNCTION MPIR_Ialltoall_cdesc(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, &
                              request) &
    bind(C, name="MPIR_Ialltoall_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Ialltoall_cdesc

FUNCTION MPIR_Ialltoall_cdesc_large(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
                                    comm, request) &
    bind(C, name="MPIR_Ialltoall_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Ialltoall_cdesc_large

FUNCTION MPIR_Ialltoallv_cdesc(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, &
                               recvtype, comm, request) &
    bind(C, name="MPIR_Ialltoallv_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), INTENT(in) :: sendcounts(*)
    INTEGER(c_int), INTENT(in) :: sdispls(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), INTENT(in) :: recvcounts(*)
    INTEGER(c_int), INTENT(in) :: rdispls(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Ialltoallv_cdesc

FUNCTION MPIR_Ialltoallv_cdesc_large(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, &
                                     rdispls, recvtype, comm, request) &
    bind(C, name="MPIR_Ialltoallv_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: sdispls(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: rdispls(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Ialltoallv_cdesc_large

FUNCTION MPIR_Ialltoallw_cdesc(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, &
                               rdispls, recvtypes, comm, request) &
    bind(C, name="MPIR_Ialltoallw_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), INTENT(in) :: sendcounts(*)
    INTEGER(c_int), INTENT(in) :: sdispls(*)
    INTEGER(c_Datatype), INTENT(in) :: sendtypes(*)
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), INTENT(in) :: recvcounts(*)
    INTEGER(c_int), INTENT(in) :: rdispls(*)
    INTEGER(c_Datatype), INTENT(in) :: recvtypes(*)
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Ialltoallw_cdesc

FUNCTION MPIR_Ialltoallw_cdesc_large(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, &
                                     rdispls, recvtypes, comm, request) &
    bind(C, name="MPIR_Ialltoallw_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: sdispls(*)
    INTEGER(c_Datatype), INTENT(in) :: sendtypes(*)
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: rdispls(*)
    INTEGER(c_Datatype), INTENT(in) :: recvtypes(*)
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Ialltoallw_cdesc_large

FUNCTION MPIR_Ibcast_cdesc(buffer, count, datatype, root, comm, request) &
    bind(C, name="MPIR_Ibcast_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: buffer
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Ibcast_cdesc

FUNCTION MPIR_Ibcast_cdesc_large(buffer, count, datatype, root, comm, request) &
    bind(C, name="MPIR_Ibcast_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: buffer
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Ibcast_cdesc_large

FUNCTION MPIR_Iexscan_cdesc(sendbuf, recvbuf, count, datatype, op, comm, request) &
    bind(C, name="MPIR_Iexscan_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Iexscan_cdesc

FUNCTION MPIR_Iexscan_cdesc_large(sendbuf, recvbuf, count, datatype, op, comm, request) &
    bind(C, name="MPIR_Iexscan_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Iexscan_cdesc_large

FUNCTION MPIR_Igather_cdesc(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, &
                            request) &
    bind(C, name="MPIR_Igather_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Igather_cdesc

FUNCTION MPIR_Igather_cdesc_large(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, &
                                  comm, request) &
    bind(C, name="MPIR_Igather_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Igather_cdesc_large

FUNCTION MPIR_Igatherv_cdesc(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, &
                             root, comm, request) &
    bind(C, name="MPIR_Igatherv_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), INTENT(in) :: recvcounts(*)
    INTEGER(c_int), INTENT(in) :: displs(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Igatherv_cdesc

FUNCTION MPIR_Igatherv_cdesc_large(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
                                   recvtype, root, comm, request) &
    bind(C, name="MPIR_Igatherv_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: displs(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Igatherv_cdesc_large

FUNCTION MPIR_Ineighbor_allgather_cdesc(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
                                        comm, request) &
    bind(C, name="MPIR_Ineighbor_allgather_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Ineighbor_allgather_cdesc

FUNCTION MPIR_Ineighbor_allgather_cdesc_large(sendbuf, sendcount, sendtype, recvbuf, recvcount, &
                                              recvtype, comm, request) &
    bind(C, name="MPIR_Ineighbor_allgather_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Ineighbor_allgather_cdesc_large

FUNCTION MPIR_Ineighbor_allgatherv_cdesc(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
                                         recvtype, comm, request) &
    bind(C, name="MPIR_Ineighbor_allgatherv_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), INTENT(in) :: recvcounts(*)
    INTEGER(c_int), INTENT(in) :: displs(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Ineighbor_allgatherv_cdesc

FUNCTION MPIR_Ineighbor_allgatherv_cdesc_large(sendbuf, sendcount, sendtype, recvbuf, recvcounts, &
                                               displs, recvtype, comm, request) &
    bind(C, name="MPIR_Ineighbor_allgatherv_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: displs(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Ineighbor_allgatherv_cdesc_large

FUNCTION MPIR_Ineighbor_alltoall_cdesc(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
                                       comm, request) &
    bind(C, name="MPIR_Ineighbor_alltoall_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Ineighbor_alltoall_cdesc

FUNCTION MPIR_Ineighbor_alltoall_cdesc_large(sendbuf, sendcount, sendtype, recvbuf, recvcount, &
                                             recvtype, comm, request) &
    bind(C, name="MPIR_Ineighbor_alltoall_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Ineighbor_alltoall_cdesc_large

FUNCTION MPIR_Ineighbor_alltoallv_cdesc(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, &
                                        rdispls, recvtype, comm, request) &
    bind(C, name="MPIR_Ineighbor_alltoallv_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), INTENT(in) :: sendcounts(*)
    INTEGER(c_int), INTENT(in) :: sdispls(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), INTENT(in) :: recvcounts(*)
    INTEGER(c_int), INTENT(in) :: rdispls(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Ineighbor_alltoallv_cdesc

FUNCTION MPIR_Ineighbor_alltoallv_cdesc_large(sendbuf, sendcounts, sdispls, sendtype, recvbuf, &
                                              recvcounts, rdispls, recvtype, comm, request) &
    bind(C, name="MPIR_Ineighbor_alltoallv_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: sdispls(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: rdispls(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Ineighbor_alltoallv_cdesc_large

FUNCTION MPIR_Ineighbor_alltoallw_cdesc(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, &
                                        recvcounts, rdispls, recvtypes, comm, request) &
    bind(C, name="MPIR_Ineighbor_alltoallw_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), INTENT(in) :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: sdispls(*)
    INTEGER(c_Datatype), INTENT(in) :: sendtypes(*)
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), INTENT(in) :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: rdispls(*)
    INTEGER(c_Datatype), INTENT(in) :: recvtypes(*)
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Ineighbor_alltoallw_cdesc

FUNCTION MPIR_Ineighbor_alltoallw_cdesc_large(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, &
                                              recvcounts, rdispls, recvtypes, comm, request) &
    bind(C, name="MPIR_Ineighbor_alltoallw_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: sdispls(*)
    INTEGER(c_Datatype), INTENT(in) :: sendtypes(*)
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: rdispls(*)
    INTEGER(c_Datatype), INTENT(in) :: recvtypes(*)
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Ineighbor_alltoallw_cdesc_large

FUNCTION MPIR_Ireduce_cdesc(sendbuf, recvbuf, count, datatype, op, root, comm, request) &
    bind(C, name="MPIR_Ireduce_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Ireduce_cdesc

FUNCTION MPIR_Ireduce_cdesc_large(sendbuf, recvbuf, count, datatype, op, root, comm, request) &
    bind(C, name="MPIR_Ireduce_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Ireduce_cdesc_large

FUNCTION MPIR_Ireduce_scatter_cdesc(sendbuf, recvbuf, recvcounts, datatype, op, comm, request) &
    bind(C, name="MPIR_Ireduce_scatter_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), INTENT(in) :: recvcounts(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Ireduce_scatter_cdesc

FUNCTION MPIR_Ireduce_scatter_cdesc_large(sendbuf, recvbuf, recvcounts, datatype, op, comm, &
                                          request) &
    bind(C, name="MPIR_Ireduce_scatter_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Ireduce_scatter_cdesc_large

FUNCTION MPIR_Ireduce_scatter_block_cdesc(sendbuf, recvbuf, recvcount, datatype, op, comm, &
                                          request) &
    bind(C, name="MPIR_Ireduce_scatter_block_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Ireduce_scatter_block_cdesc

FUNCTION MPIR_Ireduce_scatter_block_cdesc_large(sendbuf, recvbuf, recvcount, datatype, op, comm, &
                                                request) &
    bind(C, name="MPIR_Ireduce_scatter_block_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Ireduce_scatter_block_cdesc_large

FUNCTION MPIR_Iscan_cdesc(sendbuf, recvbuf, count, datatype, op, comm, request) &
    bind(C, name="MPIR_Iscan_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Iscan_cdesc

FUNCTION MPIR_Iscan_cdesc_large(sendbuf, recvbuf, count, datatype, op, comm, request) &
    bind(C, name="MPIR_Iscan_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Iscan_cdesc_large

FUNCTION MPIR_Iscatter_cdesc(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, &
                             request) &
    bind(C, name="MPIR_Iscatter_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Iscatter_cdesc

FUNCTION MPIR_Iscatter_cdesc_large(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, &
                                   comm, request) &
    bind(C, name="MPIR_Iscatter_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Iscatter_cdesc_large

FUNCTION MPIR_Iscatterv_cdesc(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, &
                              root, comm, request) &
    bind(C, name="MPIR_Iscatterv_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), INTENT(in) :: sendcounts(*)
    INTEGER(c_int), INTENT(in) :: displs(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Iscatterv_cdesc

FUNCTION MPIR_Iscatterv_cdesc_large(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, &
                                    recvtype, root, comm, request) &
    bind(C, name="MPIR_Iscatterv_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: displs(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Iscatterv_cdesc_large

FUNCTION MPIR_Neighbor_allgather_cdesc(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
                                       comm) &
    bind(C, name="MPIR_Neighbor_allgather_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Neighbor_allgather_cdesc

FUNCTION MPIR_Neighbor_allgather_cdesc_large(sendbuf, sendcount, sendtype, recvbuf, recvcount, &
                                             recvtype, comm) &
    bind(C, name="MPIR_Neighbor_allgather_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Neighbor_allgather_cdesc_large

FUNCTION MPIR_Neighbor_allgather_init_cdesc(sendbuf, sendcount, sendtype, recvbuf, recvcount, &
                                            recvtype, comm, info, request) &
    bind(C, name="MPIR_Neighbor_allgather_init_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Neighbor_allgather_init_cdesc

FUNCTION MPIR_Neighbor_allgather_init_cdesc_large(sendbuf, sendcount, sendtype, recvbuf, recvcount, &
                                                  recvtype, comm, info, request) &
    bind(C, name="MPIR_Neighbor_allgather_init_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Neighbor_allgather_init_cdesc_large

FUNCTION MPIR_Neighbor_allgatherv_cdesc(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, &
                                        recvtype, comm) &
    bind(C, name="MPIR_Neighbor_allgatherv_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), INTENT(in) :: recvcounts(*)
    INTEGER(c_int), INTENT(in) :: displs(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Neighbor_allgatherv_cdesc

FUNCTION MPIR_Neighbor_allgatherv_cdesc_large(sendbuf, sendcount, sendtype, recvbuf, recvcounts, &
                                              displs, recvtype, comm) &
    bind(C, name="MPIR_Neighbor_allgatherv_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: displs(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Neighbor_allgatherv_cdesc_large

FUNCTION MPIR_Neighbor_allgatherv_init_cdesc(sendbuf, sendcount, sendtype, recvbuf, recvcounts, &
                                             displs, recvtype, comm, info, request) &
    bind(C, name="MPIR_Neighbor_allgatherv_init_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), INTENT(in) :: recvcounts(*)
    INTEGER(c_int), INTENT(in) :: displs(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Neighbor_allgatherv_init_cdesc

FUNCTION MPIR_Neighbor_allgatherv_init_cdesc_large(sendbuf, sendcount, sendtype, recvbuf, &
                                                   recvcounts, displs, recvtype, comm, info, &
                                                   request) &
    bind(C, name="MPIR_Neighbor_allgatherv_init_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: displs(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Neighbor_allgatherv_init_cdesc_large

FUNCTION MPIR_Neighbor_alltoall_cdesc(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
                                      comm) &
    bind(C, name="MPIR_Neighbor_alltoall_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Neighbor_alltoall_cdesc

FUNCTION MPIR_Neighbor_alltoall_cdesc_large(sendbuf, sendcount, sendtype, recvbuf, recvcount, &
                                            recvtype, comm) &
    bind(C, name="MPIR_Neighbor_alltoall_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Neighbor_alltoall_cdesc_large

FUNCTION MPIR_Neighbor_alltoall_init_cdesc(sendbuf, sendcount, sendtype, recvbuf, recvcount, &
                                           recvtype, comm, info, request) &
    bind(C, name="MPIR_Neighbor_alltoall_init_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Neighbor_alltoall_init_cdesc

FUNCTION MPIR_Neighbor_alltoall_init_cdesc_large(sendbuf, sendcount, sendtype, recvbuf, recvcount, &
                                                 recvtype, comm, info, request) &
    bind(C, name="MPIR_Neighbor_alltoall_init_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Neighbor_alltoall_init_cdesc_large

FUNCTION MPIR_Neighbor_alltoallv_cdesc(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, &
                                       rdispls, recvtype, comm) &
    bind(C, name="MPIR_Neighbor_alltoallv_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), INTENT(in) :: sendcounts(*)
    INTEGER(c_int), INTENT(in) :: sdispls(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), INTENT(in) :: recvcounts(*)
    INTEGER(c_int), INTENT(in) :: rdispls(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Neighbor_alltoallv_cdesc

FUNCTION MPIR_Neighbor_alltoallv_cdesc_large(sendbuf, sendcounts, sdispls, sendtype, recvbuf, &
                                             recvcounts, rdispls, recvtype, comm) &
    bind(C, name="MPIR_Neighbor_alltoallv_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: sdispls(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: rdispls(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Neighbor_alltoallv_cdesc_large

FUNCTION MPIR_Neighbor_alltoallv_init_cdesc(sendbuf, sendcounts, sdispls, sendtype, recvbuf, &
                                            recvcounts, rdispls, recvtype, comm, info, request) &
    bind(C, name="MPIR_Neighbor_alltoallv_init_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), INTENT(in) :: sendcounts(*)
    INTEGER(c_int), INTENT(in) :: sdispls(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), INTENT(in) :: recvcounts(*)
    INTEGER(c_int), INTENT(in) :: rdispls(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Neighbor_alltoallv_init_cdesc

FUNCTION MPIR_Neighbor_alltoallv_init_cdesc_large(sendbuf, sendcounts, sdispls, sendtype, recvbuf, &
                                                  recvcounts, rdispls, recvtype, comm, info, &
                                                  request) &
    bind(C, name="MPIR_Neighbor_alltoallv_init_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: sdispls(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: rdispls(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Neighbor_alltoallv_init_cdesc_large

FUNCTION MPIR_Neighbor_alltoallw_cdesc(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, &
                                       rdispls, recvtypes, comm) &
    bind(C, name="MPIR_Neighbor_alltoallw_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), INTENT(in) :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: sdispls(*)
    INTEGER(c_Datatype), INTENT(in) :: sendtypes(*)
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), INTENT(in) :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: rdispls(*)
    INTEGER(c_Datatype), INTENT(in) :: recvtypes(*)
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Neighbor_alltoallw_cdesc

FUNCTION MPIR_Neighbor_alltoallw_cdesc_large(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, &
                                             recvcounts, rdispls, recvtypes, comm) &
    bind(C, name="MPIR_Neighbor_alltoallw_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: sdispls(*)
    INTEGER(c_Datatype), INTENT(in) :: sendtypes(*)
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: rdispls(*)
    INTEGER(c_Datatype), INTENT(in) :: recvtypes(*)
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Neighbor_alltoallw_cdesc_large

FUNCTION MPIR_Neighbor_alltoallw_init_cdesc(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, &
                                            recvcounts, rdispls, recvtypes, comm, info, request) &
    bind(C, name="MPIR_Neighbor_alltoallw_init_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), INTENT(in) :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: sdispls(*)
    INTEGER(c_Datatype), INTENT(in) :: sendtypes(*)
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), INTENT(in) :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: rdispls(*)
    INTEGER(c_Datatype), INTENT(in) :: recvtypes(*)
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Neighbor_alltoallw_init_cdesc

FUNCTION MPIR_Neighbor_alltoallw_init_cdesc_large(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, &
                                                  recvcounts, rdispls, recvtypes, comm, info, &
                                                  request) &
    bind(C, name="MPIR_Neighbor_alltoallw_init_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: sdispls(*)
    INTEGER(c_Datatype), INTENT(in) :: sendtypes(*)
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: rdispls(*)
    INTEGER(c_Datatype), INTENT(in) :: recvtypes(*)
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Neighbor_alltoallw_init_cdesc_large

FUNCTION MPIR_Reduce_cdesc(sendbuf, recvbuf, count, datatype, op, root, comm) &
    bind(C, name="MPIR_Reduce_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Reduce_cdesc

FUNCTION MPIR_Reduce_cdesc_large(sendbuf, recvbuf, count, datatype, op, root, comm) &
    bind(C, name="MPIR_Reduce_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Reduce_cdesc_large

FUNCTION MPIR_Reduce_init_cdesc(sendbuf, recvbuf, count, datatype, op, root, comm, info, request) &
    bind(C, name="MPIR_Reduce_init_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Reduce_init_cdesc

FUNCTION MPIR_Reduce_init_cdesc_large(sendbuf, recvbuf, count, datatype, op, root, comm, info, &
                                      request) &
    bind(C, name="MPIR_Reduce_init_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Reduce_init_cdesc_large

FUNCTION MPIR_Reduce_local_cdesc(inbuf, inoutbuf, count, datatype, op) &
    bind(C, name="MPIR_Reduce_local_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: inbuf
    TYPE(*), DIMENSION(..) :: inoutbuf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Reduce_local_cdesc

FUNCTION MPIR_Reduce_local_cdesc_large(inbuf, inoutbuf, count, datatype, op) &
    bind(C, name="MPIR_Reduce_local_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: inbuf
    TYPE(*), DIMENSION(..) :: inoutbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Reduce_local_cdesc_large

FUNCTION MPIR_Reduce_scatter_cdesc(sendbuf, recvbuf, recvcounts, datatype, op, comm) &
    bind(C, name="MPIR_Reduce_scatter_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), INTENT(in) :: recvcounts(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Reduce_scatter_cdesc

FUNCTION MPIR_Reduce_scatter_cdesc_large(sendbuf, recvbuf, recvcounts, datatype, op, comm) &
    bind(C, name="MPIR_Reduce_scatter_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Reduce_scatter_cdesc_large

FUNCTION MPIR_Reduce_scatter_block_cdesc(sendbuf, recvbuf, recvcount, datatype, op, comm) &
    bind(C, name="MPIR_Reduce_scatter_block_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Reduce_scatter_block_cdesc

FUNCTION MPIR_Reduce_scatter_block_cdesc_large(sendbuf, recvbuf, recvcount, datatype, op, comm) &
    bind(C, name="MPIR_Reduce_scatter_block_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Reduce_scatter_block_cdesc_large

FUNCTION MPIR_Reduce_scatter_block_init_cdesc(sendbuf, recvbuf, recvcount, datatype, op, comm, info, &
                                              request) &
    bind(C, name="MPIR_Reduce_scatter_block_init_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Reduce_scatter_block_init_cdesc

FUNCTION MPIR_Reduce_scatter_block_init_cdesc_large(sendbuf, recvbuf, recvcount, datatype, op, comm, &
                                                    info, request) &
    bind(C, name="MPIR_Reduce_scatter_block_init_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Reduce_scatter_block_init_cdesc_large

FUNCTION MPIR_Reduce_scatter_init_cdesc(sendbuf, recvbuf, recvcounts, datatype, op, comm, info, &
                                        request) &
    bind(C, name="MPIR_Reduce_scatter_init_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), INTENT(in) :: recvcounts(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Reduce_scatter_init_cdesc

FUNCTION MPIR_Reduce_scatter_init_cdesc_large(sendbuf, recvbuf, recvcounts, datatype, op, comm, &
                                              info, request) &
    bind(C, name="MPIR_Reduce_scatter_init_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: recvcounts(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Reduce_scatter_init_cdesc_large

FUNCTION MPIR_Scan_cdesc(sendbuf, recvbuf, count, datatype, op, comm) &
    bind(C, name="MPIR_Scan_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Scan_cdesc

FUNCTION MPIR_Scan_cdesc_large(sendbuf, recvbuf, count, datatype, op, comm) &
    bind(C, name="MPIR_Scan_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Scan_cdesc_large

FUNCTION MPIR_Scan_init_cdesc(sendbuf, recvbuf, count, datatype, op, comm, info, request) &
    bind(C, name="MPIR_Scan_init_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Scan_init_cdesc

FUNCTION MPIR_Scan_init_cdesc_large(sendbuf, recvbuf, count, datatype, op, comm, info, request) &
    bind(C, name="MPIR_Scan_init_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Scan_init_cdesc_large

FUNCTION MPIR_Scatter_cdesc(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, &
                            comm) &
    bind(C, name="MPIR_Scatter_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Scatter_cdesc

FUNCTION MPIR_Scatter_cdesc_large(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, &
                                  comm) &
    bind(C, name="MPIR_Scatter_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Scatter_cdesc_large

FUNCTION MPIR_Scatter_init_cdesc(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, &
                                 comm, info, request) &
    bind(C, name="MPIR_Scatter_init_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Scatter_init_cdesc

FUNCTION MPIR_Scatter_init_cdesc_large(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, &
                                       root, comm, info, request) &
    bind(C, name="MPIR_Scatter_init_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Scatter_init_cdesc_large

FUNCTION MPIR_Scatterv_cdesc(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, &
                             root, comm) &
    bind(C, name="MPIR_Scatterv_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), INTENT(in) :: sendcounts(*)
    INTEGER(c_int), INTENT(in) :: displs(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Scatterv_cdesc

FUNCTION MPIR_Scatterv_cdesc_large(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, &
                                   recvtype, root, comm) &
    bind(C, name="MPIR_Scatterv_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: displs(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Scatterv_cdesc_large

FUNCTION MPIR_Scatterv_init_cdesc(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, &
                                  recvtype, root, comm, info, request) &
    bind(C, name="MPIR_Scatterv_init_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), INTENT(in) :: sendcounts(*)
    INTEGER(c_int), INTENT(in) :: displs(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Scatterv_init_cdesc

FUNCTION MPIR_Scatterv_init_cdesc_large(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, &
                                        recvtype, root, comm, info, request) &
    bind(C, name="MPIR_Scatterv_init_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(in) :: sendcounts(*)
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(in) :: displs(*)
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_int), VALUE, INTENT(in) :: root
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Scatterv_init_cdesc_large

FUNCTION MPIR_Get_address_cdesc(location, address) &
    bind(C, name="MPIR_Get_address_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: location
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(out) :: address
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Get_address_cdesc

FUNCTION MPIR_Pack_cdesc(inbuf, incount, datatype, outbuf, outsize, position, comm) &
    bind(C, name="MPIR_Pack_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: inbuf
    INTEGER(c_int), VALUE, INTENT(in) :: incount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    TYPE(*), DIMENSION(..) :: outbuf
    INTEGER(c_int), VALUE, INTENT(in) :: outsize
    INTEGER(c_int), INTENT(inout) :: position
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Pack_cdesc

FUNCTION MPIR_Pack_cdesc_large(inbuf, incount, datatype, outbuf, outsize, position, comm) &
    bind(C, name="MPIR_Pack_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: inbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: incount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    TYPE(*), DIMENSION(..) :: outbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: outsize
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(inout) :: position
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Pack_cdesc_large

FUNCTION MPIR_Pack_external_cdesc(datarep, inbuf, incount, datatype, outbuf, outsize, position) &
    bind(C, name="MPIR_Pack_external_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    character(kind=c_char), INTENT(in) :: datarep(*)
    TYPE(*), DIMENSION(..), INTENT(in) :: inbuf
    INTEGER(c_int), VALUE, INTENT(in) :: incount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    TYPE(*), DIMENSION(..) :: outbuf
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: outsize
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(inout) :: position
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Pack_external_cdesc

FUNCTION MPIR_Pack_external_cdesc_large(datarep, inbuf, incount, datatype, outbuf, outsize, &
                                        position) &
    bind(C, name="MPIR_Pack_external_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    character(kind=c_char), INTENT(in) :: datarep(*)
    TYPE(*), DIMENSION(..), INTENT(in) :: inbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: incount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    TYPE(*), DIMENSION(..) :: outbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: outsize
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(inout) :: position
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Pack_external_cdesc_large

FUNCTION MPIR_Unpack_cdesc(inbuf, insize, position, outbuf, outcount, datatype, comm) &
    bind(C, name="MPIR_Unpack_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: inbuf
    INTEGER(c_int), VALUE, INTENT(in) :: insize
    INTEGER(c_int), INTENT(inout) :: position
    TYPE(*), DIMENSION(..) :: outbuf
    INTEGER(c_int), VALUE, INTENT(in) :: outcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Unpack_cdesc

FUNCTION MPIR_Unpack_cdesc_large(inbuf, insize, position, outbuf, outcount, datatype, comm) &
    bind(C, name="MPIR_Unpack_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: inbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: insize
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(inout) :: position
    TYPE(*), DIMENSION(..) :: outbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: outcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Unpack_cdesc_large

FUNCTION MPIR_Unpack_external_cdesc(datarep, inbuf, insize, position, outbuf, outcount, datatype) &
    bind(C, name="MPIR_Unpack_external_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    character(kind=c_char), INTENT(in) :: datarep(*)
    TYPE(*), DIMENSION(..), INTENT(in) :: inbuf
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: insize
    INTEGER(KIND=MPI_ADDRESS_KIND), INTENT(inout) :: position
    TYPE(*), DIMENSION(..) :: outbuf
    INTEGER(c_int), VALUE, INTENT(in) :: outcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Unpack_external_cdesc

FUNCTION MPIR_Unpack_external_cdesc_large(datarep, inbuf, insize, position, outbuf, outcount, &
                                          datatype) &
    bind(C, name="MPIR_Unpack_external_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype
    IMPLICIT NONE
    character(kind=c_char), INTENT(in) :: datarep(*)
    TYPE(*), DIMENSION(..), INTENT(in) :: inbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: insize
    INTEGER(KIND=MPI_COUNT_KIND), INTENT(inout) :: position
    TYPE(*), DIMENSION(..) :: outbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: outcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Unpack_external_cdesc_large

FUNCTION MPIR_Info_set_hex_cdesc(info, key, value, value_size) &
    bind(C, name="MPIR_Info_set_hex_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_char
    USE :: mpi_c_interface_types, ONLY : c_Info
    IMPLICIT NONE
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    character(kind=c_char), INTENT(in) :: key(*)
    TYPE(*), DIMENSION(..), INTENT(in) :: value
    INTEGER(c_int), VALUE, INTENT(in) :: value_size
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Info_set_hex_cdesc

FUNCTION MPIR_Precv_init_cdesc(buf, partitions, count, datatype, dest, tag, comm, info, request) &
    bind(C, name="MPIR_Precv_init_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: partitions
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Precv_init_cdesc

FUNCTION MPIR_Psend_init_cdesc(buf, partitions, count, datatype, dest, tag, comm, info, request) &
    bind(C, name="MPIR_Psend_init_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Info, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: partitions
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Psend_init_cdesc

FUNCTION MPIR_Bsend_cdesc(buf, count, datatype, dest, tag, comm) &
    bind(C, name="MPIR_Bsend_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Bsend_cdesc

FUNCTION MPIR_Bsend_cdesc_large(buf, count, datatype, dest, tag, comm) &
    bind(C, name="MPIR_Bsend_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Bsend_cdesc_large

FUNCTION MPIR_Bsend_init_cdesc(buf, count, datatype, dest, tag, comm, request) &
    bind(C, name="MPIR_Bsend_init_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Bsend_init_cdesc

FUNCTION MPIR_Bsend_init_cdesc_large(buf, count, datatype, dest, tag, comm, request) &
    bind(C, name="MPIR_Bsend_init_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Bsend_init_cdesc_large

FUNCTION MPIR_Buffer_attach_cdesc(buffer, size) &
    bind(C, name="MPIR_Buffer_attach_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buffer
    INTEGER(c_int), VALUE, INTENT(in) :: size
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Buffer_attach_cdesc

FUNCTION MPIR_Buffer_attach_cdesc_large(buffer, size) &
    bind(C, name="MPIR_Buffer_attach_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buffer
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: size
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Buffer_attach_cdesc_large

FUNCTION MPIR_Comm_attach_buffer_cdesc(comm, buffer, size) &
    bind(C, name="MPIR_Comm_attach_buffer_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    TYPE(*), DIMENSION(..), INTENT(in) :: buffer
    INTEGER(c_int), VALUE, INTENT(in) :: size
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_attach_buffer_cdesc

FUNCTION MPIR_Comm_attach_buffer_cdesc_large(comm, buffer, size) &
    bind(C, name="MPIR_Comm_attach_buffer_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Comm
    IMPLICIT NONE
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    TYPE(*), DIMENSION(..), INTENT(in) :: buffer
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: size
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Comm_attach_buffer_cdesc_large

FUNCTION MPIR_Ibsend_cdesc(buf, count, datatype, dest, tag, comm, request) &
    bind(C, name="MPIR_Ibsend_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Ibsend_cdesc

FUNCTION MPIR_Ibsend_cdesc_large(buf, count, datatype, dest, tag, comm, request) &
    bind(C, name="MPIR_Ibsend_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Ibsend_cdesc_large

FUNCTION MPIR_Imrecv_cdesc(buf, count, datatype, message, request) &
    bind(C, name="MPIR_Imrecv_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Message, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Message), INTENT(inout) :: message
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Imrecv_cdesc

FUNCTION MPIR_Imrecv_cdesc_large(buf, count, datatype, message, request) &
    bind(C, name="MPIR_Imrecv_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Message, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Message), INTENT(inout) :: message
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Imrecv_cdesc_large

FUNCTION MPIR_Irecv_cdesc(buf, count, datatype, source, tag, comm, request) &
    bind(C, name="MPIR_Irecv_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: source
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Irecv_cdesc

FUNCTION MPIR_Irecv_cdesc_large(buf, count, datatype, source, tag, comm, request) &
    bind(C, name="MPIR_Irecv_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: source
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Irecv_cdesc_large

FUNCTION MPIR_Irsend_cdesc(buf, count, datatype, dest, tag, comm, request) &
    bind(C, name="MPIR_Irsend_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Irsend_cdesc

FUNCTION MPIR_Irsend_cdesc_large(buf, count, datatype, dest, tag, comm, request) &
    bind(C, name="MPIR_Irsend_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Irsend_cdesc_large

FUNCTION MPIR_Isend_cdesc(buf, count, datatype, dest, tag, comm, request) &
    bind(C, name="MPIR_Isend_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Isend_cdesc

FUNCTION MPIR_Isend_cdesc_large(buf, count, datatype, dest, tag, comm, request) &
    bind(C, name="MPIR_Isend_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Isend_cdesc_large

FUNCTION MPIR_Isendrecv_cdesc(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, &
                              recvtype, source, recvtag, comm, request) &
    bind(C, name="MPIR_Isendrecv_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: sendtag
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_int), VALUE, INTENT(in) :: source
    INTEGER(c_int), VALUE, INTENT(in) :: recvtag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Isendrecv_cdesc

FUNCTION MPIR_Isendrecv_cdesc_large(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, &
                                    recvtype, source, recvtag, comm, request) &
    bind(C, name="MPIR_Isendrecv_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: sendtag
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_int), VALUE, INTENT(in) :: source
    INTEGER(c_int), VALUE, INTENT(in) :: recvtag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Isendrecv_cdesc_large

FUNCTION MPIR_Isendrecv_replace_cdesc(buf, count, datatype, dest, sendtag, source, recvtag, comm, &
                                      request) &
    bind(C, name="MPIR_Isendrecv_replace_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: sendtag
    INTEGER(c_int), VALUE, INTENT(in) :: source
    INTEGER(c_int), VALUE, INTENT(in) :: recvtag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Isendrecv_replace_cdesc

FUNCTION MPIR_Isendrecv_replace_cdesc_large(buf, count, datatype, dest, sendtag, source, recvtag, &
                                            comm, request) &
    bind(C, name="MPIR_Isendrecv_replace_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: sendtag
    INTEGER(c_int), VALUE, INTENT(in) :: source
    INTEGER(c_int), VALUE, INTENT(in) :: recvtag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Isendrecv_replace_cdesc_large

FUNCTION MPIR_Issend_cdesc(buf, count, datatype, dest, tag, comm, request) &
    bind(C, name="MPIR_Issend_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Issend_cdesc

FUNCTION MPIR_Issend_cdesc_large(buf, count, datatype, dest, tag, comm, request) &
    bind(C, name="MPIR_Issend_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Issend_cdesc_large

FUNCTION MPIR_Mrecv_cdesc(buf, count, datatype, message, status) &
    bind(C, name="MPIR_Mrecv_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Message
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Message), INTENT(inout) :: message
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Mrecv_cdesc

FUNCTION MPIR_Mrecv_cdesc_large(buf, count, datatype, message, status) &
    bind(C, name="MPIR_Mrecv_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Message
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Message), INTENT(inout) :: message
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Mrecv_cdesc_large

FUNCTION MPIR_Recv_cdesc(buf, count, datatype, source, tag, comm, status) &
    bind(C, name="MPIR_Recv_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: source
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Recv_cdesc

FUNCTION MPIR_Recv_cdesc_large(buf, count, datatype, source, tag, comm, status) &
    bind(C, name="MPIR_Recv_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: source
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Recv_cdesc_large

FUNCTION MPIR_Recv_init_cdesc(buf, count, datatype, source, tag, comm, request) &
    bind(C, name="MPIR_Recv_init_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: source
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Recv_init_cdesc

FUNCTION MPIR_Recv_init_cdesc_large(buf, count, datatype, source, tag, comm, request) &
    bind(C, name="MPIR_Recv_init_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: source
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Recv_init_cdesc_large

FUNCTION MPIR_Rsend_cdesc(buf, count, datatype, dest, tag, comm) &
    bind(C, name="MPIR_Rsend_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Rsend_cdesc

FUNCTION MPIR_Rsend_cdesc_large(buf, count, datatype, dest, tag, comm) &
    bind(C, name="MPIR_Rsend_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Rsend_cdesc_large

FUNCTION MPIR_Rsend_init_cdesc(buf, count, datatype, dest, tag, comm, request) &
    bind(C, name="MPIR_Rsend_init_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Rsend_init_cdesc

FUNCTION MPIR_Rsend_init_cdesc_large(buf, count, datatype, dest, tag, comm, request) &
    bind(C, name="MPIR_Rsend_init_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Rsend_init_cdesc_large

FUNCTION MPIR_Send_cdesc(buf, count, datatype, dest, tag, comm) &
    bind(C, name="MPIR_Send_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Send_cdesc

FUNCTION MPIR_Send_cdesc_large(buf, count, datatype, dest, tag, comm) &
    bind(C, name="MPIR_Send_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Send_cdesc_large

FUNCTION MPIR_Send_init_cdesc(buf, count, datatype, dest, tag, comm, request) &
    bind(C, name="MPIR_Send_init_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Send_init_cdesc

FUNCTION MPIR_Send_init_cdesc_large(buf, count, datatype, dest, tag, comm, request) &
    bind(C, name="MPIR_Send_init_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Send_init_cdesc_large

FUNCTION MPIR_Sendrecv_cdesc(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, &
                             recvtype, source, recvtag, comm, status) &
    bind(C, name="MPIR_Sendrecv_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(c_int), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: sendtag
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_int), VALUE, INTENT(in) :: source
    INTEGER(c_int), VALUE, INTENT(in) :: recvtag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Sendrecv_cdesc

FUNCTION MPIR_Sendrecv_cdesc_large(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, &
                                   recvtype, source, recvtag, comm, status) &
    bind(C, name="MPIR_Sendrecv_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: sendcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: sendtype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: sendtag
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: recvcount
    INTEGER(c_Datatype), VALUE, INTENT(in) :: recvtype
    INTEGER(c_int), VALUE, INTENT(in) :: source
    INTEGER(c_int), VALUE, INTENT(in) :: recvtag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Sendrecv_cdesc_large

FUNCTION MPIR_Sendrecv_replace_cdesc(buf, count, datatype, dest, sendtag, source, recvtag, comm, &
                                     status) &
    bind(C, name="MPIR_Sendrecv_replace_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: sendtag
    INTEGER(c_int), VALUE, INTENT(in) :: source
    INTEGER(c_int), VALUE, INTENT(in) :: recvtag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Sendrecv_replace_cdesc

FUNCTION MPIR_Sendrecv_replace_cdesc_large(buf, count, datatype, dest, sendtag, source, recvtag, &
                                           comm, status) &
    bind(C, name="MPIR_Sendrecv_replace_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: sendtag
    INTEGER(c_int), VALUE, INTENT(in) :: source
    INTEGER(c_int), VALUE, INTENT(in) :: recvtag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Sendrecv_replace_cdesc_large

FUNCTION MPIR_Session_attach_buffer_cdesc(session, buffer, size) &
    bind(C, name="MPIR_Session_attach_buffer_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Session
    IMPLICIT NONE
    INTEGER(c_Session), VALUE, INTENT(in) :: session
    TYPE(*), DIMENSION(..), INTENT(in) :: buffer
    INTEGER(c_int), VALUE, INTENT(in) :: size
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Session_attach_buffer_cdesc

FUNCTION MPIR_Session_attach_buffer_cdesc_large(session, buffer, size) &
    bind(C, name="MPIR_Session_attach_buffer_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Session
    IMPLICIT NONE
    INTEGER(c_Session), VALUE, INTENT(in) :: session
    TYPE(*), DIMENSION(..), INTENT(in) :: buffer
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: size
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Session_attach_buffer_cdesc_large

FUNCTION MPIR_Ssend_cdesc(buf, count, datatype, dest, tag, comm) &
    bind(C, name="MPIR_Ssend_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Ssend_cdesc

FUNCTION MPIR_Ssend_cdesc_large(buf, count, datatype, dest, tag, comm) &
    bind(C, name="MPIR_Ssend_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Ssend_cdesc_large

FUNCTION MPIR_Ssend_init_cdesc(buf, count, datatype, dest, tag, comm, request) &
    bind(C, name="MPIR_Ssend_init_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Ssend_init_cdesc

FUNCTION MPIR_Ssend_init_cdesc_large(buf, count, datatype, dest, tag, comm, request) &
    bind(C, name="MPIR_Ssend_init_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Ssend_init_cdesc_large

FUNCTION MPIR_Accumulate_cdesc(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
                               target_count, target_datatype, op, win) &
    bind(C, name="MPIR_Accumulate_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Win
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: origin_addr
    INTEGER(c_int), VALUE, INTENT(in) :: origin_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: origin_datatype
    INTEGER(c_int), VALUE, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: target_disp
    INTEGER(c_int), VALUE, INTENT(in) :: target_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: target_datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Accumulate_cdesc

FUNCTION MPIR_Accumulate_cdesc_large(origin_addr, origin_count, origin_datatype, target_rank, &
                                     target_disp, target_count, target_datatype, op, win) &
    bind(C, name="MPIR_Accumulate_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Win
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: origin_addr
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: origin_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: origin_datatype
    INTEGER(c_int), VALUE, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: target_disp
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: target_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: target_datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Accumulate_cdesc_large

FUNCTION MPIR_Compare_and_swap_cdesc(origin_addr, compare_addr, result_addr, datatype, target_rank, &
                                     target_disp, win) &
    bind(C, name="MPIR_Compare_and_swap_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Win
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: origin_addr
    TYPE(*), DIMENSION(..), INTENT(in) :: compare_addr
    TYPE(*), DIMENSION(..) :: result_addr
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: target_disp
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Compare_and_swap_cdesc

FUNCTION MPIR_Fetch_and_op_cdesc(origin_addr, result_addr, datatype, target_rank, target_disp, op, &
                                 win) &
    bind(C, name="MPIR_Fetch_and_op_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Win
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: origin_addr
    TYPE(*), DIMENSION(..) :: result_addr
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: target_disp
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Fetch_and_op_cdesc

FUNCTION MPIR_Free_mem_cdesc(base) &
    bind(C, name="MPIR_Free_mem_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: base
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Free_mem_cdesc

FUNCTION MPIR_Get_cdesc(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
                        target_count, target_datatype, win) &
    bind(C, name="MPIR_Get_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Win
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: origin_addr
    INTEGER(c_int), VALUE, INTENT(in) :: origin_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: origin_datatype
    INTEGER(c_int), VALUE, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: target_disp
    INTEGER(c_int), VALUE, INTENT(in) :: target_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: target_datatype
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Get_cdesc

FUNCTION MPIR_Get_cdesc_large(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
                              target_count, target_datatype, win) &
    bind(C, name="MPIR_Get_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Win
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: origin_addr
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: origin_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: origin_datatype
    INTEGER(c_int), VALUE, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: target_disp
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: target_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: target_datatype
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Get_cdesc_large

FUNCTION MPIR_Get_accumulate_cdesc(origin_addr, origin_count, origin_datatype, result_addr, &
                                   result_count, result_datatype, target_rank, target_disp, &
                                   target_count, target_datatype, op, win) &
    bind(C, name="MPIR_Get_accumulate_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Win
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: origin_addr
    INTEGER(c_int), VALUE, INTENT(in) :: origin_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: origin_datatype
    TYPE(*), DIMENSION(..) :: result_addr
    INTEGER(c_int), VALUE, INTENT(in) :: result_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: result_datatype
    INTEGER(c_int), VALUE, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: target_disp
    INTEGER(c_int), VALUE, INTENT(in) :: target_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: target_datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Get_accumulate_cdesc

FUNCTION MPIR_Get_accumulate_cdesc_large(origin_addr, origin_count, origin_datatype, result_addr, &
                                         result_count, result_datatype, target_rank, target_disp, &
                                         target_count, target_datatype, op, win) &
    bind(C, name="MPIR_Get_accumulate_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Win
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: origin_addr
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: origin_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: origin_datatype
    TYPE(*), DIMENSION(..) :: result_addr
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: result_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: result_datatype
    INTEGER(c_int), VALUE, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: target_disp
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: target_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: target_datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Get_accumulate_cdesc_large

FUNCTION MPIR_Put_cdesc(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
                        target_count, target_datatype, win) &
    bind(C, name="MPIR_Put_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Win
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: origin_addr
    INTEGER(c_int), VALUE, INTENT(in) :: origin_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: origin_datatype
    INTEGER(c_int), VALUE, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: target_disp
    INTEGER(c_int), VALUE, INTENT(in) :: target_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: target_datatype
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Put_cdesc

FUNCTION MPIR_Put_cdesc_large(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
                              target_count, target_datatype, win) &
    bind(C, name="MPIR_Put_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Win
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: origin_addr
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: origin_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: origin_datatype
    INTEGER(c_int), VALUE, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: target_disp
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: target_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: target_datatype
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Put_cdesc_large

FUNCTION MPIR_Raccumulate_cdesc(origin_addr, origin_count, origin_datatype, target_rank, &
                                target_disp, target_count, target_datatype, op, win, request) &
    bind(C, name="MPIR_Raccumulate_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Win, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: origin_addr
    INTEGER(c_int), VALUE, INTENT(in) :: origin_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: origin_datatype
    INTEGER(c_int), VALUE, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: target_disp
    INTEGER(c_int), VALUE, INTENT(in) :: target_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: target_datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Raccumulate_cdesc

FUNCTION MPIR_Raccumulate_cdesc_large(origin_addr, origin_count, origin_datatype, target_rank, &
                                      target_disp, target_count, target_datatype, op, win, &
                                      request) &
    bind(C, name="MPIR_Raccumulate_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Win, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: origin_addr
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: origin_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: origin_datatype
    INTEGER(c_int), VALUE, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: target_disp
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: target_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: target_datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Raccumulate_cdesc_large

FUNCTION MPIR_Rget_cdesc(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
                         target_count, target_datatype, win, request) &
    bind(C, name="MPIR_Rget_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Win, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: origin_addr
    INTEGER(c_int), VALUE, INTENT(in) :: origin_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: origin_datatype
    INTEGER(c_int), VALUE, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: target_disp
    INTEGER(c_int), VALUE, INTENT(in) :: target_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: target_datatype
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Rget_cdesc

FUNCTION MPIR_Rget_cdesc_large(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
                               target_count, target_datatype, win, request) &
    bind(C, name="MPIR_Rget_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Win, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: origin_addr
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: origin_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: origin_datatype
    INTEGER(c_int), VALUE, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: target_disp
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: target_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: target_datatype
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Rget_cdesc_large

FUNCTION MPIR_Rget_accumulate_cdesc(origin_addr, origin_count, origin_datatype, result_addr, &
                                    result_count, result_datatype, target_rank, target_disp, &
                                    target_count, target_datatype, op, win, request) &
    bind(C, name="MPIR_Rget_accumulate_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Win, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: origin_addr
    INTEGER(c_int), VALUE, INTENT(in) :: origin_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: origin_datatype
    TYPE(*), DIMENSION(..) :: result_addr
    INTEGER(c_int), VALUE, INTENT(in) :: result_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: result_datatype
    INTEGER(c_int), VALUE, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: target_disp
    INTEGER(c_int), VALUE, INTENT(in) :: target_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: target_datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Rget_accumulate_cdesc

FUNCTION MPIR_Rget_accumulate_cdesc_large(origin_addr, origin_count, origin_datatype, result_addr, &
                                          result_count, result_datatype, target_rank, target_disp, &
                                          target_count, target_datatype, op, win, request) &
    bind(C, name="MPIR_Rget_accumulate_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Win, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: origin_addr
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: origin_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: origin_datatype
    TYPE(*), DIMENSION(..) :: result_addr
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: result_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: result_datatype
    INTEGER(c_int), VALUE, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: target_disp
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: target_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: target_datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Rget_accumulate_cdesc_large

FUNCTION MPIR_Rput_cdesc(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
                         target_count, target_datatype, win, request) &
    bind(C, name="MPIR_Rput_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Win, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: origin_addr
    INTEGER(c_int), VALUE, INTENT(in) :: origin_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: origin_datatype
    INTEGER(c_int), VALUE, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: target_disp
    INTEGER(c_int), VALUE, INTENT(in) :: target_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: target_datatype
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Rput_cdesc

FUNCTION MPIR_Rput_cdesc_large(origin_addr, origin_count, origin_datatype, target_rank, target_disp, &
                               target_count, target_datatype, win, request) &
    bind(C, name="MPIR_Rput_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND, MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Win, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: origin_addr
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: origin_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: origin_datatype
    INTEGER(c_int), VALUE, INTENT(in) :: target_rank
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: target_disp
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: target_count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: target_datatype
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Rput_cdesc_large

FUNCTION MPIR_Win_attach_cdesc(win, base, size) &
    bind(C, name="MPIR_Win_attach_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Win
    IMPLICIT NONE
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    TYPE(*), DIMENSION(..), INTENT(in) :: base
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: size
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_attach_cdesc

FUNCTION MPIR_Win_create_cdesc(base, size, disp_unit, info, comm, win) &
    bind(C, name="MPIR_Win_create_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Info, c_Comm, c_Win
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: base
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: size
    INTEGER(c_int), VALUE, INTENT(in) :: disp_unit
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Win), INTENT(out) :: win
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_create_cdesc

FUNCTION MPIR_Win_create_cdesc_large(base, size, disp_unit, info, comm, win) &
    bind(C, name="MPIR_Win_create_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_ADDRESS_KIND
    USE :: mpi_c_interface_types, ONLY : c_Info, c_Comm, c_Win
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: base
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: size
    INTEGER(KIND=MPI_ADDRESS_KIND), VALUE, INTENT(in) :: disp_unit
    INTEGER(c_Info), VALUE, INTENT(in) :: info
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Win), INTENT(out) :: win
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_create_cdesc_large

FUNCTION MPIR_Win_detach_cdesc(win, base) &
    bind(C, name="MPIR_Win_detach_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Win
    IMPLICIT NONE
    INTEGER(c_Win), VALUE, INTENT(in) :: win
    TYPE(*), DIMENSION(..), INTENT(in) :: base
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Win_detach_cdesc

FUNCTION MPIR_Stream_send_cdesc(buf, count, datatype, dest, tag, comm, source_stream_index, &
                                dest_stream_index) &
    bind(C, name="MPIR_Stream_send_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), VALUE, INTENT(in) :: source_stream_index
    INTEGER(c_int), VALUE, INTENT(in) :: dest_stream_index
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Stream_send_cdesc

FUNCTION MPIR_Stream_send_cdesc_large(buf, count, datatype, dest, tag, comm, source_stream_index, &
                                      dest_stream_index) &
    bind(C, name="MPIR_Stream_send_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), VALUE, INTENT(in) :: source_stream_index
    INTEGER(c_int), VALUE, INTENT(in) :: dest_stream_index
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Stream_send_cdesc_large

FUNCTION MPIR_Stream_isend_cdesc(buf, count, datatype, dest, tag, comm, source_stream_index, &
                                 dest_stream_index, request) &
    bind(C, name="MPIR_Stream_isend_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), VALUE, INTENT(in) :: source_stream_index
    INTEGER(c_int), VALUE, INTENT(in) :: dest_stream_index
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Stream_isend_cdesc

FUNCTION MPIR_Stream_isend_cdesc_large(buf, count, datatype, dest, tag, comm, source_stream_index, &
                                       dest_stream_index, request) &
    bind(C, name="MPIR_Stream_isend_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), VALUE, INTENT(in) :: source_stream_index
    INTEGER(c_int), VALUE, INTENT(in) :: dest_stream_index
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Stream_isend_cdesc_large

FUNCTION MPIR_Stream_recv_cdesc(buf, count, datatype, source, tag, comm, source_stream_index, &
                                dest_stream_index, status) &
    bind(C, name="MPIR_Stream_recv_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: source
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), VALUE, INTENT(in) :: source_stream_index
    INTEGER(c_int), VALUE, INTENT(in) :: dest_stream_index
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Stream_recv_cdesc

FUNCTION MPIR_Stream_recv_cdesc_large(buf, count, datatype, source, tag, comm, source_stream_index, &
                                      dest_stream_index, status) &
    bind(C, name="MPIR_Stream_recv_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: source
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), VALUE, INTENT(in) :: source_stream_index
    INTEGER(c_int), VALUE, INTENT(in) :: dest_stream_index
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Stream_recv_cdesc_large

FUNCTION MPIR_Stream_irecv_cdesc(buf, count, datatype, source, tag, comm, source_stream_index, &
                                 dest_stream_index, request) &
    bind(C, name="MPIR_Stream_irecv_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: source
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), VALUE, INTENT(in) :: source_stream_index
    INTEGER(c_int), VALUE, INTENT(in) :: dest_stream_index
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Stream_irecv_cdesc

FUNCTION MPIR_Stream_irecv_cdesc_large(buf, count, datatype, source, tag, comm, source_stream_index, &
                                       dest_stream_index, request) &
    bind(C, name="MPIR_Stream_irecv_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: source
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int), VALUE, INTENT(in) :: source_stream_index
    INTEGER(c_int), VALUE, INTENT(in) :: dest_stream_index
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Stream_irecv_cdesc_large

FUNCTION MPIR_Send_enqueue_cdesc(buf, count, datatype, dest, tag, comm) &
    bind(C, name="MPIR_Send_enqueue_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Send_enqueue_cdesc

FUNCTION MPIR_Send_enqueue_cdesc_large(buf, count, datatype, dest, tag, comm) &
    bind(C, name="MPIR_Send_enqueue_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Send_enqueue_cdesc_large

FUNCTION MPIR_Recv_enqueue_cdesc(buf, count, datatype, source, tag, comm, status) &
    bind(C, name="MPIR_Recv_enqueue_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: source
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Recv_enqueue_cdesc

FUNCTION MPIR_Recv_enqueue_cdesc_large(buf, count, datatype, source, tag, comm, status) &
    bind(C, name="MPIR_Recv_enqueue_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: source
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Recv_enqueue_cdesc_large

FUNCTION MPIR_Isend_enqueue_cdesc(buf, count, datatype, dest, tag, comm, request) &
    bind(C, name="MPIR_Isend_enqueue_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Isend_enqueue_cdesc

FUNCTION MPIR_Isend_enqueue_cdesc_large(buf, count, datatype, dest, tag, comm, request) &
    bind(C, name="MPIR_Isend_enqueue_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: dest
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Isend_enqueue_cdesc_large

FUNCTION MPIR_Irecv_enqueue_cdesc(buf, count, datatype, source, tag, comm, request) &
    bind(C, name="MPIR_Irecv_enqueue_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: source
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Irecv_enqueue_cdesc

FUNCTION MPIR_Irecv_enqueue_cdesc_large(buf, count, datatype, source, tag, comm, request) &
    bind(C, name="MPIR_Irecv_enqueue_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Comm, c_Request
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int), VALUE, INTENT(in) :: source
    INTEGER(c_int), VALUE, INTENT(in) :: tag
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Irecv_enqueue_cdesc_large

FUNCTION MPIR_Allreduce_enqueue_cdesc(sendbuf, recvbuf, count, datatype, op, comm) &
    bind(C, name="MPIR_Allreduce_enqueue_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Allreduce_enqueue_cdesc

FUNCTION MPIR_Allreduce_enqueue_cdesc_large(sendbuf, recvbuf, count, datatype, op, comm) &
    bind(C, name="MPIR_Allreduce_enqueue_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_Datatype, c_Op, c_Comm
    IMPLICIT NONE
    TYPE(*), DIMENSION(..), INTENT(in) :: sendbuf
    TYPE(*), DIMENSION(..) :: recvbuf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Op), VALUE, INTENT(in) :: op
    INTEGER(c_Comm), VALUE, INTENT(in) :: comm
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_Allreduce_enqueue_cdesc_large

FUNCTION MPIR_File_iread_cdesc(fh, buf, count, datatype, request) &
    bind(C, name="MPIR_File_iread_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_iread_cdesc

FUNCTION MPIR_File_iread_cdesc_large(fh, buf, count, datatype, request) &
    bind(C, name="MPIR_File_iread_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_iread_cdesc_large

FUNCTION MPIR_File_iread_all_cdesc(fh, buf, count, datatype, request) &
    bind(C, name="MPIR_File_iread_all_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_iread_all_cdesc

FUNCTION MPIR_File_iread_all_cdesc_large(fh, buf, count, datatype, request) &
    bind(C, name="MPIR_File_iread_all_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_iread_all_cdesc_large

FUNCTION MPIR_File_iread_at_cdesc(fh, offset, buf, count, datatype, request) &
    bind(C, name="MPIR_File_iread_at_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), VALUE, INTENT(in) :: offset
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_iread_at_cdesc

FUNCTION MPIR_File_iread_at_cdesc_large(fh, offset, buf, count, datatype, request) &
    bind(C, name="MPIR_File_iread_at_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND, MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), VALUE, INTENT(in) :: offset
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_iread_at_cdesc_large

FUNCTION MPIR_File_iread_at_all_cdesc(fh, offset, buf, count, datatype, request) &
    bind(C, name="MPIR_File_iread_at_all_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), VALUE, INTENT(in) :: offset
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_iread_at_all_cdesc

FUNCTION MPIR_File_iread_at_all_cdesc_large(fh, offset, buf, count, datatype, request) &
    bind(C, name="MPIR_File_iread_at_all_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND, MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), VALUE, INTENT(in) :: offset
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_iread_at_all_cdesc_large

FUNCTION MPIR_File_iread_shared_cdesc(fh, buf, count, datatype, request) &
    bind(C, name="MPIR_File_iread_shared_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_iread_shared_cdesc

FUNCTION MPIR_File_iread_shared_cdesc_large(fh, buf, count, datatype, request) &
    bind(C, name="MPIR_File_iread_shared_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_iread_shared_cdesc_large

FUNCTION MPIR_File_iwrite_cdesc(fh, buf, count, datatype, request) &
    bind(C, name="MPIR_File_iwrite_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_iwrite_cdesc

FUNCTION MPIR_File_iwrite_cdesc_large(fh, buf, count, datatype, request) &
    bind(C, name="MPIR_File_iwrite_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_iwrite_cdesc_large

FUNCTION MPIR_File_iwrite_all_cdesc(fh, buf, count, datatype, request) &
    bind(C, name="MPIR_File_iwrite_all_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_iwrite_all_cdesc

FUNCTION MPIR_File_iwrite_all_cdesc_large(fh, buf, count, datatype, request) &
    bind(C, name="MPIR_File_iwrite_all_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_iwrite_all_cdesc_large

FUNCTION MPIR_File_iwrite_at_cdesc(fh, offset, buf, count, datatype, request) &
    bind(C, name="MPIR_File_iwrite_at_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), VALUE, INTENT(in) :: offset
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_iwrite_at_cdesc

FUNCTION MPIR_File_iwrite_at_cdesc_large(fh, offset, buf, count, datatype, request) &
    bind(C, name="MPIR_File_iwrite_at_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND, MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), VALUE, INTENT(in) :: offset
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_iwrite_at_cdesc_large

FUNCTION MPIR_File_iwrite_at_all_cdesc(fh, offset, buf, count, datatype, request) &
    bind(C, name="MPIR_File_iwrite_at_all_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), VALUE, INTENT(in) :: offset
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_iwrite_at_all_cdesc

FUNCTION MPIR_File_iwrite_at_all_cdesc_large(fh, offset, buf, count, datatype, request) &
    bind(C, name="MPIR_File_iwrite_at_all_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND, MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), VALUE, INTENT(in) :: offset
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_iwrite_at_all_cdesc_large

FUNCTION MPIR_File_iwrite_shared_cdesc(fh, buf, count, datatype, request) &
    bind(C, name="MPIR_File_iwrite_shared_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_iwrite_shared_cdesc

FUNCTION MPIR_File_iwrite_shared_cdesc_large(fh, buf, count, datatype, request) &
    bind(C, name="MPIR_File_iwrite_shared_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype, c_Request
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_Request), INTENT(out) :: request
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_iwrite_shared_cdesc_large

FUNCTION MPIR_File_read_cdesc(fh, buf, count, datatype, status) &
    bind(C, name="MPIR_File_read_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_read_cdesc

FUNCTION MPIR_File_read_cdesc_large(fh, buf, count, datatype, status) &
    bind(C, name="MPIR_File_read_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_read_cdesc_large

FUNCTION MPIR_File_read_all_cdesc(fh, buf, count, datatype, status) &
    bind(C, name="MPIR_File_read_all_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_read_all_cdesc

FUNCTION MPIR_File_read_all_cdesc_large(fh, buf, count, datatype, status) &
    bind(C, name="MPIR_File_read_all_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_read_all_cdesc_large

FUNCTION MPIR_File_read_all_begin_cdesc(fh, buf, count, datatype) &
    bind(C, name="MPIR_File_read_all_begin_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_read_all_begin_cdesc

FUNCTION MPIR_File_read_all_begin_cdesc_large(fh, buf, count, datatype) &
    bind(C, name="MPIR_File_read_all_begin_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_read_all_begin_cdesc_large

FUNCTION MPIR_File_read_all_end_cdesc(fh, buf, status) &
    bind(C, name="MPIR_File_read_all_end_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_File
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..) :: buf
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_read_all_end_cdesc

FUNCTION MPIR_File_read_at_cdesc(fh, offset, buf, count, datatype, status) &
    bind(C, name="MPIR_File_read_at_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), VALUE, INTENT(in) :: offset
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_read_at_cdesc

FUNCTION MPIR_File_read_at_cdesc_large(fh, offset, buf, count, datatype, status) &
    bind(C, name="MPIR_File_read_at_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND, MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), VALUE, INTENT(in) :: offset
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_read_at_cdesc_large

FUNCTION MPIR_File_read_at_all_cdesc(fh, offset, buf, count, datatype, status) &
    bind(C, name="MPIR_File_read_at_all_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), VALUE, INTENT(in) :: offset
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_read_at_all_cdesc

FUNCTION MPIR_File_read_at_all_cdesc_large(fh, offset, buf, count, datatype, status) &
    bind(C, name="MPIR_File_read_at_all_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND, MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), VALUE, INTENT(in) :: offset
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_read_at_all_cdesc_large

FUNCTION MPIR_File_read_at_all_begin_cdesc(fh, offset, buf, count, datatype) &
    bind(C, name="MPIR_File_read_at_all_begin_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), VALUE, INTENT(in) :: offset
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_read_at_all_begin_cdesc

FUNCTION MPIR_File_read_at_all_begin_cdesc_large(fh, offset, buf, count, datatype) &
    bind(C, name="MPIR_File_read_at_all_begin_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND, MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), VALUE, INTENT(in) :: offset
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_read_at_all_begin_cdesc_large

FUNCTION MPIR_File_read_at_all_end_cdesc(fh, buf, status) &
    bind(C, name="MPIR_File_read_at_all_end_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_File
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..) :: buf
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_read_at_all_end_cdesc

FUNCTION MPIR_File_read_ordered_cdesc(fh, buf, count, datatype, status) &
    bind(C, name="MPIR_File_read_ordered_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_read_ordered_cdesc

FUNCTION MPIR_File_read_ordered_cdesc_large(fh, buf, count, datatype, status) &
    bind(C, name="MPIR_File_read_ordered_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_read_ordered_cdesc_large

FUNCTION MPIR_File_read_ordered_begin_cdesc(fh, buf, count, datatype) &
    bind(C, name="MPIR_File_read_ordered_begin_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_read_ordered_begin_cdesc

FUNCTION MPIR_File_read_ordered_begin_cdesc_large(fh, buf, count, datatype) &
    bind(C, name="MPIR_File_read_ordered_begin_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_read_ordered_begin_cdesc_large

FUNCTION MPIR_File_read_ordered_end_cdesc(fh, buf, status) &
    bind(C, name="MPIR_File_read_ordered_end_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_File
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..) :: buf
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_read_ordered_end_cdesc

FUNCTION MPIR_File_read_shared_cdesc(fh, buf, count, datatype, status) &
    bind(C, name="MPIR_File_read_shared_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_read_shared_cdesc

FUNCTION MPIR_File_read_shared_cdesc_large(fh, buf, count, datatype, status) &
    bind(C, name="MPIR_File_read_shared_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_read_shared_cdesc_large

FUNCTION MPIR_File_write_cdesc(fh, buf, count, datatype, status) &
    bind(C, name="MPIR_File_write_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_write_cdesc

FUNCTION MPIR_File_write_cdesc_large(fh, buf, count, datatype, status) &
    bind(C, name="MPIR_File_write_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_write_cdesc_large

FUNCTION MPIR_File_write_all_cdesc(fh, buf, count, datatype, status) &
    bind(C, name="MPIR_File_write_all_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_write_all_cdesc

FUNCTION MPIR_File_write_all_cdesc_large(fh, buf, count, datatype, status) &
    bind(C, name="MPIR_File_write_all_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_write_all_cdesc_large

FUNCTION MPIR_File_write_all_begin_cdesc(fh, buf, count, datatype) &
    bind(C, name="MPIR_File_write_all_begin_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_write_all_begin_cdesc

FUNCTION MPIR_File_write_all_begin_cdesc_large(fh, buf, count, datatype) &
    bind(C, name="MPIR_File_write_all_begin_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_write_all_begin_cdesc_large

FUNCTION MPIR_File_write_all_end_cdesc(fh, buf, status) &
    bind(C, name="MPIR_File_write_all_end_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_File
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_write_all_end_cdesc

FUNCTION MPIR_File_write_at_cdesc(fh, offset, buf, count, datatype, status) &
    bind(C, name="MPIR_File_write_at_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), VALUE, INTENT(in) :: offset
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_write_at_cdesc

FUNCTION MPIR_File_write_at_cdesc_large(fh, offset, buf, count, datatype, status) &
    bind(C, name="MPIR_File_write_at_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND, MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), VALUE, INTENT(in) :: offset
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_write_at_cdesc_large

FUNCTION MPIR_File_write_at_all_cdesc(fh, offset, buf, count, datatype, status) &
    bind(C, name="MPIR_File_write_at_all_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), VALUE, INTENT(in) :: offset
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_write_at_all_cdesc

FUNCTION MPIR_File_write_at_all_cdesc_large(fh, offset, buf, count, datatype, status) &
    bind(C, name="MPIR_File_write_at_all_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND, MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), VALUE, INTENT(in) :: offset
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_write_at_all_cdesc_large

FUNCTION MPIR_File_write_at_all_begin_cdesc(fh, offset, buf, count, datatype) &
    bind(C, name="MPIR_File_write_at_all_begin_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), VALUE, INTENT(in) :: offset
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_write_at_all_begin_cdesc

FUNCTION MPIR_File_write_at_all_begin_cdesc_large(fh, offset, buf, count, datatype) &
    bind(C, name="MPIR_File_write_at_all_begin_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_OFFSET_KIND, MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    INTEGER(KIND=MPI_OFFSET_KIND), VALUE, INTENT(in) :: offset
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_write_at_all_begin_cdesc_large

FUNCTION MPIR_File_write_at_all_end_cdesc(fh, buf, status) &
    bind(C, name="MPIR_File_write_at_all_end_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_File
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_write_at_all_end_cdesc

FUNCTION MPIR_File_write_ordered_cdesc(fh, buf, count, datatype, status) &
    bind(C, name="MPIR_File_write_ordered_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_write_ordered_cdesc

FUNCTION MPIR_File_write_ordered_cdesc_large(fh, buf, count, datatype, status) &
    bind(C, name="MPIR_File_write_ordered_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_write_ordered_cdesc_large

FUNCTION MPIR_File_write_ordered_begin_cdesc(fh, buf, count, datatype) &
    bind(C, name="MPIR_File_write_ordered_begin_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_write_ordered_begin_cdesc

FUNCTION MPIR_File_write_ordered_begin_cdesc_large(fh, buf, count, datatype) &
    bind(C, name="MPIR_File_write_ordered_begin_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_write_ordered_begin_cdesc_large

FUNCTION MPIR_File_write_ordered_end_cdesc(fh, buf, status) &
    bind(C, name="MPIR_File_write_ordered_end_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_File
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_write_ordered_end_cdesc

FUNCTION MPIR_File_write_shared_cdesc(fh, buf, count, datatype, status) &
    bind(C, name="MPIR_File_write_shared_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(c_int), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_write_shared_cdesc

FUNCTION MPIR_File_write_shared_cdesc_large(fh, buf, count, datatype, status) &
    bind(C, name="MPIR_File_write_shared_cdesc_large") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int, c_ptr
    USE :: mpi_f08_compile_constants, ONLY : MPI_COUNT_KIND
    USE :: mpi_c_interface_types, ONLY : c_File, c_Datatype
    IMPLICIT NONE
    INTEGER(c_File), VALUE, INTENT(in) :: fh
    TYPE(*), DIMENSION(..), INTENT(in) :: buf
    INTEGER(KIND=MPI_COUNT_KIND), VALUE, INTENT(in) :: count
    INTEGER(c_Datatype), VALUE, INTENT(in) :: datatype
    TYPE(c_ptr), VALUE, INTENT(in) :: status
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_File_write_shared_cdesc_large

FUNCTION MPIR_F_sync_reg_cdesc(buf) &
    bind(C, name="MPIR_F_sync_reg_cdesc") result(ierror)
    USE, intrinsic :: iso_c_binding, ONLY : c_int
    IMPLICIT NONE
    TYPE(*), DIMENSION(..) :: buf
    INTEGER(c_int) :: ierror
END FUNCTION MPIR_F_sync_reg_cdesc

END INTERFACE
END module mpi_c_interface_cdesc
