#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

typedef struct {
    char name[50];
    char grade;
} student_t;

void func1(student_t *stu) {
    stu->name[0] = 'S';
}

void func2(char *grade){
    *grade +=2;
}

int main(void)
{
    student_t stu[2] = {{"Ta", 'F'}, {"Ki", 'B'}};

    func1(stu);
    func2(&stu[1].grade);

    printf("%s %c ", stu[0].name, stu[0].grade);
    printf("%s %c ", stu[1].name, stu[1].grade);

    return 0;
}
