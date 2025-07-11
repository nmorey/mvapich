/*
 * Copyright (c) 2016, 2022 Intel Corporation, Inc.  All rights reserved.
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

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <ofi_util.h>
#include "ucr.h"
#include "prov/mverbs/src/mverbs_ofi.h"

static uint64_t ucr_passthru_cntr_read(struct fid_cntr *cntr_fid)
{
    struct ucr_cntr *cntr;

    cntr = container_of(cntr_fid, struct ucr_cntr, util_cntr.cntr_fid);
    cntr->util_cntr.progress(&cntr->util_cntr);
    return fi_cntr_read(cntr->msg_cntr);
}

static uint64_t ucr_passthru_cntr_readerr(struct fid_cntr *cntr_fid)
{
    struct ucr_cntr *cntr;

    cntr = container_of(cntr_fid, struct ucr_cntr, util_cntr.cntr_fid);
    cntr->util_cntr.progress(&cntr->util_cntr);
    return fi_cntr_readerr(cntr->msg_cntr);
}

static int ucr_passthru_cntr_add(struct fid_cntr *cntr_fid, uint64_t value)
{
    struct ucr_cntr *cntr;

    cntr = container_of(cntr_fid, struct ucr_cntr, util_cntr.cntr_fid);
    return fi_cntr_add(cntr->msg_cntr, value);
}

static int ucr_passthru_cntr_set(struct fid_cntr *cntr_fid, uint64_t value)
{
    struct ucr_cntr *cntr;

    cntr = container_of(cntr_fid, struct ucr_cntr, util_cntr.cntr_fid);
    return fi_cntr_set(cntr->msg_cntr, value);
}

static int ucr_passthru_cntr_wait(struct fid_cntr *cntr_fid, uint64_t threshold,
                                  int timeout)
{
    struct ucr_cntr *cntr;
    uint64_t endtime, errcnt;
    int ret, timeout_quantum;

    cntr = container_of(cntr_fid, struct ucr_cntr, util_cntr.cntr_fid);
    errcnt = fi_cntr_readerr(cntr->msg_cntr);
    endtime = ofi_timeout_time(timeout);

    do {
        cntr->util_cntr.progress(&cntr->util_cntr);

        if (errcnt != fi_cntr_readerr(cntr->msg_cntr))
            return -FI_EAVAIL;

        if (ofi_adjust_timeout(endtime, &timeout))
            return -FI_ETIMEDOUT;

        /* We need to ensure that CM events are progressed, so return
         * periodically to force progress on the EQ.
         */
        timeout_quantum = (timeout < 0 ? OFI_TIMEOUT_QUANTUM_MS :
                                         MIN(OFI_TIMEOUT_QUANTUM_MS, timeout));

        ret = fi_cntr_wait(cntr->msg_cntr, threshold, timeout_quantum);
    } while (ret == -FI_ETIMEDOUT &&
             (timeout < 0 || timeout_quantum < timeout));

    return ret;
}

static int ucr_passthru_cntr_adderr(struct fid_cntr *cntr_fid, uint64_t value)
{
    struct ucr_cntr *cntr;

    cntr = container_of(cntr_fid, struct ucr_cntr, util_cntr.cntr_fid);
    return fi_cntr_adderr(cntr->msg_cntr, value);
}

static int ucr_passthru_cntr_seterr(struct fid_cntr *cntr_fid, uint64_t value)
{
    struct ucr_cntr *cntr;

    cntr = container_of(cntr_fid, struct ucr_cntr, util_cntr.cntr_fid);
    return fi_cntr_seterr(cntr->msg_cntr, value);
}

static struct fi_ops_cntr ucr_passthru_cntr_ops = {
    .size = sizeof(struct fi_ops_cntr),
    .read = ucr_passthru_cntr_read,
    .readerr = ucr_passthru_cntr_readerr,
    .add = ucr_passthru_cntr_add,
    .set = ucr_passthru_cntr_set,
    .wait = ucr_passthru_cntr_wait,
    .adderr = ucr_passthru_cntr_adderr,
    .seterr = ucr_passthru_cntr_seterr,
};

