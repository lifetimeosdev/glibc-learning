#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int set_close_exec_flag(int desc, int value)
{
    int oldflags = fcntl(desc, F_GETFD, 0);
    if (oldflags < 0)
        return oldflags;
    if (value != 0)
        oldflags |= FD_CLOEXEC;
    else
        oldflags &= ~FD_CLOEXEC;
    return fcntl(desc, F_SETFD, oldflags);
}

int main(int argc, char *argv[])
{
    int fd = open("test.txt", O_RDWR, 0644);
    int fd2 = dup(fd);
    int fd3 = dup2(fd, 22);
    printf("fd = %d , fd2 = %d , fd3 = %d\n", fd, fd2, fd3);

    off_t offset = lseek(fd, 2, SEEK_SET);
    printf("fd offset is %ld\n", offset);
    offset = lseek(fd2, 0, SEEK_CUR);
    printf("fd offset is %ld\n", offset);
    offset = lseek(fd3, 0, SEEK_CUR);
    printf("fd offset is %ld\n", offset);

    return 0;
}