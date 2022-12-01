/* Copyright (c) 2001-2021, The Ohio State University. All rights
 * reserved.
 *
 * This file is part of the MVAPICH2 software package developed by the
 * team members of The Ohio State University's Network-Based Computing
 * Laboratory (NBCL), headed by Professor Dhabaleswar K. (DK) Panda.
 *
 * For detailed copyright and licensing information, please refer to the
 * copyright file COPYRIGHT in the top level MVAPICH2 directory.
 *
 */

/*
 * This file defines the MPID_ functions implemented by the chosen device.
 * these functions are all implemented by MV2 and are within the MV2_ 
 * namespace and should be accessible by the MPI_ level. Most are implemented
 * in the MV2_MPIDI_ level, which should be defined by the specific device
 * being used. 
 */

#ifndef _CUDA_UTIL_H_
#define _CUDA_UTIL_H_

#include "cuda.h"
#include "cuda_runtime.h"

#if defined(_ENABLE_CUDA_)
#define MV2_MPID_Device_CtxGetCurrent(_ctx)     \
    MV2_MPIDI_Device_CtxGetCurrent(_ctx) 

#define MV2_MPID_DeviceEventCreate(_event)     \
    MV2_MPIDI_DeviceEventCreate(_event)

#define MV2_MPID_DeviceEventCreateWithFlags(_event, _flags)    \
    MV2_MPIDI_DeviceEventCreateWithFlags(_event, _flags)

#define MV2_MPID_Device_EventRecord(_event, _stream)    \
    MV2_MPIDI_Device_EventRecord(_event, _stream)

#define MV2_MPID_Device_EventSynchronize    \
    MV2_MPIDI_Device_EventSynchronize

#define MV2_MPID_Memcpy_Device          \
    MV2_MPIDI_Memcpy_Device

#define MV2_MPID_Memcpy_Device_Async      \
    MV2_MPIDI_Memcpy_Device_Async

#define MV2_MPID_Device_StreamWaitEvent     \
    MV2_MPIDI_Device_StreamWaitEvent

#endif
#endif /* _IBV_CUDA_UTIL_H_ */
