#include <stdio.h>
#include <stdio_ext.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen("test.txt", "r");
    int ret;
    ret = setvbuf(fp, NULL, _IOLBF, BUFSIZ);
    printf("setvbuf return value is %d\n", ret);

    ret = __flbf(fp);
    printf("__flbf return value is %d\n", ret);
    size_t size = __fbufsize(fp);
    printf("__fbufsize return value is %ld\n", size);

    ret = fclose(fp);
    printf("fclose return value is %d\n", ret);

    return 0;
}