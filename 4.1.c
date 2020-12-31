#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    printf("isalpha? %d\n", isalpha('a'));
    printf("isalpha? %d\n", isalpha(EOF));
    printf("islower? %d\n", islower('A'));
    printf("isupper? %d\n", isupper('A'));
    printf("isdigit? %d\n", isdigit('1'));
    printf("isalnum? %d\n",isalnum('0'));
    printf("isxdigit? %d\n",isxdigit('f'));
    printf("ispunct? %d\n",ispunct(';'));
    printf("isspace? %d\n",isspace('\t'));
    printf("isblank? %d\n",isblank('\t'));
    printf("isgraph? %d\n",isgraph(' '));
    printf("isprint? %d\n",isprint(' '));
    printf("iscntrl? %d\n",iscntrl('\r'));
    printf("isascii? %d\n",isascii('\n'));

    printf("tolower %c\n", tolower('C'));
    printf("toascii %c\n",toascii(67));
    
    return 0;
}