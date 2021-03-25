#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *args[] = {"ls", NULL};
    execvp("ls", args);

    return 0;
}