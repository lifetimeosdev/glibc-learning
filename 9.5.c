#define _GNU_SOURCE
#include <stdio.h>
#include <search.h>

int main(int argc, char *argv[])
{
    int ret = hcreate(1024);
    printf("hcreate return value is %d\n", ret);
    struct entry entry;
    entry.key = "hello";
    entry.data = "world";
    struct entry *insert = hsearch(entry, ENTER);
    printf("return value is %s\t%s\n", insert->key, (char *)insert->data);

    struct entry *find = hsearch(entry, FIND);
    printf("return value is %s\t%s\n", find->key, (char *)find->data);

    hdestroy();

    struct hsearch_data htab;
    int ret_r = hcreate_r(1024, &htab);
    printf("hcreate_r return value is %d\n", ret_r);

    struct entry *retval;
    ret_r = hsearch_r(entry, ENTER, &retval, &htab);
    printf("hcreate_r return value is %d\n", ret_r);
    ret_r = hsearch_r(entry, FIND, &retval, &htab);
    printf("hcreate_r return value is %d\n", ret_r);

    hdestroy_r(&htab);

    return 0;
}