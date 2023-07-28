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
#include <regex.h>
#include "mvp_common_tuning.h"
#include "bcast_tuning.h"
#include "bcast_arch_tuning.h"

/* TODO: This should be moved to the pre-header as it is in ch4 */
#ifdef CHANNEL_MRAIL
#include "mvp_arch_hca_detect.h"
#endif

/* array used to tune bcast */

int mvp_size_bcast_tuning_table = 0;
mvp_bcast_tuning_table *mvp_bcast_thresholds_table = NULL;

int *mvp_bcast_indexed_table_ppn_conf = NULL;
int mvp_bcast_indexed_num_ppn_conf = 1;
int *mvp_size_bcast_indexed_tuning_table = NULL;
mvp_bcast_indexed_tuning_table **mvp_bcast_indexed_thresholds_table = NULL;

static inline MVP_Bcast_fn_t MVP_get_inter_node_bcast_fn()
{
    switch (MVP_BCAST_INTER_NODE_TUNING_ALGO) {
        case MVP_BCAST_INTER_NODE_TUNING_ALGO_SCATTER_DOUBLING_ALLGATHER:
            return &MPIR_Bcast_scatter_doubling_allgather_MVP;
        case MVP_BCAST_INTER_NODE_TUNING_ALGO_SCATTER_RING_ALLGATHER:
            return &MPIR_Bcast_scatter_ring_allgather_MVP;
        case MVP_BCAST_INTER_NODE_TUNING_ALGO_SCATTER_RING_ALLGATHER_SHM:
            return &MPIR_Bcast_scatter_ring_allgather_shm_MVP;
        case MVP_BCAST_INTER_NODE_TUNING_ALGO_KNOMIAL:
            return &MPIR_Knomial_Bcast_inter_node_wrapper_MVP;
        case MVP_BCAST_INTER_NODE_TUNING_ALGO_PIPELINED:
            return &MPIR_Pipelined_Bcast_MVP;
        default:
            PRINT_ERROR("WARNING: Invalid value for "
                        "MVP_BCAST_INTER_NODE_TUNING_ALGO.\n");
        case MVP_BCAST_INTER_NODE_TUNING_ALGO_UNSET:
        case MVP_BCAST_INTER_NODE_TUNING_ALGO_BINOMIAL:
            return &MPIR_Bcast_binomial_MVP;
    }
}
static inline MVP_Bcast_fn_t MVP_get_intra_node_bcast_fn()
{
    switch (MVP_BCAST_INTRA_NODE_TUNING_ALGO) {
        case MVP_BCAST_INTRA_NODE_TUNING_ALGO_KNOMIAL:
            return &MPIR_Knomial_Bcast_intra_node_MVP;
        default:
            PRINT_ERROR("WARNING: Invalid value for "
                        "MVP_BCAST_INTRA_NODE_TUNING_ALGO.\n");
        case MVP_BCAST_INTRA_NODE_TUNING_ALGO_UNSET:
        case MVP_BCAST_INTRA_NODE_TUNING_ALGO_SHMEM:
            return &MPIR_Shmem_Bcast_MVP;
    }
}

