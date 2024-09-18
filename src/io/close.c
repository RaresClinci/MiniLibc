// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	/* TODO: Implement close(). */
	// sys_close = 3
	int ret = syscall(3, fd);

	// procesare rezultat
	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return ret;
}
