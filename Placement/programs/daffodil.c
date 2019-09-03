#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cube(int i) {
    return i*i*i;
}

void f(int start, int end)
{
    int i;
    for (i=start; i<=end; i++) {
        int ones = i % 10;
        int tens = (i/10) % 10;
        int hundreds = (i/100) % 10;
        if ((cube(ones) + cube(tens) + cube(hundreds)) == i) {
            printf("%d\n", i);
        }
    }
    
}

void g(int start, int end)
{
    int i = start;
    int ones = i % 10;
    int tens = (i / 10) % 10;
    int hundreds = (i / 100) % 10;
    if ((cube(ones) + cube(tens) + cube(hundreds)) == i)
    {
        printf("%d\n", i);
    }

    if (start == end)
    {
        return;
    }
    else
    {
        g(start + 1, end);
    }
}

int main(void)
{
    int start = 100, end = 999;
    g(start, end);
    return 0;
}