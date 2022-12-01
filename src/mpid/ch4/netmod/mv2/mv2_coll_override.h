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

/* Collective overloads for the CH4 device in MV2. Placed here as it applies to
 * all CH4 netmods
 *
 * These collectives are implemented at the MPIR layer, but we are wrapping them
 * here at the MPIDI layer to overload the netmod defaults.
 *
 * Note that most nonblocking collectives have been dropped from our overloads
 * as they are obsolete and use the deprecated sched algorithms. We do maintain
 * the collectives for which sharp support exists.
 */

#ifndef MV2_COLL_OVERRIDE_H
#define MV2_COLL_OVERRIDE_H

#ifdef _OSU_COLLECTIVES_
/* 
 * override select ofi/ucx collectives
 *
 * this is not a clean method but it's a start
 */
#include "mv2_mpir.h"

/* 
 * probably need to include a ch4_shmem_coll.h file to disable 
 * most of our channel specific shmem colls 
 */

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

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_MV2_mpi_barrier(MPIR_Comm *comm, MPIR_Errflag_t *errflag)
{
    int mpi_errno = MPI_SUCCESS;
    if (mv2_use_osu_collectives &&
        comm->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        mpi_errno = MPIR_Barrier_MV2(comm, errflag);
    } else {
        mpi_errno = MPIR_Barrier_impl(comm, errflag);
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
  fn_fail: 
    return mpi_errno;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_MV2_mpi_bcast(void *buffer, int count,
                                  MPI_Datatype datatype, int root,
                                  MPIR_Comm *comm, MPIR_Errflag_t *errflag)
{
    int mpi_errno = MPI_SUCCESS;
    if (mv2_use_osu_collectives &&
        comm->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        mpi_errno = MPIR_Bcast_MV2(buffer, count, datatype, root,
                                        comm, errflag);
    } else {
        mpi_errno = MPIR_Bcast_impl(buffer, count, datatype, root, 
                                    comm, errflag);
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
  fn_fail: 
    return mpi_errno;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_MV2_mpi_allreduce(const void *sendbuf, void *recvbuf,
                                                        int count, MPI_Datatype datatype,
                                                        MPI_Op op, MPIR_Comm *comm, 
                                                        MPIR_Errflag_t *errflag)
{
    int mpi_errno = 0;
    if (mv2_use_osu_collectives &&
        comm->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        mpi_errno = MPIR_Allreduce_MV2(sendbuf, recvbuf, count, datatype, op,
                                       comm, errflag);
        MPIR_ERR_CHECK(mpi_errno);
    } else {
        mpi_errno = MPIR_Allreduce_impl(sendbuf, recvbuf, count, datatype, op,
                                        comm, errflag);
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
  fn_fail: 
    return mpi_errno;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_MV2_mpi_allgather(const void *sendbuf, int sendcount,
                                      MPI_Datatype sendtype, void *recvbuf,
                                      int recvcount, MPI_Datatype recvtype,
                                      MPIR_Comm *comm, MPIR_Errflag_t *errflag)
{
    if (mv2_use_osu_collectives &&
        comm->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        return MPIR_Allgather_MV2(sendbuf, sendcount, sendtype, recvbuf,
                                recvcount, recvtype, comm, errflag);
    }
    return MPIR_Allgather_impl(sendbuf, sendcount, sendtype, recvbuf,
                                    recvcount, recvtype, comm, errflag);
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_MV2_mpi_allgatherv(const void *sendbuf, int sendcount,
                                       MPI_Datatype sendtype, void *recvbuf,
                                       const int *recvcounts, const int *displs,
                                       MPI_Datatype recvtype, MPIR_Comm *comm,
                                       MPIR_Errflag_t *errflag)
{
    if (mv2_use_osu_collectives &&
        comm->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        return MPIR_Allgatherv_MV2(sendbuf, sendcount, sendtype, recvbuf,
                                   recvcounts, displs, recvtype, comm,
                                   errflag);
    } 
    return MPIR_Allgatherv_impl(sendbuf, sendcount, sendtype, recvbuf,
                                 recvcounts, displs, recvtype, comm,
                                 errflag);
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_MV2_mpi_scatter(const void *sendbuf, int sendcount,
                                    MPI_Datatype sendtype, void *recvbuf,
                                    int recvcount, MPI_Datatype recvtype,
                                    int root, MPIR_Comm *comm,
                                    MPIR_Errflag_t *errflag)
{
    int mpi_errno = MPI_SUCCESS;
    if (mv2_use_osu_collectives &&
        comm->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        mpi_errno = MPIR_Scatter_MV2(sendbuf, sendcount, sendtype, recvbuf,
                                     recvcount, recvtype, root, comm, errflag);
        MPIR_ERR_CHECK(mpi_errno);
    } else {
        mpi_errno = MPIR_Scatter_impl(sendbuf, sendcount, sendtype, recvbuf,
                                 recvcount, recvtype, root, comm, errflag);
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
  fn_fail: 
    return mpi_errno;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_MV2_mpi_scatterv(const void *sendbuf, const int *sendcounts,
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
  fn_fail: 
    return mpi_errno;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_MV2_mpi_gather(const void *sendbuf, int sendcount,
                                   MPI_Datatype sendtype, void *recvbuf,
                                   int recvcount, MPI_Datatype recvtype,
                                   int root, MPIR_Comm *comm,
                                   MPIR_Errflag_t *errflag)
{
    if (mv2_use_osu_collectives &&
        comm->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        return MPIR_Gather_MV2(sendbuf, sendcount, sendtype, recvbuf,
                               recvcount, recvtype, root, comm, errflag);
    }
    return MPIR_Gather_impl(sendbuf, sendcount, sendtype, recvbuf,
                            recvcount, recvtype, root, comm, errflag);
}

#if 0 /* Not implemented */
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_MV2_mpi_gatherv(const void *sendbuf, int sendcount,
                                    MPI_Datatype sendtype, void *recvbuf,
                                    const int *recvcounts, const int *displs,
                                    MPI_Datatype recvtype, int root,
                                    MPIR_Comm *comm, MPIR_Errflag_t *errflag)
{
    if (mv2_use_osu_collectives &&
        comm->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        return MPIR_Gatherv_MV2(sendbuf, sendcount, sendtype, recvbuf, 
                                recvcounts, displs, recvtype, root, comm,
                                errflag);
    }

    return MPIR_Gatherv_impl(sendbuf, sendcount, sendtype, recvbuf,
                             recvcounts, displs, recvtype, root, comm, errflag);

}
#endif

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_MV2_mpi_alltoall(const void *sendbuf, int sendcount,
                                     MPI_Datatype sendtype, void *recvbuf,
                                     int recvcount, MPI_Datatype recvtype,
                                     MPIR_Comm *comm, MPIR_Errflag_t *errflag)
{
    if (mv2_use_osu_collectives &&
        comm->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        return MPIR_Alltoall_MV2(sendbuf, sendcount, sendtype, recvbuf,
                                 recvcount, recvtype, comm, errflag);
    }

    return MPIR_Alltoall_impl(sendbuf, sendcount, sendtype, recvbuf,
                              recvcount, recvtype, comm, errflag);
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_MV2_mpi_alltoallv(const void *sendbuf,
                                      const int *sendcounts, const int *sdispls,
                                      MPI_Datatype sendtype, void *recvbuf,
                                      const int *recvcounts, const int *rdispls,
                                      MPI_Datatype recvtype, MPIR_Comm *comm,
                                      MPIR_Errflag_t *errflag)
{
    if (mv2_use_osu_collectives &&
        comm->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        return MPIR_Alltoallv_MV2(sendbuf, sendcounts, sdispls, sendtype,
                                  recvbuf, recvcounts, rdispls, recvtype,
                                  comm, errflag);
    }

    return MPIR_Alltoallv_impl(sendbuf, sendcounts, sdispls, sendtype,
                               recvbuf, recvcounts, rdispls, recvtype,
                               comm, errflag);
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_MV2_mpi_reduce(const void *sendbuf, void *recvbuf,
                                   int count, MPI_Datatype datatype,
                                   MPI_Op op, int root, MPIR_Comm *comm,
                                   MPIR_Errflag_t *errflag)
{
    int mpi_errno = MPI_SUCCESS;
    if (mv2_use_osu_collectives &&
        comm->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        mpi_errno = MPIR_Reduce_MV2(sendbuf, recvbuf, count, datatype, op, root,
                                    comm, errflag);
    } else {
        mpi_errno = MPIR_Reduce_impl(sendbuf, recvbuf, count, datatype, op,
                                     root, comm, errflag);
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
  fn_fail: 
    return mpi_errno;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_MV2_mpi_reduce_scatter(const void *sendbuf, void *recvbuf,
                                           const int recvcounts[],
                                           MPI_Datatype datatype, MPI_Op op,
                                           MPIR_Comm *comm,
                                           MPIR_Errflag_t *errflag)
{
    if (mv2_use_osu_collectives &&
        comm->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        return MPIR_Reduce_scatter_MV2(sendbuf, recvbuf, recvcounts, 
                                       datatype, op, comm, errflag);
    }

    return MPIR_Reduce_scatter_impl(sendbuf, recvbuf, recvcounts,
                                    datatype, op, comm, errflag);
}

#if 0 /* Not implemented */
MPL_STATIC_INLINE_PREFIX int MPIDI_NM_MV2_mpi_reduce_scatter_block(const void *sendbuf,
                                                 void *recvbuf, int recvcount,
                                                 MPI_Datatype datatype,
                                                 MPI_Op op, MPIR_Comm *comm,
                                                 MPIR_Errflag_t *errflag)
{
    if (mv2_use_osu_collectives &&
        comm->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        return MPIR_Reduce_scatter_block_MV2(sendbuf, recvbuf, recvcount,
                                             datatype, op, comm, 
                                             errflag);
    }

    return MPIR_Reduce_scatter_block_impl(sendbuf, recvbuf, recvcount,
                                          datatype, op, comm,
                                          errflag);
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_MV2_mpi_scan(const void *sendbuf, void *recvbuf, int count,
                                 MPI_Datatype datatype, MPI_Op op,
                                 MPIR_Comm *comm, MPIR_Errflag_t *errflag)
{
    if (mv2_use_osu_collectives &&
        comm->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        return MPIR_Scan_MV2(sendbuf, recvbuf, count, datatype, op,
                                        comm, errflag);
    }

    return MPIR_Scan_impl(sendbuf, recvbuf, count, datatype, op, comm,
                               errflag);
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_MV2_mpi_exscan(const void *sendbuf, void *recvbuf, int count,
                              MPI_Datatype datatype, MPI_Op op, MPIR_Comm *comm,
                              MPIR_Errflag_t *errflag)
{
    if (mv2_use_osu_collectives && 
        comm->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        return MPIR_Exscan_MV2(sendbuf, recvbuf, count, datatype, op,
                               comm, errflag);
    }

    return MPIR_Exscan_impl(sendbuf, recvbuf, count, datatype, op, comm,
                                 errflag);
}
#endif

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_MV2_mpi_iallreduce(const void *sendbuf, void *recvbuf, 
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
  fn_fail: 
    return mpi_errno;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_MV2_mpi_ibarrier(MPIR_Comm *comm, MPIR_Request **request)
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
  fn_fail: 
    return mpi_errno;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_MV2_mpi_ibcast(void *buffer, int count, 
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
  fn_fail: 
    return mpi_errno;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_NM_MV2_mpi_ireduce(const void *sendbuf,
                                                      void *recvbuf, int count, 
                                                      MPI_Datatype datatype,
                                                      MPI_Op op, int root,
                                                      MPIR_Comm *comm,
                                                      MPIR_Request **request)
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
  fn_fail: 
    return mpi_errno;
}

/* undefine the MPICH versions */
/* TODO-merge: this is kind of hacky, should find a better
 * way to override these while staying out of MPICH code */
#undef MPIDI_NM_mpi_barrier
#undef MPIDI_NM_mpi_bcast
#undef MPIDI_NM_mpi_allreduce
#undef MPIDI_NM_mpi_allgather
#undef MPIDI_NM_mpi_allgatherv
#undef MPIDI_NM_mpi_scatter
#undef MPIDI_NM_mpi_gather
#undef MPIDI_NM_mpi_gatherv
#undef MPIDI_NM_mpi_alltoall
#undef MPIDI_NM_mpi_alltoallV
#undef MPIDI_NM_mpi_reduce
#undef MPIDI_NM_mpi_reduce_scatter
#undef MPIDI_NM_mpi_reduce_scatter_block
#undef MPIDI_NM_mpi_scan
#undef MPIDI_NM_mpi_exscan
/* nonblocking collectives with SHARP support */
#undef MPIDI_NM_mpi_iallreduce
#undef MPIDI_NM_mpi_ibarrier
#undef MPIDI_NM_mpi_ibcast
#undef MPIDI_NM_mpi_ireduce

/* override functions with ours */
#define MPIDI_NM_mpi_barrier                MPIDI_NM_MV2_mpi_barrier
#define MPIDI_NM_mpi_bcast                  MPIDI_NM_MV2_mpi_bcast
#define MPIDI_NM_mpi_allreduce              MPIDI_NM_MV2_mpi_allreduce
#define MPIDI_NM_mpi_allgather              MPIDI_NM_MV2_mpi_allgather
#define MPIDI_NM_mpi_allgatherv             MPIDI_NM_MV2_mpi_allgatherv
#define MPIDI_NM_mpi_scatter                MPIDI_NM_MV2_mpi_scatter
#define MPIDI_NM_mpi_scatterv               MPIDI_NM_MV2_mpi_scatterv
#define MPIDI_NM_mpi_gather                 MPIDI_NM_MV2_mpi_gather
/* #define MPIDI_NM_mpi_gatherv                MPIDI_NM_MV2_mpi_gatherv */
#define MPIDI_NM_mpi_alltoall               MPIDI_NM_MV2_mpi_alltoall
#define MPIDI_NM_mpi_alltoallv              MPIDI_NM_MV2_mpi_alltoallv
#define MPIDI_NM_mpi_reduce                 MPIDI_NM_MV2_mpi_reduce
#define MPIDI_NM_mpi_reduce_scatter         MPIDI_NM_MV2_mpi_reduce_scatter
/* 
#define MPIDI_NM_mpi_reduce_scatter_block   MPIDI_NM_MV2_mpi_reduce_scatter_block
#define MPIDI_NM_mpi_scan                   MPIDI_NM_MV2_mpi_scan
#define MPIDI_NM_mpi_exscan                 MPIDI_NM_MV2_mpi_exscan
*/
/* nonblocking collectives with SHARP support */
#define MPIDI_NM_mpi_iallreduce             MPIDI_NM_MV2_mpi_iallreduce
#define MPIDI_NM_mpi_ibarrier               MPIDI_NM_MV2_mpi_ibarrier
#define MPIDI_NM_mpi_ibcast                 MPIDI_NM_MV2_mpi_ibcast
#define MPIDI_NM_mpi_ireduce                MPIDI_NM_MV2_mpi_ireduce

#endif /* defined(_OSU_COLLECTIVES_) */

#endif /* MV2_COLL_OVERRIDE_H */
