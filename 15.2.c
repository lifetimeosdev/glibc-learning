#include <stdio.h>
#include <stdlib.h>

void write_data(FILE *stream)
{
    int i;
    for (size_t i = 0; i < 100; i++)
    {
        fprintf(stream, "%ld\n", i);
    }
    if (ferror(stream))
    {
        fprintf(stderr, "Output to stream failed.\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[])
{
    FILE *output;
    output = popen("more", "w");
    if (!output)
    {
        fprintf(stderr, "incorrect parameters or too many files.\n");
        exit(EXIT_FAILURE);
    }
    write_data(output);
    if(pclose(output) !=0){
        fprintf(stderr, "Could not run more or other error.\n");
    }

    return 0;
}