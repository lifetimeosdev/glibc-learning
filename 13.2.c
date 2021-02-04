#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
    char buf[BUFSIZ];
    int fd = open("test.txt", O_RDWR | O_CREAT, 0644);
    ssize_t n = read(fd, &buf, BUFSIZ);
    buf[n] = '\0';
    printf("read return value is %ld-%s\n", n, buf);

    n = pread(fd, &buf, 2, 2);
    buf[n] = '\0';
    printf("read return value is %ld-%s\n", n, buf);

    //pread does not change the the fp position
    n = read(fd, &buf, BUFSIZ);
    buf[n] = '\0';
    printf("read return value is %ld-%s\n", n, buf);

    char str[] = "hello";
    n = write(fd, str, sizeof(str) - 1);
    printf("write return value is %ld\n", n);

    n = pwrite(fd, str, sizeof(str) - 1, 2);
    printf("pwrite return value is %ld\n", n);

    int ret = close(fd);
    printf("close return value is %d\n", ret);

    return 0;
}