#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    char *a = "abcd";
    char *b = "abcdefg";
    printf("memcmp result is %d\n", memcmp(a, b, 8));
    printf("strcmp result is %d\n", strcmp(a, b));
    char *c = "ABcdefg";
    printf("strcasecmp result is %d\n", strcasecmp(b, c));
    printf("strncmp result is %d\n", strncmp(a, b, 2));
    printf("strncasecmp result is %d\n", strncasecmp(b, c, 2));

    return 0;
}