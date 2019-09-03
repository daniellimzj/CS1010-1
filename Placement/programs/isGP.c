#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isGP(double a, double b, double c) {
    return (b/a) == (c/b) || (a/c) == (c/b) || (b/c) == (c/a) || (b/a) == (a/c) || (c/a) == (a/b) || (a/c) == (b/c);
}

int main(void)
{
    printf("%d ", isGP(2,6,18));
    printf("%d ", isGP(18,2,6));
    printf("%d ", isGP(2,18,6));
    printf("%d ", isGP(6,18,2));
    printf("%d ", isGP(6,2,18));
    printf("%d ", isGP(18,6,2));
    printf("%d ", isGP(18,5,2));
    printf("%d", isGP(54,6,2));

}