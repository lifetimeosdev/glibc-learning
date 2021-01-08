#include <stdio.h>
#include <argz.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *argvv[] = {"abc", "def", NULL};
    char *argz = NULL;
    size_t argz_len = 0;
    error_t err = argz_create(argvv, &argz, &argz_len);
    printf("argz is %s\n", argz);
    printf("argz len is %ld\n", argz_len);
    return 0;
}