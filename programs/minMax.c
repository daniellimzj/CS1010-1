#include <stdio.h>

int minMax(int arr[], int size, int*max) {
    int i, min;

    min = arr[0];
    *max = arr[0];

    for (i=1; i< size; i++) {
        if (arr[i] > *max)
            *max =   arr[i];
        else if (arr[i] < min)
            min = arr[i];
    }

    return min;
}

int main(void)
{
    int min, max = 0;
    int arr[] = {3,2,1,4,5};

    min = minMax(arr, 5 , &max);

    printf("Min is %d max is %d", min, max);

    return 0;
}
