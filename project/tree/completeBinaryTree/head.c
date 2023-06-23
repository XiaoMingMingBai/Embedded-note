#include "head.h"

Node *BinaryTreeCreat(int total, int num)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("malloc error on function %s", __func__);
        return NULL;
    }
    node->data = num;
    if (num * 2 <= total)
    {
        node->leftChild = BinaryTreeCreat(total, num * 2);
    }
    else
    {
        node->leftChild = NULL;
    }
    if (num * 2 + 1 <= total)
    {
        node->rightChild = BinaryTreeCreat(total, num * 2 + 1);
    }
    else
    {
        node->rightChild = NULL;
    }
    return node;
}

int BinaryTreeQueuesTraverseShow(Node *root)
{
    Node *tem;
    PointerQue *queues = QueuesCreat();
    QueuesIn(queues, (M_DATA)root);
    printf("tree");
    while (!QueuesIsEmpty(queues))
    {
        tem = (Node *)QueuesOut(queues);
        printf("-%d", tem->data);
        if (tem->leftChild)
        {
            QueuesIn(queues, (M_DATA)tem->leftChild);
        }
        if (tem->rightChild)
        {
            QueuesIn(queues, (M_DATA)tem->rightChild);
        }
    }
    putchar(10);
    return 0;
}

int BinaryTreeFirstTraverseShow(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    printf("-%d", root->data);
    BinaryTreeFirstTraverseShow(root->leftChild);
    BinaryTreeFirstTraverseShow(root->rightChild);
    return 0;
}

int BinaryTreeMiddleTraverseShow(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    BinaryTreeMiddleTraverseShow(root->leftChild);
    printf("-%d", root->data);
    BinaryTreeMiddleTraverseShow(root->rightChild);
    return 0;
}

int BinaryTreeAfterTraverseShow(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    BinaryTreeAfterTraverseShow(root->leftChild);
    BinaryTreeAfterTraverseShow(root->rightChild);
    printf("-%d", root->data);
    return 0;
}
