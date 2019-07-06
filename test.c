#include <stdio.h>
#include <string.h>
#include <stdlib.h>

func(char* s){
    if (*s) {
        func(s+1);
        printf("%c", *s);
    }
}

int main(void)
{
    char *title = "CS1010";
    func(title);
    printf("\n");
}

/*

int main() {
    int list[] = {9, 3, 2, 8,5,6,7,4,1,10};
    int i,temp;

    for (i=1;i<10;i++) {
        if (list[i] > list [i-1])
        {
            temp = list[i];
            list[i] = list [i+1];
            list[i+1] = temp;
        }
    }
    for (i=0;i<10;i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

int main(void) {
    int n = 9;
    if (n>10)
        if (n>11)
            printf("A\n");
    else
    {
            printf("B\n");
    }
    
}

void mystery(int a, int *ptr_b, int arr_c[]) {
    ptr_b = &(ary_c[2]);
    ptr_b--;
    *ary_c = *ptr_b;
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
*/