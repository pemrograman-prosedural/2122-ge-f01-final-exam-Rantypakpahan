#ifndef DORM_H
#define DORM_H

#include "gender.h"



struct dorm_t
{
    char name[20];
    unsigned short capacity;
    enum gender_t gender;
    unsigned short residents_num;
};

struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender);
void print_dorm(struct dorm_t *dorm, int tempshow);
void print_dorm_detail(struct dorm_t *dorm, int tempshow);
void addDorm(struct dorm_t *asrama, int *banyak_asrama, char *input);
void printAllDormDetails(struct dorm_t *asrama, int banyak_asrama);
void printAllDorms(struct dorm_t *asrama, int banyak_asrama);


#endif