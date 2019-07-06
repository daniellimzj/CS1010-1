#include <stdio.h>

#define MATRIC_LEN=8;
#define MAX_STRING_LEN = 50;

typedef struct {
    char matric[MATRIC_LEN];
    char name[MAX_STRING_LEN];
    char gender;
    double GPA;
    char department[50];
} student_t;

int read_file