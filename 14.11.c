#include <stdio.h>
#include <unistd.h>
#include <error.h>
#include <errno.h>
#include <sys/stat.h>


int main(int argc, char *argv[])
{
    int ret;
    struct stat statbuf;

    ret = chown("./a.out", 1234, 1234);
    if (ret < 0)
        error(1, errno, "chown error");
    ret = stat("./a.out", &statbuf);
    if (ret < 0)
        error(1, errno, "stat error");

    return 0;
}