static inline void MVP_set_user_defined_gather_tuning_table()
{
    mvp_bcast_indexed_num_ppn_conf = 1;

    mvp_bcast_indexed_thresholds_table =
        MPL_malloc(mvp_bcast_indexed_num_ppn_conf *
                       sizeof(mvp_bcast_indexed_tuning_table *),
                   MPL_MEM_COLL);
    mvp_size_bcast_indexed_tuning_table =
        MPL_malloc(mvp_bcast_indexed_num_ppn_conf * sizeof(int), MPL_MEM_COLL);
    mvp_bcast_indexed_table_ppn_conf =
        MPL_malloc(mvp_bcast_indexed_num_ppn_conf * sizeof(int), MPL_MEM_COLL);

    /* -1 indicates user defined algorithm */
    mvp_bcast_indexed_table_ppn_conf[0] = -1;
    mvp_size_bcast_indexed_tuning_table[0] = 1;
    mvp_bcast_indexed_thresholds_table[0] =
        MPL_malloc(mvp_size_bcast_indexed_tuning_table[0] *
                       sizeof(mvp_bcast_indexed_tuning_table),
                   MPL_MEM_COLL);

    mvp_bcast_indexed_tuning_table tmp_table = {
        .numproc = 1,
        .bcast_segment_size = MVP_BCAST_SEGMENT_SIZE,
        .inter_node_knomial_factor = MVP_KNOMIAL_INTER_NODE_FACTOR,
        .intra_node_knomial_factor = MVP_KNOMIAL_INTRA_NODE_FACTOR,
        .is_two_level_bcast[0] = MVP_BCAST_TUNING_IS_TWO_LEVEL,
        .size_inter_table = 1,
        .inter_leader[0] = {.msg_sz = 1,
                            .zcpy_pipelined_knomial_factor = -1,
                            .bcast_fn = MVP_get_inter_node_bcast_fn()},
        .size_intra_table = 1,
        .intra_node[0] = {.msg_sz = 1,
                          .zcpy_pipelined_knomial_factor = -1,
                          .bcast_fn = MVP_get_intra_node_bcast_fn()},
    };

    MPIR_Memcpy(mvp_bcast_indexed_thresholds_table[0], &tmp_table,
                sizeof(mvp_bcast_indexed_tuning_table));
}

int MVP_set_bcast_tuning_table(int heterogeneity,
                               struct coll_info *colls_arch_hca)
{
    int agg_table_sum = 0;
    int i;
    mvp_bcast_indexed_tuning_table **table_ptrs = NULL;

