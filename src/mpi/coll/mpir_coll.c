/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"
#include "iallgatherv/iallgatherv.h"

/* ---- barrier ---- */

int MPIR_Barrier_allcomm_auto(MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__BARRIER,
        .comm_ptr = comm_ptr,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Barrier_intra_k_dissemination:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_barrier_intra_k_dissemination_call_counter, 1);
            mpi_errno = MPIR_Barrier_intra_k_dissemination(comm_ptr,
                                                           cnt->u.barrier.intra_k_dissemination.k,
                                                           errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Barrier_intra_recexch:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_barrier_intra_recexch_call_counter, 1);
            mpi_errno = MPIR_Barrier_intra_recexch(comm_ptr, cnt->u.barrier.intra_recexch.k,
                                                   cnt->u.barrier.intra_recexch.single_phase_recv,
                                                   errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Barrier_intra_smp:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_barrier_intra_smp_call_counter, 1);
            mpi_errno = MPIR_Barrier_intra_smp(comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Barrier_intra_osu_pairwise:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_barrier_intra_osu_pairwise_call_counter, 1);
            mpi_errno = MPIR_Barrier_intra_osu_pairwise(comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Barrier_inter_bcast:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_barrier_inter_bcast_call_counter, 1);
            mpi_errno = MPIR_Barrier_inter_bcast(comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Barrier_allcomm_nb:
           mpi_errno = MPIR_Barrier_allcomm_nb(comm_ptr, errflag);
           break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Barrier_impl(MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_BARRIER_INTRA_ALGORITHM) {
            case MPIR_CVAR_BARRIER_INTRA_ALGORITHM_k_dissemination:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_barrier_intra_k_dissemination_call_counter, 1);
                mpi_errno = MPIR_Barrier_intra_k_dissemination(comm_ptr, MPIR_CVAR_BARRIER_DISSEM_KVAL,
                                                               errflag);
                break;
            case MPIR_CVAR_BARRIER_INTRA_ALGORITHM_recexch:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_barrier_intra_recexch_call_counter, 1);
                mpi_errno = MPIR_Barrier_intra_recexch(comm_ptr, MPIR_CVAR_BARRIER_RECEXCH_KVAL,
                                                       MPIR_CVAR_BARRIER_RECEXCH_SINGLE_PHASE_RECV,
                                                       errflag);
                break;
            case MPIR_CVAR_BARRIER_INTRA_ALGORITHM_smp:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, MPIR_Comm_is_parent_comm(comm_ptr), mpi_errno,
                                               "Barrier smp cannot be applied.\n");
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_barrier_intra_smp_call_counter, 1);
                mpi_errno = MPIR_Barrier_intra_smp(comm_ptr, errflag);
                break;
            case MPIR_CVAR_BARRIER_INTRA_ALGORITHM_osu_pairwise:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_barrier_intra_osu_pairwise_call_counter, 1);
                mpi_errno = MPIR_Barrier_intra_osu_pairwise(comm_ptr, errflag);
                break;
            case MPIR_CVAR_BARRIER_INTRA_ALGORITHM_nb:
                mpi_errno = MPIR_Barrier_allcomm_nb(comm_ptr, errflag);
                 break;
            case MPIR_CVAR_BARRIER_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Barrier_allcomm_auto(comm_ptr, errflag);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        switch (MPIR_CVAR_BARRIER_INTER_ALGORITHM) {
            case MPIR_CVAR_BARRIER_INTER_ALGORITHM_bcast:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_barrier_inter_bcast_call_counter, 1);
                mpi_errno = MPIR_Barrier_inter_bcast(comm_ptr, errflag);
                break;
            case MPIR_CVAR_BARRIER_INTER_ALGORITHM_nb:
                mpi_errno = MPIR_Barrier_allcomm_nb(comm_ptr, errflag);
                 break;
            case MPIR_CVAR_BARRIER_INTER_ALGORITHM_auto:
                mpi_errno = MPIR_Barrier_allcomm_auto(comm_ptr, errflag);
                break;
            default:
                MPIR_Assert(0);
        }
    }
    MPIR_ERR_CHECK(mpi_errno);
    goto fn_exit;
    
  fallback:
    mpi_errno = MPIR_Barrier_allcomm_auto(comm_ptr, errflag);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Barrier(MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_barrier_call_counter, mvp_barrier_timer);
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_BARRIER_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Barrier(comm_ptr, errflag);
    } else {
        mpi_errno = MPIR_Barrier_impl(comm_ptr, errflag);
    }
    
    MVP_COLL_PVAR_UPDATE_END(mvp_barrier_timer);
    
    return mpi_errno;
}

/* ---- ibarrier ---- */

int MPIR_Ibarrier_allcomm_sched_auto(MPIR_Comm * comm_ptr, bool is_persistent, void **sched_p,
                                     enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__IBARRIER,
        .comm_ptr = comm_ptr,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ibarrier_intra_sched_recursive_doubling:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ibarrier_intra_sched_recursive_doubling_call_counter,
                                    1);
            mpi_errno = MPIR_Ibarrier_intra_sched_recursive_doubling(comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ibarrier_intra_tsp_recexch:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ibarrier_intra_tsp_recexch_call_counter, 1);
            mpi_errno = MPIR_TSP_Ibarrier_sched_intra_recexch(comm_ptr,
                                cnt->u.ibarrier.intra_tsp_recexch.k, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ibarrier_intra_tsp_k_dissemination:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ibarrier_intra_tsp_k_dissemination_call_counter, 1);
            mpi_errno = MPIR_TSP_Ibarrier_sched_intra_k_dissemination(comm_ptr,
                                cnt->u.ibarrier.intra_tsp_k_dissemination.k, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ibarrier_inter_sched_bcast:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ibarrier_inter_sched_bcast_call_counter, 1);
            mpi_errno = MPIR_Ibarrier_inter_sched_bcast(comm_ptr, *sched_p);
            break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ibarrier_sched_impl(MPIR_Comm * comm_ptr, bool is_persistent, void **sched_p,
                             enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_IBARRIER_INTRA_ALGORITHM) {
            case MPIR_CVAR_IBARRIER_INTRA_ALGORITHM_sched_recursive_doubling:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ibarrier_intra_sched_recursive_doubling_call_counter,
                                        1);
                mpi_errno = MPIR_Ibarrier_intra_sched_recursive_doubling(comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IBARRIER_INTRA_ALGORITHM_tsp_recexch:
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ibarrier_intra_tsp_recexch_call_counter, 1);
                mpi_errno = MPIR_TSP_Ibarrier_sched_intra_recexch(comm_ptr,
                                    MPIR_CVAR_IBARRIER_RECEXCH_KVAL, *sched_p);
                break;
            case MPIR_CVAR_IBARRIER_INTRA_ALGORITHM_tsp_k_dissemination:
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ibarrier_intra_tsp_k_dissemination_call_counter, 1);
                mpi_errno = MPIR_TSP_Ibarrier_sched_intra_k_dissemination(comm_ptr,
                                    MPIR_CVAR_IBARRIER_DISSEM_KVAL, *sched_p);
                break;
            case MPIR_CVAR_IBARRIER_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Ibarrier_allcomm_sched_auto(comm_ptr, is_persistent, sched_p,
                                sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        switch (MPIR_CVAR_IBARRIER_INTER_ALGORITHM) {
            case MPIR_CVAR_IBARRIER_INTER_ALGORITHM_sched_bcast:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ibarrier_inter_sched_bcast_call_counter, 1);
                mpi_errno = MPIR_Ibarrier_inter_sched_bcast(comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IBARRIER_INTER_ALGORITHM_auto:
                mpi_errno = MPIR_Ibarrier_allcomm_sched_auto(comm_ptr, is_persistent, sched_p,
                                sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    }
    MPIR_ERR_CHECK(mpi_errno);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ibarrier_impl(MPIR_Comm * comm_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    enum MPIR_sched_type sched_type;
    void *sched;
    
    *request = NULL;
    mpi_errno = MPIR_Ibarrier_sched_impl(comm_ptr, false, &sched, &sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    MPII_SCHED_START(sched_type, sched, comm_ptr, request);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ibarrier(MPIR_Comm * comm_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_ibarrier_call_counter, mvp_ibarrier_timer);
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_IBARRIER_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Ibarrier(comm_ptr, request);
    } else {
        mpi_errno = MPIR_Ibarrier_impl(comm_ptr, request);
    }
    
    MVP_COLL_PVAR_UPDATE_END(mvp_ibarrier_timer);
    
    return mpi_errno;
}

int MPIR_Barrier_init_impl(MPIR_Comm * comm_ptr, MPIR_Info * info_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Request *req = MPIR_Request_create(MPIR_REQUEST_KIND__PREQUEST_COLL);
    MPIR_ERR_CHKANDJUMP(!req, mpi_errno, MPI_ERR_OTHER, "**nomem");
    MPIR_Comm_add_ref(comm_ptr);
    req->comm = comm_ptr;
    MPIR_Comm_save_inactive_request(comm_ptr, req);
    req->u.persist_coll.sched_type = MPIR_SCHED_INVALID;
    req->u.persist_coll.real_request = NULL;
    mpi_errno = MPIR_Ibarrier_sched_impl(comm_ptr, true, &req->u.persist_coll.sched,
                                         &req->u.persist_coll.sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    
    *request = req;
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Barrier_init(MPIR_Comm * comm_ptr, MPIR_Info * info_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_BARRIER_INIT_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Barrier_init(comm_ptr, info_ptr, request);
    } else {
        mpi_errno = MPIR_Barrier_init_impl(comm_ptr, info_ptr, request);
    }
    
    return mpi_errno;
}

/* ---- bcast ---- */

int MPIR_Bcast_allcomm_auto(void *buffer, MPI_Aint count, MPI_Datatype datatype, int root,
                            MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__BCAST,
        .comm_ptr = comm_ptr,
        .u.bcast.buffer = buffer,
        .u.bcast.count = count,
        .u.bcast.datatype = datatype,
        .u.bcast.root = root,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Bcast_intra_binomial:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_bcast_intra_binomial_call_counter, 1);
            mpi_errno = MPIR_Bcast_intra_binomial(buffer, count, datatype, root, comm_ptr,
                                                  errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Bcast_intra_scatter_recursive_doubling_allgather:
            MPIR_T_PVAR_COUNTER_INC(MVP,
                                    mvp_bcast_intra_scatter_recursive_doubling_allgather_call_counter,
                                    1);
            mpi_errno = MPIR_Bcast_intra_scatter_recursive_doubling_allgather(buffer, count,
                                datatype, root, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Bcast_intra_scatter_ring_allgather:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_bcast_intra_scatter_ring_allgather_call_counter, 1);
            mpi_errno = MPIR_Bcast_intra_scatter_ring_allgather(buffer, count, datatype, root,
                                comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Bcast_intra_smp:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_bcast_intra_smp_call_counter, 1);
            mpi_errno = MPIR_Bcast_intra_smp(buffer, count, datatype, root, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Bcast_intra_tree:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_bcast_intra_tree_call_counter, 1);
            mpi_errno = MPIR_Bcast_intra_tree(buffer, count, datatype, root, comm_ptr,
                                              cnt->u.bcast.intra_tree.tree_type,
                                              cnt->u.bcast.intra_tree.k,
                                              cnt->u.bcast.intra_tree.is_non_blocking, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Bcast_intra_pipelined_tree:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_bcast_intra_pipelined_tree_call_counter, 1);
            mpi_errno = MPIR_Bcast_intra_pipelined_tree(buffer, count, datatype, root, comm_ptr,
                                                        cnt->u.bcast.intra_pipelined_tree.tree_type,
                                                        cnt->u.bcast.intra_pipelined_tree.k,
                                                        cnt->u.bcast.intra_pipelined_tree.is_non_blocking,
                                                        cnt->u.bcast.intra_pipelined_tree.chunk_size,
                                                        cnt->u.bcast.intra_pipelined_tree.recv_pre_posted,
                                                        errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Bcast_intra_osu_knomial:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_bcast_intra_osu_knomial_call_counter, 1);
            mpi_errno = MPIR_Bcast_intra_osu_knomial(buffer, count, datatype, root, comm_ptr,
                                                     cnt->u.bcast.intra_osu_knomial.inter_kf,
                                                     cnt->u.bcast.intra_osu_knomial.intra_kf,
                                                     errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Bcast_intra_osu_pipelined:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_bcast_intra_osu_pipelined_call_counter, 1);
            mpi_errno = MPIR_Bcast_intra_osu_pipelined(buffer, count, datatype, root, comm_ptr,
                                                       cnt->u.bcast.intra_osu_pipelined.seg_size,
                                                       errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Bcast_inter_remote_send_local_bcast:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_bcast_inter_remote_send_local_bcast_call_counter, 1);
            mpi_errno = MPIR_Bcast_inter_remote_send_local_bcast(buffer, count, datatype, root,
                                comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Bcast_allcomm_nb:
           mpi_errno = MPIR_Bcast_allcomm_nb(buffer, count, datatype, root, comm_ptr, errflag);
           break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Bcast_impl(void *buffer, MPI_Aint count, MPI_Datatype datatype, int root,
                    MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_BCAST_INTRA_ALGORITHM) {
            case MPIR_CVAR_BCAST_INTRA_ALGORITHM_binomial:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_bcast_intra_binomial_call_counter, 1);
                mpi_errno = MPIR_Bcast_intra_binomial(buffer, count, datatype, root, comm_ptr,
                                                      errflag);
                break;
            case MPIR_CVAR_BCAST_INTRA_ALGORITHM_scatter_recursive_doubling_allgather:
                MPIR_T_PVAR_COUNTER_INC(MVP,
                                        mvp_bcast_intra_scatter_recursive_doubling_allgather_call_counter,
                                        1);
                mpi_errno = MPIR_Bcast_intra_scatter_recursive_doubling_allgather(buffer, count,
                                    datatype, root, comm_ptr, errflag);
                break;
            case MPIR_CVAR_BCAST_INTRA_ALGORITHM_scatter_ring_allgather:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_bcast_intra_scatter_ring_allgather_call_counter, 1);
                mpi_errno = MPIR_Bcast_intra_scatter_ring_allgather(buffer, count, datatype, root,
                                    comm_ptr, errflag);
                break;
            case MPIR_CVAR_BCAST_INTRA_ALGORITHM_smp:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, MPIR_Comm_is_parent_comm(comm_ptr), mpi_errno,
                                               "Bcast smp cannot be applied.\n");
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_bcast_intra_smp_call_counter, 1);
                mpi_errno = MPIR_Bcast_intra_smp(buffer, count, datatype, root, comm_ptr, errflag);
                break;
            case MPIR_CVAR_BCAST_INTRA_ALGORITHM_tree:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_bcast_intra_tree_call_counter, 1);
                mpi_errno = MPIR_Bcast_intra_tree(buffer, count, datatype, root, comm_ptr,
                                                  MPIR_Bcast_tree_type, MPIR_CVAR_BCAST_TREE_KVAL,
                                                  MPIR_CVAR_BCAST_IS_NON_BLOCKING, errflag);
                break;
            case MPIR_CVAR_BCAST_INTRA_ALGORITHM_pipelined_tree:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_bcast_intra_pipelined_tree_call_counter, 1);
                mpi_errno = MPIR_Bcast_intra_pipelined_tree(buffer, count, datatype, root, comm_ptr,
                                                            MPIR_Bcast_tree_type,
                                                            MPIR_CVAR_BCAST_TREE_KVAL,
                                                            MPIR_CVAR_BCAST_IS_NON_BLOCKING,
                                                            MPIR_CVAR_BCAST_TREE_PIPELINE_CHUNK_SIZE,
                                                            MPIR_CVAR_BCAST_RECV_PRE_POST, errflag);
                break;
            case MPIR_CVAR_BCAST_INTRA_ALGORITHM_osu_knomial:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_bcast_intra_osu_knomial_call_counter, 1);
                mpi_errno = MPIR_Bcast_intra_osu_knomial(buffer, count, datatype, root, comm_ptr,
                                                         MPIR_CVAR_BCAST_INTER_KNOMIAL_FACTOR,
                                                         MPIR_CVAR_BCAST_INTRA_KNOMIAL_FACTOR,
                                                         errflag);
                break;
            case MPIR_CVAR_BCAST_INTRA_ALGORITHM_osu_pipelined:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_bcast_intra_osu_pipelined_call_counter, 1);
                mpi_errno = MPIR_Bcast_intra_osu_pipelined(buffer, count, datatype, root, comm_ptr,
                                                           MPIR_CVAR_BCAST_SEGMENT_SIZE, errflag);
                break;
            case MPIR_CVAR_BCAST_INTRA_ALGORITHM_nb:
                mpi_errno = MPIR_Bcast_allcomm_nb(buffer, count, datatype, root, comm_ptr,
                                                  errflag);
                 break;
            case MPIR_CVAR_BCAST_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Bcast_allcomm_auto(buffer, count, datatype, root, comm_ptr,
                                                    errflag);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        switch (MPIR_CVAR_BCAST_INTER_ALGORITHM) {
            case MPIR_CVAR_BCAST_INTER_ALGORITHM_remote_send_local_bcast:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_bcast_inter_remote_send_local_bcast_call_counter, 1);
                mpi_errno = MPIR_Bcast_inter_remote_send_local_bcast(buffer, count, datatype, root,
                                    comm_ptr, errflag);
                break;
            case MPIR_CVAR_BCAST_INTER_ALGORITHM_nb:
                mpi_errno = MPIR_Bcast_allcomm_nb(buffer, count, datatype, root, comm_ptr,
                                                  errflag);
                 break;
            case MPIR_CVAR_BCAST_INTER_ALGORITHM_auto:
                mpi_errno = MPIR_Bcast_allcomm_auto(buffer, count, datatype, root, comm_ptr,
                                                    errflag);
                break;
            default:
                MPIR_Assert(0);
        }
    }
    MPIR_ERR_CHECK(mpi_errno);
    goto fn_exit;
    
  fallback:
    mpi_errno = MPIR_Bcast_allcomm_auto(buffer, count, datatype, root, comm_ptr, errflag);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Bcast(void *buffer, MPI_Aint count, MPI_Datatype datatype, int root, MPIR_Comm * comm_ptr,
               MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_bcast_call_counter, mvp_bcast_timer);
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_BCAST_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Bcast(buffer, count, datatype, root, comm_ptr, errflag);
    } else {
        mpi_errno = MPIR_Bcast_impl(buffer, count, datatype, root, comm_ptr, errflag);
    }
    
    MVP_COLL_PVAR_UPDATE_END(mvp_bcast_timer);
    
    return mpi_errno;
}

/* ---- ibcast ---- */

int MPIR_Ibcast_allcomm_sched_auto(void *buffer, MPI_Aint count, MPI_Datatype datatype, int root,
                                   MPIR_Comm * comm_ptr, bool is_persistent, void **sched_p,
                                   enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__IBCAST,
        .comm_ptr = comm_ptr,
        .u.ibcast.buffer = buffer,
        .u.ibcast.count = count,
        .u.ibcast.datatype = datatype,
        .u.ibcast.root = root,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ibcast_intra_sched_binomial:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ibcast_intra_sched_binomial_call_counter, 1);
            mpi_errno = MPIR_Ibcast_intra_sched_binomial(buffer, count, datatype, root, comm_ptr,
                                                         *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ibcast_intra_sched_smp:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ibcast_intra_sched_smp_call_counter, 1);
            mpi_errno = MPIR_Ibcast_intra_sched_smp(buffer, count, datatype, root, comm_ptr,
                                                    *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ibcast_intra_sched_scatter_recursive_doubling_allgather:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP,
                                    mvp_ibcast_intra_sched_scatter_recursive_doubling_allgather_call_counter,
                                    1);
            mpi_errno = MPIR_Ibcast_intra_sched_scatter_recursive_doubling_allgather(buffer, count,
                                datatype, root, comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ibcast_intra_sched_scatter_ring_allgather:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ibcast_intra_sched_scatter_ring_allgather_call_counter,
                                    1);
            mpi_errno = MPIR_Ibcast_intra_sched_scatter_ring_allgather(buffer, count, datatype,
                                root, comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ibcast_intra_tsp_tree:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ibcast_intra_tsp_tree_call_counter, 1);
            mpi_errno = MPIR_TSP_Ibcast_sched_intra_tree(buffer, count, datatype, root, comm_ptr,
                                                         cnt->u.ibcast.intra_tsp_tree.tree_type,
                                                         cnt->u.ibcast.intra_tsp_tree.k,
                                                         cnt->u.ibcast.intra_tsp_tree.chunk_size,
                                                         *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ibcast_intra_tsp_scatterv_recexch_allgatherv:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP,
                                    mvp_ibcast_intra_tsp_scatterv_recexch_allgatherv_call_counter,
                                    1);
            mpi_errno = MPIR_TSP_Ibcast_sched_intra_scatterv_allgatherv(buffer, count, datatype,
                                root, comm_ptr,
                                MPIR_CVAR_IALLGATHERV_INTRA_ALGORITHM_tsp_recexch_doubling,
                                cnt->u.ibcast.intra_tsp_scatterv_recexch_allgatherv.scatterv_k,
                                cnt->u.ibcast.intra_tsp_scatterv_recexch_allgatherv.allgatherv_k,
                                *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ibcast_intra_tsp_scatterv_ring_allgatherv:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ibcast_intra_tsp_scatterv_ring_allgatherv_call_counter,
                                    1);
            mpi_errno = MPIR_TSP_Ibcast_sched_intra_scatterv_ring_allgatherv(buffer, count,
                                datatype, root, comm_ptr,
                                cnt->u.ibcast.intra_tsp_scatterv_ring_allgatherv.scatterv_k,
                                *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ibcast_intra_tsp_ring:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ibcast_intra_tsp_ring_call_counter, 1);
            mpi_errno = MPIR_TSP_Ibcast_sched_intra_tree(buffer, count, datatype, root, comm_ptr,
                                                         MPIR_TREE_TYPE_KARY, 1,
                                                         cnt->u.ibcast.intra_tsp_ring.chunk_size,
                                                         *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ibcast_inter_sched_flat:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ibcast_inter_sched_flat_call_counter, 1);
            mpi_errno = MPIR_Ibcast_inter_sched_flat(buffer, count, datatype, root, comm_ptr,
                                                     *sched_p);
            break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ibcast_sched_impl(void *buffer, MPI_Aint count, MPI_Datatype datatype, int root,
                           MPIR_Comm * comm_ptr, bool is_persistent, void **sched_p,
                           enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_IBCAST_INTRA_ALGORITHM) {
            case MPIR_CVAR_IBCAST_INTRA_ALGORITHM_sched_binomial:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ibcast_intra_sched_binomial_call_counter, 1);
                mpi_errno = MPIR_Ibcast_intra_sched_binomial(buffer, count, datatype, root, comm_ptr,
                                                             *sched_p);
                break;
            case MPIR_CVAR_IBCAST_INTRA_ALGORITHM_sched_smp:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, MPIR_Comm_is_parent_comm(comm_ptr), mpi_errno,
                                               "Ibcast sched_smp cannot be applied.\n");
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ibcast_intra_sched_smp_call_counter, 1);
                mpi_errno = MPIR_Ibcast_intra_sched_smp(buffer, count, datatype, root, comm_ptr,
                                                        *sched_p);
                break;
            case MPIR_CVAR_IBCAST_INTRA_ALGORITHM_sched_scatter_recursive_doubling_allgather:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, comm_ptr->local_size == comm_ptr->coll.pof2, mpi_errno,
                                               "Ibcast sched_scatter_recursive_doubling_allgather cannot be applied.\n");
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP,
                                        mvp_ibcast_intra_sched_scatter_recursive_doubling_allgather_call_counter,
                                        1);
                mpi_errno = MPIR_Ibcast_intra_sched_scatter_recursive_doubling_allgather(buffer, count,
                                    datatype, root, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IBCAST_INTRA_ALGORITHM_sched_scatter_ring_allgather:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ibcast_intra_sched_scatter_ring_allgather_call_counter,
                                        1);
                mpi_errno = MPIR_Ibcast_intra_sched_scatter_ring_allgather(buffer, count, datatype,
                                    root, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IBCAST_INTRA_ALGORITHM_tsp_tree:
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ibcast_intra_tsp_tree_call_counter, 1);
                mpi_errno = MPIR_TSP_Ibcast_sched_intra_tree(buffer, count, datatype, root, comm_ptr,
                                                             MPIR_Ibcast_tree_type,
                                                             MPIR_CVAR_IBCAST_TREE_KVAL,
                                                             MPIR_CVAR_IBCAST_TREE_PIPELINE_CHUNK_SIZE,
                                                             *sched_p);
                break;
            case MPIR_CVAR_IBCAST_INTRA_ALGORITHM_tsp_scatterv_recexch_allgatherv:
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP,
                                        mvp_ibcast_intra_tsp_scatterv_recexch_allgatherv_call_counter,
                                        1);
                mpi_errno = MPIR_TSP_Ibcast_sched_intra_scatterv_allgatherv(buffer, count, datatype,
                                    root, comm_ptr,
                                    MPIR_CVAR_IALLGATHERV_INTRA_ALGORITHM_tsp_recexch_doubling,
                                    MPIR_CVAR_IBCAST_SCATTERV_KVAL,
                                    MPIR_CVAR_IBCAST_ALLGATHERV_RECEXCH_KVAL, *sched_p);
                break;
            case MPIR_CVAR_IBCAST_INTRA_ALGORITHM_tsp_scatterv_ring_allgatherv:
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ibcast_intra_tsp_scatterv_ring_allgatherv_call_counter,
                                        1);
                mpi_errno = MPIR_TSP_Ibcast_sched_intra_scatterv_ring_allgatherv(buffer, count,
                                    datatype, root, comm_ptr, MPIR_CVAR_IBCAST_SCATTERV_KVAL,
                                    *sched_p);
                break;
            case MPIR_CVAR_IBCAST_INTRA_ALGORITHM_tsp_ring:
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ibcast_intra_tsp_ring_call_counter, 1);
                mpi_errno = MPIR_TSP_Ibcast_sched_intra_tree(buffer, count, datatype, root, comm_ptr,
                                                             MPIR_TREE_TYPE_KARY, 1,
                                                             MPIR_CVAR_IBCAST_RING_CHUNK_SIZE,
                                                             *sched_p);
                break;
            case MPIR_CVAR_IBCAST_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Ibcast_allcomm_sched_auto(buffer, count, datatype, root, comm_ptr,
                                                           is_persistent, sched_p, sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        switch (MPIR_CVAR_IBCAST_INTER_ALGORITHM) {
            case MPIR_CVAR_IBCAST_INTER_ALGORITHM_sched_flat:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ibcast_inter_sched_flat_call_counter, 1);
                mpi_errno = MPIR_Ibcast_inter_sched_flat(buffer, count, datatype, root, comm_ptr,
                                                         *sched_p);
                break;
            case MPIR_CVAR_IBCAST_INTER_ALGORITHM_auto:
                mpi_errno = MPIR_Ibcast_allcomm_sched_auto(buffer, count, datatype, root, comm_ptr,
                                                           is_persistent, sched_p, sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    }
    MPIR_ERR_CHECK(mpi_errno);
    goto fn_exit;
    
  fallback:
    mpi_errno = MPIR_Ibcast_allcomm_sched_auto(buffer, count, datatype, root, comm_ptr,
                                               is_persistent, sched_p, sched_type_p);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ibcast_impl(void *buffer, MPI_Aint count, MPI_Datatype datatype, int root,
                     MPIR_Comm * comm_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    enum MPIR_sched_type sched_type;
    void *sched;
    
    *request = NULL;
    mpi_errno = MPIR_Ibcast_sched_impl(buffer, count, datatype, root, comm_ptr, false, &sched,
                                       &sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    MPII_SCHED_START(sched_type, sched, comm_ptr, request);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ibcast(void *buffer, MPI_Aint count, MPI_Datatype datatype, int root, MPIR_Comm * comm_ptr,
                MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_ibcast_call_counter, mvp_ibcast_timer);
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_IBCAST_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Ibcast(buffer, count, datatype, root, comm_ptr, request);
    } else {
        mpi_errno = MPIR_Ibcast_impl(buffer, count, datatype, root, comm_ptr, request);
    }
    
    MVP_COLL_PVAR_UPDATE_END(mvp_ibcast_timer);
    
    return mpi_errno;
}

int MPIR_Bcast_init_impl(void *buffer, MPI_Aint count, MPI_Datatype datatype, int root,
                         MPIR_Comm * comm_ptr, MPIR_Info * info_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Request *req = MPIR_Request_create(MPIR_REQUEST_KIND__PREQUEST_COLL);
    MPIR_ERR_CHKANDJUMP(!req, mpi_errno, MPI_ERR_OTHER, "**nomem");
    MPIR_Comm_add_ref(comm_ptr);
    req->comm = comm_ptr;
    MPIR_Comm_save_inactive_request(comm_ptr, req);
    req->u.persist_coll.sched_type = MPIR_SCHED_INVALID;
    req->u.persist_coll.real_request = NULL;
    mpi_errno = MPIR_Ibcast_sched_impl(buffer, count, datatype, root, comm_ptr, true,
                                       &req->u.persist_coll.sched,
                                       &req->u.persist_coll.sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    
    *request = req;
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Bcast_init(void *buffer, MPI_Aint count, MPI_Datatype datatype, int root,
                    MPIR_Comm * comm_ptr, MPIR_Info * info_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_BCAST_INIT_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Bcast_init(buffer, count, datatype, root, comm_ptr, info_ptr, request);
    } else {
        mpi_errno = MPIR_Bcast_init_impl(buffer, count, datatype, root, comm_ptr, info_ptr,
                                         request);
    }
    
    return mpi_errno;
}

/* ---- gather ---- */

int MPIR_Gather_allcomm_auto(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                             void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype, int root,
                             MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__GATHER,
        .comm_ptr = comm_ptr,
        .u.gather.sendbuf = sendbuf,
        .u.gather.sendcount = sendcount,
        .u.gather.sendtype = sendtype,
        .u.gather.recvbuf = recvbuf,
        .u.gather.recvcount = recvcount,
        .u.gather.recvtype = recvtype,
        .u.gather.root = root,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Gather_intra_binomial:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_gather_intra_binomial_call_counter, 1);
            mpi_errno = MPIR_Gather_intra_binomial(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                                   recvtype, root, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Gather_intra_osu_direct:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_gather_intra_osu_direct_call_counter, 1);
            mpi_errno = MPIR_Gather_intra_osu_direct(sendbuf, sendcount, sendtype, recvbuf,
                                                     recvcount, recvtype, root, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Gather_intra_osu_direct_block:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_gather_intra_osu_direct_block_call_counter, 1);
            mpi_errno = MPIR_Gather_intra_osu_direct_block(sendbuf, sendcount, sendtype, recvbuf,
                                                           recvcount, recvtype, root, comm_ptr,
                                                           errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Gather_inter_linear:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_gather_inter_linear_call_counter, 1);
            mpi_errno = MPIR_Gather_inter_linear(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                                 recvtype, root, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Gather_inter_local_gather_remote_send:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_gather_inter_local_gather_remote_send_call_counter,
                                    1);
            mpi_errno = MPIR_Gather_inter_local_gather_remote_send(sendbuf, sendcount, sendtype,
                                recvbuf, recvcount, recvtype, root, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Gather_allcomm_nb:
           mpi_errno = MPIR_Gather_allcomm_nb(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                              recvtype, root, comm_ptr, errflag);
           break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Gather_impl(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                     MPI_Aint recvcount, MPI_Datatype recvtype, int root, MPIR_Comm * comm_ptr,
                     MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_GATHER_INTRA_ALGORITHM) {
            case MPIR_CVAR_GATHER_INTRA_ALGORITHM_binomial:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_gather_intra_binomial_call_counter, 1);
                mpi_errno = MPIR_Gather_intra_binomial(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                                       recvtype, root, comm_ptr, errflag);
                break;
            case MPIR_CVAR_GATHER_INTRA_ALGORITHM_osu_direct:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_gather_intra_osu_direct_call_counter, 1);
                mpi_errno = MPIR_Gather_intra_osu_direct(sendbuf, sendcount, sendtype, recvbuf,
                                                         recvcount, recvtype, root, comm_ptr, errflag);
                break;
            case MPIR_CVAR_GATHER_INTRA_ALGORITHM_osu_direct_block:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_gather_intra_osu_direct_block_call_counter, 1);
                mpi_errno = MPIR_Gather_intra_osu_direct_block(sendbuf, sendcount, sendtype, recvbuf,
                                                               recvcount, recvtype, root, comm_ptr,
                                                               errflag);
                break;
            case MPIR_CVAR_GATHER_INTRA_ALGORITHM_nb:
                mpi_errno = MPIR_Gather_allcomm_nb(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                                   recvtype, root, comm_ptr, errflag);
                 break;
            case MPIR_CVAR_GATHER_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Gather_allcomm_auto(sendbuf, sendcount, sendtype, recvbuf,
                                                     recvcount, recvtype, root, comm_ptr, errflag);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        switch (MPIR_CVAR_GATHER_INTER_ALGORITHM) {
            case MPIR_CVAR_GATHER_INTER_ALGORITHM_linear:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_gather_inter_linear_call_counter, 1);
                mpi_errno = MPIR_Gather_inter_linear(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                                     recvtype, root, comm_ptr, errflag);
                break;
            case MPIR_CVAR_GATHER_INTER_ALGORITHM_local_gather_remote_send:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_gather_inter_local_gather_remote_send_call_counter,
                                        1);
                mpi_errno = MPIR_Gather_inter_local_gather_remote_send(sendbuf, sendcount, sendtype,
                                    recvbuf, recvcount, recvtype, root, comm_ptr, errflag);
                break;
            case MPIR_CVAR_GATHER_INTER_ALGORITHM_nb:
                mpi_errno = MPIR_Gather_allcomm_nb(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                                   recvtype, root, comm_ptr, errflag);
                 break;
            case MPIR_CVAR_GATHER_INTER_ALGORITHM_auto:
                mpi_errno = MPIR_Gather_allcomm_auto(sendbuf, sendcount, sendtype, recvbuf,
                                                     recvcount, recvtype, root, comm_ptr, errflag);
                break;
            default:
                MPIR_Assert(0);
        }
    }
    MPIR_ERR_CHECK(mpi_errno);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Gather(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                MPI_Aint recvcount, MPI_Datatype recvtype, int root, MPIR_Comm * comm_ptr,
                MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_gather_call_counter, mvp_gather_timer);
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_GATHER_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Gather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root,
                                comm_ptr, errflag);
    } else {
        mpi_errno = MPIR_Gather_impl(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                                     root, comm_ptr, errflag);
    }
    
    MVP_COLL_PVAR_UPDATE_END(mvp_gather_timer);
    
    return mpi_errno;
}

/* ---- igather ---- */

int MPIR_Igather_allcomm_sched_auto(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                                    void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                                    int root, MPIR_Comm * comm_ptr, bool is_persistent,
                                    void **sched_p, enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__IGATHER,
        .comm_ptr = comm_ptr,
        .u.igather.sendbuf = sendbuf,
        .u.igather.sendcount = sendcount,
        .u.igather.sendtype = sendtype,
        .u.igather.recvbuf = recvbuf,
        .u.igather.recvcount = recvcount,
        .u.igather.recvtype = recvtype,
        .u.igather.root = root,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Igather_intra_sched_binomial:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_igather_intra_sched_binomial_call_counter, 1);
            mpi_errno = MPIR_Igather_intra_sched_binomial(sendbuf, sendcount, sendtype, recvbuf,
                                                          recvcount, recvtype, root, comm_ptr,
                                                          *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Igather_intra_tsp_tree:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_igather_intra_tsp_tree_call_counter, 1);
            mpi_errno = MPIR_TSP_Igather_sched_intra_tree(sendbuf, sendcount, sendtype, recvbuf,
                                                          recvcount, recvtype, root, comm_ptr,
                                                          cnt->u.igather.intra_tsp_tree.k,
                                                          *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Igather_inter_sched_long:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_igather_inter_sched_long_call_counter, 1);
            mpi_errno = MPIR_Igather_inter_sched_long(sendbuf, sendcount, sendtype, recvbuf,
                                                      recvcount, recvtype, root, comm_ptr,
                                                      *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Igather_inter_sched_short:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_igather_inter_sched_short_call_counter, 1);
            mpi_errno = MPIR_Igather_inter_sched_short(sendbuf, sendcount, sendtype, recvbuf,
                                                       recvcount, recvtype, root, comm_ptr,
                                                       *sched_p);
            break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Igather_sched_impl(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                            void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype, int root,
                            MPIR_Comm * comm_ptr, bool is_persistent, void **sched_p,
                            enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_IGATHER_INTRA_ALGORITHM) {
            case MPIR_CVAR_IGATHER_INTRA_ALGORITHM_sched_binomial:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_igather_intra_sched_binomial_call_counter, 1);
                mpi_errno = MPIR_Igather_intra_sched_binomial(sendbuf, sendcount, sendtype, recvbuf,
                                                              recvcount, recvtype, root, comm_ptr,
                                                              *sched_p);
                break;
            case MPIR_CVAR_IGATHER_INTRA_ALGORITHM_tsp_tree:
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_igather_intra_tsp_tree_call_counter, 1);
                mpi_errno = MPIR_TSP_Igather_sched_intra_tree(sendbuf, sendcount, sendtype, recvbuf,
                                                              recvcount, recvtype, root, comm_ptr,
                                                              MPIR_CVAR_IGATHER_TREE_KVAL, *sched_p);
                break;
            case MPIR_CVAR_IGATHER_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Igather_allcomm_sched_auto(sendbuf, sendcount, sendtype, recvbuf,
                                                            recvcount, recvtype, root, comm_ptr,
                                                            is_persistent, sched_p, sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        switch (MPIR_CVAR_IGATHER_INTER_ALGORITHM) {
            case MPIR_CVAR_IGATHER_INTER_ALGORITHM_sched_long:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_igather_inter_sched_long_call_counter, 1);
                mpi_errno = MPIR_Igather_inter_sched_long(sendbuf, sendcount, sendtype, recvbuf,
                                                          recvcount, recvtype, root, comm_ptr,
                                                          *sched_p);
                break;
            case MPIR_CVAR_IGATHER_INTER_ALGORITHM_sched_short:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_igather_inter_sched_short_call_counter, 1);
                mpi_errno = MPIR_Igather_inter_sched_short(sendbuf, sendcount, sendtype, recvbuf,
                                                           recvcount, recvtype, root, comm_ptr,
                                                           *sched_p);
                break;
            case MPIR_CVAR_IGATHER_INTER_ALGORITHM_auto:
                mpi_errno = MPIR_Igather_allcomm_sched_auto(sendbuf, sendcount, sendtype, recvbuf,
                                                            recvcount, recvtype, root, comm_ptr,
                                                            is_persistent, sched_p, sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    }
    MPIR_ERR_CHECK(mpi_errno);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Igather_impl(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                      MPI_Aint recvcount, MPI_Datatype recvtype, int root, MPIR_Comm * comm_ptr,
                      MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    enum MPIR_sched_type sched_type;
    void *sched;
    
    *request = NULL;
    mpi_errno = MPIR_Igather_sched_impl(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                                        root, comm_ptr, false, &sched, &sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    MPII_SCHED_START(sched_type, sched, comm_ptr, request);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Igather(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                 MPI_Aint recvcount, MPI_Datatype recvtype, int root, MPIR_Comm * comm_ptr,
                 MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_igather_call_counter, mvp_igather_timer);
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_IGATHER_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Igather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root,
                                 comm_ptr, request);
    } else {
        mpi_errno = MPIR_Igather_impl(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                                      root, comm_ptr, request);
    }
    
    MVP_COLL_PVAR_UPDATE_END(mvp_igather_timer);
    
    return mpi_errno;
}

