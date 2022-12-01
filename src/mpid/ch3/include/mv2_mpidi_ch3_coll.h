/* Copyright (c) 2001-2021, The Ohio State University. All rights
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

/* Collective overloads for the CH3 device in MV2. Placed here as it applies to
 * both mrail and PSM. 
 *
 * These collectives are implemented at the MPIR layer, but we are wrapping them
 * here at the MPIDI layer to overload in MPID_coll.h
 *
 * Note that all nonblocking collectives have been dropped from our overloads as
 * they are obsolete and use the deprecated sched algorithms. 
 */

#ifndef MPIDI_MV2_CH3_COLL_INCLUDED
#define MPIDI_MV2_CH3_COLL_INCLUDED

#include "mv2_mpir.h"

extern int mv2_use_osu_collectives;
extern int shmem_coll_count_threshold;
#if defined(_MCST_SUPPORT_)
extern int mv2_use_mcast_scatter;
#endif /*  #if defined(_MCST_SUPPORT_) */
int mv2_increment_shmem_coll_counter(MPIR_Comm *comm_ptr);
int mv2_increment_allgather_coll_counter(MPIR_Comm *comm_ptr);
int disable_split_comm(pthread_t);
int enable_split_comm(pthread_t);
#if defined(_MCST_SUPPORT_)
int create_mcast_comm(MPI_Comm comm, int size, int my_rank);
#endif /* defined(_MCST_SUPPORT_) */

static inline int MPIDI_MV2_Barrier(MPIR_Comm *comm, MPIR_Errflag_t *errflag)
{
    int mpi_errno = MPI_SUCCESS;
#ifdef _OSU_COLLECTIVES_
    if (mv2_use_osu_collectives &&
        comm->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        mpi_errno = MPIR_Barrier_MV2(comm, errflag);
    } else {
#endif
        mpi_errno = MPIR_Barrier_impl(comm, errflag);
#ifdef _OSU_COLLECTIVES_
    }
    if (mv2_use_osu_collectives) {
        mpi_errno = mv2_increment_shmem_coll_counter(comm);
        MPIR_ERR_CHECK(mpi_errno);
        if(comm->dev.ch.allgather_comm_ok == 0) {
            mpi_errno = mv2_increment_allgather_coll_counter(comm);
            MPIR_ERR_CHECK(mpi_errno);
        }
#if defined(_SHARP_SUPPORT_)
        comm->dev.ch.barrier_coll_count++;
        if (mv2_enable_sharp_coll &&
            mv2_enable_sharp_barrier &&
            (comm->dev.ch.is_sharp_ok == 0) &&
            (comm->dev.ch.shmem_coll_ok == 1) &&
            (comm->dev.ch.barrier_coll_count >= shmem_coll_count_threshold)) { 
            disable_split_comm(pthread_self());
            mpi_errno = create_sharp_comm(comm->handle, comm->local_size, comm->rank);
            MPIR_ERR_CHECk(mpi_errno);
            enable_split_comm(pthread_self());
        }
#endif /*(_SHARP_SUPPORT_)*/
    }
#endif /* _OSU_COLLECTIVES_ */
  fn_fail: 
    return mpi_errno;
}

static inline int MPIDI_MV2_Bcast(void *buffer, int count,
                                  MPI_Datatype datatype, int root,
                                  MPIR_Comm *comm, MPIR_Errflag_t *errflag)
{
    int mpi_errno = MPI_SUCCESS;
#ifdef _OSU_COLLECTIVES_
    if (mv2_use_osu_collectives &&
        comm->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        mpi_errno = MPIR_Bcast_MV2(buffer, count, datatype, root,
                                        comm, errflag);
    } else {
#endif
        mpi_errno = MPIR_Bcast_impl(buffer, count, datatype, root, 
                                    comm, errflag);
#ifdef _OSU_COLLECTIVES_
    }
    if (mv2_use_osu_collectives) {
        mpi_errno = mv2_increment_shmem_coll_counter(comm);
        MPIR_ERR_CHECK(mpi_errno);
        if(comm->dev.ch.allgather_comm_ok == 0) {
            mpi_errno = mv2_increment_allgather_coll_counter(comm);
            MPIR_ERR_CHECK(mpi_errno);
        }
#if defined(_SHARP_SUPPORT_)
        comm->dev.ch.bcast_coll_count++;
        if (mv2_enable_sharp_coll &&
            mv2_enable_sharp_bcast &&
            (comm->dev.ch.is_sharp_ok == 0) &&
            (comm->dev.ch.shmem_coll_ok == 1) &&
            (comm->dev.ch.bcast_coll_count >= shmem_coll_count_threshold)) { 
            disable_split_comm(pthread_self());
            mpi_errno = create_sharp_comm(comm->handle, comm->local_size, comm->rank);
            MPIR_ERR_CHECk(mpi_errno);
            enable_split_comm(pthread_self());
        }
#endif /*(_SHARP_SUPPORT_)*/
    }
#endif /* _OSU_COLLECTIVES_ */
  fn_fail: 
    return mpi_errno;
}

