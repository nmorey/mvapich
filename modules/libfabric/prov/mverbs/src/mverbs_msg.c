/*
 * Copyright (c) 2013-2018 Intel Corporation, Inc.  All rights reserved.
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

#include "config.h"

#include "mverbs_ofi.h"

static inline ssize_t mverbs_msg_ep_recvmsg(struct fid_ep *ep_fid,
                                            const struct fi_msg *msg,
                                            uint64_t flags)
{
    struct mverbs_ep *ep =
        container_of(ep_fid, struct mverbs_ep, util_ep.ep_fid);
    struct ibv_recv_wr wr = {
        .wr_id = (uintptr_t)msg->context,
        .num_sge = msg->iov_count,
        .next = NULL,
    };

    mverbs_iov_dupa(wr.sg_list, msg->msg_iov, msg->desc, msg->iov_count);
    return mverbs_post_recv(ep, &wr);
}

static ssize_t mverbs_msg_ep_recv(struct fid_ep *ep_fid, void *buf, size_t len,
                                  void *desc, fi_addr_t src_addr, void *context)
{
    struct mverbs_ep *ep =
        container_of(ep_fid, struct mverbs_ep, util_ep.ep_fid);
    struct ibv_sge sge = mverbs_init_sge(buf, len, desc);
    struct ibv_recv_wr wr = {
        .wr_id = (uintptr_t)context,
        .num_sge = 1,
        .sg_list = &sge,
        .next = NULL,
    };

    return mverbs_post_recv(ep, &wr);
}

static ssize_t mverbs_msg_ep_recvv(struct fid_ep *ep_fid,
                                   const struct iovec *iov, void **desc,
                                   size_t count, fi_addr_t src_addr,
                                   void *context)
{
    struct fi_msg msg = {
        .msg_iov = iov,
        .desc = desc,
        .iov_count = count,
        .addr = src_addr,
        .context = context,
    };

    return mverbs_msg_ep_recvmsg(ep_fid, &msg, 0);
}

static ssize_t mverbs_msg_ep_sendmsg(struct fid_ep *ep_fid,
                                     const struct fi_msg *msg, uint64_t flags)
{
    struct mverbs_ep *ep =
        container_of(ep_fid, struct mverbs_ep, util_ep.ep_fid);
    struct ibv_send_wr wr = {
        .wr_id = (uintptr_t)msg->context,
    };

    if (flags & FI_REMOTE_CQ_DATA) {
        wr.opcode = IBV_WR_SEND_WITH_IMM;
        wr.imm_data = htonl((uint32_t)msg->data);
    } else {
        wr.opcode = IBV_WR_SEND;
    }

    return mverbs_send_iov(ep, &wr, msg->msg_iov, msg->desc, msg->iov_count,
                           flags);
}

static ssize_t mverbs_msg_ep_send(struct fid_ep *ep_fid, const void *buf,
                                  size_t len, void *desc, fi_addr_t dest_addr,
                                  void *context)
{
    struct mverbs_ep *ep =
        container_of(ep_fid, struct mverbs_ep, util_ep.ep_fid);
    struct ibv_send_wr wr = {
        .wr_id = MVERBS_COMP(ep, (uintptr_t)context),
        .opcode = IBV_WR_SEND,
        .send_flags = MVERBS_INJECT(ep, len, desc),
    };

    return mverbs_send_buf(ep, &wr, buf, len, desc);
}

static ssize_t mverbs_msg_ep_senddata(struct fid_ep *ep_fid, const void *buf,
                                      size_t len, void *desc, uint64_t data,
                                      fi_addr_t dest_addr, void *context)
{
    struct mverbs_ep *ep =
        container_of(ep_fid, struct mverbs_ep, util_ep.ep_fid);
    struct ibv_send_wr wr = {
        .wr_id = MVERBS_COMP(ep, (uintptr_t)context),
        .opcode = IBV_WR_SEND_WITH_IMM,
        .send_flags = MVERBS_INJECT(ep, len, desc),
    };

    wr.imm_data = htonl((uint32_t)data);

    return mverbs_send_buf(ep, &wr, buf, len, desc);
}

static ssize_t mverbs_msg_ep_sendv(struct fid_ep *ep_fid,
                                   const struct iovec *iov, void **desc,
                                   size_t count, fi_addr_t dest_addr,
                                   void *context)
{
    struct mverbs_ep *ep =
        container_of(ep_fid, struct mverbs_ep, util_ep.ep_fid);
    struct ibv_send_wr wr = {
        .wr_id = (uintptr_t)context,
        .opcode = IBV_WR_SEND,
    };

    return mverbs_send_iov(ep, &wr, iov, desc, count, ep->util_ep.tx_op_flags);
}

static ssize_t mverbs_msg_ep_inject(struct fid_ep *ep_fid, const void *buf,
                                    size_t len, fi_addr_t dest_addr)
{
    struct mverbs_ep *ep =
        container_of(ep_fid, struct mverbs_ep, util_ep.ep_fid);
    struct ibv_send_wr wr = {
        .wr_id = MVERBS_NO_COMP_FLAG,
        .opcode = IBV_WR_SEND,
        .send_flags = IBV_SEND_INLINE,
    };

    return mverbs_send_buf(ep, &wr, buf, len, NULL);
}

static ssize_t mverbs_msg_ep_injectdata(struct fid_ep *ep_fid, const void *buf,
                                        size_t len, uint64_t data,
                                        fi_addr_t dest_addr)
{
    struct mverbs_ep *ep =
        container_of(ep_fid, struct mverbs_ep, util_ep.ep_fid);
    struct ibv_send_wr wr = {
        .wr_id = MVERBS_NO_COMP_FLAG,
        .opcode = IBV_WR_SEND_WITH_IMM,
        .send_flags = IBV_SEND_INLINE,
    };

    wr.imm_data = htonl((uint32_t)data);

    return mverbs_send_buf(ep, &wr, buf, len, NULL);
}

static ssize_t mverbs_msg_inject_fast(struct fid_ep *ep_fid, const void *buf,
                                      size_t len, fi_addr_t dest_addr)
{
    struct mverbs_ep *ep =
        container_of(ep_fid, struct mverbs_ep, util_ep.ep_fid);

    ep->wrs->sge.addr = (uintptr_t)buf;
    ep->wrs->sge.length = (uint32_t)len;

    return mverbs_post_send(ep, &ep->wrs->msg_wr, 0);
}

static ssize_t mverbs_msg_ep_injectdata_fast(struct fid_ep *ep_fid,
                                             const void *buf, size_t len,
                                             uint64_t data, fi_addr_t dest_addr)
{
    ssize_t ret;
    struct mverbs_ep *ep =
        container_of(ep_fid, struct mverbs_ep, util_ep.ep_fid);

    ep->wrs->msg_wr.imm_data = htonl((uint32_t)data);
    ep->wrs->msg_wr.opcode = IBV_WR_SEND_WITH_IMM;

    ep->wrs->sge.addr = (uintptr_t)buf;
    ep->wrs->sge.length = (uint32_t)len;

    ret = mverbs_post_send(ep, &ep->wrs->msg_wr, 0);
    ep->wrs->msg_wr.opcode = IBV_WR_SEND;
    return ret;
}

const struct fi_ops_msg mverbs_msg_ep_msg_ops_ts = {
    .size = sizeof(struct fi_ops_msg),
    .recv = mverbs_msg_ep_recv,
    .recvv = mverbs_msg_ep_recvv,
    .recvmsg = mverbs_msg_ep_recvmsg,
    .send = mverbs_msg_ep_send,
    .sendv = mverbs_msg_ep_sendv,
    .sendmsg = mverbs_msg_ep_sendmsg,
    .inject = mverbs_msg_ep_inject,
    .senddata = mverbs_msg_ep_senddata,
    .injectdata = mverbs_msg_ep_injectdata,
};

const struct fi_ops_msg mverbs_msg_ep_msg_ops = {
    .size = sizeof(struct fi_ops_msg),
    .recv = mverbs_msg_ep_recv,
    .recvv = mverbs_msg_ep_recvv,
    .recvmsg = mverbs_msg_ep_recvmsg,
    .send = mverbs_msg_ep_send,
    .sendv = mverbs_msg_ep_sendv,
    .sendmsg = mverbs_msg_ep_sendmsg,
    .inject = mverbs_msg_inject_fast,
    .senddata = mverbs_msg_ep_senddata,
    .injectdata = mverbs_msg_ep_injectdata_fast,
};

static ssize_t mverbs_msg_xrc_ep_sendmsg(struct fid_ep *ep_fid,
                                         const struct fi_msg *msg,
                                         uint64_t flags)
{
    struct mverbs_xrc_ep *ep =
        container_of(ep_fid, struct mverbs_xrc_ep, base_ep.util_ep.ep_fid);
    struct ibv_send_wr wr = {
        .wr_id = (uintptr_t)msg->context,
    };

    VRB_SET_REMOTE_SRQN(wr, ep->peer_srqn);

    if (flags & FI_REMOTE_CQ_DATA) {
        wr.opcode = IBV_WR_SEND_WITH_IMM;
        wr.imm_data = htonl((uint32_t)msg->data);
    } else {
        wr.opcode = IBV_WR_SEND;
    }

    return mverbs_send_iov(&ep->base_ep, &wr, msg->msg_iov, msg->desc,
                           msg->iov_count, flags);
}

static ssize_t mverbs_msg_xrc_ep_send(struct fid_ep *ep_fid, const void *buf,
                                      size_t len, void *desc,
                                      fi_addr_t dest_addr, void *context)
{
    struct mverbs_xrc_ep *ep =
        container_of(ep_fid, struct mverbs_xrc_ep, base_ep.util_ep.ep_fid);
    struct ibv_send_wr wr = {
        .wr_id = MVERBS_COMP(&ep->base_ep, (uintptr_t)context),
        .opcode = IBV_WR_SEND,
        .send_flags = MVERBS_INJECT(&ep->base_ep, len, desc),
    };

    VRB_SET_REMOTE_SRQN(wr, ep->peer_srqn);

    return mverbs_send_buf(&ep->base_ep, &wr, buf, len, desc);
}

static ssize_t mverbs_msg_xrc_ep_senddata(struct fid_ep *ep_fid,
                                          const void *buf, size_t len,
                                          void *desc, uint64_t data,
                                          fi_addr_t dest_addr, void *context)
{
    struct mverbs_xrc_ep *ep =
        container_of(ep_fid, struct mverbs_xrc_ep, base_ep.util_ep.ep_fid);
    struct ibv_send_wr wr = {
        .wr_id = MVERBS_COMP(&ep->base_ep, (uintptr_t)context),
        .opcode = IBV_WR_SEND_WITH_IMM,
        .send_flags = MVERBS_INJECT(&ep->base_ep, len, desc),
    };

    wr.imm_data = htonl((uint32_t)data);

    VRB_SET_REMOTE_SRQN(wr, ep->peer_srqn);

    return mverbs_send_buf(&ep->base_ep, &wr, buf, len, desc);
}

static ssize_t mverbs_msg_xrc_ep_sendv(struct fid_ep *ep_fid,
                                       const struct iovec *iov, void **desc,
                                       size_t count, fi_addr_t dest_addr,
                                       void *context)
{
    struct mverbs_xrc_ep *ep =
        container_of(ep_fid, struct mverbs_xrc_ep, base_ep.util_ep.ep_fid);
    struct ibv_send_wr wr = {
        .wr_id = (uintptr_t)context,
        .opcode = IBV_WR_SEND,
    };

    VRB_SET_REMOTE_SRQN(wr, ep->peer_srqn);

    return mverbs_send_iov(&ep->base_ep, &wr, iov, desc, count,
                           ep->base_ep.util_ep.tx_op_flags);
}

static ssize_t mverbs_msg_xrc_ep_inject(struct fid_ep *ep_fid, const void *buf,
                                        size_t len, fi_addr_t dest_addr)
{
    struct mverbs_xrc_ep *ep =
        container_of(ep_fid, struct mverbs_xrc_ep, base_ep.util_ep.ep_fid);
    struct ibv_send_wr wr = {
        .wr_id = MVERBS_NO_COMP_FLAG,
        .opcode = IBV_WR_SEND,
        .send_flags = IBV_SEND_INLINE,
    };

    VRB_SET_REMOTE_SRQN(wr, ep->peer_srqn);

    return mverbs_send_buf(&ep->base_ep, &wr, buf, len, NULL);
}

static ssize_t mverbs_msg_xrc_ep_injectdata(struct fid_ep *ep_fid,
                                            const void *buf, size_t len,
                                            uint64_t data, fi_addr_t dest_addr)
{
    struct mverbs_xrc_ep *ep =
        container_of(ep_fid, struct mverbs_xrc_ep, base_ep.util_ep.ep_fid);
    struct ibv_send_wr wr = {
        .wr_id = MVERBS_NO_COMP_FLAG,
        .opcode = IBV_WR_SEND_WITH_IMM,
        .send_flags = IBV_SEND_INLINE,
    };

    wr.imm_data = htonl((uint32_t)data);

    VRB_SET_REMOTE_SRQN(wr, ep->peer_srqn);

    return mverbs_send_buf(&ep->base_ep, &wr, buf, len, NULL);
}

/* NOTE: Initially the XRC endpoint must be used with a SRQ. */
const struct fi_ops_msg mverbs_msg_xrc_ep_msg_ops_ts = {
    .size = sizeof(struct fi_ops_msg),
    .recv = fi_no_msg_recv,
    .recvv = fi_no_msg_recvv,
    .recvmsg = fi_no_msg_recvmsg,
    .send = fi_no_msg_send,
    .sendv = fi_no_msg_sendv,
    .sendmsg = fi_no_msg_sendmsg,
    .inject = fi_no_msg_inject,
    .senddata = fi_no_msg_senddata,
    .injectdata = fi_no_msg_injectdata,
};

const struct fi_ops_msg mverbs_msg_xrc_ep_msg_ops = {
    .size = sizeof(struct fi_ops_msg),
    .recv = fi_no_msg_recv,
    .recvv = fi_no_msg_recvv,
    .recvmsg = fi_no_msg_recvmsg,
    .send = fi_no_msg_send,
    .sendv = fi_no_msg_sendv,
    .sendmsg = fi_no_msg_sendmsg,
    .inject = fi_no_msg_inject,
    .senddata = fi_no_msg_senddata,
    .injectdata = fi_no_msg_injectdata,
};

const struct fi_ops_msg mverbs_msg_srq_xrc_ep_msg_ops = {
    .size = sizeof(struct fi_ops_msg),
    .recv = fi_no_msg_recv,
    .recvv = fi_no_msg_recvv,
    .recvmsg = fi_no_msg_recvmsg,
    .send = mverbs_msg_xrc_ep_send,
    .sendv = mverbs_msg_xrc_ep_sendv,
    .sendmsg = mverbs_msg_xrc_ep_sendmsg,
    .inject = mverbs_msg_xrc_ep_inject,
    .senddata = mverbs_msg_xrc_ep_senddata,
    .injectdata = mverbs_msg_xrc_ep_injectdata,
};
