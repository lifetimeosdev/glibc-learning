#include <stdio.h>
#include <threads.h>
#include <stdlib.h>

int thread_do(void *arg)
{
    printf("%s\n", arg);
    printf("%ld\n", thrd_current());
    struct timespec time =
        {.tv_sec = 5,
         .tv_nsec = 10};
    int ret = thrd_sleep(&time, NULL);
    printf("thrd_sleep ret is %d\n", ret);
    return 0;
}

int main(int argc, char *argv[])
{
    thrd_t thr;

    int ret = thrd_create(&thr, thread_do, (void *)"hello thread");
    printf("thrd_create ret is %d\n", ret);
    printf("thread identifies is %ld\n", thr);
    //ret = thrd_detach(thr);
    //printf("thrd_detach ret is %d\n", ret);

    thrd_yield();
    struct timespec time =
        {.tv_sec = 1,
         .tv_nsec = 10};
    ret = thrd_sleep(&time, NULL);
    printf("thrd_sleep ret is %d\n", ret);

    int *res;
    thrd_join(thr, res);

    return 0;
}