int MPIR_Gather_init_impl(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                          void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype, int root,
                          MPIR_Comm * comm_ptr, MPIR_Info * info_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Request *req = MPIR_Request_create(MPIR_REQUEST_KIND__PREQUEST_COLL);
    MPIR_ERR_CHKANDJUMP(!req, mpi_errno, MPI_ERR_OTHER, "**nomem");
    MPIR_Comm_add_ref(comm_ptr);
    req->comm = comm_ptr;
    MPIR_Comm_save_inactive_request(comm_ptr, req);
    req->u.persist_coll.sched_type = MPIR_SCHED_INVALID;
    req->u.persist_coll.real_request = NULL;
    mpi_errno = MPIR_Igather_sched_impl(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                                        root, comm_ptr, true, &req->u.persist_coll.sched,
                                        &req->u.persist_coll.sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    
    *request = req;
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Gather_init(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                     MPI_Aint recvcount, MPI_Datatype recvtype, int root, MPIR_Comm * comm_ptr,
                     MPIR_Info * info_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_GATHER_INIT_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Gather_init(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                                     root, comm_ptr, info_ptr, request);
    } else {
        mpi_errno = MPIR_Gather_init_impl(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                          recvtype, root, comm_ptr, info_ptr, request);
    }
    
    return mpi_errno;
}

/* ---- gatherv ---- */

int MPIR_Gatherv_allcomm_auto(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                              void *recvbuf, const MPI_Aint recvcounts[], const MPI_Aint displs[],
                              MPI_Datatype recvtype, int root, MPIR_Comm * comm_ptr,
                              MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__GATHERV,
        .comm_ptr = comm_ptr,
        .u.gatherv.sendbuf = sendbuf,
        .u.gatherv.sendcount = sendcount,
        .u.gatherv.sendtype = sendtype,
        .u.gatherv.recvbuf = recvbuf,
        .u.gatherv.recvcounts = recvcounts,
        .u.gatherv.displs = displs,
        .u.gatherv.recvtype = recvtype,
        .u.gatherv.root = root,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Gatherv_allcomm_linear:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_gatherv_intra_linear_call_counter, 1);
            mpi_errno = MPIR_Gatherv_allcomm_linear(sendbuf, sendcount, sendtype, recvbuf,
                                                    recvcounts, displs, recvtype, root, comm_ptr,
                                                    errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Gatherv_allcomm_nb:
           mpi_errno = MPIR_Gatherv_allcomm_nb(sendbuf, sendcount, sendtype, recvbuf, recvcounts,
                                               displs, recvtype, root, comm_ptr, errflag);
           break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Gatherv_impl(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                      const MPI_Aint recvcounts[], const MPI_Aint displs[], MPI_Datatype recvtype,
                      int root, MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_GATHERV_INTRA_ALGORITHM) {
            case MPIR_CVAR_GATHERV_INTRA_ALGORITHM_linear:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_gatherv_intra_linear_call_counter, 1);
                mpi_errno = MPIR_Gatherv_allcomm_linear(sendbuf, sendcount, sendtype, recvbuf,
                                                        recvcounts, displs, recvtype, root, comm_ptr,
                                                        errflag);
                break;
            case MPIR_CVAR_GATHERV_INTRA_ALGORITHM_nb:
                mpi_errno = MPIR_Gatherv_allcomm_nb(sendbuf, sendcount, sendtype, recvbuf,
                                                    recvcounts, displs, recvtype, root, comm_ptr,
                                                    errflag);
                 break;
            case MPIR_CVAR_GATHERV_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Gatherv_allcomm_auto(sendbuf, sendcount, sendtype, recvbuf,
                                                      recvcounts, displs, recvtype, root, comm_ptr,
                                                      errflag);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        switch (MPIR_CVAR_GATHERV_INTER_ALGORITHM) {
            case MPIR_CVAR_GATHERV_INTER_ALGORITHM_linear:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_gatherv_inter_linear_call_counter, 1);
                mpi_errno = MPIR_Gatherv_allcomm_linear(sendbuf, sendcount, sendtype, recvbuf,
                                                        recvcounts, displs, recvtype, root, comm_ptr,
                                                        errflag);
                break;
            case MPIR_CVAR_GATHERV_INTER_ALGORITHM_nb:
                mpi_errno = MPIR_Gatherv_allcomm_nb(sendbuf, sendcount, sendtype, recvbuf,
                                                    recvcounts, displs, recvtype, root, comm_ptr,
                                                    errflag);
                 break;
            case MPIR_CVAR_GATHERV_INTER_ALGORITHM_auto:
                mpi_errno = MPIR_Gatherv_allcomm_auto(sendbuf, sendcount, sendtype, recvbuf,
                                                      recvcounts, displs, recvtype, root, comm_ptr,
                                                      errflag);
                break;
            default:
                MPIR_Assert(0);
        }
    }
    MPIR_ERR_CHECK(mpi_errno);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Gatherv(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                 const MPI_Aint recvcounts[], const MPI_Aint displs[], MPI_Datatype recvtype,
                 int root, MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_gatherv_call_counter, mvp_gatherv_timer);
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_GATHERV_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Gatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs,
                                 recvtype, root, comm_ptr, errflag);
    } else {
        mpi_errno = MPIR_Gatherv_impl(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs,
                                      recvtype, root, comm_ptr, errflag);
    }
    
    MVP_COLL_PVAR_UPDATE_END(mvp_gatherv_timer);
    
    return mpi_errno;
}

/* ---- igatherv ---- */

int MPIR_Igatherv_allcomm_sched_auto(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                                     void *recvbuf, const MPI_Aint recvcounts[],
                                     const MPI_Aint displs[], MPI_Datatype recvtype, int root,
                                     MPIR_Comm * comm_ptr, bool is_persistent, void **sched_p,
                                     enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__IGATHERV,
        .comm_ptr = comm_ptr,
        .u.igatherv.sendbuf = sendbuf,
        .u.igatherv.sendcount = sendcount,
        .u.igatherv.sendtype = sendtype,
        .u.igatherv.recvbuf = recvbuf,
        .u.igatherv.recvcounts = recvcounts,
        .u.igatherv.displs = displs,
        .u.igatherv.recvtype = recvtype,
        .u.igatherv.root = root,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Igatherv_allcomm_sched_linear:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_igatherv_intra_sched_linear_call_counter, 1);
            mpi_errno = MPIR_Igatherv_allcomm_sched_linear(sendbuf, sendcount, sendtype, recvbuf,
                                                           recvcounts, displs, recvtype, root,
                                                           comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Igatherv_allcomm_tsp_linear:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_igatherv_intra_tsp_linear_call_counter, 1);
            mpi_errno = MPIR_TSP_Igatherv_sched_allcomm_linear(sendbuf, sendcount, sendtype,
                                recvbuf, recvcounts, displs, recvtype, root, comm_ptr, *sched_p);
            break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Igatherv_sched_impl(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                             void *recvbuf, const MPI_Aint recvcounts[], const MPI_Aint displs[],
                             MPI_Datatype recvtype, int root, MPIR_Comm * comm_ptr,
                             bool is_persistent, void **sched_p,
                             enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_IGATHERV_INTRA_ALGORITHM) {
            case MPIR_CVAR_IGATHERV_INTRA_ALGORITHM_sched_linear:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_igatherv_intra_sched_linear_call_counter, 1);
                mpi_errno = MPIR_Igatherv_allcomm_sched_linear(sendbuf, sendcount, sendtype, recvbuf,
                                                               recvcounts, displs, recvtype, root,
                                                               comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IGATHERV_INTRA_ALGORITHM_tsp_linear:
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_igatherv_intra_tsp_linear_call_counter, 1);
                mpi_errno = MPIR_TSP_Igatherv_sched_allcomm_linear(sendbuf, sendcount, sendtype,
                                    recvbuf, recvcounts, displs, recvtype, root, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IGATHERV_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Igatherv_allcomm_sched_auto(sendbuf, sendcount, sendtype, recvbuf,
                                recvcounts, displs, recvtype, root, comm_ptr, is_persistent,
                                sched_p, sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        switch (MPIR_CVAR_IGATHERV_INTER_ALGORITHM) {
            case MPIR_CVAR_IGATHERV_INTER_ALGORITHM_sched_linear:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_igatherv_inter_sched_linear_call_counter, 1);
                mpi_errno = MPIR_Igatherv_allcomm_sched_linear(sendbuf, sendcount, sendtype, recvbuf,
                                                               recvcounts, displs, recvtype, root,
                                                               comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IGATHERV_INTER_ALGORITHM_tsp_linear:
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_igatherv_inter_tsp_linear_call_counter, 1);
                mpi_errno = MPIR_TSP_Igatherv_sched_allcomm_linear(sendbuf, sendcount, sendtype,
                                    recvbuf, recvcounts, displs, recvtype, root, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IGATHERV_INTER_ALGORITHM_auto:
                mpi_errno = MPIR_Igatherv_allcomm_sched_auto(sendbuf, sendcount, sendtype, recvbuf,
                                recvcounts, displs, recvtype, root, comm_ptr, is_persistent,
                                sched_p, sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    }
    MPIR_ERR_CHECK(mpi_errno);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Igatherv_impl(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                       void *recvbuf, const MPI_Aint recvcounts[], const MPI_Aint displs[],
                       MPI_Datatype recvtype, int root, MPIR_Comm * comm_ptr,
                       MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    enum MPIR_sched_type sched_type;
    void *sched;
    
    *request = NULL;
    mpi_errno = MPIR_Igatherv_sched_impl(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs,
                                         recvtype, root, comm_ptr, false, &sched, &sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    MPII_SCHED_START(sched_type, sched, comm_ptr, request);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Igatherv(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                  const MPI_Aint recvcounts[], const MPI_Aint displs[], MPI_Datatype recvtype,
                  int root, MPIR_Comm * comm_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_igatherv_call_counter, mvp_igatherv_timer);
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_IGATHERV_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Igatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs,
                                  recvtype, root, comm_ptr, request);
    } else {
        mpi_errno = MPIR_Igatherv_impl(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs,
                                       recvtype, root, comm_ptr, request);
    }
    
    MVP_COLL_PVAR_UPDATE_END(mvp_igatherv_timer);
    
    return mpi_errno;
}

int MPIR_Gatherv_init_impl(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                           void *recvbuf, const MPI_Aint recvcounts[], const MPI_Aint displs[],
                           MPI_Datatype recvtype, int root, MPIR_Comm * comm_ptr,
                           MPIR_Info * info_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Request *req = MPIR_Request_create(MPIR_REQUEST_KIND__PREQUEST_COLL);
    MPIR_ERR_CHKANDJUMP(!req, mpi_errno, MPI_ERR_OTHER, "**nomem");
    MPIR_Comm_add_ref(comm_ptr);
    req->comm = comm_ptr;
    MPIR_Comm_save_inactive_request(comm_ptr, req);
    req->u.persist_coll.sched_type = MPIR_SCHED_INVALID;
    req->u.persist_coll.real_request = NULL;
    mpi_errno = MPIR_Igatherv_sched_impl(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs,
                                         recvtype, root, comm_ptr, true, &req->u.persist_coll.sched,
                                         &req->u.persist_coll.sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    
    *request = req;
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Gatherv_init(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                      const MPI_Aint recvcounts[], const MPI_Aint displs[], MPI_Datatype recvtype,
                      int root, MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                      MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_GATHERV_INIT_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Gatherv_init(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs,
                                      recvtype, root, comm_ptr, info_ptr, request);
    } else {
        mpi_errno = MPIR_Gatherv_init_impl(sendbuf, sendcount, sendtype, recvbuf, recvcounts,
                                           displs, recvtype, root, comm_ptr, info_ptr, request);
    }
    
    return mpi_errno;
}

/* ---- scatter ---- */

int MPIR_Scatter_allcomm_auto(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                              void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype, int root,
                              MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__SCATTER,
        .comm_ptr = comm_ptr,
        .u.scatter.sendbuf = sendbuf,
        .u.scatter.sendcount = sendcount,
        .u.scatter.sendtype = sendtype,
        .u.scatter.recvbuf = recvbuf,
        .u.scatter.recvcount = recvcount,
        .u.scatter.recvtype = recvtype,
        .u.scatter.root = root,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Scatter_intra_binomial:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_scatter_intra_binomial_call_counter, 1);
            mpi_errno = MPIR_Scatter_intra_binomial(sendbuf, sendcount, sendtype, recvbuf,
                                                    recvcount, recvtype, root, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Scatter_intra_osu_direct:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_scatter_intra_osu_direct_call_counter, 1);
            mpi_errno = MPIR_Scatter_intra_osu_direct(sendbuf, sendcount, sendtype, recvbuf,
                                                      recvcount, recvtype, root, comm_ptr,
                                                      errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Scatter_inter_linear:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_scatter_inter_linear_call_counter, 1);
            mpi_errno = MPIR_Scatter_inter_linear(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                                  recvtype, root, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Scatter_inter_remote_send_local_scatter:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_scatter_inter_remote_send_local_scatter_call_counter,
                                    1);
            mpi_errno = MPIR_Scatter_inter_remote_send_local_scatter(sendbuf, sendcount, sendtype,
                                recvbuf, recvcount, recvtype, root, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Scatter_allcomm_nb:
           mpi_errno = MPIR_Scatter_allcomm_nb(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                               recvtype, root, comm_ptr, errflag);
           break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Scatter_impl(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                      MPI_Aint recvcount, MPI_Datatype recvtype, int root, MPIR_Comm * comm_ptr,
                      MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_SCATTER_INTRA_ALGORITHM) {
            case MPIR_CVAR_SCATTER_INTRA_ALGORITHM_binomial:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_scatter_intra_binomial_call_counter, 1);
                mpi_errno = MPIR_Scatter_intra_binomial(sendbuf, sendcount, sendtype, recvbuf,
                                                        recvcount, recvtype, root, comm_ptr, errflag);
                break;
            case MPIR_CVAR_SCATTER_INTRA_ALGORITHM_osu_direct:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_scatter_intra_osu_direct_call_counter, 1);
                mpi_errno = MPIR_Scatter_intra_osu_direct(sendbuf, sendcount, sendtype, recvbuf,
                                                          recvcount, recvtype, root, comm_ptr,
                                                          errflag);
                break;
            case MPIR_CVAR_SCATTER_INTRA_ALGORITHM_nb:
                mpi_errno = MPIR_Scatter_allcomm_nb(sendbuf, sendcount, sendtype, recvbuf,
                                                    recvcount, recvtype, root, comm_ptr, errflag);
                 break;
            case MPIR_CVAR_SCATTER_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Scatter_allcomm_auto(sendbuf, sendcount, sendtype, recvbuf,
                                                      recvcount, recvtype, root, comm_ptr,
                                                      errflag);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        switch (MPIR_CVAR_SCATTER_INTER_ALGORITHM) {
            case MPIR_CVAR_SCATTER_INTER_ALGORITHM_linear:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_scatter_inter_linear_call_counter, 1);
                mpi_errno = MPIR_Scatter_inter_linear(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                                      recvtype, root, comm_ptr, errflag);
                break;
            case MPIR_CVAR_SCATTER_INTER_ALGORITHM_remote_send_local_scatter:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_scatter_inter_remote_send_local_scatter_call_counter,
                                        1);
                mpi_errno = MPIR_Scatter_inter_remote_send_local_scatter(sendbuf, sendcount, sendtype,
                                    recvbuf, recvcount, recvtype, root, comm_ptr, errflag);
                break;
            case MPIR_CVAR_SCATTER_INTER_ALGORITHM_nb:
                mpi_errno = MPIR_Scatter_allcomm_nb(sendbuf, sendcount, sendtype, recvbuf,
                                                    recvcount, recvtype, root, comm_ptr, errflag);
                 break;
            case MPIR_CVAR_SCATTER_INTER_ALGORITHM_auto:
                mpi_errno = MPIR_Scatter_allcomm_auto(sendbuf, sendcount, sendtype, recvbuf,
                                                      recvcount, recvtype, root, comm_ptr,
                                                      errflag);
                break;
            default:
                MPIR_Assert(0);
        }
    }
    MPIR_ERR_CHECK(mpi_errno);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Scatter(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                 MPI_Aint recvcount, MPI_Datatype recvtype, int root, MPIR_Comm * comm_ptr,
                 MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_scatter_call_counter, mvp_scatter_timer);
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_SCATTER_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Scatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root,
                                 comm_ptr, errflag);
    } else {
        mpi_errno = MPIR_Scatter_impl(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                                      root, comm_ptr, errflag);
    }
    
    MVP_COLL_PVAR_UPDATE_END(mvp_scatter_timer);
    
    return mpi_errno;
}

/* ---- iscatter ---- */

int MPIR_Iscatter_allcomm_sched_auto(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                                     void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                                     int root, MPIR_Comm * comm_ptr, bool is_persistent,
                                     void **sched_p, enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__ISCATTER,
        .comm_ptr = comm_ptr,
        .u.iscatter.sendbuf = sendbuf,
        .u.iscatter.sendcount = sendcount,
        .u.iscatter.sendtype = sendtype,
        .u.iscatter.recvbuf = recvbuf,
        .u.iscatter.recvcount = recvcount,
        .u.iscatter.recvtype = recvtype,
        .u.iscatter.root = root,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iscatter_intra_sched_binomial:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iscatter_intra_sched_binomial_call_counter, 1);
            mpi_errno = MPIR_Iscatter_intra_sched_binomial(sendbuf, sendcount, sendtype, recvbuf,
                                                           recvcount, recvtype, root, comm_ptr,
                                                           *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iscatter_intra_tsp_tree:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iscatter_intra_tsp_tree_call_counter, 1);
            mpi_errno = MPIR_TSP_Iscatter_sched_intra_tree(sendbuf, sendcount, sendtype, recvbuf,
                                                           recvcount, recvtype, root, comm_ptr,
                                                           cnt->u.iscatter.intra_tsp_tree.k,
                                                           *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iscatter_inter_sched_linear:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iscatter_inter_sched_linear_call_counter, 1);
            mpi_errno = MPIR_Iscatter_inter_sched_linear(sendbuf, sendcount, sendtype, recvbuf,
                                                         recvcount, recvtype, root, comm_ptr,
                                                         *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iscatter_inter_sched_remote_send_local_scatter:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP,
                                    mvp_iscatter_inter_sched_remote_send_local_scatter_call_counter,
                                    1);
            mpi_errno = MPIR_Iscatter_inter_sched_remote_send_local_scatter(sendbuf, sendcount,
                                sendtype, recvbuf, recvcount, recvtype, root, comm_ptr, *sched_p);
            break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Iscatter_sched_impl(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                             void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype, int root,
                             MPIR_Comm * comm_ptr, bool is_persistent, void **sched_p,
                             enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_ISCATTER_INTRA_ALGORITHM) {
            case MPIR_CVAR_ISCATTER_INTRA_ALGORITHM_sched_binomial:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iscatter_intra_sched_binomial_call_counter, 1);
                mpi_errno = MPIR_Iscatter_intra_sched_binomial(sendbuf, sendcount, sendtype, recvbuf,
                                                               recvcount, recvtype, root, comm_ptr,
                                                               *sched_p);
                break;
            case MPIR_CVAR_ISCATTER_INTRA_ALGORITHM_tsp_tree:
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iscatter_intra_tsp_tree_call_counter, 1);
                mpi_errno = MPIR_TSP_Iscatter_sched_intra_tree(sendbuf, sendcount, sendtype, recvbuf,
                                                               recvcount, recvtype, root, comm_ptr,
                                                               MPIR_CVAR_ISCATTER_TREE_KVAL, *sched_p);
                break;
            case MPIR_CVAR_ISCATTER_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Iscatter_allcomm_sched_auto(sendbuf, sendcount, sendtype, recvbuf,
                                recvcount, recvtype, root, comm_ptr, is_persistent, sched_p,
                                sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        switch (MPIR_CVAR_ISCATTER_INTER_ALGORITHM) {
            case MPIR_CVAR_ISCATTER_INTER_ALGORITHM_sched_linear:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iscatter_inter_sched_linear_call_counter, 1);
                mpi_errno = MPIR_Iscatter_inter_sched_linear(sendbuf, sendcount, sendtype, recvbuf,
                                                             recvcount, recvtype, root, comm_ptr,
                                                             *sched_p);
                break;
            case MPIR_CVAR_ISCATTER_INTER_ALGORITHM_sched_remote_send_local_scatter:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP,
                                        mvp_iscatter_inter_sched_remote_send_local_scatter_call_counter,
                                        1);
                mpi_errno = MPIR_Iscatter_inter_sched_remote_send_local_scatter(sendbuf, sendcount,
                                    sendtype, recvbuf, recvcount, recvtype, root, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_ISCATTER_INTER_ALGORITHM_auto:
                mpi_errno = MPIR_Iscatter_allcomm_sched_auto(sendbuf, sendcount, sendtype, recvbuf,
                                recvcount, recvtype, root, comm_ptr, is_persistent, sched_p,
                                sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    }
    MPIR_ERR_CHECK(mpi_errno);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Iscatter_impl(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                       void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype, int root,
                       MPIR_Comm * comm_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    enum MPIR_sched_type sched_type;
    void *sched;
    
    *request = NULL;
    mpi_errno = MPIR_Iscatter_sched_impl(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                                         root, comm_ptr, false, &sched, &sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    MPII_SCHED_START(sched_type, sched, comm_ptr, request);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Iscatter(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                  MPI_Aint recvcount, MPI_Datatype recvtype, int root, MPIR_Comm * comm_ptr,
                  MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_iscatter_call_counter, mvp_iscatter_timer);
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_ISCATTER_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Iscatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root,
                                  comm_ptr, request);
    } else {
        mpi_errno = MPIR_Iscatter_impl(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                                       root, comm_ptr, request);
    }
    
    MVP_COLL_PVAR_UPDATE_END(mvp_iscatter_timer);
    
    return mpi_errno;
}

int MPIR_Scatter_init_impl(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                           void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype, int root,
                           MPIR_Comm * comm_ptr, MPIR_Info * info_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Request *req = MPIR_Request_create(MPIR_REQUEST_KIND__PREQUEST_COLL);
    MPIR_ERR_CHKANDJUMP(!req, mpi_errno, MPI_ERR_OTHER, "**nomem");
    MPIR_Comm_add_ref(comm_ptr);
    req->comm = comm_ptr;
    MPIR_Comm_save_inactive_request(comm_ptr, req);
    req->u.persist_coll.sched_type = MPIR_SCHED_INVALID;
    req->u.persist_coll.real_request = NULL;
    mpi_errno = MPIR_Iscatter_sched_impl(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                                         root, comm_ptr, true, &req->u.persist_coll.sched,
                                         &req->u.persist_coll.sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    
    *request = req;
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Scatter_init(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                      MPI_Aint recvcount, MPI_Datatype recvtype, int root, MPIR_Comm * comm_ptr,
                      MPIR_Info * info_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_SCATTER_INIT_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Scatter_init(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                                      root, comm_ptr, info_ptr, request);
    } else {
        mpi_errno = MPIR_Scatter_init_impl(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                           recvtype, root, comm_ptr, info_ptr, request);
    }
    
    return mpi_errno;
}

/* ---- scatterv ---- */

int MPIR_Scatterv_allcomm_auto(const void *sendbuf, const MPI_Aint sendcounts[],
                               const MPI_Aint displs[], MPI_Datatype sendtype, void *recvbuf,
                               MPI_Aint recvcount, MPI_Datatype recvtype, int root,
                               MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__SCATTERV,
        .comm_ptr = comm_ptr,
        .u.scatterv.sendbuf = sendbuf,
        .u.scatterv.sendcounts = sendcounts,
        .u.scatterv.displs = displs,
        .u.scatterv.sendtype = sendtype,
        .u.scatterv.recvbuf = recvbuf,
        .u.scatterv.recvcount = recvcount,
        .u.scatterv.recvtype = recvtype,
        .u.scatterv.root = root,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Scatterv_allcomm_linear:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_scatterv_intra_linear_call_counter, 1);
            mpi_errno = MPIR_Scatterv_allcomm_linear(sendbuf, sendcounts, displs, sendtype, recvbuf,
                                                     recvcount, recvtype, root, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Scatterv_allcomm_nb:
           mpi_errno = MPIR_Scatterv_allcomm_nb(sendbuf, sendcounts, displs, sendtype, recvbuf,
                                                recvcount, recvtype, root, comm_ptr, errflag);
           break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Scatterv_impl(const void *sendbuf, const MPI_Aint sendcounts[], const MPI_Aint displs[],
                       MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount,
                       MPI_Datatype recvtype, int root, MPIR_Comm * comm_ptr,
                       MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_SCATTERV_INTRA_ALGORITHM) {
            case MPIR_CVAR_SCATTERV_INTRA_ALGORITHM_linear:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_scatterv_intra_linear_call_counter, 1);
                mpi_errno = MPIR_Scatterv_allcomm_linear(sendbuf, sendcounts, displs, sendtype, recvbuf,
                                                         recvcount, recvtype, root, comm_ptr, errflag);
                break;
            case MPIR_CVAR_SCATTERV_INTRA_ALGORITHM_nb:
                mpi_errno = MPIR_Scatterv_allcomm_nb(sendbuf, sendcounts, displs, sendtype, recvbuf,
                                                     recvcount, recvtype, root, comm_ptr, errflag);
                 break;
            case MPIR_CVAR_SCATTERV_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Scatterv_allcomm_auto(sendbuf, sendcounts, displs, sendtype,
                                                       recvbuf, recvcount, recvtype, root, comm_ptr,
                                                       errflag);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        switch (MPIR_CVAR_SCATTERV_INTER_ALGORITHM) {
            case MPIR_CVAR_SCATTERV_INTER_ALGORITHM_linear:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_scatterv_inter_linear_call_counter, 1);
                mpi_errno = MPIR_Scatterv_allcomm_linear(sendbuf, sendcounts, displs, sendtype, recvbuf,
                                                         recvcount, recvtype, root, comm_ptr, errflag);
                break;
            case MPIR_CVAR_SCATTERV_INTER_ALGORITHM_nb:
                mpi_errno = MPIR_Scatterv_allcomm_nb(sendbuf, sendcounts, displs, sendtype, recvbuf,
                                                     recvcount, recvtype, root, comm_ptr, errflag);
                 break;
            case MPIR_CVAR_SCATTERV_INTER_ALGORITHM_auto:
                mpi_errno = MPIR_Scatterv_allcomm_auto(sendbuf, sendcounts, displs, sendtype,
                                                       recvbuf, recvcount, recvtype, root, comm_ptr,
                                                       errflag);
                break;
            default:
                MPIR_Assert(0);
        }
    }
    MPIR_ERR_CHECK(mpi_errno);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Scatterv(const void *sendbuf, const MPI_Aint sendcounts[], const MPI_Aint displs[],
                  MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                  int root, MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_scatterv_call_counter, mvp_scatterv_timer);
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_SCATTERV_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Scatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount,
                                  recvtype, root, comm_ptr, errflag);
    } else {
        mpi_errno = MPIR_Scatterv_impl(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount,
                                       recvtype, root, comm_ptr, errflag);
    }
    
    MVP_COLL_PVAR_UPDATE_END(mvp_scatterv_timer);
    
    return mpi_errno;
}

/* ---- iscatterv ---- */

int MPIR_Iscatterv_allcomm_sched_auto(const void *sendbuf, const MPI_Aint sendcounts[],
                                      const MPI_Aint displs[], MPI_Datatype sendtype, void *recvbuf,
                                      MPI_Aint recvcount, MPI_Datatype recvtype, int root,
                                      MPIR_Comm * comm_ptr, bool is_persistent, void **sched_p,
                                      enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__ISCATTERV,
        .comm_ptr = comm_ptr,
        .u.iscatterv.sendbuf = sendbuf,
        .u.iscatterv.sendcounts = sendcounts,
        .u.iscatterv.displs = displs,
        .u.iscatterv.sendtype = sendtype,
        .u.iscatterv.recvbuf = recvbuf,
        .u.iscatterv.recvcount = recvcount,
        .u.iscatterv.recvtype = recvtype,
        .u.iscatterv.root = root,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iscatterv_allcomm_sched_linear:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iscatterv_intra_sched_linear_call_counter, 1);
            mpi_errno = MPIR_Iscatterv_allcomm_sched_linear(sendbuf, sendcounts, displs, sendtype,
                                                            recvbuf, recvcount, recvtype, root,
                                                            comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iscatterv_allcomm_tsp_linear:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iscatterv_intra_tsp_linear_call_counter, 1);
            mpi_errno = MPIR_TSP_Iscatterv_sched_allcomm_linear(sendbuf, sendcounts, displs,
                                sendtype, recvbuf, recvcount, recvtype, root, comm_ptr, *sched_p);
            break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Iscatterv_sched_impl(const void *sendbuf, const MPI_Aint sendcounts[],
                              const MPI_Aint displs[], MPI_Datatype sendtype, void *recvbuf,
                              MPI_Aint recvcount, MPI_Datatype recvtype, int root,
                              MPIR_Comm * comm_ptr, bool is_persistent, void **sched_p,
                              enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_ISCATTERV_INTRA_ALGORITHM) {
            case MPIR_CVAR_ISCATTERV_INTRA_ALGORITHM_sched_linear:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iscatterv_intra_sched_linear_call_counter, 1);
                mpi_errno = MPIR_Iscatterv_allcomm_sched_linear(sendbuf, sendcounts, displs, sendtype,
                                                                recvbuf, recvcount, recvtype, root,
                                                                comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_ISCATTERV_INTRA_ALGORITHM_tsp_linear:
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iscatterv_intra_tsp_linear_call_counter, 1);
                mpi_errno = MPIR_TSP_Iscatterv_sched_allcomm_linear(sendbuf, sendcounts, displs,
                                    sendtype, recvbuf, recvcount, recvtype, root, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_ISCATTERV_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Iscatterv_allcomm_sched_auto(sendbuf, sendcounts, displs, sendtype,
                                recvbuf, recvcount, recvtype, root, comm_ptr, is_persistent,
                                sched_p, sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        switch (MPIR_CVAR_ISCATTERV_INTER_ALGORITHM) {
            case MPIR_CVAR_ISCATTERV_INTER_ALGORITHM_sched_linear:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iscatterv_inter_sched_linear_call_counter, 1);
                mpi_errno = MPIR_Iscatterv_allcomm_sched_linear(sendbuf, sendcounts, displs, sendtype,
                                                                recvbuf, recvcount, recvtype, root,
                                                                comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_ISCATTERV_INTER_ALGORITHM_tsp_linear:
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iscatterv_inter_tsp_linear_call_counter, 1);
                mpi_errno = MPIR_TSP_Iscatterv_sched_allcomm_linear(sendbuf, sendcounts, displs,
                                    sendtype, recvbuf, recvcount, recvtype, root, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_ISCATTERV_INTER_ALGORITHM_auto:
                mpi_errno = MPIR_Iscatterv_allcomm_sched_auto(sendbuf, sendcounts, displs, sendtype,
                                recvbuf, recvcount, recvtype, root, comm_ptr, is_persistent,
                                sched_p, sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    }
    MPIR_ERR_CHECK(mpi_errno);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Iscatterv_impl(const void *sendbuf, const MPI_Aint sendcounts[], const MPI_Aint displs[],
                        MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount,
                        MPI_Datatype recvtype, int root, MPIR_Comm * comm_ptr,
                        MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    enum MPIR_sched_type sched_type;
    void *sched;
    
    *request = NULL;
    mpi_errno = MPIR_Iscatterv_sched_impl(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount,
                                          recvtype, root, comm_ptr, false, &sched, &sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    MPII_SCHED_START(sched_type, sched, comm_ptr, request);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Iscatterv(const void *sendbuf, const MPI_Aint sendcounts[], const MPI_Aint displs[],
                   MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                   int root, MPIR_Comm * comm_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_iscatterv_call_counter, mvp_iscatterv_timer);
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_ISCATTERV_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Iscatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount,
                                   recvtype, root, comm_ptr, request);
    } else {
        mpi_errno = MPIR_Iscatterv_impl(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount,
                                        recvtype, root, comm_ptr, request);
    }
    
    MVP_COLL_PVAR_UPDATE_END(mvp_iscatterv_timer);
    
    return mpi_errno;
}

int MPIR_Scatterv_init_impl(const void *sendbuf, const MPI_Aint sendcounts[],
                            const MPI_Aint displs[], MPI_Datatype sendtype, void *recvbuf,
                            MPI_Aint recvcount, MPI_Datatype recvtype, int root,
                            MPIR_Comm * comm_ptr, MPIR_Info * info_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Request *req = MPIR_Request_create(MPIR_REQUEST_KIND__PREQUEST_COLL);
    MPIR_ERR_CHKANDJUMP(!req, mpi_errno, MPI_ERR_OTHER, "**nomem");
    MPIR_Comm_add_ref(comm_ptr);
    req->comm = comm_ptr;
    MPIR_Comm_save_inactive_request(comm_ptr, req);
    req->u.persist_coll.sched_type = MPIR_SCHED_INVALID;
    req->u.persist_coll.real_request = NULL;
    mpi_errno = MPIR_Iscatterv_sched_impl(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount,
                                          recvtype, root, comm_ptr, true,
                                          &req->u.persist_coll.sched,
                                          &req->u.persist_coll.sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    
    *request = req;
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Scatterv_init(const void *sendbuf, const MPI_Aint sendcounts[], const MPI_Aint displs[],
                       MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount,
                       MPI_Datatype recvtype, int root, MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                       MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_SCATTERV_INIT_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Scatterv_init(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount,
                                       recvtype, root, comm_ptr, info_ptr, request);
    } else {
        mpi_errno = MPIR_Scatterv_init_impl(sendbuf, sendcounts, displs, sendtype, recvbuf,
                                            recvcount, recvtype, root, comm_ptr, info_ptr,
                                            request);
    }
    
    return mpi_errno;
}

/* ---- allgather ---- */

int MPIR_Allgather_allcomm_auto(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                                void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                                MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__ALLGATHER,
        .comm_ptr = comm_ptr,
        .u.allgather.sendbuf = sendbuf,
        .u.allgather.sendcount = sendcount,
        .u.allgather.sendtype = sendtype,
        .u.allgather.recvbuf = recvbuf,
        .u.allgather.recvcount = recvcount,
        .u.allgather.recvtype = recvtype,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allgather_intra_brucks:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allgather_intra_brucks_call_counter, 1);
            mpi_errno = MPIR_Allgather_intra_brucks(sendbuf, sendcount, sendtype, recvbuf,
                                                    recvcount, recvtype, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allgather_intra_k_brucks:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allgather_intra_k_brucks_call_counter, 1);
            mpi_errno = MPIR_Allgather_intra_k_brucks(sendbuf, sendcount, sendtype, recvbuf,
                                                      recvcount, recvtype, comm_ptr,
                                                      cnt->u.allgather.intra_k_brucks.k, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allgather_intra_recursive_doubling:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allgather_intra_recursive_doubling_call_counter, 1);
            mpi_errno = MPIR_Allgather_intra_recursive_doubling(sendbuf, sendcount, sendtype,
                                recvbuf, recvcount, recvtype, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allgather_intra_ring:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allgather_intra_ring_call_counter, 1);
            mpi_errno = MPIR_Allgather_intra_ring(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                                  recvtype, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allgather_intra_recexch_doubling:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allgather_intra_recexch_doubling_call_counter, 1);
            mpi_errno = MPIR_Allgather_intra_recexch(sendbuf, sendcount, sendtype, recvbuf,
                                                     recvcount, recvtype, comm_ptr,
                                                     MPIR_ALLGATHER_RECEXCH_TYPE_DISTANCE_DOUBLING,
                                                     cnt->u.allgather.intra_recexch_doubling.k,
                                                     cnt->u.allgather.intra_recexch_doubling.single_phase_recv,
                                                     errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allgather_intra_recexch_halving:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allgather_intra_recexch_halving_call_counter, 1);
            mpi_errno = MPIR_Allgather_intra_recexch(sendbuf, sendcount, sendtype, recvbuf,
                                                     recvcount, recvtype, comm_ptr,
                                                     MPIR_ALLGATHER_RECEXCH_TYPE_DISTANCE_HALVING,
                                                     cnt->u.allgather.intra_recexch_halving.k,
                                                     cnt->u.allgather.intra_recexch_halving.single_phase_recv,
                                                     errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allgather_intra_osu_direct:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allgather_intra_osu_direct_call_counter, 1);
            mpi_errno = MPIR_Allgather_intra_osu_direct(sendbuf, sendcount, sendtype, recvbuf,
                                                        recvcount, recvtype, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allgather_intra_osu_direct_spread:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allgather_intra_osu_direct_spread_call_counter, 1);
            mpi_errno = MPIR_Allgather_intra_osu_direct_spread(sendbuf, sendcount, sendtype,
                                recvbuf, recvcount, recvtype, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allgather_intra_osu_gather_bcast:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allgather_intra_osu_gather_bcast_call_counter, 1);
            mpi_errno = MPIR_Allgather_intra_osu_gather_bcast(sendbuf, sendcount, sendtype, recvbuf,
                                recvcount, recvtype, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allgather_inter_local_gather_remote_bcast:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allgather_inter_local_gather_remote_bcast_call_counter,
                                    1);
            mpi_errno = MPIR_Allgather_inter_local_gather_remote_bcast(sendbuf, sendcount, sendtype,
                                recvbuf, recvcount, recvtype, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allgather_allcomm_nb:
           mpi_errno = MPIR_Allgather_allcomm_nb(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                                 recvtype, comm_ptr, errflag);
           break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Allgather_impl(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                        void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                        MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_ALLGATHER_INTRA_ALGORITHM) {
            case MPIR_CVAR_ALLGATHER_INTRA_ALGORITHM_brucks:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allgather_intra_brucks_call_counter, 1);
                mpi_errno = MPIR_Allgather_intra_brucks(sendbuf, sendcount, sendtype, recvbuf,
                                                        recvcount, recvtype, comm_ptr, errflag);
                break;
            case MPIR_CVAR_ALLGATHER_INTRA_ALGORITHM_k_brucks:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allgather_intra_k_brucks_call_counter, 1);
                mpi_errno = MPIR_Allgather_intra_k_brucks(sendbuf, sendcount, sendtype, recvbuf,
                                                          recvcount, recvtype, comm_ptr,
                                                          MPIR_CVAR_ALLGATHER_BRUCKS_KVAL, errflag);
                break;
            case MPIR_CVAR_ALLGATHER_INTRA_ALGORITHM_recursive_doubling:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, comm_ptr->local_size == comm_ptr->coll.pof2, mpi_errno,
                                               "Allgather recursive_doubling cannot be applied.\n");
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allgather_intra_recursive_doubling_call_counter, 1);
                mpi_errno = MPIR_Allgather_intra_recursive_doubling(sendbuf, sendcount, sendtype,
                                    recvbuf, recvcount, recvtype, comm_ptr, errflag);
                break;
            case MPIR_CVAR_ALLGATHER_INTRA_ALGORITHM_ring:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allgather_intra_ring_call_counter, 1);
                mpi_errno = MPIR_Allgather_intra_ring(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                                      recvtype, comm_ptr, errflag);
                break;
            case MPIR_CVAR_ALLGATHER_INTRA_ALGORITHM_recexch_doubling:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allgather_intra_recexch_doubling_call_counter, 1);
                mpi_errno = MPIR_Allgather_intra_recexch(sendbuf, sendcount, sendtype, recvbuf,
                                                         recvcount, recvtype, comm_ptr,
                                                         MPIR_ALLGATHER_RECEXCH_TYPE_DISTANCE_DOUBLING,
                                                         MPIR_CVAR_ALLGATHER_RECEXCH_KVAL,
                                                         MPIR_CVAR_ALLGATHER_RECEXCH_SINGLE_PHASE_RECV,
                                                         errflag);
                break;
            case MPIR_CVAR_ALLGATHER_INTRA_ALGORITHM_recexch_halving:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allgather_intra_recexch_halving_call_counter, 1);
                mpi_errno = MPIR_Allgather_intra_recexch(sendbuf, sendcount, sendtype, recvbuf,
                                                         recvcount, recvtype, comm_ptr,
                                                         MPIR_ALLGATHER_RECEXCH_TYPE_DISTANCE_HALVING,
                                                         MPIR_CVAR_ALLGATHER_RECEXCH_KVAL,
                                                         MPIR_CVAR_ALLGATHER_RECEXCH_SINGLE_PHASE_RECV,
                                                         errflag);
                break;
            case MPIR_CVAR_ALLGATHER_INTRA_ALGORITHM_osu_direct:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allgather_intra_osu_direct_call_counter, 1);
                mpi_errno = MPIR_Allgather_intra_osu_direct(sendbuf, sendcount, sendtype, recvbuf,
                                                            recvcount, recvtype, comm_ptr, errflag);
                break;
            case MPIR_CVAR_ALLGATHER_INTRA_ALGORITHM_osu_direct_spread:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allgather_intra_osu_direct_spread_call_counter, 1);
                mpi_errno = MPIR_Allgather_intra_osu_direct_spread(sendbuf, sendcount, sendtype,
                                    recvbuf, recvcount, recvtype, comm_ptr, errflag);
                break;
            case MPIR_CVAR_ALLGATHER_INTRA_ALGORITHM_osu_gather_bcast:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allgather_intra_osu_gather_bcast_call_counter, 1);
                mpi_errno = MPIR_Allgather_intra_osu_gather_bcast(sendbuf, sendcount, sendtype, recvbuf,
                                    recvcount, recvtype, comm_ptr, errflag);
                break;
            case MPIR_CVAR_ALLGATHER_INTRA_ALGORITHM_nb:
                mpi_errno = MPIR_Allgather_allcomm_nb(sendbuf, sendcount, sendtype, recvbuf,
                                                      recvcount, recvtype, comm_ptr, errflag);
                 break;
            case MPIR_CVAR_ALLGATHER_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Allgather_allcomm_auto(sendbuf, sendcount, sendtype, recvbuf,
                                                        recvcount, recvtype, comm_ptr, errflag);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        switch (MPIR_CVAR_ALLGATHER_INTER_ALGORITHM) {
            case MPIR_CVAR_ALLGATHER_INTER_ALGORITHM_local_gather_remote_bcast:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allgather_inter_local_gather_remote_bcast_call_counter,
                                        1);
                mpi_errno = MPIR_Allgather_inter_local_gather_remote_bcast(sendbuf, sendcount, sendtype,
                                    recvbuf, recvcount, recvtype, comm_ptr, errflag);
                break;
            case MPIR_CVAR_ALLGATHER_INTER_ALGORITHM_nb:
                mpi_errno = MPIR_Allgather_allcomm_nb(sendbuf, sendcount, sendtype, recvbuf,
                                                      recvcount, recvtype, comm_ptr, errflag);
                 break;
            case MPIR_CVAR_ALLGATHER_INTER_ALGORITHM_auto:
                mpi_errno = MPIR_Allgather_allcomm_auto(sendbuf, sendcount, sendtype, recvbuf,
                                                        recvcount, recvtype, comm_ptr, errflag);
                break;
            default:
                MPIR_Assert(0);
        }
    }
    MPIR_ERR_CHECK(mpi_errno);
    goto fn_exit;
    
  fallback:
    mpi_errno = MPIR_Allgather_allcomm_auto(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                            recvtype, comm_ptr, errflag);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Allgather(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                   MPI_Aint recvcount, MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                   MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_allgather_call_counter, mvp_allgather_timer);
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_ALLGATHER_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                                   comm_ptr, errflag);
    } else {
        mpi_errno = MPIR_Allgather_impl(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                                        comm_ptr, errflag);
    }
    
    MVP_COLL_PVAR_UPDATE_END(mvp_allgather_timer);
    
    return mpi_errno;
}

