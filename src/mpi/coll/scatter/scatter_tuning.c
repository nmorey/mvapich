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
#include "scatter_tuning.h"
#include "scatter_arch_tuning.h"

/* TODO: This should be moved to the pre-header as it is in ch4 */
#ifdef CHANNEL_MRAIL
#include "mvp_arch_hca_detect.h"
#endif

int *mvp_scatter_table_ppn_conf = NULL;
int mvp_scatter_num_ppn_conf = 1;
int *mvp_size_scatter_tuning_table = NULL;
mvp_scatter_tuning_table **mvp_scatter_thresholds_table = NULL;

int *mvp_scatter_indexed_table_ppn_conf = NULL;
int mvp_scatter_indexed_num_ppn_conf = 1;
int *mvp_size_scatter_indexed_tuning_table = NULL;
mvp_scatter_indexed_tuning_table **mvp_scatter_indexed_thresholds_table = NULL;

int MVP_set_scatter_tuning_table(int heterogeneity,
                                 struct coll_info *colls_arch_hca)
{
    int agg_table_sum = 0;
    int i;

        mvp_scatter_indexed_tuning_table **table_ptrs = NULL;
#ifndef _MVP_CH4_OVERRIDE_
#ifdef CHANNEL_MRAIL_GEN2
        if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                 MVP_ARCH_INTEL_XEON_X5650_12,
                                 MVP_HCA_MLX_CX_QDR) &&
            !heterogeneity) {
            /* Lonestar Table*/
            mvp_scatter_indexed_num_ppn_conf = 3;
            mvp_scatter_indexed_thresholds_table =
                MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                               mvp_scatter_indexed_num_ppn_conf,
                           MPL_MEM_COLL);
            table_ptrs = MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                                        mvp_scatter_indexed_num_ppn_conf,
                                    MPL_MEM_COLL);
            mvp_size_scatter_indexed_tuning_table = MPL_malloc(
                sizeof(int) * mvp_scatter_indexed_num_ppn_conf, MPL_MEM_COLL);
            mvp_scatter_indexed_table_ppn_conf = MPL_malloc(
                mvp_scatter_indexed_num_ppn_conf * sizeof(int), MPL_MEM_COLL);

            mvp_scatter_indexed_table_ppn_conf[0] = 1;
            mvp_size_scatter_indexed_tuning_table[0] = 4;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_1ppn[] =
                    GEN2__INTEL_XEON_X5650_12__MLX_CX_QDR__1PPN table_ptrs[0] =
                        mvp_tmp_scatter_indexed_thresholds_table_1ppn;

            mvp_scatter_indexed_table_ppn_conf[1] = 2;
            mvp_size_scatter_indexed_tuning_table[1] = 3;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_2ppn[] =
                    GEN2__INTEL_XEON_X5650_12__MLX_CX_QDR__2PPN table_ptrs[1] =
                        mvp_tmp_scatter_indexed_thresholds_table_2ppn;

            mvp_scatter_indexed_table_ppn_conf[2] = 12;
            mvp_size_scatter_indexed_tuning_table[2] = 6;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_12ppn[] =
                    GEN2__INTEL_XEON_X5650_12__MLX_CX_QDR__12PPN table_ptrs[2] =
                        mvp_tmp_scatter_indexed_thresholds_table_12ppn;

            agg_table_sum = 0;
            for (i = 0; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                agg_table_sum += mvp_size_scatter_indexed_tuning_table[i];
            }
            mvp_scatter_indexed_thresholds_table[0] = MPL_malloc(
                agg_table_sum * sizeof(mvp_scatter_indexed_tuning_table),
                MPL_MEM_COLL);
            MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[0], table_ptrs[0],
                        (sizeof(mvp_scatter_indexed_tuning_table) *
                         mvp_size_scatter_indexed_tuning_table[0]));
            for (i = 1; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                mvp_scatter_indexed_thresholds_table[i] =
                    mvp_scatter_indexed_thresholds_table[i - 1] +
                    mvp_size_scatter_indexed_tuning_table[i - 1];
                MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[i],
                            table_ptrs[i],
                            (sizeof(mvp_scatter_indexed_tuning_table) *
                             mvp_size_scatter_indexed_tuning_table[i]));
            }
            MPL_free(table_ptrs);
            return 0;
        }
        if ((MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                  MVP_ARCH_INTEL_XEON_E5_2690_V2_2S_20,
                                  MVP_HCA_MLX_CX_CONNIB) ||
             MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                  MVP_ARCH_INTEL_XEON_E5_2680_V2_2S_20,
                                  MVP_HCA_MLX_CX_CONNIB)) &&
            !heterogeneity) {
            /* PSG Table*/
            mvp_scatter_indexed_num_ppn_conf = 3;
            mvp_scatter_indexed_thresholds_table =
                MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                               mvp_scatter_indexed_num_ppn_conf,
                           MPL_MEM_COLL);
            table_ptrs = MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                                        mvp_scatter_indexed_num_ppn_conf,
                                    MPL_MEM_COLL);
            mvp_size_scatter_indexed_tuning_table = MPL_malloc(
                sizeof(int) * mvp_scatter_indexed_num_ppn_conf, MPL_MEM_COLL);
            mvp_scatter_indexed_table_ppn_conf = MPL_malloc(
                mvp_scatter_indexed_num_ppn_conf * sizeof(int), MPL_MEM_COLL);

            mvp_scatter_indexed_table_ppn_conf[0] = 1;
            mvp_size_scatter_indexed_tuning_table[0] = 3;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_1ppn[] =
                    GEN2__INTEL_XEON_E5_2690_V2_2S_20__MLX_CX_CONNIB__1PPN;
            table_ptrs[0] = mvp_tmp_scatter_indexed_thresholds_table_1ppn;

            mvp_scatter_indexed_table_ppn_conf[1] = 2;
            mvp_size_scatter_indexed_tuning_table[1] = 4;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_2ppn[] =
                    GEN2__INTEL_XEON_E5_2690_V2_2S_20__MLX_CX_CONNIB__2PPN;
            table_ptrs[1] = mvp_tmp_scatter_indexed_thresholds_table_2ppn;

            mvp_scatter_indexed_table_ppn_conf[2] = 20;
            mvp_size_scatter_indexed_tuning_table[2] = 4;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_20ppn[] =
                    GEN2__INTEL_XEON_E5_2690_V2_2S_20__MLX_CX_CONNIB__20PPN;
            table_ptrs[2] = mvp_tmp_scatter_indexed_thresholds_table_20ppn;

            agg_table_sum = 0;
            for (i = 0; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                agg_table_sum += mvp_size_scatter_indexed_tuning_table[i];
            }
            mvp_scatter_indexed_thresholds_table[0] = MPL_malloc(
                agg_table_sum * sizeof(mvp_scatter_indexed_tuning_table),
                MPL_MEM_COLL);
            MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[0], table_ptrs[0],
                        (sizeof(mvp_scatter_indexed_tuning_table) *
                         mvp_size_scatter_indexed_tuning_table[0]));
            for (i = 1; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                mvp_scatter_indexed_thresholds_table[i] =
                    mvp_scatter_indexed_thresholds_table[i - 1] +
                    mvp_size_scatter_indexed_tuning_table[i - 1];
                MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[i],
                            table_ptrs[i],
                            (sizeof(mvp_scatter_indexed_tuning_table) *
                             mvp_size_scatter_indexed_tuning_table[i]));
            }
            MPL_free(table_ptrs);
            return 0;
        }
        if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                 MVP_ARCH_INTEL_XEON_E5_2630_V2_2S_12,
                                 MVP_HCA_MLX_CX_CONNIB) &&
            !heterogeneity) {
            /* Wilkes Table*/
            mvp_scatter_indexed_num_ppn_conf = 3;
            mvp_scatter_indexed_thresholds_table =
                MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                               mvp_scatter_indexed_num_ppn_conf,
                           MPL_MEM_COLL);
            table_ptrs = MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                                        mvp_scatter_indexed_num_ppn_conf,
                                    MPL_MEM_COLL);
            mvp_size_scatter_indexed_tuning_table = MPL_malloc(
                sizeof(int) * mvp_scatter_indexed_num_ppn_conf, MPL_MEM_COLL);
            mvp_scatter_indexed_table_ppn_conf = MPL_malloc(
                mvp_scatter_indexed_num_ppn_conf * sizeof(int), MPL_MEM_COLL);

            mvp_scatter_indexed_table_ppn_conf[0] = 1;
            mvp_size_scatter_indexed_tuning_table[0] = 6;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_1ppn[] =
                    GEN2__INTEL_XEON_E5_2630_V2_2S_12__MLX_CX_CONNIB__1PPN
                        table_ptrs[0] =
                            mvp_tmp_scatter_indexed_thresholds_table_1ppn;

            mvp_scatter_indexed_table_ppn_conf[1] = 2;
            mvp_size_scatter_indexed_tuning_table[1] = 6;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_2ppn[] =
                    GEN2__INTEL_XEON_E5_2630_V2_2S_12__MLX_CX_CONNIB__2PPN
                        table_ptrs[1] =
                            mvp_tmp_scatter_indexed_thresholds_table_2ppn;

            mvp_scatter_indexed_table_ppn_conf[2] = 12;
            mvp_size_scatter_indexed_tuning_table[2] = 6;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_12ppn[] =
                    GEN2__INTEL_XEON_E5_2630_V2_2S_12__MLX_CX_CONNIB__12PPN
                        table_ptrs[2] =
                            mvp_tmp_scatter_indexed_thresholds_table_12ppn;

            agg_table_sum = 0;
            for (i = 0; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                agg_table_sum += mvp_size_scatter_indexed_tuning_table[i];
            }
            mvp_scatter_indexed_thresholds_table[0] = MPL_malloc(
                agg_table_sum * sizeof(mvp_scatter_indexed_tuning_table),
                MPL_MEM_COLL);
            MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[0], table_ptrs[0],
                        (sizeof(mvp_scatter_indexed_tuning_table) *
                         mvp_size_scatter_indexed_tuning_table[0]));
            for (i = 1; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                mvp_scatter_indexed_thresholds_table[i] =
                    mvp_scatter_indexed_thresholds_table[i - 1] +
                    mvp_size_scatter_indexed_tuning_table[i - 1];
                MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[i],
                            table_ptrs[i],
                            (sizeof(mvp_scatter_indexed_tuning_table) *
                             mvp_size_scatter_indexed_tuning_table[i]));
            }
            MPL_free(table_ptrs);
            return 0;
        }
        if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                 MVP_ARCH_AMD_OPTERON_6136_32,
                                 MVP_HCA_MLX_CX_QDR) &&
            !heterogeneity) {
            /*Trestles Table*/
            mvp_scatter_indexed_num_ppn_conf = 3;
            mvp_scatter_indexed_thresholds_table =
                MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                               mvp_scatter_indexed_num_ppn_conf,
                           MPL_MEM_COLL);
            table_ptrs = MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                                        mvp_scatter_indexed_num_ppn_conf,
                                    MPL_MEM_COLL);
            mvp_size_scatter_indexed_tuning_table = MPL_malloc(
                sizeof(int) * mvp_scatter_indexed_num_ppn_conf, MPL_MEM_COLL);
            mvp_scatter_indexed_table_ppn_conf = MPL_malloc(
                mvp_scatter_indexed_num_ppn_conf * sizeof(int), MPL_MEM_COLL);

            mvp_scatter_indexed_table_ppn_conf[0] = 1;
            mvp_size_scatter_indexed_tuning_table[0] = 4;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_1ppn[] =
                    GEN2__AMD_OPTERON_6136_32__MLX_CX_QDR__1PPN table_ptrs[0] =
                        mvp_tmp_scatter_indexed_thresholds_table_1ppn;

            mvp_scatter_indexed_table_ppn_conf[1] = 2;
            mvp_size_scatter_indexed_tuning_table[1] = 3;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_2ppn[] =
                    GEN2__AMD_OPTERON_6136_32__MLX_CX_QDR__2PPN table_ptrs[1] =
                        mvp_tmp_scatter_indexed_thresholds_table_2ppn;

            mvp_scatter_indexed_table_ppn_conf[2] = 32;
#if defined(_SMP_CMA_)
            mvp_scatter_indexed_tuning_table
                mvp_tmp_cma_scatter_indexed_thresholds_table_32ppn[] =
                    GEN2_CMA__AMD_OPTERON_6136_32__MLX_CX_QDR__32PPN;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_32ppn[] =
                    GEN2__AMD_OPTERON_6136_32__MLX_CX_QDR__32PPN;
            if (MVP_SMP_USE_CMA) {
                mvp_size_scatter_indexed_tuning_table[2] = 4;
                table_ptrs[2] =
                    mvp_tmp_cma_scatter_indexed_thresholds_table_32ppn;
            } else {
                mvp_size_scatter_indexed_tuning_table[2] = 4;
                table_ptrs[2] = mvp_tmp_scatter_indexed_thresholds_table_32ppn;
            }
