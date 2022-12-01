#include "bcast_tuning.h"

#if defined(_MCST_SUPPORT_)
#include "ibv_mcast.h"
int MPIR_Mcast_inter_node_MV2(void *buffer,
                              int count,
                              MPI_Datatype datatype,
                              int root, MPIR_Comm * comm_ptr, 
                              MPIR_Errflag_t *errflag)
{
    MPIR_TIMER_START(coll, bcast, mcast_internode);
    int mpi_errno = MPI_SUCCESS;
    int rank, comm_size;
    int extent;
    intptr_t nbytes;
    MPI_Comm shmem_comm, leader_comm;
    MPIR_Comm *shmem_commptr = NULL, *leader_commptr = NULL;
    int leader_rank, leader_comm_rank, leader_of_root;
    bcast_info_t *bcast_info;
    void *buf;
    intptr_t len, pos;

    MPIR_T_PVAR_COUNTER_INC(MV2, mv2_coll_bcast_mcast_internode, 1);
    comm_size = comm_ptr->local_size;
    rank = comm_ptr->rank;
    bcast_info = (bcast_info_t *) comm_ptr->dev.ch.bcast_info;

    shmem_comm = comm_ptr->dev.ch.shmem_comm;
    MPIR_Comm_get_ptr(shmem_comm, shmem_commptr);

    leader_comm = comm_ptr->dev.ch.leader_comm;
    MPIR_Comm_get_ptr(leader_comm, leader_commptr);
    leader_comm_rank = comm_ptr->dev.ch.leader_rank[rank];
    leader_rank = comm_ptr->dev.ch.leader_map[rank];
    leader_of_root = comm_ptr->dev.ch.leader_map[root];
    MPI_Aint true_lb, true_extent;
    MPIR_Type_get_true_extent_impl(datatype, &true_lb, &true_extent);

    /* If there is only one process, return */
    if (comm_size == 1)
        goto fn_exit;

    MPIR_Datatype_get_extent_macro(datatype, extent);
    nbytes = (intptr_t) (count) * (extent);
    PRINT_DEBUG(DEBUG_MCST_verbose > 3,
                "Calling mcast msg of size %ld fragment size %ld\n",
                nbytes, MAX_MCAST_FRAGMENT_SIZE);
    for (pos = 0; pos < nbytes; pos += MAX_MCAST_FRAGMENT_SIZE) {
        buf = (char *) buffer + true_lb + pos;
        len = MIN(nbytes - pos, MAX_MCAST_FRAGMENT_SIZE);

        if (leader_rank == leader_of_root) {
            if (mv2_use_mcast_pipeline_shm) {
                mpi_errno = MPIR_Shmem_Bcast_MV2((char *) buf, len,
                                                 MPI_BYTE, 0, shmem_commptr, 
                                                 errflag);
            }
        }

        if (leader_comm_rank >= 0) {
            if (IS_MCAST_WINDOW_FULL(bcast_info->win_head, 
                                     bcast_info->win_tail)) {
                MPIR_Barrier_impl(leader_commptr, errflag);
                bcast_info->win_head++;
                mv2_mcast_flush_sendwin(&bcast_info->send_window);
                bcast_info->win_tail = bcast_info->win_head - 1;
                PRINT_DEBUG(DEBUG_MCST_verbose > 4,
                            "sendwindow full. tail set to :%u\n", 
                            bcast_info->win_tail);
                MPIR_Assert(bcast_info->send_window.head == NULL);
            }

            if (rank == leader_of_root) {
                mv2_mcast_send((bcast_info_t *) comm_ptr->dev.ch.bcast_info, 
                                buf, len);
            } else {
                mv2_mcast_recv((bcast_info_t *) comm_ptr->dev.ch.bcast_info, 
                                buf, len, leader_of_root);
            }
        }

        if (mv2_use_mcast_pipeline_shm && leader_rank != leader_of_root) {
            mpi_errno = MPIR_Shmem_Bcast_MV2((char *) buf, len,
                                             MPI_BYTE, 0, shmem_commptr, 
                                             errflag);
        }

        bcast_info->win_head++;
    }

    if (mv2_use_mcast_pipeline_shm) {
        comm_ptr->dev.ch.intra_node_done = 1;
    }

  fn_exit:
    MPIR_TIMER_END(coll, bcast, mcast_internode);
    return mpi_errno;
}
#endif
