#include <stdio.h>
#include <time.h>

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

    return 0;
}