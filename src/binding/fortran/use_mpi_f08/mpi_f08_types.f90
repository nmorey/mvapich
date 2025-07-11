!
! Copyright (C) by Argonne National Laboratory
!     See COPYRIGHT in top-level directory
!

! -- THIS FILE IS AUTO-GENERATED -- 

MODULE mpi_f08_types
    USE, intrinsic :: iso_c_binding, ONLY: c_int
    USE :: mpi_c_interface_types, ONLY: c_Count, c_Status
    IMPLICIT NONE
    
    private :: c_int, c_Count, c_Status
    
    TYPE, bind(C) :: MPI_Comm
        INTEGER :: MPI_VAL
    END TYPE MPI_Comm
    
    TYPE, bind(C) :: MPI_Datatype
        INTEGER :: MPI_VAL
    END TYPE MPI_Datatype
    
    TYPE, bind(C) :: MPI_Errhandler
        INTEGER :: MPI_VAL
    END TYPE MPI_Errhandler
    
    TYPE, bind(C) :: MPI_File
        INTEGER :: MPI_VAL
    END TYPE MPI_File
    
    TYPE, bind(C) :: MPI_Group
        INTEGER :: MPI_VAL
    END TYPE MPI_Group
    
    TYPE, bind(C) :: MPI_Info
        INTEGER :: MPI_VAL
    END TYPE MPI_Info
    
    TYPE, bind(C) :: MPI_Op
        INTEGER :: MPI_VAL
    END TYPE MPI_Op
    
    TYPE, bind(C) :: MPI_Request
        INTEGER :: MPI_VAL
    END TYPE MPI_Request
    
    TYPE, bind(C) :: MPI_Win
        INTEGER :: MPI_VAL
    END TYPE MPI_Win
    
    TYPE, bind(C) :: MPI_Message
        INTEGER :: MPI_VAL
    END TYPE MPI_Message
    
    TYPE, bind(C) :: MPI_Session
        INTEGER :: MPI_VAL
    END TYPE MPI_Session
    
    TYPE, bind(C) :: MPIX_Stream
        INTEGER :: MPI_VAL
    END TYPE MPIX_Stream
    
    INTERFACE
        
        FUNCTION MPI_File_f2c(x) bind(C, name="MPI_File_f2c") result(res)
            USE mpi_c_interface_types, ONLY: c_File
            INTEGER, VALUE :: x
            INTEGER(c_File) :: res
        END FUNCTION MPI_File_f2c
        
        FUNCTION MPI_File_c2f(x) bind(C, name="MPI_File_c2f") result(res)
            USE mpi_c_interface_types, ONLY: c_File
            INTEGER(c_File), VALUE :: x
            INTEGER :: res
        END FUNCTION MPI_File_c2f
    END INTERFACE
    
    TYPE, bind(C) :: MPI_Status
        INTEGER :: count_lo
        INTEGER :: count_hi_and_cancelled
        INTEGER :: MPI_SOURCE
        INTEGER :: MPI_TAG
        INTEGER :: MPI_ERROR
    END TYPE MPI_Status
    
    INTEGER, parameter :: MPI_SOURCE = 3
    INTEGER, parameter :: MPI_TAG    = 4
    INTEGER, parameter :: MPI_ERROR  = 5
    INTEGER, parameter :: MPI_STATUS_SIZE = 5
    
    INTERFACE assignment(=)
        module procedure MPI_Status_f08_assign_c
        module procedure MPI_Status_c_assign_f08
    END INTERFACE
    
    private :: MPI_Status_f08_assign_c
    private :: MPI_Status_c_assign_f08
    private :: MPI_Status_f_assign_c
    private :: MPI_Status_c_assign_f
    
    INTERFACE operator(==)
        module procedure MPI_Comm_eq
        module procedure MPI_Comm_f08_eq_f
        module procedure MPI_Comm_f_eq_f08
        module procedure MPI_Datatype_eq
        module procedure MPI_Datatype_f08_eq_f
        module procedure MPI_Datatype_f_eq_f08
        module procedure MPI_Errhandler_eq
        module procedure MPI_Errhandler_f08_eq_f
        module procedure MPI_Errhandler_f_eq_f08
        module procedure MPI_File_eq
        module procedure MPI_File_f08_eq_f
        module procedure MPI_File_f_eq_f08
        module procedure MPI_Group_eq
        module procedure MPI_Group_f08_eq_f
        module procedure MPI_Group_f_eq_f08
        module procedure MPI_Info_eq
        module procedure MPI_Info_f08_eq_f
        module procedure MPI_Info_f_eq_f08
        module procedure MPI_Op_eq
        module procedure MPI_Op_f08_eq_f
        module procedure MPI_Op_f_eq_f08
        module procedure MPI_Request_eq
        module procedure MPI_Request_f08_eq_f
        module procedure MPI_Request_f_eq_f08
        module procedure MPI_Win_eq
        module procedure MPI_Win_f08_eq_f
        module procedure MPI_Win_f_eq_f08
        module procedure MPI_Message_eq
        module procedure MPI_Message_f08_eq_f
        module procedure MPI_Message_f_eq_f08
        module procedure MPI_Session_eq
        module procedure MPI_Session_f08_eq_f
        module procedure MPI_Session_f_eq_f08
        module procedure MPIX_Stream_eq
        module procedure MPIX_Stream_f08_eq_f
        module procedure MPIX_Stream_f_eq_f08
    END INTERFACE
    
    private :: MPI_Comm_eq
    private :: MPI_Comm_f08_eq_f
    private :: MPI_Comm_f_eq_f08
    private :: MPI_Datatype_eq
    private :: MPI_Datatype_f08_eq_f
    private :: MPI_Datatype_f_eq_f08
    private :: MPI_Errhandler_eq
    private :: MPI_Errhandler_f08_eq_f
    private :: MPI_Errhandler_f_eq_f08
    private :: MPI_File_eq
    private :: MPI_File_f08_eq_f
    private :: MPI_File_f_eq_f08
    private :: MPI_Group_eq
    private :: MPI_Group_f08_eq_f
    private :: MPI_Group_f_eq_f08
    private :: MPI_Info_eq
    private :: MPI_Info_f08_eq_f
    private :: MPI_Info_f_eq_f08
    private :: MPI_Op_eq
    private :: MPI_Op_f08_eq_f
    private :: MPI_Op_f_eq_f08
    private :: MPI_Request_eq
    private :: MPI_Request_f08_eq_f
    private :: MPI_Request_f_eq_f08
    private :: MPI_Win_eq
    private :: MPI_Win_f08_eq_f
    private :: MPI_Win_f_eq_f08
    private :: MPI_Message_eq
    private :: MPI_Message_f08_eq_f
    private :: MPI_Message_f_eq_f08
    private :: MPI_Session_eq
    private :: MPI_Session_f08_eq_f
    private :: MPI_Session_f_eq_f08
    private :: MPIX_Stream_eq
    private :: MPIX_Stream_f08_eq_f
    private :: MPIX_Stream_f_eq_f08
    
    INTERFACE operator(/=)
        module procedure MPI_Comm_neq
        module procedure MPI_Comm_f08_neq_f
        module procedure MPI_Comm_f_neq_f08
        module procedure MPI_Datatype_neq
        module procedure MPI_Datatype_f08_neq_f
        module procedure MPI_Datatype_f_neq_f08
        module procedure MPI_Errhandler_neq
        module procedure MPI_Errhandler_f08_neq_f
        module procedure MPI_Errhandler_f_neq_f08
        module procedure MPI_File_neq
        module procedure MPI_File_f08_neq_f
        module procedure MPI_File_f_neq_f08
        module procedure MPI_Group_neq
        module procedure MPI_Group_f08_neq_f
        module procedure MPI_Group_f_neq_f08
        module procedure MPI_Info_neq
        module procedure MPI_Info_f08_neq_f
        module procedure MPI_Info_f_neq_f08
        module procedure MPI_Op_neq
        module procedure MPI_Op_f08_neq_f
        module procedure MPI_Op_f_neq_f08
        module procedure MPI_Request_neq
        module procedure MPI_Request_f08_neq_f
        module procedure MPI_Request_f_neq_f08
        module procedure MPI_Win_neq
        module procedure MPI_Win_f08_neq_f
        module procedure MPI_Win_f_neq_f08
        module procedure MPI_Message_neq
        module procedure MPI_Message_f08_neq_f
        module procedure MPI_Message_f_neq_f08
        module procedure MPI_Session_neq
        module procedure MPI_Session_f08_neq_f
        module procedure MPI_Session_f_neq_f08
        module procedure MPIX_Stream_neq
        module procedure MPIX_Stream_f08_neq_f
        module procedure MPIX_Stream_f_neq_f08
    END INTERFACE
    
    private :: MPI_Comm_neq
    private :: MPI_Comm_f08_neq_f
    private :: MPI_Comm_f_neq_f08
    private :: MPI_Datatype_neq
    private :: MPI_Datatype_f08_neq_f
    private :: MPI_Datatype_f_neq_f08
    private :: MPI_Errhandler_neq
    private :: MPI_Errhandler_f08_neq_f
    private :: MPI_Errhandler_f_neq_f08
    private :: MPI_File_neq
    private :: MPI_File_f08_neq_f
    private :: MPI_File_f_neq_f08
    private :: MPI_Group_neq
    private :: MPI_Group_f08_neq_f
    private :: MPI_Group_f_neq_f08
    private :: MPI_Info_neq
    private :: MPI_Info_f08_neq_f
    private :: MPI_Info_f_neq_f08
    private :: MPI_Op_neq
    private :: MPI_Op_f08_neq_f
    private :: MPI_Op_f_neq_f08
    private :: MPI_Request_neq
    private :: MPI_Request_f08_neq_f
    private :: MPI_Request_f_neq_f08
    private :: MPI_Win_neq
    private :: MPI_Win_f08_neq_f
    private :: MPI_Win_f_neq_f08
    private :: MPI_Message_neq
    private :: MPI_Message_f08_neq_f
    private :: MPI_Message_f_neq_f08
    private :: MPI_Session_neq
    private :: MPI_Session_f08_neq_f
    private :: MPI_Session_f_neq_f08
    private :: MPIX_Stream_neq
    private :: MPIX_Stream_f08_neq_f
    private :: MPIX_Stream_f_neq_f08
    
    INTERFACE MPI_Sizeof
        module procedure MPI_Sizeof_character
        module procedure MPI_Sizeof_logical
        module procedure MPI_Sizeof_xint8
        module procedure MPI_Sizeof_xint16
        module procedure MPI_Sizeof_xint32
        module procedure MPI_Sizeof_xint64
        module procedure MPI_Sizeof_xreal32
        module procedure MPI_Sizeof_xreal64
        module procedure MPI_Sizeof_xreal128
        module procedure MPI_Sizeof_xcomplex32
        module procedure MPI_Sizeof_xcomplex64
        module procedure MPI_Sizeof_xcomplex128
    END INTERFACE
    
    private :: MPI_Sizeof_character
    private :: MPI_Sizeof_logical
    private :: MPI_Sizeof_xint8
    private :: MPI_Sizeof_xint16
    private :: MPI_Sizeof_xint32
    private :: MPI_Sizeof_xint64
    private :: MPI_Sizeof_xreal32
    private :: MPI_Sizeof_xreal64
    private :: MPI_Sizeof_xreal128
    private :: MPI_Sizeof_xcomplex32
    private :: MPI_Sizeof_xcomplex64
    private :: MPI_Sizeof_xcomplex128
    
    contains
    
    
    SUBROUTINE MPI_Sizeof_character(x, size, ierror)
        character, dimension(..) :: x
        INTEGER, INTENT(out) :: size
        INTEGER, OPTIONAL, INTENT(out) :: ierror
        
        size = storage_size(x)/8
        IF (present(ierror)) ierror = 0
    END SUBROUTINE
    
    SUBROUTINE MPI_Sizeof_logical(x, size, ierror)
        logical, dimension(..) :: x
        INTEGER, INTENT(out) :: size
        INTEGER, OPTIONAL, INTENT(out) :: ierror
        
        size = storage_size(x)/8
        IF (present(ierror)) ierror = 0
    END SUBROUTINE
    
    SUBROUTINE MPI_Sizeof_xint8(x, size, ierror)
        USE, intrinsic :: iso_fortran_env, ONLY: int8
        INTEGER(int8), dimension(..) :: x
        INTEGER, INTENT(out) :: size
        INTEGER, OPTIONAL, INTENT(out) :: ierror
        
        size = storage_size(x)/8
        IF (present(ierror)) ierror = 0
    END SUBROUTINE
    
    SUBROUTINE MPI_Sizeof_xint16(x, size, ierror)
        USE, intrinsic :: iso_fortran_env, ONLY: int16
        INTEGER(int16), dimension(..) :: x
        INTEGER, INTENT(out) :: size
        INTEGER, OPTIONAL, INTENT(out) :: ierror
        
        size = storage_size(x)/8
        IF (present(ierror)) ierror = 0
    END SUBROUTINE
    
    SUBROUTINE MPI_Sizeof_xint32(x, size, ierror)
        USE, intrinsic :: iso_fortran_env, ONLY: int32
        INTEGER(int32), dimension(..) :: x
        INTEGER, INTENT(out) :: size
        INTEGER, OPTIONAL, INTENT(out) :: ierror
        
        size = storage_size(x)/8
        IF (present(ierror)) ierror = 0
    END SUBROUTINE
    
    SUBROUTINE MPI_Sizeof_xint64(x, size, ierror)
        USE, intrinsic :: iso_fortran_env, ONLY: int64
        INTEGER(int64), dimension(..) :: x
        INTEGER, INTENT(out) :: size
        INTEGER, OPTIONAL, INTENT(out) :: ierror
        
        size = storage_size(x)/8
        IF (present(ierror)) ierror = 0
    END SUBROUTINE
    
    SUBROUTINE MPI_Sizeof_xreal32(x, size, ierror)
        USE, intrinsic :: iso_fortran_env, ONLY: real32
        real(real32), dimension(..) :: x
        INTEGER, INTENT(out) :: size
        INTEGER, OPTIONAL, INTENT(out) :: ierror
        
        size = storage_size(x)/8
        IF (present(ierror)) ierror = 0
    END SUBROUTINE
    
    SUBROUTINE MPI_Sizeof_xreal64(x, size, ierror)
        USE, intrinsic :: iso_fortran_env, ONLY: real64
        real(real64), dimension(..) :: x
        INTEGER, INTENT(out) :: size
        INTEGER, OPTIONAL, INTENT(out) :: ierror
        
        size = storage_size(x)/8
        IF (present(ierror)) ierror = 0
    END SUBROUTINE
    
    SUBROUTINE MPI_Sizeof_xreal128(x, size, ierror)
        USE, intrinsic :: iso_fortran_env, ONLY: real128
        real(real128), dimension(..) :: x
        INTEGER, INTENT(out) :: size
        INTEGER, OPTIONAL, INTENT(out) :: ierror
        
        size = storage_size(x)/8
        IF (present(ierror)) ierror = 0
    END SUBROUTINE
    
    SUBROUTINE MPI_Sizeof_xcomplex32(x, size, ierror)
        USE, intrinsic :: iso_fortran_env, ONLY: real32
        complex(real32), dimension(..) :: x
        INTEGER, INTENT(out) :: size
        INTEGER, OPTIONAL, INTENT(out) :: ierror
        
        size = storage_size(x)/8
        IF (present(ierror)) ierror = 0
    END SUBROUTINE
    
    SUBROUTINE MPI_Sizeof_xcomplex64(x, size, ierror)
        USE, intrinsic :: iso_fortran_env, ONLY: real64
        complex(real64), dimension(..) :: x
        INTEGER, INTENT(out) :: size
        INTEGER, OPTIONAL, INTENT(out) :: ierror
        
        size = storage_size(x)/8
        IF (present(ierror)) ierror = 0
    END SUBROUTINE
    
    SUBROUTINE MPI_Sizeof_xcomplex128(x, size, ierror)
        USE, intrinsic :: iso_fortran_env, ONLY: real128
        complex(real128), dimension(..) :: x
        INTEGER, INTENT(out) :: size
        INTEGER, OPTIONAL, INTENT(out) :: ierror
        
        size = storage_size(x)/8
        IF (present(ierror)) ierror = 0
    END SUBROUTINE
    
    elemental SUBROUTINE MPI_Status_c_assign_f08(status_c, status_f08)
        TYPE(MPI_Status), INTENT(in) :: status_f08
        TYPE(c_Status), INTENT(out) :: status_c
        
        status_c%count_lo = status_f08%count_lo
        status_c%count_hi_and_cancelled = status_f08%count_hi_and_cancelled
        status_c%MPI_SOURCE = status_f08%MPI_SOURCE
        status_c%MPI_TAG = status_f08%MPI_TAG
        status_c%MPI_ERROR = status_f08%MPI_ERROR
    END SUBROUTINE
    
    elemental SUBROUTINE MPI_Status_f08_assign_c(status_f08, status_c)
        TYPE(c_Status), INTENT(in) :: status_c
        TYPE(MPI_Status), INTENT(out) :: status_f08
        
        status_f08%count_lo = status_c%count_lo
        status_f08%count_hi_and_cancelled = status_c%count_hi_and_cancelled
        status_f08%MPI_SOURCE = status_c%MPI_SOURCE
        status_f08%MPI_TAG = status_c%MPI_TAG
        status_f08%MPI_ERROR = status_c%MPI_ERROR
    END SUBROUTINE
    
    SUBROUTINE MPI_Status_c_assign_f(status_c, status_f)
        INTEGER, INTENT(in) :: status_f(MPI_STATUS_SIZE)
        TYPE(c_Status), INTENT(out) :: status_c
        
        status_c%count_lo = status_f(1)
        status_c%count_hi_and_cancelled = status_f(2)
        status_c%MPI_SOURCE = status_f(MPI_SOURCE)
        status_c%MPI_TAG = status_f(MPI_TAG)
        status_c%MPI_ERROR = status_f(MPI_ERROR)
    END SUBROUTINE
    
    SUBROUTINE MPI_Status_f_assign_c(status_f, status_c)
        TYPE(c_Status), INTENT(in) :: status_c
        INTEGER, INTENT(out) :: status_f(MPI_STATUS_SIZE)
        
        status_f(1) = status_c%count_lo
        status_f(2) = status_c%count_hi_and_cancelled
        status_f(MPI_SOURCE) = status_c%MPI_SOURCE
        status_f(MPI_TAG) = status_c%MPI_TAG
        status_f(MPI_ERROR) = status_c%MPI_ERROR
    END SUBROUTINE
    
    SUBROUTINE MPI_Status_f082c(status_f08, status_c, ierror)
        TYPE(MPI_Status), INTENT(in) :: status_f08
        TYPE(c_Status), INTENT(out) :: status_c
        INTEGER, OPTIONAL, INTENT(out) :: ierror
        
        status_c = status_f08
        IF (present(ierror)) ierror = 0
    END SUBROUTINE
    
    SUBROUTINE MPI_Status_c2f08(status_c, status_f08, ierror)
        TYPE(c_Status), INTENT(in) :: status_c
        TYPE(MPI_Status), INTENT(out) :: status_f08
        INTEGER, OPTIONAL, INTENT(out) :: ierror
        
        status_f08 = status_c
        IF (present(ierror)) ierror = 0
    END SUBROUTINE
    
    SUBROUTINE MPI_Status_f082f(f08_status, f_status, ierror)
        TYPE(MPI_Status), INTENT(in) :: f08_status
        INTEGER, INTENT(out) :: f_status(MPI_STATUS_SIZE)
        INTEGER, OPTIONAL, INTENT(out) :: ierror
        
        f_status(1) = f08_status%count_lo
        f_status(2) = f08_status%count_hi_and_cancelled
        f_status(MPI_SOURCE) = f08_status%MPI_SOURCE
        f_status(MPI_TAG) = f08_status%MPI_TAG
        f_status(MPI_ERROR) = f08_status%MPI_ERROR
        IF (present(ierror)) ierror = 0
    END SUBROUTINE
    
    SUBROUTINE MPI_Status_f2f08(f_status, f08_status, ierror)
        INTEGER, INTENT(in) :: f_status(MPI_STATUS_SIZE)
        TYPE(MPI_Status), INTENT(out) :: f08_status
        INTEGER, OPTIONAL, INTENT(out) :: ierror
        
        f08_status%count_lo = f_status(1)
        f08_status%count_hi_and_cancelled = f_status(2)
        f08_status%MPI_SOURCE = f_status(MPI_SOURCE)
        f08_status%MPI_TAG = f_status(MPI_TAG)
        f08_status%MPI_ERROR = f_status(MPI_ERROR)
        IF (present(ierror)) ierror = 0
    END SUBROUTINE
    
    SUBROUTINE PMPI_Status_f082c(status_f08, status_c, ierror)
        TYPE(MPI_Status), INTENT(in) :: status_f08
        TYPE(c_Status), INTENT(out) :: status_c
        INTEGER, OPTIONAL, INTENT(out) :: ierror
        
        status_c = status_f08
        IF (present(ierror)) ierror = 0
    END SUBROUTINE
    
    SUBROUTINE PMPI_Status_c2f08(status_c, status_f08, ierror)
        TYPE(c_Status), INTENT(in) :: status_c
        TYPE(MPI_Status), INTENT(out) :: status_f08
        INTEGER, OPTIONAL, INTENT(out) :: ierror
        
        status_f08 = status_c
        IF (present(ierror)) ierror = 0
    END SUBROUTINE
    
    SUBROUTINE PMPI_Status_f082f(f08_status, f_status, ierror)
        TYPE(MPI_Status), INTENT(in) :: f08_status
        INTEGER, INTENT(out) :: f_status(MPI_STATUS_SIZE)
        INTEGER, OPTIONAL, INTENT(out) :: ierror
        
        f_status(1) = f08_status%count_lo
        f_status(2) = f08_status%count_hi_and_cancelled
        f_status(MPI_SOURCE) = f08_status%MPI_SOURCE
        f_status(MPI_TAG) = f08_status%MPI_TAG
        f_status(MPI_ERROR) = f08_status%MPI_ERROR
        IF (present(ierror)) ierror = 0
    END SUBROUTINE
    
    SUBROUTINE PMPI_Status_f2f08(f_status, f08_status, ierror)
        INTEGER, INTENT(in) :: f_status(MPI_STATUS_SIZE)
        TYPE(MPI_Status), INTENT(out) :: f08_status
        INTEGER, OPTIONAL, INTENT(out) :: ierror
        
        f08_status%count_lo = f_status(1)
        f08_status%count_hi_and_cancelled = f_status(2)
        f08_status%MPI_SOURCE = f_status(MPI_SOURCE)
        f08_status%MPI_TAG = f_status(MPI_TAG)
        f08_status%MPI_ERROR = f_status(MPI_ERROR)
        IF (present(ierror)) ierror = 0
    END SUBROUTINE
    
    
    elemental FUNCTION MPI_Comm_eq(x, y) result(res)
        TYPE(MPI_Comm), INTENT(in) :: x, y
        LOGICAL :: res
        res = (x%MPI_VAL == y%MPI_VAL)
    END FUNCTION MPI_Comm_eq
    
    
    elemental FUNCTION MPI_Comm_f08_eq_f(f08, f) result(res)
        TYPE(MPI_Comm), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL == f)
    END FUNCTION MPI_Comm_f08_eq_f
    
    elemental FUNCTION MPI_Comm_f_eq_f08(f, f08) result(res)
        TYPE(MPI_Comm), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL == f)
    END FUNCTION MPI_Comm_f_eq_f08
    
    elemental FUNCTION MPI_Datatype_eq(x, y) result(res)
        TYPE(MPI_Datatype), INTENT(in) :: x, y
        LOGICAL :: res
        res = (x%MPI_VAL == y%MPI_VAL)
    END FUNCTION MPI_Datatype_eq
    
    
    elemental FUNCTION MPI_Datatype_f08_eq_f(f08, f) result(res)
        TYPE(MPI_Datatype), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL == f)
    END FUNCTION MPI_Datatype_f08_eq_f
    
    elemental FUNCTION MPI_Datatype_f_eq_f08(f, f08) result(res)
        TYPE(MPI_Datatype), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL == f)
    END FUNCTION MPI_Datatype_f_eq_f08
    
    elemental FUNCTION MPI_Errhandler_eq(x, y) result(res)
        TYPE(MPI_Errhandler), INTENT(in) :: x, y
        LOGICAL :: res
        res = (x%MPI_VAL == y%MPI_VAL)
    END FUNCTION MPI_Errhandler_eq
    
    
    elemental FUNCTION MPI_Errhandler_f08_eq_f(f08, f) result(res)
        TYPE(MPI_Errhandler), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL == f)
    END FUNCTION MPI_Errhandler_f08_eq_f
    
    elemental FUNCTION MPI_Errhandler_f_eq_f08(f, f08) result(res)
        TYPE(MPI_Errhandler), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL == f)
    END FUNCTION MPI_Errhandler_f_eq_f08
    
    elemental FUNCTION MPI_File_eq(x, y) result(res)
        TYPE(MPI_File), INTENT(in) :: x, y
        LOGICAL :: res
        res = (x%MPI_VAL == y%MPI_VAL)
    END FUNCTION MPI_File_eq
    
    
    elemental FUNCTION MPI_File_f08_eq_f(f08, f) result(res)
        TYPE(MPI_File), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL == f)
    END FUNCTION MPI_File_f08_eq_f
    
    elemental FUNCTION MPI_File_f_eq_f08(f, f08) result(res)
        TYPE(MPI_File), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL == f)
    END FUNCTION MPI_File_f_eq_f08
    
    elemental FUNCTION MPI_Group_eq(x, y) result(res)
        TYPE(MPI_Group), INTENT(in) :: x, y
        LOGICAL :: res
        res = (x%MPI_VAL == y%MPI_VAL)
    END FUNCTION MPI_Group_eq
    
    
    elemental FUNCTION MPI_Group_f08_eq_f(f08, f) result(res)
        TYPE(MPI_Group), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL == f)
    END FUNCTION MPI_Group_f08_eq_f
    
    elemental FUNCTION MPI_Group_f_eq_f08(f, f08) result(res)
        TYPE(MPI_Group), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL == f)
    END FUNCTION MPI_Group_f_eq_f08
    
    elemental FUNCTION MPI_Info_eq(x, y) result(res)
        TYPE(MPI_Info), INTENT(in) :: x, y
        LOGICAL :: res
        res = (x%MPI_VAL == y%MPI_VAL)
    END FUNCTION MPI_Info_eq
    
    
    elemental FUNCTION MPI_Info_f08_eq_f(f08, f) result(res)
        TYPE(MPI_Info), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL == f)
    END FUNCTION MPI_Info_f08_eq_f
    
    elemental FUNCTION MPI_Info_f_eq_f08(f, f08) result(res)
        TYPE(MPI_Info), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL == f)
    END FUNCTION MPI_Info_f_eq_f08
    
    elemental FUNCTION MPI_Op_eq(x, y) result(res)
        TYPE(MPI_Op), INTENT(in) :: x, y
        LOGICAL :: res
        res = (x%MPI_VAL == y%MPI_VAL)
    END FUNCTION MPI_Op_eq
    
    
    elemental FUNCTION MPI_Op_f08_eq_f(f08, f) result(res)
        TYPE(MPI_Op), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL == f)
    END FUNCTION MPI_Op_f08_eq_f
    
    elemental FUNCTION MPI_Op_f_eq_f08(f, f08) result(res)
        TYPE(MPI_Op), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL == f)
    END FUNCTION MPI_Op_f_eq_f08
    
    elemental FUNCTION MPI_Request_eq(x, y) result(res)
        TYPE(MPI_Request), INTENT(in) :: x, y
        LOGICAL :: res
        res = (x%MPI_VAL == y%MPI_VAL)
    END FUNCTION MPI_Request_eq
    
    
    elemental FUNCTION MPI_Request_f08_eq_f(f08, f) result(res)
        TYPE(MPI_Request), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL == f)
    END FUNCTION MPI_Request_f08_eq_f
    
    elemental FUNCTION MPI_Request_f_eq_f08(f, f08) result(res)
        TYPE(MPI_Request), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL == f)
    END FUNCTION MPI_Request_f_eq_f08
    
    elemental FUNCTION MPI_Win_eq(x, y) result(res)
        TYPE(MPI_Win), INTENT(in) :: x, y
        LOGICAL :: res
        res = (x%MPI_VAL == y%MPI_VAL)
    END FUNCTION MPI_Win_eq
    
    
    elemental FUNCTION MPI_Win_f08_eq_f(f08, f) result(res)
        TYPE(MPI_Win), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL == f)
    END FUNCTION MPI_Win_f08_eq_f
    
    elemental FUNCTION MPI_Win_f_eq_f08(f, f08) result(res)
        TYPE(MPI_Win), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL == f)
    END FUNCTION MPI_Win_f_eq_f08
    
    elemental FUNCTION MPI_Message_eq(x, y) result(res)
        TYPE(MPI_Message), INTENT(in) :: x, y
        LOGICAL :: res
        res = (x%MPI_VAL == y%MPI_VAL)
    END FUNCTION MPI_Message_eq
    
    
    elemental FUNCTION MPI_Message_f08_eq_f(f08, f) result(res)
        TYPE(MPI_Message), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL == f)
    END FUNCTION MPI_Message_f08_eq_f
    
    elemental FUNCTION MPI_Message_f_eq_f08(f, f08) result(res)
        TYPE(MPI_Message), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL == f)
    END FUNCTION MPI_Message_f_eq_f08
    
    elemental FUNCTION MPI_Session_eq(x, y) result(res)
        TYPE(MPI_Session), INTENT(in) :: x, y
        LOGICAL :: res
        res = (x%MPI_VAL == y%MPI_VAL)
    END FUNCTION MPI_Session_eq
    
    
    elemental FUNCTION MPI_Session_f08_eq_f(f08, f) result(res)
        TYPE(MPI_Session), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL == f)
    END FUNCTION MPI_Session_f08_eq_f
    
    elemental FUNCTION MPI_Session_f_eq_f08(f, f08) result(res)
        TYPE(MPI_Session), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL == f)
    END FUNCTION MPI_Session_f_eq_f08
    
    elemental FUNCTION MPIX_Stream_eq(x, y) result(res)
        TYPE(MPIX_Stream), INTENT(in) :: x, y
        LOGICAL :: res
        res = (x%MPI_VAL == y%MPI_VAL)
    END FUNCTION MPIX_Stream_eq
    
    
    elemental FUNCTION MPIX_Stream_f08_eq_f(f08, f) result(res)
        TYPE(MPIX_Stream), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL == f)
    END FUNCTION MPIX_Stream_f08_eq_f
    
    elemental FUNCTION MPIX_Stream_f_eq_f08(f, f08) result(res)
        TYPE(MPIX_Stream), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL == f)
    END FUNCTION MPIX_Stream_f_eq_f08
    
    
    elemental FUNCTION MPI_Comm_neq(x, y) result(res)
        TYPE(MPI_Comm), INTENT(in) :: x, y
        LOGICAL :: res
        res = (x%MPI_VAL /= y%MPI_VAL)
    END FUNCTION MPI_Comm_neq
    
    
    elemental FUNCTION MPI_Comm_f08_neq_f(f08, f) result(res)
        TYPE(MPI_Comm), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL /= f)
    END FUNCTION MPI_Comm_f08_neq_f
    
    elemental FUNCTION MPI_Comm_f_neq_f08(f, f08) result(res)
        TYPE(MPI_Comm), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL /= f)
    END FUNCTION MPI_Comm_f_neq_f08
    
    elemental FUNCTION MPI_Datatype_neq(x, y) result(res)
        TYPE(MPI_Datatype), INTENT(in) :: x, y
        LOGICAL :: res
        res = (x%MPI_VAL /= y%MPI_VAL)
    END FUNCTION MPI_Datatype_neq
    
    
    elemental FUNCTION MPI_Datatype_f08_neq_f(f08, f) result(res)
        TYPE(MPI_Datatype), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL /= f)
    END FUNCTION MPI_Datatype_f08_neq_f
    
    elemental FUNCTION MPI_Datatype_f_neq_f08(f, f08) result(res)
        TYPE(MPI_Datatype), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL /= f)
    END FUNCTION MPI_Datatype_f_neq_f08
    
    elemental FUNCTION MPI_Errhandler_neq(x, y) result(res)
        TYPE(MPI_Errhandler), INTENT(in) :: x, y
        LOGICAL :: res
        res = (x%MPI_VAL /= y%MPI_VAL)
    END FUNCTION MPI_Errhandler_neq
    
    
    elemental FUNCTION MPI_Errhandler_f08_neq_f(f08, f) result(res)
        TYPE(MPI_Errhandler), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL /= f)
    END FUNCTION MPI_Errhandler_f08_neq_f
    
    elemental FUNCTION MPI_Errhandler_f_neq_f08(f, f08) result(res)
        TYPE(MPI_Errhandler), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL /= f)
    END FUNCTION MPI_Errhandler_f_neq_f08
    
    elemental FUNCTION MPI_File_neq(x, y) result(res)
        TYPE(MPI_File), INTENT(in) :: x, y
        LOGICAL :: res
        res = (x%MPI_VAL /= y%MPI_VAL)
    END FUNCTION MPI_File_neq
    
    
    elemental FUNCTION MPI_File_f08_neq_f(f08, f) result(res)
        TYPE(MPI_File), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL /= f)
    END FUNCTION MPI_File_f08_neq_f
    
    elemental FUNCTION MPI_File_f_neq_f08(f, f08) result(res)
        TYPE(MPI_File), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL /= f)
    END FUNCTION MPI_File_f_neq_f08
    
    elemental FUNCTION MPI_Group_neq(x, y) result(res)
        TYPE(MPI_Group), INTENT(in) :: x, y
        LOGICAL :: res
        res = (x%MPI_VAL /= y%MPI_VAL)
    END FUNCTION MPI_Group_neq
    
    
    elemental FUNCTION MPI_Group_f08_neq_f(f08, f) result(res)
        TYPE(MPI_Group), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL /= f)
    END FUNCTION MPI_Group_f08_neq_f
    
    elemental FUNCTION MPI_Group_f_neq_f08(f, f08) result(res)
        TYPE(MPI_Group), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL /= f)
    END FUNCTION MPI_Group_f_neq_f08
    
    elemental FUNCTION MPI_Info_neq(x, y) result(res)
        TYPE(MPI_Info), INTENT(in) :: x, y
        LOGICAL :: res
        res = (x%MPI_VAL /= y%MPI_VAL)
    END FUNCTION MPI_Info_neq
    
    
    elemental FUNCTION MPI_Info_f08_neq_f(f08, f) result(res)
        TYPE(MPI_Info), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL /= f)
    END FUNCTION MPI_Info_f08_neq_f
    
    elemental FUNCTION MPI_Info_f_neq_f08(f, f08) result(res)
        TYPE(MPI_Info), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL /= f)
    END FUNCTION MPI_Info_f_neq_f08
    
    elemental FUNCTION MPI_Op_neq(x, y) result(res)
        TYPE(MPI_Op), INTENT(in) :: x, y
        LOGICAL :: res
        res = (x%MPI_VAL /= y%MPI_VAL)
    END FUNCTION MPI_Op_neq
    
    
    elemental FUNCTION MPI_Op_f08_neq_f(f08, f) result(res)
        TYPE(MPI_Op), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL /= f)
    END FUNCTION MPI_Op_f08_neq_f
    
    elemental FUNCTION MPI_Op_f_neq_f08(f, f08) result(res)
        TYPE(MPI_Op), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL /= f)
    END FUNCTION MPI_Op_f_neq_f08
    
    elemental FUNCTION MPI_Request_neq(x, y) result(res)
        TYPE(MPI_Request), INTENT(in) :: x, y
        LOGICAL :: res
        res = (x%MPI_VAL /= y%MPI_VAL)
    END FUNCTION MPI_Request_neq
    
    
    elemental FUNCTION MPI_Request_f08_neq_f(f08, f) result(res)
        TYPE(MPI_Request), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL /= f)
    END FUNCTION MPI_Request_f08_neq_f
    
    elemental FUNCTION MPI_Request_f_neq_f08(f, f08) result(res)
        TYPE(MPI_Request), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL /= f)
    END FUNCTION MPI_Request_f_neq_f08
    
    elemental FUNCTION MPI_Win_neq(x, y) result(res)
        TYPE(MPI_Win), INTENT(in) :: x, y
        LOGICAL :: res
        res = (x%MPI_VAL /= y%MPI_VAL)
    END FUNCTION MPI_Win_neq
    
    
    elemental FUNCTION MPI_Win_f08_neq_f(f08, f) result(res)
        TYPE(MPI_Win), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL /= f)
    END FUNCTION MPI_Win_f08_neq_f
    
    elemental FUNCTION MPI_Win_f_neq_f08(f, f08) result(res)
        TYPE(MPI_Win), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL /= f)
    END FUNCTION MPI_Win_f_neq_f08
    
    elemental FUNCTION MPI_Message_neq(x, y) result(res)
        TYPE(MPI_Message), INTENT(in) :: x, y
        LOGICAL :: res
        res = (x%MPI_VAL /= y%MPI_VAL)
    END FUNCTION MPI_Message_neq
    
    
    elemental FUNCTION MPI_Message_f08_neq_f(f08, f) result(res)
        TYPE(MPI_Message), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL /= f)
    END FUNCTION MPI_Message_f08_neq_f
    
    elemental FUNCTION MPI_Message_f_neq_f08(f, f08) result(res)
        TYPE(MPI_Message), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL /= f)
    END FUNCTION MPI_Message_f_neq_f08
    
    elemental FUNCTION MPI_Session_neq(x, y) result(res)
        TYPE(MPI_Session), INTENT(in) :: x, y
        LOGICAL :: res
        res = (x%MPI_VAL /= y%MPI_VAL)
    END FUNCTION MPI_Session_neq
    
    
    elemental FUNCTION MPI_Session_f08_neq_f(f08, f) result(res)
        TYPE(MPI_Session), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL /= f)
    END FUNCTION MPI_Session_f08_neq_f
    
    elemental FUNCTION MPI_Session_f_neq_f08(f, f08) result(res)
        TYPE(MPI_Session), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL /= f)
    END FUNCTION MPI_Session_f_neq_f08
    
    elemental FUNCTION MPIX_Stream_neq(x, y) result(res)
        TYPE(MPIX_Stream), INTENT(in) :: x, y
        LOGICAL :: res
        res = (x%MPI_VAL /= y%MPI_VAL)
    END FUNCTION MPIX_Stream_neq
    
    
    elemental FUNCTION MPIX_Stream_f08_neq_f(f08, f) result(res)
        TYPE(MPIX_Stream), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL /= f)
    END FUNCTION MPIX_Stream_f08_neq_f
    
    elemental FUNCTION MPIX_Stream_f_neq_f08(f, f08) result(res)
        TYPE(MPIX_Stream), INTENT(in) :: f08
        INTEGER, INTENT(in) :: f
        LOGICAL :: res
        res = (f08%MPI_VAL /= f)
    END FUNCTION MPIX_Stream_f_neq_f08
    
    FUNCTION MPI_Comm_f2c(x) result(res)
        USE mpi_c_interface_types, ONLY: c_Comm
        INTEGER, VALUE :: x
        INTEGER(c_Comm) :: res
        res = x
    END FUNCTION MPI_Comm_f2c
    
    FUNCTION MPI_Comm_c2f(x) result(res)
        USE mpi_c_interface_types, ONLY: c_Comm
        INTEGER(c_Comm), VALUE :: x
        INTEGER :: res
        res = x
    END FUNCTION MPI_Comm_c2f
    
    FUNCTION MPI_Datatype_f2c(x) result(res)
        USE mpi_c_interface_types, ONLY: c_Datatype
        INTEGER, VALUE :: x
        INTEGER(c_Datatype) :: res
        res = x
    END FUNCTION MPI_Datatype_f2c
    
    FUNCTION MPI_Datatype_c2f(x) result(res)
        USE mpi_c_interface_types, ONLY: c_Datatype
        INTEGER(c_Datatype), VALUE :: x
        INTEGER :: res
        res = x
    END FUNCTION MPI_Datatype_c2f
    
    FUNCTION MPI_Errhandler_f2c(x) result(res)
        USE mpi_c_interface_types, ONLY: c_Errhandler
        INTEGER, VALUE :: x
        INTEGER(c_Errhandler) :: res
        res = x
    END FUNCTION MPI_Errhandler_f2c
    
    FUNCTION MPI_Errhandler_c2f(x) result(res)
        USE mpi_c_interface_types, ONLY: c_Errhandler
        INTEGER(c_Errhandler), VALUE :: x
        INTEGER :: res
        res = x
    END FUNCTION MPI_Errhandler_c2f
    
    FUNCTION MPI_Group_f2c(x) result(res)
        USE mpi_c_interface_types, ONLY: c_Group
        INTEGER, VALUE :: x
        INTEGER(c_Group) :: res
        res = x
    END FUNCTION MPI_Group_f2c
    
    FUNCTION MPI_Group_c2f(x) result(res)
        USE mpi_c_interface_types, ONLY: c_Group
        INTEGER(c_Group), VALUE :: x
        INTEGER :: res
        res = x
    END FUNCTION MPI_Group_c2f
    
    FUNCTION MPI_Info_f2c(x) result(res)
        USE mpi_c_interface_types, ONLY: c_Info
        INTEGER, VALUE :: x
        INTEGER(c_Info) :: res
        res = x
    END FUNCTION MPI_Info_f2c
    
    FUNCTION MPI_Info_c2f(x) result(res)
        USE mpi_c_interface_types, ONLY: c_Info
        INTEGER(c_Info), VALUE :: x
        INTEGER :: res
        res = x
    END FUNCTION MPI_Info_c2f
    
    FUNCTION MPI_Op_f2c(x) result(res)
        USE mpi_c_interface_types, ONLY: c_Op
        INTEGER, VALUE :: x
        INTEGER(c_Op) :: res
        res = x
    END FUNCTION MPI_Op_f2c
    
    FUNCTION MPI_Op_c2f(x) result(res)
        USE mpi_c_interface_types, ONLY: c_Op
        INTEGER(c_Op), VALUE :: x
        INTEGER :: res
        res = x
    END FUNCTION MPI_Op_c2f
    
    FUNCTION MPI_Request_f2c(x) result(res)
        USE mpi_c_interface_types, ONLY: c_Request
        INTEGER, VALUE :: x
        INTEGER(c_Request) :: res
        res = x
    END FUNCTION MPI_Request_f2c
    
    FUNCTION MPI_Request_c2f(x) result(res)
        USE mpi_c_interface_types, ONLY: c_Request
        INTEGER(c_Request), VALUE :: x
        INTEGER :: res
        res = x
    END FUNCTION MPI_Request_c2f
    
    FUNCTION MPI_Win_f2c(x) result(res)
        USE mpi_c_interface_types, ONLY: c_Win
        INTEGER, VALUE :: x
        INTEGER(c_Win) :: res
        res = x
    END FUNCTION MPI_Win_f2c
    
    FUNCTION MPI_Win_c2f(x) result(res)
        USE mpi_c_interface_types, ONLY: c_Win
        INTEGER(c_Win), VALUE :: x
        INTEGER :: res
        res = x
    END FUNCTION MPI_Win_c2f
    
    FUNCTION MPI_Message_f2c(x) result(res)
        USE mpi_c_interface_types, ONLY: c_Message
        INTEGER, VALUE :: x
        INTEGER(c_Message) :: res
        res = x
    END FUNCTION MPI_Message_f2c
    
    FUNCTION MPI_Message_c2f(x) result(res)
        USE mpi_c_interface_types, ONLY: c_Message
        INTEGER(c_Message), VALUE :: x
        INTEGER :: res
        res = x
    END FUNCTION MPI_Message_c2f
    
    FUNCTION MPI_Session_f2c(x) result(res)
        USE mpi_c_interface_types, ONLY: c_Session
        INTEGER, VALUE :: x
        INTEGER(c_Session) :: res
        res = x
    END FUNCTION MPI_Session_f2c
    
    FUNCTION MPI_Session_c2f(x) result(res)
        USE mpi_c_interface_types, ONLY: c_Session
        INTEGER(c_Session), VALUE :: x
        INTEGER :: res
        res = x
    END FUNCTION MPI_Session_c2f
    
    FUNCTION MPIX_Stream_f2c(x) result(res)
        USE mpi_c_interface_types, ONLY: c_Stream
        INTEGER, VALUE :: x
        INTEGER(c_Stream) :: res
        res = x
    END FUNCTION MPIX_Stream_f2c
    
    FUNCTION MPIX_Stream_c2f(x) result(res)
        USE mpi_c_interface_types, ONLY: c_Stream
        INTEGER(c_Stream), VALUE :: x
        INTEGER :: res
        res = x
    END FUNCTION MPIX_Stream_c2f
    
END MODULE mpi_f08_types
