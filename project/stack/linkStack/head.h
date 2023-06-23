#ifndef __HEAD_H__
#define __HEAD_H__
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define DATA int

typedef struct node
{
    M_DATA data;
    struct node *next;
}Node;

Node *StackCreat(void);
int StackIn(Node *head,M_DATA data);
int StackIsEmpty(Node *head);
M_DATA StackOut(Node *head);
int StackShow(Node *head);

#endif