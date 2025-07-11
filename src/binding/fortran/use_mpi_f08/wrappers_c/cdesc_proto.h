/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

int MPIR_Allgather_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                         MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                         int recvcount, MPI_Datatype recvtype, MPI_Comm comm) ;
int MPIR_Allgather_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                               MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                               MPI_Count recvcount, MPI_Datatype recvtype,
                               MPI_Comm comm) ;
int MPIR_Allgather_init_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                              MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                              int recvcount, MPI_Datatype recvtype,
                              MPI_Comm comm, MPI_Info info,
                              MPI_Request *request) ;
int MPIR_Allgather_init_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                                    MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                                    MPI_Count recvcount, MPI_Datatype recvtype,
                                    MPI_Comm comm, MPI_Info info,
                                    MPI_Request *request) ;
int MPIR_Allgatherv_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                          MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                          const int recvcounts[], const int displs[],
                          MPI_Datatype recvtype, MPI_Comm comm) ;
int MPIR_Allgatherv_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                                MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                                const MPI_Count recvcounts[],
                                const MPI_Aint displs[], MPI_Datatype recvtype,
                                MPI_Comm comm) ;
int MPIR_Allgatherv_init_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                               MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                               const int recvcounts[], const int displs[],
                               MPI_Datatype recvtype, MPI_Comm comm,
                               MPI_Info info, MPI_Request *request) ;
int MPIR_Allgatherv_init_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                                     MPI_Datatype sendtype,
                                     CFI_cdesc_t *recvbuf,
                                     const MPI_Count recvcounts[],
                                     const MPI_Aint displs[],
                                     MPI_Datatype recvtype, MPI_Comm comm,
                                     MPI_Info info, MPI_Request *request) ;
int MPIR_Allreduce_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf, int count,
                         MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) ;
int MPIR_Allreduce_cdesc_large(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                               MPI_Count count, MPI_Datatype datatype,
                               MPI_Op op, MPI_Comm comm) ;
int MPIR_Allreduce_init_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                              int count, MPI_Datatype datatype, MPI_Op op,
                              MPI_Comm comm, MPI_Info info,
                              MPI_Request *request) ;
int MPIR_Allreduce_init_cdesc_large(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                                    MPI_Count count, MPI_Datatype datatype,
                                    MPI_Op op, MPI_Comm comm, MPI_Info info,
                                    MPI_Request *request) ;
int MPIR_Alltoall_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                        MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                        int recvcount, MPI_Datatype recvtype, MPI_Comm comm) ;
int MPIR_Alltoall_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                              MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                              MPI_Count recvcount, MPI_Datatype recvtype,
                              MPI_Comm comm) ;
int MPIR_Alltoall_init_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                             MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                             int recvcount, MPI_Datatype recvtype,
                             MPI_Comm comm, MPI_Info info,
                             MPI_Request *request) ;
int MPIR_Alltoall_init_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                                   MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                                   MPI_Count recvcount, MPI_Datatype recvtype,
                                   MPI_Comm comm, MPI_Info info,
                                   MPI_Request *request) ;
int MPIR_Alltoallv_cdesc(CFI_cdesc_t *sendbuf, const int sendcounts[],
                         const int sdispls[], MPI_Datatype sendtype,
                         CFI_cdesc_t *recvbuf, const int recvcounts[],
                         const int rdispls[], MPI_Datatype recvtype,
                         MPI_Comm comm) ;
int MPIR_Alltoallv_cdesc_large(CFI_cdesc_t *sendbuf,
                               const MPI_Count sendcounts[],
                               const MPI_Aint sdispls[], MPI_Datatype sendtype,
                               CFI_cdesc_t *recvbuf,
                               const MPI_Count recvcounts[],
                               const MPI_Aint rdispls[], MPI_Datatype recvtype,
                               MPI_Comm comm) ;
int MPIR_Alltoallv_init_cdesc(CFI_cdesc_t *sendbuf, const int sendcounts[],
                              const int sdispls[], MPI_Datatype sendtype,
                              CFI_cdesc_t *recvbuf, const int recvcounts[],
                              const int rdispls[], MPI_Datatype recvtype,
                              MPI_Comm comm, MPI_Info info,
                              MPI_Request *request) ;
int MPIR_Alltoallv_init_cdesc_large(CFI_cdesc_t *sendbuf,
                                    const MPI_Count sendcounts[],
                                    const MPI_Aint sdispls[],
                                    MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                                    const MPI_Count recvcounts[],
                                    const MPI_Aint rdispls[],
                                    MPI_Datatype recvtype, MPI_Comm comm,
                                    MPI_Info info, MPI_Request *request) ;
int MPIR_Alltoallw_cdesc(CFI_cdesc_t *sendbuf, const int sendcounts[],
                         const int sdispls[], const MPI_Datatype sendtypes[],
                         CFI_cdesc_t *recvbuf, const int recvcounts[],
                         const int rdispls[], const MPI_Datatype recvtypes[],
                         MPI_Comm comm) ;
int MPIR_Alltoallw_cdesc_large(CFI_cdesc_t *sendbuf,
                               const MPI_Count sendcounts[],
                               const MPI_Aint sdispls[],
                               const MPI_Datatype sendtypes[],
                               CFI_cdesc_t *recvbuf,
                               const MPI_Count recvcounts[],
                               const MPI_Aint rdispls[],
                               const MPI_Datatype recvtypes[], MPI_Comm comm) ;
int MPIR_Alltoallw_init_cdesc(CFI_cdesc_t *sendbuf, const int sendcounts[],
                              const int sdispls[],
                              const MPI_Datatype sendtypes[],
                              CFI_cdesc_t *recvbuf, const int recvcounts[],
                              const int rdispls[],
                              const MPI_Datatype recvtypes[], MPI_Comm comm,
                              MPI_Info info, MPI_Request *request) ;
int MPIR_Alltoallw_init_cdesc_large(CFI_cdesc_t *sendbuf,
                                    const MPI_Count sendcounts[],
                                    const MPI_Aint sdispls[],
                                    const MPI_Datatype sendtypes[],
                                    CFI_cdesc_t *recvbuf,
                                    const MPI_Count recvcounts[],
                                    const MPI_Aint rdispls[],
                                    const MPI_Datatype recvtypes[],
                                    MPI_Comm comm, MPI_Info info,
                                    MPI_Request *request) ;
int MPIR_Bcast_cdesc(CFI_cdesc_t *buffer, int count, MPI_Datatype datatype,
                     int root, MPI_Comm comm) ;
int MPIR_Bcast_cdesc_large(CFI_cdesc_t *buffer, MPI_Count count,
                           MPI_Datatype datatype, int root, MPI_Comm comm) ;
int MPIR_Bcast_init_cdesc(CFI_cdesc_t *buffer, int count, MPI_Datatype datatype,
                          int root, MPI_Comm comm, MPI_Info info,
                          MPI_Request *request) ;
int MPIR_Bcast_init_cdesc_large(CFI_cdesc_t *buffer, MPI_Count count,
                                MPI_Datatype datatype, int root, MPI_Comm comm,
                                MPI_Info info, MPI_Request *request) ;
int MPIR_Exscan_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf, int count,
                      MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) ;
int MPIR_Exscan_cdesc_large(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                            MPI_Count count, MPI_Datatype datatype, MPI_Op op,
                            MPI_Comm comm) ;
int MPIR_Exscan_init_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                           int count, MPI_Datatype datatype, MPI_Op op,
                           MPI_Comm comm, MPI_Info info, MPI_Request *request) ;
int MPIR_Exscan_init_cdesc_large(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                                 MPI_Count count, MPI_Datatype datatype,
                                 MPI_Op op, MPI_Comm comm, MPI_Info info,
                                 MPI_Request *request) ;
int MPIR_Gather_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                      MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                      int recvcount, MPI_Datatype recvtype, int root,
                      MPI_Comm comm) ;
