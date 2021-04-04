#include <stdio.h>
#include <threads.h>
#include <stdlib.h>

static once_flag flag = ONCE_FLAG_INIT;

void once_do(void)
{
    printf("%s\n", "once");
}

int thread_do(void *arg)
{
    call_once(&flag, once_do);
    return 0;
}

int main(int argc, char *argv[])
{
    thrd_t thr[16];

    for (int i = 1; i < 16; i++)
    {
        thrd_create(&thr[i], thread_do, NULL);
    }
    getc(stdin);

    return 0;
}