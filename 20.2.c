#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{   
    int result = abs(-1);
    printf("abs result is %d\n",result);
    
    double d = fabs(-1.23456789);
    printf("fabs result is %f\n",d);

    float f = fabsf(-1.23456789);
    printf("fabsf result is %f\n",f);

    long double ld = fabsl(-1.23456789);
    printf("fabsl result is %Lf\n",ld);


    return 0;
}