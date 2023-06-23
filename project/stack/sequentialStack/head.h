#ifndef __HEAD_H__
#define __HEAD_H__
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define DATA int
#define N 30

typedef struct Node
{
    M_DATA data[N];
    int top;
} seqstack_N;

int Menu(seqstack_N *head);
seqstack_N *SeqStackCreate(void);
int SeqStackIsFull(seqstack_N *head);
int SeqStackIsEmpty(seqstack_N *head);
int SeqStackPush(seqstack_N *head, M_DATA data);
M_DATA SeqStackPop(seqstack_N *head);
void SeqStackShow(seqstack_N *head);

#endif