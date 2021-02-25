#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    div_t result = div(10, 2);
    printf("%d %d\n", result.quot, result.rem);

    ldiv_t lresult = ldiv(10, 2);
    printf("%ld %ld\n", lresult.quot, lresult.rem);

    lldiv_t llresult = lldiv(10, 2);
    printf("%lld %lld\n", llresult.quot, llresult.rem);

    double a = 1.0 / 3;
    int c = fpclassify(0.0000);
    switch (c)
    {
    case FP_NAN:
        printf("NaN");
        break;
    case FP_INFINITE:
        printf("infinity");
        break;
    case FP_ZERO:
        printf("zero");
        break;
    case FP_SUBNORMAL:
        printf("subnormal");
        break;
    case FP_NORMAL:
        printf("normal");
        break;
    default:
        break;
    }

    printf("\nisfinite %d\n", isfinite(INFINITY));

    printf("cast float %d\n", (int)111.2);
    printf("cast float %d\n", (int)111.5);
    return 0;
}