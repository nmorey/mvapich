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

int yaksuri_seqi_pack_contig_hvector_blklen_1_long_double(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.contig.count;
    intptr_t stride1 = type->u.contig.child->extent;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count2 = type->u.contig.child->u.hvector.count;
    intptr_t blocklength2 ATTRIBUTE((unused)) = type->u.contig.child->u.hvector.blocklength;
    intptr_t stride2 = type->u.contig.child->u.hvector.stride;
    uintptr_t extent2 ATTRIBUTE((unused)) = type->u.contig.child->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__MAX:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 1; k2++) {
                            YAKSURI_SEQI_OP_MAX_FLOAT(long double, *((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < 1; k2++) {
                            YAKSURI_SEQI_OP_PROD(*((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 1; k2++) {
                            YAKSURI_SEQI_OP_REPLACE(*((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__MIN:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 1; k2++) {
                            YAKSURI_SEQI_OP_MIN_FLOAT(long double, *((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < 1; k2++) {
                            YAKSURI_SEQI_OP_SUM(*((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
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

int yaksuri_seqi_unpack_contig_hvector_blklen_1_long_double(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.contig.count;
    intptr_t stride1 = type->u.contig.child->extent;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count2 = type->u.contig.child->u.hvector.count;
    intptr_t blocklength2 ATTRIBUTE((unused)) = type->u.contig.child->u.hvector.blocklength;
    intptr_t stride2 = type->u.contig.child->u.hvector.stride;
    uintptr_t extent2 ATTRIBUTE((unused)) = type->u.contig.child->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__MAX:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 1; k2++) {
                            YAKSURI_SEQI_OP_MAX_FLOAT(long double, *((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < 1; k2++) {
                            YAKSURI_SEQI_OP_PROD(*((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 1; k2++) {
                            YAKSURI_SEQI_OP_REPLACE(*((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__MIN:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 1; k2++) {
                            YAKSURI_SEQI_OP_MIN_FLOAT(long double, *((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < 1; k2++) {
                            YAKSURI_SEQI_OP_SUM(*((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
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

int yaksuri_seqi_pack_contig_hvector_blklen_2_long_double(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.contig.count;
    intptr_t stride1 = type->u.contig.child->extent;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count2 = type->u.contig.child->u.hvector.count;
    intptr_t blocklength2 ATTRIBUTE((unused)) = type->u.contig.child->u.hvector.blocklength;
    intptr_t stride2 = type->u.contig.child->u.hvector.stride;
    uintptr_t extent2 ATTRIBUTE((unused)) = type->u.contig.child->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__MAX:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 2; k2++) {
                            YAKSURI_SEQI_OP_MAX_FLOAT(long double, *((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < 2; k2++) {
                            YAKSURI_SEQI_OP_PROD(*((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 2; k2++) {
                            YAKSURI_SEQI_OP_REPLACE(*((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__MIN:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 2; k2++) {
                            YAKSURI_SEQI_OP_MIN_FLOAT(long double, *((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < 2; k2++) {
                            YAKSURI_SEQI_OP_SUM(*((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
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

int yaksuri_seqi_unpack_contig_hvector_blklen_2_long_double(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.contig.count;
    intptr_t stride1 = type->u.contig.child->extent;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count2 = type->u.contig.child->u.hvector.count;
    intptr_t blocklength2 ATTRIBUTE((unused)) = type->u.contig.child->u.hvector.blocklength;
    intptr_t stride2 = type->u.contig.child->u.hvector.stride;
    uintptr_t extent2 ATTRIBUTE((unused)) = type->u.contig.child->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__MAX:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 2; k2++) {
                            YAKSURI_SEQI_OP_MAX_FLOAT(long double, *((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < 2; k2++) {
                            YAKSURI_SEQI_OP_PROD(*((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 2; k2++) {
                            YAKSURI_SEQI_OP_REPLACE(*((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__MIN:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 2; k2++) {
                            YAKSURI_SEQI_OP_MIN_FLOAT(long double, *((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < 2; k2++) {
                            YAKSURI_SEQI_OP_SUM(*((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
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

int yaksuri_seqi_pack_contig_hvector_blklen_3_long_double(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.contig.count;
    intptr_t stride1 = type->u.contig.child->extent;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count2 = type->u.contig.child->u.hvector.count;
    intptr_t blocklength2 ATTRIBUTE((unused)) = type->u.contig.child->u.hvector.blocklength;
    intptr_t stride2 = type->u.contig.child->u.hvector.stride;
    uintptr_t extent2 ATTRIBUTE((unused)) = type->u.contig.child->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__MAX:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 3; k2++) {
                            YAKSURI_SEQI_OP_MAX_FLOAT(long double, *((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < 3; k2++) {
                            YAKSURI_SEQI_OP_PROD(*((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 3; k2++) {
                            YAKSURI_SEQI_OP_REPLACE(*((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__MIN:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 3; k2++) {
                            YAKSURI_SEQI_OP_MIN_FLOAT(long double, *((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < 3; k2++) {
                            YAKSURI_SEQI_OP_SUM(*((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
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

int yaksuri_seqi_unpack_contig_hvector_blklen_3_long_double(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.contig.count;
    intptr_t stride1 = type->u.contig.child->extent;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count2 = type->u.contig.child->u.hvector.count;
    intptr_t blocklength2 ATTRIBUTE((unused)) = type->u.contig.child->u.hvector.blocklength;
    intptr_t stride2 = type->u.contig.child->u.hvector.stride;
    uintptr_t extent2 ATTRIBUTE((unused)) = type->u.contig.child->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__MAX:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 3; k2++) {
                            YAKSURI_SEQI_OP_MAX_FLOAT(long double, *((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < 3; k2++) {
                            YAKSURI_SEQI_OP_PROD(*((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 3; k2++) {
                            YAKSURI_SEQI_OP_REPLACE(*((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__MIN:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 3; k2++) {
                            YAKSURI_SEQI_OP_MIN_FLOAT(long double, *((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < 3; k2++) {
                            YAKSURI_SEQI_OP_SUM(*((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
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

int yaksuri_seqi_pack_contig_hvector_blklen_4_long_double(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.contig.count;
    intptr_t stride1 = type->u.contig.child->extent;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count2 = type->u.contig.child->u.hvector.count;
    intptr_t blocklength2 ATTRIBUTE((unused)) = type->u.contig.child->u.hvector.blocklength;
    intptr_t stride2 = type->u.contig.child->u.hvector.stride;
    uintptr_t extent2 ATTRIBUTE((unused)) = type->u.contig.child->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__MAX:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 4; k2++) {
                            YAKSURI_SEQI_OP_MAX_FLOAT(long double, *((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < 4; k2++) {
                            YAKSURI_SEQI_OP_PROD(*((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 4; k2++) {
                            YAKSURI_SEQI_OP_REPLACE(*((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__MIN:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 4; k2++) {
                            YAKSURI_SEQI_OP_MIN_FLOAT(long double, *((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < 4; k2++) {
                            YAKSURI_SEQI_OP_SUM(*((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
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

int yaksuri_seqi_unpack_contig_hvector_blklen_4_long_double(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.contig.count;
    intptr_t stride1 = type->u.contig.child->extent;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count2 = type->u.contig.child->u.hvector.count;
    intptr_t blocklength2 ATTRIBUTE((unused)) = type->u.contig.child->u.hvector.blocklength;
    intptr_t stride2 = type->u.contig.child->u.hvector.stride;
    uintptr_t extent2 ATTRIBUTE((unused)) = type->u.contig.child->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__MAX:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 4; k2++) {
                            YAKSURI_SEQI_OP_MAX_FLOAT(long double, *((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < 4; k2++) {
                            YAKSURI_SEQI_OP_PROD(*((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 4; k2++) {
                            YAKSURI_SEQI_OP_REPLACE(*((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__MIN:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 4; k2++) {
                            YAKSURI_SEQI_OP_MIN_FLOAT(long double, *((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < 4; k2++) {
                            YAKSURI_SEQI_OP_SUM(*((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
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

int yaksuri_seqi_pack_contig_hvector_blklen_5_long_double(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.contig.count;
    intptr_t stride1 = type->u.contig.child->extent;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count2 = type->u.contig.child->u.hvector.count;
    intptr_t blocklength2 ATTRIBUTE((unused)) = type->u.contig.child->u.hvector.blocklength;
    intptr_t stride2 = type->u.contig.child->u.hvector.stride;
    uintptr_t extent2 ATTRIBUTE((unused)) = type->u.contig.child->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__MAX:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 5; k2++) {
                            YAKSURI_SEQI_OP_MAX_FLOAT(long double, *((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < 5; k2++) {
                            YAKSURI_SEQI_OP_PROD(*((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 5; k2++) {
                            YAKSURI_SEQI_OP_REPLACE(*((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__MIN:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 5; k2++) {
                            YAKSURI_SEQI_OP_MIN_FLOAT(long double, *((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < 5; k2++) {
                            YAKSURI_SEQI_OP_SUM(*((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
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

int yaksuri_seqi_unpack_contig_hvector_blklen_5_long_double(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.contig.count;
    intptr_t stride1 = type->u.contig.child->extent;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count2 = type->u.contig.child->u.hvector.count;
    intptr_t blocklength2 ATTRIBUTE((unused)) = type->u.contig.child->u.hvector.blocklength;
    intptr_t stride2 = type->u.contig.child->u.hvector.stride;
    uintptr_t extent2 ATTRIBUTE((unused)) = type->u.contig.child->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__MAX:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 5; k2++) {
                            YAKSURI_SEQI_OP_MAX_FLOAT(long double, *((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < 5; k2++) {
                            YAKSURI_SEQI_OP_PROD(*((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 5; k2++) {
                            YAKSURI_SEQI_OP_REPLACE(*((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__MIN:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 5; k2++) {
                            YAKSURI_SEQI_OP_MIN_FLOAT(long double, *((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < 5; k2++) {
                            YAKSURI_SEQI_OP_SUM(*((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
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

int yaksuri_seqi_pack_contig_hvector_blklen_6_long_double(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.contig.count;
    intptr_t stride1 = type->u.contig.child->extent;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count2 = type->u.contig.child->u.hvector.count;
    intptr_t blocklength2 ATTRIBUTE((unused)) = type->u.contig.child->u.hvector.blocklength;
    intptr_t stride2 = type->u.contig.child->u.hvector.stride;
    uintptr_t extent2 ATTRIBUTE((unused)) = type->u.contig.child->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__MAX:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 6; k2++) {
                            YAKSURI_SEQI_OP_MAX_FLOAT(long double, *((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < 6; k2++) {
                            YAKSURI_SEQI_OP_PROD(*((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 6; k2++) {
                            YAKSURI_SEQI_OP_REPLACE(*((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__MIN:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 6; k2++) {
                            YAKSURI_SEQI_OP_MIN_FLOAT(long double, *((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < 6; k2++) {
                            YAKSURI_SEQI_OP_SUM(*((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
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

int yaksuri_seqi_unpack_contig_hvector_blklen_6_long_double(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.contig.count;
    intptr_t stride1 = type->u.contig.child->extent;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count2 = type->u.contig.child->u.hvector.count;
    intptr_t blocklength2 ATTRIBUTE((unused)) = type->u.contig.child->u.hvector.blocklength;
    intptr_t stride2 = type->u.contig.child->u.hvector.stride;
    uintptr_t extent2 ATTRIBUTE((unused)) = type->u.contig.child->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__MAX:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 6; k2++) {
                            YAKSURI_SEQI_OP_MAX_FLOAT(long double, *((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < 6; k2++) {
                            YAKSURI_SEQI_OP_PROD(*((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 6; k2++) {
                            YAKSURI_SEQI_OP_REPLACE(*((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__MIN:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 6; k2++) {
                            YAKSURI_SEQI_OP_MIN_FLOAT(long double, *((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < 6; k2++) {
                            YAKSURI_SEQI_OP_SUM(*((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
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

int yaksuri_seqi_pack_contig_hvector_blklen_7_long_double(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.contig.count;
    intptr_t stride1 = type->u.contig.child->extent;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count2 = type->u.contig.child->u.hvector.count;
    intptr_t blocklength2 ATTRIBUTE((unused)) = type->u.contig.child->u.hvector.blocklength;
    intptr_t stride2 = type->u.contig.child->u.hvector.stride;
    uintptr_t extent2 ATTRIBUTE((unused)) = type->u.contig.child->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__MAX:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 7; k2++) {
                            YAKSURI_SEQI_OP_MAX_FLOAT(long double, *((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < 7; k2++) {
                            YAKSURI_SEQI_OP_PROD(*((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 7; k2++) {
                            YAKSURI_SEQI_OP_REPLACE(*((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__MIN:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 7; k2++) {
                            YAKSURI_SEQI_OP_MIN_FLOAT(long double, *((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < 7; k2++) {
                            YAKSURI_SEQI_OP_SUM(*((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
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

int yaksuri_seqi_unpack_contig_hvector_blklen_7_long_double(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.contig.count;
    intptr_t stride1 = type->u.contig.child->extent;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count2 = type->u.contig.child->u.hvector.count;
    intptr_t blocklength2 ATTRIBUTE((unused)) = type->u.contig.child->u.hvector.blocklength;
    intptr_t stride2 = type->u.contig.child->u.hvector.stride;
    uintptr_t extent2 ATTRIBUTE((unused)) = type->u.contig.child->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__MAX:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 7; k2++) {
                            YAKSURI_SEQI_OP_MAX_FLOAT(long double, *((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < 7; k2++) {
                            YAKSURI_SEQI_OP_PROD(*((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 7; k2++) {
                            YAKSURI_SEQI_OP_REPLACE(*((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__MIN:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 7; k2++) {
                            YAKSURI_SEQI_OP_MIN_FLOAT(long double, *((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < 7; k2++) {
                            YAKSURI_SEQI_OP_SUM(*((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
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

int yaksuri_seqi_pack_contig_hvector_blklen_8_long_double(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.contig.count;
    intptr_t stride1 = type->u.contig.child->extent;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count2 = type->u.contig.child->u.hvector.count;
    intptr_t blocklength2 ATTRIBUTE((unused)) = type->u.contig.child->u.hvector.blocklength;
    intptr_t stride2 = type->u.contig.child->u.hvector.stride;
    uintptr_t extent2 ATTRIBUTE((unused)) = type->u.contig.child->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__MAX:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 8; k2++) {
                            YAKSURI_SEQI_OP_MAX_FLOAT(long double, *((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < 8; k2++) {
                            YAKSURI_SEQI_OP_PROD(*((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 8; k2++) {
                            YAKSURI_SEQI_OP_REPLACE(*((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__MIN:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 8; k2++) {
                            YAKSURI_SEQI_OP_MIN_FLOAT(long double, *((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < 8; k2++) {
                            YAKSURI_SEQI_OP_SUM(*((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
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

int yaksuri_seqi_unpack_contig_hvector_blklen_8_long_double(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.contig.count;
    intptr_t stride1 = type->u.contig.child->extent;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count2 = type->u.contig.child->u.hvector.count;
    intptr_t blocklength2 ATTRIBUTE((unused)) = type->u.contig.child->u.hvector.blocklength;
    intptr_t stride2 = type->u.contig.child->u.hvector.stride;
    uintptr_t extent2 ATTRIBUTE((unused)) = type->u.contig.child->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__MAX:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 8; k2++) {
                            YAKSURI_SEQI_OP_MAX_FLOAT(long double, *((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < 8; k2++) {
                            YAKSURI_SEQI_OP_PROD(*((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 8; k2++) {
                            YAKSURI_SEQI_OP_REPLACE(*((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__MIN:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < 8; k2++) {
                            YAKSURI_SEQI_OP_MIN_FLOAT(long double, *((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < 8; k2++) {
                            YAKSURI_SEQI_OP_SUM(*((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
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

int yaksuri_seqi_pack_contig_hvector_blklen_generic_long_double(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.contig.count;
    intptr_t stride1 = type->u.contig.child->extent;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count2 = type->u.contig.child->u.hvector.count;
    intptr_t blocklength2 ATTRIBUTE((unused)) = type->u.contig.child->u.hvector.blocklength;
    intptr_t stride2 = type->u.contig.child->u.hvector.stride;
    uintptr_t extent2 ATTRIBUTE((unused)) = type->u.contig.child->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__MAX:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < blocklength2; k2++) {
                            YAKSURI_SEQI_OP_MAX_FLOAT(long double, *((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < blocklength2; k2++) {
                            YAKSURI_SEQI_OP_PROD(*((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < blocklength2; k2++) {
                            YAKSURI_SEQI_OP_REPLACE(*((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__MIN:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < blocklength2; k2++) {
                            YAKSURI_SEQI_OP_MIN_FLOAT(long double, *((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < blocklength2; k2++) {
                            YAKSURI_SEQI_OP_SUM(*((const long double *) (const void *) (sbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))), *((long double *) (void *) (dbuf + idx)));
                            idx += sizeof(long double);
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

int yaksuri_seqi_unpack_contig_hvector_blklen_generic_long_double(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.contig.count;
    intptr_t stride1 = type->u.contig.child->extent;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count2 = type->u.contig.child->u.hvector.count;
    intptr_t blocklength2 ATTRIBUTE((unused)) = type->u.contig.child->u.hvector.blocklength;
    intptr_t stride2 = type->u.contig.child->u.hvector.stride;
    uintptr_t extent2 ATTRIBUTE((unused)) = type->u.contig.child->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__MAX:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < blocklength2; k2++) {
                            YAKSURI_SEQI_OP_MAX_FLOAT(long double, *((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < blocklength2; k2++) {
                            YAKSURI_SEQI_OP_PROD(*((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < blocklength2; k2++) {
                            YAKSURI_SEQI_OP_REPLACE(*((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
                        }
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__MIN:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t j2 = 0; j2 < count2; j2++) {
                        for (intptr_t k2 = 0; k2 < blocklength2; k2++) {
                            YAKSURI_SEQI_OP_MIN_FLOAT(long double, *((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
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
                        for (intptr_t k2 = 0; k2 < blocklength2; k2++) {
                            YAKSURI_SEQI_OP_SUM(*((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent + j1 * stride1 + j2 * stride2 + k2 * sizeof(long double))));
                            idx += sizeof(long double);
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

