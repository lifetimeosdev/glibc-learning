#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    void * p = malloc(SIGSTKSZ);

    stack_t stack = {
        .ss_sp= p,
        .ss_size= SIGSTKSZ,
        .ss_flags= SS_ONSTACK
    };

   int ret = sigaltstack(&stack,NULL);
   if (ret == -1)
   {
       perror("sigaltstack error");
       return 1;       
   }
    return 0;
}