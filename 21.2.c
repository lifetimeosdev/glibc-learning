#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int main(int argc, char *argv[])
{
    time_t t;
    time(&t);
    printf("time result is %ld\n", t);

    int ret;
    struct timespec ts;
    ret = clock_gettime(CLOCK_REALTIME, &ts);
    if (ret)
    {
        fprintf(stderr, "clock_gettime error.");
        return 1;
    }
    else
        printf("realtime: sec=%ld\tns=%ld\n", ts.tv_sec, ts.tv_nsec);

    ret = clock_gettime(CLOCK_MONOTONIC, &ts);
    if (ret)
    {
        fprintf(stderr, "clock_gettime error.");
        return 1;
    }
    else
        printf("monotonic: sec=%ld\tns=%ld\n", ts.tv_sec, ts.tv_nsec);

    ret = clock_getres(CLOCK_REALTIME, &ts);
    if (ret)
    {
        fprintf(stderr, "clock_getres error.");
        return 1;
    }
    else
        printf("getres: sec=%ld\tns=%ld\n", ts.tv_sec, ts.tv_nsec);

    struct timeval tv;
    ret = gettimeofday(&tv, NULL);
    if (ret)
    {
        fprintf(stderr, "gettimeofday error.");
        return 1;
    }
    else
        printf("timeval: sec=%ld\tus=%ld\n", tv.tv_sec, tv.tv_usec);

    clock_gettime(CLOCK_REALTIME, &ts);
    ts.tv_sec -= 120;
    ret = clock_settime(CLOCK_REALTIME, &ts);
    if (ret)
    {
        perror("gettimeofday error");
        return 1;
    }
    return 0;
}