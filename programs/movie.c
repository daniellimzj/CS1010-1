#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

void mostSimilar(int arr[][5], int users, int movies, int *user1, int *user2) {
    double minDist = 100;
    double sum, eDist;
    int k;

    for (int i = 0; i < users - 1; i++) {
        for (int j = 1; j < users; j++) {
            sum = 0;
            if (i != j) {
                for (k = 0; k< movies; k++) {
                    sum += (arr[i][k] - arr[j][k]) * (arr[i][k] - arr[j][k]);
                }
                //printf("%.2f, %d, %d, %d", sum, i , j , k);
                eDist = sqrt(sum);
                //printf("%.2f\n", eDist);
                if (eDist < minDist) {
                    minDist = eDist;
                    
                    *user1 = i;
                    *user2 = j;

                    //printf("%.2f, %d, %d\n", minDist, *user1, *user2);
                }
            }
        }
    }
}

int main(void)
{
    int arr[][5] = {{4,4,3,3,2},{4,3,1,1,5},{5,5,5,2,2},{4,3,1,1,4}};
    int r, user1 = 0, user2 = 0;

    mostSimilar(arr, 4, 5, &user1, &user2);

    printf("%d %d", user1, user2);

    return 0;
}
