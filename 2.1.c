#include <obstack.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define obstack_chunk_alloc xmalloc
#define obstack_chunk_free free

void *xmalloc(size_t size);
void my_obstack_alloc_failed(void);
char *copystring(char *);
void add_string(struct obstack *, const char *, int);

static struct obstack myobstack;

int main(int argc, char *argv[])
{
    obstack_alloc_failed_handler = &my_obstack_alloc_failed;
    obstack_init(&myobstack);
    char *s = copystring("hello world");
    printf("copystring result is %s.\n", s);
    char *s2 = obstack_copy(&myobstack, s, strlen(s));
    printf("obstack_copy resutl is %s.\n", s2);
    obstack_free(&myobstack, NULL);
    int room = obstack_room(&myobstack);
    printf("myobstack room is %d bytes.\n", room);
    obstack_1grow_fast(&myobstack, 'a');
    obstack_ptr_grow_fast(&myobstack, s);
    obstack_int_grow_fast(&myobstack, 27);
    obstack_blank_fast(&myobstack, sizeof(long));
    add_string(&myobstack, s, strlen(s));
    void *base = obstack_base(&myobstack);
    void *next_free = obstack_next_free(&myobstack);
    int size = obstack_object_size(&myobstack);
    printf("size is %d ---- %ld\n", size, next_free - base);

    int mask = obstack_alignment_mask(&myobstack);
    printf("mask is %d\n", mask);
    obstack_alignment_mask(&myobstack) = 0;
    obstack_finish(&myobstack);
    mask = obstack_alignment_mask(&myobstack);
    printf("mask is %d\n", mask);
    
    int chunk_size = obstack_chunk_size(&myobstack);
    printf("chunk size is %d\n", chunk_size);
    obstack_chunk_size(&myobstack) = 666;
    chunk_size = obstack_chunk_size(&myobstack);
    printf("chunk size is %d\n", chunk_size);

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

void add_string(struct obstack *obstack, const char *ptr, int len)
{
    while (len > 0)
    {
        int room = obstack_room(obstack);
        if (room == 0)
        {
            obstack_1grow(obstack, *ptr++);
            len--;
        }
        else
        {
            if (room > len)
                room = len;
            len -= room;
            while (room-- > 0)
                obstack_1grow_fast(obstack, *ptr++);
        }
    }
}