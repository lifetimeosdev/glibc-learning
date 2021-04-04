#include <stdio.h>
#include <threads.h>
#include <stdlib.h>
#include <errno.h>

static tss_t tss_key;
static int counter = 0;

int thread_do(void *arg)
{
    counter++;
    tss_set(tss_key, (void *)&counter);
    void *v = tss_get(tss_key);
    printf("%d tss_get vaue is %d\n", tss_key, *(int *)v);
    // tss_delete(tss_key);
    return 0;
}

void dtor(void *arg)
{
    printf("dtor called %ld\n", thrd_current());
}

int main(int argc, char *argv[])
{
    thrd_t thr[16];

    tss_create(&tss_key, dtor);

    for (int i = 0; i < 16; i++)
        thrd_create(&thr[i], thread_do, NULL);

    struct timespec time = {.tv_sec = 1, .tv_nsec = 0};
    while (counter < 16)
        thrd_sleep(&time, NULL);

    return 0;
}