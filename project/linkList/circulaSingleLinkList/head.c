#include "head.h"

void ShowMenu(L_LinkList *headLoop, int *choose)
{
    system("clear");
    ShowLoopLinkList(headLoop);
    printf("0.insert from head 1.insert from tail 2.insert by pos\n");
    printf("3.remove from head 4.remove from tail 5.remove by pos\n");
    printf("6.find data by pos 7.updata by pos\n");
    printf("please enter the number of your choice: ");
    scanf("%d", choose);
}

L_LinkList *CreateLoopLinkList(void)
{
    L_LinkList *h = NULL;
    h = (L_LinkList *)malloc(sizeof(L_LinkList));
    if (h == NULL)
    {
        printf("%s malloc error!", __func__);
        return NULL;
    }
    h->dataNode = (DATATYPE)0;
    h->nextNode = h;
    return h;
}

int ShowLoopLinkList(L_LinkList *headLoop)
{
    L_LinkList *head = headLoop;
    printf("Loop->");
    while (headLoop->nextNode != head)
    {
        headLoop = headLoop->nextNode;
        printf("%d->", headLoop->dataNode);
    }
    puts("loop");
    putchar(10);
}

int INS_HeadLoopLinkList(L_LinkList *headLoop, DATATYPE data)
{
    L_LinkList *node = NULL;
    node = (L_LinkList *)malloc(sizeof(L_LinkList));
    if (node == NULL)
    {
        printf("%s malloc error!", __func__);
        return -1;
    }
    node->dataNode = data;
    node->nextNode = headLoop->nextNode;
    headLoop->nextNode = node;
    return 0;
}

int INS_TailLoopLinkList(L_LinkList *headLoop, DATATYPE data)
{
    L_LinkList *node = NULL, *head = headLoop;
    node = (L_LinkList *)malloc(sizeof(L_LinkList));
    if (node == NULL)
    {
        printf("%s malloc error!", __func__);
        return -1;
    }
    while (headLoop->nextNode != head)
    {
        headLoop = headLoop->nextNode;
    }
    node->dataNode = data;
    node->nextNode = head;
    headLoop->nextNode = node;
}

int INS_PosLoopLinkList(L_LinkList *headLoop, int pos, DATATYPE data)
{
    L_LinkList *node = NULL, *head = headLoop;
    node = (L_LinkList *)malloc(sizeof(L_LinkList));
    if (node == NULL)
    {
        printf("%s malloc error!", __func__);
        return -1;
    }
    for (int i = 0; i < pos - 1; i++)
    {
        if (headLoop->nextNode == head)
        {
            break;
        }
        headLoop = headLoop->nextNode;
    }
    node->dataNode = data;
    node->nextNode = headLoop->nextNode;
    headLoop->nextNode = node;
    return 0;
}

int EmptyLoopLinkList(L_LinkList *headLoop)
{
    if (headLoop->nextNode == headLoop)
    {
        printf("loop link list is empty!");
        return 1;
    }
    return 0;
}

int RM_HeadLoopLinkList(L_LinkList *headLoop)
{
    L_LinkList *tem = NULL;
    tem = headLoop->nextNode;
    headLoop->nextNode = headLoop->nextNode->nextNode;
    free(tem);
    tem = NULL;
    printf("remove finish\n");
    sleep(0.5);
    return 0;
}

int RM_TailLoopLinkList(L_LinkList *headLoop)
{
    L_LinkList *tem = NULL, *head = headLoop;
    while (headLoop->nextNode->nextNode != head)
    {
        headLoop = headLoop->nextNode;
    }
    tem = headLoop->nextNode;
    headLoop->nextNode = head;
    free(tem);
    printf("remove finish\n");
    sleep(0.5);
    tem = NULL;
    return 0;
}

int RM_PosLoopLinkList(L_LinkList *headLoop, int pos)
{
    L_LinkList *tem = NULL, *head = headLoop;
    for (int i = 0; i < pos - 1; i++)
    {
        if (headLoop->nextNode->nextNode == head)
        {
            break;
        }
        headLoop = headLoop->nextNode;
    }
    tem = headLoop->nextNode;
    headLoop->nextNode = tem->nextNode;
    free(tem);
    printf("remove finish\n");
    sleep(0.5);
    tem = NULL;
    return 0;
}

void Debug(L_LinkList *headLoop)
{
    for (int i = 0; i < 6; i++)
    {
        INS_TailLoopLinkList(headLoop, i);
    }
}

int FI_PosLoopLinkList(L_LinkList *headLoop, int pos)
{
    L_LinkList *head = headLoop;
    for (int i = 0; i < pos; i++)
    {
        headLoop = headLoop->nextNode;
        if (headLoop == head)
        {
            printf("not so such!");
            return -1;
        }
    }
    printf("the data at this position is %d",headLoop->dataNode);
    sleep(1);
    return 0;
}

int UP_PosLoopLinkList(L_LinkList *headLoop, int pos, DATATYPE data)
{
    L_LinkList *head = headLoop;
    for (int i = 0; i < pos; i++)
    {
        headLoop = headLoop->nextNode;
        if (headLoop == head)
        {
            printf("not so such!");
            return -1;
        }
    }
    headLoop->dataNode=data;
    return 0;
}
