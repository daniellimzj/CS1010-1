#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int determinant(int mtx[][10], int size) {
    for(int i = 0 ; i< size; i++) {
            for (int j = 0 ; j <size; j ++) {
                printf("%d ", mtx[i][j]);
            }
            printf("\n");
        }
    
    if (size == 2)
    {
        return (mtx[0][0] * mtx[1][1]) - (mtx[0][1] * mtx[1][0]);
    }

    int sum = 0;
    int i, j ,k, l, m, det;

    for (l = 0; l < size; l++)
    {
        int newMtx[size - 1][10];

            for (i = 1; i < size; i++)
            {
                m = 0;
                for (j = 0; j < size; j++)
                {
                    if (j != l)
                    {
                        newMtx[i-1][m] = mtx[i][j];
                        m++;
                    }
                }
            }


        for(i = 0 ; i< size -1; i++) {
            for ( j = 0 ; j <size-1; j ++) {
                printf("%d ", newMtx[i][j]);
            }
            printf("\n");
        }

        det = determinant(newMtx, size - 1);
        printf("%d\n", det);

        if (l%2) {
            sum += -1*mtx[0][l]*det;
        } else sum += mtx[0][l]*det;
    }

    return sum;
}

int main(void)
{
    int mtx[][10] = {{1,3,5,9},
                    {1,3,1,7},
                    {4,3,9,7},
                    {5,2,0,9}};

    int det = determinant(mtx, 4);

    printf("%d", det);

    return 0;
}
