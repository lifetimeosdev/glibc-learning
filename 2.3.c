#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    void *brk = sbrk(0);
    printf("the brk is %p\n", brk);

    brk = sbrk(1);
    printf("the brk is %p\n", brk);
    return 0;
}