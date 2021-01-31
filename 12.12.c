#include <stdio.h>

int main(int argc, char *argv[])
{
    int ret;
    FILE *fp;
    fp = fopen("test.txt","r");
    char a[1024];
    int count = fread(a,sizeof(char),sizeof(a),fp);
    printf("fread count is %d\n",count);
    ret = feof(fp);
    printf("feof return value is %d\n", ret);

    ret = ferror(fp);
    printf("ferror return value is %d\n",ret);

    clearerr(fp);

    return 0;
}