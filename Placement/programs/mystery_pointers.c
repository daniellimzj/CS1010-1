#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mystery(int a, int *ptr_b, int arr_c[]) {
    ptr_b = &(arr_c[2]);
    ptr_b--;
    *arr_c = *ptr_b;
    ptr_b = &a;
    *ptr_b++;
    a += 2;
    *ptr_b = a;
    return;
}

void main() {
    int a =1, *ptr_b, arr_c[] = {2,3,4};
    ptr_b = arr_c;
    mystery(a,ptr_b,arr_c);
    printf("%d %d %d %d %d\n", a, *ptr_b, arr_c[0], arr_c[1], arr_c[2]);
}
