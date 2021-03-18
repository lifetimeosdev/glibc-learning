#include <stdio.h>
#include <signal.h>
#include <setjmp.h>

jmp_buf return_to_top_level;
volatile sig_atomic_t waiting_for_input;

void handle_sigint(int signum)
{
    waiting_for_input = 0;
    longjmp(return_to_top_level, 1);
}

int main(int argc, char *argv[])
{
    signal(SIGINT, handle_sigint);
    while (1)
    {
        if(setjmp(return_to_top_level) == 0)
            printf("do..\n");
    }
    
    return 0;
}