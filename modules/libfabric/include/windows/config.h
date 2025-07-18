/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */

/* defined to 1 if libfabric was configured with --enable-debug, 0 otherwise
   */
/* #define ENABLE_DEBUG 1 */

/* Define to 1 if the linker supports alias attribute. */
/* #undef HAVE_ALIAS_ATTRIBUTE */

/* Set to 1 to use c11 atomic functions */
/* #undef HAVE_ATOMICS */   /* TODO: add atomics support for windows */

/* bgq provider is built */
#define HAVE_BGQ 0

/* bgq provider is built as DSO */
#define HAVE_BGQ_DL 0

/* Set to 1 to use built-in intrincics atomics */
#define HAVE_BUILTIN_ATOMICS 1

/* Define to 1 if clock_gettime is available. */
/* #undef HAVE_CLOCK_GETTIME */

/* Define to 1 if you have the <dlfcn.h> header file. */
/* #undef HAVE_DLFCN_H */

/* dmabuf_peer_mem provider is built */
#define HAVE_DMABUF_PEER_MEM 0

/* dmabuf_peer_mem provider is built as DSO */
#define HAVE_DMABUF_PEER_MEM_DL 0

#ifndef HAVE_EFA
/* efa provider is built */
#define HAVE_EFA 0
#endif /* HAVE_EFA */

/* efa provider is built as DSO */
#define HAVE_EFA_DL 0

/* Indicates if ibv_reg_dmabuf_mr verbs is available */
#define HAVE_EFA_DMABUF_MR 0

/* Define to 1 if host_clock_get_service is available. */
/* #undef HAVE_HOST_GET_CLOCK_SERVICE */

/* gni provider is built */
#define HAVE_GNI 0

/* gni provider is built as DSO */
#define HAVE_GNI_DL 0

/* hook_debug provider is built */
#define HAVE_HOOK_DEBUG 0

/* hook_debug provider is built as DSO */
#define HAVE_HOOK_DEBUG_DL 0

/* hook_hmem provider is built */
#define HAVE_HOOK_HMEM 0

/* hook_hmem provider is built as DSO */
#define HAVE_HOOK_HMEM_DL 0

/* Define to 1 if you have the <infiniband/verbs.h> header file. */
#define HAVE_INFINIBAND_VERBS_H 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the `dl' library (-ldl). */
/* #undef HAVE_LIBDL */

/* Whether we have libl or libnl3 */
/* #undef HAVE_LIBNL3 */

/* Define to 1 if you have the `pthread' library (-lpthread). */
/* #undef HAVE_LIBPTHREAD */

/* Define to 1 if you have the <memory.h> header file. */
/* #undef HAVE_MEMORY_H */

/* Define to 1 if you have the <netlink/netlink.h> header file. */
/* #undef HAVE_NETLINK_NETLINK_H */

/* Define to 1 if you have the <netlink/version.h> header file. */
/* #undef HAVE_NETLINK_VERSION_H */

/* opx provider is built */
#define HAVE_OPX 0

/* opx provider is built as DSO */
#define HAVE_OPX_DL 0

/* perf provider is built */
#define HAVE_PERF 1

/* perf provider is built as DSO */
#define HAVE_PERF_DL 0

/* profile provider is built */
#define HAVE_PROFILE 0

/* profile provider is built as DSO */
#define HAVE_PROFILE_DL 0

/* psm2 provider is built */
#define HAVE_PSM2 0

/* psm2 provider is built as DSO */
#define HAVE_PSM2_DL 0

/* psm3 provider is built */
#define HAVE_PSM3 0

/* psm3 provider is built as DSO */
#define HAVE_PSM3_DL 0

/* Define to 1 if you have the <psm2.h> header file. */
/* #undef HAVE_PSM2_H */

/* Define to 1 if you have the <rdma/rsocket.h> header file. */
/* #undef HAVE_RDMA_RSOCKET_H */

