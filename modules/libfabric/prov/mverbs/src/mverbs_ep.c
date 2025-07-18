/*
 * Copyright (c) Intel Corporation, Inc.  All rights reserved.
 * Copyright (c) 2019 System Fabric Works, Inc. All rights reserved.
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

#include "config.h"

#include "mverbs_ofi.h"

static struct fi_ops_msg mverbs_srq_msg_ops;

void mverbs_add_credits(struct fid_ep *ep_fid, uint64_t credits)
{
    struct mverbs_ep *ep;

    ep = container_of(ep_fid, struct mverbs_ep, util_ep.ep_fid);

    ofi_genlock_lock(&mverbs_ep2_progress(ep)->ep_lock);
    /*
     * 'saved_peer_rq_credits' is only for the credit update coming before
     * flow_ctrl_ops->enable() is called, at which point 'peer_rq_credits'
     * is guaranteed to be UNIT64_MAX because no send has happened yet.
     */
    if (ep->peer_rq_credits == UINT64_MAX)
        ep->saved_peer_rq_credits += credits;
    else
        ep->peer_rq_credits += credits;
    ofi_genlock_unlock(&mverbs_ep2_progress(ep)->ep_lock);
}

ssize_t mverbs_post_recv(struct mverbs_ep *ep, struct ibv_recv_wr *wr)
{
    struct mverbs_context *ctx;
    struct ibv_recv_wr *bad_wr;
    uint64_t credits_to_give;
    int ret, err;

    ofi_genlock_lock(&mverbs_ep2_progress(ep)->ep_lock);
    ctx = mverbs_alloc_ctx(mverbs_ep2_progress(ep));
    if (!ctx) {
        ret = -FI_EAGAIN;
        goto unlock;
    }

    ctx->ep = ep;
    ctx->user_ctx = (void *)(uintptr_t)wr->wr_id;
    ctx->op_queue = VRB_OP_RQ;
    wr->wr_id = (uintptr_t)ctx;

    ret = ibv_post_recv(ep->ibv_qp, wr, &bad_wr);
    wr->wr_id = (uintptr_t)ctx->user_ctx;
    if (ret) {
        mverbs_free_ctx(mverbs_ep2_progress(ep), ctx);
        ret = -FI_EAGAIN;
        goto unlock;
    }

    slist_insert_tail(&ctx->entry, &ep->rq_list);
    if (++ep->rq_credits_avail >= ep->threshold) {
        credits_to_give = ep->rq_credits_avail;
        ep->rq_credits_avail = 0;
    } else {
        credits_to_give = 0;
    }

    if (credits_to_give) {
        /* FIXME: we have to drop the lock here, since send_credits
         * calls back to rxm, which calls back to verbs to send a
         * credit message.  That path re-acquires the lock.  Fix this
         * by having send_credit go through a separate path which will
         * avoid acquiring the lock.  This requires changing rxm's
         * deferred tx queue.
         */
        ofi_genlock_unlock(&mverbs_ep2_progress(ep)->ep_lock);

        err = mverbs_ep2_domain(ep)->send_credits(&ep->util_ep.ep_fid,
                                                  credits_to_give);
        ofi_genlock_lock(&mverbs_ep2_progress(ep)->ep_lock);
        if (err)
            ep->rq_credits_avail += credits_to_give;
    }

unlock:
    ofi_genlock_unlock(&mverbs_ep2_progress(ep)->ep_lock);
    return ret;
}

void mverbs_shutdown_ep(struct mverbs_ep *ep)
{
    struct fi_eq_cm_entry entry;

    if (!ep)
        return;

    ofi_genlock_held(mverbs_ep2_progress(ep)->active_lock);
    if (ep->state != VRB_CONNECTED || !ep->eq)
        return;

    ep->state = VRB_DISCONNECTED;
    memset(&entry, 0, sizeof(entry));
    entry.fid = &ep->util_ep.ep_fid.fid;
    (void)mverbs_eq_write_event(ep->eq, FI_SHUTDOWN, &entry, sizeof(entry));
}

ssize_t mverbs_post_send(struct mverbs_ep *ep, struct ibv_send_wr *wr,
                         uint64_t flags)
{
    struct mverbs_context *ctx;
    struct ibv_send_wr *bad_wr;
    struct mverbs_cq *cq;
    size_t credits_to_give = 0;
    int ret, err;

    ofi_genlock_lock(&mverbs_ep2_progress(ep)->ep_lock);
    ctx = mverbs_alloc_ctx(mverbs_ep2_progress(ep));
    if (!ctx) {
        ret = -FI_EAGAIN;
        goto unlock;
    }

    if (!ep->sq_credits || !ep->peer_rq_credits) {
        cq = container_of(ep->util_ep.rx_cq, struct mverbs_cq, util_cq);
        mverbs_flush_cq(cq);

        if (!ep->sq_credits || !ep->peer_rq_credits)
            goto freectx;
    }

    if (mverbs_wr_consumes_recv(wr) && !--ep->peer_rq_credits &&
        !(flags & FI_PRIORITY)) {
        /* Last credit is reserved for credit update */
        ep->peer_rq_credits++;
        goto freectx;
    }

    ep->sq_credits--;

    ctx->ep = ep;
    ctx->user_ctx = (void *)(uintptr_t)wr->wr_id;
    ctx->op_queue = VRB_OP_SQ;
    ctx->sq_opcode = wr->opcode;
    wr->wr_id = (uintptr_t)ctx;

    ret = ibv_post_send(ep->ibv_qp, wr, &bad_wr);
    wr->wr_id = (uintptr_t)ctx->user_ctx;
    if (ret) {
        VRB_WARN(FI_LOG_EP_DATA, "Post send failed - %zd\n",
                 mverbs_convert_ret(ret));
        goto credits;
    }
    slist_insert_tail(&ctx->entry, &ep->sq_list);

unlock:
    ofi_genlock_unlock(&mverbs_ep2_progress(ep)->ep_lock);
    return ret;

credits:
    if (mverbs_wr_consumes_recv(wr))
        ep->peer_rq_credits++;
    ep->sq_credits++;

    if (ep->rq_credits_avail >= ep->threshold) {
        credits_to_give = ep->rq_credits_avail;
        ep->rq_credits_avail = 0;
    }

    if (credits_to_give) {
        /* FIXME: we have to drop the lock here, since send_credits
         * calls back to rxm, which calls back to verbs to send a
         * credit message.  That path re-acquires the lock.  Fix this
         * by having send_credit go through a separate path which will
         * avoid acquiring the lock.  This requires changing rxm's
         * deferred tx queue.
         */
        ofi_genlock_unlock(&mverbs_ep2_progress(ep)->ep_lock);

        err = mverbs_ep2_domain(ep)->send_credits(&ep->util_ep.ep_fid,
                                                  credits_to_give);
        ofi_genlock_lock(&mverbs_ep2_progress(ep)->ep_lock);
        if (err)
            ep->rq_credits_avail += credits_to_give;
    }

freectx:
    mverbs_free_ctx(mverbs_ep2_progress(ep), ctx);
    ofi_genlock_unlock(&mverbs_ep2_progress(ep)->ep_lock);
    return -FI_EAGAIN;
}

ssize_t mverbs_send_iov(struct mverbs_ep *ep, struct ibv_send_wr *wr,
                        const struct iovec *iov, void **desc, int count,
                        uint64_t flags)
{
    enum fi_hmem_iface iface;
    uint64_t device;
    void *bounce_buf;
    void *send_desc;
    size_t i, len = 0;
    ssize_t ret;

    wr->sg_list = alloca(sizeof(*wr->sg_list) * count);
    for (i = 0; i < count; i++) {
        wr->sg_list[i].addr = (uintptr_t)iov[i].iov_base;
        wr->sg_list[i].length = iov[i].iov_len;
        wr->sg_list[i].lkey =
            desc ? ((struct mverbs_mem_desc *)desc[i])->lkey : 0;
        len += iov[i].iov_len;
    }

    if (desc) {
        iface = ((struct mverbs_mem_desc *)desc[0])->info.iface;
        device = ((struct mverbs_mem_desc *)desc[0])->info.device;
        send_desc = desc[0];

        wr->send_flags = MVERBS_INJECT_FLAGS(ep, len, flags, send_desc);
    } else {
        iface = FI_HMEM_SYSTEM;
        device = 0;
        send_desc = NULL;

        wr->send_flags = IBV_SEND_INLINE;
    }

    if (wr->send_flags & IBV_SEND_INLINE) {
        bounce_buf = alloca(len);
        ret = ofi_copy_from_hmem_iov(bounce_buf, len, iface, device, iov, count,
                                     0);
        if (ret != len) {
            VRB_WARN(FI_LOG_EP_DATA, "hmem copy error");
            return -FI_EIO;
        }

        wr->sg_list[0] = mverbs_init_sge(bounce_buf, len, NULL);
        wr->num_sge = 1;
    } else {
        wr->num_sge = count;
    }

    wr->wr_id = MVERBS_COMP_FLAGS(ep, flags, wr->wr_id);
    if (flags & FI_FENCE)
        wr->send_flags |= IBV_SEND_FENCE;

    ret = mverbs_post_send(ep, wr, flags);
    return ret;
}

static inline int mverbs_msg_ep_cmdata_size(fid_t fid)
{
    struct mverbs_pep *pep;
    struct mverbs_ep *ep;
    bool is_xrc;

    switch (fid->fclass) {
        case FI_CLASS_PEP:
            pep = container_of(fid, struct mverbs_pep, pep_fid.fid);
            is_xrc = mverbs_is_xrc_info(pep->info);
            break;
        case FI_CLASS_EP:
            ep = container_of(fid, struct mverbs_ep, util_ep.ep_fid.fid);
            is_xrc = mverbs_is_xrc_ep(ep);
            break;
        default:
            is_xrc = 0;
    };
    if (is_xrc)
        return MVERBS_CM_DATA_SIZE - sizeof(struct mverbs_xrc_cm_data);
    else
        return MVERBS_CM_DATA_SIZE;
}

static int mverbs_ep_getopt(fid_t fid, int level, int optname, void *optval,
                            size_t *optlen)
{
    switch (level) {
        case FI_OPT_ENDPOINT:
            switch (optname) {
                case FI_OPT_CM_DATA_SIZE:
                    if (*optlen < sizeof(size_t))
                        return -FI_ETOOSMALL;
                    *((size_t *)optval) = mverbs_msg_ep_cmdata_size(fid);
                    *optlen = sizeof(size_t);
                    return 0;
                default:
                    return -FI_ENOPROTOOPT;
            }
        default:
            return -FI_ENOPROTOOPT;
    }
    return 0;
}

static int mverbs_ep_setopt(fid_t fid, int level, int optname,
                            const void *optval, size_t optlen)
{
    if (level != FI_OPT_ENDPOINT)
        return -FI_ENOPROTOOPT;

    if (optname == FI_OPT_CUDA_API_PERMITTED) {
        if (!hmem_ops[FI_HMEM_CUDA].initialized) {
            FI_WARN(&mverbs_prov, FI_LOG_EP_CTRL,
                    "Cannot set CUDA API permitted when"
                    "CUDA library or CUDA device is not available\n");
            return -FI_EINVAL;
        }

        /* our HMEM support does not make calls to CUDA API,
         * therefore we can accept any option for FI_OPT_CUDA_API_PERMITTED.
         */
        return FI_SUCCESS;
    }

    return -FI_ENOPROTOOPT;
}

static struct fi_ops_ep mverbs_ep_base_ops = {
    .size = sizeof(struct fi_ops_ep),
    .cancel = fi_no_cancel,
    .getopt = mverbs_ep_getopt,
    .setopt = mverbs_ep_setopt,
    .tx_ctx = fi_no_tx_ctx,
    .rx_ctx = fi_no_rx_ctx,
    .rx_size_left = fi_no_rx_size_left,
    .tx_size_left = fi_no_tx_size_left,
};

