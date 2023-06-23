#include "head.h"

int Menu(seqstack_N *head)
{
    int tem;
    system("clear");
    SeqStackShow(head);
    printf("0.debug\n");
    printf("1.push stack 2.pop stack\n");
    printf("please the number you want to choose: ");
    scanf("%d",&tem);
    return tem;
}

seqstack_N *SeqStackCreate(void)
{
    seqstack_N *head;
    head = (seqstack_N *)malloc(sizeof(seqstack_N));
    if (head == NULL)
    {
        printf("malloc error on function '%s\n'", __func__);
        return NULL;
    }
    // memset(head->data, 0, sizeof(DATA) * N);
    head->top = -1;
    return head;
}

int SeqStackIsFull(seqstack_N *head)
{
    return (head->top + 1 == N) ? 1 : 0;
}

int SeqStackIsEmpty(seqstack_N *head)
{
    return (head->top == -1) ? 1 : 0;
}

int SeqStackPush(seqstack_N *head, M_DATA data)
{
    if (SeqStackIsFull(head))
    {
        printf("sequential stack is full on function %s\n", __func__);
        return -1;
    }
    head->data[++head->top] = data;
    return 0;
}

M_DATA SeqStackPop(seqstack_N *head)
{
    if (SeqStackIsEmpty(head))
    {
        printf("sequential stack is full on function %s\n", __func__);
        return -1;
    }
    return (M_DATA)(head->data[head->top--]);
}

void SeqStackShow(seqstack_N *head)
{
    printf("sequential stick");
    for (int i = 0; i <= head->top; i++)
    {
        printf("-%d", head->data[i]);
    }
    putchar(10);
}
