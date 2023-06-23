#include <stdio.h>
#include <stdlib.h>
#define DATA int

typedef struct node
{
    M_DATA data;
    struct node *next;
} Node;

Node *ListCreat(void);
int ListInsert(Node *head, M_DATA data);
Node *ListReverse(Node *head);
int ListShow(Node *head);

int main(int argc, char const *argv[])
{
    Node *list = ListCreat();
    for (int i = 1; i < 8; i++)
    {
        ListInsert(list, i);
    }
    ListShow(list);
    list->next=ListReverse(list->next);
    ListShow(list);
    return 0;
}

Node *ListCreat(void)
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}

int ListInsert(Node *head, M_DATA data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = head->next;
    head->next = node;
    return 0;
}

Node *ListReverse(Node *head)
{
    if ((head == NULL )|| (head->next == NULL))
    {
        return head;
    }
    Node *end = ListReverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return end;
}

int ListShow(Node *head)
{
    printf("list");
    while (head->next!=NULL)
    {
        head=head->next;
        printf("-%d",head->data);
    }
    putchar(10);
}