static struct fi_ops_rma mverbs_dgram_rma_ops = {
    .size = sizeof(struct fi_ops_rma),
    .read = fi_no_rma_read,
    .readv = fi_no_rma_readv,
    .readmsg = fi_no_rma_readmsg,
    .write = fi_no_rma_write,
    .writev = fi_no_rma_writev,
    .writemsg = fi_no_rma_writemsg,
    .inject = fi_no_rma_inject,
    .writedata = fi_no_rma_writedata,
    .injectdata = fi_no_rma_injectdata,
};

static int mverbs_alloc_wrs(struct mverbs_ep *ep)
{
    ep->wrs = calloc(1, sizeof(*ep->wrs));
    if (!ep->wrs)
        return -FI_ENOMEM;

    ep->wrs->msg_wr.wr_id = MVERBS_NO_COMP_FLAG;
    ep->wrs->msg_wr.opcode = IBV_WR_SEND;
    ep->wrs->msg_wr.send_flags = IBV_SEND_INLINE;
    ep->wrs->msg_wr.sg_list = &ep->wrs->sge;
    ep->wrs->msg_wr.num_sge = 1;

    ep->wrs->rma_wr.wr_id = MVERBS_NO_COMP_FLAG;
    ep->wrs->rma_wr.opcode = IBV_WR_RDMA_WRITE;
    ep->wrs->rma_wr.send_flags = IBV_SEND_INLINE;
    ep->wrs->rma_wr.sg_list = &ep->wrs->sge;
    ep->wrs->rma_wr.num_sge = 1;

    return FI_SUCCESS;
}

static void mverbs_free_wrs(struct mverbs_ep *ep) { free(ep->wrs); }

static void mverbs_util_ep_progress_noop(struct util_ep *util_ep)
{
    /* This routine shouldn't be called */
    assert(0);
}

static struct mverbs_ep *mverbs_alloc_init_ep(struct fi_info *info,
                                              struct mverbs_domain *domain,
                                              void *context)
{
    struct mverbs_ep *ep;
    struct mverbs_xrc_ep *xrc_ep;
    int ret;

    if (mverbs_is_xrc_info(info)) {
        xrc_ep = calloc(1, sizeof(*xrc_ep));
        if (!xrc_ep)
            return NULL;
        xrc_ep->magic = MVERBS_XRC_EP_MAGIC;
        ep = &xrc_ep->base_ep;
    } else {
        ep = calloc(1, sizeof(*ep));
        if (!ep)
            return NULL;
    }

    // When we are enabling flow control, we artificially inject
    // a credit so that the credit messaging itself is not blocked
    // by a lack of credits.  To counter this, we will adjust the number
    // of credit we send the first time by initializing to -1.
    ep->rq_credits_avail = -1;

    if (domain->util_domain.threading != FI_THREAD_SAFE) {
        if (mverbs_alloc_wrs(ep))
            goto err1;
    }

    ret = ofi_endpoint_init(&domain->util_domain.domain_fid, &mverbs_util_prov,
                            info, &ep->util_ep, context,
                            mverbs_util_ep_progress_noop);
    if (ret) {
        VRB_WARN_ERR(FI_LOG_EP_CTRL, "ofi_endpoint_init", ret);
        goto err2;
    }

    slist_init(&ep->sq_list);
    slist_init(&ep->rq_list);
    ep->util_ep.ep_fid.msg = calloc(1, sizeof(*ep->util_ep.ep_fid.msg));
    if (!ep->util_ep.ep_fid.msg)
        goto err3;

    return ep;
err3:
    (void)ofi_endpoint_close(&ep->util_ep);
err2:
    mverbs_free_wrs(ep);
err1:
    free(ep);
    return NULL;
}

/* Generate flush completion entries for any queued send requests. */
static void mverbs_flush_sq(struct mverbs_ep *ep)
{
    struct mverbs_context *ctx;
    struct mverbs_cq *cq;
    struct slist_entry *entry;
    struct ibv_wc wc = {0};

    assert(ofi_genlock_held(mverbs_ep2_progress(ep)->active_lock));
    if (!ep->util_ep.tx_cq)
        return;

    cq = container_of(ep->util_ep.tx_cq, struct mverbs_cq, util_cq);
    wc.status = IBV_WC_WR_FLUSH_ERR;
    wc.vendor_err = FI_ECANCELED;

    while (!slist_empty(&ep->sq_list)) {
        entry = slist_remove_head(&ep->sq_list);
        ctx = container_of(entry, struct mverbs_context, entry);
        assert(ctx->op_queue == VRB_OP_SQ);

        wc.wr_id = (uintptr_t)ctx->user_ctx;
        wc.opcode = mverbs_wr2wc_opcode(ctx->sq_opcode);

        ctx->ep->sq_credits++;
        mverbs_free_ctx(mverbs_ep2_progress(ep), ctx);

        if (wc.wr_id != MVERBS_NO_COMP_FLAG)
            mverbs_report_wc(cq, &wc);
    }
}

static void mverbs_flush_rq(struct mverbs_ep *ep)
{
    struct mverbs_context *ctx;
    struct mverbs_cq *cq;
    struct slist_entry *entry;
    struct ibv_wc wc = {0};

    assert(ofi_genlock_held(mverbs_ep2_progress(ep)->active_lock));
    if (!ep->util_ep.rx_cq)
        return;

    cq = container_of(ep->util_ep.rx_cq, struct mverbs_cq, util_cq);
    wc.status = IBV_WC_WR_FLUSH_ERR;
    wc.vendor_err = FI_ECANCELED;

    while (!slist_empty(&ep->rq_list)) {
        entry = slist_remove_head(&ep->rq_list);
        ctx = container_of(entry, struct mverbs_context, entry);

        wc.wr_id = (uintptr_t)ctx->user_ctx;
        wc.opcode = IBV_WC_RECV;
        mverbs_free_ctx(mverbs_ep2_progress(ep), ctx);

        if (wc.wr_id != MVERBS_NO_COMP_FLAG)
            mverbs_report_wc(cq, &wc);
    }
}

static int mverbs_close_free_ep(struct mverbs_ep *ep)
{
    int ret;

    free(ep->util_ep.ep_fid.msg);
    ep->util_ep.ep_fid.msg = NULL;
    free(ep->cm_priv_data);

    ret = ofi_endpoint_close(&ep->util_ep);
    if (ret)
        return ret;

    mverbs_free_wrs(ep);
    free(ep->info_attr.src_addr);
    free(ep->info_attr.dest_addr);
    free(ep);

    return 0;
}

static void mverbs_ep_xrc_close(struct mverbs_ep *ep)
{
    struct mverbs_xrc_ep *xrc_ep =
        container_of(ep, struct mverbs_xrc_ep, base_ep);

    assert(ofi_mutex_held(&ep->eq->event_lock));
    if (xrc_ep->conn_setup)
        mverbs_free_xrc_conn_setup(xrc_ep, 0);

    if (xrc_ep->conn_map_node)
        mverbs_eq_remove_sidr_conn(xrc_ep);
    mverbs_ep_destroy_xrc_qp(xrc_ep);
    xrc_ep->magic = 0;
}

static int mverbs_ep_close(fid_t fid)
{
    int ret;
    struct mverbs_fabric *fab;
    struct mverbs_ep *ep =
        container_of(fid, struct mverbs_ep, util_ep.ep_fid.fid);

    switch (ep->util_ep.type) {
        case FI_EP_MSG:
            if (ep->eq) {
                ofi_mutex_lock(&ep->eq->event_lock);
                if (ep->eq->err.err && ep->eq->err.fid == fid) {
                    if (ep->eq->err.err_data) {
                        free(ep->eq->err.err_data);
                        ep->eq->err.err_data = NULL;
                        ep->eq->err.err_data_size = 0;
                    }
                    ep->eq->err.err = 0;
                    ep->eq->err.prov_errno = 0;
                }
                mverbs_eq_remove_events(ep->eq, fid);
            }

            if (mverbs_is_xrc_ep(ep))
                mverbs_ep_xrc_close(ep);
            else
                rdma_destroy_ep(ep->id);

            if (ep->eq)
                ofi_mutex_unlock(&ep->eq->event_lock);

            ofi_genlock_lock(&mverbs_ep2_progress(ep)->ep_lock);
            mverbs_cleanup_cq(ep);
            mverbs_flush_sq(ep);
            mverbs_flush_rq(ep);
            ofi_genlock_unlock(&mverbs_ep2_progress(ep)->ep_lock);
            break;
        case FI_EP_DGRAM:
            fab =
                container_of(&ep->util_ep.domain->fabric->fabric_fid,
                             struct mverbs_fabric, util_fabric.fabric_fid.fid);
            ofi_ns_del_local_name(&fab->name_server, &ep->service,
                                  &ep->ep_name);
            if (ep->ibv_qp) {
                ret = ibv_destroy_qp(ep->ibv_qp);
                if (ret) {
                    VRB_WARN_ERRNO(FI_LOG_EP_CTRL, "ibv_destroy_qp");
                    return -errno;
                }
            }

            ofi_genlock_lock(&mverbs_ep2_progress(ep)->ep_lock);
            mverbs_cleanup_cq(ep);
            mverbs_flush_sq(ep);
            mverbs_flush_rq(ep);
            ofi_genlock_unlock(&mverbs_ep2_progress(ep)->ep_lock);
            break;
        default:
            VRB_WARN(FI_LOG_DOMAIN, "Unknown EP type\n");
            assert(0);
            return -FI_EINVAL;
    }

    VRB_INFO(FI_LOG_DOMAIN, "EP %p is being closed\n", ep);

    ret = mverbs_close_free_ep(ep);
    if (ret) {
        VRB_WARN_ERR(FI_LOG_DOMAIN, "mverbs_close_free_ep", ret);
        return ret;
    }

    return 0;
}

static inline int mverbs_ep_xrc_set_tgt_chan(struct mverbs_ep *ep)
{
    struct mverbs_xrc_ep *xrc_ep =
        container_of(ep, struct mverbs_xrc_ep, base_ep);
    if (xrc_ep->tgt_id)
        return rdma_migrate_id(xrc_ep->tgt_id, ep->eq->channel);

    return FI_SUCCESS;
}

static int mverbs_ep_bind(struct fid *fid, struct fid *bfid, uint64_t flags)
{
    struct mverbs_ep *ep;
    struct mverbs_cq *cq =
        container_of(bfid, struct mverbs_cq, util_cq.cq_fid.fid);
    struct mverbs_dgram_av *av;
    int ret;

    ep = container_of(fid, struct mverbs_ep, util_ep.ep_fid.fid);
    ret = ofi_ep_bind_valid(&mverbs_prov, bfid, flags);
    if (ret)
        return ret;

    switch (bfid->fclass) {
        case FI_CLASS_CQ:
            ret = ofi_ep_bind_cq(&ep->util_ep, &cq->util_cq, flags);
            break;
        case FI_CLASS_EQ:
            if (ep->util_ep.type != FI_EP_MSG)
                return -FI_EINVAL;

            ep->eq = container_of(bfid, struct mverbs_eq, eq_fid.fid);

            /* Make sure EQ channel is not polled during migrate */
            ofi_mutex_lock(&ep->eq->event_lock);
            if (mverbs_is_xrc_ep(ep))
                ret = mverbs_ep_xrc_set_tgt_chan(ep);
            else
                ret = rdma_migrate_id(ep->id, ep->eq->channel);
            ofi_mutex_unlock(&ep->eq->event_lock);
            if (ret) {
                VRB_WARN_ERRNO(FI_LOG_EP_CTRL, "rdma_migrate_id");
                ret = -errno;
            }
            break;
        case FI_CLASS_SRX_CTX:
            if (ep->util_ep.type != FI_EP_MSG)
                return -FI_EINVAL;

            ep->srx = container_of(bfid, struct mverbs_srx, ep_fid.fid);
            break;
        case FI_CLASS_AV:
            if (ep->util_ep.type != FI_EP_DGRAM)
                return -FI_EINVAL;

            av = container_of(bfid, struct mverbs_dgram_av, util_av.av_fid.fid);
            ret = ofi_ep_bind_av(&ep->util_ep, &av->util_av);
            break;
        default:
            ret = -FI_EINVAL;
            break;
    }

    return ret;
}

