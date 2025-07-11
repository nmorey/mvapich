/*
 * Copyright (c) 2001-2025, The Ohio State University. All rights reserved.
 *
 * This file is part of the MVAPICH software package developed by the team
 * members of The Ohio State University's Network-Based Computing Laboratory
 * (NBCL), headed by Professor Dhabaleswar K. (DK) Panda.
 *
 * For detailed copyright and licensing information, please refer to the
 * copyright file COPYRIGHT in the top level MVAPICH directory.
 */

#include "mpidimpl.h"
#include "pt2pt_tuning.h"
#include "mpir_err.h"
#include <json.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

/*
=== BEGIN_MPI_T_CVAR_INFO_BLOCK ===

categories:
    - name        : MVAPICH
      description : CVARs that are added by MVAPICH specific functionality

cvars:
    - name        : MPIR_CVAR_PT2PT_JSON_TUNING_FILE
      category    : MVAPICH
      type        : string
      default     : ""
      class       : none
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : >-
        If non-empty, this cvar specifies a file for architecture-specific
        tuning

=== END_MPI_T_CVAR_INFO_BLOCK ===
*/

static void parse_data(struct json_object *obj)
{
    char *ckey = NULL;
    int mpi_errno = MPI_SUCCESS;
    json_object_object_foreach(obj, key, val)
    {
        ckey = MPL_strdup_no_spaces(key);
        if (!strncmp(ckey, SMP_EAGER_SZ_KEY, strlen(SMP_EAGER_SZ_KEY))) {
            tuning_data.mvp_intra_eager_size =
                atoi(ckey + strlen(SMP_EAGER_SZ_KEY));
        } else if (!strncmp(ckey, SMP_COOP_SZ_KEY, strlen(SMP_COOP_SZ_KEY))) {
            tuning_data.mvp_coop_threshold =
                atoi(ckey + strlen(SMP_COOP_SZ_KEY));
        } else {
            MPL_free(ckey);
            MPIR_ERR_SETANDJUMP(mpi_errno, MPI_ERR_OTHER, "**keyvalinvalid");
        }
    }
    MPL_free(ckey);
fn_fail:
    return;
}

void parse_json_tree_intra_tuning(struct json_object *obj)
{
    enum json_type type ATTRIBUTE((unused));
    int mpi_errno = MPI_SUCCESS;
    char *ckey = NULL;
    unsigned int cache_size = 0;
    unsigned long long ram_size = 0;

    json_object_object_foreach(obj, key, val)
    {
        type = json_object_get_type(val);
        ckey = MPL_strdup_no_spaces(key);
        MPIR_Assert(type == json_type_object);

        if (!strncmp(ckey, SMP_EAGER_SZ_KEY, strlen(SMP_EAGER_SZ_KEY)) ||
            !strncmp(ckey, SMP_COOP_SZ_KEY, strlen(SMP_COOP_SZ_KEY))) {
            parse_data(obj);
            MPL_free(ckey);
            return;
        }

        char *temp_key = ckey;
        if (!strncmp(temp_key, "cache<=", strlen("cache<="))) {
            strtok(temp_key, "<=");
            char *number = strtok(NULL, "<=");
            char *size =
                (number + strlen(number) - (sizeof(MVP_KB_SUFFIX) - 1));
            cache_size = atoi(number);
            if (!strncmp(size, MVP_KB_SUFFIX, strlen(MVP_KB_SUFFIX))) {
                cache_size *= MVP_KB_COUNT;
            } else if (!strncmp(size, MVP_MB_SUFFIX, strlen(MVP_MB_SUFFIX))) {
                cache_size *= MVP_MB_COUNT;
            } else if (!strncmp(size, MVP_GB_SUFFIX, strlen(MVP_GB_SUFFIX))) {
                cache_size *= MVP_GB_COUNT;
            }
            if (tuning_data.cache_size <= cache_size) {
                parse_json_tree_intra_tuning(json_object_object_get(obj, key));
                MPL_free(ckey);
                continue;
            } else {
                MPL_free(ckey);
                continue;
                /* Why we continue:
                 * To iterate through all cache sizes at this specific key
                 * we do NOT immediately go to default tuning upon the first
                 * mismatch
                 */
            }
        } else if (!strncmp(temp_key, "cache=any", strlen("cache=any"))) {
            parse_json_tree_intra_tuning(json_object_object_get(obj, key));
            MPL_free(ckey);
            continue;
        } else if (!strncmp(temp_key, "RAM<=", strlen("RAM<="))) {
            strtok(temp_key, "<=");
            char *number = strtok(NULL, "<=");
            char *size =
                (number + strlen(number) - (sizeof(MVP_KB_SUFFIX) - 1));
            ram_size = atoi(number);
            if (!strncmp(size, MVP_KB_SUFFIX, strlen(MVP_KB_SUFFIX))) {
                ram_size *= MVP_KB_COUNT;
            } else if (!strncmp(size, MVP_MB_SUFFIX, strlen(MVP_MB_SUFFIX))) {
                ram_size *= MVP_MB_COUNT;
            } else if (!strncmp(size, MVP_GB_SUFFIX, strlen(MVP_GB_SUFFIX))) {
                ram_size *= MVP_GB_COUNT;
            }
            if (tuning_data.ram_size <= ram_size) {
                parse_json_tree_intra_tuning(json_object_object_get(obj, key));
                MPL_free(ckey);
                continue;
            } else {
                MPL_free(ckey);
                continue;
                /* See above reasoning for continuing*/
            }
        } else if (!strncmp(temp_key, "RAM=any", strlen("RAM=any"))) {
            parse_json_tree_intra_tuning(json_object_object_get(obj, key));
            MPL_free(ckey);
            continue;
        } else {
            MPL_free(ckey);
            MPIR_ERR_SETANDJUMP(mpi_errno, MPI_ERR_INTERN, "**keyvalinvalid");
        }
    }
fn_fail:
    return;
}

