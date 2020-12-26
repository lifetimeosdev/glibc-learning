#include <obstack.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define obstack_chunk_alloc xmalloc
#define obstack_chunk_free free

void *xmalloc(size_t size);
void my_obstack_alloc_failed(void);
char *copystring(char *copystring);

static struct obstack myobstack;

int main(int argc, char *argv[])
{
    obstack_alloc_failed_handler = &my_obstack_alloc_failed;
    obstack_init(&myobstack);
    char *s = copystring("hello world");
    printf("copystring result is %s.\n", s);
    char *s2 = obstack_copy(&myobstack, s, strlen(s));
    printf("obstack_copy resutl is %s.\n", s2);
    obstack_free(&myobstack,NULL);
    return 0;
}

void *xmalloc(size_t size)
{
    void *value = malloc(size);
    if (value == 0)
        exit(1);
    return value;
}
void my_obstack_alloc_failed(void)
{
    fprintf(stderr, "obstack alloc failed.");
    exit(1);
}
char *copystring(char *string)
{
    size_t len = strlen(string);
    char *s = (char *)obstack_alloc(&myobstack, len);
    memcpy(s, string, len);
    return s;
}