    if (MVP_BCAST_INTER_NODE_TUNING_ALGO_UNSET !=
            MVP_BCAST_INTER_NODE_TUNING_ALGO ||
        MVP_BCAST_INTRA_NODE_TUNING_ALGO_UNSET !=
            MVP_BCAST_INTRA_NODE_TUNING_ALGO) {
        MVP_set_user_defined_gather_tuning_table();
        return 0;
    }

#if defined(_MVP_CH4_OVERRIDE_)
    if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                             MVP_ARCH_INTEL_XEON_X5650_12, MVP_HCA_QLGIC_QIB) &&
        !heterogeneity) {
        /*Sierra Table*/
        mvp_bcast_indexed_num_ppn_conf = 2;
        mvp_bcast_indexed_thresholds_table =
            MPL_malloc(sizeof(mvp_bcast_indexed_tuning_table *) *
                           mvp_bcast_indexed_num_ppn_conf,
                       MPL_MEM_COLL);
        table_ptrs = MPL_malloc(sizeof(mvp_bcast_indexed_tuning_table *) *
                                    mvp_bcast_indexed_num_ppn_conf,
                                MPL_MEM_COLL);
        mvp_size_bcast_indexed_tuning_table = MPL_malloc(
            sizeof(int) * mvp_bcast_indexed_num_ppn_conf, MPL_MEM_COLL);
        mvp_bcast_indexed_table_ppn_conf = MPL_malloc(
            mvp_bcast_indexed_num_ppn_conf * sizeof(int), MPL_MEM_COLL);

        mvp_bcast_indexed_table_ppn_conf[0] = 1;
        mvp_size_bcast_indexed_tuning_table[0] = 5;
        mvp_bcast_indexed_tuning_table
            mvp_tmp_bcast_indexed_thresholds_table_1ppn[] =
                PSM__INTEL_XEON_X5650_12__MVP_HCA_QLGIC_QIB__1PPN;
        table_ptrs[0] = mvp_tmp_bcast_indexed_thresholds_table_1ppn;

        mvp_bcast_indexed_table_ppn_conf[1] = 12;
        mvp_size_bcast_indexed_tuning_table[1] = 6;
        mvp_bcast_indexed_tuning_table
            mvp_tmp_bcast_indexed_thresholds_table_32ppn[] =
                PSM__INTEL_XEON_X5650_12__MVP_HCA_QLGIC_QIB__12PPN;
        table_ptrs[1] = mvp_tmp_bcast_indexed_thresholds_table_32ppn;

        agg_table_sum = 0;
        for (i = 0; i < mvp_bcast_indexed_num_ppn_conf; i++) {
            agg_table_sum += mvp_size_bcast_indexed_tuning_table[i];
        }
        mvp_bcast_indexed_thresholds_table[0] =
            MPL_malloc(agg_table_sum * sizeof(mvp_bcast_indexed_tuning_table),
                       MPL_MEM_COLL);
        MPIR_Memcpy(mvp_bcast_indexed_thresholds_table[0], table_ptrs[0],
                    (sizeof(mvp_bcast_indexed_tuning_table) *
                     mvp_size_bcast_indexed_tuning_table[0]));
        for (i = 1; i < mvp_bcast_indexed_num_ppn_conf; i++) {
            mvp_bcast_indexed_thresholds_table[i] =
                mvp_bcast_indexed_thresholds_table[i - 1] +
                mvp_size_bcast_indexed_tuning_table[i - 1];
            MPIR_Memcpy(mvp_bcast_indexed_thresholds_table[i], table_ptrs[i],
                        (sizeof(mvp_bcast_indexed_tuning_table) *
                         mvp_size_bcast_indexed_tuning_table[i]));
        }
        MPL_free(table_ptrs);
        return 0;
    } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                    MVP_ARCH_INTEL_XEON_E5_2695_V3_2S_28,
                                    MVP_HCA_INTEL_HFI1) &&
               !heterogeneity) {
        /*Bridges Table*/
        MVP_COLL_TUNING_START_TABLE(bcast, 6)
        MVP_COLL_TUNING_ADD_CONF(
            bcast, 1, 4, PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__1PPN)
        MVP_COLL_TUNING_ADD_CONF(
            bcast, 2, 5, PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__2PPN)
        MVP_COLL_TUNING_ADD_CONF(
            bcast, 4, 5, PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__4PPN)
        MVP_COLL_TUNING_ADD_CONF(
            bcast, 8, 5, PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__8PPN)
        MVP_COLL_TUNING_ADD_CONF(
            bcast, 16, 5, PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__16PPN)
        MVP_COLL_TUNING_ADD_CONF(
            bcast, 28, 5, PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__28PPN)
        MVP_COLL_TUNING_FINISH_TABLE(bcast)
    } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                    MVP_ARCH_INTEL_XEON_E5_2695_V4_2S_36,
                                    MVP_HCA_INTEL_HFI1) &&
               !heterogeneity) {
        /* Bebop/Jade/Opal Table */
        MVP_COLL_TUNING_START_TABLE(bcast, 5)
        MVP_COLL_TUNING_ADD_CONF(
            bcast, 1, 5, PSM__INTEL_XEON_E5_2695_V4_2S_36_INTEL_HFI_100__1PPN)
        MVP_COLL_TUNING_ADD_CONF(
            bcast, 4, 5, PSM__INTEL_XEON_E5_2695_V4_2S_36_INTEL_HFI_100__4PPN)
        MVP_COLL_TUNING_ADD_CONF(
            bcast, 8, 5, PSM__INTEL_XEON_E5_2695_V4_2S_36_INTEL_HFI_100__8PPN)
        MVP_COLL_TUNING_ADD_CONF(
            bcast, 16, 5, PSM__INTEL_XEON_E5_2695_V4_2S_36_INTEL_HFI_100__16PPN)
        MVP_COLL_TUNING_ADD_CONF(
            bcast, 36, 5, PSM__INTEL_XEON_E5_2695_V4_2S_36_INTEL_HFI_100__36PPN)
        MVP_COLL_TUNING_FINISH_TABLE(bcast)
    } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                    MVP_ARCH_INTEL_XEON_PHI_7250,
                                    MVP_HCA_INTEL_HFI1) &&
               !heterogeneity) {
        /* TACC-KNL Table */
        MVP_COLL_TUNING_START_TABLE(bcast, 6)
        MVP_COLL_TUNING_ADD_CONF(
            bcast, 1, 5, PSM__INTEL_XEON_PHI_7250_68_INTEL_HFI_100__1PPN)
        MVP_COLL_TUNING_ADD_CONF(
            bcast, 4, 6, PSM__INTEL_XEON_PHI_7250_68_INTEL_HFI_100__4PPN)
        MVP_COLL_TUNING_ADD_CONF(
            bcast, 8, 5, PSM__INTEL_XEON_PHI_7250_68_INTEL_HFI_100__8PPN)
        MVP_COLL_TUNING_ADD_CONF(
            bcast, 16, 5, PSM__INTEL_XEON_PHI_7250_68_INTEL_HFI_100__16PPN)
        MVP_COLL_TUNING_ADD_CONF(
            bcast, 32, 5, PSM__INTEL_XEON_PHI_7250_68_INTEL_HFI_100__32PPN)
        MVP_COLL_TUNING_ADD_CONF(
            bcast, 64, 4, PSM__INTEL_XEON_PHI_7250_68_INTEL_HFI_100__64PPN)
        MVP_COLL_TUNING_FINISH_TABLE(bcast)
    } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                    MVP_ARCH_INTEL_PLATINUM_8170_2S_52,
                                    MVP_HCA_INTEL_HFI1) &&
               !heterogeneity) {
        /* TACC-Skylake Table */
        MVP_COLL_TUNING_START_TABLE(bcast, 7)
        MVP_COLL_TUNING_ADD_CONF(
            bcast, 1, 4, PSM__INTEL_PLATINUM_8170_2S_52_INTEL_HFI_100__1PPN)
        MVP_COLL_TUNING_ADD_CONF(
            bcast, 2, 5, PSM__INTEL_PLATINUM_8170_2S_52_INTEL_HFI_100__2PPN)
        MVP_COLL_TUNING_ADD_CONF(
            bcast, 4, 5, PSM__INTEL_PLATINUM_8170_2S_52_INTEL_HFI_100__4PPN)
        MVP_COLL_TUNING_ADD_CONF(
            bcast, 8, 5, PSM__INTEL_PLATINUM_8170_2S_52_INTEL_HFI_100__8PPN)
        MVP_COLL_TUNING_ADD_CONF(
            bcast, 16, 5, PSM__INTEL_PLATINUM_8170_2S_52_INTEL_HFI_100__16PPN)
        MVP_COLL_TUNING_ADD_CONF(
            bcast, 24, 5, PSM__INTEL_PLATINUM_8170_2S_52_INTEL_HFI_100__24PPN)
        MVP_COLL_TUNING_ADD_CONF(
            bcast, 48, 5, PSM__INTEL_PLATINUM_8170_2S_52_INTEL_HFI_100__48PPN)
        MVP_COLL_TUNING_FINISH_TABLE(bcast)
    } else {
        /*default psm table: Bridges Table*/
        MVP_COLL_TUNING_START_TABLE(bcast, 6)
        MVP_COLL_TUNING_ADD_CONF(
            bcast, 1, 4, PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__1PPN)
        MVP_COLL_TUNING_ADD_CONF(
            bcast, 2, 5, PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__2PPN)
        MVP_COLL_TUNING_ADD_CONF(
            bcast, 4, 5, PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__4PPN)
        MVP_COLL_TUNING_ADD_CONF(
            bcast, 8, 5, PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__8PPN)
        MVP_COLL_TUNING_ADD_CONF(
            bcast, 16, 5, PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__16PPN)
        MVP_COLL_TUNING_ADD_CONF(
            bcast, 28, 5, PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__28PPN)
        MVP_COLL_TUNING_FINISH_TABLE(bcast)
    }
