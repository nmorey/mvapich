/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* Automatically generated
 *   by:   ./maint/extractmv2cvars
 *   on:   Mon Aug 15 15:07:19 2022 UTC
 *
 * DO NOT EDIT!!!
 */

#if !defined(MV2_CVARS_H_INCLUDED)
#define MV2_CVARS_H_INCLUDED

#include "mpitimpl.h" /* for MPIR_T_cvar_range_value_t */

/* Initializes cvar values from the environment */
int MPIR_T_MV2_cvar_init(void);
int MPIR_T_MV2_cvar_finalize(void);

/* Extern declarations for each cvar
 * (definitions in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/util/mv2_cvars.c) */

/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/allgather/allgather_osu.c */
extern int MV2_ALLGATHER_BRUCK_THRESHOLD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/allgather/allgather_osu.c */
extern int MV2_ALLGATHER_RD_THRESHOLD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/allgather/allgather_osu.c */
extern int MV2_ALLGATHER_REVERSE_RANKING;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/allgatherv/allgatherv_osu.c */
extern int MV2_ALLGATHERV_RD_THRESHOLD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/allreduce/allreduce_osu.c */
extern int MV2_ALLREDUCE_2LEVEL_MSG;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/allreduce/allreduce_osu.c */
extern int MV2_ALLREDUCE_SHORT_MSG;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/allreduce/allreduce_osu.c */
extern int MV2_SHMEM_ALLREDUCE_MSG;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/allreduce/allreduce_osu.c */
extern int MV2_USE_SHMEM_ALLREDUCE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/allreduce/allreduce_osu.c */
extern int MV2_USE_SOCKET_AWARE_ALLREDUCE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/allreduce/allreduce_osu.c */
extern int MV2_USE_SOCKET_AWARE_SHARP_ALLREDUCE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/allreduce/allreduce_osu.c */
extern int MV2_SOCKET_AWARE_ALLREDUCE_MAX_MSG;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/allreduce/allreduce_osu.c */
extern int MV2_SOCKET_AWARE_ALLREDUCE_MIN_MSG;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/alltoall/alltoall_osu.c */
extern int MV2_ALLTOALL_MEDIUM_MSG;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/alltoall/alltoall_osu.c */
extern int MV2_ALLTOALL_SMALL_MSG;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/alltoall/alltoall_osu.c */
extern int MV2_ALLTOALL_THROTTLE_FACTOR;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/alltoall/alltoall_osu.c */
extern int MV2_USE_XOR_ALLTOALL;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/barrier/barrier_osu.c */
extern int MV2_USE_SHMEM_BARRIER;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/barrier/barrier_osu.c */
extern int MV2_USE_SOCKET_AWARE_BARRIER;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/bcast/bcast_osu.c */
extern int MV2_BCAST_TWO_LEVEL_SYSTEM_SIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/bcast/bcast_osu.c */
extern int MV2_KNOMIAL_2LEVEL_BCAST_MESSAGE_SIZE_THRESHOLD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/bcast/bcast_osu.c */
extern int MV2_KNOMIAL_2LEVEL_BCAST_SYSTEM_SIZE_THRESHOLD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/bcast/bcast_osu.c */
extern int MV2_USE_BCAST_SHORT_MSG;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/bcast/bcast_osu.c */
extern int MV2_USE_KNOMIAL_2LEVEL_BCAST;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/bcast/bcast_osu.c */
extern int MV2_USE_KNOMIAL_INTER_LEADER_BCAST;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/bcast/bcast_osu.c */
extern int MV2_USE_SHMEM_BCAST;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/gather/gather_osu.c */
extern int MV2_GATHER_SWITCH_PT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/gather/gather_osu.c */
extern int MV2_USE_DIRECT_GATHER;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/gather/gather_osu.c */
extern int MV2_USE_DIRECT_GATHER_SYSTEM_SIZE_MEDIUM;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/gather/gather_osu.c */
extern int MV2_USE_DIRECT_GATHER_SYSTEM_SIZE_SMALL;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/gather/gather_osu.c */
extern int MV2_USE_TWO_LEVEL_GATHER;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/reduce/reduce_osu.c */
extern int MV2_INTRA_SHMEM_REDUCE_MSG;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/reduce/reduce_osu.c */
extern int MV2_REDUCE_2LEVEL_MSG;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/reduce/reduce_osu.c */
extern int MV2_REDUCE_SHORT_MSG;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/reduce/reduce_osu.c */
extern int MV2_SHMEM_REDUCE_MSG;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/reduce/reduce_osu.c */
extern int MV2_USE_SHMEM_REDUCE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/scatter/scatter_osu.c */
extern int MV2_RED_SCAT_LARGE_MSG;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/scatter/scatter_osu.c */
extern int MV2_RED_SCAT_SHORT_MSG;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/scatter/scatter_osu.c */
extern int MV2_SCATTER_MEDIUM_MSG;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/scatter/scatter_osu.c */
extern int MV2_SCATTER_SMALL_MSG;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/scatter/scatter_osu.c */
extern int MV2_USE_DIRECT_SCATTER;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/scatter/scatter_osu.c */
extern int MV2_USE_SCATTER_RD_INTER_LEADER_BCAST;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/scatter/scatter_osu.c */
extern int MV2_USE_SCATTER_RING_INTER_LEADER_BCAST;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/scatter/scatter_osu.c */
extern int MV2_USE_TWO_LEVEL_SCATTER;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/shmem/mv2_shmem_coll.c */
extern int MV2_KNOMIAL_INTER_LEADER_THRESHOLD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/shmem/mv2_shmem_coll.c */
extern int MV2_KNOMIAL_INTER_NODE_FACTOR;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/shmem/mv2_shmem_coll.c */
extern int MV2_KNOMIAL_INTRA_NODE_FACTOR;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/shmem/mv2_shmem_coll.c */
extern int MV2_KNOMIAL_INTRA_NODE_THRESHOLD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/shmem/mv2_shmem_coll.c */
extern int MV2_SHMEM_COLL_MAX_MSG_SIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/shmem/mv2_shmem_coll.c */
extern int MV2_SHMEM_COLL_NUM_COMM;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/shmem/mv2_shmem_coll.c */
extern int MV2_SHMEM_COLL_NUM_PROCS;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/shmem/mv2_shmem_coll.c */
extern int MV2_SHMEM_COLL_SPIN_COUNT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/shmem/mv2_shmem_coll.c */
extern int MV2_USE_OSU_COLLECTIVES;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/shmem/mv2_shmem_coll.c */
extern int MV2_USE_OSU_NB_COLLECTIVES;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/shmem/mv2_shmem_coll.c */
extern int MV2_USE_SHMEM_COLL;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpi/coll/shmem/mv2_shmem_coll.c */
extern int MV2_ENABLE_SOCKET_AWARE_COLLECTIVES;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/common/src/affinity/hwloc_bind.c */
extern const char * MV2_CPU_BINDING_LEVEL;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/common/src/affinity/hwloc_bind.c */
extern const char * MV2_CPU_MAPPING;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/common/src/affinity/hwloc_bind.c */
extern int MV2_ENABLE_AFFINITY;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/common/src/affinity/hwloc_bind.c */
extern int MV2_ENABLE_LEASTLOAD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/common/src/affinity/hwloc_bind.c */
extern const char * MV2_CPU_BINDING_POLICY;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/common/src/cm/cm.c */
extern int MV2_CM_MAX_SPIN_COUNT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/common/src/cm/cm.c */
extern int MV2_CM_RECV_BUFFERS;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/common/src/cm/cm.c */
extern int MV2_CM_SEND_DEPTH;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/common/src/cm/cm.c */
extern int MV2_CM_TIMEOUT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/common/src/cm/cm.c */
extern int MV2_CM_UD_PSN;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/common/src/cm/cm.c */
extern int MV2_CM_THREAD_STACKSIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/common/src/detect/hca/mv2_hca_detect.c */
extern int MV2_FORCE_HCA_TYPE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/common/src/detect/hca/mv2_hca_detect.c */
extern int MV2_HCA_AWARE_PROCESS_MAPPING;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/common/src/rdma_cm/rdma_cm.c */
extern int MV2_RDMA_CM_ARP_TIMEOUT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/common/src/rdma_cm/rdma_cm.c */
extern int MV2_RDMA_CM_PORT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/common/src/rdma_cm/rdma_cm.c */
extern int MV2_RDMA_CM_MAX_PORT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/common/src/rdma_cm/rdma_cm.c */
extern int MV2_RDMA_CM_MIN_PORT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_ipc.c */
extern const char * MV2_SHMEM_DIR;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_EAGER_CUDAHOST_REG;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_VECTOR_OPT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_KERNEL_OPT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_KERNEL_VECTOR_TIDBLK_SIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_KERNEL_VECTOR_YSIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_KERNEL_SUBARR_TIDBLK_SIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_KERNEL_SUBARR_XDIM;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_KERNEL_SUBARR_YDIM;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_KERNEL_SUBARR_ZDIM;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_NUM_EVENTS;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_INIT_CONTEXT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CHECK_CUDA_ATTRIBUTE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_USE_NAIVE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_ALLTOALL_DYNAMIC;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_REGISTER_NAIVE_BUF;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_GATHER_NAIVE_LIMIT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_SCATTER_NAIVE_LIMIT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_ALLTOALL_NAIVE_LIMIT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_ALLTOALLV_NAIVE_LIMIT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_ALLGATHER_NAIVE_LIMIT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_ALLGATHERV_NAIVE_LIMIT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_BCAST_NAIVE_LIMIT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_GATHERV_NAIVE_LIMIT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_SCATTERV_NAIVE_LIMIT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_ALLGATHER_RD_LIMIT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_ALLGATHER_FGP;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_IPC;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_IPC_SHARE_GPU;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_SMP_IPC;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_ENABLE_IPC_CACHE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_IPC_MAX_CACHE_ENTRIES;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_IPC_NUM_STAGE_BUFFERS;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_IPC_STAGE_BUF_SIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_IPC_BUFFERED;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_IPC_THRESHOLD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_IPC_BUFFERED_LIMIT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_IPC_SYNC_LIMIT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_DYNAMIC_INIT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_cuda_util.c */
extern int MV2_CUDA_NONBLOCKING_STREAMS;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_SMP_EAGERSIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern const char * MV2_IBA_HCA;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_SMP_USE_CMA;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_SMP_USE_LIMIC2;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_SMP_POLLING_THRESHOLD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_SMP_CMA_MAX_SIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_SMP_LIMIC2_MAX_SIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_SMP_QUEUE_LENGTH;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_LIMIC_PUT_THRESHOLD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_LIMIC_GET_THRESHOLD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_R3_THRESHOLD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_INTRA_NODE_R3_THRESHOLD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_INTER_NODE_R3_THRESHOLD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_R3_NOCACHE_THRESHOLD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_MAX_R3_PENDING_DATA;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_USE_LIMIC2_COLL;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_SMP_USE_MAX_SWITCH;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_CUDA_SMP_PIPELINE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_SMP_DELAY_SHMEM_POOL_INIT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_SMP_PRIORITY_POLLING;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_SMP_NUM_SEND_BUFFER;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_SMP_BATCH_SIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_SMP_SEND_BUF_SIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_USE_OPT_EAGER_RECV;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_NUM_NODES_IN_JOB;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_USE_MCAST;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_USE_RDMA_CM_MCAST;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_USE_QOS;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_3DTORUS_SUPPORT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_PATH_SL_QUERY;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_NUM_SLS;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_NUM_SA_QUERY_RETRIES;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_MAX_RDMA_CONNECT_ATTEMPTS;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_RDMA_CM_CONNECT_RETRY_INTERVAL;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_USE_HSAM;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_USE_APM;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_USE_APM_TEST;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_USE_IWARP_MODE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_USE_RDMA_CM;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_RDMA_CM_MULTI_SUBNET_SUPPORT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_SUPPORT_DPM;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_ON_DEMAND_THRESHOLD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_USE_XRC;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_USE_SRQ;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_IWARP_MULTIPLE_CQ_THRESHOLD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_USE_LAZY_MEM_UNREGISTER;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_USE_RMA_FAST_PATH;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_FORCE_IB_ATOMIC;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_USE_RDMA_ONE_SIDED;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_RNDV_EXT_SENDQ_SIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_RDMA_NUM_EXTRA_POLLS;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_COALESCE_THRESHOLD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_USE_COALESCE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_SPIN_COUNT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern const char * MV2_PROCESS_TO_RAIL_MAPPING;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern const char * MV2_SM_SCHEDULING;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern const char * MV2_SMALL_MSG_RAIL_SHARING_POLICY;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern const char * MV2_MED_MSG_RAIL_SHARING_POLICY;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern const char * MV2_RAIL_SHARING_POLICY;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern const char * MV2_RNDV_PROTOCOL;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern const char * MV2_SMP_RNDV_PROTOCOL;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_SUPPRESS_JOB_STARTUP_PERFORMANCE_WARNING;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_USE_RDMA_FAST_PATH;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_RDMA_FAST_PATH_BUF_SIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_POLLING_SET_LIMIT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_POLLING_SET_THRESHOLD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_RDMA_EAGER_LIMIT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_NUM_RDMA_BUFFER;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_RDMA_FAST_PATH_PREALLOCATE_BUFFERS;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_SYSREPORT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern const char * MV2_DEFAULT_MTU;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_NUM_CQES_PER_POLL;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_NUM_PORTS;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_NUM_QP_PER_PORT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_PIN_POOL_SIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_DEFAULT_MAX_CQ_SIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_IBA_EAGER_THRESHOLD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_STRIPING_THRESHOLD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_RAIL_SHARING_MED_MSG_THRESHOLD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_RAIL_SHARING_LARGE_MSG_THRESHOLD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_DEFAULT_PUT_GET_LIST_SIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_EAGERSIZE_1SC;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_PUT_FALLBACK_THRESHOLD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_GET_FALLBACK_THRESHOLD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_DEFAULT_QP_OUS_RD_ATOM;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_DEFAULT_MAX_RDMA_DST_OPS;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_DEFAULT_PSN;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern const char * MV2_DEFAULT_PKEY;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern const char * MV2_DEFAULT_QKEY;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_DEFAULT_MIN_RNR_TIMER;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_DEFAULT_SERVICE_LEVEL;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_DEFAULT_TIME_OUT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_DEFAULT_STATIC_RATE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_DEFAULT_SRC_PATH_BITS;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_DEFAULT_RETRY_COUNT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_DEFAULT_RNR_RETRY;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_DEFAULT_MAX_SG_LIST;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_DEFAULT_MAX_SEND_WQE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_CM_WAIT_TIME;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_USE_UD_HYBRID;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_UD_MTU;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_HYBRID_MAX_RC_CONN;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_UD_NUM_MSG_LIMIT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_UD_SENDWINDOW_SIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_UD_RECVWINDOW_SIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_UD_RETRY_TIMEOUT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_UD_MAX_RETRY_TIMEOUT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_UD_PROGRESS_SPIN;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_UD_RETRY_COUNT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_UD_PROGRESS_TIMEOUT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_UD_MAX_SEND_WQE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_UD_MAX_RECV_WQE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_USE_UD_SRQ;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_UD_VBUF_POOL_SIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_UD_MAX_ACK_PENDING;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_SHMEM_BACKED_UD_CM;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_USE_UD_ZCOPY;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_UD_ZCOPY_THRESHOLD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_UD_NUM_ZCOPY_RNDV_QPS;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_UD_ZCOPY_RQ_SIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_UD_ZCOPY_NUM_RETRY;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_UD_ZCOPY_ENABLE_POLLING;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_UD_ZCOPY_PUSH_SEGMENT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_UD_DROP_PACKET_RATE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_MCAST_ENABLE_REL;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_MCAST_USE_MCAST_NACK;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_MCAST_NUM_NODES_THRESHOLD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_MCAST_MAX_RECV_WQE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_MCAST_WINDOW_SIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_MCAST_DROP_PACKET_RATE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_MCAST_RETRY_TIMEOUT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_MCAST_MAX_RETRY_TIMEOUT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_MCAST_NSPIN_THRESHOLD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_MCAST_COMM_INIT_TIMEOUT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_MCAST_COMM_INIT_RETRIES;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_MCAST_SKIP_LOOPBACK;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_MCAST_BCAST_MIN_MSG;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_MCAST_BCAST_MAX_MSG;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_DEFAULT_MAX_RECV_WQE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_NDREG_ENTRIES_MAX;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_NDREG_ENTRIES;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_DREG_CACHE_LIMIT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_USE_HWLOC_CPU_BINDING;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_THREAD_YIELD_SPIN_THRESHOLD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_USE_THREAD_YIELD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_NUM_SPINS_BEFORE_LOCK;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_ASYNC_THREAD_STACK_SIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_USE_HUGEPAGES;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_MEMORY_OPTIMIZATION;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_SRQ_MAX_SIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_SRQ_SIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_SRQ_LIMIT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_UD_SRQ_MAX_SIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_UD_SRQ_SIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_UD_SRQ_LIMIT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_MAX_NUM_UD_VBUFS;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_MAX_INLINE_SIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_VBUF_TOTAL_SIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_VBUF_MAX;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_INITIAL_PREPOST_DEPTH;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_PREPOST_DEPTH;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_VBUF_POOL_SIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_MAX_NUM_VBUFS;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_VBUF_SECONDARY_POOL_SIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_CUDA_BLOCK_SIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_CUDA_NUM_RNDV_BLOCKS;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_MPIRUN_RSH_LAUNCH;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_USE_ROCE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_USE_ROCE_MODE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_USE_RING_STARTUP;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_ON_DEMAND_UD_INFO_EXCHANGE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_USE_PMI_IBARRIER;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_USE_PMI_IALLGATHER;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_NUM_HCAS;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ibv_param.c */
extern int MV2_HOMOGENEOUS_CLUSTER;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/mv2_mpit_cvars.c */
extern int MV2_USE_BLOCKING;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/mv2_mpit_cvars.c */
extern int MV2_USE_SHARED_MEM;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ofed_abstraction.h */
extern const char * MV2_LIBIBVERBS_PATH;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ofed_abstraction.h */
extern const char * MV2_LIBIBMAD_PATH;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ofed_abstraction.h */
extern const char * MV2_LIBIBUMAD_PATH;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ofed_abstraction.h */
extern const char * MV2_LIBRDMACM_PATH;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ofed_abstraction.h */
extern const char * MV2_LIBSHARP_PATH;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ofed_abstraction.h */
extern int MV2_ENABLE_SHARP;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/rdma_iba_priv.c */
extern int MV2_ALLOW_HETEROGENEOUS_HCA_SELECTION;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/rdma_iba_priv.c */
extern int MV2_PROCESS_PLACEMENT_AWARE_HCA_MAPPING;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ring_startup.c */
extern int MV2_DEFAULT_PORT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/gen2/ring_startup.c */
extern int MV2_DEFAULT_GID_INDEX;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/rdma/ch3_init.c */
extern int MV2_IOV_DENSITY_MIN;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/rdma/ch3_init.c */
extern int MV2_ENABLE_EAGER_THRESHOLD_REDUCTION;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/rdma/ch3_init.c */
extern int MV2_USE_EAGER_FAST_SEND;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/rdma/ch3_init.c */
extern int MV2_SUPPORT_FORK_SAFETY;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/rdma/ch3_init.c */
extern int MV2_RDMA_MAX_TRANSFER_SIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/rdma/ch3_init.c */
extern int MV2_RNDV_IMMEDIATE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/rdma/ch3_init.c */
extern int MV2_CHECK_CACHE_ALIGNMENT;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/rdma/ch3_init.c */
extern int MV2_HYBRID_ENABLE_THRESHOLD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/rdma/ch3_init.c */
extern int MV2_USE_ONLY_UD;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/rdma/ch3_init.c */
extern int MV2_SHOW_ENV_INFO;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/rdma/ch3_init.c */
extern const char * MV2_DEBUG_CORESIZE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/rdma/ch3_init.c */
extern int MV2_DEBUG_SHOW_BACKTRACE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/rdma/ch3_init.c */
extern int MV2_USE_THREAD_WARNING;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/rdma/ch3_progress.c */
extern int MV2_POLLING_LEVEL;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/rdma/ch3_smp_progress.c */
extern int MV2_WALK_SHARED_PAGES;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/rdma/ch3_smp_progress.c */
extern int MV2_SMP_PRIORITY_FACTOR;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/channels/mrail/src/rdma/ch3_smp_progress.c */
extern int MV2_USE_PT2PT_SHMEM;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch3/src/mpid_abort.c */
extern int MV2_ABORT_SLEEP_SECONDS;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch4/netmod/mv2/mv2_arch_detect.c */
extern int MV2_FORCE_ARCH_TYPE;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch4/netmod/mv2/mv2_init.c */
extern int MV2_SHOW_CPU_BINDING;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch4/netmod/mv2/mv2_init.c */
extern int MV2_SHOW_HCA_BINDING;
/* declared in /tmp/kbVZIP5kb7/mvapich2-3.0a/maint/../src/mpid/ch4/netmod/mv2/mv2_init.c */
extern int MV2_SHOW_HW_BINDING;

/* TODO: this should be defined elsewhere */
#define MV2_assert MPIR_Assert

/* Arbitrary, simplifies interaction with external interfaces like MPI_T_ */
#define MV2_MAX_STRLEN (384)

/* Shortens enum value comparisons */
#define MV2_ENUM_IS(A, a) (MV2_ ## A == MV2_ ## A ## _ ## a)

#endif /* MV2_CVARS_H_INCLUDED */
