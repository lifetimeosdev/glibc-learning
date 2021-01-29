#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("|%10.8ld|\n", 666L);
    printf("|%-10.8ld|\n", 666L);
    printf("|%*.8ld|\n", 10, 666L);
    printf("|%10.*ld|\n", 8, 666L);
    printf("|%*.*ld|\n", 10, 8, 666L);
    printf("|%10.8f|\n", 6.666);
    printf("|%10.2a|\n", 123.456);
    printf("|%10.2f|\n", 123.456);
    printf("|%10.2e|\n", 123.456);
    printf("|%10.2g|\n", 123.456);
    printf("|%c|\n", 'a');
    printf("|%3s%-6s|\n", "no", "where");
    int a = 6;
    printf("|%p|\n", &a);
    int nchar;
    printf("nchar is %d\n",nchar);
    printf("hello%s.%n","a",&nchar);
    printf("nchar is %d\n",nchar);


    return 0;
}