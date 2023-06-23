#include <stdio.h>
#include <string.h>
#include "./myhand.h"
#include "./function.c"

/* defind */

/* function declaration */

/* type declaration */
typedef struct Person
{
    char *name;
    char sex;
    int age;
} Person_t;

/* struct declaration */
typedef struct Student
{
    struct Person *per1;
    Person_t *per2;
    float score;
} Student_t;

/* A description of the function */
int main(int argc, const char *argv[])
{
    Student_t *stu = (Student_t *)malloc(sizeof(Student_t));
    stu->per1 = (Person_t *)malloc(sizeof(Person_t));
    stu->per2 = (Person_t *)malloc(sizeof(Person_t));
    stu->per1->name = (char *)malloc(10);
    stu->per2->name = (char *)malloc(10);

    strcpy(stu->per1->name, "zhang m");
    strcpy(stu->per2->name, "zhang s");
    stu->score = 150.0;
    stu->per1->sex = 'a';
    stu->per2->sex = 's';
    stu->per1->age = 23;
    stu->per2->age = 18;
    printf("name: %s\tsex: %c\tage: %d\tscore: %d\n", stu->per1->name, stu->per1->sex, stu->per1->age, stu->score);
    printf("name: %s\tsex: %c\tage: %d\tscore: %d\n", stu->per2->name, stu->per2->sex, stu->per2->age, stu->score);
    return 0;
}