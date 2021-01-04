#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void sort_strings(char **array, int nstrings);
int compare_elements(const void *v1, const void *v2);

int main(int argc, char *argv[])
{
    char *a = "abcd";
    char *b = "abcdefg";
    printf("strcoll result is %d\n", strcoll(a, b));

    char *strings[] = {"abc", "ab", "abcd"};
    sort_strings(strings, 3);
    printf("sort result is %s\t%s\t%s\n", strings[0], strings[1], strings[2]);

    char c[1024];
    char *d = "abcdefg";
    strxfrm(c, d, sizeof(d) + 1);
    printf("strxfrm result is %s\n", c);

    return 0;
}

int compare_elements(const void *v1, const void *v2)
{
    char *const *p1 = v1;
    char *const *p2 = v2;
    return strcoll(*p1, *p2);
}

void sort_strings(char **array, int nstrings)
{
    qsort(array, nstrings, sizeof(char *), compare_elements);
}