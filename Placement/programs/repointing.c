#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int a = 3, *b, c, *d, e, *f;
    b = &a;
    printf("a = %d, c = %d, e = %d\n", a, c, e);
    *b = 5;
    printf("a = %d, c = %d, e = %d\n", a, c, e);
    printf("*b = %d\n", *b);
    c = *b * 3;
    printf("a = %d, c = %d, e = %d\n", a, c, e);
    printf("*b = %d\n", *b);
    d = b;
    printf("a = %d, c = %d, e = %d\n", a, c, e);
    printf("*b = %d, *d = %d\n", *b, *d);
    e = *b + c;
    printf("a = %d, c = %d, e = %d\n", a, c, e);
    printf("*b = %d, *d = %d\n", *b, *d);
    *d = c + e;
    printf("a = %d, c = %d, e = %d\n", a, c, e);
    printf("*b = %d, *d = %d\n", *b, *d);
    f = &e;
    printf("a = %d, c = %d, e = %d\n", a, c, e);
    printf("*b = %d, *d = %d, *f = %d\n", *b, *d, *f);
    a = *f + *b;
    printf("a = %d, c = %d, e = %d\n", a, c, e);
    printf("*b = %d, *d = %d, *f = %d\n", *b, *d, *f);
    *f = *d - *b;
    printf("a = %d, c = %d, e = %d\n", a, c, e);
    printf("*b = %d, *d = %d, *f = %d\n", *b, *d, *f);
    return 0;
}