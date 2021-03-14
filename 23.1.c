#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf main_loop;

void abort_to_main_loop(int status)
{
    longjmp(main_loop, status);
}

void do_command(void)
{
    char buffer[256];
    if (fgets(buffer, 128, stdin) == NULL)
        abort_to_main_loop(-1);
    else
        exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{
    while (1)
    {
        int ret;
        if ((ret = setjmp(main_loop)))
            printf("Back at main loop ... %d\n", ret);
        else
            do_command();
    }

    return 0;
}