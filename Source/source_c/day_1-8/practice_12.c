/******************************************************************
 *   自定义实现strlen\strcpy\strncpy\strcat\strncat\strcmp\strncmp
 ******************************************************************/

#include <stdio.h>
#define COUNT 10

/**************************************************
 *   函数声明
 **************************************************/
int my_strlen(char *str);
char *my_strcpy(char *, char *);
char *my_strncpy(char *, char *, int);
char *my_strcat(char *, char *);
char *my_strncat(char *, char *, int);
int my_strcmp(char *, char *); 
int my_strncmp(char *, char *,int);
void printx(void);

/*******************************************************
 * 主函数
 *******************************************************/
int main(int argc, char const *argv[])
{
    char str_one[80] = {"tello world! It's fun to learn!"};
    char str_two[23] = {"tglszis a examination!"};
    char str_three[40] = {"tglso world! It's fun to learn!"};
    printf("str_one is: %s\nstr_two is: %s\n", str_one, str_two);
    printx();

    printf("This is after cpy runs : \t%s\n", my_strcpy(str_one, str_two));
    my_strcpy(str_one, str_three);
    printf("This is after ncpy runs :\t%s\n", my_strncpy(str_one, str_two, 6));
    my_strcpy(str_one, str_three);
    printx();

    printf("This is after cat runs : \t%s\n", my_strcat(str_one, str_two));
    my_strcpy(str_one, str_three);
    printf("This is after ncat runs : \t%s\n", my_strncat(str_one, str_two, 2));
    my_strcpy(str_one, str_three);
    printx();

    printf("This is after cmp runs : \t%d\n", my_strcmp(str_one, str_two));
    my_strcpy(str_one, str_three);
    printf("This is after ncmp runs : \t%d\n", my_strncmp(str_one, str_two,3));
    my_strcpy(str_one, str_three);
    return 0;
}

/*
 *   打印隔离
 */
void printx(void)
{
    printf("\n");
    for (int i = 0; i < 66; i++)
    {
        printf("*");
    }
    printf("\n");
}

/***********************************************************
 *   strlen
 ***********************************************************/
int my_strlen(char *str)
{
    int len = 0;
    while (*(str++) != '\0')
    {
        len++;
    }
    return len;
}

/*****************************************************
 *   strcpy\strncpy
 *****************************************************/
char *my_strcpy(char *str_f, char *str_b)
{
    int len = 0;
    while (*(str_b + len) != '\0')
    {
        *(str_f + len) = *(str_b + len);
        len++;
    }
    *(str_f + len) = '\0';
    return str_f;
}

char *my_strncpy(char *str_f, char *str_b, int sum)
{
    for (int i = 0; i < sum; i++)
    {
        *(str_f + i) = *(str_b + i);
    }
    return str_f;
}

/*******************************************************
 *   strcat\strncat
 *******************************************************/
char *my_strcat(char *str_f, char *str_b)
{
    int len = my_strlen(str_f);
    int i = 0;
    while (*(str_b + i) != '\0')
    {
        *(str_f + len + i) = *(str_b + i);
        i++;
    }
    return str_f;
}

char *my_strncat(char *str_f, char *str_b, int len)
{
    int end = my_strlen(str_f);
    int i;
    for (i = 0; i < len; i++)
    {
        *(str_f + end + i) = *(str_b + i);
    }
    *(str_f+end+i)='\0';
    return str_f;
}

/*******************************************************
 *   strcmp\strncmp
 *******************************************************/
int my_strcmp(char *str_f,char *str_b)
{
    int i=0;
    while (*(str_f+i)!='\0')
    {
        if (*(str_f+i)!=*(str_b+i))
        {
            if (*(str_f+i)>*(str_b+i))
            {
                return 1;
            }
            return -1;
        }
        i++;
    }
    return (*(str_f+i)-*(str_b+i));
}

int my_strncmp(char *str_f,char *str_b,int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        if (*(str_f+i)=='\0')
        {
            break;
        }
        if (*(str_f+i)!=*(str_b+i))
        {
            if (*(str_f+i)>*(str_b+i))
            {
                return 1;
            }
            return -1;
        }
    }
    return (*(str_b+i-1)-*(str_f+i-1));
}