static inline int MPIDI_MV2_Allreduce(const void *sendbuf, void *recvbuf,
                                      int count, MPI_Datatype datatype,
                                      MPI_Op op, MPIR_Comm *comm, 
                                      MPIR_Errflag_t *errflag)
{
    int mpi_errno = 0;
#ifdef _OSU_COLLECTIVES_
    if (mv2_use_osu_collectives &&
        comm->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        mpi_errno = MPIR_Allreduce_MV2(sendbuf, recvbuf, count, datatype, op,
                                       comm, errflag);
        MPIR_ERR_CHECK(mpi_errno);
    } else {
#endif
        mpi_errno = MPIR_Allreduce_impl(sendbuf, recvbuf, count, datatype, op,
                                        comm, errflag);
#ifdef _OSU_COLLECTIVES_
    }
    if (mv2_use_osu_collectives) {
        mpi_errno = mv2_increment_shmem_coll_counter(comm);
        MPIR_ERR_CHECK(mpi_errno);
        if(comm->dev.ch.allgather_comm_ok == 0) {
            mpi_errno = mv2_increment_allgather_coll_counter(comm);
            MPIR_ERR_CHECK(mpi_errno);
        }
#if defined(_SHARP_SUPPORT_)
        comm->dev.ch.allreduce_coll_count++;
        if (mv2_enable_sharp_coll &&
            mv2_enable_sharp_allreduce &&
            (comm->dev.ch.is_sharp_ok == 0) &&
            (comm->dev.ch.shmem_coll_ok == 1) &&
            (comm->dev.ch.allreduce_coll_count >= shmem_coll_count_threshold)) { 
            disable_split_comm(pthread_self());
            mpi_errno = create_sharp_comm(comm->handle, comm->local_size, comm->rank);
            MPIR_ERR_CHECk(mpi_errno);
            enable_split_comm(pthread_self());
        }
#endif /*(_SHARP_SUPPORT_)*/
    }
#endif /* _OSU_COLLECTIVES_ */
  fn_fail: 
    return mpi_errno;
}

static inline int MPIDI_MV2_Allgather(const void *sendbuf, int sendcount,
                                      MPI_Datatype sendtype, void *recvbuf,
                                      int recvcount, MPI_Datatype recvtype,
                                      MPIR_Comm *comm, MPIR_Errflag_t *errflag)
{
#ifdef _OSU_COLLECTIVES_
    if (mv2_use_osu_collectives &&
        comm->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        return MPIR_Allgather_MV2(sendbuf, sendcount, sendtype, recvbuf,
                                recvcount, recvtype, comm, errflag);
    }
#endif
    return MPIR_Allgather_impl(sendbuf, sendcount, sendtype, recvbuf,
                                    recvcount, recvtype, comm, errflag);
}

static inline int MPIDI_MV2_Allgatherv(const void *sendbuf, int sendcount,
                                       MPI_Datatype sendtype, void *recvbuf,
                                       const int *recvcounts, const int *displs,
                                       MPI_Datatype recvtype, MPIR_Comm *comm,
                                       MPIR_Errflag_t *errflag)
{
#ifdef _OSU_COLLECTIVES_
    if (mv2_use_osu_collectives &&
        comm->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        return MPIR_Allgatherv_MV2(sendbuf, sendcount, sendtype, recvbuf,
                                   recvcounts, displs, recvtype, comm,
                                   errflag);
    } 
#endif
    return MPIR_Allgatherv_impl(sendbuf, sendcount, sendtype, recvbuf,
                                 recvcounts, displs, recvtype, comm,
                                 errflag);
}

