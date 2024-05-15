// 12S23008 - Ranty Insen Pakpahan
// 12S23015 - Kevin Kristoforus Samosir

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libs/dorm.h"
#include "./libs/student.h"

int main(int _argc, char **_argv) 
{
    int looping = 0;
    char command[100];
    struct student_t *student = malloc(100 * sizeof(struct student_t));
    struct dorm_t *dorm = malloc(100 *sizeof(struct dorm_t));
    int student_num = 0;
    int banyak_dorm = 0;
    
    while (looping != 1 )
    {
        command[0] = '\0';
        short k = 0;
        while (1 == 1)
        {
            char i = getchar();
            if (i == '\n')
            {
                break;
            }
            if (i == '\r')
            {
                continue;
            }
            command[k] = i;
            command[++k] = '\0';    
        }

        char *input = strtok(command, "#");

        if (strcmp(input, "student-add") == 0)
        {
            input = strtok(NULL, "#");
            strcpy(student[student_num].id, input);
            input = strtok(NULL, "#");
            strcpy(student[student_num].name, input);
            input = strtok(NULL, "#");
            strcpy(student[student_num].year, input);
            input = strtok(NULL, "#");
            if (strcmp(input, "male") == 0)
            {
                student[student_num].gender = 0;
            }
            else if (strcmp(input, "female") == 0)
            {
                student[student_num].gender = 1;
            }
            student[student_num].dorm = NULL;
            student_num++;
        }
        if (strcmp(input, "student-print-all") == 0)
        {
            for (int i = 0; i < student_num; i++)
            {
                if (student[i].gender != 1)
            {
                printf("%s|%s|%s|male\n", student[i].id, student[i].name, student[i].year);
                
            }
            else 
            {
                printf("%s|%s|%s|female\n", student[i].id, student[i].name, student[i].year);
            }
            } 
        }
        if (strcmp(input, "student-print-all-detail") == 0)
        {
            for (int i = 0; i < student_num; i++)
            {
                if (student[i].dorm == NULL)
                {
                    if (student[i].gender != 1)
                    {
                        printf("%s|%s|%s|male|unassigned\n", student[i].id, student[i].name, student[i].year);
                    }   else 
                        {
                            printf("%s|%s|%s|female|unassigned\n", student[i].id, student[i].name, student[i].year);
                        }
                }  else 

            
                    {
                    if (student[i].gender != 1)
                    {
                    printf("%s|%s|%s|male|%s\n", student[i].id, student[i].name, student[i].year, student[i].dorm->name);
                    }   else 
                        {
                            printf("%s|%s|%s|female|%s\n", student[i].id, student[i].name, student[i].year, student[i].dorm->name);
                        }
                    }
            }
        }

        if (strcmp(input, "dorm-add") == 0)
        {
            input = strtok(NULL, "#");
            strcpy(dorm[banyak_dorm].name, input);
            input = strtok(NULL, "#");
            dorm[banyak_dorm].capacity = atoi(input);
            input = strtok(NULL, "#");
            if (strcmp(input, "male") == 0)
            {
                dorm[banyak_dorm].gender = 0;
            }
            else if (strcmp(input, "female") == 0)
            {
                dorm[banyak_dorm].gender = 1;
            }
            dorm[banyak_dorm].residents_num = 0;
            banyak_dorm++;
        }
        if (strcmp(input, "student-leave") == 0) {
    char *id = strtok(NULL, "#");
    int index = -1;
    int dormIndex = -1;
    for (int i = 0; i < student_num; i++) {
        if (strcmp(id, student[i].id) == 0) {
            index = i;
            if (student[i].dorm != NULL) {
                for (int j = 0; j < banyak_dorm; j++) {
                    if (strcmp(student[i].dorm->name, dorm[j].name) == 0) {
                        dormIndex = j;
                        break;
                    }
                }
                if (dormIndex != -1) {
                    dorm[dormIndex].residents_num--;
                }
            }
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < student_num - 1; i++) {
            student[i] = student[i + 1];
        }
        student_num--;
    } 
}

          
          

       
        if (strcmp(input, "dorm-print-all") == 0)
        {
            for (int i = 0; i < banyak_dorm; i++)
            {
                if (dorm[i].gender != 1)
                {
                    printf("%s|%d|male\n", dorm[i].name, dorm[i].capacity);
                }
                else 
                {
                    printf("%s|%d|female\n", dorm[i].name, dorm[i].capacity);
                }   
            }
        }

        if (strcmp(input, "assign-student") == 0)
        {
            int indexstudent = 0;
            int indexdorm = 0;  
            char *nim = strtok(NULL, "#");
            char *namadorm = strtok(NULL, "#");
            for (int i = 0; i < student_num; i++)
            {
                if(strcmp(nim, student[i].id) == 0 )
                {
                    indexstudent = i;
                } 
                
            }
            for (int i = 0; i < banyak_dorm; i++)
            {
                if (strcmp(namadorm, dorm[i].name) == 0)
                {
                    indexdorm = i;
                }
                
            }
            
            if (dorm[indexdorm].capacity > dorm[indexdorm].residents_num)
            {
                if (student[indexstudent].gender == dorm[indexdorm].gender)
                {
                    student[indexstudent].dorm = &dorm[indexdorm];
                    dorm[indexdorm].residents_num++;
                }
            }
        }
        
        if (strcmp(input, "move-student") == 0)
        {
            int indexstudent = 0;
            int indexdorm = 0;
            int temp_dorm = 0;
            char *nim = strtok(NULL, "#");
            char *namadorm = strtok(NULL, "#");
            for (int i = 0; i < student_num; i++)
            {
                if(strcmp(nim, student[i].id) == 0 )
                {
                    indexstudent = i;
                } 
            }

            for (int i = 0; i < student_num; i++)
            {
                if (student[indexstudent].dorm == &dorm[i])
                {
                    temp_dorm = i;
                }
            }
            
            for (int i = 0; i < banyak_dorm; i++)
            {
                if (strcmp(namadorm, dorm[i].name) == 0)
                {
                    indexdorm = i;
                }
            }

            if (dorm[indexdorm].capacity > dorm[indexdorm].residents_num && student[indexstudent].gender == dorm[indexdorm].gender)
            {
                if (student[indexstudent].dorm != NULL)
                {
                    dorm[temp_dorm].residents_num--;
                }

                student[indexstudent].dorm = &dorm[indexdorm];
                dorm[indexdorm].residents_num++;
            }           
        }
        
         if (strcmp(input, "dorm-print-all-detail") == 0)
        {
            for (int i = 0; i < banyak_dorm; i++)
            {
                if (dorm[i].gender != 1)
            {
                printf("%s|%d|male|%d\n", dorm[i].name, dorm[i].capacity, dorm[i].residents_num);
                
            }
            else 
            {
                printf("%s|%d|female|%d\n", dorm[i].name, dorm[i].capacity, dorm[i].residents_num);
            }
            } 
        }     

        
        if (strcmp( input, "---") == 0)
        {
            looping = 1;
        }
    }
}  