static int ucr_passthru_cntr_close(struct fid *fid)
{
    struct ucr_cntr *cntr;
    int ret;

    cntr = container_of(fid, struct ucr_cntr, util_cntr.cntr_fid.fid);

    if (cntr->msg_cntr) {
        ret = fi_close(&cntr->msg_cntr->fid);
        if (ret)
            return ret;
    }

    cntr->msg_cntr = NULL;
    ret = ofi_cntr_cleanup(&cntr->util_cntr);
    if (ret)
        return ret;

    free(cntr);
    return 0;
}

static struct fi_ops ucr_passthru_cntr_fi_ops = {
    .size = sizeof(struct fi_ops),
    .close = ucr_passthru_cntr_close,
    .bind = fi_no_bind,
    .control = fi_no_control,
    .ops_open = fi_no_ops_open,
};

static struct fi_ops ucr_peer_av_fi_ops = {
    .size = sizeof(struct fi_ops),
    .close = fi_no_close,
    .bind = fi_no_bind,
    .control = fi_no_control,
    .ops_open = fi_no_ops_open,
};

int ucr_peer_av_query(struct fid_peer_av *av, struct fi_av_attr *attr)
{
    struct ucr_av *ucr_av = container_of(av, struct ucr_av, peer_av);

    memset(attr, 0, sizeof(*attr));

    /* Only count is useful at this moment */
    attr->count = ofi_av_size(&ucr_av->util_av);

    return 0;
}

fi_addr_t ucr_peer_av_ep_addr(struct fid_peer_av *av, struct fid_ep *ep)
{
    struct ucr_av *ucr_av = container_of(av, struct ucr_av, peer_av);
    size_t addrlen;
    char *addr;
    fi_addr_t addr_ret;
    int ret;

    addrlen = 0;
    ret = fi_getname(&ep->fid, NULL, &addrlen);
    if (ret != FI_SUCCESS && addrlen == 0)
        goto err1;

    addr = calloc(1, addrlen);
    if (!addr)
        goto err1;

    ret = fi_getname(&ep->fid, addr, &addrlen);
    if (ret)
        goto err2;

    addr_ret = ofi_av_lookup_fi_addr(&ucr_av->util_av, addr);
    free(addr);
    return addr_ret;

err2:
    free(addr);
err1:
    return FI_ADDR_NOTAVAIL;
}

static struct fi_ops_av_owner ucr_av_owner_ops = {
    .size = sizeof(struct fi_ops_av_owner),
    .query = ucr_peer_av_query,
    .ep_addr = ucr_peer_av_ep_addr,
};

static int ucr_av_open(struct fid_domain *domain_fid, struct fi_av_attr *attr,
                       struct fid_av **fid_av, void *context)
{
    struct ucr_domain *ucr_domain;
    struct ucr_av *ucr_av;
    struct fid_av *fid_av_new;
    struct fi_peer_av_context peer_context;
    struct fi_av_attr peer_attr = {
        .flags = FI_PEER,
    };
    int ret;

    ret = ucr_util_av_open(
        domain_fid, attr, &fid_av_new, context, sizeof(struct ucr_conn),
        ofi_av_remove_cleanup ? ucr_av_remove_handler : NULL);
    if (ret)
        return ret;

    ucr_av = container_of(fid_av_new, struct ucr_av, util_av.av_fid);
    ucr_domain =
        container_of(domain_fid, struct ucr_domain, util_domain.domain_fid);

    ucr_av->peer_av.fid.fclass = FI_CLASS_PEER_AV;
    ucr_av->peer_av.fid.ops = &ucr_peer_av_fi_ops;
    ucr_av->peer_av.owner_ops = &ucr_av_owner_ops;
    peer_context.size = sizeof(peer_context);
    peer_context.av = &ucr_av->peer_av;

    if (ucr_domain->util_coll_domain) {
        ret = fi_av_open(ucr_domain->util_coll_domain, &peer_attr,
                         &ucr_av->util_coll_av, &peer_context);
        if (ret)
            goto err1;
    }
    if (ucr_domain->offload_coll_domain) {
        ret = fi_av_open(ucr_domain->offload_coll_domain, &peer_attr,
                         &ucr_av->offload_coll_av, &peer_context);
        if (ret)
            goto err1;
    }
    *fid_av = fid_av_new;
    return 0;

err1:
    fi_close(&fid_av_new->fid);
    return ret;
}

