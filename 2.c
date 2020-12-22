#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct foo
{
    int no;
};

int main(int argc, char *argv[])
{
    struct foo *ptr;
    ptr = (struct foo *)malloc(sizeof(struct foo));
    if (ptr == NULL)
        abort();
    memset(ptr, 0, sizeof(struct foo));
    return 0;
}

char *
savestring(const char *ptr, size_t len)
{
    char *value = (char *)malloc(len + 1);
    value[len] = '\0';
    return (char *)memcpy(value, ptr, len);
}