#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd;
    fd = open("test.txt", O_RDWR, 0644);
    off_t offset = lseek(fd, 3, SEEK_CUR);
    printf("lseek return value is %ld\n", offset);

    offset = lseek(fd, 5, SEEK_SET);
    printf("lseek return value is %ld\n", offset);

    offset = lseek(fd, 1024, SEEK_END);
    printf("lseek return value is %ld\n", offset);

    offset = lseek(fd, -4, SEEK_END);
    printf("lseek return value is %ld\n", offset);

    offset = lseek(fd, 0, SEEK_CUR);
    printf("lseek return value is %ld\n", offset);

    int fd2 = open("test.txt", O_RDWR, 0644);
    offset = lseek(fd2, 0, SEEK_CUR);
    printf("lseek on fd2 return value is %ld\n", offset);

    int fd3 = dup(fd);
    printf("fd=%d,fd3=%d\n", fd, fd3);
    offset = lseek(fd3, 0, SEEK_CUR);
    printf("lseek on fd3 return value is %ld\n", offset);

    FILE *fp;
    fp = fdopen(fd3, "r+");
    int fd4 = fileno(fp);
    printf("fd4=%d\n", fd4);
    fflush(fp);
    

    return 0;
}