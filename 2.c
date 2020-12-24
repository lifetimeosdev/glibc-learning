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
    printf("%d\n",status);

    free(ptr);
    status = mprobe(ptr);
    printf("%d\n",status);

    struct mallinfo minfo = mallinfo();
    printf("total size of memory alloced is %d bytes\n", minfo.arena);
    printf("%d trunks are not in use.\n", minfo.ordblks);
    printf("%d trunks of memory are alloced by mmap.\n", minfo.hblks);
    printf("%d bytes of memory are alloced by mmap.\n", minfo.hblkhd);
    printf("total size of memory occupied by chunks are %d .\n", minfo.uordblks);
    printf("This is the total size of memory occupied by free (not in use) chunks. %d.\n", minfo.fordblks);
    printf("This is the size of the top-most releasable chunk that normally borders the end of the heap %d.\n", minfo.keepcost);

    return 0;
}

char *
savestring(const char *ptr, size_t len)
{
    char *value = (char *)malloc(len + 1);
    value[len] = '\0';
    return (char *)memcpy(value, ptr, len);
}
