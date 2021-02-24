#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    div_t result = div(10, 2);
    printf("%d %d\n", result.quot, result.rem);

    ldiv_t lresult = ldiv(10, 2);
    printf("%ld %ld\n", lresult.quot, lresult.rem);

    lldiv_t llresult = lldiv(10, 2);
    printf("%lld %lld\n", llresult.quot, llresult.rem);


    return 0;
}