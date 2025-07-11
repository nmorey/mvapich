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

int yaksuri_seqi_pack_long_double(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__MAX:
        {
            for (intptr_t i = 0; i < count; i++) {
                YAKSURI_SEQI_OP_MAX_FLOAT(long double, *((const long double *) (const void *) (sbuf + i * extent)), *((long double *) (void *) (dbuf + idx)));
                idx += sizeof(long double);
            }
            break;
        }
        
        case YAKSA_OP__PROD:
        {
            for (intptr_t i = 0; i < count; i++) {
                YAKSURI_SEQI_OP_PROD(*((const long double *) (const void *) (sbuf + i * extent)), *((long double *) (void *) (dbuf + idx)));
                idx += sizeof(long double);
            }
            break;
        }
        
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                YAKSURI_SEQI_OP_REPLACE(*((const long double *) (const void *) (sbuf + i * extent)), *((long double *) (void *) (dbuf + idx)));
                idx += sizeof(long double);
            }
            break;
        }
        
        case YAKSA_OP__MIN:
        {
            for (intptr_t i = 0; i < count; i++) {
                YAKSURI_SEQI_OP_MIN_FLOAT(long double, *((const long double *) (const void *) (sbuf + i * extent)), *((long double *) (void *) (dbuf + idx)));
                idx += sizeof(long double);
            }
            break;
        }
        
        case YAKSA_OP__SUM:
        {
            for (intptr_t i = 0; i < count; i++) {
                YAKSURI_SEQI_OP_SUM(*((const long double *) (const void *) (sbuf + i * extent)), *((long double *) (void *) (dbuf + idx)));
                idx += sizeof(long double);
            }
            break;
        }
        
        default:
            break;
    }
    
    return rc;
}

int yaksuri_seqi_unpack_long_double(const void *inbuf, void *outbuf, uintptr_t count, yaksi_type_s * type, yaksa_op_t op)
{
    int rc = YAKSA_SUCCESS;
    const char *restrict sbuf = (const char *) inbuf;
    char *restrict dbuf = (char *) outbuf;
    uintptr_t extent ATTRIBUTE((unused)) = type->extent;
    
    uintptr_t idx = 0;
    switch (op) {
        case YAKSA_OP__MAX:
        {
            for (intptr_t i = 0; i < count; i++) {
                YAKSURI_SEQI_OP_MAX_FLOAT(long double, *((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent)));
                idx += sizeof(long double);
            }
            break;
        }
        
        case YAKSA_OP__PROD:
        {
            for (intptr_t i = 0; i < count; i++) {
                YAKSURI_SEQI_OP_PROD(*((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent)));
                idx += sizeof(long double);
            }
            break;
        }
        
        case YAKSA_OP__REPLACE:
        {
            for (intptr_t i = 0; i < count; i++) {
                YAKSURI_SEQI_OP_REPLACE(*((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent)));
                idx += sizeof(long double);
            }
            break;
        }
        
        case YAKSA_OP__MIN:
        {
            for (intptr_t i = 0; i < count; i++) {
                YAKSURI_SEQI_OP_MIN_FLOAT(long double, *((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent)));
                idx += sizeof(long double);
            }
            break;
        }
        
        case YAKSA_OP__SUM:
        {
            for (intptr_t i = 0; i < count; i++) {
                YAKSURI_SEQI_OP_SUM(*((const long double *) (const void *) (sbuf + idx)), *((long double *) (void *) (dbuf + i * extent)));
                idx += sizeof(long double);
            }
            break;
        }
        
        default:
            break;
    }
    
    return rc;
}

