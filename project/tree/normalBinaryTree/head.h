#if !defined(HEAD_H)
#define HEAD_H

#include <stdio.h>
#include <stdlib.h>
#define DATA char



typedef struct node
{
    DATA data;
    struct node *leftChild,*rightChild;
}Node;

Node *BinaryTreeCreat(void);
int FirstTraverseShow(Node *root);
int MiddleTraverseShow(Node *root);
int AfterTraverseShow(Node *root);
#endif // HEAD_H
