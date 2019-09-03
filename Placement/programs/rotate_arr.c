#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main(void)
{
    int arr[5][5] = {{0}};
    int i,j,k,temp;

    for (i = 0; i < 5; i++){
        arr[0][i]=1;
        arr[i][2]=1;
    }

    for ( i = 0; i< 5; i++) {
        for (j = 0 ; j < 5; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
printf("\n");
    for ( i = 0; i< 5; i++) {
        for (j = 0 ; j < 5; j++) {
            if (i + j < 4) {
                temp = arr[i][j];
                arr[i][j] = arr[4-j][4-i];
                arr[4-j][4-i] = temp;
            }
        }
    }
    
    for ( i = 0; i< 5; i++) {
        for (j = 0 ; j < 5; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
