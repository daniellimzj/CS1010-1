#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int sum_integers(char str[])
{
    int i = 0;
    int total = 0;

    while (i<strlen(str)) {
        char num[strlen(str)-i];
        int j = 0;
        while (isdigit(str[i])) {
            num[j] = str[i];
            j++;
            i++;       
        }
        total += atoi(num);
        i++;
    }

    return total;
}

int main(void)
{
    char num[100];

    scanf("%s", num);

    printf("%d", sum_integers(num));
}
