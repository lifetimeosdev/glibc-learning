#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <mcheck.h>

struct foo
{
    int no;
};

int main(int argc, char *argv[])
{
    //mcheck(NULL);

    struct foo *ptr;
    ptr = (struct foo *)malloc(sizeof(struct foo));
    if (ptr == NULL)
        abort();
    memset(ptr, 0, sizeof(struct foo));

    ptr = (struct foo *)realloc(ptr, 2 * sizeof(struct foo));
    ptr = (struct foo *)reallocarray(ptr, 2, sizeof(struct foo));
    ptr = (struct foo *)calloc(4, sizeof(struct foo));

    ptr = (struct foo *)aligned_alloc(8, sizeof(struct foo));
    posix_memalign((void *)&ptr , 8, sizeof(struct foo));
    enum mcheck_status status = mprobe(ptr);
    printf("%d",status);

    free(ptr);
    status = mprobe(ptr);
    printf("%d",status);
    return 0;
}

char *
savestring(const char *ptr, size_t len)
{
    char *value = (char *)malloc(len + 1);
    value[len] = '\0';
    return (char *)memcpy(value, ptr, len);
}