static int ucr_cntr_open(struct fid_domain *fid_domain,
                         struct fi_cntr_attr *attr, struct fid_cntr **cntr_fid,
                         void *context)
{
    struct ucr_domain *domain;
    struct ucr_cntr *cntr;
    int ret;

    domain =
        container_of(fid_domain, struct ucr_domain, util_domain.domain_fid.fid);
    cntr = calloc(1, sizeof(*cntr));
    if (!cntr)
        return -FI_ENOMEM;

    ret = ofi_cntr_init(&ucr_prov, fid_domain, attr, &cntr->util_cntr,
                        &ofi_cntr_progress, context);
    if (ret)
        goto free;

    if (domain->passthru) {
        ret = fi_cntr_open(domain->msg_domain, attr, &cntr->msg_cntr, cntr);
        if (ret) {
            UCR_WARN_ERR(FI_LOG_CNTR, "fi_cntr_open", ret);
            goto cleanup;
        }

        cntr->util_cntr.cntr_fid.fid.ops = &ucr_passthru_cntr_fi_ops;
        cntr->util_cntr.cntr_fid.ops = &ucr_passthru_cntr_ops;
    }

    *cntr_fid = &cntr->util_cntr.cntr_fid;
    return FI_SUCCESS;

cleanup:
    ofi_cntr_cleanup(&cntr->util_cntr);
free:
    free(cntr);
    return ret;
}

static int ucr_query_collective(struct fid_domain *domain,
                                enum fi_collective_op coll,
                                struct fi_collective_attr *attr, uint64_t flags)
{
    struct ucr_domain *ucr_domain;
    int ret;

    ucr_domain =
        container_of(domain, struct ucr_domain, util_domain.domain_fid);

    if (!ucr_domain->util_coll_domain)
        return -FI_ENOSYS;

    if (ucr_domain->offload_coll_domain)
        ret = fi_query_collective(ucr_domain->offload_coll_domain, coll, attr,
                                  flags);
    else
        ret = -FI_ENOSYS;

    if (ret == FI_SUCCESS || flags & OFI_OFFLOAD_PROV_ONLY)
        return ret;

    return fi_query_collective(ucr_domain->util_coll_domain, coll, attr, flags);
}

static struct fi_ops_domain ucr_domain_ops = {
    .size = sizeof(struct fi_ops_domain),
    .av_open = ucr_av_open,
    .cq_open = ucr_cq_open,
    .endpoint = ucr_endpoint,
    .scalable_ep = fi_no_scalable_ep,
    .cntr_open = ucr_cntr_open,
    .poll_open = fi_poll_create,
    .stx_ctx = fi_no_stx_context,
    .srx_ctx = fi_no_srx_context,
    .query_atomic = ucr_ep_query_atomic,
    .query_collective = ucr_query_collective,
};

static void ucr_mr_remove_map_entry(struct ucr_mr *mr)
{
    ofi_genlock_lock(&mr->domain->util_domain.lock);
    (void)ofi_mr_map_remove(&mr->domain->util_domain.mr_map, mr->mr_fid.key);
    ofi_genlock_unlock(&mr->domain->util_domain.lock);
}

static int ucr_mr_add_map_entry(struct util_domain *domain,
                                struct fi_mr_attr *msg_attr,
                                struct ucr_mr *ucr_mr, uint64_t flags)
{
    uint64_t temp_key;
    int ret;

    msg_attr->requested_key = ucr_mr->mr_fid.key;

    ofi_genlock_lock(&domain->lock);
    ret =
        ofi_mr_map_insert(&domain->mr_map, msg_attr, &temp_key, ucr_mr, flags);
    if (OFI_UNLIKELY(ret)) {
        FI_WARN(&ucr_prov, FI_LOG_DOMAIN,
                "MR map insert for atomic verification failed %d\n", ret);
    } else {
        assert(ucr_mr->mr_fid.key == temp_key);
    }
    ofi_genlock_unlock(&domain->lock);

    return ret;
}

struct ucr_mr *ucr_mr_get_map_entry(struct ucr_domain *domain, uint64_t key)
{
    struct ucr_mr *mr;

    ofi_genlock_lock(&domain->util_domain.lock);
    mr = ofi_mr_map_get(&domain->util_domain.mr_map, key);
    ofi_genlock_unlock(&domain->util_domain.lock);

    return mr;
}

