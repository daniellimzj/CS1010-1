#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main(void)
{
    int N = 8;

    int mat[N][N];
    int i , j , k, lower , upper , count;

    for (k = 0; k< N; k += N/4) {
        lower =k;
        upper =k+N/4;
        count =0;

        for (i = k; i<N/4+k; i++) {
            for (j=0;j<lower;j++)
                mat[i][j] = 0;

            for (j= lower; j<upper; j++)
                mat[i][j] = ++count;

            for (j=upper; j<N;j++)
                mat[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }


}
