// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length)
{
	/* TODO: Implement ftruncate(). */
	// 	sys_ftruncate = 77
	long int res = syscall(77, fd, length);

	// procesam rezultatul
	if (res < 0) {
		errno = -res;
		return -1;
	}

	return res;
}
