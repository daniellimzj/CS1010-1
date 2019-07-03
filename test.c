#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void tata(long a, long* b)
{
    *(b + 1) = a;
    b = &a;
}

int main(void)
{
    long x[2] = {-5, 10};
    long *p;

    p =x;
    tata(*p,x);

    printf("%ld %ld\n", x[0], x[1]);
}