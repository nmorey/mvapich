/* Copyright (c) 2001-2021, The Ohio State University. All rights
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
#include "reduce_tuning.h"
#include "reduce_arch_tuning.h"
#include "reduce_scatter_tuning.h"

int mvp_size_reduce_tuning_table = 0;
mvp_reduce_tuning_table *mvp_reduce_thresholds_table = NULL;

int *mvp_reduce_indexed_table_ppn_conf = NULL;
int mvp_reduce_indexed_num_ppn_conf = 1;
int *mvp_size_reduce_indexed_tuning_table = NULL;
mvp_reduce_indexed_tuning_table **mvp_reduce_indexed_thresholds_table = NULL;

static inline MVP_Reduce_fn_t MVP_get_inter_node_reduce_fn()
{
    int i, j;
    switch (MVP_REDUCE_INTER_NODE_TUNING_ALGO) {
        default:
            PRINT_ERROR("WARNING: Invalid value for "
                        "MVP_REDUCE_INTER_NODE_TUNING_ALGO.\n");
        case MVP_REDUCE_INTER_NODE_TUNING_ALGO_UNSET:
        case MVP_REDUCE_INTER_NODE_TUNING_ALGO_KNOMIAL:
            return &MPIR_Reduce_inter_knomial_wrapper_MVP;
        case MVP_REDUCE_INTER_NODE_TUNING_ALGO_BINOMIAL:
            return &MPIR_Reduce_binomial_MVP;
        case MVP_REDUCE_INTER_NODE_TUNING_ALGO_RED_SCAT_GATHER:
            return &MPIR_Reduce_redscat_gather_MVP;
        case MVP_REDUCE_INTER_NODE_TUNING_ALGO_ALLREDUCE:
            /* Do not allow reduce_scatter implementations that use reduce.
            This leads to an infinite recursion of
            reduce->allreduce->reduce_scatter->reduce->allreduce */
            for (i = 0; i < mvp_size_red_scat_tuning_table; i++) {
                mvp_red_scat_tuning_table *tbl =
                    &mvp_red_scat_thresholds_table[i];
                int size = tbl->size_inter_table;
                for (j = 0; j < size; j++) {
                    if (tbl->inter_leader[j].MVP_pt_Red_scat_function ==
                        &MPIR_Reduce_Scatter_Basic_MVP) {
                        PRINT_DEBUG(
                            DEBUG_SHM_verbose,
                            "Invalid algorithm for reduce_scatter "
                            "when forcing MVP_REDUCE_INTER_NODE_TUNING_ALGO to "
                            "ALLREDUCE.\n"
                            "Setting to "
                            "MPIR_Reduce_scatter_Rec_Halving_MVP\n");
                        tbl->inter_leader[j].MVP_pt_Red_scat_function =
                            &MPIR_Reduce_scatter_Rec_Halving_MVP;
                    }
                }
            }
            return &MPIR_Reduce_allreduce_MVP;
    }
}
static inline MVP_Reduce_fn_t MVP_get_intra_node_reduce_fn()
{
    switch (MVP_REDUCE_INTRA_NODE_TUNING_ALGO) {
        default:
            PRINT_ERROR("WARNING: Invalid value for "
                        "MVP_REDUCE_INTRA_NODE_TUNING_ALGO.\n");
        case MVP_REDUCE_INTRA_NODE_TUNING_ALGO_UNSET:
        case MVP_REDUCE_INTRA_NODE_TUNING_ALGO_BINOMIAL:
            return &MPIR_Reduce_binomial_MVP;
        case MVP_REDUCE_INTRA_NODE_TUNING_ALGO_KNOMIAL:
            return &MPIR_Reduce_intra_knomial_wrapper_MVP;
        case MVP_REDUCE_INTRA_NODE_TUNING_ALGO_SHMEM:
            return &MPIR_Reduce_shmem_MVP;
    }
}
static inline void MVP_set_user_defined_reduce_tuning_table()
{
    mvp_reduce_indexed_num_ppn_conf = 1;
    mvp_reduce_indexed_thresholds_table =
        MPL_malloc(mvp_reduce_indexed_num_ppn_conf *
                       sizeof(mvp_reduce_indexed_tuning_table *),
                   MPL_MEM_COLL);
    mvp_reduce_indexed_table_ppn_conf =
        MPL_malloc(mvp_reduce_indexed_num_ppn_conf * sizeof(int), MPL_MEM_COLL);
    mvp_size_reduce_indexed_tuning_table =
        MPL_malloc(mvp_reduce_indexed_num_ppn_conf * sizeof(int), MPL_MEM_COLL);

    /* -1 indicates user defined algorithm */
    mvp_reduce_indexed_table_ppn_conf[0] = -1;
    mvp_size_reduce_indexed_tuning_table[0] = 1;
    mvp_reduce_indexed_thresholds_table[0] =
        MPL_malloc(mvp_size_reduce_indexed_tuning_table[0] *
                       sizeof(mvp_reduce_indexed_tuning_table),
                   MPL_MEM_COLL);

    mvp_reduce_indexed_tuning_table tmp_table = {
        .numproc = 1,
        .inter_k_degree = 4,
        .intra_k_degree = 4,
        .size_inter_table = 1,
        .size_intra_table = 1,
        .is_two_level_reduce = MVP_REDUCE_TUNING_IS_TWO_LEVEL,
        .inter_leader[0] =
            {
                .msg_sz = 1,
                .reduce_fn = MVP_get_inter_node_reduce_fn(),
            },
        .intra_node[0] =
            {
                .msg_sz = 1,
                .reduce_fn = MVP_get_intra_node_reduce_fn(),
            },
    };

    MPIR_Memcpy(mvp_reduce_indexed_thresholds_table[0], &tmp_table,
                sizeof(mvp_reduce_indexed_tuning_table));
}

