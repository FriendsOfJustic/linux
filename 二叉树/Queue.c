#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

void QueueInit(Queue* q)
{
	ListNode* First = (ListNode*)malloc(sizeof(ListNode));
	q->head = q->tail = First;
	q->tail->next = NULL;
}

void QueuePush(Queue* q, Datatype x)
{
	assert(q);
	q->tail->x = x;
	ListNode* NewNode = (ListNode*)malloc(sizeof(ListNode));
	q->tail->next = NewNode;
	q->tail = NewNode;
	q->tail->next = NULL;
}

void QueuePop(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	if (!QueueEmpty(q))
	{
		ListNode* temp = q->head->next;
		free(q->head);
		q->head = temp;
	}

}

Datatype QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->head->x;
}

Datatype QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	ListNode* cur = q->head;
	while (cur->next != q->tail)
	{
		cur = cur->next;
	}
	return cur->x;
}

int QueueSize(Queue* q)
{
	if (QueueEmpty(q))
	{
		return 0;
	}
	ListNode* cur = q->head;
	int k = 0;
	while (cur != q->tail)
	{
		cur = cur->next;
		k++;
	}
	return k;
}

int QueueEmpty(Queue* q)
{
	return q->head == q->tail;
}

void QueueDestroy(Queue* q)
{
	ListNode* cur = q->head;
	while (cur != q->tail)
	{
		ListNode* temp = cur->next;
		free(cur);
		cur = temp;
	}
	free(cur);
	cur = NULL;
	q->head = NULL;
	q->tail = NULL;

}
