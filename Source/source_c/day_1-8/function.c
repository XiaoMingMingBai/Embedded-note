/**
 *@file dddd.c
 *@author XiaoMingMingBai (1269596930@qq.com)
 *@brief 
 *@version 0.1
 *@date 2023-04-23
 *
 *@copyright Ming (c) 2023
 *
 */

#include <stdlib.h>
#include <stdio.h>

/* Print the array and enter the array size */
void Printf_Arr(int *ar, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%d\t", *(ar + i));
    }
    printf("\n");
}

/* Enter in the array, enter the array size */
void Scanf_Arr(int *arr, int count)
{
    printf("please enter the number of ten :\t");
    for (int i = 0; i < count; i++)
    {
        scanf("%d", arr + i);
    }
}

/* Heap allocation shaping memory, enter the numbe */
int *Malloc_Arr(int count)
{
    int *arr = (int *)(malloc(sizeof(int) * count));
    return arr;
}

/* Generate a random array of numbers and enter a number */
void Test_Arr(int *arr, int count)
{
    for (int i = 0; i < count; i++)
    {
        /* code */
    }
}