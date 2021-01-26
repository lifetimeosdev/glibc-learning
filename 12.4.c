#include <stdio.h>

int main(int argc, char *argv[])
{
    char *line = NULL;
    size_t n = 0;
    FILE *fp;
    int ret;
    fp = fopen("test.txt", "r");

    ret = getline(&line, &n, fp);
    if (ret == -1)
    {
        printf("getline error\n");
        return -1;
    }
    printf("getline result is %s, n is %ld\n", line, n);


    ret = getdelim(&line, &n, 'r', fp);
    if (ret == -1)
    {
        printf("getdelim error\n");
        return -1;
    }
    printf("getdelim result is %s, n is %ld\n", line, n);

    char linedata[4];
    char * ret_line ;
    ret_line = fgets(linedata, 4, stdin);
    if ( ret_line == NULL)
    {
        printf("fgets error.\n");
        return -1;
    }
    printf("fgets result is %s\n", ret_line);


    return 0;
}