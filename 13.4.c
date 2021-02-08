#include <sys/uio.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd = open("test.txt", O_RDWR, 0644);
    struct iovec vectors[2];
    char buf1[3];
    char buf2[4];
    vectors[0].iov_base = buf1;
    vectors[0].iov_len = sizeof(buf1) - 1;
    vectors[1].iov_base = &buf2;
    vectors[1].iov_len = sizeof(buf2) - 1;

    ssize_t readn = readv(fd, vectors, 2);
    printf("readv return value is %ld\n", readn);
    buf1[2] = buf2[3] = '\0';
    printf("buf1 value is %s\n", buf1);
    printf("buf2 value is %s\n", buf2);

    ssize_t writen = writev(fd, vectors, 2);
    printf("writev return value is %ld\n", writen);

    readn = preadv(fd, vectors, 2, 2);
    printf("preadv return value is %ld\n", readn);
    buf1[2] = buf2[3] = '\0';
    printf("buf1 value is %s\n", buf1);
    printf("buf2 value is %s\n", buf2);

    writen = pwritev(fd, vectors, 2, 6);
    printf("writev return value is %ld\n", writen);

    close(fd);

    return 0;
}