/* ---- iallgather ---- */

int MPIR_Iallgather_allcomm_sched_auto(const void *sendbuf, MPI_Aint sendcount,
                                       MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount,
                                       MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                                       bool is_persistent, void **sched_p,
                                       enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__IALLGATHER,
        .comm_ptr = comm_ptr,
        .u.iallgather.sendbuf = sendbuf,
        .u.iallgather.sendcount = sendcount,
        .u.iallgather.sendtype = sendtype,
        .u.iallgather.recvbuf = recvbuf,
        .u.iallgather.recvcount = recvcount,
        .u.iallgather.recvtype = recvtype,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgather_intra_sched_ring:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallgather_intra_sched_ring_call_counter, 1);
            mpi_errno = MPIR_Iallgather_intra_sched_ring(sendbuf, sendcount, sendtype, recvbuf,
                                                         recvcount, recvtype, comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgather_intra_sched_brucks:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallgather_intra_sched_brucks_call_counter, 1);
            mpi_errno = MPIR_Iallgather_intra_sched_brucks(sendbuf, sendcount, sendtype, recvbuf,
                                                           recvcount, recvtype, comm_ptr,
                                                           *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgather_intra_sched_recursive_doubling:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallgather_intra_sched_recursive_doubling_call_counter,
                                    1);
            mpi_errno = MPIR_Iallgather_intra_sched_recursive_doubling(sendbuf, sendcount, sendtype,
                                recvbuf, recvcount, recvtype, comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgather_intra_tsp_ring:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallgather_intra_tsp_ring_call_counter, 1);
            mpi_errno = MPIR_TSP_Iallgather_sched_intra_ring(sendbuf, sendcount, sendtype, recvbuf,
                                recvcount, recvtype, comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgather_intra_tsp_brucks:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallgather_intra_tsp_brucks_call_counter, 1);
            mpi_errno = MPIR_TSP_Iallgather_sched_intra_brucks(sendbuf, sendcount, sendtype,
                                recvbuf, recvcount, recvtype, comm_ptr,
                                cnt->u.iallgather.intra_tsp_brucks.k, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgather_intra_tsp_recexch_doubling:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallgather_intra_tsp_recexch_doubling_call_counter,
                                    1);
            mpi_errno = MPIR_TSP_Iallgather_sched_intra_recexch(sendbuf, sendcount, sendtype,
                                recvbuf, recvcount, recvtype, comm_ptr,
                                MPIR_IALLGATHER_RECEXCH_TYPE_DISTANCE_DOUBLING,
                                cnt->u.iallgather.intra_tsp_recexch_doubling.k, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgather_intra_tsp_recexch_halving:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallgather_intra_tsp_recexch_halving_call_counter, 1);
            mpi_errno = MPIR_TSP_Iallgather_sched_intra_recexch(sendbuf, sendcount, sendtype,
                                recvbuf, recvcount, recvtype, comm_ptr,
                                MPIR_IALLGATHER_RECEXCH_TYPE_DISTANCE_HALVING,
                                cnt->u.iallgather.intra_tsp_recexch_halving.k, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgather_inter_sched_local_gather_remote_bcast:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP,
                                    mvp_iallgather_inter_sched_local_gather_remote_bcast_call_counter,
                                    1);
            mpi_errno = MPIR_Iallgather_inter_sched_local_gather_remote_bcast(sendbuf, sendcount,
                                sendtype, recvbuf, recvcount, recvtype, comm_ptr, *sched_p);
            break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Iallgather_sched_impl(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                               void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                               MPIR_Comm * comm_ptr, bool is_persistent, void **sched_p,
                               enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_IALLGATHER_INTRA_ALGORITHM) {
            case MPIR_CVAR_IALLGATHER_INTRA_ALGORITHM_sched_ring:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallgather_intra_sched_ring_call_counter, 1);
                mpi_errno = MPIR_Iallgather_intra_sched_ring(sendbuf, sendcount, sendtype, recvbuf,
                                                             recvcount, recvtype, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IALLGATHER_INTRA_ALGORITHM_sched_brucks:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallgather_intra_sched_brucks_call_counter, 1);
                mpi_errno = MPIR_Iallgather_intra_sched_brucks(sendbuf, sendcount, sendtype, recvbuf,
                                                               recvcount, recvtype, comm_ptr,
                                                               *sched_p);
                break;
            case MPIR_CVAR_IALLGATHER_INTRA_ALGORITHM_sched_recursive_doubling:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, comm_ptr->local_size == comm_ptr->coll.pof2, mpi_errno,
                                               "Iallgather sched_recursive_doubling cannot be applied.\n");
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallgather_intra_sched_recursive_doubling_call_counter,
                                        1);
                mpi_errno = MPIR_Iallgather_intra_sched_recursive_doubling(sendbuf, sendcount, sendtype,
                                    recvbuf, recvcount, recvtype, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IALLGATHER_INTRA_ALGORITHM_tsp_ring:
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallgather_intra_tsp_ring_call_counter, 1);
                mpi_errno = MPIR_TSP_Iallgather_sched_intra_ring(sendbuf, sendcount, sendtype, recvbuf,
                                    recvcount, recvtype, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IALLGATHER_INTRA_ALGORITHM_tsp_brucks:
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallgather_intra_tsp_brucks_call_counter, 1);
                mpi_errno = MPIR_TSP_Iallgather_sched_intra_brucks(sendbuf, sendcount, sendtype,
                                    recvbuf, recvcount, recvtype, comm_ptr,
                                    MPIR_CVAR_IALLGATHER_BRUCKS_KVAL, *sched_p);
                break;
            case MPIR_CVAR_IALLGATHER_INTRA_ALGORITHM_tsp_recexch_doubling:
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallgather_intra_tsp_recexch_doubling_call_counter,
                                        1);
                mpi_errno = MPIR_TSP_Iallgather_sched_intra_recexch(sendbuf, sendcount, sendtype,
                                    recvbuf, recvcount, recvtype, comm_ptr,
                                    MPIR_IALLGATHER_RECEXCH_TYPE_DISTANCE_DOUBLING,
                                    MPIR_CVAR_IALLGATHER_RECEXCH_KVAL, *sched_p);
                break;
            case MPIR_CVAR_IALLGATHER_INTRA_ALGORITHM_tsp_recexch_halving:
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallgather_intra_tsp_recexch_halving_call_counter, 1);
                mpi_errno = MPIR_TSP_Iallgather_sched_intra_recexch(sendbuf, sendcount, sendtype,
                                    recvbuf, recvcount, recvtype, comm_ptr,
                                    MPIR_IALLGATHER_RECEXCH_TYPE_DISTANCE_HALVING,
                                    MPIR_CVAR_IALLGATHER_RECEXCH_KVAL, *sched_p);
                break;
            case MPIR_CVAR_IALLGATHER_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Iallgather_allcomm_sched_auto(sendbuf, sendcount, sendtype,
                                recvbuf, recvcount, recvtype, comm_ptr, is_persistent, sched_p,
                                sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        switch (MPIR_CVAR_IALLGATHER_INTER_ALGORITHM) {
            case MPIR_CVAR_IALLGATHER_INTER_ALGORITHM_sched_local_gather_remote_bcast:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP,
                                        mvp_iallgather_inter_sched_local_gather_remote_bcast_call_counter,
                                        1);
                mpi_errno = MPIR_Iallgather_inter_sched_local_gather_remote_bcast(sendbuf, sendcount,
                                    sendtype, recvbuf, recvcount, recvtype, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IALLGATHER_INTER_ALGORITHM_auto:
                mpi_errno = MPIR_Iallgather_allcomm_sched_auto(sendbuf, sendcount, sendtype,
                                recvbuf, recvcount, recvtype, comm_ptr, is_persistent, sched_p,
                                sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    }
    MPIR_ERR_CHECK(mpi_errno);
    goto fn_exit;
    
  fallback:
    mpi_errno = MPIR_Iallgather_allcomm_sched_auto(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                                   recvtype, comm_ptr, is_persistent, sched_p,
                                                   sched_type_p);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Iallgather_impl(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                         void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                         MPIR_Comm * comm_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    enum MPIR_sched_type sched_type;
    void *sched;
    
    *request = NULL;
    mpi_errno = MPIR_Iallgather_sched_impl(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                           recvtype, comm_ptr, false, &sched, &sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    MPII_SCHED_START(sched_type, sched, comm_ptr, request);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Iallgather(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    MPI_Aint recvcount, MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                    MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_iallgather_call_counter, mvp_iallgather_timer);
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_IALLGATHER_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Iallgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                                    comm_ptr, request);
    } else {
        mpi_errno = MPIR_Iallgather_impl(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                                         comm_ptr, request);
    }
    
    MVP_COLL_PVAR_UPDATE_END(mvp_iallgather_timer);
    
    return mpi_errno;
}

int MPIR_Allgather_init_impl(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                             void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                             MPIR_Comm * comm_ptr, MPIR_Info * info_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Request *req = MPIR_Request_create(MPIR_REQUEST_KIND__PREQUEST_COLL);
    MPIR_ERR_CHKANDJUMP(!req, mpi_errno, MPI_ERR_OTHER, "**nomem");
    MPIR_Comm_add_ref(comm_ptr);
    req->comm = comm_ptr;
    MPIR_Comm_save_inactive_request(comm_ptr, req);
    req->u.persist_coll.sched_type = MPIR_SCHED_INVALID;
    req->u.persist_coll.real_request = NULL;
    mpi_errno = MPIR_Iallgather_sched_impl(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                           recvtype, comm_ptr, true, &req->u.persist_coll.sched,
                                           &req->u.persist_coll.sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    
    *request = req;
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Allgather_init(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                        void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                        MPIR_Comm * comm_ptr, MPIR_Info * info_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_ALLGATHER_INIT_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Allgather_init(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                                        comm_ptr, info_ptr, request);
    } else {
        mpi_errno = MPIR_Allgather_init_impl(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                             recvtype, comm_ptr, info_ptr, request);
    }
    
    return mpi_errno;
}

/* ---- allgatherv ---- */

int MPIR_Allgatherv_allcomm_auto(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                                 void *recvbuf, const MPI_Aint recvcounts[],
                                 const MPI_Aint displs[], MPI_Datatype recvtype,
                                 MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__ALLGATHERV,
        .comm_ptr = comm_ptr,
        .u.allgatherv.sendbuf = sendbuf,
        .u.allgatherv.sendcount = sendcount,
        .u.allgatherv.sendtype = sendtype,
        .u.allgatherv.recvbuf = recvbuf,
        .u.allgatherv.recvcounts = recvcounts,
        .u.allgatherv.displs = displs,
        .u.allgatherv.recvtype = recvtype,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allgatherv_intra_brucks:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allgatherv_intra_brucks_call_counter, 1);
            mpi_errno = MPIR_Allgatherv_intra_brucks(sendbuf, sendcount, sendtype, recvbuf,
                                                     recvcounts, displs, recvtype, comm_ptr,
                                                     errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allgatherv_intra_recursive_doubling:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allgatherv_intra_recursive_doubling_call_counter, 1);
            mpi_errno = MPIR_Allgatherv_intra_recursive_doubling(sendbuf, sendcount, sendtype,
                                recvbuf, recvcounts, displs, recvtype, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allgatherv_intra_ring:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allgatherv_intra_ring_call_counter, 1);
            mpi_errno = MPIR_Allgatherv_intra_ring(sendbuf, sendcount, sendtype, recvbuf,
                                                   recvcounts, displs, recvtype, comm_ptr,
                                                   errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allgatherv_inter_remote_gather_local_bcast:
            MPIR_T_PVAR_COUNTER_INC(MVP,
                                    mvp_allgatherv_inter_remote_gather_local_bcast_call_counter,
                                    1);
            mpi_errno = MPIR_Allgatherv_inter_remote_gather_local_bcast(sendbuf, sendcount,
                                sendtype, recvbuf, recvcounts, displs, recvtype, comm_ptr,
                                errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allgatherv_allcomm_nb:
           mpi_errno = MPIR_Allgatherv_allcomm_nb(sendbuf, sendcount, sendtype, recvbuf, recvcounts,
                                                  displs, recvtype, comm_ptr, errflag);
           break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Allgatherv_impl(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                         void *recvbuf, const MPI_Aint recvcounts[], const MPI_Aint displs[],
                         MPI_Datatype recvtype, MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_ALLGATHERV_INTRA_ALGORITHM) {
            case MPIR_CVAR_ALLGATHERV_INTRA_ALGORITHM_brucks:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allgatherv_intra_brucks_call_counter, 1);
                mpi_errno = MPIR_Allgatherv_intra_brucks(sendbuf, sendcount, sendtype, recvbuf,
                                                         recvcounts, displs, recvtype, comm_ptr,
                                                         errflag);
                break;
            case MPIR_CVAR_ALLGATHERV_INTRA_ALGORITHM_recursive_doubling:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, comm_ptr->local_size == comm_ptr->coll.pof2, mpi_errno,
                                               "Allgatherv recursive_doubling cannot be applied.\n");
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allgatherv_intra_recursive_doubling_call_counter, 1);
                mpi_errno = MPIR_Allgatherv_intra_recursive_doubling(sendbuf, sendcount, sendtype,
                                    recvbuf, recvcounts, displs, recvtype, comm_ptr, errflag);
                break;
            case MPIR_CVAR_ALLGATHERV_INTRA_ALGORITHM_ring:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allgatherv_intra_ring_call_counter, 1);
                mpi_errno = MPIR_Allgatherv_intra_ring(sendbuf, sendcount, sendtype, recvbuf,
                                                       recvcounts, displs, recvtype, comm_ptr,
                                                       errflag);
                break;
            case MPIR_CVAR_ALLGATHERV_INTRA_ALGORITHM_nb:
                mpi_errno = MPIR_Allgatherv_allcomm_nb(sendbuf, sendcount, sendtype, recvbuf,
                                                       recvcounts, displs, recvtype, comm_ptr,
                                                       errflag);
                 break;
            case MPIR_CVAR_ALLGATHERV_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Allgatherv_allcomm_auto(sendbuf, sendcount, sendtype, recvbuf,
                                                         recvcounts, displs, recvtype, comm_ptr,
                                                         errflag);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        switch (MPIR_CVAR_ALLGATHERV_INTER_ALGORITHM) {
            case MPIR_CVAR_ALLGATHERV_INTER_ALGORITHM_remote_gather_local_bcast:
                MPIR_T_PVAR_COUNTER_INC(MVP,
                                        mvp_allgatherv_inter_remote_gather_local_bcast_call_counter,
                                        1);
                mpi_errno = MPIR_Allgatherv_inter_remote_gather_local_bcast(sendbuf, sendcount,
                                    sendtype, recvbuf, recvcounts, displs, recvtype, comm_ptr,
                                    errflag);
                break;
            case MPIR_CVAR_ALLGATHERV_INTER_ALGORITHM_nb:
                mpi_errno = MPIR_Allgatherv_allcomm_nb(sendbuf, sendcount, sendtype, recvbuf,
                                                       recvcounts, displs, recvtype, comm_ptr,
                                                       errflag);
                 break;
            case MPIR_CVAR_ALLGATHERV_INTER_ALGORITHM_auto:
                mpi_errno = MPIR_Allgatherv_allcomm_auto(sendbuf, sendcount, sendtype, recvbuf,
                                                         recvcounts, displs, recvtype, comm_ptr,
                                                         errflag);
                break;
            default:
                MPIR_Assert(0);
        }
    }
    MPIR_ERR_CHECK(mpi_errno);
    goto fn_exit;
    
  fallback:
    mpi_errno = MPIR_Allgatherv_allcomm_auto(sendbuf, sendcount, sendtype, recvbuf, recvcounts,
                                             displs, recvtype, comm_ptr, errflag);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Allgatherv(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint displs[], MPI_Datatype recvtype,
                    MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_allgatherv_call_counter, mvp_allgatherv_timer);
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_ALLGATHERV_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs,
                                    recvtype, comm_ptr, errflag);
    } else {
        mpi_errno = MPIR_Allgatherv_impl(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs,
                                         recvtype, comm_ptr, errflag);
    }
    
    MVP_COLL_PVAR_UPDATE_END(mvp_allgatherv_timer);
    
    return mpi_errno;
}

/* ---- iallgatherv ---- */

int MPIR_Iallgatherv_allcomm_sched_auto(const void *sendbuf, MPI_Aint sendcount,
                                        MPI_Datatype sendtype, void *recvbuf,
                                        const MPI_Aint recvcounts[], const MPI_Aint displs[],
                                        MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                                        bool is_persistent, void **sched_p,
                                        enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__IALLGATHERV,
        .comm_ptr = comm_ptr,
        .u.iallgatherv.sendbuf = sendbuf,
        .u.iallgatherv.sendcount = sendcount,
        .u.iallgatherv.sendtype = sendtype,
        .u.iallgatherv.recvbuf = recvbuf,
        .u.iallgatherv.recvcounts = recvcounts,
        .u.iallgatherv.displs = displs,
        .u.iallgatherv.recvtype = recvtype,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgatherv_intra_sched_brucks:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallgatherv_intra_sched_brucks_call_counter, 1);
            mpi_errno = MPIR_Iallgatherv_intra_sched_brucks(sendbuf, sendcount, sendtype, recvbuf,
                                                            recvcounts, displs, recvtype, comm_ptr,
                                                            *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgatherv_intra_sched_recursive_doubling:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP,
                                    mvp_iallgatherv_intra_sched_recursive_doubling_call_counter,
                                    1);
            mpi_errno = MPIR_Iallgatherv_intra_sched_recursive_doubling(sendbuf, sendcount,
                                sendtype, recvbuf, recvcounts, displs, recvtype, comm_ptr,
                                *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgatherv_intra_sched_ring:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallgatherv_intra_sched_ring_call_counter, 1);
            mpi_errno = MPIR_Iallgatherv_intra_sched_ring(sendbuf, sendcount, sendtype, recvbuf,
                                                          recvcounts, displs, recvtype, comm_ptr,
                                                          *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgatherv_intra_tsp_recexch_doubling:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallgatherv_intra_tsp_recexch_doubling_call_counter,
                                    1);
            mpi_errno = MPIR_TSP_Iallgatherv_sched_intra_recexch(sendbuf, sendcount, sendtype,
                                recvbuf, recvcounts, displs, recvtype, comm_ptr,
                                MPIR_IALLGATHERV_RECEXCH_TYPE_DISTANCE_DOUBLING,
                                cnt->u.iallgatherv.intra_tsp_recexch_doubling.k, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgatherv_intra_tsp_recexch_halving:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallgatherv_intra_tsp_recexch_halving_call_counter,
                                    1);
            mpi_errno = MPIR_TSP_Iallgatherv_sched_intra_recexch(sendbuf, sendcount, sendtype,
                                recvbuf, recvcounts, displs, recvtype, comm_ptr,
                                MPIR_IALLGATHERV_RECEXCH_TYPE_DISTANCE_HALVING,
                                cnt->u.iallgatherv.intra_tsp_recexch_halving.k, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgatherv_intra_tsp_ring:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallgatherv_intra_tsp_ring_call_counter, 1);
            mpi_errno = MPIR_TSP_Iallgatherv_sched_intra_ring(sendbuf, sendcount, sendtype, recvbuf,
                                recvcounts, displs, recvtype, comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgatherv_intra_tsp_brucks:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallgatherv_intra_tsp_brucks_call_counter, 1);
            mpi_errno = MPIR_TSP_Iallgatherv_sched_intra_brucks(sendbuf, sendcount, sendtype,
                                recvbuf, recvcounts, displs, recvtype, comm_ptr,
                                cnt->u.iallgatherv.intra_tsp_brucks.k, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgatherv_inter_sched_remote_gather_local_bcast:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP,
                                    mvp_iallgatherv_inter_sched_remote_gather_local_bcast_call_counter,
                                    1);
            mpi_errno = MPIR_Iallgatherv_inter_sched_remote_gather_local_bcast(sendbuf, sendcount,
                                sendtype, recvbuf, recvcounts, displs, recvtype, comm_ptr,
                                *sched_p);
            break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Iallgatherv_sched_impl(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                                void *recvbuf, const MPI_Aint recvcounts[], const MPI_Aint displs[],
                                MPI_Datatype recvtype, MPIR_Comm * comm_ptr, bool is_persistent,
                                void **sched_p, enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_IALLGATHERV_INTRA_ALGORITHM) {
            case MPIR_CVAR_IALLGATHERV_INTRA_ALGORITHM_sched_brucks:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallgatherv_intra_sched_brucks_call_counter, 1);
                mpi_errno = MPIR_Iallgatherv_intra_sched_brucks(sendbuf, sendcount, sendtype, recvbuf,
                                                                recvcounts, displs, recvtype, comm_ptr,
                                                                *sched_p);
                break;
            case MPIR_CVAR_IALLGATHERV_INTRA_ALGORITHM_sched_recursive_doubling:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, comm_ptr->local_size == comm_ptr->coll.pof2, mpi_errno,
                                               "Iallgatherv sched_recursive_doubling cannot be applied.\n");
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP,
                                        mvp_iallgatherv_intra_sched_recursive_doubling_call_counter,
                                        1);
                mpi_errno = MPIR_Iallgatherv_intra_sched_recursive_doubling(sendbuf, sendcount,
                                    sendtype, recvbuf, recvcounts, displs, recvtype, comm_ptr,
                                    *sched_p);
                break;
            case MPIR_CVAR_IALLGATHERV_INTRA_ALGORITHM_sched_ring:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallgatherv_intra_sched_ring_call_counter, 1);
                mpi_errno = MPIR_Iallgatherv_intra_sched_ring(sendbuf, sendcount, sendtype, recvbuf,
                                                              recvcounts, displs, recvtype, comm_ptr,
                                                              *sched_p);
                break;
            case MPIR_CVAR_IALLGATHERV_INTRA_ALGORITHM_tsp_recexch_doubling:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, MPII_Iallgatherv_is_displs_ordered(comm_ptr->local_size, recvcounts, displs), mpi_errno,
                                               "Iallgatherv tsp_recexch_doubling cannot be applied.\n");
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallgatherv_intra_tsp_recexch_doubling_call_counter,
                                        1);
                mpi_errno = MPIR_TSP_Iallgatherv_sched_intra_recexch(sendbuf, sendcount, sendtype,
                                    recvbuf, recvcounts, displs, recvtype, comm_ptr,
                                    MPIR_IALLGATHERV_RECEXCH_TYPE_DISTANCE_DOUBLING,
                                    MPIR_CVAR_IALLGATHERV_RECEXCH_KVAL, *sched_p);
                break;
            case MPIR_CVAR_IALLGATHERV_INTRA_ALGORITHM_tsp_recexch_halving:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, MPII_Iallgatherv_is_displs_ordered(comm_ptr->local_size, recvcounts, displs), mpi_errno,
                                               "Iallgatherv tsp_recexch_halving cannot be applied.\n");
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallgatherv_intra_tsp_recexch_halving_call_counter,
                                        1);
                mpi_errno = MPIR_TSP_Iallgatherv_sched_intra_recexch(sendbuf, sendcount, sendtype,
                                    recvbuf, recvcounts, displs, recvtype, comm_ptr,
                                    MPIR_IALLGATHERV_RECEXCH_TYPE_DISTANCE_HALVING,
                                    MPIR_CVAR_IALLGATHERV_RECEXCH_KVAL, *sched_p);
                break;
            case MPIR_CVAR_IALLGATHERV_INTRA_ALGORITHM_tsp_ring:
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallgatherv_intra_tsp_ring_call_counter, 1);
                mpi_errno = MPIR_TSP_Iallgatherv_sched_intra_ring(sendbuf, sendcount, sendtype, recvbuf,
                                    recvcounts, displs, recvtype, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IALLGATHERV_INTRA_ALGORITHM_tsp_brucks:
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallgatherv_intra_tsp_brucks_call_counter, 1);
                mpi_errno = MPIR_TSP_Iallgatherv_sched_intra_brucks(sendbuf, sendcount, sendtype,
                                    recvbuf, recvcounts, displs, recvtype, comm_ptr,
                                    MPIR_CVAR_IALLGATHERV_BRUCKS_KVAL, *sched_p);
                break;
            case MPIR_CVAR_IALLGATHERV_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Iallgatherv_allcomm_sched_auto(sendbuf, sendcount, sendtype,
                                recvbuf, recvcounts, displs, recvtype, comm_ptr, is_persistent,
                                sched_p, sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        switch (MPIR_CVAR_IALLGATHERV_INTER_ALGORITHM) {
            case MPIR_CVAR_IALLGATHERV_INTER_ALGORITHM_sched_remote_gather_local_bcast:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP,
                                        mvp_iallgatherv_inter_sched_remote_gather_local_bcast_call_counter,
                                        1);
                mpi_errno = MPIR_Iallgatherv_inter_sched_remote_gather_local_bcast(sendbuf, sendcount,
                                    sendtype, recvbuf, recvcounts, displs, recvtype, comm_ptr,
                                    *sched_p);
                break;
            case MPIR_CVAR_IALLGATHERV_INTER_ALGORITHM_auto:
                mpi_errno = MPIR_Iallgatherv_allcomm_sched_auto(sendbuf, sendcount, sendtype,
                                recvbuf, recvcounts, displs, recvtype, comm_ptr, is_persistent,
                                sched_p, sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    }
    MPIR_ERR_CHECK(mpi_errno);
    goto fn_exit;
    
  fallback:
    mpi_errno = MPIR_Iallgatherv_allcomm_sched_auto(sendbuf, sendcount, sendtype, recvbuf,
                                                    recvcounts, displs, recvtype, comm_ptr,
                                                    is_persistent, sched_p, sched_type_p);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Iallgatherv_impl(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                          void *recvbuf, const MPI_Aint recvcounts[], const MPI_Aint displs[],
                          MPI_Datatype recvtype, MPIR_Comm * comm_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    enum MPIR_sched_type sched_type;
    void *sched;
    
    *request = NULL;
    mpi_errno = MPIR_Iallgatherv_sched_impl(sendbuf, sendcount, sendtype, recvbuf, recvcounts,
                                            displs, recvtype, comm_ptr, false, &sched,
                                            &sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    MPII_SCHED_START(sched_type, sched, comm_ptr, request);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Iallgatherv(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                     const MPI_Aint recvcounts[], const MPI_Aint displs[], MPI_Datatype recvtype,
                     MPIR_Comm * comm_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_iallgatherv_call_counter, mvp_iallgatherv_timer);
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_IALLGATHERV_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Iallgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs,
                                     recvtype, comm_ptr, request);
    } else {
        mpi_errno = MPIR_Iallgatherv_impl(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs,
                                          recvtype, comm_ptr, request);
    }
    
    MVP_COLL_PVAR_UPDATE_END(mvp_iallgatherv_timer);
    
    return mpi_errno;
}

int MPIR_Allgatherv_init_impl(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                              void *recvbuf, const MPI_Aint recvcounts[], const MPI_Aint displs[],
                              MPI_Datatype recvtype, MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                              MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Request *req = MPIR_Request_create(MPIR_REQUEST_KIND__PREQUEST_COLL);
    MPIR_ERR_CHKANDJUMP(!req, mpi_errno, MPI_ERR_OTHER, "**nomem");
    MPIR_Comm_add_ref(comm_ptr);
    req->comm = comm_ptr;
    MPIR_Comm_save_inactive_request(comm_ptr, req);
    req->u.persist_coll.sched_type = MPIR_SCHED_INVALID;
    req->u.persist_coll.real_request = NULL;
    mpi_errno = MPIR_Iallgatherv_sched_impl(sendbuf, sendcount, sendtype, recvbuf, recvcounts,
                                            displs, recvtype, comm_ptr, true,
                                            &req->u.persist_coll.sched,
                                            &req->u.persist_coll.sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    
    *request = req;
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Allgatherv_init(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                         void *recvbuf, const MPI_Aint recvcounts[], const MPI_Aint displs[],
                         MPI_Datatype recvtype, MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                         MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_ALLGATHERV_INIT_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Allgatherv_init(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs,
                                         recvtype, comm_ptr, info_ptr, request);
    } else {
        mpi_errno = MPIR_Allgatherv_init_impl(sendbuf, sendcount, sendtype, recvbuf, recvcounts,
                                              displs, recvtype, comm_ptr, info_ptr, request);
    }
    
    return mpi_errno;
}

/* ---- alltoall ---- */

int MPIR_Alltoall_allcomm_auto(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                               void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                               MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__ALLTOALL,
        .comm_ptr = comm_ptr,
        .u.alltoall.sendbuf = sendbuf,
        .u.alltoall.sendcount = sendcount,
        .u.alltoall.sendtype = sendtype,
        .u.alltoall.recvbuf = recvbuf,
        .u.alltoall.recvcount = recvcount,
        .u.alltoall.recvtype = recvtype,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Alltoall_intra_brucks:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_alltoall_intra_brucks_call_counter, 1);
            mpi_errno = MPIR_Alltoall_intra_brucks(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                                   recvtype, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Alltoall_intra_k_brucks:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_alltoall_intra_k_brucks_call_counter, 1);
            mpi_errno = MPIR_Alltoall_intra_k_brucks(sendbuf, sendcount, sendtype, recvbuf,
                                                     recvcount, recvtype, comm_ptr,
                                                     cnt->u.alltoall.intra_k_brucks.k, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Alltoall_intra_pairwise:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_alltoall_intra_pairwise_call_counter, 1);
            mpi_errno = MPIR_Alltoall_intra_pairwise(sendbuf, sendcount, sendtype, recvbuf,
                                                     recvcount, recvtype, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Alltoall_intra_pairwise_sendrecv_replace:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_alltoall_intra_pairwise_sendrecv_replace_call_counter,
                                    1);
            mpi_errno = MPIR_Alltoall_intra_pairwise_sendrecv_replace(sendbuf, sendcount, sendtype,
                                recvbuf, recvcount, recvtype, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Alltoall_intra_scattered:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_alltoall_intra_scattered_call_counter, 1);
            mpi_errno = MPIR_Alltoall_intra_scattered(sendbuf, sendcount, sendtype, recvbuf,
                                                      recvcount, recvtype, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Alltoall_inter_pairwise_exchange:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_alltoall_inter_pairwise_exchange_call_counter, 1);
            mpi_errno = MPIR_Alltoall_inter_pairwise_exchange(sendbuf, sendcount, sendtype, recvbuf,
                                recvcount, recvtype, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Alltoall_allcomm_nb:
           mpi_errno = MPIR_Alltoall_allcomm_nb(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                                recvtype, comm_ptr, errflag);
           break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Alltoall_impl(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                       void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                       MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_ALLTOALL_INTRA_ALGORITHM) {
            case MPIR_CVAR_ALLTOALL_INTRA_ALGORITHM_brucks:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, sendbuf != MPI_IN_PLACE, mpi_errno,
                                               "Alltoall brucks cannot be applied.\n");
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_alltoall_intra_brucks_call_counter, 1);
                mpi_errno = MPIR_Alltoall_intra_brucks(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                                       recvtype, comm_ptr, errflag);
                break;
            case MPIR_CVAR_ALLTOALL_INTRA_ALGORITHM_k_brucks:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, sendbuf != MPI_IN_PLACE, mpi_errno,
                                               "Alltoall k_brucks cannot be applied.\n");
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_alltoall_intra_k_brucks_call_counter, 1);
                mpi_errno = MPIR_Alltoall_intra_k_brucks(sendbuf, sendcount, sendtype, recvbuf,
                                                         recvcount, recvtype, comm_ptr,
                                                         MPIR_CVAR_ALLTOALL_BRUCKS_KVAL, errflag);
                break;
            case MPIR_CVAR_ALLTOALL_INTRA_ALGORITHM_pairwise:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, sendbuf != MPI_IN_PLACE, mpi_errno,
                                               "Alltoall pairwise cannot be applied.\n");
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_alltoall_intra_pairwise_call_counter, 1);
                mpi_errno = MPIR_Alltoall_intra_pairwise(sendbuf, sendcount, sendtype, recvbuf,
                                                         recvcount, recvtype, comm_ptr, errflag);
                break;
            case MPIR_CVAR_ALLTOALL_INTRA_ALGORITHM_pairwise_sendrecv_replace:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, sendbuf == MPI_IN_PLACE, mpi_errno,
                                               "Alltoall pairwise_sendrecv_replace cannot be applied.\n");
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_alltoall_intra_pairwise_sendrecv_replace_call_counter,
                                        1);
                mpi_errno = MPIR_Alltoall_intra_pairwise_sendrecv_replace(sendbuf, sendcount, sendtype,
                                    recvbuf, recvcount, recvtype, comm_ptr, errflag);
                break;
            case MPIR_CVAR_ALLTOALL_INTRA_ALGORITHM_scattered:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, sendbuf != MPI_IN_PLACE, mpi_errno,
                                               "Alltoall scattered cannot be applied.\n");
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_alltoall_intra_scattered_call_counter, 1);
                mpi_errno = MPIR_Alltoall_intra_scattered(sendbuf, sendcount, sendtype, recvbuf,
                                                          recvcount, recvtype, comm_ptr, errflag);
                break;
            case MPIR_CVAR_ALLTOALL_INTRA_ALGORITHM_nb:
                mpi_errno = MPIR_Alltoall_allcomm_nb(sendbuf, sendcount, sendtype, recvbuf,
                                                     recvcount, recvtype, comm_ptr, errflag);
                 break;
            case MPIR_CVAR_ALLTOALL_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Alltoall_allcomm_auto(sendbuf, sendcount, sendtype, recvbuf,
                                                       recvcount, recvtype, comm_ptr, errflag);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        switch (MPIR_CVAR_ALLTOALL_INTER_ALGORITHM) {
            case MPIR_CVAR_ALLTOALL_INTER_ALGORITHM_pairwise_exchange:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_alltoall_inter_pairwise_exchange_call_counter, 1);
                mpi_errno = MPIR_Alltoall_inter_pairwise_exchange(sendbuf, sendcount, sendtype, recvbuf,
                                    recvcount, recvtype, comm_ptr, errflag);
                break;
            case MPIR_CVAR_ALLTOALL_INTER_ALGORITHM_nb:
                mpi_errno = MPIR_Alltoall_allcomm_nb(sendbuf, sendcount, sendtype, recvbuf,
                                                     recvcount, recvtype, comm_ptr, errflag);
                 break;
            case MPIR_CVAR_ALLTOALL_INTER_ALGORITHM_auto:
                mpi_errno = MPIR_Alltoall_allcomm_auto(sendbuf, sendcount, sendtype, recvbuf,
                                                       recvcount, recvtype, comm_ptr, errflag);
                break;
            default:
                MPIR_Assert(0);
        }
    }
    MPIR_ERR_CHECK(mpi_errno);
    goto fn_exit;
    
  fallback:
    mpi_errno = MPIR_Alltoall_allcomm_auto(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                           recvtype, comm_ptr, errflag);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Alltoall(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                  MPI_Aint recvcount, MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                  MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_alltoall_call_counter, mvp_alltoall_timer);
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_ALLTOALL_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                                  comm_ptr, errflag);
    } else {
        mpi_errno = MPIR_Alltoall_impl(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                                       comm_ptr, errflag);
    }
    
    MVP_COLL_PVAR_UPDATE_END(mvp_alltoall_timer);
    
    return mpi_errno;
}

