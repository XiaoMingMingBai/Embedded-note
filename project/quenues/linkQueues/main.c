#include "head.h"

int main(int argc, char const *argv[])
{
    bool menu = true;
    int menuChoose, pos;
    M_DATA data;
    Pointer *pointer = LinkQueuesCreat();
    printf("1.in 2.out\n");
    while (menu)
    {

        printf("please enter your choose: ");
        scanf("%d", &menuChoose);
        switch (menuChoose)
        {
        case 1:
            printf("please the data to in: ");
            scanf("%d", &data);
            LinkQueuesIn(pointer, data);
            putchar(10);
            LinkQueuesShow(pointer);
            putchar(10);
            break;
        case 2:
            LinkQueuesOut(pointer);
            putchar(10);
            LinkQueuesShow(pointer);
            putchar(10);
            break;
        default:
            break;
        }
    }
    return 0;
}
