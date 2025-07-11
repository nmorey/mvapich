/*
 * Copyright (c) 2013-2021 Intel Corporation. All rights reserved.
 * Copyright (c) 2020 Cisco Systems, Inc.  All rights reserved.
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

#include <inttypes.h>
#include <math.h>

#include <rdma/fabric.h>
#include <ofi.h>

#include "ucr.h"

ssize_t ucr_handle_unexp_sar(struct ucr_recv_queue *recv_queue,
                             struct ucr_recv_entry *recv_entry,
                             struct ucr_rx_buf *rx_buf)
{
    struct ucr_recv_match_attr match_attr;
    struct dlist_entry *entry;
    bool last;
    ssize_t ret;

    ret = ucr_handle_rx_buf(rx_buf);
    last = ucr_sar_get_seg_type(&rx_buf->pkt.ctrl_hdr) == UCR_SAR_SEG_LAST;
    if (ret || last)
        return ret;

    match_attr.addr = recv_entry->addr;
    match_attr.tag = recv_entry->tag;
    match_attr.ignore = recv_entry->ignore;

    dlist_foreach_container_safe(&recv_queue->unexp_msg_list, struct ucr_rx_buf,
                                 rx_buf, unexp_msg.entry, entry)
    {
        if (!recv_queue->match_unexp(&rx_buf->unexp_msg.entry, &match_attr))
            continue;
        /* Handle unordered completions from MSG provider */
        if ((rx_buf->pkt.ctrl_hdr.msg_id != recv_entry->sar.msg_id) ||
            ((rx_buf->pkt.ctrl_hdr.type != ucr_ctrl_seg)))
            continue;

        if (!rx_buf->conn) {
            rx_buf->conn = ofi_idm_at(&rx_buf->ep->conn_idx_map,
                                      (int)rx_buf->pkt.ctrl_hdr.conn_id);
        }
        if (recv_entry->sar.conn != rx_buf->conn)
            continue;
        rx_buf->recv_entry = recv_entry;
        dlist_remove(&rx_buf->unexp_msg.entry);
        last = ucr_sar_get_seg_type(&rx_buf->pkt.ctrl_hdr) == UCR_SAR_SEG_LAST;
        ret = ucr_handle_rx_buf(rx_buf);
        if (ret || last)
            break;
    }
    return ret;
}

/*
 * We don't expect to have unexpected messages when the app is using
 * multi-recv buffers.  Optimize for that case.
 *
 * If there are unexpected messages waiting when we post a mult-recv buffer,
 * we trim off the start of the buffer, treat it as a normal buffer, and pair
 * it with an unexpected message.  We continue doing this until either no
 * unexpected messages are left or the multi-recv buffer has been consumed.
 */
static ssize_t ucr_post_mrecv(struct ucr_ep *ep, const struct iovec *iov,
                              void **desc, void *context, uint64_t op_flags)
{
    struct ucr_recv_entry *recv_entry;
    struct ucr_rx_buf *rx_buf;
    struct iovec cur_iov = *iov;
    ssize_t ret;

    do {
        recv_entry =
            ucr_recv_entry_get(ep, &cur_iov, desc, 1, FI_ADDR_UNSPEC, 0, 0,
                               context, op_flags, &ep->recv_queue);
        if (!recv_entry) {
            ret = -FI_ENOMEM;
            break;
        }

        rx_buf = ucr_get_unexp_msg(&ep->recv_queue, recv_entry->addr, 0, 0);
        if (!rx_buf) {
            dlist_insert_tail(&recv_entry->entry, &ep->recv_queue.recv_list);
            return 0;
        }

        dlist_remove(&rx_buf->unexp_msg.entry);
        rx_buf->recv_entry = recv_entry;
        recv_entry->flags &= ~FI_MULTI_RECV;
        recv_entry->total_len = MIN(cur_iov.iov_len, rx_buf->pkt.hdr.size);
        recv_entry->ucr_iov.iov[0].iov_len = recv_entry->total_len;

        cur_iov.iov_base = (uint8_t *)cur_iov.iov_base + recv_entry->total_len;
        cur_iov.iov_len -= recv_entry->total_len;

        if (rx_buf->pkt.ctrl_hdr.type != ucr_ctrl_seg)
            ret = ucr_handle_rx_buf(rx_buf);
        else
            ret = ucr_handle_unexp_sar(&ep->recv_queue, recv_entry, rx_buf);

    } while (!ret && cur_iov.iov_len >= ep->min_multi_recv_size);

    if ((cur_iov.iov_len < ep->min_multi_recv_size) ||
        (ret && cur_iov.iov_len != iov->iov_len)) {
        ucr_cq_write(ep->util_ep.rx_cq, context, FI_MULTI_RECV, 0, NULL, 0, 0);
    }

    return ret;
}

