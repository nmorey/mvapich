/*
 * Copyright (c) Intel Corporation, Inc.  All rights reserved.
 * Copyright (c) 2016 Cisco Systems, Inc. All rights reserved.
 * Copyright (c) 2018-2019 Cray Inc. All rights reserved.
 * Copyright (c) 2018-2019 System Fabric Works, Inc. All rights reserved.
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

#ifndef MVERBS_OFI_H
#define MVERBS_OFI_H

#include "config.h"

#include <asm/types.h>
#include <errno.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <poll.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <pthread.h>
#include <ofi_epoll.h>

#include <infiniband/ib.h>
#include <infiniband/verbs.h>
#include <rdma/rdma_cma.h>

#include <rdma/fabric.h>
#include <rdma/fi_cm.h>
#include <rdma/fi_domain.h>
#include <rdma/fi_endpoint.h>
#include <rdma/fi_rma.h>
#include <rdma/fi_errno.h>

#include "ofi.h"
#include "ofi_atomic.h"
#include "ofi_enosys.h"
#include <uthash.h>
#include "ofi_prov.h"
#include "ofi_list.h"
#include "ofi_signal.h"
#include "ofi_util.h"
#include "ofi_tree.h"
#include "ofi_indexer.h"
#include "ofi_iov.h"
#include "ofi_hmem.h"

#include "ofi_mverbs_compat.h"


#ifndef AF_IB
#define AF_IB 27
#endif

#ifndef RAI_FAMILY
#define RAI_FAMILY              0x00000008
#endif

#define MVERBS_RESOLVE_TIMEOUT 2000	// ms

#define MVERBS_PROV_NAME "mverbs"

#define VRB_DBG(subsys, ...) FI_DBG(&mverbs_prov, subsys, __VA_ARGS__)
#define VRB_INFO(subsys, ...) FI_INFO(&mverbs_prov, subsys, __VA_ARGS__)
#define VRB_TRACE(subsys, ...) FI_TRACE(&mverbs_prov, subsys, __VA_ARGS__)
#define VRB_WARN(subsys, ...) FI_WARN(&mverbs_prov, subsys, __VA_ARGS__)

#define VRB_WARN_ERRNO(subsys, fn) \
	VRB_WARN(subsys, fn ": %s (%d)\n", strerror(errno), errno)
#define VRB_WARN_ERR(subsys, fn, err) \
	VRB_WARN(subsys, fn ": %s (%d)\n", fi_strerror((int) -(err)), (int) err)


#define MVERBS_INJECT_FLAGS(ep, len, flags, desc) \
	(((flags) & FI_INJECT) || !(desc) || \
	 ((((struct mverbs_mem_desc *) (desc))->info.iface == FI_HMEM_SYSTEM) && \
	  ((len) <= (ep)->info_attr.inject_size))) ? IBV_SEND_INLINE : 0
#define MVERBS_INJECT(ep, len, desc) \
	MVERBS_INJECT_FLAGS(ep, len, (ep)->util_ep.tx_op_flags, desc)

#define MVERBS_COMP_FLAGS(ep, flags, context)		\
	(((ep)->util_ep.tx_op_flags | (flags)) &		\
	 FI_COMPLETION ? context : MVERBS_NO_COMP_FLAG)
#define MVERBS_COMP(ep, context)						\
	MVERBS_COMP_FLAGS((ep), (ep)->util_ep.tx_op_flags, context)

#define MVERBS_WCE_CNT 1024
#define MVERBS_WRE_CNT 1024

#define MVERBS_DEF_CQ_SIZE 1024
#define MVERBS_MR_IOV_LIMIT 1

#define MVERBS_NO_COMP_FLAG	((uint64_t)-1)

#define VRB_CM_DATA_SIZE	(56)
#define MVERBS_CM_DATA_SIZE	(VRB_CM_DATA_SIZE -		\
				 sizeof(struct mverbs_cm_data_hdr))

#define VRB_CM_REJ_CONSUMER_DEFINED		28
#define VRB_CM_REJ_SIDR_CONSUMER_DEFINED	2

#define MVERBS_DGRAM_MSG_PREFIX_SIZE		(40)

#define VRB_EP_TYPE(info)						\
	((info && info->ep_attr) ? info->ep_attr->type : FI_EP_MSG)
#define VRB_EP_PROTO(info)						\
	(((info) && (info)->ep_attr) ? (info)->ep_attr->protocol :	\
					FI_PROTO_UNSPEC)

#define VRB_MEM_ALIGNMENT (64)
#define VRB_BUF_ALIGNMENT (4096) /* TODO: Page or MTU size */
#define VRB_POOL_BUF_CNT (100)

