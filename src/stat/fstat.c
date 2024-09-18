// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	/* TODO: Implement fstat(). */
	// 	sys_fstat = 5
	int ret = syscall(5, fd, st);

	// procesam rezultatul
	if(ret < 0) {
		errno = -ret;
		return -1;
	}

	return ret;
}
