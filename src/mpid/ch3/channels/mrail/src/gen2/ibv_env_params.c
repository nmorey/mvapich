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
#include "rdma_impl.h"
#include "ibv_param.h"
#include "coll_shmem_internal.h"
#include "gather_tuning.h"
#include "hwloc_bind.h"

/* List of all runtime environment variables.
** Format of the parameter info
**  {
**      id,
**      datatype,
**      name,
**      addr of variables which stores the param value
**      externally visible 1 or 0
**      descrption of the parameter.
**  }
*/
mv2_env_param_list_t  param_list[] = {
/* mpirun_rsh */
{
    MV2_COMM_WORLD_LOCAL_RANK,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_launcher,
    "MV2_COMM_WORLD_LOCAL_RANK",
    NULL,
    0,
    NULL    },
{
    PMI_ID,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_launcher,
    "PMI_ID",
    NULL,
    0,
    NULL    },
{
    MPIRUN_COMM_MULTIPLE,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_launcher,
    "MPIRUN_COMM_MULTIPLE",
    NULL,
    0,
    NULL    },
{
    MPISPAWN_BINARY_PATH,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_launcher,
    "MPISPAWN_BINARY_PATH",
    NULL,
    0,
    NULL    },
{
    MPISPAWN_CR_CKPT_CNT,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_launcher,
    "MPISPAWN_CR_CKPT_CNT",
    NULL,
    0,
    NULL    },
{
    MPISPAWN_CR_CONTEXT,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_launcher,
    "MPISPAWN_CR_CONTEXT",
    NULL,
    0,
    NULL    },
{
    MPISPAWN_CR_SESSIONID,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_launcher,
    "MPISPAWN_CR_SESSIONID",
    NULL,
    0,
    NULL    },
{
    MPISPAWN_GLOBAL_NPROCS,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_launcher,
    "MPISPAWN_GLOBAL_NPROCS",
    NULL,
    0,
    NULL    },
{
    MPISPAWN_MPIRUN_CR_PORT,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_launcher,
    "MPISPAWN_MPIRUN_CR_PORT",
    NULL,
    0,
    NULL    },
{
    MPISPAWN_MPIRUN_HOST,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_launcher,
    "MPISPAWN_MPIRUN_HOST",
    NULL,
    0,
    NULL    },
{
    MPISPAWN_MPIRUN_ID,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_launcher,
    "MPISPAWN_MPIRUN_ID",
    NULL,
    0,
    NULL    },
{
    MPISPAWN_NNODES,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_launcher,
    "MPISPAWN_NNODES",
    NULL,
    0,
    NULL    },
{
    MPISPAWN_WORKING_DIR,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_launcher,
    "MPISPAWN_WORKING_DIR",
    NULL,
    0,
    NULL    },
{
    MPIEXEC_TIMEOUT,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_launcher,
    "MPIEXEC_TIMEOUT",
    NULL,
    1,
    NULL    },
{
    MPISPAWN_USE_TOTALVIEW,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_launcher,
    "MPISPAWN_USE_TOTALVIEW",
    NULL,
    0,
    NULL    },
{
    MV2_FASTSSH_THRESHOLD,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_launcher,
    "MV2_FASTSSH_THRESHOLD",
    NULL,
    1,
    NULL    },
{
    MV2_MPIRUN_TIMEOUT,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_launcher,
    "MV2_MPIRUN_TIMEOUT",
    NULL,
    1,
    NULL    },
{
    MV2_MT_DEGREE,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_launcher,
    "MV2_MT_DEGREE",
    NULL,
    1,
    NULL    },
{
    MV2_NPROCS_THRESHOLD,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_launcher,
    "MV2_NPROCS_THRESHOLD",
    NULL,
    1,
    NULL    },
{
    USE_LINEAR_SSH,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_launcher,
    "USE_LINEAR_SSH",
    NULL,
    0,
    NULL    },
{
    PMI_SUBVERSION,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_launcher,
    "PMI_SUBVERSION",
    NULL,
    0,
    NULL    },
{
    PMI_VERSION,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_launcher,
    "PMI_VERSION",
    NULL,
    0,
    NULL    },
{
    PMI_PORT,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_launcher,
    "PMI_PORT",
    NULL,
    0,
    NULL    },
{
    PARENT_ROOT_PORT_NAME,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_launcher,
    "PARENT_ROOT_PORT_NAME",
    NULL,
    0,
    NULL    },
/* QoS */
/* collectives */
/* ckpt */
{
    MV2_CKPT_AGGRE_MIG_ROLE,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_ckpt,
    "MV2_CKPT_AGGRE_MIG_ROLE",
    NULL,
    0,
    NULL    },
{
    MV2_CKPT_AGGREGATION_BUFPOOL_SIZE,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_ckpt,
    "MV2_CKPT_AGGREGATION_BUFPOOL_SIZE",
    NULL,
    1,
    NULL    },
{
    MV2_CKPT_AGGREGATION_CHUNK_SIZE,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_ckpt,
    "MV2_CKPT_AGGREGATION_CHUNK_SIZE",
    NULL,
    1,
    NULL    },
{
    MV2_CKPT_AGGRE_MIG_FILE,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_ckpt,
    "MV2_CKPT_AGGRE_MIG_FILE",
    NULL,
    0,
    NULL    },
{
    MV2_CKPT_FILE,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_ckpt,
    "MV2_CKPT_FILE",
    NULL,
    1,
    NULL    },
{
    MV2_CKPT_INTERVAL,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_ckpt,
    "MV2_CKPT_INTERVAL",
    NULL,
    1,
    NULL    },
{
    MV2_CKPT_MAX_CKPTS,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_ckpt,
    "MV2_CKPT_MAX_CKPTS",
    NULL,
    0,
    NULL    },
{
    MV2_CKPT_MAX_SAVE_CKPTS,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_ckpt,
    "MV2_CKPT_MAX_SAVE_CKPTS",
    NULL,
    1,
    NULL    },
{
    MV2_CKPT_MPD_BASE_PORT,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_ckpt,
    "MV2_CKPT_MPD_BASE_PORT",
    NULL,
    0,
    NULL    },
{
    MV2_CKPT_NO_SYNC,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_ckpt,
    "MV2_CKPT_NO_SYNC",
    NULL,
    1,
    NULL    },
{
    MV2_CKPT_SESSIONID,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_ckpt,
    "MV2_CKPT_SESSIONID",
    NULL,
    0,
    NULL    },
{
    MV2_CKPT_USE_AGGREGATION,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_ckpt,
    "MV2_CKPT_USE_AGGREGATION",
    NULL,
    1,
    NULL    },
/* debug */
{
    TOTALVIEW,
    MV2_PARAM_TYPE_INVALID,
    MV2_PARAM_GROUP_debugger,
    "TOTALVIEW",
    NULL,
    0,
    NULL    }
};



