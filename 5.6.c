#include <stdio.h>
#include <argz.h>
#include <stdlib.h>
#include <stddef.h>

int main(int argc, char *argv[])
{
    char *argvv[] = {"abc", "def", NULL};
    char *argz = NULL;
    size_t argz_len = 0;
    error_t err = argz_create(argvv, &argz, &argz_len);
    printf("argz is %s\n", argz);
    printf("argz is %s\n", argz + 4);
    printf("argz len is %ld\n", argz_len);
    printf("err is %d\n", err);

    err = argz_create_sep("666666,999999", ',', &argz, &argz_len);
    printf("argz is %s\n", argz);
    printf("argz is %s\n", argz + 7);
    printf("argz len is %ld\n", argz_len);
    printf("err is %d\n", err);

    printf("argz_count result is %ld\n", argz_count(argz, argz_len));

    argz_extract(argz, argz_len, argvv);
    printf("argz_extract result 0 is %s\n", argvv[0]);
    printf("argz_extract result 1 is %s\n", argvv[1]);
    printf("argz_extract result 2 is %s\n", argvv[2]);

    err = argz_add(&argz, &argz_len, "123456");
    printf("argz is %s\n", argz);
    printf("argz is %s\n", argz + 7);
    printf("argz len is %ld\n", argz_len);
    printf("err is %d\n", err);

    err = argz_add_sep(&argz, &argz_len, "123:456", ':');
    printf("argz is %s\n", argz);
    printf("argz len is %ld\n", argz_len);
    printf("err is %d\n", err);

    err = argz_append(&argz, &argz_len, "0000", 4);
    argz_delete(&argz, &argz_len, argz);
    err = argz_insert(&argz, &argz_len, argz + 7, "hahha");

    char *entry;
    for (entry = argz; entry; entry = argz_next(argz, argz_len, entry))
    {
        printf("entry is %s\n", entry);
    }

    int replace_count;
    err = argz_replace(&argz, &argz_len, "12", "787878", &replace_count);

    argz_stringify(argz, argz_len, '|');
    printf("argz_stringify result is %s\n", argz);

    return 0;
}