int MVP_set_reduce_tuning_table(int heterogeneity,
                                struct coll_info *colls_arch_hca)
{
    int agg_table_sum = 0;
    int i;
    mvp_reduce_indexed_tuning_table **table_ptrs = NULL;

    if (MVP_REDUCE_INTER_NODE_TUNING_ALGO_UNSET !=
            MVP_REDUCE_INTER_NODE_TUNING_ALGO ||
        MVP_REDUCE_INTRA_NODE_TUNING_ALGO_UNSET !=
            MVP_REDUCE_INTRA_NODE_TUNING_ALGO) {
        MVP_set_user_defined_reduce_tuning_table();
        return 0;
    }

#ifndef _MVP_CH4_OVERRIDE_
#if defined(CHANNEL_NEMESIS_IB)
    if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                             MVP_ARCH_INTEL_XEON_E5_2680_16,
                             MVP_HCA_MLX_CX_FDR) &&
        !heterogeneity) {
        /*Stampede Table*/
        mvp_reduce_indexed_num_ppn_conf = 3;
        mvp_reduce_indexed_thresholds_table =
            MPL_malloc(sizeof(mvp_reduce_indexed_tuning_table *) *
                           mvp_reduce_indexed_num_ppn_conf,
                       MPL_MEM_COLL);
        table_ptrs = MPL_malloc(sizeof(mvp_reduce_indexed_tuning_table *) *
                                    mvp_reduce_indexed_num_ppn_conf,
                                MPL_MEM_COLL);
        mvp_size_reduce_indexed_tuning_table = MPL_malloc(
            sizeof(int) * mvp_reduce_indexed_num_ppn_conf, MPL_MEM_COLL);
        mvp_reduce_indexed_table_ppn_conf = MPL_malloc(
            sizeof(int) * mvp_reduce_indexed_num_ppn_conf, MPL_MEM_COLL);

        mvp_reduce_indexed_table_ppn_conf[0] = 1;
        mvp_size_reduce_indexed_tuning_table[0] = 5;
        mvp_reduce_indexed_tuning_table
            mvp_tmp_reduce_indexed_thresholds_table_1ppn[] =
                NEMESIS__INTEL_XEON_E5_2680_16__MLX_CX_FDR__1PPN table_ptrs[0] =
                    mvp_tmp_reduce_indexed_thresholds_table_1ppn;

        mvp_reduce_indexed_table_ppn_conf[1] = 2;
        mvp_size_reduce_indexed_tuning_table[1] = 5;
        mvp_reduce_indexed_tuning_table
            mvp_tmp_reduce_indexed_thresholds_table_2ppn[] =
                NEMESIS__INTEL_XEON_E5_2680_16__MLX_CX_FDR__2PPN table_ptrs[1] =
                    mvp_tmp_reduce_indexed_thresholds_table_2ppn;

        mvp_reduce_indexed_table_ppn_conf[2] = 16;
        mvp_size_reduce_indexed_tuning_table[2] = 7;
        mvp_reduce_indexed_tuning_table
            mvp_tmp_reduce_indexed_thresholds_table_16ppn[] =
                NEMESIS__INTEL_XEON_E5_2680_16__MLX_CX_FDR__16PPN
                    table_ptrs[2] =
                        mvp_tmp_reduce_indexed_thresholds_table_16ppn;

        agg_table_sum = 0;
        for (i = 0; i < mvp_reduce_indexed_num_ppn_conf; i++) {
            agg_table_sum += mvp_size_reduce_indexed_tuning_table[i];
        }
        mvp_reduce_indexed_thresholds_table[0] =
            MPL_malloc(agg_table_sum * sizeof(mvp_reduce_indexed_tuning_table),
                       MPL_MEM_COLL);
        MPIR_Memcpy(mvp_reduce_indexed_thresholds_table[0], table_ptrs[0],
                    (sizeof(mvp_reduce_indexed_tuning_table) *
                     mvp_size_reduce_indexed_tuning_table[0]));
        for (i = 1; i < mvp_reduce_indexed_num_ppn_conf; i++) {
            mvp_reduce_indexed_thresholds_table[i] =
                mvp_reduce_indexed_thresholds_table[i - 1] +
                mvp_size_reduce_indexed_tuning_table[i - 1];
            MPIR_Memcpy(mvp_reduce_indexed_thresholds_table[i], table_ptrs[i],
                        (sizeof(mvp_reduce_indexed_tuning_table) *
                         mvp_size_reduce_indexed_tuning_table[i]));
        }
        MPL_free(table_ptrs);
        return 0;
    } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                    MVP_ARCH_INTEL_XEON_E5_2670_16,
                                    MVP_HCA_MLX_CX_QDR) &&
               !heterogeneity) {
        /*Gordon Table*/
        mvp_reduce_indexed_num_ppn_conf = 3;
        mvp_reduce_indexed_thresholds_table =
            MPL_malloc(sizeof(mvp_reduce_indexed_tuning_table *) *
                           mvp_reduce_indexed_num_ppn_conf,
                       MPL_MEM_COLL);
        table_ptrs = MPL_malloc(sizeof(mvp_reduce_indexed_tuning_table *) *
                                    mvp_reduce_indexed_num_ppn_conf,
                                MPL_MEM_COLL);
        mvp_size_reduce_indexed_tuning_table = MPL_malloc(
            sizeof(int) * mvp_reduce_indexed_num_ppn_conf, MPL_MEM_COLL);
        mvp_reduce_indexed_table_ppn_conf = MPL_malloc(
            sizeof(int) * mvp_reduce_indexed_num_ppn_conf, MPL_MEM_COLL);

        mvp_reduce_indexed_table_ppn_conf[0] = 1;
        mvp_size_reduce_indexed_tuning_table[0] = 2;
        mvp_reduce_indexed_tuning_table
            mvp_tmp_reduce_indexed_thresholds_table_1ppn[] =
                NEMESIS__INTEL_XEON_E5_2670_16__MLX_CX_QDR_1PPN table_ptrs[0] =
                    mvp_tmp_reduce_indexed_thresholds_table_1ppn;

        mvp_reduce_indexed_table_ppn_conf[1] = 2;
        mvp_size_reduce_indexed_tuning_table[1] = 2;
        mvp_reduce_indexed_tuning_table
            mvp_tmp_reduce_indexed_thresholds_table_2ppn[] =
                NEMESIS__INTEL_XEON_E5_2670_16__MLX_CX_QDR_2PPN table_ptrs[1] =
                    mvp_tmp_reduce_indexed_thresholds_table_2ppn;

        mvp_reduce_indexed_table_ppn_conf[2] = 16;
        mvp_size_reduce_indexed_tuning_table[2] = 4;
        mvp_reduce_indexed_tuning_table
            mvp_tmp_reduce_indexed_thresholds_table_16ppn[] =
                NEMESIS__INTEL_XEON_E5_2670_16__MLX_CX_QDR_16PPN table_ptrs[2] =
                    mvp_tmp_reduce_indexed_thresholds_table_16ppn;

        agg_table_sum = 0;
        for (i = 0; i < mvp_reduce_indexed_num_ppn_conf; i++) {
            agg_table_sum += mvp_size_reduce_indexed_tuning_table[i];
        }
        mvp_reduce_indexed_thresholds_table[0] =
            MPL_malloc(agg_table_sum * sizeof(mvp_reduce_indexed_tuning_table),
                       MPL_MEM_COLL);
        MPIR_Memcpy(mvp_reduce_indexed_thresholds_table[0], table_ptrs[0],
                    (sizeof(mvp_reduce_indexed_tuning_table) *
                     mvp_size_reduce_indexed_tuning_table[0]));
        for (i = 1; i < mvp_reduce_indexed_num_ppn_conf; i++) {
            mvp_reduce_indexed_thresholds_table[i] =
                mvp_reduce_indexed_thresholds_table[i - 1] +
                mvp_size_reduce_indexed_tuning_table[i - 1];
            MPIR_Memcpy(mvp_reduce_indexed_thresholds_table[i], table_ptrs[i],
                        (sizeof(mvp_reduce_indexed_tuning_table) *
                         mvp_size_reduce_indexed_tuning_table[i]));
        }
        MPL_free(table_ptrs);
        return 0;
    } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                    MVP_ARCH_INTEL_XEON_E5_2670_16,
                                    MVP_HCA_MLX_CX_FDR) &&
               !heterogeneity) {
        /*Yellowstone Table*/
        mvp_reduce_indexed_num_ppn_conf = 3;
        mvp_reduce_indexed_thresholds_table =
            MPL_malloc(sizeof(mvp_reduce_indexed_tuning_table *) *
                           mvp_reduce_indexed_num_ppn_conf,
                       MPL_MEM_COLL);
        table_ptrs = MPL_malloc(sizeof(mvp_reduce_indexed_tuning_table *) *
                                    mvp_reduce_indexed_num_ppn_conf,
                                MPL_MEM_COLL);
        mvp_size_reduce_indexed_tuning_table = MPL_malloc(
            sizeof(int) * mvp_reduce_indexed_num_ppn_conf, MPL_MEM_COLL);
        mvp_reduce_indexed_table_ppn_conf = MPL_malloc(
            sizeof(int) * mvp_reduce_indexed_num_ppn_conf, MPL_MEM_COLL);

        mvp_reduce_indexed_table_ppn_conf[0] = 1;
        mvp_size_reduce_indexed_tuning_table[0] = 2;
        mvp_reduce_indexed_tuning_table
            mvp_tmp_reduce_indexed_thresholds_table_1ppn[] =
                NEMESIS__INTEL_XEON_E5_2670_16__MLX_CX_FDR__1PPN table_ptrs[0] =
                    mvp_tmp_reduce_indexed_thresholds_table_1ppn;

        mvp_reduce_indexed_table_ppn_conf[1] = 2;
        mvp_size_reduce_indexed_tuning_table[1] = 2;
        mvp_reduce_indexed_tuning_table
            mvp_tmp_reduce_indexed_thresholds_table_2ppn[] =
                NEMESIS__INTEL_XEON_E5_2670_16__MLX_CX_FDR__2PPN table_ptrs[1] =
                    mvp_tmp_reduce_indexed_thresholds_table_2ppn;

        mvp_reduce_indexed_table_ppn_conf[2] = 16;
        mvp_size_reduce_indexed_tuning_table[2] = 3;
        mvp_reduce_indexed_tuning_table
            mvp_tmp_reduce_indexed_thresholds_table_16ppn[] =
                NEMESIS__INTEL_XEON_E5_2670_16__MLX_CX_FDR__16PPN
                    table_ptrs[2] =
                        mvp_tmp_reduce_indexed_thresholds_table_16ppn;

        agg_table_sum = 0;
        for (i = 0; i < mvp_reduce_indexed_num_ppn_conf; i++) {
            agg_table_sum += mvp_size_reduce_indexed_tuning_table[i];
        }
        mvp_reduce_indexed_thresholds_table[0] =
            MPL_malloc(agg_table_sum * sizeof(mvp_reduce_indexed_tuning_table),
                       MPL_MEM_COLL);
        MPIR_Memcpy(mvp_reduce_indexed_thresholds_table[0], table_ptrs[0],
                    (sizeof(mvp_reduce_indexed_tuning_table) *
                     mvp_size_reduce_indexed_tuning_table[0]));
        for (i = 1; i < mvp_reduce_indexed_num_ppn_conf; i++) {
            mvp_reduce_indexed_thresholds_table[i] =
                mvp_reduce_indexed_thresholds_table[i - 1] +
                mvp_size_reduce_indexed_tuning_table[i - 1];
            MPIR_Memcpy(mvp_reduce_indexed_thresholds_table[i], table_ptrs[i],
                        (sizeof(mvp_reduce_indexed_tuning_table) *
                         mvp_size_reduce_indexed_tuning_table[i]));
        }
        MPL_free(table_ptrs);
        return 0;
    } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                    MVP_ARCH_AMD_OPTERON_6136_32,
                                    MVP_HCA_MLX_CX_QDR) &&
               !heterogeneity) {
        /*Trestles Table*/
        mvp_reduce_indexed_num_ppn_conf = 3;
        mvp_reduce_indexed_thresholds_table =
            MPL_malloc(sizeof(mvp_reduce_indexed_tuning_table *) *
                           mvp_reduce_indexed_num_ppn_conf,
                       MPL_MEM_COLL);
        table_ptrs = MPL_malloc(sizeof(mvp_reduce_indexed_tuning_table *) *
                                    mvp_reduce_indexed_num_ppn_conf,
                                MPL_MEM_COLL);
        mvp_size_reduce_indexed_tuning_table = MPL_malloc(
            sizeof(int) * mvp_reduce_indexed_num_ppn_conf, MPL_MEM_COLL);
        mvp_reduce_indexed_table_ppn_conf = MPL_malloc(
            sizeof(int) * mvp_reduce_indexed_num_ppn_conf, MPL_MEM_COLL);

        mvp_reduce_indexed_table_ppn_conf[0] = 1;
        mvp_size_reduce_indexed_tuning_table[0] = 4;
        mvp_reduce_indexed_tuning_table
            mvp_tmp_reduce_indexed_thresholds_table_1ppn[] =
                NEMESIS__AMD_OPTERON_6136_32__MLX_CX_QDR__1PPN table_ptrs[0] =
                    mvp_tmp_reduce_indexed_thresholds_table_1ppn;

        mvp_reduce_indexed_table_ppn_conf[1] = 2;
        mvp_size_reduce_indexed_tuning_table[1] = 3;
        mvp_reduce_indexed_tuning_table
            mvp_tmp_reduce_indexed_thresholds_table_2ppn[] =
                NEMESIS__AMD_OPTERON_6136_32__MLX_CX_QDR__2PPN table_ptrs[1] =
                    mvp_tmp_reduce_indexed_thresholds_table_2ppn;

        mvp_reduce_indexed_table_ppn_conf[2] = 32;
        mvp_size_reduce_indexed_tuning_table[2] = 2;
        mvp_reduce_indexed_tuning_table
            mvp_tmp_reduce_indexed_thresholds_table_32ppn[] =
                NEMESIS__AMD_OPTERON_6136_32__MLX_CX_QDR__32PPN table_ptrs[2] =
                    mvp_tmp_reduce_indexed_thresholds_table_32ppn;

        agg_table_sum = 0;
        for (i = 0; i < mvp_reduce_indexed_num_ppn_conf; i++) {
            agg_table_sum += mvp_size_reduce_indexed_tuning_table[i];
        }
        mvp_reduce_indexed_thresholds_table[0] =
            MPL_malloc(agg_table_sum * sizeof(mvp_reduce_indexed_tuning_table),
                       MPL_MEM_COLL);
        MPIR_Memcpy(mvp_reduce_indexed_thresholds_table[0], table_ptrs[0],
                    (sizeof(mvp_reduce_indexed_tuning_table) *
                     mvp_size_reduce_indexed_tuning_table[0]));
        for (i = 1; i < mvp_reduce_indexed_num_ppn_conf; i++) {
            mvp_reduce_indexed_thresholds_table[i] =
                mvp_reduce_indexed_thresholds_table[i - 1] +
                mvp_size_reduce_indexed_tuning_table[i - 1];
            MPIR_Memcpy(mvp_reduce_indexed_thresholds_table[i], table_ptrs[i],
                        (sizeof(mvp_reduce_indexed_tuning_table) *
                         mvp_size_reduce_indexed_tuning_table[i]));
        }
        MPL_free(table_ptrs);
        return 0;
    } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                    MVP_ARCH_INTEL_XEON_E5630_8,
                                    MVP_HCA_MLX_CX_QDR) &&
               !heterogeneity) {
        /*RI Table*/
        mvp_reduce_indexed_num_ppn_conf = 3;
        mvp_reduce_indexed_thresholds_table =
            MPL_malloc(sizeof(mvp_reduce_indexed_tuning_table *) *
                           mvp_reduce_indexed_num_ppn_conf,
                       MPL_MEM_COLL);
        table_ptrs = MPL_malloc(sizeof(mvp_reduce_indexed_tuning_table *) *
                                    mvp_reduce_indexed_num_ppn_conf,
                                MPL_MEM_COLL);
        mvp_size_reduce_indexed_tuning_table = MPL_malloc(
            sizeof(int) * mvp_reduce_indexed_num_ppn_conf, MPL_MEM_COLL);
        mvp_reduce_indexed_table_ppn_conf = MPL_malloc(
            sizeof(int) * mvp_reduce_indexed_num_ppn_conf, MPL_MEM_COLL);

        mvp_reduce_indexed_table_ppn_conf[0] = 1;
        mvp_size_reduce_indexed_tuning_table[0] = 2;
        mvp_reduce_indexed_tuning_table
            mvp_tmp_reduce_indexed_thresholds_table_1ppn[] =
                NEMESIS__RI__1PPN table_ptrs[0] =
                    mvp_tmp_reduce_indexed_thresholds_table_1ppn;

        mvp_reduce_indexed_table_ppn_conf[1] = 2;
        mvp_size_reduce_indexed_tuning_table[1] = 2;
        mvp_reduce_indexed_tuning_table
            mvp_tmp_reduce_indexed_thresholds_table_2ppn[] =
                NEMESIS__RI__2PPN table_ptrs[1] =
                    mvp_tmp_reduce_indexed_thresholds_table_2ppn;

        mvp_reduce_indexed_table_ppn_conf[2] = 8;
        mvp_size_reduce_indexed_tuning_table[2] = 8;
        mvp_reduce_indexed_tuning_table
            mvp_tmp_reduce_indexed_thresholds_table_8ppn[] =
                NEMESIS__RI__8PPN table_ptrs[2] =
                    mvp_tmp_reduce_indexed_thresholds_table_8ppn;

        agg_table_sum = 0;
        for (i = 0; i < mvp_reduce_indexed_num_ppn_conf; i++) {
            agg_table_sum += mvp_size_reduce_indexed_tuning_table[i];
        }
        mvp_reduce_indexed_thresholds_table[0] =
            MPL_malloc(agg_table_sum * sizeof(mvp_reduce_indexed_tuning_table),
                       MPL_MEM_COLL);
        MPIR_Memcpy(mvp_reduce_indexed_thresholds_table[0], table_ptrs[0],
                    (sizeof(mvp_reduce_indexed_tuning_table) *
                     mvp_size_reduce_indexed_tuning_table[0]));
        for (i = 1; i < mvp_reduce_indexed_num_ppn_conf; i++) {
            mvp_reduce_indexed_thresholds_table[i] =
                mvp_reduce_indexed_thresholds_table[i - 1] +
                mvp_size_reduce_indexed_tuning_table[i - 1];
            MPIR_Memcpy(mvp_reduce_indexed_thresholds_table[i], table_ptrs[i],
                        (sizeof(mvp_reduce_indexed_tuning_table) *
                         mvp_size_reduce_indexed_tuning_table[i]));
        }
        MPL_free(table_ptrs);
        return 0;
    } else {
        /*Stampede Table*/
        mvp_reduce_indexed_num_ppn_conf = 3;
        mvp_reduce_indexed_thresholds_table =
            MPL_malloc(sizeof(mvp_reduce_indexed_tuning_table *) *
                           mvp_reduce_indexed_num_ppn_conf,
                       MPL_MEM_COLL);
        table_ptrs = MPL_malloc(sizeof(mvp_reduce_indexed_tuning_table *) *
                                    mvp_reduce_indexed_num_ppn_conf,
                                MPL_MEM_COLL);
        mvp_size_reduce_indexed_tuning_table = MPL_malloc(
            sizeof(int) * mvp_reduce_indexed_num_ppn_conf, MPL_MEM_COLL);
        mvp_reduce_indexed_table_ppn_conf = MPL_malloc(
            sizeof(int) * mvp_reduce_indexed_num_ppn_conf, MPL_MEM_COLL);

        mvp_reduce_indexed_table_ppn_conf[0] = 1;
        mvp_reduce_indexed_tuning_table
            mvp_tmp_reduce_indexed_thresholds_table_1ppn[] =
                GEN2__INTEL_XEON_E5_2680_16__MLX_CX_FDR__1PPN;
        mvp_reduce_indexed_tuning_table
            mvp_tmp_cma_reduce_indexed_thresholds_table_1ppn[] =
                GEN2_CMA__INTEL_XEON_E5_2680_16__MLX_CX_FDR__1PPN;
#if defined(_SMP_CMA_)
            if (MVP_SMP_USE_CMA) {
                mvp_size_reduce_indexed_tuning_table[0] = 5;
                table_ptrs[0] =
                    mvp_tmp_cma_reduce_indexed_thresholds_table_1ppn;
            } else {
                mvp_size_reduce_indexed_tuning_table[0] = 5;
                table_ptrs[0] = mvp_tmp_reduce_indexed_thresholds_table_1ppn;
            }
#else
            mvp_size_reduce_indexed_tuning_table[0] = 5;
            table_ptrs[0] = mvp_tmp_reduce_indexed_thresholds_table_1ppn;
#endif

            mvp_reduce_indexed_table_ppn_conf[1] = 2;
            mvp_reduce_indexed_tuning_table
                mvp_tmp_reduce_indexed_thresholds_table_2ppn[] =
                    GEN2__INTEL_XEON_E5_2680_16__MLX_CX_FDR__2PPN;
            mvp_reduce_indexed_tuning_table
                mvp_tmp_cma_reduce_indexed_thresholds_table_2ppn[] =
                    GEN2_CMA__INTEL_XEON_E5_2680_16__MLX_CX_FDR__2PPN;
#if defined(_SMP_CMA_)
            if (MVP_SMP_USE_CMA) {
                mvp_size_reduce_indexed_tuning_table[1] = 6;
                table_ptrs[1] =
                    mvp_tmp_cma_reduce_indexed_thresholds_table_2ppn;
            } else {
                mvp_size_reduce_indexed_tuning_table[1] = 6;
                table_ptrs[1] = mvp_tmp_reduce_indexed_thresholds_table_2ppn;
            }
#else
            mvp_size_reduce_indexed_tuning_table[1] = 6;
            table_ptrs[1] = mvp_tmp_reduce_indexed_thresholds_table_2ppn;
#endif

            mvp_reduce_indexed_table_ppn_conf[2] = 16;
            mvp_reduce_indexed_tuning_table
                mvp_tmp_cma_reduce_indexed_thresholds_table_16ppn[] =
                    GEN2_CMA__INTEL_XEON_E5_2680_16__MLX_CX_FDR__16PPN;
            mvp_reduce_indexed_tuning_table
                mvp_tmp_reduce_indexed_thresholds_table_16ppn[] =
                    GEN2__INTEL_XEON_E5_2680_16__MLX_CX_FDR__16PPN;
#if defined(_SMP_CMA_)
            if (MVP_SMP_USE_CMA) {
                mvp_size_reduce_indexed_tuning_table[2] = 6;
                table_ptrs[2] =
                    mvp_tmp_cma_reduce_indexed_thresholds_table_16ppn;
            } else {
                mvp_size_reduce_indexed_tuning_table[2] = 6;
                table_ptrs[2] = mvp_tmp_reduce_indexed_thresholds_table_16ppn;
            }
#else
            mvp_size_reduce_indexed_tuning_table[2] = 6;
            table_ptrs[2] = mvp_tmp_reduce_indexed_thresholds_table_16ppn;
#endif

            agg_table_sum = 0;
            for (i = 0; i < mvp_reduce_indexed_num_ppn_conf; i++) {
                agg_table_sum += mvp_size_reduce_indexed_tuning_table[i];
            }
            mvp_reduce_indexed_thresholds_table[0] = MPL_malloc(
                agg_table_sum * sizeof(mvp_reduce_indexed_tuning_table),
                MPL_MEM_COLL);
            MPIR_Memcpy(mvp_reduce_indexed_thresholds_table[0], table_ptrs[0],
                        (sizeof(mvp_reduce_indexed_tuning_table) *
                         mvp_size_reduce_indexed_tuning_table[0]));
            for (i = 1; i < mvp_reduce_indexed_num_ppn_conf; i++) {
                mvp_reduce_indexed_thresholds_table[i] =
                    mvp_reduce_indexed_thresholds_table[i - 1] +
                    mvp_size_reduce_indexed_tuning_table[i - 1];
                MPIR_Memcpy(mvp_reduce_indexed_thresholds_table[i],
                            table_ptrs[i],
                            (sizeof(mvp_reduce_indexed_tuning_table) *
                             mvp_size_reduce_indexed_tuning_table[i]));
            }
            MPL_free(table_ptrs);
            return 0;
    }
