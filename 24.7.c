#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void int_handler(int signum)
{
    psignal(signum, NULL);
    sleep(30);
}

int main(int argc, char *argv[])
{
    struct sigaction sa;
    sigset_t set;
    // sigemptyset(&set);
    sigfillset(&set);
    sa.sa_handler = int_handler;
    sa.sa_mask = set;
    sa.sa_flags = 0;

    // sigprocmask(SIG_BLOCK, &set, NULL);

    sigaction(SIGINT, &sa, NULL);

    while (1)
        ;

    return 0;
}