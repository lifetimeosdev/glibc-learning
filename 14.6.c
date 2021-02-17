#define _XOPEN_SOURCE 700

#include <stdio.h>
#include <ftw.h>

int ftw_func(const char *name, const struct stat *stat, int flag)
{
    if (flag == FTW_NS)
        return 1;
    printf("%s\n", name);

    return 0;
}
int nftw_func(const char *name, const struct stat *stat,
              int flag, struct FTW *ftw)
{
    if (flag == FTW_NS)
        return 1;
    printf("%s\n", name);

    return 0;
}

int main(int argc, char *argv[])
{
    int ret;

    ret = ftw("/tmp", ftw_func, 1);
    printf("\nftw return value is %d\n", ret);

    ret = nftw("/tmp", nftw_func, 1, FTW_CHDIR);
    printf("\nnftw return value is %d\n", ret);

        return 0;
}