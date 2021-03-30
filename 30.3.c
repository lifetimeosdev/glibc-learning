#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *login = getlogin();
    printf("current login is %s\n",login);

    return 0;
}