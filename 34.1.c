#include <stdio.h>
#include <stdlib.h>
#include <execinfo.h>

void print_trace(void)
{
    void *array[10];
    char **strings;
    int size, i;

    size = backtrace(array, 10);
    strings = backtrace_symbols(array, size);
    if (strings)
    {
        printf("obtained %d stack frames.\n", size);
        for (i = 0; i < size; i++)
            printf("%s\n", strings[i]);
    }
    free(strings);
}

void dumy_function(void)
{
    print_trace();
}

int main(int argc, char *argv[])
{
    dumy_function();
    return 0;
}