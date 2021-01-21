#include <stdio.h>
#include <wordexp.h>

void print_tilde_result(const char *words)
{
    wordexp_t result;
    int ret;
    ret = wordexp(words, &result, 0);
    if (ret != 0)
        printf("error. ${A}");
    else
        printf("%s\t%s\n", words, result.we_wordv[0]);
}

int main(int argc, char *argv[])
{
    print_tilde_result("${A}B");
    print_tilde_result("$A-B");
    print_tilde_result("$A_B");
    print_tilde_result("${C:-NO}-$C");
    print_tilde_result("${C:=NO}-$C");
    print_tilde_result("${C:?NO}-$C");
    print_tilde_result("${C:+NO}-$C");
    print_tilde_result("${#A}");
    print_tilde_result("${A%%b*}");
    print_tilde_result("${A%b*}");
    print_tilde_result("${A##*b}");
    print_tilde_result("${A#*b}");


    return 0;
}