int MPIR_Gather_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                            MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                            MPI_Count recvcount, MPI_Datatype recvtype,
                            int root, MPI_Comm comm) ;
int MPIR_Gather_init_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                           MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                           int recvcount, MPI_Datatype recvtype, int root,
                           MPI_Comm comm, MPI_Info info, MPI_Request *request) ;
int MPIR_Gather_init_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                                 MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                                 MPI_Count recvcount, MPI_Datatype recvtype,
                                 int root, MPI_Comm comm, MPI_Info info,
                                 MPI_Request *request) ;
int MPIR_Gatherv_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                       MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                       const int recvcounts[], const int displs[],
                       MPI_Datatype recvtype, int root, MPI_Comm comm) ;
int MPIR_Gatherv_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                             MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                             const MPI_Count recvcounts[],
                             const MPI_Aint displs[], MPI_Datatype recvtype,
                             int root, MPI_Comm comm) ;
int MPIR_Gatherv_init_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                            MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                            const int recvcounts[], const int displs[],
                            MPI_Datatype recvtype, int root, MPI_Comm comm,
                            MPI_Info info, MPI_Request *request) ;
int MPIR_Gatherv_init_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                                  MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                                  const MPI_Count recvcounts[],
                                  const MPI_Aint displs[],
                                  MPI_Datatype recvtype, int root,
                                  MPI_Comm comm, MPI_Info info,
                                  MPI_Request *request) ;
int MPIR_Iallgather_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                          MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                          int recvcount, MPI_Datatype recvtype, MPI_Comm comm,
                          MPI_Request *request) ;
int MPIR_Iallgather_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                                MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                                MPI_Count recvcount, MPI_Datatype recvtype,
                                MPI_Comm comm, MPI_Request *request) ;
int MPIR_Iallgatherv_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                           MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                           const int recvcounts[], const int displs[],
                           MPI_Datatype recvtype, MPI_Comm comm,
                           MPI_Request *request) ;
int MPIR_Iallgatherv_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                                 MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                                 const MPI_Count recvcounts[],
                                 const MPI_Aint displs[], MPI_Datatype recvtype,
                                 MPI_Comm comm, MPI_Request *request) ;
int MPIR_Iallreduce_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf, int count,
                          MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                          MPI_Request *request) ;
int MPIR_Iallreduce_cdesc_large(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                                MPI_Count count, MPI_Datatype datatype,
                                MPI_Op op, MPI_Comm comm, MPI_Request *request) ;
int MPIR_Ialltoall_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                         MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                         int recvcount, MPI_Datatype recvtype, MPI_Comm comm,
                         MPI_Request *request) ;
int MPIR_Ialltoall_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                               MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                               MPI_Count recvcount, MPI_Datatype recvtype,
                               MPI_Comm comm, MPI_Request *request) ;
int MPIR_Ialltoallv_cdesc(CFI_cdesc_t *sendbuf, const int sendcounts[],
                          const int sdispls[], MPI_Datatype sendtype,
                          CFI_cdesc_t *recvbuf, const int recvcounts[],
                          const int rdispls[], MPI_Datatype recvtype,
                          MPI_Comm comm, MPI_Request *request) ;
int MPIR_Ialltoallv_cdesc_large(CFI_cdesc_t *sendbuf,
                                const MPI_Count sendcounts[],
                                const MPI_Aint sdispls[], MPI_Datatype sendtype,
                                CFI_cdesc_t *recvbuf,
                                const MPI_Count recvcounts[],
                                const MPI_Aint rdispls[], MPI_Datatype recvtype,
                                MPI_Comm comm, MPI_Request *request) ;
int MPIR_Ialltoallw_cdesc(CFI_cdesc_t *sendbuf, const int sendcounts[],
                          const int sdispls[], const MPI_Datatype sendtypes[],
                          CFI_cdesc_t *recvbuf, const int recvcounts[],
                          const int rdispls[], const MPI_Datatype recvtypes[],
                          MPI_Comm comm, MPI_Request *request) ;
int MPIR_Ialltoallw_cdesc_large(CFI_cdesc_t *sendbuf,
                                const MPI_Count sendcounts[],
                                const MPI_Aint sdispls[],
                                const MPI_Datatype sendtypes[],
                                CFI_cdesc_t *recvbuf,
                                const MPI_Count recvcounts[],
                                const MPI_Aint rdispls[],
                                const MPI_Datatype recvtypes[], MPI_Comm comm,
                                MPI_Request *request) ;
int MPIR_Ibcast_cdesc(CFI_cdesc_t *buffer, int count, MPI_Datatype datatype,
                      int root, MPI_Comm comm, MPI_Request *request) ;
int MPIR_Ibcast_cdesc_large(CFI_cdesc_t *buffer, MPI_Count count,
                            MPI_Datatype datatype, int root, MPI_Comm comm,
                            MPI_Request *request) ;
int MPIR_Iexscan_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf, int count,
                       MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                       MPI_Request *request) ;
int MPIR_Iexscan_cdesc_large(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                             MPI_Count count, MPI_Datatype datatype, MPI_Op op,
                             MPI_Comm comm, MPI_Request *request) ;
int MPIR_Igather_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                       MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                       int recvcount, MPI_Datatype recvtype, int root,
                       MPI_Comm comm, MPI_Request *request) ;
int MPIR_Igather_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                             MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                             MPI_Count recvcount, MPI_Datatype recvtype,
                             int root, MPI_Comm comm, MPI_Request *request) ;
int MPIR_Igatherv_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                        MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                        const int recvcounts[], const int displs[],
                        MPI_Datatype recvtype, int root, MPI_Comm comm,
                        MPI_Request *request) ;
int MPIR_Igatherv_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                              MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                              const MPI_Count recvcounts[],
                              const MPI_Aint displs[], MPI_Datatype recvtype,
                              int root, MPI_Comm comm, MPI_Request *request) ;
int MPIR_Ineighbor_allgather_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                                   MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                                   int recvcount, MPI_Datatype recvtype,
                                   MPI_Comm comm, MPI_Request *request) ;
int MPIR_Ineighbor_allgather_cdesc_large(CFI_cdesc_t *sendbuf,
                    MPI_Count sendcount, MPI_Datatype sendtype,
                    CFI_cdesc_t *recvbuf, MPI_Count recvcount,
                    MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) ;
int MPIR_Ineighbor_allgatherv_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                                    MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                                    const int recvcounts[], const int displs[],
                                    MPI_Datatype recvtype, MPI_Comm comm,
                                    MPI_Request *request) ;
int MPIR_Ineighbor_allgatherv_cdesc_large(CFI_cdesc_t *sendbuf,
                    MPI_Count sendcount, MPI_Datatype sendtype,
                    CFI_cdesc_t *recvbuf, const MPI_Count recvcounts[],
                    const MPI_Aint displs[], MPI_Datatype recvtype,
                    MPI_Comm comm, MPI_Request *request) ;
int MPIR_Ineighbor_alltoall_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                                  MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                                  int recvcount, MPI_Datatype recvtype,
                                  MPI_Comm comm, MPI_Request *request) ;
int MPIR_Ineighbor_alltoall_cdesc_large(CFI_cdesc_t *sendbuf,
                                        MPI_Count sendcount,
                                        MPI_Datatype sendtype,
                                        CFI_cdesc_t *recvbuf,
                                        MPI_Count recvcount,
                                        MPI_Datatype recvtype, MPI_Comm comm,
                                        MPI_Request *request) ;
int MPIR_Ineighbor_alltoallv_cdesc(CFI_cdesc_t *sendbuf, const int sendcounts[],
                                   const int sdispls[], MPI_Datatype sendtype,
                                   CFI_cdesc_t *recvbuf, const int recvcounts[],
                                   const int rdispls[], MPI_Datatype recvtype,
                                   MPI_Comm comm, MPI_Request *request) ;