#define MVERBS_ANY_DOMAIN "verbs_any_domain"
#define MVERBS_ANY_FABRIC "verbs_any_fabric"

extern struct fi_provider mverbs_prov;
extern struct util_prov mverbs_util_prov;
extern ofi_mutex_t mverbs_init_mutex;
extern struct dlist_entry verbs_devs;

extern struct mverbs_gl_data {
	int	def_tx_size;
	int	def_rx_size;
	int	def_tx_iov_limit;
	int	def_rx_iov_limit;
	int	def_inline_size;
	int	min_rnr_timer;
	int	cqread_bunch_size;
	int	use_odp;
	char	*iface;
	int	gid_idx;
	char	*device_name;

	struct {
		int	buffer_num;
		int	buffer_size;
		int	rndv_seg_size;
		int	thread_timeout;
		char	*eager_send_opcode;
		char	*cm_thread_affinity;
	} rdm;

	struct {
		int	use_name_server;
		int	name_server_port;
	} dgram;

	struct {
		int	prefer_xrc;
		char	*xrcd_filename;
	} msg;

	bool	peer_mem_support;
	bool	dmabuf_support;
} mverbs_gl_data;

struct verbs_addr {
	struct dlist_entry entry;
	struct rdma_addrinfo *rai;
};

/*
 * fields of Infiniband packet headers that are used to
 * represent OFI EP address
 * - LRH (Local Route Header) - Link Layer:
 *   - LID - destination Local Identifier
 *   - SL - Service Level
 * - GRH (Global Route Header) - Network Layer:
 *   - GID - destination Global Identifier
 * - BTH (Base Transport Header) - Transport Layer:
 *   - QPN - destination Queue Pair number
 *   - P_key - Partition Key
 *
 * Note: DON'T change the placement of the fields in the structure.
 *       The placement is to keep structure size = 256 bits (32 byte).
 */
struct ofi_ib_ud_ep_name {
	union ibv_gid	gid;		/* 64-bit GUID + 64-bit EUI - GRH */

	uint32_t	qpn;		/* BTH */

	uint16_t	lid; 		/* LRH */
	uint16_t	pkey;		/* BTH */
	uint16_t	service;	/* for NS src addr, 0 means any */

	uint8_t 	sl;		/* LRH */
	uint8_t		padding[5];	/* forced padding to 256 bits (32 byte) */
}; /* 256 bits */

#define MVERBS_IB_UD_NS_ANY_SERVICE	0

static inline
int mverbs_dgram_ns_is_service_wildcard(void *svc)
{
	return (*(int *) svc == MVERBS_IB_UD_NS_ANY_SERVICE);
}

static inline
int mverbs_dgram_ns_service_cmp(void *svc1, void *svc2)
{
	int service1 = *(int *) svc1, service2 = *(int *) svc2;

	if (mverbs_dgram_ns_is_service_wildcard(svc1) ||
	    mverbs_dgram_ns_is_service_wildcard(svc2))
		return 0;

	return (service1 < service2) ? -1 : (service1 > service2);
}

struct verbs_dev_info {
	struct dlist_entry entry;
	char *name;
	struct dlist_entry addrs;
};


struct mverbs_fabric {
	struct util_fabric	util_fabric;
	const struct fi_info	*info;
	struct util_ns		name_server;
};

int mverbs_fabric(struct fi_fabric_attr *attr, struct fid_fabric **fabric,
		  void *context);
int mverbs_find_fabric(const struct fi_fabric_attr *attr);

struct mverbs_progress {
	struct ofi_genlock	ep_lock;
	struct ofi_genlock	*active_lock;

	struct ofi_bufpool	*ctx_pool;
};

int mverbs_init_progress(struct mverbs_progress *progress, struct ibv_context *verbs);
void mverbs_close_progress(struct mverbs_progress *progress);

struct mverbs_eq_entry {
	struct dlist_entry	item;
	uint32_t		event;
	size_t			len;
	union {
		struct fi_eq_entry 	*eq_entry;
		struct fi_eq_cm_entry	*cm_entry;
		uint8_t 		data[0];
	};
};

typedef int (*mverbs_trywait_func)(struct fid *fid);

/* An OFI indexer is used to maintain a unique connection request to
 * endpoint mapping. The key is a 32-bit value (referred to as a
 * connection tag) and is passed to the remote peer by the active side
 * of a connection request. When the reciprocal XRC connection in the
 * reverse direction is made, the key is passed back and used to map
 * back to the original endpoint. A key is defined as a 32-bit value:
 *
 *     SSSSSSSS:SSSSSSII:IIIIIIII:IIIIIIII
 *     |-- sequence -||--- unique key ---|
 */
