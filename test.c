#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

void copynwords(char src[], char dest[], int n) {
    dest[0] = '\0';
    char *p = strtok(src, " ");
    while (p!= NULL && n> 0) {
        strcat(dest, p);
        strcat(dest, " ");
        p = strtok(NULL, " ");
        n--;
    }
    dest[strlen(dest) - 1] = '\0';
}

int main(void)
{
    char src[] = "Be the change you wish to see in the world";
    char dest[256];

    copynwords(src, dest, 3);

    puts(dest);
}
