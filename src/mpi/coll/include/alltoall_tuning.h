/* Copyright (c) 2001-2022, The Ohio State University. All rights
 * reserved.
 *
 * This file is part of the MVAPICH2 software package developed by the
 * team members of The Ohio State University's Network-Based Computing
 * Laboratory (NBCL), headed by Professor Dhabaleswar K. (DK) Panda.
 *
 * For detailed copyright and licensing information, please refer to the
 * copyright file COPYRIGHT in the top level MVAPICH2 directory.
 *
 */

#ifndef _ALLTOALL_TUNING_
#define _ALLTOALL_TUNING_

#include "mv2_coll_shmem.h"

#define NMATCH (3+1)

/* Alltoall tuning flags
 *  BRUCK: MV2_ALLTOALL_TUNING=0
 *  RD: MV2_ALLTOALL_TUNING=1
 *  SCATTER_DEST: MV2_ALLTOALL_TUNING=2
 *  PAIRWISE: MV2_ALLTOALL_TUNING=3
 *  INPLACE: MV2_ALLTOALL_TUNING=4
 */

/* Indicates number of processes per node */
extern int *mv2_alltoall_table_ppn_conf;
/* Indicates total number of configurations */
extern int mv2_alltoall_num_ppn_conf;

extern MPIR_T_pvar_timer_t PVAR_TIMER_mv2_coll_timer_alltoall_inplace;
extern MPIR_T_pvar_timer_t PVAR_TIMER_mv2_coll_timer_alltoall_bruck;
extern MPIR_T_pvar_timer_t PVAR_TIMER_mv2_coll_timer_alltoall_rd;
extern MPIR_T_pvar_timer_t PVAR_TIMER_mv2_coll_timer_alltoall_sd;
extern MPIR_T_pvar_timer_t PVAR_TIMER_mv2_coll_timer_alltoall_pw;

extern unsigned long long PVAR_COUNTER_mv2_coll_alltoall_inplace;
extern unsigned long long PVAR_COUNTER_mv2_coll_alltoall_bruck;
extern unsigned long long PVAR_COUNTER_mv2_coll_alltoall_rd;
extern unsigned long long PVAR_COUNTER_mv2_coll_alltoall_sd;
extern unsigned long long PVAR_COUNTER_mv2_coll_alltoall_pw;

extern unsigned long long PVAR_COUNTER_mv2_coll_alltoall_inplace_bytes_send;
extern unsigned long long PVAR_COUNTER_mv2_coll_alltoall_bruck_bytes_send;
extern unsigned long long PVAR_COUNTER_mv2_coll_alltoall_sd_bytes_send;
extern unsigned long long PVAR_COUNTER_mv2_coll_alltoall_pw_bytes_send;
extern unsigned long long PVAR_COUNTER_mv2_coll_alltoall_intra_bytes_send;
extern unsigned long long PVAR_COUNTER_mv2_coll_alltoall_inplace_bytes_recv;
extern unsigned long long PVAR_COUNTER_mv2_coll_alltoall_bruck_bytes_recv;
extern unsigned long long PVAR_COUNTER_mv2_coll_alltoall_sd_bytes_recv;
extern unsigned long long PVAR_COUNTER_mv2_coll_alltoall_pw_bytes_recv;
extern unsigned long long PVAR_COUNTER_mv2_coll_alltoall_intra_bytes_recv;
extern unsigned long long PVAR_COUNTER_mv2_coll_alltoall_inplace_count_send;
extern unsigned long long PVAR_COUNTER_mv2_coll_alltoall_bruck_count_send;
extern unsigned long long PVAR_COUNTER_mv2_coll_alltoall_sd_count_send;
extern unsigned long long PVAR_COUNTER_mv2_coll_alltoall_pw_count_send;
extern unsigned long long PVAR_COUNTER_mv2_coll_alltoall_intra_count_send;
extern unsigned long long PVAR_COUNTER_mv2_coll_alltoall_inplace_count_recv;
extern unsigned long long PVAR_COUNTER_mv2_coll_alltoall_bruck_count_recv;
extern unsigned long long PVAR_COUNTER_mv2_coll_alltoall_sd_count_recv;
extern unsigned long long PVAR_COUNTER_mv2_coll_alltoall_pw_count_recv;
extern unsigned long long PVAR_COUNTER_mv2_coll_alltoall_intra_count_recv;
extern unsigned long long PVAR_COUNTER_mv2_coll_alltoall_bytes_send;
extern unsigned long long PVAR_COUNTER_mv2_coll_alltoall_bytes_recv;
extern unsigned long long PVAR_COUNTER_mv2_coll_alltoall_count_send;
extern unsigned long long PVAR_COUNTER_mv2_coll_alltoall_count_recv;

