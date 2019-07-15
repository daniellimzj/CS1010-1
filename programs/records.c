#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

typedef struct
{
    int day;
    int start;
    int end;
} record_t;

typedef struct
{
    char name[81];
    int numRecords;
    record_t records[200];
} employee_t;

int readRecords(employee_t employees[])
{
    FILE *infile;

    if ((infile = fopen("records.in", "r")) == NULL)
    {
        puts("error with opening file");
        exit(1);
    }

    int numEmp;

    fscanf(infile, "%d", &numEmp);

    for (int i = 0; i < numEmp; i++)
    {
        fscanf(infile, "%s %d", employees[i].name, &employees[i].numRecords);

        for (int j = 0; j < employees[i].numRecords; j++)
        {
            fscanf(infile, "%d %d %d", &employees[i].records[j].day, &employees[i].records[j].start, &employees[i].records[j].end);
        }
    }

    fclose(infile);

    return numEmp;
}

void sortEmployees(employee_t employees[], int num)
{
    int sum[num], tempsum;
    employee_t temp;

    for (int i = 0; i < num; i++)
    {
        sum[i] = 0;
        for (int j = 0; j < employees[i].numRecords; j++)
        {
            sum[i] += employees[i].records[j].end - employees[i].records[j].start;
        }
    }

    for (int limit = num - 1; limit > 0; limit--)
    {
        for (int i = 0; i < limit; i++)
        {
            if (sum[i] < sum[i + 1])
            {
                tempsum = sum[i];
                sum[i] = sum[i + 1];
                sum[i + 1] = tempsum;

                temp = employees[i];
                employees[i] = employees[i + 1];
                employees[i + 1] = temp;
            }
        }
    }
}

int lonelyEmployee(employee_t employees[], int num, char name[])
{
    int sum, i_buff;

    for (int k = 0; k < 8; k++)
    {
        sum = 0;
        for (int i = 0; i < num; i++)
        {
            for (int j = 0; j < employees[i].numRecords; j++)
            {
                if (employees[i].records[j].day == k)
                {
                    sum += 1;
                    i_buff = i;
                }
            }
        }
        if (sum == 1)
        {
            strcpy(name, employees[i_buff].name);
            return 1;
        }
    }

    return 0;
}

int main(void)
{
    employee_t employees[256];
    char name[256];

    int num = readRecords(employees);

    sortEmployees(employees, num);

    for (int i = 0; i < num; i++)
    {
        puts(employees[i].name);
        for (int j = 0; j < employees[i].numRecords; j++)
        {
            //printf("%d %d %d\n", employees[i].records[j].day, employees[i].records[j].start, employees[i].records[j].end);
        }
    }

    lonelyEmployee(employees, num, name);

    puts(name);

    return 0;
}