/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "mpidimpl.h"
#include "ipc_pre.h"
#include "ipc_types.h"

int MPIDI_IPC_ack_target_msg_cb(void *am_hdr, void *data, MPI_Aint in_data_sz,
                                uint32_t attr, MPIR_Request ** req)
{
    int mpi_errno = MPI_SUCCESS;
    MPIDI_IPC_ack_t *hdr = am_hdr;
    MPIR_Request *sreq = hdr->req_ptr;

    MPIR_FUNC_ENTER;

    MPIR_Datatype_release_if_not_builtin(MPIDIG_REQUEST(sreq, datatype));
    if ((MPIDIG_REQUEST(sreq, req->status) & MPIDIG_REQ_RTS) &&
        MPIDIG_REQUEST(sreq, req->rreq.match_req) != NULL) {
        /* This block is executed only when the receive is enqueued (handoff) &&
         * receive was matched with an unexpected long RTS message.
         * `sreq` is the unexpected message received and `match_req` is the message
         * that came from CH4 (e.g. MPIDI_recv_safe) */
        MPIR_Request *match_req = MPIDIG_REQUEST(sreq, req->rreq.match_req);
        match_req->status = sreq->status;
        MPID_Request_complete(match_req);
        /* Free the unexpected request on behalf of the user */
        MPIDI_CH4_REQUEST_FREE(sreq);
    }
    MPID_Request_complete(sreq);

    if (attr & MPIDIG_AM_ATTR__IS_ASYNC) {
        *req = NULL;
    }

    MPIR_FUNC_EXIT;
    return mpi_errno;
}

int MPIDI_IPC_rndv_cb(MPIR_Request * rreq)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_FUNC_ENTER;

    MPI_Aint in_data_sz = MPIDIG_recv_in_data_sz(rreq);
    MPIR_Request *sreq_ptr = MPIDIG_REQUEST(rreq, req->rreq.peer_req_ptr);

    mpi_errno = MPIDI_IPCI_handle_lmt_recv(MPIDIG_REQUEST(rreq, rndv_hdr),
                                           in_data_sz, sreq_ptr, rreq);

    MPIR_FUNC_EXIT;
    return mpi_errno;
}

int MPIDI_IPC_complete(MPIR_Request * rreq, MPIDI_IPCI_type_t ipc_type)
{
    int mpi_errno = MPI_SUCCESS;

    MPIDI_IPC_ack_t am_hdr;
    am_hdr.ipc_type = ipc_type;
    am_hdr.req_ptr = MPIDIG_REQUEST(rreq, req->rreq.peer_req_ptr);

    int local_vci = MPIDIG_REQUEST(rreq, req->local_vci);
    int remote_vci = MPIDIG_REQUEST(rreq, req->remote_vci);
    CH4_CALL(am_send_hdr(rreq->status.MPI_SOURCE, rreq->comm, MPIDI_IPC_ACK,
                         &am_hdr, sizeof(am_hdr), local_vci, remote_vci), 1, mpi_errno);
    MPIR_ERR_CHECK(mpi_errno);

    if (MPIDIG_REQUEST(rreq, req->rreq.u.ipc.src_dt_ptr)) {
        MPIR_Datatype_free(MPIDIG_REQUEST(rreq, req->rreq.u.ipc.src_dt_ptr));
    }

    MPIDIG_REQUEST(rreq, req->target_cmpl_cb) (rreq);

  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIDI_IPC_remote_complete(MPIR_Request *rreq, MPIDI_IPCI_type_t ipc_type)
{
    int mpi_errno = MPI_SUCCESS;

    MPIDI_IPC_ack_t am_hdr;
    am_hdr.ipc_type = ipc_type;
    am_hdr.req_ptr = MPIDIG_REQUEST(rreq, req->rreq.peer_req_ptr);

    int local_vci = MPIDIG_REQUEST(rreq, req->local_vci);
    int remote_vci = MPIDIG_REQUEST(rreq, req->remote_vci);

    CH4_CALL(am_send_hdr(rreq->status.MPI_SOURCE, rreq->comm,
                         MPIDI_IPC_ACK, &am_hdr, sizeof(am_hdr), local_vci,
                         remote_vci),
             1, mpi_errno);
    MPIR_ERR_CHECK(mpi_errno);

    if (MPIDIG_REQUEST(rreq, req->rreq.u.ipc.src_dt_ptr)) {
        MPIR_Datatype_free(MPIDIG_REQUEST(rreq, req->rreq.u.ipc.src_dt_ptr));
    }

fn_exit:
    return mpi_errno;
fn_fail:
    goto fn_exit;
}

int MPIDI_IPC_rndv_cts_cb(void *am_hdr, void *data, MPI_Aint in_data_sz,
                          uint32_t attr, MPIR_Request **req)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Request *sreq = NULL;
    MPIDI_IPC_cts_t *hdr = (MPIDI_IPC_cts_t *)am_hdr;
    size_t data_sz;

    MPIR_FUNC_ENTER;

    sreq = (MPIR_Request *)hdr->sreq_ptr;
    MPIR_Assert(sreq != NULL);

    MPL_DBG_MSG_FMT(
        MPIDI_CH4_DBG_GENERAL, VERBOSE,
        (MPL_DBG_FDEST, "got ipc cts req handle=0x%x", sreq->handle));
    MPIDI_Datatype_check_size(MPIDIG_REQUEST(sreq, datatype),
                              MPIDIG_REQUEST(sreq, count), data_sz);

    mpi_errno = MPIDI_IPCI_handle_lmt_send(&(hdr->ipc_hdr), data_sz, sreq,
                                           hdr->rreq_ptr);
    MPIDIG_REQUEST(sreq, req->rreq.peer_req_ptr) = hdr->rreq_ptr;
    if ((MPIR_CVAR_CH4_IPC_RNDV_PROTOCOL ==
             MPIR_CVAR_CH4_IPC_RNDV_PROTOCOL_auto &&
             data_sz >= MPIR_CVAR_CH4_IPC_CMA_COOP_THRESHOLD) ||
        MPIR_CVAR_CH4_IPC_RNDV_PROTOCOL ==
            MPIR_CVAR_CH4_IPC_RNDV_PROTOCOL_coop ||
        MPIR_CVAR_CH4_IPC_RNDV_PROTOCOL ==
            MPIR_CVAR_CH4_IPC_RNDV_PROTOCOL_rput) {
        MPIDI_IPC_remote_complete(sreq, hdr->ipc_hdr.ipc_type);
        if (MPIR_CVAR_CH4_IPC_RNDV_PROTOCOL ==
            MPIR_CVAR_CH4_IPC_RNDV_PROTOCOL_rput) {
            MPID_Request_complete(sreq);
        }
    }

    MPIR_FUNC_EXIT;
    return mpi_errno;
}
