#include <internal/io.h>
#include <internal/syscall.h>
#include <internal/types.h>
#include <errno.h>
#include <string.h>
#include <time.h>

int nanosleep(const struct timespec *requested_time, struct timespec *remaining) {
    // sys_nanosleep = 35
    long ret = syscall(35, requested_time, remaining);

    // procesam rezultatul
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

unsigned int sleep(unsigned int seconds) {
    // parsam inputul in formatul timespec
    struct timespec time;
    time.tv_nsec = 0;
    time.tv_sec = seconds;

    int ret = nanosleep(&time, NULL);

    return ret;
}
