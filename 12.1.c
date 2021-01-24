#include <stdio.h>
#include <stdio_ext.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen("test.txt", "r");
    printf("r result is %p\n", fp);
    fp = fopen("test.txt", "w");
    printf("w result is %p\n", fp);
    fp = fopen("test.txt", "a");
    printf("a result is %p\n", fp);

    fp = fopen("test.txt", "r+");
    printf("r+ result is %p\n", fp);
    fp = fopen("test.txt", "w+");
    printf("w+ result is %p\n", fp);
    fp = fopen("test.txt", "a+");
    printf("a+ result is %p\n", fp);

    fp = freopen("test.txt", "r", fp);
    printf("freopen r result is %p\n", fp);

    fp = stdin;
    printf("stdin is %p\n", fp);
    fp = freopen("test.txt", "r", fp);
    printf("freopen r result is %p\n", fp);

    printf("__freadable result is %d\n", __freadable(fp));
    printf("__fwritable result is %d\n", __fwritable(fp));

    printf("__freading result is %d\n", __freading(fp));
    printf("__fwriting result is %d\n", __fwriting(fp));

    return 0;
}