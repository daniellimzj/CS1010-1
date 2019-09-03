#include <stdio.h>
#include <string.h>

typedef struct
{
    char matric[10]; // matric number
    int num_mods;    // number of modules taken
    int credit[8];   // credits of modules taken
    // credit[0] is the credit
    // of the first module, etc.
    char grade[8][3]; // grades of modules taken
    // grade[0] is the grade of
    // the first module, etc.
} student_t;

void read_records(student_t stu[]);
double get_grade_point(char grade[]);
double cal_cap(student_t stu);
double get_highest_cap(student_t stu[]);
void print_top_student(student_t stu[], double max_cap);

int main(void)
{
    student_t stu[10];

    read_records(stu);

    double max_cap = get_highest_cap(stu);

    print_top_student(stu, max_cap);
}

void read_records(student_t stu[])
{
    FILE *infile;
    int i, j, size = 10;

    infile = fopen("roster.txt", "r");

    for (i = 0; i < size; i++)
    {
        fscanf(infile, "%s %d", stu[i].matric, &stu[i].num_mods);
        for (j = 0; j < stu[i].num_mods; j++)
        {
            fscanf(infile, "%d %s", &stu[i].credit[j], stu[i].grade[j]);
        }
    }

    fclose(infile);
}

double get_grade_point(char grade[])
{
    char gradeLetter[11][3] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "D+", "D", "F"};
    double gradePoint[11] = {5.0, 5.0, 4.5, 4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0};

    for (int i = 0; i < 11; i++)
    {
        if (strcmp(grade, gradeLetter[i]) == 0)
        {
            return gradePoint[i];
        }
    }
}

double cal_cap(student_t stu)
{
    double sumCreditGrade = 0, sumCredit = 0;
    for (int i = 0; i < stu.num_mods; i++)
    {
        sumCreditGrade += (double)stu.credit[i] * get_grade_point(stu.grade[i]);
    }
    for (int i = 0; i < stu.num_mods; i++)
    {
        sumCredit += (double)stu.credit[i];
    }
    return sumCreditGrade / sumCredit;
}

double get_highest_cap(student_t stu[])
{
    double newCap = cal_cap(stu[0]);
    for (int i = 0; i < 10; i++)
    {
        if (cal_cap(stu[i]) > newCap)
        {
            newCap = cal_cap(stu[i]);
        }
    }

    return newCap;
}

void print_top_student(student_t stu[], double max_cap)
{
    for (int i = 0; i < 10; i++)
    {
        if (cal_cap(stu[i]) == max_cap)
        {
            printf("%.2f %s\n", max_cap, stu[i].matric);
        }
    }
}