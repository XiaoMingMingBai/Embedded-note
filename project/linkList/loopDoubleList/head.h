#ifndef __HEAD_H__
#define __HEAD_H__

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define DATA_D int

typedef struct Node {
    DATA_D dataNode;
    struct Node *preNode, *nextNode;
} D_LinkList;

D_LinkList* D_CreateLinkList(void);
int D_ShowLinkList(D_LinkList* headList);
void debug(D_LinkList* head);
int D_INS_HeadLinkList(D_LinkList* headList, DATA_D dataNode);
int D_INS_PosLinkList(D_LinkList* headList, int pos, DATA_D dataNode);
int D_IsEmptyLinkList(D_LinkList* headList);
int D_DEL_HeadLinkList(D_LinkList* headList);
DATA_D D_FIND_PosLinkList(D_LinkList* headList, int pos);
int D_UP_PosLinkList(D_LinkList* headList, int pos ,DATA_D data);
#endif