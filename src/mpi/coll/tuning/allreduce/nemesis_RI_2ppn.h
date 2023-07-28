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

#define NEMESIS__RI__2PPN                                                      \
    {{2,                                                                       \
      0,                                                                       \
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0},               \
      18,                                                                      \
      {{1, &MPIR_Allreduce_pt2pt_rd_MVP},                                      \
       {2, &MPIR_Allreduce_pt2pt_rs_MVP},                                      \
       {4, &MPIR_Allreduce_pt2pt_rs_MVP},                                      \
       {8, &MPIR_Allreduce_pt2pt_rd_MVP},                                      \
       {16, &MPIR_Allreduce_pt2pt_rs_MVP},                                     \
       {32, &MPIR_Allreduce_pt2pt_rs_MVP},                                     \
       {64, &MPIR_Allreduce_pt2pt_rs_MVP},                                     \
       {128, &MPIR_Allreduce_pt2pt_rs_MVP},                                    \
       {256, &MPIR_Allreduce_pt2pt_rs_MVP},                                    \
       {512, &MPIR_Allreduce_pt2pt_rs_MVP},                                    \
       {1024, &MPIR_Allreduce_pt2pt_rs_MVP},                                   \
       {2048, &MPIR_Allreduce_pt2pt_rs_MVP},                                   \
       {4096, &MPIR_Allreduce_pt2pt_rs_MVP},                                   \
       {8192, &MPIR_Allreduce_pt2pt_rs_MVP},                                   \
       {16384, &MPIR_Allreduce_pt2pt_rs_MVP},                                  \
       {32768, &MPIR_Allreduce_pt2pt_rs_MVP},                                  \
       {65536, &MPIR_Allreduce_pt2pt_rs_MVP},                                  \
       {131072, &MPIR_Allreduce_pt2pt_rs_MVP},                                 \
       {262144, &MPIR_Allreduce_pt2pt_rs_MVP}},                                \
      18,                                                                      \
      {{1, &MPIR_Allreduce_reduce_shmem_MVP},                                  \
       {2, &MPIR_Allreduce_reduce_shmem_MVP},                                  \
       {4, &MPIR_Allreduce_reduce_shmem_MVP},                                  \
       {8, &MPIR_Allreduce_reduce_shmem_MVP},                                  \
       {16, &MPIR_Allreduce_reduce_shmem_MVP},                                 \
       {32, &MPIR_Allreduce_reduce_shmem_MVP},                                 \
       {64, &MPIR_Allreduce_reduce_shmem_MVP},                                 \
       {128, &MPIR_Allreduce_reduce_shmem_MVP},                                \
       {256, &MPIR_Allreduce_reduce_shmem_MVP},                                \
       {512, &MPIR_Allreduce_reduce_shmem_MVP},                                \
       {1024, &MPIR_Allreduce_reduce_shmem_MVP},                               \
       {2048, &MPIR_Allreduce_reduce_shmem_MVP},                               \
       {4096, &MPIR_Allreduce_reduce_p2p_MVP},                                 \
       {8192, &MPIR_Allreduce_reduce_p2p_MVP},                                 \
       {16384, &MPIR_Allreduce_reduce_p2p_MVP},                                \
       {32768, &MPIR_Allreduce_reduce_shmem_MVP},                              \
       {65536, &MPIR_Allreduce_reduce_p2p_MVP},                                \
       {131072, &MPIR_Allreduce_reduce_p2p_MVP},                               \
       {262144, &MPIR_Allreduce_reduce_p2p_MVP}}},                             \
     {4,                                                                       \
      0,                                                                       \
      {1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},               \
      18,                                                                      \
      {{1, &MPIR_Allreduce_pt2pt_rs_MVP},                                      \
       {2, &MPIR_Allreduce_pt2pt_rd_MVP},                                      \
       {4, &MPIR_Allreduce_pt2pt_rd_MVP},                                      \
       {8, &MPIR_Allreduce_pt2pt_rd_MVP},                                      \
       {16, &MPIR_Allreduce_pt2pt_rd_MVP},                                     \
       {32, &MPIR_Allreduce_pt2pt_rd_MVP},                                     \
       {64, &MPIR_Allreduce_pt2pt_rd_MVP},                                     \
       {128, &MPIR_Allreduce_pt2pt_rd_MVP},                                    \
       {256, &MPIR_Allreduce_pt2pt_rd_MVP},                                    \
       {512, &MPIR_Allreduce_pt2pt_rd_MVP},                                    \
       {1024, &MPIR_Allreduce_pt2pt_rd_MVP},                                   \
       {2048, &MPIR_Allreduce_pt2pt_rd_MVP},                                   \
       {4096, &MPIR_Allreduce_pt2pt_rs_MVP},                                   \
       {8192, &MPIR_Allreduce_pt2pt_rs_MVP},                                   \
       {16384, &MPIR_Allreduce_pt2pt_rs_MVP},                                  \
       {32768, &MPIR_Allreduce_pt2pt_rs_MVP},                                  \
       {65536, &MPIR_Allreduce_pt2pt_rs_MVP},                                  \
       {131072, &MPIR_Allreduce_pt2pt_rs_MVP},                                 \
       {262144, &MPIR_Allreduce_pt2pt_rs_MVP}},                                \
      18,                                                                      \
      {{1, &MPIR_Allreduce_reduce_shmem_MVP},                                  \
       {2, &MPIR_Allreduce_reduce_shmem_MVP},                                  \
       {4, &MPIR_Allreduce_reduce_p2p_MVP},                                    \
       {8, &MPIR_Allreduce_reduce_p2p_MVP},                                    \
       {16, &MPIR_Allreduce_reduce_shmem_MVP},                                 \
       {32, &MPIR_Allreduce_reduce_p2p_MVP},                                   \
       {64, &MPIR_Allreduce_reduce_p2p_MVP},                                   \
       {128, &MPIR_Allreduce_reduce_p2p_MVP},                                  \
       {256, &MPIR_Allreduce_reduce_shmem_MVP},                                \
       {512, &MPIR_Allreduce_reduce_shmem_MVP},                                \
       {1024, &MPIR_Allreduce_reduce_shmem_MVP},                               \
       {2048, &MPIR_Allreduce_reduce_shmem_MVP},                               \
       {4096, &MPIR_Allreduce_reduce_p2p_MVP},                                 \
       {8192, &MPIR_Allreduce_reduce_p2p_MVP},                                 \
       {16384, &MPIR_Allreduce_reduce_p2p_MVP},                                \
       {32768, &MPIR_Allreduce_reduce_p2p_MVP},                                \
       {65536, &MPIR_Allreduce_reduce_p2p_MVP},                                \
       {131072, &MPIR_Allreduce_reduce_p2p_MVP},                               \
       {262144, &MPIR_Allreduce_reduce_p2p_MVP}}}};
