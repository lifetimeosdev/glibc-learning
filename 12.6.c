#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char a[] = "hello world\n";
    FILE *fp;
    fp = fopen("test.txt", "w");
    if (fp == NULL)
    {
        printf("fopen test.txt error.\n");
        return EXIT_FAILURE;
    }
    int write_count;
    write_count = fwrite(a, sizeof(char), sizeof(a), fp);
    if (write_count != sizeof(a))
    {
        printf("fwrite error\n");
        return EXIT_FAILURE;
    }
    write_count = fwrite_unlocked(a, sizeof(char), sizeof(a), fp);
    if (write_count != sizeof(a))
    {
        printf("fwrite_unlocked error\n");
        return EXIT_FAILURE;
    }

    char *b = (char *)malloc(sizeof(a) );
    int read_count;
    fp = freopen("test.txt", "r", fp);
    while ((read_count = fread(b, sizeof(char), sizeof(a), fp)) > 0)
    {
        b[read_count] = '\0';
        printf("fread result is %s\n", b);
    }

    read_count = fread_unlocked(b, sizeof(char), sizeof(a), fp);
    printf("%d",read_count);

    return 0;
}