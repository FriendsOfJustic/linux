#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int Datatype;
typedef struct ListNode
{
	Datatype x;
	struct ListNode* next;
}ListNode;

typedef struct
{
	ListNode* head;
	ListNode* tail;
}Queue;

void QueueInit(Queue* q);

void QueuePush(Queue* q, Datatype x);

void QueuePop(Queue* q);

Datatype QueueFront(Queue* q);

Datatype QueueBack(Queue* q);

int QueueSize(Queue* q);

int QueueEmpty(Queue* q);

void QueueDestroy(Queue* q);

