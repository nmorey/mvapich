/*
 * Copyright (c) 2013-2021 Intel Corporation, Inc.  All rights reserved.
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

#include <ofi_mem.h>

#include "mverbs_ofi.h"
#include "ofi_hmem.h"
#include "mverbs_osd.h"

static void mverbs_fini(void);

static const char *local_node = "localhost";

#define MVERBS_DEFAULT_MIN_RNR_TIMER 12

struct mverbs_gl_data mverbs_gl_data = {
    .def_tx_size = 384,
    .def_rx_size = 384,
    .def_tx_iov_limit = 1,
    .def_rx_iov_limit = 1,
    .def_inline_size = 256,
    .min_rnr_timer = MVERBS_DEFAULT_MIN_RNR_TIMER,
    .use_odp = 0,
    .cqread_bunch_size = 8,
    .iface = NULL,
    .gid_idx = 0,
    .dgram =
        {
            .use_name_server = 1,
            .name_server_port = 5678,
        },

    .msg =
        {
            /* Disabled by default. Use XRC transport for message
             * endpoint only if it is explicitly requested */
            .prefer_xrc = 0,
            .xrcd_filename = "/tmp/mverbs_xrcd",
        },
};

struct mverbs_dev_preset {
    int max_inline_data;
    const char *dev_name_prefix;
} mverbs_dev_presets[] = {
    {
        .max_inline_data = 48,
        .dev_name_prefix = "i40iw",
    },
};

struct fi_provider mverbs_prov = {.name = MVERBS_PROV_NAME,
                                  .version = OFI_VERSION_DEF_PROV,
                                  .fi_version = OFI_VERSION_LATEST,
                                  .getinfo = mverbs_getinfo,
                                  .fabric = mverbs_fabric,
                                  .cleanup = mverbs_fini};

struct util_prov mverbs_util_prov = {
    .prov = &mverbs_prov,
    .info = NULL,
    /* The support of the shared recieve contexts
     * is dynamically calculated */
    .flags = 0,
};

/* mutex for guarding the initialization of mverbs_util_prov.info */
ofi_mutex_t mverbs_init_mutex;

int mverbs_sockaddr_len(struct sockaddr *addr)
{
    if (addr->sa_family == AF_IB)
        return sizeof(struct sockaddr_ib);
    else
        return ofi_sizeofaddr(addr);
}

static int mverbs_get_rdmacm_rai(const char *node, const char *service,
                                 uint64_t flags, uint32_t addr_format,
                                 void *src_addr, size_t src_addrlen,
                                 void *dest_addr, size_t dest_addrlen,
                                 struct rdma_addrinfo **rai)
{
    struct rdma_addrinfo rai_hints, *_rai;
    struct rdma_addrinfo **cur, *next;
    int ret;

    ret = mverbs_set_rai(addr_format, src_addr, src_addrlen, dest_addr,
                         dest_addrlen, flags, &rai_hints);
    if (ret)
        goto out;

    if (!node && !rai_hints.ai_dst_addr) {
        if (!rai_hints.ai_src_addr && !service)
            node = local_node;
        rai_hints.ai_flags |= RAI_PASSIVE;
    }

    ret = rdma_getaddrinfo((char *)node, (char *)service, &rai_hints, &_rai);
    if (ret) {
        VRB_WARN_ERRNO(FI_LOG_FABRIC, "rdma_getaddrinfo");
        if (errno)
            ret = -errno;
        goto out;
    }

    /*
     * Remove ib_rai entries added by IBACM to
     * prevent wrong ib_connect_hdr from being sent in connect request.
     */
    if (addr_format && (addr_format != FI_SOCKADDR_IB)) {
        for (cur = &_rai; *cur;) {
            if ((*cur)->ai_family == AF_IB) {
                next = (*cur)->ai_next;
                (*cur)->ai_next = NULL;
                rdma_freeaddrinfo(*cur);
                *cur = next;
            } else {
                cur = &(*cur)->ai_next;
            }
        }
    }

    *rai = _rai;
out:
    if (rai_hints.ai_src_addr)
        free(rai_hints.ai_src_addr);
    if (rai_hints.ai_dst_addr)
        free(rai_hints.ai_dst_addr);
    return ret;
}

