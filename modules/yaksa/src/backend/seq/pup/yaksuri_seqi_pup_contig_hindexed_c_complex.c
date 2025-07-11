/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 *
 * DO NOT EDIT: AUTOMATICALLY GENERATED FILE !!
 */

#include <string.h>
#include <stdint.h>
#include <wchar.h>
#include "yaksuri_seqi_pup.h"

int yaksuri_seqi_pack_contig_hindexed_c_complex(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.contig.count;
    intptr_t stride1 = type->u.contig.child->extent;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count2 = type->u.contig.child->u.hindexed.count;
    intptr_t *restrict array_of_blocklengths2 = type->u.contig.child->u.hindexed.array_of_blocklengths;
    intptr_t *restrict array_of_displs2 = type->u.contig.child->u.hindexed.array_of_displs;
    uintptr_t extent2 ATTRIBUTE((unused)) = type->u.contig.child->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < array_of_blocklengths2[j2]; k2++) {
                            YAKSURI_SEQI_OP_REPLACE(*((const float _Complex *) (const void *) (sbuf + i * extent + j1 * stride1 + array_of_displs2[j2] + k2 * sizeof(float _Complex))), *((float _Complex *) (void *) (dbuf + idx)));
                            idx += sizeof(float _Complex);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__PROD:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < array_of_blocklengths2[j2]; k2++) {
                            YAKSURI_SEQI_OP_PROD(*((const float _Complex *) (const void *) (sbuf + i * extent + j1 * stride1 + array_of_displs2[j2] + k2 * sizeof(float _Complex))), *((float _Complex *) (void *) (dbuf + idx)));
                            idx += sizeof(float _Complex);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__SUM:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < array_of_blocklengths2[j2]; k2++) {
                            YAKSURI_SEQI_OP_SUM(*((const float _Complex *) (const void *) (sbuf + i * extent + j1 * stride1 + array_of_displs2[j2] + k2 * sizeof(float _Complex))), *((float _Complex *) (void *) (dbuf + idx)));
                            idx += sizeof(float _Complex);
                        }
                    }
                }
            }
            break;
        }
        
        default:
            break;
    }
    
    return rc;
}

int yaksuri_seqi_unpack_contig_hindexed_c_complex(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.contig.count;
    intptr_t stride1 = type->u.contig.child->extent;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count2 = type->u.contig.child->u.hindexed.count;
    intptr_t *restrict array_of_blocklengths2 = type->u.contig.child->u.hindexed.array_of_blocklengths;
    intptr_t *restrict array_of_displs2 = type->u.contig.child->u.hindexed.array_of_displs;
    uintptr_t extent2 ATTRIBUTE((unused)) = type->u.contig.child->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < array_of_blocklengths2[j2]; k2++) {
                            YAKSURI_SEQI_OP_REPLACE(*((const float _Complex *) (const void *) (sbuf + idx)), *((float _Complex *) (void *) (dbuf + i * extent + j1 * stride1 + array_of_displs2[j2] + k2 * sizeof(float _Complex))));
                            idx += sizeof(float _Complex);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__PROD:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < array_of_blocklengths2[j2]; k2++) {
                            YAKSURI_SEQI_OP_PROD(*((const float _Complex *) (const void *) (sbuf + idx)), *((float _Complex *) (void *) (dbuf + i * extent + j1 * stride1 + array_of_displs2[j2] + k2 * sizeof(float _Complex))));
                            idx += sizeof(float _Complex);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__SUM:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < array_of_blocklengths2[j2]; k2++) {
                            YAKSURI_SEQI_OP_SUM(*((const float _Complex *) (const void *) (sbuf + idx)), *((float _Complex *) (void *) (dbuf + i * extent + j1 * stride1 + array_of_displs2[j2] + k2 * sizeof(float _Complex))));
                            idx += sizeof(float _Complex);
                        }
                    }
                }
            }
            break;
        }
        
        default:
            break;
    }
    
    return rc;
}

