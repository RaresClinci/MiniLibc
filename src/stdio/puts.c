
#include <internal/io.h>
#include <internal/syscall.h>
#include <internal/types.h>
#include <errno.h>
#include <string.h>

int puts(const char *str){
    int len = strlen(str);

    // scriem stringul, urmat de endline
    int ret1 = write(1, str, len);
    int ret2 = write(1, "\n", 1);

    // verificam daca afisarile s-au facu corect
    if (ret1 < 0) {
        errno = -ret1;
        return -1;
    }

    if (ret2 < 0) {
        errno = -ret2;
        return -1;
    }

    return ret1;
}
