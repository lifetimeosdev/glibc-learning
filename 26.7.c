#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    execlp("ls", "ls", NULL);

    return 0;
}