#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

volatile sig_atomic_t usr_interrupt = 0;

void synch_signal(int sig)
{
    usr_interrupt = 1;
}
void child_function(void){
    printf("I'm here!!! My pid is %d.\n",(int)getpid());
    kill(getppid(),SIGUSR1);
    puts("Bye, now ...");
    exit(0);
}

int main(int argc, char *argv[])
{
    struct sigaction usr_action;
    sigset_t block_mask;
    pid_t child_id;

    sigfillset(&block_mask);
    usr_action.sa_handler = synch_signal;
    usr_action.sa_mask = block_mask;
    usr_action.sa_flags = 0;
    sigaction(SIGUSR1, &usr_action, NULL);

    child_id = fork();
    if(child_id == 0)
        child_function();
    while(!usr_interrupt)
        ;
    puts("That's all, floks!");
    return 0;
}