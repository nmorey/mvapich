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
#include "allgatherv_tuning.h"

/* TODO: This should be moved to the pre-header as it is in ch4 */
#ifdef CHANNEL_MRAIL
#include "mvp_arch_hca_detect.h"
#endif

enum {
    ALLGATHERV_REC = 1,
    ALLGATHERV_BRUCK,
    ALLGATHERV_RING,
    ALLGATHERV_CYCLIC,
};

int mvp_size_allgatherv_tuning_table = 0;
mvp_allgatherv_tuning_table *mvp_allgatherv_thresholds_table = NULL;

int MVP_set_allgatherv_tuning_table(int heterogeneity,
                                    struct coll_info *colls_arch_hca)
{
#ifndef _MVP_CH4_OVERRIDE_
#ifdef CHANNEL_MRAIL_GEN2
    if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                             MVP_ARCH_INTEL_XEON_X5650_12,
                             MVP_HCA_MLX_CX_QDR) &&
        !heterogeneity) {
        mvp_size_allgatherv_tuning_table = 6;
        mvp_allgatherv_thresholds_table =
            MPL_malloc(mvp_size_allgatherv_tuning_table *
                           sizeof(mvp_allgatherv_tuning_table),
                       MPL_MEM_COLL);
        mvp_allgatherv_tuning_table mvp_tmp_allgatherv_thresholds_table[] = {
            {
                12,
                2,
                {
                    {0, 512, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {512, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                24,
                2,
                {
                    {0, 512, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {512, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                48,
                2,
                {
                    {0, 256, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {256, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                96,
                2,
                {
                    {0, 256, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {256, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                192,
                2,
                {
                    {0, 256, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {256, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                384,
                2,
                {
                    {0, 256, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {256, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
        };
        MPIR_Memcpy(mvp_allgatherv_thresholds_table,
                    mvp_tmp_allgatherv_thresholds_table,
                    mvp_size_allgatherv_tuning_table *
                        sizeof(mvp_allgatherv_tuning_table));
    } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                    MVP_ARCH_INTEL_XEON_E5_2680_16,
                                    MVP_HCA_MLX_CX_FDR) &&
               !heterogeneity) {
        mvp_size_allgatherv_tuning_table = 6;
        mvp_allgatherv_thresholds_table =
            MPL_malloc(mvp_size_allgatherv_tuning_table *
                           sizeof(mvp_allgatherv_tuning_table),
                       MPL_MEM_COLL);
        mvp_allgatherv_tuning_table mvp_tmp_allgatherv_thresholds_table[] = {
            {
                16,
                2,
                {
                    {0, 512, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {512, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                32,
                2,
                {
                    {0, 512, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {512, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                64,
                2,
                {
                    {0, 256, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {256, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                128,
                2,
                {
                    {0, 256, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {256, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                256,
                2,
                {
                    {0, 256, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {256, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                512,
                2,
                {
                    {0, 256, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {256, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },

        };
        MPIR_Memcpy(mvp_allgatherv_thresholds_table,
                    mvp_tmp_allgatherv_thresholds_table,
                    mvp_size_allgatherv_tuning_table *
                        sizeof(mvp_allgatherv_tuning_table));
    } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                    MVP_ARCH_AMD_OPTERON_6136_32,
                                    MVP_HCA_MLX_CX_QDR) &&
               !heterogeneity) {
        mvp_size_allgatherv_tuning_table = 6;
        mvp_allgatherv_thresholds_table =
            MPL_malloc(mvp_size_allgatherv_tuning_table *
                           sizeof(mvp_allgatherv_tuning_table),
                       MPL_MEM_COLL);
        mvp_allgatherv_tuning_table mvp_tmp_allgatherv_thresholds_table[] = {
            /*Trestles*/
            {
                32,
                2,
                {
                    {0, 512, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {512, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                64,
                2,
                {
                    {0, 256, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {256, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                128,
                2,
                {
                    {0, 128, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {128, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                256,
                2,
                {
                    {0, 128, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {128, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                512,
                2,
                {
                    {0, 128, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {128, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                1024,
                2,
                {
                    {0, 256, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {256, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
        };
        MPIR_Memcpy(mvp_allgatherv_thresholds_table,
                    mvp_tmp_allgatherv_thresholds_table,
                    mvp_size_allgatherv_tuning_table *
                        sizeof(mvp_allgatherv_tuning_table));
    } else
#elif defined(CHANNEL_NEMESIS_IB)
    if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                             MVP_ARCH_INTEL_XEON_X5650_12,
                             MVP_HCA_MLX_CX_QDR) &&
        !heterogeneity) {
        mvp_size_allgatherv_tuning_table = 6;
        mvp_allgatherv_thresholds_table =
            MPL_malloc(mvp_size_allgatherv_tuning_table *
                           sizeof(mvp_allgatherv_tuning_table),
                       MPL_MEM_COLL);
        mvp_allgatherv_tuning_table mvp_tmp_allgatherv_thresholds_table[] = {
            {
                12,
                2,
                {
                    {0, 512, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {512, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                24,
                2,
                {
                    {0, 512, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {512, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                48,
                2,
                {
                    {0, 256, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {256, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                96,
                2,
                {
                    {0, 256, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {256, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                192,
                2,
                {
                    {0, 256, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {256, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                384,
                2,
                {
                    {0, 256, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {256, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
        };
        MPIR_Memcpy(mvp_allgatherv_thresholds_table,
                    mvp_tmp_allgatherv_thresholds_table,
                    mvp_size_allgatherv_tuning_table *
                        sizeof(mvp_allgatherv_tuning_table));
    } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                    MVP_ARCH_INTEL_XEON_E5_2680_16,
                                    MVP_HCA_MLX_CX_FDR) &&
               !heterogeneity) {
        mvp_size_allgatherv_tuning_table = 6;
        mvp_allgatherv_thresholds_table =
            MPL_malloc(mvp_size_allgatherv_tuning_table *
                           sizeof(mvp_allgatherv_tuning_table),
                       MPL_MEM_COLL);
        mvp_allgatherv_tuning_table mvp_tmp_allgatherv_thresholds_table[] = {
            {
                16,
                2,
                {
                    {0, 512, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {512, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                32,
                2,
                {
                    {0, 512, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {512, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                64,
                2,
                {
                    {0, 256, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {256, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                128,
                2,
                {
                    {0, 256, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {256, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                256,
                2,
                {
                    {0, 256, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {256, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                512,
                2,
                {
                    {0, 256, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {256, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },

        };
        MPIR_Memcpy(mvp_allgatherv_thresholds_table,
                    mvp_tmp_allgatherv_thresholds_table,
                    mvp_size_allgatherv_tuning_table *
                        sizeof(mvp_allgatherv_tuning_table));
    } else if (MVP_IS_ARCH_HCA_TYPE(MVP_get_arch_hca_type(),
                                    MVP_ARCH_AMD_OPTERON_6136_32,
                                    MVP_HCA_MLX_CX_QDR) &&
               !heterogeneity) {
        mvp_size_allgatherv_tuning_table = 6;
        mvp_allgatherv_thresholds_table =
            MPL_malloc(mvp_size_allgatherv_tuning_table *
                           sizeof(mvp_allgatherv_tuning_table),
                       MPL_MEM_COLL);
        mvp_allgatherv_tuning_table mvp_tmp_allgatherv_thresholds_table[] = {
            /*Trestles*/
            {
                32,
                2,
                {
                    {0, 512, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {512, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                64,
                2,
                {
                    {0, 256, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {256, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                128,
                2,
                {
                    {0, 128, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {128, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                256,
                2,
                {
                    {0, 128, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {128, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                512,
                2,
                {
                    {0, 128, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {128, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                1024,
                2,
                {
                    {0, 256, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {256, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
        };
        MPIR_Memcpy(mvp_allgatherv_thresholds_table,
                    mvp_tmp_allgatherv_thresholds_table,
                    mvp_size_allgatherv_tuning_table *
                        sizeof(mvp_allgatherv_tuning_table));
    } else
#endif
#endif /* !_MVP_CH4_OVERRIDE_ */
    {
        mvp_size_allgatherv_tuning_table = 7;
        mvp_allgatherv_thresholds_table =
            MPL_malloc(mvp_size_allgatherv_tuning_table *
                           sizeof(mvp_allgatherv_tuning_table),
                       MPL_MEM_COLL);
        mvp_allgatherv_tuning_table mvp_tmp_allgatherv_thresholds_table[] = {
            {
                8,
                2,
                {
                    {0, 512, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {512, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                16,
                2,
                {
                    {0, 512, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {512, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                32,
                2,
                {
                    {0, 512, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {512, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                64,
                2,
                {
                    {0, 256, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {256, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                128,
                2,
                {
                    {0, 256, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {256, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                256,
                2,
                {
                    {0, 256, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {256, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },
            {
                512,
                2,
                {
                    {0, 256, &MPIR_Allgatherv_Rec_Doubling_MVP},
                    {256, -1, &MPIR_Allgatherv_Ring_MVP},
                },
            },

        };
        MPIR_Memcpy(mvp_allgatherv_thresholds_table,
                    mvp_tmp_allgatherv_thresholds_table,
                    mvp_size_allgatherv_tuning_table *
                        sizeof(mvp_allgatherv_tuning_table));
    }
    return 0;
}

void MVP_cleanup_allgatherv_tuning_table()
{
    if (mvp_allgatherv_thresholds_table != NULL) {
        MPL_free(mvp_allgatherv_thresholds_table);
    }
}

/* Return the number of separator inside a string */
static int count_sep(const char *string)
{
    return *string == '\0' ? 0 : (count_sep(string + 1) + (*string == ','));
}

int MVP_internode_Allgatherv_is_define(const char *mvp_user_allgatherv_inter)
{
    int i = 0;
    int nb_element = count_sep(mvp_user_allgatherv_inter) + 1;

    /* If one allgatherv tuning table is already defined */
    if (mvp_allgatherv_thresholds_table != NULL) {
        MPL_free(mvp_allgatherv_thresholds_table);
    }

    mvp_allgatherv_tuning_table mvp_tmp_allgatherv_thresholds_table[1];
    mvp_size_allgatherv_tuning_table = 1;

    /* We realloc the space for the new allgatherv tuning table */
    mvp_allgatherv_thresholds_table = MPL_malloc(
        mvp_size_allgatherv_tuning_table * sizeof(mvp_allgatherv_tuning_table),
        MPL_MEM_COLL);

    if (nb_element == 1) {
        mvp_tmp_allgatherv_thresholds_table[0].numproc = 1;
        mvp_tmp_allgatherv_thresholds_table[0].size_inter_table = 1;
        mvp_tmp_allgatherv_thresholds_table[0].inter_leader[0].min = 0;
        mvp_tmp_allgatherv_thresholds_table[0].inter_leader[0].max = -1;

        switch (atoi(mvp_user_allgatherv_inter)) {
            case ALLGATHERV_REC:
                mvp_tmp_allgatherv_thresholds_table[0]
                    .inter_leader[0]
                    .MVP_pt_Allgatherv_function =
                    &MPIR_Allgatherv_Rec_Doubling_MVP;
                break;
            case ALLGATHERV_BRUCK:
                mvp_tmp_allgatherv_thresholds_table[0]
                    .inter_leader[0]
                    .MVP_pt_Allgatherv_function = &MPIR_Allgatherv_Bruck_MVP;
                break;
            case ALLGATHERV_RING:
                mvp_tmp_allgatherv_thresholds_table[0]
                    .inter_leader[0]
                    .MVP_pt_Allgatherv_function = &MPIR_Allgatherv_Ring_MVP;
                break;
            case ALLGATHERV_CYCLIC:
                mvp_tmp_allgatherv_thresholds_table[0]
                    .inter_leader[0]
                    .MVP_pt_Allgatherv_function =
                    &MPIR_Allgatherv_Ring_Cyclic_MVP;
                break;
            default:
                mvp_tmp_allgatherv_thresholds_table[0]
                    .inter_leader[0]
                    .MVP_pt_Allgatherv_function = &MPIR_Allgatherv_Bruck_MVP;
        }

    } else {
        char *dup, *p, *save_p;
        regmatch_t match[NMATCH];
        regex_t preg;
        const char *regexp = "([0-9]+):([0-9]+)-([0-9]+|\\+)";

        if (!(dup = MPL_strdup(mvp_user_allgatherv_inter))) {
            fprintf(stderr, "failed to duplicate `%s'\n",
                    mvp_user_allgatherv_inter);
            return -1;
        }

        if (regcomp(&preg, regexp, REG_EXTENDED)) {
            fprintf(stderr, "failed to compile regexp `%s'\n",
                    mvp_user_allgatherv_inter);
            MPL_free(dup);
            return -1;
        }

        mvp_tmp_allgatherv_thresholds_table[0].numproc = 1;
        mvp_tmp_allgatherv_thresholds_table[0].size_inter_table = nb_element;

        i = 0;
        for (p = strtok_r(dup, ",", &save_p); p;
             p = strtok_r(NULL, ",", &save_p)) {
            if (regexec(&preg, p, NMATCH, match, 0)) {
                fprintf(stderr, "failed to match on `%s'\n", p);
                regfree(&preg);
                MPL_free(dup);
                return -1;
            }
            /* given () start at 1 */
            switch (atoi(p + match[1].rm_so)) {
                case ALLGATHERV_REC:
                    mvp_tmp_allgatherv_thresholds_table[0]
                        .inter_leader[i]
                        .MVP_pt_Allgatherv_function =
                        &MPIR_Allgatherv_Rec_Doubling_MVP;
                    break;
                case ALLGATHERV_BRUCK:
                    mvp_tmp_allgatherv_thresholds_table[0]
                        .inter_leader[i]
                        .MVP_pt_Allgatherv_function =
                        &MPIR_Allgatherv_Bruck_MVP;
                    break;
                case ALLGATHERV_RING:
                    mvp_tmp_allgatherv_thresholds_table[0]
                        .inter_leader[i]
                        .MVP_pt_Allgatherv_function = &MPIR_Allgatherv_Ring_MVP;
                    break;
                case ALLGATHERV_CYCLIC:
                    mvp_tmp_allgatherv_thresholds_table[0]
                        .inter_leader[i]
                        .MVP_pt_Allgatherv_function =
                        &MPIR_Allgatherv_Ring_Cyclic_MVP;
                    break;
                default:
                    mvp_tmp_allgatherv_thresholds_table[0]
                        .inter_leader[i]
                        .MVP_pt_Allgatherv_function =
                        &MPIR_Allgatherv_Bruck_MVP;
            }
            mvp_tmp_allgatherv_thresholds_table[0].inter_leader[i].min =
                atoi(p + match[2].rm_so);
            if (p[match[3].rm_so] == '+') {
                mvp_tmp_allgatherv_thresholds_table[0].inter_leader[i].max = -1;
            } else {
                mvp_tmp_allgatherv_thresholds_table[0].inter_leader[i].max =
                    atoi(p + match[3].rm_so);
            }
            i++;
        }
        MPL_free(dup);
        regfree(&preg);
    }
    MPIR_Memcpy(mvp_allgatherv_thresholds_table,
                mvp_tmp_allgatherv_thresholds_table,
                sizeof(mvp_allgatherv_tuning_table));
    return 0;
}