#define MVERBS_CONN_TAG_INDEX_BITS	18
#define MVERBS_CONN_TAG_INVALID		0xFFFFFFFF	/* Key is not valid */

struct mverbs_eq {
	struct fid_eq		eq_fid;
	struct mverbs_fabric	*fab;
	ofi_mutex_t		lock;
	ofi_mutex_t		event_lock;
	struct dlistfd_head	list_head;
	struct rdma_event_channel *channel;
	uint64_t		flags;
	struct fi_eq_err_entry	err;

	ofi_epoll_t		epollfd;
	enum fi_wait_obj	wait_obj;

	struct {
		/* The connection key map is used during the XRC connection
		 * process to map an XRC reciprocal connection request back
		 * to the active endpoint that initiated the original
		 * connection request. It is protected with the eq::lock */
		struct ofi_key_idx	conn_key_idx;
		struct indexer		*conn_key_map;

		/* TODO: This is limiting and restricts applications to using
		 * a single listener per EQ. While sufficient for RXM we should
		 * consider using an internal PEP listener for handling the
		 * internally processed reciprocal connections. */
		uint16_t		pep_port;

		/* SIDR request/responses are a two-way handshake; therefore,
		 * we maintain an RB tree of SIDR accept responses, so that if
		 * a response is lost, the subsequent retried request can be
		 * detected and the original accept response resent. Note, that
		 * rejected requests can be passed to RXM and will be rejected
		 * a second time. */
		struct ofi_rbmap	sidr_conn_rbmap;
	} xrc;
};

int mverbs_eq_open(struct fid_fabric *fabric, struct fi_eq_attr *attr,
		   struct fid_eq **eq, void *context);
int mverbs_eq_trywait(struct mverbs_eq *eq);
void mverbs_eq_remove_events(struct mverbs_eq *eq, struct fid *fid);

int mverbs_av_open(struct fid_domain *domain, struct fi_av_attr *attr,
		   struct fid_av **av, void *context);

struct mverbs_pep {
	struct fid_pep		pep_fid;
	struct mverbs_eq		*eq;
	struct rdma_cm_id	*id;

	/* XRC uses SIDR based RDMA CM exchanges for setting up
	 * shared QP connections. This ID is bound to the same
	 * port number as "id", but the RDMA_PS_UDP port space. */
	struct rdma_cm_id	*xrc_ps_udp_id;

	int			backlog;
	int			bound;
	size_t			src_addrlen;
	struct fi_info		*info;
};

struct fi_ops_cm *mverbs_pep_ops_cm(struct mverbs_pep *pep);


#if MVERBS_HAVE_QUERY_EX
#define VRB_ACCESS_ON_DEMAND IBV_ACCESS_ON_DEMAND
#else
#define VRB_ACCESS_ON_DEMAND 0
#endif

enum {
	VRB_USE_XRC = BIT(0),
	VRB_USE_ODP = BIT(1),
};

struct mverbs_domain {
	struct util_domain		util_domain;
	struct ibv_context		*verbs;
	struct ibv_pd			*pd;

	struct mverbs_progress		progress;

	enum fi_ep_type			ep_type;
	struct fi_info			*info;

	/* The EQ is utilized by verbs/MSG */
	struct mverbs_eq			*eq;
	uint64_t			eq_flags;

	ssize_t		(*send_credits)(struct fid_ep *ep, uint64_t credits);

	/* Domain use of specific extended H/W capabilities, e.g. XRC, ODP */
	uint64_t			ext_flags;
	struct {
		int			xrcd_fd;
		struct ibv_xrcd		*xrcd;

		/* XRC INI QP connections can be shared between endpoint
		 * within the same domain. The domain maintains an RBTree
		 * for mapping endpoint destination addresses to the
		 * physical XRC INI connection to the associated node. The
		 * map and XRC INI connection object state information are
		 * protected via the ini_lock. */
		ofi_mutex_t		ini_lock;
		ofi_mutex_lock_t	lock_acquire;
		ofi_mutex_unlock_t	lock_release;
		struct ofi_rbmap	*ini_conn_rbmap;
	} xrc;

	/* MR stuff */
	struct ofi_mr_cache		cache;
};

struct mverbs_cq;

struct mverbs_wc_entry {
	struct slist_entry	entry;
	struct ibv_wc		wc;
};

struct mverbs_srx;

