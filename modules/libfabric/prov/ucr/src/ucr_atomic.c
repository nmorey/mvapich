/*
 * Copyright (c) 2018 Cray Inc. All rights reserved.
 * Copyright (c) 2018 System Fabric Works, Inc. All rights reserved.
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

#include <ofi_atomic.h>

#include "ucr.h"

static void ucr_ep_format_atomic_pkt_hdr(
    struct ucr_conn *ucr_conn, struct ucr_tx_buf *tx_buf, size_t data_len,
    uint8_t pkt_op, enum fi_datatype datatype, uint8_t atomic_op,
    uint64_t flags, uint64_t data, const struct fi_rma_ioc *rma_ioc,
    size_t rma_ioc_count)
{
    struct ucr_atomic_hdr *atomic_hdr;

    atomic_hdr = (struct ucr_atomic_hdr *)tx_buf->pkt.data;
    ucr_ep_format_tx_buf_pkt(ucr_conn, data_len, pkt_op, data, 0, flags,
                             &tx_buf->pkt);
    tx_buf->pkt.ctrl_hdr.type = ucr_ctrl_atomic;
    tx_buf->pkt.hdr.op = pkt_op;
    tx_buf->pkt.hdr.atomic.datatype = datatype;
    tx_buf->pkt.hdr.atomic.op = atomic_op;
    tx_buf->pkt.hdr.atomic.ioc_count = (uint8_t)rma_ioc_count;
    if (rma_ioc_count)
        memcpy(atomic_hdr->rma_ioc, rma_ioc,
               rma_ioc_count * sizeof(struct fi_rma_ioc));
    tx_buf->flags = flags;
}

static inline ssize_t ucr_ep_send_atomic_req(struct ucr_ep *ucr_ep,
                                             struct ucr_conn *ucr_conn,
                                             struct ucr_tx_buf *tx_buf,
                                             uint64_t len)
{
    ssize_t ret;

    /* Atomic request TX completion processing is performed when the
     * software generated atomic response message is received. */
    tx_buf->hdr.state = UCR_ATOMIC_RESP_WAIT;
    if (len <= ucr_ep->inject_limit)
        ret = fi_inject(ucr_conn->msg_ep, &tx_buf->pkt, len, 0);
    else
        ret = fi_send(ucr_conn->msg_ep, &tx_buf->pkt, len, tx_buf->hdr.desc, 0,
                      tx_buf);
    if (ret == -FI_EAGAIN)
        ucr_ep_do_progress(&ucr_ep->util_ep);

    if (OFI_LIKELY(!ret))
        FI_DBG(&ucr_prov, FI_LOG_EP_DATA,
               "sent atomic request: op: %" PRIu8 " msg_id: 0x%" PRIx64 "\n",
               tx_buf->pkt.hdr.op, tx_buf->pkt.ctrl_hdr.msg_id);
    else if (OFI_UNLIKELY(ret != -FI_EAGAIN))
        FI_WARN(&ucr_prov, FI_LOG_EP_DATA,
                "unable to send atomic "
                "request: op: %" PRIu8 " msg_id: 0x%" PRIx64 "\n",
                tx_buf->pkt.hdr.op, tx_buf->pkt.ctrl_hdr.msg_id);
    return ret;
}

