// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <internal/types.h>

int truncate(const char *path, off_t length)
{
	/* TODO: Implement truncate(). */
	int ret = syscall(__NR_truncate, path, length);

	if (ret >= 0) {
		return ret;
	}

	errno = -ret;
	return -1;
}
