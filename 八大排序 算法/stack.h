#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>



typedef int Datatype;
typedef struct S
{
	Datatype* a;
	int top;
	int Capacity;
}Stack;

void StackInit(Stack* p);
void StackPush(Stack* p, Datatype x);
void StackPop(Stack* p);
Datatype StackTop(Stack* p);
int StackEmpty(Stack* p);
void StackDestroy(Stack* p);
void StackPrint(Stack* p);
