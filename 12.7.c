#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("|%10.8ld|\n", 666L);
    printf("|%-10.8ld|\n", 666L);
    printf("|%*.8ld|\n", 10, 666L);
    printf("|%10.*ld|\n", 8, 666L);
    printf("|%*.*ld|\n", 10, 8, 666L);
    printf("|%10.8f|\n", 6.666);

    return 0;
}