#ifndef STUDENT_H
#define STUDENT_H

#include "gender.h"
#include "dorm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student_t
{
    char id[12];
    char name[40];
    char year[5];
    enum gender_t gender;
    struct dorm_t *dorm;
}; 

struct student_t create_student(char *_id, char *_name, char *_year,
                                enum gender_t _gender);
void print_student_details(struct student_t *student, int tempallshow);
void print_student(struct student_t *student, int tempshow);
void move_student(struct student_t *student, struct dorm_t *dorm, struct dorm_t *dorm_t);
void assign_student(struct student_t *student, struct dorm_t *dorm);
void addStudent(struct student_t *student, int *student_num, char *input);
void printAllStudents(struct student_t *student, int student_num);
void printAllStudentDetails(struct student_t *student, int student_num);


#endif
