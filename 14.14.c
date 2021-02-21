#include <stdio.h>
#include <error.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int ret;
    int fd;

    ret = truncate("./a.txt", 1024 * 1024);
    if (ret)
        error(1, errno, "truncate error");

    fd = open("./a.txt", O_RDWR);
    printf("fd = %d\n", fd);
    ret = posix_fallocate(fd, 0, 1024 * 1024 * 10);
    if (ret)
        error(1, errno, "posix_fallocate error");
    return 0;
}