typedef struct {
    int min;
    int max;
    int (*MV2_pt_Alltoall_function) (const void *sendbuf, 
                                     int sendcount, 
                                     MPI_Datatype sendtype, 
                                     void *recvbuf, 
                                     int recvcount, MPI_Datatype recvtype, 
                                     MPIR_Comm *comm_ptr, 
                                     MPIR_Errflag_t *errflag );
} mv2_alltoall_tuning_element;

typedef struct {
    int numproc;
    int size_table;
    mv2_alltoall_tuning_element algo_table[MV2_MAX_NB_THRESHOLDS];
    mv2_alltoall_tuning_element in_place_algo_table[MV2_MAX_NB_THRESHOLDS];
} mv2_alltoall_tuning_table;

extern int *mv2_size_alltoall_tuning_table;
extern mv2_alltoall_tuning_table **mv2_alltoall_thresholds_table;
extern int mv2_use_old_alltoall;

typedef struct {
    int msg_sz;
    int (*MV2_pt_Alltoall_function) (const void *sendbuf, 
                                     int sendcount, 
                                     MPI_Datatype sendtype,
                                     void *recvbuf, 
                                     int recvcount, 
                                     MPI_Datatype recvtype,
                                     MPIR_Comm *comm_ptr, 
                                     MPIR_Errflag_t *errflag );
} mv2_alltoall_indexed_tuning_element;

typedef struct {
    int numproc;
    int in_place_algo_table[MV2_MAX_NB_THRESHOLDS];
    int size_table;
    mv2_alltoall_indexed_tuning_element algo_table[MV2_MAX_NB_THRESHOLDS];
} mv2_alltoall_indexed_tuning_table;

/* Indicates number of processes per node */
extern int *mv2_alltoall_indexed_table_ppn_conf;
/* Indicates total number of configurations */
extern int mv2_alltoall_indexed_num_ppn_conf;
extern int *mv2_size_alltoall_indexed_tuning_table;
extern mv2_alltoall_indexed_tuning_table 
            **mv2_alltoall_indexed_thresholds_table;

extern int MPIR_Alltoall_bruck_MV2(
                            const void *sendbuf,
                            int sendcount,
                            MPI_Datatype sendtype,
                            void *recvbuf,
                            int recvcount,
                            MPI_Datatype recvtype,
                            MPIR_Comm *comm_ptr,
                            MPIR_Errflag_t *errflag );

extern int MPIR_Alltoall_ALG_MV2(
                            const void *sendbuf,
                            int sendcount,
                            MPI_Datatype sendtype,
                            void *recvbuf,
                            int recvcount,
                            MPI_Datatype recvtype,
                            MPIR_Comm *comm_ptr,
                            MPIR_Errflag_t *errflag );

extern int MPIR_Alltoall_RD_MV2(
                            const void *sendbuf,
                            int sendcount,
                            MPI_Datatype sendtype,
                            void *recvbuf,
                            int recvcount,
                            MPI_Datatype recvtype,
                            MPIR_Comm *comm_ptr,
                            MPIR_Errflag_t *errflag );


extern int MPIR_Alltoall_Scatter_dest_MV2(
                            const void *sendbuf,
                            int sendcount,
                            MPI_Datatype sendtype,
                            void *recvbuf,
                            int recvcount,
                            MPI_Datatype recvtype,
                            MPIR_Comm *comm_ptr,
                            MPIR_Errflag_t *errflag );



extern int MPIR_Alltoall_pairwise_MV2(
                            const void *sendbuf,
                            int sendcount,
                            MPI_Datatype sendtype,
                            void *recvbuf,
                            int recvcount,
                            MPI_Datatype recvtype,
                            MPIR_Comm *comm_ptr,
                            MPIR_Errflag_t *errflag );

extern int MPIR_Alltoall_inplace_MV2(
                            const void *sendbuf,
                            int sendcount,
                            MPI_Datatype sendtype,
                            void *recvbuf,
                            int recvcount,
                            MPI_Datatype recvtype,
                            MPIR_Comm *comm_ptr,
                            MPIR_Errflag_t *errflag ); 


/* Architecture detection tuning */
int MV2_set_alltoall_tuning_table(int heterogeneity, 
                                  struct coll_info *colls_arch_hca);

/* Function to clean free memory allocated by bcast tuning table*/
void MV2_cleanup_alltoall_tuning_table();

/* Function used inside ch3_shmem_coll.c to tune bcast thresholds */
int MV2_Alltoall_is_define(char *mv2_user_alltoall);

                                           

#endif


