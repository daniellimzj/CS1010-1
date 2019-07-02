#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define AVERAGE(x,y) (0.5 * x) + (0.5 * y)

int main(void)
{
    long x = 10;
    long y = 10;

    double ave = 2*AVERAGE(x,y);

    printf("%f", ave);
}
