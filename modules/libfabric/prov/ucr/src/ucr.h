
/*
 * Copyright (c) 2016-2021 Intel Corporation, Inc.  All rights reserved.
 * Copyright (c) 2019 Amazon.com, Inc. or its affiliates. All rights reserved.
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

#if HAVE_CONFIG_H
#  include <config.h>
#endif /* HAVE_CONFIG_H */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <rdma/fabric.h>
#include <rdma/fi_errno.h>
#include <rdma/fi_cm.h>
#include <rdma/fi_domain.h>
#include <rdma/fi_endpoint.h>
#include <rdma/fi_eq.h>

#include <ofi.h>
#include <ofi_enosys.h>
#include <ofi_util.h>
#include <ofi_list.h>
#include <ofi_lock.h>
#include <ofi_proto.h>
#include <ofi_iov.h>
#include <ofi_hmem.h>

#ifndef _UCR_H_
#define _UCR_H_


#define UCR_CM_DATA_VERSION	1
#define UCR_OP_VERSION		3
#define UCR_CTRL_VERSION	4

enum {
	UCR_REJECT_UNSPEC,
	UCR_REJECT_ECONNREFUSED,
	UCR_REJECT_EALREADY,
};

enum {
	UCR_CM_FLOW_CTRL_LOCAL,
	UCR_CM_FLOW_CTRL_PEER_ON,
	UCR_CM_FLOW_CTRL_PEER_OFF,
};

union ucr_cm_data {
	struct _connect {
		uint8_t version;
		uint8_t endianness;
		uint8_t ctrl_version;
		uint8_t op_version;
		uint16_t port;
		uint8_t flow_ctrl;
		uint8_t padding;
		uint32_t eager_limit;
		uint32_t rx_size; /* used? */
		uint64_t client_conn_id;
	} connect;

	struct _accept {
		uint64_t server_conn_id;
		uint32_t rx_size; /* used? */
		uint8_t flow_ctrl;
		uint8_t align_pad[3];
	} accept;

	struct _reject {
		uint8_t version;
		uint8_t reason;
	} reject;
};

static inline uint64_t ucr_conn_id(int peer_index)
{
	return (((uint64_t) getpid()) << 32) | ((uint32_t) peer_index);
}

static inline int ucr_peer_index(uint64_t conn_id)
{
	return (int) conn_id;
}

static inline uint32_t ucr_peer_pid(uint64_t conn_id)
{
	return (uint32_t) (conn_id >> 32);
}

extern size_t ucr_buffer_size;
extern size_t ucr_packet_size;

#define UCR_SAR_TX_ERROR	UINT64_MAX
#define UCR_SAR_RX_INIT		UINT64_MAX

#define UCR_IOV_LIMIT 4

#define UCR_PEER_XFER_TAG_FLAG	(1ULL << 63)

#define UCR_MR_MODES	(OFI_MR_BASIC_MAP | FI_MR_LOCAL)

#define UCR_PASSTHRU_TX_OP_FLAGS (FI_TRANSMIT_COMPLETE)

#define UCR_PASSTHRU_RX_OP_FLAGS 0ULL

#define UCR_TX_OP_FLAGS (FI_INJECT | FI_INJECT_COMPLETE | \
			 FI_DELIVERY_COMPLETE | FI_COMPLETION)
#define UCR_RX_OP_FLAGS (FI_MULTI_RECV | FI_COMPLETION)

#define UCR_MR_VIRT_ADDR(info) ((info->domain_attr->mr_mode == FI_MR_BASIC) ||\
				info->domain_attr->mr_mode & FI_MR_VIRT_ADDR)

#define UCR_MR_PROV_KEY(info) ((info->domain_attr->mr_mode == FI_MR_BASIC) ||\
			       info->domain_attr->mr_mode & FI_MR_PROV_KEY)

#define UCR_UPDATE_STATE(subsystem, buf, new_state)			\
	do {								\
		FI_DBG(&ucr_prov, subsystem, "[PROTO] msg_id: 0x%"	\
		       PRIx64 " %s -> %s\n", (buf)->pkt.ctrl_hdr.msg_id,\
		       ucr_proto_state_str[(buf)->hdr.state],		\
		       ucr_proto_state_str[new_state]);			\
		(buf)->hdr.state = new_state;				\
	} while (0)

#define UCR_DBG_ADDR_TAG(subsystem, log_str, addr, tag) 	\
	FI_DBG(&ucr_prov, subsystem, log_str 			\
	       " (fi_addr: 0x%" PRIx64 " tag: 0x%" PRIx64 ")\n",\
	       addr, tag)
#define UCR_WARN_ERR(subsystem, log_str, err) \
	FI_WARN(&ucr_prov, subsystem, log_str "%s (%d)\n", \
		fi_strerror((int) -(err)), (int) err)