#else
            mvp_size_scatter_indexed_tuning_table[2] = 4;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_32ppn[] =
                    GEN2__AMD_OPTERON_6136_32__MLX_CX_QDR__32PPN;
            table_ptrs[2] = mvp_tmp_scatter_indexed_thresholds_table_32ppn;
#endif

            agg_table_sum = 0;
            for (i = 0; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                agg_table_sum += mvp_size_scatter_indexed_tuning_table[i];
            }
            mvp_scatter_indexed_thresholds_table[0] = MPL_malloc(
                agg_table_sum * sizeof(mvp_scatter_indexed_tuning_table),
                MPL_MEM_COLL);
            MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[0], table_ptrs[0],
                        (sizeof(mvp_scatter_indexed_tuning_table) *
                         mvp_size_scatter_indexed_tuning_table[0]));
            for (i = 1; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                mvp_scatter_indexed_thresholds_table[i] =
                    mvp_scatter_indexed_thresholds_table[i - 1] +
                    mvp_size_scatter_indexed_tuning_table[i - 1];
                MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[i],
                            table_ptrs[i],
                            (sizeof(mvp_scatter_indexed_tuning_table) *
                             mvp_size_scatter_indexed_tuning_table[i]));
            }
            MPL_free(table_ptrs);
            return 0;
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_INTEL_XEON_E5_2670_16,
                                        MVP_HCA_MLX_CX_QDR) &&
                   !heterogeneity) {
            /*Gordon Table*/
            mvp_scatter_indexed_num_ppn_conf = 3;
            mvp_scatter_indexed_thresholds_table =
                MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                               mvp_scatter_indexed_num_ppn_conf,
                           MPL_MEM_COLL);
            table_ptrs = MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                                        mvp_scatter_indexed_num_ppn_conf,
                                    MPL_MEM_COLL);
            mvp_size_scatter_indexed_tuning_table = MPL_malloc(
                sizeof(int) * mvp_scatter_indexed_num_ppn_conf, MPL_MEM_COLL);
            mvp_scatter_indexed_table_ppn_conf = MPL_malloc(
                mvp_scatter_indexed_num_ppn_conf * sizeof(int), MPL_MEM_COLL);

            mvp_scatter_indexed_table_ppn_conf[0] = 1;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_1ppn[] =
                    GEN2__INTEL_XEON_E5_2670_16__MLX_CX_QDR__1PPN;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_cma_scatter_indexed_thresholds_table_1ppn[] =
                    GEN2_CMA__INTEL_XEON_E5_2670_16__MLX_CX_QDR__1PPN;
#if defined(_SMP_CMA_)
            if (MVP_SMP_USE_CMA) {
                mvp_size_scatter_indexed_tuning_table[0] = 6;
                table_ptrs[0] =
                    mvp_tmp_cma_scatter_indexed_thresholds_table_1ppn;
            } else {
                mvp_size_scatter_indexed_tuning_table[0] = 6;
                table_ptrs[0] = mvp_tmp_scatter_indexed_thresholds_table_1ppn;
            }
#else
            mvp_size_scatter_indexed_tuning_table[0] = 6;
            table_ptrs[0] = mvp_tmp_scatter_indexed_thresholds_table_1ppn;
#endif

            mvp_scatter_indexed_table_ppn_conf[1] = 2;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_2ppn[] =
                    GEN2__INTEL_XEON_E5_2670_16__MLX_CX_QDR__2PPN;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_cma_scatter_indexed_thresholds_table_2ppn[] =
                    GEN2_CMA__INTEL_XEON_E5_2670_16__MLX_CX_QDR__2PPN;
#if defined(_SMP_CMA_)
            if (MVP_SMP_USE_CMA) {
                mvp_size_scatter_indexed_tuning_table[1] = 7;
                table_ptrs[1] =
                    mvp_tmp_cma_scatter_indexed_thresholds_table_2ppn;
            } else {
                mvp_size_scatter_indexed_tuning_table[1] = 7;
                table_ptrs[1] = mvp_tmp_scatter_indexed_thresholds_table_2ppn;
            }
#else
            mvp_size_scatter_indexed_tuning_table[1] = 7;
            table_ptrs[1] = mvp_tmp_scatter_indexed_thresholds_table_2ppn;
#endif

            mvp_scatter_indexed_table_ppn_conf[2] = 16;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_cma_scatter_indexed_thresholds_table_16ppn[] =
                    GEN2_CMA__INTEL_XEON_E5_2670_16__MLX_CX_QDR__16PPN;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_16ppn[] =
                    GEN2__INTEL_XEON_E5_2670_16__MLX_CX_QDR__16PPN;
#if defined(_SMP_CMA_)
            if (MVP_SMP_USE_CMA) {
                mvp_size_scatter_indexed_tuning_table[2] = 7;
                table_ptrs[2] =
                    mvp_tmp_cma_scatter_indexed_thresholds_table_16ppn;
            } else {
                mvp_size_scatter_indexed_tuning_table[2] = 7;
                table_ptrs[2] = mvp_tmp_scatter_indexed_thresholds_table_16ppn;
            }
#else
            mvp_size_scatter_indexed_tuning_table[2] = 7;
            table_ptrs[2] = mvp_tmp_scatter_indexed_thresholds_table_16ppn;
#endif

            agg_table_sum = 0;
            for (i = 0; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                agg_table_sum += mvp_size_scatter_indexed_tuning_table[i];
            }
            mvp_scatter_indexed_thresholds_table[0] = MPL_malloc(
                agg_table_sum * sizeof(mvp_scatter_indexed_tuning_table),
                MPL_MEM_COLL);
            MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[0], table_ptrs[0],
                        (sizeof(mvp_scatter_indexed_tuning_table) *
                         mvp_size_scatter_indexed_tuning_table[0]));
            for (i = 1; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                mvp_scatter_indexed_thresholds_table[i] =
                    mvp_scatter_indexed_thresholds_table[i - 1] +
                    mvp_size_scatter_indexed_tuning_table[i - 1];
                MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[i],
                            table_ptrs[i],
                            (sizeof(mvp_scatter_indexed_tuning_table) *
                             mvp_size_scatter_indexed_tuning_table[i]));
            }
            MPL_free(table_ptrs);
            return 0;
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_INTEL_XEON_E5_2670_16,
                                        MVP_HCA_MLX_CX_FDR) &&
                   !heterogeneity) {
            /*Yellowstone Table*/
            mvp_scatter_indexed_num_ppn_conf = 3;
            mvp_scatter_indexed_thresholds_table =
                MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                               mvp_scatter_indexed_num_ppn_conf,
                           MPL_MEM_COLL);
            table_ptrs = MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                                        mvp_scatter_indexed_num_ppn_conf,
                                    MPL_MEM_COLL);
            mvp_size_scatter_indexed_tuning_table = MPL_malloc(
                sizeof(int) * mvp_scatter_indexed_num_ppn_conf, MPL_MEM_COLL);
            mvp_scatter_indexed_table_ppn_conf = MPL_malloc(
                mvp_scatter_indexed_num_ppn_conf * sizeof(int), MPL_MEM_COLL);

            mvp_scatter_indexed_table_ppn_conf[0] = 1;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_1ppn[] =
                    GEN2__INTEL_XEON_E5_2670_16__MLX_CX_FDR__1PPN;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_cma_scatter_indexed_thresholds_table_1ppn[] =
                    GEN2_CMA__INTEL_XEON_E5_2670_16__MLX_CX_FDR__1PPN;
#if defined(_SMP_CMA_)
            if (MVP_SMP_USE_CMA) {
                mvp_size_scatter_indexed_tuning_table[0] = 3;
                table_ptrs[0] =
                    mvp_tmp_cma_scatter_indexed_thresholds_table_1ppn;
            } else {
                mvp_size_scatter_indexed_tuning_table[0] = 2;
                table_ptrs[0] = mvp_tmp_scatter_indexed_thresholds_table_1ppn;
            }
#else
            mvp_size_scatter_indexed_tuning_table[0] = 2;
            table_ptrs[0] = mvp_tmp_scatter_indexed_thresholds_table_1ppn;
#endif

            mvp_scatter_indexed_table_ppn_conf[1] = 2;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_2ppn[] =
                    GEN2__INTEL_XEON_E5_2670_16__MLX_CX_FDR__2PPN;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_cma_scatter_indexed_thresholds_table_2ppn[] =
                    GEN2_CMA__INTEL_XEON_E5_2670_16__MLX_CX_FDR__2PPN;
#if defined(_SMP_CMA_)
            if (MVP_SMP_USE_CMA) {
                mvp_size_scatter_indexed_tuning_table[1] = 3;
                table_ptrs[1] =
                    mvp_tmp_cma_scatter_indexed_thresholds_table_2ppn;
            } else {
                mvp_size_scatter_indexed_tuning_table[1] = 2;
                table_ptrs[1] = mvp_tmp_scatter_indexed_thresholds_table_2ppn;
            }
#else
            mvp_size_scatter_indexed_tuning_table[1] = 2;
            table_ptrs[1] = mvp_tmp_scatter_indexed_thresholds_table_2ppn;
#endif

            mvp_scatter_indexed_table_ppn_conf[2] = 16;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_cma_scatter_indexed_thresholds_table_16ppn[] =
                    GEN2_CMA__INTEL_XEON_E5_2670_16__MLX_CX_FDR__16PPN;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_16ppn[] =
                    GEN2__INTEL_XEON_E5_2670_16__MLX_CX_FDR__16PPN;
#if defined(_SMP_CMA_)
            if (MVP_SMP_USE_CMA) {
                mvp_size_scatter_indexed_tuning_table[2] = 4;
                table_ptrs[2] =
                    mvp_tmp_cma_scatter_indexed_thresholds_table_16ppn;
            } else {
                mvp_size_scatter_indexed_tuning_table[2] = 5;
                table_ptrs[2] = mvp_tmp_scatter_indexed_thresholds_table_16ppn;
            }
#else
            mvp_size_scatter_indexed_tuning_table[2] = 5;
            table_ptrs[2] = mvp_tmp_scatter_indexed_thresholds_table_16ppn;
#endif

            agg_table_sum = 0;
            for (i = 0; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                agg_table_sum += mvp_size_scatter_indexed_tuning_table[i];
            }
            mvp_scatter_indexed_thresholds_table[0] = MPL_malloc(
                agg_table_sum * sizeof(mvp_scatter_indexed_tuning_table),
                MPL_MEM_COLL);
            MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[0], table_ptrs[0],
                        (sizeof(mvp_scatter_indexed_tuning_table) *
                         mvp_size_scatter_indexed_tuning_table[0]));
            for (i = 1; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                mvp_scatter_indexed_thresholds_table[i] =
                    mvp_scatter_indexed_thresholds_table[i - 1] +
                    mvp_size_scatter_indexed_tuning_table[i - 1];
                MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[i],
                            table_ptrs[i],
                            (sizeof(mvp_scatter_indexed_tuning_table) *
                             mvp_size_scatter_indexed_tuning_table[i]));
            }
            MPL_free(table_ptrs);
            return 0;
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_INTEL_XEON_E5_2680_16,
                                        MVP_HCA_MLX_CX_FDR) &&
                   !heterogeneity) {
            /*Stampede Table*/
            mvp_scatter_indexed_num_ppn_conf = 4;
            mvp_scatter_indexed_thresholds_table =
                MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                               mvp_scatter_indexed_num_ppn_conf,
                           MPL_MEM_COLL);
            table_ptrs = MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                                        mvp_scatter_indexed_num_ppn_conf,
                                    MPL_MEM_COLL);
            mvp_size_scatter_indexed_tuning_table = MPL_malloc(
                sizeof(int) * mvp_scatter_indexed_num_ppn_conf, MPL_MEM_COLL);
            mvp_scatter_indexed_table_ppn_conf = MPL_malloc(
                mvp_scatter_indexed_num_ppn_conf * sizeof(int), MPL_MEM_COLL);

            mvp_scatter_indexed_table_ppn_conf[0] = 1;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_1ppn[] =
                    GEN2__INTEL_XEON_E5_2680_16__MLX_CX_FDR__1PPN;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_cma_scatter_indexed_thresholds_table_1ppn[] =
                    GEN2_CMA__INTEL_XEON_E5_2680_16__MLX_CX_FDR__1PPN;
#if defined(_SMP_CMA_)
            if (MVP_SMP_USE_CMA) {
                mvp_size_scatter_indexed_tuning_table[0] = 5;
                table_ptrs[0] =
                    mvp_tmp_cma_scatter_indexed_thresholds_table_1ppn;
            } else {
                mvp_size_scatter_indexed_tuning_table[0] = 5;
                table_ptrs[0] = mvp_tmp_scatter_indexed_thresholds_table_1ppn;
            }
