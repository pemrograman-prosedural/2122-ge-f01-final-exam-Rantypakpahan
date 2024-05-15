#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dorm.h"
#include "student.h"

void addDorm(struct dorm_t *dorm, int *banyak_dorm, char *input) {
    char *name = strtok(NULL, "#");
    char *capacity = strtok(NULL, "#");
    char *gender = strtok(NULL, "#");
   
    strcpy(dorm[*banyak_dorm].name, name);
    dorm[*banyak_dorm].capacity = atoi(capacity);

    if (strcmp(gender, "male") == 0) {
        dorm[*banyak_dorm].gender = 0;
    } else if (strcmp(gender, "female") == 0) {
        dorm[*banyak_dorm].gender = 1;
    }

    dorm[*banyak_dorm].residents_num = 0;
    (*banyak_dorm)++;
}

void printAllDormDetails(struct dorm_t *dorm, int banyak_dorm) {
    for (int i = 0; i < banyak_dorm; i++) {
        if (dorm[i].gender != 1) {
            printf("%s|%d|male|%d\n", dorm[i].name, dorm[i].capacity, dorm[i].residents_num);
        } else {
            printf("%s|%d|female|%d\n", dorm[i].name, dorm[i].capacity, dorm[i].residents_num);
        }
    }
}

void printAllDorms(struct dorm_t *dorm, int banyak_dorm) {
    for (int i = 0; i < banyak_dorm; i++) {
        if (dorm[i].gender != 1) {
            printf("%s|%d|male\n", dorm[i].name, dorm[i].capacity);
        } else {
            printf("%s|%d|female\n", dorm[i].name, dorm[i].capacity);
        }
    }
}