#include <stdio.h>
#include <sys/stat.h>
#include <error.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

    mode_t mode = umask(0222);
    printf("old umask is %o\n", mode);

    int ret = chmod("./a.out", 0644);
    if (ret < 0)
        error(1, errno, "chmod error");

    ret = access("./a.out", X_OK);
    if (ret)
        printf("file can not execute\n");

    return 0;
}