static int mverbs_get_sib_rai(const char *node, const char *service,
                              uint64_t flags, uint32_t addr_format,
                              void *src_addr, size_t src_addrlen,
                              void *dest_addr, size_t dest_addrlen,
                              struct rdma_addrinfo **rai)
{
    struct sockaddr_ib *sib;
    size_t sib_len;
    char *straddr;
    uint32_t fmt;
    int ret;
    bool has_prefix;
    const char *prefix = "fi_sockaddr_ib://";

    *rai = calloc(1, sizeof(struct rdma_addrinfo));
    if (*rai == NULL)
        return -FI_ENOMEM;

    ret = mverbs_set_rai(addr_format, src_addr, src_addrlen, dest_addr,
                         dest_addrlen, flags, *rai);
    if (ret)
        return ret;

    if (node) {
        fmt = ofi_addr_format(node);
        if (fmt == FI_SOCKADDR_IB)
            has_prefix = true;
        else if (fmt == FI_FORMAT_UNSPEC)
            has_prefix = false;
        else
            return -FI_EINVAL;

        if (service) {
            ret = asprintf(&straddr, "%s%s:%s", has_prefix ? "" : prefix, node,
                           service);
        } else {
            ret = asprintf(&straddr, "%s%s", has_prefix ? "" : prefix, node);
        }

        if (ret == -1)
            return -FI_ENOMEM;

        ret = ofi_str_toaddr(straddr, &fmt, (void **)&sib, &sib_len);
        free(straddr);

        if (ret || fmt != FI_SOCKADDR_IB) {
            return -FI_EINVAL;
        }

        if (flags & FI_SOURCE) {
            (*rai)->ai_flags |= RAI_PASSIVE;
            if ((*rai)->ai_src_addr)
                free((*rai)->ai_src_addr);
            (*rai)->ai_src_addr = (void *)sib;
            (*rai)->ai_src_len = sizeof(struct sockaddr_ib);
        } else {
            if ((*rai)->ai_dst_addr)
                free((*rai)->ai_dst_addr);
            (*rai)->ai_dst_addr = (void *)sib;
            (*rai)->ai_dst_len = sizeof(struct sockaddr_ib);
        }

    } else if (service) {
        if ((flags & FI_SOURCE) && (*rai)->ai_src_addr) {
            if ((*rai)->ai_src_len < sizeof(struct sockaddr_ib))
                return -FI_EINVAL;

            (*rai)->ai_src_len = sizeof(struct sockaddr_ib);
            sib = (struct sockaddr_ib *)(*rai)->ai_src_addr;
        } else {
            if ((*rai)->ai_dst_len < sizeof(struct sockaddr_ib))
                return -FI_EINVAL;

            (*rai)->ai_dst_len = sizeof(struct sockaddr_ib);
            sib = (struct sockaddr_ib *)(*rai)->ai_dst_addr;
        }

        sib->sib_sid =
            htonll(((uint64_t)RDMA_PS_IB << 16) + (uint16_t)atoi(service));
        sib->sib_sid_mask = htonll(OFI_IB_IP_PS_MASK | OFI_IB_IP_PORT_MASK);
    }

    return 0;
}

static int mverbs_get_rdma_rai(const char *node, const char *service,
                               uint32_t addr_format, void *src_addr,
                               size_t src_addrlen, void *dest_addr,
                               size_t dest_addrlen, uint64_t flags,
                               struct rdma_addrinfo **rai)
{
    if (addr_format == FI_SOCKADDR_IB && (node || src_addr || dest_addr)) {
        return mverbs_get_sib_rai(node, service, flags, addr_format, src_addr,
                                  src_addrlen, dest_addr, dest_addrlen, rai);
    }

    return mverbs_get_rdmacm_rai(node, service, flags, addr_format, src_addr,
                                 src_addrlen, dest_addr, dest_addrlen, rai);
}

int mverbs_get_rai_id(const char *node, const char *service, uint64_t flags,
                      const struct fi_info *hints, struct rdma_addrinfo **rai,
                      struct rdma_cm_id **id)
{
    int ret;