struct mverbs_cq {
	struct util_cq		util_cq;
	struct ibv_comp_channel	*channel;
	struct ibv_cq		*cq;
	size_t			entry_size;
	uint64_t		flags;
	enum fi_wait_obj	wait_obj;
	enum fi_cq_wait_cond	wait_cond;
	struct ibv_wc		wc;
	struct fd_signal	signal;
	ofi_atomic32_t		nevents;

	struct {
		/* The list of XRC SRQ contexts associated with this CQ */
		struct dlist_entry	srq_list;
	} xrc;
};

int mverbs_cq_open(struct fid_domain *domain, struct fi_cq_attr *attr,
		   struct fid_cq **cq, void *context);
int mverbs_cq_trywait(struct mverbs_cq *cq);

struct mverbs_mem_desc {
	struct fid_mr		mr_fid;
	struct ibv_mr		*mr;
	struct mverbs_domain	*domain;
	/* this field is used only by MR cache operations */
	struct ofi_mr_entry	*entry;
	struct ofi_mr_info	info;
	uint32_t		lkey;
	struct gdrcopy_handle *cache_gdrcopy_handle;
};

extern struct fi_ops_mr mverbs_mr_ops;

int mverbs_mr_cache_add_region(struct ofi_mr_cache *cache,
			       struct ofi_mr_entry *entry);
void mverbs_mr_cache_delete_region(struct ofi_mr_cache *cache,
				   struct ofi_mr_entry *entry);

/*
 * An XRC SRQ cannot be created until the associated RX CQ is known,
 * maintain a list of validated pre-posted receives to post once
 * the SRQ is created.
 */
struct mverbs_xrc_srx_prepost {
	struct slist_entry	prepost_entry;
	void			*buf;
	void			*desc;
	void			*context;
	size_t			len;
	fi_addr_t		src_addr;
};

struct mverbs_srx {
	struct fid_ep		ep_fid;
	struct ibv_srq		*srq;
	struct mverbs_domain	*domain;

	/* For XRC SRQ only */
	struct {
		/* XRC SRQ is not created until endpoint enable */
		/* TODO: replace prepost_lock with progress lock */
		ofi_mutex_t		prepost_lock;
		struct slist		prepost_list;
		uint32_t		max_recv_wr;
		uint32_t		max_sge;
		uint32_t		prepost_count;

		/* The RX CQ associated with this XRC SRQ. */
		struct mverbs_cq		*cq;

		/* The CQ maintains a list of XRC SRQ associated with it */
		struct dlist_entry	srq_entry;
	} xrc;
};

int mverbs_srq_context(struct fid_domain *domain, struct fi_rx_attr *attr,
		       struct fid_ep **rx_ep, void *context);

int mverbs_domain_xrc_init(struct mverbs_domain *domain);
int mverbs_domain_xrc_cleanup(struct mverbs_domain *domain);

enum mverbs_ini_qp_state {
	VRB_INI_QP_UNCONNECTED,
	VRB_INI_QP_CONNECTING,
	VRB_INI_QP_CONNECTED
};

#define VRB_NO_INI_TGT_QPNUM 0
#define VRB_RECIP_CONN	1

/*
 * An XRC transport INI QP connection can be shared within a process to
 * communicate with all the ranks on the same remote node. This structure is
 * only accessed during connection setup and tear down and should be
 * done while holding the domain:eq:lock.
 */
struct mverbs_ini_shared_conn {
	/* To share, EP must have same remote peer host addr and TX CQ */
	struct sockaddr			*peer_addr;
	struct mverbs_cq			*tx_cq;

	/* The physical INI/TGT QPN connection. Virtual connections to the
	 * same remote peer and TGT QPN will share this connection, with
	 * the remote end opening the specified XRC TGT QPN for sharing
	 * During the physical connection setup, phys_conn_id identifies
	 * the RDMA CM ID (and MSG_EP) associated with the operation. */
	enum mverbs_ini_qp_state		state;
	struct rdma_cm_id		*phys_conn_id;
	struct ibv_qp			*ini_qp;
	uint32_t			tgt_qpn;

	/* EP waiting on or using this INI/TGT physical connection will be in
	 * one of these list and hold a reference to the shared connection. */
	struct dlist_entry		pending_list;
	struct dlist_entry		active_list;
	ofi_atomic32_t			ref_cnt;
};

enum mverbs_xrc_ep_conn_state {
	VRB_XRC_UNCONNECTED,
	VRB_XRC_ORIG_CONNECTING,
	VRB_XRC_ORIG_CONNECTED,
	VRB_XRC_RECIP_CONNECTING,
	VRB_XRC_CONNECTED,
	VRB_XRC_ERROR
};

