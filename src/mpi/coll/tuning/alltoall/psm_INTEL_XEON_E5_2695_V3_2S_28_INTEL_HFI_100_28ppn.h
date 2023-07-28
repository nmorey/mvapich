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

#define PSM__INTEL_XEON_E5_2695_V3_2S_28_INTEL_HFI_100__28PPN                  \
    {                                                                          \
        {28,                                                                   \
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1},                     \
         16,                                                                   \
         {{1, &MPIR_Alltoall_bruck_MVP},                                       \
          {2, &MPIR_Alltoall_bruck_MVP},                                       \
          {4, &MPIR_Alltoall_bruck_MVP},                                       \
          {8, &MPIR_Alltoall_pairwise_MVP},                                    \
          {16, &MPIR_Alltoall_pairwise_MVP},                                   \
          {32, &MPIR_Alltoall_RD_MVP},                                         \
          {64, &MPIR_Alltoall_bruck_MVP},                                      \
          {128, &MPIR_Alltoall_inplace_MVP},                                   \
          {256, &MPIR_Alltoall_inplace_MVP},                                   \
          {512, &MPIR_Alltoall_Scatter_dest_MVP},                              \
          {1024, &MPIR_Alltoall_Scatter_dest_MVP},                             \
          {2048, &MPIR_Alltoall_Scatter_dest_MVP},                             \
          {4096, &MPIR_Alltoall_inplace_MVP},                                  \
          {8192, &MPIR_Alltoall_pairwise_MVP},                                 \
          {16384, &MPIR_Alltoall_Scatter_dest_MVP},                            \
          {32768, &MPIR_Alltoall_Scatter_dest_MVP}}},                          \
            {56,                                                               \
             {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1},                 \
             16,                                                               \
             {{1, &MPIR_Alltoall_RD_MVP},                                      \
              {2, &MPIR_Alltoall_bruck_MVP},                                   \
              {4, &MPIR_Alltoall_bruck_MVP},                                   \
              {8, &MPIR_Alltoall_bruck_MVP},                                   \
              {16, &MPIR_Alltoall_bruck_MVP},                                  \
              {32, &MPIR_Alltoall_bruck_MVP},                                  \
              {64, &MPIR_Alltoall_bruck_MVP},                                  \
              {128, &MPIR_Alltoall_bruck_MVP},                                 \
              {256, &MPIR_Alltoall_bruck_MVP},                                 \
              {512, &MPIR_Alltoall_pairwise_MVP},                              \
              {1024, &MPIR_Alltoall_bruck_MVP},                                \
              {2048, &MPIR_Alltoall_Scatter_dest_MVP},                         \
              {4096, &MPIR_Alltoall_Scatter_dest_MVP},                         \
              {8192, &MPIR_Alltoall_Scatter_dest_MVP},                         \
              {16384, &MPIR_Alltoall_pairwise_MVP},                            \
              {32768, &MPIR_Alltoall_pairwise_MVP}}},                          \
            {112,                                                              \
             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},                 \
             16,                                                               \
             {{1, &MPIR_Alltoall_bruck_MVP},                                   \
              {2, &MPIR_Alltoall_bruck_MVP},                                   \
              {4, &MPIR_Alltoall_bruck_MVP},                                   \
              {8, &MPIR_Alltoall_bruck_MVP},                                   \
              {16, &MPIR_Alltoall_bruck_MVP},                                  \
              {32, &MPIR_Alltoall_bruck_MVP},                                  \
              {64, &MPIR_Alltoall_bruck_MVP},                                  \
              {128, &MPIR_Alltoall_bruck_MVP},                                 \
              {256, &MPIR_Alltoall_bruck_MVP},                                 \
              {512, &MPIR_Alltoall_pairwise_MVP},                              \
              {1024, &MPIR_Alltoall_bruck_MVP},                                \
              {2048, &MPIR_Alltoall_Scatter_dest_MVP},                         \
              {4096, &MPIR_Alltoall_Scatter_dest_MVP},                         \
              {8192, &MPIR_Alltoall_Scatter_dest_MVP},                         \
              {16384, &MPIR_Alltoall_Scatter_dest_MVP},                        \
              {32768, &MPIR_Alltoall_Scatter_dest_MVP}}},                      \
            {224,                                                              \
             {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1},                 \
             16,                                                               \
             {{1, &MPIR_Alltoall_bruck_MVP},                                   \
              {2, &MPIR_Alltoall_bruck_MVP},                                   \
              {4, &MPIR_Alltoall_bruck_MVP},                                   \
              {8, &MPIR_Alltoall_bruck_MVP},                                   \
              {16, &MPIR_Alltoall_bruck_MVP},                                  \
              {32, &MPIR_Alltoall_bruck_MVP},                                  \
              {64, &MPIR_Alltoall_bruck_MVP},                                  \
              {128, &MPIR_Alltoall_bruck_MVP},                                 \
              {256, &MPIR_Alltoall_Scatter_dest_MVP},                          \
              {512, &MPIR_Alltoall_pairwise_MVP},                              \
              {1024, &MPIR_Alltoall_pairwise_MVP},                             \
              {2048, &MPIR_Alltoall_Scatter_dest_MVP},                         \
              {4096, &MPIR_Alltoall_pairwise_MVP},                             \
              {8192, &MPIR_Alltoall_Scatter_dest_MVP},                         \
              {16384, &MPIR_Alltoall_Scatter_dest_MVP},                        \
              {32768, &MPIR_Alltoall_Scatter_dest_MVP}}},                      \
        {                                                                      \
            448, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0}, 16,         \
            {                                                                  \
                {1, &MPIR_Alltoall_bruck_MVP}, {2, &MPIR_Alltoall_bruck_MVP},  \
                    {4, &MPIR_Alltoall_bruck_MVP},                             \
                    {8, &MPIR_Alltoall_bruck_MVP},                             \
                    {16, &MPIR_Alltoall_bruck_MVP},                            \
                    {32, &MPIR_Alltoall_bruck_MVP},                            \
                    {64, &MPIR_Alltoall_bruck_MVP},                            \
                    {128, &MPIR_Alltoall_bruck_MVP},                           \
                    {256, &MPIR_Alltoall_bruck_MVP},                           \
                    {512, &MPIR_Alltoall_bruck_MVP},                           \
                    {1024, &MPIR_Alltoall_bruck_MVP},                          \
                    {2048, &MPIR_Alltoall_Scatter_dest_MVP},                   \
                    {4096, &MPIR_Alltoall_pairwise_MVP},                       \
                    {8192, &MPIR_Alltoall_Scatter_dest_MVP},                   \
                    {16384, &MPIR_Alltoall_Scatter_dest_MVP},                  \
                {                                                              \
                    32768, &MPIR_Alltoall_pairwise_MVP                         \
                }                                                              \
            }                                                                  \
        }                                                                      \
    }
