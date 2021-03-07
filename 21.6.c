#define _XOPEN_SOURCE
#include <stdio.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[])
{
    time_t t1;
    struct tm tm1, *tm1p;
    char str[64];

    t1 = time(&t1);
    tm1p = localtime_r(&t1, &tm1);
    char *ta = asctime_r(tm1p, str);
    printf("%s", ta);

    ta = ctime_r(&t1, str);
    printf("%s", ta);

    int ret = strftime(str, sizeof(str), "%Y-%m-%d %H:%M:%S %Z", tm1p);
    printf("%s\n", ta);

    struct tm tm2;
    memset(&tm2, '\0', sizeof(tm2));
    strptime(str, "%Y-%m-%d %H:%M:%S %Z", &tm2);
    printf("%d-%d-%d %d:%d:%d\n", tm2.tm_year + 1900,
           tm2.tm_mon + 1, tm2.tm_mday, tm2.tm_hour, tm2.tm_min, tm2.tm_sec);

    return 0;
}