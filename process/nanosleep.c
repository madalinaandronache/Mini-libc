#include <unistd.h>
#include <time.h>
#include <internal/syscall.h>
#include <stdlib.h>
#include <errno.h>

int nanosleep(const struct timespec *rqtp, struct timespec *rmtp){
    int ret = syscall(__NR_nanosleep, rqtp, rmtp);

    if (ret >= 0){
		return ret;
	}

	errno = -ret;
    return ret;
}