static inline int MPIDI_MV2_Scatter(const void *sendbuf, int sendcount,
                                    MPI_Datatype sendtype, void *recvbuf,
                                    int recvcount, MPI_Datatype recvtype,
                                    int root, MPIR_Comm *comm,
                                    MPIR_Errflag_t *errflag)
{
    int mpi_errno = MPI_SUCCESS;
#ifdef _OSU_COLLECTIVES_
    if (mv2_use_osu_collectives &&
        comm->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        mpi_errno = MPIR_Scatter_MV2(sendbuf, sendcount, sendtype, recvbuf,
                                     recvcount, recvtype, root, comm, errflag);
        MPIR_ERR_CHECK(mpi_errno);
    } else {
#endif
        mpi_errno = MPIR_Scatter_impl(sendbuf, sendcount, sendtype, recvbuf,
                                 recvcount, recvtype, root, comm, errflag);
#ifdef _OSU_COLLECTIVES_
    }
    if (mv2_use_osu_collectives) {
        if (comm->dev.ch.shmem_coll_ok == 0) {
            mpi_errno = mv2_increment_shmem_coll_counter(comm);
            MPIR_ERR_CHECK(mpi_errno);
        }
#if defined(_SHARP_SUPPORT_)
        comm->dev.ch.scatter_coll_count++;
        if (mv2_enable_sharp_coll &&
            mv2_enable_sharp_scatter &&
            (comm->dev.ch.is_sharp_ok == 0) &&
            (comm->dev.ch.shmem_coll_ok == 1) &&
            (comm->dev.ch.scatter_coll_count >= 
                            shmem_coll_count_threshold)) {
            disable_split_comm(pthread_self());
            mpi_errno = create_sharp_comm(comm->handle, 
                                          comm->local_size, comm->rank);
            MPIR_ERR_CHECK(mpi_errno);
            enable_split_comm(pthread_self());
        }
#endif /*(_SHARP_SUPPORT_)*/
#if defined(_MCST_SUPPORT_)
        if (rdma_enable_mcast && mv2_use_mcast_scatter &&
            (comm->dev.ch.is_mcast_ok == 0) &&
            (comm->dev.ch.shmem_coll_ok == 1) &&
            (comm->dev.ch.scatter_coll_count >= shmem_coll_count_threshold)) {
            disable_split_comm(pthread_self());
            mpi_errno = create_mcast_comm(comm->handle, comm->local_size, comm->rank);
            MPIR_ERR_CHECK(mpi_errno);
            enable_split_comm(pthread_self());
        }
#endif /*(_MCST_SUPPORT_)*/
    }
#endif /* _OSU_COLLECTIVES_ */
  fn_fail: 
    return mpi_errno;
}

