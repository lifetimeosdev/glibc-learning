#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *v;
    v = getenv("PATH");
    puts(v);

    putenv("AA=BB");
    v = getenv("AA");
    puts(v);

    setenv("CC", "DD", 1);
    v = getenv("CC");
    puts(v);
    unsetenv("CC");
    v = getenv("CC");
    if (v == NULL)
        puts("CC not set");

    clearenv();
    v = getenv("PATH");
    if (v == NULL)
        puts("PATH not set");

    return 0;
}