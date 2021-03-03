#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int main(int argc, char *argv[])
{
    int ret;
    struct timeval delta = {0};
    struct timeval olddelta = delta;

    delta.tv_usec += 100;
    ret = adjtime(&delta, &olddelta);
    if (ret)
    {
        perror("adjtime error");
        return 1;
    }
    return 0;
}