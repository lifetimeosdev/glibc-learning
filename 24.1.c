#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

void sig_hangup_handler(int signum)
{
    psignal(signum, NULL);
}

int main(int argc, char *argv[])
{
    char *msg = strsignal(1);
    printf("signal 1 is %s\n", msg);

    psignal(1, "signal 1 is ");
    signal(SIGHUP, sig_hangup_handler);

    sleep(10);
    return 0;
}