#include <stdio.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <utime.h>
#include <error.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    struct stat statbuf;
    int ret;

    ret = stat("./a.out", &statbuf);
    if (ret)
        error(1, errno, "stat error");

    struct utimbuf time = {1, 1};

    ret = utime("./a.out", &time);
    if (ret)
        error(1, errno, "utime error");

    struct timeval times[2];
    times[0].tv_sec = 2;
    times[0].tv_usec = 2;
    times[1].tv_sec = 2;
    times[1].tv_usec = 2;
    ret = utimes("./a.out", times);
    if (ret)
        error(1, errno, "utimes error");

    return 0;
}