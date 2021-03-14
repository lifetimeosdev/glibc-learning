#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <ucontext.h>
#include <sys/time.h>

static volatile int expired;
static ucontext_t uc[3];
static int switches;

static void f(int n)
{
    int m = 0;
    while (1)
    {
        if (++m % 100 == 0)
        {
            putchar('.');
            fflush(stdout);
        }
        if (expired)
        {
            if (++switches == 20)
                return;
            printf("\nswitching from %d to %d\n", n, 3 - n);
            expired = 0;
            swapcontext(&uc[n], &uc[3 - n]);
        }
    }
}

void hadler(int signal)
{
    expired = 1;
}

int main(int argc, char *argv[])
{
    struct sigaction sa;
    struct itimerval it;
    char st1[8192];
    char st2[8192];

    sa.sa_flags = SA_RESTART;
    sigfillset(&sa.sa_mask);
    sa.sa_handler = hadler;
    it.it_interval.tv_sec = 0;
    it.it_interval.tv_usec = 1;
    it.it_value = it.it_interval;

    if (sigaction(SIGPROF, &sa, NULL) < 0 || setitimer(ITIMER_PROF, &it, NULL) < 0 || getcontext(&uc[1]) == -1 || getcontext(&uc[2]) == -1)
        abort();
    uc[1].uc_link = &uc[0];
    uc[1].uc_stack.ss_sp = st1;
    uc[1].uc_stack.ss_size = sizeof(st1);
    makecontext(&uc[1], (void (*)(void))f, 1, 1);

    uc[2].uc_link = &uc[0];
    uc[2].uc_stack.ss_sp = st2;
    uc[2].uc_stack.ss_size = sizeof(st2);
    makecontext(&uc[2], (void (*)(void))f, 1, 2);

    swapcontext(&uc[0], &uc[1]);
    putchar('\n');

    return 0;
}