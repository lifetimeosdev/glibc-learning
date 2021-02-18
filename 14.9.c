#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    int ret;

    ret = unlink("./a.out");
    if (ret < 0)
    {
        perror("unlink error");
        return 1;
    }

    mkdir("/tmp/a", 0700);
    mkdir("/tmp/b", 0700);
    mkdir("/tmp/c", 0700);

    ret = rmdir("/tmp/a");
    if (ret < 0)
    {
        perror("rmdir error");
        return 1;
    }

    ret = remove("/tmp/b");
    if (ret < 0)
    {
        perror("remove error");
        return 1;
    }

    ret = rename("./test.txt", "./test.txt.bak");
    if (ret < 0)
    {
        perror("rename error");
        return 1;
    }

    return 0;
}