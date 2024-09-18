// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */
	// sys_mmap = 9
	long ret = syscall(9, addr, length, prot, flags, fd, offset);

	// procesare rezultat
	if(ret < 0) {
		errno = -ret;
		return (void*)-1;
	}

	return (void*)ret;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */
	// sys_mremap = 25
	long ret = syscall(25, old_address, old_size, new_size, flags);

	// procesare rezultat
	if (ret < 0) {
		errno = -ret;
		return (void*)-1;
	}

	return (void*)ret;
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	// sys_munmap = 11
	long ret = syscall(11, addr, length);

	// procesare rezultat
	if (ret < 0) {
		errno = -ret;
		return -1;
	}
	return ret;
}
