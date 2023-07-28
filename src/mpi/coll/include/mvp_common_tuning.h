/* Copyright (c) 2001-2023, The Ohio State University. All rights
 * reserved.
 *
 * This file is part of the MVAPICH software package developed by the
 * team members of The Ohio State University's Network-Based Computing
 * Laboratory (NBCL), headed by Professor Dhabaleswar K. (DK) Panda.
 *
 * For detailed copyright and licensing information, please refer to the
 * copyright file COPYRIGHT in the top level MVAPICH directory.
 *
 */
#ifndef _COMMON_TUNING_
#define _COMMON_TUNING_

#include "mpichconf.h"

#define MVP_COLL_TUNING_SETUP_TABLE(_cname)                                    \
    int *mvp_##_cname##_table_ppn_conf = NULL;                                 \
    int mvp_##_cname##_num_ppn_conf = 1;                                       \
    int *mvp_size_##_cname##_tuning_table = NULL;                              \
    mvp_##_cname##_tuning_table **mvp_##_cname##_thresholds_table = NULL;      \
    int *mvp_##_cname##_indexed_table_ppn_conf = NULL;                         \
    int mvp_##_cname##_indexed_num_ppn_conf = 1;                               \
    int *mvp_size_##_cname##_indexed_tuning_table = NULL;                      \
    mvp_##_cname##_indexed_tuning_table *                                      \
        *mvp_##_cname##_indexed_thresholds_table = NULL;

