#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int binarySearch(int a[], int item, int low, int high)
{
    if (high <= low)
        return (item > a[low]) ? (low + 1) : low;

    int mid = (high + low) / 2;

    if (a[mid] == item)
    {
        return mid + 1;
    }

    if (item > a[mid])
    {
        return binarySearch(a, item, mid + 1, high);
    }
    else
    {
        return binarySearch(a, item, low, mid - 1);
    }
}

void insertionSort(int a[], int n)
{
    int i;
    int j;

    for (i = 1; i < n; i++) {
        j = i -1;
        int temp = a[i];
        int loc = binarySearch(a, temp, 0, j);
        while ( j >= loc) {
            a[j+1] = a[j];
            j--;
        }
        a[loc] = temp;
    }
}

int main(void)
{
    int a[5] = {12, 10, 17, 4, 7};

    printf("%d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4]);

    insertionSort(a, 5);

    printf("%d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4]);

    return 0;
}