int MPIR_Ineighbor_alltoallv_cdesc_large(CFI_cdesc_t *sendbuf,
                    const MPI_Count sendcounts[], const MPI_Aint sdispls[],
                    MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                    const MPI_Count recvcounts[], const MPI_Aint rdispls[],
                    MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request) ;
int MPIR_Ineighbor_alltoallw_cdesc(CFI_cdesc_t *sendbuf, const int sendcounts[],
                                   const MPI_Aint sdispls[],
                                   const MPI_Datatype sendtypes[],
                                   CFI_cdesc_t *recvbuf, const int recvcounts[],
                                   const MPI_Aint rdispls[],
                                   const MPI_Datatype recvtypes[],
                                   MPI_Comm comm, MPI_Request *request) ;
int MPIR_Ineighbor_alltoallw_cdesc_large(CFI_cdesc_t *sendbuf,
                    const MPI_Count sendcounts[], const MPI_Aint sdispls[],
                    const MPI_Datatype sendtypes[], CFI_cdesc_t *recvbuf,
                    const MPI_Count recvcounts[], const MPI_Aint rdispls[],
                    const MPI_Datatype recvtypes[], MPI_Comm comm,
                    MPI_Request *request) ;
int MPIR_Ireduce_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf, int count,
                       MPI_Datatype datatype, MPI_Op op, int root,
                       MPI_Comm comm, MPI_Request *request) ;
int MPIR_Ireduce_cdesc_large(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                             MPI_Count count, MPI_Datatype datatype, MPI_Op op,
                             int root, MPI_Comm comm, MPI_Request *request) ;
int MPIR_Ireduce_scatter_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                               const int recvcounts[], MPI_Datatype datatype,
                               MPI_Op op, MPI_Comm comm, MPI_Request *request) ;
int MPIR_Ireduce_scatter_cdesc_large(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                                     const MPI_Count recvcounts[],
                                     MPI_Datatype datatype, MPI_Op op,
                                     MPI_Comm comm, MPI_Request *request) ;
int MPIR_Ireduce_scatter_block_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                                     int recvcount, MPI_Datatype datatype,
                                     MPI_Op op, MPI_Comm comm,
                                     MPI_Request *request) ;
int MPIR_Ireduce_scatter_block_cdesc_large(CFI_cdesc_t *sendbuf,
                    CFI_cdesc_t *recvbuf, MPI_Count recvcount,
                    MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                    MPI_Request *request) ;
int MPIR_Iscan_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf, int count,
                     MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                     MPI_Request *request) ;
int MPIR_Iscan_cdesc_large(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                           MPI_Count count, MPI_Datatype datatype, MPI_Op op,
                           MPI_Comm comm, MPI_Request *request) ;
int MPIR_Iscatter_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                        MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                        int recvcount, MPI_Datatype recvtype, int root,
                        MPI_Comm comm, MPI_Request *request) ;
int MPIR_Iscatter_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                              MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                              MPI_Count recvcount, MPI_Datatype recvtype,
                              int root, MPI_Comm comm, MPI_Request *request) ;
int MPIR_Iscatterv_cdesc(CFI_cdesc_t *sendbuf, const int sendcounts[],
                         const int displs[], MPI_Datatype sendtype,
                         CFI_cdesc_t *recvbuf, int recvcount,
                         MPI_Datatype recvtype, int root, MPI_Comm comm,
                         MPI_Request *request) ;
int MPIR_Iscatterv_cdesc_large(CFI_cdesc_t *sendbuf,
                               const MPI_Count sendcounts[],
                               const MPI_Aint displs[], MPI_Datatype sendtype,
                               CFI_cdesc_t *recvbuf, MPI_Count recvcount,
                               MPI_Datatype recvtype, int root, MPI_Comm comm,
                               MPI_Request *request) ;
int MPIR_Neighbor_allgather_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                                  MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                                  int recvcount, MPI_Datatype recvtype,
                                  MPI_Comm comm) ;
int MPIR_Neighbor_allgather_cdesc_large(CFI_cdesc_t *sendbuf,
                                        MPI_Count sendcount,
                                        MPI_Datatype sendtype,
                                        CFI_cdesc_t *recvbuf,
                                        MPI_Count recvcount,
                                        MPI_Datatype recvtype, MPI_Comm comm) ;
int MPIR_Neighbor_allgather_init_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                                       MPI_Datatype sendtype,
                                       CFI_cdesc_t *recvbuf, int recvcount,
                                       MPI_Datatype recvtype, MPI_Comm comm,
                                       MPI_Info info, MPI_Request *request) ;
int MPIR_Neighbor_allgather_init_cdesc_large(CFI_cdesc_t *sendbuf,
                    MPI_Count sendcount, MPI_Datatype sendtype,
                    CFI_cdesc_t *recvbuf, MPI_Count recvcount,
                    MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info,
                    MPI_Request *request) ;
int MPIR_Neighbor_allgatherv_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                                   MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                                   const int recvcounts[], const int displs[],
                                   MPI_Datatype recvtype, MPI_Comm comm) ;
int MPIR_Neighbor_allgatherv_cdesc_large(CFI_cdesc_t *sendbuf,
                    MPI_Count sendcount, MPI_Datatype sendtype,
                    CFI_cdesc_t *recvbuf, const MPI_Count recvcounts[],
                    const MPI_Aint displs[], MPI_Datatype recvtype,
                    MPI_Comm comm) ;
int MPIR_Neighbor_allgatherv_init_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                                        MPI_Datatype sendtype,
                                        CFI_cdesc_t *recvbuf,
                                        const int recvcounts[],
                                        const int displs[],
                                        MPI_Datatype recvtype, MPI_Comm comm,
                                        MPI_Info info, MPI_Request *request) ;
int MPIR_Neighbor_allgatherv_init_cdesc_large(CFI_cdesc_t *sendbuf,
                    MPI_Count sendcount, MPI_Datatype sendtype,
                    CFI_cdesc_t *recvbuf, const MPI_Count recvcounts[],
                    const MPI_Aint displs[], MPI_Datatype recvtype,
                    MPI_Comm comm, MPI_Info info, MPI_Request *request) ;
int MPIR_Neighbor_alltoall_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                                 MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                                 int recvcount, MPI_Datatype recvtype,
                                 MPI_Comm comm) ;
int MPIR_Neighbor_alltoall_cdesc_large(CFI_cdesc_t *sendbuf,
                                       MPI_Count sendcount,
                                       MPI_Datatype sendtype,
                                       CFI_cdesc_t *recvbuf,
                                       MPI_Count recvcount,
                                       MPI_Datatype recvtype, MPI_Comm comm) ;
int MPIR_Neighbor_alltoall_init_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                                      MPI_Datatype sendtype,
                                      CFI_cdesc_t *recvbuf, int recvcount,
                                      MPI_Datatype recvtype, MPI_Comm comm,
                                      MPI_Info info, MPI_Request *request) ;
int MPIR_Neighbor_alltoall_init_cdesc_large(CFI_cdesc_t *sendbuf,
                    MPI_Count sendcount, MPI_Datatype sendtype,
                    CFI_cdesc_t *recvbuf, MPI_Count recvcount,
                    MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info,
                    MPI_Request *request) ;
int MPIR_Neighbor_alltoallv_cdesc(CFI_cdesc_t *sendbuf, const int sendcounts[],
                                  const int sdispls[], MPI_Datatype sendtype,
                                  CFI_cdesc_t *recvbuf, const int recvcounts[],
                                  const int rdispls[], MPI_Datatype recvtype,
                                  MPI_Comm comm) ;
int MPIR_Neighbor_alltoallv_cdesc_large(CFI_cdesc_t *sendbuf,
                                        const MPI_Count sendcounts[],
                                        const MPI_Aint sdispls[],
                                        MPI_Datatype sendtype,
                                        CFI_cdesc_t *recvbuf,
                                        const MPI_Count recvcounts[],
                                        const MPI_Aint rdispls[],
                                        MPI_Datatype recvtype, MPI_Comm comm) ;