static int mverbs_create_dgram_ep(struct mverbs_domain *domain,
                                  struct mverbs_ep *ep,
                                  struct ibv_qp_init_attr *init_attr)
{
    struct mverbs_fabric *fab;
    struct ibv_qp_attr attr = {
        .qp_state = IBV_QPS_INIT,
        .pkey_index = 0,
        .port_num = 1,
        .qkey = 0x11111111,
    };
    int ret = 0;
    union ibv_gid gid;
    uint16_t p_key;
    struct ibv_port_attr port_attr;

    init_attr->qp_type = IBV_QPT_UD;

    ep->ibv_qp = ibv_create_qp(domain->pd, init_attr);
    if (!ep->ibv_qp) {
        VRB_WARN_ERRNO(FI_LOG_EP_CTRL, "ibv_create_qp");
        return -errno;
    }

    ret = ibv_modify_qp(ep->ibv_qp, &attr,
                        IBV_QP_STATE | IBV_QP_PKEY_INDEX | IBV_QP_PORT |
                            IBV_QP_QKEY);
    if (ret) {
        VRB_WARN_ERRNO(FI_LOG_EP_CTRL, "ibv_modify_qp");
        return -errno;
    }

    memset(&attr, 0, sizeof(attr));
    attr.qp_state = IBV_QPS_RTR;
    ret = ibv_modify_qp(ep->ibv_qp, &attr, IBV_QP_STATE);
    if (ret) {
        VRB_WARN_ERRNO(FI_LOG_EP_CTRL, "ibv_modify_qp");
        return -errno;
    }

    if (ep->util_ep.tx_cq) {
        memset(&attr, 0, sizeof(attr));
        attr.qp_state = IBV_QPS_RTS;
        attr.sq_psn = 0xffffff;
        ret = ibv_modify_qp(ep->ibv_qp, &attr, IBV_QP_STATE | IBV_QP_SQ_PSN);
        if (ret) {
            VRB_WARN_ERRNO(FI_LOG_EP_CTRL, "ibv_modify_qp");
            return -errno;
        }
    }

    if (ibv_query_gid(domain->verbs, 1, mverbs_gl_data.gid_idx, &gid)) {
        VRB_WARN_ERRNO(FI_LOG_EP_CTRL, "ibv_query_gid");
        return -errno;
    }

    if (ibv_query_pkey(domain->verbs, 1, 0, &p_key)) {
        VRB_WARN(FI_LOG_EP_CTRL, "Unable to query P_Key, errno = %d", errno);
        return -errno;
    }

    if (ibv_query_port(domain->verbs, 1, &port_attr)) {
        VRB_WARN_ERRNO(FI_LOG_EP_CTRL, "ibv_query_port");
        return -errno;
    }

    ep->ep_name.lid = port_attr.lid;
    ep->ep_name.sl = port_attr.sm_sl;
    ep->ep_name.gid = gid;
    ep->ep_name.qpn = ep->ibv_qp->qp_num;
    ep->ep_name.pkey = p_key;

    fab = container_of(ep->util_ep.domain->fabric, struct mverbs_fabric,
                       util_fabric);

    ofi_ns_add_local_name(&fab->name_server, &ep->service, &ep->ep_name);

    return 0;
}

FI_MVERBS_XRC_ONLY
static int mverbs_process_xrc_preposted(struct mverbs_srx *srx)
{
    struct mverbs_xrc_srx_prepost *recv;
    struct slist_entry *entry;
    int ret;

    assert(ofi_mutex_held(&srx->xrc.prepost_lock));
    /* The pre-post SRQ function ops have been replaced so the
     * posting here results in adding the RX entries to the SRQ */
    while (!slist_empty(&srx->xrc.prepost_list)) {
        entry = slist_remove_head(&srx->xrc.prepost_list);
        recv =
            container_of(entry, struct mverbs_xrc_srx_prepost, prepost_entry);
        ret = fi_recv(&srx->ep_fid, recv->buf, recv->len, recv->desc,
                      recv->src_addr, recv->context);
        free(recv);
        if (ret) {
            VRB_WARN_ERR(FI_LOG_EP_DATA, "fi_recv", ret);
            return ret;
        }
    }
    return FI_SUCCESS;
}

static int mverbs_ep_enable_xrc(struct mverbs_ep *ep)
{
#if MVERBS_HAVE_XRC
    struct mverbs_xrc_ep *xrc_ep =
        container_of(ep, struct mverbs_xrc_ep, base_ep);
    struct mverbs_srx *srx = ep->srx;
    struct mverbs_domain *domain = container_of(
        ep->util_ep.rx_cq->domain, struct mverbs_domain, util_domain);
    struct mverbs_cq *cq =
        container_of(ep->util_ep.rx_cq, struct mverbs_cq, util_cq);
    struct ibv_srq_init_attr_ex attr;
    ssize_t ret;

    /* XRC EP additional initialization */
    dlist_init(&xrc_ep->ini_conn_entry);
    xrc_ep->conn_state = VRB_XRC_UNCONNECTED;

    ofi_mutex_lock(&srx->xrc.prepost_lock);
    if (srx->srq) {
        /*
         * Multiple endpoints bound to the same XRC SRX context have
         * the restriction that they must be bound to the same RX CQ
         */
        if (!srx->xrc.cq || srx->xrc.cq != cq) {
            ofi_mutex_unlock(&srx->xrc.prepost_lock);
            VRB_WARN(FI_LOG_EP_CTRL, "SRX_CTX/CQ mismatch\n");
            return -FI_EINVAL;
        }
        ibv_get_srq_num(srx->srq, &xrc_ep->srqn);
        ret = FI_SUCCESS;
        goto done;
    }

    memset(&attr, 0, sizeof(attr));
    attr.attr.max_wr = srx->xrc.max_recv_wr;
    attr.attr.max_sge = srx->xrc.max_sge;
    attr.comp_mask = IBV_SRQ_INIT_ATTR_TYPE | IBV_SRQ_INIT_ATTR_XRCD |
                     IBV_SRQ_INIT_ATTR_CQ | IBV_SRQ_INIT_ATTR_PD;
    attr.srq_type = IBV_SRQT_XRC;
    attr.xrcd = domain->xrc.xrcd;
    attr.cq = cq->cq;
    attr.pd = domain->pd;

    srx->srq = ibv_create_srq_ex(domain->verbs, &attr);
    if (!srx->srq) {
        VRB_WARN_ERRNO(FI_LOG_DOMAIN, "ibv_create_srq_ex");
        ret = -errno;
        goto done;
    }
    /* The RX CQ maintains a list of all the XRC SRQs that were created
     * using it as the CQ */
    ofi_genlock_lock(&mverbs_ep2_progress(ep)->ep_lock);
    dlist_insert_tail(&srx->xrc.srq_entry, &cq->xrc.srq_list);
    srx->xrc.cq = cq;
    ofi_genlock_unlock(&mverbs_ep2_progress(ep)->ep_lock);

    ibv_get_srq_num(srx->srq, &xrc_ep->srqn);

    /* Swap functions since locking is no longer required */
    srx->ep_fid.msg = &mverbs_srq_msg_ops;
    ret = mverbs_process_xrc_preposted(srx);
done:
    ofi_mutex_unlock(&srx->xrc.prepost_lock);

    return ret;
#else  /* MVERBS_HAVE_XRC */
    return -FI_ENOSYS;
#endif /* !MVERBS_HAVE_XRC */
}

void mverbs_msg_ep_get_qp_attr(struct mverbs_ep *ep,
                               struct ibv_qp_init_attr *attr)
{
    attr->qp_context = ep;

    if (ep->util_ep.tx_cq) {
        struct mverbs_cq *cq =
            container_of(ep->util_ep.tx_cq, struct mverbs_cq, util_cq);

        attr->cap.max_send_wr = ep->info_attr.tx_size;
        attr->cap.max_send_sge = ep->info_attr.tx_iov_limit;
        attr->send_cq = cq->cq;
    } else {
        struct mverbs_cq *cq =
            container_of(ep->util_ep.rx_cq, struct mverbs_cq, util_cq);

        attr->send_cq = cq->cq;
    }

    if (ep->util_ep.rx_cq) {
        struct mverbs_cq *cq =
            container_of(ep->util_ep.rx_cq, struct mverbs_cq, util_cq);

        attr->cap.max_recv_wr = ep->info_attr.rx_size;
        attr->cap.max_recv_sge = ep->info_attr.rx_iov_limit;
        attr->recv_cq = cq->cq;
    } else {
        struct mverbs_cq *cq =
            container_of(ep->util_ep.tx_cq, struct mverbs_cq, util_cq);

        attr->recv_cq = cq->cq;
    }
    attr->cap.max_inline_data = ep->info_attr.inject_size;
    attr->qp_type = IBV_QPT_RC;
    attr->sq_sig_all = 1;

    if (ep->srx) {
        attr->srq = ep->srx->srq;
        /* Recieve posts are done to SRQ not QP RQ */
        attr->cap.max_recv_wr = 0;
    }
}

static int mverbs_ep_enable(struct fid_ep *ep_fid)
{
    struct ibv_qp_init_attr attr = {0};
    struct mverbs_ep *ep =
        container_of(ep_fid, struct mverbs_ep, util_ep.ep_fid);
    struct mverbs_domain *domain = mverbs_ep2_domain(ep);
    int ret;

    if (!ep->eq && (ep->util_ep.type == FI_EP_MSG)) {
        VRB_WARN(FI_LOG_EP_CTRL, "Endpoint is not bound to an event queue\n");
        return -FI_ENOEQ;
    }

    if (!ep->util_ep.tx_cq && !ep->util_ep.rx_cq) {
        VRB_WARN(FI_LOG_EP_CTRL, "Endpoint is not bound to "
                                 "a send or receive completion queue\n");
        return -FI_ENOCQ;
    }

    if (!ep->util_ep.tx_cq && (ofi_needs_tx(ep->util_ep.caps))) {
        VRB_WARN(FI_LOG_EP_CTRL, "Endpoint is not bound to "
                                 "a send completion queue when it has transmit "
                                 "capabilities enabled (FI_SEND | FI_RMA).\n");
        return -FI_ENOCQ;
    }

    if (!ep->util_ep.rx_cq && ofi_needs_rx(ep->util_ep.caps)) {
        VRB_WARN(FI_LOG_EP_CTRL,
                 "Endpoint is not bound to "
                 "a receive completion queue when it has receive "
                 "capabilities enabled. (FI_RECV)\n");
        return -FI_ENOCQ;
    }
    mverbs_msg_ep_get_qp_attr(ep, &attr);

    switch (ep->util_ep.type) {
        case FI_EP_MSG:
            if (ep->srx) {
                /* Override receive function pointers to prevent the user from
                 * posting Receive WRs to a QP where a SRQ is attached to it */
                if (domain->ext_flags & VRB_USE_XRC) {
                    *ep->util_ep.ep_fid.msg = mverbs_msg_srq_xrc_ep_msg_ops;
                    return mverbs_ep_enable_xrc(ep);
                } else {
                    ep->util_ep.ep_fid.msg->recv = fi_no_msg_recv;
                    ep->util_ep.ep_fid.msg->recvv = fi_no_msg_recvv;
                    ep->util_ep.ep_fid.msg->recvmsg = fi_no_msg_recvmsg;
                }
            } else if (domain->ext_flags & VRB_USE_XRC) {
                VRB_WARN(FI_LOG_EP_CTRL, "XRC EP_MSG not bound "
                                         "to srx_context\n");
                return -FI_EINVAL;
            }

            ret = rdma_create_qp(ep->id, domain->pd, &attr);
            if (ret) {
                VRB_WARN_ERRNO(FI_LOG_EP_CTRL, "rdma_create_qp");
                return -errno;
            }

            /* Allow shared XRC INI QP not controlled by RDMA CM
             * to share same post functions as RC QP. */
            ep->ibv_qp = ep->id->qp;
            break;
        case FI_EP_DGRAM:
            assert(domain);
            attr.sq_sig_all = 1;
            ret = mverbs_create_dgram_ep(domain, ep, &attr);
            if (ret) {
                VRB_WARN_ERR(FI_LOG_EP_CTRL, "mverbs_create_dgram_ep", ret);
                return ret;
            }
            break;
        default:
            VRB_WARN(FI_LOG_EP_CTRL, "Unknown EP type\n");
            assert(0);
            return -FI_EINVAL;
    }
    return 0;
}

