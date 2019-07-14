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
    float count = 0;

    if (strlen(name1) > strlen(name2)) {
        for (int i = 0; i< strlen(name2); i++) {
            if (tolower(name1[i]) == tolower(name2[i])) {
                count++;
            }
        }
        return count/strlen(name1);
    } else {
        for (int i = 0; i< strlen(name1); i++) {
            if (tolower(name1[i]) == tolower(name2[i])) {
                count++;
            }
        }
        return count/strlen(name2);
    }
}

int findDuplicates(cust_t customers[], int size, int index, cust_t duplicates[]) {
    int j = 0;

    for (int i = 0; i < size; i++)
    {
        if (i != index && customers[i].gender == customers[index].gender && customers[i].age == customers[index].age && computeSimilarity(customers[i].name, customers[index].name) > 0.7)
        {
            duplicates[j] = customers[i];
            j++;
        }
    }

    return j;
}

void sortDuplicates(cust_t customer, cust_t duplicates[], int size) {
    cust_t temp;
    
    for(int start = 0; start < size -1 ; start ++) {
        float max = computeSimilarity(duplicates[start].name, customer.name);
        int max_i = start;
        for (int i = start + 1; i<size; i++) {
            if (computeSimilarity(duplicates[i].name, customer.name) > max) {
                max = computeSimilarity(duplicates[i].name, customer.name);
                max_i = i;
            }
        }
        temp = duplicates[max_i];
        duplicates[max_i] = duplicates[start];
        duplicates[start] = temp;
    }
    
}

int main(void)
{
    cust_t customers[5], duplicates[6];

    int size = readCustomers(customers);

    printf("%d\n", size);

    for (int i = 0; i< size; i++) {
        printf("%s %c %d\n", customers[i].name, customers[i].gender, customers[i].age);
    }

    printf("%.2f\n", computeSimilarity(customers[2].name, customers[4].name));

    int dupsSize = findDuplicates(customers, size, 2, duplicates);

    printf("%d\n", dupsSize);

    for (int i = 0; i < dupsSize; i++) {
        printf("%s %c %d\n", duplicates[i].name, duplicates[i].gender, duplicates[i].age);
    }

    sortDuplicates(customers[3], duplicates, dupsSize);

    for (int i = 0; i < dupsSize; i++) {
        printf("%s %c %d\n", duplicates[i].name, duplicates[i].gender, duplicates[i].age);
    }
}
