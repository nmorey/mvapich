/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "mpidimpl.h"
#include "ipc_types.h"

static int get_iovs(void *buf, MPI_Aint count, MPI_Datatype datatype, MPI_Aint data_sz,
                    struct iovec **iovs_out, MPI_Aint * len_out);
static int copy_iovs(pid_t pid, MPI_Aint src_data_sz,
                     struct iovec *src_iovs, MPI_Aint src_iov_len,
                     struct iovec *dst_iovs, MPI_Aint dst_iov_len, int dir);

enum cma_dir { CMA_DIRECTION__READ, CMA_DIRECTION__WRITE };

MPL_STATIC_INLINE_PREFIX int MPIDI_CMAI_handle_gpu_buf(
    void *buf, MPI_Aint src_data_sz, void **tmp_buf)
{
    /* check for a GPU recv buffer and allocate temp bufs */
    if (MPIR_CVAR_ENABLE_GPU) {
        MPL_pointer_attr_t attr;
        MPIR_GPU_query_pointer_attr(buf, &attr);
        if (MPL_gpu_attr_is_dev(&attr)) {
            *tmp_buf = MPL_malloc(src_data_sz, MPL_MEM_OTHER);
        }
    }
    return MPI_SUCCESS;
}

int MPIDI_CMA_copy_data(MPIDI_IPC_hdr * ipc_hdr, MPIR_Request * rreq, MPI_Aint src_data_sz)
{
    int mpi_errno = MPI_SUCCESS;

    /* local iovs */
    struct iovec *dst_iovs;
    MPI_Aint dst_iov_len;
    void *tmp_buf = NULL;

    mpi_errno = MPIDI_CMAI_handle_gpu_buf(MPIDIG_REQUEST(rreq, buffer),
                                          src_data_sz, &tmp_buf);
    MPIR_ERR_CHECK(mpi_errno);

    if (!tmp_buf) {
        mpi_errno = get_iovs(MPIDIG_REQUEST(rreq, buffer),
                             MPIDIG_REQUEST(rreq, count),
                             MPIDIG_REQUEST(rreq, datatype), -1, &dst_iovs,
                             &dst_iov_len);
    } else {
        mpi_errno = get_iovs(tmp_buf, src_data_sz, MPI_BYTE, -1, &dst_iovs,
                             &dst_iov_len);
    }
    MPIR_ERR_CHECK(mpi_errno);

    /* remote iovs */
    struct iovec static_src_iov;
    struct iovec *src_iovs;
    MPI_Aint src_iov_len;

    if (ipc_hdr->is_contig) {
        src_iovs = &static_src_iov;
        src_iov_len = 1;

        src_iovs[0].iov_base = (void *) ipc_hdr->ipc_handle.cma.vaddr;
        src_iovs[0].iov_len = src_data_sz;
    } else {
        void *flattened_type = ipc_hdr + 1;
        MPIR_Datatype *dt = (MPIR_Datatype *) MPIR_Handle_obj_alloc(&MPIR_Datatype_mem);
        MPIR_Assert(dt);
        mpi_errno = MPIR_Typerep_unflatten(dt, flattened_type);
        MPIR_ERR_CHECK(mpi_errno);

        mpi_errno = get_iovs((void *) ipc_hdr->ipc_handle.cma.vaddr, ipc_hdr->count, dt->handle,
                             src_data_sz, &src_iovs, &src_iov_len);
        MPIR_ERR_CHECK(mpi_errno);

        MPIR_Datatype_free(dt);
    }

    /* process_vm_readv */
    pid_t src_pid = ipc_hdr->ipc_handle.cma.pid;
    mpi_errno = copy_iovs(src_pid, src_data_sz, src_iovs, src_iov_len, dst_iovs,
                          dst_iov_len, CMA_DIRECTION__READ);
    MPIR_ERR_CHECK(mpi_errno);

    if (NULL != tmp_buf) {
        MPI_Aint actual_unpack_bytes;
        mpi_errno = MPIR_Typerep_unpack(tmp_buf, src_data_sz,
                                        MPIDIG_REQUEST(rreq, buffer),
                                        MPIDIG_REQUEST(rreq, count),
                                        MPIDIG_REQUEST(rreq, datatype), 0,
                                        &actual_unpack_bytes,
                                        MPIR_TYPEREP_FLAG_NONE);
        MPIR_ERR_CHECK(mpi_errno);
        if (actual_unpack_bytes < src_data_sz) {
            MPIR_ERR_SETANDJUMP(mpi_errno, MPI_ERR_TYPE, "**dtypemismatch");
        }
    }

  fn_exit:
    if (src_iovs != &static_src_iov) {
        MPL_free(src_iovs);
    }
    MPL_free(dst_iovs);

    if (NULL != tmp_buf) {
        MPL_free(tmp_buf);
    }
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIDI_CMA_copy_data_rput(MPIDI_IPC_hdr *ipc_hdr, MPIR_Request *sreq,
                             MPI_Aint src_data_sz)
{
    int mpi_errno = MPI_SUCCESS;

    /* remote iovs */
    struct iovec static_dst_iov;
    struct iovec *dst_iovs;
    MPI_Aint dst_iov_len;

    /* local iovs */
    struct iovec *src_iovs;
    MPI_Aint src_iov_len;
    mpi_errno =
        get_iovs(MPIDIG_REQUEST(sreq, buffer), MPIDIG_REQUEST(sreq, count),
                 MPIDIG_REQUEST(sreq, datatype), -1, &src_iovs, &src_iov_len);
    MPIR_ERR_CHECK(mpi_errno);

    if (ipc_hdr->is_contig) {
        dst_iovs = &static_dst_iov;
        dst_iov_len = 1;

        dst_iovs[0].iov_base = (void *)ipc_hdr->ipc_handle.cma.vaddr;
        dst_iovs[0].iov_len = src_data_sz;
    } else {
        void *flattened_type = ipc_hdr + 1;
        MPIR_Datatype *dt =
            (MPIR_Datatype *)MPIR_Handle_obj_alloc(&MPIR_Datatype_mem);
        MPIR_Assert(dt);
        mpi_errno = MPIR_Typerep_unflatten(dt, flattened_type);
        MPIR_ERR_CHECK(mpi_errno);

        mpi_errno = get_iovs((void *)ipc_hdr->ipc_handle.cma.vaddr,
                             ipc_hdr->count, dt->handle, src_data_sz, &dst_iovs,
                             &dst_iov_len);
        MPIR_ERR_CHECK(mpi_errno);

        MPIR_Datatype_free(dt);
    }

    /* process_vm_writev */
    pid_t src_pid = ipc_hdr->ipc_handle.cma.pid;
    mpi_errno = copy_iovs(src_pid, src_data_sz, src_iovs, src_iov_len, dst_iovs,
                          dst_iov_len, CMA_DIRECTION__WRITE);
    MPIR_ERR_CHECK(mpi_errno);

  fn_exit:
    if (dst_iovs != &static_dst_iov) {
        MPL_free(dst_iovs);
    }
    MPL_free(src_iovs);

    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIDI_CMA_copy_data_coop(MPIDI_IPC_hdr *ipc_hdr, MPIR_Request *req,
                             MPI_Aint src_data_sz, int src_dst)
{
    int mpi_errno = MPI_SUCCESS;

    /* remote iovs */
    struct iovec static_remote_iov;
    struct iovec *remote_iovs;
    MPI_Aint remote_iov_len;

    /* local iovs */
    struct iovec *local_iovs;
    MPI_Aint local_iov_len;

    /* copy direction - write/rput for src, read/rget for dst */
    int copy_dir = src_dst ? CMA_DIRECTION__READ : CMA_DIRECTION__WRITE;

    /* divide buffer elements */
    MPI_Aint rput_count = (MPIDIG_REQUEST(req, count)) / 2;
    MPI_Aint rget_count = MPIDIG_REQUEST(req, count) - rput_count;

    /* calculate half size */
    MPI_Aint rput_remote_sz = src_data_sz / 2;
    MPI_Aint rget_remote_sz = src_data_sz - rput_count;
    MPI_Aint remote_sz = src_dst ? rget_remote_sz : rput_remote_sz;

    /* offset into local buffer that a proccess will operate on */
    void *rput_buf = MPIDIG_REQUEST(req, buffer);
    void *rget_buf = NULL;
    /* where to start local iovs */
    void *local_buf = NULL;
    MPI_Aint local_count;
    /* where to start remote iovs */
    void *remote_buf = NULL;
    MPI_Aint remote_count;

    pid_t tgt_pid = ipc_hdr->ipc_handle.cma.pid;

    /* size of first half of message in bytes */
    MPI_Aint len, rput_bytes;
    mpi_errno = MPIR_Typerep_iov_len(rput_count, MPIDIG_REQUEST(req, datatype),
                                     -1, &len, &rput_bytes);

    if (!src_dst) {
        /* sender/rput side - first half of message */
        local_buf = rput_buf;
        local_count = rput_count;
        remote_buf = (void *)ipc_hdr->ipc_handle.cma.vaddr;
    } else {
        /* reciever/rget side - second half of message */
        rget_buf = MPIDIG_REQUEST(req, buffer) + rput_bytes;
        local_buf = rget_buf;
        local_count = rget_count;
        remote_buf = (void *)ipc_hdr->ipc_handle.cma.vaddr + rput_bytes;
    }

    /* local / remote abstraction */
    /* get local iovs */
    mpi_errno =
        get_iovs(local_buf, local_count, MPIDIG_REQUEST(req, datatype), -1,
                 &local_iovs, &local_iov_len);
    MPIR_ERR_CHECK(mpi_errno);

    /* get remote iovs */
    if (ipc_hdr->is_contig) {
        remote_iovs = &static_remote_iov;
        remote_iov_len = 1;

        remote_iovs[0].iov_base = remote_buf;
        remote_iovs[0].iov_len = remote_sz;
    } else {
        /* divide buffer elements */
        void *flattened_type = ipc_hdr + 1;
        MPI_Aint rput_remote_count = ipc_hdr->count / 2;
        MPI_Aint rget_remote_count = ipc_hdr->count - rput_remote_count;
        MPI_Aint remote_count = src_dst ? rget_remote_count : rput_remote_count;
        MPIR_Datatype *dt =
            (MPIR_Datatype *)MPIR_Handle_obj_alloc(&MPIR_Datatype_mem);
        MPIR_Assert(dt);
        mpi_errno = MPIR_Typerep_unflatten(dt, flattened_type);
        MPIR_ERR_CHECK(mpi_errno);

        mpi_errno = get_iovs(remote_buf, remote_count, dt->handle,
                             src_data_sz, &remote_iovs, &remote_iov_len);
        MPIR_ERR_CHECK(mpi_errno);

        MPIR_Datatype_free(dt);
    }

    /* process_vm_writev/process_vm_readv */
    if (!src_dst) {
        mpi_errno = copy_iovs(tgt_pid, remote_sz, local_iovs, local_iov_len,
                              remote_iovs, remote_iov_len, copy_dir);
    } else {
        mpi_errno = copy_iovs(tgt_pid, remote_sz, remote_iovs, remote_iov_len,
                              local_iovs, local_iov_len, copy_dir);
    }

    MPIR_ERR_CHECK(mpi_errno);

  fn_exit:
    if (remote_iovs != &static_remote_iov) {
        MPL_free(remote_iovs);
    }
    MPL_free(local_iovs);

    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

static int get_iovs(void *buf, MPI_Aint count, MPI_Datatype datatype, MPI_Aint data_sz,
                    struct iovec **iovs_out, MPI_Aint * len_out)
{
    int mpi_errno = MPI_SUCCESS;

    struct iovec *iovs;
    MPI_Aint len, actual;

    mpi_errno = MPIR_Typerep_iov_len(count, datatype, data_sz, &len, &actual);
    MPIR_ERR_CHECK(mpi_errno);

    iovs = MPL_malloc(len * sizeof(struct iovec), MPL_MEM_OTHER);
    MPIR_Assert(iovs);

    mpi_errno = MPIR_Typerep_to_iov_offset(buf, count, datatype, 0, iovs, len, &actual);
    MPIR_ERR_CHECK(mpi_errno);

    *iovs_out = iovs;
    *len_out = len;

  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

/* Potentially src_iov_len or dst_iov_len is bigger than IOV_MAX,
 * thus, we can just call a single process_vm_readv */
static int copy_iovs(pid_t src_pid, MPI_Aint src_data_sz,
                     struct iovec *src_iovs, MPI_Aint src_iov_len,
                     struct iovec *dst_iovs, MPI_Aint dst_iov_len,
                     int dir)
{
    int mpi_errno = MPI_SUCCESS;

    MPI_Aint i_src = 0, i_dst = 0;
    MPI_Aint cur_offset = 0;
    bool got_err_truncate = false;

/* Apparently process_vm_readv can't handle iov segment larger than 0x7ffff000 */
/* FIXME: confirm and find reference */
#define MAX_IOV_SEG_SIZE 0x7ffff000
    while (i_src < src_iov_len && i_dst < dst_iov_len) {
        MPI_Aint n_src, n_dst;
        MPI_Aint exp_data_sz;
        /* in case we result in partial iov */
        MPI_Aint remain_src_len, remain_dst_len;

        remain_src_len = 0;
        remain_dst_len = 0;

        n_src = src_iov_len - i_src;
        n_dst = dst_iov_len - i_dst;
        exp_data_sz = src_data_sz - cur_offset;

        if (n_src <= IOV_MAX && n_dst <= IOV_MAX && exp_data_sz <= MAX_IOV_SEG_SIZE) {
            MPI_Aint cnt_dst = 0;
            for (int i = 0; i < n_dst; i++) {
                cnt_dst += dst_iovs[i_dst + i].iov_len;
            }

            if (cnt_dst < exp_data_sz) {
                /* overflow */
                exp_data_sz = cnt_dst;
                MPI_Aint cnt_src = 0;
                for (int i = 0; i < n_src; i++) {
                    cnt_src += src_iovs[i_src + i].iov_len;
                    if (cnt_src >= exp_data_sz) {
                        MPI_Aint remain_len = cnt_src - exp_data_sz;
                        src_iovs[i_src + i].iov_len -= remain_len;
                        n_src = i + 1;
                        break;
                    }
                }
                /* signal MPI_ERR_TRUNCATE */
                got_err_truncate = true;
            } else if (cnt_dst > exp_data_sz) {
                cnt_dst = 0;
                for (int i = 0; i < n_dst; i++) {
                    cnt_dst += dst_iovs[i_dst + i].iov_len;
                    if (cnt_dst >= exp_data_sz) {
                        MPI_Aint remain_len = cnt_dst - exp_data_sz;
                        dst_iovs[i_dst + i].iov_len -= remain_len;
                        n_dst = i + 1;
                    }
                }
            }
        } else {
            if (n_src > IOV_MAX) {
                n_src = IOV_MAX;
            }
            if (n_dst > IOV_MAX) {
                n_dst = IOV_MAX;
            }

            MPI_Aint cnt_src = 0;
            for (int i = 0; i < n_src; i++) {
                cnt_src += src_iovs[i_src + i].iov_len;
            }
            MPI_Aint cnt_dst = 0;
            for (int i = 0; i < n_dst; i++) {
                cnt_dst += dst_iovs[i_dst + i].iov_len;
            }
            exp_data_sz = MPL_MIN(MAX_IOV_SEG_SIZE, MPL_MIN(cnt_src, cnt_dst));

            if (cnt_src > exp_data_sz) {
                cnt_src = 0;
                for (int i = 0; i < n_src; i++) {
                    cnt_src += src_iovs[i_src + i].iov_len;
                    if (cnt_src >= exp_data_sz) {
                        MPI_Aint remain_len = cnt_src - exp_data_sz;
                        src_iovs[i_src + i].iov_len -= remain_len;
                        n_src = i + 1;
                        remain_src_len = remain_len;
                        break;
                    }
                }
            }
            if (cnt_dst > exp_data_sz) {
                cnt_dst = 0;
                for (int i = 0; i < n_dst; i++) {
                    cnt_dst += dst_iovs[i_dst + i].iov_len;
                    if (cnt_dst >= exp_data_sz) {
                        MPI_Aint remain_len = cnt_dst - exp_data_sz;
                        dst_iovs[i_dst + i].iov_len -= remain_len;
                        n_dst = i + 1;
                        remain_dst_len = remain_len;
                        break;
                    }
                }
            }
        }

        MPI_Aint cnt;
        if (CMA_DIRECTION__READ == dir) {
            cnt = process_vm_readv(src_pid, dst_iovs + i_dst, n_dst,
                                   src_iovs + i_src, n_src, 0);
            MPIR_ERR_CHKANDJUMP1(cnt == -1, mpi_errno, MPI_ERR_OTHER,
                                 "**cmaread", "**cmaread %d", errno);
            MPIR_ERR_CHKANDJUMP2(cnt != exp_data_sz, mpi_errno, MPI_ERR_OTHER,
                                 "**cmadata", "**cmadata %d %d", (int)cnt,
                                 (int)exp_data_sz);
        } else if (CMA_DIRECTION__WRITE == dir) {
            cnt = process_vm_writev(src_pid, src_iovs + i_src, n_src,
                                    dst_iovs + i_dst, n_dst, 0);
            MPIR_ERR_CHKANDJUMP1(cnt == -1, mpi_errno, MPI_ERR_OTHER,
                                 "**cmawrite", "**cmawrite %d", errno);
            MPIR_ERR_CHKANDJUMP2(cnt != exp_data_sz, mpi_errno, MPI_ERR_OTHER,
                                 "**cmadata", "**cmadata %d %d", (int)cnt,
                                 (int)exp_data_sz);
        } else {
            fprintf(stderr, "invalid direction\n");
            cnt = -1;
        }
        MPIR_ERR_CHKANDJUMP1(cnt == -1, mpi_errno, MPI_ERR_OTHER,
                             "**flag", "**flag %d", errno);

        cur_offset += cnt;
        i_src += n_src;
        i_dst += n_dst;

        if (remain_src_len > 0) {
            i_src--;
            /* adjust the remaining iov */
            src_iovs[i_src].iov_base = (char *) src_iovs[i_src].iov_base + src_iovs[i_src].iov_len;
            src_iovs[i_src].iov_len = remain_src_len;
        }
        if (remain_dst_len > 0) {
            i_dst--;
            /* adjust the remaining iov */
            dst_iovs[i_dst].iov_base = (char *) dst_iovs[i_dst].iov_base + dst_iovs[i_dst].iov_len;
            dst_iovs[i_dst].iov_len = remain_dst_len;
        }
        if (got_err_truncate) {
            /* This signals truncation error */
            /* FIXME: set specific error "**truncate %d %d %d %d" */
            MPIR_ERR_SETANDJUMP(mpi_errno, MPI_ERR_TRUNCATE, "**truncate");
        }
    }

  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}