#define UCR_GET_PROTO_STATE(context)					\
	(*(enum ucr_proto_state *)					\
	  ((unsigned char *)context + offsetof(struct ucr_buf, state)))

#define UCR_SET_PROTO_STATE(comp, new_state)				\
do {									\
	(*(enum ucr_proto_state *)					\
	  ((unsigned char *)(comp)->op_context +			\
		offsetof(struct ucr_buf, state))) = (new_state);	\
} while (0)

#define ucr_tx_buf_2_msg_id(ucr_ep, pool_type, tx_buf)				\
	((uint64_t) ucr_get_buf_index(&(ucr_ep)->buf_pools[pool_type],		\
				       (void *) tx_buf))
#define ucr_msg_id_2_tx_buf(ucr_ep, pool_type, msg_id)				\
	((void *) ucr_buf_get_by_index(&(ucr_ep)->buf_pools[pool_type],		\
				       (uint64_t) msg_id))

extern struct fi_provider ucr_prov;
extern struct util_prov ucr_util_prov;

extern struct fi_ops_msg ucr_msg_ops;
extern struct fi_ops_msg ucr_msg_thru_ops;
extern struct fi_ops_tagged ucr_tagged_ops;
extern struct fi_ops_tagged ucr_tagged_thru_ops;
extern struct fi_ops_rma ucr_rma_ops;
extern struct fi_ops_rma ucr_rma_thru_ops;
extern struct fi_ops_atomic ucr_ops_atomic;

enum {
	UCR_MSG_RXTX_SIZE = 128,
	UCR_MSG_SRX_SIZE = 4096,
	UCR_RX_SIZE = 65536,
	UCR_TX_SIZE = 128,
};

extern size_t ucr_msg_tx_size;
extern size_t ucr_msg_rx_size;
extern size_t ucr_cm_progress_interval;
extern size_t ucr_cq_eq_fairness;
extern int ucr_passthru;
extern int ucr_force_auto_progress;
extern int ucr_use_write_rndv;
extern enum fi_wait_obj def_wait_obj, def_tcp_wait_obj;

struct ucr_ep;
struct ucr_av;


enum ucr_cm_state {
	UCR_CM_IDLE,
	UCR_CM_CONNECTING,
	UCR_CM_ACCEPTING,
	UCR_CM_CONNECTED,
};

enum {
	UCR_CONN_INDEXED = BIT(0),
};

/* Each local ucr ep will have at most 1 connection to a single
 * remote ucr ep.  A local ucr ep may not be connected to all
 * remote ucr ep's.
 */
struct ucr_conn {
	enum ucr_cm_state state;
	struct util_peer_addr *peer;
	struct fid_ep *msg_ep;
	struct ucr_ep *ep;

	/* Prior versions of libfabric did not guarantee that all connections
	 * from the same peer would have the same conn_id.  For compatibility
	 * we need to store the remote_index per connection, rather than with
	 * the peer_addr.
	 */
	int remote_index;
	uint32_t remote_pid;
	uint8_t flags;
	uint8_t flow_ctrl;
	uint8_t peer_flow_ctrl;

	struct dlist_entry deferred_entry;
	struct dlist_entry deferred_tx_queue;
	struct dlist_entry deferred_sar_msgs;
	struct dlist_entry deferred_sar_segments;
	struct dlist_entry loopback_entry;
};

void ucr_freeall_conns(struct ucr_ep *ep);

struct ucr_fabric {
	struct util_fabric util_fabric;
	struct fid_fabric *msg_fabric;
	struct fi_info *util_coll_info;
	struct fi_info *offload_coll_info;
	struct fid_fabric *util_coll_fabric;
	struct fid_fabric *offload_coll_fabric;
};

struct ucr_domain {
	struct util_domain util_domain;
	struct fid_domain *msg_domain;
	size_t max_atomic_size;
	size_t rx_post_size;
	uint64_t mr_key;
	bool passthru;
	struct ofi_ops_flow_ctrl *flow_ctrl_ops;
	struct ofi_bufpool *amo_bufpool;
	ofi_mutex_t amo_bufpool_lock;
	struct fid_domain *util_coll_domain;
	struct fid_domain *offload_coll_domain;
	uint64_t offload_coll_mask;
};

struct ucr_cq {
	struct util_cq util_cq;
	struct fid_peer_cq peer_cq;
	struct fid_cq *util_coll_cq;
	struct fid_cq *offload_coll_cq;
};

struct ucr_eq {
	struct util_eq util_eq;
	struct fid_eq *util_coll_eq;
	struct fid_eq *offload_coll_eq;
};

struct ucr_cntr {
	struct util_cntr util_cntr;

	/* Used in passthru mode */
	struct fid_cntr *msg_cntr;
};


