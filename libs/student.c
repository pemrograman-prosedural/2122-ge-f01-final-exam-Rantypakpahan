#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dorm.h"
#include "student.h"

void assign_student(struct student_t *student, struct dorm_t *dorm)
{
    if (dorm->capacity > dorm->residents_num && student->gender == dorm->gender)
    {
        student->dorm = dorm;
        dorm->residents_num+= 1;
    }
}
 

void move_student(struct student_t *student, struct dorm_t *dorm, struct dorm_t *_dorm)
{
    if (dorm->capacity > dorm->residents_num && student->gender == dorm->gender)
    {
        student->dorm = dorm;
        dorm->residents_num += 1;
        _dorm->residents_num -= 1;
    }
    
}

void addStudent(struct student_t *student, int *student_num, char *input) {
    char *id = strtok(NULL, "#");
    char *name = strtok(NULL, "#");
    char *year = strtok(NULL, "#");
    char *gender = strtok(NULL, "#");

    strcpy(student[*student_num].id, id);
    strcpy(student[*student_num].name, name);
    strcpy(student[*student_num].year, year);

    if (strcmp(gender, "male") == 0) {
        student[*student_num].gender = 0;
    } else if (strcmp(gender, "female") == 0) {
        student[*student_num].gender = 1;
    }

    (*student_num)++;
}

void printAllStudents(struct student_t *student, int student_num) {
    for (int i = 0; i < student_num; i++) {
        if (student[i].gender != 1) {
            printf("%s|%s|%s|male\n", student[i].id, student[i].name, student[i].year);
        } else {
            printf("%s|%s|%s|female\n", student[i].id, student[i].name, student[i].year);
        }
    }
}

void printAllStudentDetails(struct student_t *student, int student_num) {
    for (int i = 0; i < student_num; i++) {
        if (student[i].gender != 1) {
            printf("%s|%s|%s|male|unassigned\n", student[i].id, student[i].name, student[i].year);
        } else {
            printf("%s|%s|%s|female|unassigned\n", student[i].id, student[i].name, student[i].year);
        }
    }
}