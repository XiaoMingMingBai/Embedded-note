#include <stdio.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#define COUNT 20


char *mygets(char *arr,int n)
{
    char *s=arr;
    int tem=n,ch=0;
    fprintf(stdout,"enter a miximum of %d char: ",n);
    while (tem--)
    {
        if ((ch=getch())=='\n')
        {
            ch='\0';
            *s=ch;
            return arr;
        }
        *(s++)=ch;
    }
    *s='\0';
    return arr;
}

int main(int argc, char const *argv[])
{
    char str[COUNT];
    mygets(str,6);
    fprintf(stdout,"%s\n",str);
    return 0;
}