/*
 * The following XRC state is only required during XRC connection
 * establishment and can be freed once bidirectional connectivity
 * is established.
 */
#define VRB_MAX_XRC_CONNECT_RETRIES	16

struct mverbs_xrc_ep_conn_setup {
	int				retry_count;

	/* The connection tag is used to associate the reciprocal
	 * XRC INI/TGT QP connection request in the reverse direction
	 * with the original request. The tag is created by the
	 * original active side. */
	uint32_t			conn_tag;
	uint32_t			remote_conn_tag;

	/* Delivery of the FI_CONNECTED event is delayed until
	 * bidirectional connectivity is established. */
	size_t				event_len;
	uint8_t				event_data[VRB_CM_DATA_SIZE];

	/* Connection request may have to queue waiting for the
	 * physical XRC INI/TGT QP connection to complete. */
	int				pending_recip;
	size_t				pending_paramlen;
	uint8_t				pending_param[VRB_CM_DATA_SIZE];
};

enum mverbs_ep_state {
	VRB_IDLE,
	VRB_RESOLVE_ROUTE,
	VRB_CONNECTING,
	VRB_REQ_RCVD,
	VRB_ACCEPTING,
	VRB_CONNECTED,
	VRB_DISCONNECTED,
};

struct mverbs_ep {
	struct util_ep			util_ep;
	struct ibv_qp			*ibv_qp;

	/* Protected by send CQ lock */
	uint64_t			sq_credits;
	uint64_t			peer_rq_credits;
	uint64_t			saved_peer_rq_credits;
	struct slist			sq_list;
	struct slist			rq_list;
	/* Protected by recv CQ lock */
	int64_t				rq_credits_avail;
	int64_t				threshold;

	enum mverbs_ep_state		state;
	union {
		struct rdma_cm_id	*id;
		struct {
			struct ofi_ib_ud_ep_name	ep_name;
			int				service;
		};
	};

	struct {
		size_t			inject_size;
		size_t                  tx_size;
		size_t                  tx_iov_limit;
		size_t                  rx_size;
		size_t                  rx_iov_limit;
		uint32_t                protocol;
		uint32_t                addr_format;
		size_t                  src_addrlen;
		size_t                  dest_addrlen;
		void                    *src_addr;
		void                    *dest_addr;
		void                    *handle;
	} info_attr;
	struct mverbs_eq			*eq;
	struct mverbs_srx			*srx;

	struct {
		struct ibv_send_wr	rma_wr;
		struct ibv_send_wr	msg_wr;
		struct ibv_sge		sge;
	} *wrs;
	struct rdma_conn_param		conn_param;
	struct mverbs_cm_data_hdr		*cm_hdr;
	void				*cm_priv_data;
	bool				hmem_enabled;
};


enum mverbs_op_queue {
	VRB_OP_SQ,
	VRB_OP_RQ,
	VRB_OP_SRQ,
};

struct mverbs_context {
	struct slist_entry		entry;
	union {
		struct mverbs_ep		*ep;
		struct mverbs_srx		*srx;
	};
	void				*user_ctx;
	enum mverbs_op_queue		op_queue;
	enum ibv_wr_opcode		sq_opcode;
};

enum ibv_wc_opcode mverbs_wr2wc_opcode(enum ibv_wr_opcode wr);

#define MVERBS_XRC_EP_MAGIC		0x1F3D5B79
struct mverbs_xrc_ep {
	/* Must be first */
	struct mverbs_ep			base_ep;

	/* XRC only fields */
	struct rdma_cm_id		*tgt_id;
	struct ibv_qp			*tgt_ibv_qp;
	enum mverbs_xrc_ep_conn_state	conn_state;
	bool				recip_req_received;
	uint32_t			magic;
	uint32_t			srqn;
	uint32_t			peer_srqn;

	/* A reference is held to a shared physical XRC INI/TGT QP connecting
	 * to the destination node. */
	struct mverbs_ini_shared_conn	*ini_conn;
	struct dlist_entry		ini_conn_entry;

	/* The following is used for resending lost SIDR accept response
	 * messages when a retransmit SIDR connect request is received. */
	void				*accept_param_data;
	size_t				accept_param_len;
	uint16_t			remote_pep_port;
	bool				recip_accept;
	struct ofi_rbnode		*conn_map_node;

	/* The following state is allocated during XRC bidirectional setup and
	 * freed once the connection is established. */
	struct mverbs_xrc_ep_conn_setup	*conn_setup;
};

static inline int mverbs_is_xrc_info(struct fi_info *info)
{
	return (VRB_EP_TYPE(info) == FI_EP_MSG) &&
		(VRB_EP_PROTO(info) == FI_PROTO_RDMA_CM_IB_XRC);
}

