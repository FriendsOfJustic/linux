#define _CRT_SECURE_NO_WARNINGS 1


#include"DoubleList.h"

void IniteDlist(Dlist** phead)
{
	assert(phead);
	*phead = (Dlist*)malloc(sizeof(Dlist));
	(*phead)->next = *phead;
	(*phead)->prev = *phead;
	(*phead)->val = -1;
}
void DlistDestroy(Dlist** phead)
{
	assert(phead);
	Dlist* tail = (*phead)->prev;
	Dlist* Prev = tail->prev;
	while (tail != *phead)
	{
		free(tail);
		tail = Prev;
		if(Prev!=*phead)
		Prev = Prev->prev;
	}
	free(*phead);
	*phead = NULL;
}
void ListPrint(Dlist* phead)
{
	Dlist* cur = phead->next;
	while (cur != phead)
	{
		printf(" %d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}
void DListPushBack(Dlist* phead, datatype x)
{
	assert(phead);
	Dlist* tail = phead->prev;
	Dlist* NewNode = (Dlist*)malloc(sizeof(Dlist));
	NewNode->val = x;
	tail->next = NewNode;
	NewNode->prev = tail;
	phead->prev = NewNode;
	NewNode->next = phead;
}
void DListPushFront(Dlist* phead, datatype x)
{
	assert(phead);
	Dlist* NewNode = (Dlist*)malloc(sizeof(Dlist));
	Dlist* Next = phead->next;
	NewNode->val = x;
	phead->next = NewNode;
	NewNode->prev = phead;
	NewNode->next = Next;
	Next->prev = NewNode;
}
void DListPopBack(Dlist* phead)
{
	assert(phead);
	Dlist* tail = phead->prev;
	Dlist* NewTail = tail->prev;
	phead->prev = NewTail;
	NewTail->next = phead;
	free(tail);
}
void DListPopFront(Dlist* phead)
{
	assert(phead);
	Dlist* head = phead->next;
	Dlist* Newhead = head->next;
	phead->next = Newhead;
	Newhead->prev = phead;
	free(head);
}


Dlist* Listfind(Dlist* phead, datatype x)
{
	assert(phead);
	Dlist* cur = phead->next;
	while (cur!=phead)
	{
		if (cur->val == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void DlistInsert(Dlist* pos, datatype x)           //Ç°²å
{
	assert(pos);
	Dlist* Prev = pos->prev;
	Dlist* NewNode = (Dlist*)malloc(sizeof(Dlist));
	NewNode->val = x;
	Prev->next = NewNode;
	NewNode->prev = Prev;
	NewNode->next = pos;
	pos->prev = NewNode;
}

void DlistErease(Dlist* pos)        //É¾³ı
{
	assert(pos);
	Dlist* Prev = pos->prev;
	Dlist* Next = pos->next;
	free(pos);
	Prev->next = Next;
	Next->prev = Prev;
}
