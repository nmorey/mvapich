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
#include "mpiimpl.h"
#ifdef ENABLE_PVAR_MVP
unsigned long long PVAR_COUNTER_mvp_mpic_send_byte_counter_array[287];
unsigned long long PVAR_COUNTER_mvp_mpic_recv_byte_counter_array[287];
unsigned long long PVAR_COUNTER_mvp_mpic_isend_byte_counter_array[287];
unsigned long long PVAR_COUNTER_mvp_mpic_irecv_byte_counter_array[287];
unsigned long long PVAR_COUNTER_mvp_barrier_intra_k_dissemination_call_counter;
unsigned long long PVAR_COUNTER_mvp_barrier_intra_recexch_call_counter;
unsigned long long PVAR_COUNTER_mvp_barrier_intra_smp_call_counter;
unsigned long long PVAR_COUNTER_mvp_barrier_intra_osu_pairwise_call_counter;
unsigned long long PVAR_COUNTER_mvp_barrier_inter_bcast_call_counter;
unsigned long long PVAR_COUNTER_mvp_ibarrier_intra_sched_recursive_doubling_call_counter;
unsigned long long PVAR_COUNTER_mvp_ibarrier_intra_tsp_recexch_call_counter;
unsigned long long PVAR_COUNTER_mvp_ibarrier_intra_tsp_k_dissemination_call_counter;
unsigned long long PVAR_COUNTER_mvp_ibarrier_inter_sched_bcast_call_counter;
unsigned long long PVAR_COUNTER_mvp_bcast_intra_binomial_call_counter;
unsigned long long PVAR_COUNTER_mvp_bcast_intra_scatter_recursive_doubling_allgather_call_counter;
unsigned long long PVAR_COUNTER_mvp_bcast_intra_scatter_ring_allgather_call_counter;
unsigned long long PVAR_COUNTER_mvp_bcast_intra_smp_call_counter;
unsigned long long PVAR_COUNTER_mvp_bcast_intra_tree_call_counter;
unsigned long long PVAR_COUNTER_mvp_bcast_intra_pipelined_tree_call_counter;
unsigned long long PVAR_COUNTER_mvp_bcast_intra_osu_knomial_call_counter;
unsigned long long PVAR_COUNTER_mvp_bcast_intra_osu_pipelined_call_counter;
unsigned long long PVAR_COUNTER_mvp_ibcast_intra_sched_binomial_call_counter;
unsigned long long PVAR_COUNTER_mvp_ibcast_intra_sched_smp_call_counter;
unsigned long long PVAR_COUNTER_mvp_ibcast_intra_sched_scatter_recursive_doubling_allgather_call_counter;
unsigned long long PVAR_COUNTER_mvp_ibcast_intra_sched_scatter_ring_allgather_call_counter;
unsigned long long PVAR_COUNTER_mvp_ibcast_intra_tsp_tree_call_counter;
unsigned long long PVAR_COUNTER_mvp_ibcast_intra_tsp_scatterv_recexch_allgatherv_call_counter;
unsigned long long PVAR_COUNTER_mvp_ibcast_intra_tsp_scatterv_ring_allgatherv_call_counter;
unsigned long long PVAR_COUNTER_mvp_ibcast_intra_tsp_ring_call_counter;
unsigned long long PVAR_COUNTER_mvp_bcast_inter_remote_send_local_bcast_call_counter;
unsigned long long PVAR_COUNTER_mvp_ibcast_inter_sched_flat_call_counter;
unsigned long long PVAR_COUNTER_mvp_gather_intra_binomial_call_counter;
unsigned long long PVAR_COUNTER_mvp_gather_intra_osu_direct_call_counter;
unsigned long long PVAR_COUNTER_mvp_gather_intra_osu_direct_block_call_counter;
unsigned long long PVAR_COUNTER_mvp_gather_inter_linear_call_counter;
unsigned long long PVAR_COUNTER_mvp_gather_inter_local_gather_remote_send_call_counter;
unsigned long long PVAR_COUNTER_mvp_igather_intra_sched_binomial_call_counter;
unsigned long long PVAR_COUNTER_mvp_igather_intra_tsp_tree_call_counter;
unsigned long long PVAR_COUNTER_mvp_igather_inter_sched_long_call_counter;
unsigned long long PVAR_COUNTER_mvp_igather_inter_sched_short_call_counter;
unsigned long long PVAR_COUNTER_mvp_gatherv_intra_linear_call_counter;
unsigned long long PVAR_COUNTER_mvp_gatherv_inter_linear_call_counter;
unsigned long long PVAR_COUNTER_mvp_igatherv_intra_sched_linear_call_counter;
unsigned long long PVAR_COUNTER_mvp_igatherv_intra_tsp_linear_call_counter;
unsigned long long PVAR_COUNTER_mvp_igatherv_inter_sched_linear_call_counter;
unsigned long long PVAR_COUNTER_mvp_igatherv_inter_tsp_linear_call_counter;
unsigned long long PVAR_COUNTER_mvp_scatter_intra_binomial_call_counter;
unsigned long long PVAR_COUNTER_mvp_scatter_intra_osu_direct_call_counter;
unsigned long long PVAR_COUNTER_mvp_scatter_inter_linear_call_counter;
unsigned long long PVAR_COUNTER_mvp_scatter_inter_remote_send_local_scatter_call_counter;
unsigned long long PVAR_COUNTER_mvp_iscatter_intra_sched_binomial_call_counter;
unsigned long long PVAR_COUNTER_mvp_iscatter_intra_tsp_tree_call_counter;
unsigned long long PVAR_COUNTER_mvp_iscatter_inter_sched_linear_call_counter;
unsigned long long PVAR_COUNTER_mvp_iscatter_inter_sched_remote_send_local_scatter_call_counter;
unsigned long long PVAR_COUNTER_mvp_scatterv_intra_linear_call_counter;
unsigned long long PVAR_COUNTER_mvp_scatterv_inter_linear_call_counter;
unsigned long long PVAR_COUNTER_mvp_iscatterv_intra_sched_linear_call_counter;
unsigned long long PVAR_COUNTER_mvp_iscatterv_intra_tsp_linear_call_counter;
unsigned long long PVAR_COUNTER_mvp_iscatterv_inter_sched_linear_call_counter;
unsigned long long PVAR_COUNTER_mvp_iscatterv_inter_tsp_linear_call_counter;
unsigned long long PVAR_COUNTER_mvp_allgather_intra_brucks_call_counter;
unsigned long long PVAR_COUNTER_mvp_allgather_intra_k_brucks_call_counter;
unsigned long long PVAR_COUNTER_mvp_allgather_intra_recursive_doubling_call_counter;
unsigned long long PVAR_COUNTER_mvp_allgather_intra_ring_call_counter;
unsigned long long PVAR_COUNTER_mvp_allgather_intra_recexch_doubling_call_counter;
unsigned long long PVAR_COUNTER_mvp_allgather_intra_recexch_halving_call_counter;
unsigned long long PVAR_COUNTER_mvp_allgather_intra_osu_direct_call_counter;
unsigned long long PVAR_COUNTER_mvp_allgather_intra_osu_direct_spread_call_counter;
unsigned long long PVAR_COUNTER_mvp_allgather_intra_osu_gather_bcast_call_counter;
unsigned long long PVAR_COUNTER_mvp_allgather_inter_local_gather_remote_bcast_call_counter;
unsigned long long PVAR_COUNTER_mvp_iallgather_intra_sched_ring_call_counter;
unsigned long long PVAR_COUNTER_mvp_iallgather_intra_sched_brucks_call_counter;
unsigned long long PVAR_COUNTER_mvp_iallgather_intra_sched_recursive_doubling_call_counter;
unsigned long long PVAR_COUNTER_mvp_iallgather_intra_tsp_ring_call_counter;
unsigned long long PVAR_COUNTER_mvp_iallgather_intra_tsp_brucks_call_counter;
unsigned long long PVAR_COUNTER_mvp_iallgather_intra_tsp_recexch_doubling_call_counter;
unsigned long long PVAR_COUNTER_mvp_iallgather_intra_tsp_recexch_halving_call_counter;
unsigned long long PVAR_COUNTER_mvp_iallgather_inter_sched_local_gather_remote_bcast_call_counter;
unsigned long long PVAR_COUNTER_mvp_allgatherv_intra_brucks_call_counter;
unsigned long long PVAR_COUNTER_mvp_allgatherv_intra_recursive_doubling_call_counter;
unsigned long long PVAR_COUNTER_mvp_allgatherv_intra_ring_call_counter;
unsigned long long PVAR_COUNTER_mvp_allgatherv_inter_remote_gather_local_bcast_call_counter;
unsigned long long PVAR_COUNTER_mvp_iallgatherv_intra_sched_brucks_call_counter;
unsigned long long PVAR_COUNTER_mvp_iallgatherv_intra_sched_recursive_doubling_call_counter;
unsigned long long PVAR_COUNTER_mvp_iallgatherv_intra_sched_ring_call_counter;
unsigned long long PVAR_COUNTER_mvp_iallgatherv_intra_tsp_recexch_doubling_call_counter;
unsigned long long PVAR_COUNTER_mvp_iallgatherv_intra_tsp_recexch_halving_call_counter;
unsigned long long PVAR_COUNTER_mvp_iallgatherv_intra_tsp_ring_call_counter;
unsigned long long PVAR_COUNTER_mvp_iallgatherv_intra_tsp_brucks_call_counter;
unsigned long long PVAR_COUNTER_mvp_iallgatherv_inter_sched_remote_gather_local_bcast_call_counter;
unsigned long long PVAR_COUNTER_mvp_alltoall_intra_brucks_call_counter;
unsigned long long PVAR_COUNTER_mvp_alltoall_intra_k_brucks_call_counter;
unsigned long long PVAR_COUNTER_mvp_alltoall_intra_pairwise_call_counter;
unsigned long long PVAR_COUNTER_mvp_alltoall_intra_pairwise_sendrecv_replace_call_counter;
unsigned long long PVAR_COUNTER_mvp_alltoall_intra_scattered_call_counter;
unsigned long long PVAR_COUNTER_mvp_alltoall_inter_pairwise_exchange_call_counter;
unsigned long long PVAR_COUNTER_mvp_ialltoall_intra_sched_brucks_call_counter;
unsigned long long PVAR_COUNTER_mvp_ialltoall_intra_sched_inplace_call_counter;
unsigned long long PVAR_COUNTER_mvp_ialltoall_intra_sched_pairwise_call_counter;
unsigned long long PVAR_COUNTER_mvp_ialltoall_intra_sched_permuted_sendrecv_call_counter;
unsigned long long PVAR_COUNTER_mvp_ialltoall_intra_tsp_ring_call_counter;
unsigned long long PVAR_COUNTER_mvp_ialltoall_intra_tsp_brucks_call_counter;
unsigned long long PVAR_COUNTER_mvp_ialltoall_intra_tsp_scattered_call_counter;
unsigned long long PVAR_COUNTER_mvp_ialltoall_inter_sched_pairwise_exchange_call_counter;
unsigned long long PVAR_COUNTER_mvp_alltoallv_intra_pairwise_sendrecv_replace_call_counter;
unsigned long long PVAR_COUNTER_mvp_alltoallv_intra_scattered_call_counter;
unsigned long long PVAR_COUNTER_mvp_alltoallv_inter_pairwise_exchange_call_counter;
unsigned long long PVAR_COUNTER_mvp_ialltoallv_intra_sched_blocked_call_counter;
unsigned long long PVAR_COUNTER_mvp_ialltoallv_intra_sched_inplace_call_counter;
unsigned long long PVAR_COUNTER_mvp_ialltoallv_intra_tsp_scattered_call_counter;
unsigned long long PVAR_COUNTER_mvp_ialltoallv_intra_tsp_blocked_call_counter;
unsigned long long PVAR_COUNTER_mvp_ialltoallv_intra_tsp_inplace_call_counter;
unsigned long long PVAR_COUNTER_mvp_ialltoallv_inter_sched_pairwise_exchange_call_counter;
unsigned long long PVAR_COUNTER_mvp_alltoallw_intra_pairwise_sendrecv_replace_call_counter;
unsigned long long PVAR_COUNTER_mvp_alltoallw_intra_scattered_call_counter;
unsigned long long PVAR_COUNTER_mvp_alltoallw_inter_pairwise_exchange_call_counter;
unsigned long long PVAR_COUNTER_mvp_ialltoallw_intra_sched_blocked_call_counter;
unsigned long long PVAR_COUNTER_mvp_ialltoallw_intra_sched_inplace_call_counter;
unsigned long long PVAR_COUNTER_mvp_ialltoallw_intra_tsp_blocked_call_counter;
unsigned long long PVAR_COUNTER_mvp_ialltoallw_intra_tsp_inplace_call_counter;
unsigned long long PVAR_COUNTER_mvp_ialltoallw_inter_sched_pairwise_exchange_call_counter;
unsigned long long PVAR_COUNTER_mvp_reduce_intra_binomial_call_counter;
unsigned long long PVAR_COUNTER_mvp_reduce_intra_smp_call_counter;
unsigned long long PVAR_COUNTER_mvp_reduce_intra_reduce_scatter_gather_call_counter;
unsigned long long PVAR_COUNTER_mvp_reduce_intra_osu_knomial_call_counter;
unsigned long long PVAR_COUNTER_mvp_reduce_intra_osu_allreduce_call_counter;
unsigned long long PVAR_COUNTER_mvp_reduce_inter_local_reduce_remote_send_call_counter;
unsigned long long PVAR_COUNTER_mvp_ireduce_intra_sched_smp_call_counter;
unsigned long long PVAR_COUNTER_mvp_ireduce_intra_sched_binomial_call_counter;
unsigned long long PVAR_COUNTER_mvp_ireduce_intra_sched_reduce_scatter_gather_call_counter;
unsigned long long PVAR_COUNTER_mvp_ireduce_intra_tsp_tree_call_counter;
unsigned long long PVAR_COUNTER_mvp_ireduce_intra_tsp_ring_call_counter;
unsigned long long PVAR_COUNTER_mvp_ireduce_inter_sched_local_reduce_remote_send_call_counter;
unsigned long long PVAR_COUNTER_mvp_allreduce_intra_smp_call_counter;
unsigned long long PVAR_COUNTER_mvp_allreduce_intra_recursive_doubling_call_counter;
unsigned long long PVAR_COUNTER_mvp_allreduce_intra_recursive_multiplying_call_counter;
unsigned long long PVAR_COUNTER_mvp_allreduce_intra_reduce_scatter_allgather_call_counter;
unsigned long long PVAR_COUNTER_mvp_allreduce_intra_tree_call_counter;
unsigned long long PVAR_COUNTER_mvp_allreduce_intra_recexch_call_counter;
unsigned long long PVAR_COUNTER_mvp_allreduce_intra_ring_call_counter;
unsigned long long PVAR_COUNTER_mvp_allreduce_intra_k_reduce_scatter_allgather_call_counter;
unsigned long long PVAR_COUNTER_mvp_allreduce_inter_reduce_exchange_bcast_call_counter;
unsigned long long PVAR_COUNTER_mvp_iallreduce_intra_sched_naive_call_counter;
unsigned long long PVAR_COUNTER_mvp_iallreduce_intra_sched_smp_call_counter;
unsigned long long PVAR_COUNTER_mvp_iallreduce_intra_sched_recursive_doubling_call_counter;
unsigned long long PVAR_COUNTER_mvp_iallreduce_intra_sched_reduce_scatter_allgather_call_counter;
unsigned long long PVAR_COUNTER_mvp_iallreduce_intra_tsp_recexch_single_buffer_call_counter;
unsigned long long PVAR_COUNTER_mvp_iallreduce_intra_tsp_recexch_multiple_buffer_call_counter;
unsigned long long PVAR_COUNTER_mvp_iallreduce_intra_tsp_tree_call_counter;
unsigned long long PVAR_COUNTER_mvp_iallreduce_intra_tsp_ring_call_counter;
unsigned long long PVAR_COUNTER_mvp_iallreduce_intra_tsp_recexch_reduce_scatter_recexch_allgatherv_call_counter;
unsigned long long PVAR_COUNTER_mvp_iallreduce_inter_sched_remote_reduce_local_bcast_call_counter;
unsigned long long PVAR_COUNTER_mvp_reduce_scatter_intra_noncommutative_call_counter;
unsigned long long PVAR_COUNTER_mvp_reduce_scatter_intra_pairwise_call_counter;
unsigned long long PVAR_COUNTER_mvp_reduce_scatter_intra_recursive_doubling_call_counter;
unsigned long long PVAR_COUNTER_mvp_reduce_scatter_intra_recursive_halving_call_counter;
unsigned long long PVAR_COUNTER_mvp_reduce_scatter_intra_osu_basic_call_counter;
unsigned long long PVAR_COUNTER_mvp_reduce_scatter_intra_osu_ring_call_counter;
unsigned long long PVAR_COUNTER_mvp_reduce_scatter_inter_remote_reduce_local_scatter_call_counter;
unsigned long long PVAR_COUNTER_mvp_ireduce_scatter_intra_sched_noncommutative_call_counter;
unsigned long long PVAR_COUNTER_mvp_ireduce_scatter_intra_sched_recursive_doubling_call_counter;
unsigned long long PVAR_COUNTER_mvp_ireduce_scatter_intra_sched_pairwise_call_counter;
unsigned long long PVAR_COUNTER_mvp_ireduce_scatter_intra_sched_recursive_halving_call_counter;
unsigned long long PVAR_COUNTER_mvp_ireduce_scatter_intra_tsp_recexch_call_counter;
unsigned long long PVAR_COUNTER_mvp_ireduce_scatter_inter_sched_remote_reduce_local_scatterv_call_counter;
unsigned long long PVAR_COUNTER_mvp_reduce_scatter_block_intra_noncommutative_call_counter;
unsigned long long PVAR_COUNTER_mvp_reduce_scatter_block_intra_recursive_doubling_call_counter;
unsigned long long PVAR_COUNTER_mvp_reduce_scatter_block_intra_pairwise_call_counter;
unsigned long long PVAR_COUNTER_mvp_reduce_scatter_block_intra_recursive_halving_call_counter;
unsigned long long PVAR_COUNTER_mvp_reduce_scatter_block_inter_remote_reduce_local_scatter_call_counter;
unsigned long long PVAR_COUNTER_mvp_ireduce_scatter_block_intra_sched_noncommutative_call_counter;
unsigned long long PVAR_COUNTER_mvp_ireduce_scatter_block_intra_sched_recursive_doubling_call_counter;
unsigned long long PVAR_COUNTER_mvp_ireduce_scatter_block_intra_sched_pairwise_call_counter;
unsigned long long PVAR_COUNTER_mvp_ireduce_scatter_block_intra_sched_recursive_halving_call_counter;
unsigned long long PVAR_COUNTER_mvp_ireduce_scatter_block_intra_tsp_recexch_call_counter;
unsigned long long PVAR_COUNTER_mvp_ireduce_scatter_block_inter_sched_remote_reduce_local_scatterv_call_counter;
unsigned long long PVAR_COUNTER_mvp_scan_intra_smp_call_counter;
unsigned long long PVAR_COUNTER_mvp_scan_intra_recursive_doubling_call_counter;
unsigned long long PVAR_COUNTER_mvp_iscan_intra_sched_smp_call_counter;
unsigned long long PVAR_COUNTER_mvp_iscan_intra_sched_recursive_doubling_call_counter;
unsigned long long PVAR_COUNTER_mvp_iscan_intra_tsp_recursive_doubling_call_counter;
unsigned long long PVAR_COUNTER_mvp_exscan_intra_recursive_doubling_call_counter;
unsigned long long PVAR_COUNTER_mvp_iexscan_intra_sched_recursive_doubling_call_counter;
unsigned long long PVAR_COUNTER_mvp_ineighbor_allgather_intra_sched_linear_call_counter;
unsigned long long PVAR_COUNTER_mvp_ineighbor_allgather_intra_tsp_linear_call_counter;
unsigned long long PVAR_COUNTER_mvp_ineighbor_allgatherv_intra_sched_linear_call_counter;
unsigned long long PVAR_COUNTER_mvp_ineighbor_allgatherv_intra_tsp_linear_call_counter;
unsigned long long PVAR_COUNTER_mvp_ineighbor_alltoall_intra_sched_linear_call_counter;
unsigned long long PVAR_COUNTER_mvp_ineighbor_alltoall_intra_tsp_linear_call_counter;
unsigned long long PVAR_COUNTER_mvp_ineighbor_alltoallv_intra_sched_linear_call_counter;
unsigned long long PVAR_COUNTER_mvp_ineighbor_alltoallv_intra_tsp_linear_call_counter;
unsigned long long PVAR_COUNTER_mvp_ineighbor_alltoallw_intra_sched_linear_call_counter;
unsigned long long PVAR_COUNTER_mvp_ineighbor_alltoallw_intra_tsp_linear_call_counter;
unsigned long long PVAR_COUNTER_mvp_barrier_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_barrier_timer;
unsigned long long PVAR_COUNTER_mvp_ibarrier_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_ibarrier_timer;
unsigned long long PVAR_COUNTER_mvp_bcast_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_bcast_timer;
unsigned long long PVAR_COUNTER_mvp_ibcast_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_ibcast_timer;
unsigned long long PVAR_COUNTER_mvp_gather_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_gather_timer;
unsigned long long PVAR_COUNTER_mvp_igather_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_igather_timer;
unsigned long long PVAR_COUNTER_mvp_gatherv_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_gatherv_timer;
unsigned long long PVAR_COUNTER_mvp_igatherv_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_igatherv_timer;
unsigned long long PVAR_COUNTER_mvp_scatter_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_scatter_timer;
unsigned long long PVAR_COUNTER_mvp_iscatter_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_iscatter_timer;
unsigned long long PVAR_COUNTER_mvp_scatterv_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_scatterv_timer;
unsigned long long PVAR_COUNTER_mvp_iscatterv_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_iscatterv_timer;
unsigned long long PVAR_COUNTER_mvp_allgather_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_allgather_timer;
unsigned long long PVAR_COUNTER_mvp_iallgather_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_iallgather_timer;
unsigned long long PVAR_COUNTER_mvp_allgatherv_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_allgatherv_timer;
unsigned long long PVAR_COUNTER_mvp_iallgatherv_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_iallgatherv_timer;
unsigned long long PVAR_COUNTER_mvp_alltoall_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_alltoall_timer;
unsigned long long PVAR_COUNTER_mvp_ialltoall_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_ialltoall_timer;
unsigned long long PVAR_COUNTER_mvp_alltoallv_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_alltoallv_timer;
unsigned long long PVAR_COUNTER_mvp_ialltoallv_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_ialltoallv_timer;
unsigned long long PVAR_COUNTER_mvp_alltoallw_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_alltoallw_timer;
unsigned long long PVAR_COUNTER_mvp_ialltoallw_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_ialltoallw_timer;
unsigned long long PVAR_COUNTER_mvp_reduce_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_reduce_timer;
unsigned long long PVAR_COUNTER_mvp_ireduce_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_ireduce_timer;
unsigned long long PVAR_COUNTER_mvp_allreduce_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_allreduce_timer;
unsigned long long PVAR_COUNTER_mvp_iallreduce_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_iallreduce_timer;
unsigned long long PVAR_COUNTER_mvp_reduce_scatter_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_reduce_scatter_timer;
unsigned long long PVAR_COUNTER_mvp_ireduce_scatter_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_ireduce_scatter_timer;
unsigned long long PVAR_COUNTER_mvp_reduce_scatter_block_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_reduce_scatter_block_timer;
unsigned long long PVAR_COUNTER_mvp_ireduce_scatter_block_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_ireduce_scatter_block_timer;
unsigned long long PVAR_COUNTER_mvp_scan_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_scan_timer;
unsigned long long PVAR_COUNTER_mvp_iscan_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_iscan_timer;
unsigned long long PVAR_COUNTER_mvp_exscan_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_exscan_timer;
unsigned long long PVAR_COUNTER_mvp_iexscan_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_iexscan_timer;
unsigned long long PVAR_COUNTER_mvp_neighbor_allgather_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_neighbor_allgather_timer;
unsigned long long PVAR_COUNTER_mvp_ineighbor_allgather_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_ineighbor_allgather_timer;
unsigned long long PVAR_COUNTER_mvp_neighbor_allgatherv_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_neighbor_allgatherv_timer;
unsigned long long PVAR_COUNTER_mvp_ineighbor_allgatherv_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_ineighbor_allgatherv_timer;
unsigned long long PVAR_COUNTER_mvp_neighbor_alltoall_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_neighbor_alltoall_timer;
unsigned long long PVAR_COUNTER_mvp_ineighbor_alltoall_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_ineighbor_alltoall_timer;
unsigned long long PVAR_COUNTER_mvp_neighbor_alltoallv_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_neighbor_alltoallv_timer;
unsigned long long PVAR_COUNTER_mvp_ineighbor_alltoallv_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_ineighbor_alltoallv_timer;
unsigned long long PVAR_COUNTER_mvp_neighbor_alltoallw_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_neighbor_alltoallw_timer;
unsigned long long PVAR_COUNTER_mvp_ineighbor_alltoallw_call_counter;
MPIR_T_pvar_timer_t PVAR_TIMER_mvp_ineighbor_alltoallw_timer;

