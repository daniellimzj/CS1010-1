#include <stdio.h>

void print(int n);

int main(void) {
    int f;
    printf("Enter n: ");
    scanf("%d", &f);
    print(f);
}

void print(int n) {
    int twoCounter = 1;
    int fiveCounter = 1;
    int highestPrinted = 0;
    while(highestPrinted <= n) {
        int twoholder = twoCounter * 2;
        int fiveholder = fiveCounter * 5;
        if (twoholder < fiveholder && twoholder <= n) {
            twoCounter *= 2;
            printf("%d ", twoCounter);
            highestPrinted = twoCounter;
        } 
        else if (fiveholder <= n) {
            fiveCounter *= 5;
            printf("%d ", fiveCounter);
            highestPrinted = fiveCounter;
        }
        else {
            break;
        }
    }
}