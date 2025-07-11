##
## Copyright (C) by Argonne National Laboratory
##     See COPYRIGHT in top-level directory
##

include $(top_srcdir)/src/mpi/coll/mvapich/allgather/Makefile.mk
include $(top_srcdir)/src/mpi/coll/mvapich/barrier/Makefile.mk
include $(top_srcdir)/src/mpi/coll/mvapich/bcast/Makefile.mk
include $(top_srcdir)/src/mpi/coll/mvapich/gather/Makefile.mk
include $(top_srcdir)/src/mpi/coll/mvapich/reduce/Makefile.mk
include $(top_srcdir)/src/mpi/coll/mvapich/scatter/Makefile.mk
include $(top_srcdir)/src/mpi/coll/mvapich/reduce_scatter/Makefile.mk

AM_CPPFLAGS += -I$(top_srcdir)/src/mpi/coll/mvapich/include/

noinst_HEADERS +=                    \
    src/mpi/coll/mvapich/include/mvp_coll_impl.h


#include $(top_srcdir)/src/mpi/coll/mvapich/allgather/Makefile.mk
#include $(top_srcdir)/src/mpi/coll/mvapich/allgatherv/Makefile.mk
#include $(top_srcdir)/src/mpi/coll/mvapich/allreduce/Makefile.mk
#include $(top_srcdir)/src/mpi/coll/mvapich/alltoall/Makefile.mk
#include $(top_srcdir)/src/mpi/coll/mvapich/alltoallv/Makefile.mk
#include $(top_srcdir)/src/mpi/coll/mvapich/reduce_scatter/Makefile.mk
#include $(top_srcdir)/src/mpi/coll/mvapich/reduce/Makefile.mk
#include $(top_srcdir)/src/mpi/coll/mvapich/scatter/Makefile.mk
