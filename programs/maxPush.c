#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

void maxPush(int arr[], int size, int index, int length) {
    if (length == 1 || index == size - 1) {
        return;
    }

    if (arr[index] > arr[index + 1]) {
        arr[index+1] = arr[index];
    }

    return maxPush(arr, size, index + 1, length - 1);
}

int maxPull(int arr[], int size, int index, int length) {
    int end = index + length - 1;

    if (end > size) {
        end = size - 1;
    }
    
    if (length == 1) {
        return index;
    }

    if (arr[end] > arr[end - 1]) {
        arr[end - 1] = arr[end];
    }

    return maxPull(arr, size, index, length - 1);
}

int main(void)
{
    int A[] = {11,3,5,8,19,7,10,12,6,9};

    int index, length;

    scanf("%d %d", &index, &length);

    maxPull(A, 10, index , length);

    for (int i =0;i<10;i++){
        printf("%d, ", A[i]);
    }

    return 0;

}