static inline int MPIDI_MV2_Scatterv(const void *sendbuf, const int *sendcounts,
                                     const int *displs, MPI_Datatype sendtype,
                                     void *recvbuf, int recvcount,
                                     MPI_Datatype recvtype, int root,
                                     MPIR_Comm *comm,
                                     MPIR_Errflag_t *errflag)
{
    int mpi_errno = MPI_SUCCESS;
#if defined (_SHARP_SUPPORT_)
    if (comm->dev.ch.is_sharp_ok == 1 && 
            mv2_enable_sharp_coll == 1 &&
            mv2_enable_sharp_scatterv) {
        mpi_errno = MPIR_Sharp_Scatterv_MV2(sendbuf, sendcounts, displs,
                                            sendtype, recvbuf, recvcount,
                                            recvtype, root, comm, errflag);
        /* Direct flat algorithm in which every process calls Sharp
         * MV2_ENABLE_SHARP should be set to 1 */
        if (mpi_errno == MPI_SUCCESS) {
            goto cont_sharp;
        }
        /* SHARP collective is not supported,
        * continue without using SHARP */
    }
#endif /* end of defined (_SHARP_SUPPORT_) */

    mpi_errno = MPIR_Scatterv_impl(sendbuf, sendcounts, displs,
                                   sendtype, recvbuf, recvcount,
                                   recvtype, root, comm, errflag);

#ifdef _OSU_COLLECTIVES_
#if defined(_SHARP_SUPPORT_)
  cont_sharp:
#endif /* defined(_SHARP_SUPPORT_) */
    if (mv2_use_osu_collectives) {
        if (comm->dev.ch.shmem_coll_ok == 0) {
            mpi_errno = mv2_increment_shmem_coll_counter(comm);
            MPIR_ERR_CHECK(mpi_errno);
        }
#if defined(_SHARP_SUPPORT_)
        comm->dev.ch.scatterv_coll_count++;
        if (mv2_enable_sharp_coll &&
            mv2_enable_sharp_scatterv &&
            (comm->dev.ch.is_sharp_ok == 0) &&
            (comm->dev.ch.shmem_coll_ok == 1) &&
            (comm->dev.ch.scatterv_coll_count >= 
                            shmem_coll_count_threshold)) {
            disable_split_comm(pthread_self());
            mpi_errno = create_sharp_comm(comm->handle, 
                                          comm->local_size, comm->rank);
            MPIR_ERR_CHECK(mpi_errno);
            enable_split_comm(pthread_self());
        }
#endif /*(_SHARP_SUPPORT_)*/
    }
#endif /* _OSU_COLLECTIVES_ */
  fn_fail: 
    return mpi_errno;
}

static inline int MPIDI_MV2_Gather(const void *sendbuf, int sendcount,
                                   MPI_Datatype sendtype, void *recvbuf,
                                   int recvcount, MPI_Datatype recvtype,
                                   int root, MPIR_Comm *comm,
                                   MPIR_Errflag_t *errflag)
{
#ifdef _OSU_COLLECTIVES_
    if (mv2_use_osu_collectives &&
        comm->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        return MPIR_Gather_MV2(sendbuf, sendcount, sendtype, recvbuf,
                               recvcount, recvtype, root, comm, errflag);
    }
#endif
    return MPIR_Gather_impl(sendbuf, sendcount, sendtype, recvbuf,
                            recvcount, recvtype, root, comm, errflag);
}

static inline int MPIDI_MV2_Gatherv(const void *sendbuf, int sendcount,
                                    MPI_Datatype sendtype, void *recvbuf,
                                    const int *recvcounts, const int *displs,
                                    MPI_Datatype recvtype, int root,
                                    MPIR_Comm *comm, MPIR_Errflag_t *errflag)
{
#ifdef _OSU_COLLECTIVES_
    if (mv2_use_osu_collectives &&
        comm->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        return MPIR_Gatherv_MV2(sendbuf, sendcount, sendtype, recvbuf, 
                                recvcounts, displs, recvtype, root, comm,
                                errflag);
    }
#endif

    return MPIR_Gatherv_impl(sendbuf, sendcount, sendtype, recvbuf,
                             recvcounts, displs, recvtype, root, comm, errflag);

}

static inline int MPIDI_MV2_Alltoall(const void *sendbuf, int sendcount,
                                     MPI_Datatype sendtype, void *recvbuf,
                                     int recvcount, MPI_Datatype recvtype,
                                     MPIR_Comm *comm, MPIR_Errflag_t *errflag)
{
#ifdef _OSU_COLLECTIVES_
    if (mv2_use_osu_collectives &&
        comm->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        return MPIR_Alltoall_MV2(sendbuf, sendcount, sendtype, recvbuf,
                                 recvcount, recvtype, comm, errflag);
    }
#endif

    return MPIR_Alltoall_impl(sendbuf, sendcount, sendtype, recvbuf,
                              recvcount, recvtype, comm, errflag);
}

static inline int MPIDI_MV2_Alltoallv(const void *sendbuf,
                                      const int *sendcounts, const int *sdispls,
                                      MPI_Datatype sendtype, void *recvbuf,
                                      const int *recvcounts, const int *rdispls,
                                      MPI_Datatype recvtype, MPIR_Comm *comm,
                                      MPIR_Errflag_t *errflag)
{
#ifdef _OSU_COLLECTIVES_
    if (mv2_use_osu_collectives &&
        comm->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        return MPIR_Alltoallv_MV2(sendbuf, sendcounts, sdispls, sendtype,
                                  recvbuf, recvcounts, rdispls, recvtype,
                                  comm, errflag);
    }
#endif

    return MPIR_Alltoallv_impl(sendbuf, sendcounts, sdispls, sendtype,
                               recvbuf, recvcounts, rdispls, recvtype,
                               comm, errflag);
}