static int mverbs_ep_control(struct fid *fid, int command, void *arg)
{
    struct fid_ep *ep;

    switch (fid->fclass) {
        case FI_CLASS_EP:
            ep = container_of(fid, struct fid_ep, fid);
            switch (command) {
                case FI_ENABLE:
                    return mverbs_ep_enable(ep);
                default:
                    return -FI_ENOSYS;
            }
            break;
        default:
            return -FI_ENOSYS;
    }
}

static int mverbs_dgram_ep_setname(fid_t ep_fid, void *addr, size_t addrlen)
{
    struct mverbs_ep *ep;
    void *save_addr;
    int ret = FI_SUCCESS;

    ep = container_of(ep_fid, struct mverbs_ep, util_ep.ep_fid.fid);
    if (addrlen < ep->info_attr.src_addrlen) {
        VRB_INFO(FI_LOG_EP_CTRL, "addrlen expected: %zu, got: %zu\n",
                 ep->info_attr.src_addrlen, addrlen);
        return -FI_ETOOSMALL;
    }
    /*
     * save previous address to be able make
     * a roll back on the previous one
     */
    save_addr = ep->info_attr.src_addr;

    ep->info_attr.src_addr = calloc(1, ep->info_attr.src_addrlen);
    if (!ep->info_attr.src_addr) {
        ep->info_attr.src_addr = save_addr;
        ret = -FI_ENOMEM;
        goto err;
    }

    memcpy(ep->info_attr.src_addr, addr, ep->info_attr.src_addrlen);
    memcpy(&ep->ep_name, addr, ep->info_attr.src_addrlen);

err:
    ep->info_attr.src_addr = save_addr;
    return ret;
}

static int mverbs_dgram_ep_getname(fid_t ep_fid, void *addr, size_t *addrlen)
{
    struct mverbs_ep *ep;

    ep = container_of(ep_fid, struct mverbs_ep, util_ep.ep_fid.fid);
    if (*addrlen < sizeof(ep->ep_name)) {
        *addrlen = sizeof(ep->ep_name);
        VRB_INFO(FI_LOG_EP_CTRL, "addrlen expected: %zu, got: %zu\n",
                 sizeof(ep->ep_name), *addrlen);
        return -FI_ETOOSMALL;
    }

    memset(addr, 0, *addrlen);
    memcpy(addr, &ep->ep_name, sizeof(ep->ep_name));
    *addrlen = sizeof(ep->ep_name);

    return FI_SUCCESS;
}

static struct fi_ops mverbs_ep_ops = {
    .size = sizeof(struct fi_ops),
    .close = mverbs_ep_close,
    .bind = mverbs_ep_bind,
    .control = mverbs_ep_control,
    .ops_open = fi_no_ops_open,
};

static struct fi_ops_cm mverbs_dgram_cm_ops = {
    .size = sizeof(mverbs_dgram_cm_ops),
    .setname = mverbs_dgram_ep_setname,
    .getname = mverbs_dgram_ep_getname,
    .getpeer = fi_no_getpeer,
    .connect = fi_no_connect,
    .listen = fi_no_listen,
    .accept = fi_no_accept,
    .reject = fi_no_reject,
    .shutdown = fi_no_shutdown,
    .join = fi_no_join,
};

static int mverbs_ep_save_info_attr(struct mverbs_ep *ep, struct fi_info *info)
{
    ep->info_attr.protocol = info->ep_attr->protocol;
    ep->info_attr.inject_size = info->tx_attr->inject_size;
    ep->info_attr.tx_size = info->tx_attr->size;
    ep->info_attr.tx_iov_limit = info->tx_attr->iov_limit;
    ep->info_attr.rx_size = info->rx_attr->size;
    ep->info_attr.rx_iov_limit = info->rx_attr->iov_limit;
    ep->info_attr.addr_format = info->addr_format;
    ep->info_attr.handle = info->handle;

    if (info->src_addr) {
        ep->info_attr.src_addr = mem_dup(info->src_addr, info->src_addrlen);
        if (ep->info_attr.src_addr == NULL) {
            VRB_WARN(FI_LOG_EP_CTRL, "Memory error save src addr\n");
            return -FI_ENOMEM;
        }
        ep->info_attr.src_addrlen = info->src_addrlen;
    }
    if (info->dest_addr) {
        ep->info_attr.dest_addr = mem_dup(info->dest_addr, info->dest_addrlen);
        if (ep->info_attr.dest_addr == NULL) {
            VRB_WARN(FI_LOG_EP_CTRL, "Memory error save dest addr\n");
            free(ep->info_attr.src_addr);
            ep->info_attr.src_addr = NULL;
            return -FI_ENOMEM;
        }
        ep->info_attr.dest_addrlen = info->dest_addrlen;
    }
    return FI_SUCCESS;
}

int mverbs_open_ep(struct fid_domain *domain, struct fi_info *info,
                   struct fid_ep **ep_fid, void *context)
{
    struct mverbs_domain *dom;
    struct mverbs_ep *ep;
    struct mverbs_connreq *connreq;
    struct mverbs_pep *pep;
    struct fi_info *fi;
    int ret;

    if (!info->ep_attr || !info->rx_attr || !info->tx_attr)
        return -FI_EINVAL;

    if (info->src_addr)
        ofi_straddr_dbg(&mverbs_prov, FI_LOG_FABRIC, "open_ep src addr",
                        info->src_addr);
    if (info->dest_addr)
        ofi_straddr_dbg(&mverbs_prov, FI_LOG_FABRIC, "open_ep dest addr",
                        info->dest_addr);

    dom = container_of(domain, struct mverbs_domain, util_domain.domain_fid);
    /* strncmp is used here, because the function is used
     * to allocate DGRAM (has prefix <dev_name>-dgram) and MSG EPs */
    if (strncmp(dom->verbs->device->name, info->domain_attr->name,
                strlen(dom->verbs->device->name))) {
        VRB_WARN(FI_LOG_DOMAIN, "Invalid info->domain_attr->name: %s and %s\n",
                 dom->verbs->device->name, info->domain_attr->name);
        return -FI_EINVAL;
    }

    fi = dom->info;

    ret = mverbs_check_ep_attr(info, fi);
    if (ret)
        return ret;

    ret =
        ofi_check_tx_attr(&mverbs_prov, fi->tx_attr, info->tx_attr, info->mode);
    if (ret)
        return ret;

    ret = mverbs_check_rx_attr(info->rx_attr, info, fi);
    if (ret)
        return ret;

    ep = mverbs_alloc_init_ep(info, dom, context);
    if (!ep) {
        VRB_WARN_ERR(FI_LOG_EP_CTRL, "mverbs_alloc_init_ep", -ENOMEM);
        return -FI_ENOMEM;
    }

    ep->peer_rq_credits = UINT64_MAX;
    ep->threshold = INT64_MAX; /* disables RQ flow control */
    ep->hmem_enabled = !!(ep->util_ep.caps & FI_HMEM);

    ret = mverbs_ep_save_info_attr(ep, info);
    if (ret)
        goto close_ep;

    switch (info->ep_attr->type) {
        case FI_EP_MSG:
            if (dom->ext_flags & VRB_USE_XRC) {
                if (dom->util_domain.threading == FI_THREAD_SAFE) {
                    *ep->util_ep.ep_fid.msg = mverbs_msg_xrc_ep_msg_ops_ts;
                    ep->util_ep.ep_fid.rma = &mverbs_msg_xrc_ep_rma_ops_ts;
                } else {
                    *ep->util_ep.ep_fid.msg = mverbs_msg_xrc_ep_msg_ops;
                    ep->util_ep.ep_fid.rma = &mverbs_msg_xrc_ep_rma_ops;
                }
                ep->util_ep.ep_fid.cm = &mverbs_msg_xrc_ep_cm_ops;
                ep->util_ep.ep_fid.atomic = &mverbs_msg_xrc_ep_atomic_ops;
            } else {
                if (dom->util_domain.threading == FI_THREAD_SAFE) {
                    *ep->util_ep.ep_fid.msg = mverbs_msg_ep_msg_ops_ts;
                    ep->util_ep.ep_fid.rma = &mverbs_msg_ep_rma_ops_ts;
                } else {
                    *ep->util_ep.ep_fid.msg = mverbs_msg_ep_msg_ops;
                    ep->util_ep.ep_fid.rma = &mverbs_msg_ep_rma_ops;
                }
                ep->util_ep.ep_fid.cm = &mverbs_msg_ep_cm_ops;
                ep->util_ep.ep_fid.atomic = &mverbs_msg_ep_atomic_ops;
            }

            if (!info->handle) {
                /* Only RC, XRC active RDMA CM ID is created at connect */
                if (!(dom->ext_flags & VRB_USE_XRC)) {
                    ret = mverbs_create_ep(
                        ep, mverbs_get_port_space(info->addr_format), &ep->id);
                    if (ret)
                        goto close_ep;
                    ep->id->context = &ep->util_ep.ep_fid.fid;
                }
            } else if (info->handle->fclass == FI_CLASS_CONNREQ) {
                connreq =
                    container_of(info->handle, struct mverbs_connreq, handle);
                if (dom->ext_flags & VRB_USE_XRC) {
                    assert(connreq->is_xrc);

                    if (!connreq->xrc.is_reciprocal) {
                        ret = mverbs_process_xrc_connreq(ep, connreq);
                        if (ret)
                            goto close_ep;
                    }
                } else {
                    /* ep now owns this rdma cm id, prevent trying to access
                     * it outside of ep operations to avoid possible use-after-
                     * free bugs in case the ep is closed
                     */
                    ofi_genlock_lock(&mverbs_ep2_progress(ep)->ep_lock);
                    ep->state = VRB_REQ_RCVD;
                    ep->id = connreq->id;
                    connreq->id = NULL;
                    ep->ibv_qp = ep->id->qp;
                    ep->id->context = &ep->util_ep.ep_fid.fid;
                    ofi_genlock_unlock(&mverbs_ep2_progress(ep)->ep_lock);
                }
            } else if (info->handle->fclass == FI_CLASS_PEP) {
                pep =
                    container_of(info->handle, struct mverbs_pep, pep_fid.fid);
                ep->id = pep->id;
                ep->ibv_qp = ep->id->qp;
                pep->id = NULL;

                if (rdma_resolve_addr(ep->id, info->src_addr, info->dest_addr,
                                      MVERBS_RESOLVE_TIMEOUT)) {
                    ret = -errno;
                    VRB_WARN_ERRNO(FI_LOG_EP_CTRL, "rdma_resolve_addr");
                    /* rdma_destroy_ep will close the id->qp */
                    ep->ibv_qp = NULL;
                    rdma_destroy_ep(ep->id);
                    goto close_ep;
                }
                ep->id->context = &ep->util_ep.ep_fid.fid;
            } else {
                ret = -FI_ENOSYS;
                goto close_ep;
            }
            break;
        case FI_EP_DGRAM:
            ep->service =
                (info->src_addr) ?
                    (((struct ofi_ib_ud_ep_name *)info->src_addr)->service) :
                    (((getpid() & 0x7FFF) << 16) + ((uintptr_t)ep & 0xFFFF));

            if (dom->util_domain.threading == FI_THREAD_SAFE) {
                *ep->util_ep.ep_fid.msg = mverbs_dgram_msg_ops_ts;
            } else {
                *ep->util_ep.ep_fid.msg = mverbs_dgram_msg_ops;
            }
            ep->util_ep.ep_fid.rma = &mverbs_dgram_rma_ops;
            ep->util_ep.ep_fid.cm = &mverbs_dgram_cm_ops;
            break;
        default:
            VRB_WARN(FI_LOG_EP_CTRL, "Unknown EP type\n");
            ret = -FI_EINVAL;
            assert(0);
            goto close_ep;
    }

