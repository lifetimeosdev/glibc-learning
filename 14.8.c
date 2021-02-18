#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *readlink_malloc(const char *filename)
{
    int size = 100;
    char *buffer = NULL;

    while (1)
    {
        buffer = (char *)malloc(size);
        int nchars = readlink(filename, buffer, size);
        if (nchars < 0)
        {
            free(buffer);
            return NULL;
        }
        if (nchars < size)
            return buffer;
        size *= 2;
    }
}

int main(int argc, char *argv[])
{
    int ret;

    ret = symlink("/tmp/a.txt", "/tmp/a.link");
    if (ret == -1)
    {
        perror("symlink error");
        return 1;
    }

    char *filename = readlink_malloc("/tmp/a.link");
    printf("filename = %s\n", filename);
    free(filename);
    
    filename = realpath("./a.out",NULL);
    if (filename == NULL)
    {
        perror("realpath error");
        return 1;
    }
    printf("realpath = %s\n",filename);
    free(filename);    

    return 0;
}