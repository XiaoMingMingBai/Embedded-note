#if !defined(HEAD_H)
#define HEAD_H

#include "queues.h"
#define DATA int



typedef struct node
{
    DATA data;
    struct node *leftChild,*rightChild;
}Node;

Node *BinaryTreeCreat(int total,int num);
int BinaryTreeQueuesTraverseShow(Node *root);
int BinaryTreeFirstTraverseShow(Node *root);
int BinaryTreeMiddleTraverseShow(Node *root);
int BinaryTreeAfterTraverseShow(Node *root);
#endif // HEAD_H
