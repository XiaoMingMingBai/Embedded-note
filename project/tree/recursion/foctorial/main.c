#include <stdio.h>


int foctorial(int num);

int main(int argc, char const *argv[])
{
    printf("%d",foctorial(5));
    return 0;
}

int foctorial(int num)
{
    if (num==1)
    {
        return 1;
    }
    return num*foctorial(num-1);
}
