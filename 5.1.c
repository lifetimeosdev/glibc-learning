#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *a = "hello, world";
    printf("len is %ld\n", strlen(a));
    char b[35] = "hello, world";
    printf("len is %ld\n", strlen(b));
    char *c = b;
    printf("len is %ld\n", strlen(c));

    printf("strnlen is %ld\n", strnlen(a, 5));

    char d[1024];
    char *e = memcpy(d, a, strlen(a) + 1);
    printf("memcpy result is %s\t%s\n", e, d);

    // char f[] = "hello, ";
    // char g[] = "world";
    // char *h = (char *)malloc(sizeof(f) + sizeof(g));
    // mempcpy(mempcpy(h, f, sizeof(f)), g, sizeof(g));
    // printf("mempcpy result is %s\n", h);

    char i[] = "hello";
    char *j = i;
    j++;
    printf("%s\n", j);
    char *k = memmove(i, j, 4);
    printf("memmove result is %s\n", k);

    char *l = "hello, world";
    char m[1024];
    char *n = memccpy(m, l, 'l', 32);
    printf("%s\t%s\n", m, n);

    char o[] = "hello, world";
    char *p = memset(o, 'a', strlen(o));
    printf("memset result is %s\t%s\n", o, p);

    char *q = "hello, world";
    char *r = strdup(q);
    printf("strdup result is %s\n", r);

    char s[100]="hello, ";
    strcat(s,"world");
    printf("strcat result is %s\n", s);

    return 0;
}