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

#include "mpiimpl.h"
#include "datatype.h"
#include "mv2_common_tuning.h"
#include "gather_tuning.h"

/*
=== BEGIN_MPI_T_MV2_CVAR_INFO_BLOCK ===

cvars:
    - name        : MV2_GATHER_SWITCH_PT
      category    : COLLECTIVE
      type        : int
      default     : -1
      class       : none
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : >-
        We use different algorithms depending on the system size. For small
        system sizes (up to 386 cores), we use the "2-level" algorithm 
        followed by the "Direct" algorithm. For medium system sizes (up to 1k),
        we use the "Binomial" algorithm followed by the "Direct" algorithm.
        Users can set the switching point between algorithms using this runtime
        parameter.

    - name        : MV2_USE_DIRECT_GATHER
      category    : COLLECTIVE
      type        : boolean
      default     : 1
      class       : none
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : >-
        Use the "Direct" algorithm for the MPI_Gather operation. If
        this parameter is set to 0 at run-time, the "Direct" algorithm
        will not be invoked.

    - name        : MV2_USE_DIRECT_GATHER_SYSTEM_SIZE_MEDIUM
      category    : COLLECTIVE
      type        : int
      default     : 1024
      class       : none
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : >-
        TODO-DESC

    - name        : MV2_USE_DIRECT_GATHER_SYSTEM_SIZE_SMALL
      category    : COLLECTIVE
      type        : int
      default     : 384
      class       : none
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : >-
        TODO-DESC

    - name        : MV2_USE_TWO_LEVEL_GATHER
      category    : COLLECTIVE
      type        : boolean
      default     : 1
      class       : none
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : >-
        Use the two-level multi-core-aware algorithm for the
        MPI_Gather operation. If this parameter is set to 0 at
        run-time, the two-level algorithm will not be invoked.

=== END_MPI_T_MV2_CVAR_INFO_BLOCK ===
*/

MV2_Gather_function_ptr MV2_Gather_inter_leader_function = NULL;
MV2_Gather_function_ptr MV2_Gather_intra_node_function = NULL;

