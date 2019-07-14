#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

void translate(char sentence[], char output[])
{
    char *p;
    int j = 0;
    char wa[] = " wa ";
    char fa[] = " fa ";

    p = strtok(sentence, " ");

    while (p != NULL)
    {
        for (int i = 0; i < strlen(p); i++)
        {
            if (p[i] == 'a')
            {
                p[i] = 'o';
                i = strlen(p);
            }
        }

        strcat(output, p);

        if (j % 2) {
            strcat(output, fa);
        } else {
            strcat(output, wa);
       }

        j++;


        p = strtok(NULL, " ");
    }
}

int main(void)
{
    char in[] = "i have a banana", out[100];

    translate(in, out);

    puts(out);

    return 0;

}
