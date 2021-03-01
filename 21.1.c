#include <stdio.h>
#include <time.h>
#include <sys/times.h>

int main(int argc, char *argv[])
{
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    for (size_t i = 0; i < 1000000000; i++)
    {
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("cpu time used is %f\n", cpu_time_used);

    struct tms t;
    clock_t ret = times(&t);
    printf("times return is %ld\n", ret);
    printf("tms_utime is %ld\n", t.tms_utime);
    printf("tms_stime is %ld\n", t.tms_stime);

    return 0;
}