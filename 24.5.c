#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void int_handler(int signum)
{
    psignal(signum, NULL);
}

int main(int argc, char *argv[])
{
    signal(SIGINT, int_handler);
    int ret = raise(SIGINT);
    if (ret < 0)
    {
        fprintf(stderr, "raise error\n");
        return 1;
    }
   ret = kill(getpid(), SIGINT);
    if (ret ==-1)
    {
        fprintf(stderr, "kill error\n");
        return 2;
    }
   
    return 0;
}