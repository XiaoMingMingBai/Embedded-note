#include <stdio.h>
#include <stdlib.h>

// 定义循环链表结构体
typedef struct node
{
    int value;
    struct node *next;
} Node;

// 创建循环链表
Node *create_list(int n)
{
    Node *head = (Node *)malloc(sizeof(Node));
    Node *cur = head;

    for (int i = 1; i <= n; i++)
    {
        Node *node = (Node *)malloc(sizeof(Node));
        node->value = i;
        cur->next = node;
        cur = node;
    }
    cur->next = head->next;
    free(head);
    return cur->next;
}

// 删除当前节点的下一个节点
Node *delete_next_node(Node *node)
{
    Node *next = node->next;
    node->next = next->next;
    printf("%d ", next->value);
    free(next);
    return node->next;
}

// 解决约瑟夫问题
void josephus(int n, int m, int k)
{
    Node *head = create_list(n);
    Node *cur = head;

    // 找到开始的位置
    for (int i = 1; i < k; i++)
    {
        cur = cur->next;
    }

    while (n > 1)
    {
        for (int i = 1; i < m; i++)
        {
            cur = cur->next;
        }
        cur = delete_next_node(cur);
        n--;
    }

    printf("The last one is %d\n", cur->value);

    free(cur);
}

int main()
{
    int n = 10; // 总人数
    int m = 3;  // 数到m的人出列
    int k = 2;  // 从第k个人开始报数
    josephus(n, m, k);
    return 0;
}