#endif
#else  /* !_MVP_CH4_OVERRIDE_ */
        if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                 MVP_ARCH_INTEL_XEON_X5650_12,
                                 MVP_HCA_QLGIC_QIB) &&
            !heterogeneity) {
            /*Sierra Table*/
            mvp_reduce_indexed_num_ppn_conf = 2;
            mvp_reduce_indexed_thresholds_table =
                MPL_malloc(sizeof(mvp_reduce_indexed_tuning_table *) *
                               mvp_reduce_indexed_num_ppn_conf,
                           MPL_MEM_COLL);
            table_ptrs = MPL_malloc(sizeof(mvp_reduce_indexed_tuning_table *) *
                                        mvp_reduce_indexed_num_ppn_conf,
                                    MPL_MEM_COLL);
            mvp_size_reduce_indexed_tuning_table = MPL_malloc(
                sizeof(int) * mvp_reduce_indexed_num_ppn_conf, MPL_MEM_COLL);
            mvp_reduce_indexed_table_ppn_conf = MPL_malloc(
                sizeof(int) * mvp_reduce_indexed_num_ppn_conf, MPL_MEM_COLL);

            mvp_reduce_indexed_table_ppn_conf[0] = 1;
            mvp_size_reduce_indexed_tuning_table[0] = 5;
            mvp_reduce_indexed_tuning_table
                mvp_tmp_reduce_indexed_thresholds_table_1ppn[] =
                    PSM__INTEL_XEON_X5650_12__MVP_HCA_QLGIC_QIB__1PPN;
            table_ptrs[0] = mvp_tmp_reduce_indexed_thresholds_table_1ppn;

            mvp_reduce_indexed_table_ppn_conf[1] = 12;
            mvp_size_reduce_indexed_tuning_table[1] = 6;
            mvp_reduce_indexed_tuning_table
                mvp_tmp_reduce_indexed_thresholds_table_12ppn[] =
                    PSM__INTEL_XEON_X5650_12__MVP_HCA_QLGIC_QIB__12PPN;
            table_ptrs[1] = mvp_tmp_reduce_indexed_thresholds_table_12ppn;

            agg_table_sum = 0;
            for (i = 0; i < mvp_reduce_indexed_num_ppn_conf; i++) {
                agg_table_sum += mvp_size_reduce_indexed_tuning_table[i];
            }
            mvp_reduce_indexed_thresholds_table[0] = MPL_malloc(
                agg_table_sum * sizeof(mvp_reduce_indexed_tuning_table),
                MPL_MEM_COLL);
            MPIR_Memcpy(mvp_reduce_indexed_thresholds_table[0], table_ptrs[0],
                        (sizeof(mvp_reduce_indexed_tuning_table) *
                         mvp_size_reduce_indexed_tuning_table[0]));
            for (i = 1; i < mvp_reduce_indexed_num_ppn_conf; i++) {
                mvp_reduce_indexed_thresholds_table[i] =
                    mvp_reduce_indexed_thresholds_table[i - 1] +
                    mvp_size_reduce_indexed_tuning_table[i - 1];
                MPIR_Memcpy(mvp_reduce_indexed_thresholds_table[i],
                            table_ptrs[i],
                            (sizeof(mvp_reduce_indexed_tuning_table) *
                             mvp_size_reduce_indexed_tuning_table[i]));
            }
            MPL_free(table_ptrs);
            return 0;
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_INTEL_XEON_E5_2695_V3_2S_28,
                                        MVP_HCA_INTEL_HFI1) &&
                   !heterogeneity) {
            /*Bridges Table*/
            MVP_COLL_TUNING_START_TABLE(reduce, 6)
            MVP_COLL_TUNING_ADD_CONF(
                reduce, 1, 4,
                PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__1PPN)
            MVP_COLL_TUNING_ADD_CONF(
                reduce, 2, 5,
                PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__2PPN)
            MVP_COLL_TUNING_ADD_CONF(
                reduce, 4, 5,
                PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__4PPN)
            MVP_COLL_TUNING_ADD_CONF(
                reduce, 8, 5,
                PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__8PPN)
            MVP_COLL_TUNING_ADD_CONF(
                reduce, 16, 5,
                PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__16PPN)
            MVP_COLL_TUNING_ADD_CONF(
                reduce, 28, 5,
                PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__28PPN)
            MVP_COLL_TUNING_FINISH_TABLE(reduce)
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_INTEL_XEON_E5_2695_V4_2S_36,
                                        MVP_HCA_INTEL_HFI1) &&
                   !heterogeneity) {
            /* Bebop/Jade/Opal Table */
            MVP_COLL_TUNING_START_TABLE(reduce, 5)
            MVP_COLL_TUNING_ADD_CONF(
                reduce, 1, 5,
                PSM__INTEL_XEON_E5_2695_V4_2S_36_INTEL_HFI_100__1PPN)
            MVP_COLL_TUNING_ADD_CONF(
                reduce, 4, 5,
                PSM__INTEL_XEON_E5_2695_V4_2S_36_INTEL_HFI_100__4PPN)
            MVP_COLL_TUNING_ADD_CONF(
                reduce, 8, 5,
                PSM__INTEL_XEON_E5_2695_V4_2S_36_INTEL_HFI_100__8PPN)
            MVP_COLL_TUNING_ADD_CONF(
                reduce, 16, 5,
                PSM__INTEL_XEON_E5_2695_V4_2S_36_INTEL_HFI_100__16PPN)
            MVP_COLL_TUNING_ADD_CONF(
                reduce, 36, 5,
                PSM__INTEL_XEON_E5_2695_V4_2S_36_INTEL_HFI_100__36PPN)
            MVP_COLL_TUNING_FINISH_TABLE(reduce)
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_INTEL_XEON_PHI_7250,
                                        MVP_HCA_INTEL_HFI1) &&
                   !heterogeneity) {
            /* TACC-KNL Table */
            MVP_COLL_TUNING_START_TABLE(reduce, 6)
            MVP_COLL_TUNING_ADD_CONF(
                reduce, 1, 5, PSM__INTEL_XEON_PHI_7250_68_INTEL_HFI_100__1PPN)
            MVP_COLL_TUNING_ADD_CONF(
                reduce, 4, 6, PSM__INTEL_XEON_PHI_7250_68_INTEL_HFI_100__4PPN)
            MVP_COLL_TUNING_ADD_CONF(
                reduce, 8, 5, PSM__INTEL_XEON_PHI_7250_68_INTEL_HFI_100__8PPN)
            MVP_COLL_TUNING_ADD_CONF(
                reduce, 16, 5, PSM__INTEL_XEON_PHI_7250_68_INTEL_HFI_100__16PPN)
            MVP_COLL_TUNING_ADD_CONF(
                reduce, 32, 5, PSM__INTEL_XEON_PHI_7250_68_INTEL_HFI_100__32PPN)
            MVP_COLL_TUNING_ADD_CONF(
                reduce, 64, 4, PSM__INTEL_XEON_PHI_7250_68_INTEL_HFI_100__64PPN)
            MVP_COLL_TUNING_FINISH_TABLE(reduce)
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_INTEL_PLATINUM_8170_2S_52,
                                        MVP_HCA_INTEL_HFI1) &&
                   !heterogeneity) {
            /* Diamond-Skylake Table */
            MVP_COLL_TUNING_START_TABLE(reduce, 8)
            MVP_COLL_TUNING_ADD_CONF(
                reduce, 1, 3,
                PSM__INTEL_PLATINUM_8170_2S_52_INTEL_HFI_100__1PPN)
            MVP_COLL_TUNING_ADD_CONF(
                reduce, 2, 4,
                PSM__INTEL_PLATINUM_8170_2S_52_INTEL_HFI_100__2PPN)
            MVP_COLL_TUNING_ADD_CONF(
                reduce, 4, 4,
                PSM__INTEL_PLATINUM_8170_2S_52_INTEL_HFI_100__4PPN)
            MVP_COLL_TUNING_ADD_CONF(
                reduce, 8, 4,
                PSM__INTEL_PLATINUM_8170_2S_52_INTEL_HFI_100__8PPN)
            MVP_COLL_TUNING_ADD_CONF(
                reduce, 16, 4,
                PSM__INTEL_PLATINUM_8170_2S_52_INTEL_HFI_100__16PPN)
            MVP_COLL_TUNING_ADD_CONF(
                reduce, 26, 4,
                PSM__INTEL_PLATINUM_8170_2S_52_INTEL_HFI_100__26PPN)
            MVP_COLL_TUNING_ADD_CONF(
                reduce, 48, 5,
                PSM__INTEL_PLATINUM_8160_2S_48_INTEL_HFI_100__48PPN)
            MVP_COLL_TUNING_ADD_CONF(
                reduce, 52, 4,
                PSM__INTEL_PLATINUM_8170_2S_52_INTEL_HFI_100__52PPN)
            MVP_COLL_TUNING_FINISH_TABLE(reduce)
        } else {
            /*default psm table: Bridges Table*/
            MVP_COLL_TUNING_START_TABLE(reduce, 6)
            MVP_COLL_TUNING_ADD_CONF(
                reduce, 1, 4,
                PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__1PPN)
            MVP_COLL_TUNING_ADD_CONF(
                reduce, 2, 5,
                PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__2PPN)
            MVP_COLL_TUNING_ADD_CONF(
                reduce, 4, 5,
                PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__4PPN)
            MVP_COLL_TUNING_ADD_CONF(
                reduce, 8, 5,
                PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__8PPN)
            MVP_COLL_TUNING_ADD_CONF(
                reduce, 16, 5,
                PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__16PPN)
            MVP_COLL_TUNING_ADD_CONF(
                reduce, 28, 5,
                PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__28PPN)
            MVP_COLL_TUNING_FINISH_TABLE(reduce)
        }
