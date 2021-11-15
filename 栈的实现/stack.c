#define _CRT_SECURE_NO_WARNINGS 1

#include"stack.h"



void StackInit(Stack* p)
{
	p->a = (int *)malloc(4*sizeof(Stack));
	p->top = 0;
	p->Capacity = 4;
}

void StackPush(Stack* p, Datatype x)
{
	assert(p);
	if (p->top == p->Capacity)
	{
		p->a = (int*)realloc(p->a,2 * p->Capacity*sizeof(Stack));
		p->Capacity = p->Capacity * 2;
	}
	p->a[p->top] = x;
	p->top++;
}

void StackPop(Stack* p)
{
	if(p->top)
	p->top = p -> top - 1;
}

void StackPrint(Stack* p)
{
	assert(p);
	for (int i = 0; i < p->top; i++)
	{
		printf(" %d ", p->a[i]);
	}
	printf("\n");
}

Datatype StackTop(Stack* p)
{
	return p->a[p->top - 1];
}

int StackEmpty(Stack* p)
{
	return p->top == 0;
}

void StackDestroy(Stack* p)
{
	free(p->a);
	p->a = NULL;
	p->top = 0;
	p->Capacity = 0;
}

