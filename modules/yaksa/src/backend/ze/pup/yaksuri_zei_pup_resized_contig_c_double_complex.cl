/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 *
 * DO NOT EDIT: AUTOMATICALLY GENERATED FILE !!
 */

typedef signed char int8_t;
typedef signed short int int16_t;
typedef signed int int32_t;
typedef signed long int64_t;
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long uint64_t;
#include "yaksuri_zei_md.h"

__kernel void yaksuri_zei_kernel_pack_REPLACE_resized_contig_c_double_complex(__global const void *inbuf, __global void *outbuf, unsigned long count, __global const yaksuri_zei_md_s *__restrict__ md)
{
    __global const char *__restrict__ sbuf = (__global char *) inbuf;
    __global char *__restrict__ dbuf = (__global char *) outbuf;
    sbuf = (__global const char *) ((__global char *)sbuf - md->true_lb);
    uintptr_t extent = md->extent;
    uintptr_t idx = get_global_id(0);
    uintptr_t res = idx;
    uintptr_t inner_elements = md->num_elements;
    
    if (idx >= (count * inner_elements))
        return;
    
    uintptr_t x0 = res / inner_elements;
    res %= inner_elements;
    inner_elements /= md->u.resized.child->u.contig.count;
    
    uintptr_t x1 = res;
    
    intptr_t stride2 = md->u.resized.child->u.contig.child->extent;
    *((double2 *) (void *) (dbuf + idx * sizeof(double2))) = *((const double2 *) (const void *) (sbuf + x0 * extent + x1 * stride2));
}

__kernel void yaksuri_zei_kernel_unpack_REPLACE_resized_contig_c_double_complex(__global const void *inbuf, __global void *outbuf, unsigned long count, __global const yaksuri_zei_md_s *__restrict__ md)
{
    __global const char *__restrict__ sbuf = (__global char *) inbuf;
    __global char *__restrict__ dbuf = (__global char *) outbuf;
    dbuf = dbuf - md->true_lb;
    uintptr_t extent = md->extent;
    uintptr_t idx = get_global_id(0);
    uintptr_t res = idx;
    uintptr_t inner_elements = md->num_elements;
    
    if (idx >= (count * inner_elements))
        return;
    
    uintptr_t x0 = res / inner_elements;
    res %= inner_elements;
    inner_elements /= md->u.resized.child->u.contig.count;
    
    uintptr_t x1 = res;
    
    intptr_t stride2 = md->u.resized.child->u.contig.child->extent;
    *((double2 *) (void *) (dbuf + x0 * extent + x1 * stride2)) = *((const double2 *) (const void *) (sbuf + idx * sizeof(double2)));
}

__kernel void yaksuri_zei_kernel_pack_PROD_resized_contig_c_double_complex(__global const void *inbuf, __global void *outbuf, unsigned long count, __global const yaksuri_zei_md_s *__restrict__ md)
{
    __global const char *__restrict__ sbuf = (__global char *) inbuf;
    __global char *__restrict__ dbuf = (__global char *) outbuf;
    sbuf = (__global const char *) ((__global char *)sbuf - md->true_lb);
    uintptr_t extent = md->extent;
    uintptr_t idx = get_global_id(0);
    uintptr_t res = idx;
    uintptr_t inner_elements = md->num_elements;
    
    if (idx >= (count * inner_elements))
        return;
    
    uintptr_t x0 = res / inner_elements;
    res %= inner_elements;
    inner_elements /= md->u.resized.child->u.contig.count;
    
    uintptr_t x1 = res;
    
    intptr_t stride2 = md->u.resized.child->u.contig.child->extent;
    double2 dest;
    double2 src = *((const double2 *) (const void *) (sbuf + x0 * extent + x1 * stride2));
    double2 temp_dest = *((double2 *) (void *) (dbuf + idx * sizeof(double2)));
    dest.x = temp_dest.x * src.x - temp_dest.y * src.y;
    dest.y = temp_dest.x * src.y + temp_dest.y * src.x;
    *((double2 *) (void *) (dbuf + idx * sizeof(double2))) = dest;
}

__kernel void yaksuri_zei_kernel_unpack_PROD_resized_contig_c_double_complex(__global const void *inbuf, __global void *outbuf, unsigned long count, __global const yaksuri_zei_md_s *__restrict__ md)
{
    __global const char *__restrict__ sbuf = (__global char *) inbuf;
    __global char *__restrict__ dbuf = (__global char *) outbuf;
    dbuf = dbuf - md->true_lb;
    uintptr_t extent = md->extent;
    uintptr_t idx = get_global_id(0);
    uintptr_t res = idx;
    uintptr_t inner_elements = md->num_elements;
    
    if (idx >= (count * inner_elements))
        return;
    
    uintptr_t x0 = res / inner_elements;
    res %= inner_elements;
    inner_elements /= md->u.resized.child->u.contig.count;
    
    uintptr_t x1 = res;
    
    intptr_t stride2 = md->u.resized.child->u.contig.child->extent;
    double2 dest;
    double2 src = *((const double2 *) (const void *) (sbuf + idx * sizeof(double2)));
    double2 temp_dest = *((double2 *) (void *) (dbuf + x0 * extent + x1 * stride2));
    dest.x = temp_dest.x * src.x - temp_dest.y * src.y;
    dest.y = temp_dest.x * src.y + temp_dest.y * src.x;
    *((double2 *) (void *) (dbuf + x0 * extent + x1 * stride2)) = dest;
}

__kernel void yaksuri_zei_kernel_pack_SUM_resized_contig_c_double_complex(__global const void *inbuf, __global void *outbuf, unsigned long count, __global const yaksuri_zei_md_s *__restrict__ md)
{
    __global const char *__restrict__ sbuf = (__global char *) inbuf;
    __global char *__restrict__ dbuf = (__global char *) outbuf;
    sbuf = (__global const char *) ((__global char *)sbuf - md->true_lb);
    uintptr_t extent = md->extent;
    uintptr_t idx = get_global_id(0);
    uintptr_t res = idx;
    uintptr_t inner_elements = md->num_elements;
    
    if (idx >= (count * inner_elements))
        return;
    
    uintptr_t x0 = res / inner_elements;
    res %= inner_elements;
    inner_elements /= md->u.resized.child->u.contig.count;
    
    uintptr_t x1 = res;
    
    intptr_t stride2 = md->u.resized.child->u.contig.child->extent;
    *((double2 *) (void *) (dbuf + idx * sizeof(double2))) += *((const double2 *) (const void *) (sbuf + x0 * extent + x1 * stride2));
}

__kernel void yaksuri_zei_kernel_unpack_SUM_resized_contig_c_double_complex(__global const void *inbuf, __global void *outbuf, unsigned long count, __global const yaksuri_zei_md_s *__restrict__ md)
{
    __global const char *__restrict__ sbuf = (__global char *) inbuf;
    __global char *__restrict__ dbuf = (__global char *) outbuf;
    dbuf = dbuf - md->true_lb;
    uintptr_t extent = md->extent;
    uintptr_t idx = get_global_id(0);
    uintptr_t res = idx;
    uintptr_t inner_elements = md->num_elements;
    
    if (idx >= (count * inner_elements))
        return;
    
    uintptr_t x0 = res / inner_elements;
    res %= inner_elements;
    inner_elements /= md->u.resized.child->u.contig.count;
    
    uintptr_t x1 = res;
    
    intptr_t stride2 = md->u.resized.child->u.contig.child->extent;
    *((double2 *) (void *) (dbuf + x0 * extent + x1 * stride2)) += *((const double2 *) (const void *) (sbuf + idx * sizeof(double2)));
}

