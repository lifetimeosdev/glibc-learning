#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <stdlib.h>

void do_at_exit(void)
{
    printf("at_exit...\n");
    sync();
}

int main(int argc, char *argv[])
{
    int rc;
    rc = syscall(SYS_chdir, "/tmp");
    printf("syscall return value is %d\n", rc);

    atexit(do_at_exit);

    //exit(EXIT_SUCCESS);
    _exit(23);
    return 0;
}