static inline int MPIDI_MV2_Reduce(const void *sendbuf, void *recvbuf,
                                   int count, MPI_Datatype datatype,
                                   MPI_Op op, int root, MPIR_Comm *comm,
                                   MPIR_Errflag_t *errflag)
{
    int mpi_errno = MPI_SUCCESS;
#ifdef _OSU_COLLECTIVES_
    if (mv2_use_osu_collectives &&
        comm->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        mpi_errno = MPIR_Reduce_MV2(sendbuf, recvbuf, count, datatype, op, root,
                                    comm, errflag);
    } else {
#endif
        mpi_errno = MPIR_Reduce_impl(sendbuf, recvbuf, count, datatype, op,
                                     root, comm, errflag);
#ifdef _OSU_COLLECTIVES_
    }
    if (mv2_use_osu_collectives) {
        if (comm->dev.ch.shmem_coll_ok == 0) {
            mpi_errno = mv2_increment_shmem_coll_counter(comm);
            MPIR_ERR_CHECK(mpi_errno);
        }
#if defined(_SHARP_SUPPORT_)
        comm->dev.ch.reduce_coll_count++;
        if (mv2_enable_sharp_coll &&
            mv2_enable_sharp_reduce &&
            (comm->dev.ch.is_sharp_ok == 0) &&
            (comm->dev.ch.shmem_coll_ok == 1) &&
            (comm->dev.ch.reduce_coll_count >= 
                            shmem_coll_count_threshold)) {
            disable_split_comm(pthread_self());
            mpi_errno = create_sharp_comm(comm->handle, 
                                          comm->local_size, comm->rank);
            MPIR_ERR_CHECK(mpi_errno);
            enable_split_comm(pthread_self());
        }
#endif /* (_SHARP_SUPPORT_) */
    }
#endif /* _OSU_COLLECTIVES_ */
  fn_fail: 
    return mpi_errno;
}

static inline int MPIDI_MV2_Reduce_scatter(const void *sendbuf, void *recvbuf,
                                           const int recvcounts[],
                                           MPI_Datatype datatype, MPI_Op op,
                                           MPIR_Comm *comm,
                                           MPIR_Errflag_t *errflag)
{
#ifdef _OSU_COLLECTIVES_
    if (mv2_use_osu_collectives &&
        comm->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        return MPIR_Reduce_scatter_MV2(sendbuf, recvbuf, recvcounts, 
                                       datatype, op, comm, errflag);
    }
#endif

    return MPIR_Reduce_scatter_impl(sendbuf, recvbuf, recvcounts,
                                    datatype, op, comm, errflag);
}

static inline int MPIDI_MV2_Reduce_scatter_block(const void *sendbuf,
                                                 void *recvbuf, int recvcount,
                                                 MPI_Datatype datatype,
                                                 MPI_Op op, MPIR_Comm *comm,
                                                 MPIR_Errflag_t *errflag)
{
#ifdef _OSU_COLLECTIVES_
    if (mv2_use_osu_collectives &&
        comm->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        return MPIR_Reduce_scatter_block_MV2(sendbuf, recvbuf, recvcount,
                                             datatype, op, comm, 
                                             errflag);
    }
#endif

    return MPIR_Reduce_scatter_block_impl(sendbuf, recvbuf, recvcount,
                                          datatype, op, comm,
                                          errflag);
}

static inline int MPIDI_MV2_Scan(const void *sendbuf, void *recvbuf, int count,
                                 MPI_Datatype datatype, MPI_Op op,
                                 MPIR_Comm *comm, MPIR_Errflag_t *errflag)
{
#ifdef _OSU_COLLECTIVES_
    if (mv2_use_osu_collectives &&
        comm->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        return MPIR_Scan_MV2(sendbuf, recvbuf, count, datatype, op,
                                        comm, errflag);
    }
#endif

    return MPIR_Scan_impl(sendbuf, recvbuf, count, datatype, op, comm,
                               errflag);
}

