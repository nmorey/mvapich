/*
 * Copyright (c) 2001-2023, The Ohio State University. All rights reserved.
 *
 * This file is part of the MVAPICH software package developed by the team
 * members of The Ohio State University's Network-Based Computing Laboratory
 * (NBCL), headed by Professor Dhabaleswar K. (DK) Panda.
 *
 * For detailed copyright and licensing information, please refer to the
 * copyright file COPYRIGHT in the top level MVAPICH directory.
 */

#include "mpiimpl.h"
#include "mvp_coll_impl.h"

/*
=== BEGIN_MPI_T_CVAR_INFO_BLOCK ===

cvars:
    - name        : MPIR_CVAR_REDUCE_INTER_KNOMIAL_FACTOR
      category    : COLLECTIVE
      type        : int
      default     : 4
      class       : none
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : >-
        This defines the degree of the knomial operation during the
        inter-node knomial reduce phase.

    - name        : MPIR_CVAR_REDUCE_INTRA_KNOMIAL_FACTOR
      category    : COLLECTIVE
      type        : int
      default     : 4
      class       : none
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : >-
        This defines the degree of the knomial operation during the
        intra-node knomial reduce phase.

=== END_MPI_T_CVAR_INFO_BLOCK ===
*/

MPL_STATIC_INLINE_PREFIX int MPIR_Reduce_knomial_trace(
    int root, int reduce_kf, MPIR_Comm *comm_ptr, int *dst,
    int *expected_send_count, int *expected_recv_count, int **src_array)
{
    int mask = 0x1, k, comm_size, src, rank, relative_rank, lroot = 0;
    int orig_mask = 0x1;
    int recv_iter = 0, send_iter = 0;
    int *knomial_reduce_src_array = NULL;
    rank = comm_ptr->rank;
    comm_size = comm_ptr->local_size;

    lroot = root;
    relative_rank = (rank - lroot + comm_size) % comm_size;

    /* First compute to whom we need to send data */
    while (mask < comm_size) {
        if (relative_rank % (reduce_kf * mask)) {
            *dst =
                relative_rank / (reduce_kf * mask) * (reduce_kf * mask) + root;
            if (*dst >= comm_size) {
                *dst -= comm_size;
            }
            send_iter++;
            break;
        }
        mask *= reduce_kf;
    }
    mask /= reduce_kf;

    /* Now compute how many children we have in the knomial-tree */
    orig_mask = mask;
    while (mask > 0) {
        for (k = 1; k < reduce_kf; k++) {
            if (relative_rank + mask * k < comm_size) {
                recv_iter++;
            }
        }
        mask /= reduce_kf;
    }

    /* Finally, fill up the src array */
    if (recv_iter > 0) {
        knomial_reduce_src_array =
            MPL_malloc(sizeof(int) * recv_iter, MPL_MEM_COLL);
    }

    mask = orig_mask;
    recv_iter = 0;
    while (mask > 0) {
        for (k = 1; k < reduce_kf; k++) {
            if (relative_rank + mask * k < comm_size) {
                src = rank + mask * k;
                if (src >= comm_size) {
                    src -= comm_size;
                }
                knomial_reduce_src_array[recv_iter++] = src;
            }
        }
        mask /= reduce_kf;
    }

    *expected_recv_count = recv_iter;
    *expected_send_count = send_iter;
    *src_array = knomial_reduce_src_array;
    return 0;
}

