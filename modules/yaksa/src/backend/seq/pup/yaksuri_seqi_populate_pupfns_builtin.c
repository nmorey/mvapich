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
#include "yaksuri_seqi.h"
#include "yaksuri_seqi_populate_pupfns.h"
#include "yaksuri_seqi_pup.h"

int yaksuri_seqi_populate_pupfns_builtin(yaksi_type_s * type)
{
    int rc = YAKSA_SUCCESS;
    yaksuri_seqi_type_s *seq = (yaksuri_seqi_type_s *) type->backend.seq.priv;
    
    switch (type->u.builtin.handle) {
        case YAKSA_TYPE___BOOL:
        seq->pack = yaksuri_seqi_pack__Bool;
        seq->unpack = yaksuri_seqi_unpack__Bool;
        break;
        case YAKSA_TYPE__CHAR:
        seq->pack = yaksuri_seqi_pack_char;
        seq->unpack = yaksuri_seqi_unpack_char;
        break;
        case YAKSA_TYPE__WCHAR_T:
        seq->pack = yaksuri_seqi_pack_wchar_t;
        seq->unpack = yaksuri_seqi_unpack_wchar_t;
        break;
        case YAKSA_TYPE__INT8_T:
        seq->pack = yaksuri_seqi_pack_int8_t;
        seq->unpack = yaksuri_seqi_unpack_int8_t;
        break;
        case YAKSA_TYPE__INT16_T:
        seq->pack = yaksuri_seqi_pack_int16_t;
        seq->unpack = yaksuri_seqi_unpack_int16_t;
        break;
        case YAKSA_TYPE__INT32_T:
        seq->pack = yaksuri_seqi_pack_int32_t;
        seq->unpack = yaksuri_seqi_unpack_int32_t;
        break;
        case YAKSA_TYPE__INT64_T:
        seq->pack = yaksuri_seqi_pack_int64_t;
        seq->unpack = yaksuri_seqi_unpack_int64_t;
        break;
        case YAKSA_TYPE__FLOAT:
        seq->pack = yaksuri_seqi_pack_float;
        seq->unpack = yaksuri_seqi_unpack_float;
        break;
        case YAKSA_TYPE__DOUBLE:
        seq->pack = yaksuri_seqi_pack_double;
        seq->unpack = yaksuri_seqi_unpack_double;
        break;
        case YAKSA_TYPE__LONG_DOUBLE:
        seq->pack = yaksuri_seqi_pack_long_double;
        seq->unpack = yaksuri_seqi_unpack_long_double;
        break;
        case YAKSA_TYPE__C_COMPLEX:
        seq->pack = yaksuri_seqi_pack_c_complex;
        seq->unpack = yaksuri_seqi_unpack_c_complex;
        break;
        case YAKSA_TYPE__C_DOUBLE_COMPLEX:
        seq->pack = yaksuri_seqi_pack_c_double_complex;
        seq->unpack = yaksuri_seqi_unpack_c_double_complex;
        break;
        case YAKSA_TYPE__C_LONG_DOUBLE_COMPLEX:
        seq->pack = yaksuri_seqi_pack_c_long_double_complex;
        seq->unpack = yaksuri_seqi_unpack_c_long_double_complex;
        break;
        default:
            break;
    }
    
    return rc;
}
