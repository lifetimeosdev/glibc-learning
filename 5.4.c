#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <stddef.h>

int main(int argc, char *argv[])
{
    char *const str = "hello, world";
    char *a = memchr(str, 'e', strlen(str));
    printf("memchr result %p is %c\n", a, *a);
    char *b = memchr(str, 'u', strlen(str));
    printf("memchr result %p\n", b);

    char *c = rawmemchr(str, '\0');
    printf("rawmemchr result %p\t%c\n", c, *c);

    char *d = memrchr(str, 'e', strlen(str));
    printf("memrchr result is %p\t%c\n", d, *d);

    char *e = strchr(str, 'e');
    printf("strchr result is %c\n", *e);
    char *f = strchr(str, '\0');
    printf("strchr \\0 result is %p\n", f);

    char *g = strchrnul(str, 'u');
    printf("strchrnul result is %p\n", g);

    char *str_result = strstr(str, "el");
    printf("strstr result is %s\n", str_result);

    char *str_case_result = strcasestr(str, "El");
    printf("strcasestr result is %s\n", str_case_result);

    char *mem_result = memmem(str, strlen(str), "l", 1);
    printf("memmem result is %s\n", mem_result);

    size_t index = strspn(str, "abcdefh");
    printf("strspn result is %ld\n", index);

    size_t index2 = strcspn(str, ",.;");
    printf("strcspn result is %ld\n", index2);

    char *h = strpbrk(str, ",.;");
    printf("strpbrk result is %s\n", h);

    char *str1 = strdupa(str);
    char *i = strtok(str1, ",");
    printf("strtok result is %s\n", i);
    char *j = strtok(NULL, ",");
    printf("strtok result is %s\n", j);

    char *str2 = strdupa(str);
    char *token = strsep(&str2, ",");
    printf("strsep result is %s\n", token);
    token = strsep(&str2, ",");
    printf("strsep result is %s\n", token);

    printf("basename result is %s\n", basename("/tmp/a/a.gz"));

    return 0;
}