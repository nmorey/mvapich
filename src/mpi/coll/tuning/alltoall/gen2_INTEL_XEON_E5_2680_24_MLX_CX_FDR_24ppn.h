/* Copyright (c) 2001-2023, The Ohio State University. All rights
 * reserved.
 *
 * This file is part of the MVAPICH software package developed by the
 * team members of The Ohio State University's Network-Based Computing
 * Laboratory (NBCL), headed by Professor Dhabaleswar K. (DK) Panda.
 *
 * For detailed copyright and licensing information, please refer to the
 * copyright file COPYRIGHT in the top level MVAPICH directory.
 */

#define GEN2__INTEL_XEON_E5_2680_24__MLX_CX_FDR__24PPN                         \
    {                                                                          \
        {48,                                                                   \
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},                     \
         15,                                                                   \
         {{1, &MPIR_Alltoall_RD_MVP},                                          \
          {2, &MPIR_Alltoall_RD_MVP},                                          \
          {4, &MPIR_Alltoall_bruck_MVP},                                       \
          {8, &MPIR_Alltoall_bruck_MVP},                                       \
          {16, &MPIR_Alltoall_bruck_MVP},                                      \
          {32, &MPIR_Alltoall_bruck_MVP},                                      \
          {64, &MPIR_Alltoall_bruck_MVP},                                      \
          {128, &MPIR_Alltoall_bruck_MVP},                                     \
          {256, &MPIR_Alltoall_bruck_MVP},                                     \
          {512, &MPIR_Alltoall_bruck_MVP},                                     \
          {1024, &MPIR_Alltoall_bruck_MVP},                                    \
          {2048, &MPIR_Alltoall_bruck_MVP},                                    \
          {4096, &MPIR_Alltoall_bruck_MVP},                                    \
          {8192, &MPIR_Alltoall_inplace_MVP},                                  \
          {16384, &MPIR_Alltoall_inplace_MVP},                                 \
          {32768, &MPIR_Alltoall_inplace_MVP}}},                               \
            {96,                                                               \
             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},                 \
             15,                                                               \
             {{1, &MPIR_Alltoall_RD_MVP},                                      \
              {2, &MPIR_Alltoall_bruck_MVP},                                   \
              {4, &MPIR_Alltoall_bruck_MVP},                                   \
              {8, &MPIR_Alltoall_bruck_MVP},                                   \
              {16, &MPIR_Alltoall_bruck_MVP},                                  \
              {32, &MPIR_Alltoall_bruck_MVP},                                  \
              {64, &MPIR_Alltoall_bruck_MVP},                                  \
              {128, &MPIR_Alltoall_bruck_MVP},                                 \
              {256, &MPIR_Alltoall_bruck_MVP},                                 \
              {512, &MPIR_Alltoall_bruck_MVP},                                 \
              {1024, &MPIR_Alltoall_bruck_MVP},                                \
              {2048, &MPIR_Alltoall_bruck_MVP},                                \
              {4096, &MPIR_Alltoall_bruck_MVP},                                \
              {8192, &MPIR_Alltoall_Scatter_dest_MVP},                         \
              {16384, &MPIR_Alltoall_pairwise_MVP},                            \
              {32768, &MPIR_Alltoall_pairwise_MVP}}},                          \
            {192,                                                              \
             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},                 \
             15,                                                               \
             {{1, &MPIR_Alltoall_bruck_MVP},                                   \
              {2, &MPIR_Alltoall_bruck_MVP},                                   \
              {4, &MPIR_Alltoall_bruck_MVP},                                   \
              {8, &MPIR_Alltoall_bruck_MVP},                                   \
              {16, &MPIR_Alltoall_bruck_MVP},                                  \
              {32, &MPIR_Alltoall_bruck_MVP},                                  \
              {64, &MPIR_Alltoall_bruck_MVP},                                  \
              {128, &MPIR_Alltoall_bruck_MVP},                                 \
              {256, &MPIR_Alltoall_bruck_MVP},                                 \
              {512, &MPIR_Alltoall_bruck_MVP},                                 \
              {1024, &MPIR_Alltoall_bruck_MVP},                                \
              {2048, &MPIR_Alltoall_bruck_MVP},                                \
              {4096, &MPIR_Alltoall_pairwise_MVP},                             \
              {8192, &MPIR_Alltoall_pairwise_MVP},                             \
              {16384, &MPIR_Alltoall_pairwise_MVP},                            \
              {32768, &MPIR_Alltoall_pairwise_MVP}}},                          \
            {384,                                                              \
             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},                 \
             15,                                                               \
             {{1, &MPIR_Alltoall_bruck_MVP},                                   \
              {2, &MPIR_Alltoall_bruck_MVP},                                   \
              {4, &MPIR_Alltoall_bruck_MVP},                                   \
              {8, &MPIR_Alltoall_bruck_MVP},                                   \
              {16, &MPIR_Alltoall_bruck_MVP},                                  \
              {32, &MPIR_Alltoall_bruck_MVP},                                  \
              {64, &MPIR_Alltoall_bruck_MVP},                                  \
              {128, &MPIR_Alltoall_bruck_MVP},                                 \
              {256, &MPIR_Alltoall_bruck_MVP},                                 \
              {512, &MPIR_Alltoall_bruck_MVP},                                 \
              {1024, &MPIR_Alltoall_bruck_MVP},                                \
              {2048, &MPIR_Alltoall_bruck_MVP},                                \
              {4096, &MPIR_Alltoall_pairwise_MVP},                             \
              {8192, &MPIR_Alltoall_pairwise_MVP},                             \
              {16384, &MPIR_Alltoall_pairwise_MVP},                            \
              {32768, &MPIR_Alltoall_pairwise_MVP}}},                          \
        {                                                                      \
            768, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0}, 15,         \
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
                    {2048, &MPIR_Alltoall_pairwise_MVP},                       \
                    {4096, &MPIR_Alltoall_pairwise_MVP},                       \
                    {8192, &MPIR_Alltoall_Scatter_dest_MVP},                   \
                    {16384, &MPIR_Alltoall_Scatter_dest_MVP},                  \
                {                                                              \
                    32768, &MPIR_Alltoall_pairwise_MVP                         \
                }                                                              \
            }                                                                  \
        }                                                                      \
    }