static int ucr_domain_close(fid_t fid)
{
    struct ucr_domain *ucr_domain;
    int ret;

    ucr_domain =
        container_of(fid, struct ucr_domain, util_domain.domain_fid.fid);

    ofi_mutex_destroy(&ucr_domain->amo_bufpool_lock);
    ofi_bufpool_destroy(ucr_domain->amo_bufpool);

    ret = fi_close(&ucr_domain->msg_domain->fid);
    if (ret)
        return ret;

    if (ucr_domain->offload_coll_domain) {
        ret = fi_close(&ucr_domain->offload_coll_domain->fid);
        if (ret)
            return ret;
        ucr_domain->offload_coll_domain = NULL;
    }

    if (ucr_domain->util_coll_domain) {
        ret = fi_close(&ucr_domain->util_coll_domain->fid);
        if (ret)
            return ret;
        ucr_domain->util_coll_domain = NULL;
    }

    ret = ofi_domain_close(&ucr_domain->util_domain);
    if (ret)
        return ret;

    free(ucr_domain);
    return 0;
}

static struct fi_ops ucr_domain_fi_ops = {
    .size = sizeof(struct fi_ops),
    .close = ucr_domain_close,
    .bind = fi_no_bind,
    .control = fi_no_control,
    .ops_open = fi_no_ops_open,
};

static int ucr_mr_close(fid_t fid)
{
    struct ucr_mr *ucr_mr;
    int ret;

    ucr_mr = container_of(fid, struct ucr_mr, mr_fid.fid);

    if (ucr_mr->domain->util_domain.info_domain_caps & FI_ATOMIC)
        ucr_mr_remove_map_entry(ucr_mr);

    if (ucr_mr->hmem_handle) {
        ofi_hmem_dev_unregister(ucr_mr->iface, (uint64_t)ucr_mr->hmem_handle);
    }

    ret = fi_close(&ucr_mr->msg_mr->fid);
    if (ret)
        FI_WARN(&ucr_prov, FI_LOG_DOMAIN, "Unable to close MSG MR\n");

    ofi_atomic_dec32(&ucr_mr->domain->util_domain.ref);
    free(ucr_mr);
    return ret;
}

static struct fi_ops ucr_mr_ops = {
    .size = sizeof(struct fi_ops),
    .close = ucr_mr_close,
    .bind = fi_no_bind,
    .control = fi_no_control,
    .ops_open = fi_no_ops_open,
};

int ucr_msg_mr_reg_internal(struct ucr_domain *ucr_domain, const void *buf,
                            size_t len, uint64_t acs, uint64_t flags,
                            struct fid_mr **mr)
{
    int ret, tries = 0;

    /* If we can't get a key within 1024 tries, give up */
    do {
        ret =
            fi_mr_reg(ucr_domain->msg_domain, buf, len, acs, 0,
                      ucr_domain->mr_key++ | FI_PROV_SPECIFIC, flags, mr, NULL);
    } while (ret == -FI_ENOKEY && tries++ < 1024);

    return ret;
}

void ucr_msg_mr_closev(struct fid_mr **mr, size_t count)
{
    int ret;
    size_t i;

    for (i = 0; i < count; i++) {
        if (mr[i]) {
            ret = fi_close(&mr[i]->fid);
            if (ret)
                FI_WARN(&ucr_prov, FI_LOG_EP_DATA,
                        "Unable to close msg mr: %zu\n", i);
            mr[i] = NULL;
        }
    }
}

int ucr_msg_mr_regv(struct ucr_ep *ucr_ep, const struct iovec *iov,
                    size_t count, size_t reg_limit, uint64_t access,
                    struct fid_mr **mr)
{
    struct ucr_domain *ucr_domain;
    size_t i;
    int ret;

    ucr_domain =
        container_of(ucr_ep->util_ep.domain, struct ucr_domain, util_domain);

    for (i = 0; i < count && reg_limit; i++) {
        size_t len = MIN(iov[i].iov_len, reg_limit);
        ret = ucr_msg_mr_reg_internal(ucr_domain, iov[i].iov_base, len, access,
                                      0, &mr[i]);
        if (ret)
            goto err;
        reg_limit -= len;
    }
    return 0;
err:
    ucr_msg_mr_closev(mr, i);
    return ret;
}

/* Large send/recv transfers use RMA rendezvous protocol */
static uint64_t ucr_mr_get_msg_access(struct ucr_domain *ucr_domain,
                                      uint64_t access)
{
    if (access & FI_SEND) {
        access |= ucr_use_write_rndv ? FI_WRITE : FI_REMOTE_READ;
    }

    if (access & FI_RECV) {
        access |= ucr_use_write_rndv ? FI_REMOTE_WRITE : FI_READ;
    }

    return access;
}