static inline int MPIDI_MV2_Exscan(const void *sendbuf, void *recvbuf, int count,
                              MPI_Datatype datatype, MPI_Op op, MPIR_Comm *comm,
                              MPIR_Errflag_t *errflag)
{
#ifdef _OSU_COLLECTIVES_
    if (mv2_use_osu_collectives && 
        comm->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        return MPIR_Exscan_MV2(sendbuf, recvbuf, count, datatype, op,
                               comm, errflag);
    }
#endif

    return MPIR_Exscan_impl(sendbuf, recvbuf, count, datatype, op, comm,
                                 errflag);
}

static inline int MPIDI_MV2_Iallreduce(const void *sendbuf, void *recvbuf, 
                                       int count, MPI_Datatype datatype, 
                                       MPI_Op op, MPIR_Comm *comm,
                                       MPIR_Request **request)
{
    int mpi_errno = MPI_SUCCESS;
#if defined (_SHARP_SUPPORT_)
    if (comm->dev.ch.is_sharp_ok == 1 && 
        count <= mv2_sharp_tuned_msg_size / 4 && 
        mv2_enable_sharp_coll == 2) {
        /* Direct flat algorithm in which every process calls Sharp
        *  MV2_ENABLE_SHARP should be set to 2 */
        mpi_errno = MPIR_Sharp_Iallreduce_MV2(sendbuf, recvbuf, count,
                                              datatype, op, comm, NULL,
                                              request);
        if (mpi_errno == MPI_SUCCESS) {
            goto cont_sharp;
        }
        /* SHARP collective is not supported,
        * continue without using SHARP */
    }
#endif /* end of defined (_SHARP_SUPPORT_) */

    mpi_errno = MPIR_Iallreduce_impl(sendbuf, recvbuf, count, datatype, op, 
                                     comm, request);
#ifdef _OSU_COLLECTIVES_
#if defined(_SHARP_SUPPORT_)
  cont_sharp:
#endif /* defined(_SHARP_SUPPORT_) */
    if (mv2_use_osu_collectives) {
        if (comm->dev.ch.shmem_coll_ok == 0) {
            mpi_errno = mv2_increment_shmem_coll_counter(comm);
            MPIR_ERR_CHECK(mpi_errno);
        }
#if defined(_SHARP_SUPPORT_)
        comm->dev.ch.iallreduce_coll_count++;
        if (mv2_enable_sharp_coll &&
            mv2_enable_sharp_iallreduce &&
            (comm->dev.ch.is_sharp_ok == 0) &&
            (comm->dev.ch.shmem_coll_ok == 1) &&
            (comm->dev.ch.iallreduce_coll_count >= 
                            shmem_coll_count_threshold)) {
            disable_split_comm(pthread_self());
            mpi_errno = create_sharp_comm(comm->handle, 
                                          comm->local_size, comm->rank);
            MPIR_ERR_CHECK(mpi_errno);
            enable_split_comm(pthread_self());
        }
#endif /*(_SHARP_SUPPORT_)*/
    }
#endif /* _OSU_COLLECTIVES_ */
  fn_fail: 
    return mpi_errno;
}

