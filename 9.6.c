#define _GNU_SOURCE
#include <stdio.h>
#include <search.h>
#include <stddef.h>

int cmp_int(const void *a, const void *b)
{
    const int *v1 = a;
    const int *v2 = b;
    return (*v1 > *v2) - (*v1 < *v2);
}
void free_node(void *nodep)
{
}
void action_node(const void *nodep, VISIT value, int level)
{
    printf("twalt %d \t %d \t %d\n", *(int *)nodep, value, level);
}

int data1 = 666;
int data2 = 999;

int main(int argc, char *argv[])
{
    void *troot = NULL;
    int *search;
    search = tsearch(&data1, &troot, cmp_int);
    printf("tsearch result is %d\t%d\n", data1, *search);
    printf("search : %p \t %p\n", &data1, search);
    search = tsearch(&data2, &troot, cmp_int);
    printf("tsearch result is %d\t%d\n", data2, *search);
    printf("search : %p \t %p\n", &data2, search);

    search = (int *)tfind(&data1, &troot, cmp_int);
    printf("tfind result is %d\t%d\n", data1, *search);
    printf("find : %p \t %p\n", &data1, search);

    void *delete = tdelete(&data1, &troot, cmp_int);
    printf("delete : %p \t %p\n", &data1, delete);

    // tdestroy(&troot, free_node);
    twalk(&troot, action_node);

    return 0;
}