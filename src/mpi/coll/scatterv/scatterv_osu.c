/*
 *
 *  (C) 2001 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */
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

#include "mpiimpl.h"
#include "helper_fns.h"
#include "coll_shmem.h"
#if defined (_SHARP_SUPPORT_)
#include "api/sharp_coll.h"
#include "ibv_sharp.h"
extern int mv2_sharp_tuned_msg_size;
#endif

#if defined (_SHARP_SUPPORT_)
int MPIR_Sharp_Scatterv_MV2(const void *sendbuf, const int *sendcounts,
                            const int *displs, MPI_Datatype sendtype,
                            void *recvbuf, int recvcount,
                            MPI_Datatype recvtype, int root,
                            MPIR_Comm *comm_ptr, MPIR_Errflag_t *errflag)
{
    int mpi_errno = MPI_SUCCESS;
    MPI_Aint type_size = 0;
    /* Get size of data */
    MPIR_Datatype_get_size_macro(sendtype, type_size);
    intptr_t nbytes;
    int rank = comm_ptr->rank;
    int size = comm_ptr->local_size;
    void *buffer = NULL;
    int copy_offset;
    int total_count = 0;
    int i;
    int nonroot_displs[size];
 
    i = type_size * recvcount * size;
    if (i >= mv2_coll_tmp_buf_size) {
        mpi_errno = MPI_ERR_NO_MEM;
        PRINT_DEBUG(DEBUG_Sharp_verbose, "coll_tmp_buf out of mem (%d), "
                                         "need %d, continue without SHARP\n",
                                         mv2_coll_tmp_buf_size, i);
        MPIR_ERR_SETANDJUMP2(mpi_errno, MPI_ERR_INTERN, "**sharpcoll", 
                            "coll_tmp_buf out of mem (%d), need %d, "
                            "continue without SHARP", mv2_coll_tmp_buf_size,
                            i);
    }

    buffer = (void *)comm_ptr->dev.ch.coll_tmp_buf;
    if (rank == root) {
        for (i = 0; i < size; i++) {
            total_count += sendcounts[i];
            ((int *)buffer)[i] = displs[i];
        }
        ((int *)buffer)[size] = total_count; 
    }

    mpi_errno = MPIR_Bcast_MV2(buffer, size + 1, MPI_INT, root, comm_ptr,
                               errflag);
    if (mpi_errno) {
         MPIR_ERR_SETANDJUMP(mpi_errno, MPI_ERR_INTERN, "**sharpcoll");
    }

    if (rank != root) {
        for (i = 0; i < size; i++) {
            nonroot_displs[i] = ((int *)buffer)[i];
        }
        total_count = ((int *)buffer)[size];
    }   
  
    nbytes = (intptr_t)(total_count) * (type_size);

    if (rank == root) {
        buffer = (void *)sendbuf;
    } else {
        buffer = (void *)comm_ptr->dev.ch.coll_tmp_buf;
    }

    mpi_errno = MPIR_Sharp_Bcast_MV2(buffer, total_count, sendtype,
                                     root, comm_ptr, errflag);
    if (mpi_errno) {
        MPIR_ERR_SETANDJUMP(mpi_errno, MPI_ERR_INTERN, "**sharpcoll");
    }

    if (rank == root) {
        if (recvbuf != MPI_IN_PLACE) {
            copy_offset = displs[rank] * type_size; 
            mpi_errno = MPIR_Localcopy((char *)buffer + copy_offset, recvcount,
                                       recvtype, recvbuf, recvcount,
                                       recvtype);
        }
    } else {
        copy_offset = nonroot_displs[rank] * type_size;
        mpi_errno = MPIR_Localcopy((char *)buffer + copy_offset, recvcount,
                                   recvtype, recvbuf, recvcount, recvtype);
    }

  fn_exit:
    return mpi_errno;

  fn_fail:
    goto fn_exit;
}
#endif