static ssize_t ucr_recv_common(struct ucr_ep *ucr_ep, const struct iovec *iov,
                               void **desc, size_t count, fi_addr_t src_addr,
                               void *context, uint64_t op_flags)
{
    struct ucr_recv_entry *recv_entry;
    struct ucr_rx_buf *rx_buf;
    ssize_t ret;

    assert(ucr_ep->util_ep.rx_cq);
    assert(count <= ucr_ep->ucr_info->rx_attr->iov_limit);

    ofi_genlock_lock(&ucr_ep->util_ep.lock);
    if (op_flags & FI_MULTI_RECV) {
        ret = ucr_post_mrecv(ucr_ep, iov, desc, context, op_flags);
        goto release;
    }

    recv_entry = ucr_recv_entry_get(ucr_ep, iov, desc, count, src_addr, 0, 0,
                                    context, op_flags, &ucr_ep->recv_queue);
    if (!recv_entry) {
        ret = -FI_EAGAIN;
        goto release;
    }

    rx_buf = ucr_get_unexp_msg(&ucr_ep->recv_queue, recv_entry->addr, 0, 0);
    if (!rx_buf) {
        dlist_insert_tail(&recv_entry->entry, &ucr_ep->recv_queue.recv_list);
        ret = FI_SUCCESS;
        goto release;
    }

    dlist_remove(&rx_buf->unexp_msg.entry);
    rx_buf->recv_entry = recv_entry;

    ret = (rx_buf->pkt.ctrl_hdr.type != ucr_ctrl_seg) ?
              ucr_handle_rx_buf(rx_buf) :
              ucr_handle_unexp_sar(&ucr_ep->recv_queue, recv_entry, rx_buf);

release:
    ofi_genlock_unlock(&ucr_ep->util_ep.lock);
    return ret;
}

static ssize_t ucr_buf_recv(struct ucr_ep *ucr_ep, const struct iovec *iov,
                            void **desc, size_t count, fi_addr_t src_addr,
                            void *context, uint64_t flags)
{
    struct ucr_recv_entry *recv_entry;
    struct fi_recv_context *recv_ctx = context;
    struct ucr_rx_buf *rx_buf;
    ssize_t ret = 0;

    context = recv_ctx->context;
    rx_buf = container_of(recv_ctx, struct ucr_rx_buf, recv_context);

    ofi_genlock_lock(&ucr_ep->util_ep.lock);
    if (flags & FI_CLAIM) {
        FI_DBG(&ucr_prov, FI_LOG_EP_DATA, "Claiming buffered receive\n");

        recv_entry = ucr_recv_entry_get(ucr_ep, iov, desc, count, src_addr, 0,
                                        0, context, flags, &ucr_ep->recv_queue);
        if (!recv_entry) {
            ret = -FI_EAGAIN;
            goto unlock;
        }

        recv_entry->comp_flags |= FI_CLAIM;

        rx_buf->recv_entry = recv_entry;
        ret = ucr_handle_rx_buf(rx_buf);
    } else {
        assert(flags & FI_DISCARD);
        FI_DBG(&ucr_prov, FI_LOG_EP_DATA, "Discarding buffered receive\n");
        ucr_free_rx_buf(rx_buf);
    }
unlock:
    ofi_genlock_unlock(&ucr_ep->util_ep.lock);
    return ret;
}

static ssize_t ucr_recvmsg(struct fid_ep *ep_fid, const struct fi_msg *msg,
                           uint64_t flags)
{
    struct ucr_ep *ucr_ep =
        container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);

    if (ucr_ep->ucr_info->mode & FI_BUFFERED_RECV)
        return ucr_buf_recv(ucr_ep, msg->msg_iov, msg->desc, msg->iov_count,
                            msg->addr, msg->context,
                            flags | ucr_ep->util_ep.rx_msg_flags);

    return ucr_recv_common(ucr_ep, msg->msg_iov, msg->desc, msg->iov_count,
                           msg->addr, msg->context,
                           flags | ucr_ep->util_ep.rx_msg_flags);
}

static ssize_t ucr_recv(struct fid_ep *ep_fid, void *buf, size_t len,
                        void *desc, fi_addr_t src_addr, void *context)
{
    struct ucr_ep *ucr_ep =
        container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    struct iovec iov = {
        .iov_base = buf,
        .iov_len = len,
    };

    return ucr_recv_common(ucr_ep, &iov, &desc, 1, src_addr, context,
                           ucr_ep->util_ep.rx_op_flags);
}

static ssize_t ucr_recvv(struct fid_ep *ep_fid, const struct iovec *iov,
                         void **desc, size_t count, fi_addr_t src_addr,
                         void *context)
{
    struct ucr_ep *ucr_ep =
        container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);

    return ucr_recv_common(ucr_ep, iov, desc, count, src_addr, context,
                           ucr_ep->util_ep.rx_op_flags);
}

static ssize_t ucr_alloc_rndv_buf(struct ucr_ep *ucr_ep,
                                  struct ucr_conn *ucr_conn, void *context,
                                  uint8_t count, const struct iovec *iov,
                                  void **desc, size_t data_len, uint64_t data,
                                  uint64_t flags, uint64_t tag, uint8_t op,
                                  enum fi_hmem_iface iface, uint64_t device,
                                  struct ucr_tx_buf **rndv_buf)
{
    struct fid_mr *ucr_mr_msg_mr[UCR_IOV_LIMIT];
    struct fid_mr **mr_iov;
    size_t len, i;
    ssize_t ret;