struct ucr_mr {
	struct fid_mr mr_fid;
	struct fid_mr *msg_mr;
	struct ucr_domain *domain;
	enum fi_hmem_iface iface;
	uint64_t device;
	void *hmem_handle;
	uint64_t hmem_flags;
	ofi_mutex_t amo_lock;
};

static inline enum fi_hmem_iface
ucr_mr_desc_to_hmem_iface_dev(void **desc, size_t count, uint64_t *device)
{
	if (!count || !desc || !desc[0]) {
		*device = 0;
		return FI_HMEM_SYSTEM;
	}

	*device = ((struct ucr_mr *) desc[0])->device;
	return ((struct ucr_mr *) desc[0])->iface;
}

struct ucr_rndv_hdr {
	struct ofi_rma_iov iov[UCR_IOV_LIMIT];
	uint8_t count;
};

#define ucr_pkt_rndv_data(ucr_pkt) \
	((ucr_pkt)->data + sizeof(struct ucr_rndv_hdr))

struct ucr_atomic_hdr {
	struct fi_rma_ioc rma_ioc[UCR_IOV_LIMIT];
	char data[];
};

struct ucr_atomic_resp_hdr {
	int32_t status;
	uint32_t result_len;
	char data[];
};

/*
 * Macros to generate enums and associated string values
 * e.g.
 * #define UCR_PROTO_STATES(FUNC)	\
 * 	FUNC(STATE1),			\
 * 	FUNC(STATE2),			\
 * 	...				\
 * 	FUNC(STATEn)
 *
 * enum ucr_state {
 * 	UCR_PROTO_STATES(OFI_ENUM_VAL)
 * };
 *
 * char *ucr_state_str[] = {
 * 	UCR_PROTO_STATES(OFI_STR)
 * };
 */

/* UCR protocol states / tx/rx context */
#define UCR_PROTO_STATES(FUNC)		\
	FUNC(UCR_TX),			\
	FUNC(UCR_INJECT_TX),		\
	FUNC(UCR_RMA),			\
	FUNC(UCR_RX),			\
	FUNC(UCR_SAR_TX),		\
	FUNC(UCR_CREDIT_TX),		\
	FUNC(UCR_RNDV_TX),		\
	FUNC(UCR_RNDV_READ_DONE_WAIT),	\
	FUNC(UCR_RNDV_WRITE_DATA_WAIT),	\
	FUNC(UCR_RNDV_WRITE_DONE_WAIT),	\
	FUNC(UCR_RNDV_READ),		\
	FUNC(UCR_RNDV_WRITE), /* not used */ \
	FUNC(UCR_RNDV_READ_DONE_SENT),	\
	FUNC(UCR_RNDV_READ_DONE_RECVD),	\
	FUNC(UCR_RNDV_WRITE_DATA_SENT),	\
	FUNC(UCR_RNDV_WRITE_DATA_RECVD), /* not used */ \
	FUNC(UCR_RNDV_WRITE_DONE_SENT),	\
	FUNC(UCR_RNDV_WRITE_DONE_RECVD),\
	FUNC(UCR_RNDV_FINISH), /* not needed */	\
	FUNC(UCR_ATOMIC_RESP_WAIT),	\
	FUNC(UCR_ATOMIC_RESP_SENT)

enum ucr_proto_state {
	UCR_PROTO_STATES(OFI_ENUM_VAL)
};

extern char *ucr_proto_state_str[];

enum {
	ucr_ctrl_eager,
	ucr_ctrl_seg,
	ucr_ctrl_rndv_req,
	ucr_ctrl_rndv_rd_done,
	ucr_ctrl_atomic,
	ucr_ctrl_atomic_resp,
	ucr_ctrl_credit,
	ucr_ctrl_rndv_wr_data,
	ucr_ctrl_rndv_wr_done
};

struct ucr_pkt {
	struct ofi_ctrl_hdr ctrl_hdr;
	struct ofi_op_hdr hdr;
	char data[];
};

union ucr_sar_ctrl_data {
	struct {
		enum ucr_sar_seg_type {
			UCR_SAR_SEG_FIRST	= 1,
			UCR_SAR_SEG_MIDDLE	= 2,
			UCR_SAR_SEG_LAST	= 3,
		} seg_type : 2;
		uint32_t offset;
	};
	uint64_t align;
};

static inline enum ucr_sar_seg_type
ucr_sar_get_seg_type(struct ofi_ctrl_hdr *ctrl_hdr)
{
	return (uint8_t)((union ucr_sar_ctrl_data *)&(ctrl_hdr->ctrl_data))->seg_type & 0x3;
}