static inline int mverbs_is_xrc_ep(struct mverbs_ep *ep)
{
	return (ep->util_ep.type == FI_EP_MSG) &&
		(ep->info_attr.protocol == FI_PROTO_RDMA_CM_IB_XRC);
}

int mverbs_open_ep(struct fid_domain *domain, struct fi_info *info,
		   struct fid_ep **ep, void *context);
int mverbs_passive_ep(struct fid_fabric *fabric, struct fi_info *info,
		      struct fid_pep **pep, void *context);
int mverbs_create_ep(struct mverbs_ep *ep, enum rdma_port_space ps,
		     struct rdma_cm_id **id);
int mverbs_dgram_av_open(struct fid_domain *domain_fid, struct fi_av_attr *attr,
			 struct fid_av **av_fid, void *context);

static inline struct mverbs_domain *mverbs_ep2_domain(struct mverbs_ep *ep)
{
	return container_of(ep->util_ep.domain, struct mverbs_domain,
			    util_domain);
}

extern struct fi_ops_atomic mverbs_msg_ep_atomic_ops;
extern struct fi_ops_atomic mverbs_msg_xrc_ep_atomic_ops;
extern struct fi_ops_cm mverbs_msg_ep_cm_ops;
extern struct fi_ops_cm mverbs_msg_xrc_ep_cm_ops;
extern const struct fi_ops_msg mverbs_msg_ep_msg_ops_ts;
extern const struct fi_ops_msg mverbs_msg_ep_msg_ops;
extern const struct fi_ops_msg mverbs_dgram_msg_ops_ts;
extern const struct fi_ops_msg mverbs_dgram_msg_ops;
extern const struct fi_ops_msg mverbs_msg_xrc_ep_msg_ops;
extern const struct fi_ops_msg mverbs_msg_xrc_ep_msg_ops_ts;
extern const struct fi_ops_msg mverbs_msg_srq_xrc_ep_msg_ops;
extern struct fi_ops_rma mverbs_msg_ep_rma_ops_ts;
extern struct fi_ops_rma mverbs_msg_ep_rma_ops;
extern struct fi_ops_rma mverbs_msg_xrc_ep_rma_ops_ts;
extern struct fi_ops_rma mverbs_msg_xrc_ep_rma_ops;

#define VRB_XRC_VERSION	2

struct mverbs_xrc_cm_data {
	uint8_t		version;
	uint8_t		reciprocal;
	uint16_t	port;
	uint32_t	tgt_qpn;
	uint32_t	srqn;
	uint32_t	conn_tag;
};

struct mverbs_xrc_conn_info {
	uint32_t		conn_tag;
	uint32_t		is_reciprocal;
	uint32_t		ini_qpn;
	uint32_t		tgt_qpn;
	uint32_t		peer_srqn;
	uint16_t		port;
	struct rdma_conn_param	conn_param;
};

struct mverbs_connreq {
	struct fid			handle;
	struct rdma_cm_id		*id;

	/* Support for XRC bidirectional connections, and
	 * non-RDMA CM managed QP. */
	int				is_xrc;
	struct mverbs_xrc_conn_info	xrc;
};

/* Structure below is a copy of the RDMA CM header (structure ib_connect_hdr in
 * file librdmacm/cma.h)
 * DO NOT MODIFY! */
struct mverbs_rdma_cm_hdr {
	uint8_t  cma_version; /* Set by the kernel */
	uint8_t  ip_version; /*  IP version: 7:4 */
	uint16_t port;
	uint32_t src_addr[4];
	uint32_t dst_addr[4];
};

struct mverbs_cm_data_hdr {
	uint8_t	size;
	char	data[];
};

int mverbs_eq_add_sidr_conn(struct mverbs_xrc_ep *ep,
			    void *param_data, size_t param_len);
void mverbs_eq_remove_sidr_conn(struct mverbs_xrc_ep *ep);

void mverbs_msg_ep_get_qp_attr(struct mverbs_ep *ep,
			       struct ibv_qp_init_attr *attr);
int mverbs_process_xrc_connreq(struct mverbs_ep *ep,
			       struct mverbs_connreq *connreq);

void mverbs_next_xrc_conn_state(struct mverbs_xrc_ep *ep);
void mverbs_prev_xrc_conn_state(struct mverbs_xrc_ep *ep);
void mverbs_eq_set_xrc_conn_tag(struct mverbs_xrc_ep *ep);
void mverbs_eq_clear_xrc_conn_tag(struct mverbs_xrc_ep *ep);
void mverbs_set_xrc_cm_data(struct mverbs_xrc_cm_data *local, int reciprocal,
			    uint32_t conn_tag, uint16_t port, uint32_t tgt_qpn,
			    uint32_t srqn);
