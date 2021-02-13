#include <stdio.h>
#include <aio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int fd = open("test.txt", O_RDWR, 0644);
    printf("fd = %d\n", fd);

    char buf[1024];

    struct aiocb aio = {0};
    aio.aio_offset = -1;
    aio.aio_fildes = fd;
    aio.aio_buf = buf;
    aio.aio_nbytes = 1024;
    aio.aio_sigevent.sigev_notify = SIGEV_NONE;

    int ret = aio_read(&aio);
    printf("aio_read return value is %d\n", ret);
    if (ret == -1)
        perror("aio_read error");

    ssize_t aret = aio_return(&aio);
    printf("aio_return value is %ld\n", aret);

    ret = aio_error(&aio);
    printf("aio_error return value is %d\n", ret);
    perror("aio_error");

    ret = aio_fsync(O_SYNC, &aio);
    printf("aio_fsync return value is %d\n", ret);

    ret = aio_cancel(fd, &aio);
    printf("aio_cancel return value is %d\n", ret);

    return 0;
}