    if (info->ep_attr->tx_ctx_cnt == 0 || info->ep_attr->tx_ctx_cnt == 1)
        ep->sq_credits = info->tx_attr->size;

    *ep_fid = &ep->util_ep.ep_fid;
    ep->util_ep.ep_fid.fid.ops = &mverbs_ep_ops;
    ep->util_ep.ep_fid.ops = &mverbs_ep_base_ops;

    return FI_SUCCESS;

close_ep:
    mverbs_close_free_ep(ep);
    return ret;
}

static int mverbs_pep_bind(fid_t fid, struct fid *bfid, uint64_t flags)
{
    struct mverbs_pep *pep;
    int ret;

    pep = container_of(fid, struct mverbs_pep, pep_fid.fid);
    if (bfid->fclass != FI_CLASS_EQ)
        return -FI_EINVAL;

    pep->eq = container_of(bfid, struct mverbs_eq, eq_fid.fid);
    /*
     * This is a restrictive solution that enables an XRC EP to
     * inform it's peer the port that should be used in making the
     * reciprocal connection request. While it meets RXM requirements
     * it limits an EQ to a single passive endpoint. TODO: implement
     * a more general solution.
     */
    if (mverbs_is_xrc_info(pep->info)) {
        if (pep->eq->xrc.pep_port) {
            VRB_WARN(FI_LOG_EP_CTRL, "XRC limits EQ binding to a single PEP\n");
            return -FI_EINVAL;
        }
        pep->eq->xrc.pep_port = ntohs(rdma_get_src_port(pep->id));
    }

    ret = rdma_migrate_id(pep->id, pep->eq->channel);
    if (ret) {
        VRB_WARN_ERRNO(FI_LOG_EP_CTRL, "rdma_migrate_id");
        return -errno;
    }

    if (mverbs_is_xrc_info(pep->info)) {
        ret = rdma_migrate_id(pep->xrc_ps_udp_id, pep->eq->channel);
        if (ret)
            return -errno;
    }
    return FI_SUCCESS;
}

static int mverbs_pep_control(struct fid *fid, int command, void *arg)
{
    struct mverbs_pep *pep;
    int ret = 0;

    switch (fid->fclass) {
        case FI_CLASS_PEP:
            pep = container_of(fid, struct mverbs_pep, pep_fid.fid);
            switch (command) {
                case FI_BACKLOG:
                    if (!arg)
                        return -FI_EINVAL;
                    pep->backlog = *(int *)arg;
                    break;
                default:
                    ret = -FI_ENOSYS;
                    break;
            }
            break;
        default:
            ret = -FI_ENOSYS;
            break;
    }

    return ret;
}

static int mverbs_pep_close(fid_t fid)
{
    struct mverbs_pep *pep;

    pep = container_of(fid, struct mverbs_pep, pep_fid.fid);
    if (pep->id)
        rdma_destroy_ep(pep->id);
    if (pep->xrc_ps_udp_id)
        rdma_destroy_ep(pep->xrc_ps_udp_id);

    fi_freeinfo(pep->info);
    free(pep);
    return 0;
}

static struct fi_ops mverbs_pep_fi_ops = {
    .size = sizeof(struct fi_ops),
    .close = mverbs_pep_close,
    .bind = mverbs_pep_bind,
    .control = mverbs_pep_control,
    .ops_open = fi_no_ops_open,
};

static struct fi_ops_ep mverbs_pep_ops = {
    .size = sizeof(struct fi_ops_ep),
    .getopt = mverbs_ep_getopt,
    .setopt = fi_no_setopt,
    .tx_ctx = fi_no_tx_ctx,
    .rx_ctx = fi_no_rx_ctx,
    .rx_size_left = fi_no_rx_size_left,
    .tx_size_left = fi_no_tx_size_left,
};

int mverbs_passive_ep(struct fid_fabric *fabric, struct fi_info *info,
                      struct fid_pep **pep, void *context)
{
    struct mverbs_pep *_pep;
    int ret;

    _pep = calloc(1, sizeof *_pep);
    if (!_pep)
        return -FI_ENOMEM;

    if (!(_pep->info = fi_dupinfo(info))) {
        ret = -FI_ENOMEM;
        goto err1;
    }

    if (_pep->info->dest_addr || _pep->info->dest_addrlen) {
        free(_pep->info->dest_addr);
        _pep->info->dest_addr = NULL;
        _pep->info->dest_addrlen = 0;
    }

    ret = rdma_create_id(NULL, &_pep->id, &_pep->pep_fid.fid,
                         mverbs_get_port_space(_pep->info->addr_format));
    if (ret) {
        VRB_WARN_ERRNO(FI_LOG_EP_CTRL, "rdma_create_id");
        goto err2;
    }

    if (info->src_addr) {
        ret = rdma_bind_addr(_pep->id, (struct sockaddr *)info->src_addr);
        if (ret) {
            VRB_WARN_ERRNO(FI_LOG_EP_CTRL, "rdma_bind_addr");
            ret = -errno;
            goto err3;
        }
        _pep->bound = 1;
    }

    /* XRC listens on both RDMA_PS_TCP and RDMA_PS_UDP */
    if (mverbs_is_xrc_info(info)) {
        ret = rdma_create_id(NULL, &_pep->xrc_ps_udp_id, &_pep->pep_fid.fid,
                             RDMA_PS_UDP);
        if (ret) {
            VRB_WARN_ERRNO(FI_LOG_EP_CTRL, "rdma_create_id");
            goto err3;
        }
        /* Currently both listens must be bound to same port number */
        ofi_addr_set_port(_pep->info->src_addr,
                          ntohs(rdma_get_src_port(_pep->id)));
        ret = rdma_bind_addr(_pep->xrc_ps_udp_id,
                             (struct sockaddr *)_pep->info->src_addr);
        if (ret) {
            VRB_WARN_ERRNO(FI_LOG_EP_CTRL, "rdma_bind_addr");
            goto err4;
        }
    }

    _pep->pep_fid.fid.fclass = FI_CLASS_PEP;
    _pep->pep_fid.fid.context = context;
    _pep->pep_fid.fid.ops = &mverbs_pep_fi_ops;
    _pep->pep_fid.ops = &mverbs_pep_ops;
    _pep->pep_fid.cm = mverbs_pep_ops_cm(_pep);

    _pep->src_addrlen = info->src_addrlen;

    *pep = &_pep->pep_fid;
    return 0;

err4:
    /* Only possible for XRC code path */
    rdma_destroy_id(_pep->xrc_ps_udp_id);
err3:
    rdma_destroy_id(_pep->id);
err2:
    fi_freeinfo(_pep->info);
err1:
    free(_pep);
    return ret;
}

static struct fi_ops_ep mverbs_srx_base_ops = {
    .size = sizeof(struct fi_ops_ep),
    .cancel = fi_no_cancel,
    .getopt = fi_no_getopt,
    .setopt = fi_no_setopt,
    .tx_ctx = fi_no_tx_ctx,
    .rx_ctx = fi_no_rx_ctx,
    .rx_size_left = fi_no_rx_size_left,
    .tx_size_left = fi_no_tx_size_left,
};

static struct fi_ops_cm mverbs_srx_cm_ops = {
    .size = sizeof(struct fi_ops_cm),
    .setname = fi_no_setname,
    .getname = fi_no_getname,
    .getpeer = fi_no_getpeer,
    .connect = fi_no_connect,
    .listen = fi_no_listen,
    .accept = fi_no_accept,
    .reject = fi_no_reject,
    .shutdown = fi_no_shutdown,
    .join = fi_no_join,
};

static struct fi_ops_rma mverbs_srx_rma_ops = {
    .size = sizeof(struct fi_ops_rma),
    .read = fi_no_rma_read,
    .readv = fi_no_rma_readv,
    .readmsg = fi_no_rma_readmsg,
    .write = fi_no_rma_write,
    .writev = fi_no_rma_writev,
    .writemsg = fi_no_rma_writemsg,
    .inject = fi_no_rma_inject,
    .writedata = fi_no_rma_writedata,
    .injectdata = fi_no_rma_injectdata,
};

static struct fi_ops_atomic mverbs_srx_atomic_ops = {
    .size = sizeof(struct fi_ops_atomic),
    .write = fi_no_atomic_write,
    .writev = fi_no_atomic_writev,
    .writemsg = fi_no_atomic_writemsg,
    .inject = fi_no_atomic_inject,
    .readwrite = fi_no_atomic_readwrite,
    .readwritev = fi_no_atomic_readwritev,
    .readwritemsg = fi_no_atomic_readwritemsg,
    .compwrite = fi_no_atomic_compwrite,
    .compwritev = fi_no_atomic_compwritev,
    .compwritemsg = fi_no_atomic_compwritemsg,
    .writevalid = fi_no_atomic_writevalid,
    .readwritevalid = fi_no_atomic_readwritevalid,
    .compwritevalid = fi_no_atomic_compwritevalid,
};

ssize_t mverbs_post_srq(struct mverbs_srx *srx, struct ibv_recv_wr *wr)
{
    struct mverbs_context *ctx;
    struct ibv_recv_wr *bad_wr;
    int ret;

    ofi_genlock_lock(mverbs_srx2_progress(srx)->active_lock);
    ctx = mverbs_alloc_ctx(mverbs_srx2_progress(srx));
    if (!ctx) {
        ret = -FI_EAGAIN;
        goto unlock;
    }

    ctx->srx = srx;
    ctx->user_ctx = (void *)(uintptr_t)wr->wr_id;
    ctx->op_queue = VRB_OP_SRQ;
    wr->wr_id = (uintptr_t)ctx;

    ret = ibv_post_srq_recv(srx->srq, wr, &bad_wr);
    wr->wr_id = (uintptr_t)ctx->user_ctx;

    if (ret) {
        mverbs_free_ctx(mverbs_srx2_progress(srx), ctx);
        ret = FI_EAGAIN;
    }

unlock:
    ofi_genlock_unlock(mverbs_srx2_progress(srx)->active_lock);
    return ret;
}

static inline ssize_t mverbs_srx_recvmsg(struct fid_ep *ep_fid,
                                         const struct fi_msg *msg,
                                         uint64_t flags)
{
    struct mverbs_srx *srx = container_of(ep_fid, struct mverbs_srx, ep_fid);
    struct ibv_recv_wr wr = {
        .wr_id = (uintptr_t)msg->context,
        .num_sge = msg->iov_count,
        .next = NULL,
    };

    mverbs_iov_dupa(wr.sg_list, msg->msg_iov, msg->desc, msg->iov_count);
    return mverbs_post_srq(srx, &wr);
}

static ssize_t mverbs_srx_recv(struct fid_ep *ep_fid, void *buf, size_t len,
                               void *desc, fi_addr_t src_addr, void *context)
{
    struct mverbs_srx *srx = container_of(ep_fid, struct mverbs_srx, ep_fid);
    struct ibv_sge sge = mverbs_init_sge(buf, len, desc);
    struct ibv_recv_wr wr = {
        .wr_id = (uintptr_t)context,
        .num_sge = 1,
        .sg_list = &sge,
        .next = NULL,
    };

    return mverbs_post_srq(srx, &wr);
}

