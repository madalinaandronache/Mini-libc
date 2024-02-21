#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

int puts(const char *str) {
    size_t len = strlen(str);
    ssize_t bytes_written = write(1, str, len);

    if (bytes_written < 0) {
        errno = -EOF;
        return EOF;
    }

    int res = write(1, "\n", 1);
    if (res != 1) {
        errno = -EOF;
        return EOF;
    }

    return 0;
}
