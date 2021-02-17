#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int ret = link("/tmp/a.txt", "/tmp/b.txt");
    if (ret == -1)
    {
        perror("link error");
        return 1;
    }

    DIR *dp = opendir("/tmp");
    int dfd = dirfd(dp);
    ret = linkat(dfd, "a.txt", dfd, "c.txt", AT_SYMLINK_FOLLOW);
    if (ret == -1)
    {
        perror("linkat error");
        return 1;
    }

    return 0;
}