    // TODO create a similar function that won't require pruning ib_rai
    if (hints) {
        ret = mverbs_get_rdma_rai(node, service, hints->addr_format,
                                  hints->src_addr, hints->src_addrlen,
                                  hints->dest_addr, hints->dest_addrlen, flags,
                                  rai);
    } else {
        ret = mverbs_get_rdma_rai(node, service, FI_FORMAT_UNSPEC, NULL, 0,
                                  NULL, 0, flags, rai);
    }
    if (ret)
        return ret;

    ret = rdma_create_id(
        NULL, id, NULL,
        mverbs_get_port_space(hints ? hints->addr_format : FI_FORMAT_UNSPEC));
    if (ret) {
        VRB_WARN_ERRNO(FI_LOG_FABRIC, "rdma_create_id");
        ret = -errno;
        goto err1;
    }

    if ((*rai)->ai_flags & RAI_PASSIVE) {
        ret = rdma_bind_addr(*id, (*rai)->ai_src_addr);
        if (ret) {
            VRB_WARN_ERRNO(FI_LOG_FABRIC, "rdma_bind_addr");
            ofi_straddr_log(&mverbs_prov, FI_LOG_INFO, FI_LOG_FABRIC,
                            "bind addr", (*rai)->ai_src_addr);
            ret = -errno;
            goto err2;
        }
        return 0;
    }

    ret = rdma_resolve_addr(*id, (*rai)->ai_src_addr, (*rai)->ai_dst_addr,
                            MVERBS_RESOLVE_TIMEOUT);
    if (ret) {
        VRB_WARN_ERRNO(FI_LOG_FABRIC, "rdma_resolve_addr");
        ofi_straddr_log(&mverbs_prov, FI_LOG_INFO, FI_LOG_FABRIC, "src addr",
                        (*rai)->ai_src_addr);
        ofi_straddr_log(&mverbs_prov, FI_LOG_INFO, FI_LOG_FABRIC, "dst addr",
                        (*rai)->ai_dst_addr);
        ret = -errno;
        goto err2;
    }
    return 0;
err2:
    if (rdma_destroy_id(*id))
        VRB_WARN_ERRNO(FI_LOG_FABRIC, "rdma_destroy_id");
err1:
    rdma_freeaddrinfo(*rai);
    return ret;
}

int mverbs_create_ep(struct mverbs_ep *ep, enum rdma_port_space ps,
                     struct rdma_cm_id **id)
{
    struct rdma_addrinfo *rai = NULL;
    int ret;

    ret = mverbs_get_rdma_rai(NULL, NULL, ep->info_attr.addr_format,
                              ep->info_attr.src_addr, ep->info_attr.src_addrlen,
                              ep->info_attr.dest_addr,
                              ep->info_attr.dest_addrlen, 0, &rai);
    if (ret) {
        return ret;
    }

    if (rdma_create_id(NULL, id, NULL, ps)) {
        ret = -errno;
        VRB_WARN_ERRNO(FI_LOG_FABRIC, "rdma_create_id");
        goto err1;
    }

    /* TODO convert this call to non-blocking (use event channel) as well:
     * This may likely be needed for better scaling when running large
     * MPI jobs.
     * Making this non-blocking would mean we can't create QP at EP enable
     * time. We need to wait for RDMA_CM_EVENT_ADDR_RESOLVED event before
     * creating the QP using rdma_create_qp. It would also require a SW
     * receive queue to store recvs posted by app after enabling the EP.
     */
    if (rdma_resolve_addr(*id, rai->ai_src_addr, rai->ai_dst_addr,
                          MVERBS_RESOLVE_TIMEOUT)) {
        ret = -errno;
        VRB_WARN_ERRNO(FI_LOG_EP_CTRL, "rdma_resolve_addr");
        ofi_straddr_log(&mverbs_prov, FI_LOG_WARN, FI_LOG_EP_CTRL, "src addr",
                        rai->ai_src_addr);
        ofi_straddr_log(&mverbs_prov, FI_LOG_WARN, FI_LOG_EP_CTRL, "dst addr",
                        rai->ai_dst_addr);
        goto err2;
    }
    rdma_freeaddrinfo(rai);
    return 0;

err2:
    rdma_destroy_id(*id);
err1:
    rdma_freeaddrinfo(rai);
    return ret;
}