static void ucr_mr_init(struct ucr_mr *ucr_mr, struct ucr_domain *domain,
                        void *context)
{
    ucr_mr->mr_fid.fid.fclass = FI_CLASS_MR;
    ucr_mr->mr_fid.fid.context = context;
    ucr_mr->mr_fid.fid.ops = &ucr_mr_ops;
    ucr_mr->mr_fid.mem_desc = ucr_mr;
    ucr_mr->mr_fid.key = fi_mr_key(ucr_mr->msg_mr);
    ucr_mr->domain = domain;
    ucr_mr->hmem_flags = 0x0;
    ucr_mr->hmem_handle = NULL;
    ofi_atomic_inc32(&domain->util_domain.ref);
}

static int ucr_mr_regattr(struct fid *fid, const struct fi_mr_attr *attr,
                          uint64_t flags, struct fid_mr **mr)
{
    struct ucr_domain *ucr_domain;
    struct fi_mr_attr msg_attr = *attr;
    struct ucr_mr *ucr_mr;
    int ret, gdrerr;

    ucr_domain =
        container_of(fid, struct ucr_domain, util_domain.domain_fid.fid);

    if (!ofi_hmem_is_initialized(attr->iface)) {
        FI_WARN(&ucr_prov, FI_LOG_MR,
                "Cannot register memory for uninitialized iface\n");
        return -FI_ENOSYS;
    }

    ucr_mr = calloc(1, sizeof(*ucr_mr));
    if (!ucr_mr)
        return -FI_ENOMEM;

    ofi_mr_update_attr(ucr_domain->util_domain.fabric->fabric_fid.api_version,
                       ucr_domain->util_domain.info_domain_caps, attr,
                       &msg_attr, flags);

    if ((flags & FI_HMEM_HOST_ALLOC) && (attr->iface == FI_HMEM_ZE))
        msg_attr.device.ze = -1;

    msg_attr.access = ucr_mr_get_msg_access(ucr_domain, attr->access);

    ret = fi_mr_regattr(ucr_domain->msg_domain, &msg_attr, flags,
                        &ucr_mr->msg_mr);
    if (ret) {
        FI_WARN(&ucr_prov, FI_LOG_DOMAIN, "Unable to register MSG MR\n");
        goto err;
    }
    ucr_mr_init(ucr_mr, ucr_domain, attr->context);
    ofi_mutex_init(&ucr_mr->amo_lock);
    ucr_mr->iface = msg_attr.iface;
    ucr_mr->device = msg_attr.device.reserved;
    *mr = &ucr_mr->mr_fid;

    /*
     * Check if the GDRCopy handle in the memory descriptor is already cached.
     * If it is not cached, register the device memory and cache the handle;
     * otherwise, use the cached GDRCopy handle.
     */
    if (((struct mverbs_mem_desc *)ucr_mr->msg_mr->mem_desc)
            ->cache_gdrcopy_handle == NULL) {
        gdrerr = ofi_hmem_dev_register(ucr_mr->iface, attr->mr_iov->iov_base,
                                       attr->mr_iov->iov_len,
                                       (uint64_t *)&ucr_mr->hmem_handle);
        if (gdrerr) {
            ucr_mr->hmem_flags = 0x0;
            ucr_mr->hmem_handle = NULL;
        } else {
            ucr_mr->hmem_flags = OFI_HMEM_DATA_DEV_REG_HANDLE;
            ((struct mverbs_mem_desc *)ucr_mr->msg_mr->mem_desc)
                ->cache_gdrcopy_handle =
                (struct gdrcopy_handle *)ucr_mr->hmem_handle;
        }
    } else {
        ucr_mr->hmem_flags = OFI_HMEM_DATA_DEV_REG_HANDLE;
        cuda_gdrcopy_get_cache_gdrhandle(
            &ucr_mr->hmem_handle,
            (uint64_t *)(((struct mverbs_mem_desc *)ucr_mr->msg_mr->mem_desc)
                             ->cache_gdrcopy_handle));
    }

    if (ucr_domain->util_domain.info_domain_caps & FI_ATOMIC) {
        ret = ucr_mr_add_map_entry(&ucr_domain->util_domain, &msg_attr, ucr_mr,
                                   flags);
        if (ret)
            goto map_err;
    }

    return 0;

map_err:
    fi_close(&ucr_mr->mr_fid.fid);
    return ret;
err:
    free(ucr_mr);
    return ret;
}

