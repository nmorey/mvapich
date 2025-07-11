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

int yaksuri_seqi_pack_resized_c_double_complex(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                YAKSURI_SEQI_OP_REPLACE(*((const double _Complex *) (const void *) (sbuf + i * extent)), *((double _Complex *) (void *) (dbuf + idx)));
                idx += sizeof(double _Complex);
            }
            break;
        }
        
        case YAKSA_OP__PROD:
        {
            for (intptr_t i = 0; i < count; i++) {
                YAKSURI_SEQI_OP_PROD(*((const double _Complex *) (const void *) (sbuf + i * extent)), *((double _Complex *) (void *) (dbuf + idx)));
                idx += sizeof(double _Complex);
            }
            break;
        }
        
        case YAKSA_OP__SUM:
        {
            for (intptr_t i = 0; i < count; i++) {
                YAKSURI_SEQI_OP_SUM(*((const double _Complex *) (const void *) (sbuf + i * extent)), *((double _Complex *) (void *) (dbuf + idx)));
                idx += sizeof(double _Complex);
            }
            break;
        }
        
        default:
            break;
    }
    
    return rc;
}

int yaksuri_seqi_unpack_resized_c_double_complex(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    uintptr_t extent1 ATTRIBUTE((unused)) = type->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                YAKSURI_SEQI_OP_REPLACE(*((const double _Complex *) (const void *) (sbuf + idx)), *((double _Complex *) (void *) (dbuf + i * extent)));
                idx += sizeof(double _Complex);
            }
            break;
        }
        
        case YAKSA_OP__PROD:
        {
            for (intptr_t i = 0; i < count; i++) {
                YAKSURI_SEQI_OP_PROD(*((const double _Complex *) (const void *) (sbuf + idx)), *((double _Complex *) (void *) (dbuf + i * extent)));
                idx += sizeof(double _Complex);
            }
            break;
        }
        
        case YAKSA_OP__SUM:
        {
            for (intptr_t i = 0; i < count; i++) {
                YAKSURI_SEQI_OP_SUM(*((const double _Complex *) (const void *) (sbuf + idx)), *((double _Complex *) (void *) (dbuf + i * extent)));
                idx += sizeof(double _Complex);
            }
            break;
        }
        
        default:
            break;
    }
    
    return rc;
}