static ssize_t mverbs_srx_recvv(struct fid_ep *ep_fid, const struct iovec *iov,
                                void **desc, size_t count, fi_addr_t src_addr,
                                void *context)
{
    struct fi_msg msg = {
        .msg_iov = iov,
        .desc = desc,
        .iov_count = count,
        .addr = src_addr,
        .context = context,
    };

    return mverbs_srx_recvmsg(ep_fid, &msg, 0);
}

static struct fi_ops_msg mverbs_srq_msg_ops = {
    .size = sizeof(struct fi_ops_msg),
    .recv = mverbs_srx_recv,
    .recvv = mverbs_srx_recvv,
    .recvmsg = mverbs_srx_recvmsg,
    .send = fi_no_msg_send,
    .sendv = fi_no_msg_sendv,
    .sendmsg = fi_no_msg_sendmsg,
    .inject = fi_no_msg_inject,
    .senddata = fi_no_msg_senddata,
    .injectdata = fi_no_msg_injectdata,
};

/*
 * XRC SRQ semantics differ from basic SRQ semantics in that the SRQ not the
 * QP selects which CQ will be used for receive completions. An artifact of
 * this is that the XRC SRQ can not be created until a CQ is bound to the
 * endpoint. This routine will be swapped out when the first endpoint bound
 * to the shared receive context is enabled.
 */
static ssize_t mverbs_xrc_srx_prepost_recv(struct fid_ep *ep_fid, void *buf,
                                           size_t len, void *desc,
                                           fi_addr_t src_addr, void *context)
{
    struct mverbs_srx *srx = container_of(ep_fid, struct mverbs_srx, ep_fid);
    struct mverbs_xrc_srx_prepost *recv;
    ssize_t ret;

    ofi_mutex_lock(&srx->xrc.prepost_lock);

    /* Handle race that can occur when SRQ is created and pre-post
     * receive message function is swapped out. */
    if (srx->srq) {
        ofi_mutex_unlock(&srx->xrc.prepost_lock);
        return mverbs_convert_ret(
            fi_recv(ep_fid, buf, len, desc, src_addr, context));
    }

    /* The only software error that can occur is overflow */
    if (OFI_UNLIKELY(srx->xrc.prepost_count >= srx->xrc.max_recv_wr)) {
        ret = -FI_EAVAIL;
        goto done;
    }

    recv = calloc(1, sizeof(*recv));
    if (OFI_UNLIKELY(!recv)) {
        ret = -FI_EAGAIN;
        goto done;
    }

    recv->buf = buf;
    recv->desc = desc;
    recv->src_addr = src_addr;
    recv->len = len;
    recv->context = context;
    srx->xrc.prepost_count++;
    slist_insert_tail(&recv->prepost_entry, &srx->xrc.prepost_list);
    ret = FI_SUCCESS;
done:
    ofi_mutex_unlock(&srx->xrc.prepost_lock);
    return ret;
}

static struct fi_ops_msg mverbs_xrc_srq_msg_ops = {
    .size = sizeof(struct fi_ops_msg),
    .recv = mverbs_xrc_srx_prepost_recv,
    .recvv = fi_no_msg_recvv,     /* Not used by RXM */
    .recvmsg = fi_no_msg_recvmsg, /* Not used by RXM */
    .send = fi_no_msg_send,
    .sendv = fi_no_msg_sendv,
    .sendmsg = fi_no_msg_sendmsg,
    .inject = fi_no_msg_inject,
    .senddata = fi_no_msg_senddata,
    .injectdata = fi_no_msg_injectdata,
};

static void mverbs_cleanup_prepost_bufs(struct mverbs_srx *srx)
{
    struct mverbs_xrc_srx_prepost *recv;
    struct slist_entry *entry;

    while (!slist_empty(&srx->xrc.prepost_list)) {
        entry = slist_remove_head(&srx->xrc.prepost_list);
        recv =
            container_of(entry, struct mverbs_xrc_srx_prepost, prepost_entry);
        free(recv);
    }
}

int mverbs_xrc_close_srq(struct mverbs_srx *srx)
{
    int ret;

    assert(ofi_genlock_held(mverbs_srx2_progress(srx)->active_lock));
    assert(srx->domain->ext_flags & VRB_USE_XRC);
    if (!srx->xrc.cq || !srx->srq)
        return FI_SUCCESS;

    ret = ibv_destroy_srq(srx->srq);
    if (ret) {
        VRB_WARN_ERRNO(FI_LOG_EP_CTRL, "ibv_destroy_srq");
        return -ret;
    }
    srx->srq = NULL;
    srx->xrc.cq = NULL;
    dlist_remove(&srx->xrc.srq_entry);
    mverbs_cleanup_prepost_bufs(srx);

    return FI_SUCCESS;
}

static int mverbs_srx_close(fid_t fid)
{
    struct mverbs_srx *srx = container_of(fid, struct mverbs_srx, ep_fid.fid);
    struct mverbs_cq *cq = srx->xrc.cq;
    int ret;

    if (srx->domain->ext_flags & VRB_USE_XRC) {
        if (cq) {
            ofi_genlock_lock(mverbs_srx2_progress(srx)->active_lock);
            ret = mverbs_xrc_close_srq(srx);
            ofi_genlock_unlock(mverbs_srx2_progress(srx)->active_lock);
            if (ret)
                goto err;
        }
        ofi_mutex_destroy(&srx->xrc.prepost_lock);
    } else {
        ret = ibv_destroy_srq(srx->srq);
        if (ret)
            goto err;
    }

    free(srx);
    return FI_SUCCESS;

err:
    VRB_WARN_ERRNO(FI_LOG_EP_CTRL, "ibv_destroy_srq");
    return ret;
}

static struct fi_ops mverbs_srx_ops = {
    .size = sizeof(struct fi_ops),
    .close = mverbs_srx_close,
    .bind = fi_no_bind,
    .control = fi_no_control,
    .ops_open = fi_no_ops_open,
};

int mverbs_srq_context(struct fid_domain *domain, struct fi_rx_attr *attr,
                       struct fid_ep **srx_fid, void *context)
{
    struct ibv_srq_init_attr srq_init_attr = {0};
    struct mverbs_domain *dom;
    struct mverbs_srx *srx;
    int ret;

    if (!domain)
        return -FI_EINVAL;

    srx = calloc(1, sizeof(*srx));
    if (!srx)
        return -FI_ENOMEM;

    dom = container_of(domain, struct mverbs_domain, util_domain.domain_fid);

    srx->ep_fid.fid.fclass = FI_CLASS_SRX_CTX;
    srx->ep_fid.fid.context = context;
    srx->ep_fid.fid.ops = &mverbs_srx_ops;
    srx->ep_fid.ops = &mverbs_srx_base_ops;
    srx->ep_fid.cm = &mverbs_srx_cm_ops;
    srx->ep_fid.rma = &mverbs_srx_rma_ops;
    srx->ep_fid.atomic = &mverbs_srx_atomic_ops;
    srx->domain = dom;

    /* XRC SRQ creation is delayed until the first endpoint it is bound
     * to is enabled.*/
    if (dom->ext_flags & VRB_USE_XRC) {
        ofi_mutex_init(&srx->xrc.prepost_lock);
        slist_init(&srx->xrc.prepost_list);
        dlist_init(&srx->xrc.srq_entry);
        srx->xrc.max_recv_wr = attr->size;
        srx->xrc.max_sge = attr->iov_limit;
        srx->ep_fid.msg = &mverbs_xrc_srq_msg_ops;
        goto done;
    }

    srx->ep_fid.msg = &mverbs_srq_msg_ops;
    srq_init_attr.attr.max_wr = attr->size;
    srq_init_attr.attr.max_sge = attr->iov_limit;

    srx->srq = ibv_create_srq(dom->pd, &srq_init_attr);
    if (!srx->srq) {
        VRB_WARN_ERRNO(FI_LOG_DOMAIN, "ibv_create_srq");
        ret = -errno;
        goto err;
    }

done:
    *srx_fid = &srx->ep_fid;
    return FI_SUCCESS;

err:
    free(srx);
    return ret;
}

#define VRB_DEF_ATOMICVALID(name, flags)                                       \
    static int mverbs_msg_ep_atomic_##name(struct fid_ep *ep_fid,              \
                                           enum fi_datatype datatype,          \
                                           enum fi_op op, size_t *count)       \
    {                                                                          \
        struct mverbs_ep *ep =                                                 \
            container_of(ep_fid, struct mverbs_ep, util_ep.ep_fid);            \
        struct fi_atomic_attr attr;                                            \
        int ret;                                                               \
                                                                               \
        ret = mverbs_query_atomic(&ep->util_ep.domain->domain_fid, datatype,   \
                                  op, &attr, flags);                           \
        if (!ret)                                                              \
            *count = attr.count;                                               \
        return ret;                                                            \
    }

VRB_DEF_ATOMICVALID(writevalid, 0)
VRB_DEF_ATOMICVALID(readwritevalid, FI_FETCH_ATOMIC)
VRB_DEF_ATOMICVALID(compwritevalid, FI_COMPARE_ATOMIC)

int mverbs_query_atomic(struct fid_domain *domain_fid,
                        enum fi_datatype datatype, enum fi_op op,
                        struct fi_atomic_attr *attr, uint64_t flags)
{
    struct mverbs_domain *domain =
        container_of(domain_fid, struct mverbs_domain, util_domain.domain_fid);
    char *log_str_fetch = "fi_fetch_atomic with FI_SUM op";
    char *log_str_comp = "fi_compare_atomic";
    char *log_str;

    if (flags & FI_TAGGED)
        return -FI_ENOSYS;

    if ((flags & FI_FETCH_ATOMIC) && (flags & FI_COMPARE_ATOMIC))
        return -FI_EBADFLAGS;

    if (!flags) {
        switch (op) {
            case FI_ATOMIC_WRITE:
                break;
            default:
                return -FI_ENOSYS;
        }
    } else {
        if (flags & FI_FETCH_ATOMIC) {
            switch (op) {
                case FI_ATOMIC_READ:
                    goto check_datatype;
                case FI_SUM:
                    log_str = log_str_fetch;
                    break;
                default:
                    return -FI_ENOSYS;
            }
        } else if (flags & FI_COMPARE_ATOMIC) {
            if (op != FI_CSWAP)
                return -FI_ENOSYS;
            log_str = log_str_comp;
        } else {
            return -FI_EBADFLAGS;
        }
        if (domain->info->tx_attr->op_flags & FI_INJECT) {
            VRB_INFO(FI_LOG_EP_DATA, "FI_INJECT not supported for %s\n",
                     log_str);
            return -FI_EINVAL;
        }
    }
check_datatype:
    switch (datatype) {
        case FI_INT64:
        case FI_UINT64:
#if __BITS_PER_LONG == 64
        case FI_DOUBLE:
        case FI_FLOAT:
#endif
            break;
        default:
            return -FI_EINVAL;
    }

    attr->size = ofi_datatype_size(datatype);
    if (attr->size == 0)
        return -FI_EINVAL;

    attr->count = 1;
    return 0;
}

static ssize_t mverbs_msg_ep_atomic_write(struct fid_ep *ep_fid,
                                          const void *buf, size_t count,
                                          void *desc, fi_addr_t dest_addr,
                                          uint64_t addr, uint64_t key,
                                          enum fi_datatype datatype,
                                          enum fi_op op, void *context)
{
    struct mverbs_ep *ep =
        container_of(ep_fid, struct mverbs_ep, util_ep.ep_fid);
    struct ibv_send_wr wr = {
        .wr_id = MVERBS_COMP(ep, (uintptr_t)context),
        .opcode = IBV_WR_RDMA_WRITE,
        .wr.rdma.remote_addr = addr,
        .wr.rdma.rkey = (uint32_t)(uintptr_t)key,
        .send_flags =
            MVERBS_INJECT(ep, sizeof(uint64_t), desc) | IBV_SEND_FENCE,
    };
    size_t count_copy;
    int ret;