    *rndv_buf = ucr_get_tx_buf(ucr_ep);
    if (!*rndv_buf)
        return -FI_EAGAIN;

    (*rndv_buf)->pkt.ctrl_hdr.type = ucr_ctrl_rndv_req;
    ucr_ep_format_tx_buf_pkt(ucr_conn, data_len, op, data, tag, flags,
                             &(*rndv_buf)->pkt);
    (*rndv_buf)->pkt.ctrl_hdr.msg_id = ofi_buf_index(*rndv_buf);
    (*rndv_buf)->app_context = context;
    (*rndv_buf)->flags = flags;
    (*rndv_buf)->rma.count = count;

    if (!ucr_ep->rdm_mr_local) {
        ret = ucr_msg_mr_regv(ucr_ep, iov, (*rndv_buf)->rma.count, data_len,
                              ucr_ep->rndv_ops->tx_mr_access,
                              (*rndv_buf)->rma.mr);
        if (ret)
            goto err;
        mr_iov = (*rndv_buf)->rma.mr;
    } else {
        for (i = 0; i < count; i++)
            ucr_mr_msg_mr[i] = ((struct ucr_mr *)desc[i])->msg_mr;

        mr_iov = ucr_mr_msg_mr;
    }

    if (ucr_ep->rndv_ops == &ucr_rndv_ops_write) {
        (*rndv_buf)->write_rndv.conn = ucr_conn;
        for (i = 0; i < count; i++) {
            (*rndv_buf)->write_rndv.iov[i] = iov[i];
            (*rndv_buf)->write_rndv.desc[i] = fi_mr_desc(mr_iov[i]);
        }
    }

    ucr_rndv_hdr_init(ucr_ep, &(*rndv_buf)->pkt.data, iov,
                      (*rndv_buf)->rma.count, mr_iov);

    len = sizeof(struct ucr_pkt) + sizeof(struct ucr_rndv_hdr);

    if (ucr_ep->ucr_info->mode & FI_BUFFERED_RECV) {
        ret = ofi_copy_from_hmem_iov(ucr_pkt_rndv_data(&(*rndv_buf)->pkt),
                                     ucr_ep->buffered_min, iface, device, iov,
                                     count, 0);
        assert((size_t)ret == ucr_ep->buffered_min);

        len += ucr_ep->buffered_min;
    }

    return len;

err:
    ucr_free_tx_buf(ucr_ep, *rndv_buf);
    return ret;
}

static ssize_t ucr_send_rndv(struct ucr_ep *ucr_ep, struct ucr_conn *ucr_conn,
                             struct ucr_tx_buf *tx_buf, size_t pkt_size)
{
    ssize_t ret;

    if (pkt_size <= ucr_ep->inject_limit) {
        if (ucr_ep->rndv_ops == &ucr_rndv_ops_write)
            UCR_UPDATE_STATE(FI_LOG_EP_DATA, tx_buf, UCR_RNDV_WRITE_DATA_WAIT);
        else
            UCR_UPDATE_STATE(FI_LOG_EP_DATA, tx_buf, UCR_RNDV_READ_DONE_WAIT);

        ret = fi_inject(ucr_conn->msg_ep, &tx_buf->pkt, pkt_size, 0);
    } else {
        UCR_UPDATE_STATE(FI_LOG_EP_DATA, tx_buf, UCR_RNDV_TX);
        ret = fi_send(ucr_conn->msg_ep, &tx_buf->pkt, pkt_size,
                      tx_buf->hdr.desc, 0, tx_buf);
    }

    if (ret)
        goto err;

    return FI_SUCCESS;

err:
    FI_DBG(&ucr_prov, FI_LOG_EP_DATA, "Transmit for MSG provider failed\n");
    if (!ucr_ep->rdm_mr_local)
        ucr_msg_mr_closev(tx_buf->rma.mr, tx_buf->rma.count);
    ucr_free_tx_buf(ucr_ep, tx_buf);
    return ret;
}

static size_t ucr_ep_sar_calc_segs_cnt(struct ucr_ep *ucr_ep, size_t data_len)
{
    return (data_len + ucr_buffer_size - 1) / ucr_buffer_size;
}

static struct ucr_tx_buf *ucr_init_segment(
    struct ucr_ep *ucr_ep, struct ucr_conn *ucr_conn, void *app_context,
    size_t total_len, size_t seg_len, size_t seg_no, uint64_t data,
    uint64_t flags, uint64_t tag, uint8_t op, enum ucr_sar_seg_type seg_type,
    uint64_t *msg_id)
{
    struct ucr_tx_buf *tx_buf;

    tx_buf = ucr_get_tx_buf(ucr_ep);
    if (!tx_buf)
        return NULL;

    tx_buf->hdr.state = UCR_SAR_TX;
    tx_buf->pkt.ctrl_hdr.type = ucr_ctrl_seg;

    ucr_ep_format_tx_buf_pkt(ucr_conn, total_len, op, data, tag, flags,
                             &tx_buf->pkt);
    if (seg_type == UCR_SAR_SEG_FIRST) {
        *msg_id = tx_buf->pkt.ctrl_hdr.msg_id = ofi_buf_index(tx_buf);
    } else {
        tx_buf->pkt.ctrl_hdr.msg_id = *msg_id;
    }
    tx_buf->pkt.ctrl_hdr.seg_size = (uint16_t)seg_len;
    tx_buf->pkt.ctrl_hdr.seg_no = (uint32_t)seg_no;
    tx_buf->app_context = app_context;
    tx_buf->flags = flags;
    ucr_sar_set_seg_type(&tx_buf->pkt.ctrl_hdr, seg_type);

    return tx_buf;
}

