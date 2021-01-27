#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen("test.txt", "r");
    int ret;
    ret = fgetc(fp);
    if (ret != EOF)
        printf("fgetc result is %c\n", ret);
    ret = fgetc(fp);
    if (ret != EOF)
        printf("fgetc result is %c\n", ret);

    ret = ungetc('1', fp);
    if (ret != EOF)
        printf("ungetc result is %c\n", ret);
    ret = ungetc('2', fp);
    if (ret != EOF)
        printf("ungetc result is %c\n", ret);

    ret = fgetc(fp);
    if (ret != EOF)
        printf("fgetc result is %c\n", ret);
    ret = fgetc(fp);
    if (ret != EOF)
        printf("fgetc result is %c\n", ret);
    ret = fgetc(fp);
    if (ret != EOF)
        printf("fgetc result is %c\n", ret);

    return 0;
}