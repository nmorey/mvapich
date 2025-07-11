/*
 * Copyright (c) 2017-2020 Intel Corporation. All rights reserved.
 * (C) Copyright 2020 Hewlett Packard Enterprise Development LP
 *
 * This software is available to you under a choice of one of two
 * licenses.  You may choose to be licensed under the terms of the GNU
 * General Public License (GPL) Version 2, available from the file
 * COPYING in the main directory of this source tree, or the
 * BSD license below:
 *
 *     Redistribution and use in source and binary forms, with or
 *     without modification, are permitted provided that the following
 *     conditions are met:
 *
 *      - Redistributions of source code must retain the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer.
 *
 *      - Redistributions in binary form must reproduce the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer in the documentation and/or other materials
 *        provided with the distribution.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "ucr.h"

static ssize_t ucr_ep_rma_reg_iov(struct ucr_ep *ucr_ep,
                                  const struct iovec *msg_iov, void **desc,
                                  void **desc_storage, size_t iov_count,
                                  uint64_t access, struct ucr_tx_buf *rma_buf)
{
    size_t i, ret;

    if (!ucr_ep->msg_mr_local)
        return FI_SUCCESS;

    if (!ucr_ep->rdm_mr_local) {
        ret = ucr_msg_mr_regv(ucr_ep, msg_iov, iov_count, SIZE_MAX, access,
                              rma_buf->rma.mr);
        if (OFI_UNLIKELY(ret))
            return ret;

        for (i = 0; i < iov_count; i++)
            desc_storage[i] = fi_mr_desc(rma_buf->rma.mr[i]);
        rma_buf->rma.count = (uint8_t)iov_count;
    } else {
        for (i = 0; i < iov_count; i++)
            desc_storage[i] = fi_mr_desc(((struct ucr_mr *)desc[i])->msg_mr);
    }
    return FI_SUCCESS;
}

static ssize_t ucr_ep_rma_common(
    struct ucr_ep *ucr_ep, const struct fi_msg_rma *msg, uint64_t flags,
    ssize_t (*rma_msg)(struct fid_ep *ep_fid, const struct fi_msg_rma *msg,
                       uint64_t flags),
    uint64_t comp_flags)
{
    struct ucr_tx_buf *rma_buf;
    struct fi_msg_rma msg_rma = *msg;
    struct ucr_conn *ucr_conn;
    void *mr_desc[UCR_IOV_LIMIT] = {0};
    ssize_t ret;

    assert(msg->rma_iov_count <= ucr_ep->ucr_info->tx_attr->rma_iov_limit);

    ofi_genlock_lock(&ucr_ep->util_ep.lock);

    ret = ucr_get_conn(ucr_ep, msg->addr, &ucr_conn);
    if (ret)
        goto unlock;

    rma_buf = ucr_get_tx_buf(ucr_ep);
    if (!rma_buf) {
        ret = -FI_EAGAIN;
        goto unlock;
    }

    rma_buf->hdr.state = UCR_RMA;
    rma_buf->pkt.ctrl_hdr.type = ucr_ctrl_eager;
    rma_buf->app_context = msg->context;
    rma_buf->flags = flags;

    ret = ucr_ep_rma_reg_iov(ucr_ep, msg_rma.msg_iov, msg_rma.desc, mr_desc,
                             msg_rma.iov_count,
                             comp_flags & (FI_WRITE | FI_READ), rma_buf);
    if (OFI_UNLIKELY(ret))
        goto release;

    msg_rma.desc = mr_desc;
    msg_rma.context = rma_buf;

    ret = rma_msg(ucr_conn->msg_ep, &msg_rma, flags);
    if (!ret)
        goto unlock;

    if ((ucr_ep->msg_mr_local) && (!ucr_ep->rdm_mr_local))
        ucr_msg_mr_closev(rma_buf->rma.mr, rma_buf->rma.count);
release:
    ucr_free_tx_buf(ucr_ep, rma_buf);
unlock:
    ofi_genlock_unlock(&ucr_ep->util_ep.lock);
    return ret;
}

static ssize_t ucr_ep_readmsg(struct fid_ep *ep_fid,
                              const struct fi_msg_rma *msg, uint64_t flags)
{
    struct ucr_ep *ucr_ep;

    ucr_ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    return ucr_ep_rma_common(ucr_ep, msg, flags | ucr_ep->util_ep.tx_msg_flags,
                             fi_readmsg, FI_READ);
}

static ssize_t ucr_ep_readv(struct fid_ep *ep_fid, const struct iovec *iov,
                            void **desc, size_t count, fi_addr_t src_addr,
                            uint64_t addr, uint64_t key, void *context)
{
    struct ucr_ep *ucr_ep =
        container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    struct fi_rma_iov rma_iov = {
        .addr = addr,
        .len = ofi_total_iov_len(iov, count),
        .key = key,
    };
    struct fi_msg_rma msg = {
        .msg_iov = iov,
        .desc = desc,
        .iov_count = count,
        .addr = src_addr,
        .rma_iov = &rma_iov,
        .rma_iov_count = 1,
        .context = context,
        .data = 0,
    };

    return ucr_ep_rma_common(ucr_ep, &msg, ucr_ep->util_ep.tx_op_flags,
                             fi_readmsg, FI_READ);
}

static ssize_t ucr_ep_read(struct fid_ep *ep_fid, void *buf, size_t len,
                           void *desc, fi_addr_t src_addr, uint64_t addr,
                           uint64_t key, void *context)
{
    struct iovec iov = {
        .iov_base = (void *)buf,
        .iov_len = len,
    };
    struct fi_rma_iov rma_iov = {
        .addr = addr,
        .len = len,
        .key = key,
    };
    struct fi_msg_rma msg = {
        .msg_iov = &iov,
        .desc = &desc,
        .iov_count = 1,
        .addr = src_addr,
        .rma_iov = &rma_iov,
        .rma_iov_count = 1,
        .context = context,
        .data = 0,
    };
    struct ucr_ep *ucr_ep;

    ucr_ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    return ucr_ep_rma_common(ucr_ep, &msg, ucr_ep->util_ep.tx_op_flags,
                             fi_readmsg, FI_READ);
}

static void ucr_ep_format_rma_msg(struct ucr_tx_buf *rma_buf,
                                  const struct fi_msg_rma *orig_msg,
                                  struct iovec *ucr_iov,
                                  struct fi_msg_rma *ucr_msg)
{
    ssize_t ret __attribute__((unused));
    ucr_msg->context = rma_buf;
    ucr_msg->addr = orig_msg->addr;
    ucr_msg->data = orig_msg->data;

    ret = ucr_copy_from_hmem_iov(orig_msg->desc, rma_buf->pkt.data,
                                 rma_buf->pkt.hdr.size, orig_msg->msg_iov,
                                 orig_msg->iov_count, 0);
    assert((size_t)ret == rma_buf->pkt.hdr.size);

    ucr_iov->iov_base = &rma_buf->pkt.data;
    ucr_iov->iov_len = rma_buf->pkt.hdr.size;
    ucr_msg->msg_iov = ucr_iov;
    ucr_msg->desc = &rma_buf->hdr.desc;
    ucr_msg->iov_count = 1;

    ucr_msg->rma_iov = orig_msg->rma_iov;
    ucr_msg->rma_iov_count = orig_msg->rma_iov_count;
}

static ssize_t ucr_ep_rma_emulate_inject_msg(struct ucr_ep *ucr_ep,
                                             struct ucr_conn *ucr_conn,
                                             size_t total_size,
                                             const struct fi_msg_rma *msg,
                                             uint64_t flags)
{
    struct ucr_tx_buf *rma_buf;
    ssize_t ret;
    struct iovec ucr_msg_iov = {0};
    struct fi_msg_rma ucr_rma_msg = {0};

    assert(msg->rma_iov_count <= ucr_ep->ucr_info->tx_attr->rma_iov_limit);

    rma_buf = ucr_get_tx_buf(ucr_ep);
    if (!rma_buf)
        return -FI_EAGAIN;

    rma_buf->hdr.state = UCR_RMA;
    rma_buf->pkt.ctrl_hdr.type = ucr_ctrl_eager;
    rma_buf->pkt.hdr.size = total_size;
    rma_buf->app_context = msg->context;
    rma_buf->flags = flags;
    ucr_ep_format_rma_msg(rma_buf, msg, &ucr_msg_iov, &ucr_rma_msg);

    flags = (flags & ~FI_INJECT) | FI_COMPLETION;

    ret = fi_writemsg(ucr_conn->msg_ep, &ucr_rma_msg, flags);
    if (ret) {
        if (ret == -FI_EAGAIN)
            ucr_ep_do_progress(&ucr_ep->util_ep);
        ucr_free_tx_buf(ucr_ep, rma_buf);
    }
    return ret;
}

static ssize_t ucr_ep_rma_emulate_inject(struct ucr_ep *ucr_ep,
                                         struct ucr_conn *ucr_conn,
                                         const void *buf, size_t len,
                                         uint64_t data, fi_addr_t dest_addr,
                                         uint64_t addr, uint64_t key,
                                         uint64_t flags)
{
    struct fi_rma_iov rma_iov = {
        .addr = addr,
        .len = len,
        .key = key,
    };
    struct iovec iov = {
        .iov_base = (void *)buf,
        .iov_len = len,
    };
    struct fi_msg_rma msg = {
        .msg_iov = &iov,
        .desc = NULL,
        .iov_count = 1,
        .addr = dest_addr,
        .rma_iov = &rma_iov,
        .rma_iov_count = 1,
        .context = NULL,
        .data = data,
    };

    return ucr_ep_rma_emulate_inject_msg(ucr_ep, ucr_conn, len, &msg, flags);
}

static ssize_t ucr_ep_rma_inject_common(struct ucr_ep *ucr_ep,
                                        const struct fi_msg_rma *msg,
                                        uint64_t flags)
{
    struct ucr_conn *ucr_conn;
    size_t total_size = ofi_total_iov_len(msg->msg_iov, msg->iov_count);
    ssize_t ret;

    assert(total_size <= ucr_ep->ucr_info->tx_attr->inject_size);

    ofi_genlock_lock(&ucr_ep->util_ep.lock);

    ret = ucr_get_conn(ucr_ep, msg->addr, &ucr_conn);
    if (ret)
        goto unlock;

    if ((total_size > ucr_ep->ucr_info->tx_attr->inject_size) ||
        ucr_ep->util_ep.cntrs[CNTR_WR] || (flags & FI_COMPLETION) ||
        (msg->iov_count > 1) || (msg->rma_iov_count > 1)) {
        ret = ucr_ep_rma_emulate_inject_msg(ucr_ep, ucr_conn, total_size, msg,
                                            flags);
        goto unlock;
    }

    if (flags & FI_REMOTE_CQ_DATA) {
        ret = fi_inject_writedata(ucr_conn->msg_ep, msg->msg_iov->iov_base,
                                  msg->msg_iov->iov_len, msg->data, msg->addr,
                                  msg->rma_iov->addr, msg->rma_iov->key);
    } else {
        ret = fi_inject_write(ucr_conn->msg_ep, msg->msg_iov->iov_base,
                              msg->msg_iov->iov_len, msg->addr,
                              msg->rma_iov->addr, msg->rma_iov->key);
    }
    if (ret == -FI_EAGAIN)
        ucr_ep_do_progress(&ucr_ep->util_ep);
    else if (ret)
        FI_WARN(&ucr_prov, FI_LOG_EP_DATA,
                "fi_inject_write* for"
                "MSG provider failed: %zd\n",
                ret);
unlock:
    ofi_genlock_unlock(&ucr_ep->util_ep.lock);
    return ret;
}

static ssize_t ucr_ep_generic_writemsg(struct fid_ep *ep_fid,
                                       const struct fi_msg_rma *msg,
                                       uint64_t flags)
{
    struct ucr_ep *ucr_ep;

    ucr_ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    if (flags & FI_INJECT)
        return ucr_ep_rma_inject_common(ucr_ep, msg, flags);
    else
        return ucr_ep_rma_common(ucr_ep, msg, flags, fi_writemsg, FI_WRITE);
}

static ssize_t ucr_ep_writemsg(struct fid_ep *ep_fid,
                               const struct fi_msg_rma *msg, uint64_t flags)
{
    struct ucr_ep *ucr_ep;

    ucr_ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    return ucr_ep_generic_writemsg(ep_fid, msg,
                                   flags | ucr_ep->util_ep.tx_msg_flags);
}

static ssize_t ucr_ep_writev(struct fid_ep *ep_fid, const struct iovec *iov,
                             void **desc, size_t count, fi_addr_t dest_addr,
                             uint64_t addr, uint64_t key, void *context)
{
    struct fi_rma_iov rma_iov = {
        .addr = addr,
        .len = ofi_total_iov_len(iov, count),
        .key = key,
    };
    struct fi_msg_rma msg = {
        .msg_iov = iov,
        .desc = desc,
        .iov_count = count,
        .addr = dest_addr,
        .rma_iov = &rma_iov,
        .rma_iov_count = 1,
        .context = context,
        .data = 0,
    };
    struct ucr_ep *ucr_ep;

    ucr_ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    return ucr_ep_generic_writemsg(ep_fid, &msg, ucr_ep->util_ep.tx_op_flags);
}

static ssize_t ucr_ep_writedata(struct fid_ep *ep_fid, const void *buf,
                                size_t len, void *desc, uint64_t data,
                                fi_addr_t dest_addr, uint64_t addr,
                                uint64_t key, void *context)
{
    struct fi_rma_iov rma_iov = {
        .addr = addr,
        .len = len,
        .key = key,
    };
    struct iovec iov = {
        .iov_base = (void *)buf,
        .iov_len = len,
    };
    struct fi_msg_rma msg = {
        .msg_iov = &iov,
        .desc = &desc,
        .iov_count = 1,
        .addr = dest_addr,
        .rma_iov = &rma_iov,
        .rma_iov_count = 1,
        .context = context,
        .data = data,
    };
    struct ucr_ep *ucr_ep;

    ucr_ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    return ucr_ep_generic_writemsg(
        ep_fid, &msg, ucr_ep->util_ep.tx_op_flags | FI_REMOTE_CQ_DATA);
}

static ssize_t ucr_ep_write(struct fid_ep *ep_fid, const void *buf, size_t len,
                            void *desc, fi_addr_t dest_addr, uint64_t addr,
                            uint64_t key, void *context)
{
    struct fi_rma_iov rma_iov = {
        .addr = addr,
        .len = len,
        .key = key,
    };
    struct iovec iov = {
        .iov_base = (void *)buf,
        .iov_len = len,
    };
    struct fi_msg_rma msg = {
        .msg_iov = &iov,
        .desc = &desc,
        .iov_count = 1,
        .addr = dest_addr,
        .rma_iov = &rma_iov,
        .rma_iov_count = 1,
        .context = context,
        .data = 0,
    };
    struct ucr_ep *ucr_ep;

    ucr_ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    return ucr_ep_generic_writemsg(ep_fid, &msg, ucr_ep->util_ep.tx_op_flags);
}

static ssize_t ucr_ep_inject_write(struct fid_ep *ep_fid, const void *buf,
                                   size_t len, fi_addr_t dest_addr,
                                   uint64_t addr, uint64_t key)
{
    struct ucr_conn *ucr_conn;
    struct ucr_ep *ucr_ep;
    ssize_t ret;

    ucr_ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    ofi_genlock_lock(&ucr_ep->util_ep.lock);

    ret = ucr_get_conn(ucr_ep, dest_addr, &ucr_conn);
    if (ret)
        goto unlock;

    if (len > ucr_ep->inject_limit || ucr_ep->util_ep.cntrs[CNTR_WR]) {
        ret = ucr_ep_rma_emulate_inject(ucr_ep, ucr_conn, buf, len, 0,
                                        dest_addr, addr, key, FI_INJECT);
        goto unlock;
    }

    ret = fi_inject_write(ucr_conn->msg_ep, buf, len, dest_addr, addr, key);
    if (ret == -FI_EAGAIN)
        ucr_ep_do_progress(&ucr_ep->util_ep);
    else if (ret)
        FI_WARN(&ucr_prov, FI_LOG_EP_DATA,
                "fi_inject_write for"
                " MSG provider failed: %zd\n",
                ret);
unlock:
    ofi_genlock_unlock(&ucr_ep->util_ep.lock);
    return ret;
}

static ssize_t ucr_ep_inject_writedata(struct fid_ep *ep_fid, const void *buf,
                                       size_t len, uint64_t data,
                                       fi_addr_t dest_addr, uint64_t addr,
                                       uint64_t key)
{
    struct ucr_conn *ucr_conn;
    struct ucr_ep *ucr_ep;
    ssize_t ret;

    ucr_ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    ofi_genlock_lock(&ucr_ep->util_ep.lock);

    ret = ucr_get_conn(ucr_ep, dest_addr, &ucr_conn);
    if (ret)
        goto unlock;

    if (len > ucr_ep->inject_limit || ucr_ep->util_ep.cntrs[CNTR_WR]) {
        ret = ucr_ep_rma_emulate_inject(ucr_ep, ucr_conn, buf, len, data,
                                        dest_addr, addr, key,
                                        FI_REMOTE_CQ_DATA | FI_INJECT);
        goto unlock;
    }

    ret = fi_inject_writedata(ucr_conn->msg_ep, buf, len, data, dest_addr, addr,
                              key);
    if (ret == -FI_EAGAIN)
        ucr_ep_do_progress(&ucr_ep->util_ep);
    else if (ret)
        FI_WARN(&ucr_prov, FI_LOG_EP_DATA,
                "fi_inject_writedata"
                " for MSG provider failed: %zd\n",
                ret);
unlock:
    ofi_genlock_unlock(&ucr_ep->util_ep.lock);
    return ret;
}

struct fi_ops_rma ucr_rma_ops = {
    .size = sizeof(struct fi_ops_rma),
    .read = ucr_ep_read,
    .readv = ucr_ep_readv,
    .readmsg = ucr_ep_readmsg,
    .write = ucr_ep_write,
    .writev = ucr_ep_writev,
    .writemsg = ucr_ep_writemsg,
    .inject = ucr_ep_inject_write,
    .writedata = ucr_ep_writedata,
    .injectdata = ucr_ep_inject_writedata,
};

static ssize_t ucr_read_thru(struct fid_ep *ep_fid, void *buf, size_t len,
                             void *desc, fi_addr_t src_addr, uint64_t addr,
                             uint64_t key, void *context)
{
    struct ucr_ep *ep;
    struct ucr_conn *conn;
    ssize_t ret;

    ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    ofi_genlock_lock(&ep->util_ep.lock);

    ret = ucr_get_conn(ep, src_addr, &conn);
    if (ret)
        goto unlock;

    ret = fi_read(conn->msg_ep, buf, len, desc, src_addr, addr, key, context);
unlock:
    ofi_genlock_unlock(&ep->util_ep.lock);
    return ret;
}

static ssize_t ucr_readv_thru(struct fid_ep *ep_fid, const struct iovec *iov,
                              void **desc, size_t count, fi_addr_t src_addr,
                              uint64_t addr, uint64_t key, void *context)
{
    struct ucr_ep *ep;
    struct ucr_conn *conn;
    ssize_t ret;

    ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    ofi_genlock_lock(&ep->util_ep.lock);

    ret = ucr_get_conn(ep, src_addr, &conn);
    if (ret)
        goto unlock;

    ret =
        fi_readv(conn->msg_ep, iov, desc, count, src_addr, addr, key, context);
unlock:
    ofi_genlock_unlock(&ep->util_ep.lock);
    return ret;
}

static ssize_t ucr_readmsg_thru(struct fid_ep *ep_fid,
                                const struct fi_msg_rma *msg, uint64_t flags)
{
    struct ucr_ep *ep;
    struct ucr_conn *conn;
    ssize_t ret;

    ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    ofi_genlock_lock(&ep->util_ep.lock);

    ret = ucr_get_conn(ep, msg->addr, &conn);
    if (ret)
        goto unlock;

    ret = fi_readmsg(conn->msg_ep, msg, flags);
unlock:
    ofi_genlock_unlock(&ep->util_ep.lock);
    return ret;
}

static ssize_t ucr_write_thru(struct fid_ep *ep_fid, const void *buf,
                              size_t len, void *desc, fi_addr_t dest_addr,
                              uint64_t addr, uint64_t key, void *context)
{
    struct ucr_ep *ep;
    struct ucr_conn *conn;
    ssize_t ret;

    ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    ofi_genlock_lock(&ep->util_ep.lock);

    ret = ucr_get_conn(ep, dest_addr, &conn);
    if (ret)
        goto unlock;

    ret = fi_write(conn->msg_ep, buf, len, desc, dest_addr, addr, key, context);
unlock:
    ofi_genlock_unlock(&ep->util_ep.lock);
    return ret;
}

static ssize_t ucr_writev_thru(struct fid_ep *ep_fid, const struct iovec *iov,
                               void **desc, size_t count, fi_addr_t dest_addr,
                               uint64_t addr, uint64_t key, void *context)
{
    struct ucr_ep *ep;
    struct ucr_conn *conn;
    ssize_t ret;

    ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    ofi_genlock_lock(&ep->util_ep.lock);

    ret = ucr_get_conn(ep, dest_addr, &conn);
    if (ret)
        goto unlock;

    ret = fi_writev(conn->msg_ep, iov, desc, count, dest_addr, addr, key,
                    context);
unlock:
    ofi_genlock_unlock(&ep->util_ep.lock);
    return ret;
}

static ssize_t ucr_writemsg_thru(struct fid_ep *ep_fid,
                                 const struct fi_msg_rma *msg, uint64_t flags)
{
    struct ucr_ep *ep;
    struct ucr_conn *conn;
    ssize_t ret;

    ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    ofi_genlock_lock(&ep->util_ep.lock);

    ret = ucr_get_conn(ep, msg->addr, &conn);
    if (ret)
        goto unlock;

    ret = fi_writemsg(conn->msg_ep, msg, flags);
unlock:
    ofi_genlock_unlock(&ep->util_ep.lock);
    return ret;
}

static ssize_t ucr_inject_write_thru(struct fid_ep *ep_fid, const void *buf,
                                     size_t len, fi_addr_t dest_addr,
                                     uint64_t addr, uint64_t key)
{
    struct ucr_ep *ep;
    struct ucr_conn *conn;
    ssize_t ret;

    ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    ofi_genlock_lock(&ep->util_ep.lock);

    ret = ucr_get_conn(ep, dest_addr, &conn);
    if (ret)
        goto unlock;

    ret = fi_inject_write(conn->msg_ep, buf, len, dest_addr, addr, key);
unlock:
    ofi_genlock_unlock(&ep->util_ep.lock);
    return ret;
}

static ssize_t ucr_writedata_thru(struct fid_ep *ep_fid, const void *buf,
                                  size_t len, void *desc, uint64_t data,
                                  fi_addr_t dest_addr, uint64_t addr,
                                  uint64_t key, void *context)
{
    struct ucr_ep *ep;
    struct ucr_conn *conn;
    ssize_t ret;

    ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    ofi_genlock_lock(&ep->util_ep.lock);

    ret = ucr_get_conn(ep, dest_addr, &conn);
    if (ret)
        goto unlock;

    ret = fi_writedata(conn->msg_ep, buf, len, desc, data, dest_addr, addr, key,
                       context);
unlock:
    ofi_genlock_unlock(&ep->util_ep.lock);
    return ret;
}

static ssize_t ucr_inject_writedata_thru(struct fid_ep *ep_fid, const void *buf,
                                         size_t len, uint64_t data,
                                         fi_addr_t dest_addr, uint64_t addr,
                                         uint64_t key)
{
    struct ucr_ep *ep;
    struct ucr_conn *conn;
    ssize_t ret;

    ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    ofi_genlock_lock(&ep->util_ep.lock);

    ret = ucr_get_conn(ep, dest_addr, &conn);
    if (ret)
        goto unlock;

    ret =
        fi_inject_writedata(conn->msg_ep, buf, len, data, dest_addr, addr, key);
unlock:
    ofi_genlock_unlock(&ep->util_ep.lock);
    return ret;
}

struct fi_ops_rma ucr_rma_thru_ops = {
    .size = sizeof(struct fi_ops_rma),
    .read = ucr_read_thru,
    .readv = ucr_readv_thru,
    .readmsg = ucr_readmsg_thru,
    .write = ucr_write_thru,
    .writev = ucr_writev_thru,
    .writemsg = ucr_writemsg_thru,
    .inject = ucr_inject_write_thru,
    .writedata = ucr_writedata_thru,
    .injectdata = ucr_inject_writedata_thru,
};