ssize_t ucr_send_segment(struct ucr_ep *ucr_ep, struct ucr_conn *ucr_conn,
                         void *app_context, size_t data_len, size_t remain_len,
                         uint64_t msg_id, size_t seg_len, size_t seg_no,
                         size_t segs_cnt, uint64_t data, uint64_t flags,
                         uint64_t tag, uint8_t op, const struct iovec *iov,
                         uint8_t count, size_t *iov_offset,
                         struct ucr_tx_buf **out_tx_buf,
                         enum fi_hmem_iface iface, uint64_t device)
{
    struct ucr_tx_buf *tx_buf;
    enum ucr_sar_seg_type seg_type = UCR_SAR_SEG_MIDDLE;
    ssize_t ret __attribute__((unused));

    if (seg_no == (segs_cnt - 1)) {
        seg_type = UCR_SAR_SEG_LAST;
        assert(remain_len <= seg_len);
        seg_len = remain_len;
    }

    tx_buf = ucr_init_segment(ucr_ep, ucr_conn, app_context, data_len, seg_len,
                              seg_no, data, flags, tag, op, seg_type, &msg_id);
    if (!tx_buf) {
        *out_tx_buf = NULL;
        return -FI_EAGAIN;
    }

    ret = ofi_copy_from_hmem_iov(tx_buf->pkt.data, seg_len, iface, device, iov,
                                 count, *iov_offset);
    assert((size_t)ret == seg_len);

    *iov_offset += seg_len;

    *out_tx_buf = tx_buf;

    return fi_send(ucr_conn->msg_ep, &tx_buf->pkt,
                   sizeof(struct ucr_pkt) + tx_buf->pkt.ctrl_hdr.seg_size,
                   tx_buf->hdr.desc, 0, tx_buf);
}

static ssize_t ucr_send_sar(struct ucr_ep *ucr_ep, struct ucr_conn *ucr_conn,
                            const struct iovec *iov, void **desc, uint8_t count,
                            void *context, uint64_t data, uint64_t flags,
                            uint64_t tag, uint8_t op, size_t data_len,
                            size_t segs_cnt)
{
    struct ucr_tx_buf *tx_buf, *first_tx_buf;
    size_t i, iov_offset = 0, remain_len = data_len;
    struct ucr_deferred_tx_entry *def_tx;
    enum fi_hmem_iface iface;
    uint64_t device;
    uint64_t msg_id = 0;
    ssize_t ret;

    assert(segs_cnt >= 2);
    iface = ucr_mr_desc_to_hmem_iface_dev(desc, count, &device);

    first_tx_buf =
        ucr_init_segment(ucr_ep, ucr_conn, context, data_len, ucr_buffer_size,
                         0, data, flags, tag, op, UCR_SAR_SEG_FIRST, &msg_id);
    if (!first_tx_buf)
        return -FI_EAGAIN;

    ret = ofi_copy_from_hmem_iov(first_tx_buf->pkt.data, ucr_buffer_size, iface,
                                 device, iov, count, iov_offset);
    assert((size_t)ret == ucr_buffer_size);

    iov_offset += ucr_buffer_size;

    ret = fi_send(ucr_conn->msg_ep, &first_tx_buf->pkt,
                  sizeof(struct ucr_pkt) + first_tx_buf->pkt.ctrl_hdr.seg_size,
                  first_tx_buf->hdr.desc, 0, first_tx_buf);
    if (ret) {
        if (ret == -FI_EAGAIN)
            ucr_ep_do_progress(&ucr_ep->util_ep);
        ucr_free_tx_buf(ucr_ep, first_tx_buf);
        return ret;
    }

    remain_len -= ucr_buffer_size;

    for (i = 1; i < segs_cnt; i++) {
        ret = ucr_send_segment(ucr_ep, ucr_conn, context, data_len, remain_len,
                               msg_id, ucr_buffer_size, i, segs_cnt, data,
                               flags, tag, op, iov, count, &iov_offset, &tx_buf,
                               iface, device);
        if (ret) {
            if (ret == -FI_EAGAIN)
                goto defer;
            goto free;
        }
        remain_len -= ucr_buffer_size;
    }

    return 0;

free:
    ucr_free_tx_buf(ucr_ep, first_tx_buf);
    return ret;
defer:
    def_tx = ucr_ep_alloc_deferred_tx_entry(ucr_ep, ucr_conn,
                                            UCR_DEFERRED_TX_SAR_SEG);
    if (!def_tx) {
        if (tx_buf)
            ucr_free_tx_buf(ucr_ep, tx_buf);
        return -FI_ENOMEM;
    }
    memcpy(def_tx->sar_seg.payload.iov, iov, sizeof(*iov) * count);
    def_tx->sar_seg.payload.count = count;
    def_tx->sar_seg.payload.cur_iov_offset = iov_offset;
    def_tx->sar_seg.payload.tag = tag;
    def_tx->sar_seg.payload.data = data;
    def_tx->sar_seg.cur_seg_tx_buf = tx_buf;
    def_tx->sar_seg.app_context = context;
    def_tx->sar_seg.flags = flags;
    def_tx->sar_seg.op = op;
    def_tx->sar_seg.next_seg_no = i;
    def_tx->sar_seg.segs_cnt = segs_cnt;
    def_tx->sar_seg.total_len = data_len;
    def_tx->sar_seg.remain_len = remain_len;
    def_tx->sar_seg.msg_id = msg_id;
    def_tx->sar_seg.iface = iface;
    def_tx->sar_seg.device = device;
    ucr_queue_deferred_tx(def_tx, OFI_LIST_TAIL);
    return 0;
}

