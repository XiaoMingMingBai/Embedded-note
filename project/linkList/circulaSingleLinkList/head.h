#ifndef __HAND_H__
#define __HAND_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define DATATYPE int

typedef struct Node
{
    DATATYPE dataNode;
    struct Node *nextNode;
}L_LinkList;

void ShowMenu(L_LinkList *headLoop, int *choose);

L_LinkList* CreateLoopLinkList(void);

int ShowLoopLinkList(L_LinkList *headLoop);

int INS_HeadLoopLinkList(L_LinkList *headLoop,DATATYPE data);

int INS_TailLoopLinkList(L_LinkList *headLoop, DATATYPE data);

int INS_PosLoopLinkList(L_LinkList *headLoop, int pos, DATATYPE data);

int EmptyLoopLinkList(L_LinkList *headLoop);

int RM_HeadLoopLinkList(L_LinkList *headLoop);

int RM_TailLoopLinkList(L_LinkList *headLoop);

int RM_PosLoopLinkList(L_LinkList *headLoop, int pos);

void Debug(L_LinkList *headLoop);

int FI_PosLoopLinkList(L_LinkList *headLoop, int pos);

int UP_PosLoopLinkList(L_LinkList *headLoop, int pos, DATATYPE data);


#endif