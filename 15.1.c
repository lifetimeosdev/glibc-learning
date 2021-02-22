#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

//Read characters from the pipe and echo them to stdout
void read_from_pipe(int file)
{
    FILE *stream;
    int c;
    stream = fdopen(file, "r");
    while( (c = fgetc(stream))!= EOF)
        putchar(c);
    fclose(stream);
}

//Write the random text to the pipe
void write_to_pipe(int file)
{
    FILE *stream;
    stream = fdopen(file, "w");
    fprintf(stream, "Hello, world!\n");
    fprintf(stream, "goodbye, world!\n");
    fclose(stream);
}

int main(int argc, char *argv[])
{
    pid_t pid;
    int mypipe[2];

    if(pipe(mypipe)){
        fprintf(stderr, "pipe failed.\n");
        return EXIT_FAILURE;
    }

    pid = fork();
    if (pid == (pid_t)0){
        //This is the child process. 
        //Close other end first.
        close(mypipe[1]);
        read_from_pipe(mypipe[0]);
        return EXIT_SUCCESS;
    }else if(pid < (pid_t)0){
        fprintf(stderr,"Fork failed.\n");
        return EXIT_FAILURE;
    }else{
        close (mypipe[0]);
        write_to_pipe(mypipe[1]);
        return EXIT_SUCCESS;
    }

    return 0;
}