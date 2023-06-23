#include "linklist.h"

void Debug(T_LinkList *linkList)
{
    for (int i = 0; i < 6; i++)
    {
        INS_TailLinkList(linkList, i);
    }
}

void LinkListShow(T_LinkList *linkList)
{
    printf("linkList");
    while (linkList->noteNext)
    {
        printf("->%d", linkList->noteNext->noteData);
        linkList = linkList->noteNext;
    }
    putchar(10);
}

T_LinkList *LinkListCreate(void)
{
    T_LinkList *h = NULL;
    // storage allocation
    h = (T_LinkList *)malloc(sizeof(T_LinkList));
    if (h == NULL)
    {
        printf("malloc error\n");
        return NULL;
    }
    // initialization
    h->noteData = (DATATYPE)0;
    h->noteNext = NULL;
    return h;
}

int INS_HeadLinkList(T_LinkList *linkList, DATATYPE data)
{
    T_LinkList *tem;
    // storage allocation
    tem = (T_LinkList *)malloc(sizeof(T_LinkList));
    if (tem == NULL)
    {
        printf("malloc error\n");
        return -1;
    }
    // insert
    tem->noteData = data;
    tem->noteNext = linkList->noteNext;
    linkList->noteNext = tem;
    return 0;
}

int INS_TailLinkList(T_LinkList *linkList, DATATYPE data)
{
    // storage allocation
    T_LinkList *tem;
    tem = (T_LinkList *)malloc(sizeof(T_LinkList));
    if (tem == NULL)
    {
        printf("malloc error\n");
        return -1;
    }
    // to tail
    while (linkList->noteNext)
    {
        linkList = linkList->noteNext;
    }
    // insert
    tem->noteData = data;
    tem->noteNext = linkList->noteNext;
    linkList->noteNext = tem;
    return 0;
}

int INS_PosLinkList(T_LinkList *linkList, int posNote, DATATYPE data)
{
    if (posNote <= 0)
    {
        printf("position input error!\n");
        return -1;
    }
    // storage allocation
    T_LinkList *tem;
    tem = (T_LinkList *)malloc(sizeof(T_LinkList));
    if (tem == NULL)
    {
        printf("malloc error\n");
        return -1;
    }
    // to the pos
    for (int i = 0; i < posNote; i++)
    {
        if (linkList->noteNext == NULL)
        {
            printf("to the tail\n");
            tem->noteNext = linkList->noteNext;
            tem->noteData = data;
            linkList->noteNext = tem;
            return 0;
        }
        linkList = linkList->noteNext;
    }
    // insert
    tem->noteData = linkList->noteData;
    tem->noteNext = linkList->noteNext;
    linkList->noteData = data;
    linkList->noteNext = tem;
    return 0;
}

int LinkListIsEmpty(T_LinkList *linkList)
{
    if (linkList->noteNext == NULL)
    {
        printf("link list is empty!\n");
        return 1;
    }
    return 0;
}

int RM_HeadLinkList(T_LinkList *linkList)
{
    T_LinkList *temDelete;
    if (LinkListIsEmpty(linkList))
    {
        return 0;
    }
    temDelete = linkList->noteNext;
    linkList->noteNext = linkList->noteNext->noteNext;
    free(temDelete);
    temDelete = NULL;
    return 0;
}

int RM_TailLinkList(T_LinkList *linkList)
{
    T_LinkList *temDelete;
    // if empty
    if (LinkListIsEmpty(linkList))
    {
        return 0;
    }
    while (linkList->noteNext->noteNext)
    {
        linkList = linkList->noteNext;
    }
    temDelete = linkList->noteNext;
    linkList->noteNext = linkList->noteNext->noteNext;
    free(temDelete);
    temDelete = NULL;
    return 0;
}

int RM_PosLinkList(T_LinkList *linkList, int posNote)
{
    T_LinkList *temDelete;
    // if empty
    if (LinkListIsEmpty(linkList))
    {
        return 0;
    }
    for (int i = 0; i < posNote - 1; i++)
    {
        linkList = linkList->noteNext;
        if (LinkListIsEmpty(linkList))
        {
            printf("There's not that much data\n");
            return 0;
        }
    }
    temDelete = linkList->noteNext;
    linkList->noteNext = linkList->noteNext->noteNext;
    free(temDelete);
    temDelete = NULL;
    return 0;
}

DATATYPE FIND_PosLinkList(T_LinkList *linkList, int posNote)
{
    for (int i = 0; i < posNote; i++)
    {
        linkList = linkList->noteNext;
    }
    return (DATATYPE)linkList->noteData;
}

int RW_PosLinkList(T_LinkList *linkList, int posNote, DATATYPE data)
{
    for (int i = 0; i < posNote; i++)
    {
        linkList = linkList->noteNext;
    }
    linkList->noteData = data;
    printf("rewrite finish\n");
    sleep(0.5);
    return 0;
}

int SORT_InverseLinkList(T_LinkList *linkList)
{
    T_LinkList *temHand = NULL, *tem;
    if (LinkListIsEmpty(linkList))
    {
        return 0;
    }
    temHand = linkList->noteNext;
    linkList->noteNext = NULL;
    while (temHand)
    {
        tem = temHand;
        temHand = temHand->noteNext;
        tem->noteNext = linkList->noteNext;
        linkList->noteNext = tem;
    }
    return 0;
}

int SORT_LinkList(T_LinkList *linkList)
{
    T_LinkList *temHead = linkList, *tem, *med;
    tem = linkList->noteNext;
    linkList->noteNext = NULL;
    while (tem)
    {
        med = tem;
        tem = tem->noteNext;
        while (linkList->noteNext != NULL && med->noteData > linkList->noteNext->noteData)
        {
            linkList = linkList->noteNext;
        }
        med->noteNext = linkList->noteNext;
        linkList->noteNext = med;
        linkList = temHead;
    }
    return 0;
}
