#include "head.h"

int main(int argc, char const *argv[])
{
    int choose, pos;
    bool menu = true;
    DATATYPE temData;
    L_LinkList *headLoop = NULL;
    headLoop = CreateLoopLinkList();
    if (headLoop == NULL)
    {
        return -1;
    }
    while (menu)
    {
        ShowMenu(headLoop, &choose);
        switch (choose)
        {
        case 0:
            printf("please enter the data of you want to insert from head: ");
            scanf("%d", &temData);
            INS_HeadLoopLinkList(headLoop, temData);
            break;
        case 1:
            printf("please enter the data of you want to insert from tail: ");
            scanf("%d", &temData);
            INS_TailLoopLinkList(headLoop, temData);
            break;
        case 2:
            printf("please enter the pos and data of you want to insert from tail: ");
            scanf("%d%d", &pos, &temData);
            INS_PosLoopLinkList(headLoop, pos, temData);
            break;
        case 3:
            RM_HeadLoopLinkList(headLoop);
            break;
        case 4:
            RM_TailLoopLinkList(headLoop);
            break;
        case 5:
            printf("please enter the pos you want to remove: ");
            scanf("%d",&pos);
            RM_PosLoopLinkList(headLoop,pos);
            break;
        case 6:
            printf("please enter the pos you want to find: ");
            scanf("%d",&pos);
            FI_PosLoopLinkList(headLoop,pos);
            break;
        case 7:
            printf("please enter the pos and data you want to updata: ");
            scanf("%d%d",&pos,&temData);
            UP_PosLoopLinkList(headLoop,pos,temData);
            break;
        default:
            Debug(headLoop);
            break;
        }
    }

    return 0;
}