static ssize_t ucr_ep_atomic_common(
    struct ucr_ep *ucr_ep, struct ucr_conn *ucr_conn,
    const struct fi_msg_atomic *msg, const struct fi_ioc *comparev,
    void **compare_desc, size_t compare_iov_count, struct fi_ioc *resultv,
    void **result_desc, size_t result_iov_count, uint8_t op, uint64_t flags)
{
    struct ucr_tx_buf *tx_buf;
    struct ucr_atomic_hdr *atomic_hdr;
    struct iovec buf_iov[UCR_IOV_LIMIT];
    struct iovec cmp_iov[UCR_IOV_LIMIT];
    enum fi_hmem_iface buf_iface = FI_HMEM_SYSTEM;
    enum fi_hmem_iface cmp_iface = FI_HMEM_SYSTEM;
    uint64_t buf_device = 0;
    uint64_t cmp_device = 0;
    size_t datatype_sz = ofi_datatype_size(msg->datatype);
    size_t buf_len = 0;
    size_t cmp_len = 0;
    size_t data_len, tot_len;
    ssize_t ret;
    int i;

    assert(msg->iov_count <= UCR_IOV_LIMIT &&
           msg->rma_iov_count <= UCR_IOV_LIMIT);

    if (flags & FI_REMOTE_CQ_DATA) {
        FI_WARN(&ucr_prov, FI_LOG_EP_DATA,
                "atomic with remote CQ data not supported\n");
        return -FI_EINVAL;
    }

    if (msg->op != FI_ATOMIC_READ) {
        assert(msg->msg_iov);
        ofi_ioc_to_iov(msg->msg_iov, buf_iov, msg->iov_count, datatype_sz);
        buf_len = ofi_total_iov_len(buf_iov, msg->iov_count);

        buf_iface = ucr_mr_desc_to_hmem_iface_dev(msg->desc, msg->iov_count,
                                                  &buf_device);
    }

    if (op == ofi_op_atomic_compare) {
        assert(comparev);
        ofi_ioc_to_iov(comparev, cmp_iov, compare_iov_count, datatype_sz);
        cmp_len = ofi_total_iov_len(cmp_iov, compare_iov_count);
        assert(buf_len == cmp_len);

        cmp_iface = ucr_mr_desc_to_hmem_iface_dev(
            compare_desc, compare_iov_count, &cmp_device);
    }

    data_len = buf_len + cmp_len + sizeof(struct ucr_atomic_hdr);
    tot_len = data_len + sizeof(struct ucr_pkt);

    if (tot_len > ucr_packet_size) {
        FI_WARN(&ucr_prov, FI_LOG_EP_DATA, "atomic data too large %zu\n",
                tot_len);
        return -FI_EINVAL;
    }

    tx_buf = ucr_get_tx_buf(ucr_ep);
    if (!tx_buf)
        return -FI_EAGAIN;

    ucr_ep_format_atomic_pkt_hdr(ucr_conn, tx_buf, data_len, op, msg->datatype,
                                 msg->op, flags, msg->data, msg->rma_iov,
                                 msg->rma_iov_count);
    tx_buf->pkt.ctrl_hdr.msg_id = ofi_buf_index(tx_buf);
    tx_buf->app_context = msg->context;

    atomic_hdr = (struct ucr_atomic_hdr *)tx_buf->pkt.data;

    ret = ofi_copy_from_hmem_iov(atomic_hdr->data, buf_len, buf_iface,
                                 buf_device, buf_iov, msg->iov_count, 0);
    assert((size_t)ret == buf_len);

    if (cmp_len) {
        ret = ofi_copy_from_hmem_iov(atomic_hdr->data + buf_len, cmp_len,
                                     cmp_iface, cmp_device, cmp_iov,
                                     compare_iov_count, 0);
        assert((size_t)ret == cmp_len);
    }

    tx_buf->atomic_result.count = (uint8_t)result_iov_count;
    if (resultv) {
        ofi_ioc_to_iov(resultv, tx_buf->atomic_result.iov, result_iov_count,
                       datatype_sz);

        if (result_desc) {
            for (i = 0; i < result_iov_count; i++)
                tx_buf->atomic_result.desc[i] = result_desc[i];
        }
    }

    ret = ucr_ep_send_atomic_req(ucr_ep, ucr_conn, tx_buf, tot_len);
    if (ret)
        ucr_free_tx_buf(ucr_ep, tx_buf);

    return ret;
}

static ssize_t ucr_ep_generic_atomic_writemsg(struct ucr_ep *ucr_ep,
                                              const struct fi_msg_atomic *msg,
                                              uint64_t flags)
{
    struct ucr_conn *ucr_conn;
    ssize_t ret;

    ofi_genlock_lock(&ucr_ep->util_ep.lock);
    ret = ucr_get_conn(ucr_ep, msg->addr, &ucr_conn);
    if (ret)
        goto unlock;

    ret = ucr_ep_atomic_common(ucr_ep, ucr_conn, msg, NULL, NULL, 0, NULL, NULL,
                               0, ofi_op_atomic, flags);
unlock:
    ofi_genlock_unlock(&ucr_ep->util_ep.lock);
    return ret;
}

static ssize_t ucr_ep_atomic_writemsg(struct fid_ep *ep_fid,
                                      const struct fi_msg_atomic *msg,
                                      uint64_t flags)
{
    struct ucr_ep *ucr_ep =
        container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);

    return ucr_ep_generic_atomic_writemsg(ucr_ep, msg,
                                          flags | ucr_ep->util_ep.tx_msg_flags);
}

