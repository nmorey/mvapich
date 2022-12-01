/* -*- Mode: C; c-basic-offset:4 ; -*- */
/* Copyright (c) 2001-2022, The Ohio State University. All rights
 * reserved.
 *
 * This file is part of the MVAPICH2 software package developed by the
 * team members of The Ohio State University's Network-Based Computing
 * Laboratory (NBCL), headed by Professor Dhabaleswar K. (DK) Panda.
 *
 * For detailed copyright and licensing information, please refer to the
 * copyright file COPYRIGHT in the top level MVAPICH2 directory.
 */
/*
 *
 *  (C) 2001 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

#include "mpiimpl.h"
#include "mv2_coll_shmem.h"
#include "mv2_common_tuning.h"
#include "alltoallv_tuning.h"

int (*MV2_Alltoallv_function) (const void *sendbuf,
                             const int *sendcnts,
                             const int *sdispls,
                             MPI_Datatype sendtype,
                             void *recvbuf,
                             const int *recvcnts,
                             const int *rdispls,
                             MPI_Datatype recvtype,
                             MPIR_Comm * comm_ptr, MPIR_Errflag_t *errflag)=NULL;

/* This is the default implementation of alltoallv. The algorithm is:
   
   Algorithm: MPI_Alltoallv

   Since each process sends/receives different amounts of data to
   every other process, we don't know the total message size for all
   processes without additional communication. Therefore we simply use
   the "middle of the road" isend/irecv algorithm that works
   reasonably well in all cases.

   We post all irecvs and isends and then do a waitall. We scatter the
   order of sources and destinations among the processes, so that all
   processes don't try to send/recv to/from the same process at the
   same time. 

   Possible improvements: 

   End Algorithm: MPI_Alltoallv
*/