#else
            mvp_size_scatter_indexed_tuning_table[0] = 5;
            table_ptrs[0] = mvp_tmp_scatter_indexed_thresholds_table_1ppn;
#endif

            mvp_scatter_indexed_table_ppn_conf[1] = 2;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_2ppn[] =
                    GEN2__INTEL_XEON_E5_2680_16__MLX_CX_FDR__2PPN;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_cma_scatter_indexed_thresholds_table_2ppn[] =
                    GEN2_CMA__INTEL_XEON_E5_2680_16__MLX_CX_FDR__2PPN;
#if defined(_SMP_CMA_)
            if (MVP_SMP_USE_CMA) {
                mvp_size_scatter_indexed_tuning_table[1] = 6;
                table_ptrs[1] =
                    mvp_tmp_cma_scatter_indexed_thresholds_table_2ppn;
            } else {
                mvp_size_scatter_indexed_tuning_table[1] = 6;
                table_ptrs[1] = mvp_tmp_scatter_indexed_thresholds_table_2ppn;
            }
#else
            mvp_size_scatter_indexed_tuning_table[1] = 6;
            table_ptrs[1] = mvp_tmp_scatter_indexed_thresholds_table_2ppn;
#endif

            mvp_scatter_indexed_table_ppn_conf[2] = 4;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_cma_scatter_indexed_thresholds_table_4ppn[] =
                    GEN2_CMA__INTEL_XEON_E5_2680_16__MLX_CX_FDR__4PPN;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_4ppn[] =
                    GEN2__INTEL_XEON_E5_2680_16__MLX_CX_FDR__4PPN;
#if defined(_SMP_CMA_)
            if (MVP_SMP_USE_CMA) {
                mvp_size_scatter_indexed_tuning_table[2] = 1;
                table_ptrs[2] =
                    mvp_tmp_cma_scatter_indexed_thresholds_table_4ppn;
            } else {
                mvp_size_scatter_indexed_tuning_table[2] = 1;
                table_ptrs[2] = mvp_tmp_scatter_indexed_thresholds_table_4ppn;
            }
#else
            mvp_size_scatter_indexed_tuning_table[2] = 1;
            table_ptrs[2] = mvp_tmp_scatter_indexed_thresholds_table_4ppn;
#endif

            mvp_scatter_indexed_table_ppn_conf[3] = 16;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_cma_scatter_indexed_thresholds_table_16ppn[] =
                    GEN2_CMA__INTEL_XEON_E5_2680_16__MLX_CX_FDR__16PPN;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_16ppn[] =
                    GEN2__INTEL_XEON_E5_2680_16__MLX_CX_FDR__16PPN;
#if defined(_SMP_CMA_)
            if (MVP_SMP_USE_CMA) {
                mvp_size_scatter_indexed_tuning_table[3] = 6;
                table_ptrs[3] =
                    mvp_tmp_cma_scatter_indexed_thresholds_table_16ppn;
            } else {
                mvp_size_scatter_indexed_tuning_table[3] = 6;
                table_ptrs[3] = mvp_tmp_scatter_indexed_thresholds_table_16ppn;
            }
#else
            mvp_size_scatter_indexed_tuning_table[3] = 6;
            table_ptrs[3] = mvp_tmp_scatter_indexed_thresholds_table_16ppn;
