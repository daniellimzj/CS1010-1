#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

typedef struct
{
    char name[50];
    int age;
} student_t;

void func1(char name[], int age)
{
    strcat(name, "*");
    age += 5;
}

void func2(student_t stu[])
{
    int i;
    for (i = 0; i < 3; i++)
    {
        stu[i].age /= 2;
    }
}

void func3(student_t *ptr)
{
    strcpy(ptr->name, "Rose");
    ptr->age += 10;
}

int main(void)
{
    int i;
    student_t stu[3] = {{"Jo", 25}, {"Mar", 20}, {"Ott", 33}};

    func1(stu[1].name, stu[1].age);
    func2(stu);
    func3(stu);

    for (i = 0; i < 3; i++)
        printf("%s %d ", stu[i].name, stu[i].age);

    return 0;
}
