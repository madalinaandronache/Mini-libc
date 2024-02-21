#include <unistd.h>
#include <time.h>
#include <internal/syscall.h>
#include <errno.h>

time_t time(time_t* timer) {
    if (timer != NULL) {
        *timer = 0;
    }
    return 0;
}

unsigned int sleep(unsigned int seconds){
    // Source: https://codebrowser.dev/glibc/glibc/sysdeps/posix/sleep.c.html

    int save_errno = errno;
    const unsigned int max = (unsigned int)(((unsigned long long)(~((time_t)0))) >> 1);
    struct timespec ts = {0, 0};

    do {
        if (sizeof(ts.tv_sec) <= sizeof(seconds)) {
            ts.tv_sec += (unsigned int)(seconds < max ? seconds : max);
            seconds -= ts.tv_sec;
        } else {
            ts.tv_sec = (time_t)seconds;
            seconds = 0;
        }

        if (nanosleep(&ts, &ts) < 0) {
            return seconds + ts.tv_sec;
        }
    } while (seconds > 0);
    errno = save_errno;
    return 0;
}