static int mverbs_param_define(const char *param_name, const char *param_str,
                               enum fi_param_type type, void *param_default)
{
    char *param_help, param_default_str[256] = {0};
    char *begin_def_section = " (default: ", *end_def_section = ")";
    int ret = FI_SUCCESS;
    size_t len, param_default_sz = 0;
    size_t param_str_sz = strlen(param_str);
    size_t begin_def_section_sz = strlen(begin_def_section);
    size_t end_def_section_sz = strlen(end_def_section);

    if (param_default != NULL) {
        switch (type) {
            case FI_PARAM_STRING:
                if (*(char **)param_default != NULL) {
                    param_default_sz =
                        MIN(strlen(*(char **)param_default), 254);
                    strncpy(param_default_str, *(char **)param_default,
                            param_default_sz);
                    param_default_str[param_default_sz + 1] = '\0';
                }
                break;
            case FI_PARAM_INT:
            case FI_PARAM_BOOL:
                snprintf(param_default_str, 256, "%d", *((int *)param_default));
                param_default_sz = strlen(param_default_str);
                break;
            case FI_PARAM_SIZE_T:
                snprintf(param_default_str, 256, "%zu",
                         *((size_t *)param_default));
                param_default_sz = strlen(param_default_str);
                break;
            default:
                assert(0);
                ret = -FI_EINVAL;
                goto fn;
        }
    }

    len = param_str_sz + strlen(begin_def_section) + param_default_sz +
          end_def_section_sz + 1;
    param_help = calloc(1, len);
    if (!param_help) {
        assert(0);
        ret = -FI_ENOMEM;
        goto fn;
    }

    strncat(param_help, param_str, param_str_sz + 1);
    strncat(param_help, begin_def_section, begin_def_section_sz + 1);
    strncat(param_help, param_default_str, param_default_sz + 1);
    strncat(param_help, end_def_section, end_def_section_sz + 1);

    param_help[len - 1] = '\0';

    fi_param_define(&mverbs_prov, param_name, type, param_help);

    free(param_help);
fn:
    return ret;
}

#if ENABLE_DEBUG
static void mverbs_dbg_query_qp_attr(struct ibv_qp *qp)
{
    struct ibv_qp_init_attr attr = {0};
    struct ibv_qp_attr qp_attr = {0};
    int ret;

    ret = ibv_query_qp(qp, &qp_attr,
                       IBV_QP_TIMEOUT | IBV_QP_RETRY_CNT | IBV_QP_RNR_RETRY |
                           IBV_QP_MIN_RNR_TIMER,
                       &attr);
    if (ret) {
        VRB_WARN_ERRNO(FI_LOG_EP_CTRL, "ibv_query_qp");
        return;
    }

    FI_DBG(&mverbs_prov, FI_LOG_EP_CTRL,
           "QP attributes: "
           "min_rnr_timer"
           ": %" PRIu8 ", "
           "timeout"
           ": %" PRIu8 ", "
           "retry_cnt"
           ": %" PRIu8 ", "
           "rnr_retry"
           ": %" PRIu8 "\n",
           qp_attr.min_rnr_timer, qp_attr.timeout, qp_attr.retry_cnt,
           qp_attr.rnr_retry);
}
#else
static void mverbs_dbg_query_qp_attr(struct ibv_qp *qp) {}
#endif

void mverbs_set_rnr_timer(struct ibv_qp *qp)
{
    struct ibv_qp_attr attr = {0};
    int ret;

    if (mverbs_gl_data.min_rnr_timer > 31) {
        VRB_WARN(FI_LOG_EQ,
                 "min_rnr_timer value out of valid range; "
                 "using default value of %d\n",
                 MVERBS_DEFAULT_MIN_RNR_TIMER);
        attr.min_rnr_timer = MVERBS_DEFAULT_MIN_RNR_TIMER;
    } else {
        attr.min_rnr_timer = mverbs_gl_data.min_rnr_timer;
    }

    /* XRC initiator QP do not have responder logic */
    if (qp->qp_type == IBV_QPT_XRC_SEND)
        return;

    ret = ibv_modify_qp(qp, &attr, IBV_QP_MIN_RNR_TIMER);
    if (ret)
        VRB_WARN_ERRNO(FI_LOG_EP_CTRL, "ibv_modify_qp");

    mverbs_dbg_query_qp_attr(qp);
}

