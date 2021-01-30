#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

char *make_message(char *name, char *value);
int main(int argc, char *argv[])
{
    int ret;
    ret = printf("hello,%s\n", "a");
    printf("printf return value is %d\n", ret);

    FILE *fp;
    fp = fopen("test.txt", "w+");
    ret = fprintf(fp, "hello,%s\n", "s");
    printf("fprintf return value is %d\n", ret);

    char str[1024];
    ret = sprintf(str, "hello,%s\n", "a");
    printf("sprintf return value is %d\n", ret);
    printf("sprintf result is %s\n", str);

    char *buf = make_message("hello", "world");
    printf("buffer is %s\n", buf);
    free(buf);

    buf =NULL;
    ret = asprintf(&buf, "asprintf");
    printf("asprintf result is %s\n", buf);

    return 0;
}

char *make_message(char *name, char *value)
{
    int size = 100;
    char *buffer = (char *)malloc(size);
    int nchars;
    if (buffer == NULL)
        return NULL;

    nchars = snprintf(buffer, size, "value of %s is %s", name, value);
    if (nchars >= size)
    {
        size = nchars + 1;
        buffer = (char *)realloc(buffer, size);
        if (buffer != NULL)
            snprintf(buffer, size, "value of %s is %s", name, value);
    }
    return buffer;
}
