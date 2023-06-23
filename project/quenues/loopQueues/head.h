#ifndef __head_H__
#define __head_H__
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#define DATA int
#define N 5

typedef struct Node
{
    M_DATA data[N+1];
    int front,rear;
}LoopQue;

LoopQue* LoopQueueCreate(void);
int LoopQueueIsFull(LoopQue *head);
int LoopQueueIsEmpty(LoopQue *head);
int LoopQueueIn(LoopQue *head, M_DATA data);
M_DATA LoopQueueOut(LoopQue *head);
void LoopQueueShow(LoopQue *head);
#endif