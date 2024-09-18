/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef __TIME_H__
#define __TIME_H__	1

#ifdef __cplusplus
extern "C" {
#endif

#include <internal/types.h>

typedef unsigned long time_t;
typedef unsigned long clock_t;

struct timespec{
    time_t tv_sec; // numarul de secunde de la inceputul epocii sau alt punct de referinta
    long int tv_nsec; // numarul de nanosecunde
};

int nanosleep(const struct timespec *requested_time, struct timespec *remaining);

#ifdef __cplusplus
}
#endif

#endif
