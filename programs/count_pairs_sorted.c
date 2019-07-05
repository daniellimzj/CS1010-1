#include <stdio.h>

int count_pairs_sorted(int arr[], int size, int key);

int main(void) {
    int a[] = {0, 1, 3, 4, 6, 7, 8};

    int count = count_pairs_sorted(a, 7, 7);

    printf("%d\n", count);

    return 0;
}

int count_pairs_sorted(int arr[], int size, int key) {
    int count = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = size - 1; j > i; j--) {
            if (arr[i] + arr[j] == key) {
                count++;
                break;
            }
        }
    }
    return count;
}