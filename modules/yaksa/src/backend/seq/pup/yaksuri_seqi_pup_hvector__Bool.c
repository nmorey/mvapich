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

int yaksuri_seqi_pack_hvector_blklen_1__Bool(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.hvector.count;
    intptr_t blocklength1 ATTRIBUTE((unused)) = type->u.hvector.blocklength;
    intptr_t stride1 = type->u.hvector.stride;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 1; k1++) {
                        YAKSURI_SEQI_OP_REPLACE(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 1; k1++) {
                        YAKSURI_SEQI_OP_LOR(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LXOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 1; k1++) {
                        YAKSURI_SEQI_OP_LXOR(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LAND:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 1; k1++) {
                        YAKSURI_SEQI_OP_LAND(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
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

int yaksuri_seqi_unpack_hvector_blklen_1__Bool(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.hvector.count;
    intptr_t blocklength1 ATTRIBUTE((unused)) = type->u.hvector.blocklength;
    intptr_t stride1 = type->u.hvector.stride;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 1; k1++) {
                        YAKSURI_SEQI_OP_REPLACE(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 1; k1++) {
                        YAKSURI_SEQI_OP_LOR(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LXOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 1; k1++) {
                        YAKSURI_SEQI_OP_LXOR(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LAND:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 1; k1++) {
                        YAKSURI_SEQI_OP_LAND(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
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

int yaksuri_seqi_pack_hvector_blklen_2__Bool(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.hvector.count;
    intptr_t blocklength1 ATTRIBUTE((unused)) = type->u.hvector.blocklength;
    intptr_t stride1 = type->u.hvector.stride;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 2; k1++) {
                        YAKSURI_SEQI_OP_REPLACE(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 2; k1++) {
                        YAKSURI_SEQI_OP_LOR(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LXOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 2; k1++) {
                        YAKSURI_SEQI_OP_LXOR(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LAND:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 2; k1++) {
                        YAKSURI_SEQI_OP_LAND(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
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

int yaksuri_seqi_unpack_hvector_blklen_2__Bool(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.hvector.count;
    intptr_t blocklength1 ATTRIBUTE((unused)) = type->u.hvector.blocklength;
    intptr_t stride1 = type->u.hvector.stride;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 2; k1++) {
                        YAKSURI_SEQI_OP_REPLACE(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 2; k1++) {
                        YAKSURI_SEQI_OP_LOR(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LXOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 2; k1++) {
                        YAKSURI_SEQI_OP_LXOR(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LAND:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 2; k1++) {
                        YAKSURI_SEQI_OP_LAND(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
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

int yaksuri_seqi_pack_hvector_blklen_3__Bool(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.hvector.count;
    intptr_t blocklength1 ATTRIBUTE((unused)) = type->u.hvector.blocklength;
    intptr_t stride1 = type->u.hvector.stride;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 3; k1++) {
                        YAKSURI_SEQI_OP_REPLACE(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 3; k1++) {
                        YAKSURI_SEQI_OP_LOR(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LXOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 3; k1++) {
                        YAKSURI_SEQI_OP_LXOR(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LAND:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 3; k1++) {
                        YAKSURI_SEQI_OP_LAND(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
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

int yaksuri_seqi_unpack_hvector_blklen_3__Bool(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.hvector.count;
    intptr_t blocklength1 ATTRIBUTE((unused)) = type->u.hvector.blocklength;
    intptr_t stride1 = type->u.hvector.stride;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 3; k1++) {
                        YAKSURI_SEQI_OP_REPLACE(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 3; k1++) {
                        YAKSURI_SEQI_OP_LOR(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LXOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 3; k1++) {
                        YAKSURI_SEQI_OP_LXOR(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LAND:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 3; k1++) {
                        YAKSURI_SEQI_OP_LAND(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
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

int yaksuri_seqi_pack_hvector_blklen_4__Bool(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.hvector.count;
    intptr_t blocklength1 ATTRIBUTE((unused)) = type->u.hvector.blocklength;
    intptr_t stride1 = type->u.hvector.stride;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 4; k1++) {
                        YAKSURI_SEQI_OP_REPLACE(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 4; k1++) {
                        YAKSURI_SEQI_OP_LOR(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LXOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 4; k1++) {
                        YAKSURI_SEQI_OP_LXOR(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LAND:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 4; k1++) {
                        YAKSURI_SEQI_OP_LAND(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
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

int yaksuri_seqi_unpack_hvector_blklen_4__Bool(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.hvector.count;
    intptr_t blocklength1 ATTRIBUTE((unused)) = type->u.hvector.blocklength;
    intptr_t stride1 = type->u.hvector.stride;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 4; k1++) {
                        YAKSURI_SEQI_OP_REPLACE(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 4; k1++) {
                        YAKSURI_SEQI_OP_LOR(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LXOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 4; k1++) {
                        YAKSURI_SEQI_OP_LXOR(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LAND:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 4; k1++) {
                        YAKSURI_SEQI_OP_LAND(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
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

int yaksuri_seqi_pack_hvector_blklen_5__Bool(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.hvector.count;
    intptr_t blocklength1 ATTRIBUTE((unused)) = type->u.hvector.blocklength;
    intptr_t stride1 = type->u.hvector.stride;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 5; k1++) {
                        YAKSURI_SEQI_OP_REPLACE(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 5; k1++) {
                        YAKSURI_SEQI_OP_LOR(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LXOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 5; k1++) {
                        YAKSURI_SEQI_OP_LXOR(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LAND:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 5; k1++) {
                        YAKSURI_SEQI_OP_LAND(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
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

int yaksuri_seqi_unpack_hvector_blklen_5__Bool(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.hvector.count;
    intptr_t blocklength1 ATTRIBUTE((unused)) = type->u.hvector.blocklength;
    intptr_t stride1 = type->u.hvector.stride;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 5; k1++) {
                        YAKSURI_SEQI_OP_REPLACE(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 5; k1++) {
                        YAKSURI_SEQI_OP_LOR(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LXOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 5; k1++) {
                        YAKSURI_SEQI_OP_LXOR(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LAND:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 5; k1++) {
                        YAKSURI_SEQI_OP_LAND(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
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

int yaksuri_seqi_pack_hvector_blklen_6__Bool(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.hvector.count;
    intptr_t blocklength1 ATTRIBUTE((unused)) = type->u.hvector.blocklength;
    intptr_t stride1 = type->u.hvector.stride;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 6; k1++) {
                        YAKSURI_SEQI_OP_REPLACE(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 6; k1++) {
                        YAKSURI_SEQI_OP_LOR(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LXOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 6; k1++) {
                        YAKSURI_SEQI_OP_LXOR(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LAND:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 6; k1++) {
                        YAKSURI_SEQI_OP_LAND(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
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

int yaksuri_seqi_unpack_hvector_blklen_6__Bool(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.hvector.count;
    intptr_t blocklength1 ATTRIBUTE((unused)) = type->u.hvector.blocklength;
    intptr_t stride1 = type->u.hvector.stride;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 6; k1++) {
                        YAKSURI_SEQI_OP_REPLACE(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 6; k1++) {
                        YAKSURI_SEQI_OP_LOR(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LXOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 6; k1++) {
                        YAKSURI_SEQI_OP_LXOR(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LAND:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 6; k1++) {
                        YAKSURI_SEQI_OP_LAND(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
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

int yaksuri_seqi_pack_hvector_blklen_7__Bool(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.hvector.count;
    intptr_t blocklength1 ATTRIBUTE((unused)) = type->u.hvector.blocklength;
    intptr_t stride1 = type->u.hvector.stride;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 7; k1++) {
                        YAKSURI_SEQI_OP_REPLACE(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 7; k1++) {
                        YAKSURI_SEQI_OP_LOR(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LXOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 7; k1++) {
                        YAKSURI_SEQI_OP_LXOR(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LAND:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 7; k1++) {
                        YAKSURI_SEQI_OP_LAND(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
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

int yaksuri_seqi_unpack_hvector_blklen_7__Bool(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.hvector.count;
    intptr_t blocklength1 ATTRIBUTE((unused)) = type->u.hvector.blocklength;
    intptr_t stride1 = type->u.hvector.stride;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 7; k1++) {
                        YAKSURI_SEQI_OP_REPLACE(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 7; k1++) {
                        YAKSURI_SEQI_OP_LOR(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LXOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 7; k1++) {
                        YAKSURI_SEQI_OP_LXOR(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LAND:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 7; k1++) {
                        YAKSURI_SEQI_OP_LAND(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
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

int yaksuri_seqi_pack_hvector_blklen_8__Bool(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.hvector.count;
    intptr_t blocklength1 ATTRIBUTE((unused)) = type->u.hvector.blocklength;
    intptr_t stride1 = type->u.hvector.stride;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 8; k1++) {
                        YAKSURI_SEQI_OP_REPLACE(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 8; k1++) {
                        YAKSURI_SEQI_OP_LOR(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LXOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 8; k1++) {
                        YAKSURI_SEQI_OP_LXOR(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LAND:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 8; k1++) {
                        YAKSURI_SEQI_OP_LAND(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
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

int yaksuri_seqi_unpack_hvector_blklen_8__Bool(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.hvector.count;
    intptr_t blocklength1 ATTRIBUTE((unused)) = type->u.hvector.blocklength;
    intptr_t stride1 = type->u.hvector.stride;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 8; k1++) {
                        YAKSURI_SEQI_OP_REPLACE(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 8; k1++) {
                        YAKSURI_SEQI_OP_LOR(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LXOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 8; k1++) {
                        YAKSURI_SEQI_OP_LXOR(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LAND:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < 8; k1++) {
                        YAKSURI_SEQI_OP_LAND(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
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

int yaksuri_seqi_pack_hvector_blklen_generic__Bool(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.hvector.count;
    intptr_t blocklength1 ATTRIBUTE((unused)) = type->u.hvector.blocklength;
    intptr_t stride1 = type->u.hvector.stride;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < blocklength1; k1++) {
                        YAKSURI_SEQI_OP_REPLACE(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < blocklength1; k1++) {
                        YAKSURI_SEQI_OP_LOR(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LXOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < blocklength1; k1++) {
                        YAKSURI_SEQI_OP_LXOR(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LAND:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < blocklength1; k1++) {
                        YAKSURI_SEQI_OP_LAND(*((const _Bool *) (const void *) (sbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))), *((_Bool *) (void *) (dbuf + idx)));
                        idx += sizeof(_Bool);
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

int yaksuri_seqi_unpack_hvector_blklen_generic__Bool(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    intptr_t count1 = type->u.hvector.count;
    intptr_t blocklength1 ATTRIBUTE((unused)) = type->u.hvector.blocklength;
    intptr_t stride1 = type->u.hvector.stride;
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < blocklength1; k1++) {
                        YAKSURI_SEQI_OP_REPLACE(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < blocklength1; k1++) {
                        YAKSURI_SEQI_OP_LOR(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LXOR:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < blocklength1; k1++) {
                        YAKSURI_SEQI_OP_LXOR(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
                    }
                }
            }
            break;
        }
        
        case YAKSA_OP__LAND:
        {
            for (intptr_t i = 0; i < count; i++) {
                for (intptr_t j1 = 0; j1 < count1; j1++) {
                    for (intptr_t k1 = 0; k1 < blocklength1; k1++) {
                        YAKSURI_SEQI_OP_LAND(*((const _Bool *) (const void *) (sbuf + idx)), *((_Bool *) (void *) (dbuf + i * extent + j1 * stride1 + k1 * sizeof(_Bool))));
                        idx += sizeof(_Bool);
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

