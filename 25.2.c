#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

static int verbose_flag;

int main(int argc, char *argv[])
{
    int c;

    while (1)
    {
        static struct option long_options[] =
            {
                {"verbose", no_argument, &verbose_flag, 1},
                {"brief", no_argument, &verbose_flag, 0},
                {"add", no_argument, NULL, 'a'},
                {"append", no_argument, NULL, 'b'},
                {"delete", required_argument, NULL, 'd'},
                {"create", required_argument, NULL, 'c'},
                {"file", required_argument, NULL, 'f'},
                {0, 0, 0, 0}};

        int option_index = 0;
        c = getopt_long(argc, argv, "abc:d:f:", long_options, &option_index);
        if (c == -1)
            break;
        switch (c)
        {
        case 0:
            puts("getopt_long return 0");
            if (long_options[option_index].flag != 0)
                break;
            printf("option %s", long_options[option_index].name);
            if (optarg)
                printf(" with arg %s", optarg);
            printf("\n");
            break;
        case 'a':
            puts("option -a\n");
            break;
        case 'b':
            puts("option -b\n");
            break;
        case 'c':
            printf("option -c with value %s\n", optarg);
            break;
        case 'd':
            printf("option -d with value %s\n", optarg);
            break;
        case 'f':
            printf("option -f with value %s\n", optarg);
            break;
        case '?':
            break;
        default:
            abort();
        }
    }

    if (verbose_flag)
        puts("verbose flag is set");
    if (optind < argc)
    {
        printf("non-option ARGV-elements:");
        while (optind < argc)
            printf("%s", argv[optind++]);
        putchar('\n');
    }

    return 0;
}