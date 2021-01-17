#define _GNU_SOURCE
#include <stdio.h>
#include <fnmatch.h>

int main(int argc, char *argv[])
{
    int ret;
    ret = fnmatch("abc*", "abcdef", FNM_CASEFOLD);
    printf("return value is %d\n", ret);
    ret = fnmatch("abc?", "abcdef", FNM_CASEFOLD);
    printf("return value is %d\n", ret);

    return 0;
}