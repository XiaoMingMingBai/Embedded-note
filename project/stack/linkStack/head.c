#include "head.h"

Node *StackCreat(void)
{
    Node *head=(Node *)malloc(sizeof(Node));
    if (head==NULL)
    {
        printf("malloc error on function %s\n",__func__);
        return NULL;
    }
    head->data=(M_DATA)0;
    head->next=NULL;
    return head;
}

int StackIn(Node *head, M_DATA data)
{
    Node *node=(Node *)malloc(sizeof(Node));
    if (head==NULL)
    {
        printf("malloc error on function %s\n",__func__);
        return -1;
    }
    node->data=data;
    node->next=head->next;
    head->next=node;
    return 0;
}

int StackIsEmpty(Node *head)
{
    return head->next==NULL?1:0;
}

M_DATA StackOut(Node *head)
{
    M_DATA data;
    Node *tem=NULL;
    if (StackIsEmpty(head))
    {
        printf("Stack is empty on function %s",__func__);
        return (M_DATA)-1;
    }
    tem=head->next;
    data=tem->data;
    head->next=tem->next;
    free(tem);
    tem=NULL;
    return data;
}

int StackShow(Node *head)
{
    if (StackIsEmpty(head))
    {
        printf("Stack is empty on function %s",__func__);
        return -1;
    }
    printf("stack");
    while (head->next!=NULL)
    {
        printf("-%d",head->next->data);
        head=head->next;
    }
    putchar(10);
    return 0;
}
