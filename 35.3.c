#include <stdio.h>
#include <threads.h>
#include <stdlib.h>

static mtx_t mutex;
static __sig_atomic_t counter = 0;

int thread_do(void *arg)
{
    mtx_lock(&mutex);
    printf("thread %ld\n", thrd_current());
    counter++;
    mtx_unlock(&mutex);
    return 0;
}

int main(int argc, char *argv[])
{
    thrd_t thr[16];

    mtx_init(&mutex, mtx_plain);

    for (int i = 0; i < 16; i++)
        thrd_create(&thr[i], thread_do, NULL);

    struct timespec time = {.tv_sec = 1, .tv_nsec = 0};
    while (counter < 16)
        thrd_sleep(&time, NULL);

    mtx_destroy(&mutex);

    return 0;
}