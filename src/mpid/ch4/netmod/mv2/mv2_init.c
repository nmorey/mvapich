/*
 * Copyright (c) 2001-2022, The Ohio State University. All rights reserved.
 * This file is part of the MVAPICH2 software package developed by the team
 * members of The Ohio State University's Network-Based Computing Laboratory
 * (NBCL), headed by Professor Dhabaleswar K. (DK) Panda. For detailed
 * copyright and licensing information, please refer to the copyright file
 * COPYRIGHT in the top level MVAPICH2 directory.
 */

#include "mpidimpl.h"
#include "mv2_coll_shmem.h"
#include "hwloc_bind.h"

/*
=== BEGIN_MPI_T_MV2_CVAR_INFO_BLOCK ===

categories:
    - name        : CH4
      description : INHERITED

cvars:
    - name        : MV2_SHOW_CPU_BINDING
      category    : CH4
      type        : int
      default     : 0
      class       : none
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : >-
        Possible values: 0, 1, 2
        If set to 1, prints the CPU mapping of all processes on the node where
        rank 0 exists. If set to 2, prints the CPU mapping of all processes on
        all nodes. 

    - name        : MV2_SHOW_HCA_BINDING
      category    : CH4
      type        : int
      default     : 0
      class       : none
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : >-
        Possible values: 0, 1, 2
        If set to 1, prints the HCA mapping of all processes on the node where
        rank 0 exists. If set to 2, prints the HCA mapping of all processes on
        all nodes. 

    - name        : MV2_SHOW_HW_BINDING
      category    : CH4
      type        : int
      default     : 0
      class       : none
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : >-
        Possible values: 0, 1, 2
        If set to 1, prints the CPU and HCA mappings of all processes on the
        node where rank 0 exists. If set to 2, prints the CPU and HCA mappings
        of all processes on all nodes. 

=== END_MPI_T_MV2_CVAR_INFO_BLOCK ===
*/
int MPIDI_MV2_mpi_init_hook(int rank, int size, int appnum, int *tag_bits,
                            MPIR_Comm *init_comm)
{
    int mpi_errno = MPI_SUCCESS;

    /* initialize mv2 specific cvars 
     * base cvars were intialized before the call to MPID_Init so this is safe
     */
    MPIR_T_MV2_cvar_init();
 
    /* Set affinity before any other init hooks to ensure that the same process
     * to core mapping is used everywhere */
    mpi_errno = MPIDI_MV2_CH4_set_affinity(MPIR_Process.rank, MPIR_Process.size);
    MPIR_ERR_CHECK(mpi_errno);

#ifdef HAVE_CH4_NETMOD_OFI
    mpi_errno = MPIDI_OFI_mpi_init_hook(rank, size, appnum, tag_bits,
                                        init_comm);
#endif
#ifdef HAVE_CH4_NETMOD_UCX
    mpi_errno = MPIDI_UCX_mpi_init_hook(rank, size, appnum, tag_bits,
                                        init_comm);
#endif
    MPIR_ERR_CHECK(mpi_errno);

  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIDI_MV2_mpi_finalize_hook(void)
{
    int mpi_errno = MPI_SUCCESS;

    /* Check to see if shmem_collectives were enabled. If yes, the
    specific entries need to be freed. */
    MPIR_Comm *comm_ptr = NULL;
    MPIR_Errflag_t errflag = MPIR_ERR_NONE;
    MPIR_Comm_get_ptr( MPI_COMM_WORLD, comm_ptr );
    mpi_errno = MPIR_Barrier_impl(comm_ptr, &errflag);
    MPIR_ERR_CHECK(mpi_errno);
    if(MPIR_Process.comm_world->dev.ch.shmem_coll_ok == 1) {
        mpi_errno = free_2level_comm(MPIR_Process.comm_world);
        MPIR_ERR_CHECK(mpi_errno);
    }

    /* finalize mv2 specific cvars */
    MPIR_T_MV2_cvar_finalize();

    MV2_collectives_arch_finalize();

    if (mv2_enable_shmem_collectives || finalize_coll_comm == 1) {
        mpi_errno = MPIR_MV2_SHMEM_COLL_Cleanup();
        MPIR_ERR_CHECK(mpi_errno);
    }

    smpi_destroy_hwloc_topology();

#ifdef HAVE_CH4_NETMOD_OFI
    mpi_errno = MPIDI_OFI_mpi_finalize_hook();
#endif
#ifdef HAVE_CH4_NETMOD_UCX
    mpi_errno = MPIDI_UCX_mpi_finalize_hook();
#endif
    MPIR_ERR_CHECK(mpi_errno);

  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIDI_MV2_post_init(void)
{
    int mpi_errno = MPI_SUCCESS;
    int show_binding = 0;
#ifdef HAVE_CH4_NETMOD_OFI
    mpi_errno = MPIDI_OFI_post_init();
#endif
#ifdef HAVE_CH4_NETMOD_UCX
    mpi_errno = MPIDI_UCX_post_init();
#endif
    MPIR_ERR_CHECK(mpi_errno);

    /* show cpu/hca affinity and clean up hwloc files */
    show_binding = (MV2_SHOW_CPU_BINDING > MV2_SHOW_HW_BINDING) ?
                    MV2_SHOW_CPU_BINDING : MV2_SHOW_HW_BINDING;
    if (show_binding) {
        mv2_show_cpu_affinity(show_binding);
    }
#if 0
    show_binding = (MV2_SHOW_HCA_BINDING > MV2_SHOW_HW_BINDING) ?
                    MV2_SHOW_HCA_BINDING : MV2_SHOW_HW_BINDING;
    if (show_binding) {
        mv2_show_hca_affinity(show_binding);
    }
#endif

#ifdef _OSU_COLLECTIVES_
    /*
     * TODO: we need to get this in an MV2_USE_OSU_COLLECTIVES branch,
     * but as of right now not running arch_init breaks other code.
     * Root cause here is MV2_Read_env_vars() is called in that
     * function. Whole function needs to be refactored though.
     */
    struct coll_info colls_arch_hca[colls_max];
    /* TODO : We need a reliable way to find heterogeneity here. Setting
     * it to 0 for testing purposes. */
    int heterogeneity = 0;
    mpi_errno = MV2_collectives_arch_init(heterogeneity, colls_arch_hca);
    MPIR_ERR_CHECK(mpi_errno);

    mpi_errno = MPIR_MV2_SMP_COLL_init();
    MPIR_ERR_CHECK(mpi_errno); 

    /* setup two level comm for OSU collectives */
    if (mv2_use_osu_collectives && mv2_enable_shmem_collectives &&
        (mv2_enable_socket_aware_collectives ||
         mv2_enable_topo_aware_collectives)) {
        mpi_errno = smpi_load_hwloc_topology_whole();
        if (mpi_errno != MPI_SUCCESS) {
            MPIR_ERR_POP(mpi_errno);
        }

        if(mv2_enable_topo_aware_collectives) {
            /* Find the NUMA domain I am bound to */
            mpi_errno = smpi_identify_my_numa_id();
            if (mpi_errno != MPI_SUCCESS) {
                MPIR_ERR_POP(mpi_errno);
            }
            /* Find the socket I am bound to */
            mpi_errno = smpi_identify_my_sock_id();
            if (mpi_errno != MPI_SUCCESS) {
                MPIR_ERR_POP(mpi_errno);
            }
            /* PRINT_DEBUG(DEBUG_INIT_verbose, "cpu_id = %d, sock_id = %d, numa_id = %d, l3_id = %d\n",
                    mv2_my_cpu_id, mv2_my_sock_id, mv2_my_numa_id, mv2_my_l3_id); */
        }
    }

    if (mv2_use_osu_collectives &&
        mv2_enable_shmem_collectives) {

       MPIR_Comm *comm_ptr = NULL;
       MPIR_Comm_get_ptr(MPI_COMM_WORLD, comm_ptr);
       int flag=0; 
       PMPI_Comm_test_inter(comm_ptr->handle, &flag);

       if(flag == 0 && comm_ptr->dev.ch.shmem_coll_ok == 0 &&
               comm_ptr->local_size < mv2_two_level_comm_early_init_threshold &&
               check_split_comm(pthread_self())) { 

            disable_split_comm(pthread_self());
            mpi_errno = create_2level_comm(comm_ptr->handle, comm_ptr->local_size, comm_ptr->rank);
            if(mpi_errno) {
               MPIR_ERR_POP(mpi_errno);
            }
            enable_split_comm(pthread_self());
            if(mpi_errno) {
               MPIR_ERR_POP(mpi_errno);
            }
       } 
    }
#endif

    mpi_errno = smpi_unlink_hwloc_topology_file();
    MPIR_ERR_CHECK(mpi_errno);

  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}
