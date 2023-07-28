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

#ifndef _ALLGATHERV_TUNING_
#define _ALLGATHERV_TUNING_

#include "mvp_coll_shmem.h"

#define NMATCH (3 + 1)

/* Allgatherv tuning flags
 * recursive doubling: MVP_INTER_ALLGATHERV_TUNING=1
 * bruck:              MVP_INTER_ALLGATHERV_TUNING=2
 * ring:               MVP_INTER_ALLGATHERV_TUNING=3
 * ring_cyclic:        MVP_INTER_ALLGATHERV_TUNING=4
 * Regular expression example:
 *   MVP_INTER_ALLGATHERV_TUNING=2:0-1024,1:1024-8192,3:8192-+
 *   meaning: use bruck for 0 byte to 1024 bytes
 *            use recursive doubling for 1024 byte to 8192 bytes
 *            use ring since 8192 bytes
 */

extern const char *mvp_user_allgatherv_inter;

extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_coll_timer_allgatherv_rec_doubling;
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_coll_timer_allgatherv_bruck;
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_coll_timer_allgatherv_ring;
extern MPIR_T_pvar_timer_t PVAR_TIMER_mvp_coll_timer_allgatherv_ring_cyclic;

extern unsigned long long PVAR_COUNTER_mvp_coll_allgatherv_rec_doubling;
extern unsigned long long PVAR_COUNTER_mvp_coll_allgatherv_bruck;
extern unsigned long long PVAR_COUNTER_mvp_coll_allgatherv_ring;
extern unsigned long long PVAR_COUNTER_mvp_coll_allgatherv_ring_cyclic;

extern unsigned long long
    PVAR_COUNTER_mvp_coll_allgatherv_rec_doubling_bytes_send;
extern unsigned long long PVAR_COUNTER_mvp_coll_allgatherv_bruck_bytes_send;
extern unsigned long long PVAR_COUNTER_mvp_coll_allgatherv_ring_bytes_send;
extern unsigned long long
    PVAR_COUNTER_mvp_coll_allgatherv_rec_doubling_bytes_recv;
extern unsigned long long PVAR_COUNTER_mvp_coll_allgatherv_bruck_bytes_recv;
extern unsigned long long PVAR_COUNTER_mvp_coll_allgatherv_ring_bytes_recv;
extern unsigned long long
    PVAR_COUNTER_mvp_coll_allgatherv_rec_doubling_count_send;
extern unsigned long long PVAR_COUNTER_mvp_coll_allgatherv_bruck_count_send;
extern unsigned long long PVAR_COUNTER_mvp_coll_allgatherv_ring_count_send;
extern unsigned long long
    PVAR_COUNTER_mvp_coll_allgatherv_rec_doubling_count_recv;
extern unsigned long long PVAR_COUNTER_mvp_coll_allgatherv_bruck_count_recv;
extern unsigned long long PVAR_COUNTER_mvp_coll_allgatherv_ring_count_recv;
extern unsigned long long PVAR_COUNTER_mvp_coll_allgatherv_bytes_send;
extern unsigned long long PVAR_COUNTER_mvp_coll_allgatherv_bytes_recv;
extern unsigned long long PVAR_COUNTER_mvp_coll_allgatherv_count_send;
extern unsigned long long PVAR_COUNTER_mvp_coll_allgatherv_count_recv;

typedef struct {
    int min;
    int max;
    int (*MVP_pt_Allgatherv_function)(const void *sendbuf, int sendcount,
                                      MPI_Datatype sendtype, void *recvbuf,
                                      const int *recvcounts, const int *displs,
                                      MPI_Datatype recvtype,
                                      MPIR_Comm *comm_ptr,
                                      MPIR_Errflag_t *errflag);
} mvp_allgatherv_tuning_element;

typedef struct {
    int numproc;
    int size_inter_table;
    mvp_allgatherv_tuning_element inter_leader[MVP_MAX_NB_THRESHOLDS];
} mvp_allgatherv_tuning_table;

extern int mvp_size_allgatherv_tuning_table;
extern mvp_allgatherv_tuning_table *mvp_allgatherv_thresholds_table;

extern int MPIR_Allgatherv_Rec_Doubling_MVP(
    const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf,
    const int *recvcounts, const int *displs, MPI_Datatype recvtype,
    MPIR_Comm *comm_ptr, MPIR_Errflag_t *errflag);

extern int MPIR_Allgatherv_Bruck_MVP(const void *sendbuf, int sendcount,
                                     MPI_Datatype sendtype, void *recvbuf,
                                     const int *recvcounts, const int *displs,
                                     MPI_Datatype recvtype, MPIR_Comm *comm_ptr,
                                     MPIR_Errflag_t *errflag);

extern int MPIR_Allgatherv_Ring_MVP(const void *sendbuf, int sendcount,
                                    MPI_Datatype sendtype, void *recvbuf,
                                    const int *recvcounts, const int *displs,
                                    MPI_Datatype recvtype, MPIR_Comm *comm_ptr,
                                    MPIR_Errflag_t *errflag);

extern int MPIR_Allgatherv_Ring_Cyclic_MVP(
    const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf,
    const int *recvcounts, const int *displs, MPI_Datatype recvtype,
    MPIR_Comm *comm_ptr, MPIR_Errflag_t *errflag);

/* Architecture detection tuning */
int MVP_set_allgatherv_tuning_table(int heterogeneity,
                                    struct coll_info *colls_arch_hca);

/* Function to clean free memory allocated by allgatherv tuning table*/
void MVP_cleanup_allgatherv_tuning_table();

/* Function used inside ch3_shmem_coll.c to tune allgatherv thresholds */
int MVP_internode_Allgatherv_is_define(const char *mvp_user_allgatherv_inter);
#endif
