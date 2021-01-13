#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int compare_int(const void *a, const void *b);

int main(int argc, char *argv[])
{
    int arr[] = {1, 3, 5, 7, 9};
    size_t len = 5;
    int a = 5;
    int b = 6;
    int *find = bsearch(&a, arr, len, sizeof(int), compare_int);
    if (find == NULL)
        printf("not found\n");
    else
    {
        printf("lfind return is %d\n", *find);
        printf("nmemb is %ld\n", len);
    }

    return 0;
}

int compare_int(const void *a, const void *b)
{
    const int *ia = (const int *)a;
    const int *ib = (const int *)b;
    return (*ia > *ib) - (*ia < *ib);
}