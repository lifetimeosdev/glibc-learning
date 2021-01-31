#include <stdio.h>

int main(int argc, char *argv[])
{
    int ret;
    int a;
    double b;
    ret = scanf("%d\t%lf", &a, &b);
    if (ret != 2)
    {
        fprintf(stderr, "scanf error \n");
        return -1;
    }
    printf("scanf result is %d\t%f\n", a, b);

    char str[1024];
    ret = scanf("%2s123", str);
    if (ret != 1)
    {
        fprintf(stderr, "scanf error \n");
        return -1;
    }
    printf("scanf result is %s\n", str);
    ret = scanf("\n%3c", str);
    if (ret != 1)
    {
        fprintf(stderr, "scanf error \n");
        return -1;
    }
    str[3] = '\0';
    printf("scanf result is %s\n", str);

    ret = scanf("%3[1234567890]", str);
    printf("%%s[ result is %s\n", str);

    // char *variable, *value;
    // scanf("%a[a-zA-Z0-9] = %a[^\n]\n", &variable, &value);
    // printf("%s = %s\n", variable, value);

    return 0;
}