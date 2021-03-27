#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SHELL "/bin/sh"

int my_system(const char *command)
{
    int status;
    pid_t pid;
    pid = fork();
    if (pid == 0)
    {
        //Child
        execl(SHELL, SHELL, "-c", command, NULL);
        _exit(EXIT_FAILURE);
    }
    else if (pid < 0)
        status = -1;
    else
    {
        //parent
        if (waitpid(pid, &status, 0) != pid)
            status = -1;
    }
    return status;
}

int main(int argc, char *argv[])
{
    int status = my_system("ls -alh");
    if (status == -1)
    {
        fprintf(stderr, "my_system exec error\n");
        return 1;
    }

    return 0;
}