static inline void
ucr_sar_set_seg_type(struct ofi_ctrl_hdr *ctrl_hdr, enum ucr_sar_seg_type seg_type)
{
	((union ucr_sar_ctrl_data *)&(ctrl_hdr->ctrl_data))->seg_type = seg_type;
}

struct ucr_recv_match_attr {
	fi_addr_t addr;
	uint64_t tag;
	uint64_t ignore;
};

struct ucr_unexp_msg {
	struct dlist_entry entry;
	fi_addr_t addr;
	uint64_t tag;
};

struct ucr_iov {
	struct iovec iov[UCR_IOV_LIMIT];
	void *desc[UCR_IOV_LIMIT];
	uint8_t count;
};

struct ucr_buf {
	/* Must stay at top */
	struct fi_context fi_context;

	enum ucr_proto_state state;

	void *desc;
};

struct ucr_rx_buf {
	/* Must stay at top */
	struct ucr_buf hdr;

	struct ucr_ep *ep;
	/* MSG EP / shared context to which bufs would be posted to */
	struct fid_ep *rx_ep;
	struct dlist_entry repost_entry;
	struct ucr_conn *conn;		/* msg ep data was received on */
	struct ucr_recv_entry *recv_entry;
	struct ucr_unexp_msg unexp_msg;
	uint64_t comp_flags;
	struct fi_recv_context recv_context;
	bool repost;

	/* Used for large messages */
	struct dlist_entry rndv_wait_entry;
	struct ucr_rndv_hdr *remote_rndv_hdr;
	size_t rndv_rma_index;
	struct fid_mr *mr[UCR_IOV_LIMIT];

	/* Only differs from pkt.data for unexpected messages */
	void *data;
	/* Must stay at bottom */
	struct ucr_pkt pkt;
};

struct ucr_tx_buf {
	/* Must stay at top */
	struct ucr_buf hdr;

	OFI_DBG_VAR(bool, user_tx)
	void *app_context;
	uint64_t flags;

	union {
		struct {
			struct fid_mr *mr[UCR_IOV_LIMIT];
			uint8_t count;
		} rma;
		struct ucr_iov atomic_result;
	};

	struct {
		struct iovec iov[UCR_IOV_LIMIT];
		void *desc[UCR_IOV_LIMIT];
		struct ucr_conn *conn;
		size_t rndv_rma_index;
		size_t rndv_rma_count;
		struct ucr_tx_buf *done_buf;
		struct ucr_rndv_hdr remote_hdr;
	} write_rndv;

	/* Must stay at bottom */
	struct ucr_pkt pkt;
};

struct ucr_coll_buf {
	/* Must stay at top */
	struct ucr_buf hdr;

	struct ucr_ep *ep;
	void *app_context;
	uint64_t flags;
};

/* Used for application transmits, provides credit check */
struct ucr_tx_buf *ucr_get_tx_buf(struct ucr_ep *ep);
void ucr_free_tx_buf(struct ucr_ep *ep, struct ucr_tx_buf *buf);

/* Context for collective operations */
struct ucr_coll_buf *ucr_get_coll_buf(struct ucr_ep *ep);
void ucr_free_coll_buf(struct ucr_ep *ep, struct ucr_coll_buf *buf);

enum ucr_deferred_tx_entry_type {
	UCR_DEFERRED_TX_RNDV_ACK,
	UCR_DEFERRED_TX_RNDV_DONE,
	UCR_DEFERRED_TX_RNDV_READ,
	UCR_DEFERRED_TX_RNDV_WRITE,
	UCR_DEFERRED_TX_SAR_SEG,
	UCR_DEFERRED_TX_ATOMIC_RESP,
	UCR_DEFERRED_TX_CREDIT_SEND,
};

struct ucr_deferred_tx_entry {
	struct ucr_ep *ucr_ep;
	struct ucr_conn *ucr_conn;
	struct dlist_entry entry;
	enum ucr_deferred_tx_entry_type type;

	union {
		struct {
			struct ucr_rx_buf *rx_buf;
			size_t pkt_size;
		} rndv_ack;
		struct {
			struct ucr_tx_buf *tx_buf;
		} rndv_done;
		struct {
			struct ucr_rx_buf *rx_buf;
			struct fi_rma_iov rma_iov;
			struct ucr_iov ucr_iov;
		} rndv_read;
		struct {
			struct ucr_tx_buf *tx_buf;
			struct fi_rma_iov rma_iov;
			struct ucr_iov ucr_iov;
		} rndv_write;
		struct {
			struct ucr_tx_buf *cur_seg_tx_buf;
			struct {
				struct iovec iov[UCR_IOV_LIMIT];
				uint8_t count;
				size_t cur_iov_offset;
				uint64_t data;
				uint64_t tag;
			} payload;
			size_t next_seg_no;
			size_t segs_cnt;
			uint8_t op;
			size_t total_len;
			size_t remain_len;
			uint64_t msg_id;
			void *app_context;
			uint64_t flags;
			enum fi_hmem_iface iface;
			uint64_t device;
		} sar_seg;
		struct {
			struct ucr_tx_buf *tx_buf;
			ssize_t len;
		} atomic_resp;
		struct {
			struct ucr_tx_buf *tx_buf;
		} credit_msg;
	};
};