int MPIR_Neighbor_alltoallv_init_cdesc(CFI_cdesc_t *sendbuf,
                                       const int sendcounts[],
                                       const int sdispls[],
                                       MPI_Datatype sendtype,
                                       CFI_cdesc_t *recvbuf,
                                       const int recvcounts[],
                                       const int rdispls[],
                                       MPI_Datatype recvtype, MPI_Comm comm,
                                       MPI_Info info, MPI_Request *request) ;
int MPIR_Neighbor_alltoallv_init_cdesc_large(CFI_cdesc_t *sendbuf,
                    const MPI_Count sendcounts[], const MPI_Aint sdispls[],
                    MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                    const MPI_Count recvcounts[], const MPI_Aint rdispls[],
                    MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info,
                    MPI_Request *request) ;
int MPIR_Neighbor_alltoallw_cdesc(CFI_cdesc_t *sendbuf, const int sendcounts[],
                                  const MPI_Aint sdispls[],
                                  const MPI_Datatype sendtypes[],
                                  CFI_cdesc_t *recvbuf, const int recvcounts[],
                                  const MPI_Aint rdispls[],
                                  const MPI_Datatype recvtypes[],
                                  MPI_Comm comm) ;
int MPIR_Neighbor_alltoallw_cdesc_large(CFI_cdesc_t *sendbuf,
                                        const MPI_Count sendcounts[],
                                        const MPI_Aint sdispls[],
                                        const MPI_Datatype sendtypes[],
                                        CFI_cdesc_t *recvbuf,
                                        const MPI_Count recvcounts[],
                                        const MPI_Aint rdispls[],
                                        const MPI_Datatype recvtypes[],
                                        MPI_Comm comm) ;
int MPIR_Neighbor_alltoallw_init_cdesc(CFI_cdesc_t *sendbuf,
                                       const int sendcounts[],
                                       const MPI_Aint sdispls[],
                                       const MPI_Datatype sendtypes[],
                                       CFI_cdesc_t *recvbuf,
                                       const int recvcounts[],
                                       const MPI_Aint rdispls[],
                                       const MPI_Datatype recvtypes[],
                                       MPI_Comm comm, MPI_Info info,
                                       MPI_Request *request) ;
int MPIR_Neighbor_alltoallw_init_cdesc_large(CFI_cdesc_t *sendbuf,
                    const MPI_Count sendcounts[], const MPI_Aint sdispls[],
                    const MPI_Datatype sendtypes[], CFI_cdesc_t *recvbuf,
                    const MPI_Count recvcounts[], const MPI_Aint rdispls[],
                    const MPI_Datatype recvtypes[], MPI_Comm comm,
                    MPI_Info info, MPI_Request *request) ;
int MPIR_Reduce_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf, int count,
                      MPI_Datatype datatype, MPI_Op op, int root,
                      MPI_Comm comm) ;
int MPIR_Reduce_cdesc_large(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                            MPI_Count count, MPI_Datatype datatype, MPI_Op op,
                            int root, MPI_Comm comm) ;
int MPIR_Reduce_init_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                           int count, MPI_Datatype datatype, MPI_Op op,
                           int root, MPI_Comm comm, MPI_Info info,
                           MPI_Request *request) ;
int MPIR_Reduce_init_cdesc_large(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                                 MPI_Count count, MPI_Datatype datatype,
                                 MPI_Op op, int root, MPI_Comm comm,
                                 MPI_Info info, MPI_Request *request) ;
int MPIR_Reduce_local_cdesc(CFI_cdesc_t *inbuf, CFI_cdesc_t *inoutbuf,
                            int count, MPI_Datatype datatype, MPI_Op op) ;
int MPIR_Reduce_local_cdesc_large(CFI_cdesc_t *inbuf, CFI_cdesc_t *inoutbuf,
                                  MPI_Count count, MPI_Datatype datatype,
                                  MPI_Op op) ;
int MPIR_Reduce_scatter_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                              const int recvcounts[], MPI_Datatype datatype,
                              MPI_Op op, MPI_Comm comm) ;
int MPIR_Reduce_scatter_cdesc_large(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                                    const MPI_Count recvcounts[],
                                    MPI_Datatype datatype, MPI_Op op,
                                    MPI_Comm comm) ;
int MPIR_Reduce_scatter_block_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                                    int recvcount, MPI_Datatype datatype,
                                    MPI_Op op, MPI_Comm comm) ;
int MPIR_Reduce_scatter_block_cdesc_large(CFI_cdesc_t *sendbuf,
                    CFI_cdesc_t *recvbuf, MPI_Count recvcount,
                    MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) ;
int MPIR_Reduce_scatter_block_init_cdesc(CFI_cdesc_t *sendbuf,
                    CFI_cdesc_t *recvbuf, int recvcount, MPI_Datatype datatype,
                    MPI_Op op, MPI_Comm comm, MPI_Info info,
                    MPI_Request *request) ;
int MPIR_Reduce_scatter_block_init_cdesc_large(CFI_cdesc_t *sendbuf,
                    CFI_cdesc_t *recvbuf, MPI_Count recvcount,
                    MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                    MPI_Info info, MPI_Request *request) ;
int MPIR_Reduce_scatter_init_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                                   const int recvcounts[],
                                   MPI_Datatype datatype, MPI_Op op,
                                   MPI_Comm comm, MPI_Info info,
                                   MPI_Request *request) ;
int MPIR_Reduce_scatter_init_cdesc_large(CFI_cdesc_t *sendbuf,
                    CFI_cdesc_t *recvbuf, const MPI_Count recvcounts[],
                    MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                    MPI_Info info, MPI_Request *request) ;
int MPIR_Scan_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf, int count,
                    MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) ;
int MPIR_Scan_cdesc_large(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                          MPI_Count count, MPI_Datatype datatype, MPI_Op op,
                          MPI_Comm comm) ;
int MPIR_Scan_init_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf, int count,
                         MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                         MPI_Info info, MPI_Request *request) ;
int MPIR_Scan_init_cdesc_large(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                               MPI_Count count, MPI_Datatype datatype,
                               MPI_Op op, MPI_Comm comm, MPI_Info info,
                               MPI_Request *request) ;
int MPIR_Scatter_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                       MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                       int recvcount, MPI_Datatype recvtype, int root,
                       MPI_Comm comm) ;
int MPIR_Scatter_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                             MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                             MPI_Count recvcount, MPI_Datatype recvtype,
                             int root, MPI_Comm comm) ;
int MPIR_Scatter_init_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                            MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                            int recvcount, MPI_Datatype recvtype, int root,
                            MPI_Comm comm, MPI_Info info, MPI_Request *request) ;
int MPIR_Scatter_init_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                                  MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                                  MPI_Count recvcount, MPI_Datatype recvtype,
                                  int root, MPI_Comm comm, MPI_Info info,
                                  MPI_Request *request) ;
int MPIR_Scatterv_cdesc(CFI_cdesc_t *sendbuf, const int sendcounts[],
                        const int displs[], MPI_Datatype sendtype,
                        CFI_cdesc_t *recvbuf, int recvcount,
                        MPI_Datatype recvtype, int root, MPI_Comm comm) ;
int MPIR_Scatterv_cdesc_large(CFI_cdesc_t *sendbuf,
                              const MPI_Count sendcounts[],
                              const MPI_Aint displs[], MPI_Datatype sendtype,
                              CFI_cdesc_t *recvbuf, MPI_Count recvcount,
                              MPI_Datatype recvtype, int root, MPI_Comm comm) ;
int MPIR_Scatterv_init_cdesc(CFI_cdesc_t *sendbuf, const int sendcounts[],
                             const int displs[], MPI_Datatype sendtype,
                             CFI_cdesc_t *recvbuf, int recvcount,
                             MPI_Datatype recvtype, int root, MPI_Comm comm,
                             MPI_Info info, MPI_Request *request) ;