int mverbs_verify_xrc_cm_data(struct mverbs_xrc_cm_data *remote,
			      int private_data_len);
int mverbs_connect_xrc(struct mverbs_xrc_ep *ep, struct sockaddr *addr,
		       int reciprocal, void *param, size_t paramlen);
int mverbs_accept_xrc(struct mverbs_xrc_ep *ep, int reciprocal,
		      void *param, size_t paramlen);
int mverbs_resend_shared_accept_xrc(struct mverbs_xrc_ep *ep,
				    struct mverbs_connreq *connreq,
				    struct rdma_cm_id *id);
void mverbs_free_xrc_conn_setup(struct mverbs_xrc_ep *ep, int disconnect);
void mverbs_add_pending_ini_conn(struct mverbs_xrc_ep *ep, int reciprocal,
				 void *conn_param, size_t conn_paramlen);
void mverbs_sched_ini_conn(struct mverbs_ini_shared_conn *ini_conn);
int mverbs_get_shared_ini_conn(struct mverbs_xrc_ep *ep,
			       struct mverbs_ini_shared_conn **ini_conn);
void mverbs_put_shared_ini_conn(struct mverbs_xrc_ep *ep);

void mverbs_save_priv_data(struct mverbs_xrc_ep *ep, const void *data,
			   size_t len);
int mverbs_ep_create_ini_qp(struct mverbs_xrc_ep *ep, void *dst_addr,
			    uint32_t *peer_tgt_qpn);
void mverbs_ep_ini_conn_done(struct mverbs_xrc_ep *ep, uint32_t peer_tgt_qpn);
void mverbs_ep_ini_conn_rejected(struct mverbs_xrc_ep *ep);
int mverbs_ep_create_tgt_qp(struct mverbs_xrc_ep *ep, uint32_t tgt_qpn);
void mverbs_ep_tgt_conn_done(struct mverbs_xrc_ep *qp);
int mverbs_ep_destroy_xrc_qp(struct mverbs_xrc_ep *ep);

int mverbs_xrc_close_srq(struct mverbs_srx *srx);

int mverbs_read_params(void);
int mverbs_getinfo(uint32_t version, const char *node, const char *service,
		   uint64_t flags, const struct fi_info *hints,
		   struct fi_info **info);
const struct fi_info *mverbs_get_verbs_info(const struct fi_info *ilist,
					    const char *domain_name);
int mverbs_set_rai(uint32_t addr_format, void *src_addr, size_t src_addrlen,
		void *dest_addr, size_t dest_addrlen, uint64_t flags,
		struct rdma_addrinfo *rai);
int mverbs_get_matching_info(uint32_t version, const struct fi_info *hints,
			     struct fi_info **info, const struct fi_info *verbs_info,
			     uint8_t passive);
int mverbs_get_port_space(uint32_t addr_format);
void mverbs_alter_info(const struct fi_info *hints, struct fi_info *info);

struct mverbs_ep_domain {
	char			*suffix;
	enum fi_ep_type		type;
	uint32_t		protocol;
};

extern const struct mverbs_ep_domain mverbs_dgram_domain;
extern const struct mverbs_ep_domain mverbs_msg_xrc_domain;

int mverbs_check_ep_attr(const struct fi_info *hints,
			 const struct fi_info *info);
int mverbs_check_rx_attr(const struct fi_rx_attr *attr,
			 const struct fi_info *hints,
			 const struct fi_info *info);

static inline int mverbs_cmp_xrc_domain_name(const char *domain_name,
					     const char *rdma_name)
{
	size_t domain_len = strlen(domain_name);
	size_t suffix_len = strlen(mverbs_msg_xrc_domain.suffix);

	return domain_len > suffix_len ? strncmp(domain_name, rdma_name,
						 domain_len - suffix_len) : -1;
}

int mverbs_cq_signal(struct fid_cq *cq);

struct mverbs_eq_entry *mverbs_eq_alloc_entry(uint32_t event,
					      const void *buf, size_t len);
ssize_t mverbs_eq_write_event(struct mverbs_eq *eq, uint32_t event,
		const void *buf, size_t len);

int mverbs_query_atomic(struct fid_domain *domain_fid, enum fi_datatype datatype,
			enum fi_op op, struct fi_atomic_attr *attr,
			uint64_t flags);