#endif

            agg_table_sum = 0;
            for (i = 0; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                agg_table_sum += mvp_size_scatter_indexed_tuning_table[i];
            }
            mvp_scatter_indexed_thresholds_table[0] = MPL_malloc(
                agg_table_sum * sizeof(mvp_scatter_indexed_tuning_table),
                MPL_MEM_COLL);
            MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[0], table_ptrs[0],
                        (sizeof(mvp_scatter_indexed_tuning_table) *
                         mvp_size_scatter_indexed_tuning_table[0]));
            for (i = 1; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                mvp_scatter_indexed_thresholds_table[i] =
                    mvp_scatter_indexed_thresholds_table[i - 1] +
                    mvp_size_scatter_indexed_tuning_table[i - 1];
                MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[i],
                            table_ptrs[i],
                            (sizeof(mvp_scatter_indexed_tuning_table) *
                             mvp_size_scatter_indexed_tuning_table[i]));
            }
            MPL_free(table_ptrs);
            return 0;
        }

        else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                      MVP_ARCH_INTEL_XEON_E5_2680_V4_2S_28,
                                      MVP_HCA_MLX_CX_EDR) &&
                 !heterogeneity) {
            /*RI2 Table*/
            MVP_COLL_TUNING_START_TABLE(scatter, 6)
            MVP_COLL_TUNING_ADD_CONF(scatter, 1, 5, GEN2__RI2__1PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 1, 5, GEN2_CMA__RI2__1PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 2, 6, GEN2__RI2__2PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 2, 6, GEN2_CMA__RI2__2PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 4, 5, GEN2__RI2__4PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 4, 5, GEN2_CMA__RI2__4PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 8, 5, GEN2__RI2__8PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 8, 5, GEN2_CMA__RI2__8PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 16, 5, GEN2__RI2__16PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 16, 5, GEN2_CMA__RI2__16PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 28, 6, GEN2__RI2__28PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 28, 6, GEN2_CMA__RI2__28PPN)
            MVP_COLL_TUNING_FINISH_TABLE(scatter)
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_AMD_EPYC_7551_64,
                                        MVP_HCA_MLX_CX_EDR) &&
                   !heterogeneity) {
            /* AMD EPYC table */
            MVP_COLL_TUNING_START_TABLE(scatter, 7)
            MVP_COLL_TUNING_ADD_CONF(scatter, 1, 3, GEN2__AMD_EPYC__1PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 1, 3,
                                         GEN2_CMA__AMD_EPYC__1PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 2, 4, GEN2__AMD_EPYC__2PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 2, 4,
                                         GEN2_CMA__AMD_EPYC__2PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 4, 4, GEN2__AMD_EPYC__4PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 4, 4,
                                         GEN2_CMA__AMD_EPYC__4PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 8, 4, GEN2__AMD_EPYC__8PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 8, 4,
                                         GEN2_CMA__AMD_EPYC__8PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 16, 4, GEN2__AMD_EPYC__16PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 16, 4,
                                         GEN2_CMA__AMD_EPYC__16PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 32, 4, GEN2__AMD_EPYC__32PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 32, 4,
                                         GEN2_CMA__AMD_EPYC__32PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 64, 4, GEN2__AMD_EPYC__64PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 64, 4,
                                         GEN2_CMA__AMD_EPYC__64PPN)
            MVP_COLL_TUNING_FINISH_TABLE(scatter)
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_AMD_EPYC_7551_64,
                                        MVP_HCA_MLX_CX_HDR) &&
                   !heterogeneity) {
            /* AMD EPYC table */
            MVP_COLL_TUNING_START_TABLE(scatter, 7)
            MVP_COLL_TUNING_ADD_CONF(scatter, 1, 3, GEN2__AMD_EPYC__1PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 1, 3,
                                         GEN2_CMA__AMD_EPYC__1PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 2, 4, GEN2__AMD_EPYC__2PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 2, 4,
                                         GEN2_CMA__AMD_EPYC__2PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 4, 4, GEN2__AMD_EPYC__4PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 4, 4,
                                         GEN2_CMA__AMD_EPYC__4PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 8, 4, GEN2__AMD_EPYC__8PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 8, 4,
                                         GEN2_CMA__AMD_EPYC__8PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 16, 4, GEN2__AMD_EPYC__16PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 16, 4,
                                         GEN2_CMA__AMD_EPYC__16PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 32, 4, GEN2__AMD_EPYC__32PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 32, 4,
                                         GEN2_CMA__AMD_EPYC__32PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 64, 4, GEN2__AMD_EPYC__64PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 64, 4,
                                         GEN2_CMA__AMD_EPYC__64PPN)
            MVP_COLL_TUNING_FINISH_TABLE(scatter)
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_AMD_EPYC_7551_64,
                                        MVP_HCA_ANY) &&
                   !heterogeneity) {
            /* AMD EPYC table */
            MVP_COLL_TUNING_START_TABLE(scatter, 7)
            MVP_COLL_TUNING_ADD_CONF(scatter, 1, 3, GEN2__AMD_EPYC__1PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 1, 3,
                                         GEN2_CMA__AMD_EPYC__1PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 2, 4, GEN2__AMD_EPYC__2PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 2, 4,
                                         GEN2_CMA__AMD_EPYC__2PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 4, 4, GEN2__AMD_EPYC__4PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 4, 4,
                                         GEN2_CMA__AMD_EPYC__4PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 8, 4, GEN2__AMD_EPYC__8PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 8, 4,
                                         GEN2_CMA__AMD_EPYC__8PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 16, 4, GEN2__AMD_EPYC__16PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 16, 4,
                                         GEN2_CMA__AMD_EPYC__16PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 32, 4, GEN2__AMD_EPYC__32PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 32, 4,
                                         GEN2_CMA__AMD_EPYC__32PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 64, 4, GEN2__AMD_EPYC__64PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 64, 4,
                                         GEN2_CMA__AMD_EPYC__64PPN)
            MVP_COLL_TUNING_FINISH_TABLE(scatter)
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_AMD_EPYC_7662_64,
                                        MVP_HCA_MLX_CX_EDR) &&
                   !heterogeneity) {
            /* Spock @ORNL table */
            MVP_COLL_TUNING_START_TABLE(scatter, 7)
            MVP_COLL_TUNING_ADD_CONF(scatter, 1, 4,
                                     GEN2_CMA__AMD_EPYC_7763_128__1PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 1, 4,
                                         GEN2_CMA__AMD_EPYC_7763_128__1PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 2, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__2PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 2, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__2PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 4, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__4PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 4, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__4PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 8, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__8PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 8, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__8PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 16, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__16PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 16, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__16PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 32, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__32PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 32, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__32PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 64, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__64PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 64, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__64PPN)
            MVP_COLL_TUNING_FINISH_TABLE(scatter)
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_AMD_EPYC_7662_64,
                                        MVP_HCA_MLX_CX_HDR) &&
                   !heterogeneity) {
            /* Spock @ORNL table */
            MVP_COLL_TUNING_START_TABLE(scatter, 7)
            MVP_COLL_TUNING_ADD_CONF(scatter, 1, 4,
                                     GEN2_CMA__AMD_EPYC_7763_128__1PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 1, 4,
                                         GEN2_CMA__AMD_EPYC_7763_128__1PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 2, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__2PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 2, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__2PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 4, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__4PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 4, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__4PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 8, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__8PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 8, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__8PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 16, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__16PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 16, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__16PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 32, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__32PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 32, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__32PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 64, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__64PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 64, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__64PPN)
            MVP_COLL_TUNING_FINISH_TABLE(scatter)
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_AMD_EPYC_7662_64,
                                        MVP_HCA_ANY) &&
                   !heterogeneity) {
            /* Spock @ORNL table */
            MVP_COLL_TUNING_START_TABLE(scatter, 7)
            MVP_COLL_TUNING_ADD_CONF(scatter, 1, 4,
                                     GEN2_CMA__AMD_EPYC_7763_128__1PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 1, 4,
                                         GEN2_CMA__AMD_EPYC_7763_128__1PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 2, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__2PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 2, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__2PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 4, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__4PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 4, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__4PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 8, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__8PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 8, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__8PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 16, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__16PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 16, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__16PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 32, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__32PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 32, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__32PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 64, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__64PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 64, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__64PPN)
            MVP_COLL_TUNING_FINISH_TABLE(scatter)
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_AMD_EPYC_7763_128,
                                        MVP_HCA_MLX_CX_EDR) &&
                   !heterogeneity) {
            /* Lonestar-6 table */
            MVP_COLL_TUNING_START_TABLE(scatter, 8)
            MVP_COLL_TUNING_ADD_CONF(scatter, 1, 4,
                                     GEN2_CMA__AMD_EPYC_7763_128__1PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 1, 4,
                                         GEN2_CMA__AMD_EPYC_7763_128__1PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 2, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__2PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 2, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__2PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 4, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__4PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 4, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__4PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 8, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__8PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 8, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__8PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 16, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__16PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 16, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__16PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 32, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__32PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 32, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__32PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 64, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__64PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 64, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__64PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 128, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__128PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 128, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__128PPN)
            MVP_COLL_TUNING_FINISH_TABLE(scatter)
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_AMD_EPYC_7763_128,
                                        MVP_HCA_MLX_CX_HDR) &&
                   !heterogeneity) {
            /* Lonestar-6 table */
            MVP_COLL_TUNING_START_TABLE(scatter, 8)
            MVP_COLL_TUNING_ADD_CONF(scatter, 1, 4,
                                     GEN2_CMA__AMD_EPYC_7763_128__1PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 1, 4,
                                         GEN2_CMA__AMD_EPYC_7763_128__1PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 2, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__2PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 2, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__2PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 4, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__4PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 4, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__4PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 8, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__8PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 8, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__8PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 16, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__16PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 16, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__16PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 32, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__32PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 32, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__32PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 64, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__64PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 64, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__64PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 128, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__128PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 128, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__128PPN)
            MVP_COLL_TUNING_FINISH_TABLE(scatter)
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_AMD_EPYC_7763_128,
                                        MVP_HCA_ANY) &&
                   !heterogeneity) {
            /* Lonestar-6 table */
            MVP_COLL_TUNING_START_TABLE(scatter, 8)
            MVP_COLL_TUNING_ADD_CONF(scatter, 1, 4,
                                     GEN2_CMA__AMD_EPYC_7763_128__1PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 1, 4,
                                         GEN2_CMA__AMD_EPYC_7763_128__1PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 2, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__2PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 2, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__2PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 4, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__4PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 4, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__4PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 8, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__8PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 8, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__8PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 16, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__16PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 16, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__16PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 32, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__32PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 32, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__32PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 64, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__64PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 64, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__64PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 128, 5,
                                     GEN2_CMA__AMD_EPYC_7763_128__128PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 128, 5,
                                         GEN2_CMA__AMD_EPYC_7763_128__128PPN)
            MVP_COLL_TUNING_FINISH_TABLE(scatter)
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_AMD_EPYC_7601_64,
                                        MVP_HCA_ANY) &&
                   !heterogeneity) {
            /* AMD EPYC rome oslo table */
            MVP_COLL_TUNING_START_TABLE(scatter, 8)
            MVP_COLL_TUNING_ADD_CONF(scatter, 1, 4,
                                     GEN2_CMA__AMD_EPYC_ROME__1PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 1, 4,
                                         GEN2_CMA__AMD_EPYC_ROME__1PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 2, 5,
                                     GEN2_CMA__AMD_EPYC_ROME__2PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 2, 5,
                                         GEN2_CMA__AMD_EPYC_ROME__2PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 4, 5,
                                     GEN2_CMA__AMD_EPYC_ROME__4PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 4, 5,
                                         GEN2_CMA__AMD_EPYC_ROME__4PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 8, 5,
                                     GEN2_CMA__AMD_EPYC_ROME__8PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 8, 5,
                                         GEN2_CMA__AMD_EPYC_ROME__8PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 16, 5,
                                     GEN2_CMA__AMD_EPYC_ROME__16PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 16, 5,
                                         GEN2_CMA__AMD_EPYC_ROME__16PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 32, 5,
                                     GEN2_CMA__AMD_EPYC_ROME__32PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 32, 5,
                                         GEN2_CMA__AMD_EPYC_ROME__32PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 60, 5,
                                     GEN2_CMA__AMD_EPYC_ROME__60PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 60, 5,
                                         GEN2_CMA__AMD_EPYC_ROME__60PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 64, 5,
                                     GEN2_CMA__AMD_EPYC_ROME__64PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 64, 5,
                                         GEN2_CMA__AMD_EPYC_ROME__64PPN)
            MVP_COLL_TUNING_FINISH_TABLE(scatter)
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_AMD_EPYC_7742_128,
                                        MVP_HCA_ANY) &&
                   !heterogeneity) {
            /* AMD EPYC rome table */
            MVP_COLL_TUNING_START_TABLE(scatter, 10)
            MVP_COLL_TUNING_ADD_CONF(scatter, 1, 4,
                                     GEN2_CMA__AMD_EPYC_ROME__1PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 1, 4,
                                         GEN2_CMA__AMD_EPYC_ROME__1PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 2, 5,
                                     GEN2_CMA__AMD_EPYC_ROME__2PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 2, 5,
                                         GEN2_CMA__AMD_EPYC_ROME__2PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 4, 5,
                                     GEN2_CMA__AMD_EPYC_ROME__4PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 4, 5,
                                         GEN2_CMA__AMD_EPYC_ROME__4PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 8, 5,
                                     GEN2_CMA__AMD_EPYC_ROME__8PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 8, 5,
                                         GEN2_CMA__AMD_EPYC_ROME__8PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 16, 5,
                                     GEN2_CMA__AMD_EPYC_ROME__16PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 16, 5,
                                         GEN2_CMA__AMD_EPYC_ROME__16PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 32, 5,
                                     GEN2_CMA__AMD_EPYC_ROME__32PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 32, 5,
                                         GEN2_CMA__AMD_EPYC_ROME__32PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 60, 5,
                                     GEN2_CMA__AMD_EPYC_ROME__60PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 60, 5,
                                         GEN2_CMA__AMD_EPYC_ROME__60PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 64, 5,
                                     GEN2_CMA__AMD_EPYC_ROME__64PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 64, 5,
                                         GEN2_CMA__AMD_EPYC_ROME__64PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 120, 5,
                                     GEN2_CMA__AMD_EPYC_ROME__120PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 120, 5,
                                         GEN2_CMA__AMD_EPYC_ROME__120PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 128, 5,
                                     GEN2_CMA__AMD_EPYC_ROME__128PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 128, 5,
                                         GEN2_CMA__AMD_EPYC_ROME__128PPN)
            MVP_COLL_TUNING_FINISH_TABLE(scatter)
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_INTEL_XEON_E5_2687W_V3_2S_20,
                                        MVP_HCA_MLX_CX_HDR) &&
                   !heterogeneity) {
            /* Haswell HDR nodes on NOWLAB */
            MVP_COLL_TUNING_START_TABLE(scatter, 6)
            MVP_COLL_TUNING_ADD_CONF(scatter, 1, 2, GEN2_CMA__NOWHASWELL__1PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 1, 2,
                                         GEN2_CMA__NOWHASWELL__1PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 2, 2, GEN2_CMA__NOWHASWELL__2PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 2, 2,
                                         GEN2_CMA__NOWHASWELL__2PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 4, 3, GEN2_CMA__NOWHASWELL__4PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 4, 3,
                                         GEN2_CMA__NOWHASWELL__4PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 8, 3, GEN2_CMA__NOWHASWELL__8PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 8, 3,
                                         GEN2_CMA__NOWHASWELL__8PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 16, 3,
                                     GEN2_CMA__NOWHASWELL__16PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 16, 3,
                                         GEN2_CMA__NOWHASWELL__16PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 20, 3,
                                     GEN2_CMA__NOWHASWELL__20PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 20, 3,
                                         GEN2_CMA__NOWHASWELL__20PPN)
            MVP_COLL_TUNING_FINISH_TABLE(scatter)
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_INTEL_PLATINUM_8280_2S_56,
                                        MVP_HCA_MLX_CX_EDR) &&
                   !heterogeneity) {
            /* Frontera */
            MVP_COLL_TUNING_START_TABLE(scatter, 8)
            MVP_COLL_TUNING_ADD_CONF(scatter, 1, 4, GEN2_CMA__FRONTERA__1PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 1, 4,
                                         GEN2_CMA__FRONTERA__1PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 2, 5, GEN2_CMA__FRONTERA__2PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 2, 5,
                                         GEN2_CMA__FRONTERA__2PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 4, 5, GEN2_CMA__FRONTERA__4PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 4, 5,
                                         GEN2_CMA__FRONTERA__4PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 8, 5, GEN2_CMA__FRONTERA__8PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 8, 5,
                                         GEN2_CMA__FRONTERA__8PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 16, 5, GEN2_CMA__FRONTERA__16PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 16, 5,
                                         GEN2_CMA__FRONTERA__16PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 28, 4, GEN2_CMA__FRONTERA__28PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 28, 4,
                                         GEN2_CMA__FRONTERA__28PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 32, 5, GEN2_CMA__FRONTERA__32PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 32, 5,
                                         GEN2_CMA__FRONTERA__32PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 56, 5, GEN2_CMA__FRONTERA__56PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 56, 5,
                                         GEN2_CMA__FRONTERA__56PPN)
            MVP_COLL_TUNING_FINISH_TABLE(scatter)
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_AMD_EPYC_7401_48,
                                        MVP_HCA_MLX_CX_EDR) &&
                   !heterogeneity) {
            /* LLNL Corona */
            MVP_COLL_TUNING_START_TABLE(scatter, 7)
            MVP_COLL_TUNING_ADD_CONF(scatter, 1, 4,
                                     GEN2_CMA__AMD_EPYC_7401_24__1PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 1, 4,
                                         GEN2_CMA__AMD_EPYC_7401_24__1PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 2, 5,
                                     GEN2_CMA__AMD_EPYC_7401_24__2PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 2, 5,
                                         GEN2_CMA__AMD_EPYC_7401_24__2PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 4, 5,
                                     GEN2_CMA__AMD_EPYC_7401_24__4PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 4, 5,
                                         GEN2_CMA__AMD_EPYC_7401_24__4PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 8, 5,
                                     GEN2_CMA__AMD_EPYC_7401_24__8PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 8, 5,
                                         GEN2_CMA__AMD_EPYC_7401_24__8PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 16, 5,
                                     GEN2_CMA__AMD_EPYC_7401_24__16PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 16, 5,
                                         GEN2_CMA__AMD_EPYC_7401_24__16PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 32, 5,
                                     GEN2_CMA__AMD_EPYC_7401_24__32PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 32, 5,
                                         GEN2_CMA__AMD_EPYC_7401_24__32PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 48, 5,
                                     GEN2_CMA__AMD_EPYC_7401_24__48PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 48, 5,
                                         GEN2_CMA__AMD_EPYC_7401_24__48PPN)
            MVP_COLL_TUNING_FINISH_TABLE(scatter)
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_INTEL_XEON_E5_2620_V4_2S_16,
                                        MVP_HCA_MLX_CX_FDR) &&
                   !heterogeneity) {
            /* Frontera RTX */
            MVP_COLL_TUNING_START_TABLE(scatter, 5)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 1, 4,
                GEN2_CMA__MVP_ARCH_INTEL_XEON_E5_2620_V4_2S_16__1PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(
                scatter, 1, 4,
                GEN2_CMA__MVP_ARCH_INTEL_XEON_E5_2620_V4_2S_16__1PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 2, 5,
                GEN2_CMA__MVP_ARCH_INTEL_XEON_E5_2620_V4_2S_16__2PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(
                scatter, 2, 5,
                GEN2_CMA__MVP_ARCH_INTEL_XEON_E5_2620_V4_2S_16__2PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 4, 5,
                GEN2_CMA__MVP_ARCH_INTEL_XEON_E5_2620_V4_2S_16__4PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(
                scatter, 4, 5,
                GEN2_CMA__MVP_ARCH_INTEL_XEON_E5_2620_V4_2S_16__4PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 8, 5,
                GEN2_CMA__MVP_ARCH_INTEL_XEON_E5_2620_V4_2S_16__8PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(
                scatter, 8, 5,
                GEN2_CMA__MVP_ARCH_INTEL_XEON_E5_2620_V4_2S_16__8PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 16, 5,
                GEN2_CMA__MVP_ARCH_INTEL_XEON_E5_2620_V4_2S_16__16PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(
                scatter, 16, 5,
                GEN2_CMA__MVP_ARCH_INTEL_XEON_E5_2620_V4_2S_16__16PPN)
            MVP_COLL_TUNING_FINISH_TABLE(scatter)
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_ARM_CAVIUM_V8_2S_28,
                                        MVP_HCA_MLX_CX_EDR) &&
                   !heterogeneity) {
            /* Mayer */
            MVP_COLL_TUNING_START_TABLE(scatter, 8)
            MVP_COLL_TUNING_ADD_CONF(scatter, 1, 3, GEN2_CMA__MAYER__1PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 1, 3, GEN2_CMA__MAYER__1PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 2, 4, GEN2_CMA__MAYER__2PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 2, 4, GEN2_CMA__MAYER__2PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 4, 4, GEN2_CMA__MAYER__4PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 4, 4, GEN2_CMA__MAYER__4PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 8, 4, GEN2_CMA__MAYER__8PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 8, 4, GEN2_CMA__MAYER__8PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 16, 4, GEN2_CMA__MAYER__16PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 16, 4, GEN2_CMA__MAYER__16PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 28, 4, GEN2_CMA__MAYER__28PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 28, 4, GEN2_CMA__MAYER__28PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 32, 4, GEN2_CMA__MAYER__32PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 32, 4, GEN2_CMA__MAYER__32PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 56, 4, GEN2_CMA__MAYER__56PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 56, 4, GEN2_CMA__MAYER__56PPN)
            MVP_COLL_TUNING_FINISH_TABLE(scatter)
        } else if ((MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                         MVP_ARCH_ARM_CAVIUM_V8_2S_32,
                                         MVP_HCA_MLX_CX_EDR) ||
                    MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                         MVP_ARCH_ARM_FUJITSU_V0_4S_48,
                                         MVP_HCA_MLX_CX_EDR)) &&
                   !heterogeneity) {
            /* Catalyst & Ookami */
            MVP_COLL_TUNING_START_TABLE(scatter, 7)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 1, 5, GEN2_CMA__ARM_CAVIUM_V8_2S_32_MLX_CX_EDR__1PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(
                scatter, 1, 5, GEN2_CMA__ARM_CAVIUM_V8_2S_32_MLX_CX_EDR__1PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 2, 6, GEN2_CMA__ARM_CAVIUM_V8_2S_32_MLX_CX_EDR__2PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(
                scatter, 2, 6, GEN2_CMA__ARM_CAVIUM_V8_2S_32_MLX_CX_EDR__2PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 4, 6, GEN2_CMA__ARM_CAVIUM_V8_2S_32_MLX_CX_EDR__4PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(
                scatter, 4, 6, GEN2_CMA__ARM_CAVIUM_V8_2S_32_MLX_CX_EDR__4PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 8, 6, GEN2_CMA__ARM_CAVIUM_V8_2S_32_MLX_CX_EDR__8PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(
                scatter, 8, 6, GEN2_CMA__ARM_CAVIUM_V8_2S_32_MLX_CX_EDR__8PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 16, 6, GEN2_CMA__ARM_CAVIUM_V8_2S_32_MLX_CX_EDR__16PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(
                scatter, 16, 6, GEN2_CMA__ARM_CAVIUM_V8_2S_32_MLX_CX_EDR__16PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 32, 6, GEN2_CMA__ARM_CAVIUM_V8_2S_32_MLX_CX_EDR__32PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(
                scatter, 32, 6, GEN2_CMA__ARM_CAVIUM_V8_2S_32_MLX_CX_EDR__32PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 64, 6, GEN2_CMA__ARM_CAVIUM_V8_2S_32_MLX_CX_EDR__64PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(
                scatter, 64, 6, GEN2_CMA__ARM_CAVIUM_V8_2S_32_MLX_CX_EDR__64PPN)
            MVP_COLL_TUNING_FINISH_TABLE(scatter)
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_ARM_CAVIUM_V8_2S_28,
                                        MVP_HCA_MLX_CX_FDR) &&
                   !heterogeneity) {
            /* ARM system at Hartree Center */
            MVP_COLL_TUNING_START_TABLE(scatter, 5)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 1, 2, GEN2_CMA__ARM_CAVIUM_V8_2S_28_MLX_CX_FDR__1PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 4, 3, GEN2_CMA__ARM_CAVIUM_V8_2S_28_MLX_CX_FDR__4PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 8, 3, GEN2_CMA__ARM_CAVIUM_V8_2S_28_MLX_CX_FDR__8PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 16, 3, GEN2_CMA__ARM_CAVIUM_V8_2S_28_MLX_CX_FDR__16PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 24, 3, GEN2_CMA__ARM_CAVIUM_V8_2S_28_MLX_CX_FDR__24PPN)
            MVP_COLL_TUNING_FINISH_TABLE(scatter)
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_IBM_POWER8,
                                        MVP_HCA_MLX_CX_EDR) &&
                   !heterogeneity) {
            /* Ray Table */
            MVP_COLL_TUNING_START_TABLE(scatter, 3)
            MVP_COLL_TUNING_ADD_CONF(scatter, 2, 5,
                                     GEN2_CMA__IBM_POWER8_MLX_CX_EDR__2PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 4, 5,
                                     GEN2_CMA__IBM_POWER8_MLX_CX_EDR__4PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 8, 4,
                                     GEN2_CMA__IBM_POWER8_MLX_CX_EDR__8PPN)
            MVP_COLL_TUNING_FINISH_TABLE(scatter)
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_IBM_POWER9,
                                        MVP_HCA_MLX_CX_EDR) &&
                   !heterogeneity) {
            /* Sierra Table: Use table for Ray temporarily */
            MVP_COLL_TUNING_START_TABLE(scatter, 9)
            MVP_COLL_TUNING_ADD_CONF(scatter, 1, 4,
                                     GEN2__IBM_POWER9_MLX_CX_EDR__1PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 1, 4,
                                         GEN2_CMA__IBM_POWER9_MLX_CX_EDR__1PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 2, 5,
                                     GEN2__IBM_POWER9_MLX_CX_EDR__2PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 4, 5,
                                     GEN2__IBM_POWER9_MLX_CX_EDR__4PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 4, 5,
                                         GEN2_CMA__IBM_POWER9_MLX_CX_EDR__4PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 6, 5,
                                     GEN2_CMA__IBM_POWER9_MLX_CX_EDR__6PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 6, 5,
                                         GEN2_CMA__IBM_POWER9_MLX_CX_EDR__6PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 8, 5,
                                     GEN2__IBM_POWER9_MLX_CX_EDR__8PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 8, 5,
                                         GEN2_CMA__IBM_POWER9_MLX_CX_EDR__8PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 16, 5,
                                     GEN2__IBM_POWER9_MLX_CX_EDR__16PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 16, 5,
                                         GEN2_CMA__IBM_POWER9_MLX_CX_EDR__16PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 22, 5,
                                     GEN2__IBM_POWER9_MLX_CX_EDR__22PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 22, 5,
                                         GEN2_CMA__IBM_POWER9_MLX_CX_EDR__22PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 32, 5,
                                     GEN2__IBM_POWER9_MLX_CX_EDR__32PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 32, 5,
                                         GEN2_CMA__IBM_POWER9_MLX_CX_EDR__32PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 44, 5,
                                     GEN2__IBM_POWER9_MLX_CX_EDR__44PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 44, 5,
                                         GEN2_CMA__IBM_POWER9_MLX_CX_EDR__44PPN)
            MVP_COLL_TUNING_FINISH_TABLE(scatter)
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_INTEL_XEON_E5630_8,
                                        MVP_HCA_MLX_CX_QDR) &&
                   !heterogeneity) {
            /*RI Table*/
            MVP_COLL_TUNING_START_TABLE(scatter, 4)
            MVP_COLL_TUNING_ADD_CONF(scatter, 1, 6, GEN2__RI__1PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 1, 6, GEN2_CMA__RI__1PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 2, 7, GEN2__RI__2PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 2, 7, GEN2_CMA__RI__2PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 4, 1, GEN2__RI__4PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 4, 1, GEN2_CMA__RI__4PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 8, 8, GEN2__RI__8PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 8, 8, GEN2_CMA__RI__8PPN)
            MVP_COLL_TUNING_FINISH_TABLE(scatter)
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_INTEL_XEON_E5_2680_V3_2S_24,
                                        MVP_HCA_MLX_CX_FDR) &&
                   !heterogeneity) {
            /*Comet Table*/
            mvp_scatter_indexed_num_ppn_conf = 1;
            mvp_scatter_indexed_thresholds_table =
                MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                               mvp_scatter_indexed_num_ppn_conf,
                           MPL_MEM_COLL);
            table_ptrs = MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                                        mvp_scatter_indexed_num_ppn_conf,
                                    MPL_MEM_COLL);
            mvp_size_scatter_indexed_tuning_table = MPL_malloc(
                sizeof(int) * mvp_scatter_indexed_num_ppn_conf, MPL_MEM_COLL);
            mvp_scatter_indexed_table_ppn_conf = MPL_malloc(
                mvp_scatter_indexed_num_ppn_conf * sizeof(int), MPL_MEM_COLL);

            mvp_scatter_indexed_table_ppn_conf[0] = 24;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_24ppn[] =
                    GEN2__INTEL_XEON_E5_2680_24__MLX_CX_FDR__24PPN;
            /*
            mvp_scatter_indexed_tuning_table
        mvp_tmp_cma_scatter_indexed_thresholds_table_24ppn[] =
                GEN2_CMA__INTEL_XEON_E5_2680_24__MLX_CX_FDR__24PPN;
        #if defined(_SMP_CMA_)
            if (MVP_SMP_USE_CMA) {
              mvp_size_scatter_indexed_tuning_table[0] = 6;
              table_ptrs[0] =
        mvp_tmp_cma_scatter_indexed_thresholds_table_24ppn;
            }
            else {
              mvp_size_scatter_indexed_tuning_table[0] = 6;
              table_ptrs[0] = mvp_tmp_scatter_indexed_thresholds_table_24ppn;
            }
        #else
            */
            mvp_size_scatter_indexed_tuning_table[0] = 6;
            table_ptrs[0] = mvp_tmp_scatter_indexed_thresholds_table_24ppn;
            /*
        #endif
            */

            agg_table_sum = 0;
            for (i = 0; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                agg_table_sum += mvp_size_scatter_indexed_tuning_table[i];
            }
            mvp_scatter_indexed_thresholds_table[0] = MPL_malloc(
                agg_table_sum * sizeof(mvp_scatter_indexed_tuning_table),
                MPL_MEM_COLL);
            MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[0], table_ptrs[0],
                        (sizeof(mvp_scatter_indexed_tuning_table) *
                         mvp_size_scatter_indexed_tuning_table[0]));
            for (i = 1; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                mvp_scatter_indexed_thresholds_table[i] =
                    mvp_scatter_indexed_thresholds_table[i - 1] +
                    mvp_size_scatter_indexed_tuning_table[i - 1];
                MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[i],
                            table_ptrs[i],
                            (sizeof(mvp_scatter_indexed_tuning_table) *
                             mvp_size_scatter_indexed_tuning_table[i]));
            }
            MPL_free(table_ptrs);
            return 0;
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(), MVP_ARCH_ANY,
                                        MVP_HCA_MLX_CX_EDR) &&
                   !heterogeneity) {
            MVP_COLL_TUNING_START_TABLE(scatter, 6)
            MVP_COLL_TUNING_ADD_CONF(scatter, 1, 5, GEN2__RI2__1PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 1, 5, GEN2_CMA__RI2__1PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 2, 6, GEN2__RI2__2PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 2, 6, GEN2_CMA__RI2__2PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 4, 5, GEN2__RI2__4PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 4, 5, GEN2_CMA__RI2__4PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 8, 5, GEN2__RI2__8PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 8, 5, GEN2_CMA__RI2__8PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 16, 5, GEN2__RI2__16PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 16, 5, GEN2_CMA__RI2__16PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 28, 6, GEN2__RI2__28PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 28, 6, GEN2_CMA__RI2__28PPN)
            MVP_COLL_TUNING_FINISH_TABLE(scatter)
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(), MVP_ARCH_ANY,
                                        MVP_HCA_MLX_CX_HDR) &&
                   !heterogeneity) {
            MVP_COLL_TUNING_START_TABLE(scatter, 6)
            MVP_COLL_TUNING_ADD_CONF(scatter, 1, 5, GEN2__RI2__1PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 1, 5, GEN2_CMA__RI2__1PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 2, 6, GEN2__RI2__2PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 2, 6, GEN2_CMA__RI2__2PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 4, 5, GEN2__RI2__4PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 4, 5, GEN2_CMA__RI2__4PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 8, 5, GEN2__RI2__8PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 8, 5, GEN2_CMA__RI2__8PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 16, 5, GEN2__RI2__16PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 16, 5, GEN2_CMA__RI2__16PPN)
            MVP_COLL_TUNING_ADD_CONF(scatter, 28, 6, GEN2__RI2__28PPN)
            MVP_COLL_TUNING_ADD_CONF_CMA(scatter, 28, 6, GEN2_CMA__RI2__28PPN)
            MVP_COLL_TUNING_FINISH_TABLE(scatter)
        } else {
            /*Stampede Table*/
            mvp_scatter_indexed_num_ppn_conf = 3;
            mvp_scatter_indexed_thresholds_table =
                MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                               mvp_scatter_indexed_num_ppn_conf,
                           MPL_MEM_COLL);
            table_ptrs = MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                                        mvp_scatter_indexed_num_ppn_conf,
                                    MPL_MEM_COLL);
            mvp_size_scatter_indexed_tuning_table = MPL_malloc(
                sizeof(int) * mvp_scatter_indexed_num_ppn_conf, MPL_MEM_COLL);
            mvp_scatter_indexed_table_ppn_conf = MPL_malloc(
                mvp_scatter_indexed_num_ppn_conf * sizeof(int), MPL_MEM_COLL);

            mvp_scatter_indexed_table_ppn_conf[0] = 1;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_1ppn[] =
                    GEN2__INTEL_XEON_E5_2680_16__MLX_CX_FDR__1PPN;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_cma_scatter_indexed_thresholds_table_1ppn[] =
                    GEN2_CMA__INTEL_XEON_E5_2680_16__MLX_CX_FDR__1PPN;