/* ---- ialltoall ---- */

int MPIR_Ialltoall_allcomm_sched_auto(const void *sendbuf, MPI_Aint sendcount,
                                      MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount,
                                      MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                                      bool is_persistent, void **sched_p,
                                      enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__IALLTOALL,
        .comm_ptr = comm_ptr,
        .u.ialltoall.sendbuf = sendbuf,
        .u.ialltoall.sendcount = sendcount,
        .u.ialltoall.sendtype = sendtype,
        .u.ialltoall.recvbuf = recvbuf,
        .u.ialltoall.recvcount = recvcount,
        .u.ialltoall.recvtype = recvtype,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoall_intra_sched_brucks:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoall_intra_sched_brucks_call_counter, 1);
            mpi_errno = MPIR_Ialltoall_intra_sched_brucks(sendbuf, sendcount, sendtype, recvbuf,
                                                          recvcount, recvtype, comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoall_intra_sched_inplace:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoall_intra_sched_inplace_call_counter, 1);
            mpi_errno = MPIR_Ialltoall_intra_sched_inplace(sendbuf, sendcount, sendtype, recvbuf,
                                                           recvcount, recvtype, comm_ptr,
                                                           *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoall_intra_sched_pairwise:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoall_intra_sched_pairwise_call_counter, 1);
            mpi_errno = MPIR_Ialltoall_intra_sched_pairwise(sendbuf, sendcount, sendtype, recvbuf,
                                                            recvcount, recvtype, comm_ptr,
                                                            *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoall_intra_sched_permuted_sendrecv:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoall_intra_sched_permuted_sendrecv_call_counter,
                                    1);
            mpi_errno = MPIR_Ialltoall_intra_sched_permuted_sendrecv(sendbuf, sendcount, sendtype,
                                recvbuf, recvcount, recvtype, comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoall_intra_tsp_ring:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoall_intra_tsp_ring_call_counter, 1);
            mpi_errno = MPIR_TSP_Ialltoall_sched_intra_ring(sendbuf, sendcount, sendtype, recvbuf,
                                                            recvcount, recvtype, comm_ptr,
                                                            *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoall_intra_tsp_brucks:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoall_intra_tsp_brucks_call_counter, 1);
            mpi_errno = MPIR_TSP_Ialltoall_sched_intra_brucks(sendbuf, sendcount, sendtype, recvbuf,
                                recvcount, recvtype, comm_ptr, cnt->u.ialltoall.intra_tsp_brucks.k,
                                cnt->u.ialltoall.intra_tsp_brucks.buffer_per_phase, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoall_intra_tsp_scattered:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoall_intra_tsp_scattered_call_counter, 1);
            mpi_errno = MPIR_TSP_Ialltoall_sched_intra_scattered(sendbuf, sendcount, sendtype,
                                recvbuf, recvcount, recvtype, comm_ptr,
                                cnt->u.ialltoall.intra_tsp_scattered.batch_size,
                                cnt->u.ialltoall.intra_tsp_scattered.bblock, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoall_inter_sched_pairwise_exchange:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoall_inter_sched_pairwise_exchange_call_counter,
                                    1);
            mpi_errno = MPIR_Ialltoall_inter_sched_pairwise_exchange(sendbuf, sendcount, sendtype,
                                recvbuf, recvcount, recvtype, comm_ptr, *sched_p);
            break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ialltoall_sched_impl(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                              void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                              MPIR_Comm * comm_ptr, bool is_persistent, void **sched_p,
                              enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_IALLTOALL_INTRA_ALGORITHM) {
            case MPIR_CVAR_IALLTOALL_INTRA_ALGORITHM_sched_brucks:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, sendbuf != MPI_IN_PLACE, mpi_errno,
                                               "Ialltoall sched_brucks cannot be applied.\n");
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoall_intra_sched_brucks_call_counter, 1);
                mpi_errno = MPIR_Ialltoall_intra_sched_brucks(sendbuf, sendcount, sendtype, recvbuf,
                                                              recvcount, recvtype, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IALLTOALL_INTRA_ALGORITHM_sched_inplace:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, sendbuf == MPI_IN_PLACE, mpi_errno,
                                               "Ialltoall sched_inplace cannot be applied.\n");
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoall_intra_sched_inplace_call_counter, 1);
                mpi_errno = MPIR_Ialltoall_intra_sched_inplace(sendbuf, sendcount, sendtype, recvbuf,
                                                               recvcount, recvtype, comm_ptr,
                                                               *sched_p);
                break;
            case MPIR_CVAR_IALLTOALL_INTRA_ALGORITHM_sched_pairwise:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, sendbuf != MPI_IN_PLACE, mpi_errno,
                                               "Ialltoall sched_pairwise cannot be applied.\n");
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoall_intra_sched_pairwise_call_counter, 1);
                mpi_errno = MPIR_Ialltoall_intra_sched_pairwise(sendbuf, sendcount, sendtype, recvbuf,
                                                                recvcount, recvtype, comm_ptr,
                                                                *sched_p);
                break;
            case MPIR_CVAR_IALLTOALL_INTRA_ALGORITHM_sched_permuted_sendrecv:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, sendbuf != MPI_IN_PLACE, mpi_errno,
                                               "Ialltoall sched_permuted_sendrecv cannot be applied.\n");
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoall_intra_sched_permuted_sendrecv_call_counter,
                                        1);
                mpi_errno = MPIR_Ialltoall_intra_sched_permuted_sendrecv(sendbuf, sendcount, sendtype,
                                    recvbuf, recvcount, recvtype, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IALLTOALL_INTRA_ALGORITHM_tsp_ring:
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoall_intra_tsp_ring_call_counter, 1);
                mpi_errno = MPIR_TSP_Ialltoall_sched_intra_ring(sendbuf, sendcount, sendtype, recvbuf,
                                                                recvcount, recvtype, comm_ptr,
                                                                *sched_p);
                break;
            case MPIR_CVAR_IALLTOALL_INTRA_ALGORITHM_tsp_brucks:
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoall_intra_tsp_brucks_call_counter, 1);
                mpi_errno = MPIR_TSP_Ialltoall_sched_intra_brucks(sendbuf, sendcount, sendtype, recvbuf,
                                    recvcount, recvtype, comm_ptr, MPIR_CVAR_IALLTOALL_BRUCKS_KVAL,
                                    MPIR_CVAR_IALLTOALL_BRUCKS_BUFFER_PER_NBR, *sched_p);
                break;
            case MPIR_CVAR_IALLTOALL_INTRA_ALGORITHM_tsp_scattered:
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoall_intra_tsp_scattered_call_counter, 1);
                mpi_errno = MPIR_TSP_Ialltoall_sched_intra_scattered(sendbuf, sendcount, sendtype,
                                    recvbuf, recvcount, recvtype, comm_ptr,
                                    MPIR_CVAR_IALLTOALL_SCATTERED_BATCH_SIZE,
                                    MPIR_CVAR_IALLTOALL_SCATTERED_OUTSTANDING_TASKS, *sched_p);
                break;
            case MPIR_CVAR_IALLTOALL_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Ialltoall_allcomm_sched_auto(sendbuf, sendcount, sendtype, recvbuf,
                                recvcount, recvtype, comm_ptr, is_persistent, sched_p,
                                sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        switch (MPIR_CVAR_IALLTOALL_INTER_ALGORITHM) {
            case MPIR_CVAR_IALLTOALL_INTER_ALGORITHM_sched_pairwise_exchange:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoall_inter_sched_pairwise_exchange_call_counter,
                                        1);
                mpi_errno = MPIR_Ialltoall_inter_sched_pairwise_exchange(sendbuf, sendcount, sendtype,
                                    recvbuf, recvcount, recvtype, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IALLTOALL_INTER_ALGORITHM_auto:
                mpi_errno = MPIR_Ialltoall_allcomm_sched_auto(sendbuf, sendcount, sendtype, recvbuf,
                                recvcount, recvtype, comm_ptr, is_persistent, sched_p,
                                sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    }
    MPIR_ERR_CHECK(mpi_errno);
    goto fn_exit;
    
  fallback:
    mpi_errno = MPIR_Ialltoall_allcomm_sched_auto(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                                  recvtype, comm_ptr, is_persistent, sched_p,
                                                  sched_type_p);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ialltoall_impl(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                        void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                        MPIR_Comm * comm_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    enum MPIR_sched_type sched_type;
    void *sched;
    
    *request = NULL;
    mpi_errno = MPIR_Ialltoall_sched_impl(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                          recvtype, comm_ptr, false, &sched, &sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    MPII_SCHED_START(sched_type, sched, comm_ptr, request);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ialltoall(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                   MPI_Aint recvcount, MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                   MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_ialltoall_call_counter, mvp_ialltoall_timer);
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_IALLTOALL_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Ialltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                                   comm_ptr, request);
    } else {
        mpi_errno = MPIR_Ialltoall_impl(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                                        comm_ptr, request);
    }
    
    MVP_COLL_PVAR_UPDATE_END(mvp_ialltoall_timer);
    
    return mpi_errno;
}

int MPIR_Alltoall_init_impl(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                            void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                            MPIR_Comm * comm_ptr, MPIR_Info * info_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Request *req = MPIR_Request_create(MPIR_REQUEST_KIND__PREQUEST_COLL);
    MPIR_ERR_CHKANDJUMP(!req, mpi_errno, MPI_ERR_OTHER, "**nomem");
    MPIR_Comm_add_ref(comm_ptr);
    req->comm = comm_ptr;
    MPIR_Comm_save_inactive_request(comm_ptr, req);
    req->u.persist_coll.sched_type = MPIR_SCHED_INVALID;
    req->u.persist_coll.real_request = NULL;
    mpi_errno = MPIR_Ialltoall_sched_impl(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                          recvtype, comm_ptr, true, &req->u.persist_coll.sched,
                                          &req->u.persist_coll.sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    
    *request = req;
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Alltoall_init(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                       void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                       MPIR_Comm * comm_ptr, MPIR_Info * info_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_ALLTOALL_INIT_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Alltoall_init(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                                       comm_ptr, info_ptr, request);
    } else {
        mpi_errno = MPIR_Alltoall_init_impl(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                            recvtype, comm_ptr, info_ptr, request);
    }
    
    return mpi_errno;
}

/* ---- alltoallv ---- */

int MPIR_Alltoallv_allcomm_auto(const void *sendbuf, const MPI_Aint sendcounts[],
                                const MPI_Aint sdispls[], MPI_Datatype sendtype, void *recvbuf,
                                const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                                MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                                MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__ALLTOALLV,
        .comm_ptr = comm_ptr,
        .u.alltoallv.sendbuf = sendbuf,
        .u.alltoallv.sendcounts = sendcounts,
        .u.alltoallv.sdispls = sdispls,
        .u.alltoallv.sendtype = sendtype,
        .u.alltoallv.recvbuf = recvbuf,
        .u.alltoallv.recvcounts = recvcounts,
        .u.alltoallv.rdispls = rdispls,
        .u.alltoallv.recvtype = recvtype,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Alltoallv_intra_pairwise_sendrecv_replace:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_alltoallv_intra_pairwise_sendrecv_replace_call_counter,
                                    1);
            mpi_errno = MPIR_Alltoallv_intra_pairwise_sendrecv_replace(sendbuf, sendcounts, sdispls,
                                sendtype, recvbuf, recvcounts, rdispls, recvtype, comm_ptr,
                                errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Alltoallv_intra_scattered:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_alltoallv_intra_scattered_call_counter, 1);
            mpi_errno = MPIR_Alltoallv_intra_scattered(sendbuf, sendcounts, sdispls, sendtype,
                                                       recvbuf, recvcounts, rdispls, recvtype,
                                                       comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Alltoallv_inter_pairwise_exchange:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_alltoallv_inter_pairwise_exchange_call_counter, 1);
            mpi_errno = MPIR_Alltoallv_inter_pairwise_exchange(sendbuf, sendcounts, sdispls,
                                sendtype, recvbuf, recvcounts, rdispls, recvtype, comm_ptr,
                                errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Alltoallv_allcomm_nb:
           mpi_errno = MPIR_Alltoallv_allcomm_nb(sendbuf, sendcounts, sdispls, sendtype, recvbuf,
                                                 recvcounts, rdispls, recvtype, comm_ptr, errflag);
           break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Alltoallv_impl(const void *sendbuf, const MPI_Aint sendcounts[], const MPI_Aint sdispls[],
                        MPI_Datatype sendtype, void *recvbuf, const MPI_Aint recvcounts[],
                        const MPI_Aint rdispls[], MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                        MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_ALLTOALLV_INTRA_ALGORITHM) {
            case MPIR_CVAR_ALLTOALLV_INTRA_ALGORITHM_pairwise_sendrecv_replace:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, sendbuf == MPI_IN_PLACE, mpi_errno,
                                               "Alltoallv pairwise_sendrecv_replace cannot be applied.\n");
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_alltoallv_intra_pairwise_sendrecv_replace_call_counter,
                                        1);
                mpi_errno = MPIR_Alltoallv_intra_pairwise_sendrecv_replace(sendbuf, sendcounts, sdispls,
                                    sendtype, recvbuf, recvcounts, rdispls, recvtype, comm_ptr,
                                    errflag);
                break;
            case MPIR_CVAR_ALLTOALLV_INTRA_ALGORITHM_scattered:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, sendbuf != MPI_IN_PLACE, mpi_errno,
                                               "Alltoallv scattered cannot be applied.\n");
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_alltoallv_intra_scattered_call_counter, 1);
                mpi_errno = MPIR_Alltoallv_intra_scattered(sendbuf, sendcounts, sdispls, sendtype,
                                                           recvbuf, recvcounts, rdispls, recvtype,
                                                           comm_ptr, errflag);
                break;
            case MPIR_CVAR_ALLTOALLV_INTRA_ALGORITHM_nb:
                mpi_errno = MPIR_Alltoallv_allcomm_nb(sendbuf, sendcounts, sdispls, sendtype,
                                                      recvbuf, recvcounts, rdispls, recvtype,
                                                      comm_ptr, errflag);
                 break;
            case MPIR_CVAR_ALLTOALLV_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Alltoallv_allcomm_auto(sendbuf, sendcounts, sdispls, sendtype,
                                                        recvbuf, recvcounts, rdispls, recvtype,
                                                        comm_ptr, errflag);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        switch (MPIR_CVAR_ALLTOALLV_INTER_ALGORITHM) {
            case MPIR_CVAR_ALLTOALLV_INTER_ALGORITHM_pairwise_exchange:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_alltoallv_inter_pairwise_exchange_call_counter, 1);
                mpi_errno = MPIR_Alltoallv_inter_pairwise_exchange(sendbuf, sendcounts, sdispls,
                                    sendtype, recvbuf, recvcounts, rdispls, recvtype, comm_ptr,
                                    errflag);
                break;
            case MPIR_CVAR_ALLTOALLV_INTER_ALGORITHM_nb:
                mpi_errno = MPIR_Alltoallv_allcomm_nb(sendbuf, sendcounts, sdispls, sendtype,
                                                      recvbuf, recvcounts, rdispls, recvtype,
                                                      comm_ptr, errflag);
                 break;
            case MPIR_CVAR_ALLTOALLV_INTER_ALGORITHM_auto:
                mpi_errno = MPIR_Alltoallv_allcomm_auto(sendbuf, sendcounts, sdispls, sendtype,
                                                        recvbuf, recvcounts, rdispls, recvtype,
                                                        comm_ptr, errflag);
                break;
            default:
                MPIR_Assert(0);
        }
    }
    MPIR_ERR_CHECK(mpi_errno);
    goto fn_exit;
    
  fallback:
    mpi_errno = MPIR_Alltoallv_allcomm_auto(sendbuf, sendcounts, sdispls, sendtype, recvbuf,
                                            recvcounts, rdispls, recvtype, comm_ptr, errflag);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Alltoallv(const void *sendbuf, const MPI_Aint sendcounts[], const MPI_Aint sdispls[],
                   MPI_Datatype sendtype, void *recvbuf, const MPI_Aint recvcounts[],
                   const MPI_Aint rdispls[], MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                   MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_alltoallv_call_counter, mvp_alltoallv_timer);
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_ALLTOALLV_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts,
                                   rdispls, recvtype, comm_ptr, errflag);
    } else {
        mpi_errno = MPIR_Alltoallv_impl(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts,
                                        rdispls, recvtype, comm_ptr, errflag);
    }
    
    MVP_COLL_PVAR_UPDATE_END(mvp_alltoallv_timer);
    
    return mpi_errno;
}

/* ---- ialltoallv ---- */

int MPIR_Ialltoallv_allcomm_sched_auto(const void *sendbuf, const MPI_Aint sendcounts[],
                                       const MPI_Aint sdispls[], MPI_Datatype sendtype,
                                       void *recvbuf, const MPI_Aint recvcounts[],
                                       const MPI_Aint rdispls[], MPI_Datatype recvtype,
                                       MPIR_Comm * comm_ptr, bool is_persistent, void **sched_p,
                                       enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__IALLTOALLV,
        .comm_ptr = comm_ptr,
        .u.ialltoallv.sendbuf = sendbuf,
        .u.ialltoallv.sendcounts = sendcounts,
        .u.ialltoallv.sdispls = sdispls,
        .u.ialltoallv.sendtype = sendtype,
        .u.ialltoallv.recvbuf = recvbuf,
        .u.ialltoallv.recvcounts = recvcounts,
        .u.ialltoallv.rdispls = rdispls,
        .u.ialltoallv.recvtype = recvtype,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoallv_intra_sched_blocked:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoallv_intra_sched_blocked_call_counter, 1);
            mpi_errno = MPIR_Ialltoallv_intra_sched_blocked(sendbuf, sendcounts, sdispls, sendtype,
                                                            recvbuf, recvcounts, rdispls, recvtype,
                                                            comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoallv_intra_sched_inplace:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoallv_intra_sched_inplace_call_counter, 1);
            mpi_errno = MPIR_Ialltoallv_intra_sched_inplace(sendbuf, sendcounts, sdispls, sendtype,
                                                            recvbuf, recvcounts, rdispls, recvtype,
                                                            comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoallv_intra_tsp_scattered:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoallv_intra_tsp_scattered_call_counter, 1);
            mpi_errno = MPIR_TSP_Ialltoallv_sched_intra_scattered(sendbuf, sendcounts, sdispls,
                                sendtype, recvbuf, recvcounts, rdispls, recvtype, comm_ptr,
                                cnt->u.ialltoallv.intra_tsp_scattered.batch_size,
                                cnt->u.ialltoallv.intra_tsp_scattered.bblock, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoallv_intra_tsp_blocked:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoallv_intra_tsp_blocked_call_counter, 1);
            mpi_errno = MPIR_TSP_Ialltoallv_sched_intra_blocked(sendbuf, sendcounts, sdispls,
                                sendtype, recvbuf, recvcounts, rdispls, recvtype, comm_ptr,
                                cnt->u.ialltoallv.intra_tsp_blocked.bblock, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoallv_intra_tsp_inplace:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoallv_intra_tsp_inplace_call_counter, 1);
            mpi_errno = MPIR_TSP_Ialltoallv_sched_intra_inplace(sendbuf, sendcounts, sdispls,
                                sendtype, recvbuf, recvcounts, rdispls, recvtype, comm_ptr,
                                *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoallv_inter_sched_pairwise_exchange:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoallv_inter_sched_pairwise_exchange_call_counter,
                                    1);
            mpi_errno = MPIR_Ialltoallv_inter_sched_pairwise_exchange(sendbuf, sendcounts, sdispls,
                                sendtype, recvbuf, recvcounts, rdispls, recvtype, comm_ptr,
                                *sched_p);
            break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ialltoallv_sched_impl(const void *sendbuf, const MPI_Aint sendcounts[],
                               const MPI_Aint sdispls[], MPI_Datatype sendtype, void *recvbuf,
                               const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                               MPI_Datatype recvtype, MPIR_Comm * comm_ptr, bool is_persistent,
                               void **sched_p, enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_IALLTOALLV_INTRA_ALGORITHM) {
            case MPIR_CVAR_IALLTOALLV_INTRA_ALGORITHM_sched_blocked:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, sendbuf != MPI_IN_PLACE, mpi_errno,
                                               "Ialltoallv sched_blocked cannot be applied.\n");
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoallv_intra_sched_blocked_call_counter, 1);
                mpi_errno = MPIR_Ialltoallv_intra_sched_blocked(sendbuf, sendcounts, sdispls, sendtype,
                                                                recvbuf, recvcounts, rdispls, recvtype,
                                                                comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IALLTOALLV_INTRA_ALGORITHM_sched_inplace:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, sendbuf == MPI_IN_PLACE, mpi_errno,
                                               "Ialltoallv sched_inplace cannot be applied.\n");
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoallv_intra_sched_inplace_call_counter, 1);
                mpi_errno = MPIR_Ialltoallv_intra_sched_inplace(sendbuf, sendcounts, sdispls, sendtype,
                                                                recvbuf, recvcounts, rdispls, recvtype,
                                                                comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IALLTOALLV_INTRA_ALGORITHM_tsp_scattered:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, sendbuf != MPI_IN_PLACE, mpi_errno,
                                               "Ialltoallv tsp_scattered cannot be applied.\n");
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoallv_intra_tsp_scattered_call_counter, 1);
                mpi_errno = MPIR_TSP_Ialltoallv_sched_intra_scattered(sendbuf, sendcounts, sdispls,
                                    sendtype, recvbuf, recvcounts, rdispls, recvtype, comm_ptr,
                                    MPIR_CVAR_IALLTOALLV_SCATTERED_BATCH_SIZE,
                                    MPIR_CVAR_IALLTOALLV_SCATTERED_OUTSTANDING_TASKS, *sched_p);
                break;
            case MPIR_CVAR_IALLTOALLV_INTRA_ALGORITHM_tsp_blocked:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, sendbuf != MPI_IN_PLACE, mpi_errno,
                                               "Ialltoallv tsp_blocked cannot be applied.\n");
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoallv_intra_tsp_blocked_call_counter, 1);
                mpi_errno = MPIR_TSP_Ialltoallv_sched_intra_blocked(sendbuf, sendcounts, sdispls,
                                    sendtype, recvbuf, recvcounts, rdispls, recvtype, comm_ptr,
                                    MPIR_CVAR_ALLTOALL_THROTTLE, *sched_p);
                break;
            case MPIR_CVAR_IALLTOALLV_INTRA_ALGORITHM_tsp_inplace:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, sendbuf == MPI_IN_PLACE, mpi_errno,
                                               "Ialltoallv tsp_inplace cannot be applied.\n");
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoallv_intra_tsp_inplace_call_counter, 1);
                mpi_errno = MPIR_TSP_Ialltoallv_sched_intra_inplace(sendbuf, sendcounts, sdispls,
                                    sendtype, recvbuf, recvcounts, rdispls, recvtype, comm_ptr,
                                    *sched_p);
                break;
            case MPIR_CVAR_IALLTOALLV_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Ialltoallv_allcomm_sched_auto(sendbuf, sendcounts, sdispls,
                                sendtype, recvbuf, recvcounts, rdispls, recvtype, comm_ptr,
                                is_persistent, sched_p, sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        switch (MPIR_CVAR_IALLTOALLV_INTER_ALGORITHM) {
            case MPIR_CVAR_IALLTOALLV_INTER_ALGORITHM_sched_pairwise_exchange:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoallv_inter_sched_pairwise_exchange_call_counter,
                                        1);
                mpi_errno = MPIR_Ialltoallv_inter_sched_pairwise_exchange(sendbuf, sendcounts, sdispls,
                                    sendtype, recvbuf, recvcounts, rdispls, recvtype, comm_ptr,
                                    *sched_p);
                break;
            case MPIR_CVAR_IALLTOALLV_INTER_ALGORITHM_auto:
                mpi_errno = MPIR_Ialltoallv_allcomm_sched_auto(sendbuf, sendcounts, sdispls,
                                sendtype, recvbuf, recvcounts, rdispls, recvtype, comm_ptr,
                                is_persistent, sched_p, sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    }
    MPIR_ERR_CHECK(mpi_errno);
    goto fn_exit;
    
  fallback:
    mpi_errno = MPIR_Ialltoallv_allcomm_sched_auto(sendbuf, sendcounts, sdispls, sendtype, recvbuf,
                                                   recvcounts, rdispls, recvtype, comm_ptr,
                                                   is_persistent, sched_p, sched_type_p);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ialltoallv_impl(const void *sendbuf, const MPI_Aint sendcounts[], const MPI_Aint sdispls[],
                         MPI_Datatype sendtype, void *recvbuf, const MPI_Aint recvcounts[],
                         const MPI_Aint rdispls[], MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                         MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    enum MPIR_sched_type sched_type;
    void *sched;
    
    *request = NULL;
    mpi_errno = MPIR_Ialltoallv_sched_impl(sendbuf, sendcounts, sdispls, sendtype, recvbuf,
                                           recvcounts, rdispls, recvtype, comm_ptr, false, &sched,
                                           &sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    MPII_SCHED_START(sched_type, sched, comm_ptr, request);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ialltoallv(const void *sendbuf, const MPI_Aint sendcounts[], const MPI_Aint sdispls[],
                    MPI_Datatype sendtype, void *recvbuf, const MPI_Aint recvcounts[],
                    const MPI_Aint rdispls[], MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                    MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_ialltoallv_call_counter, mvp_ialltoallv_timer);
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_IALLTOALLV_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Ialltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts,
                                    rdispls, recvtype, comm_ptr, request);
    } else {
        mpi_errno = MPIR_Ialltoallv_impl(sendbuf, sendcounts, sdispls, sendtype, recvbuf,
                                         recvcounts, rdispls, recvtype, comm_ptr, request);
    }
    
    MVP_COLL_PVAR_UPDATE_END(mvp_ialltoallv_timer);
    
    return mpi_errno;
}

int MPIR_Alltoallv_init_impl(const void *sendbuf, const MPI_Aint sendcounts[],
                             const MPI_Aint sdispls[], MPI_Datatype sendtype, void *recvbuf,
                             const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                             MPI_Datatype recvtype, MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                             MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Request *req = MPIR_Request_create(MPIR_REQUEST_KIND__PREQUEST_COLL);
    MPIR_ERR_CHKANDJUMP(!req, mpi_errno, MPI_ERR_OTHER, "**nomem");
    MPIR_Comm_add_ref(comm_ptr);
    req->comm = comm_ptr;
    MPIR_Comm_save_inactive_request(comm_ptr, req);
    req->u.persist_coll.sched_type = MPIR_SCHED_INVALID;
    req->u.persist_coll.real_request = NULL;
    mpi_errno = MPIR_Ialltoallv_sched_impl(sendbuf, sendcounts, sdispls, sendtype, recvbuf,
                                           recvcounts, rdispls, recvtype, comm_ptr, true,
                                           &req->u.persist_coll.sched,
                                           &req->u.persist_coll.sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    
    *request = req;
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Alltoallv_init(const void *sendbuf, const MPI_Aint sendcounts[], const MPI_Aint sdispls[],
                        MPI_Datatype sendtype, void *recvbuf, const MPI_Aint recvcounts[],
                        const MPI_Aint rdispls[], MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                        MPIR_Info * info_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_ALLTOALLV_INIT_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Alltoallv_init(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts,
                                        rdispls, recvtype, comm_ptr, info_ptr, request);
    } else {
        mpi_errno = MPIR_Alltoallv_init_impl(sendbuf, sendcounts, sdispls, sendtype, recvbuf,
                                             recvcounts, rdispls, recvtype, comm_ptr, info_ptr,
                                             request);
    }
    
    return mpi_errno;
}

/* ---- alltoallw ---- */

int MPIR_Alltoallw_allcomm_auto(const void *sendbuf, const MPI_Aint sendcounts[],
                                const MPI_Aint sdispls[], const MPI_Datatype sendtypes[],
                                void *recvbuf, const MPI_Aint recvcounts[],
                                const MPI_Aint rdispls[], const MPI_Datatype recvtypes[],
                                MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__ALLTOALLW,
        .comm_ptr = comm_ptr,
        .u.alltoallw.sendbuf = sendbuf,
        .u.alltoallw.sendcounts = sendcounts,
        .u.alltoallw.sdispls = sdispls,
        .u.alltoallw.sendtypes = sendtypes,
        .u.alltoallw.recvbuf = recvbuf,
        .u.alltoallw.recvcounts = recvcounts,
        .u.alltoallw.rdispls = rdispls,
        .u.alltoallw.recvtypes = recvtypes,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Alltoallw_intra_pairwise_sendrecv_replace:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_alltoallw_intra_pairwise_sendrecv_replace_call_counter,
                                    1);
            mpi_errno = MPIR_Alltoallw_intra_pairwise_sendrecv_replace(sendbuf, sendcounts, sdispls,
                                sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm_ptr,
                                errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Alltoallw_intra_scattered:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_alltoallw_intra_scattered_call_counter, 1);
            mpi_errno = MPIR_Alltoallw_intra_scattered(sendbuf, sendcounts, sdispls, sendtypes,
                                                       recvbuf, recvcounts, rdispls, recvtypes,
                                                       comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Alltoallw_inter_pairwise_exchange:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_alltoallw_inter_pairwise_exchange_call_counter, 1);
            mpi_errno = MPIR_Alltoallw_inter_pairwise_exchange(sendbuf, sendcounts, sdispls,
                                sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm_ptr,
                                errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Alltoallw_allcomm_nb:
           mpi_errno = MPIR_Alltoallw_allcomm_nb(sendbuf, sendcounts, sdispls, sendtypes, recvbuf,
                                                 recvcounts, rdispls, recvtypes, comm_ptr,
                                                 errflag);
           break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Alltoallw_impl(const void *sendbuf, const MPI_Aint sendcounts[], const MPI_Aint sdispls[],
                        const MPI_Datatype sendtypes[], void *recvbuf, const MPI_Aint recvcounts[],
                        const MPI_Aint rdispls[], const MPI_Datatype recvtypes[],
                        MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_ALLTOALLW_INTRA_ALGORITHM) {
            case MPIR_CVAR_ALLTOALLW_INTRA_ALGORITHM_pairwise_sendrecv_replace:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, sendbuf == MPI_IN_PLACE, mpi_errno,
                                               "Alltoallw pairwise_sendrecv_replace cannot be applied.\n");
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_alltoallw_intra_pairwise_sendrecv_replace_call_counter,
                                        1);
                mpi_errno = MPIR_Alltoallw_intra_pairwise_sendrecv_replace(sendbuf, sendcounts, sdispls,
                                    sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm_ptr,
                                    errflag);
                break;
            case MPIR_CVAR_ALLTOALLW_INTRA_ALGORITHM_scattered:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, sendbuf != MPI_IN_PLACE, mpi_errno,
                                               "Alltoallw scattered cannot be applied.\n");
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_alltoallw_intra_scattered_call_counter, 1);
                mpi_errno = MPIR_Alltoallw_intra_scattered(sendbuf, sendcounts, sdispls, sendtypes,
                                                           recvbuf, recvcounts, rdispls, recvtypes,
                                                           comm_ptr, errflag);
                break;
            case MPIR_CVAR_ALLTOALLW_INTRA_ALGORITHM_nb:
                mpi_errno = MPIR_Alltoallw_allcomm_nb(sendbuf, sendcounts, sdispls, sendtypes,
                                                      recvbuf, recvcounts, rdispls, recvtypes,
                                                      comm_ptr, errflag);
                 break;
            case MPIR_CVAR_ALLTOALLW_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Alltoallw_allcomm_auto(sendbuf, sendcounts, sdispls, sendtypes,
                                                        recvbuf, recvcounts, rdispls, recvtypes,
                                                        comm_ptr, errflag);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        switch (MPIR_CVAR_ALLTOALLW_INTER_ALGORITHM) {
            case MPIR_CVAR_ALLTOALLW_INTER_ALGORITHM_pairwise_exchange:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_alltoallw_inter_pairwise_exchange_call_counter, 1);
                mpi_errno = MPIR_Alltoallw_inter_pairwise_exchange(sendbuf, sendcounts, sdispls,
                                    sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm_ptr,
                                    errflag);
                break;
            case MPIR_CVAR_ALLTOALLW_INTER_ALGORITHM_nb:
                mpi_errno = MPIR_Alltoallw_allcomm_nb(sendbuf, sendcounts, sdispls, sendtypes,
                                                      recvbuf, recvcounts, rdispls, recvtypes,
                                                      comm_ptr, errflag);
                 break;
            case MPIR_CVAR_ALLTOALLW_INTER_ALGORITHM_auto:
                mpi_errno = MPIR_Alltoallw_allcomm_auto(sendbuf, sendcounts, sdispls, sendtypes,
                                                        recvbuf, recvcounts, rdispls, recvtypes,
                                                        comm_ptr, errflag);
                break;
            default:
                MPIR_Assert(0);
        }
    }
    MPIR_ERR_CHECK(mpi_errno);
    goto fn_exit;
    
  fallback:
    mpi_errno = MPIR_Alltoallw_allcomm_auto(sendbuf, sendcounts, sdispls, sendtypes, recvbuf,
                                            recvcounts, rdispls, recvtypes, comm_ptr, errflag);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Alltoallw(const void *sendbuf, const MPI_Aint sendcounts[], const MPI_Aint sdispls[],
                   const MPI_Datatype sendtypes[], void *recvbuf, const MPI_Aint recvcounts[],
                   const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPIR_Comm * comm_ptr,
                   MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_alltoallw_call_counter, mvp_alltoallw_timer);
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_ALLTOALLW_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts,
                                   rdispls, recvtypes, comm_ptr, errflag);
    } else {
        mpi_errno = MPIR_Alltoallw_impl(sendbuf, sendcounts, sdispls, sendtypes, recvbuf,
                                        recvcounts, rdispls, recvtypes, comm_ptr, errflag);
    }
    
    MVP_COLL_PVAR_UPDATE_END(mvp_alltoallw_timer);
    
    return mpi_errno;
}

/* ---- ialltoallw ---- */

