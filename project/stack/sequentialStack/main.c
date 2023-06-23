#include "head.h"

int main(int argc, char const *argv[])
{
    int choose;
    bool menu=true;
    M_DATA data;
    seqstack_N *list=SeqStackCreate();
    while (menu)
    {
        choose=Menu(list);
        switch (choose)
        {
        case 1:
            printf("please enter the data you want to push stack: ");
            scanf("%d",&data);
            SeqStackPush(list,data);
            break;
        case 2:
            SeqStackPop(list);
            break;
        default:
            break;
        }
    }
    return 0;
}