#include <stdio.h>
#include <sys/resource.h>
#include <errno.h>
#include <unistd.h>

void print_priority()
{
    errno = 0;
    int pri = getpriority(PRIO_PROCESS, 0);
    if (errno != 0)
        perror("getpriority error");
    else
        printf("priority is %d\n", pri);
}

int main(int argc, char *argv[])
{
    printf("PRIO_MAX=%d\n", PRIO_MAX);
    printf("PRIO_MIN=%d\n", PRIO_MIN);
    print_priority();

    int ret = setpriority(PRIO_PROCESS, 0, -20);
    if (ret == -1)
    {
        perror("setpriority error");
        return 1;
    }
    print_priority();
    nice(10);
    print_priority();
    return 0;
}