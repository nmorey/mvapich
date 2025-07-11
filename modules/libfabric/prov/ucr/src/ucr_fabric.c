/*
 * Copyright (c) 2016, 2022 Intel Corporation, Inc.  All rights reserved.
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

#include <ofi_util.h>

#include "ucr.h"

static struct fi_ops_fabric ucr_fabric_ops = {.size =
                                                  sizeof(struct fi_ops_fabric),
                                              .domain = ucr_domain_open,
                                              .passive_ep = fi_no_passive_ep,
                                              .eq_open = ucr_eq_open,
                                              .wait_open = ofi_wait_fd_open,
                                              .trywait = ofi_trywait};

static int ucr_fabric_close(fid_t fid)
{
    struct ucr_fabric *ucr_fabric;
    int ret;

    ucr_fabric =
        container_of(fid, struct ucr_fabric, util_fabric.fabric_fid.fid);

    if (ucr_fabric->offload_coll_fabric)
        fi_close(&ucr_fabric->offload_coll_fabric->fid);

    if (ucr_fabric->util_coll_fabric)
        fi_close(&ucr_fabric->util_coll_fabric->fid);

    fi_freeinfo(ucr_fabric->offload_coll_info);
    fi_freeinfo(ucr_fabric->util_coll_info);

    ret = fi_close(&ucr_fabric->msg_fabric->fid);
    if (ret)
        return ret;

    ret = ofi_fabric_close(&ucr_fabric->util_fabric);
    if (ret)
        return ret;

    free(ucr_fabric);
    return 0;
}

static struct fi_ops ucr_fabric_fi_ops = {
    .size = sizeof(struct fi_ops),
    .close = ucr_fabric_close,
    .bind = fi_no_bind,
    .control = fi_no_control,
    .ops_open = fi_no_ops_open,
};

static int ucr_fabric_init_coll(const char *name, struct fi_info **coll_info,
                                struct fid_fabric **coll_fabric)
{
    struct fi_info *hints, *info;
    struct fid_fabric *fabric;
    int ret;

    hints = fi_allocinfo();
    if (!hints)
        return -FI_ENOMEM;

    hints->fabric_attr->prov_name = strdup(name);
    if (!hints->fabric_attr->prov_name) {
        fi_freeinfo(hints);
        return -FI_ENOMEM;
    }

    hints->mode = FI_PEER_TRANSFER;
    ret = fi_getinfo(OFI_VERSION_LATEST, NULL, NULL, OFI_OFFLOAD_PROV_ONLY,
                     hints, &info);
    fi_freeinfo(hints);

    if (ret)
        return ret;

    ret = fi_fabric(info->fabric_attr, &fabric, NULL);
    if (ret)
        goto err1;

    *coll_info = info;
    *coll_fabric = fabric;
    return FI_SUCCESS;

err1:
    fi_freeinfo(info);
    return ret;
}

static int ucr_fabric_init_util_coll(struct ucr_fabric *fabric)
{
    return ucr_fabric_init_coll(OFI_OFFLOAD_PREFIX "coll",
                                &fabric->util_coll_info,
                                &fabric->util_coll_fabric);
}

static int ucr_fabric_init_offload_coll(struct ucr_fabric *fabric)
{
    if ((ofi_offload_coll_prov_name == NULL) ||
        (!strlen(ofi_offload_coll_prov_name)))
        return -FI_ENODATA;

    return ucr_fabric_init_coll(ofi_offload_coll_prov_name,
                                &fabric->offload_coll_info,
                                &fabric->offload_coll_fabric);
}

int ucr_fabric(struct fi_fabric_attr *attr, struct fid_fabric **fabric,
               void *context)
{
    struct ucr_fabric *ucr_fabric;
    struct fi_info *msg_info;
    int ret;

    ucr_fabric = calloc(1, sizeof(*ucr_fabric));
    if (!ucr_fabric)
        return -FI_ENOMEM;

    ret = ofi_fabric_init(&ucr_prov, &ucr_fabric_attr, attr,
                          &ucr_fabric->util_fabric, context);
    if (ret)
        goto err1;

    ret = ofi_get_core_info_fabric(&ucr_prov, attr, &msg_info);
    if (ret) {
        FI_WARN(&ucr_prov, FI_LOG_FABRIC, "Unable to get core info!\n");
        ret = -FI_EINVAL;
        goto err2;
    }

    ret = fi_fabric(msg_info->fabric_attr, &ucr_fabric->msg_fabric, context);
    if (ret) {
        goto err3;
    }

    ret = ucr_fabric_init_util_coll(ucr_fabric);
    if (ret && ret != -FI_ENODATA)
        goto err4;

    ret = ucr_fabric_init_offload_coll(ucr_fabric);
    if (ret && ret != -FI_ENODATA)
        goto err5;

    *fabric = &ucr_fabric->util_fabric.fabric_fid;
    (*fabric)->fid.ops = &ucr_fabric_fi_ops;
    (*fabric)->ops = &ucr_fabric_ops;

    fi_freeinfo(msg_info);
    return 0;

err5:
    fi_close(&ucr_fabric->util_coll_fabric->fid);
    fi_freeinfo(ucr_fabric->util_coll_info);
err4:
    fi_close(&ucr_fabric->msg_fabric->fid);
err3:
    fi_freeinfo(msg_info);
err2:
    (void)ofi_fabric_close(&ucr_fabric->util_fabric);
err1:
    free(ucr_fabric);
    return ret;
}
