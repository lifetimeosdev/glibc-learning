#include <stdio.h>
#include <ctype.h>

static int y_or_n_p(const char *question);

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

    fp = freopen("test.txt", "r", fp);
    ret = fgetc(fp);
    if (ret == EOF)
    {
        printf("fgetc error");
        return 1;
    }
    else
        printf("fgetc result is %c\n", (char)ret);

    ret = fgetc_unlocked(fp);
    if (ret == EOF)
    {
        printf("fgetc_unlocked error");
        return 1;
    }
    else
        printf("fgetc_unlocked result is %c\n", (char)ret);

    ret = getc(fp);
    if (ret == EOF)
    {
        printf("getc error");
        return 1;
    }
    else
        printf("getc result is %c\n", (char)ret);

    ret = getc_unlocked(fp);
    if (ret == EOF)
    {
        printf("getc_unlocked error");
        return 1;
    }
    else
        printf("getc_unlocked result is %c\n", (char)ret);

    ret = getchar();
    if (ret == EOF)
    {
        printf("getchar error");
        return 1;
    }
    else
        printf("getchar result is %c\n", (char)ret);

    printf("your answer is %d\n", y_or_n_p("Delete?"));

    return 0;
}

int y_or_n_p(const char *question)
{
    fputs(question, stdout);
    while (1)
    {
        int c, answer;
        fputc(' ', stdout);
        c = tolower(fgetc(stdin));
        answer = c;
        while (c != '\n' && c != EOF)
            c = fgetc(stdin);
        if (answer == 'y')
            return 1;
        if (answer == 'n')
            return 0;
        fputs("Please answer y or n:", stdout);
    }
}