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

/* 
 * This file contains the MV2 extensions to the MPIR_ interface used by MPICH 
 * most of these formerly resided in mpiimpl.h but after MPICH refactored that
 * file it makes more sense to keep these in a seperate file. 
 */

#ifndef MV2_MPIR_H_INCLUDED
#define MV2_MPIR_H_INCLUDED


/*****************************************************************************/
/***************************** mv2_mpir_coll.h *******************************/
/*****************************************************************************/

/*
 * this section defines several collective related values used by MVAPICH2 
 * formerlly residing in mpiimpl.h 
 */

/* max no. of irecvs/isends posted at a 
time in some alltoall algorithms. Setting
it to 0 causes all irecvs/isends to be
posted at once. */
#define MPIR_ALLTOALL_THROTTLE        32
#define MPIR_ALLTOALL_INTRA_THROTTLE  32
#define MPIR_ALLTOALL_LARGE_MSG_THROTTLE  4
#define MV2_ALLTOALL_LARGE_MSG        64*1024

#define MPIR_BCAST_LONG_MSG           524288
#define MPIR_BCAST_MIN_PROCS          8

#ifdef _OSU_MVAPICH_
#define MPIR_ALLTOALL_SHORT_MSG         2048
#define MPIR_ALLTOALL_MEDIUM_MSG        16384
#define MPIR_ALLTOALL_SMALL_SYSTEM_SIZE 256
#define MPIR_BCAST_SHORT_MSG            16384
#define MPIR_BCAST_LARGE_MSG            512*1024
#else /* _OSU_MVAPICH_ */
#define MPIR_ALLTOALL_SHORT_MSG       8192
#define MPIR_ALLTOALL_MEDIUM_MSG      8192
#define MPIR_BCAST_SHORT_MSG          12288 
#endif /* _OSU_MVAPICH_ */
#define MPIR_ALLGATHER_SHORT_MSG      81920
#define MPIR_ALLGATHER_LONG_MSG       524288
#define MV2_ALLGATHER_SHORT_MSG       1024
#define MV2_ALLGATHER_LONG_MSG        1024
#define MPIR_REDUCE_SHORT_MSG         8192
#define MPIR_ALLREDUCE_SHORT_MSG      2048
#define MPIR_GATHER_VSMALL_MSG        1024
#define MPIR_SCATTER_SHORT_MSG        2048  /* for intercommunicator scatter */
#define MPIR_GATHER_SHORT_MSG         2048  /* for intercommunicator scatter */
#define MPIR_GATHERV_MIN_PROCS        32

#ifdef _OSU_MVAPICH_
#define SHMEM_ALLREDUCE_THRESHOLD (1<<15)
#define MPIR_ALLREDUCE_2LEVEL_THRESHOLD (1<<18)
#define SHMEM_REDUCE_THRESHOLD (1<<12)
#define SHMEM_INTRA_REDUCE_THRESHOLD (1<<11)
#define MPIR_REDUCE_2LEVEL_THRESHOLD (1<<14)

struct coll_runtime {
    int allgather_rd_threshold; 
    int allgather_bruck_threshold;
    int allreduce_short_msg;
    int allreduce_2level_threshold; 
    int reduce_short_msg;
    int reduce_2level_threshold;
    int shmem_allreduce_msg;
    int shmem_reduce_msg;
    int shmem_intra_reduce_msg;
    int alltoall_small_msg; 
    int alltoall_medium_msg; 
    int alltoall_throttle_factor;
    int alltoall_intra_throttle_factor;
    int alltoall_large_msg_throttle_factor;
};

int MPIR_Allgather_MV2(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                   void *recvbuf, int recvcount, MPI_Datatype recvtype,
                   MPIR_Comm *comm_ptr, MPIR_Errflag_t *errflag );
int MPIR_Allgatherv_MV2(const void *sendbuf, int sendcount, MPI_Datatype sendtype, 
                    void *recvbuf, const int *recvcounts, const int *displs,   
                    MPI_Datatype recvtype, MPIR_Comm *comm_ptr, MPIR_Errflag_t *errflag );
