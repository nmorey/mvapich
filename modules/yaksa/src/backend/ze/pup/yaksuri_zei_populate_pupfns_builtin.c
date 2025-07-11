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
#include "yaksuri_zei.h"
#include "yaksuri_zei_populate_pupfns.h"
#include "yaksuri_zei_pup.h"

int yaksuri_zei_populate_pupfns_builtin(yaksi_type_s * type)
{
    int rc = YAKSA_SUCCESS;
    yaksuri_zei_type_s *ze = (yaksuri_zei_type_s *) type->backend.ze.priv;
    
    switch (type->u.builtin.handle) {
        case YAKSA_TYPE__CHAR:
        ze->pack[YAKSA_OP__REPLACE] = yaksuri_zei_pack_REPLACE_char;
        ze->unpack[YAKSA_OP__REPLACE] = yaksuri_zei_unpack_REPLACE_char;
        ze->name = "yaksuri_zei_op_char";
        break;
        case YAKSA_TYPE__INT8_T:
        ze->pack[YAKSA_OP__PROD] = yaksuri_zei_pack_PROD_int8_t;
        ze->unpack[YAKSA_OP__PROD] = yaksuri_zei_unpack_PROD_int8_t;
        ze->pack[YAKSA_OP__BOR] = yaksuri_zei_pack_BOR_int8_t;
        ze->unpack[YAKSA_OP__BOR] = yaksuri_zei_unpack_BOR_int8_t;
        ze->pack[YAKSA_OP__BAND] = yaksuri_zei_pack_BAND_int8_t;
        ze->unpack[YAKSA_OP__BAND] = yaksuri_zei_unpack_BAND_int8_t;
        ze->pack[YAKSA_OP__REPLACE] = yaksuri_zei_pack_REPLACE_int8_t;
        ze->unpack[YAKSA_OP__REPLACE] = yaksuri_zei_unpack_REPLACE_int8_t;
        ze->pack[YAKSA_OP__LXOR] = yaksuri_zei_pack_LXOR_int8_t;
        ze->unpack[YAKSA_OP__LXOR] = yaksuri_zei_unpack_LXOR_int8_t;
        ze->pack[YAKSA_OP__MAX] = yaksuri_zei_pack_MAX_int8_t;
        ze->unpack[YAKSA_OP__MAX] = yaksuri_zei_unpack_MAX_int8_t;
        ze->pack[YAKSA_OP__LAND] = yaksuri_zei_pack_LAND_int8_t;
        ze->unpack[YAKSA_OP__LAND] = yaksuri_zei_unpack_LAND_int8_t;
        ze->pack[YAKSA_OP__BXOR] = yaksuri_zei_pack_BXOR_int8_t;
        ze->unpack[YAKSA_OP__BXOR] = yaksuri_zei_unpack_BXOR_int8_t;
        ze->pack[YAKSA_OP__SUM] = yaksuri_zei_pack_SUM_int8_t;
        ze->unpack[YAKSA_OP__SUM] = yaksuri_zei_unpack_SUM_int8_t;
        ze->pack[YAKSA_OP__MIN] = yaksuri_zei_pack_MIN_int8_t;
        ze->unpack[YAKSA_OP__MIN] = yaksuri_zei_unpack_MIN_int8_t;
        ze->pack[YAKSA_OP__LOR] = yaksuri_zei_pack_LOR_int8_t;
        ze->unpack[YAKSA_OP__LOR] = yaksuri_zei_unpack_LOR_int8_t;
        ze->name = "yaksuri_zei_op_int8_t";
        break;
        case YAKSA_TYPE__INT16_T:
        ze->pack[YAKSA_OP__PROD] = yaksuri_zei_pack_PROD_int16_t;
        ze->unpack[YAKSA_OP__PROD] = yaksuri_zei_unpack_PROD_int16_t;
        ze->pack[YAKSA_OP__BOR] = yaksuri_zei_pack_BOR_int16_t;
        ze->unpack[YAKSA_OP__BOR] = yaksuri_zei_unpack_BOR_int16_t;
        ze->pack[YAKSA_OP__BAND] = yaksuri_zei_pack_BAND_int16_t;
        ze->unpack[YAKSA_OP__BAND] = yaksuri_zei_unpack_BAND_int16_t;
        ze->pack[YAKSA_OP__REPLACE] = yaksuri_zei_pack_REPLACE_int16_t;
        ze->unpack[YAKSA_OP__REPLACE] = yaksuri_zei_unpack_REPLACE_int16_t;
        ze->pack[YAKSA_OP__LXOR] = yaksuri_zei_pack_LXOR_int16_t;
        ze->unpack[YAKSA_OP__LXOR] = yaksuri_zei_unpack_LXOR_int16_t;
        ze->pack[YAKSA_OP__MAX] = yaksuri_zei_pack_MAX_int16_t;
        ze->unpack[YAKSA_OP__MAX] = yaksuri_zei_unpack_MAX_int16_t;
        ze->pack[YAKSA_OP__LAND] = yaksuri_zei_pack_LAND_int16_t;
        ze->unpack[YAKSA_OP__LAND] = yaksuri_zei_unpack_LAND_int16_t;
        ze->pack[YAKSA_OP__BXOR] = yaksuri_zei_pack_BXOR_int16_t;
        ze->unpack[YAKSA_OP__BXOR] = yaksuri_zei_unpack_BXOR_int16_t;
        ze->pack[YAKSA_OP__SUM] = yaksuri_zei_pack_SUM_int16_t;
        ze->unpack[YAKSA_OP__SUM] = yaksuri_zei_unpack_SUM_int16_t;
        ze->pack[YAKSA_OP__MIN] = yaksuri_zei_pack_MIN_int16_t;
        ze->unpack[YAKSA_OP__MIN] = yaksuri_zei_unpack_MIN_int16_t;
        ze->pack[YAKSA_OP__LOR] = yaksuri_zei_pack_LOR_int16_t;
        ze->unpack[YAKSA_OP__LOR] = yaksuri_zei_unpack_LOR_int16_t;
        ze->name = "yaksuri_zei_op_int16_t";
        break;
        case YAKSA_TYPE__INT32_T:
        ze->pack[YAKSA_OP__PROD] = yaksuri_zei_pack_PROD_int32_t;
        ze->unpack[YAKSA_OP__PROD] = yaksuri_zei_unpack_PROD_int32_t;
        ze->pack[YAKSA_OP__BOR] = yaksuri_zei_pack_BOR_int32_t;
        ze->unpack[YAKSA_OP__BOR] = yaksuri_zei_unpack_BOR_int32_t;
        ze->pack[YAKSA_OP__BAND] = yaksuri_zei_pack_BAND_int32_t;
        ze->unpack[YAKSA_OP__BAND] = yaksuri_zei_unpack_BAND_int32_t;
        ze->pack[YAKSA_OP__REPLACE] = yaksuri_zei_pack_REPLACE_int32_t;
        ze->unpack[YAKSA_OP__REPLACE] = yaksuri_zei_unpack_REPLACE_int32_t;
        ze->pack[YAKSA_OP__LXOR] = yaksuri_zei_pack_LXOR_int32_t;
        ze->unpack[YAKSA_OP__LXOR] = yaksuri_zei_unpack_LXOR_int32_t;
        ze->pack[YAKSA_OP__MAX] = yaksuri_zei_pack_MAX_int32_t;
        ze->unpack[YAKSA_OP__MAX] = yaksuri_zei_unpack_MAX_int32_t;
        ze->pack[YAKSA_OP__LAND] = yaksuri_zei_pack_LAND_int32_t;
        ze->unpack[YAKSA_OP__LAND] = yaksuri_zei_unpack_LAND_int32_t;
        ze->pack[YAKSA_OP__BXOR] = yaksuri_zei_pack_BXOR_int32_t;
        ze->unpack[YAKSA_OP__BXOR] = yaksuri_zei_unpack_BXOR_int32_t;
        ze->pack[YAKSA_OP__SUM] = yaksuri_zei_pack_SUM_int32_t;
        ze->unpack[YAKSA_OP__SUM] = yaksuri_zei_unpack_SUM_int32_t;
        ze->pack[YAKSA_OP__MIN] = yaksuri_zei_pack_MIN_int32_t;
        ze->unpack[YAKSA_OP__MIN] = yaksuri_zei_unpack_MIN_int32_t;
        ze->pack[YAKSA_OP__LOR] = yaksuri_zei_pack_LOR_int32_t;
        ze->unpack[YAKSA_OP__LOR] = yaksuri_zei_unpack_LOR_int32_t;
        ze->name = "yaksuri_zei_op_int32_t";
        break;
        case YAKSA_TYPE__INT64_T:
        ze->pack[YAKSA_OP__PROD] = yaksuri_zei_pack_PROD_int64_t;
        ze->unpack[YAKSA_OP__PROD] = yaksuri_zei_unpack_PROD_int64_t;
        ze->pack[YAKSA_OP__BOR] = yaksuri_zei_pack_BOR_int64_t;
        ze->unpack[YAKSA_OP__BOR] = yaksuri_zei_unpack_BOR_int64_t;
        ze->pack[YAKSA_OP__BAND] = yaksuri_zei_pack_BAND_int64_t;
        ze->unpack[YAKSA_OP__BAND] = yaksuri_zei_unpack_BAND_int64_t;
        ze->pack[YAKSA_OP__REPLACE] = yaksuri_zei_pack_REPLACE_int64_t;
        ze->unpack[YAKSA_OP__REPLACE] = yaksuri_zei_unpack_REPLACE_int64_t;
        ze->pack[YAKSA_OP__LXOR] = yaksuri_zei_pack_LXOR_int64_t;
        ze->unpack[YAKSA_OP__LXOR] = yaksuri_zei_unpack_LXOR_int64_t;
        ze->pack[YAKSA_OP__MAX] = yaksuri_zei_pack_MAX_int64_t;
        ze->unpack[YAKSA_OP__MAX] = yaksuri_zei_unpack_MAX_int64_t;
        ze->pack[YAKSA_OP__LAND] = yaksuri_zei_pack_LAND_int64_t;
        ze->unpack[YAKSA_OP__LAND] = yaksuri_zei_unpack_LAND_int64_t;
        ze->pack[YAKSA_OP__BXOR] = yaksuri_zei_pack_BXOR_int64_t;
        ze->unpack[YAKSA_OP__BXOR] = yaksuri_zei_unpack_BXOR_int64_t;
        ze->pack[YAKSA_OP__SUM] = yaksuri_zei_pack_SUM_int64_t;
        ze->unpack[YAKSA_OP__SUM] = yaksuri_zei_unpack_SUM_int64_t;
        ze->pack[YAKSA_OP__MIN] = yaksuri_zei_pack_MIN_int64_t;
        ze->unpack[YAKSA_OP__MIN] = yaksuri_zei_unpack_MIN_int64_t;
        ze->pack[YAKSA_OP__LOR] = yaksuri_zei_pack_LOR_int64_t;
        ze->unpack[YAKSA_OP__LOR] = yaksuri_zei_unpack_LOR_int64_t;
        ze->name = "yaksuri_zei_op_int64_t";
        break;
        case YAKSA_TYPE__FLOAT:
        ze->pack[YAKSA_OP__PROD] = yaksuri_zei_pack_PROD_float;
        ze->unpack[YAKSA_OP__PROD] = yaksuri_zei_unpack_PROD_float;
        ze->pack[YAKSA_OP__REPLACE] = yaksuri_zei_pack_REPLACE_float;
        ze->unpack[YAKSA_OP__REPLACE] = yaksuri_zei_unpack_REPLACE_float;
        ze->pack[YAKSA_OP__MAX] = yaksuri_zei_pack_MAX_float;
        ze->unpack[YAKSA_OP__MAX] = yaksuri_zei_unpack_MAX_float;
        ze->pack[YAKSA_OP__SUM] = yaksuri_zei_pack_SUM_float;
        ze->unpack[YAKSA_OP__SUM] = yaksuri_zei_unpack_SUM_float;
        ze->pack[YAKSA_OP__MIN] = yaksuri_zei_pack_MIN_float;
        ze->unpack[YAKSA_OP__MIN] = yaksuri_zei_unpack_MIN_float;
        ze->name = "yaksuri_zei_op_float";
        break;
        case YAKSA_TYPE__DOUBLE:
        ze->pack[YAKSA_OP__PROD] = yaksuri_zei_pack_PROD_double;
        ze->unpack[YAKSA_OP__PROD] = yaksuri_zei_unpack_PROD_double;
        ze->pack[YAKSA_OP__REPLACE] = yaksuri_zei_pack_REPLACE_double;
        ze->unpack[YAKSA_OP__REPLACE] = yaksuri_zei_unpack_REPLACE_double;
        ze->pack[YAKSA_OP__MAX] = yaksuri_zei_pack_MAX_double;
        ze->unpack[YAKSA_OP__MAX] = yaksuri_zei_unpack_MAX_double;
        ze->pack[YAKSA_OP__SUM] = yaksuri_zei_pack_SUM_double;
        ze->unpack[YAKSA_OP__SUM] = yaksuri_zei_unpack_SUM_double;
        ze->pack[YAKSA_OP__MIN] = yaksuri_zei_pack_MIN_double;
        ze->unpack[YAKSA_OP__MIN] = yaksuri_zei_unpack_MIN_double;
        ze->name = "yaksuri_zei_op_double";
        break;
        case YAKSA_TYPE__C_COMPLEX:
        ze->pack[YAKSA_OP__REPLACE] = yaksuri_zei_pack_REPLACE_c_complex;
        ze->unpack[YAKSA_OP__REPLACE] = yaksuri_zei_unpack_REPLACE_c_complex;
        ze->pack[YAKSA_OP__PROD] = yaksuri_zei_pack_PROD_c_complex;
        ze->unpack[YAKSA_OP__PROD] = yaksuri_zei_unpack_PROD_c_complex;
        ze->pack[YAKSA_OP__SUM] = yaksuri_zei_pack_SUM_c_complex;
        ze->unpack[YAKSA_OP__SUM] = yaksuri_zei_unpack_SUM_c_complex;
        ze->name = "yaksuri_zei_op_c_complex";
        break;
        case YAKSA_TYPE__C_DOUBLE_COMPLEX:
        ze->pack[YAKSA_OP__REPLACE] = yaksuri_zei_pack_REPLACE_c_double_complex;
        ze->unpack[YAKSA_OP__REPLACE] = yaksuri_zei_unpack_REPLACE_c_double_complex;
        ze->pack[YAKSA_OP__PROD] = yaksuri_zei_pack_PROD_c_double_complex;
        ze->unpack[YAKSA_OP__PROD] = yaksuri_zei_unpack_PROD_c_double_complex;
        ze->pack[YAKSA_OP__SUM] = yaksuri_zei_pack_SUM_c_double_complex;
        ze->unpack[YAKSA_OP__SUM] = yaksuri_zei_unpack_SUM_c_double_complex;
        ze->name = "yaksuri_zei_op_c_double_complex";
        break;
        case YAKSA_TYPE__UNSIGNED_CHAR:
        ze->pack[YAKSA_OP__REPLACE] = yaksuri_zei_pack_REPLACE_char;
        ze->unpack[YAKSA_OP__REPLACE] = yaksuri_zei_unpack_REPLACE_char;
        ze->name = "yaksuri_zei_op_char";
        break;
        case YAKSA_TYPE__UINT8_T:
        ze->pack[YAKSA_OP__PROD] = yaksuri_zei_pack_PROD_int8_t;
        ze->unpack[YAKSA_OP__PROD] = yaksuri_zei_unpack_PROD_int8_t;
        ze->pack[YAKSA_OP__BOR] = yaksuri_zei_pack_BOR_int8_t;
        ze->unpack[YAKSA_OP__BOR] = yaksuri_zei_unpack_BOR_int8_t;
        ze->pack[YAKSA_OP__BAND] = yaksuri_zei_pack_BAND_int8_t;
        ze->unpack[YAKSA_OP__BAND] = yaksuri_zei_unpack_BAND_int8_t;
        ze->pack[YAKSA_OP__REPLACE] = yaksuri_zei_pack_REPLACE_int8_t;
        ze->unpack[YAKSA_OP__REPLACE] = yaksuri_zei_unpack_REPLACE_int8_t;
        ze->pack[YAKSA_OP__LXOR] = yaksuri_zei_pack_LXOR_int8_t;
        ze->unpack[YAKSA_OP__LXOR] = yaksuri_zei_unpack_LXOR_int8_t;
        ze->pack[YAKSA_OP__MAX] = yaksuri_zei_pack_MAX_int8_t;
        ze->unpack[YAKSA_OP__MAX] = yaksuri_zei_unpack_MAX_int8_t;
        ze->pack[YAKSA_OP__LAND] = yaksuri_zei_pack_LAND_int8_t;
        ze->unpack[YAKSA_OP__LAND] = yaksuri_zei_unpack_LAND_int8_t;
        ze->pack[YAKSA_OP__BXOR] = yaksuri_zei_pack_BXOR_int8_t;
        ze->unpack[YAKSA_OP__BXOR] = yaksuri_zei_unpack_BXOR_int8_t;
        ze->pack[YAKSA_OP__SUM] = yaksuri_zei_pack_SUM_int8_t;
        ze->unpack[YAKSA_OP__SUM] = yaksuri_zei_unpack_SUM_int8_t;
        ze->pack[YAKSA_OP__MIN] = yaksuri_zei_pack_MIN_int8_t;
        ze->unpack[YAKSA_OP__MIN] = yaksuri_zei_unpack_MIN_int8_t;
        ze->pack[YAKSA_OP__LOR] = yaksuri_zei_pack_LOR_int8_t;
        ze->unpack[YAKSA_OP__LOR] = yaksuri_zei_unpack_LOR_int8_t;
        ze->name = "yaksuri_zei_op_int8_t";
        break;
        case YAKSA_TYPE__UINT16_T:
        ze->pack[YAKSA_OP__PROD] = yaksuri_zei_pack_PROD_int16_t;
        ze->unpack[YAKSA_OP__PROD] = yaksuri_zei_unpack_PROD_int16_t;
        ze->pack[YAKSA_OP__BOR] = yaksuri_zei_pack_BOR_int16_t;
        ze->unpack[YAKSA_OP__BOR] = yaksuri_zei_unpack_BOR_int16_t;
        ze->pack[YAKSA_OP__BAND] = yaksuri_zei_pack_BAND_int16_t;
        ze->unpack[YAKSA_OP__BAND] = yaksuri_zei_unpack_BAND_int16_t;
        ze->pack[YAKSA_OP__REPLACE] = yaksuri_zei_pack_REPLACE_int16_t;
        ze->unpack[YAKSA_OP__REPLACE] = yaksuri_zei_unpack_REPLACE_int16_t;
        ze->pack[YAKSA_OP__LXOR] = yaksuri_zei_pack_LXOR_int16_t;
        ze->unpack[YAKSA_OP__LXOR] = yaksuri_zei_unpack_LXOR_int16_t;
        ze->pack[YAKSA_OP__MAX] = yaksuri_zei_pack_MAX_int16_t;
        ze->unpack[YAKSA_OP__MAX] = yaksuri_zei_unpack_MAX_int16_t;
        ze->pack[YAKSA_OP__LAND] = yaksuri_zei_pack_LAND_int16_t;
        ze->unpack[YAKSA_OP__LAND] = yaksuri_zei_unpack_LAND_int16_t;
        ze->pack[YAKSA_OP__BXOR] = yaksuri_zei_pack_BXOR_int16_t;
        ze->unpack[YAKSA_OP__BXOR] = yaksuri_zei_unpack_BXOR_int16_t;
        ze->pack[YAKSA_OP__SUM] = yaksuri_zei_pack_SUM_int16_t;
        ze->unpack[YAKSA_OP__SUM] = yaksuri_zei_unpack_SUM_int16_t;
        ze->pack[YAKSA_OP__MIN] = yaksuri_zei_pack_MIN_int16_t;
        ze->unpack[YAKSA_OP__MIN] = yaksuri_zei_unpack_MIN_int16_t;
        ze->pack[YAKSA_OP__LOR] = yaksuri_zei_pack_LOR_int16_t;
        ze->unpack[YAKSA_OP__LOR] = yaksuri_zei_unpack_LOR_int16_t;
        ze->name = "yaksuri_zei_op_int16_t";
        break;
        case YAKSA_TYPE__UINT32_T:
        ze->pack[YAKSA_OP__PROD] = yaksuri_zei_pack_PROD_int32_t;
        ze->unpack[YAKSA_OP__PROD] = yaksuri_zei_unpack_PROD_int32_t;
        ze->pack[YAKSA_OP__BOR] = yaksuri_zei_pack_BOR_int32_t;
        ze->unpack[YAKSA_OP__BOR] = yaksuri_zei_unpack_BOR_int32_t;
        ze->pack[YAKSA_OP__BAND] = yaksuri_zei_pack_BAND_int32_t;
        ze->unpack[YAKSA_OP__BAND] = yaksuri_zei_unpack_BAND_int32_t;
        ze->pack[YAKSA_OP__REPLACE] = yaksuri_zei_pack_REPLACE_int32_t;
        ze->unpack[YAKSA_OP__REPLACE] = yaksuri_zei_unpack_REPLACE_int32_t;
        ze->pack[YAKSA_OP__LXOR] = yaksuri_zei_pack_LXOR_int32_t;
        ze->unpack[YAKSA_OP__LXOR] = yaksuri_zei_unpack_LXOR_int32_t;
        ze->pack[YAKSA_OP__MAX] = yaksuri_zei_pack_MAX_int32_t;
        ze->unpack[YAKSA_OP__MAX] = yaksuri_zei_unpack_MAX_int32_t;
        ze->pack[YAKSA_OP__LAND] = yaksuri_zei_pack_LAND_int32_t;
        ze->unpack[YAKSA_OP__LAND] = yaksuri_zei_unpack_LAND_int32_t;
        ze->pack[YAKSA_OP__BXOR] = yaksuri_zei_pack_BXOR_int32_t;
        ze->unpack[YAKSA_OP__BXOR] = yaksuri_zei_unpack_BXOR_int32_t;
        ze->pack[YAKSA_OP__SUM] = yaksuri_zei_pack_SUM_int32_t;
        ze->unpack[YAKSA_OP__SUM] = yaksuri_zei_unpack_SUM_int32_t;
        ze->pack[YAKSA_OP__MIN] = yaksuri_zei_pack_MIN_int32_t;
        ze->unpack[YAKSA_OP__MIN] = yaksuri_zei_unpack_MIN_int32_t;
        ze->pack[YAKSA_OP__LOR] = yaksuri_zei_pack_LOR_int32_t;
        ze->unpack[YAKSA_OP__LOR] = yaksuri_zei_unpack_LOR_int32_t;
        ze->name = "yaksuri_zei_op_int32_t";
        break;
        case YAKSA_TYPE__UINT64_T:
        ze->pack[YAKSA_OP__PROD] = yaksuri_zei_pack_PROD_int64_t;
        ze->unpack[YAKSA_OP__PROD] = yaksuri_zei_unpack_PROD_int64_t;
        ze->pack[YAKSA_OP__BOR] = yaksuri_zei_pack_BOR_int64_t;
        ze->unpack[YAKSA_OP__BOR] = yaksuri_zei_unpack_BOR_int64_t;
        ze->pack[YAKSA_OP__BAND] = yaksuri_zei_pack_BAND_int64_t;
        ze->unpack[YAKSA_OP__BAND] = yaksuri_zei_unpack_BAND_int64_t;
        ze->pack[YAKSA_OP__REPLACE] = yaksuri_zei_pack_REPLACE_int64_t;
        ze->unpack[YAKSA_OP__REPLACE] = yaksuri_zei_unpack_REPLACE_int64_t;
        ze->pack[YAKSA_OP__LXOR] = yaksuri_zei_pack_LXOR_int64_t;
        ze->unpack[YAKSA_OP__LXOR] = yaksuri_zei_unpack_LXOR_int64_t;
        ze->pack[YAKSA_OP__MAX] = yaksuri_zei_pack_MAX_int64_t;
        ze->unpack[YAKSA_OP__MAX] = yaksuri_zei_unpack_MAX_int64_t;
        ze->pack[YAKSA_OP__LAND] = yaksuri_zei_pack_LAND_int64_t;
        ze->unpack[YAKSA_OP__LAND] = yaksuri_zei_unpack_LAND_int64_t;
        ze->pack[YAKSA_OP__BXOR] = yaksuri_zei_pack_BXOR_int64_t;
        ze->unpack[YAKSA_OP__BXOR] = yaksuri_zei_unpack_BXOR_int64_t;
        ze->pack[YAKSA_OP__SUM] = yaksuri_zei_pack_SUM_int64_t;
        ze->unpack[YAKSA_OP__SUM] = yaksuri_zei_unpack_SUM_int64_t;
        ze->pack[YAKSA_OP__MIN] = yaksuri_zei_pack_MIN_int64_t;
        ze->unpack[YAKSA_OP__MIN] = yaksuri_zei_unpack_MIN_int64_t;
        ze->pack[YAKSA_OP__LOR] = yaksuri_zei_pack_LOR_int64_t;
        ze->unpack[YAKSA_OP__LOR] = yaksuri_zei_unpack_LOR_int64_t;
        ze->name = "yaksuri_zei_op_int64_t";
        break;
        case YAKSA_TYPE__BYTE:
        ze->pack[YAKSA_OP__PROD] = yaksuri_zei_pack_PROD_int8_t;
        ze->unpack[YAKSA_OP__PROD] = yaksuri_zei_unpack_PROD_int8_t;
        ze->pack[YAKSA_OP__BOR] = yaksuri_zei_pack_BOR_int8_t;
        ze->unpack[YAKSA_OP__BOR] = yaksuri_zei_unpack_BOR_int8_t;
        ze->pack[YAKSA_OP__BAND] = yaksuri_zei_pack_BAND_int8_t;
        ze->unpack[YAKSA_OP__BAND] = yaksuri_zei_unpack_BAND_int8_t;
        ze->pack[YAKSA_OP__REPLACE] = yaksuri_zei_pack_REPLACE_int8_t;
        ze->unpack[YAKSA_OP__REPLACE] = yaksuri_zei_unpack_REPLACE_int8_t;
        ze->pack[YAKSA_OP__LXOR] = yaksuri_zei_pack_LXOR_int8_t;
        ze->unpack[YAKSA_OP__LXOR] = yaksuri_zei_unpack_LXOR_int8_t;
        ze->pack[YAKSA_OP__MAX] = yaksuri_zei_pack_MAX_int8_t;
        ze->unpack[YAKSA_OP__MAX] = yaksuri_zei_unpack_MAX_int8_t;
        ze->pack[YAKSA_OP__LAND] = yaksuri_zei_pack_LAND_int8_t;
        ze->unpack[YAKSA_OP__LAND] = yaksuri_zei_unpack_LAND_int8_t;
        ze->pack[YAKSA_OP__BXOR] = yaksuri_zei_pack_BXOR_int8_t;
        ze->unpack[YAKSA_OP__BXOR] = yaksuri_zei_unpack_BXOR_int8_t;
        ze->pack[YAKSA_OP__SUM] = yaksuri_zei_pack_SUM_int8_t;
        ze->unpack[YAKSA_OP__SUM] = yaksuri_zei_unpack_SUM_int8_t;
        ze->pack[YAKSA_OP__MIN] = yaksuri_zei_pack_MIN_int8_t;
        ze->unpack[YAKSA_OP__MIN] = yaksuri_zei_unpack_MIN_int8_t;
        ze->pack[YAKSA_OP__LOR] = yaksuri_zei_pack_LOR_int8_t;
        ze->unpack[YAKSA_OP__LOR] = yaksuri_zei_unpack_LOR_int8_t;
        ze->name = "yaksuri_zei_op_int8_t";
        break;
        default:
            break;
    }
    
    return rc;
}
