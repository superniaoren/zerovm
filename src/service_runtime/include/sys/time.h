/*
 * Copyright 2008  The Native Client Authors.  All rights reserved.
 * Use of this source code is governed by a BSD-style license that can
 * be found in the LICENSE file.
 */

/*
 * NaCl Service Runtime API.  Time types.
 */

#ifndef NATIVE_CLIENT_SRC_TRUSTED_SERVICE_RUNTIME_INCLUDE_SYS_TIME_H_
#define NATIVE_CLIENT_SRC_TRUSTED_SERVICE_RUNTIME_INCLUDE_SYS_TIME_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef int32_t   nacl_abi_suseconds_t;

#ifndef nacl_abi___clock_t_defined
#define nacl_abi___clock_t_defined
typedef long int  nacl_abi_clock_t;  /* to be deprecated */
#endif

/* d'b: from _types.h {{ */
typedef int64_t       nacl_abi___time_t;
typedef nacl_abi___time_t nacl_abi_time_t; /* }} */

struct nacl_abi_timeval {
  nacl_abi_time_t      nacl_abi_tv_sec;
  nacl_abi_suseconds_t nacl_abi_tv_usec;
};

struct nacl_abi_timespec {
  nacl_abi_time_t    tv_sec;
  int32_t            tv_nsec;
};

/* obsolete.  should not be used */
struct nacl_abi_timezone {
  int tz_minuteswest;
  int tz_dsttime;
};

/*
 * In some places (e.g., the linux man page) the second parameter is defined
 * as a struct timezone *.  The header file says this struct type should
 * never be used, and defines it by default as void *.  The Mac man page says
 * it is void *.
 */
extern int nacl_abi_gettimeofday(struct nacl_abi_timeval *tv, void *tz);

#ifdef __cplusplus
}
#endif

#endif
