#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    sync();

    int fd = open("test.txt", O_RDWR, 0644);
    int ret = fsync(fd);
    printf("fsync return value is %d\n", ret);

    ret = fdatasync(fd);
    printf("fdatasync return value is %d\n", ret);

    return 0;
}