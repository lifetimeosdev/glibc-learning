#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    execl("/bin/ls","ls","-alh",NULL);


    return 0;
}