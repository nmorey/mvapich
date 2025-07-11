/*
 * Copyright (C) by Network Based Computing Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* Automatically generated
 *   by:   ./maint/extractmvppvars
 *   on:   Thu Mar  6 22:01:57 2025 UTC
 *
 * DO NOT EDIT!!!
 */

#if !defined(MVP_PVARS_H_INCLUDED)
#define MVP_PVARS_H_INCLUDED
#include "mpiimpl.h"
#ifdef ENABLE_PVAR_MVP

#define MVP_COLL_PVAR_UPDATE_START(c, t) \
  do { \
    MPIR_T_PVAR_COUNTER_INC(MVP, c, 1); \
    MPIR_T_PVAR_TIMER_START(MVP, t); \
  } while(0);
#define MVP_COLL_PVAR_UPDATE_END(t) \
  MPIR_T_PVAR_TIMER_END(MVP, t);

#define MVP_MPIC_PVAR_BYTE_COUNTER(arr, tag, count, datatype) \
  do { \
    MPI_Aint pvar_msg_sz; \
    MPIR_Datatype_get_size_macro(datatype, pvar_msg_sz); \
    pvar_msg_sz *= count; \
    if (tag < MPIR_BARRIER_TAG || tag > MPIR_FIRST_NBC_TAG) { \
        MPIR_T_PVAR_COUNTER_ARRAY_INC(MVP, arr, 0, pvar_msg_sz); \
    } else { \
        MPIR_T_PVAR_COUNTER_ARRAY_INC(MVP, arr, tag, pvar_msg_sz); \
    } \
  } while (0);


void MPIR_REGISTER_MVP_VARIABLES(void);
/* Extern declarations for each pvar
 * (definitions in src/util/mvp_pvars.c) */

