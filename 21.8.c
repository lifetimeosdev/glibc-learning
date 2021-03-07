#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
    const struct timeval t = {.tv_sec = 5,
                              .tv_usec = 0};

    struct itimerval it;
    it.it_interval = it.it_value = t;

    int ret = setitimer(ITIMER_REAL, &it, NULL);
    if (ret == -1)
    {
        perror("setitimer error");
        return 1;
    }

    int remain_sec = sleep(100);
    printf("sleep remain sec is %d", remain_sec);

    struct timespec t1, t2;
    t1.tv_sec = 100;
    t1.tv_nsec = 0;
    t2.tv_sec = 0;
    t2.tv_nsec = 0;
    nanosleep(&t1, &t2);
    return 0;
}