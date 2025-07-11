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

#ifndef __PT2PT_TUNING_H__
#define __PT2PT_TUNING_H__


#include <unistd.h>
#include <stdint.h>

#define CONFIG_FILE_CACHE "/sys/devices/system/cpu/cpu0/cache/index3/size"
#define CONFIG_FILE_RAM "/proc/meminfo"

#define MVP_MEM_TOTAL "MemTotal"

#define MVP_KB_SUFFIX "kB"
#define MVP_MB_SUFFIX "mB"
#define MVP_GB_SUFFIX "gB"
#define MVP_WHITESPACE " "

#define MVP_MAX_LINE_LENGTH 1024
#define MVP_KB_COUNT 1024
#define MVP_MB_COUNT 1048576
#define MVP_GB_COUNT (MVP_KB_COUNT * MVP_MB_COUNT)




struct MPIDI_MVP_tuning_data { 
    unsigned int cache_size;
    unsigned long long ram_size;

    /* potentially down the line */
    unsigned int core_count;
    unsigned int socket_count;

    /* Fields */
    unsigned int mvp_intra_eager_size;
    unsigned int mvp_coop_threshold;
};

static struct MPIDI_MVP_tuning_data tuning_data;
int MPIDI_MVP_extract_json_file(const char *json_filename, char **json_ptr);
int MPIDI_MVP_initialize_tuning_data_struct(void);
int MPIDI_MVP_set_intra_node_tunables();


/****** General Arch break down
 * For reference, the values are meant to be stored as whole numbers directly.
 * Easier to deal with, frankly. --michalowicz.2 
 *      {
 *          "cache<={XYZ kB}":  // Or "cache=any"
 *          {
 *              "coop_threshold=<value>":{}
 *          },
 *          "RAM=any": // Or "RAM<={XYZ gB}"
 *          {
 *              "intra_eager_size=<value>":{}
 *          }
 *      }
 */

#define SMP_EAGER_SZ_KEY "intra_eager_size="
#define SMP_COOP_SZ_KEY "coop_threshold="


#endif /* __INTRA_TUNING_H__ */
