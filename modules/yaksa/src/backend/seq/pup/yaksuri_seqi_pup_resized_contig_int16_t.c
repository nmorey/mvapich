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

int yaksuri_seqi_pack_resized_contig_int16_t(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count2 = type->u.resized.child->u.contig.count;
    intptr_t stride2 = type->u.resized.child->u.contig.child->extent;
    uintptr_t extent2 ATTRIBUTE((unused)) = type->u.resized.child->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__MAX:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j2 = 0; j2 < count2; j2++) {
                    YAKSURI_SEQI_OP_MAX(*((const int16_t *) (const void *) (sbuf + i * extent + j2 * stride2)), *((int16_t *) (void *) (dbuf + idx)));
                    idx += sizeof(int16_t);
                }
            }
            break;
        }
        
        case YAKSA_OP__LOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j2 = 0; j2 < count2; j2++) {
                    YAKSURI_SEQI_OP_LOR(*((const int16_t *) (const void *) (sbuf + i * extent + j2 * stride2)), *((int16_t *) (void *) (dbuf + idx)));
                    idx += sizeof(int16_t);
                }
            }
            break;
        }
        
        case YAKSA_OP__BAND:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j2 = 0; j2 < count2; j2++) {
                    YAKSURI_SEQI_OP_BAND(*((const int16_t *) (const void *) (sbuf + i * extent + j2 * stride2)), *((int16_t *) (void *) (dbuf + idx)));
                    idx += sizeof(int16_t);
                }
            }
            break;
        }
        
        case YAKSA_OP__BOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j2 = 0; j2 < count2; j2++) {
                    YAKSURI_SEQI_OP_BOR(*((const int16_t *) (const void *) (sbuf + i * extent + j2 * stride2)), *((int16_t *) (void *) (dbuf + idx)));
                    idx += sizeof(int16_t);
                }
            }
            break;
        }
        
        case YAKSA_OP__PROD:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j2 = 0; j2 < count2; j2++) {
                    YAKSURI_SEQI_OP_PROD(*((const int16_t *) (const void *) (sbuf + i * extent + j2 * stride2)), *((int16_t *) (void *) (dbuf + idx)));
                    idx += sizeof(int16_t);
                }
            }
            break;
        }
        
        case YAKSA_OP__LAND:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j2 = 0; j2 < count2; j2++) {
                    YAKSURI_SEQI_OP_LAND(*((const int16_t *) (const void *) (sbuf + i * extent + j2 * stride2)), *((int16_t *) (void *) (dbuf + idx)));
                    idx += sizeof(int16_t);
                }
            }
            break;
        }
        
        case YAKSA_OP__BXOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j2 = 0; j2 < count2; j2++) {
                    YAKSURI_SEQI_OP_BXOR(*((const int16_t *) (const void *) (sbuf + i * extent + j2 * stride2)), *((int16_t *) (void *) (dbuf + idx)));
                    idx += sizeof(int16_t);
                }
            }
            break;
        }
        
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j2 = 0; j2 < count2; j2++) {
                    YAKSURI_SEQI_OP_REPLACE(*((const int16_t *) (const void *) (sbuf + i * extent + j2 * stride2)), *((int16_t *) (void *) (dbuf + idx)));
                    idx += sizeof(int16_t);
                }
            }
            break;
        }
        
        case YAKSA_OP__MIN:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j2 = 0; j2 < count2; j2++) {
                    YAKSURI_SEQI_OP_MIN(*((const int16_t *) (const void *) (sbuf + i * extent + j2 * stride2)), *((int16_t *) (void *) (dbuf + idx)));
                    idx += sizeof(int16_t);
                }
            }
            break;
        }
        
        case YAKSA_OP__LXOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j2 = 0; j2 < count2; j2++) {
                    YAKSURI_SEQI_OP_LXOR(*((const int16_t *) (const void *) (sbuf + i * extent + j2 * stride2)), *((int16_t *) (void *) (dbuf + idx)));
                    idx += sizeof(int16_t);
                }
            }
            break;
        }
        
        case YAKSA_OP__SUM:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j2 = 0; j2 < count2; j2++) {
                    YAKSURI_SEQI_OP_SUM(*((const int16_t *) (const void *) (sbuf + i * extent + j2 * stride2)), *((int16_t *) (void *) (dbuf + idx)));
                    idx += sizeof(int16_t);
                }
            }
            break;
        }
        
        default:
            break;
    }
    
    return rc;
}

