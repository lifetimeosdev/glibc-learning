#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *args[] =
        {
            "ls",
            "-a",
            "-l",
            NULL};
    execv("/bin/ls", args);


    return 0;
}