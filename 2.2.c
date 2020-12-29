#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

int open1(char *str1, char *str2, int flags, int mode);
int open2(char *str1, char *str2, int flags, int mode);
int open3(char *str1, char *str2, int flags, int mode);

int main(int argc, char *argv[])
{
    int *a = (int *)alloca(sizeof(int));
    *a = 4;

    int r1 = open1("/home/work/", ".bash_history", O_RDONLY, 0644);
    printf("The open1 return value is %d \n", r1);
    int r2 = open2("/home/work/", ".bash_history", O_RDONLY, 0644);
    printf("The open2 return value is %d \n", r2);
    int r3 = open3("/home/work/", ".bash_history", O_RDONLY, 0644);
    printf("The open3 retur3 value is %d \n", r3);


    return 0;
}

int open1(char *str1, char *str2, int flags, int mode)
{
    char *name = (char *)alloca(strlen(str1) + strlen(str2) + 1);
    stpcpy(stpcpy(name, str1), str2);
    return open(name, flags, mode);
}

int open2(char *str1, char *str2, int flags, int mode)
{
    char *name = (char *)malloc(strlen(str1) + strlen(str2) + 1);
    int desc;
    if (name == NULL)
        return -1;
    stpcpy(stpcpy(name, str1), str2);
    desc = open(name, flags, mode);
    free(name);
    return desc;
}

int open3(char *str1, char *str2, int flags, int mode)
{
    char name[strlen(str1) + strlen(str2) + 1];
    stpcpy(stpcpy(name, str1), str2);
    return open(name, flags, mode);
}