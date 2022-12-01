## Copyright (c) 2001-2022, The Ohio State University. All rights
## reserved.
##
## This file is part of the MVAPICH2 software package developed by the
## team members of The Ohio State University's Network-Based Computing
## Laboratory (NBCL), headed by Professor Dhabaleswar K. (DK) Panda.
##
## For detailed copyright and licensing information, please refer to the
## copyright file COPYRIGHT in the top level MVAPICH2 directory.
##

if BUILD_OSU_MVAPICH
mpi_core_sources +=			\
	src/mpid/ch4/netmod/mv2/mv2_init.c  \
	src/mpid/ch4/netmod/mv2/func_table.c  \
	src/mpid/ch4/netmod/mv2/debug_utils.c \
	src/mpid/ch4/netmod/mv2/mv2_utils.c \
	src/mpid/ch4/netmod/mv2/hwloc_bind.c  \
	src/mpid/ch4/netmod/mv2/mv2_arch_detect.c \
	src/mpid/ch4/netmod/mv2/mv2_comm.c
endif