static inline int MPIDI_MV2_Ibarrier(MPIR_Comm *comm, MPIR_Request **request)
{
    int mpi_errno = MPI_SUCCESS;
#if defined (_SHARP_SUPPORT_)
    if (comm->dev.ch.is_sharp_ok == 1 && mv2_enable_sharp_coll == 2) {
        mpi_errno = MPIR_Sharp_Ibarrier_MV2(comm, NULL, request);
        if (mpi_errno == MPI_SUCCESS) {
            goto cont_sharp;
        }
        /* SHARP collective is not supported,
        * continue without using SHARP */
    }
#endif /* end of defined (_SHARP_SUPPORT_) */

    mpi_errno = MPIR_Ibarrier_impl(comm, request);

#ifdef _OSU_COLLECTIVES_
#if defined(_SHARP_SUPPORT_)
  cont_sharp:
#endif /* defined(_SHARP_SUPPORT_) */
    if (mv2_use_osu_collectives) {
        if (comm->dev.ch.shmem_coll_ok == 0) {
            mpi_errno = mv2_increment_shmem_coll_counter(comm);
            MPIR_ERR_CHECK(mpi_errno);
        }
#if defined(_SHARP_SUPPORT_)
        comm->dev.ch.ibarrier_coll_count++;
        if (mv2_enable_sharp_coll &&
            mv2_enable_sharp_ibarrier &&
            (comm->dev.ch.is_sharp_ok == 0) &&
            (comm->dev.ch.shmem_coll_ok == 1) &&
            (comm->dev.ch.ibarrier_coll_count >= 
                            shmem_coll_count_threshold)) {
            disable_split_comm(pthread_self());
            mpi_errno = create_sharp_comm(comm->handle, 
                                          comm->local_size, comm->rank);
            MPIR_ERR_CHECK(mpi_errno);
            enable_split_comm(pthread_self());
        }
#endif /*(_SHARP_SUPPORT_)*/
    }
#endif /* _OSU_COLLECTIVES_ */
  fn_fail: 
    return mpi_errno;
}

static inline int MPIDI_MV2_Ibcast(void *buffer, int count, 
                                   MPI_Datatype datatype, int root,
                                   MPIR_Comm *comm, MPIR_Request **request)
{
    int mpi_errno = MPI_SUCCESS;
#if defined (_SHARP_SUPPORT_)
    if (comm->dev.ch.is_sharp_ok == 1 && 
        count <= mv2_sharp_tuned_msg_size / 4 && 
        mv2_enable_sharp_coll == 2) {
        mpi_errno = MPIR_Sharp_Ibcast_MV2(buffer, count, datatype, root, comm,
                                          NULL, request);
        /* Direct flat algorithm in which every process calls Sharp
         * MV2_ENABLE_SHARP should be set to 2 */
        if (mpi_errno == MPI_SUCCESS) {
            goto cont_sharp;
        }
        /* SHARP collective is not supported,
        * continue without using SHARP */
    }
#endif /* end of defined (_SHARP_SUPPORT_) */

    mpi_errno = MPIR_Ibcast_impl(buffer, count, datatype, root, comm, request);

#ifdef _OSU_COLLECTIVES_
#if defined(_SHARP_SUPPORT_)
  cont_sharp:
#endif /* defined(_SHARP_SUPPORT_) */
    if (mv2_use_osu_collectives) {
        if (comm->dev.ch.shmem_coll_ok == 0) {
            mpi_errno = mv2_increment_shmem_coll_counter(comm);
            MPIR_ERR_CHECK(mpi_errno);
        }
#if defined(_SHARP_SUPPORT_)
        comm->dev.ch.ibcast_coll_count++;
        if (mv2_enable_sharp_coll &&
            mv2_enable_sharp_ibcast &&
            (comm->dev.ch.is_sharp_ok == 0) &&
            (comm->dev.ch.shmem_coll_ok == 1) &&
            (comm->dev.ch.ibcast_coll_count >= 
                            shmem_coll_count_threshold)) {
            disable_split_comm(pthread_self());
            mpi_errno = create_sharp_comm(comm->handle, 
                                          comm->local_size, comm->rank);
            MPIR_ERR_CHECK(mpi_errno);
            enable_split_comm(pthread_self());
        }
#endif /*(_SHARP_SUPPORT_)*/
    }
#endif /* _OSU_COLLECTIVES_ */
  fn_fail: 
    return mpi_errno;
}

