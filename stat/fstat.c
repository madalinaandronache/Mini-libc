// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	/* TODO: Implement fstat(). */
	int ret = syscall(__NR_fstat, fd, st);

	if (ret >= 0) {
		return ret;
	}

	errno = -ret;
	return -1;
}