static ssize_t ucr_emulate_inject(struct ucr_ep *ucr_ep,
                                  struct ucr_conn *ucr_conn, const void *buf,
                                  size_t len, size_t pkt_size, uint64_t data,
                                  uint64_t flags, uint64_t tag, uint8_t op)
{
    struct ucr_tx_buf *tx_buf;
    ssize_t ret;

    tx_buf = ucr_get_tx_buf(ucr_ep);
    if (!tx_buf)
        return -FI_EAGAIN;

    tx_buf->hdr.state = UCR_INJECT_TX;
    tx_buf->pkt.ctrl_hdr.type = ucr_ctrl_eager;
    tx_buf->flags = flags;

    ucr_ep_format_tx_buf_pkt(ucr_conn, len, op, data, tag, flags, &tx_buf->pkt);
    memcpy(tx_buf->pkt.data, buf, len);

    ret = fi_send(ucr_conn->msg_ep, &tx_buf->pkt, pkt_size, tx_buf->hdr.desc, 0,
                  tx_buf);
    if (ret) {
        if (ret == -FI_EAGAIN)
            ucr_ep_do_progress(&ucr_ep->util_ep);
        ucr_free_tx_buf(ucr_ep, tx_buf);
    }
    return ret;
}

ssize_t ucr_inject_send(struct ucr_ep *ucr_ep, struct ucr_conn *ucr_conn,
                        const void *buf, size_t len)
{
    struct ucr_pkt *inject_pkt = ucr_ep->inject_pkt;
    size_t pkt_size = sizeof(*inject_pkt) + len;
    ssize_t ret;

    assert(len <= ucr_ep->ucr_info->tx_attr->inject_size);

    inject_pkt->ctrl_hdr.conn_id = ucr_conn->remote_index;
    if (pkt_size <= ucr_ep->inject_limit && !ucr_ep->util_ep.cntrs[CNTR_TX]) {
        inject_pkt->hdr.size = len;
        memcpy(inject_pkt->data, buf, len);
        ret = fi_inject(ucr_conn->msg_ep, inject_pkt, pkt_size, 0);
    } else {
        ret = ucr_emulate_inject(ucr_ep, ucr_conn, buf, len, pkt_size,
                                 inject_pkt->hdr.data, inject_pkt->hdr.flags,
                                 inject_pkt->hdr.tag, inject_pkt->hdr.op);
    }
    return ret;
}

static bool ucr_use_direct_send(struct ucr_ep *ep, size_t iov_count,
                                uint64_t flags)
{
    return ep->enable_direct_send &&
           (iov_count < ep->msg_info->tx_attr->iov_limit);
}

static ssize_t ucr_direct_send(struct ucr_ep *ep, struct ucr_conn *ucr_conn,
                               struct ucr_tx_buf *tx_buf,
                               const struct iovec *iov, void **desc,
                               size_t count)
{
    struct iovec send_iov[UCR_IOV_LIMIT];
    void *send_desc[UCR_IOV_LIMIT];
    struct ucr_mr *mr;
    ssize_t ret;
    int i;

    send_iov[0].iov_base = &tx_buf->pkt;
    send_iov[0].iov_len = sizeof(tx_buf->pkt);
    memcpy(&send_iov[1], iov, sizeof(*iov) * count);

    if (ep->msg_mr_local) {
        send_desc[0] = tx_buf->hdr.desc;

        for (i = 0; i < count; i++) {
            assert(desc[i]);
            mr = desc[i];
            send_desc[i + 1] = fi_mr_desc(mr->msg_mr);
        }

        ret = fi_sendv(ucr_conn->msg_ep, send_iov, send_desc, count + 1, 0,
                       tx_buf);
    } else {
        ret = fi_sendv(ucr_conn->msg_ep, send_iov, NULL, count + 1, 0, tx_buf);
    }
    return ret;
}