static ssize_t ucr_ep_atomic_writev(struct fid_ep *ep_fid,
                                    const struct fi_ioc *iov, void **desc,
                                    size_t count, fi_addr_t dest_addr,
                                    uint64_t addr, uint64_t key,
                                    enum fi_datatype datatype, enum fi_op op,
                                    void *context)
{
    struct ucr_ep *ucr_ep =
        container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    struct fi_rma_ioc rma_iov = {
        .addr = addr,
        .count = ofi_total_ioc_cnt(iov, count),
        .key = key,
    };
    struct fi_msg_atomic msg = {
        .msg_iov = iov,
        .desc = desc,
        .iov_count = count,
        .addr = dest_addr,
        .rma_iov = &rma_iov,
        .rma_iov_count = 1,
        .datatype = datatype,
        .op = op,
        .context = context,
        .data = 0,
    };

    return ucr_ep_generic_atomic_writemsg(ucr_ep, &msg,
                                          ucr_ep->util_ep.tx_op_flags);
}

static ssize_t ucr_ep_atomic_write(struct fid_ep *ep_fid, const void *buf,
                                   size_t count, void *desc,
                                   fi_addr_t dest_addr, uint64_t addr,
                                   uint64_t key, enum fi_datatype datatype,
                                   enum fi_op op, void *context)
{
    const struct fi_ioc iov = {
        .addr = (void *)buf,
        .count = count,
    };

    return ucr_ep_atomic_writev(ep_fid, &iov, &desc, 1, dest_addr, addr, key,
                                datatype, op, context);
}

static ssize_t ucr_ep_atomic_inject(struct fid_ep *ep_fid, const void *buf,
                                    size_t count, fi_addr_t dest_addr,
                                    uint64_t addr, uint64_t key,
                                    enum fi_datatype datatype, enum fi_op op)
{
    struct ucr_ep *ucr_ep =
        container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    struct fi_ioc msg_iov = {
        .addr = (void *)buf,
        .count = count,
    };
    struct fi_rma_ioc rma_iov = {
        .addr = addr,
        .count = count,
        .key = key,
    };
    struct fi_msg_atomic msg = {
        .msg_iov = &msg_iov,
        .desc = NULL,
        .iov_count = 1,
        .addr = dest_addr,
        .rma_iov = &rma_iov,
        .rma_iov_count = 1,
        .datatype = datatype,
        .op = op,
        .context = NULL,
        .data = 0,
    };

    return ucr_ep_generic_atomic_writemsg(ucr_ep, &msg, FI_INJECT);
}

static ssize_t ucr_ep_generic_atomic_readwritemsg(
    struct ucr_ep *ucr_ep, const struct fi_msg_atomic *msg,
    struct fi_ioc *resultv, void **result_desc, size_t result_count,
    uint64_t flags)
{
    struct ucr_conn *ucr_conn;
    ssize_t ret;

    ofi_genlock_lock(&ucr_ep->util_ep.lock);
    ret = ucr_get_conn(ucr_ep, msg->addr, &ucr_conn);
    if (ret)
        goto unlock;

    ret = ucr_ep_atomic_common(ucr_ep, ucr_conn, msg, NULL, NULL, 0, resultv,
                               result_desc, result_count, ofi_op_atomic_fetch,
                               flags);
unlock:
    ofi_genlock_unlock(&ucr_ep->util_ep.lock);
    return ret;
}

static ssize_t ucr_ep_atomic_readwritemsg(struct fid_ep *ep_fid,
                                          const struct fi_msg_atomic *msg,
                                          struct fi_ioc *resultv,
                                          void **result_desc,
                                          size_t result_count, uint64_t flags)
{
    struct ucr_ep *ucr_ep =
        container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);

    return ucr_ep_generic_atomic_readwritemsg(
        ucr_ep, msg, resultv, result_desc, result_count,
        flags | ucr_ep->util_ep.tx_msg_flags);
}

static ssize_t ucr_ep_atomic_readwritev(struct fid_ep *ep_fid,
                                        const struct fi_ioc *iov, void **desc,
                                        size_t count, struct fi_ioc *resultv,
                                        void **result_desc, size_t result_count,
                                        fi_addr_t dest_addr, uint64_t addr,
                                        uint64_t key, enum fi_datatype datatype,
                                        enum fi_op op, void *context)
{
    struct ucr_ep *ucr_ep =
        container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    struct fi_rma_ioc rma_iov = {
        .addr = addr,
        .count = ofi_total_ioc_cnt(iov, count),
        .key = key,
    };
    struct fi_msg_atomic msg = {
        .msg_iov = iov,
        .desc = desc,
        .iov_count = count,
        .addr = dest_addr,
        .rma_iov = &rma_iov,
        .rma_iov_count = 1,
        .datatype = datatype,
        .op = op,
        .context = context,
        .data = 0,
    };

