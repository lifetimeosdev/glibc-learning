#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <error.h>

int main(int argc, char *argv[])
{
    long page_size = sysconf(_SC_PAGESIZE);
    printf("default page size is %ld\n", page_size);

    int fd = open("test.txt", O_RDONLY, 0644);
    char *address = (char *)mmap(NULL, page_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (address != MAP_FAILED)
        printf("result is %s\n", address);
    else
        perror("mmap error.");

    int ret = msync(address, page_size, MS_SYNC);
    printf("msync return value is %d\n", ret);

    ret = madvise(address, page_size, MADV_RANDOM);
    printf("madvise return value is %d\n", ret);

    fd = shm_open("test.shm", O_RDWR | O_CREAT, 0644);
    if (fd == -1)
        perror("shm_open error");
    else
        printf("shm_open return fd is %d\n", fd);

    ret = shm_unlink("test.shm");
    printf("shm_unlink return value is %d\n", ret);

    ret = munmap(address, page_size);
    printf("munmap return value is %d\n", ret);
    return 0;
}