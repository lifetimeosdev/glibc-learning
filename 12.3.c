#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen("test.txt", "w");
    int chr = '9';
    int ret;
    ret = fputc(chr, fp);
    if (ret != chr)
    {
        printf("fputc error");
        return 1;
    }
    ret = fputc_unlocked(chr, fp);
    if (ret != chr)
    {
        printf("fputc_unlocked error");
        return 1;
    }
    ret = putc(chr, fp);
    if (ret != chr)
    {
        printf("putc error");
        return 1;
    }
    ret = putc_unlocked(chr, fp);
    if (ret != chr)
    {
        printf("putc_unlocked error");
        return 1;
    }
    ret = putchar(chr);
    if (ret != chr)
    {
        printf("putchar error");
        return 1;
    }
    ret = putchar_unlocked(chr);
    if (ret != chr)
    {
        printf("putc_unlocked error");
        return 1;
    }
    ret = fputs("\nhello world", fp);
    if (ret == EOF)
    {
        printf("puts error");
        return 1;
    }

    ret = puts("hello world");
    if (ret == EOF)
    {
        printf("puts error");
        return 1;
    }

    return 0;
}