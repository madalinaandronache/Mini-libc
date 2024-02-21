// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */
	// Source about variadic functions: https://onepunchcoder.medium.com/variadic-functions-explained-fd3b4ab6fd84
	mode_t mode = 0;

	va_list args;
    va_start(args, flags);

	if(flags & O_CREAT) {
		mode = va_arg(args, mode_t);
	}

	va_end(args);

	int ret = syscall(__NR_open, filename, flags, mode);

	if (ret >= 0) {
		return ret;
	}

	errno = -ret;
	return -1;
}
