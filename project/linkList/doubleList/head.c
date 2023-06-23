#include "head.h"

D_LinkList *D_CreateLinkList(void)
{
    D_LinkList *tem = (D_LinkList *)malloc(sizeof(D_LinkList));
    if (tem == NULL)
    {
        printf("%s malloc error!", __func__);
        return NULL;
    }
    tem->dataNode = 0;
    tem->preNode = tem->nextNode = NULL;
    return tem;
}

void MenuList()
{
    printf("0.debug\n");
    printf("1.insert from head 2.insert from tail 3.insert by pos\n");
    printf("4.delete from head 5.delete from tail 6.delete by pos\n");
    printf("7.find by pos 8.updata by pos\n");
    printf("please enter your choice: ");
}

int D_ShowLinkList(D_LinkList *headList)
{
    int tem;
    system("clear");
    printf("forward double link list");
    while (headList->nextNode != NULL)
    {
        headList = headList->nextNode;
        printf("-%d", headList->dataNode);
    }
    putchar(10);
    printf("reverse double link list: ");
    while (headList->preNode != NULL)
    {
        printf("%d-", headList->dataNode);
        headList = headList->preNode;
    }
    putchar(10);
    MenuList();
    scanf("%d", &tem);
    return tem;
}

void debug(D_LinkList *head)
{
    for (int i = 1; i <= 6; i++)
    {
        D_INS_HeadLinkList(head, i);
    }
}

int D_INS_HeadLinkList(D_LinkList *headList, DATA_D dataNode)
{
    D_LinkList *node = (D_LinkList *)malloc(sizeof(D_LinkList));
    if (node == NULL)
    {
        printf("malloc error in %s", __func__);
        return -1;
    }
    node->dataNode = dataNode;
    node->nextNode = headList->nextNode;
    node->preNode = headList;
    if (headList->nextNode != NULL)
    {
        headList->nextNode->preNode = node;
    }
    headList->nextNode = node;
    return 0;
}

int D_INS_TailLinkList(D_LinkList* headList, DATA_D dataNode)
{
    D_LinkList *node = (D_LinkList *)malloc(sizeof(D_LinkList));
    if (node == NULL)
    {
        printf("malloc error in %s", __func__);
        return -1;
    }
    node->dataNode = dataNode;
    while (headList->nextNode != NULL)
    {
        headList = headList->nextNode;
    }
    node->nextNode = headList->nextNode;
    headList->nextNode=node;
    return 0;
}

int D_INS_PosLinkList(D_LinkList *headList, int pos, DATA_D dataNode)
{
#if 1
    D_LinkList *tem,*node = (D_LinkList *)malloc(sizeof(D_LinkList));
    if (node == NULL)
    {
        printf("malloc error in %s", __func__);
        return -1;
    }
    node->dataNode = dataNode;
    for (int i = 1; i < pos; i++)
    {
        if (headList->nextNode == NULL)
        {
            break;
        }
        headList = headList->nextNode;
    }
    if (headList->nextNode != NULL)
    {
        headList->nextNode->preNode = node;
    }
    node->nextNode = headList->nextNode;
    node->preNode = headList;
    headList->nextNode = node;
    return 0;
#else
    
#endif
}

int D_IsEmptyLinkList(D_LinkList *headList)
{
    return headList->nextNode==NULL ? 1 : 0;
}

int D_DEL_HeadLinkList(D_LinkList *headList)
{
    D_LinkList *tem = headList->nextNode;
    if (D_IsEmptyLinkList(headList))
    {
        printf("double link list is empty!");
        return -1;
    }
    headList->nextNode = tem->nextNode;
    tem->nextNode->preNode = headList;
    free(tem);
    tem = NULL;
    return 0;
}

int D_DEL_TailLinkList(D_LinkList *headList)
{
    D_LinkList *tem;
    if (D_IsEmptyLinkList(headList))
    {
        printf("double link list is empty!");
        return -1;
    }
    while (headList->nextNode != NULL)
    {
        headList = headList->nextNode;
    }
    tem = headList;
    tem->preNode->nextNode = tem->nextNode;
    free(tem);
    tem = NULL;
    return 0;
}

int D_DEL_PosLinkList(D_LinkList *headList, int pos)
{
    D_LinkList *tem;
    for (int i = 0; i < pos; i++)
    {
        if (headList->nextNode == NULL)
        {
            printf("error on the right!");
            return -1;
        }
        headList = headList->nextNode;
    }
    tem = headList;
    if (tem->nextNode != NULL)
    {
        tem->nextNode->preNode = tem->preNode;
    }
    tem->preNode->nextNode = tem->nextNode;
    free(tem);
    return 0;
}

DATA_D D_FIND_PosLinkList(D_LinkList *headList, int pos)
{
    while (headList != NULL)
    {
        if (pos != 0)
        {
            headList = headList->nextNode;
            pos--;
        }
        else
        {
            printf("the data at this location is %d\n", headList->dataNode);
            printf("please enter a key to continue\n");
            getchar();
            return 0;
        }
    }
    printf("Out of range on the right\n");
    return -1;
}

int D_UP_PosLinkList(D_LinkList *headList, int pos, DATA_D data)
{
    while (headList != NULL)
    {
        if (pos != 0)
        {
            headList = headList->nextNode;
            pos--;
        }
        else
        {
            printf("The data at position %d is updated from %d to %d\n", pos, headList->dataNode, data);
            headList->dataNode = data;
            break;
        }
    }
    printf("Out of range on the right\n");
    return -1;
}

int D_NEG_LinkList(D_LinkList *headList)
{
#if 1
    D_LinkList *node = headList, *tem;
    if (node->nextNode->nextNode != NULL)
    {
        node = node->nextNode;
        node->preNode = NULL;
        while (node != NULL)
        {
            tem = node->preNode;
            node->preNode = node->nextNode;
            node->nextNode = tem;
            node = node->preNode;
        }
        tem->preNode->preNode = headList;
        headList->nextNode = tem->preNode;
    }
    return 0;
#else
    D_LinkList *node = headList, *tem;
    node = headList->nextNode;
    while (node)
    {
        tem = node->preNode;
        node->preNode = node->nextNode;
        node->nextNode = tem;
        node = node->preNode;
    }
    node = tem->preNode;
    headList->nextNode->nextNode = NULL;
    headList->nextNode = node;
    node->preNode = headList;
    return 0;
#endif
}