#define MVP_COLL_TUNING_START_TABLE(_cname, _nconf)                            \
    {                                                                          \
        colls_arch_hca[_cname].arch_type = table_arch_tmp;                     \
        colls_arch_hca[_cname].hca_type = table_hca_tmp;                       \
        int idx = -1, nconf = _nconf;                                          \
        mvp_##_cname##_indexed_num_ppn_conf = nconf;                           \
        mvp_##_cname##_indexed_thresholds_table =                              \
            MPL_malloc(sizeof(mvp_##_cname##_indexed_tuning_table *) * nconf,  \
                       MPL_MEM_COLL);                                          \
        table_ptrs =                                                           \
            MPL_malloc(sizeof(mvp_##_cname##_indexed_tuning_table *) * nconf,  \
                       MPL_MEM_COLL);                                          \
        mvp_size_##_cname##_indexed_tuning_table =                             \
            MPL_malloc(sizeof(int) * nconf, MPL_MEM_COLL);                     \
        mvp_##_cname##_indexed_table_ppn_conf =                                \
            MPL_malloc(sizeof(int) * nconf, MPL_MEM_COLL);

#define MVP_COLL_TUNING_ADD_CONF(_cname, _ppn, _size, _name)                   \
    ++idx;                                                                     \
    mvp_##_cname##_indexed_tuning_table tmp_##_cname##_ppn[] = _name;          \
    mvp_##_cname##_indexed_table_ppn_conf[idx] = _ppn;                         \
    mvp_size_##_cname##_indexed_tuning_table[idx] = _size;                     \
    table_ptrs[idx] = tmp_##_cname##_ppn;

#if defined(_SMP_CMA_)
#define MVP_COLL_TUNING_ADD_CONF_CMA(_cname, _ppn, _size, _name)               \
    mvp_##_cname##_indexed_tuning_table tmp_cma_##_cname##_ppn[] = _name;      \
    if (MVP_SMP_USE_CMA) {                                                     \
        mvp_##_cname##_indexed_table_ppn_conf[idx] = _ppn;                     \
        mvp_size_##_cname##_indexed_tuning_table[idx] = _size;                 \
        table_ptrs[idx] = tmp_cma_##_cname##_ppn;                              \
    }
#else
#define MVP_COLL_TUNING_ADD_CONF_CMA(_cname, _ppn, _size, _name)
#endif

#define MVP_COLL_TUNING_FINISH_TABLE(_cname)                                   \
    agg_table_sum = 0;                                                         \
    for (i = 0; i < nconf; i++) {                                              \
        agg_table_sum += mvp_size_##_cname##_indexed_tuning_table[i];          \
    }                                                                          \
    mvp_##_cname##_indexed_thresholds_table[0] = MPL_malloc(                   \
        sizeof(mvp_##_cname##_indexed_tuning_table) * agg_table_sum,           \
        MPL_MEM_COLL);                                                         \
    MPIR_Memcpy(mvp_##_cname##_indexed_thresholds_table[0], table_ptrs[0],     \
                sizeof(mvp_##_cname##_indexed_tuning_table) *                  \
                    mvp_size_##_cname##_indexed_tuning_table[0]);              \
    for (i = 1; i < nconf; i++) {                                              \
        mvp_##_cname##_indexed_thresholds_table[i] =                           \
            mvp_##_cname##_indexed_thresholds_table[i - 1] +                   \
            mvp_size_##_cname##_indexed_tuning_table[i - 1];                   \
        MPIR_Memcpy(mvp_##_cname##_indexed_thresholds_table[i], table_ptrs[i], \
                    sizeof(mvp_##_cname##_indexed_tuning_table) *              \
                        mvp_size_##_cname##_indexed_tuning_table[i]);          \
    }                                                                          \
    MPL_free(table_ptrs);                                                      \
    return 0;                                                                  \
    }

#define FIND_PPN_INDEX(_cname, _locsize, _confindx, _parflag)                  \
    {                                                                          \
        int i = 0;                                                             \
        do {                                                                   \
            if (_locsize == mvp_##_cname##_indexed_table_ppn_conf[i]) {        \
                _confindx = i;                                                 \
                _parflag = 1;                                                  \
                break;                                                         \
            } else if (i < mvp_##_cname##_indexed_num_ppn_conf - 1) {          \
                if (_locsize > mvp_##_cname##_indexed_table_ppn_conf[i] &&     \
                    _locsize < mvp_##_cname##_indexed_table_ppn_conf[i + 1]) { \
                    _confindx = i + 1;                                         \
                    _parflag = 1;                                              \
                    break;                                                     \
                }                                                              \
            } else if (i == mvp_##_cname##_indexed_num_ppn_conf - 1) {         \
                if (_locsize > mvp_##_cname##_indexed_table_ppn_conf[i]) {     \
                    _confindx = i;                                             \
                    _parflag = 1;                                              \
                    break;                                                     \
                }                                                              \
            }                                                                  \
            i++;                                                               \
        } while (i < mvp_##_cname##_indexed_num_ppn_conf);                     \
    }

/* defined enum for right hand side values used in mvp collective algorithms
 selection. */
enum mvp_bcast_tuning {
    SHMEM_BCAST_INTRA,
    KNOMIAL_BCAST_INTRA,
    BCAST_BIONOMIAL_INTRA,
    BCAST_SCATTER_DOUBLING_ALLGATHER_FLAT,
    BCAST_SCATTER_DOUBLING_ALLGATHER,
    BCAST_SCATTER_RING_ALLGATEHR_FLAT,
    BCAST_SCATTER_RING_ALLGATHER,
    BCAST_SCATTER_RING_ALLGATHER_SHM,
    KNOMIAL_BCAST_INTER_NODE_WRAPPER,
    PIPELINED_BCAST,
    PIPELINED_BCAST_ZCPY
};

enum mvp_reduce_tuning {
    REDUCE_BINOMIAL = 1,
    REDUCE_INTER_KNOMIAL,
    REDUCE_INTRA_KNOMIAL,
    REDUCE_SHMEM,
    REDUCE_RDSC_GATHER,
    REDUCE_ZCPY,
    REDUCE_X1, /* place holder for master-x algorithm */
    REDUCE_ALLREDUCE
};

enum mvp_allreduce_tuning {
    ALLREDUCE_P2P_RD = 1,
    ALLREDUCE_P2P_RS,
    ALLREDUCE_MCAST_2LEVEL,
    ALLREDUCE_MCAST_RSA,
    ALLREDUCE_SHMEM_REDUCE,
    ALLREDUCE_P2P_REDUCE,
    ALLREDUCE_X1, /* place holder for master-x algorithm */
    ALLREDUCE_RED_SCAT_ALLGA_COLL,
    ALLREDUCE_RING,
    ALLREDUCE_X2, /* place holder for master-x algorithm */
    ALLREDUCE_SOCK_AWARE,
    ALLREDUCE_X3, /* place holder for master-x algorithm */
};

enum mvp_scatter_tuning {
    SCATTER_BINOMIAL = 1,
    SCATTER_DIRECT,
    SCATTER_TWO_LEVEL_BINOMIAL,
    SCATTER_TWO_LEVEL_DIRECT,
    SCATTER_MCAST
};

enum {
    RED_SCAT_BASIC = 1,
    RED_SCAT_REC_HALF,
    RED_SCAT_PAIRWISE,
    RED_SCAT_RING,
    RED_SCAT_RING_2LVL,
};

enum mvp_alltoall_tuning {
    ALLTOALL_BRUCK_MVP,
    ALLTOALL_RD_MVP,
    ALLTOALL_SCATTER_DEST_MVP,
    ALLTOALL_PAIRWISE_MVP,
    ALLTOALL_INPLACE_MVP
};

enum mvp_alltoallv_tuning {
    ALLTOALLV_INTRA_SCATTER_MVP,
    ALLTOALLV_INTRA_MVP,
    ALLTOALLV_MVP
};

enum mvp_ibcast_tuning {
    IBCAST_BINOMIAL = 1,
    IBCAST_SCATTER_REC_DBL_ALLGATHER,
    IBCAST_SCATTER_RING_ALLGATHER
};

enum mvp_igather_tuning {
    IGATHER_BINOMIAL = 1,
#ifdef _USE_CORE_DIRECT_
    IGATHER_DIRECT
#endif /* _USE_CORE_DIRECT_ */
};

enum mvp_iallreduce_tuning {
    IALLREDUCE_NAIVE = 1,
    IALLREDUCE_REDSCAT_ALLGATHER,
    IALLREDUCE_REC_DBL,
#if defined(_SHARP_SUPPORT_)
    SHARP_IALLREDUCE_MVP
#endif /*defined (_SHARP_SUPPORT_)*/
};

enum mvp_ired_scat_tuning {
    IREDUCE_SCATTER_PAIRWISE = 1,
    IREDUCE_SCATTER_REC_HLV,
    IREDUCE_SCATTER_REC_DBL,
    IREDUCE_SCATTER_NONCOMM
};

enum mvp_ialltoall_tuning {
    IALLTOALL_BRUCK = 1,
    IALLTOALL_PERM_SR,
    IALLTOALL_PAIRWISE
};

enum mvp_ireduce_tuning { IREDUCE_BINOMIAL = 1, IREDUCE_REDSCAT_GATHER };

enum mvp_iscatter_tuning {
    ISCATTER_BINOMIAL = 1,
#ifdef _USE_CORE_DIRECT_
    ISCATTER_DIRECT
#endif /* _USE_CORE_DIRECT_ */
};

enum mvp_ibarrier_tuning { IBARRIER_INTRA = 1 };
#endif
