#include <sys/mman.h>
#include <stdlib.h>
#include <stdio.h>
#include <error.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    short size = 64;
    int ret = -1;
    char *str = (char *)malloc(size);
    // ret = mlock(str, size);
    // printf("The return value is %d\n", ret);

    ret = mlockall(MCL_CURRENT);
    printf("The return value is %d\n", ret);
    printf("The errno is %d\n", errno);

    ret = munlockall();
    printf("The return value is %d\n", ret);
    printf("The errno is %d\n", errno);

    free(str);

    return 0;
}