#include "head.h"

int main(int argc, char const *argv[])
{
    bool menu = true;
    int menuChoose, pos;
    M_DATA data;
    Node *head = StackCreat();
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
            StackIn(head, data);
            putchar(10);
            StackShow(head);
            putchar(10);
            break;
        case 2:
            StackOut(head);
            putchar(10);
            StackShow(head);
            putchar(10);
            break;
        default:
            break;
        }
    }
    return 0;
}
