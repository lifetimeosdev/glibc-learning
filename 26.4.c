#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *args[] = {"ls", "-a", NULL};
    char *env[] = {"A=B", NULL};
    execve("/bin/ls", args, env);
    return 0;
}