/* List of all cuda runtime environment variables.
 * ** Format of the parameter info
 * * **  {
 * * **      id,
 * * **      datatype,
 * * **      name,
 * * **      addr of variables which stores the param value
 * * **      externally visible 1 or 0
 * * **      descrption of the parameter.
 * * **  }
 * * */
#if defined(_ENABLE_CUDA_)
mv2_env_param_list_t  cuda_param_list[] = {
#if defined(HAVE_CUDA_IPC)
{
    MV2_CUDA_IPC_THRESHOLD,
    MV2_PARAM_TYPE_INT,
    MV2_PARAM_GROUP_cuda,
    "MV2_CUDA_IPC_THRESHOLD",
    &mv2_device_ipc_threshold,
    1,
    NULL    }
#endif /*#if defined(HAVE_CUDA_IPC)*/
};
#endif /*#if defined(_ENABLE_CUDA_)*/


void mv2_show_all_params()
{
    /* iterate over all cvars */
    cvar_table_entry_t *cvar_p = NULL;

    fprintf(stderr, "%55s|%20s|%10s\n","CVAR Name", "Value","Active");
    while (cvar_p = (cvar_table_entry_t *)utarray_next(cvar_table, cvar_p)) {
        if (cvar_p->datatype == MPI_INT) {
            fprintf(stderr, "%-55s|%20d|%10d\n", cvar_p->name,
                            *(int *)(cvar_p->addr), cvar_p->active);
        } else if (cvar_p->datatype == MPI_DOUBLE) {
            fprintf(stderr, "%-55s|%20f|%10d\n", cvar_p->name,
                            *(float *)(cvar_p->addr), cvar_p->active);
        } else if (cvar_p->addr == NULL || (*(char **)cvar_p->addr) == NULL) {
            char *tmp = "((NULL))";
            fprintf(stderr, "%-55s|%20s|%10d\n", cvar_p->name,
                            tmp, cvar_p->active);
        } else {
            fprintf(stderr, "%-55s|%20s|%10d\n", cvar_p->name,
                            (const char **)(cvar_p->addr), cvar_p->active);
        }
    }
    fflush(stderr);
}


