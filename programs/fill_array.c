#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define N 6

void fill_array(int mtx[N][N])
{
    for (int i = 0; i < N; i++) {
        int j = i;
        mtx[i][j] = 0;
    }

    int j = 0;
    int k = N - 1;
    int temp;
    int count = 1;

    for (int i = 1; i <= N*(N-1); i++) {
        temp = j;
        j = k;
        k = temp;
        if (i % 2 == 1)
        {
            mtx[j][k] = i;
        }
        else
        {
            mtx[j][k] = i;

            if (k == N - 1)
            {
                k -= count;
                count++;
                j = 0;
            }
            else
            {
                k++;
                j++;
            }
        }
    }

    
}

int main(void)
{
    int mtx[N][N];

    fill_array(mtx);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", mtx[i][j]);
        }
        printf("\n");
    }
}