int MPIR_Scatterv_init_cdesc_large(CFI_cdesc_t *sendbuf,
                                   const MPI_Count sendcounts[],
                                   const MPI_Aint displs[],
                                   MPI_Datatype sendtype, CFI_cdesc_t *recvbuf,
                                   MPI_Count recvcount, MPI_Datatype recvtype,
                                   int root, MPI_Comm comm, MPI_Info info,
                                   MPI_Request *request) ;
int MPIR_Get_address_cdesc(CFI_cdesc_t *location, MPI_Aint *address) ;
int MPIR_Pack_cdesc(CFI_cdesc_t *inbuf, int incount, MPI_Datatype datatype,
                    CFI_cdesc_t *outbuf, int outsize, int *position,
                    MPI_Comm comm) ;
int MPIR_Pack_cdesc_large(CFI_cdesc_t *inbuf, MPI_Count incount,
                          MPI_Datatype datatype, CFI_cdesc_t *outbuf,
                          MPI_Count outsize, MPI_Count *position,
                          MPI_Comm comm) ;
int MPIR_Pack_external_cdesc(const char *datarep, CFI_cdesc_t *inbuf,
                             int incount, MPI_Datatype datatype,
                             CFI_cdesc_t *outbuf, MPI_Aint outsize,
                             MPI_Aint *position) ;
int MPIR_Pack_external_cdesc_large(const char *datarep, CFI_cdesc_t *inbuf,
                                   MPI_Count incount, MPI_Datatype datatype,
                                   CFI_cdesc_t *outbuf, MPI_Count outsize,
                                   MPI_Count *position) ;
int MPIR_Unpack_cdesc(CFI_cdesc_t *inbuf, int insize, int *position,
                      CFI_cdesc_t *outbuf, int outcount, MPI_Datatype datatype,
                      MPI_Comm comm) ;
int MPIR_Unpack_cdesc_large(CFI_cdesc_t *inbuf, MPI_Count insize,
                            MPI_Count *position, CFI_cdesc_t *outbuf,
                            MPI_Count outcount, MPI_Datatype datatype,
                            MPI_Comm comm) ;
int MPIR_Unpack_external_cdesc(const char datarep[], CFI_cdesc_t *inbuf,
                               MPI_Aint insize, MPI_Aint *position,
                               CFI_cdesc_t *outbuf, int outcount,
                               MPI_Datatype datatype) ;
int MPIR_Unpack_external_cdesc_large(const char datarep[], CFI_cdesc_t *inbuf,
                                     MPI_Count insize, MPI_Count *position,
                                     CFI_cdesc_t *outbuf, MPI_Count outcount,
                                     MPI_Datatype datatype) ;
int MPIR_Info_set_hex_cdesc(MPI_Info info, const char *key, CFI_cdesc_t *value,
                            int value_size) ;
int MPIR_Precv_init_cdesc(CFI_cdesc_t *buf, int partitions, MPI_Count count,
                          MPI_Datatype datatype, int dest, int tag,
                          MPI_Comm comm, MPI_Info info, MPI_Request *request) ;
int MPIR_Psend_init_cdesc(CFI_cdesc_t *buf, int partitions, MPI_Count count,
                          MPI_Datatype datatype, int dest, int tag,
                          MPI_Comm comm, MPI_Info info, MPI_Request *request) ;
int MPIR_Bsend_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                     int dest, int tag, MPI_Comm comm) ;
int MPIR_Bsend_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                           MPI_Datatype datatype, int dest, int tag,
                           MPI_Comm comm) ;
int MPIR_Bsend_init_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                          int dest, int tag, MPI_Comm comm,
                          MPI_Request *request) ;
int MPIR_Bsend_init_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                                MPI_Datatype datatype, int dest, int tag,
                                MPI_Comm comm, MPI_Request *request) ;
int MPIR_Buffer_attach_cdesc(CFI_cdesc_t *buffer, int size) ;
int MPIR_Buffer_attach_cdesc_large(CFI_cdesc_t *buffer, MPI_Count size) ;
int MPIR_Comm_attach_buffer_cdesc(MPI_Comm comm, CFI_cdesc_t *buffer, int size) ;
int MPIR_Comm_attach_buffer_cdesc_large(MPI_Comm comm, CFI_cdesc_t *buffer,
                                        MPI_Count size) ;
int MPIR_Ibsend_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                      int dest, int tag, MPI_Comm comm, MPI_Request *request) ;
int MPIR_Ibsend_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                            MPI_Datatype datatype, int dest, int tag,
                            MPI_Comm comm, MPI_Request *request) ;
int MPIR_Imrecv_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                      MPI_Message *message, MPI_Request *request) ;
int MPIR_Imrecv_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                            MPI_Datatype datatype, MPI_Message *message,
                            MPI_Request *request) ;
int MPIR_Irecv_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                     int source, int tag, MPI_Comm comm, MPI_Request *request) ;
int MPIR_Irecv_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                           MPI_Datatype datatype, int source, int tag,
                           MPI_Comm comm, MPI_Request *request) ;
int MPIR_Irsend_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                      int dest, int tag, MPI_Comm comm, MPI_Request *request) ;
int MPIR_Irsend_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                            MPI_Datatype datatype, int dest, int tag,
                            MPI_Comm comm, MPI_Request *request) ;
int MPIR_Isend_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                     int dest, int tag, MPI_Comm comm, MPI_Request *request) ;
int MPIR_Isend_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                           MPI_Datatype datatype, int dest, int tag,
                           MPI_Comm comm, MPI_Request *request) ;
int MPIR_Isendrecv_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                         MPI_Datatype sendtype, int dest, int sendtag,
                         CFI_cdesc_t *recvbuf, int recvcount,
                         MPI_Datatype recvtype, int source, int recvtag,
                         MPI_Comm comm, MPI_Request *request) ;
int MPIR_Isendrecv_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                               MPI_Datatype sendtype, int dest, int sendtag,
                               CFI_cdesc_t *recvbuf, MPI_Count recvcount,
                               MPI_Datatype recvtype, int source, int recvtag,
                               MPI_Comm comm, MPI_Request *request) ;
int MPIR_Isendrecv_replace_cdesc(CFI_cdesc_t *buf, int count,
                                 MPI_Datatype datatype, int dest, int sendtag,
                                 int source, int recvtag, MPI_Comm comm,
                                 MPI_Request *request) ;
int MPIR_Isendrecv_replace_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                                       MPI_Datatype datatype, int dest,
                                       int sendtag, int source, int recvtag,
                                       MPI_Comm comm, MPI_Request *request) ;
int MPIR_Issend_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                      int dest, int tag, MPI_Comm comm, MPI_Request *request) ;
int MPIR_Issend_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                            MPI_Datatype datatype, int dest, int tag,
                            MPI_Comm comm, MPI_Request *request) ;
int MPIR_Mrecv_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                     MPI_Message *message, MPI_Status *status) ;
int MPIR_Mrecv_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                           MPI_Datatype datatype, MPI_Message *message,
                           MPI_Status *status) ;
int MPIR_Recv_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                    int source, int tag, MPI_Comm comm, MPI_Status *status) ;
int MPIR_Recv_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                          MPI_Datatype datatype, int source, int tag,
                          MPI_Comm comm, MPI_Status *status) ;
int MPIR_Recv_init_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                         int source, int tag, MPI_Comm comm,
                         MPI_Request *request) ;
int MPIR_Recv_init_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                               MPI_Datatype datatype, int source, int tag,
                               MPI_Comm comm, MPI_Request *request) ;
int MPIR_Rsend_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                     int dest, int tag, MPI_Comm comm) ;
int MPIR_Rsend_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                           MPI_Datatype datatype, int dest, int tag,
                           MPI_Comm comm) ;
