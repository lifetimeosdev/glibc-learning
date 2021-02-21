#include <stdio.h>
#include <sys/stat.h>
#include <error.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int ret = mknod("./a.dev", S_IFCHR|S_IRUSR|S_IWUSR, 1);
    if(ret)
        error(-1,errno, "mknod error");

    return 0;
}