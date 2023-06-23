#include "queues.h"

PointerQue *QueuesCreat(void)
{
    Member *member=(Member *)malloc(sizeof(Member));
    if (member==NULL)
    {
        printf("molloc error on function '%s'",__func__);
        return NULL;
    }
    member->data=0;
    member->next=NULL;
    PointerQue *list=(PointerQue *)malloc(sizeof(PointerQue));
    if (member==NULL)
    {
        printf("molloc error on function '%s'",__func__);
        return NULL;
    }
    list->back=list->front=member;
    return list;
}

int QueuesIn(PointerQue *list, M_DATA data)
{
    Member *member=(Member *)malloc(sizeof(Member));
    if (member==NULL)
    {
        printf("molloc error on function '%s'\n",__func__);
        return -1;
    }
    member->data=data;
    member->next=list->back->next;
    list->back->next=member;
    list->back=member;
    return 0;
}

int QueuesIsEmpty(PointerQue *list)
{
    return list->back==list->front?1:0;
}

M_DATA QueuesOut(PointerQue *list)
{
    M_DATA data;
    if (QueuesIsEmpty(list))
    {
        printf("queues is empty on function %s\n",__func__);
        return -1;
    }
    Member *tem=list->front->next;
    data=tem->data;
    list->front->next=tem->next;
    if (list->front->next==NULL)
    {
        list->back=list->front;
    }
    free(tem);
    tem=NULL;
    return data;
}

int QueuesShow(PointerQue *list)
{
    printf("list");
    Member *head=list->front;
    while (head->next!=NULL)
    {
        printf("-%d",head->next->data);
        head=head->next;
    }
    putchar(10);
    return 0;
}
