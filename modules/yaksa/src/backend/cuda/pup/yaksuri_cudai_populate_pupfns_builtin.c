/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 *
 * DO NOT EDIT: AUTOMATICALLY GENERATED FILE !!
 */

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include "yaksi.h"
#include "yaksu.h"
#include "yaksuri_cudai.h"
#include "yaksuri_cudai_populate_pupfns.h"
#include "yaksuri_cudai_pup.h"

int yaksuri_cudai_populate_pupfns_builtin(yaksi_type_s * type)
{
    int rc = YAKSA_SUCCESS;
    yaksuri_cudai_type_s *cuda = (yaksuri_cudai_type_s *) type->backend.cuda.priv;
    
    switch (type->u.builtin.handle) {
        case YAKSA_TYPE___BOOL:
        cuda->pack = yaksuri_cudai_pack__Bool;
        cuda->unpack = yaksuri_cudai_unpack__Bool;
        break;
        case YAKSA_TYPE__CHAR:
        cuda->pack = yaksuri_cudai_pack_char;
        cuda->unpack = yaksuri_cudai_unpack_char;
        break;
        case YAKSA_TYPE__WCHAR_T:
        cuda->pack = yaksuri_cudai_pack_wchar_t;
        cuda->unpack = yaksuri_cudai_unpack_wchar_t;
        break;
        case YAKSA_TYPE__INT8_T:
        cuda->pack = yaksuri_cudai_pack_int8_t;
        cuda->unpack = yaksuri_cudai_unpack_int8_t;
        break;
        case YAKSA_TYPE__INT16_T:
        cuda->pack = yaksuri_cudai_pack_int16_t;
        cuda->unpack = yaksuri_cudai_unpack_int16_t;
        break;
        case YAKSA_TYPE__INT32_T:
        cuda->pack = yaksuri_cudai_pack_int32_t;
        cuda->unpack = yaksuri_cudai_unpack_int32_t;
        break;
        case YAKSA_TYPE__INT64_T:
        cuda->pack = yaksuri_cudai_pack_int64_t;
        cuda->unpack = yaksuri_cudai_unpack_int64_t;
        break;
        case YAKSA_TYPE__FLOAT:
        cuda->pack = yaksuri_cudai_pack_float;
        cuda->unpack = yaksuri_cudai_unpack_float;
        break;
        case YAKSA_TYPE__DOUBLE:
        cuda->pack = yaksuri_cudai_pack_double;
        cuda->unpack = yaksuri_cudai_unpack_double;
        break;
        case YAKSA_TYPE__LONG_DOUBLE:
        cuda->pack = yaksuri_cudai_pack_double;
        cuda->unpack = yaksuri_cudai_unpack_double;
        break;
        default:
            break;
    }
    
    return rc;
}
