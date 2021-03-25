#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *env = {"A=B"};

    execle("/bin/ls", "ls", "-a", NULL, env);

    return 0;
}