    if (OFI_UNLIKELY(count != 1))
        return -FI_E2BIG;

    if (OFI_UNLIKELY(op != FI_ATOMIC_WRITE))
        return -FI_ENOSYS;

    count_copy = count;

    ret = mverbs_msg_ep_atomic_writevalid(ep_fid, datatype, op, &count_copy);
    if (ret)
        return ret;

    return mverbs_send_buf(ep, &wr, buf, sizeof(uint64_t), desc);
}

static ssize_t mverbs_msg_ep_atomic_writev(
    struct fid_ep *ep, const struct fi_ioc *iov, void **desc, size_t count,
    fi_addr_t dest_addr, uint64_t addr, uint64_t key, enum fi_datatype datatype,
    enum fi_op op, void *context)
{
    if (OFI_UNLIKELY(iov->count != 1))
        return -FI_E2BIG;

    return mverbs_msg_ep_atomic_write(ep, iov->addr, count, desc[0], dest_addr,
                                      addr, key, datatype, op, context);
}

static ssize_t mverbs_msg_ep_atomic_writemsg(struct fid_ep *ep_fid,
                                             const struct fi_msg_atomic *msg,
                                             uint64_t flags)
{
    struct mverbs_ep *ep =
        container_of(ep_fid, struct mverbs_ep, util_ep.ep_fid);
    struct ibv_send_wr wr = {
        .wr_id = MVERBS_COMP_FLAGS(ep, flags, (uintptr_t)msg->context),
        .wr.rdma.remote_addr = msg->rma_iov->addr,
        .wr.rdma.rkey = (uint32_t)(uintptr_t)msg->rma_iov->key,
        .send_flags =
            MVERBS_INJECT_FLAGS(ep, sizeof(uint64_t), flags, msg->desc[0]) |
            IBV_SEND_FENCE,
    };
    size_t count_copy;
    int ret;

    if (OFI_UNLIKELY(msg->iov_count != 1 || msg->msg_iov->count != 1))
        return -FI_E2BIG;

    if (OFI_UNLIKELY(msg->op != FI_ATOMIC_WRITE))
        return -FI_ENOSYS;

    count_copy = msg->iov_count;

    ret = mverbs_msg_ep_atomic_writevalid(ep_fid, msg->datatype, msg->op,
                                          &count_copy);
    if (ret)
        return ret;

    if (flags & FI_REMOTE_CQ_DATA) {
        wr.opcode = IBV_WR_RDMA_WRITE_WITH_IMM;
        wr.imm_data = htonl((uint32_t)msg->data);
    } else {
        wr.opcode = IBV_WR_RDMA_WRITE;
    }

    return mverbs_send_buf(ep, &wr, msg->msg_iov->addr, sizeof(uint64_t),
                           msg->desc[0]);
}

static ssize_t mverbs_msg_ep_atomic_readwrite(
    struct fid_ep *ep_fid, const void *buf, size_t count, void *desc,
    void *result, void *result_desc, fi_addr_t dest_addr, uint64_t addr,
    uint64_t key, enum fi_datatype datatype, enum fi_op op, void *context)
{
    struct mverbs_ep *ep =
        container_of(ep_fid, struct mverbs_ep, util_ep.ep_fid);
    struct ibv_send_wr wr = {
        .wr_id = MVERBS_COMP(ep, (uintptr_t)context),
        .send_flags = IBV_SEND_FENCE,
    };
    size_t count_copy;
    int ret;

    if (OFI_UNLIKELY(count != 1))
        return -FI_E2BIG;

    count_copy = count;

    ret =
        mverbs_msg_ep_atomic_readwritevalid(ep_fid, datatype, op, &count_copy);
    if (ret)
        return ret;

    switch (op) {
        case FI_ATOMIC_READ:
            wr.opcode = IBV_WR_RDMA_READ;
            wr.wr.rdma.remote_addr = addr;
            wr.wr.rdma.rkey = (uint32_t)(uintptr_t)key;
            break;
        case FI_SUM:
            wr.opcode = IBV_WR_ATOMIC_FETCH_AND_ADD;
            wr.wr.atomic.remote_addr = addr;
            wr.wr.atomic.compare_add = (uintptr_t)buf;
            wr.wr.atomic.swap = 0;
            wr.wr.atomic.rkey = (uint32_t)(uintptr_t)key;
            break;
        default:
            return -FI_ENOSYS;
    }

    return mverbs_send_buf(ep, &wr, result, sizeof(uint64_t), result_desc);
}

static ssize_t mverbs_msg_ep_atomic_readwritev(
    struct fid_ep *ep, const struct fi_ioc *iov, void **desc, size_t count,
    struct fi_ioc *resultv, void **result_desc, size_t result_count,
    fi_addr_t dest_addr, uint64_t addr, uint64_t key, enum fi_datatype datatype,
    enum fi_op op, void *context)
{
    if (OFI_UNLIKELY(iov->count != 1))
        return -FI_E2BIG;

    return mverbs_msg_ep_atomic_readwrite(
        ep, iov->addr, count, desc[0], resultv->addr, result_desc[0], dest_addr,
        addr, key, datatype, op, context);
}

static ssize_t mverbs_msg_ep_atomic_readwritemsg(
    struct fid_ep *ep_fid, const struct fi_msg_atomic *msg,
    struct fi_ioc *resultv, void **result_desc, size_t result_count,
    uint64_t flags)
{
    struct mverbs_ep *ep =
        container_of(ep_fid, struct mverbs_ep, util_ep.ep_fid);
    struct ibv_send_wr wr = {
        .wr_id = MVERBS_COMP_FLAGS(ep, flags, (uintptr_t)msg->context),
        .send_flags = IBV_SEND_FENCE,
    };
    size_t count_copy;
    int ret;

    if (OFI_UNLIKELY(msg->iov_count != 1 || msg->msg_iov->count != 1))
        return -FI_E2BIG;

    count_copy = msg->iov_count;

    ret = mverbs_msg_ep_atomic_readwritevalid(ep_fid, msg->datatype, msg->op,
                                              &count_copy);
    if (ret)
        return ret;

    switch (msg->op) {
        case FI_ATOMIC_READ:
            wr.opcode = IBV_WR_RDMA_READ;
            wr.wr.rdma.remote_addr = msg->rma_iov->addr;
            wr.wr.rdma.rkey = (uint32_t)(uintptr_t)msg->rma_iov->key;
            break;
        case FI_SUM:
            wr.opcode = IBV_WR_ATOMIC_FETCH_AND_ADD;
            wr.wr.atomic.remote_addr = msg->rma_iov->addr;
            wr.wr.atomic.compare_add = (uintptr_t)msg->addr;
            wr.wr.atomic.swap = 0;
            wr.wr.atomic.rkey = (uint32_t)(uintptr_t)msg->rma_iov->key;
            break;
        default:
            return -FI_ENOSYS;
    }

    if (flags & FI_REMOTE_CQ_DATA)
        wr.imm_data = htonl((uint32_t)msg->data);

    return mverbs_send_buf(ep, &wr, resultv->addr, sizeof(uint64_t),
                           result_desc[0]);
}

static ssize_t mverbs_msg_ep_atomic_compwrite(
    struct fid_ep *ep_fid, const void *buf, size_t count, void *desc,
    const void *compare, void *compare_desc, void *result, void *result_desc,
    fi_addr_t dest_addr, uint64_t addr, uint64_t key, enum fi_datatype datatype,
    enum fi_op op, void *context)
{
    struct mverbs_ep *ep =
        container_of(ep_fid, struct mverbs_ep, util_ep.ep_fid);
    struct ibv_send_wr wr = {
        .wr_id = MVERBS_COMP(ep, (uintptr_t)context),
        .opcode = IBV_WR_ATOMIC_CMP_AND_SWP,
        .wr.atomic.remote_addr = addr,
        .wr.atomic.compare_add = (uintptr_t)compare,
        .wr.atomic.swap = (uintptr_t)buf,
        .wr.atomic.rkey = (uint32_t)(uintptr_t)key,
        .send_flags = IBV_SEND_FENCE,
    };
    size_t count_copy;
    int ret;

    if (OFI_UNLIKELY(count != 1))
        return -FI_E2BIG;

    count_copy = count;

    ret =
        mverbs_msg_ep_atomic_compwritevalid(ep_fid, datatype, op, &count_copy);
    if (ret)
        return ret;

    return mverbs_send_buf(ep, &wr, result, sizeof(uint64_t), result_desc);
}

static ssize_t mverbs_msg_ep_atomic_compwritev(
    struct fid_ep *ep, const struct fi_ioc *iov, void **desc, size_t count,
    const struct fi_ioc *comparev, void **compare_desc, size_t compare_count,
    struct fi_ioc *resultv, void **result_desc, size_t result_count,
    fi_addr_t dest_addr, uint64_t addr, uint64_t key, enum fi_datatype datatype,
    enum fi_op op, void *context)
{
    if (OFI_UNLIKELY(iov->count != 1))
        return -FI_E2BIG;

    return mverbs_msg_ep_atomic_compwrite(
        ep, iov->addr, count, desc[0], comparev->addr, compare_desc[0],
        resultv->addr, result_desc[0], dest_addr, addr, key, datatype, op,
        context);
}

static ssize_t mverbs_msg_ep_atomic_compwritemsg(
    struct fid_ep *ep_fid, const struct fi_msg_atomic *msg,
    const struct fi_ioc *comparev, void **compare_desc, size_t compare_count,
    struct fi_ioc *resultv, void **result_desc, size_t result_count,
    uint64_t flags)
{
    struct mverbs_ep *ep =
        container_of(ep_fid, struct mverbs_ep, util_ep.ep_fid);
    struct ibv_send_wr wr = {
        .wr_id = MVERBS_COMP_FLAGS(ep, flags, (uintptr_t)msg->context),
        .opcode = IBV_WR_ATOMIC_CMP_AND_SWP,
        .wr.atomic.remote_addr = msg->rma_iov->addr,
        .wr.atomic.compare_add = (uintptr_t)comparev->addr,
        .wr.atomic.swap = (uintptr_t)msg->addr,
        .wr.atomic.rkey = (uint32_t)(uintptr_t)msg->rma_iov->key,
        .send_flags = IBV_SEND_FENCE,
    };
    size_t count_copy;
    int ret;

    if (OFI_UNLIKELY(msg->iov_count != 1 || msg->msg_iov->count != 1))
        return -FI_E2BIG;

    count_copy = msg->iov_count;

    ret = mverbs_msg_ep_atomic_compwritevalid(ep_fid, msg->datatype, msg->op,
                                              &count_copy);
    if (ret)
        return ret;

    if (flags & FI_REMOTE_CQ_DATA)
        wr.imm_data = htonl((uint32_t)msg->data);

    return mverbs_send_buf(ep, &wr, resultv->addr, sizeof(uint64_t),
                           result_desc[0]);
}

struct fi_ops_atomic mverbs_msg_ep_atomic_ops = {
    .size = sizeof(struct fi_ops_atomic),
    .write = mverbs_msg_ep_atomic_write,
    .writev = mverbs_msg_ep_atomic_writev,
    .writemsg = mverbs_msg_ep_atomic_writemsg,
    .inject = fi_no_atomic_inject,
    .readwrite = mverbs_msg_ep_atomic_readwrite,
    .readwritev = mverbs_msg_ep_atomic_readwritev,
    .readwritemsg = mverbs_msg_ep_atomic_readwritemsg,
    .compwrite = mverbs_msg_ep_atomic_compwrite,
    .compwritev = mverbs_msg_ep_atomic_compwritev,
    .compwritemsg = mverbs_msg_ep_atomic_compwritemsg,
    .writevalid = mverbs_msg_ep_atomic_writevalid,
    .readwritevalid = mverbs_msg_ep_atomic_readwritevalid,
    .compwritevalid = mverbs_msg_ep_atomic_compwritevalid};

