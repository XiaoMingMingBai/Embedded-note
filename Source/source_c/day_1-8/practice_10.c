/*
 *定义一个字符数组，char c_arr[1024]= {0},
 *	从终端输入一个字符串对字符数组进行初始化，字符串中只能包含小写字母，
 *	统计次字符数组中出现每个字符的个数。
 */
#include <stdio.h>
#include<windows.h>
#include "D:\12695\OneDrive - MSFT\Code\HuaQing\HAND\myhand.h"

void c_sta(char *);

int main(int argc, char const *argv[])
{
    char c_arr[66] = {"abcdefghijklmnopqrstuvwxyz"};
    printf("source string:%s\n", c_arr);
    c_sta(c_arr);
}

void c_sta(char *arr)
{
    int c_sum_arr[26] = {0, 0};
    for (int i = 0; i < 26; i++)
    {
        printf("%c\t", 97 + i);
    }
    printf("\n");
    while (*arr != '\0')
    {
        printf("\r");
        int tem = *arr++ - 97;
        c_sum_arr[tem]++;
        for (int i = 0; i < 26; i++)
        {
            printf("%d\t", c_sum_arr[i]);
        }
        Sleep(600);
    }
    for (int i = 0; i < 26; i++)
    {
        printf("%d\t", c_sum_arr[i]);
    }
}