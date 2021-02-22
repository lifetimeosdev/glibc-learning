#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int ret;
    ret = mkfifo("./a.fifo", 0744);
    if (ret)
    {
        fprintf(stderr, "could not mkfifo\n");
        return EXIT_FAILURE;
    }
    pid_t pid;
    pid = fork();
    if (pid < 0)
    {
        fprintf(stderr, "fork error\n");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        //child
        int fd = open("./a.fifo", O_WRONLY);
        FILE *stream;
        stream = fdopen(fd, "w");
        fprintf(stream, "Hello...\n");
        exit(EXIT_SUCCESS);
    }
    else
    {
        //parent
        int fd = open("./a.fifo", O_RDONLY);
        FILE *stream;
        stream = fdopen(fd, "r");
        char buf[1024] = {0};
        fgets(buf, sizeof(buf), stream);
        printf("%s", buf);
        exit(EXIT_SUCCESS);
    }

    return 0;
}