#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void f(char* str)
{
    int length = strlen(str);
    int i;
    for (i=0; i<length/2;i++) {
        char ch = *(str + i);
        *(str + i) = *(str + length -1 - i);
        *(str + length - 1 - i) = ch;
    }
    
}

int main(void)
{
    char str[] = "abcdef";
    f(str);
    printf("%s\n", str);
    return 0;
}