#if defined(_SMP_CMA_)
            if (MVP_SMP_USE_CMA) {
                mvp_size_scatter_indexed_tuning_table[0] = 5;
                table_ptrs[0] =
                    mvp_tmp_cma_scatter_indexed_thresholds_table_1ppn;
            } else {
                mvp_size_scatter_indexed_tuning_table[0] = 5;
                table_ptrs[0] = mvp_tmp_scatter_indexed_thresholds_table_1ppn;
            }
#else
            mvp_size_scatter_indexed_tuning_table[0] = 5;
            table_ptrs[0] = mvp_tmp_scatter_indexed_thresholds_table_1ppn;
#endif

            mvp_scatter_indexed_table_ppn_conf[1] = 2;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_2ppn[] =
                    GEN2__INTEL_XEON_E5_2680_16__MLX_CX_FDR__2PPN;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_cma_scatter_indexed_thresholds_table_2ppn[] =
                    GEN2_CMA__INTEL_XEON_E5_2680_16__MLX_CX_FDR__2PPN;
#if defined(_SMP_CMA_)
            if (MVP_SMP_USE_CMA) {
                mvp_size_scatter_indexed_tuning_table[1] = 6;
                table_ptrs[1] =
                    mvp_tmp_cma_scatter_indexed_thresholds_table_2ppn;
            } else {
                mvp_size_scatter_indexed_tuning_table[1] = 6;
                table_ptrs[1] = mvp_tmp_scatter_indexed_thresholds_table_2ppn;
            }