int MPIR_Alltoallv_intra_MV2(const void *sendbuf,
                             const int *sendcnts,
                             const int *sdispls,
                             MPI_Datatype sendtype,
                             void *recvbuf,
                             const int *recvcnts,
                             const int *rdispls,
                             MPI_Datatype recvtype,
                             MPIR_Comm * comm_ptr, MPIR_Errflag_t *errflag)
{
    MPIR_TIMER_START(coll,alltoallv,intra);
    MPIR_T_PVAR_COUNTER_INC(MV2, mv2_coll_alltoallv_intra, 1);
    int comm_size, i, j;
    MPI_Aint send_extent, recv_extent;
    int mpi_errno = MPI_SUCCESS;
    int mpi_errno_ret = MPI_SUCCESS;
    int dst, rank;

    int pof2, src;
    MPI_Status status;

    comm_size = comm_ptr->local_size;
    rank = comm_ptr->rank;

    /* Get extent of send and recv types */
    MPIR_Datatype_get_extent_macro(sendtype, send_extent);
    MPIR_Datatype_get_extent_macro(recvtype, recv_extent);

    if (sendbuf == MPI_IN_PLACE) {
        /* We use pair-wise sendrecv_replace in order to conserve memory usage,
         * which is keeping with the spirit of the MPI-2.2 Standard.  But
         * because of this approach all processes must agree on the global
         * schedule of sendrecv_replace operations to avoid deadlock.
         *
         * Note that this is not an especially efficient algorithm in terms of
         * time and there will be multiple repeated malloc/free's rather than
         * maintaining a single buffer across the whole loop.  Something like
         * MADRE is probably the best solution for the MPI_IN_PLACE scenario. */
        for (i = 0; i < comm_size; ++i) {
            /* start inner loop at i to avoid re-exchanging data */
            for (j = i; j < comm_size; ++j) {
                if (rank == i) {
                    /* also covers the (rank == i && rank == j) case */
                    MPIR_PVAR_INC(alltoallv, intra, send, recvcnts[j], recvtype);
                    MPIR_PVAR_INC(alltoallv, intra, recv, recvcnts[j], recvtype);
                    mpi_errno =
                        MPIC_Sendrecv_replace(((char *) recvbuf +
                                                  rdispls[j] * recv_extent),
                                                 recvcnts[j], recvtype, j,
                                                 MPIR_ALLTOALL_TAG, j,
                                                 MPIR_ALLTOALL_TAG, comm_ptr,
                                                 &status, errflag);
                    if (mpi_errno) {
                        /* for communication errors, just record the error but
                         * continue */
                        *errflag = MPIR_ERR_GET_CLASS(mpi_errno);
                        MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
                        MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
                    }
                } else if (rank == j) {
                    /* same as above with i/j args reversed */
                    MPIR_PVAR_INC(alltoallv, intra, send, recvcnts[j], recvtype);
                    MPIR_PVAR_INC(alltoallv, intra, recv, recvcnts[j], recvtype);
                    mpi_errno =
                        MPIC_Sendrecv_replace(((char *) recvbuf +
                                                  rdispls[i] * recv_extent),
                                                 recvcnts[i], recvtype, i,
                                                 MPIR_ALLTOALL_TAG, i,
                                                 MPIR_ALLTOALL_TAG, comm_ptr,
                                                 &status, errflag);
                    if (mpi_errno) {
                        /* for communication errors, just record the error but
                         * continue */
                        *errflag = MPIR_ERR_GET_CLASS(mpi_errno);
                        MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
                        MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
                    }
                }
            }
        }
    } else if (mv2_use_scatter_dest_alltoallv) {
        mpi_errno = MPIR_Alltoallv_intra_scatter_MV2(sendbuf,
                             sendcnts,
                             sdispls,
                             sendtype,
                             recvbuf,
                             recvcnts,
                             rdispls,
                             recvtype,
                             comm_ptr, errflag);
    } else {
        mpi_errno = MPIR_Localcopy(((char *) sendbuf +
                                    sdispls[rank] * send_extent),
                                   sendcnts[rank], sendtype,
                                   ((char *) recvbuf +
                                    rdispls[rank] * recv_extent),
                                   recvcnts[rank], recvtype);

        if (mpi_errno) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**fail", 0);
            return mpi_errno;
        }

        /* Is comm_size a power-of-two? */
        pof2 = comm_ptr->dev.ch.is_pof2;

        /* Do the pairwise exchanges */
        for (i = 1; i < comm_size; i++) {
            if (pof2 == 1) {
                /* use exclusive-or algorithm */
                src = dst = rank ^ i;
            } else {
                src = (rank - i + comm_size) % comm_size;
                dst = (rank + i) % comm_size;
            }
            MPIR_PVAR_INC(alltoallv, intra, send, sendcnts[dst], sendtype);
            MPIR_PVAR_INC(alltoallv, intra, recv, recvcnts[src], recvtype);
            mpi_errno = MPIC_Sendrecv(((char *) sendbuf +
                                          sdispls[dst] * send_extent),
                                         sendcnts[dst], sendtype, dst,
                                         MPIR_ALLTOALL_TAG,
                                         ((char *) recvbuf +
                                          rdispls[src] * recv_extent),
                                         recvcnts[src], recvtype, src,
                                         MPIR_ALLTOALL_TAG, comm_ptr, &status,
                                         errflag);
            if (mpi_errno) {
                /* for communication errors, just record the error but
                 * continue */
                *errflag = MPIR_ERR_GET_CLASS(mpi_errno);
                MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
                MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
            }

        }
    }
  fn_exit:
    MPIR_TIMER_END(coll, alltoallv, intra);
    return (mpi_errno);

  fn_fail:
    goto fn_exit;
}

/* end:nested */

