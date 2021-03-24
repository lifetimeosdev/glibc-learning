#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int ret;
    ret = system("/bin/ls -alh");
    printf("system return value is %d\n", ret);

    return 0;
}