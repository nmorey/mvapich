/*
 * Copyright (c) 2001-2023, The Ohio State University. All rights
 * reserved.
 *
 * This file is part of the MVAPICH software package developed by the
 * team members of The Ohio State University's Network-Based Computing
 * Laboratory (NBCL), headed by Professor Dhabaleswar K. (DK) Panda.
 *
 * For detailed copyright and licensing information, please refer to the
 * copyright file COPYRIGHT in the top level MVAPICH directory.
 */

#define PSM__INTEL_XEON_X5650_12__MVP_HCA_QLGIC_QIB__12PPN                     \
    {{24,                                                                      \
      4,                                                                       \
      4,                                                                       \
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},               \
      18,                                                                      \
      {{1, &MPIR_Reduce_binomial_MVP},                                         \
       {2, &MPIR_Reduce_inter_knomial_wrapper_MVP},                            \
       {4, &MPIR_Reduce_binomial_MVP},                                         \
       {8, &MPIR_Reduce_binomial_MVP},                                         \
       {16, &MPIR_Reduce_binomial_MVP},                                        \
       {32, &MPIR_Reduce_binomial_MVP},                                        \
       {64, &MPIR_Reduce_binomial_MVP},                                        \
       {128, &MPIR_Reduce_binomial_MVP},                                       \
       {256, &MPIR_Reduce_binomial_MVP},                                       \
       {512, &MPIR_Reduce_binomial_MVP},                                       \
       {1024, &MPIR_Reduce_binomial_MVP},                                      \
       {2048, &MPIR_Reduce_binomial_MVP},                                      \
       {4096, &MPIR_Reduce_binomial_MVP},                                      \
       {8192, &MPIR_Reduce_inter_knomial_wrapper_MVP},                         \
       {16384, &MPIR_Reduce_inter_knomial_wrapper_MVP},                        \
       {32768, &MPIR_Reduce_inter_knomial_wrapper_MVP},                        \
       {65536, &MPIR_Reduce_inter_knomial_wrapper_MVP},                        \
       {131072, &MPIR_Reduce_inter_knomial_wrapper_MVP},                       \
       {262144, &MPIR_Reduce_inter_knomial_wrapper_MVP}},                      \
      18,                                                                      \
      {{1, &MPIR_Reduce_shmem_MVP},                                            \
       {2, &MPIR_Reduce_shmem_MVP},                                            \
       {4, &MPIR_Reduce_shmem_MVP},                                            \
       {8, &MPIR_Reduce_shmem_MVP},                                            \
       {16, &MPIR_Reduce_shmem_MVP},                                           \
       {32, &MPIR_Reduce_shmem_MVP},                                           \
       {64, &MPIR_Reduce_shmem_MVP},                                           \
       {128, &MPIR_Reduce_shmem_MVP},                                          \
       {256, &MPIR_Reduce_shmem_MVP},                                          \
       {512, &MPIR_Reduce_shmem_MVP},                                          \
       {1024, &MPIR_Reduce_shmem_MVP},                                         \
       {2048, &MPIR_Reduce_shmem_MVP},                                         \
       {4096, &MPIR_Reduce_shmem_MVP},                                         \
       {8192, &MPIR_Reduce_shmem_MVP},                                         \
       {16384, &MPIR_Reduce_shmem_MVP},                                        \
       {32768, &MPIR_Reduce_shmem_MVP},                                        \
       {65536, &MPIR_Reduce_shmem_MVP},                                        \
       {131072, &MPIR_Reduce_shmem_MVP},                                       \
       {262144, &MPIR_Reduce_shmem_MVP}}},                                     \
     {48,                                                                      \
      4,                                                                       \
      4,                                                                       \
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},               \
      18,                                                                      \
      {{1, &MPIR_Reduce_inter_knomial_wrapper_MVP},                            \
       {2, &MPIR_Reduce_inter_knomial_wrapper_MVP},                            \
       {4, &MPIR_Reduce_inter_knomial_wrapper_MVP},                            \
       {8, &MPIR_Reduce_inter_knomial_wrapper_MVP},                            \
       {16, &MPIR_Reduce_inter_knomial_wrapper_MVP},                           \
       {32, &MPIR_Reduce_inter_knomial_wrapper_MVP},                           \
       {64, &MPIR_Reduce_inter_knomial_wrapper_MVP},                           \
       {128, &MPIR_Reduce_inter_knomial_wrapper_MVP},                          \
       {256, &MPIR_Reduce_inter_knomial_wrapper_MVP},                          \
       {512, &MPIR_Reduce_inter_knomial_wrapper_MVP},                          \
       {1024, &MPIR_Reduce_binomial_MVP},                                      \
       {2048, &MPIR_Reduce_binomial_MVP},                                      \
       {4096, &MPIR_Reduce_binomial_MVP},                                      \
       {8192, &MPIR_Reduce_binomial_MVP},                                      \
       {16384, &MPIR_Reduce_inter_knomial_wrapper_MVP},                        \
       {32768, &MPIR_Reduce_inter_knomial_wrapper_MVP},                        \
       {65536, &MPIR_Reduce_binomial_MVP},                                     \
       {131072, &MPIR_Reduce_redscat_gather_MVP},                              \
       {262144, &MPIR_Reduce_redscat_gather_MVP}},                             \
      18,                                                                      \
      {{1, &MPIR_Reduce_shmem_MVP},                                            \
       {2, &MPIR_Reduce_shmem_MVP},                                            \
       {4, &MPIR_Reduce_shmem_MVP},                                            \
       {8, &MPIR_Reduce_shmem_MVP},                                            \
       {16, &MPIR_Reduce_shmem_MVP},                                           \
       {32, &MPIR_Reduce_shmem_MVP},                                           \
       {64, &MPIR_Reduce_shmem_MVP},                                           \
       {128, &MPIR_Reduce_shmem_MVP},                                          \
       {256, &MPIR_Reduce_shmem_MVP},                                          \
       {512, &MPIR_Reduce_shmem_MVP},                                          \
       {1024, &MPIR_Reduce_shmem_MVP},                                         \
       {2048, &MPIR_Reduce_shmem_MVP},                                         \
       {4096, &MPIR_Reduce_shmem_MVP},                                         \
       {8192, &MPIR_Reduce_shmem_MVP},                                         \
       {16384, &MPIR_Reduce_shmem_MVP},                                        \
       {32768, &MPIR_Reduce_shmem_MVP},                                        \
       {65536, &MPIR_Reduce_shmem_MVP},                                        \
       {131072, &MPIR_Reduce_shmem_MVP},                                       \
       {262144, &MPIR_Reduce_shmem_MVP}}},                                     \
     {96,                                                                      \
      4,                                                                       \
      4,                                                                       \
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},               \
      18,                                                                      \
      {{1, &MPIR_Reduce_inter_knomial_wrapper_MVP},                            \
       {2, &MPIR_Reduce_inter_knomial_wrapper_MVP},                            \
       {4, &MPIR_Reduce_inter_knomial_wrapper_MVP},                            \
       {8, &MPIR_Reduce_inter_knomial_wrapper_MVP},                            \
       {16, &MPIR_Reduce_inter_knomial_wrapper_MVP},                           \
       {32, &MPIR_Reduce_inter_knomial_wrapper_MVP},                           \
       {64, &MPIR_Reduce_inter_knomial_wrapper_MVP},                           \
       {128, &MPIR_Reduce_inter_knomial_wrapper_MVP},                          \
       {256, &MPIR_Reduce_inter_knomial_wrapper_MVP},                          \
       {512, &MPIR_Reduce_inter_knomial_wrapper_MVP},                          \
       {1024, &MPIR_Reduce_binomial_MVP},                                      \
       {2048, &MPIR_Reduce_binomial_MVP},                                      \
       {4096, &MPIR_Reduce_binomial_MVP},                                      \
       {8192, &MPIR_Reduce_binomial_MVP},                                      \
       {16384, &MPIR_Reduce_redscat_gather_MVP},                               \
       {32768, &MPIR_Reduce_redscat_gather_MVP},                               \
       {65536, &MPIR_Reduce_redscat_gather_MVP},                               \
       {131072, &MPIR_Reduce_redscat_gather_MVP},                              \
       {262144, &MPIR_Reduce_redscat_gather_MVP}},                             \
      18,                                                                      \
      {{1, &MPIR_Reduce_shmem_MVP},                                            \
       {2, &MPIR_Reduce_shmem_MVP},                                            \
       {4, &MPIR_Reduce_shmem_MVP},                                            \
       {8, &MPIR_Reduce_shmem_MVP},                                            \
       {16, &MPIR_Reduce_shmem_MVP},                                           \
       {32, &MPIR_Reduce_shmem_MVP},                                           \
       {64, &MPIR_Reduce_shmem_MVP},                                           \
       {128, &MPIR_Reduce_shmem_MVP},                                          \
       {256, &MPIR_Reduce_shmem_MVP},                                          \
       {512, &MPIR_Reduce_shmem_MVP},                                          \
       {1024, &MPIR_Reduce_shmem_MVP},                                         \
       {2048, &MPIR_Reduce_shmem_MVP},                                         \
       {4096, &MPIR_Reduce_shmem_MVP},                                         \
       {8192, &MPIR_Reduce_shmem_MVP},                                         \
       {16384, &MPIR_Reduce_shmem_MVP},                                        \
       {32768, &MPIR_Reduce_shmem_MVP},                                        \
       {65536, &MPIR_Reduce_shmem_MVP},                                        \
       {131072, &MPIR_Reduce_shmem_MVP},                                       \
       {262144, &MPIR_Reduce_shmem_MVP}}},                                     \
     {192,                                                                     \
      4,                                                                       \
      4,                                                                       \
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},               \
      18,                                                                      \
      {{1, &MPIR_Reduce_inter_knomial_wrapper_MVP},                            \
       {2, &MPIR_Reduce_inter_knomial_wrapper_MVP},                            \
       {4, &MPIR_Reduce_inter_knomial_wrapper_MVP},                            \
       {8, &MPIR_Reduce_inter_knomial_wrapper_MVP},                            \
       {16, &MPIR_Reduce_inter_knomial_wrapper_MVP},                           \
       {32, &MPIR_Reduce_inter_knomial_wrapper_MVP},                           \
       {64, &MPIR_Reduce_inter_knomial_wrapper_MVP},                           \
       {128, &MPIR_Reduce_inter_knomial_wrapper_MVP},                          \
       {256, &MPIR_Reduce_inter_knomial_wrapper_MVP},                          \
       {512, &MPIR_Reduce_inter_knomial_wrapper_MVP},                          \
       {1024, &MPIR_Reduce_binomial_MVP},                                      \
       {2048, &MPIR_Reduce_binomial_MVP},                                      \
       {4096, &MPIR_Reduce_binomial_MVP},                                      \
       {8192, &MPIR_Reduce_binomial_MVP},                                      \
       {16384, &MPIR_Reduce_redscat_gather_MVP},                               \
       {32768, &MPIR_Reduce_binomial_MVP},                                     \
       {65536, &MPIR_Reduce_binomial_MVP},                                     \
       {131072, &MPIR_Reduce_binomial_MVP},                                    \
       {262144, &MPIR_Reduce_binomial_MVP}},                                   \
      18,                                                                      \
      {{1, &MPIR_Reduce_shmem_MVP},                                            \
       {2, &MPIR_Reduce_shmem_MVP},                                            \
       {4, &MPIR_Reduce_shmem_MVP},                                            \
       {8, &MPIR_Reduce_shmem_MVP},                                            \
       {16, &MPIR_Reduce_shmem_MVP},                                           \
       {32, &MPIR_Reduce_shmem_MVP},                                           \
       {64, &MPIR_Reduce_shmem_MVP},                                           \
       {128, &MPIR_Reduce_shmem_MVP},                                          \
       {256, &MPIR_Reduce_shmem_MVP},                                          \
       {512, &MPIR_Reduce_shmem_MVP},                                          \
       {1024, &MPIR_Reduce_shmem_MVP},                                         \
       {2048, &MPIR_Reduce_shmem_MVP},                                         \
       {4096, &MPIR_Reduce_shmem_MVP},                                         \
       {8192, &MPIR_Reduce_shmem_MVP},                                         \
       {16384, &MPIR_Reduce_shmem_MVP},                                        \
       {32768, &MPIR_Reduce_shmem_MVP},                                        \
       {65536, &MPIR_Reduce_shmem_MVP},                                        \
       {131072, &MPIR_Reduce_shmem_MVP},                                       \
       {262144, &MPIR_Reduce_shmem_MVP}}},                                     \
     {384,                                                                     \
      4,                                                                       \
      4,                                                                       \
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},               \
      18,                                                                      \
      {{1, &MPIR_Reduce_inter_knomial_wrapper_MVP},                            \
       {2, &MPIR_Reduce_inter_knomial_wrapper_MVP},                            \
       {4, &MPIR_Reduce_inter_knomial_wrapper_MVP},                            \
       {8, &MPIR_Reduce_inter_knomial_wrapper_MVP},                            \
       {16, &MPIR_Reduce_inter_knomial_wrapper_MVP},                           \
       {32, &MPIR_Reduce_inter_knomial_wrapper_MVP},                           \
       {64, &MPIR_Reduce_inter_knomial_wrapper_MVP},                           \
       {128, &MPIR_Reduce_inter_knomial_wrapper_MVP},                          \
       {256, &MPIR_Reduce_inter_knomial_wrapper_MVP},                          \
       {512, &MPIR_Reduce_inter_knomial_wrapper_MVP},                          \
       {1024, &MPIR_Reduce_binomial_MVP},                                      \
       {2048, &MPIR_Reduce_binomial_MVP},                                      \
       {4096, &MPIR_Reduce_inter_knomial_wrapper_MVP},                         \
       {8192, &MPIR_Reduce_binomial_MVP},                                      \
       {16384, &MPIR_Reduce_binomial_MVP},                                     \
       {32768, &MPIR_Reduce_binomial_MVP},                                     \
       {65536, &MPIR_Reduce_binomial_MVP},                                     \
       {131072, &MPIR_Reduce_binomial_MVP},                                    \
       {262144, &MPIR_Reduce_binomial_MVP}},                                   \
      18,                                                                      \
      {{1, &MPIR_Reduce_shmem_MVP},                                            \
       {2, &MPIR_Reduce_shmem_MVP},                                            \
       {4, &MPIR_Reduce_shmem_MVP},                                            \
       {8, &MPIR_Reduce_shmem_MVP},                                            \
       {16, &MPIR_Reduce_shmem_MVP},                                           \
       {32, &MPIR_Reduce_shmem_MVP},                                           \
       {64, &MPIR_Reduce_shmem_MVP},                                           \
       {128, &MPIR_Reduce_shmem_MVP},                                          \
       {256, &MPIR_Reduce_shmem_MVP},                                          \
       {512, &MPIR_Reduce_shmem_MVP},                                          \
       {1024, &MPIR_Reduce_shmem_MVP},                                         \
       {2048, &MPIR_Reduce_shmem_MVP},                                         \
       {4096, &MPIR_Reduce_shmem_MVP},                                         \
       {8192, &MPIR_Reduce_shmem_MVP},                                         \
       {16384, &MPIR_Reduce_shmem_MVP},                                        \
       {32768, &MPIR_Reduce_shmem_MVP},                                        \
       {65536, &MPIR_Reduce_shmem_MVP},                                        \
       {131072, &MPIR_Reduce_shmem_MVP},                                       \
       {262144, &MPIR_Reduce_shmem_MVP}}},                                     \
     {768,                                                                     \
      4,                                                                       \
      4,                                                                       \
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},               \
      18,                                                                      \
      {{1, &MPIR_Reduce_inter_knomial_wrapper_MVP},                            \
       {2, &MPIR_Reduce_inter_knomial_wrapper_MVP},                            \
       {4, &MPIR_Reduce_inter_knomial_wrapper_MVP},                            \
       {8, &MPIR_Reduce_inter_knomial_wrapper_MVP},                            \
       {16, &MPIR_Reduce_inter_knomial_wrapper_MVP},                           \
       {32, &MPIR_Reduce_inter_knomial_wrapper_MVP},                           \
       {64, &MPIR_Reduce_inter_knomial_wrapper_MVP},                           \
       {128, &MPIR_Reduce_inter_knomial_wrapper_MVP},                          \
       {256, &MPIR_Reduce_inter_knomial_wrapper_MVP},                          \
       {512, &MPIR_Reduce_inter_knomial_wrapper_MVP},                          \
       {1024, &MPIR_Reduce_binomial_MVP},                                      \
       {2048, &MPIR_Reduce_binomial_MVP},                                      \
       {4096, &MPIR_Reduce_binomial_MVP},                                      \
       {8192, &MPIR_Reduce_binomial_MVP},                                      \
       {16384, &MPIR_Reduce_inter_knomial_wrapper_MVP},                        \
       {32768, &MPIR_Reduce_binomial_MVP},                                     \
       {65536, &MPIR_Reduce_binomial_MVP},                                     \
       {131072, &MPIR_Reduce_binomial_MVP},                                    \
       {262144, &MPIR_Reduce_redscat_gather_MVP}},                             \
      18,                                                                      \
      {{1, &MPIR_Reduce_shmem_MVP},                                            \
       {2, &MPIR_Reduce_shmem_MVP},                                            \
       {4, &MPIR_Reduce_shmem_MVP},                                            \
       {8, &MPIR_Reduce_shmem_MVP},                                            \
       {16, &MPIR_Reduce_shmem_MVP},                                           \
       {32, &MPIR_Reduce_shmem_MVP},                                           \
       {64, &MPIR_Reduce_shmem_MVP},                                           \
       {128, &MPIR_Reduce_shmem_MVP},                                          \
       {256, &MPIR_Reduce_shmem_MVP},                                          \
       {512, &MPIR_Reduce_shmem_MVP},                                          \
       {1024, &MPIR_Reduce_shmem_MVP},                                         \
       {2048, &MPIR_Reduce_shmem_MVP},                                         \
       {4096, &MPIR_Reduce_shmem_MVP},                                         \
       {8192, &MPIR_Reduce_shmem_MVP},                                         \
       {16384, &MPIR_Reduce_shmem_MVP},                                        \
       {32768, &MPIR_Reduce_shmem_MVP},                                        \
       {65536, &MPIR_Reduce_shmem_MVP},                                        \
       {131072, &MPIR_Reduce_shmem_MVP},                                       \
       {262144, &MPIR_Reduce_shmem_MVP}}}};