int MPIR_Ialltoallw_allcomm_sched_auto(const void *sendbuf, const MPI_Aint sendcounts[],
                                       const MPI_Aint sdispls[], const MPI_Datatype sendtypes[],
                                       void *recvbuf, const MPI_Aint recvcounts[],
                                       const MPI_Aint rdispls[], const MPI_Datatype recvtypes[],
                                       MPIR_Comm * comm_ptr, bool is_persistent, void **sched_p,
                                       enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__IALLTOALLW,
        .comm_ptr = comm_ptr,
        .u.ialltoallw.sendbuf = sendbuf,
        .u.ialltoallw.sendcounts = sendcounts,
        .u.ialltoallw.sdispls = sdispls,
        .u.ialltoallw.sendtypes = sendtypes,
        .u.ialltoallw.recvbuf = recvbuf,
        .u.ialltoallw.recvcounts = recvcounts,
        .u.ialltoallw.rdispls = rdispls,
        .u.ialltoallw.recvtypes = recvtypes,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoallw_intra_sched_blocked:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoallw_intra_sched_blocked_call_counter, 1);
            mpi_errno = MPIR_Ialltoallw_intra_sched_blocked(sendbuf, sendcounts, sdispls, sendtypes,
                                                            recvbuf, recvcounts, rdispls, recvtypes,
                                                            comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoallw_intra_sched_inplace:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoallw_intra_sched_inplace_call_counter, 1);
            mpi_errno = MPIR_Ialltoallw_intra_sched_inplace(sendbuf, sendcounts, sdispls, sendtypes,
                                                            recvbuf, recvcounts, rdispls, recvtypes,
                                                            comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoallw_intra_tsp_blocked:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoallw_intra_tsp_blocked_call_counter, 1);
            mpi_errno = MPIR_TSP_Ialltoallw_sched_intra_blocked(sendbuf, sendcounts, sdispls,
                                sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm_ptr,
                                cnt->u.ialltoallw.intra_tsp_blocked.bblock, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoallw_intra_tsp_inplace:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoallw_intra_tsp_inplace_call_counter, 1);
            mpi_errno = MPIR_TSP_Ialltoallw_sched_intra_inplace(sendbuf, sendcounts, sdispls,
                                sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm_ptr,
                                *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoallw_inter_sched_pairwise_exchange:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoallw_inter_sched_pairwise_exchange_call_counter,
                                    1);
            mpi_errno = MPIR_Ialltoallw_inter_sched_pairwise_exchange(sendbuf, sendcounts, sdispls,
                                sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm_ptr,
                                *sched_p);
            break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ialltoallw_sched_impl(const void *sendbuf, const MPI_Aint sendcounts[],
                               const MPI_Aint sdispls[], const MPI_Datatype sendtypes[],
                               void *recvbuf, const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                               const MPI_Datatype recvtypes[], MPIR_Comm * comm_ptr,
                               bool is_persistent, void **sched_p,
                               enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_IALLTOALLW_INTRA_ALGORITHM) {
            case MPIR_CVAR_IALLTOALLW_INTRA_ALGORITHM_sched_blocked:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, sendbuf != MPI_IN_PLACE, mpi_errno,
                                               "Ialltoallw sched_blocked cannot be applied.\n");
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoallw_intra_sched_blocked_call_counter, 1);
                mpi_errno = MPIR_Ialltoallw_intra_sched_blocked(sendbuf, sendcounts, sdispls, sendtypes,
                                                                recvbuf, recvcounts, rdispls, recvtypes,
                                                                comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IALLTOALLW_INTRA_ALGORITHM_sched_inplace:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, sendbuf == MPI_IN_PLACE, mpi_errno,
                                               "Ialltoallw sched_inplace cannot be applied.\n");
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoallw_intra_sched_inplace_call_counter, 1);
                mpi_errno = MPIR_Ialltoallw_intra_sched_inplace(sendbuf, sendcounts, sdispls, sendtypes,
                                                                recvbuf, recvcounts, rdispls, recvtypes,
                                                                comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IALLTOALLW_INTRA_ALGORITHM_tsp_blocked:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, sendbuf != MPI_IN_PLACE, mpi_errno,
                                               "Ialltoallw tsp_blocked cannot be applied.\n");
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoallw_intra_tsp_blocked_call_counter, 1);
                mpi_errno = MPIR_TSP_Ialltoallw_sched_intra_blocked(sendbuf, sendcounts, sdispls,
                                    sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm_ptr,
                                    MPIR_CVAR_ALLTOALL_THROTTLE, *sched_p);
                break;
            case MPIR_CVAR_IALLTOALLW_INTRA_ALGORITHM_tsp_inplace:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, sendbuf == MPI_IN_PLACE, mpi_errno,
                                               "Ialltoallw tsp_inplace cannot be applied.\n");
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoallw_intra_tsp_inplace_call_counter, 1);
                mpi_errno = MPIR_TSP_Ialltoallw_sched_intra_inplace(sendbuf, sendcounts, sdispls,
                                    sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm_ptr,
                                    *sched_p);
                break;
            case MPIR_CVAR_IALLTOALLW_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Ialltoallw_allcomm_sched_auto(sendbuf, sendcounts, sdispls,
                                sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm_ptr,
                                is_persistent, sched_p, sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        switch (MPIR_CVAR_IALLTOALLW_INTER_ALGORITHM) {
            case MPIR_CVAR_IALLTOALLW_INTER_ALGORITHM_sched_pairwise_exchange:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ialltoallw_inter_sched_pairwise_exchange_call_counter,
                                        1);
                mpi_errno = MPIR_Ialltoallw_inter_sched_pairwise_exchange(sendbuf, sendcounts, sdispls,
                                    sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm_ptr,
                                    *sched_p);
                break;
            case MPIR_CVAR_IALLTOALLW_INTER_ALGORITHM_auto:
                mpi_errno = MPIR_Ialltoallw_allcomm_sched_auto(sendbuf, sendcounts, sdispls,
                                sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm_ptr,
                                is_persistent, sched_p, sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    }
    MPIR_ERR_CHECK(mpi_errno);
    goto fn_exit;
    
  fallback:
    mpi_errno = MPIR_Ialltoallw_allcomm_sched_auto(sendbuf, sendcounts, sdispls, sendtypes, recvbuf,
                                                   recvcounts, rdispls, recvtypes, comm_ptr,
                                                   is_persistent, sched_p, sched_type_p);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ialltoallw_impl(const void *sendbuf, const MPI_Aint sendcounts[], const MPI_Aint sdispls[],
                         const MPI_Datatype sendtypes[], void *recvbuf, const MPI_Aint recvcounts[],
                         const MPI_Aint rdispls[], const MPI_Datatype recvtypes[],
                         MPIR_Comm * comm_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    enum MPIR_sched_type sched_type;
    void *sched;
    
    *request = NULL;
    mpi_errno = MPIR_Ialltoallw_sched_impl(sendbuf, sendcounts, sdispls, sendtypes, recvbuf,
                                           recvcounts, rdispls, recvtypes, comm_ptr, false, &sched,
                                           &sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    MPII_SCHED_START(sched_type, sched, comm_ptr, request);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ialltoallw(const void *sendbuf, const MPI_Aint sendcounts[], const MPI_Aint sdispls[],
                    const MPI_Datatype sendtypes[], void *recvbuf, const MPI_Aint recvcounts[],
                    const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPIR_Comm * comm_ptr,
                    MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_ialltoallw_call_counter, mvp_ialltoallw_timer);
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_IALLTOALLW_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Ialltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts,
                                    rdispls, recvtypes, comm_ptr, request);
    } else {
        mpi_errno = MPIR_Ialltoallw_impl(sendbuf, sendcounts, sdispls, sendtypes, recvbuf,
                                         recvcounts, rdispls, recvtypes, comm_ptr, request);
    }
    
    MVP_COLL_PVAR_UPDATE_END(mvp_ialltoallw_timer);
    
    return mpi_errno;
}

int MPIR_Alltoallw_init_impl(const void *sendbuf, const MPI_Aint sendcounts[],
                             const MPI_Aint sdispls[], const MPI_Datatype sendtypes[],
                             void *recvbuf, const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                             const MPI_Datatype recvtypes[], MPIR_Comm * comm_ptr,
                             MPIR_Info * info_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Request *req = MPIR_Request_create(MPIR_REQUEST_KIND__PREQUEST_COLL);
    MPIR_ERR_CHKANDJUMP(!req, mpi_errno, MPI_ERR_OTHER, "**nomem");
    MPIR_Comm_add_ref(comm_ptr);
    req->comm = comm_ptr;
    MPIR_Comm_save_inactive_request(comm_ptr, req);
    req->u.persist_coll.sched_type = MPIR_SCHED_INVALID;
    req->u.persist_coll.real_request = NULL;
    mpi_errno = MPIR_Ialltoallw_sched_impl(sendbuf, sendcounts, sdispls, sendtypes, recvbuf,
                                           recvcounts, rdispls, recvtypes, comm_ptr, true,
                                           &req->u.persist_coll.sched,
                                           &req->u.persist_coll.sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    
    *request = req;
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Alltoallw_init(const void *sendbuf, const MPI_Aint sendcounts[], const MPI_Aint sdispls[],
                        const MPI_Datatype sendtypes[], void *recvbuf, const MPI_Aint recvcounts[],
                        const MPI_Aint rdispls[], const MPI_Datatype recvtypes[],
                        MPIR_Comm * comm_ptr, MPIR_Info * info_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_ALLTOALLW_INIT_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Alltoallw_init(sendbuf, sendcounts, sdispls, sendtypes, recvbuf,
                                        recvcounts, rdispls, recvtypes, comm_ptr, info_ptr,
                                        request);
    } else {
        mpi_errno = MPIR_Alltoallw_init_impl(sendbuf, sendcounts, sdispls, sendtypes, recvbuf,
                                             recvcounts, rdispls, recvtypes, comm_ptr, info_ptr,
                                             request);
    }
    
    return mpi_errno;
}

/* ---- reduce ---- */

int MPIR_Reduce_allcomm_auto(const void *sendbuf, void *recvbuf, MPI_Aint count,
                             MPI_Datatype datatype, MPI_Op op, int root, MPIR_Comm * comm_ptr,
                             MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__REDUCE,
        .comm_ptr = comm_ptr,
        .u.reduce.sendbuf = sendbuf,
        .u.reduce.recvbuf = recvbuf,
        .u.reduce.count = count,
        .u.reduce.datatype = datatype,
        .u.reduce.op = op,
        .u.reduce.root = root,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_intra_binomial:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_reduce_intra_binomial_call_counter, 1);
            mpi_errno = MPIR_Reduce_intra_binomial(sendbuf, recvbuf, count, datatype, op, root,
                                                   comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_intra_smp:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_reduce_intra_smp_call_counter, 1);
            mpi_errno = MPIR_Reduce_intra_smp(sendbuf, recvbuf, count, datatype, op, root, comm_ptr,
                                              errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_intra_reduce_scatter_gather:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_reduce_intra_reduce_scatter_gather_call_counter, 1);
            mpi_errno = MPIR_Reduce_intra_reduce_scatter_gather(sendbuf, recvbuf, count, datatype,
                                op, root, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_intra_osu_knomial:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_reduce_intra_osu_knomial_call_counter, 1);
            mpi_errno = MPIR_Reduce_intra_osu_knomial(sendbuf, recvbuf, count, datatype, op, root,
                                                      comm_ptr,
                                                      cnt->u.reduce.intra_osu_knomial.inter_kf,
                                                      cnt->u.reduce.intra_osu_knomial.intra_kf,
                                                      errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_intra_osu_allreduce:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_reduce_intra_osu_allreduce_call_counter, 1);
            mpi_errno = MPIR_Reduce_intra_osu_allreduce(sendbuf, recvbuf, count, datatype, op, root,
                                                        comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_inter_local_reduce_remote_send:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_reduce_inter_local_reduce_remote_send_call_counter,
                                    1);
            mpi_errno = MPIR_Reduce_inter_local_reduce_remote_send(sendbuf, recvbuf, count,
                                datatype, op, root, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_allcomm_nb:
           mpi_errno = MPIR_Reduce_allcomm_nb(sendbuf, recvbuf, count, datatype, op, root, comm_ptr,
                                              errflag);
           break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Reduce_impl(const void *sendbuf, void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                     MPI_Op op, int root, MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_REDUCE_INTRA_ALGORITHM) {
            case MPIR_CVAR_REDUCE_INTRA_ALGORITHM_binomial:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_reduce_intra_binomial_call_counter, 1);
                mpi_errno = MPIR_Reduce_intra_binomial(sendbuf, recvbuf, count, datatype, op, root,
                                                       comm_ptr, errflag);
                break;
            case MPIR_CVAR_REDUCE_INTRA_ALGORITHM_smp:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, MPIR_Op_is_commutative(op) && MPIR_Comm_is_parent_comm(comm_ptr), mpi_errno,
                                               "Reduce smp cannot be applied.\n");
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_reduce_intra_smp_call_counter, 1);
                mpi_errno = MPIR_Reduce_intra_smp(sendbuf, recvbuf, count, datatype, op, root, comm_ptr,
                                                  errflag);
                break;
            case MPIR_CVAR_REDUCE_INTRA_ALGORITHM_reduce_scatter_gather:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, count >= comm_ptr->coll.pof2 && HANDLE_IS_BUILTIN(op), mpi_errno,
                                               "Reduce reduce_scatter_gather cannot be applied.\n");
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_reduce_intra_reduce_scatter_gather_call_counter, 1);
                mpi_errno = MPIR_Reduce_intra_reduce_scatter_gather(sendbuf, recvbuf, count, datatype,
                                    op, root, comm_ptr, errflag);
                break;
            case MPIR_CVAR_REDUCE_INTRA_ALGORITHM_osu_knomial:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_reduce_intra_osu_knomial_call_counter, 1);
                mpi_errno = MPIR_Reduce_intra_osu_knomial(sendbuf, recvbuf, count, datatype, op, root,
                                                          comm_ptr,
                                                          MPIR_CVAR_REDUCE_INTER_KNOMIAL_FACTOR,
                                                          MPIR_CVAR_REDUCE_INTRA_KNOMIAL_FACTOR,
                                                          errflag);
                break;
            case MPIR_CVAR_REDUCE_INTRA_ALGORITHM_osu_allreduce:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_reduce_intra_osu_allreduce_call_counter, 1);
                mpi_errno = MPIR_Reduce_intra_osu_allreduce(sendbuf, recvbuf, count, datatype, op, root,
                                                            comm_ptr, errflag);
                break;
            case MPIR_CVAR_REDUCE_INTRA_ALGORITHM_nb:
                mpi_errno = MPIR_Reduce_allcomm_nb(sendbuf, recvbuf, count, datatype, op, root,
                                                   comm_ptr, errflag);
                 break;
            case MPIR_CVAR_REDUCE_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Reduce_allcomm_auto(sendbuf, recvbuf, count, datatype, op, root,
                                                     comm_ptr, errflag);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        switch (MPIR_CVAR_REDUCE_INTER_ALGORITHM) {
            case MPIR_CVAR_REDUCE_INTER_ALGORITHM_local_reduce_remote_send:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_reduce_inter_local_reduce_remote_send_call_counter,
                                        1);
                mpi_errno = MPIR_Reduce_inter_local_reduce_remote_send(sendbuf, recvbuf, count,
                                    datatype, op, root, comm_ptr, errflag);
                break;
            case MPIR_CVAR_REDUCE_INTER_ALGORITHM_nb:
                mpi_errno = MPIR_Reduce_allcomm_nb(sendbuf, recvbuf, count, datatype, op, root,
                                                   comm_ptr, errflag);
                 break;
            case MPIR_CVAR_REDUCE_INTER_ALGORITHM_auto:
                mpi_errno = MPIR_Reduce_allcomm_auto(sendbuf, recvbuf, count, datatype, op, root,
                                                     comm_ptr, errflag);
                break;
            default:
                MPIR_Assert(0);
        }
    }
    MPIR_ERR_CHECK(mpi_errno);
    goto fn_exit;
    
  fallback:
    mpi_errno = MPIR_Reduce_allcomm_auto(sendbuf, recvbuf, count, datatype, op, root, comm_ptr,
                                         errflag);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Reduce(const void *sendbuf, void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                MPI_Op op, int root, MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_reduce_call_counter, mvp_reduce_timer);
    void *in_recvbuf = recvbuf;
    void *host_sendbuf = NULL;
    void *host_recvbuf = NULL;
    
    if(!MPIR_Typerep_reduce_is_supported(op, count, datatype))
      MPIR_Coll_host_buffer_alloc(sendbuf, (comm_ptr->rank == root || root == MPI_ROOT) ? recvbuf : NULL, count, datatype, &host_sendbuf, &host_recvbuf);
    
    if (host_sendbuf) {
        sendbuf = host_sendbuf;
    }
    if (host_recvbuf) {
        recvbuf = host_recvbuf;
    }
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_REDUCE_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Reduce(sendbuf, recvbuf, count, datatype, op, root, comm_ptr, errflag);
    } else {
        mpi_errno = MPIR_Reduce_impl(sendbuf, recvbuf, count, datatype, op, root, comm_ptr,
                                     errflag);
    }
    if (host_recvbuf) {
        recvbuf = in_recvbuf;
        MPIR_Localcopy(host_recvbuf, count, datatype, recvbuf, count, datatype);
    }
    MPIR_Coll_host_buffer_free(host_sendbuf, host_recvbuf);
    
    MVP_COLL_PVAR_UPDATE_END(mvp_reduce_timer);
    
    return mpi_errno;
}

/* ---- ireduce ---- */

int MPIR_Ireduce_allcomm_sched_auto(const void *sendbuf, void *recvbuf, MPI_Aint count,
                                    MPI_Datatype datatype, MPI_Op op, int root,
                                    MPIR_Comm * comm_ptr, bool is_persistent, void **sched_p,
                                    enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__IREDUCE,
        .comm_ptr = comm_ptr,
        .u.ireduce.sendbuf = sendbuf,
        .u.ireduce.recvbuf = recvbuf,
        .u.ireduce.count = count,
        .u.ireduce.datatype = datatype,
        .u.ireduce.op = op,
        .u.ireduce.root = root,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_intra_sched_smp:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ireduce_intra_sched_smp_call_counter, 1);
            mpi_errno = MPIR_Ireduce_intra_sched_smp(sendbuf, recvbuf, count, datatype, op, root,
                                                     comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_intra_sched_binomial:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ireduce_intra_sched_binomial_call_counter, 1);
            mpi_errno = MPIR_Ireduce_intra_sched_binomial(sendbuf, recvbuf, count, datatype, op,
                                                          root, comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_intra_sched_reduce_scatter_gather:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ireduce_intra_sched_reduce_scatter_gather_call_counter,
                                    1);
            mpi_errno = MPIR_Ireduce_intra_sched_reduce_scatter_gather(sendbuf, recvbuf, count,
                                datatype, op, root, comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_intra_tsp_tree:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ireduce_intra_tsp_tree_call_counter, 1);
            mpi_errno = MPIR_TSP_Ireduce_sched_intra_tree(sendbuf, recvbuf, count, datatype, op,
                                                          root, comm_ptr,
                                                          cnt->u.ireduce.intra_tsp_tree.tree_type,
                                                          cnt->u.ireduce.intra_tsp_tree.k,
                                                          cnt->u.ireduce.intra_tsp_tree.chunk_size,
                                                          cnt->u.ireduce.intra_tsp_tree.buffer_per_child,
                                                          *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_intra_tsp_ring:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ireduce_intra_tsp_ring_call_counter, 1);
            mpi_errno = MPIR_TSP_Ireduce_sched_intra_tree(sendbuf, recvbuf, count, datatype, op,
                                                          root, comm_ptr, MPIR_TREE_TYPE_KARY, 1,
                                                          cnt->u.ireduce.intra_tsp_ring.chunk_size,
                                                          cnt->u.ireduce.intra_tsp_ring.buffer_per_child,
                                                          *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_inter_sched_local_reduce_remote_send:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP,
                                    mvp_ireduce_inter_sched_local_reduce_remote_send_call_counter,
                                    1);
            mpi_errno = MPIR_Ireduce_inter_sched_local_reduce_remote_send(sendbuf, recvbuf, count,
                                datatype, op, root, comm_ptr, *sched_p);
            break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ireduce_sched_impl(const void *sendbuf, void *recvbuf, MPI_Aint count,
                            MPI_Datatype datatype, MPI_Op op, int root, MPIR_Comm * comm_ptr,
                            bool is_persistent, void **sched_p, enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_IREDUCE_INTRA_ALGORITHM) {
            case MPIR_CVAR_IREDUCE_INTRA_ALGORITHM_sched_smp:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, MPIR_Op_is_commutative(op) && MPIR_Comm_is_parent_comm(comm_ptr), mpi_errno,
                                               "Ireduce sched_smp cannot be applied.\n");
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ireduce_intra_sched_smp_call_counter, 1);
                mpi_errno = MPIR_Ireduce_intra_sched_smp(sendbuf, recvbuf, count, datatype, op, root,
                                                         comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IREDUCE_INTRA_ALGORITHM_sched_binomial:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ireduce_intra_sched_binomial_call_counter, 1);
                mpi_errno = MPIR_Ireduce_intra_sched_binomial(sendbuf, recvbuf, count, datatype, op,
                                                              root, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IREDUCE_INTRA_ALGORITHM_sched_reduce_scatter_gather:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, count >= comm_ptr->coll.pof2 && HANDLE_IS_BUILTIN(op), mpi_errno,
                                               "Ireduce sched_reduce_scatter_gather cannot be applied.\n");
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ireduce_intra_sched_reduce_scatter_gather_call_counter,
                                        1);
                mpi_errno = MPIR_Ireduce_intra_sched_reduce_scatter_gather(sendbuf, recvbuf, count,
                                    datatype, op, root, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IREDUCE_INTRA_ALGORITHM_tsp_tree:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, MPIR_Op_is_commutative(op), mpi_errno,
                                               "Ireduce tsp_tree cannot be applied.\n");
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ireduce_intra_tsp_tree_call_counter, 1);
                mpi_errno = MPIR_TSP_Ireduce_sched_intra_tree(sendbuf, recvbuf, count, datatype, op,
                                                              root, comm_ptr, MPIR_Ireduce_tree_type,
                                                              MPIR_CVAR_IREDUCE_TREE_KVAL,
                                                              MPIR_CVAR_IREDUCE_TREE_PIPELINE_CHUNK_SIZE,
                                                              MPIR_CVAR_IREDUCE_TREE_BUFFER_PER_CHILD,
                                                              *sched_p);
                break;
            case MPIR_CVAR_IREDUCE_INTRA_ALGORITHM_tsp_ring:
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ireduce_intra_tsp_ring_call_counter, 1);
                mpi_errno = MPIR_TSP_Ireduce_sched_intra_tree(sendbuf, recvbuf, count, datatype, op,
                                                              root, comm_ptr, MPIR_TREE_TYPE_KARY, 1,
                                                              MPIR_CVAR_IREDUCE_RING_CHUNK_SIZE,
                                                              MPIR_CVAR_IREDUCE_TREE_BUFFER_PER_CHILD,
                                                              *sched_p);
                break;
            case MPIR_CVAR_IREDUCE_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Ireduce_allcomm_sched_auto(sendbuf, recvbuf, count, datatype, op,
                                                            root, comm_ptr, is_persistent, sched_p,
                                                            sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        switch (MPIR_CVAR_IREDUCE_INTER_ALGORITHM) {
            case MPIR_CVAR_IREDUCE_INTER_ALGORITHM_sched_local_reduce_remote_send:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP,
                                        mvp_ireduce_inter_sched_local_reduce_remote_send_call_counter,
                                        1);
                mpi_errno = MPIR_Ireduce_inter_sched_local_reduce_remote_send(sendbuf, recvbuf, count,
                                    datatype, op, root, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IREDUCE_INTER_ALGORITHM_auto:
                mpi_errno = MPIR_Ireduce_allcomm_sched_auto(sendbuf, recvbuf, count, datatype, op,
                                                            root, comm_ptr, is_persistent, sched_p,
                                                            sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    }
    MPIR_ERR_CHECK(mpi_errno);
    goto fn_exit;
    
  fallback:
    mpi_errno = MPIR_Ireduce_allcomm_sched_auto(sendbuf, recvbuf, count, datatype, op, root,
                                                comm_ptr, is_persistent, sched_p, sched_type_p);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ireduce_impl(const void *sendbuf, void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                      MPI_Op op, int root, MPIR_Comm * comm_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    enum MPIR_sched_type sched_type;
    void *sched;
    
    *request = NULL;
    mpi_errno = MPIR_Ireduce_sched_impl(sendbuf, recvbuf, count, datatype, op, root, comm_ptr,
                                        false, &sched, &sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    MPII_SCHED_START(sched_type, sched, comm_ptr, request);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ireduce(const void *sendbuf, void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                 MPI_Op op, int root, MPIR_Comm * comm_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_ireduce_call_counter, mvp_ireduce_timer);
    void *in_recvbuf = recvbuf;
    void *host_sendbuf = NULL;
    void *host_recvbuf = NULL;
    
    if(!MPIR_Typerep_reduce_is_supported(op, count, datatype))
      MPIR_Coll_host_buffer_alloc(sendbuf, (comm_ptr->rank == root || root == MPI_ROOT) ? recvbuf : NULL, count, datatype, &host_sendbuf, &host_recvbuf);
    
    if (host_sendbuf) {
        sendbuf = host_sendbuf;
    }
    if (host_recvbuf) {
        recvbuf = host_recvbuf;
    }
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_IREDUCE_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Ireduce(sendbuf, recvbuf, count, datatype, op, root, comm_ptr, request);
    } else {
        mpi_errno = MPIR_Ireduce_impl(sendbuf, recvbuf, count, datatype, op, root, comm_ptr,
                                      request);
    }
    MPIR_Coll_host_buffer_swap_back(host_sendbuf, host_recvbuf, in_recvbuf, count, datatype, *request);
    
    MVP_COLL_PVAR_UPDATE_END(mvp_ireduce_timer);
    
    return mpi_errno;
}

int MPIR_Reduce_init_impl(const void *sendbuf, void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                          MPI_Op op, int root, MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                          MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Request *req = MPIR_Request_create(MPIR_REQUEST_KIND__PREQUEST_COLL);
    MPIR_ERR_CHKANDJUMP(!req, mpi_errno, MPI_ERR_OTHER, "**nomem");
    MPIR_Comm_add_ref(comm_ptr);
    req->comm = comm_ptr;
    MPIR_Comm_save_inactive_request(comm_ptr, req);
    req->u.persist_coll.sched_type = MPIR_SCHED_INVALID;
    req->u.persist_coll.real_request = NULL;
    mpi_errno = MPIR_Ireduce_sched_impl(sendbuf, recvbuf, count, datatype, op, root, comm_ptr, true,
                                        &req->u.persist_coll.sched,
                                        &req->u.persist_coll.sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    
    *request = req;
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Reduce_init(const void *sendbuf, void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                     MPI_Op op, int root, MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                     MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    void *in_recvbuf = recvbuf;
    void *host_sendbuf = NULL;
    void *host_recvbuf = NULL;
    
    if(!MPIR_Typerep_reduce_is_supported(op, count, datatype))
      MPIR_Coll_host_buffer_alloc(sendbuf, (comm_ptr->rank == root || root == MPI_ROOT) ? recvbuf : NULL, count, datatype, &host_sendbuf, &host_recvbuf);
    
    if (host_sendbuf) {
        sendbuf = host_sendbuf;
    }
    if (host_recvbuf) {
        recvbuf = host_recvbuf;
    }
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_REDUCE_INIT_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Reduce_init(sendbuf, recvbuf, count, datatype, op, root, comm_ptr,
                                     info_ptr, request);
    } else {
        mpi_errno = MPIR_Reduce_init_impl(sendbuf, recvbuf, count, datatype, op, root, comm_ptr,
                                          info_ptr, request);
    }
    MPIR_Coll_host_buffer_persist_set(host_sendbuf, host_recvbuf, in_recvbuf, count, datatype, *request);
    
    return mpi_errno;
}

/* ---- allreduce ---- */

int MPIR_Allreduce_allcomm_auto(const void *sendbuf, void *recvbuf, MPI_Aint count,
                                MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                                MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__ALLREDUCE,
        .comm_ptr = comm_ptr,
        .u.allreduce.sendbuf = sendbuf,
        .u.allreduce.recvbuf = recvbuf,
        .u.allreduce.count = count,
        .u.allreduce.datatype = datatype,
        .u.allreduce.op = op,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allreduce_intra_smp:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allreduce_intra_smp_call_counter, 1);
            mpi_errno = MPIR_Allreduce_intra_smp(sendbuf, recvbuf, count, datatype, op, comm_ptr,
                                                 errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allreduce_intra_recursive_doubling:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allreduce_intra_recursive_doubling_call_counter, 1);
            mpi_errno = MPIR_Allreduce_intra_recursive_doubling(sendbuf, recvbuf, count, datatype,
                                op, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allreduce_intra_recursive_multiplying:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allreduce_intra_recursive_multiplying_call_counter,
                                    1);
            mpi_errno = MPIR_Allreduce_intra_recursive_multiplying(sendbuf, recvbuf, count,
                                datatype, op, comm_ptr,
                                cnt->u.allreduce.intra_recursive_multiplying.k, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allreduce_intra_reduce_scatter_allgather:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allreduce_intra_reduce_scatter_allgather_call_counter,
                                    1);
            mpi_errno = MPIR_Allreduce_intra_reduce_scatter_allgather(sendbuf, recvbuf, count,
                                datatype, op, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allreduce_intra_tree:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allreduce_intra_tree_call_counter, 1);
            mpi_errno = MPIR_Allreduce_intra_tree(sendbuf, recvbuf, count, datatype, op, comm_ptr,
                                                  cnt->u.allreduce.intra_tree.tree_type,
                                                  cnt->u.allreduce.intra_tree.k,
                                                  cnt->u.allreduce.intra_tree.chunk_size,
                                                  cnt->u.allreduce.intra_tree.buffer_per_child,
                                                  errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allreduce_intra_recexch:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allreduce_intra_recexch_call_counter, 1);
            mpi_errno = MPIR_Allreduce_intra_recexch(sendbuf, recvbuf, count, datatype, op,
                                                     comm_ptr, cnt->u.allreduce.intra_recexch.k,
                                                     cnt->u.allreduce.intra_recexch.single_phase_recv,
                                                     errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allreduce_intra_ring:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allreduce_intra_ring_call_counter, 1);
            mpi_errno = MPIR_Allreduce_intra_ring(sendbuf, recvbuf, count, datatype, op, comm_ptr,
                                                  errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allreduce_intra_k_reduce_scatter_allgather:
            MPIR_T_PVAR_COUNTER_INC(MVP,
                                    mvp_allreduce_intra_k_reduce_scatter_allgather_call_counter,
                                    1);
            mpi_errno = MPIR_Allreduce_intra_k_reduce_scatter_allgather(sendbuf, recvbuf, count,
                                datatype, op, comm_ptr,
                                cnt->u.allreduce.intra_k_reduce_scatter_allgather.k,
                                cnt->u.allreduce.intra_k_reduce_scatter_allgather.single_phase_recv,
                                errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allreduce_inter_reduce_exchange_bcast:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allreduce_inter_reduce_exchange_bcast_call_counter,
                                    1);
            mpi_errno = MPIR_Allreduce_inter_reduce_exchange_bcast(sendbuf, recvbuf, count,
                                datatype, op, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allreduce_allcomm_nb:
           mpi_errno = MPIR_Allreduce_allcomm_nb(sendbuf, recvbuf, count, datatype, op, comm_ptr,
                                                 errflag);
           break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Allreduce_impl(const void *sendbuf, void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                        MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_ALLREDUCE_INTRA_ALGORITHM) {
            case MPIR_CVAR_ALLREDUCE_INTRA_ALGORITHM_smp:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, MPIR_Op_is_commutative(op) && MPIR_Comm_is_parent_comm(comm_ptr), mpi_errno,
                                               "Allreduce smp cannot be applied.\n");
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allreduce_intra_smp_call_counter, 1);
                mpi_errno = MPIR_Allreduce_intra_smp(sendbuf, recvbuf, count, datatype, op, comm_ptr,
                                                     errflag);
                break;
            case MPIR_CVAR_ALLREDUCE_INTRA_ALGORITHM_recursive_doubling:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allreduce_intra_recursive_doubling_call_counter, 1);
                mpi_errno = MPIR_Allreduce_intra_recursive_doubling(sendbuf, recvbuf, count, datatype,
                                    op, comm_ptr, errflag);
                break;
            case MPIR_CVAR_ALLREDUCE_INTRA_ALGORITHM_recursive_multiplying:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, MPIR_Op_is_commutative(op), mpi_errno,
                                               "Allreduce recursive_multiplying cannot be applied.\n");
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allreduce_intra_recursive_multiplying_call_counter,
                                        1);
                mpi_errno = MPIR_Allreduce_intra_recursive_multiplying(sendbuf, recvbuf, count,
                                    datatype, op, comm_ptr,
                                    MPIR_CVAR_ALLREDUCE_RECURSIVE_MULTIPLYING_KVAL, errflag);
                break;
            case MPIR_CVAR_ALLREDUCE_INTRA_ALGORITHM_reduce_scatter_allgather:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, count >= comm_ptr->coll.pof2 && HANDLE_IS_BUILTIN(op), mpi_errno,
                                               "Allreduce reduce_scatter_allgather cannot be applied.\n");
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allreduce_intra_reduce_scatter_allgather_call_counter,
                                        1);
                mpi_errno = MPIR_Allreduce_intra_reduce_scatter_allgather(sendbuf, recvbuf, count,
                                    datatype, op, comm_ptr, errflag);
                break;
            case MPIR_CVAR_ALLREDUCE_INTRA_ALGORITHM_tree:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allreduce_intra_tree_call_counter, 1);
                mpi_errno = MPIR_Allreduce_intra_tree(sendbuf, recvbuf, count, datatype, op, comm_ptr,
                                                      MPIR_Allreduce_tree_type,
                                                      MPIR_CVAR_ALLREDUCE_TREE_KVAL,
                                                      MPIR_CVAR_ALLREDUCE_TREE_PIPELINE_CHUNK_SIZE,
                                                      MPIR_CVAR_ALLREDUCE_TREE_BUFFER_PER_CHILD,
                                                      errflag);
                break;
            case MPIR_CVAR_ALLREDUCE_INTRA_ALGORITHM_recexch:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allreduce_intra_recexch_call_counter, 1);
                mpi_errno = MPIR_Allreduce_intra_recexch(sendbuf, recvbuf, count, datatype, op,
                                                         comm_ptr, MPIR_CVAR_ALLREDUCE_RECEXCH_KVAL,
                                                         MPIR_CVAR_ALLREDUCE_RECEXCH_SINGLE_PHASE_RECV,
                                                         errflag);
                break;
            case MPIR_CVAR_ALLREDUCE_INTRA_ALGORITHM_ring:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, MPIR_Op_is_commutative(op), mpi_errno,
                                               "Allreduce ring cannot be applied.\n");
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allreduce_intra_ring_call_counter, 1);
                mpi_errno = MPIR_Allreduce_intra_ring(sendbuf, recvbuf, count, datatype, op, comm_ptr,
                                                      errflag);
                break;
            case MPIR_CVAR_ALLREDUCE_INTRA_ALGORITHM_k_reduce_scatter_allgather:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, MPIR_Op_is_commutative(op), mpi_errno,
                                               "Allreduce k_reduce_scatter_allgather cannot be applied.\n");
                MPIR_T_PVAR_COUNTER_INC(MVP,
                                        mvp_allreduce_intra_k_reduce_scatter_allgather_call_counter,
                                        1);
                mpi_errno = MPIR_Allreduce_intra_k_reduce_scatter_allgather(sendbuf, recvbuf, count,
                                    datatype, op, comm_ptr, MPIR_CVAR_ALLREDUCE_RECEXCH_KVAL,
                                    MPIR_CVAR_ALLREDUCE_RECEXCH_SINGLE_PHASE_RECV, errflag);
                break;
            case MPIR_CVAR_ALLREDUCE_INTRA_ALGORITHM_nb:
                mpi_errno = MPIR_Allreduce_allcomm_nb(sendbuf, recvbuf, count, datatype, op,
                                                      comm_ptr, errflag);
                 break;
            case MPIR_CVAR_ALLREDUCE_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Allreduce_allcomm_auto(sendbuf, recvbuf, count, datatype, op,
                                                        comm_ptr, errflag);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        switch (MPIR_CVAR_ALLREDUCE_INTER_ALGORITHM) {
            case MPIR_CVAR_ALLREDUCE_INTER_ALGORITHM_reduce_exchange_bcast:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_allreduce_inter_reduce_exchange_bcast_call_counter,
                                        1);
                mpi_errno = MPIR_Allreduce_inter_reduce_exchange_bcast(sendbuf, recvbuf, count,
                                    datatype, op, comm_ptr, errflag);
                break;
            case MPIR_CVAR_ALLREDUCE_INTER_ALGORITHM_nb:
                mpi_errno = MPIR_Allreduce_allcomm_nb(sendbuf, recvbuf, count, datatype, op,
                                                      comm_ptr, errflag);
                 break;
            case MPIR_CVAR_ALLREDUCE_INTER_ALGORITHM_auto:
                mpi_errno = MPIR_Allreduce_allcomm_auto(sendbuf, recvbuf, count, datatype, op,
                                                        comm_ptr, errflag);
                break;
            default:
                MPIR_Assert(0);
        }
    }
    MPIR_ERR_CHECK(mpi_errno);
    goto fn_exit;
    
  fallback:
    mpi_errno = MPIR_Allreduce_allcomm_auto(sendbuf, recvbuf, count, datatype, op, comm_ptr,
                                            errflag);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Allreduce(const void *sendbuf, void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                   MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_allreduce_call_counter, mvp_allreduce_timer);
    void *in_recvbuf = recvbuf;
    void *host_sendbuf = NULL;
    void *host_recvbuf = NULL;
    
    if(!MPIR_Typerep_reduce_is_supported(op, count, datatype))
      MPIR_Coll_host_buffer_alloc(sendbuf, recvbuf, count, datatype, &host_sendbuf, &host_recvbuf);
    
    if (host_sendbuf) {
        sendbuf = host_sendbuf;
    }
    if (host_recvbuf) {
        recvbuf = host_recvbuf;
    }
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_ALLREDUCE_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Allreduce(sendbuf, recvbuf, count, datatype, op, comm_ptr, errflag);
    } else {
        mpi_errno = MPIR_Allreduce_impl(sendbuf, recvbuf, count, datatype, op, comm_ptr, errflag);
    }
    if (host_recvbuf) {
        recvbuf = in_recvbuf;
        MPIR_Localcopy(host_recvbuf, count, datatype, recvbuf, count, datatype);
    }
    MPIR_Coll_host_buffer_free(host_sendbuf, host_recvbuf);
    
    MVP_COLL_PVAR_UPDATE_END(mvp_allreduce_timer);
    
    return mpi_errno;
}

/* ---- iallreduce ---- */