void mverbs_set_rnr_timer(struct ibv_qp *qp);
void mverbs_cleanup_cq(struct mverbs_ep *cur_ep);
int mverbs_find_max_inline(struct ibv_pd *pd, struct ibv_context *context,
			   enum ibv_qp_type qp_type);

struct mverbs_dgram_av {
	struct util_av util_av;
	struct dlist_entry av_entry_list;
};

struct mverbs_dgram_av_entry {
	struct dlist_entry list_entry;
	struct ofi_ib_ud_ep_name addr;
	struct ibv_ah *ah;
};

static inline struct mverbs_dgram_av_entry*
mverbs_dgram_av_lookup_av_entry(fi_addr_t fi_addr)
{
	return (struct mverbs_dgram_av_entry *) (uintptr_t) fi_addr;
}

/* NOTE:
 * When ibv_post_send/recv returns '-1' it means the following:
 * Deal with non-compliant libibverbs drivers which set errno
 * instead of directly returning the error value
 */
static inline ssize_t mverbs_convert_ret(int ret)
{
	if (!ret)
		return 0;
	else if (ret == -ENOMEM || ret == ENOMEM)
		return -FI_EAGAIN;
	else if (ret == -1)
		return (errno == ENOMEM) ? -FI_EAGAIN : -errno;
	else
		return -abs(ret);
}


int mverbs_poll_cq(struct mverbs_cq *cq, struct ibv_wc *wc);
void mverbs_report_wc(struct mverbs_cq *cq, struct ibv_wc *wc);
void mverbs_flush_cq(struct mverbs_cq *cq);

#define mverbs_init_sge(buf, len, desc) (struct ibv_sge)	\
	{ .addr = (uintptr_t) buf,			\
	  .length = (uint32_t) len,			\
	  .lkey = (desc) ? ((struct mverbs_mem_desc *) (desc))->lkey : 0 }

#define mverbs_iov_dupa(dst, iov, desc, count)			\
do {								\
	size_t i;						\
	dst = alloca(sizeof(*dst) * count);			\
	for (i = 0; i < count; i++) {				\
		dst[i] = mverbs_init_sge(iov[i].iov_base,		\
				      iov[i].iov_len, desc[i]);	\
	}							\
} while (0)

#define mverbs_wr_consumes_recv(wr)						\
	( wr->opcode == IBV_WR_SEND || wr->opcode == IBV_WR_SEND_WITH_IMM	\
	|| wr->opcode == IBV_WR_RDMA_WRITE_WITH_IMM )

void mverbs_shutdown_ep(struct mverbs_ep *ep);
ssize_t mverbs_post_send(struct mverbs_ep *ep, struct ibv_send_wr *wr, uint64_t flags);
ssize_t mverbs_post_recv(struct mverbs_ep *ep, struct ibv_recv_wr *wr);

static inline ssize_t
mverbs_send_buf(struct mverbs_ep *ep, struct ibv_send_wr *wr,
		const void *buf, size_t len, void *desc)
{
	struct ibv_sge sge = mverbs_init_sge(buf, len, desc);

	wr->sg_list = &sge;
	wr->num_sge = 1;

	return mverbs_post_send(ep, wr, 0);
}

ssize_t mverbs_send_iov(struct mverbs_ep *ep, struct ibv_send_wr *wr,
		     const struct iovec *iov, void **desc, int count,
		     uint64_t flags);

void mverbs_add_credits(struct fid_ep *ep, uint64_t credits);

int mverbs_get_rai_id(const char *node, const char *service, uint64_t flags,
		      const struct fi_info *hints, struct rdma_addrinfo **rai,
		      struct rdma_cm_id **id);


static inline struct mverbs_progress *mverbs_cq2_progress(struct mverbs_cq *cq)
{
	struct mverbs_domain *domain;
	domain = container_of(cq->util_cq.domain, struct mverbs_domain,
			      util_domain);
	return &domain->progress;
}

static inline struct mverbs_progress *mverbs_ep2_progress(struct mverbs_ep *ep)
{
	return &mverbs_ep2_domain(ep)->progress;
}

static inline struct mverbs_progress *mverbs_srx2_progress(struct mverbs_srx *srx)
{
	return &srx->domain->progress;
}

static inline struct mverbs_context *mverbs_alloc_ctx(struct mverbs_progress *progress)
{
	assert(ofi_genlock_held(progress->active_lock));
	return ofi_buf_alloc(progress->ctx_pool);
}

static inline void
mverbs_free_ctx(struct mverbs_progress *progress, struct mverbs_context *ctx)
{
	assert(ofi_genlock_held(progress->active_lock));
	ofi_buf_free(ctx);
}

#endif /* MVERBS_OFI_H */
