#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    fd_set fds;
    FD_ZERO(&fds);

    int fd = open("test.txt", O_RDWR, 0644);
    FD_SET(fd, &fds);
    int is_set = FD_ISSET(fd, &fds);
    printf("fd %d is set: %d\n", fd, is_set);

    FD_CLR(fd, &fds);
    is_set = FD_ISSET(fd, &fds);
    printf("fd %d is set: %d\n", fd, is_set);

    FD_SET(fd, &fds);

    return 0;
}