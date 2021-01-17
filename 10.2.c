#include <stdio.h>
#include <glob.h>
#include <stddef.h>

int main(int argc, char *argv[])
{
    glob_t result;
    int ret;
    ret = glob("~/*", GLOB_TILDE | GLOB_ONLYDIR, NULL, &result);
    printf("glob ret is %d\n", ret);
    for (size_t i = 0; i < result.gl_pathc; i++)
    {
        printf("%s\n", *result.gl_pathv++);
    }

    return 0;
}