int MPIR_Iallreduce_allcomm_sched_auto(const void *sendbuf, void *recvbuf, MPI_Aint count,
                                       MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                                       bool is_persistent, void **sched_p,
                                       enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__IALLREDUCE,
        .comm_ptr = comm_ptr,
        .u.iallreduce.sendbuf = sendbuf,
        .u.iallreduce.recvbuf = recvbuf,
        .u.iallreduce.count = count,
        .u.iallreduce.datatype = datatype,
        .u.iallreduce.op = op,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallreduce_intra_sched_naive:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallreduce_intra_sched_naive_call_counter, 1);
            mpi_errno = MPIR_Iallreduce_intra_sched_naive(sendbuf, recvbuf, count, datatype, op,
                                                          comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallreduce_intra_sched_smp:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallreduce_intra_sched_smp_call_counter, 1);
            mpi_errno = MPIR_Iallreduce_intra_sched_smp(sendbuf, recvbuf, count, datatype, op,
                                                        comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallreduce_intra_sched_recursive_doubling:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallreduce_intra_sched_recursive_doubling_call_counter,
                                    1);
            mpi_errno = MPIR_Iallreduce_intra_sched_recursive_doubling(sendbuf, recvbuf, count,
                                datatype, op, comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallreduce_intra_sched_reduce_scatter_allgather:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP,
                                    mvp_iallreduce_intra_sched_reduce_scatter_allgather_call_counter,
                                    1);
            mpi_errno = MPIR_Iallreduce_intra_sched_reduce_scatter_allgather(sendbuf, recvbuf,
                                count, datatype, op, comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallreduce_intra_tsp_recexch_single_buffer:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP,
                                    mvp_iallreduce_intra_tsp_recexch_single_buffer_call_counter,
                                    1);
            mpi_errno = MPIR_TSP_Iallreduce_sched_intra_recexch(sendbuf, recvbuf, count, datatype,
                                op, comm_ptr, MPIR_IALLREDUCE_RECEXCH_TYPE_SINGLE_BUFFER,
                                cnt->u.iallreduce.intra_tsp_recexch_single_buffer.k, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallreduce_intra_tsp_recexch_multiple_buffer:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP,
                                    mvp_iallreduce_intra_tsp_recexch_multiple_buffer_call_counter,
                                    1);
            mpi_errno = MPIR_TSP_Iallreduce_sched_intra_recexch(sendbuf, recvbuf, count, datatype,
                                op, comm_ptr, MPIR_IALLREDUCE_RECEXCH_TYPE_MULTIPLE_BUFFER,
                                cnt->u.iallreduce.intra_tsp_recexch_multiple_buffer.k, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallreduce_intra_tsp_tree:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallreduce_intra_tsp_tree_call_counter, 1);
            mpi_errno = MPIR_TSP_Iallreduce_sched_intra_tree(sendbuf, recvbuf, count, datatype, op,
                                comm_ptr, cnt->u.iallreduce.intra_tsp_tree.tree_type,
                                cnt->u.iallreduce.intra_tsp_tree.k,
                                cnt->u.iallreduce.intra_tsp_tree.chunk_size,
                                cnt->u.iallreduce.intra_tsp_tree.buffer_per_child, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallreduce_intra_tsp_ring:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallreduce_intra_tsp_ring_call_counter, 1);
            mpi_errno = MPIR_TSP_Iallreduce_sched_intra_ring(sendbuf, recvbuf, count, datatype, op,
                                comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallreduce_intra_tsp_recexch_reduce_scatter_recexch_allgatherv:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP,
                                    mvp_iallreduce_intra_tsp_recexch_reduce_scatter_recexch_allgatherv_call_counter,
                                    1);
            mpi_errno = MPIR_TSP_Iallreduce_sched_intra_recexch_reduce_scatter_recexch_allgatherv(sendbuf,
                                recvbuf, count, datatype, op, comm_ptr,
                                cnt->u.iallreduce.intra_tsp_recexch_reduce_scatter_recexch_allgatherv.k,
                                *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallreduce_inter_sched_remote_reduce_local_bcast:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP,
                                    mvp_iallreduce_inter_sched_remote_reduce_local_bcast_call_counter,
                                    1);
            mpi_errno = MPIR_Iallreduce_inter_sched_remote_reduce_local_bcast(sendbuf, recvbuf,
                                count, datatype, op, comm_ptr, *sched_p);
            break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Iallreduce_sched_impl(const void *sendbuf, void *recvbuf, MPI_Aint count,
                               MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                               bool is_persistent, void **sched_p,
                               enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_IALLREDUCE_INTRA_ALGORITHM) {
            case MPIR_CVAR_IALLREDUCE_INTRA_ALGORITHM_sched_naive:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallreduce_intra_sched_naive_call_counter, 1);
                mpi_errno = MPIR_Iallreduce_intra_sched_naive(sendbuf, recvbuf, count, datatype, op,
                                                              comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IALLREDUCE_INTRA_ALGORITHM_sched_smp:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, MPIR_Op_is_commutative(op) && MPIR_Comm_is_parent_comm(comm_ptr), mpi_errno,
                                               "Iallreduce sched_smp cannot be applied.\n");
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallreduce_intra_sched_smp_call_counter, 1);
                mpi_errno = MPIR_Iallreduce_intra_sched_smp(sendbuf, recvbuf, count, datatype, op,
                                                            comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IALLREDUCE_INTRA_ALGORITHM_sched_recursive_doubling:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallreduce_intra_sched_recursive_doubling_call_counter,
                                        1);
                mpi_errno = MPIR_Iallreduce_intra_sched_recursive_doubling(sendbuf, recvbuf, count,
                                    datatype, op, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IALLREDUCE_INTRA_ALGORITHM_sched_reduce_scatter_allgather:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, count >= comm_ptr->coll.pof2 && HANDLE_IS_BUILTIN(op), mpi_errno,
                                               "Iallreduce sched_reduce_scatter_allgather cannot be applied.\n");
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP,
                                        mvp_iallreduce_intra_sched_reduce_scatter_allgather_call_counter,
                                        1);
                mpi_errno = MPIR_Iallreduce_intra_sched_reduce_scatter_allgather(sendbuf, recvbuf,
                                    count, datatype, op, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IALLREDUCE_INTRA_ALGORITHM_tsp_recexch_single_buffer:
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP,
                                        mvp_iallreduce_intra_tsp_recexch_single_buffer_call_counter,
                                        1);
                mpi_errno = MPIR_TSP_Iallreduce_sched_intra_recexch(sendbuf, recvbuf, count, datatype,
                                    op, comm_ptr, MPIR_IALLREDUCE_RECEXCH_TYPE_SINGLE_BUFFER,
                                    MPIR_CVAR_IALLREDUCE_RECEXCH_KVAL, *sched_p);
                break;
            case MPIR_CVAR_IALLREDUCE_INTRA_ALGORITHM_tsp_recexch_multiple_buffer:
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP,
                                        mvp_iallreduce_intra_tsp_recexch_multiple_buffer_call_counter,
                                        1);
                mpi_errno = MPIR_TSP_Iallreduce_sched_intra_recexch(sendbuf, recvbuf, count, datatype,
                                    op, comm_ptr, MPIR_IALLREDUCE_RECEXCH_TYPE_MULTIPLE_BUFFER,
                                    MPIR_CVAR_IALLREDUCE_RECEXCH_KVAL, *sched_p);
                break;
            case MPIR_CVAR_IALLREDUCE_INTRA_ALGORITHM_tsp_tree:
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallreduce_intra_tsp_tree_call_counter, 1);
                mpi_errno = MPIR_TSP_Iallreduce_sched_intra_tree(sendbuf, recvbuf, count, datatype, op,
                                    comm_ptr, MPIR_Iallreduce_tree_type, MPIR_CVAR_IALLREDUCE_TREE_KVAL,
                                    MPIR_CVAR_IALLREDUCE_TREE_PIPELINE_CHUNK_SIZE,
                                    MPIR_CVAR_IALLREDUCE_TREE_BUFFER_PER_CHILD, *sched_p);
                break;
            case MPIR_CVAR_IALLREDUCE_INTRA_ALGORITHM_tsp_ring:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, MPIR_Op_is_commutative(op), mpi_errno,
                                               "Iallreduce tsp_ring cannot be applied.\n");
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iallreduce_intra_tsp_ring_call_counter, 1);
                mpi_errno = MPIR_TSP_Iallreduce_sched_intra_ring(sendbuf, recvbuf, count, datatype, op,
                                    comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IALLREDUCE_INTRA_ALGORITHM_tsp_recexch_reduce_scatter_recexch_allgatherv:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, MPIR_Op_is_commutative(op), mpi_errno,
                                               "Iallreduce tsp_recexch_reduce_scatter_recexch_allgatherv cannot be applied.\n");
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP,
                                        mvp_iallreduce_intra_tsp_recexch_reduce_scatter_recexch_allgatherv_call_counter,
                                        1);
                mpi_errno = MPIR_TSP_Iallreduce_sched_intra_recexch_reduce_scatter_recexch_allgatherv(sendbuf,
                                    recvbuf, count, datatype, op, comm_ptr,
                                    MPIR_CVAR_IALLREDUCE_RECEXCH_KVAL, *sched_p);
                break;
            case MPIR_CVAR_IALLREDUCE_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Iallreduce_allcomm_sched_auto(sendbuf, recvbuf, count, datatype,
                                op, comm_ptr, is_persistent, sched_p, sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        switch (MPIR_CVAR_IALLREDUCE_INTER_ALGORITHM) {
            case MPIR_CVAR_IALLREDUCE_INTER_ALGORITHM_sched_remote_reduce_local_bcast:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP,
                                        mvp_iallreduce_inter_sched_remote_reduce_local_bcast_call_counter,
                                        1);
                mpi_errno = MPIR_Iallreduce_inter_sched_remote_reduce_local_bcast(sendbuf, recvbuf,
                                    count, datatype, op, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IALLREDUCE_INTER_ALGORITHM_auto:
                mpi_errno = MPIR_Iallreduce_allcomm_sched_auto(sendbuf, recvbuf, count, datatype,
                                op, comm_ptr, is_persistent, sched_p, sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    }
    MPIR_ERR_CHECK(mpi_errno);
    goto fn_exit;
    
  fallback:
    mpi_errno = MPIR_Iallreduce_allcomm_sched_auto(sendbuf, recvbuf, count, datatype, op, comm_ptr,
                                                   is_persistent, sched_p, sched_type_p);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Iallreduce_impl(const void *sendbuf, void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                         MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    enum MPIR_sched_type sched_type;
    void *sched;
    
    *request = NULL;
    mpi_errno = MPIR_Iallreduce_sched_impl(sendbuf, recvbuf, count, datatype, op, comm_ptr, false,
                                           &sched, &sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    MPII_SCHED_START(sched_type, sched, comm_ptr, request);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Iallreduce(const void *sendbuf, void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                    MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_iallreduce_call_counter, mvp_iallreduce_timer);
    void *in_recvbuf = recvbuf;
    void *host_sendbuf = NULL;
    void *host_recvbuf = NULL;
    
    if(!MPIR_Typerep_reduce_is_supported(op, count, datatype))
      MPIR_Coll_host_buffer_alloc(sendbuf, recvbuf, count, datatype, &host_sendbuf, &host_recvbuf);
    
    if (host_sendbuf) {
        sendbuf = host_sendbuf;
    }
    if (host_recvbuf) {
        recvbuf = host_recvbuf;
    }
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_IALLREDUCE_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Iallreduce(sendbuf, recvbuf, count, datatype, op, comm_ptr, request);
    } else {
        mpi_errno = MPIR_Iallreduce_impl(sendbuf, recvbuf, count, datatype, op, comm_ptr, request);
    }
    MPIR_Coll_host_buffer_swap_back(host_sendbuf, host_recvbuf, in_recvbuf, count, datatype, *request);
    
    MVP_COLL_PVAR_UPDATE_END(mvp_iallreduce_timer);
    
    return mpi_errno;
}

int MPIR_Allreduce_init_impl(const void *sendbuf, void *recvbuf, MPI_Aint count,
                             MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                             MPIR_Info * info_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Request *req = MPIR_Request_create(MPIR_REQUEST_KIND__PREQUEST_COLL);
    MPIR_ERR_CHKANDJUMP(!req, mpi_errno, MPI_ERR_OTHER, "**nomem");
    MPIR_Comm_add_ref(comm_ptr);
    req->comm = comm_ptr;
    MPIR_Comm_save_inactive_request(comm_ptr, req);
    req->u.persist_coll.sched_type = MPIR_SCHED_INVALID;
    req->u.persist_coll.real_request = NULL;
    mpi_errno = MPIR_Iallreduce_sched_impl(sendbuf, recvbuf, count, datatype, op, comm_ptr, true,
                                           &req->u.persist_coll.sched,
                                           &req->u.persist_coll.sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    
    *request = req;
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Allreduce_init(const void *sendbuf, void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                        MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                        MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    void *in_recvbuf = recvbuf;
    void *host_sendbuf = NULL;
    void *host_recvbuf = NULL;
    
    if(!MPIR_Typerep_reduce_is_supported(op, count, datatype))
      MPIR_Coll_host_buffer_alloc(sendbuf, recvbuf, count, datatype, &host_sendbuf, &host_recvbuf);
    
    if (host_sendbuf) {
        sendbuf = host_sendbuf;
    }
    if (host_recvbuf) {
        recvbuf = host_recvbuf;
    }
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_ALLREDUCE_INIT_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Allreduce_init(sendbuf, recvbuf, count, datatype, op, comm_ptr, info_ptr,
                                        request);
    } else {
        mpi_errno = MPIR_Allreduce_init_impl(sendbuf, recvbuf, count, datatype, op, comm_ptr,
                                             info_ptr, request);
    }
    MPIR_Coll_host_buffer_persist_set(host_sendbuf, host_recvbuf, in_recvbuf, count, datatype, *request);
    
    return mpi_errno;
}

/* ---- reduce_scatter ---- */

int MPIR_Reduce_scatter_allcomm_auto(const void *sendbuf, void *recvbuf,
                                     const MPI_Aint recvcounts[], MPI_Datatype datatype, MPI_Op op,
                                     MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__REDUCE_SCATTER,
        .comm_ptr = comm_ptr,
        .u.reduce_scatter.sendbuf = sendbuf,
        .u.reduce_scatter.recvbuf = recvbuf,
        .u.reduce_scatter.recvcounts = recvcounts,
        .u.reduce_scatter.datatype = datatype,
        .u.reduce_scatter.op = op,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_scatter_intra_noncommutative:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_reduce_scatter_intra_noncommutative_call_counter, 1);
            mpi_errno = MPIR_Reduce_scatter_intra_noncommutative(sendbuf, recvbuf, recvcounts,
                                datatype, op, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_scatter_intra_pairwise:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_reduce_scatter_intra_pairwise_call_counter, 1);
            mpi_errno = MPIR_Reduce_scatter_intra_pairwise(sendbuf, recvbuf, recvcounts, datatype,
                                                           op, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_scatter_intra_recursive_doubling:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_reduce_scatter_intra_recursive_doubling_call_counter,
                                    1);
            mpi_errno = MPIR_Reduce_scatter_intra_recursive_doubling(sendbuf, recvbuf, recvcounts,
                                datatype, op, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_scatter_intra_recursive_halving:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_reduce_scatter_intra_recursive_halving_call_counter,
                                    1);
            mpi_errno = MPIR_Reduce_scatter_intra_recursive_halving(sendbuf, recvbuf, recvcounts,
                                datatype, op, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_scatter_intra_osu_basic:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_reduce_scatter_intra_osu_basic_call_counter, 1);
            mpi_errno = MPIR_Reduce_scatter_intra_osu_basic(sendbuf, recvbuf, recvcounts, datatype,
                                                            op, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_scatter_intra_osu_ring:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_reduce_scatter_intra_osu_ring_call_counter, 1);
            mpi_errno = MPIR_Reduce_scatter_intra_osu_ring(sendbuf, recvbuf, recvcounts, datatype,
                                                           op, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_scatter_inter_remote_reduce_local_scatter:
            MPIR_T_PVAR_COUNTER_INC(MVP,
                                    mvp_reduce_scatter_inter_remote_reduce_local_scatter_call_counter,
                                    1);
            mpi_errno = MPIR_Reduce_scatter_inter_remote_reduce_local_scatter(sendbuf, recvbuf,
                                recvcounts, datatype, op, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_scatter_allcomm_nb:
           mpi_errno = MPIR_Reduce_scatter_allcomm_nb(sendbuf, recvbuf, recvcounts, datatype, op,
                                                      comm_ptr, errflag);
           break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Reduce_scatter_impl(const void *sendbuf, void *recvbuf, const MPI_Aint recvcounts[],
                             MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                             MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_REDUCE_SCATTER_INTRA_ALGORITHM) {
            case MPIR_CVAR_REDUCE_SCATTER_INTRA_ALGORITHM_noncommutative:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_reduce_scatter_intra_noncommutative_call_counter, 1);
                mpi_errno = MPIR_Reduce_scatter_intra_noncommutative(sendbuf, recvbuf, recvcounts,
                                    datatype, op, comm_ptr, errflag);
                break;
            case MPIR_CVAR_REDUCE_SCATTER_INTRA_ALGORITHM_pairwise:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, MPIR_Op_is_commutative(op), mpi_errno,
                                               "Reduce_scatter pairwise cannot be applied.\n");
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_reduce_scatter_intra_pairwise_call_counter, 1);
                mpi_errno = MPIR_Reduce_scatter_intra_pairwise(sendbuf, recvbuf, recvcounts, datatype,
                                                               op, comm_ptr, errflag);
                break;
            case MPIR_CVAR_REDUCE_SCATTER_INTRA_ALGORITHM_recursive_doubling:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_reduce_scatter_intra_recursive_doubling_call_counter,
                                        1);
                mpi_errno = MPIR_Reduce_scatter_intra_recursive_doubling(sendbuf, recvbuf, recvcounts,
                                    datatype, op, comm_ptr, errflag);
                break;
            case MPIR_CVAR_REDUCE_SCATTER_INTRA_ALGORITHM_recursive_halving:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, MPIR_Op_is_commutative(op), mpi_errno,
                                               "Reduce_scatter recursive_halving cannot be applied.\n");
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_reduce_scatter_intra_recursive_halving_call_counter,
                                        1);
                mpi_errno = MPIR_Reduce_scatter_intra_recursive_halving(sendbuf, recvbuf, recvcounts,
                                    datatype, op, comm_ptr, errflag);
                break;
            case MPIR_CVAR_REDUCE_SCATTER_INTRA_ALGORITHM_osu_basic:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_reduce_scatter_intra_osu_basic_call_counter, 1);
                mpi_errno = MPIR_Reduce_scatter_intra_osu_basic(sendbuf, recvbuf, recvcounts, datatype,
                                                                op, comm_ptr, errflag);
                break;
            case MPIR_CVAR_REDUCE_SCATTER_INTRA_ALGORITHM_osu_ring:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_reduce_scatter_intra_osu_ring_call_counter, 1);
                mpi_errno = MPIR_Reduce_scatter_intra_osu_ring(sendbuf, recvbuf, recvcounts, datatype,
                                                               op, comm_ptr, errflag);
                break;
            case MPIR_CVAR_REDUCE_SCATTER_INTRA_ALGORITHM_nb:
                mpi_errno = MPIR_Reduce_scatter_allcomm_nb(sendbuf, recvbuf, recvcounts, datatype,
                                                           op, comm_ptr, errflag);
                 break;
            case MPIR_CVAR_REDUCE_SCATTER_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Reduce_scatter_allcomm_auto(sendbuf, recvbuf, recvcounts, datatype,
                                op, comm_ptr, errflag);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        switch (MPIR_CVAR_REDUCE_SCATTER_INTER_ALGORITHM) {
            case MPIR_CVAR_REDUCE_SCATTER_INTER_ALGORITHM_remote_reduce_local_scatter:
                MPIR_T_PVAR_COUNTER_INC(MVP,
                                        mvp_reduce_scatter_inter_remote_reduce_local_scatter_call_counter,
                                        1);
                mpi_errno = MPIR_Reduce_scatter_inter_remote_reduce_local_scatter(sendbuf, recvbuf,
                                    recvcounts, datatype, op, comm_ptr, errflag);
                break;
            case MPIR_CVAR_REDUCE_SCATTER_INTER_ALGORITHM_nb:
                mpi_errno = MPIR_Reduce_scatter_allcomm_nb(sendbuf, recvbuf, recvcounts, datatype,
                                                           op, comm_ptr, errflag);
                 break;
            case MPIR_CVAR_REDUCE_SCATTER_INTER_ALGORITHM_auto:
                mpi_errno = MPIR_Reduce_scatter_allcomm_auto(sendbuf, recvbuf, recvcounts, datatype,
                                op, comm_ptr, errflag);
                break;
            default:
                MPIR_Assert(0);
        }
    }
    MPIR_ERR_CHECK(mpi_errno);
    goto fn_exit;
    
  fallback:
    mpi_errno = MPIR_Reduce_scatter_allcomm_auto(sendbuf, recvbuf, recvcounts, datatype, op,
                                                 comm_ptr, errflag);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Reduce_scatter(const void *sendbuf, void *recvbuf, const MPI_Aint recvcounts[],
                        MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                        MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_reduce_scatter_call_counter, mvp_reduce_scatter_timer);
    void *in_recvbuf = recvbuf;
    void *host_sendbuf = NULL;
    void *host_recvbuf = NULL;
    
    MPI_Aint count = 0;
    for (int i = 0; i < MPIR_Comm_size(comm_ptr); i++) {
        count += recvcounts[i];
    }
    
    if(!MPIR_Typerep_reduce_is_supported(op, count, datatype))
      MPIR_Coll_host_buffer_alloc(sendbuf, recvbuf, count, datatype, &host_sendbuf, &host_recvbuf);
    
    if (host_sendbuf) {
        sendbuf = host_sendbuf;
    }
    if (host_recvbuf) {
        recvbuf = host_recvbuf;
    }
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_REDUCE_SCATTER_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Reduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm_ptr,
                                        errflag);
    } else {
        mpi_errno = MPIR_Reduce_scatter_impl(sendbuf, recvbuf, recvcounts, datatype, op, comm_ptr,
                                             errflag);
    }
    if (host_recvbuf) {
        recvbuf = in_recvbuf;
        MPIR_Localcopy(host_recvbuf, count, datatype, recvbuf, count, datatype);
    }
    MPIR_Coll_host_buffer_free(host_sendbuf, host_recvbuf);
    
    MVP_COLL_PVAR_UPDATE_END(mvp_reduce_scatter_timer);
    
    return mpi_errno;
}

/* ---- ireduce_scatter ---- */

int MPIR_Ireduce_scatter_allcomm_sched_auto(const void *sendbuf, void *recvbuf,
                                            const MPI_Aint recvcounts[], MPI_Datatype datatype,
                                            MPI_Op op, MPIR_Comm * comm_ptr, bool is_persistent,
                                            void **sched_p, enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__IREDUCE_SCATTER,
        .comm_ptr = comm_ptr,
        .u.ireduce_scatter.sendbuf = sendbuf,
        .u.ireduce_scatter.recvbuf = recvbuf,
        .u.ireduce_scatter.recvcounts = recvcounts,
        .u.ireduce_scatter.datatype = datatype,
        .u.ireduce_scatter.op = op,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_scatter_intra_sched_noncommutative:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP,
                                    mvp_ireduce_scatter_intra_sched_noncommutative_call_counter,
                                    1);
            mpi_errno = MPIR_Ireduce_scatter_intra_sched_noncommutative(sendbuf, recvbuf,
                                recvcounts, datatype, op, comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_scatter_intra_sched_recursive_doubling:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP,
                                    mvp_ireduce_scatter_intra_sched_recursive_doubling_call_counter,
                                    1);
            mpi_errno = MPIR_Ireduce_scatter_intra_sched_recursive_doubling(sendbuf, recvbuf,
                                recvcounts, datatype, op, comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_scatter_intra_sched_pairwise:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ireduce_scatter_intra_sched_pairwise_call_counter, 1);
            mpi_errno = MPIR_Ireduce_scatter_intra_sched_pairwise(sendbuf, recvbuf, recvcounts,
                                datatype, op, comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_scatter_intra_sched_recursive_halving:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP,
                                    mvp_ireduce_scatter_intra_sched_recursive_halving_call_counter,
                                    1);
            mpi_errno = MPIR_Ireduce_scatter_intra_sched_recursive_halving(sendbuf, recvbuf,
                                recvcounts, datatype, op, comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_scatter_intra_tsp_recexch:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ireduce_scatter_intra_tsp_recexch_call_counter, 1);
            mpi_errno = MPIR_TSP_Ireduce_scatter_sched_intra_recexch(sendbuf, recvbuf, recvcounts,
                                datatype, op, comm_ptr,
                                IREDUCE_SCATTER_RECEXCH_TYPE_DISTANCE_DOUBLING,
                                cnt->u.ireduce_scatter.intra_tsp_recexch.k, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_scatter_inter_sched_remote_reduce_local_scatterv:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP,
                                    mvp_ireduce_scatter_inter_sched_remote_reduce_local_scatterv_call_counter,
                                    1);
            mpi_errno = MPIR_Ireduce_scatter_inter_sched_remote_reduce_local_scatterv(sendbuf,
                                recvbuf, recvcounts, datatype, op, comm_ptr, *sched_p);
            break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ireduce_scatter_sched_impl(const void *sendbuf, void *recvbuf, const MPI_Aint recvcounts[],
                                    MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                                    bool is_persistent, void **sched_p,
                                    enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_IREDUCE_SCATTER_INTRA_ALGORITHM) {
            case MPIR_CVAR_IREDUCE_SCATTER_INTRA_ALGORITHM_sched_noncommutative:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, comm_ptr->local_size == comm_ptr->coll.pof2, mpi_errno,
                                               "Ireduce_scatter sched_noncommutative cannot be applied.\n");
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP,
                                        mvp_ireduce_scatter_intra_sched_noncommutative_call_counter,
                                        1);
                mpi_errno = MPIR_Ireduce_scatter_intra_sched_noncommutative(sendbuf, recvbuf,
                                    recvcounts, datatype, op, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IREDUCE_SCATTER_INTRA_ALGORITHM_sched_recursive_doubling:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP,
                                        mvp_ireduce_scatter_intra_sched_recursive_doubling_call_counter,
                                        1);
                mpi_errno = MPIR_Ireduce_scatter_intra_sched_recursive_doubling(sendbuf, recvbuf,
                                    recvcounts, datatype, op, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IREDUCE_SCATTER_INTRA_ALGORITHM_sched_pairwise:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, MPIR_Op_is_commutative(op), mpi_errno,
                                               "Ireduce_scatter sched_pairwise cannot be applied.\n");
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ireduce_scatter_intra_sched_pairwise_call_counter, 1);
                mpi_errno = MPIR_Ireduce_scatter_intra_sched_pairwise(sendbuf, recvbuf, recvcounts,
                                    datatype, op, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IREDUCE_SCATTER_INTRA_ALGORITHM_sched_recursive_halving:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, MPIR_Op_is_commutative(op), mpi_errno,
                                               "Ireduce_scatter sched_recursive_halving cannot be applied.\n");
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP,
                                        mvp_ireduce_scatter_intra_sched_recursive_halving_call_counter,
                                        1);
                mpi_errno = MPIR_Ireduce_scatter_intra_sched_recursive_halving(sendbuf, recvbuf,
                                    recvcounts, datatype, op, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IREDUCE_SCATTER_INTRA_ALGORITHM_tsp_recexch:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, MPIR_Op_is_commutative(op), mpi_errno,
                                               "Ireduce_scatter tsp_recexch cannot be applied.\n");
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ireduce_scatter_intra_tsp_recexch_call_counter, 1);
                mpi_errno = MPIR_TSP_Ireduce_scatter_sched_intra_recexch(sendbuf, recvbuf, recvcounts,
                                    datatype, op, comm_ptr,
                                    IREDUCE_SCATTER_RECEXCH_TYPE_DISTANCE_DOUBLING,
                                    MPIR_CVAR_IREDUCE_SCATTER_RECEXCH_KVAL, *sched_p);
                break;
            case MPIR_CVAR_IREDUCE_SCATTER_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Ireduce_scatter_allcomm_sched_auto(sendbuf, recvbuf, recvcounts,
                                datatype, op, comm_ptr, is_persistent, sched_p, sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        switch (MPIR_CVAR_IREDUCE_SCATTER_INTER_ALGORITHM) {
            case MPIR_CVAR_IREDUCE_SCATTER_INTER_ALGORITHM_sched_remote_reduce_local_scatterv:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP,
                                        mvp_ireduce_scatter_inter_sched_remote_reduce_local_scatterv_call_counter,
                                        1);
                mpi_errno = MPIR_Ireduce_scatter_inter_sched_remote_reduce_local_scatterv(sendbuf,
                                    recvbuf, recvcounts, datatype, op, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IREDUCE_SCATTER_INTER_ALGORITHM_auto:
                mpi_errno = MPIR_Ireduce_scatter_allcomm_sched_auto(sendbuf, recvbuf, recvcounts,
                                datatype, op, comm_ptr, is_persistent, sched_p, sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    }
    MPIR_ERR_CHECK(mpi_errno);
    goto fn_exit;
    
  fallback:
    mpi_errno = MPIR_Ireduce_scatter_allcomm_sched_auto(sendbuf, recvbuf, recvcounts, datatype, op,
                                                        comm_ptr, is_persistent, sched_p,
                                                        sched_type_p);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ireduce_scatter_impl(const void *sendbuf, void *recvbuf, const MPI_Aint recvcounts[],
                              MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                              MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    enum MPIR_sched_type sched_type;
    void *sched;
    
    *request = NULL;
    mpi_errno = MPIR_Ireduce_scatter_sched_impl(sendbuf, recvbuf, recvcounts, datatype, op,
                                                comm_ptr, false, &sched, &sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    MPII_SCHED_START(sched_type, sched, comm_ptr, request);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ireduce_scatter(const void *sendbuf, void *recvbuf, const MPI_Aint recvcounts[],
                         MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                         MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_ireduce_scatter_call_counter, mvp_ireduce_scatter_timer);
    void *in_recvbuf = recvbuf;
    void *host_sendbuf = NULL;
    void *host_recvbuf = NULL;
    
    MPI_Aint count = 0;
    for (int i = 0; i < MPIR_Comm_size(comm_ptr); i++) {
        count += recvcounts[i];
    }
    
    if(!MPIR_Typerep_reduce_is_supported(op, count, datatype))
      MPIR_Coll_host_buffer_alloc(sendbuf, recvbuf, count, datatype, &host_sendbuf, &host_recvbuf);
    
    if (host_sendbuf) {
        sendbuf = host_sendbuf;
    }
    if (host_recvbuf) {
        recvbuf = host_recvbuf;
    }
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_IREDUCE_SCATTER_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Ireduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm_ptr,
                                         request);
    } else {
        mpi_errno = MPIR_Ireduce_scatter_impl(sendbuf, recvbuf, recvcounts, datatype, op, comm_ptr,
                                              request);
    }
    MPIR_Coll_host_buffer_swap_back(host_sendbuf, host_recvbuf, in_recvbuf, recvcounts[comm_ptr->rank], datatype, *request);
    
    MVP_COLL_PVAR_UPDATE_END(mvp_ireduce_scatter_timer);
    
    return mpi_errno;
}

int MPIR_Reduce_scatter_init_impl(const void *sendbuf, void *recvbuf, const MPI_Aint recvcounts[],
                                  MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                                  MPIR_Info * info_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Request *req = MPIR_Request_create(MPIR_REQUEST_KIND__PREQUEST_COLL);
    MPIR_ERR_CHKANDJUMP(!req, mpi_errno, MPI_ERR_OTHER, "**nomem");
    MPIR_Comm_add_ref(comm_ptr);
    req->comm = comm_ptr;
    MPIR_Comm_save_inactive_request(comm_ptr, req);
    req->u.persist_coll.sched_type = MPIR_SCHED_INVALID;
    req->u.persist_coll.real_request = NULL;
    mpi_errno = MPIR_Ireduce_scatter_sched_impl(sendbuf, recvbuf, recvcounts, datatype, op,
                                                comm_ptr, true, &req->u.persist_coll.sched,
                                                &req->u.persist_coll.sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    
    *request = req;
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Reduce_scatter_init(const void *sendbuf, void *recvbuf, const MPI_Aint recvcounts[],
                             MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                             MPIR_Info * info_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    void *in_recvbuf = recvbuf;
    void *host_sendbuf = NULL;
    void *host_recvbuf = NULL;
    
    MPI_Aint count = 0;
    for (int i = 0; i < MPIR_Comm_size(comm_ptr); i++) {
        count += recvcounts[i];
    }
    
    if(!MPIR_Typerep_reduce_is_supported(op, count, datatype))
      MPIR_Coll_host_buffer_alloc(sendbuf, recvbuf, count, datatype, &host_sendbuf, &host_recvbuf);
    
    if (host_sendbuf) {
        sendbuf = host_sendbuf;
    }
    if (host_recvbuf) {
        recvbuf = host_recvbuf;
    }
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_REDUCE_SCATTER_INIT_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Reduce_scatter_init(sendbuf, recvbuf, recvcounts, datatype, op, comm_ptr,
                                             info_ptr, request);
    } else {
        mpi_errno = MPIR_Reduce_scatter_init_impl(sendbuf, recvbuf, recvcounts, datatype, op,
                                                  comm_ptr, info_ptr, request);
    }
    MPIR_Coll_host_buffer_persist_set(host_sendbuf, host_recvbuf, in_recvbuf, recvcounts[comm_ptr->rank], datatype, *request);
    
    return mpi_errno;
}

/* ---- reduce_scatter_block ---- */

int MPIR_Reduce_scatter_block_allcomm_auto(const void *sendbuf, void *recvbuf, MPI_Aint recvcount,
                                           MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                                           MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__REDUCE_SCATTER_BLOCK,
        .comm_ptr = comm_ptr,
        .u.reduce_scatter_block.sendbuf = sendbuf,
        .u.reduce_scatter_block.recvbuf = recvbuf,
        .u.reduce_scatter_block.recvcount = recvcount,
        .u.reduce_scatter_block.datatype = datatype,
        .u.reduce_scatter_block.op = op,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_scatter_block_intra_noncommutative:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_reduce_scatter_block_intra_noncommutative_call_counter,
                                    1);
            mpi_errno = MPIR_Reduce_scatter_block_intra_noncommutative(sendbuf, recvbuf, recvcount,
                                datatype, op, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_scatter_block_intra_recursive_doubling:
            MPIR_T_PVAR_COUNTER_INC(MVP,
                                    mvp_reduce_scatter_block_intra_recursive_doubling_call_counter,
                                    1);
            mpi_errno = MPIR_Reduce_scatter_block_intra_recursive_doubling(sendbuf, recvbuf,
                                recvcount, datatype, op, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_scatter_block_intra_pairwise:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_reduce_scatter_block_intra_pairwise_call_counter, 1);
            mpi_errno = MPIR_Reduce_scatter_block_intra_pairwise(sendbuf, recvbuf, recvcount,
                                datatype, op, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_scatter_block_intra_recursive_halving:
            MPIR_T_PVAR_COUNTER_INC(MVP,
                                    mvp_reduce_scatter_block_intra_recursive_halving_call_counter,
                                    1);
            mpi_errno = MPIR_Reduce_scatter_block_intra_recursive_halving(sendbuf, recvbuf,
                                recvcount, datatype, op, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_scatter_block_inter_remote_reduce_local_scatter:
            MPIR_T_PVAR_COUNTER_INC(MVP,
                                    mvp_reduce_scatter_block_inter_remote_reduce_local_scatter_call_counter,
                                    1);
            mpi_errno = MPIR_Reduce_scatter_block_inter_remote_reduce_local_scatter(sendbuf,
                                recvbuf, recvcount, datatype, op, comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_scatter_block_allcomm_nb:
           mpi_errno = MPIR_Reduce_scatter_block_allcomm_nb(sendbuf, recvbuf, recvcount, datatype,
                                                            op, comm_ptr, errflag);
           break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Reduce_scatter_block_impl(const void *sendbuf, void *recvbuf, MPI_Aint recvcount,
                                   MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                                   MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_REDUCE_SCATTER_BLOCK_INTRA_ALGORITHM) {
            case MPIR_CVAR_REDUCE_SCATTER_BLOCK_INTRA_ALGORITHM_noncommutative:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, comm_ptr->local_size == comm_ptr->coll.pof2, mpi_errno,
                                               "Reduce_scatter_block noncommutative cannot be applied.\n");
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_reduce_scatter_block_intra_noncommutative_call_counter,
                                        1);
                mpi_errno = MPIR_Reduce_scatter_block_intra_noncommutative(sendbuf, recvbuf, recvcount,
                                    datatype, op, comm_ptr, errflag);
                break;
            case MPIR_CVAR_REDUCE_SCATTER_BLOCK_INTRA_ALGORITHM_recursive_doubling:
                MPIR_T_PVAR_COUNTER_INC(MVP,
                                        mvp_reduce_scatter_block_intra_recursive_doubling_call_counter,
                                        1);
                mpi_errno = MPIR_Reduce_scatter_block_intra_recursive_doubling(sendbuf, recvbuf,
                                    recvcount, datatype, op, comm_ptr, errflag);
                break;
            case MPIR_CVAR_REDUCE_SCATTER_BLOCK_INTRA_ALGORITHM_pairwise:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, MPIR_Op_is_commutative(op), mpi_errno,
                                               "Reduce_scatter_block pairwise cannot be applied.\n");
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_reduce_scatter_block_intra_pairwise_call_counter, 1);
                mpi_errno = MPIR_Reduce_scatter_block_intra_pairwise(sendbuf, recvbuf, recvcount,
                                    datatype, op, comm_ptr, errflag);
                break;
            case MPIR_CVAR_REDUCE_SCATTER_BLOCK_INTRA_ALGORITHM_recursive_halving:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, MPIR_Op_is_commutative(op), mpi_errno,
                                               "Reduce_scatter_block recursive_halving cannot be applied.\n");
                MPIR_T_PVAR_COUNTER_INC(MVP,
                                        mvp_reduce_scatter_block_intra_recursive_halving_call_counter,
                                        1);
                mpi_errno = MPIR_Reduce_scatter_block_intra_recursive_halving(sendbuf, recvbuf,
                                    recvcount, datatype, op, comm_ptr, errflag);
                break;
            case MPIR_CVAR_REDUCE_SCATTER_BLOCK_INTRA_ALGORITHM_nb:
                mpi_errno = MPIR_Reduce_scatter_block_allcomm_nb(sendbuf, recvbuf, recvcount,
                                datatype, op, comm_ptr, errflag);
                 break;
            case MPIR_CVAR_REDUCE_SCATTER_BLOCK_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Reduce_scatter_block_allcomm_auto(sendbuf, recvbuf, recvcount,
                                datatype, op, comm_ptr, errflag);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        switch (MPIR_CVAR_REDUCE_SCATTER_BLOCK_INTER_ALGORITHM) {
            case MPIR_CVAR_REDUCE_SCATTER_BLOCK_INTER_ALGORITHM_remote_reduce_local_scatter:
                MPIR_T_PVAR_COUNTER_INC(MVP,
                                        mvp_reduce_scatter_block_inter_remote_reduce_local_scatter_call_counter,
                                        1);
                mpi_errno = MPIR_Reduce_scatter_block_inter_remote_reduce_local_scatter(sendbuf,
                                    recvbuf, recvcount, datatype, op, comm_ptr, errflag);
                break;
            case MPIR_CVAR_REDUCE_SCATTER_BLOCK_INTER_ALGORITHM_nb:
                mpi_errno = MPIR_Reduce_scatter_block_allcomm_nb(sendbuf, recvbuf, recvcount,
                                datatype, op, comm_ptr, errflag);
                 break;
            case MPIR_CVAR_REDUCE_SCATTER_BLOCK_INTER_ALGORITHM_auto:
                mpi_errno = MPIR_Reduce_scatter_block_allcomm_auto(sendbuf, recvbuf, recvcount,
                                datatype, op, comm_ptr, errflag);
                break;
            default:
                MPIR_Assert(0);
        }
    }
    MPIR_ERR_CHECK(mpi_errno);
    goto fn_exit;
    
  fallback:
    mpi_errno = MPIR_Reduce_scatter_block_allcomm_auto(sendbuf, recvbuf, recvcount, datatype, op,
                                                       comm_ptr, errflag);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Reduce_scatter_block(const void *sendbuf, void *recvbuf, MPI_Aint recvcount,
                              MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                              MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_reduce_scatter_block_call_counter, mvp_reduce_scatter_block_timer);
    void *in_recvbuf = recvbuf;
    void *host_sendbuf = NULL;
    void *host_recvbuf = NULL;
    
    MPI_Aint count = MPIR_Comm_size(comm_ptr) * recvcount;
    if(!MPIR_Typerep_reduce_is_supported(op, count, datatype))
      MPIR_Coll_host_buffer_alloc(sendbuf, recvbuf, count, datatype, &host_sendbuf, &host_recvbuf);
    
    if (host_sendbuf) {
        sendbuf = host_sendbuf;
    }
    if (host_recvbuf) {
        recvbuf = host_recvbuf;
    }
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_REDUCE_SCATTER_BLOCK_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Reduce_scatter_block(sendbuf, recvbuf, recvcount, datatype, op, comm_ptr,
                                              errflag);
    } else {
        mpi_errno = MPIR_Reduce_scatter_block_impl(sendbuf, recvbuf, recvcount, datatype, op,
                                                   comm_ptr, errflag);
    }
    if (host_recvbuf) {
        recvbuf = in_recvbuf;
        MPIR_Localcopy(host_recvbuf, count, datatype, recvbuf, count, datatype);
    }
    MPIR_Coll_host_buffer_free(host_sendbuf, host_recvbuf);
    
    MVP_COLL_PVAR_UPDATE_END(mvp_reduce_scatter_block_timer);
    
    return mpi_errno;
}

