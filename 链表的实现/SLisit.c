#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

SListNode* BuySListNode(SLTDateType x)
{
	SListNode* pc = (SListNode*)malloc(sizeof(SListNode));
	if (pc == NULL)
	{
		//perror(malloc);
		return NULL;
	}
	else
	{
		pc->data = x;
		return pc;
	}
}
void SListPushBack(SListNode** phead, SLTDateType x)
{
	assert(phead);//断言传进来的指针是否为NULL，但一般指针被创建了就不会出现这种情况
	//assert(*phead);//直接断言也彳亍
	if (*phead==NULL)//判断传进来的链表是否为空链表
	{
		SListNode* new = BuySListNode(x);
		*phead = new;
		new->next = NULL;
	}
	else
	{
		//找尾
		SListNode* new = BuySListNode(x);
		SListNode* pc = *phead;
		while (pc->next)
		{
			pc = pc->next;
		}
		pc->next = new;
		new->next = NULL;
	}
}
void SListPushFront(SListNode** phead, SLTDateType x)
{
	assert(phead);
	SListNode* new = BuySListNode(x);
	if (*phead == NULL)
	{
		new->next = NULL;
		*phead = new;
	}
	else
	{
		new->next = *phead;
		*phead=new;
	}

}
void SListPopBack(SListNode** phead, SLTDateType x)
{
	assert(phead);
	assert(*phead);
	if ((*phead)->next == NULL)
	{
		free(*phead);
		(*phead) = NULL;
	}
	else
	{
		SListNode* tail = *phead;
		while (tail->next->next)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next= NULL;
	}

}
void SListPopFront(SListNode** phead, SLTDateType x)
{
	assert(phead);
	assert(*phead);
	if ((*phead)->next==NULL)
	{
		free((*phead)->next);
		*phead = NULL;
	}
	else
	{
		SListNode* temp = (*phead)->next;
		free(*phead);
		*phead = temp;
	}
}

void SListPrint(SListNode* plist)
{
	SListNode* tail = plist;
	while (tail != NULL)
	{
		printf("%d->", tail->data);
		tail = tail->next;
	}
	printf("NULL\n");
}


SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	assert(plist);
	while (plist)
	{
		if (plist->data == x)
		{
			printf("找到值为%d的值了\n", x);
			return plist;
		}
		else
		{
			plist = plist->next;
		}
	}
	printf("没找到\n");
	return NULL;

}


void SListDestory(SListNode** phead)
{
	while (*phead)
	{
		if ((*phead)->next == NULL)
		{
			free((*phead));
			(*phead) = NULL;
		}
		else
		{
			SListNode* plist = (*phead);
			while (plist->next->next)
			{
				plist = plist->next;

			}
			free(plist->next);
			plist->next = NULL;
		}
	}
}

//
//
//void SListInsertAfter(SListNode** pos, SLTDateType x)
//{
//	if (*pos == NULL)
//	{
//		SListNode* new = BuySListNode(x);
//		*pos = new;
//		new->next = NULL;
//	}
//	else
//	{
//		SListNode* new = BuySListNode(x);
//		new->next = (*pos)->next;
//		(*pos)->next = new;
//	}
//	printf("后插入后：");
//}


void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	if (pos == NULL)
	{
		SListNode* new = BuySListNode(x);
		pos = new;
		new->next = NULL;
	}
	else
	{
		SListNode* new = BuySListNode(x);
		new->next = (pos)->next;
		(pos)->next = new;
	}
	printf("后插入后：");
}

//void SListEraseAfter(SListNode** pos)
//{
//	assert((*pos)->next);
//	(*pos)->next = (*pos)->next->next;
//	free((*pos)->next);
//	(*pos)->next = NULL;
//	printf("后删过后：");
//}

void SListEraseAfter(SListNode* pos)
{
	assert((pos)->next);
	(pos)->next = (pos)->next->next;
	free((pos)->next);
	(pos)->next = NULL;
	printf("后删过后：");
}