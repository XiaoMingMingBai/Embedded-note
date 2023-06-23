#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define DATATYPE int

typedef struct Note
{
    DATATYPE noteData;
    struct Note *noteNext;
}T_LinkList;

void Debug(T_LinkList *);

void LinkListShow(T_LinkList *);

T_LinkList *LinkListCreate(void);

int INS_HeadLinkList(T_LinkList *, DATATYPE );

int INS_TailLinkList(T_LinkList *, DATATYPE );

int INS_PosLinkList(T_LinkList *,int , DATATYPE );

int LinkListIsEmpty(T_LinkList *);

int RM_HeadLinkList(T_LinkList *);

int RM_TailLinkList(T_LinkList *);

int RM_PosLinkList(T_LinkList *,int );

DATATYPE FIND_PosLinkList(T_LinkList *, int );

int RW_PosLinkList(T_LinkList *, int , DATATYPE );

int SORT_InverseLinkList(T_LinkList *);

int SORT_LinkList(T_LinkList *);

void LinkListInsertSort(T_LinkList *h);

#endif