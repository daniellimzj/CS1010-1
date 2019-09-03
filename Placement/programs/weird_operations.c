#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

void g(int *a, int *b, int *c) {
    *b = *c/(*a)--;
}


int main(void)
{
    int a =1, b=2, c=3;

    g(&c, &a, &b);

    printf("%d %d %d", a,b,c);

    return 0;
}
