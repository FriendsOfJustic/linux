#define _CRT_SECURE_NO_WARNINGS 1

#pragma once;
#include"stack.h"
int main()
{
	Stack ps;
	StackInit(&ps);
	StackPush(&ps, 1);
	StackPush(&ps, 2);
	StackPush(&ps, 3);
	StackPush(&ps, 4);
	StackPrint(&ps);
	StackPop(&ps);
	StackPrint(&ps);
	Datatype ret = StackTop(&ps);
	printf("Õ»¶¥Îª£º%d", ret);
	StackDestroy(&ps);
}