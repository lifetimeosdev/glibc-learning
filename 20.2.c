#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int result = abs(-1);
    printf("abs result is %d\n", result);

    double d = fabs(-1.23456789);
    printf("fabs result is %f\n", d);

    float f = fabsf(-1.23456789);
    printf("fabsf result is %f\n", f);

    long double ld = fabsl(-1.23456789);
    printf("fabsl result is %Lf\n", ld);

    double c = ceil(1.1);
    printf("ceil result is %f\n", c);

    double fl = floor(1.1);
    printf("floor result is %f\n", fl);

    double t = trunc(1.1);
    printf("trunc result is %f\n", t);

    double r = rint(1.5);
    printf("rint result is %f\n", r);

    double ni = nearbyint(-1.5);
    printf("nearbyint result is %f\n", ni);

    double rd = round(1.5);
    printf("round result is %f\n", rd);

    int g = isgreater(1.111111111111112,
                      1.11111111111111);
    printf("isgreater result is %d\n", g);
    return 0;
}