int MPIR_Alltoallv_MV2(const void *sendbuf,
                             const int *sendcnts,
                             const int *sdispls,
                             MPI_Datatype sendtype,
                             void *recvbuf,
                             const int *recvcnts,
                             const int *rdispls,
                             MPI_Datatype recvtype,
                             MPIR_Comm * comm_ptr, MPIR_Errflag_t *errflag)
{
    int mpi_errno = MPI_SUCCESS;

    if (mv2_use_indexed_tuning || mv2_use_indexed_alltoallv_tuning) {
        mpi_errno = MPIR_Alltoallv_index_tuned_intra_MV2(sendbuf, sendcnts, sdispls, sendtype, recvbuf, recvcnts, rdispls, recvtype, comm_ptr, errflag);
    }
    else {
        mpi_errno = MPIR_Alltoallv_intra_MV2(sendbuf, sendcnts, sdispls, sendtype, recvbuf, recvcnts, rdispls, recvtype, comm_ptr, errflag);
    }

    MPIR_ERR_CHECK(mpi_errno);

  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Alltoallv_index_tuned_intra_MV2(const void *sendbuf,
                             const int *sendcnts,
                             const int *sdispls,
                             MPI_Datatype sendtype,
                             void *recvbuf,
                             const int *recvcnts,
                             const int *rdispls,
                             MPI_Datatype recvtype,
                             MPIR_Comm * comm_ptr, MPIR_Errflag_t *errflag)
{
    int mpi_errno=MPI_SUCCESS;
    int partial_sub_ok = 0;
    int conf_index = 0;
    int local_size = -1;
    int comm_size_index = 0;
    int inter_node_algo_index = 0;
    int table_min_comm_size = 0;
    int table_max_comm_size = 0;
    int lp2ltn; // largest power of 2 less than n
    MPI_Comm shmem_comm;
    MPIR_Comm *shmem_commptr=NULL;
    int comm_size = comm_ptr->local_size;

    if (mv2_alltoallv_indexed_table_ppn_conf[0] == -1) {
        /* Indicating user defined tuning */
        conf_index = 0;
        goto conf_check_end;
    }

    if (likely(mv2_enable_skip_tuning_table_search)) {
        /* Force scatter dest algo */
        MV2_Alltoallv_function = MPIR_Alltoallv_intra_scatter_MV2;
        goto skip_tuning_tables;
    }

    /* check if safe to use partial subscription mode */
    if (comm_ptr->dev.ch.shmem_coll_ok == 1 && comm_ptr->dev.ch.is_uniform) {
    
        shmem_comm = comm_ptr->dev.ch.shmem_comm;
        MPIR_Comm_get_ptr(shmem_comm, shmem_commptr);
        local_size = shmem_commptr->local_size;
        FIND_PPN_INDEX  (alltoallv, local_size,conf_index, partial_sub_ok)
    }
    
    if (partial_sub_ok != 1) {
        conf_index = mv2_alltoallv_indexed_num_ppn_conf/2;
    }
    
conf_check_end:

    /* Search for the corresponding system size inside the tuning table */
    /*
     * Comm sizes progress in powers of 2. Therefore comm_size can just be indexed instead
     */
    table_min_comm_size = mv2_alltoallv_indexed_thresholds_table[conf_index][0].numproc;
    table_max_comm_size =
	mv2_alltoallv_indexed_thresholds_table[conf_index][mv2_size_alltoallv_indexed_tuning_table[conf_index] - 1].numproc;
    
    if (comm_size < table_min_comm_size) {
        /* Comm size smaller than smallest configuration in table: use smallest available */
        comm_size_index = 0;
    } else if (comm_size > table_max_comm_size) {
        /* Comm size larger than largest configuration in table: use largest available */
        comm_size_index = mv2_size_alltoallv_indexed_tuning_table[conf_index] - 1;
    } else {
        /* Comm size in between smallest and largest configuration: find closest match */
        if (comm_ptr->dev.ch.is_pof2) {
            comm_size_index = log2( comm_size / table_min_comm_size );
        } else {
            lp2ltn = pow(2, (int)log2(comm_size));
            comm_size_index = (lp2ltn < table_min_comm_size) ? 0 : log2( lp2ltn / table_min_comm_size );
        }
    }

    inter_node_algo_index = 0;

    MV2_Alltoallv_function = mv2_alltoallv_indexed_thresholds_table[conf_index][comm_size_index].algo_table[inter_node_algo_index]
        .MV2_pt_Alltoallv_function;

skip_tuning_tables:
    mpi_errno = MV2_Alltoallv_function(sendbuf, sendcnts, sdispls, sendtype, recvbuf, recvcnts, rdispls, recvtype, comm_ptr, errflag );
    return (mpi_errno);
}
