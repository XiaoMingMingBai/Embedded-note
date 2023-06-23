#if !defined(QUEUES)
#define QUEUES

#include <stdio.h>
#include <stdlib.h>
#define M_DATA long

typedef struct member
{
    M_DATA data;
    struct member *next;
} Member;

typedef struct pointer
{
    struct member *front, *back;
} PointerQue;

PointerQue *QueuesCreat(void);
int QueuesIn(PointerQue *list, M_DATA data);
int QueuesIsEmpty(PointerQue *list);
M_DATA QueuesOut(PointerQue *list);
int QueuesShow(PointerQue *list);
#endif // QUEUES
