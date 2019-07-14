#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

typedef struct {
    char name[51];
    char gender;
    int age;
} cust_t;

int readCustomers(cust_t customers[]) {
    FILE *infile;

    if ((infile = fopen("customer.dat", "r")) == NULL)
    {
        printf("Error opening file");
        exit(1);
    }

    int size;

    fscanf(infile, "%d", &size);

    while (!feof(infile))
    {
        for (int i = 0; i < size; i++)
        {
            fscanf(infile, "%s %c %d", customers[i].name, &customers[i].gender, &customers[i].age);
        }
    }

    fclose(infile);

    return size;
}

float computeSimilarity(char name1[], char name2[]) {
    
}

int main(void)
{
    cust_t customers[5];

    int size = readCustomers(customers);

    printf("%d\n", size);

    for (int i = 0; i< size; i++) {
        printf("%s %c %d\n", customers[i].name, customers[i].gender, customers[i].age);
    }
}
