#include <stdio.h>

/*******************************************************************
 *   1-6 day
 *******************************************************************/

int practice_studentGrades();
int practice_judgmentYear();
int practice_judgmentTriangle();
int practice_judgmentDay();
int practice_numberComposition(int upper);
int practice_multiplicationTable(int upper);
int practice_begMoney();
int practice_forFig();

int main(int argc, char const *argv[])
{
    // practice_studentGrades();
    // practice_judgmentYear();
    // practice_judgmentTriangle();
    // practice_judgmentDay();
    // practice_numberComposition(6);
    // practice_multiplicationTable(9);
    // practice_begMoney();
    // practice_forFig();
    return 0;
}

/***********************************************************************
 *练习题1：
 *    在终端输入一个整数，用来表示学生的成绩
 *    输出学生成绩对应的等级
 *        [90,100]	A
 *        [80, 90)	B
 *        [70, 80)	C
 *        [60, 70)	D
 *        [0,60)	不及格
 ***********************************************************************/

int practice_studentGrades()
{
    float g_stuGrades; // 定义成绩变量
    while (1)          // 死循环，便于测试
    {
        printf("Please enter your grade");          // 提示输入
        scanf("%f", &g_stuGrades);                  // 把输入存到变量地址
        if (g_stuGrades >= 0 && g_stuGrades <= 100) // 判断是否为0-100
        {
            if (g_stuGrades >= 90) // 判断是否为A
            {
                printf("Your grade is A.\n");
            }
            else if (g_stuGrades >= 80) // 判断是否为B
            {
                printf("Your grade is B.\n");
            }
            else if (g_stuGrades >= 70) // 判断是否为C
            {
                printf("Your grade is C.\n");
            }
            else if (g_stuGrades >= 60) // 判断是否为D
            {
                printf("Your grade is D.\n");
            }
            else
            {
                printf("Your grades are unqualified!\n"); // 否则不及格
            }
        }
        else
        {
            printf("Input error!\n"); // 提示输入错误
        }
    }
    return 0; // 程序结束
}

/**********************************************************************
 *练习题2：
 *	在终端输入一个整数，用来表示年份，输出这一年是平年还是闰年
 *	闰年：能被4整除且不能被100整除，或者能被400整除
 **********************************************************************/

int practice_judgmentYear()
{
    int g_numYear;
    while (1)
    {
        printf("please enter the g_numYear.");
        scanf("%d", &g_numYear);
        if (g_numYear > 0)
        {
            if (((g_numYear % 400) == 0) || (((g_numYear % 4) == 0) && ((g_numYear % 100) != 0))) // Divisible by 400 or (divisivle by 4 and not divisivle by 100)
            {
                printf("%d is a leap Year.\n", g_numYear); // leap year
            }
            else
            {
                printf("%d is a common Year.\n", g_numYear); // common year
            }
        }
        else
        {
            printf("Input error\n"); // input error
        }
    }
    return 0;
}

/*******************************************************************************
 *练习题3：
 *	在终端输入三个整数，分别表示三角形的三边长
 *	输出能否构成三角形
 *	如果能构成三角形，再输出能构成什么类型的三角形：等腰、等边、直角、普通。
 *
 *	使用if嵌套。
 *******************************************************************************/

int practice_judgmentTriangle()
{
    int g_sideTri_1, g_sideTri_2, g_sideTri_3;
    while (1)
    {
        printf("Please enter the three sides of the triangle.");
        scanf("%d%d%d", &g_sideTri_1, &g_sideTri_2, &g_sideTri_3);
        if (((g_sideTri_1 + g_sideTri_2) > g_sideTri_3) &&
            ((g_sideTri_1 + g_sideTri_3) > g_sideTri_2) &&
            ((g_sideTri_2 + g_sideTri_3) > g_sideTri_1)) // Determine whether it is a triangle
        {
            if ((g_sideTri_1 == g_sideTri_2) && (g_sideTri_2 == g_sideTri_3)) // Determine whether it is an equilateral triangle
            {
                printf("This is an equilateral triangle.\n");
            }
            else if ((g_sideTri_1 == g_sideTri_2) || (g_sideTri_1 == g_sideTri_3) || (g_sideTri_2 == g_sideTri_3)) // Determine whether it is an isosceles triangle
            {
                printf("This is an isosceles triangle.\n");
            }
            else if (((g_sideTri_1 * g_sideTri_1 + g_sideTri_2 * g_sideTri_2) == (g_sideTri_3 * g_sideTri_3)) ||
                     ((g_sideTri_1 * g_sideTri_1 + g_sideTri_3 * g_sideTri_3) == g_sideTri_2 * g_sideTri_2) ||
                     ((g_sideTri_2 * g_sideTri_2 + g_sideTri_3 * g_sideTri_3) == g_sideTri_1 * g_sideTri_1)) // Determine whether it is an right
            {
                printf("This is an right triangle.\n");
            }
            else
            {
                printf("This is an ordinary triangle.\n");
            }
        }
        else
        {
            printf("Cannot form a trangle!\n");
        }
    }
    return 0;
}