static int ucr_mr_regv(struct fid *fid, const struct iovec *iov, size_t count,
                       uint64_t access, uint64_t offset, uint64_t requested_key,
                       uint64_t flags, struct fid_mr **mr, void *context)
{
    struct ucr_domain *ucr_domain;
    struct ucr_mr *ucr_mr;
    int ret;
    struct fi_mr_attr msg_attr = {
        .mr_iov = iov,
        .iov_count = count,
        .access = access,
        .offset = offset,
        .requested_key = requested_key,
        .context = context,
    };

    ucr_domain =
        container_of(fid, struct ucr_domain, util_domain.domain_fid.fid);

    ucr_mr = calloc(1, sizeof(*ucr_mr));
    if (!ucr_mr)
        return -FI_ENOMEM;

    access = ucr_mr_get_msg_access(ucr_domain, access);

    ret = fi_mr_regv(ucr_domain->msg_domain, iov, count, access, offset,
                     requested_key, flags, &ucr_mr->msg_mr, context);
    if (ret) {
        FI_WARN(&ucr_prov, FI_LOG_DOMAIN, "Unable to register MSG MR\n");
        goto err;
    }
    ucr_mr_init(ucr_mr, ucr_domain, context);
    *mr = &ucr_mr->mr_fid;

    if (ucr_domain->util_domain.info_domain_caps & FI_ATOMIC) {
        ret = ucr_mr_add_map_entry(&ucr_domain->util_domain, &msg_attr, ucr_mr,
                                   flags);
        if (ret)
            goto map_err;
    }

    return 0;
map_err:
    fi_close(&ucr_mr->mr_fid.fid);
    return ret;
err:
    free(ucr_mr);
    return ret;
}

static int ucr_mr_reg(struct fid *fid, const void *buf, size_t len,
                      uint64_t access, uint64_t offset, uint64_t requested_key,
                      uint64_t flags, struct fid_mr **mr, void *context)
{
    struct iovec iov;

    iov.iov_base = (void *)buf;
    iov.iov_len = len;
    return ucr_mr_regv(fid, &iov, 1, access, offset, requested_key, flags, mr,
                       context);
}

static struct fi_ops_mr ucr_domain_mr_ops = {
    .size = sizeof(struct fi_ops_mr),
    .reg = ucr_mr_reg,
    .regv = ucr_mr_regv,
    .regattr = ucr_mr_regattr,
};

static int ucr_mr_regattr_thru(struct fid *fid, const struct fi_mr_attr *attr,
                               uint64_t flags, struct fid_mr **mr)
{
    struct ucr_domain *domain;

    domain = container_of(fid, struct ucr_domain, util_domain.domain_fid.fid);
    return fi_mr_regattr(domain->msg_domain, attr, flags, mr);
}

static int ucr_mr_regv_thru(struct fid *fid, const struct iovec *iov,
                            size_t count, uint64_t access, uint64_t offset,
                            uint64_t requested_key, uint64_t flags,
                            struct fid_mr **mr, void *context)
{
    struct ucr_domain *domain;

    domain = container_of(fid, struct ucr_domain, util_domain.domain_fid.fid);
    return fi_mr_regv(domain->msg_domain, iov, count, access, offset,
                      requested_key, flags, mr, context);
}

static int ucr_mr_reg_thru(struct fid *fid, const void *buf, size_t len,
                           uint64_t access, uint64_t offset,
                           uint64_t requested_key, uint64_t flags,
                           struct fid_mr **mr, void *context)
{
    struct ucr_domain *domain;

    domain = container_of(fid, struct ucr_domain, util_domain.domain_fid.fid);
    return fi_mr_reg(domain->msg_domain, buf, len, access, offset,
                     requested_key, flags, mr, context);
}

static struct fi_ops_mr ucr_domain_mr_thru_ops = {
    .size = sizeof(struct fi_ops_mr),
    .reg = ucr_mr_reg_thru,
    .regv = ucr_mr_regv_thru,
    .regattr = ucr_mr_regattr_thru,
};

