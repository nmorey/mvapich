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

int yaksuri_zei_populate_pupfns_resized_blkhindx(yaksi_type_s * type)
{
    int rc = YAKSA_SUCCESS;
    yaksuri_zei_type_s *ze = (yaksuri_zei_type_s *) type->backend.ze.priv;
    
    char *str = getenv("YAKSA_ENV_MAX_NESTING_LEVEL");
    int max_nesting_level;
    if (str) {
        max_nesting_level = atoi(str);
    } else {
        max_nesting_level = YAKSI_ENV_DEFAULT_NESTING_LEVEL;
    }
    
    switch (type->u.resized.child->u.blkhindx.child->kind) {
        case YAKSI_TYPE_KIND__BUILTIN:
        switch (type->u.resized.child->u.blkhindx.child->u.builtin.handle) {
            case YAKSA_TYPE__CHAR:
            if (max_nesting_level >= 2) {
                ze->pack[YAKSA_OP__REPLACE] = yaksuri_zei_pack_REPLACE_resized_blkhindx_char;
                ze->unpack[YAKSA_OP__REPLACE] = yaksuri_zei_unpack_REPLACE_resized_blkhindx_char;
                ze->name = "yaksuri_zei_op_resized_blkhindx_char";
            }
            break;
            case YAKSA_TYPE__INT8_T:
            if (max_nesting_level >= 2) {
                ze->pack[YAKSA_OP__PROD] = yaksuri_zei_pack_PROD_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__PROD] = yaksuri_zei_unpack_PROD_resized_blkhindx_int8_t;
                ze->pack[YAKSA_OP__BOR] = yaksuri_zei_pack_BOR_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__BOR] = yaksuri_zei_unpack_BOR_resized_blkhindx_int8_t;
                ze->pack[YAKSA_OP__BAND] = yaksuri_zei_pack_BAND_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__BAND] = yaksuri_zei_unpack_BAND_resized_blkhindx_int8_t;
                ze->pack[YAKSA_OP__REPLACE] = yaksuri_zei_pack_REPLACE_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__REPLACE] = yaksuri_zei_unpack_REPLACE_resized_blkhindx_int8_t;
                ze->pack[YAKSA_OP__LXOR] = yaksuri_zei_pack_LXOR_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__LXOR] = yaksuri_zei_unpack_LXOR_resized_blkhindx_int8_t;
                ze->pack[YAKSA_OP__MAX] = yaksuri_zei_pack_MAX_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__MAX] = yaksuri_zei_unpack_MAX_resized_blkhindx_int8_t;
                ze->pack[YAKSA_OP__LAND] = yaksuri_zei_pack_LAND_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__LAND] = yaksuri_zei_unpack_LAND_resized_blkhindx_int8_t;
                ze->pack[YAKSA_OP__BXOR] = yaksuri_zei_pack_BXOR_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__BXOR] = yaksuri_zei_unpack_BXOR_resized_blkhindx_int8_t;
                ze->pack[YAKSA_OP__SUM] = yaksuri_zei_pack_SUM_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__SUM] = yaksuri_zei_unpack_SUM_resized_blkhindx_int8_t;
                ze->pack[YAKSA_OP__MIN] = yaksuri_zei_pack_MIN_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__MIN] = yaksuri_zei_unpack_MIN_resized_blkhindx_int8_t;
                ze->pack[YAKSA_OP__LOR] = yaksuri_zei_pack_LOR_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__LOR] = yaksuri_zei_unpack_LOR_resized_blkhindx_int8_t;
                ze->name = "yaksuri_zei_op_resized_blkhindx_int8_t";
            }
            break;
            case YAKSA_TYPE__INT16_T:
            if (max_nesting_level >= 2) {
                ze->pack[YAKSA_OP__PROD] = yaksuri_zei_pack_PROD_resized_blkhindx_int16_t;
                ze->unpack[YAKSA_OP__PROD] = yaksuri_zei_unpack_PROD_resized_blkhindx_int16_t;
                ze->pack[YAKSA_OP__BOR] = yaksuri_zei_pack_BOR_resized_blkhindx_int16_t;
                ze->unpack[YAKSA_OP__BOR] = yaksuri_zei_unpack_BOR_resized_blkhindx_int16_t;
                ze->pack[YAKSA_OP__BAND] = yaksuri_zei_pack_BAND_resized_blkhindx_int16_t;
                ze->unpack[YAKSA_OP__BAND] = yaksuri_zei_unpack_BAND_resized_blkhindx_int16_t;
                ze->pack[YAKSA_OP__REPLACE] = yaksuri_zei_pack_REPLACE_resized_blkhindx_int16_t;
                ze->unpack[YAKSA_OP__REPLACE] = yaksuri_zei_unpack_REPLACE_resized_blkhindx_int16_t;
                ze->pack[YAKSA_OP__LXOR] = yaksuri_zei_pack_LXOR_resized_blkhindx_int16_t;
                ze->unpack[YAKSA_OP__LXOR] = yaksuri_zei_unpack_LXOR_resized_blkhindx_int16_t;
                ze->pack[YAKSA_OP__MAX] = yaksuri_zei_pack_MAX_resized_blkhindx_int16_t;
                ze->unpack[YAKSA_OP__MAX] = yaksuri_zei_unpack_MAX_resized_blkhindx_int16_t;
                ze->pack[YAKSA_OP__LAND] = yaksuri_zei_pack_LAND_resized_blkhindx_int16_t;
                ze->unpack[YAKSA_OP__LAND] = yaksuri_zei_unpack_LAND_resized_blkhindx_int16_t;
                ze->pack[YAKSA_OP__BXOR] = yaksuri_zei_pack_BXOR_resized_blkhindx_int16_t;
                ze->unpack[YAKSA_OP__BXOR] = yaksuri_zei_unpack_BXOR_resized_blkhindx_int16_t;
                ze->pack[YAKSA_OP__SUM] = yaksuri_zei_pack_SUM_resized_blkhindx_int16_t;
                ze->unpack[YAKSA_OP__SUM] = yaksuri_zei_unpack_SUM_resized_blkhindx_int16_t;
                ze->pack[YAKSA_OP__MIN] = yaksuri_zei_pack_MIN_resized_blkhindx_int16_t;
                ze->unpack[YAKSA_OP__MIN] = yaksuri_zei_unpack_MIN_resized_blkhindx_int16_t;
                ze->pack[YAKSA_OP__LOR] = yaksuri_zei_pack_LOR_resized_blkhindx_int16_t;
                ze->unpack[YAKSA_OP__LOR] = yaksuri_zei_unpack_LOR_resized_blkhindx_int16_t;
                ze->name = "yaksuri_zei_op_resized_blkhindx_int16_t";
            }
            break;
            case YAKSA_TYPE__INT32_T:
            if (max_nesting_level >= 2) {
                ze->pack[YAKSA_OP__PROD] = yaksuri_zei_pack_PROD_resized_blkhindx_int32_t;
                ze->unpack[YAKSA_OP__PROD] = yaksuri_zei_unpack_PROD_resized_blkhindx_int32_t;
                ze->pack[YAKSA_OP__BOR] = yaksuri_zei_pack_BOR_resized_blkhindx_int32_t;
                ze->unpack[YAKSA_OP__BOR] = yaksuri_zei_unpack_BOR_resized_blkhindx_int32_t;
                ze->pack[YAKSA_OP__BAND] = yaksuri_zei_pack_BAND_resized_blkhindx_int32_t;
                ze->unpack[YAKSA_OP__BAND] = yaksuri_zei_unpack_BAND_resized_blkhindx_int32_t;
                ze->pack[YAKSA_OP__REPLACE] = yaksuri_zei_pack_REPLACE_resized_blkhindx_int32_t;
                ze->unpack[YAKSA_OP__REPLACE] = yaksuri_zei_unpack_REPLACE_resized_blkhindx_int32_t;
                ze->pack[YAKSA_OP__LXOR] = yaksuri_zei_pack_LXOR_resized_blkhindx_int32_t;
                ze->unpack[YAKSA_OP__LXOR] = yaksuri_zei_unpack_LXOR_resized_blkhindx_int32_t;
                ze->pack[YAKSA_OP__MAX] = yaksuri_zei_pack_MAX_resized_blkhindx_int32_t;
                ze->unpack[YAKSA_OP__MAX] = yaksuri_zei_unpack_MAX_resized_blkhindx_int32_t;
                ze->pack[YAKSA_OP__LAND] = yaksuri_zei_pack_LAND_resized_blkhindx_int32_t;
                ze->unpack[YAKSA_OP__LAND] = yaksuri_zei_unpack_LAND_resized_blkhindx_int32_t;
                ze->pack[YAKSA_OP__BXOR] = yaksuri_zei_pack_BXOR_resized_blkhindx_int32_t;
                ze->unpack[YAKSA_OP__BXOR] = yaksuri_zei_unpack_BXOR_resized_blkhindx_int32_t;
                ze->pack[YAKSA_OP__SUM] = yaksuri_zei_pack_SUM_resized_blkhindx_int32_t;
                ze->unpack[YAKSA_OP__SUM] = yaksuri_zei_unpack_SUM_resized_blkhindx_int32_t;
                ze->pack[YAKSA_OP__MIN] = yaksuri_zei_pack_MIN_resized_blkhindx_int32_t;
                ze->unpack[YAKSA_OP__MIN] = yaksuri_zei_unpack_MIN_resized_blkhindx_int32_t;
                ze->pack[YAKSA_OP__LOR] = yaksuri_zei_pack_LOR_resized_blkhindx_int32_t;
                ze->unpack[YAKSA_OP__LOR] = yaksuri_zei_unpack_LOR_resized_blkhindx_int32_t;
                ze->name = "yaksuri_zei_op_resized_blkhindx_int32_t";
            }
            break;
            case YAKSA_TYPE__INT64_T:
            if (max_nesting_level >= 2) {
                ze->pack[YAKSA_OP__PROD] = yaksuri_zei_pack_PROD_resized_blkhindx_int64_t;
                ze->unpack[YAKSA_OP__PROD] = yaksuri_zei_unpack_PROD_resized_blkhindx_int64_t;
                ze->pack[YAKSA_OP__BOR] = yaksuri_zei_pack_BOR_resized_blkhindx_int64_t;
                ze->unpack[YAKSA_OP__BOR] = yaksuri_zei_unpack_BOR_resized_blkhindx_int64_t;
                ze->pack[YAKSA_OP__BAND] = yaksuri_zei_pack_BAND_resized_blkhindx_int64_t;
                ze->unpack[YAKSA_OP__BAND] = yaksuri_zei_unpack_BAND_resized_blkhindx_int64_t;
                ze->pack[YAKSA_OP__REPLACE] = yaksuri_zei_pack_REPLACE_resized_blkhindx_int64_t;
                ze->unpack[YAKSA_OP__REPLACE] = yaksuri_zei_unpack_REPLACE_resized_blkhindx_int64_t;
                ze->pack[YAKSA_OP__LXOR] = yaksuri_zei_pack_LXOR_resized_blkhindx_int64_t;
                ze->unpack[YAKSA_OP__LXOR] = yaksuri_zei_unpack_LXOR_resized_blkhindx_int64_t;
                ze->pack[YAKSA_OP__MAX] = yaksuri_zei_pack_MAX_resized_blkhindx_int64_t;
                ze->unpack[YAKSA_OP__MAX] = yaksuri_zei_unpack_MAX_resized_blkhindx_int64_t;
                ze->pack[YAKSA_OP__LAND] = yaksuri_zei_pack_LAND_resized_blkhindx_int64_t;
                ze->unpack[YAKSA_OP__LAND] = yaksuri_zei_unpack_LAND_resized_blkhindx_int64_t;
                ze->pack[YAKSA_OP__BXOR] = yaksuri_zei_pack_BXOR_resized_blkhindx_int64_t;
                ze->unpack[YAKSA_OP__BXOR] = yaksuri_zei_unpack_BXOR_resized_blkhindx_int64_t;
                ze->pack[YAKSA_OP__SUM] = yaksuri_zei_pack_SUM_resized_blkhindx_int64_t;
                ze->unpack[YAKSA_OP__SUM] = yaksuri_zei_unpack_SUM_resized_blkhindx_int64_t;
                ze->pack[YAKSA_OP__MIN] = yaksuri_zei_pack_MIN_resized_blkhindx_int64_t;
                ze->unpack[YAKSA_OP__MIN] = yaksuri_zei_unpack_MIN_resized_blkhindx_int64_t;
                ze->pack[YAKSA_OP__LOR] = yaksuri_zei_pack_LOR_resized_blkhindx_int64_t;
                ze->unpack[YAKSA_OP__LOR] = yaksuri_zei_unpack_LOR_resized_blkhindx_int64_t;
                ze->name = "yaksuri_zei_op_resized_blkhindx_int64_t";
            }
            break;
            case YAKSA_TYPE__FLOAT:
            if (max_nesting_level >= 2) {
                ze->pack[YAKSA_OP__PROD] = yaksuri_zei_pack_PROD_resized_blkhindx_float;
                ze->unpack[YAKSA_OP__PROD] = yaksuri_zei_unpack_PROD_resized_blkhindx_float;
                ze->pack[YAKSA_OP__REPLACE] = yaksuri_zei_pack_REPLACE_resized_blkhindx_float;
                ze->unpack[YAKSA_OP__REPLACE] = yaksuri_zei_unpack_REPLACE_resized_blkhindx_float;
                ze->pack[YAKSA_OP__MAX] = yaksuri_zei_pack_MAX_resized_blkhindx_float;
                ze->unpack[YAKSA_OP__MAX] = yaksuri_zei_unpack_MAX_resized_blkhindx_float;
                ze->pack[YAKSA_OP__SUM] = yaksuri_zei_pack_SUM_resized_blkhindx_float;
                ze->unpack[YAKSA_OP__SUM] = yaksuri_zei_unpack_SUM_resized_blkhindx_float;
                ze->pack[YAKSA_OP__MIN] = yaksuri_zei_pack_MIN_resized_blkhindx_float;
                ze->unpack[YAKSA_OP__MIN] = yaksuri_zei_unpack_MIN_resized_blkhindx_float;
                ze->name = "yaksuri_zei_op_resized_blkhindx_float";
            }
            break;
            case YAKSA_TYPE__DOUBLE:
            if (max_nesting_level >= 2) {
                ze->pack[YAKSA_OP__PROD] = yaksuri_zei_pack_PROD_resized_blkhindx_double;
                ze->unpack[YAKSA_OP__PROD] = yaksuri_zei_unpack_PROD_resized_blkhindx_double;
                ze->pack[YAKSA_OP__REPLACE] = yaksuri_zei_pack_REPLACE_resized_blkhindx_double;
                ze->unpack[YAKSA_OP__REPLACE] = yaksuri_zei_unpack_REPLACE_resized_blkhindx_double;
                ze->pack[YAKSA_OP__MAX] = yaksuri_zei_pack_MAX_resized_blkhindx_double;
                ze->unpack[YAKSA_OP__MAX] = yaksuri_zei_unpack_MAX_resized_blkhindx_double;
                ze->pack[YAKSA_OP__SUM] = yaksuri_zei_pack_SUM_resized_blkhindx_double;
                ze->unpack[YAKSA_OP__SUM] = yaksuri_zei_unpack_SUM_resized_blkhindx_double;
                ze->pack[YAKSA_OP__MIN] = yaksuri_zei_pack_MIN_resized_blkhindx_double;
                ze->unpack[YAKSA_OP__MIN] = yaksuri_zei_unpack_MIN_resized_blkhindx_double;
                ze->name = "yaksuri_zei_op_resized_blkhindx_double";
            }
            break;
            case YAKSA_TYPE__C_COMPLEX:
            if (max_nesting_level >= 2) {
                ze->pack[YAKSA_OP__REPLACE] = yaksuri_zei_pack_REPLACE_resized_blkhindx_c_complex;
                ze->unpack[YAKSA_OP__REPLACE] = yaksuri_zei_unpack_REPLACE_resized_blkhindx_c_complex;
                ze->pack[YAKSA_OP__PROD] = yaksuri_zei_pack_PROD_resized_blkhindx_c_complex;
                ze->unpack[YAKSA_OP__PROD] = yaksuri_zei_unpack_PROD_resized_blkhindx_c_complex;
                ze->pack[YAKSA_OP__SUM] = yaksuri_zei_pack_SUM_resized_blkhindx_c_complex;
                ze->unpack[YAKSA_OP__SUM] = yaksuri_zei_unpack_SUM_resized_blkhindx_c_complex;
                ze->name = "yaksuri_zei_op_resized_blkhindx_c_complex";
            }
            break;
            case YAKSA_TYPE__C_DOUBLE_COMPLEX:
            if (max_nesting_level >= 2) {
                ze->pack[YAKSA_OP__REPLACE] = yaksuri_zei_pack_REPLACE_resized_blkhindx_c_double_complex;
                ze->unpack[YAKSA_OP__REPLACE] = yaksuri_zei_unpack_REPLACE_resized_blkhindx_c_double_complex;
                ze->pack[YAKSA_OP__PROD] = yaksuri_zei_pack_PROD_resized_blkhindx_c_double_complex;
                ze->unpack[YAKSA_OP__PROD] = yaksuri_zei_unpack_PROD_resized_blkhindx_c_double_complex;
                ze->pack[YAKSA_OP__SUM] = yaksuri_zei_pack_SUM_resized_blkhindx_c_double_complex;
                ze->unpack[YAKSA_OP__SUM] = yaksuri_zei_unpack_SUM_resized_blkhindx_c_double_complex;
                ze->name = "yaksuri_zei_op_resized_blkhindx_c_double_complex";
            }
            break;
            case YAKSA_TYPE__UNSIGNED_CHAR:
            if (max_nesting_level >= 2) {
                ze->pack[YAKSA_OP__REPLACE] = yaksuri_zei_pack_REPLACE_resized_blkhindx_char;
                ze->unpack[YAKSA_OP__REPLACE] = yaksuri_zei_unpack_REPLACE_resized_blkhindx_char;
                ze->name = "yaksuri_zei_op_resized_blkhindx_char";
            }
            break;
            case YAKSA_TYPE__UINT8_T:
            if (max_nesting_level >= 2) {
                ze->pack[YAKSA_OP__PROD] = yaksuri_zei_pack_PROD_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__PROD] = yaksuri_zei_unpack_PROD_resized_blkhindx_int8_t;
                ze->pack[YAKSA_OP__BOR] = yaksuri_zei_pack_BOR_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__BOR] = yaksuri_zei_unpack_BOR_resized_blkhindx_int8_t;
                ze->pack[YAKSA_OP__BAND] = yaksuri_zei_pack_BAND_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__BAND] = yaksuri_zei_unpack_BAND_resized_blkhindx_int8_t;
                ze->pack[YAKSA_OP__REPLACE] = yaksuri_zei_pack_REPLACE_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__REPLACE] = yaksuri_zei_unpack_REPLACE_resized_blkhindx_int8_t;
                ze->pack[YAKSA_OP__LXOR] = yaksuri_zei_pack_LXOR_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__LXOR] = yaksuri_zei_unpack_LXOR_resized_blkhindx_int8_t;
                ze->pack[YAKSA_OP__MAX] = yaksuri_zei_pack_MAX_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__MAX] = yaksuri_zei_unpack_MAX_resized_blkhindx_int8_t;
                ze->pack[YAKSA_OP__LAND] = yaksuri_zei_pack_LAND_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__LAND] = yaksuri_zei_unpack_LAND_resized_blkhindx_int8_t;
                ze->pack[YAKSA_OP__BXOR] = yaksuri_zei_pack_BXOR_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__BXOR] = yaksuri_zei_unpack_BXOR_resized_blkhindx_int8_t;
                ze->pack[YAKSA_OP__SUM] = yaksuri_zei_pack_SUM_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__SUM] = yaksuri_zei_unpack_SUM_resized_blkhindx_int8_t;
                ze->pack[YAKSA_OP__MIN] = yaksuri_zei_pack_MIN_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__MIN] = yaksuri_zei_unpack_MIN_resized_blkhindx_int8_t;
                ze->pack[YAKSA_OP__LOR] = yaksuri_zei_pack_LOR_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__LOR] = yaksuri_zei_unpack_LOR_resized_blkhindx_int8_t;
                ze->name = "yaksuri_zei_op_resized_blkhindx_int8_t";
            }
            break;
            case YAKSA_TYPE__UINT16_T:
            if (max_nesting_level >= 2) {
                ze->pack[YAKSA_OP__PROD] = yaksuri_zei_pack_PROD_resized_blkhindx_int16_t;
                ze->unpack[YAKSA_OP__PROD] = yaksuri_zei_unpack_PROD_resized_blkhindx_int16_t;
                ze->pack[YAKSA_OP__BOR] = yaksuri_zei_pack_BOR_resized_blkhindx_int16_t;
                ze->unpack[YAKSA_OP__BOR] = yaksuri_zei_unpack_BOR_resized_blkhindx_int16_t;
                ze->pack[YAKSA_OP__BAND] = yaksuri_zei_pack_BAND_resized_blkhindx_int16_t;
                ze->unpack[YAKSA_OP__BAND] = yaksuri_zei_unpack_BAND_resized_blkhindx_int16_t;
                ze->pack[YAKSA_OP__REPLACE] = yaksuri_zei_pack_REPLACE_resized_blkhindx_int16_t;
                ze->unpack[YAKSA_OP__REPLACE] = yaksuri_zei_unpack_REPLACE_resized_blkhindx_int16_t;
                ze->pack[YAKSA_OP__LXOR] = yaksuri_zei_pack_LXOR_resized_blkhindx_int16_t;
                ze->unpack[YAKSA_OP__LXOR] = yaksuri_zei_unpack_LXOR_resized_blkhindx_int16_t;
                ze->pack[YAKSA_OP__MAX] = yaksuri_zei_pack_MAX_resized_blkhindx_int16_t;
                ze->unpack[YAKSA_OP__MAX] = yaksuri_zei_unpack_MAX_resized_blkhindx_int16_t;
                ze->pack[YAKSA_OP__LAND] = yaksuri_zei_pack_LAND_resized_blkhindx_int16_t;
                ze->unpack[YAKSA_OP__LAND] = yaksuri_zei_unpack_LAND_resized_blkhindx_int16_t;
                ze->pack[YAKSA_OP__BXOR] = yaksuri_zei_pack_BXOR_resized_blkhindx_int16_t;
                ze->unpack[YAKSA_OP__BXOR] = yaksuri_zei_unpack_BXOR_resized_blkhindx_int16_t;
                ze->pack[YAKSA_OP__SUM] = yaksuri_zei_pack_SUM_resized_blkhindx_int16_t;
                ze->unpack[YAKSA_OP__SUM] = yaksuri_zei_unpack_SUM_resized_blkhindx_int16_t;
                ze->pack[YAKSA_OP__MIN] = yaksuri_zei_pack_MIN_resized_blkhindx_int16_t;
                ze->unpack[YAKSA_OP__MIN] = yaksuri_zei_unpack_MIN_resized_blkhindx_int16_t;
                ze->pack[YAKSA_OP__LOR] = yaksuri_zei_pack_LOR_resized_blkhindx_int16_t;
                ze->unpack[YAKSA_OP__LOR] = yaksuri_zei_unpack_LOR_resized_blkhindx_int16_t;
                ze->name = "yaksuri_zei_op_resized_blkhindx_int16_t";
            }
            break;
            case YAKSA_TYPE__UINT32_T:
            if (max_nesting_level >= 2) {
                ze->pack[YAKSA_OP__PROD] = yaksuri_zei_pack_PROD_resized_blkhindx_int32_t;
                ze->unpack[YAKSA_OP__PROD] = yaksuri_zei_unpack_PROD_resized_blkhindx_int32_t;
                ze->pack[YAKSA_OP__BOR] = yaksuri_zei_pack_BOR_resized_blkhindx_int32_t;
                ze->unpack[YAKSA_OP__BOR] = yaksuri_zei_unpack_BOR_resized_blkhindx_int32_t;
                ze->pack[YAKSA_OP__BAND] = yaksuri_zei_pack_BAND_resized_blkhindx_int32_t;
                ze->unpack[YAKSA_OP__BAND] = yaksuri_zei_unpack_BAND_resized_blkhindx_int32_t;
                ze->pack[YAKSA_OP__REPLACE] = yaksuri_zei_pack_REPLACE_resized_blkhindx_int32_t;
                ze->unpack[YAKSA_OP__REPLACE] = yaksuri_zei_unpack_REPLACE_resized_blkhindx_int32_t;
                ze->pack[YAKSA_OP__LXOR] = yaksuri_zei_pack_LXOR_resized_blkhindx_int32_t;
                ze->unpack[YAKSA_OP__LXOR] = yaksuri_zei_unpack_LXOR_resized_blkhindx_int32_t;
                ze->pack[YAKSA_OP__MAX] = yaksuri_zei_pack_MAX_resized_blkhindx_int32_t;
                ze->unpack[YAKSA_OP__MAX] = yaksuri_zei_unpack_MAX_resized_blkhindx_int32_t;
                ze->pack[YAKSA_OP__LAND] = yaksuri_zei_pack_LAND_resized_blkhindx_int32_t;
                ze->unpack[YAKSA_OP__LAND] = yaksuri_zei_unpack_LAND_resized_blkhindx_int32_t;
                ze->pack[YAKSA_OP__BXOR] = yaksuri_zei_pack_BXOR_resized_blkhindx_int32_t;
                ze->unpack[YAKSA_OP__BXOR] = yaksuri_zei_unpack_BXOR_resized_blkhindx_int32_t;
                ze->pack[YAKSA_OP__SUM] = yaksuri_zei_pack_SUM_resized_blkhindx_int32_t;
                ze->unpack[YAKSA_OP__SUM] = yaksuri_zei_unpack_SUM_resized_blkhindx_int32_t;
                ze->pack[YAKSA_OP__MIN] = yaksuri_zei_pack_MIN_resized_blkhindx_int32_t;
                ze->unpack[YAKSA_OP__MIN] = yaksuri_zei_unpack_MIN_resized_blkhindx_int32_t;
                ze->pack[YAKSA_OP__LOR] = yaksuri_zei_pack_LOR_resized_blkhindx_int32_t;
                ze->unpack[YAKSA_OP__LOR] = yaksuri_zei_unpack_LOR_resized_blkhindx_int32_t;
                ze->name = "yaksuri_zei_op_resized_blkhindx_int32_t";
            }
            break;
            case YAKSA_TYPE__UINT64_T:
            if (max_nesting_level >= 2) {
                ze->pack[YAKSA_OP__PROD] = yaksuri_zei_pack_PROD_resized_blkhindx_int64_t;
                ze->unpack[YAKSA_OP__PROD] = yaksuri_zei_unpack_PROD_resized_blkhindx_int64_t;
                ze->pack[YAKSA_OP__BOR] = yaksuri_zei_pack_BOR_resized_blkhindx_int64_t;
                ze->unpack[YAKSA_OP__BOR] = yaksuri_zei_unpack_BOR_resized_blkhindx_int64_t;
                ze->pack[YAKSA_OP__BAND] = yaksuri_zei_pack_BAND_resized_blkhindx_int64_t;
                ze->unpack[YAKSA_OP__BAND] = yaksuri_zei_unpack_BAND_resized_blkhindx_int64_t;
                ze->pack[YAKSA_OP__REPLACE] = yaksuri_zei_pack_REPLACE_resized_blkhindx_int64_t;
                ze->unpack[YAKSA_OP__REPLACE] = yaksuri_zei_unpack_REPLACE_resized_blkhindx_int64_t;
                ze->pack[YAKSA_OP__LXOR] = yaksuri_zei_pack_LXOR_resized_blkhindx_int64_t;
                ze->unpack[YAKSA_OP__LXOR] = yaksuri_zei_unpack_LXOR_resized_blkhindx_int64_t;
                ze->pack[YAKSA_OP__MAX] = yaksuri_zei_pack_MAX_resized_blkhindx_int64_t;
                ze->unpack[YAKSA_OP__MAX] = yaksuri_zei_unpack_MAX_resized_blkhindx_int64_t;
                ze->pack[YAKSA_OP__LAND] = yaksuri_zei_pack_LAND_resized_blkhindx_int64_t;
                ze->unpack[YAKSA_OP__LAND] = yaksuri_zei_unpack_LAND_resized_blkhindx_int64_t;
                ze->pack[YAKSA_OP__BXOR] = yaksuri_zei_pack_BXOR_resized_blkhindx_int64_t;
                ze->unpack[YAKSA_OP__BXOR] = yaksuri_zei_unpack_BXOR_resized_blkhindx_int64_t;
                ze->pack[YAKSA_OP__SUM] = yaksuri_zei_pack_SUM_resized_blkhindx_int64_t;
                ze->unpack[YAKSA_OP__SUM] = yaksuri_zei_unpack_SUM_resized_blkhindx_int64_t;
                ze->pack[YAKSA_OP__MIN] = yaksuri_zei_pack_MIN_resized_blkhindx_int64_t;
                ze->unpack[YAKSA_OP__MIN] = yaksuri_zei_unpack_MIN_resized_blkhindx_int64_t;
                ze->pack[YAKSA_OP__LOR] = yaksuri_zei_pack_LOR_resized_blkhindx_int64_t;
                ze->unpack[YAKSA_OP__LOR] = yaksuri_zei_unpack_LOR_resized_blkhindx_int64_t;
                ze->name = "yaksuri_zei_op_resized_blkhindx_int64_t";
            }
            break;
            case YAKSA_TYPE__BYTE:
            if (max_nesting_level >= 2) {
                ze->pack[YAKSA_OP__PROD] = yaksuri_zei_pack_PROD_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__PROD] = yaksuri_zei_unpack_PROD_resized_blkhindx_int8_t;
                ze->pack[YAKSA_OP__BOR] = yaksuri_zei_pack_BOR_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__BOR] = yaksuri_zei_unpack_BOR_resized_blkhindx_int8_t;
                ze->pack[YAKSA_OP__BAND] = yaksuri_zei_pack_BAND_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__BAND] = yaksuri_zei_unpack_BAND_resized_blkhindx_int8_t;
                ze->pack[YAKSA_OP__REPLACE] = yaksuri_zei_pack_REPLACE_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__REPLACE] = yaksuri_zei_unpack_REPLACE_resized_blkhindx_int8_t;
                ze->pack[YAKSA_OP__LXOR] = yaksuri_zei_pack_LXOR_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__LXOR] = yaksuri_zei_unpack_LXOR_resized_blkhindx_int8_t;
                ze->pack[YAKSA_OP__MAX] = yaksuri_zei_pack_MAX_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__MAX] = yaksuri_zei_unpack_MAX_resized_blkhindx_int8_t;
                ze->pack[YAKSA_OP__LAND] = yaksuri_zei_pack_LAND_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__LAND] = yaksuri_zei_unpack_LAND_resized_blkhindx_int8_t;
                ze->pack[YAKSA_OP__BXOR] = yaksuri_zei_pack_BXOR_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__BXOR] = yaksuri_zei_unpack_BXOR_resized_blkhindx_int8_t;
                ze->pack[YAKSA_OP__SUM] = yaksuri_zei_pack_SUM_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__SUM] = yaksuri_zei_unpack_SUM_resized_blkhindx_int8_t;
                ze->pack[YAKSA_OP__MIN] = yaksuri_zei_pack_MIN_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__MIN] = yaksuri_zei_unpack_MIN_resized_blkhindx_int8_t;
                ze->pack[YAKSA_OP__LOR] = yaksuri_zei_pack_LOR_resized_blkhindx_int8_t;
                ze->unpack[YAKSA_OP__LOR] = yaksuri_zei_unpack_LOR_resized_blkhindx_int8_t;
                ze->name = "yaksuri_zei_op_resized_blkhindx_int8_t";
            }
            break;
            default:
                break;
        }
        break;
        default:
            break;
    }
    
    return rc;
}
