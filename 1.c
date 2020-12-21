#define _GNU_SOURCE

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

FILE *open_sesame(char *name);

int main(int argc, char **argv)
{
    printf("errno=%d\n", errno);
    printf("EACCESS is %s\n", strerror(EACCES));

    char buf[BUFSIZ];
    printf("EACCESS is %s\n", strerror_r(EACCES, buf, BUFSIZ));

    errno = EACCES;
    perror("Error is ");

    printf("program invocation name is %s\n", program_invocation_name);
    printf("program invocation short name is %s\n", program_invocation_short_name);

    open_sesame("/tmp/1.txt");

    return 0;
}

FILE *
open_sesame(char *name)
{
    FILE *stream;

    errno = 0;
    stream = fopen(name, "r");
    if (stream == NULL)
    {
        fprintf(stderr, "%s: Could't open file %s; %s\n",
                program_invocation_short_name, name, strerror(errno));
        exit(EXIT_FAILURE);
    }
    else
        return stream;
}