struct ucr_recv_entry {
	struct dlist_entry entry;
	struct ucr_iov ucr_iov;
	fi_addr_t addr;
	void *context;
	uint64_t flags;
	uint64_t tag;
	uint64_t ignore;
	uint64_t comp_flags;
	size_t total_len;
	struct ucr_recv_queue *recv_queue;

	/* Used for SAR protocol */
	struct {
		struct dlist_entry entry;
		size_t total_recv_len;
		struct ucr_conn *conn;
		uint64_t msg_id;
	} sar;
	/* Used for Rendezvous protocol */
	struct {
		/* This is used to send RNDV ACK */
		struct ucr_tx_buf *tx_buf;
	} rndv;
};
OFI_DECLARE_FREESTACK(struct ucr_recv_entry, ucr_recv_fs);

enum ucr_recv_queue_type {
	UCR_RECV_QUEUE_UNSPEC,
	UCR_RECV_QUEUE_MSG,
	UCR_RECV_QUEUE_TAGGED,
};

struct ucr_recv_queue {
	struct ucr_ep		*ucr_ep;
	enum ucr_recv_queue_type type;
	struct ucr_recv_fs	*fs;
	struct dlist_entry	recv_list;
	struct dlist_entry	unexp_msg_list;
	dlist_func_t		*match_recv;
	dlist_func_t		*match_unexp;
};

struct ucr_eager_ops {
	void (*comp_tx)(struct ucr_ep *ucr_ep,
			struct ucr_tx_buf *tx_eager_buf);
	void (*handle_rx)(struct ucr_rx_buf *rx_buf);
};

struct ucr_rndv_ops {
	int rx_mr_access;
	int tx_mr_access;
	ssize_t (*handle_rx)(struct ucr_rx_buf *rx_buf);
	ssize_t (*xfer)(struct fid_ep *ep, const struct iovec *iov, void **desc,
			size_t count, fi_addr_t remote_addr, uint64_t addr,
			uint64_t key, void *context);
	ssize_t (*defer_xfer)(struct ucr_deferred_tx_entry **def_tx_entry,
			      size_t index, struct iovec *iov,
			      void *desc[UCR_IOV_LIMIT], size_t count,
			      void *buf);
};

struct ucr_ep {
	struct util_ep 		util_ep;
	struct fi_info 		*ucr_info;
	struct fi_info 		*msg_info;

	int			connecting_cnt;
	struct index_map	conn_idx_map;
	struct dlist_entry	loopback_list;
	union ofi_sock_ip	addr;

	pthread_t		cm_thread;
	struct fid_pep 		*msg_pep;
	struct fid_eq 		*msg_eq;
	struct fid_ep 		*msg_srx;
	struct fid_ep		*util_coll_ep;
	struct fid_ep		*offload_coll_ep;
	struct fi_ops_transfer_peer *util_coll_peer_xfer_ops;
	struct fi_ops_transfer_peer *offload_coll_peer_xfer_ops;
	uint64_t		offload_coll_mask;

	struct fid_cq 		*msg_cq;
	uint64_t		msg_cq_last_poll;
	size_t 			comp_per_progress;
	size_t			cq_eq_fairness;
	void			(*handle_comp_error)(struct ucr_ep *ep);
	ssize_t			(*handle_comp)(struct ucr_ep *ep,
					       struct fi_cq_data_entry *comp);

	bool			msg_mr_local;
	bool			rdm_mr_local;
	bool			do_progress;
	bool			enable_direct_send;

	size_t			min_multi_recv_size;
	size_t			buffered_min;
	size_t			buffered_limit;
	size_t			inject_limit;

	size_t			eager_limit;
	size_t			sar_limit;
	size_t			tx_credit;

	struct ofi_bufpool	*rx_pool;
	struct ofi_bufpool	*tx_pool;
	struct ofi_bufpool	*coll_pool;
	struct ucr_pkt		*inject_pkt;

	struct dlist_entry	deferred_queue;
	struct dlist_entry	rndv_wait_list;

	struct ucr_recv_queue	recv_queue;
	struct ucr_recv_queue	trecv_queue;
	struct ofi_bufpool	*multi_recv_pool;

	struct ucr_eager_ops	*eager_ops;
	struct ucr_rndv_ops	*rndv_ops;

    struct ucr_rx_buf *rx_buf_cache;
};

