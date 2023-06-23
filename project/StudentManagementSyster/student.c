#include <stdio.h>
#include <string.h>
#include "student1.h"


int Insert_stu(struct Class *cls)
{
    int count = cls->count;
    if (cls->count >= 100)
    {
        printf("The class is full!");
        return -1;
    }
    printf("please enter the student's name: ");
    scanf("%[^\t]\t%c%d%d", cls->stu[count].name, &(cls->stu[count].sex), &(cls->stu[count].age), &(cls->stu[count].score));
    cls->count++;
    return 0;
}
int Set_stu_list(struct Class *cls)
{

    return 0;
}

int Delete_stu(struct Class *cls)
{
    Name tem;
    printf("please enter the name of the student you want to delete: ");
    gets(tem);
    for (int i = 0; i < cls->count; i++)
    {
        if (strcmp(tem, (cls->stu + i)->name) == 0)
        {
            for (int j = i; j < cls->count; j++)
            {
                cls->stu[j] = *(cls->stu + j + 1);
            }
            cls->count--;
            printf("delete successfully\n");
            return 0;
        }
    }
    printf("there is no such student in this class\n");
    return 0;
}
int Update_stu_score(struct Class *cls)
{
    Name tem;
    short int score;
    printf("please enter the name of the student you want to update score: ");
    gets(tem);
    for (int i = 0; i < cls->count; i++)
    {
        if (strcmp(tem, (cls->stu + i)->name) == 0)
        {
            printf("please enter the student's new score: ");
            scanf("%d", &score);
            (*(cls->stu + i)).score = score;
            printf("Score update success!\n");
            return 0;
        }
    }
    printf("there is no such student in this class\n");
    return 0;
}

int Select_stu(struct Class *cls)
{
    Name tem;
    printf("please enter the name of the stuent you want to find: ");
    scanf("%[^\n]", tem);
    for (int i = 0; i < cls->count; i++)
    {
        if (strcmp(tem, (cls->stu + i)->name) == 0)
        {
            printf("No.%d\tname: %s\tsex: %c\tage: %d\tscore: %d\n", i + 1, cls->stu[i].name, cls->stu[i].sex, cls->stu[i].age, cls->stu[i].score);
        }
    }
    return 0;
}
int Sort_stu_score(struct Class *cls)
{
    typedef enum select_sort
    {
        name,
        score,
    } Sort;
    Sort select;
    printf("************************************\n");
    printf("       0.by name 1.by score\n");
    printf("************************************\n");
    printf("please enter number: ");
    scanf("%d", &select);
    switch (select)
    {
    case name:
        Sort_stu_score_name(cls);
        break;
    case score:
        Sort_stu_score_score(cls);
        break;
    default:
        printf("enter error!");
        break;
    }
    return 0;
}

int Sort_stu_score_name(struct Class *cls)
{
    struct Student tem;
    for (int i = 1; i < cls->count; i++)
    {
        for (int j = 0; j < cls->count - i; j++)
        {
            if (strncmp(cls->stu[j].name, cls->stu[j + 1].name, 1) > 0)
            {
                tem = cls->stu[j];
                cls->stu[j] = cls->stu[j + 1];
                cls->stu[j + 1] = tem;
            }
        }
    }
    printf("Sorting by name succeeded!");
    return 0;
}
int Sort_stu_score_score(struct Class *cls)
{
    struct Student tem;
    for (int i = 1; i < cls->count; i++)
    {
        for (int j = 0; j < cls->count - i; j++)
        {
            if (cls->stu[j].score<cls->stu[j + 1].score)
            {
                tem = cls->stu[j];
                cls->stu[j] = cls->stu[j + 1];
                cls->stu[j + 1] = tem;
            }
        }
    }
    printf("Sorting by name succeeded!");
    return 0;
}

int Printf_stu_score(struct Class *cls)
{
    for (int i = 0; i < cls->count; i++)
    {
        printf("No.%d\tname: %-20s\tsex: %c\tage: %d\tscore: %d\n", i + 1, cls->stu[i].name, cls->stu[i].sex, cls->stu[i].age, cls->stu[i].score);
    }
    return 0;
}

int Debug_stu(struct Class *cls)
{
    strcpy((cls->stu + 2)->name, "zhang ming yang");
    (cls->stu + 2)->sex = 'a';
    (cls->stu + 2)->age = 18;
    (cls->stu + 2)->score = 150;
    struct Student tem1 =
        {
            .name = "zhang ming yang",
            .sex = 's',
            .age = 18,
            .score = 150};
    struct Student tem2 =
        {
            .name = "zhu kang yuan",
            .sex = 's',
            .age = 18,
            .score = 140};
    cls->stu[0] = tem1;
    cls->stu[1] = tem2;
    cls->count = 3;
    return 0;
}