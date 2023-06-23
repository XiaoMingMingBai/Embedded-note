#include "head.h"

Node *BinaryTreeCreat(void)
{
    char c=getchar();
    if (c=='#')
    {
        return NULL;
    }
    Node *node=(Node *)malloc(sizeof(Node));
    node->data=c;
    node->leftChild=BinaryTreeCreat();
    node->rightChild=BinaryTreeCreat();
    return node;
}

int FirstTraverseShow(Node *root)
{
    if (root==NULL)
    {
        return 0;
    }
    printf("-%c",root->data);
    FirstTraverseShow(root->leftChild);
    FirstTraverseShow(root->rightChild);
    return 0;
}

int MiddleTraverseShow(Node *root)
{
    if (root==NULL)
    {
        return 0;
    }
    MiddleTraverseShow(root->leftChild);
    printf("-%c",root->data);
    MiddleTraverseShow(root->rightChild);
    return 0;
}

int AfterTraverseShow(Node *root)
{
    if (root==NULL)
    {
        return 0;
    }
    AfterTraverseShow(root->leftChild);
    AfterTraverseShow(root->rightChild);
    printf("-%c",root->data);
    return 0;
}