int ucr_start_listen(struct ucr_ep *ep);
void ucr_stop_listen(struct ucr_ep *ep);
void ucr_conn_progress(struct ucr_ep *ep);


extern struct fi_provider ucr_prov;
extern struct fi_info ucr_thru_info;
extern struct fi_fabric_attr ucr_fabric_attr;

extern struct ucr_rndv_ops ucr_rndv_ops_read;
extern struct ucr_rndv_ops ucr_rndv_ops_write;

int ucr_fabric(struct fi_fabric_attr *attr, struct fid_fabric **fabric,
			void *context);
int ucr_info_to_core(uint32_t version, const struct fi_info *ucr_info,
		     const struct fi_info *base_info, struct fi_info *core_info);
int ucr_info_to_ucr(uint32_t version, const struct fi_info *core_info,
		     const struct fi_info *base_info, struct fi_info *info);
bool ucr_passthru_info(const struct fi_info *info);

int ucr_eq_open(struct fid_fabric *fabric_fid, struct fi_eq_attr *attr,
		struct fid_eq **eq_fid, void *context);

int ucr_domain_open(struct fid_fabric *fabric, struct fi_info *info,
			     struct fid_domain **dom, void *context);
int ucr_cq_open(struct fid_domain *domain, struct fi_cq_attr *attr,
			 struct fid_cq **cq_fid, void *context);
ssize_t ucr_handle_rx_buf(struct ucr_rx_buf *rx_buf);

int ucr_endpoint(struct fid_domain *domain, struct fi_info *info,
			  struct fid_ep **ep, void *context);

void ucr_cq_write_error(struct util_cq *cq, struct util_cntr *cntr,
			void *op_context, int err);
void ucr_cq_write_error_all(struct ucr_ep *ucr_ep, int err);
void ucr_handle_comp_error(struct ucr_ep *ucr_ep);
ssize_t ucr_handle_comp(struct ucr_ep *ucr_ep, struct fi_cq_data_entry *comp);
void ucr_thru_comp_error(struct ucr_ep *ucr_ep);
ssize_t ucr_thru_comp(struct ucr_ep *ucr_ep, struct fi_cq_data_entry *comp);
void ucr_ep_progress(struct util_ep *util_ep);
void ucr_ep_progress_coll(struct util_ep *util_ep);
void ucr_ep_do_progress(struct util_ep *util_ep);

void ucr_handle_eager(struct ucr_rx_buf *rx_buf);
void ucr_handle_coll_eager(struct ucr_rx_buf *rx_buf);
void ucr_finish_eager_send(struct ucr_ep *ucr_ep,
			   struct ucr_tx_buf *tx_eager_buf);
void ucr_finish_coll_eager_send(struct ucr_ep *ucr_ep,
				struct ucr_tx_buf *tx_eager_buf);

int ucr_prepost_recv(struct ucr_ep *ucr_ep, struct fid_ep *rx_ep);

int ucr_ep_query_atomic(struct fid_domain *domain, enum fi_datatype datatype,
			enum fi_op op, struct fi_atomic_attr *attr,
			uint64_t flags);
ssize_t ucr_rndv_read(struct ucr_rx_buf *rx_buf);
ssize_t ucr_rndv_send_wr_data(struct ucr_rx_buf *rx_buf);
void ucr_rndv_hdr_init(struct ucr_ep *ucr_ep, void *buf,
			      const struct iovec *iov, size_t count,
			      struct fid_mr **mr);

ssize_t ucr_copy_hmem(void *desc, char *host_buf, void *dev_buf, size_t size,
		      int dir);
ssize_t ucr_copy_hmem_iov(void **desc, char *buf, size_t buf_size,
			  const struct iovec *hmem_iov, int iov_count,
			  size_t iov_offset, int dir);
static inline ssize_t ucr_copy_from_hmem_iov(void **desc, char *buf,
					     size_t buf_size,
					     const struct iovec *hmem_iov,
					     int iov_count, size_t iov_offset)
{
	return ucr_copy_hmem_iov(desc, buf, buf_size, hmem_iov, iov_count,
				 iov_offset, OFI_COPY_IOV_TO_BUF);
}
static inline ssize_t ucr_copy_to_hmem_iov(void **desc, char *buf, int buf_size,
					   const struct iovec *hmem_iov,
					   int iov_count, size_t iov_offset)
{
	return ucr_copy_hmem_iov(desc, buf, buf_size, hmem_iov, iov_count,
				 iov_offset, OFI_COPY_BUF_TO_IOV);
}

static inline size_t ucr_ep_max_atomic_size(struct fi_info *info)
{
	assert(ucr_buffer_size >= sizeof(struct ucr_atomic_hdr));
	return ucr_buffer_size - sizeof(struct ucr_atomic_hdr);
}