int MPIR_Rsend_init_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                          int dest, int tag, MPI_Comm comm,
                          MPI_Request *request) ;
int MPIR_Rsend_init_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                                MPI_Datatype datatype, int dest, int tag,
                                MPI_Comm comm, MPI_Request *request) ;
int MPIR_Send_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                    int dest, int tag, MPI_Comm comm) ;
int MPIR_Send_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                          MPI_Datatype datatype, int dest, int tag,
                          MPI_Comm comm) ;
int MPIR_Send_init_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                         int dest, int tag, MPI_Comm comm,
                         MPI_Request *request) ;
int MPIR_Send_init_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                               MPI_Datatype datatype, int dest, int tag,
                               MPI_Comm comm, MPI_Request *request) ;
int MPIR_Sendrecv_cdesc(CFI_cdesc_t *sendbuf, int sendcount,
                        MPI_Datatype sendtype, int dest, int sendtag,
                        CFI_cdesc_t *recvbuf, int recvcount,
                        MPI_Datatype recvtype, int source, int recvtag,
                        MPI_Comm comm, MPI_Status *status) ;
int MPIR_Sendrecv_cdesc_large(CFI_cdesc_t *sendbuf, MPI_Count sendcount,
                              MPI_Datatype sendtype, int dest, int sendtag,
                              CFI_cdesc_t *recvbuf, MPI_Count recvcount,
                              MPI_Datatype recvtype, int source, int recvtag,
                              MPI_Comm comm, MPI_Status *status) ;
int MPIR_Sendrecv_replace_cdesc(CFI_cdesc_t *buf, int count,
                                MPI_Datatype datatype, int dest, int sendtag,
                                int source, int recvtag, MPI_Comm comm,
                                MPI_Status *status) ;
int MPIR_Sendrecv_replace_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                                      MPI_Datatype datatype, int dest,
                                      int sendtag, int source, int recvtag,
                                      MPI_Comm comm, MPI_Status *status) ;
int MPIR_Session_attach_buffer_cdesc(MPI_Session session, CFI_cdesc_t *buffer,
                                     int size) ;
int MPIR_Session_attach_buffer_cdesc_large(MPI_Session session,
                    CFI_cdesc_t *buffer, MPI_Count size) ;
int MPIR_Ssend_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                     int dest, int tag, MPI_Comm comm) ;
int MPIR_Ssend_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                           MPI_Datatype datatype, int dest, int tag,
                           MPI_Comm comm) ;
int MPIR_Ssend_init_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                          int dest, int tag, MPI_Comm comm,
                          MPI_Request *request) ;
int MPIR_Ssend_init_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                                MPI_Datatype datatype, int dest, int tag,
                                MPI_Comm comm, MPI_Request *request) ;
int MPIR_Accumulate_cdesc(CFI_cdesc_t *origin_addr, int origin_count,
                          MPI_Datatype origin_datatype, int target_rank,
                          MPI_Aint target_disp, int target_count,
                          MPI_Datatype target_datatype, MPI_Op op, MPI_Win win) ;
int MPIR_Accumulate_cdesc_large(CFI_cdesc_t *origin_addr,
                                MPI_Count origin_count,
                                MPI_Datatype origin_datatype, int target_rank,
                                MPI_Aint target_disp, MPI_Count target_count,
                                MPI_Datatype target_datatype, MPI_Op op,
                                MPI_Win win) ;
int MPIR_Compare_and_swap_cdesc(CFI_cdesc_t *origin_addr,
                                CFI_cdesc_t *compare_addr,
                                CFI_cdesc_t *result_addr, MPI_Datatype datatype,
                                int target_rank, MPI_Aint target_disp,
                                MPI_Win win) ;
int MPIR_Fetch_and_op_cdesc(CFI_cdesc_t *origin_addr, CFI_cdesc_t *result_addr,
                            MPI_Datatype datatype, int target_rank,
                            MPI_Aint target_disp, MPI_Op op, MPI_Win win) ;
int MPIR_Free_mem_cdesc(CFI_cdesc_t *base) ;
int MPIR_Get_cdesc(CFI_cdesc_t *origin_addr, int origin_count,
                   MPI_Datatype origin_datatype, int target_rank,
                   MPI_Aint target_disp, int target_count,
                   MPI_Datatype target_datatype, MPI_Win win) ;
int MPIR_Get_cdesc_large(CFI_cdesc_t *origin_addr, MPI_Count origin_count,
                         MPI_Datatype origin_datatype, int target_rank,
                         MPI_Aint target_disp, MPI_Count target_count,
                         MPI_Datatype target_datatype, MPI_Win win) ;
int MPIR_Get_accumulate_cdesc(CFI_cdesc_t *origin_addr, int origin_count,
                              MPI_Datatype origin_datatype,
                              CFI_cdesc_t *result_addr, int result_count,
                              MPI_Datatype result_datatype, int target_rank,
                              MPI_Aint target_disp, int target_count,
                              MPI_Datatype target_datatype, MPI_Op op,
                              MPI_Win win) ;
int MPIR_Get_accumulate_cdesc_large(CFI_cdesc_t *origin_addr,
                                    MPI_Count origin_count,
                                    MPI_Datatype origin_datatype,
                                    CFI_cdesc_t *result_addr,
                                    MPI_Count result_count,
                                    MPI_Datatype result_datatype,
                                    int target_rank, MPI_Aint target_disp,
                                    MPI_Count target_count,
                                    MPI_Datatype target_datatype, MPI_Op op,
                                    MPI_Win win) ;
int MPIR_Put_cdesc(CFI_cdesc_t *origin_addr, int origin_count,
                   MPI_Datatype origin_datatype, int target_rank,
                   MPI_Aint target_disp, int target_count,
                   MPI_Datatype target_datatype, MPI_Win win) ;
int MPIR_Put_cdesc_large(CFI_cdesc_t *origin_addr, MPI_Count origin_count,
                         MPI_Datatype origin_datatype, int target_rank,
                         MPI_Aint target_disp, MPI_Count target_count,
                         MPI_Datatype target_datatype, MPI_Win win) ;
int MPIR_Raccumulate_cdesc(CFI_cdesc_t *origin_addr, int origin_count,
                           MPI_Datatype origin_datatype, int target_rank,
                           MPI_Aint target_disp, int target_count,
                           MPI_Datatype target_datatype, MPI_Op op, MPI_Win win,
                           MPI_Request *request) ;
int MPIR_Raccumulate_cdesc_large(CFI_cdesc_t *origin_addr,
                                 MPI_Count origin_count,
                                 MPI_Datatype origin_datatype, int target_rank,
                                 MPI_Aint target_disp, MPI_Count target_count,
                                 MPI_Datatype target_datatype, MPI_Op op,
                                 MPI_Win win, MPI_Request *request) ;
int MPIR_Rget_cdesc(CFI_cdesc_t *origin_addr, int origin_count,
                    MPI_Datatype origin_datatype, int target_rank,
                    MPI_Aint target_disp, int target_count,
                    MPI_Datatype target_datatype, MPI_Win win,
                    MPI_Request *request) ;
int MPIR_Rget_cdesc_large(CFI_cdesc_t *origin_addr, MPI_Count origin_count,
                          MPI_Datatype origin_datatype, int target_rank,
                          MPI_Aint target_disp, MPI_Count target_count,
                          MPI_Datatype target_datatype, MPI_Win win,
                          MPI_Request *request) ;
int MPIR_Rget_accumulate_cdesc(CFI_cdesc_t *origin_addr, int origin_count,
                               MPI_Datatype origin_datatype,
                               CFI_cdesc_t *result_addr, int result_count,
                               MPI_Datatype result_datatype, int target_rank,
                               MPI_Aint target_disp, int target_count,
                               MPI_Datatype target_datatype, MPI_Op op,
                               MPI_Win win, MPI_Request *request) ;
