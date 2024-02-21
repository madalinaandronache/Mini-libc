/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef _TIME_H
#define _TIME_H	1

#ifdef __cplusplus
extern "C" {
#endif

#include <internal/io.h>
#include <internal/types.h>

typedef long time_t;

struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
};

struct timespec {
    time_t tv_sec;
    long tv_nsec;
};

time_t time(time_t* timer);
int nanosleep(const struct timespec *rqtp, struct timespec *rmtp);


#ifdef __cplusplus
}
#endif

#endif
