//
// Created by profanter on 19.07.16.
//

#ifndef MDNSD_MDNSD_COMMON_H
#define MDNSD_MDNSD_COMMON_H

#ifndef _XOPEN_SOURCE
# define _XOPEN_SOURCE 500
#endif
#ifndef _DEFAULT_SOURCE
# define _DEFAULT_SOURCE 1
#endif

#if defined __APPLE__
// required for ip_mreq
#define _DARWIN_C_SOURCE 1
#endif

#define MDNSD_free(ptr) free(ptr)
#define MDNSD_malloc(size) malloc(size)
#define MDNSD_calloc(num, size) calloc(num, size)
#define MDNSD_realloc(ptr, size) realloc(ptr, size)

/**
 * Function Export
 * --------------- */
/* On Win32: Define MDNSD_DYNAMIC_LINKING and MDNSD_DYNAMIC_LINKING_EXPORT in order to
   export symbols for a DLL. Define MDNSD_DYNAMIC_LINKING only to import symbols
	from a DLL.*/
#ifdef MDNSD_DYNAMIC_LINKING
# ifdef _WIN32
#  ifdef MDNSD_DYNAMIC_LINKING_EXPORT
#   ifdef __GNUC__
#    define MDNSD_EXPORT __attribute__ ((dllexport))
#   else
#    define MDNSD_EXPORT __declspec(dllexport)
#   endif
#  else
#   ifdef __GNUC__
#    define MDNSD_EXPORT __attribute__ ((dllexport))
#   else
#    define MDNSD_EXPORT __declspec(dllimport)
#   endif
#  endif
# endif
#else
# if __GNUC__ || __clang__
#  define MDNSD_EXPORT __attribute__ ((visibility ("default")))
# else
#  define MDNSD_EXPORT
# endif
#endif

/**
 * Inline Functions
 * ---------------- */
#ifdef _MSC_VER
# define MDNSD_INLINE __inline
#else
# define MDNSD_INLINE inline
#endif

#endif //MDNSD_MDNSD_COMMON_H