static inline int MPIDI_MV2_Ireduce(void *sendbuf, void *recvbuf, int count, 
                                    MPI_Datatype datatype, MPI_Op op, int root,
                                    MPIR_Comm *comm, MPIR_Request **request)
{
    int mpi_errno = MPI_SUCCESS;
#if defined (_SHARP_SUPPORT_)
    if (comm->dev.ch.is_sharp_ok == 1 && 
        count <= mv2_sharp_tuned_msg_size / 4 && 
        mv2_enable_sharp_coll == 2) {
        mpi_errno = MPIR_Sharp_Ireduce_MV2(sendbuf, recvbuf, count, datatype,
                                           op, root, comm, NULL, request);
        /* Direct flat algorithm in which every process calls Sharp
         * MV2_ENABLE_SHARP should be set to 2 */
        if (mpi_errno == MPI_SUCCESS) {
            goto cont_sharp;
        }
        /* SHARP collective is not supported,
        * continue without using SHARP */
    }
#endif /* end of defined (_SHARP_SUPPORT_) */

    mpi_errno = MPIR_Ireduce_impl(sendbuf, recvbuf, count, datatype, op, root,
                                  comm, request);

#ifdef _OSU_COLLECTIVES_
#if defined(_SHARP_SUPPORT_)
  cont_sharp:
#endif /* defined(_SHARP_SUPPORT_) */
    if (mv2_use_osu_collectives) {
        if (comm->dev.ch.shmem_coll_ok == 0) {
            mpi_errno = mv2_increment_shmem_coll_counter(comm);
            MPIR_ERR_CHECK(mpi_errno);
        }
#if defined(_SHARP_SUPPORT_)
        comm->dev.ch.ireduce_coll_count++;
        if (mv2_enable_sharp_coll &&
            mv2_enable_sharp_ireduce &&
            (comm->dev.ch.is_sharp_ok == 0) &&
            (comm->dev.ch.shmem_coll_ok == 1) &&
            (comm->dev.ch.ireduce_coll_count >= 
                            shmem_coll_count_threshold)) {
            disable_split_comm(pthread_self());
            mpi_errno = create_sharp_comm(comm->handle, 
                                          comm->local_size, comm->rank);
            MPIR_ERR_CHECK(mpi_errno);
            enable_split_comm(pthread_self());
        }
#endif /*(_SHARP_SUPPORT_)*/
    }
#endif /* _OSU_COLLECTIVES_ */
  fn_fail: 
    return mpi_errno;
}

/* undefine the MPICH versions */
/* TODO-merge: this is kind of hacky, should find a better
 * way to override these while staying out of MPICH code */
#undef MPID_Barrier
#undef MPID_Bcast
#undef MPID_Allreduce
#undef MPID_Allgather
#undef MPID_Allgatherv
#undef MPID_Scatter
#undef MPID_Gather
#undef MPID_Gatherv
#undef MPID_Alltoall
#undef MPID_AlltoallV
#undef MPID_Reduce
#undef MPID_Reduce_scatter
#undef MPID_Reduce_scatter_block
#undef MPID_Scan
#undef MPID_Exscan
/* nonblocking collectives with SHARP support */
#undef MPID_Iallreduce
#undef MPID_Ibarrier
#undef MPID_Ibcast
#undef MPID_Ireduce

/* override functions with ours */
#define MPID_Barrier                MPIDI_MV2_Barrier
#define MPID_Bcast                  MPIDI_MV2_Bcast
#define MPID_Allreduce              MPIDI_MV2_Allreduce
#define MPID_Allgather              MPIDI_MV2_Allgather
#define MPID_Allgatherv             MPIDI_MV2_Allgatherv
#define MPID_Scatter                MPIDI_MV2_Scatter
#define MPID_Scatterv               MPIDI_MV2_Scatterv
#define MPID_Gather                 MPIDI_MV2_Gather
#define MPID_Gatherv                MPIDI_MV2_Gatherv
#define MPID_Alltoall               MPIDI_MV2_Alltoall
#define MPID_AlltoallV              MPIDI_MV2_AlltoallV
#define MPID_Reduce                 MPIDI_MV2_Reduce
#define MPID_Reduce_scatter         MPIDI_MV2_Reduce_scatter
#define MPID_Reduce_scatter_block   MPIDI_MV2_Reduce_scatter_block
#define MPID_Scan                   MPIDI_MV2_Scan
#define MPID_Exscan                 MPIDI_MV2_Exscan
/* nonblocking collectives with SHARP support */
#define MPID_Iallreduce             MPIDI_MV2_Iallreduce
#define MPID_Ibarrier               MPIDI_MV2_Ibarrier
#define MPID_Ibcast                 MPIDI_MV2_Ibcast
#define MPID_Ireduce                MPIDI_MV2_Ireduce

#endif /* MPIDI_MV2_CH3_COLL_INCLUDED */
