#include "head.h"

int main(int argc, char const *argv[])
{
    bool menu = true;
    int menuChoose, pos;
    DATA_D data;
    D_LinkList *list = D_CreateLinkList();
    while (menu)
    {
        menuChoose = D_ShowLinkList(list);
        switch (menuChoose)
        {
        case 0:
            debug(list);
            break;
        case 1:
            printf("please enter the data you want to insert");
            scanf("%d%*c", &data);
            D_INS_HeadLinkList(list, data);
            break;
        case 2:
            printf("please enter the data you want to insert");
            scanf("%d%*c", &data);
            D_INS_TailLinkList(list, data);
            break;
        case 3:
            printf("please enter the pos and data you want to insert");
            scanf("%d%d%*c", &pos, &data);
            D_INS_PosLinkList(list, pos, data);
            break;
        case 4:
            D_DEL_HeadLinkList(list);
            break;
        case 5:
            D_DEL_TailLinkList(list);
            break;
        case 6:
            printf("please enter the pos you want to insert");
            scanf("%d%*c", &pos);
            D_DEL_PosLinkList(list, pos);
            break;
        case 7:
            printf("please enter the pos you want to find");
            scanf("%d%*c", &pos);
            D_FIND_PosLinkList(list, pos);
            break;
        case 8:
            printf("please enter the pos amd data you want to updata");
            scanf("%d%d%*c", &pos, &data);
            getchar();
            D_UP_PosLinkList(list, pos, data);
            break;
        default:
            break;
        }
    }
    return 0;
}