int MPIDI_MVP_extract_json_file(const char *json_filename, char **json_ptr)
{
    int mpi_errno = MPI_SUCCESS;
    int fd = -1;
    struct stat st;
    char *json = NULL;
    struct json_object *tree = NULL;
    MPIR_Assert(strcmp(json_filename, ""));

    fd = open(json_filename, O_RDONLY);
    MPIR_ERR_CHKANDJUMP(fd == -1, mpi_errno, MPI_ERR_INTERN, "**fileaccess");

    stat(json_filename, &st);
    json = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    close(fd);

    *json_ptr = json;
    tree = json_tokener_parse(json);
    parse_json_tree_intra_tuning(tree);
    json_object_put(tree);

fn_fail:
    return mpi_errno;
}

int MPIDI_MVP_initialize_tuning_data_struct(void)
{
    int mpi_errno = MPI_SUCCESS;
    FILE *fp = NULL;
    unsigned int cache_size = 0;
    unsigned int ram_size = 0;

    char line[MVP_MAX_LINE_LENGTH] = {0};
    char *key = NULL, *tmp = NULL;
    int lenstr = 0;

    fp = fopen(CONFIG_FILE_CACHE, "r");
    if (fp == NULL) {
        fprintf(stderr, "[WARNING][%s]: Failed to open \"%s\"\n", __func__,
                CONFIG_FILE_CACHE);
        mpi_errno = MPI_ERR_OTHER;
        goto fn_fail;
    } else {
        while (!feof(fp)) {
            memset(line, 0, MVP_MAX_LINE_LENGTH);
            fgets(line, MVP_MAX_LINE_LENGTH - 1, fp);

            lenstr = strlen(line);
            if (lenstr == 0) {
                continue;
            }
            cache_size = atoi(line);

            tuning_data.cache_size = cache_size;
            if (line[lenstr - 2] == 'K') {
                tuning_data.cache_size *= MVP_KB_COUNT;
            } else if (line[lenstr - 2] == 'M') {
                tuning_data.cache_size *= MVP_MB_COUNT;
            } else if (line[lenstr - 2] == 'G') {
                tuning_data.cache_size *= MVP_GB_COUNT;
            }
            continue;
        }
        fclose(fp);
        fp = NULL;
    }

    fp = fopen(CONFIG_FILE_RAM, "r");
    if (fp == NULL) {
        MPIR_ERR_SETANDJUMP(mpi_errno, MPI_ERR_OTHER, "**fileaccess");
    }

    while (!feof(fp)) {
        memset(line, 0, MVP_MAX_LINE_LENGTH);
        fgets(line, MVP_MAX_LINE_LENGTH - 1, fp);
        if (strlen(line) == 0) {
            continue;
        }

        if (!(key = strtok(line, ":\t"))) {
            continue;
        }

        if (!strcmp(key, MVP_MEM_TOTAL)) {
            tmp = strtok(NULL, MVP_WHITESPACE);
            char *tmp2 = strtok(NULL, MVP_WHITESPACE);
            ram_size = atoi(tmp);
            tuning_data.ram_size = ram_size;
            if (!strncmp(tmp2, MVP_KB_SUFFIX, strlen(MVP_KB_SUFFIX))) {
                tuning_data.ram_size *= MVP_KB_COUNT;
            } else if (!strncmp(tmp2, MVP_MB_SUFFIX, strlen(MVP_MB_SUFFIX))) {
                tuning_data.ram_size *= MVP_MB_COUNT;
            } else if (!strncmp(tmp2, MVP_GB_SUFFIX, strlen(MVP_GB_SUFFIX))) {
                tuning_data.ram_size *= MVP_GB_COUNT;
            }
            continue;
        }
    }
    fclose(fp);
    fp = NULL;

fn_fail:
    return mpi_errno;
}

int MPIDI_MVP_set_intra_node_tunables()
{
    if (MPIR_CVAR_PT2PT_JSON_TUNING_FILE == NULL ||
        strcmp(MPIR_CVAR_PT2PT_JSON_TUNING_FILE, "") == 0) {
        return MPI_SUCCESS;
    }

    int mpi_errno = MPI_SUCCESS;
    char *json_buffer = NULL;

    mpi_errno = MPIDI_MVP_initialize_tuning_data_struct();
    if (mpi_errno != MPI_SUCCESS) {
        MPIR_ERR_SETANDJUMP(mpi_errno, MPI_ERR_OTHER, "**other");
    }

    mpi_errno = MPIDI_MVP_extract_json_file(MPIR_CVAR_PT2PT_JSON_TUNING_FILE,
                                            &json_buffer);
    if (mpi_errno != MPI_SUCCESS || json_buffer == NULL) {
        fprintf(stderr,
                "[ERROR][%s] Failed to extract filename contents into a "
                "buffer; falling back to defaults\n",
                __func__);

        tuning_data.mvp_intra_eager_size = 131072;
        tuning_data.mvp_coop_threshold = 262144;
    }

    MPIR_CVAR_SOFT_SET(MPIR_CVAR_CH4_SHM_POSIX_IQUEUE_CELL_SIZE,
                       tuning_data.mvp_intra_eager_size);
    MPIR_CVAR_SOFT_SET(MPIR_CVAR_CH4_PACK_BUFFER_SIZE,
                       tuning_data.mvp_intra_eager_size);

fn_fail:
    return mpi_errno;
}
