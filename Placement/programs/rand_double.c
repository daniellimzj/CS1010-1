#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    double ans = (double) rand()/RAND_MAX * 8 - 4;

    printf("%.10f", ans);
    return 0;
}
