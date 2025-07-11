/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#ifndef COLL_ALGOS_H_INCLUDED
#define COLL_ALGOS_H_INCLUDED

int MPIR_Barrier_allcomm_auto(MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Barrier_intra_k_dissemination(MPIR_Comm * comm_ptr, int k,
                                       MPIR_Errflag_t errflag);
int MPIR_Barrier_intra_recexch(MPIR_Comm * comm_ptr, int k,
                               int single_phase_recv, MPIR_Errflag_t errflag);
int MPIR_Barrier_intra_smp(MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Barrier_intra_osu_pairwise(MPIR_Comm * comm_ptr,
                                    MPIR_Errflag_t errflag);
int MPIR_Barrier_inter_bcast(MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Barrier_allcomm_nb(MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);;
int MPIR_Barrier_impl(MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Barrier(MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Ibarrier_allcomm_sched_auto(MPIR_Comm * comm_ptr, bool is_persistent,
                                     void **sched_p,
                                     enum MPIR_sched_type *sched_type_p);
int MPIR_Ibarrier_intra_sched_auto(MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Ibarrier_inter_sched_auto(MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Ibarrier_intra_sched_recursive_doubling(MPIR_Comm * comm_ptr,
                    MPIR_Sched_t s);
int MPIR_TSP_Ibarrier_sched_intra_recexch(MPIR_Comm * comm_ptr, int k,
                    MPIR_TSP_sched_t sched);
int MPIR_TSP_Ibarrier_sched_intra_k_dissemination(MPIR_Comm * comm_ptr, int k,
                    MPIR_TSP_sched_t sched);
int MPIR_Ibarrier_inter_sched_bcast(MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Ibarrier_sched_impl(MPIR_Comm * comm_ptr, bool is_persistent,
                             void **sched_p,
                             enum MPIR_sched_type *sched_type_p);
int MPIR_Ibarrier_impl(MPIR_Comm * comm_ptr, MPIR_Request ** request);
int MPIR_Ibarrier(MPIR_Comm * comm_ptr, MPIR_Request ** request);
int MPIR_Barrier_init_impl(MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                           MPIR_Request ** request);
int MPIR_Barrier_init(MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                      MPIR_Request ** request);
int MPIR_Bcast_allcomm_auto(void *buffer, MPI_Aint count, MPI_Datatype datatype,
                            int root, MPIR_Comm * comm_ptr,
                            MPIR_Errflag_t errflag);
int MPIR_Bcast_intra_binomial(void *buffer, MPI_Aint count,
                              MPI_Datatype datatype, int root,
                              MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Bcast_intra_scatter_recursive_doubling_allgather(void *buffer,
                    MPI_Aint count, MPI_Datatype datatype, int root,
                    MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Bcast_intra_scatter_ring_allgather(void *buffer, MPI_Aint count,
                    MPI_Datatype datatype, int root, MPIR_Comm * comm_ptr,
                    MPIR_Errflag_t errflag);
int MPIR_Bcast_intra_smp(void *buffer, MPI_Aint count, MPI_Datatype datatype,
                         int root, MPIR_Comm * comm_ptr,
                         MPIR_Errflag_t errflag);
int MPIR_Bcast_intra_tree(void *buffer, MPI_Aint count, MPI_Datatype datatype,
                          int root, MPIR_Comm * comm_ptr, int tree_type, int k,
                          int is_non_blocking, MPIR_Errflag_t errflag);
int MPIR_Bcast_intra_pipelined_tree(void *buffer, MPI_Aint count,
                                    MPI_Datatype datatype, int root,
                                    MPIR_Comm * comm_ptr, int tree_type, int k,
                                    int is_non_blocking, int chunk_size,
                                    int recv_pre_posted,
                                    MPIR_Errflag_t errflag);
int MPIR_Bcast_intra_osu_knomial(void *buffer, MPI_Aint count,
                                 MPI_Datatype datatype, int root,
                                 MPIR_Comm * comm_ptr, int inter_kf,
                                 int intra_kf, MPIR_Errflag_t errflag);
int MPIR_Bcast_intra_osu_pipelined(void *buffer, MPI_Aint count,
                                   MPI_Datatype datatype, int root,
                                   MPIR_Comm * comm_ptr, int seg_size,
                                   MPIR_Errflag_t errflag);
int MPIR_Bcast_inter_remote_send_local_bcast(void *buffer, MPI_Aint count,
                    MPI_Datatype datatype, int root, MPIR_Comm * comm_ptr,
                    MPIR_Errflag_t errflag);
int MPIR_Bcast_allcomm_nb(void *buffer, MPI_Aint count, MPI_Datatype datatype,
                          int root, MPIR_Comm * comm_ptr,
                          MPIR_Errflag_t errflag);;
int MPIR_Bcast_impl(void *buffer, MPI_Aint count, MPI_Datatype datatype,
                    int root, MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Bcast(void *buffer, MPI_Aint count, MPI_Datatype datatype, int root,
               MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Ibcast_allcomm_sched_auto(void *buffer, MPI_Aint count,
                                   MPI_Datatype datatype, int root,
                                   MPIR_Comm * comm_ptr, bool is_persistent,
                                   void **sched_p,
                                   enum MPIR_sched_type *sched_type_p);
int MPIR_Ibcast_intra_sched_auto(void *buffer, MPI_Aint count,
                                 MPI_Datatype datatype, int root,
                                 MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Ibcast_inter_sched_auto(void *buffer, MPI_Aint count,
                                 MPI_Datatype datatype, int root,
                                 MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Ibcast_intra_sched_binomial(void *buffer, MPI_Aint count,
                                     MPI_Datatype datatype, int root,
                                     MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Ibcast_intra_sched_smp(void *buffer, MPI_Aint count,
                                MPI_Datatype datatype, int root,
                                MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Ibcast_intra_sched_scatter_recursive_doubling_allgather(void *buffer,
                    MPI_Aint count, MPI_Datatype datatype, int root,
                    MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Ibcast_intra_sched_scatter_ring_allgather(void *buffer, MPI_Aint count,
                    MPI_Datatype datatype, int root, MPIR_Comm * comm_ptr,
                    MPIR_Sched_t s);
int MPIR_TSP_Ibcast_sched_intra_tree(void *buffer, MPI_Aint count,
                                     MPI_Datatype datatype, int root,
                                     MPIR_Comm * comm_ptr, int tree_type, int k,
                                     int chunk_size, MPIR_TSP_sched_t sched);
int MPIR_TSP_Ibcast_sched_intra_scatterv_allgatherv(void *buffer,
                    MPI_Aint count, MPI_Datatype datatype, int root,
                    MPIR_Comm * comm_ptr, int allgatherv_algo, int scatterv_k,
                    int allgatherv_k, MPIR_TSP_sched_t sched);
int MPIR_TSP_Ibcast_sched_intra_scatterv_ring_allgatherv(void *buffer,
                    MPI_Aint count, MPI_Datatype datatype, int root,
                    MPIR_Comm * comm_ptr, int scatterv_k,
                    MPIR_TSP_sched_t sched);
int MPIR_Ibcast_inter_sched_flat(void *buffer, MPI_Aint count,
                                 MPI_Datatype datatype, int root,
                                 MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Ibcast_sched_impl(void *buffer, MPI_Aint count, MPI_Datatype datatype,
                           int root, MPIR_Comm * comm_ptr, bool is_persistent,
                           void **sched_p, enum MPIR_sched_type *sched_type_p);
int MPIR_Ibcast_impl(void *buffer, MPI_Aint count, MPI_Datatype datatype,
                     int root, MPIR_Comm * comm_ptr, MPIR_Request ** request);
int MPIR_Ibcast(void *buffer, MPI_Aint count, MPI_Datatype datatype, int root,
                MPIR_Comm * comm_ptr, MPIR_Request ** request);
int MPIR_Bcast_init_impl(void *buffer, MPI_Aint count, MPI_Datatype datatype,
                         int root, MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                         MPIR_Request ** request);
int MPIR_Bcast_init(void *buffer, MPI_Aint count, MPI_Datatype datatype,
                    int root, MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                    MPIR_Request ** request);
int MPIR_Gather_allcomm_auto(const void *sendbuf, MPI_Aint sendcount,
                             MPI_Datatype sendtype, void *recvbuf,
                             MPI_Aint recvcount, MPI_Datatype recvtype,
                             int root, MPIR_Comm * comm_ptr,
                             MPIR_Errflag_t errflag);
int MPIR_Gather_intra_binomial(const void *sendbuf, MPI_Aint sendcount,
                               MPI_Datatype sendtype, void *recvbuf,
                               MPI_Aint recvcount, MPI_Datatype recvtype,
                               int root, MPIR_Comm * comm_ptr,
                               MPIR_Errflag_t errflag);
int MPIR_Gather_intra_osu_direct(const void *sendbuf, MPI_Aint sendcount,
                                 MPI_Datatype sendtype, void *recvbuf,
                                 MPI_Aint recvcount, MPI_Datatype recvtype,
                                 int root, MPIR_Comm * comm_ptr,
                                 MPIR_Errflag_t errflag);
int MPIR_Gather_intra_osu_direct_block(const void *sendbuf, MPI_Aint sendcount,
                                       MPI_Datatype sendtype, void *recvbuf,
                                       MPI_Aint recvcount,
                                       MPI_Datatype recvtype, int root,
                                       MPIR_Comm * comm_ptr,
                                       MPIR_Errflag_t errflag);
int MPIR_Gather_inter_linear(const void *sendbuf, MPI_Aint sendcount,
                             MPI_Datatype sendtype, void *recvbuf,
                             MPI_Aint recvcount, MPI_Datatype recvtype,
                             int root, MPIR_Comm * comm_ptr,
                             MPIR_Errflag_t errflag);
int MPIR_Gather_inter_local_gather_remote_send(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    MPI_Aint recvcount, MPI_Datatype recvtype, int root,
                    MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Gather_allcomm_nb(const void *sendbuf, MPI_Aint sendcount,
                           MPI_Datatype sendtype, void *recvbuf,
                           MPI_Aint recvcount, MPI_Datatype recvtype, int root,
                           MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);;
int MPIR_Gather_impl(const void *sendbuf, MPI_Aint sendcount,
                     MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount,
                     MPI_Datatype recvtype, int root, MPIR_Comm * comm_ptr,
                     MPIR_Errflag_t errflag);
int MPIR_Gather(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                int root, MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Igather_allcomm_sched_auto(const void *sendbuf, MPI_Aint sendcount,
                                    MPI_Datatype sendtype, void *recvbuf,
                                    MPI_Aint recvcount, MPI_Datatype recvtype,
                                    int root, MPIR_Comm * comm_ptr,
                                    bool is_persistent, void **sched_p,
                                    enum MPIR_sched_type *sched_type_p);
int MPIR_Igather_intra_sched_auto(const void *sendbuf, MPI_Aint sendcount,
                                  MPI_Datatype sendtype, void *recvbuf,
                                  MPI_Aint recvcount, MPI_Datatype recvtype,
                                  int root, MPIR_Comm * comm_ptr,
                                  MPIR_Sched_t s);
int MPIR_Igather_inter_sched_auto(const void *sendbuf, MPI_Aint sendcount,
                                  MPI_Datatype sendtype, void *recvbuf,
                                  MPI_Aint recvcount, MPI_Datatype recvtype,
                                  int root, MPIR_Comm * comm_ptr,
                                  MPIR_Sched_t s);
int MPIR_Igather_intra_sched_binomial(const void *sendbuf, MPI_Aint sendcount,
                                      MPI_Datatype sendtype, void *recvbuf,
                                      MPI_Aint recvcount, MPI_Datatype recvtype,
                                      int root, MPIR_Comm * comm_ptr,
                                      MPIR_Sched_t s);
int MPIR_TSP_Igather_sched_intra_tree(const void *sendbuf, MPI_Aint sendcount,
                                      MPI_Datatype sendtype, void *recvbuf,
                                      MPI_Aint recvcount, MPI_Datatype recvtype,
                                      int root, MPIR_Comm * comm_ptr, int k,
                                      MPIR_TSP_sched_t sched);
int MPIR_Igather_inter_sched_long(const void *sendbuf, MPI_Aint sendcount,
                                  MPI_Datatype sendtype, void *recvbuf,
                                  MPI_Aint recvcount, MPI_Datatype recvtype,
                                  int root, MPIR_Comm * comm_ptr,
                                  MPIR_Sched_t s);
int MPIR_Igather_inter_sched_short(const void *sendbuf, MPI_Aint sendcount,
                                   MPI_Datatype sendtype, void *recvbuf,
                                   MPI_Aint recvcount, MPI_Datatype recvtype,
                                   int root, MPIR_Comm * comm_ptr,
                                   MPIR_Sched_t s);
int MPIR_Igather_sched_impl(const void *sendbuf, MPI_Aint sendcount,
                            MPI_Datatype sendtype, void *recvbuf,
                            MPI_Aint recvcount, MPI_Datatype recvtype, int root,
                            MPIR_Comm * comm_ptr, bool is_persistent,
                            void **sched_p,
                            enum MPIR_sched_type *sched_type_p);
int MPIR_Igather_impl(const void *sendbuf, MPI_Aint sendcount,
                      MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount,
                      MPI_Datatype recvtype, int root, MPIR_Comm * comm_ptr,
                      MPIR_Request ** request);
int MPIR_Igather(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                 void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                 int root, MPIR_Comm * comm_ptr, MPIR_Request ** request);
int MPIR_Gather_init_impl(const void *sendbuf, MPI_Aint sendcount,
                          MPI_Datatype sendtype, void *recvbuf,
                          MPI_Aint recvcount, MPI_Datatype recvtype, int root,
                          MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                          MPIR_Request ** request);
int MPIR_Gather_init(const void *sendbuf, MPI_Aint sendcount,
                     MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount,
                     MPI_Datatype recvtype, int root, MPIR_Comm * comm_ptr,
                     MPIR_Info * info_ptr, MPIR_Request ** request);
int MPIR_Gatherv_allcomm_auto(const void *sendbuf, MPI_Aint sendcount,
                              MPI_Datatype sendtype, void *recvbuf,
                              const MPI_Aint recvcounts[],
                              const MPI_Aint displs[], MPI_Datatype recvtype,
                              int root, MPIR_Comm * comm_ptr,
                              MPIR_Errflag_t errflag);
int MPIR_Gatherv_allcomm_linear(const void *sendbuf, MPI_Aint sendcount,
                                MPI_Datatype sendtype, void *recvbuf,
                                const MPI_Aint recvcounts[],
                                const MPI_Aint displs[], MPI_Datatype recvtype,
                                int root, MPIR_Comm * comm_ptr,
                                MPIR_Errflag_t errflag);
int MPIR_Gatherv_allcomm_nb(const void *sendbuf, MPI_Aint sendcount,
                            MPI_Datatype sendtype, void *recvbuf,
                            const MPI_Aint recvcounts[],
                            const MPI_Aint displs[], MPI_Datatype recvtype,
                            int root, MPIR_Comm * comm_ptr,
                            MPIR_Errflag_t errflag);;
int MPIR_Gatherv_impl(const void *sendbuf, MPI_Aint sendcount,
                      MPI_Datatype sendtype, void *recvbuf,
                      const MPI_Aint recvcounts[], const MPI_Aint displs[],
                      MPI_Datatype recvtype, int root, MPIR_Comm * comm_ptr,
                      MPIR_Errflag_t errflag);
int MPIR_Gatherv(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                 void *recvbuf, const MPI_Aint recvcounts[],
                 const MPI_Aint displs[], MPI_Datatype recvtype, int root,
                 MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Igatherv_allcomm_sched_auto(const void *sendbuf, MPI_Aint sendcount,
                                     MPI_Datatype sendtype, void *recvbuf,
                                     const MPI_Aint recvcounts[],
                                     const MPI_Aint displs[],
                                     MPI_Datatype recvtype, int root,
                                     MPIR_Comm * comm_ptr, bool is_persistent,
                                     void **sched_p,
                                     enum MPIR_sched_type *sched_type_p);
int MPIR_Igatherv_intra_sched_auto(const void *sendbuf, MPI_Aint sendcount,
                                   MPI_Datatype sendtype, void *recvbuf,
                                   const MPI_Aint recvcounts[],
                                   const MPI_Aint displs[],
                                   MPI_Datatype recvtype, int root,
                                   MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Igatherv_inter_sched_auto(const void *sendbuf, MPI_Aint sendcount,
                                   MPI_Datatype sendtype, void *recvbuf,
                                   const MPI_Aint recvcounts[],
                                   const MPI_Aint displs[],
                                   MPI_Datatype recvtype, int root,
                                   MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Igatherv_allcomm_sched_linear(const void *sendbuf, MPI_Aint sendcount,
                                       MPI_Datatype sendtype, void *recvbuf,
                                       const MPI_Aint recvcounts[],
                                       const MPI_Aint displs[],
                                       MPI_Datatype recvtype, int root,
                                       MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_TSP_Igatherv_sched_allcomm_linear(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint displs[],
                    MPI_Datatype recvtype, int root, MPIR_Comm * comm_ptr,
                    MPIR_TSP_sched_t sched);
int MPIR_Igatherv_sched_impl(const void *sendbuf, MPI_Aint sendcount,
                             MPI_Datatype sendtype, void *recvbuf,
                             const MPI_Aint recvcounts[],
                             const MPI_Aint displs[], MPI_Datatype recvtype,
                             int root, MPIR_Comm * comm_ptr, bool is_persistent,
                             void **sched_p,
                             enum MPIR_sched_type *sched_type_p);
int MPIR_Igatherv_impl(const void *sendbuf, MPI_Aint sendcount,
                       MPI_Datatype sendtype, void *recvbuf,
                       const MPI_Aint recvcounts[], const MPI_Aint displs[],
                       MPI_Datatype recvtype, int root, MPIR_Comm * comm_ptr,
                       MPIR_Request ** request);
int MPIR_Igatherv(const void *sendbuf, MPI_Aint sendcount,
                  MPI_Datatype sendtype, void *recvbuf,
                  const MPI_Aint recvcounts[], const MPI_Aint displs[],
                  MPI_Datatype recvtype, int root, MPIR_Comm * comm_ptr,
                  MPIR_Request ** request);
int MPIR_Gatherv_init_impl(const void *sendbuf, MPI_Aint sendcount,
                           MPI_Datatype sendtype, void *recvbuf,
                           const MPI_Aint recvcounts[], const MPI_Aint displs[],
                           MPI_Datatype recvtype, int root,
                           MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                           MPIR_Request ** request);
int MPIR_Gatherv_init(const void *sendbuf, MPI_Aint sendcount,
                      MPI_Datatype sendtype, void *recvbuf,
                      const MPI_Aint recvcounts[], const MPI_Aint displs[],
                      MPI_Datatype recvtype, int root, MPIR_Comm * comm_ptr,
                      MPIR_Info * info_ptr, MPIR_Request ** request);
int MPIR_Scatter_allcomm_auto(const void *sendbuf, MPI_Aint sendcount,
                              MPI_Datatype sendtype, void *recvbuf,
                              MPI_Aint recvcount, MPI_Datatype recvtype,
                              int root, MPIR_Comm * comm_ptr,
                              MPIR_Errflag_t errflag);
int MPIR_Scatter_intra_binomial(const void *sendbuf, MPI_Aint sendcount,
                                MPI_Datatype sendtype, void *recvbuf,
                                MPI_Aint recvcount, MPI_Datatype recvtype,
                                int root, MPIR_Comm * comm_ptr,
                                MPIR_Errflag_t errflag);
int MPIR_Scatter_intra_osu_direct(const void *sendbuf, MPI_Aint sendcount,
                                  MPI_Datatype sendtype, void *recvbuf,
                                  MPI_Aint recvcount, MPI_Datatype recvtype,
                                  int root, MPIR_Comm * comm_ptr,
                                  MPIR_Errflag_t errflag);
int MPIR_Scatter_inter_linear(const void *sendbuf, MPI_Aint sendcount,
                              MPI_Datatype sendtype, void *recvbuf,
                              MPI_Aint recvcount, MPI_Datatype recvtype,
                              int root, MPIR_Comm * comm_ptr,
                              MPIR_Errflag_t errflag);
int MPIR_Scatter_inter_remote_send_local_scatter(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    MPI_Aint recvcount, MPI_Datatype recvtype, int root,
                    MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Scatter_allcomm_nb(const void *sendbuf, MPI_Aint sendcount,
                            MPI_Datatype sendtype, void *recvbuf,
                            MPI_Aint recvcount, MPI_Datatype recvtype, int root,
                            MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);;
int MPIR_Scatter_impl(const void *sendbuf, MPI_Aint sendcount,
                      MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount,
                      MPI_Datatype recvtype, int root, MPIR_Comm * comm_ptr,
                      MPIR_Errflag_t errflag);
int MPIR_Scatter(const void *sendbuf, MPI_Aint sendcount, MPI_Datatype sendtype,
                 void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                 int root, MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Iscatter_allcomm_sched_auto(const void *sendbuf, MPI_Aint sendcount,
                                     MPI_Datatype sendtype, void *recvbuf,
                                     MPI_Aint recvcount, MPI_Datatype recvtype,
                                     int root, MPIR_Comm * comm_ptr,
                                     bool is_persistent, void **sched_p,
                                     enum MPIR_sched_type *sched_type_p);
int MPIR_Iscatter_intra_sched_auto(const void *sendbuf, MPI_Aint sendcount,
                                   MPI_Datatype sendtype, void *recvbuf,
                                   MPI_Aint recvcount, MPI_Datatype recvtype,
                                   int root, MPIR_Comm * comm_ptr,
                                   MPIR_Sched_t s);
int MPIR_Iscatter_inter_sched_auto(const void *sendbuf, MPI_Aint sendcount,
                                   MPI_Datatype sendtype, void *recvbuf,
                                   MPI_Aint recvcount, MPI_Datatype recvtype,
                                   int root, MPIR_Comm * comm_ptr,
                                   MPIR_Sched_t s);
int MPIR_Iscatter_intra_sched_binomial(const void *sendbuf, MPI_Aint sendcount,
                                       MPI_Datatype sendtype, void *recvbuf,
                                       MPI_Aint recvcount,
                                       MPI_Datatype recvtype, int root,
                                       MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_TSP_Iscatter_sched_intra_tree(const void *sendbuf, MPI_Aint sendcount,
                                       MPI_Datatype sendtype, void *recvbuf,
                                       MPI_Aint recvcount,
                                       MPI_Datatype recvtype, int root,
                                       MPIR_Comm * comm_ptr, int k,
                                       MPIR_TSP_sched_t sched);
int MPIR_Iscatter_inter_sched_linear(const void *sendbuf, MPI_Aint sendcount,
                                     MPI_Datatype sendtype, void *recvbuf,
                                     MPI_Aint recvcount, MPI_Datatype recvtype,
                                     int root, MPIR_Comm * comm_ptr,
                                     MPIR_Sched_t s);
int MPIR_Iscatter_inter_sched_remote_send_local_scatter(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    MPI_Aint recvcount, MPI_Datatype recvtype, int root,
                    MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Iscatter_sched_impl(const void *sendbuf, MPI_Aint sendcount,
                             MPI_Datatype sendtype, void *recvbuf,
                             MPI_Aint recvcount, MPI_Datatype recvtype,
                             int root, MPIR_Comm * comm_ptr, bool is_persistent,
                             void **sched_p,
                             enum MPIR_sched_type *sched_type_p);
int MPIR_Iscatter_impl(const void *sendbuf, MPI_Aint sendcount,
                       MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount,
                       MPI_Datatype recvtype, int root, MPIR_Comm * comm_ptr,
                       MPIR_Request ** request);
int MPIR_Iscatter(const void *sendbuf, MPI_Aint sendcount,
                  MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount,
                  MPI_Datatype recvtype, int root, MPIR_Comm * comm_ptr,
                  MPIR_Request ** request);
int MPIR_Scatter_init_impl(const void *sendbuf, MPI_Aint sendcount,
                           MPI_Datatype sendtype, void *recvbuf,
                           MPI_Aint recvcount, MPI_Datatype recvtype, int root,
                           MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                           MPIR_Request ** request);
int MPIR_Scatter_init(const void *sendbuf, MPI_Aint sendcount,
                      MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount,
                      MPI_Datatype recvtype, int root, MPIR_Comm * comm_ptr,
                      MPIR_Info * info_ptr, MPIR_Request ** request);
int MPIR_Scatterv_allcomm_auto(const void *sendbuf, const MPI_Aint sendcounts[],
                               const MPI_Aint displs[], MPI_Datatype sendtype,
                               void *recvbuf, MPI_Aint recvcount,
                               MPI_Datatype recvtype, int root,
                               MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Scatterv_allcomm_linear(const void *sendbuf,
                                 const MPI_Aint sendcounts[],
                                 const MPI_Aint displs[], MPI_Datatype sendtype,
                                 void *recvbuf, MPI_Aint recvcount,
                                 MPI_Datatype recvtype, int root,
                                 MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Scatterv_allcomm_nb(const void *sendbuf, const MPI_Aint sendcounts[],
                             const MPI_Aint displs[], MPI_Datatype sendtype,
                             void *recvbuf, MPI_Aint recvcount,
                             MPI_Datatype recvtype, int root,
                             MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);;
int MPIR_Scatterv_impl(const void *sendbuf, const MPI_Aint sendcounts[],
                       const MPI_Aint displs[], MPI_Datatype sendtype,
                       void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                       int root, MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Scatterv(const void *sendbuf, const MPI_Aint sendcounts[],
                  const MPI_Aint displs[], MPI_Datatype sendtype, void *recvbuf,
                  MPI_Aint recvcount, MPI_Datatype recvtype, int root,
                  MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Iscatterv_allcomm_sched_auto(const void *sendbuf,
                                      const MPI_Aint sendcounts[],
                                      const MPI_Aint displs[],
                                      MPI_Datatype sendtype, void *recvbuf,
                                      MPI_Aint recvcount, MPI_Datatype recvtype,
                                      int root, MPIR_Comm * comm_ptr,
                                      bool is_persistent, void **sched_p,
                                      enum MPIR_sched_type *sched_type_p);
int MPIR_Iscatterv_intra_sched_auto(const void *sendbuf,
                                    const MPI_Aint sendcounts[],
                                    const MPI_Aint displs[],
                                    MPI_Datatype sendtype, void *recvbuf,
                                    MPI_Aint recvcount, MPI_Datatype recvtype,
                                    int root, MPIR_Comm * comm_ptr,
                                    MPIR_Sched_t s);
int MPIR_Iscatterv_inter_sched_auto(const void *sendbuf,
                                    const MPI_Aint sendcounts[],
                                    const MPI_Aint displs[],
                                    MPI_Datatype sendtype, void *recvbuf,
                                    MPI_Aint recvcount, MPI_Datatype recvtype,
                                    int root, MPIR_Comm * comm_ptr,
                                    MPIR_Sched_t s);
int MPIR_Iscatterv_allcomm_sched_linear(const void *sendbuf,
                                        const MPI_Aint sendcounts[],
                                        const MPI_Aint displs[],
                                        MPI_Datatype sendtype, void *recvbuf,
                                        MPI_Aint recvcount,
                                        MPI_Datatype recvtype, int root,
                                        MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_TSP_Iscatterv_sched_allcomm_linear(const void *sendbuf,
                    const MPI_Aint sendcounts[], const MPI_Aint displs[],
                    MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount,
                    MPI_Datatype recvtype, int root, MPIR_Comm * comm_ptr,
                    MPIR_TSP_sched_t sched);
int MPIR_Iscatterv_sched_impl(const void *sendbuf, const MPI_Aint sendcounts[],
                              const MPI_Aint displs[], MPI_Datatype sendtype,
                              void *recvbuf, MPI_Aint recvcount,
                              MPI_Datatype recvtype, int root,
                              MPIR_Comm * comm_ptr, bool is_persistent,
                              void **sched_p,
                              enum MPIR_sched_type *sched_type_p);
int MPIR_Iscatterv_impl(const void *sendbuf, const MPI_Aint sendcounts[],
                        const MPI_Aint displs[], MPI_Datatype sendtype,
                        void *recvbuf, MPI_Aint recvcount,
                        MPI_Datatype recvtype, int root, MPIR_Comm * comm_ptr,
                        MPIR_Request ** request);
int MPIR_Iscatterv(const void *sendbuf, const MPI_Aint sendcounts[],
                   const MPI_Aint displs[], MPI_Datatype sendtype,
                   void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                   int root, MPIR_Comm * comm_ptr, MPIR_Request ** request);
int MPIR_Scatterv_init_impl(const void *sendbuf, const MPI_Aint sendcounts[],
                            const MPI_Aint displs[], MPI_Datatype sendtype,
                            void *recvbuf, MPI_Aint recvcount,
                            MPI_Datatype recvtype, int root,
                            MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                            MPIR_Request ** request);
int MPIR_Scatterv_init(const void *sendbuf, const MPI_Aint sendcounts[],
                       const MPI_Aint displs[], MPI_Datatype sendtype,
                       void *recvbuf, MPI_Aint recvcount, MPI_Datatype recvtype,
                       int root, MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                       MPIR_Request ** request);
int MPIR_Allgather_allcomm_auto(const void *sendbuf, MPI_Aint sendcount,
                                MPI_Datatype sendtype, void *recvbuf,
                                MPI_Aint recvcount, MPI_Datatype recvtype,
                                MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Allgather_intra_brucks(const void *sendbuf, MPI_Aint sendcount,
                                MPI_Datatype sendtype, void *recvbuf,
                                MPI_Aint recvcount, MPI_Datatype recvtype,
                                MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Allgather_intra_k_brucks(const void *sendbuf, MPI_Aint sendcount,
                                  MPI_Datatype sendtype, void *recvbuf,
                                  MPI_Aint recvcount, MPI_Datatype recvtype,
                                  MPIR_Comm * comm_ptr, int k,
                                  MPIR_Errflag_t errflag);
int MPIR_Allgather_intra_recursive_doubling(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    MPI_Aint recvcount, MPI_Datatype recvtype,
                    MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Allgather_intra_ring(const void *sendbuf, MPI_Aint sendcount,
                              MPI_Datatype sendtype, void *recvbuf,
                              MPI_Aint recvcount, MPI_Datatype recvtype,
                              MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Allgather_intra_recexch(const void *sendbuf, MPI_Aint sendcount,
                                 MPI_Datatype sendtype, void *recvbuf,
                                 MPI_Aint recvcount, MPI_Datatype recvtype,
                                 MPIR_Comm * comm_ptr, int recexch_type, int k,
                                 int single_phase_recv,
                                 MPIR_Errflag_t errflag);
int MPIR_Allgather_intra_osu_direct(const void *sendbuf, MPI_Aint sendcount,
                                    MPI_Datatype sendtype, void *recvbuf,
                                    MPI_Aint recvcount, MPI_Datatype recvtype,
                                    MPIR_Comm * comm_ptr,
                                    MPIR_Errflag_t errflag);
int MPIR_Allgather_intra_osu_direct_spread(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    MPI_Aint recvcount, MPI_Datatype recvtype,
                    MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Allgather_intra_osu_gather_bcast(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    MPI_Aint recvcount, MPI_Datatype recvtype,
                    MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Allgather_inter_local_gather_remote_bcast(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    MPI_Aint recvcount, MPI_Datatype recvtype,
                    MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Allgather_allcomm_nb(const void *sendbuf, MPI_Aint sendcount,
                              MPI_Datatype sendtype, void *recvbuf,
                              MPI_Aint recvcount, MPI_Datatype recvtype,
                              MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);;
int MPIR_Allgather_impl(const void *sendbuf, MPI_Aint sendcount,
                        MPI_Datatype sendtype, void *recvbuf,
                        MPI_Aint recvcount, MPI_Datatype recvtype,
                        MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Allgather(const void *sendbuf, MPI_Aint sendcount,
                   MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount,
                   MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                   MPIR_Errflag_t errflag);
int MPIR_Iallgather_allcomm_sched_auto(const void *sendbuf, MPI_Aint sendcount,
                                       MPI_Datatype sendtype, void *recvbuf,
                                       MPI_Aint recvcount,
                                       MPI_Datatype recvtype,
                                       MPIR_Comm * comm_ptr, bool is_persistent,
                                       void **sched_p,
                                       enum MPIR_sched_type *sched_type_p);
int MPIR_Iallgather_intra_sched_auto(const void *sendbuf, MPI_Aint sendcount,
                                     MPI_Datatype sendtype, void *recvbuf,
                                     MPI_Aint recvcount, MPI_Datatype recvtype,
                                     MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Iallgather_inter_sched_auto(const void *sendbuf, MPI_Aint sendcount,
                                     MPI_Datatype sendtype, void *recvbuf,
                                     MPI_Aint recvcount, MPI_Datatype recvtype,
                                     MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Iallgather_intra_sched_ring(const void *sendbuf, MPI_Aint sendcount,
                                     MPI_Datatype sendtype, void *recvbuf,
                                     MPI_Aint recvcount, MPI_Datatype recvtype,
                                     MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Iallgather_intra_sched_brucks(const void *sendbuf, MPI_Aint sendcount,
                                       MPI_Datatype sendtype, void *recvbuf,
                                       MPI_Aint recvcount,
                                       MPI_Datatype recvtype,
                                       MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Iallgather_intra_sched_recursive_doubling(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    MPI_Aint recvcount, MPI_Datatype recvtype,
                    MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_TSP_Iallgather_sched_intra_ring(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    MPI_Aint recvcount, MPI_Datatype recvtype,
                    MPIR_Comm * comm_ptr, MPIR_TSP_sched_t sched);
int MPIR_TSP_Iallgather_sched_intra_brucks(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    MPI_Aint recvcount, MPI_Datatype recvtype,
                    MPIR_Comm * comm_ptr, int k, MPIR_TSP_sched_t sched);
int MPIR_TSP_Iallgather_sched_intra_recexch(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    MPI_Aint recvcount, MPI_Datatype recvtype,
                    MPIR_Comm * comm_ptr, int recexch_type, int k,
                    MPIR_TSP_sched_t sched);
int MPIR_Iallgather_inter_sched_local_gather_remote_bcast(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    MPI_Aint recvcount, MPI_Datatype recvtype,
                    MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Iallgather_sched_impl(const void *sendbuf, MPI_Aint sendcount,
                               MPI_Datatype sendtype, void *recvbuf,
                               MPI_Aint recvcount, MPI_Datatype recvtype,
                               MPIR_Comm * comm_ptr, bool is_persistent,
                               void **sched_p,
                               enum MPIR_sched_type *sched_type_p);
int MPIR_Iallgather_impl(const void *sendbuf, MPI_Aint sendcount,
                         MPI_Datatype sendtype, void *recvbuf,
                         MPI_Aint recvcount, MPI_Datatype recvtype,
                         MPIR_Comm * comm_ptr, MPIR_Request ** request);
int MPIR_Iallgather(const void *sendbuf, MPI_Aint sendcount,
                    MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount,
                    MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                    MPIR_Request ** request);
int MPIR_Allgather_init_impl(const void *sendbuf, MPI_Aint sendcount,
                             MPI_Datatype sendtype, void *recvbuf,
                             MPI_Aint recvcount, MPI_Datatype recvtype,
                             MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                             MPIR_Request ** request);
int MPIR_Allgather_init(const void *sendbuf, MPI_Aint sendcount,
                        MPI_Datatype sendtype, void *recvbuf,
                        MPI_Aint recvcount, MPI_Datatype recvtype,
                        MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                        MPIR_Request ** request);
int MPIR_Allgatherv_allcomm_auto(const void *sendbuf, MPI_Aint sendcount,
                                 MPI_Datatype sendtype, void *recvbuf,
                                 const MPI_Aint recvcounts[],
                                 const MPI_Aint displs[], MPI_Datatype recvtype,
                                 MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Allgatherv_intra_brucks(const void *sendbuf, MPI_Aint sendcount,
                                 MPI_Datatype sendtype, void *recvbuf,
                                 const MPI_Aint recvcounts[],
                                 const MPI_Aint displs[], MPI_Datatype recvtype,
                                 MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Allgatherv_intra_recursive_doubling(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint displs[],
                    MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                    MPIR_Errflag_t errflag);
int MPIR_Allgatherv_intra_ring(const void *sendbuf, MPI_Aint sendcount,
                               MPI_Datatype sendtype, void *recvbuf,
                               const MPI_Aint recvcounts[],
                               const MPI_Aint displs[], MPI_Datatype recvtype,
                               MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Allgatherv_inter_remote_gather_local_bcast(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint displs[],
                    MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                    MPIR_Errflag_t errflag);
int MPIR_Allgatherv_allcomm_nb(const void *sendbuf, MPI_Aint sendcount,
                               MPI_Datatype sendtype, void *recvbuf,
                               const MPI_Aint recvcounts[],
                               const MPI_Aint displs[], MPI_Datatype recvtype,
                               MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);;
int MPIR_Allgatherv_impl(const void *sendbuf, MPI_Aint sendcount,
                         MPI_Datatype sendtype, void *recvbuf,
                         const MPI_Aint recvcounts[], const MPI_Aint displs[],
                         MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                         MPIR_Errflag_t errflag);
int MPIR_Allgatherv(const void *sendbuf, MPI_Aint sendcount,
                    MPI_Datatype sendtype, void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint displs[],
                    MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                    MPIR_Errflag_t errflag);
int MPIR_Iallgatherv_allcomm_sched_auto(const void *sendbuf, MPI_Aint sendcount,
                                        MPI_Datatype sendtype, void *recvbuf,
                                        const MPI_Aint recvcounts[],
                                        const MPI_Aint displs[],
                                        MPI_Datatype recvtype,
                                        MPIR_Comm * comm_ptr,
                                        bool is_persistent, void **sched_p,
                                        enum MPIR_sched_type *sched_type_p);
int MPIR_Iallgatherv_intra_sched_auto(const void *sendbuf, MPI_Aint sendcount,
                                      MPI_Datatype sendtype, void *recvbuf,
                                      const MPI_Aint recvcounts[],
                                      const MPI_Aint displs[],
                                      MPI_Datatype recvtype,
                                      MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Iallgatherv_inter_sched_auto(const void *sendbuf, MPI_Aint sendcount,
                                      MPI_Datatype sendtype, void *recvbuf,
                                      const MPI_Aint recvcounts[],
                                      const MPI_Aint displs[],
                                      MPI_Datatype recvtype,
                                      MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Iallgatherv_intra_sched_brucks(const void *sendbuf, MPI_Aint sendcount,
                                        MPI_Datatype sendtype, void *recvbuf,
                                        const MPI_Aint recvcounts[],
                                        const MPI_Aint displs[],
                                        MPI_Datatype recvtype,
                                        MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Iallgatherv_intra_sched_recursive_doubling(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint displs[],
                    MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                    MPIR_Sched_t s);
int MPIR_Iallgatherv_intra_sched_ring(const void *sendbuf, MPI_Aint sendcount,
                                      MPI_Datatype sendtype, void *recvbuf,
                                      const MPI_Aint recvcounts[],
                                      const MPI_Aint displs[],
                                      MPI_Datatype recvtype,
                                      MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_TSP_Iallgatherv_sched_intra_recexch(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint displs[],
                    MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                    int recexch_type, int k, MPIR_TSP_sched_t sched);
int MPIR_TSP_Iallgatherv_sched_intra_ring(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint displs[],
                    MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                    MPIR_TSP_sched_t sched);
int MPIR_TSP_Iallgatherv_sched_intra_brucks(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint displs[],
                    MPI_Datatype recvtype, MPIR_Comm * comm_ptr, int k,
                    MPIR_TSP_sched_t sched);
int MPIR_Iallgatherv_inter_sched_remote_gather_local_bcast(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint displs[],
                    MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                    MPIR_Sched_t s);
int MPIR_Iallgatherv_sched_impl(const void *sendbuf, MPI_Aint sendcount,
                                MPI_Datatype sendtype, void *recvbuf,
                                const MPI_Aint recvcounts[],
                                const MPI_Aint displs[], MPI_Datatype recvtype,
                                MPIR_Comm * comm_ptr, bool is_persistent,
                                void **sched_p,
                                enum MPIR_sched_type *sched_type_p);
int MPIR_Iallgatherv_impl(const void *sendbuf, MPI_Aint sendcount,
                          MPI_Datatype sendtype, void *recvbuf,
                          const MPI_Aint recvcounts[], const MPI_Aint displs[],
                          MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                          MPIR_Request ** request);
int MPIR_Iallgatherv(const void *sendbuf, MPI_Aint sendcount,
                     MPI_Datatype sendtype, void *recvbuf,
                     const MPI_Aint recvcounts[], const MPI_Aint displs[],
                     MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                     MPIR_Request ** request);
int MPIR_Allgatherv_init_impl(const void *sendbuf, MPI_Aint sendcount,
                              MPI_Datatype sendtype, void *recvbuf,
                              const MPI_Aint recvcounts[],
                              const MPI_Aint displs[], MPI_Datatype recvtype,
                              MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                              MPIR_Request ** request);
int MPIR_Allgatherv_init(const void *sendbuf, MPI_Aint sendcount,
                         MPI_Datatype sendtype, void *recvbuf,
                         const MPI_Aint recvcounts[], const MPI_Aint displs[],
                         MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                         MPIR_Info * info_ptr, MPIR_Request ** request);
int MPIR_Alltoall_allcomm_auto(const void *sendbuf, MPI_Aint sendcount,
                               MPI_Datatype sendtype, void *recvbuf,
                               MPI_Aint recvcount, MPI_Datatype recvtype,
                               MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Alltoall_intra_brucks(const void *sendbuf, MPI_Aint sendcount,
                               MPI_Datatype sendtype, void *recvbuf,
                               MPI_Aint recvcount, MPI_Datatype recvtype,
                               MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Alltoall_intra_k_brucks(const void *sendbuf, MPI_Aint sendcount,
                                 MPI_Datatype sendtype, void *recvbuf,
                                 MPI_Aint recvcount, MPI_Datatype recvtype,
                                 MPIR_Comm * comm_ptr, int k,
                                 MPIR_Errflag_t errflag);
int MPIR_Alltoall_intra_pairwise(const void *sendbuf, MPI_Aint sendcount,
                                 MPI_Datatype sendtype, void *recvbuf,
                                 MPI_Aint recvcount, MPI_Datatype recvtype,
                                 MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Alltoall_intra_pairwise_sendrecv_replace(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    MPI_Aint recvcount, MPI_Datatype recvtype,
                    MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Alltoall_intra_scattered(const void *sendbuf, MPI_Aint sendcount,
                                  MPI_Datatype sendtype, void *recvbuf,
                                  MPI_Aint recvcount, MPI_Datatype recvtype,
                                  MPIR_Comm * comm_ptr,
                                  MPIR_Errflag_t errflag);
int MPIR_Alltoall_inter_pairwise_exchange(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    MPI_Aint recvcount, MPI_Datatype recvtype,
                    MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Alltoall_allcomm_nb(const void *sendbuf, MPI_Aint sendcount,
                             MPI_Datatype sendtype, void *recvbuf,
                             MPI_Aint recvcount, MPI_Datatype recvtype,
                             MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);;
int MPIR_Alltoall_impl(const void *sendbuf, MPI_Aint sendcount,
                       MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount,
                       MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                       MPIR_Errflag_t errflag);
int MPIR_Alltoall(const void *sendbuf, MPI_Aint sendcount,
                  MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount,
                  MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                  MPIR_Errflag_t errflag);
int MPIR_Ialltoall_allcomm_sched_auto(const void *sendbuf, MPI_Aint sendcount,
                                      MPI_Datatype sendtype, void *recvbuf,
                                      MPI_Aint recvcount, MPI_Datatype recvtype,
                                      MPIR_Comm * comm_ptr, bool is_persistent,
                                      void **sched_p,
                                      enum MPIR_sched_type *sched_type_p);
int MPIR_Ialltoall_intra_sched_auto(const void *sendbuf, MPI_Aint sendcount,
                                    MPI_Datatype sendtype, void *recvbuf,
                                    MPI_Aint recvcount, MPI_Datatype recvtype,
                                    MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Ialltoall_inter_sched_auto(const void *sendbuf, MPI_Aint sendcount,
                                    MPI_Datatype sendtype, void *recvbuf,
                                    MPI_Aint recvcount, MPI_Datatype recvtype,
                                    MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Ialltoall_intra_sched_brucks(const void *sendbuf, MPI_Aint sendcount,
                                      MPI_Datatype sendtype, void *recvbuf,
                                      MPI_Aint recvcount, MPI_Datatype recvtype,
                                      MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Ialltoall_intra_sched_inplace(const void *sendbuf, MPI_Aint sendcount,
                                       MPI_Datatype sendtype, void *recvbuf,
                                       MPI_Aint recvcount,
                                       MPI_Datatype recvtype,
                                       MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Ialltoall_intra_sched_pairwise(const void *sendbuf, MPI_Aint sendcount,
                                        MPI_Datatype sendtype, void *recvbuf,
                                        MPI_Aint recvcount,
                                        MPI_Datatype recvtype,
                                        MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Ialltoall_intra_sched_permuted_sendrecv(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    MPI_Aint recvcount, MPI_Datatype recvtype,
                    MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_TSP_Ialltoall_sched_intra_ring(const void *sendbuf, MPI_Aint sendcount,
                                        MPI_Datatype sendtype, void *recvbuf,
                                        MPI_Aint recvcount,
                                        MPI_Datatype recvtype,
                                        MPIR_Comm * comm_ptr,
                                        MPIR_TSP_sched_t sched);
int MPIR_TSP_Ialltoall_sched_intra_brucks(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    MPI_Aint recvcount, MPI_Datatype recvtype,
                    MPIR_Comm * comm_ptr, int k, int buffer_per_phase,
                    MPIR_TSP_sched_t sched);
int MPIR_TSP_Ialltoall_sched_intra_scattered(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    MPI_Aint recvcount, MPI_Datatype recvtype,
                    MPIR_Comm * comm_ptr, int batch_size, int bblock,
                    MPIR_TSP_sched_t sched);
int MPIR_Ialltoall_inter_sched_pairwise_exchange(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    MPI_Aint recvcount, MPI_Datatype recvtype,
                    MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Ialltoall_sched_impl(const void *sendbuf, MPI_Aint sendcount,
                              MPI_Datatype sendtype, void *recvbuf,
                              MPI_Aint recvcount, MPI_Datatype recvtype,
                              MPIR_Comm * comm_ptr, bool is_persistent,
                              void **sched_p,
                              enum MPIR_sched_type *sched_type_p);
int MPIR_Ialltoall_impl(const void *sendbuf, MPI_Aint sendcount,
                        MPI_Datatype sendtype, void *recvbuf,
                        MPI_Aint recvcount, MPI_Datatype recvtype,
                        MPIR_Comm * comm_ptr, MPIR_Request ** request);
int MPIR_Ialltoall(const void *sendbuf, MPI_Aint sendcount,
                   MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount,
                   MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                   MPIR_Request ** request);
int MPIR_Alltoall_init_impl(const void *sendbuf, MPI_Aint sendcount,
                            MPI_Datatype sendtype, void *recvbuf,
                            MPI_Aint recvcount, MPI_Datatype recvtype,
                            MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                            MPIR_Request ** request);
int MPIR_Alltoall_init(const void *sendbuf, MPI_Aint sendcount,
                       MPI_Datatype sendtype, void *recvbuf, MPI_Aint recvcount,
                       MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                       MPIR_Info * info_ptr, MPIR_Request ** request);
int MPIR_Alltoallv_allcomm_auto(const void *sendbuf,
                                const MPI_Aint sendcounts[],
                                const MPI_Aint sdispls[], MPI_Datatype sendtype,
                                void *recvbuf, const MPI_Aint recvcounts[],
                                const MPI_Aint rdispls[], MPI_Datatype recvtype,
                                MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Alltoallv_intra_pairwise_sendrecv_replace(const void *sendbuf,
                    const MPI_Aint sendcounts[], const MPI_Aint sdispls[],
                    MPI_Datatype sendtype, void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                    MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                    MPIR_Errflag_t errflag);
int MPIR_Alltoallv_intra_scattered(const void *sendbuf,
                                   const MPI_Aint sendcounts[],
                                   const MPI_Aint sdispls[],
                                   MPI_Datatype sendtype, void *recvbuf,
                                   const MPI_Aint recvcounts[],
                                   const MPI_Aint rdispls[],
                                   MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                                   MPIR_Errflag_t errflag);
int MPIR_Alltoallv_inter_pairwise_exchange(const void *sendbuf,
                    const MPI_Aint sendcounts[], const MPI_Aint sdispls[],
                    MPI_Datatype sendtype, void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                    MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                    MPIR_Errflag_t errflag);
int MPIR_Alltoallv_allcomm_nb(const void *sendbuf, const MPI_Aint sendcounts[],
                              const MPI_Aint sdispls[], MPI_Datatype sendtype,
                              void *recvbuf, const MPI_Aint recvcounts[],
                              const MPI_Aint rdispls[], MPI_Datatype recvtype,
                              MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);;
int MPIR_Alltoallv_impl(const void *sendbuf, const MPI_Aint sendcounts[],
                        const MPI_Aint sdispls[], MPI_Datatype sendtype,
                        void *recvbuf, const MPI_Aint recvcounts[],
                        const MPI_Aint rdispls[], MPI_Datatype recvtype,
                        MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Alltoallv(const void *sendbuf, const MPI_Aint sendcounts[],
                   const MPI_Aint sdispls[], MPI_Datatype sendtype,
                   void *recvbuf, const MPI_Aint recvcounts[],
                   const MPI_Aint rdispls[], MPI_Datatype recvtype,
                   MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Ialltoallv_allcomm_sched_auto(const void *sendbuf,
                                       const MPI_Aint sendcounts[],
                                       const MPI_Aint sdispls[],
                                       MPI_Datatype sendtype, void *recvbuf,
                                       const MPI_Aint recvcounts[],
                                       const MPI_Aint rdispls[],
                                       MPI_Datatype recvtype,
                                       MPIR_Comm * comm_ptr, bool is_persistent,
                                       void **sched_p,
                                       enum MPIR_sched_type *sched_type_p);
int MPIR_Ialltoallv_intra_sched_auto(const void *sendbuf,
                                     const MPI_Aint sendcounts[],
                                     const MPI_Aint sdispls[],
                                     MPI_Datatype sendtype, void *recvbuf,
                                     const MPI_Aint recvcounts[],
                                     const MPI_Aint rdispls[],
                                     MPI_Datatype recvtype,
                                     MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Ialltoallv_inter_sched_auto(const void *sendbuf,
                                     const MPI_Aint sendcounts[],
                                     const MPI_Aint sdispls[],
                                     MPI_Datatype sendtype, void *recvbuf,
                                     const MPI_Aint recvcounts[],
                                     const MPI_Aint rdispls[],
                                     MPI_Datatype recvtype,
                                     MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Ialltoallv_intra_sched_blocked(const void *sendbuf,
                                        const MPI_Aint sendcounts[],
                                        const MPI_Aint sdispls[],
                                        MPI_Datatype sendtype, void *recvbuf,
                                        const MPI_Aint recvcounts[],
                                        const MPI_Aint rdispls[],
                                        MPI_Datatype recvtype,
                                        MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Ialltoallv_intra_sched_inplace(const void *sendbuf,
                                        const MPI_Aint sendcounts[],
                                        const MPI_Aint sdispls[],
                                        MPI_Datatype sendtype, void *recvbuf,
                                        const MPI_Aint recvcounts[],
                                        const MPI_Aint rdispls[],
                                        MPI_Datatype recvtype,
                                        MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_TSP_Ialltoallv_sched_intra_scattered(const void *sendbuf,
                    const MPI_Aint sendcounts[], const MPI_Aint sdispls[],
                    MPI_Datatype sendtype, void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                    MPI_Datatype recvtype, MPIR_Comm * comm_ptr, int batch_size,
                    int bblock, MPIR_TSP_sched_t sched);
int MPIR_TSP_Ialltoallv_sched_intra_blocked(const void *sendbuf,
                    const MPI_Aint sendcounts[], const MPI_Aint sdispls[],
                    MPI_Datatype sendtype, void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                    MPI_Datatype recvtype, MPIR_Comm * comm_ptr, int bblock,
                    MPIR_TSP_sched_t sched);
int MPIR_TSP_Ialltoallv_sched_intra_inplace(const void *sendbuf,
                    const MPI_Aint sendcounts[], const MPI_Aint sdispls[],
                    MPI_Datatype sendtype, void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                    MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                    MPIR_TSP_sched_t sched);
int MPIR_Ialltoallv_inter_sched_pairwise_exchange(const void *sendbuf,
                    const MPI_Aint sendcounts[], const MPI_Aint sdispls[],
                    MPI_Datatype sendtype, void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                    MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                    MPIR_Sched_t s);
int MPIR_Ialltoallv_sched_impl(const void *sendbuf, const MPI_Aint sendcounts[],
                               const MPI_Aint sdispls[], MPI_Datatype sendtype,
                               void *recvbuf, const MPI_Aint recvcounts[],
                               const MPI_Aint rdispls[], MPI_Datatype recvtype,
                               MPIR_Comm * comm_ptr, bool is_persistent,
                               void **sched_p,
                               enum MPIR_sched_type *sched_type_p);
int MPIR_Ialltoallv_impl(const void *sendbuf, const MPI_Aint sendcounts[],
                         const MPI_Aint sdispls[], MPI_Datatype sendtype,
                         void *recvbuf, const MPI_Aint recvcounts[],
                         const MPI_Aint rdispls[], MPI_Datatype recvtype,
                         MPIR_Comm * comm_ptr, MPIR_Request ** request);
int MPIR_Ialltoallv(const void *sendbuf, const MPI_Aint sendcounts[],
                    const MPI_Aint sdispls[], MPI_Datatype sendtype,
                    void *recvbuf, const MPI_Aint recvcounts[],
                    const MPI_Aint rdispls[], MPI_Datatype recvtype,
                    MPIR_Comm * comm_ptr, MPIR_Request ** request);
int MPIR_Alltoallv_init_impl(const void *sendbuf, const MPI_Aint sendcounts[],
                             const MPI_Aint sdispls[], MPI_Datatype sendtype,
                             void *recvbuf, const MPI_Aint recvcounts[],
                             const MPI_Aint rdispls[], MPI_Datatype recvtype,
                             MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                             MPIR_Request ** request);
int MPIR_Alltoallv_init(const void *sendbuf, const MPI_Aint sendcounts[],
                        const MPI_Aint sdispls[], MPI_Datatype sendtype,
                        void *recvbuf, const MPI_Aint recvcounts[],
                        const MPI_Aint rdispls[], MPI_Datatype recvtype,
                        MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                        MPIR_Request ** request);
int MPIR_Alltoallw_allcomm_auto(const void *sendbuf,
                                const MPI_Aint sendcounts[],
                                const MPI_Aint sdispls[],
                                const MPI_Datatype sendtypes[], void *recvbuf,
                                const MPI_Aint recvcounts[],
                                const MPI_Aint rdispls[],
                                const MPI_Datatype recvtypes[],
                                MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Alltoallw_intra_pairwise_sendrecv_replace(const void *sendbuf,
                    const MPI_Aint sendcounts[], const MPI_Aint sdispls[],
                    const MPI_Datatype sendtypes[], void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                    const MPI_Datatype recvtypes[], MPIR_Comm * comm_ptr,
                    MPIR_Errflag_t errflag);
int MPIR_Alltoallw_intra_scattered(const void *sendbuf,
                                   const MPI_Aint sendcounts[],
                                   const MPI_Aint sdispls[],
                                   const MPI_Datatype sendtypes[],
                                   void *recvbuf, const MPI_Aint recvcounts[],
                                   const MPI_Aint rdispls[],
                                   const MPI_Datatype recvtypes[],
                                   MPIR_Comm * comm_ptr,
                                   MPIR_Errflag_t errflag);
int MPIR_Alltoallw_inter_pairwise_exchange(const void *sendbuf,
                    const MPI_Aint sendcounts[], const MPI_Aint sdispls[],
                    const MPI_Datatype sendtypes[], void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                    const MPI_Datatype recvtypes[], MPIR_Comm * comm_ptr,
                    MPIR_Errflag_t errflag);
int MPIR_Alltoallw_allcomm_nb(const void *sendbuf, const MPI_Aint sendcounts[],
                              const MPI_Aint sdispls[],
                              const MPI_Datatype sendtypes[], void *recvbuf,
                              const MPI_Aint recvcounts[],
                              const MPI_Aint rdispls[],
                              const MPI_Datatype recvtypes[],
                              MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);;
int MPIR_Alltoallw_impl(const void *sendbuf, const MPI_Aint sendcounts[],
                        const MPI_Aint sdispls[],
                        const MPI_Datatype sendtypes[], void *recvbuf,
                        const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                        const MPI_Datatype recvtypes[], MPIR_Comm * comm_ptr,
                        MPIR_Errflag_t errflag);
int MPIR_Alltoallw(const void *sendbuf, const MPI_Aint sendcounts[],
                   const MPI_Aint sdispls[], const MPI_Datatype sendtypes[],
                   void *recvbuf, const MPI_Aint recvcounts[],
                   const MPI_Aint rdispls[], const MPI_Datatype recvtypes[],
                   MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Ialltoallw_allcomm_sched_auto(const void *sendbuf,
                                       const MPI_Aint sendcounts[],
                                       const MPI_Aint sdispls[],
                                       const MPI_Datatype sendtypes[],
                                       void *recvbuf,
                                       const MPI_Aint recvcounts[],
                                       const MPI_Aint rdispls[],
                                       const MPI_Datatype recvtypes[],
                                       MPIR_Comm * comm_ptr, bool is_persistent,
                                       void **sched_p,
                                       enum MPIR_sched_type *sched_type_p);
int MPIR_Ialltoallw_intra_sched_auto(const void *sendbuf,
                                     const MPI_Aint sendcounts[],
                                     const MPI_Aint sdispls[],
                                     const MPI_Datatype sendtypes[],
                                     void *recvbuf, const MPI_Aint recvcounts[],
                                     const MPI_Aint rdispls[],
                                     const MPI_Datatype recvtypes[],
                                     MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Ialltoallw_inter_sched_auto(const void *sendbuf,
                                     const MPI_Aint sendcounts[],
                                     const MPI_Aint sdispls[],
                                     const MPI_Datatype sendtypes[],
                                     void *recvbuf, const MPI_Aint recvcounts[],
                                     const MPI_Aint rdispls[],
                                     const MPI_Datatype recvtypes[],
                                     MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Ialltoallw_intra_sched_blocked(const void *sendbuf,
                                        const MPI_Aint sendcounts[],
                                        const MPI_Aint sdispls[],
                                        const MPI_Datatype sendtypes[],
                                        void *recvbuf,
                                        const MPI_Aint recvcounts[],
                                        const MPI_Aint rdispls[],
                                        const MPI_Datatype recvtypes[],
                                        MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Ialltoallw_intra_sched_inplace(const void *sendbuf,
                                        const MPI_Aint sendcounts[],
                                        const MPI_Aint sdispls[],
                                        const MPI_Datatype sendtypes[],
                                        void *recvbuf,
                                        const MPI_Aint recvcounts[],
                                        const MPI_Aint rdispls[],
                                        const MPI_Datatype recvtypes[],
                                        MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_TSP_Ialltoallw_sched_intra_blocked(const void *sendbuf,
                    const MPI_Aint sendcounts[], const MPI_Aint sdispls[],
                    const MPI_Datatype sendtypes[], void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                    const MPI_Datatype recvtypes[], MPIR_Comm * comm_ptr,
                    int bblock, MPIR_TSP_sched_t sched);
int MPIR_TSP_Ialltoallw_sched_intra_inplace(const void *sendbuf,
                    const MPI_Aint sendcounts[], const MPI_Aint sdispls[],
                    const MPI_Datatype sendtypes[], void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                    const MPI_Datatype recvtypes[], MPIR_Comm * comm_ptr,
                    MPIR_TSP_sched_t sched);
int MPIR_Ialltoallw_inter_sched_pairwise_exchange(const void *sendbuf,
                    const MPI_Aint sendcounts[], const MPI_Aint sdispls[],
                    const MPI_Datatype sendtypes[], void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                    const MPI_Datatype recvtypes[], MPIR_Comm * comm_ptr,
                    MPIR_Sched_t s);
int MPIR_Ialltoallw_sched_impl(const void *sendbuf, const MPI_Aint sendcounts[],
                               const MPI_Aint sdispls[],
                               const MPI_Datatype sendtypes[], void *recvbuf,
                               const MPI_Aint recvcounts[],
                               const MPI_Aint rdispls[],
                               const MPI_Datatype recvtypes[],
                               MPIR_Comm * comm_ptr, bool is_persistent,
                               void **sched_p,
                               enum MPIR_sched_type *sched_type_p);
int MPIR_Ialltoallw_impl(const void *sendbuf, const MPI_Aint sendcounts[],
                         const MPI_Aint sdispls[],
                         const MPI_Datatype sendtypes[], void *recvbuf,
                         const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                         const MPI_Datatype recvtypes[], MPIR_Comm * comm_ptr,
                         MPIR_Request ** request);
int MPIR_Ialltoallw(const void *sendbuf, const MPI_Aint sendcounts[],
                    const MPI_Aint sdispls[], const MPI_Datatype sendtypes[],
                    void *recvbuf, const MPI_Aint recvcounts[],
                    const MPI_Aint rdispls[], const MPI_Datatype recvtypes[],
                    MPIR_Comm * comm_ptr, MPIR_Request ** request);
int MPIR_Alltoallw_init_impl(const void *sendbuf, const MPI_Aint sendcounts[],
                             const MPI_Aint sdispls[],
                             const MPI_Datatype sendtypes[], void *recvbuf,
                             const MPI_Aint recvcounts[],
                             const MPI_Aint rdispls[],
                             const MPI_Datatype recvtypes[],
                             MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                             MPIR_Request ** request);
int MPIR_Alltoallw_init(const void *sendbuf, const MPI_Aint sendcounts[],
                        const MPI_Aint sdispls[],
                        const MPI_Datatype sendtypes[], void *recvbuf,
                        const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                        const MPI_Datatype recvtypes[], MPIR_Comm * comm_ptr,
                        MPIR_Info * info_ptr, MPIR_Request ** request);
int MPIR_Reduce_allcomm_auto(const void *sendbuf, void *recvbuf, MPI_Aint count,
                             MPI_Datatype datatype, MPI_Op op, int root,
                             MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Reduce_intra_binomial(const void *sendbuf, void *recvbuf,
                               MPI_Aint count, MPI_Datatype datatype, MPI_Op op,
                               int root, MPIR_Comm * comm_ptr,
                               MPIR_Errflag_t errflag);
int MPIR_Reduce_intra_smp(const void *sendbuf, void *recvbuf, MPI_Aint count,
                          MPI_Datatype datatype, MPI_Op op, int root,
                          MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Reduce_intra_reduce_scatter_gather(const void *sendbuf, void *recvbuf,
                    MPI_Aint count, MPI_Datatype datatype, MPI_Op op, int root,
                    MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Reduce_intra_osu_knomial(const void *sendbuf, void *recvbuf,
                                  MPI_Aint count, MPI_Datatype datatype,
                                  MPI_Op op, int root, MPIR_Comm * comm_ptr,
                                  int inter_kf, int intra_kf,
                                  MPIR_Errflag_t errflag);
int MPIR_Reduce_intra_osu_allreduce(const void *sendbuf, void *recvbuf,
                                    MPI_Aint count, MPI_Datatype datatype,
                                    MPI_Op op, int root, MPIR_Comm * comm_ptr,
                                    MPIR_Errflag_t errflag);
int MPIR_Reduce_inter_local_reduce_remote_send(const void *sendbuf,
                    void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                    MPI_Op op, int root, MPIR_Comm * comm_ptr,
                    MPIR_Errflag_t errflag);
int MPIR_Reduce_allcomm_nb(const void *sendbuf, void *recvbuf, MPI_Aint count,
                           MPI_Datatype datatype, MPI_Op op, int root,
                           MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);;
int MPIR_Reduce_impl(const void *sendbuf, void *recvbuf, MPI_Aint count,
                     MPI_Datatype datatype, MPI_Op op, int root,
                     MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Reduce(const void *sendbuf, void *recvbuf, MPI_Aint count,
                MPI_Datatype datatype, MPI_Op op, int root,
                MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Ireduce_allcomm_sched_auto(const void *sendbuf, void *recvbuf,
                                    MPI_Aint count, MPI_Datatype datatype,
                                    MPI_Op op, int root, MPIR_Comm * comm_ptr,
                                    bool is_persistent, void **sched_p,
                                    enum MPIR_sched_type *sched_type_p);
int MPIR_Ireduce_intra_sched_auto(const void *sendbuf, void *recvbuf,
                                  MPI_Aint count, MPI_Datatype datatype,
                                  MPI_Op op, int root, MPIR_Comm * comm_ptr,
                                  MPIR_Sched_t s);
int MPIR_Ireduce_inter_sched_auto(const void *sendbuf, void *recvbuf,
                                  MPI_Aint count, MPI_Datatype datatype,
                                  MPI_Op op, int root, MPIR_Comm * comm_ptr,
                                  MPIR_Sched_t s);
int MPIR_Ireduce_intra_sched_smp(const void *sendbuf, void *recvbuf,
                                 MPI_Aint count, MPI_Datatype datatype,
                                 MPI_Op op, int root, MPIR_Comm * comm_ptr,
                                 MPIR_Sched_t s);
int MPIR_Ireduce_intra_sched_binomial(const void *sendbuf, void *recvbuf,
                                      MPI_Aint count, MPI_Datatype datatype,
                                      MPI_Op op, int root, MPIR_Comm * comm_ptr,
                                      MPIR_Sched_t s);
int MPIR_Ireduce_intra_sched_reduce_scatter_gather(const void *sendbuf,
                    void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                    MPI_Op op, int root, MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_TSP_Ireduce_sched_intra_tree(const void *sendbuf, void *recvbuf,
                                      MPI_Aint count, MPI_Datatype datatype,
                                      MPI_Op op, int root, MPIR_Comm * comm_ptr,
                                      int tree_type, int k, int chunk_size,
                                      int buffer_per_child,
                                      MPIR_TSP_sched_t sched);
int MPIR_Ireduce_inter_sched_local_reduce_remote_send(const void *sendbuf,
                    void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                    MPI_Op op, int root, MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Ireduce_sched_impl(const void *sendbuf, void *recvbuf, MPI_Aint count,
                            MPI_Datatype datatype, MPI_Op op, int root,
                            MPIR_Comm * comm_ptr, bool is_persistent,
                            void **sched_p,
                            enum MPIR_sched_type *sched_type_p);
int MPIR_Ireduce_impl(const void *sendbuf, void *recvbuf, MPI_Aint count,
                      MPI_Datatype datatype, MPI_Op op, int root,
                      MPIR_Comm * comm_ptr, MPIR_Request ** request);
int MPIR_Ireduce(const void *sendbuf, void *recvbuf, MPI_Aint count,
                 MPI_Datatype datatype, MPI_Op op, int root,
                 MPIR_Comm * comm_ptr, MPIR_Request ** request);
int MPIR_Reduce_init_impl(const void *sendbuf, void *recvbuf, MPI_Aint count,
                          MPI_Datatype datatype, MPI_Op op, int root,
                          MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                          MPIR_Request ** request);
int MPIR_Reduce_init(const void *sendbuf, void *recvbuf, MPI_Aint count,
                     MPI_Datatype datatype, MPI_Op op, int root,
                     MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                     MPIR_Request ** request);
int MPIR_Allreduce_allcomm_auto(const void *sendbuf, void *recvbuf,
                                MPI_Aint count, MPI_Datatype datatype,
                                MPI_Op op, MPIR_Comm * comm_ptr,
                                MPIR_Errflag_t errflag);
int MPIR_Allreduce_intra_smp(const void *sendbuf, void *recvbuf, MPI_Aint count,
                             MPI_Datatype datatype, MPI_Op op,
                             MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Allreduce_intra_recursive_doubling(const void *sendbuf, void *recvbuf,
                    MPI_Aint count, MPI_Datatype datatype, MPI_Op op,
                    MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Allreduce_intra_recursive_multiplying(const void *sendbuf,
                    void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                    MPI_Op op, MPIR_Comm * comm_ptr, int k,
                    MPIR_Errflag_t errflag);
int MPIR_Allreduce_intra_reduce_scatter_allgather(const void *sendbuf,
                    void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                    MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Allreduce_intra_tree(const void *sendbuf, void *recvbuf,
                              MPI_Aint count, MPI_Datatype datatype, MPI_Op op,
                              MPIR_Comm * comm_ptr, int tree_type, int k,
                              int chunk_size, int buffer_per_child,
                              MPIR_Errflag_t errflag);
int MPIR_Allreduce_intra_recexch(const void *sendbuf, void *recvbuf,
                                 MPI_Aint count, MPI_Datatype datatype,
                                 MPI_Op op, MPIR_Comm * comm_ptr, int k,
                                 int single_phase_recv,
                                 MPIR_Errflag_t errflag);
int MPIR_Allreduce_intra_ring(const void *sendbuf, void *recvbuf,
                              MPI_Aint count, MPI_Datatype datatype, MPI_Op op,
                              MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Allreduce_intra_k_reduce_scatter_allgather(const void *sendbuf,
                    void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                    MPI_Op op, MPIR_Comm * comm_ptr, int k,
                    int single_phase_recv, MPIR_Errflag_t errflag);
int MPIR_Allreduce_inter_reduce_exchange_bcast(const void *sendbuf,
                    void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                    MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Allreduce_allcomm_nb(const void *sendbuf, void *recvbuf,
                              MPI_Aint count, MPI_Datatype datatype, MPI_Op op,
                              MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);;
int MPIR_Allreduce_impl(const void *sendbuf, void *recvbuf, MPI_Aint count,
                        MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                        MPIR_Errflag_t errflag);
int MPIR_Allreduce(const void *sendbuf, void *recvbuf, MPI_Aint count,
                   MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                   MPIR_Errflag_t errflag);
int MPIR_Iallreduce_allcomm_sched_auto(const void *sendbuf, void *recvbuf,
                                       MPI_Aint count, MPI_Datatype datatype,
                                       MPI_Op op, MPIR_Comm * comm_ptr,
                                       bool is_persistent, void **sched_p,
                                       enum MPIR_sched_type *sched_type_p);
int MPIR_Iallreduce_intra_sched_auto(const void *sendbuf, void *recvbuf,
                                     MPI_Aint count, MPI_Datatype datatype,
                                     MPI_Op op, MPIR_Comm * comm_ptr,
                                     MPIR_Sched_t s);
int MPIR_Iallreduce_inter_sched_auto(const void *sendbuf, void *recvbuf,
                                     MPI_Aint count, MPI_Datatype datatype,
                                     MPI_Op op, MPIR_Comm * comm_ptr,
                                     MPIR_Sched_t s);
int MPIR_Iallreduce_intra_sched_naive(const void *sendbuf, void *recvbuf,
                                      MPI_Aint count, MPI_Datatype datatype,
                                      MPI_Op op, MPIR_Comm * comm_ptr,
                                      MPIR_Sched_t s);
int MPIR_Iallreduce_intra_sched_smp(const void *sendbuf, void *recvbuf,
                                    MPI_Aint count, MPI_Datatype datatype,
                                    MPI_Op op, MPIR_Comm * comm_ptr,
                                    MPIR_Sched_t s);
int MPIR_Iallreduce_intra_sched_recursive_doubling(const void *sendbuf,
                    void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                    MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Iallreduce_intra_sched_reduce_scatter_allgather(const void *sendbuf,
                    void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                    MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_TSP_Iallreduce_sched_intra_recexch(const void *sendbuf, void *recvbuf,
                    MPI_Aint count, MPI_Datatype datatype, MPI_Op op,
                    MPIR_Comm * comm_ptr, int recexch_type, int k,
                    MPIR_TSP_sched_t sched);
int MPIR_TSP_Iallreduce_sched_intra_tree(const void *sendbuf, void *recvbuf,
                    MPI_Aint count, MPI_Datatype datatype, MPI_Op op,
                    MPIR_Comm * comm_ptr, int tree_type, int k, int chunk_size,
                    int buffer_per_child, MPIR_TSP_sched_t sched);
int MPIR_TSP_Iallreduce_sched_intra_ring(const void *sendbuf, void *recvbuf,
                    MPI_Aint count, MPI_Datatype datatype, MPI_Op op,
                    MPIR_Comm * comm_ptr, MPIR_TSP_sched_t sched);
int MPIR_TSP_Iallreduce_sched_intra_recexch_reduce_scatter_recexch_allgatherv(const void *sendbuf,
                    void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                    MPI_Op op, MPIR_Comm * comm_ptr, int k,
                    MPIR_TSP_sched_t sched);
int MPIR_Iallreduce_inter_sched_remote_reduce_local_bcast(const void *sendbuf,
                    void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                    MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Iallreduce_sched_impl(const void *sendbuf, void *recvbuf,
                               MPI_Aint count, MPI_Datatype datatype, MPI_Op op,
                               MPIR_Comm * comm_ptr, bool is_persistent,
                               void **sched_p,
                               enum MPIR_sched_type *sched_type_p);
int MPIR_Iallreduce_impl(const void *sendbuf, void *recvbuf, MPI_Aint count,
                         MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                         MPIR_Request ** request);
int MPIR_Iallreduce(const void *sendbuf, void *recvbuf, MPI_Aint count,
                    MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                    MPIR_Request ** request);
int MPIR_Allreduce_init_impl(const void *sendbuf, void *recvbuf, MPI_Aint count,
                             MPI_Datatype datatype, MPI_Op op,
                             MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                             MPIR_Request ** request);
int MPIR_Allreduce_init(const void *sendbuf, void *recvbuf, MPI_Aint count,
                        MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                        MPIR_Info * info_ptr, MPIR_Request ** request);
int MPIR_Reduce_scatter_allcomm_auto(const void *sendbuf, void *recvbuf,
                                     const MPI_Aint recvcounts[],
                                     MPI_Datatype datatype, MPI_Op op,
                                     MPIR_Comm * comm_ptr,
                                     MPIR_Errflag_t errflag);
int MPIR_Reduce_scatter_intra_noncommutative(const void *sendbuf, void *recvbuf,
                    const MPI_Aint recvcounts[], MPI_Datatype datatype,
                    MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Reduce_scatter_intra_pairwise(const void *sendbuf, void *recvbuf,
                                       const MPI_Aint recvcounts[],
                                       MPI_Datatype datatype, MPI_Op op,
                                       MPIR_Comm * comm_ptr,
                                       MPIR_Errflag_t errflag);
int MPIR_Reduce_scatter_intra_recursive_doubling(const void *sendbuf,
                    void *recvbuf, const MPI_Aint recvcounts[],
                    MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                    MPIR_Errflag_t errflag);
int MPIR_Reduce_scatter_intra_recursive_halving(const void *sendbuf,
                    void *recvbuf, const MPI_Aint recvcounts[],
                    MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                    MPIR_Errflag_t errflag);
int MPIR_Reduce_scatter_intra_osu_basic(const void *sendbuf, void *recvbuf,
                                        const MPI_Aint recvcounts[],
                                        MPI_Datatype datatype, MPI_Op op,
                                        MPIR_Comm * comm_ptr,
                                        MPIR_Errflag_t errflag);
int MPIR_Reduce_scatter_intra_osu_ring(const void *sendbuf, void *recvbuf,
                                       const MPI_Aint recvcounts[],
                                       MPI_Datatype datatype, MPI_Op op,
                                       MPIR_Comm * comm_ptr,
                                       MPIR_Errflag_t errflag);
int MPIR_Reduce_scatter_inter_remote_reduce_local_scatter(const void *sendbuf,
                    void *recvbuf, const MPI_Aint recvcounts[],
                    MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                    MPIR_Errflag_t errflag);
int MPIR_Reduce_scatter_allcomm_nb(const void *sendbuf, void *recvbuf,
                                   const MPI_Aint recvcounts[],
                                   MPI_Datatype datatype, MPI_Op op,
                                   MPIR_Comm * comm_ptr,
                                   MPIR_Errflag_t errflag);;
int MPIR_Reduce_scatter_impl(const void *sendbuf, void *recvbuf,
                             const MPI_Aint recvcounts[], MPI_Datatype datatype,
                             MPI_Op op, MPIR_Comm * comm_ptr,
                             MPIR_Errflag_t errflag);
int MPIR_Reduce_scatter(const void *sendbuf, void *recvbuf,
                        const MPI_Aint recvcounts[], MPI_Datatype datatype,
                        MPI_Op op, MPIR_Comm * comm_ptr,
                        MPIR_Errflag_t errflag);
int MPIR_Ireduce_scatter_allcomm_sched_auto(const void *sendbuf, void *recvbuf,
                    const MPI_Aint recvcounts[], MPI_Datatype datatype,
                    MPI_Op op, MPIR_Comm * comm_ptr, bool is_persistent,
                    void **sched_p, enum MPIR_sched_type *sched_type_p);
int MPIR_Ireduce_scatter_intra_sched_auto(const void *sendbuf, void *recvbuf,
                    const MPI_Aint recvcounts[], MPI_Datatype datatype,
                    MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Ireduce_scatter_inter_sched_auto(const void *sendbuf, void *recvbuf,
                    const MPI_Aint recvcounts[], MPI_Datatype datatype,
                    MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Ireduce_scatter_intra_sched_noncommutative(const void *sendbuf,
                    void *recvbuf, const MPI_Aint recvcounts[],
                    MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                    MPIR_Sched_t s);
int MPIR_Ireduce_scatter_intra_sched_recursive_doubling(const void *sendbuf,
                    void *recvbuf, const MPI_Aint recvcounts[],
                    MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                    MPIR_Sched_t s);
int MPIR_Ireduce_scatter_intra_sched_pairwise(const void *sendbuf,
                    void *recvbuf, const MPI_Aint recvcounts[],
                    MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                    MPIR_Sched_t s);
int MPIR_Ireduce_scatter_intra_sched_recursive_halving(const void *sendbuf,
                    void *recvbuf, const MPI_Aint recvcounts[],
                    MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                    MPIR_Sched_t s);
int MPIR_TSP_Ireduce_scatter_sched_intra_recexch(const void *sendbuf,
                    void *recvbuf, const MPI_Aint recvcounts[],
                    MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                    int recexch_type, int k, MPIR_TSP_sched_t sched);
int MPIR_Ireduce_scatter_inter_sched_remote_reduce_local_scatterv(const void *sendbuf,
                    void *recvbuf, const MPI_Aint recvcounts[],
                    MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                    MPIR_Sched_t s);
int MPIR_Ireduce_scatter_sched_impl(const void *sendbuf, void *recvbuf,
                                    const MPI_Aint recvcounts[],
                                    MPI_Datatype datatype, MPI_Op op,
                                    MPIR_Comm * comm_ptr, bool is_persistent,
                                    void **sched_p,
                                    enum MPIR_sched_type *sched_type_p);
int MPIR_Ireduce_scatter_impl(const void *sendbuf, void *recvbuf,
                              const MPI_Aint recvcounts[],
                              MPI_Datatype datatype, MPI_Op op,
                              MPIR_Comm * comm_ptr, MPIR_Request ** request);
int MPIR_Ireduce_scatter(const void *sendbuf, void *recvbuf,
                         const MPI_Aint recvcounts[], MPI_Datatype datatype,
                         MPI_Op op, MPIR_Comm * comm_ptr,
                         MPIR_Request ** request);
int MPIR_Reduce_scatter_init_impl(const void *sendbuf, void *recvbuf,
                                  const MPI_Aint recvcounts[],
                                  MPI_Datatype datatype, MPI_Op op,
                                  MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                                  MPIR_Request ** request);
int MPIR_Reduce_scatter_init(const void *sendbuf, void *recvbuf,
                             const MPI_Aint recvcounts[], MPI_Datatype datatype,
                             MPI_Op op, MPIR_Comm * comm_ptr,
                             MPIR_Info * info_ptr, MPIR_Request ** request);
int MPIR_Reduce_scatter_block_allcomm_auto(const void *sendbuf, void *recvbuf,
                    MPI_Aint recvcount, MPI_Datatype datatype, MPI_Op op,
                    MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Reduce_scatter_block_intra_noncommutative(const void *sendbuf,
                    void *recvbuf, MPI_Aint recvcount, MPI_Datatype datatype,
                    MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Reduce_scatter_block_intra_recursive_doubling(const void *sendbuf,
                    void *recvbuf, MPI_Aint recvcount, MPI_Datatype datatype,
                    MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Reduce_scatter_block_intra_pairwise(const void *sendbuf, void *recvbuf,
                    MPI_Aint recvcount, MPI_Datatype datatype, MPI_Op op,
                    MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Reduce_scatter_block_intra_recursive_halving(const void *sendbuf,
                    void *recvbuf, MPI_Aint recvcount, MPI_Datatype datatype,
                    MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Reduce_scatter_block_inter_remote_reduce_local_scatter(const void *sendbuf,
                    void *recvbuf, MPI_Aint recvcount, MPI_Datatype datatype,
                    MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Reduce_scatter_block_allcomm_nb(const void *sendbuf, void *recvbuf,
                    MPI_Aint recvcount, MPI_Datatype datatype, MPI_Op op,
                    MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);;
int MPIR_Reduce_scatter_block_impl(const void *sendbuf, void *recvbuf,
                                   MPI_Aint recvcount, MPI_Datatype datatype,
                                   MPI_Op op, MPIR_Comm * comm_ptr,
                                   MPIR_Errflag_t errflag);
int MPIR_Reduce_scatter_block(const void *sendbuf, void *recvbuf,
                              MPI_Aint recvcount, MPI_Datatype datatype,
                              MPI_Op op, MPIR_Comm * comm_ptr,
                              MPIR_Errflag_t errflag);
int MPIR_Ireduce_scatter_block_allcomm_sched_auto(const void *sendbuf,
                    void *recvbuf, MPI_Aint recvcount, MPI_Datatype datatype,
                    MPI_Op op, MPIR_Comm * comm_ptr, bool is_persistent,
                    void **sched_p, enum MPIR_sched_type *sched_type_p);
int MPIR_Ireduce_scatter_block_intra_sched_auto(const void *sendbuf,
                    void *recvbuf, MPI_Aint recvcount, MPI_Datatype datatype,
                    MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Ireduce_scatter_block_inter_sched_auto(const void *sendbuf,
                    void *recvbuf, MPI_Aint recvcount, MPI_Datatype datatype,
                    MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Ireduce_scatter_block_intra_sched_noncommutative(const void *sendbuf,
                    void *recvbuf, MPI_Aint recvcount, MPI_Datatype datatype,
                    MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Ireduce_scatter_block_intra_sched_recursive_doubling(const void *sendbuf,
                    void *recvbuf, MPI_Aint recvcount, MPI_Datatype datatype,
                    MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Ireduce_scatter_block_intra_sched_pairwise(const void *sendbuf,
                    void *recvbuf, MPI_Aint recvcount, MPI_Datatype datatype,
                    MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Ireduce_scatter_block_intra_sched_recursive_halving(const void *sendbuf,
                    void *recvbuf, MPI_Aint recvcount, MPI_Datatype datatype,
                    MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_TSP_Ireduce_scatter_block_sched_intra_recexch(const void *sendbuf,
                    void *recvbuf, MPI_Aint recvcount, MPI_Datatype datatype,
                    MPI_Op op, MPIR_Comm * comm_ptr, int k,
                    MPIR_TSP_sched_t sched);
int MPIR_Ireduce_scatter_block_inter_sched_remote_reduce_local_scatterv(const void *sendbuf,
                    void *recvbuf, MPI_Aint recvcount, MPI_Datatype datatype,
                    MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Ireduce_scatter_block_sched_impl(const void *sendbuf, void *recvbuf,
                    MPI_Aint recvcount, MPI_Datatype datatype, MPI_Op op,
                    MPIR_Comm * comm_ptr, bool is_persistent, void **sched_p,
                    enum MPIR_sched_type *sched_type_p);
int MPIR_Ireduce_scatter_block_impl(const void *sendbuf, void *recvbuf,
                                    MPI_Aint recvcount, MPI_Datatype datatype,
                                    MPI_Op op, MPIR_Comm * comm_ptr,
                                    MPIR_Request ** request);
int MPIR_Ireduce_scatter_block(const void *sendbuf, void *recvbuf,
                               MPI_Aint recvcount, MPI_Datatype datatype,
                               MPI_Op op, MPIR_Comm * comm_ptr,
                               MPIR_Request ** request);
int MPIR_Reduce_scatter_block_init_impl(const void *sendbuf, void *recvbuf,
                                        MPI_Aint recvcount,
                                        MPI_Datatype datatype, MPI_Op op,
                                        MPIR_Comm * comm_ptr,
                                        MPIR_Info * info_ptr,
                                        MPIR_Request ** request);
int MPIR_Reduce_scatter_block_init(const void *sendbuf, void *recvbuf,
                                   MPI_Aint recvcount, MPI_Datatype datatype,
                                   MPI_Op op, MPIR_Comm * comm_ptr,
                                   MPIR_Info * info_ptr,
                                   MPIR_Request ** request);
int MPIR_Scan_allcomm_auto(const void *sendbuf, void *recvbuf, MPI_Aint count,
                           MPI_Datatype datatype, MPI_Op op,
                           MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Scan_intra_smp(const void *sendbuf, void *recvbuf, MPI_Aint count,
                        MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                        MPIR_Errflag_t errflag);
int MPIR_Scan_intra_recursive_doubling(const void *sendbuf, void *recvbuf,
                                       MPI_Aint count, MPI_Datatype datatype,
                                       MPI_Op op, MPIR_Comm * comm_ptr,
                                       MPIR_Errflag_t errflag);
int MPIR_Scan_allcomm_nb(const void *sendbuf, void *recvbuf, MPI_Aint count,
                         MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                         MPIR_Errflag_t errflag);;
int MPIR_Scan_impl(const void *sendbuf, void *recvbuf, MPI_Aint count,
                   MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                   MPIR_Errflag_t errflag);
int MPIR_Scan(const void *sendbuf, void *recvbuf, MPI_Aint count,
              MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
              MPIR_Errflag_t errflag);
int MPIR_Iscan_allcomm_sched_auto(const void *sendbuf, void *recvbuf,
                                  MPI_Aint count, MPI_Datatype datatype,
                                  MPI_Op op, MPIR_Comm * comm_ptr,
                                  bool is_persistent, void **sched_p,
                                  enum MPIR_sched_type *sched_type_p);
int MPIR_Iscan_intra_sched_auto(const void *sendbuf, void *recvbuf,
                                MPI_Aint count, MPI_Datatype datatype,
                                MPI_Op op, MPIR_Comm * comm_ptr,
                                MPIR_Sched_t s);
int MPIR_Iscan_intra_sched_smp(const void *sendbuf, void *recvbuf,
                               MPI_Aint count, MPI_Datatype datatype, MPI_Op op,
                               MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Iscan_intra_sched_recursive_doubling(const void *sendbuf,
                    void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                    MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_TSP_Iscan_sched_intra_recursive_doubling(const void *sendbuf,
                    void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                    MPI_Op op, MPIR_Comm * comm_ptr, MPIR_TSP_sched_t sched);
int MPIR_Iscan_sched_impl(const void *sendbuf, void *recvbuf, MPI_Aint count,
                          MPI_Datatype datatype, MPI_Op op,
                          MPIR_Comm * comm_ptr, bool is_persistent,
                          void **sched_p, enum MPIR_sched_type *sched_type_p);
int MPIR_Iscan_impl(const void *sendbuf, void *recvbuf, MPI_Aint count,
                    MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                    MPIR_Request ** request);
int MPIR_Iscan(const void *sendbuf, void *recvbuf, MPI_Aint count,
               MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
               MPIR_Request ** request);
int MPIR_Scan_init_impl(const void *sendbuf, void *recvbuf, MPI_Aint count,
                        MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                        MPIR_Info * info_ptr, MPIR_Request ** request);
int MPIR_Scan_init(const void *sendbuf, void *recvbuf, MPI_Aint count,
                   MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                   MPIR_Info * info_ptr, MPIR_Request ** request);
int MPIR_Exscan_allcomm_auto(const void *sendbuf, void *recvbuf, MPI_Aint count,
                             MPI_Datatype datatype, MPI_Op op,
                             MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Exscan_intra_recursive_doubling(const void *sendbuf, void *recvbuf,
                    MPI_Aint count, MPI_Datatype datatype, MPI_Op op,
                    MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);
int MPIR_Exscan_allcomm_nb(const void *sendbuf, void *recvbuf, MPI_Aint count,
                           MPI_Datatype datatype, MPI_Op op,
                           MPIR_Comm * comm_ptr, MPIR_Errflag_t errflag);;
int MPIR_Exscan_impl(const void *sendbuf, void *recvbuf, MPI_Aint count,
                     MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                     MPIR_Errflag_t errflag);
int MPIR_Exscan(const void *sendbuf, void *recvbuf, MPI_Aint count,
                MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                MPIR_Errflag_t errflag);
int MPIR_Iexscan_allcomm_sched_auto(const void *sendbuf, void *recvbuf,
                                    MPI_Aint count, MPI_Datatype datatype,
                                    MPI_Op op, MPIR_Comm * comm_ptr,
                                    bool is_persistent, void **sched_p,
                                    enum MPIR_sched_type *sched_type_p);
int MPIR_Iexscan_intra_sched_auto(const void *sendbuf, void *recvbuf,
                                  MPI_Aint count, MPI_Datatype datatype,
                                  MPI_Op op, MPIR_Comm * comm_ptr,
                                  MPIR_Sched_t s);
int MPIR_Iexscan_intra_sched_recursive_doubling(const void *sendbuf,
                    void *recvbuf, MPI_Aint count, MPI_Datatype datatype,
                    MPI_Op op, MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Iexscan_sched_impl(const void *sendbuf, void *recvbuf, MPI_Aint count,
                            MPI_Datatype datatype, MPI_Op op,
                            MPIR_Comm * comm_ptr, bool is_persistent,
                            void **sched_p,
                            enum MPIR_sched_type *sched_type_p);
int MPIR_Iexscan_impl(const void *sendbuf, void *recvbuf, MPI_Aint count,
                      MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                      MPIR_Request ** request);
int MPIR_Iexscan(const void *sendbuf, void *recvbuf, MPI_Aint count,
                 MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                 MPIR_Request ** request);
int MPIR_Exscan_init_impl(const void *sendbuf, void *recvbuf, MPI_Aint count,
                          MPI_Datatype datatype, MPI_Op op,
                          MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                          MPIR_Request ** request);
int MPIR_Exscan_init(const void *sendbuf, void *recvbuf, MPI_Aint count,
                     MPI_Datatype datatype, MPI_Op op, MPIR_Comm * comm_ptr,
                     MPIR_Info * info_ptr, MPIR_Request ** request);
int MPIR_Neighbor_allgather_allcomm_auto(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    MPI_Aint recvcount, MPI_Datatype recvtype,
                    MPIR_Comm * comm_ptr);
int MPIR_Neighbor_allgather_allcomm_nb(const void *sendbuf, MPI_Aint sendcount,
                                       MPI_Datatype sendtype, void *recvbuf,
                                       MPI_Aint recvcount,
                                       MPI_Datatype recvtype,
                                       MPIR_Comm * comm_ptr);;
int MPIR_Neighbor_allgather_impl(const void *sendbuf, MPI_Aint sendcount,
                                 MPI_Datatype sendtype, void *recvbuf,
                                 MPI_Aint recvcount, MPI_Datatype recvtype,
                                 MPIR_Comm * comm_ptr);
int MPIR_Neighbor_allgather(const void *sendbuf, MPI_Aint sendcount,
                            MPI_Datatype sendtype, void *recvbuf,
                            MPI_Aint recvcount, MPI_Datatype recvtype,
                            MPIR_Comm * comm_ptr);
int MPIR_Ineighbor_allgather_allcomm_sched_auto(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    MPI_Aint recvcount, MPI_Datatype recvtype,
                    MPIR_Comm * comm_ptr, bool is_persistent, void **sched_p,
                    enum MPIR_sched_type *sched_type_p);
int MPIR_Ineighbor_allgather_intra_sched_auto(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    MPI_Aint recvcount, MPI_Datatype recvtype,
                    MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Ineighbor_allgather_allcomm_sched_linear(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    MPI_Aint recvcount, MPI_Datatype recvtype,
                    MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_TSP_Ineighbor_allgather_sched_allcomm_linear(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    MPI_Aint recvcount, MPI_Datatype recvtype,
                    MPIR_Comm * comm_ptr, MPIR_TSP_sched_t sched);
int MPIR_Ineighbor_allgather_sched_impl(const void *sendbuf, MPI_Aint sendcount,
                                        MPI_Datatype sendtype, void *recvbuf,
                                        MPI_Aint recvcount,
                                        MPI_Datatype recvtype,
                                        MPIR_Comm * comm_ptr,
                                        bool is_persistent, void **sched_p,
                                        enum MPIR_sched_type *sched_type_p);
int MPIR_Ineighbor_allgather_impl(const void *sendbuf, MPI_Aint sendcount,
                                  MPI_Datatype sendtype, void *recvbuf,
                                  MPI_Aint recvcount, MPI_Datatype recvtype,
                                  MPIR_Comm * comm_ptr,
                                  MPIR_Request ** request);
int MPIR_Ineighbor_allgather(const void *sendbuf, MPI_Aint sendcount,
                             MPI_Datatype sendtype, void *recvbuf,
                             MPI_Aint recvcount, MPI_Datatype recvtype,
                             MPIR_Comm * comm_ptr, MPIR_Request ** request);
int MPIR_Neighbor_allgather_init_impl(const void *sendbuf, MPI_Aint sendcount,
                                      MPI_Datatype sendtype, void *recvbuf,
                                      MPI_Aint recvcount, MPI_Datatype recvtype,
                                      MPIR_Comm * comm_ptr,
                                      MPIR_Info * info_ptr,
                                      MPIR_Request ** request);
int MPIR_Neighbor_allgather_init(const void *sendbuf, MPI_Aint sendcount,
                                 MPI_Datatype sendtype, void *recvbuf,
                                 MPI_Aint recvcount, MPI_Datatype recvtype,
                                 MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                                 MPIR_Request ** request);
int MPIR_Neighbor_allgatherv_allcomm_auto(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint displs[],
                    MPI_Datatype recvtype, MPIR_Comm * comm_ptr);
int MPIR_Neighbor_allgatherv_allcomm_nb(const void *sendbuf, MPI_Aint sendcount,
                                        MPI_Datatype sendtype, void *recvbuf,
                                        const MPI_Aint recvcounts[],
                                        const MPI_Aint displs[],
                                        MPI_Datatype recvtype,
                                        MPIR_Comm * comm_ptr);;
int MPIR_Neighbor_allgatherv_impl(const void *sendbuf, MPI_Aint sendcount,
                                  MPI_Datatype sendtype, void *recvbuf,
                                  const MPI_Aint recvcounts[],
                                  const MPI_Aint displs[],
                                  MPI_Datatype recvtype, MPIR_Comm * comm_ptr);
int MPIR_Neighbor_allgatherv(const void *sendbuf, MPI_Aint sendcount,
                             MPI_Datatype sendtype, void *recvbuf,
                             const MPI_Aint recvcounts[],
                             const MPI_Aint displs[], MPI_Datatype recvtype,
                             MPIR_Comm * comm_ptr);
int MPIR_Ineighbor_allgatherv_allcomm_sched_auto(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint displs[],
                    MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                    bool is_persistent, void **sched_p,
                    enum MPIR_sched_type *sched_type_p);
int MPIR_Ineighbor_allgatherv_intra_sched_auto(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint displs[],
                    MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                    MPIR_Sched_t s);
int MPIR_Ineighbor_allgatherv_allcomm_sched_linear(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint displs[],
                    MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                    MPIR_Sched_t s);
int MPIR_TSP_Ineighbor_allgatherv_sched_allcomm_linear(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint displs[],
                    MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                    MPIR_TSP_sched_t sched);
int MPIR_Ineighbor_allgatherv_sched_impl(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint displs[],
                    MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                    bool is_persistent, void **sched_p,
                    enum MPIR_sched_type *sched_type_p);
int MPIR_Ineighbor_allgatherv_impl(const void *sendbuf, MPI_Aint sendcount,
                                   MPI_Datatype sendtype, void *recvbuf,
                                   const MPI_Aint recvcounts[],
                                   const MPI_Aint displs[],
                                   MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                                   MPIR_Request ** request);
int MPIR_Ineighbor_allgatherv(const void *sendbuf, MPI_Aint sendcount,
                              MPI_Datatype sendtype, void *recvbuf,
                              const MPI_Aint recvcounts[],
                              const MPI_Aint displs[], MPI_Datatype recvtype,
                              MPIR_Comm * comm_ptr, MPIR_Request ** request);
int MPIR_Neighbor_allgatherv_init_impl(const void *sendbuf, MPI_Aint sendcount,
                                       MPI_Datatype sendtype, void *recvbuf,
                                       const MPI_Aint recvcounts[],
                                       const MPI_Aint displs[],
                                       MPI_Datatype recvtype,
                                       MPIR_Comm * comm_ptr,
                                       MPIR_Info * info_ptr,
                                       MPIR_Request ** request);
int MPIR_Neighbor_allgatherv_init(const void *sendbuf, MPI_Aint sendcount,
                                  MPI_Datatype sendtype, void *recvbuf,
                                  const MPI_Aint recvcounts[],
                                  const MPI_Aint displs[],
                                  MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                                  MPIR_Info * info_ptr,
                                  MPIR_Request ** request);
int MPIR_Neighbor_alltoall_allcomm_auto(const void *sendbuf, MPI_Aint sendcount,
                                        MPI_Datatype sendtype, void *recvbuf,
                                        MPI_Aint recvcount,
                                        MPI_Datatype recvtype,
                                        MPIR_Comm * comm_ptr);
int MPIR_Neighbor_alltoall_allcomm_nb(const void *sendbuf, MPI_Aint sendcount,
                                      MPI_Datatype sendtype, void *recvbuf,
                                      MPI_Aint recvcount, MPI_Datatype recvtype,
                                      MPIR_Comm * comm_ptr);;
int MPIR_Neighbor_alltoall_impl(const void *sendbuf, MPI_Aint sendcount,
                                MPI_Datatype sendtype, void *recvbuf,
                                MPI_Aint recvcount, MPI_Datatype recvtype,
                                MPIR_Comm * comm_ptr);
int MPIR_Neighbor_alltoall(const void *sendbuf, MPI_Aint sendcount,
                           MPI_Datatype sendtype, void *recvbuf,
                           MPI_Aint recvcount, MPI_Datatype recvtype,
                           MPIR_Comm * comm_ptr);
int MPIR_Ineighbor_alltoall_allcomm_sched_auto(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    MPI_Aint recvcount, MPI_Datatype recvtype,
                    MPIR_Comm * comm_ptr, bool is_persistent, void **sched_p,
                    enum MPIR_sched_type *sched_type_p);
int MPIR_Ineighbor_alltoall_intra_sched_auto(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    MPI_Aint recvcount, MPI_Datatype recvtype,
                    MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_Ineighbor_alltoall_allcomm_sched_linear(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    MPI_Aint recvcount, MPI_Datatype recvtype,
                    MPIR_Comm * comm_ptr, MPIR_Sched_t s);
int MPIR_TSP_Ineighbor_alltoall_sched_allcomm_linear(const void *sendbuf,
                    MPI_Aint sendcount, MPI_Datatype sendtype, void *recvbuf,
                    MPI_Aint recvcount, MPI_Datatype recvtype,
                    MPIR_Comm * comm_ptr, MPIR_TSP_sched_t sched);
int MPIR_Ineighbor_alltoall_sched_impl(const void *sendbuf, MPI_Aint sendcount,
                                       MPI_Datatype sendtype, void *recvbuf,
                                       MPI_Aint recvcount,
                                       MPI_Datatype recvtype,
                                       MPIR_Comm * comm_ptr, bool is_persistent,
                                       void **sched_p,
                                       enum MPIR_sched_type *sched_type_p);
int MPIR_Ineighbor_alltoall_impl(const void *sendbuf, MPI_Aint sendcount,
                                 MPI_Datatype sendtype, void *recvbuf,
                                 MPI_Aint recvcount, MPI_Datatype recvtype,
                                 MPIR_Comm * comm_ptr,
                                 MPIR_Request ** request);
int MPIR_Ineighbor_alltoall(const void *sendbuf, MPI_Aint sendcount,
                            MPI_Datatype sendtype, void *recvbuf,
                            MPI_Aint recvcount, MPI_Datatype recvtype,
                            MPIR_Comm * comm_ptr, MPIR_Request ** request);
int MPIR_Neighbor_alltoall_init_impl(const void *sendbuf, MPI_Aint sendcount,
                                     MPI_Datatype sendtype, void *recvbuf,
                                     MPI_Aint recvcount, MPI_Datatype recvtype,
                                     MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                                     MPIR_Request ** request);
int MPIR_Neighbor_alltoall_init(const void *sendbuf, MPI_Aint sendcount,
                                MPI_Datatype sendtype, void *recvbuf,
                                MPI_Aint recvcount, MPI_Datatype recvtype,
                                MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                                MPIR_Request ** request);
int MPIR_Neighbor_alltoallv_allcomm_auto(const void *sendbuf,
                    const MPI_Aint sendcounts[], const MPI_Aint sdispls[],
                    MPI_Datatype sendtype, void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                    MPI_Datatype recvtype, MPIR_Comm * comm_ptr);
int MPIR_Neighbor_alltoallv_allcomm_nb(const void *sendbuf,
                                       const MPI_Aint sendcounts[],
                                       const MPI_Aint sdispls[],
                                       MPI_Datatype sendtype, void *recvbuf,
                                       const MPI_Aint recvcounts[],
                                       const MPI_Aint rdispls[],
                                       MPI_Datatype recvtype,
                                       MPIR_Comm * comm_ptr);;
int MPIR_Neighbor_alltoallv_impl(const void *sendbuf,
                                 const MPI_Aint sendcounts[],
                                 const MPI_Aint sdispls[],
                                 MPI_Datatype sendtype, void *recvbuf,
                                 const MPI_Aint recvcounts[],
                                 const MPI_Aint rdispls[],
                                 MPI_Datatype recvtype, MPIR_Comm * comm_ptr);
int MPIR_Neighbor_alltoallv(const void *sendbuf, const MPI_Aint sendcounts[],
                            const MPI_Aint sdispls[], MPI_Datatype sendtype,
                            void *recvbuf, const MPI_Aint recvcounts[],
                            const MPI_Aint rdispls[], MPI_Datatype recvtype,
                            MPIR_Comm * comm_ptr);
int MPIR_Ineighbor_alltoallv_allcomm_sched_auto(const void *sendbuf,
                    const MPI_Aint sendcounts[], const MPI_Aint sdispls[],
                    MPI_Datatype sendtype, void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                    MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                    bool is_persistent, void **sched_p,
                    enum MPIR_sched_type *sched_type_p);
int MPIR_Ineighbor_alltoallv_intra_sched_auto(const void *sendbuf,
                    const MPI_Aint sendcounts[], const MPI_Aint sdispls[],
                    MPI_Datatype sendtype, void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                    MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                    MPIR_Sched_t s);
int MPIR_Ineighbor_alltoallv_allcomm_sched_linear(const void *sendbuf,
                    const MPI_Aint sendcounts[], const MPI_Aint sdispls[],
                    MPI_Datatype sendtype, void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                    MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                    MPIR_Sched_t s);
int MPIR_TSP_Ineighbor_alltoallv_sched_allcomm_linear(const void *sendbuf,
                    const MPI_Aint sendcounts[], const MPI_Aint sdispls[],
                    MPI_Datatype sendtype, void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                    MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                    MPIR_TSP_sched_t sched);
int MPIR_Ineighbor_alltoallv_sched_impl(const void *sendbuf,
                                        const MPI_Aint sendcounts[],
                                        const MPI_Aint sdispls[],
                                        MPI_Datatype sendtype, void *recvbuf,
                                        const MPI_Aint recvcounts[],
                                        const MPI_Aint rdispls[],
                                        MPI_Datatype recvtype,
                                        MPIR_Comm * comm_ptr,
                                        bool is_persistent, void **sched_p,
                                        enum MPIR_sched_type *sched_type_p);
int MPIR_Ineighbor_alltoallv_impl(const void *sendbuf,
                                  const MPI_Aint sendcounts[],
                                  const MPI_Aint sdispls[],
                                  MPI_Datatype sendtype, void *recvbuf,
                                  const MPI_Aint recvcounts[],
                                  const MPI_Aint rdispls[],
                                  MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                                  MPIR_Request ** request);
int MPIR_Ineighbor_alltoallv(const void *sendbuf, const MPI_Aint sendcounts[],
                             const MPI_Aint sdispls[], MPI_Datatype sendtype,
                             void *recvbuf, const MPI_Aint recvcounts[],
                             const MPI_Aint rdispls[], MPI_Datatype recvtype,
                             MPIR_Comm * comm_ptr, MPIR_Request ** request);
int MPIR_Neighbor_alltoallv_init_impl(const void *sendbuf,
                                      const MPI_Aint sendcounts[],
                                      const MPI_Aint sdispls[],
                                      MPI_Datatype sendtype, void *recvbuf,
                                      const MPI_Aint recvcounts[],
                                      const MPI_Aint rdispls[],
                                      MPI_Datatype recvtype,
                                      MPIR_Comm * comm_ptr,
                                      MPIR_Info * info_ptr,
                                      MPIR_Request ** request);
int MPIR_Neighbor_alltoallv_init(const void *sendbuf,
                                 const MPI_Aint sendcounts[],
                                 const MPI_Aint sdispls[],
                                 MPI_Datatype sendtype, void *recvbuf,
                                 const MPI_Aint recvcounts[],
                                 const MPI_Aint rdispls[],
                                 MPI_Datatype recvtype, MPIR_Comm * comm_ptr,
                                 MPIR_Info * info_ptr,
                                 MPIR_Request ** request);
int MPIR_Neighbor_alltoallw_allcomm_auto(const void *sendbuf,
                    const MPI_Aint sendcounts[], const MPI_Aint sdispls[],
                    const MPI_Datatype sendtypes[], void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                    const MPI_Datatype recvtypes[], MPIR_Comm * comm_ptr);
int MPIR_Neighbor_alltoallw_allcomm_nb(const void *sendbuf,
                                       const MPI_Aint sendcounts[],
                                       const MPI_Aint sdispls[],
                                       const MPI_Datatype sendtypes[],
                                       void *recvbuf,
                                       const MPI_Aint recvcounts[],
                                       const MPI_Aint rdispls[],
                                       const MPI_Datatype recvtypes[],
                                       MPIR_Comm * comm_ptr);;
int MPIR_Neighbor_alltoallw_impl(const void *sendbuf,
                                 const MPI_Aint sendcounts[],
                                 const MPI_Aint sdispls[],
                                 const MPI_Datatype sendtypes[], void *recvbuf,
                                 const MPI_Aint recvcounts[],
                                 const MPI_Aint rdispls[],
                                 const MPI_Datatype recvtypes[],
                                 MPIR_Comm * comm_ptr);
int MPIR_Neighbor_alltoallw(const void *sendbuf, const MPI_Aint sendcounts[],
                            const MPI_Aint sdispls[],
                            const MPI_Datatype sendtypes[], void *recvbuf,
                            const MPI_Aint recvcounts[],
                            const MPI_Aint rdispls[],
                            const MPI_Datatype recvtypes[],
                            MPIR_Comm * comm_ptr);
int MPIR_Ineighbor_alltoallw_allcomm_sched_auto(const void *sendbuf,
                    const MPI_Aint sendcounts[], const MPI_Aint sdispls[],
                    const MPI_Datatype sendtypes[], void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                    const MPI_Datatype recvtypes[], MPIR_Comm * comm_ptr,
                    bool is_persistent, void **sched_p,
                    enum MPIR_sched_type *sched_type_p);
int MPIR_Ineighbor_alltoallw_intra_sched_auto(const void *sendbuf,
                    const MPI_Aint sendcounts[], const MPI_Aint sdispls[],
                    const MPI_Datatype sendtypes[], void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                    const MPI_Datatype recvtypes[], MPIR_Comm * comm_ptr,
                    MPIR_Sched_t s);
int MPIR_Ineighbor_alltoallw_allcomm_sched_linear(const void *sendbuf,
                    const MPI_Aint sendcounts[], const MPI_Aint sdispls[],
                    const MPI_Datatype sendtypes[], void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                    const MPI_Datatype recvtypes[], MPIR_Comm * comm_ptr,
                    MPIR_Sched_t s);
int MPIR_TSP_Ineighbor_alltoallw_sched_allcomm_linear(const void *sendbuf,
                    const MPI_Aint sendcounts[], const MPI_Aint sdispls[],
                    const MPI_Datatype sendtypes[], void *recvbuf,
                    const MPI_Aint recvcounts[], const MPI_Aint rdispls[],
                    const MPI_Datatype recvtypes[], MPIR_Comm * comm_ptr,
                    MPIR_TSP_sched_t sched);
int MPIR_Ineighbor_alltoallw_sched_impl(const void *sendbuf,
                                        const MPI_Aint sendcounts[],
                                        const MPI_Aint sdispls[],
                                        const MPI_Datatype sendtypes[],
                                        void *recvbuf,
                                        const MPI_Aint recvcounts[],
                                        const MPI_Aint rdispls[],
                                        const MPI_Datatype recvtypes[],
                                        MPIR_Comm * comm_ptr,
                                        bool is_persistent, void **sched_p,
                                        enum MPIR_sched_type *sched_type_p);
int MPIR_Ineighbor_alltoallw_impl(const void *sendbuf,
                                  const MPI_Aint sendcounts[],
                                  const MPI_Aint sdispls[],
                                  const MPI_Datatype sendtypes[], void *recvbuf,
                                  const MPI_Aint recvcounts[],
                                  const MPI_Aint rdispls[],
                                  const MPI_Datatype recvtypes[],
                                  MPIR_Comm * comm_ptr,
                                  MPIR_Request ** request);
int MPIR_Ineighbor_alltoallw(const void *sendbuf, const MPI_Aint sendcounts[],
                             const MPI_Aint sdispls[],
                             const MPI_Datatype sendtypes[], void *recvbuf,
                             const MPI_Aint recvcounts[],
                             const MPI_Aint rdispls[],
                             const MPI_Datatype recvtypes[],
                             MPIR_Comm * comm_ptr, MPIR_Request ** request);
int MPIR_Neighbor_alltoallw_init_impl(const void *sendbuf,
                                      const MPI_Aint sendcounts[],
                                      const MPI_Aint sdispls[],
                                      const MPI_Datatype sendtypes[],
                                      void *recvbuf,
                                      const MPI_Aint recvcounts[],
                                      const MPI_Aint rdispls[],
                                      const MPI_Datatype recvtypes[],
                                      MPIR_Comm * comm_ptr,
                                      MPIR_Info * info_ptr,
                                      MPIR_Request ** request);
int MPIR_Neighbor_alltoallw_init(const void *sendbuf,
                                 const MPI_Aint sendcounts[],
                                 const MPI_Aint sdispls[],
                                 const MPI_Datatype sendtypes[], void *recvbuf,
                                 const MPI_Aint recvcounts[],
                                 const MPI_Aint rdispls[],
                                 const MPI_Datatype recvtypes[],
                                 MPIR_Comm * comm_ptr, MPIR_Info * info_ptr,
                                 MPIR_Request ** request);
#endif /* COLL_ALGOS_H_INCLUDED */
