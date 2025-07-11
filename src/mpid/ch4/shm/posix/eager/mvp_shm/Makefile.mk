##
## Copyright (C) by Argonne National Laboratory
##     See COPYRIGHT in top-level directory
##

if BUILD_CH4_SHM_POSIX_EAGER_MVP_SHM

noinst_HEADERS += src/mpid/ch4/shm/posix/eager/mvp_shm/mvp_shm_send.h \
                  src/mpid/ch4/shm/posix/eager/mvp_shm/mvp_shm_recv.h \
                  src/mpid/ch4/shm/posix/eager/mvp_shm/posix_eager_inline.h

mpi_core_sources += src/mpid/ch4/shm/posix/eager/mvp_shm/func_table.c \
                    src/mpid/ch4/shm/posix/eager/mvp_shm/mvp_shm_init.c

endif
