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
#ifndef MPIT_MV2_H
#define MPIT_MV2_H 1

void MPIT_REGISTER_MV2_VARIABLES (void);
void MPIT_MEM_REGISTER_PVARS (void);
void MPIT_FREE_MV2_VARIABLES (void);

void * MPIT_malloc (size_t, int, char const *);
void * MPIT_calloc (size_t, size_t, int, char const *);
void MPIT_free (void *, int, char const *);
char * MPIT_strdup (const char *, int, char const *);
void * MPIT_realloc (void *, size_t, int, char const *);
int MPIT_memalign (void **, size_t, size_t, int, char const *);

/* formerly contents of mpimem.h - all relating to PVARs */
#if ENABLE_PVAR_MEM
/* require that mpl_trmem.h be included first */
#ifndef MPL_H_INCLUDED
#error 'mv2_mpit.h requires that mpl.h be included first'
#endif

#include "mpl.h"

#undef MPL_malloc
#undef MPL_calloc
#undef MPL_free
#undef MPL_strdup
#undef MPL_realloc
#undef MPL_aligned_alloc

/* use the MPIT versions of memory management functions. 
 * These are implemented using the MPICH MPL functions/macros and will behave
 * similarly but with the addition of the mpi_t memory management 
 */
#define MPL_malloc(a,b)             MPIT_malloc((a),(b),__LINE__,__FILE__)
#define MPL_calloc(a,b,c)           MPIT_calloc((a),(b),(c),__LINE__,__FILE__)
#define MPL_free(a)                 MPIT_free(a,__LINE__,__FILE__)
#define MPL_realloc(a,b,c)          MPIT_realloc((a),(b),(c),__LINE__,__FILE__)
#define MPL_aligned_alloc(a,b,c)    MPIT_aligned_alloc((a),(b),(c),__LINE__,__FILE__)

#define MPL_strdup(a)               MPIT_strdup(a, __LINE__, __FILE__)
#define MPL_realloc(a,b)            MPIT_realloc(a, b, __LINE__, __FILE__)
#define MPL_aligned_alloc(a,b,c)    MPIT_memalign(a, b, c, __LINE__, __FILE__)
/* compatability macro */
#define MPL_memalign(a,b,c)         MPIT_memalign(a, b, c, __LINE__, __FILE__)
#define MPL_memalign_Free(a)        MPIT_memalign_free(a, __LINE__, __FILE__)
#define MPL_shmdt(a)                MPIT_shmdt(a, __LINE__, __FILE__)

#else /* ENABLE_PVAR_MEM */
/*
 * Forward declaration of function used to call the real free function
 */
void Real_Free (void * ptr);
#define MPL_Memalign(a,b,c)         posix_memalign(a, b, c)
#define MPL_Memalign_Free(a)        Real_Free(a)
#define MPL_shmdt(a)                shmdt(a)

/* Memory PVAR Declarations */
static unsigned long long PVAR_LEVEL_mem_allocated;
static MPIR_T_pvar_watermark_t PVAR_HIGHWATERMARK_mem_allocated;
static unsigned long PVAR_COUNTER_num_malloc_calls;
static unsigned long PVAR_COUNTER_num_calloc_calls;
static unsigned long PVAR_COUNTER_num_memalign_calls;
static unsigned long PVAR_COUNTER_num_strdup_calls;
static unsigned long PVAR_COUNTER_num_realloc_calls;
static unsigned long PVAR_COUNTER_num_free_calls;
static unsigned long PVAR_COUNTER_num_memalign_free_calls;

typedef struct {
    void * addr;
    size_t size;
} MPIT_MEMORY_T;

#endif /* ENABLE_PVAR_MEM */
#endif