/* trace provider is built */
#define HAVE_TRACE 0

/* trace provider is built as DSO */
#define HAVE_TRACE_DL 0

/* UDP provider is built */
#define HAVE_UDP 1

/* UDP provider is built as DSO */
#define HAVE_UDP_DL 0

/* usnic provider is built */
#define HAVE_USNIC 0

/* usnic provider is built as DSO */
#define HAVE_USNIC_DL 0

/* sockets provider is built */
#define HAVE_SOCKETS 1

/* sockets provider is built as DSO */
#define HAVE_SOCKETS_DL 0

/* Define to 1 to restrict dlopen operations to providers which were available
   at compile-time */
#define HAVE_RESTRICTED_DL 0

/* rxm provider is built */
#define HAVE_RXM 1

/* rxm provider is built as DSO */
#define HAVE_RXM_DL 0

/* rxd provider is built */
#define HAVE_RXD 1

/* rxd provider is built as DSO */
#define HAVE_RXD_DL 0

/* shm provider is built */
#define HAVE_SHM 0

/* shm provider is built as DSO */
#define HAVE_SHM_DL 0


/* Network Direct provider is built */
#define HAVE_NETDIR 1

/* Network Direct provider is built as DSO */
/* #undef HAVE_NETDIR_DL */

/* TCP provider is built */
#define HAVE_TCP 1

/* TCP provider is built as DSO */
#define HAVE_TCP_DL 0

/* NET provider is built */
#define HAVE_NET 1

/* NET provider is built as DSO */
/* #undef HAVE_NET_DL */

/* Define to 1 if you have the <stdint.h> header file. */
/* #undef HAVE_STDINT_H */

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if compiler/linker support symbol versioning. */
/* #undef HAVE_SYMVER_SUPPORT */

/* Define to 1 if you have the <sys/mman.h> header file. */
/* #undef HAVE_SYS_MMAN_H */

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* ucx provider is built */
#define HAVE_UCX 0

/* ucx provider is built as DSO */
#define HAVE_UCX_DL 0

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* usnic provider is built */
/* #undef HAVE_USNIC */

/* usnic provider is built as DSO */
/* #undef HAVE_USNIC_DL */

/* verbs provider is built */
#define HAVE_VERBS 1

/* verbs provider is built as DSO */
#define HAVE_VERBS_DL 0

/* Whether infiniband/verbs.h has XRC support or not */
#define VERBS_HAVE_XRC 0

/* Define to 1 to enable valgrind annotations */
/* #undef INCLUDE_VALGRIND */

/* Define to the sub-directory where libtool stores uninstalled libraries. */
#define LT_OBJDIR ".libs/"

/* Name of package */
#define PACKAGE "libfabric"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "ofiwg@lists.openfabrics.org"

/* Define to the full name of this package. */
#define PACKAGE_NAME PACKAGE

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME PACKAGE

/* Define to the version of this package. */
#define PACKAGE_VERSION "1.20.2"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING PACKAGE_NAME " " PACKAGE_VERSION

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to 1 if pthread_spin_init is available. */
/* #undef PT_LOCK_SPIN */

/* Define to 1 if adapter info API is defined. */
#define HAVE_MIB_IPADDRTABLE 1

/* Define to 1 if you have the `getifaddrs' function. */
#define HAVE_GETIFADDRS 1

/* The size of `void *', as computed by sizeof. */
#ifdef _WIN64
#define SIZEOF_VOID_P 8
#else /* _WIN64 */
#define SIZEOF_VOID_P 4
#endif /* _WIN64 */

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Version number of package */
#define _FI_EXP(s) #s
#define _FI_TO_STRING(s) _FI_EXP(s)
#define VERSION _FI_TO_STRING(FI_MAJOR_VERSION) "." _FI_TO_STRING(FI_MINOR_VERSION) "." _FI_TO_STRING(FI_REVISION_VERSION)

#ifndef BUILD_ID
#define BUILD_ID ""
#endif