#else
        {
            /*Stampede Table*/
            mvp_bcast_indexed_num_ppn_conf = 3;
            mvp_bcast_indexed_thresholds_table =
                MPL_malloc(sizeof(mvp_bcast_indexed_tuning_table *) *
                               mvp_bcast_indexed_num_ppn_conf,
                           MPL_MEM_COLL);
            table_ptrs = MPL_malloc(sizeof(mvp_bcast_indexed_tuning_table *) *
                                        mvp_bcast_indexed_num_ppn_conf,
                                    MPL_MEM_COLL);
            mvp_size_bcast_indexed_tuning_table = MPL_malloc(
                sizeof(int) * mvp_bcast_indexed_num_ppn_conf, MPL_MEM_COLL);
            mvp_bcast_indexed_table_ppn_conf = MPL_malloc(
                mvp_bcast_indexed_num_ppn_conf * sizeof(int), MPL_MEM_COLL);

            mvp_bcast_indexed_table_ppn_conf[0] = 1;
            mvp_size_bcast_indexed_tuning_table[0] = 5;
            mvp_bcast_indexed_tuning_table
                mvp_tmp_bcast_indexed_thresholds_table_1ppn[] =
                    NEMESIS__INTEL_XEON_E5_2680_16__MLX_CX_FDR__1PPN
                        table_ptrs[0] =
                            mvp_tmp_bcast_indexed_thresholds_table_1ppn;

            mvp_bcast_indexed_table_ppn_conf[1] = 2;
            mvp_size_bcast_indexed_tuning_table[1] = 5;
            mvp_bcast_indexed_tuning_table
                mvp_tmp_bcast_indexed_thresholds_table_2ppn[] =
                    NEMESIS__INTEL_XEON_E5_2680_16__MLX_CX_FDR__2PPN
                        table_ptrs[1] =
                            mvp_tmp_bcast_indexed_thresholds_table_2ppn;

            mvp_bcast_indexed_table_ppn_conf[2] = 16;
            mvp_size_bcast_indexed_tuning_table[2] = 7;
            mvp_bcast_indexed_tuning_table
                mvp_tmp_bcast_indexed_thresholds_table_16ppn[] =
                    NEMESIS__INTEL_XEON_E5_2680_16__MLX_CX_FDR__16PPN
                        table_ptrs[2] =
                            mvp_tmp_bcast_indexed_thresholds_table_16ppn;

            agg_table_sum = 0;
            for (i = 0; i < mvp_bcast_indexed_num_ppn_conf; i++) {
                agg_table_sum += mvp_size_bcast_indexed_tuning_table[i];
            }
            mvp_bcast_indexed_thresholds_table[0] = MPL_malloc(
                agg_table_sum * sizeof(mvp_bcast_indexed_tuning_table),
                MPL_MEM_COLL);
            MPIR_Memcpy(mvp_bcast_indexed_thresholds_table[0], table_ptrs[0],
                        (sizeof(mvp_bcast_indexed_tuning_table) *
                         mvp_size_bcast_indexed_tuning_table[0]));
            for (i = 1; i < mvp_bcast_indexed_num_ppn_conf; i++) {
                mvp_bcast_indexed_thresholds_table[i] =
                    mvp_bcast_indexed_thresholds_table[i - 1] +
                    mvp_size_bcast_indexed_tuning_table[i - 1];
                MPIR_Memcpy(mvp_bcast_indexed_thresholds_table[i],
                            table_ptrs[i],
                            (sizeof(mvp_bcast_indexed_tuning_table) *
                             mvp_size_bcast_indexed_tuning_table[i]));
            }
            MPL_free(table_ptrs);
            return 0;
        }
#endif
    return 0;
}

void MVP_cleanup_bcast_tuning_table()
{
        MPL_free(mvp_bcast_indexed_thresholds_table[0]);
        MPL_free(mvp_bcast_indexed_table_ppn_conf);
        MPL_free(mvp_size_bcast_indexed_tuning_table);
        if (mvp_bcast_indexed_thresholds_table != NULL) {
            MPL_free(mvp_bcast_indexed_thresholds_table);
        }
}
