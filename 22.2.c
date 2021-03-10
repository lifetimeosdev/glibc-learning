#include <stdio.h>
#include <sched.h>

int main(int argc, char *argv[])
{
    int max = sched_get_priority_max(SCHED_RR);
    int min = sched_get_priority_min(SCHED_RR);
    printf("min=%d max=%d\n", min, max);

    struct sched_param sp;
    sp.sched_priority = 90;

    int ret = sched_setscheduler(0, SCHED_RR, &sp);
    if (ret == -1)
    {
        perror("sched_setscheduler error");
        return 1;
    }

    ret = sched_getscheduler(0);
    printf("current scheduler is %d\n", ret);

    sp.sched_priority = -100;
    sched_getparam(0, &sp);
    printf("sched_priority is %d\n", sp.sched_priority);

    struct timespec ts = {
        .tv_nsec = 0,
        .tv_sec = 0};
    ret = sched_rr_get_interval(0, &ts);
    if (ret == -1)
    {
        perror("sched_rr_get_interval error");
        return 1;
    }
    printf("sched_rr_get_interval is %lds %ldns\n", ts.tv_sec, ts.tv_nsec);

    ret = sched_yield();
    if (ret == -1)
    {
        perror("sched_yield error");
        return 1;
    }

    return 0;
}