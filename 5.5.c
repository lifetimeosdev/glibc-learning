#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    char a[] = "abc";
    explicit_bzero(a, 4);
    printf("%s\n", a);

    char b[] = "abcdefg";
    strfry(b);
    printf("%s\n", b);

    char c[] = "abcdefg";
    void *d = memfrob(c, strlen(c));
    printf("%s\n", c);

    char *e = memfrob(d, strlen(c));
    printf("%s\n", e);

    return 0;
}