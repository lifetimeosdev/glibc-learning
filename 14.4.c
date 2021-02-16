#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *ep;

    dp = opendir("./");
    if (dp)
    {
        ep = readdir(dp);
        puts(ep->d_name);
        ep = readdir(dp);
        puts(ep->d_name);

        rewinddir(dp);
        ep = readdir(dp);
        puts(ep->d_name);

        long pos = telldir(dp);
        printf("dirctory pos = %ld\n", pos);

        seekdir(dp, pos);
    }
    else
        perror("Couldn't open the directory");

    return 0;
}