/* declared in src/mpi_t/mvp_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_mpic_send_byte_counter_array[287];
/* declared in src/mpi_t/mvp_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_mpic_recv_byte_counter_array[287];
/* declared in src/mpi_t/mvp_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_mpic_isend_byte_counter_array[287];
/* declared in src/mpi_t/mvp_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_mpic_irecv_byte_counter_array[287];
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_barrier_intra_k_dissemination_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_barrier_intra_recexch_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_barrier_intra_smp_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_barrier_intra_osu_pairwise_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_barrier_inter_bcast_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ibarrier_intra_sched_recursive_doubling_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ibarrier_intra_tsp_recexch_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ibarrier_intra_tsp_k_dissemination_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ibarrier_inter_sched_bcast_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_bcast_intra_binomial_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_bcast_intra_scatter_recursive_doubling_allgather_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_bcast_intra_scatter_ring_allgather_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_bcast_intra_smp_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_bcast_intra_tree_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_bcast_intra_pipelined_tree_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_bcast_intra_osu_knomial_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_bcast_intra_osu_pipelined_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ibcast_intra_sched_binomial_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ibcast_intra_sched_smp_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ibcast_intra_sched_scatter_recursive_doubling_allgather_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ibcast_intra_sched_scatter_ring_allgather_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ibcast_intra_tsp_tree_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ibcast_intra_tsp_scatterv_recexch_allgatherv_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ibcast_intra_tsp_scatterv_ring_allgatherv_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ibcast_intra_tsp_ring_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_bcast_inter_remote_send_local_bcast_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ibcast_inter_sched_flat_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_gather_intra_binomial_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_gather_intra_osu_direct_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_gather_intra_osu_direct_block_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_gather_inter_linear_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_gather_inter_local_gather_remote_send_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_igather_intra_sched_binomial_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_igather_intra_tsp_tree_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_igather_inter_sched_long_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_igather_inter_sched_short_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_gatherv_intra_linear_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_gatherv_inter_linear_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_igatherv_intra_sched_linear_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_igatherv_intra_tsp_linear_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_igatherv_inter_sched_linear_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_igatherv_inter_tsp_linear_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_scatter_intra_binomial_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_scatter_intra_osu_direct_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_scatter_inter_linear_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_scatter_inter_remote_send_local_scatter_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iscatter_intra_sched_binomial_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iscatter_intra_tsp_tree_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iscatter_inter_sched_linear_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iscatter_inter_sched_remote_send_local_scatter_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_scatterv_intra_linear_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_scatterv_inter_linear_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iscatterv_intra_sched_linear_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iscatterv_intra_tsp_linear_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iscatterv_inter_sched_linear_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iscatterv_inter_tsp_linear_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_allgather_intra_brucks_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_allgather_intra_k_brucks_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_allgather_intra_recursive_doubling_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_allgather_intra_ring_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_allgather_intra_recexch_doubling_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_allgather_intra_recexch_halving_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_allgather_intra_osu_direct_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_allgather_intra_osu_direct_spread_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_allgather_intra_osu_gather_bcast_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_allgather_inter_local_gather_remote_bcast_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iallgather_intra_sched_ring_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iallgather_intra_sched_brucks_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iallgather_intra_sched_recursive_doubling_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iallgather_intra_tsp_ring_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iallgather_intra_tsp_brucks_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iallgather_intra_tsp_recexch_doubling_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iallgather_intra_tsp_recexch_halving_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iallgather_inter_sched_local_gather_remote_bcast_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_allgatherv_intra_brucks_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_allgatherv_intra_recursive_doubling_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_allgatherv_intra_ring_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_allgatherv_inter_remote_gather_local_bcast_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iallgatherv_intra_sched_brucks_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iallgatherv_intra_sched_recursive_doubling_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iallgatherv_intra_sched_ring_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iallgatherv_intra_tsp_recexch_doubling_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iallgatherv_intra_tsp_recexch_halving_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iallgatherv_intra_tsp_ring_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iallgatherv_intra_tsp_brucks_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iallgatherv_inter_sched_remote_gather_local_bcast_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_alltoall_intra_brucks_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_alltoall_intra_k_brucks_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_alltoall_intra_pairwise_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_alltoall_intra_pairwise_sendrecv_replace_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_alltoall_intra_scattered_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_alltoall_inter_pairwise_exchange_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ialltoall_intra_sched_brucks_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ialltoall_intra_sched_inplace_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ialltoall_intra_sched_pairwise_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ialltoall_intra_sched_permuted_sendrecv_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ialltoall_intra_tsp_ring_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ialltoall_intra_tsp_brucks_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ialltoall_intra_tsp_scattered_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ialltoall_inter_sched_pairwise_exchange_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_alltoallv_intra_pairwise_sendrecv_replace_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_alltoallv_intra_scattered_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_alltoallv_inter_pairwise_exchange_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ialltoallv_intra_sched_blocked_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ialltoallv_intra_sched_inplace_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ialltoallv_intra_tsp_scattered_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ialltoallv_intra_tsp_blocked_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ialltoallv_intra_tsp_inplace_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ialltoallv_inter_sched_pairwise_exchange_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_alltoallw_intra_pairwise_sendrecv_replace_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_alltoallw_intra_scattered_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_alltoallw_inter_pairwise_exchange_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ialltoallw_intra_sched_blocked_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ialltoallw_intra_sched_inplace_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ialltoallw_intra_tsp_blocked_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ialltoallw_intra_tsp_inplace_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ialltoallw_inter_sched_pairwise_exchange_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_reduce_intra_binomial_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_reduce_intra_smp_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_reduce_intra_reduce_scatter_gather_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_reduce_intra_osu_knomial_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_reduce_intra_osu_allreduce_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_reduce_inter_local_reduce_remote_send_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ireduce_intra_sched_smp_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ireduce_intra_sched_binomial_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ireduce_intra_sched_reduce_scatter_gather_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ireduce_intra_tsp_tree_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ireduce_intra_tsp_ring_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ireduce_inter_sched_local_reduce_remote_send_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_allreduce_intra_smp_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_allreduce_intra_recursive_doubling_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_allreduce_intra_recursive_multiplying_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_allreduce_intra_reduce_scatter_allgather_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_allreduce_intra_tree_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_allreduce_intra_recexch_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_allreduce_intra_ring_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_allreduce_intra_k_reduce_scatter_allgather_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_allreduce_inter_reduce_exchange_bcast_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iallreduce_intra_sched_naive_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iallreduce_intra_sched_smp_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iallreduce_intra_sched_recursive_doubling_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iallreduce_intra_sched_reduce_scatter_allgather_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iallreduce_intra_tsp_recexch_single_buffer_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iallreduce_intra_tsp_recexch_multiple_buffer_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iallreduce_intra_tsp_tree_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iallreduce_intra_tsp_ring_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iallreduce_intra_tsp_recexch_reduce_scatter_recexch_allgatherv_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iallreduce_inter_sched_remote_reduce_local_bcast_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_reduce_scatter_intra_noncommutative_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_reduce_scatter_intra_pairwise_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_reduce_scatter_intra_recursive_doubling_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_reduce_scatter_intra_recursive_halving_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_reduce_scatter_intra_osu_basic_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_reduce_scatter_intra_osu_ring_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_reduce_scatter_inter_remote_reduce_local_scatter_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ireduce_scatter_intra_sched_noncommutative_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ireduce_scatter_intra_sched_recursive_doubling_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ireduce_scatter_intra_sched_pairwise_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ireduce_scatter_intra_sched_recursive_halving_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ireduce_scatter_intra_tsp_recexch_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ireduce_scatter_inter_sched_remote_reduce_local_scatterv_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_reduce_scatter_block_intra_noncommutative_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_reduce_scatter_block_intra_recursive_doubling_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_reduce_scatter_block_intra_pairwise_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_reduce_scatter_block_intra_recursive_halving_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_reduce_scatter_block_inter_remote_reduce_local_scatter_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ireduce_scatter_block_intra_sched_noncommutative_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ireduce_scatter_block_intra_sched_recursive_doubling_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ireduce_scatter_block_intra_sched_pairwise_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ireduce_scatter_block_intra_sched_recursive_halving_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ireduce_scatter_block_intra_tsp_recexch_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ireduce_scatter_block_inter_sched_remote_reduce_local_scatterv_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_scan_intra_smp_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_scan_intra_recursive_doubling_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iscan_intra_sched_smp_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iscan_intra_sched_recursive_doubling_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iscan_intra_tsp_recursive_doubling_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_exscan_intra_recursive_doubling_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iexscan_intra_sched_recursive_doubling_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ineighbor_allgather_intra_sched_linear_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ineighbor_allgather_intra_tsp_linear_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ineighbor_allgatherv_intra_sched_linear_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ineighbor_allgatherv_intra_tsp_linear_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ineighbor_alltoall_intra_sched_linear_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ineighbor_alltoall_intra_tsp_linear_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ineighbor_alltoallv_intra_sched_linear_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ineighbor_alltoallv_intra_tsp_linear_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ineighbor_alltoallw_intra_sched_linear_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ineighbor_alltoallw_intra_tsp_linear_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_barrier_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_barrier_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ibarrier_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_ibarrier_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_bcast_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_bcast_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ibcast_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_ibcast_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_gather_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_gather_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_igather_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_igather_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_gatherv_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_gatherv_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_igatherv_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_igatherv_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_scatter_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_scatter_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iscatter_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_iscatter_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_scatterv_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_scatterv_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iscatterv_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_iscatterv_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_allgather_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_allgather_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iallgather_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_iallgather_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_allgatherv_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_allgatherv_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iallgatherv_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_iallgatherv_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_alltoall_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_alltoall_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ialltoall_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_ialltoall_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_alltoallv_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_alltoallv_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ialltoallv_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_ialltoallv_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_alltoallw_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_alltoallw_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ialltoallw_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_ialltoallw_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_reduce_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_reduce_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ireduce_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_ireduce_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_allreduce_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_allreduce_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iallreduce_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_iallreduce_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_reduce_scatter_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_reduce_scatter_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ireduce_scatter_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_ireduce_scatter_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_reduce_scatter_block_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_reduce_scatter_block_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ireduce_scatter_block_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_ireduce_scatter_block_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_scan_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_scan_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iscan_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_iscan_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_exscan_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_exscan_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_iexscan_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_iexscan_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_neighbor_allgather_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_neighbor_allgather_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ineighbor_allgather_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_ineighbor_allgather_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_neighbor_allgatherv_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_neighbor_allgatherv_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ineighbor_allgatherv_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_ineighbor_allgatherv_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_neighbor_alltoall_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_neighbor_alltoall_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ineighbor_alltoall_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_ineighbor_alltoall_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_neighbor_alltoallv_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_neighbor_alltoallv_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ineighbor_alltoallv_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_ineighbor_alltoallv_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_neighbor_alltoallw_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_neighbor_alltoallw_timer;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern unsigned long long PVAR_COUNTER_mvp_ineighbor_alltoallw_call_counter;
/* declared in src/mpi_t/mvp_coll_pvars.txt */
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_ineighbor_alltoallw_timer;

#define MVP_PVAR_COUNT 281
#else /* ENABLE_PVAR_MVP */
#define MVP_COLL_PVAR_UPDATE_START(c, t)
#define MVP_COLL_PVAR_UPDATE_END(t)
#define MPIR_REGISTER_MVP_VARIABLES()
#define MVP_PVAR_COUNT 0
#endif /* ENABLE_PVAR_MVP */
#endif /* MVP_PVARS_H_INCLUDED */
