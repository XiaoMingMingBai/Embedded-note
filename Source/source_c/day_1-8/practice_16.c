#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./myhand.h"
#include "./function.c"

/* defind */

/* type declaration */
typedef char char_arr[20];

/* struct declaration */
struct Student
{
    char_arr name;
    char sex;
    unsigned int age;
    unsigned int score;
};

/* function declaration */
void Print_struct(struct Student *);
void Scanf_struct(struct Student *, char_arr, char, unsigned, unsigned);
void Sort_struct(struct Student *stu);
void Enter_struct(struct Student *stu);

/* A description of the function */
int main(int argc, const char *argv[])
{
    struct Student stu[5] = {};
    struct Student *s = stu;
    Enter_struct(s);
    // Scanf_struct(*s, "zhang", 's', 18, 150);
    // Scanf_struct(*(s + 1), "zhu", 'a', 18, 140);
    // Scanf_struct(*(s + 2), "liu", 'b', 19, 110);
    // Scanf_struct(*(s + 3), "yao", 'c', 18, 132);
    // Scanf_struct(*(s + 4), "yao", 'c', 18, 132);
    // Sort_struct(s);
    Print_struct(s);
    // Print_struct(*(s + 1));
    // Print_struct(*(s + 2));
    // Print_struct(*(s + 3));
    // Print_struct(*(s + 4));

    return 0;
}

void Print_struct(struct Student *stu)
{
    printf("name: %s\tsex: %c\tage: %u\tscore: %u\n", stu->name, stu->sex, stu->age, stu->score);
}

void Scanf_struct(struct Student *stu, char_arr name, char sex, unsigned age, unsigned score)
{
    strcpy(stu->name, name);
    stu->sex = sex;
    stu->age = age;
    stu->score = score;
}

void Sort_struct(struct Student *stu)
{
    struct Student tem;
    for (int i = 1; i < 5; i++)
    {
        for (int j = 0; j < 5 - i; j++)
        {
            if ((stu + j)->score < (stu + j + 1)->score)
            {
                tem = *(stu + j);
                *(stu + j) = *(stu + j + 1);
                *(stu + j + 1) = tem;
            }
        }
    }
}

void Enter_struct(struct Student *stu)
{
    for (int i = 0; i < 1; i++)
    {
        printf("enter the name of %d student : ", i + 1);
        gets((stu + i)->name);
        printf("enter the sex/age/score of %d student : ", i + 1);
        scanf("%c", &((stu + i)->sex));
        scanf("%u%u", &((stu + i)->age), &((stu + i)->score));
    }
}