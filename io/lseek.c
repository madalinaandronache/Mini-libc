// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <internal/types.h>

off_t lseek(int fd, off_t offset, int whence)
{
	/* TODO: Implement lseek(). */
	off_t result = syscall(__NR_lseek, fd, offset, whence);

	if(result >= 0) {
		return result;
	}

	errno = -result;
	return -1;
}