static ssize_t ucr_send_credits(struct fid_ep *ep, uint64_t credits)
{
    struct ucr_conn *ucr_conn = ep->fid.context;
    struct ucr_ep *ucr_ep = ucr_conn->ep;
    struct ucr_deferred_tx_entry *def_tx_entry;
    struct ucr_tx_buf *tx_buf;
    struct iovec iov;
    struct fi_msg msg;
    ssize_t ret;

    tx_buf = ofi_buf_alloc(ucr_ep->tx_pool);
    if (!tx_buf) {
        FI_WARN(&ucr_prov, FI_LOG_EP_DATA,
                "Ran out of buffers from TX credit buffer pool.\n");
        return -FI_ENOMEM;
    }

    tx_buf->hdr.state = UCR_CREDIT_TX;
    ucr_ep_format_tx_buf_pkt(ucr_conn, 0, ucr_ctrl_credit, 0, 0, FI_SEND,
                             &tx_buf->pkt);
    tx_buf->pkt.ctrl_hdr.type = ucr_ctrl_credit;
    tx_buf->pkt.ctrl_hdr.msg_id = ofi_buf_index(tx_buf);
    tx_buf->pkt.ctrl_hdr.ctrl_data = credits;

    if (ucr_conn->state != UCR_CM_CONNECTED)
        goto defer;

    iov.iov_base = &tx_buf->pkt;
    iov.iov_len = sizeof(struct ucr_pkt);
    msg.msg_iov = &iov;
    msg.iov_count = 1;
    msg.context = tx_buf;
    msg.desc = &tx_buf->hdr.desc;

    ret = fi_sendmsg(ep, &msg, FI_PRIORITY);
    if (!ret)
        return FI_SUCCESS;

defer:
    def_tx_entry = ucr_ep_alloc_deferred_tx_entry(ucr_ep, ucr_conn,
                                                  UCR_DEFERRED_TX_CREDIT_SEND);
    if (!def_tx_entry) {
        FI_WARN(&ucr_prov, FI_LOG_CQ,
                "unable to allocate TX entry for deferred CREDIT mxg\n");
        ofi_buf_free(tx_buf);
        return -FI_ENOMEM;
    }

    def_tx_entry->credit_msg.tx_buf = tx_buf;
    ucr_queue_deferred_tx(def_tx_entry, OFI_LIST_HEAD);
    return FI_SUCCESS;
}

static void ucr_no_add_credits(struct fid_ep *ep_fid, uint64_t credits) {}

static void ucr_no_credit_handler(struct fid_domain *domain_fid,
                                  ssize_t (*credit_handler)(struct fid_ep *ep,
                                                            uint64_t credits))
{
}

static int ucr_no_enable_flow_ctrl(struct fid_ep *ep_fid, uint64_t threshold)
{
    return -FI_ENOSYS;
}

static bool ucr_no_flow_ctrl_available(struct fid_ep *ep_fid) { return false; }

struct ofi_ops_flow_ctrl ucr_no_ops_flow_ctrl = {
    .size = sizeof(struct ofi_ops_flow_ctrl),
    .add_credits = ucr_no_add_credits,
    .enable = ucr_no_enable_flow_ctrl,
    .set_send_handler = ucr_no_credit_handler,
    .available = ucr_no_flow_ctrl_available,
};

static int ucr_config_flow_ctrl(struct ucr_domain *domain)
{
    struct ofi_ops_flow_ctrl *flow_ctrl_ops;
    int ret;

    ret = fi_open_ops(&domain->msg_domain->fid, OFI_OPS_FLOW_CTRL, 0,
                      (void **)&flow_ctrl_ops, NULL);
    if (ret) {
        if (ret == -FI_ENOSYS) {
            domain->flow_ctrl_ops = &ucr_no_ops_flow_ctrl;
            return 0;
        }
        return ret;
    }

    assert(flow_ctrl_ops);
    domain->flow_ctrl_ops = flow_ctrl_ops;
    domain->flow_ctrl_ops->set_send_handler(domain->msg_domain,
                                            ucr_send_credits);
    return 0;
}

static uint64_t ucr_get_coll_caps(struct fid_domain *domain)
{
    struct fi_collective_attr attr;
    uint64_t mask = 0;

    attr.datatype = FI_INT8;
    attr.datatype_attr.count = 1;
    attr.datatype_attr.size = sizeof(int8_t);
    attr.mode = 0;
    for (int i = FI_BARRIER; i <= FI_GATHER; i++) {
        attr.op = (i == FI_BARRIER) ? FI_NOOP : FI_MIN;
        if (fi_query_collective(domain, i, &attr, 0) == FI_SUCCESS)
            mask |= BIT(i);
    }
    return mask;
}

