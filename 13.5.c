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

    return 0;
}