static inline ssize_t
ucr_atomic_send_respmsg(struct ucr_ep *ucr_ep, struct ucr_conn *conn,
			struct ucr_tx_buf *resp_buf, ssize_t len)
{
	struct iovec iov = {
		.iov_base = (void *) &resp_buf->pkt,
		.iov_len = len,
	};
	struct fi_msg msg = {
		.msg_iov = &iov,
		.desc = &resp_buf->hdr.desc,
		.iov_count = 1,
		.context = resp_buf,
		.data = 0,
	};
	return fi_sendmsg(conn->msg_ep, &msg, FI_COMPLETION);
}

void ucr_ep_progress_deferred_queue(struct ucr_ep *ucr_ep,
				    struct ucr_conn *ucr_conn);

struct ucr_deferred_tx_entry *
ucr_ep_alloc_deferred_tx_entry(struct ucr_ep *ucr_ep, struct ucr_conn *ucr_conn,
			       enum ucr_deferred_tx_entry_type type);

static inline void
ucr_queue_deferred_tx(struct ucr_deferred_tx_entry *tx_entry,
		      enum ofi_list_end list_end)
{
	struct ucr_conn *conn = tx_entry->ucr_conn;

	if (dlist_empty(&conn->deferred_tx_queue))
		dlist_insert_tail(&conn->deferred_entry,
				  &conn->ep->deferred_queue);
	if (list_end == OFI_LIST_HEAD) {
		dlist_insert_head(&tx_entry->entry,
				  &conn->deferred_tx_queue);
	} else  {
		dlist_insert_tail(&tx_entry->entry,
				  &conn->deferred_tx_queue);
	}
}

static inline void
ucr_dequeue_deferred_tx(struct ucr_deferred_tx_entry *tx_entry)
{
	struct ucr_conn *conn = tx_entry->ucr_conn;

	assert(!dlist_empty(&conn->deferred_tx_queue));
	dlist_remove(&tx_entry->entry);
	if (dlist_empty(&conn->deferred_tx_queue))
		dlist_remove_init(&conn->deferred_entry);
}

int ucr_conn_process_eq_events(struct ucr_ep *ucr_ep);

void ucr_msg_mr_closev(struct fid_mr **mr, size_t count);
int ucr_msg_mr_regv(struct ucr_ep *ucr_ep, const struct iovec *iov,
		    size_t count, size_t reg_limit, uint64_t access,
		    struct fid_mr **mr);
int ucr_msg_mr_reg_internal(struct ucr_domain *ucr_domain, const void *buf,
			    size_t len, uint64_t acs, uint64_t flags,
			    struct fid_mr **mr);

static inline void ucr_cntr_incerr(struct util_cntr *cntr)
{
	if (cntr)
		cntr->cntr_fid.ops->adderr(&cntr->cntr_fid, 1);
}

static inline void
ucr_cq_write(struct util_cq *cq, void *context, uint64_t flags, size_t len,
	     void *buf, uint64_t data, uint64_t tag)
{
	int ret;

	FI_DBG(&ucr_prov, FI_LOG_CQ, "Reporting %s completion\n",
	       fi_tostr((void *) &flags, FI_TYPE_CQ_EVENT_FLAGS));

	ret = ofi_cq_write(cq, context, flags, len, buf, data, tag);
	if (ret) {
		FI_WARN(&ucr_prov, FI_LOG_CQ,
			"Unable to report completion\n");
		assert(0);
	}
	if (cq->wait)
		cq->wait->signal(cq->wait);
}

static inline void
ucr_cq_write_src(struct util_cq *cq, void *context, uint64_t flags, size_t len,
		 void *buf, uint64_t data, uint64_t tag, fi_addr_t addr)
{
	int ret;

	FI_DBG(&ucr_prov, FI_LOG_CQ, "Reporting %s completion\n",
	       fi_tostr((void *) &flags, FI_TYPE_CQ_EVENT_FLAGS));

	ret = ofi_cq_write_src(cq, context, flags, len, buf, data, tag, addr);
	if (ret) {
		FI_WARN(&ucr_prov, FI_LOG_CQ,
			"Unable to report completion\n");
		assert(0);
	}
	if (cq->wait)
		cq->wait->signal(cq->wait);
}

ssize_t ucr_get_conn(struct ucr_ep *ucr_ep, fi_addr_t addr,
		     struct ucr_conn **ucr_conn);

static inline void
ucr_ep_format_tx_buf_pkt(struct ucr_conn *ucr_conn, size_t len, uint8_t op,
			 uint64_t data, uint64_t tag, uint64_t flags,
			 struct ucr_pkt *pkt)
{
	pkt->ctrl_hdr.conn_id = ucr_conn->remote_index;
	pkt->hdr.size = len;
	pkt->hdr.op = op;
	pkt->hdr.tag = tag;
	pkt->hdr.flags = (flags & FI_REMOTE_CQ_DATA);
	pkt->hdr.data = data;
}

