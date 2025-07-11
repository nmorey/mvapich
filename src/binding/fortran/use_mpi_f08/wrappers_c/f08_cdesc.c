/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "cdesc.h"

int MPIR_Allgather_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                         MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                         int recvcount, MPI_Datatype recvtype, MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    int sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    int recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Allgather(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, comm);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Allgather_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                               MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                               MPI_Count recvcount, MPI_Datatype recvtype,
                               MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    MPI_Count sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Allgather_c(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, comm);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Allgather_init_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                              MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                              int recvcount, MPI_Datatype recvtype,
                              MPI_Comm comm, MPI_Info info,
                              MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    int sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    int recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Allgather_init(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, comm, info, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Allgather_init_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                                    MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                                    MPI_Count recvcount, MPI_Datatype recvtype,
                                    MPI_Comm comm, MPI_Info info,
                                    MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    MPI_Count sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Allgather_init_c(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, comm, info, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Allgatherv_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                          MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                          const int recvcounts[], const int displs[],
                          MPI_Datatype recvtype, MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    int sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Allgatherv(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcounts, displs, recvtype, comm);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    return err;
}

int MPIR_Allgatherv_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                                MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                                const MPI_Count recvcounts[],
                                const MPI_Aint displs[], MPI_Datatype recvtype,
                                MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    MPI_Count sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Allgatherv_c(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcounts, displs, recvtype, comm);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    return err;
}

int MPIR_Allgatherv_init_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                               MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                               const int recvcounts[], const int displs[],
                               MPI_Datatype recvtype, MPI_Comm comm,
                               MPI_Info info, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    int sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Allgatherv_init(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcounts, displs, recvtype, comm, info, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    return err;
}

int MPIR_Allgatherv_init_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                                     MPI_Datatype sendtype,
                                     CFI_cdesc_t *recvbuf,
                                     const MPI_Count recvcounts[],
                                     const MPI_Aint displs[],
                                     MPI_Datatype recvtype, MPI_Comm comm,
                                     MPI_Info info, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    MPI_Count sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Allgatherv_init_c(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcounts, displs, recvtype, comm, info, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    return err;
}

