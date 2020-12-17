#include <stdio.h>
#include <errno.h>

int main(int argc, char **argv)
{
    printf("%s\n", "hello world");
    printf("%d\n", errno);
    return 0;
}