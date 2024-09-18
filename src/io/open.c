// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */
	// obtinem flagurile
	mode_t mode = 0;
	va_list args;
	va_start(args, flags);

	if (flags & O_CREAT)
		mode = va_arg(args, mode_t);

	va_end(args);

	// sys_open = 2
	int fd = syscall(2, filename, flags, mode);

	// procesare rezultat
	if (fd < 0) {
		errno = -fd;
		return -1;
	}

	return fd;
}
