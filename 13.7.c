#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>

int input_timeout(int filedes, unsigned int seconds)
{
    fd_set set;
    struct timeval timeout;

    FD_ZERO(&set);
    FD_SET(filedes, &set);

    timeout.tv_sec = seconds;
    timeout.tv_usec = 0;

    return select(FD_SETSIZE, &set, NULL, NULL, &timeout);
}

int main(int argc, char *argv[])
{
    fprintf(stderr, "select returned %d\n", input_timeout(STDIN_FILENO, 5));
    return 0;
}