#include <stdio.h>
#include <sys/stat.h>
#include <error.h>
#include <errno.h>
#include <fcntl.h>

void check_file_type(struct stat *statbuf)
{
    if (S_ISDIR(statbuf->st_mode))
        printf("It is a directory\n");
    else if (S_ISCHR(statbuf->st_mode))
        printf("It is a character special file\n");
    else if (S_ISBLK(statbuf->st_mode))
        printf("It is a block special file\n");
    else if (S_ISREG(statbuf->st_mode))
        printf("It is a regular file\n");
    else if (S_ISFIFO(statbuf->st_mode))
        printf("It is a FIFO/PIPE special file\n");
    else if (S_ISLNK(statbuf->st_mode))
        printf("It is a symbolic link");
    else if (S_ISSOCK(statbuf->st_mode))
        printf("It is a socket");
    else if (S_TYPEISMQ(statbuf))
        printf("It is a message queue object\n");
    else if (S_TYPEISSEM(statbuf))
        printf("It is a semaphore object\n");
    else if (S_TYPEISSHM(statbuf))
        printf("It is a shared memory object\n");
    else
        printf("unknow\n");
}

int main(int argc, char *argv[])
{
    struct stat statbuf;
    int ret, fd;

    ret = stat("./a.out", &statbuf);
    if (ret < 0)
        error(1, errno, "stat error");

    fd = open("./a.out", O_RDONLY);
    if (fd < 0)
        error(1, errno, "stat error");

    ret = fstat(fd, &statbuf);
    if (ret < 0)
        error(1, errno, "stat error");

    check_file_type(&statbuf);

    return 0;
}