static ssize_t ucr_send_eager(struct ucr_ep *ucr_ep, struct ucr_conn *ucr_conn,
                              const struct iovec *iov, void **desc,
                              size_t count, void *context, uint64_t data,
                              uint64_t flags, uint64_t tag, uint8_t op,
                              size_t data_len, size_t total_len)
{
    struct ucr_tx_buf *eager_buf;
    ssize_t ret;

    eager_buf = ucr_get_tx_buf(ucr_ep);
    if (!eager_buf)
        return -FI_EAGAIN;

    eager_buf->hdr.state = UCR_TX;
    eager_buf->pkt.ctrl_hdr.type = ucr_ctrl_eager;
    eager_buf->app_context = context;
    eager_buf->flags = flags;

    if (ucr_use_direct_send(ucr_ep, count, flags)) {
        ucr_ep_format_tx_buf_pkt(ucr_conn, data_len, op, data, tag, flags,
                                 &eager_buf->pkt);

        ret = ucr_direct_send(ucr_ep, ucr_conn, eager_buf, iov, desc, count);
    } else {
        ucr_ep_format_tx_buf_pkt(ucr_conn, data_len, op, data, tag, flags,
                                 &eager_buf->pkt);
        ret = ucr_copy_from_hmem_iov(desc, eager_buf->pkt.data,
                                     eager_buf->pkt.hdr.size, iov, count, 0);
        assert((size_t)ret == eager_buf->pkt.hdr.size);
        ret = fi_send(ucr_conn->msg_ep, &eager_buf->pkt, total_len,
                      eager_buf->hdr.desc, 0, eager_buf);
    }

    if (ret) {
        if (ret == -FI_EAGAIN)
            ucr_ep_do_progress(&ucr_ep->util_ep);
        ucr_free_tx_buf(ucr_ep, eager_buf);
    }
    return ret;
}

ssize_t ucr_send_common(struct ucr_ep *ucr_ep, struct ucr_conn *ucr_conn,
                        const struct iovec *iov, void **desc, size_t count,
                        void *context, uint64_t data, uint64_t flags,
                        uint64_t tag, uint8_t op)
{
    struct ucr_tx_buf *rndv_buf;
    size_t data_len, total_len;
    enum fi_hmem_iface iface;
    uint64_t device;
    ssize_t ret;

    if (flags & FI_PEER_TRANSFER)
        tag |= UCR_PEER_XFER_TAG_FLAG;

    data_len = ofi_total_iov_len(iov, count);
    total_len = sizeof(struct ucr_pkt) + data_len;

    assert(count <= ucr_ep->ucr_info->tx_attr->iov_limit);
    assert((!(flags & FI_INJECT) &&
            (data_len > ucr_ep->ucr_info->tx_attr->inject_size)) ||
           (data_len <= ucr_ep->ucr_info->tx_attr->inject_size));

    iface = ucr_mr_desc_to_hmem_iface_dev(desc, count, &device);
    if (iface == FI_HMEM_ZE || iface == FI_HMEM_SYNAPSEAI)
        goto rndv_send;

    if (data_len <= ucr_ep->eager_limit) {
        ret = ucr_send_eager(ucr_ep, ucr_conn, iov, desc, count, context, data,
                             flags, tag, op, data_len, total_len);
    } else if (data_len <= ucr_ep->sar_limit) {
        ret = ucr_send_sar(ucr_ep, ucr_conn, iov, desc, (uint8_t)count, context,
                           data, flags, tag, op, data_len,
                           ucr_ep_sar_calc_segs_cnt(ucr_ep, data_len));
    } else {
    rndv_send:
        ret = ucr_alloc_rndv_buf(ucr_ep, ucr_conn, context, (uint8_t)count, iov,
                                 desc, data_len, data, flags, tag, op, iface,
                                 device, &rndv_buf);
        if (ret >= 0)
            ret = ucr_send_rndv(ucr_ep, ucr_conn, rndv_buf, ret);
    }

    return ret;
}

static ssize_t ucr_sendmsg(struct fid_ep *ep_fid, const struct fi_msg *msg,
                           uint64_t flags)
{
    struct ucr_conn *ucr_conn;
    struct ucr_ep *ucr_ep;
    ssize_t ret;

    ucr_ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    ofi_genlock_lock(&ucr_ep->util_ep.lock);
    ret = ucr_get_conn(ucr_ep, msg->addr, &ucr_conn);
    if (ret)
        goto unlock;

    ret = ucr_send_common(ucr_ep, ucr_conn, msg->msg_iov, msg->desc,
                          msg->iov_count, msg->context, msg->data,
                          flags | ucr_ep->util_ep.tx_msg_flags, 0, ofi_op_msg);
unlock:
    ofi_genlock_unlock(&ucr_ep->util_ep.lock);
    return ret;
}

static ssize_t ucr_send(struct fid_ep *ep_fid, const void *buf, size_t len,
                        void *desc, fi_addr_t dest_addr, void *context)
{
    struct ucr_conn *ucr_conn;
    struct ucr_ep *ucr_ep;
    struct iovec iov = {
        .iov_base = (void *)buf,
        .iov_len = len,
    };
    ssize_t ret;

    ucr_ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    ofi_genlock_lock(&ucr_ep->util_ep.lock);
    ret = ucr_get_conn(ucr_ep, dest_addr, &ucr_conn);
    if (ret)
        goto unlock;

    ret = ucr_send_common(ucr_ep, ucr_conn, &iov, &desc, 1, context, 0,
                          ucr_ep->util_ep.tx_op_flags, 0, ofi_op_msg);
unlock:
    ofi_genlock_unlock(&ucr_ep->util_ep.lock);
    return ret;
}