/************************************************************************
 *   从终端输入年份和月份，
 *   判断此月份对应的天数
 ************************************************************************/

int practice_judgmentDay()
{
    int year, month, num;
    int sunmber[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    /*     if (year >= 0 && (month <=12 && month >= 1))
        {
            if (((year % 400) == 0) || (((year % 4) == 0) && ((year % 100) != 0)))
            {
                if (month == 2)
                {
                    num = sunmber[month-1] - 1;
                }
                else
                {
                    num = sunmber[month-1];
                }
            }
            else
            {
                num = sunmber[month-1];
            }
        }
        return 0; */

    while (1)
    {
        printf("please enter:");
        scanf("%d%d", &year, &month);
        if (year >= 0)
        {
            switch (month)
            {
            case 1:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
                printf("There are %d days in %d %d\n", sunmber[month - 1], month, year);
                break;
            case 2:
                if (((year % 400) == 0) || (((year % 4) == 0) && ((year % 100) != 0)))
                {
                    printf("There are %d days in %d %d\n", sunmber[month - 1] - 1, month, year);
                }
                else
                {
                    printf("There are %d days in %d %d\n", sunmber[month - 1], month, year);
                }
                break;
            default:
                printf("input error!!!\n");
                break;
            }
        }
        else
        {
            printf("input error!!!\n");
        }
    }
}

/**************************************************
 *   1-9 组成三位数，每一位不能重复
 **************************************************/

int practice_numberComposition(int upper)
{
    int a = 1, b, c, sum = 0;
    while (a <= upper)
    {
        b = 1;
        while (b <= upper)
        {
            c = 1;
            while (c <= upper)
            {
                if (a != b && b != c && a != c)
                {
                    printf("%d%d%d\t", a, b, c++);
                    sum++;
                }
                c++;
            }
            b++;
            printf("\n");
        }
        a++;
    }
    printf("There are %d combinations", sum);
    return 0;
}

/************************************************
 *   乘法表
 ************************************************/

int practice_multiplicationTable(int upper)
{
    int i = 1, j;
    printf("input multiplication table:\n");
    while (i <= upper)
    {
        j = 1;
        while (j <= i)
        {
            printf("%d * %d = %d\t", j++, i, i * j);
        }
        i++;
        printf("\n");
    }
}

/**********************************************************
 *求出用50元， 20元， 10元， 可以组合成100元的所有的情况？
 *
 **********************************************************/

int practice_begMoney()
{
    int five, two, one;
    printf("50\t20\t10\n");
    for (five = 0; five < 3; five++)
    {
        for (two = 0; two < 6; two++)
        {
            for (one = 0; one < 11; one++)
            {
                if ((50 * five + 20 * two + one * 10) == 100)
                {
                    printf("%d\t%d\t%d\n", five, two, one);
                }
                else if ((50 * five + 20 * two + one * 10) > 100)
                {
                    break;
                }
            }
        }
    }
}

/**********************************************************
 *使用for循环嵌套，打印以下图形。
 *    FEDCBA
 *    +FEDCB
 *    ++FEDC
 *    +++FED
 *    ++++FE
 *    +++++F
 *
 *********************************************************/

int practice_forFig()
{
    for (int i = 0; i < 6; i++)
    {
        int q = i;
        int w = 'F';
        while (q)
        {
            printf("+");
            q--;
        }
        for (int j = 6; j > i; j--)
        {
            printf("%c", w--);
        }
        printf("\n");
    }
}
