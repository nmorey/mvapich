dnl Configury specific to the libfabric ucr provider

dnl Called to configure this provider
dnl
dnl Arguments:
dnl
dnl $1: action if configured successfully
dnl $2: action if not configured successfully
dnl
AC_DEFUN([FI_UCR_CONFIGURE],[
       # Determine if we can support the ucr provider
       ucr_h_happy=0
       AS_IF([test x"$enable_ucr" != x"no"], [ucr_h_happy=1])
       AS_IF([test $ucr_h_happy -eq 1], [$1], [$2])
       AC_ARG_ENABLE([ucr-regcache], [AS_HELP_STRING([--disable-ucr-regcache],
                                     [Disable UCR memory registration caching])],
                     [enable_ucr_regcache=no], [enable_ucr_regcache=yes])
       AM_CONDITIONAL([HAVE_UCR_REGCACHE], [test x"$enable_ucr_regcache" != x"no"])
])

