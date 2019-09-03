#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int start;
    int end;
    char name[20];
}employee_t;

int read_employee(employee_t emp[])
{
    int num;
    printf("Enter the number of employees: ");
    scanf("%d\n", &num);
    for (int i = 0; i<num; i++){
            scanf("%s %d %d", emp[i].name, &emp[i].start, &emp[i].end);
    }

    return num;
}

void overlap(employee_t new_emp, employee_t emp[], int size)
{
    printf("Enter new employee:\n");
    scanf("%s %d %d", new_emp.name, &new_emp.start, &new_emp.end);
    int overlapTime = 0;
    for (int i = 0; i<size; i++){
        if (new_emp.start >= emp[i].start && new_emp.end <= emp[i].end) {
            printf("%s %d %d\n", emp[i].name, emp[i].start, emp[i].end);
            overlapTime += new_emp.end - new_emp.start;
        } else if (new_emp.start < emp[i].end && new_emp.start >= emp[i].start && new_emp.end >= emp[i].end){
            printf("%s %d %d\n", emp[i].name, emp[i].start, emp[i].end);
            overlapTime += emp[i].end - new_emp.start;
        } else if (new_emp.end > emp[i].start && new_emp.start <= emp[i].start && new_emp.end <= emp[i].end){
            printf("%s %d %d\n", emp[i].name, emp[i].start, emp[i].end);
            overlapTime += new_emp.end - emp[i].start;
        } else if (new_emp.start <= emp[i].start && new_emp.end >= emp[i].end){
            printf("%s %d %d\n", emp[i].name, emp[i].start, emp[i].end);
            overlapTime += emp[i].end - emp[i].start;
        }
    }

    printf("%d\n", overlapTime);
}

int main(void)
{
    employee_t emp[10];

    int size = read_employee(emp);

    employee_t new_emp;
    
    overlap(new_emp, emp, size);


    return 0;
}