static ssize_t ucr_sendv(struct fid_ep *ep_fid, const struct iovec *iov,
                         void **desc, size_t count, fi_addr_t dest_addr,
                         void *context)
{
    struct ucr_conn *ucr_conn;
    struct ucr_ep *ucr_ep;
    ssize_t ret;

    ucr_ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    ofi_genlock_lock(&ucr_ep->util_ep.lock);
    ret = ucr_get_conn(ucr_ep, dest_addr, &ucr_conn);
    if (ret)
        goto unlock;

    ret = ucr_send_common(ucr_ep, ucr_conn, iov, desc, count, context, 0,
                          ucr_ep->util_ep.tx_op_flags, 0, ofi_op_msg);
unlock:
    ofi_genlock_unlock(&ucr_ep->util_ep.lock);
    return ret;
}

static ssize_t ucr_inject(struct fid_ep *ep_fid, const void *buf, size_t len,
                          fi_addr_t dest_addr)
{
    struct ucr_conn *ucr_conn;
    struct ucr_ep *ucr_ep;
    ssize_t ret;

    ucr_ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    ofi_genlock_lock(&ucr_ep->util_ep.lock);
    ret = ucr_get_conn(ucr_ep, dest_addr, &ucr_conn);
    if (ret)
        goto unlock;

    ucr_ep->inject_pkt->hdr.op = ofi_op_msg;
    ucr_ep->inject_pkt->hdr.flags = 0;
    ucr_ep->inject_pkt->hdr.tag = 0;
    ucr_ep->inject_pkt->hdr.data = 0;

    ret = ucr_inject_send(ucr_ep, ucr_conn, buf, len);
unlock:
    ofi_genlock_unlock(&ucr_ep->util_ep.lock);
    return ret;
}

static ssize_t ucr_senddata(struct fid_ep *ep_fid, const void *buf, size_t len,
                            void *desc, uint64_t data, fi_addr_t dest_addr,
                            void *context)
{
    struct ucr_conn *ucr_conn;
    struct ucr_ep *ucr_ep;
    struct iovec iov = {
        .iov_base = (void *)buf,
        .iov_len = len,
    };
    ssize_t ret;

    ucr_ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    ofi_genlock_lock(&ucr_ep->util_ep.lock);
    ret = ucr_get_conn(ucr_ep, dest_addr, &ucr_conn);
    if (ret)
        goto unlock;

    ret = ucr_send_common(ucr_ep, ucr_conn, &iov, &desc, 1, context, data,
                          ucr_ep->util_ep.tx_op_flags | FI_REMOTE_CQ_DATA, 0,
                          ofi_op_msg);
unlock:
    ofi_genlock_unlock(&ucr_ep->util_ep.lock);
    return ret;
}

static ssize_t ucr_injectdata(struct fid_ep *ep_fid, const void *buf,
                              size_t len, uint64_t data, fi_addr_t dest_addr)
{
    struct ucr_conn *ucr_conn;
    struct ucr_ep *ucr_ep;
    ssize_t ret;

    ucr_ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    ofi_genlock_lock(&ucr_ep->util_ep.lock);
    ret = ucr_get_conn(ucr_ep, dest_addr, &ucr_conn);
    if (ret)
        goto unlock;

    ucr_ep->inject_pkt->hdr.op = ofi_op_msg;
    ucr_ep->inject_pkt->hdr.flags = FI_REMOTE_CQ_DATA;
    ucr_ep->inject_pkt->hdr.tag = 0;
    ucr_ep->inject_pkt->hdr.data = data;

    ret = ucr_inject_send(ucr_ep, ucr_conn, buf, len);
unlock:
    ofi_genlock_unlock(&ucr_ep->util_ep.lock);
    return ret;
}

struct fi_ops_msg ucr_msg_ops = {
    .size = sizeof(struct fi_ops_msg),
    .recv = ucr_recv,
    .recvv = ucr_recvv,
    .recvmsg = ucr_recvmsg,
    .send = ucr_send,
    .sendv = ucr_sendv,
    .sendmsg = ucr_sendmsg,
    .inject = ucr_inject,
    .senddata = ucr_senddata,
    .injectdata = ucr_injectdata,
};

static ssize_t ucr_recv_thru(struct fid_ep *ep_fid, void *buf, size_t len,
                             void *desc, fi_addr_t src_addr, void *context)
{
    struct ucr_ep *ep;
    ssize_t ret;

    ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    assert(ep->msg_srx);

    ofi_genlock_lock(&ep->util_ep.lock);
    ret = fi_recv(ep->msg_srx, buf, len, desc, src_addr, context);
    ofi_genlock_unlock(&ep->util_ep.lock);
    return ret;
}

