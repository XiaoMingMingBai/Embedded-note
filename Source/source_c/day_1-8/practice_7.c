/*****************************************************
 *   g定义一个整型数组，数组长度为10，
 *	从终端输入的方式对数组的每个元素进行初始化。
 *	将数组中的成员进行倒叙。
 *****************************************************/

#include <stdio.h>

#define count 10

int exchange(int pos[]);

int main(int argc, char const *argv[])
{
    int positive[count] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < count; i++)
    {
        printf("%d\t", positive[i]);
    }
    exchange(positive);
    printf("\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d\t", positive[i]);
    }
    return 0;
}

/***************************************************
 * 数组前后置换
 ***************************************************/
int exchange(int *pos)
{
    int tem;
    for (int i = 0; i < count / 2; i++)
    {
        tem = pos[i];
        pos[i] = pos[count - 1 - i];
        pos[count - 1 - i] = tem;
    }
}