#include <stdio.h>
#include <time.h>

#define SIZE 256

int main(int argc, char *argv[])
{
    char buffer[SIZE];
    time_t curtime;
    struct tm *loctime;

    curtime = time(NULL);
    loctime = localtime(&curtime);

    fputs(asctime(loctime), stdout);

    strftime(buffer,SIZE, "Today is %A, %B %d.\n", loctime);
    fputs(buffer, stdout);
    strftime(buffer, SIZE, "The time is %I:%M %p.\n", loctime);
    fputs(buffer, stdout);

    return 0;
}