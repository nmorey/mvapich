[#] start of __file__
dnl MPICH_SUBCFG_AFTER=src/mpid/ch4

AC_DEFUN([PAC_SUBCFG_PREREQ_]PAC_SUBCFG_AUTO_SUFFIX,[
    AM_COND_IF([BUILD_CH4],[
        for eager in $ch4_posix_eager_modules ; do
            AS_CASE([$eager],[mvp_shm],[build_ch4_shm_posix_eager_mvp_shm=yes])
            if test $eager = "mvp_shm" ; then
                AC_DEFINE(HAVE_CH4_SHM_EAGER_MVP_SHM,1,[MVP_SHM submodule is built])
            fi
        done
    ])
    AM_CONDITIONAL([BUILD_CH4_SHM_POSIX_EAGER_MVP_SHM],[test "X$build_ch4_shm_posix_eager_mvp_shm" = "Xyes"])
])dnl

AC_DEFUN([PAC_SUBCFG_BODY_]PAC_SUBCFG_AUTO_SUFFIX,[
])dnl end _BODY

[#] end of __file__
