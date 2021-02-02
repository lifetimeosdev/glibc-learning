#include <stdio.h>
#include <stdio_ext.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen("test.txt","w");
    int ret;
    ret = fflush(fp);
    printf("fflush return value is %d\n",ret);
    ret = fclose(fp);

    fflush_unlocked(NULL);

    _flushlbf();
    __fpurge(fp);

    return 0;
}