#if defined(_ENABLE_CUDA_)
void mv2_show_cuda_params()
{
    int i, n_params;
    char *value;
    n_params = sizeof(cuda_param_list)/sizeof(cuda_param_list[0]);
    fprintf(stderr, "\n MVAPICH2 GDR Parameters\n");
    for (i = 0; i <n_params; i++) {
        if(cuda_param_list[i].value != NULL) {
            switch(cuda_param_list[i].type) {
                case MV2_PARAM_TYPE_INT8:
                    fprintf(stderr, "\t%-35s : %d\n",
                        cuda_param_list[i].name, *(uint8_t *)(cuda_param_list[i].value));
                        break;
                case MV2_PARAM_TYPE_INT16:
                    fprintf(stderr, "\t%-35s : %d\n",
                        cuda_param_list[i].name, *(uint16_t *)(cuda_param_list[i].value));
                        break;
                case MV2_PARAM_TYPE_INT:
                    fprintf(stderr, "\t%-35s : %d\n",
                        cuda_param_list[i].name, *(int *)(cuda_param_list[i].value));
                    break;
                case MV2_PARAM_TYPE_LONG:
                    fprintf(stderr, "\t%-35s : %ld\n",
                        cuda_param_list[i].name, *(long *)cuda_param_list[i].value);
                    break;
                case MV2_PARAM_TYPE_STRING:
                    fprintf(stderr, "\t%-35s : %s\n",
                        cuda_param_list[i].name, (char *)cuda_param_list[i].value);
                    break;
                case MV2_PARAM_TYPE_INVALID:
                    if(cuda_param_list[i].value != NULL) {
                    }
                    break;
            }
        } else if((value = getenv(cuda_param_list[i].name)) != NULL) {
                    fprintf(stderr, "\t%-35s : %s\n",
                                cuda_param_list[i].name, value);
        }
    }
}
#endif /*#if defined(_ENABLE_CUDA_)*/

/* List of all runtime info.
** Format of the parameter info
**  {
**      description,
**      addr of variables which stores the param value
**      datatype,
**   }
***/

typedef struct mv2_runlog_info_list {
    char *description;
    void *param;
    MPI_Datatype datatype;
} mv2_runlog_info_list_t;

int mv2_show_runlog_level = 0;

mv2_runlog_info_list_t runlog_info[] = {
{"Max dreg entries used",            &dreg_max_use_count,         MPI_INT},
};

#undef FUNCNAME
#define FUNCNAME mv2_print_param_info
#undef FCNAME
#define FCNAME MPL_QUOTE(FUNCNAME)
static inline int mv2_print_param_info(MPIR_Comm *comm_ptr, mv2_runlog_info_list_t *item, int level)
{
    char param_avg[16], param_min[16], param_max[16];
    int root=0;
    int mpi_errno = MPI_SUCCESS;
    MPIR_Errflag_t errflag = MPIR_ERR_NONE;

    if (level == 2 ) {
        mpi_errno =  MPIR_Reduce_binomial_MV2(item->param, param_max, 1, item->datatype,
                MPI_MAX, root, comm_ptr, &errflag);
        if (mpi_errno) {
            MPIR_ERR_POP(mpi_errno);
        }
        mpi_errno = MPIR_Reduce_binomial_MV2(item->param, param_min, 1, item->datatype,
                MPI_MIN, root, comm_ptr, &errflag);
        if (mpi_errno) {
            MPIR_ERR_POP(mpi_errno);
        }
        mpi_errno = MPIR_Reduce_binomial_MV2(item->param, param_avg, 1, item->datatype,
                MPI_SUM, root, comm_ptr, &errflag);
        if (mpi_errno) {
            MPIR_ERR_POP(mpi_errno);
        }
    }

    if(comm_ptr->rank == 0) {
        if (level == 2) {
            if(item->datatype == MPI_LONG) {
                long *pavg, *pmin, *pmax;
                pavg = (long *) param_avg;
                pmin = (long *) param_min;
                pmax = (long *) param_max;
                *pavg =  *pavg / comm_ptr->local_size;
                fprintf(stderr, "\t%-30s  : Min: %-8lu  Max: %-8lu Avg: %-8lu \n",
                        item->description, *pmin, *pmax, *pavg);
            } else {
                int *pavg, *pmin, *pmax;
                pavg = (int *) param_avg;
                pmin = (int *) param_min;
                pmax = (int *) param_max;
                *pavg /= comm_ptr->local_size;
                fprintf(stderr, "\t%-30s  : Min: %-8d  Max: %-8d Avg: %-8d \n",
                        item->description, *pmin, *pmax, *pavg);
            }
        } else {
            if(item->datatype == MPI_LONG) {
                fprintf(stderr, "\t%-30s  : %-8lu\n",
                        item->description, *(long *)item->param);
            } else {
                fprintf(stderr, "\t%-30s  :%-8d \n",
                        item->description, *(int *)item->param);
            }
        }
    }

fn_exit:
    return mpi_errno;
fn_fail:
    goto fn_exit;

}

void mv2_show_runlog_info(int level)
{
    int pg_rank;
    int n_params, i;

    MPIR_Comm *comm_ptr = NULL;

    MPIR_Comm_get_ptr(MPI_COMM_WORLD, comm_ptr);
    pg_rank = comm_ptr->rank;

    n_params = sizeof(runlog_info)/sizeof(runlog_info[0]);

    if (pg_rank == 0) {
        fprintf(stderr, "\n-------------------------------");
        fprintf(stderr, "\n\n MVAPICH2 DEBUG RUN LOG\n\n");
    }

    for (i = 0; i <n_params; i++) {
        mv2_print_param_info(comm_ptr, &runlog_info[i], level);
    }

    if (pg_rank == 0) {
        fprintf(stderr, "-------------------------------\n");
    }

}