void MPIR_REGISTER_MVP_VARIABLES(void)
{

     MPIR_T_PVAR_COUNTER_ARRAY_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_mpic_send_byte_counter_array, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "barrier-intra Algorithms", /* Category Name */
         "Number of bytes passing through MPIC_Send" /* Description */);
     MPIR_T_PVAR_COUNTER_ARRAY_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_mpic_recv_byte_counter_array, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "barrier-intra Algorithms", /* Category Name */
         "Number of bytes passing through mpic_send_array" /* Description */);
     MPIR_T_PVAR_COUNTER_ARRAY_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_mpic_isend_byte_counter_array, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "barrier-intra Algorithms", /* Category Name */
         "Number of bytes passing through MPIC_Isend_replace" /* Description */);
     MPIR_T_PVAR_COUNTER_ARRAY_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_mpic_irecv_byte_counter_array, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "barrier-intra Algorithms", /* Category Name */
         "Number of bytes passing through MPIC_Irecv" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_barrier_intra_k_dissemination_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "barrier-intra Algorithms", /* Category Name */
         "Number of calls to barrier_intra_k_dissemination" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_barrier_intra_recexch_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "barrier-intra Algorithms", /* Category Name */
         "Number of calls to barrier_intra_recexch" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_barrier_intra_smp_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "barrier-intra Algorithms", /* Category Name */
         "Number of calls to barrier_intra_smp" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_barrier_intra_osu_pairwise_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "barrier-intra Algorithms", /* Category Name */
         "Number of calls to barrier_intra_osu_pairwise" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_barrier_inter_bcast_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "barrier-inter Algorithms", /* Category Name */
         "Number of calls to barrier_inter_bcast" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ibarrier_intra_sched_recursive_doubling_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ibarrier-intra Algorithms", /* Category Name */
         "Number of calls to ibarrier_intra_sched_recursive_doubling" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ibarrier_intra_tsp_recexch_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ibarrier-intra Algorithms", /* Category Name */
         "Number of calls to ibarrier_intra_tsp_recexch" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ibarrier_intra_tsp_k_dissemination_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ibarrier-intra Algorithms", /* Category Name */
         "Number of calls to ibarrier_intra_tsp_k_dissemination" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ibarrier_inter_sched_bcast_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ibarrier-inter Algorithms", /* Category Name */
         "Number of calls to ibarrier_inter_sched_bcast" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_bcast_intra_binomial_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "bcast-intra Algorithms", /* Category Name */
         "Number of calls to bcast_intra_binomial" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_bcast_intra_scatter_recursive_doubling_allgather_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "bcast-intra Algorithms", /* Category Name */
         "Number of calls to bcast_intra_scatter_recursive_doubling_allgather" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_bcast_intra_scatter_ring_allgather_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "bcast-intra Algorithms", /* Category Name */
         "Number of calls to bcast_intra_scatter_ring_allgather" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_bcast_intra_smp_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "bcast-intra Algorithms", /* Category Name */
         "Number of calls to bcast_intra_smp" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_bcast_intra_tree_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "bcast-intra Algorithms", /* Category Name */
         "Number of calls to bcast_intra_tree" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_bcast_intra_pipelined_tree_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "bcast-intra Algorithms", /* Category Name */
         "Number of calls to bcast_intra_pipelined_tree" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_bcast_intra_osu_knomial_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "bcast-intra Algorithms", /* Category Name */
         "Number of calls to bcast_intra_osu_knomial" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_bcast_intra_osu_pipelined_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "bcast-intra Algorithms", /* Category Name */
         "Number of calls to bcast_intra_osu_pipelined" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ibcast_intra_sched_binomial_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ibcast-intra Algorithms", /* Category Name */
         "Number of calls to ibcast_intra_sched_binomial" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ibcast_intra_sched_smp_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ibcast-intra Algorithms", /* Category Name */
         "Number of calls to ibcast_intra_sched_smp" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ibcast_intra_sched_scatter_recursive_doubling_allgather_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ibcast-intra Algorithms", /* Category Name */
         "Number of calls to ibcast_intra_sched_scatter_recursive_doubling_allgather" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ibcast_intra_sched_scatter_ring_allgather_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ibcast-intra Algorithms", /* Category Name */
         "Number of calls to ibcast_intra_sched_scatter_ring_allgather" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ibcast_intra_tsp_tree_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ibcast-intra Algorithms", /* Category Name */
         "Number of calls to ibcast_intra_tsp_tree" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ibcast_intra_tsp_scatterv_recexch_allgatherv_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ibcast-intra Algorithms", /* Category Name */
         "Number of calls to ibcast_intra_tsp_scatterv_recexch_allgatherv" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ibcast_intra_tsp_scatterv_ring_allgatherv_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ibcast-intra Algorithms", /* Category Name */
         "Number of calls to ibcast_intra_tsp_scatterv_ring_allgatherv" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ibcast_intra_tsp_ring_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ibcast-intra Algorithms", /* Category Name */
         "Number of calls to ibcast_intra_tsp_ring" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_bcast_inter_remote_send_local_bcast_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "bcast-inter Algorithms", /* Category Name */
         "Number of calls to bcast_inter_remote_send_local_bcast" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ibcast_inter_sched_flat_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ibcast-inter Algorithms", /* Category Name */
         "Number of calls to ibcast_inter_sched_flat" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_gather_intra_binomial_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "gather-intra Algorithms", /* Category Name */
         "Number of calls to gather_intra_binomial" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_gather_intra_osu_direct_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "gather-intra Algorithms", /* Category Name */
         "Number of calls to gather_intra_osu_direct" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_gather_intra_osu_direct_block_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "gather-intra Algorithms", /* Category Name */
         "Number of calls to gather_intra_osu_direct_block" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_gather_inter_linear_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "gather-inter Algorithms", /* Category Name */
         "Number of calls to gather_inter_linear" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_gather_inter_local_gather_remote_send_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "gather-inter Algorithms", /* Category Name */
         "Number of calls to gather_inter_local_gather_remote_send" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_igather_intra_sched_binomial_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "igather-intra Algorithms", /* Category Name */
         "Number of calls to igather_intra_sched_binomial" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_igather_intra_tsp_tree_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "igather-intra Algorithms", /* Category Name */
         "Number of calls to igather_intra_tsp_tree" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_igather_inter_sched_long_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "igather-inter Algorithms", /* Category Name */
         "Number of calls to igather_inter_sched_long" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_igather_inter_sched_short_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "igather-inter Algorithms", /* Category Name */
         "Number of calls to igather_inter_sched_short" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_gatherv_intra_linear_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "gatherv-intra Algorithms", /* Category Name */
         "Number of calls to gatherv_intra_linear" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_gatherv_inter_linear_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "gatherv-inter Algorithms", /* Category Name */
         "Number of calls to gatherv_inter_linear" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_igatherv_intra_sched_linear_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "igatherv-intra Algorithms", /* Category Name */
         "Number of calls to igatherv_intra_sched_linear" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_igatherv_intra_tsp_linear_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "igatherv-intra Algorithms", /* Category Name */
         "Number of calls to igatherv_intra_tsp_linear" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_igatherv_inter_sched_linear_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "igatherv-inter Algorithms", /* Category Name */
         "Number of calls to igatherv_inter_sched_linear" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_igatherv_inter_tsp_linear_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "igatherv-inter Algorithms", /* Category Name */
         "Number of calls to igatherv_inter_tsp_linear" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_scatter_intra_binomial_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "scatter-intra Algorithms", /* Category Name */
         "Number of calls to scatter_intra_binomial" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_scatter_intra_osu_direct_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "scatter-intra Algorithms", /* Category Name */
         "Number of calls to scatter_intra_osu_direct" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_scatter_inter_linear_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "scatter-inter Algorithms", /* Category Name */
         "Number of calls to scatter_inter_linear" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_scatter_inter_remote_send_local_scatter_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "scatter-inter Algorithms", /* Category Name */
         "Number of calls to scatter_inter_remote_send_local_scatter" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iscatter_intra_sched_binomial_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iscatter-intra Algorithms", /* Category Name */
         "Number of calls to iscatter_intra_sched_binomial" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iscatter_intra_tsp_tree_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iscatter-intra Algorithms", /* Category Name */
         "Number of calls to iscatter_intra_tsp_tree" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iscatter_inter_sched_linear_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iscatter-inter Algorithms", /* Category Name */
         "Number of calls to iscatter_inter_sched_linear" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iscatter_inter_sched_remote_send_local_scatter_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iscatter-inter Algorithms", /* Category Name */
         "Number of calls to iscatter_inter_sched_remote_send_local_scatter" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_scatterv_intra_linear_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "scatterv-intra Algorithms", /* Category Name */
         "Number of calls to scatterv_intra_linear" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_scatterv_inter_linear_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "scatterv-inter Algorithms", /* Category Name */
         "Number of calls to scatterv_inter_linear" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iscatterv_intra_sched_linear_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iscatterv-intra Algorithms", /* Category Name */
         "Number of calls to iscatterv_intra_sched_linear" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iscatterv_intra_tsp_linear_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iscatterv-intra Algorithms", /* Category Name */
         "Number of calls to iscatterv_intra_tsp_linear" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iscatterv_inter_sched_linear_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iscatterv-inter Algorithms", /* Category Name */
         "Number of calls to iscatterv_inter_sched_linear" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iscatterv_inter_tsp_linear_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iscatterv-inter Algorithms", /* Category Name */
         "Number of calls to iscatterv_inter_tsp_linear" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_allgather_intra_brucks_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "allgather-intra Algorithms", /* Category Name */
         "Number of calls to allgather_intra_brucks" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_allgather_intra_k_brucks_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "allgather-intra Algorithms", /* Category Name */
         "Number of calls to allgather_intra_k_brucks" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_allgather_intra_recursive_doubling_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "allgather-intra Algorithms", /* Category Name */
         "Number of calls to allgather_intra_recursive_doubling" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_allgather_intra_ring_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "allgather-intra Algorithms", /* Category Name */
         "Number of calls to allgather_intra_ring" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_allgather_intra_recexch_doubling_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "allgather-intra Algorithms", /* Category Name */
         "Number of calls to allgather_intra_recexch_doubling" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_allgather_intra_recexch_halving_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "allgather-intra Algorithms", /* Category Name */
         "Number of calls to allgather_intra_recexch_halving" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_allgather_intra_osu_direct_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "allgather-intra Algorithms", /* Category Name */
         "Number of calls to allgather_intra_osu_direct" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_allgather_intra_osu_direct_spread_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "allgather-intra Algorithms", /* Category Name */
         "Number of calls to allgather_intra_osu_direct_spread" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_allgather_intra_osu_gather_bcast_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "allgather-intra Algorithms", /* Category Name */
         "Number of calls to allgather_intra_osu_gather_bcast" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_allgather_inter_local_gather_remote_bcast_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "allgather-inter Algorithms", /* Category Name */
         "Number of calls to allgather_inter_local_gather_remote_bcast" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iallgather_intra_sched_ring_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iallgather-intra Algorithms", /* Category Name */
         "Number of calls to iallgather_intra_sched_ring" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iallgather_intra_sched_brucks_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iallgather-intra Algorithms", /* Category Name */
         "Number of calls to iallgather_intra_sched_brucks" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iallgather_intra_sched_recursive_doubling_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iallgather-intra Algorithms", /* Category Name */
         "Number of calls to iallgather_intra_sched_recursive_doubling" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iallgather_intra_tsp_ring_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iallgather-intra Algorithms", /* Category Name */
         "Number of calls to iallgather_intra_tsp_ring" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iallgather_intra_tsp_brucks_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iallgather-intra Algorithms", /* Category Name */
         "Number of calls to iallgather_intra_tsp_brucks" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iallgather_intra_tsp_recexch_doubling_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iallgather-intra Algorithms", /* Category Name */
         "Number of calls to iallgather_intra_tsp_recexch_doubling" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iallgather_intra_tsp_recexch_halving_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iallgather-intra Algorithms", /* Category Name */
         "Number of calls to iallgather_intra_tsp_recexch_halving" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iallgather_inter_sched_local_gather_remote_bcast_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iallgather-inter Algorithms", /* Category Name */
         "Number of calls to iallgather_inter_sched_local_gather_remote_bcast" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_allgatherv_intra_brucks_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "allgatherv-intra Algorithms", /* Category Name */
         "Number of calls to allgatherv_intra_brucks" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_allgatherv_intra_recursive_doubling_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "allgatherv-intra Algorithms", /* Category Name */
         "Number of calls to allgatherv_intra_recursive_doubling" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_allgatherv_intra_ring_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "allgatherv-intra Algorithms", /* Category Name */
         "Number of calls to allgatherv_intra_ring" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_allgatherv_inter_remote_gather_local_bcast_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "allgatherv-inter Algorithms", /* Category Name */
         "Number of calls to allgatherv_inter_remote_gather_local_bcast" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iallgatherv_intra_sched_brucks_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iallgatherv-intra Algorithms", /* Category Name */
         "Number of calls to iallgatherv_intra_sched_brucks" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iallgatherv_intra_sched_recursive_doubling_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iallgatherv-intra Algorithms", /* Category Name */
         "Number of calls to iallgatherv_intra_sched_recursive_doubling" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iallgatherv_intra_sched_ring_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iallgatherv-intra Algorithms", /* Category Name */
         "Number of calls to iallgatherv_intra_sched_ring" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iallgatherv_intra_tsp_recexch_doubling_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iallgatherv-intra Algorithms", /* Category Name */
         "Number of calls to iallgatherv_intra_tsp_recexch_doubling" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iallgatherv_intra_tsp_recexch_halving_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iallgatherv-intra Algorithms", /* Category Name */
         "Number of calls to iallgatherv_intra_tsp_recexch_halving" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iallgatherv_intra_tsp_ring_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iallgatherv-intra Algorithms", /* Category Name */
         "Number of calls to iallgatherv_intra_tsp_ring" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iallgatherv_intra_tsp_brucks_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iallgatherv-intra Algorithms", /* Category Name */
         "Number of calls to iallgatherv_intra_tsp_brucks" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iallgatherv_inter_sched_remote_gather_local_bcast_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iallgatherv-inter Algorithms", /* Category Name */
         "Number of calls to iallgatherv_inter_sched_remote_gather_local_bcast" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_alltoall_intra_brucks_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "alltoall-intra Algorithms", /* Category Name */
         "Number of calls to alltoall_intra_brucks" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_alltoall_intra_k_brucks_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "alltoall-intra Algorithms", /* Category Name */
         "Number of calls to alltoall_intra_k_brucks" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_alltoall_intra_pairwise_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "alltoall-intra Algorithms", /* Category Name */
         "Number of calls to alltoall_intra_pairwise" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_alltoall_intra_pairwise_sendrecv_replace_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "alltoall-intra Algorithms", /* Category Name */
         "Number of calls to alltoall_intra_pairwise_sendrecv_replace" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_alltoall_intra_scattered_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "alltoall-intra Algorithms", /* Category Name */
         "Number of calls to alltoall_intra_scattered" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_alltoall_inter_pairwise_exchange_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "alltoall-inter Algorithms", /* Category Name */
         "Number of calls to alltoall_inter_pairwise_exchange" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ialltoall_intra_sched_brucks_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ialltoall-intra Algorithms", /* Category Name */
         "Number of calls to ialltoall_intra_sched_brucks" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ialltoall_intra_sched_inplace_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ialltoall-intra Algorithms", /* Category Name */
         "Number of calls to ialltoall_intra_sched_inplace" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ialltoall_intra_sched_pairwise_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ialltoall-intra Algorithms", /* Category Name */
         "Number of calls to ialltoall_intra_sched_pairwise" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ialltoall_intra_sched_permuted_sendrecv_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ialltoall-intra Algorithms", /* Category Name */
         "Number of calls to ialltoall_intra_sched_permuted_sendrecv" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ialltoall_intra_tsp_ring_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ialltoall-intra Algorithms", /* Category Name */
         "Number of calls to ialltoall_intra_tsp_ring" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ialltoall_intra_tsp_brucks_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ialltoall-intra Algorithms", /* Category Name */
         "Number of calls to ialltoall_intra_tsp_brucks" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ialltoall_intra_tsp_scattered_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ialltoall-intra Algorithms", /* Category Name */
         "Number of calls to ialltoall_intra_tsp_scattered" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ialltoall_inter_sched_pairwise_exchange_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ialltoall-inter Algorithms", /* Category Name */
         "Number of calls to ialltoall_inter_sched_pairwise_exchange" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_alltoallv_intra_pairwise_sendrecv_replace_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "alltoallv-intra Algorithms", /* Category Name */
         "Number of calls to alltoallv_intra_pairwise_sendrecv_replace" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_alltoallv_intra_scattered_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "alltoallv-intra Algorithms", /* Category Name */
         "Number of calls to alltoallv_intra_scattered" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_alltoallv_inter_pairwise_exchange_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "alltoallv-inter Algorithms", /* Category Name */
         "Number of calls to alltoallv_inter_pairwise_exchange" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ialltoallv_intra_sched_blocked_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ialltoallv-intra Algorithms", /* Category Name */
         "Number of calls to ialltoallv_intra_sched_blocked" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ialltoallv_intra_sched_inplace_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ialltoallv-intra Algorithms", /* Category Name */
         "Number of calls to ialltoallv_intra_sched_inplace" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ialltoallv_intra_tsp_scattered_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ialltoallv-intra Algorithms", /* Category Name */
         "Number of calls to ialltoallv_intra_tsp_scattered" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ialltoallv_intra_tsp_blocked_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ialltoallv-intra Algorithms", /* Category Name */
         "Number of calls to ialltoallv_intra_tsp_blocked" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ialltoallv_intra_tsp_inplace_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ialltoallv-intra Algorithms", /* Category Name */
         "Number of calls to ialltoallv_intra_tsp_inplace" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ialltoallv_inter_sched_pairwise_exchange_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ialltoallv-inter Algorithms", /* Category Name */
         "Number of calls to ialltoallv_inter_sched_pairwise_exchange" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_alltoallw_intra_pairwise_sendrecv_replace_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "alltoallw-intra Algorithms", /* Category Name */
         "Number of calls to alltoallw_intra_pairwise_sendrecv_replace" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_alltoallw_intra_scattered_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "alltoallw-intra Algorithms", /* Category Name */
         "Number of calls to alltoallw_intra_scattered" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_alltoallw_inter_pairwise_exchange_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "alltoallw-inter Algorithms", /* Category Name */
         "Number of calls to alltoallw_inter_pairwise_exchange" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ialltoallw_intra_sched_blocked_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ialltoallw-intra Algorithms", /* Category Name */
         "Number of calls to ialltoallw_intra_sched_blocked" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ialltoallw_intra_sched_inplace_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ialltoallw-intra Algorithms", /* Category Name */
         "Number of calls to ialltoallw_intra_sched_inplace" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ialltoallw_intra_tsp_blocked_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ialltoallw-intra Algorithms", /* Category Name */
         "Number of calls to ialltoallw_intra_tsp_blocked" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ialltoallw_intra_tsp_inplace_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ialltoallw-intra Algorithms", /* Category Name */
         "Number of calls to ialltoallw_intra_tsp_inplace" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ialltoallw_inter_sched_pairwise_exchange_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ialltoallw-inter Algorithms", /* Category Name */
         "Number of calls to ialltoallw_inter_sched_pairwise_exchange" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_reduce_intra_binomial_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "reduce-intra Algorithms", /* Category Name */
         "Number of calls to reduce_intra_binomial" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_reduce_intra_smp_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "reduce-intra Algorithms", /* Category Name */
         "Number of calls to reduce_intra_smp" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_reduce_intra_reduce_scatter_gather_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "reduce-intra Algorithms", /* Category Name */
         "Number of calls to reduce_intra_reduce_scatter_gather" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_reduce_intra_osu_knomial_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "reduce-intra Algorithms", /* Category Name */
         "Number of calls to reduce_intra_osu_knomial" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_reduce_intra_osu_allreduce_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "reduce-intra Algorithms", /* Category Name */
         "Number of calls to reduce_intra_osu_allreduce" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_reduce_inter_local_reduce_remote_send_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "reduce-inter Algorithms", /* Category Name */
         "Number of calls to reduce_inter_local_reduce_remote_send" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ireduce_intra_sched_smp_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ireduce-intra Algorithms", /* Category Name */
         "Number of calls to ireduce_intra_sched_smp" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ireduce_intra_sched_binomial_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ireduce-intra Algorithms", /* Category Name */
         "Number of calls to ireduce_intra_sched_binomial" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ireduce_intra_sched_reduce_scatter_gather_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ireduce-intra Algorithms", /* Category Name */
         "Number of calls to ireduce_intra_sched_reduce_scatter_gather" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ireduce_intra_tsp_tree_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ireduce-intra Algorithms", /* Category Name */
         "Number of calls to ireduce_intra_tsp_tree" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ireduce_intra_tsp_ring_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ireduce-intra Algorithms", /* Category Name */
         "Number of calls to ireduce_intra_tsp_ring" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ireduce_inter_sched_local_reduce_remote_send_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ireduce-inter Algorithms", /* Category Name */
         "Number of calls to ireduce_inter_sched_local_reduce_remote_send" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_allreduce_intra_smp_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "allreduce-intra Algorithms", /* Category Name */
         "Number of calls to allreduce_intra_smp" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_allreduce_intra_recursive_doubling_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "allreduce-intra Algorithms", /* Category Name */
         "Number of calls to allreduce_intra_recursive_doubling" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_allreduce_intra_recursive_multiplying_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "allreduce-intra Algorithms", /* Category Name */
         "Number of calls to allreduce_intra_recursive_multiplying" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_allreduce_intra_reduce_scatter_allgather_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "allreduce-intra Algorithms", /* Category Name */
         "Number of calls to allreduce_intra_reduce_scatter_allgather" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_allreduce_intra_tree_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "allreduce-intra Algorithms", /* Category Name */
         "Number of calls to allreduce_intra_tree" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_allreduce_intra_recexch_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "allreduce-intra Algorithms", /* Category Name */
         "Number of calls to allreduce_intra_recexch" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_allreduce_intra_ring_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "allreduce-intra Algorithms", /* Category Name */
         "Number of calls to allreduce_intra_ring" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_allreduce_intra_k_reduce_scatter_allgather_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "allreduce-intra Algorithms", /* Category Name */
         "Number of calls to allreduce_intra_k_reduce_scatter_allgather" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_allreduce_inter_reduce_exchange_bcast_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "allreduce-inter Algorithms", /* Category Name */
         "Number of calls to allreduce_inter_reduce_exchange_bcast" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iallreduce_intra_sched_naive_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iallreduce-intra Algorithms", /* Category Name */
         "Number of calls to iallreduce_intra_sched_naive" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iallreduce_intra_sched_smp_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iallreduce-intra Algorithms", /* Category Name */
         "Number of calls to iallreduce_intra_sched_smp" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iallreduce_intra_sched_recursive_doubling_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iallreduce-intra Algorithms", /* Category Name */
         "Number of calls to iallreduce_intra_sched_recursive_doubling" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iallreduce_intra_sched_reduce_scatter_allgather_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iallreduce-intra Algorithms", /* Category Name */
         "Number of calls to iallreduce_intra_sched_reduce_scatter_allgather" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iallreduce_intra_tsp_recexch_single_buffer_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iallreduce-intra Algorithms", /* Category Name */
         "Number of calls to iallreduce_intra_tsp_recexch_single_buffer" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iallreduce_intra_tsp_recexch_multiple_buffer_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iallreduce-intra Algorithms", /* Category Name */
         "Number of calls to iallreduce_intra_tsp_recexch_multiple_buffer" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iallreduce_intra_tsp_tree_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iallreduce-intra Algorithms", /* Category Name */
         "Number of calls to iallreduce_intra_tsp_tree" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iallreduce_intra_tsp_ring_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iallreduce-intra Algorithms", /* Category Name */
         "Number of calls to iallreduce_intra_tsp_ring" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iallreduce_intra_tsp_recexch_reduce_scatter_recexch_allgatherv_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iallreduce-intra Algorithms", /* Category Name */
         "Number of calls to iallreduce_intra_tsp_recexch_reduce_scatter_recexch_allgatherv" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iallreduce_inter_sched_remote_reduce_local_bcast_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iallreduce-inter Algorithms", /* Category Name */
         "Number of calls to iallreduce_inter_sched_remote_reduce_local_bcast" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_reduce_scatter_intra_noncommutative_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "reduce_scatter-intra Algorithms", /* Category Name */
         "Number of calls to reduce_scatter_intra_noncommutative" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_reduce_scatter_intra_pairwise_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "reduce_scatter-intra Algorithms", /* Category Name */
         "Number of calls to reduce_scatter_intra_pairwise" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_reduce_scatter_intra_recursive_doubling_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "reduce_scatter-intra Algorithms", /* Category Name */
         "Number of calls to reduce_scatter_intra_recursive_doubling" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_reduce_scatter_intra_recursive_halving_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "reduce_scatter-intra Algorithms", /* Category Name */
         "Number of calls to reduce_scatter_intra_recursive_halving" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_reduce_scatter_intra_osu_basic_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "reduce_scatter-intra Algorithms", /* Category Name */
         "Number of calls to reduce_scatter_intra_osu_basic" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_reduce_scatter_intra_osu_ring_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "reduce_scatter-intra Algorithms", /* Category Name */
         "Number of calls to reduce_scatter_intra_osu_ring" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_reduce_scatter_inter_remote_reduce_local_scatter_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "reduce_scatter-inter Algorithms", /* Category Name */
         "Number of calls to reduce_scatter_inter_remote_reduce_local_scatter" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ireduce_scatter_intra_sched_noncommutative_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ireduce_scatter-intra Algorithms", /* Category Name */
         "Number of calls to ireduce_scatter_intra_sched_noncommutative" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ireduce_scatter_intra_sched_recursive_doubling_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ireduce_scatter-intra Algorithms", /* Category Name */
         "Number of calls to ireduce_scatter_intra_sched_recursive_doubling" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ireduce_scatter_intra_sched_pairwise_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ireduce_scatter-intra Algorithms", /* Category Name */
         "Number of calls to ireduce_scatter_intra_sched_pairwise" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ireduce_scatter_intra_sched_recursive_halving_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ireduce_scatter-intra Algorithms", /* Category Name */
         "Number of calls to ireduce_scatter_intra_sched_recursive_halving" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ireduce_scatter_intra_tsp_recexch_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ireduce_scatter-intra Algorithms", /* Category Name */
         "Number of calls to ireduce_scatter_intra_tsp_recexch" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ireduce_scatter_inter_sched_remote_reduce_local_scatterv_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ireduce_scatter-inter Algorithms", /* Category Name */
         "Number of calls to ireduce_scatter_inter_sched_remote_reduce_local_scatterv" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_reduce_scatter_block_intra_noncommutative_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "reduce_scatter_block-intra Algorithms", /* Category Name */
         "Number of calls to reduce_scatter_block_intra_noncommutative" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_reduce_scatter_block_intra_recursive_doubling_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "reduce_scatter_block-intra Algorithms", /* Category Name */
         "Number of calls to reduce_scatter_block_intra_recursive_doubling" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_reduce_scatter_block_intra_pairwise_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "reduce_scatter_block-intra Algorithms", /* Category Name */
         "Number of calls to reduce_scatter_block_intra_pairwise" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_reduce_scatter_block_intra_recursive_halving_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "reduce_scatter_block-intra Algorithms", /* Category Name */
         "Number of calls to reduce_scatter_block_intra_recursive_halving" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_reduce_scatter_block_inter_remote_reduce_local_scatter_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "reduce_scatter_block-inter Algorithms", /* Category Name */
         "Number of calls to reduce_scatter_block_inter_remote_reduce_local_scatter" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ireduce_scatter_block_intra_sched_noncommutative_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ireduce_scatter_block-intra Algorithms", /* Category Name */
         "Number of calls to ireduce_scatter_block_intra_sched_noncommutative" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ireduce_scatter_block_intra_sched_recursive_doubling_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ireduce_scatter_block-intra Algorithms", /* Category Name */
         "Number of calls to ireduce_scatter_block_intra_sched_recursive_doubling" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ireduce_scatter_block_intra_sched_pairwise_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ireduce_scatter_block-intra Algorithms", /* Category Name */
         "Number of calls to ireduce_scatter_block_intra_sched_pairwise" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ireduce_scatter_block_intra_sched_recursive_halving_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ireduce_scatter_block-intra Algorithms", /* Category Name */
         "Number of calls to ireduce_scatter_block_intra_sched_recursive_halving" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ireduce_scatter_block_intra_tsp_recexch_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ireduce_scatter_block-intra Algorithms", /* Category Name */
         "Number of calls to ireduce_scatter_block_intra_tsp_recexch" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ireduce_scatter_block_inter_sched_remote_reduce_local_scatterv_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ireduce_scatter_block-inter Algorithms", /* Category Name */
         "Number of calls to ireduce_scatter_block_inter_sched_remote_reduce_local_scatterv" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_scan_intra_smp_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "scan-intra Algorithms", /* Category Name */
         "Number of calls to scan_intra_smp" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_scan_intra_recursive_doubling_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "scan-intra Algorithms", /* Category Name */
         "Number of calls to scan_intra_recursive_doubling" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iscan_intra_sched_smp_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iscan-intra Algorithms", /* Category Name */
         "Number of calls to iscan_intra_sched_smp" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iscan_intra_sched_recursive_doubling_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iscan-intra Algorithms", /* Category Name */
         "Number of calls to iscan_intra_sched_recursive_doubling" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iscan_intra_tsp_recursive_doubling_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iscan-intra Algorithms", /* Category Name */
         "Number of calls to iscan_intra_tsp_recursive_doubling" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_exscan_intra_recursive_doubling_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "exscan-intra Algorithms", /* Category Name */
         "Number of calls to exscan_intra_recursive_doubling" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iexscan_intra_sched_recursive_doubling_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "iexscan-intra Algorithms", /* Category Name */
         "Number of calls to iexscan_intra_sched_recursive_doubling" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ineighbor_allgather_intra_sched_linear_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ineighbor_allgather-intra Algorithms", /* Category Name */
         "Number of calls to ineighbor_allgather_intra_sched_linear" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ineighbor_allgather_intra_tsp_linear_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ineighbor_allgather-intra Algorithms", /* Category Name */
         "Number of calls to ineighbor_allgather_intra_tsp_linear" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ineighbor_allgatherv_intra_sched_linear_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ineighbor_allgatherv-intra Algorithms", /* Category Name */
         "Number of calls to ineighbor_allgatherv_intra_sched_linear" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ineighbor_allgatherv_intra_tsp_linear_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ineighbor_allgatherv-intra Algorithms", /* Category Name */
         "Number of calls to ineighbor_allgatherv_intra_tsp_linear" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ineighbor_alltoall_intra_sched_linear_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ineighbor_alltoall-intra Algorithms", /* Category Name */
         "Number of calls to ineighbor_alltoall_intra_sched_linear" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ineighbor_alltoall_intra_tsp_linear_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ineighbor_alltoall-intra Algorithms", /* Category Name */
         "Number of calls to ineighbor_alltoall_intra_tsp_linear" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ineighbor_alltoallv_intra_sched_linear_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ineighbor_alltoallv-intra Algorithms", /* Category Name */
         "Number of calls to ineighbor_alltoallv_intra_sched_linear" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ineighbor_alltoallv_intra_tsp_linear_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ineighbor_alltoallv-intra Algorithms", /* Category Name */
         "Number of calls to ineighbor_alltoallv_intra_tsp_linear" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ineighbor_alltoallw_intra_sched_linear_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ineighbor_alltoallw-intra Algorithms", /* Category Name */
         "Number of calls to ineighbor_alltoallw_intra_sched_linear" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ineighbor_alltoallw_intra_tsp_linear_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "ineighbor_alltoallw-intra Algorithms", /* Category Name */
         "Number of calls to ineighbor_alltoallw_intra_tsp_linear" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_barrier_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Barrier Collective", /* Category Name */
         "Number of calls to Barrier" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_barrier_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Barrier Collective", /* Category Name */
         "Total time spent in Barrier" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ibarrier_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Ibarrier Collective", /* Category Name */
         "Number of calls to Ibarrier" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_ibarrier_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Ibarrier Collective", /* Category Name */
         "Total time spent in Ibarrier" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_bcast_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Bcast Collective", /* Category Name */
         "Number of calls to Bcast" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_bcast_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Bcast Collective", /* Category Name */
         "Total time spent in Bcast" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ibcast_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Ibcast Collective", /* Category Name */
         "Number of calls to Ibcast" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_ibcast_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Ibcast Collective", /* Category Name */
         "Total time spent in Ibcast" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_gather_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Gather Collective", /* Category Name */
         "Number of calls to Gather" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_gather_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Gather Collective", /* Category Name */
         "Total time spent in Gather" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_igather_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Igather Collective", /* Category Name */
         "Number of calls to Igather" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_igather_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Igather Collective", /* Category Name */
         "Total time spent in Igather" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_gatherv_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Gatherv Collective", /* Category Name */
         "Number of calls to Gatherv" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_gatherv_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Gatherv Collective", /* Category Name */
         "Total time spent in Gatherv" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_igatherv_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Igatherv Collective", /* Category Name */
         "Number of calls to Igatherv" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_igatherv_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Igatherv Collective", /* Category Name */
         "Total time spent in Igatherv" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_scatter_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Scatter Collective", /* Category Name */
         "Number of calls to Scatter" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_scatter_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Scatter Collective", /* Category Name */
         "Total time spent in Scatter" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iscatter_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Iscatter Collective", /* Category Name */
         "Number of calls to Iscatter" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_iscatter_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Iscatter Collective", /* Category Name */
         "Total time spent in Iscatter" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_scatterv_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Scatterv Collective", /* Category Name */
         "Number of calls to Scatterv" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_scatterv_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Scatterv Collective", /* Category Name */
         "Total time spent in Scatterv" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iscatterv_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Iscatterv Collective", /* Category Name */
         "Number of calls to Iscatterv" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_iscatterv_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Iscatterv Collective", /* Category Name */
         "Total time spent in Iscatterv" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_allgather_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Allgather Collective", /* Category Name */
         "Number of calls to Allgather" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_allgather_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Allgather Collective", /* Category Name */
         "Total time spent in Allgather" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iallgather_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Iallgather Collective", /* Category Name */
         "Number of calls to Iallgather" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_iallgather_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Iallgather Collective", /* Category Name */
         "Total time spent in Iallgather" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_allgatherv_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Allgatherv Collective", /* Category Name */
         "Number of calls to Allgatherv" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_allgatherv_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Allgatherv Collective", /* Category Name */
         "Total time spent in Allgatherv" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iallgatherv_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Iallgatherv Collective", /* Category Name */
         "Number of calls to Iallgatherv" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_iallgatherv_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Iallgatherv Collective", /* Category Name */
         "Total time spent in Iallgatherv" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_alltoall_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Alltoall Collective", /* Category Name */
         "Number of calls to Alltoall" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_alltoall_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Alltoall Collective", /* Category Name */
         "Total time spent in Alltoall" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ialltoall_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Ialltoall Collective", /* Category Name */
         "Number of calls to Ialltoall" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_ialltoall_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Ialltoall Collective", /* Category Name */
         "Total time spent in Ialltoall" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_alltoallv_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Alltoallv Collective", /* Category Name */
         "Number of calls to Alltoallv" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_alltoallv_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Alltoallv Collective", /* Category Name */
         "Total time spent in Alltoallv" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ialltoallv_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Ialltoallv Collective", /* Category Name */
         "Number of calls to Ialltoallv" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_ialltoallv_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Ialltoallv Collective", /* Category Name */
         "Total time spent in Ialltoallv" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_alltoallw_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Alltoallw Collective", /* Category Name */
         "Number of calls to Alltoallw" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_alltoallw_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Alltoallw Collective", /* Category Name */
         "Total time spent in Alltoallw" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ialltoallw_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Ialltoallw Collective", /* Category Name */
         "Number of calls to Ialltoallw" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_ialltoallw_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Ialltoallw Collective", /* Category Name */
         "Total time spent in Ialltoallw" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_reduce_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Reduce Collective", /* Category Name */
         "Number of calls to Reduce" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_reduce_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Reduce Collective", /* Category Name */
         "Total time spent in Reduce" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ireduce_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Ireduce Collective", /* Category Name */
         "Number of calls to Ireduce" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_ireduce_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Ireduce Collective", /* Category Name */
         "Total time spent in Ireduce" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_allreduce_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Allreduce Collective", /* Category Name */
         "Number of calls to Allreduce" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_allreduce_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Allreduce Collective", /* Category Name */
         "Total time spent in Allreduce" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iallreduce_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Iallreduce Collective", /* Category Name */
         "Number of calls to Iallreduce" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_iallreduce_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Iallreduce Collective", /* Category Name */
         "Total time spent in Iallreduce" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_reduce_scatter_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Reduce_scatter Collective", /* Category Name */
         "Number of calls to Reduce_scatter" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_reduce_scatter_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Reduce_scatter Collective", /* Category Name */
         "Total time spent in Reduce_scatter" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ireduce_scatter_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Ireduce_scatter Collective", /* Category Name */
         "Number of calls to Ireduce_scatter" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_ireduce_scatter_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Ireduce_scatter Collective", /* Category Name */
         "Total time spent in Ireduce_scatter" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_reduce_scatter_block_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Reduce_scatter_block Collective", /* Category Name */
         "Number of calls to Reduce_scatter_block" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_reduce_scatter_block_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Reduce_scatter_block Collective", /* Category Name */
         "Total time spent in Reduce_scatter_block" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ireduce_scatter_block_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Ireduce_scatter_block Collective", /* Category Name */
         "Number of calls to Ireduce_scatter_block" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_ireduce_scatter_block_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Ireduce_scatter_block Collective", /* Category Name */
         "Total time spent in Ireduce_scatter_block" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_scan_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Scan Collective", /* Category Name */
         "Number of calls to Scan" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_scan_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Scan Collective", /* Category Name */
         "Total time spent in Scan" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iscan_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Iscan Collective", /* Category Name */
         "Number of calls to Iscan" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_iscan_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Iscan Collective", /* Category Name */
         "Total time spent in Iscan" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_exscan_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Exscan Collective", /* Category Name */
         "Number of calls to Exscan" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_exscan_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Exscan Collective", /* Category Name */
         "Total time spent in Exscan" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_iexscan_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Iexscan Collective", /* Category Name */
         "Number of calls to Iexscan" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_iexscan_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Iexscan Collective", /* Category Name */
         "Total time spent in Iexscan" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_neighbor_allgather_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Neighbor_allgather Collective", /* Category Name */
         "Number of calls to Neighbor_allgather" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_neighbor_allgather_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Neighbor_allgather Collective", /* Category Name */
         "Total time spent in Neighbor_allgather" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ineighbor_allgather_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Ineighbor_allgather Collective", /* Category Name */
         "Number of calls to Ineighbor_allgather" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_ineighbor_allgather_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Ineighbor_allgather Collective", /* Category Name */
         "Total time spent in Ineighbor_allgather" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_neighbor_allgatherv_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Neighbor_allgatherv Collective", /* Category Name */
         "Number of calls to Neighbor_allgatherv" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_neighbor_allgatherv_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Neighbor_allgatherv Collective", /* Category Name */
         "Total time spent in Neighbor_allgatherv" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ineighbor_allgatherv_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Ineighbor_allgatherv Collective", /* Category Name */
         "Number of calls to Ineighbor_allgatherv" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_ineighbor_allgatherv_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Ineighbor_allgatherv Collective", /* Category Name */
         "Total time spent in Ineighbor_allgatherv" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_neighbor_alltoall_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Neighbor_alltoall Collective", /* Category Name */
         "Number of calls to Neighbor_alltoall" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_neighbor_alltoall_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Neighbor_alltoall Collective", /* Category Name */
         "Total time spent in Neighbor_alltoall" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ineighbor_alltoall_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Ineighbor_alltoall Collective", /* Category Name */
         "Number of calls to Ineighbor_alltoall" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_ineighbor_alltoall_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Ineighbor_alltoall Collective", /* Category Name */
         "Total time spent in Ineighbor_alltoall" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_neighbor_alltoallv_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Neighbor_alltoallv Collective", /* Category Name */
         "Number of calls to Neighbor_alltoallv" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_neighbor_alltoallv_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Neighbor_alltoallv Collective", /* Category Name */
         "Total time spent in Neighbor_alltoallv" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ineighbor_alltoallv_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Ineighbor_alltoallv Collective", /* Category Name */
         "Number of calls to Ineighbor_alltoallv" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_ineighbor_alltoallv_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Ineighbor_alltoallv Collective", /* Category Name */
         "Total time spent in Ineighbor_alltoallv" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_neighbor_alltoallw_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Neighbor_alltoallw Collective", /* Category Name */
         "Number of calls to Neighbor_alltoallw" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_neighbor_alltoallw_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Neighbor_alltoallw Collective", /* Category Name */
         "Total time spent in Neighbor_alltoallw" /* Description */);
     MPIR_T_PVAR_COUNTER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_UNSIGNED_LONG_LONG, /* Datatype */
         mvp_ineighbor_alltoallw_call_counter, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         (MPIR_T_PVAR_FLAG_READONLY | MPIR_T_PVAR_FLAG_SUM), /* Flags */
         "Ineighbor_alltoallw Collective", /* Category Name */
         "Number of calls to Ineighbor_alltoallw" /* Description */);
     MPIR_T_PVAR_TIMER_REGISTER_STATIC(
         MVP, /* Module */
         MPI_DOUBLE, /* Datatype */
         mvp_ineighbor_alltoallw_timer, /* Name */
         MPI_T_VERBOSITY_USER_BASIC, /* Verbosity */
         MPI_T_BIND_NO_OBJECT, /* Bind */
         MPIR_T_PVAR_FLAG_SUM, /* Flags */
         "Ineighbor_alltoallw Collective", /* Category Name */
         "Total time spent in Ineighbor_alltoallw" /* Description */);

}
#endif /* ENABLE_PVAR_MVP */
