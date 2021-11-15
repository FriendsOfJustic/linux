#define _CRT_SECURE_NO_WARNINGS 1
#include"Seqlist.h"


void SeqListInit(SeqList* ps)
{
	assert(ps);
	SLDateType* pc = (SLDateType*)malloc(4 * sizeof(SLDateType));
	if (pc == NULL)
	{
		perror("malloc");
	}
	else
	{
		ps->arr = pc;
		ps->sz = 0;
		ps->capacity = 4;
	}
	/*ps->sz = 0;
	ps->capacity = 4;*/
}

void SeqListDestory(SeqList* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
		ps->arr = NULL;
	}
	ps->sz = 0;
	ps->capacity = 0;
}

void SeqListPrint(SeqList* ps)
{
	for (int i = 0; i < ps->sz; i++)
	{
		printf("%d ", *(ps->arr + i));
	}
	printf("\n");
}


void CheckSeqList(SeqList* ps)
{
	if (ps->sz == ps->capacity)
	{
		SLDateType*pc = (SLDateType*)realloc(ps->arr, ps->capacity * sizeof(SLDateType) + 4 * sizeof(SLDateType));
		if (pc == NULL)
		{
			perror("malloc");
		}
		else
		{
			ps->arr = pc;
			
			ps->capacity += 4;
		}
	}

}
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	CheckSeqList(ps);
	ps->arr[ps->sz] = x;
	ps->sz++;
}
void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps);
	CheckSeqList(ps);
	for (int i = ps->sz; i >= 0; i--)
	{
		if (i == 0)
		{
			ps->arr[i] = x;
		}
		else
		{
			ps->arr[i] = ps->arr[i - 1];
		}
	}
	ps->sz++;
}

void SeqListPopFront(SeqList* ps)
{
	if (ps->sz < 1)
		return;
	for (int i = 0; i < ps->sz - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->sz--;
}
void SeqListPopBack(SeqList* ps)
{
	if (ps->sz < 1)
		return;

	ps->sz--;
}


// 顺序表查找
int SeqListFind(SeqList* ps, SLDateType x)
{
	for (int i = 0; i < ps->sz; i++)
	{
		if (ps->arr[ps->sz] == x)
			return i;
	}
	return -1;
}
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, int pos, SLDateType x)
{
	CheckSeqList(ps);
	if (pos > ps->sz+1)
	{
			return;
	}
	for (int i = ps->sz; i >= pos-1; i--)
	{
		if (i == pos-1)
		{
			ps->arr[i] = x;
		}
		else
		{
			ps->arr[i] = ps->arr[i - 1];
		}
	}
	ps->sz++;
}
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, int pos)
{
	if (ps->sz < 1)
		return;
	for (int i = pos-1; i < ps->sz - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->sz--;
}