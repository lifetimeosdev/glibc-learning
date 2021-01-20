#include <stdio.h>
#include <wordexp.h>
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int expand_and_execute(const char *program, const char **options)
{
    wordexp_t result;
    pid_t pid;
    int status, i;
    switch (wordexp(program, &result, 0))
    {
    case 0: //successful
        break;
    case WRDE_NOSPACE:
        wordfree(&result);
        break;
    default:
        return -1;
    }

    for (i = 0; options[i] != NULL; i++)
    {
        if (wordexp(options[i], &result, WRDE_APPEND))
        {
            wordfree(&result);
            return -1;
        }
    }
    //printf("%s\n", result.we_wordv[0]);
    //printf("%s\n", result.we_wordv[1]);

    pid = fork();
    if (pid == 0) //child
    {
        execv(result.we_wordv[0], result.we_wordv);
        exit(EXIT_FAILURE);
    }
    else if (pid < 0) //error
    {
        status = -1;
    }
    else //parent
        if (waitpid(pid, &status, 0) != pid)
        status = -1;

    wordfree(&result);
    return status;
}
int main(int argc, char *argv[])
{
    const char *options[] = {"$PATH", NULL};
    int status = expand_and_execute("/bin/echo", options);
    printf("return status is %d\n", status);

    return 0;
}
