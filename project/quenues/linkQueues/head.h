#ifndef __HEAD_H__
#define __HEAD_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#define DATA int

typedef struct node
{
    M_DATA data;
    struct node *next;
} Node;

typedef struct pointer
{
    Node *front, *reat;
} Pointer;

Pointer *LinkQueuesCreat(void);
int LinkQueuesIn(Pointer *pointer, M_DATA data);
int LinkQueuesIsEmpty(Pointer *pointer);
M_DATA LinkQueuesOut(Pointer *pointer);
int LinkQueuesShow(Pointer *pointer);

#endif