#else
            mvp_size_scatter_indexed_tuning_table[1] = 6;
            table_ptrs[1] = mvp_tmp_scatter_indexed_thresholds_table_2ppn;
#endif

            mvp_scatter_indexed_table_ppn_conf[2] = 16;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_cma_scatter_indexed_thresholds_table_16ppn[] =
                    GEN2_CMA__INTEL_XEON_E5_2680_16__MLX_CX_FDR__16PPN;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_16ppn[] =
                    GEN2__INTEL_XEON_E5_2680_16__MLX_CX_FDR__16PPN;
#if defined(_SMP_CMA_)
            if (MVP_SMP_USE_CMA) {
                mvp_size_scatter_indexed_tuning_table[2] = 6;
                table_ptrs[2] =
                    mvp_tmp_cma_scatter_indexed_thresholds_table_16ppn;
            } else {
                mvp_size_scatter_indexed_tuning_table[2] = 6;
                table_ptrs[2] = mvp_tmp_scatter_indexed_thresholds_table_16ppn;
            }
#else
            mvp_size_scatter_indexed_tuning_table[2] = 6;
            table_ptrs[2] = mvp_tmp_scatter_indexed_thresholds_table_16ppn;
#endif

            agg_table_sum = 0;
            for (i = 0; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                agg_table_sum += mvp_size_scatter_indexed_tuning_table[i];
            }
            mvp_scatter_indexed_thresholds_table[0] = MPL_malloc(
                agg_table_sum * sizeof(mvp_scatter_indexed_tuning_table),
                MPL_MEM_COLL);
            MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[0], table_ptrs[0],
                        (sizeof(mvp_scatter_indexed_tuning_table) *
                         mvp_size_scatter_indexed_tuning_table[0]));
            for (i = 1; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                mvp_scatter_indexed_thresholds_table[i] =
                    mvp_scatter_indexed_thresholds_table[i - 1] +
                    mvp_size_scatter_indexed_tuning_table[i - 1];
                MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[i],
                            table_ptrs[i],
                            (sizeof(mvp_scatter_indexed_tuning_table) *
                             mvp_size_scatter_indexed_tuning_table[i]));
            }
            MPL_free(table_ptrs);
            return 0;
        }
