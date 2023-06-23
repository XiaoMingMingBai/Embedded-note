#include "head.h"

Pointer *LinkQueuesCreat(void)
{
    Node *head=(Node *)malloc(sizeof(Node));
    Pointer *pointer;
    if (head==NULL)
    {
        printf("malloc error on function %s",__func__);
        return NULL;
    }
    head->data=(M_DATA)0;
    head->next=NULL;
    pointer=(Pointer *)malloc(sizeof(Pointer));
    if (pointer==NULL)
    {
        printf("malloc error on function %s",__func__);
        return NULL;
    }    
    pointer->front=pointer->reat=head;
    return pointer;
}

int LinkQueuesIn(Pointer *pointer, M_DATA data)
{
    Node *tem=(Node *)malloc(sizeof(Node));
    if (tem==NULL)
    {
        printf("malloc error on function %s",__func__);
        return -1;
    }
    tem->data=data;
    tem->next=pointer->reat->next;
    pointer->reat->next=tem;
    pointer->reat=tem;
    return 0;
}

int LinkQueuesIsEmpty(Pointer *pointer)
{
    return pointer->front==pointer->reat?1:0;
}

M_DATA LinkQueuesOut(Pointer *pointer)
{
    M_DATA data;
    Node* tem=NULL;
    if (LinkQueuesIsEmpty(pointer))
    {
        printf("Link queues is empty on function %s",__func__);
        return -1;
    }
    tem=pointer->front->next;
    data=tem->data;
    pointer->front->next=tem->next;
    if (tem->next==NULL)
    {
        pointer->reat=pointer->front;
    }
    free(tem);
    tem=NULL;
    return data;
}

int LinkQueuesShow(Pointer *pointer)
{
    printf("queues");
    Node*tem=pointer->front;
    while (tem->next!=NULL)
    {
        printf("-%d",tem->next->data);
        tem=tem->next;
    }
    putchar(10);
    return 0;
}