int yaksuri_seqi_unpack_resized_contig_int16_t(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count2 = type->u.resized.child->u.contig.count;
    intptr_t stride2 = type->u.resized.child->u.contig.child->extent;
    uintptr_t extent2 ATTRIBUTE((unused)) = type->u.resized.child->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__MAX:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j2 = 0; j2 < count2; j2++) {
                    YAKSURI_SEQI_OP_MAX(*((const int16_t *) (const void *) (sbuf + idx)), *((int16_t *) (void *) (dbuf + i * extent + j2 * stride2)));
                    idx += sizeof(int16_t);
                }
            }
            break;
        }
        
        case YAKSA_OP__LOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j2 = 0; j2 < count2; j2++) {
                    YAKSURI_SEQI_OP_LOR(*((const int16_t *) (const void *) (sbuf + idx)), *((int16_t *) (void *) (dbuf + i * extent + j2 * stride2)));
                    idx += sizeof(int16_t);
                }
            }
            break;
        }
        
        case YAKSA_OP__BAND:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j2 = 0; j2 < count2; j2++) {
                    YAKSURI_SEQI_OP_BAND(*((const int16_t *) (const void *) (sbuf + idx)), *((int16_t *) (void *) (dbuf + i * extent + j2 * stride2)));
                    idx += sizeof(int16_t);
                }
            }
            break;
        }
        
        case YAKSA_OP__BOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j2 = 0; j2 < count2; j2++) {
                    YAKSURI_SEQI_OP_BOR(*((const int16_t *) (const void *) (sbuf + idx)), *((int16_t *) (void *) (dbuf + i * extent + j2 * stride2)));
                    idx += sizeof(int16_t);
                }
            }
            break;
        }
        
        case YAKSA_OP__PROD:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j2 = 0; j2 < count2; j2++) {
                    YAKSURI_SEQI_OP_PROD(*((const int16_t *) (const void *) (sbuf + idx)), *((int16_t *) (void *) (dbuf + i * extent + j2 * stride2)));
                    idx += sizeof(int16_t);
                }
            }
            break;
        }
        
        case YAKSA_OP__LAND:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j2 = 0; j2 < count2; j2++) {
                    YAKSURI_SEQI_OP_LAND(*((const int16_t *) (const void *) (sbuf + idx)), *((int16_t *) (void *) (dbuf + i * extent + j2 * stride2)));
                    idx += sizeof(int16_t);
                }
            }
            break;
        }
        
        case YAKSA_OP__BXOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j2 = 0; j2 < count2; j2++) {
                    YAKSURI_SEQI_OP_BXOR(*((const int16_t *) (const void *) (sbuf + idx)), *((int16_t *) (void *) (dbuf + i * extent + j2 * stride2)));
                    idx += sizeof(int16_t);
                }
            }
            break;
        }
        
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j2 = 0; j2 < count2; j2++) {
                    YAKSURI_SEQI_OP_REPLACE(*((const int16_t *) (const void *) (sbuf + idx)), *((int16_t *) (void *) (dbuf + i * extent + j2 * stride2)));
                    idx += sizeof(int16_t);
                }
            }
            break;
        }
        
        case YAKSA_OP__MIN:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j2 = 0; j2 < count2; j2++) {
                    YAKSURI_SEQI_OP_MIN(*((const int16_t *) (const void *) (sbuf + idx)), *((int16_t *) (void *) (dbuf + i * extent + j2 * stride2)));
                    idx += sizeof(int16_t);
                }
            }
            break;
        }
        
        case YAKSA_OP__LXOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j2 = 0; j2 < count2; j2++) {
                    YAKSURI_SEQI_OP_LXOR(*((const int16_t *) (const void *) (sbuf + idx)), *((int16_t *) (void *) (dbuf + i * extent + j2 * stride2)));
                    idx += sizeof(int16_t);
                }
            }
            break;
        }
        
        case YAKSA_OP__SUM:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j2 = 0; j2 < count2; j2++) {
                    YAKSURI_SEQI_OP_SUM(*((const int16_t *) (const void *) (sbuf + idx)), *((int16_t *) (void *) (dbuf + i * extent + j2 * stride2)));
                    idx += sizeof(int16_t);
                }
            }
            break;
        }
        
        default:
            break;
    }
    
    return rc;
}

