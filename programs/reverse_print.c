#include <stdio.h>

void reverse_print(int n);

int main(void) {
    int f;
    printf("How many values to enter? ");
    scanf("%d", &f);
    reverse_print(f);
}

void reverse_print(int n) {
    int m;
    scanf("%d", &m);
    if (n > 1) {
        reverse_print(n - 1);
        printf("%d ", m);
    }
    else {
        printf("%d ", m);
    }
}