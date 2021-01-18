#include <stdio.h>
#include <regex.h>

int main(int argc, char *argv[])
{
    regex_t compiled;
    int ret;
    ret = regcomp(&compiled, "a.*c", REG_ICASE | REG_EXTENDED);
    printf("regcomp return value is %d\n", ret);
    printf("compiled re_nsub is %ld\n", compiled.re_nsub);

    ret = regexec(&compiled, "1234", 0, NULL, 0);
    printf("regexec return value is %d\n", ret);
    char buf[1024];
    int len = regerror(ret, &compiled, buf, 1024);
    printf("error msg len is %d\t error is: %s\n", len, buf);

    regmatch_t match[1];
    ret = regexec(&compiled, "111abbbc111", 1, match, 0);
    printf("regexec return value is %d\n", ret);
    printf("regexec match begin offset is %d\n", match[0].rm_so);
    printf("regexec match end offset is %d\n", match[0].rm_eo);

    regfree(&compiled);

    return 0;
}