int MPIR_Allreduce_MV2(const void *sendbuf, void *recvbuf, int count, 
                   MPI_Datatype datatype, MPI_Op op, MPIR_Comm *comm_ptr, MPIR_Errflag_t *errflag);
int MPIR_Alltoall_MV2(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                  void *recvbuf, int recvcount, MPI_Datatype recvtype,
                  MPIR_Comm *comm_ptr, MPIR_Errflag_t *errflag);
int MPIR_Alltoallv_MV2(const void *sendbuf, const int *sendcnts, const int *sdispls, 
                         MPI_Datatype sendtype, void *recvbuf, const int *recvcnts, 
                         const int *rdispls, MPI_Datatype recvtype, MPIR_Comm *comm_ptr, MPIR_Errflag_t *errflag);
int MPIR_Alltoallv_intra_MV2(const void *sendbuf, const int *sendcnts, const int *sdispls, 
                         MPI_Datatype sendtype, void *recvbuf, const int *recvcnts, 
                         const int *rdispls, MPI_Datatype recvtype, MPIR_Comm *comm_ptr, MPIR_Errflag_t *errflag);
int MPIR_Bcast_MV2 (void *buffer, int count, MPI_Datatype datatype, int
                root, MPIR_Comm *comm_ptr, MPIR_Errflag_t *errflag);
int MPIR_Gather_MV2 (const void *sendbuf, int sendcnt, MPI_Datatype sendtype,
                 void *recvbuf, int recvcnt, MPI_Datatype recvtype,
                 int root, MPIR_Comm *comm_ptr, MPIR_Errflag_t *errflag);
int MPIR_Gatherv_MV2 (const void *sendbuf, int sendcnt, MPI_Datatype sendtype,
                      void *recvbuf, const int *recvcnts, const int *displs,
                      MPI_Datatype recvtype, int root, MPIR_Comm *comm_ptr, MPIR_Errflag_t *errflag);
int MPIR_Reduce_MV2(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype,
                MPI_Op op, int root, MPIR_Comm *comm_ptr, MPIR_Errflag_t *errflag );
int MPIR_Scatter_MV2(const void *sendbuf, int sendcnt, MPI_Datatype sendtype, 
                 void *recvbuf, int recvcnt, MPI_Datatype recvtype, 
                 int root, MPIR_Comm *comm_ptr, MPIR_Errflag_t *errflag );
int MPIR_Reduce_scatter_MV2(const void *sendbuf, void *recvbuf, const int *recvcnts, 
                              MPI_Datatype datatype, MPI_Op op, MPIR_Comm *comm_ptr, MPIR_Errflag_t *errflag);
int MPIR_Reduce_scatter_block_MV2(const void *sendbuf, void *recvbuf,
                                int recvcount, MPI_Datatype datatype,
                                MPI_Op op, MPIR_Comm *comm_ptr, MPIR_Errflag_t *errflag);
int MPIR_Scan_MV2(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype,
              MPI_Op op, MPIR_Comm *comm_ptr, MPIR_Errflag_t *errflag);
int MPIR_Exscan_MV2(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype,
                MPI_Op op, MPIR_Comm *comm_ptr, MPIR_Errflag_t *errflag);
int MPIR_Barrier_MV2( MPIR_Comm *comm_ptr, MPIR_Errflag_t *errflag);

/* we do not currently have support for our own NBC designs in ch4 
 * since they all relied on the deprecated scheduler algorithsm */
#if defined(CHANNEL_MRAIL)
int MPIR_Ibcast_MV2(void *buffer, int count, MPI_Datatype datatype, int root,
                    MPIR_Comm *comm_ptr, MPIR_Sched_t s);
int MPIR_Igather_MV2(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf,
                     int recvcount, MPI_Datatype recvtype, int root, MPIR_Comm *comm_ptr,
                     MPIR_Sched_t s);
int MPIR_Iscatter_binomial(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf,
                           int recvcount, MPI_Datatype recvtype, int root, MPIR_Comm *comm_ptr,
                           MPIR_Sched_t s);
int MPIR_Iscatter_MV2(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf,
                      int recvcount, MPI_Datatype recvtype, int root, MPIR_Comm *comm_ptr,
                      MPIR_Sched_t s);
