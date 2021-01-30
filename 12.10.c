#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <printf.h>

int validata_args(char *format, int nargs)
{
    int *argtypes;
    int nwanted;
    argtypes = (int *)alloca(strlen(format) / 2 * sizeof(int));
    nwanted = parse_printf_format(format, nargs, argtypes);
    if (nwanted > nargs)
    {
        fprintf(stderr, "too few arguments (at least %d required)", nwanted);
        return 0;
    }
    for (int i = 0; i < nwanted; i++)
    {
        char *wanted;
        if (argtypes[i] & PA_FLAG_PTR)
            wanted = "structure";
        else
        {
            switch (argtypes[i] & ~PA_FLAG_MASK)
            {
            case PA_INT:
            case PA_FLOAT:
            case PA_DOUBLE:
                wanted = "number";
                break;
            case PA_CHAR:
                wanted = "char";
                break;
            case PA_STRING:
                wanted = "string";
                break;
            case PA_POINTER:
                wanted = "structure";
                break;
            }
        }
        printf("type is %s\n", wanted);
    }
    return 1;
}

int main(int argc, char *argv[])
{
    int ret = validata_args("%s%d", 2);
    printf("return value is %d\n", ret);
    return 0;
}