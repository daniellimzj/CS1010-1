#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define AVERAGE(x,y) (0.5 * x) + (0.5 * y)

void tata(double **ptrer, double *z)
{
    *ptrer = z;
}

int main(void)
{
    double *ptr, x = 1, y = 2;
    ptr = &y;
    printf("%f, %p, %p, %p\n", *ptr, ptr, &y, &x);
    tata(&ptr, &x);
    printf("%f, %p, %p, %p\n", *ptr, ptr, &y, &x);
}