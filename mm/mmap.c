// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>
#include <internal/types.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */

	if ((flags & (MAP_SHARED | MAP_PRIVATE)) == 0) {
		errno = EINVAL;
        return MAP_FAILED;
    }

	if (fd == -1) {
		return (void *)syscall(__NR_mmap, (long)addr, length, prot, flags | MAP_PRIVATE, -1, 0);
    }

	int ret = syscall(__NR_mmap, (long)addr, length, prot, flags, fd, offset);

	errno = -ret;
	return MAP_FAILED;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */
	long ret = syscall(__NR_mremap, (unsigned long) old_address, old_size, new_size, flags);

	if (ret >= 0) {
		return (void *)ret;
	}

	errno = -ret;
	return MAP_FAILED;
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	int ret = syscall(__NR_munmap, (unsigned long) addr, length);

	if (ret >= 0) {
		return ret;
	}

	errno = -ret;
	return -1;
}