#elif defined(CHANNEL_NEMESIS_IB)
        if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                 MVP_ARCH_AMD_OPTERON_6136_32,
                                 MVP_HCA_MLX_CX_QDR) &&
            !heterogeneity) {
            /*Trestles Table*/
            mvp_scatter_indexed_num_ppn_conf = 3;
            mvp_scatter_indexed_thresholds_table =
                MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                               mvp_scatter_indexed_num_ppn_conf,
                           MPL_MEM_COLL);
            table_ptrs = MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                                        mvp_scatter_indexed_num_ppn_conf,
                                    MPL_MEM_COLL);
            mvp_size_scatter_indexed_tuning_table = MPL_malloc(
                sizeof(int) * mvp_scatter_indexed_num_ppn_conf, MPL_MEM_COLL);
            mvp_scatter_indexed_table_ppn_conf = MPL_malloc(
                mvp_scatter_indexed_num_ppn_conf * sizeof(int), MPL_MEM_COLL);

            mvp_scatter_indexed_table_ppn_conf[0] = 1;
            mvp_size_scatter_indexed_tuning_table[0] = 4;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_1ppn[] =
                    NEMESIS__AMD_OPTERON_6136_32__MLX_CX_QDR__1PPN
                        table_ptrs[0] =
                            mvp_tmp_scatter_indexed_thresholds_table_1ppn;

            mvp_scatter_indexed_table_ppn_conf[1] = 2;
            mvp_size_scatter_indexed_tuning_table[1] = 3;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_2ppn[] =
                    NEMESIS__AMD_OPTERON_6136_32__MLX_CX_QDR__2PPN
                        table_ptrs[1] =
                            mvp_tmp_scatter_indexed_thresholds_table_2ppn;

            mvp_scatter_indexed_table_ppn_conf[2] = 32;
            mvp_size_scatter_indexed_tuning_table[2] = 2;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_32ppn[] =
                    NEMESIS__AMD_OPTERON_6136_32__MLX_CX_QDR__32PPN
                        table_ptrs[2] =
                            mvp_tmp_scatter_indexed_thresholds_table_32ppn;

            agg_table_sum = 0;
            for (i = 0; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                agg_table_sum += mvp_size_scatter_indexed_tuning_table[i];
            }
            mvp_scatter_indexed_thresholds_table[0] = MPL_malloc(
                agg_table_sum * sizeof(mvp_scatter_indexed_tuning_table),
                MPL_MEM_COLL);
            MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[0], table_ptrs[0],
                        (sizeof(mvp_scatter_indexed_tuning_table) *
                         mvp_size_scatter_indexed_tuning_table[0]));
            for (i = 1; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                mvp_scatter_indexed_thresholds_table[i] =
                    mvp_scatter_indexed_thresholds_table[i - 1] +
                    mvp_size_scatter_indexed_tuning_table[i - 1];
                MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[i],
                            table_ptrs[i],
                            (sizeof(mvp_scatter_indexed_tuning_table) *
                             mvp_size_scatter_indexed_tuning_table[i]));
            }
            MPL_free(table_ptrs);
            return 0;
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_INTEL_XEON_E5_2670_16,
                                        MVP_HCA_MLX_CX_QDR) &&
                   !heterogeneity) {
            /*Gordon Table*/
            mvp_scatter_indexed_num_ppn_conf = 3;
            mvp_scatter_indexed_thresholds_table =
                MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                               mvp_scatter_indexed_num_ppn_conf,
                           MPL_MEM_COLL);
            table_ptrs = MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                                        mvp_scatter_indexed_num_ppn_conf,
                                    MPL_MEM_COLL);
            mvp_size_scatter_indexed_tuning_table = MPL_malloc(
                sizeof(int) * mvp_scatter_indexed_num_ppn_conf, MPL_MEM_COLL);
            mvp_scatter_indexed_table_ppn_conf = MPL_malloc(
                mvp_scatter_indexed_num_ppn_conf * sizeof(int), MPL_MEM_COLL);

            mvp_scatter_indexed_table_ppn_conf[0] = 1;
            mvp_size_scatter_indexed_tuning_table[0] = 2;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_1ppn[] =
                    NEMESIS__INTEL_XEON_E5_2670_16__MLX_CX_QDR_1PPN
                        table_ptrs[0] =
                            mvp_tmp_scatter_indexed_thresholds_table_1ppn;

            mvp_scatter_indexed_table_ppn_conf[1] = 2;
            mvp_size_scatter_indexed_tuning_table[1] = 2;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_2ppn[] =
                    NEMESIS__INTEL_XEON_E5_2670_16__MLX_CX_QDR_2PPN
                        table_ptrs[1] =
                            mvp_tmp_scatter_indexed_thresholds_table_2ppn;

            mvp_scatter_indexed_table_ppn_conf[2] = 16;
            mvp_size_scatter_indexed_tuning_table[2] = 4;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_16ppn[] =
                    NEMESIS__INTEL_XEON_E5_2670_16__MLX_CX_QDR_16PPN
                        table_ptrs[2] =
                            mvp_tmp_scatter_indexed_thresholds_table_16ppn;

            agg_table_sum = 0;
            for (i = 0; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                agg_table_sum += mvp_size_scatter_indexed_tuning_table[i];
            }
            mvp_scatter_indexed_thresholds_table[0] = MPL_malloc(
                agg_table_sum * sizeof(mvp_scatter_indexed_tuning_table),
                MPL_MEM_COLL);
            MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[0], table_ptrs[0],
                        (sizeof(mvp_scatter_indexed_tuning_table) *
                         mvp_size_scatter_indexed_tuning_table[0]));
            for (i = 1; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                mvp_scatter_indexed_thresholds_table[i] =
                    mvp_scatter_indexed_thresholds_table[i - 1] +
                    mvp_size_scatter_indexed_tuning_table[i - 1];
                MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[i],
                            table_ptrs[i],
                            (sizeof(mvp_scatter_indexed_tuning_table) *
                             mvp_size_scatter_indexed_tuning_table[i]));
            }
            MPL_free(table_ptrs);
            return 0;
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_INTEL_XEON_E5_2670_16,
                                        MVP_HCA_MLX_CX_FDR) &&
                   !heterogeneity) {
            /*Yellowstone Table*/
            mvp_scatter_indexed_num_ppn_conf = 3;
            mvp_scatter_indexed_thresholds_table =
                MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                               mvp_scatter_indexed_num_ppn_conf,
                           MPL_MEM_COLL);
            table_ptrs = MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                                        mvp_scatter_indexed_num_ppn_conf,
                                    MPL_MEM_COLL);
            mvp_size_scatter_indexed_tuning_table = MPL_malloc(
                sizeof(int) * mvp_scatter_indexed_num_ppn_conf, MPL_MEM_COLL);
            mvp_scatter_indexed_table_ppn_conf = MPL_malloc(
                mvp_scatter_indexed_num_ppn_conf * sizeof(int), MPL_MEM_COLL);

            mvp_scatter_indexed_table_ppn_conf[0] = 1;
            mvp_size_scatter_indexed_tuning_table[0] = 2;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_1ppn[] =
                    NEMESIS__INTEL_XEON_E5_2670_16__MLX_CX_FDR__1PPN
                        table_ptrs[0] =
                            mvp_tmp_scatter_indexed_thresholds_table_1ppn;

            mvp_scatter_indexed_table_ppn_conf[1] = 2;
            mvp_size_scatter_indexed_tuning_table[1] = 2;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_2ppn[] =
                    NEMESIS__INTEL_XEON_E5_2670_16__MLX_CX_FDR__2PPN
                        table_ptrs[1] =
                            mvp_tmp_scatter_indexed_thresholds_table_2ppn;

            mvp_scatter_indexed_table_ppn_conf[2] = 16;
            mvp_size_scatter_indexed_tuning_table[2] = 5;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_16ppn[] =
                    NEMESIS__INTEL_XEON_E5_2670_16__MLX_CX_FDR__16PPN
                        table_ptrs[2] =
                            mvp_tmp_scatter_indexed_thresholds_table_16ppn;

            agg_table_sum = 0;
            for (i = 0; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                agg_table_sum += mvp_size_scatter_indexed_tuning_table[i];
            }
            mvp_scatter_indexed_thresholds_table[0] = MPL_malloc(
                agg_table_sum * sizeof(mvp_scatter_indexed_tuning_table),
                MPL_MEM_COLL);
            MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[0], table_ptrs[0],
                        (sizeof(mvp_scatter_indexed_tuning_table) *
                         mvp_size_scatter_indexed_tuning_table[0]));
            for (i = 1; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                mvp_scatter_indexed_thresholds_table[i] =
                    mvp_scatter_indexed_thresholds_table[i - 1] +
                    mvp_size_scatter_indexed_tuning_table[i - 1];
                MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[i],
                            table_ptrs[i],
                            (sizeof(mvp_scatter_indexed_tuning_table) *
                             mvp_size_scatter_indexed_tuning_table[i]));
            }
            MPL_free(table_ptrs);
            return 0;
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_INTEL_XEON_E5_2680_16,
                                        MVP_HCA_MLX_CX_FDR) &&
                   !heterogeneity) {
            /*Stampede Table*/
            mvp_scatter_indexed_num_ppn_conf = 3;
            mvp_scatter_indexed_thresholds_table =
                MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                               mvp_scatter_indexed_num_ppn_conf,
                           MPL_MEM_COLL);
            table_ptrs = MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                                        mvp_scatter_indexed_num_ppn_conf,
                                    MPL_MEM_COLL);
            mvp_size_scatter_indexed_tuning_table = MPL_malloc(
                sizeof(int) * mvp_scatter_indexed_num_ppn_conf, MPL_MEM_COLL);
            mvp_scatter_indexed_table_ppn_conf = MPL_malloc(
                mvp_scatter_indexed_num_ppn_conf * sizeof(int), MPL_MEM_COLL);

            mvp_scatter_indexed_table_ppn_conf[0] = 1;
            mvp_size_scatter_indexed_tuning_table[0] = 5;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_1ppn[] =
                    NEMESIS__INTEL_XEON_E5_2680_16__MLX_CX_FDR__1PPN
                        table_ptrs[0] =
                            mvp_tmp_scatter_indexed_thresholds_table_1ppn;

            mvp_scatter_indexed_table_ppn_conf[1] = 2;
            mvp_size_scatter_indexed_tuning_table[1] = 5;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_2ppn[] =
                    NEMESIS__INTEL_XEON_E5_2680_16__MLX_CX_FDR__2PPN
                        table_ptrs[1] =
                            mvp_tmp_scatter_indexed_thresholds_table_2ppn;

            mvp_scatter_indexed_table_ppn_conf[2] = 16;
            mvp_size_scatter_indexed_tuning_table[2] = 7;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_16ppn[] =
                    NEMESIS__INTEL_XEON_E5_2680_16__MLX_CX_FDR__16PPN
                        table_ptrs[2] =
                            mvp_tmp_scatter_indexed_thresholds_table_16ppn;

            agg_table_sum = 0;
            for (i = 0; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                agg_table_sum += mvp_size_scatter_indexed_tuning_table[i];
            }
            mvp_scatter_indexed_thresholds_table[0] = MPL_malloc(
                agg_table_sum * sizeof(mvp_scatter_indexed_tuning_table),
                MPL_MEM_COLL);
            MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[0], table_ptrs[0],
                        (sizeof(mvp_scatter_indexed_tuning_table) *
                         mvp_size_scatter_indexed_tuning_table[0]));
            for (i = 1; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                mvp_scatter_indexed_thresholds_table[i] =
                    mvp_scatter_indexed_thresholds_table[i - 1] +
                    mvp_size_scatter_indexed_tuning_table[i - 1];
                MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[i],
                            table_ptrs[i],
                            (sizeof(mvp_scatter_indexed_tuning_table) *
                             mvp_size_scatter_indexed_tuning_table[i]));
            }
            MPL_free(table_ptrs);
            return 0;
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_INTEL_XEON_E5630_8,
                                        MVP_HCA_MLX_CX_QDR) &&
                   !heterogeneity) {
            /*RI Table*/
            mvp_scatter_indexed_num_ppn_conf = 3;
            mvp_scatter_indexed_thresholds_table =
                MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                               mvp_scatter_indexed_num_ppn_conf,
                           MPL_MEM_COLL);
            table_ptrs = MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                                        mvp_scatter_indexed_num_ppn_conf,
                                    MPL_MEM_COLL);
            mvp_size_scatter_indexed_tuning_table = MPL_malloc(
                sizeof(int) * mvp_scatter_indexed_num_ppn_conf, MPL_MEM_COLL);
            mvp_scatter_indexed_table_ppn_conf = MPL_malloc(
                mvp_scatter_indexed_num_ppn_conf * sizeof(int), MPL_MEM_COLL);

            mvp_scatter_indexed_table_ppn_conf[0] = 1;
            mvp_size_scatter_indexed_tuning_table[0] = 2;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_1ppn[] =
                    NEMESIS__RI__1PPN table_ptrs[0] =
                        mvp_tmp_scatter_indexed_thresholds_table_1ppn;

            mvp_scatter_indexed_table_ppn_conf[1] = 2;
            mvp_size_scatter_indexed_tuning_table[1] = 2;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_2ppn[] =
                    NEMESIS__RI__2PPN table_ptrs[1] =
                        mvp_tmp_scatter_indexed_thresholds_table_2ppn;

            mvp_scatter_indexed_table_ppn_conf[2] = 8;
            mvp_size_scatter_indexed_tuning_table[2] = 8;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_8ppn[] =
                    NEMESIS__RI__8PPN table_ptrs[2] =
                        mvp_tmp_scatter_indexed_thresholds_table_8ppn;

            agg_table_sum = 0;
            for (i = 0; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                agg_table_sum += mvp_size_scatter_indexed_tuning_table[i];
            }
            mvp_scatter_indexed_thresholds_table[0] = MPL_malloc(
                agg_table_sum * sizeof(mvp_scatter_indexed_tuning_table),
                MPL_MEM_COLL);
            MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[0], table_ptrs[0],
                        (sizeof(mvp_scatter_indexed_tuning_table) *
                         mvp_size_scatter_indexed_tuning_table[0]));
            for (i = 1; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                mvp_scatter_indexed_thresholds_table[i] =
                    mvp_scatter_indexed_thresholds_table[i - 1] +
                    mvp_size_scatter_indexed_tuning_table[i - 1];
                MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[i],
                            table_ptrs[i],
                            (sizeof(mvp_scatter_indexed_tuning_table) *
                             mvp_size_scatter_indexed_tuning_table[i]));
            }
            MPL_free(table_ptrs);
            return 0;
        } else {
            /*Stampede Table*/
            mvp_scatter_indexed_num_ppn_conf = 3;
            mvp_scatter_indexed_thresholds_table =
                MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                               mvp_scatter_indexed_num_ppn_conf,
                           MPL_MEM_COLL);
            table_ptrs = MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                                        mvp_scatter_indexed_num_ppn_conf,
                                    MPL_MEM_COLL);
            mvp_size_scatter_indexed_tuning_table = MPL_malloc(
                sizeof(int) * mvp_scatter_indexed_num_ppn_conf, MPL_MEM_COLL);
            mvp_scatter_indexed_table_ppn_conf = MPL_malloc(
                mvp_scatter_indexed_num_ppn_conf * sizeof(int), MPL_MEM_COLL);

            mvp_scatter_indexed_table_ppn_conf[0] = 1;
            mvp_size_scatter_indexed_tuning_table[0] = 5;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_1ppn[] =
                    NEMESIS__INTEL_XEON_E5_2680_16__MLX_CX_FDR__1PPN
                        table_ptrs[0] =
                            mvp_tmp_scatter_indexed_thresholds_table_1ppn;

            mvp_scatter_indexed_table_ppn_conf[1] = 2;
            mvp_size_scatter_indexed_tuning_table[1] = 5;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_2ppn[] =
                    NEMESIS__INTEL_XEON_E5_2680_16__MLX_CX_FDR__2PPN
                        table_ptrs[1] =
                            mvp_tmp_scatter_indexed_thresholds_table_2ppn;

            mvp_scatter_indexed_table_ppn_conf[2] = 16;
            mvp_size_scatter_indexed_tuning_table[2] = 7;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_16ppn[] =
                    NEMESIS__INTEL_XEON_E5_2680_16__MLX_CX_FDR__16PPN
                        table_ptrs[2] =
                            mvp_tmp_scatter_indexed_thresholds_table_16ppn;

            agg_table_sum = 0;
            for (i = 0; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                agg_table_sum += mvp_size_scatter_indexed_tuning_table[i];
            }
            mvp_scatter_indexed_thresholds_table[0] = MPL_malloc(
                agg_table_sum * sizeof(mvp_scatter_indexed_tuning_table),
                MPL_MEM_COLL);
            MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[0], table_ptrs[0],
                        (sizeof(mvp_scatter_indexed_tuning_table) *
                         mvp_size_scatter_indexed_tuning_table[0]));
            for (i = 1; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                mvp_scatter_indexed_thresholds_table[i] =
                    mvp_scatter_indexed_thresholds_table[i - 1] +
                    mvp_size_scatter_indexed_tuning_table[i - 1];
                MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[i],
                            table_ptrs[i],
                            (sizeof(mvp_scatter_indexed_tuning_table) *
                             mvp_size_scatter_indexed_tuning_table[i]));
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
            mvp_scatter_indexed_num_ppn_conf = 2;
            mvp_scatter_indexed_thresholds_table =
                MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                               mvp_scatter_indexed_num_ppn_conf,
                           MPL_MEM_COLL);
            table_ptrs = MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                                        mvp_scatter_indexed_num_ppn_conf,
                                    MPL_MEM_COLL);
            mvp_size_scatter_indexed_tuning_table = MPL_malloc(
                sizeof(int) * mvp_scatter_indexed_num_ppn_conf, MPL_MEM_COLL);
            mvp_scatter_indexed_table_ppn_conf = MPL_malloc(
                mvp_scatter_indexed_num_ppn_conf * sizeof(int), MPL_MEM_COLL);

            mvp_scatter_indexed_table_ppn_conf[0] = 1;
            mvp_size_scatter_indexed_tuning_table[0] = 5;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_1ppn[] =
                    PSM__INTEL_XEON_X5650_12__MVP_HCA_QLGIC_QIB__1PPN;
            table_ptrs[0] = mvp_tmp_scatter_indexed_thresholds_table_1ppn;

            mvp_scatter_indexed_table_ppn_conf[1] = 12;
            mvp_size_scatter_indexed_tuning_table[1] = 6;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_12ppn[] =
                    PSM__INTEL_XEON_X5650_12__MVP_HCA_QLGIC_QIB__12PPN;
            table_ptrs[1] = mvp_tmp_scatter_indexed_thresholds_table_12ppn;

            agg_table_sum = 0;
            for (i = 0; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                agg_table_sum += mvp_size_scatter_indexed_tuning_table[i];
            }
            mvp_scatter_indexed_thresholds_table[0] = MPL_malloc(
                agg_table_sum * sizeof(mvp_scatter_indexed_tuning_table),
                MPL_MEM_COLL);
            MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[0], table_ptrs[0],
                        (sizeof(mvp_scatter_indexed_tuning_table) *
                         mvp_size_scatter_indexed_tuning_table[0]));
            for (i = 1; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                mvp_scatter_indexed_thresholds_table[i] =
                    mvp_scatter_indexed_thresholds_table[i - 1] +
                    mvp_size_scatter_indexed_tuning_table[i - 1];
                MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[i],
                            table_ptrs[i],
                            (sizeof(mvp_scatter_indexed_tuning_table) *
                             mvp_size_scatter_indexed_tuning_table[i]));
            }
            MPL_free(table_ptrs);
            return 0;
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_INTEL_XEON_E5_2695_V3_2S_28,
                                        MVP_HCA_INTEL_HFI1) &&
                   !heterogeneity) {
            /*Bridges Table*/
            MVP_COLL_TUNING_START_TABLE(scatter, 6)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 1, 4,
                PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__1PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 2, 5,
                PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__2PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 4, 5,
                PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__4PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 8, 5,
                PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__8PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 16, 5,
                PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__16PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 28, 5,
                PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__28PPN)
            MVP_COLL_TUNING_FINISH_TABLE(scatter)
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_INTEL_XEON_E5_2695_V4_2S_36,
                                        MVP_HCA_INTEL_HFI1) &&
                   !heterogeneity) {
            /* Bebop/Jade/Opal Table */
            MVP_COLL_TUNING_START_TABLE(scatter, 5)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 1, 5,
                PSM__INTEL_XEON_E5_2695_V4_2S_36_INTEL_HFI_100__1PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 4, 5,
                PSM__INTEL_XEON_E5_2695_V4_2S_36_INTEL_HFI_100__4PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 8, 5,
                PSM__INTEL_XEON_E5_2695_V4_2S_36_INTEL_HFI_100__8PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 16, 5,
                PSM__INTEL_XEON_E5_2695_V4_2S_36_INTEL_HFI_100__16PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 36, 5,
                PSM__INTEL_XEON_E5_2695_V4_2S_36_INTEL_HFI_100__36PPN)
            MVP_COLL_TUNING_FINISH_TABLE(scatter)
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_INTEL_XEON_PHI_7250,
                                        MVP_HCA_INTEL_HFI1) &&
                   !heterogeneity) {
            /* TACC-KNL Table */
            MVP_COLL_TUNING_START_TABLE(scatter, 6)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 1, 5, PSM__INTEL_XEON_PHI_7250_68_INTEL_HFI_100__1PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 4, 6, PSM__INTEL_XEON_PHI_7250_68_INTEL_HFI_100__4PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 8, 5, PSM__INTEL_XEON_PHI_7250_68_INTEL_HFI_100__8PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 16, 6,
                PSM__INTEL_XEON_PHI_7250_68_INTEL_HFI_100__16PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 32, 5,
                PSM__INTEL_XEON_PHI_7250_68_INTEL_HFI_100__32PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 64, 4,
                PSM__INTEL_XEON_PHI_7250_68_INTEL_HFI_100__64PPN)
            MVP_COLL_TUNING_FINISH_TABLE(scatter)
        } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                        MVP_ARCH_INTEL_PLATINUM_8170_2S_52,
                                        MVP_HCA_INTEL_HFI1) &&
                   !heterogeneity) {
            /* TACC-Skylake Table */
            MVP_COLL_TUNING_START_TABLE(scatter, 9)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 1, 4,
                PSM__INTEL_PLATINUM_8170_2S_52_INTEL_HFI_100__1PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 2, 5,
                PSM__INTEL_PLATINUM_8170_2S_52_INTEL_HFI_100__2PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 4, 5,
                PSM__INTEL_PLATINUM_8170_2S_52_INTEL_HFI_100__4PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 8, 5,
                PSM__INTEL_PLATINUM_8170_2S_52_INTEL_HFI_100__8PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 16, 5,
                PSM__INTEL_PLATINUM_8170_2S_52_INTEL_HFI_100__16PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 24, 5,
                PSM__INTEL_PLATINUM_8170_2S_52_INTEL_HFI_100__24PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 26, 4,
                PSM__INTEL_PLATINUM_8170_2S_52_INTEL_HFI_100__26PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 48, 5,
                PSM__INTEL_PLATINUM_8170_2S_52_INTEL_HFI_100__48PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 52, 4,
                PSM__INTEL_PLATINUM_8170_2S_52_INTEL_HFI_100__52PPN)
            MVP_COLL_TUNING_FINISH_TABLE(scatter)
        } else {
            /*default psm table: Bridges Table*/
            MVP_COLL_TUNING_START_TABLE(scatter, 6)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 1, 4,
                PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__1PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 2, 5,
                PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__2PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 4, 5,
                PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__4PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 8, 5,
                PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__8PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 16, 5,
                PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__16PPN)
            MVP_COLL_TUNING_ADD_CONF(
                scatter, 28, 5,
                PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__28PPN)
            MVP_COLL_TUNING_FINISH_TABLE(scatter)
        }
