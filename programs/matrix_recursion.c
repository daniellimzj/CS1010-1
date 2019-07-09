#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COL 10

void borderMatrix(int mtx[ ][MAX_COL], int start, int stop) {
    int i,j;


    if(start >= stop) {
        return;
    }

    if (mtx[start][start] == 0)
    {
        for (i = start; i <= stop; i++)
        {
            for (j = start; j <= stop; j++)
            {
                mtx[i][j] = 1;
            }
        }
    }
    else
    {
        for (i = start; i <= stop; i++)
        {
            for (j = start; j <= stop; j++)
            {
                mtx[i][j] = 0;
            }
        }
    }
    
    for (int i = 0; i <= stop + start ; i ++) {
        for (int j = 0; j <= stop + start; j ++) {
            printf("%d ", mtx[i][j]);
        }
        printf("\n");
    }

    borderMatrix(mtx, start + 1, stop - 1);
}

int main(void)
{
    int n = 6;

    int mtx[n][n];

    

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            mtx[i][j] = 0;
        }
    }

    borderMatrix(mtx, 0, n - 1);

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            printf("%d ", mtx[i][j]);
        }
        printf("\n");
    }
}