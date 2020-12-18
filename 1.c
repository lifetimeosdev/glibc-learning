#define _GNU_SOURCE

#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv)
{
    printf("errno=%d\n", errno);
    printf("EACCESS is %s\n", strerror(EACCES));

    char buf[BUFSIZ];
    printf("EACCESS is %s\n", strerror_r(EACCES, buf, BUFSIZ));

    errno = EACCES;
    perror("Error is ");

    return 0;
}