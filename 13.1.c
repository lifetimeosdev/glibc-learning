#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd;
    int ret;
    fd = open("test.txt", O_RDONLY, 0644);
    if (fd < 0)
        printf("open error.");

    ret = close(fd);
    printf("close return value is %d\n", ret);

    fd = creat("test.txt",0644);
    printf("crate fd is %d\n", fd);

    return 0;
}