int MPIR_Iallgather_MV2(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf,
                      int recvcount, MPI_Datatype recvtype, MPIR_Comm *comm_ptr, MPIR_Sched_t s);
int MPIR_Ireduce_MV2(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype,
                     MPI_Op op, int root, MPIR_Comm *comm_ptr, MPIR_Sched_t s);
int MPIR_Iallreduce_MV2(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype,
                        MPI_Op op, MPIR_Comm *comm_ptr, MPIR_Sched_t s);
int MPIR_Ireduce_scatter_MV2(const void *sendbuf, void *recvbuf, const int *recvcnts,
                               MPI_Datatype datatype, MPI_Op op, MPIR_Comm *comm_ptr,
                               MPIR_Sched_t s);
int MPIR_Ibarrier_MV2(MPIR_Comm *comm_ptr, MPIR_Sched_t s);
int MPIR_Ialltoall_MV2(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                       void *recvbuf, int recvcount, MPI_Datatype recvtype,
                       MPIR_Comm *comm_ptr, MPIR_Sched_t s);
int MPIR_Ialltoallv_MV2(const void *sendbuf, const int *sendcounts, const int *sdispls,
                        MPI_Datatype sendtype, void *recvbuf, const int *recvcounts,
                        const int *rdispls, MPI_Datatype recvtype, MPIR_Comm *comm_ptr, MPIR_Sched_t s);
int MPIR_Iallgatherv_MV2(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                           void *recvbuf, const int *recvcounts, const int *displs,
                           MPI_Datatype recvtype, MPIR_Comm *comm_ptr, MPIR_Sched_t s);
#endif /* CHANNEL_MRAIL */
#endif /* _OSU_MVAPICH_ */

/*****************************************************************************/
/*************************** mv2_mpir_contextid.h ****************************/
/*****************************************************************************/


/*****************************************************************************/
/****************************** mv2_mpir_mem.h *******************************/
/*****************************************************************************/

/*
 * This file defines the MVAPICH2 specific extentions of MPICH's MPIR memory
 * interface 
 */

#include <string.h>

#if defined(CHANNEL_MRAIL) || defined(_MV2_CH4_OVERRIDE_)

#if (!defined(NDEBUG) && defined(HAVE_ERROR_CHECKING))
/* May be used to perform sanity and range checking on memcpy and mempcy-like
   function calls.  This macro will bail out much like an MPIR_Assert if any of
   the checks fail. */
#define CHECK_MEMSET(dst_,c,len_)                           \
    do {                                                    \
        MPIR_Assert( len_ > 0);                             \
        MPL_VG_CHECK_MEM_IS_ADDRESSABLE((dst_),(len_));     \
    } while (0)
#else
#define CHECK_MEMSET(dst_,src_,len_) do {} while (0)
#endif /* (!defined(NDEBUG) && defined(HAVE_ERROR_CHECKING)) */

/* Overriding memset:
 *  Devices and channels can override the default implementation of
 *  MPIR_Memset by defining the MPID_Memset macro.  The implementation
 *  can call MPIR_Memset for the default memset implementation.     
 *  Note that MPIR_Memset returns void rather than a
 *  pointer to the destination buffer.  This is different from C89
 *  memset.
 */
#define MPIR_Memset(dst, c, len)            \
    do {                                    \
        CHECK_MEMSET((dst), (c), (len));    \
        memset((dst), (c), (len));          \
    } while (0)             

#endif /* defined(CHANNEL_MRAIL) or defined(_MV2_CH4_OVERRIDE_) */

/*****************************************************************************/
/***************************** mv2_mpir_request.h ****************************/
/*****************************************************************************/

/*
 * this section defines several collective related values used by MVAPICH2 
 * formerly residing in mpiimpl.h 
 */
/* MV2 dummy request builtin type */
#if 0
#define MPIR_MV2_REQUEST_DUMMY      (MPI_Request)0x6c000020
#undef MPIR_REQUEST_BUILTIN_COUNT  
#define MPIR_REQUEST_BUILTIN_COUNT  0x21
#endif

#endif /* MV2_MPIR_H_INCLUDED */