/* ---- ireduce_scatter_block ---- */

int MPIR_Ireduce_scatter_block_allcomm_sched_auto(const void *sendbuf, void *recvbuf,
                                                  MPI_Aint recvcount, MPI_Datatype datatype,
                                                  MPI_Op op, MPIR_Comm * comm_ptr,
                                                  bool is_persistent, void **sched_p,
                                                  enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__IREDUCE_SCATTER_BLOCK,
        .comm_ptr = comm_ptr,
        .u.ireduce_scatter_block.sendbuf = sendbuf,
        .u.ireduce_scatter_block.recvbuf = recvbuf,
        .u.ireduce_scatter_block.recvcount = recvcount,
        .u.ireduce_scatter_block.datatype = datatype,
        .u.ireduce_scatter_block.op = op,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_scatter_block_intra_sched_noncommutative:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP,
                                    mvp_ireduce_scatter_block_intra_sched_noncommutative_call_counter,
                                    1);
            mpi_errno = MPIR_Ireduce_scatter_block_intra_sched_noncommutative(sendbuf, recvbuf,
                                recvcount, datatype, op, comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_scatter_block_intra_sched_recursive_doubling:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP,
                                    mvp_ireduce_scatter_block_intra_sched_recursive_doubling_call_counter,
                                    1);
            mpi_errno = MPIR_Ireduce_scatter_block_intra_sched_recursive_doubling(sendbuf, recvbuf,
                                recvcount, datatype, op, comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_scatter_block_intra_sched_pairwise:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP,
                                    mvp_ireduce_scatter_block_intra_sched_pairwise_call_counter,
                                    1);
            mpi_errno = MPIR_Ireduce_scatter_block_intra_sched_pairwise(sendbuf, recvbuf, recvcount,
                                datatype, op, comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_scatter_block_intra_sched_recursive_halving:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP,
                                    mvp_ireduce_scatter_block_intra_sched_recursive_halving_call_counter,
                                    1);
            mpi_errno = MPIR_Ireduce_scatter_block_intra_sched_recursive_halving(sendbuf, recvbuf,
                                recvcount, datatype, op, comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_scatter_block_intra_tsp_recexch:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ireduce_scatter_block_intra_tsp_recexch_call_counter,
                                    1);
            mpi_errno = MPIR_TSP_Ireduce_scatter_block_sched_intra_recexch(sendbuf, recvbuf,
                                recvcount, datatype, op, comm_ptr,
                                cnt->u.ireduce_scatter_block.intra_tsp_recexch.k, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_scatter_block_inter_sched_remote_reduce_local_scatterv:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP,
                                    mvp_ireduce_scatter_block_inter_sched_remote_reduce_local_scatterv_call_counter,
                                    1);
            mpi_errno = MPIR_Ireduce_scatter_block_inter_sched_remote_reduce_local_scatterv(sendbuf,
                                recvbuf, recvcount, datatype, op, comm_ptr, *sched_p);
            break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ireduce_scatter_block_sched_impl(const void *sendbuf, void *recvbuf, MPI_Aint recvcount,
                                          MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                                          bool is_persistent, void **sched_p,
                                          enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_IREDUCE_SCATTER_BLOCK_INTRA_ALGORITHM) {
            case MPIR_CVAR_IREDUCE_SCATTER_BLOCK_INTRA_ALGORITHM_sched_noncommutative:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, comm_ptr->local_size == comm_ptr->coll.pof2, mpi_errno,
                                               "Ireduce_scatter_block sched_noncommutative cannot be applied.\n");
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP,
                                        mvp_ireduce_scatter_block_intra_sched_noncommutative_call_counter,
                                        1);
                mpi_errno = MPIR_Ireduce_scatter_block_intra_sched_noncommutative(sendbuf, recvbuf,
                                    recvcount, datatype, op, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IREDUCE_SCATTER_BLOCK_INTRA_ALGORITHM_sched_recursive_doubling:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP,
                                        mvp_ireduce_scatter_block_intra_sched_recursive_doubling_call_counter,
                                        1);
                mpi_errno = MPIR_Ireduce_scatter_block_intra_sched_recursive_doubling(sendbuf, recvbuf,
                                    recvcount, datatype, op, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IREDUCE_SCATTER_BLOCK_INTRA_ALGORITHM_sched_pairwise:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, MPIR_Op_is_commutative(op), mpi_errno,
                                               "Ireduce_scatter_block sched_pairwise cannot be applied.\n");
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP,
                                        mvp_ireduce_scatter_block_intra_sched_pairwise_call_counter,
                                        1);
                mpi_errno = MPIR_Ireduce_scatter_block_intra_sched_pairwise(sendbuf, recvbuf, recvcount,
                                    datatype, op, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IREDUCE_SCATTER_BLOCK_INTRA_ALGORITHM_sched_recursive_halving:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, MPIR_Op_is_commutative(op), mpi_errno,
                                               "Ireduce_scatter_block sched_recursive_halving cannot be applied.\n");
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP,
                                        mvp_ireduce_scatter_block_intra_sched_recursive_halving_call_counter,
                                        1);
                mpi_errno = MPIR_Ireduce_scatter_block_intra_sched_recursive_halving(sendbuf, recvbuf,
                                    recvcount, datatype, op, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IREDUCE_SCATTER_BLOCK_INTRA_ALGORITHM_tsp_recexch:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, MPIR_Op_is_commutative(op), mpi_errno,
                                               "Ireduce_scatter_block tsp_recexch cannot be applied.\n");
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ireduce_scatter_block_intra_tsp_recexch_call_counter,
                                        1);
                mpi_errno = MPIR_TSP_Ireduce_scatter_block_sched_intra_recexch(sendbuf, recvbuf,
                                    recvcount, datatype, op, comm_ptr,
                                    MPIR_CVAR_IREDUCE_SCATTER_BLOCK_RECEXCH_KVAL, *sched_p);
                break;
            case MPIR_CVAR_IREDUCE_SCATTER_BLOCK_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Ireduce_scatter_block_allcomm_sched_auto(sendbuf, recvbuf,
                                recvcount, datatype, op, comm_ptr, is_persistent, sched_p,
                                sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        switch (MPIR_CVAR_IREDUCE_SCATTER_BLOCK_INTER_ALGORITHM) {
            case MPIR_CVAR_IREDUCE_SCATTER_BLOCK_INTER_ALGORITHM_sched_remote_reduce_local_scatterv:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP,
                                        mvp_ireduce_scatter_block_inter_sched_remote_reduce_local_scatterv_call_counter,
                                        1);
                mpi_errno = MPIR_Ireduce_scatter_block_inter_sched_remote_reduce_local_scatterv(sendbuf,
                                    recvbuf, recvcount, datatype, op, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IREDUCE_SCATTER_BLOCK_INTER_ALGORITHM_auto:
                mpi_errno = MPIR_Ireduce_scatter_block_allcomm_sched_auto(sendbuf, recvbuf,
                                recvcount, datatype, op, comm_ptr, is_persistent, sched_p,
                                sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    }
    MPIR_ERR_CHECK(mpi_errno);
    goto fn_exit;
    
  fallback:
    mpi_errno = MPIR_Ireduce_scatter_block_allcomm_sched_auto(sendbuf, recvbuf, recvcount, datatype,
                        op, comm_ptr, is_persistent, sched_p, sched_type_p);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ireduce_scatter_block_impl(const void *sendbuf, void *recvbuf, MPI_Aint recvcount,
                                    MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                                    MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    enum MPIR_sched_type sched_type;
    void *sched;
    
    *request = NULL;
    mpi_errno = MPIR_Ireduce_scatter_block_sched_impl(sendbuf, recvbuf, recvcount, datatype, op,
                                                      comm_ptr, false, &sched, &sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    MPII_SCHED_START(sched_type, sched, comm_ptr, request);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ireduce_scatter_block(const void *sendbuf, void *recvbuf, MPI_Aint recvcount,
                               MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                               MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_ireduce_scatter_block_call_counter, mvp_ireduce_scatter_block_timer);
    void *in_recvbuf = recvbuf;
    void *host_sendbuf = NULL;
    void *host_recvbuf = NULL;
    
    MPI_Aint count = MPIR_Comm_size(comm_ptr) * recvcount;
    if(!MPIR_Typerep_reduce_is_supported(op, count, datatype))
      MPIR_Coll_host_buffer_alloc(sendbuf, recvbuf, count, datatype, &host_sendbuf, &host_recvbuf);
    
    if (host_sendbuf) {
        sendbuf = host_sendbuf;
    }
    if (host_recvbuf) {
        recvbuf = host_recvbuf;
    }
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_IREDUCE_SCATTER_BLOCK_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Ireduce_scatter_block(sendbuf, recvbuf, recvcount, datatype, op, comm_ptr,
                                               request);
    } else {
        mpi_errno = MPIR_Ireduce_scatter_block_impl(sendbuf, recvbuf, recvcount, datatype, op,
                                                    comm_ptr, request);
    }
    MPIR_Coll_host_buffer_swap_back(host_sendbuf, host_recvbuf, in_recvbuf, recvcount, datatype, *request);
    
    MVP_COLL_PVAR_UPDATE_END(mvp_ireduce_scatter_block_timer);
    
    return mpi_errno;
}

int MPIR_Reduce_scatter_block_init_impl(const void *sendbuf, void *recvbuf, MPI_Aint recvcount,
                                        MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                                        MPIR_Info * info_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Request *req = MPIR_Request_create(MPIR_REQUEST_KIND__PREQUEST_COLL);
    MPIR_ERR_CHKANDJUMP(!req, mpi_errno, MPI_ERR_OTHER, "**nomem");
    MPIR_Comm_add_ref(comm_ptr);
    req->comm = comm_ptr;
    MPIR_Comm_save_inactive_request(comm_ptr, req);
    req->u.persist_coll.sched_type = MPIR_SCHED_INVALID;
    req->u.persist_coll.real_request = NULL;
    mpi_errno = MPIR_Ireduce_scatter_block_sched_impl(sendbuf, recvbuf, recvcount, datatype, op,
                                                      comm_ptr, true, &req->u.persist_coll.sched,
                                                      &req->u.persist_coll.sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    
    *request = req;
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Reduce_scatter_block_init(const void *sendbuf, void *recvbuf, MPI_Aint recvcount,
                                   MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                                   MPIR_Info * info_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    void *in_recvbuf = recvbuf;
    void *host_sendbuf = NULL;
    void *host_recvbuf = NULL;
    
    MPI_Aint count = MPIR_Comm_size(comm_ptr) * recvcount;
    if(!MPIR_Typerep_reduce_is_supported(op, count, datatype))
      MPIR_Coll_host_buffer_alloc(sendbuf, recvbuf, count, datatype, &host_sendbuf, &host_recvbuf);
    
    if (host_sendbuf) {
        sendbuf = host_sendbuf;
    }
    if (host_recvbuf) {
        recvbuf = host_recvbuf;
    }
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_REDUCE_SCATTER_BLOCK_INIT_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Reduce_scatter_block_init(sendbuf, recvbuf, recvcount, datatype, op,
                                                   comm_ptr, info_ptr, request);
    } else {
        mpi_errno = MPIR_Reduce_scatter_block_init_impl(sendbuf, recvbuf, recvcount, datatype, op,
                                                        comm_ptr, info_ptr, request);
    }
    MPIR_Coll_host_buffer_persist_set(host_sendbuf, host_recvbuf, in_recvbuf, recvcount, datatype, *request);
    
    return mpi_errno;
}

/* ---- scan ---- */

int MPIR_Scan_allcomm_auto(const void *sendbuf, void *recvbuf, MPI_Aint count,
                           MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                           MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__SCAN,
        .comm_ptr = comm_ptr,
        .u.scan.sendbuf = sendbuf,
        .u.scan.recvbuf = recvbuf,
        .u.scan.count = count,
        .u.scan.datatype = datatype,
        .u.scan.op = op,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Scan_intra_smp:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_scan_intra_smp_call_counter, 1);
            mpi_errno = MPIR_Scan_intra_smp(sendbuf, recvbuf, count, datatype, op, comm_ptr,
                                            errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Scan_intra_recursive_doubling:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_scan_intra_recursive_doubling_call_counter, 1);
            mpi_errno = MPIR_Scan_intra_recursive_doubling(sendbuf, recvbuf, count, datatype, op,
                                                           comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Scan_allcomm_nb:
           mpi_errno = MPIR_Scan_allcomm_nb(sendbuf, recvbuf, count, datatype, op, comm_ptr,
                                            errflag);
           break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Scan_impl(const void *sendbuf, void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                   MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_SCAN_INTRA_ALGORITHM) {
            case MPIR_CVAR_SCAN_INTRA_ALGORITHM_smp:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, MPIR_Op_is_commutative(op) && MPII_Comm_is_node_consecutive(comm_ptr), mpi_errno,
                                               "Scan smp cannot be applied.\n");
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_scan_intra_smp_call_counter, 1);
                mpi_errno = MPIR_Scan_intra_smp(sendbuf, recvbuf, count, datatype, op, comm_ptr,
                                                errflag);
                break;
            case MPIR_CVAR_SCAN_INTRA_ALGORITHM_recursive_doubling:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_scan_intra_recursive_doubling_call_counter, 1);
                mpi_errno = MPIR_Scan_intra_recursive_doubling(sendbuf, recvbuf, count, datatype, op,
                                                               comm_ptr, errflag);
                break;
            case MPIR_CVAR_SCAN_INTRA_ALGORITHM_nb:
                mpi_errno = MPIR_Scan_allcomm_nb(sendbuf, recvbuf, count, datatype, op, comm_ptr,
                                                 errflag);
                 break;
            case MPIR_CVAR_SCAN_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Scan_allcomm_auto(sendbuf, recvbuf, count, datatype, op, comm_ptr,
                                                   errflag);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        MPIR_Assert_error("Only intra-communicator allowed");
    }
    MPIR_ERR_CHECK(mpi_errno);
    goto fn_exit;
    
  fallback:
    mpi_errno = MPIR_Scan_allcomm_auto(sendbuf, recvbuf, count, datatype, op, comm_ptr, errflag);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Scan(const void *sendbuf, void *recvbuf, MPI_Aint count, MPI_Datatype datatype, MPI_Op op,
              MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_scan_call_counter, mvp_scan_timer);
    void *in_recvbuf = recvbuf;
    void *host_sendbuf = NULL;
    void *host_recvbuf = NULL;
    
    if(!MPIR_Typerep_reduce_is_supported(op, count, datatype))
      MPIR_Coll_host_buffer_alloc(sendbuf, recvbuf, count, datatype, &host_sendbuf, &host_recvbuf);
    
    if (host_sendbuf) {
        sendbuf = host_sendbuf;
    }
    if (host_recvbuf) {
        recvbuf = host_recvbuf;
    }
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_SCAN_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Scan(sendbuf, recvbuf, count, datatype, op, comm_ptr, errflag);
    } else {
        mpi_errno = MPIR_Scan_impl(sendbuf, recvbuf, count, datatype, op, comm_ptr, errflag);
    }
    if (host_recvbuf) {
        recvbuf = in_recvbuf;
        MPIR_Localcopy(host_recvbuf, count, datatype, recvbuf, count, datatype);
    }
    MPIR_Coll_host_buffer_free(host_sendbuf, host_recvbuf);
    
    MVP_COLL_PVAR_UPDATE_END(mvp_scan_timer);
    
    return mpi_errno;
}

/* ---- iscan ---- */

int MPIR_Iscan_allcomm_sched_auto(const void *sendbuf, void *recvbuf, MPI_Aint count,
                                  MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                                  bool is_persistent, void **sched_p,
                                  enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__ISCAN,
        .comm_ptr = comm_ptr,
        .u.iscan.sendbuf = sendbuf,
        .u.iscan.recvbuf = recvbuf,
        .u.iscan.count = count,
        .u.iscan.datatype = datatype,
        .u.iscan.op = op,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iscan_intra_sched_smp:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iscan_intra_sched_smp_call_counter, 1);
            mpi_errno = MPIR_Iscan_intra_sched_smp(sendbuf, recvbuf, count, datatype, op, comm_ptr,
                                                   *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iscan_intra_sched_recursive_doubling:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iscan_intra_sched_recursive_doubling_call_counter, 1);
            mpi_errno = MPIR_Iscan_intra_sched_recursive_doubling(sendbuf, recvbuf, count, datatype,
                                op, comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iscan_intra_tsp_recursive_doubling:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iscan_intra_tsp_recursive_doubling_call_counter, 1);
            mpi_errno = MPIR_TSP_Iscan_sched_intra_recursive_doubling(sendbuf, recvbuf, count,
                                datatype, op, comm_ptr, *sched_p);
            break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Iscan_sched_impl(const void *sendbuf, void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                          MPI_Op op, MPIR_Comm * comm_ptr, bool is_persistent, void **sched_p,
                          enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_ISCAN_INTRA_ALGORITHM) {
            case MPIR_CVAR_ISCAN_INTRA_ALGORITHM_sched_smp:
                MPII_COLLECTIVE_FALLBACK_CHECK(comm_ptr->rank, MPIR_Op_is_commutative(op) && MPII_Comm_is_node_consecutive(comm_ptr), mpi_errno,
                                               "Iscan sched_smp cannot be applied.\n");
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iscan_intra_sched_smp_call_counter, 1);
                mpi_errno = MPIR_Iscan_intra_sched_smp(sendbuf, recvbuf, count, datatype, op, comm_ptr,
                                                       *sched_p);
                break;
            case MPIR_CVAR_ISCAN_INTRA_ALGORITHM_sched_recursive_doubling:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iscan_intra_sched_recursive_doubling_call_counter, 1);
                mpi_errno = MPIR_Iscan_intra_sched_recursive_doubling(sendbuf, recvbuf, count, datatype,
                                    op, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_ISCAN_INTRA_ALGORITHM_tsp_recursive_doubling:
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iscan_intra_tsp_recursive_doubling_call_counter, 1);
                mpi_errno = MPIR_TSP_Iscan_sched_intra_recursive_doubling(sendbuf, recvbuf, count,
                                    datatype, op, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_ISCAN_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Iscan_allcomm_sched_auto(sendbuf, recvbuf, count, datatype, op,
                                                          comm_ptr, is_persistent, sched_p,
                                                          sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        MPIR_Assert_error("Only intra-communicator allowed");
    }
    MPIR_ERR_CHECK(mpi_errno);
    goto fn_exit;
    
  fallback:
    mpi_errno = MPIR_Iscan_allcomm_sched_auto(sendbuf, recvbuf, count, datatype, op, comm_ptr,
                                              is_persistent, sched_p, sched_type_p);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Iscan_impl(const void *sendbuf, void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                    MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    enum MPIR_sched_type sched_type;
    void *sched;
    
    *request = NULL;
    mpi_errno = MPIR_Iscan_sched_impl(sendbuf, recvbuf, count, datatype, op, comm_ptr, false,
                                      &sched, &sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    MPII_SCHED_START(sched_type, sched, comm_ptr, request);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Iscan(const void *sendbuf, void *recvbuf, MPI_Aint count, MPI_Datatype datatype, MPI_Op op,
               MPIR_Comm * comm_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_iscan_call_counter, mvp_iscan_timer);
    void *in_recvbuf = recvbuf;
    void *host_sendbuf = NULL;
    void *host_recvbuf = NULL;
    
    if(!MPIR_Typerep_reduce_is_supported(op, count, datatype))
      MPIR_Coll_host_buffer_alloc(sendbuf, recvbuf, count, datatype, &host_sendbuf, &host_recvbuf);
    
    if (host_sendbuf) {
        sendbuf = host_sendbuf;
    }
    if (host_recvbuf) {
        recvbuf = host_recvbuf;
    }
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_ISCAN_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Iscan(sendbuf, recvbuf, count, datatype, op, comm_ptr, request);
    } else {
        mpi_errno = MPIR_Iscan_impl(sendbuf, recvbuf, count, datatype, op, comm_ptr, request);
    }
    MPIR_Coll_host_buffer_swap_back(host_sendbuf, host_recvbuf, in_recvbuf, count, datatype, *request);
    
    MVP_COLL_PVAR_UPDATE_END(mvp_iscan_timer);
    
    return mpi_errno;
}

int MPIR_Scan_init_impl(const void *sendbuf, void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                        MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                        MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Request *req = MPIR_Request_create(MPIR_REQUEST_KIND__PREQUEST_COLL);
    MPIR_ERR_CHKANDJUMP(!req, mpi_errno, MPI_ERR_OTHER, "**nomem");
    MPIR_Comm_add_ref(comm_ptr);
    req->comm = comm_ptr;
    MPIR_Comm_save_inactive_request(comm_ptr, req);
    req->u.persist_coll.sched_type = MPIR_SCHED_INVALID;
    req->u.persist_coll.real_request = NULL;
    mpi_errno = MPIR_Iscan_sched_impl(sendbuf, recvbuf, count, datatype, op, comm_ptr, true,
                                      &req->u.persist_coll.sched, &req->u.persist_coll.sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    
    *request = req;
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Scan_init(const void *sendbuf, void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                   MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Info * info_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    void *in_recvbuf = recvbuf;
    void *host_sendbuf = NULL;
    void *host_recvbuf = NULL;
    
    if(!MPIR_Typerep_reduce_is_supported(op, count, datatype))
      MPIR_Coll_host_buffer_alloc(sendbuf, recvbuf, count, datatype, &host_sendbuf, &host_recvbuf);
    
    if (host_sendbuf) {
        sendbuf = host_sendbuf;
    }
    if (host_recvbuf) {
        recvbuf = host_recvbuf;
    }
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_SCAN_INIT_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Scan_init(sendbuf, recvbuf, count, datatype, op, comm_ptr, info_ptr,
                                   request);
    } else {
        mpi_errno = MPIR_Scan_init_impl(sendbuf, recvbuf, count, datatype, op, comm_ptr, info_ptr,
                                        request);
    }
    MPIR_Coll_host_buffer_persist_set(host_sendbuf, host_recvbuf, in_recvbuf, count, datatype, *request);
    
    return mpi_errno;
}

/* ---- exscan ---- */

int MPIR_Exscan_allcomm_auto(const void *sendbuf, void *recvbuf, MPI_Aint count,
                             MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                             MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__EXSCAN,
        .comm_ptr = comm_ptr,
        .u.exscan.sendbuf = sendbuf,
        .u.exscan.recvbuf = recvbuf,
        .u.exscan.count = count,
        .u.exscan.datatype = datatype,
        .u.exscan.op = op,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Exscan_intra_recursive_doubling:
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_exscan_intra_recursive_doubling_call_counter, 1);
            mpi_errno = MPIR_Exscan_intra_recursive_doubling(sendbuf, recvbuf, count, datatype, op,
                                comm_ptr, errflag);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Exscan_allcomm_nb:
           mpi_errno = MPIR_Exscan_allcomm_nb(sendbuf, recvbuf, count, datatype, op, comm_ptr,
                                              errflag);
           break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Exscan_impl(const void *sendbuf, void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                     MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_EXSCAN_INTRA_ALGORITHM) {
            case MPIR_CVAR_EXSCAN_INTRA_ALGORITHM_recursive_doubling:
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_exscan_intra_recursive_doubling_call_counter, 1);
                mpi_errno = MPIR_Exscan_intra_recursive_doubling(sendbuf, recvbuf, count, datatype, op,
                                    comm_ptr, errflag);
                break;
            case MPIR_CVAR_EXSCAN_INTRA_ALGORITHM_nb:
                mpi_errno = MPIR_Exscan_allcomm_nb(sendbuf, recvbuf, count, datatype, op, comm_ptr,
                                                   errflag);
                 break;
            case MPIR_CVAR_EXSCAN_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Exscan_allcomm_auto(sendbuf, recvbuf, count, datatype, op,
                                                     comm_ptr, errflag);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        MPIR_Assert_error("Only intra-communicator allowed");
    }
    MPIR_ERR_CHECK(mpi_errno);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Exscan(const void *sendbuf, void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_exscan_call_counter, mvp_exscan_timer);
    void *in_recvbuf = recvbuf;
    void *host_sendbuf = NULL;
    void *host_recvbuf = NULL;
    
    if(!MPIR_Typerep_reduce_is_supported(op, count, datatype))
      MPIR_Coll_host_buffer_alloc(sendbuf, recvbuf, count, datatype, &host_sendbuf, &host_recvbuf);
    
    if (host_sendbuf) {
        sendbuf = host_sendbuf;
    }
    if (host_recvbuf) {
        recvbuf = host_recvbuf;
    }
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_EXSCAN_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Exscan(sendbuf, recvbuf, count, datatype, op, comm_ptr, errflag);
    } else {
        mpi_errno = MPIR_Exscan_impl(sendbuf, recvbuf, count, datatype, op, comm_ptr, errflag);
    }
    if (host_recvbuf) {
        recvbuf = in_recvbuf;
        MPIR_Localcopy(host_recvbuf, count, datatype, recvbuf, count, datatype);
    }
    MPIR_Coll_host_buffer_free(host_sendbuf, host_recvbuf);
    
    MVP_COLL_PVAR_UPDATE_END(mvp_exscan_timer);
    
    return mpi_errno;
}

/* ---- iexscan ---- */

int MPIR_Iexscan_allcomm_sched_auto(const void *sendbuf, void *recvbuf, MPI_Aint count,
                                    MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                                    bool is_persistent, void **sched_p,
                                    enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__IEXSCAN,
        .comm_ptr = comm_ptr,
        .u.iexscan.sendbuf = sendbuf,
        .u.iexscan.recvbuf = recvbuf,
        .u.iexscan.count = count,
        .u.iexscan.datatype = datatype,
        .u.iexscan.op = op,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iexscan_intra_sched_recursive_doubling:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iexscan_intra_sched_recursive_doubling_call_counter,
                                    1);
            mpi_errno = MPIR_Iexscan_intra_sched_recursive_doubling(sendbuf, recvbuf, count,
                                datatype, op, comm_ptr, *sched_p);
            break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Iexscan_sched_impl(const void *sendbuf, void *recvbuf, MPI_Aint count,
                            MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                            bool is_persistent, void **sched_p, enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_IEXSCAN_INTRA_ALGORITHM) {
            case MPIR_CVAR_IEXSCAN_INTRA_ALGORITHM_sched_recursive_doubling:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_iexscan_intra_sched_recursive_doubling_call_counter,
                                        1);
                mpi_errno = MPIR_Iexscan_intra_sched_recursive_doubling(sendbuf, recvbuf, count,
                                    datatype, op, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_IEXSCAN_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Iexscan_allcomm_sched_auto(sendbuf, recvbuf, count, datatype, op,
                                                            comm_ptr, is_persistent, sched_p,
                                                            sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        MPIR_Assert_error("Only intra-communicator allowed");
    }
    MPIR_ERR_CHECK(mpi_errno);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Iexscan_impl(const void *sendbuf, void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                      MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    enum MPIR_sched_type sched_type;
    void *sched;
    
    *request = NULL;
    mpi_errno = MPIR_Iexscan_sched_impl(sendbuf, recvbuf, count, datatype, op, comm_ptr, false,
                                        &sched, &sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    MPII_SCHED_START(sched_type, sched, comm_ptr, request);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Iexscan(const void *sendbuf, void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                 MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_iexscan_call_counter, mvp_iexscan_timer);
    void *in_recvbuf = recvbuf;
    void *host_sendbuf = NULL;
    void *host_recvbuf = NULL;
    
    if(!MPIR_Typerep_reduce_is_supported(op, count, datatype))
      MPIR_Coll_host_buffer_alloc(sendbuf, recvbuf, count, datatype, &host_sendbuf, &host_recvbuf);
    
    if (host_sendbuf) {
        sendbuf = host_sendbuf;
    }
    if (host_recvbuf) {
        recvbuf = host_recvbuf;
    }
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_IEXSCAN_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Iexscan(sendbuf, recvbuf, count, datatype, op, comm_ptr, request);
    } else {
        mpi_errno = MPIR_Iexscan_impl(sendbuf, recvbuf, count, datatype, op, comm_ptr, request);
    }
    MPIR_Coll_host_buffer_swap_back(host_sendbuf, host_recvbuf, in_recvbuf, count, datatype, *request);
    
    MVP_COLL_PVAR_UPDATE_END(mvp_iexscan_timer);
    
    return mpi_errno;
}

int MPIR_Exscan_init_impl(const void *sendbuf, void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                          MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                          MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Request *req = MPIR_Request_create(MPIR_REQUEST_KIND__PREQUEST_COLL);
    MPIR_ERR_CHKANDJUMP(!req, mpi_errno, MPI_ERR_OTHER, "**nomem");
    MPIR_Comm_add_ref(comm_ptr);
    req->comm = comm_ptr;
    MPIR_Comm_save_inactive_request(comm_ptr, req);
    req->u.persist_coll.sched_type = MPIR_SCHED_INVALID;
    req->u.persist_coll.real_request = NULL;
    mpi_errno = MPIR_Iexscan_sched_impl(sendbuf, recvbuf, count, datatype, op, comm_ptr, true,
                                        &req->u.persist_coll.sched,
                                        &req->u.persist_coll.sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    
    *request = req;
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Exscan_init(const void *sendbuf, void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                     MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                     MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    void *in_recvbuf = recvbuf;
    void *host_sendbuf = NULL;
    void *host_recvbuf = NULL;
    
    if(!MPIR_Typerep_reduce_is_supported(op, count, datatype))
      MPIR_Coll_host_buffer_alloc(sendbuf, recvbuf, count, datatype, &host_sendbuf, &host_recvbuf);
    
    if (host_sendbuf) {
        sendbuf = host_sendbuf;
    }
    if (host_recvbuf) {
        recvbuf = host_recvbuf;
    }
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_EXSCAN_INIT_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Exscan_init(sendbuf, recvbuf, count, datatype, op, comm_ptr, info_ptr,
                                     request);
    } else {
        mpi_errno = MPIR_Exscan_init_impl(sendbuf, recvbuf, count, datatype, op, comm_ptr, info_ptr,
                                          request);
    }
    MPIR_Coll_host_buffer_persist_set(host_sendbuf, host_recvbuf, in_recvbuf, count, datatype, *request);
    
    return mpi_errno;
}

/* ---- neighbor_allgather ---- */

int MPIR_Neighbor_allgather_allcomm_auto(const void *sendbuf, MPI_Aint sendcount,
                                         MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount,
                                         MPI_Datatype recvtype, MPIR_Comm * comm_ptr)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__NEIGHBOR_ALLGATHER,
        .comm_ptr = comm_ptr,
        .u.neighbor_allgather.sendbuf = sendbuf,
        .u.neighbor_allgather.sendcount = sendcount,
        .u.neighbor_allgather.sendtype = sendtype,
        .u.neighbor_allgather.recvbuf = recvbuf,
        .u.neighbor_allgather.recvcount = recvcount,
        .u.neighbor_allgather.recvtype = recvtype,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Neighbor_allgather_allcomm_nb:
           mpi_errno = MPIR_Neighbor_allgather_allcomm_nb(sendbuf, sendcount, sendtype, recvbuf,
                                                          recvcount, recvtype, comm_ptr);
           break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Neighbor_allgather_impl(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                                 void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                                 MPIR_Comm * comm_ptr)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_NEIGHBOR_ALLGATHER_INTRA_ALGORITHM) {
            case MPIR_CVAR_NEIGHBOR_ALLGATHER_INTRA_ALGORITHM_nb:
                mpi_errno = MPIR_Neighbor_allgather_allcomm_nb(sendbuf, sendcount, sendtype,
                                recvbuf, recvcount, recvtype, comm_ptr);
                 break;
            case MPIR_CVAR_NEIGHBOR_ALLGATHER_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Neighbor_allgather_allcomm_auto(sendbuf, sendcount, sendtype,
                                recvbuf, recvcount, recvtype, comm_ptr);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        MPIR_Assert_error("Only intra-communicator allowed");
    }
    MPIR_ERR_CHECK(mpi_errno);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Neighbor_allgather(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                            void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                            MPIR_Comm * comm_ptr)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_neighbor_allgather_call_counter, mvp_neighbor_allgather_timer);
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_NEIGHBOR_ALLGATHER_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Neighbor_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                            recvtype, comm_ptr);
    } else {
        mpi_errno = MPIR_Neighbor_allgather_impl(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                                 recvtype, comm_ptr);
    }
    
    MVP_COLL_PVAR_UPDATE_END(mvp_neighbor_allgather_timer);
    
    return mpi_errno;
}

/* ---- ineighbor_allgather ---- */

int MPIR_Ineighbor_allgather_allcomm_sched_auto(const void *sendbuf, MPI_Aint sendcount,
                                                MPI_Datatype sendtype, void *recvbuf,
                                                MPI_Aint recvcount, MPI_Datatype recvtype,
                                                MPIR_Comm * comm_ptr, bool is_persistent,
                                                void **sched_p, enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__INEIGHBOR_ALLGATHER,
        .comm_ptr = comm_ptr,
        .u.ineighbor_allgather.sendbuf = sendbuf,
        .u.ineighbor_allgather.sendcount = sendcount,
        .u.ineighbor_allgather.sendtype = sendtype,
        .u.ineighbor_allgather.recvbuf = recvbuf,
        .u.ineighbor_allgather.recvcount = recvcount,
        .u.ineighbor_allgather.recvtype = recvtype,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ineighbor_allgather_allcomm_sched_linear:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ineighbor_allgather_intra_sched_linear_call_counter,
                                    1);
            mpi_errno = MPIR_Ineighbor_allgather_allcomm_sched_linear(sendbuf, sendcount, sendtype,
                                recvbuf, recvcount, recvtype, comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ineighbor_allgather_allcomm_tsp_linear:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ineighbor_allgather_intra_tsp_linear_call_counter, 1);
            mpi_errno = MPIR_TSP_Ineighbor_allgather_sched_allcomm_linear(sendbuf, sendcount,
                                sendtype, recvbuf, recvcount, recvtype, comm_ptr, *sched_p);
            break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ineighbor_allgather_sched_impl(const void *sendbuf, MPI_Aint sendcount,
                                        MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount,
                                        MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                                        bool is_persistent, void **sched_p,
                                        enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_INEIGHBOR_ALLGATHER_INTRA_ALGORITHM) {
            case MPIR_CVAR_INEIGHBOR_ALLGATHER_INTRA_ALGORITHM_sched_linear:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ineighbor_allgather_intra_sched_linear_call_counter,
                                        1);
                mpi_errno = MPIR_Ineighbor_allgather_allcomm_sched_linear(sendbuf, sendcount, sendtype,
                                    recvbuf, recvcount, recvtype, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_INEIGHBOR_ALLGATHER_INTRA_ALGORITHM_tsp_linear:
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ineighbor_allgather_intra_tsp_linear_call_counter, 1);
                mpi_errno = MPIR_TSP_Ineighbor_allgather_sched_allcomm_linear(sendbuf, sendcount,
                                    sendtype, recvbuf, recvcount, recvtype, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_INEIGHBOR_ALLGATHER_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Ineighbor_allgather_allcomm_sched_auto(sendbuf, sendcount,
                                sendtype, recvbuf, recvcount, recvtype, comm_ptr, is_persistent,
                                sched_p, sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        MPIR_Assert_error("Only intra-communicator allowed");
    }
    MPIR_ERR_CHECK(mpi_errno);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ineighbor_allgather_impl(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                                  void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                                  MPIR_Comm * comm_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    enum MPIR_sched_type sched_type;
    void *sched;
    
    *request = NULL;
    mpi_errno = MPIR_Ineighbor_allgather_sched_impl(sendbuf, sendcount, sendtype, recvbuf,
                                                    recvcount, recvtype, comm_ptr, false, &sched,
                                                    &sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    MPII_SCHED_START(sched_type, sched, comm_ptr, request);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ineighbor_allgather(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                             void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                             MPIR_Comm * comm_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_ineighbor_allgather_call_counter, mvp_ineighbor_allgather_timer);
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_INEIGHBOR_ALLGATHER_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Ineighbor_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                             recvtype, comm_ptr, request);
    } else {
        mpi_errno = MPIR_Ineighbor_allgather_impl(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                                  recvtype, comm_ptr, request);
    }
    
    MVP_COLL_PVAR_UPDATE_END(mvp_ineighbor_allgather_timer);
    
    return mpi_errno;
}