int MPIR_Allreduce_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf, int count,
                         MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Allreduce(sendbuf_i, recvbuf_i, count_i, datatype_i, op, comm);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Allreduce_cdesc_large(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                               MPI_Count count, MPI_Datatype datatype,
                               MPI_Op op, MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Allreduce_c(sendbuf_i, recvbuf_i, count_i, datatype_i, op, comm);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Allreduce_init_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                              int count, MPI_Datatype datatype, MPI_Op op,
                              MPI_Comm comm, MPI_Info info,
                              MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Allreduce_init(sendbuf_i, recvbuf_i, count_i, datatype_i, op, comm, info, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Allreduce_init_cdesc_large(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                                    MPI_Count count, MPI_Datatype datatype,
                                    MPI_Op op, MPI_Comm comm, MPI_Info info,
                                    MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Allreduce_init_c(sendbuf_i, recvbuf_i, count_i, datatype_i, op, comm, info, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Alltoall_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                        MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                        int recvcount, MPI_Datatype recvtype, MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    int sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    int recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Alltoall(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, comm);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Alltoall_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                              MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                              MPI_Count recvcount, MPI_Datatype recvtype,
                              MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    MPI_Count sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Alltoall_c(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, comm);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Alltoall_init_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                             MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                             int recvcount, MPI_Datatype recvtype,
                             MPI_Comm comm, MPI_Info info,
                             MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    int sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    int recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Alltoall_init(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, comm, info, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Alltoall_init_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                                   MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                                   MPI_Count recvcount, MPI_Datatype recvtype,
                                   MPI_Comm comm, MPI_Info info,
                                   MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    MPI_Count sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Alltoall_init_c(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, comm, info, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Alltoallv_cdesc(CFI_cdesc_t *sendbuf, const int sendcounts[],
                         const int sdispls[], MPI_Datatype sendtype,
                         CFI_cdesc_t *recvbuf, const int recvcounts[],
                         const int rdispls[], MPI_Datatype recvtype,
                         MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Alltoallv(sendbuf_i, sendcounts, sdispls, sendtype, recvbuf_i, recvcounts, rdispls, recvtype, comm);
    
    return err;
}

int MPIR_Alltoallv_cdesc_large(CFI_cdesc_t *sendbuf,
                               const MPI_Count sendcounts[],
                               const MPI_Aint sdispls[], MPI_Datatype sendtype,
                               CFI_cdesc_t *recvbuf,
                               const MPI_Count recvcounts[],
                               const MPI_Aint rdispls[], MPI_Datatype recvtype,
                               MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Alltoallv_c(sendbuf_i, sendcounts, sdispls, sendtype, recvbuf_i, recvcounts, rdispls, recvtype, comm);
    
    return err;
}

int MPIR_Alltoallv_init_cdesc(CFI_cdesc_t *sendbuf, const int sendcounts[],
                              const int sdispls[], MPI_Datatype sendtype,
                              CFI_cdesc_t *recvbuf, const int recvcounts[],
                              const int rdispls[], MPI_Datatype recvtype,
                              MPI_Comm comm, MPI_Info info,
                              MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Alltoallv_init(sendbuf_i, sendcounts, sdispls, sendtype, recvbuf_i, recvcounts, rdispls, recvtype, comm, info, request);
    
    return err;
}

int MPIR_Alltoallv_init_cdesc_large(CFI_cdesc_t *sendbuf,
                                    const MPI_Count sendcounts[],
                                    const MPI_Aint sdispls[],
                                    MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                                    const MPI_Count recvcounts[],
                                    const MPI_Aint rdispls[],
                                    MPI_Datatype recvtype, MPI_Comm comm,
                                    MPI_Info info, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Alltoallv_init_c(sendbuf_i, sendcounts, sdispls, sendtype, recvbuf_i, recvcounts, rdispls, recvtype, comm, info, request);
    
    return err;
}

int MPIR_Alltoallw_cdesc(CFI_cdesc_t *sendbuf, const int sendcounts[],
                         const int sdispls[], const MPI_Datatype sendtypes[],
                         CFI_cdesc_t *recvbuf, const int recvcounts[],
                         const int rdispls[], const MPI_Datatype recvtypes[],
                         MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Alltoallw(sendbuf_i, sendcounts, sdispls, sendtypes, recvbuf_i, recvcounts, rdispls, recvtypes, comm);
    
    return err;
}

int MPIR_Alltoallw_cdesc_large(CFI_cdesc_t *sendbuf,
                               const MPI_Count sendcounts[],
                               const MPI_Aint sdispls[],
                               const MPI_Datatype sendtypes[],
                               CFI_cdesc_t *recvbuf,
                               const MPI_Count recvcounts[],
                               const MPI_Aint rdispls[],
                               const MPI_Datatype recvtypes[], MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Alltoallw_c(sendbuf_i, sendcounts, sdispls, sendtypes, recvbuf_i, recvcounts, rdispls, recvtypes, comm);
    
    return err;
}

int MPIR_Alltoallw_init_cdesc(CFI_cdesc_t *sendbuf, const int sendcounts[],
                              const int sdispls[],
                              const MPI_Datatype sendtypes[],
                              CFI_cdesc_t *recvbuf, const int recvcounts[],
                              const int rdispls[],
                              const MPI_Datatype recvtypes[], MPI_Comm comm,
                              MPI_Info info, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Alltoallw_init(sendbuf_i, sendcounts, sdispls, sendtypes, recvbuf_i, recvcounts, rdispls, recvtypes, comm, info, request);
    
    return err;
}

int MPIR_Alltoallw_init_cdesc_large(CFI_cdesc_t *sendbuf,
                                    const MPI_Count sendcounts[],
                                    const MPI_Aint sdispls[],
                                    const MPI_Datatype sendtypes[],
                                    CFI_cdesc_t *recvbuf,
                                    const MPI_Count recvcounts[],
                                    const MPI_Aint rdispls[],
                                    const MPI_Datatype recvtypes[],
                                    MPI_Comm comm, MPI_Info info,
                                    MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Alltoallw_init_c(sendbuf_i, sendcounts, sdispls, sendtypes, recvbuf_i, recvcounts, rdispls, recvtypes, comm, info, request);
    
    return err;
}

int MPIR_Bcast_cdesc(CFI_cdesc_t *buffer, int count, MPI_Datatype datatype,
                     int root, MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *buffer_i = buffer->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buffer_i == &MPIR_F08_MPI_BOTTOM) {
        buffer_i = MPI_BOTTOM;
    }
    
    if (buffer->rank != 0 && !CFI_is_contiguous(buffer)) {
        err = cdesc_create_datatype(buffer, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Bcast(buffer_i, count_i, datatype_i, root, comm);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Bcast_cdesc_large(CFI_cdesc_t *buffer, MPI_Count count,
                           MPI_Datatype datatype, int root, MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *buffer_i = buffer->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buffer_i == &MPIR_F08_MPI_BOTTOM) {
        buffer_i = MPI_BOTTOM;
    }
    
    if (buffer->rank != 0 && !CFI_is_contiguous(buffer)) {
        err = cdesc_create_datatype(buffer, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Bcast_c(buffer_i, count_i, datatype_i, root, comm);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Bcast_init_cdesc(CFI_cdesc_t *buffer, int count, MPI_Datatype datatype,
                          int root, MPI_Comm comm, MPI_Info info,
                          MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buffer_i = buffer->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buffer_i == &MPIR_F08_MPI_BOTTOM) {
        buffer_i = MPI_BOTTOM;
    }
    
    if (buffer->rank != 0 && !CFI_is_contiguous(buffer)) {
        err = cdesc_create_datatype(buffer, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Bcast_init(buffer_i, count_i, datatype_i, root, comm, info, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Bcast_init_cdesc_large(CFI_cdesc_t *buffer, MPI_Count count,
                                MPI_Datatype datatype, int root, MPI_Comm comm,
                                MPI_Info info, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buffer_i = buffer->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buffer_i == &MPIR_F08_MPI_BOTTOM) {
        buffer_i = MPI_BOTTOM;
    }
    
    if (buffer->rank != 0 && !CFI_is_contiguous(buffer)) {
        err = cdesc_create_datatype(buffer, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Bcast_init_c(buffer_i, count_i, datatype_i, root, comm, info, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Exscan_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf, int count,
                      MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Exscan(sendbuf_i, recvbuf_i, count_i, datatype_i, op, comm);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Exscan_cdesc_large(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                            MPI_Count count, MPI_Datatype datatype, MPI_Op op,
                            MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Exscan_c(sendbuf_i, recvbuf_i, count_i, datatype_i, op, comm);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Exscan_init_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                           int count, MPI_Datatype datatype, MPI_Op op,
                           MPI_Comm comm, MPI_Info info, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Exscan_init(sendbuf_i, recvbuf_i, count_i, datatype_i, op, comm, info, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Exscan_init_cdesc_large(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                                 MPI_Count count, MPI_Datatype datatype,
                                 MPI_Op op, MPI_Comm comm, MPI_Info info,
                                 MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Exscan_init_c(sendbuf_i, recvbuf_i, count_i, datatype_i, op, comm, info, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Gather_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                      MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                      int recvcount, MPI_Datatype recvtype, int root,
                      MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    int sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    int recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Gather(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, root, comm);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Gather_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                            MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                            MPI_Count recvcount, MPI_Datatype recvtype,
                            int root, MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    MPI_Count sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Gather_c(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, root, comm);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Gather_init_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                           MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                           int recvcount, MPI_Datatype recvtype, int root,
                           MPI_Comm comm, MPI_Info info, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    int sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    int recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Gather_init(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, root, comm, info, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Gather_init_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                                 MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                                 MPI_Count recvcount, MPI_Datatype recvtype,
                                 int root, MPI_Comm comm, MPI_Info info,
                                 MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    MPI_Count sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Gather_init_c(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, root, comm, info, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Gatherv_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                       MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                       const int recvcounts[], const int displs[],
                       MPI_Datatype recvtype, int root, MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    int sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Gatherv(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcounts, displs, recvtype, root, comm);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    return err;
}

int MPIR_Gatherv_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                             MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                             const MPI_Count recvcounts[],
                             const MPI_Aint displs[], MPI_Datatype recvtype,
                             int root, MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    MPI_Count sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Gatherv_c(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcounts, displs, recvtype, root, comm);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    return err;
}

int MPIR_Gatherv_init_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                            MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                            const int recvcounts[], const int displs[],
                            MPI_Datatype recvtype, int root, MPI_Comm comm,
                            MPI_Info info, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    int sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Gatherv_init(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcounts, displs, recvtype, root, comm, info, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    return err;
}

int MPIR_Gatherv_init_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                                  MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                                  const MPI_Count recvcounts[],
                                  const MPI_Aint displs[],
                                  MPI_Datatype recvtype, int root,
                                  MPI_Comm comm, MPI_Info info,
                                  MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    MPI_Count sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Gatherv_init_c(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcounts, displs, recvtype, root, comm, info, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    return err;
}

int MPIR_Iallgather_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                          MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                          int recvcount, MPI_Datatype recvtype, MPI_Comm comm,
                          MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    int sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    int recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Iallgather(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, comm, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Iallgather_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                                MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                                MPI_Count recvcount, MPI_Datatype recvtype,
                                MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    MPI_Count sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Iallgather_c(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, comm, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Iallgatherv_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                           MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                           const int recvcounts[], const int displs[],
                           MPI_Datatype recvtype, MPI_Comm comm,
                           MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    int sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Iallgatherv(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcounts, displs, recvtype, comm, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    return err;
}

int MPIR_Iallgatherv_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                                 MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                                 const MPI_Count recvcounts[],
                                 const MPI_Aint displs[], MPI_Datatype recvtype,
                                 MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    MPI_Count sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Iallgatherv_c(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcounts, displs, recvtype, comm, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    return err;
}

int MPIR_Iallreduce_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf, int count,
                          MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                          MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Iallreduce(sendbuf_i, recvbuf_i, count_i, datatype_i, op, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Iallreduce_cdesc_large(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                                MPI_Count count, MPI_Datatype datatype,
                                MPI_Op op, MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Iallreduce_c(sendbuf_i, recvbuf_i, count_i, datatype_i, op, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Ialltoall_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                         MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                         int recvcount, MPI_Datatype recvtype, MPI_Comm comm,
                         MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    int sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    int recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Ialltoall(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, comm, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Ialltoall_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                               MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                               MPI_Count recvcount, MPI_Datatype recvtype,
                               MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    MPI_Count sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Ialltoall_c(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, comm, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Ialltoallv_cdesc(CFI_cdesc_t *sendbuf, const int sendcounts[],
                          const int sdispls[], MPI_Datatype sendtype,
                          CFI_cdesc_t *recvbuf, const int recvcounts[],
                          const int rdispls[], MPI_Datatype recvtype,
                          MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Ialltoallv(sendbuf_i, sendcounts, sdispls, sendtype, recvbuf_i, recvcounts, rdispls, recvtype, comm, request);
    
    return err;
}

int MPIR_Ialltoallv_cdesc_large(CFI_cdesc_t *sendbuf,
                                const MPI_Count sendcounts[],
                                const MPI_Aint sdispls[], MPI_Datatype sendtype,
                                CFI_cdesc_t *recvbuf,
                                const MPI_Count recvcounts[],
                                const MPI_Aint rdispls[], MPI_Datatype recvtype,
                                MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Ialltoallv_c(sendbuf_i, sendcounts, sdispls, sendtype, recvbuf_i, recvcounts, rdispls, recvtype, comm, request);
    
    return err;
}

int MPIR_Ialltoallw_cdesc(CFI_cdesc_t *sendbuf, const int sendcounts[],
                          const int sdispls[], const MPI_Datatype sendtypes[],
                          CFI_cdesc_t *recvbuf, const int recvcounts[],
                          const int rdispls[], const MPI_Datatype recvtypes[],
                          MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Ialltoallw(sendbuf_i, sendcounts, sdispls, sendtypes, recvbuf_i, recvcounts, rdispls, recvtypes, comm, request);
    
    return err;
}

int MPIR_Ialltoallw_cdesc_large(CFI_cdesc_t *sendbuf,
                                const MPI_Count sendcounts[],
                                const MPI_Aint sdispls[],
                                const MPI_Datatype sendtypes[],
                                CFI_cdesc_t *recvbuf,
                                const MPI_Count recvcounts[],
                                const MPI_Aint rdispls[],
                                const MPI_Datatype recvtypes[], MPI_Comm comm,
                                MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Ialltoallw_c(sendbuf_i, sendcounts, sdispls, sendtypes, recvbuf_i, recvcounts, rdispls, recvtypes, comm, request);
    
    return err;
}

int MPIR_Ibcast_cdesc(CFI_cdesc_t *buffer, int count, MPI_Datatype datatype,
                      int root, MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buffer_i = buffer->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buffer_i == &MPIR_F08_MPI_BOTTOM) {
        buffer_i = MPI_BOTTOM;
    }
    
    if (buffer->rank != 0 && !CFI_is_contiguous(buffer)) {
        err = cdesc_create_datatype(buffer, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Ibcast(buffer_i, count_i, datatype_i, root, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Ibcast_cdesc_large(CFI_cdesc_t *buffer, MPI_Count count,
                            MPI_Datatype datatype, int root, MPI_Comm comm,
                            MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buffer_i = buffer->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buffer_i == &MPIR_F08_MPI_BOTTOM) {
        buffer_i = MPI_BOTTOM;
    }
    
    if (buffer->rank != 0 && !CFI_is_contiguous(buffer)) {
        err = cdesc_create_datatype(buffer, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Ibcast_c(buffer_i, count_i, datatype_i, root, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Iexscan_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf, int count,
                       MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                       MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Iexscan(sendbuf_i, recvbuf_i, count_i, datatype_i, op, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Iexscan_cdesc_large(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                             MPI_Count count, MPI_Datatype datatype, MPI_Op op,
                             MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Iexscan_c(sendbuf_i, recvbuf_i, count_i, datatype_i, op, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Igather_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                       MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                       int recvcount, MPI_Datatype recvtype, int root,
                       MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    int sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    int recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Igather(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, root, comm, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Igather_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                             MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                             MPI_Count recvcount, MPI_Datatype recvtype,
                             int root, MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    MPI_Count sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Igather_c(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, root, comm, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Igatherv_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                        MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                        const int recvcounts[], const int displs[],
                        MPI_Datatype recvtype, int root, MPI_Comm comm,
                        MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    int sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Igatherv(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcounts, displs, recvtype, root, comm, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    return err;
}

int MPIR_Igatherv_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                              MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                              const MPI_Count recvcounts[],
                              const MPI_Aint displs[], MPI_Datatype recvtype,
                              int root, MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    MPI_Count sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Igatherv_c(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcounts, displs, recvtype, root, comm, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    return err;
}

int MPIR_Ineighbor_allgather_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                                   MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                                   int recvcount, MPI_Datatype recvtype,
                                   MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    int sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    int recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Ineighbor_allgather(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, comm, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Ineighbor_allgather_cdesc_large(CFI_cdesc_t *sendbuf,
                    MPI_Count sendcount, MPI_Datatype sendtype,
                    CFI_cdesc_t *recvbuf, MPI_Count recvcount,
                    MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    MPI_Count sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Ineighbor_allgather_c(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, comm, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Ineighbor_allgatherv_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                                    MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                                    const int recvcounts[], const int displs[],
                                    MPI_Datatype recvtype, MPI_Comm comm,
                                    MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    int sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Ineighbor_allgatherv(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcounts, displs, recvtype, comm, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    return err;
}

int MPIR_Ineighbor_allgatherv_cdesc_large(CFI_cdesc_t *sendbuf,
                    MPI_Count sendcount, MPI_Datatype sendtype,
                    CFI_cdesc_t *recvbuf, const MPI_Count recvcounts[],
                    const MPI_Aint displs[], MPI_Datatype recvtype,
                    MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    MPI_Count sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Ineighbor_allgatherv_c(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcounts, displs, recvtype, comm, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    return err;
}

int MPIR_Ineighbor_alltoall_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                                  MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                                  int recvcount, MPI_Datatype recvtype,
                                  MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    int sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    int recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Ineighbor_alltoall(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, comm, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Ineighbor_alltoall_cdesc_large(CFI_cdesc_t *sendbuf,
                                        MPI_Count sendcount,
                                        MPI_Datatype sendtype,
                                        CFI_cdesc_t *recvbuf,
                                        MPI_Count recvcount,
                                        MPI_Datatype recvtype, MPI_Comm comm,
                                        MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    MPI_Count sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Ineighbor_alltoall_c(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, comm, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Ineighbor_alltoallv_cdesc(CFI_cdesc_t *sendbuf, const int sendcounts[],
                                   const int sdispls[], MPI_Datatype sendtype,
                                   CFI_cdesc_t *recvbuf, const int recvcounts[],
                                   const int rdispls[], MPI_Datatype recvtype,
                                   MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Ineighbor_alltoallv(sendbuf_i, sendcounts, sdispls, sendtype, recvbuf_i, recvcounts, rdispls, recvtype, comm, request);
    
    return err;
}

int MPIR_Ineighbor_alltoallv_cdesc_large(CFI_cdesc_t *sendbuf,
                    const MPI_Count sendcounts[], const MPI_Aint sdispls[],
                    MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                    const MPI_Count recvcounts[], const MPI_Aint rdispls[],
                    MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Ineighbor_alltoallv_c(sendbuf_i, sendcounts, sdispls, sendtype, recvbuf_i, recvcounts, rdispls, recvtype, comm, request);
    
    return err;
}

int MPIR_Ineighbor_alltoallw_cdesc(CFI_cdesc_t *sendbuf, const int sendcounts[],
                                   const MPI_Aint sdispls[],
                                   const MPI_Datatype sendtypes[],
                                   CFI_cdesc_t *recvbuf, const int recvcounts[],
                                   const MPI_Aint rdispls[],
                                   const MPI_Datatype recvtypes[],
                                   MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Ineighbor_alltoallw(sendbuf_i, sendcounts, sdispls, sendtypes, recvbuf_i, recvcounts, rdispls, recvtypes, comm, request);
    
    return err;
}

int MPIR_Ineighbor_alltoallw_cdesc_large(CFI_cdesc_t *sendbuf,
                    const MPI_Count sendcounts[], const MPI_Aint sdispls[],
                    const MPI_Datatype sendtypes[], CFI_cdesc_t *recvbuf,
                    const MPI_Count recvcounts[], const MPI_Aint rdispls[],
                    const MPI_Datatype recvtypes[], MPI_Comm comm,
                    MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Ineighbor_alltoallw_c(sendbuf_i, sendcounts, sdispls, sendtypes, recvbuf_i, recvcounts, rdispls, recvtypes, comm, request);
    
    return err;
}

int MPIR_Ireduce_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf, int count,
                       MPI_Datatype datatype, MPI_Op op, int root,
                       MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Ireduce(sendbuf_i, recvbuf_i, count_i, datatype_i, op, root, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Ireduce_cdesc_large(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                             MPI_Count count, MPI_Datatype datatype, MPI_Op op,
                             int root, MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Ireduce_c(sendbuf_i, recvbuf_i, count_i, datatype_i, op, root, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Ireduce_scatter_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                               const int recvcounts[], MPI_Datatype datatype,
                               MPI_Op op, MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Ireduce_scatter(sendbuf_i, recvbuf_i, recvcounts, datatype, op, comm, request);
    
    return err;
}

int MPIR_Ireduce_scatter_cdesc_large(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                                     const MPI_Count recvcounts[],
                                     MPI_Datatype datatype, MPI_Op op,
                                     MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Ireduce_scatter_c(sendbuf_i, recvbuf_i, recvcounts, datatype, op, comm, request);
    
    return err;
}

int MPIR_Ireduce_scatter_block_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                                     int recvcount, MPI_Datatype datatype,
                                     MPI_Op op, MPI_Comm comm,
                                     MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Ireduce_scatter_block(sendbuf_i, recvbuf_i, recvcount, datatype, op, comm, request);
    
    return err;
}

int MPIR_Ireduce_scatter_block_cdesc_large(CFI_cdesc_t *sendbuf,
                    CFI_cdesc_t *recvbuf, MPI_Count recvcount,
                    MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                    MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Ireduce_scatter_block_c(sendbuf_i, recvbuf_i, recvcount, datatype, op, comm, request);
    
    return err;
}

int MPIR_Iscan_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf, int count,
                     MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                     MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Iscan(sendbuf_i, recvbuf_i, count_i, datatype_i, op, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Iscan_cdesc_large(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                           MPI_Count count, MPI_Datatype datatype, MPI_Op op,
                           MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Iscan_c(sendbuf_i, recvbuf_i, count_i, datatype_i, op, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Iscatter_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                        MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                        int recvcount, MPI_Datatype recvtype, int root,
                        MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    int sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    int recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    } else if (recvbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        recvbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Iscatter(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, root, comm, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Iscatter_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                              MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                              MPI_Count recvcount, MPI_Datatype recvtype,
                              int root, MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    MPI_Count sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    } else if (recvbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        recvbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Iscatter_c(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, root, comm, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Iscatterv_cdesc(CFI_cdesc_t *sendbuf, const int sendcounts[],
                         const int displs[], MPI_Datatype sendtype,
                         CFI_cdesc_t *recvbuf, int recvcount,
                         MPI_Datatype recvtype, int root, MPI_Comm comm,
                         MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    int recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    } else if (recvbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        recvbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Iscatterv(sendbuf_i, sendcounts, displs, sendtype, recvbuf_i, recvcount_i, recvtype_i, root, comm, request);
    
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Iscatterv_cdesc_large(CFI_cdesc_t *sendbuf,
                               const MPI_Count sendcounts[],
                               const MPI_Aint displs[], MPI_Datatype sendtype,
                               CFI_cdesc_t *recvbuf, MPI_Count recvcount,
                               MPI_Datatype recvtype, int root, MPI_Comm comm,
                               MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    } else if (recvbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        recvbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Iscatterv_c(sendbuf_i, sendcounts, displs, sendtype, recvbuf_i, recvcount_i, recvtype_i, root, comm, request);
    
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Neighbor_allgather_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                                  MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                                  int recvcount, MPI_Datatype recvtype,
                                  MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    int sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    int recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Neighbor_allgather(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, comm);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Neighbor_allgather_cdesc_large(CFI_cdesc_t *sendbuf,
                                        MPI_Count sendcount,
                                        MPI_Datatype sendtype,
                                        CFI_cdesc_t *recvbuf,
                                        MPI_Count recvcount,
                                        MPI_Datatype recvtype, MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    MPI_Count sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Neighbor_allgather_c(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, comm);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Neighbor_allgather_init_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                                       MPI_Datatype sendtype,
                                       CFI_cdesc_t *recvbuf, int recvcount,
                                       MPI_Datatype recvtype, MPI_Comm comm,
                                       MPI_Info info, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    int sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    int recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Neighbor_allgather_init(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, comm, info, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Neighbor_allgather_init_cdesc_large(CFI_cdesc_t *sendbuf,
                    MPI_Count sendcount, MPI_Datatype sendtype,
                    CFI_cdesc_t *recvbuf, MPI_Count recvcount,
                    MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info,
                    MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    MPI_Count sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Neighbor_allgather_init_c(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, comm, info, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Neighbor_allgatherv_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                                   MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                                   const int recvcounts[], const int displs[],
                                   MPI_Datatype recvtype, MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    int sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Neighbor_allgatherv(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcounts, displs, recvtype, comm);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    return err;
}

int MPIR_Neighbor_allgatherv_cdesc_large(CFI_cdesc_t *sendbuf,
                    MPI_Count sendcount, MPI_Datatype sendtype,
                    CFI_cdesc_t *recvbuf, const MPI_Count recvcounts[],
                    const MPI_Aint displs[], MPI_Datatype recvtype,
                    MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    MPI_Count sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Neighbor_allgatherv_c(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcounts, displs, recvtype, comm);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    return err;
}

int MPIR_Neighbor_allgatherv_init_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                                        MPI_Datatype sendtype,
                                        CFI_cdesc_t *recvbuf,
                                        const int recvcounts[],
                                        const int displs[],
                                        MPI_Datatype recvtype, MPI_Comm comm,
                                        MPI_Info info, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    int sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Neighbor_allgatherv_init(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcounts, displs, recvtype, comm, info, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    return err;
}

int MPIR_Neighbor_allgatherv_init_cdesc_large(CFI_cdesc_t *sendbuf,
                    MPI_Count sendcount, MPI_Datatype sendtype,
                    CFI_cdesc_t *recvbuf, const MPI_Count recvcounts[],
                    const MPI_Aint displs[], MPI_Datatype recvtype,
                    MPI_Comm comm, MPI_Info info, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    MPI_Count sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Neighbor_allgatherv_init_c(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcounts, displs, recvtype, comm, info, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    return err;
}

int MPIR_Neighbor_alltoall_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                                 MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                                 int recvcount, MPI_Datatype recvtype,
                                 MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    int sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    int recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Neighbor_alltoall(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, comm);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Neighbor_alltoall_cdesc_large(CFI_cdesc_t *sendbuf,
                                       MPI_Count sendcount,
                                       MPI_Datatype sendtype,
                                       CFI_cdesc_t *recvbuf,
                                       MPI_Count recvcount,
                                       MPI_Datatype recvtype, MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    MPI_Count sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Neighbor_alltoall_c(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, comm);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Neighbor_alltoall_init_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                                      MPI_Datatype sendtype,
                                      CFI_cdesc_t *recvbuf, int recvcount,
                                      MPI_Datatype recvtype, MPI_Comm comm,
                                      MPI_Info info, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    int sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    int recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Neighbor_alltoall_init(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, comm, info, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Neighbor_alltoall_init_cdesc_large(CFI_cdesc_t *sendbuf,
                    MPI_Count sendcount, MPI_Datatype sendtype,
                    CFI_cdesc_t *recvbuf, MPI_Count recvcount,
                    MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info,
                    MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    MPI_Count sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Neighbor_alltoall_init_c(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, comm, info, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Neighbor_alltoallv_cdesc(CFI_cdesc_t *sendbuf, const int sendcounts[],
                                  const int sdispls[], MPI_Datatype sendtype,
                                  CFI_cdesc_t *recvbuf, const int recvcounts[],
                                  const int rdispls[], MPI_Datatype recvtype,
                                  MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Neighbor_alltoallv(sendbuf_i, sendcounts, sdispls, sendtype, recvbuf_i, recvcounts, rdispls, recvtype, comm);
    
    return err;
}

int MPIR_Neighbor_alltoallv_cdesc_large(CFI_cdesc_t *sendbuf,
                                        const MPI_Count sendcounts[],
                                        const MPI_Aint sdispls[],
                                        MPI_Datatype sendtype,
                                        CFI_cdesc_t *recvbuf,
                                        const MPI_Count recvcounts[],
                                        const MPI_Aint rdispls[],
                                        MPI_Datatype recvtype, MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Neighbor_alltoallv_c(sendbuf_i, sendcounts, sdispls, sendtype, recvbuf_i, recvcounts, rdispls, recvtype, comm);
    
    return err;
}

int MPIR_Neighbor_alltoallv_init_cdesc(CFI_cdesc_t *sendbuf,
                                       const int sendcounts[],
                                       const int sdispls[],
                                       MPI_Datatype sendtype,
                                       CFI_cdesc_t *recvbuf,
                                       const int recvcounts[],
                                       const int rdispls[],
                                       MPI_Datatype recvtype, MPI_Comm comm,
                                       MPI_Info info, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Neighbor_alltoallv_init(sendbuf_i, sendcounts, sdispls, sendtype, recvbuf_i, recvcounts, rdispls, recvtype, comm, info, request);
    
    return err;
}

int MPIR_Neighbor_alltoallv_init_cdesc_large(CFI_cdesc_t *sendbuf,
                    const MPI_Count sendcounts[], const MPI_Aint sdispls[],
                    MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                    const MPI_Count recvcounts[], const MPI_Aint rdispls[],
                    MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info,
                    MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Neighbor_alltoallv_init_c(sendbuf_i, sendcounts, sdispls, sendtype, recvbuf_i, recvcounts, rdispls, recvtype, comm, info, request);
    
    return err;
}

int MPIR_Neighbor_alltoallw_cdesc(CFI_cdesc_t *sendbuf, const int sendcounts[],
                                  const MPI_Aint sdispls[],
                                  const MPI_Datatype sendtypes[],
                                  CFI_cdesc_t *recvbuf, const int recvcounts[],
                                  const MPI_Aint rdispls[],
                                  const MPI_Datatype recvtypes[],
                                  MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Neighbor_alltoallw(sendbuf_i, sendcounts, sdispls, sendtypes, recvbuf_i, recvcounts, rdispls, recvtypes, comm);
    
    return err;
}

int MPIR_Neighbor_alltoallw_cdesc_large(CFI_cdesc_t *sendbuf,
                                        const MPI_Count sendcounts[],
                                        const MPI_Aint sdispls[],
                                        const MPI_Datatype sendtypes[],
                                        CFI_cdesc_t *recvbuf,
                                        const MPI_Count recvcounts[],
                                        const MPI_Aint rdispls[],
                                        const MPI_Datatype recvtypes[],
                                        MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Neighbor_alltoallw_c(sendbuf_i, sendcounts, sdispls, sendtypes, recvbuf_i, recvcounts, rdispls, recvtypes, comm);
    
    return err;
}

int MPIR_Neighbor_alltoallw_init_cdesc(CFI_cdesc_t *sendbuf,
                                       const int sendcounts[],
                                       const MPI_Aint sdispls[],
                                       const MPI_Datatype sendtypes[],
                                       CFI_cdesc_t *recvbuf,
                                       const int recvcounts[],
                                       const MPI_Aint rdispls[],
                                       const MPI_Datatype recvtypes[],
                                       MPI_Comm comm, MPI_Info info,
                                       MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Neighbor_alltoallw_init(sendbuf_i, sendcounts, sdispls, sendtypes, recvbuf_i, recvcounts, rdispls, recvtypes, comm, info, request);
    
    return err;
}

int MPIR_Neighbor_alltoallw_init_cdesc_large(CFI_cdesc_t *sendbuf,
                    const MPI_Count sendcounts[], const MPI_Aint sdispls[],
                    const MPI_Datatype sendtypes[], CFI_cdesc_t *recvbuf,
                    const MPI_Count recvcounts[], const MPI_Aint rdispls[],
                    const MPI_Datatype recvtypes[], MPI_Comm comm,
                    MPI_Info info, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Neighbor_alltoallw_init_c(sendbuf_i, sendcounts, sdispls, sendtypes, recvbuf_i, recvcounts, rdispls, recvtypes, comm, info, request);
    
    return err;
}

int MPIR_Reduce_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf, int count,
                      MPI_Datatype datatype, MPI_Op op, int root,
                      MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Reduce(sendbuf_i, recvbuf_i, count_i, datatype_i, op, root, comm);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Reduce_cdesc_large(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                            MPI_Count count, MPI_Datatype datatype, MPI_Op op,
                            int root, MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Reduce_c(sendbuf_i, recvbuf_i, count_i, datatype_i, op, root, comm);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Reduce_init_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                           int count, MPI_Datatype datatype, MPI_Op op,
                           int root, MPI_Comm comm, MPI_Info info,
                           MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Reduce_init(sendbuf_i, recvbuf_i, count_i, datatype_i, op, root, comm, info, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Reduce_init_cdesc_large(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                                 MPI_Count count, MPI_Datatype datatype,
                                 MPI_Op op, int root, MPI_Comm comm,
                                 MPI_Info info, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Reduce_init_c(sendbuf_i, recvbuf_i, count_i, datatype_i, op, root, comm, info, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Reduce_local_cdesc(CFI_cdesc_t *inbuf, CFI_cdesc_t *inoutbuf,
                            int count, MPI_Datatype datatype, MPI_Op op)
{
    int err = MPI_SUCCESS;
    void *inbuf_i = inbuf->base_addr;
    void *inoutbuf_i = inoutbuf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (inbuf_i == &MPIR_F08_MPI_BOTTOM) {
        inbuf_i = MPI_BOTTOM;
    } else if (inbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        inbuf_i = MPI_IN_PLACE;
    }
    
    if (inoutbuf_i == &MPIR_F08_MPI_BOTTOM) {
        inoutbuf_i = MPI_BOTTOM;
    }
    
    if (inoutbuf->rank != 0 && !CFI_is_contiguous(inoutbuf)) {
        err = cdesc_create_datatype(inoutbuf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Reduce_local(inbuf_i, inoutbuf_i, count_i, datatype_i, op);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Reduce_local_cdesc_large(CFI_cdesc_t *inbuf, CFI_cdesc_t *inoutbuf,
                                  MPI_Count count, MPI_Datatype datatype,
                                  MPI_Op op)
{
    int err = MPI_SUCCESS;
    void *inbuf_i = inbuf->base_addr;
    void *inoutbuf_i = inoutbuf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (inbuf_i == &MPIR_F08_MPI_BOTTOM) {
        inbuf_i = MPI_BOTTOM;
    } else if (inbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        inbuf_i = MPI_IN_PLACE;
    }
    
    if (inoutbuf_i == &MPIR_F08_MPI_BOTTOM) {
        inoutbuf_i = MPI_BOTTOM;
    }
    
    if (inoutbuf->rank != 0 && !CFI_is_contiguous(inoutbuf)) {
        err = cdesc_create_datatype(inoutbuf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Reduce_local_c(inbuf_i, inoutbuf_i, count_i, datatype_i, op);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Reduce_scatter_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                              const int recvcounts[], MPI_Datatype datatype,
                              MPI_Op op, MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Reduce_scatter(sendbuf_i, recvbuf_i, recvcounts, datatype, op, comm);
    
    return err;
}

int MPIR_Reduce_scatter_cdesc_large(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                                    const MPI_Count recvcounts[],
                                    MPI_Datatype datatype, MPI_Op op,
                                    MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Reduce_scatter_c(sendbuf_i, recvbuf_i, recvcounts, datatype, op, comm);
    
    return err;
}

int MPIR_Reduce_scatter_block_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                                    int recvcount, MPI_Datatype datatype,
                                    MPI_Op op, MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Reduce_scatter_block(sendbuf_i, recvbuf_i, recvcount, datatype, op, comm);
    
    return err;
}

int MPIR_Reduce_scatter_block_cdesc_large(CFI_cdesc_t *sendbuf,
                    CFI_cdesc_t *recvbuf, MPI_Count recvcount,
                    MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Reduce_scatter_block_c(sendbuf_i, recvbuf_i, recvcount, datatype, op, comm);
    
    return err;
}

int MPIR_Reduce_scatter_block_init_cdesc(CFI_cdesc_t *sendbuf,
                    CFI_cdesc_t *recvbuf, int recvcount, MPI_Datatype datatype,
                    MPI_Op op, MPI_Comm comm, MPI_Info info,
                    MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Reduce_scatter_block_init(sendbuf_i, recvbuf_i, recvcount, datatype, op, comm, info, request);
    
    return err;
}

int MPIR_Reduce_scatter_block_init_cdesc_large(CFI_cdesc_t *sendbuf,
                    CFI_cdesc_t *recvbuf, MPI_Count recvcount,
                    MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                    MPI_Info info, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Reduce_scatter_block_init_c(sendbuf_i, recvbuf_i, recvcount, datatype, op, comm, info, request);
    
    return err;
}

int MPIR_Reduce_scatter_init_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                                   const int recvcounts[],
                                   MPI_Datatype datatype, MPI_Op op,
                                   MPI_Comm comm, MPI_Info info,
                                   MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Reduce_scatter_init(sendbuf_i, recvbuf_i, recvcounts, datatype, op, comm, info, request);
    
    return err;
}

int MPIR_Reduce_scatter_init_cdesc_large(CFI_cdesc_t *sendbuf,
                    CFI_cdesc_t *recvbuf, const MPI_Count recvcounts[],
                    MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                    MPI_Info info, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Reduce_scatter_init_c(sendbuf_i, recvbuf_i, recvcounts, datatype, op, comm, info, request);
    
    return err;
}

int MPIR_Scan_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf, int count,
                    MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Scan(sendbuf_i, recvbuf_i, count_i, datatype_i, op, comm);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Scan_cdesc_large(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                          MPI_Count count, MPI_Datatype datatype, MPI_Op op,
                          MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Scan_c(sendbuf_i, recvbuf_i, count_i, datatype_i, op, comm);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Scan_init_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf, int count,
                         MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                         MPI_Info info, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Scan_init(sendbuf_i, recvbuf_i, count_i, datatype_i, op, comm, info, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Scan_init_cdesc_large(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                               MPI_Count count, MPI_Datatype datatype,
                               MPI_Op op, MPI_Comm comm, MPI_Info info,
                               MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    } else if (sendbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        sendbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Scan_init_c(sendbuf_i, recvbuf_i, count_i, datatype_i, op, comm, info, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Scatter_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                       MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                       int recvcount, MPI_Datatype recvtype, int root,
                       MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    int sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    int recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    } else if (recvbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        recvbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Scatter(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, root, comm);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Scatter_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                             MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                             MPI_Count recvcount, MPI_Datatype recvtype,
                             int root, MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    MPI_Count sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    } else if (recvbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        recvbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Scatter_c(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, root, comm);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Scatter_init_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                            MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                            int recvcount, MPI_Datatype recvtype, int root,
                            MPI_Comm comm, MPI_Info info, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    int sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    int recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    } else if (recvbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        recvbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Scatter_init(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, root, comm, info, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Scatter_init_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                                  MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                                  MPI_Count recvcount, MPI_Datatype recvtype,
                                  int root, MPI_Comm comm, MPI_Info info,
                                  MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    MPI_Count sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    } else if (recvbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        recvbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Scatter_init_c(sendbuf_i, sendcount_i, sendtype_i, recvbuf_i, recvcount_i, recvtype_i, root, comm, info, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Scatterv_cdesc(CFI_cdesc_t *sendbuf, const int sendcounts[],
                        const int displs[], MPI_Datatype sendtype,
                        CFI_cdesc_t *recvbuf, int recvcount,
                        MPI_Datatype recvtype, int root, MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    int recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    } else if (recvbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        recvbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Scatterv(sendbuf_i, sendcounts, displs, sendtype, recvbuf_i, recvcount_i, recvtype_i, root, comm);
    
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Scatterv_cdesc_large(CFI_cdesc_t *sendbuf,
                              const MPI_Count sendcounts[],
                              const MPI_Aint displs[], MPI_Datatype sendtype,
                              CFI_cdesc_t *recvbuf, MPI_Count recvcount,
                              MPI_Datatype recvtype, int root, MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    } else if (recvbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        recvbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Scatterv_c(sendbuf_i, sendcounts, displs, sendtype, recvbuf_i, recvcount_i, recvtype_i, root, comm);
    
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Scatterv_init_cdesc(CFI_cdesc_t *sendbuf, const int sendcounts[],
                             const int displs[], MPI_Datatype sendtype,
                             CFI_cdesc_t *recvbuf, int recvcount,
                             MPI_Datatype recvtype, int root, MPI_Comm comm,
                             MPI_Info info, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    int recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    } else if (recvbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        recvbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Scatterv_init(sendbuf_i, sendcounts, displs, sendtype, recvbuf_i, recvcount_i, recvtype_i, root, comm, info, request);
    
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Scatterv_init_cdesc_large(CFI_cdesc_t *sendbuf,
                                   const MPI_Count sendcounts[],
                                   const MPI_Aint displs[],
                                   MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                                   MPI_Count recvcount, MPI_Datatype recvtype,
                                   int root, MPI_Comm comm, MPI_Info info,
                                   MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    } else if (recvbuf_i == &MPIR_F08_MPI_IN_PLACE) {
        recvbuf_i = MPI_IN_PLACE;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Scatterv_init_c(sendbuf_i, sendcounts, displs, sendtype, recvbuf_i, recvcount_i, recvtype_i, root, comm, info, request);
    
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Get_address_cdesc(CFI_cdesc_t *location, MPI_Aint *address)
{
    int err = MPI_SUCCESS;
    void *location_i = location->base_addr;
    
    if (location_i == &MPIR_F08_MPI_BOTTOM) {
        location_i = MPI_BOTTOM;
    }
    
    err = MPI_Get_address(location_i, address);
    
    return err;
}

int MPIR_Pack_cdesc(CFI_cdesc_t *inbuf, int incount, MPI_Datatype datatype,
                    CFI_cdesc_t *outbuf, int outsize, int *position,
                    MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *inbuf_i = inbuf->base_addr;
    void *outbuf_i = outbuf->base_addr;
    
    if (inbuf_i == &MPIR_F08_MPI_BOTTOM) {
        inbuf_i = MPI_BOTTOM;
    }
    
    if (outbuf_i == &MPIR_F08_MPI_BOTTOM) {
        outbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Pack(inbuf_i, incount, datatype, outbuf_i, outsize, position, comm);
    
    return err;
}

int MPIR_Pack_cdesc_large(CFI_cdesc_t *inbuf, MPI_Count incount,
                          MPI_Datatype datatype, CFI_cdesc_t *outbuf,
                          MPI_Count outsize, MPI_Count *position,
                          MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *inbuf_i = inbuf->base_addr;
    void *outbuf_i = outbuf->base_addr;
    
    if (inbuf_i == &MPIR_F08_MPI_BOTTOM) {
        inbuf_i = MPI_BOTTOM;
    }
    
    if (outbuf_i == &MPIR_F08_MPI_BOTTOM) {
        outbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Pack_c(inbuf_i, incount, datatype, outbuf_i, outsize, position, comm);
    
    return err;
}

int MPIR_Pack_external_cdesc(const char *datarep, CFI_cdesc_t *inbuf,
                             int incount, MPI_Datatype datatype,
                             CFI_cdesc_t *outbuf, MPI_Aint outsize,
                             MPI_Aint *position)
{
    int err = MPI_SUCCESS;
    void *inbuf_i = inbuf->base_addr;
    void *outbuf_i = outbuf->base_addr;
    
    if (inbuf_i == &MPIR_F08_MPI_BOTTOM) {
        inbuf_i = MPI_BOTTOM;
    }
    
    if (outbuf_i == &MPIR_F08_MPI_BOTTOM) {
        outbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Pack_external(datarep, inbuf_i, incount, datatype, outbuf_i, outsize, position);
    
    return err;
}

int MPIR_Pack_external_cdesc_large(const char *datarep, CFI_cdesc_t *inbuf,
                                   MPI_Count incount, MPI_Datatype datatype,
                                   CFI_cdesc_t *outbuf, MPI_Count outsize,
                                   MPI_Count *position)
{
    int err = MPI_SUCCESS;
    void *inbuf_i = inbuf->base_addr;
    void *outbuf_i = outbuf->base_addr;
    
    if (inbuf_i == &MPIR_F08_MPI_BOTTOM) {
        inbuf_i = MPI_BOTTOM;
    }
    
    if (outbuf_i == &MPIR_F08_MPI_BOTTOM) {
        outbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Pack_external_c(datarep, inbuf_i, incount, datatype, outbuf_i, outsize, position);
    
    return err;
}

int MPIR_Unpack_cdesc(CFI_cdesc_t *inbuf, int insize, int *position,
                      CFI_cdesc_t *outbuf, int outcount, MPI_Datatype datatype,
                      MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *inbuf_i = inbuf->base_addr;
    void *outbuf_i = outbuf->base_addr;
    
    if (inbuf_i == &MPIR_F08_MPI_BOTTOM) {
        inbuf_i = MPI_BOTTOM;
    }
    
    if (outbuf_i == &MPIR_F08_MPI_BOTTOM) {
        outbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Unpack(inbuf_i, insize, position, outbuf_i, outcount, datatype, comm);
    
    return err;
}

int MPIR_Unpack_cdesc_large(CFI_cdesc_t *inbuf, MPI_Count insize,
                            MPI_Count *position, CFI_cdesc_t *outbuf,
                            MPI_Count outcount, MPI_Datatype datatype,
                            MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *inbuf_i = inbuf->base_addr;
    void *outbuf_i = outbuf->base_addr;
    
    if (inbuf_i == &MPIR_F08_MPI_BOTTOM) {
        inbuf_i = MPI_BOTTOM;
    }
    
    if (outbuf_i == &MPIR_F08_MPI_BOTTOM) {
        outbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Unpack_c(inbuf_i, insize, position, outbuf_i, outcount, datatype, comm);
    
    return err;
}

int MPIR_Unpack_external_cdesc(const char datarep[], CFI_cdesc_t *inbuf,
                               MPI_Aint insize, MPI_Aint *position,
                               CFI_cdesc_t *outbuf, int outcount,
                               MPI_Datatype datatype)
{
    int err = MPI_SUCCESS;
    void *inbuf_i = inbuf->base_addr;
    void *outbuf_i = outbuf->base_addr;
    
    if (inbuf_i == &MPIR_F08_MPI_BOTTOM) {
        inbuf_i = MPI_BOTTOM;
    }
    
    if (outbuf_i == &MPIR_F08_MPI_BOTTOM) {
        outbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Unpack_external(datarep, inbuf_i, insize, position, outbuf_i, outcount, datatype);
    
    return err;
}

int MPIR_Unpack_external_cdesc_large(const char datarep[], CFI_cdesc_t *inbuf,
                                     MPI_Count insize, MPI_Count *position,
                                     CFI_cdesc_t *outbuf, MPI_Count outcount,
                                     MPI_Datatype datatype)
{
    int err = MPI_SUCCESS;
    void *inbuf_i = inbuf->base_addr;
    void *outbuf_i = outbuf->base_addr;
    
    if (inbuf_i == &MPIR_F08_MPI_BOTTOM) {
        inbuf_i = MPI_BOTTOM;
    }
    
    if (outbuf_i == &MPIR_F08_MPI_BOTTOM) {
        outbuf_i = MPI_BOTTOM;
    }
    
    err = MPI_Unpack_external_c(datarep, inbuf_i, insize, position, outbuf_i, outcount, datatype);
    
    return err;
}

int MPIR_Info_set_hex_cdesc(MPI_Info info, const char *key, CFI_cdesc_t *value,
                            int value_size)
{
    int err = MPI_SUCCESS;
    void *value_i = value->base_addr;
    
    if (value_i == &MPIR_F08_MPI_BOTTOM) {
        value_i = MPI_BOTTOM;
    }
    
    err = MPIX_Info_set_hex(info, key, value_i, value_size);
    
    return err;
}

int MPIR_Precv_init_cdesc(CFI_cdesc_t *buf, int partitions, MPI_Count count,
                          MPI_Datatype datatype, int dest, int tag,
                          MPI_Comm comm, MPI_Info info, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    err = MPI_Precv_init(buf_i, partitions, count, datatype, dest, tag, comm, info, request);
    
    return err;
}

int MPIR_Psend_init_cdesc(CFI_cdesc_t *buf, int partitions, MPI_Count count,
                          MPI_Datatype datatype, int dest, int tag,
                          MPI_Comm comm, MPI_Info info, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    err = MPI_Psend_init(buf_i, partitions, count, datatype, dest, tag, comm, info, request);
    
    return err;
}

int MPIR_Bsend_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                     int dest, int tag, MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Bsend(buf_i, count_i, datatype_i, dest, tag, comm);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Bsend_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                           MPI_Datatype datatype, int dest, int tag,
                           MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Bsend_c(buf_i, count_i, datatype_i, dest, tag, comm);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Bsend_init_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                          int dest, int tag, MPI_Comm comm,
                          MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Bsend_init(buf_i, count_i, datatype_i, dest, tag, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Bsend_init_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                                MPI_Datatype datatype, int dest, int tag,
                                MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Bsend_init_c(buf_i, count_i, datatype_i, dest, tag, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Buffer_attach_cdesc(CFI_cdesc_t *buffer, int size)
{
    int err = MPI_SUCCESS;
    void *buffer_i = buffer->base_addr;
    
    if (buffer_i == &MPIR_F08_MPI_BOTTOM) {
        buffer_i = MPI_BOTTOM;
    }
    
    err = MPI_Buffer_attach(buffer_i, size);
    
    return err;
}

int MPIR_Buffer_attach_cdesc_large(CFI_cdesc_t *buffer, MPI_Count size)
{
    int err = MPI_SUCCESS;
    void *buffer_i = buffer->base_addr;
    
    if (buffer_i == &MPIR_F08_MPI_BOTTOM) {
        buffer_i = MPI_BOTTOM;
    }
    
    err = MPI_Buffer_attach_c(buffer_i, size);
    
    return err;
}

int MPIR_Comm_attach_buffer_cdesc(MPI_Comm comm, CFI_cdesc_t *buffer, int size)
{
    int err = MPI_SUCCESS;
    void *buffer_i = buffer->base_addr;
    
    if (buffer_i == &MPIR_F08_MPI_BOTTOM) {
        buffer_i = MPI_BOTTOM;
    }
    
    err = MPI_Comm_attach_buffer(comm, buffer_i, size);
    
    return err;
}

int MPIR_Comm_attach_buffer_cdesc_large(MPI_Comm comm, CFI_cdesc_t *buffer,
                                        MPI_Count size)
{
    int err = MPI_SUCCESS;
    void *buffer_i = buffer->base_addr;
    
    if (buffer_i == &MPIR_F08_MPI_BOTTOM) {
        buffer_i = MPI_BOTTOM;
    }
    
    err = MPI_Comm_attach_buffer_c(comm, buffer_i, size);
    
    return err;
}

int MPIR_Ibsend_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                      int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Ibsend(buf_i, count_i, datatype_i, dest, tag, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Ibsend_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                            MPI_Datatype datatype, int dest, int tag,
                            MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Ibsend_c(buf_i, count_i, datatype_i, dest, tag, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Imrecv_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                      MPI_Message *message, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Imrecv(buf_i, count_i, datatype_i, message, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Imrecv_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                            MPI_Datatype datatype, MPI_Message *message,
                            MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Imrecv_c(buf_i, count_i, datatype_i, message, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Irecv_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                     int source, int tag, MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Irecv(buf_i, count_i, datatype_i, source, tag, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Irecv_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                           MPI_Datatype datatype, int source, int tag,
                           MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Irecv_c(buf_i, count_i, datatype_i, source, tag, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Irsend_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                      int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Irsend(buf_i, count_i, datatype_i, dest, tag, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Irsend_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                            MPI_Datatype datatype, int dest, int tag,
                            MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Irsend_c(buf_i, count_i, datatype_i, dest, tag, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Isend_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                     int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Isend(buf_i, count_i, datatype_i, dest, tag, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Isend_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                           MPI_Datatype datatype, int dest, int tag,
                           MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Isend_c(buf_i, count_i, datatype_i, dest, tag, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Isendrecv_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                         MPI_Datatype sendtype, int dest, int sendtag,
                         CFI_cdesc_t *recvbuf, int recvcount,
                         MPI_Datatype recvtype, int source, int recvtag,
                         MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    int sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    int recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Isendrecv(sendbuf_i, sendcount_i, sendtype_i, dest, sendtag, recvbuf_i, recvcount_i, recvtype_i, source, recvtag, comm, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Isendrecv_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                               MPI_Datatype sendtype, int dest, int sendtag,
                               CFI_cdesc_t *recvbuf, MPI_Count recvcount,
                               MPI_Datatype recvtype, int source, int recvtag,
                               MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    MPI_Count sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Isendrecv_c(sendbuf_i, sendcount_i, sendtype_i, dest, sendtag, recvbuf_i, recvcount_i, recvtype_i, source, recvtag, comm, request);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Isendrecv_replace_cdesc(CFI_cdesc_t *buf, int count,
                                 MPI_Datatype datatype, int dest, int sendtag,
                                 int source, int recvtag, MPI_Comm comm,
                                 MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Isendrecv_replace(buf_i, count_i, datatype_i, dest, sendtag, source, recvtag, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Isendrecv_replace_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                                       MPI_Datatype datatype, int dest,
                                       int sendtag, int source, int recvtag,
                                       MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Isendrecv_replace_c(buf_i, count_i, datatype_i, dest, sendtag, source, recvtag, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Issend_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                      int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Issend(buf_i, count_i, datatype_i, dest, tag, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Issend_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                            MPI_Datatype datatype, int dest, int tag,
                            MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Issend_c(buf_i, count_i, datatype_i, dest, tag, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Mrecv_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                     MPI_Message *message, MPI_Status *status)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Mrecv(buf_i, count_i, datatype_i, message, status);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Mrecv_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                           MPI_Datatype datatype, MPI_Message *message,
                           MPI_Status *status)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Mrecv_c(buf_i, count_i, datatype_i, message, status);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Recv_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                    int source, int tag, MPI_Comm comm, MPI_Status *status)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Recv(buf_i, count_i, datatype_i, source, tag, comm, status);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Recv_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                          MPI_Datatype datatype, int source, int tag,
                          MPI_Comm comm, MPI_Status *status)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Recv_c(buf_i, count_i, datatype_i, source, tag, comm, status);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Recv_init_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                         int source, int tag, MPI_Comm comm,
                         MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Recv_init(buf_i, count_i, datatype_i, source, tag, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Recv_init_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                               MPI_Datatype datatype, int source, int tag,
                               MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Recv_init_c(buf_i, count_i, datatype_i, source, tag, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Rsend_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                     int dest, int tag, MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Rsend(buf_i, count_i, datatype_i, dest, tag, comm);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Rsend_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                           MPI_Datatype datatype, int dest, int tag,
                           MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Rsend_c(buf_i, count_i, datatype_i, dest, tag, comm);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Rsend_init_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                          int dest, int tag, MPI_Comm comm,
                          MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Rsend_init(buf_i, count_i, datatype_i, dest, tag, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Rsend_init_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                                MPI_Datatype datatype, int dest, int tag,
                                MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Rsend_init_c(buf_i, count_i, datatype_i, dest, tag, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Send_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                    int dest, int tag, MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Send(buf_i, count_i, datatype_i, dest, tag, comm);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Send_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                          MPI_Datatype datatype, int dest, int tag,
                          MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Send_c(buf_i, count_i, datatype_i, dest, tag, comm);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Send_init_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                         int dest, int tag, MPI_Comm comm,
                         MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Send_init(buf_i, count_i, datatype_i, dest, tag, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Send_init_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                               MPI_Datatype datatype, int dest, int tag,
                               MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Send_init_c(buf_i, count_i, datatype_i, dest, tag, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Sendrecv_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                        MPI_Datatype sendtype, int dest, int sendtag,
                        CFI_cdesc_t *recvbuf, int recvcount,
                        MPI_Datatype recvtype, int source, int recvtag,
                        MPI_Comm comm, MPI_Status *status)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    int sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    int recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Sendrecv(sendbuf_i, sendcount_i, sendtype_i, dest, sendtag, recvbuf_i, recvcount_i, recvtype_i, source, recvtag, comm, status);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Sendrecv_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                              MPI_Datatype sendtype, int dest, int sendtag,
                              CFI_cdesc_t *recvbuf, MPI_Count recvcount,
                              MPI_Datatype recvtype, int source, int recvtag,
                              MPI_Comm comm, MPI_Status *status)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    MPI_Count sendcount_i = sendcount;
    MPI_Datatype sendtype_i = sendtype;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count recvcount_i = recvcount;
    MPI_Datatype recvtype_i = recvtype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (sendbuf->rank != 0 && !CFI_is_contiguous(sendbuf)) {
        err = cdesc_create_datatype(sendbuf, sendcount, sendtype, &sendtype_i);
        if (err) return err;
        sendcount_i = 1;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, recvcount, recvtype, &recvtype_i);
        if (err) return err;
        recvcount_i = 1;
    }
    
    err = MPI_Sendrecv_c(sendbuf_i, sendcount_i, sendtype_i, dest, sendtag, recvbuf_i, recvcount_i, recvtype_i, source, recvtag, comm, status);
    
    if (sendtype_i != sendtype) PMPI_Type_free(&sendtype_i);
    if (recvtype_i != recvtype) PMPI_Type_free(&recvtype_i);
    return err;
}

int MPIR_Sendrecv_replace_cdesc(CFI_cdesc_t *buf, int count,
                                MPI_Datatype datatype, int dest, int sendtag,
                                int source, int recvtag, MPI_Comm comm,
                                MPI_Status *status)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Sendrecv_replace(buf_i, count_i, datatype_i, dest, sendtag, source, recvtag, comm, status);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Sendrecv_replace_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                                      MPI_Datatype datatype, int dest,
                                      int sendtag, int source, int recvtag,
                                      MPI_Comm comm, MPI_Status *status)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Sendrecv_replace_c(buf_i, count_i, datatype_i, dest, sendtag, source, recvtag, comm, status);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Session_attach_buffer_cdesc(MPI_Session session, CFI_cdesc_t *buffer,
                                     int size)
{
    int err = MPI_SUCCESS;
    void *buffer_i = buffer->base_addr;
    
    if (buffer_i == &MPIR_F08_MPI_BOTTOM) {
        buffer_i = MPI_BOTTOM;
    }
    
    err = MPI_Session_attach_buffer(session, buffer_i, size);
    
    return err;
}

int MPIR_Session_attach_buffer_cdesc_large(MPI_Session session,
                    CFI_cdesc_t *buffer, MPI_Count size)
{
    int err = MPI_SUCCESS;
    void *buffer_i = buffer->base_addr;
    
    if (buffer_i == &MPIR_F08_MPI_BOTTOM) {
        buffer_i = MPI_BOTTOM;
    }
    
    err = MPI_Session_attach_buffer_c(session, buffer_i, size);
    
    return err;
}

int MPIR_Ssend_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                     int dest, int tag, MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Ssend(buf_i, count_i, datatype_i, dest, tag, comm);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Ssend_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                           MPI_Datatype datatype, int dest, int tag,
                           MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Ssend_c(buf_i, count_i, datatype_i, dest, tag, comm);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Ssend_init_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                          int dest, int tag, MPI_Comm comm,
                          MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Ssend_init(buf_i, count_i, datatype_i, dest, tag, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Ssend_init_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                                MPI_Datatype datatype, int dest, int tag,
                                MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_Ssend_init_c(buf_i, count_i, datatype_i, dest, tag, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Accumulate_cdesc(CFI_cdesc_t *origin_addr, int origin_count,
                          MPI_Datatype origin_datatype, int target_rank,
                          MPI_Aint target_disp, int target_count,
                          MPI_Datatype target_datatype, MPI_Op op, MPI_Win win)
{
    int err = MPI_SUCCESS;
    void *origin_addr_i = origin_addr->base_addr;
    int origin_count_i = origin_count;
    MPI_Datatype origin_datatype_i = origin_datatype;
    
    if (origin_addr_i == &MPIR_F08_MPI_BOTTOM) {
        origin_addr_i = MPI_BOTTOM;
    }
    
    if (origin_addr->rank != 0 && !CFI_is_contiguous(origin_addr)) {
        err = cdesc_create_datatype(origin_addr, origin_count, origin_datatype, &origin_datatype_i);
        if (err) return err;
        origin_count_i = 1;
    }
    
    err = MPI_Accumulate(origin_addr_i, origin_count_i, origin_datatype_i, target_rank, target_disp, target_count, target_datatype, op, win);
    
    if (origin_datatype_i != origin_datatype) PMPI_Type_free(&origin_datatype_i);
    return err;
}

int MPIR_Accumulate_cdesc_large(CFI_cdesc_t *origin_addr,
                                MPI_Count origin_count,
                                MPI_Datatype origin_datatype, int target_rank,
                                MPI_Aint target_disp, MPI_Count target_count,
                                MPI_Datatype target_datatype, MPI_Op op,
                                MPI_Win win)
{
    int err = MPI_SUCCESS;
    void *origin_addr_i = origin_addr->base_addr;
    MPI_Count origin_count_i = origin_count;
    MPI_Datatype origin_datatype_i = origin_datatype;
    
    if (origin_addr_i == &MPIR_F08_MPI_BOTTOM) {
        origin_addr_i = MPI_BOTTOM;
    }
    
    if (origin_addr->rank != 0 && !CFI_is_contiguous(origin_addr)) {
        err = cdesc_create_datatype(origin_addr, origin_count, origin_datatype, &origin_datatype_i);
        if (err) return err;
        origin_count_i = 1;
    }
    
    err = MPI_Accumulate_c(origin_addr_i, origin_count_i, origin_datatype_i, target_rank, target_disp, target_count, target_datatype, op, win);
    
    if (origin_datatype_i != origin_datatype) PMPI_Type_free(&origin_datatype_i);
    return err;
}

int MPIR_Compare_and_swap_cdesc(CFI_cdesc_t *origin_addr,
                                CFI_cdesc_t *compare_addr,
                                CFI_cdesc_t *result_addr, MPI_Datatype datatype,
                                int target_rank, MPI_Aint target_disp,
                                MPI_Win win)
{
    int err = MPI_SUCCESS;
    void *origin_addr_i = origin_addr->base_addr;
    void *compare_addr_i = compare_addr->base_addr;
    void *result_addr_i = result_addr->base_addr;
    
    if (origin_addr_i == &MPIR_F08_MPI_BOTTOM) {
        origin_addr_i = MPI_BOTTOM;
    }
    
    if (compare_addr_i == &MPIR_F08_MPI_BOTTOM) {
        compare_addr_i = MPI_BOTTOM;
    }
    
    if (result_addr_i == &MPIR_F08_MPI_BOTTOM) {
        result_addr_i = MPI_BOTTOM;
    }
    
    err = MPI_Compare_and_swap(origin_addr_i, compare_addr_i, result_addr_i, datatype, target_rank, target_disp, win);
    
    return err;
}

int MPIR_Fetch_and_op_cdesc(CFI_cdesc_t *origin_addr, CFI_cdesc_t *result_addr,
                            MPI_Datatype datatype, int target_rank,
                            MPI_Aint target_disp, MPI_Op op, MPI_Win win)
{
    int err = MPI_SUCCESS;
    void *origin_addr_i = origin_addr->base_addr;
    void *result_addr_i = result_addr->base_addr;
    
    if (origin_addr_i == &MPIR_F08_MPI_BOTTOM) {
        origin_addr_i = MPI_BOTTOM;
    }
    
    if (result_addr_i == &MPIR_F08_MPI_BOTTOM) {
        result_addr_i = MPI_BOTTOM;
    }
    
    err = MPI_Fetch_and_op(origin_addr_i, result_addr_i, datatype, target_rank, target_disp, op, win);
    
    return err;
}

int MPIR_Free_mem_cdesc(CFI_cdesc_t *base)
{
    int err = MPI_SUCCESS;
    void *base_i = base->base_addr;
    
    if (base_i == &MPIR_F08_MPI_BOTTOM) {
        base_i = MPI_BOTTOM;
    }
    
    err = MPI_Free_mem(base_i);
    
    return err;
}

int MPIR_Get_cdesc(CFI_cdesc_t *origin_addr, int origin_count,
                   MPI_Datatype origin_datatype, int target_rank,
                   MPI_Aint target_disp, int target_count,
                   MPI_Datatype target_datatype, MPI_Win win)
{
    int err = MPI_SUCCESS;
    void *origin_addr_i = origin_addr->base_addr;
    int origin_count_i = origin_count;
    MPI_Datatype origin_datatype_i = origin_datatype;
    
    if (origin_addr_i == &MPIR_F08_MPI_BOTTOM) {
        origin_addr_i = MPI_BOTTOM;
    }
    
    if (origin_addr->rank != 0 && !CFI_is_contiguous(origin_addr)) {
        err = cdesc_create_datatype(origin_addr, origin_count, origin_datatype, &origin_datatype_i);
        if (err) return err;
        origin_count_i = 1;
    }
    
    err = MPI_Get(origin_addr_i, origin_count_i, origin_datatype_i, target_rank, target_disp, target_count, target_datatype, win);
    
    if (origin_datatype_i != origin_datatype) PMPI_Type_free(&origin_datatype_i);
    return err;
}

int MPIR_Get_cdesc_large(CFI_cdesc_t *origin_addr, MPI_Count origin_count,
                         MPI_Datatype origin_datatype, int target_rank,
                         MPI_Aint target_disp, MPI_Count target_count,
                         MPI_Datatype target_datatype, MPI_Win win)
{
    int err = MPI_SUCCESS;
    void *origin_addr_i = origin_addr->base_addr;
    MPI_Count origin_count_i = origin_count;
    MPI_Datatype origin_datatype_i = origin_datatype;
    
    if (origin_addr_i == &MPIR_F08_MPI_BOTTOM) {
        origin_addr_i = MPI_BOTTOM;
    }
    
    if (origin_addr->rank != 0 && !CFI_is_contiguous(origin_addr)) {
        err = cdesc_create_datatype(origin_addr, origin_count, origin_datatype, &origin_datatype_i);
        if (err) return err;
        origin_count_i = 1;
    }
    
    err = MPI_Get_c(origin_addr_i, origin_count_i, origin_datatype_i, target_rank, target_disp, target_count, target_datatype, win);
    
    if (origin_datatype_i != origin_datatype) PMPI_Type_free(&origin_datatype_i);
    return err;
}

int MPIR_Get_accumulate_cdesc(CFI_cdesc_t *origin_addr, int origin_count,
                              MPI_Datatype origin_datatype,
                              CFI_cdesc_t *result_addr, int result_count,
                              MPI_Datatype result_datatype, int target_rank,
                              MPI_Aint target_disp, int target_count,
                              MPI_Datatype target_datatype, MPI_Op op,
                              MPI_Win win)
{
    int err = MPI_SUCCESS;
    void *origin_addr_i = origin_addr->base_addr;
    int origin_count_i = origin_count;
    MPI_Datatype origin_datatype_i = origin_datatype;
    void *result_addr_i = result_addr->base_addr;
    int result_count_i = result_count;
    MPI_Datatype result_datatype_i = result_datatype;
    
    if (origin_addr_i == &MPIR_F08_MPI_BOTTOM) {
        origin_addr_i = MPI_BOTTOM;
    }
    
    if (origin_addr->rank != 0 && !CFI_is_contiguous(origin_addr)) {
        err = cdesc_create_datatype(origin_addr, origin_count, origin_datatype, &origin_datatype_i);
        if (err) return err;
        origin_count_i = 1;
    }
    
    if (result_addr_i == &MPIR_F08_MPI_BOTTOM) {
        result_addr_i = MPI_BOTTOM;
    }
    
    if (result_addr->rank != 0 && !CFI_is_contiguous(result_addr)) {
        err = cdesc_create_datatype(result_addr, result_count, result_datatype, &result_datatype_i);
        if (err) return err;
        result_count_i = 1;
    }
    
    err = MPI_Get_accumulate(origin_addr_i, origin_count_i, origin_datatype_i, result_addr_i, result_count_i, result_datatype_i, target_rank, target_disp, target_count, target_datatype, op, win);
    
    if (origin_datatype_i != origin_datatype) PMPI_Type_free(&origin_datatype_i);
    if (result_datatype_i != result_datatype) PMPI_Type_free(&result_datatype_i);
    return err;
}

int MPIR_Get_accumulate_cdesc_large(CFI_cdesc_t *origin_addr,
                                    MPI_Count origin_count,
                                    MPI_Datatype origin_datatype,
                                    CFI_cdesc_t *result_addr,
                                    MPI_Count result_count,
                                    MPI_Datatype result_datatype,
                                    int target_rank, MPI_Aint target_disp,
                                    MPI_Count target_count,
                                    MPI_Datatype target_datatype, MPI_Op op,
                                    MPI_Win win)
{
    int err = MPI_SUCCESS;
    void *origin_addr_i = origin_addr->base_addr;
    MPI_Count origin_count_i = origin_count;
    MPI_Datatype origin_datatype_i = origin_datatype;
    void *result_addr_i = result_addr->base_addr;
    MPI_Count result_count_i = result_count;
    MPI_Datatype result_datatype_i = result_datatype;
    
    if (origin_addr_i == &MPIR_F08_MPI_BOTTOM) {
        origin_addr_i = MPI_BOTTOM;
    }
    
    if (origin_addr->rank != 0 && !CFI_is_contiguous(origin_addr)) {
        err = cdesc_create_datatype(origin_addr, origin_count, origin_datatype, &origin_datatype_i);
        if (err) return err;
        origin_count_i = 1;
    }
    
    if (result_addr_i == &MPIR_F08_MPI_BOTTOM) {
        result_addr_i = MPI_BOTTOM;
    }
    
    if (result_addr->rank != 0 && !CFI_is_contiguous(result_addr)) {
        err = cdesc_create_datatype(result_addr, result_count, result_datatype, &result_datatype_i);
        if (err) return err;
        result_count_i = 1;
    }
    
    err = MPI_Get_accumulate_c(origin_addr_i, origin_count_i, origin_datatype_i, result_addr_i, result_count_i, result_datatype_i, target_rank, target_disp, target_count, target_datatype, op, win);
    
    if (origin_datatype_i != origin_datatype) PMPI_Type_free(&origin_datatype_i);
    if (result_datatype_i != result_datatype) PMPI_Type_free(&result_datatype_i);
    return err;
}

int MPIR_Put_cdesc(CFI_cdesc_t *origin_addr, int origin_count,
                   MPI_Datatype origin_datatype, int target_rank,
                   MPI_Aint target_disp, int target_count,
                   MPI_Datatype target_datatype, MPI_Win win)
{
    int err = MPI_SUCCESS;
    void *origin_addr_i = origin_addr->base_addr;
    int origin_count_i = origin_count;
    MPI_Datatype origin_datatype_i = origin_datatype;
    
    if (origin_addr_i == &MPIR_F08_MPI_BOTTOM) {
        origin_addr_i = MPI_BOTTOM;
    }
    
    if (origin_addr->rank != 0 && !CFI_is_contiguous(origin_addr)) {
        err = cdesc_create_datatype(origin_addr, origin_count, origin_datatype, &origin_datatype_i);
        if (err) return err;
        origin_count_i = 1;
    }
    
    err = MPI_Put(origin_addr_i, origin_count_i, origin_datatype_i, target_rank, target_disp, target_count, target_datatype, win);
    
    if (origin_datatype_i != origin_datatype) PMPI_Type_free(&origin_datatype_i);
    return err;
}

int MPIR_Put_cdesc_large(CFI_cdesc_t *origin_addr, MPI_Count origin_count,
                         MPI_Datatype origin_datatype, int target_rank,
                         MPI_Aint target_disp, MPI_Count target_count,
                         MPI_Datatype target_datatype, MPI_Win win)
{
    int err = MPI_SUCCESS;
    void *origin_addr_i = origin_addr->base_addr;
    MPI_Count origin_count_i = origin_count;
    MPI_Datatype origin_datatype_i = origin_datatype;
    
    if (origin_addr_i == &MPIR_F08_MPI_BOTTOM) {
        origin_addr_i = MPI_BOTTOM;
    }
    
    if (origin_addr->rank != 0 && !CFI_is_contiguous(origin_addr)) {
        err = cdesc_create_datatype(origin_addr, origin_count, origin_datatype, &origin_datatype_i);
        if (err) return err;
        origin_count_i = 1;
    }
    
    err = MPI_Put_c(origin_addr_i, origin_count_i, origin_datatype_i, target_rank, target_disp, target_count, target_datatype, win);
    
    if (origin_datatype_i != origin_datatype) PMPI_Type_free(&origin_datatype_i);
    return err;
}

int MPIR_Raccumulate_cdesc(CFI_cdesc_t *origin_addr, int origin_count,
                           MPI_Datatype origin_datatype, int target_rank,
                           MPI_Aint target_disp, int target_count,
                           MPI_Datatype target_datatype, MPI_Op op, MPI_Win win,
                           MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *origin_addr_i = origin_addr->base_addr;
    int origin_count_i = origin_count;
    MPI_Datatype origin_datatype_i = origin_datatype;
    
    if (origin_addr_i == &MPIR_F08_MPI_BOTTOM) {
        origin_addr_i = MPI_BOTTOM;
    }
    
    if (origin_addr->rank != 0 && !CFI_is_contiguous(origin_addr)) {
        err = cdesc_create_datatype(origin_addr, origin_count, origin_datatype, &origin_datatype_i);
        if (err) return err;
        origin_count_i = 1;
    }
    
    err = MPI_Raccumulate(origin_addr_i, origin_count_i, origin_datatype_i, target_rank, target_disp, target_count, target_datatype, op, win, request);
    
    if (origin_datatype_i != origin_datatype) PMPI_Type_free(&origin_datatype_i);
    return err;
}

int MPIR_Raccumulate_cdesc_large(CFI_cdesc_t *origin_addr,
                                 MPI_Count origin_count,
                                 MPI_Datatype origin_datatype, int target_rank,
                                 MPI_Aint target_disp, MPI_Count target_count,
                                 MPI_Datatype target_datatype, MPI_Op op,
                                 MPI_Win win, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *origin_addr_i = origin_addr->base_addr;
    MPI_Count origin_count_i = origin_count;
    MPI_Datatype origin_datatype_i = origin_datatype;
    
    if (origin_addr_i == &MPIR_F08_MPI_BOTTOM) {
        origin_addr_i = MPI_BOTTOM;
    }
    
    if (origin_addr->rank != 0 && !CFI_is_contiguous(origin_addr)) {
        err = cdesc_create_datatype(origin_addr, origin_count, origin_datatype, &origin_datatype_i);
        if (err) return err;
        origin_count_i = 1;
    }
    
    err = MPI_Raccumulate_c(origin_addr_i, origin_count_i, origin_datatype_i, target_rank, target_disp, target_count, target_datatype, op, win, request);
    
    if (origin_datatype_i != origin_datatype) PMPI_Type_free(&origin_datatype_i);
    return err;
}

int MPIR_Rget_cdesc(CFI_cdesc_t *origin_addr, int origin_count,
                    MPI_Datatype origin_datatype, int target_rank,
                    MPI_Aint target_disp, int target_count,
                    MPI_Datatype target_datatype, MPI_Win win,
                    MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *origin_addr_i = origin_addr->base_addr;
    int origin_count_i = origin_count;
    MPI_Datatype origin_datatype_i = origin_datatype;
    
    if (origin_addr_i == &MPIR_F08_MPI_BOTTOM) {
        origin_addr_i = MPI_BOTTOM;
    }
    
    if (origin_addr->rank != 0 && !CFI_is_contiguous(origin_addr)) {
        err = cdesc_create_datatype(origin_addr, origin_count, origin_datatype, &origin_datatype_i);
        if (err) return err;
        origin_count_i = 1;
    }
    
    err = MPI_Rget(origin_addr_i, origin_count_i, origin_datatype_i, target_rank, target_disp, target_count, target_datatype, win, request);
    
    if (origin_datatype_i != origin_datatype) PMPI_Type_free(&origin_datatype_i);
    return err;
}

int MPIR_Rget_cdesc_large(CFI_cdesc_t *origin_addr, MPI_Count origin_count,
                          MPI_Datatype origin_datatype, int target_rank,
                          MPI_Aint target_disp, MPI_Count target_count,
                          MPI_Datatype target_datatype, MPI_Win win,
                          MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *origin_addr_i = origin_addr->base_addr;
    MPI_Count origin_count_i = origin_count;
    MPI_Datatype origin_datatype_i = origin_datatype;
    
    if (origin_addr_i == &MPIR_F08_MPI_BOTTOM) {
        origin_addr_i = MPI_BOTTOM;
    }
    
    if (origin_addr->rank != 0 && !CFI_is_contiguous(origin_addr)) {
        err = cdesc_create_datatype(origin_addr, origin_count, origin_datatype, &origin_datatype_i);
        if (err) return err;
        origin_count_i = 1;
    }
    
    err = MPI_Rget_c(origin_addr_i, origin_count_i, origin_datatype_i, target_rank, target_disp, target_count, target_datatype, win, request);
    
    if (origin_datatype_i != origin_datatype) PMPI_Type_free(&origin_datatype_i);
    return err;
}

int MPIR_Rget_accumulate_cdesc(CFI_cdesc_t *origin_addr, int origin_count,
                               MPI_Datatype origin_datatype,
                               CFI_cdesc_t *result_addr, int result_count,
                               MPI_Datatype result_datatype, int target_rank,
                               MPI_Aint target_disp, int target_count,
                               MPI_Datatype target_datatype, MPI_Op op,
                               MPI_Win win, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *origin_addr_i = origin_addr->base_addr;
    int origin_count_i = origin_count;
    MPI_Datatype origin_datatype_i = origin_datatype;
    void *result_addr_i = result_addr->base_addr;
    int result_count_i = result_count;
    MPI_Datatype result_datatype_i = result_datatype;
    
    if (origin_addr_i == &MPIR_F08_MPI_BOTTOM) {
        origin_addr_i = MPI_BOTTOM;
    }
    
    if (origin_addr->rank != 0 && !CFI_is_contiguous(origin_addr)) {
        err = cdesc_create_datatype(origin_addr, origin_count, origin_datatype, &origin_datatype_i);
        if (err) return err;
        origin_count_i = 1;
    }
    
    if (result_addr_i == &MPIR_F08_MPI_BOTTOM) {
        result_addr_i = MPI_BOTTOM;
    }
    
    if (result_addr->rank != 0 && !CFI_is_contiguous(result_addr)) {
        err = cdesc_create_datatype(result_addr, result_count, result_datatype, &result_datatype_i);
        if (err) return err;
        result_count_i = 1;
    }
    
    err = MPI_Rget_accumulate(origin_addr_i, origin_count_i, origin_datatype_i, result_addr_i, result_count_i, result_datatype_i, target_rank, target_disp, target_count, target_datatype, op, win, request);
    
    if (origin_datatype_i != origin_datatype) PMPI_Type_free(&origin_datatype_i);
    if (result_datatype_i != result_datatype) PMPI_Type_free(&result_datatype_i);
    return err;
}

int MPIR_Rget_accumulate_cdesc_large(CFI_cdesc_t *origin_addr,
                                     MPI_Count origin_count,
                                     MPI_Datatype origin_datatype,
                                     CFI_cdesc_t *result_addr,
                                     MPI_Count result_count,
                                     MPI_Datatype result_datatype,
                                     int target_rank, MPI_Aint target_disp,
                                     MPI_Count target_count,
                                     MPI_Datatype target_datatype, MPI_Op op,
                                     MPI_Win win, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *origin_addr_i = origin_addr->base_addr;
    MPI_Count origin_count_i = origin_count;
    MPI_Datatype origin_datatype_i = origin_datatype;
    void *result_addr_i = result_addr->base_addr;
    MPI_Count result_count_i = result_count;
    MPI_Datatype result_datatype_i = result_datatype;
    
    if (origin_addr_i == &MPIR_F08_MPI_BOTTOM) {
        origin_addr_i = MPI_BOTTOM;
    }
    
    if (origin_addr->rank != 0 && !CFI_is_contiguous(origin_addr)) {
        err = cdesc_create_datatype(origin_addr, origin_count, origin_datatype, &origin_datatype_i);
        if (err) return err;
        origin_count_i = 1;
    }
    
    if (result_addr_i == &MPIR_F08_MPI_BOTTOM) {
        result_addr_i = MPI_BOTTOM;
    }
    
    if (result_addr->rank != 0 && !CFI_is_contiguous(result_addr)) {
        err = cdesc_create_datatype(result_addr, result_count, result_datatype, &result_datatype_i);
        if (err) return err;
        result_count_i = 1;
    }
    
    err = MPI_Rget_accumulate_c(origin_addr_i, origin_count_i, origin_datatype_i, result_addr_i, result_count_i, result_datatype_i, target_rank, target_disp, target_count, target_datatype, op, win, request);
    
    if (origin_datatype_i != origin_datatype) PMPI_Type_free(&origin_datatype_i);
    if (result_datatype_i != result_datatype) PMPI_Type_free(&result_datatype_i);
    return err;
}

int MPIR_Rput_cdesc(CFI_cdesc_t *origin_addr, int origin_count,
                    MPI_Datatype origin_datatype, int target_rank,
                    MPI_Aint target_disp, int target_count,
                    MPI_Datatype target_datatype, MPI_Win win,
                    MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *origin_addr_i = origin_addr->base_addr;
    int origin_count_i = origin_count;
    MPI_Datatype origin_datatype_i = origin_datatype;
    
    if (origin_addr_i == &MPIR_F08_MPI_BOTTOM) {
        origin_addr_i = MPI_BOTTOM;
    }
    
    if (origin_addr->rank != 0 && !CFI_is_contiguous(origin_addr)) {
        err = cdesc_create_datatype(origin_addr, origin_count, origin_datatype, &origin_datatype_i);
        if (err) return err;
        origin_count_i = 1;
    }
    
    err = MPI_Rput(origin_addr_i, origin_count_i, origin_datatype_i, target_rank, target_disp, target_count, target_datatype, win, request);
    
    if (origin_datatype_i != origin_datatype) PMPI_Type_free(&origin_datatype_i);
    return err;
}

int MPIR_Rput_cdesc_large(CFI_cdesc_t *origin_addr, MPI_Count origin_count,
                          MPI_Datatype origin_datatype, int target_rank,
                          MPI_Aint target_disp, MPI_Count target_count,
                          MPI_Datatype target_datatype, MPI_Win win,
                          MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *origin_addr_i = origin_addr->base_addr;
    MPI_Count origin_count_i = origin_count;
    MPI_Datatype origin_datatype_i = origin_datatype;
    
    if (origin_addr_i == &MPIR_F08_MPI_BOTTOM) {
        origin_addr_i = MPI_BOTTOM;
    }
    
    if (origin_addr->rank != 0 && !CFI_is_contiguous(origin_addr)) {
        err = cdesc_create_datatype(origin_addr, origin_count, origin_datatype, &origin_datatype_i);
        if (err) return err;
        origin_count_i = 1;
    }
    
    err = MPI_Rput_c(origin_addr_i, origin_count_i, origin_datatype_i, target_rank, target_disp, target_count, target_datatype, win, request);
    
    if (origin_datatype_i != origin_datatype) PMPI_Type_free(&origin_datatype_i);
    return err;
}

int MPIR_Win_attach_cdesc(MPI_Win win, CFI_cdesc_t *base, MPI_Aint size)
{
    int err = MPI_SUCCESS;
    void *base_i = base->base_addr;
    
    if (base_i == &MPIR_F08_MPI_BOTTOM) {
        base_i = MPI_BOTTOM;
    }
    
    err = MPI_Win_attach(win, base_i, size);
    
    return err;
}

int MPIR_Win_create_cdesc(CFI_cdesc_t *base, MPI_Aint size, int disp_unit,
                          MPI_Info info, MPI_Comm comm, MPI_Win *win)
{
    int err = MPI_SUCCESS;
    void *base_i = base->base_addr;
    
    if (base_i == &MPIR_F08_MPI_BOTTOM) {
        base_i = MPI_BOTTOM;
    }
    
    err = MPI_Win_create(base_i, size, disp_unit, info, comm, win);
    
    return err;
}

int MPIR_Win_create_cdesc_large(CFI_cdesc_t *base, MPI_Aint size,
                                MPI_Aint disp_unit, MPI_Info info,
                                MPI_Comm comm, MPI_Win *win)
{
    int err = MPI_SUCCESS;
    void *base_i = base->base_addr;
    
    if (base_i == &MPIR_F08_MPI_BOTTOM) {
        base_i = MPI_BOTTOM;
    }
    
    err = MPI_Win_create_c(base_i, size, disp_unit, info, comm, win);
    
    return err;
}

int MPIR_Win_detach_cdesc(MPI_Win win, CFI_cdesc_t *base)
{
    int err = MPI_SUCCESS;
    void *base_i = base->base_addr;
    
    if (base_i == &MPIR_F08_MPI_BOTTOM) {
        base_i = MPI_BOTTOM;
    }
    
    err = MPI_Win_detach(win, base_i);
    
    return err;
}

int MPIR_Stream_send_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                           int dest, int tag, MPI_Comm comm,
                           int source_stream_index, int dest_stream_index)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPIX_Stream_send(buf_i, count_i, datatype_i, dest, tag, comm, source_stream_index, dest_stream_index);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Stream_send_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                                 MPI_Datatype datatype, int dest, int tag,
                                 MPI_Comm comm, int source_stream_index,
                                 int dest_stream_index)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPIX_Stream_send_c(buf_i, count_i, datatype_i, dest, tag, comm, source_stream_index, dest_stream_index);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Stream_isend_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                            int dest, int tag, MPI_Comm comm,
                            int source_stream_index, int dest_stream_index,
                            MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPIX_Stream_isend(buf_i, count_i, datatype_i, dest, tag, comm, source_stream_index, dest_stream_index, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Stream_isend_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                                  MPI_Datatype datatype, int dest, int tag,
                                  MPI_Comm comm, int source_stream_index,
                                  int dest_stream_index, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPIX_Stream_isend_c(buf_i, count_i, datatype_i, dest, tag, comm, source_stream_index, dest_stream_index, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Stream_recv_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                           int source, int tag, MPI_Comm comm,
                           int source_stream_index, int dest_stream_index,
                           MPI_Status *status)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPIX_Stream_recv(buf_i, count_i, datatype_i, source, tag, comm, source_stream_index, dest_stream_index, status);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Stream_recv_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                                 MPI_Datatype datatype, int source, int tag,
                                 MPI_Comm comm, int source_stream_index,
                                 int dest_stream_index, MPI_Status *status)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPIX_Stream_recv_c(buf_i, count_i, datatype_i, source, tag, comm, source_stream_index, dest_stream_index, status);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Stream_irecv_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                            int source, int tag, MPI_Comm comm,
                            int source_stream_index, int dest_stream_index,
                            MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPIX_Stream_irecv(buf_i, count_i, datatype_i, source, tag, comm, source_stream_index, dest_stream_index, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Stream_irecv_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                                  MPI_Datatype datatype, int source, int tag,
                                  MPI_Comm comm, int source_stream_index,
                                  int dest_stream_index, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPIX_Stream_irecv_c(buf_i, count_i, datatype_i, source, tag, comm, source_stream_index, dest_stream_index, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Send_enqueue_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                            int dest, int tag, MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPIX_Send_enqueue(buf_i, count_i, datatype_i, dest, tag, comm);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Send_enqueue_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                                  MPI_Datatype datatype, int dest, int tag,
                                  MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPIX_Send_enqueue_c(buf_i, count_i, datatype_i, dest, tag, comm);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Recv_enqueue_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                            int source, int tag, MPI_Comm comm,
                            MPI_Status *status)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPIX_Recv_enqueue(buf_i, count_i, datatype_i, source, tag, comm, status);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Recv_enqueue_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                                  MPI_Datatype datatype, int source, int tag,
                                  MPI_Comm comm, MPI_Status *status)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPIX_Recv_enqueue_c(buf_i, count_i, datatype_i, source, tag, comm, status);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Isend_enqueue_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                             int dest, int tag, MPI_Comm comm,
                             MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPIX_Isend_enqueue(buf_i, count_i, datatype_i, dest, tag, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Isend_enqueue_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                                   MPI_Datatype datatype, int dest, int tag,
                                   MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPIX_Isend_enqueue_c(buf_i, count_i, datatype_i, dest, tag, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Irecv_enqueue_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                             int source, int tag, MPI_Comm comm,
                             MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPIX_Irecv_enqueue(buf_i, count_i, datatype_i, source, tag, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Irecv_enqueue_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                                   MPI_Datatype datatype, int source, int tag,
                                   MPI_Comm comm, MPI_Request *request)
{
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPIX_Irecv_enqueue_c(buf_i, count_i, datatype_i, source, tag, comm, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Allreduce_enqueue_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                                 int count, MPI_Datatype datatype, MPI_Op op,
                                 MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPIX_Allreduce_enqueue(sendbuf_i, recvbuf_i, count_i, datatype_i, op, comm);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_Allreduce_enqueue_cdesc_large(CFI_cdesc_t *sendbuf,
                                       CFI_cdesc_t *recvbuf, MPI_Count count,
                                       MPI_Datatype datatype, MPI_Op op,
                                       MPI_Comm comm)
{
    int err = MPI_SUCCESS;
    void *sendbuf_i = sendbuf->base_addr;
    void *recvbuf_i = recvbuf->base_addr;
    MPI_Count count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (sendbuf_i == &MPIR_F08_MPI_BOTTOM) {
        sendbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf_i == &MPIR_F08_MPI_BOTTOM) {
        recvbuf_i = MPI_BOTTOM;
    }
    
    if (recvbuf->rank != 0 && !CFI_is_contiguous(recvbuf)) {
        err = cdesc_create_datatype(recvbuf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPIX_Allreduce_enqueue_c(sendbuf_i, recvbuf_i, count_i, datatype_i, op, comm);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
}

int MPIR_File_iread_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                          MPI_Datatype datatype, MPI_Request *request)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_File_iread(fh, buf_i, count_i, datatype_i, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
#endif
}

int MPIR_File_iread_cdesc_large(MPI_File fh, CFI_cdesc_t *buf, MPI_Count count,
                                MPI_Datatype datatype, MPI_Request *request)
{
    return MPI_ERR_INTERN;
}

int MPIR_File_iread_all_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                              MPI_Datatype datatype, MPI_Request *request)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_File_iread_all(fh, buf_i, count_i, datatype_i, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
#endif
}

int MPIR_File_iread_all_cdesc_large(MPI_File fh, CFI_cdesc_t *buf,
                                    MPI_Count count, MPI_Datatype datatype,
                                    MPI_Request *request)
{
    return MPI_ERR_INTERN;
}

int MPIR_File_iread_at_cdesc(MPI_File fh, MPI_Offset offset, CFI_cdesc_t *buf,
                             int count, MPI_Datatype datatype,
                             MPI_Request *request)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_File_iread_at(fh, offset, buf_i, count_i, datatype_i, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
#endif
}

int MPIR_File_iread_at_cdesc_large(MPI_File fh, MPI_Offset offset,
                                   CFI_cdesc_t *buf, MPI_Count count,
                                   MPI_Datatype datatype, MPI_Request *request)
{
    return MPI_ERR_INTERN;
}

int MPIR_File_iread_at_all_cdesc(MPI_File fh, MPI_Offset offset,
                                 CFI_cdesc_t *buf, int count,
                                 MPI_Datatype datatype, MPI_Request *request)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_File_iread_at_all(fh, offset, buf_i, count_i, datatype_i, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
#endif
}

int MPIR_File_iread_at_all_cdesc_large(MPI_File fh, MPI_Offset offset,
                                       CFI_cdesc_t *buf, MPI_Count count,
                                       MPI_Datatype datatype,
                                       MPI_Request *request)
{
    return MPI_ERR_INTERN;
}

int MPIR_File_iread_shared_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                                 MPI_Datatype datatype, MPI_Request *request)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_File_iread_shared(fh, buf_i, count_i, datatype_i, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
#endif
}

int MPIR_File_iread_shared_cdesc_large(MPI_File fh, CFI_cdesc_t *buf,
                                       MPI_Count count, MPI_Datatype datatype,
                                       MPI_Request *request)
{
    return MPI_ERR_INTERN;
}

int MPIR_File_iwrite_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                           MPI_Datatype datatype, MPI_Request *request)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_File_iwrite(fh, buf_i, count_i, datatype_i, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
#endif
}

int MPIR_File_iwrite_cdesc_large(MPI_File fh, CFI_cdesc_t *buf, MPI_Count count,
                                 MPI_Datatype datatype, MPI_Request *request)
{
    return MPI_ERR_INTERN;
}

int MPIR_File_iwrite_all_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                               MPI_Datatype datatype, MPI_Request *request)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_File_iwrite_all(fh, buf_i, count_i, datatype_i, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
#endif
}

int MPIR_File_iwrite_all_cdesc_large(MPI_File fh, CFI_cdesc_t *buf,
                                     MPI_Count count, MPI_Datatype datatype,
                                     MPI_Request *request)
{
    return MPI_ERR_INTERN;
}

int MPIR_File_iwrite_at_cdesc(MPI_File fh, MPI_Offset offset, CFI_cdesc_t *buf,
                              int count, MPI_Datatype datatype,
                              MPI_Request *request)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_File_iwrite_at(fh, offset, buf_i, count_i, datatype_i, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
#endif
}

int MPIR_File_iwrite_at_cdesc_large(MPI_File fh, MPI_Offset offset,
                                    CFI_cdesc_t *buf, MPI_Count count,
                                    MPI_Datatype datatype,
                                    MPI_Request *request)
{
    return MPI_ERR_INTERN;
}

int MPIR_File_iwrite_at_all_cdesc(MPI_File fh, MPI_Offset offset,
                                  CFI_cdesc_t *buf, int count,
                                  MPI_Datatype datatype, MPI_Request *request)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_File_iwrite_at_all(fh, offset, buf_i, count_i, datatype_i, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
#endif
}

int MPIR_File_iwrite_at_all_cdesc_large(MPI_File fh, MPI_Offset offset,
                                        CFI_cdesc_t *buf, MPI_Count count,
                                        MPI_Datatype datatype,
                                        MPI_Request *request)
{
    return MPI_ERR_INTERN;
}

int MPIR_File_iwrite_shared_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                                  MPI_Datatype datatype, MPI_Request *request)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_File_iwrite_shared(fh, buf_i, count_i, datatype_i, request);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
#endif
}

int MPIR_File_iwrite_shared_cdesc_large(MPI_File fh, CFI_cdesc_t *buf,
                                        MPI_Count count, MPI_Datatype datatype,
                                        MPI_Request *request)
{
    return MPI_ERR_INTERN;
}

int MPIR_File_read_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                         MPI_Datatype datatype, MPI_Status *status)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_File_read(fh, buf_i, count_i, datatype_i, status);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
#endif
}

int MPIR_File_read_cdesc_large(MPI_File fh, CFI_cdesc_t *buf, MPI_Count count,
                               MPI_Datatype datatype, MPI_Status *status)
{
    return MPI_ERR_INTERN;
}

int MPIR_File_read_all_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                             MPI_Datatype datatype, MPI_Status *status)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_File_read_all(fh, buf_i, count_i, datatype_i, status);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
#endif
}

int MPIR_File_read_all_cdesc_large(MPI_File fh, CFI_cdesc_t *buf,
                                   MPI_Count count, MPI_Datatype datatype,
                                   MPI_Status *status)
{
    return MPI_ERR_INTERN;
}

int MPIR_File_read_all_begin_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                                   MPI_Datatype datatype)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_File_read_all_begin(fh, buf_i, count_i, datatype_i);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
#endif
}

int MPIR_File_read_all_begin_cdesc_large(MPI_File fh, CFI_cdesc_t *buf,
                    MPI_Count count, MPI_Datatype datatype)
{
    return MPI_ERR_INTERN;
}

int MPIR_File_read_all_end_cdesc(MPI_File fh, CFI_cdesc_t *buf,
                                 MPI_Status *status)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    err = MPI_File_read_all_end(fh, buf_i, status);
    
    return err;
#endif
}

int MPIR_File_read_at_cdesc(MPI_File fh, MPI_Offset offset, CFI_cdesc_t *buf,
                            int count, MPI_Datatype datatype,
                            MPI_Status *status)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_File_read_at(fh, offset, buf_i, count_i, datatype_i, status);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
#endif
}

int MPIR_File_read_at_cdesc_large(MPI_File fh, MPI_Offset offset,
                                  CFI_cdesc_t *buf, MPI_Count count,
                                  MPI_Datatype datatype, MPI_Status *status)
{
    return MPI_ERR_INTERN;
}

int MPIR_File_read_at_all_cdesc(MPI_File fh, MPI_Offset offset,
                                CFI_cdesc_t *buf, int count,
                                MPI_Datatype datatype, MPI_Status *status)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_File_read_at_all(fh, offset, buf_i, count_i, datatype_i, status);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
#endif
}

int MPIR_File_read_at_all_cdesc_large(MPI_File fh, MPI_Offset offset,
                                      CFI_cdesc_t *buf, MPI_Count count,
                                      MPI_Datatype datatype,
                                      MPI_Status *status)
{
    return MPI_ERR_INTERN;
}

int MPIR_File_read_at_all_begin_cdesc(MPI_File fh, MPI_Offset offset,
                                      CFI_cdesc_t *buf, int count,
                                      MPI_Datatype datatype)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_File_read_at_all_begin(fh, offset, buf_i, count_i, datatype_i);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
#endif
}

int MPIR_File_read_at_all_begin_cdesc_large(MPI_File fh, MPI_Offset offset,
                    CFI_cdesc_t *buf, MPI_Count count, MPI_Datatype datatype)
{
    return MPI_ERR_INTERN;
}

int MPIR_File_read_at_all_end_cdesc(MPI_File fh, CFI_cdesc_t *buf,
                                    MPI_Status *status)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    err = MPI_File_read_at_all_end(fh, buf_i, status);
    
    return err;
#endif
}

int MPIR_File_read_ordered_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                                 MPI_Datatype datatype, MPI_Status *status)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_File_read_ordered(fh, buf_i, count_i, datatype_i, status);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
#endif
}

int MPIR_File_read_ordered_cdesc_large(MPI_File fh, CFI_cdesc_t *buf,
                                       MPI_Count count, MPI_Datatype datatype,
                                       MPI_Status *status)
{
    return MPI_ERR_INTERN;
}

int MPIR_File_read_ordered_begin_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                                       MPI_Datatype datatype)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_File_read_ordered_begin(fh, buf_i, count_i, datatype_i);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
#endif
}

int MPIR_File_read_ordered_begin_cdesc_large(MPI_File fh, CFI_cdesc_t *buf,
                    MPI_Count count, MPI_Datatype datatype)
{
    return MPI_ERR_INTERN;
}

int MPIR_File_read_ordered_end_cdesc(MPI_File fh, CFI_cdesc_t *buf,
                                     MPI_Status *status)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    err = MPI_File_read_ordered_end(fh, buf_i, status);
    
    return err;
#endif
}

int MPIR_File_read_shared_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                                MPI_Datatype datatype, MPI_Status *status)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_File_read_shared(fh, buf_i, count_i, datatype_i, status);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
#endif
}

int MPIR_File_read_shared_cdesc_large(MPI_File fh, CFI_cdesc_t *buf,
                                      MPI_Count count, MPI_Datatype datatype,
                                      MPI_Status *status)
{
    return MPI_ERR_INTERN;
}

int MPIR_File_write_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                          MPI_Datatype datatype, MPI_Status *status)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_File_write(fh, buf_i, count_i, datatype_i, status);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
#endif
}

int MPIR_File_write_cdesc_large(MPI_File fh, CFI_cdesc_t *buf, MPI_Count count,
                                MPI_Datatype datatype, MPI_Status *status)
{
    return MPI_ERR_INTERN;
}

int MPIR_File_write_all_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                              MPI_Datatype datatype, MPI_Status *status)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_File_write_all(fh, buf_i, count_i, datatype_i, status);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
#endif
}

int MPIR_File_write_all_cdesc_large(MPI_File fh, CFI_cdesc_t *buf,
                                    MPI_Count count, MPI_Datatype datatype,
                                    MPI_Status *status)
{
    return MPI_ERR_INTERN;
}

int MPIR_File_write_all_begin_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                                    MPI_Datatype datatype)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_File_write_all_begin(fh, buf_i, count_i, datatype_i);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
#endif
}

int MPIR_File_write_all_begin_cdesc_large(MPI_File fh, CFI_cdesc_t *buf,
                    MPI_Count count, MPI_Datatype datatype)
{
    return MPI_ERR_INTERN;
}

int MPIR_File_write_all_end_cdesc(MPI_File fh, CFI_cdesc_t *buf,
                                  MPI_Status *status)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    err = MPI_File_write_all_end(fh, buf_i, status);
    
    return err;
#endif
}

int MPIR_File_write_at_cdesc(MPI_File fh, MPI_Offset offset, CFI_cdesc_t *buf,
                             int count, MPI_Datatype datatype,
                             MPI_Status *status)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_File_write_at(fh, offset, buf_i, count_i, datatype_i, status);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
#endif
}

int MPIR_File_write_at_cdesc_large(MPI_File fh, MPI_Offset offset,
                                   CFI_cdesc_t *buf, MPI_Count count,
                                   MPI_Datatype datatype, MPI_Status *status)
{
    return MPI_ERR_INTERN;
}

int MPIR_File_write_at_all_cdesc(MPI_File fh, MPI_Offset offset,
                                 CFI_cdesc_t *buf, int count,
                                 MPI_Datatype datatype, MPI_Status *status)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_File_write_at_all(fh, offset, buf_i, count_i, datatype_i, status);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
#endif
}

int MPIR_File_write_at_all_cdesc_large(MPI_File fh, MPI_Offset offset,
                                       CFI_cdesc_t *buf, MPI_Count count,
                                       MPI_Datatype datatype,
                                       MPI_Status *status)
{
    return MPI_ERR_INTERN;
}

int MPIR_File_write_at_all_begin_cdesc(MPI_File fh, MPI_Offset offset,
                                       CFI_cdesc_t *buf, int count,
                                       MPI_Datatype datatype)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_File_write_at_all_begin(fh, offset, buf_i, count_i, datatype_i);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
#endif
}

int MPIR_File_write_at_all_begin_cdesc_large(MPI_File fh, MPI_Offset offset,
                    CFI_cdesc_t *buf, MPI_Count count, MPI_Datatype datatype)
{
    return MPI_ERR_INTERN;
}

int MPIR_File_write_at_all_end_cdesc(MPI_File fh, CFI_cdesc_t *buf,
                                     MPI_Status *status)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    err = MPI_File_write_at_all_end(fh, buf_i, status);
    
    return err;
#endif
}

int MPIR_File_write_ordered_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                                  MPI_Datatype datatype, MPI_Status *status)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_File_write_ordered(fh, buf_i, count_i, datatype_i, status);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
#endif
}

int MPIR_File_write_ordered_cdesc_large(MPI_File fh, CFI_cdesc_t *buf,
                                        MPI_Count count, MPI_Datatype datatype,
                                        MPI_Status *status)
{
    return MPI_ERR_INTERN;
}

int MPIR_File_write_ordered_begin_cdesc(MPI_File fh, CFI_cdesc_t *buf,
                                        int count, MPI_Datatype datatype)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_File_write_ordered_begin(fh, buf_i, count_i, datatype_i);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
#endif
}

int MPIR_File_write_ordered_begin_cdesc_large(MPI_File fh, CFI_cdesc_t *buf,
                    MPI_Count count, MPI_Datatype datatype)
{
    return MPI_ERR_INTERN;
}

int MPIR_File_write_ordered_end_cdesc(MPI_File fh, CFI_cdesc_t *buf,
                                      MPI_Status *status)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    err = MPI_File_write_ordered_end(fh, buf_i, status);
    
    return err;
#endif
}

int MPIR_File_write_shared_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                                 MPI_Datatype datatype, MPI_Status *status)
{
#ifndef HAVE_ROMIO
    return MPI_ERR_INTERN;
#else
    int err = MPI_SUCCESS;
    void *buf_i = buf->base_addr;
    int count_i = count;
    MPI_Datatype datatype_i = datatype;
    
    if (buf_i == &MPIR_F08_MPI_BOTTOM) {
        buf_i = MPI_BOTTOM;
    }
    
    if (buf->rank != 0 && !CFI_is_contiguous(buf)) {
        err = cdesc_create_datatype(buf, count, datatype, &datatype_i);
        if (err) return err;
        count_i = 1;
    }
    
    err = MPI_File_write_shared(fh, buf_i, count_i, datatype_i, status);
    
    if (datatype_i != datatype) PMPI_Type_free(&datatype_i);
    return err;
#endif
}

int MPIR_File_write_shared_cdesc_large(MPI_File fh, CFI_cdesc_t *buf,
                                       MPI_Count count, MPI_Datatype datatype,
                                       MPI_Status *status)
{
    return MPI_ERR_INTERN;
}

int MPIR_F_sync_reg_cdesc(CFI_cdesc_t *buf)
{
    int err = MPI_SUCCESS;
    return err;
}