int MPIR_Gather_index_tuned_intra_MV2(const void *sendbuf,
                    int sendcnt,
                    MPI_Datatype sendtype,
                    void *recvbuf,
                    int recvcnt,
                    MPI_Datatype recvtype,
                    int root, MPIR_Comm * comm_ptr, MPIR_Errflag_t *errflag) {
    
    int comm_size_index = 0;
    int inter_node_algo_index = 0;
    int intra_node_algo_index = 0;
    int local_size = 0;
    int partial_sub_ok = 0;
    int conf_index = 0;
    int table_min_comm_size = 0;
    int table_max_comm_size = 0;
    int table_min_inter_size = 0;
    int table_max_inter_size = 0;
    int table_min_intra_size = 0;
    int table_max_intra_size = 0;
    int last_inter;
    int last_intra;
    int lp2ltn; // largest power of 2 less than n
    int lp2ltn_min;
    MPIR_Comm *shmem_commptr = NULL;
    MPI_Comm shmem_comm;
    int mpi_errno = MPI_SUCCESS;
    int comm_size = 0;
    MPI_Aint nbytes = 0;
    MPI_Aint recvtype_size, sendtype_size;
    int rank = -1;

    comm_size = comm_ptr->local_size;
    rank = comm_ptr->rank;

    if (rank == root) {
        MPIR_Datatype_get_size_macro(recvtype, recvtype_size);
        nbytes = recvcnt * recvtype_size;
    } else {
        MPIR_Datatype_get_size_macro(sendtype, sendtype_size);
        nbytes = sendcnt * sendtype_size;
    }
    
    /* check if safe to use partial subscription mode */
    if (comm_ptr->dev.ch.shmem_coll_ok == 1 && comm_ptr->dev.ch.is_uniform) {
    
        shmem_comm = comm_ptr->dev.ch.shmem_comm;
        MPIR_Comm_get_ptr(shmem_comm, shmem_commptr);
        local_size = shmem_commptr->local_size;
        if (mv2_gather_indexed_table_ppn_conf[0] == -1) {
            // Indicating user defined tuning
            conf_index = 0;
            goto conf_check_end;
        }

        FIND_PPN_INDEX  (gather, local_size,conf_index, partial_sub_ok)

    }

    if (partial_sub_ok != 1) {
        conf_index = mv2_gather_indexed_num_ppn_conf/2;
    }
    
conf_check_end:

    /* Search for the corresponding system size inside the tuning table */
    /*
     * Comm sizes progress in powers of 2. Therefore comm_size can just be indexed instead
     */
    table_min_comm_size = mv2_gather_indexed_thresholds_table[conf_index][0].numproc;
    table_max_comm_size =
	mv2_gather_indexed_thresholds_table[conf_index][mv2_size_gather_indexed_tuning_table[conf_index] - 1].numproc;
    
    if (comm_size < table_min_comm_size) {
	/* Comm size smaller than smallest configuration in table: use smallest available */
	comm_size_index = 0;
    }
    else if (comm_size > table_max_comm_size) {
	/* Comm size larger than largest configuration in table: use largest available */
	comm_size_index = mv2_size_gather_indexed_tuning_table[conf_index] - 1;
    }
    else {
	/* Comm size in between smallest and largest configuration: find closest match */
    lp2ltn_min = pow(2, (int)log2(table_min_comm_size));    
	if (comm_ptr->dev.ch.is_pof2) {
	    comm_size_index = log2( comm_size / lp2ltn_min );
	}
	else {
	    lp2ltn = pow(2, (int)log2(comm_size));
        comm_size_index = (lp2ltn < lp2ltn_min) ? 0 : log2( lp2ltn / lp2ltn_min );
	}
    }

    last_inter = mv2_gather_indexed_thresholds_table[conf_index][comm_size_index].size_inter_table - 1;
    table_min_inter_size = mv2_gather_indexed_thresholds_table[conf_index][comm_size_index].inter_leader[0].msg_sz;
    table_max_inter_size = mv2_gather_indexed_thresholds_table[conf_index][comm_size_index].inter_leader[last_inter].msg_sz;
    last_intra = mv2_gather_indexed_thresholds_table[conf_index][comm_size_index].size_intra_table - 1;
    table_min_intra_size = mv2_gather_indexed_thresholds_table[conf_index][comm_size_index].intra_node[0].msg_sz;
    table_max_intra_size = mv2_gather_indexed_thresholds_table[conf_index][comm_size_index].intra_node[last_intra].msg_sz;
    
    if (nbytes < table_min_inter_size) {
	/* Msg size smaller than smallest configuration in table: use smallest available */
	inter_node_algo_index = 0;
    }
    else if (nbytes > table_max_inter_size) {
	/* Msg size larger than largest configuration in table: use largest available */
	inter_node_algo_index = last_inter;
    }
    else {
	/* Msg size in between smallest and largest configuration: find closest match */
	if (pow(2, (int)log2(nbytes)) == nbytes) {
	    inter_node_algo_index = log2( nbytes / table_min_inter_size );
	}
	else {
	    lp2ltn = pow(2, (int)log2(nbytes));
	    inter_node_algo_index = (lp2ltn < table_min_inter_size) ? 0 : log2( lp2ltn / table_min_inter_size );
	}
    }
    
    if (nbytes < table_min_intra_size) {
	/* Msg size smaller than smallest configuration in table: use smallest available */
	intra_node_algo_index = 0;
    }
    else if (nbytes > table_max_intra_size) {
	/* Msg size larger than largest configuration in table: use largest available */
	intra_node_algo_index = last_intra;
    }
    else {
	/* Msg size in between smallest and largest configuration: find closest match */
	if (pow(2, (int)log2(nbytes)) == nbytes) {
	    intra_node_algo_index = log2(nbytes / table_min_intra_size );
	}
	else {
	    lp2ltn = pow(2, (int)log2(nbytes));
	    intra_node_algo_index = (lp2ltn < table_min_intra_size) ? 0 : log2(lp2ltn / table_min_intra_size );
	}
    }
    
#ifdef _ENABLE_CUDA_
   MPI_Aint sendtype_extent;
   MPIR_Datatype_get_extent_macro(sendtype, sendtype_extent);
   int recvtype_extent = 0;
   MPIR_Datatype_get_extent_macro(recvtype, recvtype_extent);
   int send_mem_type = 0;
   int recv_mem_type = 0;
   if (mv2_enable_device) {
       send_mem_type = is_device_buffer(sendbuf);
       recv_mem_type = is_device_buffer(recvbuf);
   }
   if (mv2_enable_device && (send_mem_type || recv_mem_type) &&
       mv2_device_coll_use_stage && (nbytes <= mv2_device_gather_stage_limit/comm_size)) {
       if (sendbuf != MPI_IN_PLACE) {
            if (rank == root) {
                mpi_errno = device_stage_alloc (NULL, 0,
                          &recvbuf, recvcnt*recvtype_extent*comm_size, 
                          0, recv_mem_type, 
                          0);
            } else {
                mpi_errno = device_stage_alloc ((void **)&sendbuf, sendcnt*sendtype_extent,
                          NULL, 0, 
                          send_mem_type, 0, 
                          0);
            }
       } else {
            mpi_errno = device_stage_alloc ((void **)&sendbuf, recvcnt*recvtype_extent,
                      &recvbuf, recvcnt*recvtype_extent*comm_size, 
                      0, recv_mem_type, 
                      rank*recvcnt*recvtype_extent);
       }
        MPIR_ERR_CHECK(mpi_errno);
   }


    /* Use Direct algorithm in cuda configuration */
    if (mv2_enable_device && (((nbytes > mv2_device_gather_stage_limit/comm_size) &&
        mv2_device_coll_use_stage) || !mv2_device_coll_use_stage)) {
        mpi_errno = MPIR_Gather_MV2_Direct(sendbuf, sendcnt,
                                           sendtype, recvbuf, recvcnt, recvtype,
                                           root, comm_ptr, errflag);
    } else
#endif /*_ENABLE_CUDA_*/

    if (comm_ptr->dev.ch.rank_list != NULL &&
            mv2_use_direct_gather == 1 && mv2_use_two_level_gather == 1 &&
            comm_ptr->dev.ch.shmem_coll_ok == 1 && comm_ptr->dev.ch.is_blocked == 0) {
        /* Set intra-node function pt for gather_two_level */
        MV2_Gather_intra_node_function = mv2_gather_indexed_thresholds_table[conf_index][comm_size_index].
	    intra_node[intra_node_algo_index].MV2_pt_Gather_function;
        /* Set inter-leader pt */
        MV2_Gather_inter_leader_function = mv2_gather_indexed_thresholds_table[conf_index][comm_size_index].
	    inter_leader[inter_node_algo_index].MV2_pt_Gather_function;
        /* We call Gather function */
        mpi_errno =
            MV2_Gather_inter_leader_function(sendbuf, sendcnt, sendtype, recvbuf, recvcnt,
                                             recvtype, root, comm_ptr, errflag);

    } else {
        mpi_errno = MPIR_Gather_intra_binomial(sendbuf, sendcnt, sendtype,
                                               recvbuf, recvcnt, recvtype,
                                               root, comm_ptr, errflag);
    }

#ifdef _ENABLE_CUDA_ 
    if (mv2_enable_device && (send_mem_type || recv_mem_type) &&
        mv2_device_coll_use_stage && (nbytes <= mv2_device_gather_stage_limit/comm_size)){
        if (rank == root) {
            device_stage_free (NULL,
                        &recvbuf, recvcnt*recvtype_extent*comm_size,
                        0, recv_mem_type);
        } else {
            device_stage_free ((void **)&sendbuf,
                        NULL, 0,
                        send_mem_type, 0);
        }
    }
#endif                          /*#ifdef _ENABLE_CUDA_*/     

    MPIR_ERR_CHECK(mpi_errno);

  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Gather_MV2(const void *sendbuf,
                    int sendcnt,
                    MPI_Datatype sendtype,
                    void *recvbuf,
                    int recvcnt,
                    MPI_Datatype recvtype,
                    int root, MPIR_Comm * comm_ptr, MPIR_Errflag_t *errflag)
{
    int mpi_errno = MPI_SUCCESS;
    int range = 0;
    int range_threshold = 0;
    int range_intra_threshold = 0;
    MPI_Aint nbytes = 0;
    int comm_size = 0;
    MPI_Aint recvtype_size, sendtype_size;
    int rank = -1;

    comm_size = comm_ptr->local_size;
    rank = comm_ptr->rank;

    if (rank == root) {
        MPIR_Datatype_get_size_macro(recvtype, recvtype_size);
        nbytes = recvcnt * recvtype_size;
    } else {
        MPIR_Datatype_get_size_macro(sendtype, sendtype_size);
        nbytes = sendcnt * sendtype_size;
    }
    
    if (mv2_use_indexed_tuning || mv2_use_indexed_gather_tuning) {
	mpi_errno =  MPIR_Gather_index_tuned_intra_MV2(sendbuf, sendcnt,
                                           sendtype, recvbuf, recvcnt, recvtype,
                                           root, comm_ptr, errflag);
	goto fn_exit;
    }
    /* Search for the corresponding system size inside the tuning table */
    while ((range < (mv2_size_gather_tuning_table - 1)) &&
           (comm_size > mv2_gather_thresholds_table[range].numproc)) {
        range++;
    }
    /* Search for corresponding inter-leader function */
    while ((range_threshold < (mv2_gather_thresholds_table[range].size_inter_table - 1))
           && (nbytes >
               mv2_gather_thresholds_table[range].inter_leader[range_threshold].max)
           && (mv2_gather_thresholds_table[range].inter_leader[range_threshold].max !=
               -1)) {
        range_threshold++;
    }

    /* Search for corresponding intra node function */
    while ((range_intra_threshold < (mv2_gather_thresholds_table[range].size_intra_table - 1))
           && (nbytes >
               mv2_gather_thresholds_table[range].intra_node[range_intra_threshold].max)
           && (mv2_gather_thresholds_table[range].intra_node[range_intra_threshold].max !=
               -1)) {
        range_intra_threshold++;
    }
#if defined(_SMP_LIMIC_)   
    int range_limic_scheme = 0;
    if (use_limic_gather){
        /* Search for corresponding limic-scheme function */
        while ((range_limic_scheme < (mv2_gather_thresholds_table[range].nb_limic_scheme - 1))
                && (nbytes >
                    mv2_gather_thresholds_table[range].limic_gather_scheme[range_limic_scheme].max)
                && (mv2_gather_thresholds_table[range].limic_gather_scheme[range_limic_scheme].max !=
                    -1)) {
            range_limic_scheme++;
        }
        num_scheme =   mv2_gather_thresholds_table[range].limic_gather_scheme[range_limic_scheme].scheme;
    }
#endif /*#if defined(_SMP_LIMIC_)*/
#ifdef _ENABLE_CUDA_
   MPI_Aint sendtype_extent;
   MPIR_Datatype_get_extent_macro(sendtype, sendtype_extent);
   int recvtype_extent = 0;
   MPIR_Datatype_get_extent_macro(recvtype, recvtype_extent);
   int send_mem_type = 0;
   int recv_mem_type = 0;
   if (mv2_enable_device) {
       send_mem_type = is_device_buffer(sendbuf);
       recv_mem_type = is_device_buffer(recvbuf);
   }
   if (mv2_enable_device && (send_mem_type || recv_mem_type) &&
       mv2_device_coll_use_stage && (nbytes <= mv2_device_gather_stage_limit/comm_size)) {
       if (sendbuf != MPI_IN_PLACE) {
            if (rank == root) {
                mpi_errno = device_stage_alloc (NULL, 0,
                          &recvbuf, recvcnt*recvtype_extent*comm_size, 
                          0, recv_mem_type, 
                          0);
            } else {
                mpi_errno = device_stage_alloc ((void **)&sendbuf, sendcnt*sendtype_extent,
                          NULL, 0, 
                          send_mem_type, 0, 
                          0);
            }
       } else {
            mpi_errno = device_stage_alloc ((void **)&sendbuf, recvcnt*recvtype_extent,
                      &recvbuf, recvcnt*recvtype_extent*comm_size, 
                      0, recv_mem_type, 
                      rank*recvcnt*recvtype_extent);
       }
        MPIR_ERR_CHECK(mpi_errno);
   }


    /* Use Direct algorithm in cuda configuration */
    if (mv2_enable_device && (((nbytes > mv2_device_gather_stage_limit/comm_size) &&
        mv2_device_coll_use_stage) || !mv2_device_coll_use_stage)) {
        mpi_errno = MPIR_Gather_MV2_Direct(sendbuf, sendcnt,
                                           sendtype, recvbuf, recvcnt, recvtype,
                                           root, comm_ptr, errflag);
    } else
#endif /*_ENABLE_CUDA_*/

    if (comm_ptr->dev.ch.is_global_block == 1 && mv2_use_direct_gather == 1 &&
            mv2_use_two_level_gather == 1 && comm_ptr->dev.ch.shmem_coll_ok == 1 &&
            comm_ptr->dev.ch.is_blocked == 0) {
        /* Set intra-node function pt for gather_two_level */
        MV2_Gather_intra_node_function = 
                              mv2_gather_thresholds_table[range].intra_node[range_intra_threshold].
                              MV2_pt_Gather_function;
        /* Set inter-leader pt */
        MV2_Gather_inter_leader_function =
                              mv2_gather_thresholds_table[range].inter_leader[range_threshold].
                              MV2_pt_Gather_function;
        /* We call Gather function */
        mpi_errno =
            MV2_Gather_inter_leader_function(sendbuf, sendcnt, sendtype, recvbuf, recvcnt,
                                             recvtype, root, comm_ptr, errflag);

    } else {
        mpi_errno = MPIR_Gather_intra_binomial(sendbuf, sendcnt, sendtype,
                                               recvbuf, recvcnt, recvtype,
                                               root, comm_ptr, errflag);
    }

#ifdef _ENABLE_CUDA_ 
    if (mv2_enable_device && (send_mem_type || recv_mem_type) &&
        mv2_device_coll_use_stage && (nbytes <= mv2_device_gather_stage_limit/comm_size)){
        if (rank == root) {
            device_stage_free (NULL,
                        &recvbuf, recvcnt*recvtype_extent*comm_size,
                        0, recv_mem_type);
        } else {
            device_stage_free ((void **)&sendbuf,
                        NULL, 0,
                        send_mem_type, 0);
        }
    }
#endif                          /*#ifdef _ENABLE_CUDA_*/     

    MPIR_ERR_CHECK(mpi_errno);

  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

/* end:nested */
