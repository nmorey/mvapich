/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpi_fortimpl.h"
#include "fortran_profile.h"



FORT_DLL_SPEC void FORT_CALL mpi_attr_delete_(MPI_Fint *comm, MPI_Fint *keyval, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Attr_delete((MPI_Comm) (*comm), (int) (*keyval));
}


FORT_DLL_SPEC void FORT_CALL mpi_attr_get_(MPI_Fint *comm, MPI_Fint *keyval, MPI_Fint *attribute_val, MPI_Fint *flag, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    void *attribute_val_i;
    int flag_i;
    *ierr = MPII_Comm_get_attr((MPI_Comm) (*comm), (int) (*keyval), &attribute_val_i, &flag_i, MPIR_ATTR_INT);
    if (*ierr || !flag_i) {
        *attribute_val = 0;
    } else {
        *attribute_val = (MPI_Aint) attribute_val_i;
    }
    if (*ierr == MPI_SUCCESS) {
        *flag = MPII_TO_FLOG(flag_i);
    }
}


FORT_DLL_SPEC void FORT_CALL mpi_attr_put_(MPI_Fint *comm, MPI_Fint *keyval, MPI_Fint *attribute_val, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPII_Comm_set_attr((MPI_Comm) (*comm), (int) (*keyval), (void *) (intptr_t) (*attribute_val), MPIR_ATTR_INT);
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_create_keyval_(MPI_Comm_copy_attr_function comm_copy_attr_fn, MPI_Comm_delete_attr_function comm_delete_attr_fn, MPI_Fint *comm_keyval, void *extra_state, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Comm_create_keyval(comm_copy_attr_fn, comm_delete_attr_fn, (int *) comm_keyval, extra_state);
    
#else  /* ! HAVE_FINT_IS_INT */
    int comm_keyval_i;
    *ierr = MPI_Comm_create_keyval(comm_copy_attr_fn, comm_delete_attr_fn, &comm_keyval_i, extra_state);
    *comm_keyval = (MPI_Fint) comm_keyval_i;
#endif
    if (!*ierr) {
        MPII_Keyval_set_f90_proxy((int) *comm_keyval);
    }
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_delete_attr_(MPI_Fint *comm, MPI_Fint *comm_keyval, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Comm_delete_attr((MPI_Comm) (*comm), (int) (*comm_keyval));
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_free_keyval_(MPI_Fint *comm_keyval, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Comm_free_keyval((int *) comm_keyval);
    
#else  /* ! HAVE_FINT_IS_INT */
    int comm_keyval_i;
    comm_keyval_i = (int) *comm_keyval;
    *ierr = MPI_Comm_free_keyval(&comm_keyval_i);
    *comm_keyval = (MPI_Fint) comm_keyval_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_get_attr_(MPI_Fint *comm, MPI_Fint *comm_keyval, MPI_Aint *attribute_val, MPI_Fint *flag, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    void *attribute_val_i;
    int flag_i;
    *ierr = MPII_Comm_get_attr((MPI_Comm) (*comm), (int) (*comm_keyval), &attribute_val_i, &flag_i, MPIR_ATTR_AINT);
    if (*ierr || !flag_i) {
        *attribute_val = 0;
    } else {
        *attribute_val = (MPI_Aint) attribute_val_i;
    }
    if (*ierr == MPI_SUCCESS) {
        *flag = MPII_TO_FLOG(flag_i);
    }
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_set_attr_(MPI_Fint *comm, MPI_Fint *comm_keyval, MPI_Aint *attribute_val, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPII_Comm_set_attr((MPI_Comm) (*comm), (int) (*comm_keyval), (void *) (intptr_t) (*attribute_val), MPIR_ATTR_AINT);
}


FORT_DLL_SPEC void FORT_CALL mpi_keyval_create_(MPI_Copy_function copy_fn, MPI_Delete_function delete_fn, MPI_Fint *keyval, void *extra_state, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Keyval_create(copy_fn, delete_fn, (int *) keyval, extra_state);
    
#else  /* ! HAVE_FINT_IS_INT */
    int keyval_i;
    *ierr = MPI_Keyval_create(copy_fn, delete_fn, &keyval_i, extra_state);
    *keyval = (MPI_Fint) keyval_i;
#endif
    if (!*ierr) {
        MPII_Keyval_set_f90_proxy((int) *keyval);
    }
}


FORT_DLL_SPEC void FORT_CALL mpi_keyval_free_(MPI_Fint *keyval, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Keyval_free((int *) keyval);
    
#else  /* ! HAVE_FINT_IS_INT */
    int keyval_i;
    keyval_i = (int) *keyval;
    *ierr = MPI_Keyval_free(&keyval_i);
    *keyval = (MPI_Fint) keyval_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_type_create_keyval_(MPI_Type_copy_attr_function type_copy_attr_fn, MPI_Type_delete_attr_function type_delete_attr_fn, MPI_Fint *type_keyval, void *extra_state, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Type_create_keyval(type_copy_attr_fn, type_delete_attr_fn, (int *) type_keyval, extra_state);
    
#else  /* ! HAVE_FINT_IS_INT */
    int type_keyval_i;
    *ierr = MPI_Type_create_keyval(type_copy_attr_fn, type_delete_attr_fn, &type_keyval_i, extra_state);
    *type_keyval = (MPI_Fint) type_keyval_i;
#endif
    if (!*ierr) {
        MPII_Keyval_set_f90_proxy((int) *type_keyval);
    }
}


FORT_DLL_SPEC void FORT_CALL mpi_type_delete_attr_(MPI_Fint *datatype, MPI_Fint *type_keyval, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Type_delete_attr((MPI_Datatype) (*datatype), (int) (*type_keyval));
}


FORT_DLL_SPEC void FORT_CALL mpi_type_free_keyval_(MPI_Fint *type_keyval, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Type_free_keyval((int *) type_keyval);
    
#else  /* ! HAVE_FINT_IS_INT */
    int type_keyval_i;
    type_keyval_i = (int) *type_keyval;
    *ierr = MPI_Type_free_keyval(&type_keyval_i);
    *type_keyval = (MPI_Fint) type_keyval_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_type_get_attr_(MPI_Fint *datatype, MPI_Fint *type_keyval, MPI_Aint *attribute_val, MPI_Fint *flag, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    void *attribute_val_i;
    int flag_i;
    *ierr = MPII_Type_get_attr((MPI_Datatype) (*datatype), (int) (*type_keyval), &attribute_val_i, &flag_i, MPIR_ATTR_AINT);
    if (*ierr || !flag_i) {
        *attribute_val = 0;
    } else {
        *attribute_val = (MPI_Aint) attribute_val_i;
    }
    if (*ierr == MPI_SUCCESS) {
        *flag = MPII_TO_FLOG(flag_i);
    }
}


FORT_DLL_SPEC void FORT_CALL mpi_type_set_attr_(MPI_Fint *datatype, MPI_Fint *type_keyval, MPI_Aint *attribute_val, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPII_Type_set_attr((MPI_Datatype) (*datatype), (int) (*type_keyval), (void *) (intptr_t) (*attribute_val), MPIR_ATTR_AINT);
}


FORT_DLL_SPEC void FORT_CALL mpi_win_create_keyval_(MPI_Win_copy_attr_function win_copy_attr_fn, MPI_Win_delete_attr_function win_delete_attr_fn, MPI_Fint *win_keyval, void *extra_state, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Win_create_keyval(win_copy_attr_fn, win_delete_attr_fn, (int *) win_keyval, extra_state);
    
#else  /* ! HAVE_FINT_IS_INT */
    int win_keyval_i;
    *ierr = MPI_Win_create_keyval(win_copy_attr_fn, win_delete_attr_fn, &win_keyval_i, extra_state);
    *win_keyval = (MPI_Fint) win_keyval_i;
#endif
    if (!*ierr) {
        MPII_Keyval_set_f90_proxy((int) *win_keyval);
    }
}


FORT_DLL_SPEC void FORT_CALL mpi_win_delete_attr_(MPI_Fint *win, MPI_Fint *win_keyval, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Win_delete_attr((MPI_Win) (*win), (int) (*win_keyval));
}


FORT_DLL_SPEC void FORT_CALL mpi_win_free_keyval_(MPI_Fint *win_keyval, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Win_free_keyval((int *) win_keyval);
    
#else  /* ! HAVE_FINT_IS_INT */
    int win_keyval_i;
    win_keyval_i = (int) *win_keyval;
    *ierr = MPI_Win_free_keyval(&win_keyval_i);
    *win_keyval = (MPI_Fint) win_keyval_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_win_get_attr_(MPI_Fint *win, MPI_Fint *win_keyval, MPI_Aint *attribute_val, MPI_Fint *flag, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    void *attribute_val_i;
    int flag_i;
    *ierr = MPII_Win_get_attr((MPI_Win) (*win), (int) (*win_keyval), &attribute_val_i, &flag_i, MPIR_ATTR_AINT);
    if (*ierr || !flag_i) {
        *attribute_val = 0;
    } else {
        *attribute_val = (MPI_Aint) attribute_val_i;
    }
    if (*ierr == MPI_SUCCESS) {
        *flag = MPII_TO_FLOG(flag_i);
    }
}


FORT_DLL_SPEC void FORT_CALL mpi_win_set_attr_(MPI_Fint *win, MPI_Fint *win_keyval, MPI_Aint *attribute_val, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPII_Win_set_attr((MPI_Win) (*win), (int) (*win_keyval), (void *) (intptr_t) (*attribute_val), MPIR_ATTR_AINT);
}


FORT_DLL_SPEC void FORT_CALL mpi_allgather_(void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
    *ierr = MPI_Allgather(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm));
}


FORT_DLL_SPEC void FORT_CALL mpi_allgather_init_(void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *info, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Allgather_init(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm), (MPI_Info) (*info), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Allgather_init(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm), (MPI_Info) (*info), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_allgatherv_(void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcounts, MPI_Fint *displs, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Allgatherv(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int *) recvcounts, (int *) displs, (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm));
    
#else  /* ! HAVE_FINT_IS_INT */
    int is_inter;
    int comm_size;
    MPI_Comm_test_inter((MPI_Comm) (*comm), &is_inter);
    if (is_inter) {
        MPI_Comm_remote_size((MPI_Comm) (*comm), &comm_size);
    } else {
        MPI_Comm_size((MPI_Comm) (*comm), &comm_size);
    }
    int *recvcounts_i;
    recvcounts_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        recvcounts_i[i] = (int) recvcounts[i];
    }
    int *displs_i;
    displs_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        displs_i[i] = (int) displs[i];
    }
    *ierr = MPI_Allgatherv(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, recvcounts_i, displs_i, (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm));
    free(recvcounts_i);
    free(displs_i);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_allgatherv_init_(void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcounts, MPI_Fint *displs, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *info, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Allgatherv_init(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int *) recvcounts, (int *) displs, (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm), (MPI_Info) (*info), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    int is_inter;
    int comm_size;
    MPI_Comm_test_inter((MPI_Comm) (*comm), &is_inter);
    if (is_inter) {
        MPI_Comm_remote_size((MPI_Comm) (*comm), &comm_size);
    } else {
        MPI_Comm_size((MPI_Comm) (*comm), &comm_size);
    }
    int *recvcounts_i;
    recvcounts_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        recvcounts_i[i] = (int) recvcounts[i];
    }
    int *displs_i;
    displs_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        displs_i[i] = (int) displs[i];
    }
    MPI_Request request_i;
    *ierr = MPI_Allgatherv_init(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, recvcounts_i, displs_i, (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm), (MPI_Info) (*info), &request_i);
    free(recvcounts_i);
    free(displs_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_allreduce_(void *sendbuf, void *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
    *ierr = MPI_Allreduce(sendbuf, recvbuf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Op) (*op), (MPI_Comm) (*comm));
}


FORT_DLL_SPEC void FORT_CALL mpi_allreduce_init_(void *sendbuf, void *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *info, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Allreduce_init(sendbuf, recvbuf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Op) (*op), (MPI_Comm) (*comm), (MPI_Info) (*info), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Allreduce_init(sendbuf, recvbuf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Op) (*op), (MPI_Comm) (*comm), (MPI_Info) (*info), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_alltoall_(void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
    *ierr = MPI_Alltoall(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm));
}


FORT_DLL_SPEC void FORT_CALL mpi_alltoall_init_(void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *info, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Alltoall_init(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm), (MPI_Info) (*info), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Alltoall_init(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm), (MPI_Info) (*info), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_alltoallv_(void *sendbuf, MPI_Fint *sendcounts, MPI_Fint *sdispls, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcounts, MPI_Fint *rdispls, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Alltoallv(sendbuf, (int *) sendcounts, (int *) sdispls, (MPI_Datatype) (*sendtype), recvbuf, (int *) recvcounts, (int *) rdispls, (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm));
    
#else  /* ! HAVE_FINT_IS_INT */
    int is_inter;
    int comm_size;
    MPI_Comm_test_inter((MPI_Comm) (*comm), &is_inter);
    if (is_inter) {
        MPI_Comm_remote_size((MPI_Comm) (*comm), &comm_size);
    } else {
        MPI_Comm_size((MPI_Comm) (*comm), &comm_size);
    }
    int *sendcounts_i;
    sendcounts_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        sendcounts_i[i] = (int) sendcounts[i];
    }
    int *sdispls_i;
    sdispls_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        sdispls_i[i] = (int) sdispls[i];
    }
    int *recvcounts_i;
    recvcounts_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        recvcounts_i[i] = (int) recvcounts[i];
    }
    int *rdispls_i;
    rdispls_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        rdispls_i[i] = (int) rdispls[i];
    }
    *ierr = MPI_Alltoallv(sendbuf, sendcounts_i, sdispls_i, (MPI_Datatype) (*sendtype), recvbuf, recvcounts_i, rdispls_i, (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm));
    free(sendcounts_i);
    free(sdispls_i);
    free(recvcounts_i);
    free(rdispls_i);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_alltoallv_init_(void *sendbuf, MPI_Fint *sendcounts, MPI_Fint *sdispls, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcounts, MPI_Fint *rdispls, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *info, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Alltoallv_init(sendbuf, (int *) sendcounts, (int *) sdispls, (MPI_Datatype) (*sendtype), recvbuf, (int *) recvcounts, (int *) rdispls, (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm), (MPI_Info) (*info), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    int is_inter;
    int comm_size;
    MPI_Comm_test_inter((MPI_Comm) (*comm), &is_inter);
    if (is_inter) {
        MPI_Comm_remote_size((MPI_Comm) (*comm), &comm_size);
    } else {
        MPI_Comm_size((MPI_Comm) (*comm), &comm_size);
    }
    int *sendcounts_i;
    sendcounts_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        sendcounts_i[i] = (int) sendcounts[i];
    }
    int *sdispls_i;
    sdispls_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        sdispls_i[i] = (int) sdispls[i];
    }
    int *recvcounts_i;
    recvcounts_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        recvcounts_i[i] = (int) recvcounts[i];
    }
    int *rdispls_i;
    rdispls_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        rdispls_i[i] = (int) rdispls[i];
    }
    MPI_Request request_i;
    *ierr = MPI_Alltoallv_init(sendbuf, sendcounts_i, sdispls_i, (MPI_Datatype) (*sendtype), recvbuf, recvcounts_i, rdispls_i, (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm), (MPI_Info) (*info), &request_i);
    free(sendcounts_i);
    free(sdispls_i);
    free(recvcounts_i);
    free(rdispls_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_alltoallw_(void *sendbuf, MPI_Fint *sendcounts, MPI_Fint *sdispls, MPI_Fint *sendtypes, void *recvbuf, MPI_Fint *recvcounts, MPI_Fint *rdispls, MPI_Fint *recvtypes, MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Alltoallw(sendbuf, (int *) sendcounts, (int *) sdispls, (int *) sendtypes, recvbuf, (int *) recvcounts, (int *) rdispls, (int *) recvtypes, (MPI_Comm) (*comm));
    
#else  /* ! HAVE_FINT_IS_INT */
    int is_inter;
    int comm_size;
    MPI_Comm_test_inter((MPI_Comm) (*comm), &is_inter);
    if (is_inter) {
        MPI_Comm_remote_size((MPI_Comm) (*comm), &comm_size);
    } else {
        MPI_Comm_size((MPI_Comm) (*comm), &comm_size);
    }
    int *sendcounts_i;
    sendcounts_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        sendcounts_i[i] = (int) sendcounts[i];
    }
    int *sdispls_i;
    sdispls_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        sdispls_i[i] = (int) sdispls[i];
    }
    MPI_Datatype *sendtypes_i;
    sendtypes_i = malloc(sizeof(MPI_Datatype) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        sendtypes_i[i] = (MPI_Datatype) sendtypes[i];
    }
    int *recvcounts_i;
    recvcounts_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        recvcounts_i[i] = (int) recvcounts[i];
    }
    int *rdispls_i;
    rdispls_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        rdispls_i[i] = (int) rdispls[i];
    }
    MPI_Datatype *recvtypes_i;
    recvtypes_i = malloc(sizeof(MPI_Datatype) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        recvtypes_i[i] = (MPI_Datatype) recvtypes[i];
    }
    *ierr = MPI_Alltoallw(sendbuf, sendcounts_i, sdispls_i, sendtypes_i, recvbuf, recvcounts_i, rdispls_i, recvtypes_i, (MPI_Comm) (*comm));
    free(sendcounts_i);
    free(sdispls_i);
    free(sendtypes_i);
    free(recvcounts_i);
    free(rdispls_i);
    free(recvtypes_i);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_alltoallw_init_(void *sendbuf, MPI_Fint *sendcounts, MPI_Fint *sdispls, MPI_Fint *sendtypes, void *recvbuf, MPI_Fint *recvcounts, MPI_Fint *rdispls, MPI_Fint *recvtypes, MPI_Fint *comm, MPI_Fint *info, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Alltoallw_init(sendbuf, (int *) sendcounts, (int *) sdispls, (int *) sendtypes, recvbuf, (int *) recvcounts, (int *) rdispls, (int *) recvtypes, (MPI_Comm) (*comm), (MPI_Info) (*info), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    int is_inter;
    int comm_size;
    MPI_Comm_test_inter((MPI_Comm) (*comm), &is_inter);
    if (is_inter) {
        MPI_Comm_remote_size((MPI_Comm) (*comm), &comm_size);
    } else {
        MPI_Comm_size((MPI_Comm) (*comm), &comm_size);
    }
    int *sendcounts_i;
    sendcounts_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        sendcounts_i[i] = (int) sendcounts[i];
    }
    int *sdispls_i;
    sdispls_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        sdispls_i[i] = (int) sdispls[i];
    }
    MPI_Datatype *sendtypes_i;
    sendtypes_i = malloc(sizeof(MPI_Datatype) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        sendtypes_i[i] = (MPI_Datatype) sendtypes[i];
    }
    int *recvcounts_i;
    recvcounts_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        recvcounts_i[i] = (int) recvcounts[i];
    }
    int *rdispls_i;
    rdispls_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        rdispls_i[i] = (int) rdispls[i];
    }
    MPI_Datatype *recvtypes_i;
    recvtypes_i = malloc(sizeof(MPI_Datatype) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        recvtypes_i[i] = (MPI_Datatype) recvtypes[i];
    }
    MPI_Request request_i;
    *ierr = MPI_Alltoallw_init(sendbuf, sendcounts_i, sdispls_i, sendtypes_i, recvbuf, recvcounts_i, rdispls_i, recvtypes_i, (MPI_Comm) (*comm), (MPI_Info) (*info), &request_i);
    free(sendcounts_i);
    free(sdispls_i);
    free(sendtypes_i);
    free(recvcounts_i);
    free(rdispls_i);
    free(recvtypes_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_barrier_(MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Barrier((MPI_Comm) (*comm));
}


FORT_DLL_SPEC void FORT_CALL mpi_barrier_init_(MPI_Fint *comm, MPI_Fint *info, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Barrier_init((MPI_Comm) (*comm), (MPI_Info) (*info), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Barrier_init((MPI_Comm) (*comm), (MPI_Info) (*info), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_bcast_(void *buffer, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buffer == MPIR_F_MPI_BOTTOM) {
        buffer = MPI_BOTTOM;
    }
    
    *ierr = MPI_Bcast(buffer, (int) (*count), (MPI_Datatype) (*datatype), (int) (*root), (MPI_Comm) (*comm));
}


FORT_DLL_SPEC void FORT_CALL mpi_bcast_init_(void *buffer, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *info, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buffer == MPIR_F_MPI_BOTTOM) {
        buffer = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Bcast_init(buffer, (int) (*count), (MPI_Datatype) (*datatype), (int) (*root), (MPI_Comm) (*comm), (MPI_Info) (*info), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Bcast_init(buffer, (int) (*count), (MPI_Datatype) (*datatype), (int) (*root), (MPI_Comm) (*comm), (MPI_Info) (*info), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_exscan_(void *sendbuf, void *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
    *ierr = MPI_Exscan(sendbuf, recvbuf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Op) (*op), (MPI_Comm) (*comm));
}


FORT_DLL_SPEC void FORT_CALL mpi_exscan_init_(void *sendbuf, void *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *info, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Exscan_init(sendbuf, recvbuf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Op) (*op), (MPI_Comm) (*comm), (MPI_Info) (*info), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Exscan_init(sendbuf, recvbuf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Op) (*op), (MPI_Comm) (*comm), (MPI_Info) (*info), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_gather_(void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
    *ierr = MPI_Gather(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (int) (*root), (MPI_Comm) (*comm));
}


FORT_DLL_SPEC void FORT_CALL mpi_gather_init_(void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *info, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Gather_init(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (int) (*root), (MPI_Comm) (*comm), (MPI_Info) (*info), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Gather_init(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (int) (*root), (MPI_Comm) (*comm), (MPI_Info) (*info), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_gatherv_(void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcounts, MPI_Fint *displs, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Gatherv(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int *) recvcounts, (int *) displs, (MPI_Datatype) (*recvtype), (int) (*root), (MPI_Comm) (*comm));
    
#else  /* ! HAVE_FINT_IS_INT */
    int is_inter;
    int comm_size;
    MPI_Comm_test_inter((MPI_Comm) (*comm), &is_inter);
    if (is_inter) {
        MPI_Comm_remote_size((MPI_Comm) (*comm), &comm_size);
    } else {
        MPI_Comm_size((MPI_Comm) (*comm), &comm_size);
    }
    int *recvcounts_i;
    recvcounts_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        recvcounts_i[i] = (int) recvcounts[i];
    }
    int *displs_i;
    displs_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        displs_i[i] = (int) displs[i];
    }
    *ierr = MPI_Gatherv(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, recvcounts_i, displs_i, (MPI_Datatype) (*recvtype), (int) (*root), (MPI_Comm) (*comm));
    free(recvcounts_i);
    free(displs_i);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_gatherv_init_(void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcounts, MPI_Fint *displs, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *info, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Gatherv_init(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int *) recvcounts, (int *) displs, (MPI_Datatype) (*recvtype), (int) (*root), (MPI_Comm) (*comm), (MPI_Info) (*info), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    int is_inter;
    int comm_size;
    MPI_Comm_test_inter((MPI_Comm) (*comm), &is_inter);
    if (is_inter) {
        MPI_Comm_remote_size((MPI_Comm) (*comm), &comm_size);
    } else {
        MPI_Comm_size((MPI_Comm) (*comm), &comm_size);
    }
    int *recvcounts_i;
    recvcounts_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        recvcounts_i[i] = (int) recvcounts[i];
    }
    int *displs_i;
    displs_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        displs_i[i] = (int) displs[i];
    }
    MPI_Request request_i;
    *ierr = MPI_Gatherv_init(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, recvcounts_i, displs_i, (MPI_Datatype) (*recvtype), (int) (*root), (MPI_Comm) (*comm), (MPI_Info) (*info), &request_i);
    free(recvcounts_i);
    free(displs_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_iallgather_(void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Iallgather(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Iallgather(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_iallgatherv_(void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcounts, MPI_Fint *displs, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Iallgatherv(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int *) recvcounts, (int *) displs, (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    int is_inter;
    int comm_size;
    MPI_Comm_test_inter((MPI_Comm) (*comm), &is_inter);
    if (is_inter) {
        MPI_Comm_remote_size((MPI_Comm) (*comm), &comm_size);
    } else {
        MPI_Comm_size((MPI_Comm) (*comm), &comm_size);
    }
    int *recvcounts_i;
    recvcounts_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        recvcounts_i[i] = (int) recvcounts[i];
    }
    int *displs_i;
    displs_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        displs_i[i] = (int) displs[i];
    }
    MPI_Request request_i;
    *ierr = MPI_Iallgatherv(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, recvcounts_i, displs_i, (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm), &request_i);
    free(recvcounts_i);
    free(displs_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_iallreduce_(void *sendbuf, void *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Iallreduce(sendbuf, recvbuf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Op) (*op), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Iallreduce(sendbuf, recvbuf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Op) (*op), (MPI_Comm) (*comm), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_ialltoall_(void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Ialltoall(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Ialltoall(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_ialltoallv_(void *sendbuf, MPI_Fint *sendcounts, MPI_Fint *sdispls, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcounts, MPI_Fint *rdispls, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Ialltoallv(sendbuf, (int *) sendcounts, (int *) sdispls, (MPI_Datatype) (*sendtype), recvbuf, (int *) recvcounts, (int *) rdispls, (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    int is_inter;
    int comm_size;
    MPI_Comm_test_inter((MPI_Comm) (*comm), &is_inter);
    if (is_inter) {
        MPI_Comm_remote_size((MPI_Comm) (*comm), &comm_size);
    } else {
        MPI_Comm_size((MPI_Comm) (*comm), &comm_size);
    }
    int *sendcounts_i;
    sendcounts_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        sendcounts_i[i] = (int) sendcounts[i];
    }
    int *sdispls_i;
    sdispls_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        sdispls_i[i] = (int) sdispls[i];
    }
    int *recvcounts_i;
    recvcounts_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        recvcounts_i[i] = (int) recvcounts[i];
    }
    int *rdispls_i;
    rdispls_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        rdispls_i[i] = (int) rdispls[i];
    }
    MPI_Request request_i;
    *ierr = MPI_Ialltoallv(sendbuf, sendcounts_i, sdispls_i, (MPI_Datatype) (*sendtype), recvbuf, recvcounts_i, rdispls_i, (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm), &request_i);
    free(sendcounts_i);
    free(sdispls_i);
    free(recvcounts_i);
    free(rdispls_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_ialltoallw_(void *sendbuf, MPI_Fint *sendcounts, MPI_Fint *sdispls, MPI_Fint *sendtypes, void *recvbuf, MPI_Fint *recvcounts, MPI_Fint *rdispls, MPI_Fint *recvtypes, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Ialltoallw(sendbuf, (int *) sendcounts, (int *) sdispls, (int *) sendtypes, recvbuf, (int *) recvcounts, (int *) rdispls, (int *) recvtypes, (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    int is_inter;
    int comm_size;
    MPI_Comm_test_inter((MPI_Comm) (*comm), &is_inter);
    if (is_inter) {
        MPI_Comm_remote_size((MPI_Comm) (*comm), &comm_size);
    } else {
        MPI_Comm_size((MPI_Comm) (*comm), &comm_size);
    }
    int *sendcounts_i;
    sendcounts_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        sendcounts_i[i] = (int) sendcounts[i];
    }
    int *sdispls_i;
    sdispls_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        sdispls_i[i] = (int) sdispls[i];
    }
    MPI_Datatype *sendtypes_i;
    sendtypes_i = malloc(sizeof(MPI_Datatype) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        sendtypes_i[i] = (MPI_Datatype) sendtypes[i];
    }
    int *recvcounts_i;
    recvcounts_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        recvcounts_i[i] = (int) recvcounts[i];
    }
    int *rdispls_i;
    rdispls_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        rdispls_i[i] = (int) rdispls[i];
    }
    MPI_Datatype *recvtypes_i;
    recvtypes_i = malloc(sizeof(MPI_Datatype) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        recvtypes_i[i] = (MPI_Datatype) recvtypes[i];
    }
    MPI_Request request_i;
    *ierr = MPI_Ialltoallw(sendbuf, sendcounts_i, sdispls_i, sendtypes_i, recvbuf, recvcounts_i, rdispls_i, recvtypes_i, (MPI_Comm) (*comm), &request_i);
    free(sendcounts_i);
    free(sdispls_i);
    free(sendtypes_i);
    free(recvcounts_i);
    free(rdispls_i);
    free(recvtypes_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_ibarrier_(MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Ibarrier((MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Ibarrier((MPI_Comm) (*comm), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_ibcast_(void *buffer, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buffer == MPIR_F_MPI_BOTTOM) {
        buffer = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Ibcast(buffer, (int) (*count), (MPI_Datatype) (*datatype), (int) (*root), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Ibcast(buffer, (int) (*count), (MPI_Datatype) (*datatype), (int) (*root), (MPI_Comm) (*comm), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_iexscan_(void *sendbuf, void *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Iexscan(sendbuf, recvbuf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Op) (*op), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Iexscan(sendbuf, recvbuf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Op) (*op), (MPI_Comm) (*comm), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_igather_(void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Igather(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (int) (*root), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Igather(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (int) (*root), (MPI_Comm) (*comm), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_igatherv_(void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcounts, MPI_Fint *displs, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Igatherv(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int *) recvcounts, (int *) displs, (MPI_Datatype) (*recvtype), (int) (*root), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    int is_inter;
    int comm_size;
    MPI_Comm_test_inter((MPI_Comm) (*comm), &is_inter);
    if (is_inter) {
        MPI_Comm_remote_size((MPI_Comm) (*comm), &comm_size);
    } else {
        MPI_Comm_size((MPI_Comm) (*comm), &comm_size);
    }
    int *recvcounts_i;
    recvcounts_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        recvcounts_i[i] = (int) recvcounts[i];
    }
    int *displs_i;
    displs_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        displs_i[i] = (int) displs[i];
    }
    MPI_Request request_i;
    *ierr = MPI_Igatherv(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, recvcounts_i, displs_i, (MPI_Datatype) (*recvtype), (int) (*root), (MPI_Comm) (*comm), &request_i);
    free(recvcounts_i);
    free(displs_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_ineighbor_allgather_(void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Ineighbor_allgather(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Ineighbor_allgather(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_ineighbor_allgatherv_(void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcounts, MPI_Fint *displs, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Ineighbor_allgatherv(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int *) recvcounts, (int *) displs, (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    int indegree, outdegree, weighted;
    MPI_Dist_graph_neighbors_count((MPI_Comm) (*comm), &indegree, &outdegree, &weighted);
    int *recvcounts_i;
    recvcounts_i = malloc(sizeof(int) * indegree);
    for (int i = 0; i < indegree; i++) {
        recvcounts_i[i] = (int) recvcounts[i];
    }
    int *displs_i;
    displs_i = malloc(sizeof(int) * indegree);
    for (int i = 0; i < indegree; i++) {
        displs_i[i] = (int) displs[i];
    }
    MPI_Request request_i;
    *ierr = MPI_Ineighbor_allgatherv(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, recvcounts_i, displs_i, (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm), &request_i);
    free(recvcounts_i);
    free(displs_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_ineighbor_alltoall_(void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Ineighbor_alltoall(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Ineighbor_alltoall(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_ineighbor_alltoallv_(void *sendbuf, MPI_Fint *sendcounts, MPI_Fint *sdispls, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcounts, MPI_Fint *rdispls, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Ineighbor_alltoallv(sendbuf, (int *) sendcounts, (int *) sdispls, (MPI_Datatype) (*sendtype), recvbuf, (int *) recvcounts, (int *) rdispls, (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    int indegree, outdegree, weighted;
    MPI_Dist_graph_neighbors_count((MPI_Comm) (*comm), &indegree, &outdegree, &weighted);
    int *sendcounts_i;
    sendcounts_i = malloc(sizeof(int) * indegree);
    for (int i = 0; i < indegree; i++) {
        sendcounts_i[i] = (int) sendcounts[i];
    }
    int *sdispls_i;
    sdispls_i = malloc(sizeof(int) * indegree);
    for (int i = 0; i < indegree; i++) {
        sdispls_i[i] = (int) sdispls[i];
    }
    int *recvcounts_i;
    recvcounts_i = malloc(sizeof(int) * outdegree);
    for (int i = 0; i < outdegree; i++) {
        recvcounts_i[i] = (int) recvcounts[i];
    }
    int *rdispls_i;
    rdispls_i = malloc(sizeof(int) * outdegree);
    for (int i = 0; i < outdegree; i++) {
        rdispls_i[i] = (int) rdispls[i];
    }
    MPI_Request request_i;
    *ierr = MPI_Ineighbor_alltoallv(sendbuf, sendcounts_i, sdispls_i, (MPI_Datatype) (*sendtype), recvbuf, recvcounts_i, rdispls_i, (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm), &request_i);
    free(sendcounts_i);
    free(sdispls_i);
    free(recvcounts_i);
    free(rdispls_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_ineighbor_alltoallw_(void *sendbuf, MPI_Fint *sendcounts, MPI_Aint *sdispls, MPI_Fint *sendtypes, void *recvbuf, MPI_Fint *recvcounts, MPI_Aint *rdispls, MPI_Fint *recvtypes, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Ineighbor_alltoallw(sendbuf, (int *) sendcounts, sdispls, (int *) sendtypes, recvbuf, (int *) recvcounts, rdispls, (int *) recvtypes, (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    int indegree, outdegree, weighted;
    MPI_Dist_graph_neighbors_count((MPI_Comm) (*comm), &indegree, &outdegree, &weighted);
    int *sendcounts_i;
    sendcounts_i = malloc(sizeof(int) * indegree);
    for (int i = 0; i < indegree; i++) {
        sendcounts_i[i] = (int) sendcounts[i];
    }
    MPI_Datatype *sendtypes_i;
    sendtypes_i = malloc(sizeof(MPI_Datatype) * indegree);
    for (int i = 0; i < indegree; i++) {
        sendtypes_i[i] = (MPI_Datatype) sendtypes[i];
    }
    int *recvcounts_i;
    recvcounts_i = malloc(sizeof(int) * outdegree);
    for (int i = 0; i < outdegree; i++) {
        recvcounts_i[i] = (int) recvcounts[i];
    }
    MPI_Datatype *recvtypes_i;
    recvtypes_i = malloc(sizeof(MPI_Datatype) * outdegree);
    for (int i = 0; i < outdegree; i++) {
        recvtypes_i[i] = (MPI_Datatype) recvtypes[i];
    }
    MPI_Request request_i;
    *ierr = MPI_Ineighbor_alltoallw(sendbuf, sendcounts_i, sdispls, sendtypes_i, recvbuf, recvcounts_i, rdispls, recvtypes_i, (MPI_Comm) (*comm), &request_i);
    free(sendcounts_i);
    free(sendtypes_i);
    free(recvcounts_i);
    free(recvtypes_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_ireduce_(void *sendbuf, void *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Ireduce(sendbuf, recvbuf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Op) (*op), (int) (*root), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Ireduce(sendbuf, recvbuf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Op) (*op), (int) (*root), (MPI_Comm) (*comm), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_ireduce_scatter_(void *sendbuf, void *recvbuf, MPI_Fint *recvcounts, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Ireduce_scatter(sendbuf, recvbuf, (int *) recvcounts, (MPI_Datatype) (*datatype), (MPI_Op) (*op), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    int comm_size;
    MPI_Comm_size((MPI_Comm) (*comm), &comm_size);
    int *recvcounts_i;
    recvcounts_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        recvcounts_i[i] = (int) recvcounts[i];
    }
    MPI_Request request_i;
    *ierr = MPI_Ireduce_scatter(sendbuf, recvbuf, recvcounts_i, (MPI_Datatype) (*datatype), (MPI_Op) (*op), (MPI_Comm) (*comm), &request_i);
    free(recvcounts_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_ireduce_scatter_block_(void *sendbuf, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Ireduce_scatter_block(sendbuf, recvbuf, (int) (*recvcount), (MPI_Datatype) (*datatype), (MPI_Op) (*op), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    int comm_size;
    MPI_Comm_size((MPI_Comm) (*comm), &comm_size);
    MPI_Request request_i;
    *ierr = MPI_Ireduce_scatter_block(sendbuf, recvbuf, (int) (*recvcount), (MPI_Datatype) (*datatype), (MPI_Op) (*op), (MPI_Comm) (*comm), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_iscan_(void *sendbuf, void *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Iscan(sendbuf, recvbuf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Op) (*op), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Iscan(sendbuf, recvbuf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Op) (*op), (MPI_Comm) (*comm), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_iscatter_(void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    } else if (recvbuf == MPIR_F_MPI_IN_PLACE) {
        recvbuf = MPI_IN_PLACE;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Iscatter(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (int) (*root), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Iscatter(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (int) (*root), (MPI_Comm) (*comm), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_iscatterv_(void *sendbuf, MPI_Fint *sendcounts, MPI_Fint *displs, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    } else if (recvbuf == MPIR_F_MPI_IN_PLACE) {
        recvbuf = MPI_IN_PLACE;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Iscatterv(sendbuf, (int *) sendcounts, (int *) displs, (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (int) (*root), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    int is_inter;
    int comm_size;
    MPI_Comm_test_inter((MPI_Comm) (*comm), &is_inter);
    if (is_inter) {
        MPI_Comm_remote_size((MPI_Comm) (*comm), &comm_size);
    } else {
        MPI_Comm_size((MPI_Comm) (*comm), &comm_size);
    }
    int *sendcounts_i;
    sendcounts_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        sendcounts_i[i] = (int) sendcounts[i];
    }
    int *displs_i;
    displs_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        displs_i[i] = (int) displs[i];
    }
    MPI_Request request_i;
    *ierr = MPI_Iscatterv(sendbuf, sendcounts_i, displs_i, (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (int) (*root), (MPI_Comm) (*comm), &request_i);
    free(sendcounts_i);
    free(displs_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_neighbor_allgather_(void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
    *ierr = MPI_Neighbor_allgather(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm));
}


FORT_DLL_SPEC void FORT_CALL mpi_neighbor_allgather_init_(void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *info, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Neighbor_allgather_init(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm), (MPI_Info) (*info), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Neighbor_allgather_init(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm), (MPI_Info) (*info), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_neighbor_allgatherv_(void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcounts, MPI_Fint *displs, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Neighbor_allgatherv(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int *) recvcounts, (int *) displs, (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm));
    
#else  /* ! HAVE_FINT_IS_INT */
    int indegree, outdegree, weighted;
    MPI_Dist_graph_neighbors_count((MPI_Comm) (*comm), &indegree, &outdegree, &weighted);
    int *recvcounts_i;
    recvcounts_i = malloc(sizeof(int) * indegree);
    for (int i = 0; i < indegree; i++) {
        recvcounts_i[i] = (int) recvcounts[i];
    }
    int *displs_i;
    displs_i = malloc(sizeof(int) * indegree);
    for (int i = 0; i < indegree; i++) {
        displs_i[i] = (int) displs[i];
    }
    *ierr = MPI_Neighbor_allgatherv(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, recvcounts_i, displs_i, (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm));
    free(recvcounts_i);
    free(displs_i);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_neighbor_allgatherv_init_(void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcounts, MPI_Fint *displs, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *info, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Neighbor_allgatherv_init(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int *) recvcounts, (int *) displs, (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm), (MPI_Info) (*info), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    int indegree, outdegree, weighted;
    MPI_Dist_graph_neighbors_count((MPI_Comm) (*comm), &indegree, &outdegree, &weighted);
    int *recvcounts_i;
    recvcounts_i = malloc(sizeof(int) * indegree);
    for (int i = 0; i < indegree; i++) {
        recvcounts_i[i] = (int) recvcounts[i];
    }
    int *displs_i;
    displs_i = malloc(sizeof(int) * indegree);
    for (int i = 0; i < indegree; i++) {
        displs_i[i] = (int) displs[i];
    }
    MPI_Request request_i;
    *ierr = MPI_Neighbor_allgatherv_init(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, recvcounts_i, displs_i, (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm), (MPI_Info) (*info), &request_i);
    free(recvcounts_i);
    free(displs_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_neighbor_alltoall_(void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
    *ierr = MPI_Neighbor_alltoall(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm));
}


FORT_DLL_SPEC void FORT_CALL mpi_neighbor_alltoall_init_(void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *info, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Neighbor_alltoall_init(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm), (MPI_Info) (*info), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Neighbor_alltoall_init(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm), (MPI_Info) (*info), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_neighbor_alltoallv_(void *sendbuf, MPI_Fint *sendcounts, MPI_Fint *sdispls, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcounts, MPI_Fint *rdispls, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Neighbor_alltoallv(sendbuf, (int *) sendcounts, (int *) sdispls, (MPI_Datatype) (*sendtype), recvbuf, (int *) recvcounts, (int *) rdispls, (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm));
    
#else  /* ! HAVE_FINT_IS_INT */
    int indegree, outdegree, weighted;
    MPI_Dist_graph_neighbors_count((MPI_Comm) (*comm), &indegree, &outdegree, &weighted);
    int *sendcounts_i;
    sendcounts_i = malloc(sizeof(int) * indegree);
    for (int i = 0; i < indegree; i++) {
        sendcounts_i[i] = (int) sendcounts[i];
    }
    int *sdispls_i;
    sdispls_i = malloc(sizeof(int) * indegree);
    for (int i = 0; i < indegree; i++) {
        sdispls_i[i] = (int) sdispls[i];
    }
    int *recvcounts_i;
    recvcounts_i = malloc(sizeof(int) * outdegree);
    for (int i = 0; i < outdegree; i++) {
        recvcounts_i[i] = (int) recvcounts[i];
    }
    int *rdispls_i;
    rdispls_i = malloc(sizeof(int) * outdegree);
    for (int i = 0; i < outdegree; i++) {
        rdispls_i[i] = (int) rdispls[i];
    }
    *ierr = MPI_Neighbor_alltoallv(sendbuf, sendcounts_i, sdispls_i, (MPI_Datatype) (*sendtype), recvbuf, recvcounts_i, rdispls_i, (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm));
    free(sendcounts_i);
    free(sdispls_i);
    free(recvcounts_i);
    free(rdispls_i);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_neighbor_alltoallv_init_(void *sendbuf, MPI_Fint *sendcounts, MPI_Fint *sdispls, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcounts, MPI_Fint *rdispls, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *info, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Neighbor_alltoallv_init(sendbuf, (int *) sendcounts, (int *) sdispls, (MPI_Datatype) (*sendtype), recvbuf, (int *) recvcounts, (int *) rdispls, (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm), (MPI_Info) (*info), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    int indegree, outdegree, weighted;
    MPI_Dist_graph_neighbors_count((MPI_Comm) (*comm), &indegree, &outdegree, &weighted);
    int *sendcounts_i;
    sendcounts_i = malloc(sizeof(int) * indegree);
    for (int i = 0; i < indegree; i++) {
        sendcounts_i[i] = (int) sendcounts[i];
    }
    int *sdispls_i;
    sdispls_i = malloc(sizeof(int) * indegree);
    for (int i = 0; i < indegree; i++) {
        sdispls_i[i] = (int) sdispls[i];
    }
    int *recvcounts_i;
    recvcounts_i = malloc(sizeof(int) * outdegree);
    for (int i = 0; i < outdegree; i++) {
        recvcounts_i[i] = (int) recvcounts[i];
    }
    int *rdispls_i;
    rdispls_i = malloc(sizeof(int) * outdegree);
    for (int i = 0; i < outdegree; i++) {
        rdispls_i[i] = (int) rdispls[i];
    }
    MPI_Request request_i;
    *ierr = MPI_Neighbor_alltoallv_init(sendbuf, sendcounts_i, sdispls_i, (MPI_Datatype) (*sendtype), recvbuf, recvcounts_i, rdispls_i, (MPI_Datatype) (*recvtype), (MPI_Comm) (*comm), (MPI_Info) (*info), &request_i);
    free(sendcounts_i);
    free(sdispls_i);
    free(recvcounts_i);
    free(rdispls_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_neighbor_alltoallw_(void *sendbuf, MPI_Fint *sendcounts, MPI_Aint *sdispls, MPI_Fint *sendtypes, void *recvbuf, MPI_Fint *recvcounts, MPI_Aint *rdispls, MPI_Fint *recvtypes, MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Neighbor_alltoallw(sendbuf, (int *) sendcounts, sdispls, (int *) sendtypes, recvbuf, (int *) recvcounts, rdispls, (int *) recvtypes, (MPI_Comm) (*comm));
    
#else  /* ! HAVE_FINT_IS_INT */
    int indegree, outdegree, weighted;
    MPI_Dist_graph_neighbors_count((MPI_Comm) (*comm), &indegree, &outdegree, &weighted);
    int *sendcounts_i;
    sendcounts_i = malloc(sizeof(int) * indegree);
    for (int i = 0; i < indegree; i++) {
        sendcounts_i[i] = (int) sendcounts[i];
    }
    MPI_Datatype *sendtypes_i;
    sendtypes_i = malloc(sizeof(MPI_Datatype) * indegree);
    for (int i = 0; i < indegree; i++) {
        sendtypes_i[i] = (MPI_Datatype) sendtypes[i];
    }
    int *recvcounts_i;
    recvcounts_i = malloc(sizeof(int) * outdegree);
    for (int i = 0; i < outdegree; i++) {
        recvcounts_i[i] = (int) recvcounts[i];
    }
    MPI_Datatype *recvtypes_i;
    recvtypes_i = malloc(sizeof(MPI_Datatype) * outdegree);
    for (int i = 0; i < outdegree; i++) {
        recvtypes_i[i] = (MPI_Datatype) recvtypes[i];
    }
    *ierr = MPI_Neighbor_alltoallw(sendbuf, sendcounts_i, sdispls, sendtypes_i, recvbuf, recvcounts_i, rdispls, recvtypes_i, (MPI_Comm) (*comm));
    free(sendcounts_i);
    free(sendtypes_i);
    free(recvcounts_i);
    free(recvtypes_i);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_neighbor_alltoallw_init_(void *sendbuf, MPI_Fint *sendcounts, MPI_Aint *sdispls, MPI_Fint *sendtypes, void *recvbuf, MPI_Fint *recvcounts, MPI_Aint *rdispls, MPI_Fint *recvtypes, MPI_Fint *comm, MPI_Fint *info, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Neighbor_alltoallw_init(sendbuf, (int *) sendcounts, sdispls, (int *) sendtypes, recvbuf, (int *) recvcounts, rdispls, (int *) recvtypes, (MPI_Comm) (*comm), (MPI_Info) (*info), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    int indegree, outdegree, weighted;
    MPI_Dist_graph_neighbors_count((MPI_Comm) (*comm), &indegree, &outdegree, &weighted);
    int *sendcounts_i;
    sendcounts_i = malloc(sizeof(int) * indegree);
    for (int i = 0; i < indegree; i++) {
        sendcounts_i[i] = (int) sendcounts[i];
    }
    MPI_Datatype *sendtypes_i;
    sendtypes_i = malloc(sizeof(MPI_Datatype) * indegree);
    for (int i = 0; i < indegree; i++) {
        sendtypes_i[i] = (MPI_Datatype) sendtypes[i];
    }
    int *recvcounts_i;
    recvcounts_i = malloc(sizeof(int) * outdegree);
    for (int i = 0; i < outdegree; i++) {
        recvcounts_i[i] = (int) recvcounts[i];
    }
    MPI_Datatype *recvtypes_i;
    recvtypes_i = malloc(sizeof(MPI_Datatype) * outdegree);
    for (int i = 0; i < outdegree; i++) {
        recvtypes_i[i] = (MPI_Datatype) recvtypes[i];
    }
    MPI_Request request_i;
    *ierr = MPI_Neighbor_alltoallw_init(sendbuf, sendcounts_i, sdispls, sendtypes_i, recvbuf, recvcounts_i, rdispls, recvtypes_i, (MPI_Comm) (*comm), (MPI_Info) (*info), &request_i);
    free(sendcounts_i);
    free(sendtypes_i);
    free(recvcounts_i);
    free(recvtypes_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_reduce_(void *sendbuf, void *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
    *ierr = MPI_Reduce(sendbuf, recvbuf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Op) (*op), (int) (*root), (MPI_Comm) (*comm));
}


FORT_DLL_SPEC void FORT_CALL mpi_reduce_init_(void *sendbuf, void *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *info, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Reduce_init(sendbuf, recvbuf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Op) (*op), (int) (*root), (MPI_Comm) (*comm), (MPI_Info) (*info), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Reduce_init(sendbuf, recvbuf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Op) (*op), (int) (*root), (MPI_Comm) (*comm), (MPI_Info) (*info), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_reduce_local_(void *inbuf, void *inoutbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (inbuf == MPIR_F_MPI_BOTTOM) {
        inbuf = MPI_BOTTOM;
    } else if (inbuf == MPIR_F_MPI_IN_PLACE) {
        inbuf = MPI_IN_PLACE;
    }
    
    if (inoutbuf == MPIR_F_MPI_BOTTOM) {
        inoutbuf = MPI_BOTTOM;
    }
    
    *ierr = MPI_Reduce_local(inbuf, inoutbuf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Op) (*op));
}


FORT_DLL_SPEC void FORT_CALL mpi_reduce_scatter_(void *sendbuf, void *recvbuf, MPI_Fint *recvcounts, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Reduce_scatter(sendbuf, recvbuf, (int *) recvcounts, (MPI_Datatype) (*datatype), (MPI_Op) (*op), (MPI_Comm) (*comm));
    
#else  /* ! HAVE_FINT_IS_INT */
    int comm_size;
    MPI_Comm_size((MPI_Comm) (*comm), &comm_size);
    int *recvcounts_i;
    recvcounts_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        recvcounts_i[i] = (int) recvcounts[i];
    }
    *ierr = MPI_Reduce_scatter(sendbuf, recvbuf, recvcounts_i, (MPI_Datatype) (*datatype), (MPI_Op) (*op), (MPI_Comm) (*comm));
    free(recvcounts_i);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_reduce_scatter_block_(void *sendbuf, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Reduce_scatter_block(sendbuf, recvbuf, (int) (*recvcount), (MPI_Datatype) (*datatype), (MPI_Op) (*op), (MPI_Comm) (*comm));
    
#else  /* ! HAVE_FINT_IS_INT */
    int comm_size;
    MPI_Comm_size((MPI_Comm) (*comm), &comm_size);
    *ierr = MPI_Reduce_scatter_block(sendbuf, recvbuf, (int) (*recvcount), (MPI_Datatype) (*datatype), (MPI_Op) (*op), (MPI_Comm) (*comm));
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_reduce_scatter_block_init_(void *sendbuf, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *info, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Reduce_scatter_block_init(sendbuf, recvbuf, (int) (*recvcount), (MPI_Datatype) (*datatype), (MPI_Op) (*op), (MPI_Comm) (*comm), (MPI_Info) (*info), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    int comm_size;
    MPI_Comm_size((MPI_Comm) (*comm), &comm_size);
    MPI_Request request_i;
    *ierr = MPI_Reduce_scatter_block_init(sendbuf, recvbuf, (int) (*recvcount), (MPI_Datatype) (*datatype), (MPI_Op) (*op), (MPI_Comm) (*comm), (MPI_Info) (*info), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_reduce_scatter_init_(void *sendbuf, void *recvbuf, MPI_Fint *recvcounts, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *info, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Reduce_scatter_init(sendbuf, recvbuf, (int *) recvcounts, (MPI_Datatype) (*datatype), (MPI_Op) (*op), (MPI_Comm) (*comm), (MPI_Info) (*info), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    int comm_size;
    MPI_Comm_size((MPI_Comm) (*comm), &comm_size);
    int *recvcounts_i;
    recvcounts_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        recvcounts_i[i] = (int) recvcounts[i];
    }
    MPI_Request request_i;
    *ierr = MPI_Reduce_scatter_init(sendbuf, recvbuf, recvcounts_i, (MPI_Datatype) (*datatype), (MPI_Op) (*op), (MPI_Comm) (*comm), (MPI_Info) (*info), &request_i);
    free(recvcounts_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_scan_(void *sendbuf, void *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
    *ierr = MPI_Scan(sendbuf, recvbuf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Op) (*op), (MPI_Comm) (*comm));
}


FORT_DLL_SPEC void FORT_CALL mpi_scan_init_(void *sendbuf, void *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *info, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
        sendbuf = MPI_IN_PLACE;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Scan_init(sendbuf, recvbuf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Op) (*op), (MPI_Comm) (*comm), (MPI_Info) (*info), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Scan_init(sendbuf, recvbuf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Op) (*op), (MPI_Comm) (*comm), (MPI_Info) (*info), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_scatter_(void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    } else if (recvbuf == MPIR_F_MPI_IN_PLACE) {
        recvbuf = MPI_IN_PLACE;
    }
    
    *ierr = MPI_Scatter(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (int) (*root), (MPI_Comm) (*comm));
}


FORT_DLL_SPEC void FORT_CALL mpi_scatter_init_(void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *info, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    } else if (recvbuf == MPIR_F_MPI_IN_PLACE) {
        recvbuf = MPI_IN_PLACE;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Scatter_init(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (int) (*root), (MPI_Comm) (*comm), (MPI_Info) (*info), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Scatter_init(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (int) (*root), (MPI_Comm) (*comm), (MPI_Info) (*info), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_scatterv_(void *sendbuf, MPI_Fint *sendcounts, MPI_Fint *displs, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    } else if (recvbuf == MPIR_F_MPI_IN_PLACE) {
        recvbuf = MPI_IN_PLACE;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Scatterv(sendbuf, (int *) sendcounts, (int *) displs, (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (int) (*root), (MPI_Comm) (*comm));
    
#else  /* ! HAVE_FINT_IS_INT */
    int is_inter;
    int comm_size;
    MPI_Comm_test_inter((MPI_Comm) (*comm), &is_inter);
    if (is_inter) {
        MPI_Comm_remote_size((MPI_Comm) (*comm), &comm_size);
    } else {
        MPI_Comm_size((MPI_Comm) (*comm), &comm_size);
    }
    int *sendcounts_i;
    sendcounts_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        sendcounts_i[i] = (int) sendcounts[i];
    }
    int *displs_i;
    displs_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        displs_i[i] = (int) displs[i];
    }
    *ierr = MPI_Scatterv(sendbuf, sendcounts_i, displs_i, (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (int) (*root), (MPI_Comm) (*comm));
    free(sendcounts_i);
    free(displs_i);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_scatterv_init_(void *sendbuf, MPI_Fint *sendcounts, MPI_Fint *displs, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *info, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    } else if (recvbuf == MPIR_F_MPI_IN_PLACE) {
        recvbuf = MPI_IN_PLACE;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Scatterv_init(sendbuf, (int *) sendcounts, (int *) displs, (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (int) (*root), (MPI_Comm) (*comm), (MPI_Info) (*info), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    int is_inter;
    int comm_size;
    MPI_Comm_test_inter((MPI_Comm) (*comm), &is_inter);
    if (is_inter) {
        MPI_Comm_remote_size((MPI_Comm) (*comm), &comm_size);
    } else {
        MPI_Comm_size((MPI_Comm) (*comm), &comm_size);
    }
    int *sendcounts_i;
    sendcounts_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        sendcounts_i[i] = (int) sendcounts[i];
    }
    int *displs_i;
    displs_i = malloc(sizeof(int) * comm_size);
    for (int i = 0; i < comm_size; i++) {
        displs_i[i] = (int) displs[i];
    }
    MPI_Request request_i;
    *ierr = MPI_Scatterv_init(sendbuf, sendcounts_i, displs_i, (MPI_Datatype) (*sendtype), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (int) (*root), (MPI_Comm) (*comm), (MPI_Info) (*info), &request_i);
    free(sendcounts_i);
    free(displs_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_compare_(MPI_Fint *comm1, MPI_Fint *comm2, MPI_Fint *result, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Comm_compare((MPI_Comm) (*comm1), (MPI_Comm) (*comm2), (int *) result);
    
#else  /* ! HAVE_FINT_IS_INT */
    int result_i;
    *ierr = MPI_Comm_compare((MPI_Comm) (*comm1), (MPI_Comm) (*comm2), &result_i);
    *result = (MPI_Fint) result_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_create_(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *newcomm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Comm_create((MPI_Comm) (*comm), (MPI_Group) (*group), (MPI_Comm *) newcomm);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Comm newcomm_i;
    *ierr = MPI_Comm_create((MPI_Comm) (*comm), (MPI_Group) (*group), &newcomm_i);
    *newcomm = (MPI_Fint) newcomm_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_create_group_(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *tag, MPI_Fint *newcomm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Comm_create_group((MPI_Comm) (*comm), (MPI_Group) (*group), (int) (*tag), (MPI_Comm *) newcomm);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Comm newcomm_i;
    *ierr = MPI_Comm_create_group((MPI_Comm) (*comm), (MPI_Group) (*group), (int) (*tag), &newcomm_i);
    *newcomm = (MPI_Fint) newcomm_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_dup_(MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Comm_dup((MPI_Comm) (*comm), (MPI_Comm *) newcomm);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Comm newcomm_i;
    *ierr = MPI_Comm_dup((MPI_Comm) (*comm), &newcomm_i);
    *newcomm = (MPI_Fint) newcomm_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_dup_with_info_(MPI_Fint *comm, MPI_Fint *info, MPI_Fint *newcomm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Comm_dup_with_info((MPI_Comm) (*comm), (MPI_Info) (*info), (MPI_Comm *) newcomm);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Comm newcomm_i;
    *ierr = MPI_Comm_dup_with_info((MPI_Comm) (*comm), (MPI_Info) (*info), &newcomm_i);
    *newcomm = (MPI_Fint) newcomm_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_free_(MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Comm_free((MPI_Comm *) comm);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Comm comm_i;
    comm_i = (MPI_Comm) *comm;
    *ierr = MPI_Comm_free(&comm_i);
    *comm = (MPI_Fint) comm_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_get_info_(MPI_Fint *comm, MPI_Fint *info_used, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Comm_get_info((MPI_Comm) (*comm), (MPI_Info *) info_used);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Info info_used_i;
    *ierr = MPI_Comm_get_info((MPI_Comm) (*comm), &info_used_i);
    *info_used = (MPI_Fint) info_used_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_get_name_(MPI_Fint *comm, char *comm_name FORT_MIXED_LEN(comm_name_len), MPI_Fint *resultlen, MPI_Fint *ierr FORT_END_LEN(comm_name_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *comm_name_i = malloc(comm_name_len + 1);
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Comm_get_name((MPI_Comm) (*comm), comm_name_i, (int *) resultlen);
    
#else  /* ! HAVE_FINT_IS_INT */
    int resultlen_i;
    *ierr = MPI_Comm_get_name((MPI_Comm) (*comm), comm_name_i, &resultlen_i);
    *resultlen = (MPI_Fint) resultlen_i;
#endif
    if (*ierr == MPI_SUCCESS) {
        MPIR_fort_copy_str_from_c(comm_name, comm_name_len, comm_name_i);
    }
    free(comm_name_i);
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_group_(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Comm_group((MPI_Comm) (*comm), (MPI_Group *) group);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Group group_i;
    *ierr = MPI_Comm_group((MPI_Comm) (*comm), &group_i);
    *group = (MPI_Fint) group_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_idup_(MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Comm_idup((MPI_Comm) (*comm), (MPI_Comm *) newcomm, (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Comm newcomm_i;
    MPI_Request request_i;
    *ierr = MPI_Comm_idup((MPI_Comm) (*comm), &newcomm_i, &request_i);
    *newcomm = (MPI_Fint) newcomm_i;
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_idup_with_info_(MPI_Fint *comm, MPI_Fint *info, MPI_Fint *newcomm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Comm_idup_with_info((MPI_Comm) (*comm), (MPI_Info) (*info), (MPI_Comm *) newcomm, (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Comm newcomm_i;
    MPI_Request request_i;
    *ierr = MPI_Comm_idup_with_info((MPI_Comm) (*comm), (MPI_Info) (*info), &newcomm_i, &request_i);
    *newcomm = (MPI_Fint) newcomm_i;
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_rank_(MPI_Fint *comm, MPI_Fint *rank, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Comm_rank((MPI_Comm) (*comm), (int *) rank);
    
#else  /* ! HAVE_FINT_IS_INT */
    int rank_i;
    *ierr = MPI_Comm_rank((MPI_Comm) (*comm), &rank_i);
    *rank = (MPI_Fint) rank_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_remote_group_(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Comm_remote_group((MPI_Comm) (*comm), (MPI_Group *) group);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Group group_i;
    *ierr = MPI_Comm_remote_group((MPI_Comm) (*comm), &group_i);
    *group = (MPI_Fint) group_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_remote_size_(MPI_Fint *comm, MPI_Fint *size, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Comm_remote_size((MPI_Comm) (*comm), (int *) size);
    
#else  /* ! HAVE_FINT_IS_INT */
    int size_i;
    *ierr = MPI_Comm_remote_size((MPI_Comm) (*comm), &size_i);
    *size = (MPI_Fint) size_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_set_info_(MPI_Fint *comm, MPI_Fint *info, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Comm_set_info((MPI_Comm) (*comm), (MPI_Info) (*info));
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_set_name_(MPI_Fint *comm, char *comm_name FORT_MIXED_LEN(comm_name_len), MPI_Fint *ierr FORT_END_LEN(comm_name_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *comm_name_i = MPIR_fort_dup_str(comm_name, comm_name_len);
    *ierr = MPI_Comm_set_name((MPI_Comm) (*comm), comm_name_i);
    free(comm_name_i);
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_size_(MPI_Fint *comm, MPI_Fint *size, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Comm_size((MPI_Comm) (*comm), (int *) size);
    
#else  /* ! HAVE_FINT_IS_INT */
    int size_i;
    *ierr = MPI_Comm_size((MPI_Comm) (*comm), &size_i);
    *size = (MPI_Fint) size_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_split_(MPI_Fint *comm, MPI_Fint *color, MPI_Fint *key, MPI_Fint *newcomm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Comm_split((MPI_Comm) (*comm), (int) (*color), (int) (*key), (MPI_Comm *) newcomm);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Comm newcomm_i;
    *ierr = MPI_Comm_split((MPI_Comm) (*comm), (int) (*color), (int) (*key), &newcomm_i);
    *newcomm = (MPI_Fint) newcomm_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_split_type_(MPI_Fint *comm, MPI_Fint *split_type, MPI_Fint *key, MPI_Fint *info, MPI_Fint *newcomm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Comm_split_type((MPI_Comm) (*comm), (int) (*split_type), (int) (*key), (MPI_Info) (*info), (MPI_Comm *) newcomm);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Comm newcomm_i;
    *ierr = MPI_Comm_split_type((MPI_Comm) (*comm), (int) (*split_type), (int) (*key), (MPI_Info) (*info), &newcomm_i);
    *newcomm = (MPI_Fint) newcomm_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_test_inter_(MPI_Fint *comm, MPI_Fint *flag, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    int flag_i;
    *ierr = MPI_Comm_test_inter((MPI_Comm) (*comm), &flag_i);
    if (*ierr == MPI_SUCCESS) {
        *flag = MPII_TO_FLOG(flag_i);
    }
}


FORT_DLL_SPEC void FORT_CALL mpi_intercomm_create_(MPI_Fint *local_comm, MPI_Fint *local_leader, MPI_Fint *peer_comm, MPI_Fint *remote_leader, MPI_Fint *tag, MPI_Fint *newintercomm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Intercomm_create((MPI_Comm) (*local_comm), (int) (*local_leader), (MPI_Comm) (*peer_comm), (int) (*remote_leader), (int) (*tag), (MPI_Comm *) newintercomm);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Comm newintercomm_i;
    *ierr = MPI_Intercomm_create((MPI_Comm) (*local_comm), (int) (*local_leader), (MPI_Comm) (*peer_comm), (int) (*remote_leader), (int) (*tag), &newintercomm_i);
    *newintercomm = (MPI_Fint) newintercomm_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_intercomm_create_from_groups_(MPI_Fint *local_group, MPI_Fint *local_leader, MPI_Fint *remote_group, MPI_Fint *remote_leader, char *stringtag FORT_MIXED_LEN(stringtag_len), MPI_Fint *info, MPI_Fint *errhandler, MPI_Fint *newintercomm, MPI_Fint *ierr FORT_END_LEN(stringtag_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *stringtag_i = MPIR_fort_dup_str(stringtag, stringtag_len);
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Intercomm_create_from_groups((MPI_Group) (*local_group), (int) (*local_leader), (MPI_Group) (*remote_group), (int) (*remote_leader), stringtag_i, (MPI_Info) (*info), (MPI_Errhandler) (*errhandler), (MPI_Comm *) newintercomm);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Comm newintercomm_i;
    *ierr = MPI_Intercomm_create_from_groups((MPI_Group) (*local_group), (int) (*local_leader), (MPI_Group) (*remote_group), (int) (*remote_leader), stringtag_i, (MPI_Info) (*info), (MPI_Errhandler) (*errhandler), &newintercomm_i);
    *newintercomm = (MPI_Fint) newintercomm_i;
#endif
    free(stringtag_i);
}


FORT_DLL_SPEC void FORT_CALL mpi_intercomm_merge_(MPI_Fint *intercomm, MPI_Fint *high, MPI_Fint *newintracomm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Intercomm_merge((MPI_Comm) (*intercomm), *high, (MPI_Comm *) newintracomm);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Comm newintracomm_i;
    *ierr = MPI_Intercomm_merge((MPI_Comm) (*intercomm), *high, &newintracomm_i);
    *newintracomm = (MPI_Fint) newintracomm_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpix_comm_test_threadcomm_(MPI_Fint *comm, MPI_Fint *flag, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    int flag_i;
    *ierr = MPIX_Comm_test_threadcomm((MPI_Comm) (*comm), &flag_i);
    if (*ierr == MPI_SUCCESS) {
        *flag = MPII_TO_FLOG(flag_i);
    }
}


FORT_DLL_SPEC void FORT_CALL mpix_comm_revoke_(MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPIX_Comm_revoke((MPI_Comm) (*comm));
}


FORT_DLL_SPEC void FORT_CALL mpix_comm_shrink_(MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPIX_Comm_shrink((MPI_Comm) (*comm), (MPI_Comm *) newcomm);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Comm newcomm_i;
    *ierr = MPIX_Comm_shrink((MPI_Comm) (*comm), &newcomm_i);
    *newcomm = (MPI_Fint) newcomm_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpix_comm_failure_ack_(MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPIX_Comm_failure_ack((MPI_Comm) (*comm));
}


FORT_DLL_SPEC void FORT_CALL mpix_comm_failure_get_acked_(MPI_Fint *comm, MPI_Fint *failedgrp, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPIX_Comm_failure_get_acked((MPI_Comm) (*comm), (MPI_Group *) failedgrp);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Group failedgrp_i;
    *ierr = MPIX_Comm_failure_get_acked((MPI_Comm) (*comm), &failedgrp_i);
    *failedgrp = (MPI_Fint) failedgrp_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpix_comm_agree_(MPI_Fint *comm, MPI_Fint *flag, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    int flag_i;
    *ierr = MPIX_Comm_agree((MPI_Comm) (*comm), &flag_i);
    if (*ierr == MPI_SUCCESS) {
        *flag = MPII_TO_FLOG(flag_i);
    }
}


FORT_DLL_SPEC void FORT_CALL mpix_comm_get_failed_(MPI_Fint *comm, MPI_Fint *failedgrp, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPIX_Comm_get_failed((MPI_Comm) (*comm), (MPI_Group *) failedgrp);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Group failedgrp_i;
    *ierr = MPIX_Comm_get_failed((MPI_Comm) (*comm), &failedgrp_i);
    *failedgrp = (MPI_Fint) failedgrp_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_get_address_(void *location, MPI_Aint *address, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (location == MPIR_F_MPI_BOTTOM) {
        location = MPI_BOTTOM;
    }
    
    *ierr = MPI_Get_address(location, address);
}


FORT_DLL_SPEC void FORT_CALL mpi_get_count_(MPI_Fint *status, MPI_Fint *datatype, MPI_Fint *count, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Get_count((MPI_Status *) status, (MPI_Datatype) (*datatype), (int *) count);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    status_arg = (MPI_Status *) status_i;
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status_i[i] = (int) status[i];
    }
    int count_i;
    *ierr = MPI_Get_count(status_arg, (MPI_Datatype) (*datatype), &count_i);
    *count = (MPI_Fint) count_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_get_elements_(MPI_Fint *status, MPI_Fint *datatype, MPI_Fint *count, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Get_elements((MPI_Status *) status, (MPI_Datatype) (*datatype), (int *) count);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    status_arg = (MPI_Status *) status_i;
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status_i[i] = (int) status[i];
    }
    int count_i;
    *ierr = MPI_Get_elements(status_arg, (MPI_Datatype) (*datatype), &count_i);
    *count = (MPI_Fint) count_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_get_elements_x_(MPI_Fint *status, MPI_Fint *datatype, MPI_Count *count, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Get_elements_x((MPI_Status *) status, (MPI_Datatype) (*datatype), count);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    status_arg = (MPI_Status *) status_i;
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status_i[i] = (int) status[i];
    }
    *ierr = MPI_Get_elements_x(status_arg, (MPI_Datatype) (*datatype), count);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_pack_(void *inbuf, MPI_Fint *incount, MPI_Fint *datatype, void *outbuf, MPI_Fint *outsize, MPI_Fint *position, MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (inbuf == MPIR_F_MPI_BOTTOM) {
        inbuf = MPI_BOTTOM;
    }
    
    if (outbuf == MPIR_F_MPI_BOTTOM) {
        outbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Pack(inbuf, (int) (*incount), (MPI_Datatype) (*datatype), outbuf, (int) (*outsize), (int *) position, (MPI_Comm) (*comm));
    
#else  /* ! HAVE_FINT_IS_INT */
    int position_i;
    position_i = (int) *position;
    *ierr = MPI_Pack(inbuf, (int) (*incount), (MPI_Datatype) (*datatype), outbuf, (int) (*outsize), &position_i, (MPI_Comm) (*comm));
    *position = (MPI_Fint) position_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_pack_external_(char *datarep FORT_MIXED_LEN(datarep_len), void *inbuf, MPI_Fint *incount, MPI_Fint *datatype, void *outbuf, MPI_Aint *outsize, MPI_Aint *position, MPI_Fint *ierr FORT_END_LEN(datarep_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *datarep_i = MPIR_fort_dup_str(datarep, datarep_len);
    if (inbuf == MPIR_F_MPI_BOTTOM) {
        inbuf = MPI_BOTTOM;
    }
    
    if (outbuf == MPIR_F_MPI_BOTTOM) {
        outbuf = MPI_BOTTOM;
    }
    
    *ierr = MPI_Pack_external(datarep_i, inbuf, (int) (*incount), (MPI_Datatype) (*datatype), outbuf, *outsize, position);
    free(datarep_i);
}


FORT_DLL_SPEC void FORT_CALL mpi_pack_external_size_(char *datarep FORT_MIXED_LEN(datarep_len), MPI_Fint *incount, MPI_Fint *datatype, MPI_Aint *size, MPI_Fint *ierr FORT_END_LEN(datarep_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *datarep_i = MPIR_fort_dup_str(datarep, datarep_len);
    *ierr = MPI_Pack_external_size(datarep_i, (int) (*incount), (MPI_Datatype) (*datatype), size);
    free(datarep_i);
}


FORT_DLL_SPEC void FORT_CALL mpi_pack_size_(MPI_Fint *incount, MPI_Fint *datatype, MPI_Fint *comm, MPI_Fint *size, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Pack_size((int) (*incount), (MPI_Datatype) (*datatype), (MPI_Comm) (*comm), (int *) size);
    
#else  /* ! HAVE_FINT_IS_INT */
    int size_i;
    *ierr = MPI_Pack_size((int) (*incount), (MPI_Datatype) (*datatype), (MPI_Comm) (*comm), &size_i);
    *size = (MPI_Fint) size_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_status_set_elements_(MPI_Fint *status, MPI_Fint *datatype, MPI_Fint *count, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Status_set_elements((MPI_Status *) status, (MPI_Datatype) (*datatype), (int) (*count));
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    status_arg = (MPI_Status *) status_i;
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status_i[i] = (int) status[i];
    }
    *ierr = MPI_Status_set_elements(status_arg, (MPI_Datatype) (*datatype), (int) (*count));
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_status_set_elements_x_(MPI_Fint *status, MPI_Fint *datatype, MPI_Count *count, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Status_set_elements_x((MPI_Status *) status, (MPI_Datatype) (*datatype), *count);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    status_arg = (MPI_Status *) status_i;
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status_i[i] = (int) status[i];
    }
    *ierr = MPI_Status_set_elements_x(status_arg, (MPI_Datatype) (*datatype), *count);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_type_commit_(MPI_Fint *datatype, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Type_commit((MPI_Datatype *) datatype);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Datatype datatype_i;
    datatype_i = (MPI_Datatype) *datatype;
    *ierr = MPI_Type_commit(&datatype_i);
    *datatype = (MPI_Fint) datatype_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_type_contiguous_(MPI_Fint *count, MPI_Fint *oldtype, MPI_Fint *newtype, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Type_contiguous((int) (*count), (MPI_Datatype) (*oldtype), (MPI_Datatype *) newtype);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Datatype newtype_i;
    *ierr = MPI_Type_contiguous((int) (*count), (MPI_Datatype) (*oldtype), &newtype_i);
    *newtype = (MPI_Fint) newtype_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_type_create_darray_(MPI_Fint *size, MPI_Fint *rank, MPI_Fint *ndims, MPI_Fint *array_of_gsizes, MPI_Fint *array_of_distribs, MPI_Fint *array_of_dargs, MPI_Fint *array_of_psizes, MPI_Fint *order, MPI_Fint *oldtype, MPI_Fint *newtype, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Type_create_darray((int) (*size), (int) (*rank), (int) (*ndims), (int *) array_of_gsizes, (int *) array_of_distribs, (int *) array_of_dargs, (int *) array_of_psizes, (int) (*order), (MPI_Datatype) (*oldtype), (MPI_Datatype *) newtype);
    
#else  /* ! HAVE_FINT_IS_INT */
    int *array_of_gsizes_i;
    array_of_gsizes_i = malloc(sizeof(int) * (*ndims));
    for (int i = 0; i < (*ndims); i++) {
        array_of_gsizes_i[i] = (int) array_of_gsizes[i];
    }
    int *array_of_distribs_i;
    array_of_distribs_i = malloc(sizeof(int) * (*ndims));
    for (int i = 0; i < (*ndims); i++) {
        array_of_distribs_i[i] = (int) array_of_distribs[i];
    }
    int *array_of_dargs_i;
    array_of_dargs_i = malloc(sizeof(int) * (*ndims));
    for (int i = 0; i < (*ndims); i++) {
        array_of_dargs_i[i] = (int) array_of_dargs[i];
    }
    int *array_of_psizes_i;
    array_of_psizes_i = malloc(sizeof(int) * (*ndims));
    for (int i = 0; i < (*ndims); i++) {
        array_of_psizes_i[i] = (int) array_of_psizes[i];
    }
    MPI_Datatype newtype_i;
    *ierr = MPI_Type_create_darray((int) (*size), (int) (*rank), (int) (*ndims), array_of_gsizes_i, array_of_distribs_i, array_of_dargs_i, array_of_psizes_i, (int) (*order), (MPI_Datatype) (*oldtype), &newtype_i);
    free(array_of_gsizes_i);
    free(array_of_distribs_i);
    free(array_of_dargs_i);
    free(array_of_psizes_i);
    *newtype = (MPI_Fint) newtype_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_type_create_f90_complex_(MPI_Fint *p, MPI_Fint *r, MPI_Fint *newtype, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Type_create_f90_complex((int) (*p), (int) (*r), (MPI_Datatype *) newtype);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Datatype newtype_i;
    *ierr = MPI_Type_create_f90_complex((int) (*p), (int) (*r), &newtype_i);
    *newtype = (MPI_Fint) newtype_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_type_create_f90_integer_(MPI_Fint *r, MPI_Fint *newtype, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Type_create_f90_integer((int) (*r), (MPI_Datatype *) newtype);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Datatype newtype_i;
    *ierr = MPI_Type_create_f90_integer((int) (*r), &newtype_i);
    *newtype = (MPI_Fint) newtype_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_type_create_f90_real_(MPI_Fint *p, MPI_Fint *r, MPI_Fint *newtype, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Type_create_f90_real((int) (*p), (int) (*r), (MPI_Datatype *) newtype);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Datatype newtype_i;
    *ierr = MPI_Type_create_f90_real((int) (*p), (int) (*r), &newtype_i);
    *newtype = (MPI_Fint) newtype_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_type_create_hindexed_(MPI_Fint *count, MPI_Fint *array_of_blocklengths, MPI_Aint *array_of_displacements, MPI_Fint *oldtype, MPI_Fint *newtype, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Type_create_hindexed((int) (*count), (int *) array_of_blocklengths, array_of_displacements, (MPI_Datatype) (*oldtype), (MPI_Datatype *) newtype);
    
#else  /* ! HAVE_FINT_IS_INT */
    int *array_of_blocklengths_i;
    array_of_blocklengths_i = malloc(sizeof(int) * (*count));
    for (int i = 0; i < (*count); i++) {
        array_of_blocklengths_i[i] = (int) array_of_blocklengths[i];
    }
    MPI_Datatype newtype_i;
    *ierr = MPI_Type_create_hindexed((int) (*count), array_of_blocklengths_i, array_of_displacements, (MPI_Datatype) (*oldtype), &newtype_i);
    free(array_of_blocklengths_i);
    *newtype = (MPI_Fint) newtype_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_type_create_hindexed_block_(MPI_Fint *count, MPI_Fint *blocklength, MPI_Aint *array_of_displacements, MPI_Fint *oldtype, MPI_Fint *newtype, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Type_create_hindexed_block((int) (*count), (int) (*blocklength), array_of_displacements, (MPI_Datatype) (*oldtype), (MPI_Datatype *) newtype);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Datatype newtype_i;
    *ierr = MPI_Type_create_hindexed_block((int) (*count), (int) (*blocklength), array_of_displacements, (MPI_Datatype) (*oldtype), &newtype_i);
    *newtype = (MPI_Fint) newtype_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_type_create_hvector_(MPI_Fint *count, MPI_Fint *blocklength, MPI_Aint *stride, MPI_Fint *oldtype, MPI_Fint *newtype, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Type_create_hvector((int) (*count), (int) (*blocklength), *stride, (MPI_Datatype) (*oldtype), (MPI_Datatype *) newtype);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Datatype newtype_i;
    *ierr = MPI_Type_create_hvector((int) (*count), (int) (*blocklength), *stride, (MPI_Datatype) (*oldtype), &newtype_i);
    *newtype = (MPI_Fint) newtype_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_type_create_indexed_block_(MPI_Fint *count, MPI_Fint *blocklength, MPI_Fint *array_of_displacements, MPI_Fint *oldtype, MPI_Fint *newtype, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Type_create_indexed_block((int) (*count), (int) (*blocklength), (int *) array_of_displacements, (MPI_Datatype) (*oldtype), (MPI_Datatype *) newtype);
    
#else  /* ! HAVE_FINT_IS_INT */
    int *array_of_displacements_i;
    array_of_displacements_i = malloc(sizeof(int) * (*count));
    for (int i = 0; i < (*count); i++) {
        array_of_displacements_i[i] = (int) array_of_displacements[i];
    }
    MPI_Datatype newtype_i;
    *ierr = MPI_Type_create_indexed_block((int) (*count), (int) (*blocklength), array_of_displacements_i, (MPI_Datatype) (*oldtype), &newtype_i);
    free(array_of_displacements_i);
    *newtype = (MPI_Fint) newtype_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_type_create_resized_(MPI_Fint *oldtype, MPI_Aint *lb, MPI_Aint *extent, MPI_Fint *newtype, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Type_create_resized((MPI_Datatype) (*oldtype), *lb, *extent, (MPI_Datatype *) newtype);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Datatype newtype_i;
    *ierr = MPI_Type_create_resized((MPI_Datatype) (*oldtype), *lb, *extent, &newtype_i);
    *newtype = (MPI_Fint) newtype_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_type_create_struct_(MPI_Fint *count, MPI_Fint *array_of_blocklengths, MPI_Aint *array_of_displacements, MPI_Fint *array_of_types, MPI_Fint *newtype, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Type_create_struct((int) (*count), (int *) array_of_blocklengths, array_of_displacements, (int *) array_of_types, (MPI_Datatype *) newtype);
    
#else  /* ! HAVE_FINT_IS_INT */
    int *array_of_blocklengths_i;
    array_of_blocklengths_i = malloc(sizeof(int) * (*count));
    for (int i = 0; i < (*count); i++) {
        array_of_blocklengths_i[i] = (int) array_of_blocklengths[i];
    }
    MPI_Datatype *array_of_types_i;
    array_of_types_i = malloc(sizeof(MPI_Datatype) * (*count));
    for (int i = 0; i < (*count); i++) {
        array_of_types_i[i] = (MPI_Datatype) array_of_types[i];
    }
    MPI_Datatype newtype_i;
    *ierr = MPI_Type_create_struct((int) (*count), array_of_blocklengths_i, array_of_displacements, array_of_types_i, &newtype_i);
    free(array_of_blocklengths_i);
    free(array_of_types_i);
    *newtype = (MPI_Fint) newtype_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_type_create_subarray_(MPI_Fint *ndims, MPI_Fint *array_of_sizes, MPI_Fint *array_of_subsizes, MPI_Fint *array_of_starts, MPI_Fint *order, MPI_Fint *oldtype, MPI_Fint *newtype, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Type_create_subarray((int) (*ndims), (int *) array_of_sizes, (int *) array_of_subsizes, (int *) array_of_starts, (int) (*order), (MPI_Datatype) (*oldtype), (MPI_Datatype *) newtype);
    
#else  /* ! HAVE_FINT_IS_INT */
    int *array_of_sizes_i;
    array_of_sizes_i = malloc(sizeof(int) * (*ndims));
    for (int i = 0; i < (*ndims); i++) {
        array_of_sizes_i[i] = (int) array_of_sizes[i];
    }
    int *array_of_subsizes_i;
    array_of_subsizes_i = malloc(sizeof(int) * (*ndims));
    for (int i = 0; i < (*ndims); i++) {
        array_of_subsizes_i[i] = (int) array_of_subsizes[i];
    }
    int *array_of_starts_i;
    array_of_starts_i = malloc(sizeof(int) * (*ndims));
    for (int i = 0; i < (*ndims); i++) {
        array_of_starts_i[i] = (int) array_of_starts[i];
    }
    MPI_Datatype newtype_i;
    *ierr = MPI_Type_create_subarray((int) (*ndims), array_of_sizes_i, array_of_subsizes_i, array_of_starts_i, (int) (*order), (MPI_Datatype) (*oldtype), &newtype_i);
    free(array_of_sizes_i);
    free(array_of_subsizes_i);
    free(array_of_starts_i);
    *newtype = (MPI_Fint) newtype_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_type_dup_(MPI_Fint *oldtype, MPI_Fint *newtype, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Type_dup((MPI_Datatype) (*oldtype), (MPI_Datatype *) newtype);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Datatype newtype_i;
    *ierr = MPI_Type_dup((MPI_Datatype) (*oldtype), &newtype_i);
    *newtype = (MPI_Fint) newtype_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_type_free_(MPI_Fint *datatype, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Type_free((MPI_Datatype *) datatype);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Datatype datatype_i;
    datatype_i = (MPI_Datatype) *datatype;
    *ierr = MPI_Type_free(&datatype_i);
    *datatype = (MPI_Fint) datatype_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_type_get_contents_(MPI_Fint *datatype, MPI_Fint *max_integers, MPI_Fint *max_addresses, MPI_Fint *max_datatypes, MPI_Fint *array_of_integers, MPI_Aint *array_of_addresses, MPI_Fint *array_of_datatypes, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Type_get_contents((MPI_Datatype) (*datatype), (int) (*max_integers), (int) (*max_addresses), (int) (*max_datatypes), (int *) array_of_integers, array_of_addresses, (int *) array_of_datatypes);
    
#else  /* ! HAVE_FINT_IS_INT */
    int *array_of_integers_i;
    array_of_integers_i = malloc(sizeof(int) * (*max_integers));
    MPI_Datatype *array_of_datatypes_i;
    array_of_datatypes_i = malloc(sizeof(MPI_Datatype) * (*max_datatypes));
    *ierr = MPI_Type_get_contents((MPI_Datatype) (*datatype), (int) (*max_integers), (int) (*max_addresses), (int) (*max_datatypes), array_of_integers_i, array_of_addresses, array_of_datatypes_i);
    for (int i = 0; i < (*max_integers); i++) {
        array_of_integers[i] = (MPI_Fint) array_of_integers_i[i];
    }
    free(array_of_integers_i);
    for (int i = 0; i < (*max_datatypes); i++) {
        array_of_datatypes[i] = (MPI_Fint) array_of_datatypes_i[i];
    }
    free(array_of_datatypes_i);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_type_get_envelope_(MPI_Fint *datatype, MPI_Fint *num_integers, MPI_Fint *num_addresses, MPI_Fint *num_datatypes, MPI_Fint *combiner, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Type_get_envelope((MPI_Datatype) (*datatype), (int *) num_integers, (int *) num_addresses, (int *) num_datatypes, (int *) combiner);
    
#else  /* ! HAVE_FINT_IS_INT */
    int num_integers_i;
    int num_addresses_i;
    int num_datatypes_i;
    int combiner_i;
    *ierr = MPI_Type_get_envelope((MPI_Datatype) (*datatype), &num_integers_i, &num_addresses_i, &num_datatypes_i, &combiner_i);
    *num_integers = (MPI_Fint) num_integers_i;
    *num_addresses = (MPI_Fint) num_addresses_i;
    *num_datatypes = (MPI_Fint) num_datatypes_i;
    *combiner = (MPI_Fint) combiner_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_type_get_extent_(MPI_Fint *datatype, MPI_Aint *lb, MPI_Aint *extent, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Type_get_extent((MPI_Datatype) (*datatype), lb, extent);
}


FORT_DLL_SPEC void FORT_CALL mpi_type_get_extent_x_(MPI_Fint *datatype, MPI_Count *lb, MPI_Count *extent, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Type_get_extent_x((MPI_Datatype) (*datatype), lb, extent);
}


FORT_DLL_SPEC void FORT_CALL mpi_type_get_name_(MPI_Fint *datatype, char *type_name FORT_MIXED_LEN(type_name_len), MPI_Fint *resultlen, MPI_Fint *ierr FORT_END_LEN(type_name_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *type_name_i = malloc(type_name_len + 1);
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Type_get_name((MPI_Datatype) (*datatype), type_name_i, (int *) resultlen);
    
#else  /* ! HAVE_FINT_IS_INT */
    int resultlen_i;
    *ierr = MPI_Type_get_name((MPI_Datatype) (*datatype), type_name_i, &resultlen_i);
    *resultlen = (MPI_Fint) resultlen_i;
#endif
    if (*ierr == MPI_SUCCESS) {
        MPIR_fort_copy_str_from_c(type_name, type_name_len, type_name_i);
    }
    free(type_name_i);
}


FORT_DLL_SPEC void FORT_CALL mpi_type_get_true_extent_(MPI_Fint *datatype, MPI_Aint *true_lb, MPI_Aint *true_extent, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Type_get_true_extent((MPI_Datatype) (*datatype), true_lb, true_extent);
}


FORT_DLL_SPEC void FORT_CALL mpi_type_get_true_extent_x_(MPI_Fint *datatype, MPI_Count *true_lb, MPI_Count *true_extent, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Type_get_true_extent_x((MPI_Datatype) (*datatype), true_lb, true_extent);
}


FORT_DLL_SPEC void FORT_CALL mpi_type_get_value_index_(MPI_Fint *value_type, MPI_Fint *index_type, MPI_Fint *pair_type, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Type_get_value_index((MPI_Datatype) (*value_type), (MPI_Datatype) (*index_type), (MPI_Datatype *) pair_type);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Datatype pair_type_i;
    *ierr = MPI_Type_get_value_index((MPI_Datatype) (*value_type), (MPI_Datatype) (*index_type), &pair_type_i);
    *pair_type = (MPI_Fint) pair_type_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_type_indexed_(MPI_Fint *count, MPI_Fint *array_of_blocklengths, MPI_Fint *array_of_displacements, MPI_Fint *oldtype, MPI_Fint *newtype, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Type_indexed((int) (*count), (int *) array_of_blocklengths, (int *) array_of_displacements, (MPI_Datatype) (*oldtype), (MPI_Datatype *) newtype);
    
#else  /* ! HAVE_FINT_IS_INT */
    int *array_of_blocklengths_i;
    array_of_blocklengths_i = malloc(sizeof(int) * (*count));
    for (int i = 0; i < (*count); i++) {
        array_of_blocklengths_i[i] = (int) array_of_blocklengths[i];
    }
    int *array_of_displacements_i;
    array_of_displacements_i = malloc(sizeof(int) * (*count));
    for (int i = 0; i < (*count); i++) {
        array_of_displacements_i[i] = (int) array_of_displacements[i];
    }
    MPI_Datatype newtype_i;
    *ierr = MPI_Type_indexed((int) (*count), array_of_blocklengths_i, array_of_displacements_i, (MPI_Datatype) (*oldtype), &newtype_i);
    free(array_of_blocklengths_i);
    free(array_of_displacements_i);
    *newtype = (MPI_Fint) newtype_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_type_match_size_(MPI_Fint *typeclass, MPI_Fint *size, MPI_Fint *datatype, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Type_match_size((int) (*typeclass), (int) (*size), (MPI_Datatype *) datatype);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Datatype datatype_i;
    *ierr = MPI_Type_match_size((int) (*typeclass), (int) (*size), &datatype_i);
    *datatype = (MPI_Fint) datatype_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_type_set_name_(MPI_Fint *datatype, char *type_name FORT_MIXED_LEN(type_name_len), MPI_Fint *ierr FORT_END_LEN(type_name_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *type_name_i = MPIR_fort_dup_str(type_name, type_name_len);
    *ierr = MPI_Type_set_name((MPI_Datatype) (*datatype), type_name_i);
    free(type_name_i);
}


FORT_DLL_SPEC void FORT_CALL mpi_type_size_(MPI_Fint *datatype, MPI_Fint *size, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Type_size((MPI_Datatype) (*datatype), (int *) size);
    
#else  /* ! HAVE_FINT_IS_INT */
    int size_i;
    *ierr = MPI_Type_size((MPI_Datatype) (*datatype), &size_i);
    *size = (MPI_Fint) size_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_type_size_x_(MPI_Fint *datatype, MPI_Count *size, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Type_size_x((MPI_Datatype) (*datatype), size);
}


FORT_DLL_SPEC void FORT_CALL mpi_type_vector_(MPI_Fint *count, MPI_Fint *blocklength, MPI_Fint *stride, MPI_Fint *oldtype, MPI_Fint *newtype, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Type_vector((int) (*count), (int) (*blocklength), (int) (*stride), (MPI_Datatype) (*oldtype), (MPI_Datatype *) newtype);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Datatype newtype_i;
    *ierr = MPI_Type_vector((int) (*count), (int) (*blocklength), (int) (*stride), (MPI_Datatype) (*oldtype), &newtype_i);
    *newtype = (MPI_Fint) newtype_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_unpack_(void *inbuf, MPI_Fint *insize, MPI_Fint *position, void *outbuf, MPI_Fint *outcount, MPI_Fint *datatype, MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (inbuf == MPIR_F_MPI_BOTTOM) {
        inbuf = MPI_BOTTOM;
    }
    
    if (outbuf == MPIR_F_MPI_BOTTOM) {
        outbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Unpack(inbuf, (int) (*insize), (int *) position, outbuf, (int) (*outcount), (MPI_Datatype) (*datatype), (MPI_Comm) (*comm));
    
#else  /* ! HAVE_FINT_IS_INT */
    int position_i;
    position_i = (int) *position;
    *ierr = MPI_Unpack(inbuf, (int) (*insize), &position_i, outbuf, (int) (*outcount), (MPI_Datatype) (*datatype), (MPI_Comm) (*comm));
    *position = (MPI_Fint) position_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_unpack_external_(char *datarep FORT_MIXED_LEN(datarep_len), void *inbuf, MPI_Aint *insize, MPI_Aint *position, void *outbuf, MPI_Fint *outcount, MPI_Fint *datatype, MPI_Fint *ierr FORT_END_LEN(datarep_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *datarep_i = MPIR_fort_dup_str(datarep, datarep_len);
    if (inbuf == MPIR_F_MPI_BOTTOM) {
        inbuf = MPI_BOTTOM;
    }
    
    if (outbuf == MPIR_F_MPI_BOTTOM) {
        outbuf = MPI_BOTTOM;
    }
    
    *ierr = MPI_Unpack_external(datarep_i, inbuf, *insize, position, outbuf, (int) (*outcount), (MPI_Datatype) (*datatype));
    free(datarep_i);
}


FORT_DLL_SPEC void FORT_CALL mpi_address_(void *location, MPI_Fint *address, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (location == MPIR_F_MPI_BOTTOM) {
        location = MPI_BOTTOM;
    }
    
    MPI_Aint address_i;
    *ierr = MPI_Address(location, &address_i);
    *address = (MPI_Fint) address_i;
    if ((MPI_Aint) (*address) != address_i) {
        /* Unfortunately, there isn't an easy way to invoke error handler */
        *ierr = MPI_ERR_OTHER;
    }
}


FORT_DLL_SPEC void FORT_CALL mpi_type_extent_(MPI_Fint *datatype, MPI_Fint *extent, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    MPI_Aint extent_i;
    *ierr = MPI_Type_extent((MPI_Datatype) (*datatype), &extent_i);
    *extent = (MPI_Fint) extent_i;
}


FORT_DLL_SPEC void FORT_CALL mpi_type_lb_(MPI_Fint *datatype, MPI_Fint *displacement, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    MPI_Aint displacement_i;
    *ierr = MPI_Type_lb((MPI_Datatype) (*datatype), &displacement_i);
    *displacement = (MPI_Fint) displacement_i;
}


FORT_DLL_SPEC void FORT_CALL mpi_type_ub_(MPI_Fint *datatype, MPI_Fint *displacement, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    MPI_Aint displacement_i;
    *ierr = MPI_Type_ub((MPI_Datatype) (*datatype), &displacement_i);
    *displacement = (MPI_Fint) displacement_i;
}


FORT_DLL_SPEC void FORT_CALL mpi_type_hindexed_(MPI_Fint *count, MPI_Fint *array_of_blocklengths, MPI_Fint *array_of_displacements, MPI_Fint *oldtype, MPI_Fint *newtype, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    MPI_Aint *array_of_displacements_i;
#ifdef HAVE_AINT_DIFFERENT_THAN_FINT
    array_of_displacements_i = malloc((*count) * sizeof(MPI_Aint));
    for (int i = 0; i < (*count); i++) {
        array_of_displacements_i[i] = (MPI_Aint) array_of_displacements[i];
    }
#else
    array_of_displacements_i = array_of_displacements;
#endif
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Type_hindexed((int) (*count), (int *) array_of_blocklengths, array_of_displacements_i, (MPI_Datatype) (*oldtype), (MPI_Datatype *) newtype);
    
#else  /* ! HAVE_FINT_IS_INT */
    int *array_of_blocklengths_i;
    array_of_blocklengths_i = malloc(sizeof(int) * (*count));
    for (int i = 0; i < (*count); i++) {
        array_of_blocklengths_i[i] = (int) array_of_blocklengths[i];
    }
    MPI_Datatype newtype_i;
    *ierr = MPI_Type_hindexed((int) (*count), array_of_blocklengths_i, array_of_displacements_i, (MPI_Datatype) (*oldtype), &newtype_i);
    free(array_of_blocklengths_i);
    *newtype = (MPI_Fint) newtype_i;
#endif
#ifdef HAVE_AINT_DIFFERENT_THAN_FINT
    free(array_of_displacements_i);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_type_hvector_(MPI_Fint *count, MPI_Fint *blocklength, MPI_Fint *stride, MPI_Fint *oldtype, MPI_Fint *newtype, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Type_hvector((int) (*count), (int) (*blocklength), (MPI_Aint) (*stride), (MPI_Datatype) (*oldtype), (MPI_Datatype *) newtype);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Datatype newtype_i;
    *ierr = MPI_Type_hvector((int) (*count), (int) (*blocklength), (MPI_Aint) (*stride), (MPI_Datatype) (*oldtype), &newtype_i);
    *newtype = (MPI_Fint) newtype_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_type_struct_(MPI_Fint *count, MPI_Fint *array_of_blocklengths, MPI_Fint *array_of_displacements, MPI_Fint *array_of_types, MPI_Fint *newtype, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    MPI_Aint *array_of_displacements_i;
#ifdef HAVE_AINT_DIFFERENT_THAN_FINT
    array_of_displacements_i = malloc((*count) * sizeof(MPI_Aint));
    for (int i = 0; i < (*count); i++) {
        array_of_displacements_i[i] = (MPI_Aint) array_of_displacements[i];
    }
#else
    array_of_displacements_i = array_of_displacements;
#endif
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Type_struct((int) (*count), (int *) array_of_blocklengths, array_of_displacements_i, (int *) array_of_types, (MPI_Datatype *) newtype);
    
#else  /* ! HAVE_FINT_IS_INT */
    int *array_of_blocklengths_i;
    array_of_blocklengths_i = malloc(sizeof(int) * (*count));
    for (int i = 0; i < (*count); i++) {
        array_of_blocklengths_i[i] = (int) array_of_blocklengths[i];
    }
    MPI_Datatype *array_of_types_i;
    array_of_types_i = malloc(sizeof(MPI_Datatype) * (*count));
    for (int i = 0; i < (*count); i++) {
        array_of_types_i[i] = (MPI_Datatype) array_of_types[i];
    }
    MPI_Datatype newtype_i;
    *ierr = MPI_Type_struct((int) (*count), array_of_blocklengths_i, array_of_displacements_i, array_of_types_i, &newtype_i);
    free(array_of_blocklengths_i);
    free(array_of_types_i);
    *newtype = (MPI_Fint) newtype_i;
#endif
#ifdef HAVE_AINT_DIFFERENT_THAN_FINT
    free(array_of_displacements_i);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_add_error_class_(MPI_Fint *errorclass, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Add_error_class((int *) errorclass);
    
#else  /* ! HAVE_FINT_IS_INT */
    int errorclass_i;
    *ierr = MPI_Add_error_class(&errorclass_i);
    *errorclass = (MPI_Fint) errorclass_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_add_error_code_(MPI_Fint *errorclass, MPI_Fint *errorcode, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Add_error_code((int) (*errorclass), (int *) errorcode);
    
#else  /* ! HAVE_FINT_IS_INT */
    int errorcode_i;
    *ierr = MPI_Add_error_code((int) (*errorclass), &errorcode_i);
    *errorcode = (MPI_Fint) errorcode_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_add_error_string_(MPI_Fint *errorcode, char *string FORT_MIXED_LEN(string_len), MPI_Fint *ierr FORT_END_LEN(string_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *string_i = MPIR_fort_dup_str(string, string_len);
    *ierr = MPI_Add_error_string((int) (*errorcode), string_i);
    free(string_i);
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_call_errhandler_(MPI_Fint *comm, MPI_Fint *errorcode, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Comm_call_errhandler((MPI_Comm) (*comm), (int) (*errorcode));
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_create_errhandler_(F77_ErrFunction comm_errhandler_fn, MPI_Fint *errhandler, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPII_errhan_create(comm_errhandler_fn, errhandler, F77_COMM);
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_get_errhandler_(MPI_Fint *comm, MPI_Fint *errhandler, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Comm_get_errhandler((MPI_Comm) (*comm), (MPI_Errhandler *) errhandler);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Errhandler errhandler_i;
    *ierr = MPI_Comm_get_errhandler((MPI_Comm) (*comm), &errhandler_i);
    *errhandler = (MPI_Fint) errhandler_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_set_errhandler_(MPI_Fint *comm, MPI_Fint *errhandler, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Comm_set_errhandler((MPI_Comm) (*comm), (MPI_Errhandler) (*errhandler));
}


FORT_DLL_SPEC void FORT_CALL mpi_errhandler_free_(MPI_Fint *errhandler, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Errhandler_free((MPI_Errhandler *) errhandler);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Errhandler errhandler_i;
    errhandler_i = (MPI_Errhandler) *errhandler;
    *ierr = MPI_Errhandler_free(&errhandler_i);
    *errhandler = (MPI_Fint) errhandler_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_error_class_(MPI_Fint *errorcode, MPI_Fint *errorclass, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Error_class((int) (*errorcode), (int *) errorclass);
    
#else  /* ! HAVE_FINT_IS_INT */
    int errorclass_i;
    *ierr = MPI_Error_class((int) (*errorcode), &errorclass_i);
    *errorclass = (MPI_Fint) errorclass_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_error_string_(MPI_Fint *errorcode, char *string FORT_MIXED_LEN(string_len), MPI_Fint *resultlen, MPI_Fint *ierr FORT_END_LEN(string_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *string_i = malloc(string_len + 1);
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Error_string((int) (*errorcode), string_i, (int *) resultlen);
    
#else  /* ! HAVE_FINT_IS_INT */
    int resultlen_i;
    *ierr = MPI_Error_string((int) (*errorcode), string_i, &resultlen_i);
    *resultlen = (MPI_Fint) resultlen_i;
#endif
    if (*ierr == MPI_SUCCESS) {
        MPIR_fort_copy_str_from_c(string, string_len, string_i);
    }
    free(string_i);
}


FORT_DLL_SPEC void FORT_CALL mpi_file_call_errhandler_(MPI_Fint *fh, MPI_Fint *errorcode, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_File_call_errhandler(MPI_File_f2c(*fh), (int) (*errorcode));
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_create_errhandler_(F77_ErrFunction file_errhandler_fn, MPI_Fint *errhandler, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPII_errhan_create(file_errhandler_fn, errhandler, F77_FILE);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_get_errhandler_(MPI_Fint *file, MPI_Fint *errhandler, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_File_get_errhandler(MPI_File_f2c(*file), (MPI_Errhandler *) errhandler);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Errhandler errhandler_i;
    *ierr = MPI_File_get_errhandler(MPI_File_f2c(*file), &errhandler_i);
    *errhandler = (MPI_Fint) errhandler_i;
#endif
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_set_errhandler_(MPI_Fint *file, MPI_Fint *errhandler, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_File_set_errhandler(MPI_File_f2c(*file), (MPI_Errhandler) (*errhandler));
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_remove_error_class_(MPI_Fint *errorclass, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Remove_error_class((int) (*errorclass));
}


FORT_DLL_SPEC void FORT_CALL mpi_remove_error_code_(MPI_Fint *errorcode, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Remove_error_code((int) (*errorcode));
}


FORT_DLL_SPEC void FORT_CALL mpi_remove_error_string_(MPI_Fint *errorcode, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Remove_error_string((int) (*errorcode));
}


FORT_DLL_SPEC void FORT_CALL mpi_session_call_errhandler_(MPI_Fint *session, MPI_Fint *errorcode, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Session_call_errhandler((MPI_Session) (*session), (int) (*errorcode));
}


FORT_DLL_SPEC void FORT_CALL mpi_session_create_errhandler_(F77_ErrFunction session_errhandler_fn, MPI_Fint *errhandler, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPII_errhan_create(session_errhandler_fn, errhandler, F77_SESSION);
}


FORT_DLL_SPEC void FORT_CALL mpi_session_get_errhandler_(MPI_Fint *session, MPI_Fint *errhandler, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Session_get_errhandler((MPI_Session) (*session), (MPI_Errhandler *) errhandler);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Errhandler errhandler_i;
    *ierr = MPI_Session_get_errhandler((MPI_Session) (*session), &errhandler_i);
    *errhandler = (MPI_Fint) errhandler_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_session_set_errhandler_(MPI_Fint *session, MPI_Fint *errhandler, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Session_set_errhandler((MPI_Session) (*session), (MPI_Errhandler) (*errhandler));
}


FORT_DLL_SPEC void FORT_CALL mpi_win_call_errhandler_(MPI_Fint *win, MPI_Fint *errorcode, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Win_call_errhandler((MPI_Win) (*win), (int) (*errorcode));
}


FORT_DLL_SPEC void FORT_CALL mpi_win_create_errhandler_(F77_ErrFunction win_errhandler_fn, MPI_Fint *errhandler, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPII_errhan_create(win_errhandler_fn, errhandler, F77_WIN);
}


FORT_DLL_SPEC void FORT_CALL mpi_win_get_errhandler_(MPI_Fint *win, MPI_Fint *errhandler, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Win_get_errhandler((MPI_Win) (*win), (MPI_Errhandler *) errhandler);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Errhandler errhandler_i;
    *ierr = MPI_Win_get_errhandler((MPI_Win) (*win), &errhandler_i);
    *errhandler = (MPI_Fint) errhandler_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_win_set_errhandler_(MPI_Fint *win, MPI_Fint *errhandler, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Win_set_errhandler((MPI_Win) (*win), (MPI_Errhandler) (*errhandler));
}


FORT_DLL_SPEC void FORT_CALL mpi_errhandler_create_(F77_ErrFunction comm_errhandler_fn, MPI_Fint *errhandler, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPII_errhan_create(comm_errhandler_fn, errhandler, F77_COMM);
}


FORT_DLL_SPEC void FORT_CALL mpi_errhandler_get_(MPI_Fint *comm, MPI_Fint *errhandler, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Errhandler_get((MPI_Comm) (*comm), (MPI_Errhandler *) errhandler);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Errhandler errhandler_i;
    *ierr = MPI_Errhandler_get((MPI_Comm) (*comm), &errhandler_i);
    *errhandler = (MPI_Fint) errhandler_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_errhandler_set_(MPI_Fint *comm, MPI_Fint *errhandler, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Errhandler_set((MPI_Comm) (*comm), (MPI_Errhandler) (*errhandler));
}


FORT_DLL_SPEC void FORT_CALL mpi_group_compare_(MPI_Fint *group1, MPI_Fint *group2, MPI_Fint *result, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Group_compare((MPI_Group) (*group1), (MPI_Group) (*group2), (int *) result);
    
#else  /* ! HAVE_FINT_IS_INT */
    int result_i;
    *ierr = MPI_Group_compare((MPI_Group) (*group1), (MPI_Group) (*group2), &result_i);
    *result = (MPI_Fint) result_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_group_difference_(MPI_Fint *group1, MPI_Fint *group2, MPI_Fint *newgroup, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Group_difference((MPI_Group) (*group1), (MPI_Group) (*group2), (MPI_Group *) newgroup);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Group newgroup_i;
    *ierr = MPI_Group_difference((MPI_Group) (*group1), (MPI_Group) (*group2), &newgroup_i);
    *newgroup = (MPI_Fint) newgroup_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_group_excl_(MPI_Fint *group, MPI_Fint *n, MPI_Fint *ranks, MPI_Fint *newgroup, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Group_excl((MPI_Group) (*group), (int) (*n), (int *) ranks, (MPI_Group *) newgroup);
    
#else  /* ! HAVE_FINT_IS_INT */
    int *ranks_i;
    ranks_i = malloc(sizeof(int) * (*n));
    for (int i = 0; i < (*n); i++) {
        ranks_i[i] = (int) ranks[i];
    }
    MPI_Group newgroup_i;
    *ierr = MPI_Group_excl((MPI_Group) (*group), (int) (*n), ranks_i, &newgroup_i);
    free(ranks_i);
    *newgroup = (MPI_Fint) newgroup_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_group_free_(MPI_Fint *group, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Group_free((MPI_Group *) group);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Group group_i;
    group_i = (MPI_Group) *group;
    *ierr = MPI_Group_free(&group_i);
    *group = (MPI_Fint) group_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_group_incl_(MPI_Fint *group, MPI_Fint *n, MPI_Fint *ranks, MPI_Fint *newgroup, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Group_incl((MPI_Group) (*group), (int) (*n), (int *) ranks, (MPI_Group *) newgroup);
    
#else  /* ! HAVE_FINT_IS_INT */
    int *ranks_i;
    ranks_i = malloc(sizeof(int) * (*n));
    for (int i = 0; i < (*n); i++) {
        ranks_i[i] = (int) ranks[i];
    }
    MPI_Group newgroup_i;
    *ierr = MPI_Group_incl((MPI_Group) (*group), (int) (*n), ranks_i, &newgroup_i);
    free(ranks_i);
    *newgroup = (MPI_Fint) newgroup_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_group_intersection_(MPI_Fint *group1, MPI_Fint *group2, MPI_Fint *newgroup, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Group_intersection((MPI_Group) (*group1), (MPI_Group) (*group2), (MPI_Group *) newgroup);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Group newgroup_i;
    *ierr = MPI_Group_intersection((MPI_Group) (*group1), (MPI_Group) (*group2), &newgroup_i);
    *newgroup = (MPI_Fint) newgroup_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_group_range_excl_(MPI_Fint *group, MPI_Fint *n, MPI_Fint *ranges, MPI_Fint *newgroup, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Group_range_excl((MPI_Group) (*group), (int) (*n), (int (*)[3]) ranges, (MPI_Group *) newgroup);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Group newgroup_i;
    *ierr = MPI_Group_range_excl((MPI_Group) (*group), (int) (*n), (int (*)[3]) ranges, &newgroup_i);
    *newgroup = (MPI_Fint) newgroup_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_group_range_incl_(MPI_Fint *group, MPI_Fint *n, MPI_Fint *ranges, MPI_Fint *newgroup, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Group_range_incl((MPI_Group) (*group), (int) (*n), (int (*)[3]) ranges, (MPI_Group *) newgroup);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Group newgroup_i;
    *ierr = MPI_Group_range_incl((MPI_Group) (*group), (int) (*n), (int (*)[3]) ranges, &newgroup_i);
    *newgroup = (MPI_Fint) newgroup_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_group_rank_(MPI_Fint *group, MPI_Fint *rank, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Group_rank((MPI_Group) (*group), (int *) rank);
    
#else  /* ! HAVE_FINT_IS_INT */
    int rank_i;
    *ierr = MPI_Group_rank((MPI_Group) (*group), &rank_i);
    *rank = (MPI_Fint) rank_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_group_size_(MPI_Fint *group, MPI_Fint *size, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Group_size((MPI_Group) (*group), (int *) size);
    
#else  /* ! HAVE_FINT_IS_INT */
    int size_i;
    *ierr = MPI_Group_size((MPI_Group) (*group), &size_i);
    *size = (MPI_Fint) size_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_group_translate_ranks_(MPI_Fint *group1, MPI_Fint *n, MPI_Fint *ranks1, MPI_Fint *group2, MPI_Fint *ranks2, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Group_translate_ranks((MPI_Group) (*group1), (int) (*n), (int *) ranks1, (MPI_Group) (*group2), (int *) ranks2);
    
#else  /* ! HAVE_FINT_IS_INT */
    int *ranks1_i;
    ranks1_i = malloc(sizeof(int) * (*n));
    for (int i = 0; i < (*n); i++) {
        ranks1_i[i] = (int) ranks1[i];
    }
    int *ranks2_i;
    ranks2_i = malloc(sizeof(int) * (*n));
    *ierr = MPI_Group_translate_ranks((MPI_Group) (*group1), (int) (*n), ranks1_i, (MPI_Group) (*group2), ranks2_i);
    free(ranks1_i);
    for (int i = 0; i < (*n); i++) {
        ranks2[i] = (MPI_Fint) ranks2_i[i];
    }
    free(ranks2_i);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_group_union_(MPI_Fint *group1, MPI_Fint *group2, MPI_Fint *newgroup, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Group_union((MPI_Group) (*group1), (MPI_Group) (*group2), (MPI_Group *) newgroup);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Group newgroup_i;
    *ierr = MPI_Group_union((MPI_Group) (*group1), (MPI_Group) (*group2), &newgroup_i);
    *newgroup = (MPI_Fint) newgroup_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_info_create_(MPI_Fint *info, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Info_create((MPI_Info *) info);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Info info_i;
    *ierr = MPI_Info_create(&info_i);
    *info = (MPI_Fint) info_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_info_create_env_(MPI_Fint *info, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Info_create_env(0, 0, (MPI_Info *) info);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Info info_i;
    *ierr = MPI_Info_create_env(0, 0, &info_i);
    *info = (MPI_Fint) info_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_info_delete_(MPI_Fint *info, char *key FORT_MIXED_LEN(key_len), MPI_Fint *ierr FORT_END_LEN(key_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *key_i = MPIR_fort_dup_str(key, key_len);
    *ierr = MPI_Info_delete((MPI_Info) (*info), key_i);
    free(key_i);
}


FORT_DLL_SPEC void FORT_CALL mpi_info_dup_(MPI_Fint *info, MPI_Fint *newinfo, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Info_dup((MPI_Info) (*info), (MPI_Info *) newinfo);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Info newinfo_i;
    *ierr = MPI_Info_dup((MPI_Info) (*info), &newinfo_i);
    *newinfo = (MPI_Fint) newinfo_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_info_free_(MPI_Fint *info, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Info_free((MPI_Info *) info);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Info info_i;
    info_i = (MPI_Info) *info;
    *ierr = MPI_Info_free(&info_i);
    *info = (MPI_Fint) info_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_info_get_(MPI_Fint *info, char *key FORT_MIXED_LEN(key_len), MPI_Fint *valuelen, char *value FORT_MIXED_LEN(value_len), MPI_Fint *flag, MPI_Fint *ierr FORT_END_LEN(key_len) FORT_END_LEN(value_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *key_i = MPIR_fort_dup_str(key, key_len);
    char *value_i = malloc(value_len + 1);
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Info_get((MPI_Info) (*info), key_i, (int) (*valuelen), value_i, (int *) flag);
    
#else  /* ! HAVE_FINT_IS_INT */
    int flag_i;
    *ierr = MPI_Info_get((MPI_Info) (*info), key_i, (int) (*valuelen), value_i, &flag_i);
    *flag = (MPI_Fint) flag_i;
#endif
    free(key_i);
    if (*ierr == MPI_SUCCESS && *flag) {
        MPIR_fort_copy_str_from_c(value, value_len, value_i);
    }
    free(value_i);
}


FORT_DLL_SPEC void FORT_CALL mpi_info_get_nkeys_(MPI_Fint *info, MPI_Fint *nkeys, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Info_get_nkeys((MPI_Info) (*info), (int *) nkeys);
    
#else  /* ! HAVE_FINT_IS_INT */
    int nkeys_i;
    *ierr = MPI_Info_get_nkeys((MPI_Info) (*info), &nkeys_i);
    *nkeys = (MPI_Fint) nkeys_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_info_get_nthkey_(MPI_Fint *info, MPI_Fint *n, char *key FORT_MIXED_LEN(key_len), MPI_Fint *ierr FORT_END_LEN(key_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *key_i = malloc(key_len + 1);
    *ierr = MPI_Info_get_nthkey((MPI_Info) (*info), (int) (*n), key_i);
    if (*ierr == MPI_SUCCESS) {
        MPIR_fort_copy_str_from_c(key, key_len, key_i);
    }
    free(key_i);
}


FORT_DLL_SPEC void FORT_CALL mpi_info_get_string_(MPI_Fint *info, char *key FORT_MIXED_LEN(key_len), MPI_Fint *buflen, char *value FORT_MIXED_LEN(value_len), MPI_Fint *flag, MPI_Fint *ierr FORT_END_LEN(key_len) FORT_END_LEN(value_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *key_i = MPIR_fort_dup_str(key, key_len);
    int buflen_i = (*buflen > 0) ? (int) (*buflen + 1) : 0;
    int buflen_nonzero = (*buflen > 0);
    char *value_i = malloc(value_len + 1);
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Info_get_string((MPI_Info) (*info), key_i, &buflen_i, value_i, (int *) flag);
    
#else  /* ! HAVE_FINT_IS_INT */
    int flag_i;
    *ierr = MPI_Info_get_string((MPI_Info) (*info), key_i, &buflen_i, value_i, &flag_i);
    *flag = (MPI_Fint) flag_i;
#endif
    free(key_i);
    *buflen = (buflen_i > 0) ? (MPI_Fint) (buflen_i - 1) : 0;
    if (*ierr == MPI_SUCCESS && (*flag && buflen_nonzero)) {
        MPIR_fort_copy_str_from_c(value, value_len, value_i);
    }
    free(value_i);
}


FORT_DLL_SPEC void FORT_CALL mpi_info_get_valuelen_(MPI_Fint *info, char *key FORT_MIXED_LEN(key_len), MPI_Fint *valuelen, MPI_Fint *flag, MPI_Fint *ierr FORT_END_LEN(key_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *key_i = MPIR_fort_dup_str(key, key_len);
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Info_get_valuelen((MPI_Info) (*info), key_i, (int *) valuelen, (int *) flag);
    
#else  /* ! HAVE_FINT_IS_INT */
    int valuelen_i;
    int flag_i;
    *ierr = MPI_Info_get_valuelen((MPI_Info) (*info), key_i, &valuelen_i, &flag_i);
    *valuelen = (MPI_Fint) valuelen_i;
    *flag = (MPI_Fint) flag_i;
#endif
    free(key_i);
}


FORT_DLL_SPEC void FORT_CALL mpi_info_set_(MPI_Fint *info, char *key FORT_MIXED_LEN(key_len), char *value FORT_MIXED_LEN(value_len), MPI_Fint *ierr FORT_END_LEN(key_len) FORT_END_LEN(value_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *key_i = MPIR_fort_dup_str(key, key_len);
    char *value_i = MPIR_fort_dup_str(value, value_len);
    *ierr = MPI_Info_set((MPI_Info) (*info), key_i, value_i);
    free(key_i);
    free(value_i);
}


FORT_DLL_SPEC void FORT_CALL mpix_info_set_hex_(MPI_Fint *info, char *key FORT_MIXED_LEN(key_len), void *value, MPI_Fint *value_size, MPI_Fint *ierr FORT_END_LEN(key_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *key_i = MPIR_fort_dup_str(key, key_len);
    if (value == MPIR_F_MPI_BOTTOM) {
        value = MPI_BOTTOM;
    }
    
    *ierr = MPIX_Info_set_hex((MPI_Info) (*info), key_i, value, (int) (*value_size));
    free(key_i);
}


FORT_DLL_SPEC void FORT_CALL mpi_abort_(MPI_Fint *comm, MPI_Fint *errorcode, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Abort((MPI_Comm) (*comm), (int) (*errorcode));
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_create_from_group_(MPI_Fint *group, char *stringtag FORT_MIXED_LEN(stringtag_len), MPI_Fint *info, MPI_Fint *errhandler, MPI_Fint *newcomm, MPI_Fint *ierr FORT_END_LEN(stringtag_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *stringtag_i = MPIR_fort_dup_str(stringtag, stringtag_len);
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Comm_create_from_group((MPI_Group) (*group), stringtag_i, (MPI_Info) (*info), (MPI_Errhandler) (*errhandler), (MPI_Comm *) newcomm);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Comm newcomm_i;
    *ierr = MPI_Comm_create_from_group((MPI_Group) (*group), stringtag_i, (MPI_Info) (*info), (MPI_Errhandler) (*errhandler), &newcomm_i);
    *newcomm = (MPI_Fint) newcomm_i;
#endif
    free(stringtag_i);
}


FORT_DLL_SPEC void FORT_CALL mpi_finalize_(MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Finalize();
}


FORT_DLL_SPEC void FORT_CALL mpi_finalized_(MPI_Fint *flag, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    int flag_i;
    *ierr = MPI_Finalized(&flag_i);
    if (*ierr == MPI_SUCCESS) {
        *flag = MPII_TO_FLOG(flag_i);
    }
}


FORT_DLL_SPEC void FORT_CALL mpi_group_from_session_pset_(MPI_Fint *session, char *pset_name FORT_MIXED_LEN(pset_name_len), MPI_Fint *newgroup, MPI_Fint *ierr FORT_END_LEN(pset_name_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *pset_name_i = MPIR_fort_dup_str(pset_name, pset_name_len);
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Group_from_session_pset((MPI_Session) (*session), pset_name_i, (MPI_Group *) newgroup);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Group newgroup_i;
    *ierr = MPI_Group_from_session_pset((MPI_Session) (*session), pset_name_i, &newgroup_i);
    *newgroup = (MPI_Fint) newgroup_i;
#endif
    free(pset_name_i);
}


FORT_DLL_SPEC void FORT_CALL mpi_init_(MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Init(0, 0);
}


FORT_DLL_SPEC void FORT_CALL mpi_init_thread_(MPI_Fint *required, MPI_Fint *provided, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Init_thread(0, 0, (int) (*required), (int *) provided);
    
#else  /* ! HAVE_FINT_IS_INT */
    int provided_i;
    *ierr = MPI_Init_thread(0, 0, (int) (*required), &provided_i);
    *provided = (MPI_Fint) provided_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_initialized_(MPI_Fint *flag, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    int flag_i;
    *ierr = MPI_Initialized(&flag_i);
    if (*ierr == MPI_SUCCESS) {
        *flag = MPII_TO_FLOG(flag_i);
    }
}


FORT_DLL_SPEC void FORT_CALL mpi_is_thread_main_(MPI_Fint *flag, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    int flag_i;
    *ierr = MPI_Is_thread_main(&flag_i);
    if (*ierr == MPI_SUCCESS) {
        *flag = MPII_TO_FLOG(flag_i);
    }
}


FORT_DLL_SPEC void FORT_CALL mpi_query_thread_(MPI_Fint *provided, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Query_thread((int *) provided);
    
#else  /* ! HAVE_FINT_IS_INT */
    int provided_i;
    *ierr = MPI_Query_thread(&provided_i);
    *provided = (MPI_Fint) provided_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_session_finalize_(MPI_Fint *session, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Session_finalize((MPI_Session *) session);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Session session_i;
    session_i = (MPI_Session) *session;
    *ierr = MPI_Session_finalize(&session_i);
    *session = (MPI_Fint) session_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_session_get_info_(MPI_Fint *session, MPI_Fint *info_used, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Session_get_info((MPI_Session) (*session), (MPI_Info *) info_used);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Info info_used_i;
    *ierr = MPI_Session_get_info((MPI_Session) (*session), &info_used_i);
    *info_used = (MPI_Fint) info_used_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_session_get_nth_pset_(MPI_Fint *session, MPI_Fint *info, MPI_Fint *n, MPI_Fint *pset_len, char *pset_name FORT_MIXED_LEN(pset_name_len), MPI_Fint *ierr FORT_END_LEN(pset_name_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *pset_name_i = malloc(pset_name_len + 1);
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Session_get_nth_pset((MPI_Session) (*session), (MPI_Info) (*info), (int) (*n - 1), (int *) pset_len, pset_name_i);
    
#else  /* ! HAVE_FINT_IS_INT */
    int pset_len_i;
    pset_len_i = (int) *pset_len;
    *ierr = MPI_Session_get_nth_pset((MPI_Session) (*session), (MPI_Info) (*info), (int) (*n - 1), &pset_len_i, pset_name_i);
    *pset_len = (MPI_Fint) pset_len_i;
#endif
    if (*ierr == MPI_SUCCESS) {
        MPIR_fort_copy_str_from_c(pset_name, pset_name_len, pset_name_i);
    }
    free(pset_name_i);
}


FORT_DLL_SPEC void FORT_CALL mpi_session_get_num_psets_(MPI_Fint *session, MPI_Fint *info, MPI_Fint *npset_names, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Session_get_num_psets((MPI_Session) (*session), (MPI_Info) (*info), (int *) npset_names);
    
#else  /* ! HAVE_FINT_IS_INT */
    int npset_names_i;
    *ierr = MPI_Session_get_num_psets((MPI_Session) (*session), (MPI_Info) (*info), &npset_names_i);
    *npset_names = (MPI_Fint) npset_names_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_session_get_pset_info_(MPI_Fint *session, char *pset_name FORT_MIXED_LEN(pset_name_len), MPI_Fint *info, MPI_Fint *ierr FORT_END_LEN(pset_name_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *pset_name_i = MPIR_fort_dup_str(pset_name, pset_name_len);
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Session_get_pset_info((MPI_Session) (*session), pset_name_i, (MPI_Info *) info);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Info info_i;
    *ierr = MPI_Session_get_pset_info((MPI_Session) (*session), pset_name_i, &info_i);
    *info = (MPI_Fint) info_i;
#endif
    free(pset_name_i);
}


FORT_DLL_SPEC void FORT_CALL mpi_session_init_(MPI_Fint *info, MPI_Fint *errhandler, MPI_Fint *session, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Session_init((MPI_Info) (*info), (MPI_Errhandler) (*errhandler), (MPI_Session *) session);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Session session_i;
    *ierr = MPI_Session_init((MPI_Info) (*info), (MPI_Errhandler) (*errhandler), &session_i);
    *session = (MPI_Fint) session_i;
#endif
}


FORT_DLL_SPEC MPI_Aint FORT_CALL mpi_aint_add_(MPI_Aint *base, MPI_Aint *disp) {
    return MPI_Aint_add(*base, *disp);
}


FORT_DLL_SPEC MPI_Aint FORT_CALL mpi_aint_diff_(MPI_Aint *addr1, MPI_Aint *addr2) {
    return MPI_Aint_diff(*addr1, *addr2);
}


FORT_DLL_SPEC void FORT_CALL mpi_get_library_version_(char *version FORT_MIXED_LEN(version_len), MPI_Fint *resultlen, MPI_Fint *ierr FORT_END_LEN(version_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *version_i = malloc(version_len + 1);
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Get_library_version(version_i, (int *) resultlen);
    
#else  /* ! HAVE_FINT_IS_INT */
    int resultlen_i;
    *ierr = MPI_Get_library_version(version_i, &resultlen_i);
    *resultlen = (MPI_Fint) resultlen_i;
#endif
    if (*ierr == MPI_SUCCESS) {
        MPIR_fort_copy_str_from_c(version, version_len, version_i);
    }
    free(version_i);
}


FORT_DLL_SPEC void FORT_CALL mpi_get_processor_name_(char *name FORT_MIXED_LEN(name_len), MPI_Fint *resultlen, MPI_Fint *ierr FORT_END_LEN(name_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *name_i = malloc(name_len + 1);
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Get_processor_name(name_i, (int *) resultlen);
    
#else  /* ! HAVE_FINT_IS_INT */
    int resultlen_i;
    *ierr = MPI_Get_processor_name(name_i, &resultlen_i);
    *resultlen = (MPI_Fint) resultlen_i;
#endif
    if (*ierr == MPI_SUCCESS) {
        MPIR_fort_copy_str_from_c(name, name_len, name_i);
    }
    free(name_i);
}


FORT_DLL_SPEC void FORT_CALL mpi_get_version_(MPI_Fint *version, MPI_Fint *subversion, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Get_version((int *) version, (int *) subversion);
    
#else  /* ! HAVE_FINT_IS_INT */
    int version_i;
    int subversion_i;
    *ierr = MPI_Get_version(&version_i, &subversion_i);
    *version = (MPI_Fint) version_i;
    *subversion = (MPI_Fint) subversion_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_pcontrol_(MPI_Fint *level) {
    MPI_Pcontrol((int) (*level));
}


FORT_DLL_SPEC void FORT_CALL mpix_gpu_query_support_(MPI_Fint *gpu_type, MPI_Fint *is_supported, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    int is_supported_i;
    *ierr = MPIX_GPU_query_support((int) (*gpu_type), &is_supported_i);
    if (*ierr == MPI_SUCCESS) {
        *is_supported = MPII_TO_FLOG(is_supported_i);
    }
}


FORT_DLL_SPEC void FORT_CALL mpix_query_cuda_support_(MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPIX_Query_cuda_support();
}


FORT_DLL_SPEC void FORT_CALL mpix_query_ze_support_(MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPIX_Query_ze_support();
}


FORT_DLL_SPEC void FORT_CALL mpix_query_hip_support_(MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPIX_Query_hip_support();
}


FORT_DLL_SPEC void FORT_CALL mpi_op_commutative_(MPI_Fint *op, MPI_Fint *commute, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    int commute_i;
    *ierr = MPI_Op_commutative((MPI_Op) (*op), &commute_i);
    if (*ierr == MPI_SUCCESS) {
        *commute = MPII_TO_FLOG(commute_i);
    }
}


FORT_DLL_SPEC void FORT_CALL mpi_op_create_(F77_OpFunction *user_fn, MPI_Fint *commute, MPI_Fint *op, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPII_op_create(user_fn, *commute, op);
}


FORT_DLL_SPEC void FORT_CALL mpi_op_free_(MPI_Fint *op, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Op_free((MPI_Op *) op);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Op op_i;
    op_i = (MPI_Op) *op;
    *ierr = MPI_Op_free(&op_i);
    *op = (MPI_Fint) op_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_parrived_(MPI_Fint *request, MPI_Fint *partition, MPI_Fint *flag, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Parrived((MPI_Request) (*request), (int) (*partition), (int *) flag);
    
#else  /* ! HAVE_FINT_IS_INT */
    int flag_i;
    *ierr = MPI_Parrived((MPI_Request) (*request), (int) (*partition), &flag_i);
    *flag = (MPI_Fint) flag_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_pready_(MPI_Fint *partition, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Pready((int) (*partition), (MPI_Request) (*request));
}


FORT_DLL_SPEC void FORT_CALL mpi_pready_list_(MPI_Fint *length, MPI_Fint *array_of_partitions, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Pready_list((int) (*length), (int *) array_of_partitions, (MPI_Request) (*request));
    
#else  /* ! HAVE_FINT_IS_INT */
    int *array_of_partitions_i;
    array_of_partitions_i = malloc(sizeof(int) * (*length));
    for (int i = 0; i < (*length); i++) {
        array_of_partitions_i[i] = (int) array_of_partitions[i];
    }
    *ierr = MPI_Pready_list((int) (*length), array_of_partitions_i, (MPI_Request) (*request));
    free(array_of_partitions_i);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_pready_range_(MPI_Fint *partition_low, MPI_Fint *partition_high, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Pready_range((int) (*partition_low), (int) (*partition_high), (MPI_Request) (*request));
}


FORT_DLL_SPEC void FORT_CALL mpi_precv_init_(void *buf, MPI_Fint *partitions, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *info, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Precv_init(buf, (int) (*partitions), (MPI_Count) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*tag), (MPI_Comm) (*comm), (MPI_Info) (*info), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Precv_init(buf, (int) (*partitions), (MPI_Count) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*tag), (MPI_Comm) (*comm), (MPI_Info) (*info), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_psend_init_(void *buf, MPI_Fint *partitions, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *info, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Psend_init(buf, (int) (*partitions), (MPI_Count) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*tag), (MPI_Comm) (*comm), (MPI_Info) (*info), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Psend_init(buf, (int) (*partitions), (MPI_Count) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*tag), (MPI_Comm) (*comm), (MPI_Info) (*info), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_bsend_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
    *ierr = MPI_Bsend(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*tag), (MPI_Comm) (*comm));
}


FORT_DLL_SPEC void FORT_CALL mpi_bsend_init_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Bsend_init(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*tag), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Bsend_init(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*tag), (MPI_Comm) (*comm), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_buffer_attach_(void *buffer, MPI_Fint *size, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buffer == MPIR_F_MPI_BUFFER_AUTOMATIC) {
        buffer = MPI_BUFFER_AUTOMATIC;
    }
    
    *ierr = MPI_Buffer_attach(buffer, (int) (*size));
}


FORT_DLL_SPEC void FORT_CALL mpi_buffer_detach_(MPI_Aint *buffer_addr, MPI_Fint *size, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    void * buffer_addr_i;
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Buffer_detach(&buffer_addr_i, (int *) size);
    
#else  /* ! HAVE_FINT_IS_INT */
    int size_i;
    *ierr = MPI_Buffer_detach(&buffer_addr_i, &size_i);
    *size = (MPI_Fint) size_i;
#endif
    *buffer_addr = (MPI_Aint) buffer_addr_i;
}


FORT_DLL_SPEC void FORT_CALL mpi_buffer_flush_(MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Buffer_flush();
}


FORT_DLL_SPEC void FORT_CALL mpi_buffer_iflush_(MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Buffer_iflush((MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Buffer_iflush(&request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_attach_buffer_(MPI_Fint *comm, void *buffer, MPI_Fint *size, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buffer == MPIR_F_MPI_BOTTOM) {
        buffer = MPI_BOTTOM;
    }
    
    *ierr = MPI_Comm_attach_buffer((MPI_Comm) (*comm), buffer, (int) (*size));
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_detach_buffer_(MPI_Fint *comm, MPI_Aint *buffer_addr, MPI_Fint *size, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    void * buffer_addr_i;
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Comm_detach_buffer((MPI_Comm) (*comm), &buffer_addr_i, (int *) size);
    
#else  /* ! HAVE_FINT_IS_INT */
    int size_i;
    *ierr = MPI_Comm_detach_buffer((MPI_Comm) (*comm), &buffer_addr_i, &size_i);
    *size = (MPI_Fint) size_i;
#endif
    *buffer_addr = (MPI_Aint) buffer_addr_i;
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_flush_buffer_(MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Comm_flush_buffer((MPI_Comm) (*comm));
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_iflush_buffer_(MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Comm_iflush_buffer((MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Comm_iflush_buffer((MPI_Comm) (*comm), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_ibsend_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Ibsend(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*tag), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Ibsend(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*tag), (MPI_Comm) (*comm), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_improbe_(MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *flag, MPI_Fint *message, MPI_Fint *status, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    int flag_i;
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPI_Improbe((int) (*source), (int) (*tag), (MPI_Comm) (*comm), &flag_i, (MPI_Message *) message, (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Message message_i;
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPI_Improbe((int) (*source), (int) (*tag), (MPI_Comm) (*comm), &flag_i, &message_i, status_arg);
    *message = (MPI_Fint) message_i;
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
    if (*ierr == MPI_SUCCESS) {
        *flag = MPII_TO_FLOG(flag_i);
    }
}


FORT_DLL_SPEC void FORT_CALL mpi_imrecv_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *message, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Imrecv(buf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Message *) message, (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Message message_i;
    message_i = (MPI_Message) *message;
    MPI_Request request_i;
    *ierr = MPI_Imrecv(buf, (int) (*count), (MPI_Datatype) (*datatype), &message_i, &request_i);
    *message = (MPI_Fint) message_i;
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_iprobe_(MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *flag, MPI_Fint *status, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    int flag_i;
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPI_Iprobe((int) (*source), (int) (*tag), (MPI_Comm) (*comm), &flag_i, (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPI_Iprobe((int) (*source), (int) (*tag), (MPI_Comm) (*comm), &flag_i, status_arg);
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
    if (*ierr == MPI_SUCCESS) {
        *flag = MPII_TO_FLOG(flag_i);
    }
}


FORT_DLL_SPEC void FORT_CALL mpi_irecv_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Irecv(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*source), (int) (*tag), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Irecv(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*source), (int) (*tag), (MPI_Comm) (*comm), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_irsend_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Irsend(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*tag), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Irsend(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*tag), (MPI_Comm) (*comm), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_isend_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Isend(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*tag), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Isend(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*tag), (MPI_Comm) (*comm), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_isendrecv_(void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *dest, MPI_Fint *sendtag, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *source, MPI_Fint *recvtag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Isendrecv(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), (int) (*dest), (int) (*sendtag), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (int) (*source), (int) (*recvtag), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Isendrecv(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), (int) (*dest), (int) (*sendtag), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (int) (*source), (int) (*recvtag), (MPI_Comm) (*comm), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_isendrecv_replace_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *sendtag, MPI_Fint *source, MPI_Fint *recvtag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Isendrecv_replace(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*sendtag), (int) (*source), (int) (*recvtag), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Isendrecv_replace(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*sendtag), (int) (*source), (int) (*recvtag), (MPI_Comm) (*comm), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_issend_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Issend(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*tag), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Issend(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*tag), (MPI_Comm) (*comm), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_mprobe_(MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *message, MPI_Fint *status, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPI_Mprobe((int) (*source), (int) (*tag), (MPI_Comm) (*comm), (MPI_Message *) message, (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Message message_i;
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPI_Mprobe((int) (*source), (int) (*tag), (MPI_Comm) (*comm), &message_i, status_arg);
    *message = (MPI_Fint) message_i;
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_mrecv_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *message, MPI_Fint *status, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPI_Mrecv(buf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Message *) message, (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Message message_i;
    message_i = (MPI_Message) *message;
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPI_Mrecv(buf, (int) (*count), (MPI_Datatype) (*datatype), &message_i, status_arg);
    *message = (MPI_Fint) message_i;
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_probe_(MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPI_Probe((int) (*source), (int) (*tag), (MPI_Comm) (*comm), (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPI_Probe((int) (*source), (int) (*tag), (MPI_Comm) (*comm), status_arg);
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_recv_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPI_Recv(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*source), (int) (*tag), (MPI_Comm) (*comm), (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPI_Recv(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*source), (int) (*tag), (MPI_Comm) (*comm), status_arg);
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_recv_init_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Recv_init(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*source), (int) (*tag), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Recv_init(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*source), (int) (*tag), (MPI_Comm) (*comm), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_rsend_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
    *ierr = MPI_Rsend(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*tag), (MPI_Comm) (*comm));
}


FORT_DLL_SPEC void FORT_CALL mpi_rsend_init_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Rsend_init(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*tag), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Rsend_init(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*tag), (MPI_Comm) (*comm), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_send_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
    *ierr = MPI_Send(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*tag), (MPI_Comm) (*comm));
}


FORT_DLL_SPEC void FORT_CALL mpi_send_init_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Send_init(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*tag), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Send_init(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*tag), (MPI_Comm) (*comm), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_sendrecv_(void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *dest, MPI_Fint *sendtag, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *source, MPI_Fint *recvtag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPI_Sendrecv(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), (int) (*dest), (int) (*sendtag), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (int) (*source), (int) (*recvtag), (MPI_Comm) (*comm), (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPI_Sendrecv(sendbuf, (int) (*sendcount), (MPI_Datatype) (*sendtype), (int) (*dest), (int) (*sendtag), recvbuf, (int) (*recvcount), (MPI_Datatype) (*recvtype), (int) (*source), (int) (*recvtag), (MPI_Comm) (*comm), status_arg);
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_sendrecv_replace_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *sendtag, MPI_Fint *source, MPI_Fint *recvtag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPI_Sendrecv_replace(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*sendtag), (int) (*source), (int) (*recvtag), (MPI_Comm) (*comm), (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPI_Sendrecv_replace(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*sendtag), (int) (*source), (int) (*recvtag), (MPI_Comm) (*comm), status_arg);
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_session_attach_buffer_(MPI_Fint *session, void *buffer, MPI_Fint *size, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buffer == MPIR_F_MPI_BOTTOM) {
        buffer = MPI_BOTTOM;
    }
    
    *ierr = MPI_Session_attach_buffer((MPI_Session) (*session), buffer, (int) (*size));
}


FORT_DLL_SPEC void FORT_CALL mpi_session_detach_buffer_(MPI_Fint *session, MPI_Aint *buffer_addr, MPI_Fint *size, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    void * buffer_addr_i;
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Session_detach_buffer((MPI_Session) (*session), &buffer_addr_i, (int *) size);
    
#else  /* ! HAVE_FINT_IS_INT */
    int size_i;
    *ierr = MPI_Session_detach_buffer((MPI_Session) (*session), &buffer_addr_i, &size_i);
    *size = (MPI_Fint) size_i;
#endif
    *buffer_addr = (MPI_Aint) buffer_addr_i;
}


FORT_DLL_SPEC void FORT_CALL mpi_session_flush_buffer_(MPI_Fint *session, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Session_flush_buffer((MPI_Session) (*session));
}


FORT_DLL_SPEC void FORT_CALL mpi_session_iflush_buffer_(MPI_Fint *session, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Session_iflush_buffer((MPI_Session) (*session), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Session_iflush_buffer((MPI_Session) (*session), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_ssend_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
    *ierr = MPI_Ssend(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*tag), (MPI_Comm) (*comm));
}


FORT_DLL_SPEC void FORT_CALL mpi_ssend_init_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Ssend_init(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*tag), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Ssend_init(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*tag), (MPI_Comm) (*comm), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_cancel_(MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Cancel((MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    request_i = (MPI_Request) *request;
    *ierr = MPI_Cancel(&request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_grequest_complete_(MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Grequest_complete((MPI_Request) (*request));
}


FORT_DLL_SPEC void FORT_CALL mpi_grequest_start_(MPI_Grequest_query_function query_fn, MPI_Grequest_free_function free_fn, MPI_Grequest_cancel_function cancel_fn, void *extra_state, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Grequest_start(query_fn, free_fn, cancel_fn, extra_state, (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Grequest_start(query_fn, free_fn, cancel_fn, extra_state, &request_i);
    *request = (MPI_Fint) request_i;
#endif
    if (!*ierr) {
        MPII_Grequest_set_lang_f77((int) *request);
    }
}


FORT_DLL_SPEC void FORT_CALL mpi_request_free_(MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Request_free((MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    request_i = (MPI_Request) *request;
    *ierr = MPI_Request_free(&request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_request_get_status_(MPI_Fint *request, MPI_Fint *flag, MPI_Fint *status, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    int flag_i;
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPI_Request_get_status((MPI_Request) (*request), &flag_i, (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPI_Request_get_status((MPI_Request) (*request), &flag_i, status_arg);
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
    if (*ierr == MPI_SUCCESS) {
        *flag = MPII_TO_FLOG(flag_i);
    }
}


FORT_DLL_SPEC void FORT_CALL mpi_request_get_status_all_(MPI_Fint *count, MPI_Fint *array_of_requests, MPI_Fint *flag, MPI_Fint *array_of_statuses, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    int flag_i;
#ifdef HAVE_FINT_IS_INT
    if (array_of_statuses == MPI_F_STATUSES_IGNORE) {
        array_of_statuses = (MPI_Fint *) MPI_STATUSES_IGNORE;
    }
    *ierr = MPI_Request_get_status_all((int) (*count), (int *) array_of_requests, &flag_i, (MPI_Status *) array_of_statuses);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request *array_of_requests_i;
    array_of_requests_i = malloc(sizeof(MPI_Request) * (*count));
    for (int i = 0; i < (*count); i++) {
        array_of_requests_i[i] = (MPI_Request) array_of_requests[i];
    }
    MPI_Status *statuses_i;
    if (array_of_statuses == MPI_F_STATUSES_IGNORE) {
        statuses_i = MPI_STATUS_IGNORE;
    } else {
        statuses_i = malloc((*count) * sizeof(MPI_Status));
        int *p = (int *) statuses_i;
        for (int i = 0; i < (*count) * MPI_F_STATUS_SIZE; i++) {
            p[i] = (int) array_of_statuses[i];
        }
    }
    *ierr = MPI_Request_get_status_all((int) (*count), array_of_requests_i, &flag_i, statuses_i);
    free(array_of_requests_i);
    if (array_of_statuses != MPI_F_STATUSES_IGNORE) {
        int *p = (int *) statuses_i;
        for (int i = 0; i < (*count) * MPI_F_STATUS_SIZE; i++) {
            array_of_statuses[i] = (MPI_Fint) p[i];
        }
        free(statuses_i);
    }
#endif
    if (*ierr == MPI_SUCCESS) {
        *flag = MPII_TO_FLOG(flag_i);
    }
}


FORT_DLL_SPEC void FORT_CALL mpi_request_get_status_any_(MPI_Fint *count, MPI_Fint *array_of_requests, MPI_Fint *indx, MPI_Fint *flag, MPI_Fint *status, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    int indx_i;
    int flag_i;
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPI_Request_get_status_any((int) (*count), (int *) array_of_requests, &indx_i, &flag_i, (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request *array_of_requests_i;
    array_of_requests_i = malloc(sizeof(MPI_Request) * (*count));
    for (int i = 0; i < (*count); i++) {
        array_of_requests_i[i] = (MPI_Request) array_of_requests[i];
    }
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPI_Request_get_status_any((int) (*count), array_of_requests_i, &indx_i, &flag_i, status_arg);
    free(array_of_requests_i);
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
    if (*ierr == MPI_SUCCESS) {
        if (indx_i == MPI_UNDEFINED) {
            *indx = indx_i;
        } else {
            *indx = indx_i + 1;
        }
    }
    if (*ierr == MPI_SUCCESS) {
        *flag = MPII_TO_FLOG(flag_i);
    }
}


FORT_DLL_SPEC void FORT_CALL mpi_request_get_status_some_(MPI_Fint *incount, MPI_Fint *array_of_requests, MPI_Fint *outcount, MPI_Fint *array_of_indices, MPI_Fint *array_of_statuses, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    if (array_of_statuses == MPI_F_STATUSES_IGNORE) {
        array_of_statuses = (MPI_Fint *) MPI_STATUSES_IGNORE;
    }
    *ierr = MPI_Request_get_status_some((int) (*incount), (int *) array_of_requests, (int *) outcount, (int *) array_of_indices, (MPI_Status *) array_of_statuses);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request *array_of_requests_i;
    array_of_requests_i = malloc(sizeof(MPI_Request) * (*incount));
    for (int i = 0; i < (*incount); i++) {
        array_of_requests_i[i] = (MPI_Request) array_of_requests[i];
    }
    int outcount_i;
    int *array_of_indices_i;
    array_of_indices_i = malloc(sizeof(int) * (*incount));
    MPI_Status *statuses_i;
    if (array_of_statuses == MPI_F_STATUSES_IGNORE) {
        statuses_i = MPI_STATUS_IGNORE;
    } else {
        statuses_i = malloc((*incount) * sizeof(MPI_Status));
        int *p = (int *) statuses_i;
        for (int i = 0; i < (*incount) * MPI_F_STATUS_SIZE; i++) {
            p[i] = (int) array_of_statuses[i];
        }
    }
    *ierr = MPI_Request_get_status_some((int) (*incount), array_of_requests_i, &outcount_i, array_of_indices_i, statuses_i);
    free(array_of_requests_i);
    *outcount = (MPI_Fint) outcount_i;
    for (int i = 0; i < (*outcount); i++) {
        array_of_indices[i] = (MPI_Fint) array_of_indices_i[i];
    }
    free(array_of_indices_i);
    if (array_of_statuses != MPI_F_STATUSES_IGNORE) {
        int *p = (int *) statuses_i;
        for (int i = 0; i < (*outcount) * MPI_F_STATUS_SIZE; i++) {
            array_of_statuses[i] = (MPI_Fint) p[i];
        }
        free(statuses_i);
    }
#endif
    for (int i = 0; i < (*outcount); i++) {
        array_of_indices[i] += 1;
    }
}


FORT_DLL_SPEC void FORT_CALL mpi_start_(MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Start((MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    request_i = (MPI_Request) *request;
    *ierr = MPI_Start(&request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_startall_(MPI_Fint *count, MPI_Fint *array_of_requests, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Startall((int) (*count), (int *) array_of_requests);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request *array_of_requests_i;
    array_of_requests_i = malloc(sizeof(MPI_Request) * (*count));
    for (int i = 0; i < (*count); i++) {
        array_of_requests_i[i] = (MPI_Request) array_of_requests[i];
    }
    *ierr = MPI_Startall((int) (*count), array_of_requests_i);
    for (int i = 0; i < (*count); i++) {
        array_of_requests[i] = (MPI_Fint) array_of_requests_i[i];
    }
    free(array_of_requests_i);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_status_get_error_(MPI_Fint *status, MPI_Fint *error, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Status_get_error((MPI_Status *) status, (int *) error);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    status_arg = (MPI_Status *) status_i;
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status_i[i] = (int) status[i];
    }
    int error_i;
    *ierr = MPI_Status_get_error(status_arg, &error_i);
    *error = (MPI_Fint) error_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_status_get_source_(MPI_Fint *status, MPI_Fint *source, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Status_get_source((MPI_Status *) status, (int *) source);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    status_arg = (MPI_Status *) status_i;
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status_i[i] = (int) status[i];
    }
    int source_i;
    *ierr = MPI_Status_get_source(status_arg, &source_i);
    *source = (MPI_Fint) source_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_status_get_tag_(MPI_Fint *status, MPI_Fint *tag, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Status_get_tag((MPI_Status *) status, (int *) tag);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    status_arg = (MPI_Status *) status_i;
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status_i[i] = (int) status[i];
    }
    int tag_i;
    *ierr = MPI_Status_get_tag(status_arg, &tag_i);
    *tag = (MPI_Fint) tag_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_status_set_error_(MPI_Fint *status, MPI_Fint *error, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Status_set_error((MPI_Status *) status, (int) (*error));
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    status_arg = (MPI_Status *) status_i;
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status_i[i] = (int) status[i];
    }
    *ierr = MPI_Status_set_error(status_arg, (int) (*error));
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_status_set_source_(MPI_Fint *status, MPI_Fint *source, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Status_set_source((MPI_Status *) status, (int) (*source));
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    status_arg = (MPI_Status *) status_i;
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status_i[i] = (int) status[i];
    }
    *ierr = MPI_Status_set_source(status_arg, (int) (*source));
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_status_set_tag_(MPI_Fint *status, MPI_Fint *tag, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Status_set_tag((MPI_Status *) status, (int) (*tag));
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    status_arg = (MPI_Status *) status_i;
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status_i[i] = (int) status[i];
    }
    *ierr = MPI_Status_set_tag(status_arg, (int) (*tag));
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_status_set_cancelled_(MPI_Fint *status, MPI_Fint *flag, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Status_set_cancelled((MPI_Status *) status, *flag);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    status_arg = (MPI_Status *) status_i;
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status_i[i] = (int) status[i];
    }
    *ierr = MPI_Status_set_cancelled(status_arg, *flag);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_test_(MPI_Fint *request, MPI_Fint *flag, MPI_Fint *status, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    int flag_i;
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPI_Test((MPI_Request *) request, &flag_i, (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    request_i = (MPI_Request) *request;
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPI_Test(&request_i, &flag_i, status_arg);
    *request = (MPI_Fint) request_i;
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
    if (*ierr == MPI_SUCCESS) {
        *flag = MPII_TO_FLOG(flag_i);
    }
}


FORT_DLL_SPEC void FORT_CALL mpi_test_cancelled_(MPI_Fint *status, MPI_Fint *flag, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    int flag_i;
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Test_cancelled((MPI_Status *) status, &flag_i);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    status_arg = (MPI_Status *) status_i;
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status_i[i] = (int) status[i];
    }
    *ierr = MPI_Test_cancelled(status_arg, &flag_i);
#endif
    if (*ierr == MPI_SUCCESS) {
        *flag = MPII_TO_FLOG(flag_i);
    }
}


FORT_DLL_SPEC void FORT_CALL mpi_testall_(MPI_Fint *count, MPI_Fint *array_of_requests, MPI_Fint *flag, MPI_Fint *array_of_statuses, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    int flag_i;
#ifdef HAVE_FINT_IS_INT
    if (array_of_statuses == MPI_F_STATUSES_IGNORE) {
        array_of_statuses = (MPI_Fint *) MPI_STATUSES_IGNORE;
    }
    *ierr = MPI_Testall((int) (*count), (int *) array_of_requests, &flag_i, (MPI_Status *) array_of_statuses);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request *array_of_requests_i;
    array_of_requests_i = malloc(sizeof(MPI_Request) * (*count));
    for (int i = 0; i < (*count); i++) {
        array_of_requests_i[i] = (MPI_Request) array_of_requests[i];
    }
    MPI_Status *statuses_i;
    if (array_of_statuses == MPI_F_STATUSES_IGNORE) {
        statuses_i = MPI_STATUS_IGNORE;
    } else {
        statuses_i = malloc((*count) * sizeof(MPI_Status));
        int *p = (int *) statuses_i;
        for (int i = 0; i < (*count) * MPI_F_STATUS_SIZE; i++) {
            p[i] = (int) array_of_statuses[i];
        }
    }
    *ierr = MPI_Testall((int) (*count), array_of_requests_i, &flag_i, statuses_i);
    for (int i = 0; i < (*count); i++) {
        array_of_requests[i] = (MPI_Fint) array_of_requests_i[i];
    }
    free(array_of_requests_i);
    if (array_of_statuses != MPI_F_STATUSES_IGNORE) {
        int *p = (int *) statuses_i;
        for (int i = 0; i < (*count) * MPI_F_STATUS_SIZE; i++) {
            array_of_statuses[i] = (MPI_Fint) p[i];
        }
        free(statuses_i);
    }
#endif
    if (*ierr == MPI_SUCCESS) {
        *flag = MPII_TO_FLOG(flag_i);
    }
}


FORT_DLL_SPEC void FORT_CALL mpi_testany_(MPI_Fint *count, MPI_Fint *array_of_requests, MPI_Fint *indx, MPI_Fint *flag, MPI_Fint *status, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    int indx_i;
    int flag_i;
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPI_Testany((int) (*count), (int *) array_of_requests, &indx_i, &flag_i, (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request *array_of_requests_i;
    array_of_requests_i = malloc(sizeof(MPI_Request) * (*count));
    for (int i = 0; i < (*count); i++) {
        array_of_requests_i[i] = (MPI_Request) array_of_requests[i];
    }
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPI_Testany((int) (*count), array_of_requests_i, &indx_i, &flag_i, status_arg);
    for (int i = 0; i < (*count); i++) {
        array_of_requests[i] = (MPI_Fint) array_of_requests_i[i];
    }
    free(array_of_requests_i);
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
    if (*ierr == MPI_SUCCESS) {
        if (indx_i == MPI_UNDEFINED) {
            *indx = indx_i;
        } else {
            *indx = indx_i + 1;
        }
    }
    if (*ierr == MPI_SUCCESS) {
        *flag = MPII_TO_FLOG(flag_i);
    }
}


FORT_DLL_SPEC void FORT_CALL mpi_testsome_(MPI_Fint *incount, MPI_Fint *array_of_requests, MPI_Fint *outcount, MPI_Fint *array_of_indices, MPI_Fint *array_of_statuses, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    if (array_of_statuses == MPI_F_STATUSES_IGNORE) {
        array_of_statuses = (MPI_Fint *) MPI_STATUSES_IGNORE;
    }
    *ierr = MPI_Testsome((int) (*incount), (int *) array_of_requests, (int *) outcount, (int *) array_of_indices, (MPI_Status *) array_of_statuses);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request *array_of_requests_i;
    array_of_requests_i = malloc(sizeof(MPI_Request) * (*incount));
    for (int i = 0; i < (*incount); i++) {
        array_of_requests_i[i] = (MPI_Request) array_of_requests[i];
    }
    int outcount_i;
    int *array_of_indices_i;
    array_of_indices_i = malloc(sizeof(int) * (*incount));
    MPI_Status *statuses_i;
    if (array_of_statuses == MPI_F_STATUSES_IGNORE) {
        statuses_i = MPI_STATUS_IGNORE;
    } else {
        statuses_i = malloc((*incount) * sizeof(MPI_Status));
        int *p = (int *) statuses_i;
        for (int i = 0; i < (*incount) * MPI_F_STATUS_SIZE; i++) {
            p[i] = (int) array_of_statuses[i];
        }
    }
    *ierr = MPI_Testsome((int) (*incount), array_of_requests_i, &outcount_i, array_of_indices_i, statuses_i);
    for (int i = 0; i < (*incount); i++) {
        array_of_requests[i] = (MPI_Fint) array_of_requests_i[i];
    }
    free(array_of_requests_i);
    *outcount = (MPI_Fint) outcount_i;
    for (int i = 0; i < (*outcount); i++) {
        array_of_indices[i] = (MPI_Fint) array_of_indices_i[i];
    }
    free(array_of_indices_i);
    if (array_of_statuses != MPI_F_STATUSES_IGNORE) {
        int *p = (int *) statuses_i;
        for (int i = 0; i < (*outcount) * MPI_F_STATUS_SIZE; i++) {
            array_of_statuses[i] = (MPI_Fint) p[i];
        }
        free(statuses_i);
    }
#endif
    for (int i = 0; i < (*outcount); i++) {
        array_of_indices[i] += 1;
    }
}


FORT_DLL_SPEC void FORT_CALL mpi_wait_(MPI_Fint *request, MPI_Fint *status, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPI_Wait((MPI_Request *) request, (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    request_i = (MPI_Request) *request;
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPI_Wait(&request_i, status_arg);
    *request = (MPI_Fint) request_i;
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_waitall_(MPI_Fint *count, MPI_Fint *array_of_requests, MPI_Fint *array_of_statuses, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    if (array_of_statuses == MPI_F_STATUSES_IGNORE) {
        array_of_statuses = (MPI_Fint *) MPI_STATUSES_IGNORE;
    }
    *ierr = MPI_Waitall((int) (*count), (int *) array_of_requests, (MPI_Status *) array_of_statuses);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request *array_of_requests_i;
    array_of_requests_i = malloc(sizeof(MPI_Request) * (*count));
    for (int i = 0; i < (*count); i++) {
        array_of_requests_i[i] = (MPI_Request) array_of_requests[i];
    }
    MPI_Status *statuses_i;
    if (array_of_statuses == MPI_F_STATUSES_IGNORE) {
        statuses_i = MPI_STATUS_IGNORE;
    } else {
        statuses_i = malloc((*count) * sizeof(MPI_Status));
        int *p = (int *) statuses_i;
        for (int i = 0; i < (*count) * MPI_F_STATUS_SIZE; i++) {
            p[i] = (int) array_of_statuses[i];
        }
    }
    *ierr = MPI_Waitall((int) (*count), array_of_requests_i, statuses_i);
    for (int i = 0; i < (*count); i++) {
        array_of_requests[i] = (MPI_Fint) array_of_requests_i[i];
    }
    free(array_of_requests_i);
    if (array_of_statuses != MPI_F_STATUSES_IGNORE) {
        int *p = (int *) statuses_i;
        for (int i = 0; i < (*count) * MPI_F_STATUS_SIZE; i++) {
            array_of_statuses[i] = (MPI_Fint) p[i];
        }
        free(statuses_i);
    }
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_waitany_(MPI_Fint *count, MPI_Fint *array_of_requests, MPI_Fint *indx, MPI_Fint *status, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    int indx_i;
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPI_Waitany((int) (*count), (int *) array_of_requests, &indx_i, (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request *array_of_requests_i;
    array_of_requests_i = malloc(sizeof(MPI_Request) * (*count));
    for (int i = 0; i < (*count); i++) {
        array_of_requests_i[i] = (MPI_Request) array_of_requests[i];
    }
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPI_Waitany((int) (*count), array_of_requests_i, &indx_i, status_arg);
    for (int i = 0; i < (*count); i++) {
        array_of_requests[i] = (MPI_Fint) array_of_requests_i[i];
    }
    free(array_of_requests_i);
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
    if (*ierr == MPI_SUCCESS) {
        if (indx_i == MPI_UNDEFINED) {
            *indx = indx_i;
        } else {
            *indx = indx_i + 1;
        }
    }
}


FORT_DLL_SPEC void FORT_CALL mpi_waitsome_(MPI_Fint *incount, MPI_Fint *array_of_requests, MPI_Fint *outcount, MPI_Fint *array_of_indices, MPI_Fint *array_of_statuses, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    if (array_of_statuses == MPI_F_STATUSES_IGNORE) {
        array_of_statuses = (MPI_Fint *) MPI_STATUSES_IGNORE;
    }
    *ierr = MPI_Waitsome((int) (*incount), (int *) array_of_requests, (int *) outcount, (int *) array_of_indices, (MPI_Status *) array_of_statuses);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request *array_of_requests_i;
    array_of_requests_i = malloc(sizeof(MPI_Request) * (*incount));
    for (int i = 0; i < (*incount); i++) {
        array_of_requests_i[i] = (MPI_Request) array_of_requests[i];
    }
    int outcount_i;
    int *array_of_indices_i;
    array_of_indices_i = malloc(sizeof(int) * (*incount));
    MPI_Status *statuses_i;
    if (array_of_statuses == MPI_F_STATUSES_IGNORE) {
        statuses_i = MPI_STATUS_IGNORE;
    } else {
        statuses_i = malloc((*incount) * sizeof(MPI_Status));
        int *p = (int *) statuses_i;
        for (int i = 0; i < (*incount) * MPI_F_STATUS_SIZE; i++) {
            p[i] = (int) array_of_statuses[i];
        }
    }
    *ierr = MPI_Waitsome((int) (*incount), array_of_requests_i, &outcount_i, array_of_indices_i, statuses_i);
    for (int i = 0; i < (*incount); i++) {
        array_of_requests[i] = (MPI_Fint) array_of_requests_i[i];
    }
    free(array_of_requests_i);
    *outcount = (MPI_Fint) outcount_i;
    for (int i = 0; i < (*outcount); i++) {
        array_of_indices[i] = (MPI_Fint) array_of_indices_i[i];
    }
    free(array_of_indices_i);
    if (array_of_statuses != MPI_F_STATUSES_IGNORE) {
        int *p = (int *) statuses_i;
        for (int i = 0; i < (*outcount) * MPI_F_STATUS_SIZE; i++) {
            array_of_statuses[i] = (MPI_Fint) p[i];
        }
        free(statuses_i);
    }
#endif
    for (int i = 0; i < (*outcount); i++) {
        array_of_indices[i] += 1;
    }
}


FORT_DLL_SPEC int FORT_CALL mpix_request_is_complete_(MPI_Fint *request) {
    return MPIX_Request_is_complete((MPI_Request) (*request));
}


FORT_DLL_SPEC void FORT_CALL mpi_accumulate_(void *origin_addr, MPI_Fint *origin_count, MPI_Fint *origin_datatype, MPI_Fint *target_rank, MPI_Aint *target_disp, MPI_Fint *target_count, MPI_Fint *target_datatype, MPI_Fint *op, MPI_Fint *win, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (origin_addr == MPIR_F_MPI_BOTTOM) {
        origin_addr = MPI_BOTTOM;
    }
    
    *ierr = MPI_Accumulate(origin_addr, (int) (*origin_count), (MPI_Datatype) (*origin_datatype), (int) (*target_rank), *target_disp, (int) (*target_count), (MPI_Datatype) (*target_datatype), (MPI_Op) (*op), (MPI_Win) (*win));
}


FORT_DLL_SPEC void FORT_CALL mpi_alloc_mem_(MPI_Aint *size, MPI_Fint *info, MPI_Aint *baseptr, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    void * baseptr_i;
    *ierr = MPI_Alloc_mem(*size, (MPI_Info) (*info), &baseptr_i);
    *baseptr = (MPI_Aint) baseptr_i;
}

FORT_DLL_SPEC void FORT_CALL mpi_alloc_mem_cptr_(MPI_Aint *size, MPI_Fint *info, void * *baseptr, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    void * baseptr_i;
    *ierr = MPI_Alloc_mem(*size, (MPI_Info) (*info), &baseptr_i);
    *baseptr = (void *) baseptr_i;
}


FORT_DLL_SPEC void FORT_CALL mpi_compare_and_swap_(void *origin_addr, void *compare_addr, void *result_addr, MPI_Fint *datatype, MPI_Fint *target_rank, MPI_Aint *target_disp, MPI_Fint *win, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (origin_addr == MPIR_F_MPI_BOTTOM) {
        origin_addr = MPI_BOTTOM;
    }
    
    if (compare_addr == MPIR_F_MPI_BOTTOM) {
        compare_addr = MPI_BOTTOM;
    }
    
    if (result_addr == MPIR_F_MPI_BOTTOM) {
        result_addr = MPI_BOTTOM;
    }
    
    *ierr = MPI_Compare_and_swap(origin_addr, compare_addr, result_addr, (MPI_Datatype) (*datatype), (int) (*target_rank), *target_disp, (MPI_Win) (*win));
}


FORT_DLL_SPEC void FORT_CALL mpi_fetch_and_op_(void *origin_addr, void *result_addr, MPI_Fint *datatype, MPI_Fint *target_rank, MPI_Aint *target_disp, MPI_Fint *op, MPI_Fint *win, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (origin_addr == MPIR_F_MPI_BOTTOM) {
        origin_addr = MPI_BOTTOM;
    }
    
    if (result_addr == MPIR_F_MPI_BOTTOM) {
        result_addr = MPI_BOTTOM;
    }
    
    *ierr = MPI_Fetch_and_op(origin_addr, result_addr, (MPI_Datatype) (*datatype), (int) (*target_rank), *target_disp, (MPI_Op) (*op), (MPI_Win) (*win));
}


FORT_DLL_SPEC void FORT_CALL mpi_free_mem_(void *base, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (base == MPIR_F_MPI_BOTTOM) {
        base = MPI_BOTTOM;
    }
    
    *ierr = MPI_Free_mem(base);
}


FORT_DLL_SPEC void FORT_CALL mpi_get_(void *origin_addr, MPI_Fint *origin_count, MPI_Fint *origin_datatype, MPI_Fint *target_rank, MPI_Aint *target_disp, MPI_Fint *target_count, MPI_Fint *target_datatype, MPI_Fint *win, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (origin_addr == MPIR_F_MPI_BOTTOM) {
        origin_addr = MPI_BOTTOM;
    }
    
    *ierr = MPI_Get(origin_addr, (int) (*origin_count), (MPI_Datatype) (*origin_datatype), (int) (*target_rank), *target_disp, (int) (*target_count), (MPI_Datatype) (*target_datatype), (MPI_Win) (*win));
}


FORT_DLL_SPEC void FORT_CALL mpi_get_accumulate_(void *origin_addr, MPI_Fint *origin_count, MPI_Fint *origin_datatype, void *result_addr, MPI_Fint *result_count, MPI_Fint *result_datatype, MPI_Fint *target_rank, MPI_Aint *target_disp, MPI_Fint *target_count, MPI_Fint *target_datatype, MPI_Fint *op, MPI_Fint *win, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (origin_addr == MPIR_F_MPI_BOTTOM) {
        origin_addr = MPI_BOTTOM;
    }
    
    if (result_addr == MPIR_F_MPI_BOTTOM) {
        result_addr = MPI_BOTTOM;
    }
    
    *ierr = MPI_Get_accumulate(origin_addr, (int) (*origin_count), (MPI_Datatype) (*origin_datatype), result_addr, (int) (*result_count), (MPI_Datatype) (*result_datatype), (int) (*target_rank), *target_disp, (int) (*target_count), (MPI_Datatype) (*target_datatype), (MPI_Op) (*op), (MPI_Win) (*win));
}


FORT_DLL_SPEC void FORT_CALL mpi_put_(void *origin_addr, MPI_Fint *origin_count, MPI_Fint *origin_datatype, MPI_Fint *target_rank, MPI_Aint *target_disp, MPI_Fint *target_count, MPI_Fint *target_datatype, MPI_Fint *win, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (origin_addr == MPIR_F_MPI_BOTTOM) {
        origin_addr = MPI_BOTTOM;
    }
    
    *ierr = MPI_Put(origin_addr, (int) (*origin_count), (MPI_Datatype) (*origin_datatype), (int) (*target_rank), *target_disp, (int) (*target_count), (MPI_Datatype) (*target_datatype), (MPI_Win) (*win));
}


FORT_DLL_SPEC void FORT_CALL mpi_raccumulate_(void *origin_addr, MPI_Fint *origin_count, MPI_Fint *origin_datatype, MPI_Fint *target_rank, MPI_Aint *target_disp, MPI_Fint *target_count, MPI_Fint *target_datatype, MPI_Fint *op, MPI_Fint *win, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (origin_addr == MPIR_F_MPI_BOTTOM) {
        origin_addr = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Raccumulate(origin_addr, (int) (*origin_count), (MPI_Datatype) (*origin_datatype), (int) (*target_rank), *target_disp, (int) (*target_count), (MPI_Datatype) (*target_datatype), (MPI_Op) (*op), (MPI_Win) (*win), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Raccumulate(origin_addr, (int) (*origin_count), (MPI_Datatype) (*origin_datatype), (int) (*target_rank), *target_disp, (int) (*target_count), (MPI_Datatype) (*target_datatype), (MPI_Op) (*op), (MPI_Win) (*win), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_rget_(void *origin_addr, MPI_Fint *origin_count, MPI_Fint *origin_datatype, MPI_Fint *target_rank, MPI_Aint *target_disp, MPI_Fint *target_count, MPI_Fint *target_datatype, MPI_Fint *win, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (origin_addr == MPIR_F_MPI_BOTTOM) {
        origin_addr = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Rget(origin_addr, (int) (*origin_count), (MPI_Datatype) (*origin_datatype), (int) (*target_rank), *target_disp, (int) (*target_count), (MPI_Datatype) (*target_datatype), (MPI_Win) (*win), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Rget(origin_addr, (int) (*origin_count), (MPI_Datatype) (*origin_datatype), (int) (*target_rank), *target_disp, (int) (*target_count), (MPI_Datatype) (*target_datatype), (MPI_Win) (*win), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_rget_accumulate_(void *origin_addr, MPI_Fint *origin_count, MPI_Fint *origin_datatype, void *result_addr, MPI_Fint *result_count, MPI_Fint *result_datatype, MPI_Fint *target_rank, MPI_Aint *target_disp, MPI_Fint *target_count, MPI_Fint *target_datatype, MPI_Fint *op, MPI_Fint *win, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (origin_addr == MPIR_F_MPI_BOTTOM) {
        origin_addr = MPI_BOTTOM;
    }
    
    if (result_addr == MPIR_F_MPI_BOTTOM) {
        result_addr = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Rget_accumulate(origin_addr, (int) (*origin_count), (MPI_Datatype) (*origin_datatype), result_addr, (int) (*result_count), (MPI_Datatype) (*result_datatype), (int) (*target_rank), *target_disp, (int) (*target_count), (MPI_Datatype) (*target_datatype), (MPI_Op) (*op), (MPI_Win) (*win), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Rget_accumulate(origin_addr, (int) (*origin_count), (MPI_Datatype) (*origin_datatype), result_addr, (int) (*result_count), (MPI_Datatype) (*result_datatype), (int) (*target_rank), *target_disp, (int) (*target_count), (MPI_Datatype) (*target_datatype), (MPI_Op) (*op), (MPI_Win) (*win), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_rput_(void *origin_addr, MPI_Fint *origin_count, MPI_Fint *origin_datatype, MPI_Fint *target_rank, MPI_Aint *target_disp, MPI_Fint *target_count, MPI_Fint *target_datatype, MPI_Fint *win, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (origin_addr == MPIR_F_MPI_BOTTOM) {
        origin_addr = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Rput(origin_addr, (int) (*origin_count), (MPI_Datatype) (*origin_datatype), (int) (*target_rank), *target_disp, (int) (*target_count), (MPI_Datatype) (*target_datatype), (MPI_Win) (*win), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_Rput(origin_addr, (int) (*origin_count), (MPI_Datatype) (*origin_datatype), (int) (*target_rank), *target_disp, (int) (*target_count), (MPI_Datatype) (*target_datatype), (MPI_Win) (*win), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_win_allocate_(MPI_Aint *size, MPI_Fint *disp_unit, MPI_Fint *info, MPI_Fint *comm, MPI_Aint *baseptr, MPI_Fint *win, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    void * baseptr_i;
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Win_allocate(*size, (int) (*disp_unit), (MPI_Info) (*info), (MPI_Comm) (*comm), &baseptr_i, (MPI_Win *) win);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Win win_i;
    *ierr = MPI_Win_allocate(*size, (int) (*disp_unit), (MPI_Info) (*info), (MPI_Comm) (*comm), &baseptr_i, &win_i);
    *win = (MPI_Fint) win_i;
#endif
    *baseptr = (MPI_Aint) baseptr_i;
}

FORT_DLL_SPEC void FORT_CALL mpi_win_allocate_cptr_(MPI_Aint *size, MPI_Fint *disp_unit, MPI_Fint *info, MPI_Fint *comm, void * *baseptr, MPI_Fint *win, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    void * baseptr_i;
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Win_allocate(*size, (int) (*disp_unit), (MPI_Info) (*info), (MPI_Comm) (*comm), &baseptr_i, (MPI_Win *) win);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Win win_i;
    *ierr = MPI_Win_allocate(*size, (int) (*disp_unit), (MPI_Info) (*info), (MPI_Comm) (*comm), &baseptr_i, &win_i);
    *win = (MPI_Fint) win_i;
#endif
    *baseptr = (void *) baseptr_i;
}


FORT_DLL_SPEC void FORT_CALL mpi_win_allocate_shared_(MPI_Aint *size, MPI_Fint *disp_unit, MPI_Fint *info, MPI_Fint *comm, MPI_Aint *baseptr, MPI_Fint *win, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    void * baseptr_i;
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Win_allocate_shared(*size, (int) (*disp_unit), (MPI_Info) (*info), (MPI_Comm) (*comm), &baseptr_i, (MPI_Win *) win);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Win win_i;
    *ierr = MPI_Win_allocate_shared(*size, (int) (*disp_unit), (MPI_Info) (*info), (MPI_Comm) (*comm), &baseptr_i, &win_i);
    *win = (MPI_Fint) win_i;
#endif
    *baseptr = (MPI_Aint) baseptr_i;
}

FORT_DLL_SPEC void FORT_CALL mpi_win_allocate_shared_cptr_(MPI_Aint *size, MPI_Fint *disp_unit, MPI_Fint *info, MPI_Fint *comm, void * *baseptr, MPI_Fint *win, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    void * baseptr_i;
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Win_allocate_shared(*size, (int) (*disp_unit), (MPI_Info) (*info), (MPI_Comm) (*comm), &baseptr_i, (MPI_Win *) win);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Win win_i;
    *ierr = MPI_Win_allocate_shared(*size, (int) (*disp_unit), (MPI_Info) (*info), (MPI_Comm) (*comm), &baseptr_i, &win_i);
    *win = (MPI_Fint) win_i;
#endif
    *baseptr = (void *) baseptr_i;
}


FORT_DLL_SPEC void FORT_CALL mpi_win_attach_(MPI_Fint *win, void *base, MPI_Aint *size, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (base == MPIR_F_MPI_BOTTOM) {
        base = MPI_BOTTOM;
    }
    
    *ierr = MPI_Win_attach((MPI_Win) (*win), base, *size);
}


FORT_DLL_SPEC void FORT_CALL mpi_win_complete_(MPI_Fint *win, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Win_complete((MPI_Win) (*win));
}


FORT_DLL_SPEC void FORT_CALL mpi_win_create_(void *base, MPI_Aint *size, MPI_Fint *disp_unit, MPI_Fint *info, MPI_Fint *comm, MPI_Fint *win, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (base == MPIR_F_MPI_BOTTOM) {
        base = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Win_create(base, *size, (int) (*disp_unit), (MPI_Info) (*info), (MPI_Comm) (*comm), (MPI_Win *) win);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Win win_i;
    *ierr = MPI_Win_create(base, *size, (int) (*disp_unit), (MPI_Info) (*info), (MPI_Comm) (*comm), &win_i);
    *win = (MPI_Fint) win_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_win_create_dynamic_(MPI_Fint *info, MPI_Fint *comm, MPI_Fint *win, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Win_create_dynamic((MPI_Info) (*info), (MPI_Comm) (*comm), (MPI_Win *) win);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Win win_i;
    *ierr = MPI_Win_create_dynamic((MPI_Info) (*info), (MPI_Comm) (*comm), &win_i);
    *win = (MPI_Fint) win_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_win_detach_(MPI_Fint *win, void *base, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (base == MPIR_F_MPI_BOTTOM) {
        base = MPI_BOTTOM;
    }
    
    *ierr = MPI_Win_detach((MPI_Win) (*win), base);
}


FORT_DLL_SPEC void FORT_CALL mpi_win_fence_(MPI_Fint *assert, MPI_Fint *win, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Win_fence((int) (*assert), (MPI_Win) (*win));
}


FORT_DLL_SPEC void FORT_CALL mpi_win_flush_(MPI_Fint *rank, MPI_Fint *win, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Win_flush((int) (*rank), (MPI_Win) (*win));
}


FORT_DLL_SPEC void FORT_CALL mpi_win_flush_all_(MPI_Fint *win, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Win_flush_all((MPI_Win) (*win));
}


FORT_DLL_SPEC void FORT_CALL mpi_win_flush_local_(MPI_Fint *rank, MPI_Fint *win, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Win_flush_local((int) (*rank), (MPI_Win) (*win));
}


FORT_DLL_SPEC void FORT_CALL mpi_win_flush_local_all_(MPI_Fint *win, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Win_flush_local_all((MPI_Win) (*win));
}


FORT_DLL_SPEC void FORT_CALL mpi_win_free_(MPI_Fint *win, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Win_free((MPI_Win *) win);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Win win_i;
    win_i = (MPI_Win) *win;
    *ierr = MPI_Win_free(&win_i);
    *win = (MPI_Fint) win_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_win_get_group_(MPI_Fint *win, MPI_Fint *group, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Win_get_group((MPI_Win) (*win), (MPI_Group *) group);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Group group_i;
    *ierr = MPI_Win_get_group((MPI_Win) (*win), &group_i);
    *group = (MPI_Fint) group_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_win_get_info_(MPI_Fint *win, MPI_Fint *info_used, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Win_get_info((MPI_Win) (*win), (MPI_Info *) info_used);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Info info_used_i;
    *ierr = MPI_Win_get_info((MPI_Win) (*win), &info_used_i);
    *info_used = (MPI_Fint) info_used_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_win_get_name_(MPI_Fint *win, char *win_name FORT_MIXED_LEN(win_name_len), MPI_Fint *resultlen, MPI_Fint *ierr FORT_END_LEN(win_name_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *win_name_i = malloc(win_name_len + 1);
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Win_get_name((MPI_Win) (*win), win_name_i, (int *) resultlen);
    
#else  /* ! HAVE_FINT_IS_INT */
    int resultlen_i;
    *ierr = MPI_Win_get_name((MPI_Win) (*win), win_name_i, &resultlen_i);
    *resultlen = (MPI_Fint) resultlen_i;
#endif
    if (*ierr == MPI_SUCCESS) {
        MPIR_fort_copy_str_from_c(win_name, win_name_len, win_name_i);
    }
    free(win_name_i);
}


FORT_DLL_SPEC void FORT_CALL mpi_win_lock_(MPI_Fint *lock_type, MPI_Fint *rank, MPI_Fint *assert, MPI_Fint *win, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Win_lock((int) (*lock_type), (int) (*rank), (int) (*assert), (MPI_Win) (*win));
}


FORT_DLL_SPEC void FORT_CALL mpi_win_lock_all_(MPI_Fint *assert, MPI_Fint *win, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Win_lock_all((int) (*assert), (MPI_Win) (*win));
}


FORT_DLL_SPEC void FORT_CALL mpi_win_post_(MPI_Fint *group, MPI_Fint *assert, MPI_Fint *win, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Win_post((MPI_Group) (*group), (int) (*assert), (MPI_Win) (*win));
}


FORT_DLL_SPEC void FORT_CALL mpi_win_set_info_(MPI_Fint *win, MPI_Fint *info, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Win_set_info((MPI_Win) (*win), (MPI_Info) (*info));
}


FORT_DLL_SPEC void FORT_CALL mpi_win_set_name_(MPI_Fint *win, char *win_name FORT_MIXED_LEN(win_name_len), MPI_Fint *ierr FORT_END_LEN(win_name_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *win_name_i = MPIR_fort_dup_str(win_name, win_name_len);
    *ierr = MPI_Win_set_name((MPI_Win) (*win), win_name_i);
    free(win_name_i);
}


FORT_DLL_SPEC void FORT_CALL mpi_win_shared_query_(MPI_Fint *win, MPI_Fint *rank, MPI_Aint *size, MPI_Fint *disp_unit, MPI_Aint *baseptr, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    void * baseptr_i;
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Win_shared_query((MPI_Win) (*win), (int) (*rank), size, (int *) disp_unit, &baseptr_i);
    
#else  /* ! HAVE_FINT_IS_INT */
    int disp_unit_i;
    *ierr = MPI_Win_shared_query((MPI_Win) (*win), (int) (*rank), size, &disp_unit_i, &baseptr_i);
    *disp_unit = (MPI_Fint) disp_unit_i;
#endif
    *baseptr = (MPI_Aint) baseptr_i;
}

FORT_DLL_SPEC void FORT_CALL mpi_win_shared_query_cptr_(MPI_Fint *win, MPI_Fint *rank, MPI_Aint *size, MPI_Fint *disp_unit, void * *baseptr, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    void * baseptr_i;
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Win_shared_query((MPI_Win) (*win), (int) (*rank), size, (int *) disp_unit, &baseptr_i);
    
#else  /* ! HAVE_FINT_IS_INT */
    int disp_unit_i;
    *ierr = MPI_Win_shared_query((MPI_Win) (*win), (int) (*rank), size, &disp_unit_i, &baseptr_i);
    *disp_unit = (MPI_Fint) disp_unit_i;
#endif
    *baseptr = (void *) baseptr_i;
}


FORT_DLL_SPEC void FORT_CALL mpi_win_start_(MPI_Fint *group, MPI_Fint *assert, MPI_Fint *win, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Win_start((MPI_Group) (*group), (int) (*assert), (MPI_Win) (*win));
}


FORT_DLL_SPEC void FORT_CALL mpi_win_sync_(MPI_Fint *win, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Win_sync((MPI_Win) (*win));
}


FORT_DLL_SPEC void FORT_CALL mpi_win_test_(MPI_Fint *win, MPI_Fint *flag, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    int flag_i;
    *ierr = MPI_Win_test((MPI_Win) (*win), &flag_i);
    if (*ierr == MPI_SUCCESS) {
        *flag = MPII_TO_FLOG(flag_i);
    }
}


FORT_DLL_SPEC void FORT_CALL mpi_win_unlock_(MPI_Fint *rank, MPI_Fint *win, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Win_unlock((int) (*rank), (MPI_Win) (*win));
}


FORT_DLL_SPEC void FORT_CALL mpi_win_unlock_all_(MPI_Fint *win, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Win_unlock_all((MPI_Win) (*win));
}


FORT_DLL_SPEC void FORT_CALL mpi_win_wait_(MPI_Fint *win, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_Win_wait((MPI_Win) (*win));
}


FORT_DLL_SPEC void FORT_CALL mpi_close_port_(char *port_name FORT_MIXED_LEN(port_name_len), MPI_Fint *ierr FORT_END_LEN(port_name_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *port_name_i = MPIR_fort_dup_str(port_name, port_name_len);
    *ierr = MPI_Close_port(port_name_i);
    free(port_name_i);
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_accept_(char *port_name FORT_MIXED_LEN(port_name_len), MPI_Fint *info, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr FORT_END_LEN(port_name_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *port_name_i = MPIR_fort_dup_str(port_name, port_name_len);
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Comm_accept(port_name_i, (MPI_Info) (*info), (int) (*root), (MPI_Comm) (*comm), (MPI_Comm *) newcomm);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Comm newcomm_i;
    *ierr = MPI_Comm_accept(port_name_i, (MPI_Info) (*info), (int) (*root), (MPI_Comm) (*comm), &newcomm_i);
    *newcomm = (MPI_Fint) newcomm_i;
#endif
    free(port_name_i);
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_connect_(char *port_name FORT_MIXED_LEN(port_name_len), MPI_Fint *info, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *newcomm, MPI_Fint *ierr FORT_END_LEN(port_name_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *port_name_i = MPIR_fort_dup_str(port_name, port_name_len);
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Comm_connect(port_name_i, (MPI_Info) (*info), (int) (*root), (MPI_Comm) (*comm), (MPI_Comm *) newcomm);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Comm newcomm_i;
    *ierr = MPI_Comm_connect(port_name_i, (MPI_Info) (*info), (int) (*root), (MPI_Comm) (*comm), &newcomm_i);
    *newcomm = (MPI_Fint) newcomm_i;
#endif
    free(port_name_i);
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_disconnect_(MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Comm_disconnect((MPI_Comm *) comm);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Comm comm_i;
    comm_i = (MPI_Comm) *comm;
    *ierr = MPI_Comm_disconnect(&comm_i);
    *comm = (MPI_Fint) comm_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_get_parent_(MPI_Fint *parent, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Comm_get_parent((MPI_Comm *) parent);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Comm parent_i;
    *ierr = MPI_Comm_get_parent(&parent_i);
    *parent = (MPI_Fint) parent_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_join_(MPI_Fint *fd, MPI_Fint *intercomm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Comm_join((int) (*fd), (MPI_Comm *) intercomm);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Comm intercomm_i;
    *ierr = MPI_Comm_join((int) (*fd), &intercomm_i);
    *intercomm = (MPI_Fint) intercomm_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_spawn_(char *command FORT_MIXED_LEN(command_len), char *argv FORT_MIXED_LEN(argv_len), MPI_Fint *maxprocs, MPI_Fint *info, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *intercomm, MPI_Fint *array_of_errcodes, MPI_Fint *ierr FORT_END_LEN(command_len) FORT_END_LEN(argv_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *command_i = MPIR_fort_dup_str(command, command_len);
    char **argv_i;
    if (argv == MPI_F_ARGV_NULL) {
        argv_i = MPI_ARGV_NULL;
    } else {
        argv_i = MPIR_fort_dup_str_array(argv, argv_len, argv_len, 0);
    }
#ifdef HAVE_FINT_IS_INT
    if (array_of_errcodes == MPI_F_ERRCODES_IGNORE) {
        array_of_errcodes = (MPI_Fint *) MPI_ERRCODES_IGNORE;
    }
    *ierr = MPI_Comm_spawn(command_i, argv_i, (int) (*maxprocs), (MPI_Info) (*info), (int) (*root), (MPI_Comm) (*comm), (MPI_Comm *) intercomm, (int *) array_of_errcodes);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Comm intercomm_i;
    int *array_of_errcodes_i;
    int array_of_errcodes_is_special = 0;
    if (array_of_errcodes == MPI_F_ERRCODES_IGNORE) {
        array_of_errcodes_i = MPI_ERRCODES_IGNORE;
        array_of_errcodes_is_special = 1;
    }
    if (!array_of_errcodes_is_special) {
        array_of_errcodes_i = malloc(sizeof(int) * (*maxprocs));
    }
    *ierr = MPI_Comm_spawn(command_i, argv_i, (int) (*maxprocs), (MPI_Info) (*info), (int) (*root), (MPI_Comm) (*comm), &intercomm_i, array_of_errcodes_i);
    *intercomm = (MPI_Fint) intercomm_i;
    if (!array_of_errcodes_is_special) {
        for (int i = 0; i < (*maxprocs); i++) {
            array_of_errcodes[i] = (MPI_Fint) array_of_errcodes_i[i];
        }
        free(array_of_errcodes_i);
    }
#endif
    free(command_i);
    if (argv != MPI_F_ARGV_NULL) {
        MPIR_fort_free_str_array(argv_i);
    }
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_spawn_multiple_(MPI_Fint *count, char *array_of_commands FORT_MIXED_LEN(array_of_commands_len), char *array_of_argv FORT_MIXED_LEN(array_of_argv_len), MPI_Fint *array_of_maxprocs, MPI_Fint *array_of_info, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *intercomm, MPI_Fint *array_of_errcodes, MPI_Fint *ierr FORT_END_LEN(array_of_commands_len) FORT_END_LEN(array_of_argv_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char **array_of_commands_i;
    if (array_of_commands == MPI_F_ARGV_NULL) {
        array_of_commands_i = MPI_ARGV_NULL;
    } else {
        array_of_commands_i = MPIR_fort_dup_str_array(array_of_commands, array_of_commands_len, array_of_commands_len, *count);
    }
    char ***array_of_argv_i;
    if (array_of_argv == MPI_F_ARGVS_NULL) {
        array_of_argv_i = MPI_ARGVS_NULL;
    } else {
        array_of_argv_i = MPIR_fort_dup_str_2d_array(array_of_argv, array_of_argv_len, *count);
    }
#ifdef HAVE_FINT_IS_INT
    if (array_of_errcodes == MPI_F_ERRCODES_IGNORE) {
        array_of_errcodes = (MPI_Fint *) MPI_ERRCODES_IGNORE;
    }
    *ierr = MPI_Comm_spawn_multiple((int) (*count), array_of_commands_i, array_of_argv_i, (int *) array_of_maxprocs, (int *) array_of_info, (int) (*root), (MPI_Comm) (*comm), (MPI_Comm *) intercomm, (int *) array_of_errcodes);
    
#else  /* ! HAVE_FINT_IS_INT */
    int total_procs = 0;
    for (int i = 0; i < *count; i++) {
        total_procs += (int) array_of_maxprocs[i];
    }
    int *array_of_maxprocs_i;
    array_of_maxprocs_i = malloc(sizeof(int) * (*count));
    for (int i = 0; i < (*count); i++) {
        array_of_maxprocs_i[i] = (int) array_of_maxprocs[i];
    }
    MPI_Info *array_of_info_i;
    array_of_info_i = malloc(sizeof(MPI_Info) * (*count));
    for (int i = 0; i < (*count); i++) {
        array_of_info_i[i] = (MPI_Info) array_of_info[i];
    }
    MPI_Comm intercomm_i;
    int *array_of_errcodes_i;
    int array_of_errcodes_is_special = 0;
    if (array_of_errcodes == MPI_F_ERRCODES_IGNORE) {
        array_of_errcodes_i = MPI_ERRCODES_IGNORE;
        array_of_errcodes_is_special = 1;
    }
    if (!array_of_errcodes_is_special) {
        array_of_errcodes_i = malloc(sizeof(int) * total_procs);
    }
    *ierr = MPI_Comm_spawn_multiple((int) (*count), array_of_commands_i, array_of_argv_i, array_of_maxprocs_i, array_of_info_i, (int) (*root), (MPI_Comm) (*comm), &intercomm_i, array_of_errcodes_i);
    free(array_of_maxprocs_i);
    free(array_of_info_i);
    *intercomm = (MPI_Fint) intercomm_i;
    if (!array_of_errcodes_is_special) {
        for (int i = 0; i < total_procs; i++) {
            array_of_errcodes[i] = (MPI_Fint) array_of_errcodes_i[i];
        }
        free(array_of_errcodes_i);
    }
#endif
    if (array_of_commands != MPI_F_ARGV_NULL) {
        MPIR_fort_free_str_array(array_of_commands_i);
    }
    if (array_of_argv != MPI_F_ARGVS_NULL) {
        MPIR_fort_free_str_2d_array(array_of_argv_i, *count);
    }
}


FORT_DLL_SPEC void FORT_CALL mpi_lookup_name_(char *service_name FORT_MIXED_LEN(service_name_len), MPI_Fint *info, char *port_name FORT_MIXED_LEN(port_name_len), MPI_Fint *ierr FORT_END_LEN(service_name_len) FORT_END_LEN(port_name_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *service_name_i = MPIR_fort_dup_str(service_name, service_name_len);
    char *port_name_i = malloc(port_name_len + 1);
    *ierr = MPI_Lookup_name(service_name_i, (MPI_Info) (*info), port_name_i);
    free(service_name_i);
    if (*ierr == MPI_SUCCESS) {
        MPIR_fort_copy_str_from_c(port_name, port_name_len, port_name_i);
    }
    free(port_name_i);
}


FORT_DLL_SPEC void FORT_CALL mpi_open_port_(MPI_Fint *info, char *port_name FORT_MIXED_LEN(port_name_len), MPI_Fint *ierr FORT_END_LEN(port_name_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *port_name_i = malloc(port_name_len + 1);
    *ierr = MPI_Open_port((MPI_Info) (*info), port_name_i);
    if (*ierr == MPI_SUCCESS) {
        MPIR_fort_copy_str_from_c(port_name, port_name_len, port_name_i);
    }
    free(port_name_i);
}


FORT_DLL_SPEC void FORT_CALL mpi_publish_name_(char *service_name FORT_MIXED_LEN(service_name_len), MPI_Fint *info, char *port_name FORT_MIXED_LEN(port_name_len), MPI_Fint *ierr FORT_END_LEN(service_name_len) FORT_END_LEN(port_name_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *service_name_i = MPIR_fort_dup_str(service_name, service_name_len);
    char *port_name_i = MPIR_fort_dup_str(port_name, port_name_len);
    *ierr = MPI_Publish_name(service_name_i, (MPI_Info) (*info), port_name_i);
    free(service_name_i);
    free(port_name_i);
}


FORT_DLL_SPEC void FORT_CALL mpi_unpublish_name_(char *service_name FORT_MIXED_LEN(service_name_len), MPI_Fint *info, char *port_name FORT_MIXED_LEN(port_name_len), MPI_Fint *ierr FORT_END_LEN(service_name_len) FORT_END_LEN(port_name_len)) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *service_name_i = MPIR_fort_dup_str(service_name, service_name_len);
    char *port_name_i = MPIR_fort_dup_str(port_name, port_name_len);
    *ierr = MPI_Unpublish_name(service_name_i, (MPI_Info) (*info), port_name_i);
    free(service_name_i);
    free(port_name_i);
}


FORT_DLL_SPEC void FORT_CALL mpix_stream_create_(MPI_Fint *info, MPI_Fint *stream, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPIX_Stream_create((MPI_Info) (*info), (MPIX_Stream *) stream);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPIX_Stream stream_i;
    *ierr = MPIX_Stream_create((MPI_Info) (*info), &stream_i);
    *stream = (MPI_Fint) stream_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpix_stream_free_(MPI_Fint *stream, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPIX_Stream_free((MPIX_Stream *) stream);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPIX_Stream stream_i;
    stream_i = (MPIX_Stream) *stream;
    *ierr = MPIX_Stream_free(&stream_i);
    *stream = (MPI_Fint) stream_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpix_stream_comm_create_(MPI_Fint *comm, MPI_Fint *stream, MPI_Fint *newcomm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPIX_Stream_comm_create((MPI_Comm) (*comm), (MPIX_Stream) (*stream), (MPI_Comm *) newcomm);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Comm newcomm_i;
    *ierr = MPIX_Stream_comm_create((MPI_Comm) (*comm), (MPIX_Stream) (*stream), &newcomm_i);
    *newcomm = (MPI_Fint) newcomm_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpix_stream_comm_create_multiplex_(MPI_Fint *comm, MPI_Fint *count, MPI_Fint *array_of_streams, MPI_Fint *newcomm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPIX_Stream_comm_create_multiplex((MPI_Comm) (*comm), (int) (*count), (int *) array_of_streams, (MPI_Comm *) newcomm);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPIX_Stream *array_of_streams_i;
    array_of_streams_i = malloc(sizeof(MPIX_Stream) * (*count));
    for (int i = 0; i < (*count); i++) {
        array_of_streams_i[i] = (MPIX_Stream) array_of_streams[i];
    }
    MPI_Comm newcomm_i;
    *ierr = MPIX_Stream_comm_create_multiplex((MPI_Comm) (*comm), (int) (*count), array_of_streams_i, &newcomm_i);
    free(array_of_streams_i);
    *newcomm = (MPI_Fint) newcomm_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpix_comm_get_stream_(MPI_Fint *comm, MPI_Fint *idx, MPI_Fint *stream, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPIX_Comm_get_stream((MPI_Comm) (*comm), (int) (*idx - 1), (MPIX_Stream *) stream);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPIX_Stream stream_i;
    *ierr = MPIX_Comm_get_stream((MPI_Comm) (*comm), (int) (*idx - 1), &stream_i);
    *stream = (MPI_Fint) stream_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpix_stream_progress_(MPI_Fint *stream, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPIX_Stream_progress((MPIX_Stream) (*stream));
}


FORT_DLL_SPEC void FORT_CALL mpix_start_progress_thread_(MPI_Fint *stream, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPIX_Start_progress_thread((MPIX_Stream) (*stream));
}


FORT_DLL_SPEC void FORT_CALL mpix_stop_progress_thread_(MPI_Fint *stream, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPIX_Stop_progress_thread((MPIX_Stream) (*stream));
}


FORT_DLL_SPEC void FORT_CALL mpix_stream_send_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *source_stream_index, MPI_Fint *dest_stream_index, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
    *ierr = MPIX_Stream_send(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*tag), (MPI_Comm) (*comm), (int) (*source_stream_index - 1), (int) (*dest_stream_index - 1));
}


FORT_DLL_SPEC void FORT_CALL mpix_stream_isend_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *source_stream_index, MPI_Fint *dest_stream_index, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPIX_Stream_isend(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*tag), (MPI_Comm) (*comm), (int) (*source_stream_index - 1), (int) (*dest_stream_index - 1), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPIX_Stream_isend(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*tag), (MPI_Comm) (*comm), (int) (*source_stream_index - 1), (int) (*dest_stream_index - 1), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpix_stream_recv_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *source_stream_index, MPI_Fint *dest_stream_index, MPI_Fint *status, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPIX_Stream_recv(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*source), (int) (*tag), (MPI_Comm) (*comm), (int) (*source_stream_index - 1), (int) (*dest_stream_index - 1), (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPIX_Stream_recv(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*source), (int) (*tag), (MPI_Comm) (*comm), (int) (*source_stream_index - 1), (int) (*dest_stream_index - 1), status_arg);
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
}


FORT_DLL_SPEC void FORT_CALL mpix_stream_irecv_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *source_stream_index, MPI_Fint *dest_stream_index, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPIX_Stream_irecv(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*source), (int) (*tag), (MPI_Comm) (*comm), (int) (*source_stream_index - 1), (int) (*dest_stream_index - 1), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPIX_Stream_irecv(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*source), (int) (*tag), (MPI_Comm) (*comm), (int) (*source_stream_index - 1), (int) (*dest_stream_index - 1), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpix_send_enqueue_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
    *ierr = MPIX_Send_enqueue(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*tag), (MPI_Comm) (*comm));
}


FORT_DLL_SPEC void FORT_CALL mpix_recv_enqueue_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPIX_Recv_enqueue(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*source), (int) (*tag), (MPI_Comm) (*comm), (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPIX_Recv_enqueue(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*source), (int) (*tag), (MPI_Comm) (*comm), status_arg);
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
}


FORT_DLL_SPEC void FORT_CALL mpix_isend_enqueue_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPIX_Isend_enqueue(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*tag), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPIX_Isend_enqueue(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*dest), (int) (*tag), (MPI_Comm) (*comm), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpix_irecv_enqueue_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPIX_Irecv_enqueue(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*source), (int) (*tag), (MPI_Comm) (*comm), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPIX_Irecv_enqueue(buf, (int) (*count), (MPI_Datatype) (*datatype), (int) (*source), (int) (*tag), (MPI_Comm) (*comm), &request_i);
    *request = (MPI_Fint) request_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpix_wait_enqueue_(MPI_Fint *request, MPI_Fint *status, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPIX_Wait_enqueue((MPI_Request *) request, (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    request_i = (MPI_Request) *request;
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPIX_Wait_enqueue(&request_i, status_arg);
    *request = (MPI_Fint) request_i;
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
}


FORT_DLL_SPEC void FORT_CALL mpix_waitall_enqueue_(MPI_Fint *count, MPI_Fint *array_of_requests, MPI_Fint *array_of_statuses, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    if (array_of_statuses == MPI_F_STATUSES_IGNORE) {
        array_of_statuses = (MPI_Fint *) MPI_STATUSES_IGNORE;
    }
    *ierr = MPIX_Waitall_enqueue((int) (*count), (int *) array_of_requests, (MPI_Status *) array_of_statuses);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request *array_of_requests_i;
    array_of_requests_i = malloc(sizeof(MPI_Request) * (*count));
    for (int i = 0; i < (*count); i++) {
        array_of_requests_i[i] = (MPI_Request) array_of_requests[i];
    }
    MPI_Status *statuses_i;
    if (array_of_statuses == MPI_F_STATUSES_IGNORE) {
        statuses_i = MPI_STATUS_IGNORE;
    } else {
        statuses_i = malloc((*count) * sizeof(MPI_Status));
        int *p = (int *) statuses_i;
        for (int i = 0; i < (*count) * MPI_F_STATUS_SIZE; i++) {
            p[i] = (int) array_of_statuses[i];
        }
    }
    *ierr = MPIX_Waitall_enqueue((int) (*count), array_of_requests_i, statuses_i);
    for (int i = 0; i < (*count); i++) {
        array_of_requests[i] = (MPI_Fint) array_of_requests_i[i];
    }
    free(array_of_requests_i);
    if (array_of_statuses != MPI_F_STATUSES_IGNORE) {
        int *p = (int *) statuses_i;
        for (int i = 0; i < (*count) * MPI_F_STATUS_SIZE; i++) {
            array_of_statuses[i] = (MPI_Fint) p[i];
        }
        free(statuses_i);
    }
#endif
}


FORT_DLL_SPEC void FORT_CALL mpix_allreduce_enqueue_(void *sendbuf, void *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (sendbuf == MPIR_F_MPI_BOTTOM) {
        sendbuf = MPI_BOTTOM;
    }
    
    if (recvbuf == MPIR_F_MPI_BOTTOM) {
        recvbuf = MPI_BOTTOM;
    }
    
    *ierr = MPIX_Allreduce_enqueue(sendbuf, recvbuf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Op) (*op), (MPI_Comm) (*comm));
}


FORT_DLL_SPEC void FORT_CALL mpix_threadcomm_init_(MPI_Fint *comm, MPI_Fint *num_threads, MPI_Fint *newthreadcomm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPIX_Threadcomm_init((MPI_Comm) (*comm), (int) (*num_threads), (MPI_Comm *) newthreadcomm);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Comm newthreadcomm_i;
    *ierr = MPIX_Threadcomm_init((MPI_Comm) (*comm), (int) (*num_threads), &newthreadcomm_i);
    *newthreadcomm = (MPI_Fint) newthreadcomm_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpix_threadcomm_free_(MPI_Fint *threadcomm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPIX_Threadcomm_free((MPI_Comm *) threadcomm);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Comm threadcomm_i;
    threadcomm_i = (MPI_Comm) *threadcomm;
    *ierr = MPIX_Threadcomm_free(&threadcomm_i);
    *threadcomm = (MPI_Fint) threadcomm_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpix_threadcomm_start_(MPI_Fint *threadcomm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPIX_Threadcomm_start((MPI_Comm) (*threadcomm));
}


FORT_DLL_SPEC void FORT_CALL mpix_threadcomm_finish_(MPI_Fint *threadcomm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPIX_Threadcomm_finish((MPI_Comm) (*threadcomm));
}


FORT_DLL_SPEC double FORT_CALL mpi_wtick_(void) {
    return MPI_Wtick();
}


FORT_DLL_SPEC double FORT_CALL mpi_wtime_(void) {
    return MPI_Wtime();
}


FORT_DLL_SPEC void FORT_CALL mpi_cart_coords_(MPI_Fint *comm, MPI_Fint *rank, MPI_Fint *maxdims, MPI_Fint *coords, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Cart_coords((MPI_Comm) (*comm), (int) (*rank), (int) (*maxdims), (int *) coords);
    
#else  /* ! HAVE_FINT_IS_INT */
    int *coords_i;
    coords_i = malloc(sizeof(int) * (*maxdims));
    *ierr = MPI_Cart_coords((MPI_Comm) (*comm), (int) (*rank), (int) (*maxdims), coords_i);
    for (int i = 0; i < (*maxdims); i++) {
        coords[i] = (MPI_Fint) coords_i[i];
    }
    free(coords_i);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_cart_create_(MPI_Fint *comm_old, MPI_Fint *ndims, MPI_Fint *dims, MPI_Fint *periods, MPI_Fint *reorder, MPI_Fint *comm_cart, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Cart_create((MPI_Comm) (*comm_old), (int) (*ndims), (int *) dims, (int *) periods, *reorder, (MPI_Comm *) comm_cart);
    
#else  /* ! HAVE_FINT_IS_INT */
    int *dims_i;
    dims_i = malloc(sizeof(int) * (*ndims));
    for (int i = 0; i < (*ndims); i++) {
        dims_i[i] = (int) dims[i];
    }
    int *periods_i;
    periods_i = malloc(sizeof(int) * (*ndims));
    for (int i = 0; i < (*ndims); i++) {
        periods_i[i] = (int) periods[i];
    }
    MPI_Comm comm_cart_i;
    *ierr = MPI_Cart_create((MPI_Comm) (*comm_old), (int) (*ndims), dims_i, periods_i, *reorder, &comm_cart_i);
    free(dims_i);
    free(periods_i);
    *comm_cart = (MPI_Fint) comm_cart_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_cart_get_(MPI_Fint *comm, MPI_Fint *maxdims, MPI_Fint *dims, MPI_Fint *periods, MPI_Fint *coords, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Cart_get((MPI_Comm) (*comm), (int) (*maxdims), (int *) dims, (int *) periods, (int *) coords);
    
#else  /* ! HAVE_FINT_IS_INT */
    int *dims_i;
    dims_i = malloc(sizeof(int) * (*maxdims));
    int *periods_i;
    periods_i = malloc(sizeof(int) * (*maxdims));
    int *coords_i;
    coords_i = malloc(sizeof(int) * (*maxdims));
    *ierr = MPI_Cart_get((MPI_Comm) (*comm), (int) (*maxdims), dims_i, periods_i, coords_i);
    for (int i = 0; i < (*maxdims); i++) {
        dims[i] = (MPI_Fint) dims_i[i];
    }
    free(dims_i);
    for (int i = 0; i < (*maxdims); i++) {
        periods[i] = MPII_TO_FLOG(periods_i[i]);
    }
    free(periods_i);
    for (int i = 0; i < (*maxdims); i++) {
        coords[i] = (MPI_Fint) coords_i[i];
    }
    free(coords_i);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_cart_map_(MPI_Fint *comm, MPI_Fint *ndims, MPI_Fint *dims, MPI_Fint *periods, MPI_Fint *newrank, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Cart_map((MPI_Comm) (*comm), (int) (*ndims), (int *) dims, (int *) periods, (int *) newrank);
    
#else  /* ! HAVE_FINT_IS_INT */
    int *dims_i;
    dims_i = malloc(sizeof(int) * (*ndims));
    for (int i = 0; i < (*ndims); i++) {
        dims_i[i] = (int) dims[i];
    }
    int *periods_i;
    periods_i = malloc(sizeof(int) * (*ndims));
    for (int i = 0; i < (*ndims); i++) {
        periods_i[i] = (int) periods[i];
    }
    int newrank_i;
    *ierr = MPI_Cart_map((MPI_Comm) (*comm), (int) (*ndims), dims_i, periods_i, &newrank_i);
    free(dims_i);
    free(periods_i);
    *newrank = (MPI_Fint) newrank_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_cart_rank_(MPI_Fint *comm, MPI_Fint *coords, MPI_Fint *rank, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Cart_rank((MPI_Comm) (*comm), (int *) coords, (int *) rank);
    
#else  /* ! HAVE_FINT_IS_INT */
    int maxdims;
    MPI_Cartdim_get((MPI_Comm) (*comm), &maxdims);
    int *coords_i;
    coords_i = malloc(sizeof(int) * maxdims);
    for (int i = 0; i < maxdims; i++) {
        coords_i[i] = (int) coords[i];
    }
    int rank_i;
    *ierr = MPI_Cart_rank((MPI_Comm) (*comm), coords_i, &rank_i);
    free(coords_i);
    *rank = (MPI_Fint) rank_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_cart_shift_(MPI_Fint *comm, MPI_Fint *direction, MPI_Fint *disp, MPI_Fint *rank_source, MPI_Fint *rank_dest, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Cart_shift((MPI_Comm) (*comm), (int) (*direction), (int) (*disp), (int *) rank_source, (int *) rank_dest);
    
#else  /* ! HAVE_FINT_IS_INT */
    int rank_source_i;
    int rank_dest_i;
    *ierr = MPI_Cart_shift((MPI_Comm) (*comm), (int) (*direction), (int) (*disp), &rank_source_i, &rank_dest_i);
    *rank_source = (MPI_Fint) rank_source_i;
    *rank_dest = (MPI_Fint) rank_dest_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_cart_sub_(MPI_Fint *comm, MPI_Fint *remain_dims, MPI_Fint *newcomm, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Cart_sub((MPI_Comm) (*comm), (int *) remain_dims, (MPI_Comm *) newcomm);
    
#else  /* ! HAVE_FINT_IS_INT */
    int maxdims;
    MPI_Cartdim_get((MPI_Comm) (*comm), &maxdims);
    int *remain_dims_i;
    remain_dims_i = malloc(sizeof(int) * maxdims);
    for (int i = 0; i < maxdims; i++) {
        remain_dims_i[i] = (int) remain_dims[i];
    }
    MPI_Comm newcomm_i;
    *ierr = MPI_Cart_sub((MPI_Comm) (*comm), remain_dims_i, &newcomm_i);
    free(remain_dims_i);
    *newcomm = (MPI_Fint) newcomm_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_cartdim_get_(MPI_Fint *comm, MPI_Fint *ndims, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Cartdim_get((MPI_Comm) (*comm), (int *) ndims);
    
#else  /* ! HAVE_FINT_IS_INT */
    int ndims_i;
    *ierr = MPI_Cartdim_get((MPI_Comm) (*comm), &ndims_i);
    *ndims = (MPI_Fint) ndims_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_dims_create_(MPI_Fint *nnodes, MPI_Fint *ndims, MPI_Fint *dims, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Dims_create((int) (*nnodes), (int) (*ndims), (int *) dims);
    
#else  /* ! HAVE_FINT_IS_INT */
    int *dims_i;
    dims_i = malloc(sizeof(int) * (*ndims));
    for (int i = 0; i < (*ndims); i++) {
        dims_i[i] = (int) dims[i];
    }
    *ierr = MPI_Dims_create((int) (*nnodes), (int) (*ndims), dims_i);
    for (int i = 0; i < (*ndims); i++) {
        dims[i] = (MPI_Fint) dims_i[i];
    }
    free(dims_i);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_dist_graph_create_(MPI_Fint *comm_old, MPI_Fint *n, MPI_Fint *sources, MPI_Fint *degrees, MPI_Fint *destinations, MPI_Fint *weights, MPI_Fint *info, MPI_Fint *reorder, MPI_Fint *comm_dist_graph, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    if (weights == MPIR_F_MPI_UNWEIGHTED) {
        weights = (MPI_Fint *) MPI_UNWEIGHTED;
    } else if (weights == MPIR_F_MPI_WEIGHTS_EMPTY) {
        weights = (MPI_Fint *) MPI_WEIGHTS_EMPTY;
    }
    *ierr = MPI_Dist_graph_create((MPI_Comm) (*comm_old), (int) (*n), (int *) sources, (int *) degrees, (int *) destinations, (int *) weights, (MPI_Info) (*info), *reorder, (MPI_Comm *) comm_dist_graph);
    
#else  /* ! HAVE_FINT_IS_INT */
    int total_degrees = 0;
    for (int i = 0; i < *n; i++) {
        total_degrees += (int) degrees[i];
    }
    int *sources_i;
    sources_i = malloc(sizeof(int) * (*n));
    for (int i = 0; i < (*n); i++) {
        sources_i[i] = (int) sources[i];
    }
    int *degrees_i;
    degrees_i = malloc(sizeof(int) * (*n));
    for (int i = 0; i < (*n); i++) {
        degrees_i[i] = (int) degrees[i];
    }
    int *destinations_i;
    destinations_i = malloc(sizeof(int) * total_degrees);
    for (int i = 0; i < total_degrees; i++) {
        destinations_i[i] = (int) destinations[i];
    }
    int *weights_i;
    int weights_is_special = 0;
    if (weights == MPIR_F_MPI_UNWEIGHTED) {
        weights_i = MPI_UNWEIGHTED;
        weights_is_special = 1;
    } else if (weights == MPIR_F_MPI_WEIGHTS_EMPTY) {
        weights_i = MPI_WEIGHTS_EMPTY;
        weights_is_special = 1;
    }
    if (!weights_is_special) {
        weights_i = malloc(sizeof(int) * total_degrees);
        for (int i = 0; i < total_degrees; i++) {
            weights_i[i] = (int) weights[i];
        }
    }
    MPI_Comm comm_dist_graph_i;
    *ierr = MPI_Dist_graph_create((MPI_Comm) (*comm_old), (int) (*n), sources_i, degrees_i, destinations_i, weights_i, (MPI_Info) (*info), *reorder, &comm_dist_graph_i);
    free(sources_i);
    free(degrees_i);
    free(destinations_i);
    if (!weights_is_special) {
        free(weights_i);
    }
    *comm_dist_graph = (MPI_Fint) comm_dist_graph_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_dist_graph_create_adjacent_(MPI_Fint *comm_old, MPI_Fint *indegree, MPI_Fint *sources, MPI_Fint *sourceweights, MPI_Fint *outdegree, MPI_Fint *destinations, MPI_Fint *destweights, MPI_Fint *info, MPI_Fint *reorder, MPI_Fint *comm_dist_graph, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    if (sourceweights == MPIR_F_MPI_UNWEIGHTED) {
        sourceweights = (MPI_Fint *) MPI_UNWEIGHTED;
    } else if (sourceweights == MPIR_F_MPI_WEIGHTS_EMPTY) {
        sourceweights = (MPI_Fint *) MPI_WEIGHTS_EMPTY;
    }
    if (destweights == MPIR_F_MPI_UNWEIGHTED) {
        destweights = (MPI_Fint *) MPI_UNWEIGHTED;
    } else if (destweights == MPIR_F_MPI_WEIGHTS_EMPTY) {
        destweights = (MPI_Fint *) MPI_WEIGHTS_EMPTY;
    }
    *ierr = MPI_Dist_graph_create_adjacent((MPI_Comm) (*comm_old), (int) (*indegree), (int *) sources, (int *) sourceweights, (int) (*outdegree), (int *) destinations, (int *) destweights, (MPI_Info) (*info), *reorder, (MPI_Comm *) comm_dist_graph);
    
#else  /* ! HAVE_FINT_IS_INT */
    int *sources_i;
    sources_i = malloc(sizeof(int) * (*indegree));
    for (int i = 0; i < (*indegree); i++) {
        sources_i[i] = (int) sources[i];
    }
    int *sourceweights_i;
    int sourceweights_is_special = 0;
    if (sourceweights == MPIR_F_MPI_UNWEIGHTED) {
        sourceweights_i = MPI_UNWEIGHTED;
        sourceweights_is_special = 1;
    } else if (sourceweights == MPIR_F_MPI_WEIGHTS_EMPTY) {
        sourceweights_i = MPI_WEIGHTS_EMPTY;
        sourceweights_is_special = 1;
    }
    if (!sourceweights_is_special) {
        sourceweights_i = malloc(sizeof(int) * (*indegree));
        for (int i = 0; i < (*indegree); i++) {
            sourceweights_i[i] = (int) sourceweights[i];
        }
    }
    int *destinations_i;
    destinations_i = malloc(sizeof(int) * (*outdegree));
    for (int i = 0; i < (*outdegree); i++) {
        destinations_i[i] = (int) destinations[i];
    }
    int *destweights_i;
    int destweights_is_special = 0;
    if (destweights == MPIR_F_MPI_UNWEIGHTED) {
        destweights_i = MPI_UNWEIGHTED;
        destweights_is_special = 1;
    } else if (destweights == MPIR_F_MPI_WEIGHTS_EMPTY) {
        destweights_i = MPI_WEIGHTS_EMPTY;
        destweights_is_special = 1;
    }
    if (!destweights_is_special) {
        destweights_i = malloc(sizeof(int) * (*outdegree));
        for (int i = 0; i < (*outdegree); i++) {
            destweights_i[i] = (int) destweights[i];
        }
    }
    MPI_Comm comm_dist_graph_i;
    *ierr = MPI_Dist_graph_create_adjacent((MPI_Comm) (*comm_old), (int) (*indegree), sources_i, sourceweights_i, (int) (*outdegree), destinations_i, destweights_i, (MPI_Info) (*info), *reorder, &comm_dist_graph_i);
    free(sources_i);
    if (!sourceweights_is_special) {
        free(sourceweights_i);
    }
    free(destinations_i);
    if (!destweights_is_special) {
        free(destweights_i);
    }
    *comm_dist_graph = (MPI_Fint) comm_dist_graph_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_dist_graph_neighbors_(MPI_Fint *comm, MPI_Fint *maxindegree, MPI_Fint *sources, MPI_Fint *sourceweights, MPI_Fint *maxoutdegree, MPI_Fint *destinations, MPI_Fint *destweights, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Dist_graph_neighbors((MPI_Comm) (*comm), (int) (*maxindegree), (int *) sources, (int *) sourceweights, (int) (*maxoutdegree), (int *) destinations, (int *) destweights);
    
#else  /* ! HAVE_FINT_IS_INT */
    int *sources_i;
    sources_i = malloc(sizeof(int) * (*maxindegree));
    int *sourceweights_i;
    sourceweights_i = malloc(sizeof(int) * (*maxindegree));
    int *destinations_i;
    destinations_i = malloc(sizeof(int) * (*maxoutdegree));
    int *destweights_i;
    destweights_i = malloc(sizeof(int) * (*maxoutdegree));
    *ierr = MPI_Dist_graph_neighbors((MPI_Comm) (*comm), (int) (*maxindegree), sources_i, sourceweights_i, (int) (*maxoutdegree), destinations_i, destweights_i);
    for (int i = 0; i < (*maxindegree); i++) {
        sources[i] = (MPI_Fint) sources_i[i];
    }
    free(sources_i);
    for (int i = 0; i < (*maxindegree); i++) {
        sourceweights[i] = (MPI_Fint) sourceweights_i[i];
    }
    free(sourceweights_i);
    for (int i = 0; i < (*maxoutdegree); i++) {
        destinations[i] = (MPI_Fint) destinations_i[i];
    }
    free(destinations_i);
    for (int i = 0; i < (*maxoutdegree); i++) {
        destweights[i] = (MPI_Fint) destweights_i[i];
    }
    free(destweights_i);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_dist_graph_neighbors_count_(MPI_Fint *comm, MPI_Fint *indegree, MPI_Fint *outdegree, MPI_Fint *weighted, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    int weighted_i;
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Dist_graph_neighbors_count((MPI_Comm) (*comm), (int *) indegree, (int *) outdegree, &weighted_i);
    
#else  /* ! HAVE_FINT_IS_INT */
    int indegree_i;
    int outdegree_i;
    *ierr = MPI_Dist_graph_neighbors_count((MPI_Comm) (*comm), &indegree_i, &outdegree_i, &weighted_i);
    *indegree = (MPI_Fint) indegree_i;
    *outdegree = (MPI_Fint) outdegree_i;
#endif
    if (*ierr == MPI_SUCCESS) {
        *weighted = MPII_TO_FLOG(weighted_i);
    }
}


FORT_DLL_SPEC void FORT_CALL mpi_get_hw_resource_info_(MPI_Fint *hw_info, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Get_hw_resource_info((MPI_Info *) hw_info);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Info hw_info_i;
    *ierr = MPI_Get_hw_resource_info(&hw_info_i);
    *hw_info = (MPI_Fint) hw_info_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_graph_create_(MPI_Fint *comm_old, MPI_Fint *nnodes, MPI_Fint *indx, MPI_Fint *edges, MPI_Fint *reorder, MPI_Fint *comm_graph, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Graph_create((MPI_Comm) (*comm_old), (int) (*nnodes), (int *) indx, (int *) edges, *reorder, (MPI_Comm *) comm_graph);
    
#else  /* ! HAVE_FINT_IS_INT */
    int *indx_i;
    indx_i = malloc(sizeof(int) * (*nnodes));
    for (int i = 0; i < (*nnodes); i++) {
        indx_i[i] = (int) indx[i];
    }
    int *edges_i;
    edges_i = malloc(sizeof(int) * indx[*nnodes - 1]);
    for (int i = 0; i < indx[*nnodes - 1]; i++) {
        edges_i[i] = (int) edges[i];
    }
    MPI_Comm comm_graph_i;
    *ierr = MPI_Graph_create((MPI_Comm) (*comm_old), (int) (*nnodes), indx_i, edges_i, *reorder, &comm_graph_i);
    free(indx_i);
    free(edges_i);
    *comm_graph = (MPI_Fint) comm_graph_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_graph_get_(MPI_Fint *comm, MPI_Fint *maxindex, MPI_Fint *maxedges, MPI_Fint *indx, MPI_Fint *edges, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Graph_get((MPI_Comm) (*comm), (int) (*maxindex), (int) (*maxedges), (int *) indx, (int *) edges);
    
#else  /* ! HAVE_FINT_IS_INT */
    int *indx_i;
    indx_i = malloc(sizeof(int) * (*maxindex));
    int *edges_i;
    edges_i = malloc(sizeof(int) * (*maxedges));
    *ierr = MPI_Graph_get((MPI_Comm) (*comm), (int) (*maxindex), (int) (*maxedges), indx_i, edges_i);
    for (int i = 0; i < (*maxindex); i++) {
        indx[i] = (MPI_Fint) indx_i[i];
    }
    free(indx_i);
    for (int i = 0; i < (*maxedges); i++) {
        edges[i] = (MPI_Fint) edges_i[i];
    }
    free(edges_i);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_graph_map_(MPI_Fint *comm, MPI_Fint *nnodes, MPI_Fint *indx, MPI_Fint *edges, MPI_Fint *newrank, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Graph_map((MPI_Comm) (*comm), (int) (*nnodes), (int *) indx, (int *) edges, (int *) newrank);
    
#else  /* ! HAVE_FINT_IS_INT */
    int *indx_i;
    indx_i = malloc(sizeof(int) * (*nnodes));
    for (int i = 0; i < (*nnodes); i++) {
        indx_i[i] = (int) indx[i];
    }
    int *edges_i;
    edges_i = malloc(sizeof(int) * indx[*nnodes - 1]);
    for (int i = 0; i < indx[*nnodes - 1]; i++) {
        edges_i[i] = (int) edges[i];
    }
    int newrank_i;
    *ierr = MPI_Graph_map((MPI_Comm) (*comm), (int) (*nnodes), indx_i, edges_i, &newrank_i);
    free(indx_i);
    free(edges_i);
    *newrank = (MPI_Fint) newrank_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_graph_neighbors_(MPI_Fint *comm, MPI_Fint *rank, MPI_Fint *maxneighbors, MPI_Fint *neighbors, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Graph_neighbors((MPI_Comm) (*comm), (int) (*rank), (int) (*maxneighbors), (int *) neighbors);
    
#else  /* ! HAVE_FINT_IS_INT */
    int *neighbors_i;
    neighbors_i = malloc(sizeof(int) * (*maxneighbors));
    *ierr = MPI_Graph_neighbors((MPI_Comm) (*comm), (int) (*rank), (int) (*maxneighbors), neighbors_i);
    for (int i = 0; i < (*maxneighbors); i++) {
        neighbors[i] = (MPI_Fint) neighbors_i[i];
    }
    free(neighbors_i);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_graph_neighbors_count_(MPI_Fint *comm, MPI_Fint *rank, MPI_Fint *nneighbors, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Graph_neighbors_count((MPI_Comm) (*comm), (int) (*rank), (int *) nneighbors);
    
#else  /* ! HAVE_FINT_IS_INT */
    int nneighbors_i;
    *ierr = MPI_Graph_neighbors_count((MPI_Comm) (*comm), (int) (*rank), &nneighbors_i);
    *nneighbors = (MPI_Fint) nneighbors_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_graphdims_get_(MPI_Fint *comm, MPI_Fint *nnodes, MPI_Fint *nedges, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Graphdims_get((MPI_Comm) (*comm), (int *) nnodes, (int *) nedges);
    
#else  /* ! HAVE_FINT_IS_INT */
    int nnodes_i;
    int nedges_i;
    *ierr = MPI_Graphdims_get((MPI_Comm) (*comm), &nnodes_i, &nedges_i);
    *nnodes = (MPI_Fint) nnodes_i;
    *nedges = (MPI_Fint) nedges_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_topo_test_(MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) {
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_Topo_test((MPI_Comm) (*comm), (int *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    int status_i;
    *ierr = MPI_Topo_test((MPI_Comm) (*comm), &status_i);
    *status = (MPI_Fint) status_i;
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_close_(MPI_Fint *fh, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    MPI_File fh_i = MPI_File_f2c(*fh);
    *ierr = MPI_File_close(&fh_i);
    *fh = MPI_File_c2f(fh_i);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_delete_(char *filename FORT_MIXED_LEN(filename_len), MPI_Fint *info, MPI_Fint *ierr FORT_END_LEN(filename_len)) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *filename_i = MPIR_fort_dup_str(filename, filename_len);
    *ierr = MPI_File_delete(filename_i, (MPI_Info) (*info));
    free(filename_i);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_get_amode_(MPI_Fint *fh, MPI_Fint *amode, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_File_get_amode(MPI_File_f2c(*fh), (int *) amode);
    
#else  /* ! HAVE_FINT_IS_INT */
    int amode_i;
    *ierr = MPI_File_get_amode(MPI_File_f2c(*fh), &amode_i);
    *amode = (MPI_Fint) amode_i;
#endif
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_get_atomicity_(MPI_Fint *fh, MPI_Fint *flag, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    int flag_i;
    *ierr = MPI_File_get_atomicity(MPI_File_f2c(*fh), &flag_i);
    if (*ierr == MPI_SUCCESS) {
        *flag = MPII_TO_FLOG(flag_i);
    }
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_get_byte_offset_(MPI_Fint *fh, MPI_Offset *offset, MPI_Offset *disp, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_File_get_byte_offset(MPI_File_f2c(*fh), *offset, disp);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_get_group_(MPI_Fint *fh, MPI_Fint *group, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_File_get_group(MPI_File_f2c(*fh), (MPI_Group *) group);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Group group_i;
    *ierr = MPI_File_get_group(MPI_File_f2c(*fh), &group_i);
    *group = (MPI_Fint) group_i;
#endif
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_get_info_(MPI_Fint *fh, MPI_Fint *info_used, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_File_get_info(MPI_File_f2c(*fh), (MPI_Info *) info_used);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Info info_used_i;
    *ierr = MPI_File_get_info(MPI_File_f2c(*fh), &info_used_i);
    *info_used = (MPI_Fint) info_used_i;
#endif
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_get_position_(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_File_get_position(MPI_File_f2c(*fh), offset);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_get_position_shared_(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_File_get_position_shared(MPI_File_f2c(*fh), offset);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_get_size_(MPI_Fint *fh, MPI_Offset *size, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_File_get_size(MPI_File_f2c(*fh), size);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_get_type_extent_(MPI_Fint *fh, MPI_Fint *datatype, MPI_Aint *extent, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_File_get_type_extent(MPI_File_f2c(*fh), (MPI_Datatype) (*datatype), extent);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_get_view_(MPI_Fint *fh, MPI_Offset *disp, MPI_Fint *etype, MPI_Fint *filetype, char *datarep FORT_MIXED_LEN(datarep_len), MPI_Fint *ierr FORT_END_LEN(datarep_len)) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *datarep_i = malloc(datarep_len + 1);
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_File_get_view(MPI_File_f2c(*fh), disp, (MPI_Datatype *) etype, (MPI_Datatype *) filetype, datarep_i);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Datatype etype_i;
    MPI_Datatype filetype_i;
    *ierr = MPI_File_get_view(MPI_File_f2c(*fh), disp, &etype_i, &filetype_i, datarep_i);
    *etype = (MPI_Fint) etype_i;
    *filetype = (MPI_Fint) filetype_i;
#endif
    if (*ierr == MPI_SUCCESS) {
        MPIR_fort_copy_str_from_c(datarep, datarep_len, datarep_i);
    }
    free(datarep_i);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_iread_(MPI_Fint *fh, void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_File_iread(MPI_File_f2c(*fh), buf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_File_iread(MPI_File_f2c(*fh), buf, (int) (*count), (MPI_Datatype) (*datatype), &request_i);
    *request = (MPI_Fint) request_i;
#endif
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_iread_all_(MPI_Fint *fh, void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_File_iread_all(MPI_File_f2c(*fh), buf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_File_iread_all(MPI_File_f2c(*fh), buf, (int) (*count), (MPI_Datatype) (*datatype), &request_i);
    *request = (MPI_Fint) request_i;
#endif
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_iread_at_(MPI_Fint *fh, MPI_Offset *offset, void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_File_iread_at(MPI_File_f2c(*fh), *offset, buf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_File_iread_at(MPI_File_f2c(*fh), *offset, buf, (int) (*count), (MPI_Datatype) (*datatype), &request_i);
    *request = (MPI_Fint) request_i;
#endif
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_iread_at_all_(MPI_Fint *fh, MPI_Offset *offset, void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_File_iread_at_all(MPI_File_f2c(*fh), *offset, buf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_File_iread_at_all(MPI_File_f2c(*fh), *offset, buf, (int) (*count), (MPI_Datatype) (*datatype), &request_i);
    *request = (MPI_Fint) request_i;
#endif
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_iread_shared_(MPI_Fint *fh, void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_File_iread_shared(MPI_File_f2c(*fh), buf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_File_iread_shared(MPI_File_f2c(*fh), buf, (int) (*count), (MPI_Datatype) (*datatype), &request_i);
    *request = (MPI_Fint) request_i;
#endif
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_iwrite_(MPI_Fint *fh, void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_File_iwrite(MPI_File_f2c(*fh), buf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_File_iwrite(MPI_File_f2c(*fh), buf, (int) (*count), (MPI_Datatype) (*datatype), &request_i);
    *request = (MPI_Fint) request_i;
#endif
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_iwrite_all_(MPI_Fint *fh, void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_File_iwrite_all(MPI_File_f2c(*fh), buf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_File_iwrite_all(MPI_File_f2c(*fh), buf, (int) (*count), (MPI_Datatype) (*datatype), &request_i);
    *request = (MPI_Fint) request_i;
#endif
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_iwrite_at_(MPI_Fint *fh, MPI_Offset *offset, void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_File_iwrite_at(MPI_File_f2c(*fh), *offset, buf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_File_iwrite_at(MPI_File_f2c(*fh), *offset, buf, (int) (*count), (MPI_Datatype) (*datatype), &request_i);
    *request = (MPI_Fint) request_i;
#endif
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_iwrite_at_all_(MPI_Fint *fh, MPI_Offset *offset, void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_File_iwrite_at_all(MPI_File_f2c(*fh), *offset, buf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_File_iwrite_at_all(MPI_File_f2c(*fh), *offset, buf, (int) (*count), (MPI_Datatype) (*datatype), &request_i);
    *request = (MPI_Fint) request_i;
#endif
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_iwrite_shared_(MPI_Fint *fh, void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    *ierr = MPI_File_iwrite_shared(MPI_File_f2c(*fh), buf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Request *) request);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Request request_i;
    *ierr = MPI_File_iwrite_shared(MPI_File_f2c(*fh), buf, (int) (*count), (MPI_Datatype) (*datatype), &request_i);
    *request = (MPI_Fint) request_i;
#endif
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_open_(MPI_Fint *comm, char *filename FORT_MIXED_LEN(filename_len), MPI_Fint *amode, MPI_Fint *info, MPI_Fint *fh, MPI_Fint *ierr FORT_END_LEN(filename_len)) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *filename_i = MPIR_fort_dup_str(filename, filename_len);
    MPI_File fh_i;
    *ierr = MPI_File_open((MPI_Comm) (*comm), filename_i, (int) (*amode), (MPI_Info) (*info), &fh_i);
    free(filename_i);
    *fh = MPI_File_c2f(fh_i);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_preallocate_(MPI_Fint *fh, MPI_Offset *size, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_File_preallocate(MPI_File_f2c(*fh), *size);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_read_(MPI_Fint *fh, void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPI_File_read(MPI_File_f2c(*fh), buf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPI_File_read(MPI_File_f2c(*fh), buf, (int) (*count), (MPI_Datatype) (*datatype), status_arg);
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_read_all_(MPI_Fint *fh, void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPI_File_read_all(MPI_File_f2c(*fh), buf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPI_File_read_all(MPI_File_f2c(*fh), buf, (int) (*count), (MPI_Datatype) (*datatype), status_arg);
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_read_all_begin_(MPI_Fint *fh, void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
    *ierr = MPI_File_read_all_begin(MPI_File_f2c(*fh), buf, (int) (*count), (MPI_Datatype) (*datatype));
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_read_all_end_(MPI_Fint *fh, void *buf, MPI_Fint *status, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPI_File_read_all_end(MPI_File_f2c(*fh), buf, (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPI_File_read_all_end(MPI_File_f2c(*fh), buf, status_arg);
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_read_at_(MPI_Fint *fh, MPI_Offset *offset, void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPI_File_read_at(MPI_File_f2c(*fh), *offset, buf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPI_File_read_at(MPI_File_f2c(*fh), *offset, buf, (int) (*count), (MPI_Datatype) (*datatype), status_arg);
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_read_at_all_(MPI_Fint *fh, MPI_Offset *offset, void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPI_File_read_at_all(MPI_File_f2c(*fh), *offset, buf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPI_File_read_at_all(MPI_File_f2c(*fh), *offset, buf, (int) (*count), (MPI_Datatype) (*datatype), status_arg);
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_read_at_all_begin_(MPI_Fint *fh, MPI_Offset *offset, void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
    *ierr = MPI_File_read_at_all_begin(MPI_File_f2c(*fh), *offset, buf, (int) (*count), (MPI_Datatype) (*datatype));
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_read_at_all_end_(MPI_Fint *fh, void *buf, MPI_Fint *status, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPI_File_read_at_all_end(MPI_File_f2c(*fh), buf, (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPI_File_read_at_all_end(MPI_File_f2c(*fh), buf, status_arg);
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_read_ordered_(MPI_Fint *fh, void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPI_File_read_ordered(MPI_File_f2c(*fh), buf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPI_File_read_ordered(MPI_File_f2c(*fh), buf, (int) (*count), (MPI_Datatype) (*datatype), status_arg);
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_read_ordered_begin_(MPI_Fint *fh, void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
    *ierr = MPI_File_read_ordered_begin(MPI_File_f2c(*fh), buf, (int) (*count), (MPI_Datatype) (*datatype));
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_read_ordered_end_(MPI_Fint *fh, void *buf, MPI_Fint *status, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPI_File_read_ordered_end(MPI_File_f2c(*fh), buf, (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPI_File_read_ordered_end(MPI_File_f2c(*fh), buf, status_arg);
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_read_shared_(MPI_Fint *fh, void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPI_File_read_shared(MPI_File_f2c(*fh), buf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPI_File_read_shared(MPI_File_f2c(*fh), buf, (int) (*count), (MPI_Datatype) (*datatype), status_arg);
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_seek_(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *whence, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_File_seek(MPI_File_f2c(*fh), *offset, (int) (*whence));
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_seek_shared_(MPI_Fint *fh, MPI_Offset *offset, MPI_Fint *whence, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_File_seek_shared(MPI_File_f2c(*fh), *offset, (int) (*whence));
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_set_atomicity_(MPI_Fint *fh, MPI_Fint *flag, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_File_set_atomicity(MPI_File_f2c(*fh), *flag);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_set_info_(MPI_Fint *fh, MPI_Fint *info, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_File_set_info(MPI_File_f2c(*fh), (MPI_Info) (*info));
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_set_size_(MPI_Fint *fh, MPI_Offset *size, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_File_set_size(MPI_File_f2c(*fh), *size);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_set_view_(MPI_Fint *fh, MPI_Offset *disp, MPI_Fint *etype, MPI_Fint *filetype, char *datarep FORT_MIXED_LEN(datarep_len), MPI_Fint *info, MPI_Fint *ierr FORT_END_LEN(datarep_len)) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *datarep_i = MPIR_fort_dup_str(datarep, datarep_len);
    *ierr = MPI_File_set_view(MPI_File_f2c(*fh), *disp, (MPI_Datatype) (*etype), (MPI_Datatype) (*filetype), datarep_i, (MPI_Info) (*info));
    free(datarep_i);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_sync_(MPI_Fint *fh, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    *ierr = MPI_File_sync(MPI_File_f2c(*fh));
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_write_(MPI_Fint *fh, void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPI_File_write(MPI_File_f2c(*fh), buf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPI_File_write(MPI_File_f2c(*fh), buf, (int) (*count), (MPI_Datatype) (*datatype), status_arg);
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_write_all_(MPI_Fint *fh, void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPI_File_write_all(MPI_File_f2c(*fh), buf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPI_File_write_all(MPI_File_f2c(*fh), buf, (int) (*count), (MPI_Datatype) (*datatype), status_arg);
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_write_all_begin_(MPI_Fint *fh, void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
    *ierr = MPI_File_write_all_begin(MPI_File_f2c(*fh), buf, (int) (*count), (MPI_Datatype) (*datatype));
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_write_all_end_(MPI_Fint *fh, void *buf, MPI_Fint *status, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPI_File_write_all_end(MPI_File_f2c(*fh), buf, (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPI_File_write_all_end(MPI_File_f2c(*fh), buf, status_arg);
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_write_at_(MPI_Fint *fh, MPI_Offset *offset, void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPI_File_write_at(MPI_File_f2c(*fh), *offset, buf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPI_File_write_at(MPI_File_f2c(*fh), *offset, buf, (int) (*count), (MPI_Datatype) (*datatype), status_arg);
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_write_at_all_(MPI_Fint *fh, MPI_Offset *offset, void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPI_File_write_at_all(MPI_File_f2c(*fh), *offset, buf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPI_File_write_at_all(MPI_File_f2c(*fh), *offset, buf, (int) (*count), (MPI_Datatype) (*datatype), status_arg);
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_write_at_all_begin_(MPI_Fint *fh, MPI_Offset *offset, void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
    *ierr = MPI_File_write_at_all_begin(MPI_File_f2c(*fh), *offset, buf, (int) (*count), (MPI_Datatype) (*datatype));
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_write_at_all_end_(MPI_Fint *fh, void *buf, MPI_Fint *status, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPI_File_write_at_all_end(MPI_File_f2c(*fh), buf, (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPI_File_write_at_all_end(MPI_File_f2c(*fh), buf, status_arg);
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_write_ordered_(MPI_Fint *fh, void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPI_File_write_ordered(MPI_File_f2c(*fh), buf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPI_File_write_ordered(MPI_File_f2c(*fh), buf, (int) (*count), (MPI_Datatype) (*datatype), status_arg);
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_write_ordered_begin_(MPI_Fint *fh, void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
    *ierr = MPI_File_write_ordered_begin(MPI_File_f2c(*fh), buf, (int) (*count), (MPI_Datatype) (*datatype));
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_write_ordered_end_(MPI_Fint *fh, void *buf, MPI_Fint *status, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPI_File_write_ordered_end(MPI_File_f2c(*fh), buf, (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPI_File_write_ordered_end(MPI_File_f2c(*fh), buf, status_arg);
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_file_write_shared_(MPI_Fint *fh, void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *status, MPI_Fint *ierr) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    if (buf == MPIR_F_MPI_BOTTOM) {
        buf = MPI_BOTTOM;
    }
    
#ifdef HAVE_FINT_IS_INT
    if (status == MPI_F_STATUS_IGNORE) {
        status = (MPI_Fint *) MPI_STATUS_IGNORE;
    }
    *ierr = MPI_File_write_shared(MPI_File_f2c(*fh), buf, (int) (*count), (MPI_Datatype) (*datatype), (MPI_Status *) status);
    
#else  /* ! HAVE_FINT_IS_INT */
    MPI_Status * status_arg;
    int status_i[MPI_F_STATUS_SIZE];
    if (status == MPI_F_STATUS_IGNORE) {
        status_arg = MPI_STATUS_IGNORE;
    } else {
        status_arg = (MPI_Status *) status_i;
        for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
            status_i[i] = (int) status[i];
        }
    }
    *ierr = MPI_File_write_shared(MPI_File_f2c(*fh), buf, (int) (*count), (MPI_Datatype) (*datatype), status_arg);
    if (status != MPI_F_STATUS_IGNORE) {
    for (int i = 0; i < MPI_F_STATUS_SIZE; i++) {
        status[i] = (MPI_Fint) status_i[i];
    }
    }
#endif
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_register_datarep_(char *datarep FORT_MIXED_LEN(datarep_len), MPI_Datarep_conversion_function read_conversion_fn, MPI_Datarep_conversion_function write_conversion_fn, MPI_Datarep_extent_function dtype_file_extent_fn, void *extra_state, MPI_Fint *ierr FORT_END_LEN(datarep_len)) {
#ifndef HAVE_ROMIO
    *ierr = MPI_ERR_INTERN;
#else
    if (MPIR_F_NeedInit) {mpirinitf_(); MPIR_F_NeedInit = 0;}
    
    char *datarep_i = MPIR_fort_dup_str(datarep, datarep_len);
    if (read_conversion_fn == (MPI_Datarep_conversion_function *) mpi_conversion_fn_null_) {
        read_conversion_fn = NULL;
    }
    if (write_conversion_fn == (MPI_Datarep_conversion_function *) mpi_conversion_fn_null_) {
        write_conversion_fn = NULL;
    }
    *ierr = MPI_Register_datarep(datarep_i, read_conversion_fn, write_conversion_fn, dtype_file_extent_fn, extra_state);
    free(datarep_i);
#endif
}


FORT_DLL_SPEC void FORT_CALL mpi_dup_fn_(MPI_Fint *oldcomm, MPI_Fint *keyval, void *extra_state, void *attribute_val_in, void *attribute_val_out, MPI_Fint *flag, MPI_Fint *ierr) {
    * (MPI_Aint *) attribute_val_out = * (MPI_Aint *) attribute_val_in;
    *flag = MPII_TO_FLOG(1);
    *ierr = MPI_SUCCESS;
}


FORT_DLL_SPEC void FORT_CALL mpi_null_copy_fn_(MPI_Fint *oldcomm, MPI_Fint *keyval, void *extra_state, void *attribute_val_in, void *attribute_val_out, MPI_Fint *flag, MPI_Fint *ierr) {
    *flag = MPII_TO_FLOG(0);
    *ierr = MPI_SUCCESS;
}


FORT_DLL_SPEC void FORT_CALL mpi_null_delete_fn_(MPI_Fint *comm, MPI_Fint *keyval, void *attribute_val, void *extra_state, MPI_Fint *ierror) {
    *ierror = MPI_SUCCESS;
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_dup_fn_(MPI_Fint *oldcomm, MPI_Fint *comm_keyval, void *extra_state, void *attribute_val_in, void *attribute_val_out, MPI_Fint *flag, MPI_Fint *ierror) {
    * (MPI_Aint *) attribute_val_out = * (MPI_Aint *) attribute_val_in;
    *flag = MPII_TO_FLOG(1);
    *ierror = MPI_SUCCESS;
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_null_copy_fn_(MPI_Fint *oldcomm, MPI_Fint *comm_keyval, void *extra_state, void *attribute_val_in, void *attribute_val_out, MPI_Fint *flag, MPI_Fint *ierror) {
    *flag = MPII_TO_FLOG(0);
    *ierror = MPI_SUCCESS;
}


FORT_DLL_SPEC void FORT_CALL mpi_comm_null_delete_fn_(MPI_Fint *comm, MPI_Fint *comm_keyval, void *attribute_val, void *extra_state, MPI_Fint *ierror) {
    *ierror = MPI_SUCCESS;
}


FORT_DLL_SPEC void FORT_CALL mpi_type_dup_fn_(MPI_Fint *oldtype, MPI_Fint *type_keyval, void *extra_state, void *attribute_val_in, void *attribute_val_out, MPI_Fint *flag, MPI_Fint *ierror) {
    * (MPI_Aint *) attribute_val_out = * (MPI_Aint *) attribute_val_in;
    *flag = MPII_TO_FLOG(1);
    *ierror = MPI_SUCCESS;
}


FORT_DLL_SPEC void FORT_CALL mpi_type_null_copy_fn_(MPI_Fint *oldtype, MPI_Fint *type_keyval, void *extra_state, void *attribute_val_in, void *attribute_val_out, MPI_Fint *flag, MPI_Fint *ierror) {
    *flag = MPII_TO_FLOG(0);
    *ierror = MPI_SUCCESS;
}


FORT_DLL_SPEC void FORT_CALL mpi_type_null_delete_fn_(MPI_Fint *datatype, MPI_Fint *type_keyval, void *attribute_val, void *extra_state, MPI_Fint *ierror, MPI_Fint *ierr) {
    *ierror = MPI_SUCCESS;
}


FORT_DLL_SPEC void FORT_CALL mpi_win_dup_fn_(MPI_Fint *oldwin, MPI_Fint *win_keyval, void *extra_state, void *attribute_val_in, void *attribute_val_out, MPI_Fint *flag, MPI_Fint *ierror) {
    * (MPI_Aint *) attribute_val_out = * (MPI_Aint *) attribute_val_in;
    *flag = MPII_TO_FLOG(1);
    *ierror = MPI_SUCCESS;
}


FORT_DLL_SPEC void FORT_CALL mpi_win_null_copy_fn_(MPI_Fint *oldwin, MPI_Fint *win_keyval, void *extra_state, void *attribute_val_in, void *attribute_val_out, MPI_Fint *flag, MPI_Fint *ierror) {
    *flag = MPII_TO_FLOG(0);
    *ierror = MPI_SUCCESS;
}


FORT_DLL_SPEC void FORT_CALL mpi_win_null_delete_fn_(MPI_Fint *win, MPI_Fint *win_keyval, void *attribute_val, void *extra_state, MPI_Fint *ierror) {
    *ierror = MPI_SUCCESS;
}


FORT_DLL_SPEC int FORT_CALL mpi_conversion_fn_null_(void *userbuf, MPI_Datatype datatype, int count, void *filebuf, MPI_Offset position, void *extra_state) {
    /* dummy function, not callable */
    return 0;
}


FORT_DLL_SPEC void FORT_CALL mpi_f_sync_reg_(void *buf, MPI_Fint *ierr) {
    *ierr = MPI_SUCCESS;
}
