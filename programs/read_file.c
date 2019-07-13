#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIC_LEN 8
#define MAX_STRING_LEN 50

typedef struct {
    char matric[MATRIC_LEN];
    char name[MAX_STRING_LEN];
    char gender;
    double GPA;
    char department[MAX_STRING_LEN];
} student_t;

int read_file(char filename[], student_t stu_list[]) {
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
            str[MATRIC_LEN] = '\0';
            //printf("%s ", str);
            strcpy(stu_list[i].matric, str);
            //printf("%s ", stu_list[i].matric);
        }
        if (fgets(str, MAX_STRING_LEN, infile) != NULL)
        {
            str[strlen(str) - 1] = '\0';
            //printf("%s ", str);
            strcpy(stu_list[i].name, str);
            //printf("%s ", stu_list[i].matric);
        }
        if (fgets(str, MAX_STRING_LEN, infile) != NULL)
        {
            str[strlen(str) - 1] = '\0';
            //printf("%s ", str);
            stu_list[i].gender = *str;
        }
        if (fgets(str, MAX_STRING_LEN, infile) != NULL)
        {
            str[strlen(str) - 1] = '\0';
            //printf("%s ", str);
            stu_list[i].GPA = atof(str);
        }
        if (fgets(str, MAX_STRING_LEN, infile) != NULL)
        {
            str[strlen(str) - 1] = '\0';
            //printf("%s\n", str);
            strcpy(stu_list[i].department, str);
        }

        //printf("Value read: %s, %s, %c, %.2f, %s\n", stu_list[i].matric, stu_list[i].name, stu_list[i].gender, stu_list[i].GPA, stu_list[i].department);
        i++;
    }

    fclose(infile);

    return i + 1;
}

void sort_stu(student_t arr_stu[], int stu_num) {
    int limit;
    char temp[MAX_STRING_LEN];

    for (limit = stu_num -2; limit >= 0; limit--)
    {
        for (int i = 0; i < stu_num; i++)
        {
            if (strcmp(arr_stu[i].matric, arr_stu[i + 1].matric) > 0)
            {
                strcpy(temp, arr_stu[i].matric);
                strcpy(arr_stu[i].matric, arr_stu[i+1].matric);
                strcpy(arr_stu[i+1].matric, temp);
            }
        }
    }
}

int main(void) {
    char file[] = "students.txt";

    student_t stu_list[20];

    int num = read_file(file, stu_list);

    for (int i = 0; i< num; i++) {
        printf("%s\n", stu_list[i].matric);
    }

    sort_stu(stu_list, num);

    for (int i = 0; i< num; i++) {
        printf("%s\n", stu_list[i].matric);
    }

    //printf("Value read: %s %s %c %.2f %s\n", stu_list[0].matric, stu_list[0].name, stu_list[0].gender, stu_list[0].GPA, stu_list[0].department);

}