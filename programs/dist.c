#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 100

int Dist(char *str1, char *str2) {
    if (strlen(str1) == 0 || strlen(str2) == 0) {
        if (strlen(str1) > strlen(str2)) {
            return strlen(str1);
        }
        else return strlen(str2);
    }
    else {
        char *str1prime = str1;
        *str1prime++;

        char *str2prime = str2;
        *str2prime++;

        if (str1[0] == str2[0]) {
            return Dist(str1prime, str2prime);
        }
        else {
            if (1 + Dist(str1prime, str2) < 1 + Dist(str1, str2prime)) {
                return 1 + Dist(str1prime, str2);
            }
            else return 1 + Dist(str1, str2prime);
        }
    }
}

int main(void) {
    char str1[MAX_STRING_LEN];
    char str2[MAX_STRING_LEN];

    scanf("%s %s", str1, str2);

    printf("%d", Dist(str1, str2));
}