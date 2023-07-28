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

#define NEMESIS__RI__1PPN                                                      \
    {{2,                                                                       \
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},         \
      20,                                                                      \
      {{1, &MPIR_Alltoall_pairwise_MVP},                                       \
       {2, &MPIR_Alltoall_pairwise_MVP},                                       \
       {4, &MPIR_Alltoall_pairwise_MVP},                                       \
       {8, &MPIR_Alltoall_pairwise_MVP},                                       \
       {16, &MPIR_Alltoall_pairwise_MVP},                                      \
       {32, &MPIR_Alltoall_pairwise_MVP},                                      \
       {64, &MPIR_Alltoall_pairwise_MVP},                                      \
       {128, &MPIR_Alltoall_pairwise_MVP},                                     \
       {256, &MPIR_Alltoall_pairwise_MVP},                                     \
       {512, &MPIR_Alltoall_pairwise_MVP},                                     \
       {1024, &MPIR_Alltoall_pairwise_MVP},                                    \
       {2048, &MPIR_Alltoall_pairwise_MVP},                                    \
       {4096, &MPIR_Alltoall_pairwise_MVP},                                    \
       {8192, &MPIR_Alltoall_pairwise_MVP},                                    \
       {16384, &MPIR_Alltoall_pairwise_MVP},                                   \
       {32768, &MPIR_Alltoall_pairwise_MVP},                                   \
       {65536, &MPIR_Alltoall_pairwise_MVP},                                   \
       {131072, &MPIR_Alltoall_pairwise_MVP},                                  \
       {262144, &MPIR_Alltoall_pairwise_MVP},                                  \
       {524288, &MPIR_Alltoall_pairwise_MVP},                                  \
       {1048576, &MPIR_Alltoall_pairwise_MVP}}},                               \
     {4,                                                                       \
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},         \
      20,                                                                      \
      {{1, &MPIR_Alltoall_Scatter_dest_MVP},                                   \
       {2, &MPIR_Alltoall_Scatter_dest_MVP},                                   \
       {4, &MPIR_Alltoall_Scatter_dest_MVP},                                   \
       {8, &MPIR_Alltoall_Scatter_dest_MVP},                                   \
       {16, &MPIR_Alltoall_Scatter_dest_MVP},                                  \
       {32, &MPIR_Alltoall_Scatter_dest_MVP},                                  \
       {64, &MPIR_Alltoall_Scatter_dest_MVP},                                  \
       {128, &MPIR_Alltoall_Scatter_dest_MVP},                                 \
       {256, &MPIR_Alltoall_Scatter_dest_MVP},                                 \
       {512, &MPIR_Alltoall_Scatter_dest_MVP},                                 \
       {1024, &MPIR_Alltoall_Scatter_dest_MVP},                                \
       {2048, &MPIR_Alltoall_Scatter_dest_MVP},                                \
       {4096, &MPIR_Alltoall_Scatter_dest_MVP},                                \
       {8192, &MPIR_Alltoall_Scatter_dest_MVP},                                \
       {16384, &MPIR_Alltoall_Scatter_dest_MVP},                               \
       {32768, &MPIR_Alltoall_Scatter_dest_MVP},                               \
       {65536, &MPIR_Alltoall_Scatter_dest_MVP},                               \
       {131072, &MPIR_Alltoall_Scatter_dest_MVP},                              \
       {262144, &MPIR_Alltoall_Scatter_dest_MVP},                              \
       {524288, &MPIR_Alltoall_Scatter_dest_MVP},                              \
       {1048576, &MPIR_Alltoall_Scatter_dest_MVP}}}};
