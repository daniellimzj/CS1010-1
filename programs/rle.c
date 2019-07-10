#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compress(int arr[], int size, int comp[]) {
    int count = 1;
    int j = 0;
    for (int i = 0; i<size; i++) {
        if (arr[i] == arr[i + 1]) {
            count += 1;
        } else {
            comp[j] = count;
            comp[j + 1] = arr[i];
            j += 2;
            count = 1;
        }
    }

    return j;
}

int decompress(int comp[], int size, int decomp[]) {
    int pos = 0;
    
    for (int i = 0; i < size; i += 2) {
        for (int j = 0; j<comp[i]; j++) {
            decomp[pos] = comp[i+ 1];
            pos++;
        }
    }

    return pos;
}

int main(void)
{
    int arr[] = {3,3,3,2,2,2,2,7,7,7,2,2,2,6,9,9,9,9,5,27,27,42};
    int comp[22];

    int count = compress(arr, 22, comp);

    printf("%d\n", count);

    for (int i = 0; i<count; i++) {
        printf("%d ", comp[i]);
    }

    int decomp[30];

    int decount = decompress(comp, count, decomp);

    printf("\n%d\n", decount);

    for (int i = 0; i<decount; i++) {
        printf("%d ", decomp[i]);
    }
}
