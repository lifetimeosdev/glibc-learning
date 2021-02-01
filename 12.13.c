#include <stdio.h>

int main(int argc, char *argv[])
{
    long pos;
    FILE *fp;
    fp = fopen("test.txt", "r");
    pos = ftell(fp);
    printf("current fp position is %ld\n", pos);
    char c = fgetc(fp);
    pos = ftell(fp);
    printf("current fp position is %ld\n", pos);

    off_t offset = ftello(fp);
    printf("current offset position is %ld\n", offset);

    int ret;
    ret = fseek(fp, 2, SEEK_CUR);
    pos = ftell(fp);
    printf("current offset position is %ld\n", pos);
    ret = fseek(fp, 2, SEEK_SET);
    pos = ftell(fp);
    printf("current offset position is %ld\n", pos);
    ret = fseek(fp, 2, SEEK_END);
    pos = ftell(fp);
    printf("current offset position is %ld\n", pos);

    ret = fseeko(fp, 3, SEEK_SET);
    pos = ftell(fp);
    printf("current offset position is %ld\n", pos);

    rewind(fp);
    pos = ftell(fp);
    printf("current offset position is %ld\n", pos);

    fpos_t fpos;
    fgetpos(fp, &fpos);
    fsetpos(fp,&fpos);

    return 0;
}