static ssize_t ucr_recvv_thru(struct fid_ep *ep_fid, const struct iovec *iov,
                              void **desc, size_t count, fi_addr_t src_addr,
                              void *context)
{
    struct ucr_ep *ep;
    ssize_t ret;

    ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    assert(ep->msg_srx);

    ofi_genlock_lock(&ep->util_ep.lock);
    ret = fi_recvv(ep->msg_srx, iov, desc, count, src_addr, context);
    ofi_genlock_unlock(&ep->util_ep.lock);
    return ret;
}

static ssize_t ucr_recvmsg_thru(struct fid_ep *ep_fid, const struct fi_msg *msg,
                                uint64_t flags)
{
    struct ucr_ep *ep;
    ssize_t ret;

    ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    assert(ep->msg_srx);

    ofi_genlock_lock(&ep->util_ep.lock);
    ret = fi_recvmsg(ep->msg_srx, msg, flags);
    ofi_genlock_unlock(&ep->util_ep.lock);
    return ret;
}

static ssize_t ucr_send_thru(struct fid_ep *ep_fid, const void *buf, size_t len,
                             void *desc, fi_addr_t dest_addr, void *context)
{
    struct ucr_conn *conn;
    struct ucr_ep *ep;
    ssize_t ret;

    ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    ofi_genlock_lock(&ep->util_ep.lock);

    ret = ucr_get_conn(ep, dest_addr, &conn);
    if (ret)
        goto unlock;

    ret = fi_send(conn->msg_ep, buf, len, desc, 0, context);
unlock:
    ofi_genlock_unlock(&ep->util_ep.lock);
    return ret;
}

static ssize_t ucr_sendv_thru(struct fid_ep *ep_fid, const struct iovec *iov,
                              void **desc, size_t count, fi_addr_t dest_addr,
                              void *context)
{
    struct ucr_conn *conn;
    struct ucr_ep *ep;
    ssize_t ret;

    ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    ofi_genlock_lock(&ep->util_ep.lock);

    ret = ucr_get_conn(ep, dest_addr, &conn);
    if (ret)
        goto unlock;

    ret = fi_sendv(conn->msg_ep, iov, desc, count, 0, context);
unlock:
    ofi_genlock_unlock(&ep->util_ep.lock);
    return ret;
}

static ssize_t ucr_sendmsg_thru(struct fid_ep *ep_fid, const struct fi_msg *msg,
                                uint64_t flags)
{
    struct ucr_conn *conn;
    struct ucr_ep *ep;
    ssize_t ret;

    ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    ofi_genlock_lock(&ep->util_ep.lock);

    ret = ucr_get_conn(ep, msg->addr, &conn);
    if (ret)
        goto unlock;

    ret = fi_sendmsg(conn->msg_ep, msg, flags);
unlock:
    ofi_genlock_unlock(&ep->util_ep.lock);
    return ret;
}

static ssize_t ucr_inject_thru(struct fid_ep *ep_fid, const void *buf,
                               size_t len, fi_addr_t dest_addr)
{
    struct ucr_conn *conn;
    struct ucr_ep *ep;
    ssize_t ret;

    ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    ofi_genlock_lock(&ep->util_ep.lock);

    ret = ucr_get_conn(ep, dest_addr, &conn);
    if (ret)
        goto unlock;

    ret = fi_inject(conn->msg_ep, buf, len, 0);
unlock:
    ofi_genlock_unlock(&ep->util_ep.lock);
    return ret;
}

static ssize_t ucr_senddata_thru(struct fid_ep *ep_fid, const void *buf,
                                 size_t len, void *desc, uint64_t data,
                                 fi_addr_t dest_addr, void *context)
{
    struct ucr_conn *conn;
    struct ucr_ep *ep;
    ssize_t ret;

    ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    ofi_genlock_lock(&ep->util_ep.lock);

    ret = ucr_get_conn(ep, dest_addr, &conn);
    if (ret)
        goto unlock;

    ret = fi_senddata(conn->msg_ep, buf, len, desc, data, 0, context);
unlock:
    ofi_genlock_unlock(&ep->util_ep.lock);
    return ret;
}

static ssize_t ucr_injectdata_thru(struct fid_ep *ep_fid, const void *buf,
                                   size_t len, uint64_t data,
                                   fi_addr_t dest_addr)
{
    struct ucr_conn *conn;
    struct ucr_ep *ep;
    ssize_t ret;

    ep = container_of(ep_fid, struct ucr_ep, util_ep.ep_fid.fid);
    ofi_genlock_lock(&ep->util_ep.lock);

    ret = ucr_get_conn(ep, dest_addr, &conn);
    if (ret)
        goto unlock;

    ret = fi_injectdata(conn->msg_ep, buf, len, data, 0);
unlock:
    ofi_genlock_unlock(&ep->util_ep.lock);
    return ret;
}

struct fi_ops_msg ucr_msg_thru_ops = {
    .size = sizeof(struct fi_ops_msg),
    .recv = ucr_recv_thru,
    .recvv = ucr_recvv_thru,
    .recvmsg = ucr_recvmsg_thru,
    .send = ucr_send_thru,
    .sendv = ucr_sendv_thru,
    .sendmsg = ucr_sendmsg_thru,
    .inject = ucr_inject_thru,
    .senddata = ucr_senddata_thru,
    .injectdata = ucr_injectdata_thru,
};
