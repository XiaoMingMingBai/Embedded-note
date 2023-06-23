/**
 *@file practice_14.c
 *@author XiaoMingMingBai (1269596930@qq.com)
 *@brief 
 *@version 0.1
 *@date 2023-04-23
 *
 *@copyright Ming (c) 2023
 *
 */

#include <stdio.h>

int myatoi(char *); // Convert to numeric returns

void main()
{
    char str_arr[10] = "123456";
    printf("The converted value is: %d", myatoi(str_arr)); // Pass in a numeric string
}

/**
 *@brief 
 *
 *@param str 
 *@return int 
 */
int myatoi(char *str) 
{
    int num = 0;
    while (*str) // If it's not a tail 0, it keeps looping
    {
        num = num * 10 + *str - '0'; // The numbers are multiplied by 10 stacked
        str++;
    }
    return num;
}