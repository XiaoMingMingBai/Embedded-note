#include "head.h"

LoopQue *LoopQueueCreate(void)
{
    LoopQue *head;
    head=(LoopQue *)malloc(sizeof(LoopQue));
    if (head==NULL)
    {
        printf("malloc error on function %s\n",__func__);
        return NULL;
    }
    memset(head->data,0,sizeof(M_DATA)*N+1);
    head->front=head->rear=0;
    return head;
}

int LoopQueueIsFull(LoopQue *head)
{
    return (head->rear+1)%(N+1)==head->front?1:0;
}

int LoopQueueIsEmpty(LoopQue *head)
{
    return head->front==head->rear?1:0;
}

int LoopQueueIn(LoopQue *head, M_DATA data)
{
    if (LoopQueueIsFull(head))
    {
        printf("loop queues is full on function %s\n",__func__);
        return -1;
    }
    head->data[head->rear]=data;
    head->rear=(head->rear+1)%(N+1);
    return 0;
}

M_DATA LoopQueueOut(LoopQue *head)
{
    M_DATA data;
    if (LoopQueueIsEmpty(head))
    {
        printf("loop queues is empty on function %s\n",__func__);
        return (M_DATA)-1;
    }
    data=head->data[head->front];
    head->data[head->front]=0;
    head->front=(head->front+1)%(N+1);
    return data;
}

void LoopQueueShow(LoopQue *head)
{
    printf("list");
    for (int i = 0; i < N+1; i++)
    {
        printf("-%d",head->data[i]);
    }
    putchar(10);
}