#endif /* !_MVP_CH4_OVERRIDE_ */
        {
            /*Stampede Table*/
            mvp_scatter_indexed_num_ppn_conf = 3;
            mvp_scatter_indexed_thresholds_table =
                MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                               mvp_scatter_indexed_num_ppn_conf,
                           MPL_MEM_COLL);
            table_ptrs = MPL_malloc(sizeof(mvp_scatter_indexed_tuning_table *) *
                                        mvp_scatter_indexed_num_ppn_conf,
                                    MPL_MEM_COLL);
            mvp_size_scatter_indexed_tuning_table = MPL_malloc(
                sizeof(int) * mvp_scatter_indexed_num_ppn_conf, MPL_MEM_COLL);
            mvp_scatter_indexed_table_ppn_conf = MPL_malloc(
                mvp_scatter_indexed_num_ppn_conf * sizeof(int), MPL_MEM_COLL);

            mvp_scatter_indexed_table_ppn_conf[0] = 1;
            mvp_size_scatter_indexed_tuning_table[0] = 5;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_1ppn[] =
                    NEMESIS__INTEL_XEON_E5_2680_16__MLX_CX_FDR__1PPN
                        table_ptrs[0] =
                            mvp_tmp_scatter_indexed_thresholds_table_1ppn;

            mvp_scatter_indexed_table_ppn_conf[1] = 2;
            mvp_size_scatter_indexed_tuning_table[1] = 5;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_2ppn[] =
                    NEMESIS__INTEL_XEON_E5_2680_16__MLX_CX_FDR__2PPN
                        table_ptrs[1] =
                            mvp_tmp_scatter_indexed_thresholds_table_2ppn;

            mvp_scatter_indexed_table_ppn_conf[2] = 16;
            mvp_size_scatter_indexed_tuning_table[2] = 7;
            mvp_scatter_indexed_tuning_table
                mvp_tmp_scatter_indexed_thresholds_table_16ppn[] =
                    NEMESIS__INTEL_XEON_E5_2680_16__MLX_CX_FDR__16PPN
                        table_ptrs[2] =
                            mvp_tmp_scatter_indexed_thresholds_table_16ppn;

            agg_table_sum = 0;
            for (i = 0; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                agg_table_sum += mvp_size_scatter_indexed_tuning_table[i];
            }
            mvp_scatter_indexed_thresholds_table[0] = MPL_malloc(
                agg_table_sum * sizeof(mvp_scatter_indexed_tuning_table),
                MPL_MEM_COLL);
            MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[0], table_ptrs[0],
                        (sizeof(mvp_scatter_indexed_tuning_table) *
                         mvp_size_scatter_indexed_tuning_table[0]));
            for (i = 1; i < mvp_scatter_indexed_num_ppn_conf; i++) {
                mvp_scatter_indexed_thresholds_table[i] =
                    mvp_scatter_indexed_thresholds_table[i - 1] +
                    mvp_size_scatter_indexed_tuning_table[i - 1];
                MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[i],
                            table_ptrs[i],
                            (sizeof(mvp_scatter_indexed_tuning_table) *
                             mvp_size_scatter_indexed_tuning_table[i]));
            }
            MPL_free(table_ptrs);
            return 0;
        }
}

void MVP_cleanup_scatter_tuning_table()
{
        MPL_free(mvp_scatter_indexed_thresholds_table[0]);
        MPL_free(mvp_scatter_indexed_table_ppn_conf);
        MPL_free(mvp_size_scatter_indexed_tuning_table);
        if (mvp_scatter_indexed_thresholds_table != NULL) {
            MPL_free(mvp_scatter_indexed_thresholds_table);
        }
}

/* Return the number of separator inside a string */
static int count_sep(const char *string)
{
    return *string == '\0' ? 0 : (count_sep(string + 1) + (*string == ','));
}

int MVP_internode_Scatter_is_define(const char *mvp_user_scatter_inter,
                                    const char *mvp_user_scatter_intra)
{
    int i = 0;
    int nb_element = count_sep(mvp_user_scatter_inter) + 1;

        /* If one scatter tuning table is already defined */
        if (mvp_scatter_indexed_thresholds_table != NULL) {
            if (mvp_scatter_indexed_thresholds_table[0] != NULL) {
                MPL_free(mvp_scatter_indexed_thresholds_table[0]);
            }
            MPL_free(mvp_scatter_indexed_thresholds_table);
        }

        mvp_scatter_indexed_tuning_table
            mvp_tmp_scatter_indexed_thresholds_table[1];
        mvp_scatter_indexed_num_ppn_conf = 1;
        if (mvp_size_scatter_indexed_tuning_table == NULL) {
            mvp_size_scatter_indexed_tuning_table = MPL_malloc(
                mvp_scatter_indexed_num_ppn_conf * sizeof(int), MPL_MEM_COLL);
        }
        mvp_size_scatter_indexed_tuning_table[0] = 1;

        if (mvp_scatter_indexed_table_ppn_conf == NULL) {
            mvp_scatter_indexed_table_ppn_conf = MPL_malloc(
                mvp_scatter_indexed_num_ppn_conf * sizeof(int), MPL_MEM_COLL);
        }
        /* -1 indicates user defined algorithm */
        mvp_scatter_indexed_table_ppn_conf[0] = -1;

        /* We realloc the space for the new scatter tuning table */
        mvp_scatter_indexed_thresholds_table =
            MPL_malloc(mvp_scatter_indexed_num_ppn_conf *
                           sizeof(mvp_scatter_indexed_tuning_table *),
                       MPL_MEM_COLL);
        mvp_scatter_indexed_thresholds_table[0] =
            MPL_malloc(mvp_size_scatter_indexed_tuning_table[0] *
                           sizeof(mvp_scatter_indexed_tuning_table),
                       MPL_MEM_COLL);

        if (nb_element == 1) {
            mvp_tmp_scatter_indexed_thresholds_table[0].numproc = 1;
            mvp_tmp_scatter_indexed_thresholds_table[0].size_inter_table = 1;
            mvp_tmp_scatter_indexed_thresholds_table[0].size_intra_table = 1;
            mvp_tmp_scatter_indexed_thresholds_table[0].inter_leader[0].msg_sz =
                1;
            mvp_tmp_scatter_indexed_thresholds_table[0].intra_node[0].msg_sz =
                1;

            switch (atoi(mvp_user_scatter_inter)) {
                case SCATTER_BINOMIAL:
                    mvp_tmp_scatter_indexed_thresholds_table[0]
                        .inter_leader[0]
                        .MVP_pt_Scatter_function = &MPIR_Scatter_MVP_Binomial;
                    break;
                case SCATTER_DIRECT:
                    mvp_tmp_scatter_indexed_thresholds_table[0]
                        .inter_leader[0]
                        .MVP_pt_Scatter_function = &MPIR_Scatter_MVP_Direct;
                    break;
                case SCATTER_TWO_LEVEL_BINOMIAL:
                    mvp_tmp_scatter_indexed_thresholds_table[0]
                        .inter_leader[0]
                        .MVP_pt_Scatter_function =
                        &MPIR_Scatter_MVP_two_level_Binomial;
                    break;
                case SCATTER_TWO_LEVEL_DIRECT:
                    mvp_tmp_scatter_indexed_thresholds_table[0]
                        .inter_leader[0]
                        .MVP_pt_Scatter_function =
                        &MPIR_Scatter_MVP_two_level_Direct;
                    break;
#if defined(_MCST_SUPPORT_)
                case SCATTER_MCAST:
                    mvp_tmp_scatter_indexed_thresholds_table[0]
                        .inter_leader[0]
                        .MVP_pt_Scatter_function = &MPIR_Scatter_mcst_wrap_MVP;
                    break;
#endif /* #if defined(_MCST_SUPPORT_) */
                default:
                    mvp_tmp_scatter_indexed_thresholds_table[0]
                        .inter_leader[0]
                        .MVP_pt_Scatter_function = &MPIR_Scatter_MVP_Binomial;
            }
        }
        mvp_tmp_scatter_indexed_thresholds_table[0].size_intra_table = 1;

        if (mvp_user_scatter_intra != NULL) {
            i = 0;
            nb_element = count_sep(mvp_user_scatter_intra) + 1;
            if (nb_element == 1) {
                mvp_tmp_scatter_indexed_thresholds_table[0].size_intra_table =
                    1;
                mvp_tmp_scatter_indexed_thresholds_table[0]
                    .intra_node[0]
                    .msg_sz = 1;

                switch (atoi(mvp_user_scatter_intra)) {
                    case SCATTER_DIRECT:
                        mvp_tmp_scatter_indexed_thresholds_table[0]
                            .intra_node[0]
                            .MVP_pt_Scatter_function = &MPIR_Scatter_MVP_Direct;
                        break;
                    case SCATTER_BINOMIAL:
                        mvp_tmp_scatter_indexed_thresholds_table[0]
                            .intra_node[0]
                            .MVP_pt_Scatter_function =
                            &MPIR_Scatter_MVP_Binomial;
                        break;
                    default:
                        mvp_tmp_scatter_indexed_thresholds_table[0]
                            .intra_node[0]
                            .MVP_pt_Scatter_function = &MPIR_Scatter_MVP_Direct;
                }
            }
        } else {
            mvp_tmp_scatter_indexed_thresholds_table[0].size_intra_table = 1;
            mvp_tmp_scatter_indexed_thresholds_table[0].intra_node[0].msg_sz =
                1;
            mvp_tmp_scatter_indexed_thresholds_table[0]
                .intra_node[0]
                .MVP_pt_Scatter_function = &MPIR_Scatter_MVP_Direct;
        }
        MPIR_Memcpy(mvp_scatter_indexed_thresholds_table[0],
                    mvp_tmp_scatter_indexed_thresholds_table,
                    sizeof(mvp_scatter_indexed_tuning_table));
        return 0;
}

int MVP_intranode_Scatter_is_define(const char *mvp_user_scatter_intra)
{
    int i = 0;
    int nb_element = count_sep(mvp_user_scatter_intra) + 1;

        if (nb_element == 1) {
            mvp_scatter_indexed_thresholds_table[0][0].size_intra_table = 1;
            mvp_scatter_indexed_thresholds_table[0][0].intra_node[0].msg_sz = 1;

            switch (atoi(mvp_user_scatter_intra)) {
                case SCATTER_DIRECT:
                    mvp_scatter_indexed_thresholds_table[0][0]
                        .intra_node[0]
                        .MVP_pt_Scatter_function = &MPIR_Scatter_MVP_Direct;
                    break;
                case SCATTER_BINOMIAL:
                    mvp_scatter_indexed_thresholds_table[0][0]
                        .intra_node[0]
                        .MVP_pt_Scatter_function = &MPIR_Scatter_MVP_Binomial;
                    break;
                default:
                    mvp_scatter_indexed_thresholds_table[0][0]
                        .intra_node[0]
                        .MVP_pt_Scatter_function = &MPIR_Scatter_MVP_Direct;
            }
        }
        return 0;
}