int mverbs_find_max_inline(struct ibv_pd *pd, struct ibv_context *context,
                           enum ibv_qp_type qp_type)
{
    struct ibv_qp_init_attr qp_attr;
    struct ibv_qp *qp = NULL;
    struct ibv_cq *cq;
    int max_inline = 2;
    int rst = 0;
    const char *dev_name = ibv_get_device_name(context->device);
    uint8_t i;

    for (i = 0; i < count_of(mverbs_dev_presets); i++) {
        if (!strncmp(dev_name, mverbs_dev_presets[i].dev_name_prefix,
                     strlen(mverbs_dev_presets[i].dev_name_prefix)))
            return mverbs_dev_presets[i].max_inline_data;
    }

    cq = ibv_create_cq(context, 1, NULL, NULL, 0);
    assert(cq);

    memset(&qp_attr, 0, sizeof(qp_attr));
    qp_attr.send_cq = cq;
    qp_attr.qp_type = qp_type;
    qp_attr.cap.max_send_wr = 1;
    qp_attr.cap.max_send_sge = 1;
    if (qp_type != IBV_QPT_XRC_SEND) {
        qp_attr.recv_cq = cq;
        qp_attr.cap.max_recv_wr = 1;
        qp_attr.cap.max_recv_sge = 1;
    }
    qp_attr.sq_sig_all = 1;

    do {
        if (qp)
            ibv_destroy_qp(qp);
        qp_attr.cap.max_inline_data = max_inline;
        qp = ibv_create_qp(pd, &qp_attr);
        if (qp) {
            /*
             * truescale returns max_inline_data 0
             */
            if (qp_attr.cap.max_inline_data == 0)
                break;

            /*
             * iWarp is able to create qp with unsupported
             * max_inline, lets take first returned value.
             */
            if (context->device->transport_type == IBV_TRANSPORT_IWARP) {
                max_inline = rst = qp_attr.cap.max_inline_data;
                break;
            }
            rst = max_inline;
        }
    } while (qp && (max_inline < INT_MAX / 2) && (max_inline *= 2));

    if (rst != 0) {
        int pos = rst, neg = max_inline;
        do {
            max_inline = pos + (neg - pos) / 2;
            if (qp)
                ibv_destroy_qp(qp);

            qp_attr.cap.max_inline_data = max_inline;
            qp = ibv_create_qp(pd, &qp_attr);
            if (qp)
                pos = max_inline;
            else
                neg = max_inline;

        } while (neg - pos > 2);

        rst = pos;
    }

    if (qp) {
        ibv_destroy_qp(qp);
    }

    if (cq) {
        ibv_destroy_cq(cq);
    }

    return rst;
}

static int mverbs_get_param_int(const char *param_name, const char *param_str,
                                int *param_default)
{
    int param, ret;

    ret =
        mverbs_param_define(param_name, param_str, FI_PARAM_INT, param_default);
    if (ret)
        return ret;

    if (!fi_param_get_int(&mverbs_prov, param_name, &param))
        *param_default = param;

    return 0;
}

static int mverbs_get_param_bool(const char *param_name, const char *param_str,
                                 int *param_default)
{
    int param, ret;

    ret = mverbs_param_define(param_name, param_str, FI_PARAM_BOOL,
                              param_default);
    if (ret)
        return ret;

    if (!fi_param_get_bool(&mverbs_prov, param_name, &param)) {
        *param_default = param;
        if ((*param_default != 1) && (*param_default != 0))
            return -FI_EINVAL;
    }

    return 0;
}

static int mverbs_get_param_str(const char *param_name, const char *param_str,
                                char **param_default)
{
    char *param;
    int ret;

    ret = mverbs_param_define(param_name, param_str, FI_PARAM_STRING,
                              param_default);
    if (ret)
        return ret;

    if (!fi_param_get_str(&mverbs_prov, param_name, &param))
        *param_default = param;

    return 0;
}