    return ucr_ep_generic_atomic_readwritemsg(ucr_ep, &msg, resultv,
                                              result_desc, result_count,
                                              ucr_ep->util_ep.tx_op_flags);
}

static ssize_t ucr_ep_atomic_readwrite(struct fid_ep *ep_fid, const void *buf,
                                       size_t count, void *desc, void *result,
                                       void *result_desc, fi_addr_t dest_addr,
                                       uint64_t addr, uint64_t key,
                                       enum fi_datatype datatype, enum fi_op op,
                                       void *context)
{
    struct fi_ioc iov = {
        .addr = (op == FI_ATOMIC_READ) ? NULL : (void *)buf,
        .count = count,
    };
    struct fi_ioc result_iov = {
        .addr = result,
        .count = count,
    };

    if (!buf && op != FI_ATOMIC_READ)
        return -FI_EINVAL;

    return ucr_ep_atomic_readwritev(ep_fid, &iov, &desc, 1, &result_iov,
                                    &result_desc, 1, dest_addr, addr, key,
                                    datatype, op, context);
}

static ssize_t ucr_ep_generic_atomic_compwritemsg(
    struct ucr_ep *ucr_ep, const struct fi_msg_atomic *msg,
    const struct fi_ioc *comparev, void **compare_desc, size_t compare_count,
    struct fi_ioc *resultv, void **result_desc, size_t result_count,
    uint64_t flags)
{
    struct ucr_conn *ucr_conn;
    ssize_t ret;

    ofi_genlock_lock(&ucr_ep->util_ep.lock);
    ret = ucr_get_conn(ucr_ep, msg->addr, &ucr_conn);
    if (ret)
        goto unlock;

    ret = ucr_ep_atomic_common(ucr_ep, ucr_conn, msg, comparev, compare_desc,
                               compare_count, resultv, result_desc,
                               result_count, ofi_op_atomic_compare, flags);
unlock:
    ofi_genlock_unlock(&ucr_ep->util_ep.lock);
    return ret;
}

static ssize_t ucr_ep_atomic_compwritemsg(
    struct fid_ep *ep_fid, const struct fi_msg_atomic *msg,
    const struct fi_ioc *comparev, void **compare_desc, size_t compare_count,
    struct fi_ioc *resultv, void **result_desc, size_t result_count,
    uint64_t flags)
{
    struct ucr_ep *ucr_ep =
        container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);

    return ucr_ep_generic_atomic_compwritemsg(
        ucr_ep, msg, comparev, compare_desc, compare_count, resultv,
        result_desc, result_count, flags | ucr_ep->util_ep.tx_msg_flags);
}

static ssize_t ucr_ep_atomic_compwritev(
    struct fid_ep *ep_fid, const struct fi_ioc *iov, void **desc, size_t count,
    const struct fi_ioc *comparev, void **compare_desc, size_t compare_count,
    struct fi_ioc *resultv, void **result_desc, size_t result_count,
    fi_addr_t dest_addr, uint64_t addr, uint64_t key, enum fi_datatype datatype,
    enum fi_op op, void *context)
{
    struct ucr_ep *ucr_ep =
        container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    struct fi_rma_ioc rma_iov = {
        .addr = addr,
        .count = ofi_total_ioc_cnt(iov, count),
        .key = key,
    };
    struct fi_msg_atomic msg = {
        .msg_iov = iov,
        .desc = desc,
        .iov_count = count,
        .addr = dest_addr,
        .rma_iov = &rma_iov,
        .rma_iov_count = 1,
        .datatype = datatype,
        .op = op,
        .context = context,
        .data = 0,
    };

    return ucr_ep_generic_atomic_compwritemsg(
        ucr_ep, &msg, comparev, compare_desc, compare_count, resultv,
        result_desc, result_count, ucr_ep->util_ep.tx_op_flags);
}

