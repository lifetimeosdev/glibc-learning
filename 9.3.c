#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int compare_int(const void *a, const void *b);
void print_arr(int *arr, int len);

int main(int argc, char *argv[])
{
    int arr[] = {1, 3, 0, 20, 10, 7, 9};
    int len = sizeof(arr) / sizeof(int);
    print_arr(arr, len);
    printf("\n");
    qsort(arr, len, sizeof(int), compare_int);
    print_arr(arr, len);
    printf("\n");

    return 0;
}

int compare_int(const void *a, const void *b)
{
    const int *ia = (const int *)a;
    const int *ib = (const int *)b;
    return (*ia > *ib) - (*ia < *ib);
}

void print_arr(int *arr, int len)
{
    for (int i = 0; i < len; i++)
        // printf("%d\t", *(arr + i));
        printf("%d\t", arr[i]);
}