/*
 *   定义字符数组，并使用字符串进行初始化，要求将字符串进行倒置。
 */

#include <stdio.h>

#define COUNT 8

void inversion_str(char *, char *);
void printst(char *);

int main(int argc, char const *argv[])
{
    char str[COUNT] = {"abcdefg"};
    printf("source string:  \t");
    printst(str);
    inversion_str(str, str + COUNT - 2);
    printf("inverted string:\t");
    printst(str);
    return 0;
}

void inversion_str(char *st, char *endst)
{
    char tem;
    for (int i = 0; i < (endst - st) / 2; i++)
    {
        tem = *(st + i);
        *(st + i) = *(endst - i);
        *(endst - i) = tem;
        // printst(st);
    }
}

void printst(char *st)
{
    while (*st != '\0')
    {
        printf("%c\t", *(st++));
    }
    printf("\n");
}