static ssize_t ucr_ep_atomic_compwrite(struct fid_ep *ep_fid, const void *buf,
                                       size_t count, void *desc,
                                       const void *compare, void *compare_desc,
                                       void *result, void *result_desc,
                                       fi_addr_t dest_addr, uint64_t addr,
                                       uint64_t key, enum fi_datatype datatype,
                                       enum fi_op op, void *context)
{
    struct fi_ioc iov = {
        .addr = (void *)buf,
        .count = count,
    };
    struct fi_ioc resultv = {
        .addr = result,
        .count = count,
    };
    struct fi_ioc comparev = {
        .addr = (void *)compare,
        .count = count,
    };

    return ucr_ep_atomic_compwritev(
        ep_fid, &iov, &desc, 1, &comparev, &compare_desc, 1, &resultv,
        &result_desc, 1, dest_addr, addr, key, datatype, op, context);
}

int ucr_ep_query_atomic(struct fid_domain *domain, enum fi_datatype datatype,
                        enum fi_op op, struct fi_atomic_attr *attr,
                        uint64_t flags)
{
    struct ucr_domain *ucr_domain =
        container_of(domain, struct ucr_domain, util_domain.domain_fid);
    size_t tot_size;
    int ret;

    if (flags & FI_TAGGED) {
        FI_WARN(&ucr_prov, FI_LOG_EP_DATA, "tagged atomic op not supported\n");
        return -FI_EINVAL;
    }

    if ((datatype == FI_INT128) || (datatype == FI_UINT128)) {
        FI_WARN(&ucr_prov, FI_LOG_EP_CTRL, "128-bit integers not supported\n");
        return -FI_EOPNOTSUPP;
    }

    ret = ofi_atomic_valid(&ucr_prov, datatype, op, flags);
    if (ret || !attr)
        return ret;

    tot_size = flags & FI_COMPARE_ATOMIC ? ucr_domain->max_atomic_size / 2 :
                                           ucr_domain->max_atomic_size;
    attr->size = ofi_datatype_size(datatype);
    if (!attr->size)
        return -FI_EOPNOTSUPP;

    attr->count = tot_size / attr->size;
    if (attr->count == 0)
        return -FI_EOPNOTSUPP;

    return FI_SUCCESS;
}

static int ucr_ep_atomic_valid(struct fid_ep *ep_fid, enum fi_datatype datatype,
                               enum fi_op op, size_t *count)
{
    struct ucr_ep *ucr_ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid);
    struct fi_atomic_attr attr;
    int ret;

    ret = ucr_ep_query_atomic(&ucr_ep->util_ep.domain->domain_fid, datatype, op,
                              &attr, 0);
    if (!ret)
        *count = attr.count;

    return ret;
}

static int ucr_ep_atomic_fetch_valid(struct fid_ep *ep_fid,
                                     enum fi_datatype datatype, enum fi_op op,
                                     size_t *count)
{
    struct ucr_ep *ucr_ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid);
    struct fi_atomic_attr attr;
    int ret;

    ret = ucr_ep_query_atomic(&ucr_ep->util_ep.domain->domain_fid, datatype, op,
                              &attr, FI_FETCH_ATOMIC);
    if (!ret)
        *count = attr.count;

    return ret;
}

static int ucr_ep_atomic_cswap_valid(struct fid_ep *ep_fid,
                                     enum fi_datatype datatype, enum fi_op op,
                                     size_t *count)
{
    struct ucr_ep *ucr_ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid);
    struct fi_atomic_attr attr;
    int ret;

    ret = ucr_ep_query_atomic(&ucr_ep->util_ep.domain->domain_fid, datatype, op,
                              &attr, FI_COMPARE_ATOMIC);
    if (!ret)
        *count = attr.count;

    return ret;
}

struct fi_ops_atomic ucr_ops_atomic = {
    .size = sizeof(struct fi_ops_atomic),
    .write = ucr_ep_atomic_write,
    .writev = ucr_ep_atomic_writev,
    .writemsg = ucr_ep_atomic_writemsg,
    .inject = ucr_ep_atomic_inject,
    .readwrite = ucr_ep_atomic_readwrite,
    .readwritev = ucr_ep_atomic_readwritev,
    .readwritemsg = ucr_ep_atomic_readwritemsg,
    .compwrite = ucr_ep_atomic_compwrite,
    .compwritev = ucr_ep_atomic_compwritev,
    .compwritemsg = ucr_ep_atomic_compwritemsg,
    .writevalid = ucr_ep_atomic_valid,
    .readwritevalid = ucr_ep_atomic_fetch_valid,
    .compwritevalid = ucr_ep_atomic_cswap_valid,
};
