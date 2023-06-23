#include "head.h"

int main(int argc, char const *argv[])
{
    bool menu = true;
    int menuChoose, pos;
    M_DATA data;
    LoopQue *list = LoopQueueCreate();
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
            LoopQueueIn(list, data);
            putchar(10);
            LoopQueueShow(list);
            putchar(10);
            break;
        case 2:
            LoopQueueOut(list);
            putchar(10);
            LoopQueueShow(list);
            putchar(10);
            break;
        default:
            break;
        }
    }
    return 0;
}
