#include <sys/types.h>
#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *ep;

    dp = opendir("./");
    if (dp != NULL)
    {
        while (ep = readdir(dp))
            puts(ep->d_name);
        closedir(dp);
    }
    else
        perror("Couldn't open the directory");

    return 0;
}