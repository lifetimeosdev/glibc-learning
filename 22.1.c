#include <stdio.h>
#include <sys/resource.h>
#include <sys/vtimes.h>

int main(int argc, char *argv[])
{
    struct rusage rusage;
    int ret = getrusage(RUSAGE_SELF, &rusage);
    if (ret == -1)
    {
        perror("getrusage error");
        return 1;
    }

    printf("Time spent executing user instructions:%ld s %ld us\n",
           rusage.ru_utime.tv_sec, rusage.ru_utime.tv_usec);
    printf("Time spent in operating system code on behalf of processes:%ld s %ld us\n",
           rusage.ru_stime.tv_sec, rusage.ru_stime.tv_usec);

    struct vtimes vt;

    ret = vtimes(&vt, NULL);
    if (ret == -1)
    {
        perror("vtimes error");
        return 1;
    }

    struct rlimit rl;
    ret = getrlimit(RLIMIT_NOFILE, &rl);
    if (ret == -1)
    {
        perror("getrlimit error");
        return 1;
    }
    printf("cpu limit max: %ld cur: %ld\n", rl.rlim_max, rl.rlim_cur);

    rl.rlim_cur = 1024;
    setrlimit(RLIMIT_NOFILE, &rl);
    ret = getrlimit(RLIMIT_NOFILE, &rl);
    if (ret == -1)
    {
        perror("getrlimit error");
        return 1;
    }
    printf("cpu limit max: %ld cur: %ld\n", rl.rlim_max, rl.rlim_cur);

    return 0;
}