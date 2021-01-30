#include <stdio.h>
#include <stdarg.h>

int myfprintf(FILE *strem, char *template, ...);
int myprintf(char *template, ...);

int main(int argc, char *argv[])
{
    myprintf("vprintf result is %s-%s\n", "hello", "world");
    myfprintf(stdout, "vfprintf result is %s-%s\n", "hello", "world");
    return 0;
}

int myprintf(char *template, ...)
{
    va_list ap;
    va_start(ap, template);
    int ret = vprintf(template, ap);
    va_end(ap);
    return ret;
}

int myfprintf(FILE *strem, char *template, ...)
{
    va_list ap;
    va_start(ap, template);
    int ret = vfprintf(strem, template, ap);
    va_end(ap);
    return ret;
}