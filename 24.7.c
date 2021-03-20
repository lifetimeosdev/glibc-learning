#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void int_handler(int signum)
{
    psignal(signum, NULL);
    sleep(5);
}

int main(int argc, char *argv[])
{
    struct sigaction sa;
    sigset_t block_mask, waitting_mask;
    // sigemptyset(&block_mask);
    sigfillset(&block_mask);
    sa.sa_handler = int_handler;
    sa.sa_mask = block_mask;
    sa.sa_flags = SA_INTERRUPT;

    // sigprocmask(SIG_BLOCK, &block_mask, NULL);

    sigaction(SIGINT, &sa, NULL);

    while (1)
    {
        sigpending(&waitting_mask);
        if (sigismember(&waitting_mask, SIGINT))
            puts("pending SIGINT");
    }

    return 0;
}