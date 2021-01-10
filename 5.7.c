#include <stdio.h>
#include <stddef.h>
#include <envz.h>
#include <argz.h>

int main(int argc, char *argv[])
{
    char *argvv[] = {"abc=abc11", "defg", NULL};
    char *argz;
    size_t argz_len;
    argz_create(argvv, &argz, &argz_len);

    char *entry = envz_entry(argz, argz_len, "abc");
    printf("envz_entry result is %s\n", entry);
    char *value = envz_get(argz, argz_len, "abc");
    printf("envz_get result is %s\n", value);
    value = envz_get(argz, argz_len, "defg");
    printf("envz_get result is %s\n", value);

    error_t err = envz_add(&argz, &argz_len, "hello", "world");

    err = envz_merge(&argz, &argz_len, argz, argz_len, 0);
    printf("envz_merge return value error=%d\n", err);

    envz_strip(&argz, &argz_len);
    envz_remove(&argz, &argz_len, "abc");

    argz_stringify(argz, argz_len, '|');
    printf("argz_stringify result is %s\n", argz);

    return 0;
}