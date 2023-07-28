/* -*- Mode: C; c-basic-offset:4 ; -*- */
/* Copyright (c) 2001-2023, The Ohio State University. All rights
 * reserved.
 *
 * This file is part of the MVAPICH software package developed by the
 * team members of The Ohio State University's Network-Based Computing
 * Laboratory (NBCL), headed by Professor Dhabaleswar K. (DK) Panda.
 *
 * For detailed copyright and licensing information, please refer to the
 * copyright file COPYRIGHT in the top level MVAPICH directory.
 */
/*
 *
 *  (C) 2001 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

#include "mpiimpl.h"
#include <unistd.h>
#include "mvp_coll_shmem.h"
#include <unistd.h>

extern unsigned long long PVAR_COUNTER_mvp_coll_exscan_algo;

int MPIR_Exscan_MVP(const void *sendbuf, void *recvbuf, int count,
                    MPI_Datatype datatype, MPI_Op op, MPIR_Comm *comm_ptr,
                    MPIR_Errflag_t *errflag)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_T_PVAR_COUNTER_INC(MVP, mvp_coll_exscan_algo, 1);

#ifdef _ENABLE_CUDA_
    int recv_mem_type = 0;
    int send_mem_type = 0;
    char *recv_host_buf = NULL;
    char *send_host_buf = NULL;
    char *temp_recvbuf = recvbuf;
    const char *temp_sendbuf = sendbuf;
    int stride = 0;
    MPI_Aint true_lb, true_extent, extent;
    MPIR_Type_get_true_extent_impl(datatype, &true_lb, &true_extent);
    MPIR_Datatype_get_extent_macro(datatype, extent);
    stride = count * MPL_MAX(extent, true_extent);

    if (mvp_enable_device) {
        recv_mem_type = is_device_buffer(recvbuf);
        if (sendbuf != MPI_IN_PLACE) {
            send_mem_type = is_device_buffer(sendbuf);
        }
    }

    if (mvp_enable_device && send_mem_type) {
        send_host_buf = (char *)MPL_malloc(stride);
        MVP_MPID_Memcpy_Device((void *)send_host_buf, (void *)sendbuf, stride,
                               deviceMemcpyDeviceToHost);
        sendbuf = send_host_buf;
    }

    if (mvp_enable_device && recv_mem_type) {
        recv_host_buf = (char *)MPL_malloc(stride);
        MVP_MPID_Memcpy_Device((void *)recv_host_buf, (void *)recvbuf, stride,
                               deviceMemcpyDeviceToHost);
        recvbuf = recv_host_buf;
    }
#endif

    mpi_errno =
        MPIR_Exscan(sendbuf, recvbuf, count, datatype, op, comm_ptr, errflag);
    MPIR_ERR_CHECK(mpi_errno);
#ifdef _ENABLE_CUDA_
    if (mvp_enable_device && recv_mem_type) {
        recvbuf = temp_recvbuf;
        MVP_MPID_Memcpy_Device((void *)recvbuf, (void *)recv_host_buf, stride,
                               deviceMemcpyHostToDevice);
    }
    if (mvp_enable_device && recv_mem_type) {
        if (recv_host_buf) {
            MPL_free(recv_host_buf);
            recv_host_buf = NULL;
        }
    }
    if (mvp_enable_device && send_mem_type) {
        sendbuf = temp_sendbuf;
        if (send_host_buf) {
            MPL_free(send_host_buf);
            send_host_buf = NULL;
        }
    }
#endif
    MPIR_ERR_CHECK(mpi_errno);

fn_exit:
    return mpi_errno;
fn_fail:
    goto fn_exit;
}
