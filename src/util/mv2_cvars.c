/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */
/* automatically generated
 *   by:   ./maint/extractmv2cvars
 *   at:   Mon Aug 15 15:07:19 2022 UTC
 *
 * DO NOT EDIT!!!
 */

#include "mpiimpl.h"

/* Actual storage for cvars */
int MV2_ALLGATHER_BRUCK_THRESHOLD;
int MV2_ALLGATHER_RD_THRESHOLD;
int MV2_ALLGATHER_REVERSE_RANKING;
int MV2_ALLGATHERV_RD_THRESHOLD;
int MV2_ALLREDUCE_2LEVEL_MSG;
int MV2_ALLREDUCE_SHORT_MSG;
int MV2_SHMEM_ALLREDUCE_MSG;
int MV2_USE_SHMEM_ALLREDUCE;
int MV2_USE_SOCKET_AWARE_ALLREDUCE;
int MV2_USE_SOCKET_AWARE_SHARP_ALLREDUCE;
int MV2_SOCKET_AWARE_ALLREDUCE_MAX_MSG;
int MV2_SOCKET_AWARE_ALLREDUCE_MIN_MSG;
int MV2_ALLTOALL_MEDIUM_MSG;
int MV2_ALLTOALL_SMALL_MSG;
int MV2_ALLTOALL_THROTTLE_FACTOR;
int MV2_USE_XOR_ALLTOALL;
int MV2_USE_SHMEM_BARRIER;
int MV2_USE_SOCKET_AWARE_BARRIER;
int MV2_BCAST_TWO_LEVEL_SYSTEM_SIZE;
int MV2_KNOMIAL_2LEVEL_BCAST_MESSAGE_SIZE_THRESHOLD;
int MV2_KNOMIAL_2LEVEL_BCAST_SYSTEM_SIZE_THRESHOLD;
int MV2_USE_BCAST_SHORT_MSG;
int MV2_USE_KNOMIAL_2LEVEL_BCAST;
int MV2_USE_KNOMIAL_INTER_LEADER_BCAST;
int MV2_USE_SHMEM_BCAST;
int MV2_GATHER_SWITCH_PT;
int MV2_USE_DIRECT_GATHER;
int MV2_USE_DIRECT_GATHER_SYSTEM_SIZE_MEDIUM;
int MV2_USE_DIRECT_GATHER_SYSTEM_SIZE_SMALL;
int MV2_USE_TWO_LEVEL_GATHER;
int MV2_INTRA_SHMEM_REDUCE_MSG;
int MV2_REDUCE_2LEVEL_MSG;
int MV2_REDUCE_SHORT_MSG;
int MV2_SHMEM_REDUCE_MSG;
int MV2_USE_SHMEM_REDUCE;
int MV2_RED_SCAT_LARGE_MSG;
int MV2_RED_SCAT_SHORT_MSG;
int MV2_SCATTER_MEDIUM_MSG;
int MV2_SCATTER_SMALL_MSG;
int MV2_USE_DIRECT_SCATTER;
int MV2_USE_SCATTER_RD_INTER_LEADER_BCAST;
int MV2_USE_SCATTER_RING_INTER_LEADER_BCAST;
int MV2_USE_TWO_LEVEL_SCATTER;
int MV2_KNOMIAL_INTER_LEADER_THRESHOLD;
int MV2_KNOMIAL_INTER_NODE_FACTOR;
int MV2_KNOMIAL_INTRA_NODE_FACTOR;
int MV2_KNOMIAL_INTRA_NODE_THRESHOLD;
int MV2_SHMEM_COLL_MAX_MSG_SIZE;
int MV2_SHMEM_COLL_NUM_COMM;
int MV2_SHMEM_COLL_NUM_PROCS;
int MV2_SHMEM_COLL_SPIN_COUNT;
int MV2_USE_OSU_COLLECTIVES;
int MV2_USE_OSU_NB_COLLECTIVES;
int MV2_USE_SHMEM_COLL;
int MV2_ENABLE_SOCKET_AWARE_COLLECTIVES;
const char * MV2_CPU_BINDING_LEVEL;
const char * MV2_CPU_MAPPING;
int MV2_ENABLE_AFFINITY;
int MV2_ENABLE_LEASTLOAD;
const char * MV2_CPU_BINDING_POLICY;
int MV2_CM_MAX_SPIN_COUNT;
int MV2_CM_RECV_BUFFERS;
int MV2_CM_SEND_DEPTH;
int MV2_CM_TIMEOUT;
int MV2_CM_UD_PSN;
int MV2_CM_THREAD_STACKSIZE;
int MV2_FORCE_HCA_TYPE;
int MV2_HCA_AWARE_PROCESS_MAPPING;
int MV2_RDMA_CM_ARP_TIMEOUT;
int MV2_RDMA_CM_PORT;
int MV2_RDMA_CM_MAX_PORT;
int MV2_RDMA_CM_MIN_PORT;
const char * MV2_SHMEM_DIR;
int MV2_EAGER_CUDAHOST_REG;
int MV2_CUDA_VECTOR_OPT;
int MV2_CUDA_KERNEL_OPT;
int MV2_CUDA_KERNEL_VECTOR_TIDBLK_SIZE;
int MV2_CUDA_KERNEL_VECTOR_YSIZE;
int MV2_CUDA_KERNEL_SUBARR_TIDBLK_SIZE;
int MV2_CUDA_KERNEL_SUBARR_XDIM;
int MV2_CUDA_KERNEL_SUBARR_YDIM;
int MV2_CUDA_KERNEL_SUBARR_ZDIM;
int MV2_CUDA_NUM_EVENTS;
int MV2_CUDA_INIT_CONTEXT;
int MV2_CHECK_CUDA_ATTRIBUTE;
int MV2_CUDA_USE_NAIVE;
int MV2_CUDA_ALLTOALL_DYNAMIC;
int MV2_CUDA_REGISTER_NAIVE_BUF;
int MV2_CUDA_GATHER_NAIVE_LIMIT;
int MV2_CUDA_SCATTER_NAIVE_LIMIT;
int MV2_CUDA_ALLTOALL_NAIVE_LIMIT;
int MV2_CUDA_ALLTOALLV_NAIVE_LIMIT;
int MV2_CUDA_ALLGATHER_NAIVE_LIMIT;
int MV2_CUDA_ALLGATHERV_NAIVE_LIMIT;
int MV2_CUDA_BCAST_NAIVE_LIMIT;
int MV2_CUDA_GATHERV_NAIVE_LIMIT;
int MV2_CUDA_SCATTERV_NAIVE_LIMIT;
int MV2_CUDA_ALLGATHER_RD_LIMIT;
int MV2_CUDA_ALLGATHER_FGP;
int MV2_CUDA_IPC;
int MV2_CUDA_IPC_SHARE_GPU;
int MV2_CUDA_SMP_IPC;
int MV2_CUDA_ENABLE_IPC_CACHE;
int MV2_CUDA_IPC_MAX_CACHE_ENTRIES;
int MV2_CUDA_IPC_NUM_STAGE_BUFFERS;
int MV2_CUDA_IPC_STAGE_BUF_SIZE;
int MV2_CUDA_IPC_BUFFERED;
int MV2_CUDA_IPC_THRESHOLD;
int MV2_CUDA_IPC_BUFFERED_LIMIT;
int MV2_CUDA_IPC_SYNC_LIMIT;
int MV2_CUDA_DYNAMIC_INIT;
int MV2_CUDA_NONBLOCKING_STREAMS;
int MV2_SMP_EAGERSIZE;
const char * MV2_IBA_HCA;
int MV2_SMP_USE_CMA;
int MV2_SMP_USE_LIMIC2;
int MV2_SMP_POLLING_THRESHOLD;
int MV2_SMP_CMA_MAX_SIZE;
int MV2_SMP_LIMIC2_MAX_SIZE;
int MV2_SMP_QUEUE_LENGTH;
int MV2_LIMIC_PUT_THRESHOLD;
int MV2_LIMIC_GET_THRESHOLD;
int MV2_R3_THRESHOLD;
int MV2_INTRA_NODE_R3_THRESHOLD;
int MV2_INTER_NODE_R3_THRESHOLD;
int MV2_R3_NOCACHE_THRESHOLD;
int MV2_MAX_R3_PENDING_DATA;
int MV2_USE_LIMIC2_COLL;
int MV2_SMP_USE_MAX_SWITCH;
int MV2_CUDA_SMP_PIPELINE;
int MV2_SMP_DELAY_SHMEM_POOL_INIT;
int MV2_SMP_PRIORITY_POLLING;
int MV2_SMP_NUM_SEND_BUFFER;
int MV2_SMP_BATCH_SIZE;
int MV2_SMP_SEND_BUF_SIZE;
int MV2_USE_OPT_EAGER_RECV;
int MV2_NUM_NODES_IN_JOB;
int MV2_USE_MCAST;
int MV2_USE_RDMA_CM_MCAST;
int MV2_USE_QOS;
int MV2_3DTORUS_SUPPORT;
int MV2_PATH_SL_QUERY;
int MV2_NUM_SLS;
int MV2_NUM_SA_QUERY_RETRIES;
int MV2_MAX_RDMA_CONNECT_ATTEMPTS;
int MV2_RDMA_CM_CONNECT_RETRY_INTERVAL;
int MV2_USE_HSAM;
int MV2_USE_APM;
int MV2_USE_APM_TEST;
int MV2_USE_IWARP_MODE;
int MV2_USE_RDMA_CM;
int MV2_RDMA_CM_MULTI_SUBNET_SUPPORT;
int MV2_SUPPORT_DPM;
int MV2_ON_DEMAND_THRESHOLD;
int MV2_USE_XRC;
int MV2_USE_SRQ;
int MV2_IWARP_MULTIPLE_CQ_THRESHOLD;
int MV2_USE_LAZY_MEM_UNREGISTER;
int MV2_USE_RMA_FAST_PATH;
int MV2_FORCE_IB_ATOMIC;
int MV2_USE_RDMA_ONE_SIDED;
int MV2_RNDV_EXT_SENDQ_SIZE;
int MV2_RDMA_NUM_EXTRA_POLLS;
int MV2_COALESCE_THRESHOLD;
int MV2_USE_COALESCE;
int MV2_SPIN_COUNT;
const char * MV2_PROCESS_TO_RAIL_MAPPING;
const char * MV2_SM_SCHEDULING;
const char * MV2_SMALL_MSG_RAIL_SHARING_POLICY;
const char * MV2_MED_MSG_RAIL_SHARING_POLICY;
const char * MV2_RAIL_SHARING_POLICY;
const char * MV2_RNDV_PROTOCOL;
const char * MV2_SMP_RNDV_PROTOCOL;
int MV2_SUPPRESS_JOB_STARTUP_PERFORMANCE_WARNING;
int MV2_USE_RDMA_FAST_PATH;
int MV2_RDMA_FAST_PATH_BUF_SIZE;
int MV2_POLLING_SET_LIMIT;
int MV2_POLLING_SET_THRESHOLD;
int MV2_RDMA_EAGER_LIMIT;
int MV2_NUM_RDMA_BUFFER;
int MV2_RDMA_FAST_PATH_PREALLOCATE_BUFFERS;
int MV2_SYSREPORT;
const char * MV2_DEFAULT_MTU;
int MV2_NUM_CQES_PER_POLL;
int MV2_NUM_PORTS;
int MV2_NUM_QP_PER_PORT;
int MV2_PIN_POOL_SIZE;
int MV2_DEFAULT_MAX_CQ_SIZE;
int MV2_IBA_EAGER_THRESHOLD;
int MV2_STRIPING_THRESHOLD;
int MV2_RAIL_SHARING_MED_MSG_THRESHOLD;
int MV2_RAIL_SHARING_LARGE_MSG_THRESHOLD;
int MV2_DEFAULT_PUT_GET_LIST_SIZE;
int MV2_EAGERSIZE_1SC;
int MV2_PUT_FALLBACK_THRESHOLD;
int MV2_GET_FALLBACK_THRESHOLD;
int MV2_DEFAULT_QP_OUS_RD_ATOM;
int MV2_DEFAULT_MAX_RDMA_DST_OPS;
int MV2_DEFAULT_PSN;
const char * MV2_DEFAULT_PKEY;
const char * MV2_DEFAULT_QKEY;
int MV2_DEFAULT_MIN_RNR_TIMER;
int MV2_DEFAULT_SERVICE_LEVEL;
int MV2_DEFAULT_TIME_OUT;
int MV2_DEFAULT_STATIC_RATE;
int MV2_DEFAULT_SRC_PATH_BITS;
int MV2_DEFAULT_RETRY_COUNT;
int MV2_DEFAULT_RNR_RETRY;
int MV2_DEFAULT_MAX_SG_LIST;
int MV2_DEFAULT_MAX_SEND_WQE;
int MV2_CM_WAIT_TIME;
int MV2_USE_UD_HYBRID;
int MV2_UD_MTU;
int MV2_HYBRID_MAX_RC_CONN;
int MV2_UD_NUM_MSG_LIMIT;
int MV2_UD_SENDWINDOW_SIZE;
int MV2_UD_RECVWINDOW_SIZE;
int MV2_UD_RETRY_TIMEOUT;
int MV2_UD_MAX_RETRY_TIMEOUT;
int MV2_UD_PROGRESS_SPIN;
int MV2_UD_RETRY_COUNT;
int MV2_UD_PROGRESS_TIMEOUT;
int MV2_UD_MAX_SEND_WQE;
int MV2_UD_MAX_RECV_WQE;
int MV2_USE_UD_SRQ;
int MV2_UD_VBUF_POOL_SIZE;
int MV2_UD_MAX_ACK_PENDING;
int MV2_SHMEM_BACKED_UD_CM;
int MV2_USE_UD_ZCOPY;
int MV2_UD_ZCOPY_THRESHOLD;
int MV2_UD_NUM_ZCOPY_RNDV_QPS;
int MV2_UD_ZCOPY_RQ_SIZE;
int MV2_UD_ZCOPY_NUM_RETRY;
int MV2_UD_ZCOPY_ENABLE_POLLING;
int MV2_UD_ZCOPY_PUSH_SEGMENT;
int MV2_UD_DROP_PACKET_RATE;
int MV2_MCAST_ENABLE_REL;
int MV2_MCAST_USE_MCAST_NACK;
int MV2_MCAST_NUM_NODES_THRESHOLD;
int MV2_MCAST_MAX_RECV_WQE;
int MV2_MCAST_WINDOW_SIZE;
int MV2_MCAST_DROP_PACKET_RATE;
int MV2_MCAST_RETRY_TIMEOUT;
int MV2_MCAST_MAX_RETRY_TIMEOUT;
int MV2_MCAST_NSPIN_THRESHOLD;
int MV2_MCAST_COMM_INIT_TIMEOUT;
int MV2_MCAST_COMM_INIT_RETRIES;
int MV2_MCAST_SKIP_LOOPBACK;
int MV2_MCAST_BCAST_MIN_MSG;
int MV2_MCAST_BCAST_MAX_MSG;
int MV2_DEFAULT_MAX_RECV_WQE;
int MV2_NDREG_ENTRIES_MAX;
int MV2_NDREG_ENTRIES;
int MV2_DREG_CACHE_LIMIT;
int MV2_USE_HWLOC_CPU_BINDING;
int MV2_THREAD_YIELD_SPIN_THRESHOLD;
int MV2_USE_THREAD_YIELD;
int MV2_NUM_SPINS_BEFORE_LOCK;
int MV2_ASYNC_THREAD_STACK_SIZE;
int MV2_USE_HUGEPAGES;
int MV2_MEMORY_OPTIMIZATION;
int MV2_SRQ_MAX_SIZE;
int MV2_SRQ_SIZE;
int MV2_SRQ_LIMIT;
int MV2_UD_SRQ_MAX_SIZE;
int MV2_UD_SRQ_SIZE;
int MV2_UD_SRQ_LIMIT;
int MV2_MAX_NUM_UD_VBUFS;
int MV2_MAX_INLINE_SIZE;
int MV2_VBUF_TOTAL_SIZE;
int MV2_VBUF_MAX;
int MV2_INITIAL_PREPOST_DEPTH;
int MV2_PREPOST_DEPTH;
int MV2_VBUF_POOL_SIZE;
int MV2_MAX_NUM_VBUFS;
int MV2_VBUF_SECONDARY_POOL_SIZE;
int MV2_CUDA_BLOCK_SIZE;
int MV2_CUDA_NUM_RNDV_BLOCKS;
int MV2_MPIRUN_RSH_LAUNCH;
int MV2_USE_ROCE;
int MV2_USE_ROCE_MODE;
int MV2_USE_RING_STARTUP;
int MV2_ON_DEMAND_UD_INFO_EXCHANGE;
int MV2_USE_PMI_IBARRIER;
int MV2_USE_PMI_IALLGATHER;
int MV2_NUM_HCAS;
int MV2_HOMOGENEOUS_CLUSTER;
int MV2_USE_BLOCKING;
int MV2_USE_SHARED_MEM;
const char * MV2_LIBIBVERBS_PATH;
const char * MV2_LIBIBMAD_PATH;
const char * MV2_LIBIBUMAD_PATH;
const char * MV2_LIBRDMACM_PATH;
const char * MV2_LIBSHARP_PATH;
int MV2_ENABLE_SHARP;
int MV2_ALLOW_HETEROGENEOUS_HCA_SELECTION;
int MV2_PROCESS_PLACEMENT_AWARE_HCA_MAPPING;
int MV2_DEFAULT_PORT;
int MV2_DEFAULT_GID_INDEX;
int MV2_IOV_DENSITY_MIN;
int MV2_ENABLE_EAGER_THRESHOLD_REDUCTION;
int MV2_USE_EAGER_FAST_SEND;
int MV2_SUPPORT_FORK_SAFETY;
int MV2_RDMA_MAX_TRANSFER_SIZE;
int MV2_RNDV_IMMEDIATE;
int MV2_CHECK_CACHE_ALIGNMENT;
int MV2_HYBRID_ENABLE_THRESHOLD;
int MV2_USE_ONLY_UD;
int MV2_SHOW_ENV_INFO;
const char * MV2_DEBUG_CORESIZE;
int MV2_DEBUG_SHOW_BACKTRACE;
int MV2_USE_THREAD_WARNING;
int MV2_POLLING_LEVEL;
int MV2_WALK_SHARED_PAGES;
int MV2_SMP_PRIORITY_FACTOR;
int MV2_USE_PT2PT_SHMEM;
int MV2_ABORT_SLEEP_SECONDS;
int MV2_FORCE_ARCH_TYPE;
int MV2_SHOW_CPU_BINDING;
int MV2_SHOW_HCA_BINDING;
int MV2_SHOW_HW_BINDING;

