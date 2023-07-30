#define _CRT_SECURE_NO_WARNINGS 1

//#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

//带头双向循环链表
typedef int datatype;
typedef struct DList
{
	datatype val;
	struct Dlist* prev;
	struct Dlist* next;
}Dlist;

void IniteDlist(Dlist** phead);

void DlistDestroy(Dlist** phead);

void ListPrint(Dlist* phead);

void DListPushBack(Dlist* phead,datatype x);

void DListPushFront(Dlist* phead, datatype x);

void DListPopBack(Dlist* phead);

void DListPopFront(Dlist* phead);

Dlist* Listfind(Dlist* phead, datatype x);

void DlistInsert(Dlist* pos, datatype x);

void DlistErease(Dlist* pos);