int MPIR_Neighbor_allgather_init_impl(const void *sendbuf, MPI_Aint sendcount,
                                      MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount,
                                      MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                                      MPIR_Info * info_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Request *req = MPIR_Request_create(MPIR_REQUEST_KIND__PREQUEST_COLL);
    MPIR_ERR_CHKANDJUMP(!req, mpi_errno, MPI_ERR_OTHER, "**nomem");
    MPIR_Comm_add_ref(comm_ptr);
    req->comm = comm_ptr;
    MPIR_Comm_save_inactive_request(comm_ptr, req);
    req->u.persist_coll.sched_type = MPIR_SCHED_INVALID;
    req->u.persist_coll.real_request = NULL;
    mpi_errno = MPIR_Ineighbor_allgather_sched_impl(sendbuf, sendcount, sendtype, recvbuf,
                                                    recvcount, recvtype, comm_ptr, true,
                                                    &req->u.persist_coll.sched,
                                                    &req->u.persist_coll.sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    
    *request = req;
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Neighbor_allgather_init(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                                 void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                                 MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                                 MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_NEIGHBOR_ALLGATHER_INIT_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Neighbor_allgather_init(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                                 recvtype, comm_ptr, info_ptr, request);
    } else {
        mpi_errno = MPIR_Neighbor_allgather_init_impl(sendbuf, sendcount, sendtype, recvbuf,
                                                      recvcount, recvtype, comm_ptr, info_ptr,
                                                      request);
    }
    
    return mpi_errno;
}

/* ---- neighbor_allgatherv ---- */

int MPIR_Neighbor_allgatherv_allcomm_auto(const void *sendbuf, MPI_Aint sendcount,
                                          MPI_Datatype sendtype, void *recvbuf,
                                          const MPI_Aint recvcounts[], const MPI_Aint displs[],
                                          MPI_Datatype recvtype, MPIR_Comm * comm_ptr)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__NEIGHBOR_ALLGATHERV,
        .comm_ptr = comm_ptr,
        .u.neighbor_allgatherv.sendbuf = sendbuf,
        .u.neighbor_allgatherv.sendcount = sendcount,
        .u.neighbor_allgatherv.sendtype = sendtype,
        .u.neighbor_allgatherv.recvbuf = recvbuf,
        .u.neighbor_allgatherv.recvcounts = recvcounts,
        .u.neighbor_allgatherv.displs = displs,
        .u.neighbor_allgatherv.recvtype = recvtype,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Neighbor_allgatherv_allcomm_nb:
           mpi_errno = MPIR_Neighbor_allgatherv_allcomm_nb(sendbuf, sendcount, sendtype, recvbuf,
                                                           recvcounts, displs, recvtype, comm_ptr);
           break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Neighbor_allgatherv_impl(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                                  void *recvbuf, const MPI_Aint recvcounts[],
                                  const MPI_Aint displs[], MPI_Datatype recvtype,
                                  MPIR_Comm * comm_ptr)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_NEIGHBOR_ALLGATHERV_INTRA_ALGORITHM) {
            case MPIR_CVAR_NEIGHBOR_ALLGATHERV_INTRA_ALGORITHM_nb:
                mpi_errno = MPIR_Neighbor_allgatherv_allcomm_nb(sendbuf, sendcount, sendtype,
                                recvbuf, recvcounts, displs, recvtype, comm_ptr);
                 break;
            case MPIR_CVAR_NEIGHBOR_ALLGATHERV_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Neighbor_allgatherv_allcomm_auto(sendbuf, sendcount, sendtype,
                                recvbuf, recvcounts, displs, recvtype, comm_ptr);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        MPIR_Assert_error("Only intra-communicator allowed");
    }
    MPIR_ERR_CHECK(mpi_errno);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Neighbor_allgatherv(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                             void *recvbuf, const MPI_Aint recvcounts[], const MPI_Aint displs[],
                             MPI_Datatype recvtype, MPIR_Comm * comm_ptr)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_neighbor_allgatherv_call_counter, mvp_neighbor_allgatherv_timer);
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_NEIGHBOR_ALLGATHERV_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Neighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts,
                                             displs, recvtype, comm_ptr);
    } else {
        mpi_errno = MPIR_Neighbor_allgatherv_impl(sendbuf, sendcount, sendtype, recvbuf, recvcounts,
                                                  displs, recvtype, comm_ptr);
    }
    
    MVP_COLL_PVAR_UPDATE_END(mvp_neighbor_allgatherv_timer);
    
    return mpi_errno;
}

/* ---- ineighbor_allgatherv ---- */

int MPIR_Ineighbor_allgatherv_allcomm_sched_auto(const void *sendbuf, MPI_Aint sendcount,
                                                 MPI_Datatype sendtype, void *recvbuf,
                                                 const MPI_Aint recvcounts[],
                                                 const MPI_Aint displs[], MPI_Datatype recvtype,
                                                 MPIR_Comm * comm_ptr, bool is_persistent,
                                                 void **sched_p,
                                                 enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__INEIGHBOR_ALLGATHERV,
        .comm_ptr = comm_ptr,
        .u.ineighbor_allgatherv.sendbuf = sendbuf,
        .u.ineighbor_allgatherv.sendcount = sendcount,
        .u.ineighbor_allgatherv.sendtype = sendtype,
        .u.ineighbor_allgatherv.recvbuf = recvbuf,
        .u.ineighbor_allgatherv.recvcounts = recvcounts,
        .u.ineighbor_allgatherv.displs = displs,
        .u.ineighbor_allgatherv.recvtype = recvtype,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ineighbor_allgatherv_allcomm_sched_linear:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ineighbor_allgatherv_intra_sched_linear_call_counter,
                                    1);
            mpi_errno = MPIR_Ineighbor_allgatherv_allcomm_sched_linear(sendbuf, sendcount, sendtype,
                                recvbuf, recvcounts, displs, recvtype, comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ineighbor_allgatherv_allcomm_tsp_linear:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ineighbor_allgatherv_intra_tsp_linear_call_counter,
                                    1);
            mpi_errno = MPIR_TSP_Ineighbor_allgatherv_sched_allcomm_linear(sendbuf, sendcount,
                                sendtype, recvbuf, recvcounts, displs, recvtype, comm_ptr,
                                *sched_p);
            break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ineighbor_allgatherv_sched_impl(const void *sendbuf, MPI_Aint sendcount,
                                         MPI_Datatype sendtype, void *recvbuf,
                                         const MPI_Aint recvcounts[], const MPI_Aint displs[],
                                         MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                                         bool is_persistent, void **sched_p,
                                         enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_INEIGHBOR_ALLGATHERV_INTRA_ALGORITHM) {
            case MPIR_CVAR_INEIGHBOR_ALLGATHERV_INTRA_ALGORITHM_sched_linear:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ineighbor_allgatherv_intra_sched_linear_call_counter,
                                        1);
                mpi_errno = MPIR_Ineighbor_allgatherv_allcomm_sched_linear(sendbuf, sendcount, sendtype,
                                    recvbuf, recvcounts, displs, recvtype, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_INEIGHBOR_ALLGATHERV_INTRA_ALGORITHM_tsp_linear:
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ineighbor_allgatherv_intra_tsp_linear_call_counter,
                                        1);
                mpi_errno = MPIR_TSP_Ineighbor_allgatherv_sched_allcomm_linear(sendbuf, sendcount,
                                    sendtype, recvbuf, recvcounts, displs, recvtype, comm_ptr,
                                    *sched_p);
                break;
            case MPIR_CVAR_INEIGHBOR_ALLGATHERV_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Ineighbor_allgatherv_allcomm_sched_auto(sendbuf, sendcount,
                                sendtype, recvbuf, recvcounts, displs, recvtype, comm_ptr,
                                is_persistent, sched_p, sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        MPIR_Assert_error("Only intra-communicator allowed");
    }
    MPIR_ERR_CHECK(mpi_errno);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ineighbor_allgatherv_impl(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                                   void *recvbuf, const MPI_Aint recvcounts[],
                                   const MPI_Aint displs[], MPI_Datatype recvtype,
                                   MPIR_Comm * comm_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    enum MPIR_sched_type sched_type;
    void *sched;
    
    *request = NULL;
    mpi_errno = MPIR_Ineighbor_allgatherv_sched_impl(sendbuf, sendcount, sendtype, recvbuf,
                                                     recvcounts, displs, recvtype, comm_ptr, false,
                                                     &sched, &sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    MPII_SCHED_START(sched_type, sched, comm_ptr, request);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ineighbor_allgatherv(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                              void *recvbuf, const MPI_Aint recvcounts[], const MPI_Aint displs[],
                              MPI_Datatype recvtype, MPIR_Comm * comm_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_ineighbor_allgatherv_call_counter, mvp_ineighbor_allgatherv_timer);
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_INEIGHBOR_ALLGATHERV_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Ineighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts,
                                              displs, recvtype, comm_ptr, request);
    } else {
        mpi_errno = MPIR_Ineighbor_allgatherv_impl(sendbuf, sendcount, sendtype, recvbuf,
                                                   recvcounts, displs, recvtype, comm_ptr,
                                                   request);
    }
    
    MVP_COLL_PVAR_UPDATE_END(mvp_ineighbor_allgatherv_timer);
    
    return mpi_errno;
}

int MPIR_Neighbor_allgatherv_init_impl(const void *sendbuf, MPI_Aint sendcount,
                                       MPI_Datatype sendtype, void *recvbuf,
                                       const MPI_Aint recvcounts[], const MPI_Aint displs[],
                                       MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                                       MPIR_Info * info_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Request *req = MPIR_Request_create(MPIR_REQUEST_KIND__PREQUEST_COLL);
    MPIR_ERR_CHKANDJUMP(!req, mpi_errno, MPI_ERR_OTHER, "**nomem");
    MPIR_Comm_add_ref(comm_ptr);
    req->comm = comm_ptr;
    MPIR_Comm_save_inactive_request(comm_ptr, req);
    req->u.persist_coll.sched_type = MPIR_SCHED_INVALID;
    req->u.persist_coll.real_request = NULL;
    mpi_errno = MPIR_Ineighbor_allgatherv_sched_impl(sendbuf, sendcount, sendtype, recvbuf,
                                                     recvcounts, displs, recvtype, comm_ptr, true,
                                                     &req->u.persist_coll.sched,
                                                     &req->u.persist_coll.sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    
    *request = req;
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Neighbor_allgatherv_init(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                                  void *recvbuf, const MPI_Aint recvcounts[],
                                  const MPI_Aint displs[], MPI_Datatype recvtype,
                                  MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                                  MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_NEIGHBOR_ALLGATHERV_INIT_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Neighbor_allgatherv_init(sendbuf, sendcount, sendtype, recvbuf, recvcounts,
                                                  displs, recvtype, comm_ptr, info_ptr, request);
    } else {
        mpi_errno = MPIR_Neighbor_allgatherv_init_impl(sendbuf, sendcount, sendtype, recvbuf,
                                                       recvcounts, displs, recvtype, comm_ptr,
                                                       info_ptr, request);
    }
    
    return mpi_errno;
}

/* ---- neighbor_alltoall ---- */

int MPIR_Neighbor_alltoall_allcomm_auto(const void *sendbuf, MPI_Aint sendcount,
                                        MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount,
                                        MPI_Datatype recvtype, MPIR_Comm * comm_ptr)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__NEIGHBOR_ALLTOALL,
        .comm_ptr = comm_ptr,
        .u.neighbor_alltoall.sendbuf = sendbuf,
        .u.neighbor_alltoall.sendcount = sendcount,
        .u.neighbor_alltoall.sendtype = sendtype,
        .u.neighbor_alltoall.recvbuf = recvbuf,
        .u.neighbor_alltoall.recvcount = recvcount,
        .u.neighbor_alltoall.recvtype = recvtype,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Neighbor_alltoall_allcomm_nb:
           mpi_errno = MPIR_Neighbor_alltoall_allcomm_nb(sendbuf, sendcount, sendtype, recvbuf,
                                                         recvcount, recvtype, comm_ptr);
           break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Neighbor_alltoall_impl(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                                void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                                MPIR_Comm * comm_ptr)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_NEIGHBOR_ALLTOALL_INTRA_ALGORITHM) {
            case MPIR_CVAR_NEIGHBOR_ALLTOALL_INTRA_ALGORITHM_nb:
                mpi_errno = MPIR_Neighbor_alltoall_allcomm_nb(sendbuf, sendcount, sendtype, recvbuf,
                                recvcount, recvtype, comm_ptr);
                 break;
            case MPIR_CVAR_NEIGHBOR_ALLTOALL_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Neighbor_alltoall_allcomm_auto(sendbuf, sendcount, sendtype,
                                recvbuf, recvcount, recvtype, comm_ptr);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        MPIR_Assert_error("Only intra-communicator allowed");
    }
    MPIR_ERR_CHECK(mpi_errno);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Neighbor_alltoall(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                           void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                           MPIR_Comm * comm_ptr)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_neighbor_alltoall_call_counter, mvp_neighbor_alltoall_timer);
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_NEIGHBOR_ALLTOALL_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Neighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                           recvtype, comm_ptr);
    } else {
        mpi_errno = MPIR_Neighbor_alltoall_impl(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                                recvtype, comm_ptr);
    }
    
    MVP_COLL_PVAR_UPDATE_END(mvp_neighbor_alltoall_timer);
    
    return mpi_errno;
}

/* ---- ineighbor_alltoall ---- */

int MPIR_Ineighbor_alltoall_allcomm_sched_auto(const void *sendbuf, MPI_Aint sendcount,
                                               MPI_Datatype sendtype, void *recvbuf,
                                               MPI_Aint recvcount, MPI_Datatype recvtype,
                                               MPIR_Comm * comm_ptr, bool is_persistent,
                                               void **sched_p, enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__INEIGHBOR_ALLTOALL,
        .comm_ptr = comm_ptr,
        .u.ineighbor_alltoall.sendbuf = sendbuf,
        .u.ineighbor_alltoall.sendcount = sendcount,
        .u.ineighbor_alltoall.sendtype = sendtype,
        .u.ineighbor_alltoall.recvbuf = recvbuf,
        .u.ineighbor_alltoall.recvcount = recvcount,
        .u.ineighbor_alltoall.recvtype = recvtype,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ineighbor_alltoall_allcomm_sched_linear:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ineighbor_alltoall_intra_sched_linear_call_counter,
                                    1);
            mpi_errno = MPIR_Ineighbor_alltoall_allcomm_sched_linear(sendbuf, sendcount, sendtype,
                                recvbuf, recvcount, recvtype, comm_ptr, *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ineighbor_alltoall_allcomm_tsp_linear:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ineighbor_alltoall_intra_tsp_linear_call_counter, 1);
            mpi_errno = MPIR_TSP_Ineighbor_alltoall_sched_allcomm_linear(sendbuf, sendcount,
                                sendtype, recvbuf, recvcount, recvtype, comm_ptr, *sched_p);
            break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ineighbor_alltoall_sched_impl(const void *sendbuf, MPI_Aint sendcount,
                                       MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount,
                                       MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                                       bool is_persistent, void **sched_p,
                                       enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_INEIGHBOR_ALLTOALL_INTRA_ALGORITHM) {
            case MPIR_CVAR_INEIGHBOR_ALLTOALL_INTRA_ALGORITHM_sched_linear:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ineighbor_alltoall_intra_sched_linear_call_counter,
                                        1);
                mpi_errno = MPIR_Ineighbor_alltoall_allcomm_sched_linear(sendbuf, sendcount, sendtype,
                                    recvbuf, recvcount, recvtype, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_INEIGHBOR_ALLTOALL_INTRA_ALGORITHM_tsp_linear:
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ineighbor_alltoall_intra_tsp_linear_call_counter, 1);
                mpi_errno = MPIR_TSP_Ineighbor_alltoall_sched_allcomm_linear(sendbuf, sendcount,
                                    sendtype, recvbuf, recvcount, recvtype, comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_INEIGHBOR_ALLTOALL_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Ineighbor_alltoall_allcomm_sched_auto(sendbuf, sendcount, sendtype,
                                recvbuf, recvcount, recvtype, comm_ptr, is_persistent, sched_p,
                                sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        MPIR_Assert_error("Only intra-communicator allowed");
    }
    MPIR_ERR_CHECK(mpi_errno);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ineighbor_alltoall_impl(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                                 void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                                 MPIR_Comm * comm_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    enum MPIR_sched_type sched_type;
    void *sched;
    
    *request = NULL;
    mpi_errno = MPIR_Ineighbor_alltoall_sched_impl(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                                   recvtype, comm_ptr, false, &sched, &sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    MPII_SCHED_START(sched_type, sched, comm_ptr, request);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ineighbor_alltoall(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                            void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                            MPIR_Comm * comm_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_ineighbor_alltoall_call_counter, mvp_ineighbor_alltoall_timer);
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_INEIGHBOR_ALLTOALL_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Ineighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                            recvtype, comm_ptr, request);
    } else {
        mpi_errno = MPIR_Ineighbor_alltoall_impl(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                                 recvtype, comm_ptr, request);
    }
    
    MVP_COLL_PVAR_UPDATE_END(mvp_ineighbor_alltoall_timer);
    
    return mpi_errno;
}

int MPIR_Neighbor_alltoall_init_impl(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                                     void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                                     MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                                     MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Request *req = MPIR_Request_create(MPIR_REQUEST_KIND__PREQUEST_COLL);
    MPIR_ERR_CHKANDJUMP(!req, mpi_errno, MPI_ERR_OTHER, "**nomem");
    MPIR_Comm_add_ref(comm_ptr);
    req->comm = comm_ptr;
    MPIR_Comm_save_inactive_request(comm_ptr, req);
    req->u.persist_coll.sched_type = MPIR_SCHED_INVALID;
    req->u.persist_coll.real_request = NULL;
    mpi_errno = MPIR_Ineighbor_alltoall_sched_impl(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                                   recvtype, comm_ptr, true,
                                                   &req->u.persist_coll.sched,
                                                   &req->u.persist_coll.sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    
    *request = req;
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Neighbor_alltoall_init(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                                void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                                MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                                MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_NEIGHBOR_ALLTOALL_INIT_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Neighbor_alltoall_init(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                                                recvtype, comm_ptr, info_ptr, request);
    } else {
        mpi_errno = MPIR_Neighbor_alltoall_init_impl(sendbuf, sendcount, sendtype, recvbuf,
                                                     recvcount, recvtype, comm_ptr, info_ptr,
                                                     request);
    }
    
    return mpi_errno;
}

/* ---- neighbor_alltoallv ---- */

int MPIR_Neighbor_alltoallv_allcomm_auto(const void *sendbuf, const MPI_Aint sendcounts[],
                                         const MPI_Aint sdispls[], MPI_Datatype sendtype,
                                         void *recvbuf, const MPI_Aint recvcounts[],
                                         const MPI_Aint rdispls[], MPI_Datatype recvtype,
                                         MPIR_Comm * comm_ptr)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__NEIGHBOR_ALLTOALLV,
        .comm_ptr = comm_ptr,
        .u.neighbor_alltoallv.sendbuf = sendbuf,
        .u.neighbor_alltoallv.sendcounts = sendcounts,
        .u.neighbor_alltoallv.sdispls = sdispls,
        .u.neighbor_alltoallv.sendtype = sendtype,
        .u.neighbor_alltoallv.recvbuf = recvbuf,
        .u.neighbor_alltoallv.recvcounts = recvcounts,
        .u.neighbor_alltoallv.rdispls = rdispls,
        .u.neighbor_alltoallv.recvtype = recvtype,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Neighbor_alltoallv_allcomm_nb:
           mpi_errno = MPIR_Neighbor_alltoallv_allcomm_nb(sendbuf, sendcounts, sdispls, sendtype,
                                                          recvbuf, recvcounts, rdispls, recvtype,
                                                          comm_ptr);
           break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Neighbor_alltoallv_impl(const void *sendbuf, const MPI_Aint sendcounts[],
                                 const MPI_Aint sdispls[], MPI_Datatype sendtype, void *recvbuf,
                                 const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                                 MPI_Datatype recvtype, MPIR_Comm * comm_ptr)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_NEIGHBOR_ALLTOALLV_INTRA_ALGORITHM) {
            case MPIR_CVAR_NEIGHBOR_ALLTOALLV_INTRA_ALGORITHM_nb:
                mpi_errno = MPIR_Neighbor_alltoallv_allcomm_nb(sendbuf, sendcounts, sdispls,
                                sendtype, recvbuf, recvcounts, rdispls, recvtype, comm_ptr);
                 break;
            case MPIR_CVAR_NEIGHBOR_ALLTOALLV_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Neighbor_alltoallv_allcomm_auto(sendbuf, sendcounts, sdispls,
                                sendtype, recvbuf, recvcounts, rdispls, recvtype, comm_ptr);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        MPIR_Assert_error("Only intra-communicator allowed");
    }
    MPIR_ERR_CHECK(mpi_errno);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Neighbor_alltoallv(const void *sendbuf, const MPI_Aint sendcounts[],
                            const MPI_Aint sdispls[], MPI_Datatype sendtype, void *recvbuf,
                            const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                            MPI_Datatype recvtype, MPIR_Comm * comm_ptr)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_neighbor_alltoallv_call_counter, mvp_neighbor_alltoallv_timer);
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_NEIGHBOR_ALLTOALLV_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Neighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf,
                                            recvcounts, rdispls, recvtype, comm_ptr);
    } else {
        mpi_errno = MPIR_Neighbor_alltoallv_impl(sendbuf, sendcounts, sdispls, sendtype, recvbuf,
                                                 recvcounts, rdispls, recvtype, comm_ptr);
    }
    
    MVP_COLL_PVAR_UPDATE_END(mvp_neighbor_alltoallv_timer);
    
    return mpi_errno;
}

/* ---- ineighbor_alltoallv ---- */

int MPIR_Ineighbor_alltoallv_allcomm_sched_auto(const void *sendbuf, const MPI_Aint sendcounts[],
                                                const MPI_Aint sdispls[], MPI_Datatype sendtype,
                                                void *recvbuf, const MPI_Aint recvcounts[],
                                                const MPI_Aint rdispls[], MPI_Datatype recvtype,
                                                MPIR_Comm * comm_ptr, bool is_persistent,
                                                void **sched_p, enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__INEIGHBOR_ALLTOALLV,
        .comm_ptr = comm_ptr,
        .u.ineighbor_alltoallv.sendbuf = sendbuf,
        .u.ineighbor_alltoallv.sendcounts = sendcounts,
        .u.ineighbor_alltoallv.sdispls = sdispls,
        .u.ineighbor_alltoallv.sendtype = sendtype,
        .u.ineighbor_alltoallv.recvbuf = recvbuf,
        .u.ineighbor_alltoallv.recvcounts = recvcounts,
        .u.ineighbor_alltoallv.rdispls = rdispls,
        .u.ineighbor_alltoallv.recvtype = recvtype,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ineighbor_alltoallv_allcomm_sched_linear:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ineighbor_alltoallv_intra_sched_linear_call_counter,
                                    1);
            mpi_errno = MPIR_Ineighbor_alltoallv_allcomm_sched_linear(sendbuf, sendcounts, sdispls,
                                sendtype, recvbuf, recvcounts, rdispls, recvtype, comm_ptr,
                                *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ineighbor_alltoallv_allcomm_tsp_linear:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ineighbor_alltoallv_intra_tsp_linear_call_counter, 1);
            mpi_errno = MPIR_TSP_Ineighbor_alltoallv_sched_allcomm_linear(sendbuf, sendcounts,
                                sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm_ptr,
                                *sched_p);
            break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ineighbor_alltoallv_sched_impl(const void *sendbuf, const MPI_Aint sendcounts[],
                                        const MPI_Aint sdispls[], MPI_Datatype sendtype,
                                        void *recvbuf, const MPI_Aint recvcounts[],
                                        const MPI_Aint rdispls[], MPI_Datatype recvtype,
                                        MPIR_Comm * comm_ptr, bool is_persistent, void **sched_p,
                                        enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_INEIGHBOR_ALLTOALLV_INTRA_ALGORITHM) {
            case MPIR_CVAR_INEIGHBOR_ALLTOALLV_INTRA_ALGORITHM_sched_linear:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ineighbor_alltoallv_intra_sched_linear_call_counter,
                                        1);
                mpi_errno = MPIR_Ineighbor_alltoallv_allcomm_sched_linear(sendbuf, sendcounts, sdispls,
                                    sendtype, recvbuf, recvcounts, rdispls, recvtype, comm_ptr,
                                    *sched_p);
                break;
            case MPIR_CVAR_INEIGHBOR_ALLTOALLV_INTRA_ALGORITHM_tsp_linear:
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ineighbor_alltoallv_intra_tsp_linear_call_counter, 1);
                mpi_errno = MPIR_TSP_Ineighbor_alltoallv_sched_allcomm_linear(sendbuf, sendcounts,
                                    sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm_ptr,
                                    *sched_p);
                break;
            case MPIR_CVAR_INEIGHBOR_ALLTOALLV_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Ineighbor_alltoallv_allcomm_sched_auto(sendbuf, sendcounts,
                                sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm_ptr,
                                is_persistent, sched_p, sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        MPIR_Assert_error("Only intra-communicator allowed");
    }
    MPIR_ERR_CHECK(mpi_errno);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ineighbor_alltoallv_impl(const void *sendbuf, const MPI_Aint sendcounts[],
                                  const MPI_Aint sdispls[], MPI_Datatype sendtype, void *recvbuf,
                                  const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                                  MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                                  MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    enum MPIR_sched_type sched_type;
    void *sched;
    
    *request = NULL;
    mpi_errno = MPIR_Ineighbor_alltoallv_sched_impl(sendbuf, sendcounts, sdispls, sendtype, recvbuf,
                                                    recvcounts, rdispls, recvtype, comm_ptr, false,
                                                    &sched, &sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    MPII_SCHED_START(sched_type, sched, comm_ptr, request);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ineighbor_alltoallv(const void *sendbuf, const MPI_Aint sendcounts[],
                             const MPI_Aint sdispls[], MPI_Datatype sendtype, void *recvbuf,
                             const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                             MPI_Datatype recvtype, MPIR_Comm * comm_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_ineighbor_alltoallv_call_counter, mvp_ineighbor_alltoallv_timer);
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_INEIGHBOR_ALLTOALLV_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Ineighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf,
                                             recvcounts, rdispls, recvtype, comm_ptr, request);
    } else {
        mpi_errno = MPIR_Ineighbor_alltoallv_impl(sendbuf, sendcounts, sdispls, sendtype, recvbuf,
                                                  recvcounts, rdispls, recvtype, comm_ptr,
                                                  request);
    }
    
    MVP_COLL_PVAR_UPDATE_END(mvp_ineighbor_alltoallv_timer);
    
    return mpi_errno;
}

int MPIR_Neighbor_alltoallv_init_impl(const void *sendbuf, const MPI_Aint sendcounts[],
                                      const MPI_Aint sdispls[], MPI_Datatype sendtype,
                                      void *recvbuf, const MPI_Aint recvcounts[],
                                      const MPI_Aint rdispls[], MPI_Datatype recvtype,
                                      MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                                      MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Request *req = MPIR_Request_create(MPIR_REQUEST_KIND__PREQUEST_COLL);
    MPIR_ERR_CHKANDJUMP(!req, mpi_errno, MPI_ERR_OTHER, "**nomem");
    MPIR_Comm_add_ref(comm_ptr);
    req->comm = comm_ptr;
    MPIR_Comm_save_inactive_request(comm_ptr, req);
    req->u.persist_coll.sched_type = MPIR_SCHED_INVALID;
    req->u.persist_coll.real_request = NULL;
    mpi_errno = MPIR_Ineighbor_alltoallv_sched_impl(sendbuf, sendcounts, sdispls, sendtype, recvbuf,
                                                    recvcounts, rdispls, recvtype, comm_ptr, true,
                                                    &req->u.persist_coll.sched,
                                                    &req->u.persist_coll.sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    
    *request = req;
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Neighbor_alltoallv_init(const void *sendbuf, const MPI_Aint sendcounts[],
                                 const MPI_Aint sdispls[], MPI_Datatype sendtype, void *recvbuf,
                                 const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                                 MPI_Datatype recvtype, MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                                 MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_NEIGHBOR_ALLTOALLV_INIT_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Neighbor_alltoallv_init(sendbuf, sendcounts, sdispls, sendtype, recvbuf,
                                                 recvcounts, rdispls, recvtype, comm_ptr, info_ptr,
                                                 request);
    } else {
        mpi_errno = MPIR_Neighbor_alltoallv_init_impl(sendbuf, sendcounts, sdispls, sendtype,
                                                      recvbuf, recvcounts, rdispls, recvtype,
                                                      comm_ptr, info_ptr, request);
    }
    
    return mpi_errno;
}

/* ---- neighbor_alltoallw ---- */

int MPIR_Neighbor_alltoallw_allcomm_auto(const void *sendbuf, const MPI_Aint sendcounts[],
                                         const MPI_Aint sdispls[], const MPI_Datatype sendtypes[],
                                         void *recvbuf, const MPI_Aint recvcounts[],
                                         const MPI_Aint rdispls[], const MPI_Datatype recvtypes[],
                                         MPIR_Comm * comm_ptr)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__NEIGHBOR_ALLTOALLW,
        .comm_ptr = comm_ptr,
        .u.neighbor_alltoallw.sendbuf = sendbuf,
        .u.neighbor_alltoallw.sendcounts = sendcounts,
        .u.neighbor_alltoallw.sdispls = sdispls,
        .u.neighbor_alltoallw.sendtypes = sendtypes,
        .u.neighbor_alltoallw.recvbuf = recvbuf,
        .u.neighbor_alltoallw.recvcounts = recvcounts,
        .u.neighbor_alltoallw.rdispls = rdispls,
        .u.neighbor_alltoallw.recvtypes = recvtypes,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Neighbor_alltoallw_allcomm_nb:
           mpi_errno = MPIR_Neighbor_alltoallw_allcomm_nb(sendbuf, sendcounts, sdispls, sendtypes,
                                                          recvbuf, recvcounts, rdispls, recvtypes,
                                                          comm_ptr);
           break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Neighbor_alltoallw_impl(const void *sendbuf, const MPI_Aint sendcounts[],
                                 const MPI_Aint sdispls[], const MPI_Datatype sendtypes[],
                                 void *recvbuf, const MPI_Aint recvcounts[],
                                 const MPI_Aint rdispls[], const MPI_Datatype recvtypes[],
                                 MPIR_Comm * comm_ptr)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_NEIGHBOR_ALLTOALLW_INTRA_ALGORITHM) {
            case MPIR_CVAR_NEIGHBOR_ALLTOALLW_INTRA_ALGORITHM_nb:
                mpi_errno = MPIR_Neighbor_alltoallw_allcomm_nb(sendbuf, sendcounts, sdispls,
                                sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm_ptr);
                 break;
            case MPIR_CVAR_NEIGHBOR_ALLTOALLW_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Neighbor_alltoallw_allcomm_auto(sendbuf, sendcounts, sdispls,
                                sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm_ptr);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        MPIR_Assert_error("Only intra-communicator allowed");
    }
    MPIR_ERR_CHECK(mpi_errno);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Neighbor_alltoallw(const void *sendbuf, const MPI_Aint sendcounts[],
                            const MPI_Aint sdispls[], const MPI_Datatype sendtypes[], void *recvbuf,
                            const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                            const MPI_Datatype recvtypes[], MPIR_Comm * comm_ptr)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_neighbor_alltoallw_call_counter, mvp_neighbor_alltoallw_timer);
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_NEIGHBOR_ALLTOALLW_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Neighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf,
                                            recvcounts, rdispls, recvtypes, comm_ptr);
    } else {
        mpi_errno = MPIR_Neighbor_alltoallw_impl(sendbuf, sendcounts, sdispls, sendtypes, recvbuf,
                                                 recvcounts, rdispls, recvtypes, comm_ptr);
    }
    
    MVP_COLL_PVAR_UPDATE_END(mvp_neighbor_alltoallw_timer);
    
    return mpi_errno;
}

/* ---- ineighbor_alltoallw ---- */

int MPIR_Ineighbor_alltoallw_allcomm_sched_auto(const void *sendbuf, const MPI_Aint sendcounts[],
                                                const MPI_Aint sdispls[],
                                                const MPI_Datatype sendtypes[], void *recvbuf,
                                                const MPI_Aint recvcounts[],
                                                const MPI_Aint rdispls[],
                                                const MPI_Datatype recvtypes[],
                                                MPIR_Comm * comm_ptr, bool is_persistent,
                                                void **sched_p, enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__INEIGHBOR_ALLTOALLW,
        .comm_ptr = comm_ptr,
        .u.ineighbor_alltoallw.sendbuf = sendbuf,
        .u.ineighbor_alltoallw.sendcounts = sendcounts,
        .u.ineighbor_alltoallw.sdispls = sdispls,
        .u.ineighbor_alltoallw.sendtypes = sendtypes,
        .u.ineighbor_alltoallw.recvbuf = recvbuf,
        .u.ineighbor_alltoallw.recvcounts = recvcounts,
        .u.ineighbor_alltoallw.rdispls = rdispls,
        .u.ineighbor_alltoallw.recvtypes = recvtypes,
    };
    
    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);
    
    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ineighbor_alltoallw_allcomm_sched_linear:
            MPII_SCHED_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ineighbor_alltoallw_intra_sched_linear_call_counter,
                                    1);
            mpi_errno = MPIR_Ineighbor_alltoallw_allcomm_sched_linear(sendbuf, sendcounts, sdispls,
                                sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm_ptr,
                                *sched_p);
            break;
        
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ineighbor_alltoallw_allcomm_tsp_linear:
            MPII_GENTRAN_CREATE_SCHED_P();
            MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ineighbor_alltoallw_intra_tsp_linear_call_counter, 1);
            mpi_errno = MPIR_TSP_Ineighbor_alltoallw_sched_allcomm_linear(sendbuf, sendcounts,
                                sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes,
                                comm_ptr, *sched_p);
            break;
        
        default:
            MPIR_Assert(0);
    }
    MPIR_ERR_CHECK(mpi_errno);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ineighbor_alltoallw_sched_impl(const void *sendbuf, const MPI_Aint sendcounts[],
                                        const MPI_Aint sdispls[], const MPI_Datatype sendtypes[],
                                        void *recvbuf, const MPI_Aint recvcounts[],
                                        const MPI_Aint rdispls[], const MPI_Datatype recvtypes[],
                                        MPIR_Comm * comm_ptr, bool is_persistent, void **sched_p,
                                        enum MPIR_sched_type *sched_type_p)
{
    int mpi_errno = MPI_SUCCESS;
    
    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_INEIGHBOR_ALLTOALLW_INTRA_ALGORITHM) {
            case MPIR_CVAR_INEIGHBOR_ALLTOALLW_INTRA_ALGORITHM_sched_linear:
                MPII_SCHED_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ineighbor_alltoallw_intra_sched_linear_call_counter,
                                        1);
                mpi_errno = MPIR_Ineighbor_alltoallw_allcomm_sched_linear(sendbuf, sendcounts, sdispls,
                                    sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm_ptr,
                                    *sched_p);
                break;
            case MPIR_CVAR_INEIGHBOR_ALLTOALLW_INTRA_ALGORITHM_tsp_linear:
                MPII_GENTRAN_CREATE_SCHED_P();
                MPIR_T_PVAR_COUNTER_INC(MVP, mvp_ineighbor_alltoallw_intra_tsp_linear_call_counter, 1);
                mpi_errno = MPIR_TSP_Ineighbor_alltoallw_sched_allcomm_linear(sendbuf, sendcounts,
                                    sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes,
                                    comm_ptr, *sched_p);
                break;
            case MPIR_CVAR_INEIGHBOR_ALLTOALLW_INTRA_ALGORITHM_auto:
                mpi_errno = MPIR_Ineighbor_alltoallw_allcomm_sched_auto(sendbuf, sendcounts,
                                sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes,
                                comm_ptr, is_persistent, sched_p, sched_type_p);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        MPIR_Assert_error("Only intra-communicator allowed");
    }
    MPIR_ERR_CHECK(mpi_errno);
    
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ineighbor_alltoallw_impl(const void *sendbuf, const MPI_Aint sendcounts[],
                                  const MPI_Aint sdispls[], const MPI_Datatype sendtypes[],
                                  void *recvbuf, const MPI_Aint recvcounts[],
                                  const MPI_Aint rdispls[], const MPI_Datatype recvtypes[],
                                  MPIR_Comm * comm_ptr, MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    enum MPIR_sched_type sched_type;
    void *sched;
    
    *request = NULL;
    mpi_errno = MPIR_Ineighbor_alltoallw_sched_impl(sendbuf, sendcounts, sdispls, sendtypes,
                                                    recvbuf, recvcounts, rdispls, recvtypes,
                                                    comm_ptr, false, &sched, &sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    MPII_SCHED_START(sched_type, sched, comm_ptr, request);
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Ineighbor_alltoallw(const void *sendbuf, const MPI_Aint sendcounts[],
                             const MPI_Aint sdispls[], const MPI_Datatype sendtypes[],
                             void *recvbuf, const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                             const MPI_Datatype recvtypes[], MPIR_Comm * comm_ptr,
                             MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MVP_COLL_PVAR_UPDATE_START(mvp_ineighbor_alltoallw_call_counter, mvp_ineighbor_alltoallw_timer);
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_INEIGHBOR_ALLTOALLW_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Ineighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf,
                                             recvcounts, rdispls, recvtypes, comm_ptr, request);
    } else {
        mpi_errno = MPIR_Ineighbor_alltoallw_impl(sendbuf, sendcounts, sdispls, sendtypes, recvbuf,
                                                  recvcounts, rdispls, recvtypes, comm_ptr,
                                                  request);
    }
    
    MVP_COLL_PVAR_UPDATE_END(mvp_ineighbor_alltoallw_timer);
    
    return mpi_errno;
}

int MPIR_Neighbor_alltoallw_init_impl(const void *sendbuf, const MPI_Aint sendcounts[],
                                      const MPI_Aint sdispls[], const MPI_Datatype sendtypes[],
                                      void *recvbuf, const MPI_Aint recvcounts[],
                                      const MPI_Aint rdispls[], const MPI_Datatype recvtypes[],
                                      MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                                      MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    MPIR_Request *req = MPIR_Request_create(MPIR_REQUEST_KIND__PREQUEST_COLL);
    MPIR_ERR_CHKANDJUMP(!req, mpi_errno, MPI_ERR_OTHER, "**nomem");
    MPIR_Comm_add_ref(comm_ptr);
    req->comm = comm_ptr;
    MPIR_Comm_save_inactive_request(comm_ptr, req);
    req->u.persist_coll.sched_type = MPIR_SCHED_INVALID;
    req->u.persist_coll.real_request = NULL;
    mpi_errno = MPIR_Ineighbor_alltoallw_sched_impl(sendbuf, sendcounts, sdispls, sendtypes,
                                                    recvbuf, recvcounts, rdispls, recvtypes,
                                                    comm_ptr, true, &req->u.persist_coll.sched,
                                                    &req->u.persist_coll.sched_type);
    MPIR_ERR_CHECK(mpi_errno);
    
    *request = req;
    
  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Neighbor_alltoallw_init(const void *sendbuf, const MPI_Aint sendcounts[],
                                 const MPI_Aint sdispls[], const MPI_Datatype sendtypes[],
                                 void *recvbuf, const MPI_Aint recvcounts[],
                                 const MPI_Aint rdispls[], const MPI_Datatype recvtypes[],
                                 MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                                 MPIR_Request ** request)
{
    int mpi_errno = MPI_SUCCESS;
    
    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_NEIGHBOR_ALLTOALLW_INIT_DEVICE_COLLECTIVE)) {
        mpi_errno = MPID_Neighbor_alltoallw_init(sendbuf, sendcounts, sdispls, sendtypes, recvbuf,
                                                 recvcounts, rdispls, recvtypes, comm_ptr, info_ptr,
                                                 request);
    } else {
        mpi_errno = MPIR_Neighbor_alltoallw_init_impl(sendbuf, sendcounts, sdispls, sendtypes,
                                                      recvbuf, recvcounts, rdispls, recvtypes,
                                                      comm_ptr, info_ptr, request);
    }
    
    return mpi_errno;
}
