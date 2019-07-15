#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int match (char str[], char pat[]) {
    int digitTotal = 0;

    for (int i = 0; i<strlen(pat) - 1; i += 2) {
        int sum = 0;
        for (int j = 0; j<strlen(str); j++) {
            if (str[j] == pat[i + 1]) {
                sum += 1;
            }
        }
        char digit[] = {pat[i], 0};
        int num = atoi(digit);
        digitTotal += num;
        if (sum != num) {
            return 0;
        }
    }

    if (digitTotal != strlen(str)) {
        return 0;
    }
    
    return 1;
}

int main(void)
{
    char str[] = "AEAEAEAK";
    char pat[] = "3E4A1K";

    int lock = match(str, pat);

    printf("%d", lock);

    return 0;
}