#endif /* !_MVP_CH4_OVERRIDE_ */
        {
            /*Stampede Table*/
            mvp_reduce_indexed_num_ppn_conf = 3;
            mvp_reduce_indexed_thresholds_table =
                MPL_malloc(sizeof(mvp_reduce_indexed_tuning_table *) *
                               mvp_reduce_indexed_num_ppn_conf,
                           MPL_MEM_COMM);
            table_ptrs = MPL_malloc(sizeof(mvp_reduce_indexed_tuning_table *) *
                                        mvp_reduce_indexed_num_ppn_conf,
                                    MPL_MEM_COMM);
            mvp_size_reduce_indexed_tuning_table = MPL_malloc(
                sizeof(int) * mvp_reduce_indexed_num_ppn_conf, MPL_MEM_COMM);
            mvp_reduce_indexed_table_ppn_conf = MPL_malloc(
                sizeof(int) * mvp_reduce_indexed_num_ppn_conf, MPL_MEM_COMM);

            mvp_reduce_indexed_table_ppn_conf[0] = 1;
            mvp_reduce_indexed_tuning_table
                mvp_tmp_reduce_indexed_thresholds_table_1ppn[] =
                    GEN2__INTEL_XEON_E5_2680_16__MLX_CX_FDR__1PPN;
#if defined(_SMP_CMA_)
            mvp_reduce_indexed_tuning_table
                mvp_tmp_cma_reduce_indexed_thresholds_table_1ppn[] =
                    GEN2_CMA__INTEL_XEON_E5_2680_16__MLX_CX_FDR__1PPN;
            if (MVP_SMP_USE_CMA) {
                mvp_size_reduce_indexed_tuning_table[0] = 5;
                table_ptrs[0] =
                    mvp_tmp_cma_reduce_indexed_thresholds_table_1ppn;
            } else {
                mvp_size_reduce_indexed_tuning_table[0] = 5;
                table_ptrs[0] = mvp_tmp_reduce_indexed_thresholds_table_1ppn;
            }
#else
            mvp_size_reduce_indexed_tuning_table[0] = 5;
            table_ptrs[0] = mvp_tmp_reduce_indexed_thresholds_table_1ppn;
#endif

            mvp_reduce_indexed_table_ppn_conf[1] = 2;
            mvp_reduce_indexed_tuning_table
                mvp_tmp_reduce_indexed_thresholds_table_2ppn[] =
                    GEN2__INTEL_XEON_E5_2680_16__MLX_CX_FDR__2PPN;
#if defined(_SMP_CMA_)
            mvp_reduce_indexed_tuning_table
                mvp_tmp_cma_reduce_indexed_thresholds_table_2ppn[] =
                    GEN2_CMA__INTEL_XEON_E5_2680_16__MLX_CX_FDR__2PPN;
            if (MVP_SMP_USE_CMA) {
                mvp_size_reduce_indexed_tuning_table[1] = 6;
                table_ptrs[1] =
                    mvp_tmp_cma_reduce_indexed_thresholds_table_2ppn;
            } else {
                mvp_size_reduce_indexed_tuning_table[1] = 6;
                table_ptrs[1] = mvp_tmp_reduce_indexed_thresholds_table_2ppn;
            }
#else
            mvp_size_reduce_indexed_tuning_table[1] = 6;
            table_ptrs[1] = mvp_tmp_reduce_indexed_thresholds_table_2ppn;
#endif

            mvp_reduce_indexed_table_ppn_conf[2] = 16;
#if defined(_SMP_CMA_)
            mvp_reduce_indexed_tuning_table
                mvp_tmp_cma_reduce_indexed_thresholds_table_16ppn[] =
                    GEN2_CMA__INTEL_XEON_E5_2680_16__MLX_CX_FDR__16PPN;
#endif
            mvp_reduce_indexed_tuning_table
                mvp_tmp_reduce_indexed_thresholds_table_16ppn[] =
                    GEN2__INTEL_XEON_E5_2680_16__MLX_CX_FDR__16PPN;
#if defined(_SMP_CMA_)
            if (MVP_SMP_USE_CMA) {
                mvp_size_reduce_indexed_tuning_table[2] = 6;
                table_ptrs[2] =
                    mvp_tmp_cma_reduce_indexed_thresholds_table_16ppn;
            } else {
                mvp_size_reduce_indexed_tuning_table[2] = 6;
                table_ptrs[2] = mvp_tmp_reduce_indexed_thresholds_table_16ppn;
            }
#else
            mvp_size_reduce_indexed_tuning_table[2] = 6;
            table_ptrs[2] = mvp_tmp_reduce_indexed_thresholds_table_16ppn;
#endif

            agg_table_sum = 0;
            for (i = 0; i < mvp_reduce_indexed_num_ppn_conf; i++) {
                agg_table_sum += mvp_size_reduce_indexed_tuning_table[i];
            }
            mvp_reduce_indexed_thresholds_table[0] = MPL_malloc(
                agg_table_sum * sizeof(mvp_reduce_indexed_tuning_table),
                MPL_MEM_COLL);
            MPIR_Memcpy(mvp_reduce_indexed_thresholds_table[0], table_ptrs[0],
                        (sizeof(mvp_reduce_indexed_tuning_table) *
                         mvp_size_reduce_indexed_tuning_table[0]));
            for (i = 1; i < mvp_reduce_indexed_num_ppn_conf; i++) {
                mvp_reduce_indexed_thresholds_table[i] =
                    mvp_reduce_indexed_thresholds_table[i - 1] +
                    mvp_size_reduce_indexed_tuning_table[i - 1];
                MPIR_Memcpy(mvp_reduce_indexed_thresholds_table[i],
                            table_ptrs[i],
                            (sizeof(mvp_reduce_indexed_tuning_table) *
                             mvp_size_reduce_indexed_tuning_table[i]));
            }
            MPL_free(table_ptrs);
            return 0;
        }
        return 0;
}

void MVP_cleanup_reduce_tuning_table()
{
    MPL_free(mvp_reduce_indexed_thresholds_table[0]);
    MPL_free(mvp_reduce_indexed_table_ppn_conf);
    MPL_free(mvp_size_reduce_indexed_tuning_table);
    if (mvp_reduce_indexed_thresholds_table != NULL) {
        MPL_free(mvp_reduce_indexed_thresholds_table);
    }
}
