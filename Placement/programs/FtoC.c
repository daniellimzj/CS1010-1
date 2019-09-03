#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

void FtoC(int n, int F[][MAX_LEN], int C[][MAX_LEN])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (F[i][j] == 1)
            {
                C[i][j] = 1;
            }
        }
    }
    for (int l = 0; l < n; l++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (C[j][k] == 1 && C[k][i] == 1)
                    {
                        C[i][j] = 1;
                    }
                }
            }
        }
    }
}