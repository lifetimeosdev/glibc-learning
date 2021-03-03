#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
    struct tm *t1 = NULL;
    time_t tt;

    printf("before = %p\n", t1);
    time(&tt);
    t1 = localtime(&tt);
    if (t1)
    {
        printf("after  = %p\n", t1);
        printf("time is %ld\n", tt);
        printf("%s  %d-%d-%d %d:%d:%d\n", t1->tm_zone, t1->tm_year + 1900,
               t1->tm_mon + 1, t1->tm_mday, t1->tm_hour, t1->tm_min, t1->tm_sec);
    }
    else
    {
        printf("%p\n", t1);
        printf("time is %ld\n", tt);
        perror("localtime error");
        return 1;
    }

    struct tm t2;
    gmtime_r(&tt, &t2);
    printf("%s  %d-%d-%d %d:%d:%d\n", t2.tm_zone, t2.tm_year + 1900,
           t2.tm_mon + 1, t2.tm_mday, t2.tm_hour, t2.tm_min, t2.tm_sec);

    time_t tt2 = mktime(t1);
    printf("tt2 = %ld\n", tt2);

    time_t tt3 = timegm(&t2);
    printf("tt3 = %ld\n", tt3);

    return 0;
}