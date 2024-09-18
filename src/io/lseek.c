// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence)
{
	/* TODO: Implement lseek(). */
	// sys_open = 8
	off_t pos = syscall(8, fd, offset, whence);

	// procesare rezultat
	if (pos < 0) {
		errno = -pos;
		return (off_t)-1;
	}

	return pos;
}