int MPIR_Rget_accumulate_cdesc_large(CFI_cdesc_t *origin_addr,
                                     MPI_Count origin_count,
                                     MPI_Datatype origin_datatype,
                                     CFI_cdesc_t *result_addr,
                                     MPI_Count result_count,
                                     MPI_Datatype result_datatype,
                                     int target_rank, MPI_Aint target_disp,
                                     MPI_Count target_count,
                                     MPI_Datatype target_datatype, MPI_Op op,
                                     MPI_Win win, MPI_Request *request) ;
int MPIR_Rput_cdesc(CFI_cdesc_t *origin_addr, int origin_count,
                    MPI_Datatype origin_datatype, int target_rank,
                    MPI_Aint target_disp, int target_count,
                    MPI_Datatype target_datatype, MPI_Win win,
                    MPI_Request *request) ;
int MPIR_Rput_cdesc_large(CFI_cdesc_t *origin_addr, MPI_Count origin_count,
                          MPI_Datatype origin_datatype, int target_rank,
                          MPI_Aint target_disp, MPI_Count target_count,
                          MPI_Datatype target_datatype, MPI_Win win,
                          MPI_Request *request) ;
int MPIR_Win_attach_cdesc(MPI_Win win, CFI_cdesc_t *base, MPI_Aint size) ;
int MPIR_Win_create_cdesc(CFI_cdesc_t *base, MPI_Aint size, int disp_unit,
                          MPI_Info info, MPI_Comm comm, MPI_Win *win) ;
int MPIR_Win_create_cdesc_large(CFI_cdesc_t *base, MPI_Aint size,
                                MPI_Aint disp_unit, MPI_Info info,
                                MPI_Comm comm, MPI_Win *win) ;
int MPIR_Win_detach_cdesc(MPI_Win win, CFI_cdesc_t *base) ;
int MPIR_Stream_send_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                           int dest, int tag, MPI_Comm comm,
                           int source_stream_index, int dest_stream_index) ;
int MPIR_Stream_send_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                                 MPI_Datatype datatype, int dest, int tag,
                                 MPI_Comm comm, int source_stream_index,
                                 int dest_stream_index) ;
int MPIR_Stream_isend_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                            int dest, int tag, MPI_Comm comm,
                            int source_stream_index, int dest_stream_index,
                            MPI_Request *request) ;
int MPIR_Stream_isend_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                                  MPI_Datatype datatype, int dest, int tag,
                                  MPI_Comm comm, int source_stream_index,
                                  int dest_stream_index, MPI_Request *request) ;
int MPIR_Stream_recv_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                           int source, int tag, MPI_Comm comm,
                           int source_stream_index, int dest_stream_index,
                           MPI_Status *status) ;
int MPIR_Stream_recv_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                                 MPI_Datatype datatype, int source, int tag,
                                 MPI_Comm comm, int source_stream_index,
                                 int dest_stream_index, MPI_Status *status) ;
int MPIR_Stream_irecv_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                            int source, int tag, MPI_Comm comm,
                            int source_stream_index, int dest_stream_index,
                            MPI_Request *request) ;
int MPIR_Stream_irecv_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                                  MPI_Datatype datatype, int source, int tag,
                                  MPI_Comm comm, int source_stream_index,
                                  int dest_stream_index, MPI_Request *request) ;
int MPIR_Send_enqueue_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                            int dest, int tag, MPI_Comm comm) ;
int MPIR_Send_enqueue_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                                  MPI_Datatype datatype, int dest, int tag,
                                  MPI_Comm comm) ;
int MPIR_Recv_enqueue_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                            int source, int tag, MPI_Comm comm,
                            MPI_Status *status) ;
int MPIR_Recv_enqueue_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                                  MPI_Datatype datatype, int source, int tag,
                                  MPI_Comm comm, MPI_Status *status) ;
int MPIR_Isend_enqueue_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                             int dest, int tag, MPI_Comm comm,
                             MPI_Request *request) ;
int MPIR_Isend_enqueue_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                                   MPI_Datatype datatype, int dest, int tag,
                                   MPI_Comm comm, MPI_Request *request) ;
int MPIR_Irecv_enqueue_cdesc(CFI_cdesc_t *buf, int count, MPI_Datatype datatype,
                             int source, int tag, MPI_Comm comm,
                             MPI_Request *request) ;
int MPIR_Irecv_enqueue_cdesc_large(CFI_cdesc_t *buf, MPI_Count count,
                                   MPI_Datatype datatype, int source, int tag,
                                   MPI_Comm comm, MPI_Request *request) ;
int MPIR_Allreduce_enqueue_cdesc(CFI_cdesc_t *sendbuf, CFI_cdesc_t *recvbuf,
                                 int count, MPI_Datatype datatype, MPI_Op op,
                                 MPI_Comm comm) ;
int MPIR_Allreduce_enqueue_cdesc_large(CFI_cdesc_t *sendbuf,
                                       CFI_cdesc_t *recvbuf, MPI_Count count,
                                       MPI_Datatype datatype, MPI_Op op,
                                       MPI_Comm comm) ;
int MPIR_File_iread_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                          MPI_Datatype datatype, MPI_Request *request) ;
int MPIR_File_iread_cdesc_large(MPI_File fh, CFI_cdesc_t *buf, MPI_Count count,
                                MPI_Datatype datatype, MPI_Request *request) ;
int MPIR_File_iread_all_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                              MPI_Datatype datatype, MPI_Request *request) ;
int MPIR_File_iread_all_cdesc_large(MPI_File fh, CFI_cdesc_t *buf,
                                    MPI_Count count, MPI_Datatype datatype,
                                    MPI_Request *request) ;
int MPIR_File_iread_at_cdesc(MPI_File fh, MPI_Offset offset, CFI_cdesc_t *buf,
                             int count, MPI_Datatype datatype,
                             MPI_Request *request) ;
int MPIR_File_iread_at_cdesc_large(MPI_File fh, MPI_Offset offset,
                                   CFI_cdesc_t *buf, MPI_Count count,
                                   MPI_Datatype datatype, MPI_Request *request) ;
int MPIR_File_iread_at_all_cdesc(MPI_File fh, MPI_Offset offset,
                                 CFI_cdesc_t *buf, int count,
                                 MPI_Datatype datatype, MPI_Request *request) ;
int MPIR_File_iread_at_all_cdesc_large(MPI_File fh, MPI_Offset offset,
                                       CFI_cdesc_t *buf, MPI_Count count,
                                       MPI_Datatype datatype,
                                       MPI_Request *request) ;
int MPIR_File_iread_shared_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                                 MPI_Datatype datatype, MPI_Request *request) ;
int MPIR_File_iread_shared_cdesc_large(MPI_File fh, CFI_cdesc_t *buf,
                                       MPI_Count count, MPI_Datatype datatype,
                                       MPI_Request *request) ;
int MPIR_File_iwrite_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                           MPI_Datatype datatype, MPI_Request *request) ;
int MPIR_File_iwrite_cdesc_large(MPI_File fh, CFI_cdesc_t *buf, MPI_Count count,
                                 MPI_Datatype datatype, MPI_Request *request) ;
int MPIR_File_iwrite_all_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                               MPI_Datatype datatype, MPI_Request *request) ;
int MPIR_File_iwrite_all_cdesc_large(MPI_File fh, CFI_cdesc_t *buf,
                                     MPI_Count count, MPI_Datatype datatype,
                                     MPI_Request *request) ;
int MPIR_File_iwrite_at_cdesc(MPI_File fh, MPI_Offset offset, CFI_cdesc_t *buf,
                              int count, MPI_Datatype datatype,
                              MPI_Request *request) ;
int MPIR_File_iwrite_at_cdesc_large(MPI_File fh, MPI_Offset offset,
                                    CFI_cdesc_t *buf, MPI_Count count,
                                    MPI_Datatype datatype,
                                    MPI_Request *request) ;
