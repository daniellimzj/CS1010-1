#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* encode(char prim[])
{
    int size = strlen(prim);

    long num;
    long c;

    for (int i = 0; i < size; i++)
    {
        char letter = prim[i];

        if (letter >= 'A' && letter <= 'Z'){
            num = letter - 'A' + 27;
        }
        else if (letter >= 'a' && letter <= 'z'){
            num = letter - 'a' + 1;
        }

        char encoded = num * 3 % 52;

        if (encoded >= 27 && encoded <= 52){
            c = encoded + 'A' - 27;
        }
        else if (encoded >= 1 && encoded <= 26){
            c = encoded + 'a' - 1;
        }

        prim[i] = c;
    }

    return prim;
}

char* decode(char prim[])
{
    int size = strlen(prim);

    

    for (int i = 0; i < size; i++)
    {
        char letter = prim[i];
        long num;
        long c;

        if (letter >= 'A' && letter <= 'Z'){
            num = letter - 'A' + 27;
        }
        else if (letter >= 'a' && letter <= 'z'){
            num = letter - 'a' + 1;
        }

        while (num % 3 != 0) {
            num += 52;
        }

        char encoded = num / 3;

        if (encoded >= 27 && encoded <= 52){
            c = encoded + 'A' - 27;
        }
        else if (encoded >= 1 && encoded <= 26){
            c = encoded + 'a' - 1;
        }

        prim[i] = c;
    }

    return prim;
}

int main(void)
{
    char prim[] = "IloveU";

    printf("%s\n", encode(prim));

    char code[] = "aJSnoK";

    printf("%s\n", decode(prim));

    return 0;
}