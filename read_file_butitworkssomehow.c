#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 46
#define ISBN_LEN 18
typedef struct{
char title[MAX_STRING_LEN];
char author[MAX_STRING_LEN];
char isbn[ISBN_LEN];
float price;
int qty;
} book_t;

int read_file(char filename[], book_t book_list[]) {
    FILE *infile;
    int i = 0;

    infile = fopen(filename, "r");

    if(infile == NULL) {
      perror("Error opening file");
      return (-1);
    }

    while (!feof(infile))
    {
        char str[MAX_STRING_LEN];
        
        if (fgets(str, MAX_STRING_LEN, infile) != NULL)
        {
            str[strlen(str)-1] = '\0';
            //printf("%s ", str);
            strcpy(book_list[i].title, str);
            //printf("%s ", stu_list[i].matric);
        }
        if (fgets(str, MAX_STRING_LEN, infile) != NULL)
        {
            str[strlen(str) - 1] = '\0';
            //printf("%s ", str);
            strcpy(book_list[i].author, str);
            //printf("%s ", stu_list[i].matric);
        }
        if (fgets(str, MAX_STRING_LEN, infile) != NULL)
        {
            str[strlen(str) - 1] = '\0';
            //printf("%s ", str);
            strcpy(book_list[i].isbn, str);
        }
        if (fgets(str, MAX_STRING_LEN, infile) != NULL)
        {
            str[strlen(str) - 1] = '\0';
            //printf("%s ", str);
            book_list[i].price = atof(str);
        }
        if (fgets(str, MAX_STRING_LEN, infile) != NULL)
        {
            str[strlen(str) - 1] = '\0';
            //printf("%s\n", str);
            book_list[i].qty = atoi(str);
        }

        i++;
    }

    fclose(infile);

    return i + 1;
}

void print_books(book_t book_list[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%s, by %s, ISBN %s, SGD%.2f, Qty %d\n", book_list[i].title, book_list[i].author, book_list[i].isbn, book_list[i].price, book_list[i].qty);
    }
}

int main(void)
{
    book_t book_list[800];

    read_file("book.txt", book_list);

    print_books(book_list, 3);

}