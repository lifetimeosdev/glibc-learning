#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_hangup_handler(int signum)
{
    psignal(signum, NULL);
}
int main(int argc, char *argv[])
{
    struct sigaction sa;
    sa.sa_handler = sig_hangup_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;

    int ret = sigaction(SIGHUP, &sa, NULL);
    if (ret == -1)
    {
        perror("sigaction error");
        return 1;
    }
    sleep(10000);
    return 0;
}