int MPIR_Reduce_intra_osu_knomial(const void *sendbuf, void *recvbuf,
                                  MPI_Aint count, MPI_Datatype datatype,
                                  MPI_Op op, int root, MPIR_Comm *comm_ptr,
                                  int inter_kf, int intra_kf,
                                  MPIR_Errflag_t errflag)
{
    int mpi_errno = MPI_SUCCESS;
    int mpi_errno_ret = MPI_SUCCESS;
    int rank, is_commutative;
    int src, k;
    MPIR_Request *send_request = NULL;
    int index = 0;
    MPI_Aint true_lb, true_extent, extent;
    MPI_Status status;
    int recv_iter = 0, dst, expected_send_count, expected_recv_count;
    int *src_array = NULL;
    void **tmp_buf = NULL;
    int reduce_kf;
    MPIR_Request **requests = NULL;
    MPI_Request *mpi_reqs = NULL;
    MPIR_CHKLMEM_DECL(1);

    MPIR_T_PVAR_COUNTER_INC(MVP, mvp_coll_reduce_knomial, 1);
    MPIR_TIMER_START(coll, reduce, knomial);

    reduce_kf = comm_ptr->node_count > 1 ? inter_kf : intra_kf;

    if (count == 0) {
        goto fn_exit;
    }

    rank = comm_ptr->rank;

    /* Create a temporary buffer */

    MPIR_Type_get_true_extent_impl(datatype, &true_lb, &true_extent);
    MPIR_Datatype_get_extent_macro(datatype, extent);

    /* Get func ptr for the reduction op
     * and initialize is_commutative and is_cxx_uop */
    is_commutative = MPIR_Op_is_commutative(op);

    if (rank != root && sendbuf != MPI_IN_PLACE) {
        MPIR_CHKLMEM_MALLOC(recvbuf, void *,
                            count *(MPL_MAX(extent, true_extent)), mpi_errno,
                            "receive buffer", MPL_MEM_COLL);
        recvbuf = (void *)((char *)recvbuf - true_lb);
    }

    if (sendbuf != MPI_IN_PLACE) {
        mpi_errno =
            MPIR_Localcopy(sendbuf, count, datatype, recvbuf, count, datatype);
        MPIR_ERR_CHECK(mpi_errno);
    }

    MPIR_Reduce_knomial_trace(root, reduce_kf, comm_ptr, &dst,
                              &expected_send_count, &expected_recv_count,
                              &src_array);

    if (expected_recv_count > 0) {
        tmp_buf =
            MPL_malloc(sizeof(void *) * expected_recv_count, MPL_MEM_COLL);
        requests = (MPIR_Request **)MPL_malloc(
            sizeof(MPIR_Request *) * expected_recv_count, MPL_MEM_COLL);
        mpi_reqs = (MPI_Request *)MPL_malloc(
            sizeof(MPI_Request) * expected_recv_count, MPL_MEM_COLL);
        for (k = 0; k < expected_recv_count; k++) {
            tmp_buf[k] = MPL_malloc(count * (MPL_MAX(extent, true_extent)),
                                    MPL_MEM_COLL);
            tmp_buf[k] = (void *)((char *)tmp_buf[k] - true_lb);
        }

        while (recv_iter < expected_recv_count) {
            src = src_array[expected_recv_count - (recv_iter + 1)];

            MPIR_T_MVP_PVAR_COLL_SET_INC(reduce, knomial, recv, count,
                                         datatype);
            mpi_errno =
                MPIC_Irecv(tmp_buf[recv_iter], count, datatype, src,
                           MPIR_REDUCE_TAG, comm_ptr, &requests[recv_iter]);
            /* Convert the MPIR_Request objects to MPI_Request objects */
            mpi_reqs[recv_iter] = requests[recv_iter]->handle;
            recv_iter++;

            if (mpi_errno) {
                /* for communication errors,
                 * just record the error but continue*/
                errflag = MPIR_ERR_GET_CLASS(mpi_errno);
                MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
                MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
            }
        }

        recv_iter = 0;
        while (recv_iter < expected_recv_count) {
            mpi_errno =
                PMPI_Waitany(expected_recv_count, mpi_reqs, &index, &status);
            recv_iter++;
            if (mpi_errno) {
                /* for communication errors, just record the error but
                 * continue*/
                errflag = MPIR_ERR_GET_CLASS(mpi_errno);
                MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
                MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
            }
            if (is_commutative) {
                MPIR_Reduce_local(tmp_buf[index], recvbuf, (MPI_Aint)count,
                                  datatype, op);
            }
        }

        for (k = 0; k < expected_recv_count; k++) {
            MPL_free(tmp_buf[k]);
        }
        MPL_free(tmp_buf);
        MPL_free(requests);
        MPL_free(mpi_reqs);
    }

    if (src_array != NULL) {
        MPL_free(src_array);
    }

    if (rank != root) {
        MPIR_T_MVP_PVAR_COLL_SET_INC(reduce, knomial, send, count, datatype);
        mpi_errno = MPIC_Isend(recvbuf, count, datatype, dst, MPIR_REDUCE_TAG,
                               comm_ptr, &send_request, errflag);
        if (mpi_errno) {
            /* for communication errors, just record the error but continue
             * */
            errflag = MPIR_ERR_GET_CLASS(mpi_errno);
            MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**fail");
            MPIR_ERR_ADD(mpi_errno_ret, mpi_errno);
        }
        mpi_errno = MPIC_Waitall(1, &send_request, &status);
    }

fn_exit:
    MPIR_TIMER_END(coll, reduce, knomial);
    MPIR_CHKLMEM_FREEALL();
    if (mpi_errno_ret) {
        mpi_errno = mpi_errno_ret;
    } else if (errflag) {
        MPIR_ERR_SET(mpi_errno, MPI_ERR_OTHER, "**coll_fail");
    }
    return mpi_errno;
fn_fail:
    goto fn_exit;
}