ssize_t
ucr_send_segment(struct ucr_ep *ucr_ep,
		 struct ucr_conn *ucr_conn, void *app_context, size_t data_len,
		 size_t remain_len, uint64_t msg_id, size_t seg_len,
		 size_t seg_no, size_t segs_cnt, uint64_t data, uint64_t flags,
		 uint64_t tag, uint8_t op, const struct iovec *iov,
		 uint8_t count, size_t *iov_offset,
		 struct ucr_tx_buf **out_tx_buf,
		 enum fi_hmem_iface iface, uint64_t device);
ssize_t
ucr_send_common(struct ucr_ep *ucr_ep, struct ucr_conn *ucr_conn,
		const struct iovec *iov, void **desc, size_t count,
		void *context, uint64_t data, uint64_t flags, uint64_t tag,
		uint8_t op);
ssize_t
ucr_inject_send(struct ucr_ep *ucr_ep, struct ucr_conn *ucr_conn,
		const void *buf, size_t len);

struct ucr_recv_entry *
ucr_recv_entry_get(struct ucr_ep *ucr_ep, const struct iovec *iov,
		   void **desc, size_t count, fi_addr_t src_addr,
		   uint64_t tag, uint64_t ignore, void *context,
		   uint64_t flags, struct ucr_recv_queue *recv_queue);
struct ucr_rx_buf *
ucr_get_unexp_msg(struct ucr_recv_queue *recv_queue, fi_addr_t addr,
		  uint64_t tag, uint64_t ignore);
ssize_t ucr_handle_unexp_sar(struct ucr_recv_queue *recv_queue,
			     struct ucr_recv_entry *recv_entry,
			     struct ucr_rx_buf *rx_buf);
int ucr_post_recv(struct ucr_rx_buf *rx_buf);
void ucr_av_remove_handler(struct util_ep *util_ep,
			   struct util_peer_addr *peer);

static inline void
ucr_free_rx_buf(struct ucr_rx_buf *rx_buf)
{
	if (rx_buf->data != rx_buf->pkt.data) {
		free(rx_buf->data);
		rx_buf->data = &rx_buf->pkt.data;
	}

	/* Discard rx buffer if its msg_ep was closed */
	if (rx_buf->repost && (rx_buf->ep->msg_srx || rx_buf->conn->msg_ep)) {
        /* If SRQ is enabled, don't post the receive buf now, this
         * can be posted while polling for the next transfer*/
        if (rx_buf->ep->msg_srx && rx_buf->ep->rx_buf_cache == NULL) {
            rx_buf->ep->rx_buf_cache = rx_buf;
        } else {
            ucr_post_recv(rx_buf);
        }
	} else {
		ofi_buf_free(rx_buf);
	}
}

static inline void
ucr_recv_entry_release(struct ucr_recv_entry *entry)
{
	if (entry->recv_queue)
		ofi_freestack_push(entry->recv_queue->fs, entry);
	else
		ofi_buf_free(entry);
}

static inline void
ucr_cq_write_recv_comp(struct ucr_rx_buf *rx_buf, void *context, uint64_t flags,
		       size_t len, char *buf)
{
	if (rx_buf->ep->util_coll_peer_xfer_ops &&
	    rx_buf->pkt.hdr.tag & UCR_PEER_XFER_TAG_FLAG) {
		struct fi_cq_tagged_entry cqe = {
			.tag = rx_buf->pkt.hdr.tag,
			.op_context = rx_buf->recv_entry->context,
		};
		rx_buf->ep->util_coll_peer_xfer_ops->
			complete(rx_buf->ep->util_coll_ep, &cqe, 0);
		return;
	}

	if (rx_buf->ep->ucr_info->caps & FI_SOURCE)
		ucr_cq_write_src(rx_buf->ep->util_ep.rx_cq, context,
				 flags, len, buf, rx_buf->pkt.hdr.data,
				 rx_buf->pkt.hdr.tag,
				 rx_buf->conn->peer->fi_addr);
	else
		ucr_cq_write(rx_buf->ep->util_ep.rx_cq, context,
			     flags, len, buf, rx_buf->pkt.hdr.data,
			     rx_buf->pkt.hdr.tag);
}

struct ucr_mr *ucr_mr_get_map_entry(struct ucr_domain *domain, uint64_t key);

struct ucr_recv_entry *
ucr_multi_recv_entry_get(struct ucr_ep *ucr_ep, const struct iovec *iov,
		   void **desc, size_t count, fi_addr_t src_addr,
		   uint64_t tag, uint64_t ignore, void *context,
		   uint64_t flags);
#endif
