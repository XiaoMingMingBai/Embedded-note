#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./student1.h"

/* defind */

/* function declaration */

/* type declaration */

/* struct declaration */

/* A description of the function */
int main(int argc, const char *argv[])
{
    /*declaration*/
    short int chose;
    short int loop = 1;
    /*declaration class*/
    struct Class *Cls = (struct Class *)malloc(sizeof(struct Class));
    if (Cls == NULL)
    {
        printf("malloc faile!\n");
        return -1;
    }
    /*initialize class*/
    Cls->count = -1;
    while (loop)
    {
    INPUT:
        printf("\t\t*************************************************************\n");
        printf("\t\t0.insert 1.delete 2.select 3.update 4.sort 5.print 6.exit\n");
        printf("\t\t*************************************************************\n");
        printf("please enter number: ");
        scanf("%hd", &chose);
        /*Garbage character cleaning*/
        while (getchar() != '\n')
            ;
        /*chose*/
        if (chose > 8 || chose < 0)
        {
            printf("input error! Please try again.\n");
            goto INPUT;
        }
        switch (chose)
        {
        case 0:
            Insert_stu(Cls);
            break;
        case 1:
            Delete_stu(Cls);
            break;
        case 2:
            Select_stu(Cls);
            break;
        case 3:
            Update_stu_score(Cls);
            break;
        case 4:
            Sort_stu_score(Cls);
            break;
        case 5:
            Printf_stu_score(Cls);
            break;
        case 6:
            loop = 0;
            break;
        case 8:
            Debug_stu(Cls);
            break;
        default:
            break;
        }
    }
    printf("exit success");
    return 0;
}