int ucr_domain_open(struct fid_fabric *fabric, struct fi_info *info,
                    struct fid_domain **domain, void *context)
{
    struct ucr_domain *ucr_domain;
    struct ucr_fabric *ucr_fabric;
    struct fi_info *msg_info, *base_info;
    struct fi_peer_domain_context peer_context;
    int ret;

    ucr_domain = calloc(1, sizeof(*ucr_domain));
    if (!ucr_domain)
        return -FI_ENOMEM;

    ucr_fabric =
        container_of(fabric, struct ucr_fabric, util_fabric.fabric_fid);

    base_info = ucr_passthru_info(info) ? &ucr_thru_info : NULL;
    ret = ofi_get_core_info(fabric->api_version, NULL, NULL, 0, &ucr_util_prov,
                            info, base_info, ucr_info_to_core, &msg_info);
    if (ret)
        goto err1;

    ret = fi_domain(ucr_fabric->msg_fabric, msg_info, &ucr_domain->msg_domain,
                    context);
    if (ret)
        goto err2;

    ret = ofi_domain_init(fabric, info, &ucr_domain->util_domain, context,
                          OFI_LOCK_MUTEX);
    if (ret) {
        goto err3;
    }

    if (info->caps & FI_COLLECTIVE) {
        if (!ucr_fabric->util_coll_fabric) {
            FI_WARN(&ucr_prov, FI_LOG_DOMAIN,
                    "Util collective provider unavailable\n");
            goto err4;
        }

        peer_context.size = sizeof(peer_context);
        peer_context.domain = &ucr_domain->util_domain.domain_fid;

        ret =
            fi_domain2(ucr_fabric->util_coll_fabric, ucr_fabric->util_coll_info,
                       &ucr_domain->util_coll_domain, FI_PEER, &peer_context);
        if (ret)
            goto err4;

        if (ucr_fabric->offload_coll_fabric) {
            ret = fi_domain2(
                ucr_fabric->offload_coll_fabric, ucr_fabric->offload_coll_info,
                &ucr_domain->offload_coll_domain, FI_PEER, &peer_context);
            if (ret)
                goto err5;

            ucr_domain->offload_coll_mask |=
                ucr_get_coll_caps(ucr_domain->offload_coll_domain);
        }
    }

    /* We turn off the mr map mode bit FI_MR_PROV_KEY.  We always use the
     * key returned by the MSG provider.  That key may be generated by the
     * MSG provider, or will be provided as input by the ucr provider.
     */
    ucr_domain->util_domain.mr_map.mode &= ~FI_MR_PROV_KEY;

    ucr_domain->max_atomic_size = ucr_ep_max_atomic_size(info);
    ucr_domain->rx_post_size = ucr_packet_size;

    *domain = &ucr_domain->util_domain.domain_fid;
    (*domain)->fid.ops = &ucr_domain_fi_ops;
    (*domain)->ops = &ucr_domain_ops;

    ret = ofi_bufpool_create(&ucr_domain->amo_bufpool,
                             ucr_domain->max_atomic_size, 64, 0, 0, 0);
    if (ret)
        goto err5;

    ofi_mutex_init(&ucr_domain->amo_bufpool_lock);

    ucr_domain->passthru = ucr_passthru_info(info);
    if (ucr_domain->passthru)
        (*domain)->mr = &ucr_domain_mr_thru_ops;
    else
        (*domain)->mr = &ucr_domain_mr_ops;

    ret = ucr_config_flow_ctrl(ucr_domain);
    if (ret)
        goto err6;

    fi_freeinfo(msg_info);
    return 0;

err6:
    ofi_mutex_destroy(&ucr_domain->amo_bufpool_lock);
    ofi_bufpool_destroy(ucr_domain->amo_bufpool);
err5:
    if (ucr_domain->offload_coll_domain)
        fi_close(&ucr_domain->offload_coll_domain->fid);
    if (ucr_domain->util_coll_domain)
        fi_close(&ucr_domain->util_coll_domain->fid);
err4:
    (void)ofi_domain_close(&ucr_domain->util_domain);
err3:
    fi_close(&ucr_domain->msg_domain->fid);
err2:
    fi_freeinfo(msg_info);
err1:
    free(ucr_domain);
    return ret;
}