int MPIR_T_MV2_cvar_init(void)
{
    int mpi_errno = MPI_SUCCESS;
    int rc;
    const char *tmp_str;
    static int initialized = FALSE;
    MPIR_T_cvar_value_t defaultval;

    /* FIXME any MT issues here? */
    if (initialized)
        return MPI_SUCCESS;
    initialized = TRUE;

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_ALLGATHER_BRUCK_THRESHOLD, /* name */
        &MV2_ALLGATHER_BRUCK_THRESHOLD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_ALLGATHER_BRUCK_THRESHOLD = defaultval.d;
    rc = MPL_env2int("UCR_ALLGATHER_BRUCK_THRESHOLD", &(MV2_ALLGATHER_BRUCK_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_ALLGATHER_BRUCK_THRESHOLD");
    rc = MPL_env2int("MV2_ALLGATHER_BRUCK_THRESHOLD", &(MV2_ALLGATHER_BRUCK_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_ALLGATHER_BRUCK_THRESHOLD");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_ALLGATHER_RD_THRESHOLD, /* name */
        &MV2_ALLGATHER_RD_THRESHOLD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_ALLGATHER_RD_THRESHOLD = defaultval.d;
    rc = MPL_env2int("UCR_ALLGATHER_RD_THRESHOLD", &(MV2_ALLGATHER_RD_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_ALLGATHER_RD_THRESHOLD");
    rc = MPL_env2int("MV2_ALLGATHER_RD_THRESHOLD", &(MV2_ALLGATHER_RD_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_ALLGATHER_RD_THRESHOLD");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_ALLGATHER_REVERSE_RANKING, /* name */
        &MV2_ALLGATHER_REVERSE_RANKING, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_ALLGATHER_REVERSE_RANKING = defaultval.d;
    rc = MPL_env2bool("UCR_ALLGATHER_REVERSE_RANKING", &(MV2_ALLGATHER_REVERSE_RANKING));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_ALLGATHER_REVERSE_RANKING");
    rc = MPL_env2bool("MV2_ALLGATHER_REVERSE_RANKING", &(MV2_ALLGATHER_REVERSE_RANKING));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_ALLGATHER_REVERSE_RANKING");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_ALLGATHERV_RD_THRESHOLD, /* name */
        &MV2_ALLGATHERV_RD_THRESHOLD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC Defaults to 0 if not specified. If specified then mv2_tune_parameter is set to 1 regardless of value.");
    MV2_ALLGATHERV_RD_THRESHOLD = defaultval.d;
    rc = MPL_env2int("UCR_ALLGATHERV_RD_THRESHOLD", &(MV2_ALLGATHERV_RD_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_ALLGATHERV_RD_THRESHOLD");
    rc = MPL_env2int("MV2_ALLGATHERV_RD_THRESHOLD", &(MV2_ALLGATHERV_RD_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_ALLGATHERV_RD_THRESHOLD");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_ALLREDUCE_2LEVEL_MSG, /* name */
        &MV2_ALLREDUCE_2LEVEL_MSG, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "This parameter can be used to determine the threshold for the 2-level Allreduce algorithm. We now use the shared-memory-based algorithm for messages smaller than the MV2_SHMEM_ALLREDUCE_MSG threshold, the 2-level algorithm for medium sized messages up to the threshold defined by this parameter. We use the default point-to-point algorithms messages larger than this threshold.");
    MV2_ALLREDUCE_2LEVEL_MSG = defaultval.d;
    rc = MPL_env2int("UCR_ALLREDUCE_2LEVEL_MSG", &(MV2_ALLREDUCE_2LEVEL_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_ALLREDUCE_2LEVEL_MSG");
    rc = MPL_env2int("MV2_ALLREDUCE_2LEVEL_MSG", &(MV2_ALLREDUCE_2LEVEL_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_ALLREDUCE_2LEVEL_MSG");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_ALLREDUCE_SHORT_MSG, /* name */
        &MV2_ALLREDUCE_SHORT_MSG, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_ALLREDUCE_SHORT_MSG = defaultval.d;
    rc = MPL_env2int("UCR_ALLREDUCE_SHORT_MSG", &(MV2_ALLREDUCE_SHORT_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_ALLREDUCE_SHORT_MSG");
    rc = MPL_env2int("MV2_ALLREDUCE_SHORT_MSG", &(MV2_ALLREDUCE_SHORT_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_ALLREDUCE_SHORT_MSG");

    defaultval.d = (1<<15);
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SHMEM_ALLREDUCE_MSG, /* name */
        &MV2_SHMEM_ALLREDUCE_MSG, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "The SHMEM AllReduce is used for messages less than this threshold.");
    MV2_SHMEM_ALLREDUCE_MSG = defaultval.d;
    rc = MPL_env2int("UCR_SHMEM_ALLREDUCE_MSG", &(MV2_SHMEM_ALLREDUCE_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SHMEM_ALLREDUCE_MSG");
    rc = MPL_env2int("MV2_SHMEM_ALLREDUCE_MSG", &(MV2_SHMEM_ALLREDUCE_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SHMEM_ALLREDUCE_MSG");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_SHMEM_ALLREDUCE, /* name */
        &MV2_USE_SHMEM_ALLREDUCE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "This parameter can be used to turn off shared memory based MPI_Allreduce for OFA-IB-CH3 over IBA by setting this to 0.");
    MV2_USE_SHMEM_ALLREDUCE = defaultval.d;
    rc = MPL_env2bool("UCR_USE_SHMEM_ALLREDUCE", &(MV2_USE_SHMEM_ALLREDUCE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_SHMEM_ALLREDUCE");
    rc = MPL_env2bool("MV2_USE_SHMEM_ALLREDUCE", &(MV2_USE_SHMEM_ALLREDUCE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_SHMEM_ALLREDUCE");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_SOCKET_AWARE_ALLREDUCE, /* name */
        &MV2_USE_SOCKET_AWARE_ALLREDUCE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_USE_SOCKET_AWARE_ALLREDUCE = defaultval.d;
    rc = MPL_env2bool("UCR_USE_SOCKET_AWARE_ALLREDUCE", &(MV2_USE_SOCKET_AWARE_ALLREDUCE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_SOCKET_AWARE_ALLREDUCE");
    rc = MPL_env2bool("MV2_USE_SOCKET_AWARE_ALLREDUCE", &(MV2_USE_SOCKET_AWARE_ALLREDUCE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_SOCKET_AWARE_ALLREDUCE");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_SOCKET_AWARE_SHARP_ALLREDUCE, /* name */
        &MV2_USE_SOCKET_AWARE_SHARP_ALLREDUCE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_USE_SOCKET_AWARE_SHARP_ALLREDUCE = defaultval.d;
    rc = MPL_env2bool("UCR_USE_SOCKET_AWARE_SHARP_ALLREDUCE", &(MV2_USE_SOCKET_AWARE_SHARP_ALLREDUCE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_SOCKET_AWARE_SHARP_ALLREDUCE");
    rc = MPL_env2bool("MV2_USE_SOCKET_AWARE_SHARP_ALLREDUCE", &(MV2_USE_SOCKET_AWARE_SHARP_ALLREDUCE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_SOCKET_AWARE_SHARP_ALLREDUCE");

    defaultval.d = 2048;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SOCKET_AWARE_ALLREDUCE_MAX_MSG, /* name */
        &MV2_SOCKET_AWARE_ALLREDUCE_MAX_MSG, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_SOCKET_AWARE_ALLREDUCE_MAX_MSG = defaultval.d;
    rc = MPL_env2int("UCR_SOCKET_AWARE_ALLREDUCE_MAX_MSG", &(MV2_SOCKET_AWARE_ALLREDUCE_MAX_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SOCKET_AWARE_ALLREDUCE_MAX_MSG");
    rc = MPL_env2int("MV2_SOCKET_AWARE_ALLREDUCE_MAX_MSG", &(MV2_SOCKET_AWARE_ALLREDUCE_MAX_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SOCKET_AWARE_ALLREDUCE_MAX_MSG");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SOCKET_AWARE_ALLREDUCE_MIN_MSG, /* name */
        &MV2_SOCKET_AWARE_ALLREDUCE_MIN_MSG, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_SOCKET_AWARE_ALLREDUCE_MIN_MSG = defaultval.d;
    rc = MPL_env2int("UCR_SOCKET_AWARE_ALLREDUCE_MIN_MSG", &(MV2_SOCKET_AWARE_ALLREDUCE_MIN_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SOCKET_AWARE_ALLREDUCE_MIN_MSG");
    rc = MPL_env2int("MV2_SOCKET_AWARE_ALLREDUCE_MIN_MSG", &(MV2_SOCKET_AWARE_ALLREDUCE_MIN_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SOCKET_AWARE_ALLREDUCE_MIN_MSG");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_ALLTOALL_MEDIUM_MSG, /* name */
        &MV2_ALLTOALL_MEDIUM_MSG, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_ALLTOALL_MEDIUM_MSG = defaultval.d;
    rc = MPL_env2int("UCR_ALLTOALL_MEDIUM_MSG", &(MV2_ALLTOALL_MEDIUM_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_ALLTOALL_MEDIUM_MSG");
    rc = MPL_env2int("MV2_ALLTOALL_MEDIUM_MSG", &(MV2_ALLTOALL_MEDIUM_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_ALLTOALL_MEDIUM_MSG");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_ALLTOALL_SMALL_MSG, /* name */
        &MV2_ALLTOALL_SMALL_MSG, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_ALLTOALL_SMALL_MSG = defaultval.d;
    rc = MPL_env2int("UCR_ALLTOALL_SMALL_MSG", &(MV2_ALLTOALL_SMALL_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_ALLTOALL_SMALL_MSG");
    rc = MPL_env2int("MV2_ALLTOALL_SMALL_MSG", &(MV2_ALLTOALL_SMALL_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_ALLTOALL_SMALL_MSG");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_ALLTOALL_THROTTLE_FACTOR, /* name */
        &MV2_ALLTOALL_THROTTLE_FACTOR, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_ALLTOALL_THROTTLE_FACTOR = defaultval.d;
    rc = MPL_env2int("UCR_ALLTOALL_THROTTLE_FACTOR", &(MV2_ALLTOALL_THROTTLE_FACTOR));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_ALLTOALL_THROTTLE_FACTOR");
    rc = MPL_env2int("MV2_ALLTOALL_THROTTLE_FACTOR", &(MV2_ALLTOALL_THROTTLE_FACTOR));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_ALLTOALL_THROTTLE_FACTOR");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_XOR_ALLTOALL, /* name */
        &MV2_USE_XOR_ALLTOALL, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_USE_XOR_ALLTOALL = defaultval.d;
    rc = MPL_env2bool("UCR_USE_XOR_ALLTOALL", &(MV2_USE_XOR_ALLTOALL));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_XOR_ALLTOALL");
    rc = MPL_env2bool("MV2_USE_XOR_ALLTOALL", &(MV2_USE_XOR_ALLTOALL));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_XOR_ALLTOALL");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_SHMEM_BARRIER, /* name */
        &MV2_USE_SHMEM_BARRIER, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "This parameter can be used to turn off shared memory based MPI_Barrier for OFA-IB-CH3 over IBA by setting this to 0.");
    MV2_USE_SHMEM_BARRIER = defaultval.d;
    rc = MPL_env2bool("UCR_USE_SHMEM_BARRIER", &(MV2_USE_SHMEM_BARRIER));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_SHMEM_BARRIER");
    rc = MPL_env2bool("MV2_USE_SHMEM_BARRIER", &(MV2_USE_SHMEM_BARRIER));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_SHMEM_BARRIER");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_SOCKET_AWARE_BARRIER, /* name */
        &MV2_USE_SOCKET_AWARE_BARRIER, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_USE_SOCKET_AWARE_BARRIER = defaultval.d;
    rc = MPL_env2bool("UCR_USE_SOCKET_AWARE_BARRIER", &(MV2_USE_SOCKET_AWARE_BARRIER));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_SOCKET_AWARE_BARRIER");
    rc = MPL_env2bool("MV2_USE_SOCKET_AWARE_BARRIER", &(MV2_USE_SOCKET_AWARE_BARRIER));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_SOCKET_AWARE_BARRIER");

    defaultval.d = 64;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_BCAST_TWO_LEVEL_SYSTEM_SIZE, /* name */
        &MV2_BCAST_TWO_LEVEL_SYSTEM_SIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_BCAST_TWO_LEVEL_SYSTEM_SIZE = defaultval.d;
    rc = MPL_env2int("UCR_BCAST_TWO_LEVEL_SYSTEM_SIZE", &(MV2_BCAST_TWO_LEVEL_SYSTEM_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_BCAST_TWO_LEVEL_SYSTEM_SIZE");
    rc = MPL_env2int("MV2_BCAST_TWO_LEVEL_SYSTEM_SIZE", &(MV2_BCAST_TWO_LEVEL_SYSTEM_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_BCAST_TWO_LEVEL_SYSTEM_SIZE");

    defaultval.d = 2048;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_KNOMIAL_2LEVEL_BCAST_MESSAGE_SIZE_THRESHOLD, /* name */
        &MV2_KNOMIAL_2LEVEL_BCAST_MESSAGE_SIZE_THRESHOLD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_KNOMIAL_2LEVEL_BCAST_MESSAGE_SIZE_THRESHOLD = defaultval.d;
    rc = MPL_env2int("UCR_KNOMIAL_2LEVEL_BCAST_MESSAGE_SIZE_THRESHOLD", &(MV2_KNOMIAL_2LEVEL_BCAST_MESSAGE_SIZE_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_KNOMIAL_2LEVEL_BCAST_MESSAGE_SIZE_THRESHOLD");
    rc = MPL_env2int("MV2_KNOMIAL_2LEVEL_BCAST_MESSAGE_SIZE_THRESHOLD", &(MV2_KNOMIAL_2LEVEL_BCAST_MESSAGE_SIZE_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_KNOMIAL_2LEVEL_BCAST_MESSAGE_SIZE_THRESHOLD");

    defaultval.d = 64;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_KNOMIAL_2LEVEL_BCAST_SYSTEM_SIZE_THRESHOLD, /* name */
        &MV2_KNOMIAL_2LEVEL_BCAST_SYSTEM_SIZE_THRESHOLD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_KNOMIAL_2LEVEL_BCAST_SYSTEM_SIZE_THRESHOLD = defaultval.d;
    rc = MPL_env2int("UCR_KNOMIAL_2LEVEL_BCAST_SYSTEM_SIZE_THRESHOLD", &(MV2_KNOMIAL_2LEVEL_BCAST_SYSTEM_SIZE_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_KNOMIAL_2LEVEL_BCAST_SYSTEM_SIZE_THRESHOLD");
    rc = MPL_env2int("MV2_KNOMIAL_2LEVEL_BCAST_SYSTEM_SIZE_THRESHOLD", &(MV2_KNOMIAL_2LEVEL_BCAST_SYSTEM_SIZE_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_KNOMIAL_2LEVEL_BCAST_SYSTEM_SIZE_THRESHOLD");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_BCAST_SHORT_MSG, /* name */
        &MV2_USE_BCAST_SHORT_MSG, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_USE_BCAST_SHORT_MSG = defaultval.d;
    rc = MPL_env2int("UCR_USE_BCAST_SHORT_MSG", &(MV2_USE_BCAST_SHORT_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_BCAST_SHORT_MSG");
    rc = MPL_env2int("MV2_USE_BCAST_SHORT_MSG", &(MV2_USE_BCAST_SHORT_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_BCAST_SHORT_MSG");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_KNOMIAL_2LEVEL_BCAST, /* name */
        &MV2_USE_KNOMIAL_2LEVEL_BCAST, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_USE_KNOMIAL_2LEVEL_BCAST = defaultval.d;
    rc = MPL_env2bool("UCR_USE_KNOMIAL_2LEVEL_BCAST", &(MV2_USE_KNOMIAL_2LEVEL_BCAST));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_KNOMIAL_2LEVEL_BCAST");
    rc = MPL_env2bool("MV2_USE_KNOMIAL_2LEVEL_BCAST", &(MV2_USE_KNOMIAL_2LEVEL_BCAST));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_KNOMIAL_2LEVEL_BCAST");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_KNOMIAL_INTER_LEADER_BCAST, /* name */
        &MV2_USE_KNOMIAL_INTER_LEADER_BCAST, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_USE_KNOMIAL_INTER_LEADER_BCAST = defaultval.d;
    rc = MPL_env2bool("UCR_USE_KNOMIAL_INTER_LEADER_BCAST", &(MV2_USE_KNOMIAL_INTER_LEADER_BCAST));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_KNOMIAL_INTER_LEADER_BCAST");
    rc = MPL_env2bool("MV2_USE_KNOMIAL_INTER_LEADER_BCAST", &(MV2_USE_KNOMIAL_INTER_LEADER_BCAST));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_KNOMIAL_INTER_LEADER_BCAST");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_SHMEM_BCAST, /* name */
        &MV2_USE_SHMEM_BCAST, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "This parameter can be used to turn off shared memory based MPI_Bcast for OFA-IB-CH3 over IBA by setting this to 0.");
    MV2_USE_SHMEM_BCAST = defaultval.d;
    rc = MPL_env2bool("UCR_USE_SHMEM_BCAST", &(MV2_USE_SHMEM_BCAST));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_SHMEM_BCAST");
    rc = MPL_env2bool("MV2_USE_SHMEM_BCAST", &(MV2_USE_SHMEM_BCAST));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_SHMEM_BCAST");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_GATHER_SWITCH_PT, /* name */
        &MV2_GATHER_SWITCH_PT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "We use different algorithms depending on the system size. For small system sizes (up to 386 cores), we use the \"2-level\" algorithm  followed by the \"Direct\" algorithm. For medium system sizes (up to 1k), we use the \"Binomial\" algorithm followed by the \"Direct\" algorithm. Users can set the switching point between algorithms using this runtime parameter.");
    MV2_GATHER_SWITCH_PT = defaultval.d;
    rc = MPL_env2int("UCR_GATHER_SWITCH_PT", &(MV2_GATHER_SWITCH_PT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_GATHER_SWITCH_PT");
    rc = MPL_env2int("MV2_GATHER_SWITCH_PT", &(MV2_GATHER_SWITCH_PT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_GATHER_SWITCH_PT");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_DIRECT_GATHER, /* name */
        &MV2_USE_DIRECT_GATHER, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "Use the \"Direct\" algorithm for the MPI_Gather operation. If this parameter is set to 0 at run-time, the \"Direct\" algorithm will not be invoked.");
    MV2_USE_DIRECT_GATHER = defaultval.d;
    rc = MPL_env2bool("UCR_USE_DIRECT_GATHER", &(MV2_USE_DIRECT_GATHER));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_DIRECT_GATHER");
    rc = MPL_env2bool("MV2_USE_DIRECT_GATHER", &(MV2_USE_DIRECT_GATHER));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_DIRECT_GATHER");

    defaultval.d = 1024;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_DIRECT_GATHER_SYSTEM_SIZE_MEDIUM, /* name */
        &MV2_USE_DIRECT_GATHER_SYSTEM_SIZE_MEDIUM, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_USE_DIRECT_GATHER_SYSTEM_SIZE_MEDIUM = defaultval.d;
    rc = MPL_env2int("UCR_USE_DIRECT_GATHER_SYSTEM_SIZE_MEDIUM", &(MV2_USE_DIRECT_GATHER_SYSTEM_SIZE_MEDIUM));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_DIRECT_GATHER_SYSTEM_SIZE_MEDIUM");
    rc = MPL_env2int("MV2_USE_DIRECT_GATHER_SYSTEM_SIZE_MEDIUM", &(MV2_USE_DIRECT_GATHER_SYSTEM_SIZE_MEDIUM));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_DIRECT_GATHER_SYSTEM_SIZE_MEDIUM");

    defaultval.d = 384;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_DIRECT_GATHER_SYSTEM_SIZE_SMALL, /* name */
        &MV2_USE_DIRECT_GATHER_SYSTEM_SIZE_SMALL, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_USE_DIRECT_GATHER_SYSTEM_SIZE_SMALL = defaultval.d;
    rc = MPL_env2int("UCR_USE_DIRECT_GATHER_SYSTEM_SIZE_SMALL", &(MV2_USE_DIRECT_GATHER_SYSTEM_SIZE_SMALL));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_DIRECT_GATHER_SYSTEM_SIZE_SMALL");
    rc = MPL_env2int("MV2_USE_DIRECT_GATHER_SYSTEM_SIZE_SMALL", &(MV2_USE_DIRECT_GATHER_SYSTEM_SIZE_SMALL));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_DIRECT_GATHER_SYSTEM_SIZE_SMALL");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_TWO_LEVEL_GATHER, /* name */
        &MV2_USE_TWO_LEVEL_GATHER, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "Use the two-level multi-core-aware algorithm for the MPI_Gather operation. If this parameter is set to 0 at run-time, the two-level algorithm will not be invoked.");
    MV2_USE_TWO_LEVEL_GATHER = defaultval.d;
    rc = MPL_env2bool("UCR_USE_TWO_LEVEL_GATHER", &(MV2_USE_TWO_LEVEL_GATHER));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_TWO_LEVEL_GATHER");
    rc = MPL_env2bool("MV2_USE_TWO_LEVEL_GATHER", &(MV2_USE_TWO_LEVEL_GATHER));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_TWO_LEVEL_GATHER");

    defaultval.d = (1<<11);
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_INTRA_SHMEM_REDUCE_MSG, /* name */
        &MV2_INTRA_SHMEM_REDUCE_MSG, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_INTRA_SHMEM_REDUCE_MSG = defaultval.d;
    rc = MPL_env2int("UCR_INTRA_SHMEM_REDUCE_MSG", &(MV2_INTRA_SHMEM_REDUCE_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_INTRA_SHMEM_REDUCE_MSG");
    rc = MPL_env2int("MV2_INTRA_SHMEM_REDUCE_MSG", &(MV2_INTRA_SHMEM_REDUCE_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_INTRA_SHMEM_REDUCE_MSG");

    defaultval.d = (1<<18);
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_REDUCE_2LEVEL_MSG, /* name */
        &MV2_REDUCE_2LEVEL_MSG, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "This parameter can be used to determine the threshold for the 2-level reduce algorithm. We now use the shared-memory-based algorithm for messages smaller than the MV2_SHMEM_REDUCE_MSG, the 2-level algorithm for medium sized messages up to the threshold defined by this parameter. We use the default point-to-point algorithms messages larger than this threshold.");
    MV2_REDUCE_2LEVEL_MSG = defaultval.d;
    rc = MPL_env2int("UCR_REDUCE_2LEVEL_MSG", &(MV2_REDUCE_2LEVEL_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_REDUCE_2LEVEL_MSG");
    rc = MPL_env2int("MV2_REDUCE_2LEVEL_MSG", &(MV2_REDUCE_2LEVEL_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_REDUCE_2LEVEL_MSG");

    defaultval.d = 2048;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_REDUCE_SHORT_MSG, /* name */
        &MV2_REDUCE_SHORT_MSG, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_REDUCE_SHORT_MSG = defaultval.d;
    rc = MPL_env2int("UCR_REDUCE_SHORT_MSG", &(MV2_REDUCE_SHORT_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_REDUCE_SHORT_MSG");
    rc = MPL_env2int("MV2_REDUCE_SHORT_MSG", &(MV2_REDUCE_SHORT_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_REDUCE_SHORT_MSG");

    defaultval.d = (1<<12);
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SHMEM_REDUCE_MSG, /* name */
        &MV2_SHMEM_REDUCE_MSG, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "The SHMEM reduce is used for messages less than this threshold.");
    MV2_SHMEM_REDUCE_MSG = defaultval.d;
    rc = MPL_env2int("UCR_SHMEM_REDUCE_MSG", &(MV2_SHMEM_REDUCE_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SHMEM_REDUCE_MSG");
    rc = MPL_env2int("MV2_SHMEM_REDUCE_MSG", &(MV2_SHMEM_REDUCE_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SHMEM_REDUCE_MSG");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_SHMEM_REDUCE, /* name */
        &MV2_USE_SHMEM_REDUCE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "This parameter can be used to turn off shared memory based MPI_Reduce for OFA-IB-CH3 over IBA by setting this to 0.");
    MV2_USE_SHMEM_REDUCE = defaultval.d;
    rc = MPL_env2bool("UCR_USE_SHMEM_REDUCE", &(MV2_USE_SHMEM_REDUCE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_SHMEM_REDUCE");
    rc = MPL_env2bool("MV2_USE_SHMEM_REDUCE", &(MV2_USE_SHMEM_REDUCE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_SHMEM_REDUCE");

    defaultval.d = (512*1024);
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_RED_SCAT_LARGE_MSG, /* name */
        &MV2_RED_SCAT_LARGE_MSG, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_RED_SCAT_LARGE_MSG = defaultval.d;
    rc = MPL_env2int("UCR_RED_SCAT_LARGE_MSG", &(MV2_RED_SCAT_LARGE_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_RED_SCAT_LARGE_MSG");
    rc = MPL_env2int("MV2_RED_SCAT_LARGE_MSG", &(MV2_RED_SCAT_LARGE_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_RED_SCAT_LARGE_MSG");

    defaultval.d = 64;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_RED_SCAT_SHORT_MSG, /* name */
        &MV2_RED_SCAT_SHORT_MSG, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_RED_SCAT_SHORT_MSG = defaultval.d;
    rc = MPL_env2int("UCR_RED_SCAT_SHORT_MSG", &(MV2_RED_SCAT_SHORT_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_RED_SCAT_SHORT_MSG");
    rc = MPL_env2int("MV2_RED_SCAT_SHORT_MSG", &(MV2_RED_SCAT_SHORT_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_RED_SCAT_SHORT_MSG");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SCATTER_MEDIUM_MSG, /* name */
        &MV2_SCATTER_MEDIUM_MSG, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "When the system size is lower than 512 cores, we use the \"2-level\" algorithm for medium message sizes. This allows the user to set the threshold for medium messages. -1 indicates allowing the default values to be used. ");
    MV2_SCATTER_MEDIUM_MSG = defaultval.d;
    rc = MPL_env2int("UCR_SCATTER_MEDIUM_MSG", &(MV2_SCATTER_MEDIUM_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SCATTER_MEDIUM_MSG");
    rc = MPL_env2int("MV2_SCATTER_MEDIUM_MSG", &(MV2_SCATTER_MEDIUM_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SCATTER_MEDIUM_MSG");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SCATTER_SMALL_MSG, /* name */
        &MV2_SCATTER_SMALL_MSG, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "When the system size is lower than 512 cores, we use the \"Binomial\"algorithm for small message sizes. This allows the user to set the threshold for small messgaes. -1 indicates allowing the default values to be used.");
    MV2_SCATTER_SMALL_MSG = defaultval.d;
    rc = MPL_env2int("UCR_SCATTER_SMALL_MSG", &(MV2_SCATTER_SMALL_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SCATTER_SMALL_MSG");
    rc = MPL_env2int("MV2_SCATTER_SMALL_MSG", &(MV2_SCATTER_SMALL_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SCATTER_SMALL_MSG");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_DIRECT_SCATTER, /* name */
        &MV2_USE_DIRECT_SCATTER, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "Use the \"Direct\" algorithm for the MPI_Scatter operation. If this parameter is set to 0 at runtime, the \"Direct\" algorithm will not be invoked.");
    MV2_USE_DIRECT_SCATTER = defaultval.d;
    rc = MPL_env2bool("UCR_USE_DIRECT_SCATTER", &(MV2_USE_DIRECT_SCATTER));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_DIRECT_SCATTER");
    rc = MPL_env2bool("MV2_USE_DIRECT_SCATTER", &(MV2_USE_DIRECT_SCATTER));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_DIRECT_SCATTER");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_SCATTER_RD_INTER_LEADER_BCAST, /* name */
        &MV2_USE_SCATTER_RD_INTER_LEADER_BCAST, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_USE_SCATTER_RD_INTER_LEADER_BCAST = defaultval.d;
    rc = MPL_env2bool("UCR_USE_SCATTER_RD_INTER_LEADER_BCAST", &(MV2_USE_SCATTER_RD_INTER_LEADER_BCAST));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_SCATTER_RD_INTER_LEADER_BCAST");
    rc = MPL_env2bool("MV2_USE_SCATTER_RD_INTER_LEADER_BCAST", &(MV2_USE_SCATTER_RD_INTER_LEADER_BCAST));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_SCATTER_RD_INTER_LEADER_BCAST");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_SCATTER_RING_INTER_LEADER_BCAST, /* name */
        &MV2_USE_SCATTER_RING_INTER_LEADER_BCAST, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_USE_SCATTER_RING_INTER_LEADER_BCAST = defaultval.d;
    rc = MPL_env2bool("UCR_USE_SCATTER_RING_INTER_LEADER_BCAST", &(MV2_USE_SCATTER_RING_INTER_LEADER_BCAST));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_SCATTER_RING_INTER_LEADER_BCAST");
    rc = MPL_env2bool("MV2_USE_SCATTER_RING_INTER_LEADER_BCAST", &(MV2_USE_SCATTER_RING_INTER_LEADER_BCAST));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_SCATTER_RING_INTER_LEADER_BCAST");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_TWO_LEVEL_SCATTER, /* name */
        &MV2_USE_TWO_LEVEL_SCATTER, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "Use the two-level multi-core-aware algorithm for the MPI_Scatter operation. If this parameter is set to 0 at run-time, the two-level algorithm will not be invoked.");
    MV2_USE_TWO_LEVEL_SCATTER = defaultval.d;
    rc = MPL_env2bool("UCR_USE_TWO_LEVEL_SCATTER", &(MV2_USE_TWO_LEVEL_SCATTER));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_TWO_LEVEL_SCATTER");
    rc = MPL_env2bool("MV2_USE_TWO_LEVEL_SCATTER", &(MV2_USE_TWO_LEVEL_SCATTER));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_TWO_LEVEL_SCATTER");

    defaultval.d = (64 * 1024);
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_KNOMIAL_INTER_LEADER_THRESHOLD, /* name */
        &MV2_KNOMIAL_INTER_LEADER_THRESHOLD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_KNOMIAL_INTER_LEADER_THRESHOLD = defaultval.d;
    rc = MPL_env2int("UCR_KNOMIAL_INTER_LEADER_THRESHOLD", &(MV2_KNOMIAL_INTER_LEADER_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_KNOMIAL_INTER_LEADER_THRESHOLD");
    rc = MPL_env2int("MV2_KNOMIAL_INTER_LEADER_THRESHOLD", &(MV2_KNOMIAL_INTER_LEADER_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_KNOMIAL_INTER_LEADER_THRESHOLD");

    defaultval.d = 4;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_KNOMIAL_INTER_NODE_FACTOR, /* name */
        &MV2_KNOMIAL_INTER_NODE_FACTOR, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "This defines the degree of the knomial operation during the inter-node knomial broadcast phase.");
    MV2_KNOMIAL_INTER_NODE_FACTOR = defaultval.d;
    rc = MPL_env2int("UCR_KNOMIAL_INTER_NODE_FACTOR", &(MV2_KNOMIAL_INTER_NODE_FACTOR));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_KNOMIAL_INTER_NODE_FACTOR");
    rc = MPL_env2int("MV2_KNOMIAL_INTER_NODE_FACTOR", &(MV2_KNOMIAL_INTER_NODE_FACTOR));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_KNOMIAL_INTER_NODE_FACTOR");

    defaultval.d = 4;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_KNOMIAL_INTRA_NODE_FACTOR, /* name */
        &MV2_KNOMIAL_INTRA_NODE_FACTOR, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "This defines the degree of the knomial operation during the intra-node knomial broadcast phase.");
    MV2_KNOMIAL_INTRA_NODE_FACTOR = defaultval.d;
    rc = MPL_env2int("UCR_KNOMIAL_INTRA_NODE_FACTOR", &(MV2_KNOMIAL_INTRA_NODE_FACTOR));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_KNOMIAL_INTRA_NODE_FACTOR");
    rc = MPL_env2int("MV2_KNOMIAL_INTRA_NODE_FACTOR", &(MV2_KNOMIAL_INTRA_NODE_FACTOR));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_KNOMIAL_INTRA_NODE_FACTOR");

    defaultval.d = (128 * 1024);
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_KNOMIAL_INTRA_NODE_THRESHOLD, /* name */
        &MV2_KNOMIAL_INTRA_NODE_THRESHOLD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_KNOMIAL_INTRA_NODE_THRESHOLD = defaultval.d;
    rc = MPL_env2int("UCR_KNOMIAL_INTRA_NODE_THRESHOLD", &(MV2_KNOMIAL_INTRA_NODE_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_KNOMIAL_INTRA_NODE_THRESHOLD");
    rc = MPL_env2int("MV2_KNOMIAL_INTRA_NODE_THRESHOLD", &(MV2_KNOMIAL_INTRA_NODE_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_KNOMIAL_INTRA_NODE_THRESHOLD");

    defaultval.d = (128 * 1024);
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SHMEM_COLL_MAX_MSG_SIZE, /* name */
        &MV2_SHMEM_COLL_MAX_MSG_SIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "This parameter can be used to select the max buffer size of message for shared memory collectives.");
    MV2_SHMEM_COLL_MAX_MSG_SIZE = defaultval.d;
    rc = MPL_env2int("UCR_SHMEM_COLL_MAX_MSG_SIZE", &(MV2_SHMEM_COLL_MAX_MSG_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SHMEM_COLL_MAX_MSG_SIZE");
    rc = MPL_env2int("MV2_SHMEM_COLL_MAX_MSG_SIZE", &(MV2_SHMEM_COLL_MAX_MSG_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SHMEM_COLL_MAX_MSG_SIZE");

    defaultval.d = 32;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SHMEM_COLL_NUM_COMM, /* name */
        &MV2_SHMEM_COLL_NUM_COMM, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "This parameter can be used to select the number of communicators using shared memory collectives.");
    MV2_SHMEM_COLL_NUM_COMM = defaultval.d;
    rc = MPL_env2int("UCR_SHMEM_COLL_NUM_COMM", &(MV2_SHMEM_COLL_NUM_COMM));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SHMEM_COLL_NUM_COMM");
    rc = MPL_env2int("MV2_SHMEM_COLL_NUM_COMM", &(MV2_SHMEM_COLL_NUM_COMM));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SHMEM_COLL_NUM_COMM");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SHMEM_COLL_NUM_PROCS, /* name */
        &MV2_SHMEM_COLL_NUM_PROCS, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_SHMEM_COLL_NUM_PROCS = defaultval.d;
    rc = MPL_env2int("UCR_SHMEM_COLL_NUM_PROCS", &(MV2_SHMEM_COLL_NUM_PROCS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SHMEM_COLL_NUM_PROCS");
    rc = MPL_env2int("MV2_SHMEM_COLL_NUM_PROCS", &(MV2_SHMEM_COLL_NUM_PROCS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SHMEM_COLL_NUM_PROCS");

    defaultval.d = 5;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SHMEM_COLL_SPIN_COUNT, /* name */
        &MV2_SHMEM_COLL_SPIN_COUNT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_SHMEM_COLL_SPIN_COUNT = defaultval.d;
    rc = MPL_env2int("UCR_SHMEM_COLL_SPIN_COUNT", &(MV2_SHMEM_COLL_SPIN_COUNT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SHMEM_COLL_SPIN_COUNT");
    rc = MPL_env2int("MV2_SHMEM_COLL_SPIN_COUNT", &(MV2_SHMEM_COLL_SPIN_COUNT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SHMEM_COLL_SPIN_COUNT");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_OSU_COLLECTIVES, /* name */
        &MV2_USE_OSU_COLLECTIVES, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_USE_OSU_COLLECTIVES = defaultval.d;
    rc = MPL_env2bool("UCR_USE_OSU_COLLECTIVES", &(MV2_USE_OSU_COLLECTIVES));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_OSU_COLLECTIVES");
    rc = MPL_env2bool("MV2_USE_OSU_COLLECTIVES", &(MV2_USE_OSU_COLLECTIVES));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_OSU_COLLECTIVES");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_OSU_NB_COLLECTIVES, /* name */
        &MV2_USE_OSU_NB_COLLECTIVES, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "TODO-DESC");
    MV2_USE_OSU_NB_COLLECTIVES = defaultval.d;
    rc = MPL_env2bool("UCR_USE_OSU_NB_COLLECTIVES", &(MV2_USE_OSU_NB_COLLECTIVES));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_OSU_NB_COLLECTIVES");
    rc = MPL_env2bool("MV2_USE_OSU_NB_COLLECTIVES", &(MV2_USE_OSU_NB_COLLECTIVES));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_OSU_NB_COLLECTIVES");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_SHMEM_COLL, /* name */
        &MV2_USE_SHMEM_COLL, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "Use shared memory for collective communication. Set this to 0 for disabling shared memory collectives.");
    MV2_USE_SHMEM_COLL = defaultval.d;
    rc = MPL_env2bool("UCR_USE_SHMEM_COLL", &(MV2_USE_SHMEM_COLL));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_SHMEM_COLL");
    rc = MPL_env2bool("MV2_USE_SHMEM_COLL", &(MV2_USE_SHMEM_COLL));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_SHMEM_COLL");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_ENABLE_SOCKET_AWARE_COLLECTIVES, /* name */
        &MV2_ENABLE_SOCKET_AWARE_COLLECTIVES, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "COLLECTIVE", /* category */
        "This parameter enables/disables support for socket-aware collective communication. The parameter MV2_USE_SHMEM_COLL must be set to 1 for this to work.");
    MV2_ENABLE_SOCKET_AWARE_COLLECTIVES = defaultval.d;
    rc = MPL_env2bool("UCR_ENABLE_SOCKET_AWARE_COLLECTIVES", &(MV2_ENABLE_SOCKET_AWARE_COLLECTIVES));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_ENABLE_SOCKET_AWARE_COLLECTIVES");
    rc = MPL_env2bool("MV2_ENABLE_SOCKET_AWARE_COLLECTIVES", &(MV2_ENABLE_SOCKET_AWARE_COLLECTIVES));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_ENABLE_SOCKET_AWARE_COLLECTIVES");

    defaultval.str = (const char *) NULL;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_CHAR,
        MV2_CPU_BINDING_LEVEL, /* name */
        &MV2_CPU_BINDING_LEVEL, /* address */
        MV2_MAX_STRLEN, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This CVAR allows users to specify process to CPU (core) mapping at different binding levels. This parameters will not take effect if MV2_ENABLE_AFFINITY or MV2_USE_SHARED_MEM CVARs are set to 0,  if MV2_CPU_MAPPING is set, or if the library was configured with the \"--disable-hwloc\" option. The value of MV2_CPU_BINDING_LEVEL can be \"core\", \"socket\", or \"numanode\". When this value is not set \"core\" will be used as the default binding level. ");
    tmp_str = defaultval.str;
    rc = MPL_env2str("UCR_CPU_BINDING_LEVEL", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CPU_BINDING_LEVEL");
    rc = MPL_env2str("MV2_CPU_BINDING_LEVEL", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CPU_BINDING_LEVEL");
    if (tmp_str != NULL) {
        MV2_CPU_BINDING_LEVEL = MPL_strdup(tmp_str);
        MV2_assert(MV2_CPU_BINDING_LEVEL);
        if (MV2_CPU_BINDING_LEVEL == NULL) {
            MPIR_CHKMEM_SETERR(mpi_errno, strlen(tmp_str), "dup of string for MV2_CPU_BINDING_LEVEL");
            goto fn_fail;
        }
    }
    else {
        MV2_CPU_BINDING_LEVEL = NULL;
    }

    defaultval.str = (const char *) NULL;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_CHAR,
        MV2_CPU_MAPPING, /* name */
        &MV2_CPU_MAPPING, /* address */
        MV2_MAX_STRLEN, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This CVAR allows users to specify process to CPU(core) mapping. This parameter will not take effect if either MV2_ENABLE_AFFINITY or MV2_USE_SHARED_MEM CVARs are set to 0 or if the library was configured with the \"--disable-hwloc\" option. MV2_CPU_MAPPING is currently not supported on Solaris.");
    tmp_str = defaultval.str;
    rc = MPL_env2str("UCR_CPU_MAPPING", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CPU_MAPPING");
    rc = MPL_env2str("MV2_CPU_MAPPING", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CPU_MAPPING");
    if (tmp_str != NULL) {
        MV2_CPU_MAPPING = MPL_strdup(tmp_str);
        MV2_assert(MV2_CPU_MAPPING);
        if (MV2_CPU_MAPPING == NULL) {
            MPIR_CHKMEM_SETERR(mpi_errno, strlen(tmp_str), "dup of string for MV2_CPU_MAPPING");
            goto fn_fail;
        }
    }
    else {
        MV2_CPU_MAPPING = NULL;
    }

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_ENABLE_AFFINITY, /* name */
        &MV2_ENABLE_AFFINITY, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Enable CPU affinity by setting MV2_ENABLE_AFFINITY to 1 or disable it by setting MV2_ENABLE_AFFINITY to 0. MV2_ENABLE_AFFINITY is currently not supported on Solaris. CPU affinity is also not supported if MV2_USE_SHARED_MEM is set to 0.");
    MV2_ENABLE_AFFINITY = defaultval.d;
    rc = MPL_env2int("UCR_ENABLE_AFFINITY", &(MV2_ENABLE_AFFINITY));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_ENABLE_AFFINITY");
    rc = MPL_env2int("MV2_ENABLE_AFFINITY", &(MV2_ENABLE_AFFINITY));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_ENABLE_AFFINITY");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_ENABLE_LEASTLOAD, /* name */
        &MV2_ENABLE_LEASTLOAD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_ENABLE_LEASTLOAD = defaultval.d;
    rc = MPL_env2bool("UCR_ENABLE_LEASTLOAD", &(MV2_ENABLE_LEASTLOAD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_ENABLE_LEASTLOAD");
    rc = MPL_env2bool("MV2_ENABLE_LEASTLOAD", &(MV2_ENABLE_LEASTLOAD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_ENABLE_LEASTLOAD");

    defaultval.str = (const char *) NULL;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_CHAR,
        MV2_CPU_BINDING_POLICY, /* name */
        &MV2_CPU_BINDING_POLICY, /* address */
        MV2_MAX_STRLEN, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "We have changed the default value of MV2_CPU_BINDING_POLICY to \"hybrid\" along with MV2_HYBRID_BINDING_POLICY=bunch. It is the  same as setting MV2_CPU_BINDING_POLICY to bunch. However, it also  works well for systems with hyper-threading enabled or systems that have vendor specific core mappings. This allows users to specify process to CPU (core) mapping with the CPU binding policy. This parameter will no take effect if MV2_ENABLE_AFFINITY or MV2_USE_SHARED_MEM CVARs are set to 0, if MV2_CPU_MAPPING is set, or if the library was configured with the \"--disable-hwloc\" option. The value of MV2_CPU_BINDING_POLICY can be \"bunch\", \"scatter\", or \"hybrid\". When this parameter is unset the \"hybrid\" policy will be used. ");
    tmp_str = defaultval.str;
    rc = MPL_env2str("UCR_CPU_BINDING_POLICY", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CPU_BINDING_POLICY");
    rc = MPL_env2str("MV2_CPU_BINDING_POLICY", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CPU_BINDING_POLICY");
    if (tmp_str != NULL) {
        MV2_CPU_BINDING_POLICY = MPL_strdup(tmp_str);
        MV2_assert(MV2_CPU_BINDING_POLICY);
        if (MV2_CPU_BINDING_POLICY == NULL) {
            MPIR_CHKMEM_SETERR(mpi_errno, strlen(tmp_str), "dup of string for MV2_CPU_BINDING_POLICY");
            goto fn_fail;
        }
    }
    else {
        MV2_CPU_BINDING_POLICY = NULL;
    }

    defaultval.d = 5000;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CM_MAX_SPIN_COUNT, /* name */
        &MV2_CM_MAX_SPIN_COUNT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CM_MAX_SPIN_COUNT = defaultval.d;
    rc = MPL_env2int("UCR_CM_MAX_SPIN_COUNT", &(MV2_CM_MAX_SPIN_COUNT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CM_MAX_SPIN_COUNT");
    rc = MPL_env2int("MV2_CM_MAX_SPIN_COUNT", &(MV2_CM_MAX_SPIN_COUNT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CM_MAX_SPIN_COUNT");

    defaultval.d = 1024;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CM_RECV_BUFFERS, /* name */
        &MV2_CM_RECV_BUFFERS, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This defines the number of buffers used by connection manager to establish new connections. These buffers are quite small and are shared for all connections, so this value may be increased to 8192 for large clusters to avoid retries in case of packet drops.");
    MV2_CM_RECV_BUFFERS = defaultval.d;
    rc = MPL_env2int("UCR_CM_RECV_BUFFERS", &(MV2_CM_RECV_BUFFERS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CM_RECV_BUFFERS");
    rc = MPL_env2int("MV2_CM_RECV_BUFFERS", &(MV2_CM_RECV_BUFFERS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CM_RECV_BUFFERS");

    defaultval.d = 10;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CM_SEND_DEPTH, /* name */
        &MV2_CM_SEND_DEPTH, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CM_SEND_DEPTH = defaultval.d;
    rc = MPL_env2int("UCR_CM_SEND_DEPTH", &(MV2_CM_SEND_DEPTH));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CM_SEND_DEPTH");
    rc = MPL_env2int("MV2_CM_SEND_DEPTH", &(MV2_CM_SEND_DEPTH));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CM_SEND_DEPTH");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CM_TIMEOUT, /* name */
        &MV2_CM_TIMEOUT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This is the timeout value associated with connection management messages via UD channel. Decreasing this value may lead to faster retries but at the cost of generating duplicate messages.");
    MV2_CM_TIMEOUT = defaultval.d;
    rc = MPL_env2int("UCR_CM_TIMEOUT", &(MV2_CM_TIMEOUT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CM_TIMEOUT");
    rc = MPL_env2int("MV2_CM_TIMEOUT", &(MV2_CM_TIMEOUT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CM_TIMEOUT");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CM_UD_PSN, /* name */
        &MV2_CM_UD_PSN, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CM_UD_PSN = defaultval.d;
    rc = MPL_env2int("UCR_CM_UD_PSN", &(MV2_CM_UD_PSN));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CM_UD_PSN");
    rc = MPL_env2int("MV2_CM_UD_PSN", &(MV2_CM_UD_PSN));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CM_UD_PSN");

    defaultval.d = (1024*1024);
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CM_THREAD_STACKSIZE, /* name */
        &MV2_CM_THREAD_STACKSIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CM_THREAD_STACKSIZE = defaultval.d;
    rc = MPL_env2int("UCR_CM_THREAD_STACKSIZE", &(MV2_CM_THREAD_STACKSIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CM_THREAD_STACKSIZE");
    rc = MPL_env2int("MV2_CM_THREAD_STACKSIZE", &(MV2_CM_THREAD_STACKSIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CM_THREAD_STACKSIZE");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_FORCE_HCA_TYPE, /* name */
        &MV2_FORCE_HCA_TYPE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_FORCE_HCA_TYPE = defaultval.d;
    rc = MPL_env2int("UCR_FORCE_HCA_TYPE", &(MV2_FORCE_HCA_TYPE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_FORCE_HCA_TYPE");
    rc = MPL_env2int("MV2_FORCE_HCA_TYPE", &(MV2_FORCE_HCA_TYPE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_FORCE_HCA_TYPE");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_HCA_AWARE_PROCESS_MAPPING, /* name */
        &MV2_HCA_AWARE_PROCESS_MAPPING, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC - Not used currently.");
    MV2_HCA_AWARE_PROCESS_MAPPING = defaultval.d;
    rc = MPL_env2int("UCR_HCA_AWARE_PROCESS_MAPPING", &(MV2_HCA_AWARE_PROCESS_MAPPING));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_HCA_AWARE_PROCESS_MAPPING");
    rc = MPL_env2int("MV2_HCA_AWARE_PROCESS_MAPPING", &(MV2_HCA_AWARE_PROCESS_MAPPING));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_HCA_AWARE_PROCESS_MAPPING");

    defaultval.d = 2000;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_RDMA_CM_ARP_TIMEOUT, /* name */
        &MV2_RDMA_CM_ARP_TIMEOUT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This parameter specifies the ARP timeout to be used by RDMA CM module.");
    MV2_RDMA_CM_ARP_TIMEOUT = defaultval.d;
    rc = MPL_env2int("UCR_RDMA_CM_ARP_TIMEOUT", &(MV2_RDMA_CM_ARP_TIMEOUT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_RDMA_CM_ARP_TIMEOUT");
    rc = MPL_env2int("MV2_RDMA_CM_ARP_TIMEOUT", &(MV2_RDMA_CM_ARP_TIMEOUT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_RDMA_CM_ARP_TIMEOUT");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_RDMA_CM_PORT, /* name */
        &MV2_RDMA_CM_PORT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_RDMA_CM_PORT = defaultval.d;
    rc = MPL_env2int("UCR_RDMA_CM_PORT", &(MV2_RDMA_CM_PORT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_RDMA_CM_PORT");
    rc = MPL_env2int("MV2_RDMA_CM_PORT", &(MV2_RDMA_CM_PORT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_RDMA_CM_PORT");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_RDMA_CM_MAX_PORT, /* name */
        &MV2_RDMA_CM_MAX_PORT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This parameter specifies the upper limit of the port range to be used by the RDMA CM module when choosing the port on which it listens for connections. If not specified, defaults to 65536.");
    MV2_RDMA_CM_MAX_PORT = defaultval.d;
    rc = MPL_env2int("UCR_RDMA_CM_MAX_PORT", &(MV2_RDMA_CM_MAX_PORT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_RDMA_CM_MAX_PORT");
    rc = MPL_env2int("MV2_RDMA_CM_MAX_PORT", &(MV2_RDMA_CM_MAX_PORT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_RDMA_CM_MAX_PORT");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_RDMA_CM_MIN_PORT, /* name */
        &MV2_RDMA_CM_MIN_PORT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This parameter specifies the lower limit of the port range to be used by the RDMA CM module when choosing the port on which it listens for connections. If not specified, defaults to 1024.");
    MV2_RDMA_CM_MIN_PORT = defaultval.d;
    rc = MPL_env2int("UCR_RDMA_CM_MIN_PORT", &(MV2_RDMA_CM_MIN_PORT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_RDMA_CM_MIN_PORT");
    rc = MPL_env2int("MV2_RDMA_CM_MIN_PORT", &(MV2_RDMA_CM_MIN_PORT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_RDMA_CM_MIN_PORT");

    defaultval.str = (const char *) NULL;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_CHAR,
        MV2_SHMEM_DIR, /* name */
        &MV2_SHMEM_DIR, /* address */
        MV2_MAX_STRLEN, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This parameter can be used to specify the path to the shared memory files for intra-node communication.");
    tmp_str = defaultval.str;
    rc = MPL_env2str("UCR_SHMEM_DIR", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SHMEM_DIR");
    rc = MPL_env2str("MV2_SHMEM_DIR", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SHMEM_DIR");
    if (tmp_str != NULL) {
        MV2_SHMEM_DIR = MPL_strdup(tmp_str);
        MV2_assert(MV2_SHMEM_DIR);
        if (MV2_SHMEM_DIR == NULL) {
            MPIR_CHKMEM_SETERR(mpi_errno, strlen(tmp_str), "dup of string for MV2_SHMEM_DIR");
            goto fn_fail;
        }
    }
    else {
        MV2_SHMEM_DIR = NULL;
    }

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_EAGER_CUDAHOST_REG, /* name */
        &MV2_EAGER_CUDAHOST_REG, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_EAGER_CUDAHOST_REG = defaultval.d;
    rc = MPL_env2int("UCR_EAGER_CUDAHOST_REG", &(MV2_EAGER_CUDAHOST_REG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_EAGER_CUDAHOST_REG");
    rc = MPL_env2int("MV2_EAGER_CUDAHOST_REG", &(MV2_EAGER_CUDAHOST_REG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_EAGER_CUDAHOST_REG");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_VECTOR_OPT, /* name */
        &MV2_CUDA_VECTOR_OPT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_VECTOR_OPT = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_VECTOR_OPT", &(MV2_CUDA_VECTOR_OPT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_VECTOR_OPT");
    rc = MPL_env2int("MV2_CUDA_VECTOR_OPT", &(MV2_CUDA_VECTOR_OPT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_VECTOR_OPT");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_KERNEL_OPT, /* name */
        &MV2_CUDA_KERNEL_OPT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_KERNEL_OPT = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_KERNEL_OPT", &(MV2_CUDA_KERNEL_OPT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_KERNEL_OPT");
    rc = MPL_env2int("MV2_CUDA_KERNEL_OPT", &(MV2_CUDA_KERNEL_OPT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_KERNEL_OPT");

    defaultval.d = 1024;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_KERNEL_VECTOR_TIDBLK_SIZE, /* name */
        &MV2_CUDA_KERNEL_VECTOR_TIDBLK_SIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This controls the number of CUDA threads per block in pack/unpack kernels for MPI vector datatype in communication involving GPU device buffers.");
    MV2_CUDA_KERNEL_VECTOR_TIDBLK_SIZE = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_KERNEL_VECTOR_TIDBLK_SIZE", &(MV2_CUDA_KERNEL_VECTOR_TIDBLK_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_KERNEL_VECTOR_TIDBLK_SIZE");
    rc = MPL_env2int("MV2_CUDA_KERNEL_VECTOR_TIDBLK_SIZE", &(MV2_CUDA_KERNEL_VECTOR_TIDBLK_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_KERNEL_VECTOR_TIDBLK_SIZE");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_KERNEL_VECTOR_YSIZE, /* name */
        &MV2_CUDA_KERNEL_VECTOR_YSIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This controls the y-dimension of a thread block in pack/unpack kernels for MPI vector datatype in communication involving GPU device buffers. It controls the number of threads operating on each block of data in a vector.");
    MV2_CUDA_KERNEL_VECTOR_YSIZE = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_KERNEL_VECTOR_YSIZE", &(MV2_CUDA_KERNEL_VECTOR_YSIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_KERNEL_VECTOR_YSIZE");
    rc = MPL_env2int("MV2_CUDA_KERNEL_VECTOR_YSIZE", &(MV2_CUDA_KERNEL_VECTOR_YSIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_KERNEL_VECTOR_YSIZE");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_KERNEL_SUBARR_TIDBLK_SIZE, /* name */
        &MV2_CUDA_KERNEL_SUBARR_TIDBLK_SIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_KERNEL_SUBARR_TIDBLK_SIZE = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_KERNEL_SUBARR_TIDBLK_SIZE", &(MV2_CUDA_KERNEL_SUBARR_TIDBLK_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_KERNEL_SUBARR_TIDBLK_SIZE");
    rc = MPL_env2int("MV2_CUDA_KERNEL_SUBARR_TIDBLK_SIZE", &(MV2_CUDA_KERNEL_SUBARR_TIDBLK_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_KERNEL_SUBARR_TIDBLK_SIZE");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_KERNEL_SUBARR_XDIM, /* name */
        &MV2_CUDA_KERNEL_SUBARR_XDIM, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_KERNEL_SUBARR_XDIM = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_KERNEL_SUBARR_XDIM", &(MV2_CUDA_KERNEL_SUBARR_XDIM));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_KERNEL_SUBARR_XDIM");
    rc = MPL_env2int("MV2_CUDA_KERNEL_SUBARR_XDIM", &(MV2_CUDA_KERNEL_SUBARR_XDIM));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_KERNEL_SUBARR_XDIM");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_KERNEL_SUBARR_YDIM, /* name */
        &MV2_CUDA_KERNEL_SUBARR_YDIM, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_KERNEL_SUBARR_YDIM = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_KERNEL_SUBARR_YDIM", &(MV2_CUDA_KERNEL_SUBARR_YDIM));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_KERNEL_SUBARR_YDIM");
    rc = MPL_env2int("MV2_CUDA_KERNEL_SUBARR_YDIM", &(MV2_CUDA_KERNEL_SUBARR_YDIM));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_KERNEL_SUBARR_YDIM");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_KERNEL_SUBARR_ZDIM, /* name */
        &MV2_CUDA_KERNEL_SUBARR_ZDIM, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_KERNEL_SUBARR_ZDIM = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_KERNEL_SUBARR_ZDIM", &(MV2_CUDA_KERNEL_SUBARR_ZDIM));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_KERNEL_SUBARR_ZDIM");
    rc = MPL_env2int("MV2_CUDA_KERNEL_SUBARR_ZDIM", &(MV2_CUDA_KERNEL_SUBARR_ZDIM));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_KERNEL_SUBARR_ZDIM");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_NUM_EVENTS, /* name */
        &MV2_CUDA_NUM_EVENTS, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_NUM_EVENTS = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_NUM_EVENTS", &(MV2_CUDA_NUM_EVENTS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_NUM_EVENTS");
    rc = MPL_env2int("MV2_CUDA_NUM_EVENTS", &(MV2_CUDA_NUM_EVENTS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_NUM_EVENTS");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_INIT_CONTEXT, /* name */
        &MV2_CUDA_INIT_CONTEXT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_INIT_CONTEXT = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_INIT_CONTEXT", &(MV2_CUDA_INIT_CONTEXT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_INIT_CONTEXT");
    rc = MPL_env2int("MV2_CUDA_INIT_CONTEXT", &(MV2_CUDA_INIT_CONTEXT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_INIT_CONTEXT");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CHECK_CUDA_ATTRIBUTE, /* name */
        &MV2_CHECK_CUDA_ATTRIBUTE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CHECK_CUDA_ATTRIBUTE = defaultval.d;
    rc = MPL_env2int("UCR_CHECK_CUDA_ATTRIBUTE", &(MV2_CHECK_CUDA_ATTRIBUTE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CHECK_CUDA_ATTRIBUTE");
    rc = MPL_env2int("MV2_CHECK_CUDA_ATTRIBUTE", &(MV2_CHECK_CUDA_ATTRIBUTE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CHECK_CUDA_ATTRIBUTE");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_USE_NAIVE, /* name */
        &MV2_CUDA_USE_NAIVE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_USE_NAIVE = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_USE_NAIVE", &(MV2_CUDA_USE_NAIVE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_USE_NAIVE");
    rc = MPL_env2int("MV2_CUDA_USE_NAIVE", &(MV2_CUDA_USE_NAIVE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_USE_NAIVE");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_ALLTOALL_DYNAMIC, /* name */
        &MV2_CUDA_ALLTOALL_DYNAMIC, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_ALLTOALL_DYNAMIC = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_ALLTOALL_DYNAMIC", &(MV2_CUDA_ALLTOALL_DYNAMIC));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_ALLTOALL_DYNAMIC");
    rc = MPL_env2int("MV2_CUDA_ALLTOALL_DYNAMIC", &(MV2_CUDA_ALLTOALL_DYNAMIC));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_ALLTOALL_DYNAMIC");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_REGISTER_NAIVE_BUF, /* name */
        &MV2_CUDA_REGISTER_NAIVE_BUF, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_REGISTER_NAIVE_BUF = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_REGISTER_NAIVE_BUF", &(MV2_CUDA_REGISTER_NAIVE_BUF));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_REGISTER_NAIVE_BUF");
    rc = MPL_env2int("MV2_CUDA_REGISTER_NAIVE_BUF", &(MV2_CUDA_REGISTER_NAIVE_BUF));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_REGISTER_NAIVE_BUF");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_GATHER_NAIVE_LIMIT, /* name */
        &MV2_CUDA_GATHER_NAIVE_LIMIT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_GATHER_NAIVE_LIMIT = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_GATHER_NAIVE_LIMIT", &(MV2_CUDA_GATHER_NAIVE_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_GATHER_NAIVE_LIMIT");
    rc = MPL_env2int("MV2_CUDA_GATHER_NAIVE_LIMIT", &(MV2_CUDA_GATHER_NAIVE_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_GATHER_NAIVE_LIMIT");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_SCATTER_NAIVE_LIMIT, /* name */
        &MV2_CUDA_SCATTER_NAIVE_LIMIT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_SCATTER_NAIVE_LIMIT = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_SCATTER_NAIVE_LIMIT", &(MV2_CUDA_SCATTER_NAIVE_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_SCATTER_NAIVE_LIMIT");
    rc = MPL_env2int("MV2_CUDA_SCATTER_NAIVE_LIMIT", &(MV2_CUDA_SCATTER_NAIVE_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_SCATTER_NAIVE_LIMIT");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_ALLTOALL_NAIVE_LIMIT, /* name */
        &MV2_CUDA_ALLTOALL_NAIVE_LIMIT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_ALLTOALL_NAIVE_LIMIT = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_ALLTOALL_NAIVE_LIMIT", &(MV2_CUDA_ALLTOALL_NAIVE_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_ALLTOALL_NAIVE_LIMIT");
    rc = MPL_env2int("MV2_CUDA_ALLTOALL_NAIVE_LIMIT", &(MV2_CUDA_ALLTOALL_NAIVE_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_ALLTOALL_NAIVE_LIMIT");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_ALLTOALLV_NAIVE_LIMIT, /* name */
        &MV2_CUDA_ALLTOALLV_NAIVE_LIMIT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_ALLTOALLV_NAIVE_LIMIT = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_ALLTOALLV_NAIVE_LIMIT", &(MV2_CUDA_ALLTOALLV_NAIVE_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_ALLTOALLV_NAIVE_LIMIT");
    rc = MPL_env2int("MV2_CUDA_ALLTOALLV_NAIVE_LIMIT", &(MV2_CUDA_ALLTOALLV_NAIVE_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_ALLTOALLV_NAIVE_LIMIT");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_ALLGATHER_NAIVE_LIMIT, /* name */
        &MV2_CUDA_ALLGATHER_NAIVE_LIMIT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_ALLGATHER_NAIVE_LIMIT = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_ALLGATHER_NAIVE_LIMIT", &(MV2_CUDA_ALLGATHER_NAIVE_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_ALLGATHER_NAIVE_LIMIT");
    rc = MPL_env2int("MV2_CUDA_ALLGATHER_NAIVE_LIMIT", &(MV2_CUDA_ALLGATHER_NAIVE_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_ALLGATHER_NAIVE_LIMIT");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_ALLGATHERV_NAIVE_LIMIT, /* name */
        &MV2_CUDA_ALLGATHERV_NAIVE_LIMIT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_ALLGATHERV_NAIVE_LIMIT = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_ALLGATHERV_NAIVE_LIMIT", &(MV2_CUDA_ALLGATHERV_NAIVE_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_ALLGATHERV_NAIVE_LIMIT");
    rc = MPL_env2int("MV2_CUDA_ALLGATHERV_NAIVE_LIMIT", &(MV2_CUDA_ALLGATHERV_NAIVE_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_ALLGATHERV_NAIVE_LIMIT");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_BCAST_NAIVE_LIMIT, /* name */
        &MV2_CUDA_BCAST_NAIVE_LIMIT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_BCAST_NAIVE_LIMIT = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_BCAST_NAIVE_LIMIT", &(MV2_CUDA_BCAST_NAIVE_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_BCAST_NAIVE_LIMIT");
    rc = MPL_env2int("MV2_CUDA_BCAST_NAIVE_LIMIT", &(MV2_CUDA_BCAST_NAIVE_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_BCAST_NAIVE_LIMIT");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_GATHERV_NAIVE_LIMIT, /* name */
        &MV2_CUDA_GATHERV_NAIVE_LIMIT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_GATHERV_NAIVE_LIMIT = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_GATHERV_NAIVE_LIMIT", &(MV2_CUDA_GATHERV_NAIVE_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_GATHERV_NAIVE_LIMIT");
    rc = MPL_env2int("MV2_CUDA_GATHERV_NAIVE_LIMIT", &(MV2_CUDA_GATHERV_NAIVE_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_GATHERV_NAIVE_LIMIT");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_SCATTERV_NAIVE_LIMIT, /* name */
        &MV2_CUDA_SCATTERV_NAIVE_LIMIT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_SCATTERV_NAIVE_LIMIT = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_SCATTERV_NAIVE_LIMIT", &(MV2_CUDA_SCATTERV_NAIVE_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_SCATTERV_NAIVE_LIMIT");
    rc = MPL_env2int("MV2_CUDA_SCATTERV_NAIVE_LIMIT", &(MV2_CUDA_SCATTERV_NAIVE_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_SCATTERV_NAIVE_LIMIT");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_ALLGATHER_RD_LIMIT, /* name */
        &MV2_CUDA_ALLGATHER_RD_LIMIT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_ALLGATHER_RD_LIMIT = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_ALLGATHER_RD_LIMIT", &(MV2_CUDA_ALLGATHER_RD_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_ALLGATHER_RD_LIMIT");
    rc = MPL_env2int("MV2_CUDA_ALLGATHER_RD_LIMIT", &(MV2_CUDA_ALLGATHER_RD_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_ALLGATHER_RD_LIMIT");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_ALLGATHER_FGP, /* name */
        &MV2_CUDA_ALLGATHER_FGP, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_ALLGATHER_FGP = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_ALLGATHER_FGP", &(MV2_CUDA_ALLGATHER_FGP));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_ALLGATHER_FGP");
    rc = MPL_env2int("MV2_CUDA_ALLGATHER_FGP", &(MV2_CUDA_ALLGATHER_FGP));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_ALLGATHER_FGP");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_IPC, /* name */
        &MV2_CUDA_IPC, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This enables intra-node GPU-GPU communication using IPC feature available from CUDA 4.1");
    MV2_CUDA_IPC = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_IPC", &(MV2_CUDA_IPC));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_IPC");
    rc = MPL_env2int("MV2_CUDA_IPC", &(MV2_CUDA_IPC));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_IPC");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_IPC_SHARE_GPU, /* name */
        &MV2_CUDA_IPC_SHARE_GPU, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_IPC_SHARE_GPU = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_IPC_SHARE_GPU", &(MV2_CUDA_IPC_SHARE_GPU));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_IPC_SHARE_GPU");
    rc = MPL_env2int("MV2_CUDA_IPC_SHARE_GPU", &(MV2_CUDA_IPC_SHARE_GPU));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_IPC_SHARE_GPU");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_SMP_IPC, /* name */
        &MV2_CUDA_SMP_IPC, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This enables an optimization for short message GPU device-to-device communication using IPC feature available from CUDA 4.1");
    MV2_CUDA_SMP_IPC = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_SMP_IPC", &(MV2_CUDA_SMP_IPC));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_SMP_IPC");
    rc = MPL_env2int("MV2_CUDA_SMP_IPC", &(MV2_CUDA_SMP_IPC));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_SMP_IPC");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_ENABLE_IPC_CACHE, /* name */
        &MV2_CUDA_ENABLE_IPC_CACHE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_ENABLE_IPC_CACHE = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_ENABLE_IPC_CACHE", &(MV2_CUDA_ENABLE_IPC_CACHE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_ENABLE_IPC_CACHE");
    rc = MPL_env2int("MV2_CUDA_ENABLE_IPC_CACHE", &(MV2_CUDA_ENABLE_IPC_CACHE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_ENABLE_IPC_CACHE");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_IPC_MAX_CACHE_ENTRIES, /* name */
        &MV2_CUDA_IPC_MAX_CACHE_ENTRIES, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_IPC_MAX_CACHE_ENTRIES = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_IPC_MAX_CACHE_ENTRIES", &(MV2_CUDA_IPC_MAX_CACHE_ENTRIES));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_IPC_MAX_CACHE_ENTRIES");
    rc = MPL_env2int("MV2_CUDA_IPC_MAX_CACHE_ENTRIES", &(MV2_CUDA_IPC_MAX_CACHE_ENTRIES));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_IPC_MAX_CACHE_ENTRIES");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_IPC_NUM_STAGE_BUFFERS, /* name */
        &MV2_CUDA_IPC_NUM_STAGE_BUFFERS, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_IPC_NUM_STAGE_BUFFERS = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_IPC_NUM_STAGE_BUFFERS", &(MV2_CUDA_IPC_NUM_STAGE_BUFFERS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_IPC_NUM_STAGE_BUFFERS");
    rc = MPL_env2int("MV2_CUDA_IPC_NUM_STAGE_BUFFERS", &(MV2_CUDA_IPC_NUM_STAGE_BUFFERS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_IPC_NUM_STAGE_BUFFERS");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_IPC_STAGE_BUF_SIZE, /* name */
        &MV2_CUDA_IPC_STAGE_BUF_SIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_IPC_STAGE_BUF_SIZE = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_IPC_STAGE_BUF_SIZE", &(MV2_CUDA_IPC_STAGE_BUF_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_IPC_STAGE_BUF_SIZE");
    rc = MPL_env2int("MV2_CUDA_IPC_STAGE_BUF_SIZE", &(MV2_CUDA_IPC_STAGE_BUF_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_IPC_STAGE_BUF_SIZE");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_IPC_BUFFERED, /* name */
        &MV2_CUDA_IPC_BUFFERED, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_IPC_BUFFERED = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_IPC_BUFFERED", &(MV2_CUDA_IPC_BUFFERED));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_IPC_BUFFERED");
    rc = MPL_env2int("MV2_CUDA_IPC_BUFFERED", &(MV2_CUDA_IPC_BUFFERED));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_IPC_BUFFERED");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_IPC_THRESHOLD, /* name */
        &MV2_CUDA_IPC_THRESHOLD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_IPC_THRESHOLD = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_IPC_THRESHOLD", &(MV2_CUDA_IPC_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_IPC_THRESHOLD");
    rc = MPL_env2int("MV2_CUDA_IPC_THRESHOLD", &(MV2_CUDA_IPC_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_IPC_THRESHOLD");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_IPC_BUFFERED_LIMIT, /* name */
        &MV2_CUDA_IPC_BUFFERED_LIMIT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_IPC_BUFFERED_LIMIT = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_IPC_BUFFERED_LIMIT", &(MV2_CUDA_IPC_BUFFERED_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_IPC_BUFFERED_LIMIT");
    rc = MPL_env2int("MV2_CUDA_IPC_BUFFERED_LIMIT", &(MV2_CUDA_IPC_BUFFERED_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_IPC_BUFFERED_LIMIT");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_IPC_SYNC_LIMIT, /* name */
        &MV2_CUDA_IPC_SYNC_LIMIT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_IPC_SYNC_LIMIT = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_IPC_SYNC_LIMIT", &(MV2_CUDA_IPC_SYNC_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_IPC_SYNC_LIMIT");
    rc = MPL_env2int("MV2_CUDA_IPC_SYNC_LIMIT", &(MV2_CUDA_IPC_SYNC_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_IPC_SYNC_LIMIT");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_DYNAMIC_INIT, /* name */
        &MV2_CUDA_DYNAMIC_INIT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_DYNAMIC_INIT = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_DYNAMIC_INIT", &(MV2_CUDA_DYNAMIC_INIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_DYNAMIC_INIT");
    rc = MPL_env2int("MV2_CUDA_DYNAMIC_INIT", &(MV2_CUDA_DYNAMIC_INIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_DYNAMIC_INIT");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_NONBLOCKING_STREAMS, /* name */
        &MV2_CUDA_NONBLOCKING_STREAMS, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This controls the use of non-blocking streams for asynchronous CUDA memory copies in communication involving GPU memory.");
    MV2_CUDA_NONBLOCKING_STREAMS = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_NONBLOCKING_STREAMS", &(MV2_CUDA_NONBLOCKING_STREAMS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_NONBLOCKING_STREAMS");
    rc = MPL_env2int("MV2_CUDA_NONBLOCKING_STREAMS", &(MV2_CUDA_NONBLOCKING_STREAMS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_NONBLOCKING_STREAMS");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SMP_EAGERSIZE, /* name */
        &MV2_SMP_EAGERSIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This parameter defines the size of shared buffer between every two processes on the same node for transferring messages smaller than or equal to MV2_SMP_EAGERSIZE. Note that this variable can be set with suffixes such as 'K'/'k', 'M'/'m' or 'G'/'g' to denote Kilobyte, Megabyte or Gigabyte respectively.");
    MV2_SMP_EAGERSIZE = defaultval.d;
    rc = MPL_env2int("UCR_SMP_EAGERSIZE", &(MV2_SMP_EAGERSIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SMP_EAGERSIZE");
    rc = MPL_env2int("MV2_SMP_EAGERSIZE", &(MV2_SMP_EAGERSIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SMP_EAGERSIZE");

    defaultval.str = (const char *) NULL;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_CHAR,
        MV2_IBA_HCA, /* name */
        &MV2_IBA_HCA, /* address */
        MV2_MAX_STRLEN, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This specifies the HCA's to be used for performing network operations.");
    tmp_str = defaultval.str;
    rc = MPL_env2str("UCR_IBA_HCA", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_IBA_HCA");
    rc = MPL_env2str("MV2_IBA_HCA", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_IBA_HCA");
    if (tmp_str != NULL) {
        MV2_IBA_HCA = MPL_strdup(tmp_str);
        MV2_assert(MV2_IBA_HCA);
        if (MV2_IBA_HCA == NULL) {
            MPIR_CHKMEM_SETERR(mpi_errno, strlen(tmp_str), "dup of string for MV2_IBA_HCA");
            goto fn_fail;
        }
    }
    else {
        MV2_IBA_HCA = NULL;
    }

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SMP_USE_CMA, /* name */
        &MV2_SMP_USE_CMA, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This parameter enables/disables CMA based intra-node communication at run time. It does not take effect if MVAPICH2 is configured with -without-cma. When -with-limic2 is included in the configure flags, LiMIC2 is used in preference over CMA. Please set MV2_SMP_USE_LIMIC2 to 0 in order to choose CMA if MVAPICH2 is configured with -with-limic2.");
    MV2_SMP_USE_CMA = defaultval.d;
    rc = MPL_env2int("UCR_SMP_USE_CMA", &(MV2_SMP_USE_CMA));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SMP_USE_CMA");
    rc = MPL_env2int("MV2_SMP_USE_CMA", &(MV2_SMP_USE_CMA));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SMP_USE_CMA");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SMP_USE_LIMIC2, /* name */
        &MV2_SMP_USE_LIMIC2, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This parameter enables/disables LiMIC2 at run time. It does not take effect if MVAPICH2 is not configured with -with-limic2. Not used currently.");
    MV2_SMP_USE_LIMIC2 = defaultval.d;
    rc = MPL_env2int("UCR_SMP_USE_LIMIC2", &(MV2_SMP_USE_LIMIC2));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SMP_USE_LIMIC2");
    rc = MPL_env2int("MV2_SMP_USE_LIMIC2", &(MV2_SMP_USE_LIMIC2));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SMP_USE_LIMIC2");

    defaultval.d = 200;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SMP_POLLING_THRESHOLD, /* name */
        &MV2_SMP_POLLING_THRESHOLD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_SMP_POLLING_THRESHOLD = defaultval.d;
    rc = MPL_env2int("UCR_SMP_POLLING_THRESHOLD", &(MV2_SMP_POLLING_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SMP_POLLING_THRESHOLD");
    rc = MPL_env2int("MV2_SMP_POLLING_THRESHOLD", &(MV2_SMP_POLLING_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SMP_POLLING_THRESHOLD");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SMP_CMA_MAX_SIZE, /* name */
        &MV2_SMP_CMA_MAX_SIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_SMP_CMA_MAX_SIZE = defaultval.d;
    rc = MPL_env2int("UCR_SMP_CMA_MAX_SIZE", &(MV2_SMP_CMA_MAX_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SMP_CMA_MAX_SIZE");
    rc = MPL_env2int("MV2_SMP_CMA_MAX_SIZE", &(MV2_SMP_CMA_MAX_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SMP_CMA_MAX_SIZE");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SMP_LIMIC2_MAX_SIZE, /* name */
        &MV2_SMP_LIMIC2_MAX_SIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_SMP_LIMIC2_MAX_SIZE = defaultval.d;
    rc = MPL_env2int("UCR_SMP_LIMIC2_MAX_SIZE", &(MV2_SMP_LIMIC2_MAX_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SMP_LIMIC2_MAX_SIZE");
    rc = MPL_env2int("MV2_SMP_LIMIC2_MAX_SIZE", &(MV2_SMP_LIMIC2_MAX_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SMP_LIMIC2_MAX_SIZE");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SMP_QUEUE_LENGTH, /* name */
        &MV2_SMP_QUEUE_LENGTH, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This parameter defines the size of the shared buffer between every two processes on the same node for transferring intra-node messages smaller than or equal to MV2_SMP_EAGERSIZE. This variable can be set with suffixes suck as 'K'/'k', 'M'/'m', or 'G'/'g' to  denote Kilobyte, Megabyte, or Gigabyte respectively.");
    MV2_SMP_QUEUE_LENGTH = defaultval.d;
    rc = MPL_env2int("UCR_SMP_QUEUE_LENGTH", &(MV2_SMP_QUEUE_LENGTH));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SMP_QUEUE_LENGTH");
    rc = MPL_env2int("MV2_SMP_QUEUE_LENGTH", &(MV2_SMP_QUEUE_LENGTH));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SMP_QUEUE_LENGTH");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_LIMIC_PUT_THRESHOLD, /* name */
        &MV2_LIMIC_PUT_THRESHOLD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_LIMIC_PUT_THRESHOLD = defaultval.d;
    rc = MPL_env2int("UCR_LIMIC_PUT_THRESHOLD", &(MV2_LIMIC_PUT_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_LIMIC_PUT_THRESHOLD");
    rc = MPL_env2int("MV2_LIMIC_PUT_THRESHOLD", &(MV2_LIMIC_PUT_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_LIMIC_PUT_THRESHOLD");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_LIMIC_GET_THRESHOLD, /* name */
        &MV2_LIMIC_GET_THRESHOLD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_LIMIC_GET_THRESHOLD = defaultval.d;
    rc = MPL_env2int("UCR_LIMIC_GET_THRESHOLD", &(MV2_LIMIC_GET_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_LIMIC_GET_THRESHOLD");
    rc = MPL_env2int("MV2_LIMIC_GET_THRESHOLD", &(MV2_LIMIC_GET_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_LIMIC_GET_THRESHOLD");

    defaultval.d = 4096;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_R3_THRESHOLD, /* name */
        &MV2_R3_THRESHOLD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "The value of this variable controls what message sizes go over the R3 rendezvous protocol. Messages above this message size use MV2_RNDV_PROTOCOL.");
    MV2_R3_THRESHOLD = defaultval.d;
    rc = MPL_env2int("UCR_R3_THRESHOLD", &(MV2_R3_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_R3_THRESHOLD");
    rc = MPL_env2int("MV2_R3_THRESHOLD", &(MV2_R3_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_R3_THRESHOLD");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_INTRA_NODE_R3_THRESHOLD, /* name */
        &MV2_INTRA_NODE_R3_THRESHOLD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_INTRA_NODE_R3_THRESHOLD = defaultval.d;
    rc = MPL_env2int("UCR_INTRA_NODE_R3_THRESHOLD", &(MV2_INTRA_NODE_R3_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_INTRA_NODE_R3_THRESHOLD");
    rc = MPL_env2int("MV2_INTRA_NODE_R3_THRESHOLD", &(MV2_INTRA_NODE_R3_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_INTRA_NODE_R3_THRESHOLD");

    defaultval.d = 4096;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_INTER_NODE_R3_THRESHOLD, /* name */
        &MV2_INTER_NODE_R3_THRESHOLD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_INTER_NODE_R3_THRESHOLD = defaultval.d;
    rc = MPL_env2int("UCR_INTER_NODE_R3_THRESHOLD", &(MV2_INTER_NODE_R3_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_INTER_NODE_R3_THRESHOLD");
    rc = MPL_env2int("MV2_INTER_NODE_R3_THRESHOLD", &(MV2_INTER_NODE_R3_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_INTER_NODE_R3_THRESHOLD");

    defaultval.d = 32768;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_R3_NOCACHE_THRESHOLD, /* name */
        &MV2_R3_NOCACHE_THRESHOLD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "The value of this variable controls what message sizes go over the R3 rendezvous protocol when the registration cache is disabled (MV2_USE_LAZY_MEM_UNREGISTER=0). Messages above this message size use MV2_RNDV_PROTOCOL.");
    MV2_R3_NOCACHE_THRESHOLD = defaultval.d;
    rc = MPL_env2int("UCR_R3_NOCACHE_THRESHOLD", &(MV2_R3_NOCACHE_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_R3_NOCACHE_THRESHOLD");
    rc = MPL_env2int("MV2_R3_NOCACHE_THRESHOLD", &(MV2_R3_NOCACHE_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_R3_NOCACHE_THRESHOLD");

    defaultval.d = (512 * 1024);
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_MAX_R3_PENDING_DATA, /* name */
        &MV2_MAX_R3_PENDING_DATA, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_MAX_R3_PENDING_DATA = defaultval.d;
    rc = MPL_env2int("UCR_MAX_R3_PENDING_DATA", &(MV2_MAX_R3_PENDING_DATA));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_MAX_R3_PENDING_DATA");
    rc = MPL_env2int("MV2_MAX_R3_PENDING_DATA", &(MV2_MAX_R3_PENDING_DATA));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_MAX_R3_PENDING_DATA");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_LIMIC2_COLL, /* name */
        &MV2_USE_LIMIC2_COLL, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_USE_LIMIC2_COLL = defaultval.d;
    rc = MPL_env2int("UCR_USE_LIMIC2_COLL", &(MV2_USE_LIMIC2_COLL));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_LIMIC2_COLL");
    rc = MPL_env2int("MV2_USE_LIMIC2_COLL", &(MV2_USE_LIMIC2_COLL));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_LIMIC2_COLL");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SMP_USE_MAX_SWITCH, /* name */
        &MV2_SMP_USE_MAX_SWITCH, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_SMP_USE_MAX_SWITCH = defaultval.d;
    rc = MPL_env2int("UCR_SMP_USE_MAX_SWITCH", &(MV2_SMP_USE_MAX_SWITCH));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SMP_USE_MAX_SWITCH");
    rc = MPL_env2int("MV2_SMP_USE_MAX_SWITCH", &(MV2_SMP_USE_MAX_SWITCH));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SMP_USE_MAX_SWITCH");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_SMP_PIPELINE, /* name */
        &MV2_CUDA_SMP_PIPELINE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_SMP_PIPELINE = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_SMP_PIPELINE", &(MV2_CUDA_SMP_PIPELINE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_SMP_PIPELINE");
    rc = MPL_env2int("MV2_CUDA_SMP_PIPELINE", &(MV2_CUDA_SMP_PIPELINE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_SMP_PIPELINE");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SMP_DELAY_SHMEM_POOL_INIT, /* name */
        &MV2_SMP_DELAY_SHMEM_POOL_INIT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_SMP_DELAY_SHMEM_POOL_INIT = defaultval.d;
    rc = MPL_env2int("UCR_SMP_DELAY_SHMEM_POOL_INIT", &(MV2_SMP_DELAY_SHMEM_POOL_INIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SMP_DELAY_SHMEM_POOL_INIT");
    rc = MPL_env2int("MV2_SMP_DELAY_SHMEM_POOL_INIT", &(MV2_SMP_DELAY_SHMEM_POOL_INIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SMP_DELAY_SHMEM_POOL_INIT");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SMP_PRIORITY_POLLING, /* name */
        &MV2_SMP_PRIORITY_POLLING, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_SMP_PRIORITY_POLLING = defaultval.d;
    rc = MPL_env2int("UCR_SMP_PRIORITY_POLLING", &(MV2_SMP_PRIORITY_POLLING));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SMP_PRIORITY_POLLING");
    rc = MPL_env2int("MV2_SMP_PRIORITY_POLLING", &(MV2_SMP_PRIORITY_POLLING));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SMP_PRIORITY_POLLING");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SMP_NUM_SEND_BUFFER, /* name */
        &MV2_SMP_NUM_SEND_BUFFER, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This parameter defines the number of internal send buffers for sending intra-node messages larger than MV2_SMP_EAGERSIZE.");
    MV2_SMP_NUM_SEND_BUFFER = defaultval.d;
    rc = MPL_env2int("UCR_SMP_NUM_SEND_BUFFER", &(MV2_SMP_NUM_SEND_BUFFER));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SMP_NUM_SEND_BUFFER");
    rc = MPL_env2int("MV2_SMP_NUM_SEND_BUFFER", &(MV2_SMP_NUM_SEND_BUFFER));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SMP_NUM_SEND_BUFFER");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SMP_BATCH_SIZE, /* name */
        &MV2_SMP_BATCH_SIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_SMP_BATCH_SIZE = defaultval.d;
    rc = MPL_env2int("UCR_SMP_BATCH_SIZE", &(MV2_SMP_BATCH_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SMP_BATCH_SIZE");
    rc = MPL_env2int("MV2_SMP_BATCH_SIZE", &(MV2_SMP_BATCH_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SMP_BATCH_SIZE");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SMP_SEND_BUF_SIZE, /* name */
        &MV2_SMP_SEND_BUF_SIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This parameter defines the packet size when sending intra-node messages larger than MV2_SMP_EAGERSIZE.");
    MV2_SMP_SEND_BUF_SIZE = defaultval.d;
    rc = MPL_env2int("UCR_SMP_SEND_BUF_SIZE", &(MV2_SMP_SEND_BUF_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SMP_SEND_BUF_SIZE");
    rc = MPL_env2int("MV2_SMP_SEND_BUF_SIZE", &(MV2_SMP_SEND_BUF_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SMP_SEND_BUF_SIZE");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_OPT_EAGER_RECV, /* name */
        &MV2_USE_OPT_EAGER_RECV, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_USE_OPT_EAGER_RECV = defaultval.d;
    rc = MPL_env2int("UCR_USE_OPT_EAGER_RECV", &(MV2_USE_OPT_EAGER_RECV));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_OPT_EAGER_RECV");
    rc = MPL_env2int("MV2_USE_OPT_EAGER_RECV", &(MV2_USE_OPT_EAGER_RECV));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_OPT_EAGER_RECV");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_NUM_NODES_IN_JOB, /* name */
        &MV2_NUM_NODES_IN_JOB, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_NUM_NODES_IN_JOB = defaultval.d;
    rc = MPL_env2int("UCR_NUM_NODES_IN_JOB", &(MV2_NUM_NODES_IN_JOB));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_NUM_NODES_IN_JOB");
    rc = MPL_env2int("MV2_NUM_NODES_IN_JOB", &(MV2_NUM_NODES_IN_JOB));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_NUM_NODES_IN_JOB");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_MCAST, /* name */
        &MV2_USE_MCAST, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Set this to 1, to enable hardware multicast support in collective communication.");
    MV2_USE_MCAST = defaultval.d;
    rc = MPL_env2int("UCR_USE_MCAST", &(MV2_USE_MCAST));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_MCAST");
    rc = MPL_env2int("MV2_USE_MCAST", &(MV2_USE_MCAST));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_MCAST");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_RDMA_CM_MCAST, /* name */
        &MV2_USE_RDMA_CM_MCAST, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This parameter enables support for RDMA_CM based multicast group setup. Requires the parameter MV2_USE_MCAST to be set to 1.");
    MV2_USE_RDMA_CM_MCAST = defaultval.d;
    rc = MPL_env2int("UCR_USE_RDMA_CM_MCAST", &(MV2_USE_RDMA_CM_MCAST));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_RDMA_CM_MCAST");
    rc = MPL_env2int("MV2_USE_RDMA_CM_MCAST", &(MV2_USE_RDMA_CM_MCAST));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_RDMA_CM_MCAST");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_QOS, /* name */
        &MV2_USE_QOS, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_USE_QOS = defaultval.d;
    rc = MPL_env2int("UCR_USE_QOS", &(MV2_USE_QOS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_QOS");
    rc = MPL_env2int("MV2_USE_QOS", &(MV2_USE_QOS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_QOS");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_3DTORUS_SUPPORT, /* name */
        &MV2_3DTORUS_SUPPORT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_3DTORUS_SUPPORT = defaultval.d;
    rc = MPL_env2int("UCR_3DTORUS_SUPPORT", &(MV2_3DTORUS_SUPPORT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_3DTORUS_SUPPORT");
    rc = MPL_env2int("MV2_3DTORUS_SUPPORT", &(MV2_3DTORUS_SUPPORT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_3DTORUS_SUPPORT");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_PATH_SL_QUERY, /* name */
        &MV2_PATH_SL_QUERY, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_PATH_SL_QUERY = defaultval.d;
    rc = MPL_env2int("UCR_PATH_SL_QUERY", &(MV2_PATH_SL_QUERY));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_PATH_SL_QUERY");
    rc = MPL_env2int("MV2_PATH_SL_QUERY", &(MV2_PATH_SL_QUERY));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_PATH_SL_QUERY");

    defaultval.d = 8;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_NUM_SLS, /* name */
        &MV2_NUM_SLS, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_NUM_SLS = defaultval.d;
    rc = MPL_env2int("UCR_NUM_SLS", &(MV2_NUM_SLS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_NUM_SLS");
    rc = MPL_env2int("MV2_NUM_SLS", &(MV2_NUM_SLS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_NUM_SLS");

    defaultval.d = 20;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_NUM_SA_QUERY_RETRIES, /* name */
        &MV2_NUM_SA_QUERY_RETRIES, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Number of times the MPI library will attempt to query the subnet to obtain the path record information before giving up.");
    MV2_NUM_SA_QUERY_RETRIES = defaultval.d;
    rc = MPL_env2int("UCR_NUM_SA_QUERY_RETRIES", &(MV2_NUM_SA_QUERY_RETRIES));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_NUM_SA_QUERY_RETRIES");
    rc = MPL_env2int("MV2_NUM_SA_QUERY_RETRIES", &(MV2_NUM_SA_QUERY_RETRIES));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_NUM_SA_QUERY_RETRIES");

    defaultval.d = 20;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_MAX_RDMA_CONNECT_ATTEMPTS, /* name */
        &MV2_MAX_RDMA_CONNECT_ATTEMPTS, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_MAX_RDMA_CONNECT_ATTEMPTS = defaultval.d;
    rc = MPL_env2int("UCR_MAX_RDMA_CONNECT_ATTEMPTS", &(MV2_MAX_RDMA_CONNECT_ATTEMPTS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_MAX_RDMA_CONNECT_ATTEMPTS");
    rc = MPL_env2int("MV2_MAX_RDMA_CONNECT_ATTEMPTS", &(MV2_MAX_RDMA_CONNECT_ATTEMPTS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_MAX_RDMA_CONNECT_ATTEMPTS");

    defaultval.d = 100;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_RDMA_CM_CONNECT_RETRY_INTERVAL, /* name */
        &MV2_RDMA_CM_CONNECT_RETRY_INTERVAL, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_RDMA_CM_CONNECT_RETRY_INTERVAL = defaultval.d;
    rc = MPL_env2int("UCR_RDMA_CM_CONNECT_RETRY_INTERVAL", &(MV2_RDMA_CM_CONNECT_RETRY_INTERVAL));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_RDMA_CM_CONNECT_RETRY_INTERVAL");
    rc = MPL_env2int("MV2_RDMA_CM_CONNECT_RETRY_INTERVAL", &(MV2_RDMA_CM_CONNECT_RETRY_INTERVAL));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_RDMA_CM_CONNECT_RETRY_INTERVAL");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_HSAM, /* name */
        &MV2_USE_HSAM, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This parameter is used for utilizing hot-spot avoidance with InfiniBand clusters. To leverage this functionality, the subnet should be configured with lmc greater than zero.");
    MV2_USE_HSAM = defaultval.d;
    rc = MPL_env2int("UCR_USE_HSAM", &(MV2_USE_HSAM));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_HSAM");
    rc = MPL_env2int("MV2_USE_HSAM", &(MV2_USE_HSAM));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_HSAM");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_APM, /* name */
        &MV2_USE_APM, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This parameter is used for recovery from network faults using Automatic Path Migration. This functionality is beneficial in the presence of multiple paths in the network, which can be enabled by using lmc mechanism.");
    MV2_USE_APM = defaultval.d;
    rc = MPL_env2int("UCR_USE_APM", &(MV2_USE_APM));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_APM");
    rc = MPL_env2int("MV2_USE_APM", &(MV2_USE_APM));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_APM");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_APM_TEST, /* name */
        &MV2_USE_APM_TEST, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This parameter is used for testing the Automatic Path Migration functionality. It periodically moves the alternate path as the primary path of communication and re-loads another alternate path.");
    MV2_USE_APM_TEST = defaultval.d;
    rc = MPL_env2int("UCR_USE_APM_TEST", &(MV2_USE_APM_TEST));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_APM_TEST");
    rc = MPL_env2int("MV2_USE_APM_TEST", &(MV2_USE_APM_TEST));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_APM_TEST");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_IWARP_MODE, /* name */
        &MV2_USE_IWARP_MODE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This parameter enables the library to run in iWARP mode.");
    MV2_USE_IWARP_MODE = defaultval.d;
    rc = MPL_env2int("UCR_USE_IWARP_MODE", &(MV2_USE_IWARP_MODE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_IWARP_MODE");
    rc = MPL_env2int("MV2_USE_IWARP_MODE", &(MV2_USE_IWARP_MODE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_IWARP_MODE");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_RDMA_CM, /* name */
        &MV2_USE_RDMA_CM, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This parameter enables the use of RDMA CM for establishing the connections.");
    MV2_USE_RDMA_CM = defaultval.d;
    rc = MPL_env2int("UCR_USE_RDMA_CM", &(MV2_USE_RDMA_CM));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_RDMA_CM");
    rc = MPL_env2int("MV2_USE_RDMA_CM", &(MV2_USE_RDMA_CM));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_RDMA_CM");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_RDMA_CM_MULTI_SUBNET_SUPPORT, /* name */
        &MV2_RDMA_CM_MULTI_SUBNET_SUPPORT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This parameter allows MPI jobs to be run across multiple subnets interconnected by InfiniBand routers. Note that this requires RDMA_CM support to be enabled at configure time and runtime. Note that, RDMA_CM support is enabled by default at configure time.");
    MV2_RDMA_CM_MULTI_SUBNET_SUPPORT = defaultval.d;
    rc = MPL_env2int("UCR_RDMA_CM_MULTI_SUBNET_SUPPORT", &(MV2_RDMA_CM_MULTI_SUBNET_SUPPORT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_RDMA_CM_MULTI_SUBNET_SUPPORT");
    rc = MPL_env2int("MV2_RDMA_CM_MULTI_SUBNET_SUPPORT", &(MV2_RDMA_CM_MULTI_SUBNET_SUPPORT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_RDMA_CM_MULTI_SUBNET_SUPPORT");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SUPPORT_DPM, /* name */
        &MV2_SUPPORT_DPM, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This option enables the dynamic process management interface and on-demand connection management.");
    MV2_SUPPORT_DPM = defaultval.d;
    rc = MPL_env2int("UCR_SUPPORT_DPM", &(MV2_SUPPORT_DPM));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SUPPORT_DPM");
    rc = MPL_env2int("MV2_SUPPORT_DPM", &(MV2_SUPPORT_DPM));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SUPPORT_DPM");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_ON_DEMAND_THRESHOLD, /* name */
        &MV2_ON_DEMAND_THRESHOLD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This defines threshold for enabling on-demand connection management scheme. When the size of the job is larger than the threshold value, on-demand connection management will be used.");
    MV2_ON_DEMAND_THRESHOLD = defaultval.d;
    rc = MPL_env2int("UCR_ON_DEMAND_THRESHOLD", &(MV2_ON_DEMAND_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_ON_DEMAND_THRESHOLD");
    rc = MPL_env2int("MV2_ON_DEMAND_THRESHOLD", &(MV2_ON_DEMAND_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_ON_DEMAND_THRESHOLD");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_XRC, /* name */
        &MV2_USE_XRC, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Use the XRC InfiniBand transport available since Mellanox ConnectX adapters. This features requires OFED version later than 1.3. It also automatically enables SRQ and ON-DEMAND connection management. Note that the MVAPICH2 library needs to have been configured with -enable-xrc=yes to use this feature.");
    MV2_USE_XRC = defaultval.d;
    rc = MPL_env2int("UCR_USE_XRC", &(MV2_USE_XRC));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_XRC");
    rc = MPL_env2int("MV2_USE_XRC", &(MV2_USE_XRC));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_XRC");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_SRQ, /* name */
        &MV2_USE_SRQ, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Setting this parameter enables MVAPICH2 to use shared receive queue.");
    MV2_USE_SRQ = defaultval.d;
    rc = MPL_env2int("UCR_USE_SRQ", &(MV2_USE_SRQ));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_SRQ");
    rc = MPL_env2int("MV2_USE_SRQ", &(MV2_USE_SRQ));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_SRQ");

    defaultval.d = 32;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_IWARP_MULTIPLE_CQ_THRESHOLD, /* name */
        &MV2_IWARP_MULTIPLE_CQ_THRESHOLD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This defines the process size beyond which we use multiple completion queues for iWARP interface.");
    MV2_IWARP_MULTIPLE_CQ_THRESHOLD = defaultval.d;
    rc = MPL_env2int("UCR_IWARP_MULTIPLE_CQ_THRESHOLD", &(MV2_IWARP_MULTIPLE_CQ_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_IWARP_MULTIPLE_CQ_THRESHOLD");
    rc = MPL_env2int("MV2_IWARP_MULTIPLE_CQ_THRESHOLD", &(MV2_IWARP_MULTIPLE_CQ_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_IWARP_MULTIPLE_CQ_THRESHOLD");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_LAZY_MEM_UNREGISTER, /* name */
        &MV2_USE_LAZY_MEM_UNREGISTER, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Setting this parameter enables MVAPICH2 to use memory registration cache.");
    MV2_USE_LAZY_MEM_UNREGISTER = defaultval.d;
    rc = MPL_env2int("UCR_USE_LAZY_MEM_UNREGISTER", &(MV2_USE_LAZY_MEM_UNREGISTER));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_LAZY_MEM_UNREGISTER");
    rc = MPL_env2int("MV2_USE_LAZY_MEM_UNREGISTER", &(MV2_USE_LAZY_MEM_UNREGISTER));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_LAZY_MEM_UNREGISTER");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_RMA_FAST_PATH, /* name */
        &MV2_USE_RMA_FAST_PATH, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_USE_RMA_FAST_PATH = defaultval.d;
    rc = MPL_env2int("UCR_USE_RMA_FAST_PATH", &(MV2_USE_RMA_FAST_PATH));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_RMA_FAST_PATH");
    rc = MPL_env2int("MV2_USE_RMA_FAST_PATH", &(MV2_USE_RMA_FAST_PATH));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_RMA_FAST_PATH");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_FORCE_IB_ATOMIC, /* name */
        &MV2_FORCE_IB_ATOMIC, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_FORCE_IB_ATOMIC = defaultval.d;
    rc = MPL_env2int("UCR_FORCE_IB_ATOMIC", &(MV2_FORCE_IB_ATOMIC));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_FORCE_IB_ATOMIC");
    rc = MPL_env2int("MV2_FORCE_IB_ATOMIC", &(MV2_FORCE_IB_ATOMIC));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_FORCE_IB_ATOMIC");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_RDMA_ONE_SIDED, /* name */
        &MV2_USE_RDMA_ONE_SIDED, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Setting this parameter allows MVAPICH2 to use optimized one sided implementation based RDMA operations.");
    MV2_USE_RDMA_ONE_SIDED = defaultval.d;
    rc = MPL_env2int("UCR_USE_RDMA_ONE_SIDED", &(MV2_USE_RDMA_ONE_SIDED));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_RDMA_ONE_SIDED");
    rc = MPL_env2int("MV2_USE_RDMA_ONE_SIDED", &(MV2_USE_RDMA_ONE_SIDED));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_RDMA_ONE_SIDED");

    defaultval.d = 5;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_RNDV_EXT_SENDQ_SIZE, /* name */
        &MV2_RNDV_EXT_SENDQ_SIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_RNDV_EXT_SENDQ_SIZE = defaultval.d;
    rc = MPL_env2int("UCR_RNDV_EXT_SENDQ_SIZE", &(MV2_RNDV_EXT_SENDQ_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_RNDV_EXT_SENDQ_SIZE");
    rc = MPL_env2int("MV2_RNDV_EXT_SENDQ_SIZE", &(MV2_RNDV_EXT_SENDQ_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_RNDV_EXT_SENDQ_SIZE");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_RDMA_NUM_EXTRA_POLLS, /* name */
        &MV2_RDMA_NUM_EXTRA_POLLS, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_RDMA_NUM_EXTRA_POLLS = defaultval.d;
    rc = MPL_env2int("UCR_RDMA_NUM_EXTRA_POLLS", &(MV2_RDMA_NUM_EXTRA_POLLS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_RDMA_NUM_EXTRA_POLLS");
    rc = MPL_env2int("MV2_RDMA_NUM_EXTRA_POLLS", &(MV2_RDMA_NUM_EXTRA_POLLS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_RDMA_NUM_EXTRA_POLLS");

    defaultval.d = 6;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_COALESCE_THRESHOLD, /* name */
        &MV2_COALESCE_THRESHOLD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This parameter determines the threshold for message coalescing.");
    MV2_COALESCE_THRESHOLD = defaultval.d;
    rc = MPL_env2int("UCR_COALESCE_THRESHOLD", &(MV2_COALESCE_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_COALESCE_THRESHOLD");
    rc = MPL_env2int("MV2_COALESCE_THRESHOLD", &(MV2_COALESCE_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_COALESCE_THRESHOLD");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_COALESCE, /* name */
        &MV2_USE_COALESCE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Setting this parameter enables message coalescing to increase small message throughput.");
    MV2_USE_COALESCE = defaultval.d;
    rc = MPL_env2int("UCR_USE_COALESCE", &(MV2_USE_COALESCE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_COALESCE");
    rc = MPL_env2int("MV2_USE_COALESCE", &(MV2_USE_COALESCE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_COALESCE");

    defaultval.d = 5000;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SPIN_COUNT, /* name */
        &MV2_SPIN_COUNT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_SPIN_COUNT = defaultval.d;
    rc = MPL_env2int("UCR_SPIN_COUNT", &(MV2_SPIN_COUNT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SPIN_COUNT");
    rc = MPL_env2int("MV2_SPIN_COUNT", &(MV2_SPIN_COUNT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SPIN_COUNT");

    defaultval.str = (const char *) NULL;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_CHAR,
        MV2_PROCESS_TO_RAIL_MAPPING, /* name */
        &MV2_PROCESS_TO_RAIL_MAPPING, /* address */
        MV2_MAX_STRLEN, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "When MV2_RAIL_SHARING_POLICY is set to the value \"FIXED_MAPPING\" this variable decides the manner in which the HCAs will be mapped to the rails. The <CUSTOM LIST> is colon(:) separated list with the HCA ranks specified. e.g. 0:1:1:0. This list must map equally to the number of local processes on the nodes failing which, the default policy will be used. Similarly the number of processes on each node must be the same.");
    tmp_str = defaultval.str;
    rc = MPL_env2str("UCR_PROCESS_TO_RAIL_MAPPING", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_PROCESS_TO_RAIL_MAPPING");
    rc = MPL_env2str("MV2_PROCESS_TO_RAIL_MAPPING", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_PROCESS_TO_RAIL_MAPPING");
    if (tmp_str != NULL) {
        MV2_PROCESS_TO_RAIL_MAPPING = MPL_strdup(tmp_str);
        MV2_assert(MV2_PROCESS_TO_RAIL_MAPPING);
        if (MV2_PROCESS_TO_RAIL_MAPPING == NULL) {
            MPIR_CHKMEM_SETERR(mpi_errno, strlen(tmp_str), "dup of string for MV2_PROCESS_TO_RAIL_MAPPING");
            goto fn_fail;
        }
    }
    else {
        MV2_PROCESS_TO_RAIL_MAPPING = NULL;
    }

    defaultval.str = (const char *) "USE_FIRST";
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_CHAR,
        MV2_SM_SCHEDULING, /* name */
        &MV2_SM_SCHEDULING, /* address */
        MV2_MAX_STRLEN, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    tmp_str = defaultval.str;
    rc = MPL_env2str("UCR_SM_SCHEDULING", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SM_SCHEDULING");
    rc = MPL_env2str("MV2_SM_SCHEDULING", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SM_SCHEDULING");
    if (tmp_str != NULL) {
        MV2_SM_SCHEDULING = MPL_strdup(tmp_str);
        MV2_assert(MV2_SM_SCHEDULING);
        if (MV2_SM_SCHEDULING == NULL) {
            MPIR_CHKMEM_SETERR(mpi_errno, strlen(tmp_str), "dup of string for MV2_SM_SCHEDULING");
            goto fn_fail;
        }
    }
    else {
        MV2_SM_SCHEDULING = NULL;
    }

    defaultval.str = (const char *) "ROUND_ROBIN";
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_CHAR,
        MV2_SMALL_MSG_RAIL_SHARING_POLICY, /* name */
        &MV2_SMALL_MSG_RAIL_SHARING_POLICY, /* address */
        MV2_MAX_STRLEN, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This specifies the policy that will be used to assign HCAs to each of the processes with small message sizes.");
    tmp_str = defaultval.str;
    rc = MPL_env2str("UCR_SMALL_MSG_RAIL_SHARING_POLICY", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SMALL_MSG_RAIL_SHARING_POLICY");
    rc = MPL_env2str("MV2_SMALL_MSG_RAIL_SHARING_POLICY", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SMALL_MSG_RAIL_SHARING_POLICY");
    if (tmp_str != NULL) {
        MV2_SMALL_MSG_RAIL_SHARING_POLICY = MPL_strdup(tmp_str);
        MV2_assert(MV2_SMALL_MSG_RAIL_SHARING_POLICY);
        if (MV2_SMALL_MSG_RAIL_SHARING_POLICY == NULL) {
            MPIR_CHKMEM_SETERR(mpi_errno, strlen(tmp_str), "dup of string for MV2_SMALL_MSG_RAIL_SHARING_POLICY");
            goto fn_fail;
        }
    }
    else {
        MV2_SMALL_MSG_RAIL_SHARING_POLICY = NULL;
    }

    defaultval.str = (const char *) "ROUND_ROBIN";
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_CHAR,
        MV2_MED_MSG_RAIL_SHARING_POLICY, /* name */
        &MV2_MED_MSG_RAIL_SHARING_POLICY, /* address */
        MV2_MAX_STRLEN, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This specifies the policy that will be used to assign HCAs to each of the processes with medium message sizes.");
    tmp_str = defaultval.str;
    rc = MPL_env2str("UCR_MED_MSG_RAIL_SHARING_POLICY", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_MED_MSG_RAIL_SHARING_POLICY");
    rc = MPL_env2str("MV2_MED_MSG_RAIL_SHARING_POLICY", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_MED_MSG_RAIL_SHARING_POLICY");
    if (tmp_str != NULL) {
        MV2_MED_MSG_RAIL_SHARING_POLICY = MPL_strdup(tmp_str);
        MV2_assert(MV2_MED_MSG_RAIL_SHARING_POLICY);
        if (MV2_MED_MSG_RAIL_SHARING_POLICY == NULL) {
            MPIR_CHKMEM_SETERR(mpi_errno, strlen(tmp_str), "dup of string for MV2_MED_MSG_RAIL_SHARING_POLICY");
            goto fn_fail;
        }
    }
    else {
        MV2_MED_MSG_RAIL_SHARING_POLICY = NULL;
    }

    defaultval.str = (const char *) NULL;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_CHAR,
        MV2_RAIL_SHARING_POLICY, /* name */
        &MV2_RAIL_SHARING_POLICY, /* address */
        MV2_MAX_STRLEN, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This specifies the policy that will be used to assign HCAs to each of the processes. In the previous versions of MVAPICH2 it was known as MV2_SM_SCHEDULING. Value Domain: USE_FIRST, ROUND_ROBIN, FIXED_MAPPING");
    tmp_str = defaultval.str;
    rc = MPL_env2str("UCR_RAIL_SHARING_POLICY", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_RAIL_SHARING_POLICY");
    rc = MPL_env2str("MV2_RAIL_SHARING_POLICY", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_RAIL_SHARING_POLICY");
    if (tmp_str != NULL) {
        MV2_RAIL_SHARING_POLICY = MPL_strdup(tmp_str);
        MV2_assert(MV2_RAIL_SHARING_POLICY);
        if (MV2_RAIL_SHARING_POLICY == NULL) {
            MPIR_CHKMEM_SETERR(mpi_errno, strlen(tmp_str), "dup of string for MV2_RAIL_SHARING_POLICY");
            goto fn_fail;
        }
    }
    else {
        MV2_RAIL_SHARING_POLICY = NULL;
    }

    defaultval.str = (const char *) NULL;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_CHAR,
        MV2_RNDV_PROTOCOL, /* name */
        &MV2_RNDV_PROTOCOL, /* address */
        MV2_MAX_STRLEN, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "The value of this variable can be set to choose different Rendezvous protocols. RPUT (default RDMA-Write) RGET (RDMA Read based), R3 (send/recv based).");
    tmp_str = defaultval.str;
    rc = MPL_env2str("UCR_RNDV_PROTOCOL", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_RNDV_PROTOCOL");
    rc = MPL_env2str("MV2_RNDV_PROTOCOL", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_RNDV_PROTOCOL");
    if (tmp_str != NULL) {
        MV2_RNDV_PROTOCOL = MPL_strdup(tmp_str);
        MV2_assert(MV2_RNDV_PROTOCOL);
        if (MV2_RNDV_PROTOCOL == NULL) {
            MPIR_CHKMEM_SETERR(mpi_errno, strlen(tmp_str), "dup of string for MV2_RNDV_PROTOCOL");
            goto fn_fail;
        }
    }
    else {
        MV2_RNDV_PROTOCOL = NULL;
    }

    defaultval.str = (const char *) NULL;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_CHAR,
        MV2_SMP_RNDV_PROTOCOL, /* name */
        &MV2_SMP_RNDV_PROTOCOL, /* address */
        MV2_MAX_STRLEN, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    tmp_str = defaultval.str;
    rc = MPL_env2str("UCR_SMP_RNDV_PROTOCOL", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SMP_RNDV_PROTOCOL");
    rc = MPL_env2str("MV2_SMP_RNDV_PROTOCOL", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SMP_RNDV_PROTOCOL");
    if (tmp_str != NULL) {
        MV2_SMP_RNDV_PROTOCOL = MPL_strdup(tmp_str);
        MV2_assert(MV2_SMP_RNDV_PROTOCOL);
        if (MV2_SMP_RNDV_PROTOCOL == NULL) {
            MPIR_CHKMEM_SETERR(mpi_errno, strlen(tmp_str), "dup of string for MV2_SMP_RNDV_PROTOCOL");
            goto fn_fail;
        }
    }
    else {
        MV2_SMP_RNDV_PROTOCOL = NULL;
    }

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SUPPRESS_JOB_STARTUP_PERFORMANCE_WARNING, /* name */
        &MV2_SUPPRESS_JOB_STARTUP_PERFORMANCE_WARNING, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Set to 1 to suppress performance warnings.");
    MV2_SUPPRESS_JOB_STARTUP_PERFORMANCE_WARNING = defaultval.d;
    rc = MPL_env2int("UCR_SUPPRESS_JOB_STARTUP_PERFORMANCE_WARNING", &(MV2_SUPPRESS_JOB_STARTUP_PERFORMANCE_WARNING));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SUPPRESS_JOB_STARTUP_PERFORMANCE_WARNING");
    rc = MPL_env2int("MV2_SUPPRESS_JOB_STARTUP_PERFORMANCE_WARNING", &(MV2_SUPPRESS_JOB_STARTUP_PERFORMANCE_WARNING));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SUPPRESS_JOB_STARTUP_PERFORMANCE_WARNING");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_RDMA_FAST_PATH, /* name */
        &MV2_USE_RDMA_FAST_PATH, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Setting this parameter enables MVAPICH2 to use adaptive RDMA fast path features for OFA-IB-CH3 interface.");
    MV2_USE_RDMA_FAST_PATH = defaultval.d;
    rc = MPL_env2int("UCR_USE_RDMA_FAST_PATH", &(MV2_USE_RDMA_FAST_PATH));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_RDMA_FAST_PATH");
    rc = MPL_env2int("MV2_USE_RDMA_FAST_PATH", &(MV2_USE_RDMA_FAST_PATH));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_RDMA_FAST_PATH");

    defaultval.d = 4096;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_RDMA_FAST_PATH_BUF_SIZE, /* name */
        &MV2_RDMA_FAST_PATH_BUF_SIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "The size of the buffer used in RDMA fast path communication. This value will be ineffective if MV2_USE_RDMA_FAST_PATH is not set");
    MV2_RDMA_FAST_PATH_BUF_SIZE = defaultval.d;
    rc = MPL_env2int("UCR_RDMA_FAST_PATH_BUF_SIZE", &(MV2_RDMA_FAST_PATH_BUF_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_RDMA_FAST_PATH_BUF_SIZE");
    rc = MPL_env2int("MV2_RDMA_FAST_PATH_BUF_SIZE", &(MV2_RDMA_FAST_PATH_BUF_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_RDMA_FAST_PATH_BUF_SIZE");

    defaultval.d = 64;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_POLLING_SET_LIMIT, /* name */
        &MV2_POLLING_SET_LIMIT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_POLLING_SET_LIMIT = defaultval.d;
    rc = MPL_env2int("UCR_POLLING_SET_LIMIT", &(MV2_POLLING_SET_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_POLLING_SET_LIMIT");
    rc = MPL_env2int("MV2_POLLING_SET_LIMIT", &(MV2_POLLING_SET_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_POLLING_SET_LIMIT");

    defaultval.d = 256;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_POLLING_SET_THRESHOLD, /* name */
        &MV2_POLLING_SET_THRESHOLD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_POLLING_SET_THRESHOLD = defaultval.d;
    rc = MPL_env2int("UCR_POLLING_SET_THRESHOLD", &(MV2_POLLING_SET_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_POLLING_SET_THRESHOLD");
    rc = MPL_env2int("MV2_POLLING_SET_THRESHOLD", &(MV2_POLLING_SET_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_POLLING_SET_THRESHOLD");

    defaultval.d = 32;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_RDMA_EAGER_LIMIT, /* name */
        &MV2_RDMA_EAGER_LIMIT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_RDMA_EAGER_LIMIT = defaultval.d;
    rc = MPL_env2int("UCR_RDMA_EAGER_LIMIT", &(MV2_RDMA_EAGER_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_RDMA_EAGER_LIMIT");
    rc = MPL_env2int("MV2_RDMA_EAGER_LIMIT", &(MV2_RDMA_EAGER_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_RDMA_EAGER_LIMIT");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_NUM_RDMA_BUFFER, /* name */
        &MV2_NUM_RDMA_BUFFER, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "The number of RDMA buffers used for the RDMA fast path. This fast path is used to reduce latency and overhead of small data and control messages. This value will be ineffective if MV2_USE_RDMA_FAST_PATH is not set.");
    MV2_NUM_RDMA_BUFFER = defaultval.d;
    rc = MPL_env2int("UCR_NUM_RDMA_BUFFER", &(MV2_NUM_RDMA_BUFFER));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_NUM_RDMA_BUFFER");
    rc = MPL_env2int("MV2_NUM_RDMA_BUFFER", &(MV2_NUM_RDMA_BUFFER));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_NUM_RDMA_BUFFER");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_RDMA_FAST_PATH_PREALLOCATE_BUFFERS, /* name */
        &MV2_RDMA_FAST_PATH_PREALLOCATE_BUFFERS, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_RDMA_FAST_PATH_PREALLOCATE_BUFFERS = defaultval.d;
    rc = MPL_env2int("UCR_RDMA_FAST_PATH_PREALLOCATE_BUFFERS", &(MV2_RDMA_FAST_PATH_PREALLOCATE_BUFFERS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_RDMA_FAST_PATH_PREALLOCATE_BUFFERS");
    rc = MPL_env2int("MV2_RDMA_FAST_PATH_PREALLOCATE_BUFFERS", &(MV2_RDMA_FAST_PATH_PREALLOCATE_BUFFERS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_RDMA_FAST_PATH_PREALLOCATE_BUFFERS");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SYSREPORT, /* name */
        &MV2_SYSREPORT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_SYSREPORT = defaultval.d;
    rc = MPL_env2int("UCR_SYSREPORT", &(MV2_SYSREPORT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SYSREPORT");
    rc = MPL_env2int("MV2_SYSREPORT", &(MV2_SYSREPORT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SYSREPORT");

    defaultval.str = (const char *) NULL;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_CHAR,
        MV2_DEFAULT_MTU, /* name */
        &MV2_DEFAULT_MTU, /* address */
        MV2_MAX_STRLEN, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "The internal MTU size. For OFA-IB-CH3, this parameter should be a string instead of an integer. Valid values are: IBV_MTU_256, IBV_MTU_512, IBV_MTU_1024, IBV_MTU_2048, IBV_MTU_4096.");
    tmp_str = defaultval.str;
    rc = MPL_env2str("UCR_DEFAULT_MTU", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_DEFAULT_MTU");
    rc = MPL_env2str("MV2_DEFAULT_MTU", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_DEFAULT_MTU");
    if (tmp_str != NULL) {
        MV2_DEFAULT_MTU = MPL_strdup(tmp_str);
        MV2_assert(MV2_DEFAULT_MTU);
        if (MV2_DEFAULT_MTU == NULL) {
            MPIR_CHKMEM_SETERR(mpi_errno, strlen(tmp_str), "dup of string for MV2_DEFAULT_MTU");
            goto fn_fail;
        }
    }
    else {
        MV2_DEFAULT_MTU = NULL;
    }

    defaultval.d = 96;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_NUM_CQES_PER_POLL, /* name */
        &MV2_NUM_CQES_PER_POLL, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Set this to 1, to enable hardware multicast support in collective communication");
    MV2_NUM_CQES_PER_POLL = defaultval.d;
    rc = MPL_env2int("UCR_NUM_CQES_PER_POLL", &(MV2_NUM_CQES_PER_POLL));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_NUM_CQES_PER_POLL");
    rc = MPL_env2int("MV2_NUM_CQES_PER_POLL", &(MV2_NUM_CQES_PER_POLL));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_NUM_CQES_PER_POLL");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_NUM_PORTS, /* name */
        &MV2_NUM_PORTS, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This parameter indicates number of ports per InfiniBand adapter to be used for communication per adapter on an end node.");
    MV2_NUM_PORTS = defaultval.d;
    rc = MPL_env2int("UCR_NUM_PORTS", &(MV2_NUM_PORTS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_NUM_PORTS");
    rc = MPL_env2int("MV2_NUM_PORTS", &(MV2_NUM_PORTS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_NUM_PORTS");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_NUM_QP_PER_PORT, /* name */
        &MV2_NUM_QP_PER_PORT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This parameter indicates number of queue pairs per port to be used for communication on an end node. This is useful in the presence of multiple send/recv engines available per port for data transfer.");
    MV2_NUM_QP_PER_PORT = defaultval.d;
    rc = MPL_env2int("UCR_NUM_QP_PER_PORT", &(MV2_NUM_QP_PER_PORT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_NUM_QP_PER_PORT");
    rc = MPL_env2int("MV2_NUM_QP_PER_PORT", &(MV2_NUM_QP_PER_PORT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_NUM_QP_PER_PORT");

    defaultval.d = (2 * 1024 * 1024);
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_PIN_POOL_SIZE, /* name */
        &MV2_PIN_POOL_SIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_PIN_POOL_SIZE = defaultval.d;
    rc = MPL_env2int("UCR_PIN_POOL_SIZE", &(MV2_PIN_POOL_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_PIN_POOL_SIZE");
    rc = MPL_env2int("MV2_PIN_POOL_SIZE", &(MV2_PIN_POOL_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_PIN_POOL_SIZE");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_DEFAULT_MAX_CQ_SIZE, /* name */
        &MV2_DEFAULT_MAX_CQ_SIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Setting this value forces a different CQ size. By default the value is 40000 or the max value supported by the hardware. A value of -1 indicates deferal to the hardware/default value.");
    MV2_DEFAULT_MAX_CQ_SIZE = defaultval.d;
    rc = MPL_env2int("UCR_DEFAULT_MAX_CQ_SIZE", &(MV2_DEFAULT_MAX_CQ_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_DEFAULT_MAX_CQ_SIZE");
    rc = MPL_env2int("MV2_DEFAULT_MAX_CQ_SIZE", &(MV2_DEFAULT_MAX_CQ_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_DEFAULT_MAX_CQ_SIZE");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_IBA_EAGER_THRESHOLD, /* name */
        &MV2_IBA_EAGER_THRESHOLD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This specifies the switch point between eager and rendezvous protocol in MVAPICH2. For better performance, the value of MPIR_CVAR_MV2_IBA_EAGER_THRESHOLD should be set the same as MPIR_CVAR_MV2_VBUF_TOTAL_SIZE. The default value is architecture dependent.");
    MV2_IBA_EAGER_THRESHOLD = defaultval.d;
    rc = MPL_env2int("UCR_IBA_EAGER_THRESHOLD", &(MV2_IBA_EAGER_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_IBA_EAGER_THRESHOLD");
    rc = MPL_env2int("MV2_IBA_EAGER_THRESHOLD", &(MV2_IBA_EAGER_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_IBA_EAGER_THRESHOLD");

    defaultval.d = 8192;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_STRIPING_THRESHOLD, /* name */
        &MV2_STRIPING_THRESHOLD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This parameter specifies the message size above which we begin the stripe the message across multiple rails (if present).");
    MV2_STRIPING_THRESHOLD = defaultval.d;
    rc = MPL_env2int("UCR_STRIPING_THRESHOLD", &(MV2_STRIPING_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_STRIPING_THRESHOLD");
    rc = MPL_env2int("MV2_STRIPING_THRESHOLD", &(MV2_STRIPING_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_STRIPING_THRESHOLD");

    defaultval.d = 2048;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_RAIL_SHARING_MED_MSG_THRESHOLD, /* name */
        &MV2_RAIL_SHARING_MED_MSG_THRESHOLD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This specifies the threshold for the message size beyond which striping will take place. In the previous versions of MVAPICH2 it was known as MV2_STRIPING_THRESHOLD.");
    MV2_RAIL_SHARING_MED_MSG_THRESHOLD = defaultval.d;
    rc = MPL_env2int("UCR_RAIL_SHARING_MED_MSG_THRESHOLD", &(MV2_RAIL_SHARING_MED_MSG_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_RAIL_SHARING_MED_MSG_THRESHOLD");
    rc = MPL_env2int("MV2_RAIL_SHARING_MED_MSG_THRESHOLD", &(MV2_RAIL_SHARING_MED_MSG_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_RAIL_SHARING_MED_MSG_THRESHOLD");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_RAIL_SHARING_LARGE_MSG_THRESHOLD, /* name */
        &MV2_RAIL_SHARING_LARGE_MSG_THRESHOLD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This specifies the threshold for the message size beyond which striping will take place. In the previous versions of MVAPICH2 it was known as MV2_STRIPING_THRESHOLD");
    MV2_RAIL_SHARING_LARGE_MSG_THRESHOLD = defaultval.d;
    rc = MPL_env2int("UCR_RAIL_SHARING_LARGE_MSG_THRESHOLD", &(MV2_RAIL_SHARING_LARGE_MSG_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_RAIL_SHARING_LARGE_MSG_THRESHOLD");
    rc = MPL_env2int("MV2_RAIL_SHARING_LARGE_MSG_THRESHOLD", &(MV2_RAIL_SHARING_LARGE_MSG_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_RAIL_SHARING_LARGE_MSG_THRESHOLD");

    defaultval.d = 200;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_DEFAULT_PUT_GET_LIST_SIZE, /* name */
        &MV2_DEFAULT_PUT_GET_LIST_SIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_DEFAULT_PUT_GET_LIST_SIZE = defaultval.d;
    rc = MPL_env2int("UCR_DEFAULT_PUT_GET_LIST_SIZE", &(MV2_DEFAULT_PUT_GET_LIST_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_DEFAULT_PUT_GET_LIST_SIZE");
    rc = MPL_env2int("MV2_DEFAULT_PUT_GET_LIST_SIZE", &(MV2_DEFAULT_PUT_GET_LIST_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_DEFAULT_PUT_GET_LIST_SIZE");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_EAGERSIZE_1SC, /* name */
        &MV2_EAGERSIZE_1SC, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_EAGERSIZE_1SC = defaultval.d;
    rc = MPL_env2int("UCR_EAGERSIZE_1SC", &(MV2_EAGERSIZE_1SC));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_EAGERSIZE_1SC");
    rc = MPL_env2int("MV2_EAGERSIZE_1SC", &(MV2_EAGERSIZE_1SC));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_EAGERSIZE_1SC");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_PUT_FALLBACK_THRESHOLD, /* name */
        &MV2_PUT_FALLBACK_THRESHOLD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This defines the threshold beyond which the MPI_Put implementation is based on direct one sided RDMA operations.");
    MV2_PUT_FALLBACK_THRESHOLD = defaultval.d;
    rc = MPL_env2int("UCR_PUT_FALLBACK_THRESHOLD", &(MV2_PUT_FALLBACK_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_PUT_FALLBACK_THRESHOLD");
    rc = MPL_env2int("MV2_PUT_FALLBACK_THRESHOLD", &(MV2_PUT_FALLBACK_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_PUT_FALLBACK_THRESHOLD");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_GET_FALLBACK_THRESHOLD, /* name */
        &MV2_GET_FALLBACK_THRESHOLD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_GET_FALLBACK_THRESHOLD = defaultval.d;
    rc = MPL_env2int("UCR_GET_FALLBACK_THRESHOLD", &(MV2_GET_FALLBACK_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_GET_FALLBACK_THRESHOLD");
    rc = MPL_env2int("MV2_GET_FALLBACK_THRESHOLD", &(MV2_GET_FALLBACK_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_GET_FALLBACK_THRESHOLD");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_DEFAULT_QP_OUS_RD_ATOM, /* name */
        &MV2_DEFAULT_QP_OUS_RD_ATOM, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "The maximum number of outstanding RDMA reads and atomic operations per QP. Default value is 1 if supported. A value of -1 indicates defering to the hardware support.");
    MV2_DEFAULT_QP_OUS_RD_ATOM = defaultval.d;
    rc = MPL_env2int("UCR_DEFAULT_QP_OUS_RD_ATOM", &(MV2_DEFAULT_QP_OUS_RD_ATOM));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_DEFAULT_QP_OUS_RD_ATOM");
    rc = MPL_env2int("MV2_DEFAULT_QP_OUS_RD_ATOM", &(MV2_DEFAULT_QP_OUS_RD_ATOM));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_DEFAULT_QP_OUS_RD_ATOM");

    defaultval.d = 4;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_DEFAULT_MAX_RDMA_DST_OPS, /* name */
        &MV2_DEFAULT_MAX_RDMA_DST_OPS, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_DEFAULT_MAX_RDMA_DST_OPS = defaultval.d;
    rc = MPL_env2int("UCR_DEFAULT_MAX_RDMA_DST_OPS", &(MV2_DEFAULT_MAX_RDMA_DST_OPS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_DEFAULT_MAX_RDMA_DST_OPS");
    rc = MPL_env2int("MV2_DEFAULT_MAX_RDMA_DST_OPS", &(MV2_DEFAULT_MAX_RDMA_DST_OPS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_DEFAULT_MAX_RDMA_DST_OPS");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_DEFAULT_PSN, /* name */
        &MV2_DEFAULT_PSN, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_DEFAULT_PSN = defaultval.d;
    rc = MPL_env2int("UCR_DEFAULT_PSN", &(MV2_DEFAULT_PSN));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_DEFAULT_PSN");
    rc = MPL_env2int("MV2_DEFAULT_PSN", &(MV2_DEFAULT_PSN));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_DEFAULT_PSN");

    defaultval.str = (const char *) NULL;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_CHAR,
        MV2_DEFAULT_PKEY, /* name */
        &MV2_DEFAULT_PKEY, /* address */
        MV2_MAX_STRLEN, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Select the partition to be used for the job.");
    tmp_str = defaultval.str;
    rc = MPL_env2str("UCR_DEFAULT_PKEY", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_DEFAULT_PKEY");
    rc = MPL_env2str("MV2_DEFAULT_PKEY", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_DEFAULT_PKEY");
    if (tmp_str != NULL) {
        MV2_DEFAULT_PKEY = MPL_strdup(tmp_str);
        MV2_assert(MV2_DEFAULT_PKEY);
        if (MV2_DEFAULT_PKEY == NULL) {
            MPIR_CHKMEM_SETERR(mpi_errno, strlen(tmp_str), "dup of string for MV2_DEFAULT_PKEY");
            goto fn_fail;
        }
    }
    else {
        MV2_DEFAULT_PKEY = NULL;
    }

    defaultval.str = (const char *) NULL;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_CHAR,
        MV2_DEFAULT_QKEY, /* name */
        &MV2_DEFAULT_QKEY, /* address */
        MV2_MAX_STRLEN, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    tmp_str = defaultval.str;
    rc = MPL_env2str("UCR_DEFAULT_QKEY", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_DEFAULT_QKEY");
    rc = MPL_env2str("MV2_DEFAULT_QKEY", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_DEFAULT_QKEY");
    if (tmp_str != NULL) {
        MV2_DEFAULT_QKEY = MPL_strdup(tmp_str);
        MV2_assert(MV2_DEFAULT_QKEY);
        if (MV2_DEFAULT_QKEY == NULL) {
            MPIR_CHKMEM_SETERR(mpi_errno, strlen(tmp_str), "dup of string for MV2_DEFAULT_QKEY");
            goto fn_fail;
        }
    }
    else {
        MV2_DEFAULT_QKEY = NULL;
    }

    defaultval.d = 12;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_DEFAULT_MIN_RNR_TIMER, /* name */
        &MV2_DEFAULT_MIN_RNR_TIMER, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_DEFAULT_MIN_RNR_TIMER = defaultval.d;
    rc = MPL_env2int("UCR_DEFAULT_MIN_RNR_TIMER", &(MV2_DEFAULT_MIN_RNR_TIMER));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_DEFAULT_MIN_RNR_TIMER");
    rc = MPL_env2int("MV2_DEFAULT_MIN_RNR_TIMER", &(MV2_DEFAULT_MIN_RNR_TIMER));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_DEFAULT_MIN_RNR_TIMER");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_DEFAULT_SERVICE_LEVEL, /* name */
        &MV2_DEFAULT_SERVICE_LEVEL, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_DEFAULT_SERVICE_LEVEL = defaultval.d;
    rc = MPL_env2int("UCR_DEFAULT_SERVICE_LEVEL", &(MV2_DEFAULT_SERVICE_LEVEL));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_DEFAULT_SERVICE_LEVEL");
    rc = MPL_env2int("MV2_DEFAULT_SERVICE_LEVEL", &(MV2_DEFAULT_SERVICE_LEVEL));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_DEFAULT_SERVICE_LEVEL");

    defaultval.d = 20;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_DEFAULT_TIME_OUT, /* name */
        &MV2_DEFAULT_TIME_OUT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_DEFAULT_TIME_OUT = defaultval.d;
    rc = MPL_env2int("UCR_DEFAULT_TIME_OUT", &(MV2_DEFAULT_TIME_OUT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_DEFAULT_TIME_OUT");
    rc = MPL_env2int("MV2_DEFAULT_TIME_OUT", &(MV2_DEFAULT_TIME_OUT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_DEFAULT_TIME_OUT");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_DEFAULT_STATIC_RATE, /* name */
        &MV2_DEFAULT_STATIC_RATE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_DEFAULT_STATIC_RATE = defaultval.d;
    rc = MPL_env2int("UCR_DEFAULT_STATIC_RATE", &(MV2_DEFAULT_STATIC_RATE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_DEFAULT_STATIC_RATE");
    rc = MPL_env2int("MV2_DEFAULT_STATIC_RATE", &(MV2_DEFAULT_STATIC_RATE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_DEFAULT_STATIC_RATE");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_DEFAULT_SRC_PATH_BITS, /* name */
        &MV2_DEFAULT_SRC_PATH_BITS, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_DEFAULT_SRC_PATH_BITS = defaultval.d;
    rc = MPL_env2int("UCR_DEFAULT_SRC_PATH_BITS", &(MV2_DEFAULT_SRC_PATH_BITS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_DEFAULT_SRC_PATH_BITS");
    rc = MPL_env2int("MV2_DEFAULT_SRC_PATH_BITS", &(MV2_DEFAULT_SRC_PATH_BITS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_DEFAULT_SRC_PATH_BITS");

    defaultval.d = 7;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_DEFAULT_RETRY_COUNT, /* name */
        &MV2_DEFAULT_RETRY_COUNT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_DEFAULT_RETRY_COUNT = defaultval.d;
    rc = MPL_env2int("UCR_DEFAULT_RETRY_COUNT", &(MV2_DEFAULT_RETRY_COUNT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_DEFAULT_RETRY_COUNT");
    rc = MPL_env2int("MV2_DEFAULT_RETRY_COUNT", &(MV2_DEFAULT_RETRY_COUNT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_DEFAULT_RETRY_COUNT");

    defaultval.d = 7;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_DEFAULT_RNR_RETRY, /* name */
        &MV2_DEFAULT_RNR_RETRY, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_DEFAULT_RNR_RETRY = defaultval.d;
    rc = MPL_env2int("UCR_DEFAULT_RNR_RETRY", &(MV2_DEFAULT_RNR_RETRY));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_DEFAULT_RNR_RETRY");
    rc = MPL_env2int("MV2_DEFAULT_RNR_RETRY", &(MV2_DEFAULT_RNR_RETRY));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_DEFAULT_RNR_RETRY");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_DEFAULT_MAX_SG_LIST, /* name */
        &MV2_DEFAULT_MAX_SG_LIST, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_DEFAULT_MAX_SG_LIST = defaultval.d;
    rc = MPL_env2int("UCR_DEFAULT_MAX_SG_LIST", &(MV2_DEFAULT_MAX_SG_LIST));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_DEFAULT_MAX_SG_LIST");
    rc = MPL_env2int("MV2_DEFAULT_MAX_SG_LIST", &(MV2_DEFAULT_MAX_SG_LIST));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_DEFAULT_MAX_SG_LIST");

    defaultval.d = 64;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_DEFAULT_MAX_SEND_WQE, /* name */
        &MV2_DEFAULT_MAX_SEND_WQE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This specifies the maximum number of send WQEs on each QP. Please note that for OFA-IB-CH3 and OFA-iWARP-CH3, the default value of this parameter will be 16 if the number of processes is larger than 256 for better memory scalability.");
    MV2_DEFAULT_MAX_SEND_WQE = defaultval.d;
    rc = MPL_env2int("UCR_DEFAULT_MAX_SEND_WQE", &(MV2_DEFAULT_MAX_SEND_WQE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_DEFAULT_MAX_SEND_WQE");
    rc = MPL_env2int("MV2_DEFAULT_MAX_SEND_WQE", &(MV2_DEFAULT_MAX_SEND_WQE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_DEFAULT_MAX_SEND_WQE");

    defaultval.d = 5;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CM_WAIT_TIME, /* name */
        &MV2_CM_WAIT_TIME, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CM_WAIT_TIME = defaultval.d;
    rc = MPL_env2int("UCR_CM_WAIT_TIME", &(MV2_CM_WAIT_TIME));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CM_WAIT_TIME");
    rc = MPL_env2int("MV2_CM_WAIT_TIME", &(MV2_CM_WAIT_TIME));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CM_WAIT_TIME");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_UD_HYBRID, /* name */
        &MV2_USE_UD_HYBRID, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Set this to Zero, to disable UD transport in hybrid configuration mode.");
    MV2_USE_UD_HYBRID = defaultval.d;
    rc = MPL_env2int("UCR_USE_UD_HYBRID", &(MV2_USE_UD_HYBRID));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_UD_HYBRID");
    rc = MPL_env2int("MV2_USE_UD_HYBRID", &(MV2_USE_UD_HYBRID));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_UD_HYBRID");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_UD_MTU, /* name */
        &MV2_UD_MTU, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_UD_MTU = defaultval.d;
    rc = MPL_env2int("UCR_UD_MTU", &(MV2_UD_MTU));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_UD_MTU");
    rc = MPL_env2int("MV2_UD_MTU", &(MV2_UD_MTU));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_UD_MTU");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_HYBRID_MAX_RC_CONN, /* name */
        &MV2_HYBRID_MAX_RC_CONN, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Maximum number of RC or XRC connections created per process. This limits the amount of connection memory and prevents HCA QP cache thrashing. Default value is dependent on the process count, setting this value to -1 will use  the default value for the process count.");
    MV2_HYBRID_MAX_RC_CONN = defaultval.d;
    rc = MPL_env2int("UCR_HYBRID_MAX_RC_CONN", &(MV2_HYBRID_MAX_RC_CONN));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_HYBRID_MAX_RC_CONN");
    rc = MPL_env2int("MV2_HYBRID_MAX_RC_CONN", &(MV2_HYBRID_MAX_RC_CONN));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_HYBRID_MAX_RC_CONN");

    defaultval.d = 100;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_UD_NUM_MSG_LIMIT, /* name */
        &MV2_UD_NUM_MSG_LIMIT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_UD_NUM_MSG_LIMIT = defaultval.d;
    rc = MPL_env2int("UCR_UD_NUM_MSG_LIMIT", &(MV2_UD_NUM_MSG_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_UD_NUM_MSG_LIMIT");
    rc = MPL_env2int("MV2_UD_NUM_MSG_LIMIT", &(MV2_UD_NUM_MSG_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_UD_NUM_MSG_LIMIT");

    defaultval.d = 400;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_UD_SENDWINDOW_SIZE, /* name */
        &MV2_UD_SENDWINDOW_SIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_UD_SENDWINDOW_SIZE = defaultval.d;
    rc = MPL_env2int("UCR_UD_SENDWINDOW_SIZE", &(MV2_UD_SENDWINDOW_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_UD_SENDWINDOW_SIZE");
    rc = MPL_env2int("MV2_UD_SENDWINDOW_SIZE", &(MV2_UD_SENDWINDOW_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_UD_SENDWINDOW_SIZE");

    defaultval.d = 2501;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_UD_RECVWINDOW_SIZE, /* name */
        &MV2_UD_RECVWINDOW_SIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_UD_RECVWINDOW_SIZE = defaultval.d;
    rc = MPL_env2int("UCR_UD_RECVWINDOW_SIZE", &(MV2_UD_RECVWINDOW_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_UD_RECVWINDOW_SIZE");
    rc = MPL_env2int("MV2_UD_RECVWINDOW_SIZE", &(MV2_UD_RECVWINDOW_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_UD_RECVWINDOW_SIZE");

    defaultval.d = 500000;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_UD_RETRY_TIMEOUT, /* name */
        &MV2_UD_RETRY_TIMEOUT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Time (usec) after which an unacknowledged message will be retried.");
    MV2_UD_RETRY_TIMEOUT = defaultval.d;
    rc = MPL_env2int("UCR_UD_RETRY_TIMEOUT", &(MV2_UD_RETRY_TIMEOUT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_UD_RETRY_TIMEOUT");
    rc = MPL_env2int("MV2_UD_RETRY_TIMEOUT", &(MV2_UD_RETRY_TIMEOUT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_UD_RETRY_TIMEOUT");

    defaultval.d = 20000000;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_UD_MAX_RETRY_TIMEOUT, /* name */
        &MV2_UD_MAX_RETRY_TIMEOUT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_UD_MAX_RETRY_TIMEOUT = defaultval.d;
    rc = MPL_env2int("UCR_UD_MAX_RETRY_TIMEOUT", &(MV2_UD_MAX_RETRY_TIMEOUT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_UD_MAX_RETRY_TIMEOUT");
    rc = MPL_env2int("MV2_UD_MAX_RETRY_TIMEOUT", &(MV2_UD_MAX_RETRY_TIMEOUT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_UD_MAX_RETRY_TIMEOUT");

    defaultval.d = 1200;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_UD_PROGRESS_SPIN, /* name */
        &MV2_UD_PROGRESS_SPIN, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_UD_PROGRESS_SPIN = defaultval.d;
    rc = MPL_env2int("UCR_UD_PROGRESS_SPIN", &(MV2_UD_PROGRESS_SPIN));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_UD_PROGRESS_SPIN");
    rc = MPL_env2int("MV2_UD_PROGRESS_SPIN", &(MV2_UD_PROGRESS_SPIN));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_UD_PROGRESS_SPIN");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_UD_RETRY_COUNT, /* name */
        &MV2_UD_RETRY_COUNT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Number of retries of a message before the job is aborted. This is needed in case of HCA fails. The default value is based on  the process count. Setting this to -1 will use the default for the process count. ");
    MV2_UD_RETRY_COUNT = defaultval.d;
    rc = MPL_env2int("UCR_UD_RETRY_COUNT", &(MV2_UD_RETRY_COUNT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_UD_RETRY_COUNT");
    rc = MPL_env2int("MV2_UD_RETRY_COUNT", &(MV2_UD_RETRY_COUNT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_UD_RETRY_COUNT");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_UD_PROGRESS_TIMEOUT, /* name */
        &MV2_UD_PROGRESS_TIMEOUT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Time (usec) until ACK status is checked (and ACKs are sent if needed). To avoid unnecessary retries, set this value less than MV2_UD_RETRY_TIMEOUT. It is recommended to set this to 1/10 of MV2_UD_RETRY_TIMEOUT. The default value is based on  the process count. Setting this to -1 will use the default for the process count. ");
    MV2_UD_PROGRESS_TIMEOUT = defaultval.d;
    rc = MPL_env2int("UCR_UD_PROGRESS_TIMEOUT", &(MV2_UD_PROGRESS_TIMEOUT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_UD_PROGRESS_TIMEOUT");
    rc = MPL_env2int("MV2_UD_PROGRESS_TIMEOUT", &(MV2_UD_PROGRESS_TIMEOUT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_UD_PROGRESS_TIMEOUT");

    defaultval.d = 256;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_UD_MAX_SEND_WQE, /* name */
        &MV2_UD_MAX_SEND_WQE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_UD_MAX_SEND_WQE = defaultval.d;
    rc = MPL_env2int("UCR_UD_MAX_SEND_WQE", &(MV2_UD_MAX_SEND_WQE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_UD_MAX_SEND_WQE");
    rc = MPL_env2int("MV2_UD_MAX_SEND_WQE", &(MV2_UD_MAX_SEND_WQE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_UD_MAX_SEND_WQE");

    defaultval.d = 4096;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_UD_MAX_RECV_WQE, /* name */
        &MV2_UD_MAX_RECV_WQE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_UD_MAX_RECV_WQE = defaultval.d;
    rc = MPL_env2int("UCR_UD_MAX_RECV_WQE", &(MV2_UD_MAX_RECV_WQE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_UD_MAX_RECV_WQE");
    rc = MPL_env2int("MV2_UD_MAX_RECV_WQE", &(MV2_UD_MAX_RECV_WQE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_UD_MAX_RECV_WQE");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_UD_SRQ, /* name */
        &MV2_USE_UD_SRQ, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_USE_UD_SRQ = defaultval.d;
    rc = MPL_env2int("UCR_USE_UD_SRQ", &(MV2_USE_UD_SRQ));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_UD_SRQ");
    rc = MPL_env2int("MV2_USE_UD_SRQ", &(MV2_USE_UD_SRQ));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_UD_SRQ");

    defaultval.d = 8192;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_UD_VBUF_POOL_SIZE, /* name */
        &MV2_UD_VBUF_POOL_SIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_UD_VBUF_POOL_SIZE = defaultval.d;
    rc = MPL_env2int("UCR_UD_VBUF_POOL_SIZE", &(MV2_UD_VBUF_POOL_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_UD_VBUF_POOL_SIZE");
    rc = MPL_env2int("MV2_UD_VBUF_POOL_SIZE", &(MV2_UD_VBUF_POOL_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_UD_VBUF_POOL_SIZE");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_UD_MAX_ACK_PENDING, /* name */
        &MV2_UD_MAX_ACK_PENDING, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Maximum number of outstanding UD buffers waiting for ACK. Setting this value to -1 will use the default value of MV2_UD_SENDWINDOW_SIZE / 4.");
    MV2_UD_MAX_ACK_PENDING = defaultval.d;
    rc = MPL_env2int("UCR_UD_MAX_ACK_PENDING", &(MV2_UD_MAX_ACK_PENDING));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_UD_MAX_ACK_PENDING");
    rc = MPL_env2int("MV2_UD_MAX_ACK_PENDING", &(MV2_UD_MAX_ACK_PENDING));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_UD_MAX_ACK_PENDING");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SHMEM_BACKED_UD_CM, /* name */
        &MV2_SHMEM_BACKED_UD_CM, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC - Not used currently.");
    MV2_SHMEM_BACKED_UD_CM = defaultval.d;
    rc = MPL_env2int("UCR_SHMEM_BACKED_UD_CM", &(MV2_SHMEM_BACKED_UD_CM));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SHMEM_BACKED_UD_CM");
    rc = MPL_env2int("MV2_SHMEM_BACKED_UD_CM", &(MV2_SHMEM_BACKED_UD_CM));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SHMEM_BACKED_UD_CM");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_UD_ZCOPY, /* name */
        &MV2_USE_UD_ZCOPY, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Whether or not to use the zero-copy transfer mechanism to transfer large messages on UD transport.");
    MV2_USE_UD_ZCOPY = defaultval.d;
    rc = MPL_env2int("UCR_USE_UD_ZCOPY", &(MV2_USE_UD_ZCOPY));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_UD_ZCOPY");
    rc = MPL_env2int("MV2_USE_UD_ZCOPY", &(MV2_USE_UD_ZCOPY));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_UD_ZCOPY");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_UD_ZCOPY_THRESHOLD, /* name */
        &MV2_UD_ZCOPY_THRESHOLD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Defines the threshold for transitioning to UD ZCOPY algorithm  from R3 protocol for rndv messages. Defaults to MV2_IBA_EAGER_THRESHOLD. Setting this value to -1 will use the eager threshold (MV2_IBA_EAGER_THRESHOLD) as the default value causing all rndv messages to use UD_ZCOPY.");
    MV2_UD_ZCOPY_THRESHOLD = defaultval.d;
    rc = MPL_env2int("UCR_UD_ZCOPY_THRESHOLD", &(MV2_UD_ZCOPY_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_UD_ZCOPY_THRESHOLD");
    rc = MPL_env2int("MV2_UD_ZCOPY_THRESHOLD", &(MV2_UD_ZCOPY_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_UD_ZCOPY_THRESHOLD");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_UD_NUM_ZCOPY_RNDV_QPS, /* name */
        &MV2_UD_NUM_ZCOPY_RNDV_QPS, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Number of UD QPs to create for ZCOPY transfers. Setting this to -1 will use the default value of 64 * <number_of_hcas>.");
    MV2_UD_NUM_ZCOPY_RNDV_QPS = defaultval.d;
    rc = MPL_env2int("UCR_UD_NUM_ZCOPY_RNDV_QPS", &(MV2_UD_NUM_ZCOPY_RNDV_QPS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_UD_NUM_ZCOPY_RNDV_QPS");
    rc = MPL_env2int("MV2_UD_NUM_ZCOPY_RNDV_QPS", &(MV2_UD_NUM_ZCOPY_RNDV_QPS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_UD_NUM_ZCOPY_RNDV_QPS");

    defaultval.d = 4096;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_UD_ZCOPY_RQ_SIZE, /* name */
        &MV2_UD_ZCOPY_RQ_SIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_UD_ZCOPY_RQ_SIZE = defaultval.d;
    rc = MPL_env2int("UCR_UD_ZCOPY_RQ_SIZE", &(MV2_UD_ZCOPY_RQ_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_UD_ZCOPY_RQ_SIZE");
    rc = MPL_env2int("MV2_UD_ZCOPY_RQ_SIZE", &(MV2_UD_ZCOPY_RQ_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_UD_ZCOPY_RQ_SIZE");

    defaultval.d = 50000;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_UD_ZCOPY_NUM_RETRY, /* name */
        &MV2_UD_ZCOPY_NUM_RETRY, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_UD_ZCOPY_NUM_RETRY = defaultval.d;
    rc = MPL_env2int("UCR_UD_ZCOPY_NUM_RETRY", &(MV2_UD_ZCOPY_NUM_RETRY));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_UD_ZCOPY_NUM_RETRY");
    rc = MPL_env2int("MV2_UD_ZCOPY_NUM_RETRY", &(MV2_UD_ZCOPY_NUM_RETRY));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_UD_ZCOPY_NUM_RETRY");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_UD_ZCOPY_ENABLE_POLLING, /* name */
        &MV2_UD_ZCOPY_ENABLE_POLLING, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_UD_ZCOPY_ENABLE_POLLING = defaultval.d;
    rc = MPL_env2int("UCR_UD_ZCOPY_ENABLE_POLLING", &(MV2_UD_ZCOPY_ENABLE_POLLING));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_UD_ZCOPY_ENABLE_POLLING");
    rc = MPL_env2int("MV2_UD_ZCOPY_ENABLE_POLLING", &(MV2_UD_ZCOPY_ENABLE_POLLING));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_UD_ZCOPY_ENABLE_POLLING");

    defaultval.d = 32;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_UD_ZCOPY_PUSH_SEGMENT, /* name */
        &MV2_UD_ZCOPY_PUSH_SEGMENT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_UD_ZCOPY_PUSH_SEGMENT = defaultval.d;
    rc = MPL_env2int("UCR_UD_ZCOPY_PUSH_SEGMENT", &(MV2_UD_ZCOPY_PUSH_SEGMENT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_UD_ZCOPY_PUSH_SEGMENT");
    rc = MPL_env2int("MV2_UD_ZCOPY_PUSH_SEGMENT", &(MV2_UD_ZCOPY_PUSH_SEGMENT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_UD_ZCOPY_PUSH_SEGMENT");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_UD_DROP_PACKET_RATE, /* name */
        &MV2_UD_DROP_PACKET_RATE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_UD_DROP_PACKET_RATE = defaultval.d;
    rc = MPL_env2int("UCR_UD_DROP_PACKET_RATE", &(MV2_UD_DROP_PACKET_RATE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_UD_DROP_PACKET_RATE");
    rc = MPL_env2int("MV2_UD_DROP_PACKET_RATE", &(MV2_UD_DROP_PACKET_RATE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_UD_DROP_PACKET_RATE");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_MCAST_ENABLE_REL, /* name */
        &MV2_MCAST_ENABLE_REL, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_MCAST_ENABLE_REL = defaultval.d;
    rc = MPL_env2int("UCR_MCAST_ENABLE_REL", &(MV2_MCAST_ENABLE_REL));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_MCAST_ENABLE_REL");
    rc = MPL_env2int("MV2_MCAST_ENABLE_REL", &(MV2_MCAST_ENABLE_REL));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_MCAST_ENABLE_REL");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_MCAST_USE_MCAST_NACK, /* name */
        &MV2_MCAST_USE_MCAST_NACK, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_MCAST_USE_MCAST_NACK = defaultval.d;
    rc = MPL_env2int("UCR_MCAST_USE_MCAST_NACK", &(MV2_MCAST_USE_MCAST_NACK));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_MCAST_USE_MCAST_NACK");
    rc = MPL_env2int("MV2_MCAST_USE_MCAST_NACK", &(MV2_MCAST_USE_MCAST_NACK));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_MCAST_USE_MCAST_NACK");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_MCAST_NUM_NODES_THRESHOLD, /* name */
        &MV2_MCAST_NUM_NODES_THRESHOLD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This defines the threshold for enabling multicast support in collective communication. When MV2_USE_MCAST is set to 1 and the number of nodes in the job is greater than or equal to the threshold value, it uses multicast support in collective communication.");
    MV2_MCAST_NUM_NODES_THRESHOLD = defaultval.d;
    rc = MPL_env2int("UCR_MCAST_NUM_NODES_THRESHOLD", &(MV2_MCAST_NUM_NODES_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_MCAST_NUM_NODES_THRESHOLD");
    rc = MPL_env2int("MV2_MCAST_NUM_NODES_THRESHOLD", &(MV2_MCAST_NUM_NODES_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_MCAST_NUM_NODES_THRESHOLD");

    defaultval.d = 2096;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_MCAST_MAX_RECV_WQE, /* name */
        &MV2_MCAST_MAX_RECV_WQE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_MCAST_MAX_RECV_WQE = defaultval.d;
    rc = MPL_env2int("UCR_MCAST_MAX_RECV_WQE", &(MV2_MCAST_MAX_RECV_WQE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_MCAST_MAX_RECV_WQE");
    rc = MPL_env2int("MV2_MCAST_MAX_RECV_WQE", &(MV2_MCAST_MAX_RECV_WQE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_MCAST_MAX_RECV_WQE");

    defaultval.d = 256;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_MCAST_WINDOW_SIZE, /* name */
        &MV2_MCAST_WINDOW_SIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_MCAST_WINDOW_SIZE = defaultval.d;
    rc = MPL_env2int("UCR_MCAST_WINDOW_SIZE", &(MV2_MCAST_WINDOW_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_MCAST_WINDOW_SIZE");
    rc = MPL_env2int("MV2_MCAST_WINDOW_SIZE", &(MV2_MCAST_WINDOW_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_MCAST_WINDOW_SIZE");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_MCAST_DROP_PACKET_RATE, /* name */
        &MV2_MCAST_DROP_PACKET_RATE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_MCAST_DROP_PACKET_RATE = defaultval.d;
    rc = MPL_env2int("UCR_MCAST_DROP_PACKET_RATE", &(MV2_MCAST_DROP_PACKET_RATE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_MCAST_DROP_PACKET_RATE");
    rc = MPL_env2int("MV2_MCAST_DROP_PACKET_RATE", &(MV2_MCAST_DROP_PACKET_RATE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_MCAST_DROP_PACKET_RATE");

    defaultval.d = 500000;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_MCAST_RETRY_TIMEOUT, /* name */
        &MV2_MCAST_RETRY_TIMEOUT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_MCAST_RETRY_TIMEOUT = defaultval.d;
    rc = MPL_env2int("UCR_MCAST_RETRY_TIMEOUT", &(MV2_MCAST_RETRY_TIMEOUT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_MCAST_RETRY_TIMEOUT");
    rc = MPL_env2int("MV2_MCAST_RETRY_TIMEOUT", &(MV2_MCAST_RETRY_TIMEOUT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_MCAST_RETRY_TIMEOUT");

    defaultval.d = 20000000;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_MCAST_MAX_RETRY_TIMEOUT, /* name */
        &MV2_MCAST_MAX_RETRY_TIMEOUT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_MCAST_MAX_RETRY_TIMEOUT = defaultval.d;
    rc = MPL_env2int("UCR_MCAST_MAX_RETRY_TIMEOUT", &(MV2_MCAST_MAX_RETRY_TIMEOUT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_MCAST_MAX_RETRY_TIMEOUT");
    rc = MPL_env2int("MV2_MCAST_MAX_RETRY_TIMEOUT", &(MV2_MCAST_MAX_RETRY_TIMEOUT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_MCAST_MAX_RETRY_TIMEOUT");

    defaultval.d = 1200;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_MCAST_NSPIN_THRESHOLD, /* name */
        &MV2_MCAST_NSPIN_THRESHOLD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_MCAST_NSPIN_THRESHOLD = defaultval.d;
    rc = MPL_env2int("UCR_MCAST_NSPIN_THRESHOLD", &(MV2_MCAST_NSPIN_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_MCAST_NSPIN_THRESHOLD");
    rc = MPL_env2int("MV2_MCAST_NSPIN_THRESHOLD", &(MV2_MCAST_NSPIN_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_MCAST_NSPIN_THRESHOLD");

    defaultval.d = 10000;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_MCAST_COMM_INIT_TIMEOUT, /* name */
        &MV2_MCAST_COMM_INIT_TIMEOUT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_MCAST_COMM_INIT_TIMEOUT = defaultval.d;
    rc = MPL_env2int("UCR_MCAST_COMM_INIT_TIMEOUT", &(MV2_MCAST_COMM_INIT_TIMEOUT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_MCAST_COMM_INIT_TIMEOUT");
    rc = MPL_env2int("MV2_MCAST_COMM_INIT_TIMEOUT", &(MV2_MCAST_COMM_INIT_TIMEOUT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_MCAST_COMM_INIT_TIMEOUT");

    defaultval.d = 128;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_MCAST_COMM_INIT_RETRIES, /* name */
        &MV2_MCAST_COMM_INIT_RETRIES, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_MCAST_COMM_INIT_RETRIES = defaultval.d;
    rc = MPL_env2int("UCR_MCAST_COMM_INIT_RETRIES", &(MV2_MCAST_COMM_INIT_RETRIES));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_MCAST_COMM_INIT_RETRIES");
    rc = MPL_env2int("MV2_MCAST_COMM_INIT_RETRIES", &(MV2_MCAST_COMM_INIT_RETRIES));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_MCAST_COMM_INIT_RETRIES");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_MCAST_SKIP_LOOPBACK, /* name */
        &MV2_MCAST_SKIP_LOOPBACK, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_MCAST_SKIP_LOOPBACK = defaultval.d;
    rc = MPL_env2int("UCR_MCAST_SKIP_LOOPBACK", &(MV2_MCAST_SKIP_LOOPBACK));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_MCAST_SKIP_LOOPBACK");
    rc = MPL_env2int("MV2_MCAST_SKIP_LOOPBACK", &(MV2_MCAST_SKIP_LOOPBACK));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_MCAST_SKIP_LOOPBACK");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_MCAST_BCAST_MIN_MSG, /* name */
        &MV2_MCAST_BCAST_MIN_MSG, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_MCAST_BCAST_MIN_MSG = defaultval.d;
    rc = MPL_env2int("UCR_MCAST_BCAST_MIN_MSG", &(MV2_MCAST_BCAST_MIN_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_MCAST_BCAST_MIN_MSG");
    rc = MPL_env2int("MV2_MCAST_BCAST_MIN_MSG", &(MV2_MCAST_BCAST_MIN_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_MCAST_BCAST_MIN_MSG");

    defaultval.d = 512 * 1042;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_MCAST_BCAST_MAX_MSG, /* name */
        &MV2_MCAST_BCAST_MAX_MSG, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_MCAST_BCAST_MAX_MSG = defaultval.d;
    rc = MPL_env2int("UCR_MCAST_BCAST_MAX_MSG", &(MV2_MCAST_BCAST_MAX_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_MCAST_BCAST_MAX_MSG");
    rc = MPL_env2int("MV2_MCAST_BCAST_MAX_MSG", &(MV2_MCAST_BCAST_MAX_MSG));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_MCAST_BCAST_MAX_MSG");

    defaultval.d = 128;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_DEFAULT_MAX_RECV_WQE, /* name */
        &MV2_DEFAULT_MAX_RECV_WQE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This specifies the maximum number of receive WQEs on each QP (maximum number of receives that can be posted on a single QP).");
    MV2_DEFAULT_MAX_RECV_WQE = defaultval.d;
    rc = MPL_env2int("UCR_DEFAULT_MAX_RECV_WQE", &(MV2_DEFAULT_MAX_RECV_WQE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_DEFAULT_MAX_RECV_WQE");
    rc = MPL_env2int("MV2_DEFAULT_MAX_RECV_WQE", &(MV2_DEFAULT_MAX_RECV_WQE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_DEFAULT_MAX_RECV_WQE");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_NDREG_ENTRIES_MAX, /* name */
        &MV2_NDREG_ENTRIES_MAX, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_NDREG_ENTRIES_MAX = defaultval.d;
    rc = MPL_env2int("UCR_NDREG_ENTRIES_MAX", &(MV2_NDREG_ENTRIES_MAX));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_NDREG_ENTRIES_MAX");
    rc = MPL_env2int("MV2_NDREG_ENTRIES_MAX", &(MV2_NDREG_ENTRIES_MAX));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_NDREG_ENTRIES_MAX");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_NDREG_ENTRIES, /* name */
        &MV2_NDREG_ENTRIES, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This defines the total number of buffers that can be stored in the registration cache. It has no effect if MV2_USE_LAZY_MEM_UNREGISTER is not set. A larger value will lead to less frequent lazy de-registration.");
    MV2_NDREG_ENTRIES = defaultval.d;
    rc = MPL_env2int("UCR_NDREG_ENTRIES", &(MV2_NDREG_ENTRIES));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_NDREG_ENTRIES");
    rc = MPL_env2int("MV2_NDREG_ENTRIES", &(MV2_NDREG_ENTRIES));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_NDREG_ENTRIES");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_DREG_CACHE_LIMIT, /* name */
        &MV2_DREG_CACHE_LIMIT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_DREG_CACHE_LIMIT = defaultval.d;
    rc = MPL_env2int("UCR_DREG_CACHE_LIMIT", &(MV2_DREG_CACHE_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_DREG_CACHE_LIMIT");
    rc = MPL_env2int("MV2_DREG_CACHE_LIMIT", &(MV2_DREG_CACHE_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_DREG_CACHE_LIMIT");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_HWLOC_CPU_BINDING, /* name */
        &MV2_USE_HWLOC_CPU_BINDING, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_USE_HWLOC_CPU_BINDING = defaultval.d;
    rc = MPL_env2int("UCR_USE_HWLOC_CPU_BINDING", &(MV2_USE_HWLOC_CPU_BINDING));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_HWLOC_CPU_BINDING");
    rc = MPL_env2int("MV2_USE_HWLOC_CPU_BINDING", &(MV2_USE_HWLOC_CPU_BINDING));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_HWLOC_CPU_BINDING");

    defaultval.d = 5;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_THREAD_YIELD_SPIN_THRESHOLD, /* name */
        &MV2_THREAD_YIELD_SPIN_THRESHOLD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_THREAD_YIELD_SPIN_THRESHOLD = defaultval.d;
    rc = MPL_env2int("UCR_THREAD_YIELD_SPIN_THRESHOLD", &(MV2_THREAD_YIELD_SPIN_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_THREAD_YIELD_SPIN_THRESHOLD");
    rc = MPL_env2int("MV2_THREAD_YIELD_SPIN_THRESHOLD", &(MV2_THREAD_YIELD_SPIN_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_THREAD_YIELD_SPIN_THRESHOLD");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_THREAD_YIELD, /* name */
        &MV2_USE_THREAD_YIELD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_USE_THREAD_YIELD = defaultval.d;
    rc = MPL_env2int("UCR_USE_THREAD_YIELD", &(MV2_USE_THREAD_YIELD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_THREAD_YIELD");
    rc = MPL_env2int("MV2_USE_THREAD_YIELD", &(MV2_USE_THREAD_YIELD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_THREAD_YIELD");

    defaultval.d = 2000;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_NUM_SPINS_BEFORE_LOCK, /* name */
        &MV2_NUM_SPINS_BEFORE_LOCK, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_NUM_SPINS_BEFORE_LOCK = defaultval.d;
    rc = MPL_env2int("UCR_NUM_SPINS_BEFORE_LOCK", &(MV2_NUM_SPINS_BEFORE_LOCK));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_NUM_SPINS_BEFORE_LOCK");
    rc = MPL_env2int("MV2_NUM_SPINS_BEFORE_LOCK", &(MV2_NUM_SPINS_BEFORE_LOCK));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_NUM_SPINS_BEFORE_LOCK");

    defaultval.d = (1 << 20);
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_ASYNC_THREAD_STACK_SIZE, /* name */
        &MV2_ASYNC_THREAD_STACK_SIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_ASYNC_THREAD_STACK_SIZE = defaultval.d;
    rc = MPL_env2int("UCR_ASYNC_THREAD_STACK_SIZE", &(MV2_ASYNC_THREAD_STACK_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_ASYNC_THREAD_STACK_SIZE");
    rc = MPL_env2int("MV2_ASYNC_THREAD_STACK_SIZE", &(MV2_ASYNC_THREAD_STACK_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_ASYNC_THREAD_STACK_SIZE");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_HUGEPAGES, /* name */
        &MV2_USE_HUGEPAGES, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Set this to 0, to not use any HugePages.");
    MV2_USE_HUGEPAGES = defaultval.d;
    rc = MPL_env2int("UCR_USE_HUGEPAGES", &(MV2_USE_HUGEPAGES));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_HUGEPAGES");
    rc = MPL_env2int("MV2_USE_HUGEPAGES", &(MV2_USE_HUGEPAGES));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_HUGEPAGES");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_MEMORY_OPTIMIZATION, /* name */
        &MV2_MEMORY_OPTIMIZATION, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_MEMORY_OPTIMIZATION = defaultval.d;
    rc = MPL_env2int("UCR_MEMORY_OPTIMIZATION", &(MV2_MEMORY_OPTIMIZATION));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_MEMORY_OPTIMIZATION");
    rc = MPL_env2int("MV2_MEMORY_OPTIMIZATION", &(MV2_MEMORY_OPTIMIZATION));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_MEMORY_OPTIMIZATION");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SRQ_MAX_SIZE, /* name */
        &MV2_SRQ_MAX_SIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This is the maximum number of work requests allowed on the Shared Receive Queue. Upon receiving a SRQ limit event, the current value of MV2_SRQ_SIZE will be doubled or moved to the maximum of MV2_SRQ_MAX_SIZE, whichever is smaller. When using RDMA_CM, we cannot support very large SRQ. So, unless user set it, reduce the max_srq_size to 4K.");
    MV2_SRQ_MAX_SIZE = defaultval.d;
    rc = MPL_env2int("UCR_SRQ_MAX_SIZE", &(MV2_SRQ_MAX_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SRQ_MAX_SIZE");
    rc = MPL_env2int("MV2_SRQ_MAX_SIZE", &(MV2_SRQ_MAX_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SRQ_MAX_SIZE");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SRQ_SIZE, /* name */
        &MV2_SRQ_SIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This is the initial number of work requests posted to the Shared Receive Queue.");
    MV2_SRQ_SIZE = defaultval.d;
    rc = MPL_env2int("UCR_SRQ_SIZE", &(MV2_SRQ_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SRQ_SIZE");
    rc = MPL_env2int("MV2_SRQ_SIZE", &(MV2_SRQ_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SRQ_SIZE");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SRQ_LIMIT, /* name */
        &MV2_SRQ_LIMIT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This is the low water-mark limit for the Shared Receive Queue. If the number of available work entries on the SRQ drops below this limit, the flow control will be activated.");
    MV2_SRQ_LIMIT = defaultval.d;
    rc = MPL_env2int("UCR_SRQ_LIMIT", &(MV2_SRQ_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SRQ_LIMIT");
    rc = MPL_env2int("MV2_SRQ_LIMIT", &(MV2_SRQ_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SRQ_LIMIT");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_UD_SRQ_MAX_SIZE, /* name */
        &MV2_UD_SRQ_MAX_SIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_UD_SRQ_MAX_SIZE = defaultval.d;
    rc = MPL_env2int("UCR_UD_SRQ_MAX_SIZE", &(MV2_UD_SRQ_MAX_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_UD_SRQ_MAX_SIZE");
    rc = MPL_env2int("MV2_UD_SRQ_MAX_SIZE", &(MV2_UD_SRQ_MAX_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_UD_SRQ_MAX_SIZE");

    defaultval.d = 4096;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_UD_SRQ_SIZE, /* name */
        &MV2_UD_SRQ_SIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_UD_SRQ_SIZE = defaultval.d;
    rc = MPL_env2int("UCR_UD_SRQ_SIZE", &(MV2_UD_SRQ_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_UD_SRQ_SIZE");
    rc = MPL_env2int("MV2_UD_SRQ_SIZE", &(MV2_UD_SRQ_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_UD_SRQ_SIZE");

    defaultval.d = 128;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_UD_SRQ_LIMIT, /* name */
        &MV2_UD_SRQ_LIMIT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_UD_SRQ_LIMIT = defaultval.d;
    rc = MPL_env2int("UCR_UD_SRQ_LIMIT", &(MV2_UD_SRQ_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_UD_SRQ_LIMIT");
    rc = MPL_env2int("MV2_UD_SRQ_LIMIT", &(MV2_UD_SRQ_LIMIT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_UD_SRQ_LIMIT");

    defaultval.d = (INT_MAX);
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_MAX_NUM_UD_VBUFS, /* name */
        &MV2_MAX_NUM_UD_VBUFS, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_MAX_NUM_UD_VBUFS = defaultval.d;
    rc = MPL_env2int("UCR_MAX_NUM_UD_VBUFS", &(MV2_MAX_NUM_UD_VBUFS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_MAX_NUM_UD_VBUFS");
    rc = MPL_env2int("MV2_MAX_NUM_UD_VBUFS", &(MV2_MAX_NUM_UD_VBUFS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_MAX_NUM_UD_VBUFS");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_MAX_INLINE_SIZE, /* name */
        &MV2_MAX_INLINE_SIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This defines the maximum inline size for data transfer. Please note that the default value of this parameter will be 0 when the number of processes is larger than 256 to improve memory usage scalability.");
    MV2_MAX_INLINE_SIZE = defaultval.d;
    rc = MPL_env2int("UCR_MAX_INLINE_SIZE", &(MV2_MAX_INLINE_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_MAX_INLINE_SIZE");
    rc = MPL_env2int("MV2_MAX_INLINE_SIZE", &(MV2_MAX_INLINE_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_MAX_INLINE_SIZE");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_VBUF_TOTAL_SIZE, /* name */
        &MV2_VBUF_TOTAL_SIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "The size of each vbuf, the basic communication buffer of MVAPICH2. For better performance, the value of MV2_IBA_EAGER_THRESHOLD should be set the same as MV2_VBUF_TOTAL_SIZE.");
    MV2_VBUF_TOTAL_SIZE = defaultval.d;
    rc = MPL_env2int("UCR_VBUF_TOTAL_SIZE", &(MV2_VBUF_TOTAL_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_VBUF_TOTAL_SIZE");
    rc = MPL_env2int("MV2_VBUF_TOTAL_SIZE", &(MV2_VBUF_TOTAL_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_VBUF_TOTAL_SIZE");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_VBUF_MAX, /* name */
        &MV2_VBUF_MAX, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Max (total) number of vbufs to allocate, after which process terminates with a fatal error. -1 means no limit.");
    MV2_VBUF_MAX = defaultval.d;
    rc = MPL_env2int("UCR_VBUF_MAX", &(MV2_VBUF_MAX));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_VBUF_MAX");
    rc = MPL_env2int("MV2_VBUF_MAX", &(MV2_VBUF_MAX));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_VBUF_MAX");

    defaultval.d = 10;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_INITIAL_PREPOST_DEPTH, /* name */
        &MV2_INITIAL_PREPOST_DEPTH, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This defines the initial number of pre-posted receive buffers for each connection. If communication happen for a particular connection, the number of buffers will be increased to RDMA_PREPOST_DEPTH.");
    MV2_INITIAL_PREPOST_DEPTH = defaultval.d;
    rc = MPL_env2int("UCR_INITIAL_PREPOST_DEPTH", &(MV2_INITIAL_PREPOST_DEPTH));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_INITIAL_PREPOST_DEPTH");
    rc = MPL_env2int("MV2_INITIAL_PREPOST_DEPTH", &(MV2_INITIAL_PREPOST_DEPTH));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_INITIAL_PREPOST_DEPTH");

    defaultval.d = 64;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_PREPOST_DEPTH, /* name */
        &MV2_PREPOST_DEPTH, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This defines the number of buffers pre-posted for each connection to handle send/receive operations.");
    MV2_PREPOST_DEPTH = defaultval.d;
    rc = MPL_env2int("UCR_PREPOST_DEPTH", &(MV2_PREPOST_DEPTH));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_PREPOST_DEPTH");
    rc = MPL_env2int("MV2_PREPOST_DEPTH", &(MV2_PREPOST_DEPTH));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_PREPOST_DEPTH");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_VBUF_POOL_SIZE, /* name */
        &MV2_VBUF_POOL_SIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "The number of vbufs in the initial pool. This pool is shared among all the connections.");
    MV2_VBUF_POOL_SIZE = defaultval.d;
    rc = MPL_env2int("UCR_VBUF_POOL_SIZE", &(MV2_VBUF_POOL_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_VBUF_POOL_SIZE");
    rc = MPL_env2int("MV2_VBUF_POOL_SIZE", &(MV2_VBUF_POOL_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_VBUF_POOL_SIZE");

    defaultval.d = 8192;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_MAX_NUM_VBUFS, /* name */
        &MV2_MAX_NUM_VBUFS, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_MAX_NUM_VBUFS = defaultval.d;
    rc = MPL_env2int("UCR_MAX_NUM_VBUFS", &(MV2_MAX_NUM_VBUFS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_MAX_NUM_VBUFS");
    rc = MPL_env2int("MV2_MAX_NUM_VBUFS", &(MV2_MAX_NUM_VBUFS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_MAX_NUM_VBUFS");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_VBUF_SECONDARY_POOL_SIZE, /* name */
        &MV2_VBUF_SECONDARY_POOL_SIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "The number of vbufs allocated each time when the global pool is running out in the initial pool. This is also shared among all the connections.");
    MV2_VBUF_SECONDARY_POOL_SIZE = defaultval.d;
    rc = MPL_env2int("UCR_VBUF_SECONDARY_POOL_SIZE", &(MV2_VBUF_SECONDARY_POOL_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_VBUF_SECONDARY_POOL_SIZE");
    rc = MPL_env2int("MV2_VBUF_SECONDARY_POOL_SIZE", &(MV2_VBUF_SECONDARY_POOL_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_VBUF_SECONDARY_POOL_SIZE");

    defaultval.d = (256 * 1024);
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_BLOCK_SIZE, /* name */
        &MV2_CUDA_BLOCK_SIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "The chunk size used in large message transfer from device memory to host memory. The other suggested values for this parameter are 131072 and 524288.");
    MV2_CUDA_BLOCK_SIZE = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_BLOCK_SIZE", &(MV2_CUDA_BLOCK_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_BLOCK_SIZE");
    rc = MPL_env2int("MV2_CUDA_BLOCK_SIZE", &(MV2_CUDA_BLOCK_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_BLOCK_SIZE");

    defaultval.d = 8;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CUDA_NUM_RNDV_BLOCKS, /* name */
        &MV2_CUDA_NUM_RNDV_BLOCKS, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CUDA_NUM_RNDV_BLOCKS = defaultval.d;
    rc = MPL_env2int("UCR_CUDA_NUM_RNDV_BLOCKS", &(MV2_CUDA_NUM_RNDV_BLOCKS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CUDA_NUM_RNDV_BLOCKS");
    rc = MPL_env2int("MV2_CUDA_NUM_RNDV_BLOCKS", &(MV2_CUDA_NUM_RNDV_BLOCKS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CUDA_NUM_RNDV_BLOCKS");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_MPIRUN_RSH_LAUNCH, /* name */
        &MV2_MPIRUN_RSH_LAUNCH, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_MPIRUN_RSH_LAUNCH = defaultval.d;
    rc = MPL_env2int("UCR_MPIRUN_RSH_LAUNCH", &(MV2_MPIRUN_RSH_LAUNCH));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_MPIRUN_RSH_LAUNCH");
    rc = MPL_env2int("MV2_MPIRUN_RSH_LAUNCH", &(MV2_MPIRUN_RSH_LAUNCH));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_MPIRUN_RSH_LAUNCH");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_ROCE, /* name */
        &MV2_USE_ROCE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This parameter enables the use of RDMA over Ethernet for MPI communication. The underlying HCA and network must support this feature.");
    MV2_USE_ROCE = defaultval.d;
    rc = MPL_env2int("UCR_USE_RoCE", &(MV2_USE_ROCE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_RoCE");
    rc = MPL_env2int("MV2_USE_RoCE", &(MV2_USE_ROCE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_RoCE");
    rc = MPL_env2int("UCR_USE_ROCE", &(MV2_USE_ROCE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_ROCE");
    rc = MPL_env2int("MV2_USE_ROCE", &(MV2_USE_ROCE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_ROCE");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_ROCE_MODE, /* name */
        &MV2_USE_ROCE_MODE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_USE_ROCE_MODE = defaultval.d;
    rc = MPL_env2int("UCR_USE_RoCE_MODE", &(MV2_USE_ROCE_MODE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_RoCE_MODE");
    rc = MPL_env2int("MV2_USE_RoCE_MODE", &(MV2_USE_ROCE_MODE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_RoCE_MODE");
    rc = MPL_env2int("UCR_USE_ROCE_MODE", &(MV2_USE_ROCE_MODE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_ROCE_MODE");
    rc = MPL_env2int("MV2_USE_ROCE_MODE", &(MV2_USE_ROCE_MODE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_ROCE_MODE");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_RING_STARTUP, /* name */
        &MV2_USE_RING_STARTUP, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Setting this parameter enables MVAPICH2 to use ring based start up.");
    MV2_USE_RING_STARTUP = defaultval.d;
    rc = MPL_env2int("UCR_USE_RING_STARTUP", &(MV2_USE_RING_STARTUP));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_RING_STARTUP");
    rc = MPL_env2int("MV2_USE_RING_STARTUP", &(MV2_USE_RING_STARTUP));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_RING_STARTUP");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_ON_DEMAND_UD_INFO_EXCHANGE, /* name */
        &MV2_ON_DEMAND_UD_INFO_EXCHANGE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Setting MV2_ON_DEMAND_UD_INFO_EXCHANGE to 1 will enable on-demand Address Handle creation for hybrid mode.");
    MV2_ON_DEMAND_UD_INFO_EXCHANGE = defaultval.d;
    rc = MPL_env2int("UCR_ON_DEMAND_UD_INFO_EXCHANGE", &(MV2_ON_DEMAND_UD_INFO_EXCHANGE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_ON_DEMAND_UD_INFO_EXCHANGE");
    rc = MPL_env2int("MV2_ON_DEMAND_UD_INFO_EXCHANGE", &(MV2_ON_DEMAND_UD_INFO_EXCHANGE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_ON_DEMAND_UD_INFO_EXCHANGE");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_PMI_IBARRIER, /* name */
        &MV2_USE_PMI_IBARRIER, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_USE_PMI_IBARRIER = defaultval.d;
    rc = MPL_env2int("UCR_USE_PMI_IBARRIER", &(MV2_USE_PMI_IBARRIER));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_PMI_IBARRIER");
    rc = MPL_env2int("MV2_USE_PMI_IBARRIER", &(MV2_USE_PMI_IBARRIER));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_PMI_IBARRIER");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_PMI_IALLGATHER, /* name */
        &MV2_USE_PMI_IALLGATHER, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_USE_PMI_IALLGATHER = defaultval.d;
    rc = MPL_env2int("UCR_USE_PMI_IALLGATHER", &(MV2_USE_PMI_IALLGATHER));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_PMI_IALLGATHER");
    rc = MPL_env2int("MV2_USE_PMI_IALLGATHER", &(MV2_USE_PMI_IALLGATHER));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_PMI_IALLGATHER");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_NUM_HCAS, /* name */
        &MV2_NUM_HCAS, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This parameter indicates number of InfiniBand adapters to be used for communication on an end node. Value is potentially computed.");
    MV2_NUM_HCAS = defaultval.d;
    rc = MPL_env2int("UCR_NUM_HCAS", &(MV2_NUM_HCAS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_NUM_HCAS");
    rc = MPL_env2int("MV2_NUM_HCAS", &(MV2_NUM_HCAS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_NUM_HCAS");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_HOMOGENEOUS_CLUSTER, /* name */
        &MV2_HOMOGENEOUS_CLUSTER, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Set to 1 if using a homogeneous cluster.");
    MV2_HOMOGENEOUS_CLUSTER = defaultval.d;
    rc = MPL_env2int("UCR_HOMOGENEOUS_CLUSTER", &(MV2_HOMOGENEOUS_CLUSTER));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_HOMOGENEOUS_CLUSTER");
    rc = MPL_env2int("MV2_HOMOGENEOUS_CLUSTER", &(MV2_HOMOGENEOUS_CLUSTER));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_HOMOGENEOUS_CLUSTER");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_BLOCKING, /* name */
        &MV2_USE_BLOCKING, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Setting this parameter enables mvapich2 to use blocking mode progress. MPI applications do not take up any CPU when they are waiting for incoming messages.");
    MV2_USE_BLOCKING = defaultval.d;
    rc = MPL_env2bool("UCR_USE_BLOCKING", &(MV2_USE_BLOCKING));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_BLOCKING");
    rc = MPL_env2bool("MV2_USE_BLOCKING", &(MV2_USE_BLOCKING));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_BLOCKING");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_SHARED_MEM, /* name */
        &MV2_USE_SHARED_MEM, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Use shared memory for intra-node communication.");
    MV2_USE_SHARED_MEM = defaultval.d;
    rc = MPL_env2bool("UCR_USE_SHARED_MEM", &(MV2_USE_SHARED_MEM));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_SHARED_MEM");
    rc = MPL_env2bool("MV2_USE_SHARED_MEM", &(MV2_USE_SHARED_MEM));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_SHARED_MEM");

    defaultval.str = (const char *) NULL;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_CHAR,
        MV2_LIBIBVERBS_PATH, /* name */
        &MV2_LIBIBVERBS_PATH, /* address */
        MV2_MAX_STRLEN, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    tmp_str = defaultval.str;
    rc = MPL_env2str("UCR_LIBIBVERBS_PATH", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_LIBIBVERBS_PATH");
    rc = MPL_env2str("MV2_LIBIBVERBS_PATH", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_LIBIBVERBS_PATH");
    if (tmp_str != NULL) {
        MV2_LIBIBVERBS_PATH = MPL_strdup(tmp_str);
        MV2_assert(MV2_LIBIBVERBS_PATH);
        if (MV2_LIBIBVERBS_PATH == NULL) {
            MPIR_CHKMEM_SETERR(mpi_errno, strlen(tmp_str), "dup of string for MV2_LIBIBVERBS_PATH");
            goto fn_fail;
        }
    }
    else {
        MV2_LIBIBVERBS_PATH = NULL;
    }

    defaultval.str = (const char *) NULL;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_CHAR,
        MV2_LIBIBMAD_PATH, /* name */
        &MV2_LIBIBMAD_PATH, /* address */
        MV2_MAX_STRLEN, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    tmp_str = defaultval.str;
    rc = MPL_env2str("UCR_LIBIBMAD_PATH", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_LIBIBMAD_PATH");
    rc = MPL_env2str("MV2_LIBIBMAD_PATH", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_LIBIBMAD_PATH");
    if (tmp_str != NULL) {
        MV2_LIBIBMAD_PATH = MPL_strdup(tmp_str);
        MV2_assert(MV2_LIBIBMAD_PATH);
        if (MV2_LIBIBMAD_PATH == NULL) {
            MPIR_CHKMEM_SETERR(mpi_errno, strlen(tmp_str), "dup of string for MV2_LIBIBMAD_PATH");
            goto fn_fail;
        }
    }
    else {
        MV2_LIBIBMAD_PATH = NULL;
    }

    defaultval.str = (const char *) NULL;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_CHAR,
        MV2_LIBIBUMAD_PATH, /* name */
        &MV2_LIBIBUMAD_PATH, /* address */
        MV2_MAX_STRLEN, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    tmp_str = defaultval.str;
    rc = MPL_env2str("UCR_LIBIBUMAD_PATH", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_LIBIBUMAD_PATH");
    rc = MPL_env2str("MV2_LIBIBUMAD_PATH", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_LIBIBUMAD_PATH");
    if (tmp_str != NULL) {
        MV2_LIBIBUMAD_PATH = MPL_strdup(tmp_str);
        MV2_assert(MV2_LIBIBUMAD_PATH);
        if (MV2_LIBIBUMAD_PATH == NULL) {
            MPIR_CHKMEM_SETERR(mpi_errno, strlen(tmp_str), "dup of string for MV2_LIBIBUMAD_PATH");
            goto fn_fail;
        }
    }
    else {
        MV2_LIBIBUMAD_PATH = NULL;
    }

    defaultval.str = (const char *) NULL;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_CHAR,
        MV2_LIBRDMACM_PATH, /* name */
        &MV2_LIBRDMACM_PATH, /* address */
        MV2_MAX_STRLEN, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    tmp_str = defaultval.str;
    rc = MPL_env2str("UCR_LIBRDMACM_PATH", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_LIBRDMACM_PATH");
    rc = MPL_env2str("MV2_LIBRDMACM_PATH", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_LIBRDMACM_PATH");
    if (tmp_str != NULL) {
        MV2_LIBRDMACM_PATH = MPL_strdup(tmp_str);
        MV2_assert(MV2_LIBRDMACM_PATH);
        if (MV2_LIBRDMACM_PATH == NULL) {
            MPIR_CHKMEM_SETERR(mpi_errno, strlen(tmp_str), "dup of string for MV2_LIBRDMACM_PATH");
            goto fn_fail;
        }
    }
    else {
        MV2_LIBRDMACM_PATH = NULL;
    }

    defaultval.str = (const char *) NULL;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_CHAR,
        MV2_LIBSHARP_PATH, /* name */
        &MV2_LIBSHARP_PATH, /* address */
        MV2_MAX_STRLEN, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    tmp_str = defaultval.str;
    rc = MPL_env2str("UCR_LIBSHARP_PATH", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_LIBSHARP_PATH");
    rc = MPL_env2str("MV2_LIBSHARP_PATH", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_LIBSHARP_PATH");
    if (tmp_str != NULL) {
        MV2_LIBSHARP_PATH = MPL_strdup(tmp_str);
        MV2_assert(MV2_LIBSHARP_PATH);
        if (MV2_LIBSHARP_PATH == NULL) {
            MPIR_CHKMEM_SETERR(mpi_errno, strlen(tmp_str), "dup of string for MV2_LIBSHARP_PATH");
            goto fn_fail;
        }
    }
    else {
        MV2_LIBSHARP_PATH = NULL;
    }

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_ENABLE_SHARP, /* name */
        &MV2_ENABLE_SHARP, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Set this to 1, to enable hardware SHArP support in collective communication.");
    MV2_ENABLE_SHARP = defaultval.d;
    rc = MPL_env2int("UCR_ENABLE_SHARP", &(MV2_ENABLE_SHARP));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_ENABLE_SHARP");
    rc = MPL_env2int("MV2_ENABLE_SHARP", &(MV2_ENABLE_SHARP));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_ENABLE_SHARP");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_ALLOW_HETEROGENEOUS_HCA_SELECTION, /* name */
        &MV2_ALLOW_HETEROGENEOUS_HCA_SELECTION, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_ALLOW_HETEROGENEOUS_HCA_SELECTION = defaultval.d;
    rc = MPL_env2int("UCR_ALLOW_HETEROGENEOUS_HCA_SELECTION", &(MV2_ALLOW_HETEROGENEOUS_HCA_SELECTION));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_ALLOW_HETEROGENEOUS_HCA_SELECTION");
    rc = MPL_env2int("MV2_ALLOW_HETEROGENEOUS_HCA_SELECTION", &(MV2_ALLOW_HETEROGENEOUS_HCA_SELECTION));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_ALLOW_HETEROGENEOUS_HCA_SELECTION");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_PROCESS_PLACEMENT_AWARE_HCA_MAPPING, /* name */
        &MV2_PROCESS_PLACEMENT_AWARE_HCA_MAPPING, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_PROCESS_PLACEMENT_AWARE_HCA_MAPPING = defaultval.d;
    rc = MPL_env2int("UCR_PROCESS_PLACEMENT_AWARE_HCA_MAPPING", &(MV2_PROCESS_PLACEMENT_AWARE_HCA_MAPPING));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_PROCESS_PLACEMENT_AWARE_HCA_MAPPING");
    rc = MPL_env2int("MV2_PROCESS_PLACEMENT_AWARE_HCA_MAPPING", &(MV2_PROCESS_PLACEMENT_AWARE_HCA_MAPPING));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_PROCESS_PLACEMENT_AWARE_HCA_MAPPING");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_DEFAULT_PORT, /* name */
        &MV2_DEFAULT_PORT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This parameter is to select the specific HCA port on a active multi port InfiniBand adapter. A value of -1 indicates no user selection.");
    MV2_DEFAULT_PORT = defaultval.d;
    rc = MPL_env2int("UCR_DEFAULT_PORT", &(MV2_DEFAULT_PORT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_DEFAULT_PORT");
    rc = MPL_env2int("MV2_DEFAULT_PORT", &(MV2_DEFAULT_PORT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_DEFAULT_PORT");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_DEFAULT_GID_INDEX, /* name */
        &MV2_DEFAULT_GID_INDEX, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "In RoCE mode, this parameter allows to choose non-default GID index in loss-less ethernet setup using VLANs.");
    MV2_DEFAULT_GID_INDEX = defaultval.d;
    rc = MPL_env2int("UCR_DEFAULT_GID_INDEX", &(MV2_DEFAULT_GID_INDEX));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_DEFAULT_GID_INDEX");
    rc = MPL_env2int("MV2_DEFAULT_GID_INDEX", &(MV2_DEFAULT_GID_INDEX));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_DEFAULT_GID_INDEX");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_IOV_DENSITY_MIN, /* name */
        &MV2_IOV_DENSITY_MIN, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_IOV_DENSITY_MIN = defaultval.d;
    rc = MPL_env2int("UCR_IOV_DENSITY_MIN", &(MV2_IOV_DENSITY_MIN));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_IOV_DENSITY_MIN");
    rc = MPL_env2int("MV2_IOV_DENSITY_MIN", &(MV2_IOV_DENSITY_MIN));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_IOV_DENSITY_MIN");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_ENABLE_EAGER_THRESHOLD_REDUCTION, /* name */
        &MV2_ENABLE_EAGER_THRESHOLD_REDUCTION, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_ENABLE_EAGER_THRESHOLD_REDUCTION = defaultval.d;
    rc = MPL_env2int("UCR_ENABLE_EAGER_THRESHOLD_REDUCTION", &(MV2_ENABLE_EAGER_THRESHOLD_REDUCTION));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_ENABLE_EAGER_THRESHOLD_REDUCTION");
    rc = MPL_env2int("MV2_ENABLE_EAGER_THRESHOLD_REDUCTION", &(MV2_ENABLE_EAGER_THRESHOLD_REDUCTION));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_ENABLE_EAGER_THRESHOLD_REDUCTION");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_EAGER_FAST_SEND, /* name */
        &MV2_USE_EAGER_FAST_SEND, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_USE_EAGER_FAST_SEND = defaultval.d;
    rc = MPL_env2int("UCR_USE_EAGER_FAST_SEND", &(MV2_USE_EAGER_FAST_SEND));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_EAGER_FAST_SEND");
    rc = MPL_env2int("MV2_USE_EAGER_FAST_SEND", &(MV2_USE_EAGER_FAST_SEND));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_EAGER_FAST_SEND");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SUPPORT_FORK_SAFETY, /* name */
        &MV2_SUPPORT_FORK_SAFETY, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_SUPPORT_FORK_SAFETY = defaultval.d;
    rc = MPL_env2int("UCR_SUPPORT_FORK_SAFETY", &(MV2_SUPPORT_FORK_SAFETY));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SUPPORT_FORK_SAFETY");
    rc = MPL_env2int("MV2_SUPPORT_FORK_SAFETY", &(MV2_SUPPORT_FORK_SAFETY));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SUPPORT_FORK_SAFETY");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_RDMA_MAX_TRANSFER_SIZE, /* name */
        &MV2_RDMA_MAX_TRANSFER_SIZE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_RDMA_MAX_TRANSFER_SIZE = defaultval.d;
    rc = MPL_env2int("UCR_RDMA_MAX_TRANSFER_SIZE", &(MV2_RDMA_MAX_TRANSFER_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_RDMA_MAX_TRANSFER_SIZE");
    rc = MPL_env2int("MV2_RDMA_MAX_TRANSFER_SIZE", &(MV2_RDMA_MAX_TRANSFER_SIZE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_RDMA_MAX_TRANSFER_SIZE");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_RNDV_IMMEDIATE, /* name */
        &MV2_RNDV_IMMEDIATE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_RNDV_IMMEDIATE = defaultval.d;
    rc = MPL_env2int("UCR_RNDV_IMMEDIATE", &(MV2_RNDV_IMMEDIATE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_RNDV_IMMEDIATE");
    rc = MPL_env2int("MV2_RNDV_IMMEDIATE", &(MV2_RNDV_IMMEDIATE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_RNDV_IMMEDIATE");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_CHECK_CACHE_ALIGNMENT, /* name */
        &MV2_CHECK_CACHE_ALIGNMENT, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_CHECK_CACHE_ALIGNMENT = defaultval.d;
    rc = MPL_env2int("UCR_CHECK_CACHE_ALIGNMENT", &(MV2_CHECK_CACHE_ALIGNMENT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_CHECK_CACHE_ALIGNMENT");
    rc = MPL_env2int("MV2_CHECK_CACHE_ALIGNMENT", &(MV2_CHECK_CACHE_ALIGNMENT));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_CHECK_CACHE_ALIGNMENT");

    defaultval.d = 512;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_HYBRID_ENABLE_THRESHOLD, /* name */
        &MV2_HYBRID_ENABLE_THRESHOLD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This defines the threshold for enabling Hybrid communication using UD and RC/XRC. When the size of the job is greater than or equal to the threshold value, Hybrid mode will be enabled. Otherwise, it uses default RC/XRC connections for communication.");
    MV2_HYBRID_ENABLE_THRESHOLD = defaultval.d;
    rc = MPL_env2int("UCR_HYBRID_ENABLE_THRESHOLD", &(MV2_HYBRID_ENABLE_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_HYBRID_ENABLE_THRESHOLD");
    rc = MPL_env2int("MV2_HYBRID_ENABLE_THRESHOLD", &(MV2_HYBRID_ENABLE_THRESHOLD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_HYBRID_ENABLE_THRESHOLD");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_ONLY_UD, /* name */
        &MV2_USE_ONLY_UD, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Set this to 1, to enable only UD transport in hybrid configuration mode. It will not use any RC/XRC connections in this mode.");
    MV2_USE_ONLY_UD = defaultval.d;
    rc = MPL_env2int("UCR_USE_ONLY_UD", &(MV2_USE_ONLY_UD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_ONLY_UD");
    rc = MPL_env2int("MV2_USE_ONLY_UD", &(MV2_USE_ONLY_UD));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_ONLY_UD");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SHOW_ENV_INFO, /* name */
        &MV2_SHOW_ENV_INFO, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Show the values assigned to the run time environment parameters.");
    MV2_SHOW_ENV_INFO = defaultval.d;
    rc = MPL_env2int("UCR_SHOW_ENV_INFO", &(MV2_SHOW_ENV_INFO));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SHOW_ENV_INFO");
    rc = MPL_env2int("MV2_SHOW_ENV_INFO", &(MV2_SHOW_ENV_INFO));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SHOW_ENV_INFO");

    defaultval.str = (const char *) NULL;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_CHAR,
        MV2_DEBUG_CORESIZE, /* name */
        &MV2_DEBUG_CORESIZE, /* address */
        MV2_MAX_STRLEN, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    tmp_str = defaultval.str;
    rc = MPL_env2str("UCR_DEBUG_CORESIZE", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_DEBUG_CORESIZE");
    rc = MPL_env2str("MV2_DEBUG_CORESIZE", &tmp_str);
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_DEBUG_CORESIZE");
    if (tmp_str != NULL) {
        MV2_DEBUG_CORESIZE = MPL_strdup(tmp_str);
        MV2_assert(MV2_DEBUG_CORESIZE);
        if (MV2_DEBUG_CORESIZE == NULL) {
            MPIR_CHKMEM_SETERR(mpi_errno, strlen(tmp_str), "dup of string for MV2_DEBUG_CORESIZE");
            goto fn_fail;
        }
    }
    else {
        MV2_DEBUG_CORESIZE = NULL;
    }

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_DEBUG_SHOW_BACKTRACE, /* name */
        &MV2_DEBUG_SHOW_BACKTRACE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_DEBUG_SHOW_BACKTRACE = defaultval.d;
    rc = MPL_env2bool("UCR_DEBUG_SHOW_BACKTRACE", &(MV2_DEBUG_SHOW_BACKTRACE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_DEBUG_SHOW_BACKTRACE");
    rc = MPL_env2bool("MV2_DEBUG_SHOW_BACKTRACE", &(MV2_DEBUG_SHOW_BACKTRACE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_DEBUG_SHOW_BACKTRACE");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_THREAD_WARNING, /* name */
        &MV2_USE_THREAD_WARNING, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_USE_THREAD_WARNING = defaultval.d;
    rc = MPL_env2bool("UCR_USE_THREAD_WARNING", &(MV2_USE_THREAD_WARNING));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_THREAD_WARNING");
    rc = MPL_env2bool("MV2_USE_THREAD_WARNING", &(MV2_USE_THREAD_WARNING));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_THREAD_WARNING");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_POLLING_LEVEL, /* name */
        &MV2_POLLING_LEVEL, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Defines the frequency at which the IB device is polled");
    MV2_POLLING_LEVEL = defaultval.d;
    rc = MPL_env2int("UCR_POLLING_LEVEL", &(MV2_POLLING_LEVEL));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_POLLING_LEVEL");
    rc = MPL_env2int("MV2_POLLING_LEVEL", &(MV2_POLLING_LEVEL));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_POLLING_LEVEL");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_WALK_SHARED_PAGES, /* name */
        &MV2_WALK_SHARED_PAGES, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_WALK_SHARED_PAGES = defaultval.d;
    rc = MPL_env2int("UCR_WALK_SHARED_PAGES", &(MV2_WALK_SHARED_PAGES));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_WALK_SHARED_PAGES");
    rc = MPL_env2int("MV2_WALK_SHARED_PAGES", &(MV2_WALK_SHARED_PAGES));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_WALK_SHARED_PAGES");

    defaultval.d = -1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SMP_PRIORITY_FACTOR, /* name */
        &MV2_SMP_PRIORITY_FACTOR, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_SMP_PRIORITY_FACTOR = defaultval.d;
    rc = MPL_env2int("UCR_SMP_PRIORITY_FACTOR", &(MV2_SMP_PRIORITY_FACTOR));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SMP_PRIORITY_FACTOR");
    rc = MPL_env2int("MV2_SMP_PRIORITY_FACTOR", &(MV2_SMP_PRIORITY_FACTOR));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SMP_PRIORITY_FACTOR");

    defaultval.d = 1;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_USE_PT2PT_SHMEM, /* name */
        &MV2_USE_PT2PT_SHMEM, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "Enable shared memory for pt2pt communications");
    MV2_USE_PT2PT_SHMEM = defaultval.d;
    rc = MPL_env2int("UCR_USE_PT2PT_SHMEM", &(MV2_USE_PT2PT_SHMEM));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_USE_PT2PT_SHMEM");
    rc = MPL_env2int("MV2_USE_PT2PT_SHMEM", &(MV2_USE_PT2PT_SHMEM));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_USE_PT2PT_SHMEM");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_ABORT_SLEEP_SECONDS, /* name */
        &MV2_ABORT_SLEEP_SECONDS, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "TODO-DESC");
    MV2_ABORT_SLEEP_SECONDS = defaultval.d;
    rc = MPL_env2int("UCR_ABORT_SLEEP_SECONDS", &(MV2_ABORT_SLEEP_SECONDS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_ABORT_SLEEP_SECONDS");
    rc = MPL_env2int("MV2_ABORT_SLEEP_SECONDS", &(MV2_ABORT_SLEEP_SECONDS));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_ABORT_SLEEP_SECONDS");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_FORCE_ARCH_TYPE, /* name */
        &MV2_FORCE_ARCH_TYPE, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH3", /* category */
        "This parameter forces the architecture type.");
    MV2_FORCE_ARCH_TYPE = defaultval.d;
    rc = MPL_env2int("UCR_FORCE_ARCH_TYPE", &(MV2_FORCE_ARCH_TYPE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_FORCE_ARCH_TYPE");
    rc = MPL_env2int("MV2_FORCE_ARCH_TYPE", &(MV2_FORCE_ARCH_TYPE));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_FORCE_ARCH_TYPE");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SHOW_CPU_BINDING, /* name */
        &MV2_SHOW_CPU_BINDING, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH4", /* category */
        "Possible values: 0, 1, 2 If set to 1, prints the CPU mapping of all processes on the node where rank 0 exists. If set to 2, prints the CPU mapping of all processes on all nodes. ");
    MV2_SHOW_CPU_BINDING = defaultval.d;
    rc = MPL_env2int("UCR_SHOW_CPU_BINDING", &(MV2_SHOW_CPU_BINDING));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SHOW_CPU_BINDING");
    rc = MPL_env2int("MV2_SHOW_CPU_BINDING", &(MV2_SHOW_CPU_BINDING));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SHOW_CPU_BINDING");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SHOW_HCA_BINDING, /* name */
        &MV2_SHOW_HCA_BINDING, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH4", /* category */
        "Possible values: 0, 1, 2 If set to 1, prints the HCA mapping of all processes on the node where rank 0 exists. If set to 2, prints the HCA mapping of all processes on all nodes. ");
    MV2_SHOW_HCA_BINDING = defaultval.d;
    rc = MPL_env2int("UCR_SHOW_HCA_BINDING", &(MV2_SHOW_HCA_BINDING));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SHOW_HCA_BINDING");
    rc = MPL_env2int("MV2_SHOW_HCA_BINDING", &(MV2_SHOW_HCA_BINDING));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SHOW_HCA_BINDING");

    defaultval.d = 0;
    MPIR_T_CVAR_REGISTER_STATIC(
        MPI_INT,
        MV2_SHOW_HW_BINDING, /* name */
        &MV2_SHOW_HW_BINDING, /* address */
        1, /* count */
        MPI_T_VERBOSITY_USER_BASIC,
        MPI_T_SCOPE_ALL_EQ,
        defaultval,
        "CH4", /* category */
        "Possible values: 0, 1, 2 If set to 1, prints the CPU and HCA mappings of all processes on the node where rank 0 exists. If set to 2, prints the CPU and HCA mappings of all processes on all nodes. ");
    MV2_SHOW_HW_BINDING = defaultval.d;
    rc = MPL_env2int("UCR_SHOW_HW_BINDING", &(MV2_SHOW_HW_BINDING));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","UCR_SHOW_HW_BINDING");
    rc = MPL_env2int("MV2_SHOW_HW_BINDING", &(MV2_SHOW_HW_BINDING));
    MPIR_ERR_CHKANDJUMP1((-1 == rc),mpi_errno,MPI_ERR_OTHER,"**envvarparse","**envvarparse %s","MV2_SHOW_HW_BINDING");

fn_exit:
    return mpi_errno;
fn_fail:
    goto fn_exit;
}

int MPIR_T_MV2_cvar_finalize(void)
{
    int mpi_errno = MPI_SUCCESS;

    MPL_free((char *)MV2_CPU_BINDING_LEVEL);
    MV2_CPU_BINDING_LEVEL = NULL;

    MPL_free((char *)MV2_CPU_MAPPING);
    MV2_CPU_MAPPING = NULL;

    MPL_free((char *)MV2_CPU_BINDING_POLICY);
    MV2_CPU_BINDING_POLICY = NULL;

    MPL_free((char *)MV2_SHMEM_DIR);
    MV2_SHMEM_DIR = NULL;

    MPL_free((char *)MV2_IBA_HCA);
    MV2_IBA_HCA = NULL;

    MPL_free((char *)MV2_PROCESS_TO_RAIL_MAPPING);
    MV2_PROCESS_TO_RAIL_MAPPING = NULL;

    MPL_free((char *)MV2_SM_SCHEDULING);
    MV2_SM_SCHEDULING = NULL;

    MPL_free((char *)MV2_SMALL_MSG_RAIL_SHARING_POLICY);
    MV2_SMALL_MSG_RAIL_SHARING_POLICY = NULL;

    MPL_free((char *)MV2_MED_MSG_RAIL_SHARING_POLICY);
    MV2_MED_MSG_RAIL_SHARING_POLICY = NULL;

    MPL_free((char *)MV2_RAIL_SHARING_POLICY);
    MV2_RAIL_SHARING_POLICY = NULL;

    MPL_free((char *)MV2_RNDV_PROTOCOL);
    MV2_RNDV_PROTOCOL = NULL;

    MPL_free((char *)MV2_SMP_RNDV_PROTOCOL);
    MV2_SMP_RNDV_PROTOCOL = NULL;

    MPL_free((char *)MV2_DEFAULT_MTU);
    MV2_DEFAULT_MTU = NULL;

    MPL_free((char *)MV2_DEFAULT_PKEY);
    MV2_DEFAULT_PKEY = NULL;

    MPL_free((char *)MV2_DEFAULT_QKEY);
    MV2_DEFAULT_QKEY = NULL;

    MPL_free((char *)MV2_LIBIBVERBS_PATH);
    MV2_LIBIBVERBS_PATH = NULL;

    MPL_free((char *)MV2_LIBIBMAD_PATH);
    MV2_LIBIBMAD_PATH = NULL;

    MPL_free((char *)MV2_LIBIBUMAD_PATH);
    MV2_LIBIBUMAD_PATH = NULL;

    MPL_free((char *)MV2_LIBRDMACM_PATH);
    MV2_LIBRDMACM_PATH = NULL;

    MPL_free((char *)MV2_LIBSHARP_PATH);
    MV2_LIBSHARP_PATH = NULL;

    MPL_free((char *)MV2_DEBUG_CORESIZE);
    MV2_DEBUG_CORESIZE = NULL;

    return mpi_errno;
}

