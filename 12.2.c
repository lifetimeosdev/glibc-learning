#include <stdio.h>
#include <stdio_ext.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen("test.txt", "r");
    int err = fclose(fp);
    printf("fclose return value is %d\n", err);
    fp = fopen("test.txt", "r");

    flockfile(fp);
    err = ftrylockfile(fp);
    printf("ftrylockfile return value is %d\n", err);
    funlockfile(fp);

    __fsetlocking(fp, FSETLOCKING_BYCALLER);
    int locking = __fsetlocking(fp, FSETLOCKING_QUERY);
    printf("fp locking status is %d\n",locking);

    return 0;
}