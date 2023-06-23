/**
 *@file draft1.c
 *@author XiaoMingMingBai (1269596930@qq.com)
 *@brief 
 *@version 0.1
 *@date 2023-04-23
 *
 *@copyright Ming (c) 2023
 *
 */

#include <stdio.h>
#include "./function.c"
#include "./myhand.h"

/**
 *@brief 
 *
 */
#define COUNT 10

int prArr(int *arr);
void soArr(int *arr);

/**
 *@brief 
 *
 *@param argc 
 *@param argv 
 *@return int 
 */
int main(int argc, const char *argv[])
{
    int *ppp = NULL;
    int ar[6]={1,3,45,6,7,8};
    Printf_Arr(ar,6);
    ppp = Malloc_Arr(COUNT);
    Scanf_Arr(ppp, COUNT);
    printf("your arr is :\t");
    Printf_Arr(ppp, 10);
    (*soArr)(ppp);
    printf("\nafter sort arr :\t");
    (*prArr)(ppp);
    free(ppp);
    ppp = NULL;
    return 0;
}

/**
 *@brief 
 *
 *@param arr 
 *@return void* 
 */
int prArr(int *arr)
{
    for (int i = 0; i < COUNT; i++)
    {
        printf("%d\t", *(arr + i));
    }
    return 0;
}

/**
 *@brief 
 *
 *@param arr 
 */
void soArr(int *arr)
{
    int tem;
    for (int i = 1; i < COUNT; i++)
    {
        for (int j = 0; j < COUNT - i; j++)
        {
            if (*(arr + j) > *(arr + j + 1))
            {
                /* code */
                tem = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = tem;
            }
        }
    }
}