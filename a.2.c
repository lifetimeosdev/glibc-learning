#include <stdio.h>
#include <stdarg.h>

int add_em_up(int count, ...)
{
    va_list ap;
    int i, sum;

    va_start(ap, count);
    sum = 0;
    for (i = 0; i < count; i++)
        sum += va_arg(ap, int);
    va_end(ap);
    return sum;
}

int main(int argc, char *argv[])
{
    printf("%d\n", add_em_up(3, 5, 5, 6));
    printf("%d\n", add_em_up(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
    return 0;
}