static ssize_t mverbs_msg_xrc_ep_atomic_write(struct fid_ep *ep_fid,
                                              const void *buf, size_t count,
                                              void *desc, fi_addr_t dest_addr,
                                              uint64_t addr, uint64_t key,
                                              enum fi_datatype datatype,
                                              enum fi_op op, void *context)
{
    struct mverbs_xrc_ep *ep =
        container_of(ep_fid, struct mverbs_xrc_ep, base_ep.util_ep.ep_fid);
    struct ibv_send_wr wr = {
        .wr_id = MVERBS_COMP(&ep->base_ep, (uintptr_t)context),
        .opcode = IBV_WR_RDMA_WRITE,
        .wr.rdma.remote_addr = addr,
        .wr.rdma.rkey = (uint32_t)(uintptr_t)key,
        .send_flags = MVERBS_INJECT(&ep->base_ep, sizeof(uint64_t), desc) |
                      IBV_SEND_FENCE,
    };
    size_t count_copy;
    int ret;

    if (OFI_UNLIKELY(count != 1))
        return -FI_E2BIG;

    if (OFI_UNLIKELY(op != FI_ATOMIC_WRITE))
        return -FI_ENOSYS;

    VRB_SET_REMOTE_SRQN(wr, ep->peer_srqn);

    count_copy = count;

    ret = mverbs_msg_ep_atomic_writevalid(ep_fid, datatype, op, &count_copy);
    if (ret)
        return ret;

    return mverbs_send_buf(&ep->base_ep, &wr, buf, sizeof(uint64_t), desc);
}

static ssize_t mverbs_msg_xrc_ep_atomic_writemsg(
    struct fid_ep *ep_fid, const struct fi_msg_atomic *msg, uint64_t flags)
{
    struct mverbs_xrc_ep *ep =
        container_of(ep_fid, struct mverbs_xrc_ep, base_ep.util_ep.ep_fid);
    struct ibv_send_wr wr = {
        .wr_id =
            MVERBS_COMP_FLAGS(&ep->base_ep, flags, (uintptr_t)msg->context),
        .wr.rdma.remote_addr = msg->rma_iov->addr,
        .wr.rdma.rkey = (uint32_t)(uintptr_t)msg->rma_iov->key,
        .send_flags = MVERBS_INJECT_FLAGS(&ep->base_ep, sizeof(uint64_t), flags,
                                          msg->desc[0]) |
                      IBV_SEND_FENCE,
    };
    size_t count_copy;
    int ret;

    if (OFI_UNLIKELY(msg->iov_count != 1 || msg->msg_iov->count != 1))
        return -FI_E2BIG;

    if (OFI_UNLIKELY(msg->op != FI_ATOMIC_WRITE))
        return -FI_ENOSYS;

    VRB_SET_REMOTE_SRQN(wr, ep->peer_srqn);
    count_copy = msg->iov_count;

    ret = mverbs_msg_ep_atomic_writevalid(ep_fid, msg->datatype, msg->op,
                                          &count_copy);
    if (ret)
        return ret;

    if (flags & FI_REMOTE_CQ_DATA) {
        wr.opcode = IBV_WR_RDMA_WRITE_WITH_IMM;
        wr.imm_data = htonl((uint32_t)msg->data);
    } else {
        wr.opcode = IBV_WR_RDMA_WRITE;
    }

    return mverbs_send_buf(&ep->base_ep, &wr, msg->msg_iov->addr,
                           sizeof(uint64_t), msg->desc[0]);
}

static ssize_t mverbs_msg_xrc_ep_atomic_readwrite(
    struct fid_ep *ep_fid, const void *buf, size_t count, void *desc,
    void *result, void *result_desc, fi_addr_t dest_addr, uint64_t addr,
    uint64_t key, enum fi_datatype datatype, enum fi_op op, void *context)
{
    struct mverbs_xrc_ep *ep =
        container_of(ep_fid, struct mverbs_xrc_ep, base_ep.util_ep.ep_fid);
    struct ibv_send_wr wr = {
        .wr_id = MVERBS_COMP(&ep->base_ep, (uintptr_t)context),
        .send_flags = IBV_SEND_FENCE,
    };
    size_t count_copy;
    int ret;

    if (OFI_UNLIKELY(count != 1))
        return -FI_E2BIG;

    VRB_SET_REMOTE_SRQN(wr, ep->peer_srqn);
    count_copy = count;

    ret =
        mverbs_msg_ep_atomic_readwritevalid(ep_fid, datatype, op, &count_copy);
    if (ret)
        return ret;

    switch (op) {
        case FI_ATOMIC_READ:
            wr.opcode = IBV_WR_RDMA_READ;
            wr.wr.rdma.remote_addr = addr;
            wr.wr.rdma.rkey = (uint32_t)(uintptr_t)key;
            break;
        case FI_SUM:
            wr.opcode = IBV_WR_ATOMIC_FETCH_AND_ADD;
            wr.wr.atomic.remote_addr = addr;
            wr.wr.atomic.compare_add = (uintptr_t)buf;
            wr.wr.atomic.swap = 0;
            wr.wr.atomic.rkey = (uint32_t)(uintptr_t)key;
            break;
        default:
            return -FI_ENOSYS;
    }

    return mverbs_send_buf(&ep->base_ep, &wr, result, sizeof(uint64_t),
                           result_desc);
}

static ssize_t mverbs_msg_xrc_ep_atomic_readwritemsg(
    struct fid_ep *ep_fid, const struct fi_msg_atomic *msg,
    struct fi_ioc *resultv, void **result_desc, size_t result_count,
    uint64_t flags)
{
    struct mverbs_xrc_ep *ep =
        container_of(ep_fid, struct mverbs_xrc_ep, base_ep.util_ep.ep_fid);
    struct ibv_send_wr wr = {
        .wr_id =
            MVERBS_COMP_FLAGS(&ep->base_ep, flags, (uintptr_t)msg->context),
        .send_flags = IBV_SEND_FENCE,
    };
    size_t count_copy;
    int ret;

    if (OFI_UNLIKELY(msg->iov_count != 1 || msg->msg_iov->count != 1))
        return -FI_E2BIG;

    VRB_SET_REMOTE_SRQN(wr, ep->peer_srqn);
    count_copy = msg->iov_count;

    ret = mverbs_msg_ep_atomic_readwritevalid(ep_fid, msg->datatype, msg->op,
                                              &count_copy);
    if (ret)
        return ret;

    switch (msg->op) {
        case FI_ATOMIC_READ:
            wr.opcode = IBV_WR_RDMA_READ;
            wr.wr.rdma.remote_addr = msg->rma_iov->addr;
            wr.wr.rdma.rkey = (uint32_t)(uintptr_t)msg->rma_iov->key;
            break;
        case FI_SUM:
            wr.opcode = IBV_WR_ATOMIC_FETCH_AND_ADD;
            wr.wr.atomic.remote_addr = msg->rma_iov->addr;
            wr.wr.atomic.compare_add = (uintptr_t)msg->addr;
            wr.wr.atomic.swap = 0;
            wr.wr.atomic.rkey = (uint32_t)(uintptr_t)msg->rma_iov->key;
            break;
        default:
            return -FI_ENOSYS;
    }

    if (flags & FI_REMOTE_CQ_DATA)
        wr.imm_data = htonl((uint32_t)msg->data);

    return mverbs_send_buf(&ep->base_ep, &wr, resultv->addr, sizeof(uint64_t),
                           result_desc[0]);
}

static ssize_t mverbs_msg_xrc_ep_atomic_compwrite(
    struct fid_ep *ep_fid, const void *buf, size_t count, void *desc,
    const void *compare, void *compare_desc, void *result, void *result_desc,
    fi_addr_t dest_addr, uint64_t addr, uint64_t key, enum fi_datatype datatype,
    enum fi_op op, void *context)
{
    struct mverbs_xrc_ep *ep =
        container_of(ep_fid, struct mverbs_xrc_ep, base_ep.util_ep.ep_fid);
    struct ibv_send_wr wr = {
        .wr_id = MVERBS_COMP(&ep->base_ep, (uintptr_t)context),
        .opcode = IBV_WR_ATOMIC_CMP_AND_SWP,
        .wr.atomic.remote_addr = addr,
        .wr.atomic.compare_add = (uintptr_t)compare,
        .wr.atomic.swap = (uintptr_t)buf,
        .wr.atomic.rkey = (uint32_t)(uintptr_t)key,
        .send_flags = IBV_SEND_FENCE,
    };
    size_t count_copy;
    int ret;

    if (OFI_UNLIKELY(count != 1))
        return -FI_E2BIG;

    VRB_SET_REMOTE_SRQN(wr, ep->peer_srqn);
    count_copy = count;

    ret =
        mverbs_msg_ep_atomic_compwritevalid(ep_fid, datatype, op, &count_copy);
    if (ret)
        return ret;

    return mverbs_send_buf(&ep->base_ep, &wr, result, sizeof(uint64_t),
                           result_desc);
}

static ssize_t mverbs_msg_xrc_ep_atomic_compwritemsg(
    struct fid_ep *ep_fid, const struct fi_msg_atomic *msg,
    const struct fi_ioc *comparev, void **compare_desc, size_t compare_count,
    struct fi_ioc *resultv, void **result_desc, size_t result_count,
    uint64_t flags)
{
    struct mverbs_xrc_ep *ep =
        container_of(ep_fid, struct mverbs_xrc_ep, base_ep.util_ep.ep_fid);
    struct ibv_send_wr wr = {
        .wr_id =
            MVERBS_COMP_FLAGS(&ep->base_ep, flags, (uintptr_t)msg->context),
        .opcode = IBV_WR_ATOMIC_CMP_AND_SWP,
        .wr.atomic.remote_addr = msg->rma_iov->addr,
        .wr.atomic.compare_add = (uintptr_t)comparev->addr,
        .wr.atomic.swap = (uintptr_t)msg->addr,
        .wr.atomic.rkey = (uint32_t)(uintptr_t)msg->rma_iov->key,
        .send_flags = IBV_SEND_FENCE,
    };
    size_t count_copy;
    int ret;

    if (OFI_UNLIKELY(msg->iov_count != 1 || msg->msg_iov->count != 1))
        return -FI_E2BIG;

    VRB_SET_REMOTE_SRQN(wr, ep->peer_srqn);
    count_copy = msg->iov_count;

    ret = mverbs_msg_ep_atomic_compwritevalid(ep_fid, msg->datatype, msg->op,
                                              &count_copy);
    if (ret)
        return ret;

    if (flags & FI_REMOTE_CQ_DATA)
        wr.imm_data = htonl((uint32_t)msg->data);

    return mverbs_send_buf(&ep->base_ep, &wr, resultv->addr, sizeof(uint64_t),
                           result_desc[0]);
}

struct fi_ops_atomic mverbs_msg_xrc_ep_atomic_ops = {
    .size = sizeof(struct fi_ops_atomic),
    .write = mverbs_msg_xrc_ep_atomic_write,
    .writev = mverbs_msg_ep_atomic_writev,
    .writemsg = mverbs_msg_xrc_ep_atomic_writemsg,
    .inject = fi_no_atomic_inject,
    .readwrite = mverbs_msg_xrc_ep_atomic_readwrite,
    .readwritev = mverbs_msg_ep_atomic_readwritev,
    .readwritemsg = mverbs_msg_xrc_ep_atomic_readwritemsg,
    .compwrite = mverbs_msg_xrc_ep_atomic_compwrite,
    .compwritev = mverbs_msg_ep_atomic_compwritev,
    .compwritemsg = mverbs_msg_xrc_ep_atomic_compwritemsg,
    .writevalid = mverbs_msg_ep_atomic_writevalid,
    .readwritevalid = mverbs_msg_ep_atomic_readwritevalid,
    .compwritevalid = mverbs_msg_ep_atomic_compwritevalid};
