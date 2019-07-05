#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void tata(long n, char str[], long k)
{
    if (k == n-1) {
        str[k] = '0';
        printf("%s\n", str);
        str[k] = '1';
        printf("%s\n", str);
        return;
    }

    str[k]='0';
    tata(n, str, k+1);
    str[k]='1';
    tata(n, str, k+1);
}

int main(void)
{
    char str[4];
    tata(3, str, 0);
}