int MPIR_File_iwrite_at_all_cdesc(MPI_File fh, MPI_Offset offset,
                                  CFI_cdesc_t *buf, int count,
                                  MPI_Datatype datatype, MPI_Request *request) ;
int MPIR_File_iwrite_at_all_cdesc_large(MPI_File fh, MPI_Offset offset,
                                        CFI_cdesc_t *buf, MPI_Count count,
                                        MPI_Datatype datatype,
                                        MPI_Request *request) ;
int MPIR_File_iwrite_shared_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                                  MPI_Datatype datatype, MPI_Request *request) ;
int MPIR_File_iwrite_shared_cdesc_large(MPI_File fh, CFI_cdesc_t *buf,
                                        MPI_Count count, MPI_Datatype datatype,
                                        MPI_Request *request) ;
int MPIR_File_read_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                         MPI_Datatype datatype, MPI_Status *status) ;
int MPIR_File_read_cdesc_large(MPI_File fh, CFI_cdesc_t *buf, MPI_Count count,
                               MPI_Datatype datatype, MPI_Status *status) ;
int MPIR_File_read_all_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                             MPI_Datatype datatype, MPI_Status *status) ;
int MPIR_File_read_all_cdesc_large(MPI_File fh, CFI_cdesc_t *buf,
                                   MPI_Count count, MPI_Datatype datatype,
                                   MPI_Status *status) ;
int MPIR_File_read_all_begin_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                                   MPI_Datatype datatype) ;
int MPIR_File_read_all_begin_cdesc_large(MPI_File fh, CFI_cdesc_t *buf,
                    MPI_Count count, MPI_Datatype datatype) ;
int MPIR_File_read_all_end_cdesc(MPI_File fh, CFI_cdesc_t *buf,
                                 MPI_Status *status) ;
int MPIR_File_read_at_cdesc(MPI_File fh, MPI_Offset offset, CFI_cdesc_t *buf,
                            int count, MPI_Datatype datatype,
                            MPI_Status *status) ;
int MPIR_File_read_at_cdesc_large(MPI_File fh, MPI_Offset offset,
                                  CFI_cdesc_t *buf, MPI_Count count,
                                  MPI_Datatype datatype, MPI_Status *status) ;
int MPIR_File_read_at_all_cdesc(MPI_File fh, MPI_Offset offset,
                                CFI_cdesc_t *buf, int count,
                                MPI_Datatype datatype, MPI_Status *status) ;
int MPIR_File_read_at_all_cdesc_large(MPI_File fh, MPI_Offset offset,
                                      CFI_cdesc_t *buf, MPI_Count count,
                                      MPI_Datatype datatype,
                                      MPI_Status *status) ;
int MPIR_File_read_at_all_begin_cdesc(MPI_File fh, MPI_Offset offset,
                                      CFI_cdesc_t *buf, int count,
                                      MPI_Datatype datatype) ;
int MPIR_File_read_at_all_begin_cdesc_large(MPI_File fh, MPI_Offset offset,
                    CFI_cdesc_t *buf, MPI_Count count, MPI_Datatype datatype) ;
int MPIR_File_read_at_all_end_cdesc(MPI_File fh, CFI_cdesc_t *buf,
                                    MPI_Status *status) ;
int MPIR_File_read_ordered_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                                 MPI_Datatype datatype, MPI_Status *status) ;
int MPIR_File_read_ordered_cdesc_large(MPI_File fh, CFI_cdesc_t *buf,
                                       MPI_Count count, MPI_Datatype datatype,
                                       MPI_Status *status) ;
int MPIR_File_read_ordered_begin_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                                       MPI_Datatype datatype) ;
int MPIR_File_read_ordered_begin_cdesc_large(MPI_File fh, CFI_cdesc_t *buf,
                    MPI_Count count, MPI_Datatype datatype) ;
int MPIR_File_read_ordered_end_cdesc(MPI_File fh, CFI_cdesc_t *buf,
                                     MPI_Status *status) ;
int MPIR_File_read_shared_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                                MPI_Datatype datatype, MPI_Status *status) ;
int MPIR_File_read_shared_cdesc_large(MPI_File fh, CFI_cdesc_t *buf,
                                      MPI_Count count, MPI_Datatype datatype,
                                      MPI_Status *status) ;
int MPIR_File_write_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                          MPI_Datatype datatype, MPI_Status *status) ;
int MPIR_File_write_cdesc_large(MPI_File fh, CFI_cdesc_t *buf, MPI_Count count,
                                MPI_Datatype datatype, MPI_Status *status) ;
int MPIR_File_write_all_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                              MPI_Datatype datatype, MPI_Status *status) ;
int MPIR_File_write_all_cdesc_large(MPI_File fh, CFI_cdesc_t *buf,
                                    MPI_Count count, MPI_Datatype datatype,
                                    MPI_Status *status) ;
int MPIR_File_write_all_begin_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                                    MPI_Datatype datatype) ;
int MPIR_File_write_all_begin_cdesc_large(MPI_File fh, CFI_cdesc_t *buf,
                    MPI_Count count, MPI_Datatype datatype) ;
int MPIR_File_write_all_end_cdesc(MPI_File fh, CFI_cdesc_t *buf,
                                  MPI_Status *status) ;
int MPIR_File_write_at_cdesc(MPI_File fh, MPI_Offset offset, CFI_cdesc_t *buf,
                             int count, MPI_Datatype datatype,
                             MPI_Status *status) ;
int MPIR_File_write_at_cdesc_large(MPI_File fh, MPI_Offset offset,
                                   CFI_cdesc_t *buf, MPI_Count count,
                                   MPI_Datatype datatype, MPI_Status *status) ;
int MPIR_File_write_at_all_cdesc(MPI_File fh, MPI_Offset offset,
                                 CFI_cdesc_t *buf, int count,
                                 MPI_Datatype datatype, MPI_Status *status) ;
int MPIR_File_write_at_all_cdesc_large(MPI_File fh, MPI_Offset offset,
                                       CFI_cdesc_t *buf, MPI_Count count,
                                       MPI_Datatype datatype,
                                       MPI_Status *status) ;
int MPIR_File_write_at_all_begin_cdesc(MPI_File fh, MPI_Offset offset,
                                       CFI_cdesc_t *buf, int count,
                                       MPI_Datatype datatype) ;
int MPIR_File_write_at_all_begin_cdesc_large(MPI_File fh, MPI_Offset offset,
                    CFI_cdesc_t *buf, MPI_Count count, MPI_Datatype datatype) ;
int MPIR_File_write_at_all_end_cdesc(MPI_File fh, CFI_cdesc_t *buf,
                                     MPI_Status *status) ;
int MPIR_File_write_ordered_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                                  MPI_Datatype datatype, MPI_Status *status) ;
int MPIR_File_write_ordered_cdesc_large(MPI_File fh, CFI_cdesc_t *buf,
                                        MPI_Count count, MPI_Datatype datatype,
                                        MPI_Status *status) ;
int MPIR_File_write_ordered_begin_cdesc(MPI_File fh, CFI_cdesc_t *buf,
                                        int count, MPI_Datatype datatype) ;
int MPIR_File_write_ordered_begin_cdesc_large(MPI_File fh, CFI_cdesc_t *buf,
                    MPI_Count count, MPI_Datatype datatype) ;
int MPIR_File_write_ordered_end_cdesc(MPI_File fh, CFI_cdesc_t *buf,
                                      MPI_Status *status) ;
int MPIR_File_write_shared_cdesc(MPI_File fh, CFI_cdesc_t *buf, int count,
                                 MPI_Datatype datatype, MPI_Status *status) ;
int MPIR_File_write_shared_cdesc_large(MPI_File fh, CFI_cdesc_t *buf,
                                       MPI_Count count, MPI_Datatype datatype,
                                       MPI_Status *status) ;
int MPIR_F_sync_reg_cdesc(CFI_cdesc_t *buf) ;
