#include <stdio.h>
#include <sys/timex.h>

int main(int argc, char *argv[])
{
    struct ntptimeval ntv;
    int ret;

    ret = ntp_gettime(&ntv);
    if (ret)
    {
        if (ret == TIME_ERROR)
            fprintf(stderr, "ntp_gettime is not properly set up\n");
        else
            perror("ntp_gettime error");
        return 1;
    }
    else
        printf("sec=%ld us=%ld maxerror=%ld esterror=%ld\n", ntv.time.tv_sec, ntv.time.tv_usec,
               ntv.maxerror, ntv.esterror);
    return 0;
}