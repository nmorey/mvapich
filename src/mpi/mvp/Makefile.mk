## -*- Mode: Makefile; -*-
## vim: set ft=automake :

AM_CPPFLAGS += -I$(top_builddir)/src/mpi/mvp/include

include $(top_srcdir)/src/mpi/mvp/src/Makefile.mk
