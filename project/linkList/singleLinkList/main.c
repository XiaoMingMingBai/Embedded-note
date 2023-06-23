#include "linklist.h"

int main(int argc, char const *argv[])
{
    int menuSum = 1, chooseSum, posNote;
    DATATYPE temData;
    T_LinkList *linkList = NULL;
    linkList = LinkListCreate();
    if (linkList == NULL)
    {
        printf("link list is empty\n");
    }

    while (menuSum)
    {
        system("clear");
        LinkListShow(linkList);
        putchar(10);
        printf("\n0.show  1.insert form front  2.insert form tail  3.insert by pos  4.delete form front\n");
        printf("5.delete from tail  6.delete by pos  7.find by pos  8.rewrite data  9.inverse  10.10.sort\n");
        printf("\n");
        scanf("%d", &chooseSum);
        switch (chooseSum)
        {
        case 0:
            LinkListShow(linkList);
            break;
        case 1:
            printf("please enter the data you want to insert :");
            scanf("%d", &temData);
            INS_HeadLinkList(linkList, temData);
            break;
        case 2:
            printf("please enter the data you want to insert :");
            scanf("%d", &temData);
            INS_TailLinkList(linkList, temData);
            break;
        case 3:
            printf("please enter the pos and data you want to insert :");
            scanf("%d%d", &posNote, &temData);
            INS_PosLinkList(linkList, posNote, temData);
            break;
        case 4:
            RM_HeadLinkList(linkList);
            break;
        case 5:
            RM_TailLinkList(linkList);
            break;
        case 6:
            printf("please enter the location of the data you want to delete:");
            scanf("%d", &posNote);
            RM_PosLinkList(linkList, posNote);
            break;
        case 7:
            printf("please enter the location of the data you want to find:");
            scanf("%d", &posNote);
            printf("the data in this position is %d\n", FIND_PosLinkList(linkList, posNote));
            sleep(1);
            break;
        case 8:
            printf("please enter the location and data you want to rewrite:");
            scanf("%d%d", &posNote, &temData);
            RW_PosLinkList(linkList, posNote, temData);
            break;
        case 9:
            SORT_InverseLinkList(linkList);
            break;
        case 10:
            SORT_LinkList(linkList);
            break;
        case 11:
            Debug(linkList);
            break;
        default:
            break;
        }
    }
    return 0;
}
