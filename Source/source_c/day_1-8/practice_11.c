/*
 *   定义一个二维字符数组，并对其进行初始化，
 *	使用冒泡排序的方式，对字符串进行排序。
 */

#include <stdio.h>
#include <string.h>

#define COUNT 5

void sort_str(char (*)[]);
void print_str(char (*)[]);

int main(int argc, char const *argv[])
{
    char str_name[COUNT][10] = {"chang", "bang", "fuang", "yong", "liu"};
    sort_str(str_name);
    print_str(str_name);
    return 0;
}

void sort_str(char (*arr)[10])
{
    char tem[10];
    for (int i = 0; i < COUNT - 1; i++)
    {
        for (int j = 0; j < COUNT - 1 - i; j++)
        {
            if (strncmp(*(arr + j), *(arr + COUNT - 1 - i), 1) > 0)
            {
                strcpy(tem, *(arr + j));
                strcpy(*(arr + j), *(arr + COUNT - 1 - i));
                strcpy(*(arr + COUNT - 1 - i), tem);
                print_str(arr);
                putchar('\n');
            }
        }
    }
}

void print_str(char (*arr)[10])
{
    for (int i = 0; i < COUNT; i++)
    {
        printf("%s\t", arr + i);
    }
}