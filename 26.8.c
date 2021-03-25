#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void sigchld_handler(int signum)
{
    int pid, status, serrno;
    serrno = errno;
    while (1)
    {
        pid = waitpid(WAIT_ANY, &status, WNOHANG);
        if (pid < 0)
        {
            perror("waitpid error");
            break;
        }
        if (pid == 0)
            break;
        printf("child termination.pid=%d status=%d\n", pid, status);
    }
    errno = serrno;
}

int main(int argc, char *argv[])
{
    struct sigaction sa;
    sigset_t set;
    int pid;

    sigemptyset(&set);
    sa.sa_handler = sigchld_handler;
    sa.sa_flags = 0;
    sa.sa_mask = set;

    sigaction(SIGCHLD, &sa, NULL);
    pid = fork();
    if (pid == 0)
    {
        exit(EXIT_SUCCESS);
    }
    else if (pid < 0)
    {
        printf("fork error\n");
        _exit(1);
    }
    else
        pause();

    return 0;
}