int mverbs_read_params(void)
{
    /* Common parameters */
    if (mverbs_get_param_int("tx_size", "Default maximum tx context size",
                             &mverbs_gl_data.def_tx_size) ||
        (mverbs_gl_data.def_tx_size < 0)) {
        VRB_WARN(FI_LOG_CORE, "Invalid value of tx_size\n");
        return -FI_EINVAL;
    }
    if (mverbs_get_param_int("rx_size", "Default maximum rx context size",
                             &mverbs_gl_data.def_rx_size) ||
        (mverbs_gl_data.def_rx_size < 0)) {
        VRB_WARN(FI_LOG_CORE, "Invalid value of rx_size\n");
        return -FI_EINVAL;
    }
    if (mverbs_get_param_int("tx_iov_limit", "Default maximum tx iov_limit",
                             &mverbs_gl_data.def_tx_iov_limit) ||
        (mverbs_gl_data.def_tx_iov_limit < 0)) {
        VRB_WARN(FI_LOG_CORE, "Invalid value of tx_iov_limit\n");
        return -FI_EINVAL;
    }
    if (mverbs_get_param_int("rx_iov_limit", "Default maximum rx iov_limit",
                             &mverbs_gl_data.def_rx_iov_limit) ||
        (mverbs_gl_data.def_rx_iov_limit < 0)) {
        VRB_WARN(FI_LOG_CORE, "Invalid value of rx_iov_limit\n");
        return -FI_EINVAL;
    }
    if (mverbs_get_param_int("inline_size",
                             "Default maximum inline size. "
                             "Actual inject size returned in fi_info may be "
                             "greater",
                             &mverbs_gl_data.def_inline_size) ||
        (mverbs_gl_data.def_inline_size < 0)) {
        VRB_WARN(FI_LOG_CORE, "Invalid value of inline_size\n");
        return -FI_EINVAL;
    }
    if (mverbs_get_param_int("min_rnr_timer",
                             "Set min_rnr_timer QP "
                             "attribute (0 - 31)",
                             &mverbs_gl_data.min_rnr_timer) ||
        ((mverbs_gl_data.min_rnr_timer < 0) ||
         (mverbs_gl_data.min_rnr_timer > 31))) {
        VRB_WARN(FI_LOG_CORE, "Invalid value of min_rnr_timer\n");
        return -FI_EINVAL;
    }

    if (mverbs_get_param_bool("use_odp",
                              "Enable on-demand paging memory "
                              "registrations, if supported.  This is "
                              "currently required to register DAX file system "
                              "mmapped memory.",
                              &mverbs_gl_data.use_odp)) {
        VRB_WARN(FI_LOG_CORE, "Invalid value of use_odp\n");
        return -FI_EINVAL;
    }

    if (mverbs_get_param_bool("prefer_xrc",
                              "Order XRC transport fi_infos "
                              "ahead of RC.  Default orders RC first.  This "
                              "setting must usually be combined with setting "
                              "FI_OFI_RXM_USE_SRX.  See fi_verbs.7 man page.",
                              &mverbs_gl_data.msg.prefer_xrc)) {
        VRB_WARN(FI_LOG_CORE, "Invalid value of prefer_xrc\n");
        return -FI_EINVAL;
    }

    if (mverbs_get_param_str("xrcd_filename",
                             "A file to "
                             "associate with the XRC domain.",
                             &mverbs_gl_data.msg.xrcd_filename)) {
        VRB_WARN(FI_LOG_CORE, "Invalid value of xrcd_filename\n");
        return -FI_EINVAL;
    }
    if (mverbs_get_param_int(
            "cqread_bunch_size",
            "The number of entries to "
            "be read from the verbs completion queue at a time",
            &mverbs_gl_data.cqread_bunch_size) ||
        (mverbs_gl_data.cqread_bunch_size <= 0)) {
        VRB_WARN(FI_LOG_CORE, "Invalid value of cqread_bunch_size\n");
        return -FI_EINVAL;
    }
    if (mverbs_get_param_int("gid_idx",
                             "Set which gid index to use "
                             "attribute (0 - 255)",
                             &mverbs_gl_data.gid_idx) ||
        (mverbs_gl_data.gid_idx < 0 || mverbs_gl_data.gid_idx > 255)) {
        VRB_WARN(FI_LOG_CORE, "Invalid value of gid index\n");
        return -FI_EINVAL;
    }

    if (mverbs_get_param_str("device_name",
                             "The prefix or the full name of the "
                             "verbs device to use",
                             &mverbs_gl_data.device_name)) {
        VRB_WARN(FI_LOG_CORE, "Invalid value of device_name\n");
        return -FI_EINVAL;
    }

    if (mverbs_gl_data.dmabuf_support) {
        if (mverbs_get_param_bool(
                "use_dmabuf",
                "Enable dmabuf based memory "
                "registrations, if supported. Yes by default.",
                (int *)&mverbs_gl_data.dmabuf_support)) {
            VRB_WARN(FI_LOG_CORE, "Invalid value of use_dmabuf\n");
            return -FI_EINVAL;
        }
    }
    VRB_INFO(FI_LOG_CORE, "dmabuf support is %s\n",
             mverbs_gl_data.dmabuf_support ? "enabled" : "disabled");

    /* MSG-specific parameter */
    if (mverbs_get_param_str("iface",
                             "The prefix or the full name of the "
                             "network interface associated with the verbs "
                             "device",
                             &mverbs_gl_data.iface)) {
        VRB_WARN(FI_LOG_CORE, "Invalid value of iface\n");
        return -FI_EINVAL;
    }

    /* DGRAM-specific parameters */
    if (getenv("OMPI_COMM_WORLD_RANK") || getenv("PMI_RANK"))
        mverbs_gl_data.dgram.use_name_server = 0;
    if (mverbs_get_param_bool("dgram_use_name_server",
                              "The option that "
                              "enables/disables OFI Name Server thread used "
                              "to resolve IP-addresses to provider specific "
                              "addresses. If MPI is used, the NS is disabled "
                              "by default.",
                              &mverbs_gl_data.dgram.use_name_server)) {
        VRB_WARN(FI_LOG_CORE, "Invalid dgram_use_name_server\n");
        return -FI_EINVAL;
    }
    if (mverbs_get_param_int("dgram_name_server_port",
                             "The port on which "
                             "the name server thread listens incoming "
                             "requests.",
                             &mverbs_gl_data.dgram.name_server_port) ||
        (mverbs_gl_data.dgram.name_server_port < 0 ||
         mverbs_gl_data.dgram.name_server_port > 65535)) {
        VRB_WARN(FI_LOG_CORE, "Invalid dgram_name_server_port\n");
        return -FI_EINVAL;
    }

    return FI_SUCCESS;
}

static void mverbs_devs_free(void)
{
    struct verbs_dev_info *dev;
    struct verbs_addr *addr;

    while (!dlist_empty(&verbs_devs)) {
        dlist_pop_front(&verbs_devs, struct verbs_dev_info, dev, entry);
        while (!dlist_empty(&dev->addrs)) {
            dlist_pop_front(&dev->addrs, struct verbs_addr, addr, entry);
            rdma_freeaddrinfo(addr->rai);
            free(addr);
        }
        free(dev->name);
        free(dev);
    }
}

static void mverbs_fini(void)
{
#if HAVE_MVERBS_DL
    ofi_monitors_cleanup();
    ofi_hmem_cleanup();
    ofi_mem_fini();
#endif
    ofi_mutex_destroy(&mverbs_init_mutex);
    fi_freeinfo((void *)mverbs_util_prov.info);
    mverbs_devs_free();
    mverbs_os_fini();
    mverbs_util_prov.info = NULL;
}

MVERBS_INI
{
#if HAVE_MVERBS_DL
    ofi_mem_init();
    ofi_hmem_init();
    ofi_monitors_init();
#endif
    ofi_mutex_init(&mverbs_init_mutex);

    if (mverbs_os_ini())
        return NULL;

    return &mverbs_prov;
}
